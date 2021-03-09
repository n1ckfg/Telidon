/* fort/04/02/03/02/p11.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b5 = .03f;
#else /* NO_PROTO */
static real c_b5 = (float).03;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b16 = .7f;
static real c_b17 = .1f;
static real c_b22 = 1.1f;
static real c_b25 = .2f;
static real c_b27 = .4f;
static real c_b39 = .8f;
#else /* NO_PROTO */
static real c_b16 = (float).7;
static real c_b17 = (float).1;
static real c_b22 = (float)1.1;
static real c_b25 = (float).2;
static real c_b27 = (float).4;
static real c_b39 = (float).8;
#endif /* NO_PROTO */
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b44 = .05f;
static real c_b48 = .5f;
static real c_b49 = .9f;
#else /* NO_PROTO */
static real c_b44 = (float).05;
static real c_b48 = (float).5;
static real c_b49 = (float).9;
#endif /* NO_PROTO */
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.02/11                        * */
/*  *    TEST TITLE : Text bundle index                     * */
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

    /* Local variables */
    static real x[2], y[2];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), npl (integer *, real *, real 
	    *), ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), npl (), ntx ();
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
    extern /* Subroutine */ int nscmd (integer *, integer *), nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd (), nschh ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nstxi (integer *), nsvwi (
	    integer *), nstxr (integer *, integer *, integer *, integer *, 
	    real *, real *, integer *), ndellb (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nstxi (), nsvwi (), nstxr (), 
	    ndellb ();
#endif /* NO_PROTO */
    static integer bundif;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), numlab_(
	    integer *, real *, real *, real *), setdlg_(integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, explct;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer bundis;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), nstxal (integer *, integer *), setasf_(integer *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), setmsg_(
	    char *, char *, ftnlen, ftnlen), dchpfv_(char *, integer *, 
	    integer *, ftnlen), rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), nstxal (), setasf_(), 
	    nqwksl (), setmsg_(), dchpfv_(), rnperm_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* colour model */
/* text alignment horizontal */
/* text alignment vertical */
/* text precision */
    initgl_("04.02.03.02/11", 14L);
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
    nschh (&c_b5);
    nstxal (&c__1, &c__3);
/*  use bundled attributes */
    setasf_(&c__0);
/*  szbt = maximum size of bundle table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &szbt, &idum3, &idum4, 
	    &idum5, &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/* *** *** ***   text  index   *** *** *** */
/*  mark start of text bundles */
    nlb (&c__1);
#ifndef NO_PROTO
    setmsg_("3 4 5 6", "A defined text index should cause the addressed entr"
	    "y in the bundle table to be used when rendering a text primitive."
	    , 7L, 117L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6", "A defined text index should cause the addressed entr\
y in the bundle table to be used when rendering a text primitive.", 7L, 117L);

#endif /* NO_PROTO */
/*  bundis = number of bundles to be displayed */
    bundis = min(8,szbt);
/*  initialize bundis to font=1, precision=stroke, expansion=0.7, */
/*     spacing=0.1, color = 1 */
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	nstxr (&globnu_1.wkid, &ix, &c__1, &c__2, &c_b16, &c_b17, &c__1);
/* L60: */
    }
/*  bundif = randomly selected bundle, set to */
/*     font=2, precision=stroke, expansion=1.1, spacing=0.1, color=1 */
    bundif = rndint_(&c__1, &bundis);
    nstxr (&globnu_1.wkid, &bundif, &c__2, &c__2, &c_b22, &c_b17, &c__1);
/*  draw and label actual */
#ifndef NO_PROTO
    yincr = .8f / bundis;
    yloc = .9f;
#else /* NO_PROTO */
    yincr = (float).8 / bundis;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(&bundis, &c_b25, &yloc, &yincr);
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	nstxi (&ix);
	ntx (&c_b27, &yloc, "Phings", 6L);
	yloc -= yincr;
/* L100: */
    }
/*  mark end of linetypes */
    nlb (&c__2);
    dchpfv_("DEFINED TEXT INDICES: Which text primitive is different?", &
	    bundis, &bundif, 56L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 7", "An undefined text index should cause bundle number 1"
	    " in the text bundle table to be used when rendering a text primi"
	    "tive.", 7L, 121L);
#else /* NO_PROTO */
    setmsg_("3 4 5 7", "An undefined text index should cause bundle number 1\
 in the text bundle table to be used when rendering a text primitive.", 7L, 
	    121L);
#endif /* NO_PROTO */
/*  set index #1 in bundle table to: */
/*     font=2, precision=stroke, expansion=0.8, spacing=0.2, color=2 */
    nstxr (&globnu_1.wkid, &c__1, &c__2, &c__2, &c_b39, &c_b25, &c__2);
/*  undf1,undf2,undf3 = 3 undefined text indices */
    undf[0] = szbt + 1;
    undf[1] = szbt + 10;
    undf[2] = szbt + 90;
/*  explct = number of explicit text primitive using bundle #1 = */
/*     random integer from 0 to 4 */
    explct = rndint_(&c__0, &c__4);
    bundis = explct + 3;
    rnperm_(&bundis, perm);
    nschh (&c_b44);
    nstxal (&c__2, &c__4);
/*  draw text with bundle #1 */
    nstxi (&c__1);
    ntx (&c_b48, &c_b49, "Test text", 9L);
#ifndef NO_PROTO
    x[0] = .3f;
    x[1] = .7f;
    y[0] = .8f;
    y[1] = .8f;
#else /* NO_PROTO */
    x[0] = (float).3;
    x[1] = (float).7;
    y[0] = (float).8;
    y[1] = (float).8;
#endif /* NO_PROTO */
    npl (&c__2, x, y);
/*  display interleaved below line: */
/*    three text primitives with bundles u1,u2,u3, */
/*    explct  text primitive with bundle #1 */
#ifndef NO_PROTO
    yloc = .7f;
    yincr = .087499999999999994f;
#else /* NO_PROTO */
    yloc = (float).7;
    yincr = (float).087499999999999994;
#endif /* NO_PROTO */
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	bunel = perm[ix - 1];
	if (bunel <= 3) {
	    nstxi (&undf[bunel - 1]);
	} else {
	    nstxi (&c__1);
	}
	ntx (&c_b48, &yloc, "Test text", 9L);
	yloc -= yincr;
/* L500: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED TEXT INDICES: How many of the text primitives below t"
	    "he line have the same text attributes as the reference text prim"
	    "itive above it?", &c__12, &bundis, 142L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED TEXT INDICES: How many of the text primitives below t\
he line have the same text attributes as the reference text primitive above \
it?", &c__12, &bundis, 142L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

