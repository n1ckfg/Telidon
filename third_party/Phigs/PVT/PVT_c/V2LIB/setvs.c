/* setvs.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int setvs_(char *st, integer *arr, integer *nsz, ftnlen 
	st_len)
#else /* NO_PROTO */
/* Subroutine */ int setvs_(st, arr, nsz, st_len)
char *st;
integer *arr, *nsz;
ftnlen st_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static integer ierr;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), iniari_(char *, 
	    integer *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), iniari_();
#endif /* NO_PROTO */
    static char tmpmsg[300];

/*  SETVS initializes the integer array ARR, based on the */
/*  value-representations in ST and also returns the number */
/*  of values in NSZ.  SETVS is meant to be called to parse */
/*  strings generated directly by other PVT code, and thus */
/*  aborts on invalid strings.  To handle strings from operator, */
/*  use INIARI directly. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    iniari_(st, &arr[1], nsz, &ierr, st_len);
    if (ierr != 0) {
/* Writing concatenation */
	i__1[0] = 30, a__1[0] = "Invalid string sent to SETVS: ";
	i__1[1] = st_len, a__1[1] = st;
	s_cat(tmpmsg, a__1, i__1, &c__2, 300L);
	unmsg_(tmpmsg, 300L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setvs_ */

