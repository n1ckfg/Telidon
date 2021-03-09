/* fort/02/03/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 02.03.02/tstels                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tstels_(integer *strid, integer *stpos, integer *dir, 
	integer *isz, integer *elinc, integer *esz, integer *elexc, integer *
	expsta, integer *exppos)
#else /* NO_PROTO */
/* Subroutine */ int tstels_(strid, stpos, dir, isz, elinc, esz, elexc, 
	expsta, exppos)
integer *strid, *stpos, *dir, *isz, *elinc, *esz, *elexc, *expsta, *exppos;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nels (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nels ();
#endif /* NO_PROTO */
    static integer actsta, errind, actpos;

/*  TSTELS is used to test element search.  It accepts input parameters to
 */
/*  be passed to <element search> and the expected result.  It then issues
 */
/*  pass or fail depending on whether the actual values returned from the 
*/
/*  function match those expected. */
/*  Input parameters */
/*    STRID     : structure id to be passed to PELS */
/*    STPOS     : starting position to be passed to PELS */
/*    DIR       : search direction to be passed to PELS */
/*    ISZ,ELINC : inclusion set to be passed to PELS */
/*    ESZ,ELEXC : exclusion set to be passed to PELS */
/*    EXPSTA    : expected status (SUCCESS, FAILURE) */
/*    EXPPOS    : expected found position */
/* search success */
    /* Parameter adjustments */
    --elexc;
    --elinc;

    /* Function Body */
    nels (strid, stpos, dir, isz, &elinc[1], esz, &elexc[1], &errind, &actsta,
	     &actpos);
    if (*expsta == 0) {
	actpos = *exppos;
    }
    L__1 = errind == 0 && actsta == *expsta && actpos == *exppos;
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstels_ */

