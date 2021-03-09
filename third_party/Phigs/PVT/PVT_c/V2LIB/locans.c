/* locans.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 0.f;
#else /* NO_PROTO */
static real c_b2 = (float)0.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int locans_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locans_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real xoff = -.15f;
    static real yoff = .05f;
#else /* NO_PROTO */
    static real xoff = (float)-.15;
    static real yoff = (float).05;
#endif /* NO_PROTO */

    /* System generated locals */
    real r__1, r__2, r__3, r__4;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr ();
#endif /* NO_PROTO */
    static real npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int wcnpc_(real *, real *, real *, real *, real *)
	    ;
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int wcnpc_();
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real npcpwc;

/*  LOCANS draws an annotation text primitive with a distinct */
/*  annotation point and reference point, at the real y-location */
/*  corresponding to the integer index given in YLOC. */
    wcnpc_(&c_b2, &c_b2, &npcx, &npcy, &npcpwc);
    r__1 = *xval - xoff;
    r__2 = ylocel_(yloc) - yoff;
    r__3 = xoff * npcpwc;
    r__4 = yoff * npcpwc;
    natr (&r__1, &r__2, &r__3, &r__4, "Hiho", 4L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locans_ */

