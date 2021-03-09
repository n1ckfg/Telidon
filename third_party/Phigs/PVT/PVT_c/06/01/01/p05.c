/* fort/06/01/01/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.01/05                           * */
/*  *    TEST TITLE : Behavior of transformation of points  * */
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
    static real a3[9]	/* was [3][3] */, a4[16]	/* was [4][4] */, px, 
	    py, pz;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp_(real *, real *, real *, real *, real *), 
	    ntp (real *, real *, real *, integer *, real *, real *), etp3_(
	    real *, real *, real *, real *, real *, real *, real *), ntp3 (
	    real *, real *, real *, real *, integer *, real *, real *, real *)
	    , ifpf_(logical *), endit_(void);
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp_(), ntp (), etp3_(), ntp3 (), ifpf_(), 
	    endit_();
    extern logical appeq_();
#endif /* NO_PROTO */
    static real abserr;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real relerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static real acttpx, acttpy, acttpz;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static real exptpx, exptpy, exptpz;

    initgl_("06.01.01/05", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set up tolerance: absolute/relative error */
#ifndef NO_PROTO
    abserr = 1e-7f;
    relerr = 1e-5f;
    setmsg_("1 2 13", "<Transform point 3> should return the 3D point result"
	    "ing from applying the specified transformation matrix to the spe"
	    "cified point.", 6L, 130L);
#else /* NO_PROTO */
    abserr = (float)1e-7;
    relerr = (float)1e-5;
    setmsg_("1 2 13", "<Transform point 3> should return the 3D point result\
ing from applying the specified transformation matrix to the specified point."
	    , 6L, 130L);
#endif /* NO_PROTO */
/* set up transform */
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
/* initialize point to be transformed */
#ifndef NO_PROTO
    px = -262.27f;
    py = .02525f;
    pz = 53.838f;
#else /* NO_PROTO */
    px = (float)-262.27;
    py = (float).02525;
    pz = (float)53.838;
#endif /* NO_PROTO */
/* compute actual transformed point */
    ntp3 (&px, &py, &pz, a4, &errind, &acttpx, &acttpy, &acttpz);
    chkinq_("ptp3", &errind, 4L);
/*  Compute expected point */
    etp3_(&px, &py, &pz, a4, &exptpx, &exptpy, &exptpz);
/* Pass iff points are approximately equal */
    L__1 = appeq_(&acttpx, &exptpx, &abserr, &relerr) && appeq_(&acttpy, &
	    exptpy, &abserr, &relerr) && appeq_(&acttpz, &exptpz, &abserr, &
	    relerr);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 14", "<Transform point> should return the 2D point resultin"
	    "g from applying the specified transformation matrix to the speci"
	    "fied point.", 6L, 128L);
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
    setmsg_("1 2 14", "<Transform point> should return the 2D point resultin\
g from applying the specified transformation matrix to the specified point.", 
	    6L, 128L);
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
/* initialize point to be transformed */
#ifndef NO_PROTO
    px = -262.27f;
    py = 53.838f;
#else /* NO_PROTO */
    px = (float)-262.27;
    py = (float)53.838;
#endif /* NO_PROTO */
/* compute actual transformed point */
    ntp (&px, &py, a3, &errind, &acttpx, &acttpy);
    chkinq_("ptp", &errind, 3L);
/*  Compute expected point */
    etp_(&px, &py, a3, &exptpx, &exptpy);
/* Pass iff points are approximately equal */
    L__1 = appeq_(&acttpx, &exptpx, &abserr, &relerr) && appeq_(&acttpy, &
	    exptpy, &abserr, &relerr);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

