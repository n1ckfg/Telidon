/* fort/03/05/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 03.05/setdif                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setdif_(integer *bassiz, integer *basel, integer *subsiz,
	 integer *subel, integer *anssiz, integer *ansel)
#else /* NO_PROTO */
/* Subroutine */ int setdif_(bassiz, basel, subsiz, subel, anssiz, ansel)
integer *bassiz, *basel, *subsiz, *subel, *anssiz, *ansel;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer indx1, indx2;

/*  Setdif performs set difference: */
/*     ansel = basel - subel */

/*  Input parameters: */
/*     basel  : source set */
/*     bassiz : size of basel */
/*     subel  : subtracted set */
/*     sunsiz : size of subel */
/*  Output parameter: */
/*     ansel  : result set */
/*     anssiz : size of ansel */
    /* Parameter adjustments */
    --ansel;
    --subel;
    --basel;

    /* Function Body */
    *anssiz = 0;
    i__1 = *bassiz;
    for (indx1 = 1; indx1 <= i__1; ++indx1) {
	i__2 = *subsiz;
	for (indx2 = 1; indx2 <= i__2; ++indx2) {
	    if (basel[indx1] == subel[indx2]) {
		goto L100;
	    }
/* L200: */
	}
	++(*anssiz);
	ansel[*anssiz] = basel[indx1];
L100:
	;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setdif_ */

