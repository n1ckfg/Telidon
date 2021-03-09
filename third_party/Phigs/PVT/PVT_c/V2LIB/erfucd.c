/* erfucd.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int erfucd_(char *funnam, integer *funccd, ftnlen funnam_len)

#else /* NO_PROTO */
/* Subroutine */ int erfucd_(funnam, funccd, funnam_len)
char *funnam;
integer *funccd;
ftnlen funnam_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_indx();
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, iy;
    static char wnam[100];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen), leadnb_(char *, ftnlen);
    extern /* Subroutine */ int erfunm_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_(), leadnb_();
    extern /* Subroutine */ int erfunm_();
#endif /* NO_PROTO */
    static char trunam[100];

/*  ERFUCD accepts a character string identifying a generic function */
/*  and returns the standard function code. */

/*  Input parameter: */
/*    FUNNAM : generic name of function */
/*  Output parameter: */
/*    FUNCCD : integer code for offending function */
    *funccd = -1;
    if (s_cmp(funnam, " ", funnam_len, 1L) == 0) {
	return 0;
    }
/*  check whether already enclosed in angle brackets */
    ix = i_indx(funnam, "<", funnam_len, 1L);
    if (ix > 0) {
	s_copy(wnam, funnam + (ix - 1), 100L, funnam_len - (ix - 1));
    } else {
	ix = leadnb_(funnam, funnam_len);
	iy = itrim_(funnam, funnam_len);
/* Writing concatenation */
	i__1[0] = 1, a__1[0] = "<";
	i__1[1] = iy - (ix - 1), a__1[1] = funnam + (ix - 1);
	i__1[2] = 1, a__1[2] = ">";
	s_cat(wnam, a__1, i__1, &c__3, 100L);
    }
/*  WNAM now has canonical function name */
    for (iy = 0; iy <= 182; ++iy) {
	erfunm_(&iy, trunam, 100L);
	if (s_cmp(wnam, trunam, 100L, 100L) == 0) {
	    *funccd = iy;
	    return 0;
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* erfucd_ */

