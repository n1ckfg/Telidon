/* fort/04/02/02/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__5 = 5;
static integer c__103 = 103;
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b26 = 1.f;
static real c_b43 = .25f;
static real c_b45 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b26 = (float)1.;
static real c_b43 = (float).25;
static real c_b45 = (float).066666666666666666;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.01/04                        * */
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
    static real xact[5];
    static integer perm[14], txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk ();
#endif /* NO_PROTO */
    static real xexp[5];
    static integer idum1, idum2, idum3, cbase;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), endit_();
#endif /* NO_PROTO */
    static real nolap;
#ifndef NO_PROTO
    extern /* Subroutine */ int nbltm (real *, real *, real *, real *, real *,
	     real *, real *, integer *, real *), nqpmf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , integer *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nbltm (), nqpmf (), nclst ();
#endif /* NO_PROTO */
    static real minmw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst ();
#endif /* NO_PROTO */
    static real maxmw, xform[9]	/* was [3][3] */, nommw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt ();
#endif /* NO_PROTO */
    static integer nummw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nsvwi (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nsvwi ();
#endif /* NO_PROTO */
    static real fxpty, altmw1, altmw2;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_(), chkinq_();
#endif /* NO_PROTO */
    static real scaley;
#ifndef NO_PROTO
    extern /* Subroutine */ int numlab_(integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int numlab_();
#endif /* NO_PROTO */
    static integer errind, picstr;
    static real shifty;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *), rnperm_(
	    integer *, integer *), setasf_(integer *), locppm_(integer *, 
	    real *), nsmksc (real *), expppm_(integer *, real *, integer *, 
	    real *), setmsg_(char *, char *, ftnlen, ftnlen), discol_(integer 
	    *, integer *, integer *), nspmci (integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_(), rnperm_(), 
	    setasf_(), locppm_(), nsmksc (), expppm_(), setmsg_(), discol_(), 
	    nspmci ();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* reference handling flag */
    initgl_("04.02.02.01/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
/*  *** *** ***   inheritance for marker type and marker size *** *** */
/*  use <inquire polymarker facilities> to determine: */
/*    nummw  = number of available marker-sizes */
/*    nommw  = nominal marker-size (DC) */
/*    minmw,maxmw = minimum,maximum marker-size (DC) */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &nummw, &nommw, &
	    minmw, &maxmw, &idum3);
    chkinq_("pqpmf", &errind, 5L);
/*  nolap = .05 = distance between lines will be 1/15 - to avoid overlap 
*/
#ifndef NO_PROTO
    nolap = .05f / (nommw * dialog_1.wcpdc);
#else /* NO_PROTO */
    nolap = (float).05 / (nommw * dialog_1.wcpdc);
#endif /* NO_PROTO */
/*  get alternative marker size scale factor values: */
/*  make sure ALTMW1 < NOLAP */
/* Computing MIN */
    r__1 = maxmw / nommw;
    altmw1 = dmin(r__1,nolap);
    altmw2 = dialog_1.qvis / nommw;
/*  if default (1.0) is near altmw1 or altmw2, set alternate so as to */
/*  maximize the smallest gap among altmw1, altmw2, and 1.0: */
    avg1 = (altmw1 + 1) / 2;
    avg2 = (altmw2 + 1) / 2;
    if ((r__1 = altmw1 - 1, dabs(r__1)) < (r__2 = avg2 - 1, dabs(r__2))) {
	altmw1 = avg2;
    } else if ((r__1 = altmw2 - 1, dabs(r__1)) < (r__2 = avg1 - 1, dabs(r__2))
	    ) {
	altmw2 = avg1;
    }
/*  randomize order of polymarkers: */
    rnperm_(&c__14, perm);
/*  x-location of actual/expected markers: */
#ifndef NO_PROTO
    xact[0] = .35f;
    xexp[0] = .5f;
#else /* NO_PROTO */
    xact[0] = (float).35;
    xexp[0] = (float).5;
#endif /* NO_PROTO */
/*  set up CSS: */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  polymarker 1 */
    locppm_(perm, xact);
    nexst (&c__102);
/*  polymarker 9 */
    locppm_(&perm[8], xact);
/*  change-attributes: marker type=2, marker size=altmw1 */
/*  do not use marker type 1 (dot) */
    nsmk (&c__2);
    nsmksc (&altmw1);
/*  polymarker 10 */
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
/*  polymarker 13 */
    locppm_(&perm[12], xact);
/*  polymarker 14 */
    locppm_(&perm[13], xact);
/*  execute 105 for expected values */
    nexst (&c__105);
    nclst ();
    nopst (&c__102);
/*  polymarker 2 */
    locppm_(&perm[1], xact);
/*  change-attributes: marker type=5, marker size=altmw2 */
    nsmk (&c__5);
    nsmksc (&altmw2);
/*  execute 103 */
    nexst (&c__103);
/*  polymarker 8 */
    locppm_(&perm[7], xact);
    nclst ();
    nopst (&c__103);
/*  polymarker 3 */
    locppm_(&perm[2], xact);
/*  change-attributes: marker type=4, marker size=altmw1 */
    nsmk (&c__4);
    nsmksc (&altmw1);
/*  polymarker 4 */
    locppm_(&perm[3], xact);
/*  execute 104 */
    nexst (&c__104);
/*  polymarker 7 */
    locppm_(&perm[6], xact);
    nclst ();
    nopst (&c__104);
/*  polymarker 5 / 11 */
    locppm_(&perm[4], xact);
/*  change-attributes: marker type=2, marker size=altmw2 */
    nsmk (&c__2);
    nsmksc (&altmw2);
/*  polymarker 6 / 12 */
    locppm_(&perm[5], xact);
    nclst ();
/*  Expected attributes (except #14, whose actual marker type should be 2)
 */
    nopst (&c__105);
    expppm_(perm, xexp, &c__3, &c_b26);
    expppm_(&perm[1], xexp, &c__3, &c_b26);
    expppm_(&perm[2], xexp, &c__5, &altmw2);
    expppm_(&perm[3], xexp, &c__4, &altmw1);
    expppm_(&perm[4], xexp, &c__4, &altmw1);
    expppm_(&perm[5], xexp, &c__2, &altmw2);
    expppm_(&perm[6], xexp, &c__4, &altmw1);
    expppm_(&perm[7], xexp, &c__5, &altmw2);
    expppm_(&perm[8], xexp, &c__3, &c_b26);
    expppm_(&perm[9], xexp, &c__2, &altmw1);
    expppm_(&perm[10], xexp, &c__2, &altmw1);
    expppm_(&perm[11], xexp, &c__2, &altmw2);
    expppm_(&perm[12], xexp, &c__2, &altmw1);
    expppm_(&perm[13], xexp, &c__4, &altmw1);
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b43, &r__1, &c_b45);
    nclst ();
/*  Structure network #101 draws actual results in random order on */
/*  left side of picture.  Structure #105 draws expected results in */
/*  same random order on right side of picture, except for polymarker */
/*  14 which is deliberately drawn with different attributes. This */
/*  should be the only non-matching pair in the picture. */
#ifndef NO_PROTO
    setmsg_("3 5 6 11 12 14 15 18 19", "The marker type and marker size attr"
	    "ibutes for the polymarker primitive should be saved and restored"
	    " by <execute structure> during traversal.", 23L, 141L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR MARKER TYPE AND MARKER SIZE: "
	    "Which pair of markers does NOT match?", &c__14, &perm[13], 100L);
#else /* NO_PROTO */
    setmsg_("3 5 6 11 12 14 15 18 19", "The marker type and marker size attr\
ibutes for the polymarker primitive should be saved and restored by <execute\
 structure> during traversal.", 23L, 141L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR MARKER TYPE AND MARKER SIZE: \
Which pair of markers does NOT match?", &c__14, &perm[13], 100L);
#endif /* NO_PROTO */
/*  *** *** ***   inheritance for polymarker color index   *** *** *** */
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
/*  set up PERM to randomize position of polymarkers */
    rnperm_(&c__14, perm);
    cbase = 0;
/*  set up CSS: */
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
/*  set marker type = 3; set marker size = NOLAP (.05 in WC) */
    nsmk (&c__3);
    nsmksc (&nolap);
/*  polymarker 1 */
    locppm_(perm, xact);
    nexst (&c__102);
/*  polymarker 9 */
    locppm_(&perm[8], xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nspmci (&colind[cbase % fcol]);
/*  polymarker 10 */
    locppm_(&perm[9], xact);
/*  Tricky code here: see comments above under marker type */
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
/*  polymarker 13 */
    locppm_(&perm[12], xact);
/*  polymarker 14 */
    locppm_(&perm[13], xact);
/*  execute 105 for expected values */
    nexst (&c__105);
    nclst ();
    nopst (&c__102);
/*  polymarker 2 */
    locppm_(&perm[1], xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nspmci (&colind[cbase % fcol]);
/*  execute 103 */
    nexst (&c__103);
/*  polymarker 8 */
    locppm_(&perm[7], xact);
    nclst ();
    nopst (&c__103);
/*  polymarker 3 */
    locppm_(&perm[2], xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nspmci (&colind[cbase % fcol]);
/*  polymarker 4 */
    locppm_(&perm[3], xact);
/*  execute 104 */
    nexst (&c__104);
/*  polymarker 7 */
    locppm_(&perm[6], xact);
    nclst ();
    nopst (&c__104);
/*  polymarker 5 / 11 */
    locppm_(&perm[4], xact);
/*  increment cbase */
    ++cbase;
/*  change-attributes: use colind(cbase mod fcol) for next color index */
    nspmci (&colind[cbase % fcol]);
/*  polymarker 6 / 12 */
    locppm_(&perm[5], xact);
    nclst ();
/*  Expected attributes (except #14, whose actual color should be */
/*  same as #13): */
    nopst (&c__105);
/*  color index = 1 or colind(cbase mod fcol) */
/*  polymarker 1:14 gets cbase = 0,0,2,3,3,4,3,2,0,1,1,4,1,2 */
/*  draw labels */
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b43, &r__1, &c_b45);
    for (ix = 1; ix <= 14; ++ix) {
	nspmci (&colind[expbas[ix - 1] % fcol]);
	locppm_(&perm[ix - 1], xexp);
/* L210: */
    }
    nclst ();
#ifndef NO_PROTO
    setmsg_("3 21 22 24 25", "The polymarker color index attribute for the p"
	    "olymarker primitive should be saved and restored by <execute str"
	    "ucture> during traversal.", 13L, 135L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYMARKER COLOR INDEX: Which"
	    " pair of markers does NOT match?", &c__14, &perm[13], 95L);
#else /* NO_PROTO */
    setmsg_("3 21 22 24 25", "The polymarker color index attribute for the p\
olymarker primitive should be saved and restored by <execute structure> duri\
ng traversal.", 13L, 135L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR POLYMARKER COLOR INDEX: Which\
 pair of markers does NOT match?", &c__14, &perm[13], 95L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

