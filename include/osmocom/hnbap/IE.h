/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "HNBAP-PDU"
 * 	found in "../../asn1/hnbap/HNBAP-PDU.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_IE_H_
#define	_IE_H_


#include <asn_application.h>

/* Including external dependencies */
#include <osmocom/hnbap/ProtocolIE-ID.h>
#include <osmocom/hnbap/Criticality.h>
#include <ANY.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* IE */
typedef struct IE {
	ProtocolIE_ID_t	 id;
	Criticality_t	 criticality;
	ANY_t	 value;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IE_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IE;

#ifdef __cplusplus
}
#endif

#endif	/* _IE_H_ */
#include <asn_internal.h>