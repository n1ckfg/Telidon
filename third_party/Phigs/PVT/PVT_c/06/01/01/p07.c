/* fort/06/01/01/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 06.01.01/07                           * */
/*  *    TEST TITLE : Composition of a matrix with a        * */
/*  *                 transformation                        * */
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

    /* Local variables */
    static real a3[9]	/* was [3][3] */, a4[16]	/* was [4][4] */, x0, 
	    y0, z0, dx, dy, dz, fx, fy, fz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real phix, phiy, phiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real act3x3[9]	/* was [3][3] */, act4x4[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecotm_(real *, real *, real *, real *, real *,
	     real *, real *, real *, real *), ncotm (real *, real *, real *, 
	    real *, real *, real *, real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecotm_(), ncotm ();
#endif /* NO_PROTO */
    static real exp3x3[9]	/* was [3][3] */, exp4x4[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ecotm3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), ncotm3 (real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, integer *,
	     real *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecotm3_(), ncotm3 (), chkinq_();
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

    initgl_("06.01.01/07", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 2 17", "<Compose transformation matrix 3> should generate a m"
	    "atrix which is the composition of the specified matrix with the "
	    "specified 3D transformation.", 6L, 145L);
#else /* NO_PROTO */
    setmsg_("1 2 17", "<Compose transformation matrix 3> should generate a m\
atrix which is the composition of the specified matrix with the specified 3D\
 transformation.", 6L, 145L);
#endif /* NO_PROTO */
/* set up specified matrix */
#ifndef NO_PROTO
    a4[0] = -2.2f;
    a4[4] = 3.3f;
    a4[8] = 4.4f;
    a4[12] = 5.5f;
    a4[1] = .0023f;
    a4[5] = -727.12f;
    a4[9] = 2.09f;
    a4[13] = 33.33f;
    a4[2] = 0.f;
    a4[6] = 34.f;
    a4[10] = 54.1f;
    a4[14] = -.045f;
    a4[3] = 7.f;
    a4[7] = 6.f;
    a4[11] = 5.f;
    a4[15] = 4.f;
#else /* NO_PROTO */
    a4[0] = (float)-2.2;
    a4[4] = (float)3.3;
    a4[8] = (float)4.4;
    a4[12] = (float)5.5;
    a4[1] = (float).0023;
    a4[5] = (float)-727.12;
    a4[9] = (float)2.09;
    a4[13] = (float)33.33;
    a4[2] = (float)0.;
    a4[6] = (float)34.;
    a4[10] = (float)54.1;
    a4[14] = (float)-.045;
    a4[3] = (float)7.;
    a4[7] = (float)6.;
    a4[11] = (float)5.;
    a4[15] = (float)4.;
#endif /* NO_PROTO */
/* Set up transform parameters: */
/*   set fixed point */
#ifndef NO_PROTO
    x0 = -1.12f;
    y0 = 2.23f;
    z0 = 3.34f;
#else /* NO_PROTO */
    x0 = (float)-1.12;
    y0 = (float)2.23;
    z0 = (float)3.34;
#endif /* NO_PROTO */
/*   set shift vector */
#ifndef NO_PROTO
    dx = 6.7f;
    dy = 8.9f;
    dz = 10.11f;
#else /* NO_PROTO */
    dx = (float)6.7;
    dy = (float)8.9;
    dz = (float)10.11;
#endif /* NO_PROTO */
/*   set rotation angle */
#ifndef NO_PROTO
    phix = 7.6f;
    phiy = -5.4f;
    phiz = 3.2f;
#else /* NO_PROTO */
    phix = (float)7.6;
    phiy = (float)-5.4;
    phiz = (float)3.2;
#endif /* NO_PROTO */
/*   set scale factors */
#ifndef NO_PROTO
    fx = .0023f;
    fy = -636.34f;
    fz = 2.2f;
#else /* NO_PROTO */
    fx = (float).0023;
    fy = (float)-636.34;
    fz = (float)2.2;
#endif /* NO_PROTO */
/* <Compose transformation matrix 3> returns act4x4 = actual array */
    ncotm3 (a4, &x0, &y0, &z0, &dx, &dy, &dz, &phix, &phiy, &phiz, &fx, &fy, &
	    fz, &errind, act4x4);
    chkinq_("pcotm3", &errind, 6L);
/* Compute exp4x4 = expected array */
    ecotm3_(a4, &x0, &y0, &z0, &dx, &dy, &dz, &phix, &phiy, &phiz, &fx, &fy, &
	    fz, exp4x4);
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 18", "<Compose transformation matrix> should generate a mat"
	    "rix which is the composition of the specified matrix with the sp"
	    "ecified 2D transformation.", 6L, 143L);
#else /* NO_PROTO */
    setmsg_("1 2 18", "<Compose transformation matrix> should generate a mat\
rix which is the composition of the specified matrix with the specified 2D t\
ransformation.", 6L, 143L);
#endif /* NO_PROTO */
/* set up specified matrix */
#ifndef NO_PROTO
    a3[0] = -2.2f;
    a3[3] = 3.3f;
    a3[6] = 5.5f;
    a3[1] = .0023f;
    a3[4] = -727.12f;
    a3[7] = 33.33f;
    a3[2] = 0.f;
    a3[5] = 34.f;
    a3[8] = -.045f;
#else /* NO_PROTO */
    a3[0] = (float)-2.2;
    a3[3] = (float)3.3;
    a3[6] = (float)5.5;
    a3[1] = (float).0023;
    a3[4] = (float)-727.12;
    a3[7] = (float)33.33;
    a3[2] = (float)0.;
    a3[5] = (float)34.;
    a3[8] = (float)-.045;
#endif /* NO_PROTO */
/* Set up parameters: */
/*   set fixed point */
#ifndef NO_PROTO
    x0 = -1.12f;
    y0 = 2.23f;
#else /* NO_PROTO */
    x0 = (float)-1.12;
    y0 = (float)2.23;
#endif /* NO_PROTO */
/*   set shift vector */
#ifndef NO_PROTO
    dx = 6.7f;
    dy = 10.11f;
#else /* NO_PROTO */
    dx = (float)6.7;
    dy = (float)10.11;
#endif /* NO_PROTO */
/*   set rotation angle */
#ifndef NO_PROTO
    phiz = -5.4f;
#else /* NO_PROTO */
    phiz = (float)-5.4;
#endif /* NO_PROTO */
/*   set scale factors */
#ifndef NO_PROTO
    fx = .0023f;
    fy = -636.34f;
#else /* NO_PROTO */
    fx = (float).0023;
    fy = (float)-636.34;
#endif /* NO_PROTO */
/* <Compose transformation matrix> returns act3x3 = actual array */
    ncotm (a3, &x0, &y0, &dx, &dy, &phiz, &fx, &fy, &errind, act3x3);
    chkinq_("pcotm", &errind, 5L);
/* Compute exp3x3 = expected array */
    ecotm_(a3, &x0, &y0, &dx, &dy, &phiz, &fx, &fy, exp3x3);
    L__1 = trnseq_(&c__3, act3x3, exp3x3);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

