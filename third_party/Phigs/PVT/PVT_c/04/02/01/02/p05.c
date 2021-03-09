/* fort/04/02/01/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b37 = 37.89f;
#else /* NO_PROTO */
static real c_b37 = (float)37.89;
#endif /* NO_PROTO */
static integer c__87 = 87;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.01.02/05                        * */
/*  *    TEST TITLE : WSL polyline bundles initialized      * */
/*  *                 properly                              * */
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
    address a__1[2];
    integer i__1[2], i__2;
    char ch__1[126], ch__2[139];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    integer s_wsfi(), do_fio(), e_wsfi(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer dci, npe, dlt, pli;
    static real dlw;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdci, pdlt;
    static real pdlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer spbt, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nclwk (
	    integer *), nqplf (integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *), nqwkc (
	    integer *, integer *, integer *, integer *), nqplr (integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nopwk (integer *, integer *, integer *), nsplr (integer *, 
	    integer *, integer *, real *, integer *), chkinq_(char *, integer 
	    *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nclwk (), nqplf (), 
	    nqwkc (), nqplr (), nopwk (), nsplr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, mplbte, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqepli (integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqepli ();
#endif /* NO_PROTO */
    static integer newent;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static char msgsuf[30];
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqpplr (
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqpplr (), nqwksl ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___14 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___22 = { 0, msg, 0, "(A,I5,A)", 300, 1 };


/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.01.02/05", 14L);
    s_copy(msgsuf, "opening workstation.", 30L, 20L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  perform loop twice - once for open, once for re-open */
L50:
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  npe = number of predefined entries in WDT */
    nqplf (&specwt, &c__0, &errind, &idum1, &idum2, &idum3, &rdum1, &rdum2, &
	    rdum3, &npe);
    chkinq_("pqplf", &errind, 5L);
/*   spbt = size of WSL polyline bundle table */
    nqepli (&globnu_1.wkid, &c__0, &errind, &spbt, &idum1);
    chkinq_("pqepli", &errind, 6L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 96, a__1[0] = "WSL polyline bundle table should be the same si"
	    "ze as the predefined polyline bundle table after ";
#else /* NO_PROTO */
    i__1[0] = 96, a__1[0] = "WSL polyline bundle table should be the same si\
ze as the predefined polyline bundle table after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 126L);
    setmsg_("24 25", ch__1, 5L, 126L);
    if (spbt != npe) {
	fail_();
	s_wsfi(&io___14);
	do_fio(&c__1, "PHIGS reported ", 15L);
	do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WDT predefined polyline bundles, but ", 38L);
	do_fio(&c__1, (char *)&spbt, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WSL polyline bundles.", 22L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 109, a__1[0] = "Each WSL polyline entry should have the same a"
	    "ttributes as the corresponding predefined polyline entry after ";
#else /* NO_PROTO */
    i__1[0] = 109, a__1[0] = "Each WSL polyline entry should have the same a\
ttributes as the corresponding predefined polyline entry after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__2, a__1, i__1, &c__2, 139L);
    setmsg_("20 23 24", ch__2, 8L, 139L);
    i__2 = min(npe,spbt);
    for (pli = 1; pli <= i__2; ++pli) {
/*  pdlt = predefined linetype */
/*  pdlw = predefined linewidth scale factor */
/*  pdci = predefined polyline color index */
	nqpplr (&specwt, &pli, &errind, &pdlt, &pdlw, &pdci);
	chkinq_("pqpplr", &errind, 6L);
/*  inquire defined attributes, as set */
/*  dlt = defined linetype */
/*  dlw = defined linewidth scale factor */
/*  dci = defined polyline color index */
/*    inquire as SET */
	nqplr (&globnu_1.wkid, &pli, &c__0, &errind, &dlt, &dlw, &dci);
	chkinq_("pqplr", &errind, 5L);
	if (dlt == pdlt && dlw == pdlw && dci == pdci) {
/*  OK so far - do nothing */
	} else {
	    fail_();
	    s_wsfi(&io___22);
	    do_fio(&c__1, "WSL polyline bundle #", 21L);
	    do_fio(&c__1, (char *)&pli, (ftnlen)sizeof(integer));
#ifndef NO_PROTO
	    do_fio(&c__1, " is not initialized from corresponding WDT predef"
		    "ined bundle.", 61L);
#else /* NO_PROTO */
	    do_fio(&c__1, " is not initialized from corresponding WDT predef\
ined bundle.", 61L);
#endif /* NO_PROTO */
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L110;
	}
/* L100: */
    }
    pass_();
L110:
/* now alter bundle table - either add entry or change it */
/* maximum number of polyline bundle table entries */
    nqwksl (&specwt, &errind, &mplbte, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (mplbte > spbt) {
/* room for additional entries */
	newent = spbt + 1;
    } else {
	newent = spbt;
    }
    nsplr (&globnu_1.wkid, &newent, &c__1, &c_b37, &c__87);
/* close workstation */
    nclwk (&globnu_1.wkid);
/* check if this is 2nd time thru */
    if (s_cmp(msgsuf, "opening workstation.", 30L, 20L) == 0) {
/* this is first time thru */
	s_copy(msgsuf, "re-opening workstation.", 30L, 23L);
	goto L50;
    }
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

