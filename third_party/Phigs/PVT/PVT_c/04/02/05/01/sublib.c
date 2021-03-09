/* fort/04/02/05/01/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b6 = 0.f;
#else /* NO_PROTO */
static real c_b6 = (float)0.;
#endif /* NO_PROTO */
static integer c__5 = 5;
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b11 = .05f;
#else /* NO_PROTO */
static real c_b11 = (float).05;
#endif /* NO_PROTO */
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.05.01/showew                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int showew_(char *hding, real *reqew, real *expew, real *
	nomew, real *minlw, char *pfsw, ftnlen hding_len, ftnlen pfsw_len)
#else /* NO_PROTO */
/* Subroutine */ int showew_(hding, reqew, expew, nomew, minlw, pfsw, 
	hding_len, pfsw_len)
char *hding;
real *reqew, *expew, *nomew, *minlw;
char *pfsw;
ftnlen hding_len;
ftnlen pfsw_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real xa[5], ya[5], za[5];
    static integer ix;
    static real alt[10];
    static integer ans;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx ();
#endif /* NO_PROTO */
    static real xgap;
    static integer perm[20];
    static real xloc, xlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nsln ();
#endif /* NO_PROTO */
    static integer npts[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 ();
#endif /* NO_PROTO */
    static char digit[1];
    static real ybase;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh ();
#endif /* NO_PROTO */
    static real xmarg, fsize, xincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchoic_(char *, integer *, integer *, integer 
	    *, ftnlen), ndellb (integer *, integer *), opcofl_(void), nsplci (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchoic_(), ndellb (), opcofl_(), nsplci ();
#endif /* NO_PROTO */
    static integer numalt;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *), nsewsc (real *)
	    , altsiz_(real *, real *, real *, integer *, integer *, real *), 
	    nslwsc (real *), nstxal (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_(), nsewsc (), altsiz_(), nslwsc (), 
	    nstxal ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___17 = { 0, digit, 0, "(I1)", 1, 1 };


/*  SHOWEW tests the rendering of a given edgewidth, and returns the */
/*  pass/fail result, or an abort signal if the requested edge is */
/*  too wide to be tested. */

/*  Input parameters: */
/*    HDING : Title for this test */
/*    REQEW : The edgewidth (in DC) to be requested. */
/*    EXPEW : The expected edgewidth (in DC) - the one which should */
/*            be realized in order to pass. */
/*    NOMEW : The nominal edgewidth */
/*    MINLW : The minimum linewidth (used for simulation) */
/*  Output parameters: */
/*    PFSW  : Result of the test - P:pass, F:fail, A:abort. */
/* edge-, line-type */
/* edge flag indicator */
/* text alignment horizontal */
/* text alignment vertical */
#ifndef NO_PROTO
    ybase = .2f;
#else /* NO_PROTO */
    ybase = (float).2;
#endif /* NO_PROTO */
/*  can we fit in top of picture area? - if not, quit */
    if (*expew * dialog_1.wcpdc > 1 - ybase) {
	*pfsw = 'A';
	return 0;
    }
/*  get list of alternate sizes */
#ifndef NO_PROTO
    r__1 = (1.f - ybase) / dialog_1.wcpdc;
#else /* NO_PROTO */
    r__1 = ((float)1. - ybase) / dialog_1.wcpdc;
#endif /* NO_PROTO */
    altsiz_(expew, &dialog_1.qvis, &r__1, &c__4, &numalt, alt);
    rnperm_(&numalt, perm);
/*  draw actual and simulated edges of various widths */
/*  first simulated */
    nsln (&c__1);
    nsplci (&c__1);
    nslwsc (&c_b6);
#ifndef NO_PROTO
    xincr = 1.f / numalt;
    xloc = 0.f;
#else /* NO_PROTO */
    xincr = (float)1. / numalt;
    xloc = (float)0.;
#endif /* NO_PROTO */
    xgap = xincr / 25;
    xmarg = xgap * 3;
    xlen = (xincr - xgap - xmarg * 2) / 2;
    ya[1] = ybase + *minlw * dialog_1.wcpdc / 2;
    ya[2] = ya[1];
    i__1 = numalt;
    for (ix = 1; ix <= i__1; ++ix) {
/*  size of linewidth to be simulated - allow for thickness */
/*  of simulating edge by subtracting minimum edgewidth. */
	fsize = (alt[perm[ix - 1] - 1] - *minlw) * dialog_1.wcpdc;
	ya[0] = ya[1] + fsize;
	ya[3] = ya[0];
	ya[4] = ya[0];
	xa[0] = xloc + xmarg;
	xa[1] = xa[0];
	xa[4] = xa[0];
	xa[2] = xa[0] + xlen;
	xa[3] = xa[2];
	npl (&c__5, xa, ya);
	xloc += xincr;
/* L500: */
    }
/*  now actual */
    r__1 = *reqew / *nomew;
    nsewsc (&r__1);
    nstxal (&c__2, &c__3);
    nschh (&c_b11);
#ifndef NO_PROTO
    xloc = 0.f;
    za[0] = .5f;
    za[1] = .9f;
#else /* NO_PROTO */
    xloc = (float)0.;
    za[0] = (float).5;
    za[1] = (float).9;
#endif /* NO_PROTO */
    za[2] = za[1];
    za[3] = za[0];
    ya[0] = ybase + *expew * dialog_1.wcpdc / 2;
    ya[1] = ya[0];
    ya[2] = ya[0];
    ya[3] = ya[0];
    npts[0] = 4;
    i__1 = numalt;
    for (ix = 1; ix <= i__1; ++ix) {
/*  offset 2nd and 4th point slightly so that Z-oriented edges (1-2 an
d */
/*  3-4) project to a short horizontal line, rather than to a point. 
*/
	xa[0] = xloc + xmarg + xgap + xlen;
	xa[1] = xa[0] + xlen / 100;
	xa[2] = xa[0] + xlen;
	xa[3] = xa[2] - xlen / 100;
	nfas3 (&c__1, npts, xa, ya, za);
	s_wsfi(&io___17);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	e_wsfi();
	r__1 = xloc + xincr / 2;
#ifndef NO_PROTO
	r__2 = ybase - .05f;
#else /* NO_PROTO */
	r__2 = ybase - (float).05;
#endif /* NO_PROTO */
	ntx (&r__1, &r__2, digit, 1L);
	xloc += xincr;
/* L600: */
    }
/* Writing concatenation */
    i__2[0] = hding_len, a__1[0] = hding;
    i__2[1] = 45, a__1[1] = ": Which pair has the same vertical thickness?";
    s_cat(msg, a__1, i__2, &c__2, 300L);
    dchoic_(msg, &c__0, &numalt, &ans, 300L);
    if (ans == 0) {
	opcofl_();
	*pfsw = 'F';
    } else if (perm[ans - 1] == 1) {
	*pfsw = 'P';
    } else {
	*pfsw = 'F';
    }
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* showew_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.05.01/parpt                       * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int parpt_(real *rcx, real *rcy, integer *parity, real *
	prvc1x, real *prvc1y, real *prvc2x, real *prvc2y, real *xa, real *ya, 
	real *x, real *y, integer *step1, integer *step2)
#else /* NO_PROTO */
/* Subroutine */ int parpt_(rcx, rcy, parity, prvc1x, prvc1y, prvc2x, prvc2y, 
	xa, ya, x, y, step1, step2)
real *rcx, *rcy;
integer *parity;
real *prvc1x, *prvc1y, *prvc2x, *prvc2y, *xa, *ya, *x, *y;
integer *step1, *step2;
#endif /* NO_PROTO */
{
    static real a1, b1, c1, a2, b2, c2;
#ifndef NO_PROTO
    extern /* Subroutine */ int parlin_(real *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    integer *), lintpt_(real *, real *, real *, real *, real *, real *
	    , real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int parlin_(), lintpt_();
#endif /* NO_PROTO */

/*  PARPT accepts a reference point and 2 vectors and computes a */
/*  corner of the smallest parallelogram containing a specified */
/*  rectangle. The corner is found in the direction specified by */
/*  parity. */
/*  Input parameters */
/*    RCX,RCY       : reference point within rectangle */
/*    PARITY        : +1 to search in direction of vectors, -1 to */
/*                    search in opposite direction */
/*    PRVC1X,PRVC1Y : first vector to increment reference point */
/*    PRVC2X,PRVC2Y : second vector to increment reference point */
/*    XA,YA         : 4 corners of rectangle to be contained */
/*  Output parameters */
/*    X,Y           : corner of parallelogram */
/*    STEP1,STEP2   : number of steps taken from reference point in */
/*                    direction of 1st,2nd vector */
/*  find first, second boundary lines */
    /* Parameter adjustments */
    --ya;
    --xa;

    /* Function Body */
    parlin_(rcx, rcy, parity, prvc1x, prvc1y, prvc2x, prvc2y, &xa[1], &ya[1], 
	    &a1, &b1, &c1, step1);
    parlin_(rcx, rcy, parity, prvc2x, prvc2y, prvc1x, prvc1y, &xa[1], &ya[1], 
	    &a2, &b2, &c2, step2);
/*  intersection of lines is corner */
    lintpt_(&a1, &b1, &c1, &a2, &b2, &c2, x, y);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* parpt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.05.01/parlin                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int parlin_(real *rcx, real *rcy, integer *parity, real *
	prvc1x, real *prvc1y, real *prvc2x, real *prvc2y, real *xa, real *ya, 
	real *a, real *b, real *c, integer *step)
#else /* NO_PROTO */
/* Subroutine */ int parlin_(rcx, rcy, parity, prvc1x, prvc1y, prvc2x, prvc2y,
	 xa, ya, a, b, c, step)
real *rcx, *rcy;
integer *parity;
real *prvc1x, *prvc1y, *prvc2x, *prvc2y, *xa, *ya, *a, *b, *c;
integer *step;
#endif /* NO_PROTO */
{
    static integer ix;
    static real chk, curx, cury;
#ifndef NO_PROTO
    extern /* Subroutine */ int parcof_(real *, real *, real *, real *, real *
	    , real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int parcof_();
#endif /* NO_PROTO */

/*  PARLIN accepts a reference point and 2 vectors and computes a */
/*  side of the smallest parallelogram containing a specified */
/*  rectangle.  The side is found in the direction specified by */
/*  parity. */
/*  Input parameters */
/*    RCX,RCY       : reference point within rectangle */
/*    PARITY        : +1 to search in direction of 1st vector, -1 to */
/*                    search in opposite direction */
/*   PRVC1X,PRVC1Y : first vector: used to increment/decrement reference p
oint*/
/*    PRVC2X,PRVC2Y : second vector: indicate direction (slope) of side */

/*    XA,YA         : 4 corners of rectangle to be contained */
/*  Output parameters */
/*    A,B,C         : coefficients of side */
/*    STEP          : number of steps taken from reference point */
    /* Parameter adjustments */
    --ya;
    --xa;

    /* Function Body */
    curx = *rcx;
    cury = *rcy;
    *step = 0;
L100:
    ++(*step);
    curx += *parity * *prvc1x;
    cury += *parity * *prvc1y;
/*  candidate line coefficients */
    parcof_(&curx, &cury, prvc2x, prvc2y, a, b, c);
    chk = *a * xa[1] + *b * ya[1] + *c;
/*  check if all on same side */
    for (ix = 2; ix <= 4; ++ix) {
/*  if not on same side, go back and take another step */
#ifndef NO_PROTO
	if (chk * (*a * xa[ix] + *b * ya[ix] + *c) <= 0.f) {
#else /* NO_PROTO */
	if (chk * (*a * xa[ix] + *b * ya[ix] + *c) <= (float)0.) {
#endif /* NO_PROTO */
	    goto L100;
	}
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* parlin_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.05.01/cldiag                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int cldiag_(real *x1, real *y1, real *x2, real *y2, real *a, 
	real *b, real *c, real *d, real *xl, real *yl, real *xf)
#else /* NO_PROTO */
/* Subroutine */ int cldiag_(x1, y1, x2, y2, a, b, c, d, xl, yl, xf)
real *x1, *y1, *x2, *y2, *a, *b, *c, *d, *xl, *yl, *xf;
#endif /* NO_PROTO */
{
    static real xa[2], ya[2], za[2], zt, xw1, yw1, xw2, yw2, xhi, yhi, xlo, 
	    ylo;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), npl3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), npl3 ();
#endif /* NO_PROTO */
    static real shrink;

/*  CLDIAG accepts the x-y coordinates of 2 MC points, the */
/*  coefficients of a fill area plane, and a transformation from MC */
/*  to WC, and draws the resulting (slightly shrunken) 3D line segment. */


/*  Input parameters: */
/*    X1,Y1, X2,Y2 : MC coordinates of 1st,2nd point */
/*    A,B,C,D      : fill area plane is: a*x + b*y + c*z + d = 0 */
/*    XL,YL        : border of fill area in MC - an aligned rectanlge */
/*    XF           : transformation from MC to WC */
    /* Parameter adjustments */
    xf -= 5;
    --yl;
    --xl;

    /* Function Body */
    xlo = xl[1];
    xhi = xl[3];
    ylo = yl[3];
    yhi = yl[1];
#ifndef NO_PROTO
    shrink = .8f;
#else /* NO_PROTO */
    shrink = (float).8;
#endif /* NO_PROTO */
    xw1 = shrink * *x1 + (1 - shrink) * *x2;
    xw2 = shrink * *x2 + (1 - shrink) * *x1;
    yw1 = shrink * *y1 + (1 - shrink) * *y2;
    yw2 = shrink * *y2 + (1 - shrink) * *y1;
    if (xw1 < xlo || xw1 > xhi || yw1 < ylo || yw1 > yhi || (xw2 < xlo || xw2 
	    > xhi || yw2 < ylo || yw2 > yhi)) {
	return 0;
    }
    zt = -(doublereal)(*a * xw1 + *b * yw1 + *d) / *c;
    etp3_(&xw1, &yw1, &zt, &xf[5], xa, ya, za);
    zt = -(doublereal)(*a * xw2 + *b * yw2 + *d) / *c;
    etp3_(&xw2, &yw2, &zt, &xf[5], &xa[1], &ya[1], &za[1]);
/*  since simulated projection is flat, put in z=0.999 plane */
#ifndef NO_PROTO
    za[0] = .999f;
    za[1] = .999f;
#else /* NO_PROTO */
    za[0] = (float).999;
    za[1] = (float).999;
#endif /* NO_PROTO */
    npl3 (&c__2, xa, ya, za);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* cldiag_ */

