/* fort/02/01/02/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__103 = 103;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__106 = 106;
static integer c__107 = 107;
static integer c__108 = 108;
static integer c__102 = 102;
static integer c__109 = 109;
static integer c__110 = 110;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.03/02                        * */
/*  *    TEST TITLE : Deletion of all structures with an    * */
/*  *                 open structure                        * */
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
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), ndas (void), 
	    pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), ndas (), pass_();
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
    extern /* Subroutine */ int nclst (void), nexst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst ();
#endif /* NO_PROTO */
    static integer stype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer strref;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqopst (
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqopst ();
#endif /* NO_PROTO */
    static integer strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/* parameter for structure status */
/* PHIGS parameter types */
    initgl_("02.01.02.03/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* creation of structures */
    nopst (&c__100);
    nexst (&c__103);
    nexst (&c__104);
    nclst ();
    nopst (&c__103);
    nexst (&c__105);
    nexst (&c__105);
    nclst ();
    nopst (&c__104);
    nexst (&c__106);
    nclst ();
    nopst (&c__106);
    nexst (&c__107);
    nexst (&c__108);
    nclst ();
    nopst (&c__102);
    nexst (&c__106);
    nexst (&c__109);
    nclst ();
    nopst (&c__109);
    nexst (&c__108);
    nexst (&c__110);
    nclst ();
#ifndef NO_PROTO
    setmsg_("1", "<Delete all structures> with an open structure should remo"
	    "ve all closed structures from the CSS.", 1L, 96L);
#else /* NO_PROTO */
    setmsg_("1", "<Delete all structures> with an open structure should remo\
ve all closed structures from the CSS.", 1L, 96L);
#endif /* NO_PROTO */
    strid = 106;
    nopst (&strid);
    ndas ();
/* nstid = number of structure identifiers */
    nqsid (&c__1, &errind, &nstid, &nstr);
    chkinq_("pqsid", &errind, 5L);
    L__1 = nstid == 1 && nstr == strid;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2", "<Delete all structures> with an open structure should caus"
	    "e that structure to exist in the CSS as an open structure.", 1L, 
	    116L);
#else /* NO_PROTO */
    setmsg_("2", "<Delete all structures> with an open structure should caus\
e that structure to exist in the CSS as an open structure.", 1L, 116L);
#endif /* NO_PROTO */
/* use <inquire open structure> to determine */
/*    stype  = structure status */
/*    strref = structure id */
    nqopst (&errind, &stype, &strref);
    chkinq_("pqopst", &errind, 6L);
    if (stype != 1 || strid != strref) {
	fail_();
    } else {
	pass_();
	nclst ();
    }
#ifndef NO_PROTO
    setmsg_("2", "<Delete all structures> with an open structure should caus"
	    "e that structure to exist in the CSS as an empty structure.", 1L, 
	    117L);
#else /* NO_PROTO */
    setmsg_("2", "<Delete all structures> with an open structure should caus\
e that structure to exist in the CSS as an empty structure.", 1L, 117L);
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

