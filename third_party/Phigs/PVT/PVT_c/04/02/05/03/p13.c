/* fort/04/02/05/03/p13.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b15 = 1.f;
#else /* NO_PROTO */
static real c_b15 = (float)1.;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__14 = 14;
static integer c__11 = 11;
static integer c__13 = 13;
static integer c__102 = 102;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__103 = 103;
#ifndef NO_PROTO
static real c_b49 = .15f;
static real c_b51 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b49 = (float).15;
static real c_b51 = (float).066666666666666666;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/13                        * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization of edge index          * */
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
    integer i__1, i__2;
    real r__1, r__2;

    /* Local variables */
    static real u, z;
    static integer ix, iy, siz;
    static real avg1, avg2;
    static integer fcol;
    static real xact[3];
    static integer perm[14], txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsis ();
#endif /* NO_PROTO */
    static real xexp[3];
    static integer idum1, idum2, idum3;
    static real rdum1, rdum2, rdum3;
    static integer edflg[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), nqedf (integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *), endit_(void), nsedi (integer *), 
	    nscmd (integer *, integer *), nsici (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), nqedf (), endit_(), nsedi (), 
	    nscmd (), nsici ();
#endif /* NO_PROTO */
    static real minew, maxew, nomew;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedr (integer *, integer *, integer *, 
	    integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedr ();
#endif /* NO_PROTO */
    static integer numet, expdx[14], numew;
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *), 
	    nbltm (real *, real *, real *, real *, real *, real *, real *, 
	    integer *, real *), nslmt (real *, integer *), nexst (integer *), 
	    nclst (void), nopst (integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnset_(), nbltm (), nslmt (), nexst (), 
	    nclst (), nopst (), nsvwi ();
#endif /* NO_PROTO */
    static real fxpty, altew1, altew2;
#ifndef NO_PROTO
    extern /* Subroutine */ int rn1shf_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rn1shf_();
#endif /* NO_PROTO */
    static integer dsedge, colind[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_(), chkinq_();
#endif /* NO_PROTO */
    static integer thised;
    static real scaley;
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, ledtyp[5];
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setrvs_(char *, real *, integer *, ftnlen), discol_(
	    integer *, integer *, integer *), setval_(char *, integer *, 
	    ftnlen), setasf_(integer *), nsiasf (integer *, integer *), 
	    loctri_(integer *, real *), numlab_(integer *, real *, real *, 
	    real *), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern doublereal ylocel_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setrvs_(), discol_(), 
	    setval_(), setasf_(), nsiasf (), loctri_(), numlab_(), setmsg_();
#endif /* NO_PROTO */

/* aspect source */
/* composition type */
/* interior style */
/* off/on switch for edge flag and error handling mode */
/* colour model */
/* aspect identifier */
    initgl_("04.02.05.03/13", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nscmd (&globnu_1.wkid, &c__1);
/*  All test cases use same basic structure network for testing */
/*  inheritance. */

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

/*  *** *** ***   inheritance for edge index   *** *** *** */
/*  numet  = number of edgetypes */
/*  numew  = number of available edge-widths */
/*  nomew  = nominal edge-width (DC) */
/*  minew,maxew = minimum,maximum edge-width (DC) */
    nqedf (&dialog_1.specwt, &c__0, &errind, &numet, &idum2, &numew, &nomew, &
	    minew, &maxew, &idum3);
    chkinq_("pqedf", &errind, 5L);
/*  x-location of actual / expected triangle */
    setrvs_("0.2,0.2,0.5", xact, &siz, 11L);
    setrvs_("0.6,0.6,0.9", xexp, &siz, 11L);
/*  set edge flag */
    for (ix = 1; ix <= 5; ++ix) {
	edflg[ix - 1] = 1;
/* L50: */
    }
    if (numet == 1) {
	edflg[2] = 0;
    }
/*  distinct edgetypes */
/* Computing MIN */
    i__1 = 5, i__2 = abs(numet);
    dsedge = min(i__1,i__2);
/*  pick no more than 5 out of whatever is available */
    i__1 = abs(numet);
    rnset_(&dsedge, &i__1, perm);
    for (ix = 1; ix <= 5; ++ix) {
	if (ix <= dsedge) {
	    nqedf (&dialog_1.specwt, &perm[ix - 1], &errind, &idum1, &thised, 
		    &idum2, &rdum1, &rdum2, &rdum3, &idum3);
	    chkinq_("pqedf", &errind, 5L);
	    ledtyp[ix - 1] = thised;
	} else {
	    ledtyp[ix - 1] = ledtyp[ix - dsedge - 1];
	}
/* L100: */
    }
/*  get alternative edgewidth scale values: */
/*  altew1, altew2 =  max, min edgewidth scale factor */
    altew1 = maxew / nomew;
    altew2 = minew / nomew;
/*  but, altew1 should not exceed .05 (WC) to avoid overlap - distance */
/*  between edges will be 1/15 = .06666 */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = altew1, r__2 = .016600000000000004f / (nomew * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = altew1, r__2 = (float).016600000000000004 / (nomew * 
	    dialog_1.wcpdc);
#endif /* NO_PROTO */
    altew1 = dmin(r__1,r__2);
/*  if default (1.0) is near altew1 or altew2, set alternate so as to */
/*  maximize the smallest gap among altew1, altew2, and 1.0: */
    avg1 = (altew1 + 1) / 2;
    avg2 = (altew2 + 1) / 2;
    if ((r__1 = altew1 - 1, dabs(r__1)) < (r__2 = avg2 - 1, dabs(r__2))) {
	altew1 = avg2;
    } else if ((r__1 = altew2 - 1, dabs(r__1)) < (r__2 = avg1 - 1, dabs(r__2))
	    ) {
	altew2 = avg1;
    }
/*  call DISCOL to try to get 5 distinct foreground colors, */
/*  returning fcol = actual number of foreground colors */
    discol_(&c__5, &globnu_1.wkid, &fcol);
    setval_("1,2,3,4,5", colind, 9L);
/*  if (fcol < 5)  copy 1st valid part of list to tail of list */
    if (fcol < 5) {
	iy = 1;
	for (ix = fcol + 1; ix <= 5; ++ix) {
	    colind[ix - 1] = colind[iy - 1];
	    ++iy;
/* L300: */
	}
    }
/*  set up bundles 1-5 */
    nsedr (&globnu_1.wkid, &c__1, edflg, ledtyp, &c_b15, colind);
    nsedr (&globnu_1.wkid, &c__2, &edflg[1], &ledtyp[1], &altew1, &colind[1]);

    nsedr (&globnu_1.wkid, &c__3, &edflg[2], &ledtyp[2], &altew2, &colind[2]);

    nsedr (&globnu_1.wkid, &c__4, &edflg[3], &ledtyp[3], &altew1, &colind[3]);

    nsedr (&globnu_1.wkid, &c__5, &edflg[4], &ledtyp[4], &altew2, &colind[4]);

/*  display 14 pairs of triangles, using bundles 1-5 */
/*  randomize location of edges */
    rn1shf_(&c__14, perm);
/*  set up CSS as described above */
/*  structure #101 */
    nopst (&picstr);
/*  by convention , view #1 is for picture */
    nsvwi (&c__1);
/*  use bundled attributes */
    setasf_(&c__0);
/*  set interior style attribute ASFs to INDIVIDUAL */
    nsiasf (&c__11, &c__1);
    nsiasf (&c__13, &c__1);
/*  set interior style = EMPTY, interior color index = 1 */
    nsis (&c__4);
    nsici (&c__1);
    loctri_(perm, xact);
    nexst (&c__102);
    loctri_(&perm[8], xact);
    nsedi (&c__2);
    loctri_(&perm[9], xact);
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
/*  execute structure #104 */
    nexst (&c__104);
/*  now, cancel out transformation */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
    loctri_(&perm[12], xact);
    loctri_(&perm[13], xact);
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
    loctri_(&perm[1], xact);
    nsedi (&c__3);
    nexst (&c__103);
    loctri_(&perm[7], xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
    loctri_(&perm[2], xact);
    nsedi (&c__4);
    loctri_(&perm[3], xact);
    nexst (&c__104);
    loctri_(&perm[6], xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
    loctri_(&perm[4], xact);
    nsedi (&c__5);
    loctri_(&perm[5], xact);
    nclst ();
/*  Expected attrubutes:   structure #105 */
    nopst (&c__105);
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
	nsedi (&expdx[ix - 1]);
	loctri_(&perm[ix - 1], xexp);
/* L400: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b49, &r__1, &c_b51);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 5 6 8 9", "The edge index should be saved and restored by <ex"
	    "ecute structure> during traversal.", 9L, 84L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE INDEX: Which pair of tri"
	    "angles does NOT match?", &c__14, &perm[13], 85L);
#else /* NO_PROTO */
    setmsg_("3 5 6 8 9", "The edge index should be saved and restored by <ex\
ecute structure> during traversal.", 9L, 84L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR EDGE INDEX: Which pair of tri\
angles does NOT match?", &c__14, &perm[13], 85L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

