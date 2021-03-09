/* fort/04/01/05/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__50 = 50;
#ifndef NO_PROTO
static real c_b12 = 0.f;
#else /* NO_PROTO */
static real c_b12 = (float)0.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.05/01                           * */
/*  *    TEST TITLE : Fill area element                     * */
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

#ifndef NO_PROTO
    static real xarr[5] = { 2.33f,55.55f,-4.4f,123.f,0.f };
    static real yarr[5] = { 0.f,3.2f,-99.99f,3.2e22f,-2.2e-22f };
    static real zarr[5] = { 4.44f,0.f,0.f,5.5f,22.22f };
#else /* NO_PROTO */
    static real xarr[5] = { (float)2.33,(float)55.55,(float)-4.4,(float)123.,(
	    float)0. };
    static real yarr[5] = { (float)0.,(float)3.2,(float)-99.99,(float)3.2e22,(
	    float)-2.2e-22 };
    static real zarr[5] = { (float)4.44,(float)0.,(float)0.,(float)5.5,(float)
	    22.22 };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Local variables */
    static integer i, n, rl;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa3 (integer *, real *, real *, real *), 
	    ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa3 (), ifpf_();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg, degen;
    static logical valec;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical rareq_();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static char strar[1*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nqceco (integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nqceco ();
#endif /* NO_PROTO */
    static real rlcomb[15];
    static integer errind, intlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static logical valets;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcets (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcets ();
#endif /* NO_PROTO */
    static integer celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static logical oksofr;
    static integer strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    initgl_("04.01.05/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopst (&c__1);
    n = 5;
/* set up expected values */
    i__1 = n;
    for (i = 1; i <= i__1; ++i) {
	rlcomb[i - 1] = xarr[i - 1];
	rlcomb[i + n - 1] = yarr[i - 1];
	rlcomb[i + (n << 1) - 1] = zarr[i - 1];
/* L10: */
    }
/*  *** *** *** *** ***   Fill area 3   *** *** *** *** *** */
/*  <fill area 3> with n,xarr,yarr,zarr */
    nfa3 (&n, xarr, yarr, zarr);
/*  <inquire current element type and size> to set celtyp, celsiz */
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return fi"
	    "ll area 3 as the type of the created element and the appropriate"
	    " element size for a multipoint element.", 3L, 159L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return fi\
ll area 3 as the type of the created element and the appropriate element siz\
e for a multipoint element.", 3L, 159L);
#endif /* NO_PROTO */
/*    (celtyp = fill area 3 and */
/*     celsiz = values specified by the standard and language binding; */
/*              fortran binding values are intlen, rllen, and strlen) */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 10 && intlen == 1 && rllen == n * 3 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for a multipoint fill area 3.", 3L, 105L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for a multipoint fill area 3.", 3L, 105L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == 1 && intar[0] == n && rl == n * 3 && str == 0) 
	    {
	oksofr = TRUE_;
    } else {
	oksofr = FALSE_;
	inmsg_("Array sizes are incorrect.", 26L);
    }
    i__1 = n * 3;
    if (rareq_(&i__1, rlar, rlcomb, &c_b12, &c_b12)) {
/*        ok so far */
    } else {
	oksofr = FALSE_;
	inmsg_("Geometric point values are incorrect.", 37L);
    }
    ifpf_(&oksofr);
/*  valid type and content so far for degenerate elements */
    valets = TRUE_;
    valec = TRUE_;
    for (degen = 1; degen <= 2; ++degen) {
	nfa3 (&degen, xarr, yarr, zarr);
	nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
	if (errind == 0 && celtyp == 10 && intlen == 1 && rllen == degen * 3 
		&& strlen == 0) {
/*           OK so far */
	} else {
	    valets = FALSE_;
	}
	nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	if (errind == 0 && intg == 1 && intar[0] == degen && rl == degen * 3 
		&& rareq_(&degen, rlar, xarr, &c_b12, &c_b12) && rareq_(&
		degen, &rlar[degen], yarr, &c_b12, &c_b12) && rareq_(&degen, &
		rlar[degen * 2], zarr, &c_b12, &c_b12) && str == 0) {
/*           OK so far */
	} else {
	    valec = FALSE_;
	}
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return fi"
	    "ll area 3 as the type of the created element and the appropriate"
	    " element size for a single or double point element.", 3L, 171L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return fi\
ll area 3 as the type of the created element and the appropriate element siz\
e for a single or double point element.", 3L, 171L);
#endif /* NO_PROTO */
    ifpf_(&valets);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for a single or double point fill area 3.", 
	    3L, 117L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for a single or double point fill area 3.", 3L, 117L);
#endif /* NO_PROTO */
    ifpf_(&valec);
/*  *** *** *** *** ***   Fill area   *** *** *** *** *** */
/*  <fill area> with n,xarr,yarr */
    n = 5;
    nfa (&n, xarr, yarr);
/*  <inquire current element type and size> to set celtyp, celsiz */
#ifndef NO_PROTO
    setmsg_("4 5", "<Inquire current element type and size> should return fi"
	    "ll area as the type of the created element and the appropriate e"
	    "lement size for a multipoint element.", 3L, 157L);
#else /* NO_PROTO */
    setmsg_("4 5", "<Inquire current element type and size> should return fi\
ll area as the type of the created element and the appropriate element size \
for a multipoint element.", 3L, 157L);
#endif /* NO_PROTO */
/*    (celtyp = fill area and */
/*     celsiz = values specified by the standard and language binding) */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 11 && intlen == 1 && rllen == n << 1 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 6", "<Inquire current element content> should return the stan"
	    "dard representation for a multipoint fill area.", 3L, 103L);
#else /* NO_PROTO */
    setmsg_("4 6", "<Inquire current element content> should return the stan\
dard representation for a multipoint fill area.", 3L, 103L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == 1 && intar[0] == n && rl == n << 1 && str == 0)
	     {
	oksofr = TRUE_;
    } else {
	oksofr = FALSE_;
	inmsg_("Array sizes are incorrect.", 26L);
    }
    i__1 = n << 1;
    if (rareq_(&i__1, rlar, rlcomb, &c_b12, &c_b12)) {
/*        ok so far */
    } else {
	oksofr = FALSE_;
	inmsg_("Geometric point values are incorrect.", 37L);
    }
    ifpf_(&oksofr);
/*  valid type and content so far for degenerate elements */
    valets = TRUE_;
    valec = TRUE_;
    for (degen = 1; degen <= 2; ++degen) {
	nfa (&degen, xarr, yarr);
	nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
	if (errind == 0 && celtyp == 11 && intlen == 1 && rllen == degen << 1 
		&& strlen == 0) {
/*           OK so far */
	} else {
	    valets = FALSE_;
	}
	nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	if (errind == 0 && intg == 1 && intar[0] == degen && rl == degen << 1 
		&& rareq_(&degen, rlar, xarr, &c_b12, &c_b12) && rareq_(&
		degen, &rlar[degen], yarr, &c_b12, &c_b12) && str == 0) {
/*           OK so far */
	} else {
	    valec = FALSE_;
	}
/* L200: */
    }
/*  <inquire current element type and size> to set celtyp, celsiz */
#ifndef NO_PROTO
    setmsg_("4 5", "<Inquire current element type and size> should return fi"
	    "ll area as the type of the created element and the appropriate e"
	    "lement size for a single or double point element.", 3L, 169L);
#else /* NO_PROTO */
    setmsg_("4 5", "<Inquire current element type and size> should return fi\
ll area as the type of the created element and the appropriate element size \
for a single or double point element.", 3L, 169L);
#endif /* NO_PROTO */
    ifpf_(&valets);
#ifndef NO_PROTO
    setmsg_("4 6", "<Inquire current element content> should return the stan"
	    "dard representation for a single or double point fill area.", 3L, 
	    115L);
#else /* NO_PROTO */
    setmsg_("4 6", "<Inquire current element content> should return the stan\
dard representation for a single or double point fill area.", 3L, 115L);
#endif /* NO_PROTO */
    ifpf_(&valec);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

