/* fort/04/02/02/02/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b18 = .2f;
#else /* NO_PROTO */
static real c_b18 = (float).2;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.02/10                        * */
/*  *    TEST TITLE : Polymarker bundle index               * */
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
    real r__1;

    /* Local variables */
    static real xa[9], ya[9];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), npl (integer *, real *, real 
	    *), npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), npl (), npm ();
#endif /* NO_PROTO */
    static real mscf;
    static integer undf[3], perm[10];
    static real xloc;
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nsmk ();
#endif /* NO_PROTO */
    static integer szbt, idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1, rdum2;
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
    static real xincr, yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nspmi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpmf (), nspmi ();
#endif /* NO_PROTO */
    static real nomms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspmr (integer *, integer *, integer *, real *
	    , integer *), nopst (integer *), nsvwi (integer *), ndellb (
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspmr (), nopst (), nsvwi (), ndellb ();
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
	    nsmksc (real *), nspmci (integer *), rnperm_(integer *, integer *)
	    ;
#else /* NO_PROTO */
    extern integer rndint_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nqwksl (), 
	    setmsg_(), nsmksc (), nspmci (), rnperm_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* marker type */
/* colour model */
/* colour available */
/* type of returned value */
    initgl_("04.02.02.02/10", 14L);
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
    nqwksl (&dialog_1.specwt, &errind, &idum1, &szbt, &idum2, &idum3, &idum4, 
	    &idum5, &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/* *** *** *** *** polymarker index */
/*  mark start of polymarker bundles */
    nlb (&c__1);
#ifndef NO_PROTO
    setmsg_("3 4 5 6", "A defined polymarker index should cause the addresse"
	    "d entry in the bundle table to be used when rendering a polymark"
	    "er.", 7L, 119L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6", "A defined polymarker index should cause the addresse\
d entry in the bundle table to be used when rendering a polymarker.", 7L, 
	    119L);
#endif /* NO_PROTO */
/*  bundis = # of bundles to be displayed */
    bundis = min(8,szbt);
#ifndef NO_PROTO
    yincr = .8f / bundis;
    yloc = .9f;
#else /* NO_PROTO */
    yincr = (float).8 / bundis;
    yloc = (float).9;
#endif /* NO_PROTO */
    mscf = yincr / 2 / (nomms * dialog_1.wcpdc);
/*  initialize bundis to marker type=3, marker size=YINCR/2, color index=1
 */
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	nspmr (&globnu_1.wkid, &ix, &c__3, &mscf, &c__1);
/* L60: */
    }
/*  bundif = randomly selected bundle, set to */
/*           marker type=2, marker size=2.0, color index = 2 */
    bundif = rndint_(&c__1, &bundis);
#ifndef NO_PROTO
    r__1 = mscf * .5f;
#else /* NO_PROTO */
    r__1 = mscf * (float).5;
#endif /* NO_PROTO */
    nspmr (&globnu_1.wkid, &bundif, &c__2, &r__1, &c__2);
/*  draw and label actual */
#ifndef NO_PROTO
    xa[0] = .425f;
#else /* NO_PROTO */
    xa[0] = (float).425;
#endif /* NO_PROTO */
    numlab_(&bundis, &c_b18, &yloc, &yincr);
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	nspmi (&ix);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L100: */
    }
/*  mark end of marker types */
    nlb (&c__2);
    dchpfv_("DEFINED POLYMARKER INDICES: Which marker is different?", &bundis,
	     &bundif, 54L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 7", "An undefined polymarker index should cause bundle nu"
	    "mber 1 in the polymarker bundle table to be used when rendering "
	    "a polymarker.", 7L, 129L);
    xincr = .125f;
#else /* NO_PROTO */
    setmsg_("3 4 5 7", "An undefined polymarker index should cause bundle nu\
mber 1 in the polymarker bundle table to be used when rendering a polymarker."
	    , 7L, 129L);
    xincr = (float).125;
#endif /* NO_PROTO */
    xloc = xincr;
    mscf = xincr / 2 / (nomms * dialog_1.wcpdc);
/*  draw marker, use individual attributes: */
/*               markertype=4,width=XINCR/2,color=#2 */
/*  set ASFs to INDIVIDAUL */
    setasf_(&c__1);
#ifndef NO_PROTO
    xa[0] = .5f;
    ya[0] = .75f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    ya[0] = (float).75;
#endif /* NO_PROTO */
    nsmk (&c__4);
    nsmksc (&mscf);
    nspmci (&c__2);
    npm (&c__1, xa, ya);
/*  draw line underneath */
#ifndef NO_PROTO
    xa[0] = .1f;
    xa[1] = .9f;
    ya[0] = .625f;
#else /* NO_PROTO */
    xa[0] = (float).1;
    xa[1] = (float).9;
    ya[0] = (float).625;
#endif /* NO_PROTO */
    ya[1] = ya[0];
    npl (&c__2, xa, ya);
/*  reset ASFs to BUNDLED */
    setasf_(&c__0);
/*  set index #1 in bundle table to markertype=4, size=2.0, color index=2 
*/
    nspmr (&globnu_1.wkid, &c__1, &c__4, &mscf, &c__2);
/*  undf1,undf2,undf3 = 3 undefined polymarker indices */
    undf[0] = szbt + 1;
    undf[1] = szbt + 10;
    undf[2] = szbt + 90;
/*  explct = number of explicit markers of bundle #1 = random integer */
/*  from 0 to 4 */
    explct = rndint_(&c__0, &c__4);
    bundis = explct + 3;
    rnperm_(&bundis, perm);
/*  display interleaved: three markers with bundles u1,u2,u3, */
/*    and explct markers with bundle #1 */
#ifndef NO_PROTO
    ya[0] = .5f;
#else /* NO_PROTO */
    ya[0] = (float).5;
#endif /* NO_PROTO */
    i__1 = bundis;
    for (ix = 1; ix <= i__1; ++ix) {
	bunel = perm[ix - 1];
	if (bunel <= 3) {
	    nspmi (&undf[bunel - 1]);
	} else {
	    nspmi (&c__1);
	}
	xa[0] = xloc;
	npm (&c__1, xa, ya);
	xloc += xincr;
/* L500: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED POLYMARKER INDICES: How many of the markers below the"
	    " line have the same attributes as the marker above the line?", &
	    c__12, &bundis, 123L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED POLYMARKER INDICES: How many of the markers below the\
 line have the same attributes as the marker above the line?", &c__12, &
	    bundis, 123L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

