/* fort/09/02/05/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__100 = 100;
static integer c__2 = 2;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.05/02                           * */
/*  *    TEST TITLE : Error indicator = 202                 * */
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
    static real px[2] = { 0.f,1.f };
    static real py[2] = { 0.f,1.f };
#else /* NO_PROTO */
    static real px[2] = { (float)0.,(float)1. };
    static real py[2] = { (float)0.,(float)1. };
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static real ra10[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer ira10[10];
    static char str10[80*10];
    static integer ival1, ival2, ival3, ival4;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), rqeco_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *, integer *, char *, ftnlen), nclst (
	    void), rqets_(integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *), setvs_(char *, integer *, integer *, 
	    ftnlen), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), rqeco_(), nclst (), rqets_(), 
	    setvs_(), nopst ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("09.02.05/02", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "the specified element does not exist", 200L, 36L)
	    ;
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    setvs_("202", errinf_1.experr, &errinf_1.expsiz, 3L);
    nopst (&c__100);
    npl (&c__2, px, py);
    nclst ();
    rqets_(&c__100, &c__2, &errind, &ival1, &ival2, &ival3, &ival4);
    rqeco_(&c__100, &c__2, &c__10, &c__10, &c__10, &errind, &ival1, ira10, &
	    ival2, ra10, &ival3, ira10, str10, 80L);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

