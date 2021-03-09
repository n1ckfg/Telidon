/* fort/04/02/02/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b37 = 37.89f;
#else /* NO_PROTO */
static real c_b37 = (float)37.89;
#endif /* NO_PROTO */
static integer c__87 = 87;
#ifndef NO_PROTO
static real c_b40 = 17.89f;
#else /* NO_PROTO */
static real c_b40 = (float)17.89;
#endif /* NO_PROTO */
static integer c__27 = 27;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.02/05                        * */
/*  *    TEST TITLE : WSL polymarker bundles initialized    * */
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
    char ch__1[130], ch__2[143];

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
    static integer dci, npe;
    static real dms;
    static integer pmi, dmt;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdci;
    static real pdms;
    static integer pdmt;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer spbt, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nclwk (
	    integer *), nqpmf (integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *), nqwkc (
	    integer *, integer *, integer *, integer *), nqpmr (integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nopwk (integer *, integer *, integer *), nspmr (integer *, 
	    integer *, integer *, real *, integer *), chkinq_(char *, integer 
	    *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nclwk (), nqpmf (), 
	    nqwkc (), nqpmr (), nopwk (), nspmr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, mpmbte, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqepmi (integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqepmi ();
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
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqppmr (
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqppmr (), nqwksl ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___14 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___22 = { 0, msg, 0, "(A,I5,A)", 300, 1 };


/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.02.02/05", 14L);
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
    nqpmf (&specwt, &c__1, &errind, &idum1, &idum2, &idum3, &rdum1, &rdum2, &
	    rdum3, &npe);
    chkinq_("pqpmf", &errind, 5L);
/*   spbt = size of WSL polymarker bundle table */
    nqepmi (&globnu_1.wkid, &c__1, &errind, &spbt, &idum1);
    chkinq_("pqepmi", &errind, 6L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 100, a__1[0] = "WSL polymarker bundle table should be the same"
	    " size as the predefined polymarker bundle table after ";
#else /* NO_PROTO */
    i__1[0] = 100, a__1[0] = "WSL polymarker bundle table should be the same\
 size as the predefined polymarker bundle table after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 130L);
    setmsg_("24 25", ch__1, 5L, 130L);
    if (spbt != npe) {
	fail_();
	s_wsfi(&io___14);
	do_fio(&c__1, "PHIGS reported ", 15L);
	do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WDT predefined polymarker bundles, but ", 40L);
	do_fio(&c__1, (char *)&spbt, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WSL polymarker bundles.", 24L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 113, a__1[0] = "Each WSL polymarker entry should have the same"
	    " attributes as the corresponding predefined polymarker entry aft"
	    "er ";
#else /* NO_PROTO */
    i__1[0] = 113, a__1[0] = "Each WSL polymarker entry should have the same\
 attributes as the corresponding predefined polymarker entry after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__2, a__1, i__1, &c__2, 143L);
    setmsg_("20 23 24", ch__2, 8L, 143L);
    i__2 = min(npe,spbt);
    for (pmi = 1; pmi <= i__2; ++pmi) {
/*  pdmt = predefined marker type */
/*  pdms = predefined marker size scale factor */
/*  pdci = predefined polymarker color index */
	nqppmr (&specwt, &pmi, &errind, &pdmt, &pdms, &pdci);
	chkinq_("pqppmr", &errind, 6L);
/* inquire defined attributes, as set */
/*  dmt = defined marker type */
/*  dms = defined marker size scale factor */
/*  dci = defined polymarker color index */
/*   inquire as SET */
	nqpmr (&globnu_1.wkid, &pmi, &c__0, &errind, &dmt, &dms, &dci);
	chkinq_("pqpmr", &errind, 5L);
	if (dmt == pdmt && dms == pdms && dci == pdci) {
/*  OK so far - do nothing */
	} else {
	    fail_();
	    s_wsfi(&io___22);
	    do_fio(&c__1, "WSL polymarker bundle #", 23L);
	    do_fio(&c__1, (char *)&pmi, (ftnlen)sizeof(integer));
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
/* maximum number of polymarker bundle table entries */
    nqwksl (&specwt, &errind, &idum1, &mpmbte, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (mpmbte > spbt) {
/* room for additional entries */
	newent = spbt + 1;
	nspmr (&globnu_1.wkid, &newent, &c__1, &c_b37, &c__87);
    }
    newent = spbt;
    nspmr (&globnu_1.wkid, &newent, &c__2, &c_b40, &c__27);
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

