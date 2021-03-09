/* fort/02/01/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.01/03                           * */
/*  *    TEST TITLE : Structure creation by executing a     * */
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
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer idum1, idum2, nstr1, nstr2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqsid (integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqsid ();
#endif /* NO_PROTO */
    static integer nstid, strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nexst (integer *), nopst (
	    integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst (), nopst (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
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
    static integer strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/* PHIGS parameter types */
    initgl_("02.01.01/03", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("3", "Executing a non-existent structure should create a new str"
	    "ucture with the specified identifier in the CSS.", 1L, 106L);
#else /* NO_PROTO */
    setmsg_("3", "Executing a non-existent structure should create a new str\
ucture with the specified identifier in the CSS.", 1L, 106L);
#endif /* NO_PROTO */
    rstrid = 101;
    strid = 102;
/* open structure */
    nopst (&rstrid);
/* execute structure */
    nexst (&strid);
/* close structure */
    nclst ();
/* nstid = number of structure identifiers */
    nqsid (&c__0, &errind, &nstid, &idum1);
    chkinq_("pqsid", &errind, 5L);
    if (nstid != 2) {
	fail_();
	goto L100;
    }
/* nstr  = Nth structure identifier */
    nqsid (&c__1, &errind, &idum1, &nstr1);
    chkinq_("pqsid", &errind, 5L);
    nqsid (&c__2, &errind, &idum2, &nstr2);
    chkinq_("pqsid", &errind, 5L);
    L__1 = nstr1 == strid || nstr2 == strid;
    ifpf_(&L__1);
L100:
#ifndef NO_PROTO
    setmsg_("3", "Executing a non-existent structure should create an empty "
	    "structure with the specified identifier in the CSS.", 1L, 109L);
#else /* NO_PROTO */
    setmsg_("3", "Executing a non-existent structure should create an empty \
structure with the specified identifier in the CSS.", 1L, 109L);
#endif /* NO_PROTO */
/* strsti = structure status identifier */
    nqstst (&strid, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

