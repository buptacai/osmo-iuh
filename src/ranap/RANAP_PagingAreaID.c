/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#include "RANAP_PagingAreaID.h"

static asn_per_constraints_t asn_PER_type_RANAP_PagingAreaID_constr_1 GCC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0l,  1l }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_RANAP_PagingAreaID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RANAP_PagingAreaID, choice.lAI),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANAP_LAI,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"lAI"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANAP_PagingAreaID, choice.rAI),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANAP_RAI,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rAI"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_RANAP_PagingAreaID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* lAI */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* rAI */
};
static asn_CHOICE_specifics_t asn_SPC_RANAP_PagingAreaID_specs_1 = {
	sizeof(struct RANAP_PagingAreaID),
	offsetof(struct RANAP_PagingAreaID, _asn_ctx),
	offsetof(struct RANAP_PagingAreaID, present),
	sizeof(((struct RANAP_PagingAreaID *)0)->present),
	asn_MAP_RANAP_PagingAreaID_tag2el_1,
	2,	/* Count of tags in the map */
	0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_RANAP_PagingAreaID = {
	"RANAP_PagingAreaID",
	"RANAP_PagingAreaID",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	CHOICE_decode_uper,
	CHOICE_encode_uper,
	CHOICE_decode_aper,
	CHOICE_encode_aper,
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&asn_PER_type_RANAP_PagingAreaID_constr_1,
	asn_MBR_RANAP_PagingAreaID_1,
	2,	/* Elements count */
	&asn_SPC_RANAP_PagingAreaID_specs_1	/* Additional specs */
};

