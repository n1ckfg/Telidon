/* fort/02/01/01/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__100 = 100;
static integer c__0 = 0;
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.01/10                           * */
/*  *    TEST TITLE : Multiple structure creation           * */
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
    static integer i;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer idum1;
    static real rdum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqsid (integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqsid ();
#endif /* NO_PROTO */
    static integer nstid, nidst, strid;
#ifndef NO_PROTO
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nemst (integer *);
#else /* NO_PROTO */
    extern logical seteq_();
    extern /* Subroutine */ int nemst ();
#endif /* NO_PROTO */
    static integer starr[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nexst (integer *), npost (integer *, integer *, real *), nopst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nexst (), npost (), nopst ();
#endif /* NO_PROTO */
    static integer actual[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), ncstid (integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), ncstid (), setmsg_(), xpopph_();
#endif /* NO_PROTO */

/* PHIGS parameter types */
    initgl_("02.01.01/10", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* creation of multiple structures */
#ifndef NO_PROTO
    rdum1 = .02f;
#else /* NO_PROTO */
    rdum1 = (float).02;
#endif /* NO_PROTO */
    strid = 1;
    for (nidst = 1; nidst <= 5; ++nidst) {
	starr[nidst - 1] = strid;
	strid += 3;
/* L100: */
    }
    nemst (starr);
    ncstid (&c__100, &starr[1]);
    npost (&globnu_1.wkid, &starr[2], &rdum1);
    nopst (&starr[3]);
    nexst (&starr[4]);
    setmsg_("9 10", "The CSS should be able to hold multiple structures.", 4L,
	     51L);
/* nstid = number of structure identifiers */
    nqsid (&c__0, &errind, &nstid, &idum1);
    chkinq_("pqsid", &errind, 5L);
    if (nstid == 5) {
	for (i = 1; i <= 5; ++i) {
	    nqsid (&i, &errind, &idum1, &actual[i - 1]);
	    chkinq_("pqsid", &errind, 5L);
/* L200: */
	}
	L__1 = seteq_(&c__5, actual, starr);
	ifpf_(&L__1);
    } else {
	fail_();
    }
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

