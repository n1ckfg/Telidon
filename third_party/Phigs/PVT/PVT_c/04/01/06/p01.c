/* fort/04/01/06/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__18 = 18;
#ifndef NO_PROTO
static real c_b15 = 0.f;
#else /* NO_PROTO */
static real c_b15 = (float)0.;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.06/01                           * */
/*  *    TEST TITLE : Fill area set element                 * */
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
    static real xarr[6] = { 2.33f,55.55f,-4.4f,123.f,0.f,2.3f };
    static real yarr[6] = { 0.f,3.2f,-99.99f,3.2e22f,-2.2e-22f,4.5f };
    static real zarr[6] = { 4.44f,0.f,0.f,5.5f,22.22f,6.7f };
#else /* NO_PROTO */
    static real xarr[6] = { (float)2.33,(float)55.55,(float)-4.4,(float)123.,(
	    float)0.,(float)2.3 };
    static real yarr[6] = { (float)0.,(float)3.2,(float)-99.99,(float)3.2e22,(
	    float)-2.2e-22,(float)4.5 };
    static real zarr[6] = { (float)4.44,(float)0.,(float)0.,(float)5.5,(float)
	    22.22,(float)6.7 };
#endif /* NO_PROTO */

    /* System generated locals */
    logical L__1;

    /* Local variables */
    static integer i, n, rl, ix, str;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nfas (integer *, integer *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nfas ();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 ();
#endif /* NO_PROTO */
    static integer degen;
    static logical valec;
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
    extern /* Subroutine */ int endit_(void);
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical iareq_();
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
    static real rlcomb[18];
    static integer errind, intlen, endpts[10];
    static logical valets;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static logical oksofr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcets (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcets ();
#endif /* NO_PROTO */
    static integer strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    initgl_("04.01.06/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopst (&c__1);
    for (i = 1; i <= 6; ++i) {
	rlcomb[i - 1] = xarr[i - 1];
	rlcomb[i + 5] = yarr[i - 1];
	rlcomb[i + 11] = zarr[i - 1];
/* L10: */
    }
/*  *** *** *** *** ***   Fill area set 3   *** *** *** *** *** */
/*  fill area set with 2 subareas */
/*  set up expected values */
    n = 2;
    endpts[0] = 3;
    endpts[1] = 6;
    nfas3 (&n, endpts, xarr, yarr, zarr);
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return fi"
	    "ll area set 3 as the type of the created element and the appropr"
	    "iate element size.", 3L, 138L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return fi\
ll area set 3 as the type of the created element and the appropriate element\
 size.", 3L, 138L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 12 && intlen == n && rllen == 18 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for a fill area set 3.", 3L, 98L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for a fill area set 3.", 3L, 98L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == n && rl == 18 && str == 0) {
	oksofr = TRUE_;
    } else {
	oksofr = FALSE_;
	inmsg_("Array sizes are incorrect.", 26L);
    }
    if (iareq_(&c__2, intar, endpts)) {
/*        ok so far */
    } else {
	oksofr = FALSE_;
	inmsg_("Endpoints are incorrect.", 24L);
    }
    if (rareq_(&c__18, rlar, rlcomb, &c_b15, &c_b15)) {
/*        ok */
    } else {
	oksofr = FALSE_;
	inmsg_("Geometric point values are incorrect.", 37L);
    }
    ifpf_(&oksofr);
    valets = TRUE_;
    valec = TRUE_;
    for (ix = 0; ix <= 2; ++ix) {
	if (ix == 0) {
	    endpts[0] = 2;
	    endpts[1] = 3;
	    endpts[2] = 3;
	    degen = 3;
	    nfas3 (&c__3, endpts, xarr, yarr, zarr);
	} else {
	    endpts[0] = ix;
	    endpts[1] = ix << 1;
	    endpts[2] = ix * 3;
	    degen = ix * 3;
	    nfas3 (&c__3, endpts, xarr, yarr, zarr);
	}
	nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
	if (errind == 0 && celtyp == 12 && intlen == 3 && rllen == degen * 3 
		&& strlen == 0) {
/*           Ok as far */
	} else {
	    valets = FALSE_;
	}
	nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	if (errind == 0 && intg == 3 && rl == degen * 3 && str == 0 && iareq_(
		&c__3, intar, endpts) && rareq_(&degen, rlar, xarr, &c_b15, &
		c_b15) && rareq_(&degen, &rlar[degen], yarr, &c_b15, &c_b15) 
		&& rareq_(&degen, &rlar[degen * 2], zarr, &c_b15, &c_b15)) {
/*         Ok, so far */
	} else {
	    valec = FALSE_;
	}
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return fi"
	    "ll area set 3 as the type of the created element and the appropr"
	    "iate element size for an element with subareas with 0, 1, and/or"
	    " 2 points.", 3L, 194L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return fi\
ll area set 3 as the type of the created element and the appropriate element\
 size for an element with subareas with 0, 1, and/or 2 points.", 3L, 194L);
#endif /* NO_PROTO */
    ifpf_(&valets);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for a <fill area set 3> whose subareas have "
	    "0, 1, and/or 2 points.", 3L, 142L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for a <fill area set 3> whose subareas have 0, 1, and/or\
 2 points.", 3L, 142L);
#endif /* NO_PROTO */
    ifpf_(&valec);
/*  *** *** *** *** ***   Fill area set   *** *** *** *** *** */
/*  fill area set with two subareas */
/*  set up expected values */
    n = 2;
    endpts[0] = 3;
    endpts[1] = 6;
    nfas (&n, endpts, xarr, yarr);
#ifndef NO_PROTO
    setmsg_("4 5", "<Inquire current element type and size> should return fi"
	    "ll area set as the type of the created element and the appropria"
	    "te element size for a multipoint element.", 3L, 161L);
#else /* NO_PROTO */
    setmsg_("4 5", "<Inquire current element type and size> should return fi\
ll area set as the type of the created element and the appropriate element s\
ize for a multipoint element.", 3L, 161L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 13 && intlen == n && rllen == 12 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 6", "<Inquire current element content> should return the stan"
	    "dard representation for a multipoint fill area set.", 3L, 107L);
#else /* NO_PROTO */
    setmsg_("4 6", "<Inquire current element content> should return the stan\
dard representation for a multipoint fill area set.", 3L, 107L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == n && rl == 12 && str == 0) {
	oksofr = TRUE_;
    } else {
	oksofr = FALSE_;
	inmsg_("Array sizes are incorrect.", 26L);
    }
    if (iareq_(&c__2, intar, endpts)) {
/*        ok so far */
    } else {
	oksofr = FALSE_;
	inmsg_("Endpoints are incorrect.", 24L);
    }
    if (rareq_(&c__12, rlar, rlcomb, &c_b15, &c_b15)) {
/*        ok */
    } else {
	oksofr = FALSE_;
	inmsg_("Geometric point values are incorrect.", 37L);
    }
    ifpf_(&oksofr);
    valets = TRUE_;
    valec = TRUE_;
    for (ix = 0; ix <= 2; ++ix) {
	if (ix == 0) {
	    endpts[0] = 2;
	    endpts[1] = 3;
	    endpts[2] = 3;
	    degen = 3;
	    nfas (&c__3, endpts, xarr, yarr);
	} else {
	    endpts[0] = ix;
	    endpts[1] = ix << 1;
	    endpts[2] = ix * 3;
	    degen = ix * 3;
	    nfas (&c__3, endpts, xarr, yarr);
	}
	nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
	if (errind == 0 && celtyp == 13 && intlen == 3 && rllen == degen << 1 
		&& strlen == 0) {
/*         OK as far */
	} else {
	    valets = FALSE_;
	}
	nqceco (&c__50, &rllen, &c__50, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	if (errind == 0 && intg == 3 && rl == degen << 1 && str == 0 && 
		iareq_(&c__3, intar, endpts) && rareq_(&degen, rlar, xarr, &
		c_b15, &c_b15) && rareq_(&degen, &rlar[degen], yarr, &c_b15, &
		c_b15)) {
/*         Ok, so far */
	} else {
	    valec = FALSE_;
	}
/* L200: */
    }
#ifndef NO_PROTO
    setmsg_("4 5", "<Inquire current element type and size> should return fi"
	    "ll area set as the type of the created element and the appropria"
	    "te element size for an element with subareas with 0, 1, and/or 2"
	    " points.", 3L, 192L);
#else /* NO_PROTO */
    setmsg_("4 5", "<Inquire current element type and size> should return fi\
ll area set as the type of the created element and the appropriate element s\
ize for an element with subareas with 0, 1, and/or 2 points.", 3L, 192L);
#endif /* NO_PROTO */
    ifpf_(&valets);
#ifndef NO_PROTO
    setmsg_("4 6", "<Inquire current element content> should return the stan"
	    "dard representation for a <fill area set> whose subareas have 0,"
	    " 1, and/or 2 points.", 3L, 140L);
#else /* NO_PROTO */
    setmsg_("4 6", "<Inquire current element content> should return the stan\
dard representation for a <fill area set> whose subareas have 0, 1, and/or 2\
 points.", 3L, 140L);
#endif /* NO_PROTO */
    ifpf_(&valec);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

