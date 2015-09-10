/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_GeographicalArea_H_
#define	_RANAP_GeographicalArea_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RANAP_GA-Point.h"
#include "RANAP_GA-PointWithUnCertainty.h"
#include "RANAP_GA-Polygon.h"
#include "RANAP_GA-PointWithUnCertaintyEllipse.h"
#include "RANAP_GA-PointWithAltitude.h"
#include "RANAP_GA-PointWithAltitudeAndUncertaintyEllipsoid.h"
#include "RANAP_GA-EllipsoidArc.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_GeographicalArea_PR {
	RANAP_GeographicalArea_PR_NOTHING,	/* No components present */
	RANAP_GeographicalArea_PR_point,
	RANAP_GeographicalArea_PR_pointWithUnCertainty,
	RANAP_GeographicalArea_PR_polygon,
	/* Extensions may appear below */
	RANAP_GeographicalArea_PR_pointWithUncertaintyEllipse,
	RANAP_GeographicalArea_PR_pointWithAltitude,
	RANAP_GeographicalArea_PR_pointWithAltitudeAndUncertaintyEllipsoid,
	RANAP_GeographicalArea_PR_ellipsoidArc
} RANAP_GeographicalArea_PR;

/* RANAP_GeographicalArea */
typedef struct RANAP_GeographicalArea {
	RANAP_GeographicalArea_PR present;
	union RANAP_GeographicalArea_u {
		RANAP_GA_Point_t	 point;
		RANAP_GA_PointWithUnCertainty_t	 pointWithUnCertainty;
		RANAP_GA_Polygon_t	 polygon;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
		RANAP_GA_PointWithUnCertaintyEllipse_t	 pointWithUncertaintyEllipse;
		RANAP_GA_PointWithAltitude_t	 pointWithAltitude;
		RANAP_GA_PointWithAltitudeAndUncertaintyEllipsoid_t	 pointWithAltitudeAndUncertaintyEllipsoid;
		RANAP_GA_EllipsoidArc_t	 ellipsoidArc;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANAP_GeographicalArea_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_GeographicalArea;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_GeographicalArea_H_ */
#include <asn_internal.h>
