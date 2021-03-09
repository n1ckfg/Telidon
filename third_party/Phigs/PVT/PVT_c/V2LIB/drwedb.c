/* drwedb.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int drwedb_(integer *numbun, integer *bundis, integer *
	bundif, integer *numet)
#else /* NO_PROTO */
/* Subroutine */ int drwedb_(numbun, bundis, bundif, numet)
integer *numbun, *bundis, *bundif, *numet;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[4], ya[4];
    static integer ix, pdef, pdci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer pdet;
    static real pdew, yloc;
    static integer npts[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedt (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedt ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int drbued_(integer *, integer *), nsedfg (
	    integer *), nsedci (integer *), chkinq_(char *, integer *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int drbued_(), nsedfg (), nsedci (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nqpedr (integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nsewsc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nqpedr (), nsewsc ();
#endif /* NO_PROTO */

/*  DRWEDB draws a set of actual edges using the specified bundle */
/*  values, and a set of expected edges, using the attribute */
/*  values returned by <inquire predefined edge representation>. */
/*  It draws the expected edge incorrectly at the specified */
/*  position. */

/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of edge bundle indices to be displayed */
/*    BUNDIF : position of edge to be drawn incorrectly */
/*    NUMET  : number of edge types */
/* aspect source */
/* off/on switch for edge flag and error handling mode */
/*  draw triangles to display edge */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    npts[0] = 3;
/*  draw and label actual */
    drbued_(numbun, &bundis[1]);
/*  now draw expected results - with individual attributes from WDT */
/*  use individual attributes */
    setasf_(&c__1);
#ifndef NO_PROTO
    xa[0] = .6f;
    xa[1] = .6f;
    xa[2] = .9f;
    yloc = .9f;
    yincr = .8f / *numbun;
#else /* NO_PROTO */
    xa[0] = (float).6;
    xa[1] = (float).6;
    xa[2] = (float).9;
    yloc = (float).9;
    yincr = (float).8 / *numbun;
#endif /* NO_PROTO */
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nqpedr (&dialog_1.specwt, &bundis[ix], &errind, &pdef, &pdet, &pdew, &
		pdci);
	chkinq_("pqpedr", &errind, 6L);
	if (ix == *bundif) {
	    if (*numet == 1) {
/*  switch edge flag */
		if (pdef == 1) {
		    pdef = 0;
		} else {
		    pdef = 1;
		}
	    }
	    pdet = pdet % 4 + 1;
#ifndef NO_PROTO
	    pdew *= 1.3f;
#else /* NO_PROTO */
	    pdew *= (float)1.3;
#endif /* NO_PROTO */
	    pdci = pdci % 5 + 1;
	}
	nsedfg (&pdef);
	nsedt (&pdet);
	nsewsc (&pdew);
	nsedci (&pdci);
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
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwedb_ */

