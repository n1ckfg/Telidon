/* e03103.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b10 = 1.f;
#else /* NO_PROTO */
static real c_b10 = (float)1.;
#endif /* NO_PROTO */
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int e03103_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e03103_(useprm)
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
    static real spec[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    , rscr_(integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr (), rscr_();
#endif /* NO_PROTO */
    static integer isiz, idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *), nsedr (integer *, integer *, integer *, 
	    integer *, real *, integer *), rsedr_(integer *, integer *, 
	    integer *, integer *, real *, integer *), nclwk (integer *), 
	    nqwkc (integer *, integer *, integer *, integer *), opmsg_(char *,
	     ftnlen);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nsplr (integer *, integer *, integer *, real *, integer *), 
	    rsplr_(integer *, integer *, integer *, real *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nstxr (integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    rstxr_(integer *, integer *, integer *, integer *, real *, real *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci (), nsedr (), rsedr_(), nclwk (), 
	    nqwkc (), opmsg_();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), nsplr (), rsplr_(), setvs_(), 
	    nstxr (), rstxr_();
#endif /* NO_PROTO */
    static integer mxedg1, mxcol1, mxply1, mxtxt1;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, tabsiz, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), nqepli (integer *, 
	    integer *, integer *, integer *, integer *), tstign_(logical *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), setrvs_(
	    char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), nqepli (), tstign_(), nqwksl (), 
	    setrvs_();
#endif /* NO_PROTO */

/*  E03103 tests the handling of error number 103 */
/*   edge flag */
/*   test precision */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "setting this bundle table entry would exceed th"
	    "e maximum number of entries allowed in the workstation bundle ta"
	    "ble", 200L, 114L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "setting this bundle table entry would exceed th\
e maximum number of entries allowed in the workstation bundle table", 200L, 
	    114L);
#endif /* NO_PROTO */
    setvs_("103", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &mxply1, &idum1, &mxtxt1, &idum2, &mxedg1, &
	    idum3, &mxcol1, &idum4);
    chkinq_("pqwksl", &errind, 6L);
    if (mxply1 >= 1000) {
	opmsg_("Initializing large polyline bundle table.", 41L);
    }
    i__1 = mxply1;
    for (ix = 1; ix <= i__1; ++ix) {
	nsplr (&globnu_1.wkid, &ix, &c__1, &c_b10, &c__0);
/* L50: */
    }
    i__1 = mxply1 + 1;
    rsplr_(&globnu_1.wkid, &i__1, &c__1, &c_b10, &c__0);
    nqepli (&globnu_1.wkid, &c__0, &errind, &tabsiz, &idum1);
    chkinq_("pqepli", &errind, 6L);
    L__1 = streq_("OO**", 4L) && tabsiz == mxply1;
    tstign_(&L__1);
    if (mxtxt1 >= 1000) {
	opmsg_("Initializing large text bundle table.", 37L);
    }
    i__1 = mxtxt1;
    for (ix = 1; ix <= i__1; ++ix) {
	nstxr (&globnu_1.wkid, &ix, &c__1, &c__0, &c_b10, &c_b10, &c__0);
/* L100: */
    }
    i__1 = mxtxt1 + 1;
    rstxr_(&globnu_1.wkid, &i__1, &c__1, &c__0, &c_b10, &c_b10, &c__0);
    if (mxedg1 >= 1000) {
	opmsg_("Initializing large edge bundle table.", 37L);
    }
    i__1 = mxedg1;
    for (ix = 1; ix <= i__1; ++ix) {
	nsedr (&globnu_1.wkid, &ix, &c__1, &c__1, &c_b10, &c__0);
/* L150: */
    }
    i__1 = mxedg1 + 1;
    rsedr_(&globnu_1.wkid, &i__1, &c__1, &c__1, &c_b10, &c__0);
    if (mxcol1 > 1000) {
	opmsg_("Initializing large colour table.", 32L);
    }
    setrvs_("0.5,0.5,0.5", spec, &isiz, 11L);
    i__1 = mxcol1;
    for (ix = 1; ix <= i__1; ++ix) {
	nscr (&globnu_1.wkid, &ix, &isiz, spec);
/* L200: */
    }
    i__1 = mxcol1 + 1;
    rscr_(&globnu_1.wkid, &i__1, &isiz, spec);
    nqeci (&globnu_1.wkid, &c__0, &errind, &tabsiz, &idum1);
    chkinq_("pqeci", &errind, 5L);
    L__1 = streq_("OO**", 4L) && tabsiz == mxcol1;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e03103_ */

