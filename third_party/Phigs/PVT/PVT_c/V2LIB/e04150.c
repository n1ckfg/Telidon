/* e04150.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__3 = 3;
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int e04150_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04150_(useprm)
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
    static integer ix, isiz, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), nclwk (integer *), 
	    nqwkc (integer *, integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), nclwk (), nqwkc ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static integer maxvw;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */
    static integer nvwix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwr (integer *, integer *, real *, real *, 
	    real *, integer *), rsvwr_(integer *, integer *, real *, real *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwr (), rsvwr_();
#endif /* NO_PROTO */
    static real clplm3[4], clplm4[6], mapmt3[9]	/* was [3][3] */, mapmt4[16]	
	    /* was [4][4] */, rotmt3[9]	/* was [3][3] */, rotmt4[16]	/* 
	    was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rsvwr3_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *), chkinq_(char *, integer 
	    *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rsvwr3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqevwi (integer *, integer *, integer *, integer *, integer *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), setrvs_(
	    char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), nqevwi (), nqwksl (), 
	    setrvs_();
#endif /* NO_PROTO */

/*   E04150 tests the handling of error 150 */
/*   clipping indicator */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "setting this view table entry would exceed the "
	    "maximum number of entries allowed in the workstation view table", 
	    200L, 110L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "setting this view table entry would exceed the \
maximum number of entries allowed in the workstation view table", 200L, 110L);

#endif /* NO_PROTO */
    setvs_("150", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &idum6, 
	    &idum7, &maxvw);
    chkinq_("pqwksl", &errind, 6L);
    idmat_(&c__3, rotmt3);
    idmat_(&c__3, mapmt3);
    idmat_(&c__4, rotmt4);
    idmat_(&c__4, mapmt4);
    setrvs_("0.,1.,0.,1.", clplm3, &isiz, 11L);
    setrvs_("0.,1.,0.,1.,0.,1.", clplm4, &isiz, 17L);
/*  valid entries are 0 (unsettable) thru MAXVW-1 */
    i__1 = maxvw - 1;
    for (ix = 1; ix <= i__1; ++ix) {
	nsvwr (&globnu_1.wkid, &ix, rotmt3, mapmt3, clplm3, &c__1);
/* L100: */
    }
    rsvwr_(&globnu_1.wkid, &maxvw, rotmt3, mapmt3, clplm3, &c__1);
    nqevwi (&globnu_1.wkid, &c__0, &errind, &nvwix, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    L__1 = streq_("OO**", 4L) && nvwix == maxvw;
    tstign_(&L__1);
    rsvwr3_(&globnu_1.wkid, &maxvw, rotmt4, mapmt4, clplm4, &c__1, &c__1, &
	    c__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04150_ */

