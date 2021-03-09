/* e03113.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__801 = 801;
static integer c_n1 = -1;
static integer c__2 = 2;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b19 = .5f;
static real c_b23 = 1.f;
#else /* NO_PROTO */
static real c_b19 = (float).5;
static real c_b23 = (float)1.;
#endif /* NO_PROTO */
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b30 = .01f;
#else /* NO_PROTO */
static real c_b30 = (float).01;
#endif /* NO_PROTO */
static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int e03113_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03113_(useprm)
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
    static integer col[1]	/* was [1][1] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), rscr_(integer *, integer *, 
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), rscr_();
#endif /* NO_PROTO */
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsir_(integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsir_();
#endif /* NO_PROTO */
    static integer idum1, sizb4;
    static real cspec[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *);
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nclwk (integer *), nclst (void), nqwkc (
	    integer *, integer *, integer *, integer *), rspar_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nqpmr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nspmr (integer *, integer *, integer *, 
	    real *, integer *), rspmr_(integer *, integer *, integer *, real *
	    , integer *), setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci ();
    extern logical appeq_();
    extern /* Subroutine */ int nclwk (), nclst (), nqwkc (), rspar_();
    extern logical streq_();
    extern /* Subroutine */ int nqpmr (), nopwk (), nspmr (), rspmr_(), 
	    setvs_(), nopst ();
#endif /* NO_PROTO */
    static real mkscal;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsedci_(integer *), chkinq_(char *, integer *,
	     ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsedci_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, sizaft, mktype, mkcolo, specwt;
#ifndef NO_PROTO
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int esetup_(integer *), rsplci_(integer *), 
	    tstign_(logical *), rstxci_(integer *), setrvs_(char *, real *, 
	    integer *, ftnlen);
    extern logical intsty_(integer *, integer *);
#else /* NO_PROTO */
    extern logical strcon_();
    extern /* Subroutine */ int esetup_(), rsplci_(), tstign_(), rstxci_(), 
	    setrvs_();
    extern logical intsty_();
#endif /* NO_PROTO */

/*  E03113 tests the handling of error 113. */
/*  interior styles */
/*  type of return value */
    s_copy(errchr_1.curcon, "the colour index value is less than zero", 200L, 
	    40L);
    setvs_("113", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "12", 40L, 2L);
    esetup_(useprm);
    nopst (&c__101);
    nlb (&c__801);
    rsplci_(&c_n1);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__101, "67,801", 6L);
    tstign_(&L__1);
    rstxci_(&c_n1);
    rsedci_(&c_n1);
    L__1 = streq_("O*O*", 4L) && strcon_(&c__101, "67,801", 6L);
    tstign_(&L__1);
    nclst ();
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nspmr (&globnu_1.wkid, &c__2, &c__1, &c_b19, &c__1);
    rspmr_(&globnu_1.wkid, &c__2, &c__2, &c_b23, &c_n1);
    nqpmr (&globnu_1.wkid, &c__2, &c__0, &errind, &mktype, &mkscal, &mkcolo);
    chkinq_("pqpmr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && mktype == 1 && appeq_(&mkscal, &c_b19, &
	    c_b30, &c_b30) && mkcolo == 1;
    tstign_(&L__1);
    rsir_(&globnu_1.wkid, &c__1, &c__0, &c__1, &c_n1);
    col[0] = -1;
    if (intsty_(&specwt, &c__2)) {
	rspar_(&globnu_1.wkid, &c__1, &c__1, &c__1, &c__1, &c__1, &c__1, &
		c__1, col);
    }
    nqeci (&globnu_1.wkid, &c__0, &errind, &sizb4, &idum1);
    chkinq_("pqeci", &errind, 5L);
    setrvs_("0.5,0.5,0.5", cspec, &isiz, 11L);
    rscr_(&globnu_1.wkid, &c_n1, &c__3, cspec);
    nqeci (&globnu_1.wkid, &c__0, &errind, &sizaft, &idum1);
    chkinq_("pqeci", &errind, 5L);
    L__1 = streq_("OO**", 4L) && sizb4 == sizaft;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03113_ */

