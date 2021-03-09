/* fort/09/02/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.01/03                           * */
/*  *    TEST TITLE : Error indicator = 5                   * */
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
    static integer ia10[10], ib10[10];
    static real ra10[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int rqep_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rqep_();
#endif /* NO_PROTO */
    static char str10[45*10];
    static integer ival1, ival2, ival3, ival4;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), setvs_(char *, integer *, 
	    integer *, ftnlen), rqceco_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), setvs_(), rqceco_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), rqcets_(integer *, 
	    integer *, integer *, integer *, integer *), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), rqcets_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("09.02.01/03", 11L);
    s_copy(errchr_1.curcon, "PHIGS is closed", 200L, 15L);
    setvs_("5", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    rqep_(&errind, &ival1);
    rqcets_(&errind, &ival1, &ival2, &ival3, &ival4);
    rqceco_(&c__10, &c__10, &c__10, &errind, &ival1, ia10, &ival2, ra10, &
	    ival3, ib10, str10, 45L);
    s_copy(errchr_1.curcon, "PHIGS is open but no structure is open", 200L, 
	    38L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    rqep_(&errind, &ival1);
    rqcets_(&errind, &ival1, &ival2, &ival3, &ival4);
    rqceco_(&c__10, &c__10, &c__10, &errind, &ival1, ia10, &ival2, ra10, &
	    ival3, ib10, str10, 45L);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

