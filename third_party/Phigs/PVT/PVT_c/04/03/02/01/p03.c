/* fort/04/03/02/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.01/03                        * */
/*  *    TEST TITLE : Setting and inquiring colour model    * */
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
    extern /* Subroutine */ int ifpf_(logical *), endit_(void), nqcmd (
	    integer *, integer *, integer *), nscmd (integer *, integer *), 
	    nqwkc (integer *, integer *, integer *, integer *), nopwk (
	    integer *, integer *, integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), endit_(), nqcmd (), nscmd (), nqwkc (
	    ), nopwk (), chkinq_();
#endif /* NO_PROTO */
    static integer inimod, errind, curmod, newmod, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
/* colour model */
/* NOTE:  INTEGER rather than enumeration type.  Explicitly defined and */

/* required potion of conceptually unbounded range defined here. */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.03.02.01/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* *** *** *** *** Initial Colour Model *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("10", "<Inquire colour model> should be able to determine the in"
	    "itial colour model.", 2L, 76L);
#else /* NO_PROTO */
    setmsg_("10", "<Inquire colour model> should be able to determine the in\
itial colour model.", 2L, 76L);
#endif /* NO_PROTO */
    nqcmd (&globnu_1.wkid, &errind, &inimod);
    L__1 = errind == 0;
    ifpf_(&L__1);
/* set different colour model */
    if (inimod == 1) {
	newmod = 2;
    } else {
	newmod = 1;
    }
    nscmd (&globnu_1.wkid, &newmod);
    nqcmd (&globnu_1.wkid, &errind, &curmod);
    chkinq_("pqcmd", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("9 10", "<Set colour model> should be able to change colour mode"
	    "l from its default setting.", 4L, 82L);
#else /* NO_PROTO */
    setmsg_("9 10", "<Set colour model> should be able to change colour mode\
l from its default setting.", 4L, 82L);
#endif /* NO_PROTO */
    L__1 = newmod == curmod;
    ifpf_(&L__1);
/* *** *** *** *** Redefined Colour Model *** *** *** *** */
/* get new colour model */
    if (curmod == 1) {
	newmod = 2;
    } else {
	newmod = 1;
    }
    nscmd (&globnu_1.wkid, &newmod);
    nqcmd (&globnu_1.wkid, &errind, &curmod);
    chkinq_("pqcmd", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("9 10", "<Set colour model> should be able to set colour model a"
	    "nd then re-set it.", 4L, 73L);
#else /* NO_PROTO */
    setmsg_("9 10", "<Set colour model> should be able to set colour model a\
nd then re-set it.", 4L, 73L);
#endif /* NO_PROTO */
    L__1 = newmod == curmod;
    ifpf_(&L__1);
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

