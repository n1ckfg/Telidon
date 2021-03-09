/* fort/04/02/05/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/02                        * */
/*  *    TEST TITLE : Setting entries of various kinds      * */
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
    /* Initialized data */

    static integer defi[300] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
    static integer edi, aii, dei, nie, mne, lui, cnde;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer nnde;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer coli, naet, avet;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer coli2, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1, rdum2, rdum3;
    static integer eflag;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_();
#endif /* NO_PROTO */
    static real ewdth;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *), nsedr (
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    inmsg_(char *, ftnlen), nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedr (), nsedr (), inmsg_(), nqwkc ();
#endif /* NO_PROTO */
    static integer etype;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer eflag2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static real ewdth2;
    static integer etype2, medbte;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeedi (integer *, integer *, integer *, 
	    integer *, integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeedi (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, listel, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt, listot;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */

/* define a number greater than the number of initialized edge entries */
/* PHIGS parameter types */
/* type of returned value */
/* off/on switch for edge flag and error handling mode */
/* used to control tests */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.03/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &idum4, &medbte, &idum5,
	     &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/* maximum number of edge bundle table entries */
    mne = medbte;
/* *** *** *** *** ***    initialized entries   *** *** *** *** *** */
/* There should be at least 5 initialized edge bundles - this */
/* inquiry gets the first, so it should work.  This statement */
/* is NOT meant to test the requirement of 5 initialized bundles; */
/* that is done elsewhere. */
#ifndef NO_PROTO
    setmsg_("12", "<Inquire list of edge indices> should return initialized "
	    "indices.", 2L, 65L);
#else /* NO_PROTO */
    setmsg_("12", "<Inquire list of edge indices> should return initialized \
indices.", 2L, 65L);
#endif /* NO_PROTO */
/*   nie = number of initialized edge entries */
/*   aii = an initialized index (the first) */
    nqeedi (&globnu_1.wkid, &c__1, &errind, &nie, &aii);
    if (errind != 0) {
	fail_();
	goto L200;
    } else {
	pass_();
    }
/* get initialized attributes */
    nqedr (&globnu_1.wkid, &aii, &c__0, &errind, &eflag, &etype, &ewdth, &
	    coli);
    chkinq_("pqedr", &errind, 5L);
/* set different values for attributes */
/* make sure edgeflag is valid */
    if (eflag == 1) {
	eflag2 = 0;
    } else {
	eflag2 = 1;
    }
/*  get an available edgetype */
    nqedf (&specwt, &c__0, &errind, &naet, &idum1, &idum2, &rdum1, &rdum2, &
	    rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
    i__1 = (naet + 1) / 2;
    nqedf (&specwt, &i__1, &errind, &idum1, &avet, &idum2, &rdum1, &rdum2, &
	    rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
    if (etype != 1) {
	etype2 = 1;
    } else {
	etype2 = avet;
    }
#ifndef NO_PROTO
    ewdth2 = ewdth * 1.5f;
#else /* NO_PROTO */
    ewdth2 = ewdth * (float)1.5;
#endif /* NO_PROTO */
    coli2 = coli + 1;
    nsedr (&globnu_1.wkid, &aii, &eflag2, &etype2, &ewdth2, &coli2);
/* get current number of defined entries */
    nqeedi (&globnu_1.wkid, &c__0, &errind, &cnde, &idum1);
    chkinq_("pqeedi", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("10 12", "Re-defining a system-initialized entry should not chan"
	    "ge the number of defined entries.", 5L, 87L);
#else /* NO_PROTO */
    setmsg_("10 12", "Re-defining a system-initialized entry should not chan\
ge the number of defined entries.", 5L, 87L);
#endif /* NO_PROTO */
    L__1 = cnde == nie;
    ifpf_(&L__1);
/* check that aii is still among defined entries */
#ifndef NO_PROTO
    setmsg_("10 12", "Initialized bundle entry should be reported as defined"
	    " after being set.", 5L, 71L);
#else /* NO_PROTO */
    setmsg_("10 12", "Initialized bundle entry should be reported as defined\
 after being set.", 5L, 71L);
#endif /* NO_PROTO */
    i__1 = cnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeedi (&globnu_1.wkid, &listel, &errind, &idum1, &edi);
	chkinq_("pqeedi", &errind, 6L);
	if (edi == aii) {
	    pass_();
	    goto L160;
	}
/* L150: */
    }
    fail_();
    goto L200;
L160:
    nqedr (&globnu_1.wkid, &aii, &c__0, &errind, &eflag, &etype, &ewdth, &
	    coli);
    chkinq_("pqedr", &errind, 5L);
    setmsg_("11 14", "New values should be set for initialized bundle entry.",
	     5L, 54L);
    L__1 = eflag == eflag2 && etype == etype2 && ewdth == ewdth2 && coli == 
	    coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    undefined entries   *** *** *** *** *** */
L200:
/* get lowest undefined index */
/* get current number defined entries */
    nqeedi (&globnu_1.wkid, &c__0, &errind, &cnde, &idum1);
    chkinq_("pqeedi", &errind, 6L);
/* defi is originally an array of zeros */
    i__1 = cnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeedi (&globnu_1.wkid, &listel, &errind, &idum1, &edi);
	chkinq_("pqeedi", &errind, 6L);
/* mark as defined any index .le. cnde+1 */
/* This will leave at least one UNmarked. */
	if (edi <= cnde + 1) {
	    defi[edi - 1] = 1;
	}
/* L250: */
    }
/* first remaining zero indicates undefined entry */
    i__1 = cnde + 1;
    for (edi = 1; edi <= i__1; ++edi) {
	if (defi[edi - 1] == 0) {
/* determine lowest undefined index (not in defined list) = lui */

	    lui = edi;
	    goto L270;
	}
/* L260: */
    }
    unmsg_("Cannot find undefined index - error in test algorithm.", 54L);
/* established lui as lowest undefined index */
L270:
#ifndef NO_PROTO
    setmsg_("12 15 16", "<Inquire edge representation> should return attribu"
	    "tes for bundle #1 when inquiring an undefined entry as REALIZED.",
	     8L, 115L);
#else /* NO_PROTO */
    setmsg_("12 15 16", "<Inquire edge representation> should return attribu\
tes for bundle #1 when inquiring an undefined entry as REALIZED.", 8L, 115L);
#endif /* NO_PROTO */
/* inquire undefined bundle as REALIZED */
    nqedr (&globnu_1.wkid, &lui, &c__1, &errind, &eflag, &etype, &ewdth, &
	    coli);
    chkinq_("pqedr", &errind, 5L);
/* inquire bundle #1 as REALIZED */
    nqedr (&globnu_1.wkid, &c__1, &c__1, &errind, &eflag2, &etype2, &ewdth2, &
	    coli2);
    chkinq_("pqedr", &errind, 5L);
/* should have same attributes */
    L__1 = eflag == eflag2 && etype == etype2 && ewdth == ewdth2 && coli == 
	    coli2;
    ifpf_(&L__1);
/*  If number of initialized entries >= implementation max then skip test 
*/
/*  of setting undefined entry - goto redefined_test. */
    if (nie >= mne) {
#ifndef NO_PROTO
	inmsg_("Skipping undefined-test because all edge entries are initial"
		"ized.", 65L);
#else /* NO_PROTO */
	inmsg_("Skipping undefined-test because all edge entries are initial\
ized.", 65L);
#endif /* NO_PROTO */
	goto L300;
    }
/* Check that program allows enough room */
    if (nie >= 300) {
#ifndef NO_PROTO
	inmsg_("Skipping undefined-test because number of initialized entrie"
		"s exceed program limits.", 84L);
#else /* NO_PROTO */
	inmsg_("Skipping undefined-test because number of initialized entrie\
s exceed program limits.", 84L);
#endif /* NO_PROTO */
	goto L300;
    }
/* set values for attributes */
    eflag2 = 0;
    etype2 = 3;
#ifndef NO_PROTO
    ewdth2 = 4.f;
#else /* NO_PROTO */
    ewdth2 = (float)4.;
#endif /* NO_PROTO */
    coli2 = 5;
    nsedr (&globnu_1.wkid, &lui, &eflag2, &etype2, &ewdth2, &coli2);
    nqeedi (&globnu_1.wkid, &c__0, &errind, &listot, &idum1);
    chkinq_("pqeedi", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("10 12", "Defining an undefined entry should increment the numbe"
	    "r of defined entries.", 5L, 75L);
#else /* NO_PROTO */
    setmsg_("10 12", "Defining an undefined entry should increment the numbe\
r of defined entries.", 5L, 75L);
#endif /* NO_PROTO */
    L__1 = listot == cnde + 1;
    ifpf_(&L__1);
/* check that lui is now among defined entries */
#ifndef NO_PROTO
    setmsg_("10 12", "Undefined bundle entry should be reported as defined a"
	    "fter set.", 5L, 63L);
#else /* NO_PROTO */
    setmsg_("10 12", "Undefined bundle entry should be reported as defined a\
fter set.", 5L, 63L);
#endif /* NO_PROTO */
    i__1 = listot;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeedi (&globnu_1.wkid, &listel, &errind, &idum1, &edi);
	chkinq_("pqeedi", &errind, 6L);
	if (edi == lui) {
	    pass_();
	    goto L290;
	}
/* L280: */
    }
    fail_();
    goto L300;
L290:
    nqedr (&globnu_1.wkid, &lui, &c__0, &errind, &eflag, &etype, &ewdth, &
	    coli);
    chkinq_("pqedr", &errind, 5L);
    setmsg_("11 14", "New values should be set for undefined bundle entry.", 
	    5L, 52L);
    L__1 = eflag == eflag2 && etype == etype2 && ewdth == ewdth2 && coli == 
	    coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    redefined entries   *** *** *** *** *** */
L300:
/* get current number defined entries */
    nqeedi (&globnu_1.wkid, &c__0, &errind, &cnde, &idum1);
    chkinq_("pqeedi", &errind, 6L);
/* let dei = a defined edge index from middle of list */
    i__1 = (cnde + 1) / 2;
    nqeedi (&globnu_1.wkid, &i__1, &errind, &idum1, &dei);
    chkinq_("pqeedi", &errind, 6L);
/* set to first set of values */
    i__1 = (naet + 1) / 2;
    nqedf (&specwt, &i__1, &errind, &idum1, &etype, &idum2, &rdum1, &rdum2, &
	    rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
    eflag = 1;
#ifndef NO_PROTO
    ewdth = 3.f;
#else /* NO_PROTO */
    ewdth = (float)3.;
#endif /* NO_PROTO */
    coli = 4;
    nsedr (&globnu_1.wkid, &dei, &eflag, &etype, &ewdth, &coli);
/* re-set to different values */
    nqedf (&specwt, &naet, &errind, &idum1, &etype2, &idum2, &rdum1, &rdum2, &
	    rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
    eflag2 = 0;
#ifndef NO_PROTO
    ewdth2 = 4.f;
#else /* NO_PROTO */
    ewdth2 = (float)4.;
#endif /* NO_PROTO */
    coli2 = 5;
    nsedr (&globnu_1.wkid, &dei, &eflag2, &etype2, &ewdth2, &coli2);
/* get list size - nnde = new number of defined entries */
    nqeedi (&globnu_1.wkid, &c__0, &errind, &nnde, &idum1);
    chkinq_("pqeedi", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("10 12", "Re-defining a user-defined entry should not change num"
	    "ber of defined entries.", 5L, 77L);
#else /* NO_PROTO */
    setmsg_("10 12", "Re-defining a user-defined entry should not change num\
ber of defined entries.", 5L, 77L);
#endif /* NO_PROTO */
    L__1 = nnde == cnde;
    ifpf_(&L__1);
/* check that dei is among defined entries */
#ifndef NO_PROTO
    setmsg_("10 12", "Redefined bundle entry should be reported as defined a"
	    "fter set.", 5L, 63L);
#else /* NO_PROTO */
    setmsg_("10 12", "Redefined bundle entry should be reported as defined a\
fter set.", 5L, 63L);
#endif /* NO_PROTO */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeedi (&globnu_1.wkid, &listel, &errind, &idum1, &edi);
	chkinq_("pqeedi", &errind, 6L);
	if (edi == dei) {
	    pass_();
	    goto L330;
	}
/* L320: */
    }
    fail_();
    goto L399;
L330:
    nqedr (&globnu_1.wkid, &dei, &c__0, &errind, &eflag, &etype, &ewdth, &
	    coli);
    chkinq_("pqedr", &errind, 5L);
    setmsg_("11 14", "New values should be set for redefined bundle entry.", 
	    5L, 52L);
    L__1 = eflag == eflag2 && etype == etype2 && ewdth == ewdth2 && coli == 
	    coli2;
    ifpf_(&L__1);
L399:
/* *** *** *** ***   access all defined entries   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("12 13", "<Inquire list of edge indices> and <inquire edge repre"
	    "sentation> should detect all defined entries.", 5L, 99L);
#else /* NO_PROTO */
    setmsg_("12 13", "<Inquire list of edge indices> and <inquire edge repre\
sentation> should detect all defined entries.", 5L, 99L);
#endif /* NO_PROTO */
/* get listel-th element of defined edge indices */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeedi (&globnu_1.wkid, &listel, &errind, &idum1, &edi);
	if (errind != 0) {
	    fail_();
	    goto L415;
	}
	nqedr (&globnu_1.wkid, &edi, &c__0, &errind, &eflag, &etype, &ewdth, &
		coli);
	if (errind != 0) {
	    fail_();
	    goto L415;
	}
/* L410: */
    }
    pass_();
L415:
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

