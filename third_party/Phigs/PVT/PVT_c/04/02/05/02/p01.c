/* fort/04/02/05/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__8 = 8;
static integer c__50 = 50;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/01                        * */
/*  *    TEST TITLE : Simple setting and inquiring          * */
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
    static integer ii, rl, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer coli;
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsii (integer *), nqir (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsii (), nqir ();
#endif /* NO_PROTO */
    static integer ints;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsir (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsir ();
#endif /* NO_PROTO */
    static integer coli2, ints2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[50], strid;
    static char strar[1*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static integer styli;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static integer styli2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, intlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer eltype;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    nqcets (integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), nqcets ();
#endif /* NO_PROTO */
    static integer strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/* PHIGS parameter types */
/* types of parameter values */
/* interior style */
/* type of returned value */
    initgl_("04.02.05.02/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* structure identifier = 1 */
    strid = 1;
/* open structure */
    nopst (&strid);
/* *** *** *** *** ***    Interior index *** *** *** *** *** */
/* set value for attribute */
    nsii (&c__8);
#ifndef NO_PROTO
    setmsg_("1 5", "<Inquire current element type and size> should return in"
	    "terior index as the type of the created element and the appropri"
	    "ate element size.", 3L, 137L);
#else /* NO_PROTO */
    setmsg_("1 5", "<Inquire current element type and size> should return in\
terior index as the type of the created element and the appropriate element \
size.", 3L, 137L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 21 is the PHIGS enumeration type for peii */
    L__1 = errind == 0 && eltype == 21 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 5", "<Inquire current element content> should return the stan"
	    "dard representation for the interior index value.", 3L, 105L);
#else /* NO_PROTO */
    setmsg_("2 5", "<Inquire current element content> should return the stan\
dard representation for the interior index value.", 3L, 105L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peii */
    L__1 = errind == 0 && intar[0] == 8 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* *** *** *** interior representation set and inquire */
/* interior index, style, style index, and colour index */
    ii = 2;
    ints = 0;
    styli = 1;
    coli = 5;
    nsir (&globnu_1.wkid, &ii, &ints, &styli, &coli);
/* type of returned value = set */
    nqir (&globnu_1.wkid, &ii, &c__0, &errind, &ints2, &styli2, &coli2);
    chkinq_("pqir", &errind, 4L);
    setmsg_("12 15", "Interior attributes should be returned as set.", 5L, 
	    46L);
    L__1 = errind == 0 && ints2 == ints && styli == styli && coli2 == coli;
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

