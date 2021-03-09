/* elgprm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int elgprm_(integer *incsiz, integer *incset, integer *
	excsiz, integer *excset, integer *trusiz, integer *trulis)
#else /* NO_PROTO */
/* Subroutine */ int elgprm_(incsiz, incset, excsiz, excset, trusiz, trulis)
integer *incsiz, *incset, *excsiz, *excset, *trusiz, *trulis;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix, sval, list[8], primid;
#ifndef NO_PROTO
    extern /* Subroutine */ int setval_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setval_();
#endif /* NO_PROTO */

/*  Subroutine ELGPRM determines the eligible primitives for the */
/*  given inclusion and exclusion set. The eligible primitives are */
/*  returned in TRULIS. */
/*  Input parameters: */
/*    INCSIZ,INCSET : inclusion set */
/*    EXCSIZ,EXCSET : exclusion set */
/*  Output parameters: */
/*    TRUSIZ,TRULIS : list of eligible primitives */
/*   Check the include and exclude sets to determine which */
/*   of the following primitives will be highlighted. */
/*   position  primitive        color   nameset */
/*     1       polyline           1      0, 1, 2 */
/*     2       polymarker         2      3, 4, 5 */
/*     3       fill area          3      6, 7, 8 */
/*     4       cell array         4      9,10,11 */
/*     5       text               1     12,13,14 */
/*     6       polyline 3         2     15,16,17 */
/*     7       annotation text    3     18,19,20 */
/*     8       fill area set      4     21,22,23 */
/*   First check the inclusion set, include any primitive that */
/*   appears, then check the exclusion set, removing any primitive */
/*   that appears, the set we are left with are the eligible ones. */
/*   Names outside of 0-23 are ignored. */
    /* Parameter adjustments */
    --trulis;
    --excset;
    --incset;

    /* Function Body */
    setval_("0,0,0,0,0,0,0,0", list, 15L);
    i__1 = *incsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	sval = incset[ix];
	if (sval >= 0 && sval <= 23) {
	    primid = sval / 3 + 1;
	    list[primid - 1] = 1;
	}
/* L100: */
    }
    i__1 = *excsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	sval = excset[ix];
	if (sval >= 0 && sval <= 23) {
	    primid = sval / 3 + 1;
	    list[primid - 1] = 0;
	}
/* L110: */
    }
    *trusiz = 0;
    for (ix = 1; ix <= 8; ++ix) {
	if (list[ix - 1] == 1) {
	    ++(*trusiz);
	    trulis[*trusiz] = ix;
	}
/* L120: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* elgprm_ */

