/* expppm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int expppm_(integer *yloc, real *xval, integer *mksty, real *
	mwsc)
#else /* NO_PROTO */
/* Subroutine */ int expppm_(yloc, xval, mksty, mwsc)
integer *yloc;
real *xval;
integer *mksty;
real *mwsc;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nsmk (integer *), locppm_(integer *, real *), 
	    nsmksc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsmk (), locppm_(), nsmksc ();
#endif /* NO_PROTO */

/*  EXPPPM draws a polymarker with the expected marker type and */
/*  marker size. */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    nsmk (mksty);
    nsmksc (mwsc);
    locppm_(yloc, &xval[1]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* expppm_ */

