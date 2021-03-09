/* fort/04/02/01/02/p11.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b12 = 1.f;
static real c_b14 = .2f;
#else /* NO_PROTO */
static real c_b12 = (float)1.;
static real c_b14 = (float).2;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b43 = .05f;
static real c_b44 = .45f;
#else /* NO_PROTO */
static real c_b43 = (float).05;
static real c_b44 = (float).45;
#endif /* NO_PROTO */
static doublereal c_b76 = .25;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b114 = .15f;
#else /* NO_PROTO */
static real c_b114 = (float).15;
#endif /* NO_PROTO */
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.01.02/11                        * */
/*  *    TEST TITLE : Appearance of bundled attributes      * */
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
    static char ldescr[14*4] = "solid         " "dashed        " "dotted    "
	    "    " "dashed-dotted ";
#else /* NO_PROTO */
    static char ldescr[14*4+1] = "solid         dashed        dotted        \
dashed-dotted ";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2], i__3, i__4;
    real r__1, r__2;
    doublereal d__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    double pow_dd(doublereal *, doublereal *), cos(doublereal), sin(
	    doublereal);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat(), s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
    double pow_dd(), cos(), sin();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[9], ya[9], pi;
    static integer ix;
    static real rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer ldx;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer cdim;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer plci, undf[3], perm[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr ();
#endif /* NO_PROTO */
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), nscr (integer *, integer *, 
	    integer *, real *), nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nscr (), nsln ();
#endif /* NO_PROTO */
    static char pfsw[1];
    static real mult;
    static integer szbt, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpf_(char *, integer *, integer *, integer *
	    , ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpf_();
#endif /* NO_PROTO */
    static integer colel;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *), endit_(void), nscmd (integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci (), endit_(), nscmd ();
#endif /* NO_PROTO */
    static integer lncol[20], regdx;
    static char lntid[12];
    static integer numci;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), dynpf_(char *, char *,
	     ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), dynpf_();
#endif /* NO_PROTO */
    static integer impdx;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer stddx, rtans[10];
    static real minlw, maxlw, yincr, nomlw;
    static integer visdx;
    static real centx;
    static integer numlt;
    static real centy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqplf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    );
#else /* NO_PROTO */
    extern /* Subroutine */ int nqplf ();
#endif /* NO_PROTO */
    static integer numlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsplr (integer *, integer *, integer *, real *
	    , integer *), nopst (integer *), nspli (integer *), rnset_(
	    integer *, integer *, integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsplr (), nopst (), nspli (), rnset_(), 
	    nsvwi ();
#endif /* NO_PROTO */
    static real bckcol[6], tstlw1, tstlw2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *), dchpfv_(char *,
	     integer *, integer *, ftnlen), chkinq_(char *, integer *, ftnlen)
	    , setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb (), dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, thislt, lavslt[4], lavrlt[100], lavilt[600]
	    , numdis, szcolt, numpas, viscol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer maxcol, explct;
    static real thislw, forcol[6], newcol[6];
    static char prompt[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), rnperm_(integer *, integer *), numlab_(
	    integer *, real *, real *, real *), setmsg_(char *, char *, 
	    ftnlen, ftnlen), dlstpf_(char *, integer *, integer *, char *, 
	    ftnlen, ftnlen), srtiar_(integer *, integer *), vislab_(char *, 
	    char *, real *, real *, real *, real *, ftnlen, ftnlen), shplbw_(
	    char *, integer *, real *, real *, real *, real *, char *, ftnlen,
	     ftnlen), rnbset_(integer *, integer *, integer *, integer *), 
	    nstxci (integer *), nslwsc (real *), nsplci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nqwksl (), 
	    rnperm_(), numlab_(), setmsg_(), dlstpf_(), srtiar_(), vislab_(), 
	    shplbw_(), rnbset_(), nstxci (), nslwsc (), nsplci ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___39 = { 0, lntid, 0, "(A,I4,A)", 12, 1 };
    static icilist io___40 = { 0, lntid, 0, "(A,I5,A)", 12, 1 };


/* aspect source */
/*                bundled     individual */
/* linetype */
/* colour model */
/* colour available */
/* type of returned value */
    initgl_("04.02.01.02/11", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use bundle attributes */
    setasf_(&c__0);
/*  use <inquire polyline facilities> to determine: */
/*    numlt  = number of available linetypes */
/*    lavslt = list of available standard linetypes */
/*    lavrlt = list of available registered (non-mandatory) linetypes */
/*    lavilt = list of available implementor-defined linetypes */
/*             (may be derived directly from linetype value, if reported 
*/
/*              number of linetypes < 0) */
/*    numlw  = number of available line-widths */
/*    nomlw  = nominal line-width (DC) */
/*    minlw,maxlw = minimum,maximum line-width (DC) */
    nqplf (&dialog_1.specwt, &c__0, &errind, &numlt, &idum1, &numlw, &nomlw, &
	    minlw, &maxlw, &idum2);
    chkinq_("pqplf", &errind, 5L);
/*  szbt = maximum size of bundle table */
    nqwksl (&dialog_1.specwt, &errind, &szbt, &idum1, &idum2, &idum3, &idum4, 
	    &idum5, &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    stddx = 0;
    regdx = 0;
    impdx = 0;
    i__1 = abs(numlt);
    for (ldx = 1; ldx <= i__1; ++ldx) {
	nqplf (&dialog_1.specwt, &ldx, &errind, &idum1, &thislt, &idum2, &
		rdum1, &rdum2, &rdum3, &idum3);
	chkinq_("pqplf", &errind, 5L);
	if (thislt > 4) {
	    ++regdx;
	    lavrlt[regdx - 1] = thislt;
	} else if (thislt > 0) {
	    ++stddx;
	    lavslt[stddx - 1] = thislt;
	} else {
	    if (impdx < 600) {
		if (numlt < 0) {
/*  build list from first LDX negative integers */
		    ++impdx;
		    lavilt[impdx - 1] = -ldx;
		} else {
		    ++impdx;
		    lavilt[impdx - 1] = thislt;
		}
	    }
	}
/* L100: */
    }
/*  *** *** ***   linetype */
/*  mark start of linetypes */
    nlb (&c__1);
/* set polyline bundle representation */
    i__1 = stddx;
    for (ix = 1; ix <= i__1; ++ix) {
	nsplr (&globnu_1.wkid, &ix, &lavslt[ix - 1], &c_b12, &c__1);
/* L150: */
    }
/*  Display in random order bundles 1 thru stddx */
    rnperm_(&stddx, perm);
#ifndef NO_PROTO
    xa[0] = .3f;
    xa[1] = .9f;
    yincr = .8f / stddx;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).3;
    xa[1] = (float).9;
    yincr = (float).8 / stddx;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(&stddx, &c_b14, &yloc, &yincr);
    i__1 = stddx;
    for (ldx = 1; ldx <= i__1; ++ldx) {
	ya[0] = yloc;
	ya[1] = yloc;
	nspli (&lavslt[perm[ldx - 1] - 1]);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L200: */
    }
/*  mark end of linetypes */
    nlb (&c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 35 36", "The mandatory linetypes (1-4) should be recogn"
	    "izable from their standard description.", 13L, 85L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 35 36", "The mandatory linetypes (1-4) should be recogn\
izable from their standard description.", 13L, 85L);
#endif /* NO_PROTO */
/*  Operator must identify each linetype according to official */
/*  English description: solid, dotted, dashed, dotted-dashed. */
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 71, a__1[0] = "MANDATORY LINETYPES: List, in order, the numeri"
	    "c labels for linetypes: ";
#else /* NO_PROTO */
    i__2[0] = 71, a__1[0] = "MANDATORY LINETYPES: List, in order, the numeri\
c labels for linetypes: ";
#endif /* NO_PROTO */
    i__2[1] = 14, a__1[1] = ldescr + (lavslt[0] - 1) * 14;
    s_cat(prompt, a__1, i__2, &c__2, 200L);
    rtans[perm[0] - 1] = 1;
    i__1 = stddx;
    for (ldx = 2; ldx <= i__1; ++ldx) {
	i__3 = itrim_(prompt, 200L);
/* Writing concatenation */
	i__2[0] = 2, a__1[0] = ", ";
	i__2[1] = 14, a__1[1] = ldescr + (lavslt[ldx - 1] - 1) * 14;
	s_cat(prompt + i__3, a__1, i__2, &c__2, 200 - i__3);
	rtans[perm[ldx - 1] - 1] = ldx;
/* L300: */
    }
    i__1 = itrim_(prompt, 200L);
    s_copy(prompt + i__1, ".", 200 - i__1, 1L);
    dlstpf_(prompt, &stddx, rtans, "L", 200L, 1L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  REGDX = size of lavrlt */
    if (regdx < 1) {
	inmsg_("No non-mandatory registered linetypes are supported.", 52L);
	goto L890;
    }
/* select at most 8 linetypes in lavrlt */
/* Computing MIN */
    i__1 = min(regdx,8);
    numdis = min(i__1,szbt);
    rnset_(&numdis, &regdx, perm);
/*  and sort them */
    srtiar_(&numdis, perm);
    srtiar_(&regdx, lavrlt);
/*  set polyline bundle representation */
    i__1 = numdis;
    for (ldx = 1; ldx <= i__1; ++ldx) {
	nsplr (&globnu_1.wkid, &ldx, &lavrlt[perm[ldx - 1] - 1], &c_b12, &
		c__1);
/* L770: */
    }
/*  Display and label bundles with (some) linetypes from LAVRLT */
#ifndef NO_PROTO
    xa[0] = .5f;
    xa[1] = .9f;
    yincr = .8f / numdis;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    xa[1] = (float).9;
    yincr = (float).8 / numdis;
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = numdis;
    for (ldx = 1; ldx <= i__1; ++ldx) {
	ya[0] = yloc;
	ya[1] = yloc;
	thislt = lavrlt[perm[ldx - 1] - 1];
	s_wsfi(&io___39);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&thislt, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc - yincr * .3f;
	r__2 = yloc + yincr * .3f;
#else /* NO_PROTO */
	r__1 = yloc - yincr * (float).3;
	r__2 = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	vislab_(lntid, "R", &c_b43, &c_b44, &r__1, &r__2, 10L, 1L);
	nspli (&ldx);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L800: */
    }
#ifndef NO_PROTO
    setmsg_("3 4 5 6 35 37", "The registered non-mandatory linetypes (> 4) s"
	    "hould agree with their registered description.", 13L, 92L);
    dynpf_("NON-MANDATORY REGISTERED LINETYPES: Is each linetype depicted ac"
	    "cording to its numeric identifier's specification in the ISO reg"
	    "ister?", "Y", 134L, 1L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 35 37", "The registered non-mandatory linetypes (> 4) s\
hould agree with their registered description.", 13L, 92L);
    dynpf_("NON-MANDATORY REGISTERED LINETYPES: Is each linetype depicted ac\
cording to its numeric identifier's specification in the ISO register?", 
	    "Y", 134L, 1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  neg_type: */
L890:
/*  IMPDX = size of lavilt */
    if (impdx < 1) {
	inmsg_("No implementor-defined linetypes are supported.", 47L);
	goto L990;
    }
/* select at most 8 bundles with linetypes from lavilt */
/* Computing MIN */
    i__1 = min(impdx,8);
    numdis = min(i__1,szbt);
    rnset_(&numdis, &impdx, perm);
/* and sort them */
    srtiar_(&numdis, perm);
    srtiar_(&impdx, lavilt);
/* set polyline bundle representation */
    i__1 = numdis;
    for (ldx = 1; ldx <= i__1; ++ldx) {
	nsplr (&globnu_1.wkid, &ldx, &lavilt[perm[ldx - 1] - 1], &c_b12, &
		c__1);
/* L870: */
    }
/*  Display and label bundles with (some) linetypes from LAVILT */
#ifndef NO_PROTO
    xa[0] = .5f;
    xa[1] = .9f;
    yincr = .8f / numdis;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    xa[1] = (float).9;
    yincr = (float).8 / numdis;
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = numdis;
    for (ldx = 1; ldx <= i__1; ++ldx) {
	ya[0] = yloc;
	ya[1] = yloc;
	thislt = lavilt[perm[ldx - 1] - 1];
	s_wsfi(&io___40);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&thislt, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc - yincr * .3f;
	r__2 = yloc + yincr * .3f;
#else /* NO_PROTO */
	r__1 = yloc - yincr * (float).3;
	r__2 = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	vislab_(lntid, "R", &c_b43, &c_b44, &r__1, &r__2, 11L, 1L);
	nspli (&ldx);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L900: */
    }
#ifndef NO_PROTO
    setmsg_("3 4 5 6 35 38", "Implementor-defined linetypes (< 1) should agr"
	    "ee with the descriptions supplied by the implementor.", 13L, 99L);

    dynpf_("IMPLEMENTOR DEFINED LINETYPES: Is each linetype depicted accordi"
	    "ng to its numeric identifier's specification in the implementor "
	    "documentation?", "Y", 142L, 1L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 35 38", "Implementor-defined linetypes (< 1) should agr\
ee with the descriptions supplied by the implementor.", 13L, 99L);
    dynpf_("IMPLEMENTOR DEFINED LINETYPES: Is each linetype depicted accordi\
ng to its numeric identifier's specification in the implementor documentatio\
n?", "Y", 142L, 1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  end_linetype: */
L990:
/*  *** *** ***   2. line-width */
/*  Are there at least two visually distinguishable line-widths? */
#ifndef NO_PROTO
    if (numlw == 1 || maxlw <= minlw * 1.02f || maxlw - minlw < dialog_1.qvis)
	     {
#else /* NO_PROTO */
    if (numlw == 1 || maxlw <= minlw * (float)1.02 || maxlw - minlw < 
	    dialog_1.qvis) {
#endif /* NO_PROTO */
	tstlw1 = maxlw;
	tstlw2 = maxlw;
#ifndef NO_PROTO
	mult = 2.f;
#else /* NO_PROTO */
	mult = (float)2.;
#endif /* NO_PROTO */
    } else {
	tstlw1 = minlw;
	tstlw2 = maxlw;
	if (numlw == 0) {
/*  continuous range of linewidths available - take 4 geometric st
eps */
	    d__1 = (doublereal) (tstlw2 / tstlw1);
#ifndef NO_PROTO
	    mult = pow_dd(&d__1, &c_b76) * .9999f;
#else /* NO_PROTO */
	    mult = pow_dd(&d__1, &c_b76) * (float).9999;
#endif /* NO_PROTO */
	} else {
/*  discrete set of linewidths available - test min/max only */
#ifndef NO_PROTO
	    mult = tstlw2 / tstlw1 * .9999f;
#else /* NO_PROTO */
	    mult = tstlw2 / tstlw1 * (float).9999;
#endif /* NO_PROTO */
	}
    }
/* test scale sizes */
/* set up counter for number of sizes passed */
    numpas = 0;
    thislw = tstlw1;
/*  loop thru various linewidths/next_lw: */
L1000:
/*  invoke SHPLBW subroutine to test requested line width = thislw */
/*                                    expected line width = thislw */
    shplbw_("VARIOUS LINEWIDTH SCALE FACTORS", &globnu_1.wkid, &thislw, &
	    thislw, &nomlw, &minlw, pfsw, 31L, 1L);
    if (*pfsw == 'A') {
	if (numpas < 2) {
#ifndef NO_PROTO
	    inmsg_("Skipping test case for various scale factors because lar"
		    "gest valid line width is greater than screen size.", 106L)
		    ;
#else /* NO_PROTO */
	    inmsg_("Skipping test case for various scale factors because lar\
gest valid line width is greater than screen size.", 106L);
#endif /* NO_PROTO */
	    goto L1110;
	} else {
	    goto L1100;
	}
    } else if (*pfsw != 'P') {
	numpas = 0;
	goto L1100;
    }
/*  if PFSW = 'P', set up for next linewidth to be tested: */
    ++numpas;
    thislw *= mult;
    if (thislw <= tstlw2) {
	goto L1000;
    }
L1100:
#ifndef NO_PROTO
    setmsg_("3 4 5 6 42 43 44", "Available linewidth scale factors should co"
	    "ntrol the realized thickness of a polyline.", 16L, 86L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 42 43 44", "Available linewidth scale factors should co\
ntrol the realized thickness of a polyline.", 16L, 86L);
#endif /* NO_PROTO */
    L__1 = numpas > 0;
    ifpf_(&L__1);
/*  min_max_coerce: */
L1110:
#ifndef NO_PROTO
    setmsg_("3 4 5 6 42 43 45", "A requested positive linewidth scale factor"
	    " below the minimum available should be realized as the minimum.", 
	    16L, 106L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 42 43 45", "A requested positive linewidth scale factor\
 below the minimum available should be realized as the minimum.", 16L, 106L);
#endif /* NO_PROTO */
    r__1 = minlw / 2;
    shplbw_("POSITIVE LINEWIDTH BELOW MINIMUM", &globnu_1.wkid, &r__1, &minlw,
	     &nomlw, &minlw, pfsw, 32L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 42 43 45", "A requested negative linewidth scale factor"
	    " should be realized as the minimum.", 16L, 78L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 42 43 45", "A requested negative linewidth scale factor\
 should be realized as the minimum.", 16L, 78L);
#endif /* NO_PROTO */
    r__1 = -(doublereal)maxlw - 100;
    shplbw_("NEGATIVE LINEWIDTH", &globnu_1.wkid, &r__1, &minlw, &nomlw, &
	    minlw, pfsw, 18L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
/* test line width scale above maximum = maximum */
    r__1 = maxlw * 2;
    shplbw_("POSITIVE LINEWIDTH ABOVE MAXIMUM", &globnu_1.wkid, &r__1, &maxlw,
	     &nomlw, &minlw, pfsw, 32L, 1L);
    if (*pfsw == 'A') {
#ifndef NO_PROTO
	inmsg_("Skipping test case for requested scale factor greater than m"
		"aximum because largest valid line width is greater than scre"
		"en size.", 128L);
#else /* NO_PROTO */
	inmsg_("Skipping test case for requested scale factor greater than m\
aximum because largest valid line width is greater than screen size.", 128L);
#endif /* NO_PROTO */
    } else {
#ifndef NO_PROTO
	setmsg_("3 4 5 6 42 43 45", "A requested linewidth scale factor abov"
		"e the maximum available should be realized as the maximum.", 
		16L, 97L);
#else /* NO_PROTO */
	setmsg_("3 4 5 6 42 43 45", "A requested linewidth scale factor abov\
e the maximum available should be realized as the maximum.", 16L, 97L);
#endif /* NO_PROTO */
	L__1 = *pfsw == 'P';
	ifpf_(&L__1);
    }
/*  *** *** ***   3. polyline color index */
#ifndef NO_PROTO
    setmsg_("3 4 5 6 46 47 48", "A defined polyline color index should cause"
	    " the addressed entry in the color table to be used when renderin"
	    "g a polyline.", 16L, 120L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 46 47 48", "A defined polyline color index should cause\
 the addressed entry in the color table to be used when rendering a polyline."
	    , 16L, 120L);
#endif /* NO_PROTO */
    nscmd (&globnu_1.wkid, &c__1);
/*  bckcol = background color = realized color spec for entry #0 */
/*  forcol = foreground color = realized color spec for entry #1 */
    nqcr (&globnu_1.wkid, &c__0, &c__6, &c__1, &errind, &cdim, bckcol);
    chkinq_("pqcr", &errind, 4L);
    nqcr (&globnu_1.wkid, &c__1, &c__6, &c__1, &errind, &cdim, forcol);
    chkinq_("pqcr", &errind, 4L);
/*  szcolt = maximum size of color table (including entry #0) */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &szcolt, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  how many lines to draw */
/* Computing MIN */
    i__1 = min(szcolt,8);
    numdis = min(i__1,szbt);
/*  from values 2 to SZCOLT-1, pick NUMDIS-2 entries */
    i__1 = numdis - 2;
    i__3 = szcolt - 1;
    rnbset_(&i__1, &c__2, &i__3, lncol);
/*  add in 0 and 1 */
    lncol[numdis - 2] = 1;
    lncol[numdis - 1] = 0;
    rnperm_(&numdis, perm);
/*  from lncol, randomly select entry #visdx, but not the one that */
/*    contains 0, since this may not be re-settable. */
    i__1 = numdis - 1;
    visdx = rndint_(&c__1, &i__1);
    viscol = lncol[visdx - 1];
/*  ensure dialogue visible */
    dialog_1.dtxci = viscol;
    nstxci (&viscol);
#ifndef NO_PROTO
    yloc = .9f;
    yincr = .8f / (numdis - 1);
    xa[0] = .2f;
    xa[1] = .9f;
#else /* NO_PROTO */
    yloc = (float).9;
    yincr = (float).8 / (numdis - 1);
    xa[0] = (float).2;
    xa[1] = (float).9;
#endif /* NO_PROTO */
    numlab_(&numdis, &c_b114, &yloc, &yincr);
/*  for each color entry - set to background color */
/*                       - set bundle representation and draw line */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	plci = lncol[perm[ix - 1] - 1];
	nscr (&globnu_1.wkid, &plci, &cdim, bckcol);
/*  set entry lncol(vis) to forcol */
	nsplr (&globnu_1.wkid, &ix, &c__1, &c_b12, &plci);
	ya[0] = yloc;
	ya[1] = yloc;
	nspli (&ix);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L2100: */
    }
/*  set entry lncol(visdx) to forcol */
    nscr (&globnu_1.wkid, &viscol, &cdim, forcol);
    dchpf_("DEFINED POLYLINE COLOR INDICES: Which line is visible?", &numdis, 
	    &visdx, perm, 54L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 46 47 49", "An undefined polyline color index should ca"
	    "use entry number 1 in the color table to be used when rendering "
	    "a polyline.", 16L, 118L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 46 47 49", "An undefined polyline color index should ca\
use entry number 1 in the color table to be used when rendering a polyline.", 
	    16L, 118L);
#endif /* NO_PROTO */
/*  Try to set entry #1 opposite from BCKCOL */
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
/*  set entry #1 different from FORCOL - make sure other default */
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
    nscr (&globnu_1.wkid, &c__1, &cdim, newcol);
    nqeci (&globnu_1.wkid, &c__0, &errind, &numci, &idum1);
    chkinq_("pqeci", &errind, 5L);
    maxcol = 0;
    i__1 = numci;
    for (ix = 1; ix <= i__1; ++ix) {
	nqeci (&globnu_1.wkid, &ix, &errind, &idum1, &colel);
	chkinq_("pqeci", &errind, 5L);
	maxcol = max(maxcol,colel);
/* L2200: */
    }
/*  undf1,undf2,undf3 = 3 undefined, positive color indices */
    undf[0] = maxcol + 1;
    undf[1] = maxcol + 10;
    undf[2] = maxcol + 90;
/*  explct = number of explicit lines of color #1 = random integer */
/*  from 0 to 4, but don't overflow bundle table */
/* Computing MIN */
    i__3 = 4, i__4 = szbt - 3;
    i__1 = min(i__3,i__4);
    explct = rndint_(&c__0, &i__1);
    numdis = explct + 3;
    rnperm_(&numdis, perm);
/* draw star with individual attributes:linetype=1, width=1, color index=1
*/
/*  set individual attributes */
    setasf_(&c__1);
    nsln (&c__1);
    nslwsc (&c_b12);
    nsplci (&c__1);
#ifndef NO_PROTO
    rad = .15f;
    centx = .5f;
    centy = .75f;
    pi = 3.14159265f;
#else /* NO_PROTO */
    rad = (float).15;
    centx = (float).5;
    centy = (float).75;
    pi = (float)3.14159265;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 6; ++ix) {
	ya[ix - 1] = centy + rad * cos(pi * 4 * ix / 5);
	xa[ix - 1] = centx + rad * sin(pi * 4 * ix / 5);
/* L2400: */
    }
    npl (&c__6, xa, ya);
/*  re-set to bundle attributes */
    setasf_(&c__0);
/*  display interleaved: */
/*    three bundles with color u1,u2,u3, */
/*    explct bundles with color #1 */
#ifndef NO_PROTO
    yloc = .5f;
    yincr = .0625f;
    xa[0] = .1f;
    xa[1] = .9f;
#else /* NO_PROTO */
    yloc = (float).5;
    yincr = (float).0625;
    xa[0] = (float).1;
    xa[1] = (float).9;
#endif /* NO_PROTO */
/*  for each color entry - set to background color and draw line */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	colel = perm[ix - 1];
	if (colel <= 3) {
	    nsplr (&globnu_1.wkid, &ix, &c__1, &c_b12, &undf[colel - 1]);
	} else {
	    nsplr (&globnu_1.wkid, &ix, &c__1, &c_b12, &c__1);
	}
	ya[0] = yloc;
	ya[1] = yloc;
	nspli (&ix);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L2300: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED POLYLINE COLOR INDICES: How many of the horizontal li"
	    "nes are the same color as the star?", &c__12, &numdis, 98L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED POLYLINE COLOR INDICES: How many of the horizontal li\
nes are the same color as the star?", &c__12, &numdis, 98L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

