/* fort/06/01/01/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 06.01.01/06                           * */
/*  *    TEST TITLE : Building transformations              * */
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
    static real x0, y0, z0, dx, dy, dz, fx, fy, fz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real phix, phiy, phiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_(), endit_();
#endif /* NO_PROTO */
    static real act3x3[9]	/* was [3][3] */, act4x4[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nbltm (real *, real *, real *, real *, real *,
	     real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nbltm ();
#endif /* NO_PROTO */
    static real exp3x3[9]	/* was [3][3] */, exp4x4[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *),
	     nbltm3 (real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, integer *, real *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm3_(), nbltm3 (), chkinq_();
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

    initgl_("06.01.01/06", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 2 15", "<Build transformation matrix 3> should generate a mat"
	    "rix to perform the specified 3D transformation.", 6L, 100L);
#else /* NO_PROTO */
    setmsg_("1 2 15", "<Build transformation matrix 3> should generate a mat\
rix to perform the specified 3D transformation.", 6L, 100L);
#endif /* NO_PROTO */
/* Set up parameters: */
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
/* <Build transformation matrix 3> returns act4x4 = actual array */
    nbltm3 (&x0, &y0, &z0, &dx, &dy, &dz, &phix, &phiy, &phiz, &fx, &fy, &fz, 
	    &errind, act4x4);
    chkinq_("pbltm3", &errind, 6L);
/* Compute exp4x4 = expected array */
    ebltm3_(&x0, &y0, &z0, &dx, &dy, &dz, &phix, &phiy, &phiz, &fx, &fy, &fz, 
	    exp4x4);
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 16", "<Build transformation matrix> should generate a matri"
	    "x to perform the specified 2D transformation.", 6L, 98L);
#else /* NO_PROTO */
    setmsg_("1 2 16", "<Build transformation matrix> should generate a matri\
x to perform the specified 2D transformation.", 6L, 98L);
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
/* <Build transformation matrix> returns act3x3 = actual array */
    nbltm (&x0, &y0, &dx, &dy, &phiz, &fx, &fy, &errind, act3x3);
    chkinq_("pbltm", &errind, 5L);
/* Compute exp3x3 = expected array */
    ebltm_(&x0, &y0, &dx, &dy, &phiz, &fx, &fy, exp3x3);
    L__1 = trnseq_(&c__3, act3x3, exp3x3);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

