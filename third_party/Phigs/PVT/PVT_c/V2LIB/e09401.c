/* e09401.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/* Subroutine */ int e09401_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e09401_(useprm)
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
    static integer ix, arnm, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqarf (integer *, integer *, integer *, 
	    integer *, integer *), nqphf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nclarf (integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqarf (), nqphf ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nclarf (), chkinq_();
#endif /* NO_PROTO */
    static integer maxarf;
#ifndef NO_PROTO
    extern /* Subroutine */ int enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int enderr_();
#endif /* NO_PROTO */
    static integer errind, numarf;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), avarnm_(integer *), 
	    noparf (integer *, integer *), roparf_(integer *, integer *), 
	    tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), avarnm_(), noparf (), roparf_(), 
	    tstign_();
#endif /* NO_PROTO */

/*  E09401 tests the handling of error 401. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "opening this archive file would exceed the maxi"
	    "mum number of simultaneously open archive files", 200L, 94L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "opening this archive file would exceed the maxi\
mum number of simultaneously open archive files", 200L, 94L);
#endif /* NO_PROTO */
    setvs_("401", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    esetup_(useprm);
    nqphf (&idum1, &errind, &idum2, &maxarf, &idum3, &idum4, &idum5, &idum6, &
	    idum7);
    chkinq_("pqphf", &errind, 5L);
    i__1 = maxarf;
    for (ix = 1; ix <= i__1; ++ix) {
	avarnm_(&arnm);
	noparf (&ix, &arnm);
/* L100: */
    }
    avarnm_(&arnm);
    i__1 = maxarf + 1;
    roparf_(&i__1, &arnm);
    nqarf (&c__0, &errind, &numarf, &idum1, &idum2);
    chkinq_("pqarf", &errind, 5L);
    L__1 = streq_("O**O", 4L) && numarf == maxarf;
    tstign_(&L__1);
    i__1 = maxarf;
    for (ix = 1; ix <= i__1; ++ix) {
	nclarf (&ix);
/* L150: */
    }
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e09401_ */

