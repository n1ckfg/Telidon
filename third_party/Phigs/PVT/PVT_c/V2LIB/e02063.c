/* e02063.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/* Subroutine */ int e02063_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e02063_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char cdum[1];
    static integer idum1, idum2, idum3, idum4, idum5, idum6, owkid;
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqphf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqphf (), inmsg_();
#endif /* NO_PROTO */
    static integer maxwk;
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    ropwk_(integer *, integer *, integer *), setvs_(char *, integer *,
	     integer *, ftnlen);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), ropwk_(), setvs_();
#endif /* NO_PROTO */
    static integer oconid;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, nwkall;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer nmopwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopwk (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopwk ();
#endif /* NO_PROTO */
    static integer owtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int multws_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int multws_();
#endif /* NO_PROTO */

/*  E02063 tests the handling of error number 63. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "it would exceed the maximum number of simultane"
	    "ously open workstations", 200L, 70L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "it would exceed the maximum number of simultane\
ously open workstations", 200L, 70L);
#endif /* NO_PROTO */
    setvs_("63", errinf_1.experr, &errinf_1.expsiz, 2L);
    s_copy(errchr_1.errsrs, "12", 40L, 2L);
    esetup_(useprm);
    multws_(&c__0, "a", &nwkall, &idum1, &idum2, &idum3, cdum, 1L, 1L);
    nqphf (&c__0, &errind, &maxwk, &idum1, &idum2, &idum3, &idum4, &idum5, &
	    idum6);
    chkinq_("pqphf", &errind, 5L);
    if (nwkall <= maxwk) {
#ifndef NO_PROTO
	inmsg_("The number of all accessible workstations is less than or eq"
		"ual to maximum number of simultaneously open workstations; t"
		"herefore this test is skipped.", 150L);
#else /* NO_PROTO */
	inmsg_("The number of all accessible workstations is less than or eq\
ual to maximum number of simultaneously open workstations; therefore this te\
st is skipped.", 150L);
#endif /* NO_PROTO */
	return 0;
    }
    i__1 = maxwk + 1;
    for (ix = 1; ix <= i__1; ++ix) {
	multws_(&ix, "a", &idum1, &owkid, &oconid, &owtype, owcat, 1L, 1L);
	if (ix <= maxwk) {
	    nopwk (&owkid, &oconid, &owtype);
	} else {
	    ropwk_(&owkid, &oconid, &owtype);
	}
/* L150: */
    }
    nqopwk (&c__0, &errind, &nmopwk, &idum1);
    chkinq_("pqopwk", &errind, 6L);
    L__1 = streq_("OO**", 4L) && nmopwk == maxwk;
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e02063_ */

