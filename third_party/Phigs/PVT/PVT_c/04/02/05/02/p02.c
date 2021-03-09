/* fort/04/02/05/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.05.02/02                        * */
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
    static integer ii, aii, dii, nie, mne, lui, cnde;
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
    extern /* Subroutine */ int pass_(void), nqir (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), nqir ();
#endif /* NO_PROTO */
    static integer ints;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsir (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsir ();
#endif /* NO_PROTO */
    static integer coli2, idum1, idum2, idum3, idum4, idum5, ints2, mcoli;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqeii (integer *, integer *, 
	    integer *, integer *, integer *), inmsg_(char *, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), unmsg_(char *, 
	    ftnlen), nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqeii (), inmsg_(), nqwkc (), 
	    unmsg_(), nopwk ();
#endif /* NO_PROTO */
    static integer styli, styli2, minbte;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
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

/* define a number greater than the number of initialized text entries */
/* PHIGS parameter types */
/* type of returned value */
/* interior style */
/* used to control tests */
/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.05.02/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqwksl (&specwt, &errind, &idum1, &idum2, &idum3, &minbte, &idum4, &mpai, 
	    &mcoli, &idum5);
    chkinq_("pqwksl", &errind, 6L);
/* maximum number of interior bundle table entries */
    mne = minbte;
/* *** *** *** *** ***    initialized entries   *** *** *** *** *** */
/* There should be at least 5 initialized interior bundles - this */
/* inquiry gets the first, so it should work.  This statement */
/* is NOT meant to test the requirement of 5 initialized bundles; */
/* that is done elsewhere. */
#ifndef NO_PROTO
    setmsg_("13", "<Inquire list of interior indices> should return initiali"
	    "zed indices.", 2L, 69L);
#else /* NO_PROTO */
    setmsg_("13", "<Inquire list of interior indices> should return initiali\
zed indices.", 2L, 69L);
#endif /* NO_PROTO */
/*   nie = number of initialized interior entries */
/*   aii = an initialized index (the first) */
    nqeii (&globnu_1.wkid, &c__1, &errind, &nie, &aii);
    if (errind != 0) {
	fail_();
	goto L200;
    } else {
	pass_();
    }
/* get initialized attributes */
    nqir (&globnu_1.wkid, &aii, &c__0, &errind, &ints, &styli, &coli);
    chkinq_("pqir", &errind, 4L);
/* set different values for attributes */
/* make sure style is valid */
    if (ints == 0) {
	ints2 = 4;
    } else {
	ints2 = 0;
    }
    styli2 = styli + 1;
    coli2 = coli + 1;
    nsir (&globnu_1.wkid, &aii, &ints2, &styli2, &coli2);
/* get current number of defined entries */
    nqeii (&globnu_1.wkid, &c__0, &errind, &cnde, &idum);
    chkinq_("pqeii", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("11 13", "Redefining a system-initialized entry should not chang"
	    "e the number of defined entries.", 5L, 86L);
#else /* NO_PROTO */
    setmsg_("11 13", "Redefining a system-initialized entry should not chang\
e the number of defined entries.", 5L, 86L);
#endif /* NO_PROTO */
    L__1 = cnde == nie;
    ifpf_(&L__1);
/* check that aii is still among defined entries */
#ifndef NO_PROTO
    setmsg_("11 13", "Initialized bundle entry should be reported as defined"
	    " after being set.", 5L, 71L);
#else /* NO_PROTO */
    setmsg_("11 13", "Initialized bundle entry should be reported as defined\
 after being set.", 5L, 71L);
#endif /* NO_PROTO */
    i__1 = nie;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeii (&globnu_1.wkid, &listel, &errind, &idum, &ii);
	chkinq_("pqeii", &errind, 5L);
	if (ii == aii) {
	    pass_();
	    goto L160;
	}
/* L150: */
    }
    fail_();
    goto L200;
L160:
    nqir (&globnu_1.wkid, &aii, &c__0, &errind, &ints, &styli, &coli);
    chkinq_("pqir", &errind, 4L);
    setmsg_("12 15", "New values should be set for initialized bundle entry.",
	     5L, 54L);
    L__1 = ints == ints2 && styli == styli2 && coli == coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    undefined entries   *** *** *** *** *** */
L200:
/* get lowest undefined index */
/* get current number defined entries */
    nqeii (&globnu_1.wkid, &c__0, &errind, &cnde, &idum);
    chkinq_("pqeii", &errind, 5L);
/* defi is originally an array of zeros */
    i__1 = cnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeii (&globnu_1.wkid, &listel, &errind, &idum, &ii);
	chkinq_("pqeii", &errind, 5L);
/* mark as defined any index .le. cnde+1 */
/* This will leave at least one UNmarked. */
	if (ii <= cnde + 1) {
	    defi[ii - 1] = 1;
	}
/* L250: */
    }
/* first remaining zero indicates undefined entry */
    i__1 = cnde + 1;
    for (ii = 1; ii <= i__1; ++ii) {
	if (defi[ii - 1] == 0) {
/* determine lowest undefined index (not in defined list) = lui */

	    lui = ii;
	    goto L270;
	}
/* L260: */
    }
    unmsg_("Cannot find undefined index - error in test algorithm.", 54L);
/* established lui as lowest undefined index */
L270:
#ifndef NO_PROTO
    setmsg_("13 16 17", "<Inquire interior representation> should return att"
	    "ributes for bundle #1 when inquiring an undefined entry as REALI"
	    "ZED.", 8L, 119L);
#else /* NO_PROTO */
    setmsg_("13 16 17", "<Inquire interior representation> should return att\
ributes for bundle #1 when inquiring an undefined entry as REALIZED.", 8L, 
	    119L);
#endif /* NO_PROTO */
/* inquire undefined bundle as REALIZED */
    nqir (&globnu_1.wkid, &lui, &c__1, &errind, &ints, &styli, &coli);
    chkinq_("pqir", &errind, 4L);
/* inquire bundle #1 as REALIZED */
    nqir (&globnu_1.wkid, &c__1, &c__1, &errind, &ints2, &styli2, &coli2);
    chkinq_("pqir", &errind, 4L);
/* should have same attributes */
    L__1 = ints == ints2 && styli == styli2 && coli == coli2;
    ifpf_(&L__1);
/*  If number of initialized entries >= implementation max then skip test 
*/
/*  of setting undefined entry - goto redefined_test. */
    if (nie >= mne) {
#ifndef NO_PROTO
	inmsg_("Skipping undefined-test because all interior entries are ini"
		"tialized.", 69L);
#else /* NO_PROTO */
	inmsg_("Skipping undefined-test because all interior entries are ini\
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
    ints2 = 4;
    styli2 = 1;
    coli2 = 5;
    nsir (&globnu_1.wkid, &lui, &ints2, &styli2, &coli2);
    nqeii (&globnu_1.wkid, &c__0, &errind, &listot, &idum);
    chkinq_("pqeii", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("11 13", "Defining an undefined entry should increment the numbe"
	    "r of defined entries.", 5L, 75L);
#else /* NO_PROTO */
    setmsg_("11 13", "Defining an undefined entry should increment the numbe\
r of defined entries.", 5L, 75L);
#endif /* NO_PROTO */
    L__1 = listot == cnde + 1;
    ifpf_(&L__1);
/* check that lui is now among defined entries */
#ifndef NO_PROTO
    setmsg_("11 13", "Undefined bundle entry should be reported as defined a"
	    "fter set.", 5L, 63L);
#else /* NO_PROTO */
    setmsg_("11 13", "Undefined bundle entry should be reported as defined a\
fter set.", 5L, 63L);
#endif /* NO_PROTO */
    i__1 = listot;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeii (&globnu_1.wkid, &listel, &errind, &idum, &ii);
	chkinq_("pqeii", &errind, 5L);
	if (ii == lui) {
	    pass_();
	    goto L290;
	}
/* L280: */
    }
    fail_();
    goto L300;
L290:
    nqir (&globnu_1.wkid, &lui, &c__0, &errind, &ints, &styli, &coli);
    chkinq_("pqir", &errind, 4L);
    setmsg_("12 15", "New values should be set for undefined bundle entry.", 
	    5L, 52L);
    L__1 = ints == ints2 && styli == styli2 && coli == coli2;
    ifpf_(&L__1);
/* *** *** *** *** ***    redefined entries   *** *** *** *** *** */
L300:
/* get current number defined entries */
    nqeii (&globnu_1.wkid, &c__0, &errind, &cnde, &idum);
    chkinq_("pqeii", &errind, 5L);
/* let dii = a defined interior index from middle of list */
    i__1 = (cnde + 1) / 2;
    nqeii (&globnu_1.wkid, &i__1, &errind, &idum, &dii);
    chkinq_("pqeii", &errind, 5L);
/* set to first set of values */
    ints = 0;
    styli = 2;
    coli = 4;
    nsir (&globnu_1.wkid, &dii, &ints, &styli, &coli);
/* re-set to different values */
    ints2 = 4;
    styli2 = 0;
    coli2 = 5;
    nsir (&globnu_1.wkid, &dii, &ints2, &styli2, &coli2);
/* get list size - nnde = new number of defined entries */
    nqeii (&globnu_1.wkid, &c__0, &errind, &nnde, &idum);
    chkinq_("pqeii", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("11 13", "Redefining a user-defined entry should not change numb"
	    "er of defined entries.", 5L, 76L);
#else /* NO_PROTO */
    setmsg_("11 13", "Redefining a user-defined entry should not change numb\
er of defined entries.", 5L, 76L);
#endif /* NO_PROTO */
    L__1 = nnde == cnde;
    ifpf_(&L__1);
/* check that dii is among defined entries */
#ifndef NO_PROTO
    setmsg_("11 13", "Redefined bundle entry should be reported as defined a"
	    "fter set.", 5L, 63L);
#else /* NO_PROTO */
    setmsg_("11 13", "Redefined bundle entry should be reported as defined a\
fter set.", 5L, 63L);
#endif /* NO_PROTO */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeii (&globnu_1.wkid, &listel, &errind, &idum, &ii);
	chkinq_("pqeii", &errind, 5L);
	if (ii == dii) {
	    pass_();
	    goto L330;
	}
/* L320: */
    }
    fail_();
    goto L399;
L330:
    nqir (&globnu_1.wkid, &dii, &c__0, &errind, &ints, &styli, &coli);
    chkinq_("pqir", &errind, 4L);
    setmsg_("12 15", "New values should be set for redefined bundle entry.", 
	    5L, 52L);
    L__1 = ints == ints2 && styli == styli2 && coli == coli2;
    ifpf_(&L__1);
L399:
/* *** *** *** *** ***  access all defined entries  *** *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("13 14", "<Inquire list of interior indices> and <inquire interi"
	    "or representation> should detect all defined entries.", 5L, 107L);

#else /* NO_PROTO */
    setmsg_("13 14", "<Inquire list of interior indices> and <inquire interi\
or representation> should detect all defined entries.", 5L, 107L);
#endif /* NO_PROTO */
/* get listel-th element of defined interior indices */
    i__1 = nnde;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeii (&globnu_1.wkid, &listel, &errind, &idum, &ii);
	if (errind != 0) {
	    fail_();
	    goto L415;
	}
	nqir (&globnu_1.wkid, &ii, &c__0, &errind, &ints, &styli, &coli);
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

