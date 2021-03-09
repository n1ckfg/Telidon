/* fort/06/01/02/p13.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__106 = 106;
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b20 = 0.f;
static real c_b23 = .5f;
#else /* NO_PROTO */
static real c_b20 = (float)0.;
static real c_b23 = (float).5;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__8 = 8;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/13                           * */
/*  *    TEST TITLE : Invalid clipping specifications       * */
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
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double sin(doublereal), cos(doublereal);
#else /* NO_PROTO */
    double sin(), cos();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[10], ya[10];
    static integer ol;
    static real xf[16]	/* was [4][4] */;
    static integer op, ix;
    static real ang, mcv[2000]	/* was [4][500] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer nsz;
    static real mcv3[3000]	/* was [6][500] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int win6_(integer *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int win6_();
#endif /* NO_PROTO */
    static real cang, sang;
    static integer txci;
    static real xsiz, ysiz;
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer winid;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer maxpl, ngwin, minop, maxop;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nsmcv (integer *, integer *, 
	    real *), nemst (integer *), nexst (integer *), nopst (integer *), 
	    nsvwi (integer *), ebltm3_(real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *, real *), 
	    nsmcv3 (integer *, integer *, real *), nslmt3 (real *, integer *),
	     dchpfv_(char *, integer *, integer *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen), setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nsmcv (), nemst (), nexst (), 
	    nopst (), nsvwi (), ebltm3_(), nsmcv3 (), nslmt3 (), dchpfv_(), 
	    chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, mclpop, winlis[6], thismc;
    static real xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nqmclf (integer *, integer *, 
	    integer *, integer *, integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), nsmcli (integer *), rnperm_(integer *, integer *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nqmclf (), 
	    setmsg_(), nsmcli (), rnperm_(), setrvs_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* clipping indicator */
/*                noclip        cllip */
/* modelling clipping operator */
/*                replace,      intersect */
    initgl_("06.01.02/13", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1  is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nexst (&c__106);
    nexst (&c__102);
    nclst ();
/*  Set up 6 windows on the screen */
    win6_(&c__106, &c__1, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
/*  minop = minimum operator (lowest value) */
/*  maxop = maximum operator (highest value) */
    nqmclf (&c__0, &errind, &maxpl, &ol, &idum2);
    chkinq_("pqmclf", &errind, 6L);
    minop = 1000;
    maxop = -1000;
    i__1 = ol;
    for (ix = 1; ix <= i__1; ++ix) {
	nqmclf (&ix, &errind, &idum1, &idum2, &mclpop);
	chkinq_("pqmclf", &errind, 6L);
	if (mclpop <= minop) {
	    minop = mclpop;
	}
	if (mclpop >= maxop) {
	    maxop = mclpop;
	}
/* L100: */
    }
/*  coordinates for zigzag polyline: */
    for (ix = 1; ix <= 8; ++ix) {
#ifndef NO_PROTO
	xa[ix - 1] = ix % 2 * .6f + .2f;
	ya[ix - 1] = ix / 9.f;
#else /* NO_PROTO */
	xa[ix - 1] = ix % 2 * (float).6 + (float).2;
	ya[ix - 1] = ix / (float)9.;
#endif /* NO_PROTO */
/* L110: */
    }
/* *** *** *** ***   unsupported combination operator   *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("23 26 38 40 43 46", "If a <set modelling clipping volume> eleme"
	    "nt specifies an unsupported combination operator, then it should"
	    " be ignored upon traversal.", 17L, 133L);
#else /* NO_PROTO */
    setmsg_("23 26 38 40 43 46", "If a <set modelling clipping volume> eleme\
nt specifies an unsupported combination operator, then it should be ignored \
upon traversal.", 17L, 133L);
#endif /* NO_PROTO */
/*  set clip indicator on */
    nsmcli (&c__1);
/*  winlis = randomized list of 1-6 */
    rnperm_(&c__6, winlis);
    for (winid = 1; winid <= 6; ++winid) {
	thismc = winlis[winid - 1];
	ebltm3_(&c_b20, &c_b20, &c_b20, &xwinlo[winid - 1], &ywinlo[winid - 1]
		, &c_b23, &c_b20, &c_b20, &c_b20, &xsiz, &xsiz, &xsiz, xf);
	nslmt3 (xf, &c__2);
/*   <set modelling clipping volume> using: */
/*      operator = replace, point = 0.5,0.5, vector = -1,0 */
	op = 1;
	setrvs_("0.5,0.5,-1,0", mcv, &nsz, 12L);
	nsmcv (&op, &c__1, mcv);
/* if (thismc = 1), <set modelling clipping volume> using: */
/*      operator = replace, point = 0.7,0.5, vector = -1,0 */
	if (thismc == 1) {
	    op = 1;
	    setrvs_("0.7,0.5,-1,0", mcv, &nsz, 12L);
	    ngwin = winid;
	    nsmcv (&op, &c__1, mcv);
/* if (thismc = 2), normal clip: do nothing */
	} else if (thismc == 2) {
/* if (thismc = 3), operator WAY too low: */
	} else if (thismc == 3) {
	    op = minop - 303;
	    setrvs_("0.5,0.5,0.5,0,1,0", mcv3, &nsz, 17L);
	    nsmcv3 (&op, &c__1, mcv3);
/* if (thismc = 4), operator way too high: */
	} else if (thismc == 4) {
	    op = maxop + 1000;
	    setrvs_("0.5,0.5,0,-1", mcv, &nsz, 12L);
	    nsmcv (&op, &c__1, mcv);
/* if (thismc = 5) operator slightly too low: */
	} else if (thismc == 5) {
	    op = minop - 1;
	    setrvs_("0.5,0.5,0.5,1,1,0", mcv3, &nsz, 17L);
	    nsmcv3 (&op, &c__1, mcv3);
/* if (thismc = 6) operator slightly too high: */
	} else if (thismc == 6) {
	    op = maxop + 1;
	    setrvs_("0.5,0.5,1,-1", mcv, &nsz, 12L);
	    nsmcv (&op, &c__1, mcv);
	}
/*  draw polyline using xa, ya */
	npl (&c__8, xa, ya);
/* L120: */
    }
/* pass/fail depending on (operator response = ngwin) */
#ifndef NO_PROTO
    dchpfv_("UNSUPPORTED COMBINATION OPERATOR: In which square is the polyli"
	    "ne clipped differently?", &c__6, &ngwin, 86L);
#else /* NO_PROTO */
    dchpfv_("UNSUPPORTED COMBINATION OPERATOR: In which square is the polyli\
ne clipped differently?", &c__6, &ngwin, 86L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** ***   # distinct planes exceed maximum   *** *** *** *** */

    if (maxpl >= 500) {
#ifndef NO_PROTO
	inmsg_("Skipping test of effect of exceeding maximum number of disti"
		"nct planes, because of program storage limits.", 106L);
#else /* NO_PROTO */
	inmsg_("Skipping test of effect of exceeding maximum number of disti\
nct planes, because of program storage limits.", 106L);
#endif /* NO_PROTO */
	goto L400;
    }
#ifndef NO_PROTO
    setmsg_("23 26 38 40 43 47", "If a <set modelling clipping volume> eleme"
	    "nt attempts to generate a current MCV with more distinct planes "
	    "than the maximum supported, then it should be ignored upon trave"
	    "rsal.", 17L, 175L);
#else /* NO_PROTO */
    setmsg_("23 26 38 40 43 47", "If a <set modelling clipping volume> eleme\
nt attempts to generate a current MCV with more distinct planes than the max\
imum supported, then it should be ignored upon traversal.", 17L, 175L);
#endif /* NO_PROTO */
/*  set clip indicator on */
    nsmcli (&c__1);
/*  winlis = randomized list of 1-6 */
    rnperm_(&c__6, winlis);
    for (winid = 1; winid <= 6; ++winid) {
	thismc = winlis[winid - 1];
	ebltm3_(&c_b20, &c_b20, &c_b20, &xwinlo[winid - 1], &ywinlo[winid - 1]
		, &c_b23, &c_b20, &c_b20, &c_b20, &xsiz, &xsiz, &xsiz, xf);
	nslmt3 (xf, &c__2);
/*   <set modelling clipping volume> using: */
/*      operator = replace, point = 0.5,0.5, vector = -1,0 */
	op = 1;
	setrvs_("0.5,0.5,-1,0", mcv, &nsz, 12L);
	nsmcv (&op, &c__1, mcv);
/* if (thismc = 1), <set modelling clipping volume> using: */
/*      operator = replace, point = 0.5,0.5; vector = -1,0 */
	if (thismc == 1) {
	    op = 1;
	    setrvs_("0.5,0.5,0,-1", mcv, &nsz, 12L);
	    ngwin = winid;
	    nsmcv (&op, &c__1, mcv);
/* if (thismc = 2), normal clip: do nothing */
	} else if (thismc == 2) {
/* if (thismc = 3), exceed maximum with 2D replace: */
/* half-spaces: polygon centered at 0.5,0.5, radius = 0.1, */
/*              with maxpl+1 sides */
	} else if (thismc == 3) {
	    i__1 = maxpl + 1;
	    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
		ang = (ix << 1) * 3.14159265f / (maxpl + 1);
#else /* NO_PROTO */
		ang = (ix << 1) * (float)3.14159265 / (maxpl + 1);
#endif /* NO_PROTO */
		sang = sin(ang);
		cang = cos(ang);
#ifndef NO_PROTO
		mcv[(ix << 2) - 4] = cang * .1f + .5f;
		mcv[(ix << 2) - 3] = sang * .1f + .5f;
#else /* NO_PROTO */
		mcv[(ix << 2) - 4] = cang * (float).1 + (float).5;
		mcv[(ix << 2) - 3] = sang * (float).1 + (float).5;
#endif /* NO_PROTO */
		mcv[(ix << 2) - 2] = -(doublereal)cang;
		mcv[(ix << 2) - 1] = -(doublereal)sang;
/* L310: */
	    }
	    i__1 = maxpl + 1;
	    nsmcv (&c__1, &i__1, mcv);
/* if (thismc = 4), exceed maximum with 2D intersect: */
/* half-spaces: polygon centered at 0.5,0.5, radius = 0.1, */
/*              with maxpl sides */
	} else if (thismc == 4) {
	    i__1 = maxpl;
	    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
		ang = (ix << 1) * 3.14159265f / maxpl;
#else /* NO_PROTO */
		ang = (ix << 1) * (float)3.14159265 / maxpl;
#endif /* NO_PROTO */
		sang = sin(ang);
		cang = cos(ang);
#ifndef NO_PROTO
		mcv[(ix << 2) - 4] = cang * .1f + .5f;
		mcv[(ix << 2) - 3] = sang * .1f + .5f;
#else /* NO_PROTO */
		mcv[(ix << 2) - 4] = cang * (float).1 + (float).5;
		mcv[(ix << 2) - 3] = sang * (float).1 + (float).5;
#endif /* NO_PROTO */
		mcv[(ix << 2) - 2] = -(doublereal)cang;
		mcv[(ix << 2) - 1] = -(doublereal)sang;
/* L320: */
	    }
	    nsmcv (&c__2, &maxpl, mcv);
/* if (thismc = 5), exceed maximum with 3D replace: */
	} else if (thismc == 5) {
	    i__1 = maxpl + 1;
	    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
		ang = (ix << 1) * 3.14159265f / (maxpl + 1);
#else /* NO_PROTO */
		ang = (ix << 1) * (float)3.14159265 / (maxpl + 1);
#endif /* NO_PROTO */
		sang = sin(ang);
		cang = cos(ang);
#ifndef NO_PROTO
		mcv3[ix * 6 - 6] = cang * .1f + .5f;
		mcv3[ix * 6 - 5] = sang * .1f + .5f;
		mcv3[ix * 6 - 4] = 0.f;
#else /* NO_PROTO */
		mcv3[ix * 6 - 6] = cang * (float).1 + (float).5;
		mcv3[ix * 6 - 5] = sang * (float).1 + (float).5;
		mcv3[ix * 6 - 4] = (float)0.;
#endif /* NO_PROTO */
		mcv3[ix * 6 - 3] = -(doublereal)cang;
		mcv3[ix * 6 - 2] = -(doublereal)sang;
#ifndef NO_PROTO
		mcv3[ix * 6 - 1] = .1f;
#else /* NO_PROTO */
		mcv3[ix * 6 - 1] = (float).1;
#endif /* NO_PROTO */
/* L330: */
	    }
	    i__1 = maxpl + 1;
	    nsmcv3 (&c__1, &i__1, mcv3);
/* if (thismc = 6), exceed maximum with 3D intersect: */
	} else if (thismc == 6) {
	    i__1 = maxpl;
	    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
		ang = (ix << 1) * 3.14159265f / maxpl;
#else /* NO_PROTO */
		ang = (ix << 1) * (float)3.14159265 / maxpl;
#endif /* NO_PROTO */
		sang = sin(ang);
		cang = cos(ang);
#ifndef NO_PROTO
		mcv3[ix * 6 - 6] = cang * .1f + .5f;
		mcv3[ix * 6 - 5] = sang * .1f + .5f;
		mcv3[ix * 6 - 4] = .7f;
#else /* NO_PROTO */
		mcv3[ix * 6 - 6] = cang * (float).1 + (float).5;
		mcv3[ix * 6 - 5] = sang * (float).1 + (float).5;
		mcv3[ix * 6 - 4] = (float).7;
#endif /* NO_PROTO */
		mcv3[ix * 6 - 3] = -(doublereal)cang;
		mcv3[ix * 6 - 2] = -(doublereal)sang;
#ifndef NO_PROTO
		mcv3[ix * 6 - 1] = 0.f;
#else /* NO_PROTO */
		mcv3[ix * 6 - 1] = (float)0.;
#endif /* NO_PROTO */
/* L340: */
	    }
	    nsmcv3 (&c__2, &maxpl, mcv3);
	}
/*  draw polyline using xa, ya */
	npl (&c__8, xa, ya);
/* L130: */
    }
/* pass/fail depending on (operator response = ngwin) */
#ifndef NO_PROTO
    dchpfv_("MAXIMUM CLIPPING PLANES EXCEEDED: In which square is the polyli"
	    "ne clipped differently?", &c__6, &ngwin, 86L);
#else /* NO_PROTO */
    dchpfv_("MAXIMUM CLIPPING PLANES EXCEEDED: In which square is the polyli\
ne clipped differently?", &c__6, &ngwin, 86L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** ***   degenerate half-space   *** *** *** *** */
L400:
#ifndef NO_PROTO
    setmsg_("23 26 38 40 43 48", "If a <set modelling clipping volume> eleme"
	    "nt specifies a degenerate half-space (zero-length vector), then "
	    "it should be ignored upon traversal.", 17L, 142L);
#else /* NO_PROTO */
    setmsg_("23 26 38 40 43 48", "If a <set modelling clipping volume> eleme\
nt specifies a degenerate half-space (zero-length vector), then it should be\
 ignored upon traversal.", 17L, 142L);
#endif /* NO_PROTO */
/*  set clip indicator on */
    nsmcli (&c__1);
/*  winlis = randomized list of 1-6 */
    rnperm_(&c__6, winlis);
    for (winid = 1; winid <= 6; ++winid) {
	thismc = winlis[winid - 1];
	ebltm3_(&c_b20, &c_b20, &c_b20, &xwinlo[winid - 1], &ywinlo[winid - 1]
		, &c_b23, &c_b20, &c_b20, &c_b20, &xsiz, &xsiz, &xsiz, xf);
	nslmt3 (xf, &c__2);
/*   <set modelling clipping volume> using: */
/*      operator = replace, point = 0.5,0.5, vector = -1,0 */
	op = 1;
	setrvs_("0.5,0.5,-1,0", mcv, &nsz, 12L);
	nsmcv (&op, &c__1, mcv);
/* if (thismc = 1), <set modelling clipping volume> using: */
/*      operator = replace, point = 0.6,0.5, vector = -1,-1 */
	if (thismc == 1) {
	    op = 1;
	    setrvs_("0.6,0.5,-1,-1", mcv, &nsz, 13L);
	    ngwin = winid;
	    nsmcv (&op, &c__1, mcv);
/* if (thismc = 2), normal clip: do nothing */
	} else if (thismc == 2) {
/* if (thismc = 3), */
/*      zero vector, 2D, operator=replace: */
/*      <set modelling clipping volume> using: */
/*         operator = replace */
/*         point  = 0.4,0.6; vector =  1, 1 */
/*         point  = 0.4,0.6; vector =  0, 0 */
/*         point  = 0.4,0.6; vector = -1,-1 */
	} else if (thismc == 3) {
	    setrvs_("0.4,0.6, 1, 1", mcv, &nsz, 13L);
	    setrvs_("0.4,0.6, 0, 0", &mcv[4], &nsz, 13L);
	    setrvs_("0.4,0.6,-1,-1", &mcv[8], &nsz, 13L);
	    nsmcv (&c__1, &c__3, mcv);
/* if (thismc = 4), */
/*      zero vector, 3D, operator=intersect: */
/*      <set modelling clipping volume 3>, using: */
/*         operator = intersect */
/*         point  = 1,1,1; vector =  0,0,0 */
/*         point  = 1,1,1; vector =  1,0,0 */
/*         point  = 1,1,1; vector = -1,0,0 */
	} else if (thismc == 4) {
	    setrvs_("1,1,1, 0,0,0", mcv3, &nsz, 12L);
	    setrvs_("1,1,1, 1,0,0", &mcv3[6], &nsz, 12L);
	    setrvs_("1,1,1,-1,0,0", &mcv3[12], &nsz, 12L);
	    nsmcv3 (&c__2, &c__3, mcv3);
/* if (thismc = 5) */
/*      zero vector, 2D, operator=intersect: */
/*      <set modelling clipping volume> using: */
/*         operator = intersect */
/*         point  = 0.4,0.6; vector =  1, 1 */
/*         point  = 0.4,0.6; vector = -1,-1 */
/*         point  = 0.4,0.6; vector =  0, 0 */
	} else if (thismc == 5) {
	    setrvs_("0.4,0.6, 1, 1", mcv, &nsz, 13L);
	    setrvs_("0.4,0.6,-1,-1", &mcv[4], &nsz, 13L);
	    setrvs_("0.4,0.6, 0, 0", &mcv[8], &nsz, 13L);
	    nsmcv (&c__2, &c__3, mcv);
/* if (thismc = 6) */
/*      zero vector, 3D, operator=replace: */
/*      <set modelling clipping volume 3>, using: */
/*         operator = replace */
/*         point  = 1,1,1; vector =  1,0,0 */
/*         point  = 1,1,1; vector =  0,0,0 */
/*         point  = 1,1,1; vector = -1,0,0 */
	} else if (thismc == 6) {
	    setrvs_("1,1,1, 1,0,0", mcv3, &nsz, 12L);
	    setrvs_("1,1,1, 0,0,0", &mcv3[6], &nsz, 12L);
	    setrvs_("1,1,1,-1,0,0", &mcv3[12], &nsz, 12L);
	    nsmcv3 (&c__1, &c__3, mcv3);
	}
/*  draw polyline using xa, ya */
	npl (&c__8, xa, ya);
/* L140: */
    }
#ifndef NO_PROTO
    dchpfv_("DEGENERATE HALF-SPACE: In which square is the polyline clipped "
	    "differently?", &c__6, &ngwin, 75L);
#else /* NO_PROTO */
    dchpfv_("DEGENERATE HALF-SPACE: In which square is the polyline clipped \
differently?", &c__6, &ngwin, 75L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

