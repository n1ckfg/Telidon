/* fort/04/03/03/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__10 = 10;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b13 = .5f;
#else /* NO_PROTO */
static real c_b13 = (float).5;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.03/04                           * */
/*  *    TEST TITLE : Updating of HLHSR modes               * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static real xp[2] = { 0.f,1.f };
    static real yp[2] = { 0.f,1.f };
#else /* NO_PROTO */
    static real xp[2] = { (float)0.,(float)1. };
    static real yp[2] = { (float)0.,(float)1. };
#endif /* NO_PROTO */

    /* System generated locals */
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ifpf_(
	    logical *), nuwk (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ifpf_(), nuwk ();
#endif /* NO_PROTO */
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nclwk (integer *), nqwkc (
	    integer *, integer *, integer *, integer *), nclst (void), nqhrm (
	    integer *, integer *, integer *, integer *, integer *), nshrm (
	    integer *, integer *), nopwk (integer *, integer *, integer *), 
	    nopst (integer *), npost (integer *, integer *, real *), chkinq_(
	    char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nclwk (), nqwkc (), nclst (), 
	    nqhrm (), nshrm (), nopwk (), nopst (), npost (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, curmod, reqmod, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static logical statok;
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer upstat;

/*  Declare program-specific variables */
/* regeneration flag */
/* update state */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.03.03/04", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* get this workstation type */
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* <inquire HLHSR mode> to determine */
/*  upstat = HLHSR update state */
/*  curmod = current HLHSR mode */
/*  reqmod = requested HLHSR mode */
    upstat = -6;
    curmod = -6;
    reqmod = -6;
    nqhrm (&globnu_1.wkid, &errind, &upstat, &curmod, &reqmod);
    chkinq_("pqhrm", &errind, 5L);
/* check upstat is valid upon <open workstation> */
    statok = upstat == 0 || upstat == 1;
#ifndef NO_PROTO
    setmsg_("12", "Immediately after <open workstation>, the HLHSR update st"
	    "ate should be NOTPENDING.", 2L, 82L);
#else /* NO_PROTO */
    setmsg_("12", "Immediately after <open workstation>, the HLHSR update st\
ate should be NOTPENDING.", 2L, 82L);
#endif /* NO_PROTO */
    L__1 = upstat == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("13", "Immediately after <open workstation>, the current HLHSR m"
	    "ode should be 0.", 2L, 73L);
#else /* NO_PROTO */
    setmsg_("13", "Immediately after <open workstation>, the current HLHSR m\
ode should be 0.", 2L, 73L);
#endif /* NO_PROTO */
    L__1 = curmod == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("14", "Immediately after <open workstation>, the requested HLHSR"
	    " mode should be 0.", 2L, 75L);
#else /* NO_PROTO */
    setmsg_("14", "Immediately after <open workstation>, the requested HLHSR\
 mode should be 0.", 2L, 75L);
#endif /* NO_PROTO */
    L__1 = reqmod == 0;
    ifpf_(&L__1);
/* Try to cause HLHSR update state to be PENDING by making */
/*   surface NOT EMPTY: */
    nopst (&c__10);
    npl (&c__2, xp, yp);
    nclst ();
    npost (&globnu_1.wkid, &c__10, &c_b13);
    nuwk (&globnu_1.wkid, &c__1);
#ifndef NO_PROTO
    setmsg_("15", "The HLHSR update state should be either PENDING or NOTPEN"
	    "DING.", 2L, 62L);
#else /* NO_PROTO */
    setmsg_("15", "The HLHSR update state should be either PENDING or NOTPEN\
DING.", 2L, 62L);
#endif /* NO_PROTO */
/* re-set HLHSR mode */
    nshrm (&globnu_1.wkid, &c__0);
    upstat = -66;
    nqhrm (&globnu_1.wkid, &errind, &upstat, &idum1, &idum2);
    chkinq_("pqhrm", &errind, 5L);
    L__1 = (upstat == 0 || upstat == 1) && statok;
    ifpf_(&L__1);
/*  close workstation and re-open */
    nclwk (&globnu_1.wkid);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
#ifndef NO_PROTO
    setmsg_("12", "Immediately after re-opening the workstation, the HLHSR u"
	    "pdate state should be NOTPENDING.", 2L, 90L);
#else /* NO_PROTO */
    setmsg_("12", "Immediately after re-opening the workstation, the HLHSR u\
pdate state should be NOTPENDING.", 2L, 90L);
#endif /* NO_PROTO */
    upstat = -66;
    nqhrm (&globnu_1.wkid, &errind, &upstat, &idum1, &idum2);
    chkinq_("pqhrm", &errind, 5L);
    L__1 = upstat == 0;
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

