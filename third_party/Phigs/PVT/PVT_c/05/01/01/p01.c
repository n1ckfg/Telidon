/* fort/05/01/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.01.01/01                           * */
/*  *    TEST TITLE : Initial state of workstations         * */
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
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer wksval;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqopwk (
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqopwk ();
#endif /* NO_PROTO */
    static integer numopw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkst ();
#endif /* NO_PROTO */

/* workstation state */
    initgl_("05.01.01/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    numopw = -6;
/*  <Inquire set of open workstations> to determine */
/*     numopw = number of open workstation */
    nqopwk (&c__0, &errind, &numopw, &idum1);
    chkinq_("pqopwk", &errind, 6L);
    wksval = -6;
/*  <Inquire workstation state value> to determine */
/*     wksval = workstation state value */
    nqwkst (&wksval);
#ifndef NO_PROTO
    setmsg_("1 7", "Immediately after <open phigs>, and until the first invo"
	    "cation of <open workstation>, the set of open workstations shoul"
	    "d be empty.", 3L, 131L);
#else /* NO_PROTO */
    setmsg_("1 7", "Immediately after <open phigs>, and until the first invo\
cation of <open workstation>, the set of open workstations should be empty.", 
	    3L, 131L);
#endif /* NO_PROTO */
    L__1 = numopw == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 3 4", "Immediately after <open phigs> and until the first inv"
	    "ocation of <open workstation>, the workstation state should be W"
	    "SCL.", 5L, 122L);
#else /* NO_PROTO */
    setmsg_("2 3 4", "Immediately after <open phigs> and until the first inv\
ocation of <open workstation>, the workstation state should be WSCL.", 5L, 
	    122L);
#endif /* NO_PROTO */
    L__1 = wksval == 0;
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

