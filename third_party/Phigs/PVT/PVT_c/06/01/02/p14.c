/* fort/06/01/02/p14.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__801 = 801;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__5 = 5;
static integer c__3 = 3;
static integer c__106 = 106;
static integer c__101 = 101;
static integer c__2 = 2;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b17 = .5f;
#else /* NO_PROTO */
static real c_b17 = (float).5;
#endif /* NO_PROTO */
static integer c__102 = 102;
static integer c__103 = 103;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/14                           * */
/*  *    TEST TITLE : Restore MCV                           * */
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
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int win6_(integer *, integer *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int win6_();
#endif /* NO_PROTO */
    static real hloc[6], mscf;
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk ();
#endif /* NO_PROTO */
    static real mcv3d[6]	/* was [6][1] */;
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum2, delta;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqpmf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , integer *), nclst (void), nrmcv (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqpmf (), nclst (), nrmcv ();
#endif /* NO_PROTO */
    static real nomms, xsize, ysize;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nexst (integer *), nsvwi (
	    integer *), nsmcv3 (integer *, integer *, real *), clpair_(real *,
	     real *, real *, real *, integer *, real *, real *), dchpfv_(char 
	    *, integer *, integer *, ftnlen), chkinq_(char *, integer *, 
	    ftnlen), setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nexst (), nsvwi (), nsmcv3 (), 
	    clpair_(), dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, ranwin[6];
    static real xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsmksc (real *), nspmci (integer *
	    ), nsmcli (integer *), rnperm_(integer *, integer *), setmsg_(
	    char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsmksc (), 
	    nspmci (), nsmcli (), rnperm_(), setmsg_();
#endif /* NO_PROTO */


/* aspect source */
/*                bundled     individual */
/* clipping indicator */
/*                noclip      clip */
/* modelling clipping operator */
/*                replace     intersect */
/*  marker type   '.',   '+',  '*',  'o',  'x' */
    initgl_("06.01.02/14", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 111;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  Adjust polymarker size and color */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
#ifndef NO_PROTO
    mscf = .02f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    mscf = (float).02 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&mscf);
    nsmk (&c__5);
    nspmci (&c__3);
/*  set modelling clipping indicator = CLIP */
    nsmcli (&c__1);
/*  Set up structure 106 to label 6 windows */
    nexst (&c__106);
    nexst (&c__101);
    nclst ();
/*  Divide screen up into 6 square labelled areas for all test cases */
    win6_(&c__106, &c__2, &xsize, &ysize, xwinlo, ywinlo);
/*  *** *** *** ***   Restore MCV    *** *** *** *** */
#ifndef NO_PROTO
    delta = .05f;
#else /* NO_PROTO */
    delta = (float).05;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 5; ++ix) {
#ifndef NO_PROTO
	hloc[ix - 1] = ix * 3 * delta + .1f;
#else /* NO_PROTO */
	hloc[ix - 1] = ix * 3 * delta + (float).1;
#endif /* NO_PROTO */
/* L10: */
    }
    rnperm_(&c__6, ranwin);
/* Set up constant values for MC plane */
#ifndef NO_PROTO
    mcv3d[0] = 0.f;
    mcv3d[1] = 0.f;
    mcv3d[3] = 0.f;
    mcv3d[4] = 0.f;
    mcv3d[5] = 1.f;
#else /* NO_PROTO */
    mcv3d[0] = (float)0.;
    mcv3d[1] = (float)0.;
    mcv3d[3] = (float)0.;
    mcv3d[4] = (float)0.;
    mcv3d[5] = (float)1.;
#endif /* NO_PROTO */
/*  *** *** *** ***  Structure 101  *** *** *** *** */
    nopst (&c__101);
/*  draw visible double polymarker */
    clpair_(xwinlo, ywinlo, &xsize, &ysize, &ranwin[5], &delta, &c_b17);
/*  set MCV #1 */
    mcv3d[2] = hloc[0];
    nsmcv3 (&c__1, &c__1, mcv3d);
    nexst (&c__102);
    nclst ();
/*  *** *** *** ***  Structure 102  *** *** *** *** */
    nopst (&c__102);
/*  inherit MCV #1 */
/*  set MCV #2 */
    mcv3d[2] = hloc[1];
    nsmcv3 (&c__1, &c__1, mcv3d);
/*  restore MCV #1 */
    nrmcv ();
/*  draw half-visible double polymarker */
    clpair_(xwinlo, ywinlo, &xsize, &ysize, ranwin, &delta, hloc);
/*  set MCV #3 */
    mcv3d[2] = hloc[2];
    nsmcv3 (&c__1, &c__1, mcv3d);
    nexst (&c__103);
/*  draw half-visible double polymarker */
    clpair_(xwinlo, ywinlo, &xsize, &ysize, &ranwin[1], &delta, &hloc[2]);
/*  restore MCV #1 */
    nrmcv ();
/*  draw half-visible double polymarker */
    clpair_(xwinlo, ywinlo, &xsize, &ysize, &ranwin[2], &delta, hloc);
    nclst ();
/*  *** *** *** ***  Structure 103   *** *** *** *** */
    nopst (&c__103);
/*  inherit MCV#3 */
/*  set MCV #4 */
    mcv3d[2] = hloc[3];
    nsmcv3 (&c__1, &c__1, mcv3d);
/*  draw half-visible double polymarker */
    clpair_(xwinlo, ywinlo, &xsize, &ysize, &ranwin[3], &delta, &hloc[3]);
/*  restore MCV #3 */
    nrmcv ();
/*  draw half-visible double polymarker */
    clpair_(xwinlo, ywinlo, &xsize, &ysize, &ranwin[4], &delta, &hloc[2]);
/*  set MCV #5 */
    mcv3d[2] = hloc[4];
    nsmcv3 (&c__1, &c__1, mcv3d);
    nclst ();
#ifndef NO_PROTO
    setmsg_("23 40 43 51 56", "<Restore modelling clipping volume> should ca"
	    "use the current modelling clipping volume to be reset to the val"
	    "ue inherited by the structure being traversed.", 14L, 155L);
#else /* NO_PROTO */
    setmsg_("23 40 43 51 56", "<Restore modelling clipping volume> should ca\
use the current modelling clipping volume to be reset to the value inherited\
 by the structure being traversed.", 14L, 155L);
#endif /* NO_PROTO */
    dchpfv_("RESTORE MCV: Which box does NOT contain exactly one marker? ", &
	    c__6, &ranwin[5], 60L);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

