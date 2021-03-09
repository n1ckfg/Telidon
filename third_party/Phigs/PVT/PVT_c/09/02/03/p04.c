/* fort/09/02/03/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b12 = 1.f;
static real c_b13 = .1f;
#else /* NO_PROTO */
static real c_b12 = (float)1.;
static real c_b13 = (float).1;
#endif /* NO_PROTO */
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.03/04                           * */
/*  *    TEST TITLE : Error indicator = 106                 * */
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
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static real ra2[2], rb2[2];
    static integer ival1, ival2, ival3, ival4, ival5;
    static real rval1, rval2, rval3, rval4;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer npair;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *), nopwk (integer *, integer *, 
	    integer *), nqtxf (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *, real *
	    , real *, integer *), setvs_(char *, integer *, integer *, ftnlen)
	    , rqtxx_(integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *, char *, integer *, real *, real *, real *, 
	    real *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqwkc (), nopwk (), nqtxf (), 
	    setvs_(), rqtxx_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind, hifont, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_();
#endif /* NO_PROTO */
    static integer txtprc, txtfnt;

/*  text precision */
    initgl_("09.02.03/04", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified font is not available for the req"
	    "uested text precision on the specified workstation", 200L, 97L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified font is not available for the req\
uested text precision on the specified workstation", 200L, 97L);
#endif /* NO_PROTO */
    setvs_("106", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqtxf (&specwt, &c__0, &errind, &npair, &ival1, &ival2, &ival3, &rval1, &
	    rval2, &ival4, &rval3, &rval4, &ival5);
    chkinq_("pqtxf", &errind, 5L);
    if (npair == 0) {
	inmsg_("There are no text font and precision pairs, skip the test.", 
		58L);
	goto L666;
    }
    hifont = 1;
/*  must find a non-STROKE font */
    i__1 = npair;
    for (ix = 1; ix <= i__1; ++ix) {
	nqtxf (&specwt, &ix, &errind, &ival1, &txtfnt, &txtprc, &ival2, &
		rval1, &rval2, &ival3, &rval3, &rval4, &ival4);
	chkinq_("pqtxf", &errind, 5L);
	if (txtprc == 2) {
	    if (txtfnt > hifont) {
		hifont = txtfnt;
	    }
	}
/* L50: */
    }
    ++hifont;
    rqtxx_(&specwt, &hifont, &c_b12, &c_b13, &c_b13, &c__1, &c__1, &c__1, 
	    "TEXT", &errind, ra2, rb2, &rval1, &rval2, 4L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

