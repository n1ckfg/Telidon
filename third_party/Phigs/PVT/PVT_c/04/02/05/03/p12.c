/* fort//04/02/05/03/p12.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b22 = 1.f;
#else /* NO_PROTO */
static real c_b22 = (float)1.;
#endif /* NO_PROTO */
static integer c__2 = 2;
static doublereal c_b73 = .25;
static integer c__6 = 6;
static integer c__10 = 10;
#ifndef NO_PROTO
static real c_b113 = .25f;
#else /* NO_PROTO */
static real c_b113 = (float).25;
#endif /* NO_PROTO */
static integer c__17 = 17;
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.03/12                        * */
/*  *    TEST TITLE : Appearance of bundled attributes      * */
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
    static char ldescr[14*4] = "solid         " "dashed        " "dotted    "
	    "    " "dashed-dotted ";
#else /* NO_PROTO */
    static char ldescr[14*4+1] = "solid         dashed        dotted        \
dashed-dotted ";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2], i__3, i__4;
    real r__1;
    doublereal d__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    double pow_dd(doublereal *, doublereal *), cos(doublereal), sin(
	    doublereal);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    double pow_dd(), cos(), sin();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[6], ya[6], pi;
    static integer ix;
    static real rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer ldx, cdim, peci;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nfas (integer *, integer *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nfas ();
#endif /* NO_PROTO */
    static integer undf[3], perm[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr ();
#endif /* NO_PROTO */
    static integer txci;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), nscr (integer *, integer *, 
	    integer *, real *), nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nscr (), nsis ();
#endif /* NO_PROTO */
    static char pfsw[1];
    static real mult;
    static integer szbt, npts[1], idum1, idum2, idum3, idum4, idum5, idum6, 
	    idum7;
    static real rdum1, rdum2, rdum3;
    static integer narea, edcol[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpf_(char *, integer *, integer *, integer *
	    , ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpf_();
#endif /* NO_PROTO */
    static integer colel;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqedf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nqeci (integer *, integer *, integer *, integer *, integer *), 
	    endit_(void), nsedi (integer *), nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), nqeci (), endit_(), nsedi (), 
	    nscmd ();
#endif /* NO_PROTO */
    static integer regdx, filon, numci;
    static real minew;
    static integer stddx, numet, impdx, numew, visdx, rtans[20];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static real nomew, maxew, yincr, centx, centy, minlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsvwi (integer *), nsici (
	    integer *), nsedr (integer *, integer *, integer *, integer *, 
	    real *, integer *), inmsg_(char *, ftnlen), rnset_(integer *, 
	    integer *, integer *), dynpf_(char *, char *, ftnlen, ftnlen), 
	    nqplf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsvwi (), nsici (), nsedr (), 
	    inmsg_(), rnset_(), dynpf_(), nqplf ();
#endif /* NO_PROTO */
    static real tstew1, tstew2, bckcol[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *), drbued_(
	    integer *, integer *), nsedci (integer *), chkinq_(char *, 
	    integer *, ftnlen), setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb (), drbued_(), nsedci (), chkinq_(), 
	    setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, thiset, numdis, numpas, szcolt, maxcol, 
	    explct, lavset[10], laviet[600], lavret[10];
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer viscol;
    static real thisew, forcol[6], newcol[6];
    static char prompt[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsiasf (integer *, integer *), 
	    nqwksl (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), rnperm_(
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    dlstpf_(char *, integer *, integer *, char *, ftnlen, ftnlen), 
	    srtiar_(integer *, integer *), lbedty_(integer *, integer *, 
	    integer *, integer *), shedbw_(char *, integer *, real *, real *, 
	    real *, real *, char *, ftnlen, ftnlen), rnbset_(integer *, 
	    integer *, integer *, integer *), nstxci (integer *), numlab_(
	    integer *, real *, real *, real *), dchpfv_(char *, integer *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsiasf (), 
	    nqwksl (), rnperm_(), setmsg_(), dlstpf_(), srtiar_(), lbedty_(), 
	    shedbw_(), rnbset_(), nstxci (), numlab_(), dchpfv_();
#endif /* NO_PROTO */

/* aspect source */
/* type of returned value */
/* interior style */
/* linetype */
/* off/on switch for edge flag and error handling mode */
/* colour model */
/* aspect identifier */
    initgl_("04.02.05.03/12", 14L);
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
/*  set all ASFs to BUNDLED */
    setasf_(&c__0);
/*  set interior style attribute ASFs to INDIVIDUAL */
/*     set interior style = EMPTY, interior color index = 1 */
    nsiasf (&c__11, &c__1);
    nsiasf (&c__13, &c__1);
    nsis (&c__4);
    nsici (&c__1);
/*    numet  = number of available edgetypes */
/*    lavset = list of available standard edgetypes */
/*    lavret = list of available registered edgetypes */
/*    laviet = list of available implementor-defined edgetypes */
/*    numew  = number of available edge-widths */
/*    nomew  = nominal edge-width (DC) */
/*    minew,maxew = minimum,maximum edge-width (DC) */
    nqedf (&dialog_1.specwt, &c__0, &errind, &numet, &idum1, &numew, &nomew, &
	    minew, &maxew, &idum2);
    chkinq_("pqedf", &errind, 5L);
    stddx = 0;
    regdx = 0;
    impdx = 0;
    i__1 = abs(numet);
    for (ldx = 1; ldx <= i__1; ++ldx) {
	nqedf (&dialog_1.specwt, &ldx, &errind, &idum1, &thiset, &idum2, &
		rdum1, &rdum2, &rdum3, &idum3);
	chkinq_("pqedf", &errind, 5L);
	if (thiset > 4) {
	    ++regdx;
	    lavret[regdx - 1] = thiset;
	} else if (thiset >= 1) {
	    ++stddx;
	    lavset[stddx - 1] = thiset;
	} else {
	    if (impdx < 600) {
		if (numet < 0) {
		    ++impdx;
		    laviet[impdx - 1] = -ldx;
		} else {
		    ++impdx;
		    laviet[impdx - 1] = thiset;
		}
	    }
	}
/* L50: */
    }
/*     szbt = size of edge bundle table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &szbt, 
	    &idum5, &idum6, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  *** *** ***   edge flag indicator   *** *** *** */
/*  mark start of edge flag indicator */
    nlb (&c__1);
/*  filon  = number of areas to be drawn with edge flag ON */
    narea = 8;
    filon = rndint_(&c__1, &narea);
/*  set edge representations 1--NAREA */
    i__1 = narea;
    for (ix = 1; ix <= i__1; ++ix) {
	if (ix <= filon) {
	    nsedr (&globnu_1.wkid, &ix, &c__1, &c__1, &c_b22, &c__1);
	} else {
	    nsedr (&globnu_1.wkid, &ix, &c__0, &c__1, &c_b22, &c__1);
	}
/* L60: */
    }
/*  display in random order bundles 1-NAREA */
    rnperm_(&narea, perm);
    drbued_(&narea, perm);
/*  mark end of edge flag indicator */
    nlb (&c__2);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 30 31", "The edge of a polygonal area should be visible"
	    " when the edge flag is ON and not visible when the edge flag is "
	    "OFF.", 13L, 114L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 30 31", "The edge of a polygonal area should be visible\
 when the edge flag is ON and not visible when the edge flag is OFF.", 13L, 
	    114L);
#endif /* NO_PROTO */
    s_copy(prompt, "EDGE FLAG INDICATOR: which triangles have visible edges? "
	    , 200L, 57L);
    i__1 = narea;
    for (ix = 1; ix <= i__1; ++ix) {
	rtans[perm[ix - 1] - 1] = ix;
/* L70: */
    }
    dlstpf_(prompt, &filon, rtans, "S", 200L, 1L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);

/*  *** *** ***   edgetype   *** *** *** */
/*  stddx = size of lavset */
/*  set edge representation 1--stddx */
    i__1 = stddx;
    for (ix = 1; ix <= i__1; ++ix) {
	nsedr (&globnu_1.wkid, &ix, &c__1, &lavset[ix - 1], &c_b22, &c__1);
/* L150: */
    }
/*  Display in random order bundles 1 thru stddx */
    rnperm_(&stddx, perm);
    drbued_(&stddx, perm);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 38 39", "The standard edgetypes should be recognizable "
	    "from their standard description.", 13L, 78L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 38 39", "The standard edgetypes should be recognizable \
from their standard description.", 13L, 78L);
#endif /* NO_PROTO */
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 70, a__1[0] = "STANDARD EDGETYPES: List, in order, the numeric"
	    " labels for edgetypes: ";
#else /* NO_PROTO */
    i__2[0] = 70, a__1[0] = "STANDARD EDGETYPES: List, in order, the numeric\
 labels for edgetypes: ";
#endif /* NO_PROTO */
    i__2[1] = 14, a__1[1] = ldescr + (lavset[0] - 1) * 14;
    s_cat(prompt, a__1, i__2, &c__2, 200L);
    rtans[perm[0] - 1] = 1;
    i__1 = stddx;
    for (ldx = 2; ldx <= i__1; ++ldx) {
	i__3 = itrim_(prompt, 200L);
/* Writing concatenation */
	i__2[0] = 2, a__1[0] = ", ";
	i__2[1] = 14, a__1[1] = ldescr + (lavset[ldx - 1] - 1) * 14;
	s_cat(prompt + i__3, a__1, i__2, &c__2, 200 - i__3);
	rtans[perm[ldx - 1] - 1] = ldx;
/* L170: */
    }
    i__1 = itrim_(prompt, 200L);
    s_copy(prompt + i__1, ".", 200 - i__1, 1L);
    dlstpf_(prompt, &stddx, rtans, "L", 200L, 1L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  regdx = size of lavret */
    if (regdx < 1) {
	inmsg_("No registered edgetypes are supported.", 38L);
	goto L290;
    }
/*  numdis = min(regdx, 8, szbt) */
/*  lindis = numdis entries, randomly chosen from lavret */
/* Computing MIN */
    i__1 = min(regdx,8);
    numdis = min(i__1,szbt);
    rnset_(&numdis, &regdx, perm);
    srtiar_(&numdis, perm);
    srtiar_(&regdx, lavret);
    lbedty_(&globnu_1.wkid, &numdis, perm, lavret);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 38 40", "The registered edgetypes (> 4) should agree wi"
	    "th their registered description.", 13L, 78L);
    dynpf_("REGISTERED EDGETYPES: Is each edgetype depicted according to its"
	    " numeric identifier's specification in the ISO register? ", "Y", 
	    121L, 1L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 38 40", "The registered edgetypes (> 4) should agree wi\
th their registered description.", 13L, 78L);
    dynpf_("REGISTERED EDGETYPES: Is each edgetype depicted according to its\
 numeric identifier's specification in the ISO register? ", "Y", 121L, 1L);
#endif /* NO_PROTO */

/*  neg_type: */
L290:
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  impdx = size of laviet */
    if (impdx < 1) {
	inmsg_("No implementor defined edge types are supported.", 48L);
	goto L390;
    }
/*  numdis = min(impdx, 8, szbt) */
/*  lindis = numdis entries, randomly chosen from laviet */
/* Computing MIN */
    i__1 = min(impdx,8);
    numdis = min(i__1,szbt);
    rnset_(&numdis, &impdx, perm);
    srtiar_(&numdis, perm);
    srtiar_(&impdx, laviet);
    lbedty_(&globnu_1.wkid, &numdis, perm, laviet);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 38 41", "Implementor-defined edgetypes (< 1) should agr"
	    "ee with the descriptions supplied by the implementor.", 13L, 99L);

    dynpf_("IMPLEMENTOR DEFINED EDGETYPES: Is each edgetype depicted accordi"
	    "ng to its numeric identifier's specification in the implementor "
	    "documentation?", "Y", 142L, 1L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 38 41", "Implementor-defined edgetypes (< 1) should agr\
ee with the descriptions supplied by the implementor.", 13L, 99L);
    dynpf_("IMPLEMENTOR DEFINED EDGETYPES: Is each edgetype depicted accordi\
ng to its numeric identifier's specification in the implementor documentatio\
n?", "Y", 142L, 1L);
#endif /* NO_PROTO */
/*  end_edgetype: */
L390:
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  *** *** ***   edge-width   *** *** *** */
/*  Get minimum line width to allow simulation of edge width */
    nqplf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &rdum1, &
	    minlw, &rdum2, &idum4);
    chkinq_("pqplf", &errind, 5L);
/*  Are there at least two visually distinguishable edge-widths? */
#ifndef NO_PROTO
    if (numew == 1 || maxew <= minew * 1.02f || maxew - minew < dialog_1.qvis)
	     {
#else /* NO_PROTO */
    if (numew == 1 || maxew <= minew * (float)1.02 || maxew - minew < 
	    dialog_1.qvis) {
#endif /* NO_PROTO */
	tstew1 = maxew;
	tstew2 = tstew1;
#ifndef NO_PROTO
	mult = 2.f;
#else /* NO_PROTO */
	mult = (float)2.;
#endif /* NO_PROTO */
    } else {
	tstew1 = minew;
	tstew2 = maxew;
	if (numew == 0) {
/*   continuous range of edgewidths available - take 4 geometric s
teps */
	    d__1 = (doublereal) (tstew2 / tstew1);
#ifndef NO_PROTO
	    mult = pow_dd(&d__1, &c_b73) * .9999f;
#else /* NO_PROTO */
	    mult = pow_dd(&d__1, &c_b73) * (float).9999;
#endif /* NO_PROTO */
	} else {
/*   discrete set of edgewidths available - test min/max only */
#ifndef NO_PROTO
	    mult = tstew2 / tstew1 * .9999f;
#else /* NO_PROTO */
	    mult = tstew2 / tstew1 * (float).9999;
#endif /* NO_PROTO */
	}
    }
/*  initialize numpas and thisew */
    numpas = 0;
    thisew = tstew1;
/*  loop thru various edgewidths */
L1000:
/*  test bundle with both requested & expected edge width = thisew */
    shedbw_("VARIOUS EDGEWIDTH SCALE FACTORS", &globnu_1.wkid, &thisew, &
	    thisew, &nomew, &minlw, pfsw, 31L, 1L);
    if (*pfsw == 'A') {
	if (numpas < 2) {
#ifndef NO_PROTO
	    inmsg_("Skipping test case for various scale factors because lar"
		    "gest valid edge width is greater than screen size.", 106L)
		    ;
#else /* NO_PROTO */
	    inmsg_("Skipping test case for various scale factors because lar\
gest valid edge width is greater than screen size.", 106L);
#endif /* NO_PROTO */
	    goto L1110;
	} else {
	    goto L1100;
	}
    } else if (*pfsw != 'P') {
	numpas = 0;
	goto L1100;
    }
    ++numpas;
    thisew *= mult;
    if (thisew <= tstew2) {
	goto L1000;
    }
L1100:
/*  do_test_msg: */
#ifndef NO_PROTO
    setmsg_("3 4 5 6 45 46 47", "Available edgewidth scale factors should co"
	    "ntrol the realized thickness of a edge.", 16L, 82L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 45 46 47", "Available edgewidth scale factors should co\
ntrol the realized thickness of a edge.", 16L, 82L);
#endif /* NO_PROTO */
    L__1 = numpas > 0;
    ifpf_(&L__1);
L1110:
/*  min_max_coerce: */
#ifndef NO_PROTO
    setmsg_("3 4 5 6 45 46 48", "A requested positive edgewidth scale factor"
	    " below the minimum available should be realized as the minimum.", 
	    16L, 106L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 45 46 48", "A requested positive edgewidth scale factor\
 below the minimum available should be realized as the minimum.", 16L, 106L);
#endif /* NO_PROTO */
/*  test bundle with requested edge width = minew/2 */
/*                         expected edge width = minew */
    r__1 = minew / 2;
    shedbw_("POSITIVE EDGEWIDTH BELOW MINIMUM", &globnu_1.wkid, &r__1, &minew,
	     &nomew, &minlw, pfsw, 32L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 45 46 48", "A requested negative edgewidth scale factor"
	    " should be realized as the minimum.", 16L, 78L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 45 46 48", "A requested negative edgewidth scale factor\
 should be realized as the minimum.", 16L, 78L);
#endif /* NO_PROTO */
    r__1 = -(doublereal)maxew - 100;
    shedbw_("NEGATIVE EDGEWIDTH", &globnu_1.wkid, &r__1, &minew, &nomew, &
	    minlw, pfsw, 18L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
/*  to test requested edge width = maxew*2 */
/*  expected edge width = maxew */
    r__1 = maxew * 2;
    shedbw_("POSITIVE EDGEWIDTH ABOVE MAXIMUM", &globnu_1.wkid, &r__1, &maxew,
	     &nomew, &minlw, pfsw, 32L, 1L);
    if (*pfsw == 'A') {
#ifndef NO_PROTO
	inmsg_("Skipping test case for requested scale factor greater than m"
		"aximum because largest valid edge width is greater than scre"
		"en size.", 128L);
#else /* NO_PROTO */
	inmsg_("Skipping test case for requested scale factor greater than m\
aximum because largest valid edge width is greater than screen size.", 128L);
#endif /* NO_PROTO */
    } else {
#ifndef NO_PROTO
	setmsg_("3 4 5 6 45 46 48", "A requested edgewidth scale factor abov"
		"e the maximum available should be realized as the maximum.", 
		16L, 97L);
#else /* NO_PROTO */
	setmsg_("3 4 5 6 45 46 48", "A requested edgewidth scale factor abov\
e the maximum available should be realized as the maximum.", 16L, 97L);
#endif /* NO_PROTO */
	L__1 = *pfsw == 'P';
	ifpf_(&L__1);
    }
/*  *** *** ***   edge color index   *** *** *** */

#ifndef NO_PROTO
    setmsg_("3 4 5 6 49 50 51", "A defined edge color index should cause the"
	    " addressed entry in the color table to be used when rendering a "
	    "edge.", 16L, 112L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 49 50 51", "A defined edge color index should cause the\
 addressed entry in the color table to be used when rendering a edge.", 16L, 
	    112L);
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
/*  numdis = number of edges to be drawn */
/* Computing MIN */
    i__1 = min(8,szcolt);
    numdis = min(i__1,szbt);
/*  edcol  = random permutation of #0,#1, and numdis-2 random choices */
/*           from entries #2 to #szcolt-1 */
    i__1 = numdis - 2;
    i__3 = szcolt - 1;
    rnbset_(&i__1, &c__2, &i__3, edcol);
    edcol[numdis - 2] = 1;
    edcol[numdis - 1] = 0;
    rnperm_(&numdis, perm);
/*  visdx = randomly select an entry from edcol to be made visible */
    i__1 = numdis - 1;
    visdx = rndint_(&c__1, &i__1);
    viscol = edcol[visdx - 1];
/*  ensure dialogue visible */
    dialog_1.dtxci = viscol;
    nsiasf (&c__10, &c__1);
    nstxci (&viscol);
#ifndef NO_PROTO
    yloc = .9f;
    yincr = .8f / (numdis - 1);
    xa[0] = .3f;
    xa[1] = .7f;
    xa[2] = .5f;
    r__1 = yloc + yincr * .3f;
#else /* NO_PROTO */
    yloc = (float).9;
    yincr = (float).8 / (numdis - 1);
    xa[0] = (float).3;
    xa[1] = (float).7;
    xa[2] = (float).5;
    r__1 = yloc + yincr * (float).3;
#endif /* NO_PROTO */
    numlab_(&numdis, &c_b113, &r__1, &yincr);
    npts[0] = 3;
/*  for each color entry, set to background color and draw edges */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	nsedi (&ix);
	ya[0] = yloc;
	ya[1] = yloc;
#ifndef NO_PROTO
	ya[2] = yloc + yincr * .6f;
#else /* NO_PROTO */
	ya[2] = yloc + yincr * (float).6;
#endif /* NO_PROTO */
	nfas (&c__1, npts, xa, ya);
	peci = edcol[perm[ix - 1] - 1];
	nscr (&globnu_1.wkid, &peci, &cdim, bckcol);
	nsedr (&globnu_1.wkid, &ix, &c__1, &c__1, &c_b22, &peci);
	yloc -= yincr;
/* L2110: */
    }
    nscr (&globnu_1.wkid, &viscol, &cdim, forcol);
    dchpf_("DEFINED EDGE COLOR INDICES: which triangle is visible? ", &numdis,
	     &visdx, perm, 55L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);

/*  end_def_col: */

#ifndef NO_PROTO
    setmsg_("3 4 5 6 49 50 52", "An undefined edge color index should cause "
	    "entry number 1 in the color table to be used when rendering an e"
	    "dge.", 16L, 111L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 49 50 52", "An undefined edge color index should cause \
entry number 1 in the color table to be used when rendering an edge.", 16L, 
	    111L);
#endif /* NO_PROTO */
/*  set entry #1 in color table opposite from BCKCOL */
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
/* L2300: */
    }
/*  set entry #1 different from FORCOL - make sure undefined default */
/*  to *current* color-rep of #1, not just a predefined color. */
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
/* L2400: */
    }
/*  explct = number of explicit edges of color #1 = random integer */
/*  from 0 to min(4, szbt-3) */
/* Computing MIN */
    i__3 = 4, i__4 = szbt - 3;
    i__1 = min(i__3,i__4);
    explct = rndint_(&c__0, &i__1);
/*  display in random order bundles #1 thru explct+3 */
    numdis = explct + 3;
    rnperm_(&numdis, perm);
/*  u1,u2,u3 = 3 undefined, positive color indices */
    undf[0] = maxcol + 1;
    undf[1] = maxcol + 10;
    undf[2] = maxcol + 90;
/*  draw star with color #1 */
    nsiasf (&c__17, &c__1);
    nsedci (&c__1);
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
/* L2500: */
    }
    npts[0] = 6;
    nfas (&c__1, npts, xa, ya);
/*  set up bundles 1 thru 3 with undf, 4 thru (explct+3) with #1 */
    setasf_(&c__0);
    nsiasf (&c__11, &c__1);
    nsiasf (&c__13, &c__1);
    nsis (&c__4);
    nsici (&c__1);
    for (ix = 1; ix <= 3; ++ix) {
	nsedr (&globnu_1.wkid, &ix, &c__1, &c__1, &c_b22, &undf[ix - 1]);
/* L2600: */
    }
    i__1 = explct + 3;
    for (ix = 4; ix <= i__1; ++ix) {
	nsedr (&globnu_1.wkid, &ix, &c__1, &c__1, &c_b22, &c__1);
/* L2610: */
    }
#ifndef NO_PROTO
    xa[0] = .3f;
    xa[1] = .7f;
    xa[2] = .7f;
    xa[3] = .3f;
    yloc = .5f;
    yincr = .5f / (numdis + 1);
#else /* NO_PROTO */
    xa[0] = (float).3;
    xa[1] = (float).7;
    xa[2] = (float).7;
    xa[3] = (float).3;
    yloc = (float).5;
    yincr = (float).5 / (numdis + 1);
#endif /* NO_PROTO */
    npts[0] = 4;
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	nsedi (&perm[ix - 1]);
	ya[0] = yloc;
	ya[1] = yloc;
#ifndef NO_PROTO
	ya[2] = yloc - yincr * .5f;
#else /* NO_PROTO */
	ya[2] = yloc - yincr * (float).5;
#endif /* NO_PROTO */
	ya[3] = ya[2];
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L2700: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED EDGE COLOR INDICES: how many rectangles have edges th"
	    "e same color as the star?", &c__12, &numdis, 88L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED EDGE COLOR INDICES: how many rectangles have edges th\
e same color as the star?", &c__12, &numdis, 88L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

