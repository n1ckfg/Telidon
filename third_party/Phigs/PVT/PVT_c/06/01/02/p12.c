/* fort/06/01/02/p12.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
#ifndef NO_PROTO
static real c_b11 = -.34906585000000001f;
static real c_b12 = .34906585000000001f;
static real c_b15 = .5f;
static real c_b17 = 0.f;
static real c_b22 = 1.f;
#else /* NO_PROTO */
static real c_b11 = (float)-.34906585000000001;
static real c_b12 = (float).34906585000000001;
static real c_b15 = (float).5;
static real c_b17 = (float)0.;
static real c_b22 = (float)1.;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b31 = .01f;
static real c_b34 = -.01f;
static real c_b38 = 1.2217304750000002f;
static real c_b39 = 1.9198621750000002f;
#else /* NO_PROTO */
static real c_b31 = (float).01;
static real c_b34 = (float)-.01;
static real c_b38 = (float)1.2217304750000002;
static real c_b39 = (float)1.9198621750000002;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__9 = 9;
static integer c__4 = 4;
static integer c__30 = 30;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/12                           * */
/*  *    TEST TITLE : Geometry of modelling clipping        * */
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
    integer i__1;

    /* Local variables */
    static real xa[20], ya[20], xf[16]	/* was [4][4] */;
    static integer ix, jx;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), npm (integer 
	    *, real *, real *), etr3_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), npm (), etr3_();
#endif /* NO_PROTO */
    static real mscf, inxf[16]	/* was [4][4] */;
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *), nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk (), nsln ();
#endif /* NO_PROTO */
    static integer lvis, rvis;
    static real xrot, yrot;
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real mcvnd[6]	/* was [6][1] */;
    static integer rnloc[9];
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nclst (void), nsmcv (integer *, integer *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int nqpmf (), nclst (), nsmcv ();
#endif /* NO_PROTO */
    static real nomms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst ();
#endif /* NO_PROTO */
    static real outxf[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsvwi (integer *), clpmk5_(
	    char *, real *, real *, real *, real *, ftnlen), nbltm3 (real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, integer *, real *), nsmcv3 (integer *, 
	    integer *, real *), nslmt3 (real *, integer *);
    extern logical dchflv_(char *, integer *, integer *, ftnlen);
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     chkinq_(char *, integer *, ftnlen), setdlg_(integer *, integer *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsvwi (), clpmk5_(), nbltm3 (), 
	    nsmcv3 (), nslmt3 ();
    extern logical dchflv_();
    extern /* Subroutine */ int dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsmksc (real *), setmsg_(char *, 
	    char *, ftnlen, ftnlen), nsmcli (integer *), rnperm_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern integer rndint_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsmksc (), 
	    setmsg_(), nsmcli (), rnperm_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* clipping indicator */
/*                noclip      clip */
/* modelling clipping operator */
/*                replace     intersect */
/* marker type */
/* linetype */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    initgl_("06.01.02/12", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  Adjust polymarker size */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
#ifndef NO_PROTO
    mscf = .02f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    mscf = (float).02 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&mscf);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
/*  *** *** *** *** ***   Clipping 3D   *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("23 29 40 41 42 52 53 58 59", "A polymarker should be clipped if"
	    " and only if (1) its WC position is outside the current WC model"
	    "ling clipping volume as set by <set modelling clipping volume 3>"
	    " and (2) the current clipping indicator = CLIP.", 26L, 208L);
#else /* NO_PROTO */
    setmsg_("23 29 40 41 42 52 53 58 59", "A polymarker should be clipped if\
 and only if (1) its WC position is outside the current WC modelling clippin\
g volume as set by <set modelling clipping volume 3> and (2) the current cli\
pping indicator = CLIP.", 26L, 208L);
#endif /* NO_PROTO */
/*  set up transformation to change xy plane into a plane slightly */
/*  rotated about .5,.5,0 and then shifted so as to contain */
/*  (.5, .5, .5): */
    xrot = rndrl_(&c_b11, &c_b12);
    yrot = rndrl_(&c_b11, &c_b12);
    nbltm3 (&c_b15, &c_b15, &c_b17, &c_b17, &c_b17, &c_b15, &xrot, &yrot, &
	    c_b17, &c_b22, &c_b22, &c_b22, &errind, xf);
    chkinq_("pbltm3", &errind, 6L);
/*  set local transformation to xf */
    nslmt3 (xf, &c__2);
/*  set modelling clipping volume to xy plane in MC: */
/*    point  = 0,0,0 */
/*    vector = 0,0,1 */
#ifndef NO_PROTO
    mcvnd[0] = 0.f;
    mcvnd[1] = 0.f;
    mcvnd[2] = 0.f;
    mcvnd[3] = 0.f;
    mcvnd[4] = 0.f;
    mcvnd[5] = 1.f;
#else /* NO_PROTO */
    mcvnd[0] = (float)0.;
    mcvnd[1] = (float)0.;
    mcvnd[2] = (float)0.;
    mcvnd[3] = (float)0.;
    mcvnd[4] = (float)0.;
    mcvnd[5] = (float)1.;
#endif /* NO_PROTO */
    nsmcv3 (&c__1, &c__1, mcvnd);
/*  Generate matrices to shift along Z axis (in or out) */
    etr3_(&c_b17, &c_b17, &c_b31, inxf);
    etr3_(&c_b17, &c_b17, &c_b34, outxf);
    clpmk5_("3", mcvnd, xf, inxf, outxf, 1L);
/*  *** *** *** *** ***   Clipping 2D   *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("23 29 40 41 42 49 52 53 58 59", "A polymarker should be clipped"
	    " if and only if (1) its WC position is outside the current WC mo"
	    "delling clipping volume as set by <set modelling clipping volume"
	    "> and (2) the current clipping indicator = CLIP.", 29L, 206L);
#else /* NO_PROTO */
    setmsg_("23 29 40 41 42 49 52 53 58 59", "A polymarker should be clipped\
 if and only if (1) its WC position is outside the current WC modelling clip\
ping volume as set by <set modelling clipping volume> and (2) the current cl\
ipping indicator = CLIP.", 29L, 206L);
#endif /* NO_PROTO */
/*  set up transformation to change y=.5 plane into a plane slightly */
/*  rotated about .5,.5,0 and then shifted so as to contain */
/*  (.5, .5, .5): */
    xrot = rndrl_(&c_b38, &c_b39);
    yrot = rndrl_(&c_b11, &c_b12);
    nbltm3 (&c_b15, &c_b15, &c_b17, &c_b17, &c_b17, &c_b15, &xrot, &yrot, &
	    c_b17, &c_b22, &c_b22, &c_b22, &errind, xf);
    chkinq_("pbltm3", &errind, 6L);
/*  set local transformation to xf */
    nslmt3 (xf, &c__2);
/*  Set Clipping plane */
#ifndef NO_PROTO
    mcvnd[0] = 0.f;
    mcvnd[1] = .5f;
    mcvnd[2] = 0.f;
    mcvnd[3] = 1.f;
#else /* NO_PROTO */
    mcvnd[0] = (float)0.;
    mcvnd[1] = (float).5;
    mcvnd[2] = (float)0.;
    mcvnd[3] = (float)1.;
#endif /* NO_PROTO */
    nsmcv (&c__1, &c__1, mcvnd);
    clpmk5_("2", mcvnd, xf, inxf, outxf, 1L);
/*  *** *** *** *** ***  Zero Half Space  *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("39 41 43", "In <set modelling clipping volume>, an empty list o"
	    "f half-spaces should denote all of WC space.", 8L, 95L);
    xa[0] = .5f;
    ya[0] = 0.f;
    xa[1] = .5f;
    ya[1] = 1.f;
#else /* NO_PROTO */
    setmsg_("39 41 43", "In <set modelling clipping volume>, an empty list o\
f half-spaces should denote all of WC space.", 8L, 95L);
    xa[0] = (float).5;
    ya[0] = (float)0.;
    xa[1] = (float).5;
    ya[1] = (float)1.;
#endif /* NO_PROTO */
    nsln (&c__3);
    npl (&c__2, xa, ya);
    nsmk (&c__2);
    nsmcli (&c__1);
/*  Set 2D Clipping plane */
#ifndef NO_PROTO
    mcvnd[0] = .5f;
    mcvnd[1] = .5f;
    mcvnd[2] = -1.f;
    mcvnd[3] = 0.f;
#else /* NO_PROTO */
    mcvnd[0] = (float).5;
    mcvnd[1] = (float).5;
    mcvnd[2] = (float)-1.;
    mcvnd[3] = (float)0.;
#endif /* NO_PROTO */
    nsmcv (&c__1, &c__1, mcvnd);
/*  Intersect with zero 3D Clipping planes */
#ifndef NO_PROTO
    mcvnd[0] = .5f;
    mcvnd[1] = .5f;
    mcvnd[2] = 0.f;
    mcvnd[3] = 1.f;
    mcvnd[4] = 0.f;
    mcvnd[5] = 0.f;
#else /* NO_PROTO */
    mcvnd[0] = (float).5;
    mcvnd[1] = (float).5;
    mcvnd[2] = (float)0.;
    mcvnd[3] = (float)1.;
    mcvnd[4] = (float)0.;
    mcvnd[5] = (float)0.;
#endif /* NO_PROTO */
    nsmcv3 (&c__2, &c__0, mcvnd);
/*  MCV should be unchanged: */
    rnperm_(&c__9, rnloc);
    lvis = rndint_(&c__2, &c__4);
    i__1 = 9 - lvis;
    rvis = rndint_(&c__1, &i__1);
/*  draw pairs of markers, left visible, right clipped */
    i__1 = lvis;
    for (ix = 1; ix <= i__1; ++ix) {
	jx = ix + lvis;
#ifndef NO_PROTO
	xa[ix - 1] = .4f;
	xa[jx - 1] = .6f;
	ya[ix - 1] = rnloc[ix - 1] / 10.f;
#else /* NO_PROTO */
	xa[ix - 1] = (float).4;
	xa[jx - 1] = (float).6;
	ya[ix - 1] = rnloc[ix - 1] / (float)10.;
#endif /* NO_PROTO */
	ya[jx - 1] = ya[ix - 1];
/* L300: */
    }
    i__1 = lvis << 1;
    npm (&i__1, xa, ya);
/*  Set 2D Clipping plane to all WC space */
#ifndef NO_PROTO
    mcvnd[0] = .5f;
    mcvnd[1] = .5f;
    mcvnd[2] = 0.f;
    mcvnd[3] = 1.f;
#else /* NO_PROTO */
    mcvnd[0] = (float).5;
    mcvnd[1] = (float).5;
    mcvnd[2] = (float)0.;
    mcvnd[3] = (float)1.;
#endif /* NO_PROTO */
    nsmcv (&c__1, &c__0, mcvnd);
/*  draw pairs of markers, left visible, right clipped */
    i__1 = rvis;
    for (ix = 1; ix <= i__1; ++ix) {
	jx = ix + rvis;
#ifndef NO_PROTO
	xa[ix - 1] = .4f;
	xa[jx - 1] = .6f;
	ya[ix - 1] = rnloc[ix + lvis - 1] / 10.f;
#else /* NO_PROTO */
	xa[ix - 1] = (float).4;
	xa[jx - 1] = (float).6;
	ya[ix - 1] = rnloc[ix + lvis - 1] / (float)10.;
#endif /* NO_PROTO */
	ya[jx - 1] = ya[ix - 1];
/* L310: */
    }
    i__1 = rvis << 1;
    npm (&i__1, xa, ya);
    lvis += rvis;
#ifndef NO_PROTO
    if (dchflv_("EMPTY LIST OF HALF-SPACES: How many markers are visible to "
	    "the left of the dotted line?", &c__30, &lvis, 87L)) {
#else /* NO_PROTO */
    if (dchflv_("EMPTY LIST OF HALF-SPACES: How many markers are visible to \
the left of the dotted line?", &c__30, &lvis, 87L)) {
#endif /* NO_PROTO */
	goto L666;
    }
#ifndef NO_PROTO
    dchpfv_("EMPTY LIST OF HALF-SPACES: How many markers are visible to the "
	    "right of the dotted line?", &c__30, &rvis, 88L);
#else /* NO_PROTO */
    dchpfv_("EMPTY LIST OF HALF-SPACES: How many markers are visible to the \
right of the dotted line?", &c__30, &rvis, 88L);
#endif /* NO_PROTO */
L666:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

