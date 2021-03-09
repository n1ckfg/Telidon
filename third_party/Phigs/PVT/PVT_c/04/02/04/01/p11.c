/* fort/04/02/04/01/p11.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b3 = 0.f;
#else /* NO_PROTO */
static real c_b3 = (float)0.;
#endif /* NO_PROTO */
static integer c__14 = 14;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__102 = 102;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__103 = 103;
#ifndef NO_PROTO
static real c_b29 = .15f;
#else /* NO_PROTO */
static real c_b29 = (float).15;
#endif /* NO_PROTO */
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b66 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b66 = (float).066666666666666666;
#endif /* NO_PROTO */
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.04.01/11                        * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization for geometric          * */
/*  *                 annotation text attributes            * */
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
    integer i__1, i__2, i__3;
    real r__1;

    /* Local variables */
    static real u, z;
    static integer ix, iy, adx, siz;
    static logical got1;
    static real xact;
    static integer perm[14];
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
#endif /* NO_PROTO */
    static integer txci;
    static real npcx, npcy, lhts[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static integer lsiz;
    static real xexp;
    static integer ltxp[5], idum1, idum2;
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nqanf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *), wcnpc_(real *, real *, real *, real *,
	     real *), inmsg_(char *, ftnlen), nbltm (real *, real *, real *, 
	    real *, real *, real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nqanf (), wcnpc_(), 
	    inmsg_(), nbltm ();
#endif /* NO_PROTO */
    static integer lanst[5], numas;
    static real yincr;
    static integer expdx[14];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst ();
#endif /* NO_PROTO */
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatp (integer *), nsans (integer *), nslmt (
	    real *, integer *), nexst (integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatp (), nsans (), nslmt (), nexst (), 
	    nopst ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwi (integer *), locat2_(integer *, real *),
	     rn1shf_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwi (), locat2_(), rn1shf_();
#endif /* NO_PROTO */
    static integer lalgnh[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), numlab_(
	    integer *, real *, real *, real *), setdlg_(integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, lalgnv[5], thisas;
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real lchupx[5], lchupy[5], npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setrvs_(char *, real *, integer *, ftnlen), setasf_(
	    integer *), nstxfn (integer *), nstxpr (integer *), nsatal (
	    integer *, integer *), locatx_(integer *, real *), nsatch (real *)
	    , setval_(char *, integer *, ftnlen), setmsg_(char *, char *, 
	    ftnlen, ftnlen), dchpfv_(char *, integer *, integer *, ftnlen), 
	    nspmci (integer *), nsatcu (real *, real *), nsplci (integer *), 
	    locans_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setrvs_(), setasf_(), 
	    nstxfn (), nstxpr (), nsatal (), locatx_(), nsatch (), setval_(), 
	    setmsg_(), dchpfv_(), nspmci (), nsatcu (), nsplci (), locans_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    initgl_("04.02.04.01/11", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    wcnpc_(&c_b3, &c_b3, &npcx, &npcy, &npcpwc);
/*  All test cases use the same basic structure network for testing */
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


/*  *** *** ***   annotation text character height   *** *** *** */
/*  lhts = list of 5 distinct character heights */
/*       = [.010, .020, .015, .025, .030] */
/*    with 0.010 (default) in 1st position. */
    setrvs_(".010, .020, .015, .025, .030", lhts, &siz, 28L);
#ifndef NO_PROTO
    xact = .2f;
    xexp = .5f;
    yincr = .066666666666666666f;
#else /* NO_PROTO */
    xact = (float).2;
    xexp = (float).5;
    yincr = (float).066666666666666666;
#endif /* NO_PROTO */
/*  randomize location of text strings */
    rn1shf_(&c__14, perm);
/*  set up CSS as described above */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  Throughout, use font=1, precision=stroke, alignment=left,half */
    nstxfn (&c__1);
    nstxpr (&c__2);
    nsatal (&c__1, &c__3);
    locatx_(perm, &xact);
    nexst (&c__102);
    locatx_(&perm[8], &xact);
    nsatch (&lhts[1]);
    locatx_(&perm[9], &xact);
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
    nslmt (xform, &c__2);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    locatx_(&perm[12], &xact);
    locatx_(&perm[13], &xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locatx_(&perm[1], &xact);
    nsatch (&lhts[2]);
    nexst (&c__103);
    locatx_(&perm[7], &xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locatx_(&perm[2], &xact);
    nsatch (&lhts[3]);
    locatx_(&perm[3], &xact);
    nexst (&c__104);
    locatx_(&perm[6], &xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    locatx_(&perm[4], &xact);
    nsatch (&lhts[4]);
/*  fill area set 6 / 12 */
    locatx_(&perm[5], &xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected interior styles */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsatch (&lhts[expdx[ix - 1] - 1]);
	locatx_(&perm[ix - 1], &xexp);
/* L105: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b29, &r__1, &yincr);
    nclst ();
#ifndef NO_PROTO
    setmsg_("5 48 53 54", "The annotation text character height attribute sh"
	    "ould be saved and restored by <execute structure> during travers"
	    "al.", 10L, 116L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR ANNOTATION TEXT CHARACTER HEI"
	    "GHT: Which pair of annotation text strings does NOT match?", &
	    c__14, &perm[13], 121L);
#else /* NO_PROTO */
    setmsg_("5 48 53 54", "The annotation text character height attribute sh\
ould be saved and restored by <execute structure> during traversal.", 10L, 
	    116L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR ANNOTATION TEXT CHARACTER HEI\
GHT: Which pair of annotation text strings does NOT match?", &c__14, &perm[13]
	    , 121L);
#endif /* NO_PROTO */
/*  *** *** *** ***   annotation text alignment   *** *** *** *** */
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
/*  set up CSS as described above; display 14 pairs of annotation */
/*    text strings with annotation text alignments from lalgnh, lalgnv */
/*  show alignment point for each with polymarker */
/*  structure #101 */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  Throughout, use font=1, precision=stroke, character height = .025 */
    nstxfn (&c__1);
    nstxpr (&c__2);
#ifndef NO_PROTO
    r__1 = npcpwc * .025f;
#else /* NO_PROTO */
    r__1 = npcpwc * (float).025;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nspmci (&c__2);
    locat2_(perm, &xact);
    nexst (&c__102);
    locat2_(&perm[8], &xact);
    nsatal (&lalgnh[1], &lalgnv[1]);
    locat2_(&perm[9], &xact);
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
    nslmt (xform, &c__2);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    locat2_(&perm[12], &xact);
    locat2_(&perm[13], &xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locat2_(&perm[1], &xact);
    nsatal (&lalgnh[2], &lalgnv[2]);
    nexst (&c__103);
    locat2_(&perm[7], &xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locat2_(&perm[2], &xact);
    nsatal (&lalgnh[3], &lalgnv[3]);
    locat2_(&perm[3], &xact);
    nexst (&c__104);
    locat2_(&perm[6], &xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    locat2_(&perm[4], &xact);
    nsatal (&lalgnh[4], &lalgnv[4]);
/*  fill area set 6 / 12 */
    locat2_(&perm[5], &xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected interior styles */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsatal (&lalgnh[expdx[ix - 1] - 1], &lalgnv[expdx[ix - 1] - 1]);
	locat2_(&perm[ix - 1], &xexp);
/* L205: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b29, &r__1, &c_b66);
    nclst ();
#ifndef NO_PROTO
    setmsg_("5 65 66 68 69", "The annotation text alignment attribute should"
	    " be saved and restored by <execute structure> during traversal.", 
	    13L, 109L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR ANNOTATION TEXT ALIGNMENT: Wh"
	    "ich pair of annotation text strings is NOT similarly aligned wit"
	    "h respect to the marked annotation point?", &c__14, &perm[13], 
	    168L);
#else /* NO_PROTO */
    setmsg_("5 65 66 68 69", "The annotation text alignment attribute should\
 be saved and restored by <execute structure> during traversal.", 13L, 109L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR ANNOTATION TEXT ALIGNMENT: Wh\
ich pair of annotation text strings is NOT similarly aligned with respect to\
 the marked annotation point?", &c__14, &perm[13], 168L);
#endif /* NO_PROTO */
/*  *** ***   annotation text path and character up   *** *** */
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
/*  randomize location of annotation text strings */
    rn1shf_(&c__14, perm);
/*  set up CSS as described above; display 14 pairs of annotation */
/*    text strings with annotation text paths and character ups */
/*    from ltxp, lchup */
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
#ifndef NO_PROTO
    r__1 = npcpwc * .03f;
#else /* NO_PROTO */
    r__1 = npcpwc * (float).03;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nsatal (&c__2, &c__3);
    r__1 = ylocel_(perm);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nexst (&c__102);
    r__1 = ylocel_(&perm[8]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nsatcu (&lchupx[1], &lchupy[1]);
    nsatp (&ltxp[1]);
    r__1 = ylocel_(&perm[9]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
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
    nslmt (xform, &c__2);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    r__1 = ylocel_(&perm[12]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    r__1 = ylocel_(&perm[13]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    r__1 = ylocel_(&perm[1]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nsatcu (&lchupx[2], &lchupy[2]);
    nsatp (&ltxp[2]);
    nexst (&c__103);
    r__1 = ylocel_(&perm[7]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    r__1 = ylocel_(&perm[2]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nsatcu (&lchupx[3], &lchupy[3]);
    nsatp (&ltxp[3]);
    r__1 = ylocel_(&perm[3]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nexst (&c__104);
    r__1 = ylocel_(&perm[6]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    r__1 = ylocel_(&perm[4]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nsatcu (&lchupx[4], &lchupy[4]);
    nsatp (&ltxp[4]);
/*  fill area set 6 / 12 */
    r__1 = ylocel_(&perm[5]);
    natr (&xact, &r__1, &z, &z, t3str, 3L);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected interior styles */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	iy = expdx[ix - 1];
	nsatcu (&lchupx[iy - 1], &lchupy[iy - 1]);
	nsatp (&ltxp[iy - 1]);
	r__1 = ylocel_(&perm[ix - 1]);
	natr (&xexp, &r__1, &z, &z, t3str, 3L);
/* L305: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b29, &r__1, &c_b66);
    nclst ();
#ifndef NO_PROTO
    setmsg_("5 57 58 61 62 71 72 73 74", "The annotation text path and annot"
	    "ation text character up attributes should be saved and restored "
	    "by <execute structure> during traversal.", 25L, 138L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR ANNOTATION TEXT PATH AND CHAR"
	    "ACTER UP: Which pair of annotation text strings does NOT match?", 
	    &c__14, &perm[13], 126L);
#else /* NO_PROTO */
    setmsg_("5 57 58 61 62 71 72 73 74", "The annotation text path and annot\
ation text character up attributes should be saved and restored by <execute \
structure> during traversal.", 25L, 138L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR ANNOTATION TEXT PATH AND CHAR\
ACTER UP: Which pair of annotation text strings does NOT match?", &c__14, &
	    perm[13], 126L);
#endif /* NO_PROTO */
/*  *** *** ***   annotation style   *** *** *** */
/*  Clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  Use <inquire annotation facilities> to develop */
/*    lanst = list of available annotation styles */
    nqanf (&dialog_1.specwt, &c__0, &errind, &numas, &idum1, &idum2, &rdum1, &
	    rdum2);
    chkinq_("pqanf", &errind, 5L);
    if (numas < 2) {
#ifndef NO_PROTO
	inmsg_("Skipping test of annotation style inheritance; less than two"
		" styles available.", 78L);
#else /* NO_PROTO */
	inmsg_("Skipping test of annotation style inheritance; less than two\
 styles available.", 78L);
#endif /* NO_PROTO */
	goto L666;
    }
    lsiz = 1;
    got1 = FALSE_;
    i__1 = numas;
    for (adx = 1; adx <= i__1; ++adx) {
	nqanf (&dialog_1.specwt, &adx, &errind, &idum1, &thisas, &idum2, &
		rdum1, &rdum2);
	chkinq_("pqanf", &errind, 5L);
	if (thisas == 1) {
	    lanst[0] = 1;
	    got1 = TRUE_;
	} else {
/* Computing MIN */
	    i__2 = 5, i__3 = lsiz + 1;
	    lsiz = min(i__2,i__3);
	    lanst[lsiz - 1] = thisas;
	}
/* L150: */
    }
    if (! got1) {
#ifndef NO_PROTO
	inmsg_("Skipping test of annotation style inheritance; style #1 not "
		"available.", 70L);
#else /* NO_PROTO */
	inmsg_("Skipping test of annotation style inheritance; style #1 not \
available.", 70L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  lanst contains exactly five elements; element #1 = 1 (default) */
/*  fill out list */
    iy = 1;
    for (ix = lsiz + 1; ix <= 5; ++ix) {
	lanst[ix - 1] = lanst[iy - 1];
	++iy;
/* L400: */
    }
#ifndef NO_PROTO
    xact = .4f;
    xexp = .8f;
    yincr = .066666666666666666f;
#else /* NO_PROTO */
    xact = (float).4;
    xexp = (float).8;
    yincr = (float).066666666666666666;
#endif /* NO_PROTO */
/*  randomize location of text strings */
    rn1shf_(&c__14, perm);
/*  set up CSS as described above */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  Throughout, use font=1, precision=stroke, alignment=rite,half */
    nstxfn (&c__1);
    nstxpr (&c__2);
    nsatal (&c__3, &c__3);
#ifndef NO_PROTO
    r__1 = yincr * .5f * npcpwc;
#else /* NO_PROTO */
    r__1 = yincr * (float).5 * npcpwc;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nsplci (&c__2);
    nsln (&c__2);
    locans_(perm, &xact);
    nexst (&c__102);
    locans_(&perm[8], &xact);
    nsans (&lanst[1]);
    locans_(&perm[9], &xact);
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
    nslmt (xform, &c__2);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    locans_(&perm[12], &xact);
    locans_(&perm[13], &xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locans_(&perm[1], &xact);
    nsans (&lanst[2]);
    nexst (&c__103);
    locans_(&perm[7], &xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locans_(&perm[2], &xact);
    nsans (&lanst[3]);
    locans_(&perm[3], &xact);
    nexst (&c__104);
    locans_(&perm[6], &xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    locans_(&perm[4], &xact);
    nsans (&lanst[4]);
/*  fill area set 6 / 12 */
    locans_(&perm[5], &xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected interior styles */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsans (&lanst[expdx[ix - 1] - 1]);
	locans_(&perm[ix - 1], &xexp);
/* L405: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b29, &r__1, &yincr);
    nclst ();
#ifndef NO_PROTO
    setmsg_("5 76 83 84", "The annotation style attribute should be saved an"
	    "d restored by <execute structure> during traversal.", 10L, 100L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR ANNOTATION STYLE: Which pair "
	    "of annotation styles does NOT match?", &c__14, &perm[13], 99L);
#else /* NO_PROTO */
    setmsg_("5 76 83 84", "The annotation style attribute should be saved an\
d restored by <execute structure> during traversal.", 10L, 100L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR ANNOTATION STYLE: Which pair \
of annotation styles does NOT match?", &c__14, &perm[13], 99L);
#endif /* NO_PROTO */
/*  end_style: */
L666:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

