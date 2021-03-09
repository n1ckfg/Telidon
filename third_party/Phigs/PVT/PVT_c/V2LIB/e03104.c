/* e03104.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b11 = .9f;
#else /* NO_PROTO */
static real c_b11 = (float).9;
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
/* Subroutine */ int e03104_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03104_(useprm)
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
    extern /* Subroutine */ int nclwk (integer *), nqplf (integer *, integer *
	    , integer *, integer *, integer *, integer *, real *, real *, 
	    real *, integer *), nqwkc (integer *, integer *, integer *, 
	    integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nqplr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nsplr (integer *, integer *, integer *, 
	    real *, integer *), rsplr_(integer *, integer *, integer *, real *
	    , integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nclwk (), nqplf (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nqplr (), nopwk (), nsplr (), rsplr_(), 
	    setvs_();
#endif /* NO_PROTO */
    static integer nltyp1, linecl;
    static real linesc;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, linety, thislt, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static integer untype, mxtype;

/*   E03104 tests the handling of error number 104 */
/*  type of retured value */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified linetype is not available on the "
	    "specified workstation", 200L, 68L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified linetype is not available on the \
specified workstation", 200L, 68L);
#endif /* NO_PROTO */
    setvs_("104", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqplf (&specwt, &c__1, &errind, &nltyp1, &mxtype, &idum2, &rdum1, &rdum2, 
	    &rdum3, &idum3);
    chkinq_("pqplf", &errind, 5L);
    i__1 = abs(nltyp1);
    for (ix = 1; ix <= i__1; ++ix) {
	nqplf (&specwt, &ix, &errind, &idum1, &thislt, &idum2, &rdum1, &rdum2,
		 &rdum3, &idum3);
	chkinq_("pqplf", &errind, 5L);
	if (thislt > mxtype) {
	    mxtype = thislt;
	}
/* L50: */
    }
    untype = mxtype + 1;

    nsplr (&globnu_1.wkid, &c__1, &thislt, &c_b11, &c__0);
    rsplr_(&globnu_1.wkid, &c__1, &untype, &c_b14, &c__1);
    nqplr (&globnu_1.wkid, &c__1, &c__0, &errind, &linety, &linesc, &linecl);
    chkinq_("pqplr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && linety == thislt && appeq_(&linesc, &c_b11, &
	    c_b21, &c_b21) && linecl == 0;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03104_ */

