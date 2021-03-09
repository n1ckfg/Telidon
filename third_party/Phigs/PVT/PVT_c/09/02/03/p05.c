/* fort/09/02/03/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.03/05                           * */
/*  *    TEST TITLE : Error indicator = 109                 * */
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
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ia1010[100]	/* was [10][10] */, ival1, ival2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), rqpar_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc (), rqpar_(), 
	    nopwk (), setvs_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *);
    extern logical intsty_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_();
    extern logical intsty_();
#endif /* NO_PROTO */

/*  interior style */
    initgl_("09.02.03/05", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "interior style PATTERN is not supported on the "
	    "workstation", 200L, 58L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "interior style PATTERN is not supported on the \
workstation", 200L, 58L);
#endif /* NO_PROTO */
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    setvs_("109,101", errinf_1.experr, &errinf_1.expsiz, 7L);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    if (intsty_(&specwt, &c__2)) {
#ifndef NO_PROTO
	inmsg_("This workstation supports the interior style PATTERN; skip t"
		"he test.", 68L);
#else /* NO_PROTO */
	inmsg_("This workstation supports the interior style PATTERN; skip t\
he test.", 68L);
#endif /* NO_PROTO */
    } else {
	rqpar_(&globnu_1.wkid, &c__1, &c__0, &c__10, &c__10, &errind, &ival1, 
		&ival2, ia1010);
    }
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

