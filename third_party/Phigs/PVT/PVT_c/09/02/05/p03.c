/* fort/09/02/05/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b10 = 1.f;
static real c_b13 = .1f;
#else /* NO_PROTO */
static real c_b10 = (float)1.;
static real c_b13 = (float).1;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.05/03                           * */
/*  *    TEST TITLE : Error indicator = 203                 * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i1[5], i2[5], i3[5], i4[5], i5[5], i6[5], i7[5], i8[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *), npm3 (
	    integer *, real *, real *, real *), ndst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm (), npm3 (), ndst ();
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
    static integer errind, stpath[2]	/* was [2][1] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_();
#endif /* NO_PROTO */

/*   clipping indicator */
    initgl_("09.02.05/03", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "the specified starting path is not found in CSS",
	     200L, 47L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    setvs_("203", errinf_1.experr, &errinf_1.expsiz, 3L);
    nopst (&c__101);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
    npm3 (&c__1, px, py, pz);
    nclst ();
    setvs_("101,2", stpath, &isiz, 5L);
    riss3_(&c_b10, &c_b10, &c_b10, &c_b13, &c__1, stpath, &c__0, &c__1, &c__1,
	     i1, i2, i3, i4, &c__1, i5, i6, i7, i8, &c__10, &errind, &ival1, 
	    ira210);
    setvs_("102,2", stpath, &isiz, 5L);
    riss3_(&c_b10, &c_b10, &c_b10, &c_b13, &c__1, stpath, &c__0, &c__1, &c__1,
	     i1, i2, i3, i4, &c__1, i5, i6, i7, i8, &c__10, &errind, &ival1, 
	    ira210);
    setvs_("103,1", stpath, &isiz, 5L);
    riss3_(&c_b10, &c_b10, &c_b10, &c_b13, &c__1, stpath, &c__0, &c__1, &c__1,
	     i1, i2, i3, i4, &c__1, i5, i6, i7, i8, &c__10, &errind, &ival1, 
	    ira210);
    ndst (&c__102);
    nopst (&c__102);
    npm (&c__1, px, py);
    nclst ();
    setvs_("101,2", stpath, &isiz, 5L);
    riss_(&c_b10, &c_b10, &c_b13, &c__1, stpath, &c__0, &c__1, &c__1, i1, i2, 
	    i3, i4, &c__1, i5, i6, i7, i8, &c__10, &errind, &ival1, ira210);
    setvs_("102,2", stpath, &isiz, 5L);
    riss_(&c_b10, &c_b10, &c_b13, &c__1, stpath, &c__0, &c__1, &c__1, i1, i2, 
	    i3, i4, &c__1, i5, i6, i7, i8, &c__10, &errind, &ival1, ira210);
    setvs_("103,1", stpath, &isiz, 5L);
    riss_(&c_b10, &c_b10, &c_b13, &c__1, stpath, &c__0, &c__1, &c__1, i1, i2, 
	    i3, i4, &c__1, i5, i6, i7, i8, &c__10, &errind, &ival1, ira210);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

