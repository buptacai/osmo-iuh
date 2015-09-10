/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_SignallingIndication_H_
#define	_RANAP_SignallingIndication_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_SignallingIndication {
	RANAP_SignallingIndication_signalling	= 0
	/*
	 * Enumeration is extensible
	 */
} e_RANAP_SignallingIndication;

/* RANAP_SignallingIndication */
typedef long	 RANAP_SignallingIndication_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_SignallingIndication;
asn_struct_free_f RANAP_SignallingIndication_free;
asn_struct_print_f RANAP_SignallingIndication_print;
asn_constr_check_f RANAP_SignallingIndication_constraint;
ber_type_decoder_f RANAP_SignallingIndication_decode_ber;
der_type_encoder_f RANAP_SignallingIndication_encode_der;
xer_type_decoder_f RANAP_SignallingIndication_decode_xer;
xer_type_encoder_f RANAP_SignallingIndication_encode_xer;
per_type_decoder_f RANAP_SignallingIndication_decode_uper;
per_type_encoder_f RANAP_SignallingIndication_encode_uper;
per_type_decoder_f RANAP_SignallingIndication_decode_aper;
per_type_encoder_f RANAP_SignallingIndication_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_SignallingIndication_H_ */
#include <asn_internal.h>
