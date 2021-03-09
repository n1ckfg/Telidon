/* rn1shf.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int rn1shf_(integer *siz, integer *perm)
#else /* NO_PROTO */
/* Subroutine */ int rn1shf_(siz, perm)
integer *siz, *perm;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer swvals[4] = { 5,6,11,12 };

    static integer ix, iy, hdx, ldx, tmp, swloc;
#ifndef NO_PROTO
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static integer needvl;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_();
#endif /* NO_PROTO */

/*  Incredibly special-purpose subroutine which returns a permutation in 
*/
/*  PERM with the constraint that: */

/*     PERM(12) - PERM(11) = PERM(06) - PERM(05) */

/*  so as to force uniform scaling.  This is needed in inheritance tests 
*/
/*  when displaying primitives with an intrinsic size, such as fill area 
*/
/*  or text, as opposed to a single segment of a polyline or a single */
/*  polymarker. */
    /* Parameter adjustments */
    --perm;

    /* Function Body */
    rnperm_(siz, &perm[1]);
/*  put locations of 5,6,11,12 in ascending order */
    for (ix = 1; ix <= 3; ++ix) {
	for (iy = ix + 1; iy <= 4; ++iy) {
	    ldx = swvals[ix - 1];
	    hdx = swvals[iy - 1];
	    if (perm[ldx] > perm[hdx]) {
		tmp = perm[ldx];
		perm[ldx] = perm[hdx];
		perm[hdx] = tmp;
	    }
/* L300: */
	}
/* L200: */
    }
/*  switch values for shortest interval */
    if (perm[6] - perm[5] < perm[12] - perm[11]) {
/*  switch contents of PERM(11) with needed value */
	needvl = perm[12] + perm[5] - perm[6];
	swloc = 11;
    } else {
/*  switch contents of PERM(5) with needed value */
	needvl = perm[11] + perm[6] - perm[12];
	swloc = 5;
    }
    perm[iarfnd_(&needvl, siz, &perm[1])] = perm[swloc];
    perm[swloc] = needvl;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* rn1shf_ */

