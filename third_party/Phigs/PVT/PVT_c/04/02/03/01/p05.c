/* fort/04/02/03/01/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b12 = .8f;
#else /* NO_PROTO */
static real c_b12 = (float).8;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b15 = .035f;
#else /* NO_PROTO */
static real c_b15 = (float).035;
#endif /* NO_PROTO */
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__103 = 103;
#ifndef NO_PROTO
static real c_b33 = .15f;
#else /* NO_PROTO */
static real c_b33 = (float).15;
#endif /* NO_PROTO */
static integer c__101 = 101;
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.01/05                        * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization for non-geometric      * */
/*  *                 text attributes                       * */
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

    static integer ldisfn[5] = { 1,2,1,2,1 };
    static integer ldispr[5] = { 1,2,0,1,2 };
#ifndef NO_PROTO
    static real ldisxp[5] = { 1.f,.4f,.7f,1.3f,1.7f };
    static real ldissp[5] = { 0.f,1.4f,1.1f,.5f,-.3f };
#else /* NO_PROTO */
    static real ldisxp[5] = { (float)1.,(float).4,(float).7,(float)1.3,(float)
	    1.7 };
    static real ldissp[5] = { (float)0.,(float)1.4,(float)1.1,(float).5,(
	    float)-.3 };
#endif /* NO_PROTO */
    static integer colind[11] = { 1,2,3,4,5,6,7,8,9,10,11 };

    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
    static real u, z;
    static integer ix, iy, fcol;
    static real xact;
    static integer nfpp, perm[20], txci;
    static real xexp;
    static integer idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
    static integer cbase;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nschh (real *), nbltm (real *, real *, real *, real *, real *, 
	    real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nschh (), nbltm ();
#endif /* NO_PROTO */
    static integer subct;
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
#endif /* NO_PROTO */
    static integer expdx[14];
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst ();
#endif /* NO_PROTO */
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nqtxf (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, integer *, real *, real *, integer *), nexst (
	    integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nqtxf (), nexst (), nopst ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwi (integer *), nstxp (integer *), rn1shf_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwi (), nstxp (), rn1shf_();
#endif /* NO_PROTO */
    static real scaley;
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer errind, thisfn, thispr, picstr;
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), chkinq_(char *, integer *, ftnlen), setasf_(integer *)
	    , nschxp (real *), nstxal (integer *, integer *), loctxt_(integer 
	    *, real *), nstxfn (integer *), nstxpr (integer *), setval_(char *
	    , integer *, ftnlen), numlab_(integer *, real *, real *, real *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), dchpfv_(char *, integer *
	    , integer *, ftnlen), nschsp (real *), discol_(integer *, integer 
	    *, integer *), nstxci (integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
    extern /* Subroutine */ int initgl_(), xpopph_(), chkinq_(), setasf_(), 
	    nschxp (), nstxal (), loctxt_(), nstxfn (), nstxpr (), setval_(), 
	    numlab_(), setmsg_(), dchpfv_(), nschsp (), discol_(), nstxci ();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/*  ldisfn,ldispr = list of 5 distinct font,precision pairs */
/*  ldisxp,ldissp = list of 5 distinct expansion and spacing values */
    initgl_("04.02.03.01/05", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
/*  use <inquire text facilities> to find three other available */
/*  fonts, if any, and use them in ldisfn(3, 4, and 5). */
    nqtxf (&dialog_1.specwt, &c__0, &errind, &nfpp, &idum1, &idum2, &idum3, &
	    rdum1, &rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    subct = 0;
    i__1 = nfpp;
    for (ix = 1; ix <= i__1; ++ix) {
	nqtxf (&dialog_1.specwt, &ix, &errind, &idum1, &thisfn, &thispr, &
		idum3, &rdum1, &rdum2, &idum4, &rdum3, &rdum4, &idum5);
	chkinq_("pqtxf", &errind, 5L);
	if (thisfn == 1 || thisfn == 2) {
	    goto L100;
	}
/*  searching back from 5 to 3, because 5 has the hardest precision */

/*  to be requested (stroke), while 3 has the easiest (string). */
	for (iy = 5; iy >= 3; --iy) {
	    if (ldisfn[iy - 1] >= 1 && ldisfn[iy - 1] <= 2 && thispr >= 
		    ldispr[iy - 1]) {
		ldisfn[iy - 1] = thisfn;
		++subct;
		if (subct >= 3) {
		    goto L110;
		} else {
		    goto L100;
		}
	    }
/* L105: */
	}
L100:
	;
    }
L110:
/*  set up random permutation, with uniform scaling */
    rn1shf_(&c__14, perm);
/*  set up CSS: */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nschxp (&c_b12);
    nstxal (&c__1, &c__3);
    nschh (&c_b15);
    nstxp (&c__0);
/*  left margin for actual, expected values, and Y-increment: */
#ifndef NO_PROTO
    xact = .2f;
    xexp = .6f;
    yincr = .066666666666666666f;
#else /* NO_PROTO */
    xact = (float).2;
    xexp = (float).6;
    yincr = (float).066666666666666666;
#endif /* NO_PROTO */
/*  text 1 */
    loctxt_(perm, &xact);
    nexst (&c__102);
/*  text 9 */
    loctxt_(&perm[8], &xact);
/*  change-attributes: use ldisfn(2),ldispr(2) */
    nstxfn (&ldisfn[1]);
    nstxpr (&ldispr[1]);
/*  text 10 */
    loctxt_(&perm[9], &xact);
/*  Tricky code here: since structure 104 is re-invoked, it */
/*  generates text #5,6 on first invocation, and 11,12 */
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
/*  scaley should be 1.0, because PERM was craftily re-arranged, above */
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
/*  text 13 */
    loctxt_(&perm[12], &xact);
/*  text 14 */
    loctxt_(&perm[13], &xact);
/*  execute 105 for expected values */
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
/*  text 2 */
    loctxt_(&perm[1], &xact);
/*  change-attributes: use ldisfn(3),ldispr(3) */
    nstxfn (&ldisfn[2]);
    nstxpr (&ldispr[2]);
/*  execute 103 */
    nexst (&c__103);
/*  text 8 */
    loctxt_(&perm[7], &xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
/*  text 3 */
    loctxt_(&perm[2], &xact);
/*  change-attributes: use ldisfn(4),ldispr(4) */
    nstxfn (&ldisfn[3]);
    nstxpr (&ldispr[3]);
/*  text 4 */
    loctxt_(&perm[3], &xact);
/*  execute 104 */
    nexst (&c__104);
/*  text 7 */
    loctxt_(&perm[6], &xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  text 5 / 11 */
    loctxt_(&perm[4], &xact);
/*  change-attributes: use ldisfn(5),ldispr(5) */
    nstxfn (&ldisfn[4]);
    nstxpr (&ldispr[4]);
/*  text 6 / 12 */
    loctxt_(&perm[5], &xact);
    nclst ();
/*  Structure network #101 draws actual results in random order on */
/*  left side of picture.  Structure #105 draws expected results in */
/*  same random order on right side of picture, except for text */
/*  14 which is deliberately drawn with incorrect attributes. This */
/*  should be the only non-matching pair in the picture. */
/*  structure #105 */
    nopst (&c__105);
/* using 1 as 14th "incorrect" value because 1st and 2nd must be distinct,
*/
/*  since font 1 and 2 must be distinct. */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,1", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
/*  change-attributes to expected values */
	nstxfn (&ldisfn[expdx[ix - 1] - 1]);
	nstxpr (&ldispr[expdx[ix - 1] - 1]);
	loctxt_(&perm[ix - 1], &xexp);
/* L200: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b33, &r__1, &yincr);
    nclst ();
#ifndef NO_PROTO
    setmsg_("11 13 21 23 24 27 28 32 33", "The text font and precision attri"
	    "butes for the text primitive should be saved and restored by <ex"
	    "ecute structure> during traversal.", 26L, 131L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT FONT AND PRECISION: Whic"
	    "h pair of text primitives does NOT match?", &c__14, &perm[13], 
	    104L);
#else /* NO_PROTO */
    setmsg_("11 13 21 23 24 27 28 32 33", "The text font and precision attri\
butes for the text primitive should be saved and restored by <execute struct\
ure> during traversal.", 26L, 131L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT FONT AND PRECISION: Whic\
h pair of text primitives does NOT match?", &c__14, &perm[13], 104L);
#endif /* NO_PROTO */
/*  *** *** ***   character expansion and spacing   *** *** *** */
/*  clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  set up random permutation, with uniform scaling */
    rn1shf_(&c__14, perm);
/*  set up CSS: */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nstxal (&c__1, &c__3);
    nschh (&c_b15);
    nstxp (&c__0);
    nstxfn (&c__1);
    nstxpr (&c__2);
/*  text 1 */
    loctxt_(perm, &xact);
    nexst (&c__102);
/*  text 9 */
    loctxt_(&perm[8], &xact);
/*  change-attributes: use ldisxp(2),ldissp(2) */
    nschxp (&ldisxp[1]);
    nschsp (&ldissp[1]);
/*  text 10 */
    loctxt_(&perm[9], &xact);
/*  Tricky code here: see comments above */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    fxpty = ylocel_(&perm[4]);
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
/*  scaley should be 1.0, because PERM was craftily re-arranged, above */
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
/*  text 13 */
    loctxt_(&perm[12], &xact);
/*  text 14 */
    loctxt_(&perm[13], &xact);
/*  execute 105 for expected values */
    nexst (&c__105);
    nclst ();
/*  structure #102 */
    nopst (&c__102);
/*  text 2 */
    loctxt_(&perm[1], &xact);
/*  change-attributes: use ldisxp(3),ldissp(3) */
    nschxp (&ldisxp[2]);
    nschsp (&ldissp[2]);
/*  execute 103 */
    nexst (&c__103);
/*  text 8 */
    loctxt_(&perm[7], &xact);
    nclst ();
/*  structure #103 */
    nopst (&c__103);
/*  text 3 */
    loctxt_(&perm[2], &xact);
/*  change-attributes: use ldisxp(4),ldissp(4) */
    nschxp (&ldisxp[3]);
    nschsp (&ldissp[3]);
/*  text 4 */
    loctxt_(&perm[3], &xact);
/*  execute 104 */
    nexst (&c__104);
/*  text 7 */
    loctxt_(&perm[6], &xact);
    nclst ();
/*  structure #104 */
    nopst (&c__104);
/*  text 5 / 11 */
    loctxt_(&perm[4], &xact);
/*  change-attributes: use ldisxp(5),ldissp(5) */
    nschxp (&ldisxp[4]);
    nschsp (&ldissp[4]);
/*  text 6 / 12 */
    loctxt_(&perm[5], &xact);
    nclst ();
/*  Structure network #101 draws actual results in random order on */
/*  left side of picture.  Structure #105 draws expected results in */
/*  same random order on right side of picture, except for text */
/*  14 which is deliberately drawn with incorrect attributes. This */
/*  should be the only non-matching pair in the picture. */
/*  structure #105 */
    nopst (&c__105);
/*  values for index into expected expansion and spacing */
    setval_("1,1,3,4,4,5,4,3,1,2,2,5,2,3", expdx, 27L);
    for (ix = 1; ix <= 14; ++ix) {
/*  change-attributes to expected values */
	nschxp (&ldisxp[expdx[ix - 1] - 1]);
	nschsp (&ldissp[expdx[ix - 1] - 1]);
	loctxt_(&perm[ix - 1], &xexp);
/* L210: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b33, &r__1, &yincr);
    nclst ();
#ifndef NO_PROTO
    setmsg_("11 35 36 38 39 41 42 44 45", "The character expansion factor an"
	    "d character spacing attributes for the text primitive should be "
	    "saved and restored by <execute structure> during traversal.", 26L,
	     156L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR CHARACTER EXPANSION AND SPACI"
	    "NG: Which pair of text primitives does NOT match?", &c__14, &perm[
	    13], 112L);
#else /* NO_PROTO */
    setmsg_("11 35 36 38 39 41 42 44 45", "The character expansion factor an\
d character spacing attributes for the text primitive should be saved and re\
stored by <execute structure> during traversal.", 26L, 156L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR CHARACTER EXPANSION AND SPACI\
NG: Which pair of text primitives does NOT match?", &c__14, &perm[13], 112L);
#endif /* NO_PROTO */
/*  *** *** *** ***   text colour index   *** *** *** *** */
/*  clear the decks */
    nemst (&c__101);
    nemst (&c__102);
    nemst (&c__103);
    nemst (&c__104);
    nemst (&c__105);
/*  set up random permutation, with uniform scaling */
    rn1shf_(&c__14, perm);
/*  call DISCOL to try to get 5 distinct foreground colors, */
/*    returning fcol = actual number of foreground colors */
    discol_(&c__5, &globnu_1.wkid, &fcol);
    if (fcol <= 1) {
	fcol = 2;
/*  colind[0:1] = circular list of indices = [1,0] */
	colind[0] = 1;
	colind[1] = 0;
    } else {
/*  colind[0:fcol-1] = circular list of indices = [1,..,fcol] (as is) 
*/
    }
    cbase = 0;
/*  set up CSS: */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nstxal (&c__1, &c__3);
    nschh (&c_b15);
    nstxp (&c__0);
    nstxfn (&c__2);
    nstxpr (&c__2);
/*  text 1 */
    loctxt_(perm, &xact);
    nexst (&c__102);
/*  text 9 */
    loctxt_(&perm[8], &xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nstxci (&colind[cbase % fcol]);
/*  text 10 */
    loctxt_(&perm[9], &xact);
/*  Tricky code here: see comments above */
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
/*  text 13 */
    loctxt_(&perm[12], &xact);
/*  text 14 */
    loctxt_(&perm[13], &xact);
/*  execute 105 for expected values */
    nexst (&c__105);
    nclst ();
    nopst (&c__102);
/*  text 2 */
    loctxt_(&perm[1], &xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nstxci (&colind[cbase % fcol]);
/*  execute 103 */
    nexst (&c__103);
/*  text 8 */
    loctxt_(&perm[7], &xact);
    nclst ();
    nopst (&c__103);
/*  text 3 */
    loctxt_(&perm[2], &xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nstxci (&colind[cbase % fcol]);
/*  text 4 */
    loctxt_(&perm[3], &xact);
/*  execute 104 */
    nexst (&c__104);
/*  text 7 */
    loctxt_(&perm[6], &xact);
    nclst ();
    nopst (&c__104);
/*  text 5 / 11 */
    loctxt_(&perm[4], &xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nstxci (&colind[cbase % fcol]);
/*  text 6 / 12 */
    loctxt_(&perm[5], &xact);
    nclst ();
    nopst (&c__105);
/*  Expected attributes (except #14, whose actual color should be */
/*  same as #13): */
/*  color index = colind(cbase mod fcol) */

/*  structure #105 */
/*  text    cbase           text    cbase */
/*  ----    -----           ----    ----- */
/*  01      0               08      2 */
/*  02      0               09      0 */
/*  03      2               10      1 */
/*  04      3               11      1 */
/*  05      3               12      4 */
/*  06      4               13      1 */
/*  07      3               14      2 */
    for (ix = 1; ix <= 14; ++ix) {
	nstxci (&colind[(expdx[ix - 1] - 1) % fcol]);
	loctxt_(&perm[ix - 1], &xexp);
/* L220: */
    }
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b33, &r__1, &yincr);
    nclst ();
#ifndef NO_PROTO
    setmsg_("11 47 48 50 51", "The text color index attribute for the text p"
	    "rimitive should be saved and restored by <execute structure> dur"
	    "ing traversal.", 14L, 123L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT COLOR INDEX: Which pair "
	    "of text primitives does NOT match?", &c__14, &perm[13], 97L);
#else /* NO_PROTO */
    setmsg_("11 47 48 50 51", "The text color index attribute for the text p\
rimitive should be saved and restored by <execute structure> during traversa\
l.", 14L, 123L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR TEXT COLOR INDEX: Which pair \
of text primitives does NOT match?", &c__14, &perm[13], 97L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

