/* e03111.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int e03111_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03111_(useprm)
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
    static integer ix, mxh, idum1, idum2, thish;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *), nqhrm (integer *, integer *, integer *, 
	    integer *, integer *), nshrm (integer *, integer *), rshrm_(
	    integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk (), nqwkc (), nqhrm (), nshrm (), 
	    rshrm_();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer chhmod, nhlhmd;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqhrmf (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqhrmf ();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer untype;

/*  E03111 tests the handling of error 111 */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified hlhsr mode is not available on th"
	    "e specified workstation", 200L, 70L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified hlhsr mode is not available on th\
e specified workstation", 200L, 70L);
#endif /* NO_PROTO */
    setvs_("111", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "10", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqhrmf (&specwt, &c__1, &errind, &nhlhmd, &mxh);
    chkinq_("pqhrmf", &errind, 6L);
    i__1 = nhlhmd;
    for (ix = 1; ix <= i__1; ++ix) {
	nqhrmf (&specwt, &ix, &errind, &idum1, &thish);
	chkinq_("pqhrmf", &errind, 6L);
	if (thish > mxh) {
	    mxh = thish;
	}
/* L50: */
    }
    untype = mxh + 1;
    nshrm (&globnu_1.wkid, &thish);
    rshrm_(&globnu_1.wkid, &untype);
    nqhrm (&globnu_1.wkid, &errind, &idum1, &chhmod, &idum2);
    chkinq_("pqhrm", &errind, 5L);
    L__1 = streq_("OO**", 4L) && chhmod == thish;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03111_ */

