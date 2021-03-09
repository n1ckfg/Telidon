/* deblnk.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int deblnk_(char *strin, char *strout, integer *newsiz, 
	ftnlen strin_len, ftnlen strout_len)
#else /* NO_PROTO */
/* Subroutine */ int deblnk_(strin, strout, newsiz, strin_len, strout_len)
char *strin, *strout;
integer *newsiz;
ftnlen strin_len;
ftnlen strout_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_len(char *, ftnlen), i_indx(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer i_len(), i_indx();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, recv, nbloc, nblen;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */

/*  deblnk accepts a string (strin) and generates from it another */
/*  string (strout) with all leading and internal blanks deleted. It */
/*  also returns the new size of the compressed string as newsiz, */
/*  which points to the last non-blank (0 if all blank). */
    s_copy(strout, " ", strout_len, 1L);
    nbloc = 0;
    nblen = 1;
    recv = 1;
L100:
/* get next sending non-blank */
    i__1 = i_len(strin, strin_len);
    for (ix = nbloc + nblen; ix <= i__1; ++ix) {
	if (strin[ix - 1] != ' ') {
	    nbloc = ix;
	    goto L210;
	}
/* L200: */
    }
/* no more non-blanks */
    goto L300;
/* send next non-blank field */
L210:
    s_copy(strout + (recv - 1), strin + (nbloc - 1), strout_len - (recv - 1), 
	    strin_len - (nbloc - 1));
/* more blanks to compress out? */
    nblen = i_indx(strin + (nbloc - 1), " ", strin_len - (nbloc - 1), 1L) - 1;

    if (nblen == -1) {
/*        all done */
    } else {
/* set recv */
	recv += nblen;
	goto L100;
    }
L300:
    *newsiz = itrim_(strout, strout_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* deblnk_ */

