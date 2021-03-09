/* surfok.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical surfok_(integer *wkid, integer *expsur)
#else /* NO_PROTO */
logical surfok_(wkid, expsur)
integer *wkid, *expsur;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdus (integer *, integer *, integer *, 
	    integer *, integer *, integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdus (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, actsur;

/*  SURFOK: true iff display surface flag equals expected value. */
    nqdus (wkid, &errind, &idum1, &idum2, &actsur, &idum3);
    chkinq_("pqdus", &errind, 5L);
    ret_val = actsur == *expsur;
    return ret_val;
} /* surfok_ */

