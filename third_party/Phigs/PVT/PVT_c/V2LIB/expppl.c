/* expppl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int expppl_(integer *yloc, real *xval, integer *lnsty, real *
	lwsc)
#else /* NO_PROTO */
/* Subroutine */ int expppl_(yloc, xval, lnsty, lwsc)
integer *yloc;
real *xval;
integer *lnsty;
real *lwsc;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *), locppl_(integer *, real *), 
	    nslwsc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln (), locppl_(), nslwsc ();
#endif /* NO_PROTO */

/*  EXPPPL draws a polyline with the expected linestyle and linewidth */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    nsln (lnsty);
    nslwsc (lwsc);
    locppl_(yloc, &xval[1]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* expppl_ */

