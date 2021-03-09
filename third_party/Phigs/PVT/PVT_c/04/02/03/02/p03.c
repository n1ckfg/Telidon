/* fort/04/02/03/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b16 = 1.f;
static real c_b17 = 0.f;
#else /* NO_PROTO */
static real c_b16 = (float)1.;
static real c_b17 = (float)0.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.02/03                        * */
/*  *    TEST TITLE : Text bundle table length              * */
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
    static integer n, nde;
    static char msg[300];
    static integer txi;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer mtbe, nemp;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer mtxi, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), nopwk (integer *, 
	    integer *, integer *), nstxr (integer *, integer *, integer *, 
	    integer *, real *, real *, integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc (), nopwk (), 
	    nstxr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), errctl_(logical *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), errctl_(), setmsg_();
#endif /* NO_PROTO */
    static integer mtxbte, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqetxi (integer *, integer *, integer *, 
	    integer *, integer *), xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqetxi (), xpopph_(), nqwksl ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___19 = { 0, msg, 0, "(A,I6,A)", 300, 1 };


/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.03.02/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &idum1, &idum2, &mtxbte, &idum3, &idum4, &idum5,
	     &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/* maximum number of text bundle table entries */
    mtbe = mtxbte;
#ifndef NO_PROTO
    setmsg_("17 18", "<Inquire workstation state table lengths> should repor"
	    "t at least 20 entries as maximum size of text bundle table.", 5L, 
	    113L);
#else /* NO_PROTO */
    setmsg_("17 18", "<Inquire workstation state table lengths> should repor\
t at least 20 entries as maximum size of text bundle table.", 5L, 113L);
#endif /* NO_PROTO */
    L__1 = mtbe >= 20;
    ifpf_(&L__1);
    nqetxi (&globnu_1.wkid, &c__0, &errind, &nde, &idum1);
    chkinq_("pqetxi", &errind, 6L);
    mtxi = -9999;
    i__1 = nde;
    for (n = 1; n <= i__1; ++n) {
	nqetxi (&globnu_1.wkid, &n, &errind, &idum1, &txi);
	chkinq_("pqetxi", &errind, 6L);
	if (txi > mtxi) {
	    mtxi = txi;
	}
/* L100: */
    }
    nemp = mtbe - nde;
/*  nde  = number of defined entries */
/*  mtxi = maximum defined text index */
/*  nemp = number of empty entries */
#ifndef NO_PROTO
    setmsg_("17", "The program should be able to define additional text bund"
	    "le entries, up to the maximum.", 2L, 87L);
#else /* NO_PROTO */
    setmsg_("17", "The program should be able to define additional text bund\
le entries, up to the maximum.", 2L, 87L);
#endif /* NO_PROTO */
/*  set new entries */
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    i__1 = mtxi + nemp;
    for (txi = mtxi + 1; txi <= i__1; ++txi) {
	nstxr (&globnu_1.wkid, &txi, &c__1, &c__0, &c_b16, &c_b17, &c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___19);
	    do_fio(&c__1, "Unable to fill text bundle slot #", 33L);
	    i__2 = nde + txi - mtxi;
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
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

