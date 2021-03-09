/* fort/04/03/02/02/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__6 = 6;
static integer c__801 = 801;
static integer c__1 = 1;
static integer c__102 = 102;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b20 = .3f;
static real c_b22 = .7f;
#else /* NO_PROTO */
static real c_b20 = (float).3;
static real c_b22 = (float).7;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__9 = 9;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/06                        * */
/*  *    TEST TITLE : Colour or monochrome                  * */
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

    static logical newhue[6] = { TRUE_,TRUE_,TRUE_,TRUE_,TRUE_,TRUE_ };

    /* System generated locals */
    logical L__1;

    /* Local variables */
    static real cc[9];
    static integer ix, cola;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nqcf (integer *, integer *, 
	    integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nqcf ();
#endif /* NO_PROTO */
    static real clrs[18]	/* was [3][6] */;
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer ncoli;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd ();
#endif /* NO_PROTO */
    static integer huect;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer colix, opans;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nexst (integer *), nopst (
	    integer *), nsvwi (integer *), dchoic_(char *, integer *, integer 
	    *, integer *, ftnlen), colpch_(logical *, integer *, real *, real 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst (), nopst (), nsvwi (), 
	    dchoic_(), colpch_();
#endif /* NO_PROTO */
    static logical filmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int opfail_(void), chkinq_(char *, integer *, 
	    ftnlen), setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int opfail_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr;
    static real colary[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), nqwksl (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), setmsg_(), 
	    nqwksl ();
    extern logical intsty_();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    extern logical intsty_(integer *, integer *);

#endif /* not NO_PROTO */
/* aspect source */
/*                bundled     individual */
/* colour:        monochrome  colour */
/* interior style */
/* colour model */
/* Red */
#ifndef NO_PROTO
    clrs[0] = 1.f;
    clrs[1] = 0.f;
    clrs[2] = 0.f;
#else /* NO_PROTO */
    clrs[0] = (float)1.;
    clrs[1] = (float)0.;
    clrs[2] = (float)0.;
#endif /* NO_PROTO */
/* Yellow */
#ifndef NO_PROTO
    clrs[3] = 1.f;
    clrs[4] = 1.f;
    clrs[5] = 0.f;
#else /* NO_PROTO */
    clrs[3] = (float)1.;
    clrs[4] = (float)1.;
    clrs[5] = (float)0.;
#endif /* NO_PROTO */
/* Green */
#ifndef NO_PROTO
    clrs[6] = 0.f;
    clrs[7] = 1.f;
    clrs[8] = 0.f;
#else /* NO_PROTO */
    clrs[6] = (float)0.;
    clrs[7] = (float)1.;
    clrs[8] = (float)0.;
#endif /* NO_PROTO */
/* Cyan */
#ifndef NO_PROTO
    clrs[9] = 0.f;
    clrs[10] = 1.f;
    clrs[11] = 1.f;
#else /* NO_PROTO */
    clrs[9] = (float)0.;
    clrs[10] = (float)1.;
    clrs[11] = (float)1.;
#endif /* NO_PROTO */
/* Blue */
#ifndef NO_PROTO
    clrs[12] = 0.f;
    clrs[13] = 0.f;
    clrs[14] = 1.f;
#else /* NO_PROTO */
    clrs[12] = (float)0.;
    clrs[13] = (float)0.;
    clrs[14] = (float)1.;
#endif /* NO_PROTO */
/* Magenta */
#ifndef NO_PROTO
    clrs[15] = 1.f;
    clrs[16] = 0.f;
    clrs[17] = 1.f;
#else /* NO_PROTO */
    clrs[15] = (float)1.;
    clrs[16] = (float)0.;
    clrs[17] = (float)1.;
#endif /* NO_PROTO */
    initgl_("04.03.02.02/06", 14L);
/* open PHIGS */
    xpopph_(&c__6, &globnu_1.memun);
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
    nopst (&c__102);
/*  Set Color Model to RGB */
    nscmd (&globnu_1.wkid, &c__1);
/*  Check to see that color is available */
/*    cola = colour or monochrome */
/*    ncoli = number of colours available */
    nqcf (&dialog_1.specwt, &errind, &idum1, &cola, &idum2, cc);
    chkinq_("pqcf", &errind, 4L);
    if (cola == 1) {
#ifndef NO_PROTO
	setmsg_("4 5 21 22 26 27 33", "A workstation reported as capable of "
		"colour should be able to display more than one hue.", 18L, 
		88L);
#else /* NO_PROTO */
	setmsg_("4 5 21 22 26 27 33", "A workstation reported as capable of \
colour should be able to display more than one hue.", 18L, 88L);
#endif /* NO_PROTO */
    } else if (cola == 0) {
#ifndef NO_PROTO
	setmsg_("4 6 21 22 26 27 33", "A workstation reported as capable of "
		"monochrome should be able to display at most one hue.", 18L, 
		90L);
#else /* NO_PROTO */
	setmsg_("4 6 21 22 26 27 33", "A workstation reported as capable of \
monochrome should be able to display at most one hue.", 18L, 90L);
#endif /* NO_PROTO */
    } else {
	inmsg_("Non-standard code for colour available; skipping test.", 54L);

	goto L666;
    }
/* maximum number of colour bundle table entries */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &ncoli, &idum7);
    chkinq_("pqwksl", &errind, 6L);
    if (ncoli > 2) {
/* Use index #2, unless only 0 and 1 are available: */
	colix = 2;
    } else {
	colix = 1;
    }
/*  Determine how to fill in rectangles, use solid style */
/*  if it is available, otherwise use dense polyline cross-hatch */
    filmod = intsty_(&dialog_1.specwt, &c__1);
/*  *** *** *** ***   Test COLOR Model   *** *** *** *** */
/*  count up distinct hues */
    huect = 0;
    for (ix = 1; ix <= 6; ++ix) {
	colary[0] = clrs[ix * 3 - 3];
	colary[1] = clrs[ix * 3 - 2];
	colary[2] = clrs[ix * 3 - 1];
	nscr (&globnu_1.wkid, &colix, &c__3, colary);
	colpch_(&filmod, &colix, &c_b20, &c_b20, &c_b22, &c_b22);
#ifndef NO_PROTO
	dchoic_("HUE DISCRIMINATION FOR AVAILABLE COLOUR: The color of the s"
		"quare patch is best described as: 1-red, 2-yellow, 3-green, "
		"4-cyan, 5-blue, 6-magenta, 7-white, 8-gray, or 9-black?", &
		c__0, &c__9, &opans, 174L);
#else /* NO_PROTO */
	dchoic_("HUE DISCRIMINATION FOR AVAILABLE COLOUR: The color of the s\
quare patch is best described as: 1-red, 2-yellow, 3-green, 4-cyan, 5-blue, \
6-magenta, 7-white, 8-gray, or 9-black?", &c__0, &c__9, &opans, 174L);
#endif /* NO_PROTO */
/*   opans = operator response */
	if (opans == 0) {
	    opfail_();
	    goto L666;
	} else if (opans < 7) {
	    if (newhue[opans - 1]) {
		++huect;
		if (huect > 1) {
		    goto L210;
		}
		newhue[opans - 1] = FALSE_;
	    }
	} else {
/*           not a hue - do nothing */
	}
/* L110: */
    }
L210:
    if (cola == 1) {
/*  pass/fail depending on (response = expected subset) */
	L__1 = huect > 1;
	ifpf_(&L__1);
    } else {
	L__1 = huect <= 1;
	ifpf_(&L__1);
    }
L666:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

