/* fort/09/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.01/02                              * */
/*  *    TEST TITLE : User error handling capabilities      * */
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
    /* System generated locals */
    logical L__1;

    /* Local variables */
    static integer n;
    static real pxa[2], pya[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ifpf_(
	    logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ifpf_();
#endif /* NO_PROTO */
    static integer isiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), initgl_(char *, ftnlen), 
	    esetup_(integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    nserhm (integer *), errctl_(logical *), setrvs_(char *, real *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), initgl_(), esetup_(), setmsg_(), 
	    nserhm (), errctl_(), setrvs_();
#endif /* NO_PROTO */

/* PHIGS function names (for those functions which signal error) */
/* off/on switch for edge flag and error handling mode */
    initgl_("09.01/02", 8L);
    esetup_(&c__1);
    setrvs_("0.,0.5", pxa, &isiz, 6L);
    setrvs_("0.,0.5", pya, &isiz, 6L);
    n = 2;
#ifndef NO_PROTO
    setmsg_("1 5 7", "If error handling mode is ON, and no structure is open"
	    ", then <polyline> should return error number, function identifie"
	    "r, and error file to the user defined error handler.", 5L, 170L);
#else /* NO_PROTO */
    setmsg_("1 5 7", "If error handling mode is ON, and no structure is open\
, then <polyline> should return error number, function identifier, and error\
 file to the user defined error handler.", 5L, 170L);
#endif /* NO_PROTO */
    nserhm (&c__1);
    errinf_1.errcom = 999;
    errinf_1.funcom = 999;
    errinf_1.filcom = 999;
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    npl (&n, pxa, pya);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    L__1 = errinf_1.errcom == 5 && errinf_1.funcom == 9 && errinf_1.filcom == 
	    globnu_1.errfil;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 10", "If error handling mode is OFF, and no structure is open"
	    ", then <polyline> should not return error number, function ident"
	    "ifier and error file to the user defined error handler.", 4L, 
	    174L);
#else /* NO_PROTO */
    setmsg_("1 10", "If error handling mode is OFF, and no structure is open\
, then <polyline> should not return error number, function identifier and er\
ror file to the user defined error handler.", 4L, 174L);
#endif /* NO_PROTO */
    nserhm (&c__0);
    errinf_1.errcom = 999;
    errinf_1.funcom = 999;
    errinf_1.filcom = 999;
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    npl (&c__2, pxa, pya);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    L__1 = errinf_1.errcom == 999 && errinf_1.funcom == 999 && 
	    errinf_1.filcom == 999;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

