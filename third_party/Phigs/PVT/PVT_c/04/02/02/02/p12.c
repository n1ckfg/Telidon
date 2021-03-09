/* fort/04/02/02/02/p12.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b13 = 1.f;
#else /* NO_PROTO */
static real c_b13 = (float)1.;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__14 = 14;
static integer c__102 = 102;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__103 = 103;
#ifndef NO_PROTO
static real c_b47 = .15f;
static real c_b49 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b47 = (float).15;
static real c_b49 = (float).066666666666666666;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.02/12                        * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization of polymarker index    * */
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
    real r__1, r__2;

    /* Local variables */
    static real u, z;
    static integer ix, iy, siz, fcol;
    static real xact[5];
    static integer perm[14], txci;
    static real xexp[5];
    static integer idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nscmd (integer *, integer *), nbltm (real *, real *, real *, real 
	    *, real *, real *, real *, integer *, real *), nqpmf (integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nscmd (), nbltm (), 
	    nqpmf (), nclst ();
#endif /* NO_PROTO */
    static real minmw;
    static integer expdx[14];
    static real maxmw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspmi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspmi ();
#endif /* NO_PROTO */
    static real xform[9]	/* was [3][3] */, nommw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt ();
#endif /* NO_PROTO */
    static integer nummt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspmr (integer *, integer *, integer *, real *
	    , integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspmr ();
#endif /* NO_PROTO */
    static integer nummw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwi (integer *), rn1shf_(integer *, integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwi (), rn1shf_();
#endif /* NO_PROTO */
    static real altmw1;
    static integer colind[5];
    static real scaley;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), setdlg_(
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setrvs_(char *, real *, integer *, ftnlen), discol_(
	    integer *, integer *, integer *), setval_(char *, integer *, 
	    ftnlen), setasf_(integer *), locppm_(integer *, real *), numlab_(
	    integer *, real *, real *, real *), setmsg_(char *, char *, 
	    ftnlen, ftnlen), dchpfv_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern doublereal ylocel_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setrvs_(), discol_(), 
	    setval_(), setasf_(), locppm_(), numlab_(), setmsg_(), dchpfv_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* colour model */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* reference handling flag */
/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
    initgl_("04.02.02.02/12", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nscmd (&globnu_1.wkid, &c__1);
/*  x-location of actual/expected polymarkers */
    setrvs_("0.35", xact, &siz, 4L);
    setrvs_("0.55", xexp, &siz, 4L);
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
/*  *** *** ***   inheritance for polymarker index  *** *** */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &nummt, &idum2, &nummw, &nommw, &
	    minmw, &maxmw, &idum3);
    chkinq_("pqpmf", &errind, 5L);
/*  get alternative marker size scale factors: */
/*  altmw1 = max scale factor */
    altmw1 = maxmw / nommw;
/*  but make sure ALTMW1 < 0.05 in WC */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = altmw1, r__2 = .05f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = altmw1, r__2 = (float).05 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    altmw1 = dmin(r__1,r__2);
/*  call DISCOL to try to get 5 distinct foreground colors, */
/*    returning fcol = actual number of foreground colors */
    discol_(&c__5, &globnu_1.wkid, &fcol);
/*  colind[1:fcol] = list of indices */
    setval_("1,2,3,4,5", colind, 9L);
    iy = 1;
    for (ix = fcol + 1; ix <= 5; ++ix) {
	colind[ix - 1] = colind[iy - 1];
	++iy;
/* L300: */
    }
/*  set up 5 bundles */
    nspmr (&globnu_1.wkid, &c__1, &c__1, &c_b13, colind);
    nspmr (&globnu_1.wkid, &c__2, &c__2, &altmw1, &colind[1]);
    nspmr (&globnu_1.wkid, &c__3, &c__3, &c_b13, &colind[2]);
    nspmr (&globnu_1.wkid, &c__4, &c__4, &altmw1, &colind[3]);
    nspmr (&globnu_1.wkid, &c__5, &c__5, &c_b13, &colind[4]);
/*  randomize order of polymarkers */
    rn1shf_(&c__14, perm);
/*  set up CSS: */
/*  Structure network #101 draws actual results in random order on */
/*  left side of picture.  Structure #105 draws expected results in */
/*  same order on right side of picture, expect for polymarker #14 */
/*  which is deliberately drawn with incorrect attributes.  This */
/*  should be the only non-matching pair in the picture. */
/*  structure #101 */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use bundled attributes */
    setasf_(&c__0);
    locppm_(perm, xact);
    nexst (&c__102);
    locppm_(&perm[8], xact);
    nspmi (&c__2);
    locppm_(&perm[9], xact);
/*  Tricky code here: since structure 104 is re-invoked, it */
/*  generates polymarker #5,6 on first invocation, and 11,12 */
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
    locppm_(&perm[12], xact);
    locppm_(&perm[13], xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locppm_(&perm[1], xact);
    nspmi (&c__3);
    nexst (&c__103);
    locppm_(&perm[7], xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locppm_(&perm[2], xact);
    nspmi (&c__4);
    locppm_(&perm[3], xact);
    nexst (&c__104);
    locppm_(&perm[6], xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  polymarker 5 / 11 */
    locppm_(&perm[4], xact);
    nspmi (&c__5);
/*  polymarker 6 / 12 */
    locppm_(&perm[5], xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for bundle index */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nspmi (&expdx[ix - 1]);
	locppm_(&perm[ix - 1], xexp);
/* L400: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b47, &r__1, &c_b49);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 5 6 8 9", "The polymarker index should be saved and restored "
	    "by <execute structure> during traversal.", 9L, 90L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYMARKER INDEX: Which pair "
	    "of markers does NOT match?", &c__14, &perm[13], 89L);
#else /* NO_PROTO */
    setmsg_("3 5 6 8 9", "The polymarker index should be saved and restored \
by <execute structure> during traversal.", 9L, 90L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYMARKER INDEX: Which pair \
of markers does NOT match?", &c__14, &perm[13], 89L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

