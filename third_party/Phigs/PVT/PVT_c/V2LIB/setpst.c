/* setpst.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b4 = 1.f;
#else /* NO_PROTO */
static real c_b4 = (float)1.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int setpst_(integer *numstr, integer *strid, integer *numwks,
	 integer *acwkid, integer *stinwk)
#else /* NO_PROTO */
/* Subroutine */ int setpst_(numstr, strid, numwks, acwkid, stinwk)
integer *numstr, *strid, *numwks, *acwkid, *stinwk;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer stinwk_dim1, stinwk_offset, i__1, i__2;

    /* Local variables */
    static integer iwk, istr;
#ifndef NO_PROTO
    extern /* Subroutine */ int npost (integer *, integer *, real *), nupast (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npost (), nupast ();
#endif /* NO_PROTO */

/*  SETPST sets up the complete state of posting among a set */
/*  of structures and workstations. */
/*  ------- INPUT PARAMETERS */
/*  numstr   : number of structures */
/*  strid    : list of structure identifiers */
/*  numwks   : number of workstations */
/*  acwkid   : list of workstation identifiers */
/*  stinwk   : 2D array, indicating what is to be posted */
    /* Parameter adjustments */
    stinwk_dim1 = *numstr;
    stinwk_offset = stinwk_dim1 + 1;
    stinwk -= stinwk_offset;
    --acwkid;
    --strid;

    /* Function Body */
    i__1 = *numwks;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	nupast (&acwkid[iwk]);
	i__2 = *numstr;
	for (istr = 1; istr <= i__2; ++istr) {
	    if (stinwk[istr + iwk * stinwk_dim1] == 1) {
		npost (&acwkid[iwk], &strid[istr], &c_b4);
	    }
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setpst_ */

