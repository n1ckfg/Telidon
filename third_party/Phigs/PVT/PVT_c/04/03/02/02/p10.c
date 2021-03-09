/* fort/04/03/02/02/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__106 = 106;
static integer c__102 = 102;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b30 = 0.f;
#else /* NO_PROTO */
static real c_b30 = (float)0.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/10                        * */
/*  *    TEST TITLE : Foreground colour                     * */
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
    static real gbm[9]	/* was [3][3] */ = { 0.f,1.f,0.f,0.f,0.f,1.f,1.f,0.f,
	    1.f };
#else /* NO_PROTO */
    static real gbm[9]	/* was [3][3] */ = { (float)0.,(float)1.,(float)0.,(
	    float)0.,(float)0.,(float)1.,(float)1.,(float)0.,(float)1. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3, r__4;

    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal);
#else /* NO_PROTO */
    double sqrt();
#endif /* NO_PROTO */

    /* Local variables */
    static real bg[3], fg[3], xa[100], ya[100], xf[9]	/* was [3][3] */;
    static integer ix, bgi;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *), win6_(
	    integer *, integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm (), win6_();
#endif /* NO_PROTO */
    static integer perm[6];
    static real xloc;
    static integer txci, ngsq;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    , nqcr (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *), nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr (), nqcr (), nsmk ();
#endif /* NO_PROTO */
    static real xsiz, ysiz, side1, side2;
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum2, rdum3;
    static integer maxci;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *), endit_(void), nscmd (integer *, integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_(), endit_(), nscmd ();
#endif /* NO_PROTO */
    static real sqinc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nclst (void), nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmf (), nclst (), nemst ();
#endif /* NO_PROTO */
    static real nomms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    nopst (integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), nopst (), nsvwi ();
#endif /* NO_PROTO */
    static real bckcol[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     chkinq_(char *, integer *, ftnlen), setdlg_(integer *, integer *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, numret, colsiz, sqside, window, nxtcol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static real mrksiz, xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    nsmksc (real *), rnperm_(integer *, integer *), nspmci (integer *)
	    , sqgrmk_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nqwksl (), 
	    setmsg_(), nsmksc (), rnperm_(), nspmci (), sqgrmk_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* marker type */
/*  type of returned value */
/*  composition type */
/*  colour model */
    initgl_("04.03.02.02/10", 14L);
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
/*  set colour model = RGB */
    nscmd (&globnu_1.wkid, &c__1);
    nexst (&c__106);
    nexst (&c__102);
    nclst ();
/*  divide screen up into six labelled square areas */
    win6_(&c__106, &c__1, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
/*  bg = requested background colour = randomly: green, blue or magenta */

    bgi = rndint_(&c__1, &c__3);
    bg[0] = gbm[bgi * 3 - 3];
    bg[1] = gbm[bgi * 3 - 2];
    bg[2] = gbm[bgi * 3 - 1];
/*  set color representation #0 to bg */
    nscr (&globnu_1.wkid, &c__0, &c__3, bg);
/*  inquire color representation #0 as realized to determine */
/*    bckcol = actual background color */
    nqcr (&globnu_1.wkid, &c__0, &c__3, &c__1, &errind, &numret, bckcol);
    chkinq_("pqcr", &errind, 4L);
/*  inquire workstation state table lengths to determine */
/*    colsiz = number of settable entries in color table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &colsiz, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  maxci = maximum color index = colsiz-1 */
    maxci = colsiz - 1;
/*  fg = foreground color farthest from bckcol in color cube */
    for (ix = 1; ix <= 3; ++ix) {
#ifndef NO_PROTO
	if (bckcol[ix - 1] < .5f) {
	    fg[ix - 1] = 1.f;
#else /* NO_PROTO */
	if (bckcol[ix - 1] < (float).5) {
	    fg[ix - 1] = (float)1.;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    fg[ix - 1] = 0.f;
#else /* NO_PROTO */
	    fg[ix - 1] = (float)0.;
#endif /* NO_PROTO */
	}
/* L50: */
    }
/*  set color representations from #1 to #maxci to fg */
    i__1 = maxci;
    for (ix = 1; ix <= i__1; ++ix) {
	nscr (&globnu_1.wkid, &ix, &c__3, fg);
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("30 31 32", "All the positive entries within the reported size o"
	    "f the color table should control a foreground colour.", 8L, 104L);

#else /* NO_PROTO */
    setmsg_("30 31 32", "All the positive entries within the reported size o\
f the color table should control a foreground colour.", 8L, 104L);
#endif /* NO_PROTO */
/*  sqside = integer number of polymarkers per side of square array */
/*         = sqrt(colsiz/4 + 1) + 1 */
/*  (this ensures all color slots will be used) */
/*  side1 = 0.1 */
/*  side2 = 0.9 */
/*  sqinc = increment for square = (side2-side1) / (sqside-1) */
/*  mrksiz = polymarker size = min(0.05, 0.2 * sqinc) */
#ifndef NO_PROTO
    sqside = sqrt(colsiz / 4.f + 1.f) + 1;
    side1 = .1f;
    side2 = .9f;
#else /* NO_PROTO */
    sqside = sqrt(colsiz / (float)4. + (float)1.) + 1;
    side1 = (float).1;
    side2 = (float).9;
#endif /* NO_PROTO */
    sqinc = (side2 - side1) / (sqside - 1);
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = .05f, r__2 = sqinc * .2f;
#else /* NO_PROTO */
    r__1 = (float).05, r__2 = sqinc * (float).2;
#endif /* NO_PROTO */
    mrksiz = dmin(r__1,r__2);
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum2, &rdum3, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  set polymarker style = plus (+) */
/*  set polymarker size = mrksiz (in WC) */
    nsmk (&c__2);
    r__1 = mrksiz / (nomms * dialog_1.wcpdc);
    nsmksc (&r__1);
/*  perm = randomize order from 1 to 6 */
    rnperm_(&c__6, perm);
/*  nxtcol = next color index to use = maxci */
    nxtcol = maxci;
/*  draw square grids of polymarkers */
    for (ix = 1; ix <= 6; ++ix) {
	window = perm[ix - 1];
/*     set tranformation to scale unit square into this window */
	ebltm_(&c_b30, &c_b30, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b30, &
		xsiz, &xsiz, xf);
	nslmt (xf, &c__2);
	if (window == 1) {
/*  simulate incorrect display */
	    ngsq = ix;
	    nspmci (&c__1);
#ifndef NO_PROTO
	    r__1 = side2 + sqinc * .5f;
#else /* NO_PROTO */
	    r__1 = side2 + sqinc * (float).5;
#endif /* NO_PROTO */
	    sqgrmk_(&side1, &r__1, &sqinc);
/*  put a polymarker at a non-aligned position */
	    i__1 = sqside - 2;
#ifndef NO_PROTO
	    xa[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + .5f);
#else /* NO_PROTO */
	    xa[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + (float).5);
#endif /* NO_PROTO */
	    i__1 = sqside - 2;
#ifndef NO_PROTO
	    ya[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + .5f);
#else /* NO_PROTO */
	    ya[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + (float).5);
#endif /* NO_PROTO */
	    npm (&c__1, xa, ya);
	} else if (window == 2) {
/*  simulate correct display */
	    nspmci (&c__1);
#ifndef NO_PROTO
	    r__1 = side2 + sqinc * .5f;
#else /* NO_PROTO */
	    r__1 = side2 + sqinc * (float).5;
#endif /* NO_PROTO */
	    sqgrmk_(&side1, &r__1, &sqinc);
	} else {
/*  draw an actual grid */
#ifndef NO_PROTO
	    r__1 = side2 + sqinc * .5f;
#else /* NO_PROTO */
	    r__1 = side2 + sqinc * (float).5;
#endif /* NO_PROTO */
	    r__2 = sqinc;
	    for (xloc = side1; r__2 < 0 ? xloc >= r__1 : xloc <= r__1; xloc +=
		     r__2) {
#ifndef NO_PROTO
		r__3 = side2 + sqinc * .5f;
#else /* NO_PROTO */
		r__3 = side2 + sqinc * (float).5;
#endif /* NO_PROTO */
		r__4 = sqinc;
		for (yloc = side1; r__4 < 0 ? yloc >= r__3 : yloc <= r__3; 
			yloc += r__4) {
		    if (nxtcol < maxci) {
			++nxtcol;
		    } else {
			nxtcol = 1;
		    }
/*  display single polymarker: xa,ya */
		    nspmci (&nxtcol);
		    xa[0] = xloc;
		    ya[0] = yloc;
		    npm (&c__1, xa, ya);
/* L235: */
		}
/* L230: */
	    }
	}
/* L200: */
    }
#ifndef NO_PROTO
    dchpfv_("FOREGROUND COLOUR: Which polymarker is different in either colo"
	    "r or geometry?", &c__6, &ngsq, 77L);
#else /* NO_PROTO */
    dchpfv_("FOREGROUND COLOUR: Which polymarker is different in either colo\
r or geometry?", &c__6, &ngsq, 77L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

