/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_DataPDUType_H_
#define	_RANAP_DataPDUType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_DataPDUType {
	RANAP_DataPDUType_pDUtype0	= 0,
	RANAP_DataPDUType_pDUtype1	= 1
	/*
	 * Enumeration is extensible
	 */
} e_RANAP_DataPDUType;

/* RANAP_DataPDUType */
typedef long	 RANAP_DataPDUType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_DataPDUType;
asn_struct_free_f RANAP_DataPDUType_free;
asn_struct_print_f RANAP_DataPDUType_print;
asn_constr_check_f RANAP_DataPDUType_constraint;
ber_type_decoder_f RANAP_DataPDUType_decode_ber;
der_type_encoder_f RANAP_DataPDUType_encode_der;
xer_type_decoder_f RANAP_DataPDUType_decode_xer;
xer_type_encoder_f RANAP_DataPDUType_encode_xer;
per_type_decoder_f RANAP_DataPDUType_decode_uper;
per_type_encoder_f RANAP_DataPDUType_encode_uper;
per_type_decoder_f RANAP_DataPDUType_decode_aper;
per_type_encoder_f RANAP_DataPDUType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_DataPDUType_H_ */
#include <asn_internal.h>
