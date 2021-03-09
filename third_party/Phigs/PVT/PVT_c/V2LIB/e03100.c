/* e03100.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__101 = 101;
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b15 = 1.f;
#else /* NO_PROTO */
static real c_b15 = (float)1.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e03100_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03100_(useprm)
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
    extern /* Subroutine */ int rsir_(integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsir_();
#endif /* NO_PROTO */
    static integer idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsedi_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsedi_();
#endif /* NO_PROTO */
    static integer index;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsedr_(integer *, integer *, integer *, 
	    integer *, real *, integer *), nclwk (integer *), nclst (void), 
	    rspli_(integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    rspmr_(integer *, integer *, integer *, real *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    rstxi_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsedr_(), nclwk (), nclst (), rspli_();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), rspmr_(), setvs_(), nopst (), 
	    rstxi_();
#endif /* NO_PROTO */
    static integer nentr1, nentr2;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqepmi (integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), nqepmi ();
#endif /* NO_PROTO */

/*  E03100 tests the handling of error number 100 */
/*  type of returned value */
    s_copy(errchr_1.curcon, "the bundle index value is less than one", 200L, 
	    39L);
    setvs_("100", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    esetup_(useprm);
    nopst (&c__101);
    rspli_(&c__0);
    L__1 = streq_("O*O*", 4L);
    tstign_(&L__1);
    rstxi_(&c_n1);
    index = rndint_(&c_n1, &c__0);
    rsedi_(&index);
    nclst ();
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqepmi (&globnu_1.wkid, &c__0, &errind, &nentr1, &idum1);
    chkinq_("pqepmi", &errind, 6L);
    rspmr_(&globnu_1.wkid, &c__0, &c__1, &c_b15, &c__0);
    nqepmi (&globnu_1.wkid, &c__0, &errind, &nentr2, &idum1);
    chkinq_("pqepmi", &errind, 6L);
    L__1 = streq_("OO**", 4L) && nentr1 == nentr2;
    tstign_(&L__1);
    rsir_(&globnu_1.wkid, &c_n1, &c__1, &c__1, &c__0);
    index = rndint_(&c_n1, &c__0);
    rsedr_(&globnu_1.wkid, &index, &c__1, &c__1, &c_b15, &c__0);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03100_ */

