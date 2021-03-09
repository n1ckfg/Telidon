/* ispths.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__30 = 30;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int ispths_(real *srpx, real *srpy, real *srpz, real *sdist, 
	integer *sceil, integer *mclipi, char *stpth, char *expths, ftnlen 
	stpth_len, ftnlen expths_len)
#else /* NO_PROTO */
/* Subroutine */ int ispths_(srpx, srpy, srpz, sdist, sceil, mclipi, stpth, 
	expths, stpth_len, expths_len)
real *srpx, *srpy, *srpz, *sdist;
integer *sceil, *mclipi;
char *stpth, *expths;
ftnlen stpth_len;
ftnlen expths_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer idum[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), set2d_(char *, integer *, 
	    integer *, integer *, integer *, ftnlen), niss3 (real *, real *, 
	    real *, real *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), set2d_(), niss3 ();
#endif /* NO_PROTO */
    static integer fpath[60]	/* was [2][30] */, ipath, exlen[30], spath[60]
	    	/* was [2][30] */, exnum;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */
    static integer spsiz;
#ifndef NO_PROTO
    extern logical iareql_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical iareql_();
#endif /* NO_PROTO */
    static integer errind, expath[900]	/* was [30][30] */, fpthsz;

/*  This subroutine repeatedly invokes spatial search, using the */
/*  found path of one search as the starting path for the next, and */
/*  issues pass or fail, depending on whether the actual paths match */
/*  those expected. */
/*  Input parameters: */
/*    SRPX,Y,Z : search reference point to be used in ISS's */
/*    SDIST    : search distance to be used in ISS's */
/*    SCEIL    : search ceiling to be used in ISS's */
/*    MCLIPI   : modelling clipping indicator */
/*    STPTH    : starting path for first ISS */
/*    EXPTHS   : sequence of expected found paths for ISS's */
    setvs_(stpth, spath, &spsiz, stpth_len);
    spsiz /= 2;
    set2d_(expths, &c__30, &exnum, exlen, expath, expths_len);
    i__1 = exnum;
    for (ipath = 1; ipath <= i__1; ++ipath) {
	niss3 (srpx, srpy, srpz, sdist, &spsiz, spath, mclipi, sceil, &c__0, 
		idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &c__30,
		 &errind, &fpthsz, fpath);
	i__2 = fpthsz << 1;
	if (errind == 0 && iareql_(&i__2, fpath, &exlen[ipath - 1], &expath[
		ipath * 30 - 30])) {
/* OK so far - copy found path to next starting path */
	    spsiz = fpthsz;
	    i__2 = spsiz;
	    for (ix = 1; ix <= i__2; ++ix) {
		spath[(ix << 1) - 2] = fpath[(ix << 1) - 2];
		spath[(ix << 1) - 1] = fpath[(ix << 1) - 1];
/* L110: */
	    }
	} else {
	    fail_();
	    return 0;
	}
/* L100: */
    }
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ispths_ */

