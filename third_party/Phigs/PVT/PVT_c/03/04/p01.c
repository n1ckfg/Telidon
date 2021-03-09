/* fort/03/04/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__50 = 50;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.04/01                              * */
/*  *    TEST TITLE : Inquiring about structure identifiers * */
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
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndas ();
#endif /* NO_PROTO */
    static integer lasi[50], arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nrsid (integer *, integer *, integer *, 
	    integer *), narst (integer *, integer *, integer *), setvs_(char *
	    , integer *, integer *, ftnlen), nclarf (integer *), ndasar (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical seteq_();
    extern /* Subroutine */ int nrsid (), narst (), setvs_(), nclarf (), 
	    ndasar ();
#endif /* NO_PROTO */
    static integer laslen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer explen;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), noparf (integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen), stdcss_(void)
	    , xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), noparf (), setmsg_(), stdcss_(), 
	    xpopph_();
#endif /* NO_PROTO */
    static integer expstr[50];

/*  Declare program-specific variables */
    initgl_("03.04/01", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  set up standard networks in CSS */
    stdcss_();
/*  open new archive file, with arid = archive identifier */
    avarnm_(&arnm);
    noparf (&arid, &arnm);
/*  <delete all structures from archive> to ensure empty file */
    ndasar (&arid);
/*  expstr = expected structures = 114,102,100,140,107 */
    setvs_("114,102,100,140,107", expstr, &explen, 19L);
/*  <archive structures> with expstr, arid */
    narst (&arid, &explen, expstr);
/*  <delete all structures> from CSS */
    ndas ();
/*  <retrieve structure identifiers> to determine */
/*     lasi = list of archive structure identifiers */
    nrsid (&arid, &c__50, &laslen, lasi);
#ifndef NO_PROTO
    setmsg_("1", "<Retrieve structure identifiers> should retrieve all ident"
	    "ifiers as archived by <archive structures>.", 1L, 101L);
#else /* NO_PROTO */
    setmsg_("1", "<Retrieve structure identifiers> should retrieve all ident\
ifiers as archived by <archive structures>.", 1L, 101L);
#endif /* NO_PROTO */
/*  pass/fail depending on (lasi contains same identifiers as expstr) */
    L__1 = explen == laslen && seteq_(&explen, expstr, lasi);
    ifpf_(&L__1);
/*  close archive file */
    nclarf (&arid);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

