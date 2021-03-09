/* fort/04/02/05/03/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#else /* NO_PROTO */
static real c_b40 = (float)2.3;
#endif /* NO_PROTO */
static integer c__87 = 87;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/05                        * */
/*  *    TEST TITLE : WSL edge bundles initialized          * */
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
    static integer def, dci, edi, det;
    static real dew;
    static integer npe;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer pdef, pdci, pdet, sebt;
    static real pdew;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void), nqedr (integer *, integer *, integer *, integer *
	    , integer *, integer *, real *, integer *), inmsg_(char *, ftnlen)
	    , nsedr (integer *, integer *, integer *, integer *, real *, 
	    integer *), nclwk (integer *), nqwkc (integer *, integer *, 
	    integer *, integer *), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_(), nqedr (), inmsg_(), 
	    nsedr (), nclwk (), nqwkc (), nopwk ();
#endif /* NO_PROTO */
    static integer medbte;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeedi (integer *, integer *, integer *, 
	    integer *, integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeedi (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqpedr (integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqpedr ();
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
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___14 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___24 = { 0, msg, 0, "(A,I5,A)", 300, 1 };


/* off/on switch for edge flag and error handling mode */
/* type of returned value */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.03/05", 14L);
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
    nqedf (&specwt, &c__1, &errind, &idum1, &idum2, &idum3, &rdum1, &rdum2, &
	    rdum3, &npe);
    chkinq_("pqedf", &errind, 5L);
/*   sebt = size of WSL edge bundle table */
    nqeedi (&globnu_1.wkid, &c__0, &errind, &sebt, &idum1);
    chkinq_("pqeedi", &errind, 6L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 88, a__1[0] = "WSL edge bundle table should be the same size a"
	    "s the predefined edge bundle table after ";
#else /* NO_PROTO */
    i__1[0] = 88, a__1[0] = "WSL edge bundle table should be the same size a\
s the predefined edge bundle table after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 118L);
    setmsg_("24 25", ch__1, 5L, 118L);
    if (sebt != npe) {
	fail_();
	s_wsfi(&io___14);
	do_fio(&c__1, "PHIGS reported ", 15L);
	do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WDT predefined edge bundles, but ", 34L);
	do_fio(&c__1, (char *)&sebt, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WSL edge bundles.", 18L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 101, a__1[0] = "Each WSL edge entry should have the same attri"
	    "butes as the corresponding predefined edge entry after ";
#else /* NO_PROTO */
    i__1[0] = 101, a__1[0] = "Each WSL edge entry should have the same attri\
butes as the corresponding predefined edge entry after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__2, a__1, i__1, &c__2, 131L);
    setmsg_("20 23 24", ch__2, 8L, 131L);
    i__2 = min(npe,sebt);
    for (edi = 1; edi <= i__2; ++edi) {
/*  pdef = predefined edge flag */
/*  pdet = predefined edgetype */
/*  pdew = predefined edgewidth scale factor */
/*  pdci = predefined edge color index */
	nqpedr (&specwt, &edi, &errind, &pdef, &pdet, &pdew, &pdci);
	chkinq_("pqpedr", &errind, 6L);
/*  inquire defined attributes, as set */
/*  def = defined edge flag */
/*  det = defined edgetype */
/*  dew = defined edgewidth scale factor */
/*  dci = defined edge color index */
/*    inquire as SET */
	nqedr (&globnu_1.wkid, &edi, &c__0, &errind, &def, &det, &dew, &dci);
	chkinq_("pqedr", &errind, 5L);
	if (def == pdef && det == pdet && dew == pdew && dci == pdci) {
/*  OK so far - do nothing */
	} else {
	    fail_();
	    s_wsfi(&io___24);
	    do_fio(&c__1, "WSL edge bundle #", 17L);
	    do_fio(&c__1, (char *)&edi, (ftnlen)sizeof(integer));
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
/* maximum number of edge bundle table entries */
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &medbte, &idum5,
	     &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (medbte > sebt) {
/* room for additional entries */
	newent = sebt + 1;
    } else {
	newent = sebt;
    }
    nsedr (&globnu_1.wkid, &newent, &c__0, &c__1, &c_b40, &c__87);
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

