/* fort/09/02/05/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__10 = 10;
static integer c_n5 = -5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.05/05                           * */
/*  *    TEST TITLE : Error indicator = 207                 * */
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
    static real px[1] = { 2.f };
    static real py[1] = { 2.f };
#else /* NO_PROTO */
    static real px[1] = { (float)2. };
    static real py[1] = { (float)2. };
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static integer ira210[20]	/* was [2][10] */, ival1, ival2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), rqpde_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), rqpan_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nclst (
	    void), nexst (integer *), setvs_(char *, integer *, integer *, 
	    ftnlen), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), rqpde_(), rqpan_(), nclst (), 
	    nexst (), setvs_(), nopst ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_();
#endif /* NO_PROTO */

/*  path order */
    initgl_("09.02.05/05", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "the specified path depth is less than zero", 
	    200L, 42L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    setvs_("207", errinf_1.experr, &errinf_1.expsiz, 3L);
    nopst (&c__101);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
    npm (&c__1, px, py);
    nclst ();
    rqpan_(&c__101, &c__0, &c_n1, &c__10, &c__0, &errind, &ival1, &ival2, 
	    ira210);
    rqpde_(&c__101, &c__1, &c_n5, &c__10, &c__0, &errind, &ival1, &ival2, 
	    ira210);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

