/* drbued.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

#ifndef NO_PROTO
static real c_b2 = .2f;
#else /* NO_PROTO */
static real c_b2 = (float).2;
#endif /* NO_PROTO */
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int drbued_(integer *numbun, integer *bundis)
#else /* NO_PROTO */
/* Subroutine */ int drbued_(numbun, bundis)
integer *numbun, *bundis;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[4], ya[4];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static real yloc;
    static integer npts[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedi ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int numlab_(integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int numlab_();
#endif /* NO_PROTO */

/*  DRBUED draws a set of edges using the specified edge bundle */
/*  values. */
/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of edge bundle indices to be displayed */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    npts[0] = 3;
#ifndef NO_PROTO
    xa[0] = .25f;
    xa[1] = .25f;
    xa[2] = .55f;
    yincr = .8f / *numbun;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).25;
    xa[1] = (float).25;
    xa[2] = (float).55;
    yincr = (float).8 / *numbun;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(numbun, &c_b2, &yloc, &yincr);
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .25f;
	ya[1] = yloc + yincr * .25f;
	ya[2] = yloc - yincr * .25f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).25;
	ya[1] = yloc + yincr * (float).25;
	ya[2] = yloc - yincr * (float).25;
#endif /* NO_PROTO */
	nsedi (&bundis[ix]);
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drbued_ */

