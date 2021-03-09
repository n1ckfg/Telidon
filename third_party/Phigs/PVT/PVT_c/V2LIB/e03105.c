/* e03105.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b11 = 1.f;
#else /* NO_PROTO */
static real c_b11 = (float)1.;
#endif /* NO_PROTO */
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b14 = .5f;
static real c_b21 = .01f;
#else /* NO_PROTO */
static real c_b14 = (float).5;
static real c_b21 = (float).01;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e03105_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03105_(useprm)
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
    static integer ix, idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nqpmf (integer *, integer *
	    , integer *, integer *, integer *, integer *, real *, real *, 
	    real *, integer *), nqwkc (integer *, integer *, integer *, 
	    integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nqpmr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nspmr (integer *, integer *, integer *, 
	    real *, integer *), rspmr_(integer *, integer *, integer *, real *
	    , integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nclwk (), nqpmf (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nqpmr (), nopwk (), nspmr (), rspmr_(), 
	    setvs_();
#endif /* NO_PROTO */
    static integer nmtyp1, markcl;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static real marksc;
    static integer errind, markty, thismt, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer untype, mxtype;

/*  E03105 tests the handling of error number 105 */
/*  type of returned value */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified marker type is not available on t"
	    "he specified workstation", 200L, 71L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified marker type is not available on t\
he specified workstation", 200L, 71L);
#endif /* NO_PROTO */
    setvs_("105", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqpmf (&specwt, &c__1, &errind, &nmtyp1, &mxtype, &idum2, &rdum1, &rdum2, 
	    &rdum3, &idum3);
    chkinq_("pqpmf", &errind, 5L);
    i__1 = abs(nmtyp1);
    for (ix = 1; ix <= i__1; ++ix) {
	nqpmf (&specwt, &ix, &errind, &idum1, &thismt, &idum2, &rdum1, &rdum2,
		 &rdum3, &idum3);
	chkinq_("pqpmf", &errind, 5L);
	if (thismt > mxtype) {
	    mxtype = thismt;
	}
/* L50: */
    }
    untype = mxtype + 1;

    nspmr (&globnu_1.wkid, &c__1, &thismt, &c_b11, &c__0);
    rspmr_(&globnu_1.wkid, &c__1, &untype, &c_b14, &c__1);
    nqpmr (&globnu_1.wkid, &c__1, &c__0, &errind, &markty, &marksc, &markcl);
    chkinq_("pqpmr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && markty == thismt && appeq_(&marksc, &c_b11, &
	    c_b21, &c_b21) && markcl == 0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03105_ */

