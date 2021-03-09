/* fort/04/02/02/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.02.02/02                        * */
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
    static integer aii, nie, dpi, mne, pmi, lui, cnde;
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
    static integer mpai, coli, idum;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer coli2, mcoli;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), unmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc (), unmsg_();
#endif /* NO_PROTO */
    static integer vwtbi, mtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nspmr (integer *, integer *, integer *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmr (), nopwk (), nspmr ();
#endif /* NO_PROTO */
    static real mszsf;
    static integer mtype2;
    static real mszsf2;
    static integer medbte, minbte;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, mplbte, mpmbte, listel, specon;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer mtxbte;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqepmi (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqepmi ();
#endif /* NO_PROTO */
    static integer specwt, listot;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */

/*define a number greater than the number of initialized polymarker entrie
s*/
/* PHIGS parameter types */
/* type of returned value */
/* used to control tests */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.02.02/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqkwc", &errind, 5L);
    nqwksl (&specwt, &errind, &mplbte, &mpmbte, &mtxbte, &minbte, &medbte, &
	    mpai, &mcoli, &vwtbi);
    chkinq_("pqwksl", &errind, 6L);
/* maximum number of polymarker bundle table entries */
    mne = mpmbte;
/* *** *** *** *** ***    initialized entries   *** *** *** *** *** */
/* There should be at least 5 initialized polymarker bundles - this */
/* inquiry gets the first, so it should work.  This statement */
/* is NOT meant to test the requirement of 5 initialized bundles; */
/* that is done elsewhere. */
#ifndef NO_PROTO
    setmsg_("12", "<Inquire list of polymarker indices> should return initia"
	    "lized indices.", 2L, 71L);
#else /* NO_PROTO */
    setmsg_("12", "<Inquire list of polymarker indices> should return initia\
lized indices.", 2L, 71L);
#endif /* NO_PROTO */
/*   nie = number of initialized polymarker entries */
/*   aii = an initialized index (the first) */
    nqepmi (&globnu_1.wkid, &c__1, &errind, &nie, &aii);
    if (errind != 0) {
	fail_();
	goto L200;
    } else {
	pass_();
    }
/* get initialized attributes */
    nqpmr (&globnu_1.wkid, &aii, &c__0, &errind, &mtype, &mszsf, &coli);
    chkinq_("pqpmr", &errind, 5L);
/* set different values for attributes */
/* make sure marker type is valid */
    if (mtype < 5) {
	mtype2 = mtype + 1;
    } else {
	mtype2 = 2;
    }
#ifndef NO_PROTO
    mszsf2 = mszsf * .15f;
#else /* NO_PROTO */
    mszsf2 = mszsf * (float).15;
#endif /* NO_PROTO */
    coli2 = coli + 1;
    nspmr (&globnu_1.wkid, &aii, &mtype2, &mszsf2, &coli2);
/* get current number of defined entries */
    nqepmi (&globnu_1.wkid, &c__1, &errind, &cnde, &idum);
    chkinq_("pqepmi", &errind, 6L);
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
    i__1 = nie;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepmi (&globnu_1.wkid, &listel, &errind, &idum, &pmi);
	chkinq_("pqepmi", &errind, 6L);
	if (pmi == aii) {
	    pass_();
	    goto L160;
	}
/* L150: */
    }
    fail_();
    goto L200;
L160:
    nqpmr (&globnu_1.wkid, &aii, &c__0, &errind, &mtype, &mszsf, &coli);
    chkinq_("pqpmr", &errind, 5L);
    setmsg_("11 14", "New values should be set for initialized bundle entry.",
	     5L, 54L);
    L__1 = mtype == mtype2 && mszsf == mszsf2 && coli == coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    undefined entries   *** *** *** *** *** */
L200:
/* get lowest undefined index */
/* get current number of defined entries */
    nqepmi (&globnu_1.wkid, &c__1, &errind, &cnde, &idum);
    chkinq_("pqepmi", &errind, 6L);
/* defi is originally an array of zeros */
    i__1 = cnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepmi (&globnu_1.wkid, &listel, &errind, &idum, &pmi);
	chkinq_("pqepmi", &errind, 6L);
/* mark as defined any index .le. cnde+1 */
/* This will leave at least one UNmarked. */
	if (pmi <= cnde + 1) {
	    defi[pmi - 1] = 1;
	}
/* L250: */
    }
/* first remaining zero indicates undefined entry */
    i__1 = cnde + 1;
    for (pmi = 1; pmi <= i__1; ++pmi) {
	if (defi[pmi - 1] == 0) {
/* determine lowest undefined index (not in defined list) = lui */

	    lui = pmi;
	    goto L270;
	}
/* L260: */
    }
    unmsg_("Cannot find undefined index - error in test algorithm.", 54L);
/* established lui as lowest undefined index */
L270:
#ifndef NO_PROTO
    setmsg_("12 15 16", "<Inquire polymarker representation> should return a"
	    "ttributes for bundle #1 when inquiring an undefined entry as REA"
	    "LIZED.", 8L, 121L);
#else /* NO_PROTO */
    setmsg_("12 15 16", "<Inquire polymarker representation> should return a\
ttributes for bundle #1 when inquiring an undefined entry as REALIZED.", 8L, 
	    121L);
#endif /* NO_PROTO */
/* inquire undefined bundle as REALIZED */
    nqpmr (&globnu_1.wkid, &lui, &c__1, &errind, &mtype, &mszsf, &coli);
    chkinq_("pqpmr", &errind, 5L);
/* inquire bundle #1 as REALIZED */
    nqpmr (&globnu_1.wkid, &c__1, &c__1, &errind, &mtype2, &mszsf2, &coli2);
    chkinq_("pqpmr", &errind, 5L);
/* should have same attributes */
    L__1 = mtype == mtype2 && mszsf == mszsf2 && coli == coli2;
    ifpf_(&L__1);
/*  If number of initialized entries >= implementation max then skip test 
*/
/*  of setting undefined entry - goto redefined_test. */
    if (nie >= mne) {
#ifndef NO_PROTO
	inmsg_("Skipping undefined-test because all polymarker entries are i"
		"nitialized.", 71L);
#else /* NO_PROTO */
	inmsg_("Skipping undefined-test because all polymarker entries are i\
nitialized.", 71L);
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
    mtype2 = 2;
#ifndef NO_PROTO
    mszsf2 = .25f;
#else /* NO_PROTO */
    mszsf2 = (float).25;
#endif /* NO_PROTO */
    coli2 = 4;
    nspmr (&globnu_1.wkid, &lui, &mtype2, &mszsf2, &coli2);
    nqepmi (&globnu_1.wkid, &c__1, &errind, &listot, &idum);
    chkinq_("pqepmi", &errind, 6L);
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
	nqepmi (&globnu_1.wkid, &listel, &errind, &idum, &pmi);
	chkinq_("pqepmi", &errind, 6L);
	if (pmi == lui) {
	    pass_();
	    goto L290;
	}
/* L280: */
    }
    fail_();
    goto L300;
L290:
    nqpmr (&globnu_1.wkid, &lui, &c__0, &errind, &mtype, &mszsf, &coli);
    chkinq_("pqpmr", &errind, 5L);
    setmsg_("11 14", "New values should be set for undefined bundle entry.", 
	    5L, 52L);
    L__1 = mtype == mtype2 && mszsf == mszsf2 && coli == coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    redefined entries   *** *** *** *** *** */
L300:
/* get current number defined entries */
    nqepmi (&globnu_1.wkid, &c__1, &errind, &cnde, &idum);
    chkinq_("pqepmi", &errind, 6L);
/* let dpi = a defined polymarker index from middle of list */
    i__1 = (cnde + 1) / 2;
    nqepmi (&globnu_1.wkid, &i__1, &errind, &idum, &dpi);
    chkinq_("pqepmi", &errind, 6L);
/* set to first set of values */
    mtype = 4;
#ifndef NO_PROTO
    mszsf = .35f;
#else /* NO_PROTO */
    mszsf = (float).35;
#endif /* NO_PROTO */
    coli = 3;
    nspmr (&globnu_1.wkid, &dpi, &mtype, &mszsf, &coli);
/* re-set to different values */
    mtype2 = 3;
#ifndef NO_PROTO
    mszsf2 = .4f;
#else /* NO_PROTO */
    mszsf2 = (float).4;
#endif /* NO_PROTO */
    coli2 = 2;
    nspmr (&globnu_1.wkid, &dpi, &mtype2, &mszsf2, &coli2);
/* get list size - nnde = new number of defined entries */
    nqepmi (&globnu_1.wkid, &c__1, &errind, &nnde, &idum);
    chkinq_("pqepmi", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("10 12", "Re-defining a user-defined entry should not change num"
	    "ber of defined entries.", 5L, 77L);
#else /* NO_PROTO */
    setmsg_("10 12", "Re-defining a user-defined entry should not change num\
ber of defined entries.", 5L, 77L);
#endif /* NO_PROTO */
    L__1 = nnde == cnde;
    ifpf_(&L__1);
/* check that dpi is among defined entries */
#ifndef NO_PROTO
    setmsg_("10 12", "Redefined bundle entry should be reported as defined a"
	    "fter set.", 5L, 63L);
#else /* NO_PROTO */
    setmsg_("10 12", "Redefined bundle entry should be reported as defined a\
fter set.", 5L, 63L);
#endif /* NO_PROTO */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepmi (&globnu_1.wkid, &listel, &errind, &idum, &pmi);
	chkinq_("pqepmi", &errind, 6L);
	if (pmi == dpi) {
	    pass_();
	    goto L330;
	}
/* L320: */
    }
    fail_();
    goto L399;
L330:
    nqpmr (&globnu_1.wkid, &dpi, &c__0, &errind, &mtype, &mszsf, &coli);
    chkinq_("pqpmr", &errind, 5L);
    setmsg_("11 14", "New values should be set for redefined bundle entry.", 
	    5L, 52L);
    L__1 = mtype == mtype2 && mszsf == mszsf2 && coli == coli2;
    ifpf_(&L__1);
L399:
/* *** *** *** *** ***  access all defined entries  *** *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("12 13", "<Inquire list of polymarker indices> and <inquire poly"
	    "marker representation> should detect all defined entries.", 5L, 
	    111L);
#else /* NO_PROTO */
    setmsg_("12 13", "<Inquire list of polymarker indices> and <inquire poly\
marker representation> should detect all defined entries.", 5L, 111L);
#endif /* NO_PROTO */
/* get listel-th element of defined polymarker indices */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepmi (&globnu_1.wkid, &listel, &errind, &idum, &pmi);
	if (errind != 0) {
	    fail_();
	    goto L415;
	}
	nqpmr (&globnu_1.wkid, &pmi, &c__0, &errind, &mtype, &mszsf, &coli);
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

