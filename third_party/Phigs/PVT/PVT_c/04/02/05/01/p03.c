/* fort/04/02/05/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__4 = 4;
static integer c__0 = 0;
static integer c__8 = 8;
#ifndef NO_PROTO
static real c_b18 = .2f;
#else /* NO_PROTO */
static real c_b18 = (float).2;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__6 = 6;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b59 = .12f;
#else /* NO_PROTO */
static real c_b59 = (float).12;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b89 = .3f;
static real c_b90 = .9f;
static real c_b110 = .05f;
static real c_b111 = .45f;
#else /* NO_PROTO */
static real c_b89 = (float).3;
static real c_b90 = (float).9;
static real c_b110 = (float).05;
static real c_b111 = (float).45;
#endif /* NO_PROTO */
static doublereal c_b152 = .25;
#ifndef NO_PROTO
static real c_b189 = .25f;
#else /* NO_PROTO */
static real c_b189 = (float).25;
#endif /* NO_PROTO */
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.01/03                        * */
/*  *    TEST TITLE : Appearance of individual edge         * */
/*  *                 attributes                            * */
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
    char ch__1[2725];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double cos(doublereal), sin(doublereal);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    double cos(), sin();
    /* Subroutine */ int s_cat();
    integer s_wsfi(), do_fio(), e_wsfi();
    double pow_dd();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    double pow_dd(doublereal *, doublereal *);

#endif /* not NO_PROTO */
    /* Local variables */
    static real cc[9], xa[9], ya[9];
    static integer ix;
    static real rad;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), nlb (integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), nlb ();
#endif /* NO_PROTO */
    static integer edx;
    static char msg[2600];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer siz, edci, cdim, cola;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nfas (integer *, integer *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nfas ();
#endif /* NO_PROTO */
    static integer undf[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf ();
#endif /* NO_PROTO */
    static integer perm[10];
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
	    integer *, real *), nsln (integer *), nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nscr (), nsln (), nsis ();
#endif /* NO_PROTO */
    static char pfsw[1];
    static real mult;
    static integer npts[1], idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1, rdum2, rdum3;
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
	    endit_(void), nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqedf (), nqeci (), endit_(), nscmd ();
#endif /* NO_PROTO */
    static integer filon;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsici (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsici ();
#endif /* NO_PROTO */
    static integer regdx;
    static char lntid[12];
    static integer numci;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real minew;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedt (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedt ();
#endif /* NO_PROTO */
    static integer impdx;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer stddx, rtans[10], numet;
    static real nomew, maxew;
    static integer numew, visdx;
    static real yincr, centx, centy, minlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *), 
	    dynpf_(char *, char *, ftnlen, ftnlen), nopst (integer *), nqplf (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, real *, integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnset_(), dynpf_(), nopst (), nqplf (), 
	    nsvwi ();
#endif /* NO_PROTO */
    static real tstew1, tstew2, bckcol[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb ();
#endif /* NO_PROTO */
    static integer fascol[20], nfaset, lindis[20], errind, picstr, thiset, 
	    lavset[4], lavret[100], laviet[600], miniet, maxiet, unsudx, 
	    lunsup[10], numdis, szcolt, numfil, numpas, viscol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer maxcol, explct;
    static real thisew, forcol[6], newcol[6];
    static char prompt[200];
    static logical nozero;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *), setasf_(
	    integer *), nsedfg (integer *), chkinq_(char *, integer *, ftnlen)
	    , rnperm_(integer *, integer *), setrvs_(char *, real *, integer *
	    , ftnlen), numlab_(integer *, real *, real *, real *), setmsg_(
	    char *, char *, ftnlen, ftnlen), dlstpf_(char *, integer *, 
	    integer *, char *, ftnlen, ftnlen), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nsedci (integer *), nsplci (integer *), 
	    drwrec_(real *, real *, real *, real *), srtiar_(integer *, 
	    integer *), vislab_(char *, char *, real *, real *, real *, real *
	    , ftnlen, ftnlen), showew_(char *, real *, real *, real *, real *,
	     char *, ftnlen, ftnlen), rnbset_(integer *, integer *, integer *,
	     integer *), nstxci (integer *), dchpfv_(char *, integer *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_(), setasf_(), 
	    nsedfg (), chkinq_(), rnperm_(), setrvs_(), numlab_(), setmsg_(), 
	    dlstpf_(), nqwksl (), nsedci (), nsplci (), drwrec_(), srtiar_(), 
	    vislab_(), showew_(), rnbset_(), nstxci (), dchpfv_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___59 = { 0, lntid, 0, "(A,I2,A)", 12, 1 };
    static icilist io___60 = { 0, lntid, 0, "(A,I5,A)", 12, 1 };
    static icilist io___62 = { 0, msg, 0, "(500I5)", 2600, 1 };


/* aspect source */
/*                bundled     individual */
/* interior style */
/* edge flag indicator */
/* edgetype  (linetype) */
/* type of returned value */
/* colour model */
/* colour available */
    initgl_("04.02.05.01/03", 14L);
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
/*  use individual attributes */
    setasf_(&c__1);
/*  set interior style EMPTY and edge flag ON as default */
    nsis (&c__4);
    nsedfg (&c__1);
/*  use <inquire edge facilities> to determine: */
/*    numet  = number of available edgetypes */
/*    lavset = list of available standard edgetypes */
/*    lavret = list of available registered (>4) edgetypes */
/*    laviet = list of available implementor-defined edgetypes */
/*             (may be derived directly from edgetype value, if */
/*              reported number of edgetypes <0) */
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
    for (edx = 1; edx <= i__1; ++edx) {
	nqedf (&dialog_1.specwt, &edx, &errind, &idum1, &thiset, &idum2, &
		rdum1, &rdum2, &rdum3, &idum3);
	chkinq_("pqedf", &errind, 5L);
	if (thiset > 4) {
	    ++regdx;
	    lavret[regdx - 1] = thiset;
	} else if (thiset > 0) {
	    ++stddx;
	    lavset[stddx - 1] = thiset;
	} else {
	    if (impdx < 600) {
		++impdx;
		if (numet < 0) {
/*  build list from first EDX negative integers */
		    laviet[impdx - 1] = -edx;
		} else {
		    laviet[impdx - 1] = thiset;
		}
	    }
	}
/* L150: */
    }
/*  *** *** *** edge flag indicator */
/*  mark start of edge flag */
    nlb (&c__1);
/* filon = number of rectangles to be drawn with edge flag ON = */
/*         random number 1 - 8 */
/* and 8-filon rectangles to be drawn with edge flag OFF */
    filon = rndint_(&c__1, &c__8);
    rnperm_(&c__8, perm);
    setrvs_("0.3,0.9,0.9,0.3", xa, &siz, 15L);
#ifndef NO_PROTO
    yincr = .10000000000000001f;
    yloc = .85f;
#else /* NO_PROTO */
    yincr = (float).10000000000000001;
    yloc = (float).85;
#endif /* NO_PROTO */
    numlab_(&c__8, &c_b18, &yloc, &yincr);
    npts[0] = 4;
    for (edx = 1; edx <= 8; ++edx) {
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .3f;
	ya[1] = yloc - yincr * .3f;
	ya[2] = yloc + yincr * .3f;
	ya[3] = yloc + yincr * .3f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).3;
	ya[1] = yloc - yincr * (float).3;
	ya[2] = yloc + yincr * (float).3;
	ya[3] = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	rtans[perm[edx - 1] - 1] = edx;
	if (perm[edx - 1] <= filon) {
	    nsedfg (&c__1);
	} else {
	    nsedfg (&c__0);
	}
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L40: */
    }
/*  mark end of edge flag */
    nlb (&c__2);
#ifndef NO_PROTO
    setmsg_("4 32 33 34 35 36", "The edge of a polygonal area should be visi"
	    "ble when the edge flag is on and not visible when the edge flag "
	    "is off.", 16L, 114L);
#else /* NO_PROTO */
    setmsg_("4 32 33 34 35 36", "The edge of a polygonal area should be visi\
ble when the edge flag is on and not visible when the edge flag is off.", 16L,
	     114L);
#endif /* NO_PROTO */
/* Operator must identify the rectangles with visible edges. */
#ifndef NO_PROTO
    s_copy(prompt, "EDGE FLAG INDICATOR: List the numeric labels for all rec"
	    "tangles with visible edges.", 200L, 83L);
#else /* NO_PROTO */
    s_copy(prompt, "EDGE FLAG INDICATOR: List the numeric labels for all rec\
tangles with visible edges.", 200L, 83L);
#endif /* NO_PROTO */
    dlstpf_(prompt, &filon, rtans, "S", 200L, 1L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* edge vs boundary test */
/* <inquire color facilities>, if monochrome skip tests */
    nqcf (&dialog_1.specwt, &errind, &idum1, &cola, &idum2, cc);
    chkinq_("pqcf", &errind, 4L);
/*  szcolt = maximum size of color table (including entry #0) */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &szcolt, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (cola == 0 || szcolt <= 2) {
#ifndef NO_PROTO
	inmsg_("This workstation does not support more than one foreground c"
		"olor; skipping test because edge cannot be distinguished fro"
		"m boundary.", 131L);
#else /* NO_PROTO */
	inmsg_("This workstation does not support more than one foreground c\
olor; skipping test because edge cannot be distinguished from boundary.", 
		131L);
#endif /* NO_PROTO */
	goto L95;
    }
#ifndef NO_PROTO
    setmsg_("4 10 32 34 35 36 37", "The edges of fill area sets should be dr"
	    "awn on top of the interior.", 19L, 67L);
#else /* NO_PROTO */
    setmsg_("4 10 32 34 35 36 37", "The edges of fill area sets should be dr\
awn on top of the interior.", 19L, 67L);
#endif /* NO_PROTO */
/*  bckcol = background color = realized color spec for entry #0 */
/*  forcol = foreground color = realized color spec for entry #1 */
    nqcr (&globnu_1.wkid, &c__0, &c__6, &c__1, &errind, &cdim, bckcol);
    chkinq_("pqcr", &errind, 4L);
    nqcr (&globnu_1.wkid, &c__1, &c__6, &c__1, &errind, &cdim, forcol);
    chkinq_("pqcr", &errind, 4L);
/*  set entry #2 different from BCKCOL and FORCOL */
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
/* L80: */
    }
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
    nscr (&globnu_1.wkid, &c__2, &cdim, newcol);
/* set interior style HOLLOW */
    nsis (&c__0);
/* set edge flag on */
    nsedfg (&c__1);
/* set interior color index = #1 */
    nsici (&c__1);
/* set edge color index = #2 */
    nsedci (&c__2);
/*  draw star with color #2 */
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
/* L60: */
    }
    nsplci (&c__2);
    npl (&c__6, xa, ya);
/* nfaset = number of fill area sets = random number 1-5 */
/* display interleaved: nfaset fill area sets, 6-nfaset fill areas */
    nfaset = rndint_(&c__1, &c__5);
    rnperm_(&c__6, perm);
    setrvs_("0.2,0.8,0.8,0.2", xa, &siz, 15L);
#ifndef NO_PROTO
    yincr = .071428571428571425f;
    yloc = .5f;
#else /* NO_PROTO */
    yincr = (float).071428571428571425;
    yloc = (float).5;
#endif /* NO_PROTO */
    numlab_(&c__6, &c_b59, &yloc, &yincr);
    npts[0] = 4;
    for (ix = 1; ix <= 6; ++ix) {
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .3f;
	ya[1] = yloc - yincr * .3f;
	ya[2] = yloc + yincr * .3f;
	ya[3] = yloc + yincr * .3f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).3;
	ya[1] = yloc - yincr * (float).3;
	ya[2] = yloc + yincr * (float).3;
	ya[3] = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	rtans[perm[ix - 1] - 1] = ix;
	if (perm[ix - 1] <= nfaset) {
	    nfas (&c__1, npts, xa, ya);
	} else {
	    nfa (npts, xa, ya);
	}
	yloc -= yincr;
/* L70: */
    }
#ifndef NO_PROTO
    dlstpf_("EDGE OVERLAYS INTERIOR: List the numeric labels for all rectang"
	    "les whose outermost edges are the same color as the star.", &
	    nfaset, rtans, "S", 120L, 1L);
#else /* NO_PROTO */
    dlstpf_("EDGE OVERLAYS INTERIOR: List the numeric labels for all rectang\
les whose outermost edges are the same color as the star.", &nfaset, rtans, 
	    "S", 120L, 1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
L95:
/*  *** *** ***   edgetype */
/*  Display in random order all edgetypes in lavset */
    rnperm_(&stddx, perm);
    setrvs_("0.3,0.7,0.5", xa, &siz, 11L);
#ifndef NO_PROTO
    yincr = .8f / stddx;
    yloc = .85f;
    r__1 = yloc + .05f;
#else /* NO_PROTO */
    yincr = (float).8 / stddx;
    yloc = (float).85;
    r__1 = yloc + (float).05;
#endif /* NO_PROTO */
    numlab_(&stddx, &c_b18, &r__1, &yincr);
    npts[0] = 3;
    i__1 = stddx;
    for (edx = 1; edx <= i__1; ++edx) {
	ya[0] = yloc;
	ya[1] = yloc;
#ifndef NO_PROTO
	ya[2] = yloc + yincr * .6f;
#else /* NO_PROTO */
	ya[2] = yloc + yincr * (float).6;
#endif /* NO_PROTO */
	nsedt (&lavset[perm[edx - 1] - 1]);
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    setmsg_("4 36 40 41 42 44", "The edgetypes (1-4) should be recognizable "
	    "from their standard description.", 16L, 75L);
#else /* NO_PROTO */
    setmsg_("4 36 40 41 42 44", "The edgetypes (1-4) should be recognizable \
from their standard description.", 16L, 75L);
#endif /* NO_PROTO */
/*  Operator must identify each edgetype according to official */
/*  English description: solid, dotted, dashed, dotted-dashed. */
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
    for (edx = 2; edx <= i__1; ++edx) {
	i__3 = itrim_(prompt, 200L);
/* Writing concatenation */
	i__2[0] = 2, a__1[0] = ", ";
	i__2[1] = 14, a__1[1] = ldescr + (lavset[edx - 1] - 1) * 14;
	s_cat(prompt + i__3, a__1, i__2, &c__2, 200 - i__3);
	rtans[perm[edx - 1] - 1] = edx;
/* L300: */
    }
    i__1 = itrim_(prompt, 200L);
    s_copy(prompt + i__1, ".", 200 - i__1, 1L);
    dlstpf_(prompt, &stddx, rtans, "L", 200L, 1L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/* look for unsupported negative edgetype */
    if (numet > 0) {
/*  find negative edgetype *not* in LAVIET and whether zero */
/*  is supported. */
	nozero = TRUE_;
	miniet = 0;
	i__1 = impdx;
	for (edx = 1; edx <= i__1; ++edx) {
	    if (laviet[edx - 1] == 0) {
		nozero = FALSE_;
	    }
/* Computing MIN */
	    i__3 = miniet, i__4 = laviet[edx - 1];
	    miniet = min(i__3,i__4);
/* L400: */
	}
/*  LUNSUP is list of unsupported edgetypes, indexed by UNSUDX */
	if (nozero) {
	    unsudx = 1;
	    lunsup[unsudx - 1] = 0;
	} else {
	    unsudx = 0;
	}
/*  since this value is less than minimum of LAVIET, it's unsupported 
*/
	++unsudx;
	lunsup[unsudx - 1] = miniet - 1;
    } else {
/* all non-positive edgetypes supported - derived directly from edgety
pe value*/
	unsudx = 0;
    }
/* now look for unsupported positive edgetype */
    maxiet = stddx + 1;
    i__1 = regdx;
    for (edx = 1; edx <= i__1; ++edx) {
/* Computing MAX */
	i__3 = maxiet, i__4 = lavret[edx - 1];
	maxiet = max(i__3,i__4);
/* L500: */
    }
    ++unsudx;
    lunsup[unsudx - 1] = maxiet + 1;
/*  now add to end of LUNSUP entry #1 and a simulated edgetype */
    ++unsudx;
    lunsup[unsudx - 1] = 1;
/*  other = simulate using polylines and linetype PLDOT */
/*  this is the only one that should appear as non-solid */
    ++unsudx;
/*  Display in random order edgetypes in LUNSUP */
    rnperm_(&unsudx, perm);
    setrvs_("0.3,0.9,0.9,0.3", xa, &siz, 15L);
#ifndef NO_PROTO
    yincr = .8f / unsudx;
    yloc = .85f;
    r__1 = yloc + .05f;
#else /* NO_PROTO */
    yincr = (float).8 / unsudx;
    yloc = (float).85;
    r__1 = yloc + (float).05;
#endif /* NO_PROTO */
    numlab_(&unsudx, &c_b18, &r__1, &yincr);
    npts[0] = 4;
    i__1 = unsudx;
    for (edx = 1; edx <= i__1; ++edx) {
	ya[0] = yloc;
	ya[1] = yloc;
	ya[2] = yloc + yincr / 2;
	ya[3] = yloc + yincr / 2;
	if (perm[edx - 1] == unsudx) {
/* simulate rectangle with PLDOT */
	    nsln (&c__3);
	    r__1 = yloc + yincr / 2;
	    drwrec_(&c_b89, &c_b90, &yloc, &r__1);
	} else {
	    nsedt (&lunsup[perm[edx - 1] - 1]);
	    nfas (&c__1, npts, xa, ya);
	}
	yloc -= yincr;
/* L700: */
    }
#ifndef NO_PROTO
    setmsg_("4 36 40 41 42 43 44", "Unavailable edgetypes should be displaye"
	    "d as edgetype number 1.", 19L, 63L);
#else /* NO_PROTO */
    setmsg_("4 36 40 41 42 43 44", "Unavailable edgetypes should be displaye\
d as edgetype number 1.", 19L, 63L);
#endif /* NO_PROTO */
    dchpf_("UNSUPPORTED EDGETYPES: Which rectangle has a non-solid edge?", &
	    unsudx, &unsudx, perm, 60L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  end_solid: */
/*  REGDX = size of lavrlt */
    if (regdx < 1) {
#ifndef NO_PROTO
	inmsg_("No registered edgetypes beyond those defined in the standard"
		" (1-4) are supported.", 81L);
#else /* NO_PROTO */
	inmsg_("No registered edgetypes beyond those defined in the standard\
 (1-4) are supported.", 81L);
#endif /* NO_PROTO */
	goto L890;
    }
/* display and label at most 8 edgetypes in lavrlt */
    numdis = min(8,regdx);
    rnset_(&numdis, &regdx, perm);
/*  build list of edgetypes to be displayed */
    i__1 = numdis;
    for (edx = 1; edx <= i__1; ++edx) {
	lindis[edx - 1] = lavret[perm[edx - 1] - 1];
/* L770: */
    }
/*  and sort it */
    srtiar_(&numdis, lindis);
/*  Display in order (some) edgetypes in LAVRET */
    setrvs_("0.5,0.9,0.7", xa, &siz, 11L);
#ifndef NO_PROTO
    yincr = .8f / numdis;
    yloc = .85f;
#else /* NO_PROTO */
    yincr = (float).8 / numdis;
    yloc = (float).85;
#endif /* NO_PROTO */
    npts[0] = 3;
    i__1 = numdis;
    for (edx = 1; edx <= i__1; ++edx) {
	ya[0] = yloc;
	ya[1] = yloc;
#ifndef NO_PROTO
	ya[2] = yloc + yincr * .6f;
#else /* NO_PROTO */
	ya[2] = yloc + yincr * (float).6;
#endif /* NO_PROTO */
	thiset = lindis[edx - 1];
	s_wsfi(&io___59);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&thiset, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc + yincr * .6f;
#else /* NO_PROTO */
	r__1 = yloc + yincr * (float).6;
#endif /* NO_PROTO */
	vislab_(lntid, "R", &c_b110, &c_b111, &yloc, &r__1, 8L, 1L);
	nsedt (&thiset);
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L800: */
    }
#ifndef NO_PROTO
    setmsg_("4 36 40 41 42 45", "The appearance of the registered edgetypes "
	    "(> 4) should agree with their registered description.", 16L, 96L);

    dynpf_("REGISTERED EDGETYPES: Is each edgetype depicted according to its"
	    " numeric identifier's specification in the ISO register?", "Y", 
	    120L, 1L);
#else /* NO_PROTO */
    setmsg_("4 36 40 41 42 45", "The appearance of the registered edgetypes \
(> 4) should agree with their registered description.", 16L, 96L);
    dynpf_("REGISTERED EDGETYPES: Is each edgetype depicted according to its\
 numeric identifier's specification in the ISO register?", "Y", 120L, 1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  neg_type: */
L890:
/*  IMPDX = size of laviet */
    if (impdx < 1) {
	inmsg_("No implementor-defined edgetypes are supported.", 47L);
	goto L990;
    }
/* display and label at most 8 edgetypes in laviet */
    numdis = min(8,impdx);
    rnset_(&numdis, &impdx, perm);
/*  build list of edgetypes to be displayed */
    i__1 = numdis;
    for (edx = 1; edx <= i__1; ++edx) {
	lindis[edx - 1] = laviet[perm[edx - 1] - 1];
/* L870: */
    }
/*  and sort it */
    srtiar_(&numdis, lindis);
/*  Display (some) edgetypes in LAVIET */
    setrvs_("0.5,0.9,0.7", xa, &siz, 11L);
#ifndef NO_PROTO
    yincr = .8f / numdis;
    yloc = .85f;
#else /* NO_PROTO */
    yincr = (float).8 / numdis;
    yloc = (float).85;
#endif /* NO_PROTO */
    npts[0] = 3;
    i__1 = numdis;
    for (edx = 1; edx <= i__1; ++edx) {
	ya[0] = yloc;
	ya[1] = yloc;
#ifndef NO_PROTO
	ya[2] = yloc + yincr * .6f;
#else /* NO_PROTO */
	ya[2] = yloc + yincr * (float).6;
#endif /* NO_PROTO */
	thiset = lindis[edx - 1];
	s_wsfi(&io___60);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&thiset, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc + yincr * .6f;
#else /* NO_PROTO */
	r__1 = yloc + yincr * (float).6;
#endif /* NO_PROTO */
	vislab_(lntid, "R", &c_b110, &c_b111, &yloc, &r__1, 11L, 1L);
	nsedt (&thiset);
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L900: */
    }
#ifndef NO_PROTO
    setmsg_("4 36 40 41 42 46", "The appearance of the implementor defined e"
	    "dgetypes (< 1) should agree with the descriptions supplied by th"
	    "e implementor.", 16L, 121L);
    dynpf_("IMPLEMENTOR DEFINED EDGETYPES: Is each edgetype depicted accordi"
	    "ng to its numeric identifier's specification in the implementor "
	    "documentation?", "Y", 142L, 1L);
#else /* NO_PROTO */
    setmsg_("4 36 40 41 42 46", "The appearance of the implementor defined e\
dgetypes (< 1) should agree with the descriptions supplied by the implemento\
r.", 16L, 121L);
    dynpf_("IMPLEMENTOR DEFINED EDGETYPES: Is each edgetype depicted accordi\
ng to its numeric identifier's specification in the implementor documentatio\
n?", "Y", 142L, 1L);
#endif /* NO_PROTO */
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
/*  Check if all implementor edgetypes already shown or */
/*  edgetype appearance derived directly from value - if so, skip test */
    if (impdx <= 8 || numet < 0) {
	goto L990;
    }
#ifndef NO_PROTO
    setmsg_("46", "All reported implementor-defined edgetypes available for "
	    "a given workstation type should be documented by the implementor."
	    , 2L, 122L);
#else /* NO_PROTO */
    setmsg_("46", "All reported implementor-defined edgetypes available for \
a given workstation type should be documented by the implementor.", 2L, 122L);

#endif /* NO_PROTO */
    srtiar_(&impdx, laviet);
    s_wsfi(&io___62);
    i__1 = impdx;
    for (edx = 1; edx <= i__1; ++edx) {
	do_fio(&c__1, (char *)&laviet[edx - 1], (ftnlen)sizeof(integer));
    }
    e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 125, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR EDGETYP"
	    "ES: Are all these reportedly available edgetypes documented by t"
	    "he implementor?";
#else /* NO_PROTO */
    i__2[0] = 125, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR EDGETYP\
ES: Are all these reportedly available edgetypes documented by the implement\
or?";
#endif /* NO_PROTO */
    i__2[1] = 2600, a__1[1] = msg;
    s_cat(ch__1, a__1, i__2, &c__2, 2725L);
    dynpf_(ch__1, "Y", 2725L, 1L);
/*  end_edgetype: */
L990:
/*  *** *** ***   edgewidth */
/*  need MINLW to let SHOWEW simulate edge */
    nqplf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &rdum1, &
	    minlw, &rdum2, &idum4);
    chkinq_("pqplf", &errind, 5L);
/*  Are there at least two visually distinguishable line-widths? */
#ifndef NO_PROTO
    if (numew == 1 || maxew <= minew * 1.02f || maxew - minew < dialog_1.qvis)
	     {
#else /* NO_PROTO */
    if (numew == 1 || maxew <= minew * (float)1.02 || maxew - minew < 
	    dialog_1.qvis) {
#endif /* NO_PROTO */
	tstew1 = maxew;
	tstew2 = maxew;
#ifndef NO_PROTO
	mult = 2.f;
#else /* NO_PROTO */
	mult = (float)2.;
#endif /* NO_PROTO */
    } else {
	tstew1 = minew;
	tstew2 = maxew;
	if (numew == 0) {
/*  continuous range of edgewidths available - take 4 geometric st
eps */
	    d__1 = (doublereal) (tstew2 / tstew1);
#ifndef NO_PROTO
	    mult = pow_dd(&d__1, &c_b152) * .9999f;
#else /* NO_PROTO */
	    mult = pow_dd(&d__1, &c_b152) * (float).9999;
#endif /* NO_PROTO */
	} else {
/*  discrete set of edgewidths available - test min/max only */
#ifndef NO_PROTO
	    mult = tstew2 / tstew1 * .9999f;
#else /* NO_PROTO */
	    mult = tstew2 / tstew1 * (float).9999;
#endif /* NO_PROTO */
	}
    }
/* test scale sizes */
/* set up counter for number of sizes passed */
    numpas = 0;
    thisew = tstew1;
/*  loop thru various edgewidths/next_ew: */
L1000:
/*  invoke SHOWEW subroutine to test requested edge width = thisew */
/*                                    expected edge width = thisew */
    showew_("VARIOUS EDGEWIDTH SCALE FACTORS", &thisew, &thisew, &nomew, &
	    minlw, pfsw, 31L, 1L);
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
/*  if PFSW = 'P', set up for next edgewidth to be tested: */
    ++numpas;
    thisew *= mult;
    if (thisew <= tstew2) {
	goto L1000;
    }
L1100:
#ifndef NO_PROTO
    setmsg_("4 36 49 50 51", "Available edgewidth scale factors should contr"
	    "ol the realized thickness of an edge.", 13L, 83L);
#else /* NO_PROTO */
    setmsg_("4 36 49 50 51", "Available edgewidth scale factors should contr\
ol the realized thickness of an edge.", 13L, 83L);
#endif /* NO_PROTO */
    L__1 = numpas > 0;
    ifpf_(&L__1);
/*  min_max_coerce: */
L1110:
#ifndef NO_PROTO
    setmsg_("4 36 49 50 52", "A requested positive edgewidth scale factor be"
	    "low the minimum available should be realized as the minimum.", 
	    13L, 106L);
#else /* NO_PROTO */
    setmsg_("4 36 49 50 52", "A requested positive edgewidth scale factor be\
low the minimum available should be realized as the minimum.", 13L, 106L);
#endif /* NO_PROTO */
    r__1 = minew / 2;
    showew_("POSITIVE EDGEWIDTH BELOW MINIMUM", &r__1, &minew, &nomew, &minlw,
	     pfsw, 32L, 1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4 36 49 50 52", "A requested negative edgewidth scale factor sh"
	    "ould be realized as the minimum.", 13L, 78L);
#else /* NO_PROTO */
    setmsg_("4 36 49 50 52", "A requested negative edgewidth scale factor sh\
ould be realized as the minimum.", 13L, 78L);
#endif /* NO_PROTO */
    r__1 = -(doublereal)maxew - 100;
    showew_("NEGATIVE EDGEWIDTH", &r__1, &minew, &nomew, &minlw, pfsw, 18L, 
	    1L);
    L__1 = *pfsw == 'P';
    ifpf_(&L__1);
/* test edge width scale above maximum = maximum */
    r__1 = maxew * 2;
    showew_("POSITIVE EDGEWIDTH ABOVE MAXIMUM", &r__1, &maxew, &nomew, &minlw,
	     pfsw, 32L, 1L);
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
	setmsg_("4 36 49 50 52", "A requested edgewidth scale factor above t"
		"he maximum available should be realized as the maximum.", 13L,
		 97L);
#else /* NO_PROTO */
	setmsg_("4 36 49 50 52", "A requested edgewidth scale factor above t\
he maximum available should be realized as the maximum.", 13L, 97L);
#endif /* NO_PROTO */
	L__1 = *pfsw == 'P';
	ifpf_(&L__1);
    }
/*  *** *** ***   edge color index */
#ifndef NO_PROTO
    setmsg_("4 36 55 56 57", "A defined edge color index should cause the ad"
	    "dressed entry in the color table to be used when rendering the e"
	    "dge of a polygonal area.", 13L, 134L);
#else /* NO_PROTO */
    setmsg_("4 36 55 56 57", "A defined edge color index should cause the ad\
dressed entry in the color table to be used when rendering the edge of a pol\
ygonal area.", 13L, 134L);
#endif /* NO_PROTO */
/*  bckcol = background color = realized color spec for entry #0 */
/*  forcol = foreground color = realized color spec for entry #1 */
    nqcr (&globnu_1.wkid, &c__0, &c__6, &c__1, &errind, &cdim, bckcol);
    chkinq_("pqcr", &errind, 4L);
    nqcr (&globnu_1.wkid, &c__1, &c__6, &c__1, &errind, &cdim, forcol);
    chkinq_("pqcr", &errind, 4L);
/*  how many fill areas to draw */
    numfil = min(8,szcolt);
/*  from values 2 to SZCOLT-1, pick NUMFIL-2 entries */
    i__1 = numfil - 2;
    i__3 = szcolt - 1;
    rnbset_(&i__1, &c__2, &i__3, fascol);
/*  add in 0 and 1 */
    fascol[numfil - 2] = 1;
    fascol[numfil - 1] = 0;
    rnperm_(&numfil, perm);
/*  from fascol, randomly select entry #visdx, but not the one that */
/*    contains 0, since this may not be re-settable. */
    i__1 = numfil - 1;
    visdx = rndint_(&c__1, &i__1);
    viscol = fascol[visdx - 1];
/*  ensure dialogue visible */
    dialog_1.dtxci = viscol;
    nstxci (&viscol);
#ifndef NO_PROTO
    yloc = .9f;
    yincr = .8f / (numfil - 1);
#else /* NO_PROTO */
    yloc = (float).9;
    yincr = (float).8 / (numfil - 1);
#endif /* NO_PROTO */
    setrvs_("0.3,0.7,0.5", xa, &siz, 11L);
#ifndef NO_PROTO
    r__1 = yloc + yincr * .3f;
#else /* NO_PROTO */
    r__1 = yloc + yincr * (float).3;
#endif /* NO_PROTO */
    numlab_(&numfil, &c_b189, &r__1, &yincr);
    npts[0] = 3;
/*  for each color entry - set to background color and draw line */
    i__1 = numfil;
    for (ix = 1; ix <= i__1; ++ix) {
	edci = fascol[perm[ix - 1] - 1];
	nscr (&globnu_1.wkid, &edci, &cdim, bckcol);
	nsedci (&edci);
	ya[0] = yloc;
	ya[1] = yloc;
#ifndef NO_PROTO
	ya[2] = yloc + yincr * .6f;
#else /* NO_PROTO */
	ya[2] = yloc + yincr * (float).6;
#endif /* NO_PROTO */
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L2100: */
    }
    nscr (&globnu_1.wkid, &viscol, &cdim, forcol);
    dchpf_("DEFINED EDGE COLOR INDICES: Which triangle is visible?", &numfil, 
	    &visdx, perm, 54L);
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("4 36 55 56 58", "An undefined edge color index should cause ent"
	    "ry number 1 in the color table to be used when rendering the edg"
	    "e of a polygonal area.", 13L, 132L);
#else /* NO_PROTO */
    setmsg_("4 36 55 56 58", "An undefined edge color index should cause ent\
ry number 1 in the color table to be used when rendering the edge of a polyg\
onal area.", 13L, 132L);
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
/*  set entry #1 different from FORCOL - make sure other default */
/*  is to current color-rep of #1, not just a predefined color. */
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
/* explct = number of explicit fill area sets of color #1 = random integer
*/
/*  from 0 to 4 */
    explct = rndint_(&c__0, &c__4);
    numfil = explct + 3;
    rnperm_(&numfil, perm);
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
/*    three fill area sets of color u1,u2,u3, */
/*    explct fill area sets of color #1 */
#ifndef NO_PROTO
    yloc = .5f;
    yincr = .0625f;
#else /* NO_PROTO */
    yloc = (float).5;
    yincr = (float).0625;
#endif /* NO_PROTO */
    setrvs_("0.3,0.7,0.7,0.3", xa, &siz, 15L);
    npts[0] = 4;
/*  for each color entry - set to background color and draw fill area set 
*/
    i__1 = numfil;
    for (ix = 1; ix <= i__1; ++ix) {
	colel = perm[ix - 1];
	if (colel <= 3) {
	    nsedci (&undf[colel - 1]);
	} else {
	    nsedci (&c__1);
	}
	ya[0] = yloc;
	ya[1] = yloc;
	ya[2] = yloc + yincr / 3;
	ya[3] = yloc + yincr / 3;
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L2300: */
    }
#ifndef NO_PROTO
    dchpfv_("UNDEFINED EDGE COLOR INDICES: How many rectangles are the same "
	    "color as the star?", &c__12, &numfil, 81L);
#else /* NO_PROTO */
    dchpfv_("UNDEFINED EDGE COLOR INDICES: How many rectangles are the same \
color as the star?", &c__12, &numfil, 81L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

