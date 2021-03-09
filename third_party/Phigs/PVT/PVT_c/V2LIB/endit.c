/* endit.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int endit_(void)
#else /* NO_PROTO */
/* Subroutine */ int endit_()
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix, wkid, idum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclph (void), nclwk (integer *), nclst (void);

#else /* NO_PROTO */
    extern /* Subroutine */ int nclph (), nclwk (), nclst ();
#endif /* NO_PROTO */
    static integer numwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqsys (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqsys ();
#endif /* NO_PROTO */
    static integer sysst;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int windup_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int windup_();
#endif /* NO_PROTO */
    static integer opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nupast (integer *), nqopwk (integer *, 
	    integer *, integer *, integer *), nqopst (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nupast (), nqopwk (), nqopst ();
#endif /* NO_PROTO */

/*  ENDIT performs all normal close-out chores for a PVT test: */
/*  it clears and closes all open workstations, closes the open */
/*  structure if there is one, closes PHIGS and issues WINDUP. */
/* system state value */
/* open-structure status */
/*  check if PHIGS open */
    nqsys (&sysst);
    if (sysst == 0) {
	goto L666;
    }
/*  close all open workstations */
    nqopwk (&c__0, &errind, &numwk, &idum);
    chkinq_("pqopwk", &errind, 6L);
    i__1 = numwk;
    for (ix = 1; ix <= i__1; ++ix) {
/*  always delete 1st element of remaining list - list changes each */

/*  time thru loop because of call to PCLWK */
	nqopwk (&c__1, &errind, &idum, &wkid);
	chkinq_("pqopwk", &errind, 6L);
	nupast (&wkid);
	nclwk (&wkid);
/* L100: */
    }
/*  close open structure */
    nqopst (&errind, &opstat, &idum);
    chkinq_("pqopst", &errind, 6L);
    if (opstat == 1) {
	nclst ();
    }
    nclph ();
L666:
    windup_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* endit_ */

