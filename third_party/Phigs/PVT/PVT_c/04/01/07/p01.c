/* fort/04/01/07/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__10 = 10;
static integer c__1 = 1;
static integer c__50 = 50;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.07/01                           * */
/*  *    TEST TITLE : Cell array element                    * */
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
    static real xparpt[3] = { 55.55f,-99.99f,3.2e5f };
    static real yparpt[3] = { 0.f,3.f,-3.2e-15f };
    static real zparpt[3] = { 4.44f,0.f,2.3e-4f };
    static real degxpt[3] = { 1.f,1.f,1.f };
    static real degypt[3] = { 2.f,2.f,2.f };
    static real degzpt[3] = { 2.f,3.f,5.f };
#else /* NO_PROTO */
    static real xparpt[3] = { (float)55.55,(float)-99.99,(float)3.2e5 };
    static real yparpt[3] = { (float)0.,(float)3.,(float)-3.2e-15 };
    static real zparpt[3] = { (float)4.44,(float)0.,(float)2.3e-4 };
    static real degxpt[3] = { (float)1.,(float)1.,(float)1. };
    static real degypt[3] = { (float)2.,(float)2.,(float)2. };
    static real degzpt[3] = { (float)2.,(float)3.,(float)5. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1, i__2;
    logical L__1;

    /* Local variables */
    static integer k, rl;
#ifndef NO_PROTO
    extern /* Subroutine */ int nca (real *, real *, real *, real *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    );
#else /* NO_PROTO */
    extern /* Subroutine */ int nca ();
#endif /* NO_PROTO */
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int nca3 (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nca3 ();
#endif /* NO_PROTO */
    static integer x1st, y1st;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer icol;
    static real rlar[50];
    static integer intg, xdim, ydim;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer irow;
#ifndef NO_PROTO
    extern /* Subroutine */ int set2d_(char *, integer *, integer *, integer *
	    , integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int set2d_();
#endif /* NO_PROTO */
    static integer colia[100]	/* was [10][10] */;
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern logical iareq_();
    extern /* Subroutine */ int endit_();
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
    static integer errind, intlen, arrlen[10], expctd[50], nocols, celtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer strlen, strarl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    nqcets (integer *, integer *, integer *, integer *, integer *), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), nqcets (), xpopph_();
#endif /* NO_PROTO */

/* Points for degenerate case */
/*  Data points for degenerate case */
    initgl_("04.01.07/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  *** *** ***   Cell array 3 - Normal Case  *** *** *** */
/*  Initialize 2D cell array - normal case */
#ifndef NO_PROTO
    set2d_("0/  0,0,  0, 2, 9, 3, 7, 2, 3/0,0,  7, 2, 8, 6, 3, 8, 7/0,0,  1,"
	    " 0, 2, 3, 9, 3, 8/", &c__10, &nocols, arrlen, colia, 82L);
#else /* NO_PROTO */
    set2d_("0/  0,0,  0, 2, 9, 3, 7, 2, 3/0,0,  7, 2, 8, 6, 3, 8, 7/0,0,  1,\
 0, 2, 3, 9, 3, 8/", &c__10, &nocols, arrlen, colia, 82L);
#endif /* NO_PROTO */
    xdim = 7;
    ydim = 3;
    x1st = 3;
    y1st = 2;
/* compute expected array - normal case */
    k = 2;
    i__1 = ydim + y1st - 1;
    for (irow = y1st; irow <= i__1; ++irow) {
	i__2 = xdim + x1st - 1;
	for (icol = x1st; icol <= i__2; ++icol) {
	    ++k;
	    expctd[k - 1] = colia[icol + irow * 10 - 11];
/* L10: */
	}
/* L15: */
    }
    nopst (&c__1);
    nca3 (xparpt, yparpt, zparpt, &c__10, &c__10, &x1st, &y1st, &xdim, &ydim, 
	    colia);
/*  <inquire current element type and size> to set celtyp, celsiz */
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return ce"
	    "ll array 3 as the type of the created element and the appropriat"
	    "e element size.", 3L, 135L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return ce\
ll array 3 as the type of the created element and the appropriate element si\
ze.", 3L, 135L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 14 && intlen == xdim * ydim + 2 && rllen 
	    == 9 && strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for cell array 3.", 3L, 93L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for cell array 3.", 3L, 93L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == xdim * ydim + 2 && intar[0] == xdim && intar[1]
	     == ydim && rl == 9 && rlar[0] == xparpt[0] && rlar[1] == yparpt[
	    0] && rlar[2] == zparpt[0] && rlar[3] == xparpt[1] && rlar[4] == 
	    yparpt[1] && rlar[5] == zparpt[1] && rlar[6] == xparpt[2] && rlar[
	    7] == yparpt[2] && rlar[8] == zparpt[2] && str == 0) {
/*        OK so far */
	i__1 = k - 2;
	if (iareq_(&i__1, &intar[2], &expctd[2])) {
	    pass_();
	} else {
	    fail_();
	    inmsg_("Color index values are incorrect.", 33L);
	}
    } else {
	fail_();
	inmsg_("Array sizes or corner points are incorrect.", 43L);
    }
/*  *** *** *** *** ***   Cell array - normal case *** *** *** *** *** */
    nca (xparpt, yparpt, &xparpt[1], &yparpt[1], &c__10, &c__10, &x1st, &y1st,
	     &xdim, &ydim, colia);
#ifndef NO_PROTO
    setmsg_("6 7", "<Inquire current element type and size> should return ce"
	    "ll array as the type of the created element and the appropriate "
	    "element size.", 3L, 133L);
#else /* NO_PROTO */
    setmsg_("6 7", "<Inquire current element type and size> should return ce\
ll array as the type of the created element and the appropriate element size."
	    , 3L, 133L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 15 && intlen == xdim * ydim + 2 && rllen 
	    == 4 && strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6 8", "<Inquire current element content> should return the stan"
	    "dard representation for cell array.", 3L, 91L);
#else /* NO_PROTO */
    setmsg_("6 8", "<Inquire current element content> should return the stan\
dard representation for cell array.", 3L, 91L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == xdim * ydim + 2 && intar[0] == xdim && intar[1]
	     == ydim && rl == 4 && rlar[0] == xparpt[0] && rlar[1] == yparpt[
	    0] && rlar[2] == xparpt[1] && rlar[3] == yparpt[1] && str == 0) {
/*        OK so far */
	i__1 = k - 2;
	if (iareq_(&i__1, &intar[2], &expctd[2])) {
	    pass_();
	} else {
	    fail_();
	    inmsg_("Color index values are incorrect.", 33L);
	}
    } else {
	fail_();
	inmsg_("Array sizes or corner points are incorrect.", 43L);
    }
/* *** *** *** *** ***   Cell array 3 - Degenerate Case  *** *** *** *** 
****/
/*  Initialize 2D cell array - degenerate case */
    set2d_("0/  0,0,  9, 3/0,0,  8, 6/0,0,  1, 0/", &c__10, &nocols, arrlen, 
	    colia, 37L);
    xdim = 2;
    ydim = 3;
    x1st = 3;
    y1st = 2;
/* compute expected array - degenerate case */
    k = 2;
    i__1 = ydim + y1st - 1;
    for (irow = y1st; irow <= i__1; ++irow) {
	i__2 = xdim + x1st - 1;
	for (icol = x1st; icol <= i__2; ++icol) {
	    ++k;
	    expctd[k - 1] = colia[icol + irow * 10 - 11];
/* L25: */
	}
/* L20: */
    }
    nca3 (degxpt, degypt, degzpt, &c__10, &c__10, &x1st, &y1st, &xdim, &ydim, 
	    colia);
/*  <inquire current element type and size> to set celtyp, celsiz */
#ifndef NO_PROTO
    setmsg_("1 2", "<Inquire current element type and size> should return ce"
	    "ll array 3 as the type of the created element and the appropriat"
	    "e element size for a degenerate element.", 3L, 160L);
#else /* NO_PROTO */
    setmsg_("1 2", "<Inquire current element type and size> should return ce\
ll array 3 as the type of the created element and the appropriate element si\
ze for a degenerate element.", 3L, 160L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 14 && intlen == xdim * ydim + 2 && rllen 
	    == 9 && strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "<Inquire current element content> should return the stan"
	    "dard representation for a degenerate cell array 3.", 3L, 106L);
#else /* NO_PROTO */
    setmsg_("1 3", "<Inquire current element content> should return the stan\
dard representation for a degenerate cell array 3.", 3L, 106L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* INTAR(1) = x dimension of cell index array */
/* INTAR(2) = y dimension of cell index array */
/* INTAR(3) - INTAR( XDIM*YDIM +2) =  index array in column major order */

/*          (e.g., INTAR(3) = COLIA(1,1) INTAR(4) = COLIA(2,1)... */

    if (errind == 0 && intg == xdim * ydim + 2 && intar[0] == xdim && intar[1]
	     == ydim && rl == 9 && rlar[0] == degxpt[0] && rlar[1] == degypt[
	    0] && rlar[2] == degzpt[0] && rlar[3] == degxpt[1] && rlar[4] == 
	    degypt[1] && rlar[5] == degzpt[1] && rlar[6] == degxpt[2] && rlar[
	    7] == degypt[2] && rlar[8] == degzpt[2] && str == 0) {

/*  9 Coordinates of the parallelagram */

/*        OK so far */
	i__1 = k - 2;
	if (iareq_(&i__1, &intar[2], &expctd[2])) {
	    pass_();
	} else {
	    fail_();
	    inmsg_("Color index values are incorrect.", 33L);
	}
    } else {
	fail_();
	inmsg_("Array sizes or corner points are incorrect.", 43L);
    }
/*  *** *** *** *** ***   Cell array - degenerate case *** *** *** *** ***
 */
    nca (degxpt, degypt, &degxpt[1], &degypt[1], &c__10, &c__10, &x1st, &y1st,
	     &xdim, &ydim, colia);
#ifndef NO_PROTO
    setmsg_("6 7", "<Inquire current element type and size> should return ce"
	    "ll array as the type of the created element and the appropriate "
	    "element size for a degenerate element.", 3L, 158L);
#else /* NO_PROTO */
    setmsg_("6 7", "<Inquire current element type and size> should return ce\
ll array as the type of the created element and the appropriate element size\
 for a degenerate element.", 3L, 158L);
#endif /* NO_PROTO */
    nqcets (&errind, &celtyp, &intlen, &rllen, &strlen);
    L__1 = errind == 0 && celtyp == 15 && intlen == xdim * ydim + 2 && rllen 
	    == 4 && strlen == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6 8", "<Inquire current element content> should return the stan"
	    "dard representation for a degenerate cell array.", 3L, 104L);
#else /* NO_PROTO */
    setmsg_("6 8", "<Inquire current element content> should return the stan\
dard representation for a degenerate cell array.", 3L, 104L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
    if (errind == 0 && intg == xdim * ydim + 2 && intar[0] == xdim && intar[1]
	     == ydim && rl == 4 && rlar[0] == degxpt[0] && rlar[1] == degypt[
	    0] && rlar[2] == degxpt[1] && rlar[3] == degypt[1] && str == 0) {
/* INTAR(1) = x dimension of cell index array */
/* INTAR(2) = y dimension of cell index array */
/* INTAR(3) - INTAR( XDIM*YDIM +2) =  index array in column major orde
r */
/*          (e.g., INTAR(3) = COLIA(1,1) INTAR(4) = COLIA(2,1)... */

/*  Coordinates of P,Q */
/*        OK so far */
	i__1 = k - 2;
	if (iareq_(&i__1, &intar[2], &expctd[2])) {
	    pass_();
	} else {
	    fail_();
	    inmsg_("Color index values are incorrect.", 33L);
	}
    } else {
	fail_();
	inmsg_("Array sizes or corner points are incorrect.", 43L);
    }
/* L777: */
/* close structure and PHIGS */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

