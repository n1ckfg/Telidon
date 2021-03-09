/* csseq.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__50 = 50;
static integer c__0 = 0;

#ifndef NO_PROTO
logical csseq_(char *cssshd, ftnlen cssshd_len)
#else /* NO_PROTO */
logical csseq_(cssshd, cssshd_len)
char *cssshd;
ftnlen cssshd_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    logical ret_val;

    /* Local variables */
    static integer ir, iel, ish, iel1, iel2, idum, root[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int set2d_(char *, integer *, integer *, integer *
	    , integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int set2d_();
#endif /* NO_PROTO */
    static integer ipath;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpde (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqpde ();
#endif /* NO_PROTO */
    static integer strid, ixpth, nroot;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer ndpath;
    static logical single;
    static integer erpath[100]	/* was [2][50] */, errind, pathln[50], pathsh[
	    2500]	/* was [50][50] */, apthsz, numpth;
#ifndef NO_PROTO
    extern /* Subroutine */ int gtroot_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int gtroot_();
#endif /* NO_PROTO */

/*  CSSEQ accepts a character string parameter (cssshd = "CSS */
/*  should") which describes a CSS network and compares it to the CSS */
/*  state as reported by PHIGS inquire functions.  Csseq returns */
/*  .true. if they are equal, else .false.  The syntax of the input */
/*  string is: */
/*  cssshd             = path-list | blank */
/*  path-list          = path slash | path slash path-list */
/*  path               = path-element | path-element comma path */
/*  path-element       = structure-id comma element-reference */
/*  comma              = "," */
/*  slash              = "/" */
/*  blank              = " " */
/*  structure-id       = unsigned-integer */
/*  element-reference  = unsigned-integer */
/*  Spaces may appear anywhere. */
/*  Eg:  2,0/ */
/*       2,3,4,0/ */
/*       2, 3, 4, 0 / 2, 3, 5, 0 / 2, 3, 6, 0  / */
/*       20,0/30,0/40,0/ */
/*       20,0/30,1,50,0/40,0/ */
/*  If the CSS contains two networks: */

/*            10              110 */
/*           /  \              | */
/*         20   30            120 */
/*        /  \ / */
/*       40   50 */

/*  it could be represented by: */
/*     "10,1,20,1,40,0/  10,1,20,2,50,0/  10,2,30,1,50,0/  110,3,120,0/" 
*/
/*  A blank cssshd indicates an empty CSS */
/* truncation method */
/* interpret cssshd string into ragged 2D array of integers. */
    set2d_(cssshd, &c__50, &numpth, pathln, pathsh, cssshd_len);
/* now get all roots */
    gtroot_(&nroot, root);
/* Get all descendant paths of each root */
    i__1 = nroot;
    for (ir = 1; ir <= i__1; ++ir) {
/* structure ID of next root */
	strid = root[ir - 1];
/* ndpath = how many descendant paths ? */
	nqpde (&strid, &c__0, &c__0, &c__50, &c__0, &errind, &ndpath, &idum, 
		erpath);
	chkinq_("pqpde", &errind, 5L);
/* for singleton root, gotta force path of length 1 */
	single = ndpath == 0;
	if (single) {
	    ndpath = 1;
	}
/* retrieve each descendant path */
	i__2 = ndpath;
	for (ixpth = 1; ixpth <= i__2; ++ixpth) {
	    if (single) {
		apthsz = 1;
		erpath[0] = strid;
		erpath[1] = 0;
	    } else {
		nqpde (&strid, &c__0, &c__0, &c__50, &ixpth, &errind, &idum, &
			apthsz, erpath);
		chkinq_("pqpde", &errind, 5L);
	    }
/* look for a matching should-path */
	    i__3 = numpth;
	    for (ish = 1; ish <= i__3; ++ish) {
/* - start by seeking matching length */
		if (apthsz << 1 != pathln[ish - 1]) {
		    goto L500;
		}
/* lengths match - try contents */
		i__4 = apthsz;
		for (iel = 1; iel <= i__4; ++iel) {
		    iel2 = iel << 1;
		    iel1 = iel2 - 1;
		    if (pathsh[iel1 + ish * 50 - 51] != erpath[(iel << 1) - 2]
			    ) {
			goto L500;
		    }
		    if (pathsh[iel2 + ish * 50 - 51] != erpath[(iel << 1) - 1]
			    ) {
			goto L500;
		    }
/* L600: */
		}
/* OK they matched - delete out that should-path to prevent re
-use */
		pathln[ish - 1] = -1;
		goto L400;
L500:
		;
	    }
/* No should-path match found for path reported by PHIGS - fail */

	    ret_val = FALSE_;
	    return ret_val;
/* next descendant path from current root */
L400:
	    ;
	}
/* next root structure */
/* L300: */
    }
/* match has been found for every path returned by pqpde. */
/* Now, simply check that all expected paths have been "used" by CSS */
    i__1 = numpth;
    for (ipath = 1; ipath <= i__1; ++ipath) {
	if (pathln[ipath - 1] != -1) {
	    ret_val = FALSE_;
	    return ret_val;
	}
/* L700: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* csseq_ */

