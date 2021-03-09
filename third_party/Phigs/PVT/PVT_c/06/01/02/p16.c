/* fort/06/01/02/p16.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__106 = 106;
static integer c__2 = 2;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b18 = 0.f;
static real c_b25 = 1.f;
static real c_b32 = .1f;
static real c_b33 = .9f;
static real c_b35 = -1.f;
static real c_b42 = .5f;
static real c_b45 = -.5f;
#else /* NO_PROTO */
static real c_b18 = (float)0.;
static real c_b25 = (float)1.;
static real c_b32 = (float).1;
static real c_b33 = (float).9;
static real c_b35 = (float)-1.;
static real c_b42 = (float).5;
static real c_b45 = (float)-.5;
#endif /* NO_PROTO */
static integer c__8 = 8;
#ifndef NO_PROTO
static real c_b80 = .01f;
static real c_b81 = .99f;
#else /* NO_PROTO */
static real c_b80 = (float).01;
static real c_b81 = (float).99;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/16                           * */
/*  *    TEST TITLE : Modelling clipping for polyline and   * */
/*  *                 polymarker                            * */
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
    integer i__1, i__2;
    real r__1, r__2, r__3, r__4;

    /* Builtin functions */
#ifndef NO_PROTO
    double sin(doublereal), cos(doublereal);
#else /* NO_PROTO */
    double sin(), cos();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[40], ya[40], za[40], xf[16]	/* was [4][4] */;
    static integer ix, iy;
    static real dco[10], ang;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static real mcv3[60]	/* was [6][10] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), npl3 (integer *, real *, real *, real *), npm3 (
	    integer *, real *, real *, real *), win6_(integer *, integer *, 
	    real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), npl3 (), npm3 (), win6_();
#endif /* NO_PROTO */
    static real brad;
    static integer idel;
    static real mscf, uneg;
    static integer ptid;
    static real xloc, yloc;
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk ();
#endif /* NO_PROTO */
    static integer nsiz;
    static real upos, ytop, xsiz, ysiz;
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum2;
    static integer delta;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_();
#endif /* NO_PROTO */
    static real pdifx, pdify, pdifz;
    static integer ngwin;
    static real yincr, uparm, xincr, nomms;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nclst (void), nemst (integer *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int nqpmf (), nclst (), nemst ();
#endif /* NO_PROTO */
    static real primx[40], primy[40], primz[40];
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nsvwi (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nsvwi ();
#endif /* NO_PROTO */
    static real expvx[20], expvy[20], expvz[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *),
	     nsmcv3 (integer *, integer *, real *), nslmt3 (real *, integer *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm3_(), nsmcv3 (), nslmt3 ();
#endif /* NO_PROTO */
    static integer ngline;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), dchpfv_(
	    char *, integer *, integer *, ftnlen), setdlg_(integer *, integer 
	    *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), dchpfv_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, thiswn;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer thisln, expnum, numlin, mktype, numvis;
    static real xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsmksc (real *), setmsg_(char *, 
	    char *, ftnlen, ftnlen), nsmcli (integer *), setrvs_(char *, real 
	    *, integer *, ftnlen), lnplpt_(real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), nslwsc (real *), numlab_(integer *, real *, real *, real 
	    *), drwrec_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsmksc (), 
	    setmsg_(), nsmcli (), setrvs_(), lnplpt_(), nslwsc (), numlab_(), 
	    drwrec_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* marker type */
/* clipping indicator */
/*                noclip        cllip */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* modelling clipping operator */
/*                replace,      intersect */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    initgl_("06.01.02/16", 11L);
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
#ifndef NO_PROTO
    mscf = .012f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    mscf = (float).012 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&mscf);
/*  set marker type = circle */
    nsmk (&c__4);
    nexst (&c__102);
    nclst ();
/*  Set up 6 windows on the screen */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
    nexst (&c__106);
/*  throughout, represent a line segment as a point P and vector V, */
/*    where endpoints = P and P+V */

/*  *** *** *** ***   polyline   *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("40 41 42 43 53 57 58", "Exactly those parts of a polyline that "
	    "lie outside the current modelling clipping volume should be clip"
	    "ped.", 20L, 107L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 53 57 58", "Exactly those parts of a polyline that \
lie outside the current modelling clipping volume should be clipped.", 20L, 
	    107L);
#endif /* NO_PROTO */
/*  ngwin = incorrectly drawn window = random from 1 to 6 */
    ngwin = rndint_(&c__1, &c__6);
/*  for thiswn = 1 to 6 */
    for (thiswn = 1; thiswn <= 6; ++thiswn) {
/*  xf = modelling transformation to map unit square (0-1) into */
/*    window #thiswn (with z-dimension unaltered) */
	ebltm3_(&c_b18, &c_b18, &c_b18, &xwinlo[thiswn - 1], &ywinlo[thiswn - 
		1], &c_b18, &c_b18, &c_b18, &c_b18, &xsiz, &xsiz, &c_b25, xf);

	nslmt3 (xf, &c__2);
	nsmcli (&c__1);
/*  expected number of vertices */
	expnum = 0;
	if (thiswn == 1 || thiswn == 4) {
/*  *** *** ***  multi line segment, several ends clipped: */
/*  this creates a wedge shaped MCV, pointed away from the viewer,
 */
/*  somewhat like looking into a slightly opened vertical book */
/*  points on clipping planes = (0.5, 0.5, 0), (0.5, 0.5, 0) */
/*    vec(1) = attitude of plane #1 =  5,0,2 */
/*    vec(2) = attitude of plane #2 = -5,0,2 */
	    setrvs_("0.5,0.5,0, 5,0,2, 0.5,0.5,0, -5,0,2", mcv3, &nsiz, 35L);
	    nsmcv3 (&c__1, &c__2, mcv3);
/*  4th co-efficient for planes */
	    dco[0] = -(doublereal)(mcv3[0] * mcv3[3] + mcv3[1] * mcv3[4] + 
		    mcv3[2] * mcv3[5]);
	    dco[1] = -(doublereal)(mcv3[6] * mcv3[9] + mcv3[7] * mcv3[10] + 
		    mcv3[8] * mcv3[11]);
/*  generate zig-zag polyline to be clipped */
	    for (ix = 1; ix <= 6; ++ix) {
/*  next point */
#ifndef NO_PROTO
		primx[ix - 1] = ix % 2 * .9f + .05f;
		primy[ix - 1] = ix / 7.f;
#else /* NO_PROTO */
		primx[ix - 1] = ix % 2 * (float).9 + (float).05;
		primy[ix - 1] = ix / (float)7.;
#endif /* NO_PROTO */
		primz[ix - 1] = rndrl_(&c_b32, &c_b33);
		if (ix <= 1) {
		    goto L110;
		}
/*  vector from previous point */
		pdifx = primx[ix - 1] - primx[ix - 2];
		pdify = primy[ix - 1] - primy[ix - 2];
		pdifz = primz[ix - 1] - primz[ix - 2];
/*  intersection of this line segment and clipping planes in M
C */
		++expnum;
		lnplpt_(&primx[ix - 1], &primy[ix - 1], &primz[ix - 1], &
			pdifx, &pdify, &pdifz, &mcv3[3], &mcv3[4], &mcv3[5], 
			dco, &expvx[expnum - 1], &expvy[expnum - 1], &expvz[
			expnum - 1]);
		++expnum;
		lnplpt_(&primx[ix - 1], &primy[ix - 1], &primz[ix - 1], &
			pdifx, &pdify, &pdifz, &mcv3[9], &mcv3[10], &mcv3[11],
			 &dco[1], &expvx[expnum - 1], &expvy[expnum - 1], &
			expvz[expnum - 1]);
/*  next ix */
L110:
		;
	    }
/*  draw clipped polyline */
	    npl3 (&c__6, primx, primy, primz);
	} else if (thiswn == 2 || thiswn == 5) {
/*  *** *** ***  use six clipping planes: */
/*  xf = modelling transformation to map double-unit cube (-1 to 1
) */
/*       into window #thiswn (in z-dimension map -1 to 1 into 0 to
 1) */
#ifndef NO_PROTO
	    r__1 = xwinlo[thiswn - 1] + 1.f;
	    r__2 = ywinlo[thiswn - 1] + 1.f;
#else /* NO_PROTO */
	    r__1 = xwinlo[thiswn - 1] + (float)1.;
	    r__2 = ywinlo[thiswn - 1] + (float)1.;
#endif /* NO_PROTO */
	    r__3 = xsiz / 2;
	    r__4 = xsiz / 2;
	    ebltm3_(&c_b35, &c_b35, &c_b35, &r__1, &r__2, &c_b25, &c_b18, &
		    c_b18, &c_b18, &r__3, &r__4, &c_b42, xf);
	    nslmt3 (xf, &c__2);
/*  set up planes surrounding the origin, clipping away from the o
rigin: */
	    for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
		ang = ix * 6.2831853000000004f / 6.f;
		mcv3[ix * 6 - 6] = sin(ang) * .7f;
		mcv3[ix * 6 - 5] = cos(ang) * .7f;
		mcv3[ix * 6 - 4] = 0.f;
#else /* NO_PROTO */
		ang = ix * (float)6.2831853000000004 / (float)6.;
		mcv3[ix * 6 - 6] = sin(ang) * (float).7;
		mcv3[ix * 6 - 5] = cos(ang) * (float).7;
		mcv3[ix * 6 - 4] = (float)0.;
#endif /* NO_PROTO */
		mcv3[ix * 6 - 3] = -(doublereal)mcv3[ix * 6 - 6];
		mcv3[ix * 6 - 2] = -(doublereal)mcv3[ix * 6 - 5];
/*  wobble here - planes not parallel to z-axis */
		mcv3[ix * 6 - 1] = rndrl_(&c_b45, &c_b42);
/*  4th coefficient for plane #ix */
		dco[ix - 1] = -(doublereal)(mcv3[ix * 6 - 6] * mcv3[ix * 6 - 
			3] + mcv3[ix * 6 - 5] * mcv3[ix * 6 - 2] + mcv3[ix * 
			6 - 4] * mcv3[ix * 6 - 1]);
/*  next ix */
/* L120: */
	    }
	    nsmcv3 (&c__1, &c__6, mcv3);
/*  draw 8 line segments through the origin: */
	    for (ix = 1; ix <= 4; ++ix) {
#ifndef NO_PROTO
		ang = ix * 3.14159265f / 4;
#else /* NO_PROTO */
		ang = ix * (float)3.14159265 / 4;
#endif /* NO_PROTO */
		primx[0] = sin(ang) * 2;
		primy[0] = cos(ang) * 2;
		primz[0] = rndrl_(&c_b35, &c_b25);
		primx[1] = -(doublereal)primx[0];
		primy[1] = -(doublereal)primy[0];
		primz[1] = -(doublereal)primz[0];
		npl3 (&c__2, primx, primy, primz);
/*  calculate clipped points as those closest to the origin: 
*/
#ifndef NO_PROTO
		upos = 1e3f;
		uneg = -1e3f;
#else /* NO_PROTO */
		upos = (float)1e3;
		uneg = (float)-1e3;
#endif /* NO_PROTO */
		for (iy = 1; iy <= 6; ++iy) {
		    uparm = -(doublereal)dco[iy - 1] / (mcv3[iy * 6 - 3] * 
			    primx[0] + mcv3[iy * 6 - 2] * primy[0] + mcv3[iy *
			     6 - 1] * primz[0]);
#ifndef NO_PROTO
		    if (uparm > 0.f) {
#else /* NO_PROTO */
		    if (uparm > (float)0.) {
#endif /* NO_PROTO */
			upos = dmin(upos,uparm);
		    } else {
			uneg = dmax(uneg,uparm);
		    }
/* L140: */
		}
		++expnum;
		expvx[expnum - 1] = upos * primx[0];
		expvy[expnum - 1] = upos * primy[0];
		expvz[expnum - 1] = upos * primz[0];
		++expnum;
		expvx[expnum - 1] = uneg * primx[0];
		expvy[expnum - 1] = uneg * primy[0];
		expvz[expnum - 1] = uneg * primz[0];
/*  next ix */
/* L130: */
	    }
	} else {
/*  elseif (thiswn = 3 or 6) then */
/*  *** *** ***  clip away entire 2D line segments: */
/*  point, vector for clipping plane: ( 0.6, 0.5, 0), (-3.0,-1.0, 
5.0) */
	    setrvs_("0.6,0.5,0, -3.0,-1.0,5.0", mcv3, &nsiz, 24L);
	    nsmcv3 (&c__1, &c__1, mcv3);
/*  build spiral 2D polyline: */
	    ptid = 1;
#ifndef NO_PROTO
	    primx[ptid - 1] = .5f;
	    primy[ptid - 1] = .5f;
#else /* NO_PROTO */
	    primx[ptid - 1] = (float).5;
	    primy[ptid - 1] = (float).5;
#endif /* NO_PROTO */
	    delta = 1;
	    for (ix = 1; ix <= 5; ++ix) {
		++ptid;
#ifndef NO_PROTO
		primx[ptid - 1] = primx[ptid - 2] + delta * .15f;
#else /* NO_PROTO */
		primx[ptid - 1] = primx[ptid - 2] + delta * (float).15;
#endif /* NO_PROTO */
		primy[ptid - 1] = primy[ptid - 2];
/*  horizontal segment crosses clipping plane: */
		++expnum;
/* Computing MIN */
		r__1 = primx[ptid - 1], r__2 = primx[ptid - 2];
		expvx[expnum - 1] = dmin(r__1,r__2);
		expvy[expnum - 1] = primy[ptid - 1];
#ifndef NO_PROTO
		expvz[expnum - 1] = 0.f;
#else /* NO_PROTO */
		expvz[expnum - 1] = (float)0.;
#endif /* NO_PROTO */
		++expnum;
#ifndef NO_PROTO
		expvx[expnum - 1] = (2.3f - primy[ptid - 1]) / 3;
#else /* NO_PROTO */
		expvx[expnum - 1] = ((float)2.3 - primy[ptid - 1]) / 3;
#endif /* NO_PROTO */
		expvy[expnum - 1] = primy[ptid - 1];
#ifndef NO_PROTO
		expvz[expnum - 1] = 0.f;
#else /* NO_PROTO */
		expvz[expnum - 1] = (float)0.;
#endif /* NO_PROTO */
		++ptid;
		primx[ptid - 1] = primx[ptid - 2];
#ifndef NO_PROTO
		primy[ptid - 1] = primy[ptid - 2] + delta * .15f;
#else /* NO_PROTO */
		primy[ptid - 1] = primy[ptid - 2] + delta * (float).15;
#endif /* NO_PROTO */
		if (delta > 0) {
		    ++delta;
		} else {
		    --delta;
		}
		delta = -delta;
/*  next ix */
/* L150: */
	    }
/*  draw polyline using prim(1 to ptid) */
	    npl (&ptid, primx, primy);
	}
/*  *** *** ***  common post-processing   *** *** *** */
	if (thiswn == ngwin) {
/*  omit at random one expected vertex: */
	    idel = rndint_(&c__1, &expnum);
	    expvx[idel - 1] = expvx[expnum - 1];
	    expvy[idel - 1] = expvy[expnum - 1];
	    expvz[idel - 1] = expvz[expnum - 1];
	    --expnum;
	}
/*  draw expected vertices */
	i__1 = expnum;
	for (ix = 1; ix <= i__1; ++ix) {
/*  expv(ix) as transformed by xf */
	    etp3_(&expvx[ix - 1], &expvy[ix - 1], &expvz[ix - 1], xf, &xa[ix 
		    - 1], &ya[ix - 1], &za[ix - 1]);
/* L190: */
	}
	nsmcli (&c__0);
/*  set modelling transformation to identity */
/*  draw 2D circle polymarker for pmloc */
	idmat_(&c__4, xf);
	nslmt3 (xf, &c__2);
	npm3 (&expnum, xa, ya, za);
/*  next thiswn */
/* L100: */
    }
#ifndef NO_PROTO
    dchpfv_("MODELLING CLIPPING OF POLYLINE: In which window is there NOT ex"
	    "actly one enclosing circle marker for each polyline vertex?", &
	    c__6, &ngwin, 122L);
#else /* NO_PROTO */
    dchpfv_("MODELLING CLIPPING OF POLYLINE: In which window is there NOT ex\
actly one enclosing circle marker for each polyline vertex?", &c__6, &ngwin, 
	    122L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  *** *** *** ***   polymarker   *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("40 41 42 43 53 57 58 59", "If the location of a marker lies out"
	    "side the current modelling clipping volume, the entire marker sh"
	    "ould be clipped; if inside it should be unclipped or partially c"
	    "lipped.", 23L, 171L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 53 57 58 59", "If the location of a marker lies out\
side the current modelling clipping volume, the entire marker should be clip\
ped; if inside it should be unclipped or partially clipped.", 23L, 171L);
#endif /* NO_PROTO */
/*  set marker size = 0.03 in WC */
/*  set line width = minimum available */
#ifndef NO_PROTO
    r__1 = .03f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).03 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&r__1);
    nslwsc (&c_b18);
/*  numlin = number of lines to display */
    numlin = 8;
/*  ngline = incorrectly drawn line */
    ngline = rndint_(&c__1, &numlin);
/*  yincr = space between lines */
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
    setrvs_("0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9", xa, &nsiz, 31L);
    numlab_(&numlin, &c_b32, &ytop, &yincr);
#ifndef NO_PROTO
    brad = .017500000000000002f;
#else /* NO_PROTO */
    brad = (float).017500000000000002;
#endif /* NO_PROTO */
    i__1 = numlin;
    for (thisln = 1; thisln <= i__1; ++thisln) {
	nsmcli (&c__1);
	mktype = thisln % 5 + 1;
	nsmk (&mktype);
/*  number visible markers */
	numvis = rndint_(&c__1, &c__8);
/*  put clipping plane just to the right of marker #numvis or */
/*  just to the left of marker #numvis+1: */
#ifndef NO_PROTO
	xincr = thisln % 2 * .098f;
#else /* NO_PROTO */
	xincr = thisln % 2 * (float).098;
#endif /* NO_PROTO */
/*  set MCV = point: (numvis/10.0 + 0.101 + xincr, 0, 0); vector: (-1,
0,0) */
	setrvs_("0,0,0, -1,0,0", mcv3, &nsiz, 13L);
#ifndef NO_PROTO
	mcv3[0] = numvis / 10.f + .101f + xincr;
#else /* NO_PROTO */
	mcv3[0] = numvis / (float)10. + (float).101 + xincr;
#endif /* NO_PROTO */
	nsmcv3 (&c__1, &c__1, mcv3);
	for (ix = 1; ix <= 8; ++ix) {
	    ya[ix - 1] = yloc;
	    za[ix - 1] = rndrl_(&c_b80, &c_b81);
/* L210: */
	}
	npm3 (&c__8, xa, ya, za);
	nsmcli (&c__0);
	if (thisln == ngline) {
	    --numvis;
	}
#ifndef NO_PROTO
	xloc = .2f;
#else /* NO_PROTO */
	xloc = (float).2;
#endif /* NO_PROTO */
	i__2 = numvis;
	for (ix = 1; ix <= i__2; ++ix) {
/* draw square, using polyline, size = 0.035 in WC, centered at xl
oc, yloc*/
	    r__1 = xloc - brad;
	    r__2 = xloc + brad;
	    r__3 = yloc - brad;
	    r__4 = yloc + brad;
	    drwrec_(&r__1, &r__2, &r__3, &r__4);
#ifndef NO_PROTO
	    xloc += .1f;
#else /* NO_PROTO */
	    xloc += (float).1;
#endif /* NO_PROTO */
/* L220: */
	}
	yloc -= yincr;
/*  next thisln */
/* L200: */
    }
#ifndef NO_PROTO
    dchpfv_("MODELLING CLIPPING OF POLYMARKER: On which line is there NOT ex"
	    "actly one enclosing box for each marker?", &c__8, &ngline, 103L);
#else /* NO_PROTO */
    dchpfv_("MODELLING CLIPPING OF POLYMARKER: On which line is there NOT ex\
actly one enclosing box for each marker?", &c__8, &ngline, 103L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

