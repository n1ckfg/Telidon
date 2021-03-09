/* fort/04/01/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__106 = 106;
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__6 = 6;
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b20 = .5f;
static real c_b23 = 0.f;
static real c_b48 = .78539816250000005f;
static real c_b51 = 1.f;
#else /* NO_PROTO */
static real c_b20 = (float).5;
static real c_b23 = (float)0.;
static real c_b48 = (float).78539816250000005;
static real c_b51 = (float)1.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.02/02                           * */
/*  *    TEST TITLE : Appearance of polymarkers             * */
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
    static integer t1, t2;
    static real xa[10], ya[10], za[10], xb[10], xf[16]	/* was [4][4] */, yb[
	    10], zb[10];
    static integer ix, jx;
    static real idm[16]	/* was [4][4] */, xfa[16]	/* was [4][4] */, xfb[
	    16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *), etp3_(real *,
	     real *, real *, real *, real *, real *, real *), npm3 (integer *,
	     real *, real *, real *), win6_(integer *, integer *, real *, 
	    real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm (), etp3_(), npm3 (), win6_();
#endif /* NO_PROTO */
    static real mscf;
    static integer txci, ngsq;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk ();
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
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nqpmf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *), nclst (void), 
	    nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nqpmf (), nclst (), 
	    nemst ();
#endif /* NO_PROTO */
    static real nomms;
    static integer xperm[10], yperm[10], zperm[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nsvwi (
	    integer *), ebltm3_(real *, real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nsvwi (), ebltm3_();
#endif /* NO_PROTO */
    static logical t1same, t2same;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt3 (real *, integer *), dchpfv_(char *, 
	    integer *, integer *, ftnlen), chkinq_(char *, integer *, ftnlen),
	     setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt3 (), dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer rndint_();
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static real xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setasf_(
	    integer *), nsmksc (real *), nspmci (integer *), setmsg_(char *, 
	    char *, ftnlen, ftnlen), rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setasf_(), nsmksc (), nspmci (), 
	    setmsg_(), rnperm_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* marker type */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/*  sider = rotation amount for sides: */
/*    front,back,left,right,top,bottom */
    initgl_("04.01.02/02", 11L);
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
    nspmci (&c__3);
/*  Divide screen up into 6 square labelled areas for all test cases */
    nexst (&c__106);
    nexst (&c__102);
    nclst ();
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
/*  set up structure 106 to label 6 windows */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "The appearance of a <polymarker 3> primitive should re"
	    "flect its 3D geometry after being transformed.", 5L, 100L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "The appearance of a <polymarker 3> primitive should re\
flect its 3D geometry after being transformed.", 5L, 100L);
#endif /* NO_PROTO */
/*  which square will be marked wrong? */
    ngsq = rndint_(&c__1, &c__6);
    idmat_(&c__4, idm);
/*  generate 3D list of points distinct from any side for 3D polyline */
    npts = 7;
    rnperm_(&npts, xperm);
    rnperm_(&npts, yperm);
    rnperm_(&npts, zperm);
    i__1 = npts;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	xa[ix - 1] = (xperm[ix - 1] - .5f) / npts;
	ya[ix - 1] = (yperm[ix - 1] - .5f) / npts;
	za[ix - 1] = (zperm[ix - 1] - .5f) / npts;
#else /* NO_PROTO */
	xa[ix - 1] = (xperm[ix - 1] - (float).5) / npts;
	ya[ix - 1] = (yperm[ix - 1] - (float).5) / npts;
	za[ix - 1] = (zperm[ix - 1] - (float).5) / npts;
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
	ebltm3_(&c_b20, &c_b20, &c_b20, &r__1, &r__2, &c_b23, &sider[ix - 1], 
		&sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xf);
	nslmt3 (xf, &c__2);
/*  display the actual 3D polymarkers in square #ix */
	nsmk (&c__3);
	npm3 (&npts, xa, ya, za);
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
	nsmk (&c__4);
	npm (&npts, xb, yb);
/*  next ix */
/* L400: */
    }
#ifndef NO_PROTO
    dchpfv_("GEOMETRY OF 3D POLYMARKERS: Which polymarker does NOT have all "
	    "its asterisk vertices circled?", &c__6, &ngsq, 93L);
#else /* NO_PROTO */
    dchpfv_("GEOMETRY OF 3D POLYMARKERS: Which polymarker does NOT have all \
its asterisk vertices circled?", &c__6, &ngsq, 93L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "The appearance of a <polymarker> primitive should refl"
	    "ect its 2D geometry after being transformed.", 5L, 98L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "The appearance of a <polymarker> primitive should refl\
ect its 2D geometry after being transformed.", 5L, 98L);
#endif /* NO_PROTO */
/*  which square will be marked wrong? */
    ngsq = rndint_(&c__1, &c__6);
    idmat_(&c__4, idm);
/*  generate 2D list of points distinct from any side for 2D polymarker */

    npts = 4;
L550:
    rnperm_(&npts, xperm);
    rnperm_(&npts, yperm);
/*  avoid linearity ... */
    t1 = xperm[0] + yperm[0];
    t2 = xperm[0] - yperm[0];
    t1same = TRUE_;
    t2same = TRUE_;
    i__1 = npts;
    for (ix = 2; ix <= i__1; ++ix) {
	if (t1 != xperm[ix - 1] + yperm[ix - 1]) {
	    t1same = FALSE_;
	}
	if (t2 != xperm[ix - 1] - yperm[ix - 1]) {
	    t2same = FALSE_;
	}
/* L540: */
    }
    if (t1same || t2same) {
	goto L550;
    }
    i__1 = npts;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	xa[ix - 1] = (xperm[ix - 1] - .5f) / npts;
	ya[ix - 1] = (yperm[ix - 1] - .5f) / npts;
	za[ix - 1] = 0.f;
#else /* NO_PROTO */
	xa[ix - 1] = (xperm[ix - 1] - (float).5) / npts;
	ya[ix - 1] = (yperm[ix - 1] - (float).5) / npts;
	za[ix - 1] = (float)0.;
#endif /* NO_PROTO */
/* L510: */
    }
    for (ix = 1; ix <= 6; ++ix) {
/*  rotate 45 degrees around x and y axis into unit cube to show */
/*  z-values, then rotate to view from side(ix) */
/*  45 degrees: */
	ebltm3_(&c_b20, &c_b20, &c_b23, &c_b23, &c_b23, &c_b20, &c_b48, &
		c_b48, &c_b23, &c_b51, &c_b51, &c_b51, xfa);
/*  rotate to view from side(ix) and move to window#ix */
#ifndef NO_PROTO
	r__1 = xwinlo[ix - 1] + xsiz / 2 - .5f;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - .5f;
#else /* NO_PROTO */
	r__1 = xwinlo[ix - 1] + xsiz / 2 - (float).5;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - (float).5;
#endif /* NO_PROTO */
	ebltm3_(&c_b20, &c_b20, &c_b20, &r__1, &r__2, &c_b23, &sider[ix - 1], 
		&sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xfb);
	ecom3_(xfb, xfa, xf);
	nslmt3 (xf, &c__2);
/*  display the 2D polyline in square #ix */
	nsmk (&c__3);
	npm (&npts, xa, ya);
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
	nsmk (&c__4);
	npm (&npts, xb, yb);
/*  next ix */
/* L500: */
    }
#ifndef NO_PROTO
    dchpfv_("GEOMETRY OF 2D POLYMARKERS: Which polymarker does NOT have all "
	    "its asterisk vertices circled?", &c__6, &ngsq, 93L);
#else /* NO_PROTO */
    dchpfv_("GEOMETRY OF 2D POLYMARKERS: Which polymarker does NOT have all \
its asterisk vertices circled?", &c__6, &ngsq, 93L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

