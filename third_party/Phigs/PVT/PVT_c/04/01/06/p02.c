/* fort/04/01/06/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b23 = .2f;
static real c_b24 = .8f;
static real c_b28 = 1.f;
static real c_b45 = 1.5707963250000001f;
static real c_b46 = 2.5132741200000002f;
#else /* NO_PROTO */
static real c_b23 = (float).2;
static real c_b24 = (float).8;
static real c_b28 = (float)1.;
static real c_b45 = (float)1.5707963250000001;
static real c_b46 = (float)2.5132741200000002;
#endif /* NO_PROTO */
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b51 = -1.2566370600000001f;
static real c_b55 = 1.2566370600000001f;
static real c_b88 = .5f;
static real c_b89 = .65f;
static real c_b90 = .3f;
static real c_b120 = .78539816250000005f;
#else /* NO_PROTO */
static real c_b51 = (float)-1.2566370600000001;
static real c_b55 = (float)1.2566370600000001;
static real c_b88 = (float).5;
static real c_b89 = (float).65;
static real c_b90 = (float).3;
static real c_b120 = (float).78539816250000005;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.06/02                           * */
/*  *    TEST TITLE : Appearance of fill area sets          * */
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
    static real xr[10], yr[10], zr[10], rad, idm[16]	/* was [4][4] */, xfa[
	    16]	/* was [4][4] */, xfb[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), npm (integer 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), npm ();
#endif /* NO_PROTO */
    static integer ran6[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), win6_(integer *, integer *, real *, real *, real 
	    *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), win6_();
#endif /* NO_PROTO */
    static real mscf;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static real xmid, ymid;
    static integer txci, this__, ngsq;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *), nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk (), nsis ();
#endif /* NO_PROTO */
    static integer nsiz, npts;
    static real xsiz, ysiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *), nfas3 (
	    integer *, integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_(), nfas3 ();
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
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), setvs_(
	    char *, integer *, integer *, ftnlen), nsvwi (integer *), ebltm3_(
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *), nslmt3 (real *, integer *
	    ), dchpfv_(char *, integer *, integer *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen), setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), setvs_(), nsvwi (), 
	    ebltm3_(), nslmt3 (), dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer numemp, trulis[6], endpts[10];
    static real xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nslwsc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nslwsc ();
#endif /* NO_PROTO */
    static integer trusiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmksc (real *), nspmci (integer *), setmsg_(
	    char *, char *, ftnlen, ftnlen), rnperm_(integer *, integer *), 
	    dlstpf_(char *, integer *, integer *, char *, ftnlen, ftnlen), 
	    arcpts_(integer *, real *, real *, real *, real *, real *, real *,
	     real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmksc (), nspmci (), setmsg_(), rnperm_(), 
	    dlstpf_(), arcpts_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* marker type */
/* interior style */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/*  sider = rotation amount for sides: */
/*    front,back,left,right,top,bottom */
    initgl_("04.01.06/02", 11L);
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
    setmsg_("1 4 7", "A <fill area set> or <fill area set 3> subarea with fe"
	    "wer than three points should have no visual effect.", 5L, 105L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "A <fill area set> or <fill area set 3> subarea with fe\
wer than three points should have no visual effect.", 5L, 105L);
#endif /* NO_PROTO */
/*  random order for 1-6 */
    rnperm_(&c__6, ran6);
/*  number of empty squares */
    numemp = rndint_(&c__2, &c__4);
    trusiz = 0;
    for (ix = 1; ix <= 6; ++ix) {
	this__ = ran6[ix - 1];
/*  set up points for fill areas and polymarkers */
	for (jx = 1; jx <= 4; ++jx) {
	    xa[jx - 1] = xwinlo[ix - 1] + xsiz * rndrl_(&c_b23, &c_b24);
	    ya[jx - 1] = ywinlo[ix - 1] + ysiz * rndrl_(&c_b23, &c_b24);
	    za[jx - 1] = rndrl_(&c_b5, &c_b28);
/* L110: */
	}
	if (this__ > numemp + 1) {
/*  draw a single dot polymarker in area #ix */
	    nsmk (&c__1);
	    npm (&c__1, xa, ya);
	} else if (this__ == numemp + 1) {
/*  draw a single line segment in area #ix */
	    npl (&c__2, xa, ya);
	} else if (this__ == numemp) {
/*  draw a 2D fill area set with 0, 1, and 2 point subareas */
	    setvs_("1,1,3", endpts, &nsiz, 5L);
	    nfas (&nsiz, endpts, xa, ya);
	} else if (this__ == numemp - 1) {
/*  draw a two point 3D fill area set */
	    setvs_("2", endpts, &nsiz, 1L);
	    nfas3 (&nsiz, endpts, xa, ya, za);
	} else {
/*  draw a 3D fill area set with 0, 1, and 2 point subareas */
	    setvs_("0,2,3", endpts, &nsiz, 5L);
	    nfas3 (&nsiz, endpts, xa, ya, za);
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
    dlstpf_("DEGENERATE FILL AREA SETS: List all the empty squares (caution:"
	    " some squares may contain a dot-polymarker).", &trusiz, trulis, 
	    "S", 107L, 1L);
#else /* NO_PROTO */
    dlstpf_("DEGENERATE FILL AREA SETS: List all the empty squares (caution:\
 some squares may contain a dot-polymarker).", &trusiz, trulis, "S", 107L, 1L)
	    ;
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "A <fill area set> or <fill area set 3> primitive with "
	    "multiple vertices should be rendered as a collection of subareas"
	    ".  Each subarea should be rendered by connecting the points in t"
	    "he order that the points are given in the point list.", 5L, 235L);

#else /* NO_PROTO */
    setmsg_("1 4 7", "A <fill area set> or <fill area set 3> primitive with \
multiple vertices should be rendered as a collection of subareas.  Each suba\
rea should be rendered by connecting the points in the order that the points\
 are given in the point list.", 5L, 235L);
#endif /* NO_PROTO */
/*  random order for 1-6 */
    rnperm_(&c__6, ran6);
#ifndef NO_PROTO
    rad = xsiz * .2f;
#else /* NO_PROTO */
    rad = xsiz * (float).2;
#endif /* NO_PROTO */
    endpts[0] = 5;
    endpts[1] = 9;
    for (ix = 1; ix <= 6; ++ix) {
	this__ = ran6[ix - 1];
	xmid = xwinlo[ix - 1] + xsiz / 2;
	ymid = ywinlo[ix - 1] + ysiz * 2 / 3;
/*  coordinates for rectangle */
	xr[0] = xmid - rad;
#ifndef NO_PROTO
	yr[0] = ywinlo[ix - 1] + ysiz * .1f;
#else /* NO_PROTO */
	yr[0] = ywinlo[ix - 1] + ysiz * (float).1;
#endif /* NO_PROTO */
	xr[1] = xmid + rad;
	yr[1] = yr[0];
	xr[2] = xr[1];
#ifndef NO_PROTO
	yr[2] = ywinlo[ix - 1] + ysiz * .3f;
#else /* NO_PROTO */
	yr[2] = ywinlo[ix - 1] + ysiz * (float).3;
#endif /* NO_PROTO */
	xr[3] = xr[0];
	yr[3] = yr[2];
	xr[4] = xr[0];
	yr[4] = yr[0];
	for (jx = 1; jx <= 5; ++jx) {
#ifndef NO_PROTO
	    zr[jx - 1] = xr[jx - 1] * .5f + yr[jx - 1] * .5f;
#else /* NO_PROTO */
	    zr[jx - 1] = xr[jx - 1] * (float).5 + yr[jx - 1] * (float).5;
#endif /* NO_PROTO */
/* L205: */
	}
	for (jx = 1; jx <= 4; ++jx) {
	    xa[jx + 4] = xr[jx - 1];
	    ya[jx + 4] = yr[jx - 1];
	    za[jx + 4] = zr[jx - 1];
/* L210: */
	}
	if (this__ == 1) {
/*  use polylines to draw a 5 point star and a rectangle */
	    arcpts_(&c__6, &xmid, &ymid, &rad, &c_b45, &c_b46, xa, ya, za);
	    npl (&c__6, xa, ya);
	    npl (&c__5, xr, yr);
	    ngsq = ix;
	} else if (this__ == 2) {
/*  draw 2D rectangle and pentagon, clockwise */
	    arcpts_(&c__5, &xmid, &ymid, &rad, &c_b45, &c_b51, xa, ya, za);
	    nfas (&c__2, endpts, xa, ya);
	} else if (this__ == 3) {
/*  draw 2D rectangle and pentagon, counterclockwise */
	    arcpts_(&c__5, &xmid, &ymid, &rad, &c_b45, &c_b55, xa, ya, za);
	    nfas (&c__2, endpts, xa, ya);
	} else if (this__ == 4) {
/*  draw 3D rectangle and pentagon, clockwise */
	    arcpts_(&c__5, &xmid, &ymid, &rad, &c_b45, &c_b51, xa, ya, za);
	    nfas3 (&c__2, endpts, xa, ya, za);
	} else {
/*  draw 3D rectangle and pentagon, counterclockwise */
	    arcpts_(&c__5, &xmid, &ymid, &rad, &c_b45, &c_b55, xa, ya, za);
	    nfas3 (&c__2, endpts, xa, ya, za);
	}
/*  next ix */
/* L200: */
    }
#ifndef NO_PROTO
    dchpfv_("ORDER OF VERTICES: Which square does NOT contain a closed recta"
	    "ngle and pentagon?", &c__6, &ngsq, 81L);
#else /* NO_PROTO */
    dchpfv_("ORDER OF VERTICES: Which square does NOT contain a closed recta\
ngle and pentagon?", &c__6, &ngsq, 81L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "The subareas with a list of more than two points in a "
	    "<fill area set> or <fill area set 3> primitive should be rendere"
	    "d as closed polygonal areas.", 5L, 146L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "The subareas with a list of more than two points in a \
<fill area set> or <fill area set 3> primitive should be rendered as closed \
polygonal areas.", 5L, 146L);
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
	arcpts_(&c__5, &xmid, &ymid, &rad, &c_b45, &c_b55, xa, ya, za);
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
	    endpts[0] = 6;
	    nfas3 (&c__1, endpts, xa, ya, za);
	} else if (this__ == 3) {
/*  draw 2D pentagon with 6 points (explicit close, last=first poi
nt) */
	    endpts[0] = 6;
	    nfas (&c__1, endpts, xa, ya);
	} else if (this__ == 4) {
/*  draw 2D pentagon with 5 points (implicit close) */
	    endpts[0] = 5;
	    nfas (&c__1, endpts, xa, ya);
	} else {
/*  draw 3D pentagon with 5 points (implicit close) */
	    endpts[0] = 5;
	    nfas3 (&c__1, endpts, xa, ya, za);
	}
/*  next ix */
/* L300: */
    }
    dchpfv_("FILL AREA SET CLOSURE: Which pentagon is open?", &c__6, &ngsq, 
	    46L);
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "The appearance of a <fill area set 3> primitive should"
	    " reflect its 3D geometry after being transformed.", 5L, 103L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "The appearance of a <fill area set 3> primitive should\
 reflect its 3D geometry after being transformed.", 5L, 103L);
#endif /* NO_PROTO */
/*  which square will be marked wrong? */
    ngsq = rndint_(&c__1, &c__6);
    idmat_(&c__4, idm);
/*  set up fill area set with a triangle and a pentagon as subareas */
/*  with z = .5x + .5y */
#ifndef NO_PROTO
    xa[0] = .5f;
    ya[0] = .25f;
    xa[1] = .2f;
    ya[1] = .1f;
    xa[2] = .8f;
    ya[2] = .1f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    ya[0] = (float).25;
    xa[1] = (float).2;
    ya[1] = (float).1;
    xa[2] = (float).8;
    ya[2] = (float).1;
#endif /* NO_PROTO */
    npts = 5;
#ifndef NO_PROTO
    r__1 = 6.2831853000000004f / npts;
#else /* NO_PROTO */
    r__1 = (float)6.2831853000000004 / npts;
#endif /* NO_PROTO */
    arcpts_(&npts, &c_b88, &c_b89, &c_b90, &c_b45, &r__1, xb, yb, zb);
    i__1 = npts;
    for (ix = 1; ix <= i__1; ++ix) {
	xa[ix + 2] = xb[ix - 1];
	ya[ix + 2] = yb[ix - 1];
/* L410: */
    }
    i__1 = npts + 3;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	za[ix - 1] = xa[ix - 1] * .5f + ya[ix - 1] * .5f;
#else /* NO_PROTO */
	za[ix - 1] = xa[ix - 1] * (float).5 + ya[ix - 1] * (float).5;
#endif /* NO_PROTO */
/* L420: */
    }
    endpts[0] = 3;
    endpts[1] = npts + 3;
    for (ix = 1; ix <= 6; ++ix) {
/*  rotate to view from side(ix) and move to window#ix */
#ifndef NO_PROTO
	r__1 = xwinlo[ix - 1] + xsiz / 2 - .5f;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - .5f;
#else /* NO_PROTO */
	r__1 = xwinlo[ix - 1] + xsiz / 2 - (float).5;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - (float).5;
#endif /* NO_PROTO */
	ebltm3_(&c_b88, &c_b88, &c_b88, &r__1, &r__2, &c_b5, &sider[ix - 1], &
		sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xf);
	nslmt3 (xf, &c__2);
/*  display the 3D fill area in square #ix */
	nfas3 (&c__2, endpts, xa, ya, za);
/*  reset to identity */
	nslmt3 (idm, &c__2);
/*  expected endpoints */
	i__1 = npts + 3;
	for (jx = 1; jx <= i__1; ++jx) {
	    etp3_(&xa[jx - 1], &ya[jx - 1], &za[jx - 1], xf, &xb[jx - 1], &yb[
		    jx - 1], &zb[jx - 1]);
/* L430: */
	}
	if (ix == ngsq) {
/*  distort expected vertices - skip one */
	    i__1 = npts + 2;
	    jx = rndint_(&c__2, &i__1);
	    xb[jx - 1] = xb[npts + 2];
	    yb[jx - 1] = yb[0];
	}
/*  use 2D circle polymarker to mark expected vertices */
	i__1 = npts + 3;
	npm (&i__1, xb, yb);
/*  next ix */
/* L400: */
    }
#ifndef NO_PROTO
    dchpfv_("GEOMETRY OF 3D FILL AREA SETS: Which fill area set does NOT hav"
	    "e all its vertices circled?", &c__6, &ngsq, 90L);
#else /* NO_PROTO */
    dchpfv_("GEOMETRY OF 3D FILL AREA SETS: Which fill area set does NOT hav\
e all its vertices circled?", &c__6, &ngsq, 90L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 7", "The appearance of a <fill area set> primitive should r"
	    "eflect its 2D geometry after being transformed.", 5L, 101L);
#else /* NO_PROTO */
    setmsg_("1 4 7", "The appearance of a <fill area set> primitive should r\
eflect its 2D geometry after being transformed.", 5L, 101L);
#endif /* NO_PROTO */
/*  which square will be marked wrong? */
    ngsq = rndint_(&c__1, &c__6);
    idmat_(&c__4, idm);
/*  use same points for 2D */
    i__1 = npts + 3;
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
	ebltm3_(&c_b88, &c_b88, &c_b5, &c_b5, &c_b5, &c_b88, &c_b120, &c_b120,
		 &c_b5, &c_b28, &c_b28, &c_b28, xfa);
/*  rotate to view from side(ix) and move to window#ix */
#ifndef NO_PROTO
	r__1 = xwinlo[ix - 1] + xsiz / 2 - .5f;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - .5f;
#else /* NO_PROTO */
	r__1 = xwinlo[ix - 1] + xsiz / 2 - (float).5;
	r__2 = ywinlo[ix - 1] + ysiz / 2 - (float).5;
#endif /* NO_PROTO */
	ebltm3_(&c_b88, &c_b88, &c_b88, &r__1, &r__2, &c_b5, &sider[ix - 1], &
		sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xfb);
	ecom3_(xfb, xfa, xf);
	nslmt3 (xf, &c__2);
/*  display the 2D fill area in square #ix */
	nfas (&c__2, endpts, xa, ya);
/*  reset to identity */
	nslmt3 (idm, &c__2);
/*  expected endpoints */
	i__1 = npts + 3;
	for (jx = 1; jx <= i__1; ++jx) {
	    etp3_(&xa[jx - 1], &ya[jx - 1], &za[jx - 1], xf, &xb[jx - 1], &yb[
		    jx - 1], &zb[jx - 1]);
/* L520: */
	}
	if (ix == ngsq) {
/*  distort expected vertices */
	    i__1 = npts + 2;
	    jx = rndint_(&c__2, &i__1);
	    xb[jx - 1] = xb[npts + 2];
	    yb[jx - 1] = yb[0];
	}
/*  use 2D circle polymarker to mark expected vertices */
	i__1 = npts + 3;
	npm (&i__1, xb, yb);
/*  next ix */
/* L500: */
    }
#ifndef NO_PROTO
    dchpfv_("GEOMETRY OF 2D FILL AREA SETS: Which fill area does NOT have al"
	    "l its vertices circled?", &c__6, &ngsq, 86L);
#else /* NO_PROTO */
    dchpfv_("GEOMETRY OF 2D FILL AREA SETS: Which fill area does NOT have al\
l its vertices circled?", &c__6, &ngsq, 86L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

