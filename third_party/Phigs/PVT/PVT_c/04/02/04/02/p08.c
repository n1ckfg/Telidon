/* fort/04/02/04/02/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b10 = 1.f;
static real c_b11 = 0.f;
static real c_b16 = .3f;
#else /* NO_PROTO */
static real c_b10 = (float)1.;
static real c_b11 = (float)0.;
static real c_b16 = (float).3;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b20 = .7f;
#else /* NO_PROTO */
static real c_b20 = (float).7;
#endif /* NO_PROTO */
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b30 = 1.3f;
#else /* NO_PROTO */
static real c_b30 = (float)1.3;
#endif /* NO_PROTO */
static integer c__14 = 14;
static integer c__0 = 0;
static integer c__102 = 102;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__103 = 103;
#ifndef NO_PROTO
static real c_b59 = .15f;
static real c_b61 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b59 = (float).15;
static real c_b61 = (float).066666666666666666;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.04.02/08                        * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization of text index          * */
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
    static integer ix, iy, fcol;
    static real xact;
    static integer perm[14], txci;
    static real npcx, npcy, xexp;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nscmd (integer *, integer *), wcnpc_(real *, real *, real *, real 
	    *, real *), nbltm (real *, real *, real *, real *, real *, real *,
	     real *, integer *, real *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nscmd (), wcnpc_(), 
	    nbltm (), nclst ();
#endif /* NO_PROTO */
    static integer expdx[14];
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    nopst (integer *), nstxi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), nopst (), nstxi ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwi (integer *), nstxr (integer *, integer *
	    , integer *, integer *, real *, real *, integer *), rn1shf_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwi (), nstxr (), rn1shf_();
#endif /* NO_PROTO */
    static integer colind[5];
    static real scaley;
#ifndef NO_PROTO
    extern /* Subroutine */ int discol_(integer *, integer *, integer *), 
	    setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int discol_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setval_(char *, integer *, ftnlen), setasf_(integer *)
	    , nsatch (real *), nsatal (integer *, integer *), locatx_(integer 
	    *, real *), chkinq_(char *, integer *, ftnlen), numlab_(integer *,
	     real *, real *, real *), setmsg_(char *, char *, ftnlen, ftnlen),
	     dchpfv_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setval_(), setasf_(), 
	    nsatch (), nsatal (), locatx_(), chkinq_(), numlab_(), setmsg_(), 
	    dchpfv_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* colour model */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
    initgl_("04.02.04.02/08", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nscmd (&globnu_1.wkid, &c__1);
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
/*  *** *** ***   inheritance for text index  *** *** */
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
/*  set up 5 bundles */
    nstxr (&globnu_1.wkid, &c__1, &c__1, &c__2, &c_b10, &c_b11, colind);
    nstxr (&globnu_1.wkid, &c__2, &c__2, &c__2, &c_b10, &c_b16, &colind[1]);
    nstxr (&globnu_1.wkid, &c__3, &c__1, &c__2, &c_b20, &c_b16, &colind[2]);
    nstxr (&globnu_1.wkid, &c__4, &c__2, &c__2, &c_b20, &c_b11, &colind[3]);
    nstxr (&globnu_1.wkid, &c__5, &c__1, &c__2, &c_b30, &c_b11, &colind[4]);
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
/*  ratio of NPC to WC */
    wcnpc_(&c_b11, &c_b11, &npcx, &npcy, &npcpwc);
/*  use bundled attributes */
    setasf_(&c__0);
#ifndef NO_PROTO
    r__1 = npcpwc * .03f;
#else /* NO_PROTO */
    r__1 = npcpwc * (float).03;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nsatal (&c__2, &c__3);
#ifndef NO_PROTO
    xact = .4f;
    xexp = .7f;
#else /* NO_PROTO */
    xact = (float).4;
    xexp = (float).7;
#endif /* NO_PROTO */
    locatx_(perm, &xact);
    nexst (&c__102);
    locatx_(&perm[8], &xact);
    nstxi (&c__2);
    locatx_(&perm[9], &xact);
/*  Tricky code here: since structure 104 is re-invoked, it */
/*  generates annotation text primitive #5,6 on first invocation, */
/*  and 11,12 on 2nd.  But 11,12 would simply overlay 5,6, so we must */
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
    locatx_(&perm[12], &xact);
    locatx_(&perm[13], &xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    locatx_(&perm[1], &xact);
    nstxi (&c__3);
    nexst (&c__103);
    locatx_(&perm[7], &xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    locatx_(&perm[2], &xact);
    nstxi (&c__4);
    locatx_(&perm[3], &xact);
    nexst (&c__104);
    locatx_(&perm[6], &xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  text primitive 5 / 11 */
    locatx_(&perm[4], &xact);
    nstxi (&c__5);
/*  text primitive 6 / 12 */
    locatx_(&perm[5], &xact);
    nclst ();
/*  Expected attributes: structure #105 */
    nopst (&c__105);
/*  values for bundle index */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nstxi (&expdx[ix - 1]);
	locatx_(&perm[ix - 1], &xexp);
/* L1200: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b59, &r__1, &c_b61);
    nclst ();
#ifndef NO_PROTO
    setmsg_("1 3 4 6 7", "The text index should be saved and restored by <ex"
	    "ecute structure> during traversal.", 9L, 84L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT INDEX: Which pair of ann"
	    "otation text primitives does NOT match?", &c__14, &perm[13], 102L)
	    ;
#else /* NO_PROTO */
    setmsg_("1 3 4 6 7", "The text index should be saved and restored by <ex\
ecute structure> during traversal.", 9L, 84L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT INDEX: Which pair of ann\
otation text primitives does NOT match?", &c__14, &perm[13], 102L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

