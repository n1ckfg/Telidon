/* fort/04/02/01/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b15 = 1.f;
#else /* NO_PROTO */
static real c_b15 = (float)1.;
#endif /* NO_PROTO */
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.01.02/03                        * */
/*  *    TEST TITLE : Polyline bundle table length          * */
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
    static integer n, nde, pli;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer mpbe;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer nemp, mpli;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), nopwk (integer *, 
	    integer *, integer *), nsplr (integer *, integer *, integer *, 
	    real *, integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc (), nopwk (), 
	    nsplr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, mplbte, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqepli (integer *, 
	    integer *, integer *, integer *, integer *), errctl_(logical *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqepli (), errctl_(), setmsg_();
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


/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.01.02/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &mplbte, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/* maximum number of polyline bundle table entries */
    mpbe = mplbte;
#ifndef NO_PROTO
    setmsg_("17 18", "<Inquire workstation state table lengths> should repor"
	    "t at least 20 entries as maximum size of polyline bundle table.", 
	    5L, 117L);
#else /* NO_PROTO */
    setmsg_("17 18", "<Inquire workstation state table lengths> should repor\
t at least 20 entries as maximum size of polyline bundle table.", 5L, 117L);
#endif /* NO_PROTO */
    L__1 = mpbe >= 20;
    ifpf_(&L__1);
    nqepli (&globnu_1.wkid, &c__1, &errind, &nde, &idum1);
    chkinq_("pqepli", &errind, 6L);
    mpli = -9999;
    i__1 = nde;
    for (n = 1; n <= i__1; ++n) {
	nqepli (&globnu_1.wkid, &n, &errind, &idum1, &pli);
	chkinq_("pqepli", &errind, 6L);
	if (pli > mpli) {
	    mpli = pli;
	}
/* L100: */
    }
    nemp = mpbe - nde;
/*  nde  = number of defined entries */
/*  mpli = maximum defined polyline index */
/*  nemp = number of empty entries */
#ifndef NO_PROTO
    setmsg_("17", "The program should be able to define additional polyline "
	    "bundle entries, up to the maximum.", 2L, 91L);
#else /* NO_PROTO */
    setmsg_("17", "The program should be able to define additional polyline \
bundle entries, up to the maximum.", 2L, 91L);
#endif /* NO_PROTO */
/*  set new entries */
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    i__1 = mpli + nemp;
    for (pli = mpli + 1; pli <= i__1; ++pli) {
	nsplr (&globnu_1.wkid, &pli, &c__1, &c_b15, &c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___19);
	    do_fio(&c__1, "Unable to fill polyline bundle slot #", 37L);
	    i__2 = nde + pli - mpli;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L200;
	}
/* L150: */
    }
    pass_();
L200:
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

