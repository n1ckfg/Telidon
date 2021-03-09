/* drwpmb.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b3 = .2f;
#else /* NO_PROTO */
static real c_b3 = (float).2;
#endif /* NO_PROTO */
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int drwpmb_(integer *numbun, integer *bundis, integer *
	bundif)
#else /* NO_PROTO */
/* Subroutine */ int drwpmb_(numbun, bundis, bundif)
integer *numbun, *bundis, *bundif;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[1], ya[1];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static integer pdci, pdmt;
    static real yloc, pdmw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspmi (integer *), chkinq_(char *, integer *, 
	    ftnlen), numlab_(integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspmi (), chkinq_(), numlab_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nspmci (integer *), 
	    nsmksc (real *), nqppmr (integer *, integer *, integer *, integer 
	    *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nspmci (), nsmksc (), nqppmr ();
#endif /* NO_PROTO */

/*  DRWPMB draws a set of actual polymarkers using the specified bundle */

/*  values, and a set of expected polymarkers, using the attribute */
/*  values returned by <inquire predefined polymarker representation>. */
/*  It draws the expected polymarker incorrectly at the specified */
/*  position. */

/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of polymarker bundle indices to be displayed */
/*    BUNDIF : position of polymarker to be drawn incorrectly */
/* aspect source */
/*                bundled     individual */
/*  draw and label actual; use ASFs bundle */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    setasf_(&c__0);
#ifndef NO_PROTO
    xa[0] = .4f;
    yincr = .8f / *numbun;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).4;
    yincr = (float).8 / *numbun;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(numbun, &c_b3, &yloc, &yincr);
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	nspmi (&bundis[ix]);
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L100: */
    }
/*  now draw expected  results - with individual attributes from WDT */
    setasf_(&c__1);
#ifndef NO_PROTO
    xa[0] = .7f;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).7;
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nqppmr (&dialog_1.specwt, &bundis[ix], &errind, &pdmt, &pdmw, &pdci);
	chkinq_("pqppmr", &errind, 6L);
	if (ix == *bundif) {
	    pdmt = pdmt % 5 + 1;
#ifndef NO_PROTO
	    pdmw *= 1.5f;
#else /* NO_PROTO */
	    pdmw *= (float)1.5;
#endif /* NO_PROTO */
	    pdci = pdci % 5 + 1;
	}
	nsmk (&pdmt);
	nsmksc (&pdmw);
	nspmci (&pdci);
	ya[0] = yloc;
	npm (&c__1, xa, ya);
	yloc -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwpmb_ */

