/* e03107.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b12 = 1.f;
static real c_b16 = .5f;
static real c_b23 = .01f;
#else /* NO_PROTO */
static real c_b12 = (float)1.;
static real c_b16 = (float).5;
static real c_b23 = (float).01;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e03107_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03107_(useprm)
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
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    );
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nqedr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *), nsedr (
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    rsedr_(integer *, integer *, integer *, integer *, real *, 
	    integer *), nclwk (integer *), nqwkc (integer *, integer *, 
	    integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf ();
    extern logical appeq_();
    extern /* Subroutine */ int nqedr (), nsedr (), rsedr_(), nclwk (), 
	    nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer nedtp1, edgefg, edgecl;
    static real edgesc;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer thised, edgety, errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer untype, mxtype;

/*  E03107 tests the handling of error 107 */
/*  type of returned value */
/*   off/on switch for edge flag and error handling */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified edgetype is not available on the "
	    "specified workstation", 200L, 68L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified edgetype is not available on the \
specified workstation", 200L, 68L);
#endif /* NO_PROTO */
    setvs_("107", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "7", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqedf (&specwt, &c__1, &errind, &nedtp1, &mxtype, &idum2, &rdum1, &rdum2, 
	    &rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
    i__1 = abs(nedtp1);
    for (ix = 1; ix <= i__1; ++ix) {
	nqedf (&specwt, &ix, &errind, &idum1, &thised, &idum2, &rdum1, &rdum2,
		 &rdum3, &idum3);
	chkinq_("pqedf", &errind, 5L);
	if (thised > mxtype) {
	    mxtype = thised;
	}
/* L50: */
    }
    untype = mxtype + 1;
    nsedr (&globnu_1.wkid, &c__1, &c__0, &thised, &c_b12, &c__0);
    rsedr_(&globnu_1.wkid, &c__1, &c__1, &untype, &c_b16, &c__1);
    nqedr (&globnu_1.wkid, &c__1, &c__0, &errind, &edgefg, &edgety, &edgesc, &
	    edgecl);
    chkinq_("pqedr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && edgefg == 0 && edgety == thised && appeq_(&
	    edgesc, &c_b12, &c_b23, &c_b23) && edgecl == 0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03107_ */

