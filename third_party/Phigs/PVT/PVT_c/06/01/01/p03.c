/* fort/06/01/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 06.01.01/03                           * */
/*  *    TEST TITLE : Behavior of rotations                 * */
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
#ifndef NO_PROTO
    extern /* Subroutine */ int ero_(real *, real *), nro (real *, integer *, 
	    real *), ifpf_(logical *), erox_(real *, real *), eroy_(real *, 
	    real *), eroz_(real *, real *), nrox (real *, integer *, real *), 
	    nroy (real *, integer *, real *), nroz (real *, integer *, real *)
	    , endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ero_(), nro (), ifpf_(), erox_(), eroy_(), 
	    eroz_(), nrox (), nroy (), nroz (), endit_();
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
    static real rotang;
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

    initgl_("06.01.01/03", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 2 7", "<Rotate x> should return a correct representation for "
	    "the transformation to rotate a 3D point counterclockwise around "
	    "the x-axis by the specified number of radians.", 5L, 164L);
    rotang = 5.678f;
#else /* NO_PROTO */
    setmsg_("1 2 7", "<Rotate x> should return a correct representation for \
the transformation to rotate a 3D point counterclockwise around the x-axis b\
y the specified number of radians.", 5L, 164L);
    rotang = (float)5.678;
#endif /* NO_PROTO */
/*  <Rotate x> with rotang returns act4x4 = actual array */
    nrox (&rotang, &errind, act4x4);
    chkinq_("prox", &errind, 4L);
/*  Compute exp4x4 = expected array */
    erox_(&rotang, exp4x4);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 8", "<Rotate y> should return a correct representation for "
	    "the transformation to rotate a 3D point counterclockwise around "
	    "the y-axis by the specified number of radians.", 5L, 164L);
    rotang = -.007373f;
#else /* NO_PROTO */
    setmsg_("1 2 8", "<Rotate y> should return a correct representation for \
the transformation to rotate a 3D point counterclockwise around the y-axis b\
y the specified number of radians.", 5L, 164L);
    rotang = (float)-.007373;
#endif /* NO_PROTO */
/*  <Rotate y> with rotang returns act4x4 = actual array */
    nroy (&rotang, &errind, act4x4);
    chkinq_("proy", &errind, 4L);
/*  Compute exp4x4 = expected array */
    eroy_(&rotang, exp4x4);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 9", "<Rotate z> should return a correct representation for "
	    "the transformation to rotate a 3D point counterclockwise around "
	    "the z-axis by the specified number of radians.", 5L, 164L);
    rotang = 8.52525f;
#else /* NO_PROTO */
    setmsg_("1 2 9", "<Rotate z> should return a correct representation for \
the transformation to rotate a 3D point counterclockwise around the z-axis b\
y the specified number of radians.", 5L, 164L);
    rotang = (float)8.52525;
#endif /* NO_PROTO */
/*  <Rotate z> with rotang returns act4x4 = actual array */
    nroz (&rotang, &errind, act4x4);
    chkinq_("proz", &errind, 4L);
/*  Compute exp4x4 = expected array */
    eroz_(&rotang, exp4x4);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__4, act4x4, exp4x4);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 10", "<Rotate> should return a correct representation for t"
	    "he transformation to rotate a 2D point counterclockwise around t"
	    "he origin by the specified number of radians.", 6L, 162L);
    rotang = -11.1111f;
#else /* NO_PROTO */
    setmsg_("1 2 10", "<Rotate> should return a correct representation for t\
he transformation to rotate a 2D point counterclockwise around the origin by\
 the specified number of radians.", 6L, 162L);
    rotang = (float)-11.1111;
#endif /* NO_PROTO */
/*  <Rotate> with rotang returns act3x3 = actual array */
    nro (&rotang, &errind, act3x3);
    chkinq_("pro", &errind, 3L);
/*  Compute exp3x3 = expected array */
    ero_(&rotang, exp3x3);
/*  pass if matrices represent same transformation */
    L__1 = trnseq_(&c__3, act3x3, exp3x3);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

