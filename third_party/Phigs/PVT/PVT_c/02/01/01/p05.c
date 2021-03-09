/* fort/02/01/01/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.01.01/05                           * */
/*  *    TEST TITLE : Structure creation by changing        * */
/*  *                 the structure identifier to a         * */
/*  *                 different value                       * */
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
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), ncstid (), setmsg_();
#endif /* NO_PROTO */
    static integer nwstid;
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
    initgl_("02.01.01/05", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("5", "Changing a structure identifier with the original identifi"
	    "er having a different value than the resulting identifier should"
	    " create one new structure with the resulting identifier in the C"
	    "SS.", 1L, 189L);
#else /* NO_PROTO */
    setmsg_("5", "Changing a structure identifier with the original identifi\
er having a different value than the resulting identifier should create one \
new structure with the resulting identifier in the CSS.", 1L, 189L);
#endif /* NO_PROTO */
    strid = 101;
    nwstid = 102;
    ncstid (&strid, &nwstid);
/* nstid = number of structure identifiers */
/* nstr  = Nth structure identifier */
    nqsid (&c__1, &errind, &nstid, &nstr);
    L__1 = errind == 0 && nstid == 1 && nstr == nwstid;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("5", "Changing a structure identifier with the original identifi"
	    "er having a different value than the resulting identifier should"
	    " create an empty structure with the resulting identifier in the "
	    "CSS.", 1L, 190L);
#else /* NO_PROTO */
    setmsg_("5", "Changing a structure identifier with the original identifi\
er having a different value than the resulting identifier should create an e\
mpty structure with the resulting identifier in the CSS.", 1L, 190L);
#endif /* NO_PROTO */
    nqstst (&nwstid, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

