/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_TraceDepth_H_
#define	_RANAP_TraceDepth_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_TraceDepth {
	RANAP_TraceDepth_minimum	= 0,
	RANAP_TraceDepth_medium	= 1,
	RANAP_TraceDepth_maximum	= 2
	/*
	 * Enumeration is extensible
	 */
} e_RANAP_TraceDepth;

/* RANAP_TraceDepth */
typedef long	 RANAP_TraceDepth_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_TraceDepth;
asn_struct_free_f RANAP_TraceDepth_free;
asn_struct_print_f RANAP_TraceDepth_print;
asn_constr_check_f RANAP_TraceDepth_constraint;
ber_type_decoder_f RANAP_TraceDepth_decode_ber;
der_type_encoder_f RANAP_TraceDepth_encode_der;
xer_type_decoder_f RANAP_TraceDepth_decode_xer;
xer_type_encoder_f RANAP_TraceDepth_encode_xer;
per_type_decoder_f RANAP_TraceDepth_decode_uper;
per_type_encoder_f RANAP_TraceDepth_encode_uper;
per_type_decoder_f RANAP_TraceDepth_decode_aper;
per_type_encoder_f RANAP_TraceDepth_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_TraceDepth_H_ */
#include <asn_internal.h>
