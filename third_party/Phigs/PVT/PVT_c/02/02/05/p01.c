/* fort/02/02/05/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;
static integer c__200 = 200;
static integer c__9 = 9;
static integer c__8 = 8;
static integer c__7 = 7;
static integer c__300 = 300;
static integer c__0 = 0;
static integer c__12 = 12;
static integer c__11 = 11;
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.05/01                           * */
/*  *    TEST TITLE : Copy all elements from structure      * */
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
    extern /* Subroutine */ int nlb (integer *), fail_(void), ifpf_(logical *)
	    , nsep (integer *), endit_(void), nsedm (integer *), nclst (void),
	     nemst (integer *), nopst (integer *), chkelp_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), fail_(), ifpf_(), nsep (), endit_(), 
	    nsedm (), nclst (), nemst (), nopst (), chkelp_();
#endif /* NO_PROTO */
    static integer elepos;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), ncelst (integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), ncelst (), setmsg_();
    extern logical strcon_();
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* edit mode */
    initgl_("02.02.05/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  create structure strid1: */
    nopst (&c__100);
/*  fill strid1 with elements: */
    nlb (&c__1);
    nlb (&c__2);
    nlb (&c__3);
/*  <close structure> */
    nclst ();
/*  create structure strid2: */
    nopst (&c__200);
/*  fill strid2 with elements: */
    nlb (&c__9);
    nlb (&c__8);
    nlb (&c__7);
/*  <close structure> */
    nclst ();
/*  <open structure> for strid1 */
    nopst (&c__100);
    elepos = 2;
#ifndef NO_PROTO
    setmsg_("4", "If the specified structure in <copy all elements from stru"
	    "cture> is nonexistent, no action should take place.", 1L, 109L);
#else /* NO_PROTO */
    setmsg_("4", "If the specified structure in <copy all elements from stru\
cture> is nonexistent, no action should take place.", 1L, 109L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <copy all elements from structure> with strid3 */
    ncelst (&c__300);
    if (strcon_(&c__100, "67,1,67,2,67,3", 14L)) {
/* OK so far */
	chkelp_(&c__2);
    } else {
	fail_();
    }
/*  Use <empty structure> to create structure strid3 */
    nemst (&c__300);
    elepos = 0;
#ifndef NO_PROTO
    setmsg_("4", "If the specified structure in <copy all elements from stru"
	    "cture> is empty, no action should take place.", 1L, 103L);
#else /* NO_PROTO */
    setmsg_("4", "If the specified structure in <copy all elements from stru\
cture> is empty, no action should take place.", 1L, 103L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <copy all elements from structure> with strid3 */
    ncelst (&c__300);
    if (strcon_(&c__100, "67,1,67,2,67,3", 14L)) {
/* OK so far */
	chkelp_(&c__0);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("1", "<Copy all elements from structure> should copy all element"
	    "s of a specified structure into an open structure after the elem"
	    "ent pointer when the element pointer is positioned at the beginn"
	    "ing of the structure.", 1L, 207L);
#else /* NO_PROTO */
    setmsg_("1", "<Copy all elements from structure> should copy all element\
s of a specified structure into an open structure after the element pointer \
when the element pointer is positioned at the beginning of the structure.", 
	    1L, 207L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <copy all elements from structure> with strid2 */
    ncelst (&c__200);
    L__1 = strcon_(&c__100, "67,9,67,8,67,7,67,1,67,2,67,3", 29L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "After <copy all elements from structure>, the element poin"
	    "ter positioned at the beginning of the structure should be updat"
	    "ed to point to the last element that was copied.", 1L, 170L);
#else /* NO_PROTO */
    setmsg_("3", "After <copy all elements from structure>, the element poin\
ter positioned at the beginning of the structure should be updated to point \
to the last element that was copied.", 1L, 170L);
#endif /* NO_PROTO */
    chkelp_(&c__3);
    elepos = 4;
#ifndef NO_PROTO
    setmsg_("1", "<Copy all elements from structure> should copy all element"
	    "s of a specified structure into an open structure after the elem"
	    "ent pointer when the element pointer is positioned at the middle"
	    " of the structure.", 1L, 204L);
#else /* NO_PROTO */
    setmsg_("1", "<Copy all elements from structure> should copy all element\
s of a specified structure into an open structure after the element pointer \
when the element pointer is positioned at the middle of the structure.", 1L, 
	    204L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <copy all elements from structure> with strid2 */
    ncelst (&c__200);
    L__1 = strcon_(&c__100, "67,9,67,8,67,7,67,1,67,9,67,8,67,7,67,2,67,3", 
	    44L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "After <copy all elements from structure>, the element poin"
	    "ter positioned at the middle of the structure should be updated "
	    "to point to the last element that was copied.", 1L, 167L);
#else /* NO_PROTO */
    setmsg_("3", "After <copy all elements from structure>, the element poin\
ter positioned at the middle of the structure should be updated to point to \
the last element that was copied.", 1L, 167L);
#endif /* NO_PROTO */
    chkelp_(&c__7);
    elepos = 9;
#ifndef NO_PROTO
    setmsg_("1", "<Copy all elements from structure> should copy all element"
	    "s of a specified structure into an open structure after the elem"
	    "ent pointer when the element pointer is positioned at the end of"
	    " the structure.", 1L, 201L);
#else /* NO_PROTO */
    setmsg_("1", "<Copy all elements from structure> should copy all element\
s of a specified structure into an open structure after the element pointer \
when the element pointer is positioned at the end of the structure.", 1L, 
	    201L);
#endif /* NO_PROTO */
/*  <set element pointer> with elepos */
    nsep (&elepos);
/*  <copy all elements from structure> with strid2 */
    ncelst (&c__200);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,9,67,8,67,7,67,1,67,9,67,8,67,7,67,2,67,3,67"
	    ",9,67,8,67,7", 59L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,9,67,8,67,7,67,1,67,9,67,8,67,7,67,2,67,3,67\
,9,67,8,67,7", 59L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "After <copy all elements from structure>, the element poin"
	    "ter positioned at the end of the structure should be updated to "
	    "point to the last element that was copied.", 1L, 164L);
#else /* NO_PROTO */
    setmsg_("3", "After <copy all elements from structure>, the element poin\
ter positioned at the end of the structure should be updated to point to the\
 last element that was copied.", 1L, 164L);
#endif /* NO_PROTO */
    chkelp_(&c__12);
    elepos = 8;
#ifndef NO_PROTO
    setmsg_("1", "<Copy all elements from structure> should insert elements "
	    "even when the edit mode is REPLACE.", 1L, 93L);
#else /* NO_PROTO */
    setmsg_("1", "<Copy all elements from structure> should insert elements \
even when the edit mode is REPLACE.", 1L, 93L);
#endif /* NO_PROTO */
/*  <set edit mode> to REPLACE */
    nsedm (&c__1);
/*  <set element pointer> with elepos */
    nsep (&elepos);
/*  <copy all elements from structure> with strid2 */
    ncelst (&c__200);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,9,67,8,67,7,67,1,67,9,67,8,67,7,67,2,67,9,67"
	    ",8,67,7,67,3,67,9,67,8,67,7", 74L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,9,67,8,67,7,67,1,67,9,67,8,67,7,67,2,67,9,67\
,8,67,7,67,3,67,9,67,8,67,7", 74L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "After <copy all elements from structure>, the element poin"
	    "ter should be updated to point to the last element that was copi"
	    "ed when the edit mode is set to REPLACE.", 1L, 162L);
#else /* NO_PROTO */
    setmsg_("3", "After <copy all elements from structure>, the element poin\
ter should be updated to point to the last element that was copied when the \
edit mode is set to REPLACE.", 1L, 162L);
#endif /* NO_PROTO */
    chkelp_(&c__11);
/*  <close structure> */
    nclst ();
/*  <open structure> for strid2 */
    nopst (&c__200);
    elepos = 2;
#ifndef NO_PROTO
    setmsg_("2", "If the specified structure in <copy all elements from stru"
	    "cture> is the open structure, its contents should be copied into"
	    " itself after the element pointer.", 1L, 156L);
#else /* NO_PROTO */
    setmsg_("2", "If the specified structure in <copy all elements from stru\
cture> is the open structure, its contents should be copied into itself afte\
r the element pointer.", 1L, 156L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <copy all elements from structure> with strid2 */
    ncelst (&c__200);
    L__1 = strcon_(&c__200, "67,9,67,8,67,9,67,8,67,7,67,7", 29L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "After <copy all elements from structure>, the element poin"
	    "ter should be updated to point to the last element that was copi"
	    "ed when the specified structure is the open structure.", 1L, 176L)
	    ;
#else /* NO_PROTO */
    setmsg_("3", "After <copy all elements from structure>, the element poin\
ter should be updated to point to the last element that was copied when the \
specified structure is the open structure.", 1L, 176L);
#endif /* NO_PROTO */
    chkelp_(&c__5);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

