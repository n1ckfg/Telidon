/* fort/06/01/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__4 = 4;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.01/04                           * */
/*  *    TEST TITLE : Behavior of matrix composition        * */
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
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double tan(doublereal);
#else /* NO_PROTO */
    double tan();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i, j;
    static real inc;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom_(real *, real *, real *), ifpf_(logical *
	    ), ncom (real *, real *, integer *, real *), ecom3_(real *, real *
	    , real *), ncom3 (real *, real *, integer *, real *), endit_(void)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom_(), ifpf_(), ncom (), ecom3_(), ncom3 (),
	     endit_();
#endif /* NO_PROTO */
    static real act3x3[9]	/* was [3][3] */, ain3x3[9]	/* was [3][3] 
	    */, act4x4[16]	/* was [4][4] */, ain4x4[16]	/* was [4][4] 
	    */, bin4x4[16]	/* was [4][4] */, bin3x3[9]	/* was [3][3] 
	    */, exp3x3[9]	/* was [3][3] */, exp4x4[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
    extern logical trnseq_(integer *, real *, real *);
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
    extern logical trnseq_();
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    initgl_("06.01.01/04", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 2 11", "The matrix returned by <compose matrix 3> should perf"
	    "orm the same 3D transformation as that resulting from the multip"
	    "lication of the two specified matrices.", 6L, 156L);
    ain4x4[0] = -2.2f;
    ain4x4[4] = 3.3f;
    ain4x4[8] = 4.4f;
    ain4x4[12] = 5.5f;
    ain4x4[1] = .0023f;
    ain4x4[5] = -727.12f;
    ain4x4[9] = 2.09f;
    ain4x4[13] = 33.33f;
    ain4x4[2] = 0.f;
    ain4x4[6] = 34.f;
    ain4x4[10] = 54.1f;
    ain4x4[14] = -.045f;
    ain4x4[3] = 7.f;
    ain4x4[7] = 6.f;
    ain4x4[11] = 5.f;
    ain4x4[15] = 4.f;
    inc = 0.f;
#else /* NO_PROTO */
    setmsg_("1 2 11", "The matrix returned by <compose matrix 3> should perf\
orm the same 3D transformation as that resulting from the multiplication of \
the two specified matrices.", 6L, 156L);
    ain4x4[0] = (float)-2.2;
    ain4x4[4] = (float)3.3;
    ain4x4[8] = (float)4.4;
    ain4x4[12] = (float)5.5;
    ain4x4[1] = (float).0023;
    ain4x4[5] = (float)-727.12;
    ain4x4[9] = (float)2.09;
    ain4x4[13] = (float)33.33;
    ain4x4[2] = (float)0.;
    ain4x4[6] = (float)34.;
    ain4x4[10] = (float)54.1;
    ain4x4[14] = (float)-.045;
    ain4x4[3] = (float)7.;
    ain4x4[7] = (float)6.;
    ain4x4[11] = (float)5.;
    ain4x4[15] = (float)4.;
    inc = (float)0.;
#endif /* NO_PROTO */
    for (i = 1; i <= 4; ++i) {
	for (j = 1; j <= 4; ++j) {
#ifndef NO_PROTO
	    bin4x4[i + (j << 2) - 5] = tan(inc - 1.56f);
	    inc += .1875f;
#else /* NO_PROTO */
	    bin4x4[i + (j << 2) - 5] = tan(inc - (float)1.56);
	    inc += (float).1875;
#endif /* NO_PROTO */
/* L402: */
	}
/* L401: */
    }
    ncom3 (ain4x4, bin4x4, &errind, act4x4);
    chkinq_("pcom3", &errind, 5L);
/*  Compute exp4x4 = expected array */
    ecom3_(ain4x4, bin4x4, exp4x4);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 12", "The matrix returned by <compose matrix> should perfor"
	    "m the same 2D transformation as that resulting from the multipli"
	    "cation of the two specified matrices.", 6L, 154L);
    ain3x3[0] = -2.2f;
    ain3x3[3] = 3.3f;
    ain3x3[6] = 5.5f;
    ain3x3[1] = .0023f;
    ain3x3[4] = -727.12f;
    ain3x3[7] = 33.33f;
    ain3x3[2] = 0.f;
    ain3x3[5] = 34.f;
    ain3x3[8] = -.045f;
    inc = 0.f;
#else /* NO_PROTO */
    setmsg_("1 2 12", "The matrix returned by <compose matrix> should perfor\
m the same 2D transformation as that resulting from the multiplication of th\
e two specified matrices.", 6L, 154L);
    ain3x3[0] = (float)-2.2;
    ain3x3[3] = (float)3.3;
    ain3x3[6] = (float)5.5;
    ain3x3[1] = (float).0023;
    ain3x3[4] = (float)-727.12;
    ain3x3[7] = (float)33.33;
    ain3x3[2] = (float)0.;
    ain3x3[5] = (float)34.;
    ain3x3[8] = (float)-.045;
    inc = (float)0.;
#endif /* NO_PROTO */
    for (i = 1; i <= 3; ++i) {
	for (j = 1; j <= 3; ++j) {
#ifndef NO_PROTO
	    bin3x3[i + j * 3 - 4] = tan(inc - 1.56f);
	    inc += .33333333333333331f;
#else /* NO_PROTO */
	    bin3x3[i + j * 3 - 4] = tan(inc - (float)1.56);
	    inc += (float).33333333333333331;
#endif /* NO_PROTO */
/* L302: */
	}
/* L301: */
    }
    ncom (ain3x3, bin3x3, &errind, act3x3);
    chkinq_("pcom", &errind, 4L);
/*  Compute exp3x3 = expected array */
    ecom_(ain3x3, bin3x3, exp3x3);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__3, act3x3, exp3x3);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

