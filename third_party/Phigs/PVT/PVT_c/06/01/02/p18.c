/* fort/06/01/02/p18.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__10 = 10;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b24 = 1.f;
static real c_b25 = 0.f;
#else /* NO_PROTO */
static real c_b24 = (float)1.;
static real c_b25 = (float)0.;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b76 = .03f;
#else /* NO_PROTO */
static real c_b76 = (float).03;
#endif /* NO_PROTO */
static integer c__14 = 14;
static integer c__24 = 24;
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/18                           * */
/*  *    TEST TITLE : Modelling clipping for fill area,     * */
/*  *                 fill area set, and cell array         * */
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
    static char intlab[8*4] = "hollow. " "solid.  " "pattern." "hatch.  ";
    static char setlab[5] = " set ";
    static char setpr[5] = " SET:";
#else /* NO_PROTO */
    static char intlab[8*4+1] = "hollow. solid.  pattern.hatch.  ";
    static char setlab[5+1] = " set ";
    static char setpr[5+1] = " SET:";
#endif /* NO_PROTO */
    static integer colia[6]	/* was [3][2] */ = { 1,2,3,2,3,1 };
#ifndef NO_PROTO
    static real xp[14] = { .6f,.6f,.4f,.4f,.3f,.3f,.9f,.9f,.1f,.1f,.7f,.7f,
	    .1f,.1f };
    static real yp[14] = { .15f,.7f,.7f,0.f,0.f,.9f,.9f,.3f,.3f,.8f,.8f,.15f,
	    .15f,.3f };
#else /* NO_PROTO */
    static real xp[14] = { (float).6,(float).6,(float).4,(float).4,(float).3,(
	    float).3,(float).9,(float).9,(float).1,(float).1,(float).7,(float)
	    .7,(float).1,(float).1 };
    static real yp[14] = { (float).15,(float).7,(float).7,(float)0.,(float)0.,
	    (float).9,(float).9,(float).3,(float).3,(float).8,(float).8,(
	    float).15,(float).15,(float).3 };
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[6], a__2[5];
    integer i__1, i__2[6], i__3, i__4[5];
    real r__1;
    char ch__1[206], ch__2[147], ch__3[70];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real xf[16]	/* was [4][4] */;
    static integer ix, jx;
    static real zp[14], xt[30], yt[30];
    static integer vx[30];
    static real zt[30], aca, bca, cca, acl[3], bcl[3], ccl[3], dcl[3];
    static integer nfa;
    static real xca[3], yca[3], zca[3], xco, yco, zco, pqx, pqy, prx, pry;
#ifndef NO_PROTO
    extern /* Subroutine */ int nca3 (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nfa3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nca3 (), nfa3 ();
#endif /* NO_PROTO */
    static real mcv2[8]	/* was [4][2] */, mcv3[12]	/* was [6][2] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int win6_(integer *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int win6_();
#endif /* NO_PROTO */
    static integer anfa;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static real idxf[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static real xfas[30], yfas[30], zfas[30];
#ifndef NO_PROTO
    extern /* Subroutine */ int nspa (real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspa ();
#endif /* NO_PROTO */
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *), nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln (), nsis ();
#endif /* NO_PROTO */
    static real xexp[30], yexp[30], xsiz, ysiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_();
#endif /* NO_PROTO */
    static integer fasdx[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsici (integer *), exedv_(char *, real *, 
	    real *, ftnlen), nsedt (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsici (), exedv_(), nsedt ();
#endif /* NO_PROTO */
    static integer ngwin, wndex;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nspar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nsisi (integer *), nsmcv (integer *, integer *, real *
	    ), nemst (integer *), nexst (integer *), nopst (integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nspar (), nsisi (), nsmcv (), 
	    nemst (), nexst (), nopst (), setvs_(), nsvwi ();
#endif /* NO_PROTO */
    static integer vxsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *),
	     pt2cof_(real *, real *, real *, real *, real *, real *, real *), 
	    nsmcv3 (integer *, integer *, real *), arrtp3_(integer *, real *, 
	    real *, real *, real *, real *, real *, real *), nslmt3 (real *, 
	    integer *), faclip_(real *, real *, real *, real *, real *, real *
	    , real *, real *), denhat_(integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm3_(), pt2cof_(), nsmcv3 (), arrtp3_(), 
	    nslmt3 (), faclip_(), denhat_();
#endif /* NO_PROTO */
    static integer afasdx[3], lochar;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), setdlg_(
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, hatsty, numhat, ransty[6], ranwin[6], 
	    thiswn, numsty, intsty, primsw;
    static real xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer nstyus;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setasf_(
	    integer *), nsplci (integer *), lintpt_(real *, real *, real *, 
	    real *, real *, real *, real *, real *), nsedfg (integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), rnperm_(integer *, 
	    integer *), nsmcli (integer *), dchpfv_(char *, integer *, 
	    integer *, ftnlen), nsewsc (real *), nslwsc (real *), nsedci (
	    integer *), setrvs_(char *, real *, integer *, ftnlen), parcof_(
	    real *, real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setasf_(), nsplci (), lintpt_(), 
	    nsedfg (), setmsg_(), rnperm_(), nsmcli (), dchpfv_(), nsewsc (), 
	    nslwsc (), nsedci (), setrvs_(), parcof_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* interior style */
/* marker type    .         +        *       o         x */
/* linetype */
/* clipping indicator */
/*                noclip        cllip */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* modelling clipping operator */
/*                replace,      intersect */
/* off/on switch for edge flag and error handling mode */
/*  x,y, coordinates of fill area to be clipped */
    initgl_("06.01.02/18", 11L);
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
    nexst (&c__106);
    nsici (&c__1);
    nsplci (&c__3);
    nsln (&c__4);
    nexst (&c__102);
    nclst ();
/*  how many hatch and interior styles? */
    nqif (&dialog_1.specwt, &c__0, &c__0, &errind, &numsty, &idum1, &numhat, &
	    idum2, &idum3);
    chkinq_("pqif", &errind, 4L);
/*  hatsty = available hatch style */
    if (numhat > 0) {
	denhat_(&c__102, &c__10, &dialog_1.specwt, &hatsty);
    }
/*  list of interior styles, drawn from hollow,solid,hatch,pattern, */
/*  as available. */
    nstyus = 0;
    i__1 = numsty;
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (&dialog_1.specwt, &ix, &c__0, &errind, &idum1, &intsty, &idum2, 
		&idum3, &idum4);
	chkinq_("pqif", &errind, 4L);
	if (intsty >= 0 && intsty <= 3) {
	    ++nstyus;
	    ransty[nstyus - 1] = intsty;
	}
/* L100: */
    }
/*  set up identity matrix */
    idmat_(&c__4, idxf);
/*  Set up 6 windows on the screen */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
/*  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */

/*  the two 2D clipping planes are: */
/*     -0.45x + y - 0.07 = 0 */
/*     -0.8x  - y + 1.1  = 0 */
/*  clipping plane co-efficients (MC) */
#ifndef NO_PROTO
    acl[0] = -.45f;
    bcl[0] = 1.f;
    ccl[0] = 0.f;
    dcl[0] = -.07f;
    acl[1] = -.8f;
    bcl[1] = -1.f;
    ccl[1] = 0.f;
    dcl[1] = 1.1f;
#else /* NO_PROTO */
    acl[0] = (float)-.45;
    bcl[0] = (float)1.;
    ccl[0] = (float)0.;
    dcl[0] = (float)-.07;
    acl[1] = (float)-.8;
    bcl[1] = (float)-1.;
    ccl[1] = (float)0.;
    dcl[1] = (float)1.1;
#endif /* NO_PROTO */
/*  coefficients for line connecting first/last vertex: */
    pt2cof_(xp, yp, &xp[13], &yp[13], &acl[2], &bcl[2], &dcl[2]);
/*  2D MCV format for the two clipping planes (MC): */
    for (jx = 1; jx <= 2; ++jx) {
	mcv2[(jx << 2) - 4] = -(doublereal)dcl[jx - 1] / acl[jx - 1];
#ifndef NO_PROTO
	mcv2[(jx << 2) - 3] = 0.f;
#else /* NO_PROTO */
	mcv2[(jx << 2) - 3] = (float)0.;
#endif /* NO_PROTO */
	mcv2[(jx << 2) - 2] = acl[jx - 1];
	mcv2[(jx << 2) - 1] = bcl[jx - 1];
/* L190: */
    }
/*  expected vertices for fill area and fill area set: */
    setvs_("5,10,14,17,23,26", fasdx, &nfa, 16L);
/*  sub-area #1 */
    xexp[0] = xp[12];
    xexp[1] = xp[13];
    yexp[0] = yp[12];
    yexp[1] = yp[13];
    r__1 = -(doublereal)xp[4];
    lintpt_(&acl[2], &bcl[2], &dcl[2], &c_b24, &c_b25, &r__1, &xexp[2], &yexp[
	    2]);
    r__1 = -(doublereal)xp[4];
    lintpt_(acl, bcl, dcl, &c_b24, &c_b25, &r__1, &xexp[3], &yexp[3]);
    r__1 = -(doublereal)yp[12];
    lintpt_(acl, bcl, dcl, &c_b25, &c_b24, &r__1, &xexp[4], &yexp[4]);
/*  sub-area #2 */
    xexp[5] = xexp[2];
    yexp[5] = yexp[2];
    xexp[6] = xp[4];
    yexp[6] = yp[7];
    xexp[7] = xp[3];
    yexp[7] = yp[7];
    r__1 = -(doublereal)xp[3];
    lintpt_(acl, bcl, dcl, &c_b24, &c_b25, &r__1, &xexp[8], &yexp[8]);
    lintpt_(acl, bcl, dcl, &acl[2], &bcl[2], &dcl[2], &xexp[9], &yexp[9]);
/*  sub-area #3 */
    xexp[10] = xp[8];
    yexp[10] = yp[8];
    xexp[11] = xp[9];
    yexp[11] = yp[9];
    xexp[12] = xp[4];
    yexp[12] = yp[9];
    xexp[13] = xp[4];
    yexp[13] = yp[8];
/*  sub-area #4 */
    xexp[14] = xp[4];
    yexp[14] = yp[9];
    r__1 = -(doublereal)xp[4];
    lintpt_(&acl[1], &bcl[1], &dcl[1], &c_b24, &c_b25, &r__1, &xexp[15], &
	    yexp[15]);
    r__1 = -(doublereal)yp[9];
    lintpt_(&acl[1], &bcl[1], &dcl[1], &c_b25, &c_b24, &r__1, &xexp[16], &
	    yexp[16]);
/*  sub-area #5 */
    xexp[17] = xp[3];
    yexp[17] = yp[7];
    xexp[18] = xp[3];
    yexp[18] = yp[2];
    r__1 = -(doublereal)yp[2];
    lintpt_(&acl[1], &bcl[1], &dcl[1], &c_b25, &c_b24, &r__1, &xexp[19], &
	    yexp[19]);
    r__1 = -(doublereal)xp[0];
    lintpt_(&acl[1], &bcl[1], &dcl[1], &c_b24, &c_b25, &r__1, &xexp[20], &
	    yexp[20]);
    r__1 = -(doublereal)xp[0];
    lintpt_(acl, bcl, dcl, &c_b24, &c_b25, &r__1, &xexp[21], &yexp[21]);
    r__1 = -(doublereal)yp[7];
    lintpt_(acl, bcl, dcl, &c_b25, &c_b24, &r__1, &xexp[22], &yexp[22]);
/*  sub-area #6 */
    r__1 = -(doublereal)xp[10];
    lintpt_(acl, bcl, dcl, &c_b24, &c_b25, &r__1, &xexp[23], &yexp[23]);
    r__1 = -(doublereal)xp[10];
    lintpt_(&acl[1], &bcl[1], &dcl[1], &c_b24, &c_b25, &r__1, &xexp[24], &
	    yexp[24]);
    lintpt_(acl, bcl, dcl, &acl[1], &bcl[1], &dcl[1], &xexp[25], &yexp[25]);
/*  actual vertices for fill area set */
    setvs_("6,16,24", afasdx, &anfa, 7L);
/*  set most of the fill area set vertices directly to */
/*  fill area vertices */
    setvs_("4,5,5,14,13,12,1,8,8,7,6,6,10,9,9,5,11,12,3,3,2,8,5,5", vx, &
	    vxsiz, 53L);
    i__1 = vxsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	xfas[ix - 1] = xp[vx[ix - 1] - 1];
	yfas[ix - 1] = yp[vx[ix - 1] - 1];
/* L160: */
    }
/*  adjust sub-area #1 */
    r__1 = -(doublereal)xp[4];
    lintpt_(&acl[2], &bcl[2], &dcl[2], &c_b24, &c_b25, &r__1, &xfas[2], &yfas[
	    2]);
    xfas[5] = xp[3];
/*  adjust sub-area #2 */
    xfas[7] = xp[0];
    yfas[11] = yp[9];
    xfas[14] = xp[4];
    yfas[15] = yfas[2];
/*  adjust sub-area #3 */
    yfas[18] = yp[11];
    xfas[21] = xp[1];
    yfas[22] = yp[7];
    yfas[23] = yp[9];
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
/*  loop thru: */
/*    1. fill area / fill area set */
/*    2. interior styles */
/*    3. 6 windows */
    for (primsw = 1; primsw <= 2; ++primsw) {
	lochar = 9 - (primsw << 2);
/*  cycle thru non-empty interior styles */
	i__1 = nstyus;
	for (ix = 1; ix <= i__1; ++ix) {
	    intsty = ransty[ix - 1];
	    nsis (&intsty);
	    nsedfg (&c__0);
	    if (intsty == 0) {
/* Writing concatenation */
#ifndef NO_PROTO
		i__2[0] = 69, a__1[0] = "When the interior style is hollow, "
			"exactly those parts of a fill area";
#else /* NO_PROTO */
		i__2[0] = 69, a__1[0] = "When the interior style is hollow, \
exactly those parts of a fill area";
#endif /* NO_PROTO */
		i__2[1] = 5 - (lochar - 1), a__1[1] = setlab + (lochar - 1);
#ifndef NO_PROTO
		i__2[2] = 39, a__1[2] = "that lie outside the current modell"
			"ing ";
		i__2[3] = 39, a__1[3] = "clipping volume should be clipped, "
			"and ";
		i__2[4] = 38, a__1[4] = "the new boundaries formed by clippi"
			"ng ";
#else /* NO_PROTO */
		i__2[2] = 39, a__1[2] = "that lie outside the current modell\
ing ";
		i__2[3] = 39, a__1[3] = "clipping volume should be clipped, \
and ";
		i__2[4] = 38, a__1[4] = "the new boundaries formed by clippi\
ng ";
#endif /* NO_PROTO */
		i__2[5] = 16, a__1[5] = "should be drawn.";
		s_cat(ch__1, a__1, i__2, &c__6, 206L);
		setmsg_("40 41 42 43 53 57 58 63", ch__1, 23L, 5 - (lochar - 
			1) + 201);
	    } else {
/* Writing concatenation */
		i__2[0] = 34, a__1[0] = "Exactly those parts of a fill area";
		i__2[1] = 5 - (lochar - 1), a__1[1] = setlab + (lochar - 1);
#ifndef NO_PROTO
		i__2[2] = 39, a__1[2] = "that lie outside the current modell"
			"ing ";
		i__2[3] = 39, a__1[3] = "clipping volume should be clipped w"
			"hen ";
#else /* NO_PROTO */
		i__2[2] = 39, a__1[2] = "that lie outside the current modell\
ing ";
		i__2[3] = 39, a__1[3] = "clipping volume should be clipped w\
hen ";
#endif /* NO_PROTO */
		i__2[4] = 22, a__1[4] = "the interior style is ";
		i__2[5] = 8, a__1[5] = intlab + (intsty << 3);
		s_cat(ch__2, a__1, i__2, &c__6, 147L);
		setmsg_("40 41 42 43 53 57 58", ch__2, 20L, 5 - (lochar - 1) 
			+ 142);
		if (intsty == 2) {
/*  set pattern rep #1 to simple small checkerboard */
		    nspar (&globnu_1.wkid, &c__1, &c__3, &c__2, &c__1, &c__1, 
			    &c__3, &c__2, colia);
		    nspa (&c_b76, &c_b76);
		    nsisi (&c__1);
		} else if (intsty == 3) {
		    nsisi (&hatsty);
		}
	    }
/*  ranwin = permuted list of 1-6 */
	    rnperm_(&c__6, ranwin);
	    nsmcli (&c__1);
	    for (wndex = 1; wndex <= 6; ++wndex) {
/*  xf = modelling transformation to map unit square (0-1) int
o */
/*    window #WNDEX (with z-dimension unaltered) */
		ebltm3_(&c_b25, &c_b25, &c_b25, &xwinlo[wndex - 1], &ywinlo[
			wndex - 1], &c_b25, &c_b25, &c_b25, &c_b25, &xsiz, &
			xsiz, &c_b24, xf);
		faclip_(acl, bcl, ccl, dcl, &xco, &yco, &zco, mcv3);
/*  transform clipping plane to WC: */
		nslmt3 (xf, &c__2);
		thiswn = ranwin[wndex - 1];
/*  no clipping planes in effect */
		nsmcv (&c__1, &c__0, mcv2);
		if (thiswn == 1) {
/*  set up 2D clipping planes using replace */
		    nsmcv (&c__1, &c__2, mcv2);
		} else if (thiswn == 2) {
/*  set up 2D clipping planes using intersect */
		    nsmcv (&c__2, &c__1, &mcv2[4]);
		    nsmcv (&c__2, &c__1, mcv2);
		} else if (thiswn == 3) {
/*  set up 3D clipping planes using replace */
		    nsmcv3 (&c__1, &c__2, mcv3);
		} else if (thiswn == 4) {
/*  set up 3D clipping planes using intersect */
		    nsmcv3 (&c__2, &c__1, &mcv3[6]);
		    nsmcv3 (&c__2, &c__1, mcv3);
		} else if (thiswn == 5) {
/*  simulate complex self-intersecting fill area, properly
 clipped */
		    nfas (&nfa, fasdx, xexp, yexp);
		    goto L210;
		} else {
/*  simulate complex self-intersecting fill area, improper
ly clipped */
		    i__3 = nfa - 1;
		    nfas (&i__3, fasdx, xexp, yexp);
		    ngwin = wndex;
		    goto L210;
		}
/*  render primitive using different transformation */
		nslmt3 (idxf, &c__2);
		if (primsw == 1) {
/*  compute z-values for fill area */
		    for (jx = 1; jx <= 14; ++jx) {
			zp[jx - 1] = xco * xp[jx - 1] + yco * yp[jx - 1] + 
				zco;
/* L220: */
		    }
/*  transform fill area "by hand" to WC: */
		    arrtp3_(&c__14, xp, yp, zp, xf, xt, yt, zt);
/*  draw complex self-intersecting 3D fill area */
		    nfa3 (&c__14, xt, yt, zt);
		} else {
/*  compute z-values for fill area set */
		    for (jx = 1; jx <= 24; ++jx) {
			zfas[jx - 1] = xco * xfas[jx - 1] + yco * yfas[jx - 1]
				 + zco;
/* L225: */
		    }
/*  transform fill area set "by hand" to WC: */
		    arrtp3_(&c__24, xfas, yfas, zfas, xf, xt, yt, zt);
/*  draw complex self-intersecting 3D fill area set */
		    nfas3 (&anfa, afasdx, xt, yt, zt);
		}
/*  next wndex */
L210:
		;
	    }
/* Writing concatenation */
	    i__4[0] = 31, a__2[0] = "MODELLING CLIPPING OF FILL AREA";
	    i__4[1] = 5 - (lochar - 1), a__2[1] = setpr + (lochar - 1);
	    i__4[2] = 16, a__2[2] = " Which fill area";
	    i__4[3] = 5 - (lochar - 1), a__2[3] = setlab + (lochar - 1);
	    i__4[4] = 13, a__2[4] = "is different?";
	    s_cat(ch__3, a__2, i__4, &c__5, 70L);
	    dchpfv_(ch__3, &c__6, &ngwin, 5 - (lochar - 1) + 47 + (5 - (
		    lochar - 1)) + 13);
	    nemst (&c__102);
/*  next interior style */
/* L200: */
	}
/*  next primitive */
/* L150: */
    }
/*  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("40 41 42 43 53 57 58 64", "When a fill area set with a visible "
	    "edge is clipped, the new boundary formed by the clipping should "
	    "not be indicated by the edge.", 23L, 129L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 53 57 58 64", "When a fill area set with a visible \
edge is clipped, the new boundary formed by the clipping should not be indic\
ated by the edge.", 23L, 129L);
#endif /* NO_PROTO */
    nsis (&c__4);
    nsedfg (&c__1);
    nsedt (&c__4);
    nsln (&c__4);
    nsewsc (&c_b24);
    nslwsc (&c_b24);
    nsedci (&c__1);
    nsplci (&c__1);
/*  ranwin = permuted list of 1-6 */
    rnperm_(&c__6, ranwin);
    nsmcli (&c__1);
    for (wndex = 1; wndex <= 6; ++wndex) {
/*  xf = modelling transformation to map unit square (0-1) into */
/*    window #WNDEX (with z-dimension unaltered) */
	ebltm3_(&c_b25, &c_b25, &c_b25, &xwinlo[wndex - 1], &ywinlo[wndex - 1]
		, &c_b25, &c_b25, &c_b25, &c_b25, &xsiz, &xsiz, &c_b24, xf);
	faclip_(acl, bcl, ccl, dcl, &xco, &yco, &zco, mcv3);
/*  transform clipping plane to WC: */
	nslmt3 (xf, &c__2);
	thiswn = ranwin[wndex - 1];
/*  no clipping planes in effect */
	nsmcv (&c__1, &c__0, mcv2);
	if (thiswn == 1) {
/*  set up 2D clipping planes using replace */
	    nsmcv (&c__1, &c__2, mcv2);
	} else if (thiswn == 2) {
/*  set up 2D clipping planes using intersect */
	    nsmcv (&c__2, &c__1, &mcv2[4]);
	    nsmcv (&c__2, &c__1, mcv2);
	} else if (thiswn == 3) {
/*  set up 3D clipping planes using replace */
	    nsmcv3 (&c__1, &c__2, mcv3);
	} else if (thiswn == 4) {
/*  set up 3D clipping planes using intersect */
	    nsmcv3 (&c__2, &c__1, &mcv3[6]);
	    nsmcv3 (&c__2, &c__1, mcv3);
	} else if (thiswn == 5) {
/*  draw expected edge vertices: */
	    exedv_("5,1,2,3,4", xexp, yexp, 9L);
	    exedv_("10,6,7,11,12,15,16", xexp, yexp, 18L);
	    exedv_("21,22", xexp, yexp, 5L);
	    exedv_("24,25", xexp, yexp, 5L);
	    exedv_("9,19,20", xexp, yexp, 7L);
	    exedv_("23,14,13,17", xexp, yexp, 11L);
	    goto L310;
	} else {
/*  draw incorrect edge vertices: */
	    exedv_("5,1,2,3,4", xexp, yexp, 9L);
	    exedv_("10,6,7,11,12,15,16", xexp, yexp, 18L);
/*  this one is wrong: */
	    exedv_("21,22,24,25,21", xexp, yexp, 14L);
	    exedv_("9,19,20", xexp, yexp, 7L);
	    exedv_("23,14,13,17", xexp, yexp, 11L);
	    ngwin = wndex;
	    goto L310;
	}
/*  render primitive using different transformation */
	nslmt3 (idxf, &c__2);
/*  compute z-values for fill area set */
	for (jx = 1; jx <= 24; ++jx) {
	    zfas[jx - 1] = xco * xfas[jx - 1] + yco * yfas[jx - 1] + zco;
/* L325: */
	}
/*  transform fill area set "by hand" to WC: */
	arrtp3_(&c__24, xfas, yfas, zfas, xf, xt, yt, zt);
/*  draw complex self-intersecting 3D fill area set */
	nfas3 (&anfa, afasdx, xt, yt, zt);
/*  next wndex */
L310:
	;
    }
#ifndef NO_PROTO
    dchpfv_("MODELLING CLIPPING OF EDGED FILL AREA SET: Which clipped fill a"
	    "rea set has different edges?", &c__6, &ngwin, 91L);
#else /* NO_PROTO */
    dchpfv_("MODELLING CLIPPING OF EDGED FILL AREA SET: Which clipped fill a\
rea set has different edges?", &c__6, &ngwin, 91L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */


#ifndef NO_PROTO
    setmsg_("40 41 42 43 53 57 58", "Exactly those parts of a cell array tha"
	    "t lie outside the current modelling clipping volume should be cl"
	    "ipped.", 20L, 109L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 53 57 58", "Exactly those parts of a cell array tha\
t lie outside the current modelling clipping volume should be clipped.", 20L, 
	    109L);
#endif /* NO_PROTO */
    nsis (&c__1);
    nsedfg (&c__0);
/*  cell array x-y coordinates */
    setrvs_("0.1, 0.4, 0.5", xca, &ix, 13L);
    setrvs_("0.3, 0.9, 0.2", yca, &ix, 13L);
/*  compute cell vectors */
    pqx = (xca[1] - xca[0]) / 3;
    pqy = (yca[1] - yca[0]) / 3;
    prx = (xca[2] - xca[0]) / 2;
    pry = (yca[2] - yca[0]) / 2;
/*  compute clipped cell vertices */
/*  cell #1, color #1 */
    xexp[0] = xca[0];
    xexp[1] = xca[0] + pqx;
    xexp[2] = xca[0] + pqx + prx;
    xexp[3] = xca[0] + prx;
    yexp[0] = yca[0];
    yexp[1] = yca[0] + pqy;
    yexp[2] = yca[0] + pqy + pry;
    yexp[3] = yca[0] + pry;
/*  cell #2, color #1 */
    xexp[4] = xca[0] + pqx * 2 + prx;
    yexp[4] = yca[0] + pqy * 2 + pry;
    parcof_(&xexp[4], &yexp[4], &pqx, &pqy, &aca, &bca, &cca);
    lintpt_(&acl[1], &bcl[1], &dcl[1], &aca, &bca, &cca, &xexp[5], &yexp[5]);
    parcof_(&xexp[4], &yexp[4], &prx, &pry, &aca, &bca, &cca);
    lintpt_(&acl[1], &bcl[1], &dcl[1], &aca, &bca, &cca, &xexp[6], &yexp[6]);
/*  cell #3, color #2 */
    xexp[7] = xca[0] + pqx;
    xexp[8] = xca[0] + pqx * 2;
    xexp[9] = xca[0] + pqx * 2 + prx;
    xexp[10] = xca[0] + pqx + prx;
    yexp[7] = yca[0] + pqy;
    yexp[8] = yca[0] + pqy * 2;
    yexp[9] = yca[0] + pqy * 2 + pry;
    yexp[10] = yca[0] + pqy + pry;
/*  cell #4, color #2 */
    xexp[11] = xca[0] + prx;
    xexp[12] = xca[0] + pqx + prx;
    xexp[13] = xca[0] + pqx + prx * 2;
    yexp[11] = yca[0] + pry;
    yexp[12] = yca[0] + pqy + pry;
    yexp[13] = yca[0] + pqy + pry * 2;
    parcof_(&xexp[13], &yexp[13], &pqx, &pqy, &aca, &bca, &cca);
    lintpt_(acl, bcl, dcl, &aca, &bca, &cca, &xexp[14], &yexp[14]);
    parcof_(&xexp[11], &yexp[11], &prx, &pry, &aca, &bca, &cca);
    lintpt_(acl, bcl, dcl, &aca, &bca, &cca, &xexp[15], &yexp[15]);
/*  cell #5, color #3 */
    xexp[16] = xexp[2];
    xexp[17] = xexp[4];
    xexp[18] = xexp[6];
    xexp[20] = xexp[13];
    yexp[16] = yexp[2];
    yexp[17] = yexp[4];
    yexp[18] = yexp[6];
    yexp[20] = yexp[13];
    parcof_(&xexp[20], &yexp[20], &pqx, &pqy, &aca, &bca, &cca);
    lintpt_(&acl[1], &bcl[1], &dcl[1], &aca, &bca, &cca, &xexp[19], &yexp[19])
	    ;
/*  cell #6, color #3 */
    xexp[21] = xexp[8];
    xexp[23] = xexp[5];
    xexp[24] = xexp[4];
    yexp[21] = yexp[8];
    yexp[23] = yexp[5];
    yexp[24] = yexp[4];
    parcof_(&xexp[21], &yexp[21], &pqx, &pqy, &aca, &bca, &cca);
    lintpt_(&acl[1], &bcl[1], &dcl[1], &aca, &bca, &cca, &xexp[22], &yexp[22])
	    ;
/*  ranwin = permuted list of 1-6 */
    rnperm_(&c__6, ranwin);
    nsmcli (&c__1);
    for (wndex = 1; wndex <= 6; ++wndex) {
/*  xf = modelling transformation to map unit square (0-1) into */
/*    window #WNDEX (with z-dimension unaltered) */
	ebltm3_(&c_b25, &c_b25, &c_b25, &xwinlo[wndex - 1], &ywinlo[wndex - 1]
		, &c_b25, &c_b25, &c_b25, &c_b25, &xsiz, &xsiz, &c_b24, xf);
	faclip_(acl, bcl, ccl, dcl, &xco, &yco, &zco, mcv3);
/*  transform clipping plane to WC: */
	nslmt3 (xf, &c__2);
	thiswn = ranwin[wndex - 1];
/*  no clipping planes in effect */
	nsmcv (&c__1, &c__0, mcv2);
	if (thiswn == 1) {
/*  set up 2D clipping planes using replace */
	    nsmcv (&c__1, &c__2, mcv2);
	} else if (thiswn == 2) {
/*  set up 2D clipping planes using intersect */
	    nsmcv (&c__2, &c__1, &mcv2[4]);
	    nsmcv (&c__2, &c__1, mcv2);
	} else if (thiswn == 3) {
/*  set up 3D clipping planes using replace */
	    nsmcv3 (&c__1, &c__2, mcv3);
	} else if (thiswn == 4) {
/*  set up 3D clipping planes using intersect */
	    nsmcv3 (&c__2, &c__1, &mcv3[6]);
	    nsmcv3 (&c__2, &c__1, mcv3);
	} else if (thiswn == 5) {
/*  draw expected cells */
	    nsici (&c__1);
	    setvs_("4,7", fasdx, &nfa, 3L);
	    nfas (&nfa, fasdx, xexp, yexp);
	    nsici (&c__2);
	    setvs_("4,9", fasdx, &nfa, 3L);
	    nfas (&nfa, fasdx, &xexp[7], &yexp[7]);
	    nsici (&c__3);
	    setvs_("5,9", fasdx, &nfa, 3L);
	    nfas (&nfa, fasdx, &xexp[16], &yexp[16]);
	    goto L410;
	} else {
/*  draw incorrect cells */
	    nsici (&c__1);
	    setvs_("4,7", fasdx, &nfa, 3L);
	    nfas (&nfa, fasdx, xexp, yexp);
	    nsici (&c__2);
	    setvs_("4,8", fasdx, &nfa, 3L);
	    nfas (&nfa, fasdx, &xexp[7], &yexp[7]);
	    nsici (&c__3);
	    setvs_("5,9", fasdx, &nfa, 3L);
	    nfas (&nfa, fasdx, &xexp[16], &yexp[16]);
	    ngwin = wndex;
	    goto L410;
	}
/*  render primitive using different transformation */
	nslmt3 (idxf, &c__2);
/*  compute z-values for fill area set */
	for (jx = 1; jx <= 3; ++jx) {
	    zca[jx - 1] = xco * xca[jx - 1] + yco * yca[jx - 1] + zco;
/* L425: */
	}
/*  transform fill area set "by hand" to WC: */
	arrtp3_(&c__3, xca, yca, zca, xf, xt, yt, zt);
/*  draw complex self-intersecting 3D fill area set */
	nca3 (xt, yt, zt, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, colia);
/*  next wndex */
L410:
	;
    }
#ifndef NO_PROTO
    dchpfv_("MODELLING CLIPPING OF CELL ARRAY: Which cell array has a differ"
	    "ent size or shape?", &c__6, &ngwin, 81L);
#else /* NO_PROTO */
    dchpfv_("MODELLING CLIPPING OF CELL ARRAY: Which cell array has a differ\
ent size or shape?", &c__6, &ngwin, 81L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

