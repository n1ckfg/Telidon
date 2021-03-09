/* fort/04/03/02/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.01/02                        * */
/*  *    TEST TITLE : Colour table length                   * */
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
    static real colspc[3] = { 1.f,1.f,1.f };
#else /* NO_PROTO */
    static real colspc[3] = { (float)1.,(float)1.,(float)1. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1, i__2;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ci, nde;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer mdci;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer coli, mcte, nemp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    , pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr (), pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *), endit_(void), nscmd (integer *, integer *),
	     inmsg_(char *, ftnlen), nqwkc (integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *), chkinq_(char 
	    *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci (), endit_(), nscmd (), inmsg_(), 
	    nqwkc (), nopwk (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), errctl_(logical *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), errctl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___19 = { 0, msg, 0, "(A,I6,A)", 300, 1 };


/* colour model */
/* NOTE:  INTEGER rather than enumeration type.  Explicitly defined and */

/* required portion of conceptually unbounded range defined here. */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.03.02.01/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/* set colour model RGB */
/* This statement is necessary to give meaningful value to the */
/* colour specifications used in <set colour representation>. */
    nscmd (&globnu_1.wkid, &c__1);
/* mcte = maximum number of colour table entries */
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &idum6, 
	    &mcte, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  nde  = number of defined entries */
/*  mdci = maximum defined colour index */
/*  nemp = number of empty entries */
#ifndef NO_PROTO
    setmsg_("7 8", "<Inquire workstation state table lengths> should report "
	    "at least 2 entries as maximum size of colour table.", 3L, 107L);
#else /* NO_PROTO */
    setmsg_("7 8", "<Inquire workstation state table lengths> should report \
at least 2 entries as maximum size of colour table.", 3L, 107L);
#endif /* NO_PROTO */
    L__1 = mcte >= 2;
    ifpf_(&L__1);
    nqeci (&globnu_1.wkid, &c__0, &errind, &nde, &idum1);
    chkinq_("pqeci", &errind, 5L);
    mdci = -9999;
    i__1 = nde;
    for (ci = 1; ci <= i__1; ++ci) {
	nqeci (&globnu_1.wkid, &ci, &errind, &idum1, &coli);
	chkinq_("pqeci", &errind, 5L);
	if (coli > mdci) {
	    mdci = coli;
	}
/* L100: */
    }
    nemp = mcte - nde;
#ifndef NO_PROTO
    setmsg_("7", "The program should be able to define additional colour tab"
	    "le entries, up to the maximum.", 1L, 88L);
#else /* NO_PROTO */
    setmsg_("7", "The program should be able to define additional colour tab\
le entries, up to the maximum.", 1L, 88L);
#endif /* NO_PROTO */
/*  set new entries */
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    i__1 = mdci + nemp;
    for (coli = mdci + 1; coli <= i__1; ++coli) {
	nscr (&globnu_1.wkid, &coli, &c__3, colspc);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___19);
	    do_fio(&c__1, "Unable to fill colour table slot #", 34L);
	    i__2 = nde + coli - mdci;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L300;
	}
/* L250: */
    }
    pass_();
L300:
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

