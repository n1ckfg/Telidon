/* fort/04/02/05/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__87 = 87;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/05                        * */
/*  *    TEST TITLE : WSL interior bundles initialized      * */
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
    static integer ii, dci, din, dsi, npe;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdci, pdin, pdsi;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer sibt;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), nqir (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nsir (
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), nqir (), nsir ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqeii (integer *, integer *, 
	    integer *, integer *, integer *), inmsg_(char *, ftnlen), nclwk (
	    integer *), nqwkc (integer *, integer *, integer *, integer *), 
	    nqpir (integer *, integer *, integer *, integer *, integer *, 
	    integer *), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqeii (), inmsg_(), nclwk (), 
	    nqwkc (), nqpir (), nopwk ();
#endif /* NO_PROTO */
    static integer minbte;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon, newent;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static char msgsuf[30];
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___12 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___20 = { 0, msg, 0, "(A,I5,A,A)", 300, 1 };


/* type of returned value */
/* interior style */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.02/05", 14L);
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
    nqif (&specwt, &c__0, &c__0, &errind, &idum1, &idum2, &idum3, &idum4, &
	    npe);
    chkinq_("pqif", &errind, 4L);
/*   sibt = size of WSL interior bundle table */
    nqeii (&globnu_1.wkid, &c__0, &errind, &sibt, &idum1);
    chkinq_("pqeii", &errind, 5L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 96, a__1[0] = "WSL interior bundle table should be the same si"
	    "ze as the predefined interior bundle table after ";
#else /* NO_PROTO */
    i__1[0] = 96, a__1[0] = "WSL interior bundle table should be the same si\
ze as the predefined interior bundle table after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 126L);
    setmsg_("25 26", ch__1, 5L, 126L);
    if (sibt != npe) {
	fail_();
	s_wsfi(&io___12);
	do_fio(&c__1, "PHIGS reported ", 15L);
	do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WDT predefined interior bundles, but ", 38L);
	do_fio(&c__1, (char *)&sibt, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WSL interior bundles.", 22L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 109, a__1[0] = "Each WSL interior entry should have the same a"
	    "ttributes as the corresponding predefined interior entry after ";
#else /* NO_PROTO */
    i__1[0] = 109, a__1[0] = "Each WSL interior entry should have the same a\
ttributes as the corresponding predefined interior entry after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__2, a__1, i__1, &c__2, 139L);
    setmsg_("21 24 25", ch__2, 8L, 139L);
    i__2 = min(npe,sibt);
    for (ii = 1; ii <= i__2; ++ii) {
/*  pdin = predefined interior style */
/*  pdsi = predefined interior style index */
/*  pdci   = predefined interior color index */
	nqpir (&specwt, &ii, &errind, &pdin, &pdsi, &pdci);
	chkinq_("pqpir", &errind, 5L);
/*  inquire defined attributes, as set */
/*  din = defined interior style */
/*  dsi = defined interior style index */
/*  dci = defined interior color index */
/*    inquire as SET */
	nqir (&globnu_1.wkid, &ii, &c__0, &errind, &din, &dsi, &dci);
	chkinq_("pqir", &errind, 4L);
	if (din == pdin && dsi == pdsi && dci == pdci) {
/*  OK so far - do nothing */
	} else {
	    fail_();
	    s_wsfi(&io___20);
	    do_fio(&c__1, "WSL interior bundle #", 21L);
	    do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " is not initialized from corresponding WDT ", 43L);

	    do_fio(&c__1, "predefined bundle.", 18L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L110;
	}
/* L100: */
    }
    pass_();
L110:
/* now alter bundle table - either add entry or change it */
/* maximum number of interior bundle table entries */
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &minbte, &idum4, &idum5,
	     &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (minbte > sibt) {
/* room for additional entries */
	newent = sibt + 1;
    } else {
	newent = sibt;
    }
    nsir (&globnu_1.wkid, &newent, &c__0, &c__1, &c__87);
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

