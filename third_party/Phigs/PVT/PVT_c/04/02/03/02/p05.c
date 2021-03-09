/* fort/04/02/03/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b40 = 2.3f;
static real c_b41 = 4.5f;
#else /* NO_PROTO */
static real c_b40 = (float)2.3;
static real c_b41 = (float)4.5;
#endif /* NO_PROTO */
static integer c__87 = 87;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.02/05                        * */
/*  *    TEST TITLE : WSL text bundles initialized          * */
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
    char ch__1[118], ch__2[131];

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
    static integer dci, dfn, npe, dpr;
    static real dsp;
    static char msg[300];
    static real dxp;
    static integer txi;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdci, pdfn, pdpr;
    static real pdsp;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer stbt;
    static real pdxp;
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nclwk (
	    integer *), nqwkc (integer *, integer *, integer *, integer *), 
	    nopwk (integer *, integer *, integer *), nqtxf (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, integer *, real *, real *, integer *), nqtxr (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, integer *), nstxr (integer *, integer *, integer *
	    , integer *, real *, real *, integer *), chkinq_(char *, integer *
	    , ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nclwk (), nqwkc (), 
	    nopwk (), nqtxf (), nqtxr (), nstxr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer newent;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer mtxbte;
    static char msgsuf[30];
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqetxi (integer *, integer *, integer *, 
	    integer *, integer *), xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nqptxr (integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqetxi (), xpopph_(), nqwksl (), nqptxr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___17 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___29 = { 0, msg, 0, "(A,I5,A,A)", 300, 1 };


/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.03.02/05", 14L);
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
    nqtxf (&specwt, &c__1, &errind, &idum1, &idum2, &idum3, &idum4, &rdum1, &
	    rdum2, &idum5, &rdum3, &rdum4, &npe);
    chkinq_("pqtxf", &errind, 5L);
/*   stbt = size of WSL text bundle table */
    nqetxi (&globnu_1.wkid, &c__0, &errind, &stbt, &idum1);
    chkinq_("pqetxi", &errind, 6L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 88, a__1[0] = "WSL text bundle table should be the same size a"
	    "s the predefined text bundle table after ";
#else /* NO_PROTO */
    i__1[0] = 88, a__1[0] = "WSL text bundle table should be the same size a\
s the predefined text bundle table after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 118L);
    setmsg_("24 25", ch__1, 5L, 118L);
    if (stbt != npe) {
	fail_();
	s_wsfi(&io___17);
	do_fio(&c__1, "PHIGS reported ", 15L);
	do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WDT predefined text bundles, but ", 34L);
	do_fio(&c__1, (char *)&stbt, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WSL text bundles.", 18L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 101, a__1[0] = "Each WSL text entry should have the same attri"
	    "butes as the corresponding predefined text entry after ";
#else /* NO_PROTO */
    i__1[0] = 101, a__1[0] = "Each WSL text entry should have the same attri\
butes as the corresponding predefined text entry after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__2, a__1, i__1, &c__2, 131L);
    setmsg_("20 23 24", ch__2, 8L, 131L);
    i__2 = min(npe,stbt);
    for (txi = 1; txi <= i__2; ++txi) {
/*  pdfn = predefined font */
/*  pdpr = predefined precision */
/*  pdxp = predefined character expansion factor */
/*  pdsp = predefined character spacing */
/*  pdci = predefined text color index */
	nqptxr (&specwt, &txi, &errind, &pdfn, &pdpr, &pdxp, &pdsp, &pdci);
	chkinq_("pqptxr", &errind, 6L);
/*  inquire defined attributes, as set */
/*  dfn = defined font */
/*  dpr = defined precision */
/*  dxp = defined character expansion factor */
/*  dsp = defined character spacing */
/*  dci = defined text color index */
/*    inquire as SET */
	nqtxr (&globnu_1.wkid, &txi, &c__0, &errind, &dfn, &dpr, &dxp, &dsp, &
		dci);
	chkinq_("pqtxr", &errind, 5L);
	if (dfn == pdfn && dpr == pdpr && dxp == pdxp && dsp == pdsp && dci ==
		 pdci) {
/*  OK so far - do nothing */
	} else {
	    fail_();
	    s_wsfi(&io___29);
	    do_fio(&c__1, "WSL text bundle #", 17L);
	    do_fio(&c__1, (char *)&txi, (ftnlen)sizeof(integer));
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
/* maximum number of text bundle table entries */
    nqwksl (&specwt, &errind, &idum1, &idum2, &mtxbte, &idum3, &idum4, &idum5,
	     &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (mtxbte > stbt) {
/* room for additional entries */
	newent = stbt + 1;
    } else {
	newent = stbt;
    }
    nstxr (&globnu_1.wkid, &newent, &c__1, &c__0, &c_b40, &c_b41, &c__87);
/* close workstation */
    nclwk (&globnu_1.wkid);
/* check if this is 2nd time thru */
    if (s_cmp(msgsuf, "opening workstation.", 30L, 20L) == 0) {
/* this is first time thru */
	s_copy(msgsuf, "re-opening workstation.", 30L, 23L);
	goto L50;
    }
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

