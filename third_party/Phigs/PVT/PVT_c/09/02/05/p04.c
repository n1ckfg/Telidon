/* fort/09/02/05/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__1 = 1;
static integer c__103 = 103;
#ifndef NO_PROTO
static real c_b13 = 1.f;
static real c_b16 = .1f;
#else /* NO_PROTO */
static real c_b13 = (float)1.;
static real c_b16 = (float).1;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.05/04                           * */
/*  *    TEST TITLE : Error indicator = 204                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real px[1] = { 1.f };
    static real py[1] = { 1.f };
    static real pz[1] = { 1.f };
#else /* NO_PROTO */
    static real px[1] = { (float)1. };
    static real py[1] = { (float)1. };
    static real pz[1] = { (float)1. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i1[5], i2[5], i3[5], i4[5], i5[5], i6[5], i7[5], i8[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 ();
#endif /* NO_PROTO */
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int riss_(real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int riss_();
#endif /* NO_PROTO */
    static integer ira210[20]	/* was [2][10] */, ival1;
#ifndef NO_PROTO
    extern /* Subroutine */ int riss3_(real *, real *, real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     endit_(void), nclst (void), nexst (integer *), setvs_(char *, 
	    integer *, integer *, ftnlen), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int riss3_(), endit_(), nclst (), nexst (), 
	    setvs_(), nopst ();
#endif /* NO_PROTO */
    static integer errind, stpath[6]	/* was [2][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_();
#endif /* NO_PROTO */

/*   clipping indicator */
    initgl_("09.02.05/04", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified search ceiling index is out of ra"
	    "nge", 200L, 50L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified search ceiling index is out of ra\
nge", 200L, 50L);
#endif /* NO_PROTO */
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    setvs_("204", errinf_1.experr, &errinf_1.expsiz, 3L);
    nopst (&c__101);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
    npm3 (&c__1, px, py, pz);
    nexst (&c__103);
    nclst ();
    nopst (&c__103);
    npm3 (&c__1, px, py, pz);
    nclst ();
    setvs_("101,1,102,1", stpath, &isiz, 11L);
    i__1 = isiz / 2;
    riss3_(&c_b13, &c_b13, &c_b13, &c_b16, &i__1, stpath, &c__0, &c__3, &c__1,
	     i1, i2, i3, i4, &c__1, i5, i6, i7, i8, &c__10, &errind, &ival1, 
	    ira210);
    i__1 = isiz / 2;
    riss_(&c_b13, &c_b13, &c_b16, &i__1, stpath, &c__0, &c__0, &c__1, i1, i2, 
	    i3, i4, &c__1, i5, i6, i7, i8, &c__10, &errind, &ival1, ira210);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

