/* fort/02/01/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.01/01                           * */
/*  *    TEST TITLE : Structure creation by opening a       * */
/*  *                 non-existent structure                * */
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
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer nstr, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nclph (void), nqsid (integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nclph (), nqsid ();
#endif /* NO_PROTO */
    static integer nstid, strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nopst (integer *), chkinq_(char 
	    *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nopst (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */
    static integer strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/* PHIGS parameter types */
    initgl_("02.01.01/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    setmsg_("8", "The CSS should be empty upon first opening PHIGS.", 1L, 49L)
	    ;
    nqsid (&c__0, &errind, &nstid, &idum1);
    chkinq_("pqsid", &errind, 5L);
    L__1 = nstid == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1", "Opening a non-existent structure should create one new str"
	    "ucture with the specified identifier in the CSS.", 1L, 106L);
#else /* NO_PROTO */
    setmsg_("1", "Opening a non-existent structure should create one new str\
ucture with the specified identifier in the CSS.", 1L, 106L);
#endif /* NO_PROTO */
    strid = 100;
/* open structure */
    nopst (&strid);
/* nstid = number of structure identifiers */
/* nstr  = Nth structure identifier */
    nqsid (&c__1, &errind, &nstid, &nstr);
    L__1 = errind == 0 && nstid == 1 && nstr == strid;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1", "Opening a non-existent structure should create an empty st"
	    "ructure with the specified identifier in the CSS.", 1L, 107L);
#else /* NO_PROTO */
    setmsg_("1", "Opening a non-existent structure should create an empty st\
ructure with the specified identifier in the CSS.", 1L, 107L);
#endif /* NO_PROTO */
/* strsti = structure status identifier */
    nqstst (&strid, &errind, &strsti);
    L__1 = errind == 0 && strsti == 1;
    ifpf_(&L__1);
/* close structure */
    nclst ();
    setmsg_("8", "The CSS should be empty after closing and re-opening PHIGS."
	    , 1L, 59L);
    nclph ();
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nqsid (&c__0, &errind, &nstid, &idum1);
    chkinq_("pqsid", &errind, 5L);
    L__1 = nstid == 0;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

