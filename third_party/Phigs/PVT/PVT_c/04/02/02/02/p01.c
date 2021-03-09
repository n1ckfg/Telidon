/* fort/04/02/02/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.02.02/01                        * */
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
    static integer rl, pmi, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer coli;
    static real rlar[50];
    static integer intg, coli2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
    static real mwdth;
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspmi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspmi ();
#endif /* NO_PROTO */
    static char strar[1*50];
    static integer mtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nspmr (integer *, integer *, integer *, 
	    real *, integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmr (), nopwk (), nspmr (), nopst ();
#endif /* NO_PROTO */
    static real mwdth2;
    static integer mtype2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, intlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqcets (integer *, 
	    integer *, integer *, integer *, integer *), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqcets (), setmsg_();
#endif /* NO_PROTO */
    static integer emtype, strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/* PHIGS parameter types */
/* types of parameter values */
/* type of returned value */
    initgl_("04.02.02.02/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* structure identifier = 1 */
    strid = 1;
/* open structure */
    nopst (&strid);
/* *** *** *** *** ***    Polymarker index *** *** *** *** *** */
/* set value for attribute */
    nspmi (&c__8);
#ifndef NO_PROTO
    setmsg_("1 4", "<Inquire current element type and size> should return po"
	    "lymarker index as the type of the created element and the approp"
	    "riate element size.", 3L, 139L);
#else /* NO_PROTO */
    setmsg_("1 4", "<Inquire current element type and size> should return po\
lymarker index as the type of the created element and the appropriate elemen\
t size.", 3L, 139L);
#endif /* NO_PROTO */
    nqcets (&errind, &emtype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 19 is the PHIGS enumeration type for pepmi */
    L__1 = errind == 0 && emtype == 19 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 4", "<Inquire current element content> should return the stan"
	    "dard representation for the polymarker index value.", 3L, 107L);
#else /* NO_PROTO */
    setmsg_("2 4", "<Inquire current element content> should return the stan\
dard representation for the polymarker index value.", 3L, 107L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pepli */
    L__1 = errind == 0 && intar[0] == 8 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* *** *** *** polymarker representation set and inquire */
/*polymarker index, marker type, marker size scale factor, and colour inde
x*/
    pmi = 4;
    mtype = 3;
#ifndef NO_PROTO
    mwdth = .25f;
#else /* NO_PROTO */
    mwdth = (float).25;
#endif /* NO_PROTO */
    coli = 4;
    nspmr (&globnu_1.wkid, &pmi, &mtype, &mwdth, &coli);
/* type of returned value = set */
    nqpmr (&globnu_1.wkid, &pmi, &c__0, &errind, &mtype2, &mwdth2, &coli2);
    chkinq_("pqpmr", &errind, 5L);
    setmsg_("11 14", "Polymarker attributes should be returned as set.", 5L, 
	    48L);
    L__1 = errind == 0 && mtype2 == mtype && mwdth2 == mwdth && coli2 == coli;

    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

