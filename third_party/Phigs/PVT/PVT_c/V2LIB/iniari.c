/* iniari.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int iniari_(char *st, integer *arr, integer *nsz, integer *
	ierr, ftnlen st_len)
#else /* NO_PROTO */
/* Subroutine */ int iniari_(st, arr, nsz, ierr, st_len)
char *st;
integer *arr, *nsz, *ierr;
ftnlen st_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_indx();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer nc, lst, ival;
    static char stwk[700];
#ifndef NO_PROTO
    extern /* Subroutine */ int deblnk_(char *, char *, integer *, ftnlen, 
	    ftnlen), prsint_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int deblnk_(), prsint_();
#endif /* NO_PROTO */

/*  INIARI initializes the integer array ARR, based on the */
/*  value-representations in ST and also returns the number */
/*  of values in NSZ.  INIARI does not abort when faced with */
/*  an invalid string, just returns a non-zero error code in IERR. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    *nsz = 0;
    *ierr = 0;
/* blank means zero entries */
    if (s_cmp(st, " ", st_len, 1L) == 0) {
	return 0;
    }
/* get rid of leading, internal blanks */
    deblnk_(st, stwk, &lst, st_len, 700L);
/* L300: */
/* add trailing comma */
    ++lst;
    stwk[lst - 1] = ',';
/* now sitting at alleged number */
L400:
/* find next comma */
    nc = i_indx(stwk, ",", 700L, 1L);
    if (nc <= 1) {
	*ierr = 1;
	return 0;
    }
/* parse up to comma */
    prsint_(stwk, &ival, ierr, nc - 1);
    if (*ierr != 0) {
	*ierr += 100;
	return 0;
    }
/* add new entry to array */
    ++(*nsz);
    arr[*nsz] = ival;
/* delete thru comma */
    i__1 = nc;
    s_copy(stwk, stwk + i__1, 700L, 700 - i__1);
    if (s_cmp(stwk, " ", 700L, 1L) != 0) {
	goto L400;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* iniari_ */

