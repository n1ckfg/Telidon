/* fort/04/02/03/01/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__14 = 14;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__102 = 102;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__103 = 103;
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b45 = .025f;
#else /* NO_PROTO */
static real c_b45 = (float).025;
#endif /* NO_PROTO */
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b63 = .15f;
static real c_b65 = .066666666666666666f;
static real c_b83 = .03f;
#else /* NO_PROTO */
static real c_b63 = (float).15;
static real c_b65 = (float).066666666666666666;
static real c_b83 = (float).03;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.01/10                        * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization for geometric text     * */
/*  *                 attributes                            * */
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

#ifndef NO_PROTO
    static char t3str[3] = "Up!";
#else /* NO_PROTO */
    static char t3str[3+1] = "Up!";
#endif /* NO_PROTO */

    /* System generated locals */
    real r__1, r__2, r__3;

    /* Local variables */
    static real u, z;
    static integer ix, iy;
    static real scf;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsc (real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsc ();
#endif /* NO_PROTO */
    static integer siz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real xact;
    static integer perm[14], txci;
    static real lhts[5], xexp;
    static integer ltxp[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nschh (real *), nbltm (real *, real *, real *, real *, real *, 
	    real *, real *, integer *, real *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nschh (), nbltm (), 
	    nclst ();
#endif /* NO_PROTO */
    static integer expdx[14];
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst ();
#endif /* NO_PROTO */
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), nopst ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwi (integer *), nstxp (integer *), rn1shf_(
	    integer *, integer *), loctx1_(integer *, real *, real *), 
	    loctx2_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwi (), nstxp (), rn1shf_(), loctx1_(), 
	    loctx2_();
#endif /* NO_PROTO */
    static integer lalgnh[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), numlab_(
	    integer *, real *, real *, real *), setdlg_(integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, lalgnv[5];
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real scform[9]	/* was [3][3] */, lchupx[5], lchupy[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setrvs_(char *, real *, integer *, ftnlen), setasf_(
	    integer *), nstxfn (integer *), nstxpr (integer *), nstxal (
	    integer *, integer *), setval_(char *, integer *, ftnlen), 
	    setmsg_(char *, char *, ftnlen, ftnlen), dchpfv_(char *, integer *
	    , integer *, ftnlen), nspmci (integer *), nschup (real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setrvs_(), setasf_(), 
	    nstxfn (), nstxpr (), nstxal (), setval_(), setmsg_(), dchpfv_(), 
	    nspmci (), nschup ();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    initgl_("04.02.03.01/10", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
/*  All test cases use same basic structure network for testing */
/*  inheritance.  Five (distinct if possible) values for the */
/*  attribute(s) to be tested are set up and propagated throughout */
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
/*  *** *** *** ***   character height   *** *** *** *** */
/*  lhts = list of 5 distinct character heights */
/*       = [.010, .012, .006, .008, .014] */
/*    with 0.010 (default) in 1st position. */
    setrvs_(".010, .012, .006, .008, .014", lhts, &siz, 28L);
#ifndef NO_PROTO
    xact = .2f;
    xexp = .5f;
#else /* NO_PROTO */
    xact = (float).2;
    xexp = (float).5;
#endif /* NO_PROTO */
/*  randomize location of text strings */
    rn1shf_(&c__14, perm);
/*  set up CSS as described above */
/*  structure #101 */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  Throughout, use font=1, precision=stroke, alignment=left,half */
    nstxfn (&c__1);
    nstxpr (&c__2);
    nstxal (&c__1, &c__3);
/*  Throughout, scale such that char-ht of 0.01 and nearby values */
/*  are reasonably visible and fit on line. */
#ifndef NO_PROTO
    scf = 2.8571428571428572f;
#else /* NO_PROTO */
    scf = (float)2.8571428571428572;
#endif /* NO_PROTO */
    nsc (&scf, &scf, &errind, scform);
    chkinq_("psc", &errind, 3L);
    nslmt (scform, &c__2);
    loctx1_(perm, &xact, &scf);
    nexst (&c__102);
    loctx1_(&perm[8], &xact, &scf);
    nschh (&lhts[1]);
    loctx1_(&perm[9], &xact, &scf);
/*  Tricky code here: since structure 104 is re-invoked, it */
/*  generates rectangle #5,6 on first invocation, and 11,12 */
/*  on 2nd.  But 11,12 would simply overlay 5,6, so we must */
/*  also pass down a local transformation which maps locations 5,6 */
/*  to locations 11,12, respectively. */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    fxpty = ylocel_(&perm[4]);
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &u, &errind, xform);
    chkinq_("pbltm", &errind, 5L);
    nslmt (xform, &c__1);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    nslmt (scform, &c__2);
    loctx1_(&perm[12], &xact, &scf);
    loctx1_(&perm[13], &xact, &scf);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    loctx1_(&perm[1], &xact, &scf);
    nschh (&lhts[2]);
    nexst (&c__103);
    loctx1_(&perm[7], &xact, &scf);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    loctx1_(&perm[2], &xact, &scf);
    nschh (&lhts[3]);
    loctx1_(&perm[3], &xact, &scf);
    nexst (&c__104);
    loctx1_(&perm[6], &xact, &scf);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    loctx1_(&perm[4], &xact, &scf);
    nschh (&lhts[4]);
/*  fill area set 6 / 12 */
    loctx1_(&perm[5], &xact, &scf);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected interior styles */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nschh (&lhts[expdx[ix - 1] - 1]);
	loctx1_(&perm[ix - 1], &xexp, &scf);
/* L105: */
    }
/*  draw labels */
#ifndef NO_PROTO
    r__1 = .15f / scf;
#else /* NO_PROTO */
    r__1 = (float).15 / scf;
#endif /* NO_PROTO */
    r__2 = ylocel_(&c__1) / scf;
#ifndef NO_PROTO
    r__3 = .066666666666666666f / scf;
#else /* NO_PROTO */
    r__3 = (float).066666666666666666 / scf;
#endif /* NO_PROTO */
    numlab_(&c__14, &r__1, &r__2, &r__3);
    nclst ();
#ifndef NO_PROTO
    setmsg_("11 58 62 63", "The character height attribute should be saved a"
	    "nd restored by <execute structure> during traversal.", 11L, 100L);

    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR CHARACTER HEIGHT: Which pair "
	    "of text strings does NOT match?", &c__14, &perm[13], 94L);
#else /* NO_PROTO */
    setmsg_("11 58 62 63", "The character height attribute should be saved a\
nd restored by <execute structure> during traversal.", 11L, 100L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR CHARACTER HEIGHT: Which pair \
of text strings does NOT match?", &c__14, &perm[13], 94L);
#endif /* NO_PROTO */
/*  *** *** *** ***   text alignment   *** *** *** *** */
/*  Clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  lalgnh, lalgnv = list of 5 distinct text alignments (default in */
/*                   first position) = */

/*          horizontal  vertical */
/*          ----------  -------- */
/*     1:   LEFT        BASE */
/*     2:   CENTER      HALF */
/*     3:   RIGHT       CAP */
/*     4:   LEFT        BOTTOM */
/*     5:   RIGHT       TOP */
    setval_("1,2,3,1,3", lalgnh, 9L);
    setval_("4,3,2,5,1", lalgnv, 9L);
#ifndef NO_PROTO
    xact = .4f;
    xexp = .7f;
#else /* NO_PROTO */
    xact = (float).4;
    xexp = (float).7;
#endif /* NO_PROTO */
/*  randomize location of text strings */
    rn1shf_(&c__14, perm);
/*  Set up CSS as described above; display 14 pairs of text strings */
/*  with text alignments from lalgnh, lalgnv; show alignment point */
/*  for each with polymarker */
/*  structure #101 */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  Throughout, use font=1, precision=stroke, character height = .04 */
    nstxfn (&c__1);
    nstxpr (&c__2);
    nschh (&c_b45);
    nspmci (&c__2);
    loctx2_(perm, &xact);
    nexst (&c__102);
    loctx2_(&perm[8], &xact);
    nstxal (&lalgnh[1], &lalgnv[1]);
    loctx2_(&perm[9], &xact);
/*  Tricky code here: since structure 104 is re-invoked, it */
/*  generates rectangle #5,6 on first invocation, and 11,12 */
/*  on 2nd.  But 11,12 would simply overlay 5,6, so we must */
/*  also pass down a local transformation which maps locations 5,6 */
/*  to locations 11,12, respectively. */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    fxpty = ylocel_(&perm[4]);
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &u, &errind, xform);
    chkinq_("pbltm", &errind, 5L);
    nslmt (xform, &c__0);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, scform);
    nslmt (scform, &c__2);
    loctx2_(&perm[12], &xact);
    loctx2_(&perm[13], &xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    loctx2_(&perm[1], &xact);
    nstxal (&lalgnh[2], &lalgnv[2]);
    nexst (&c__103);
    loctx2_(&perm[7], &xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    loctx2_(&perm[2], &xact);
    nstxal (&lalgnh[3], &lalgnv[3]);
    loctx2_(&perm[3], &xact);
    nexst (&c__104);
    loctx2_(&perm[6], &xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    loctx2_(&perm[4], &xact);
    nstxal (&lalgnh[4], &lalgnv[4]);
/*  fill area set 6 / 12 */
    loctx2_(&perm[5], &xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected interior styles */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nstxal (&lalgnh[expdx[ix - 1] - 1], &lalgnv[expdx[ix - 1] - 1]);
	loctx2_(&perm[ix - 1], &xexp);
/* L205: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b63, &r__1, &c_b65);
    nclst ();
#ifndef NO_PROTO
    setmsg_("11 74 75 77 78", "The text alignment attribute should be saved "
	    "and restored by <execute structure> during traversal.", 14L, 98L);

    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT ALIGNMENT: Which pair of"
	    " text strings is NOT similarly aligned with respect to the marke"
	    "d text position?", &c__14, &perm[13], 143L);
#else /* NO_PROTO */
    setmsg_("11 74 75 77 78", "The text alignment attribute should be saved \
and restored by <execute structure> during traversal.", 14L, 98L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT ALIGNMENT: Which pair of\
 text strings is NOT similarly aligned with respect to the marked text posit\
ion?", &c__14, &perm[13], 143L);
#endif /* NO_PROTO */
/*  *** *** *** ***   text path and character up   *** *** *** *** */
/*  Clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  ltxp, lchup = list of 5 distinct text paths and character-ups */
/*                (default in first position) = */

/*          text path   character up */
/*          ---------   ------------ */
/*     1:   RIGHT        0, 1 */
/*     2:   UP          -3, 1 */
/*     3:   LEFT         1,-3 */
/*     4:   DOWN        -3,-1 */
/*     5:   LEFT        -1,-3 */
    setval_(" 0, 2, 1, 3, 1", ltxp, 14L);
    setrvs_(" 0,-3, 1,-3,-1", lchupx, &siz, 14L);
    setrvs_(" 1, 1,-3,-1,-3", lchupy, &siz, 14L);
#ifndef NO_PROTO
    xact = .3f;
    xexp = .6f;
#else /* NO_PROTO */
    xact = (float).3;
    xexp = (float).6;
#endif /* NO_PROTO */
/*  randomize location of text strings */
    rn1shf_(&c__14, perm);
/*  set up CSS as described above; display 14 pairs of text strings */
/*  with text paths and character ups from ltxp, lchup */
/*  structure #101 */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  Throughout, use font=1, precision=stroke, character height = .04, */
/*  alignment=center,half */
    nstxfn (&c__1);
    nstxpr (&c__2);
    nschh (&c_b83);
    nstxal (&c__2, &c__3);
    r__1 = ylocel_(perm);
    ntx (&xact, &r__1, t3str, 3L);
    nexst (&c__102);
    r__1 = ylocel_(&perm[8]);
    ntx (&xact, &r__1, t3str, 3L);
    nschup (&lchupx[1], &lchupy[1]);
    nstxp (&ltxp[1]);
    r__1 = ylocel_(&perm[9]);
    ntx (&xact, &r__1, t3str, 3L);
/*  Tricky code here: since structure 104 is re-invoked, it */
/*  generates rectangle #5,6 on first invocation, and 11,12 */
/*  on 2nd.  But 11,12 would simply overlay 5,6, so we must */
/*  also pass down a local transformation which maps locations 5,6 */
/*  to locations 11,12, respectively. */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    fxpty = ylocel_(&perm[4]);
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &u, &errind, xform);
    chkinq_("pbltm", &errind, 5L);
    nslmt (xform, &c__0);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, scform);
    nslmt (scform, &c__2);
    r__1 = ylocel_(&perm[12]);
    ntx (&xact, &r__1, t3str, 3L);
    r__1 = ylocel_(&perm[13]);
    ntx (&xact, &r__1, t3str, 3L);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    r__1 = ylocel_(&perm[1]);
    ntx (&xact, &r__1, t3str, 3L);
    nschup (&lchupx[2], &lchupy[2]);
    nstxp (&ltxp[2]);
    nexst (&c__103);
    r__1 = ylocel_(&perm[7]);
    ntx (&xact, &r__1, t3str, 3L);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    r__1 = ylocel_(&perm[2]);
    ntx (&xact, &r__1, t3str, 3L);
    nschup (&lchupx[3], &lchupy[3]);
    nstxp (&ltxp[3]);
    r__1 = ylocel_(&perm[3]);
    ntx (&xact, &r__1, t3str, 3L);
    nexst (&c__104);
    r__1 = ylocel_(&perm[6]);
    ntx (&xact, &r__1, t3str, 3L);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    r__1 = ylocel_(&perm[4]);
    ntx (&xact, &r__1, t3str, 3L);
    nschup (&lchupx[4], &lchupy[4]);
    nstxp (&ltxp[4]);
/*  fill area set 6 / 12 */
    r__1 = ylocel_(&perm[5]);
    ntx (&xact, &r__1, t3str, 3L);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected interior styles */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	iy = expdx[ix - 1];
	nschup (&lchupx[iy - 1], &lchupy[iy - 1]);
	nstxp (&ltxp[iy - 1]);
	r__1 = ylocel_(&perm[ix - 1]);
	ntx (&xexp, &r__1, t3str, 3L);
/* L305: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b63, &r__1, &c_b65);
    nclst ();
#ifndef NO_PROTO
    setmsg_("11 66 67 70 71 80 81 82 83", "The text path and character up at"
	    "tributes should be saved and restored by <execute structure> dur"
	    "ing traversal.", 26L, 111L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT PATH AND CHARACTER UP: W"
	    "hich pair of text strings does NOT match?", &c__14, &perm[13], 
	    104L);
#else /* NO_PROTO */
    setmsg_("11 66 67 70 71 80 81 82 83", "The text path and character up at\
tributes should be saved and restored by <execute structure> during traversa\
l.", 26L, 111L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT PATH AND CHARACTER UP: W\
hich pair of text strings does NOT match?", &c__14, &perm[13], 104L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

