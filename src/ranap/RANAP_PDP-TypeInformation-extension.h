/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_PDP_TypeInformation_extension_H_
#define	_RANAP_PDP_TypeInformation_extension_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RANAP_PDP-Type-extension.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RANAP_PDP-TypeInformation-extension */
typedef struct RANAP_PDP_TypeInformation_extension {
	A_SEQUENCE_OF(RANAP_PDP_Type_extension_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANAP_PDP_TypeInformation_extension_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_PDP_TypeInformation_extension;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_PDP_TypeInformation_extension_H_ */
#include <asn_internal.h>
