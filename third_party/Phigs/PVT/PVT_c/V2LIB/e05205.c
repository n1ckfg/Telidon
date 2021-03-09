/* e05205.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__100 = 100;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c_n1 = -1;

#ifndef NO_PROTO
/* Subroutine */ int e05205_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05205_(useprm)
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
    static real xa[2], ya[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), npl (integer *, real *, real 
	    *), nqep (integer *, integer *), nclst (void), nosep (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), npl (), nqep (), nclst (), nosep ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nopst ();
#endif /* NO_PROTO */
    static integer elpnt1, elpnt2;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int rseplb_(integer *), esetup_(integer *), 
	    tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rseplb_(), esetup_(), tstign_();
#endif /* NO_PROTO */

/*  E05205 tests the handling of error 205. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified label does not exist in the open "
	    "structure between the element pointer and the end of the structu"
	    "re", 200L, 113L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified label does not exist in the open \
structure between the element pointer and the end of the structure", 200L, 
	    113L);
#endif /* NO_PROTO */
    setvs_("205", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
    nopst (&c__100);
#ifndef NO_PROTO
    xa[0] = 0.f;
    xa[1] = .5f;
    ya[0] = 0.f;
    ya[1] = .5f;
#else /* NO_PROTO */
    xa[0] = (float)0.;
    xa[1] = (float).5;
    ya[0] = (float)0.;
    ya[1] = (float).5;
#endif /* NO_PROTO */
    npl (&c__2, xa, ya);
    nqep (&errind, &elpnt1);
    chkinq_("pqep", &errind, 4L);
    rseplb_(&c__1);
    nqep (&errind, &elpnt2);
    chkinq_("pqep", &errind, 4L);
    L__1 = streq_("O*O*", 4L) && elpnt1 == elpnt2;
    tstign_(&L__1);
    nlb (&c__1);
    npl (&c__2, xa, ya);
    nlb (&c__2);
    nosep (&c_n1);
    rseplb_(&c__1);
    nclst ();
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05205_ */

