/* fort/02/02/04/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.04/03                           * */
/*  *    TEST TITLE : Delete elements between labels        * */
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
	    integer *), endit_(void), nopst (integer *), ndellb (integer *, 
	    integer *), chkelp_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), ifpf_(), nsep (), endit_(), nopst (), 
	    ndellb (), chkelp_();
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
    initgl_("02.02.04/03", 11L);
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
    nlb (&c__7);
    nlb (&c__8);
    nlb (&c__10);
    nlb (&c__9);
    nlb (&c__10);
    elepos = 6;
#ifndef NO_PROTO
    setmsg_("5 6", "<Delete elements between labels> should delete elements "
	    "between but not including the occurrences of two specified label"
	    "s when the element pointer is not pointing to a specified label.",
	     3L, 184L);
#else /* NO_PROTO */
    setmsg_("5 6", "<Delete elements between labels> should delete elements \
between but not including the occurrences of two specified labels when the e\
lement pointer is not pointing to a specified label.", 3L, 184L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <delete elements between labels> with labl5, labl8 */
    ndellb (&c__5, &c__8);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,6,67,5,67,8,67,7,67"
	    ",7,67,8,67,10,67,9,67,10", 71L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,6,67,5,67,8,67,7,67\
,7,67,8,67,10,67,9,67,10", 71L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete elements between labels>, the element po"
	    "inter should be positioned at the element immediately preceding "
	    "the deleted group elements (when the element pointer was not poi"
	    "nting to a specified label).", 1L, 214L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete elements between labels>, the element po\
inter should be positioned at the element immediately preceding the deleted \
group elements (when the element pointer was not pointing to a specified lab\
el).", 1L, 214L);
#endif /* NO_PROTO */
    chkelp_(&c__7);
    elepos = 3;
#ifndef NO_PROTO
    setmsg_("5 6", "<Delete elements between labels> should delete elements "
	    "between but not including the occurrences of two specified label"
	    "s when the element pointer is currently pointing to a specified "
	    "label.", 3L, 190L);
#else /* NO_PROTO */
    setmsg_("5 6", "<Delete elements between labels> should delete elements \
between but not including the occurrences of two specified labels when the e\
lement pointer is currently pointing to a specified label.", 3L, 190L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos */
    nsep (&elepos);
/*  <delete elements between labels> with labl4, labl5 */
    ndellb (&c__4, &c__5);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,5,67,8,67,7,67,7,67"
	    ",8,67,10,67,9,67,10", 66L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,5,67,8,67,7,67,7,67\
,8,67,10,67,9,67,10", 66L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete elements between labels>, the element po"
	    "inter should be positioned at the element immediately preceding "
	    "the deleted group elements (when the element pointer was pointin"
	    "g to a specified label).", 1L, 210L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete elements between labels>, the element po\
inter should be positioned at the element immediately preceding the deleted \
group elements (when the element pointer was pointing to a specified label).",
	     1L, 210L);
#endif /* NO_PROTO */
    chkelp_(&c__5);
    elepos = 1;
#ifndef NO_PROTO
    setmsg_("5 6", "<Delete elements between labels> should delete elements "
	    "between but not including the successive occurrences of two labe"
	    "ls with the same value.", 3L, 143L);
#else /* NO_PROTO */
    setmsg_("5 6", "<Delete elements between labels> should delete elements \
between but not including the successive occurrences of two labels with the \
same value.", 3L, 143L);
#endif /* NO_PROTO */
    nsep (&elepos);
    ndellb (&c__8, &c__8);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,5,67,8,67,8,67,10,6"
	    "7,9,67,10", 56L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,5,67,8,67,8,67,10,6\
7,9,67,10", 56L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete elements between labels>, the element po"
	    "inter should be positioned at the element immediately preceding "
	    "the deleted group elements (when both labels had the same value)."
	    , 1L, 187L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete elements between labels>, the element po\
inter should be positioned at the element immediately preceding the deleted \
group elements (when both labels had the same value).", 1L, 187L);
#endif /* NO_PROTO */
    chkelp_(&c__7);
    elepos = 0;
#ifndef NO_PROTO
    setmsg_("5 6", "<Delete elements between labels> should delete no elemen"
	    "ts if the two labels are adjacent.", 3L, 90L);
#else /* NO_PROTO */
    setmsg_("5 6", "<Delete elements between labels> should delete no elemen\
ts if the two labels are adjacent.", 3L, 90L);
#endif /* NO_PROTO */
    nsep (&elepos);
    ndellb (&c__4, &c__3);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,5,67,8,67,8,67,10,6"
	    "7,9,67,10", 56L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,1,67,2,67,4,67,3,67,4,67,5,67,8,67,8,67,10,6\
7,9,67,10", 56L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "Following <delete elements between labels>, the element po"
	    "inter should be positioned at the element immediately preceding "
	    "the deleted group elements (when the labels were adjacent).", 1L, 
	    181L);
#else /* NO_PROTO */
    setmsg_("7", "Following <delete elements between labels>, the element po\
inter should be positioned at the element immediately preceding the deleted \
group elements (when the labels were adjacent).", 1L, 181L);
#endif /* NO_PROTO */
    chkelp_(&c__3);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

