/* issdis.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int issdis_(real *sisrpx, real *sisrpy, real *sisrpz, real *
	sdist, real *xfrmt, integer *mclipi, char *expath, ftnlen expath_len)
#else /* NO_PROTO */
/* Subroutine */ int issdis_(sisrpx, sisrpy, sisrpz, sdist, xfrmt, mclipi, 
	expath, expath_len)
real *sisrpx, *sisrpy, *sisrpz, *sdist, *xfrmt;
integer *mclipi;
char *expath;
ftnlen expath_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), issab_(real *, real *, real *, real *, char *, 
	    integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), issab_();
#endif /* NO_PROTO */
    static real cosrpx, cosrpy, cosrpz;

/*  This subroutine invokes the 3D spatial search routine with the */
/*  search distance set just below and above the theoretically */
/*  correct distance.  The search always begins at the start of */
/*  structure #101.  Thus, the search should first be unsuccessful, */
/*  and then successful.  ISSDIS issues pass or fail as a result */
/*  of these two searches. */
/*  Input parameters: */
/*    SISRPX,Y,Z : untransformed search reference point */
/*    SDIST      : correct search distance */
/*    XFRMT      : matrix used to transform search reference point */
/*    MCLIPI     : clipping indicator to be used */
/*    EXPATH     : expected found path */
/*  transform search reference point */
    /* Parameter adjustments */
    xfrmt -= 5;

    /* Function Body */
    etp3_(sisrpx, sisrpy, sisrpz, &xfrmt[5], &cosrpx, &cosrpy, &cosrpz);
    issab_(&cosrpx, &cosrpy, &cosrpz, sdist, "101,0", mclipi, &c__1, expath, 
	    5L, expath_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* issdis_ */

