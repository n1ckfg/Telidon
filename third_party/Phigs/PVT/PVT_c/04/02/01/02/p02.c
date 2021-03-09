/* fort/04/02/01/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.01.02/02                        * */
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
    static integer aii, nie, dpi, mne, pli, lui, cnde;
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
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_();
#endif /* NO_PROTO */
    static real lwdth;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc (), unmsg_();
#endif /* NO_PROTO */
    static integer vwtbi, ltype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqplr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nopwk (integer *, 
	    integer *, integer *), nsplr (integer *, integer *, integer *, 
	    real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqplr (), nopwk (), nsplr ();
#endif /* NO_PROTO */
    static real lwdth2;
    static integer ltype2, medbte, minbte;
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
    extern /* Subroutine */ int nqepli (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqepli ();
#endif /* NO_PROTO */
    static integer specwt, listot;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */

/* define a number greater than the number of initialized polyline entries
 */
/* PHIGS parameter types */
/* used to control tests */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.01.02/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &mplbte, &mpmbte, &mtxbte, &minbte, &medbte, &
	    mpai, &mcoli, &vwtbi);
    chkinq_("pqwksl", &errind, 6L);
/* maximum number of polyline bundle table entries */
    mne = mplbte;
/* *** *** *** *** ***    initialized entries   *** *** *** *** *** */
/* There should be at least 5 initialized polyline bundles - this */
/* inquiry gets the first, so it should work.  This statement */
/* is NOT meant to test the requirement of 5 initialized bundles; */
/* that is done elsewhere. */
#ifndef NO_PROTO
    setmsg_("12", "<Inquire list of polyline indices> should return initiali"
	    "zed indices.", 2L, 69L);
#else /* NO_PROTO */
    setmsg_("12", "<Inquire list of polyline indices> should return initiali\
zed indices.", 2L, 69L);
#endif /* NO_PROTO */
/*   nie = number of initialized polyline entries */
/*   aii = an initialized index (the first) */
    nqepli (&globnu_1.wkid, &c__1, &errind, &nie, &aii);
    if (errind != 0) {
	fail_();
	goto L200;
    } else {
	pass_();
    }
/* get initialized attributes */
    nqplr (&globnu_1.wkid, &aii, &c__0, &errind, &ltype, &lwdth, &coli);
    chkinq_("pqplr", &errind, 5L);
/* set different values for attributes */
/* make sure linetype is valid */
    if (ltype < 4) {
	ltype2 = ltype + 1;
    } else {
	ltype2 = 3;
    }
#ifndef NO_PROTO
    lwdth2 = lwdth * 1.5f;
#else /* NO_PROTO */
    lwdth2 = lwdth * (float)1.5;
#endif /* NO_PROTO */
    coli2 = coli + 1;
    nsplr (&globnu_1.wkid, &aii, &ltype2, &lwdth2, &coli2);
/* get current number of defined entries */
    nqepli (&globnu_1.wkid, &c__1, &errind, &cnde, &idum);
    chkinq_("pqepli", &errind, 6L);
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
	nqepli (&globnu_1.wkid, &listel, &errind, &idum, &pli);
	chkinq_("pqepli", &errind, 6L);
	if (pli == aii) {
	    pass_();
	    goto L160;
	}
/* L150: */
    }
    fail_();
    goto L200;
L160:
    nqplr (&globnu_1.wkid, &aii, &c__0, &errind, &ltype, &lwdth, &coli);
    chkinq_("pqplr", &errind, 5L);
    setmsg_("11 14", "New values should be set for initialized bundle entry.",
	     5L, 54L);
    L__1 = ltype == ltype2 && lwdth == lwdth2 && coli == coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    undefined entries   *** *** *** *** *** */
L200:
/* get lowest undefined index */
/* get current number defined entries */
    nqepli (&globnu_1.wkid, &c__1, &errind, &cnde, &idum);
    chkinq_("pqepli", &errind, 6L);
/* defi is originally an array of zeros */
    i__1 = cnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepli (&globnu_1.wkid, &listel, &errind, &idum, &pli);
	chkinq_("pqepli", &errind, 6L);
/* mark as defined any index .le. cnde+1 */
/* This will leave at least one UNmarked. */
	if (pli <= cnde + 1) {
	    defi[pli - 1] = 1;
	}
/* L250: */
    }
/* first remaining zero indicates undefined entry */
    i__1 = cnde + 1;
    for (pli = 1; pli <= i__1; ++pli) {
	if (defi[pli - 1] == 0) {
/* determine lowest undefined index (not in defined list) = lui */

	    lui = pli;
	    goto L270;
	}
/* L260: */
    }
    unmsg_("Cannot find undefined index - error in test algorithm.", 54L);
/* established lui as lowest undefined index */
L270:
#ifndef NO_PROTO
    setmsg_("12 15 16", "<Inquire polyline representation> should return att"
	    "ributes for bundle #1 when inquiring an undefined entry as REALI"
	    "ZED.", 8L, 119L);
#else /* NO_PROTO */
    setmsg_("12 15 16", "<Inquire polyline representation> should return att\
ributes for bundle #1 when inquiring an undefined entry as REALIZED.", 8L, 
	    119L);
#endif /* NO_PROTO */
/* inquire undefined bundle as REALIZED */
    nqplr (&globnu_1.wkid, &lui, &c__1, &errind, &ltype, &lwdth, &coli);
    chkinq_("pqplr", &errind, 5L);
/* inquire bundle #1 as REALIZED */
    nqplr (&globnu_1.wkid, &c__1, &c__1, &errind, &ltype2, &lwdth2, &coli2);
    chkinq_("pqplr", &errind, 5L);
/* should have same attributes */
    L__1 = ltype == ltype2 && lwdth == lwdth2 && coli == coli2;
    ifpf_(&L__1);
/*  If number of initialized entries >= implementation max then skip test 
*/
/*  of setting undefined entry - goto redefined_test. */
    if (nie >= mne) {
#ifndef NO_PROTO
	inmsg_("Skipping undefined-test because all polyline entries are ini"
		"tialized.", 69L);
#else /* NO_PROTO */
	inmsg_("Skipping undefined-test because all polyline entries are ini\
tialized.", 69L);
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
    ltype2 = 3;
#ifndef NO_PROTO
    lwdth2 = 4.f;
#else /* NO_PROTO */
    lwdth2 = (float)4.;
#endif /* NO_PROTO */
    coli2 = 5;
    nsplr (&globnu_1.wkid, &lui, &ltype2, &lwdth2, &coli2);
    nqepli (&globnu_1.wkid, &c__1, &errind, &listot, &idum);
    chkinq_("pqepli", &errind, 6L);
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
	nqepli (&globnu_1.wkid, &listel, &errind, &idum, &pli);
	chkinq_("pqepli", &errind, 6L);
	if (pli == lui) {
	    pass_();
	    goto L290;
	}
/* L280: */
    }
    fail_();
    goto L300;
L290:
    nqplr (&globnu_1.wkid, &lui, &c__0, &errind, &ltype, &lwdth, &coli);
    chkinq_("pqplr", &errind, 5L);
    setmsg_("11 14", "New values should be set for undefined bundle entry.", 
	    5L, 52L);
    L__1 = ltype == ltype2 && lwdth == lwdth2 && coli == coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    redefined entries   *** *** *** *** *** */
L300:
/* get current number defined entries */
    nqepli (&globnu_1.wkid, &c__1, &errind, &cnde, &idum);
    chkinq_("pqepli", &errind, 6L);
/* let dpi = a defined polyline index from middle of list */
    i__1 = (cnde + 1) / 2;
    nqepli (&globnu_1.wkid, &i__1, &errind, &idum, &dpi);
    chkinq_("pqepli", &errind, 6L);
/* set to first set of values */
    ltype = 2;
#ifndef NO_PROTO
    lwdth = 3.f;
#else /* NO_PROTO */
    lwdth = (float)3.;
#endif /* NO_PROTO */
    coli = 4;
    nsplr (&globnu_1.wkid, &dpi, &ltype, &lwdth, &coli);
/* re-set to different values */
    ltype2 = 3;
#ifndef NO_PROTO
    lwdth2 = 4.f;
#else /* NO_PROTO */
    lwdth2 = (float)4.;
#endif /* NO_PROTO */
    coli2 = 5;
    nsplr (&globnu_1.wkid, &dpi, &ltype2, &lwdth2, &coli2);
/* get list size - nnde = new number of defined entries */
    nqepli (&globnu_1.wkid, &c__1, &errind, &nnde, &idum);
    chkinq_("pqepli", &errind, 6L);
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
	nqepli (&globnu_1.wkid, &listel, &errind, &idum, &pli);
	chkinq_("pqepli", &errind, 6L);
	if (pli == dpi) {
	    pass_();
	    goto L330;
	}
/* L320: */
    }
    fail_();
    goto L399;
L330:
    nqplr (&globnu_1.wkid, &dpi, &c__0, &errind, &ltype, &lwdth, &coli);
    chkinq_("pqplr", &errind, 5L);
    setmsg_("11 14", "New values should be set for redefined bundle entry.", 
	    5L, 52L);
    L__1 = ltype == ltype2 && lwdth == lwdth2 && coli == coli2;
    ifpf_(&L__1);
L399:
/* *** *** *** *** ***  access all defined entries  *** *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("12 13", "<Inquire list of polyline indices> and <inquire polyli"
	    "ne representation> should detect all defined entries.", 5L, 107L);

#else /* NO_PROTO */
    setmsg_("12 13", "<Inquire list of polyline indices> and <inquire polyli\
ne representation> should detect all defined entries.", 5L, 107L);
#endif /* NO_PROTO */
/* get listel-th element of defined polyline indices */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqepli (&globnu_1.wkid, &listel, &errind, &idum, &pli);
	if (errind != 0) {
	    fail_();
	    goto L415;
	}
	nqplr (&globnu_1.wkid, &pli, &c__0, &errind, &ltype, &lwdth, &coli);
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

