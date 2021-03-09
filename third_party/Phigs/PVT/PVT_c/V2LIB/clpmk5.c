/* clpmk5.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__0 = 0;
static integer c__5 = 5;
static integer c__100 = 100;
static integer c__102 = 102;

#ifndef NO_PROTO
/* Subroutine */ int clpmk5_(char *dim, real *mcvnd, real *xf, real *inxf, 
	real *outxf, ftnlen dim_len)
#else /* NO_PROTO */
/* Subroutine */ int clpmk5_(dim, mcvnd, xf, inxf, outxf, dim_len)
char *dim;
real *mcvnd, *xf, *inxf, *outxf;
ftnlen dim_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];
    char ch__1[27], ch__2[76], ch__3[61];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real a, b, c, d, xa[3], ya[3], za[3];
    static integer ix;
    static real xx, yy;
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *), 
	    fail_(void), nsmk (integer *);
#else /* NO_PROTO */
    extern logical dyn_();
    extern /* Subroutine */ int npm3 (), fail_(), nsmk ();
#endif /* NO_PROTO */
    static logical inmcv;
    static integer visct;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), nemst (integer *), 
	    nslmt3 (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), nemst (), nslmt3 ();
#endif /* NO_PROTO */
    static logical nclipd;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     nsmcli (integer *), nspmci (integer *);
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int tranhs_(real *, real *, real *, real *, real *
	    , real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_(), nsmcli (), nspmci ();
    extern integer rndint_();
    extern /* Subroutine */ int tranhs_();
#endif /* NO_PROTO */
    static real ptxvec[6];

/*  CLPMK5 generates a 5x5 grid of polymarkers, some of which should be */

/* clipped (X style) and some of which should be visible (+ style) and the
n*/
/*  passes or fails based on operator response. */
/*  Input parameters: */
/*    DIM   : dimensionality of test (2 or 3) */
/*    XF    : transformation to be applied to clipping plane */
/*    INXF  : transformation to apply to marker to put it inside MCV */
/*    OUTXF : transformation to apply to marker to put it outside MCV */
/*    MCVND : half-space for MCV, in 3D or 2D format */
/* clipping indicator */
/*                noclip      clip */
/* modelling clipping operator */
/*                replace     intersect */
/* marker type */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/*  a,b,c,d = coefficients of transformed boundary plane */
    /* Parameter adjustments */
    outxf -= 5;
    inxf -= 5;
    xf -= 5;
    mcvnd -= 7;

    /* Function Body */
    for (ix = 1; ix <= 6; ++ix) {
	ptxvec[ix - 1] = mcvnd[ix + 6];
/* L100: */
    }
    if (*dim == '2') {
/*  two-dimensionalize */
#ifndef NO_PROTO
	ptxvec[5] = 0.f;
#else /* NO_PROTO */
	ptxvec[5] = (float)0.;
#endif /* NO_PROTO */
	ptxvec[4] = mcvnd[10];
	ptxvec[3] = mcvnd[9];
#ifndef NO_PROTO
	ptxvec[2] = 0.f;
#else /* NO_PROTO */
	ptxvec[2] = (float)0.;
#endif /* NO_PROTO */
    } else if (*dim == '3') {
/*        OK as is */
    } else {
/* Writing concatenation */
	i__1[0] = 25, a__1[0] = "CLPMK5 called with DIM = ";
	i__1[1] = 1, a__1[1] = dim;
	i__1[2] = 1, a__1[2] = ".";
	s_cat(ch__1, a__1, i__1, &c__3, 27L);
	unmsg_(ch__1, 27L);
    }
    tranhs_(ptxvec, &xf[5], &a, &b, &c, &d);
/*  visct = number of polymarkers which should be visible */
    visct = 0;
#ifndef NO_PROTO
    for (xx = .1f; xx <= 1.f; xx += .2f) {
	for (yy = .1f; yy <= 1.f; yy += .2f) {
#else /* NO_PROTO */
    for (xx = (float).1; xx <= (float)1.; xx += (float).2) {
	for (yy = (float).1; yy <= (float)1.; yy += (float).2) {
#endif /* NO_PROTO */
	    inmcv = rndint_(&c__1, &c__3) == 1;
	    nclipd = rndint_(&c__1, &c__2) == 1;
	    xa[0] = xx;
	    ya[0] = yy;
	    za[0] = (-(doublereal)a * xx - b * yy - d) / c;
	    if (inmcv) {
		nslmt3 (&inxf[5], &c__2);
	    } else {
		nslmt3 (&outxf[5], &c__2);
	    }
	    if (nclipd) {
		nsmcli (&c__0);
	    } else {
		nsmcli (&c__1);
	    }
	    if (inmcv || nclipd) {
/*  should be visible */
		nspmci (&c__2);
		nsmk (&c__2);
		++visct;
	    } else {
/*  should be invisible */
		nspmci (&c__3);
		nsmk (&c__5);
	    }
	    npm3 (&c__1, xa, ya, za);
/* L20: */
	}
/* L10: */
    }
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = dim;
    i__1[1] = 43, a__1[1] = "D GEOMETRY OF CLIPPING VOLUME: Is plus (+) ";
    i__1[2] = 32, a__1[2] = "the type of all visible markers?";
    s_cat(ch__2, a__1, i__1, &c__3, 76L);
    if (dyn_(ch__2, 76L)) {
/*        OK so far */
    } else {
	fail_();
	goto L380;
    }
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = dim;
    i__1[1] = 31, a__1[1] = "D GEOMETRY OF CLIPPING VOLUME: ";
    i__1[2] = 29, a__1[2] = "How many markers are visible?";
    s_cat(ch__3, a__1, i__1, &c__3, 61L);
    dchpfv_(ch__3, &c__100, &visct, 61L);
L380:
    nemst (&c__102);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* clpmk5_ */

