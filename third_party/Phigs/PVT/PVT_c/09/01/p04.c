/* fort/09/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.01/04                              * */
/*  *    TEST TITLE : Default error handling with error     * */
/*  *                 mode OFF                              * */
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
    static integer n;
    static real pxa[2], pya[2], pza[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), rpl3_(
	    integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), rpl3_();
#endif /* NO_PROTO */
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), setvs_(char *, integer *, 
	    integer *, ftnlen), enderr_(void), initgl_(char *, ftnlen), 
	    esetup_(integer *), nserhm (integer *), setrvs_(char *, real *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), setvs_(), enderr_(), initgl_(), 
	    esetup_(), nserhm (), setrvs_();
#endif /* NO_PROTO */

    initgl_("09.01/04", 8L);
    s_copy(errchr_1.errsrs, "1 4 10", 40L, 6L);
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "If error handling mode is OFF, and no structure"
	    " is open, then <polyline> should not write any error message to "
	    "error file.", 200L, 122L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "If error handling mode is OFF, and no structure\
 is open, then <polyline> should not write any error message to error file.", 
	    200L, 122L);
#endif /* NO_PROTO */
    setvs_("5", errinf_1.experr, &errinf_1.expsiz, 1L);
    esetup_(&c__5);
    setrvs_("0.,0.5", pxa, &isiz, 6L);
    setrvs_("0.,0.5", pya, &isiz, 6L);
    n = 2;
    nserhm (&c__0);
    npl (&n, pxa, pya);
    nserhm (&c__1);
    rpl3_(&n, pxa, pya, pza);
    enderr_();
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

