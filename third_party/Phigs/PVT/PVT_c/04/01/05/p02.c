/* fort/04/01/05/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__801 = 801;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b5 = 0.f;
#else /* NO_PROTO */
static real c_b5 = (float)0.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__4 = 4;
static integer c__3 = 3;
static integer c__106 = 106;
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b22 = .2f;
static real c_b23 = .8f;
static real c_b27 = 1.f;
static real c_b48 = 1.5707963250000001f;
static real c_b49 = 2.5132741200000002f;
#else /* NO_PROTO */
static real c_b22 = (float).2;
static real c_b23 = (float).8;
static real c_b27 = (float)1.;
static real c_b48 = (float)1.5707963250000001;
static real c_b49 = (float)2.5132741200000002;
#endif /* NO_PROTO */
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b53 = 1.2566370600000001f;
static real c_b57 = -1.2566370600000001f;
static real c_b90 = .5f;
static real c_b92 = .4f;
static real c_b94 = 6.2831853000000004f;
static real c_b122 = .78539816250000005f;
#else /* NO_PROTO */
static real c_b53 = (float)1.2566370600000001;
static real c_b57 = (float)-1.2566370600000001;
static real c_b90 = (float).5;
static real c_b92 = (float).4;
static real c_b94 = (float)6.2831853000000004;
static real c_b122 = (float).78539816250000005;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.05/02                           * */
/*  *    TEST TITLE : Appearance of fill areas              * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real sider[18]	/* was [6][3] */ = { 0.f,0.f,0.f,0.f,0.f,0.f,
	    0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f };
#else /* NO_PROTO */
    static real sider[18]	/* was [6][3] */ = { (float)0.,(float)0.,(
	    float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)
	    0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(
	    float)0.,(float)0.,(float)0. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Local variables */
    static real xa[10], ya[10], za[10], xb[10], xf[16]	/* was [4][4] */, yb[
	    10], zb[10];
    static integer ix, jx;
    static real rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */
    static real idm[16]	/* was [4][4] */, xfa[16]	/* was [4][4] */, xfb[
	    16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), npm (integer 
	    *, real *, real *), nfa3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), npm (), nfa3 ();
#endif /* NO_PROTO */
    static integer ran6[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), win6_(integer *, integer *, real *, real *, real 
	    *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), win6_();
#endif /* NO_PROTO */
    static real mscf, xmid, ymid;
    static integer txci, this__, ngsq;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *), nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk (), nsis ();
#endif /* NO_PROTO */
    static integer npts;
    static real xsiz, ysiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void);
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nclst (void), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_();
    extern doublereal rndrl_();
    extern /* Subroutine */ int nqpmf (), nclst (), nemst ();
#endif /* NO_PROTO */
    static real nomms;
    static integer ptseq[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nsvwi (
	    integer *), ebltm3_(real *, real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *), 
	    nslmt3 (real *, integer *), dchpfv_(char *, integer *, integer *, 
	    ftnlen), chkinq_(char *, integer *, ftnlen), setdlg_(integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nsvwi (), ebltm3_(), 
	    nslmt3 (), dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, trulis[6];
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer numemp;
    static real xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nslwsc (real *), nsmksc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nslwsc (), 
	    nsmksc ();
#endif /* NO_PROTO */
    static integer trusiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspmci (integer *), setmsg_(char *, char *, 
	    ftnlen, ftnlen), rnperm_(integer *, integer *), dlstpf_(char *, 
	    integer *, integer *, char *, ftnlen, ftnlen), arcpts_(integer *, 
	    real *, real *, real *, real *, real *, real *, real *, real *), 
	    setval_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspmci (), setmsg_(), rnperm_(), dlstpf_(), 
	    arcpts_(), setval_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* marker type */
/* interior style */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/*  sider = rotation amount for sides: */
/*    front,back,left,right,top,bottom */
    initgl_("04.01.05/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  default attributes */
    nslwsc (&c_b5);
/*  adjust polymarker size */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  set marker size WC */
#ifndef NO_PROTO
    mscf = .02f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    mscf = (float).02 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&mscf);
    nsmk (&c__4);
    nspmci (&c__3);
/*  use interior style HOLLOW throughout */
    nsis (&c__0);
/*  Divide screen up into 6 square labelled areas for all test cases */
    nexst (&c__106);
    nexst (&c__102);
    nclst ();
/*  set up structure 106 to label 6 windows */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
/*  set up rotations for viewing from 6 sides */
/*  back - Y-axis */
#ifndef NO_PROTO
    sider[7] = 3.14159265f;
#else /* NO_PROTO */
    sider[7] = (float)3.14159265;
#endif /* NO_PROTO */
/*  left - Y-axis */
#ifndef NO_PROTO
    sider[8] = 1.5707963250000001f;
#else /* NO_PROTO */
    sider[8] = (float)1.5707963250000001;
#endif /* NO_PROTO */
/*  right - Y-axis */
#ifndef NO_PROTO
    sider[9] = 4.7123889750000005f;
#else /* NO_PROTO */
    sider[9] = (float)4.7123889750000005;
#endif /* NO_PROTO */
/*  top - X-axis */
#ifndef NO_PROTO
    sider[4] = 1.5707963250000001f;
#else /* NO_PROTO */
    sider[4] = (float)1.5707963250000001;
#endif /* NO_PROTO */
/*  bottom - X-axis */
#ifndef NO_PROTO
    sider[5] = 4.7123889750000005f;
#else /* NO_PROTO */
    sider[5] = (float)4.7123889750000005;
#endif /* NO_PROTO */
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "A <fill area> or <fill area 3> primitive with fewer th"
	    "an three points should have no visual effect.", 5L, 99L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "A <fill area> or <fill area 3> primitive with fewer th\
an three points should have no visual effect.", 5L, 99L);
#endif /* NO_PROTO */
/*  random order for 1-6 */
    rnperm_(&c__6, ran6);
/*  number of empty squares */
    numemp = rndint_(&c__2, &c__4);
    trusiz = 0;
    for (ix = 1; ix <= 6; ++ix) {
	this__ = ran6[ix - 1];
/*  set up points for fill areas and polymarkers */
	xa[0] = xwinlo[ix - 1] + xsiz * rndrl_(&c_b22, &c_b23);
	ya[0] = ywinlo[ix - 1] + ysiz * rndrl_(&c_b22, &c_b23);
	za[0] = rndrl_(&c_b5, &c_b27);
	xa[1] = xwinlo[ix - 1] + xsiz * rndrl_(&c_b22, &c_b23);
	ya[1] = ywinlo[ix - 1] + ysiz * rndrl_(&c_b22, &c_b23);
	za[1] = rndrl_(&c_b5, &c_b27);
	if (this__ > numemp + 1) {
/*  draw a single dot polymarker in area #ix */
	    nsmk (&c__1);
	    npm (&c__1, xa, ya);
	} else if (this__ == numemp + 1) {
/*  draw a single line segment in area #ix */
	    npl (&c__2, xa, ya);
	} else if (this__ == numemp) {
/*  draw a two-point 2D fill area in area #ix */
	    nfa (&c__2, xa, ya);
	} else if (this__ == numemp - 1) {
/*  draw a two-point 3D fill area in area #ix */
	    nfa3 (&c__2, xa, ya, za);
	} else {
/*  draw a one-point 3D fill area in area #ix */
	    nfa3 (&c__1, xa, ya, za);
	}
	if (this__ <= numemp) {
/*  add to list of empty squares */
	    ++trusiz;
	    trulis[trusiz - 1] = ix;
	}
/*  next ix */
/* L100: */
    }
#ifndef NO_PROTO
    dlstpf_("DEGENERATE FILL AREAS: List all the empty squares (caution: som"
	    "e squares may contain a dot-polymarker).", &trusiz, trulis, "S", 
	    103L, 1L);
#else /* NO_PROTO */
    dlstpf_("DEGENERATE FILL AREAS: List all the empty squares (caution: som\
e squares may contain a dot-polymarker).", &trusiz, trulis, "S", 103L, 1L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "A <fill area> or <fill area 3> primitive with multiple"
	    " vertices should be rendered by connecting the points in the ord"
	    "er that the points are given in the point list.", 5L, 165L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "A <fill area> or <fill area 3> primitive with multiple\
 vertices should be rendered by connecting the points in the order that the \
points are given in the point list.", 5L, 165L);
#endif /* NO_PROTO */
/*  random order for 1-6 */
    rnperm_(&c__6, ran6);
#ifndef NO_PROTO
    rad = xsiz * .3f;
#else /* NO_PROTO */
    rad = xsiz * (float).3;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 6; ++ix) {
	this__ = ran6[ix - 1];
	xmid = xwinlo[ix - 1] + xsiz / 2;
	ymid = ywinlo[ix - 1] + ysiz / 2;
	if (this__ == 1) {
/*  use polylines to draw a 5 point star */
	    arcpts_(&c__6, &xmid, &ymid, &rad, &c_b48, &c_b49, xa, ya, za);
	    npl (&c__6, xa, ya);
	    ngsq = ix;
	} else if (this__ == 2) {
/*  draw 2D regular pentagon, clockwise */
	    arcpts_(&c__5, &xmid, &ymid, &rad, &c_b48, &c_b53, xa, ya, za);
	    nfa (&c__5, xa, ya);
	} else if (this__ == 3) {
/*  draw 2D regular pentagon, counterclockwise */
	    arcpts_(&c__5, &xmid, &ymid, &rad, &c_b48, &c_b57, xa, ya, za);
	    nfa (&c__5, xa, ya);
	} else if (this__ == 4) {
/*  draw 3D regular pentagon, clockwise */
	    arcpts_(&c__5, &xmid, &ymid, &rad, &c_b48, &c_b53, xa, ya, za);
	    nfa3 (&c__5, xa, ya, za);
	} else {
/*  draw 3D regular pentagon, counterclockwise */
	    arcpts_(&c__5, &xmid, &ymid, &rad, &c_b48, &c_b57, xa, ya, za);
	    nfa3 (&c__5, xa, ya, za);
	}
/*  next ix */
/* L200: */
    }
#ifndef NO_PROTO
    dchpfv_("ORDER OF VERTICES: Which square does NOT contain a closed regul"
	    "ar pentagon?", &c__6, &ngsq, 75L);
#else /* NO_PROTO */
    dchpfv_("ORDER OF VERTICES: Which square does NOT contain a closed regul\
ar pentagon?", &c__6, &ngsq, 75L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "A <fill area> or <fill area 3> primitive with a list o"
	    "f more than two points should be rendered as a closed polygonal "
	    "area.", 5L, 123L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "A <fill area> or <fill area 3> primitive with a list o\
f more than two points should be rendered as a closed polygonal area.", 5L, 
	    123L);
#endif /* NO_PROTO */
/*  random order for 1-6 */
    rnperm_(&c__6, ran6);
#ifndef NO_PROTO
    rad = xsiz * .3f;
#else /* NO_PROTO */
    rad = xsiz * (float).3;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 6; ++ix) {
	this__ = ran6[ix - 1];
	xmid = xwinlo[ix - 1] + xsiz / 2;
	ymid = ywinlo[ix - 1] + ysiz / 2;
	arcpts_(&c__5, &xmid, &ymid, &rad, &c_b48, &c_b53, xa, ya, za);
	xa[5] = xa[0];
	ya[5] = ya[0];
	za[5] = za[0];
	if (this__ == 1) {
/*  draw a pentagon with polylines and leave one side open */
	    npl (&c__5, xa, ya);
	    ngsq = ix;
	} else if (this__ == 2) {
/*  draw 3D pentagon with 6 points (explicit close, last=first poi
nt) */
	    nfa3 (&c__6, xa, ya, za);
	} else if (this__ == 3) {
/*  draw 2D pentagon with 6 points (explicit close, last=first poi
nt) */
	    nfa (&c__6, xa, ya);
	} else if (this__ == 4) {
/*  draw 2D pentagon with 5 points (implicit close) */
	    nfa (&c__5, xa, ya);
	} else {
/*  draw 3D pentagon with 5 points (implicit close) */
	    nfa3 (&c__5, xa, ya, za);
	}
/*  next ix */
/* L300: */
    }
    dchpfv_("FILL AREA CLOSURE: Which pentagon is open?", &c__6, &ngsq, 42L);
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "The appearance of a <fill area 3> primitive should ref"
	    "lect its 3D geometry after being transformed.", 5L, 99L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "The appearance of a <fill area 3> primitive should ref\
lect its 3D geometry after being transformed.", 5L, 99L);
#endif /* NO_PROTO */
/*  which square will be marked wrong? */
    ngsq = rndint_(&c__1, &c__6);
    idmat_(&c__4, idm);
/*  generate 3D list of points distinct from any side for 3D fill area */
/*  with 0 <= x <= y <=1, and z = .5x + .5y */
    npts = 6;
    i__1 = npts - 1;
    r__1 = rndrl_(&c_b5, &c_b94);
#ifndef NO_PROTO
    r__2 = 6.2831853000000004f / (npts - 1);
#else /* NO_PROTO */
    r__2 = (float)6.2831853000000004 / (npts - 1);
#endif /* NO_PROTO */
    arcpts_(&i__1, &c_b90, &c_b90, &c_b92, &r__1, &r__2, xb, yb, zb);
#ifndef NO_PROTO
    xb[npts - 1] = .5f;
    yb[npts - 1] = .5f;
    zb[npts - 1] = .5f;
#else /* NO_PROTO */
    xb[npts - 1] = (float).5;
    yb[npts - 1] = (float).5;
    zb[npts - 1] = (float).5;
#endif /* NO_PROTO */
    setval_("1,2,6,3,5,4", ptseq, 11L);
    i__1 = npts;
    for (ix = 1; ix <= i__1; ++ix) {
	xa[ix - 1] = xb[ptseq[ix - 1] - 1];
	ya[ix - 1] = yb[ptseq[ix - 1] - 1];
#ifndef NO_PROTO
	za[ix - 1] = xa[ix - 1] * .5f + ya[ix - 1] * .5f;
#else /* NO_PROTO */
	za[ix - 1] = xa[ix - 1] * (float).5 + ya[ix - 1] * (float).5;
#endif /* NO_PROTO */
/* L410: */
    }
    for (ix = 1; ix <= 6; ++ix) {
/*  rotate to view from side(ix) and move to window#ix */
#ifndef NO_PROTO
	r__1 = xwinlo[ix - 1] + xsiz / 2 - .5f;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - .5f;
#else /* NO_PROTO */
	r__1 = xwinlo[ix - 1] + xsiz / 2 - (float).5;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - (float).5;
#endif /* NO_PROTO */
	ebltm3_(&c_b90, &c_b90, &c_b90, &r__1, &r__2, &c_b5, &sider[ix - 1], &
		sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xf);
	nslmt3 (xf, &c__2);
/*  display the 3D fill area in square #ix */
	nfa3 (&npts, xa, ya, za);
/*  reset to identity */
	nslmt3 (idm, &c__2);
/*  expected endpoints */
	i__1 = npts;
	for (jx = 1; jx <= i__1; ++jx) {
	    etp3_(&xa[jx - 1], &ya[jx - 1], &za[jx - 1], xf, &xb[jx - 1], &yb[
		    jx - 1], &zb[jx - 1]);
/* L420: */
	}
	if (ix == ngsq) {
/*  distort expected vertices - skip one */
	    i__1 = npts - 1;
	    jx = rndint_(&c__2, &i__1);
	    xb[jx - 1] = xb[npts - 1];
	    yb[jx - 1] = yb[0];
	}
/*  use 2D circle polymarker to mark expected vertices */
	npm (&npts, xb, yb);
/*  next ix */
/* L400: */
    }
#ifndef NO_PROTO
    dchpfv_("GEOMETRY OF 3D FILL AREAS: Which fill area does NOT have all it"
	    "s vertices circled?", &c__6, &ngsq, 82L);
#else /* NO_PROTO */
    dchpfv_("GEOMETRY OF 3D FILL AREAS: Which fill area does NOT have all it\
s vertices circled?", &c__6, &ngsq, 82L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "The appearance of a <fill area> primitive should refle"
	    "ct its 2D geometry after being transformed.", 5L, 97L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "The appearance of a <fill area> primitive should refle\
ct its 2D geometry after being transformed.", 5L, 97L);
#endif /* NO_PROTO */
/*  which square will be marked wrong? */
    ngsq = rndint_(&c__1, &c__6);
    idmat_(&c__4, idm);
/*  use same points for 2D */
    i__1 = npts;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	za[ix - 1] = 0.f;
#else /* NO_PROTO */
	za[ix - 1] = (float)0.;
#endif /* NO_PROTO */
/* L510: */
    }
    for (ix = 1; ix <= 6; ++ix) {
/*  rotate 45 degrees around x and y axis into unit cube to show */
/*  z-values, then rotate to view from side(ix) */
/*  45 degrees: */
	ebltm3_(&c_b90, &c_b90, &c_b5, &c_b5, &c_b5, &c_b90, &c_b122, &c_b122,
		 &c_b5, &c_b27, &c_b27, &c_b27, xfa);
/*  rotate to view from side(ix) and move to window#ix */
#ifndef NO_PROTO
	r__1 = xwinlo[ix - 1] + xsiz / 2 - .5f;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - .5f;
#else /* NO_PROTO */
	r__1 = xwinlo[ix - 1] + xsiz / 2 - (float).5;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - (float).5;
#endif /* NO_PROTO */
	ebltm3_(&c_b90, &c_b90, &c_b90, &r__1, &r__2, &c_b5, &sider[ix - 1], &
		sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xfb);
	ecom3_(xfb, xfa, xf);
	nslmt3 (xf, &c__2);
/*  display the 2D fill area in square #ix */
	nfa (&npts, xa, ya);
/*  reset to identity */
	nslmt3 (idm, &c__2);
/*  expected endpoints */
	i__1 = npts;
	for (jx = 1; jx <= i__1; ++jx) {
	    etp3_(&xa[jx - 1], &ya[jx - 1], &za[jx - 1], xf, &xb[jx - 1], &yb[
		    jx - 1], &zb[jx - 1]);
/* L520: */
	}
	if (ix == ngsq) {
/*  distort expected vertices */
	    i__1 = npts - 1;
	    jx = rndint_(&c__2, &i__1);
	    xb[jx - 1] = xb[npts - 1];
	    yb[jx - 1] = yb[0];
	}
/*  use 2D circle polymarker to mark expected vertices */
	npm (&npts, xb, yb);
/*  next ix */
/* L500: */
    }
#ifndef NO_PROTO
    dchpfv_("GEOMETRY OF 2D FILL AREAS: Which fill area does NOT have all it"
	    "s vertices circled?", &c__6, &ngsq, 82L);
#else /* NO_PROTO */
    dchpfv_("GEOMETRY OF 2D FILL AREAS: Which fill area does NOT have all it\
s vertices circled?", &c__6, &ngsq, 82L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

