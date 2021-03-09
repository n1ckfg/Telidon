/* e03116.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__6 = 6;

#ifndef NO_PROTO
/* Subroutine */ int e03116_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03116_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer col[6]	/* was [2][3] */ = { 0,1,1,1,0,1 };
    static integer colia[6]	/* was [2][3] */ = { 1,0,0,0,1,0 };

    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer dx, dy, dx1, dy1, psiz, idum1, idum2, idum3, idum4, idum5, 
	    idum7, idum8;
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *), 
	    nqpar (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nqwkc (integer *, 
	    integer *, integer *, integer *), nspar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rspar_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical iareq_();
    extern /* Subroutine */ int inmsg_(), nclwk (), nqpar (), nqwkc (), 
	    nspar (), rspar_();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer colia1[6]	/* was [2][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), nqwksl ();
#endif /* NO_PROTO */

/*   E03116 tests the handling of error 116. */
/*  type of returned value */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "one of the dimensions of pattern colour index a"
	    "rray is less than one", 200L, 68L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "one of the dimensions of pattern colour index a\
rray is less than one", 200L, 68L);
#endif /* NO_PROTO */
    setvs_("116", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "15", 40L, 2L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &psiz, &
	    idum7, &idum8);
    chkinq_("pqwksl", &errind, 6L);
    if (psiz < 1) {
#ifndef NO_PROTO
	inmsg_("Skipping test for invalid pattern because workstation patter"
		"n table size is zero.", 81L);
#else /* NO_PROTO */
	inmsg_("Skipping test for invalid pattern because workstation patter\
n table size is zero.", 81L);
#endif /* NO_PROTO */
	return 0;
    }
    dx = 0;
    dy = 2;
    nspar (&globnu_1.wkid, &c__1, &c__2, &c__3, &c__1, &c__1, &c__2, &c__3, 
	    col);
    rspar_(&globnu_1.wkid, &c__1, &dx, &dy, &c__1, &c__1, &c__2, &c__3, colia)
	    ;
    nqpar (&globnu_1.wkid, &c__1, &c__0, &c__2, &c__3, &errind, &dx1, &dy1, 
	    colia1);
    chkinq_("pqpar", &errind, 5L);
    L__1 = streq_("OO**", 4L) && dx1 == 2 && dy1 == 3 && iareq_(&c__6, colia1,
	     col);
    tstign_(&L__1);
    rspar_(&globnu_1.wkid, &c__1, &c__2, &c__3, &c__1, &c__1, &c__2, &c__0, 
	    colia);
    dx = 2;
    dy = 0;
    rspar_(&globnu_1.wkid, &c__1, &dx, &dy, &c__1, &c__1, &c__2, &c__3, colia)
	    ;
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03116_ */

