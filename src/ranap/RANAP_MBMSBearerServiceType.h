/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_MBMSBearerServiceType_H_
#define	_RANAP_MBMSBearerServiceType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_MBMSBearerServiceType {
	RANAP_MBMSBearerServiceType_multicast	= 0,
	RANAP_MBMSBearerServiceType_broadcast	= 1
	/*
	 * Enumeration is extensible
	 */
} e_RANAP_MBMSBearerServiceType;

/* RANAP_MBMSBearerServiceType */
typedef long	 RANAP_MBMSBearerServiceType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_MBMSBearerServiceType;
asn_struct_free_f RANAP_MBMSBearerServiceType_free;
asn_struct_print_f RANAP_MBMSBearerServiceType_print;
asn_constr_check_f RANAP_MBMSBearerServiceType_constraint;
ber_type_decoder_f RANAP_MBMSBearerServiceType_decode_ber;
der_type_encoder_f RANAP_MBMSBearerServiceType_encode_der;
xer_type_decoder_f RANAP_MBMSBearerServiceType_decode_xer;
xer_type_encoder_f RANAP_MBMSBearerServiceType_encode_xer;
per_type_decoder_f RANAP_MBMSBearerServiceType_decode_uper;
per_type_encoder_f RANAP_MBMSBearerServiceType_encode_uper;
per_type_decoder_f RANAP_MBMSBearerServiceType_decode_aper;
per_type_encoder_f RANAP_MBMSBearerServiceType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_MBMSBearerServiceType_H_ */
#include <asn_internal.h>
