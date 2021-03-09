/* setis.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical setis_(integer *arr, char *st, ftnlen st_len)
#else /* NO_PROTO */
logical setis_(arr, st, st_len)
integer *arr;
char *st;
ftnlen st_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer wk[500], nsz;
#ifndef NO_PROTO
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int unmsg_(char *, ftnlen), setvs_(char *, 
	    integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical seteq_();
    extern /* Subroutine */ int unmsg_(), setvs_();
#endif /* NO_PROTO */

/*  setis compares the contents of the integer array ARR with the set */
/*  of integers encoded in the character string ST and returns .true. */
/*  iff the leading elements of ARR contain exactly those values *in */
/*  any order*.  ST contains integer-like strings separated by */
/*  commas, e.g. "3, +4, -5". */
/*  store ST values in WK array; NSZ is number of values */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    setvs_(st, wk, &nsz, st_len);
    if (nsz > 500) {
#ifndef NO_PROTO
	unmsg_("Number of values in string passed to SETIS exceeds size of w"
		"ork area.", 69L);
#else /* NO_PROTO */
	unmsg_("Number of values in string passed to SETIS exceeds size of w\
ork area.", 69L);
#endif /* NO_PROTO */
    }
/*  compare the two arrays */
    ret_val = seteq_(&nsz, &arr[1], wk);
    return ret_val;
} /* setis_ */

