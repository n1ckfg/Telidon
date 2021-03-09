/* rnset.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int rnset_(integer *size, integer *maxmem, integer *set)
#else /* NO_PROTO */
/* Subroutine */ int rnset_(size, maxmem, set)
integer *size, *maxmem, *set;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int rnbset_(integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnbset_();
#endif /* NO_PROTO */

/* RNSET returns a random set of SIZE distinct integers, chosen from */
/* the universe of 1-MAXMEM, returned in SET.  For example, if SIZE is */
/* specified as 4, and MAXMEM as 7, SET might = [2,5,7,4]. */
    /* Parameter adjustments */
    --set;

    /* Function Body */
    rnbset_(size, &c__1, maxmem, &set[1]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* rnset_ */

