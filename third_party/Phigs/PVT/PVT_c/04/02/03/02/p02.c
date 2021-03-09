/* fort/04/02/03/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.03.02/02                        * */
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
    static integer aii, nie, dpi, mne, lui, txi, cnde;
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
    static integer mpai, coli, prec;
    static real chsp;
    static integer idum;
    static real chxp;
    static integer font;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer coli2, prec2;
    static real chsp2, chxp2;
    static integer font2, mcoli;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), unmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqwkc (), unmsg_();
#endif /* NO_PROTO */
    static integer vwtbi;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nqtxr (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, integer *), nstxr (integer *, integer *
	    , integer *, integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nqtxr (), nstxr ();
#endif /* NO_PROTO */
    static integer medbte, minbte;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, mplbte, mpmbte, specon, listel;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer mtxbte, specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqetxi (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqetxi ();
#endif /* NO_PROTO */
    static integer listot;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nqwksl (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nqwksl ();
#endif /* NO_PROTO */

/* define a number greater than the number of initialized text entries */
/* PHIGS parameter types */
/* used to control tests */
    initgl_("04.02.03.02/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &mplbte, &mpmbte, &mtxbte, &minbte, &medbte, &
	    mpai, &mcoli, &vwtbi);
    chkinq_("pqwksl", &errind, 6L);
/* maximum number of text bundle table entries */
    mne = mtxbte;
/* *** *** *** *** ***    initialized entries   *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("12", "<Inquire list of text indices> should return initialized "
	    "indices.", 2L, 65L);
#else /* NO_PROTO */
    setmsg_("12", "<Inquire list of text indices> should return initialized \
indices.", 2L, 65L);
#endif /* NO_PROTO */
/* <inquire list of text indices> to determine initialized entries */
/*   nie = number of initialized text entries */
/*   aii = an initialized index */
    nqetxi (&globnu_1.wkid, &c__1, &errind, &nie, &aii);
    if (errind != 0) {
	fail_();
	goto L200;
    } else {
	pass_();
    }
/* initialized_test: */
/* get initialized attributes */
    nqtxr (&globnu_1.wkid, &aii, &c__0, &errind, &font, &prec, &chxp, &chsp, &
	    coli);
    chkinq_("pqtxr", &errind, 5L);
/* set different values for attributes */
/* make sure font is valid */
    if (font == 1) {
	font2 = 2;
    } else {
	font2 = 1;
    }
/* make sure precision is valid */
    if (prec == 2) {
	prec2 = 0;
    } else {
	prec2 = 2;
    }
#ifndef NO_PROTO
    chxp2 = chxp + .5f;
    chsp2 = chsp + .25f;
#else /* NO_PROTO */
    chxp2 = chxp + (float).5;
    chsp2 = chsp + (float).25;
#endif /* NO_PROTO */
    coli2 = coli + 1;
    nstxr (&globnu_1.wkid, &aii, &font2, &prec2, &chxp2, &chsp2, &coli2);
/* get current number of defined entries */
    nqetxi (&globnu_1.wkid, &c__1, &errind, &cnde, &idum);
    chkinq_("pqetxi", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("10 12", "Redefining a system-initialized entry should not chang"
	    "e the number of defined entries.", 5L, 86L);
#else /* NO_PROTO */
    setmsg_("10 12", "Redefining a system-initialized entry should not chang\
e the number of defined entries.", 5L, 86L);
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
	nqetxi (&globnu_1.wkid, &listel, &errind, &idum, &txi);
	chkinq_("pqetxi", &errind, 6L);
	if (txi == aii) {
	    pass_();
	    goto L160;
	}
/* L150: */
    }
    fail_();
    goto L200;
L160:
    nqtxr (&globnu_1.wkid, &aii, &c__0, &errind, &font, &prec, &chxp, &chsp, &
	    coli);
    chkinq_("pqtxr", &errind, 5L);
    setmsg_("11 14", "New values should be set for initialized bundle entry.",
	     5L, 54L);
    L__1 = font == font2 && prec == prec2 && chxp == chxp2 && chsp == chsp2 &&
	     coli == coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    undefined entries   *** *** *** *** *** */
L200:
/* get lowest undefined index */
/* get current number defined entries */
    nqetxi (&globnu_1.wkid, &c__1, &errind, &cnde, &idum);
    chkinq_("pqetxi", &errind, 6L);
/* defi is originally an array of zeros */
    i__1 = cnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqetxi (&globnu_1.wkid, &listel, &errind, &idum, &txi);
	chkinq_("pqetxi", &errind, 6L);
/* mark as defined any index .le. cnde+1 */
/* This will leave at least one UNmarked. */
	if (txi <= cnde + 1) {
	    defi[txi - 1] = 1;
	}
/* L250: */
    }
/* first remaining zero indicates undefined entry */
    i__1 = cnde + 1;
    for (txi = 1; txi <= i__1; ++txi) {
	if (defi[txi - 1] == 0) {
/* determine lowest undefined index (not in defined list) = lui */

	    lui = txi;
	    goto L270;
	}
/* L260: */
    }
    unmsg_("Cannot find undefined index - error in test algorithm.", 54L);
/* established lui as lowest undefined index */
L270:
#ifndef NO_PROTO
    setmsg_("12 15 16", "<Inquire text representation> should return attribu"
	    "tes for bundle #1 when inquiring an undefined entry as REALIZED.",
	     8L, 115L);
#else /* NO_PROTO */
    setmsg_("12 15 16", "<Inquire text representation> should return attribu\
tes for bundle #1 when inquiring an undefined entry as REALIZED.", 8L, 115L);
#endif /* NO_PROTO */
/* inquire undefined bundle as REALIZED */
    nqtxr (&globnu_1.wkid, &lui, &c__1, &errind, &font, &prec, &chxp, &chsp, &
	    coli);
    chkinq_("pqtxr", &errind, 5L);
/* inquire bundle #1 as REALIZED */
    nqtxr (&globnu_1.wkid, &c__1, &c__1, &errind, &font2, &prec2, &chxp2, &
	    chsp2, &coli2);
    chkinq_("pqtxr", &errind, 5L);
/* should have same attributes */
    L__1 = font == font2 && prec == prec2 && chxp == chxp2 && chsp == chsp2 &&
	     coli == coli2;
    ifpf_(&L__1);
/*  If number of initialized entries >= implementation max then skip test 
*/
/*  of setting undefined entry - goto redefined_test. */
    if (nie >= mne) {
#ifndef NO_PROTO
	inmsg_("Skipping undefined-test because all text entries are initial"
		"ized.", 65L);
#else /* NO_PROTO */
	inmsg_("Skipping undefined-test because all text entries are initial\
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
    font2 = 1;
    prec2 = 1;
#ifndef NO_PROTO
    chxp2 = 1.75f;
    chsp2 = 0.f;
#else /* NO_PROTO */
    chxp2 = (float)1.75;
    chsp2 = (float)0.;
#endif /* NO_PROTO */
    coli2 = 5;
    nstxr (&globnu_1.wkid, &lui, &font2, &prec2, &chxp2, &chsp2, &coli2);
    nqetxi (&globnu_1.wkid, &c__1, &errind, &listot, &idum);
    chkinq_("pqetxi", &errind, 6L);
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
	nqetxi (&globnu_1.wkid, &listel, &errind, &idum, &txi);
	chkinq_("pqetxi", &errind, 6L);
	if (txi == lui) {
	    pass_();
	    goto L290;
	}
/* L280: */
    }
    fail_();
    goto L300;
L290:
    nqtxr (&globnu_1.wkid, &lui, &c__0, &errind, &font, &prec, &chxp, &chsp, &
	    coli);
    chkinq_("pqtxr", &errind, 5L);
    setmsg_("11 14", "New values should be set for undefined bundle entry.", 
	    5L, 52L);
    L__1 = font == font2 && prec == prec2 && chxp == chxp2 && chsp == chsp2 &&
	     coli == coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    redefined entries   *** *** *** *** *** */
L300:
/* get current number of defined entries */
    nqetxi (&globnu_1.wkid, &c__1, &errind, &cnde, &idum);
    chkinq_("pqetxi", &errind, 6L);
/* let dpi = a defined text index from middle of list */
    i__1 = (cnde + 1) / 2;
    nqetxi (&globnu_1.wkid, &i__1, &errind, &idum, &dpi);
    chkinq_("pqetxi", &errind, 6L);
/* set to first set of values */
    font = 2;
    prec = 0;
#ifndef NO_PROTO
    chxp = .75f;
    chsp = .2f;
#else /* NO_PROTO */
    chxp = (float).75;
    chsp = (float).2;
#endif /* NO_PROTO */
    coli = 4;
    nstxr (&globnu_1.wkid, &dpi, &font, &prec, &chxp, &chsp, &coli);
/* re-set to different values */
    font2 = 1;
    prec2 = 2;
#ifndef NO_PROTO
    chxp2 = 1.5f;
    chsp2 = .4f;
#else /* NO_PROTO */
    chxp2 = (float)1.5;
    chsp2 = (float).4;
#endif /* NO_PROTO */
    coli2 = 5;
    nstxr (&globnu_1.wkid, &dpi, &font2, &prec2, &chxp2, &chsp2, &coli2);
/* get list size - nnde = new number of defined entries */
    nqetxi (&globnu_1.wkid, &c__1, &errind, &nnde, &idum);
    chkinq_("pqetxi", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("10 12", "Redefining an entry should not change the number of de"
	    "fined entries.", 5L, 68L);
#else /* NO_PROTO */
    setmsg_("10 12", "Redefining an entry should not change the number of de\
fined entries.", 5L, 68L);
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
	nqetxi (&globnu_1.wkid, &listel, &errind, &idum, &txi);
	chkinq_("pqetxi", &errind, 6L);
	if (txi == dpi) {
	    pass_();
	    goto L330;
	}
/* L320: */
    }
    fail_();
    goto L399;
L330:
    nqtxr (&globnu_1.wkid, &dpi, &c__0, &errind, &font, &prec, &chxp, &chsp, &
	    coli);
    chkinq_("pqtxr", &errind, 5L);
    setmsg_("11 14", "New values should be set for redefined bundle entry.", 
	    5L, 52L);
    L__1 = font == font2 && prec == prec2 && chxp == chxp2 && chsp == chsp2 &&
	     coli == coli2;
    ifpf_(&L__1);
L399:
/* *** *** *** *** ***  access all defined entries  *** *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("12 13", "<Inquire list of text indices> and <inquire text repre"
	    "sentation> should detect all defined entries.", 5L, 99L);
#else /* NO_PROTO */
    setmsg_("12 13", "<Inquire list of text indices> and <inquire text repre\
sentation> should detect all defined entries.", 5L, 99L);
#endif /* NO_PROTO */
/* get listel-th element of defined text indices */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqetxi (&globnu_1.wkid, &listel, &errind, &idum, &txi);
	if (errind != 0) {
	    fail_();
	    goto L415;
	}
	nqtxr (&globnu_1.wkid, &txi, &c__0, &errind, &font, &prec, &chxp, &
		chsp, &coli);
	if (errind != 0) {
	    fail_();
	    goto L415;
	}
/* L410: */
    }
    pass_();
L415:
/* L666: */
/* wrap up it */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

