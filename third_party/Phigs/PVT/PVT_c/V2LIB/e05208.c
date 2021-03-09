/* e05208.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b6 = .5f;
#else /* NO_PROTO */
static real c_b6 = (float).5;
#endif /* NO_PROTO */
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b8 = -.1f;
static real c_b10 = 1.1f;
#else /* NO_PROTO */
static real c_b8 = (float)-.1;
static real c_b10 = (float)1.1;
#endif /* NO_PROTO */
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b14 = .001f;
#else /* NO_PROTO */
static real c_b14 = (float).001;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e05208_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05208_(useprm)
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
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int crest_(void), nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), npost (integer *, 
	    integer *, real *), rpost_(integer *, integer *, real *), enderr_(
	    void);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int crest_(), nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), npost (), rpost_(), 
	    enderr_();
#endif /* NO_PROTO */
    static integer errind, number;
    static real orgpri;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqpost (integer *, integer *, integer *, integer *, integer *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), nqpost ();
#endif /* NO_PROTO */
    static integer postst;

/*   E05208 tests the handling of error 208. */
    s_copy(errchr_1.curcon, "the specified display priority is out of range", 
	    200L, 46L);
    setvs_("208", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    crest_();
    npost (&globnu_1.wkid, &c__100, &c_b6);
    rpost_(&globnu_1.wkid, &c__101, &c_b8);
    rpost_(&globnu_1.wkid, &c__101, &c_b10);
    nqpost (&globnu_1.wkid, &c__1, &errind, &number, &postst, &orgpri);
    L__1 = streq_("OO**", 4L) && errind == 0 && number == 1 && postst == 100 
	    && appeq_(&orgpri, &c_b6, &c_b14, &c_b14);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05208_ */

