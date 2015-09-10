/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_LAI_H_
#define	_RANAP_LAI_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RANAP_PLMNidentity.h"
#include "RANAP_LAC.h"
#include "RANAP_IE-Extensions.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RANAP_LAI */
typedef struct RANAP_LAI {
	RANAP_PLMNidentity_t	 pLMNidentity;
	RANAP_LAC_t	 lAC;
	RANAP_IE_Extensions_t	*iE_Extensions	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANAP_LAI_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_LAI;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_LAI_H_ */
#include <asn_internal.h>
