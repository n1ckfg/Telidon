/* fort/02/02/04/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__4 = 4;
static integer c__3 = 3;
static integer c__6 = 6;
static integer c__5 = 5;
static integer c__8 = 8;
static integer c__7 = 7;
static integer c__10 = 10;
static integer c__110 = 110;
static integer c__90 = 90;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.04/04                           * */
/*  *    TEST TITLE : Empty structure                       * */
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
    extern /* Subroutine */ int nlb (integer *), ifpf_(logical *), endit_(
	    void), nclst (void), nemst (integer *), nexst (integer *), nopst (
	    integer *), chkelp_(integer *), chkinq_(char *, integer *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), ifpf_(), endit_(), nclst (), nemst (),
	     nexst (), nopst (), chkelp_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
    extern logical strcon_();
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer ststin;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
    initgl_("02.02.04/04", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  <open structure> with stridc */
    nopst (&c__100);
/*  fill structure with elements: */
    nlb (&c__1);
    nlb (&c__2);
    nlb (&c__4);
    nlb (&c__3);
    nlb (&c__4);
    nlb (&c__6);
    nlb (&c__5);
    nlb (&c__6);
    nlb (&c__8);
    nlb (&c__7);
    nlb (&c__8);
    nlb (&c__10);
/*  <close structure> */
    nclst ();
/*  <open structure> with strido */
    nopst (&c__110);
/*  fill structure with elements: */
    nlb (&c__1);
    nlb (&c__2);
    nlb (&c__4);
    nlb (&c__3);
    nlb (&c__4);
    nlb (&c__6);
    nlb (&c__5);
    nlb (&c__6);
    nlb (&c__8);
    nlb (&c__7);
    nlb (&c__8);
    nlb (&c__10);
/*  <close structure> */
    nclst ();
/*  create structure network: */
/*            90 */
/*           /  \ */
/*          /    \ */
/*        100   110 */
/*  <open structure> with strid */
    nopst (&c__90);
/*  execute structure strido, stridc into strid: */
    nexst (&c__100);
    nexst (&c__110);
/*  <close structure> */
    nclst ();
#ifndef NO_PROTO
    setmsg_("8 9", "<Empty structure> should delete all the elements of a sp"
	    "ecified closed structure, but the structure itself should still "
	    "exist.", 3L, 126L);
#else /* NO_PROTO */
    setmsg_("8 9", "<Empty structure> should delete all the elements of a sp\
ecified closed structure, but the structure itself should still exist.", 3L, 
	    126L);
#endif /* NO_PROTO */
/*  <empty structure> with stridc */
    nemst (&c__100);
/*  <inquire structure status> with stridc to set ststin */
    nqstst (&c__100, &errind, &ststin);
    chkinq_("pqstst", &errind, 6L);
    L__1 = ststin == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10", "After using <empty structure> on a specified closed struc"
	    "ture, references to the now empty closed structure should remain"
	    " intact.", 2L, 129L);
#else /* NO_PROTO */
    setmsg_("10", "After using <empty structure> on a specified closed struc\
ture, references to the now empty closed structure should remain intact.", 2L,
	     129L);
#endif /* NO_PROTO */
    L__1 = strcon_(&c__90, "66,100,66,110", 13L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("8 9", "<Empty structure> should delete all the elements of a sp"
	    "ecified open structure, but the structure itself should still ex"
	    "ist.", 3L, 124L);
#else /* NO_PROTO */
    setmsg_("8 9", "<Empty structure> should delete all the elements of a sp\
ecified open structure, but the structure itself should still exist.", 3L, 
	    124L);
#endif /* NO_PROTO */
/*  <open structure> with strido */
    nopst (&c__110);
/*  <empty structure> with strido */
    nemst (&c__110);
/*  <inquire structure status> with strido to set ststin */
    nqstst (&c__110, &errind, &ststin);
    chkinq_("pqstst", &errind, 6L);
    L__1 = ststin == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10", "After using <empty structure> on a specified open structu"
	    "re, references to the now empty open structure should remain int"
	    "act.", 2L, 125L);
#else /* NO_PROTO */
    setmsg_("10", "After using <empty structure> on a specified open structu\
re, references to the now empty open structure should remain intact.", 2L, 
	    125L);
#endif /* NO_PROTO */
    L__1 = strcon_(&c__90, "66,100,66,110", 13L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("11", "If <empty structure> is used on a specified open structur"
	    "e, the element pointer should be set to 0.", 2L, 99L);
#else /* NO_PROTO */
    setmsg_("11", "If <empty structure> is used on a specified open structur\
e, the element pointer should be set to 0.", 2L, 99L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

