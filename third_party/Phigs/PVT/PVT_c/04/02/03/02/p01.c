/* fort/04/02/03/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__4 = 4;
static integer c__50 = 50;
static integer c__2 = 2;
static integer c__5 = 5;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.02/01                        * */
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
    static integer rl, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer tcoli, rllen, intar[50], tprec;
    static real tchsp;
    static integer strid;
    static real tchxp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer tfont;
    static char strar[1*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nopst (integer *), nstxi (integer *), nqtxr (integer *, integer *,
	     integer *, integer *, integer *, integer *, real *, real *, 
	    integer *), nstxr (integer *, integer *, integer *, integer *, 
	    real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nopst (), nstxi (), nqtxr (), 
	    nstxr ();
#endif /* NO_PROTO */
    static real txatr1, txatr2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, intlen, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqcets (integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqcets ();
#endif /* NO_PROTO */
    static integer eltype;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer specwt, strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/* text precision */
/* type of return values */
/* PHIGS parameter types */
    initgl_("04.02.03.02/01", 14L);
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
/* *** *** *** *** ***    Text index    *** *** *** *** *** */
/*  <set text index>: */
    nstxi (&c__4);

#ifndef NO_PROTO
    setmsg_("1 4", "<Inquire current element type and size> should return te"
	    "xt index as the type of the created element and the appropriate "
	    "element size.", 3L, 133L);
#else /* NO_PROTO */
    setmsg_("1 4", "<Inquire current element type and size> should return te\
xt index as the type of the created element and the appropriate element size."
	    , 3L, 133L);
#endif /* NO_PROTO */
/*  <inquire current element type and size> for current element type */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
    chkinq_("pqcets", &errind, 6L);
/* checking correct element type */
/* 20 is the PHIGS enumeration type for petxi */
    L__1 = errind == 0 && eltype == 20 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
/*  <inquire current element content> for current element representation 
*/
#ifndef NO_PROTO
    setmsg_("2 4", "<Inquire current element content> should return the stan"
	    "dard representation for the text index value.", 3L, 101L);
#else /* NO_PROTO */
    setmsg_("2 4", "<Inquire current element content> should return the stan\
dard representation for the text index value.", 3L, 101L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    chkinq_("pqceco", &errind, 6L);
/* checking correct output parameters for data record type petxi */
    L__1 = errind == 0 && intar[0] == 4 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/*  *** ***  text representation set and inquire *** *** */
/* set text representation for index #2 */
#ifndef NO_PROTO
    txatr1 = 2.1f;
    txatr2 = .7f;
#else /* NO_PROTO */
    txatr1 = (float)2.1;
    txatr2 = (float).7;
#endif /* NO_PROTO */
    nstxr (&globnu_1.wkid, &c__2, &c__2, &c__2, &txatr1, &txatr2, &c__5);
/*  <inquire text representation> for index #2, as set */
    setmsg_("11 14", "Text attributes should be returned as set.", 5L, 42L);
    nqtxr (&globnu_1.wkid, &c__2, &c__0, &errind, &tfont, &tprec, &tchxp, &
	    tchsp, &tcoli);
    chkinq_("pqtxr", &errind, 5L);
    L__1 = errind == 0 && tfont == 2 && tprec == 2 && tchxp == txatr1 && 
	    tchsp == txatr2 && tcoli == 5;
    ifpf_(&L__1);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

