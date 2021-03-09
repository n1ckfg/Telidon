/* fort/04/02/05/02/p13.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__5 = 5;
static integer c__0 = 0;
static integer c__50 = 50;
static integer c__2 = 2;
static integer c__14 = 14;
static integer c__102 = 102;
static integer c__9 = 9;
static integer c__10 = 10;
static integer c__104 = 104;
static integer c__3 = 3;
static integer c__13 = 13;
static integer c__105 = 105;
static integer c__103 = 103;
static integer c__8 = 8;
static integer c__4 = 4;
static integer c__7 = 7;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b68 = .15f;
static real c_b70 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b68 = (float).15;
static real c_b70 = (float).066666666666666666;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/13                        * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization of interior index      * */
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
    real r__1;

    /* Local variables */
    static real u, z;
    static integer ix, iy;
    static logical got[5];
    static integer siz, pcia[2500]	/* was [50][50] */, fcol;
    static real xact[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer perm[14];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsii (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsii ();
#endif /* NO_PROTO */
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsir (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsir ();
#endif /* NO_PROTO */
    static real xexp[4];
    static integer idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nscmd (integer *, integer *), nbltm (real *, real *, real *, real 
	    *, real *, real *, real *, integer *, real *), nspar (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nscmd (), nbltm (), 
	    nspar (), nclst ();
#endif /* NO_PROTO */
    static integer expdx[14], lints[5];
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), nopst ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwi (integer *), rn1shf_(integer *, integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwi (), rn1shf_();
#endif /* NO_PROTO */
    static integer colind[5];
    static real scaley;
#ifndef NO_PROTO
    extern /* Subroutine */ int discol_(integer *, integer *, integer *), 
	    setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int discol_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, naints, thisis, thishs, istydx[5], nxtval;
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setrvs_(char *, real *, integer *, ftnlen), setval_(
	    char *, integer *, ftnlen), chkinq_(char *, integer *, ftnlen), 
	    setasf_(integer *), nsiasf (integer *, integer *), nsedfg (
	    integer *), locrec_(integer *, real *, integer *), numlab_(
	    integer *, real *, real *, real *), setmsg_(char *, char *, 
	    ftnlen, ftnlen), dchpfv_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern doublereal ylocel_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setrvs_(), setval_(), 
	    chkinq_(), setasf_(), nsiasf (), nsedfg (), locrec_(), numlab_(), 
	    setmsg_(), dchpfv_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* aspect identifier */
/* off/on switch for edge flag and error handling mode */
/* colour model */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* reference handling flag */
/* interior got */
/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
/* set up pattern array index values */
    initgl_("04.02.05.02/13", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nscmd (&globnu_1.wkid, &c__1);
/*  x-location of actual/expected interiors */
    setrvs_("0.2, 0.2, 0.5, 0.5", xact, &siz, 18L);
    setrvs_("0.6, 0.6, 0.9, 0.9", xexp, &siz, 18L);
/*  All test cases use same basic structure network for testing */
/*  inheritance.  Note that strutucre #14 is executed by both #103 */
/*  and #101 */

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
/*  *** *** ***   inheritance for interior index  *** *** */
/*  call DISCOL to try to get 5 distinct foreground colors, */
/*    returning fcol = actual number of foreground colors */
    discol_(&c__5, &globnu_1.wkid, &fcol);
/*  colind[1:fcol] = list of indices */
    setval_("1,2,3,4,5", colind, 9L);
    iy = 1;
    for (ix = fcol + 1; ix <= 5; ++ix) {
	colind[ix - 1] = colind[iy - 1];
	++iy;
/* L100: */
    }
/*  istydx = interior style indexes (will be reset if have HATCH) */
/*  initialize istydx */
    setval_("1,2,3,4,5", istydx, 9L);
/*  see which interior styles are available */
    for (ix = 0; ix <= 4; ++ix) {
	got[ix - 1] = FALSE_;
/* L50: */
    }
/*  naints = number of available interior styles */
    nqif (&dialog_1.specwt, &c__0, &c__0, &errind, &naints, &idum1, &idum2, &
	    idum3, &idum4);
    chkinq_("pqif", &errind, 4L);
/*  keep track of which styles are available */
    i__1 = naints;
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (&dialog_1.specwt, &ix, &c__0, &errind, &idum1, &thisis, &idum2, 
		&idum3, &idum4);
	chkinq_("pqif", &errind, 4L);
/*  only use valid styles HOLLOW:EMPTY */
	if (0 <= thisis && thisis <= 4) {
	    got[thisis - 1] = TRUE_;
	}
/* L200: */
    }
/*  initialize lints = PHOLLO,PISEMP,PHOLLO,PHOLLO,PHOLLO */
/*                   = list of interior styles to be used */
    setval_("0,4,0,0,0", lints, 9L);
/*  check which styles are available, beside hollow and empty */
    nxtval = 3;
/*  if got(SOLID) then fill LINTS(nxtval:5) with solid */
    if (got[0]) {
	for (ix = nxtval; ix <= 5; ++ix) {
	    lints[ix - 1] = 1;
/* L400: */
	}
	++nxtval;
    }
/*  if got(HATCH) then fill LINTS(nxtval:5) with hatch */
    if (got[2]) {
	iy = 1;
	for (ix = nxtval; ix <= 5; ++ix) {
	    lints[ix - 1] = 3;
	    nqif (&dialog_1.specwt, &c__0, &iy, &errind, &idum1, &idum2, &
		    idum3, &thishs, &idum4);
	    chkinq_("pqif", &errind, 4L);
	    istydx[ix - 1] = thishs;
	    ++iy;
/* L425: */
	}
	++nxtval;
    }
/*  if got(PATTERN) then fill LINTS(nxtval:5) with pattern */
    if (got[1]) {
/*  set up pattern array */
	pcia[204] = 1;
	pcia[205] = 0;
	pcia[206] = 1;
	pcia[207] = 1;
	pcia[254] = 0;
	pcia[255] = 1;
	pcia[256] = 0;
	pcia[257] = 0;
	for (ix = nxtval; ix <= 5; ++ix) {
	    lints[ix - 1] = 2;
	    i__1 = ix - 1;
	    nspar (&globnu_1.wkid, &ix, &c__50, &c__50, &c__5, &c__5, &i__1, &
		    c__2, pcia);
/* L450: */
	}
    }
/*  set_bundles: */
/* L1000: */
/*  set up 5 bundles */
    for (ix = 1; ix <= 5; ++ix) {
	nsir (&globnu_1.wkid, &ix, &lints[ix - 1], &istydx[ix - 1], &colind[
		ix - 1]);
/* L1010: */
    }
/*  randomize order of interiors */
    rn1shf_(&c__14, perm);
/*  set up CSS: */
/*  Structure network #101 draws actual results in random order on */
/*  left side of picture.  Structure #105 draws expected results in */
/*  same order on right side of picture, expect for interior #14 */
/*  which is deliberately drawn with incorrect attributes.  This */
/*  should be the only non-matching pair in the picture. */
/*  structure #101 */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use bundled attributes, except for edge flag */
    setasf_(&c__0);
/*  set ASF individual: edge flag = off */
    nsiasf (&c__14, &c__1);
    nsedfg (&c__0);
    locrec_(perm, xact, &c__1);
    nexst (&c__102);
    locrec_(&perm[8], xact, &c__9);
    nsii (&c__2);
    locrec_(&perm[9], xact, &c__10);
/*  Tricky code here: since structure 104 is re-invoked, it */
/*  generates interior #5,6 on first invocation, and 11,12 */
/*  on 2nd.  But 11,12 would simply overlay 5,6, so we must */
/*  also pass down a transformation which maps locations 5,6 */
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
    scaley = (ylocel_(&perm[11]) - ylocel_(&perm[10])) / (ylocel_(&perm[5]) - 
	    ylocel_(&perm[4]));
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &scaley, &errind, xform);
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
    nsii (&c__3);
    nexst (&c__103);
    locrec_(&perm[7], xact, &c__8);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locrec_(&perm[2], xact, &c__3);
    nsii (&c__4);
    locrec_(&perm[3], xact, &c__4);
    nexst (&c__104);
    locrec_(&perm[6], xact, &c__7);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  interior 5 / 11 */
    locrec_(&perm[4], xact, &c__5);
    nsii (&c__5);
/*  interior 6 / 12 */
    locrec_(&perm[5], xact, &c__6);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for bundle index */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsii (&expdx[ix - 1]);
	locrec_(&perm[ix - 1], xexp, &ix);
/* L1200: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b68, &r__1, &c_b70);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 4 6 7 9 10", "The interior index should be saved and restored"
	    " by <execute structure> during traversal.", 12L, 88L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR INDEX: Which pair of"
	    " interiors does NOT match?", &c__14, &perm[13], 89L);
#else /* NO_PROTO */
    setmsg_("3 4 6 7 9 10", "The interior index should be saved and restored\
 by <execute structure> during traversal.", 12L, 88L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR INTERIOR INDEX: Which pair of\
 interiors does NOT match?", &c__14, &perm[13], 89L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

