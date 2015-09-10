/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_GA_Polygon_H_
#define	_RANAP_GA_Polygon_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include "RANAP_GeographicalCoordinates.h"
#include "RANAP_IE-Extensions.h"
#include <constr_SEQUENCE.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RANAP_GA-Polygon */
typedef struct RANAP_GA_Polygon {
	A_SEQUENCE_OF(struct Member {
		RANAP_GeographicalCoordinates_t	 geographicalCoordinates;
		RANAP_IE_Extensions_t	*iE_Extensions	/* OPTIONAL */;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANAP_GA_Polygon_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_GA_Polygon;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_GA_Polygon_H_ */
#include <asn_internal.h>
