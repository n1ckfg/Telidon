/* fort/06/01/02/p15.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__14 = 14;
static integer c__2 = 2;
static integer c__5 = 5;
static integer c__102 = 102;
static integer c__104 = 104;
static integer c__3 = 3;
static integer c__105 = 105;
static integer c__103 = 103;
#ifndef NO_PROTO
static real c_b43 = .1f;
static real c_b45 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b43 = (float).1;
static real c_b45 = (float).066666666666666666;
#endif /* NO_PROTO */
static integer c__101 = 101;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/15                           * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization of modelling clipping  * */
/*  *                 volume                                * */
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
    real r__1;

    /* Local variables */
    static real u, z;
    static integer op, ix;
    static real mcv[8]	/* was [4][2] */;
    static integer siz;
    static real mcv3[6]	/* was [6][1] */;
    static integer perm[14];
    static real xloc[5];
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nbltm (real *, real *, real *, real *, real *, real *, real *, 
	    integer *, real *), nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nclst (void), nsmcv (integer *, integer *, real *), nemst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nbltm (), nqpmf (), 
	    nclst (), nsmcv (), nemst ();
#endif /* NO_PROTO */
    static real xform[9]	/* was [3][3] */, nommw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    nopst (integer *), setvs_(char *, integer *, integer *, ftnlen), 
	    nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), nopst (), setvs_(), 
	    nsvwi ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int rn1shf_(integer *, integer *), nsmcv3 (
	    integer *, integer *, real *), dchpfv_(char *, integer *, integer 
	    *, ftnlen), chkinq_(char *, integer *, ftnlen), numlab_(integer *,
	     real *, real *, real *), setdlg_(integer *, integer *, integer *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int rn1shf_(), nsmcv3 (), dchpfv_(), chkinq_(), 
	    numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, expval[14];
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real shifty;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), setrvs_(char *, real *, integer *,
	     ftnlen), nsmcli (integer *), nsmksc (real *), locnpm_(integer *, 
	    integer *, real *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    locppm_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), setrvs_(), 
	    nsmcli (), nsmksc (), locnpm_(), setmsg_(), locppm_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate     postconcatenate    replace */
/* clipping indicator */
/*                noclip      clip */
/* modelling clipping operator */
/*                replace     intersect */
/* marker type */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    initgl_("06.01.02/15", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
    nsvwi (&c__1);
    setasf_(&c__1);
/*  use <inquire polymarker facilities> to determine : */
/*     nommw = nominal marker-size  (DC) */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nommw, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  *** *** *** ***   modelling clipping volume   *** *** *** *** */

/*  set up PERM to randomize position of polymarkers */
    rn1shf_(&c__14, perm);
/*  set up CSS: */
    setrvs_("0.2,0.25,0.3,0.35,0.4", xloc, &siz, 21L);
/*  structure #101 ---------- */
    nsmcli (&c__1);
    nsmk (&c__2);
/*  set marker size scale factor equivalent to WC = 0.03 */
#ifndef NO_PROTO
    r__1 = .025f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).025 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&r__1);
    locnpm_(&c__5, perm, xloc);
    nexst (&c__102);
    locnpm_(&c__5, &perm[8], xloc);
/*  set MCV: point = 0.22,0; vector = -1,0 */
    op = 1;
#ifndef NO_PROTO
    mcv[0] = .22f;
    mcv[1] = 0.f;
    mcv[2] = -1.f;
    mcv[3] = 0.f;
#else /* NO_PROTO */
    mcv[0] = (float).22;
    mcv[1] = (float)0.;
    mcv[2] = (float)-1.;
    mcv[3] = (float)0.;
#endif /* NO_PROTO */
    nsmcv (&op, &c__1, mcv);
    locnpm_(&c__5, &perm[9], xloc);
/*  set local transformation to make markers #11,12 distinguishable */
    fxpty = ylocel_(&perm[4]);
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &u, &errind, xform);
    chkinq_("pbltm", &errind, 5L);
    nslmt (xform, &c__2);
    nexst (&c__104);
/*  re-set local transformation to identity */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    locnpm_(&c__5, &perm[12], xloc);
    locnpm_(&c__5, &perm[13], xloc);
    nexst (&c__105);
    nclst ();
/*  structure #102 ---------- */
    nopst (&c__102);
    locnpm_(&c__5, &perm[1], xloc);
/*  set MCV: point = 0.27,0; vector = -1,0 */
    op = 1;
#ifndef NO_PROTO
    mcv[0] = .27f;
    mcv[1] = 0.f;
    mcv[2] = -1.f;
    mcv[3] = 0.f;
#else /* NO_PROTO */
    mcv[0] = (float).27;
    mcv[1] = (float)0.;
    mcv[2] = (float)-1.;
    mcv[3] = (float)0.;
#endif /* NO_PROTO */
    nsmcv (&op, &c__1, mcv);
    nexst (&c__103);
    locnpm_(&c__5, &perm[7], xloc);
    nclst ();
/*  structure #103 ---------- */
    nopst (&c__103);
    locnpm_(&c__5, &perm[2], xloc);
/*  set MCV3: point = 0.32,0,0; vector = -1,0,1 */
    op = 1;
#ifndef NO_PROTO
    mcv3[0] = .32f;
    mcv3[1] = 0.f;
    mcv3[2] = 0.f;
    mcv3[3] = -1.f;
    mcv3[4] = 0.f;
    mcv3[5] = 1.f;
#else /* NO_PROTO */
    mcv3[0] = (float).32;
    mcv3[1] = (float)0.;
    mcv3[2] = (float)0.;
    mcv3[3] = (float)-1.;
    mcv3[4] = (float)0.;
    mcv3[5] = (float)1.;
#endif /* NO_PROTO */
    nsmcv3 (&op, &c__1, mcv3);
    locnpm_(&c__5, &perm[3], xloc);
    nexst (&c__104);
    locnpm_(&c__5, &perm[6], xloc);
    nclst ();
/*  structure #104 ---------- */
    nopst (&c__104);
    locnpm_(&c__5, &perm[4], xloc);
/*  set MCV: point = 0.37,0; vector = -1,0 */
    op = 1;
#ifndef NO_PROTO
    mcv[0] = .37f;
    mcv[1] = 0.f;
    mcv[2] = -1.f;
    mcv[3] = 0.f;
#else /* NO_PROTO */
    mcv[0] = (float).37;
    mcv[1] = (float)0.;
    mcv[2] = (float)-1.;
    mcv[3] = (float)0.;
#endif /* NO_PROTO */
    nsmcv (&op, &c__1, mcv);
    locnpm_(&c__5, &perm[5], xloc);
    nclst ();
/*  structure #105 ---------- */
    nopst (&c__105);
    nsmcli (&c__0);
    nsmk (&c__5);
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b43, &r__1, &c_b45);
    setrvs_("0.5,0.55,0.6,0.65,0.7", xloc, &siz, 21L);
/*  Expected number of markers (except #14, deliberately incorrect): */
    setvs_("5,5,2,3,3,4,3,2,5,1,1,4,1,2", expval, &siz, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	locnpm_(&expval[ix - 1], &perm[ix - 1], xloc);
/* L300: */
    }
    nclst ();
#ifndef NO_PROTO
    setmsg_("23 26 40 41 42 43 49 50 51 57 58 59", "The current modelling cl"
	    "ipping volume should be saved and restored by <execute structure"
	    "> during traversal.", 35L, 107L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR MCV: On which line is the num"
	    "ber of plus-markers NOT equal to that of the cross-markers?", &
	    c__14, &perm[13], 122L);
#else /* NO_PROTO */
    setmsg_("23 26 40 41 42 43 49 50 51 57 58 59", "The current modelling cl\
ipping volume should be saved and restored by <execute structure> during tra\
versal.", 35L, 107L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR MCV: On which line is the num\
ber of plus-markers NOT equal to that of the cross-markers?", &c__14, &perm[
	    13], 122L);
#endif /* NO_PROTO */
/*  *** *** *** ***   modelling clipping indicator   *** *** *** *** */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L400: */
    }
/*  set up PERM to randomize position of polymarkers */
    rn1shf_(&c__14, perm);
#ifndef NO_PROTO
    xloc[0] = .2f;
#else /* NO_PROTO */
    xloc[0] = (float).2;
#endif /* NO_PROTO */
/*  structure #101 ---------- */
    nopst (&c__101);
    nsvwi (&c__1);
    setasf_(&c__1);
/*  set MCV, clip out all of MC-space: */
    op = 1;
#ifndef NO_PROTO
    mcv[0] = xloc[0] - .01f;
#else /* NO_PROTO */
    mcv[0] = xloc[0] - (float).01;
#endif /* NO_PROTO */
    mcv[1] = z;
    mcv[2] = -(doublereal)u;
    mcv[3] = z;
#ifndef NO_PROTO
    mcv[4] = xloc[0] + .01f;
#else /* NO_PROTO */
    mcv[4] = xloc[0] + (float).01;
#endif /* NO_PROTO */
    mcv[5] = z;
    mcv[6] = u;
    mcv[7] = z;
    nsmcv (&op, &c__1, mcv);
    nsmk (&c__2);
/*  set marker size scale factor equivalent to WC = 0.03 */
#ifndef NO_PROTO
    r__1 = .03f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).03 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&r__1);
    locppm_(perm, xloc);
    nexst (&c__102);
    locppm_(&perm[8], xloc);
    nsmcli (&c__1);
    locppm_(&perm[9], xloc);
/*  set local transformation to make markers #11,12 distinguishable */
    fxpty = ylocel_(&perm[4]);
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &u, &errind, xform);
    chkinq_("pbltm", &errind, 5L);
    nslmt (xform, &c__2);
    nexst (&c__104);
/*  re-set local transformation to identity */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    locppm_(&perm[12], xloc);
    locppm_(&perm[13], xloc);
    nexst (&c__105);
    nclst ();
/*  structure #102 ---------- */
    nopst (&c__102);
    locppm_(&perm[1], xloc);
    nsmcli (&c__1);
    nexst (&c__103);
    locppm_(&perm[7], xloc);
    nclst ();
/*  structure #103 ---------- */
    nopst (&c__103);
    locppm_(&perm[2], xloc);
    nsmcli (&c__0);
    locppm_(&perm[3], xloc);
    nexst (&c__104);
    locppm_(&perm[6], xloc);
    nclst ();
/*  structure #104 ---------- */
    nopst (&c__104);
    locppm_(&perm[4], xloc);
    nsmcli (&c__1);
    locppm_(&perm[5], xloc);
    nclst ();
/*  structure #105 ---------- */
    nopst (&c__105);
    nsmcli (&c__0);
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b43, &r__1, &c_b45);
#ifndef NO_PROTO
    xloc[0] += .1f;
#else /* NO_PROTO */
    xloc[0] += (float).1;
#endif /* NO_PROTO */
/*  All y-locations correspond to PERM as above. */
    setvs_("0,0,1,0,0,1,0,1,0,1,1,1,1,0", expval, &siz, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	if (expval[ix - 1] == 1) {
	    locppm_(&perm[ix - 1], xloc);
	}
/* L500: */
    }
#ifndef NO_PROTO
    setmsg_("29 52 53 54 55 57 58 59", "The current modelling clipping indic"
	    "ator should be saved and restored by <execute structure> during "
	    "traversal.", 23L, 110L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR CLIPPING INDICATOR: Which lin"
	    "e does NOT contain exactly one marker?", &c__14, &perm[13], 101L);

#else /* NO_PROTO */
    setmsg_("29 52 53 54 55 57 58 59", "The current modelling clipping indic\
ator should be saved and restored by <execute structure> during traversal.", 
	    23L, 110L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR CLIPPING INDICATOR: Which lin\
e does NOT contain exactly one marker?", &c__14, &perm[13], 101L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

