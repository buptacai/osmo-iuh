/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_SDU_ParameterItem_H_
#define	_RANAP_SDU_ParameterItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RANAP_SDU-ErrorRatio.h"
#include "RANAP_ResidualBitErrorRatio.h"
#include "RANAP_DeliveryOfErroneousSDU.h"
#include "RANAP_SDU-FormatInformationParameters.h"
#include "RANAP_IE-Extensions.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RANAP_SDU-ParameterItem */
typedef struct RANAP_SDU_ParameterItem {
	RANAP_SDU_ErrorRatio_t	*sDU_ErrorRatio	/* OPTIONAL */;
	RANAP_ResidualBitErrorRatio_t	 residualBitErrorRatio;
	RANAP_DeliveryOfErroneousSDU_t	 deliveryOfErroneousSDU;
	RANAP_SDU_FormatInformationParameters_t	*sDU_FormatInformationParameters	/* OPTIONAL */;
	RANAP_IE_Extensions_t	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANAP_SDU_ParameterItem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_SDU_ParameterItem;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_SDU_ParameterItem_H_ */
#include <asn_internal.h>
