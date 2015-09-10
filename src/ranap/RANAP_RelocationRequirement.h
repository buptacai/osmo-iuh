/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_RelocationRequirement_H_
#define	_RANAP_RelocationRequirement_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_RelocationRequirement {
	RANAP_RelocationRequirement_lossless	= 0,
	RANAP_RelocationRequirement_none	= 1,
	/*
	 * Enumeration is extensible
	 */
	RANAP_RelocationRequirement_realtime	= 2
} e_RANAP_RelocationRequirement;

/* RANAP_RelocationRequirement */
typedef long	 RANAP_RelocationRequirement_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_RelocationRequirement;
asn_struct_free_f RANAP_RelocationRequirement_free;
asn_struct_print_f RANAP_RelocationRequirement_print;
asn_constr_check_f RANAP_RelocationRequirement_constraint;
ber_type_decoder_f RANAP_RelocationRequirement_decode_ber;
der_type_encoder_f RANAP_RelocationRequirement_encode_der;
xer_type_decoder_f RANAP_RelocationRequirement_decode_xer;
xer_type_encoder_f RANAP_RelocationRequirement_encode_xer;
per_type_decoder_f RANAP_RelocationRequirement_decode_uper;
per_type_encoder_f RANAP_RelocationRequirement_encode_uper;
per_type_decoder_f RANAP_RelocationRequirement_decode_aper;
per_type_encoder_f RANAP_RelocationRequirement_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_RelocationRequirement_H_ */
#include <asn_internal.h>
