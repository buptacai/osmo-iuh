/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_AreaIdentity_H_
#define	_RANAP_AreaIdentity_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RANAP_SAI.h"
#include "RANAP_GeographicalArea.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_AreaIdentity_PR {
	RANAP_AreaIdentity_PR_NOTHING,	/* No components present */
	RANAP_AreaIdentity_PR_sAI,
	RANAP_AreaIdentity_PR_geographicalArea,
	/* Extensions may appear below */
	
} RANAP_AreaIdentity_PR;

/* RANAP_AreaIdentity */
typedef struct RANAP_AreaIdentity {
	RANAP_AreaIdentity_PR present;
	union RANAP_AreaIdentity_u {
		RANAP_SAI_t	 sAI;
		RANAP_GeographicalArea_t	 geographicalArea;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANAP_AreaIdentity_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_AreaIdentity;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_AreaIdentity_H_ */
#include <asn_internal.h>
