/* gtroot.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__50 = 50;

#ifndef NO_PROTO
/* Subroutine */ int gtroot_(integer *iroot, integer *root)
#else /* NO_PROTO */
/* Subroutine */ int gtroot_(iroot, root)
integer *iroot, *root;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer idum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpan (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqsid (integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpan (), nqsid ();
#endif /* NO_PROTO */
    static integer idstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer ixstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, erpath[100]	/* was [2][50] */, nanpth, totstr;

/*  gtroot gets all identifiers for root structures in the CSS and */
/*  returns them in the array root.  Iroot contains the number */
/*  of roots found. */
/* truncation method */
/* totstr = how many structures? */
    /* Parameter adjustments */
    --root;

    /* Function Body */
    nqsid (&c__0, &errind, &totstr, &idum);
    chkinq_("pqsid", &errind, 5L);
/* number of roots so far */
    *iroot = 0;
/* go thru all the structures, looking for roots */
    i__1 = totstr;
    for (ixstr = 1; ixstr <= i__1; ++ixstr) {
/* idstr = next structure ID to check for rootedness */
	nqsid (&ixstr, &errind, &idum, &idstr);
	chkinq_("pqsid", &errind, 5L);
/* is idstr a root?  Ie, how many ancestor paths (nanpth) are there? 
*/
	nqpan (&idstr, &c__1, &c__1, &c__50, &c__0, &errind, &nanpth, &idum, 
		erpath);
	chkinq_("pqpan", &errind, 5L);
/* if there are ancestor paths, then this is NOT a root. */
	if (nanpth > 0) {
	    goto L200;
	}
/* check overflow */
	if (*iroot >= 50) {
	    unmsg_("Number of roots found by GTROOT exceeds maximum.", 48L);
	} else {
	    ++(*iroot);
	    root[*iroot] = idstr;
	}
L200:
	;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* gtroot_ */

