/* fort/02/02/04/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.02.04/05                           * */
/*  *    TEST TITLE : Deleting structure elements in        * */
/*  *                 REPLACE edit mode                     * */
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
	    , nsep (integer *), endit_(void), nsedm (integer *), nemst (
	    integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), ndel (), ifpf_(), nsep (), endit_(), 
	    nsedm (), nemst (), nopst ();
#endif /* NO_PROTO */
    static integer elpos1, elpos2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *), chkelp_(
	    integer *), ndelra (integer *, integer *), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb (), chkelp_(), ndelra (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, elepos;
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
/* structure status indicator */
/* edit mode */
    initgl_("02.02.04/05", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  <open structure> for strid */
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
/*  <set edit mode> to REPLACE */
    nsedm (&c__1);
    elepos = 9;
#ifndef NO_PROTO
    setmsg_("1", "When the edit mode is REPLACE, <delete element> should del"
	    "ete the element pointed to by the element pointer.", 1L, 108L);
#else /* NO_PROTO */
    setmsg_("1", "When the edit mode is REPLACE, <delete element> should del\
ete the element pointed to by the element pointer.", 1L, 108L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos and <delete element> */
    nsep (&elepos);
    ndel ();
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67, 1,67,2,67,4,67,3,67, 4,67,6,67, 5,67,6,67,7"
	    ",67,8,67,10,67,9,67,10,67,2,67,1,67,2,67, 4", 90L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67, 1,67,2,67,4,67,3,67, 4,67,6,67, 5,67,6,67,7\
,67,8,67,10,67,9,67,10,67,2,67,1,67,2,67, 4", 90L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "When the edit mode is REPLACE, following <delete element>,"
	    " the element pointer should be positioned at the element immedia"
	    "tely preceding the deleted structure element.", 1L, 167L);
#else /* NO_PROTO */
    setmsg_("7", "When the edit mode is REPLACE, following <delete element>,\
 the element pointer should be positioned at the element immediately precedi\
ng the deleted structure element.", 1L, 167L);
#endif /* NO_PROTO */
    chkelp_(&c__8);
    elpos1 = 2;
    elpos2 = 6;
#ifndef NO_PROTO
    setmsg_("3", "When the edit mode is REPLACE, <delete element range> shou"
	    "ld delete all structure elements between and including the lower"
	    " element position and the higher element position.", 1L, 172L);
#else /* NO_PROTO */
    setmsg_("3", "When the edit mode is REPLACE, <delete element range> shou\
ld delete all structure elements between and including the lower element pos\
ition and the higher element position.", 1L, 172L);
#endif /* NO_PROTO */
/*  <delete element range> elpos1, elpos2 */
    ndelra (&elpos1, &elpos2);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67,1,67, 5,67,6,67,7,67,8,67,10,67,9,67,10,67,2"
	    ",67,1,67,2,67, 4", 63L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67,1,67, 5,67,6,67,7,67,8,67,10,67,9,67,10,67,2\
,67,1,67,2,67, 4", 63L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "When the edit mode is REPLACE, following <delete element r"
	    "ange>, the element pointer should be positioned at the element i"
	    "mmediately preceding the deleted group elements.", 1L, 170L);
#else /* NO_PROTO */
    setmsg_("7", "When the edit mode is REPLACE, following <delete element r\
ange>, the element pointer should be positioned at the element immediately p\
receding the deleted group elements.", 1L, 170L);
#endif /* NO_PROTO */
    chkelp_(&c__1);
    elepos = 0;
#ifndef NO_PROTO
    setmsg_("5 6", "When the edit mode is REPLACE, <delete elements between "
	    "labels> should delete elements between but not including the occ"
	    "urences of two specified labels.", 3L, 152L);
#else /* NO_PROTO */
    setmsg_("5 6", "When the edit mode is REPLACE, <delete elements between \
labels> should delete elements between but not including the occurences of t\
wo specified labels.", 3L, 152L);
#endif /* NO_PROTO */
/*  <set element pointer> to elepos and */
/*  <delete elements between labels> with labl10, labl10 */
    nsep (&elepos);
    ndellb (&c__10, &c__10);
#ifndef NO_PROTO
    L__1 = strcon_(&c__100, "67, 1,67,5,67,6,67,7,67,8,67,10,67,10,67,2,67,1"
	    ",67,2,67,4", 57L);
#else /* NO_PROTO */
    L__1 = strcon_(&c__100, "67, 1,67,5,67,6,67,7,67,8,67,10,67,10,67,2,67,1\
,67,2,67,4", 57L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("7", "When the edit mode is REPLACE, following <delete elements "
	    "between labels>, the element pointer should be positioned at the"
	    " element immediately preceding the deleted group elements.", 1L, 
	    180L);
#else /* NO_PROTO */
    setmsg_("7", "When the edit mode is REPLACE, following <delete elements \
between labels>, the element pointer should be positioned at the element imm\
ediately preceding the deleted group elements.", 1L, 180L);
#endif /* NO_PROTO */
    chkelp_(&c__6);
#ifndef NO_PROTO
    setmsg_("8 9", "When the edit mode is REPLACE, <empty structure> should "
	    "delete all the elements of a specified structure, but the struct"
	    "ure itself should still exist.", 3L, 150L);
#else /* NO_PROTO */
    setmsg_("8 9", "When the edit mode is REPLACE, <empty structure> should \
delete all the elements of a specified structure, but the structure itself s\
hould still exist.", 3L, 150L);
#endif /* NO_PROTO */
/*  <empty structure> with strid */
    nemst (&c__100);
/*  <inquire structure status> with strid to set ststin */
    nqstst (&c__100, &errind, &ststin);
    chkinq_("pqstst", &errind, 6L);
    L__1 = ststin == 1;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

