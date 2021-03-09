/* sqgrmk.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int sqgrmk_(real *start, real *finish, real *step)
#else /* NO_PROTO */
/* Subroutine */ int sqgrmk_(start, finish, step)
real *start, *finish, *step;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2, r__3, r__4;

    /* Local variables */
    static real xa[200], ya[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static integer siz;
    static real xloc, yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/*  SQGRMK draws a square grid of polymarkers.  They are drawn one */
/*  row at a time to avoid array overflow. */
/*  Input parameters: */
/*    START  : First x and y locations */
/*    FINISH : Upper limit for x and y locations */
/*    STEP   : Distance between markers */
#ifndef NO_PROTO
    if ((*finish - *start) / *step > 200.f) {
#else /* NO_PROTO */
    if ((*finish - *start) / *step > (float)200.) {
#endif /* NO_PROTO */
	unmsg_("Number of polymarkers exceeds array size in SQGRMK.", 51L);
    }
    r__1 = *finish;
    r__2 = *step;
    for (xloc = *start; r__2 < 0 ? xloc >= r__1 : xloc <= r__1; xloc += r__2) 
	    {
	siz = 0;
	r__3 = *finish;
	r__4 = *step;
	for (yloc = *start; r__4 < 0 ? yloc >= r__3 : yloc <= r__3; yloc += 
		r__4) {
	    ++siz;
	    xa[siz - 1] = xloc;
	    ya[siz - 1] = yloc;
/* L210: */
	}
	npm (&siz, xa, ya);
/* L215: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* sqgrmk_ */

