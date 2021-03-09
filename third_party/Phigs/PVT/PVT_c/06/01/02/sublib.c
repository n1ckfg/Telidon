/* fort/06/01/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b4 = 3.f;
static real c_b5 = 4.f;
static real c_b6 = 5.f;
static real c_b7 = .03f;
#else /* NO_PROTO */
static real c_b4 = (float)3.;
static real c_b5 = (float)4.;
static real c_b6 = (float)5.;
static real c_b7 = (float).03;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__100 = 100;
#ifndef NO_PROTO
static real c_b15 = 0.f;
static real c_b18 = 2.f;
#else /* NO_PROTO */
static real c_b15 = (float)0.;
static real c_b18 = (float)2.;
#endif /* NO_PROTO */
static integer c__106 = 106;
static integer c__102 = 102;
static integer c__6 = 6;
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b36 = 1.5707963250000001f;
static real c_b45 = .5f;
static real c_b51 = .17453292500000001f;
static real c_b52 = 1.f;
#else /* NO_PROTO */
static real c_b36 = (float)1.5707963250000001;
static real c_b45 = (float).5;
static real c_b51 = (float).17453292500000001;
static real c_b52 = (float)1.;
#endif /* NO_PROTO */
static integer c__16 = 16;
#ifndef NO_PROTO
static real c_b71 = 1.5f;
#else /* NO_PROTO */
static real c_b71 = (float)1.5;
#endif /* NO_PROTO */
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b113 = .4f;
static real c_b117 = -1.f;
#else /* NO_PROTO */
static real c_b113 = (float).4;
static real c_b117 = (float)-1.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/tranhs                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tranhs_(real *hs, real *xform, real *a, real *b, real *c,
	 real *d)
#else /* NO_PROTO */
/* Subroutine */ int tranhs_(hs, xform, a, b, c, d)
real *hs, *xform, *a, *b, *c, *d;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int vec1_(real *, real *, real *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int vec1_();
#endif /* NO_PROTO */
    static real oldx[4], oldy[4], oldz[4], newx[4], newy[4], newz[4], tmpx, 
	    tmpy, tmpz;
#ifndef NO_PROTO
    extern /* Subroutine */ int pt3pl_(real *, real *, real *, real *, real *,
	     real *, real *), prpv1_(real *, real *, real *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pt3pl_(), prpv1_();
#endif /* NO_PROTO */
    static real vecax, vecay, vecaz, vecbx, vecby, vecbz;
#ifndef NO_PROTO
    extern /* Subroutine */ int arrtp3_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *), crossp_(real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int arrtp3_(), crossp_();
#endif /* NO_PROTO */

/*  TRANHS accepts a 3D half-space, described as a point (on the */
/*  boundary plane) and normal vector, applies a transform, and */
/*  returns the coefficients of the new boundary plane, such that */
/*  x,y,z is in the new half-space iff A*x + B*y + C*z + D .GE. 0 */
/*  Input parameters: */
/*    HS(1,2,3)  : x,y,z coordinates of point of half-space */
/*    HS(4,5,6)  : x,y,z coordinates of normal vector of half-space */
/*    XFORM      : transformation matrix */
/*  Output parameters: */
/*    A,B,C,D    : coefficients of new boundary plane. */
/*  VECA is a unit vector orthogonal to the normal vector */
    /* Parameter adjustments */
    xform -= 5;
    --hs;

    /* Function Body */
    prpv1_(&hs[4], &hs[5], &hs[6], &tmpx, &tmpy, &tmpz);
    vec1_(&tmpx, &tmpy, &tmpz, &vecax, &vecay, &vecaz);
/*  VECB is a unit vector orthogonal to the normal vector and VECA */
    crossp_(&vecax, &vecay, &vecaz, &hs[4], &hs[5], &hs[6], &tmpx, &tmpy, &
	    tmpz);
    vec1_(&tmpx, &tmpy, &tmpz, &vecbx, &vecby, &vecbz);
/*  OLD-1, OLD-2, and OLD-3 are all in the (old) boundary plane, */
/*  forming an L-shape. */
    oldx[0] = hs[1] + vecax;
    oldy[0] = hs[2] + vecay;
    oldz[0] = hs[3] + vecaz;
    oldx[1] = hs[1] + vecbx;
    oldy[1] = hs[2] + vecby;
    oldz[1] = hs[3] + vecbz;
    oldx[2] = hs[1];
    oldy[2] = hs[2];
    oldz[2] = hs[3];
/*  OLD-4 is a point inside the (old) half-space */
    oldx[3] = hs[1] + hs[4];
    oldy[3] = hs[2] + hs[5];
    oldz[3] = hs[3] + hs[6];
/*  transform 4 old points to 4 new points */
    arrtp3_(&c__4, oldx, oldy, oldz, &xform[5], newx, newy, newz);
/*  first 3 new points define new boundary plane */
    pt3pl_(newx, newy, newz, a, b, c, d);
/*  check that parity is OK - if not, negate co-efficients */
#ifndef NO_PROTO
    if (*a * newx[3] + *b * newy[3] + *c * newz[3] + *d < 0.f) {
#else /* NO_PROTO */
    if (*a * newx[3] + *b * newy[3] + *c * newz[3] + *d < (float)0.) {
#endif /* NO_PROTO */
	*a = -(doublereal)(*a);
	*b = -(doublereal)(*b);
	*c = -(doublereal)(*c);
	*d = -(doublereal)(*d);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tranhs_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/comtok                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int comtok_(real *expcom, char *expath, ftnlen expath_len)
#else /* NO_PROTO */
/* Subroutine */ int comtok_(expcom, expath, expath_len)
real *expcom;
char *expath;
ftnlen expath_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer spath[2]	/* was [2][1] */ = { 101,0 };

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), ifpf_();
#endif /* NO_PROTO */
    static integer idum[2];
    static real srpx, srpy, srpz;
#ifndef NO_PROTO
    extern /* Subroutine */ int niss3 (real *, real *, real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int niss3 ();
#endif /* NO_PROTO */
    static integer fpath[200]	/* was [2][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, iexlen, iexpth[200]	/* was [2][100] */, fpthsz;

/*  COMTOK accepts an expected composite transformation and found */
/*  path.  It performs an incremental spatial search of structure */
/*  #101, using the transformed value of (3,4,5) as the SRP, and */
/*  issues pass or fail depending on whether the actual found path */
/*  matches that expected. */
/*  Input parameters: */
/*    EXPCOM : expected composite transformation */
/*    EXPATH : expected found path */
/* clipping indicator */
/*                noclip      clip */
    /* Parameter adjustments */
    expcom -= 5;

    /* Function Body */
/*  get expected point in WC */
    etp3_(&c_b4, &c_b5, &c_b6, &expcom[5], &srpx, &srpy, &srpz);
/*  decode expected found path */
    setvs_(expath, iexpth, &iexlen, expath_len);
    niss3 (&srpx, &srpy, &srpz, &c_b7, &c__1, spath, &c__0, &c__1, &c__0, 
	    idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &c__100, &
	    errind, &fpthsz, fpath);
    i__1 = fpthsz << 1;
    L__1 = errind == 0 && iareql_(&i__1, fpath, &iexlen, iexpth);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* comtok_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/chkmcv                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int chkmcv_(char *stpath, char *expths, ftnlen stpath_len, 
	ftnlen expths_len)
#else /* NO_PROTO */
/* Subroutine */ int chkmcv_(stpath, expths, stpath_len, expths_len)
char *stpath, *expths;
ftnlen stpath_len;
ftnlen expths_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int ispths_(real *, real *, real *, real *, 
	    integer *, integer *, char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ispths_();
#endif /* NO_PROTO */

/*  CHKMCV checks that the correct sequence of found paths is returned */
/*  by ISS as a result of the starting path.  It issues pass or fail */
/*  depending on whether the actual found paths match those expected. */
/*  It always uses a search reference point of 0,0,0 and distance of 2. */

/*  Input parameters: */
/*    STPATH : starting path for ISS */
/*    EXPTHS : expected found paths */
/* clipping indicator */
/*                noclip      clip */
    ispths_(&c_b15, &c_b15, &c_b15, &c_b18, &c__1, &c__1, stpath, expths, 
	    stpath_len, expths_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chkmcv_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION 06.01.02/modtrn                   * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
	    erox_(&c_b36, rotxf);
	} else if (this__ == 2 || this__ == 5) {
/*  Rotate 90 around y axis */
	    eroy_(&c_b36, rotxf);
	} else {
/*  Rotate 90 around z axis */
	    eroz_(&c_b36, rotxf);
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
	ebltm3_(&c_b15, &c_b15, &c_b15, &xshf, &yshf, &zshf, &c_b15, &c_b15, &
		c_b15, &xscf, &yscf, &zscf, boxf);

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
	    ebltm3_(&r__1, &r__2, &c_b45, &c_b15, &c_b15, &c_b15, &c_b15, &
		    c_b15, &c_b51, &c_b52, &c_b52, &c_b52, ngxf);
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/ranary                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ranary_(integer *size, real *array)
#else /* NO_PROTO */
/* Subroutine */ int ranary_(size, array)
integer *size;
real *array;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer array_dim1, array_offset, i__1, i__2;

    /* Local variables */
    static integer i, j;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */

/*  RANARY initializes a 2D array of size x size to random values */
/*  between 0.5 and 1.5 */
    /* Parameter adjustments */
    array_dim1 = *size;
    array_offset = array_dim1 + 1;
    array -= array_offset;

    /* Function Body */
    i__1 = *size;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *size;
	for (j = 1; j <= i__2; ++j) {
	    array[i + j * array_dim1] = rndrl_(&c_b45, &c_b71);
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ranary_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/clpgon                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int clpgon_(integer *visct, integer *numpl, real *rad)
#else /* NO_PROTO */
/* Subroutine */ int clpgon_(visct, numpl, rad)
integer *visct, *numpl;
real *rad;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
#else /* NO_PROTO */
    double cos(), sin();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static real ang;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 ();
#endif /* NO_PROTO */
    static real xloc[500], yloc[500], zloc[500];
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int rnset_();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static real thsrad;
    static integer vislis[50];

/*  CLPGON draws a set of markers some of which are just inside the */
/*  clipping region shaped like a regular polygon, and the rest just */
/*  outside it. */
/*  Input parameters: */
/*    VISCT : number of markers to be drawn inside clipping region */
/*    NUMPL : total number of markers to be drawn = #sides of polygon */
/*    RAD   : radius of polygon (distance from center to face, not vertex)
 */
/* maximum number of planes to be tested */
/*  Choose visct markers to be inside */
    rnset_(visct, numpl, vislis);
/*  calculate coordinates of polymarker: */
    i__1 = *numpl;
    for (ix = 1; ix <= i__1; ++ix) {
	if (iarfnd_(&ix, visct, vislis) > 0) {
/*  Inside: */
#ifndef NO_PROTO
	    thsrad = *rad * .99f;
#else /* NO_PROTO */
	    thsrad = *rad * (float).99;
#endif /* NO_PROTO */
	} else {
/*  Outside: */
#ifndef NO_PROTO
	    thsrad = *rad * 1.01f;
#else /* NO_PROTO */
	    thsrad = *rad * (float)1.01;
#endif /* NO_PROTO */
	}
#ifndef NO_PROTO
	ang = (ix << 1) * 3.14159265f / *numpl;
	xloc[ix - 1] = thsrad * cos(ang) + .5f;
	yloc[ix - 1] = thsrad * sin(ang) + .5f;
#else /* NO_PROTO */
	ang = (ix << 1) * (float)3.14159265 / *numpl;
	xloc[ix - 1] = thsrad * cos(ang) + (float).5;
	yloc[ix - 1] = thsrad * sin(ang) + (float).5;
#endif /* NO_PROTO */
	zloc[ix - 1] = rndrl_(&c_b15, &c_b52);
/* L100: */
    }
    npm3 (numpl, xloc, yloc, zloc);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* clpgon_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/clpmk5                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/clpair                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int clpair_(real *xwinlo, real *ywinlo, real *xsize, real *
	ysize, integer *iwx, real *delta, real *zval)
#else /* NO_PROTO */
/* Subroutine */ int clpair_(xwinlo, ywinlo, xsize, ysize, iwx, delta, zval)
real *xwinlo, *ywinlo, *xsize, *ysize;
integer *iwx;
real *delta, *zval;
#endif /* NO_PROTO */
{
    static real xa[2], ya[2], za[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 ();
#endif /* NO_PROTO */

/*  CLPAIR draws a double polymarker in the middle of the requested */
/*  window, one just in front and one just behind a given z-value, so */
/*  that exactly one of the pair will be clipped. */
/*  Input parameters: */
/*    XWINLO,YWINLO : List of locations of lower-left window corners */
/*    XSIZE,YSIZE   : Window size */
/*    IWX           : Index into window list; which window to draw in */
/*   DELTA         : offset in X and Z dimension from nominal window cente
r*/
/*   ZVAL          : nominal Z location = z-value of expected clipping pla
ne*/
    /* Parameter adjustments */
    --ywinlo;
    --xwinlo;

    /* Function Body */
    xa[0] = xwinlo[*iwx] + *xsize / 2 - *delta;
    ya[0] = ywinlo[*iwx] + *ysize / 2;
    za[0] = *zval - *delta;
    xa[1] = xwinlo[*iwx] + *xsize / 2 + *delta;
    ya[1] = ywinlo[*iwx] + *ysize / 2;
    za[1] = *zval + *delta;
    npm3 (&c__2, xa, ya, za);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* clpair_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/locnpm                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int locnpm_(integer *nppm, integer *ypos, real *xloc)
#else /* NO_PROTO */
/* Subroutine */ int locnpm_(nppm, ypos, xloc)
integer *nppm, *ypos;
real *xloc;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real ya[5];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static real yval;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCNPM draws a polymarker with NPPM markers at the real y-location */
/*  corresponding to the integer index given in YPOS. */
    /* Parameter adjustments */
    --xloc;

    /* Function Body */
    yval = ylocel_(ypos);
    i__1 = *nppm;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[ix - 1] = yval;
/* L10: */
    }
    npm (nppm, &xloc[1], ya);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locnpm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/faclip                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int faclip_(real *acl, real *bcl, real *ccl, real *dcl, real 
	*xco, real *yco, real *zco, real *mcv3)
#else /* NO_PROTO */
/* Subroutine */ int faclip_(acl, bcl, ccl, dcl, xco, yco, zco, mcv3)
real *acl, *bcl, *ccl, *dcl, *xco, *yco, *zco, *mcv3;
#endif /* NO_PROTO */
{
    static real af, bf, cf, df;
    static integer jx;
#ifndef NO_PROTO
    extern /* Subroutine */ int pl2pl_(real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *);
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pl2pl_();
    extern doublereal rndrl_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/*  FACLIP accepts the co-efficients for two given clipping planes, */
/*  generates a plane for a fill area primitive and computes */
/*  another clipping plane, perpendicular to the primitive's */
/*  plane, but intersecting it the same way as does the given */
/*  clipping plane. */
/*  Input parameters: */
/*    ACL,BCL,CCL,DCL : co-efficients of given planes (CCL usually zero) 
*/
/*  Output parameters: */
/*    XCO,YCO         : x,y co-efficients of primitive plane */
/*    MCV3            : computed planes, perpendicular to primitive plane 
*/
/*  randomize plane of fill area (in MC): xco*x + yco*y - z + zco = 0 */
    /* Parameter adjustments */
    mcv3 -= 7;
    --dcl;
    --ccl;
    --bcl;
    --acl;

    /* Function Body */
    *xco = rndrl_(&c_b15, &c_b113);
    *yco = rndrl_(&c_b15, &c_b113);
#ifndef NO_PROTO
    *zco = .1f;
#else /* NO_PROTO */
    *zco = (float).1;
#endif /* NO_PROTO */
/*  calculate 3D MCVs perpendicular to MC fill area plane, with negative 
*/
/*  x-component. */
    for (jx = 1; jx <= 2; ++jx) {
	pl2pl_(xco, yco, &c_b117, zco, &acl[jx], &bcl[jx], &ccl[jx], &dcl[jx],
		 &af, &bf, &cf, &df);
#ifndef NO_PROTO
	if (af == 0.f) {
#else /* NO_PROTO */
	if (af == (float)0.) {
#endif /* NO_PROTO */
	    unmsg_("Generated invalid clipping plane.", 33L);
#ifndef NO_PROTO
	} else if (af > 0.f) {
#else /* NO_PROTO */
	} else if (af > (float)0.) {
#endif /* NO_PROTO */
	    af = -(doublereal)af;
	    bf = -(doublereal)bf;
	    cf = -(doublereal)cf;
	    df = -(doublereal)df;
	}
	mcv3[jx * 6 + 1] = -(doublereal)df / af;
#ifndef NO_PROTO
	mcv3[jx * 6 + 2] = 0.f;
	mcv3[jx * 6 + 3] = 0.f;
#else /* NO_PROTO */
	mcv3[jx * 6 + 2] = (float)0.;
	mcv3[jx * 6 + 3] = (float)0.;
#endif /* NO_PROTO */
	mcv3[jx * 6 + 4] = af;
	mcv3[jx * 6 + 5] = bf;
	mcv3[jx * 6 + 6] = cf;
/* L330: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* faclip_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 06.01.02/exedv                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int exedv_(char *vxstr, real *xexp, real *yexp, ftnlen 
	vxstr_len)
#else /* NO_PROTO */
/* Subroutine */ int exedv_(vxstr, xexp, yexp, vxstr_len)
char *vxstr;
real *xexp, *yexp;
ftnlen vxstr_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[20], ya[20];
    static integer ix, vx[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), setvs_(char *
	    , integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), setvs_();
#endif /* NO_PROTO */
    static integer vxsiz;

/*  EXEDV draws a polyline using the indicated elements of the */
/*  arrays of expected vertices. */
/*  Input parameters: */
/*    VXSTR     : Positions in array to use as vertices */
/*    XEXP,YEXP : Array of expected vertices from which values are taken 
*/
    /* Parameter adjustments */
    --yexp;
    --xexp;

    /* Function Body */
    setvs_(vxstr, vx, &vxsiz, vxstr_len);
    i__1 = vxsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	xa[ix - 1] = xexp[vx[ix - 1]];
	ya[ix - 1] = yexp[vx[ix - 1]];
/* L100: */
    }
    npl (&vxsiz, xa, ya);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* exedv_ */

