/* fort/04/03/04/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

struct {
    integer black, green, yellow, white, blue;
} colors_;

#define colors_1 colors_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;
static integer c__8 = 8;
#ifndef NO_PROTO
static real c_b22 = .15f;
#else /* NO_PROTO */
static real c_b22 = (float).15;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b74 = 0.f;
#else /* NO_PROTO */
static real c_b74 = (float)0.;
#endif /* NO_PROTO */
static integer c__7 = 7;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.04.02/tsthlf                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tsthlf_(integer *wkid, integer *incsiz, integer *incset, 
	integer *excsiz, integer *excset)
#else /* NO_PROTO */
/* Subroutine */ int tsthlf_(wkid, incsiz, incset, excsiz, excset)
integer *wkid, *incsiz, *incset, *excsiz, *excset;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int elgprm_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), dlstpf_(char *, integer *, 
	    integer *, char *, ftnlen, ftnlen), nshlft (integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int elgprm_(), dlstpf_(), nshlft ();
#endif /* NO_PROTO */
    static integer trulis[8], trusiz;

/*  TSTHLF tests that the appropriate primitives are highlighted for */
/*  a given inclusion and exclusion set used as the highlighting */
/*  filter. */
/*  Input parameters: */
/*    WKID          : workstation identifier */
/*    INCSIZ,INCSET : inclusion set */
/*    EXCSIZ,EXCSET : exclusion set */
/*  <set highlighting filter>: */
    /* Parameter adjustments */
    --excset;
    --incset;

    /* Function Body */
    nshlft (wkid, incsiz, &incset[1], excsiz, &excset[1]);
/*  Compute expected subset of highlighted primitives from incl,excl */
    elgprm_(incsiz, &incset[1], excsiz, &excset[1], &trusiz, trulis);
#ifndef NO_PROTO
    dlstpf_("HIGHLIGHTING FILTER: For which pairs is the primitive on the le"
	    "ft highlighted (n if none)?", &trusiz, trulis, "S", 90L, 1L);
    return 0;
#else /* NO_PROTO */
    dlstpf_("HIGHLIGHTING FILTER: For which pairs is the primitive on the le\
ft highlighted (n if none)?", &trusiz, trulis, "S", 90L, 1L);
#endif /* NO_PROTO */
} /* tsthlf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.04.02/tstivf                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tstivf_(integer *wkid, integer *incsiz, integer *incset, 
	integer *excsiz, integer *excset)
#else /* NO_PROTO */
/* Subroutine */ int tstivf_(wkid, incsiz, incset, excsiz, excset)
integer *wkid, *incsiz, *incset, *excsiz, *excset;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int elgprm_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), dlstpf_(char *, integer *, 
	    integer *, char *, ftnlen, ftnlen), nsivft (integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int elgprm_(), dlstpf_(), nsivft ();
#endif /* NO_PROTO */
    static integer trulis[8], trusiz;

/*  TSTIVF tests that the appropriate primitives are invisible for */
/*  a given inclusion and exclusion set used as the invisibility */
/*  filter. */
/*  Input parameters: */
/*    WKID          : workstation identifier */
/*    INCSIZ,INCSET : inclusion set */
/*    EXCSIZ,EXCSET : exclusion set */
/*  <set invisibility filter>: */
    /* Parameter adjustments */
    --excset;
    --incset;

    /* Function Body */
    nsivft (wkid, incsiz, &incset[1], excsiz, &excset[1]);
/*  Compute expected subset of invisible primitives from incl,excl */
    elgprm_(incsiz, &incset[1], excsiz, &excset[1], &trusiz, trulis);
    dlstpf_("INVISIBILITY FILTER: Which primitives are invisible (n if none)?"
	    , &trusiz, trulis, "S", 64L, 1L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstivf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.04.02/nmscol                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int nmscol_(integer *wkid)
#else /* NO_PROTO */
/* Subroutine */ int nmscol_(wkid)
integer *wkid;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real blck[3] = { 0.f,0.f,0.f };
    static real grn[3] = { 0.f,1.f,0.f };
    static real yellw[3] = { 1.f,1.f,0.f };
    static real wht[3] = { 1.f,1.f,1.f };
    static real blu[3] = { 0.f,0.f,1.f };
#else /* NO_PROTO */
    static real blck[3] = { (float)0.,(float)0.,(float)0. };
    static real grn[3] = { (float)0.,(float)1.,(float)0. };
    static real yellw[3] = { (float)1.,(float)1.,(float)0. };
    static real wht[3] = { (float)1.,(float)1.,(float)1. };
    static real blu[3] = { (float)0.,(float)0.,(float)1. };
#endif /* NO_PROTO */

#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd (), chkinq_();
#endif /* NO_PROTO */
    static integer maxcol, errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwksl (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwksl ();
#endif /* NO_PROTO */

/*  Subroutine NMSCOL sets the workstation color indices for the */
/*  specified colors.  If the station does not support color, all */
/*  indices are set to 1 (the foreground color). */

/*  Input parameter: */
/*    WKID:  workstation identifier */
/* colour model */
/* Colors */
/*  maxcol = maximum size of color table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &maxcol, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  If workstation allows, set up its color table with entries: */
/*  color index   RGB        color */
/*  -----------   ---        ----- */
/*     0          0,0,0      black */
/*     1          0,1,0      green */
/*     2          1,1,0      yellow */
/*     3          1,1,1      white */
/*     4          0,0,1      blue */

    if (maxcol > 4) {
/*  set color model = rgb */
	nscmd (wkid, &c__1);
/*  Set representation for workstation */
	colors_1.black = 0;
	colors_1.green = 1;
	colors_1.yellow = 2;
	colors_1.white = 3;
	colors_1.blue = 4;
	nscr (wkid, &colors_1.black, &c__3, blck);
	nscr (wkid, &colors_1.green, &c__3, grn);
	nscr (wkid, &colors_1.yellow, &c__3, yellw);
	nscr (wkid, &colors_1.white, &c__3, wht);
	nscr (wkid, &colors_1.blue, &c__3, blu);
    } else {
/*  MONO set for only 2 colors */
	colors_1.black = 0;
	colors_1.green = 1;
	colors_1.yellow = 1;
	colors_1.white = 1;
	colors_1.blue = 1;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* nmscol_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.04.02/elgprm                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int elgprm_(integer *incsiz, integer *incset, integer *
	excsiz, integer *excset, integer *trusiz, integer *trulis)
#else /* NO_PROTO */
/* Subroutine */ int elgprm_(incsiz, incset, excsiz, excset, trusiz, trulis)
integer *incsiz, *incset, *excsiz, *excset, *trusiz, *trulis;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix, sval, list[8], primid;
#ifndef NO_PROTO
    extern /* Subroutine */ int setval_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setval_();
#endif /* NO_PROTO */

/*  Subroutine ELGPRM determines the eligible primitives for the */
/*  given inclusion and exclusion set. The eligible primitives are */
/*  returned in TRULIS. */
/*  Input parameters: */
/*    INCSIZ,INCSET : inclusion set */
/*    EXCSIZ,EXCSET : exclusion set */
/*  Output parameters: */
/*    TRUSIZ,TRULIS : list of eligible primitives */
/*   Check the include and exclude sets to determine which */
/*   of the following primitives will be highlighted. */
/*   position  primitive        color   nameset */
/*     1       polyline           1      0, 1, 2 */
/*     2       polymarker         2      3, 4, 5 */
/*     3       fill area          3      6, 7, 8 */
/*     4       cell array         4      9,10,11 */
/*     5       text               1     12,13,14 */
/*     6       polyline 3         2     15,16,17 */
/*     7       annotation text    3     18,19,20 */
/*     8       fill area set      4     21,22,23 */
/*   First check the inclusion set, include any primitive that */
/*   appears, then check the exclusion set, removing any primitive */
/*   that appears, the set we are left with are the eligible ones. */
/*   Names outside of 0-23 are ignored. */
    /* Parameter adjustments */
    --trulis;
    --excset;
    --incset;

    /* Function Body */
    setval_("0,0,0,0,0,0,0,0", list, 15L);
    i__1 = *incsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	sval = incset[ix];
	if (sval >= 0 && sval <= 23) {
	    primid = sval / 3 + 1;
	    list[primid - 1] = 1;
	}
/* L100: */
    }
    i__1 = *excsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	sval = excset[ix];
	if (sval >= 0 && sval <= 23) {
	    primid = sval / 3 + 1;
	    list[primid - 1] = 0;
	}
/* L110: */
    }
    *trusiz = 0;
    for (ix = 1; ix <= 8; ++ix) {
	if (list[ix - 1] == 1) {
	    ++(*trusiz);
	    trulis[*trusiz] = ix;
	}
/* L120: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* elgprm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.03.04.02/nmsprm                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int nmsprm_(logical *hlight)
#else /* NO_PROTO */
/* Subroutine */ int nmsprm_(hlight)
logical *hlight;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer colia[9]	/* was [3][3] */ = { 2,1,2,1,2,1,2,2,1 };

    /* System generated locals */
    real r__1;

    /* Local variables */
    static real x1, y1, y2, x2, x3, x4, x5, x6, x7, x8;
#ifndef NO_PROTO
    extern /* Subroutine */ int nca (real *, real *, real *, real *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    );
#else /* NO_PROTO */
    extern /* Subroutine */ int nca ();
#endif /* NO_PROTO */
    static integer ixa[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), npm (integer 
	    *, real *, real *), ntx (real *, real *, char *, ftnlen), npl3 (
	    integer *, real *, real *, real *), nads (integer *, integer *), 
	    nfas (integer *, integer *, real *, real *), natr (real *, real *,
	     real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), npm (), ntx (), npl3 (), nads (), 
	    nfas (), natr ();
#endif /* NO_PROTO */
    static real npcx, npcy, xval[4], yval[4], zval[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nres (integer *, integer *), nsis (integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nres (), nsis ();
#endif /* NO_PROTO */
    static real ytop;
#ifndef NO_PROTO
    extern doublereal ypos8_(integer *);
#else /* NO_PROTO */
    extern doublereal ypos8_();
#endif /* NO_PROTO */
    static integer names[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), nsici (integer *), wcnpc_(
	    real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), nsici (), wcnpc_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int numlab_(integer *, real *, real *, real *), 
	    nsatch (real *), nsatal (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int numlab_(), nsatch (), nsatal ();
#endif /* NO_PROTO */
    static real npcpwc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsplci (integer *), setval_(char *, integer *,
	     ftnlen), nspmci (integer *), nstxci (integer *), nstxal (integer 
	    *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsplci (), setval_(), nspmci (), nstxci (), 
	    nstxal ();
#endif /* NO_PROTO */

/*  Subroutine NMSPRM will draw the eight primitives for possible */
/*  invisibility or highlighting (2 copies of each for the latter) */
/*  down the screen and label each with the appropriate nameset. */
/* interior style */
/* text alignment horizontal */
/* text alignment vertical */
/*  Set up structure of primitives to be displayed, numbered 1-8 down */
/*  the screen: */
/*  number   primitive        color    nameset */
/*  ------   ---------        -----    ------- */
/*     1     polyline           1      0, 1, 2 */
/*     2     polymarker         2      3, 4, 5 */
/*     3     fill area          3      6, 7, 8 */
/*     4     cell array                9,10,11 */
/*     5     text               1     12,13,14 */
/*     6     polyline 3         2     15,16,17 */
/*     7     annotation text    3     18,19,20 */
/*     8     fill area set      4     21,22,23 */
#ifndef NO_PROTO
    yincr = .1111111111111111f;
#else /* NO_PROTO */
    yincr = (float).1111111111111111;
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    nstxci (&colors_1.yellow);
    numlab_(&c__8, &c_b22, &ytop, &yincr);
/*  horizontal positions */
#ifndef NO_PROTO
    x1 = .2f;
    x2 = .5f;
#else /* NO_PROTO */
    x1 = (float).2;
    x2 = (float).5;
#endif /* NO_PROTO */
    x3 = x1 + (x2 - x1) / 3;
    x4 = x1;
#ifndef NO_PROTO
    x5 = .6f;
    x6 = .9f;
#else /* NO_PROTO */
    x5 = (float).6;
    x6 = (float).9;
#endif /* NO_PROTO */
    x7 = x5 + (x6 - x5) / 3;
    x8 = x5;
/*  #1  polyline, color = 1, nameset = 0,1,2 */
    nsplci (&colors_1.green);
    setval_("0,1,2", names, 5L);
    nads (&c__3, names);
    xval[0] = x1;
    xval[1] = x2;
    yval[0] = ypos8_(&c__1);
    yval[1] = yval[0];
    npl (&c__2, xval, yval);
    nres (&c__3, names);
    if (*hlight) {
/* Comparison Copy */
	xval[0] = x5;
	xval[1] = x6;
	npl (&c__2, xval, yval);
    }
/*  #2  polymarker, color = 2, nameset = 3,4,5 */
    nspmci (&colors_1.yellow);
    setval_("3,4,5", names, 5L);
    nads (&c__3, names);
    xval[0] = x3;
    yval[0] = ypos8_(&c__2);
    npm (&c__1, xval, yval);
    nres (&c__3, names);
    if (*hlight) {
/* Comparison Copy */
	xval[0] = x7;
	npm (&c__1, xval, yval);
    }
/*  #3  fill area, color = 3, nameset = 6,7,8 */
    nsici (&colors_1.white);
    nsis (&c__1);
    setval_("6,7,8", names, 5L);
    nads (&c__3, names);
    xval[0] = x1;
    xval[1] = x2;
    xval[2] = x3;
#ifndef NO_PROTO
    yval[1] = ypos8_(&c__3) - .02f;
#else /* NO_PROTO */
    yval[1] = ypos8_(&c__3) - (float).02;
#endif /* NO_PROTO */
    yval[2] = yval[1];
#ifndef NO_PROTO
    yval[0] = yval[1] + .035f;
#else /* NO_PROTO */
    yval[0] = yval[1] + (float).035;
#endif /* NO_PROTO */
    ixa[0] = 3;
    nfas (&c__1, ixa, xval, yval);
    nres (&c__3, names);
    if (*hlight) {
/* Comparison Copy */
	xval[0] = x5;
	xval[1] = x6;
	xval[2] = x7;
	nfas (&c__1, ixa, xval, yval);
    }
/*  #4  cell array, color = 4, nameset = 9,10,11 */
    setval_("9,10,11", names, 7L);
    nads (&c__3, names);
#ifndef NO_PROTO
    y1 = ypos8_(&c__4) - .02f;
    y2 = y1 + .05f;
#else /* NO_PROTO */
    y1 = ypos8_(&c__4) - (float).02;
    y2 = y1 + (float).05;
#endif /* NO_PROTO */
    nca (&x1, &y1, &x2, &y2, &c__3, &c__3, &c__1, &c__1, &c__3, &c__3, colia);

    nres (&c__3, names);
    if (*hlight) {
/* Comparison Copy */
	nca (&x5, &y1, &x6, &y2, &c__3, &c__3, &c__1, &c__1, &c__3, &c__3, 
		colia);
    }
/*  #5  text, color = 1, nameset = 12,13,14 */
    nstxci (&colors_1.green);
    nstxal (&c__2, &c__3);
#ifndef NO_PROTO
    r__1 = yincr * .2f;
#else /* NO_PROTO */
    r__1 = yincr * (float).2;
#endif /* NO_PROTO */
    nschh (&r__1);
    setval_("12,13,14", names, 8L);
    nads (&c__3, names);
    y1 = ypos8_(&c__5);
    r__1 = (x1 + x2) / 2;
    ntx (&r__1, &y1, "PHIGS", 5L);
    nres (&c__3, names);
    if (*hlight) {
/* Comparison Copy */
	r__1 = (x5 + x6) / 2;
	ntx (&r__1, &y1, "PHIGS", 5L);
    }
/*  #6  polyline 3, color = 2, nameset = 15,16,17 */
    nsplci (&colors_1.yellow);
    setval_("15,16,17", names, 8L);
    nads (&c__3, names);
    yval[0] = ypos8_(&c__6);
    yval[1] = yval[0];
    xval[0] = x1;
    xval[1] = x2;
#ifndef NO_PROTO
    zval[0] = 0.f;
    zval[1] = 1.f;
#else /* NO_PROTO */
    zval[0] = (float)0.;
    zval[1] = (float)1.;
#endif /* NO_PROTO */
    npl3 (&c__2, xval, yval, zval);
    nres (&c__3, names);
    if (*hlight) {
/* Comparison Copy */
	xval[0] = x5;
	xval[1] = x6;
	npl3 (&c__2, xval, yval, zval);
    }
/*  #7  annotation text, color = 3, nameset = 18,19,20 */
    nstxci (&colors_1.white);
    nsatal (&c__2, &c__3);
    wcnpc_(&c_b74, &c_b74, &npcx, &npcy, &npcpwc);
#ifndef NO_PROTO
    r__1 = yincr * .2f * npcpwc;
#else /* NO_PROTO */
    r__1 = yincr * (float).2 * npcpwc;
#endif /* NO_PROTO */
    nsatch (&r__1);
    setval_("18,19,20", names, 8L);
    nads (&c__3, names);
    y1 = ypos8_(&c__7);
    r__1 = (x1 + x2) / 2;
    natr (&r__1, &y1, &c_b74, &c_b74, "Version #2", 10L);
    nres (&c__3, names);
    if (*hlight) {
/* Comparison Copy */
	r__1 = (x5 + x6) / 2;
	natr (&r__1, &y1, &c_b74, &c_b74, "Version #2", 10L);
    }
/*  #8  fill area set, color = 4, nameset = 21,22,23 */
    nsici (&colors_1.blue);
    setval_("21,22,23", names, 8L);
    nads (&c__3, names);
    y1 = ypos8_(&c__8);
#ifndef NO_PROTO
    yval[0] = y1 + .02f;
    yval[1] = y1 - .02f;
    yval[2] = y1 - .02f;
    yval[3] = y1 + .02f;
#else /* NO_PROTO */
    yval[0] = y1 + (float).02;
    yval[1] = y1 - (float).02;
    yval[2] = y1 - (float).02;
    yval[3] = y1 + (float).02;
#endif /* NO_PROTO */
    xval[0] = x1;
    xval[1] = x2;
    xval[2] = x3;
    xval[3] = x4;
    ixa[0] = 4;
    nfas (&c__1, ixa, xval, yval);
    nres (&c__3, names);
    if (*hlight) {
/* Comparison Copy */
	xval[0] = x5;
	xval[1] = x6;
	xval[2] = x7;
	xval[3] = x8;
	nfas (&c__1, ixa, xval, yval);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* nmsprm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION 04.03.04.02/ypos8                    * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal ypos8_(integer *yth)
#else /* NO_PROTO */
doublereal ypos8_(yth)
integer *yth;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  YPOS8 returns the appropriate y-coordinate in WC for element */
/*  number yth. */
#ifndef NO_PROTO
    ret_val = (9 - *yth) / 9.f;
#else /* NO_PROTO */
    ret_val = (9 - *yth) / (float)9.;
#endif /* NO_PROTO */
    return ret_val;
} /* ypos8_ */

