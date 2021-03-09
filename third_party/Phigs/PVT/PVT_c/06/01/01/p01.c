/* fort/06/01/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 06.01.01/01                           * */
/*  *    TEST TITLE : Behavior of translations              * */
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
    static real dx, dy, dz;
#ifndef NO_PROTO
    extern /* Subroutine */ int etr_(real *, real *, real *), ntr (real *, 
	    real *, integer *, real *), etr3_(real *, real *, real *, real *),
	     ntr3 (real *, real *, real *, integer *, real *), ifpf_(logical *
	    ), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr_(), ntr (), etr3_(), ntr3 (), ifpf_(), 
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

    initgl_("06.01.01/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 2 3", "<Translate 3> should return a correct representation f"
	    "or the transformation to translate a 3D point, with non-zero par"
	    "ameters.", 5L, 126L);
    dx = -33.3f;
    dy = .0076f;
    dz = 2.2f;
#else /* NO_PROTO */
    setmsg_("1 2 3", "<Translate 3> should return a correct representation f\
or the transformation to translate a 3D point, with non-zero parameters.", 5L,
	     126L);
    dx = (float)-33.3;
    dy = (float).0076;
    dz = (float)2.2;
#endif /* NO_PROTO */
/*  <Translate 3> with dx,dy,dz returns act4x4 = actual array */
    ntr3 (&dx, &dy, &dz, &errind, act4x4);
    chkinq_("ptr3", &errind, 4L);
/*  Compute exp4x4 = expected array */
    etr3_(&dx, &dy, &dz, exp4x4);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 3", "<Translate 3> should return a correct representation f"
	    "or the transformation to translate a 3D point, with zero paramet"
	    "ers.", 5L, 122L);
    dx = 0.f;
    dy = .0076f;
    dz = 0.f;
#else /* NO_PROTO */
    setmsg_("1 2 3", "<Translate 3> should return a correct representation f\
or the transformation to translate a 3D point, with zero parameters.", 5L, 
	    122L);
    dx = (float)0.;
    dy = (float).0076;
    dz = (float)0.;
#endif /* NO_PROTO */
/*  <Translate 3> with dx,dy,dz returns act4x4 = actual array */
    ntr3 (&dx, &dy, &dz, &errind, act4x4);
    chkinq_("ptr3", &errind, 4L);
/*  Compute exp4x4 = expected array */
    etr3_(&dx, &dy, &dz, exp4x4);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 4", "<Translate> should return a correct representation for"
	    " the transformation to translate a 2D point, with non-zero param"
	    "eters.", 5L, 124L);
    dx = -33.3f;
    dy = .0076f;
#else /* NO_PROTO */
    setmsg_("1 2 4", "<Translate> should return a correct representation for\
 the transformation to translate a 2D point, with non-zero parameters.", 5L, 
	    124L);
    dx = (float)-33.3;
    dy = (float).0076;
#endif /* NO_PROTO */
/*  <Translate> with dx,dy returns act3x3 = actual array */
    ntr (&dx, &dy, &errind, act3x3);
    chkinq_("ptr", &errind, 3L);
/*  Compute exp3x3 = expected array */
    etr_(&dx, &dy, exp3x3);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__3, act3x3, exp3x3);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 4", "<Translate> should return a correct representation for"
	    " the transformation to translate a 2D point, with zero parameter"
	    "s.", 5L, 120L);
    dx = 0.f;
    dy = 0.f;
#else /* NO_PROTO */
    setmsg_("1 2 4", "<Translate> should return a correct representation for\
 the transformation to translate a 2D point, with zero parameters.", 5L, 120L)
	    ;
    dx = (float)0.;
    dy = (float)0.;
#endif /* NO_PROTO */
/*  <Translate> with dx,dy returns act3x3 = actual array */
    ntr (&dx, &dy, &errind, act3x3);
    chkinq_("ptr", &errind, 3L);
/*  Compute exp3x3 = expected array */
    etr_(&dx, &dy, exp3x3);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__3, act3x3, exp3x3);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

