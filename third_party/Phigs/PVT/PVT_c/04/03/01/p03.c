/* fort/04/03/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__14 = 14;
static integer c__3 = 3;
static integer c__102 = 102;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__103 = 103;
static integer c__4 = 4;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b63 = .15f;
static real c_b65 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b63 = (float).15;
static real c_b65 = (float).066666666666666666;
#endif /* NO_PROTO */
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b130 = .03f;
static real c_b135 = .7f;
static real c_b136 = .3f;
static real c_b141 = 1.2f;
static real c_b142 = -.2f;
#else /* NO_PROTO */
static real c_b130 = (float).03;
static real c_b135 = (float).7;
static real c_b136 = (float).3;
static real c_b141 = (float)1.2;
static real c_b142 = (float)-.2;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__10 = 10;
static integer c__11 = 11;
#ifndef NO_PROTO
static real c_b217 = .1f;
static real c_b218 = .05f;
#else /* NO_PROTO */
static real c_b217 = (float).1;
static real c_b218 = (float).05;
#endif /* NO_PROTO */
static integer c__12 = 12;
static integer c__13 = 13;
#ifndef NO_PROTO
static real c_b284 = 1.f;
#else /* NO_PROTO */
static real c_b284 = (float)1.;
#endif /* NO_PROTO */
static integer c__15 = 15;
static integer c__17 = 17;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.01/03                           * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization of ASFs                * */
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
    /* Initialized data */

    static logical isavl[5] = { FALSE_,FALSE_,FALSE_,FALSE_,FALSE_ };
    static integer indval[2] = { 2,4 };

    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
    static real xa[10], ya[10];
    static integer ix, ed2, nis;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static integer siz, iix1, iix2, nedt;
    static real xact[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer perm[14];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsii (integer *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsii (), pass_();
#endif /* NO_PROTO */
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspa (real *, real *), nsmk (integer *), 
	    nsln (integer *), nsir (integer *, integer *, integer *, integer *
	    , integer *), nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspa (), nsmk (), nsln (), nsir (), nsis ();
#endif /* NO_PROTO */
    static real xexp[5];
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum2, rdum3;
    static integer ints1, ints2, colia[4]	/* was [2][2] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), nqedf (integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), nqedf ();
#endif /* NO_PROTO */
    static real mkscf;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedi (integer *), nschh (real *), endit_(
	    void), nsici (integer *), xfinh_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedi (), nschh (), endit_(), nsici (), 
	    xfinh_();
#endif /* NO_PROTO */
    static integer opans, expdx[14];
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nspmi (integer *), nemst (integer *), nspmr (integer *, 
	    integer *, integer *, real *, integer *), inmsg_(char *, ftnlen), 
	    nopst (integer *), nqplf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nsplr (integer *, integer *, integer *, real *, integer *), 
	    nsvwi (integer *), nspli (integer *), nexst (integer *), nslmt (
	    real *, integer *), nclst (void), nstxr (integer *, integer *, 
	    integer *, integer *, real *, real *, integer *), nstxi (integer *
	    ), nspar (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nsisi (integer *), 
	    nsedr (integer *, integer *, integer *, integer *, real *, 
	    integer *), nsedt (integer *), rn1shf_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmf (), nspmi (), nemst (), nspmr (), 
	    inmsg_(), nopst (), nqplf (), nsplr (), nsvwi (), nspli (), 
	    nexst (), nslmt (), nclst (), nstxr (), nstxi (), nspar (), 
	    nsisi (), nsedr (), nsedt (), rn1shf_();
#endif /* NO_PROTO */
    static integer asfdef;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchoic_(char *, integer *, integer *, integer 
	    *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchoic_();
#endif /* NO_PROTO */
    static integer asftab[90]	/* was [5][18] */, oppdef, errind, picstr, 
	    ndisct, indmrk, bunmrk;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer thisis;
    static real nomsiz;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real xtxact, xtxexp;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *), discol_(
	    integer *, integer *, integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), chkinq_(char *, integer *, ftnlen), nsmksc (real *), 
	    opfail_(void), setrvs_(char *, real *, integer *, ftnlen), 
	    nslwsc (real *), nsplci (integer *), locppl_(integer *, real *), 
	    asfset_(integer *, integer *, integer *, integer *), setval_(char 
	    *, integer *, ftnlen), numlab_(integer *, real *, real *, real *),
	     dchpfv_(char *, integer *, integer *, ftnlen), nspmci (integer *)
	    , locppm_(integer *, real *), nstxal (integer *, integer *), 
	    nstxfn (integer *), nstxpr (integer *), nschxp (real *), nschsp (
	    real *), nstxci (integer *), loctxt_(integer *, real *), intinh_(
	    integer *, integer *, integer *, integer *), nsiasf (integer *, 
	    integer *), nsedfg (integer *), loctri_(integer *, real *), 
	    nsewsc (real *), nsedci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_(), discol_(), 
	    setmsg_(), chkinq_(), nsmksc (), opfail_(), setrvs_(), nslwsc (), 
	    nsplci (), locppl_(), asfset_(), setval_(), numlab_(), dchpfv_(), 
	    nspmci (), locppm_(), nstxal (), nstxfn (), nstxpr (), nschxp (), 
	    nschsp (), nstxci (), loctxt_(), intinh_(), nsiasf (), nsedfg (), 
	    loctri_(), nsewsc (), nsedci ();
#endif /* NO_PROTO */

/* aspect identifier */
/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* interior style */
/* linetype */
/* marker type */
/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
/* off/on switch for edge flag and error handling mode */
    initgl_("04.03.01/03", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
/*  call DISCOL to try to get 2 distinct foreground colors */
    discol_(&c__2, &globnu_1.wkid, &ndisct);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
#ifndef NO_PROTO
    setmsg_("5 7 8 9", "The implementation should initialize the ASF for mar"
	    "kertype to individual or bundled.", 7L, 85L);
#else /* NO_PROTO */
    setmsg_("5 7 8 9", "The implementation should initialize the ASF for mar\
kertype to individual or bundled.", 7L, 85L);
#endif /* NO_PROTO */
/*  Determine whether individual or bundled is the default (no ASFs */
/*    set yet): */
/*  indmrk = individual markertype = plus or circle, randomly */
/*  bunmrk = bundled markertype = circle or plus, opposite of indmrk */
    indmrk = (rndint_(&c__0, &c__1) << 1) + 2;
    bunmrk = 6 - indmrk;
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomsiz, 
	    &rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  set individual attribute: */
    nsmk (&indmrk);
#ifndef NO_PROTO
    mkscf = .1f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    mkscf = (float).1 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&mkscf);
/*  set bundle #1 */
    nspmr (&globnu_1.wkid, &c__1, &bunmrk, &mkscf, &c__1);
    nspmi (&c__1);
/*  display a polymarker */
#ifndef NO_PROTO
    xa[0] = .5f;
    ya[0] = .5f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    ya[0] = (float).5;
#endif /* NO_PROTO */
    npm (&c__1, xa, ya);
    dchoic_("ASF DEFAULT: Is the displayed marker: 1-plus or 2-circle?", &
	    c__0, &c__2, &opans, 57L);
    nemst (&picstr);
    if (opans == 0) {
	opfail_();
#ifndef NO_PROTO
	inmsg_("Skipping rest of test cases because ASF default cannot be de"
		"termined.", 69L);
#else /* NO_PROTO */
	inmsg_("Skipping rest of test cases because ASF default cannot be de\
termined.", 69L);
#endif /* NO_PROTO */
	goto L666;
    }
    pass_();
    if (indval[opans - 1] == indmrk) {
	asfdef = 1;
	inmsg_("Default for initial value of ASFs is INDIVIDUAL.", 48L);
    } else {
	asfdef = 0;
	inmsg_("Default for initial value of ASFs is BUNDLED.", 45L);
    }
/*  opposite of asfdef */
    oppdef = 1 - asfdef;
/*  All the rest of the test cases use same basic structure network */
/*  for testing inheritance.  Five (distinct if possible) values for */
/*  the attribute to be tested are set up and propagated throughout */
/*  the network.  The first value is the system default from the PDT. */
/*  Note that structure #104 is executed by both #103 and #101. */
/*  Actual results are displayed on the left, expected results on the */
/*  right, with the 14th deliberately made incorrect. */

/*  default = val#1 */
/*    |                  102 */
/*    |                 /  prim 2 */
/*    |               /    attr = val#3   val#3 */
/*    V        val#1/      exec 103---------------103 */
/*  101           /        prim 8                   prim 3 */
/*    prim 1    /                                   attr = val#4 */
/*    exec 102/                                     prim 4 */
/*    prim 9                                        exec 104\ */
/*    attr = val#2                                  prim 7    \ val#4 */
/*    prim 10                                                   \ */
/*    transform             val#2                                 \ */
/*    exec 104-----------------------------------------------------104 */
/*   un-transform                                                   prim 5
/11*/
/*   prim 13                                                        attr =
 val#5*/
/*   prim 14                                                        prim 6
/12*/
/*    exec 105---------->105 */
/*                         expected values */
/*  *** *** ***   inheritance for polyline ASFs   *** *** *** */
/*  asftab = ASF table: */
/*        linetype    linewidth   color */
/*        --------    ---------   ----- */
/*  1:    asfdef      asfdef      asfdef */
/*  2:    individual  bundled     individual */
/*  3:    oppdef      oppdef      oppdef */
/*  4:    bundled     individual  bundled */
/*  5:    asfdef      asfdef      oppdef */
/*  entry #1 always set to ASF default */
    for (ix = 0; ix <= 17; ++ix) {
	asftab[ix * 5] = asfdef;
/* L50: */
    }
    asftab[1] = 1;
    asftab[6] = 0;
    asftab[11] = 1;
    asftab[2] = oppdef;
    asftab[7] = oppdef;
    asftab[12] = oppdef;
    asftab[3] = 0;
    asftab[8] = 1;
    asftab[13] = 0;
    asftab[4] = asfdef;
    asftab[9] = asfdef;
    asftab[14] = oppdef;
/*  PICSTR has been emptied - start over */
    nsvwi (&c__1);
    nqplf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomsiz, 
	    &rdum1, &rdum2, &idum4);
    chkinq_("pqplf", &errind, 5L);
/*  x-location of actual/expected polylines */
    setrvs_("0.2, 0.5", xact, &siz, 8L);
    setrvs_("0.6, 0.9", xexp, &siz, 8L);
/*  randomize order of polylines */
    rn1shf_(&c__14, perm);
/*  Make individual and bundled as distinct as possible: */
/*  set individual attributes: */
    nsln (&c__3);
#ifndef NO_PROTO
    r__1 = .03f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).03 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nslwsc (&r__1);
    nsplci (&c__1);
/*  set bundle #1: */
#ifndef NO_PROTO
    r__1 = .001f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).001 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsplr (&globnu_1.wkid, &c__1, &c__2, &r__1, &c__2);
    nspli (&c__1);
    locppl_(perm, xact);
    nexst (&c__102);
    locppl_(&perm[8], xact);
    asfset_(&c__2, asftab, &c__0, &c__2);
    locppl_(&perm[9], xact);
    xfinh_(perm);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    locppl_(&perm[12], xact);
    locppl_(&perm[13], xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locppl_(&perm[1], xact);
    asfset_(&c__3, asftab, &c__0, &c__2);
    nexst (&c__103);
    locppl_(&perm[7], xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locppl_(&perm[2], xact);
    asfset_(&c__4, asftab, &c__0, &c__2);
    locppl_(&perm[3], xact);
    nexst (&c__104);
    locppl_(&perm[6], xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polyline 5 / 11 */
    locppl_(&perm[4], xact);
    asfset_(&c__5, asftab, &c__0, &c__2);
/*  polyline 6 / 12 */
    locppl_(&perm[5], xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for expected ASFs: */
/*  last "incorrect" index set to 4, rather than 3, because */
/*  #2 and #4 are guaranteed to differ in linetype, which */
/*  in turn, is guaranteed to be distinct */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,4", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	asfset_(&expdx[ix - 1], asftab, &c__0, &c__2);
	locppl_(&perm[ix - 1], xexp);
/* L100: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b63, &r__1, &c_b65);
    nclst ();
#ifndef NO_PROTO
    setmsg_("4 5 6 7 8 9 10 11", "The polyline ASFs should be saved and rest"
	    "ored by <execute structure> during traversal.", 17L, 87L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYLINE ASFS: which pair of "
	    "lines does NOT match?", &c__14, &perm[13], 84L);
#else /* NO_PROTO */
    setmsg_("4 5 6 7 8 9 10 11", "The polyline ASFs should be saved and rest\
ored by <execute structure> during traversal.", 17L, 87L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYLINE ASFS: which pair of \
lines does NOT match?", &c__14, &perm[13], 84L);
#endif /* NO_PROTO */
/*  *** *** ***   inheritance for polymarker ASFs   *** *** *** */
/*  clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  asftab = ASF table: */
/*        markertype    markerwidth   color */
/*        --------      ---------     ----- */
/*  1:    asfdef        asfdef        asfdef */
/*  2:    individual    bundled       individual */
/*  3:    oppdef        oppdef        oppdef */
/*  4:    bundled       individual    bundled */
/*  5:    asfdef        asfdef        oppdef */
/*  entry #1 always set to ASF default */
    asftab[16] = 1;
    asftab[21] = 0;
    asftab[26] = 1;
    asftab[17] = oppdef;
    asftab[22] = oppdef;
    asftab[27] = oppdef;
    asftab[18] = 0;
    asftab[23] = 1;
    asftab[28] = 0;
    asftab[19] = asfdef;
    asftab[24] = asfdef;
    asftab[29] = oppdef;
/*  PICSTR has been emptied - start over */
    nopst (&c__101);
    nsvwi (&c__1);
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomsiz, 
	    &rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  x-location of actual/expected polymarkers */
    setrvs_("0.3", xact, &siz, 3L);
    setrvs_("0.5", xexp, &siz, 3L);
/*  randomize order of polymarkers */
    rn1shf_(&c__14, perm);
/*  Make individual and bundled as distinct as possible: */
/*  set individual attributes: */
    nsmk (&c__5);
#ifndef NO_PROTO
    r__1 = .04f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).04 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nslwsc (&r__1);
    nspmci (&c__1);
/*  set bundle #1: */
#ifndef NO_PROTO
    r__1 = .02f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).02 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nspmr (&globnu_1.wkid, &c__1, &c__4, &r__1, &c__2);
    nspmi (&c__1);
    locppm_(perm, xact);
    nexst (&c__102);
    locppm_(&perm[8], xact);
    asfset_(&c__2, asftab, &c__3, &c__5);
    locppm_(&perm[9], xact);
    xfinh_(perm);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    locppm_(&perm[12], xact);
    locppm_(&perm[13], xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locppm_(&perm[1], xact);
    asfset_(&c__3, asftab, &c__3, &c__5);
    nexst (&c__103);
    locppm_(&perm[7], xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locppm_(&perm[2], xact);
    asfset_(&c__4, asftab, &c__3, &c__5);
    locppm_(&perm[3], xact);
    nexst (&c__104);
    locppm_(&perm[6], xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polymarker 5 / 11 */
    locppm_(&perm[4], xact);
    asfset_(&c__5, asftab, &c__3, &c__5);
/*  polymarker 6 / 12 */
    locppm_(&perm[5], xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for expected ASFs: */
/*  last "incorrect" index set to 4, rather than 3, because */
/*  #2 and #4 are guaranteed to differ in markertype, which */
/*  in turn, is guaranteed to be distinct */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,4", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	asfset_(&expdx[ix - 1], asftab, &c__3, &c__5);
	locppm_(&perm[ix - 1], xexp);
/* L200: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b63, &r__1, &c_b65);
    nclst ();
#ifndef NO_PROTO
    setmsg_("4 5 6 7 8 9 10 11", "The polymarker ASFs should be saved and re"
	    "stored by <execute structure> during traversal.", 17L, 89L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYMARKER ASFS: which pair o"
	    "f markers does NOT match?", &c__14, &perm[13], 88L);
#else /* NO_PROTO */
    setmsg_("4 5 6 7 8 9 10 11", "The polymarker ASFs should be saved and re\
stored by <execute structure> during traversal.", 17L, 89L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYMARKER ASFS: which pair o\
f markers does NOT match?", &c__14, &perm[13], 88L);
#endif /* NO_PROTO */
/*  *** *** ***   inheritance for text ASFs   *** *** *** */
/*  clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  asftab = ASF table: */
/*  These are carefully arranged to maximize visible difference - */
/*  e.g. use STROKE a lot so that expansion and spacing have effect */
/*        font      precision   expansion  spacing  color */
/*        ----      ---------   ---------  -------  ----- */
/*  1:    asfdef    asfdef      asfdef     asfdef   asfdef */
/*  2:    individ   bundled     individ    bundled  individ */
/*  3:    oppdef    oppdef      oppdef     oppdef   oppdef */
/*  4:    bundled   individ     bundled    individ  bundled */
/*  5:    bundled   individ     individ    individ  bundled */
/*  entry #1 always set to ASF default */
    asftab[31] = 1;
    asftab[36] = 0;
    asftab[41] = 1;
    asftab[46] = 0;
    asftab[51] = 1;
    asftab[32] = oppdef;
    asftab[37] = oppdef;
    asftab[42] = oppdef;
    asftab[47] = oppdef;
    asftab[52] = oppdef;
    asftab[33] = 0;
    asftab[38] = 1;
    asftab[43] = 0;
    asftab[48] = 1;
    asftab[53] = 0;
    asftab[34] = 0;
    asftab[39] = 1;
    asftab[44] = 1;
    asftab[49] = 1;
    asftab[54] = 0;
/*  PICSTR has been emptied - start over */
    nopst (&c__101);
    nsvwi (&c__1);
    nschh (&c_b130);
    nstxal (&c__1, &c__3);
#ifndef NO_PROTO
    xtxact = .2f;
    xtxexp = .6f;
#else /* NO_PROTO */
    xtxact = (float).2;
    xtxexp = (float).6;
#endif /* NO_PROTO */
/*  Make individual and bundled as distinct as possible: */
/*  set individual attributes: */
    nstxfn (&c__2);
    nstxpr (&c__2);
    nschxp (&c_b135);
    nschsp (&c_b136);
    nstxci (&c__2);
/*  set bundle #1 to: */
    nstxr (&globnu_1.wkid, &c__1, &c__1, &c__0, &c_b141, &c_b142, &c__1);
    nstxi (&c__1);
/*  randomize order of text */
    rn1shf_(&c__14, perm);
/*  set up CSS as described above */
    loctxt_(perm, &xtxact);
    nexst (&c__102);
    loctxt_(&perm[8], &xtxact);
    asfset_(&c__2, asftab, &c__6, &c__10);
    loctxt_(&perm[9], &xtxact);
    xfinh_(perm);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    loctxt_(&perm[12], &xtxact);
    loctxt_(&perm[13], &xtxact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    loctxt_(&perm[1], &xtxact);
    asfset_(&c__3, asftab, &c__6, &c__10);
    nexst (&c__103);
    loctxt_(&perm[7], &xtxact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    loctxt_(&perm[2], &xtxact);
    asfset_(&c__4, asftab, &c__6, &c__10);
    loctxt_(&perm[3], &xtxact);
    nexst (&c__104);
    loctxt_(&perm[6], &xtxact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polymarker 5 / 11 */
    loctxt_(&perm[4], &xtxact);
    asfset_(&c__5, asftab, &c__6, &c__10);
/*  polymarker 6 / 12 */
    loctxt_(&perm[5], &xtxact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for expected ASFs: */
/*  last "incorrect" index set to 4, rather than 3, because */
/*  #2 and #4 are guaranteed to differ in text font, which */
/*  in turn, is guaranteed to be distinct */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,4", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	asfset_(&expdx[ix - 1], asftab, &c__6, &c__10);
	loctxt_(&perm[ix - 1], &xtxexp);
/* L300: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b63, &r__1, &c_b65);
    nclst ();
#ifndef NO_PROTO
    setmsg_("4 5 6 7 8 9 10 11", "The text ASFs should be saved and restored"
	    " by <execute structure> during traversal.", 17L, 83L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT ASFS: which pair of text"
	    " primitives does NOT match?", &c__14, &perm[13], 90L);
#else /* NO_PROTO */
    setmsg_("4 5 6 7 8 9 10 11", "The text ASFs should be saved and restored\
 by <execute structure> during traversal.", 17L, 83L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT ASFS: which pair of text\
 primitives does NOT match?", &c__14, &perm[13], 90L);
#endif /* NO_PROTO */
/*  *** *** ***   inheritance for interior style ASF   *** *** *** */
/*  clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  asftab = ASF table: (this combination judged most likely to catch */
/*    a failure) */
    asftab[56] = oppdef;
    asftab[57] = oppdef;
    asftab[58] = asfdef;
    asftab[59] = oppdef;
/*  PICSTR has been emptied - start over */
    nopst (&c__101);
    nsvwi (&c__1);
/*  Make individual and bundled as distinct as possible: */
/*  set individual attributes: interior style = hollow */
    nsis (&c__0);
/*  set bundle #1 to: interior style = empty */
    nsir (&globnu_1.wkid, &c__1, &c__4, &c__1, &c__2);
    nsii (&c__1);
    intinh_(asftab, &c__11, &c__11, perm);
#ifndef NO_PROTO
    setmsg_("4 5 6 7 8 9 10 11", "The interior style ASF should be saved and"
	    " restored by <execute structure> during traversal.", 17L, 92L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR STYLE ASF: which pai"
	    "r of interiors does NOT match?", &c__14, &perm[13], 93L);
#else /* NO_PROTO */
    setmsg_("4 5 6 7 8 9 10 11", "The interior style ASF should be saved and\
 restored by <execute structure> during traversal.", 17L, 92L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR STYLE ASF: which pai\
r of interiors does NOT match?", &c__14, &perm[13], 93L);
#endif /* NO_PROTO */
/*  *** *** ***   inheritance for interior index ASF   *** *** *** */
/*  clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  check available interior styles */
    nqif (&dialog_1.specwt, &c__0, &c__0, &errind, &nis, &idum1, &idum2, &
	    idum3, &idum4);
    chkinq_("pqif", &errind, 4L);
    i__1 = abs(nis);
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (&dialog_1.specwt, &ix, &c__0, &errind, &idum1, &thisis, &idum2, 
		&idum3, &idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisis >= 0 && thisis <= 4) {
	    isavl[thisis] = TRUE_;
	}
/* L510: */
    }
/*  thisis = this interior style to be used */
/*  iix1,iix2 = two available interior indices */
    if (isavl[3]) {
/*  using HATCH - get hatch styles */
	thisis = 3;
	nqif (&dialog_1.specwt, &c__0, &c__1, &errind, &idum1, &idum2, &idum3,
		 &iix1, &idum4);
	chkinq_("pqif", &errind, 4L);
	nqif (&dialog_1.specwt, &c__0, &c__2, &errind, &idum1, &idum2, &idum3,
		 &iix2, &idum4);
	chkinq_("pqif", &errind, 4L);
    } else if (isavl[2]) {
/*  using PATTERN */
	thisis = 2;
	nspa (&c_b217, &c_b218);
	iix1 = 1;
	iix2 = 2;
/*  set up two distinct patterns */
	setval_("1,1,1,0", colia, 7L);
	nspar (&globnu_1.wkid, &c__1, &c__2, &c__2, &c__1, &c__1, &c__2, &
		c__2, colia);
	setval_("0,0,1,0", colia, 7L);
	nspar (&globnu_1.wkid, &c__2, &c__2, &c__2, &c__1, &c__1, &c__2, &
		c__2, colia);
    } else {
/*  no style sensitive to interior style index is available */
#ifndef NO_PROTO
	inmsg_("Skipping test case for interior style index ASF, since no av"
		"ailable interior style is sensitive to it.", 102L);
#else /* NO_PROTO */
	inmsg_("Skipping test case for interior style index ASF, since no av\
ailable interior style is sensitive to it.", 102L);
#endif /* NO_PROTO */
	goto L590;
    }
/*  asftab = ASF table: (this combination judged most likely to catch */
/*    a failure) */
    asftab[61] = oppdef;
    asftab[62] = oppdef;
    asftab[63] = asfdef;
    asftab[64] = oppdef;
/*  PICSTR has been emptied - start over */
    nopst (&c__101);
    nsvwi (&c__1);
/*  Make individual and bundled as distinct as possible: */
/*  set individual attributes: */
    nsis (&thisis);
    nsisi (&iix1);
    nsici (&c__1);
/*  set bundle #1: */
    nsir (&globnu_1.wkid, &c__1, &thisis, &iix2, &c__2);
    nsii (&c__1);
    intinh_(asftab, &c__12, &c__12, perm);
#ifndef NO_PROTO
    setmsg_("4 5 6 7 8 9 10 11", "The interior style index ASF should be sav"
	    "ed and restored by <execute structure> during traversal.", 17L, 
	    98L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR STYLE INDEX ASF: whi"
	    "ch pair of interiors does NOT match?", &c__14, &perm[13], 99L);
#else /* NO_PROTO */
    setmsg_("4 5 6 7 8 9 10 11", "The interior style index ASF should be sav\
ed and restored by <execute structure> during traversal.", 17L, 98L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR STYLE INDEX ASF: whi\
ch pair of interiors does NOT match?", &c__14, &perm[13], 99L);
#endif /* NO_PROTO */
/*  end_int_index: */
L590:
/*  *** *** ***   inheritance for interior color ASF   *** *** *** */
/*  clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  ints1,2 = 1st,2nd interior style */
    ints1 = 0;
    if (isavl[1]) {
	ints2 = 1;
    } else if (isavl[3]) {
	ints2 = 3;
	nqif (&dialog_1.specwt, &c__0, &c__1, &errind, &idum1, &idum2, &idum3,
		 &iix1, &idum4);
	chkinq_("pqif", &errind, 4L);
    } else {
	ints2 = 0;
    }
/*  asftab = ASF table: */
/*        style       color */
/*        -----       ----- */
/*  1:    asfdef      asfdef */
/*  2:    asfdef      oppdef */
/*  3:    oppdef      oppdef */
/*  4:    oppdef      asfdef */
/*  5:    oppdef      oppdef */
    asftab[56] = asfdef;
    asftab[66] = oppdef;
    asftab[57] = oppdef;
    asftab[67] = oppdef;
    asftab[58] = oppdef;
    asftab[68] = asfdef;
    asftab[59] = oppdef;
    asftab[69] = oppdef;
/*  PICSTR has been emptied - start over */
    nopst (&c__101);
    nsvwi (&c__1);
/*  Make individual and bundled as distinct as possible: */
/*  set individual attributes: */
    nsis (&ints1);
    nsisi (&iix1);
    if (ndisct > 1) {
	nsici (&c__2);
    } else {
	nsici (&c__0);
    }
/*  set bundle #1: */
    nsir (&globnu_1.wkid, &c__1, &ints2, &iix1, &c__1);
    nsii (&c__1);
    intinh_(asftab, &c__11, &c__13, perm);
#ifndef NO_PROTO
    setmsg_("4 5 6 7 8 9 10 11", "The interior colour ASF should be saved an"
	    "d restored by <execute structure> during traversal.", 17L, 93L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR COLOUR INDEX ASF: wh"
	    "ich pair of interiors does NOT match?", &c__14, &perm[13], 100L);
#else /* NO_PROTO */
    setmsg_("4 5 6 7 8 9 10 11", "The interior colour ASF should be saved an\
d restored by <execute structure> during traversal.", 17L, 93L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR COLOUR INDEX ASF: wh\
ich pair of interiors does NOT match?", &c__14, &perm[13], 100L);
#endif /* NO_PROTO */
/*  *** *** ***   inheritance for edge flag ASF   *** *** *** */
/*  clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  asftab = ASF table: (this combination judged most likely to catch */
/*    a failure) */
    asftab[71] = oppdef;
    asftab[72] = oppdef;
    asftab[73] = asfdef;
    asftab[74] = oppdef;
/*  PICSTR has been emptied - start over */
    nopst (&c__101);
    nsvwi (&c__1);
/*  set interior style = EMPTY */
    nsiasf (&c__11, &c__1);
    nsis (&c__4);
/*  Make individual and bundled as distinct as possible: */
/*  set individual attributes: edge flag=ON */
    nsedfg (&c__1);
/*  set bundle #1 */
    nsedr (&globnu_1.wkid, &c__1, &c__0, &c__1, &c_b284, &c__1);
    nsedi (&c__1);
/*  x-location of actual/expected interiors */
    setrvs_("0.2,0.2,0.5", xact, &siz, 11L);
    setrvs_("0.6,0.6,0.9", xexp, &siz, 11L);
/*  randomize order of interiors */
    rn1shf_(&c__14, perm);
/*  set up CSS as described above */
    loctri_(perm, xact);
    nexst (&c__102);
    loctri_(&perm[8], xact);
    asfset_(&c__2, asftab, &c__14, &c__14);
    loctri_(&perm[9], xact);
    xfinh_(perm);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    loctri_(&perm[12], xact);
    loctri_(&perm[13], xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    loctri_(&perm[1], xact);
    asfset_(&c__3, asftab, &c__14, &c__14);
    nexst (&c__103);
    loctri_(&perm[7], xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    loctri_(&perm[2], xact);
    asfset_(&c__4, asftab, &c__14, &c__14);
    loctri_(&perm[3], xact);
    nexst (&c__104);
    loctri_(&perm[6], xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polymarker 5 / 11 */
    loctri_(&perm[4], xact);
    asfset_(&c__5, asftab, &c__14, &c__14);
/*  polymarker 6 / 12 */
    loctri_(&perm[5], xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for expected ASFs: */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,4", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	asfset_(&expdx[ix - 1], asftab, &c__14, &c__14);
	loctri_(&perm[ix - 1], xexp);
/* L400: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b63, &r__1, &c_b65);
    nclst ();
#ifndef NO_PROTO
    setmsg_("4 5 6 7 8 9 10 11", "The edge flag ASF should be saved and rest"
	    "ored by <execute structure> during traversal.", 17L, 87L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE FLAG ASF: which pair of "
	    "edges does NOT match?", &c__14, &perm[13], 84L);
#else /* NO_PROTO */
    setmsg_("4 5 6 7 8 9 10 11", "The edge flag ASF should be saved and rest\
ored by <execute structure> during traversal.", 17L, 87L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE FLAG ASF: which pair of \
edges does NOT match?", &c__14, &perm[13], 84L);
#endif /* NO_PROTO */
/*  *** *** ***   inheritance for edge aspects ASFs   *** *** *** */
/*  clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);

/*  asftab = ASF table: */
/*        edgetype    edgewidth   color */
/*        --------    ---------   ----- */
/*  1:    asfdef      asfdef      asfdef */
/*  2:    individual  bundled     individual */
/*  3:    oppdef      oppdef      oppdef */
/*  4:    bundled     individual  bundled */
/*  5:    asfdef      asfdef      oppdef */
    asftab[76] = 1;
    asftab[81] = 0;
    asftab[86] = 1;
    asftab[77] = oppdef;
    asftab[82] = oppdef;
    asftab[87] = oppdef;
    asftab[78] = 0;
    asftab[83] = 1;
    asftab[88] = 0;
    asftab[79] = asfdef;
    asftab[84] = asfdef;
    asftab[89] = oppdef;
/*  PICSTR has been emptied - start over */
    nopst (&c__101);
    nsvwi (&c__1);
/*  set interior style = EMPTY, edge flag = ON */
    nsiasf (&c__11, &c__1);
    nsis (&c__4);
    nsiasf (&c__14, &c__1);
    nsedfg (&c__1);
/*  try to get non-1 edgetype: */
    nqedf (&dialog_1.specwt, &c__0, &errind, &nedt, &idum2, &idum3, &nomsiz, &
	    rdum2, &rdum3, &idum4);
    chkinq_("pqedf", &errind, 5L);
    nedt = abs(nedt);
    i__1 = nedt;
    for (ix = 1; ix <= i__1; ++ix) {
	nqedf (&dialog_1.specwt, &ix, &errind, &idum1, &ed2, &idum2, &rdum1, &
		rdum2, &rdum3, &idum4);
	chkinq_("pqedf", &errind, 5L);
	if (ed2 != 1) {
	    goto L620;
	}
/* L610: */
    }
L620:
/*  Make individual and bundled as distinct as possible: */
/*  set individual attributes: */
    nsedt (&c__1);
#ifndef NO_PROTO
    r__1 = .01f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).01 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsewsc (&r__1);
    nsedci (&c__1);
/*  set bundle #1 to: */
#ifndef NO_PROTO
    r__1 = .001f / (nomsiz * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).001 / (nomsiz * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsedr (&globnu_1.wkid, &c__1, &c__1, &ed2, &r__1, &c__2);
    nsedi (&c__1);
/*  randomize order of interiors */
    rn1shf_(&c__14, perm);
/*  set up CSS as described above */
    loctri_(perm, xact);
    nexst (&c__102);
    loctri_(&perm[8], xact);
    asfset_(&c__2, asftab, &c__15, &c__17);
    loctri_(&perm[9], xact);
    xfinh_(perm);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    loctri_(&perm[12], xact);
    loctri_(&perm[13], xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    loctri_(&perm[1], xact);
    asfset_(&c__3, asftab, &c__15, &c__17);
    nexst (&c__103);
    loctri_(&perm[7], xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    loctri_(&perm[2], xact);
    asfset_(&c__4, asftab, &c__15, &c__17);
    loctri_(&perm[3], xact);
    nexst (&c__104);
    loctri_(&perm[6], xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polymarker 5 / 11 */
    loctri_(&perm[4], xact);
    asfset_(&c__5, asftab, &c__15, &c__17);
/*  polymarker 6 / 12 */
    loctri_(&perm[5], xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for expected ASFs: */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,4", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	asfset_(&expdx[ix - 1], asftab, &c__15, &c__17);
	loctri_(&perm[ix - 1], xexp);
/* L600: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b63, &r__1, &c_b65);
    nclst ();
#ifndef NO_PROTO
    setmsg_("4 5 6 7 8 9 10 11", "The edge ASFs should be saved and restored"
	    " by <execute structure> during traversal.", 17L, 83L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE ASFS: which pair of edge"
	    "s does NOT match?", &c__14, &perm[13], 80L);
#else /* NO_PROTO */
    setmsg_("4 5 6 7 8 9 10 11", "The edge ASFs should be saved and restored\
 by <execute structure> during traversal.", 17L, 83L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE ASFS: which pair of edge\
s does NOT match?", &c__14, &perm[13], 80L);
#endif /* NO_PROTO */
L666:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

