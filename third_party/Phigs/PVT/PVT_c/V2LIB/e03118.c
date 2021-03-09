/* e03118.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__10 = 10;
#ifndef NO_PROTO
static real c_b28 = .01f;
#else /* NO_PROTO */
static real c_b28 = (float).01;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e03118_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03118_(useprm)
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
    static real spec[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *), rscr_(integer *, integer *, 
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr (), rscr_();
#endif /* NO_PROTO */
    static integer isiz;
    static real spec1[10], spec2[10];
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
    extern logical rareq_();
    extern /* Subroutine */ int nclwk (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer numcp2, lclmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcmdf (integer *, integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcmdf ();
#endif /* NO_PROTO */
    static integer nclmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), setrvs_();
#endif /* NO_PROTO */

/*  E03118 tests the handling of error 118. */
/*  type of returned values */
/* colour model */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "one of the components of the colour specificati"
	    "on is out of range", 200L, 65L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "one of the components of the colour specificati\
on is out of range", 200L, 65L);
#endif /* NO_PROTO */
    setvs_("118", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "17", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqcmdf (&specwt, &c__0, &errind, &nclmod, &idum1, &idum2);
    chkinq_("pqcmdf", &errind, 6L);
    i__1 = nclmod;
    for (ix = 1; ix <= i__1; ++ix) {
	nqcmdf (&specwt, &ix, &errind, &idum1, &lclmod, &idum2);
	chkinq_("pqcmdf", &errind, 6L);
	if (lclmod < 1 || lclmod > 4) {
	    goto L150;
	}
	nscmd (&globnu_1.wkid, &lclmod);
	setrvs_("0.5,0.5,0.5", spec1, &isiz, 11L);
	nscr (&globnu_1.wkid, &c__2, &c__3, spec1);
	setrvs_("-0.5, 0., 1.", spec, &isiz, 12L);
	rscr_(&globnu_1.wkid, &c__2, &c__3, spec);
	setrvs_("0., 1.01, 0.5", spec, &isiz, 13L);
	rscr_(&globnu_1.wkid, &c__2, &c__3, spec);
	setrvs_("0., 0.5, -0.01", spec, &isiz, 14L);
	rscr_(&globnu_1.wkid, &c__2, &c__3, spec);
	nqcr (&globnu_1.wkid, &c__2, &c__10, &c__0, &errind, &numcp2, spec2);
	chkinq_("pqcr", &errind, 4L);
	L__1 = streq_("OO**", 4L) && numcp2 == 3 && rareq_(&c__3, spec2, 
		spec1, &c_b28, &c_b28);
	tstign_(&L__1);
L150:
	;
    }
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03118_ */

