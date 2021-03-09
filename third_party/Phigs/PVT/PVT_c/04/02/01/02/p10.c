/* fort/04/02/01/02/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b12 = 1.f;
#else /* NO_PROTO */
static real c_b12 = (float)1.;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b16 = 2.f;
static real c_b18 = .2f;
#else /* NO_PROTO */
static real c_b16 = (float)2.;
static real c_b18 = (float).2;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__6 = 6;
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.01.02/10                        * */
/*  *    TEST TITLE : Polyline bundle index                 * */
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
    static real pi, xa[9], ya[9];
    static integer ix;
    static real rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), npl (integer *, real *, real 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), npl ();
#endif /* NO_PROTO */
    static integer undf[3], perm[10], txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static integer szbt, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
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
    static real yincr, centx, centy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspli (integer *), nsplr (integer *, integer *
	    , integer *, real *, integer *), nopst (integer *), nsvwi (
	    integer *), ndellb (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspli (), nsplr (), nopst (), nsvwi (), 
	    ndellb ();
#endif /* NO_PROTO */
    static integer bundif;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     chkinq_(char *, integer *, ftnlen), numlab_(integer *, real *, 
	    real *, real *), setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_(), chkinq_(), numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, explct, bundis;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nqwksl (), 
	    setmsg_(), rnperm_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* linetype */
/* colour model */
/* colour available */
/* type of returned value */
    initgl_("04.02.01.02/10", 14L);
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
/*  use bundled attributes */
    setasf_(&c__0);
/*  szbt = maximum size of bundle table */
    nqwksl (&dialog_1.specwt, &errind, &szbt, &idum1, &idum2, &idum3, &idum4, 
	    &idum5, &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/* *** *** *** *** polyline index */
/*  mark start of polyline bundles */
    nlb (&c__1);
#ifndef NO_PROTO
    setmsg_("3 4 5 6", "A defined polyline index should cause the addressed "
	    "entry in the bundle table to be used when rendering a polyline.", 
	    7L, 115L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6", "A defined polyline index should cause the addressed \
entry in the bundle table to be used when rendering a polyline.", 7L, 115L);
#endif /* NO_PROTO */
/*  bundis = # of bundles to be displayed */
    bundis = min(8,szbt);
/*  initialize bundis to linetype=1, linewidth=1.0, color index=1 */
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	nsplr (&globnu_1.wkid, &ix, &c__1, &c_b12, &c__1);
/* L60: */
    }
/*  bundif = randomly selected bundle, set to */
/*           linetype=2, linewidth=2.0, color index = 2 */
    bundif = rndint_(&c__1, &bundis);
    nsplr (&globnu_1.wkid, &bundif, &c__2, &c_b16, &c__2);
/*  draw and label actual */
#ifndef NO_PROTO
    xa[0] = .3f;
    xa[1] = .55f;
    yincr = .8f / bundis;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).3;
    xa[1] = (float).55;
    yincr = (float).8 / bundis;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(&bundis, &c_b18, &yloc, &yincr);
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	ya[1] = yloc;
	nspli (&ix);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L100: */
    }
/*  mark end of linetypes */
    nlb (&c__2);
    dchpfv_("DEFINED POLYLINE INDICES: Which line is different?", &bundis, &
	    bundif, 50L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 7", "An undefined polyline index should cause bundle numb"
	    "er 1 in the polyline bundle table to be used when rendering a po"
	    "lyline.", 7L, 123L);
#else /* NO_PROTO */
    setmsg_("3 4 5 7", "An undefined polyline index should cause bundle numb\
er 1 in the polyline bundle table to be used when rendering a polyline.", 7L, 
	    123L);
#endif /* NO_PROTO */
/*  set index #1 in bundle table to linetype=2, width=2.0, color index=2 
*/
    nsplr (&globnu_1.wkid, &c__1, &c__2, &c_b16, &c__2);
/*  undf1,undf2,undf3 = 3 undefined polyline indices */
    undf[0] = szbt + 1;
    undf[1] = szbt + 10;
    undf[2] = szbt + 90;
/*  explct = number of explicit lines of bundle #1 = random integer */
/*  from 0 to 4 */
    explct = rndint_(&c__0, &c__4);
    bundis = explct + 3;
    rnperm_(&bundis, perm);
/*  draw star with color #1 */
#ifndef NO_PROTO
    rad = .15f;
    centx = .5f;
    centy = .75f;
    pi = 3.14159265f;
#else /* NO_PROTO */
    rad = (float).15;
    centx = (float).5;
    centy = (float).75;
    pi = (float)3.14159265;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 6; ++ix) {
	ya[ix - 1] = centy + rad * cos(pi * 4 * ix / 5);
	xa[ix - 1] = centx + rad * sin(pi * 4 * ix / 5);
/* L400: */
    }
    nspli (&c__1);
    npl (&c__6, xa, ya);
/*  display interleaved: three lines with bundles u1,u2,u3, */
/*    and explct lines with bundle #1 */
#ifndef NO_PROTO
    yloc = .5f;
    yincr = .0625f;
    xa[0] = .1f;
    xa[1] = .9f;
#else /* NO_PROTO */
    yloc = (float).5;
    yincr = (float).0625;
    xa[0] = (float).1;
    xa[1] = (float).9;
#endif /* NO_PROTO */
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	bunel = perm[ix - 1];
	if (bunel <= 3) {
	    nspli (&undf[bunel - 1]);
	} else {
	    nspli (&c__1);
	}
	ya[0] = yloc;
	ya[1] = yloc;
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L500: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED POLYLINE INDICES: How many of the horizontal lines ha"
	    "ve the same attributes as the star?", &c__12, &bundis, 98L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED POLYLINE INDICES: How many of the horizontal lines ha\
ve the same attributes as the star?", &c__12, &bundis, 98L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

