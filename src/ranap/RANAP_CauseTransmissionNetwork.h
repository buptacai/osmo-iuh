/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#ifndef	_RANAP_CauseTransmissionNetwork_H_
#define	_RANAP_CauseTransmissionNetwork_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANAP_CauseTransmissionNetwork {
	RANAP_CauseTransmissionNetwork_signalling_transport_resource_failure	= 65,
	RANAP_CauseTransmissionNetwork_iu_transport_connection_failed_to_establish	= 66
} e_RANAP_CauseTransmissionNetwork;

/* RANAP_CauseTransmissionNetwork */
typedef long	 RANAP_CauseTransmissionNetwork_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANAP_CauseTransmissionNetwork;
asn_struct_free_f RANAP_CauseTransmissionNetwork_free;
asn_struct_print_f RANAP_CauseTransmissionNetwork_print;
asn_constr_check_f RANAP_CauseTransmissionNetwork_constraint;
ber_type_decoder_f RANAP_CauseTransmissionNetwork_decode_ber;
der_type_encoder_f RANAP_CauseTransmissionNetwork_encode_der;
xer_type_decoder_f RANAP_CauseTransmissionNetwork_decode_xer;
xer_type_encoder_f RANAP_CauseTransmissionNetwork_encode_xer;
per_type_decoder_f RANAP_CauseTransmissionNetwork_decode_uper;
per_type_encoder_f RANAP_CauseTransmissionNetwork_encode_uper;
per_type_decoder_f RANAP_CauseTransmissionNetwork_decode_aper;
per_type_encoder_f RANAP_CauseTransmissionNetwork_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RANAP_CauseTransmissionNetwork_H_ */
#include <asn_internal.h>
