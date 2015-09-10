/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_GlobalCN_ID_H_
#define	_RANAP_GlobalCN_ID_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RANAP_PLMNidentity.h"
#include "RANAP_CN-ID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RANAP_GlobalCN-ID */
typedef struct RANAP_GlobalCN_ID {
	RANAP_PLMNidentity_t	 pLMNidentity;
	RANAP_CN_ID_t	 cN_ID;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANAP_GlobalCN_ID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_GlobalCN_ID;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_GlobalCN_ID_H_ */
#include <asn_internal.h>
