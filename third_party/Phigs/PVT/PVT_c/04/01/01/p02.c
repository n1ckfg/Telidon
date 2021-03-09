/* fort/04/01/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b21 = .2f;
static real c_b22 = .8f;
#else /* NO_PROTO */
static real c_b21 = (float).2;
static real c_b22 = (float).8;
#endif /* NO_PROTO */
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b40 = .5f;
static real c_b46 = .1f;
static real c_b47 = .4f;
static real c_b69 = .9f;
static real c_b108 = .78539816250000005f;
static real c_b111 = 1.f;
#else /* NO_PROTO */
static real c_b40 = (float).5;
static real c_b46 = (float).1;
static real c_b47 = (float).4;
static real c_b69 = (float).9;
static real c_b108 = (float).78539816250000005;
static real c_b111 = (float)1.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.01/02                           * */
/*  *    TEST TITLE : Appearance of polylines               * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    double sin(doublereal), cos(doublereal);
#else /* NO_PROTO */
    double sin(), cos();
#endif /* NO_PROTO */

    /* Local variables */
    static integer t1, t2;
    static real xa[10], ya[10], za[10], xb[10], xf[16]	/* was [4][4] */, yb[
	    10], zb[10];
    static integer ix, jx;
    static real rad, idm[16]	/* was [4][4] */, xfa[16]	/* was [4][4] 
	    */, xfb[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), npm (integer 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), npm ();
#endif /* NO_PROTO */
    static real opx, ang1, ang2;
    static integer ran6[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), npl3 (integer *, real *, real *, real *), win6_(
	    integer *, integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), npl3 (), win6_();
#endif /* NO_PROTO */
    static real mscf, xmid, ymid;
    static integer txci, this__, ngsq;
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
    extern /* Subroutine */ int dchpf_(char *, integer *, integer *, integer *
	    , ftnlen), idmat_(integer *, real *), endit_(void);
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nclst (void), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpf_(), idmat_(), endit_();
    extern doublereal rndrl_();
    extern /* Subroutine */ int nqpmf (), nclst (), nemst ();
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
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer opensd, trulis[6], numemp;
    static real xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nslwsc (real *), nsmksc (real *), 
	    nspmci (integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nslwsc (), 
	    nsmksc (), nspmci (), setmsg_(), rnperm_();
#endif /* NO_PROTO */
    static integer trusiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int dlstpf_(char *, integer *, integer *, char *, 
	    ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dlstpf_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* marker type */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/*  sider = rotation amount for sides: */
/*    front,back,left,right,top,bottom */
    initgl_("04.01.01/02", 11L);
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
    setmsg_("1 4 7", "A <polyline> or <polyline 3> primitive with fewer than"
	    " two points should have no visual effect.", 5L, 95L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "A <polyline> or <polyline 3> primitive with fewer than\
 two points should have no visual effect.", 5L, 95L);
#endif /* NO_PROTO */
/*  random order for 1-6 */
    rnperm_(&c__6, ran6);
/*  number of empty squares */
    numemp = rndint_(&c__2, &c__4);
    trusiz = 0;
    for (ix = 1; ix <= 6; ++ix) {
	xa[0] = xwinlo[ix - 1] + xsiz * rndrl_(&c_b21, &c_b22);
	ya[0] = ywinlo[ix - 1] + ysiz * rndrl_(&c_b21, &c_b22);
	this__ = ran6[ix - 1];
	if (this__ > numemp + 1) {
/*  draw a single dot polymarker in area #ix */
	    nsmk (&c__1);
	    npm (&c__1, xa, ya);
	} else if (this__ == numemp + 1) {
/*  draw a single cross polymarker in area #ix */
	    nsmk (&c__5);
	    npm (&c__1, xa, ya);
	} else if (this__ == numemp) {
/*  draw a single point 2D polyline in area #ix */
	    npl (&c__1, xa, ya);
	    ++trusiz;
	    trulis[trusiz - 1] = ix;
	} else {
/*  draw a single point 3D polyline in area #ix */
#ifndef NO_PROTO
	    za[0] = .5f;
#else /* NO_PROTO */
	    za[0] = (float).5;
#endif /* NO_PROTO */
	    npl3 (&c__1, xa, ya, za);
	    ++trusiz;
	    trulis[trusiz - 1] = ix;
	}
/*  next ix */
/* L100: */
    }
#ifndef NO_PROTO
    dlstpf_("DEGENERATE POLYLINES: List all the empty squares (caution: some"
	    " squares may contain a dot-polymarker).", &trusiz, trulis, "S", 
	    102L, 1L);
#else /* NO_PROTO */
    dlstpf_("DEGENERATE POLYLINES: List all the empty squares (caution: some\
 squares may contain a dot-polymarker).", &trusiz, trulis, "S", 102L, 1L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "A <polyline> or <polyline 3> primitive with two points"
	    " should be rendered as a single straight line segment connecting"
	    " those points.", 5L, 132L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "A <polyline> or <polyline 3> primitive with two points\
 should be rendered as a single straight line segment connecting those point\
s.", 5L, 132L);
#endif /* NO_PROTO */
/*  which square will be marked wrong? */
    ngsq = rndint_(&c__1, &c__6);
    idmat_(&c__4, idm);
    for (ix = 1; ix <= 6; ++ix) {
/*  rotate to view from side(ix) and move to window#ix */
#ifndef NO_PROTO
	r__1 = xwinlo[ix - 1] + xsiz / 2 - .5f;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - .5f;
#else /* NO_PROTO */
	r__1 = xwinlo[ix - 1] + xsiz / 2 - (float).5;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - (float).5;
#endif /* NO_PROTO */
	ebltm3_(&c_b40, &c_b40, &c_b40, &r__1, &r__2, &c_b5, &sider[ix - 1], &
		sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xf);
	nslmt3 (xf, &c__2);
/*  get some distinct endpoints */
	for (jx = 1; jx <= 2; ++jx) {
#ifndef NO_PROTO
	    xa[jx - 1] = jx * .5f - rndrl_(&c_b46, &c_b47);
	    ya[jx - 1] = jx * .5f - rndrl_(&c_b46, &c_b47);
	    za[jx - 1] = jx * .5f - rndrl_(&c_b46, &c_b47);
#else /* NO_PROTO */
	    xa[jx - 1] = jx * (float).5 - rndrl_(&c_b46, &c_b47);
	    ya[jx - 1] = jx * (float).5 - rndrl_(&c_b46, &c_b47);
	    za[jx - 1] = jx * (float).5 - rndrl_(&c_b46, &c_b47);
#endif /* NO_PROTO */
/* L210: */
	}
	if (ix <= 2) {
/*  draw two-point 2D polyline in square #ix - will stay in cube, 
*/
/*  even though drawn in plane z=0. */
	    npl (&c__2, xa, ya);
	} else {
/*  draw two-point 3D polyline in square #ix */
	    npl3 (&c__2, xa, ya, za);
	}
/*  reset to identity */
	nslmt3 (idm, &c__2);
/*  expected endpoints */
	etp3_(xa, ya, za, xf, xb, yb, zb);
	etp3_(&xa[1], &ya[1], &za[1], xf, &xb[1], &yb[1], &zb[1]);
	if (ix == ngsq) {
/*  mark expected vertices inaccurately */
#ifndef NO_PROTO
	    xb[0] = xb[0] * .9f + xb[1] * .1f;
	    yb[0] = yb[0] * .9f + yb[1] * .1f;
#else /* NO_PROTO */
	    xb[0] = xb[0] * (float).9 + xb[1] * (float).1;
	    yb[0] = yb[0] * (float).9 + yb[1] * (float).1;
#endif /* NO_PROTO */
	}
	npm (&c__2, xb, yb);
/*  next ix */
/* L200: */
    }
#ifndef NO_PROTO
    dchpfv_("TWO-POINT POLYLINES: Which square contains something other than"
	    " a single line segment with two circled endpoints?", &c__6, &ngsq,
	     113L);
#else /* NO_PROTO */
    dchpfv_("TWO-POINT POLYLINES: Which square contains something other than\
 a single line segment with two circled endpoints?", &c__6, &ngsq, 113L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "A <polyline> or <polyline 3> primitive with a list of "
	    "more than two points should be rendered by connecting each pair "
	    "of adjacent points by a single straight line segment.", 5L, 171L);

#else /* NO_PROTO */
    setmsg_("1 4 7", "A <polyline> or <polyline 3> primitive with a list of \
more than two points should be rendered by connecting each pair of adjacent \
points by a single straight line segment.", 5L, 171L);
#endif /* NO_PROTO */
/*  side of pentagon to leave open */
    opensd = rndint_(&c__1, &c__5);
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
	if (this__ <= 2) {
/*  draw 2D pentagon with open side = opensd, using one */
/*  polyline for each segment */
#ifndef NO_PROTO
	    ang1 = opensd * 1.2566370600000001f;
#else /* NO_PROTO */
	    ang1 = opensd * (float)1.2566370600000001;
#endif /* NO_PROTO */
	    xa[0] = xmid + rad * sin(ang1);
	    ya[0] = ymid + rad * cos(ang1);
	    i__1 = opensd + 4;
	    for (jx = opensd + 1; jx <= i__1; ++jx) {
#ifndef NO_PROTO
		ang2 = jx * 1.2566370600000001f;
#else /* NO_PROTO */
		ang2 = jx * (float)1.2566370600000001;
#endif /* NO_PROTO */
		xa[1] = xmid + rad * sin(ang2);
		ya[1] = ymid + rad * cos(ang2);
		npl (&c__2, xa, ya);
		ang1 = ang2;
		xa[0] = xa[1];
		ya[0] = ya[1];
/* L310: */
	    }
	} else {
/*  draw 3D pentagon with open side = opensd, using one */
/*  polyline for whole figure */
	    opx = (real) opensd;
/*  if ix=6, draw pentagon with open side not= opensd */
	    if (this__ == 6) {
		opx += 1;
	    }
	    for (jx = 0; jx <= 4; ++jx) {
#ifndef NO_PROTO
		ang1 = (jx + opx) * 1.2566370600000001f;
#else /* NO_PROTO */
		ang1 = (jx + opx) * (float)1.2566370600000001;
#endif /* NO_PROTO */
		xa[jx] = xmid + rad * sin(ang1);
		ya[jx] = ymid + rad * cos(ang1);
		za[jx] = rndrl_(&c_b46, &c_b69);
/* L320: */
	    }
	    npl3 (&c__5, xa, ya, za);
	}
/*  next ix */
/* L300: */
    }
#ifndef NO_PROTO
    dchpf_("MULTI-POINT POLYLINES: Which pentagon is open on a different sid"
	    "e?", &c__6, &c__6, ran6, 66L);
#else /* NO_PROTO */
    dchpf_("MULTI-POINT POLYLINES: Which pentagon is open on a different sid\
e?", &c__6, &c__6, ran6, 66L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "The appearance of a <polyline 3> primitive should refl"
	    "ect its 3D geometry after being transformed.", 5L, 98L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "The appearance of a <polyline 3> primitive should refl\
ect its 3D geometry after being transformed.", 5L, 98L);
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
	ebltm3_(&c_b40, &c_b40, &c_b40, &r__1, &r__2, &c_b5, &sider[ix - 1], &
		sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xf);
	nslmt3 (xf, &c__2);
/*  display the 3D polyline in square #ix */
	npl3 (&npts, xa, ya, za);
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
    dchpfv_("GEOMETRY OF 3D POLYLINES: Which polyline does NOT have all its "
	    "vertices circled?", &c__6, &ngsq, 80L);
#else /* NO_PROTO */
    dchpfv_("GEOMETRY OF 3D POLYLINES: Which polyline does NOT have all its \
vertices circled?", &c__6, &ngsq, 80L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "The appearance of a <polyline> primitive should reflec"
	    "t its 2D geometry after being transformed.", 5L, 96L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "The appearance of a <polyline> primitive should reflec\
t its 2D geometry after being transformed.", 5L, 96L);
#endif /* NO_PROTO */    
/*  which square will be marked wrong? */
    ngsq = rndint_(&c__1, &c__6);
    idmat_(&c__4, idm);
/*  generate 2D list of points distinct from any side for 2D polyline */
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
	ebltm3_(&c_b40, &c_b40, &c_b5, &c_b5, &c_b5, &c_b40, &c_b108, &c_b108,
		 &c_b5, &c_b111, &c_b111, &c_b111, xfa);
/*  rotate to view from side(ix) and move to window#ix */
#ifndef NO_PROTO
	r__1 = xwinlo[ix - 1] + xsiz / 2 - .5f;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - .5f;
#else /* NO_PROTO */
	r__1 = xwinlo[ix - 1] + xsiz / 2 - (float).5;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - (float).5;
#endif /* NO_PROTO */
	ebltm3_(&c_b40, &c_b40, &c_b40, &r__1, &r__2, &c_b5, &sider[ix - 1], &
		sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xfb);
	ecom3_(xfb, xfa, xf);
	nslmt3 (xf, &c__2);
/*  display the 2D polyline in square #ix */
	npl (&npts, xa, ya);
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
    dchpfv_("GEOMETRY OF 2D POLYLINES: Which polyline does NOT have all its "
	    "vertices circled?", &c__6, &ngsq, 80L);
#else /* NO_PROTO */
    dchpfv_("GEOMETRY OF 2D POLYLINES: Which polyline does NOT have all its \
vertices circled?", &c__6, &ngsq, 80L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

