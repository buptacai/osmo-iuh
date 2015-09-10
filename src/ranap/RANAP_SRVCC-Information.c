/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#include "RANAP_SRVCC-Information.h"

static int
memb_nonce_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size == 128l)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_nonce_constr_2 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  128l,  128l }	/* (SIZE(128..128)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_RANAP_SRVCC_Information_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RANAP_SRVCC_Information, nonce),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		memb_nonce_constraint_1,
		&asn_PER_memb_nonce_constr_2,
		0,
		"nonce"
		},
	{ ATF_POINTER, 1, offsetof(struct RANAP_SRVCC_Information, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANAP_IE_Extensions,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"iE-Extensions"
		},
};
static const int asn_MAP_RANAP_SRVCC_Information_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_RANAP_SRVCC_Information_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RANAP_SRVCC_Information_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nonce */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_RANAP_SRVCC_Information_specs_1 = {
	sizeof(struct RANAP_SRVCC_Information),
	offsetof(struct RANAP_SRVCC_Information, _asn_ctx),
	asn_MAP_RANAP_SRVCC_Information_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_RANAP_SRVCC_Information_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	1,	/* Start extensions */
	3	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RANAP_SRVCC_Information = {
	"RANAP_SRVCC-Information",
	"RANAP_SRVCC-Information",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	SEQUENCE_decode_aper,
	SEQUENCE_encode_aper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_RANAP_SRVCC_Information_tags_1,
	sizeof(asn_DEF_RANAP_SRVCC_Information_tags_1)
		/sizeof(asn_DEF_RANAP_SRVCC_Information_tags_1[0]), /* 1 */
	asn_DEF_RANAP_SRVCC_Information_tags_1,	/* Same as above */
	sizeof(asn_DEF_RANAP_SRVCC_Information_tags_1)
		/sizeof(asn_DEF_RANAP_SRVCC_Information_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RANAP_SRVCC_Information_1,
	2,	/* Elements count */
	&asn_SPC_RANAP_SRVCC_Information_specs_1	/* Additional specs */
};

