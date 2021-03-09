/* fort/02/01/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.01/04                           * */
/*  *    TEST TITLE : Structure creation by posting a       * */
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
    static integer nstr;
    static real rdum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nclwk ();
#endif /* NO_PROTO */
    static integer nstid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqsid (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqsid ();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    npost (integer *, integer *, real *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), npost (), chkinq_();
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
    initgl_("02.01.01/04", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
#ifndef NO_PROTO
    setmsg_("4", "Posting a non-existent structure should create a new struc"
	    "ture with the specified identifier in the CSS.", 1L, 104L);
#else /* NO_PROTO */
    setmsg_("4", "Posting a non-existent structure should create a new struc\
ture with the specified identifier in the CSS.", 1L, 104L);
#endif /* NO_PROTO */
    strid = 100;
#ifndef NO_PROTO
    rdum1 = .02f;
#else /* NO_PROTO */
    rdum1 = (float).02;
#endif /* NO_PROTO */
/* post structure */
    npost (&globnu_1.wkid, &strid, &rdum1);
/* close workstation */
    nclwk (&globnu_1.wkid);
/* nstid = number of structure identifiers */
/* nstr  = Nth structure identifier */
    nqsid (&c__1, &errind, &nstid, &nstr);
    L__1 = errind == 0 && nstid == 1 && nstr == strid;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4", "Posting a non-existent structure should create an empty st"
	    "ructure with the specified identifier in the CSS.", 1L, 107L);
#else /* NO_PROTO */
    setmsg_("4", "Posting a non-existent structure should create an empty st\
ructure with the specified identifier in the CSS.", 1L, 107L);
#endif /* NO_PROTO */
/* strsti = structure status identifier */
    nqstst (&strid, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

