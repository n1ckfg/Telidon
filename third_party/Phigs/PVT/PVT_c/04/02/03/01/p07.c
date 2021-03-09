/* fort/04/02/03/01/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__6 = 6;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b21 = .15f;
static real c_b25 = .2f;
#else /* NO_PROTO */
static real c_b21 = (float).15;
static real c_b25 = (float).2;
#endif /* NO_PROTO */
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b46 = .1f;
#else /* NO_PROTO */
static real c_b46 = (float).1;
#endif /* NO_PROTO */
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.01/07                        * */
/*  *    TEST TITLE : Text color index                      * */
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
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
#else /* NO_PROTO */
    double cos(), sin();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[9], ya[9];
    static integer ix;
    static real rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx ();
#endif /* NO_PROTO */
    static integer cdim;
    static real chht;
    static integer undf[3], perm[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr ();
#endif /* NO_PROTO */
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpf_(char *, integer *, integer *, integer *
	    , ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpf_();
#endif /* NO_PROTO */
    static integer colel;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *), endit_(void), nschh (real *), nscmd (
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci (), endit_(), nschh (), nscmd ();
#endif /* NO_PROTO */
    static integer numci;
    static real centx, centy, yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst ();
#endif /* NO_PROTO */
    static integer txcol[20], txtci, visdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nsvwi (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nsvwi ();
#endif /* NO_PROTO */
    static real bckcol[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     chkinq_(char *, integer *, ftnlen), setdlg_(integer *, integer *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, numlin, picstr, viscol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer maxcol, explct, szcolt;
    static real forcol[6], newcol[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), nqwksl (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     rnbset_(integer *, integer *, integer *, integer *), rnperm_(
	    integer *, integer *), nstxci (integer *), numlab_(integer *, 
	    real *, real *, real *), nsplci (integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), setmsg_(), 
	    nqwksl (), rnbset_(), rnperm_(), nstxci (), numlab_(), nsplci (), 
	    nstxpr ();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* colour model */
/* type of returned value */
/* text precision */
/*  Declare program-specific variables */
    initgl_("04.02.03.01/07", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
#ifndef NO_PROTO
    setmsg_("11 46 47 48", "A defined text color index should cause the addr"
	    "essed entry in the color table to be used when rendering a text "
	    "primitive.", 11L, 122L);
#else /* NO_PROTO */
    setmsg_("11 46 47 48", "A defined text color index should cause the addr\
essed entry in the color table to be used when rendering a text primitive.", 
	    11L, 122L);
#endif /* NO_PROTO */
    nscmd (&globnu_1.wkid, &c__1);
/*  bckcol = background color = realized color spec for entry #0 */
/*  forcol = foreground color = realized color spec for entry #1 */
    nqcr (&globnu_1.wkid, &c__0, &c__6, &c__1, &errind, &cdim, bckcol);
    chkinq_("pqcr", &errind, 4L);
    nqcr (&globnu_1.wkid, &c__1, &c__6, &c__1, &errind, &cdim, forcol);
    chkinq_("pqcr", &errind, 4L);
/*  szcolt = maximum size of color table (including entry #0) */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &szcolt, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  how many lines to draw */
    numlin = min(8,szcolt);
/*  txcol  = random permutation of #0,#1, and numlin-2 random choices */
/*           from entries #2 to #szcolt-1 */
/*  from values 2 to SZCOLT-1, pick NUMLIN-2 entries */
    i__1 = numlin - 2;
    i__2 = szcolt - 1;
    rnbset_(&i__1, &c__2, &i__2, txcol);
/*  add in 0 and 1 */
    txcol[numlin - 2] = 1;
    txcol[numlin - 1] = 0;
    rnperm_(&numlin, perm);
/*  from txcol, randomly select entry #visdx, but not the one that */
/*    contains 0, since this may not be re-settable. */
    i__1 = numlin - 1;
    visdx = rndint_(&c__1, &i__1);
    viscol = txcol[visdx - 1];
/*  ensure dialogue and labels visible */
    dialog_1.dtxci = viscol;
    nstxci (&viscol);
#ifndef NO_PROTO
    yloc = .9f;
    yincr = .8f / (numlin - 1);
#else /* NO_PROTO */
    yloc = (float).9;
    yincr = (float).8 / (numlin - 1);
#endif /* NO_PROTO */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = yincr * .35f;
    chht = dmin(r__1,.05f);
#else /* NO_PROTO */
    r__1 = yincr * (float).35;
    chht = dmin(r__1,(float).05);
#endif /* NO_PROTO */
    nschh (&chht);
#ifndef NO_PROTO
    r__1 = yloc + chht * .5f;
#else /* NO_PROTO */
    r__1 = yloc + chht * (float).5;
#endif /* NO_PROTO */
    numlab_(&numlin, &c_b21, &r__1, &yincr);
/*  for each color entry - set to background color and draw line */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  set entry txcol(ix) to bckcol */
	txtci = txcol[perm[ix - 1] - 1];
	nscr (&globnu_1.wkid, &txtci, &cdim, bckcol);
	nstxci (&txtci);
/*  randomly pick and set a precision, to ensure no interaction */
	i__2 = rndint_(&c__0, &c__2);
	nstxpr (&i__2);
/*  draw text line #ix with text colour index = txcol(ix) */
	ntx (&c_b25, &yloc, "Defined text color", 18L);
	yloc -= yincr;
/* L2100: */
    }
/*  set entry txcol(visdx) to forcol */
    nscr (&globnu_1.wkid, &viscol, &cdim, forcol);
    dchpf_("DEFINED TEXT COLOR INDICES: Which text line is visible?", &numlin,
	     &visdx, perm, 55L);
/*  clear out last display from structure */
    nemst (&c__102);
#ifndef NO_PROTO
    setmsg_("11 46 47 49", "An undefined text color index should cause entry"
	    " number 1 in the color table to be used when rendering a text pr"
	    "imitive.", 11L, 120L);
#else /* NO_PROTO */
    setmsg_("11 46 47 49", "An undefined text color index should cause entry\
 number 1 in the color table to be used when rendering a text primitive.", 
	    11L, 120L);
#endif /* NO_PROTO */
/*  Try to set entry #1 opposite from BCKCOL */
    for (ix = 1; ix <= 3; ++ix) {
#ifndef NO_PROTO
	if (bckcol[ix - 1] > .5f) {
	    newcol[ix - 1] = 0.f;
#else /* NO_PROTO */
	if (bckcol[ix - 1] > (float).5) {
	    newcol[ix - 1] = (float)0.;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    newcol[ix - 1] = 1.f;
#else /* NO_PROTO */
	    newcol[ix - 1] = (float)1.;
#endif /* NO_PROTO */
	}
/* L2150: */
    }
/*  set entry #1 different from FORCOL - make sure that the undefined */
/*    entries default to *current* color-rep of #1, not just a */
/*    predefined color. */
#ifndef NO_PROTO
    if (forcol[2] > .5f) {
	newcol[2] = 0.f;
#else /* NO_PROTO */
    if (forcol[2] > (float).5) {
	newcol[2] = (float)0.;
#endif /* NO_PROTO */
    } else {
#ifndef NO_PROTO
	newcol[2] = 1.f;
#else /* NO_PROTO */
	newcol[2] = (float)1.;
#endif /* NO_PROTO */
    }
    nscr (&globnu_1.wkid, &c__1, &cdim, newcol);
    nqeci (&globnu_1.wkid, &c__0, &errind, &numci, &idum1);
    chkinq_("pqeci", &errind, 5L);
    maxcol = 0;
    i__1 = numci;
    for (ix = 1; ix <= i__1; ++ix) {
	nqeci (&globnu_1.wkid, &ix, &errind, &idum1, &colel);
	chkinq_("pqeci", &errind, 5L);
	maxcol = max(maxcol,colel);
/* L2200: */
    }
/*  undf1,undf2,undf3 = 3 undefined, positive color indices */
    undf[0] = maxcol + 1;
    undf[1] = maxcol + 10;
    undf[2] = maxcol + 90;
/*  explct = number of explicit lines of color #1 = random integer */
/*    from 0 to 4 */
    explct = rndint_(&c__0, &c__4);
    numlin = explct + 3;
    rnperm_(&numlin, perm);
/*  draw star with color #1 */
#ifndef NO_PROTO
    rad = .15f;
    centx = .5f;
    centy = .75f;
#else /* NO_PROTO */
    rad = (float).15;
    centx = (float).5;
    centy = (float).75;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
	ya[ix - 1] = centy + rad * cos(ix * 12.566370600000001f / 5);
	xa[ix - 1] = centx + rad * sin(ix * 12.566370600000001f / 5);
#else /* NO_PROTO */
	ya[ix - 1] = centy + rad * cos(ix * (float)12.566370600000001 / 5);
	xa[ix - 1] = centx + rad * sin(ix * (float)12.566370600000001 / 5);
#endif /* NO_PROTO */
/* L2400: */
    }
    nsplci (&c__1);
    npl (&c__6, xa, ya);
/*  display interleaved: */
/*    three text lines of color u1,u2,u3, */
/*    explct text lines of color #1 */
#ifndef NO_PROTO
    yloc = .5f;
    yincr = .0625f;
#else /* NO_PROTO */
    yloc = (float).5;
    yincr = (float).0625;
#endif /* NO_PROTO */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = yincr * .35f;
    chht = dmin(r__1,.05f);
#else /* NO_PROTO */
    r__1 = yincr * (float).35;
    chht = dmin(r__1,(float).05);
#endif /* NO_PROTO */
    nschh (&chht);
/*  for each color entry - set to background color and draw text string */

    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
	colel = perm[ix - 1];
	if (colel <= 3) {
	    nstxci (&undf[colel - 1]);
	} else {
	    nstxci (&c__1);
	}
/*  randomly pick and set a precision, to ensure no interaction */
	i__2 = rndint_(&c__0, &c__2);
	nstxpr (&i__2);
	ntx (&c_b46, &yloc, "Undefined color", 15L);
	yloc -= yincr;
/* L2300: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED TEXT COLOR INDICES: How many text lines are the same "
	    "color as the star?", &c__12, &numlin, 81L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED TEXT COLOR INDICES: How many text lines are the same \
color as the star?", &c__12, &numlin, 81L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

