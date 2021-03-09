/* fort/04/02/05/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__5 = 5;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/01                        * */
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
    static integer rl, edi, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer coli, naet;
    static real rlar[50];
    static integer intg, coli2, idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
    static integer eflag;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void), nsedi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_(), nsedi ();
#endif /* NO_PROTO */
    static real ewdth;
    static integer rllen, intar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedr (integer *, integer *, integer *, 
	    integer *, real *, integer *), nqedr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedr (), nqedr ();
#endif /* NO_PROTO */
    static integer strid, etype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static char strar[80*5];
    static integer eflag2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nopst ();
#endif /* NO_PROTO */
    static real ewdth2;
    static integer etype2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, eetype, intlen, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqcets (integer *, 
	    integer *, integer *, integer *, integer *), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqcets (), setmsg_();
#endif /* NO_PROTO */
    static integer specwt, strlen, strarl[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/* type of returned value */
/* off/on switch for edge flag and error handling mode */
    initgl_("04.02.05.03/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* structure identifier = 1 */
    strid = 1;
/* open structure */
    nopst (&strid);
/* *** *** *** *** ***    Edge index   *** *** *** *** *** */
/* set value for attribute */
    nsedi (&c__8);
#ifndef NO_PROTO
    setmsg_("1 4", "<Inquire current element type and size> should return ed"
	    "ge index as the type of the created element and the appropriate "
	    "element size.", 3L, 133L);
#else /* NO_PROTO */
    setmsg_("1 4", "<Inquire current element type and size> should return ed\
ge index as the type of the created element and the appropriate element size."
	    , 3L, 133L);
#endif /* NO_PROTO */
    nqcets (&errind, &eetype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 22 is the PHIGS enumeration type for peedi */
    L__1 = errind == 0 && eetype == 22 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 4", "<Inquire current element content> should return the stan"
	    "dard representation for the edge index value.", 3L, 101L);
#else /* NO_PROTO */
    setmsg_("2 4", "<Inquire current element content> should return the stan\
dard representation for the edge index value.", 3L, 101L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__5, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 80L);
/* checking correct output parameters for data record type peedi */
    L__1 = errind == 0 && intar[0] == 8 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* *** *** ***   edge representation set and inquire   *** *** *** */
/*  get an available edgetype */
    nqedf (&specwt, &c__0, &errind, &naet, &idum1, &idum2, &rdum1, &rdum2, &
	    rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
    nqedf (&specwt, &naet, &errind, &idum1, &etype, &idum2, &rdum1, &rdum2, &
	    rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
/* edge index, edgetype, edgewidth scale factor, and colour index */
    edi = 2;
    eflag = 1;
#ifndef NO_PROTO
    ewdth = 4.f;
#else /* NO_PROTO */
    ewdth = (float)4.;
#endif /* NO_PROTO */
    coli = 5;
    nsedr (&globnu_1.wkid, &edi, &eflag, &etype, &ewdth, &coli);
/* type of returned value = set */
    nqedr (&globnu_1.wkid, &edi, &c__0, &errind, &eflag2, &etype2, &ewdth2, &
	    coli2);
    chkinq_("pqedr", &errind, 5L);
    setmsg_("11 14", "Edge attributes should be returned as set.", 5L, 42L);
    L__1 = errind == 0 && eflag2 == eflag && etype2 == etype && ewdth2 == 
	    ewdth && coli2 == coli;
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

