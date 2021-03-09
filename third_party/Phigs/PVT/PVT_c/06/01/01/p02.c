/* fort/06/01/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 06.01.01/02                           * */
/*  *    TEST TITLE : Behavior of scaling                   * */
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
    static real fx, fy, fz;
#ifndef NO_PROTO
    extern /* Subroutine */ int esc_(real *, real *, real *), nsc (real *, 
	    real *, integer *, real *), esc3_(real *, real *, real *, real *),
	     nsc3 (real *, real *, real *, integer *, real *), ifpf_(logical *
	    ), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int esc_(), nsc (), esc3_(), nsc3 (), ifpf_(), 
	    endit_();
#endif /* NO_PROTO */
    static real act3x3[9]	/* was [3][3] */, act4x4[16]	/* was [4][4] 
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

    initgl_("06.01.01/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 2 5", "<Scale 3> should return a correct representation for t"
	    "he transformation to scale a 3D point, with non-zero parameters.",
	     5L, 118L);
    fx = -33.3f;
    fy = .0076f;
    fz = 2.2f;
#else /* NO_PROTO */
    setmsg_("1 2 5", "<Scale 3> should return a correct representation for t\
he transformation to scale a 3D point, with non-zero parameters.", 5L, 118L);
    fx = (float)-33.3;
    fy = (float).0076;
    fz = (float)2.2;
#endif /* NO_PROTO */
/*  <Scale 3> with fx,fy,fz returns act4x4 = actual array */
    nsc3 (&fx, &fy, &fz, &errind, act4x4);
    chkinq_("psc3", &errind, 4L);
/*  Compute exp4x4 = expected array */
    esc3_(&fx, &fy, &fz, exp4x4);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 5", "<Scale 3> should return a correct representation for t"
	    "he transformation to scale a 3D point, with zero parameters.", 5L,
	     114L);
    fx = 0.f;
    fy = .0076f;
    fz = 0.f;
#else /* NO_PROTO */
    setmsg_("1 2 5", "<Scale 3> should return a correct representation for t\
he transformation to scale a 3D point, with zero parameters.", 5L, 114L);
    fx = (float)0.;
    fy = (float).0076;
    fz = (float)0.;
#endif /* NO_PROTO */
/*  <Scale 3> with fx,fy,fz returns act4x4 = actual array */
    nsc3 (&fx, &fy, &fz, &errind, act4x4);
    chkinq_("psc3", &errind, 4L);
/*  Compute exp4x4 = expected array */
    esc3_(&fx, &fy, &fz, exp4x4);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 6", "<Scale> should return a correct representation for the"
	    " transformation to scale a 2D point, with non-zero parameters.", 
	    5L, 116L);
    fx = -33.3f;
    fy = .0076f;
#else /* NO_PROTO */
    setmsg_("1 2 6", "<Scale> should return a correct representation for the\
 transformation to scale a 2D point, with non-zero parameters.", 5L, 116L);
    fx = (float)-33.3;
    fy = (float).0076;
#endif /* NO_PROTO */
/*  <Scale> with fx,fy returns act3x3 = actual array */
    nsc (&fx, &fy, &errind, act3x3);
    chkinq_("psc", &errind, 3L);
/*  Compute exp3x3 = expected array */
    esc_(&fx, &fy, exp3x3);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__3, act3x3, exp3x3);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 6", "<Scale> should return a correct representation for the"
	    " transformation to scale a 2D point, with zero parameters.", 5L, 
	    112L);
    fx = 0.f;
    fy = 0.f;
#else /* NO_PROTO */
    setmsg_("1 2 6", "<Scale> should return a correct representation for the\
 transformation to scale a 2D point, with zero parameters.", 5L, 112L);
    fx = (float)0.;
    fy = (float)0.;
#endif /* NO_PROTO */
/*  <Scale> with fx,fy returns act3x3 = actual array */
    nsc (&fx, &fy, &errind, act3x3);
    chkinq_("psc", &errind, 3L);
/*  Compute exp3x3 = expected array */
    esc_(&fx, &fy, exp3x3);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__3, act3x3, exp3x3);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

