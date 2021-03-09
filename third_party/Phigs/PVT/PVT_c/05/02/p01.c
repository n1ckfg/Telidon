/* fort/05/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__6 = 6;
static integer c__10 = 10;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b23 = .5f;
#else /* NO_PROTO */
static real c_b23 = (float).5;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.02/01                              * */
/*  *    TEST TITLE : Setting and inquiring display update  * */
/*  *                 state                                 * */
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
    address a__1[4], a__2[6];
    integer i__1[4], i__2[6];
    logical L__1;
    char ch__1[187], ch__2[170];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer dm, mm, rdm, rmm;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer svr, adef, ddef;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer amod, dmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer lenop, dsurf;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nclst (void), nclwk (integer *), nqdus (integer *, 
	    integer *, integer *, integer *, integer *, integer *), nsdus (
	    integer *, integer *, integer *), nopwk (integer *, integer *, 
	    integer *), nopst (integer *), npost (integer *, integer *, real *
	    ), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int nqwkc (), nclst (), nclwk (), nqdus (), 
	    nsdus (), nopwk (), nopst (), npost (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqddus (integer *, 
	    integer *, integer *, integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqddus (), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
    static char opstat[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* parameters used in posting a structure */
/* deferral mode */
/* modification mode */
/* display surface empty */
/* dynamic modification */
/* state of visual representation */
/* parameters for <inquire workstation connection and type> */
    initgl_("05.02/01", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  DESIGN: */
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("1 2 5", "<Inquire default display update state> should report a"
	    " valid default deferral and modification mode.", 5L, 100L);
#else /* NO_PROTO */
    setmsg_("1 2 5", "<Inquire default display update state> should report a\
 valid default deferral and modification mode.", 5L, 100L);
#endif /* NO_PROTO */
/*  <inquire default display update state> to determine */
/*     ddef = default deferral mode */
/*     dmod = default modification mode */
    ddef = -6;
    dmod = -6;
    nqddus (&specwt, &errind, &ddef, &dmod);
    L__1 = errind == 0 && (ddef >= 0 && ddef <= 4) && (dmod >= 0 && dmod <= 2)
	    ;
    ifpf_(&L__1);
    s_copy(opstat, "opening", 10L, 7L);
/*  open_test: */
L100:
    lenop = itrim_(opstat, 10L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 124, a__1[0] = "<Inquire display update state> should report t"
	    "he current deferral and modification mode to be the same as the "
	    "default after ";
#else /* NO_PROTO */
    i__1[0] = 124, a__1[0] = "<Inquire display update state> should report t\
he current deferral and modification mode to be the same as the default afte\
r ";
#endif /* NO_PROTO */
    i__1[1] = lenop, a__1[1] = opstat;
    i__1[2] = 22, a__1[2] = " the workstation, but ";
    i__1[3] = 31, a__1[3] = "before they are explicitly set.";
    s_cat(ch__1, a__1, i__1, &c__4, 187L);
    setmsg_("4 8", ch__1, 3L, lenop + 177);
/*  <inquire display update state> to determine */
/*     adef  = actual deferral mode */
/*     amod  = actual modification mode */
/*     dsurf = display surface */
/*     svr   = state of visual representation */
    nqdus (&globnu_1.wkid, &errind, &adef, &amod, &dsurf, &svr);
    L__1 = errind == 0 && adef == ddef && amod == dmod;
    ifpf_(&L__1);
/* Writing concatenation */
    i__2[0] = 18, a__2[0] = "Immediately after ";
    i__2[1] = lenop, a__2[1] = opstat;
#ifndef NO_PROTO
    i__2[2] = 49, a__2[2] = " the workstation, <inquire display update state"
	    "> ";
#else /* NO_PROTO */
    i__2[2] = 49, a__2[2] = " the workstation, <inquire display update state\
> ";
#endif /* NO_PROTO */
    i__2[3] = 43, a__2[3] = "should report the display surface as EMPTY ";
    i__2[4] = 42, a__2[4] = "and the state of visual representation as ";
    i__2[5] = 8, a__2[5] = "CORRECT.";
    s_cat(ch__2, a__2, i__2, &c__6, 170L);
    setmsg_("4 9 13", ch__2, 6L, lenop + 160);
    L__1 = errind == 0 && dsurf == 1 && svr == 0;
    ifpf_(&L__1);
    if (s_cmp(opstat, "opening", 10L, 7L) == 0) {
	if (ddef == 0) {
	    dm = 3;
	} else {
	    dm = 0;
	}
	if (dmod == 2) {
	    mm = 1;
	} else {
	    mm = 2;
	}
/* <set display update state> dm,mm */
	nsdus (&globnu_1.wkid, &dm, &mm);
/* post visible structure to workstation */
	nopst (&c__10);
	npl (&c__2, xp, yp);
	nclst ();
	npost (&globnu_1.wkid, &c__10, &c_b23);
/* <close workstation> */
	nclwk (&globnu_1.wkid);
/* <open workstation> */
	nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/* opstat = "re-opening" */
	s_copy(opstat, "re-opening", 10L, 10L);
	goto L100;
    }
#ifndef NO_PROTO
    setmsg_("1 2 3 4", "<Set display update state> should be able to set any"
	    " valid deferral and modification mode.", 7L, 90L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4", "<Set display update state> should be able to set any\
 valid deferral and modification mode.", 7L, 90L);
#endif /* NO_PROTO */
    for (dm = 0; dm <= 4; ++dm) {
	for (mm = 0; mm <= 2; ++mm) {
	    nsdus (&globnu_1.wkid, &dm, &mm);
/* <set display update state> dm,mm */
/* <inquire display update state> to determine */
/*   rdm = reported deferral mode */
/*   rmm = reported modification mode */
	    nqdus (&globnu_1.wkid, &errind, &rdm, &rmm, &idum1, &idum2);
	    if (errind != 0 || rdm != dm || rmm != mm) {
		fail_();
		goto L300;
	    }
/* L200: */
	}
/* L250: */
    }
    pass_();
L300:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

