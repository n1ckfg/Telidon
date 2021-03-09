/* fort/04/03/02/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b19 = .01f;
static real c_b20 = 0.f;
static real c_b39 = 1.f;
#else /* NO_PROTO */
static real c_b19 = (float).01;
static real c_b20 = (float)0.;
static real c_b39 = (float)1.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/01                        * */
/*  *    TEST TITLE : Colour facilities                     * */
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
    logical L__1;

    /* Local variables */
    static integer i;
    static real ang0, ang1;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), nqcf (integer *
	    , integer *, integer *, integer *, integer *, real *), nqcr (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *), pass_(void), nscr (integer *, integer *, integer *, real 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), nqcf (), nqcr (), pass_(), 
	    nscr ();
#endif /* NO_PROTO */
    static integer idum1;
    static real dist0, dist1, cspec[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer ipcol;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
    extern logical rareq_();
#endif /* NO_PROTO */
    static real rspec[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nopwk ();
#endif /* NO_PROTO */
    static real actcol[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int hueang_(real *, real *, real *, real *, real *
	    ), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int hueang_(), chkinq_();
#endif /* NO_PROTO */
    static integer colavl;
    static logical husame;
    static integer errind, specon, numcol;
    static real pricol[9];
#ifndef NO_PROTO
    extern doublereal modsep_(real *, real *, real *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern doublereal modsep_();
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt, numret;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/* colour model */
/* NOTE:  INTEGER rather than enumeration type.  Explicitly defined and */

/* required portion of conceptually unbounded range defined here. */
/* colour available */
/* type of returned value */
    initgl_("04.03.02.02/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* <Inquire colour facilities> to determine */
/*  numcol = number of available colours */
/*  colavl = colour availability */
/*  pricol(1 to 3) = primary colours */
    nqcf (&specwt, &errind, &numcol, &colavl, &idum1, pricol);
    chkinq_("pqcf", &errind, 4L);
#ifndef NO_PROTO
    setmsg_("7 26", "The primary colours returned by <inquire colour facilit"
	    "ies> should be valid CIELUV values.", 4L, 90L);
#else /* NO_PROTO */
    setmsg_("7 26", "The primary colours returned by <inquire colour facilit\
ies> should be valid CIELUV values.", 4L, 90L);
#endif /* NO_PROTO */
    for (i = 1; i <= 9; ++i) {
#ifndef NO_PROTO
	if (pricol[i - 1] < 0.f || pricol[i - 1] > 1.f) {
#else /* NO_PROTO */
	if (pricol[i - 1] < (float)0. || pricol[i - 1] > (float)1.) {
#endif /* NO_PROTO */
	    fail_();
	    goto L120;
	}
/* L100: */
    }
    pass_();
L120:
#ifndef NO_PROTO
    setmsg_("7 32 33", "The primary colours of the workstation should be rea"
	    "lizable.", 7L, 60L);
#else /* NO_PROTO */
    setmsg_("7 32 33", "The primary colours of the workstation should be rea\
lizable.", 7L, 60L);
#endif /* NO_PROTO */
    nscmd (&globnu_1.wkid, &c__2);
    for (ipcol = 1; ipcol <= 7; ipcol += 3) {
	nscr (&globnu_1.wkid, &c__1, &c__3, &pricol[ipcol - 1]);
	nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &numret, actcol);
	chkinq_("pqcr", &errind, 4L);
	if (numret == 3 && rareq_(&c__3, actcol, &pricol[ipcol - 1], &c_b19, &
		c_b20)) {
/* OK so far */
	} else {
	    fail_();
	    goto L140;
	}
/* L130: */
    }
    pass_();
L140:
#ifndef NO_PROTO
    setmsg_("1 2 3", "The number of available colours should be reported as "
	    "0 or at least 2.", 5L, 70L);
#else /* NO_PROTO */
    setmsg_("1 2 3", "The number of available colours should be reported as \
0 or at least 2.", 5L, 70L);
#endif /* NO_PROTO */
    L__1 = numcol == 0 || numcol >= 2;
    ifpf_(&L__1);
    setmsg_("4", "Colour availability should be of type MONOCHROME or COLOUR."
	    , 1L, 59L);
    L__1 = colavl == 0 || colavl == 1;
    ifpf_(&L__1);
/*  <set colour model> = RGB */
    nscmd (&globnu_1.wkid, &c__1);
/*  <set colour representation> index #1 = (0, 0, 1) */
#ifndef NO_PROTO
    cspec[0] = 0.f;
    cspec[1] = 0.f;
    cspec[2] = 1.f;
#else /* NO_PROTO */
    cspec[0] = (float)0.;
    cspec[1] = (float)0.;
    cspec[2] = (float)1.;
#endif /* NO_PROTO */
    nscr (&globnu_1.wkid, &c__1, &c__3, cspec);
/*  <inquire colour representation> index #1 as REALIZED */
/*   to determine rspec = realized color spec */
    nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &numret, rspec);
    chkinq_("pqcr", &errind, 4L);
/* ang0 = angle for hue red, green, blue */
/* dist0 = distance of rspec from neutral axis */
    hueang_(rspec, &rspec[1], &rspec[2], &ang0, &dist0);
/*  <set colour representation> index #1 = (1, 1, 0) */
#ifndef NO_PROTO
    cspec[0] = 1.f;
    cspec[1] = 1.f;
    cspec[2] = 0.f;
#else /* NO_PROTO */
    cspec[0] = (float)1.;
    cspec[1] = (float)1.;
    cspec[2] = (float)0.;
#endif /* NO_PROTO */
    nscr (&globnu_1.wkid, &c__1, &c__3, cspec);
/*  <inquire colour representation> index #1 as REALIZED */
/*   to determine rspec = realized color spec */
    nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &numret, rspec);
    chkinq_("pqcr", &errind, 4L);
/* ang1 = angle for hue red, green, blue */
/* dist1 = distance of rspec from neutral axis */
    hueang_(rspec, &rspec[1], &rspec[2], &ang1, &dist1);
#ifndef NO_PROTO
    husame = modsep_(&c_b39, &ang0, &ang1) <= .05f || dist0 < .05f || dist1 < 
	    .05f;
#else /* NO_PROTO */
    husame = modsep_(&c_b39, &ang0, &ang1) <= (float).05 || dist0 < (float)
	    .05 || dist1 < (float).05;
#endif /* NO_PROTO */
    if (colavl == 1) {
#ifndef NO_PROTO
	setmsg_("5 32 33", "For colour workstations, very different hues sho"
		"uld not be realized as the same hue.", 7L, 84L);
#else /* NO_PROTO */
	setmsg_("5 32 33", "For colour workstations, very different hues sho\
uld not be realized as the same hue.", 7L, 84L);
#endif /* NO_PROTO */
	L__1 = ! husame;
	ifpf_(&L__1);
    } else {
#ifndef NO_PROTO
	setmsg_("6 32 33", "For monochrome workstations, different hues shou"
		"ld be realized as the same hue.", 7L, 79L);
#else /* NO_PROTO */
	setmsg_("6 32 33", "For monochrome workstations, different hues shou\
ld be realized as the same hue.", 7L, 79L);
#endif /* NO_PROTO */
	ifpf_(&husame);
    }
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

