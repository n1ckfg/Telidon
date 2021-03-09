/* fort/06/01/02/p17.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__106 = 106;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b13 = 0.f;
#else /* NO_PROTO */
static real c_b13 = (float)0.;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b20 = .01f;
#else /* NO_PROTO */
static real c_b20 = (float).01;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b24 = -1.f;
static real c_b27 = 1.f;
static real c_b31 = .5f;
#else /* NO_PROTO */
static real c_b24 = (float)-1.;
static real c_b27 = (float)1.;
static real c_b31 = (float).5;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__0 = 0;
static integer c__15 = 15;
static integer c__8 = 8;
#ifndef NO_PROTO
static real c_b129 = .1f;
static real c_b133 = .6f;
static real c_b134 = 1.4f;
static real c_b135 = .3f;
static real c_b136 = .8f;
static real c_b138 = -.7f;
static real c_b139 = .7f;
#else /* NO_PROTO */
static real c_b129 = (float).1;
static real c_b133 = (float).6;
static real c_b134 = (float)1.4;
static real c_b135 = (float).3;
static real c_b136 = (float).8;
static real c_b138 = (float)-.7;
static real c_b139 = (float).7;
#endif /* NO_PROTO */
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/17                           * */
/*  *    TEST TITLE : Modelling clipping for text and       * */
/*  *                 annotation text                       * */
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
    real r__1, r__2, r__3, r__4, r__5, r__6;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double r_sign(real *, real *);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    double r_sign();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i2;
    static real xa[40], ya[40], za[40], xf[16]	/* was [4][4] */;
    static integer ix, iy, iex;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static real tdx[2], tdy[2], tdz[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real vyx;
#ifndef NO_PROTO
    extern /* Subroutine */ int esc3_(real *, real *, real *, real *), vec1_(
	    real *, real *, real *, real *, real *, real *);
    extern integer mod1_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esc3_(), vec1_();
    extern integer mod1_();
#endif /* NO_PROTO */
    static real mcv2[40]	/* was [4][10] */, mcv3[60]	/* was [6][10]
	     */;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), win6_(integer *, integer *, real *, real *, real 
	    *, real *), ntx3 (real *, real *, real *, real *, real *, real *, 
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), win6_(), ntx3 ();
#endif /* NO_PROTO */
    static real htab[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real vtab[5], ycap, ybas, chxp, scxf[16]	/* was [4][4] */, 
	    yloc;
    static integer txci;
    static real corx[4], cory[4], corz[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static real ytop, xsiz, ysiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_();
#endif /* NO_PROTO */
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr3 (real *, real *, real *, real *, real *,
	     real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr3 ();
#endif /* NO_PROTO */
    static real achht, delta, chhth;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */
    static real nomhb, nomhc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), endit_();
#endif /* NO_PROTO */
    static real chxph, chhtv, hvecx;
    static integer opans, ngwin;
    static real nvecx;
    static integer numhp;
    static real chxpv;
    static integer txlen;
    static real nvecy;
    static integer visdx;
    static real nvecz, xcent, hvecy, hvecz, vvecx, ntxwd, ntxht, vvecy, vvecz;

#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static real expvx[20], expvy[20], expvz[20], nomhl, nomhr, nomvl, nomvr, 
	    nomvb, nomvc, tdrot[16]	/* was [4][4] */, corxf[16]	/* 
	    was [4][4] */, centx, centy, centz, xleft, d1vecx, d1vecy, d1vecz,
	     d2vecx, d2vecy, d2vecz, xrite, yincr;
    static char txstr[7], chstr[13];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsvwi (integer *), nexst (
	    integer *), nclst (void), ebltm3_(real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), nstxp (integer *), nemst (integer *), nsmcv3 (integer *, 
	    integer *, real *), nsmcv (integer *, integer *, real *), wcnpc_(
	    real *, real *, real *, real *, real *), nsatp (integer *), 
	    nsans (integer *), rnset_(integer *, integer *, integer *), 
	    nslmt3 (real *, integer *), dchoic_(char *, integer *, integer *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsvwi (), nexst (), nclst (), 
	    ebltm3_(), nstxp (), nemst (), nsmcv3 (), nsmcv (), wcnpc_(), 
	    nsatp (), nsans (), rnset_(), nslmt3 (), dchoic_();
#endif /* NO_PROTO */
    static integer ngline;
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer picstr, thiswn;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer txfont, txpath, expnum, numvis, ranwin[8], vislis[8], 
	    wntype, numlin, thisln;
    static real npcpwc, winsiz, xwinlo[6], ywinlo[6];
    static char atxstr[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), txexal_(integer *, integer *, char *, real *, real *, 
	    real *, real *, ftnlen), nschsp (real *), nstxfn (integer *), 
	    nstxpr (integer *), nstxal (integer *, integer *), nstxci (
	    integer *), nsplci (integer *), nslwsc (real *), nsmcli (integer *
	    ), crossp_(real *, real *, real *, real *, real *, real *, real *,
	     real *, real *), nschxp (real *), dchpfv_(char *, integer *, 
	    integer *, ftnlen), setrvs_(char *, real *, integer *, ftnlen), 
	    opfail_(void), nsatch (real *), nsatal (integer *, integer *), 
	    dlstpf_(char *, integer *, integer *, char *, ftnlen, ftnlen), 
	    numlab_(integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), setmsg_(), 
	    txexal_(), nschsp (), nstxfn (), nstxpr (), nstxal (), nstxci (), 
	    nsplci (), nslwsc (), nsmcli (), crossp_(), nschxp (), dchpfv_(), 
	    setrvs_(), opfail_(), nsatch (), nsatal (), dlstpf_(), numlab_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* linetype */
/* text precision */
/* clipping indicator */
/*                noclip        cllip */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* modelling clipping operator */
/*                replace,      intersect */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    initgl_("06.01.02/17", 11L);
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
    nexst (&c__102);
    nclst ();
/*  Set up 6 windows on the screen */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
    nexst (&c__106);
/*  throughout, represent a line segment as a point P and vector V, */
/*    where endpoints = P and P+V */
/*  *** *** *** ***   text   *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("40 41 42 43 53 57 58", "Exactly those parts of a text primitive"
	    " in STROKE precision that lie outside the current modelling clip"
	    "ping volume should be clipped.", 20L, 133L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 53 57 58", "Exactly those parts of a text primitive\
 in STROKE precision that lie outside the current modelling clipping volume \
should be clipped.", 20L, 133L);
#endif /* NO_PROTO */
/*  txstr = text string with ASCII characters that fill character box */
    s_copy(txstr, "ZHMENKX", 7L, 7L);
    txfont = 1;
/*  *** *** ***  set up expected horizontal text extent: */
    txpath = 0;
    txexal_(&txfont, &txpath, txstr, &ntxwd, &ntxht, htab, vtab, 7L);
/*  using text alignment = center,half: */
/* nomhl,nomhr = nominal x-location of left,right border of horizontal str
ing*/
/* nomhb,nomhc = nominal y-location of baseline,capline of horizontal stri
ng*/
    nomhl = htab[0] - htab[1];
    nomhr = htab[2] - htab[1];
    nomhb = vtab[3] - vtab[2];
    nomhc = vtab[1] - vtab[2];
/*  horizontal-path expansion factor */
#ifndef NO_PROTO
    chxph = .3f;
#else /* NO_PROTO */
    chxph = (float).3;
#endif /* NO_PROTO */
    nomhl *= chxph;
    nomhr *= chxph;
/*  horizontal-path character height */
#ifndef NO_PROTO
    chhth = 1.9f / (nomhr - nomhl);
#else /* NO_PROTO */
    chhth = (float)1.9 / (nomhr - nomhl);
#endif /* NO_PROTO */
/*  *** *** ***  set up expected vertical text extent: */
    txpath = 3;
    txexal_(&txfont, &txpath, txstr, &ntxwd, &ntxht, htab, vtab, 7L);
/*  using text alignment = center,half: */
/* nomvl,nomvr = nominal x-location of left,right border of vertical strin
g*/
/* nomvb,nomvc = nominal y-location of baseline,capline of vertical string
*/
    nomvl = htab[0] - htab[1];
    nomvr = htab[2] - htab[1];
    nomvb = vtab[3] - vtab[2];
    nomvc = vtab[1] - vtab[2];
/*  vertical-path expansion factor */
#ifndef NO_PROTO
    chxpv = 3.f;
#else /* NO_PROTO */
    chxpv = (float)3.;
#endif /* NO_PROTO */
    nomvl *= chxpv;
    nomvr *= chxpv;
/*  vertical-path character height */
#ifndef NO_PROTO
    chhtv = 1.9f / (nomvc - nomvb);
#else /* NO_PROTO */
    chhtv = (float)1.9 / (nomvc - nomvb);
#endif /* NO_PROTO */
/*  set constant attributes */
    nschsp (&c_b13);
    nstxfn (&txfont);
    nstxpr (&c__2);
    nstxal (&c__2, &c__3);
    nstxci (&c__1);
    nsplci (&c__2);
    nsln (&c__3);
    nslwsc (&c_b20);
/*  incorrectly drawn window */
    ngwin = rndint_(&c__1, &c__6);
    for (thiswn = 1; thiswn <= 6; ++thiswn) {
/*  xf = modelling transformation to map double-unit MC cube (-1 to 1)
 */
/*       into window #thiswn in xy-dimensions, and into (0 to 1) */
/*       in z-dimension */
#ifndef NO_PROTO
	r__1 = xwinlo[thiswn - 1] + 1.f;
	r__2 = ywinlo[thiswn - 1] + 1.f;
#else /* NO_PROTO */
	r__1 = xwinlo[thiswn - 1] + (float)1.;
	r__2 = ywinlo[thiswn - 1] + (float)1.;
#endif /* NO_PROTO */
	r__3 = xsiz / 2;
	r__4 = xsiz / 2;
	ebltm3_(&c_b24, &c_b24, &c_b24, &r__1, &r__2, &c_b27, &c_b13, &c_b13, 
		&c_b13, &r__3, &r__4, &c_b31, xf);
	nslmt3 (xf, &c__2);
	nsmcli (&c__1);
/*  compute expected text position: */
/*  get_vecs: random 3D vector chosen from -1 to 1 in each dimension 
*/
L105:
	for (ix = 1; ix <= 2; ++ix) {
	    tdx[ix - 1] = rndrl_(&c_b24, &c_b27);
	    tdy[ix - 1] = rndrl_(&c_b24, &c_b27);
	    tdz[ix - 1] = rndrl_(&c_b24, &c_b27);
/* L110: */
	}
/*  nvec = normal vector to text plane = cross-product of vec1 x vec2 
*/
	crossp_(tdx, tdy, tdz, &tdx[1], &tdy[1], &tdz[1], &nvecx, &nvecy, &
		nvecz);
/*  ensure text-plane not edge-on to operator: */
#ifndef NO_PROTO
	if (dabs(nvecz) < dabs(nvecx) * .6f || dabs(nvecz) < dabs(nvecy) * 
		.6f) {
#else /* NO_PROTO */
	if (dabs(nvecz) < dabs(nvecx) * (float).6 || dabs(nvecz) < dabs(nvecy)
		 * (float).6) {
#endif /* NO_PROTO */
	    goto L105;
	}
/*  tdrot = 3D rotation transformation resulting from application */
/*          of text direction vectors */
	idmat_(&c__4, tdrot);
/*  compute unit vectors expressing TLC directions within MC - */
/*  build these into columns of transformation matrix. */
/*  TLC X-direction = 1st vector, scaled to unit size */
	vec1_(tdx, tdy, tdz, tdrot, &tdrot[1], &tdrot[2]);
/*  TLC Z-direction = 1st x 2nd vector, scaled to unit size */
	vec1_(&nvecx, &nvecy, &nvecz, &tdrot[8], &tdrot[9], &tdrot[10]);
/*  TLC Y-direction = Z-direction x X-direction */
	crossp_(&tdrot[8], &tdrot[9], &tdrot[10], tdrot, &tdrot[1], &tdrot[2],
		 &tdrot[4], &tdrot[5], &tdrot[6]);
/*  compute text rectangle corners: */
	if (thiswn < 4) {
/*  set up for horizontal path: */
	    nschh (&chhth);
	    nschxp (&chxph);
	    nstxp (&c__0);
/*  scxf = transformation to scale by chhth */
	    esc3_(&chhth, &chhth, &chhth, scxf);
/*  corxf = transformation for corners of text rectangle induced 
*/
/*          by text direction vectors and char-height: TLC to MC 
*/
/*        = scxf x tdrot */
	    ecom3_(scxf, tdrot, corxf);
/*  compute expected corners of text rectangle in MC, in order */
/*  left-base, left-cap, right-cap, right-base */
	    etp3_(&nomhl, &nomhb, &c_b13, corxf, corx, cory, corz);
	    etp3_(&nomhl, &nomhc, &c_b13, corxf, &corx[1], &cory[1], &corz[1])
		    ;
	    etp3_(&nomhr, &nomhc, &c_b13, corxf, &corx[2], &cory[2], &corz[2])
		    ;
	    etp3_(&nomhr, &nomhb, &c_b13, corxf, &corx[3], &cory[3], &corz[3])
		    ;
	} else {
/*  set up for vertical path: */
	    nschh (&chhtv);
	    nschxp (&chxpv);
	    nstxp (&c__3);
/*  scxf = transformation to scale by chhtv */
	    esc3_(&chhtv, &chhtv, &chhtv, scxf);
/*  corxf = transformation for corners of text rectangle induced 
*/
/*          by text direction vectors and char-height: TLC to MC 
*/
/*        = scxf x tdrot */
	    ecom3_(scxf, tdrot, corxf);
/*  compute expected corners of text rectangle in MC, in order */
/*  1:left-base, 2:left-cap, 3:right-cap, 4:right-base */
	    etp3_(&nomvl, &nomvb, &c_b13, corxf, corx, cory, corz);
	    etp3_(&nomvl, &nomvc, &c_b13, corxf, &corx[1], &cory[1], &corz[1])
		    ;
	    etp3_(&nomvr, &nomvc, &c_b13, corxf, &corx[2], &cory[2], &corz[2])
		    ;
	    etp3_(&nomvr, &nomvb, &c_b13, corxf, &corx[3], &cory[3], &corz[3])
		    ;
	}
/*  the 4 computed corners form a scaled, rotated rectangle in 3D MC, 
*/
/*  and a parallelogram when projected to xy-plane. */
/*  cent = center point = (corlb + corlc + corrb + corrc) / 4 */
	centx = (corx[0] + corx[1] + corx[2] + corx[3]) / 4;
	centy = (cory[0] + cory[1] + cory[2] + cory[3]) / 4;
	centz = (corz[0] + corz[1] + corz[2] + corz[3]) / 4;
/*  base vector, char-up vector */
	hvecx = corx[3] - corx[0];
	hvecy = cory[3] - cory[0];
	hvecz = corz[3] - corz[0];
	vvecx = corx[1] - corx[0];
	vvecy = cory[1] - cory[0];
	vvecz = corz[1] - corz[0];
/*  d1vec = 1st diagonal vector = corrc-corlb */
/*  d2vec = 2nd diagonal vector = corlc-corrb */
	d1vecx = corx[2] - corx[0];
	d1vecy = cory[2] - cory[0];
	d1vecz = corz[2] - corz[0];
	d2vecx = corx[1] - corx[3];
	d2vecy = cory[1] - cory[3];
	d2vecz = corz[1] - corz[3];
/*  compute values for clipping planes and for expected vertices: */
	if (thiswn == 1 || thiswn == 4) {
/*  clip off all but one corner: */
/*  plpt(1) = (corlb + 2*cent) / 3 */
	    mcv3[0] = (corx[0] + centx * 2) / 3;
	    mcv3[1] = (cory[0] + centy * 2) / 3;
	    mcv3[2] = (corz[0] + centz * 2) / 3;
/*  vec(1)  = cross-product of d2vec x nvec */
	    crossp_(&nvecx, &nvecy, &nvecz, &d2vecx, &d2vecy, &d2vecz, &mcv3[
		    3], &mcv3[4], &mcv3[5]);
/*  number of half-planes */
	    numhp = 1;
/*  expected number of vertices */
	    expnum = 3;
/*  expected vertices */
	    expvx[0] = corx[0];
	    expvy[0] = cory[0];
	    expvz[0] = corz[0];
	    expvx[1] = (corx[1] * 2 + corx[0]) / 3;
	    expvy[1] = (cory[1] * 2 + cory[0]) / 3;
	    expvz[1] = (corz[1] * 2 + corz[0]) / 3;
	    expvx[2] = (corx[3] * 2 + corx[0]) / 3;
	    expvy[2] = (cory[3] * 2 + cory[0]) / 3;
	    expvz[2] = (corz[3] * 2 + corz[0]) / 3;
	} else if (thiswn == 2 || thiswn == 5) {
/*  clip off 4 corners: */
	    for (ix = 1; ix <= 4; ++ix) {
		mcv3[ix * 6 - 6] = (corx[ix - 1] * 2 + centx) / 3;
		mcv3[ix * 6 - 5] = (cory[ix - 1] * 2 + centy) / 3;
		mcv3[ix * 6 - 4] = (corz[ix - 1] * 2 + centz) / 3;
/* L120: */
	    }
	    crossp_(&d2vecx, &d2vecy, &d2vecz, &nvecx, &nvecy, &nvecz, &mcv3[
		    3], &mcv3[4], &mcv3[5]);
	    crossp_(&d1vecx, &d1vecy, &d1vecz, &nvecx, &nvecy, &nvecz, &mcv3[
		    9], &mcv3[10], &mcv3[11]);
	    for (ix = 3; ix <= 4; ++ix) {
		for (iy = 4; iy <= 6; ++iy) {
		    mcv3[iy + ix * 6 - 7] = -(doublereal)mcv3[iy + (ix - 2) * 
			    6 - 7];
/* L126: */
		}
/* L125: */
	    }
/*  number of half-planes */
	    numhp = 4;
/*  expected number of vertices */
	    expnum = 8;
/*  expected vertices */
	    for (ix = 1; ix <= 4; ++ix) {
		for (iy = 0; iy <= 1; ++iy) {
		    iex = (ix << 1) + iy - 1;
		    i__1 = ix + (iy << 1) - 1;
		    i2 = mod1_(&i__1, &c__4);
		    expvx[iex - 1] = (corx[ix - 1] * 2 + corx[i2 - 1]) / 3;
		    expvy[iex - 1] = (cory[ix - 1] * 2 + cory[i2 - 1]) / 3;
		    expvz[iex - 1] = (corz[ix - 1] * 2 + corz[i2 - 1]) / 3;
/* L131: */
		}
/* L130: */
	    }
	} else {
/*  (thiswn = 3 or 6) clip down the middle: */
/*  number of half-planes */
	    numhp = 1;
	    mcv3[0] = centx;
	    mcv3[1] = centy;
	    mcv3[2] = centz;
/*  expected number of vertices */
	    expnum = 4;
	    if (thiswn == 3) {
/*  clip horizontally - clip away top half */
/*  vec(1) = cross-product of hvec x nvec */
		crossp_(&hvecx, &hvecy, &hvecz, &nvecx, &nvecy, &nvecz, &mcv3[
			3], &mcv3[4], &mcv3[5]);
		expvx[0] = corx[0];
		expvy[0] = cory[0];
		expvz[0] = corz[0];
		expvx[1] = corx[3];
		expvy[1] = cory[3];
		expvz[1] = corz[3];
		expvx[2] = (corx[3] + corx[2]) / 2;
		expvy[2] = (cory[3] + cory[2]) / 2;
		expvz[2] = (corz[3] + corz[2]) / 2;
		expvx[3] = (corx[0] + corx[1]) / 2;
		expvy[3] = (cory[0] + cory[1]) / 2;
		expvz[3] = (corz[0] + corz[1]) / 2;
	    } else {
/*  clip vertically - clip away left side */
/*  vec(1) = cross-product of vvec x nvec */
		crossp_(&vvecx, &vvecy, &vvecz, &nvecx, &nvecy, &nvecz, &mcv3[
			3], &mcv3[4], &mcv3[5]);
		expvx[0] = corx[2];
		expvy[0] = cory[2];
		expvz[0] = corz[2];
		expvx[1] = corx[3];
		expvy[1] = cory[3];
		expvz[1] = corz[3];
		expvx[2] = (corx[3] + corx[0]) / 2;
		expvy[2] = (cory[3] + cory[0]) / 2;
		expvz[2] = (corz[3] + corz[0]) / 2;
		expvx[3] = (corx[2] + corx[1]) / 2;
		expvy[3] = (cory[2] + cory[1]) / 2;
		expvz[3] = (corz[2] + corz[1]) / 2;
	    }
	}
/*   set MCV (with REPLACE operator) */
	nsmcv3 (&c__1, &numhp, mcv3);
/*  draw 3D text */
	ntx3 (&c_b13, &c_b13, &c_b13, tdx, tdy, tdz, txstr, 7L);
	if (thiswn == ngwin) {
	    expvx[2] = centx;
	    expvy[2] = centy;
	    expvz[2] = centz;
	}
/*  compute expected vertices in WC */
	i__1 = expnum + 1;
	for (ix = 1; ix <= i__1; ++ix) {
	    iy = ix % expnum + 1;
	    etp3_(&expvx[iy - 1], &expvy[iy - 1], &expvz[iy - 1], xf, &xa[ix 
		    - 1], &ya[ix - 1], &za[ix - 1]);
/* L155: */
	}
	nsmcli (&c__0);
	idmat_(&c__4, scxf);
	nslmt3 (scxf, &c__2);
	i__1 = expnum + 1;
	npl (&i__1, xa, ya);
/*  next thiswn */
/* L100: */
    }
#ifndef NO_PROTO
    dchpfv_("MODELLING CLIPPING OF STROKE TEXT: In which window is the clipp"
	    "ed text NOT accurately outlined?", &c__6, &ngwin, 95L);
#else /* NO_PROTO */
    dchpfv_("MODELLING CLIPPING OF STROKE TEXT: In which window is the clipp\
ed text NOT accurately outlined?", &c__6, &ngwin, 95L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("40 41 42 43 53 57 58 60", "Characters in a text primitive drawn"
	    " in CHAR precision that lie completely outside the current model"
	    "ling clipping volume should be clipped, and those completely ins"
	    "ide should not be clipped.", 23L, 190L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 53 57 58 60", "Characters in a text primitive drawn\
 in CHAR precision that lie completely outside the current modelling clippin\
g volume should be clipped, and those completely inside should not be clippe\
d.", 23L, 190L);
#endif /* NO_PROTO */
/*  set constant attributes */
    nschsp (&c_b13);
    nstxfn (&txfont);
    nstxpr (&c__1);
    nstxal (&c__2, &c__3);
#ifndef NO_PROTO
    r__1 = chhth * .05f;
#else /* NO_PROTO */
    r__1 = chhth * (float).05;
#endif /* NO_PROTO */
    nschh (&r__1);
    nschxp (&c_b27);
    nstxp (&c__0);
    s_copy(chstr, "EEEEEEEEEEEEE", 13L, 13L);
    numvis = rndint_(&c__2, &c__6);
/*  number of characters drawn */
    txlen = (numvis << 1) + 1;
/*  set 2D MCV (with REPLACE operator) with 1 half-plane = */
/*     point: (.5,.5); vector: (1,0) */
    setrvs_(".5,.5, 1,0", mcv2, &ix, 10L);
    nsmcv (&c__1, &c__1, mcv2);
    nsmcli (&c__1);
    ntx (&c_b31, &c_b31, chstr, txlen);
#ifndef NO_PROTO
    dchoic_("MODELLING CLIPPING OF CHAR TEXT: How many characters are at lea"
	    "st partially visible?", &c__0, &c__15, &opans, 84L);
#else /* NO_PROTO */
    dchoic_("MODELLING CLIPPING OF CHAR TEXT: How many characters are at lea\
st partially visible?", &c__0, &c__15, &opans, 84L);
#endif /* NO_PROTO */
    if (opans == 0) {
	opfail_();
    } else {
	L__1 = opans == numvis || opans == numvis + 1;
	ifpf_(&L__1);
    }
    nemst (&c__102);
/*  *** *** *** ***   annotation text   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("40 41 42 43 53 57 58 61 62", "If its reference point is inside "
	    "the current MCV, then those parts of an annotation text primitiv"
	    "e that also lie inside should be visible, but if its reference p"
	    "oint is outside the current MCV, then the entire annotation text"
	    " primitive should be model-clipped.", 26L, 260L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 53 57 58 61 62", "If its reference point is inside \
the current MCV, then those parts of an annotation text primitive that also \
lie inside should be visible, but if its reference point is outside the curr\
ent MCV, then the entire annotation text primitive should be model-clipped.", 
	    26L, 260L);
#endif /* NO_PROTO */
/*  set up 6 windows */
    nexst (&c__106);
/*  npcpwc = NPC units per WC units */
    wcnpc_(&c_b13, &c_b13, &rdum1, &rdum2, &npcpwc);
/*  winsiz = window-size in NPC = window-size in WC * npcpwc */
    winsiz = xsiz * npcpwc;
    nstxfn (&c__1);
    nstxpr (&c__2);
    nstxci (&c__1);
    nschsp (&c_b13);
    nschxp (&c_b27);
#ifndef NO_PROTO
    r__1 = winsiz * .2f;
#else /* NO_PROTO */
    r__1 = winsiz * (float).2;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nsatp (&c__0);
    nsatal (&c__2, &c__3);
    nsans (&c__2);
    nsplci (&c__2);
    nsln (&c__1);
/*  ranwin = list of 6 integers chosen from 1-8 */
    rnset_(&c__6, &c__8, ranwin);
/*  vislis = list of windows with invisible annotation text = empty */
    visdx = 0;
/*  set clipping ON */
    nsmcli (&c__1);
/*  x-component of clipping vector */
#ifndef NO_PROTO
    mcv3[3] = 0.f;
#else /* NO_PROTO */
    mcv3[3] = (float)0.;
#endif /* NO_PROTO */
    for (thiswn = 1; thiswn <= 6; ++thiswn) {
	wntype = ranwin[thiswn - 1];
/*  center of window */
	mcv3[0] = xwinlo[thiswn - 1] + xsiz / 2;
	mcv3[1] = ywinlo[thiswn - 1] + ysiz / 2;
#ifndef NO_PROTO
	mcv3[2] = .5f;
#else /* NO_PROTO */
	mcv3[2] = (float).5;
#endif /* NO_PROTO */
/*  point MCV vector to 4 quadrants around the x-axis: */
	if (wntype % 4 < 2) {
#ifndef NO_PROTO
	    mcv3[4] = -1.f;
#else /* NO_PROTO */
	    mcv3[4] = (float)-1.;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    mcv3[4] = 1.f;
#else /* NO_PROTO */
	    mcv3[4] = (float)1.;
#endif /* NO_PROTO */
	}
	mcv3[5] = (real) ((wntype % 2 << 1) - 1);
	nsmcv3 (&c__1, &c__1, mcv3);
	if (wntype < 5) {
/*  should be partially visible: */
#ifndef NO_PROTO
	    delta = .01f;
#else /* NO_PROTO */
	    delta = (float).01;
#endif /* NO_PROTO */
	} else {
/*  should be invisible: */
	    ++visdx;
	    vislis[visdx - 1] = thiswn;
#ifndef NO_PROTO
	    delta = -.01f;
#else /* NO_PROTO */
	    delta = (float)-.01;
#endif /* NO_PROTO */
	}
/*  delta vector, in WC: */
	d1vecx = delta * 2;
	d1vecy = delta * mcv3[4];
	d1vecz = delta * mcv3[5];
/*  draw annotation text "ABC" at refpt with offset */
	r__1 = mcv3[0] + d1vecx;
	r__2 = mcv3[1] + d1vecy;
	r__3 = mcv3[2] + d1vecz;
	r__4 = d1vecx * -2 * npcpwc;
	r__5 = d1vecy * -2 * npcpwc;
	r__6 = d1vecz * -2 * npcpwc;
	natr3 (&r__1, &r__2, &r__3, &r__4, &r__5, &r__6, "ABC", 3L);
/*  next thiswn */
/* L200: */
    }
#ifndef NO_PROTO
    dlstpf_("MODELLING CLIPPING OF ENTIRE ANNOTATION TEXT: List all the empt"
	    "y windows.", &visdx, vislis, "S", 73L, 1L);
#else /* NO_PROTO */
    dlstpf_("MODELLING CLIPPING OF ENTIRE ANNOTATION TEXT: List all the empt\
y windows.", &visdx, vislis, "S", 73L, 1L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  *** *** *** *** *** *** *** *** *** *** *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("40 41 42 43 53 57 58 62", "If its reference point is inside the"
	    " current MCV, then at least those parts of an annotation text pr"
	    "imitive that also lie inside should be visible.", 23L, 147L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 53 57 58 62", "If its reference point is inside the\
 current MCV, then at least those parts of an annotation text primitive that\
 also lie inside should be visible.", 23L, 147L);
#endif /* NO_PROTO */
/*  txstr = text string with ASCII characters that fill character box */
    s_copy(atxstr, "EXAM", 4L, 4L);
    txfont = 1;
/*  *** *** ***  set up expected horizontal text extent: */
    txpath = 0;
    txexal_(&txfont, &txpath, atxstr, &ntxwd, &ntxht, htab, vtab, 4L);
/*  using text alignment = center,half: */
/* nomhl,nomhr = nominal x-location of left,right border of horizontal str
ing*/
/* nomhb,nomhc = nominal y-location of baseline,capline of horizontal stri
ng*/
    nomhl = htab[0] - htab[1];
    nomhr = htab[2] - htab[1];
    nomhb = vtab[3] - vtab[2];
    nomhc = vtab[1] - vtab[2];
/*  number of lines to display */
    numlin = 8;
#ifndef NO_PROTO
    yincr = 1 / (numlin + 1.f);
#else /* NO_PROTO */
    yincr = 1 / (numlin + (float)1.);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
/*  set achht (in WC) to scale ann-text so as to fit on line: */
#ifndef NO_PROTO
    achht = yincr * .5f;
#else /* NO_PROTO */
    achht = yincr * (float).5;
#endif /* NO_PROTO */
    nomhl *= achht;
    nomhr *= achht;
    nomhb *= achht;
    nomhc *= achht;
/*  set up attributes */
    nstxfn (&txfont);
    nstxpr (&c__2);
    nschsp (&c_b13);
    nschxp (&c_b27);
    r__1 = achht * npcpwc;
    nsatch (&r__1);
    nsatal (&c__2, &c__3);
    nsatp (&txpath);
    nstxci (&c__1);
    nsplci (&c__2);
    nsln (&c__3);
    nslwsc (&c_b20);
/*  draw labels for numlin lines */
    numlab_(&numlin, &c_b129, &ytop, &yincr);
/*  ngline = incorrect line = random from 1 to numlin */
    ngline = rndint_(&c__1, &numlin);
/*  expected number of vertices */
    expnum = 5;
    i__1 = numlin;
    for (thisln = 1; thisln <= i__1; ++thisln) {
	nsmcli (&c__1);
/*  compute values for clipping planes and for expected vertices: */
/*  compute expected annotation text position: */
	chxp = rndrl_(&c_b133, &c_b134);
/*  reference point for annotation text */
	xcent = rndrl_(&c_b135, &c_b136);
	xleft = xcent + nomhl * chxp;
	xrite = xcent + nomhr * chxp;
	ybas = yloc + nomhb;
	ycap = yloc + nomhc;
	nschxp (&chxp);
/*    clip down the middle: */
	mcv3[0] = xcent;
	mcv3[1] = yloc;
#ifndef NO_PROTO
	mcv3[2] = .5f;
	r__1 = .55f - xcent;
#else /* NO_PROTO */
	mcv3[2] = (float).5;
	r__1 = (float).55 - xcent;
#endif /* NO_PROTO */
	mcv3[3] = nomhc * r_sign(&c_b27, &r__1);
	mcv3[4] = nomhl * chxp * rndrl_(&c_b138, &c_b139);
#ifndef NO_PROTO
	mcv3[5] = .1f;
#else /* NO_PROTO */
	mcv3[5] = (float).1;
#endif /* NO_PROTO */
/*  set MCV (with REPLACE operator) with 1 half-plane */
	nsmcv3 (&c__1, &c__1, mcv3);
/*  delta vector, in WC: */
#ifndef NO_PROTO
	delta = .1f;
#else /* NO_PROTO */
	delta = (float).1;
#endif /* NO_PROTO */
	d1vecx = delta * mcv3[3];
	d1vecy = delta * mcv3[4];
	d1vecz = delta * mcv3[5];
/*     draw 3D annotation text: */
	r__1 = mcv3[0] + d1vecx;
	r__2 = mcv3[1] + d1vecy;
	r__3 = mcv3[2] + d1vecz;
	r__4 = -(doublereal)d1vecx * npcpwc;
	r__5 = -(doublereal)d1vecy * npcpwc;
	r__6 = -(doublereal)d1vecz * npcpwc;
	natr3 (&r__1, &r__2, &r__3, &r__4, &r__5, &r__6, atxstr, 4L);
/*  compute expected vertices in WC: */
	expvy[0] = ycap;
	expvy[1] = ybas;
	expvy[2] = ybas;
	expvy[3] = ycap;
	expvy[4] = ycap;
#ifndef NO_PROTO
	if (mcv3[3] > 0.f) {
#else /* NO_PROTO */
	if (mcv3[3] > (float)0.) {
#endif /* NO_PROTO */
	    expvx[0] = xrite;
	    expvx[1] = xrite;
	    expvx[4] = xrite;
	} else {
	    expvx[0] = xleft;
	    expvx[1] = xleft;
	    expvx[4] = xleft;
	}
	vyx = mcv3[4] / mcv3[3];
	expvx[2] = xcent + (yloc - ybas) * vyx;
	expvx[3] = xcent + (yloc - ycap) * vyx;
	if (thisln == ngline) {
/*  distort vertices: */
#ifndef NO_PROTO
	    delta = .15f;
	    if (xcent > .55f) {
#else /* NO_PROTO */
	    delta = (float).15;
	    if (xcent > (float).55) {
#endif /* NO_PROTO */
		delta = -(doublereal)delta;
	    }
	    i__2 = expnum;
	    for (ix = 1; ix <= i__2; ++ix) {
		expvx[ix - 1] += delta;
/* L410: */
	    }
	}
	nsmcli (&c__0);
/*     draw expected 2D polyline for expv(1 to expnum) */
	npl (&c__5, expvx, expvy);
	yloc -= yincr;
/*  next thisln */
/* L400: */
    }
#ifndef NO_PROTO
    dchpfv_("PARTIAL MODELLING CLIPPING OF ANNOTATION TEXT: On which line is"
	    " the dotted boundary NOT filled with annotation text (additional"
	    " annotation text outside boundary is permitted)?", &numlin, &
	    ngline, 175L);
#else /* NO_PROTO */
    dchpfv_("PARTIAL MODELLING CLIPPING OF ANNOTATION TEXT: On which line is\
 the dotted boundary NOT filled with annotation text (additional annotation \
text outside boundary is permitted)?", &numlin, &ngline, 175L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

