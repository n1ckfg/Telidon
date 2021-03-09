/* modtrn.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__106 = 106;
static integer c__1 = 1;
static integer c__102 = 102;
static integer c__4 = 4;
static integer c__6 = 6;
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b16 = 1.5707963250000001f;
static real c_b19 = 0.f;
static real c_b25 = .5f;
static real c_b31 = .17453292500000001f;
static real c_b32 = 1.f;
#else /* NO_PROTO */
static real c_b16 = (float)1.5707963250000001;
static real c_b19 = (float)0.;
static real c_b25 = (float).5;
static real c_b31 = (float).17453292500000001;
static real c_b32 = (float)1.;
#endif /* NO_PROTO */
static integer c__16 = 16;
static integer c__0 = 0;

#ifndef NO_PROTO
integer modtrn_(integer *dim)
#else /* NO_PROTO */
integer modtrn_(dim)
integer *dim;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real px[2] = { 1.f,2.f };
    static real py[2] = { 1.f,2.f };
    static real pz[2] = { 1.f,2.f };
#else /* NO_PROTO */
    static real px[2] = { (float)1.,(float)2. };
    static real py[2] = { (float)1.,(float)2. };
    static real pz[2] = { (float)1.,(float)2. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer ret_val;
    real r__1, r__2;

    /* Local variables */
    static real xa[2], ya[2], xf[16]	/* was [4][4] */;
    static integer ix;
    static real xf2[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *), etp3_(real *,
	     real *, real *, real *, real *, real *, real *), npl3 (integer *,
	     real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm (), etp3_(), npl3 ();
#endif /* NO_PROTO */
    static real wc1x, wc1y, tmp4[16]	/* was [4][4] */, wc1z, wc2x, wc2y, 
	    wc2z;
#ifndef NO_PROTO
    extern /* Subroutine */ int win6_(integer *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int win6_();
#endif /* NO_PROTO */
    static real idxf[16]	/* was [4][4] */, fixf[16]	/* was [4][4] 
	    */, boxf[16]	/* was [4][4] */, xmid, ngxf[16]	/* 
	    was [4][4] */, xscf, yscf, zscf, ymid;
    static integer this__;
    static real zmid, xshf, yshf, zshf;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *), exp34_(real *, real *), 
	    erox_(real *, real *), eroy_(real *, real *), eroz_(real *, real *
	    );
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk (), exp34_(), erox_(), eroy_(), eroz_();
#endif /* NO_PROTO */
    static real xsiz, ysiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *), idmat_(
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_(), idmat_();
#endif /* NO_PROTO */
    static integer ngbox;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), unmsg_(char *, ftnlen), nslmt (
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), unmsg_(), nslmt ();
#endif /* NO_PROTO */
    static real rotxf[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), ebltm3_(real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *), nsgmt3 (real *), nslmt3 (real *, integer 
	    *), cpyiar_(integer *, real *, real *), nsplci (integer *), 
	    nspmci (integer *);
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), ebltm3_(), nsgmt3 (), nslmt3 (), 
	    cpyiar_(), nsplci (), nspmci ();
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer lisbox[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int ranary_(integer *, real *), rnperm_(integer *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ranary_(), rnperm_();
#endif /* NO_PROTO */
    static real xwinlo[6], ywinlo[6];

/*  MODTRN performs a random transformation on six line segments using */
/*  various modelling facilities, and marks the expected endpoints */
/*  with circle-polymarkers.  It returns the identifier of the line */
/*  segment which is marked incorrectly. */

/*  Input parameter: */
/*     DIM: dimensionality of the transformations to be tested (2 or 3) */

/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* Marker type */
/*  Set up structure 106 to label 6 windows */
    win6_(&c__106, &c__1, &xsiz, &ysiz, xwinlo, ywinlo);
/*  Open test structure */
    nopst (&c__102);
/*  Set polymarker type */
    nsmk (&c__4);
/*  Initialize identity matrix */
    idmat_(&c__4, idxf);
    rnperm_(&c__6, lisbox);
/*  box to be drawn incorrectly */
    ngbox = rndint_(&c__1, &c__6);
    nsplci (&c__2);
    nspmci (&c__3);
    for (ix = 1; ix <= 6; ++ix) {
	this__ = lisbox[ix - 1];
	if (*dim == 2) {
/*  set up for 2D */
	    ranary_(&c__3, xf2);
	    exp34_(xf2, xf);
	} else if (*dim == 3) {
/*  set up for 3D */
	    ranary_(&c__4, xf);
	} else {
	    unmsg_("MODTRN called with invalid dimension.", 37L);
	}
	if (this__ == 1 || this__ == 4) {
/*  Rotate 90 around x axis */
	    erox_(&c_b16, rotxf);
	} else if (this__ == 2 || this__ == 5) {
/*  Rotate 90 around y axis */
	    eroy_(&c_b16, rotxf);
	} else {
/*  Rotate 90 around z axis */
	    eroz_(&c_b16, rotxf);
	}

/*  Compose new transformation matrix */
	ecom3_(rotxf, xf, tmp4);

/*  Calculate transformation by ROTXF x XF of (1,1,1) and (2,2,2) */
	etp3_(px, py, pz, tmp4, &wc1x, &wc1y, &wc1z);
	etp3_(&px[1], &py[1], &pz[1], tmp4, &wc2x, &wc2y, &wc2z);
#ifndef NO_PROTO
	xscf = xsiz * .8f / (wc2x - wc1x);
	yscf = ysiz * .8f / (wc2y - wc1y);
	zscf = .8f / (wc2z - wc1z);
#else /* NO_PROTO */
	xscf = xsiz * (float).8 / (wc2x - wc1x);
	yscf = ysiz * (float).8 / (wc2y - wc1y);
	zscf = (float).8 / (wc2z - wc1z);
#endif /* NO_PROTO */
	xmid = xscf * (wc1x + wc2x) / 2;
	ymid = yscf * (wc1y + wc2y) / 2;
	zmid = zscf * (wc1z + wc2z) / 2;
	xshf = xwinlo[ix - 1] + xsiz / 2 - xmid;
	yshf = ywinlo[ix - 1] + ysiz / 2 - ymid;
#ifndef NO_PROTO
	zshf = .5f - zmid;
#else /* NO_PROTO */
	zshf = (float).5 - zmid;
#endif /* NO_PROTO */
	ebltm3_(&c_b19, &c_b19, &c_b19, &xshf, &yshf, &zshf, &c_b19, &c_b19, &
		c_b19, &xscf, &yscf, &zscf, boxf);

/*  Compose new transformation matrix = BOX x ROTXF x XF */
	ecom3_(boxf, rotxf, fixf);
	ecom3_(fixf, xf, tmp4);

/*  Calculate expected positions of (1,1,1) and (2,2,2) */
	etp3_(px, py, pz, tmp4, &wc1x, &wc1y, &wc1z);
	etp3_(&px[1], &py[1], &pz[1], tmp4, &wc2x, &wc2y, &wc2z);
	if (ix == ngbox) {
/*  distort result - rotate by 10 degrees */
	    r__1 = xwinlo[ix - 1] + xsiz / 2;
	    r__2 = ywinlo[ix - 1] + ysiz / 2;
	    ebltm3_(&r__1, &r__2, &c_b25, &c_b19, &c_b19, &c_b19, &c_b19, &
		    c_b19, &c_b31, &c_b32, &c_b32, &c_b32, ngxf);
	    ecom3_(ngxf, fixf, tmp4);
	    cpyiar_(&c__16, tmp4, fixf);
	}
	if (this__ < 3) {
	    nslmt3 (fixf, &c__2);
	    if (*dim == 2) {
		nslmt (xf2, &c__0);
	    } else {
		nslmt3 (xf, &c__0);
	    }
	} else if (this__ < 5) {
	    if (*dim == 2) {
		nslmt (xf2, &c__2);
	    } else {
		nslmt3 (xf, &c__2);
	    }
	    nslmt3 (fixf, &c__1);
	} else {
	    if (*dim == 2) {
		nslmt (xf2, &c__2);
	    } else {
		nslmt3 (xf, &c__2);
	    }
	    nsgmt3 (fixf);
	}
/*  Draw line segment as changed by transformation matrix */
	npl3 (&c__2, px, py, pz);
/*  Now expected endpoints with no transformations */
	nslmt3 (idxf, &c__2);
	nsgmt3 (idxf);
	xa[0] = wc1x;
	ya[0] = wc1y;
	xa[1] = wc2x;
	ya[1] = wc2y;
	npm (&c__2, xa, ya);
/* L100: */
    }
    nclst ();
    ret_val = ngbox;
    return ret_val;
} /* modtrn_ */

