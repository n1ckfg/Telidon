/* iareql.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical iareql_(integer *sizea, integer *arra, integer *sizeb, integer *arrb)
#else /* NO_PROTO */
logical iareql_(sizea, arra, sizeb, arrb)
integer *sizea, *arra, *sizeb, *arrb;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical iareq_();
#endif /* NO_PROTO */

/*  General purpose routine for equality of two variable-length */
/*  integer lists. */
/*  ------- Input parameters: */
/*  sizea   : size of first list */
/*  arra    : contents of first list */
/*  sizeb   : size of second list */
/*  arrb    : contents of second list */
/*  This will handle multi-dimensional arrays according to the usual */
/*  Fortran rules for overlaying arrays. */
    /* Parameter adjustments */
    --arrb;
    --arra;

    /* Function Body */
    if (*sizea == *sizeb) {
	ret_val = iareq_(sizea, &arra[1], &arrb[1]);
    } else {
	ret_val = FALSE_;
    }
    return ret_val;
} /* iareql_ */

