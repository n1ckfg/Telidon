/* fort/04/02/05/04/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__100 = 100;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.04/03                        * */
/*  *    TEST TITLE : Pattern table length                  * */
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
    static integer ii, nde, pai;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer mpai, mdpi, nemp, mpte;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7, colia[
	    10000]	/* was [100][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_();
#endif /* NO_PROTO */
    static logical nopat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nspar (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nopwk (
	    integer *, integer *, integer *), chkinq_(char *, integer *, 
	    ftnlen), nqepai (integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), nspar (), nopwk (), chkinq_(), 
	    nqepai ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern logical patavl_(integer *);
#else /* NO_PROTO */
    extern logical patavl_();
#endif /* NO_PROTO */
    static integer specon;
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
    static icilist io___21 = { 0, msg, 0, "(A,I6,A)", 300, 1 };


/* set up pattern color index array */
/* type of returned value */
/* interior style */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.04/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nopat = ! patavl_(&specwt);
    if (nopat) {
	inmsg_("Pattern interior style is not supported on this workstation.",
		 60L);
    }
    mpai = -6;
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &mpai, &
	    idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/* maximum number of pattern table entries */
    mpte = mpai;
/*  nde  = number of defined entries */
/*  mdpi = maximum defined pattern index */
/*  nemp = number of empty entries */
    if (nopat) {
#ifndef NO_PROTO
	setmsg_("8 9", "If PATTERN interior style is not supported, <inquire"
		" workstation state table lengths> should report 0 entries as"
		" maximum size of pattern table.", 3L, 143L);
#else /* NO_PROTO */
	setmsg_("8 9", "If PATTERN interior style is not supported, <inquire\
 workstation state table lengths> should report 0 entries as maximum size of\
 pattern table.", 3L, 143L);
#endif /* NO_PROTO */
	L__1 = mpte == 0;
	ifpf_(&L__1);
	goto L666;
    }
#ifndef NO_PROTO
    setmsg_("8 10", "If PATTERN interior style is supported, <inquire workst"
	    "ation state table lengths> should report at least 10 entries as "
	    "maximum size of pattern table.", 4L, 149L);
#else /* NO_PROTO */
    setmsg_("8 10", "If PATTERN interior style is supported, <inquire workst\
ation state table lengths> should report at least 10 entries as maximum size\
 of pattern table.", 4L, 149L);
#endif /* NO_PROTO */
    L__1 = mpte >= 10;
    ifpf_(&L__1);
    nqepai (&globnu_1.wkid, &c__0, &errind, &nde, &idum1);
    chkinq_("pqepai", &errind, 6L);
    mdpi = -9999;
    i__1 = nde;
    for (ii = 1; ii <= i__1; ++ii) {
	nqepai (&globnu_1.wkid, &ii, &errind, &idum1, &pai);
	chkinq_("pqepai", &errind, 6L);
	if (pai > mdpi) {
	    mdpi = pai;
	}
/* L100: */
    }
/* set up values for pattern color index array */
    colia[0] = 97;
    colia[1] = 5;
    colia[100] = 33;
    colia[101] = 53;
    nemp = mpte - nde;
#ifndef NO_PROTO
    setmsg_("8", "The program should be able to define additional pattern ta"
	    "ble entries, up to the maximum.", 1L, 89L);
#else /* NO_PROTO */
    setmsg_("8", "The program should be able to define additional pattern ta\
ble entries, up to the maximum.", 1L, 89L);
#endif /* NO_PROTO */
/*  set new entries */
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    i__1 = mdpi + nemp;
    for (pai = mdpi + 1; pai <= i__1; ++pai) {
	nspar (&globnu_1.wkid, &pai, &c__100, &c__100, &c__1, &c__1, &c__2, &
		c__2, colia);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___21);
	    do_fio(&c__1, "Unable to fill pattern table slot #", 35L);
	    i__2 = nde + pai - mdpi;
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
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

