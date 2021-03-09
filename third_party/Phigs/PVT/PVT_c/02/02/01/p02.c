/* fort/02/02/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__40 = 40;
static integer c__1 = 1;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.02.01/02                           * */
/*  *    TEST TITLE : Opening and closing a non-empty       * */
/*  *                 existing structure                    * */
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
    extern /* Subroutine */ int nlb (integer *), ifpf_(logical *), nqep (
	    integer *, integer *), nsep (integer *), endit_(void), nclst (
	    void), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), ifpf_(), nqep (), nsep (), endit_(), 
	    nclst (), nopst ();
#endif /* NO_PROTO */
    static integer errind, elepos;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer rstrid;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer ststin;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst ();
#endif /* NO_PROTO */
    static integer opstst;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* open-structure status */
/* structure status indicator */
    initgl_("02.02.01/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  <Open structure> with strid */
    nopst (&c__40);
/*  Fill open structure with elements: */
    nlb (&c__1);
    nlb (&c__2);
/*  <inquire open structure> to set opstst, strid */
#ifndef NO_PROTO
    setmsg_("1 5", "If a non-empty structure is open <inquire open structure"
	    "> should return an OPEN structure status and the structure ident"
	    "ifier of the open structure.", 3L, 148L);
#else /* NO_PROTO */
    setmsg_("1 5", "If a non-empty structure is open <inquire open structure\
> should return an OPEN structure status and the structure identifier of the\
 open structure.", 3L, 148L);
#endif /* NO_PROTO */
    nqopst (&errind, &opstst, &rstrid);
    L__1 = errind == 0 && opstst == 1 && rstrid == 40;
    ifpf_(&L__1);
/*  <inquire structure status> to set ststin */
#ifndef NO_PROTO
    setmsg_("7", "<Inquire structure status> should return the appropriate s"
	    "tructure status as NOTEMPTY for a non-empty structure when the s"
	    "tructure is open.", 1L, 139L);
#else /* NO_PROTO */
    setmsg_("7", "<Inquire structure status> should return the appropriate s\
tructure status as NOTEMPTY for a non-empty structure when the structure is \
open.", 1L, 139L);
#endif /* NO_PROTO */
    nqstst (&c__40, &errind, &ststin);
    L__1 = errind == 0 && ststin == 2;
    ifpf_(&L__1);
/* check that re-opening structure re-sets element pointer */
    nsep (&c__1);
    nclst ();
    nopst (&c__40);
/*  <inquire element pointer> to set elepos */
#ifndef NO_PROTO
    setmsg_("2 8", "<Inquire element pointer> should return the element poin"
	    "ter position as the last element after opening a non-empty struc"
	    "ture.", 3L, 125L);
#else /* NO_PROTO */
    setmsg_("2 8", "<Inquire element pointer> should return the element poin\
ter position as the last element after opening a non-empty structure.", 3L, 
	    125L);
#endif /* NO_PROTO */
    nqep (&errind, &elepos);
    L__1 = errind == 0 && elepos == 2;
    ifpf_(&L__1);
/*  <close structure> */
    nclst ();
/*  <inquire structure status> to set ststin */
#ifndef NO_PROTO
    setmsg_("7", "<Inquire structure status> should return the appropriate s"
	    "tructure status as NOTEMPTY for a non-empty structure when the s"
	    "tructure is closed.", 1L, 141L);
#else /* NO_PROTO */
    setmsg_("7", "<Inquire structure status> should return the appropriate s\
tructure status as NOTEMPTY for a non-empty structure when the structure is \
closed.", 1L, 141L);
#endif /* NO_PROTO */
    nqstst (&c__40, &errind, &ststin);
    L__1 = errind == 0 && ststin == 2;
    ifpf_(&L__1);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

