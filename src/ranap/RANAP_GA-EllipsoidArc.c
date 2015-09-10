/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "../../asn1/ranap/RANAP-IEs.asn"
 */

#include "RANAP_GA-EllipsoidArc.h"

static int
memb_innerRadius_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0l && value <= 65535l)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_uncertaintyRadius_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0l && value <= 127l)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_offsetAngle_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0l && value <= 179l)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_includedAngle_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0l && value <= 179l)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_confidence_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0l && value <= 127l)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_innerRadius_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 16,  16,  0l,  65535l }	/* (0..65535) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_uncertaintyRadius_constr_4 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  0l,  127l }	/* (0..127) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_offsetAngle_constr_5 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0l,  179l }	/* (0..179) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_includedAngle_constr_6 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0l,  179l }	/* (0..179) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_confidence_constr_7 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  0l,  127l }	/* (0..127) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_RANAP_GA_EllipsoidArc_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RANAP_GA_EllipsoidArc, geographicalCoordinates),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANAP_GeographicalCoordinates,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"geographicalCoordinates"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANAP_GA_EllipsoidArc, innerRadius),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_innerRadius_constraint_1,
		&asn_PER_memb_innerRadius_constr_3,
		0,
		"innerRadius"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANAP_GA_EllipsoidArc, uncertaintyRadius),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_uncertaintyRadius_constraint_1,
		&asn_PER_memb_uncertaintyRadius_constr_4,
		0,
		"uncertaintyRadius"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANAP_GA_EllipsoidArc, offsetAngle),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_offsetAngle_constraint_1,
		&asn_PER_memb_offsetAngle_constr_5,
		0,
		"offsetAngle"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANAP_GA_EllipsoidArc, includedAngle),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_includedAngle_constraint_1,
		&asn_PER_memb_includedAngle_constr_6,
		0,
		"includedAngle"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RANAP_GA_EllipsoidArc, confidence),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_confidence_constraint_1,
		&asn_PER_memb_confidence_constr_7,
		0,
		"confidence"
		},
	{ ATF_POINTER, 1, offsetof(struct RANAP_GA_EllipsoidArc, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RANAP_IE_Extensions,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"iE-Extensions"
		},
};
static const int asn_MAP_RANAP_GA_EllipsoidArc_oms_1[] = { 6 };
static const ber_tlv_tag_t asn_DEF_RANAP_GA_EllipsoidArc_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RANAP_GA_EllipsoidArc_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* geographicalCoordinates */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* innerRadius */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* uncertaintyRadius */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* offsetAngle */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* includedAngle */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* confidence */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_RANAP_GA_EllipsoidArc_specs_1 = {
	sizeof(struct RANAP_GA_EllipsoidArc),
	offsetof(struct RANAP_GA_EllipsoidArc, _asn_ctx),
	asn_MAP_RANAP_GA_EllipsoidArc_tag2el_1,
	7,	/* Count of tags in the map */
	asn_MAP_RANAP_GA_EllipsoidArc_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	6,	/* Start extensions */
	8	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RANAP_GA_EllipsoidArc = {
	"RANAP_GA-EllipsoidArc",
	"RANAP_GA-EllipsoidArc",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	SEQUENCE_decode_aper,
	SEQUENCE_encode_aper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_RANAP_GA_EllipsoidArc_tags_1,
	sizeof(asn_DEF_RANAP_GA_EllipsoidArc_tags_1)
		/sizeof(asn_DEF_RANAP_GA_EllipsoidArc_tags_1[0]), /* 1 */
	asn_DEF_RANAP_GA_EllipsoidArc_tags_1,	/* Same as above */
	sizeof(asn_DEF_RANAP_GA_EllipsoidArc_tags_1)
		/sizeof(asn_DEF_RANAP_GA_EllipsoidArc_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RANAP_GA_EllipsoidArc_1,
	7,	/* Elements count */
	&asn_SPC_RANAP_GA_EllipsoidArc_specs_1	/* Additional specs */
};

