/* fort/04/03/02/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw, 
	    errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[
	    20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__1 = 1;
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__100 = 100;
static integer c__3 = 3;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b23 = .15f;
static real c_b40 = .2f;
static real c_b41 = .5f;
static real c_b53 = .55f;
static real c_b54 = .95f;
#else /* NO_PROTO */
static real c_b23 = (float).15;
static real c_b40 = (float).2;
static real c_b41 = (float).5;
static real c_b53 = (float).55;
static real c_b54 = (float).95;
#endif /* NO_PROTO */
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b78 = 0.f;
static real c_b79 = 1.f;
static real c_b87 = .02f;
static real c_b94 = .1f;
#else /* NO_PROTO */
static real c_b78 = (float)0.;
static real c_b79 = (float)1.;
static real c_b87 = (float).02;
static real c_b94 = (float).1;
#endif /* NO_PROTO */
static integer c__7 = 7;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b123 = .01f;
static real c_b129 = .05f;
static real c_b133 = .25f;
static real c_b134 = .75f;
#else /* NO_PROTO */
static real c_b123 = (float).01;
static real c_b129 = (float).05;
static real c_b133 = (float).25;
static real c_b134 = (float).75;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.02.02/hueang                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int hueang_(real *r, real *g, real *b, real *ang, real *dist)

#else /* NO_PROTO */
/* Subroutine */ int hueang_(r, g, b, ang, dist)
real *r, *g, *b, *ang, *dist;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal), atan(doublereal), atan2(doublereal, doublereal);
#else /* NO_PROTO */
    double sqrt(), atan(), atan2();
#endif /* NO_PROTO */

    /* Local variables */
    static real u, a45, pi, xo, yo, zo, zz;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_();
#endif /* NO_PROTO */
    static real tmat[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm3_();
#endif /* NO_PROTO */

/*  This program calculates a characteristic angle for a hue from the */
/*  RGB color cube.  It does so by rotating the cube 45 deg around the */
/*  y-axis and atan(sqrt(2)) around the z-axis (assuming xyz = RGB). */
/*  This lines up the black-white cube diagonal (0,0,0 to 1,1,1) along */
/*  the y-axis.  Now, transformed points along the color-saturated */
/*  vertices are such that their angle in the x-z plane is a measure */
/*  of hue; so atan2 is used to compute the hue of any RGB point. */
/*  BTW, somewhat surprisingly, the points which are transformed into */
/*  the x=0 plane are all those in the old plane described by: */
/*  x -2y + z = 0 (this plane contains the points (0,0,0), (1,1,1), */
/*  and (0,.5,1), all of which can be "seen" to be rotated into x=0 */
/*  plane).  This plane is such that it is satisfied by any points of */
/*  the form: (q, q+c, q+2c), so that sample points like (3,4,5) will */
/*  always transform into the x=0 plane. */
/*  Hueang also returns the distance of the RGB point from the */
/*  neutral (black-white) axis. */
#ifndef NO_PROTO
    zz = 0.f;
    u = 1.f;
    pi = 3.14159265f;
    a45 = pi / 4.f;
    r__1 = atan(sqrt(2.f));
#else /* NO_PROTO */
    zz = (float)0.;
    u = (float)1.;
    pi = (float)3.14159265;
    a45 = pi / (float)4.;
    r__1 = atan(sqrt((float)2.));
#endif /* NO_PROTO */
    ebltm3_(&zz, &zz, &zz, &zz, &zz, &zz, &zz, &a45, &r__1, &u, &u, &u, tmat);

/* L10: */
    etp3_(r, g, b, tmat, &xo, &yo, &zo);
    *dist = sqrt(xo * xo + zo * zo);
    if (*dist == zz) {
#ifndef NO_PROTO
	*ang = -666.f;
#else /* NO_PROTO */
	*ang = (float)-666.;
#endif /* NO_PROTO */
    } else {
/*  Normalize to 0..1 */
	*ang = atan2(xo, zo) / (pi * 2);
#ifndef NO_PROTO
	if (*ang < 0.f) {
#else /* NO_PROTO */
	if (*ang < (float)0.) {
#endif /* NO_PROTO */
	    *ang += 1;
	}
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* hueang_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION 04.03.02.02/modsep                   * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal modsep_(real *period, real *a, real *b)
#else /* NO_PROTO */
doublereal modsep_(period, a, b)
real *period, *a, *b;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val, r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    double r_mod(real *, real *);
#else /* NO_PROTO */
    double r_mod();
#endif /* NO_PROTO */

    /* Local variables */
    static real am, bm, abdif;

/*  Given a period and two values, a and b, modsep calculates the */
/*  absolute value of the smallest "distance" between the values, */
/*  treating them as points on a circle with circumference of size = */
/*  period.  For example, if period=360, as for degree-measure, */
/*  modsep of 5 and 15 would of course be 10, but so would modsep of */
/*  5 and 355, or 0 and 710, or 0 and 730. */
#ifndef NO_PROTO
    if (*period == 0.f) {
	ret_val = 0.f;
#else /* NO_PROTO */
    if (*period == (float)0.) {
	ret_val = (float)0.;
#endif /* NO_PROTO */
	return ret_val;
    }
/* get normalized mod-values - correct for loopy way Fortran */
/* mods negative numbers. */
    am = r_mod(a, period);
#ifndef NO_PROTO
    if (*a < 0.f) {
#else /* NO_PROTO */
    if (*a < (float)0.) {
#endif /* NO_PROTO */
	am += *period;
    }
    bm = r_mod(b, period);
#ifndef NO_PROTO
    if (*b < 0.f) {
#else /* NO_PROTO */
    if (*b < (float)0.) {
#endif /* NO_PROTO */
	bm += *period;
    }
/* now:   0 .le. am,bm  .lt. period */
    abdif = (r__1 = am - bm, dabs(r__1));
/* Computing MIN */
    r__1 = abdif, r__2 = *period - abdif;
    ret_val = dmin(r__1,r__2);
    return ret_val;
} /* modsep_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 04.03.02.02/undcmd                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical undcmd_(integer *nummod, integer *modlis, integer *hicol, char *
	prompt, ftnlen prompt_len)
#else /* NO_PROTO */
logical undcmd_(nummod, modlis, hicol, prompt, prompt_len)
integer *nummod, *modlis, *hicol;
char *prompt;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3], a__2[2];
    integer i__1, i__2[3], i__3, i__4[2], i__5;
    real r__1;
    logical ret_val;
    char ch__1[80], ch__2[78], ch__3[34];
    icilist ici__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer cm;
    static real hi[8];
    static integer ii;
    static real lo[8];
    static integer ix, icm;
    static char msg[200];
    static real yhi;
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
#else /* NO_PROTO */
    extern logical dyn_();
#endif /* NO_PROTO */
    static real ylo;
    static integer pos1;
    static char cval[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr ();
#endif /* NO_PROTO */
    static real ytop;
    static integer cmdim;
    static logical lomag;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *), inmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd (), inmsg_();
#endif /* NO_PROTO */
    static integer numcm, colix, numcl;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static char rvals[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), rnset_(integer *, integer *
	    , integer *), dchoic_(char *, integer *, integer *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), rnset_(), dchoic_();
#endif /* NO_PROTO */
    static real actcol[8];
#ifndef NO_PROTO
    extern /* Subroutine */ int colpch_(logical *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int colpch_();
#endif /* NO_PROTO */
    static logical filmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int numlab_(integer *, real *, real *, real *), 
	    chkinq_(char *, integer *, ftnlen), vislab_(char *, char *, real *
	    , real *, real *, real *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int numlab_(), chkinq_(), vislab_();
#endif /* NO_PROTO */
    static integer errind, ranlis[8];
    static real colary[8];
#ifndef NO_PROTO
    extern /* Subroutine */ int drlval_(char *, real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int drlval_();
#endif /* NO_PROTO */
    static integer numtst;
#ifndef NO_PROTO
    extern logical intsty_(integer *, integer *);
#else /* NO_PROTO */
    extern logical intsty_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___18 = { 0, cval, 0, "(I5)", 5, 1 };
    static icilist io___22 = { 0, cval, 0, "(I5)", 5, 1 };
    static icilist io___36 = { 0, msg, 0, "(A,I5,A,I5,A,I5,A)", 200, 1 };
    static icilist io___40 = { 0, msg, 0, "(A,I5,A,A,A)", 200, 1 };
    static icilist io___41 = { 0, cval, 0, "(I5)", 5, 1 };


/*  UNDCMD tests the list of color models passed in by requesting */
/*  dimensions and drawing color patches using those dimensions. */
/*  The operator is asked if the displayed color matches the */
/*  randomly chosen color coordinates. */
/*  Input parameters: */
/*    NUMMOD :  Size of list of color models */
/*    MODLIS :  Entire list of color models which may be tested */
/*    HICOL  :  Highest color index to be used */
/*    PROMPT :  String for prompt, indicating documentation to */
/*              be used for reference */
/*  interior style */
/*     type of returned values set, realized */
/*  Determine how to fill in rectangles, use solid style */
/*  if it is available, otherwise use dense polyline cross-hatch */
    /* Parameter adjustments */
    --modlis;

    /* Function Body */
    filmod = intsty_(&dialog_1.specwt, &c__1);
/*  number of models to test */
    numtst = min(8,*nummod);
/*  Test a random subset of the models if > 8 */
    rnset_(&numtst, nummod, ranlis);
    i__1 = numtst;
    for (icm = 1; icm <= i__1; ++icm) {
	nemst (&c__102);
/*  Set Color Model */
	cm = modlis[ranlis[icm - 1]];
	nscmd (&globnu_1.wkid, &cm);
	s_wsfi(&io___18);
	do_fio(&c__1, (char *)&cm, (ftnlen)sizeof(integer));
	e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
	i__2[0] = 74, a__1[0] = "DIMENSION OF COLOUR MODEL: How many dimensi"
		"ons are there for colour model ";
#else /* NO_PROTO */
	i__2[0] = 74, a__1[0] = "DIMENSION OF COLOUR MODEL: How many dimensi\
ons are there for colour model ";
#endif /* NO_PROTO */
	i__2[1] = 5, a__1[1] = cval;
	i__2[2] = 1, a__1[2] = "?";
	s_cat(ch__1, a__1, i__2, &c__3, 80L);
	dchoic_(ch__1, &c__0, &c__100, &cmdim, 80L);
	if (cmdim == 0) {
	    inmsg_("Operator reported zero dimensions for a color model.", 
		    52L);
	    ret_val = FALSE_;
	    return ret_val;
	}
/*  determine format for displaying color coordinates */
	lomag = TRUE_;
	i__3 = cmdim;
	for (ix = 1; ix <= i__3; ++ix) {
	    s_wsfi(&io___22);
	    do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	    e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
	    i__4[0] = 73, a__2[0] = "DIMENSION BOUNDS: Enter the LOWER limit"
		    " for valid values for dimension # ";
#else /* NO_PROTO */
	    i__4[0] = 73, a__2[0] = "DIMENSION BOUNDS: Enter the LOWER limit\
 for valid values for dimension # ";
#endif /* NO_PROTO */
	    i__4[1] = 5, a__2[1] = cval;
	    s_cat(ch__2, a__2, i__4, &c__2, 78L);
	    drlval_(ch__2, &lo[ix - 1], 78L);
/* Writing concatenation */
#ifndef NO_PROTO
	    i__4[0] = 73, a__2[0] = "DIMENSION BOUNDS: Enter the UPPER limit"
		    " for valid values for dimension # ";
#else /* NO_PROTO */
	    i__4[0] = 73, a__2[0] = "DIMENSION BOUNDS: Enter the UPPER limit\
 for valid values for dimension # ";
#endif /* NO_PROTO */
	    i__4[1] = 5, a__2[1] = cval;
	    s_cat(ch__2, a__2, i__4, &c__2, 78L);
	    drlval_(ch__2, &hi[ix - 1], 78L);
#ifndef NO_PROTO
	    if ((r__1 = lo[ix - 1], dabs(r__1)) >= 10.f) {
#else /* NO_PROTO */
	    if ((r__1 = lo[ix - 1], dabs(r__1)) >= (float)10.) {
#endif /* NO_PROTO */
		lomag = FALSE_;
	    }
#ifndef NO_PROTO
	    if ((r__1 = hi[ix - 1], dabs(r__1)) >= 10.f) {
#else /* NO_PROTO */
	    if ((r__1 = hi[ix - 1], dabs(r__1)) >= (float)10.) {
#endif /* NO_PROTO */
		lomag = FALSE_;
	    }
/* L100: */
	}
/*  Draw color patches down left side of screen: */
	numcm = *hicol - 1;
#ifndef NO_PROTO
	yincr = 1.f / (numcm + 1.f);
#else /* NO_PROTO */
	yincr = (float)1. / (numcm + (float)1.);
#endif /* NO_PROTO */
	ytop = 1 - yincr;
#ifndef NO_PROTO
	ylo = ytop - yincr * .25f;
	yhi = ytop + yincr * .25f;
#else /* NO_PROTO */
	ylo = ytop - yincr * (float).25;
	yhi = ytop + yincr * (float).25;
#endif /* NO_PROTO */
	numlab_(&numcm, &c_b23, &ytop, &yincr);
	i__3 = *hicol;
	for (colix = 2; colix <= i__3; ++colix) {
	    i__5 = cmdim;
	    for (ix = 1; ix <= i__5; ++ix) {
		colary[ix - 1] = rndrl_(&lo[ix - 1], &hi[ix - 1]);
/* L110: */
	    }
	    nscr (&globnu_1.wkid, &colix, &cmdim, colary);
/*  determine actual colval */
	    nqcr (&globnu_1.wkid, &colix, &cmdim, &c__1, &errind, &numcl, 
		    actcol);
	    chkinq_("pqcr", &errind, 4L);
	    if (numcl != cmdim) {
		s_wsfi(&io___36);
		do_fio(&c__1, "Reported dimensionality for color model #", 
			41L);
		do_fio(&c__1, (char *)&cm, (ftnlen)sizeof(integer));
		do_fio(&c__1, " is ", 4L);
		do_fio(&c__1, (char *)&numcl, (ftnlen)sizeof(integer));
#ifndef NO_PROTO
		do_fio(&c__1, "; does not match value specified by operator "
			"= ", 47L);
#else /* NO_PROTO */
		do_fio(&c__1, "; does not match value specified by operator \
= ", 47L);
#endif /* NO_PROTO */
		do_fio(&c__1, (char *)&cmdim, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 200L);
		ret_val = FALSE_;
		return ret_val;
	    }
	    colpch_(&filmod, &colix, &c_b40, &ylo, &c_b41, &yhi);
/*  format color coordinates for printing */
	    s_copy(rvals, " ", 80L, 1L);
	    i__5 = numcl;
	    for (ii = 1; ii <= i__5; ++ii) {
		if (lomag) {
		    pos1 = ii * 6 - 5;
		    ici__1.icierr = 0;
		    ici__1.icirnum = 1;
		    ici__1.icirlen = 6;
		    ici__1.iciunit = rvals + (pos1 - 1);
		    ici__1.icifmt = "(A,F5.2)";
		    s_wsfi(&ici__1);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, (char *)&actcol[ii - 1], (ftnlen)sizeof(
			    real));
		    e_wsfi();
		} else {
		    pos1 = ii * 10 - 9;
		    ici__1.icierr = 0;
		    ici__1.icirnum = 1;
		    ici__1.icirlen = 10;
		    ici__1.iciunit = rvals + (pos1 - 1);
		    ici__1.icifmt = "(A,E9.2)";
		    s_wsfi(&ici__1);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, (char *)&actcol[ii - 1], (ftnlen)sizeof(
			    real));
		    e_wsfi();
		}
/* L120: */
	    }
	    vislab_(rvals + 1, "L", &c_b53, &c_b54, &ylo, &yhi, itrim_(rvals, 
		    80L) - 1, 1L);
	    ylo -= yincr;
	    yhi -= yincr;
/*  next random color within color model */
/* L130: */
	}
	s_wsfi(&io___40);
#ifndef NO_PROTO
	do_fio(&c__1, "ACCURACY OF COLOUR MODEL: Are the colours of the rect"
		"angles compatible with the corresponding colour coordinate v"
		"alues within colour model #", 140L);
#else /* NO_PROTO */
	do_fio(&c__1, "ACCURACY OF COLOUR MODEL: Are the colours of the rect\
angles compatible with the corresponding colour coordinate values within col\
our model #", 140L);
#endif /* NO_PROTO */
	do_fio(&c__1, (char *)&cm, (ftnlen)sizeof(integer));
	do_fio(&c__1, ", according to the ", 19L);
	do_fio(&c__1, prompt, prompt_len);
	do_fio(&c__1, "?", 1L);
	e_wsfi();
	if (dyn_(msg, 200L)) {
/*           OK so far */
	} else {
	    s_wsfi(&io___41);
	    do_fio(&c__1, (char *)&cm, (ftnlen)sizeof(integer));
	    e_wsfi();
/* Writing concatenation */
	    i__2[0] = 13, a__1[0] = "Color Model #";
	    i__2[1] = 5, a__1[1] = cval;
	    i__2[2] = 16, a__1[2] = " caused failure.";
	    s_cat(ch__3, a__1, i__2, &c__3, 34L);
	    inmsg_(ch__3, 34L);
	    ret_val = FALSE_;
	    return ret_val;
	}
/*  next color model */
/* L140: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* undcmd_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.02.02/colpch                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int colpch_(logical *filmod, integer *clor, real *xlo, real *
	ylo, real *xhi, real *yhi)
#else /* NO_PROTO */
/* Subroutine */ int colpch_(filmod, clor, xlo, ylo, xhi, yhi)
logical *filmod;
integer *clor;
real *xlo, *ylo, *xhi, *yhi;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), npl (integer 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), npl ();
#endif /* NO_PROTO */
    static real filx[4], fily[4], yinc, yval;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *), nsis (integer *), nsici (
	    integer *), nsplci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln (), nsis (), nsici (), nsplci ();
#endif /* NO_PROTO */

/*  COLPCH will generate a rectangular color patch with the specified */
/*  diagonal vertices.  It will use solid interior fill area or */
/*  polylines based on the specified filling mode. */
/*  Input parameters: */
/*    FILMOD          : use fill area if true, otherwise polyline */
/*    CLOR            : color index to use */
/*    XLO,YLO,XHI,YHI : extent of the rectangle */
/*  interior style hollow, solid,    pattern,  hatch,    empty */
/* linetype */
    filx[0] = *xlo;
    filx[1] = *xhi;
    filx[2] = *xhi;
    filx[3] = *xlo;
    if (*filmod) {
	fily[0] = *ylo;
	fily[1] = *ylo;
	fily[2] = *yhi;
	fily[3] = *yhi;
	nsis (&c__1);
	nsici (clor);
	nfa (&c__4, filx, fily);
    } else {
	nsln (&c__1);
	nsplci (clor);
/*  paint lines at the rate of about 400/screen */
#ifndef NO_PROTO
	yinc = .0025000000000000001f;
#else /* NO_PROTO */
	yinc = (float).0025000000000000001;
#endif /* NO_PROTO */
	r__1 = *yhi;
	r__2 = yinc;
	for (yval = *ylo; r__2 < 0 ? yval >= r__1 : yval <= r__1; yval += 
		r__2) {
	    fily[0] = yval;
	    fily[1] = yval;
	    npl (&c__2, filx, fily);
/* L100: */
	}
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* colpch_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.02.02/coltrn                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int coltrn_(integer *wkid, char *colabl, real *fromcc, 
	integer *frommd, real *tocc, integer *tomd, char *srs, ftnlen 
	colabl_len, ftnlen srs_len)
#else /* NO_PROTO */
/* Subroutine */ int coltrn_(wkid, colabl, fromcc, frommd, tocc, tomd, srs, 
	colabl_len, srs_len)
integer *wkid;
char *colabl;
real *fromcc;
integer *frommd;
real *tocc;
integer *tomd;
char *srs;
ftnlen colabl_len;
ftnlen srs_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char modnam[3*4] = "RGB" "CIE" "HSV" "HLS";
#else /* NO_PROTO */
    static char modnam[3*4+1] = "RGBCIEHSVHLS";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[7], a__2[6];
    integer i__1[7], i__2[6];
    logical L__1;
    char ch__1[66], ch__2[56], ch__3[92];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer do_fio(integer *, char *, ftnlen), e_wsfi(void);
#else /* NO_PROTO */
    integer s_wsfi();
    /* Subroutine */ int s_cat();
    integer do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, iy;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nqcr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *), nscr (
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nqcr (), nscr ();
#endif /* NO_PROTO */
    static real cspec[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *), inmsg_(char *, 
	    ftnlen);
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd (), inmsg_();
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static real actcol[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
    extern logical coleql_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
    extern logical coleql_();
#endif /* NO_PROTO */
    static integer errind;
    static real expcol[3];
    static integer passct;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer numret;

    /* Fortran I/O blocks */
    static icilist io___56 = { 0, msg, 0, "(A)", 300, 1 };


/*  COLTRN tests the ability to translate color from one model to */
/*  another and issues pass or fail as a result. */
/*  Input parameters: */
/*    WKID   : workstation identifier */
/*    COLABL : labels (names) of colors to be tested */
/*    FROMCC : color coordinates to translate from */
/*    FROMMD : color model to translate from */
/*    TOCC   : color coordinates to translate to (expected result) */
/*    TOMD   : color model to translate to */
/*    SRS    : SR identifiers for test case */
/* colour model */
/* type of returned value */
    /* Parameter adjustments */
    tocc -= 4;
    fromcc -= 4;
    colabl -= 8;

    /* Function Body */
    passct = 0;
    for (ix = 1; ix <= 9; ++ix) {
/* <set colour model> */
	nscmd (wkid, frommd);
/*  <set colour representation> index #1, entry #ix, change -1 to */
/*     random value between 0 and 1 */
	for (iy = 1; iy <= 3; ++iy) {
#ifndef NO_PROTO
	    if (fromcc[iy + ix * 3] == -1.f) {
#else /* NO_PROTO */
	    if (fromcc[iy + ix * 3] == (float)-1.) {
#endif /* NO_PROTO */
		cspec[iy - 1] = rndrl_(&c_b78, &c_b79);
	    } else {
		cspec[iy - 1] = fromcc[iy + ix * 3];
	    }
	    expcol[iy - 1] = tocc[iy + ix * 3];
/* L110: */
	}
	nscr (wkid, &c__1, &c__3, cspec);
	nqcr (wkid, &c__1, &c__3, &c__1, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
/*  attempt to convert only realizable colors */
	if (! coleql_(&c__3, actcol, cspec, &c_b87, &c_b78)) {
	    goto L100;
	}
/*  <re-set colour model> */
	nscmd (wkid, tomd);
/*  <inquire colour representation> as SET, to determine cspec */
	nqcr (wkid, &c__1, &c__3, &c__0, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
	if (numret == 3 && coleql_(&c__3, actcol, expcol, &c_b94, &c_b78)) {
/*  OK so far */
	    ++passct;
	} else {
	    passct = -666;
	    s_wsfi(&io___56);
/* Writing concatenation */
	    i__1[0] = 33, a__1[0] = "Fail to change colour model from ";
	    i__1[1] = 3, a__1[1] = modnam + (*frommd - 1) * 3;
	    i__1[2] = 4, a__1[2] = " to ";
	    i__1[3] = 3, a__1[3] = modnam + (*tomd - 1) * 3;
	    i__1[4] = 14, a__1[4] = " for colour = ";
	    i__1[5] = 8, a__1[5] = colabl + (ix << 3);
	    i__1[6] = 1, a__1[6] = ".";
	    s_cat(ch__1, a__1, i__1, &c__7, 66L);
	    do_fio(&c__1, ch__1, 66L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	}
L100:
	;
    }
    if (passct == 0) {
/* Writing concatenation */
	i__1[0] = 14, a__1[0] = "No realizable ";
	i__1[1] = 3, a__1[1] = modnam + (*frommd - 1) * 3;
	i__1[2] = 12, a__1[2] = " colors for ";
	i__1[3] = 3, a__1[3] = modnam + (*frommd - 1) * 3;
	i__1[4] = 4, a__1[4] = " to ";
	i__1[5] = 3, a__1[5] = modnam + (*tomd - 1) * 3;
	i__1[6] = 17, a__1[6] = " conversion test.";
	s_cat(ch__2, a__1, i__1, &c__7, 56L);
	inmsg_(ch__2, 56L);
    } else {
/* Writing concatenation */
	i__2[0] = 31, a__2[0] = "Changing the colour model from ";
	i__2[1] = 3, a__2[1] = modnam + (*frommd - 1) * 3;
	i__2[2] = 4, a__2[2] = " to ";
	i__2[3] = 3, a__2[3] = modnam + (*tomd - 1) * 3;
	i__2[4] = 38, a__2[4] = " should not affect the colours in the ";
	i__2[5] = 13, a__2[5] = "colour table.";
	s_cat(ch__3, a__2, i__2, &c__6, 92L);
	setmsg_(srs, ch__3, srs_len, 92L);
	L__1 = passct > 0;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* coltrn_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.02.02/sethue                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int sethue_(integer *wkid, integer *colmod, integer *maxfg, 
	integer *paltte, real *cc, integer *numset, integer *lscoli)
#else /* NO_PROTO */
/* Subroutine */ int sethue_(wkid, colmod, maxfg, paltte, cc, numset, lscoli)
integer *wkid, *colmod, *maxfg, *paltte;
real *cc;
integer *numset, *lscoli;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ix, iy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *), nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr (), nscmd ();
#endif /* NO_PROTO */
    static logical colok;
    static integer ccsiz, rncol[20], palix;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int rnset_();
#endif /* NO_PROTO */
    static real realcc[3], thiscc[3];
#ifndef NO_PROTO
    extern logical coleql_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical coleql_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, numdsp;

/*  SETHUE tries to set as many hues as possible in the color table */
/*  and reports back the order in which they were set and how many. */

/*  Input parameters */
/*    WKID   : workstation identifier */
/*    COLMOD : Color model to set up under */
/*    MAXFG  : Maximum number of available foreground entries in */
/*             color table, starting with #2 */
/*    PALTTE : Number of colors to be displayed if possible */
/*    CC     : Color coordinates to be set in color table */

/*  Output parameters */
/*    NUMSET : Number of entries successfully set */
/*    LSCOLI : List of which entries in CC (palette) were set */
/* type of returned value */
/* colour model */
    /* Parameter adjustments */
    --lscoli;
    cc -= 4;

    /* Function Body */
    nscmd (wkid, colmod);
/*  max number to be displayed */
    numdsp = min(*maxfg,*paltte);
    rnset_(&numdsp, paltte, rncol);
/*  how many set so far? */
    *numset = 0;
    i__1 = numdsp;
    for (ix = 1; ix <= i__1; ++ix) {
/*  which color in palette to try */
	palix = rncol[ix - 1];
	for (iy = 1; iy <= 3; ++iy) {
	    thiscc[iy - 1] = cc[iy + palix * 3];
/*  treat -1 as a "don't care" value */
#ifndef NO_PROTO
	    if (thiscc[iy - 1] == -1.f) {
#else /* NO_PROTO */
	    if (thiscc[iy - 1] == (float)-1.) {
#endif /* NO_PROTO */
		thiscc[iy - 1] = rndrl_(&c_b78, &c_b79);
	    }
/* L110: */
	}
	i__2 = *numset + 2;
	nscr (wkid, &i__2, &c__3, thiscc);
	i__2 = *numset + 2;
	nqcr (wkid, &i__2, &c__3, &c__1, &errind, &ccsiz, realcc);
	chkinq_("pqcr", &errind, 4L);
	if (ccsiz != 3) {
	    goto L100;
	}
/*  is realized hue close enough ?? */
	if (*colmod == 2) {
	    colok = coleql_(&c__2, realcc, thiscc, &c_b123, &c_b78) && 
		    coleql_(&c__1, &realcc[2], &thiscc[2], &c_b94, &c_b78);
	} else {
	    colok = coleql_(&c__3, realcc, thiscc, &c_b129, &c_b78);
	}
	if (colok) {
/*  add to list */
	    ++(*numset);
	    lscoli[*numset] = palix;
	} else {
/*           not set */
	}
L100:
	;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* sethue_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION 04.03.02.02/tsthue                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
integer tsthue_(char *prmpt, logical *filmod, integer *numset, integer *
	lscoli, ftnlen prmpt_len)
#else /* NO_PROTO */
integer tsthue_(prmpt, filmod, numset, lscoli, prmpt_len)
char *prmpt;
logical *filmod;
integer *numset, *lscoli;
ftnlen prmpt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val, i__1, i__2;
    real r__1;

    /* Local variables */
    static integer ix;
    static real yval, ytop, yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), colpch_(logical *, integer 
	    *, real *, real *, real *, real *);
    extern logical iareql_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int drwrec_(real *, real *, real *, real *), 
	    dilist_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), colpch_();
    extern logical iareql_();
    extern /* Subroutine */ int drwrec_(), dilist_();
#endif /* NO_PROTO */
    static integer anslis[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsplci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsplci ();
#endif /* NO_PROTO */
    static integer anssiz;

/*  TSTHUE displays NUMSET colors, starting with #2, using LSCOLI as */
/*  color indices.  It then asks the operator to identify these and */
/*  issues 1 (pass), -1 (fail), or -2 (fail with comment), as a result. */


/*  Input parameters: */
/*    PRMPT  : prompt for the operator */
/*    FILMOD : fill mode for rectangle; true for solid fill area, */
/*             false for polylines */
/*    NUMSET : number of colored rectangles to be drawn */
/*    LSCOLI : list of identifiers from color palette */
    /* Parameter adjustments */
    --lscoli;

    /* Function Body */
#ifndef NO_PROTO
    yincr = 1.f / (*numset + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (*numset + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
#ifndef NO_PROTO
    yval = ytop - yincr * .25f;
#else /* NO_PROTO */
    yval = ytop - yincr * (float).25;
#endif /* NO_PROTO */
    i__1 = *numset;
    for (ix = 1; ix <= i__1; ++ix) {
	i__2 = ix + 1;
#ifndef NO_PROTO
	r__1 = yval + yincr * .5f;
#else /* NO_PROTO */
	r__1 = yval + yincr * (float).5;
#endif /* NO_PROTO */
	colpch_(filmod, &i__2, &c_b133, &yval, &c_b134, &r__1);
	nsplci (&c__1);
#ifndef NO_PROTO
	r__1 = yval + yincr * .5f;
#else /* NO_PROTO */
	r__1 = yval + yincr * (float).5;
#endif /* NO_PROTO */
	drwrec_(&c_b133, &c_b134, &yval, &r__1);
	yval -= yincr;
/* L120: */
    }
    dilist_(prmpt, &anssiz, anslis, prmpt_len);
    if (anssiz == 1 && anslis[0] == 0) {
	ret_val = -2;
    } else if (iareql_(&anssiz, anslis, numset, &lscoli[1])) {
	ret_val = 1;
    } else {
	ret_val = -1;
    }
    nemst (&c__102);
    return ret_val;
} /* tsthue_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 04.03.02.02/coleql                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical coleql_(integer *size, real *act, real *exp__, real *abserr, real *
	relerr)
#else /* NO_PROTO */
logical coleql_(size, act, exp__, abserr, relerr)
integer *size;
real *act, *exp__, *abserr, *relerr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */

/*  Special purpose routine for testing approximate equality of */
/*  all three color components, unless one is -1. */
/*  Input parameters: */
/*    SIZE    : Number of elements to be compared */
/*    ACT     : actual values */
/*    EXP     : expected values */
/*    ABSERR  : absolute tolerance */
/*    RELERR  : relative tolerance */
    /* Parameter adjustments */
    --exp__;
    --act;

    /* Function Body */
    i__1 = *size;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	if (act[ix] == -1.f || exp__[ix] == -1.f) {
#else /* NO_PROTO */
	if (act[ix] == (float)-1. || exp__[ix] == (float)-1.) {
#endif /* NO_PROTO */
/* OK so far */
	} else if (appeq_(&act[ix], &exp__[ix], abserr, relerr)) {
/* OK so far */
	} else {
	    ret_val = FALSE_;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* coleql_ */

