/* setsvr.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;
static integer c__2 = 2;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int setsvr_(integer *wkid, integer *reqsvr)
#else /* NO_PROTO */
/* Subroutine */ int setsvr_(wkid, reqsvr)
integer *wkid, *reqsvr;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nrst (integer *, integer *), nsdus (integer *,
	     integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nrst (), nsdus ();
#endif /* NO_PROTO */
    static integer actpcc;
#ifndef NO_PROTO
    extern /* Subroutine */ int picchg_(integer *, char *, char *, integer *, 
	    integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int picchg_();
#endif /* NO_PROTO */
    static integer actsev;

/*  SETSVR: attempts to set the SVR of the specified workstation */
/*  to requested state.  There is no error report; the caller must */
/*  determine success. */
/* deferral mode */
/* modification mode */
/* dynamic modification */
/* clear control flag */
/*                conditionally  always */
/* state of visual representation */
/*                correct    deferred    simulated */
    nsdus (wkid, &c__4, &c__2);
/* make SVR correct */
    nrst (wkid, &c__0);
    if (*reqsvr == 1) {
/*  attempt IRG-type picture change */
	picchg_(wkid, "0", "13,14,15,16,17,9,8,1,2,3,4,5,6,7,10,11,12", &
		actsev, &actpcc, 1L, 41L);
    } else if (*reqsvr == 2) {
/*  attempt CBS-type picture change */
	picchg_(wkid, "2", "13,14,15,16,17,9,8,1,2,3,4,5,6,7,10,11,12", &
		actsev, &actpcc, 1L, 41L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setsvr_ */

