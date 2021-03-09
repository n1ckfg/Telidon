/* plattr.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b17 = .2f;
static real c_b69 = .05f;
static real c_b70 = .45f;
#else /* NO_PROTO */
static real c_b17 = (float).2;
static real c_b69 = (float).05;
static real c_b70 = (float).45;
#endif /* NO_PROTO */
static doublereal c_b119 = .25;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b174 = .15f;
#else /* NO_PROTO */
static real c_b174 = (float).15;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__12 = 12;

#ifndef NO_PROTO
/* Subroutine */ int plattr_(char *tstype, ftnlen tstype_len)
#else /* NO_PROTO */
/* Subroutine */ int plattr_(tstype, tstype_len)
char *tstype;
ftnlen tstype_len;
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
    integer i__1[2], i__2, i__3;
    real r__1, r__2;
    doublereal d__1;
    logical L__1;
    char ch__1[29], ch__2[154], ch__3[132], ch__4[161], ch__5[168], ch__6[
	    2725], ch__7[155], ch__8[175], ch__9[147], ch__10[166], ch__11[
	    189], ch__12[187];

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
    extern /* Subroutine */ int ndlw_(real *, real *, real *), nqcr (integer *
	    , integer *, integer *, integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndlw_(), nqcr ();
#endif /* NO_PROTO */
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), nsln (integer *), nscr (
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nsln (), nscr ();
#endif /* NO_PROTO */
    static char pfsw[1];
    static real mult;
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
	    integer *, integer *), nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci (), nscmd ();
#endif /* NO_PROTO */
    static integer lncol[20], regdx, plcol, numci;
    static char lntid[12];
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
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer numlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqplf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nopst (integer *), rnset_(integer *, integer *, integer *), 
	    nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqplf (), nopst (), rnset_(), nsvwi ();
#endif /* NO_PROTO */
    static real bckcol[6], tstlw1, tstlw2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *), dchpfv_(char *,
	     integer *, integer *, ftnlen), chkinq_(char *, integer *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb (), dchpfv_(), chkinq_();
#endif /* NO_PROTO */
    static integer lindis[20], errind, picstr, thislt, lavslt[4], lavrlt[100],
	     lavilt[600], minilt, maxilt, numdis, unsudx, lunsup[10], szcolt, 
	    numlin, numpas, viscol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer maxcol, explct, ndisct, ndlnst;
#ifndef NO_PROTO
    extern integer ranlst_(integer *, integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern integer ranlst_();
#endif /* NO_PROTO */
    static real thislw, forcol[6], newcol[6];
    static char prompt[200], suffix[70];
    static logical nozero;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setdlg_(
	    integer *, integer *, integer *), setasf_(integer *), discol_(
	    integer *, integer *, integer *), rnperm_(integer *, integer *), 
	    numlab_(integer *, real *, real *, real *), nsplci (integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), dlstpf_(char *, integer *
	    , integer *, char *, ftnlen, ftnlen), srtiar_(integer *, integer *
	    ), vislab_(char *, char *, real *, real *, real *, real *, ftnlen,
	     ftnlen), showlw_(char *, integer *, integer *, real *, real *, 
	    real *, real *, char *, ftnlen, ftnlen), nqwksl (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), rnbset_(integer *, integer *, 
	    integer *, integer *), nstxci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setdlg_(), setasf_(), discol_(), 
	    rnperm_(), numlab_(), nsplci (), setmsg_(), dlstpf_(), srtiar_(), 
	    vislab_(), showlw_(), nqwksl (), rnbset_(), nstxci ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___41 = { 0, lntid, 0, "(A,I2,A)", 12, 1 };
    static icilist io___42 = { 0, lntid, 0, "(A,I5,A)", 12, 1 };
    static icilist io___44 = { 0, msg, 0, "(500I5)", 2600, 1 };


/*  PLATTR tests polyline attributes, either individually, using the */
/*  default values for the other attributes, or in combination, using */
/*  non-default values for the others. */
/*  Input parameter: */
/*    TSTYPE : 'i' for individual, 'c' for combination */
/* aspect source */
/*                bundled     individual */
/* linetype */
/* type of returned value */
/* colour model */
    if (*tstype == 'i' || *tstype == 'c') {
/*        tstype valid */
    } else {
/* Writing concatenation */
	i__1[0] = 28, a__1[0] = "PLATTR called with TSTYPE = ";
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
/*  use <inquire polyline facilities> to determine: */
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
    stddx = 0;
    regdx = 0;
    impdx = 0;
    i__2 = abs(numlt);
    for (ldx = 1; ldx <= i__2; ++ldx) {
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
    if (*tstype == 'c') {
/*  ndisct = number of distinct foreground colors in color table. */
	discol_(&c__8, &globnu_1.wkid, &ndisct);
    }
/*  *** *** ***   1. linetype */
/*  mark start of linetypes */
    nlb (&c__1);
/*  Display in random order all linetypes in lavslt */
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
    if (*tstype == 'c') {
	r__1 = yincr / 2;
	ndlw_(&r__1, &nomlw, &minlw);
    }
    numlab_(&stddx, &c_b17, &yloc, &yincr);
    i__2 = stddx;
    for (ldx = 1; ldx <= i__2; ++ldx) {
	ya[0] = yloc;
	ya[1] = yloc;
	if (*tstype == 'c') {
	    i__3 = rndint_(&c__1, &ndisct);
	    nsplci (&i__3);
	}
	nsln (&lavslt[perm[ldx - 1] - 1]);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L200: */
    }
/*  mark end of linetypes */
    nlb (&c__2);
    if (*tstype == 'c') {
	s_copy(suffix, ", even when a non-default linewidth or color is used."
		, 70L, 53L);
    } else {
	s_copy(suffix, ".", 70L, 1L);
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 84, a__1[0] = "The mandatory linetypes (1-4) should be recogni"
	    "zable from their standard description";
#else /* NO_PROTO */
    i__1[0] = 84, a__1[0] = "The mandatory linetypes (1-4) should be recogni\
zable from their standard description";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__2, a__1, i__1, &c__2, 154L);
    setmsg_("3 4 5 6 8", ch__2, 9L, 154L);
/*  Operator must identify each linetype according to official */
/*  English description: solid, dotted, dashed, dotted-dashed. */
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 71, a__1[0] = "MANDATORY LINETYPES: List, in order, the numeri"
	    "c labels for linetypes: ";
#else /* NO_PROTO */
    i__1[0] = 71, a__1[0] = "MANDATORY LINETYPES: List, in order, the numeri\
c labels for linetypes: ";
#endif /* NO_PROTO */
    i__1[1] = 14, a__1[1] = ldescr + (lavslt[0] - 1) * 14;
    s_cat(prompt, a__1, i__1, &c__2, 200L);
    rtans[perm[0] - 1] = 1;
    i__2 = stddx;
    for (ldx = 2; ldx <= i__2; ++ldx) {
	i__3 = itrim_(prompt, 200L);
/* Writing concatenation */
	i__1[0] = 2, a__1[0] = ", ";
	i__1[1] = 14, a__1[1] = ldescr + (lavslt[ldx - 1] - 1) * 14;
	s_cat(prompt + i__3, a__1, i__1, &c__2, 200 - i__3);
	rtans[perm[ldx - 1] - 1] = ldx;
/* L300: */
    }
    i__2 = itrim_(prompt, 200L);
    s_copy(prompt + i__2, ".", 200 - i__2, 1L);
    dlstpf_(prompt, &stddx, rtans, "L", 200L, 1L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* look for unsupported negative linetype */
    if (numlt > 0) {
/*  find negative linetype *not* in LAVILT and whether zero */
/*  is supported. */
	nozero = TRUE_;
	minilt = 0;
	i__2 = impdx;
	for (ldx = 1; ldx <= i__2; ++ldx) {
	    if (lavilt[ldx - 1] == 0) {
		nozero = FALSE_;
	    }
	    if (lavilt[ldx - 1] < minilt) {
		minilt = lavilt[ldx - 1];
	    }
/* L400: */
	}
/*  LUNSUP is list of unsupported linetypes, indexed by UNSUDX */
	if (nozero) {
	    unsudx = 1;
	    lunsup[unsudx - 1] = 0;
	} else {
	    unsudx = 0;
	}
/*  since this value is less than minimum of LAVILT, it's unsupported 
*/
	++unsudx;
	lunsup[unsudx - 1] = minilt - 1;
    } else {
/* all non-positive linetypes supported - derived directly from linety
pe value*/
	unsudx = 0;
    }
/* now look for unsupported positive linetype */
    maxilt = 5;
    i__2 = regdx;
    for (ldx = 1; ldx <= i__2; ++ldx) {
	if (lavrlt[ldx - 1] > maxilt) {
	    maxilt = lavrlt[ldx - 1];
	}
/* L500: */
    }
    ++unsudx;
    lunsup[unsudx - 1] = maxilt + 1;
/*  now add to end of LUNSUP entry #1 and a non-solid linetype */
    ++unsudx;
    lunsup[unsudx - 1] = 1;
/*  other = another available non-solid linetype: 2,3, or 4 */
    i__2 = stddx;
    for (ldx = 1; ldx <= i__2; ++ldx) {
	if (lavslt[ldx - 1] > 1) {
/*  this is the only one that should appear as non-solid */
	    ++unsudx;
	    lunsup[unsudx - 1] = lavslt[ldx - 1];
	    goto L610;
	}
/* L600: */
    }
/*  no other available  - goto end_solid */
    goto L690;
L610:
/*  Display in random order linetypes in LUNSUP */
    rnperm_(&unsudx, perm);
#ifndef NO_PROTO
    xa[0] = .3f;
    xa[1] = .9f;
    yincr = .8f / unsudx;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).3;
    xa[1] = (float).9;
    yincr = (float).8 / unsudx;
    yloc = (float).9;
#endif /* NO_PROTO */
    if (*tstype == 'c') {
	r__1 = yincr / 2;
	ndlw_(&r__1, &nomlw, &minlw);
    }
    numlab_(&unsudx, &c_b17, &yloc, &yincr);
    i__2 = unsudx;
    for (ldx = 1; ldx <= i__2; ++ldx) {
	ya[0] = yloc;
	ya[1] = yloc;
	if (*tstype == 'c') {
	    i__3 = rndint_(&c__1, &ndisct);
	    nsplci (&i__3);
	}
	nsln (&lunsup[perm[ldx - 1] - 1]);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L700: */
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 62, a__1[0] = "Unavailable linetypes should be displayed as li"
	    "netype number 1";
#else /* NO_PROTO */
    i__1[0] = 62, a__1[0] = "Unavailable linetypes should be displayed as li\
netype number 1";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__3, a__1, i__1, &c__2, 132L);
    setmsg_("3 4 5 6 7 8", ch__3, 11L, 132L);
    dchpf_("UNSUPPORTED LINETYPES: Which line is NOT solid?", &unsudx, &
	    unsudx, perm, 47L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  end_solid: */
L690:
/*  REGDX = size of lavrlt */
    if (regdx < 1) {
	inmsg_("No non-mandatory registered linetypes are supported.", 52L);
	goto L890;
    }
/* display and label at most 8 linetypes in lavrlt */
    numdis = min(8,regdx);
    rnset_(&numdis, &regdx, perm);
/*  build list of linetypes to be displayed */
    i__2 = numdis;
    for (ldx = 1; ldx <= i__2; ++ldx) {
	lindis[ldx - 1] = lavrlt[perm[ldx - 1] - 1];
/* L770: */
    }
/*  and sort it */
    srtiar_(&numdis, lindis);
/*  Display in order (some) linetypes in LAVRLT */
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
    if (*tstype == 'c') {
	r__1 = yincr / 2;
	ndlw_(&r__1, &nomlw, &minlw);
    }
    i__2 = numdis;
    for (ldx = 1; ldx <= i__2; ++ldx) {
	ya[0] = yloc;
	ya[1] = yloc;
	thislt = lindis[ldx - 1];
	s_wsfi(&io___41);
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
	vislab_(lntid, "R", &c_b69, &c_b70, &r__1, &r__2, 8L, 1L);
	if (*tstype == 'c') {
	    i__3 = rndint_(&c__1, &ndisct);
	    nsplci (&i__3);
	}
	nsln (&thislt);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L800: */
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 91, a__1[0] = "The registered non-mandatory linetypes (> 4) sh"
	    "ould agree with their registered description";
#else /* NO_PROTO */
    i__1[0] = 91, a__1[0] = "The registered non-mandatory linetypes (> 4) sh\
ould agree with their registered description";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__4, a__1, i__1, &c__2, 161L);
    setmsg_("3 4 5 6 9", ch__4, 9L, 161L);
#ifndef NO_PROTO
    dynpf_("NON-MANDATORY REGISTERED LINETYPES: Is each linetype depicted ac"
	    "cording to its numeric identifier's specification in the ISO reg"
	    "ister?", "Y", 134L, 1L);
#else /* NO_PROTO */
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
/* display and label at most 8 linetypes in lavilt */
    numdis = min(8,impdx);
    rnset_(&numdis, &impdx, perm);
/*  build list of linetypes to be displayed */
    i__2 = numdis;
    for (ldx = 1; ldx <= i__2; ++ldx) {
	lindis[ldx - 1] = lavilt[perm[ldx - 1] - 1];
/* L870: */
    }
/*  and sort it */

    srtiar_(&numdis, lindis);
/*  Display (some) linetypes in LAVILT */
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
    if (*tstype == 'c') {
	r__1 = yincr / 2;
	ndlw_(&r__1, &nomlw, &minlw);
    }
    i__2 = numdis;

    for (ldx = 1; ldx <= i__2; ++ldx) {
	ya[0] = yloc;
	ya[1] = yloc;
	thislt = lindis[ldx - 1];
	s_wsfi(&io___42);
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
	vislab_(lntid, "R", &c_b69, &c_b70, &r__1, &r__2, 11L, 1L);
	if (*tstype == 'c') {
	    i__3 = rndint_(&c__1, &ndisct);
	    nsplci (&i__3);
	}
	nsln (&thislt);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L900: */
    }

/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 98, a__1[0] = "Implementor-defined linetypes (< 1) should agre"
	    "e with the descriptions supplied by the implementor";
#else /* NO_PROTO */
    i__1[0] = 98, a__1[0] = "Implementor-defined linetypes (< 1) should agre\
e with the descriptions supplied by the implementor";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__5, a__1, i__1, &c__2, 168L);

    setmsg_("3 4 5 6 10", ch__5, 10L, 168L);

#ifndef NO_PROTO
    dynpf_("IMPLEMENTOR DEFINED LINETYPES: Is each linetype depicted accordi"
	    "ng to its numeric identifier's specification in the implementor "
	    "documentation?", "Y", 142L, 1L);
#else /* NO_PROTO */
    dynpf_("IMPLEMENTOR DEFINED LINETYPES: Is each linetype depicted accordi\
ng to its numeric identifier's specification in the implementor documentatio\
n?", "Y", 142L, 1L);
#endif /* NO_PROTO */

/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  Check if all implementor linetypes already shown or */
/*  linetype appearance derived directly from value - if so, skip test */
    if (impdx <= 8 || numlt < 0) {
	goto L990;
    }
    if (*tstype == 'c') {
	goto L990;
    }
#ifndef NO_PROTO
    setmsg_("10", "All reported implementor-defined linetypes available for "
	    "a given workstation type should be documented by the implementor."
	    , 2L, 122L);
#else /* NO_PROTO */
    setmsg_("10", "All reported implementor-defined linetypes available for \
a given workstation type should be documented by the implementor.", 2L, 122L);

#endif /* NO_PROTO */
    srtiar_(&impdx, lavilt);
    s_wsfi(&io___44);
    i__2 = impdx;
    for (ldx = 1; ldx <= i__2; ++ldx) {
	do_fio(&c__1, (char *)&lavilt[ldx - 1], (ftnlen)sizeof(integer));
    }
    e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 125, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR LINETYP"
	    "ES: Are all these reportedly available linetypes documented by t"
	    "he implementor?";
#else /* NO_PROTO */
    i__1[0] = 125, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR LINETYP\
ES: Are all these reportedly available linetypes documented by the implement\
or?";
#endif /* NO_PROTO */
    i__1[1] = 2600, a__1[1] = msg;
    s_cat(ch__6, a__1, i__1, &c__2, 2725L);
    dynpf_(ch__6, "Y", 2725L, 1L);
/*  end_linetype: */
L990:
/*  *** *** ***   2. line-width */
    if (*tstype == 'c') {
	s_copy(suffix, ", even when a non-default linetype or color is used.",
		 70L, 52L);
    } else {
	s_copy(suffix, ".", 70L, 1L);
	ndlnst = 1;
	plcol = 1;
    }
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
	    mult = pow_dd(&d__1, &c_b119) * .9999f;
#else /* NO_PROTO */
	    mult = pow_dd(&d__1, &c_b119) * (float).9999;
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
    if (*tstype == 'c') {
/*  random linetype and color: */
	ndlnst = ranlst_(&stddx, lavslt, &regdx, lavrlt, &impdx, lavilt);
	plcol = rndint_(&c__1, &ndisct);
    }
/*  invoke SHOWLW subroutine to test requested line width = thislw */
/*                                    expected line width = thislw */
    showlw_("VARIOUS LINEWIDTH SCALE FACTORS", &ndlnst, &plcol, &thislw, &
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
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 85, a__1[0] = "Available linewidth scale factors should contro"
	    "l the realized thickness of a polyline";
#else /* NO_PROTO */
    i__1[0] = 85, a__1[0] = "Available linewidth scale factors should contro\
l the realized thickness of a polyline";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__7, a__1, i__1, &c__2, 155L);
    setmsg_("3 13 14 15", ch__7, 10L, 155L);
    L__1 = numpas > 0;
    ifpf_(&L__1);
/*  min_max_coerce: */
L1110:
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 105, a__1[0] = "A requested positive linewidth scale factor be"
	    "low the minimum available should be realized as the minimum";
#else /* NO_PROTO */
    i__1[0] = 105, a__1[0] = "A requested positive linewidth scale factor be\
low the minimum available should be realized as the minimum";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__8, a__1, i__1, &c__2, 175L);
    setmsg_("3 13 14 16", ch__8, 10L, 175L);
    if (*tstype == 'c') {
/*  random linetype and color: */
	ndlnst = ranlst_(&stddx, lavslt, &regdx, lavrlt, &impdx, lavilt);
	plcol = rndint_(&c__1, &ndisct);
    }
    r__1 = minlw / 2;
    showlw_("POSITIVE LINEWIDTH BELOW MINIMUM", &ndlnst, &plcol, &r__1, &
	    minlw, &nomlw, &minlw, pfsw, 32L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 77, a__1[0] = "A requested negative linewidth scale factor sho"
	    "uld be realized as the minimum";
#else /* NO_PROTO */
    i__1[0] = 77, a__1[0] = "A requested negative linewidth scale factor sho\
uld be realized as the minimum";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__9, a__1, i__1, &c__2, 147L);
    setmsg_("3 13 14 16", ch__9, 10L, 147L);
    if (*tstype == 'c') {
/*  random linetype and color: */
	ndlnst = ranlst_(&stddx, lavslt, &regdx, lavrlt, &impdx, lavilt);
	plcol = rndint_(&c__1, &ndisct);
    }
    r__1 = -(doublereal)maxlw - 100;
    showlw_("NEGATIVE LINEWIDTH", &ndlnst, &plcol, &r__1, &minlw, &nomlw, &
	    minlw, pfsw, 18L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
/* test line width scale above maximum = maximum */
    if (*tstype == 'c') {
/*  random linetype and color: */
	ndlnst = ranlst_(&stddx, lavslt, &regdx, lavrlt, &impdx, lavilt);
	plcol = rndint_(&c__1, &ndisct);
    }
    r__1 = maxlw * 2;
    showlw_("POSITIVE LINEWIDTH ABOVE MAXIMUM", &ndlnst, &plcol, &r__1, &
	    maxlw, &nomlw, &minlw, pfsw, 32L, 1L);
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
/* Writing concatenation */
#ifndef NO_PROTO
	i__1[0] = 96, a__1[0] = "A requested linewidth scale factor above th"
		"e maximum available should be realized as the maximum";
#else /* NO_PROTO */
	i__1[0] = 96, a__1[0] = "A requested linewidth scale factor above th\
e maximum available should be realized as the maximum";
#endif /* NO_PROTO */
	i__1[1] = 70, a__1[1] = suffix;
	s_cat(ch__10, a__1, i__1, &c__2, 166L);
	setmsg_("3 13 14 16", ch__10, 10L, 166L);
	L__1 = *pfsw == 'P';
	ifpf_(&L__1);
    }
/*  *** *** ***   3. polyline color index */
    if (*tstype == 'c') {
#ifndef NO_PROTO
	s_copy(suffix, ", even when a non-default linetype or linewidth is u"
		"sed.", 70L, 56L);
#else /* NO_PROTO */
	s_copy(suffix, ", even when a non-default linetype or linewidth is u\
sed.", 70L, 56L);
#endif /* NO_PROTO */
    } else {
	s_copy(suffix, ".", 70L, 1L);
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 119, a__1[0] = "A defined polyline color index should cause th"
	    "e addressed entry in the color table to be used when rendering a"
	    " polyline";
#else /* NO_PROTO */
    i__1[0] = 119, a__1[0] = "A defined polyline color index should cause th\
e addressed entry in the color table to be used when rendering a polyline";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__11, a__1, i__1, &c__2, 189L);
    setmsg_("3 19 20 21", ch__11, 10L, 189L);
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
    numlin = min(8,szcolt);
/*  from values 2 to SZCOLT-1, pick NUMLIN-2 entries */
    i__2 = numlin - 2;
    i__3 = szcolt - 1;
    rnbset_(&i__2, &c__2, &i__3, lncol);
/*  add in 0 and 1 */
    lncol[numlin - 2] = 1;
    lncol[numlin - 1] = 0;
    rnperm_(&numlin, perm);
/*  from lncol, randomly select entry #visdx, but not the one that */
/*    contains 0, since this may not be re-settable. */
    i__2 = numlin - 1;
    visdx = rndint_(&c__1, &i__2);
    viscol = lncol[visdx - 1];
/*  ensure dialogue visible */
    dialog_1.dtxci = viscol;
    nstxci (&viscol);
#ifndef NO_PROTO
    yloc = .9f;
    yincr = .8f / (numlin - 1);
    xa[0] = .2f;
    xa[1] = .9f;
#else /* NO_PROTO */
    yloc = (float).9;
    yincr = (float).8 / (numlin - 1);
    xa[0] = (float).2;
    xa[1] = (float).9;
#endif /* NO_PROTO */
    if (*tstype == 'c') {
/*  non-default linewidth */
	r__1 = yincr / 2;
	ndlw_(&r__1, &nomlw, &minlw);
    }
    numlab_(&numlin, &c_b174, &yloc, &yincr);
/*  for each color entry - set to background color and draw line */
    i__2 = numlin;
    for (ix = 1; ix <= i__2; ++ix) {
	plci = lncol[perm[ix - 1] - 1];
	nscr (&globnu_1.wkid, &plci, &cdim, bckcol);
	nsplci (&plci);
	if (*tstype == 'c') {
/*  random linetype */
	    i__3 = ranlst_(&stddx, lavslt, &regdx, lavrlt, &impdx, lavilt);
	    nsln (&i__3);
	}
	ya[0] = yloc;
	ya[1] = yloc;
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L2100: */
    }
/*  set entry lncol(visdx) to forcol */
    nscr (&globnu_1.wkid, &viscol, &cdim, forcol);
    dchpf_("DEFINED POLYLINE COLOR INDICES: Which line is visible?", &numlin, 
	    &visdx, perm, 54L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 117, a__1[0] = "An undefined polyline color index should cause"
	    " entry number 1 in the color table to be used when rendering a p"
	    "olyline";
#else /* NO_PROTO */
    i__1[0] = 117, a__1[0] = "An undefined polyline color index should cause\
 entry number 1 in the color table to be used when rendering a polyline";
#endif /* NO_PROTO */
    i__1[1] = 70, a__1[1] = suffix;
    s_cat(ch__12, a__1, i__1, &c__2, 187L);
    setmsg_("3 19 20 22 ", ch__12, 11L, 187L);
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
/*  explct = number of explicit lines of color #1 = random integer */
/*  from 0 to 4 */
    explct = rndint_(&c__0, &c__4);
    numlin = explct + 3;
    rnperm_(&numlin, perm);
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
/*    three lines of color u1,u2,u3, */
/*    explct lines of color #1 */
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
    if (*tstype == 'c') {
/*  non-default linewidth */
	r__1 = yincr / 2;
	ndlw_(&r__1, &nomlw, &minlw);
    }
/*  for each color entry - set to background color and draw line */
    i__2 = numlin;
    for (ix = 1; ix <= i__2; ++ix) {
	colel = perm[ix - 1];
	if (colel <= 3) {
	    nsplci (&undf[colel - 1]);
	} else {
	    nsplci (&c__1);
	}
	if (*tstype == 'c') {
/*  random linetype */
	    i__3 = ranlst_(&stddx, lavslt, &regdx, lavrlt, &impdx, lavilt);
	    nsln (&i__3);
	}
	ya[0] = yloc;
	ya[1] = yloc;
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L2300: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED POLYLINE COLOR INDICES: How many of the horizontal li"
	    "nes are the same color as the star?", &c__12, &numlin, 98L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED POLYLINE COLOR INDICES: How many of the horizontal li\
nes are the same color as the star?", &c__12, &numlin, 98L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* plattr_ */

