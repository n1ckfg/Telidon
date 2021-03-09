/* fort/04/01/07/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__4 = 4;
static integer c__106 = 106;
static integer c__2 = 2;
static integer c__6 = 6;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b21 = 0.f;
static real c_b26 = 360.f;
static real c_b29 = 75.f;
static real c_b30 = 105.f;
static real c_b35 = 1.f;
static real c_b55 = .5f;
static real c_b61 = .52359877500000007f;
static real c_b72 = -1.f;
static real c_b74 = -5.f;
static real c_b75 = 5.f;
static real c_b114 = .3f;
static real c_b115 = .4f;
#else /* NO_PROTO */
static real c_b21 = (float)0.;
static real c_b26 = (float)360.;
static real c_b29 = (float)75.;
static real c_b30 = (float)105.;
static real c_b35 = (float)1.;
static real c_b55 = (float).5;
static real c_b61 = (float).52359877500000007;
static real c_b72 = (float)-1.;
static real c_b74 = (float)-5.;
static real c_b75 = (float)5.;
static real c_b114 = (float).3;
static real c_b115 = (float).4;
#endif /* NO_PROTO */
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.07/02                           * */
/*  *    TEST TITLE : Appearance of cell arrays             * */
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

    static integer tesid = 102;

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
#else /* NO_PROTO */
    double cos(), sin();
#endif /* NO_PROTO */

    /* Local variables */
    static integer x1, y1;
    static real xa[4], ya[4];
    static integer dx, dy;
    static real xf[9]	/* was [3][3] */;
    static integer ix, iy;
    static real px, qx, py, qy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nca (real *, real *, real *, real *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    );
#else /* NO_PROTO */
    extern /* Subroutine */ int nca ();
#endif /* NO_PROTO */
    static real ang;
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
    extern /* Subroutine */ int npm (integer *, real *, real *), nca3 (real *,
	     real *, real *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical dyn_();
    extern /* Subroutine */ int npm (), nca3 ();
#endif /* NO_PROTO */
    static real xf3d[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl3 (integer *, real *, real *, real *), 
	    win6_(integer *, integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl3 (), win6_();
#endif /* NO_PROTO */
    static integer ngca, icol;
    static real qang, mscf, rang;
    static integer celx, undf[3], cely, ncls, perm[6];
    static real colx;
    static integer txci, this__;
    static real coly;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *), nqcr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *), nscr (
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk (), nqcr (), nscr ();
#endif /* NO_PROTO */
    static integer lsiz, irow;
    static real xsiz, ysiz, xpts[4], ypts[4], zpts[4], rowx, rowy;
    static integer idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int set2d_(char *, integer *, integer *, integer *
	    , integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int set2d_();
#endif /* NO_PROTO */
    static real rdum1, rdum2;
    static integer colia[25]	/* was [5][5] */;
    static real xdiag[2], ydiag[2], zdiag[2];
    static integer ngcol;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *), nqeci (integer *, integer *, integer *, 
	    integer *, integer *), endit_(void), nscmd (integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_(), nqeci (), endit_(), nscmd ();
#endif /* NO_PROTO */
    static integer numci, lcols[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static real centx, centy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nqplf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmf (), nqplf (), nclst ();
#endif /* NO_PROTO */
    static real nomms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), unmsg_(char *, ftnlen), 
	    nslmt (real *, integer *), nexst (integer *), nopst (integer *), 
	    nsvwi (integer *), ebltm3_(real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *, real *), 
	    nslmt3 (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), unmsg_(), nslmt (), nexst (), 
	    nopst (), nsvwi (), ebltm3_(), nslmt3 ();
#endif /* NO_PROTO */
    static real bckcol[3];
#ifndef NO_PROTO
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static real radcir;
    static integer linecl, markcl;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_();
#endif /* NO_PROTO */
    static integer colloc;
    static logical solidc;
    static integer corcol;
    static real diagsz;
    static integer errind, picstr, nocols, arrlen[5];
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer ncolor, offset;
    static real forcol[3], newcol[3], xwinlo[6], ywinlo[6], rndnum;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *), setasf_(
	    integer *), chkinq_(char *, integer *, ftnlen), nsmksc (real *), 
	    nspmci (integer *), nslwsc (real *), nsplci (integer *), setmsg_(
	    char *, char *, ftnlen, ftnlen), discol_(integer *, integer *, 
	    integer *), rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_(), setasf_(), 
	    chkinq_(), nsmksc (), nspmci (), nslwsc (), nsplci (), setmsg_(), 
	    discol_(), rnperm_();
#endif /* NO_PROTO */

/* Aspect source */
/*                BUNDLED     INDIVIDUAL */
/* Marker type */
/* Composition type */
/*                PRECONCATENATE  POSTCONCATENATE  REPLACE */
/* Regeneration flag */
/* Colour model */
/* Type of returned value */
    initgl_("04.01.07/02", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* Set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
#ifndef NO_PROTO
    solidc = dyn_("Are the cells of a cell array on this workstation display"
	    "ed using the color index from the specified array?", 107L);
#else /* NO_PROTO */
    solidc = dyn_("Are the cells of a cell array on this workstation display\
ed using the color index from the specified array?", 107L);
#endif /* NO_PROTO */
    nopst (&picstr);
/*  By convention, view #1 is for picture */
    nsvwi (&c__1);
/*  Use individual attributes */
    setasf_(&c__1);
/*  Default attributes */
    linecl = 1;
    markcl = 2;
/*  Adjust polymarker size */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  Set marker size and color */
#ifndef NO_PROTO
    mscf = .02f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    mscf = (float).02 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&mscf);
    nsmk (&c__4);
    nspmci (&markcl);
/*  Adjust polyline width */
    nqplf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqplf", &errind, 5L);
/*  Set line size and color */
#ifndef NO_PROTO
    mscf = .01f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    mscf = (float).01 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nslwsc (&mscf);
    nsplci (&linecl);
/*  Divide screen up into 6 square labelled areas for all test cases */
    nexst (&c__106);
    nexst (&tesid);
    nclst ();
/*  Set up structure 106 to label 6 windows */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
/*  *** *** *** *** ***   CELL ARRAY 3D    *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("4 14", "A <cell array 3> should be rendered as a parallelogram "
	    "with the specified points P, Q, and R as vertices.", 4L, 105L);
#else /* NO_PROTO */
    setmsg_("4 14", "A <cell array 3> should be rendered as a parallelogram \
with the specified points P, Q, and R as vertices.", 4L, 105L);
#endif /* NO_PROTO */
/*  NGCA = no-good cell array: random integer from 1 to 6 */
    ngca = rndint_(&c__1, &c__6);
/*  Radius of circle for cell array corners */
#ifndef NO_PROTO
    radcir = .3f;
#else /* NO_PROTO */
    radcir = (float).3;
#endif /* NO_PROTO */
/*  5x5 checkerboard 2d array, using 1 and 0 only */
    set2d_("1,0,1,0,1/0,1,0,1,0/1,0,1,0,1/0,1,0,1,0/1,0,1,0,1/", &c__5, &
	    nocols, arrlen, colia, 50L);
/*  Open test structure */
    nopst (&tesid);
    for (ix = 1; ix <= 6; ++ix) {
/*  Scale 0:1,0:1 into window #ix */
	ebltm_(&c_b21, &c_b21, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b21, &
		xsiz, &ysiz, xf);
	nslmt (xf, &c__2);
/*  find random points on circle for P,Q,R of cell array */
#ifndef NO_PROTO
	ang = rndrl_(&c_b21, &c_b26) * .017453292500000002f;
	xpts[0] = radcir * cos(ang) + .5f;
	ypts[0] = radcir * sin(ang) + .5f;
#else /* NO_PROTO */
	ang = rndrl_(&c_b21, &c_b26) * (float).017453292500000002;
	xpts[0] = radcir * cos(ang) + (float).5;
	ypts[0] = radcir * sin(ang) + (float).5;
#endif /* NO_PROTO */
	offset = (rndint_(&c__0, &c__1) << 1) - 1;
#ifndef NO_PROTO
	qang = ang + offset * (rndrl_(&c_b29, &c_b30) * .017453292500000002f);

	rang = ang - offset * (rndrl_(&c_b29, &c_b30) * .017453292500000002f);

	xpts[1] = radcir * cos(qang) + .5f;
	ypts[1] = radcir * sin(qang) + .5f;
	xpts[2] = radcir * cos(rang) + .5f;
	ypts[2] = radcir * sin(rang) + .5f;
#else /* NO_PROTO */
	qang = ang + offset * (rndrl_(&c_b29, &c_b30) * (float)
		.017453292500000002);
	rang = ang - offset * (rndrl_(&c_b29, &c_b30) * (float)
		.017453292500000002);
	xpts[1] = radcir * cos(qang) + (float).5;
	ypts[1] = radcir * sin(qang) + (float).5;
	xpts[2] = radcir * cos(rang) + (float).5;
	ypts[2] = radcir * sin(rang) + (float).5;
#endif /* NO_PROTO */
L20:
	zpts[0] = rndrl_(&c_b21, &c_b35);
	zpts[1] = rndrl_(&c_b21, &c_b35);
	zpts[2] = rndrl_(&c_b21, &c_b35);
#ifndef NO_PROTO
	if (zpts[1] + zpts[2] - zpts[0] < 0.f || zpts[1] + zpts[2] - zpts[0] 
		> 1.f) {
#else /* NO_PROTO */
	if (zpts[1] + zpts[2] - zpts[0] < (float)0. || zpts[1] + zpts[2] - 
		zpts[0] > (float)1.) {
#endif /* NO_PROTO */
	    goto L20;
	}
/*   Draw cell array 3, using */
/*      P,Q,R = (PX,PY,PZ), (QX,QY,QZ), (RX,RY,RZ) ,COLIA(1:DX, 1:DY) 
*/
	nca3 (xpts, ypts, zpts, &c__5, &c__5, &c__1, &c__1, &c__5, &c__5, 
		colia);
	for (iy = 1; iy <= 3; ++iy) {
	    xa[iy - 1] = xpts[iy - 1];
	    ya[iy - 1] = ypts[iy - 1];
/* L30: */
	}
/* Mark vertices */
	if (ix == ngca) {
/* compute incorrect location */
#ifndef NO_PROTO
	    xa[3] = xa[0] + (xa[1] + xa[2] - xa[0] * 2) * 1.1f;
	    ya[3] = ya[0] + (ya[1] + ya[2] - ya[0] * 2) * 1.1f;
#else /* NO_PROTO */
	    xa[3] = xa[0] + (xa[1] + xa[2] - xa[0] * 2) * (float)1.1;
	    ya[3] = ya[0] + (ya[1] + ya[2] - ya[0] * 2) * (float)1.1;
#endif /* NO_PROTO */
	} else {
	    xa[3] = xa[1] + xa[2] - xa[0];
	    ya[3] = ya[1] + ya[2] - ya[0];
	}
/* Mark vertices with a circle */
	npm (&c__4, xa, ya);
/* L10: */
    }
#ifndef NO_PROTO
    dchpfv_("MINIMAL SIMULATION OF 3D CELL ARRAYS: For which cell array are "
	    "the vertices NOT accurately marked by a circle?", &c__6, &ngca, 
	    110L);
#else /* NO_PROTO */
    dchpfv_("MINIMAL SIMULATION OF 3D CELL ARRAYS: For which cell array are \
the vertices NOT accurately marked by a circle?", &c__6, &ngca, 110L);
#endif /* NO_PROTO */
    nemst (&tesid);
/*  *** *** *** *** ***   CELL ARRAY 2D    *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("9 14", "A <cell array> should be rendered as a rectangle (in MC"
	    ") with the specified points P and Q as opposite vertices.", 4L, 
	    112L);
#else /* NO_PROTO */
    setmsg_("9 14", "A <cell array> should be rendered as a rectangle (in MC\
) with the specified points P and Q as opposite vertices.", 4L, 112L);
#endif /* NO_PROTO */
/*  NGCA = No-good cell array: random integer from 1 to 6 */
    ngca = rndint_(&c__1, &c__6);
    for (ix = 1; ix <= 6; ++ix) {
/*  rotate 30 degrees around x and y and then shift to z=0.5 plane */
	ebltm3_(&c_b55, &c_b55, &c_b21, &c_b21, &c_b21, &c_b55, &c_b61, &
		c_b61, &c_b21, &c_b35, &c_b35, &c_b35, xf3d);
	nslmt3 (xf3d, &c__2);
/*  Scale 0:1,0:1 into window #ix */
	ebltm_(&c_b21, &c_b21, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b21, &
		xsiz, &ysiz, xf);
	nslmt (xf, &c__1);
	rndnum = rndrl_(&c_b72, &c_b35);
#ifndef NO_PROTO
	if (rndnum >= 0.f) {
	    px = .15f;
	    qx = .85f;
#else /* NO_PROTO */
	if (rndnum >= (float)0.) {
	    px = (float).15;
	    qx = (float).85;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    px = .75f;
	    qx = .25f;
#else /* NO_PROTO */
	    px = (float).75;
	    qx = (float).25;
#endif /* NO_PROTO */
	}
	rndnum = rndrl_(&c_b74, &c_b75);
#ifndef NO_PROTO
	if (rndnum >= 0.f) {
	    py = .25f;
	    qy = .85f;
#else /* NO_PROTO */
	if (rndnum >= (float)0.) {
	    py = (float).25;
	    qy = (float).85;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    py = .75f;
	    qy = .15f;
#else /* NO_PROTO */
	    py = (float).75;
	    qy = (float).15;
#endif /* NO_PROTO */
	}
/* Draw cell array using p,q = (px,py) (qx,qy) colia(1:dx, 1:dy) */
	nca (&px, &py, &qx, &qy, &c__5, &c__5, &c__1, &c__1, &c__5, &c__5, 
		colia);
	xa[0] = px;
	ya[0] = py;
	xa[1] = qx;
	ya[1] = py;
	xa[2] = px;
	ya[2] = qy;
/*  mark vertices */
	if (ix == ngca) {
/*  compute incorrect vertices */
#ifndef NO_PROTO
	    xa[3] = px + (qx - px) * 1.1f;
	    ya[3] = py + (qy - py) * 1.1f;
#else /* NO_PROTO */
	    xa[3] = px + (qx - px) * (float)1.1;
	    ya[3] = py + (qy - py) * (float)1.1;
#endif /* NO_PROTO */
	} else {
	    xa[3] = qx;
	    ya[3] = qy;
	}
/* Mark vertices with circles */
	npm (&c__4, xa, ya);
/* L50: */
    }
#ifndef NO_PROTO
    dchpfv_("MINIMAL SIMULATION OF 2D CELL ARRAYS: For which cell array are "
	    "the vertices NOT accurately marked by a circle?", &c__6, &ngca, 
	    110L);
#else /* NO_PROTO */
    dchpfv_("MINIMAL SIMULATION OF 2D CELL ARRAYS: For which cell array are \
the vertices NOT accurately marked by a circle?", &c__6, &ngca, 110L);
#endif /* NO_PROTO */
    nemst (&tesid);
/*  *** *** *** *** ***   COLOR TEST SETUP   *** *** *** *** *** */
    if (! solidc) {
#ifndef NO_PROTO
	inmsg_("Skipping tests of color index arrays, since this workstation"
		" does not support control of cell coloring by the array.", 
		116L);
#else /* NO_PROTO */
	inmsg_("Skipping tests of color index arrays, since this workstation\
 does not support control of cell coloring by the array.", 116L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  Request 5 distinct colors */
    discol_(&c__5, &globnu_1.wkid, &ncls);
    if (ncls <= 2) {
	goto L85;
    }
/*  Fill colia(ix,iy) avoiding same colors in adjacent cells */
    for (ix = 1; ix <= 5; ++ix) {
	for (iy = 1; iy <= 5; ++iy) {
/* set up list of random colors */
	    rnperm_(&ncls, lcols);
	    lsiz = ncls;
	    if (ix > 1) {
/*  strike color of previous row from list */
		colloc = iarfnd_(&colia[ix - 1 + iy * 5 - 6], &lsiz, lcols);
		if (colloc > 0) {
		    lcols[colloc - 1] = lcols[lsiz - 1];
		    --lsiz;
		}
	    }
	    if (iy > 1) {
/*  strike color of previous column from list */
		colloc = iarfnd_(&colia[ix + (iy - 1) * 5 - 6], &lsiz, lcols);

		if (colloc > 0) {
		    lcols[colloc - 1] = lcols[lsiz - 1];
		    --lsiz;
		}
	    }
	    if (lsiz >= 1) {
		colia[ix + iy * 5 - 6] = lcols[rndint_(&c__1, &lsiz) - 1];
	    } else {
		colia[ix + iy * 5 - 6] = rndint_(&c__0, &ncls);
	    }
/* L80: */
	}
/* L70: */
    }
L85:
/*  *** *** *** *** ***  CELL COLOR TEST  *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("4 5 9 10 11 12", "The color index of the cells of a <cell array"
	    " 3> and <cell array> should be determined by the corresponding e"
	    "lement of the specified color index array.", 14L, 151L);
#else /* NO_PROTO */
    setmsg_("4 5 9 10 11 12", "The color index of the cells of a <cell array\
 3> and <cell array> should be determined by the corresponding element of th\
e specified color index array.", 14L, 151L);
#endif /* NO_PROTO */
/*  NGCA = no-good cell array: random integer from 1 to 6 */
    ngca = rndint_(&c__1, &c__6);
    for (ix = 1; ix <= 6; ++ix) {
/*  number of cells */
	dx = rndint_(&c__2, &c__4);
	dy = rndint_(&c__2, &c__4);
/*  starting position for color array */
	x1 = 6 - dx;
	y1 = 6 - dy;
/*  Scale 0:1,0:1 into window #ix */
	ebltm_(&c_b21, &c_b21, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b21, &
		xsiz, &ysiz, xf);
	nslmt (xf, &c__2);
	if (ix > 3) {
/* We are in 3-D */
#ifndef NO_PROTO
	    ang = rndrl_(&c_b21, &c_b26) * .017453292500000002f;
	    xpts[0] = radcir * cos(ang) + .5f;
	    ypts[0] = radcir * sin(ang) + .5f;
#else /* NO_PROTO */
	    ang = rndrl_(&c_b21, &c_b26) * (float).017453292500000002;
	    xpts[0] = radcir * cos(ang) + (float).5;
	    ypts[0] = radcir * sin(ang) + (float).5;
#endif /* NO_PROTO */
	    offset = (rndint_(&c__0, &c__1) << 1) - 1;
#ifndef NO_PROTO
	    qang = ang + offset * (rndrl_(&c_b29, &c_b30) * 
		    .017453292500000002f);
	    rang = ang - offset * (rndrl_(&c_b29, &c_b30) * 
		    .017453292500000002f);
	    xpts[1] = radcir * cos(qang) + .5f;
	    ypts[1] = radcir * sin(qang) + .5f;
	    xpts[2] = radcir * cos(rang) + .5f;
	    ypts[2] = radcir * sin(rang) + .5f;
#else /* NO_PROTO */
	    qang = ang + offset * (rndrl_(&c_b29, &c_b30) * (float)
		    .017453292500000002);
	    rang = ang - offset * (rndrl_(&c_b29, &c_b30) * (float)
		    .017453292500000002);
	    xpts[1] = radcir * cos(qang) + (float).5;
	    ypts[1] = radcir * sin(qang) + (float).5;
	    xpts[2] = radcir * cos(rang) + (float).5;
	    ypts[2] = radcir * sin(rang) + (float).5;
#endif /* NO_PROTO */
	    xpts[3] = xpts[1] + xpts[2] - xpts[0];
	    ypts[3] = ypts[1] + ypts[2] - ypts[0];
/*  put z-values between 0.2 and 0.5 - behind diagonals to be draw
n */
	    zpts[0] = rndrl_(&c_b114, &c_b115);
	    zpts[1] = rndrl_(&c_b114, &c_b115);
	    zpts[2] = rndrl_(&c_b114, &c_b115);
	    zpts[3] = zpts[1] + zpts[2] - zpts[0];
/*   Draw cell array 3 */
	    nca3 (xpts, ypts, zpts, &c__5, &c__5, &x1, &y1, &dx, &dy, colia);
	} else {
/*  2-D cell array */
	    rndnum = rndrl_(&c_b72, &c_b35);
#ifndef NO_PROTO
	    if (rndnum >= 0.f) {
		px = .15f;
		qx = .85f;
#else /* NO_PROTO */
	    if (rndnum >= (float)0.) {
		px = (float).15;
		qx = (float).85;
#endif /* NO_PROTO */
	    } else {
#ifndef NO_PROTO
		px = .75f;
		qx = .25f;
#else /* NO_PROTO */
		px = (float).75;
		qx = (float).25;
#endif /* NO_PROTO */
	    }
	    rndnum = rndrl_(&c_b74, &c_b75);
#ifndef NO_PROTO
	    if (rndnum >= 0.f) {
		py = .25f;
		qy = .85f;
#else /* NO_PROTO */
	    if (rndnum >= (float)0.) {
		py = (float).25;
		qy = (float).85;
#endif /* NO_PROTO */
	    } else {
#ifndef NO_PROTO
		py = .75f;
		qy = .15f;
#else /* NO_PROTO */
		py = (float).75;
		qy = (float).15;
#endif /* NO_PROTO */
	    }
/*  Draw cell array using p,q = (px,py) (qx,qy) colia(1:dx, 1:dy) 
*/
	    nca (&px, &py, &qx, &qy, &c__5, &c__5, &x1, &y1, &dx, &dy, colia);

	    xpts[0] = px;
	    ypts[0] = py;
	    xpts[1] = qx;
	    ypts[1] = py;
	    xpts[2] = px;
	    ypts[2] = qy;
	    xpts[3] = qx;
	    ypts[3] = qy;
	}
/* Compute cell boundaries and draw diagonals in correct color */
#ifndef NO_PROTO
	zdiag[0] = .999f;
	zdiag[1] = .999f;
#else /* NO_PROTO */
	zdiag[0] = (float).999;
	zdiag[1] = (float).999;
#endif /* NO_PROTO */
/* vectors for incrementing row and column: */
	rowx = (xpts[1] - xpts[0]) / dx;
	rowy = (ypts[1] - ypts[0]) / dx;
	colx = (xpts[2] - xpts[0]) / dy;
	coly = (ypts[2] - ypts[0]) / dy;
/*  control size of diagonal */
#ifndef NO_PROTO
	diagsz = .3f;
#else /* NO_PROTO */
	diagsz = (float).3;
#endif /* NO_PROTO */
	i__1 = dx;
	for (irow = 1; irow <= i__1; ++irow) {
	    i__2 = dy;
	    for (icol = 1; icol <= i__2; ++icol) {
/*  get correct color */
		celx = x1 + irow - 1;
		cely = y1 + icol - 1;
		corcol = colia[celx + cely * 5 - 6];
		if (ix == ngca && irow == 2 && icol == 2) {
/*  use an incorrect color */
		    ngcol = colia[celx - 1 + cely * 5 - 6];
		    if (ngcol != corcol) {
			goto L510;
		    }
		    ngcol = colia[celx + 1 + cely * 5 - 6];
		    if (ngcol != corcol) {
			goto L510;
		    }
		    ngcol = colia[celx + (cely - 1) * 5 - 6];
		    if (ngcol != corcol) {
			goto L510;
		    }
		    ngcol = colia[celx + (cely + 1) * 5 - 6];
		    if (ngcol != corcol) {
			goto L510;
		    }
#ifndef NO_PROTO
		    unmsg_("Aborting test: cannot find distinct color for ce"
			    "ll to be colored incorrectly.", 77L);
#else /* NO_PROTO */
		    unmsg_("Aborting test: cannot find distinct color for ce\
ll to be colored incorrectly.", 77L);
#endif /* NO_PROTO */
L510:
		    nsplci (&ngcol);
		} else {
/*  use correct color */
		    nsplci (&corcol);
		}
/*  center of this cell: */
#ifndef NO_PROTO
		centx = xpts[0] + (irow - .5f) * rowx + (icol - .5f) * colx;
		centy = ypts[0] + (irow - .5f) * rowy + (icol - .5f) * coly;
#else /* NO_PROTO */
		centx = xpts[0] + (irow - (float).5) * rowx + (icol - (float)
			.5) * colx;
		centy = ypts[0] + (irow - (float).5) * rowy + (icol - (float)
			.5) * coly;
#endif /* NO_PROTO */
/*  first diagonal */
		xdiag[0] = centx + diagsz * (rowx + colx);
		ydiag[0] = centy + diagsz * (rowy + coly);
		xdiag[1] = centx - diagsz * (rowx + colx);
		ydiag[1] = centy - diagsz * (rowy + coly);
		npl3 (&c__2, xdiag, ydiag, zdiag);
/*  second diagonal */
		xdiag[0] = centx + diagsz * rowx - diagsz * colx;
		ydiag[0] = centy + diagsz * rowy - diagsz * coly;
		xdiag[1] = centx - diagsz * rowx + diagsz * colx;
		ydiag[1] = centy - diagsz * rowy + diagsz * coly;
		npl3 (&c__2, xdiag, ydiag, zdiag);
/*  next cell */
/* L180: */
	    }
/* L170: */
	}
/*  next cell array */
/* L140: */
    }
#ifndef NO_PROTO
    dchpfv_("CELL ARRAY COLORING: For which cell array do the cell diagonals"
	    " NOT match the cell color?", &c__6, &ngca, 89L);
#else /* NO_PROTO */
    dchpfv_("CELL ARRAY COLORING: For which cell array do the cell diagonals\
 NOT match the cell color?", &c__6, &ngca, 89L);
#endif /* NO_PROTO */
    nemst (&tesid);
/*  *** *** ***  UNDEFINED CELL COLOR INDICES  *** *** *** */
#ifndef NO_PROTO
    setmsg_("12 13", "An index which is undefined in the color table should "
	    "cause entry number 1 to be used as the color of a cell which is "
	    "specified by that index.", 5L, 142L);
#else /* NO_PROTO */
    setmsg_("12 13", "An index which is undefined in the color table should \
cause entry number 1 to be used as the color of a cell which is specified by\
 that index.", 5L, 142L);
#endif /* NO_PROTO */
/*  Set colors so that they are not the background */
/*  Or the foreground color */
    nscmd (&globnu_1.wkid, &c__1);
/*  BCKCOL = background color = realized color spec for entry #0 */
    nqcr (&globnu_1.wkid, &c__0, &c__3, &c__1, &errind, &ncolor, bckcol);
    chkinq_("pqcr", &errind, 4L);
/*  FORCOL = Foreground color = realized color spec for entry #1 */
    nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &ncolor, forcol);
    chkinq_("pqcr", &errind, 4L);
/*  Try to set entry #1 opposite from bckcol */
    for (ix = 1; ix <= 3; ++ix) {
#ifndef NO_PROTO
	if (bckcol[ix - 1] > .5f) {
	    newcol[ix - 1] = 0.f;
#else /* NO_PROTO */
	if (bckcol[ix - 1] > (float).5) {
	    newcol[ix - 1] = (float)0.;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    newcol[ix - 1] = 1.f;
#else /* NO_PROTO */
	    newcol[ix - 1] = (float)1.;
#endif /* NO_PROTO */
	}
/* L2150: */
    }
/*  Set entry #1 different from forcol - make sure other default */
/*  is to current color-rep of #1, not just a predefined color. */
#ifndef NO_PROTO
    if (forcol[2] > .5f) {
	newcol[2] = 0.f;
#else /* NO_PROTO */
    if (forcol[2] > (float).5) {
	newcol[2] = (float)0.;
#endif /* NO_PROTO */
    } else {
#ifndef NO_PROTO
	newcol[2] = 1.f;
#else /* NO_PROTO */
	newcol[2] = (float)1.;
#endif /* NO_PROTO */
    }
    nscr (&globnu_1.wkid, &c__1, &c__3, newcol);
    nqeci (&globnu_1.wkid, &c__0, &errind, &numci, &idum1);
    chkinq_("pqeci", &errind, 5L);
/*  UNDF1,UNDF2,UNDF3 = 3 undefined, positive color indices */
    undf[0] = numci + 1;
    undf[1] = -1;
    undf[2] = numci + 90;
    rnperm_(&c__6, perm);
    dx = 3;
    dy = 3;
/*  set up 3D cell array coordinates */
#ifndef NO_PROTO
    xpts[0] = .2f;
    ypts[0] = .2f;
    xpts[1] = .8f;
    ypts[1] = .2f;
    xpts[2] = .2f;
    ypts[2] = .8f;
#else /* NO_PROTO */
    xpts[0] = (float).2;
    ypts[0] = (float).2;
    xpts[1] = (float).8;
    ypts[1] = (float).2;
    xpts[2] = (float).2;
    ypts[2] = (float).8;
#endif /* NO_PROTO */
    xpts[3] = xpts[1] + xpts[2] - xpts[0];
    ypts[3] = ypts[1] + ypts[2] - ypts[0];
#ifndef NO_PROTO
    zpts[0] = .5f;
    zpts[1] = .5f;
    zpts[2] = .5f;
#else /* NO_PROTO */
    zpts[0] = (float).5;
    zpts[1] = (float).5;
    zpts[2] = (float).5;
#endif /* NO_PROTO */
    zpts[3] = zpts[1] + zpts[2] - zpts[0];
/*  set up 2D cell array coordinates */
#ifndef NO_PROTO
    px = .2f;
    py = .2f;
    qx = .8f;
    qy = .8f;
#else /* NO_PROTO */
    px = (float).2;
    py = (float).2;
    qx = (float).8;
    qy = (float).8;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 6; ++ix) {
/*  Scale 0:1,0:1 into window #ix */
	ebltm_(&c_b21, &c_b21, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b21, &
		xsiz, &ysiz, xf);
	nslmt (xf, &c__2);
/*  3x3 checkerboard 2d array, using 1 and 0 only */
	set2d_("1,0,1,0,0/0,1,0,0,0/1,0,1,0,0/0,0,0,0,0/0,0,0,0,0/", &c__5, &
		nocols, arrlen, colia, 50L);
	this__ = perm[ix - 1];
	if (this__ >= 2) {
	    colia[0] = undf[0];
	}
	if (this__ >= 3) {
	    colia[12] = undf[1];
	}
	if (this__ >= 4) {
	    colia[10] = undf[2];
	}
	if (this__ >= 5) {
	    colia[6] = undf[0];
	}
	if (this__ >= 6) {
	    colia[2] = 0;
	    ngca = ix;
	}
	if (ix > 3) {
/*  3D cell array */
	    nca3 (xpts, ypts, zpts, &c__5, &c__5, &c__1, &c__1, &dx, &dy, 
		    colia);
	} else {
/*  2D cell array */
	    nca (&px, &py, &qx, &qy, &c__5, &c__5, &c__1, &c__1, &dx, &dy, 
		    colia);
	}
/* L220: */
    }
    dchpfv_("UNDEFINED CELL COLOUR INDICES: Which cell array is different?", &
	    c__6, &ngca, 61L);
    nemst (&tesid);
/*  Wrap it up. */
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

