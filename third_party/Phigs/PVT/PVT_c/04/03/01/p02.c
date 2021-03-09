/* fort//04/03/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b16 = .15f;
#else /* NO_PROTO */
static real c_b16 = (float).15;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__4 = 4;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b61 = 0.f;
#else /* NO_PROTO */
static real c_b61 = (float)0.;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__8 = 8;
static integer c__9 = 9;
static integer c__10 = 10;
#ifndef NO_PROTO
static real c_b82 = .5f;
static real c_b113 = .1f;
static real c_b114 = .05f;
#else /* NO_PROTO */
static real c_b82 = (float).5;
static real c_b113 = (float).1;
static real c_b114 = (float).05;
#endif /* NO_PROTO */
static integer c__11 = 11;
static integer c__14 = 14;
static integer c__15 = 15;
static integer c__16 = 16;
static integer c__17 = 17;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.01/02                           * */
/*  *    TEST TITLE : Selective control of primitive        * */
/*  *                 aspects                               * */
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

    static logical styavl[5] = { FALSE_,FALSE_,FALSE_,FALSE_,FALSE_ };

    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer p1[10], p2[10], p3[10], p4[10], p5[10];
    static real xa[10], ya[10], za[10];
    static integer ix, ed1, ed2, nis, vmk[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer vln[2];
    static real tdx[2];
    static integer vis[2];
    static real tdy[2], tdz[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm (), ntx ();
#endif /* NO_PROTO */
    static char txt[14];
    static integer iix1, iix2;
    static real cxp1, cxp2;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl3 (integer *, real *, real *, real *), 
	    npm3 (integer *, real *, real *, real *), ntx3 (real *, real *, 
	    real *, real *, real *, real *, char *, ftnlen), nfas (integer *, 
	    integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl3 (), npm3 (), ntx3 (), nfas ();
#endif /* NO_PROTO */
    static integer vici[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer vedt[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nspa (real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspa ();
#endif /* NO_PROTO */
    static integer ibsw;
    static real yloc;
    static integer txci;
    static real npcx, npcy;
    static integer visi[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *), nsln (integer *), natr (
	    real *, real *, real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk (), nsln (), natr ();
#endif /* NO_PROTO */
    static integer next;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), nsis ();
#endif /* NO_PROTO */
    static integer nsiz, npts[1];
    static real xpos, ytop;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr3 (real *, real *, real *, real *, real *,
	     real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr3 ();
#endif /* NO_PROTO */
    static integer colia[4]	/* was [2][2] */, vedci[2], vedfg[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void), nsedi (integer *), nschh (real *), nsici (
	    integer *), wcnpc_(real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_(), nsedi (), nschh (), 
	    nsici (), wcnpc_();
#endif /* NO_PROTO */
    static integer vplci[2], vpmci[2], iprim;
    static real vmksc[2], vchxp[2];
    static integer vtxci[2];
    static real vlwsc[2], vchsp[2], vewsc[2], yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst ();
#endif /* NO_PROTO */
    static integer vtxfn[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nclst (void), nsvwi (
	    integer *), nqplf (integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *), nsplr (
	    integer *, integer *, integer *, real *, integer *), nspli (
	    integer *), nemst (integer *), nqpmf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , integer *), nspmr (integer *, integer *, integer *, real *, 
	    integer *), nspmi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nclst (), nsvwi (), nqplf (), 
	    nsplr (), nspli (), nemst (), nqpmf (), nspmr (), nspmi ();
#endif /* NO_PROTO */
    static integer vtxpr[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *), nstxr (integer *, integer *
	    , integer *, integer *, real *, real *, integer *), nstxi (
	    integer *), inmsg_(char *, ftnlen), nspar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nsedr (integer *, integer *, integer *, integer *, 
	    real *, integer *), nsedt (integer *);
    extern logical dchflv_(char *, integer *, integer *, ftnlen);
    extern /* Subroutine */ int nsedci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxf (), nstxr (), nstxi (), inmsg_(), 
	    nspar (), nsedr (), nsedt ();
    extern logical dchflv_();
    extern /* Subroutine */ int nsedci ();
#endif /* NO_PROTO */
    static integer flgsrc, nedwid;
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, ndisct, numlin, ngprim;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer typsrc, widsrc, colsrc, thisis, fntsrc, prcsrc, expsrc, 
	    spcsrc, nedtyp;
    static real minchx, maxchx, nomsiz, npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), discol_(integer *, integer *, integer *), setmsg_(
	    char *, char *, ftnlen, ftnlen), chkinq_(char *, integer *, 
	    ftnlen), nspmci (integer *), nstxci (integer *), numlab_(integer *
	    , real *, real *, real *), rnperm_(integer *, integer *), nslwsc (
	    real *), nsplci (integer *), nsiasf (integer *, integer *), 
	    dchpfv_(char *, integer *, integer *, ftnlen), setrvs_(char *, 
	    real *, integer *, ftnlen), nsmksc (real *), nstxal (integer *, 
	    integer *), nsatch (real *), nsatal (integer *, integer *), 
	    nstxfn (integer *), nstxpr (integer *), nschxp (real *), nschsp (
	    real *), asfint_(integer *, integer *, integer *, integer *, 
	    integer *), setval_(char *, integer *, ftnlen), nsedfg (integer *)
	    , nsewsc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), discol_(), setmsg_(), 
	    chkinq_(), nspmci (), nstxci (), numlab_(), rnperm_(), nslwsc (), 
	    nsplci (), nsiasf (), dchpfv_(), setrvs_(), nsmksc (), nstxal (), 
	    nsatch (), nsatal (), nstxfn (), nstxpr (), nschxp (), nschsp (), 
	    asfint_(), setval_(), nsedfg (), nsewsc ();
#endif /* NO_PROTO */

/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
/* interior style */
/* off/on switch for edge flag and error handling mode */
/* aspect identifier */
/* aspect source */
/*                bundled     individual */
/* aspect visibility */
/* alternative values for all attributes: */
/* alternative values for all attributes: */
    initgl_("04.03.01/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
/*  try to set color table with #1,2,3 distinct */
    discol_(&c__3, &globnu_1.wkid, &ndisct);
/*  use IBSW to switch individual/bundled */
    ibsw = 1;
/*  *** *** *** ***   polyline   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of "
	    "the non-geometric aspects of polyline primitives using either in"
	    "dividual or bundled control.", 13L, 138L);
#else /* NO_PROTO */
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of \
the non-geometric aspects of polyline primitives using either individual or \
bundled control.", 13L, 138L);
#endif /* NO_PROTO */
    nqplf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomsiz, 
	    &rdum1, &rdum2, &idum4);
    chkinq_("pqplf", &errind, 5L);
/*  aspects to be displayed: */
/*  linetype = 2, linewidth = 0.05 in WC, linecolor = 2 */
    vln[0] = 2;
#ifndef NO_PROTO
    vlwsc[0] = .05f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    vlwsc[0] = (float).05 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    vplci[0] = 2;
/*  aspects to be suppressed: */
/*  linetype = 1, linewidth = 0.0001 in WC, linecolor = 1 */
    vln[1] = 1;
#ifndef NO_PROTO
    vlwsc[1] = 1e-4f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    vlwsc[1] = (float)1e-4 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    vplci[1] = 1;
/*  set individual color indices for other primitives to 3, to make */
/*    sure they don't interact with polyline. */
    nspmci (&c__3);
    nstxci (&c__3);
    nsici (&c__3);
    nsedci (&c__3);
/*  number of lines to be displayed */
    numlin = 6;
/*  primitive to be drawn incorrectly */
    ngprim = rndint_(&c__1, &numlin);
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
    numlab_(&numlin, &c_b16, &ytop, &yincr);
#ifndef NO_PROTO
    xa[0] = .2f;
    xa[1] = .8f;
    za[0] = .5f;
    za[1] = .5f;
#else /* NO_PROTO */
    xa[0] = (float).2;
    xa[1] = (float).8;
    za[0] = (float).5;
    za[1] = (float).5;
#endif /* NO_PROTO */
/*  ensure both individual and bundle are picked for each aspect */
    rnperm_(&numlin, p1);
    rnperm_(&numlin, p2);
    rnperm_(&numlin, p3);
/*  loop to draw primitives */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  randomly pick source for aspects: */
/*  assume here that bundle/individ represented by 0/1 */
	typsrc = p1[ix - 1] % 2;
	widsrc = p2[ix - 1] % 2;
	colsrc = p3[ix - 1] % 2;
/*  set bundle #ix to displayed aspects, for BUNDLED source */
/*               and suppressed aspects, for INDIVIDUAL source */
	nsplr (&globnu_1.wkid, &ix, &vln[typsrc], &vlwsc[widsrc], &vplci[
		colsrc]);
	nspli (&ix);
/*  set individual attributes */
/*                 to displayed aspects, for INDIVIDUAL source */
/*               and suppressed aspects, for BUNDLED source */
	nsln (&vln[ibsw - typsrc]);
	nslwsc (&vlwsc[ibsw - widsrc]);
	nsplci (&vplci[ibsw - colsrc]);
/*  set ASF flags in accordance with typsrc,widsrc,colsrc */
	nsiasf (&c__0, &typsrc);
	nsiasf (&c__1, &widsrc);
	nsiasf (&c__2, &colsrc);
	if (ix == ngprim) {
/*  set ASF flag NOT in accordance with typsrc */
	    i__2 = ibsw - typsrc;
	    nsiasf (&c__0, &i__2);
	    i__2 = ibsw - widsrc;
	    nsiasf (&c__1, &i__2);
	    i__2 = ibsw - colsrc;
	    nsiasf (&c__2, &i__2);
	}
	ya[0] = yloc;
	ya[1] = yloc;
	if (ix <= numlin / 2) {
	    npl (&c__2, xa, ya);
	} else {
	    npl3 (&c__2, xa, ya, za);
	}
	yloc -= yincr;
/*  next ix */
/* L100: */
    }
    dchpfv_("ASF CONTROL OF POLYLINE: Which line is different?", &numlin, &
	    ngprim, 49L);
    nemst (&c__102);
/*  *** *** *** ***   polymarker   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of "
	    "the non-geometric aspects of polymarker primitives using either "
	    "individual or bundled control.", 13L, 140L);
#else /* NO_PROTO */
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of \
the non-geometric aspects of polymarker primitives using either individual o\
r bundled control.", 13L, 140L);
#endif /* NO_PROTO */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomsiz, 
	    &rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  aspects to be displayed: */
/*  markertype = 4, markerwidth = 0.05 in WC, markercolor = 2 */
    vmk[0] = 4;
#ifndef NO_PROTO
    vmksc[0] = .05f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    vmksc[0] = (float).05 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    vpmci[0] = 2;
/*  aspects to be suppressed: */
/*  markertype = 5, markerwidth = 0.03 in WC, markercolor = 1 */
    vmk[1] = 5;
#ifndef NO_PROTO
    vmksc[1] = .03f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    vmksc[1] = (float).03 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    vpmci[1] = 1;
/*  set individual color indices for other primitives to 3, to make */
/*    sure they don't interact with polymarker. */
    nsplci (&c__3);
    nstxci (&c__3);
    nsici (&c__3);
    nsedci (&c__3);
/*  number of lines to be displayed */
    numlin = 6;
/*  primitive to be drawn incorrectly */
    ngprim = rndint_(&c__1, &numlin);
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
    numlab_(&numlin, &c_b16, &ytop, &yincr);
    setrvs_("0.4,0.6,0.8", xa, &nsiz, 11L);
    setrvs_("0.5,0.5,0.5", za, &nsiz, 11L);
/*  ensure both individual and bundle are picked for each aspect */
    rnperm_(&numlin, p1);
    rnperm_(&numlin, p2);
    rnperm_(&numlin, p3);
/*  loop to draw primitives */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  randomly pick source for aspects: */
/*  assume here that bundle/individ represented by 0/1 */
	typsrc = p1[ix - 1] % 2;
	widsrc = p2[ix - 1] % 2;
	colsrc = p3[ix - 1] % 2;
/*  set bundle #ix to displayed aspects, for BUNDLED source */
/*               and suppressed aspects, for INDIVIDUAL source */
	nspmr (&globnu_1.wkid, &ix, &vmk[typsrc], &vmksc[widsrc], &vpmci[
		colsrc]);
	nspmi (&ix);
/*  set individual attributes */
/*                 to displayed aspects, for INDIVIDUAL source */
/*               and suppressed aspects, for BUNDLED source */
	nsmk (&vmk[ibsw - typsrc]);
	nsmksc (&vmksc[ibsw - widsrc]);
	nspmci (&vpmci[ibsw - colsrc]);
/*  set ASF flags in accordance with typsrc,widsrc,colsrc */
	nsiasf (&c__3, &typsrc);
	nsiasf (&c__4, &widsrc);
	nsiasf (&c__5, &colsrc);
	if (ix == ngprim) {
/*  set ASF flags NOT in accordance with typsrc, etc. */
	    i__2 = ibsw - typsrc;
	    nsiasf (&c__3, &i__2);
	    i__2 = ibsw - widsrc;
	    nsiasf (&c__4, &i__2);
	    i__2 = ibsw - colsrc;
	    nsiasf (&c__5, &i__2);
	}
	ya[0] = yloc;
	ya[1] = yloc;
	ya[2] = yloc;
	if (ix <= numlin / 2) {
	    npm (&c__3, xa, ya);
	} else {
	    npm3 (&c__3, xa, ya, za);
	}
	yloc -= yincr;
/*  next ix */
/* L200: */
    }
    dchpfv_("ASF CONTROL OF POLYMARKER: Which marker is different?", &numlin, 
	    &ngprim, 53L);
    nemst (&c__102);
/*  *** *** *** ***   text   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of "
	    "the non-geometric aspects of text and annotation text primitives"
	    " using either individual or bundled control.", 13L, 154L);
#else /* NO_PROTO */
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of \
the non-geometric aspects of text and annotation text primitives using eithe\
r individual or bundled control.", 13L, 154L);
#endif /* NO_PROTO */
/*  aspects to be displayed: font = 2, precision = STROKE, */
/*  expansion = 0.5, spacing = 0.3, textcolor = 2 */
    vtxfn[0] = 2;
    vtxpr[0] = 2;
#ifndef NO_PROTO
    vchsp[0] = .3f;
#else /* NO_PROTO */
    vchsp[0] = (float).3;
#endif /* NO_PROTO */
    vtxci[0] = 2;
/*  try to pick two distinct values for char-exp within the limits */
/*  of the workstation. */
    nqtxf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &idum4, &
	    rdum1, &rdum2, &idum5, &minchx, &maxchx, &idum6);
    chkinq_("pqtxf", &errind, 5L);
#ifndef NO_PROTO
    if (maxchx <= minchx * 2.5f) {
#else /* NO_PROTO */
    if (maxchx <= minchx * (float)2.5) {
#endif /* NO_PROTO */
/*        range of factors small - use whole range */
	cxp1 = minchx;
	cxp2 = maxchx;
#ifndef NO_PROTO
    } else if (maxchx <= 1.f) {
#else /* NO_PROTO */
    } else if (maxchx <= (float)1.) {
#endif /* NO_PROTO */
	cxp2 = maxchx;
#ifndef NO_PROTO
	cxp1 = cxp2 / 2.5f;
    } else if (minchx >= 1.f) {
#else /* NO_PROTO */
	cxp1 = cxp2 / (float)2.5;
    } else if (minchx >= (float)1.) {
#endif /* NO_PROTO */
	cxp1 = minchx;
#ifndef NO_PROTO
	cxp2 = cxp1 * 2.5f;
#else /* NO_PROTO */
	cxp2 = cxp1 * (float)2.5;
#endif /* NO_PROTO */
    } else {
#ifndef NO_PROTO
	cxp1 = dmax(.5f,minchx);
	cxp2 = dmin(1.2f,maxchx);
#else /* NO_PROTO */
	cxp1 = dmax((float).5,minchx);
	cxp2 = dmin((float)1.2,maxchx);
#endif /* NO_PROTO */
    }
    vchxp[0] = cxp1;
/*  aspects to be suppressed: font = 1, precision = STRING, */
/*  expansion = 1.2, spacing = -0.3, textcolor = 1 */
    vtxfn[1] = 1;
    vtxpr[1] = 0;
#ifndef NO_PROTO
    vchsp[1] = -.3f;
#else /* NO_PROTO */
    vchsp[1] = (float)-.3;
#endif /* NO_PROTO */
    vtxci[1] = 1;
    vchxp[1] = cxp2;
/*  set individual color indices for other primitives to 3, to make */
/*    sure they don't interact with text. */
    nsplci (&c__3);
    nspmci (&c__3);
    nsici (&c__3);
    nsedci (&c__3);
/*  number of lines to be displayed */
    numlin = 6;
/*  primitive to be drawn incorrectly */
    ngprim = rndint_(&c__1, &numlin);
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
    numlab_(&numlin, &c_b16, &ytop, &yincr);
/*  use iprim to pick out different primitives */
    iprim = 1;
    wcnpc_(&c_b61, &c_b61, &npcx, &npcy, &npcpwc);
#ifndef NO_PROTO
    r__1 = yincr * .4f;
#else /* NO_PROTO */
    r__1 = yincr * (float).4;
#endif /* NO_PROTO */
    nschh (&r__1);
    nstxal (&c__1, &c__3);
#ifndef NO_PROTO
    r__1 = yincr * .4f * npcpwc;
#else /* NO_PROTO */
    r__1 = yincr * (float).4 * npcpwc;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nsatal (&c__1, &c__3);
#ifndef NO_PROTO
    xpos = .2f;
#else /* NO_PROTO */
    xpos = (float).2;
#endif /* NO_PROTO */
    s_copy(txt, "Who's special?", 14L, 14L);
/*  ensure both individual and bundle are picked for each aspect */
    rnperm_(&numlin, p1);
    rnperm_(&numlin, p2);
    rnperm_(&numlin, p3);
    rnperm_(&numlin, p4);
    rnperm_(&numlin, p5);
/*  loop to draw primitives */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  randomly pick source for aspects: */
/*  assume here that bundle/individ represented by 0/1 */
	fntsrc = p1[ix - 1] % 2;
	prcsrc = p2[ix - 1] % 2;
	expsrc = p3[ix - 1] % 2;
	spcsrc = p4[ix - 1] % 2;
	colsrc = p5[ix - 1] % 2;
/*  set bundle #ix to displayed aspects, for BUNDLED source */
/*               and suppressed aspects, for INDIVIDUAL source */
	nstxr (&globnu_1.wkid, &ix, &vtxfn[fntsrc], &vtxpr[prcsrc], &vchxp[
		expsrc], &vchsp[spcsrc], &vtxci[colsrc]);
	nstxi (&ix);
/*  set individual attributes */
/*                 to displayed aspects, for INDIVIDUAL source */
/*               and suppressed aspects, for BUNDLED source */
	nstxfn (&vtxfn[ibsw - fntsrc]);
	nstxpr (&vtxpr[ibsw - prcsrc]);
	nschxp (&vchxp[ibsw - expsrc]);
	nschsp (&vchsp[ibsw - spcsrc]);
	nstxci (&vtxci[ibsw - colsrc]);
/*     set ASF flags in accordance with */
/*       fntsrc, prcsrc, expsrc, spcsrc, colsrc */
	nsiasf (&c__6, &fntsrc);
	nsiasf (&c__7, &prcsrc);
	nsiasf (&c__8, &expsrc);
	nsiasf (&c__9, &spcsrc);
	nsiasf (&c__10, &colsrc);
	if (ix == ngprim) {
/*  set ASF flags NOT in accordance with xxxsrc */
	    i__2 = ibsw - fntsrc;
	    nsiasf (&c__6, &i__2);
	    i__2 = ibsw - prcsrc;
	    nsiasf (&c__7, &i__2);
	    i__2 = ibsw - expsrc;
	    nsiasf (&c__8, &i__2);
	    i__2 = ibsw - spcsrc;
	    nsiasf (&c__9, &i__2);
	    i__2 = ibsw - colsrc;
	    nsiasf (&c__10, &i__2);
	    next = iprim;
	} else {
/*  iprim ensures that each primitive is drawn correctly at least 
once */
	    next = iprim + 1;
	}
	if (iprim == 1) {
	    ntx (&xpos, &yloc, txt, 14L);
	} else if (iprim == 2) {
	    setrvs_("1,0", tdx, &nsiz, 3L);
	    setrvs_("0,1", tdy, &nsiz, 3L);
	    setrvs_("0,0", tdz, &nsiz, 3L);
	    ntx3 (&xpos, &yloc, &c_b82, tdx, tdy, tdz, txt, 14L);
	} else if (iprim == 3) {
	    natr (&xpos, &yloc, &c_b61, &c_b61, txt, 14L);
	} else if (iprim == 4) {
	    natr3 (&xpos, &yloc, &c_b82, &c_b61, &c_b61, &c_b61, txt, 14L);
	} else {
	    ntx (&xpos, &yloc, txt, 14L);
	}
	yloc -= yincr;
	iprim = next;
/*  next ix */
/* L300: */
    }
    dchpfv_("ASF CONTROL OF TEXT: Which text is different?", &numlin, &ngprim,
	     45L);
    nemst (&c__102);
/*  *** *** *** ***   interior bundle   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of "
	    "the non-geometric aspects in the interior bundle using either in"
	    "dividual or bundled control.", 13L, 138L);
#else /* NO_PROTO */
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of \
the non-geometric aspects in the interior bundle using either individual or \
bundled control.", 13L, 138L);
#endif /* NO_PROTO */
/*  set individual color indices for other primitives to 3, to make */
/*    sure they don't interact with interior. */
    nsplci (&c__3);
    nspmci (&c__3);
    nstxci (&c__3);
    nsedci (&c__3);
/*  *** *** *** ***   interior style   *** *** *** *** */

/*  aspects to be displayed: */
/*  interior style = HOLLOW, interior index = 1, interior-color = 2 */
    vis[0] = 0;
    visi[0] = 1;
    vici[0] = 2;
/*  aspects to be suppressed: */
/*  interior style = EMPTY, interior index = 1, interior-color = 1 */
    vis[1] = 4;
    visi[1] = 1;
    vici[1] = 1;
    asfint_(vis, visi, vici, &numlin, &ngprim);
    if (dchflv_("ASF CONTROL OF INTERIOR STYLE: Which interior is different?",
	     &numlin, &ngprim, 59L)) {
	inmsg_("Failure occurred for interior style.", 36L);
	goto L490;
    }
    nemst (&c__102);
/*  *** *** *** ***   interior index   *** *** *** *** */
/*  check available interior styles */
    nqif (&dialog_1.specwt, &c__0, &c__0, &errind, &nis, &idum1, &idum2, &
	    idum3, &idum4);
    chkinq_("pqif", &errind, 4L);
    i__1 = abs(nis);
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (&dialog_1.specwt, &ix, &c__0, &errind, &idum1, &thisis, &idum2, 
		&idum3, &idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisis >= 0 && thisis <= 4) {
	    styavl[thisis] = TRUE_;
	}
/* L410: */
    }
    if (styavl[3]) {
/*  using HATCH - get hatch styles */
	thisis = 3;
	nqif (&dialog_1.specwt, &c__0, &c__1, &errind, &idum1, &idum2, &idum3,
		 &iix1, &idum4);
	chkinq_("pqif", &errind, 4L);
	nqif (&dialog_1.specwt, &c__0, &c__2, &errind, &idum1, &idum2, &idum3,
		 &iix2, &idum4);
	chkinq_("pqif", &errind, 4L);
    } else if (styavl[2]) {
/*  using PATTERN */
	thisis = 2;
	nspa (&c_b113, &c_b114);
	iix1 = 1;
	iix2 = 2;
/*  set up two distinct patterns */
	setval_("1,1,1,0", colia, 7L);
	nspar (&globnu_1.wkid, &c__1, &c__2, &c__2, &c__1, &c__1, &c__2, &
		c__2, colia);
	setval_("0,0,1,0", colia, 7L);
	nspar (&globnu_1.wkid, &c__2, &c__2, &c__2, &c__1, &c__1, &c__2, &
		c__2, colia);
    } else {
/*  no style sensitive to interior style index is available */
	goto L450;
    }
/*  interior indices now set; */
/*  aspects to be displayed: */
/*  interior style = int-style, interior index = iix1, interior-color = 2 
*/
    vis[0] = thisis;
    visi[0] = iix1;
    vici[0] = 2;
/*  aspects to be suppressed: */
/*  interior style = int-style, interior index = iix2, interior-color = 1 
*/
    vis[1] = thisis;
    visi[1] = iix2;
    vici[1] = 1;
    asfint_(vis, visi, vici, &numlin, &ngprim);
#ifndef NO_PROTO
    if (dchflv_("ASF CONTROL OF INTERIOR STYLE INDEX: Which interior is diff"
	    "erent?", &numlin, &ngprim, 65L)) {
#else /* NO_PROTO */
    if (dchflv_("ASF CONTROL OF INTERIOR STYLE INDEX: Which interior is diff\
erent?", &numlin, &ngprim, 65L)) {
#endif /* NO_PROTO */
	inmsg_("Failure occurred for interior style index.", 42L);
	goto L490;
    }
    nemst (&c__102);
/*  end_int_index: */
L450:
/*  *** *** *** ***   interior color   *** *** *** *** */
/*  if (number of distinct colors < 2) no color test */
    if (ndisct < 2) {
	pass_();
	goto L490;
    }
    if (styavl[1]) {
	thisis = 1;
    } else {
	thisis = 0;
    }
/*  aspects to be displayed: */
/*  interior style = int-style, interior index = 1, interior-color = 2 */
    vis[0] = thisis;
    visi[0] = 1;
    vici[0] = 2;
/*  aspects to be suppressed: */
/*  interior style = int-style, interior index = 1, interior-color = 1 */
    vis[1] = thisis;
    visi[1] = 1;
    vici[1] = 1;
    asfint_(vis, visi, vici, &numlin, &ngprim);
#ifndef NO_PROTO
    if (dchflv_("ASF CONTROL OF INTERIOR COLOR: Which interior color is diff"
	    "erent?", &numlin, &ngprim, 65L)) {
#else /* NO_PROTO */
    if (dchflv_("ASF CONTROL OF INTERIOR COLOR: Which interior color is diff\
erent?", &numlin, &ngprim, 65L)) {
#endif /* NO_PROTO */
	inmsg_("Failure occurred for interior color index.", 42L);
    } else {
	pass_();
    }
/*  end_int: */
L490:
    nemst (&c__102);
/*  *** *** *** ***   edge bundle   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of "
	    "the non-geometric aspects in the edge bundle using either indivi"
	    "dual or bundled control.", 13L, 134L);
#else /* NO_PROTO */
    setmsg_("1 4 5 6 7 8 9", "The program should be able to specify each of \
the non-geometric aspects in the edge bundle using either individual or bund\
led control.", 13L, 134L);
#endif /* NO_PROTO */
/*  set individual color indices for other primitives to 3, to make */
/*    sure they don't interact with edge color. */
    nsplci (&c__3);
    nspmci (&c__3);
    nstxci (&c__3);
    nsici (&c__3);
    nqedf (&dialog_1.specwt, &c__0, &errind, &nedtyp, &idum1, &nedwid, &
	    nomsiz, &rdum1, &rdum2, &idum4);
    chkinq_("pqedf", &errind, 5L);
    nedtyp = abs(nedtyp);
/*  ed1,ed2 = two available edge types */
    nqedf (&dialog_1.specwt, &c__1, &errind, &idum1, &ed1, &idum2, &rdum1, &
	    rdum2, &rdum3, &idum4);
    chkinq_("pqedf", &errind, 5L);
    if (nedtyp > 1) {
	nqedf (&dialog_1.specwt, &c__2, &errind, &idum1, &ed2, &idum2, &rdum1,
		 &rdum2, &rdum3, &idum4);
	chkinq_("pqedf", &errind, 5L);
    } else {
	ed2 = ed1;
    }
/*  *** *** *** ***   edge flag   *** *** *** *** */

/*  aspects to be displayed: */
/*  edge flag = ON, edgetype = ed2, edgewidth = 0.02 in WC, edgecolor = 2 
*/
    vedfg[0] = 1;
    vedt[0] = ed2;
#ifndef NO_PROTO
    vewsc[0] = .02f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    vewsc[0] = (float).02 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    vedci[0] = 2;
/*  aspects to be suppressed: */
/* edge flag = OFF, edgetype = ed1, edgewidth = 0.001 in WC, edgecolor = 1
*/
    vedfg[1] = 0;
    vedt[1] = ed1;
#ifndef NO_PROTO
    vewsc[1] = .001f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    vewsc[1] = (float).001 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    vedci[1] = 1;
/*  set interior style = EMPTY */
    nsiasf (&c__11, &c__1);
    nsis (&c__4);
/*  number of lines to be displayed */
    numlin = 6;
/*  primitive to be drawn incorrectly */
    ngprim = rndint_(&c__1, &numlin);
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
    numlab_(&numlin, &c_b16, &ytop, &yincr);
#ifndef NO_PROTO
    xa[0] = .2f;
    xa[1] = .2f;
    xa[2] = .8f;
    za[0] = .5f;
    za[1] = .5f;
    za[2] = .5f;
#else /* NO_PROTO */
    xa[0] = (float).2;
    xa[1] = (float).2;
    xa[2] = (float).8;
    za[0] = (float).5;
    za[1] = (float).5;
    za[2] = (float).5;
#endif /* NO_PROTO */
    npts[0] = 3;
/*  ensure both individual and bundle are picked for each aspect */
    rnperm_(&numlin, p1);
    rnperm_(&numlin, p2);
    rnperm_(&numlin, p3);
    rnperm_(&numlin, p4);
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  randomly pick source for aspects: */
/*  assume here that bundle/individ represented by 0/1 */
	flgsrc = p1[ix - 1] % 2;
	typsrc = p2[ix - 1] % 2;
	widsrc = p3[ix - 1] % 2;
	colsrc = p4[ix - 1] % 2;
/*     set bundle #ix to displayed aspects, for BUNDLED source */
/*                  and suppressed aspects, for INDIVIDUAL source */
	nsedr (&globnu_1.wkid, &ix, &vedfg[flgsrc], &vedt[typsrc], &vewsc[
		widsrc], &vedci[colsrc]);
	nsedi (&ix);
/*     set individual attributes */
/*                    to displayed aspects, for INDIVIDUAL source */
/*                  and suppressed aspects, for BUNDLED source */
	nsedfg (&vedfg[ibsw - flgsrc]);
	nsedt (&vedt[ibsw - typsrc]);
	nsewsc (&vewsc[ibsw - widsrc]);
	nsedci (&vedci[ibsw - colsrc]);
/*     set ASF flags in accordance with: flgsrc,typsrc,widsrc,colsrc 
*/
	nsiasf (&c__14, &flgsrc);
	nsiasf (&c__15, &typsrc);
	nsiasf (&c__16, &widsrc);
	nsiasf (&c__17, &colsrc);
	if (ix == ngprim) {
/*  set ASF flag NOT in accordance with sources */
	    i__2 = ibsw - flgsrc;
	    nsiasf (&c__14, &i__2);
	    i__2 = ibsw - typsrc;
	    nsiasf (&c__15, &i__2);
	    i__2 = ibsw - widsrc;
	    nsiasf (&c__16, &i__2);
	    i__2 = ibsw - colsrc;
	    nsiasf (&c__17, &i__2);
	}
#ifndef NO_PROTO
	ya[0] = yloc + yincr * .3f;
	ya[1] = yloc - yincr * .3f;
	ya[2] = yloc - yincr * .3f;
#else /* NO_PROTO */
	ya[0] = yloc + yincr * (float).3;
	ya[1] = yloc - yincr * (float).3;
	ya[2] = yloc - yincr * (float).3;
#endif /* NO_PROTO */
	if (ix <= numlin / 2) {
	    nfas (&c__1, npts, xa, ya);
	} else {
	    nfas3 (&c__1, npts, xa, ya, za);
	}
	yloc -= yincr;
/*  next ix */
/* L500: */
    }
    if (dchflv_("ASF CONTROL OF EDGE FLAG: Which edge is different?", &numlin,
	     &ngprim, 50L)) {
	inmsg_("Failure occurred for edge flag.", 31L);
	goto L590;
    }
    nemst (&c__102);
/*  *** *** *** ***   edge type,width,color   *** *** *** *** */
/*  any other distinguishing aspects? */
    if (nedtyp == 1 && nedwid == 1 && ndisct == 1) {
/*  only one edge type,width,color available */
	pass_();
	goto L590;
    }
/*  aspects to be displayed: */
/*  edge flag = ON, edgetype = ed2, edgewidth = 0.02 in WC, edgecolor = 2 
*/
    vedfg[0] = 1;
    vedt[0] = ed2;
#ifndef NO_PROTO
    vewsc[0] = .02f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    vewsc[0] = (float).02 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    vedci[0] = 2;
/*  aspects to be suppressed: */
/*  edge flag = ON, edgetype = ed1, edgewidth = 0.001 in WC, edgecolor = 1
 */
    vedfg[1] = 1;
    vedt[1] = ed1;
#ifndef NO_PROTO
    vewsc[1] = .001f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    vewsc[1] = (float).001 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    vedci[1] = 1;
/*  set interior style = EMPTY */
    nsiasf (&c__11, &c__1);
    nsis (&c__4);
/*  number of lines to be displayed */
    numlin = 6;
/*  primitive to be drawn incorrectly */
    ngprim = rndint_(&c__1, &numlin);
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
    numlab_(&numlin, &c_b16, &ytop, &yincr);
#ifndef NO_PROTO
    xa[0] = .2f;
    xa[1] = .2f;
    xa[2] = .8f;
    za[0] = .5f;
    za[1] = .5f;
    za[2] = .5f;
#else /* NO_PROTO */
    xa[0] = (float).2;
    xa[1] = (float).2;
    xa[2] = (float).8;
    za[0] = (float).5;
    za[1] = (float).5;
    za[2] = (float).5;
#endif /* NO_PROTO */
    npts[0] = 3;
/*  ensure both individual and bundle are picked for each aspect */
    rnperm_(&numlin, p1);
    rnperm_(&numlin, p2);
    rnperm_(&numlin, p3);
    rnperm_(&numlin, p4);
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  randomly pick source for aspects: */
/*  assume here that bundle/individ represented by 0/1 */
	flgsrc = p1[ix - 1] % 2;
	typsrc = p2[ix - 1] % 2;
	widsrc = p3[ix - 1] % 2;
	colsrc = p4[ix - 1] % 2;
/*     set bundle #ix to displayed aspects, for BUNDLED source */
/*                  and suppressed aspects, for INDIVIDUAL source */
	nsedr (&globnu_1.wkid, &ix, &vedfg[flgsrc], &vedt[typsrc], &vewsc[
		widsrc], &vedci[colsrc]);
	nsedi (&ix);
/*     set individual attributes */
/*                    to displayed aspects, for INDIVIDUAL source */
/*                  and suppressed aspects, for BUNDLED source */
	nsedfg (&vedfg[ibsw - flgsrc]);
	nsedt (&vedt[ibsw - typsrc]);
	nsewsc (&vewsc[ibsw - widsrc]);
	nsedci (&vedci[ibsw - colsrc]);
/*     set ASF flags in accordance with: flgsrc,typsrc,widsrc,colsrc 
*/
	nsiasf (&c__14, &flgsrc);
	nsiasf (&c__15, &typsrc);
	nsiasf (&c__16, &widsrc);
	nsiasf (&c__17, &colsrc);
	if (ix == ngprim) {
/*  set ASF flag NOT in accordance with sources */
	    i__2 = ibsw - flgsrc;
	    nsiasf (&c__14, &i__2);
	    i__2 = ibsw - typsrc;
	    nsiasf (&c__15, &i__2);
	    i__2 = ibsw - widsrc;
	    nsiasf (&c__16, &i__2);
	    i__2 = ibsw - colsrc;
	    nsiasf (&c__17, &i__2);
	}
#ifndef NO_PROTO
	ya[0] = yloc + yincr * .3f;
	ya[1] = yloc - yincr * .3f;
	ya[2] = yloc - yincr * .3f;
#else /* NO_PROTO */
	ya[0] = yloc + yincr * (float).3;
	ya[1] = yloc - yincr * (float).3;
	ya[2] = yloc - yincr * (float).3;
#endif /* NO_PROTO */
	if (ix <= numlin / 2) {
	    nfas (&c__1, npts, xa, ya);
	} else {
	    nfas3 (&c__1, npts, xa, ya, za);
	}
	yloc -= yincr;
/*  next ix */
/* L600: */
    }
    if (dchflv_("ASF CONTROL OF EDGE ASPECTS: Which edge is different?", &
	    numlin, &ngprim, 53L)) {
	inmsg_("Failure occurred for edge aspects.", 34L);
    } else {
	pass_();
    }
/*  end_edge: */
L590:
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

