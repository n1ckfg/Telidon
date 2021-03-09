/* fort/09/01/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__5 = 5;
static integer c__0 = 0;
static integer c__59 = 59;
static integer c__113 = 113;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.01/05                              * */
/*  *    TEST TITLE : Error logging function for default    * */
/*  *                 error handling                        * */
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
    extern /* Subroutine */ int endit_(void), echkz_(integer *), setvs_(char *
	    , integer *, integer *, ftnlen), enderr_(void), initgl_(char *, 
	    ftnlen), esetup_(integer *), nserhm (integer *), nerlog (integer *
	    , integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), echkz_(), setvs_(), enderr_(), 
	    initgl_(), esetup_(), nserhm (), nerlog ();
#endif /* NO_PROTO */

/* off/on switch for edge flag and error handling mode */
    initgl_("09.01/05", 8L);
    s_copy(errchr_1.errsrs, "9", 40L, 1L);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "<Error logging> should write the specified erro"
	    "r message on the error file.", 200L, 75L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "<Error logging> should write the specified erro\
r message on the error file.", 200L, 75L);
#endif /* NO_PROTO */
/*  expected error */
    setvs_("59", errinf_1.experr, &errinf_1.expsiz, 2L);
    esetup_(&c__5);
    nserhm (&c__0);
/*  simulate error #59 for <unpost all structures> */
    nerlog (&c__59, &c__113, &globnu_1.errfil);
/*  expected function */
    echkz_(&c__113);
    enderr_();
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

