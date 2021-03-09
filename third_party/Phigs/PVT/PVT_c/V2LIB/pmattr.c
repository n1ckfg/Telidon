/* pmattr.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__801 = 801;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__8 = 8;
#ifndef NO_PROTO
static real c_b17 = .1f;
static real c_b69 = .05f;
static real c_b70 = .4f;
#else /* NO_PROTO */
static real c_b17 = (float).1;
static real c_b69 = (float).05;
static real c_b70 = (float).4;
#endif /* NO_PROTO */
static doublereal c_b119 = .25;
static integer c__4 = 4;
static integer c__3 = 3;
static integer c__7 = 7;
#ifndef NO_PROTO
static real c_b171 = 1.f;
#else /* NO_PROTO */
static real c_b171 = (float)1.;
#endif /* NO_PROTO */
static integer c__12 = 12;
static integer c__6 = 6;

#ifndef NO_PROTO
/* Subroutine */ int pmattr_(char *tstype, ftnlen tstype_len)
#else /* NO_PROTO */
/* Subroutine */ int pmattr_(tstype, tstype_len)
char *tstype;
ftnlen tstype_len;
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
    integer i__1[2], i__2, i__3;
    real r__1, r__2;
    doublereal d__1;
    logical L__1;
    char ch__1[29], ch__2[157], ch__3[138], ch__4[164], ch__5[171], ch__6[
	    2731], ch__7[154], ch__8[177], ch__9[149], ch__10[168], ch__11[
	    193], ch__12[191];

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
    static char msg[2600];
    static integer mdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), npm (integer 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), npm ();
#endif /* NO_PROTO */
    static integer cdim;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer pmci, undf[3], perm[10];
    static real xloc;
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndmw_(real *, real *), nsmk (integer *), 
	    nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndmw_(), nsmk (), nsep ();
#endif /* NO_PROTO */
    static char pfsw[1];
    static real mult;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *), nqcr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *), nscr (
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln (), nqcr (), nscr ();
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
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci ();
#endif /* NO_PROTO */
    static integer mkcol[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
#endif /* NO_PROTO */
    static char mktid[12];
    static integer regdx, pmcol, numci;
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
    static real minmw, maxmw, xincr;
    static integer visdx;
    static real nommw, centx;
    static integer nummt;
    static real centy;
    static integer nummw;
    static real lmssf[7];
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), nopst (integer *), 
	    nsvwi (integer *), nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), rnset_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), nopst (), nsvwi (), nqpmf (), 
	    rnset_();
#endif /* NO_PROTO */
    static real bckcol[6], tstmw1, tstmw2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *), dchpfv_(char *,
	     integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb (), dchpfv_();
#endif /* NO_PROTO */
    static integer mardis[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, thismt, lavsmt[5], lavrmt[100], lavimt[600]
	    , minimt, maximt, unsudx, lunsup[10], numdis, szcomt, nummar, 
	    numpas, viscol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer maxcol, explct, ndisct, ndmkst;
#ifndef NO_PROTO
    extern integer ranmkt_(integer *, integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern integer ranmkt_();
#endif /* NO_PROTO */
    static real thismw, forcol[6], newcol[6];
    static char prompt[200], suffix[70];
    static logical nozero;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setasf_(
	    integer *), chkinq_(char *, integer *, ftnlen), discol_(integer *,
	     integer *, integer *), rnperm_(integer *, integer *), nsmksc (
	    real *), numlab_(integer *, real *, real *, real *), nspmci (
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen), dlstpf_(char 
	    *, integer *, integer *, char *, ftnlen, ftnlen), srtiar_(integer 
	    *, integer *), vislab_(char *, char *, real *, real *, real *, 
	    real *, ftnlen, ftnlen), showmw_(char *, integer *, integer *, 
	    real *, real *, real *, char *, ftnlen, ftnlen), nqwksl (integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, integer *), rnbset_(integer *, integer *, 
	    integer *, integer *), nstxci (integer *), nsplci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setasf_(), chkinq_(), discol_(), 
	    rnperm_(), nsmksc (), numlab_(), nspmci (), setmsg_(), dlstpf_(), 
	    srtiar_(), vislab_(), showmw_(), nqwksl (), rnbset_(), nstxci (), 
	    nsplci ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___41 = { 0, mktid, 0, "(A,I2,A)", 12, 1 };
    static icilist io___42 = { 0, mktid, 0, "(A,I5,A)", 12, 1 };
    static icilist io___44 = { 0, msg, 0, "(500I5)", 2600, 1 };


/*  PMATTR tests polymarker attributes, either individually, using the */
/*  default values for the other attributes, or in combination, using */
/*  non-default values for the others. */
/*  Input parameter: */
/*    TSTYPE : 'i' for individual, 'c' for combination */
/* aspect source */
/*                bundled     individual */
/* polyline type */
/* marker type */
/* type of returned value */
/* colour model */
    if (*tstype == 'i' || *tstype == 'c') {
/*        tstype valid */
    } else {
/* Writing concatenation */
	i__1[0] = 28, a__1[0] = "PMATTR called with TSTYPE = ";
	i__1[1] = 1, a__1[1] = tstype;
	s_cat(ch__1, a__1, i__1, &c__2, 29L);
	unmsg_(ch__1, 29L);
    }
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
    stddx = 0;
    regdx = 0;
    impdx = 0;
    i__2 = abs(nummt);
    for (mdx = 1; mdx <= i__2; ++mdx) {
	nqpmf (&dialog_1.specwt, &mdx, &errind, &idum1, &thismt, &idum2, &
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
/*  build list from first MDX negative integers */
		    ++impdx;
		    lavimt[impdx - 1] = -mdx;
		} else {
		    ++impdx;
		    lavimt[impdx - 1] = thismt;
		}
	    }
	}
/* L100: */
    }
    if (*tstype == 'c') {
/*  NDISCT = number of distinct foreground colors set in color table. 
*/
	discol_(&c__8, &globnu_1.wkid, &ndisct);
    }
/*  *** *** ***   1. marker type */
/*  mark start of marker types */
    nlb (&c__1);
/*  Display in random order all marker types in lavsmt */
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
    if (*tstype == 'c') {
	r__1 = yincr / 2;
	ndmw_(&r__1, &nommw);
    } else {
	r__1 = yincr / 2 / (nommw * dialog_1.wcpdc);
	nsmksc (&r__1);
    }
    numlab_(&stddx, &c_b17, &yloc, &yincr);
    i__2 = stddx;
    for (mdx = 1; mdx <= i__2; ++mdx) {
	ya[0] = yloc;
	if (*tstype == 'c') {
	    i__3 = rndint_(&c__1, &ndisct);
	    nspmci (&i__3);
	}
	nsmk (&lavsmt[perm[mdx - 1] - 1]);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L200: */
    }
/*  mark end of marker types */
    nlb (&c__2);
    if (*tstype == 'c') {
#ifndef NO_PROTO
	s_copy(suffix, ", even when a non-default marker size or color is us"
		"ed.", 70L, 55L);
#else /* NO_PROTO */
	s_copy(suffix, ", even when a non-default marker size or color is us\
ed.", 70L, 55L);
#endif /* NO_PROTO */
    } else {
	s_copy(suffix, ".", 70L, 1L);
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 87, a__1[0] = "The mandatory marker types (1-5) should be reco"
	    "gnizable from their standard description";
#else /* NO_PROTO */
    i__1[0] = 87, a__1[0] = "The mandatory marker types (1-5) should be reco\
gnizable from their standard description";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__2, a__1, i__1, &c__2, 157L);
    setmsg_("3 4 5 6 8", ch__2, 9L, 157L);
/*  Operator must identify each marker type according to official */
/*  English description: 1-dot, 2-plus sign, 3-asterisk, 4-circle, */
/*                       5-diagonal cross */
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 73, a__1[0] = "MANDATORY MARKER TYPES: List, in order, numeric"
	    " labels for marker types: ";
#else /* NO_PROTO */
    i__1[0] = 73, a__1[0] = "MANDATORY MARKER TYPES: List, in order, numeric\
 labels for marker types: ";
#endif /* NO_PROTO */
    i__1[1] = 14, a__1[1] = mdescr + (lavsmt[0] - 1) * 14;
    s_cat(prompt, a__1, i__1, &c__2, 200L);
    rtans[perm[0] - 1] = 1;
    i__2 = stddx;
    for (mdx = 2; mdx <= i__2; ++mdx) {
	i__3 = itrim_(prompt, 200L);
/* Writing concatenation */
	i__1[0] = 2, a__1[0] = ", ";
	i__1[1] = 14, a__1[1] = mdescr + (lavsmt[mdx - 1] - 1) * 14;
	s_cat(prompt + i__3, a__1, i__1, &c__2, 200 - i__3);
	rtans[perm[mdx - 1] - 1] = mdx;
/* L300: */
    }
    i__2 = itrim_(prompt, 200L);
    s_copy(prompt + i__2, ".", 200 - i__2, 1L);
    dlstpf_(prompt, &stddx, rtans, "L", 200L, 1L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* look for unsupported negative marker type */
    if (nummt > 0) {
/*  find negative marker type *not* in LAVIMT and whether zero */
/*  is supported. */
	nozero = TRUE_;
	minimt = 0;
	i__2 = impdx;
	for (mdx = 1; mdx <= i__2; ++mdx) {
	    if (lavimt[mdx - 1] == 0) {
		nozero = FALSE_;
	    }
	    if (lavimt[mdx - 1] < minimt) {
		minimt = lavimt[mdx - 1];
	    }
/* L400: */
	}
/*  LUNSUP is list of unsupported marker types, indexed by UNSUDX */
	if (nozero) {
	    unsudx = 1;
	    lunsup[unsudx - 1] = 0;
	} else {
	    unsudx = 0;
	}
/*  since this value is less than minimum of LAVIMT, it's unsupported 
*/
	++unsudx;
	lunsup[unsudx - 1] = minimt - 1;
    } else {
/*  all non-positive marker types supported - derived directly from */

/*  marker type value */
	unsudx = 0;
    }
/* now look for unsupported positive marker type */
    maximt = 6;
    i__2 = regdx;
    for (mdx = 1; mdx <= i__2; ++mdx) {
	if (lavrmt[mdx - 1] > maximt) {
	    maximt = lavrmt[mdx - 1];
	}
/* L500: */
    }
    ++unsudx;
    lunsup[unsudx - 1] = maximt + 1;
/*  now add to end of LUNSUP entry #3 and a non-asterisk marker type */
    ++unsudx;
    lunsup[unsudx - 1] = 3;
/*  other = another available non-asterisk marker type: 2, 4, or 5 */
    i__2 = stddx;
    for (mdx = 1; mdx <= i__2; ++mdx) {
	if (lavsmt[mdx - 1] == 2 || lavsmt[mdx - 1] == 4 || lavsmt[mdx - 1] ==
		 5) {
/*  this is the only one that should appear as non-asterisk */
	    ++unsudx;
	    lunsup[unsudx - 1] = lavsmt[mdx - 1];
	    goto L610;
	}
/* L600: */
    }
/*  no other available  - goto end_asterisk */
    goto L690;
L610:
/*  Display in random order marker types in LUNSUP */
    rnperm_(&unsudx, perm);
#ifndef NO_PROTO
    xa[0] = .3f;
    yincr = .8f / unsudx;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).3;
    yincr = (float).8 / unsudx;
    yloc = (float).9;
#endif /* NO_PROTO */
    if (*tstype == 'c') {
	r__1 = yincr / 2;
	ndmw_(&r__1, &nommw);
    } else {
	r__1 = yincr / 2 / (nommw * dialog_1.wcpdc);
	nsmksc (&r__1);
    }
    numlab_(&unsudx, &c_b17, &yloc, &yincr);
    i__2 = unsudx;
    for (mdx = 1; mdx <= i__2; ++mdx) {
	ya[0] = yloc;
	if (*tstype == 'c') {
	    i__3 = rndint_(&c__1, &ndisct);
	    nspmci (&i__3);
	}
	nsmk (&lunsup[perm[mdx - 1] - 1]);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L700: */
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 68, a__1[0] = "Unavailable marker types should be displayed as"
	    " marker type number 3";
#else /* NO_PROTO */
    i__1[0] = 68, a__1[0] = "Unavailable marker types should be displayed as\
 marker type number 3";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__3, a__1, i__1, &c__2, 138L);
    setmsg_("3 4 5 6 7 8", ch__3, 11L, 138L);
    dchpf_("UNSUPPORTED MARKER TYPES: Which marker is NOT an asterisk?", &
	    unsudx, &unsudx, perm, 58L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  end_asterisk: */
L690:
/*  REGDX = size of lavrmt */
    if (regdx < 1) {
	inmsg_("No non-mandatory registered marker types are supported.", 55L)
		;
	goto L890;
    }
/* display and label at most 8 marker types in lavrmt */
    numdis = min(8,regdx);
    rnset_(&numdis, &regdx, perm);
/*  build list of marker types to be displayed */
    i__2 = numdis;
    for (mdx = 1; mdx <= i__2; ++mdx) {
	mardis[mdx - 1] = lavrmt[perm[mdx - 1] - 1];
/* L770: */
    }
/*  and sort it */
    srtiar_(&numdis, mardis);
/*  Display in order (some) marker types in LAVRMT */
#ifndef NO_PROTO
    xa[0] = .5f;
    yincr = .8f / numdis;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    yincr = (float).8 / numdis;
    yloc = (float).9;
#endif /* NO_PROTO */
    if (*tstype == 'c') {
	r__1 = yincr / 2;
	ndmw_(&r__1, &nommw);
    } else {
	r__1 = yincr / 2 / (nommw * dialog_1.wcpdc);
	nsmksc (&r__1);
    }
    i__2 = numdis;
    for (mdx = 1; mdx <= i__2; ++mdx) {
	ya[0] = yloc;
	thismt = mardis[mdx - 1];
	s_wsfi(&io___41);
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
	vislab_(mktid, "R", &c_b69, &c_b70, &r__1, &r__2, 8L, 1L);
	if (*tstype == 'c') {
	    i__3 = rndint_(&c__1, &ndisct);
	    nspmci (&i__3);
	}
	nsmk (&thismt);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L800: */
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 94, a__1[0] = "The registered non-mandatory marker types (> 5)"
	    " should agree with their registered description";
#else /* NO_PROTO */
    i__1[0] = 94, a__1[0] = "The registered non-mandatory marker types (> 5)\
 should agree with their registered description";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__4, a__1, i__1, &c__2, 164L);
    setmsg_("3 4 5 6 9", ch__4, 9L, 164L);
#ifndef NO_PROTO
    dynpf_("NON-MANDATORY REGISTERED MARKER TYPES: Is each marker type depic"
	    "ted according to its numeric identifier's specification in the I"
	    "SO register?", "Y", 140L, 1L);
#else /* NO_PROTO */
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
/* display and label at most 8 marker types in lavimt */
    numdis = min(8,impdx);
    rnset_(&numdis, &impdx, perm);
/*  build list of marker types to be displayed */
    i__2 = numdis;
    for (mdx = 1; mdx <= i__2; ++mdx) {
	mardis[mdx - 1] = lavimt[perm[mdx - 1] - 1];
/* L870: */
    }
/*  and sort it */
    srtiar_(&numdis, mardis);
/*  Display (some) marker types in LAVIMT */
#ifndef NO_PROTO
    xa[0] = .5f;
    yincr = .8f / numdis;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    yincr = (float).8 / numdis;
    yloc = (float).9;
#endif /* NO_PROTO */
    if (*tstype == 'c') {
	r__1 = yincr / 2;
	ndmw_(&r__1, &nommw);
    } else {
	r__1 = yincr / 2 / (nommw * dialog_1.wcpdc);
	nsmksc (&r__1);
    }
    i__2 = numdis;
    for (mdx = 1; mdx <= i__2; ++mdx) {
	ya[0] = yloc;
	thismt = mardis[mdx - 1];
	s_wsfi(&io___42);
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
	vislab_(mktid, "R", &c_b69, &c_b70, &r__1, &r__2, 11L, 1L);
	if (*tstype == 'c') {
	    i__3 = rndint_(&c__1, &ndisct);
	    nspmci (&i__3);
	}
	nsmk (&thismt);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L900: */
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 101, a__1[0] = "Implementor-defined marker types (< 1) should "
	    "agree with the descriptions supplied by the implementor";
#else /* NO_PROTO */
    i__1[0] = 101, a__1[0] = "Implementor-defined marker types (< 1) should \
agree with the descriptions supplied by the implementor";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__5, a__1, i__1, &c__2, 171L);
    setmsg_("3 4 5 6 10", ch__5, 10L, 171L);
#ifndef NO_PROTO
    dynpf_("IMPLEMENTOR DEFINED MARKER TYPES: Is each marker type depicted a"
	    "ccording to its numeric identifier's specification in the implem"
	    "entor documentation?", "Y", 148L, 1L);
#else /* NO_PROTO */
    dynpf_("IMPLEMENTOR DEFINED MARKER TYPES: Is each marker type depicted a\
ccording to its numeric identifier's specification in the implementor docume\
ntation?", "Y", 148L, 1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  Check if all implementor marker types already shown or */
/*  marker type appearance derived directly from value - if so, skip test 
*/
    if (impdx <= 8 || nummt < 0) {
	goto L990;
    }
    if (*tstype == 'c') {
	goto L990;
    }
#ifndef NO_PROTO
    setmsg_("10", "All reported implementor-defined marker types available f"
	    "or a given workstation type should be documented by the implemen"
	    "tor.", 2L, 125L);
#else /* NO_PROTO */
    setmsg_("10", "All reported implementor-defined marker types available f\
or a given workstation type should be documented by the implementor.", 2L, 
	    125L);
#endif /* NO_PROTO */
/* sort first */
    srtiar_(&impdx, lavimt);
    s_wsfi(&io___44);
    i__2 = impdx;
    for (mdx = 1; mdx <= i__2; ++mdx) {
	do_fio(&c__1, (char *)&lavimt[mdx - 1], (ftnlen)sizeof(integer));
    }
    e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 131, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR MARKER "
	    "TYPES: Are all these reportedly available marker types documente"
	    "d by the implementor?";
#else /* NO_PROTO */
    i__1[0] = 131, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR MARKER \
TYPES: Are all these reportedly available marker types documented by the imp\
lementor?";
#endif /* NO_PROTO */
    i__1[1] = 2600, a__1[1] = msg;
    s_cat(ch__6, a__1, i__1, &c__2, 2731L);
    dynpf_(ch__6, "Y", 2731L, 1L);
/*  end_marker type: */
L990:
/*  *** *** ***   2. marker size */
    if (*tstype == 'c') {
#ifndef NO_PROTO
	s_copy(suffix, ", even when a non-default marker type or color is us"
		"ed.", 70L, 55L);
#else /* NO_PROTO */
	s_copy(suffix, ", even when a non-default marker type or color is us\
ed.", 70L, 55L);
#endif /* NO_PROTO */
    } else {
	s_copy(suffix, ".", 70L, 1L);
	ndmkst = 2;
	pmcol = 1;
    }
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
	    mult = pow_dd(&d__1, &c_b119) * .9999f;
#else /* NO_PROTO */
	    mult = pow_dd(&d__1, &c_b119) * (float).9999;
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
    if (*tstype == 'c') {
/*  random marker type and color: */
	ndmkst = rndint_(&c__2, &c__4);
	pmcol = rndint_(&c__1, &ndisct);
    }
/*  invoke SHOWMW subroutine to test requested marker size = thismw */
/*                                    expected marker size = thismw */
    showmw_("VARIOUS MARKER SIZE SCALE FACTORS", &ndmkst, &pmcol, &thismw, &
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
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 84, a__1[0] = "Available marker size scale factors should cont"
	    "rol the realized size of a polymarker";
#else /* NO_PROTO */
    i__1[0] = 84, a__1[0] = "Available marker size scale factors should cont\
rol the realized size of a polymarker";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__7, a__1, i__1, &c__2, 154L);
    setmsg_("3 13 14 15", ch__7, 10L, 154L);
    L__1 = numpas > 0;
    ifpf_(&L__1);
/*  min_max_coerce: */
L1110:
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 107, a__1[0] = "A requested positive marker size scale factor "
	    "below the minimum available should be realized as the minimum";
#else /* NO_PROTO */
    i__1[0] = 107, a__1[0] = "A requested positive marker size scale factor \
below the minimum available should be realized as the minimum";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__8, a__1, i__1, &c__2, 177L);
    setmsg_("3 13 14 16", ch__8, 10L, 177L);
    if (*tstype == 'c') {
/*  random marker type and color: */
	ndmkst = rndint_(&c__2, &c__4);
	pmcol = rndint_(&c__1, &ndisct);
    }
    r__1 = minmw / 2;
    showmw_("POSITIVE MARKER SIZE BELOW MINIMUM", &ndmkst, &pmcol, &r__1, &
	    minmw, &nommw, pfsw, 34L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 79, a__1[0] = "A requested negative marker size scale factor s"
	    "hould be realized as the minimum";
#else /* NO_PROTO */
    i__1[0] = 79, a__1[0] = "A requested negative marker size scale factor s\
hould be realized as the minimum";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__9, a__1, i__1, &c__2, 149L);
    setmsg_("3 13 14 16", ch__9, 10L, 149L);
    if (*tstype == 'c') {
/*  random marker type and color: */
	ndmkst = rndint_(&c__2, &c__4);
	pmcol = rndint_(&c__1, &ndisct);
    }
    r__1 = -(doublereal)maxmw - 100;
    showmw_("NEGATIVE MARKER SIZE", &ndmkst, &pmcol, &r__1, &minmw, &nommw, 
	    pfsw, 20L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
/* test marker size scale above maximum = maximum */
    if (*tstype == 'c') {
/*  random marker type and color: */
	ndmkst = rndint_(&c__2, &c__4);
	pmcol = rndint_(&c__1, &ndisct);
    }
    r__1 = maxmw * 2;
    showmw_("POSITIVE MARKER SIZE ABOVE MAXIMUM", &ndmkst, &pmcol, &r__1, &
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
/* Writing concatenation */
#ifndef NO_PROTO
	i__1[0] = 98, a__1[0] = "A requested marker size scale factor above "
		"the maximum available should be realized as the maximum";
#else /* NO_PROTO */
	i__1[0] = 98, a__1[0] = "A requested marker size scale factor above \
the maximum available should be realized as the maximum";
#endif /* NO_PROTO */
	i__1[1] = 70, a__1[1] = suffix;
	s_cat(ch__10, a__1, i__1, &c__2, 168L);
	setmsg_("3 13 14 16", ch__10, 10L, 168L);
	L__1 = *pfsw == 'P';
	ifpf_(&L__1);
    }
/*  *** *** ***   Marker type 1   *** *** *** *** */
    if (*tstype == 'c') {
	goto L1350;
    }
/* set marker type = DOT */
    nsmk (&c__1);
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
/* nummar = number of markers to be drawn = random integer between 3-7 */
    nummar = rndint_(&c__3, &c__7);
/* attributes for POLYLINE */
    nsln (&c__1);
#ifndef NO_PROTO
    xincr = .1f;
#else /* NO_PROTO */
    xincr = (float).1;
#endif /* NO_PROTO */
    xloc = xincr;
    xa[0] = xloc;
#ifndef NO_PROTO
    ya[0] = .5f;
    setmsg_("3 4 5 13 14 17", "Marker type 1 should be rendered as the small"
	    "est displayable dot, regardless of the marker size scale factor "
	    "value.", 14L, 115L);
#else /* NO_PROTO */
    ya[0] = (float).5;
    setmsg_("3 4 5 13 14 17", "Marker type 1 should be rendered as the small\
est displayable dot, regardless of the marker size scale factor value.", 14L, 
	    115L);
#endif /* NO_PROTO */
/* draw reference marker and polyline separator */
    nsmksc (&c_b171);
    npm (&c__1, xa, ya);
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
/* set up and draw markers with varying sizes */
#ifndef NO_PROTO
    ya[0] = .5f;
#else /* NO_PROTO */
    ya[0] = (float).5;
#endif /* NO_PROTO */
    i__2 = nummar;
    for (ix = 1; ix <= i__2; ++ix) {
	r__1 = lmssf[ix - 1] / nommw;
	nsmksc (&r__1);
	xloc += xincr;
	xa[0] = xloc;
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
L1350:
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  *** *** ***   3. polymarker color index */
    if (*tstype == 'c') {
#ifndef NO_PROTO
	s_copy(suffix, ", even when a non-default marker type or marker size"
		" is used.", 70L, 61L);
#else /* NO_PROTO */
	s_copy(suffix, ", even when a non-default marker type or marker size\
 is used.", 70L, 61L);
#endif /* NO_PROTO */
    } else {
	s_copy(suffix, ".", 70L, 1L);
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 123, a__1[0] = "A defined polymarker color index should cause "
	    "the addressed entry in the color table to be used when rendering"
	    " a polymarker";
#else /* NO_PROTO */
    i__1[0] = 123, a__1[0] = "A defined polymarker color index should cause \
the addressed entry in the color table to be used when rendering a polymarker"
	    ;
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__11, a__1, i__1, &c__2, 193L);
    setmsg_("3 20 21 22", ch__11, 10L, 193L);
    nscmd (&globnu_1.wkid, &c__1);
/*  bckcol = background color = realized color spec for entry #0 */
/*  forcol = foreground color = realized color spec for entry #1 */
    nqcr (&globnu_1.wkid, &c__0, &c__6, &c__1, &errind, &cdim, bckcol);
    chkinq_("pqcr", &errind, 4L);
    nqcr (&globnu_1.wkid, &c__1, &c__6, &c__1, &errind, &cdim, forcol);
    chkinq_("pqcr", &errind, 4L);
/*  szcomt = maximum size of color table (including entry #0) */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &szcomt, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  how many markers to draw */
    nummar = min(8,szcomt);
/*  from values 2 to SZCOMT-1, pick NUMMAR-2 entries */
    i__2 = nummar - 2;
    i__3 = szcomt - 1;
    rnbset_(&i__2, &c__2, &i__3, mkcol);
/*  add in 0 and 1 */
    mkcol[nummar - 2] = 1;
    mkcol[nummar - 1] = 0;
    rnperm_(&nummar, perm);
/*  from mkcol, randomly select entry #visdx, but not the one that */
/*  contains 0, since this may not be re-settable. */
    i__2 = nummar - 1;
    visdx = rndint_(&c__1, &i__2);
    viscol = mkcol[visdx - 1];
/*  ensure dialogue visible */
    dialog_1.dtxci = viscol;
    nstxci (&viscol);
#ifndef NO_PROTO
    yloc = .9f;
    yincr = .8f / (nummar - 1);
    xa[0] = .2f;
#else /* NO_PROTO */
    yloc = (float).9;
    yincr = (float).8 / (nummar - 1);
    xa[0] = (float).2;
#endif /* NO_PROTO */
    if (*tstype == 'c') {
/*  non-default marker size */
	r__1 = yincr / 2;
	ndmw_(&r__1, &nommw);
    } else {
	r__1 = yincr / 2 / (nommw * dialog_1.wcpdc);
	nsmksc (&r__1);
    }
    numlab_(&nummar, &c_b17, &yloc, &yincr);
/*  for each color entry - set to background color and draw marker */
    i__2 = nummar;
    for (ix = 1; ix <= i__2; ++ix) {
	pmci = mkcol[perm[ix - 1] - 1];
	nscr (&globnu_1.wkid, &pmci, &cdim, bckcol);
	nspmci (&pmci);
	if (*tstype == 'c') {
/*  random marker type */
	    i__3 = ranmkt_(&stddx, lavsmt, &regdx, lavrmt, &impdx, lavimt);
	    nsmk (&i__3);
	} else {
	    nsmk (&c__3);
	}
	ya[0] = yloc;
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L2100: */
    }
/*  set entry mkcol(vis) to forcol */
    nscr (&globnu_1.wkid, &viscol, &cdim, forcol);
    dchpf_("DEFINED POLYMARKER COLOR INDICES: Which marker is visible?", &
	    nummar, &visdx, perm, 58L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 121, a__1[0] = "An undefined polymarker color index should cau"
	    "se entry number 1 in the color table to be used when rendering a"
	    " polymarker";
#else /* NO_PROTO */
    i__1[0] = 121, a__1[0] = "An undefined polymarker color index should cau\
se entry number 1 in the color table to be used when rendering a polymarker";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__12, a__1, i__1, &c__2, 191L);
    setmsg_("3 20 21 23", ch__12, 10L, 191L);
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
    i__2 = numci;
    for (ix = 1; ix <= i__2; ++ix) {
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
    nummar = explct + 3;
    rnperm_(&nummar, perm);
/*  draw star with color #1 */
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
    nsplci (&c__1);
    npl (&c__6, xa, ya);
/*  display interleaved: */
/*    three markers of color u1,u2,u3, */
/*    explct markers of color #1 */
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
    if (*tstype == 'c') {
/*  non-default marker size */
	r__1 = xincr / 2;
	ndmw_(&r__1, &nommw);
    } else {
	r__1 = xincr / 2 / (nommw * dialog_1.wcpdc);
	nsmksc (&r__1);
    }
/*  for each color entry - set to undefined color or #1 and draw marker */

    i__2 = nummar;
    for (ix = 1; ix <= i__2; ++ix) {
	colel = perm[ix - 1];
	if (colel <= 3) {
	    nspmci (&undf[colel - 1]);
	} else {
	    nspmci (&c__1);
	}
	if (*tstype == 'c') {
/*  random marker type */
	    i__3 = ranmkt_(&stddx, lavsmt, &regdx, lavrmt, &impdx, lavimt);
	    nsmk (&i__3);
	} else {
	    nsmk (&c__3);
	}
	xa[0] = xloc;
	npm (&c__1, xa, ya);
	xloc += xincr;
/* L2300: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED POLYMARKER COLOR INDICES: How many markers are the sa"
	    "me color as the star?", &c__12, &nummar, 84L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED POLYMARKER COLOR INDICES: How many markers are the sa\
me color as the star?", &c__12, &nummar, 84L);
#endif /* NO_PROTO */
/* L666: */
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pmattr_ */

