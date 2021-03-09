/* fort/04/03/02/02/p09.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__6 = 6;
static integer c__9 = 9;
static integer c__0 = 0;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b19 = .1f;
static real c_b20 = 0.f;
#else /* NO_PROTO */
static real c_b19 = (float).1;
static real c_b20 = (float)0.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/09                        * */
/*  *    TEST TITLE : Background colour                     * */
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
    static real rgbval[27]	/* was [3][9] */ = { 0.f,0.f,0.f,0.f,0.f,1.f,
	    0.f,1.f,1.f,.5f,.5f,.5f,0.f,1.f,0.f,1.f,0.f,1.f,1.f,0.f,0.f,1.f,
	    1.f,1.f,1.f,1.f,0.f };
#else /* NO_PROTO */
    static real rgbval[27]	/* was [3][9] */ = { (float)0.,(float)0.,(
	    float)0.,(float)0.,(float)0.,(float)1.,(float)0.,(float)1.,(float)
	    1.,(float).5,(float).5,(float).5,(float)0.,(float)1.,(float)0.,(
	    float)1.,(float)0.,(float)1.,(float)1.,(float)0.,(float)0.,(float)
	    1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)0. };
#endif /* NO_PROTO */

    static integer ix, siz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nqcr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nqcr ();
#endif /* NO_PROTO */
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr ();
#endif /* NO_PROTO */
    static real real0[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nscmd (integer *, integer *), 
	    inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nscmd (), inmsg_();
#endif /* NO_PROTO */
    static integer color, numcl, opans;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
#endif /* NO_PROTO */
    static integer count;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *), 
	    nexst (integer *), nopst (integer *), nsvwi (integer *), dchoic_(
	    char *, integer *, integer *, integer *, ftnlen);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnset_(), nexst (), nopst (), nsvwi (), 
	    dchoic_();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static logical passed;
#ifndef NO_PROTO
    extern logical coleql_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical coleql_();
#endif /* NO_PROTO */
    static integer errind, picstr, realiz, liscol[6];
    static real colary[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_();
#endif /* NO_PROTO */
    static integer listst[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), chkinq_(char *, integer *,
	     ftnlen), setrvs_(char *, real *, integer *, ftnlen), opcofl_(
	    void), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), chkinq_(), setrvs_(), opcofl_(), 
	    setmsg_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* colour model */
/* type of returned values = set, realized */
/* number to be tested, and size of palette */
/*                    black     blue       cyan      gray */
/*                    green     magenta    red       white */
/*                    yellow */
    initgl_("04.03.02.02/09", 14L);
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
    nexst (&c__102);
    nclst ();
/*  Set Color Model = RGB */
    nscmd (&globnu_1.wkid, &c__1);
    nopst (&c__102);
/*  List of colors to be tested - do so in random order */
    rnset_(&c__6, &c__9, liscol);
/*  all tests passed so far */
    passed = TRUE_;
/*  List of colors tested so far = empty */
    count = 0;
    for (color = 1; color <= 6; ++color) {
	colary[0] = rgbval[liscol[color - 1] * 3 - 3];
	colary[1] = rgbval[liscol[color - 1] * 3 - 2];
	colary[2] = rgbval[liscol[color - 1] * 3 - 1];
	nscr (&globnu_1.wkid, &c__0, &c__3, colary);
	nqcr (&globnu_1.wkid, &c__0, &c__3, &c__1, &errind, &numcl, real0);
	chkinq_("pqcr", &errind, 4L);
/*  look for realized color - is it near a named color?? */
	for (ix = 1; ix <= 9; ++ix) {
	    if (coleql_(&c__3, real0, &rgbval[ix * 3 - 3], &c_b19, &c_b20)) {
/*  Found the realized color */
		realiz = ix;
		goto L220;
	    }
/* L210: */
	}
/*  if realized color not near a named color, skip this color */
	goto L120;
L220:
/*  if realized color already tested, skip this color */
	if (iarfnd_(&realiz, &count, listst) > 0) {
	    goto L120;
	}
/*  new color - add to list of tested colors */
	++count;
	listst[count - 1] = realiz;
/*  Set colour representation for #1 opposite from #0 */
	setrvs_("0,0,0", colary, &siz, 5L);
#ifndef NO_PROTO
	if (real0[0] < .5f) {
	    colary[0] = 1.f;
#else /* NO_PROTO */
	if (real0[0] < (float).5) {
	    colary[0] = (float)1.;
#endif /* NO_PROTO */
	}
#ifndef NO_PROTO
	if (real0[1] < .5f) {
	    colary[1] = 1.f;
#else /* NO_PROTO */
	if (real0[1] < (float).5) {
	    colary[1] = (float)1.;
#endif /* NO_PROTO */
	}
#ifndef NO_PROTO
	if (real0[2] < .5f) {
	    colary[2] = 1.f;
#else /* NO_PROTO */
	if (real0[2] < (float).5) {
	    colary[2] = (float)1.;
#endif /* NO_PROTO */
	}
	nscr (&globnu_1.wkid, &c__1, &c__3, colary);
#ifndef NO_PROTO
	dchoic_("BACKGROUND COLOUR: The color of the background is best desc"
		"ribed as: 1-black, 2-blue, 3-cyan, 4-gray, 5-green, 6-magent"
		"a, 7-red, 8-white, 9-yellow?", &c__0, &c__9, &opans, 147L);
#else /* NO_PROTO */
	dchoic_("BACKGROUND COLOUR: The color of the background is best desc\
ribed as: 1-black, 2-blue, 3-cyan, 4-gray, 5-green, 6-magenta, 7-red, 8-whit\
e, 9-yellow?", &c__0, &c__9, &opans, 147L);
#endif /* NO_PROTO */
	if (opans == realiz) {
/*           OK so far */
	} else {
	    if (opans == 0) {
		opcofl_();
	    }
	    passed = FALSE_;
	    goto L130;
	}
/*  next color */
L120:
	;
    }
L130:
    if (count == 0) {
#ifndef NO_PROTO
	inmsg_("Cannot find nameable realized color for background; skipping"
		" test.", 66L);
#else /* NO_PROTO */
	inmsg_("Cannot find nameable realized color for background; skipping\
 test.", 66L);
#endif /* NO_PROTO */
    } else {
#ifndef NO_PROTO
	setmsg_("21 22 30 32", "The background colour should correspond to e"
		"ntry #0 in the colour table.", 11L, 72L);
#else /* NO_PROTO */
	setmsg_("21 22 30 32", "The background colour should correspond to e\
ntry #0 in the colour table.", 11L, 72L);
#endif /* NO_PROTO */
	ifpf_(&passed);
    }
/* L140: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

