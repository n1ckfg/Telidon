/* fort/04/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__27 = 27;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b32 = 0.f;
#else /* NO_PROTO */
static real c_b32 = (float)0.;
#endif /* NO_PROTO */
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04/arcpts                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int arcpts_(integer *numpts, real *xmid, real *ymid, real *
	rad, real *ang1, real *anginc, real *xa, real *ya, real *za)
#else /* NO_PROTO */
/* Subroutine */ int arcpts_(numpts, xmid, ymid, rad, ang1, anginc, xa, ya, 
	za)
integer *numpts;
real *xmid, *ymid, *rad, *ang1, *anginc, *xa, *ya, *za;
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

/*  ARCPTS fills in an array with points on an arc in x and y, on */
/*  an oblique plane (z = (x+y)/2) */
/*  Input parameters: */
/*    NUMPTS    : number of points to fill in */
/*    XMID,YMID : center of circle */
/*    RAD       : radius of circle */
/*    ANG1      : first angle */
/*    ANGINC    : angle increment */
/*  Output parameters: */
/*    XA,YA,ZA  : arc points returned */
    /* Parameter adjustments */
    --za;
    --ya;
    --xa;

    /* Function Body */
    ang = *ang1;
    i__1 = *numpts;
    for (ix = 1; ix <= i__1; ++ix) {
	xa[ix] = *xmid + *rad * cos(ang);
	ya[ix] = *ymid + *rad * sin(ang);
#ifndef NO_PROTO
	za[ix] = xa[ix] * .5f + ya[ix] * .5f;
#else /* NO_PROTO */
	za[ix] = xa[ix] * (float).5 + ya[ix] * (float).5;
#endif /* NO_PROTO */
	ang += *anginc;
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* arcpts_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04/discol                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int discol_(integer *maxreq, integer *wkid, integer *ndisct)
#else /* NO_PROTO */
/* Subroutine */ int discol_(maxreq, wkid, ndisct)
integer *maxreq, *wkid, *ndisct;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2, r__3;

    /* Local variables */
    static integer ix, ncc;
    static real bval;
    static integer icol;
    static real gval, buse;
    static integer perm[30];
    static real guse, rval;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr ();
#endif /* NO_PROTO */
    static real ruse;
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7, bestc;
    static real bestd, cdist;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
#endif /* NO_PROTO */
    static real possc[81]	/* was [3][27] */;
    static integer chosen[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, thiscl;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_();
#endif /* NO_PROTO */
    static integer nxtcol;
    static real rlzcol[84]	/* was [3][28] */;
    static integer maxsiz, szcolt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwksl (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwksl ();
#endif /* NO_PROTO */

/*  DISCOL attempts to change the color table so as to put distinct */
/*  foreground colors in entries 1-MAXREQ.  These are to be */
/*  distinct from the background color as well as from each other. */
/*  DISCOL also attempts to put the color "farthest" from the */
/*  background color (and hence, the most conspicuous) as color #1. */
/*  Input parameters: */
/*    MAXREQ : Number of requested distinct colors */
/*    WKID   : Workstation identifier */
/*  Output parameters: */
/*    NDISCT : Actual number of distinct colors in color table 1-NDISCT */

/* colour model */
/* type of returned value */
/*  set color model = RGB */
    nscmd (wkid, &c__1);
/*  set up possible values - all points at 0.0, 0.67, 1.0 - */
/*  bias towards lighter side of RGB cube */
    ix = 0;
#ifndef NO_PROTO
    for (rval = 0.f; rval <= 1.4f; rval += .67f) {
	ruse = dmin(rval,1.f);
	for (gval = 0.f; gval <= 1.4f; gval += .67f) {
	    guse = dmin(gval,1.f);
	    for (bval = 0.f; bval <= 1.4f; bval += .67f) {
		buse = dmin(bval,1.f);
#else /* NO_PROTO */
    for (rval = (float)0.; rval <= (float)1.4; rval += (float).67) {
	ruse = dmin(rval,(float)1.);
	for (gval = (float)0.; gval <= (float)1.4; gval += (float).67) {
	    guse = dmin(gval,(float)1.);
	    for (bval = (float)0.; bval <= (float)1.4; bval += (float).67) {
		buse = dmin(bval,(float)1.);
#endif /* NO_PROTO */
		++ix;
		possc[ix * 3 - 3] = ruse;
		possc[ix * 3 - 2] = guse;
		possc[ix * 3 - 1] = buse;
/* L120: */
	    }
/* L110: */
	}
/* L100: */
    }
/*  get realized background color */
    nqcr (wkid, &c__0, &c__3, &c__1, &errind, &ncc, rlzcol);
    chkinq_("pqcr", &errind, 4L);
/*  szcolt = maximum size of color table (including entry #0) */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &szcolt, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  maxsiz = maximum size to try to fill */
/* Computing MIN */
    i__1 = *maxreq, i__2 = szcolt - 1;
    maxsiz = min(i__1,i__2);
/*  get permutation of 27 colors */
    rnperm_(&c__27, perm);
/*  how many distinct so far */
    *ndisct = 0;
#ifndef NO_PROTO
    bestd = -666.f;
#else /* NO_PROTO */
    bestd = (float)-666.;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 27; ++ix) {
	nxtcol = *ndisct + 1;
	thiscl = perm[ix - 1];
/*  try next possibility from 27 */
	nscr (wkid, &nxtcol, &c__3, &possc[thiscl * 3 - 3]);
/*  get color as realized */
	nqcr (wkid, &nxtcol, &c__3, &c__1, &errind, &ncc, &rlzcol[nxtcol * 3])
		;
	chkinq_("pqcr", &errind, 4L);
/*  if realized color different from others and from 0 - got a new one
, */
/*  else re-try same slot */
	for (icol = *ndisct; icol >= 0; --icol) {
/*  inter-color distance squared */
/* Computing 2nd power */
	    r__1 = rlzcol[nxtcol * 3] - rlzcol[icol * 3];
/* Computing 2nd power */
	    r__2 = rlzcol[nxtcol * 3 + 1] - rlzcol[icol * 3 + 1];
/* Computing 2nd power */
	    r__3 = rlzcol[nxtcol * 3 + 2] - rlzcol[icol * 3 + 2];
	    cdist = r__1 * r__1 + r__2 * r__2 + r__3 * r__3;
/*  minimum closeness is .3**2 */
#ifndef NO_PROTO
	    if (cdist < .09f) {
#else /* NO_PROTO */
	    if (cdist < (float).09) {
#endif /* NO_PROTO */
/*  too close - skip it */
		goto L200;
	    }
/* L300: */
	}
/*  OK - use it */
	++(*ndisct);
	chosen[*ndisct - 1] = thiscl;
/*  save color farthest from color #0 */
	if (cdist > bestd) {
	    bestd = cdist;
	    bestc = *ndisct;
	}
	if (*ndisct >= maxsiz) {
	    goto L210;
	}
L200:
	;
    }
L210:
/*  switch color farthest from #0 into slot #1 */
    nscr (wkid, &c__1, &c__3, &possc[chosen[bestc - 1] * 3 - 3]);
    nscr (wkid, &bestc, &c__3, &possc[chosen[0] * 3 - 3]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* discol_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04/xfinh                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int xfinh_(integer *perm)
#else /* NO_PROTO */
/* Subroutine */ int xfinh_(perm)
integer *perm;
#endif /* NO_PROTO */
{
    static real u, z;
#ifndef NO_PROTO
    extern /* Subroutine */ int nbltm (real *, real *, real *, real *, real *,
	     real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nbltm ();
#endif /* NO_PROTO */
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static real scaley;
    static integer errind;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real shifty;

/*  More special-purpose code here for testing inheritance. */
/*  Since structure 104 is re-invoked, it generates polyline #5,6 on */
/*  first invocation, and 11,12 on 2nd.  But 11,12 would simply */
/*  overlay 5,6, so we must also pass down a transformation which */
/*  maps locations 5,6 to locations 11,12, respectively. */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    /* Parameter adjustments */
    --perm;

    /* Function Body */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    fxpty = ylocel_(&perm[5]);
    shifty = ylocel_(&perm[11]) - ylocel_(&perm[5]);
    scaley = (ylocel_(&perm[12]) - ylocel_(&perm[11])) / (ylocel_(&perm[6]) - 
	    ylocel_(&perm[5]));
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &scaley, &errind, xform);
    chkinq_("pbltm", &errind, 5L);
    nslmt (xform, &c__2);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* xfinh_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04/locppl                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int locppl_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locppl_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static real yval[2];
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCPPL draws a polyline at the real y-location corresponding to */
/*  the integer index given in YLOC. */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    yval[0] = ylocel_(yloc);
    yval[1] = yval[0];
    npl (&c__2, &xval[1], yval);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locppl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04/loctxt                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int loctxt_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int loctxt_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCTXT draws a text primitive at the real y-location */
/*  corresponding to the integer index given in YLOC. */
    r__1 = ylocel_(yloc);
    ntx (xval, &r__1, "Hi ho!", 6L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* loctxt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04/locatx                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int locatx_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locatx_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCATX draws an annotation text primitive at the real y-location */
/*  corresponding to the integer index given in YLOC. */
    r__1 = ylocel_(yloc);
    natr (xval, &r__1, &c_b32, &c_b32, "Hi ho!", 6L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locatx_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04/locint                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int locint_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locint_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), nfas (
	    integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), nfas ();
#endif /* NO_PROTO */
    static real ymid, yval[4];
    static integer npts[1];
    static real yhalf;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCINT draws a fill area or fill area set at the real y-location */
/*  corresponding to the integer index given in YLOC.  It may be used */
/*  to check interiors. */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    npts[0] = 4;
    ymid = ylocel_(yloc);
#ifndef NO_PROTO
    yhalf = .02f;
#else /* NO_PROTO */
    yhalf = (float).02;
#endif /* NO_PROTO */
    yval[0] = ymid + yhalf;
    yval[1] = ymid - yhalf;
    yval[2] = ymid - yhalf;
    yval[3] = ymid + yhalf;
    if (*yloc % 2 == 0) {
	nfa (&c__4, &xval[1], yval);
    } else {
	nfas (&c__1, npts, &xval[1], yval);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locint_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04/loctri                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int loctri_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int loctri_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static real yval[3];
    static integer npts[1];
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCTRI draws a triangle using fill area set at the real */
/*  y-location corresponding to the integer index given in YLOC. */
/*  LOCTRI is normally used to display edges (unique to fill area */
/*  set, as opposed to simple fill area) rather than interiors. */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    npts[0] = 3;
#ifndef NO_PROTO
    yval[1] = ylocel_(yloc) - .02f;
#else /* NO_PROTO */
    yval[1] = ylocel_(yloc) - (float).02;
#endif /* NO_PROTO */
    yval[2] = yval[1];
#ifndef NO_PROTO
    yval[0] = yval[1] + .035f;
#else /* NO_PROTO */
    yval[0] = yval[1] + (float).035;
#endif /* NO_PROTO */
    nfas (&c__1, npts, &xval[1], yval);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* loctri_ */

