/* fort/04/01/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b13 = 0.f;
#else /* NO_PROTO */
static real c_b13 = (float)0.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.02/01                           * */
/*  *    TEST TITLE : Polymarker element                    * */
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
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *), 
	    ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 (), ifpf_();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
    static logical case1, case2;
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
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqcets (integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqcets ();
#endif /* NO_PROTO */
    static integer celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
    initgl_("04.01.02/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  *** *** *** *** ***   Polymarker 3   *** *** *** *** *** */
/*  <polymarker 3> with n,xarr,yarr,zarr */
    n = 5;
    nopst (&c__1);
    npm3 (&n, xarr, yarr, zarr);
/*  <inquire current element type and size> to set celtyp, celsiz */
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return po"
	    "lymarker 3 as the type of the created element and the appropriat"
	    "e element size.", 3L, 135L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return po\
lymarker 3 as the type of the created element and the appropriate element si\
ze.", 3L, 135L);
#endif /* NO_PROTO */
/*    (celtyp = polymarker 3 and */
/*     celsiz = values specified by the standard and language binding; */
/*              fortran binding values are intlen, rllen, and strlen) */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 4 && intlen == 1 && rllen == n * 3 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for polymarker 3.", 3L, 93L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for polymarker 3.", 3L, 93L);
#endif /* NO_PROTO */
    i__1 = n;
    for (i = 1; i <= i__1; ++i) {
	rlcomb[i - 1] = xarr[i - 1];
	rlcomb[i + n - 1] = yarr[i - 1];
	rlcomb[i + (n << 1) - 1] = zarr[i - 1];
/* L10: */
    }
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == 1 && intar[0] == n && rl == n * 3 && str == 0) 
	    {
	case1 = TRUE_;
    } else {
	case1 = FALSE_;
	inmsg_("Array sizes are incorrect.", 26L);
	goto L20;
    }
    i__1 = n * 3;
    case2 = rareq_(&i__1, rlar, rlcomb, &c_b13, &c_b13);
    if (! case2) {
	inmsg_("Geometric point values are incorrect.", 37L);
    }
L20:
    L__1 = case1 && case2;
    ifpf_(&L__1);
/*  *** *** *** *** ***   Polymarker   *** *** *** *** *** */
/*  <polymarker> with n,xarr,yarr */
    n = 5;
    npm (&n, xarr, yarr);
/*  <inquire current element type and size> to set celtyp, celsiz */
#ifndef NO_PROTO
    setmsg_("4 5", "<Inquire current element type and size> should return po"
	    "lymarker as the type of the created element and the appropriate "
	    "element size.", 3L, 133L);
#else /* NO_PROTO */
    setmsg_("4 5", "<Inquire current element type and size> should return po\
lymarker as the type of the created element and the appropriate element size."
	    , 3L, 133L);
#endif /* NO_PROTO */
/*    (celtyp = polymarker and */
/*     celsiz = values specified by the standard and language binding; */
/*              fortran binding values are intlen, rllen, and strlen) */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 5 && intlen == 1 && rllen == n << 1 && 
	    strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 6", "<Inquire current element content> should return the stan"
	    "dard representation for polymarker.", 3L, 91L);
#else /* NO_PROTO */
    setmsg_("4 6", "<Inquire current element content> should return the stan\
dard representation for polymarker.", 3L, 91L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == 1 && intar[0] == n && rl == n << 1 && str == 0)
	     {
	case1 = TRUE_;
    } else {
	case1 = FALSE_;
	inmsg_("Array sizes are incorrect.", 26L);
	goto L30;
    }
    i__1 = n << 1;
    case2 = rareq_(&i__1, rlar, rlcomb, &c_b13, &c_b13);
    if (! case2) {
	inmsg_("Geometric point values are incorrect.", 37L);
    }
L30:
    L__1 = case1 && case2;
    ifpf_(&L__1);
/* L777: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

