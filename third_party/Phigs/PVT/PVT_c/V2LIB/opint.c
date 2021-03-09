/* opint.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int opint_(integer *ians)
#else /* NO_PROTO */
/* Subroutine */ int opint_(ians)
integer *ians;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static char cans[40];
    static integer ierr;
#ifndef NO_PROTO
    extern /* Subroutine */ int oplin_(char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int opmsg_(char *, ftnlen);
    extern integer leadnb_(char *, ftnlen);
    extern /* Subroutine */ int prsint_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int oplin_();
    extern integer itrim_();
    extern /* Subroutine */ int opmsg_();
    extern integer leadnb_();
    extern /* Subroutine */ int prsint_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/*  OPINT gets an integer response from the operator. */
L10:
    oplin_(cans, 40L);
    if (s_cmp(cans, " ", 40L, 1L) == 0) {
	opmsg_("Response must be a non-blank valid integer.  Re-enter.", 54L);

	goto L10;
    }
    i__1 = leadnb_(cans, 40L) - 1;
    prsint_(cans + i__1, ians, &ierr, itrim_(cans, 40L) - i__1);
    if (ierr != 0) {
	opmsg_("Response must be a non-blank valid integer.  Re-enter.", 54L);

	goto L10;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opint_ */

