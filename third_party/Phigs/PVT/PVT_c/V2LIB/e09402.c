/* e09402.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/* Subroutine */ int e09402_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e09402_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer arid, narf, arnm1, arnm2, qarid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqarf (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqarf ();
#endif /* NO_PROTO */
    static integer qarnm;
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nclarf (integer *), enderr_(void);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nclarf (), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), esetup_(integer *), 
	    noparf (integer *, integer *), roparf_(integer *, integer *), 
	    tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), esetup_(), noparf (), roparf_(), 
	    tstign_();
#endif /* NO_PROTO */

/*   E09402 tests the handling of error 402. */
    s_copy(errchr_1.curcon, "the archive file identifier is already in use", 
	    200L, 45L);
    setvs_("402", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
    arid = 11;
    avarnm_(&arnm1);
    noparf (&arid, &arnm1);
    avarnm_(&arnm2);
    roparf_(&arid, &arnm2);
    nqarf (&c__1, &errind, &narf, &qarid, &qarnm);
    L__1 = streq_("O**O", 4L) && errind == 0 && narf == 1 && qarid == arid && 
	    qarnm == arnm1;
    tstign_(&L__1);
    nclarf (&arid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e09402_ */

