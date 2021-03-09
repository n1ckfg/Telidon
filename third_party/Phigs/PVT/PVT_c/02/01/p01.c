/* fort/02/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.01/01                              * */
/*  *    TEST TITLE : Inquiring about structure identifiers * */
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
    integer i__1;
    logical L__1;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer lasi[20], idum, nstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqsid (integer *, integer *, 
	    integer *, integer *);
    extern logical setis_(integer *, char *, ftnlen);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqsid ();
    extern logical setis_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), csspth_(void), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), csspth_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("02.01/01", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Use <open structure> and <execute structure> to set up */
/*  the CSS as follows: */

/*                   101        106       108 */
/*                  / | \       / */
/*                 /  |  \    1/ */
/*               1/  2|  3\   / */
/*               /    |    \ / */
/*              /     |    107 */
/*             /      | */
/*          102      103 */
/*          | \      / \\ */
/*          |  \   1/   \\ */
/*         1|  2\  /    2\\3 */
/*          |    \/       \\ */
/*          |    104      105 */
/*          |     |      / */
/*          |    1|    1/ */
/*           \    |    / */
/*            \   |   / */
/*             \  |  / */
/*              \ | / */
/*               109 */
/*  common setup routine here */
    csspth_();
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire structure identifiers> should retrieve all iden"
	    "tifiers as created by <open structure> and <execute structure>.", 
	    3L, 119L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire structure identifiers> should retrieve all iden\
tifiers as created by <open structure> and <execute structure>.", 3L, 119L);
#endif /* NO_PROTO */
/* get list of all structure identifiers = lasi */
    nqsid (&c__0, &errind, &nstr, &idum);
    chkinq_("pqsid", &errind, 5L);
/* full list should contain exactly 9 elements */
    if (nstr != 9) {
	fail_();
	goto L100;
    }
/* get entire list */
    i__1 = nstr;
    for (ix = 1; ix <= i__1; ++ix) {
	nqsid (&ix, &errind, &idum, &lasi[ix - 1]);
	chkinq_("pqsid", &errind, 5L);
/* L50: */
    }
/* full list should contain exactly: 101, 102, 103, 104, 105, 106, */
/* 107, 108, 109 */
    L__1 = setis_(lasi, "101,102,103,104,105,106,107,108,109", 35L);
    ifpf_(&L__1);
L100:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

