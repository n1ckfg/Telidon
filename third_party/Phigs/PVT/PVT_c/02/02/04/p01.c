/* fort/02/02/04/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__9 = 9;
static integer c__0 = 0;
static integer c__11 = 11;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.04/01                           * */
/*  *    TEST TITLE : Delete element                        * */
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
    extern /* Subroutine */ int nlb (integer *), ndel (void), ifpf_(logical *)
	    , nsep (integer *), endit_(void), nopst (integer *), chkelp_(
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), ndel (), ifpf_(), nsep (), endit_(), 
	    nopst (), chkelp_();
#endif /* NO_PROTO */
    static integer elepos;
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

/*  Declare program-specific variables */
    initgl_("02.02.04/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  <open structure> with strid */
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
    nlb (&c__9);
    nlb (&c__10);
    elepos = 0;
#ifndef NO_PROTO
    setmsg_("2", "If <delete element> is used, and if the element position i"
	    "s zero nothing should be deleted.", 1L, 91L);
#else /* NO_PROTO */
    setmsg_("2", "If <delete element> is used, and if the element position i\
s zero nothing should be deleted.", 1L, 91L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <delete element> */
    ndel ();
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,6,67,5,67,6,67,8,67"
	    ",7,67,8,67,10,67,9,67,10", 71L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,6,67,5,67,6,67,8,67\
,7,67,8,67,10,67,9,67,10", 71L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "If <delete element> is used, and nothing is deleted the el"
	    "ement pointer should be unchanged.", 1L, 92L);
#else /* NO_PROTO */
    setmsg_("7", "If <delete element> is used, and nothing is deleted the el\
ement pointer should be unchanged.", 1L, 92L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
    elepos = 1;
#ifndef NO_PROTO
    setmsg_("1", "<Delete element> should delete a leading structure element"
	    " pointed to by the element pointer.", 1L, 93L);
#else /* NO_PROTO */
    setmsg_("1", "<Delete element> should delete a leading structure element\
 pointed to by the element pointer.", 1L, 93L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <delete element> */
    ndel ();
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,2,67,4,67,3,67,4,67,6,67,5,67,6,67,8,67,7,67"
	    ",8,67,10,67,9,67,10", 66L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,2,67,4,67,3,67,4,67,6,67,5,67,6,67,8,67,7,67\
,8,67,10,67,9,67,10", 66L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete element>, the element pointer should be "
	    "positioned at the element immediately preceding the deleted lead"
	    "ing structure element.", 1L, 144L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete element>, the element pointer should be \
positioned at the element immediately preceding the deleted leading structur\
e element.", 1L, 144L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
    elepos = 3;
#ifndef NO_PROTO
    setmsg_("1", "<Delete element> should delete a middle structure element "
	    "pointed to by the element pointer.", 1L, 92L);
#else /* NO_PROTO */
    setmsg_("1", "<Delete element> should delete a middle structure element \
pointed to by the element pointer.", 1L, 92L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <delete element> */
    ndel ();
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,2,67,4,67,4,67,6,67,5,67,6,67,8,67,7,67,8,67"
	    ",10,67,9,67,10", 61L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,2,67,4,67,4,67,6,67,5,67,6,67,8,67,7,67,8,67\
,10,67,9,67,10", 61L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete element>, the element pointer should be "
	    "positioned at the element immediately preceding the deleted midd"
	    "le structure element.", 1L, 143L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete element>, the element pointer should be \
positioned at the element immediately preceding the deleted middle structure\
 element.", 1L, 143L);
#endif /* NO_PROTO */
    chkelp_(&c__2);
    elepos = 12;
#ifndef NO_PROTO
    setmsg_("1", "<Delete element> should delete a last structure element po"
	    "inted to by the element pointer.", 1L, 90L);
#else /* NO_PROTO */
    setmsg_("1", "<Delete element> should delete a last structure element po\
inted to by the element pointer.", 1L, 90L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <delete element> */
    ndel ();
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,2,67,4,67,4,67,6,67,5,67,6,67,8,67,7,67,8,67"
	    ",10,67,9", 55L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,2,67,4,67,4,67,6,67,5,67,6,67,8,67,7,67,8,67\
,10,67,9", 55L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete element>, the element pointer should be "
	    "positioned at the element immediately preceding the deleted last"
	    " structure element.", 1L, 141L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete element>, the element pointer should be \
positioned at the element immediately preceding the deleted last structure e\
lement.", 1L, 141L);
#endif /* NO_PROTO */
    chkelp_(&c__11);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

