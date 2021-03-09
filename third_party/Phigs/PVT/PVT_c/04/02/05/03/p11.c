/* fort//04/02/05/03/p11.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__11 = 11;
static integer c__13 = 13;
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b23 = 1.f;
static real c_b26 = 2.f;
#else /* NO_PROTO */
static real c_b23 = (float)1.;
static real c_b26 = (float)2.;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/11                        * */
/*  *    TEST TITLE : Edge bundle index                     * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
#else /* NO_PROTO */
    double cos(), sin();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[41], ya[41], pi;
    static integer ix;
    static real rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer laet[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer undf[3], perm[10], txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nsis ();
#endif /* NO_PROTO */
    static integer szbt, npts[1], idum1, idum2, idum3, idum4, idum5, idum6, 
	    idum7;
    static real rdum1, rdum2, rdum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), endit_(void), nsedi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), endit_(), nsedi ();
#endif /* NO_PROTO */
    static integer bunel;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
#endif /* NO_PROTO */
    static integer altet;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsici (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsici ();
#endif /* NO_PROTO */
    static integer maxet;
    static real yincr, centx, centy;
    static integer numet;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedr (integer *, integer *, integer *, 
	    integer *, real *, integer *), nopst (integer *), nsvwi (integer *
	    ), ndellb (integer *, integer *), drbued_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedr (), nopst (), nsvwi (), ndellb (), 
	    drbued_();
#endif /* NO_PROTO */
    static integer bundif;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     chkinq_(char *, integer *, ftnlen), setdlg_(integer *, integer *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer switch__, numbun, bundis[10], explct;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsiasf (integer *, integer *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), srtiar_(
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsiasf (), 
	    nqwksl (), srtiar_(), setmsg_(), rnperm_();
#endif /* NO_PROTO */

/* aspect source */
/* interior style */
/* off/on switch for edge flag and error handling mode */
/* colour model */
/* aspect identifier */
    initgl_("04.02.05.03/11", 14L);
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
/*  set interior style attribute ASFs to INDIVIDUAL */
/*  set interior style = EMPTY, interior color index = 1 */
    nsiasf (&c__11, &c__1);
    nsiasf (&c__13, &c__1);
    nsis (&c__4);
    nsici (&c__1);
/*  szbt   = maximum size of edge bundle table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &szbt, 
	    &idum5, &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  numet = number of available edgetypes */
/*  laet  = list of available edgetypes */
    nqedf (&dialog_1.specwt, &c__0, &errind, &numet, &idum1, &idum2, &rdum1, &
	    rdum2, &rdum3, &idum3);
    chkinq_("pqedf", &errind, 5L);
/*  ten is more than enough - limit to list size */
/* Computing MIN */
    i__1 = 10, i__2 = abs(numet);
    maxet = min(i__1,i__2);
    i__1 = maxet;
    for (ix = 1; ix <= i__1; ++ix) {
	nqedf (&dialog_1.specwt, &ix, &errind, &idum1, &laet[ix - 1], &idum2, 
		&rdum1, &rdum2, &rdum3, &idum3);
	chkinq_("pqedf", &errind, 5L);
/* L50: */
    }
/*  sort laet */
    srtiar_(&maxet, laet);
/*  *** *** ***   edge index   *** *** *** */
/*  mark start of edge bundles */
    nlb (&c__1);
#ifndef NO_PROTO
    setmsg_("3 4 5 6", "A defined edge index should cause the addressed entr"
	    "y in the bundle table to be used when rendering a edge.", 7L, 
	    107L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6", "A defined edge index should cause the addressed entr\
y in the bundle table to be used when rendering a edge.", 7L, 107L);
#endif /* NO_PROTO */
/*  numbun = number of bundles to be displayed = min(8, szbt) */
    numbun = min(8,szbt);
/*  initialize all of bundis */
    i__1 = numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nsedr (&globnu_1.wkid, &ix, &c__1, &c__1, &c_b23, &c__1);
	bundis[ix - 1] = ix;
/* L60: */
    }
/*  altet  = alternative edgetype */
/*  switch = switch edge flag ON or OFF */
    if (maxet > 1) {
	altet = laet[1];
	switch__ = 1;
    } else {
	altet = laet[0];
	switch__ = 0;
    }
/*  bundif = randomly selected bundle from BUNDIS */
    bundif = rndint_(&c__1, &numbun);
/*  set edge represent bundif */
    nsedr (&globnu_1.wkid, &bundif, &switch__, &altet, &c_b26, &c__2);
/*  Display and label triangles with edges for each bundle in bundis */
    drbued_(&numbun, bundis);
/*  mark end of edgetype */
    nlb (&c__2);
    dchpfv_("DEFINED EDGE INDICES: which triangle is different?", &numbun, &
	    bundif, 50L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 7", "An undefined edge index should cause bundle number 1"
	    " in the edge bundle table to be used when rendering an edge.", 7L,
	     112L);
#else /* NO_PROTO */
    setmsg_("3 4 5 7", "An undefined edge index should cause bundle number 1\
 in the edge bundle table to be used when rendering an edge.", 7L, 112L);
#endif /* NO_PROTO */
/*  set index #1 in bundle table */
    nsedr (&globnu_1.wkid, &c__1, &c__1, &altet, &c_b26, &c__2);
/*  u1,u2,u3 = 3 undefined, positive indices */
    undf[0] = szbt + 1;
    undf[1] = szbt + 10;
    undf[2] = szbt + 90;
/*  explct = number of explicit edges */
    explct = rndint_(&c__0, &c__4);
    numbun = explct + 3;
    rnperm_(&numbun, perm);
/*  draw star with bundle index 1 */
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
    for (ix = 1; ix <= 5; ++ix) {
	ya[ix - 1] = centy + rad * cos(pi * 4 * ix / 5);
	xa[ix - 1] = centx + rad * sin(pi * 4 * ix / 5);
/* L400: */
    }
    nsedi (&c__1);
    npts[0] = 5;
    nfas (&c__1, npts, xa, ya);
/*  display interleaved: */
#ifndef NO_PROTO
    yloc = .5f;
    yincr = .0625f;
    xa[0] = .3f;
    xa[1] = .3f;
    xa[2] = .7f;
#else /* NO_PROTO */
    yloc = (float).5;
    yincr = (float).0625;
    xa[0] = (float).3;
    xa[1] = (float).3;
    xa[2] = (float).7;
#endif /* NO_PROTO */
    npts[0] = 3;
    i__1 = numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	bunel = perm[ix - 1];
	if (bunel <= 3) {
	    nsedi (&undf[bunel - 1]);
	} else {
	    nsedi (&c__1);
	}
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .25f;
	ya[1] = yloc + yincr * .25f;
	ya[2] = yloc - yincr * .25f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).25;
	ya[1] = yloc + yincr * (float).25;
	ya[2] = yloc - yincr * (float).25;
#endif /* NO_PROTO */
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L500: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED EDGE INDICES: How many of the triangles have the same"
	    " edge attributes as the star?", &c__12, &numbun, 92L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED EDGE INDICES: How many of the triangles have the same\
 edge attributes as the star?", &c__12, &numbun, 92L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

