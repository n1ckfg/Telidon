/* fort/04/02/05/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/03                        * */
/*  *    TEST TITLE : Interior bundle table length          * */
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
    static integer n, ii, nde, mii;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer mibe;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer nemp;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), nsir (integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), nsir ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqeii (integer *, integer *, 
	    integer *, integer *, integer *), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), nopwk (integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqeii (), inmsg_(), nqwkc (), 
	    nopwk ();
#endif /* NO_PROTO */
    static integer minbte;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), errctl_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), errctl_();
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


/* interior style */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.02/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &minbte, &idum4, &idum5,
	     &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/* maximum number of interior bundle table entries */
    mibe = minbte;
/*  nde  = number of defined entries */
/*  mii = maximum defined interior index */
/*  nemp = number of empty entries */
#ifndef NO_PROTO
    setmsg_("18 19", "<Inquire workstation state table lengths> should repor"
	    "t at least 20 entries as maximum size of interior bundle table.", 
	    5L, 117L);
#else /* NO_PROTO */
    setmsg_("18 19", "<Inquire workstation state table lengths> should repor\
t at least 20 entries as maximum size of interior bundle table.", 5L, 117L);
#endif /* NO_PROTO */
    L__1 = mibe >= 20;
    ifpf_(&L__1);
    nqeii (&globnu_1.wkid, &c__0, &errind, &nde, &idum1);
    chkinq_("pqeii", &errind, 5L);
    mii = -9999;
    i__1 = nde;
    for (n = 1; n <= i__1; ++n) {
	nqeii (&globnu_1.wkid, &n, &errind, &idum1, &ii);
	chkinq_("pqeii", &errind, 5L);
	if (ii > mii) {
	    mii = ii;
	}
/* L100: */
    }
    nemp = mibe - nde;
#ifndef NO_PROTO
    setmsg_("18", "The program should be able to define additional interior "
	    "bundle entries, up to the maximum.", 2L, 91L);
#else /* NO_PROTO */
    setmsg_("18", "The program should be able to define additional interior \
bundle entries, up to the maximum.", 2L, 91L);
#endif /* NO_PROTO */
/*  set new entries */
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    i__1 = mii + nemp;
    for (ii = mii + 1; ii <= i__1; ++ii) {
	nsir (&globnu_1.wkid, &ii, &c__0, &c__1, &c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___19);
	    do_fio(&c__1, "Unable to fill interior bundle slot #", 37L);
	    i__2 = nde + ii - mii;
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

