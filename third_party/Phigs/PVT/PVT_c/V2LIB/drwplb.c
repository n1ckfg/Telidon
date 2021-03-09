/* drwplb.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int drwplb_(integer *numbun, integer *bundis, integer *
	bundif)
#else /* NO_PROTO */
/* Subroutine */ int drwplb_(numbun, bundis, bundif)
integer *numbun, *bundis, *bundif;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[2], ya[2];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer pdci, pdlt;
    static real yloc, pdlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspli (integer *), chkinq_(char *, integer *, 
	    ftnlen), numlab_(integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspli (), chkinq_(), numlab_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nsplci (integer *), 
	    nslwsc (real *), nqpplr (integer *, integer *, integer *, integer 
	    *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nsplci (), nslwsc (), nqpplr ();
#endif /* NO_PROTO */

/*  DRWPLB draws a set of actual polylines using the specified bundle */
/*  values, and a set of expected polylines, using the attribute */
/*  values returned by <inquire predefined polyline representation>. */
/*  It draws the expected polyline incorrectly at the specified */
/*  position. */

/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of polyline bundle indices to be displayed */
/*    BUNDIF : position of polyline to be drawn incorrectly */
/* aspect source */
/*                bundled     individual */
/*  draw and label actual; use individual attributes */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    setasf_(&c__0);
#ifndef NO_PROTO
    xa[0] = .25f;
    xa[1] = .55f;
    yincr = .8f / *numbun;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).25;
    xa[1] = (float).55;
    yincr = (float).8 / *numbun;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(numbun, &c_b3, &yloc, &yincr);
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	ya[1] = yloc;
	nspli (&bundis[ix]);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L100: */
    }
/*  now draw expected results - with individual attributes from WDT */
/*  use individual attributes */
    setasf_(&c__1);
#ifndef NO_PROTO
    xa[0] = .6f;
    xa[1] = .9f;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).6;
    xa[1] = (float).9;
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nqpplr (&dialog_1.specwt, &bundis[ix], &errind, &pdlt, &pdlw, &pdci);
	chkinq_("pqpplr", &errind, 6L);
	if (ix == *bundif) {
	    pdlt = pdlt % 4 + 1;
#ifndef NO_PROTO
	    pdlw *= 1.5f;
#else /* NO_PROTO */
	    pdlw *= (float)1.5;
#endif /* NO_PROTO */
	    pdci = pdci % 5 + 1;
	}
	nsln (&pdlt);
	nslwsc (&pdlw);
	nsplci (&pdci);
	ya[0] = yloc;
	ya[1] = yloc;
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwplb_ */

