/* fort/04/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b6 = 0.f;
#else /* NO_PROTO */
static real c_b6 = (float)0.;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__102 = 102;
#ifndef NO_PROTO
static real c_b13 = 1.f;
#else /* NO_PROTO */
static real c_b13 = (float)1.;
#endif /* NO_PROTO */
static integer c__103 = 103;
#ifndef NO_PROTO
static real c_b19 = .1f;
static real c_b20 = .9f;
static real c_b27 = .5f;
#else /* NO_PROTO */
static real c_b19 = (float).1;
static real c_b20 = (float).9;
static real c_b27 = (float).5;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__4 = 4;
static integer c__8 = 8;
static integer c__12 = 12;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01/01                              * */
/*  *    TEST TITLE : 2D polymarker and display space       * */
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
    logical L__1;

    /* Local variables */
    static real xa[20], ya[20];
    static integer ix, jx;
    static real scf, xcm, ycm;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static real xop, yop;
    static integer ran4[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer ran12[12];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real xloc, yloc;
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), nsmk ();
#endif /* NO_PROTO */
    static real xnom[2], ynom[2];
    static integer idum1, idum2, idum3, idum4;
    static real rdum1, rdum2, bside, lside;
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern logical iareq_();
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real rside;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static integer nmark;
    static real tside;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nclst (void), nqdsp (integer *, integer *, integer *, real *, 
	    real *, integer *, integer *), nemst (integer *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int nqpmf (), nclst (), nqdsp (), nemst ();
#endif /* NO_PROTO */
    static real nomms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nsvwi (
	    integer *), opfail_(void), chkinq_(char *, integer *, ftnlen), 
	    setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nsvwi (), opfail_(), 
	    chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, anssiz, anslis[10];
    static real dcmaxx, dcmaxy;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nsmksc (real *), nslwsc (real *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), drwrec_(real *, real *, 
	    real *, real *), drlval_(char *, real *, ftnlen), nspmci (integer 
	    *), rnbset_(integer *, integer *, integer *, integer *), rnperm_(
	    integer *, integer *), dilist_(char *, integer *, integer *, 
	    ftnlen), opmsgw_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nsmksc (), 
	    nslwsc (), setmsg_(), drwrec_(), drlval_(), nspmci (), rnbset_(), 
	    rnperm_(), dilist_(), opmsgw_();
#endif /* NO_PROTO */

/* marker type */
/* aspect source */
/*                bundled     individual */
/*  distance in WC from edge of display space */
    initgl_("04.01/01", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  For all test cases: use individual attributes */
    setasf_(&c__1);
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  set polymarker size to 3.0mm. */
#ifndef NO_PROTO
    scf = .003f / (nomms * dialog_1.mtrpdc);
#else /* NO_PROTO */
    scf = (float).003 / (nomms * dialog_1.mtrpdc);
#endif /* NO_PROTO */
    nsmksc (&scf);
/*  thin lines */
    nslwsc (&c_b6);
/*  set view for entire display space */
    nsvwi (&c__3);
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
#ifndef NO_PROTO
    setmsg_("1", "The location of 2D polymarkers should be determined by the"
	    "ir associated modelling coordinates as modified by the transform"
	    "ation pipeline.", 1L, 137L);
#else /* NO_PROTO */
    setmsg_("1", "The location of 2D polymarkers should be determined by the\
ir associated modelling coordinates as modified by the transformation pipeli\
ne.", 1L, 137L);
#endif /* NO_PROTO */
/*  draw outline of display space using polyline */
    drwrec_(&c_b6, &c_b13, &c_b6, &dialog_1.syxrat);
    nexst (&c__103);
    nclst ();
    nopst (&c__103);
/*  get display space DC-size to derive WC/DC ratio for view #3 */
    nqdsp (&dialog_1.specwt, &errind, &idum1, &dcmaxx, &dcmaxy, &idum2, &
	    idum3);
    chkinq_("pqdsp", &errind, 5L);
/*  WC coordinate of right side of empty display space */
    if (dialog_1.scrmod == 2) {
/*  left edge of dialogue area */
	rside = 1 - dialog_1.dsize;
    } else {
/*  dialogue area not at right */
#ifndef NO_PROTO
	rside = 1.f;
#else /* NO_PROTO */
	rside = (float)1.;
#endif /* NO_PROTO */
    }
/*  WC coordinate of bottom side of empty display space */
    if (dialog_1.scrmod == 1) {
/*  top edge of dialogue area */
	bside = dialog_1.syxrat * dialog_1.dsize;
    } else {
/*  dialogue area not at bottom */
#ifndef NO_PROTO
	bside = 0.f;
#else /* NO_PROTO */
	bside = (float)0.;
#endif /* NO_PROTO */
    }
/*  WC coordinate of left,top side of empty display space */
#ifndef NO_PROTO
    lside = 0.f;
#else /* NO_PROTO */
    lside = (float)0.;
#endif /* NO_PROTO */
    tside = dialog_1.syxrat;
/*  for all 5 polymarker types */
    for (ix = 1; ix <= 5; ++ix) {
/*  random from 0.1 to 0.9 between lside and rside */
	xloc = rndrl_(&c_b19, &c_b20);
	xa[0] = (1 - xloc) * lside + xloc * rside;
/*  random from 0.1 to 0.9 between bside and tside */
	yloc = rndrl_(&c_b19, &c_b20);
	ya[0] = (1 - yloc) * tside + yloc * bside;
/*  draw marker of type ix at xloc,yloc */
	nsmk (&ix);
	npm (&c__1, xa, ya);
#ifndef NO_PROTO
	drlval_("LOCATION OF 2D POLYMARKER: Enter the distance, in centimete"
		"rs, from the left edge of the display space to the center of"
		" the polymarker.", &xop, 135L);
	drlval_("LOCATION OF 2D POLYMARKER: Enter the distance, in centimete"
		"rs, from the top edge of the display space to the center of "
		"the polymarker.", &yop, 134L);
#else /* NO_PROTO */
	drlval_("LOCATION OF 2D POLYMARKER: Enter the distance, in centimete\
rs, from the left edge of the display space to the center of the polymarker.",
		 &xop, 135L);
	drlval_("LOCATION OF 2D POLYMARKER: Enter the distance, in centimete\
rs, from the top edge of the display space to the center of the polymarker.", 
		&yop, 134L);
#endif /* NO_PROTO */
	xcm = dialog_1.mtrpdc * 100 * (xa[0] - lside) * dcmaxx;
	ycm = dialog_1.mtrpdc * 100 * (tside - ya[0]) * dcmaxx;
	nemst (&c__103);
/*  must be within 0.5cm to pass ... */
	if (appeq_(&xop, &xcm, &c_b27, &c_b6) && appeq_(&yop, &ycm, &c_b27, &
		c_b6)) {
/*           OK so far */
	} else {
	    fail_();
	    goto L299;
	}
/*  next ix */
/* L200: */
    }
    pass_();
/*  end_loc: */
L299:
    nclst ();
    nopst (&c__102);
    nemst (&c__102);
/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 2", "All polymarkers drawn within the display space should be"
	    " visible, and all others should not be visible.", 3L, 103L);
#else /* NO_PROTO */
    setmsg_("1 2", "All polymarkers drawn within the display space should be\
 visible, and all others should not be visible.", 3L, 103L);
#endif /* NO_PROTO */
/*  set marker type to asterisk */
    nsmk (&c__3);
/*  try for different color */
    nspmci (&c__2);
/* ran4 = ensure each side has a different number of markers, between 3 an
d 8*/
    rnbset_(&c__4, &c__3, &c__8, ran4);
/*  nominal location of edges */
#ifndef NO_PROTO
    xnom[0] = .004f;
    xnom[1] = .996f;
    ynom[0] = .004f;
    ynom[1] = dialog_1.syxrat - .004f;
#else /* NO_PROTO */
    xnom[0] = (float).004;
    xnom[1] = (float).996;
    ynom[0] = (float).004;
    ynom[1] = dialog_1.syxrat - (float).004;
#endif /* NO_PROTO */
/*  for ix = left,right,bottom,top */
    for (ix = 1; ix <= 4; ++ix) {
/*  randomize 12 locations along each edge */
	rnperm_(&c__12, ran12);
/*  nmark = number of markers to be drawn */
	nmark = ran4[ix - 1];
/*  draw NMARK markers just inside edge #ix at locations ran12(1 : nma
rk), */
/*  and a few more outside */
	for (jx = 1; jx <= 12; ++jx) {
	    if (ix == 1 || ix == 2) {
		xa[jx - 1] = xnom[ix - 1];
#ifndef NO_PROTO
		ya[jx - 1] = dialog_1.syxrat * (ran12[jx - 1] - .5f) / 12.f;
#else /* NO_PROTO */
		ya[jx - 1] = dialog_1.syxrat * (ran12[jx - 1] - (float).5) / (
			float)12.;
#endif /* NO_PROTO */
/*  move to outside, if more than NMARK */
		if (jx > nmark) {
#ifndef NO_PROTO
		    xa[jx - 1] += ((ix << 2) - 6) * .004f;
#else /* NO_PROTO */
		    xa[jx - 1] += ((ix << 2) - 6) * (float).004;
#endif /* NO_PROTO */
		}
	    } else {
		ya[jx - 1] = ynom[ix - 3];
#ifndef NO_PROTO
		xa[jx - 1] = (ran12[jx - 1] - .5f) / 12.f;
#else /* NO_PROTO */
		xa[jx - 1] = (ran12[jx - 1] - (float).5) / (float)12.;
#endif /* NO_PROTO */
/*  move to outside, if more than NMARK */
		if (jx > nmark) {
#ifndef NO_PROTO
		    ya[jx - 1] += ((ix << 2) - 14) * .004f;
#else /* NO_PROTO */
		    ya[jx - 1] += ((ix << 2) - 14) * (float).004;
#endif /* NO_PROTO */
		}
	    }
/* L150: */
	}
	npm (&c__12, xa, ya);
/* L100: */
    }
L110:
#ifndef NO_PROTO
    dilist_("SIZE OF DISPLAY SPACE: Enter four numbers indicating how many m"
	    "arkers are visible along the left, right, bottom, and top edges "
	    "respectively of the entire display space.", &anssiz, anslis, 168L)
	    ;
#else /* NO_PROTO */
    dilist_("SIZE OF DISPLAY SPACE: Enter four numbers indicating how many m\
arkers are visible along the left, right, bottom, and top edges respectively\
 of the entire display space.", &anssiz, anslis, 168L);
#endif /* NO_PROTO */
    if (anssiz == 1 && anslis[0] == 0) {
	opfail_();
    } else if (anssiz == 4) {
	L__1 = iareq_(&c__4, anslis, ran4);
	ifpf_(&L__1);
    } else {
	opmsgw_("List must contain exactly four numbers.", 39L);
	goto L110;
    }
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

