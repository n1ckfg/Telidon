/* fort/02/02/04/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__13 = 13;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.04/02                           * */
/*  *    TEST TITLE : Delete element range                  * */
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
	    void), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), ifpf_(), endit_(), nopst ();
#endif /* NO_PROTO */
    static integer elpos1, elpos2;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkelp_(integer *), ndelra (integer *, 
	    integer *), initgl_(char *, ftnlen), setmsg_(char *, char *, 
	    ftnlen, ftnlen);
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkelp_(), ndelra (), initgl_(), setmsg_();
    extern logical strcon_();
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
    initgl_("02.02.04/02", 11L);
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
    nlb (&c__2);
    nlb (&c__1);
    nlb (&c__2);
    nlb (&c__4);
    nlb (&c__3);
    elpos1 = 9;
    elpos2 = 11;
#ifndef NO_PROTO
    setmsg_("3", "<Delete element range> should delete all structure element"
	    "s between and including the lower element position and the highe"
	    "r element position when the lower position is the first paramete"
	    "r.", 1L, 188L);
#else /* NO_PROTO */
    setmsg_("3", "<Delete element range> should delete all structure element\
s between and including the lower element position and the higher element po\
sition when the lower position is the first parameter.", 1L, 188L);
#endif /* NO_PROTO */
/*  <delete element range> with elpos1, elpos2 */
    ndelra (&elpos1, &elpos2);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,6,67,5,67,6,67,10,6"
	    "7,9,67,10,67,2,67,1,67,2,67,4,67,3", 81L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,6,67,5,67,6,67,10,6\
7,9,67,10,67,2,67,1,67,2,67,4,67,3", 81L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
    elpos1 = 16;
    elpos2 = 14;
#ifndef NO_PROTO
    setmsg_("3", "<Delete element range> should delete all structure element"
	    "s between and including the lower element position and the highe"
	    "r element position when the lower position is the second paramet"
	    "er.", 1L, 189L);
#else /* NO_PROTO */
    setmsg_("3", "<Delete element range> should delete all structure element\
s between and including the lower element position and the higher element po\
sition when the lower position is the second parameter.", 1L, 189L);
#endif /* NO_PROTO */
/*  <delete element range> with elpos1, elpos2 */
    ndelra (&elpos1, &elpos2);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,6,67,5,67,6,67,10,6"
	    "7,9,67,10,67,2,67,1", 66L);
    ifpf_(&L__1);
    setmsg_("7", "Following <delete element range>, the element pointer shou"
	    "ld be positioned at the element immediately preceding the group "
	    "of elements deleted at the end of the structure.", 1L, 170L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,6,67,5,67,6,67,10,6\
7,9,67,10,67,2,67,1", 66L);
    ifpf_(&L__1);
    setmsg_("7", "Following <delete element range>, the element pointer shou\
ld be positioned at the element immediately preceding the group of elements \
deleted at the end of the structure.", 1L, 170L);
#endif /* NO_PROTO */
    chkelp_(&c__13);
    elpos1 = 1;
    elpos2 = 3;
#ifndef NO_PROTO
    setmsg_("3", "<Delete element range> should delete all structure element"
	    "s between and including the lower element position and the highe"
	    "r element position when the lower element position is defined as"
	    " the beginning of the structure.", 1L, 218L);
#else /* NO_PROTO */
    setmsg_("3", "<Delete element range> should delete all structure element\
s between and including the lower element position and the higher element po\
sition when the lower element position is defined as the beginning of the st\
ructure.", 1L, 218L);
#endif /* NO_PROTO */
/*  <delete element range> with elpos1, elpos2 */
    ndelra (&elpos1, &elpos2);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,3,67,4,67,6,67,5,67,6,67,10,67,9,67,10,67,2,"
	    "67,1", 51L);
    ifpf_(&L__1);
    setmsg_("7", "Following <delete element range>, the element pointer shou"
	    "ld be positioned at the element immediately preceding the group "
	    "of elements deleted at the beginning of the structure.", 1L, 176L)
	    ;
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,3,67,4,67,6,67,5,67,6,67,10,67,9,67,10,67,2,\
67,1", 51L);
    ifpf_(&L__1);
    setmsg_("7", "Following <delete element range>, the element pointer shou\
ld be positioned at the element immediately preceding the group of elements \
deleted at the beginning of the structure.", 1L, 176L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
    elpos1 = -10;
    elpos2 = 3;
#ifndef NO_PROTO
    setmsg_("3 4", "If <delete element range> is used, and if an element pos"
	    "ition is less than 1, a value of 0 should be used.", 3L, 106L);
#else /* NO_PROTO */
    setmsg_("3 4", "If <delete element range> is used, and if an element pos\
ition is less than 1, a value of 0 should be used.", 3L, 106L);
#endif /* NO_PROTO */
/*  <delete element range> with elpos1, elpos2 */
    ndelra (&elpos1, &elpos2);
    L__1 = strcon_(&c__100, "67,5,67,6,67,10,67,9,67,10,67,2,67,1", 36L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete element range>, the element pointer shou"
	    "ld be positioned at the element immediately preceding the group "
	    "of elements deleted when the element position is less than 1.", 
	    1L, 183L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete element range>, the element pointer shou\
ld be positioned at the element immediately preceding the group of elements \
deleted when the element position is less than 1.", 1L, 183L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
    elpos1 = 5;
    elpos2 = 10;
#ifndef NO_PROTO
    setmsg_("3 4", "If <delete element range> is used, and if an element pos"
	    "ition is greater than the number of elements in the open structu"
	    "re, a value pointing to the last element in the structure should"
	    " be used.", 3L, 193L);
#else /* NO_PROTO */
    setmsg_("3 4", "If <delete element range> is used, and if an element pos\
ition is greater than the number of elements in the open structure, a value \
pointing to the last element in the structure should be used.", 3L, 193L);
#endif /* NO_PROTO */
/*  <delete element range> with elpos1, elpos2 */
    ndelra (&elpos1, &elpos2);
    L__1 = strcon_(&c__100, "67,5,67,6,67,10,67,9", 20L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete element range>, the element pointer shou"
	    "ld be positioned at the element immediately preceding the group "
	    "of elements deleted when the element position is greater than th"
	    "e number of elements in the open structure.", 1L, 229L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete element range>, the element pointer shou\
ld be positioned at the element immediately preceding the group of elements \
deleted when the element position is greater than the number of elements in \
the open structure.", 1L, 229L);
#endif /* NO_PROTO */
    chkelp_(&c__4);
    elpos1 = -10;
    elpos2 = 15;
#ifndef NO_PROTO
    setmsg_("3 4", "If <delete element range> is used, and if an element pos"
	    "ition is less than 1, a value of 0 should be used; if an element"
	    " position is greater than the number of elements in the open str"
	    "ucture, a value pointing to the last element in the structure sh"
	    "ould be used.", 3L, 261L);
#else /* NO_PROTO */
    setmsg_("3 4", "If <delete element range> is used, and if an element pos\
ition is less than 1, a value of 0 should be used; if an element position is\
 greater than the number of elements in the open structure, a value pointing\
 to the last element in the structure should be used.", 3L, 261L);
#endif /* NO_PROTO */
/*  <delete element range> with elpos1, elpos2 */
    ndelra (&elpos1, &elpos2);
    L__1 = strcon_(&c__100, " ", 1L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete element range>, the element pointer shou"
	    "ld be positioned at the element immediately preceding the group "
	    "of elements deleted when the element positions are less than 1 a"
	    "nd greater than the number of elements in the open structure.", 
	    1L, 247L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete element range>, the element pointer shou\
ld be positioned at the element immediately preceding the group of elements \
deleted when the element positions are less than 1 and greater than the numb\
er of elements in the open structure.", 1L, 247L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

