/* fort/02/02/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__35 = 35;
static integer c__11 = 11;
static integer c__12 = 12;
static integer c__13 = 13;
static integer c__14 = 14;
static integer c__15 = 15;
static integer c__5 = 5;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__6 = 6;
static integer c__7 = 7;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.03/01                           * */
/*  *    TEST TITLE : Set edit mode to INSERT and           * */
/*  *                 manipulate element pointer            * */
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
    extern /* Subroutine */ int nlb (integer *), ifpf_(logical *), nsep (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), ifpf_(), nsep ();
#endif /* NO_PROTO */
    static integer edmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqedm (integer *, integer *), 
	    nsedm (integer *), nosep (integer *), nopst (integer *), chkelp_(
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqedm (), nsedm (), nosep (), 
	    nopst (), chkelp_();
#endif /* NO_PROTO */
    static integer errind, elepos, elpsof;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nseplb (integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nseplb (), setmsg_();
    extern logical strcon_();
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* edit mode */
    initgl_("02.02.03/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  <open structure> with strid */
    nopst (&c__35);
/*  fill structure with elements: */
    nlb (&c__11);
    nlb (&c__12);
    nlb (&c__13);
    nlb (&c__14);
    nlb (&c__15);
#ifndef NO_PROTO
    setmsg_("5 11", "<Inquire edit mode> should return the current edit mode"
	    " as the default edit mode INSERT.", 4L, 88L);
#else /* NO_PROTO */
    setmsg_("5 11", "<Inquire edit mode> should return the current edit mode\
 as the default edit mode INSERT.", 4L, 88L);
#endif /* NO_PROTO */
    nqedm (&errind, &edmod);
    L__1 = errind == 0 && edmod == 0;
    ifpf_(&L__1);
    elepos = 2;
/*  <set element pointer> to elepos */
    nsep (&elepos);
#ifndef NO_PROTO
    setmsg_("7", "<Set element pointer> should set the element pointer to an"
	    " absolute position.", 1L, 77L);
#else /* NO_PROTO */
    setmsg_("7", "<Set element pointer> should set the element pointer to an\
 absolute position.", 1L, 77L);
#endif /* NO_PROTO */
    chkelp_(&elepos);
    nseplb (&c__15);
#ifndef NO_PROTO
    setmsg_("9", "<Set element pointer at label> should position the element"
	    " pointer at the next occurrence of a specified label, when the c"
	    "urrent element is not that label.", 1L, 155L);
#else /* NO_PROTO */
    setmsg_("9", "<Set element pointer at label> should position the element\
 pointer at the next occurrence of a specified label, when the current eleme\
nt is not that label.", 1L, 155L);
#endif /* NO_PROTO */
    chkelp_(&c__5);
    elpsof = -3;
    nosep (&elpsof);
#ifndef NO_PROTO
    setmsg_("8", "<Offset element pointer> should offset the element pointer"
	    " by a relative position.", 1L, 82L);
#else /* NO_PROTO */
    setmsg_("8", "<Offset element pointer> should offset the element pointer\
 by a relative position.", 1L, 82L);
#endif /* NO_PROTO */
    chkelp_(&c__2);
/*  <set edit mode> to REPLACE to nullify default */
    nsedm (&c__1);
/*  <set edit mode> to INSERT */
    nsedm (&c__0);
#ifndef NO_PROTO
    setmsg_("1 11", "<Inquire edit mode> should return the current edit mode"
	    " as INSERT after an explicit setting.", 4L, 92L);
#else /* NO_PROTO */
    setmsg_("1 11", "<Inquire edit mode> should return the current edit mode\
 as INSERT after an explicit setting.", 4L, 92L);
#endif /* NO_PROTO */
    nqedm (&errind, &edmod);
    L__1 = errind == 0 && edmod == 0;
    ifpf_(&L__1);
/*  <label> with label4 */
    nlb (&c__14);
#ifndef NO_PROTO
    setmsg_("2", "When <set edit mode> is INSERT, new elements should be ins"
	    "erted after the element pointed to by the element pointer.", 1L, 
	    116L);
#else /* NO_PROTO */
    setmsg_("2", "When <set edit mode> is INSERT, new elements should be ins\
erted after the element pointed to by the element pointer.", 1L, 116L);
#endif /* NO_PROTO */
    L__1 = strcon_(&c__35, "67,11,67,12,67,14,67,13,67,14,67,15", 35L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4", "When the edit mode is INSERT, the element pointer should b"
	    "e updated to point to the new element after insertion.", 1L, 112L)
	    ;
#else /* NO_PROTO */
    setmsg_("4", "When the edit mode is INSERT, the element pointer should b\
e updated to point to the new element after insertion.", 1L, 112L);
#endif /* NO_PROTO */
    chkelp_(&c__3);
    elepos = 10;
/*  <set element pointer> to elepos */
    nsep (&elepos);
#ifndef NO_PROTO
    setmsg_("7 10", "If <set element pointer> is used to position the elemen"
	    "t pointer to a position greater than the last element in the ope"
	    "n structure, the element pointer should point to the last elemen"
	    "t.", 4L, 185L);
#else /* NO_PROTO */
    setmsg_("7 10", "If <set element pointer> is used to position the elemen\
t pointer to a position greater than the last element in the open structure,\
 the element pointer should point to the last element.", 4L, 185L);
#endif /* NO_PROTO */
    chkelp_(&c__6);
    elpsof = 1;
/*  <offset element pointer> with elpsof */
    nosep (&elpsof);
#ifndef NO_PROTO
    setmsg_("8 10", "If <offset element pointer> is used to position the ele"
	    "ment pointer to a position greater than the last element in the "
	    "open structure, the element pointer should point to the last ele"
	    "ment.", 4L, 188L);
#else /* NO_PROTO */
    setmsg_("8 10", "If <offset element pointer> is used to position the ele\
ment pointer to a position greater than the last element in the open structu\
re, the element pointer should point to the last element.", 4L, 188L);
#endif /* NO_PROTO */
    chkelp_(&c__6);
    elepos = -3;
/*  <set element pointer> to elepos */
    nsep (&elepos);
#ifndef NO_PROTO
    setmsg_("7 10", "If <set element pointer> is used to position the elemen"
	    "t pointer to a position less than zero, the element pointer shou"
	    "ld point to zero.", 4L, 136L);
#else /* NO_PROTO */
    setmsg_("7 10", "If <set element pointer> is used to position the elemen\
t pointer to a position less than zero, the element pointer should point to \
zero.", 4L, 136L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
    elpsof = -1;
/*  <offset element pointer> with elpsof */
    nosep (&elpsof);
#ifndef NO_PROTO
    setmsg_("8 10", "If <offset element pointer> is used to position the ele"
	    "ment pointer to a position less than zero, the element pointer s"
	    "hould point to zero.", 4L, 139L);
#else /* NO_PROTO */
    setmsg_("8 10", "If <offset element pointer> is used to position the ele\
ment pointer to a position less than zero, the element pointer should point \
to zero.", 4L, 139L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
    nlb (&c__15);
#ifndef NO_PROTO
    setmsg_("6", "If the element pointer is 0, then the new element should b"
	    "e inserted immediately before element 1.", 1L, 98L);
#else /* NO_PROTO */
    setmsg_("6", "If the element pointer is 0, then the new element should b\
e inserted immediately before element 1.", 1L, 98L);
#endif /* NO_PROTO */
    L__1 = strcon_(&c__35, "67,15,67,11,67,12,67,14,67,13,67,14,67,15", 41L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6", "After an insertion of an element at the beginning of a str"
	    "ucture, the element pointer should become 1 and point at the new"
	    " element.", 1L, 131L);
#else /* NO_PROTO */
    setmsg_("6", "After an insertion of an element at the beginning of a str\
ucture, the element pointer should become 1 and point at the new element.", 
	    1L, 131L);
#endif /* NO_PROTO */
    chkelp_(&c__1);
/*  <set element pointer at label> with label5 */
    nseplb (&c__15);
#ifndef NO_PROTO
    setmsg_("9", "If the element pointer is already positioned at a label el"
	    "ement, <set element pointer at label> should position the elemen"
	    "t pointer at the next occurence of a specified label element wit"
	    "hin the open structure.", 1L, 209L);
#else /* NO_PROTO */
    setmsg_("9", "If the element pointer is already positioned at a label el\
ement, <set element pointer at label> should position the element pointer at\
 the next occurence of a specified label element within the open structure.", 
	    1L, 209L);
#endif /* NO_PROTO */
    chkelp_(&c__7);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

