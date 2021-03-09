/* fort/09/02/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c_n1 = -1;
static integer c__1 = 1;
static integer c_n100 = -100;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.03/01                           * */
/*  *    TEST TITLE : Error indicator = 100                 * */
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
    extern /* Subroutine */ int rqir_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqir_();
#endif /* NO_PROTO */
    static integer ival1, ival2, ival3;
    static real rval1, rval2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), rqedr_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nqwkc (integer *, integer *, integer *, integer *), rqpir_(
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nopwk (integer *, integer *, integer *), rqplr_(integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    rqpmr_(integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *), setvs_(char *, integer *, integer *, ftnlen), 
	    rqtxr_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), rqedr_(), nqwkc (), rqpir_(), 
	    nopwk (), rqplr_(), rqpmr_(), setvs_(), rqtxr_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int rqpedr_(integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), xpopph_(integer *, 
	    integer *), rqpplr_(integer *, integer *, integer *, integer *, 
	    real *, integer *), rqppmr_(integer *, integer *, integer *, 
	    integer *, real *, integer *), rqptxr_(integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqpedr_(), xpopph_(), rqpplr_(), rqppmr_(), 
	    rqptxr_();
#endif /* NO_PROTO */

    initgl_("09.02.03/01", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "the bundle index value is less than one", 200L, 
	    39L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    setvs_("100", errinf_1.experr, &errinf_1.expsiz, 3L);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &globnu_1.conid, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    rqplr_(&globnu_1.wkid, &c__0, &c__0, &errind, &ival1, &rval1, &ival2);
    rqpmr_(&globnu_1.wkid, &c_n1, &c__1, &errind, &ival1, &rval1, &ival2);
    rqtxr_(&globnu_1.wkid, &c_n100, &c__0, &errind, &ival1, &ival2, &rval1, &
	    rval2, &ival3);
    rqir_(&globnu_1.wkid, &c__0, &c__1, &errind, &ival1, &ival2, &ival3);
    rqedr_(&globnu_1.wkid, &c_n1, &c__0, &errind, &ival1, &ival2, &rval1, &
	    ival3);
    rqpplr_(&specwt, &c_n100, &errind, &ival1, &rval1, &ival2);
    rqppmr_(&specwt, &c__0, &errind, &ival1, &rval1, &ival2);
    rqptxr_(&specwt, &c_n1, &errind, &ival1, &ival2, &rval1, &rval2, &ival3);
    rqpir_(&specwt, &c_n100, &errind, &ival1, &ival2, &ival3);
    rqpedr_(&specwt, &c__0, &errind, &ival1, &ival2, &rval1, &ival3);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

