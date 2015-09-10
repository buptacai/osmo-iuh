/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_MBMSSessionDuration_H_
#define	_RANAP_MBMSSessionDuration_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RANAP_MBMSSessionDuration */
typedef OCTET_STRING_t	 RANAP_MBMSSessionDuration_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_MBMSSessionDuration;
asn_struct_free_f RANAP_MBMSSessionDuration_free;
asn_struct_print_f RANAP_MBMSSessionDuration_print;
asn_constr_check_f RANAP_MBMSSessionDuration_constraint;
ber_type_decoder_f RANAP_MBMSSessionDuration_decode_ber;
der_type_encoder_f RANAP_MBMSSessionDuration_encode_der;
xer_type_decoder_f RANAP_MBMSSessionDuration_decode_xer;
xer_type_encoder_f RANAP_MBMSSessionDuration_encode_xer;
per_type_decoder_f RANAP_MBMSSessionDuration_decode_uper;
per_type_encoder_f RANAP_MBMSSessionDuration_encode_uper;
per_type_decoder_f RANAP_MBMSSessionDuration_decode_aper;
per_type_encoder_f RANAP_MBMSSessionDuration_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_MBMSSessionDuration_H_ */
#include <asn_internal.h>
