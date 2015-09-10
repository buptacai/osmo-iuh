/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_H_
#define	_RANAP_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RANAP_Alt-RAB-Parameter-GuaranteedBitrateType.h"
#include "RANAP_Alt-RAB-Parameter-SupportedGuaranteedBitrates.h"
#include "RANAP_IE-Extensions.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RANAP_Alt-RAB-Parameter-SupportedGuaranteedBitrateInf */
typedef struct RANAP_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf {
	RANAP_Alt_RAB_Parameter_GuaranteedBitrateType_t	 altSupportedGuaranteedBitrateType;
	RANAP_Alt_RAB_Parameter_SupportedGuaranteedBitrates_t	*altSupportedGuaranteedBitrates	/* OPTIONAL */;
	RANAP_IE_Extensions_t	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANAP_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_Alt_RAB_Parameter_SupportedGuaranteedBitrateInf_H_ */
#include <asn_internal.h>
