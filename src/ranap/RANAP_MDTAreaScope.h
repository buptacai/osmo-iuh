/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_MDTAreaScope_H_
#define	_RANAP_MDTAreaScope_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RANAP_CellBased.h"
#include "RANAP_LABased.h"
#include "RANAP_RABased.h"
#include <NULL.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_MDTAreaScope_PR {
	RANAP_MDTAreaScope_PR_NOTHING,	/* No components present */
	RANAP_MDTAreaScope_PR_cellbased,
	RANAP_MDTAreaScope_PR_labased,
	RANAP_MDTAreaScope_PR_rabased,
	RANAP_MDTAreaScope_PR_plmn_area_based,
	/* Extensions may appear below */
	
} RANAP_MDTAreaScope_PR;

/* RANAP_MDTAreaScope */
typedef struct RANAP_MDTAreaScope {
	RANAP_MDTAreaScope_PR present;
	union RANAP_MDTAreaScope_u {
		RANAP_CellBased_t	 cellbased;
		RANAP_LABased_t	 labased;
		RANAP_RABased_t	 rabased;
		NULL_t	 plmn_area_based;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANAP_MDTAreaScope_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_MDTAreaScope;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_MDTAreaScope_H_ */
#include <asn_internal.h>
