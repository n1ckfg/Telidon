/* fort/04/02/01/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__104 = 104;
static integer c__3 = 3;
static integer c__105 = 105;
static integer c__103 = 103;
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b26 = 1.f;
static real c_b43 = .15f;
static real c_b45 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b26 = (float)1.;
static real c_b43 = (float).15;
static real c_b45 = (float).066666666666666666;
#endif /* NO_PROTO */
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.01.01/04                        * */
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
    /* Initialized data */

    static integer colind[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
    static integer expbas[14] = { 0,0,2,3,3,4,3,2,0,1,1,4,1,2 };

    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
    static real u, z;
    static integer ix;
    static real avg1, avg2;
    static integer fcol;
    static real xact[2];
    static integer perm[14], txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static real xexp[2];
    static integer idum1, idum2, idum3, cbase;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void), 
	    nbltm (real *, real *, real *, real *, real *, real *, real *, 
	    integer *, real *), nqplf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_(), nbltm (), nqplf (), 
	    nclst ();
#endif /* NO_PROTO */
    static real minlw, maxlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst ();
#endif /* NO_PROTO */
    static real nomlw, xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt ();
#endif /* NO_PROTO */
    static integer numlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwi ();
#endif /* NO_PROTO */
    static real altlw1, altlw2, scaley;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, picstr;
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *), rnperm_(
	    integer *, integer *), setasf_(integer *), locppl_(integer *, 
	    real *), nslwsc (real *), expppl_(integer *, real *, integer *, 
	    real *), numlab_(integer *, real *, real *, real *), setmsg_(char 
	    *, char *, ftnlen, ftnlen), dchpfv_(char *, integer *, integer *, 
	    ftnlen), discol_(integer *, integer *, integer *), nsplci (
	    integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_(), rnperm_(), 
	    setasf_(), locppl_(), nslwsc (), expppl_(), numlab_(), setmsg_(), 
	    dchpfv_(), discol_(), nsplci ();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* reference handling flag */
/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
    initgl_("04.02.01.01/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
/*  *** *** ***   inheritance for linestyle and linewidth   *** *** *** */

/*  use <inquire polyline facilities> to determine: */
/*    numlw  = number of available line-widths */
/*    nomlw  = nominal line-width (DC) */
/*    minlw,maxlw = minimum,maximum line-width (DC) */
    nqplf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &numlw, &nomlw, &
	    minlw, &maxlw, &idum3);
    chkinq_("pqplf", &errind, 5L);
/*  get alternative linewidth scale factors: */
/*  altlw1,2 = max,min scale factor */
    altlw1 = maxlw / nomlw;
/*  but make sure ALTLW1 .le. 0.05 in WC */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = altlw1, r__2 = .05f / (nomlw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = altlw1, r__2 = (float).05 / (nomlw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    altlw1 = dmin(r__1,r__2);
    altlw2 = minlw / nomlw;
/*  if default (1.0) is near altlw1 or altlw2, set alternate so as to */
/*  maximize the smallest gap among altlw1, altlw2, and 1.0: */
    avg1 = (altlw1 + 1) / 2;
    avg2 = (altlw2 + 1) / 2;
    if ((r__1 = altlw1 - 1, dabs(r__1)) < (r__2 = avg2 - 1, dabs(r__2))) {
	altlw1 = avg2;
    } else if ((r__1 = altlw2 - 1, dabs(r__1)) < (r__2 = avg1 - 1, dabs(r__2))
	    ) {
	altlw2 = avg1;
    }
/*  randomize order of polylines: */
    rnperm_(&c__14, perm);
/*  x-location of actual/expected lines: */
#ifndef NO_PROTO
    xact[0] = .2f;
    xact[1] = .55f;
    xexp[0] = .6f;
    xexp[1] = .95f;
#else /* NO_PROTO */
    xact[0] = (float).2;
    xact[1] = (float).55;
    xexp[0] = (float).6;
    xexp[1] = (float).95;
#endif /* NO_PROTO */
/*  set up CSS: */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  polyline 1 */
    locppl_(perm, xact);
    nexst (&c__102);
/*  polyline 9 */
    locppl_(&perm[8], xact);
/*  change-attributes: linestyle=2, linewidth=altlw1 */
    nsln (&c__2);
    nslwsc (&altlw1);
/*  polyline 10 */
    locppl_(&perm[9], xact);
/*  Tricky code here: since structure 104 is re-invoked, it */
/*  generates polyline #5,6 on first invocation, and 11,12 */
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
/*  polyline 13 */
    locppl_(&perm[12], xact);
/*  polyline 14 */
    locppl_(&perm[13], xact);
/*  execute 105 for expected values */
    nexst (&c__105);
    nclst ();
    nopst (&c__102);
/*  polyline 2 */
    locppl_(&perm[1], xact);
/*  change-attributes: linestyle=3, linewidth=altlw2 */
    nsln (&c__3);
    nslwsc (&altlw2);
/*  execute 103 */
    nexst (&c__103);
/*  polyline 8 */
    locppl_(&perm[7], xact);
    nclst ();
    nopst (&c__103);
/*  polyline 3 */
    locppl_(&perm[2], xact);
/*  change-attributes: linestyle=4, linewidth=altlw1 */
    nsln (&c__4);
    nslwsc (&altlw1);
/*  polyline 4 */
    locppl_(&perm[3], xact);
/*  execute 104 */
    nexst (&c__104);
/*  polyline 7 */
    locppl_(&perm[6], xact);
    nclst ();
    nopst (&c__104);
/*  polyline 5 / 11 */
    locppl_(&perm[4], xact);
/*  change-attributes: linestyle=2, linewidth=altlw2 */
    nsln (&c__2);
    nslwsc (&altlw2);
/*  polyline 6 / 12 */
    locppl_(&perm[5], xact);
    nclst ();
/*  Expected attributes (except #14, whose actual linestyle should be 2): 
*/
    nopst (&c__105);
    expppl_(perm, xexp, &c__1, &c_b26);
    expppl_(&perm[1], xexp, &c__1, &c_b26);
    expppl_(&perm[2], xexp, &c__3, &altlw2);
    expppl_(&perm[3], xexp, &c__4, &altlw1);
    expppl_(&perm[4], xexp, &c__4, &altlw1);
    expppl_(&perm[5], xexp, &c__2, &altlw2);
    expppl_(&perm[6], xexp, &c__4, &altlw1);
    expppl_(&perm[7], xexp, &c__3, &altlw2);
    expppl_(&perm[8], xexp, &c__1, &c_b26);
    expppl_(&perm[9], xexp, &c__2, &altlw1);
    expppl_(&perm[10], xexp, &c__2, &altlw1);
    expppl_(&perm[11], xexp, &c__2, &altlw2);
    expppl_(&perm[12], xexp, &c__2, &altlw1);
    expppl_(&perm[13], xexp, &c__4, &altlw1);
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b43, &r__1, &c_b45);
    nclst ();
/*  Structure network #101 draws actual results in random order on */
/*  left side of picture.  Structure #105 draws expected results in */
/*  same random order on right side of picture, except for polyline */
/*  14 which is deliberately drawn with incorrect attributes. This */
/*  should be the only non-matching pair in the picture. */
#ifndef NO_PROTO
    setmsg_("3 5 6 11 12 14 15 17 18", "The linestyle and linewidth attribut"
	    "es for the polyline primitive should be saved and restored by <e"
	    "xecute structure> during traversal.", 23L, 135L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR LINESTYLE AND LINEWIDTH: Whic"
	    "h pair of lines does NOT match?", &c__14, &perm[13], 94L);
#else /* NO_PROTO */
    setmsg_("3 5 6 11 12 14 15 17 18", "The linestyle and linewidth attribut\
es for the polyline primitive should be saved and restored by <execute struc\
ture> during traversal.", 23L, 135L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR LINESTYLE AND LINEWIDTH: Whic\
h pair of lines does NOT match?", &c__14, &perm[13], 94L);
#endif /* NO_PROTO */
/*  *** *** ***   inheritance for polyline color index   *** *** *** */
/*  clear the decks */
    for (ix = 101; ix <= 105; ++ix) {
	nemst (&ix);
/* L200: */
    }
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
/*  set up PERM to randomize position of polylines */
    rnperm_(&c__14, perm);
    cbase = 0;
/*  set up CSS: */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  set linetype = 1; set linewidth = .05 in WC */
    nsln (&c__1);
#ifndef NO_PROTO
    r__1 = .05f / (nomlw * dialog_1.wcpdc);
#else /* NO_PROTO */
    r__1 = (float).05 / (nomlw * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nslwsc (&r__1);
/*  polyline 1 */
    locppl_(perm, xact);
    nexst (&c__102);
/*  polyline 9 */
    locppl_(&perm[8], xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nsplci (&colind[cbase % fcol]);
/*  polyline 10 */
    locppl_(&perm[9], xact);
/*  Tricky code here: see comments above under linestyle */
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
/*  polyline 13 */
    locppl_(&perm[12], xact);
/*  polyline 14 */
    locppl_(&perm[13], xact);
/*  execute 105 for expected values */
    nexst (&c__105);
    nclst ();
    nopst (&c__102);
/*  polyline 2 */
    locppl_(&perm[1], xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nsplci (&colind[cbase % fcol]);
/*  execute 103 */
    nexst (&c__103);
/*  polyline 8 */
    locppl_(&perm[7], xact);
    nclst ();
    nopst (&c__103);
/*  polyline 3 */
    locppl_(&perm[2], xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nsplci (&colind[cbase % fcol]);
/*  polyline 4 */
    locppl_(&perm[3], xact);
/*  execute 104 */
    nexst (&c__104);
/*  polyline 7 */
    locppl_(&perm[6], xact);
    nclst ();
    nopst (&c__104);
/*  polyline 5 / 11 */
    locppl_(&perm[4], xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nsplci (&colind[cbase % fcol]);
/*  polyline 6 / 12 */
    locppl_(&perm[5], xact);
    nclst ();
/*  Expected attributes (except #14, whose actual color should be */
/*  same as #13): */
    nopst (&c__105);
/*  color index = 1 or colind(cbase mod fcol) */
/*  polyline 1:14 gets cbase = 0,0,2,3,3,4,3,2,0,1,1,4,1,2 */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b43, &r__1, &c_b45);
    for (ix = 1; ix <= 14; ++ix) {
	nsplci (&colind[expbas[ix - 1] % fcol]);
	locppl_(&perm[ix - 1], xexp);
/* L210: */
    }
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 20 21 23 24", "The polyline color index attribute for the pol"
	    "yline primitive should be saved and restored by <execute structu"
	    "re> during traversal.", 13L, 131L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYLINE COLOR INDEX: Which p"
	    "air of lines does NOT match?", &c__14, &perm[13], 91L);
#else /* NO_PROTO */
    setmsg_("3 20 21 23 24", "The polyline color index attribute for the pol\
yline primitive should be saved and restored by <execute structure> during t\
raversal.", 13L, 131L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYLINE COLOR INDEX: Which p\
air of lines does NOT match?", &c__14, &perm[13], 91L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

