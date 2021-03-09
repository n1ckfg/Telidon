/* chkpst.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int chkpst_(integer *numstr, integer *strid, integer *numwks,
	 integer *acwkid, integer *stvswk, logical *lwpcod, logical *lpscod)
#else /* NO_PROTO */
/* Subroutine */ int chkpst_(numstr, strid, numwks, acwkid, stvswk, lwpcod, 
	lpscod)
integer *numstr, *strid, *numwks, *acwkid, *stvswk;
logical *lwpcod, *lpscod;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer stvswk_dim1, stvswk_offset, i__1, i__2;

    /* Local variables */
    static integer iwk, istr, idum1;
#ifndef NO_PROTO
    extern logical seteq_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical seteq_();
#endif /* NO_PROTO */
    static integer errind, actlps[10], actlwp[10];
    static real dispri;
    static integer actsiz, explps[10], explwp[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkpo (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkpo ();
#endif /* NO_PROTO */
    static integer expsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpost (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpost ();
#endif /* NO_PROTO */

/*  CHKPST checks the complete actual state of posting among a set */
/*  of structures and workstations against the expected state. */
/*  ------- INPUT PARAMETERS */
/*  numstr   : number of structures */
/*  strid    : list of structure identifiers */
/*  numwks   : number of workstations */
/*  acwkid   : list of workstation identifiers */
/*  stvswk   : 2D array, indicating expected posted state */
/*  ------- OUTPUT PARAMETERS */
/*  lwpcod   : validity of lists of workstations to which posted */
/*  lpscod   : validity of lists of posted structures */
/*  actual, expected list of workstations to which posted */
/*  actual, expected list of posted structures */
/*  check list of workstations to which posted */
    /* Parameter adjustments */
    stvswk_dim1 = *numstr;
    stvswk_offset = stvswk_dim1 + 1;
    stvswk -= stvswk_offset;
    --acwkid;
    --strid;

    /* Function Body */
    i__1 = *numstr;
    for (istr = 1; istr <= i__1; ++istr) {
/*  construct expected lwp */
	expsiz = 0;
	i__2 = *numwks;
	for (iwk = 1; iwk <= i__2; ++iwk) {
	    if (stvswk[istr + iwk * stvswk_dim1] == 1) {
/*  add workstation to expected list */
		++expsiz;
		explwp[expsiz - 1] = acwkid[iwk];
	    }
/* L110: */
	}
	nqwkpo (&strid[istr], &c__0, &errind, &actsiz, &idum1);
	if (errind == 0 && actsiz == expsiz) {
/*           OK so far */
	} else {
	    *lwpcod = FALSE_;
	    goto L190;
	}
/*  construct actual lwp */
	i__2 = actsiz;
	for (iwk = 1; iwk <= i__2; ++iwk) {
	    nqwkpo (&strid[istr], &iwk, &errind, &idum1, &actlwp[iwk - 1]);
	    if (errind != 0) {
		*lwpcod = FALSE_;
		goto L190;
	    }
/* L120: */
	}
	if (! seteq_(&actsiz, actlwp, explwp)) {
	    *lwpcod = FALSE_;
	    goto L190;
	}
/* L100: */
    }
    *lwpcod = TRUE_;
L190:
/*  check list of posted structures */
    i__1 = *numwks;
    for (iwk = 1; iwk <= i__1; ++iwk) {
/*  construct expected lps */
	expsiz = 0;
	i__2 = *numstr;
	for (istr = 1; istr <= i__2; ++istr) {
	    if (stvswk[istr + iwk * stvswk_dim1] == 1) {
/*  add structure to expected list */
		++expsiz;
		explps[expsiz - 1] = strid[istr];
	    }
/* L210: */
	}
	nqpost (&acwkid[iwk], &c__0, &errind, &actsiz, &idum1, &dispri);
	if (errind == 0 && actsiz == expsiz) {
/*           OK so far */
	} else {
	    *lpscod = FALSE_;
	    goto L290;
	}
/*  construct actual lps */
	i__2 = actsiz;
	for (istr = 1; istr <= i__2; ++istr) {
	    nqpost (&acwkid[iwk], &istr, &errind, &idum1, &actlps[istr - 1], &
		    dispri);
	    if (errind != 0) {
		*lpscod = FALSE_;
		goto L290;
	    }
/* L220: */
	}
	if (! seteq_(&actsiz, actlps, explps)) {
	    *lpscod = FALSE_;
	    goto L290;
	}
/* L200: */
    }
    *lpscod = TRUE_;
L290:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* chkpst_ */

