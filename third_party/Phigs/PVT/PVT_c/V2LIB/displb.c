/* displb.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

#ifndef NO_PROTO
/* Subroutine */ int displb_(integer *samp, integer *start, integer *univ, 
	integer *subset)
#else /* NO_PROTO */
/* Subroutine */ int displb_(samp, start, univ, subset)
integer *samp, *start, *univ, *subset;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i, j, k, jj, ot, jci, kci, jlt, klt;
    static real jlw, klw;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind, maxloc, atrcnt, maxatr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static logical atrnew[3];
    static integer optatr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpplr (integer *, integer *, integer *, 
	    integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpplr ();
#endif /* NO_PROTO */

/*  DISPLB selects SAMP predefined bundles at random from the */
/*  polyline bundle table which are distinct in all their attributes. */
/*  If there are not SAMP completely distinct bundles, DISPLB tries */
/*  to maximize the number of different attributes. */

/*  Input parameters: */
/*    SAMP        : number of predefined bundles to be picked */
/*    START       : starting index */
/*    UNIV        : last element in universe to pick from */
/*  Output parameters: */
/*    SUBSET      : array containing the selected distinct bundles */
/*  total number of attributes */
    /* Parameter adjustments */
    --subset;

    /* Function Body */
    if (*univ + 1 - *start < *samp) {
#ifndef NO_PROTO
	unmsg_("Abort in DISPLB because size of universe is less than reques"
		"ted sample.", 71L);
#else /* NO_PROTO */
	unmsg_("Abort in DISPLB because size of universe is less than reques\
ted sample.", 71L);
#endif /* NO_PROTO */
    }
/*  OPTATR is the best possible number of attributes that can be distinct 
*/
    optatr = 3;
/*  this loop picks out samp elements */
    i__1 = *samp;
    for (i = 1; i <= i__1; ++i) {
/*  number of new attribute values so far */
	maxatr = -1;
/*  look at entire universe each time, starting at random location */
	j = rndint_(start, univ);
	i__2 = *univ;
	for (jj = *start; jj <= i__2; ++jj) {
	    if (j >= *univ) {
/*  cycle around to beginning */
		j = *start;
	    } else {
		++j;
	    }
	    for (ot = 1; ot <= 3; ++ot) {
		atrnew[ot - 1] = TRUE_;
/* L50: */
	    }
/*  get attributes of next candidate */
	    nqpplr (&dialog_1.specwt, &j, &errind, &jlt, &jlw, &jci);
	    chkinq_("pqpplr", &errind, 6L);
/*  check against all those picked so far; */
	    i__3 = i - 1;
	    for (k = 1; k <= i__3; ++k) {
/*  if already picked, get another j */
		if (j == subset[k]) {
		    goto L400;
		}
		nqpplr (&dialog_1.specwt, &subset[k], &errind, &klt, &klw, &
			kci);
		chkinq_("pqpplr", &errind, 6L);
/*  check all attributes */
		if (jlt == klt) {
		    atrnew[0] = FALSE_;
		}
		if (jlw == klw) {
		    atrnew[1] = FALSE_;
		}
		if (jci == kci) {
		    atrnew[2] = FALSE_;
		}
/* L300: */
	    }
/*  count # of trues */
	    atrcnt = 0;
	    for (ot = 1; ot <= 3; ++ot) {
		if (atrnew[ot - 1]) {
		    ++atrcnt;
		}
/* L75: */
	    }
/*  take the best so far */
	    if (atrcnt > maxatr) {
		maxatr = atrcnt;
		maxloc = j;
	    }
/*  cannot get better than OPTATR */
	    if (maxatr >= optatr) {
		goto L410;
	    }
L400:
	    ;
	}
/*  put best one on the list */
L410:
	subset[i] = maxloc;
/*  remember greatest number of distinct attributes */
	optatr = maxatr;
/* L500: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* displb_ */

