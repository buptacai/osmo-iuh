/* Common parts of IuCS and IuPS interfaces implementation */

/* (C) 2016-2017 by sysmocom s.f.m.c. GmbH <info@sysmocom.de>
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <osmocom/ranap/iu_client.h>

#include <osmocom/core/logging.h>
#include <osmocom/crypt/auth.h>
#include <osmocom/gprs/gprs_msgb.h>
#include <osmocom/sigtran/sccp_sap.h>
#include <osmocom/ranap/ranap_ies_defs.h>
#include <osmocom/ranap/ranap_msg_factory.h>

/* Parsed global RNC id. See also struct RANAP_GlobalRNC_ID, and note that the
 * PLMN identity is a BCD representation of the MCC and MNC.
 * See iu_grnc_id_parse(). */
struct iu_grnc_id {
	uint16_t mcc;
	uint16_t mnc;
	uint16_t rnc_id;
};

/* A remote RNC (Radio Network Controller, like BSC but for UMTS) that has
 * called us and is currently reachable at the given osmo_sccp_addr. So, when we
 * know a LAC for a subscriber, we can page it at the RNC matching that LAC or
 * RAC. An HNB-GW typically presents itself as if it were a single RNC, even
 * though it may have several RNCs in hNodeBs connected to it. Those will then
 * share the same RNC id, which they actually receive and adopt from the HNB-GW
 * in the HNBAP HNB REGISTER ACCEPT message. */
struct ranap_iu_rnc {
	struct llist_head entry;

	uint16_t rnc_id;
	uint16_t lac; /* Location Area Code (used for CS and PS) */
	uint8_t rac; /* Routing Area Code (used for PS only) */
	struct osmo_sccp_addr sccp_addr;
};

void *talloc_iu_ctx;
void *talloc_asn1_ctx;

/* Implement the extern asn_debug from libasn1c to indicate whether to print
 * asn.1 debug messages (see libasn1c). */
int asn_debug = 0;

/* Implement the extern asn1_xer_print to indicate whether the ASN.1 binary
 * code decoded and encoded during Iu communication should be logged to stderr
 * (see asn.1 generated code in osmo-iuh). */
int asn1_xer_print = 0;

ranap_iu_recv_cb_t global_iu_recv_cb = NULL;
ranap_iu_event_cb_t global_iu_event_cb = NULL;
int iu_log_subsystem = 0;

#define LOGPIU(level, fmt, args...) \
	LOGP(iu_log_subsystem, level, fmt, ## args)

static LLIST_HEAD(ue_conn_ctx_list);
static LLIST_HEAD(rnc_list);

static struct osmo_sccp_instance *g_sccp;
static struct osmo_sccp_user *g_scu;

const struct value_string ranap_iu_event_type_names[] = {
	OSMO_VALUE_STRING(RANAP_IU_EVENT_RAB_ASSIGN),
	OSMO_VALUE_STRING(RANAP_IU_EVENT_SECURITY_MODE_COMPLETE),
	OSMO_VALUE_STRING(RANAP_IU_EVENT_IU_RELEASE),
	OSMO_VALUE_STRING(RANAP_IU_EVENT_LINK_INVALIDATED),
	{ 0, NULL }
};

static struct ranap_ue_conn_ctx *ue_conn_ctx_alloc(struct ranap_iu_rnc *rnc, uint32_t conn_id)
{
	struct ranap_ue_conn_ctx *ctx = talloc_zero(talloc_iu_ctx, struct ranap_ue_conn_ctx);

	ctx->rnc = rnc;
	ctx->conn_id = conn_id;
	llist_add(&ctx->list, &ue_conn_ctx_list);

	return ctx;
}

static struct ranap_ue_conn_ctx *ue_conn_ctx_find(uint32_t conn_id)
{
	struct ranap_ue_conn_ctx *ctx;

	llist_for_each_entry(ctx, &ue_conn_ctx_list, list) {
		if (ctx->conn_id == conn_id)
			return ctx;
	}
	return NULL;
}

static struct ranap_iu_rnc *iu_rnc_alloc(uint16_t rnc_id, uint16_t lac, uint8_t rac,
					 struct osmo_sccp_addr *addr)
{
	struct ranap_iu_rnc *rnc = talloc_zero(talloc_iu_ctx, struct ranap_iu_rnc);

	rnc->rnc_id = rnc_id;
	rnc->lac = lac;
	rnc->rac = rac;
	rnc->sccp_addr = *addr;
	llist_add(&rnc->entry, &rnc_list);

	LOGPIU(LOGL_NOTICE, "New RNC %d (LAC=%d RAC=%d)\n",
	       rnc->rnc_id, rnc->lac, rnc->rac);

	return rnc;
}

static struct ranap_iu_rnc *iu_rnc_register(uint16_t rnc_id, uint16_t lac,
					    uint8_t rac, struct osmo_sccp_addr *addr)
{
	struct ranap_iu_rnc *rnc;
	llist_for_each_entry(rnc, &rnc_list, entry) {
		if (rnc->rnc_id != rnc_id)
			continue;

		/* We have this RNC Id registered already. Make sure that the
		 * details match. */

		/* TODO should a mismatch be an error? */
		if (rnc->lac != lac || rnc->rac != rac)
			LOGPIU(LOGL_NOTICE, "RNC %d changes its details:"
			       " LAC=%d RAC=%d --> LAC=%d RAC=%d\n",
			       rnc->rnc_id, rnc->lac, rnc->rac,
			       lac, rac);
		rnc->lac = lac;
		rnc->rac = rac;

		if (addr && memcmp(&rnc->sccp_addr, addr, sizeof(*addr)))
			LOGPIU(LOGL_NOTICE, "RNC %d on New SCCP Addr %s"
			       " (LAC=%d RAC=%d)\n",
			       rnc->rnc_id, osmo_sccp_addr_dump(addr), rnc->lac, rnc->rac);
		rnc->sccp_addr = *addr;
		return rnc;
	}

	/* Not found, make a new one. */
	return iu_rnc_alloc(rnc_id, lac, rac, addr);
}

/***********************************************************************
 * RANAP handling
 ***********************************************************************/

int ranap_iu_rab_act(struct ranap_ue_conn_ctx *ue_ctx, struct msgb *msg)
{
	struct osmo_scu_prim *prim;

	/* wrap RANAP message in SCCP N-DATA.req */
	prim = (struct osmo_scu_prim *) msgb_push(msg, sizeof(*prim));
	prim->u.data.conn_id = ue_ctx->conn_id;
	osmo_prim_init(&prim->oph,
		       SCCP_SAP_USER,
		       OSMO_SCU_PRIM_N_DATA,
		       PRIM_OP_REQUEST,
		       msg);
	return osmo_sccp_user_sap_down(g_scu, &prim->oph);
}

int ranap_iu_rab_deact(struct ranap_ue_conn_ctx *ue_ctx, uint8_t rab_id)
{
	/* FIXME */
	return -1;
}

int ranap_iu_tx_sec_mode_cmd(struct ranap_ue_conn_ctx *uectx, struct osmo_auth_vector *vec,
			     int send_ck, int new_key)
{
	struct osmo_scu_prim *prim;
	struct msgb *msg;

	/* create RANAP message */
	msg = ranap_new_msg_sec_mod_cmd(vec->ik, send_ck? vec->ck : NULL,
			new_key ? RANAP_KeyStatus_new : RANAP_KeyStatus_old);
	msg->l2h = msg->data;
	/* wrap RANAP message in SCCP N-DATA.req */
	prim = (struct osmo_scu_prim *) msgb_push(msg, sizeof(*prim));
	prim->u.data.conn_id = uectx->conn_id;
	osmo_prim_init(&prim->oph, SCCP_SAP_USER,
			OSMO_SCU_PRIM_N_DATA,
			PRIM_OP_REQUEST, msg);
	osmo_sccp_user_sap_down(g_scu, &prim->oph);

	return 0;
}

int ranap_iu_tx_common_id(struct ranap_ue_conn_ctx *uectx, const char *imsi)
{
	struct msgb *msg;
	struct osmo_scu_prim *prim;

	LOGPIU(LOGL_INFO, "Transmitting RANAP CommonID (SCCP conn_id %u)\n",
	       uectx->conn_id);

	msg = ranap_new_msg_common_id(imsi);
	msg->l2h = msg->data;
	prim = (struct osmo_scu_prim *) msgb_push(msg, sizeof(*prim));
	prim->u.data.conn_id = uectx->conn_id;
	osmo_prim_init(&prim->oph, SCCP_SAP_USER,
			OSMO_SCU_PRIM_N_DATA,
			PRIM_OP_REQUEST, msg);
	osmo_sccp_user_sap_down(g_scu, &prim->oph);
	return 0;
}

static int iu_grnc_id_parse(struct iu_grnc_id *dst, struct RANAP_GlobalRNC_ID *src)
{
	/* The size is coming from arbitrary sender, check it gracefully */
	if (src->pLMNidentity.size != 3) {
		LOGPIU(LOGL_ERROR, "Invalid PLMN Identity size:"
		       " should be 3, is %d\n", src->pLMNidentity.size);
		return -1;
	}
	gsm48_mcc_mnc_from_bcd(&src->pLMNidentity.buf[0],
			       &dst->mcc, &dst->mnc);
	dst->rnc_id = (uint16_t)src->rNC_ID;
	return 0;
}

#if 0
 -- not used at present --
static int iu_grnc_id_compose(struct iu_grnc_id *src, struct RANAP_GlobalRNC_ID *dst)
{
	/* The caller must ensure proper size */
	OSMO_ASSERT(dst->pLMNidentity.size == 3);
	gsm48_mcc_mnc_to_bcd(&dst->pLMNidentity.buf[0],
			     src->mcc, src->mnc);
	dst->rNC_ID = src->rnc_id;
	return 0;
}
#endif

struct new_ue_conn_ctx {
	struct osmo_sccp_addr sccp_addr;
	uint32_t conn_id;
};

static int ranap_handle_co_initial_ue(void *ctx, RANAP_InitialUE_MessageIEs_t *ies)
{
	struct new_ue_conn_ctx *new_ctx = ctx;
	struct gprs_ra_id ra_id;
	struct iu_grnc_id grnc_id;
	uint16_t sai;
	struct ranap_ue_conn_ctx *ue;
	struct msgb *msg = msgb_alloc(256, "RANAP->NAS");
	struct ranap_iu_rnc *rnc;

	if (ranap_parse_lai(&ra_id, &ies->lai) != 0) {
		LOGPIU(LOGL_ERROR, "Failed to parse RANAP LAI IE\n");
		return -1;
	}

	if (ies->presenceMask & INITIALUE_MESSAGEIES_RANAP_RAC_PRESENT) {
		ra_id.rac = asn1str_to_u8(&ies->rac);
	}

	if (iu_grnc_id_parse(&grnc_id, &ies->globalRNC_ID) != 0) {
		LOGPIU(LOGL_ERROR,
		       "Failed to parse RANAP Global-RNC-ID IE\n");
		return -1;
	}

	sai = asn1str_to_u16(&ies->sai.sAC);
	msgb_gmmh(msg) = msgb_put(msg, ies->nas_pdu.size);
	memcpy(msgb_gmmh(msg), ies->nas_pdu.buf, ies->nas_pdu.size);

	/* Make sure we know the RNC Id and LAC+RAC coming in on this connection. */
	rnc = iu_rnc_register(grnc_id.rnc_id, ra_id.lac, ra_id.rac, &new_ctx->sccp_addr);

	ue = ue_conn_ctx_alloc(rnc, new_ctx->conn_id);
	OSMO_ASSERT(ue);
	ue->ra_id = ra_id;

	/* Feed into the MM layer */
	msg->dst = ue;
	global_iu_recv_cb(msg, &ra_id, &sai);

	msgb_free(msg);

	return 0;
}

static int ranap_handle_co_dt(void *ctx, RANAP_DirectTransferIEs_t *ies)
{
	struct gprs_ra_id _ra_id, *ra_id = NULL;
	uint16_t _sai, *sai = NULL;
	struct msgb *msg = msgb_alloc(256, "RANAP->NAS");

	if (ies->presenceMask & DIRECTTRANSFERIES_RANAP_LAI_PRESENT) {
		if (ranap_parse_lai(&_ra_id, &ies->lai) != 0) {
			LOGPIU(LOGL_ERROR, "Failed to parse RANAP LAI IE\n");
			return -1;
		}
		ra_id = &_ra_id;
		if (ies->presenceMask & DIRECTTRANSFERIES_RANAP_RAC_PRESENT) {
			_ra_id.rac = asn1str_to_u8(&ies->rac);
		}
		if (ies->presenceMask & DIRECTTRANSFERIES_RANAP_SAI_PRESENT) {
			_sai = asn1str_to_u16(&ies->sai.sAC);
			sai = &_sai;
		}
	}

	msgb_gmmh(msg) = msgb_put(msg, ies->nas_pdu.size);
	memcpy(msgb_gmmh(msg), ies->nas_pdu.buf, ies->nas_pdu.size);

	/* Feed into the MM/CC/SMS-CP layer */
	msg->dst = ctx;
	global_iu_recv_cb(msg, ra_id, sai);

	msgb_free(msg);

	return 0;
}

static int ranap_handle_co_err_ind(void *ctx, RANAP_ErrorIndicationIEs_t *ies)
{
	if (ies->presenceMask & ERRORINDICATIONIES_RANAP_CAUSE_PRESENT)
		LOGPIU(LOGL_ERROR, "Rx Error Indication (%s)\n",
		       ranap_cause_str(&ies->cause));
	else
		LOGPIU(LOGL_ERROR, "Rx Error Indication\n");

	return 0;
}

int ranap_iu_tx(struct msgb *msg_nas, uint8_t sapi)
{
	struct ranap_ue_conn_ctx *uectx = msg_nas->dst;
	struct msgb *msg;
	struct osmo_scu_prim *prim;

	LOGPIU(LOGL_INFO, "Transmitting L3 Message as RANAP DT (SCCP conn_id %u)\n",
	       uectx->conn_id);

	msg = ranap_new_msg_dt(sapi, msg_nas->data, msgb_length(msg_nas));
	msgb_free(msg_nas);
	msg->l2h = msg->data;
	prim = (struct osmo_scu_prim *) msgb_push(msg, sizeof(*prim));
	prim->u.data.conn_id = uectx->conn_id;
	osmo_prim_init(&prim->oph, SCCP_SAP_USER,
			OSMO_SCU_PRIM_N_DATA,
			PRIM_OP_REQUEST, msg);
	osmo_sccp_user_sap_down(g_scu, &prim->oph);
	return 0;
}

/* Send Iu Release for the given UE connection.
 * If cause is NULL, the standard "No remaining RAB" cause is sent, otherwise
 * the provided cause. */
int ranap_iu_tx_release(struct ranap_ue_conn_ctx *ctx, const struct RANAP_Cause *cause)
{
	struct msgb *msg;
	struct osmo_scu_prim *prim;
	static const struct RANAP_Cause default_cause = {
		.present = RANAP_Cause_PR_radioNetwork,
		.choice.radioNetwork = RANAP_CauseRadioNetwork_no_remaining_rab,
	};

	if (!cause)
		cause = &default_cause;

	msg = ranap_new_msg_iu_rel_cmd(cause);
	msg->l2h = msg->data;
	prim = (struct osmo_scu_prim *) msgb_push(msg, sizeof(*prim));
	prim->u.data.conn_id = ctx->conn_id;
	osmo_prim_init(&prim->oph, SCCP_SAP_USER,
			OSMO_SCU_PRIM_N_DATA,
			PRIM_OP_REQUEST, msg);
	return osmo_sccp_user_sap_down(g_scu, &prim->oph);
}

static int ranap_handle_co_iu_rel_req(struct ranap_ue_conn_ctx *ctx, RANAP_Iu_ReleaseRequestIEs_t *ies)
{
	LOGPIU(LOGL_INFO, "Received Iu Release Request, Sending Release Command\n");
	ranap_iu_tx_release(ctx, &ies->cause);
	return 0;
}

static int ranap_handle_co_rab_ass_resp(struct ranap_ue_conn_ctx *ctx, RANAP_RAB_AssignmentResponseIEs_t *ies)
{
	int rc = -1;

	LOGPIU(LOGL_INFO,
	       "Rx RAB Assignment Response for UE conn_id %u\n", ctx->conn_id);
	if (ies->presenceMask & RAB_ASSIGNMENTRESPONSEIES_RANAP_RAB_SETUPORMODIFIEDLIST_PRESENT) {
		/* TODO: Iterate over list of SetupOrModifiedList IEs and handle each one */
		RANAP_IE_t *ranap_ie = ies->raB_SetupOrModifiedList.raB_SetupOrModifiedList_ies.list.array[0];
		RANAP_RAB_SetupOrModifiedItemIEs_t setup_ies;

		rc = ranap_decode_rab_setupormodifieditemies_fromlist(&setup_ies, &ranap_ie->value);
		if (rc) {
			LOGPIU(LOGL_ERROR, "Error in ranap_decode_rab_setupormodifieditemies()\n");
			return rc;
		}

		rc = global_iu_event_cb(ctx, RANAP_IU_EVENT_RAB_ASSIGN, &setup_ies);

		ranap_free_rab_setupormodifieditemies(&setup_ies);
	}
	/* FIXME: handle RAB Ass failure? */

	return rc;
}

static void cn_ranap_handle_co_initial(void *ctx, ranap_message *message)
{
	int rc;

	LOGPIU(LOGL_NOTICE, "handle_co_initial(dir=%u, proc=%u)\n", message->direction, message->procedureCode);

	if (message->direction != RANAP_RANAP_PDU_PR_initiatingMessage
	    || message->procedureCode != RANAP_ProcedureCode_id_InitialUE_Message) {
		LOGPIU(LOGL_ERROR, "Expected direction 'InitiatingMessage',"
		       " procedureCode 'InitialUE_Message', instead got %u and %u\n",
		       message->direction, message->procedureCode);
		rc = -1;
	}
	else
		rc = ranap_handle_co_initial_ue(ctx, &message->msg.initialUE_MessageIEs);

	if (rc) {
		LOGPIU(LOGL_ERROR, "Error in %s (%d)\n", __func__, rc);
		/* TODO handling of the error? */
	}
}

/* Entry point for connection-oriented RANAP message */
static void cn_ranap_handle_co(void *ctx, ranap_message *message)
{
	int rc;

	LOGPIU(LOGL_NOTICE, "handle_co(dir=%u, proc=%u)\n", message->direction, message->procedureCode);

	switch (message->direction) {
	case RANAP_RANAP_PDU_PR_initiatingMessage:
		switch (message->procedureCode) {
		case RANAP_ProcedureCode_id_InitialUE_Message:
			LOGPIU(LOGL_ERROR, "Got InitialUE_Message but this is not a new conn\n");
			rc = -1;
			break;
		case RANAP_ProcedureCode_id_DirectTransfer:
			rc = ranap_handle_co_dt(ctx, &message->msg.directTransferIEs);
			break;
		case RANAP_ProcedureCode_id_ErrorIndication:
			rc = ranap_handle_co_err_ind(ctx, &message->msg.errorIndicationIEs);
			break;
		case RANAP_ProcedureCode_id_Iu_ReleaseRequest:
			/* Iu Release Request */
			rc = ranap_handle_co_iu_rel_req(ctx, &message->msg.iu_ReleaseRequestIEs);
			break;
		default:
			LOGPIU(LOGL_ERROR, "Received Initiating Message: unknown Procedure Code %d\n",
			       message->procedureCode);
			rc = -1;
			break;
		}
		break;
	case RANAP_RANAP_PDU_PR_successfulOutcome:
		switch (message->procedureCode) {
		case RANAP_ProcedureCode_id_SecurityModeControl:
			/* Security Mode Complete */
			rc = global_iu_event_cb(ctx, RANAP_IU_EVENT_SECURITY_MODE_COMPLETE, NULL);
			break;
		case RANAP_ProcedureCode_id_Iu_Release:
			/* Iu Release Complete */
			rc = global_iu_event_cb(ctx, RANAP_IU_EVENT_IU_RELEASE, NULL);
			if (rc) {
				LOGPIU(LOGL_ERROR, "Iu Release event: Iu Event callback returned %d\n",
				       rc);
			}
			break;
		default:
			LOGPIU(LOGL_ERROR, "Received Successful Outcome: unknown Procedure Code %d\n",
			       message->procedureCode);
			rc = -1;
			break;
		}
		break;
	case RANAP_RANAP_PDU_PR_outcome:
		switch (message->procedureCode) {
		case RANAP_ProcedureCode_id_RAB_Assignment:
			/* RAB Assignment Response */
			rc = ranap_handle_co_rab_ass_resp(ctx, &message->msg.raB_AssignmentResponseIEs);
			break;
		default:
			LOGPIU(LOGL_ERROR, "Received Outcome: unknown Procedure Code %d\n",
			       message->procedureCode);
			rc = -1;
			break;
		}
		break;
	case RANAP_RANAP_PDU_PR_unsuccessfulOutcome:
	default:
		LOGPIU(LOGL_ERROR, "Received Unsuccessful Outcome: Procedure Code %d\n",
		       message->procedureCode);
		rc = -1;
		break;
	}

	if (rc) {
		LOGPIU(LOGL_ERROR, "Error in %s (%d)\n", __func__, rc);
		/* TODO handling of the error? */
	}
}

static int ranap_handle_cl_reset_req(void *ctx, RANAP_ResetIEs_t *ies)
{
	/* FIXME: send reset response */
	return -1;
}

static int ranap_handle_cl_err_ind(void *ctx, RANAP_ErrorIndicationIEs_t *ies)
{
	if (ies->presenceMask & ERRORINDICATIONIES_RANAP_CAUSE_PRESENT)
		LOGPIU(LOGL_ERROR, "Rx Error Indication (%s)\n",
		       ranap_cause_str(&ies->cause));
	else
		LOGPIU(LOGL_ERROR, "Rx Error Indication\n");

	return 0;
}

/* Entry point for connection-less RANAP message */
static void cn_ranap_handle_cl(void *ctx, ranap_message *message)
{
	int rc;

	switch (message->direction) {
	case RANAP_RANAP_PDU_PR_initiatingMessage:
		switch (message->procedureCode) {
		case RANAP_ProcedureCode_id_Reset:
			/* received reset.req, send reset.resp */
			rc = ranap_handle_cl_reset_req(ctx, &message->msg.resetIEs);
			break;
		case RANAP_ProcedureCode_id_ErrorIndication:
			rc = ranap_handle_cl_err_ind(ctx, &message->msg.errorIndicationIEs);
			break;
		default:
			rc = -1;
			break;
		}
		break;
	case RANAP_RANAP_PDU_PR_successfulOutcome:
	case RANAP_RANAP_PDU_PR_unsuccessfulOutcome:
	case RANAP_RANAP_PDU_PR_outcome:
	default:
		rc = -1;
		break;
	}

	if (rc) {
		LOGPIU(LOGL_ERROR, "Error in %s (%d)\n", __func__, rc);
		/* TODO handling of the error? */
	}
}

/***********************************************************************
 * Paging
 ***********************************************************************/

struct osmo_sccp_addr local_sccp_addr = {
	.presence = OSMO_SCCP_ADDR_T_SSN | OSMO_SCCP_ADDR_T_PC,
	.ri = OSMO_SCCP_RI_SSN_PC,
	.ssn = OSMO_SCCP_SSN_RANAP,
	.pc = 1,
};

/* Send a paging command down a given SCCP User. tmsi and paging_cause are
 * optional and may be passed NULL and 0, respectively, to disable their use.
 * See enum RANAP_PagingCause.
 *
 * If TMSI is given, the IMSI is not sent over the air interface. Nevertheless,
 * the IMSI is still required for resolution in the HNB-GW and/or(?) RNC. */
static int iu_tx_paging_cmd(struct osmo_sccp_addr *called_addr,
			    const char *imsi, const uint32_t *tmsi,
			    bool is_ps, uint32_t paging_cause)
{
	struct msgb *msg;
	msg = ranap_new_msg_paging_cmd(imsi, tmsi, is_ps? 1 : 0, paging_cause);
	msg->l2h = msg->data;
	osmo_sccp_tx_unitdata_msg(g_scu, &local_sccp_addr, called_addr, msg);
	return 0;
}

static int iu_page(const char *imsi, const uint32_t *tmsi_or_ptimsi,
		   uint16_t lac, uint8_t rac, bool is_ps)
{
	struct ranap_iu_rnc *rnc;
	int pagings_sent = 0;

	if (tmsi_or_ptimsi) {
		LOGPIU(LOGL_DEBUG, "%s: Looking for RNCs to page for IMSI %s"
		       " (paging will use %s %x)\n",
		       is_ps? "IuPS" : "IuCS",
		       imsi,
		       is_ps? "PTMSI" : "TMSI",
		       *tmsi_or_ptimsi);
	} else {
		LOGPIU(LOGL_DEBUG, "%s: Looking for RNCs to page for IMSI %s"
		       " (paging will use IMSI)\n",
		       is_ps? "IuPS" : "IuCS",
		       imsi
		      );
	}

	llist_for_each_entry(rnc, &rnc_list, entry) {
		if (rnc->lac != lac)
			continue;
		if (is_ps && rnc->rac != rac)
			continue;

		/* Found a match! */
		if (iu_tx_paging_cmd(&rnc->sccp_addr, imsi, tmsi_or_ptimsi, is_ps, 0)
		    == 0) {
			LOGPIU(LOGL_DEBUG,
			       "%s: Paged for IMSI %s on RNC %d, on SCCP addr %s\n",
			       is_ps? "IuPS" : "IuCS",
			       imsi, rnc->rnc_id, osmo_sccp_addr_dump(&rnc->sccp_addr));
			pagings_sent ++;
		}
	}

	/* Some logging... */
	if (pagings_sent > 0) {
		LOGPIU(LOGL_DEBUG,
		       "%s: %d RNCs were paged for IMSI %s.\n",
		       is_ps? "IuPS" : "IuCS",
		       pagings_sent, imsi);
	}
	else {
		if (is_ps) {
			LOGPIU(LOGL_ERROR, "IuPS: Found no RNC to page for"
			       " LAC %d RAC %d (would have paged IMSI %s)\n",
			       lac, rac, imsi);
		}
		else {
			LOGPIU(LOGL_ERROR, "IuCS: Found no RNC to page for"
			       " LAC %d (would have paged IMSI %s)\n",
			       lac, imsi);
		}
	}

	return pagings_sent;
}

int ranap_iu_page_cs(const char *imsi, const uint32_t *tmsi, uint16_t lac)
{
	return iu_page(imsi, tmsi, lac, 0, false);
}

int ranap_iu_page_ps(const char *imsi, const uint32_t *ptmsi, uint16_t lac, uint8_t rac)
{
	return iu_page(imsi, ptmsi, lac, rac, true);
}


/***********************************************************************
 *
 ***********************************************************************/

int tx_unitdata(struct osmo_sccp_user *scu);
int tx_conn_req(struct osmo_sccp_user *scu, uint32_t conn_id);

struct osmo_prim_hdr *make_conn_req(uint32_t conn_id);
struct osmo_prim_hdr *make_dt1_req(uint32_t conn_id, const uint8_t *data, unsigned int len);

static struct osmo_prim_hdr *make_conn_resp(struct osmo_scu_connect_param *param)
{
	struct msgb *msg = msgb_alloc(1024, "conn_resp");
	struct osmo_scu_prim *prim;

	prim = (struct osmo_scu_prim *) msgb_put(msg, sizeof(*prim));
	osmo_prim_init(&prim->oph, SCCP_SAP_USER,
			OSMO_SCU_PRIM_N_CONNECT,
			PRIM_OP_RESPONSE, msg);
	memcpy(&prim->u.connect, param, sizeof(prim->u.connect));
	return &prim->oph;
}

static int sccp_sap_up(struct osmo_prim_hdr *oph, void *_scu)
{
	struct osmo_sccp_user *scu = _scu;
	struct osmo_scu_prim *prim = (struct osmo_scu_prim *) oph;
	struct osmo_prim_hdr *resp = NULL;
	int rc;
	struct ranap_ue_conn_ctx *ue;
	struct new_ue_conn_ctx new_ctx = {};

	LOGPIU(LOGL_DEBUG, "sccp_sap_up(%s)\n", osmo_scu_prim_name(oph));

	switch (OSMO_PRIM_HDR(oph)) {
	case OSMO_PRIM(OSMO_SCU_PRIM_N_CONNECT, PRIM_OP_CONFIRM):
		/* confirmation of outbound connection */
		rc = -1;
		break;
	case OSMO_PRIM(OSMO_SCU_PRIM_N_CONNECT, PRIM_OP_INDICATION):
		/* indication of new inbound connection request*/
		LOGPIU(LOGL_DEBUG, "N-CONNECT.ind(X->%u)\n", prim->u.connect.conn_id);
		if (/*  prim->u.connect.called_addr.ssn != OSMO_SCCP_SSN_RANAP || */
		    !msgb_l2(oph->msg) || msgb_l2len(oph->msg) == 0) {
			LOGPIU(LOGL_NOTICE,
			     "Received invalid N-CONNECT.ind\n");
			return 0;
		}
		new_ctx.sccp_addr = prim->u.connect.calling_addr;
		new_ctx.conn_id = prim->u.connect.conn_id;
		/* first ensure the local SCCP socket is ACTIVE */
		resp = make_conn_resp(&prim->u.connect);
		osmo_sccp_user_sap_down(scu, resp);
		/* then handle the RANAP payload */
		rc = ranap_cn_rx_co(cn_ranap_handle_co_initial, &new_ctx, msgb_l2(oph->msg), msgb_l2len(oph->msg));
		break;
	case OSMO_PRIM(OSMO_SCU_PRIM_N_DISCONNECT, PRIM_OP_INDICATION):
		/* indication of disconnect */
		LOGPIU(LOGL_DEBUG, "N-DISCONNECT.ind(%u)\n",
		       prim->u.disconnect.conn_id);
		ue = ue_conn_ctx_find(prim->u.disconnect.conn_id);
		rc = ranap_cn_rx_co(cn_ranap_handle_co, ue, msgb_l2(oph->msg), msgb_l2len(oph->msg));
		break;
	case OSMO_PRIM(OSMO_SCU_PRIM_N_DATA, PRIM_OP_INDICATION):
		/* connection-oriented data received */
		LOGPIU(LOGL_DEBUG, "N-DATA.ind(%u, %s)\n", prim->u.data.conn_id,
		       osmo_hexdump(msgb_l2(oph->msg), msgb_l2len(oph->msg)));
		/* resolve UE context */
		ue = ue_conn_ctx_find(prim->u.data.conn_id);
		rc = ranap_cn_rx_co(cn_ranap_handle_co, ue, msgb_l2(oph->msg), msgb_l2len(oph->msg));
		break;
	case OSMO_PRIM(OSMO_SCU_PRIM_N_UNITDATA, PRIM_OP_INDICATION):
		/* connection-less data received */
		LOGPIU(LOGL_DEBUG, "N-UNITDATA.ind(%s)\n",
		       osmo_hexdump(msgb_l2(oph->msg), msgb_l2len(oph->msg)));
		rc = ranap_cn_rx_cl(cn_ranap_handle_cl, scu, msgb_l2(oph->msg), msgb_l2len(oph->msg));
		break;
	default:
		rc = -1;
		break;
	}

	msgb_free(oph->msg);
	return rc;
}

int ranap_iu_init(void *ctx, int log_subsystem, const char *sccp_user_name, struct osmo_sccp_instance *sccp,
		  ranap_iu_recv_cb_t iu_recv_cb, ranap_iu_event_cb_t iu_event_cb)
{
	iu_log_subsystem = log_subsystem;
	talloc_iu_ctx = talloc_named_const(ctx, 1, "iu");
	talloc_asn1_ctx = talloc_named_const(talloc_iu_ctx, 1, "asn1");

	global_iu_recv_cb = iu_recv_cb;
	global_iu_event_cb = iu_event_cb;
	g_sccp = sccp;
	g_scu = osmo_sccp_user_bind(g_sccp, sccp_user_name, sccp_sap_up, OSMO_SCCP_SSN_RANAP);

	return 0;
}
