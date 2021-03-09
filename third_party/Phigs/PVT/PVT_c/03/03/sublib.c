/* fort/03/03/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 03.03/cssids                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical cssids_(char *idstr, ftnlen idstr_len)
#else /* NO_PROTO */
logical cssids_(idstr, idstr_len)
char *idstr;
ftnlen idstr_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix, idum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqsid (integer *, integer *, integer *, 
	    integer *);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int unmsg_(char *, ftnlen), setvs_(char *, 
	    integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqsid ();
    extern logical seteq_();
    extern /* Subroutine */ int unmsg_(), setvs_();
#endif /* NO_PROTO */
    static integer actids[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, expids[300], actsiz, expsiz;

/*  This routine checks the actual set of structure identifiers in */
/*  the CSS against an expected list, encoded in idstr.  If equal it */
/*  returns true, else false. */
    setvs_(idstr, expids, &expsiz, idstr_len);
    if (expsiz > 300) {
	unmsg_("Expected size exceeds limits of CSSIDS.", 39L);
    }
/*  <inquire structure identifiers> to determine actual list of structures
 */
    nqsid (&c__0, &errind, &actsiz, &idum);
    chkinq_("pqsid", &errind, 5L);
    if (actsiz != expsiz) {
	ret_val = FALSE_;
	return ret_val;
    }
    if (actsiz > 300) {
	unmsg_("Actual size exceeds limits of CSSIDS.", 37L);
    }
    i__1 = actsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	nqsid (&ix, &errind, &idum, &actids[ix - 1]);
	chkinq_("pqsid", &errind, 5L);
/* L100: */
    }
    ret_val = seteq_(&actsiz, actids, expids);
    return ret_val;
} /* cssids_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 03.03/retopn                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

