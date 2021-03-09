/* fort/04/03/02/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b29 = 0.f;
static real c_b42 = .1f;
static real c_b43 = .9f;
#else /* NO_PROTO */
static real c_b29 = (float)0.;
static real c_b42 = (float).1;
static real c_b43 = (float).9;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/03                        * */
/*  *    TEST TITLE : WSL colour table initialized          * */
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
    char ch__1[108], ch__2[144];

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
    static integer ci;
    static real dcs[6];
    static integer npe;
    static char msg[300];
    static integer sct;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static real pdcs[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *), nqcr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf (), nqcr ();
#endif /* NO_PROTO */
    static real rdum[9];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), nscr (integer *, integer *, 
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), nscr ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci ();
#endif /* NO_PROTO */
    static integer mcoli;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
    extern /* Subroutine */ int inmsg_(), nclwk ();
#endif /* NO_PROTO */
    static integer ninit;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nqpcr (integer *, integer *, integer *, integer *, 
	    integer *, real *), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int nqwkc (), nqpcr (), nopwk ();
#endif /* NO_PROTO */
    static integer npredf;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
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
    static icilist io___11 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___17 = { 0, msg, 0, "(A,I5,A,A)", 300, 1 };


/* colour model */
/* NOTE:  INTEGER rather than enumeration type.  Explicitly defined and */

/* required portion of conceptually unbounded range defined here. */
/* colour available */
/* type of returned value */
    initgl_("04.03.02.02/03", 14L);
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
    nqcf (&specwt, &errind, &idum1, &idum2, &npe, rdum);
    chkinq_("pqcf", &errind, 4L);
/*   sct = size of WSL colour table */
    nqeci (&globnu_1.wkid, &c__0, &errind, &sct, &idum1);
    chkinq_("pqeci", &errind, 5L);
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 78, a__1[0] = "WSL colour table should be the same size as the"
	    " predefined colour table after ";
#else /* NO_PROTO */
    i__1[0] = 78, a__1[0] = "WSL colour table should be the same size as the\
 predefined colour table after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__1, a__1, i__1, &c__2, 108L);
    setmsg_("13 14", ch__1, 5L, 108L);
    if (sct != npe) {
	fail_();
	s_wsfi(&io___11);
	do_fio(&c__1, "PHIGS reported ", 15L);
	do_fio(&c__1, (char *)&npe, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WDT predefined colour indices, but ", 36L);
	do_fio(&c__1, (char *)&sct, (ftnlen)sizeof(integer));
	do_fio(&c__1, " WSL colour indices.", 20L);
	e_wsfi();
	inmsg_(msg, 300L);
    } else {
	pass_();
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__1[0] = 114, a__1[0] = "Each WSL colour index should have the same col"
	    "or specification as the corresponding predefined colour index af"
	    "ter ";
#else /* NO_PROTO */
    i__1[0] = 114, a__1[0] = "Each WSL colour index should have the same col\
or specification as the corresponding predefined colour index after ";
#endif /* NO_PROTO */
    i__1[1] = 30, a__1[1] = msgsuf;
    s_cat(ch__2, a__1, i__1, &c__2, 144L);
    setmsg_("9 10 13", ch__2, 7L, 144L);
    i__2 = min(npe,sct) - 1;
    for (ci = 0; ci <= i__2; ++ci) {
/*  pdcs(1-3) = predefined colour specification parameters */
	nqpcr (&specwt, &ci, &c__6, &errind, &npredf, pdcs);
	chkinq_("pqpcr", &errind, 5L);
/*  inquire defined attributes, as set */
/*  dcs(1-3)  = defined colour specification parameters */
/*  inquire as SET */
	nqcr (&globnu_1.wkid, &ci, &c__6, &c__0, &errind, &ninit, dcs);
	chkinq_("pqcr", &errind, 4L);
	if (npredf == ninit && rareq_(&npredf, dcs, pdcs, &c_b29, &c_b29)) {
/*  OK so far - do nothing */
	} else {
	    fail_();
	    s_wsfi(&io___17);
	    do_fio(&c__1, "WSL colour index #", 18L);
	    do_fio(&c__1, (char *)&ci, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " is not initialized from corresponding WDT ", 43L);

	    do_fio(&c__1, "predefined index.", 17L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L110;
	}
/* L100: */
    }
    pass_();
L110:
/* now alter colour table - either add entry or change it */
/* maximum number of colour bundle table entries */
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &idum6, 
	    &mcoli, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (mcoli > sct) {
/* room for additional entries */
	newent = sct;
    } else {
	newent = sct - 1;
    }
    i__2 = ninit;
    for (ci = 1; ci <= i__2; ++ci) {
	dcs[ci - 1] = rndrl_(&c_b42, &c_b43);
/* L300: */
    }
    nscr (&globnu_1.wkid, &newent, &ninit, dcs);
/* close workstation */
    nclwk (&globnu_1.wkid);
/* check if this is 2nd time thru */
    if (s_cmp(msgsuf, "opening workstation.", 30L, 20L) == 0) {
/* this is first time thru */
	s_copy(msgsuf, "re-opening workstation.", 30L, 23L);
	goto L50;
    }
/* L666: */
/* close PHIGS */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

