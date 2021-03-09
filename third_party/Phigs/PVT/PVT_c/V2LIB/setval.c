/* setval.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int setval_(char *st, integer *arr, ftnlen st_len)
#else /* NO_PROTO */
/* Subroutine */ int setval_(st, arr, st_len)
char *st;
integer *arr;
ftnlen st_len;
#endif /* NO_PROTO */
{
    static integer nsz;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */

/*  setval initializes the integer array ARR, based on the */
/*  value-representations in ST. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    setvs_(st, &arr[1], &nsz, st_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setval_ */

