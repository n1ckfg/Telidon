/* fort/04/01/04/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__102 = 102;
static integer c__5 = 5;
static integer c__26 = 26;
#ifndef NO_PROTO
static real c_b24 = .5f;
#else /* NO_PROTO */
static real c_b24 = (float).5;
#endif /* NO_PROTO */
static integer c__106 = 106;
static integer c__103 = 103;
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b52 = 1.f;
#else /* NO_PROTO */
static real c_b52 = (float)1.;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b113 = -.499f;
static real c_b114 = .499f;
#else /* NO_PROTO */
static real c_b113 = (float)-.499;
static real c_b114 = (float).499;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.04/02                           * */
/*  *    TEST TITLE : Appearance of annotation text         * */
/*  *                 primitives                            * */
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
    real r__1, r__2, r__3, r__4;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static real x0, y0, z0, yb, yc, xf[16]	/* was [4][4] */;
    static integer ix;
    static real yh, tx[2], ty[2], idm[16]	/* was [4][4] */, xfa[16]	
	    /* was [4][4] */, xfb[16]	/* was [4][4] */, ext;
#ifndef NO_PROTO
    extern /* Subroutine */ int esc3_(real *, real *, real *, real *), etp3_(
	    real *, real *, real *, real *, real *, real *, real *), etr3_(
	    real *, real *, real *, real *), win6_(integer *, integer *, real 
	    *, real *, real *, real *), fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esc3_(), etp3_(), etr3_(), win6_(), fail_(), 
	    ifpf_();
#endif /* NO_PROTO */
    static real chht, xmid, ymid;
    static integer perm[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
#endif /* NO_PROTO */
    static integer txci, ngsq;
    static real npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static real ybot, xext, yext, ytop, xsiz, ysiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_();
#endif /* NO_PROTO */
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr3 (real *, real *, real *, real *, real *,
	     real *, char *, ftnlen), dline_(char *, char *, ftnlen, ftnlen), 
	    idmat_(integer *, real *), endit_(void), wcnpc_(real *, real *, 
	    real *, real *, real *);
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr3 (), dline_(), idmat_(), endit_(), 
	    wcnpc_();
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static char chstr[5], lower[26];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatp (integer *), nsans (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatp (), nsans ();
#endif /* NO_PROTO */
    static char upper[26];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), rnset_(integer *, integer *, 
	    integer *), nemst (integer *), nexst (integer *), nopst (integer *
	    ), nsvwi (integer *), nqtxx (integer *, integer *, real *, real *,
	     real *, integer *, integer *, integer *, char *, integer *, real 
	    *, real *, real *, real *, ftnlen), ebltm3_(real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), rnset_(), nemst (), nexst (), 
	    nopst (), nsvwi (), nqtxx (), ebltm3_();
#endif /* NO_PROTO */
    static char chrabc[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt3 (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt3 ();
#endif /* NO_PROTO */
    static real ngdelt;
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static real npcpwc, xrefpt, yrefpt, zrefpt, xannpt, yannpt, zannpt, 
	    xwinlo[6], ywinlo[6];
    static char repstr[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nstxfn (integer *), nstxpr (
	    integer *), nsatal (integer *, integer *), nsatch (real *), 
	    nsplci (integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    chkinq_(char *, integer *, ftnlen), drwrec_(real *, real *, real *
	    , real *), dchpfv_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nstxfn (), 
	    nstxpr (), nsatal (), nsatch (), nsplci (), setmsg_(), chkinq_(), 
	    drwrec_(), dchpfv_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* line type */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    initgl_("04.01.04/02", 11L);
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
/*  ratio of NPC to WC */
    wcnpc_(&c_b5, &c_b5, &npcx, &npcy, &npcpwc);
/*  set default attributes: */
    nstxfn (&c__1);
    nstxpr (&c__2);
    nsatal (&c__2, &c__3);
    nsatp (&c__0);
#ifndef NO_PROTO
    chht = .05f;
#else /* NO_PROTO */
    chht = (float).05;
#endif /* NO_PROTO */
    r__1 = chht * npcpwc;
    nsatch (&r__1);
    nsans (&c__1);
    nsln (&c__1);
    nsplci (&c__3);
/*  set up 102 as sub-structure */
    nexst (&c__102);
    nclst ();

/*  *** *** *** *** ***  character content  *** *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("7", "A displayed annotation text primitive should contain the s"
	    "pecified character string.", 1L, 84L);
#else /* NO_PROTO */
    setmsg_("7", "A displayed annotation text primitive should contain the s\
pecified character string.", 1L, 84L);
#endif /* NO_PROTO */
    nopst (&c__102);
#ifndef NO_PROTO
    r__1 = npcpwc * .08f;
#else /* NO_PROTO */
    r__1 = npcpwc * (float).08;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nstxfn (&c__2);
    s_copy(upper, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26L, 26L);
/*  chstr = string of 5 randomly chosen upper-case letters. */
    rnset_(&c__5, &c__26, perm);
    for (ix = 1; ix <= 5; ++ix) {
	i__1 = perm[ix - 1] - 1;
	s_copy(chstr + (ix - 1), upper + i__1, 1L, perm[ix - 1] - i__1);
/* L100: */
    }
/*  display <annotation text relative 3> consisting of chstr: */
/*    reference position = 0.5, 0.5, 0.5 */
/*    offset = 0., 0., 0.1 */
    natr3 (&c_b24, &c_b24, &c_b24, &c_b5, &c_b5, &c_b5, chstr, 5L);
    dline_("CHARACTER CONTENT: Enter the displayed character string.", repstr,
	     56L, 10L);
    if (s_cmp(repstr, chstr, 10L, 5L) != 0) {
	fail_();
	goto L199;
    }
    nemst (&c__102);
    nstxfn (&c__1);
#ifndef NO_PROTO
    r__1 = npcpwc * .08f;
#else /* NO_PROTO */
    r__1 = npcpwc * (float).08;
#endif /* NO_PROTO */
    nsatch (&r__1);
/*  chstr = string of 5 randomly chosen lower-case letters */
    s_copy(lower, "abcdefghijklmnopqrstuvwxyz", 26L, 26L);
    rnset_(&c__5, &c__26, perm);
    for (ix = 1; ix <= 5; ++ix) {
	i__1 = perm[ix - 1] - 1;
	s_copy(chstr + (ix - 1), lower + i__1, 1L, perm[ix - 1] - i__1);
/* L110: */
    }
/*  display <annotation text relative> consisting of chstr: */
/*     reference point = 0.5, 0.5 */
/*     offset = 0., 0. */
    natr (&c_b24, &c_b24, &c_b5, &c_b5, chstr, 5L);
    dline_("CHARACTER CONTENT: Enter the displayed character string.", repstr,
	     56L, 10L);
    L__1 = s_cmp(repstr, chstr, 10L, 5L) == 0;
    ifpf_(&L__1);
/*  end_char: */
L199:
    nemst (&c__102);
/*  *** *** *** ***   effect of reference point   *** *** *** *** */
    nexst (&c__106);
    nexst (&c__103);
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
/*  Divide screen up into 6 squares labelled areas */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__103);
    s_copy(chrabc, "ABC", 3L, 3L);
    idmat_(&c__4, idm);
/*  amount by which "incorrect" rectangle is to be shifted */
#ifndef NO_PROTO
    ngdelt = .01f;
#else /* NO_PROTO */
    ngdelt = (float).01;
#endif /* NO_PROTO */
/*  <Inquire text extent> to get extent rectangle for CHRABC */
    nqtxx (&dialog_1.specwt, &c__1, &c_b52, &c_b5, &chht, &c__0, &c__2, &c__4,
	     chrabc, &errind, tx, ty, &rdum1, &rdum2, 3L);
    chkinq_("pqtxx", &errind, 5L);
    yb = ty[0];
    nqtxx (&dialog_1.specwt, &c__1, &c_b52, &c_b5, &chht, &c__0, &c__2, &c__3,
	     chrabc, &errind, tx, ty, &rdum1, &rdum2, 3L);
    chkinq_("pqtxx", &errind, 5L);
    yh = ty[0];
    nqtxx (&dialog_1.specwt, &c__1, &c_b52, &c_b5, &chht, &c__0, &c__2, &c__2,
	     chrabc, &errind, tx, ty, &rdum1, &rdum2, 3L);
    chkinq_("pqtxx", &errind, 5L);
    yc = ty[0];
/*  horizontal size of string in MC */
    xext = tx[1] - tx[0];
/*  MC distance from baseline to halfline */
    ybot = (r__1 = yh - yb, dabs(r__1));
/*  MC distance from capline to halfline */
    ytop = (r__1 = yc - yh, dabs(r__1));
/*  MC vertical distance from baseline to capline */
    yext = ytop + ybot;
/*  select reference point randomly from cube: */
/*    (ext,1-ext),(ext,1-ext),(ext,1-ext) */
/*  to make sure that annotation text fits in window */
/*  Distance from center of rectangle to farthest border, divided */
/*  by XSIZ to cancel effect of modelling transformation, which */
/*  multiplies by XSIZ.  Thus, when string is located, aligned at */
/*  its center, it won't overlap border. */
#ifndef NO_PROTO
    ext = dmax(xext,yext) * .5f / xsiz;
#else /* NO_PROTO */
    ext = dmax(xext,yext) * (float).5 / xsiz;
#endif /* NO_PROTO */
/*  which square is no good */
    ngsq = rndint_(&c__1, &c__6);
/*  reference point must be at least EXT distant from any side of the */
/*  unit cube in all dimensions, because modelling transformation will */
/*  rotate cube, and reference point along with it, but NOT annotation */
/*  text itself, which is always in NPC-XY plane.  Therefore, it is */
/*  incorrect (even though plausible) to apply XEXT in X-dimension, */
/*  and YEXT in Y-dimension, because rotation mixes up dimensions. */
    r__1 = 1 - ext;
    xrefpt = rndrl_(&ext, &r__1);
    r__1 = 1 - ext;
    yrefpt = rndrl_(&ext, &r__1);
    r__1 = 1 - ext;
    zrefpt = rndrl_(&ext, &r__1);
    for (ix = 1; ix <= 6; ++ix) {
	xmid = xwinlo[ix - 1] + xsiz / 2;
	ymid = ywinlo[ix - 1] + ysiz / 2;
/*  scale down to fit in square, rotate, and move to square #ix */
#ifndef NO_PROTO
	r__1 = xmid - .5f;
	r__2 = ymid - .5f;
#else /* NO_PROTO */
	r__1 = xmid - (float).5;
	r__2 = ymid - (float).5;
#endif /* NO_PROTO */
	ebltm3_(&c_b24, &c_b24, &c_b24, &r__1, &r__2, &c_b5, &sider[ix - 1], &
		sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xf);
	nslmt3 (xf, &c__2);
/*  draw the annotation text at transformed reference point */
	natr3 (&xrefpt, &yrefpt, &zrefpt, &c_b5, &c_b5, &c_b5, chrabc, 3L);
	nslmt3 (idm, &c__2);
/*  find expected center of rectangle */
	etp3_(&xrefpt, &yrefpt, &zrefpt, xf, &x0, &y0, &z0);
	if (ix == ngsq) {
/*  distort towards middle of square - don't overlap border */
	    if (x0 < xmid) {
		x0 += ngdelt;
	    } else {
		x0 -= ngdelt;
	    }
	    if (y0 < ymid) {
		y0 += ngdelt;
	    } else {
		y0 -= ngdelt;
	    }
	}
/*  outline the annotation text */
	r__1 = x0 - xext / 2;
	r__2 = x0 + xext / 2;
	r__3 = y0 - ybot;
	r__4 = y0 + ytop;
	drwrec_(&r__1, &r__2, &r__3, &r__4);
/* L250: */
    }
#ifndef NO_PROTO
    setmsg_("7 8 9", "The location of an annotation text primitive should re"
	    "flect its 3D reference point after being transformed.", 5L, 107L);

    dchpfv_("EFFECT OF REFERENCE POINT: In which box is the annotation text "
	    "NOT accurately outlined by the rectangle?", &c__6, &ngsq, 104L);
#else /* NO_PROTO */
    setmsg_("7 8 9", "The location of an annotation text primitive should re\
flect its 3D reference point after being transformed.", 5L, 107L);
    dchpfv_("EFFECT OF REFERENCE POINT: In which box is the annotation text \
NOT accurately outlined by the rectangle?", &c__6, &ngsq, 104L);
#endif /* NO_PROTO */
    nemst (&c__103);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** **
**/
/*  which square will be marked wrong? */
    ngsq = rndint_(&c__1, &c__6);
/*  reference point: */
    r__1 = 1 - ext;
    xrefpt = rndrl_(&ext, &r__1);
    r__1 = 1 - ext;
    yrefpt = rndrl_(&ext, &r__1);
#ifndef NO_PROTO
    zrefpt = 0.f;
#else /* NO_PROTO */
    zrefpt = (float)0.;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 6; ++ix) {
	xmid = xwinlo[ix - 1] + xsiz / 2;
	ymid = ywinlo[ix - 1] + ysiz / 2;
/*  first, move from Z=0 plane to somewhere in middle */
	r__2 = 1 - ext;
	r__1 = rndrl_(&ext, &r__2);
	etr3_(&c_b5, &c_b5, &r__1, xfa);
/*  scale down to fit in square, rotate, and move to square #ix */
#ifndef NO_PROTO
	r__1 = xmid - .5f;
	r__2 = ymid - .5f;
#else /* NO_PROTO */
	r__1 = xmid - (float).5;
	r__2 = ymid - (float).5;
#endif /* NO_PROTO */
	ebltm3_(&c_b24, &c_b24, &c_b24, &r__1, &r__2, &c_b5, &sider[ix - 1], &
		sider[ix + 5], &sider[ix + 11], &xsiz, &xsiz, &xsiz, xfb);
	ecom3_(xfb, xfa, xf);
	nslmt3 (xf, &c__2);
	natr (&xrefpt, &yrefpt, &c_b5, &c_b5, chrabc, 3L);
	nslmt3 (idm, &c__2);
/*  find expected center of rectangle */
	etp3_(&xrefpt, &yrefpt, &zrefpt, xf, &x0, &y0, &z0);
	if (ix == ngsq) {
/*  distort towards middle of square - don't overlap border */
	    if (x0 < xmid) {
		x0 += ngdelt;
	    } else {
		x0 -= ngdelt;
	    }
	    if (y0 < ymid) {
		y0 += ngdelt;
	    } else {
		y0 -= ngdelt;
	    }
	}
/*  outline annotation text */
	r__1 = x0 - xext / 2;
	r__2 = x0 + xext / 2;
	r__3 = y0 - ybot;
	r__4 = y0 + ytop;
	drwrec_(&r__1, &r__2, &r__3, &r__4);
/* L260: */
    }
#ifndef NO_PROTO
    setmsg_("7 8 9", "The location of an annotation text primitive should re"
	    "flect its 2D reference point after being transformed.", 5L, 107L);

    dchpfv_("EFFECT OF REFERENCE POINT: In which box is the annotation text "
	    "NOT accurately outlined by the rectangle?", &c__6, &ngsq, 104L);
#else /* NO_PROTO */
    setmsg_("7 8 9", "The location of an annotation text primitive should re\
flect its 2D reference point after being transformed.", 5L, 107L);
    dchpfv_("EFFECT OF REFERENCE POINT: In which box is the annotation text \
NOT accurately outlined by the rectangle?", &c__6, &ngsq, 104L);
#endif /* NO_PROTO */
    nemst (&c__103);
/*  *** *** ***   effect of annotation offset   *** *** *** */
/*  ngsq = no-good square containing error = random from 1 to 6 */
    ngsq = rndint_(&c__1, &c__6);
/*  chstr = "ABC" */
    s_copy(chrabc, "ABC", 3L, 3L);
    for (ix = 1; ix <= 6; ++ix) {
/*  unscaled reference point */
#ifndef NO_PROTO
	xrefpt = 1.f;
	yrefpt = 1.f;
	zrefpt = 1.f;
#else /* NO_PROTO */
	xrefpt = (float)1.;
	yrefpt = (float)1.;
	zrefpt = (float)1.;
#endif /* NO_PROTO */
/*  center of current square */
	xmid = xwinlo[ix - 1] + xsiz / 2;
	ymid = ywinlo[ix - 1] + ysiz / 2;
/*  scale into center of current square */
	esc3_(&xmid, &ymid, &c_b24, xf);
	nslmt3 (xf, &c__2);
/*  pick NPC offset randomly - but keep within square */
	r__1 = (xext - xsiz) / 2;
	r__2 = (xsiz - xext) / 2;
	xannpt = npcpwc * rndrl_(&r__1, &r__2);
	r__1 = ybot - ysiz / 2;
	r__2 = ysiz / 2 - ytop;
	yannpt = npcpwc * rndrl_(&r__1, &r__2);
	zannpt = npcpwc * rndrl_(&c_b113, &c_b114);
	if (ix <= 3) {
	    natr3 (&xrefpt, &yrefpt, &zrefpt, &xannpt, &yannpt, &zannpt, 
		    chrabc, 3L);
	} else {
	    natr (&xrefpt, &yrefpt, &xannpt, &yannpt, chrabc, 3L);
	}
	nslmt3 (idm, &c__2);
/*  expected center of rectangle, in MC */
	x0 = xmid + xannpt / npcpwc;
	y0 = ymid + yannpt / npcpwc;
	if (ix == ngsq) {
/*  distort towards middle of square - don't overlap border */
	    if (x0 < xmid) {
		x0 += ngdelt;
	    } else {
		x0 -= ngdelt;
	    }
	    if (y0 < ymid) {
		y0 += ngdelt;
	    } else {
		y0 -= ngdelt;
	    }
	}
	r__1 = x0 - xext / 2;
	r__2 = x0 + xext / 2;
	r__3 = y0 - ybot;
	r__4 = y0 + ytop;
	drwrec_(&r__1, &r__2, &r__3, &r__4);
/* L300: */
    }
#ifndef NO_PROTO
    setmsg_("7 8 9", "An annotation text primitive should be displaced from "
	    "the reference point as specified by its annotation offset values."
	    , 5L, 119L);
    dchpfv_("EFFECT OF ANNOTATION OFFSET: In which box is the annotation tex"
	    "t NOT accurately outlined by the rectangle?", &c__6, &ngsq, 106L);
#else /* NO_PROTO */
    setmsg_("7 8 9", "An annotation text primitive should be displaced from \
the reference point as specified by its annotation offset values.", 5L, 119L);
#endif /* NO_PROTO */

#ifdef NO_PROTO
    dchpfv_("EFFECT OF ANNOTATION OFFSET: In which box is the annotation tex\
t NOT accurately outlined by the rectangle?", &c__6, &ngsq, 106L);
#endif /* NO_PROTO */
    nemst (&c__103);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

