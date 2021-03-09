/* fort/04/03/04/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__4100 = 4100;
static integer c__50 = 50;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.04.01/02                        * */
/*  *    TEST TITLE : Nameset facilities                    * */
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
    integer i__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer rl, ix;
    static char msg[300];
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nads (integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nads ();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int nres (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nres ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, strl2[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer intar[4100];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqphf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     inmsg_(char *, ftnlen);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqphf (), inmsg_();
    extern logical seteq_();
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static char datrec[80*20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqceco ();
#endif /* NO_PROTO */
    static integer nanams;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, namset[4100];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___10 = { 0, msg, 0, "(A,I6)", 300, 1 };


    initgl_("04.03.04.01/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* <inquire PHIGS facilities> to determine */
/*  nanams = number of available names in namesets */
    nqphf (&c__1, &errind, &idum1, &idum2, &nanams, &idum3, &idum4, &idum5, &
	    idum6);
    chkinq_("pqphf", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("7 8", "The reported number of available names should be at leas"
	    "t 64.", 3L, 61L);
#else /* NO_PROTO */
    setmsg_("7 8", "The reported number of available names should be at leas\
t 64.", 3L, 61L);
#endif /* NO_PROTO */
    L__1 = nanams >= 64;
    ifpf_(&L__1);
    s_wsfi(&io___10);
    do_fio(&c__1, "Reported number of names = ", 27L);
    do_fio(&c__1, (char *)&nanams, (ftnlen)sizeof(integer));
    e_wsfi();
    inmsg_(msg, 300L);
    namset[0] = 0;
    namset[1] = nanams - 1;
    nopst (&c__1);
/*  <add names to set>: 0, nanams-1 */
    nads (&c__2, namset);
#ifndef NO_PROTO
    setmsg_("1 3 10", "<Inquire current element content> should return the s"
	    "tandard representation for add names to set when the operand inc"
	    "ludes the minimum and maximum allowed value for a name.", 6L, 
	    172L);
#else /* NO_PROTO */
    setmsg_("1 3 10", "<Inquire current element content> should return the s\
tandard representation for add names to set when the operand includes the mi\
nimum and maximum allowed value for a name.", 6L, 172L);
#endif /* NO_PROTO */
/*  <inquire current element content> to determine celcon */
    nqceco (&c__4100, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strl2, datrec, 80L);
    L__1 = errind == 0 && intg == 2 && seteq_(&c__2, intar, namset) && rl == 
	    0 && str == 0;
    ifpf_(&L__1);
    if (nanams > 4100) {
#ifndef NO_PROTO
	inmsg_("Number of available names is too large to allow testing of m"
		"aximum size nameset.", 80L);
#else /* NO_PROTO */
	inmsg_("Number of available names is too large to allow testing of m\
aximum size nameset.", 80L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  <remove names to set>: all names from 0 to nanams-1 */
    i__1 = nanams;
    for (ix = 1; ix <= i__1; ++ix) {
	namset[ix - 1] = nanams - ix;
/* L100: */
    }
    nres (&nanams, namset);
#ifndef NO_PROTO
    setmsg_("4 6 8 10", "<Inquire current element content> should return the"
	    " standard representation for remove names from set when the name"
	    "set contains the maximum number of names.", 8L, 156L);
#else /* NO_PROTO */
    setmsg_("4 6 8 10", "<Inquire current element content> should return the\
 standard representation for remove names from set when the nameset contains\
 the maximum number of names.", 8L, 156L);
#endif /* NO_PROTO */
/*  <inquire current element content> to determine celcon */
    nqceco (&c__4100, &c__50, &c__10, &errind, &intg, intar, &rl, rlar, &str, 
	    strl2, datrec, 80L);
    L__1 = errind == 0 && intg == nanams && seteq_(&nanams, intar, namset) && 
	    rl == 0 && str == 0;
    ifpf_(&L__1);
L666:
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

