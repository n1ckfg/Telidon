/* retopn.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int retopn_(integer *strid, integer *elptr, char *strels, 
	ftnlen strels_len)
#else /* NO_PROTO */
/* Subroutine */ int retopn_(strid, elptr, strels, strels_len)
integer *strid, *elptr;
char *strels;
ftnlen strels_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), inmsg_(char *, ftnlen), nclst (
	    void), chkelp_(integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), inmsg_(), nclst (), chkelp_(), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer errind, opstid;
#ifndef NO_PROTO
    extern logical strcon_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern logical strcon_();
#endif /* NO_PROTO */
    static integer opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst ();
#endif /* NO_PROTO */

/*  RETOPN checks that the state of the open structure is as expected */
/*  and issues pass or fail as a result.  If there is an open */
/*  structure, it is closed by RETOPN */
/*  Input parameters: */
/*    strid  : expected open structure identifier */
/*    elptr  : expected value of element pointer */
/*    strels : expected contents of open structure */
/* open-structure status */
    nqopst (&errind, &opstat, &opstid);
    chkinq_("pqopst", &errind, 6L);
    if (opstat == 1) {
	if (opstid == *strid) {
	    if (strcon_(strid, strels, strels_len)) {
		chkelp_(elptr);
	    } else {
		fail_();
		inmsg_("Failed because of incorrect structure contents.", 47L)
			;
	    }
	} else {
	    fail_();
	    inmsg_("Failed because incorrect structure was open.", 44L);
	}
	nclst ();
    } else {
	fail_();
	inmsg_("Failed because no structure was open.", 37L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* retopn_ */

