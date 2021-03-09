/* fort/02/01/01/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.01.01/06                           * */
/*  *    TEST TITLE : Structure creation by changing        * */
/*  *                 the structure identifier to the       * */
/*  *                 same value                            * */
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
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqsid (integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqsid ();
#endif /* NO_PROTO */
    static integer nstid, strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), ncstid (integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), ncstid (), setmsg_(), xpopph_();
#endif /* NO_PROTO */
    static integer strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/* PHIGS parameter types */
    initgl_("02.01.01/06", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("5", "Changing a structure identifier with the original identifi"
	    "er having the same value as the resulting identifier should crea"
	    "te one new structure with the resulting identifier in the CSS.", 
	    1L, 184L);
#else /* NO_PROTO */
    setmsg_("5", "Changing a structure identifier with the original identifi\
er having the same value as the resulting identifier should create one new s\
tructure with the resulting identifier in the CSS.", 1L, 184L);
#endif /* NO_PROTO */
    strid = 10;
    ncstid (&strid, &strid);
/* nstid = number of structure identifiers */
/* nstr  = Nth structure identifier */
    nqsid (&c__1, &errind, &nstid, &nstr);
    L__1 = errind == 0 && nstid == 1 && nstr == strid;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("5", "Changing a structure identifier with the original identifi"
	    "er having the same value as the resulting identifier should crea"
	    "te an empty structure with the resulting identifier in the CSS.", 
	    1L, 185L);
#else /* NO_PROTO */
    setmsg_("5", "Changing a structure identifier with the original identifi\
er having the same value as the resulting identifier should create an empty \
structure with the resulting identifier in the CSS.", 1L, 185L);
#endif /* NO_PROTO */
    nqstst (&strid, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

