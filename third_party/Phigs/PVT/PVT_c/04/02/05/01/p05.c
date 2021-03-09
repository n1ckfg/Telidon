/* fort/04/02/05/01/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
static integer c__14 = 14;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b23 = .027f;
#else /* NO_PROTO */
static real c_b23 = (float).027;
#endif /* NO_PROTO */
static integer c__102 = 102;
static integer c__9 = 9;
static integer c__10 = 10;
static integer c__2 = 2;
static integer c__104 = 104;
static integer c__3 = 3;
static integer c__13 = 13;
static integer c__105 = 105;
static integer c__103 = 103;
static integer c__8 = 8;
static integer c__4 = 4;
static integer c__7 = 7;
static integer c__5 = 5;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b53 = .15f;
static real c_b55 = .066666666666666666f;
static real c_b335 = .045f;
#else /* NO_PROTO */
static real c_b53 = (float).15;
static real c_b55 = (float).066666666666666666;
static real c_b335 = (float).045;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.01/05                        * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization                        * */
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
    real r__1, r__2, r__3;

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
#else /* NO_PROTO */
    double cos(), sin();
#endif /* NO_PROTO */

    /* Local variables */
    static real u, z;
    static integer ix, iy;
    static real ang, scf;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsc (real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsc ();
#endif /* NO_PROTO */
    static integer siz, fcol;
    static real xact[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer perm[20], last;
    static real xvec[10]	/* was [2][5] */, yvec[10]	/* was [2][5] 
	    */;
    static integer txci;
    static real zvec[10]	/* was [2][5] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspa (real *, real *), nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspa (), nsis ();
#endif /* NO_PROTO */
    static real xexp[4];
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum2, rdum3;
    static integer colia[6]	/* was [3][2] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), nqedf (integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *), endit_(void), nsici (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), nqedf (), endit_(), nsici ();
#endif /* NO_PROTO */
    static real minsc, maxsc;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real minew;
#ifndef NO_PROTO
    extern /* Subroutine */ int nbltm (real *, real *, real *, real *, real *,
	     real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nbltm ();
#endif /* NO_PROTO */
    static real xtact[3], nomew, maxew;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
#endif /* NO_PROTO */
    static integer expdx[14], numet;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst ();
#endif /* NO_PROTO */
    static integer numew;
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsisi (integer *), nslmt (real *, integer *), 
	    nspar (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nsedt (integer *), 
	    nexst (integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsisi (), nslmt (), nspar (), nsedt (), 
	    nexst (), nopst ();
#endif /* NO_PROTO */
    static real xtexp[3], fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwi (integer *), rn1shf_(integer *, integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwi (), rn1shf_();
#endif /* NO_PROTO */
    static integer edgflg[5], lhatch[5];
#ifndef NO_PROTO
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static integer colind[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), nsedfg (
	    integer *), locrec_(integer *, real *, integer *), setdlg_(
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), nsedfg (), locrec_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, numhat, lstyle[10], thisis, thisht, ledtyp[
	    5], thiset;
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real patszx[5], patszy[5], ewvals[5];
    static integer numsty;
    static real scform[9]	/* was [3][3] */, xrefpt[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setrvs_(char *, real *, integer *, ftnlen), setasf_(
	    integer *), setval_(char *, integer *, ftnlen), numlab_(integer *,
	     real *, real *, real *), setmsg_(char *, char *, ftnlen, ftnlen),
	     dchpfv_(char *, integer *, integer *, ftnlen), nsewsc (real *), 
	    loctri_(integer *, real *), patrec_(real *, integer *, real *, 
	    integer *), nsprpv (real *, real *, real *, real *, real *, real *
	    ), discol_(integer *, integer *, integer *), nsedci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setrvs_(), setasf_(), 
	    setval_(), numlab_(), setmsg_(), dchpfv_(), nsewsc (), loctri_(), 
	    patrec_(), nsprpv (), discol_(), nsedci ();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* interior style */
/* edge flag indicator */
/* edgetype  (linetype) */
/*  rectangle height for fill area and PI */
    initgl_("04.02.05.01/05", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
/*  use <inquire interior facilities> to determine: */
/*    numsty = number of available interior styles */
    nqif (&dialog_1.specwt, &c__0, &c__0, &errind, &numsty, &idum1, &numhat, &
	    idum2, &idum3);
    chkinq_("pqif", &errind, 4L);
    nqedf (&dialog_1.specwt, &c__0, &errind, &numet, &idum1, &numew, &nomew, &
	    minew, &maxew, &idum4);
    chkinq_("pqedf", &errind, 5L);
/*  x-location of actual/expected rectangles: */
    setrvs_("0.2, 0.2, 0.5, 0.5", xact, &siz, 18L);
    setrvs_("0.6, 0.6, 0.9, 0.9", xexp, &siz, 18L);
/*  x-location of actual/expected triangles: */
    setrvs_("0.2, 0.2, 0.45", xtact, &siz, 14L);
    setrvs_("0.6, 0.6, 0.85", xtexp, &siz, 14L);
/*  All test cases use same basic structure network for testing */
/*  inheritance. Note that structure #104 is executed by both #103 */
/*  and #101. */

/*     default attr */
/*       | */
/*       | */
/*       |                  102 */
/*       |                 /  prim 2 */
/*       |               /    attr #3    attr #3 */
/*       V      attr #1/      exec 103--------------103 */
/*     101           /        prim 8                  prim 3 */
/*       prim 1    /                                  attr #4 */
/*       exec 102/                                    prim 4 */
/*       prim 9                                       exec 104\ */
/*       attr #2                                      prim 7    \ attr #4 
*/
/*       prim 10                                                  \ */
/*       transform            attr #2                               \ */
/*       exec 104----------------------------------------------------104 
*/
/*      un-transform                                                  prim
 5/11*/
/*      prim 13                                                       attr
 #5*/
/*      prim 14                                                       prim
 6/12*/
/*       exec 105---------->105 */
/*                            expected values */
/*  *** *** *** ***   interior style   *** *** *** *** */
/*  lstyle = list of 5 (possibly repeated) available interior styles */
    i__1 = numsty;
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (&dialog_1.specwt, &ix, &c__0, &errind, &idum1, &thisis, &idum2, 
		&idum3, &idum4);
	chkinq_("pqif", &errind, 4L);
	lstyle[ix - 1] = thisis;
/* L50: */
    }
/*  make sure first 5 elements of LSTYLE are filled */
    iy = 1;
    for (ix = numsty + 1; ix <= 5; ++ix) {
	lstyle[ix - 1] = lstyle[iy - 1];
	++iy;
/* L55: */
    }
/*  put PHOLLO (default) in 1st position */
    ix = iarfnd_(&c__0, &numsty, lstyle);
    if (ix >= 1) {
	lstyle[ix - 1] = lstyle[0];
	lstyle[0] = 0;
    } else {
	inmsg_("HOLLOW not available - skipping test of interior style.", 55L)
		;
	goto L1000;
    }
/*  randomize order of rectangles: */
    rn1shf_(&c__14, perm);
/*  set up CSS: */

/*  Structure network #101 draws actual results in random order on */
/*  left side of picture.  Structure #105 draws expected results in */
/*  same random order on right side of picture, except for fill area */
/*  #14 which is deliberately drawn with incorrect attributes.  This */
/*  should be the only non-matching pair in the picture. */
/*  structure #101 */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  turn off edge flag and set pattern size to reasonable value */
    nsedfg (&c__0);
    nspa (&c_b23, &c_b23);
    locrec_(perm, xact, &c__1);
    nexst (&c__102);
    locrec_(&perm[8], xact, &c__9);
    nsis (&lstyle[1]);
    locrec_(&perm[9], xact, &c__10);
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
    locrec_(&perm[12], xact, &c__13);
    locrec_(&perm[13], xact, &c__14);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locrec_(&perm[1], xact, &c__2);
    nsis (&lstyle[2]);
    nexst (&c__103);
    locrec_(&perm[7], xact, &c__8);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locrec_(&perm[2], xact, &c__3);
    nsis (&lstyle[3]);
    locrec_(&perm[3], xact, &c__4);
    nexst (&c__104);
    locrec_(&perm[6], xact, &c__7);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    locrec_(&perm[4], xact, &c__5);
    nsis (&lstyle[4]);
/*  fill area set 6 / 12 */
    locrec_(&perm[5], xact, &c__6);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected interior styles */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsis (&lstyle[expdx[ix - 1] - 1]);
	locrec_(&perm[ix - 1], xexp, &ix);
/* L105: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b53, &r__1, &c_b55);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 4 7 8 16 17", "The interior style attribute for the fill area"
	    " and fill area set primitives should be saved and restored by <e"
	    "xecute structure> during traversal.", 13L, 145L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR STYLE: Which pair of"
	    " rectangles does NOT match?", &c__14, &perm[13], 90L);
#else /* NO_PROTO */
    setmsg_("3 4 7 8 16 17", "The interior style attribute for the fill area\
 and fill area set primitives should be saved and restored by <execute struc\
ture> during traversal.", 13L, 145L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR STYLE: Which pair of\
 rectangles does NOT match?", &c__14, &perm[13], 90L);
#endif /* NO_PROTO */
/*  *** *** *** ***   hatch index   *** *** *** *** */
L1000:
    if (iarfnd_(&c__3, &numsty, lstyle) <= 0) {
	inmsg_("Hatch style unavailable - skipping test of hatch index.", 55L)
		;
	goto L2000;
    }
/*  use <inquire interior facilities> to determine: */
/*    numhat = min(number of available hatch indexes, 5) */
/*    lhatch = list of 5 (possibly repeated) numhat hatch indexes */
/* get up to 5 random available hatch styles and see if #1 is available */

    lhatch[0] = 66;
    last = 1;
    i__1 = abs(numhat);
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (&dialog_1.specwt, &c__0, &ix, &errind, &idum1, &idum2, &idum3, &
		thisht, &idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisht == 1) {
	    lhatch[0] = 1;
	} else {
	    ++last;
	    lhatch[min(5,last) - 1] = thisht;
	}
/* L60: */
    }
    if (lhatch[0] != 1) {
	inmsg_("Hatch style #1 unavailable - skipping test of hatch index.", 
		58L);
	goto L2000;
    }
/*  make sure first 5 elements of LHATCH are filled */
    iy = 1;
    for (ix = last + 1; ix <= 5; ++ix) {
	lhatch[ix - 1] = lhatch[iy - 1];
	++iy;
/* L65: */
    }
/*  randomize order of rectangles: */
    rn1shf_(&c__14, perm);
/*  clear and re-set up CSS: */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L1010: */
    }
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  turn off edge flag and set interior style to HATCH */
    nsedfg (&c__0);
    nsis (&c__3);
/*  structure #101 */
    locrec_(perm, xact, &c__1);
    nexst (&c__102);
    locrec_(&perm[8], xact, &c__9);
    nsisi (&lhatch[1]);
    locrec_(&perm[9], xact, &c__10);
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
    locrec_(&perm[12], xact, &c__13);
    locrec_(&perm[13], xact, &c__14);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locrec_(&perm[1], xact, &c__2);
    nsisi (&lhatch[2]);
    nexst (&c__103);
    locrec_(&perm[7], xact, &c__8);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locrec_(&perm[2], xact, &c__3);
    nsisi (&lhatch[3]);
    locrec_(&perm[3], xact, &c__4);
    nexst (&c__104);
    locrec_(&perm[6], xact, &c__7);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    locrec_(&perm[4], xact, &c__5);
    nsisi (&lhatch[4]);
/*  fill area set 6 / 12 */
    locrec_(&perm[5], xact, &c__6);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected hatch indexes, except for 14th entry */

    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsisi (&lhatch[expdx[ix - 1] - 1]);
	locrec_(&perm[ix - 1], xexp, &ix);
/* L205: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b53, &r__1, &c_b55);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 4 19 20 24 25", "The hatch index attribute for the fill area "
	    "and fill area set primitives should be saved and restored by <ex"
	    "ecute structure> during traversal.", 15L, 142L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR HATCH INDEX: Which pair of re"
	    "ctangles does NOT match?", &c__14, &perm[13], 87L);
#else /* NO_PROTO */
    setmsg_("3 4 19 20 24 25", "The hatch index attribute for the fill area \
and fill area set primitives should be saved and restored by <execute struct\
ure> during traversal.", 15L, 142L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR HATCH INDEX: Which pair of re\
ctangles does NOT match?", &c__14, &perm[13], 87L);
#endif /* NO_PROTO */
/*  *** *** *** ***   pattern index   *** *** *** *** */
L2000:
    if (iarfnd_(&c__2, &numsty, lstyle) <= 0) {
	inmsg_("Pattern style unavailable - skipping test of pattern index.", 
		59L);
	goto L3000;
    }
/*     set up 5 distinct patterns in table */
    setval_("1,0,0,0,1,0", colia, 11L);
    nspar (&globnu_1.wkid, &c__1, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, 
	    colia);
    setval_("1,1,0,0,0,0", colia, 11L);
    nspar (&globnu_1.wkid, &c__2, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, 
	    colia);
    setval_("1,1,1,0,0,0", colia, 11L);
    nspar (&globnu_1.wkid, &c__3, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, 
	    colia);
    setval_("1,1,0,1,0,0", colia, 11L);
    nspar (&globnu_1.wkid, &c__4, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, 
	    colia);
    setval_("1,1,0,0,0,1", colia, 11L);
    nspar (&globnu_1.wkid, &c__5, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, 
	    colia);
/*  randomize order of rectangles: */
    rn1shf_(&c__14, perm);
/*  clear and re-set up CSS: */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L2010: */
    }
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  turn off edge flag, set interior style to PATTERN and */
/*  set pattern size to reasonable value */
    nsedfg (&c__0);
    nsis (&c__2);
    nspa (&c_b23, &c_b23);
/*  structure #101 */
    locrec_(perm, xact, &c__1);
    nexst (&c__102);
    locrec_(&perm[8], xact, &c__9);
    nsisi (&c__2);
    locrec_(&perm[9], xact, &c__10);
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
    locrec_(&perm[12], xact, &c__13);
    locrec_(&perm[13], xact, &c__14);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locrec_(&perm[1], xact, &c__2);
    nsisi (&c__3);
    nexst (&c__103);
    locrec_(&perm[7], xact, &c__8);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locrec_(&perm[2], xact, &c__3);
    nsisi (&c__4);
    locrec_(&perm[3], xact, &c__4);
    nexst (&c__104);
    locrec_(&perm[6], xact, &c__7);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    locrec_(&perm[4], xact, &c__5);
    nsisi (&c__5);
/*  fill area set 6 / 12 */
    locrec_(&perm[5], xact, &c__6);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for expected pattern indexes */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsisi (&expdx[ix - 1]);
	locrec_(&perm[ix - 1], xexp, &ix);
/* L305: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b53, &r__1, &c_b55);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 4 19 20 24 25", "The pattern index attribute for the fill are"
	    "a and fill area set primitives should be saved and restored by <"
	    "execute structure> during traversal.", 15L, 144L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR PATTERN INDEX: Which pair of "
	    "rectangles does NOT match?", &c__14, &perm[13], 89L);
#else /* NO_PROTO */
    setmsg_("3 4 19 20 24 25", "The pattern index attribute for the fill are\
a and fill area set primitives should be saved and restored by <execute stru\
cture> during traversal.", 15L, 144L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR PATTERN INDEX: Which pair of \
rectangles does NOT match?", &c__14, &perm[13], 89L);
#endif /* NO_PROTO */
L3000:
/*  *** *** *** ***   edge flag   *** *** *** *** */
/*  set up 5 edge flags in table - 1st must be default (OFF), and */
/*  make 2nd <> 4th, since these are both inherited by #104 */
    setval_("0,1,1,0,1", edgflg, 9L);
/*  randomize order of triangles: */
    rn1shf_(&c__14, perm);
/*  clear and re-set up CSS: */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L3110: */
    }
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  set interior style to EMPTY and try for moderately thick edge */
    nsis (&c__4);
#ifndef NO_PROTO
    r__1 = .01f / (nomew * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).01 / (nomew * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsewsc (&r__1);
/*  structure #101 */
    loctri_(perm, xtact);
    nexst (&c__102);
    loctri_(&perm[8], xtact);
    nsedfg (&edgflg[1]);
    loctri_(&perm[9], xtact);
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
    loctri_(&perm[12], xtact);
    loctri_(&perm[13], xtact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    loctri_(&perm[1], xtact);
    nsedfg (&edgflg[2]);
    nexst (&c__103);
    loctri_(&perm[7], xtact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    loctri_(&perm[2], xtact);
    nsedfg (&edgflg[3]);
    loctri_(&perm[3], xtact);
    nexst (&c__104);
    loctri_(&perm[6], xtact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    loctri_(&perm[4], xtact);
    nsedfg (&edgflg[4]);
/*  fill area set 6 / 12 */
    loctri_(&perm[5], xtact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected edge flags */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,4", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsedfg (&edgflg[expdx[ix - 1] - 1]);
	loctri_(&perm[ix - 1], xtexp);
/* L3105: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b53, &r__1, &c_b55);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 4 34 35 36 38 39", "The edge flag attribute for the fill area"
	    " set primitive should be saved and restored by <execute structur"
	    "e> during traversal.", 18L, 125L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE FLAG: Which pair of tria"
	    "ngles does NOT match?", &c__14, &perm[13], 84L);
#else /* NO_PROTO */
    setmsg_("3 4 34 35 36 38 39", "The edge flag attribute for the fill area\
 set primitive should be saved and restored by <execute structure> during tr\
aversal.", 18L, 125L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE FLAG: Which pair of tria\
ngles does NOT match?", &c__14, &perm[13], 84L);
#endif /* NO_PROTO */
/*  *** *** *** ***   edgetype and width   *** *** *** *** */
    if (abs(numet) == 1 && numew == 1) {
#ifndef NO_PROTO
	inmsg_("Only one edgetype and edgewidth available - skipping test of"
		" edgetype and edgewidth.", 84L);
#else /* NO_PROTO */
	inmsg_("Only one edgetype and edgewidth available - skipping test of\
 edgetype and edgewidth.", 84L);
#endif /* NO_PROTO */
	goto L4190;
    }
/*  ledtyp = list of 5 (possibly repeated) edgetypes */
/*  get up to 5 random available edge types see if #1 is available */
    ledtyp[0] = 6666;
    last = 1;
    i__1 = abs(numet);
    for (ix = 1; ix <= i__1; ++ix) {
	nqedf (&dialog_1.specwt, &ix, &errind, &idum1, &thiset, &idum2, &
		rdum1, &rdum2, &rdum3, &idum4);
	chkinq_("pqedf", &errind, 5L);
	if (thiset == 1) {
	    ledtyp[0] = 1;
	} else {
	    ++last;
	    ledtyp[min(5,last) - 1] = thiset;
	}
/* L4160: */
    }
    if (ledtyp[0] != 1) {
#ifndef NO_PROTO
	inmsg_("Edgetype #1 unavailable - skipping test of edgetype and edge"
		"width.", 66L);
#else /* NO_PROTO */
	inmsg_("Edgetype #1 unavailable - skipping test of edgetype and edge\
width.", 66L);
#endif /* NO_PROTO */
	goto L4190;
    }
/*  make sure first 5 elements of LEDTYP are filled */
    iy = 1;
    for (ix = last + 1; ix <= 5; ++ix) {
	ledtyp[ix - 1] = ledtyp[iy - 1];
	++iy;
/* L4165: */
    }
/*  try to set up 5 distinct edgewidth scale factors */
#ifndef NO_PROTO
    maxsc = .027f / (nomew * dialog_1.wcpdc);
#else /* NO_PROTO */
    maxsc = (float).027 / (nomew * dialog_1.wcpdc);
#endif /* NO_PROTO */
    minsc = minew / nomew;
    for (ix = 1; ix <= 5; ++ix) {
	ewvals[ix - 1] = minsc + (maxsc - minsc) * (ix - 1) / 4;
/* L4175: */
    }
/*  randomize order of triangles: */
    rn1shf_(&c__14, perm);
/*  clear and re-set up CSS: */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L4110: */
    }
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  set interior style to EMPTY and edge flag ON */
    nsis (&c__4);
    nsedfg (&c__1);
/*  structure #101 */
    loctri_(perm, xtact);
    nexst (&c__102);
    loctri_(&perm[8], xtact);
    nsedt (&ledtyp[1]);
    nsewsc (&ewvals[1]);
    loctri_(&perm[9], xtact);
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
    loctri_(&perm[12], xtact);
    loctri_(&perm[13], xtact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    loctri_(&perm[1], xtact);
    nsedt (&ledtyp[2]);
    nsewsc (&ewvals[2]);
    nexst (&c__103);
    loctri_(&perm[7], xtact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    loctri_(&perm[2], xtact);
    nsedt (&ledtyp[3]);
    nsewsc (&ewvals[3]);
    loctri_(&perm[3], xtact);
    nexst (&c__104);
    loctri_(&perm[6], xtact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    loctri_(&perm[4], xtact);
    nsedt (&ledtyp[4]);
    nsewsc (&ewvals[4]);
/*  fill area set 6 / 12 */
    loctri_(&perm[5], xtact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected edgetypes and widths */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsedt (&ledtyp[expdx[ix - 1] - 1]);
	nsewsc (&ewvals[expdx[ix - 1] - 1]);
	loctri_(&perm[ix - 1], xtexp);
/* L4105: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b53, &r__1, &c_b55);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 4 41 42 47 48 50 51 52 53 54", "The edgetype and edgewidth sc"
	    "ale factor attributes for the fill area set primitive should be "
	    "saved and restored by <execute structure> during traversal.", 30L,
	     152L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGETYPE AND EDGEWIDTH: Which"
	    " pair of triangles does NOT match?", &c__14, &perm[13], 97L);
#else /* NO_PROTO */
    setmsg_("3 4 41 42 47 48 50 51 52 53 54", "The edgetype and edgewidth sc\
ale factor attributes for the fill area set primitive should be saved and re\
stored by <execute structure> during traversal.", 30L, 152L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGETYPE AND EDGEWIDTH: Which\
 pair of triangles does NOT match?", &c__14, &perm[13], 97L);
#endif /* NO_PROTO */
L4190:
/*  *** *** *** ***   pattern size   *** *** *** *** */
    if (iarfnd_(&c__2, &numsty, lstyle) <= 0) {
#ifndef NO_PROTO
	inmsg_("Pattern style unavailable - skipping tests of pattern size, "
		"reference point, and vectors.", 89L);
#else /* NO_PROTO */
	inmsg_("Pattern style unavailable - skipping tests of pattern size, \
reference point, and vectors.", 89L);
#endif /* NO_PROTO */
	goto L5900;
    }
/*  set up simple checkerboard pattern in table */
    setval_("1,0,0,1", colia, 7L);
    nspar (&globnu_1.wkid, &c__1, &c__3, &c__2, &c__1, &c__1, &c__2, &c__2, 
	    colia);
/*  set up distinguishable pattern sizes */
    setrvs_("1, 1.2, 0.8, 1.4, 0.6", patszx, &siz, 21L);
    setrvs_("1, 0.8, 1.2, 1.4, 0.6", patszy, &siz, 21L);
/*  randomize order of rectangles: */
    rn1shf_(&c__14, perm);
/*  clear and re-set up CSS: */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L5120: */
    }
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  turn off edge flag, set interior style to PATTERN and */
/*  set pattern index to 1 */
    nsedfg (&c__0);
    nsis (&c__2);
    nsisi (&c__1);
/*  Because default pattern size of 1,1 would fill whole screen, */
/*  we have to scale everything such that 1,1 is part of a rectangle, */
/*  whose height is RECHT = 0.045 - so map 1.2 to RECHT */
#ifndef NO_PROTO
    scf = .037499999999999999f;
#else /* NO_PROTO */
    scf = (float).037499999999999999;
#endif /* NO_PROTO */
    nsc (&scf, &scf, &errind, scform);
    chkinq_("psc", &errind, 3L);
    nslmt (scform, &c__2);
/*  structure #101 */
    patrec_(&scf, perm, xact, &c__1);
    nexst (&c__102);
    patrec_(&scf, &perm[8], xact, &c__9);
    nspa (&patszx[1], &patszy[1]);
    patrec_(&scf, &perm[9], xact, &c__10);
    fxpty = ylocel_(&perm[4]) / scf;
    shifty = (ylocel_(&perm[10]) - ylocel_(&perm[4])) / scf;
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &u, &errind, xform);
    chkinq_("pbltm", &errind, 5L);
/*  note we add this to current transform */
    nslmt (xform, &c__0);
/*  execute 104 */
    nexst (&c__104);
/*  now, cancel out transformation ... */
    idmat_(&c__3, xform);
    nslmt (scform, &c__2);
    patrec_(&scf, &perm[12], xact, &c__13);
    patrec_(&scf, &perm[13], xact, &c__14);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    patrec_(&scf, &perm[1], xact, &c__2);
    nspa (&patszx[2], &patszy[2]);
    nexst (&c__103);
    patrec_(&scf, &perm[7], xact, &c__8);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    patrec_(&scf, &perm[2], xact, &c__3);
    nspa (&patszx[3], &patszy[3]);
    patrec_(&scf, &perm[3], xact, &c__4);
    nexst (&c__104);
    patrec_(&scf, &perm[6], xact, &c__7);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    patrec_(&scf, &perm[4], xact, &c__5);
    nspa (&patszx[4], &patszy[4]);
/*  fill area set 6 / 12 */
    patrec_(&scf, &perm[5], xact, &c__6);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected pattern sizes */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nspa (&patszx[expdx[ix - 1] - 1], &patszy[expdx[ix - 1] - 1]);
	patrec_(&scf, &perm[ix - 1], xexp, &ix);
/* L5130: */
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
    setmsg_("3 4 62 64 65 73 74", "The pattern size attribute for the fill a"
	    "rea and fill area set primitives should be saved and restored by"
	    " <execute structure> during traversal.", 18L, 143L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR PATTERN SIZE: Which pair of r"
	    "ectangles does NOT match?", &c__14, &perm[13], 88L);
#else /* NO_PROTO */
    setmsg_("3 4 62 64 65 73 74", "The pattern size attribute for the fill a\
rea and fill area set primitives should be saved and restored by <execute st\
ructure> during traversal.", 18L, 143L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR PATTERN SIZE: Which pair of r\
ectangles does NOT match?", &c__14, &perm[13], 88L);
#endif /* NO_PROTO */
/*  *** *** ***   pattern reference point and vectors   *** *** *** */
/*  set up simple stripe pattern in table */
    setval_("1,1,0,0", colia, 7L);
    nspar (&globnu_1.wkid, &c__1, &c__3, &c__2, &c__1, &c__1, &c__2, &c__2, 
	    colia);
/*  set up distinguishable pattern reference point and vectors */
    for (ix = 1; ix <= 5; ++ix) {
/*  move reference point along x-axis by 5ths of a rectangle height */

#ifndef NO_PROTO
	xrefpt[ix - 1] = (ix - 1) * .045f / 5;
	ang = (ix - 1) * 3.14159254f / 5;
#else /* NO_PROTO */
	xrefpt[ix - 1] = (ix - 1) * (float).045 / 5;
	ang = (ix - 1) * (float)3.14159254 / 5;
#endif /* NO_PROTO */
	xvec[(ix << 1) - 2] = cos(ang);
	yvec[(ix << 1) - 2] = sin(ang);
#ifndef NO_PROTO
	zvec[(ix << 1) - 2] = 0.f;
#else /* NO_PROTO */
	zvec[(ix << 1) - 2] = (float)0.;
#endif /* NO_PROTO */
	xvec[(ix << 1) - 1] = -(doublereal)yvec[(ix << 1) - 2];
	yvec[(ix << 1) - 1] = xvec[(ix << 1) - 2];
#ifndef NO_PROTO
	zvec[(ix << 1) - 1] = 0.f;
#else /* NO_PROTO */
	zvec[(ix << 1) - 1] = (float)0.;
#endif /* NO_PROTO */
/* L5110: */
    }
/*  randomize order of rectangles: */
    rn1shf_(&c__14, perm);
/*  clear and re-set up CSS: */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L5520: */
    }
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  turn off edge flag, set interior style to PATTERN, set */
/*  pattern index to 1 and set pattern size to reasonable value */
    nsedfg (&c__0);
    nsis (&c__2);
    nsisi (&c__1);
    nspa (&c_b335, &c_b335);
/*  structure #101 */
    locrec_(perm, xact, &c__1);
    nexst (&c__102);
    locrec_(&perm[8], xact, &c__9);
    nsprpv (&xrefpt[1], &z, &z, &xvec[2], &yvec[2], &zvec[2]);
    locrec_(&perm[9], xact, &c__10);
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
    locrec_(&perm[12], xact, &c__13);
    locrec_(&perm[13], xact, &c__14);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locrec_(&perm[1], xact, &c__2);
    nsprpv (&xrefpt[2], &z, &z, &xvec[4], &yvec[4], &zvec[4]);
    nexst (&c__103);
    locrec_(&perm[7], xact, &c__8);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locrec_(&perm[2], xact, &c__3);
    nsprpv (&xrefpt[3], &z, &z, &xvec[6], &yvec[6], &zvec[6]);
    locrec_(&perm[3], xact, &c__4);
    nexst (&c__104);
    locrec_(&perm[6], xact, &c__7);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    locrec_(&perm[4], xact, &c__5);
    nsprpv (&xrefpt[4], &z, &z, &xvec[8], &yvec[8], &zvec[8]);
/*  fill area set 6 / 12 */
    locrec_(&perm[5], xact, &c__6);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected pattern reference points and vectors */

    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
/*  allow for different x-location of rectangles */
	r__1 = xrefpt[expdx[ix - 1] - 1] + xexp[0] - xact[0];
	nsprpv (&r__1, &z, &z, &xvec[(expdx[ix - 1] << 1) - 2], &yvec[(expdx[
		ix - 1] << 1) - 2], &zvec[(expdx[ix - 1] << 1) - 2]);
	locrec_(&perm[ix - 1], xexp, &ix);
/* L5530: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b53, &r__1, &c_b55);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 4 68 71 72 73 74 75 76 77 80 81 82 83", "The pattern referenc"
	    "e point and vectors attributes for the fill area and fill area s"
	    "et primitives should be saved and restored by <execute structure"
	    "> during traversal.", 39L, 167L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR PATTERN REFERENCE POINT AND V"
	    "ECTORS: Which pair of rectangles does NOT match?", &c__14, &perm[
	    13], 111L);
#else /* NO_PROTO */
    setmsg_("3 4 68 71 72 73 74 75 76 77 80 81 82 83", "The pattern referenc\
e point and vectors attributes for the fill area and fill area set primitive\
s should be saved and restored by <execute structure> during traversal.", 39L,
	     167L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR PATTERN REFERENCE POINT AND V\
ECTORS: Which pair of rectangles does NOT match?", &c__14, &perm[13], 111L);
#endif /* NO_PROTO */
L5900:
/*  save color tests for last, since they may change the color table */
/*  *** *** *** *** ***   interior color index   *** *** *** *** *** */
/*  clear the decks */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L3200: */
    }
/*  call DISCOL to try to get 5 distinct foreground colors, */
/*    returning fcol = actual number of foreground colors */
    discol_(&c__5, &globnu_1.wkid, &fcol);
    if (fcol <= 1) {
	fcol = 2;
	setval_("1,0,1,1,0", colind, 9L);
    } else {
/*  colind = circular list of indices = [1,..,fcol, 1,..] */
	setval_("1,2,3,4,5", colind, 9L);
	iy = 1;
	for (ix = fcol + 1; ix <= 5; ++ix) {
	    colind[ix - 1] = colind[iy - 1];
	    ++iy;
/* L3300: */
	}
    }
/*  set up PERM to randomize position of triangles */
    rn1shf_(&c__14, perm);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  set edge flag off and try for interior style = SOLID, but take */
/*  HOLLOW as default */
    nsedfg (&c__0);
    nsis (&c__1);
/*  structure #101 */
    locrec_(perm, xact, &c__1);
    nexst (&c__102);
    locrec_(&perm[8], xact, &c__9);
    nsici (&colind[1]);
    locrec_(&perm[9], xact, &c__10);
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
    locrec_(&perm[12], xact, &c__13);
    locrec_(&perm[13], xact, &c__14);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locrec_(&perm[1], xact, &c__2);
    nsici (&colind[2]);
    nexst (&c__103);
    locrec_(&perm[7], xact, &c__8);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locrec_(&perm[2], xact, &c__3);
    nsici (&colind[3]);
    locrec_(&perm[3], xact, &c__4);
    nexst (&c__104);
    locrec_(&perm[6], xact, &c__7);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    locrec_(&perm[4], xact, &c__5);
    nsici (&colind[4]);
/*  fill area set 6 / 12 */
    locrec_(&perm[5], xact, &c__6);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected interior colour indexes */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsici (&colind[expdx[ix - 1] - 1]);
	locrec_(&perm[ix - 1], xexp, &ix);
/* L3305: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b53, &r__1, &c_b55);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 4 27 28 30 31", "The interior colour index attribute for the "
	    "fill area and fill area set primitives should be saved and resto"
	    "red by <execute structure> during traversal.", 15L, 152L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR COLOUR INDEX: Which "
	    "pair of rectangles does NOT match?", &c__14, &perm[13], 97L);
#else /* NO_PROTO */
    setmsg_("3 4 27 28 30 31", "The interior colour index attribute for the \
fill area and fill area set primitives should be saved and restored by <exec\
ute structure> during traversal.", 15L, 152L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR COLOUR INDEX: Which \
pair of rectangles does NOT match?", &c__14, &perm[13], 97L);
#endif /* NO_PROTO */
/*  *** *** *** *** ***   edge color index   *** *** *** *** *** */
/*  clear the decks */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L4200: */
    }
/*  FCOL and COLIND set from interior colour index */
/*  set up PERM to randomize position of triangles */
    rn1shf_(&c__14, perm);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  set edge flag ON, interior style = EMPTY, and try for */
/*  moderately thick edge */
    nsedfg (&c__1);
    nsis (&c__4);
#ifndef NO_PROTO
    r__1 = .01f / (nomew * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).01 / (nomew * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsewsc (&r__1);
/*  structure #101 */
    loctri_(perm, xtact);
    nexst (&c__102);
    loctri_(&perm[8], xtact);
    nsedci (&colind[1]);
    loctri_(&perm[9], xtact);
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
    loctri_(&perm[12], xtact);
    loctri_(&perm[13], xtact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    loctri_(&perm[1], xtact);
    nsedci (&colind[2]);
    nexst (&c__103);
    loctri_(&perm[7], xtact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    loctri_(&perm[2], xtact);
    nsedci (&colind[3]);
    loctri_(&perm[3], xtact);
    nexst (&c__104);
    loctri_(&perm[6], xtact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  fill area 5 / 11 */
    loctri_(&perm[4], xtact);
    nsedci (&colind[4]);
/*  fill area set 6 / 12 */
    loctri_(&perm[5], xtact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for index into expected edge colour indexes */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsedci (&colind[expdx[ix - 1] - 1]);
	loctri_(&perm[ix - 1], xtexp);
/* L4305: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b53, &r__1, &c_b55);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 4 56 57 59 60", "The edge colour index attribute for the fill"
	    " area set primitive should be saved and restored by <execute str"
	    "ucture> during traversal.", 15L, 133L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE COLOUR INDEX: Which pair"
	    " of triangles does NOT match?", &c__14, &perm[13], 92L);
#else /* NO_PROTO */
    setmsg_("3 4 56 57 59 60", "The edge colour index attribute for the fill\
 area set primitive should be saved and restored by <execute structure> duri\
ng traversal.", 15L, 133L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE COLOUR INDEX: Which pair\
 of triangles does NOT match?", &c__14, &perm[13], 92L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

