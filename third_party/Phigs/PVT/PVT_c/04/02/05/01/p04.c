/* fort/04/02/05/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b27 = .13f;
#else /* NO_PROTO */
static real c_b27 = (float).13;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b30 = .06f;
static real c_b31 = .12f;
static real c_b32 = .04f;
static real c_b33 = .08f;
#else /* NO_PROTO */
static real c_b30 = (float).06;
static real c_b31 = (float).12;
static real c_b32 = (float).04;
static real c_b33 = (float).08;
#endif /* NO_PROTO */
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b75 = -2.f;
static real c_b76 = 2.f;
static real c_b79 = 15.f;
static real c_b80 = 40.f;
#else /* NO_PROTO */
static real c_b75 = (float)-2.;
static real c_b76 = (float)2.;
static real c_b79 = (float)15.;
static real c_b80 = (float)40.;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b115 = -5.f;
static real c_b116 = 5.f;
static real c_b141 = 0.f;
#else /* NO_PROTO */
static real c_b115 = (float)-5.;
static real c_b116 = (float)5.;
static real c_b141 = (float)0.;
#endif /* NO_PROTO */
static integer c_n1 = -1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.01/04                        * */
/*  *    TEST TITLE : Appearance of individual geometric    * */
/*  *                 attributes                            * */
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
    double tan(doublereal), cos(doublereal), sin(doublereal);
    integer i_nint(real *);
#else /* NO_PROTO */
    double tan(), cos(), sin();
    integer i_nint();
#endif /* NO_PROTO */

    /* Local variables */
    static real a, b, c, d, x1, y1, id[16]	/* was [4][4] */, xa[5], ya[5]
	    , za[5], cx, xf[16]	/* was [4][4] */, cy;
    static integer ix, iy, jx, jy;
    static real vl, rx, ry, rz, ang;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */
    static real vec[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static real xla[5], enx, eny, rcx, rcy;
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern logical dyn_();
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer siz;
    static real fac1, fac2, stx, sty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa3 ();
#endif /* NO_PROTO */
    static integer col1;
#ifndef NO_PROTO
    extern integer mod1_(integer *, integer *);
#else /* NO_PROTO */
    extern integer mod1_();
#endif /* NO_PROTO */
    static real exp1, exp2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntr3 (real *, real *, real *, integer *, real 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntr3 ();
#endif /* NO_PROTO */
    static integer fcol;
#ifndef NO_PROTO
    extern doublereal rnd01_(void), vecl_(real *, real *, real *);
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern doublereal rnd01_(), vecl_();
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer perm[10];
    static real dist, yloc;
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspa (real *, real *), nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspa (), nsep ();
#endif /* NO_PROTO */
    static real xval, yval, patx[10], ybot, paty[10], xorg;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsis (integer *), nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsis (), nsln ();
#endif /* NO_PROTO */
    static integer npts[1];
    static real rcxx, rcyy, ytop, cel1x, cel1y, cel2x, cel2y;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 ();
#endif /* NO_PROTO */
    static integer colia[4]	/* was [2][2] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_();
#endif /* NO_PROTO */
    static integer ngpat;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int nspar (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nsisi (integer *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int nspar (), nsisi ();
#endif /* NO_PROTO */
    static real rfvcx[2], rfvcy[2], rfvcz[2], rvcvl[30]	/* was [6][5] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int parpt_(real *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, integer *,
	     integer *), nopst (integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int parpt_(), nopst (), nsvwi ();
#endif /* NO_PROTO */
    static integer en1inc, en2inc, st1inc, st2inc;
    static real patsz1, patsz2, prvc1x, prvc1y, prvc1z, prvc2x, prvc2y;
    static integer bcolia[6]	/* was [3][2] */;
    static real prvc2z;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt3 (real *, integer *), cldiag_(real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *);
    extern integer ceilng_(real *);
    extern /* Subroutine */ int ndellb (integer *, integer *);
    extern doublereal vecang_(real *, real *, real *, real *, real *, real *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt3 (), cldiag_();
    extern integer ceilng_();
    extern /* Subroutine */ int ndellb ();
    extern doublereal vecang_();
#endif /* NO_PROTO */
    static real npcang, tanang;
    static integer wcolia[6]	/* was [3][2] */;
    static real cosang;
#ifndef NO_PROTO
    extern /* Subroutine */ int numlab_(integer *, real *, real *, real *), 
	    setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static real celszx, celszy, refptx, refpty, refptz;
#ifndef NO_PROTO
    extern logical patavl_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), setval_(char *, integer *, ftnlen)
	    , setmsg_(char *, char *, ftnlen, ftnlen), setrvs_(char *, real *,
	     integer *, ftnlen), dchpfv_(char *, integer *, integer *, ftnlen)
	    , rnperm_(integer *, integer *), nsprpv (real *, real *, real *, 
	    real *, real *, real *), nsparf (real *, real *), discol_(integer 
	    *, integer *, integer *), pervec_(real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *), ptplds_(real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), lintpt_(real *, real *, real *, real *, real *, real *, 
	    real *, real *), nsplci (integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern logical patavl_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), setval_(), 
	    setmsg_(), setrvs_(), dchpfv_(), rnperm_(), nsprpv (), nsparf (), 
	    discol_(), pervec_(), ptplds_(), lintpt_(), nsplci (), chkinq_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* interior style */
/* linetype */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    initgl_("04.02.05.01/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    if (! patavl_(&dialog_1.specwt)) {
/*  pattern is unavailable */
#ifndef NO_PROTO
	inmsg_("Skipping tests of geometric attributes, since these apply on"
		"ly to pattern interior style, which is unavailable.", 111L);
#else /* NO_PROTO */
	inmsg_("Skipping tests of geometric attributes, since these apply on\
ly to pattern interior style, which is unavailable.", 111L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  pattern is available */
/* L30: */
    if (dyn_("Does this workstation support transformable patterns?", 53L)) {
/*        keep going */
    } else {
#ifndef NO_PROTO
	inmsg_("Skipping tests of geometric attributes, since their effect i"
		"s predictable only for transformable patterns, which are una"
		"vailable.", 129L);
#else /* NO_PROTO */
	inmsg_("Skipping tests of geometric attributes, since their effect i\
s predictable only for transformable patterns, which are unavailable.", 129L);

#endif /* NO_PROTO */
	goto L666;
    }
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*                                                      --------- */
/*                                                      | 0 | 1 | */
/*  set up simple checkerboard pattern representation   |---+---| */
/*    as entry #1, for use throughout:                  | 1 | 0 | */
/*                                                      --------- */
    setval_("0,1,1,0", colia, 7L);
    nspar (&globnu_1.wkid, &c__1, &c__2, &c__2, &c__1, &c__1, &c__2, &c__2, 
	    colia);
    nsis (&c__2);
    nsisi (&c__1);
/*  mark start of variable part of structure */
    nlb (&c__1);

/*  *** *** *** ***   pattern size   *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("3 4 61 62 71 72 73 74 75 76 77 78 79", "The lengths of the side"
	    "s of the pattern box should equal the magnitudes of the pattern "
	    "size attribute of a fill area or fill area set primitive.", 36L, 
	    144L);
#else /* NO_PROTO */
    setmsg_("3 4 61 62 71 72 73 74 75 76 77 78 79", "The lengths of the side\
s of the pattern box should equal the magnitudes of the pattern size attribu\
te of a fill area or fill area set primitive.", 36L, 144L);
#endif /* NO_PROTO */
/*  ngpat = random integer from 1 to 5 */
    ngpat = rndint_(&c__1, &c__5);
#ifndef NO_PROTO
    yincr = .16666666666666666f;
#else /* NO_PROTO */
    yincr = (float).16666666666666666;
#endif /* NO_PROTO */
    yloc = 1 - yincr;
    npts[0] = 4;
    setrvs_("0.3,0.3,0.8,0.8", xa, &ix, 15L);
    numlab_(&c__5, &c_b27, &yloc, &yincr);
    nsln (&c__3);
    for (ix = 1; ix <= 5; ++ix) {
/*  pick a pattern size */
	patsz1 = rndrl_(&c_b30, &c_b31);
	patsz2 = rndrl_(&c_b32, &c_b33);
/*  only the magnitude should matter */
#ifndef NO_PROTO
	if (rnd01_() < .5f) {
#else /* NO_PROTO */
	if (rnd01_() < (float).5) {
#endif /* NO_PROTO */
	    patsz1 = -(doublereal)patsz1;
	}
#ifndef NO_PROTO
	if (rnd01_() < .5f) {
#else /* NO_PROTO */
	if (rnd01_() < (float).5) {
#endif /* NO_PROTO */
	    patsz2 = -(doublereal)patsz2;
	}
/*  exp1,exp2 = expected cell size = patsz1,patsz2 / 2 */
	exp1 = (r__1 = patsz1 / 2, dabs(r__1));
	exp2 = (r__1 = patsz2 / 2, dabs(r__1));
	if (ix == ngpat) {
#ifndef NO_PROTO
	    if (exp1 < .1f) {
		exp1 *= 1.2f;
#else /* NO_PROTO */
	    if (exp1 < (float).1) {
		exp1 *= (float)1.2;
#endif /* NO_PROTO */
	    } else {
#ifndef NO_PROTO
		exp1 *= .8f;
#else /* NO_PROTO */
		exp1 *= (float).8;
#endif /* NO_PROTO */
	    }
	}
#ifndef NO_PROTO
	ytop = yloc + yincr * .3f;
	ybot = yloc - yincr * .3f;
#else /* NO_PROTO */
	ytop = yloc + yincr * (float).3;
	ybot = yloc - yincr * (float).3;
#endif /* NO_PROTO */
/*  draw expected boundaries of pattern cells, */
/*  using dotted polylines */
#ifndef NO_PROTO
	ya[0] = yloc + yincr * .45f;
	ya[1] = yloc - yincr * .45f;
#else /* NO_PROTO */
	ya[0] = yloc + yincr * (float).45;
	ya[1] = yloc - yincr * (float).45;
#endif /* NO_PROTO */
/*  assume reference point = 0,0 */
#ifndef NO_PROTO
	r__1 = .3f / exp1;
#else /* NO_PROTO */
	r__1 = (float).3 / exp1;
#endif /* NO_PROTO */
	x1 = ceilng_(&r__1) * exp1;
	r__1 = exp1;
#ifndef NO_PROTO
	for (xval = x1; r__1 < 0 ? xval >= .8f : xval <= .8f; xval += r__1) {
#else /* NO_PROTO */
	for (xval = x1; r__1 < 0 ? xval >= (float).8 : xval <= (float).8; 
		xval += r__1) {
#endif /* NO_PROTO */
	    xla[0] = xval;
	    xla[1] = xval;
	    npl (&c__2, xla, ya);
/* L110: */
	}
#ifndef NO_PROTO
	xla[0] = .2f;
	xla[1] = .9f;
#else /* NO_PROTO */
	xla[0] = (float).2;
	xla[1] = (float).9;
#endif /* NO_PROTO */
/*  assume reference point = 0,0 */
	r__1 = ybot / exp2;
	y1 = ceilng_(&r__1) * exp2;
	r__1 = ytop;
	r__2 = exp2;
	for (yval = y1; r__2 < 0 ? yval >= r__1 : yval <= r__1; yval += r__2) 
		{
	    ya[0] = yval;
	    ya[1] = yval;
	    npl (&c__2, xla, ya);
/* L120: */
	}
/*  draw fill area or fill area set with actual pattern size */
	nspa (&patsz1, &patsz2);
	ya[0] = ytop;
	ya[1] = ybot;
	ya[2] = ya[1];
	ya[3] = ya[0];
#ifndef NO_PROTO
	if (rnd01_() < .5f) {
#else /* NO_PROTO */
	if (rnd01_() < (float).5) {
#endif /* NO_PROTO */
	    nfa (&c__4, xa, ya);
	} else {
	    nfas (&c__1, npts, xa, ya);
	}
	yloc -= yincr;
/* L100: */
    }
/*  mark end of variable part fo structure */
    nlb (&c__2);
#ifndef NO_PROTO
    dchpfv_("ACCURACY OF PATTERN SIZE: For which rectangle are the dotted li"
	    "nes NOT aligned with cell boundaries?", &c__5, &ngpat, 100L);
#else /* NO_PROTO */
    dchpfv_("ACCURACY OF PATTERN SIZE: For which rectangle are the dotted li\
nes NOT aligned with cell boundaries?", &c__5, &ngpat, 100L);
#endif /* NO_PROTO */
/*  clear out structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 61 63 71 72 73 74 75 76 77 78 79", "A degenerate value in a"
	    " pattern size element (either component zero) should not affect "
	    "the traversal state list, nor the value bound to fill area primi"
	    "tives.", 36L, 157L);
#else /* NO_PROTO */
    setmsg_("3 4 61 63 71 72 73 74 75 76 77 78 79", "A degenerate value in a\
 pattern size element (either component zero) should not affect the traversa\
l state list, nor the value bound to fill area primitives.", 36L, 157L);
#endif /* NO_PROTO */
/*  set perm to randomize positions of primitives */
    rnperm_(&c__5, perm);
/*  set up zeros in initial pattern size arrays */
    setrvs_(".0,.0,.0,.0,.0", patx, &ix, 14L);
    setrvs_(".0,.0,.0,.0,.0", paty, &ix, 14L);
/*  set reasonable default pattern size */
    patsz1 = rndrl_(&c_b33, &c_b31);
    patsz2 = rndrl_(&c_b30, &c_b33);
/*  set values for pattern size - only 1st and 5th should take effect */
    patx[0] = patsz1;
    paty[0] = patsz2;
    paty[1] = patsz2 * -2;
    patx[2] = patsz1 * 3;
#ifndef NO_PROTO
    patx[4] = patsz1 * 1.2f;
    paty[4] = patsz2 * .8f;
    yincr = .16666666666666666f;
#else /* NO_PROTO */
    patx[4] = patsz1 * (float)1.2;
    paty[4] = patsz2 * (float).8;
    yincr = (float).16666666666666666;
#endif /* NO_PROTO */
    yloc = 1 - yincr;
    npts[0] = 4;
    setrvs_("0.3,0.3,0.8,0.8", xa, &ix, 15L);
    numlab_(&c__5, &c_b27, &yloc, &yincr);
    for (ix = 1; ix <= 5; ++ix) {
#ifndef NO_PROTO
	yloc = 1.f - perm[ix - 1] / 6.f;
	ytop = yloc + yincr * .3f;
	ybot = yloc - yincr * .3f;
#else /* NO_PROTO */
	yloc = (float)1. - perm[ix - 1] / (float)6.;
	ytop = yloc + yincr * (float).3;
	ybot = yloc - yincr * (float).3;
#endif /* NO_PROTO */
/*  draw fill area or fill area set with actual pattern size */
	nspa (&patx[ix - 1], &paty[ix - 1]);
	ya[0] = ytop;
	ya[1] = ybot;
	ya[2] = ya[1];
	ya[3] = ya[0];
#ifndef NO_PROTO
	if (rnd01_() < .5f) {
#else /* NO_PROTO */
	if (rnd01_() < (float).5) {
#endif /* NO_PROTO */
	    nfa (&c__4, xa, ya);
	} else {
	    nfas (&c__1, npts, xa, ya);
	}
/* L200: */
    }
#ifndef NO_PROTO
    dchpfv_("DEGENERATE PATTERN SIZE: Which rectangle has a different patter"
	    "n size?", &c__5, &perm[4], 70L);
#else /* NO_PROTO */
    dchpfv_("DEGENERATE PATTERN SIZE: Which rectangle has a different patter\
n size?", &c__5, &perm[4], 70L);
#endif /* NO_PROTO */
/*  clear out structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 67 69 71 72 73 74 75 76 77 78 79", "<Set pattern reference "
	    "point> should set the x-y values of the reference point as speci"
	    "fied, the z-value to zero, and the pattern reference vectors to "
	    "(1,0,0) and (0,1,0).", 36L, 171L);
#else /* NO_PROTO */
    setmsg_("3 4 67 69 71 72 73 74 75 76 77 78 79", "<Set pattern reference \
point> should set the x-y values of the reference point as specified, the z-\
value to zero, and the pattern reference vectors to (1,0,0) and (0,1,0).", 
	    36L, 171L);
#endif /* NO_PROTO */
/*  ngpat = random integer from 1 to 5 */
    ngpat = rndint_(&c__1, &c__5);
/*  set pattern size */
#ifndef NO_PROTO
    patsz1 = .15f;
    patsz2 = .08f;
#else /* NO_PROTO */
    patsz1 = (float).15;
    patsz2 = (float).08;
#endif /* NO_PROTO */
    nspa (&patsz1, &patsz2);
#ifndef NO_PROTO
    yincr = .16666666666666666f;
#else /* NO_PROTO */
    yincr = (float).16666666666666666;
#endif /* NO_PROTO */
    yloc = 1 - yincr;
    npts[0] = 4;
    setrvs_("0.3,0.3,0.8,0.8", xa, &ix, 15L);
    numlab_(&c__5, &c_b27, &yloc, &yincr);
    nsln (&c__3);
    for (ix = 1; ix <= 5; ++ix) {
/*  set up reference point values: */
	refptx = rndrl_(&c_b75, &c_b76);
	refpty = rndrl_(&c_b75, &c_b76);
/*  rvec1, rvec2 always = (1,0,0), (0,1,0) */
/*  ang = angle of rotation around axis (x=0, z=zoff) for fill area pl
ane */
/*      = random from within [15deg, 40deg] */
#ifndef NO_PROTO
	ang = rndrl_(&c_b79, &c_b80) * 3.14159265f / 180;
#else /* NO_PROTO */
	ang = rndrl_(&c_b79, &c_b80) * (float)3.14159265 / 180;
#endif /* NO_PROTO */
	tanang = tan(ang);
	cosang = cos(ang);
/*  Note relation among ZOFF, ANG and right edge of fillarea (= 0.8). 
*/
/*  In order to keep right edge within unit cube of NPC, must ensure 
*/
/*  that ZOFF .le. 1 - 0.8*TANANG.  This is satisfied for ZOFF=0.2 */
/*  and ANG .le. 40 degrees. */
/*  celsz = size of cell */
	celszx = patsz1 / 2;
	celszy = patsz2 / 2;
/*  <set pattern reference point and vectors> to */
/*     refptx, refpty + celszy/2, celszx / (2 * sin(ang)); */
/*         (if left in effect, this positions box boundary in */
/*          x-dimension exactly halfway from correct boundary; this */

/*          will be conspicuously wrong if not overridden by <set */
/*          pattern reference point>.) */
/*     vec1, vec2 = = random from within [-2,2] */
	for (iy = 1; iy <= 6; ++iy) {
	    vec[iy - 1] = rndrl_(&c_b75, &c_b76);
/* L310: */
	}
	r__2 = refpty + celszy / 2;
	r__1 = celszx / (sin(ang) * 2);
	nsprpv (&refptx, &r__2, &r__1, vec, &vec[2], &vec[4]);
/*  exp1,exp2 = expected cell size as projected on to NPC plane */
	exp1 = (r__2 = celszx * cosang, dabs(r__2));
	exp2 = dabs(celszy);
/*  set up incorrect EXP1 for NGPAT */
	if (ix == ngpat) {
#ifndef NO_PROTO
	    if (exp1 < .1f) {
		exp1 *= 1.2f;
#else /* NO_PROTO */
	    if (exp1 < (float).1) {
		exp1 *= (float)1.2;
#endif /* NO_PROTO */
	    } else {
#ifndef NO_PROTO
		exp1 *= .8f;
#else /* NO_PROTO */
		exp1 *= (float).8;
#endif /* NO_PROTO */
	    }
	}
/*  draw expected boundaries of pattern cells, based on exp1 */
/*    and exp2, using dotted polylines */
#ifndef NO_PROTO
	ya[0] = yloc + yincr * .45f;
	ya[1] = yloc - yincr * .45f;
#else /* NO_PROTO */
	ya[0] = yloc + yincr * (float).45;
	ya[1] = yloc - yincr * (float).45;
#endif /* NO_PROTO */
/*  assume reference point = refptx,refpty,0 fill area plane = */
/*  rotated by ANG around axis.  Axis: (x=0, z=ZOFF) */
/*  x-location in NPC of reference point after projection onto */
/*  fill area plane. */
/* Computing 2nd power */
	r__2 = cosang;
#ifndef NO_PROTO
	xorg = r__2 * r__2 * (refptx - tanang * .2f);
#else /* NO_PROTO */
	xorg = r__2 * r__2 * (refptx - tanang * (float).2);
#endif /* NO_PROTO */
/*  x-location of first cell boundary in range of fill area */
#ifndef NO_PROTO
	r__2 = (.3f - xorg) / exp1;
#else /* NO_PROTO */
	r__2 = ((float).3 - xorg) / exp1;
#endif /* NO_PROTO */
	x1 = xorg + ceilng_(&r__2) * exp1;
	r__2 = exp1;
#ifndef NO_PROTO
	for (xval = x1; r__2 < 0 ? xval >= .8f : xval <= .8f; xval += r__2) {
#else /* NO_PROTO */
	for (xval = x1; r__2 < 0 ? xval >= (float).8 : xval <= (float).8; 
		xval += r__2) {
#endif /* NO_PROTO */
	    xla[0] = xval;
	    xla[1] = xval;
	    npl (&c__2, xla, ya);
/* L3110: */
	}
#ifndef NO_PROTO
	xla[0] = .2f;
	xla[1] = .9f;
	ytop = yloc + yincr * .3f;
	ybot = yloc - yincr * .3f;
#else /* NO_PROTO */
	xla[0] = (float).2;
	xla[1] = (float).9;
	ytop = yloc + yincr * (float).3;
	ybot = yloc - yincr * (float).3;
#endif /* NO_PROTO */
/*  assume reference point = refptx,refpty,0 */
/*  y-location of first cell boundary in range of fill area */
	r__2 = (ybot - refpty) / exp2;
	y1 = refpty + ceilng_(&r__2) * exp2;
	r__2 = ytop;
	r__1 = exp2;
	for (yval = y1; r__1 < 0 ? yval >= r__2 : yval <= r__2; yval += r__1) 
		{
	    ya[0] = yval;
	    ya[1] = yval;
	    npl (&c__2, xla, ya);
/* L3120: */
	}
/*  set up z-values based on ang: this rotates fill area plane */
/*  around axis.  Axis: (x=0, z=ZOFF) */
#ifndef NO_PROTO
	za[0] = xa[0] * tanang + .2f;
#else /* NO_PROTO */
	za[0] = xa[0] * tanang + (float).2;
#endif /* NO_PROTO */
	za[1] = za[0];
#ifndef NO_PROTO
	za[2] = xa[2] * tanang + .2f;
#else /* NO_PROTO */
	za[2] = xa[2] * tanang + (float).2;
#endif /* NO_PROTO */
	za[3] = za[2];
/*  <set pattern reference point> to refptx, refpty */
	nsparf (&refptx, &refpty);
/*  draw fill area or fill area set #ix */
	ya[0] = ytop;
	ya[1] = ybot;
	ya[2] = ya[1];
	ya[3] = ya[0];
#ifndef NO_PROTO
	if (rnd01_() < .5f) {
#else /* NO_PROTO */
	if (rnd01_() < (float).5) {
#endif /* NO_PROTO */
	    nfa3 (&c__4, xa, ya, za);
	} else {
	    nfas3 (&c__1, npts, xa, ya, za);
	}
	yloc -= yincr;
/* L300: */
    }
#ifndef NO_PROTO
    dchpfv_("EFFECT OF SET PATTERN REFERENCE POINT: For which rectangle are "
	    "the dotted lines NOT aligned with cell boundaries?", &c__5, &
	    ngpat, 113L);
#else /* NO_PROTO */
    dchpfv_("EFFECT OF SET PATTERN REFERENCE POINT: For which rectangle are \
the dotted lines NOT aligned with cell boundaries?", &c__5, &ngpat, 113L);
#endif /* NO_PROTO */
/*  clear out structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  *** *** ***   pattern reference point and vectors   *** *** *** */
#ifndef NO_PROTO
    setmsg_("3 4 66 68 71 72 73 74 75 76 77 78 79", "The geometric attribute"
	    "s pattern size, pattern reference point, and pattern reference v"
	    "ectors should determine the location of colored pattern cells wi"
	    "thin fill area and fill area set primitives.", 36L, 195L);
#else /* NO_PROTO */
    setmsg_("3 4 66 68 71 72 73 74 75 76 77 78 79", "The geometric attribute\
s pattern size, pattern reference point, and pattern reference vectors shoul\
d determine the location of colored pattern cells within fill area and fill \
area set primitives.", 36L, 195L);
#endif /* NO_PROTO */
/*  ngpat = no-good pattern: random integer from 1 to 5 */
    ngpat = rndint_(&c__1, &c__5);
#ifndef NO_PROTO
    yincr = .16666666666666666f;
#else /* NO_PROTO */
    yincr = (float).16666666666666666;
#endif /* NO_PROTO */
/*  yloc = midpoint for next rectangle */
    yloc = 1 - yincr;
    npts[0] = 4;
/*  xleft,xright = left,right MC edges of rectangle = -.1, +.1 */
    setrvs_("-0.1,-0.1, 0.1,0.1", xa, &ix, 18L);
    numlab_(&c__5, &c_b27, &yloc, &yincr);
/*  set up PSIZ1 x PSIZ2 pattern representation as index #1, using as many
 */
/*  distinct colors as available (try for all distinct). */
    discol_(&c__6, &globnu_1.wkid, &fcol);
    col1 = 1;
    for (ix = 1; ix <= 3; ++ix) {
	for (iy = 1; iy <= 2; ++iy) {
	    bcolia[ix + iy * 3 - 4] = col1;
	    col1 = (col1 + 1) % (fcol + 1);
/* L420: */
	}
/* L410: */
    }
    nspar (&globnu_1.wkid, &c__1, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, 
	    bcolia);
    idmat_(&c__4, id);
/*  loop to create 5 patterned fill areas, with simulated cells */
    for (ix = 1; ix <= 5; ++ix) {
/*  pick_coeff: */
L451:
/*     a,b,c = first three coefficients for equation of fill area plan
e */
/*           = random from within [-5,5] */
/*     fill area plane: a*x + b*y + c*z + d = 0 */
	a = rndrl_(&c_b115, &c_b116);
	b = rndrl_(&c_b115, &c_b116);
	c = rndrl_(&c_b115, &c_b116);
/*  make sure not too oblique */
#ifndef NO_PROTO
	if (dabs(c) < 1e-4f || dabs(c) < dabs(a) || dabs(c) < dabs(b)) {
#else /* NO_PROTO */
	if (dabs(c) < (float)1e-4 || dabs(c) < dabs(a) || dabs(c) < dabs(b)) {

#endif /* NO_PROTO */
	    goto L451;
	}
/*  calculate d such that rectangle MC center (0,yloc,.5) is */
/*  contained in plane */
#ifndef NO_PROTO
	d = -(doublereal)(b * yloc + c * .5f);
#else /* NO_PROTO */
	d = -(doublereal)(b * yloc + c * (float).5);
#endif /* NO_PROTO */
/*  MC rectangle coordinates are: x: -1. : +.1 */
/*                                y: yloc + or - 0.4*yincr */
#ifndef NO_PROTO
	ybot = yloc - yincr * .4f;
	ytop = yloc + yincr * .4f;
#else /* NO_PROTO */
	ybot = yloc - yincr * (float).4;
	ytop = yloc + yincr * (float).4;
#endif /* NO_PROTO */
	ya[0] = ytop;
	ya[1] = ybot;
	ya[2] = ybot;
	ya[3] = ytop;
/*  set up z-values based on a,b,c,d plane coefficients */
	for (iy = 1; iy <= 4; ++iy) {
	    za[iy - 1] = -(doublereal)(a * xa[iy - 1] + b * ya[iy - 1] + d) / 
		    c;
/*  if (z-values of corners of rectangle not within [0,1]) then */

/*     plane too oblique, pick new coefficients */
#ifndef NO_PROTO
	    if (za[iy - 1] <= 0.f || za[iy - 1] >= 1.f) {
#else /* NO_PROTO */
	    if (za[iy - 1] <= (float)0. || za[iy - 1] >= (float)1.) {
#endif /* NO_PROTO */
		goto L451;
	    }
/* L455: */
	}
/*  refptx,refpty,refptz = random reference point */
	refptx = rndrl_(&c_b75, &c_b76);
	refpty = rndrl_(&c_b75, &c_b76);
	refptz = rndrl_(&c_b75, &c_b76);
/*  pick_vecs: 2 random reference vectors */
L460:
	rfvcx[0] = rndrl_(&c_b75, &c_b76);
	rfvcy[0] = rndrl_(&c_b75, &c_b76);
	rfvcz[0] = rndrl_(&c_b75, &c_b76);
	rfvcx[1] = rndrl_(&c_b75, &c_b76);
	rfvcy[1] = rndrl_(&c_b75, &c_b76);
	rfvcz[1] = rndrl_(&c_b75, &c_b76);
/*  calculate shape of WC cell, based on vectors rfvc1, rfvc2 projecte
d */
/*  on to fill area plane, and then onto NPC. */
/*  project reference vectors on to fill area plane */
	pervec_(&a, &b, &c, rfvcx, rfvcy, rfvcz, &prvc1x, &prvc1y, &prvc1z);
	pervec_(&a, &b, &c, &rfvcx[1], &rfvcy[1], &rfvcz[1], &prvc2x, &prvc2y,
		 &prvc2z);
/*  if shape not rectangular enough (angle projected into NPC < 55deg,
 */
/*     ignoring z-coordinate) */
/*  then goto pick_vecs */
	npcang = vecang_(&prvc1x, &prvc1y, &c_b141, &prvc2x, &prvc2y, &c_b141)
#ifndef NO_PROTO
		 * 180 / 3.14159265f;
	if (npcang < 55.f || npcang > 125.f) {
#else /* NO_PROTO */
		 * 180 / (float)3.14159265;
	if (npcang < (float)55. || npcang > (float)125.) {
#endif /* NO_PROTO */
	    goto L460;
	}
/*  calculate patsz1,patsz2 so as to make cell size visible */
#ifndef NO_PROTO
	patsz1 = vecl_(&prvc1x, &prvc1y, &prvc1z) * .05f / vecl_(&prvc1x, &
		prvc1y, &c_b141);
	patsz2 = vecl_(&prvc2x, &prvc2y, &prvc2z) * .05f / vecl_(&prvc2x, &
		prvc2y, &c_b141);
#else /* NO_PROTO */
	patsz1 = vecl_(&prvc1x, &prvc1y, &prvc1z) * (float).05 / vecl_(&
		prvc1x, &prvc1y, &c_b141);
	patsz2 = vecl_(&prvc2x, &prvc2y, &prvc2z) * (float).05 / vecl_(&
		prvc2x, &prvc2y, &c_b141);
#endif /* NO_PROTO */
/*  <set pattern size> to patsz1,patsz2 */
	nspa (&patsz1, &patsz2);
/*  <set pattern reference point and vectors> */
	nsprpv (&refptx, &refpty, &refptz, rfvcx, rfvcy, rfvcz);
/*  <set local modelling transform> such that in x, -.1,+.1 maps */
/*        to .4,.8) at z=1, and in y, yloc maps to yloc at z=0.5: */

/*          2   0  0   0.6                x' = (2x + .6/w */
/*          0   1  0   yloc/4   yields    y' =  (y + yloc/4)/w */
/*          0   0  1   0                  z' =  z/w */
/*          0   0 -0.5 1.5                w  = (3-z)/2 */
	setrvs_("2,0,0,0, 0,1,0,0, 0,0,1,-0.5, 0.6,0,0,1.5", xf, &siz, 41L);
	xf[13] = yloc / 4;
	nslmt3 (xf, &c__2);
/*  draw fill area or fill area set #ix */
	if (ix % 2 == 0) {
	    nfas3 (&c__1, npts, xa, ya, za);
	} else {
	    nfa3 (&c__4, xa, ya, za);
	}
/*  <set local modelling transform> back to identity */
	nslmt3 (id, &c__2);
/*  Now for simulation: calculate WC location and color of expected */

/*  cells, based on refpt, rfvc, patsz, and transformation. */

/*  First, in MC, get projected reference vectors adjusted to */
/*  pattern size = pattern width and height vectors */
	vl = vecl_(&prvc1x, &prvc1y, &prvc1z);
	prvc1x = prvc1x * patsz1 / vl;
	prvc1y = prvc1y * patsz1 / vl;
	prvc1z = prvc1z * patsz1 / vl;
	vl = vecl_(&prvc2x, &prvc2y, &prvc2z);
	prvc2x = prvc2x * patsz2 / vl;
	prvc2y = prvc2y * patsz2 / vl;
	prvc2z = prvc2z * patsz2 / vl;
/*  project reference point on to fill area plane */
	ptplds_(&refptx, &refpty, &refptz, &a, &b, &c, &d, &rx, &ry, &rz, &
		dist);
/*  center of rectangle in MC */
	cx = (xa[0] + xa[2]) / 2;
	cy = (ya[0] + ya[2]) / 2;
/*  fac1,fac2 are the number of times vec1 and vec2 have to be added t
o */
/*  rx,ry to get to center of rectangle. */
	r__1 = rx - cx;
	r__2 = ry - cy;
	lintpt_(&prvc1x, &prvc2x, &r__1, &prvc1y, &prvc2y, &r__2, &fac1, &
		fac2);
/*  find a "reference point" near middle of rectangle by adding integr
al */
/*  number of vec1 and vec2. */
	rcx = rx + i_nint(&fac1) * prvc1x + i_nint(&fac2) * prvc2x;
	rcy = ry + i_nint(&fac1) * prvc1y + i_nint(&fac2) * prvc2y;
/*  Idea here is to construct smallest parallelogram which contains */

/*  rectangle (fill area) and whose corners are valid reference */
/*  points, i.e. formed by adding integer multiples of reference */
/*  vectors to actual reference point. */
/*  get starting and ending corners */
	parpt_(&rcx, &rcy, &c_n1, &prvc1x, &prvc1y, &prvc2x, &prvc2y, xa, ya, 
		&stx, &sty, &st1inc, &st2inc);
	parpt_(&rcx, &rcy, &c__1, &prvc1x, &prvc1y, &prvc2x, &prvc2y, xa, ya, 
		&enx, &eny, &en1inc, &en2inc);
/*  working copy of color array */
	for (jx = 1; jx <= 3; ++jx) {
	    for (jy = 1; jy <= 2; ++jy) {
		wcolia[jx + jy * 3 - 4] = bcolia[jx + jy * 3 - 4];
/* L4201: */
	    }
/* L4101: */
	}
/*  if (ix = ngpat) then set up switching of colors for expected cells
 */
	if (ix == ngpat) {
	    wcolia[0] = bcolia[3];
	    wcolia[3] = bcolia[0];
	}
/*  cell increments (within pattern box) */
	cel1x = prvc1x / 3;
	cel1y = prvc1y / 3;
	cel2x = prvc2x / 2;
	cel2y = prvc2y / 2;
/*  Loop through potential pattern cells in MC from STX,STY to ENX,ENY
 */
	rcx = stx;
	rcy = sty;
	i__1 = (st1inc + en1inc + 1) * 3;
	for (jx = 1; jx <= i__1; ++jx) {
/*  start new "row" (along first vector) of parallelogram */
	    rcxx = rcx;
	    rcyy = rcy;
/*  Loop thru cells; RCXX,RCYY is "lower left" corner of current 
*/
/*  cell, in MC. */
	    i__2 = st2inc + en2inc + 1 << 1;
	    for (jy = 1; jy <= i__2; ++jy) {
		nsplci (&wcolia[mod1_(&jx, &c__3) + (3 - mod1_(&jy, &c__2)) * 
			3 - 4]);
/*  draw the two diagonals within cell */
		r__1 = rcxx + cel1x + cel2x;
		r__2 = rcyy + cel1y + cel2y;
		cldiag_(&rcxx, &rcyy, &r__1, &r__2, &a, &b, &c, &d, xa, ya, 
			xf);
		r__1 = rcxx + cel1x;
		r__2 = rcyy + cel1y;
		r__3 = rcxx + cel2x;
		r__4 = rcyy + cel2y;
		cldiag_(&r__1, &r__2, &r__3, &r__4, &a, &b, &c, &d, xa, ya, 
			xf);
/*  next pattern cell within this row: increment column within
 row */
		rcxx += cel2x;
		rcyy += cel2y;
/* L4520: */
	    }
/*  increment rcx,rcy to new row */
	    rcx += cel1x;
	    rcy += cel1y;
/* L4510: */
	}
	yloc -= yincr;
/*  next ix */
/* L450: */
    }
#ifndef NO_PROTO
    dchpfv_("EFFECT OF SET PATTERN REFERENCE POINT, VECTORS, AND SIZE: For w"
	    "hich rectangle are colored pattern cell diagonals visible?", &
	    c__5, &ngpat, 121L);
#else /* NO_PROTO */
    dchpfv_("EFFECT OF SET PATTERN REFERENCE POINT, VECTORS, AND SIZE: For w\
hich rectangle are colored pattern cell diagonals visible?", &c__5, &ngpat, 
	    121L);
#endif /* NO_PROTO */
/*  clear out structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 66 68 70 71 72 73 74 75 76 77 78 79", "Degenerate values in"
	    " the pattern reference vector (zero length or parallel) should n"
	    "ot affect the traversal state list, nor the value bound to fill "
	    "area primitives.", 39L, 164L);
#else /* NO_PROTO */
    setmsg_("3 4 66 68 70 71 72 73 74 75 76 77 78 79", "Degenerate values in\
 the pattern reference vector (zero length or parallel) should not affect th\
e traversal state list, nor the value bound to fill area primitives.", 39L, 
	    164L);
#endif /* NO_PROTO */
/*  set reasonable pattern size */
#ifndef NO_PROTO
    patsz1 = .05f;
    patsz2 = .05f;
#else /* NO_PROTO */
    patsz1 = (float).05;
    patsz2 = (float).05;
#endif /* NO_PROTO */
/*  <set pattern size> to patsz1,patsz2 */
    nspa (&patsz1, &patsz2);
/*  use 3x2 pattern from previous test; interior style index #1 */
/*  set perm to randomize positions of primitives */
    rnperm_(&c__5, perm);
/*  set up values for 5 pairs of reference vectors: original pair, */
/*    rfvc1,rfvc2 = (2.0, 2.0, 1.0), (-1.0, 3.0, -1.0) */
/*  vectors    values            comments */
/*  -------    ------            -------- */
/*    #1       rfvc1,rfvc2       valid entry */
/*    #2           0,rfvc1       zero length vector: no effect */
/*    #3       rfvc2,0           zero length vector: no effect */
/*    #4       5*rfvc1,rfvc1     parallel vectors: no effect */
/*    #5       rfvc2,rfvc1       valid entry, distinct from #1 */
#ifndef NO_PROTO
    setrvs_(" 2.0,  2.0,  1.0, -1.0, 3.0, -1.0,  0.0,  0.0,  0.0,  2.0, 2.0,"
	    "  1.0, -1.0,  3.0, -1.0,  0.0, 0.0,  0.0, 10.0, 10.0,  5.0,  2.0"
	    ", 2.0,  1.0, -1.0,  3.0, -1.0,  2.0, 2.0,  1.0", rvcvl, &siz, 
	    173L);
#else /* NO_PROTO */
    setrvs_(" 2.0,  2.0,  1.0, -1.0, 3.0, -1.0,  0.0,  0.0,  0.0,  2.0, 2.0,\
  1.0, -1.0,  3.0, -1.0,  0.0, 0.0,  0.0, 10.0, 10.0,  5.0,  2.0, 2.0,  1.0,\
 -1.0,  3.0, -1.0,  2.0, 2.0,  1.0", rvcvl, &siz, 173L);
#endif /* NO_PROTO */
/*  Re-locate fill areas by applying modelling transformation; thus */
/*  pattern reference point (in MC) will be constant.  Use previous */
/*  reference point. */
#ifndef NO_PROTO
    yincr = .16666666666666666f;
#else /* NO_PROTO */
    yincr = (float).16666666666666666;
#endif /* NO_PROTO */
    npts[0] = 4;
/*  untransformed location of fill area: */
    setrvs_(" 0.3,   0.3,   0.8,   0.8", xa, &ix, 25L);
    setrvs_("-0.05, +0.05, +0.05, -0.05", ya, &ix, 26L);
#ifndef NO_PROTO
    r__1 = 1.f - yincr;
#else /* NO_PROTO */
    r__1 = (float)1. - yincr;
#endif /* NO_PROTO */
    numlab_(&c__5, &c_b27, &r__1, &yincr);
    for (ix = 1; ix <= 5; ++ix) {
/*  set up reference vectors */
	rfvcx[0] = rvcvl[ix * 6 - 6];
	rfvcy[0] = rvcvl[ix * 6 - 5];
	rfvcz[0] = rvcvl[ix * 6 - 4];
	rfvcx[1] = rvcvl[ix * 6 - 3];
	rfvcy[1] = rvcvl[ix * 6 - 2];
	rfvcz[1] = rvcvl[ix * 6 - 1];
	nsprpv (&refptx, &refpty, &refptz, rfvcx, rfvcy, rfvcz);
#ifndef NO_PROTO
	yloc = 1.f - yincr * perm[ix - 1];
#else /* NO_PROTO */
	yloc = (float)1. - yincr * perm[ix - 1];
#endif /* NO_PROTO */
/*  shift up by YLOC */
	ntr3 (&c_b141, &yloc, &c_b141, &errind, xf);
	chkinq_("ptr3", &errind, 4L);
	nslmt3 (xf, &c__2);
/*  draw fill area or fill area set #ix */
	if (ix % 2 == 0) {
	    nfas (&c__1, npts, xa, ya);
	} else {
	    nfa (&c__4, xa, ya);
	}
/* L510: */
    }
#ifndef NO_PROTO
    dchpfv_("DEGENERATE PATTERN VECTORS: Which rectangle's pattern cells hav"
	    "e a different orientation?", &c__5, &perm[4], 89L);
#else /* NO_PROTO */
    dchpfv_("DEGENERATE PATTERN VECTORS: Which rectangle's pattern cells hav\
e a different orientation?", &c__5, &perm[4], 89L);
#endif /* NO_PROTO */
/*  endit: */
L666:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

