/* fort/09/02/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

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

static integer c__11 = 11;
static integer c__100 = 100;
static integer c__0 = 0;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.01/04                           * */
/*  *    TEST TITLE : Error indicator = 7                   * */
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
    static integer ival1, ival2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), rqcst_(integer *, integer *, 
	    integer *, integer *, integer *), setvs_(char *, integer *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), rqcst_(), setvs_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), rqcstn_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), rqcstn_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("09.02.01/04", 11L);
    s_copy(errchr_1.curcon, "PHIGS is closed", 200L, 15L);
    setvs_("7", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    rqcst_(&c__11, &c__100, &errind, &ival1, &ival2);
    rqcstn_(&c__11, &c__100, &c__0, &c__1, &errind, &ival1, &ival2);
    s_copy(errchr_1.curcon, "PHIGS is open but no archive file is open", 200L,
	     41L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    rqcst_(&c__11, &c__100, &errind, &ival1, &ival2);
    rqcstn_(&c__11, &c__100, &c__0, &c__1, &errind, &ival1, &ival2);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

