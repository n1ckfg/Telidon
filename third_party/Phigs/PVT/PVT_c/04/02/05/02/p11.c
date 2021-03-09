/* fort/04/02/05/02/p11.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__14 = 14;
#ifndef NO_PROTO
static real c_b9 = .1f;
#else /* NO_PROTO */
static real c_b9 = (float).1;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b30 = .2f;
#else /* NO_PROTO */
static real c_b30 = (float).2;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__3 = 3;
static integer c__40 = 40;
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.02/11                        * */
/*  *    TEST TITLE : Interior bundle index                 * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
#else /* NO_PROTO */
    double cos(), sin();
#endif /* NO_PROTO */

    /* Local variables */
    static real pi, xa[40], ya[40];
    static integer ix;
    static real ang, rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), nlb (integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), nlb ();
#endif /* NO_PROTO */
    static integer siz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer undf[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer perm[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nspa (real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspa ();
#endif /* NO_PROTO */
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsii (integer *), nsep (integer *), nsir (
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsii (), nsep (), nsir ();
#endif /* NO_PROTO */
    static integer szbt, npts[3], idum1, idum2, idum3, idum4, idum5, idum6, 
	    idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer bunel;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
#endif /* NO_PROTO */
    static real centx, yincr, centy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static integer insty;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwi (integer *), ndellb (integer *, integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwi (), ndellb ();
#endif /* NO_PROTO */
    static integer bundif;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedfg (integer *), dchpfv_(char *, integer *,
	     integer *, ftnlen), chkinq_(char *, integer *, ftnlen), numlab_(
	    integer *, real *, real *, real *), setdlg_(integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedfg (), dchpfv_(), chkinq_(), numlab_(), 
	    setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, explct, altsty;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer bundis;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsiasf (integer *, integer *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), setmsg_(
	    char *, char *, ftnlen, ftnlen), setrvs_(char *, real *, integer *
	    , ftnlen), rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsiasf (), 
	    nqwksl (), setmsg_(), setrvs_(), rnperm_();
#endif /* NO_PROTO */
    static integer numsty;

/* aspect source */
/*                bundled     individual */
/* aspect identifier */
/* off/on switch for edge flag and error handling mode */
/* interior style */
/* colour model */
/* colour available */
/* type of returned value */
    initgl_("04.02.05.02/11", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nscmd (&globnu_1.wkid, &c__1);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use bundled attributes, except edge flag (pedfg=14) */
    setasf_(&c__0);
/*  set edge flag off to distinguish between hollow and empty styles */
    nsiasf (&c__14, &c__1);
    nsedfg (&c__0);
    nspa (&c_b9, &c_b9);
/*  szbt = maximum size of bundle table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &szbt, &idum4, 
	    &idum5, &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  <inquire interior facilities> to determine */
/*  altsty = alternative interior style to hollow or empty */
    altsty = 4;
    nqif (&dialog_1.specwt, &c__0, &c__0, &errind, &numsty, &idum1, &idum2, &
	    idum3, &idum4);
    chkinq_("pqif", &errind, 4L);
/*  get an interior style other than HOLLOW and EMPTY */
    i__1 = numsty;
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (&dialog_1.specwt, &ix, &c__0, &errind, &idum1, &insty, &idum2, &
		idum3, &idum4);
	chkinq_("pqif", &errind, 4L);
	if (insty > 0 && insty < 4) {
	    altsty = insty;
	    goto L55;
	}
/* L50: */
    }
L55:
/* *** *** ***   interior index   *** *** *** */
/*  mark start of interior bundles */
    nlb (&c__1);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 7", "A defined interior index should cause the addresse"
	    "d entry in the bundle table to be used when rendering an interio"
	    "r.", 9L, 116L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 7", "A defined interior index should cause the addresse\
d entry in the bundle table to be used when rendering an interior.", 9L, 116L)
	    ;
#endif /* NO_PROTO */
/*  bundis = # of bundles to be displayed */
    bundis = min(8,szbt);
/*  initialize bundis to interior=HOLLOW, style index=1, col index=1 */
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	nsir (&globnu_1.wkid, &ix, &c__0, &c__1, &c__1);
/* L60: */
    }
/*  bundif = randomly selected bundle, set to */
/*           interior style = altsty, style index = 2, color index = 2 */
    bundif = rndint_(&c__1, &bundis);
    nsir (&globnu_1.wkid, &bundif, &altsty, &c__2, &c__2);
/*  draw and label actual */
    setrvs_("0.25, 0.5, 0.5, 0.25", xa, &siz, 20L);
#ifndef NO_PROTO
    yincr = .8f / bundis;
    yloc = .9f;
#else /* NO_PROTO */
    yincr = (float).8 / bundis;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(&bundis, &c_b30, &yloc, &yincr);
    npts[0] = 4;
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .3f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).3;
#endif /* NO_PROTO */
	ya[1] = ya[0];
#ifndef NO_PROTO
	ya[2] = yloc + yincr * .3f;
#else /* NO_PROTO */
	ya[2] = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	ya[3] = ya[2];
	nsii (&ix);
/* switch between fill area and fill area set */
	if (ix % 2 == 0) {
	    nfas (&c__1, npts, xa, ya);
	} else {
	    nfa (&c__4, xa, ya);
	}
	yloc -= yincr;
/* L100: */
    }
/*  mark end of linetypes */
    nlb (&c__2);
    dchpfv_("DEFINED INTERIOR INDICES: Which interior is different?", &bundis,
	     &bundif, 54L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 8", "An undefined interior index should cause bundle nu"
	    "mber 1 in the interior bundle table to be used when rendering an"
	    " interior.", 9L, 124L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 8", "An undefined interior index should cause bundle nu\
mber 1 in the interior bundle table to be used when rendering an interior.", 
	    9L, 124L);
#endif /* NO_PROTO */
/*  set index #1 in bundle table to: */
/*            interior style=altsty, interior index=3, color index=3 */
    nsir (&globnu_1.wkid, &c__1, &altsty, &c__3, &c__3);
/*  undf1,undf2,undf3 = 3 undefined interior indices */
    undf[0] = szbt + 1;
    undf[1] = szbt + 10;
    undf[2] = szbt + 90;
/*  explct = number of explicit interiors of bundle #1 = random integer */

/*  from 0 to 4 */
    explct = rndint_(&c__0, &c__4);
    bundis = explct + 3;
    rnperm_(&bundis, perm);
/*  draw circle with bundle #1 */
#ifndef NO_PROTO
    rad = .125f;
    centx = .5f;
    centy = .75f;
    pi = 3.14159265f;
#else /* NO_PROTO */
    rad = (float).125;
    centx = (float).5;
    centy = (float).75;
    pi = (float)3.14159265;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 40; ++ix) {
	ang = (ix << 1) * pi / 40;
	xa[ix - 1] = centx + rad * cos(ang);
	ya[ix - 1] = centy + rad * sin(ang);
/* L400: */
    }
    nsii (&c__1);
    nfa (&c__40, xa, ya);
/* display interleaved: three rectangular interiors with bundles u1,u2,u3,
*/
/*    and explct interiors with bundle #1 */
    setrvs_("0.25, 0.75, 0.75, 0.25", xa, &siz, 22L);
#ifndef NO_PROTO
    yloc = .5f;
    yincr = .0625f;
#else /* NO_PROTO */
    yloc = (float).5;
    yincr = (float).0625;
#endif /* NO_PROTO */
    npts[0] = 4;
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	bunel = perm[ix - 1];
	if (bunel <= 3) {
	    nsii (&undf[bunel - 1]);
	} else {
	    nsii (&c__1);
	}
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .3f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).3;
#endif /* NO_PROTO */
	ya[1] = ya[0];
#ifndef NO_PROTO
	ya[2] = yloc + yincr * .3f;
#else /* NO_PROTO */
	ya[2] = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	ya[3] = ya[2];
/* switch between fill area and fill area set */
	if (ix % 2 == 0) {
	    nfas (&c__1, npts, xa, ya);
	} else {
	    nfa (&c__4, xa, ya);
	}
	yloc -= yincr;
/* L500: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED INTERIOR INDICES: How many of the rectangular interio"
	    "rs have the same interior attributes (style, style index, and co"
	    "lor) as the circle?", &c__12, &bundis, 146L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED INTERIOR INDICES: How many of the rectangular interio\
rs have the same interior attributes (style, style index, and color) as the \
circle?", &c__12, &bundis, 146L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

