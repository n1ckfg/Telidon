/* fort/04/02/02/02/p11.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b13 = .1f;
#else /* NO_PROTO */
static real c_b13 = (float).1;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b41 = .05f;
static real c_b42 = .45f;
#else /* NO_PROTO */
static real c_b41 = (float).05;
static real c_b42 = (float).45;
#endif /* NO_PROTO */
static doublereal c_b73 = .25;
static integer c__3 = 3;
static integer c__7 = 7;
#ifndef NO_PROTO
static real c_b106 = 1.f;
#else /* NO_PROTO */
static real c_b106 = (float)1.;
#endif /* NO_PROTO */
static integer c__12 = 12;
static integer c__6 = 6;
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.02/11                        * */
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
    static char mdescr[14*5] = "dot           " "plus          " "asterisk  "
	    "    " "circle        " "cross         ";
#else /* NO_PROTO */
    static char mdescr[14*5+1] = "dot           plus          asterisk      \
circle        cross         ";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2], i__3;
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
    extern /* Subroutine */ int nlb (integer *), npl (integer *, real *, real 
	    *), npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), npl (), npm ();
#endif /* NO_PROTO */
    static integer cdim;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer pmci;
    static real mscf;
    static integer undf[3], perm[10];
    static real xloc;
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), nsmk (integer *), nsln (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nsmk (), nsln ();
#endif /* NO_PROTO */
    static char pfsw[1];
    static real mult;
    static integer szbt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
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
	    integer *, integer *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci (), endit_();
#endif /* NO_PROTO */
    static integer mkcol[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
#endif /* NO_PROTO */
    static char mktid[12];
    static integer regdx, numci;
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
    static real yincr;
    static integer stddx, rtans[10];
    static real minmw, maxmw, xincr, lmssf[7];
    static integer visdx;
    static real nommw, centx;
    static integer nummt;
    static real centy;
    static integer nummw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nqpmf (integer *, integer *
	    , integer *, integer *, integer *, integer *, real *, real *, 
	    real *, integer *), nspmr (integer *, integer *, integer *, real *
	    , integer *), nsvwi (integer *), nspmi (integer *), rnset_(
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nqpmf (), nspmr (), nsvwi (), 
	    nspmi (), rnset_();
#endif /* NO_PROTO */
    static real bckcol[6], tstmw1, tstmw2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *), dchpfv_(char *,
	     integer *, integer *, ftnlen), chkinq_(char *, integer *, ftnlen)
	    , setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb (), dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, thismt, lavsmt[5], lavrmt[100], lavimt[600]
	    , numdis, szcolt, numpas, viscol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer maxcol, explct, nummar;
    static real thismw, forcol[6], newcol[6];
    static char prompt[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), rnperm_(integer *, integer *), numlab_(
	    integer *, real *, real *, real *), setmsg_(char *, char *, 
	    ftnlen, ftnlen), dlstpf_(char *, integer *, integer *, char *, 
	    ftnlen, ftnlen), srtiar_(integer *, integer *), vislab_(char *, 
	    char *, real *, real *, real *, real *, ftnlen, ftnlen), shpmbw_(
	    char *, integer *, real *, real *, real *, char *, ftnlen, ftnlen)
	    , nsmksc (real *), nslwsc (real *), nsplci (integer *), rnbset_(
	    integer *, integer *, integer *, integer *), nstxci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nqwksl (), 
	    rnperm_(), numlab_(), setmsg_(), dlstpf_(), srtiar_(), vislab_(), 
	    shpmbw_(), nsmksc (), nslwsc (), nsplci (), rnbset_(), nstxci ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___39 = { 0, mktid, 0, "(A,I2,A)", 12, 1 };
    static icilist io___40 = { 0, mktid, 0, "(A,I5,A)", 12, 1 };


/* aspect source */
/*                bundled     individual */
/* marker type */
/* colour model */
/* colour available */
/* type of returned value */
    initgl_("04.02.02.02/11", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  set ASFs to BUNDLE */
    setasf_(&c__0);
/*  use <inquire polymarker facilities> to determine: */
/*    nummt  = number of marker types */
/*    lavsmt = list of available standard marker types */
/*    lavrmt = list of available registered (non-mandatory) marker types 
*/
/*    lavimt = list of available implementor-defined marker types */
/*            (may be derived directly from marker type value, if reported
*/
/*              number of marker types < 0) */
/*    nummw  = number of available marker-sizes */
/*    nommw  = nominal marker-size (DC) */
/*    minmw,maxmw = minimum,maximum marker-size (DC) */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &nummt, &idum1, &nummw, &nommw, &
	    minmw, &maxmw, &idum2);
    chkinq_("pqpmf", &errind, 5L);
/*  szbt = maximum size of bundle table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &szbt, &idum2, &idum3, &idum4, 
	    &idum5, &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    stddx = 0;
    regdx = 0;
    impdx = 0;
    i__1 = abs(nummt);
    for (ix = 1; ix <= i__1; ++ix) {
	nqpmf (&dialog_1.specwt, &ix, &errind, &idum1, &thismt, &idum2, &
		rdum1, &rdum2, &rdum3, &idum3);
	chkinq_("pqpmf", &errind, 5L);
	if (thismt > 5) {
	    ++regdx;
	    lavrmt[regdx - 1] = thismt;
	} else if (thismt > 0) {
	    ++stddx;
	    lavsmt[stddx - 1] = thismt;
	} else {
	    if (impdx < 600) {
		if (nummt < 0) {
/*  build list from first IX negative integers */
		    ++impdx;
		    lavimt[impdx - 1] = -ix;
		} else {
		    ++impdx;
		    lavimt[impdx - 1] = thismt;
		}
	    }
	}
/* L100: */
    }
/*  *** *** ***   marker type */
/*  mark start of marker types */
    nlb (&c__1);
#ifndef NO_PROTO
    mscf = .05f / (dialog_1.wcpdc * nommw);
#else /* NO_PROTO */
    mscf = (float).05 / (dialog_1.wcpdc * nommw);
#endif /* NO_PROTO */
/* set polymarker bundle representation */
    i__1 = stddx;
    for (ix = 1; ix <= i__1; ++ix) {
	nspmr (&globnu_1.wkid, &ix, &lavsmt[ix - 1], &mscf, &c__1);
/* L150: */
    }
/*  Display in random order bundles 1 thru stddx */
    rnperm_(&stddx, perm);
#ifndef NO_PROTO
    xa[0] = .3f;
    yincr = .8f / stddx;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).3;
    yincr = (float).8 / stddx;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(&stddx, &c_b13, &yloc, &yincr);
    i__1 = stddx;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	nspmi (&lavsmt[perm[ix - 1] - 1]);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L200: */
    }
/*  mark end of marker types */
    nlb (&c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 35 36", "The mandatory marker types (1-5) should be rec"
	    "ognizable from their standard description.", 13L, 88L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 35 36", "The mandatory marker types (1-5) should be rec\
ognizable from their standard description.", 13L, 88L);
#endif /* NO_PROTO */
/*  Operator must identify each marker type according to official */
/*  English description: 1-dot, 2-plus sign, 3-asterisk, 4-circle, */
/*                       5-diagonal cross */
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 73, a__1[0] = "MANDATORY MARKER TYPES: List, in order, numeric"
	    " labels for marker types: ";
#else /* NO_PROTO */
    i__2[0] = 73, a__1[0] = "MANDATORY MARKER TYPES: List, in order, numeric\
 labels for marker types: ";
#endif /* NO_PROTO */
    i__2[1] = 14, a__1[1] = mdescr + (lavsmt[0] - 1) * 14;
    s_cat(prompt, a__1, i__2, &c__2, 200L);
    rtans[perm[0] - 1] = 1;
    i__1 = stddx;
    for (ix = 2; ix <= i__1; ++ix) {
	i__3 = itrim_(prompt, 200L);
/* Writing concatenation */
	i__2[0] = 2, a__1[0] = ", ";
	i__2[1] = 14, a__1[1] = mdescr + (lavsmt[ix - 1] - 1) * 14;
	s_cat(prompt + i__3, a__1, i__2, &c__2, 200 - i__3);
	rtans[perm[ix - 1] - 1] = ix;
/* L300: */
    }
    i__1 = itrim_(prompt, 200L);
    s_copy(prompt + i__1, ".", 200 - i__1, 1L);
    dlstpf_(prompt, &stddx, rtans, "L", 200L, 1L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  REGDX = size of lavrmt */
    if (regdx < 1) {
	inmsg_("No non-mandatory registered marker types are supported.", 55L)
		;
	goto L890;
    }
/* select at most 8 bundles with marker types from lavrmt */
/* Computing MIN */
    i__1 = min(8,regdx);
    numdis = min(i__1,szbt);
    rnset_(&numdis, &regdx, perm);
/*  and sort them */
    srtiar_(&numdis, perm);
    srtiar_(&regdx, lavrmt);
/*  set polymarker bundle representation */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	nspmr (&globnu_1.wkid, &ix, &lavrmt[perm[ix - 1] - 1], &mscf, &c__1);
/* L770: */
    }
/*  Display and label bundles with (some) marker types from LAVRMT */
#ifndef NO_PROTO
    xa[0] = .5f;
    yincr = .8f / numdis;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    yincr = (float).8 / numdis;
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	thismt = lavrmt[perm[ix - 1] - 1];
	s_wsfi(&io___39);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&thismt, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc - yincr * .3f;
	r__2 = yloc + yincr * .3f;
#else /* NO_PROTO */
	r__1 = yloc - yincr * (float).3;
	r__2 = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	vislab_(mktid, "R", &c_b41, &c_b42, &r__1, &r__2, 8L, 1L);
	nspmi (&ix);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L800: */
    }
#ifndef NO_PROTO
    setmsg_("3 4 5 6 35 37", "The registered non-mandatory marker types (> 5"
	    ") should agree with their registered description.", 13L, 95L);
    dynpf_("NON-MANDATORY REGISTERED MARKER TYPES: Is each marker type depic"
	    "ted according to its numeric identifier's specification in the I"
	    "SO register?", "Y", 140L, 1L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 35 37", "The registered non-mandatory marker types (> 5\
) should agree with their registered description.", 13L, 95L);
    dynpf_("NON-MANDATORY REGISTERED MARKER TYPES: Is each marker type depic\
ted according to its numeric identifier's specification in the ISO register?",
	     "Y", 140L, 1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  neg_type: */
L890:
/*  IMPDX = size of lavimt */
    if (impdx < 1) {
	inmsg_("No implementor-defined marker types are supported.", 50L);
	goto L990;
    }
/* select at most 8 bundles with marker types from lavimt */
/* Computing MIN */
    i__1 = min(8,impdx);
    numdis = min(i__1,szbt);
    rnset_(&numdis, &impdx, perm);
/* and sort them */
    srtiar_(&numdis, perm);
    srtiar_(&impdx, lavimt);
/* set polymarker bundle representation */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	nspmr (&globnu_1.wkid, &ix, &lavimt[perm[ix - 1] - 1], &mscf, &c__1);
/* L870: */
    }
/*  Display and label bundles with (some) marker types from LAVIMT */
#ifndef NO_PROTO
    xa[0] = .5f;
    yincr = .8f / numdis;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    yincr = (float).8 / numdis;
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	thismt = lavimt[perm[ix - 1] - 1];
	s_wsfi(&io___40);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&thismt, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc - yincr * .3f;
	r__2 = yloc + yincr * .3f;
#else /* NO_PROTO */
	r__1 = yloc - yincr * (float).3;
	r__2 = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	vislab_(mktid, "R", &c_b41, &c_b42, &r__1, &r__2, 11L, 1L);
	nspmi (&ix);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L900: */
    }
#ifndef NO_PROTO
    setmsg_("3 4 5 6 35 38", "Implementor-defined marker types (< 1) should "
	    "agree with the descriptions supplied by the implementor.", 13L, 
	    102L);
    dynpf_("IMPLEMENTOR DEFINED MARKER TYPES: Is each marker type depicted a"
	    "ccording to its numeric identifier's specification in the implem"
	    "entor documentation?", "Y", 148L, 1L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 35 38", "Implementor-defined marker types (< 1) should \
agree with the descriptions supplied by the implementor.", 13L, 102L);
    dynpf_("IMPLEMENTOR DEFINED MARKER TYPES: Is each marker type depicted a\
ccording to its numeric identifier's specification in the implementor docume\
ntation?", "Y", 148L, 1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* end_markertype: */
L990:
/*  *** *** ***   marker size */
/*  Are there at least two visually distinguishable marker sizes? */
#ifndef NO_PROTO
    if (nummw == 1 || maxmw <= minmw * 1.02f || maxmw - minmw < dialog_1.qvis)
	     {
#else /* NO_PROTO */
    if (nummw == 1 || maxmw <= minmw * (float)1.02 || maxmw - minmw < 
	    dialog_1.qvis) {
#endif /* NO_PROTO */
	tstmw1 = maxmw;
	tstmw2 = maxmw;
#ifndef NO_PROTO
	mult = 2.f;
#else /* NO_PROTO */
	mult = (float)2.;
#endif /* NO_PROTO */
    } else {
	tstmw1 = minmw;
	tstmw2 = maxmw;
	if (nummw == 0) {
/*  continuous range of marker sizes available - take 4 geometric 
steps */
	    d__1 = (doublereal) (tstmw2 / tstmw1);
#ifndef NO_PROTO
	    mult = pow_dd(&d__1, &c_b73) * .9999f;
#else /* NO_PROTO */
	    mult = pow_dd(&d__1, &c_b73) * (float).9999;
#endif /* NO_PROTO */
	} else {
/*  discrete set of marker sizes available - test min/max only */
#ifndef NO_PROTO
	    mult = tstmw2 / tstmw1 * .9999f;
#else /* NO_PROTO */
	    mult = tstmw2 / tstmw1 * (float).9999;
#endif /* NO_PROTO */
	}
    }
/* test scale sizes */
/* set up counter; numpas = number of tests passed so far */
    numpas = 0;
    thismw = tstmw1;
/*  loop thru various marker sizes/next_Mw: */
L1000:
/*  invoke SHPMBW subroutine to test bundle with */
/*     requested marker size = thismw */
/*     expected marker size = thismw */
    shpmbw_("VARIOUS MARKER SIZE SCALE FACTORS", &globnu_1.wkid, &thismw, &
	    thismw, &nommw, pfsw, 33L, 1L);
    if (*pfsw == 'A') {
	if (numpas < 2) {
#ifndef NO_PROTO
	    inmsg_("Skipping test case for various scale factors because lar"
		    "gest valid marker size is greater than screen size.", 
		    107L);
#else /* NO_PROTO */
	    inmsg_("Skipping test case for various scale factors because lar\
gest valid marker size is greater than screen size.", 107L);
#endif /* NO_PROTO */
	    goto L1110;
	} else {
	    goto L1100;
	}
    } else if (*pfsw != 'P') {
	numpas = 0;
	goto L1100;
    }
/*  if PFSW = 'P', set up for next marker size to be tested: */
    ++numpas;
    thismw *= mult;
    if (thismw <= tstmw2) {
	goto L1000;
    }
L1100:
#ifndef NO_PROTO
    setmsg_("3 4 5 6 42 43 44", "Available marker size scale factors should "
	    "control the realized size of a polymarker.", 16L, 85L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 42 43 44", "Available marker size scale factors should \
control the realized size of a polymarker.", 16L, 85L);
#endif /* NO_PROTO */
    L__1 = numpas > 0;
    ifpf_(&L__1);
/*  min_max_coerce: */
L1110:
#ifndef NO_PROTO
    setmsg_("3 4 5 6 42 43 45", "A requested positive marker size scale fact"
	    "or below the minimum available should be realized as the minimum."
	    , 16L, 108L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 42 43 45", "A requested positive marker size scale fact\
or below the minimum available should be realized as the minimum.", 16L, 108L)
	    ;
#endif /* NO_PROTO */
    r__1 = minmw / 2;
    shpmbw_("POSITIVE MARKER SIZE BELOW MINIMUM", &globnu_1.wkid, &r__1, &
	    minmw, &nommw, pfsw, 34L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 42 43 45", "A requested negative marker size scale fact"
	    "or should be realized as the minimum.", 16L, 80L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 42 43 45", "A requested negative marker size scale fact\
or should be realized as the minimum.", 16L, 80L);
#endif /* NO_PROTO */
    r__1 = -(doublereal)maxmw - 100;
    shpmbw_("NEGATIVE MARKER SIZE", &globnu_1.wkid, &r__1, &minmw, &nommw, 
	    pfsw, 20L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
/* test marker size scale above maximum = maximum */
    r__1 = maxmw * 2;
    shpmbw_("POSITIVE MARKER SIZE ABOVE MAXIMUM", &globnu_1.wkid, &r__1, &
	    maxmw, &nommw, pfsw, 34L, 1L);
    if (*pfsw == 'A') {
#ifndef NO_PROTO
	inmsg_("Skipping test case for requested scale factor greater than m"
		"aximum because largest valid marker size is greater than scr"
		"een size.", 129L);
#else /* NO_PROTO */
	inmsg_("Skipping test case for requested scale factor greater than m\
aximum because largest valid marker size is greater than screen size.", 129L);

#endif /* NO_PROTO */
    } else {
#ifndef NO_PROTO
	setmsg_("3 4 5 6 42 43 45", "A requested marker size scale factor ab"
		"ove the maximum available should be realized as the maximum.",
		 16L, 99L);
#else /* NO_PROTO */
	setmsg_("3 4 5 6 42 43 45", "A requested marker size scale factor ab\
ove the maximum available should be realized as the maximum.", 16L, 99L);
#endif /* NO_PROTO */
	L__1 = *pfsw == 'P';
	ifpf_(&L__1);
    }
/*  *** *** ***   Marker type 1   *** *** *** *** */
/* lmssf =  list of marker sizes, contains: */
    lmssf[0] = minmw / 2;
    lmssf[1] = maxmw * 2;
#ifndef NO_PROTO
    lmssf[2] = -2.76f;
#else /* NO_PROTO */
    lmssf[2] = (float)-2.76;
#endif /* NO_PROTO */
    lmssf[3] = (minmw + maxmw) / 2;
    lmssf[4] = minmw;
    lmssf[5] = maxmw;
    lmssf[6] = nommw;
/* set up bundles 1-7 */
    for (ix = 1; ix <= 7; ++ix) {
	r__1 = lmssf[ix - 1] / nommw;
	nspmr (&globnu_1.wkid, &ix, &c__1, &r__1, &c__1);
/* L1150: */
    }
/* nummar = number of markers to be drawn = random integer between 3-7 */
    nummar = rndint_(&c__3, &c__7);
#ifndef NO_PROTO
    xincr = .1f;
#else /* NO_PROTO */
    xincr = (float).1;
#endif /* NO_PROTO */
    xloc = xincr;
    xa[0] = xloc;
#ifndef NO_PROTO
    ya[0] = .5f;
    setmsg_("3 4 5 6 42 43 46", "Marker type 1 should be rendered as the sma"
	    "llest displayable dot, regardless of the marker size scale facto"
	    "r value.", 16L, 115L);
#else /* NO_PROTO */
    ya[0] = (float).5;
    setmsg_("3 4 5 6 42 43 46", "Marker type 1 should be rendered as the sma\
llest displayable dot, regardless of the marker size scale factor value.", 
	    16L, 115L);
#endif /* NO_PROTO */
/* draw reference marker and polyline separator */
/*  set ASFs to INDIVIDUAL */
    setasf_(&c__1);
    nsmk (&c__1);
    nsmksc (&c_b106);
    npm (&c__1, xa, ya);
/* attributes for POLYLINE */
    nsln (&c__1);
    nslwsc (&c_b106);
    nsplci (&c__1);
    xloc = xincr + xloc;
    xa[0] = xloc;
    xa[1] = xa[0];
#ifndef NO_PROTO
    ya[0] = .45f;
    ya[1] = .55f;
#else /* NO_PROTO */
    ya[0] = (float).45;
    ya[1] = (float).55;
#endif /* NO_PROTO */
    npl (&c__2, xa, ya);
/*  set ASFs to BUNDLE */
    setasf_(&c__0);
/* draw markers with varying sizes */
#ifndef NO_PROTO
    ya[0] = .5f;
#else /* NO_PROTO */
    ya[0] = (float).5;
#endif /* NO_PROTO */
    i__1 = nummar;
    for (ix = 1; ix <= i__1; ++ix) {
	xloc += xincr;
	xa[0] = xloc;
	nspmi (&ix);
	npm (&c__1, xa, ya);
/* L1200: */
    }
#ifndef NO_PROTO
    dchpfv_("MARKER SIZE OF MARKER TYPE 1: How many dots to the right of the"
	    " vertical line are the same size as the dot to the left of the l"
	    "ine?", &c__12, &nummar, 131L);
#else /* NO_PROTO */
    dchpfv_("MARKER SIZE OF MARKER TYPE 1: How many dots to the right of the\
 vertical line are the same size as the dot to the left of the line?", &c__12,
	     &nummar, 131L);
#endif /* NO_PROTO */
/* L1350: */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  *** *** ***  polymarker color index */
#ifndef NO_PROTO
    setmsg_("3 4 5 6 47 48 49", "A defined polymarker color index should cau"
	    "se the addressed entry in the color table to be used when render"
	    "ing a polymarker.", 16L, 124L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 47 48 49", "A defined polymarker color index should cau\
se the addressed entry in the color table to be used when rendering a polyma\
rker.", 16L, 124L);
#endif /* NO_PROTO */
    nscmd (&globnu_1.wkid, &c__1);
/*  bckcol = background color = realized color spec for entry #0 */
/*  forcol = foreground color = realized color spec for entry #1 */
    nqcr (&globnu_1.wkid, &c__0, &c__6, &c__1, &errind, &cdim, bckcol);
    chkinq_("pqcr", &errind, 4L);
    nqcr (&globnu_1.wkid, &c__1, &c__6, &c__1, &errind, &cdim, forcol);
    chkinq_("pqcr", &errind, 4L);
/*  szcomt = maximum size of color table (including entry #0) */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &szcolt, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  how many markers to draw */
/* Computing MIN */
    i__1 = min(8,szcolt);
    numdis = min(i__1,szbt);
/*  from values 2 to SZCOLT-1, pick NUMDIS-2 entries */
    i__1 = numdis - 2;
    i__3 = szcolt - 1;
    rnbset_(&i__1, &c__2, &i__3, mkcol);
/*  add in 0 and 1 */
    mkcol[numdis - 2] = 1;
    mkcol[numdis - 1] = 0;
    rnperm_(&numdis, perm);
/*  from mkcol, randomly select entry #visdx, but not the one that */
/*  contains 0, since this may not be re-settable. */
    i__1 = numdis - 1;
    visdx = rndint_(&c__1, &i__1);
    viscol = mkcol[visdx - 1];
/*  ensure dialogue visible */
    dialog_1.dtxci = viscol;
    nstxci (&viscol);
#ifndef NO_PROTO
    yloc = .9f;
    yincr = .8f / (numdis - 1);
    xa[0] = .2f;
#else /* NO_PROTO */
    yloc = (float).9;
    yincr = (float).8 / (numdis - 1);
    xa[0] = (float).2;
#endif /* NO_PROTO */
    numlab_(&numdis, &c_b13, &yloc, &yincr);
/*  for each color entry - set to background color */
/*                       - set bundle representation and draw marker */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	pmci = mkcol[perm[ix - 1] - 1];
	nscr (&globnu_1.wkid, &pmci, &cdim, bckcol);
/* set entry mkcol(vis) to forcol */
	nspmr (&globnu_1.wkid, &ix, &c__3, &mscf, &pmci);
	ya[0] = yloc;
	nspmi (&ix);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L2100: */
    }
/*  set entry mkcol(vis) to forcol */
    nscr (&globnu_1.wkid, &viscol, &cdim, forcol);
    dchpf_("DEFINED POLYMARKER COLOR INDICES: Which marker is visible?", &
	    numdis, &visdx, perm, 58L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 47 48 50", "An undefined polymarker color index should "
	    "cause entry number 1 in the color table to be used when renderin"
	    "g a polymarker.", 16L, 122L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 47 48 50", "An undefined polymarker color index should \
cause entry number 1 in the color table to be used when rendering a polymark\
er.", 16L, 122L);
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
/*  explct = number of explicit markers of color #1 = random integer */
/*  from 0 to 4 */
    explct = rndint_(&c__0, &c__4);
    numdis = explct + 3;
    rnperm_(&numdis, perm);
/*  draw star with individual attributes:linetype=1,width=1,col index=1 */

/*  set ASFS to INDIVIDUAL */
    setasf_(&c__1);
    nsln (&c__1);
    nslwsc (&c_b106);
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
/*  re-set ASFS to BUNDLE */
    setasf_(&c__0);
/*  display interleaved: */
/*    three bundles with color u1,u2,u3, */
/*    explct bundles with color #1 */
#ifndef NO_PROTO
    xincr = .1f;
#else /* NO_PROTO */
    xincr = (float).1;
#endif /* NO_PROTO */
    xloc = xincr;
#ifndef NO_PROTO
    ya[0] = .5f;
#else /* NO_PROTO */
    ya[0] = (float).5;
#endif /* NO_PROTO */
/*  for each color entry - set to background color and draw line */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	colel = perm[ix - 1];
	if (colel <= 3) {
	    nspmr (&globnu_1.wkid, &ix, &c__3, &mscf, &undf[colel - 1]);
	} else {
	    nspmr (&globnu_1.wkid, &ix, &c__3, &mscf, &c__1);
	}
	xa[0] = xloc;
	nspmi (&ix);
	npm (&c__1, xa, ya);
	xloc += xincr;
/* L2300: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED POLYMARKER COLOR INDICES: How many markers are the sa"
	    "me color as the star?", &c__12, &numdis, 84L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED POLYMARKER COLOR INDICES: How many markers are the sa\
me color as the star?", &c__12, &numdis, 84L);
#endif /* NO_PROTO */
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

