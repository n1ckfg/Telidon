/* setfil.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__20 = 20;

#ifndef NO_PROTO
/* Subroutine */ int setfil_(char *filt, integer *fln, integer *flisx, 
	integer *flis, integer *flesx, integer *fles, ftnlen filt_len)
#else /* NO_PROTO */
/* Subroutine */ int setfil_(filt, fln, flisx, flis, flesx, fles, filt_len)
char *filt;
integer *fln, *flisx, *flis, *flesx, *fles;
ftnlen filt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ecol, icol, eldx, etot, itot, work[2200]	/* was [20][
	    110] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int set2d_(char *, integer *, integer *, integer *
	    , integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int set2d_();
#endif /* NO_PROTO */
    static integer fltdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer collen[110], numcol;

/*  SETFIL translates the character version of a filter list into the */
/*  appropriate integer arrays. */
/*  Declaration of COLLEN and WORK allows for a filter list with 55 */
/*  filters, each with an inclusion set and exclusion set of up to 20 */
/*  members.  Generated test case from P07 uses at most 50 filters. */
    /* Parameter adjustments */
    --fles;
    --flesx;
    --flis;
    --flisx;

    /* Function Body */
    set2d_(filt, &c__20, &numcol, collen, work, filt_len);
    *fln = numcol / 2;
    if (*fln << 1 != numcol) {
	unmsg_("Illegal filter list passed to SETFIL.", 37L);
    }
    itot = 0;
    etot = 0;
    i__1 = *fln;
    for (fltdx = 1; fltdx <= i__1; ++fltdx) {
	icol = (fltdx << 1) - 1;
	ecol = fltdx << 1;
/*  inclusion set */
	i__2 = collen[icol - 1];
	for (eldx = 1; eldx <= i__2; ++eldx) {
	    ++itot;
	    flis[itot] = work[eldx + icol * 20 - 21];
/* L200: */
	}
	flisx[fltdx] = itot;
/*  exclusion set */
	i__2 = collen[ecol - 1];
	for (eldx = 1; eldx <= i__2; ++eldx) {
	    ++etot;
	    fles[etot] = work[eldx + ecol * 20 - 21];
/* L300: */
	}
	flesx[fltdx] = etot;
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setfil_ */

