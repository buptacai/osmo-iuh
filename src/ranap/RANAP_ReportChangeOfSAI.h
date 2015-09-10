/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_ReportChangeOfSAI_H_
#define	_RANAP_ReportChangeOfSAI_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_ReportChangeOfSAI {
	RANAP_ReportChangeOfSAI_requested	= 0
	/*
	 * Enumeration is extensible
	 */
} e_RANAP_ReportChangeOfSAI;

/* RANAP_ReportChangeOfSAI */
typedef long	 RANAP_ReportChangeOfSAI_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_ReportChangeOfSAI;
asn_struct_free_f RANAP_ReportChangeOfSAI_free;
asn_struct_print_f RANAP_ReportChangeOfSAI_print;
asn_constr_check_f RANAP_ReportChangeOfSAI_constraint;
ber_type_decoder_f RANAP_ReportChangeOfSAI_decode_ber;
der_type_encoder_f RANAP_ReportChangeOfSAI_encode_der;
xer_type_decoder_f RANAP_ReportChangeOfSAI_decode_xer;
xer_type_encoder_f RANAP_ReportChangeOfSAI_encode_xer;
per_type_decoder_f RANAP_ReportChangeOfSAI_decode_uper;
per_type_encoder_f RANAP_ReportChangeOfSAI_encode_uper;
per_type_decoder_f RANAP_ReportChangeOfSAI_decode_aper;
per_type_encoder_f RANAP_ReportChangeOfSAI_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_ReportChangeOfSAI_H_ */
#include <asn_internal.h>
