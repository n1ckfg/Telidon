/* fort/09/02/09/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b6 = .5f;
#else /* NO_PROTO */
static real c_b6 = (float).5;
#endif /* NO_PROTO */
static integer c__12 = 12;
static integer c__0 = 0;
static integer c__14 = 14;
static integer c__18 = 18;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.09/01                           * */
/*  *    TEST TITLE : Error indicator = 404                 * */
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
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static integer arid, arnm, ival1, ival2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nclst (void), rqcst_(integer *, 
	    integer *, integer *, integer *, integer *), setvs_(char *, 
	    integer *, integer *, ftnlen), nopst (integer *), nclarf (integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nclst (), rqcst_(), setvs_(), 
	    nopst (), nclarf ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *), 
	    noparf (integer *, integer *), narast (integer *), rqcstn_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), avarnm_(), noparf (), narast (), 
	    rqcstn_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("09.02.09/01", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "the specified archive file is not open", 200L, 
	    38L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    setvs_("404", errinf_1.experr, &errinf_1.expsiz, 3L);
    avarnm_(&arnm);
    arid = 11;
    noparf (&arid, &arnm);
    nopst (&c__100);
    ntx (&c_b6, &c_b6, "TEXT", 4L);
    nclst ();
    narast (&arid);
    rqcst_(&c__12, &c__0, &errind, &ival1, &ival2);
    rqcstn_(&c__14, &c__100, &c__0, &c__0, &errind, &ival1, &ival2);
    rqcstn_(&c__18, &c__100, &c__1, &c__0, &errind, &ival1, &ival2);
    nclarf (&arid);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

