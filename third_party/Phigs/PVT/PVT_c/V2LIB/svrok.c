/* svrok.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical svrok_(integer *wkid, char *expvls, ftnlen expvls_len)
#else /* NO_PROTO */
logical svrok_(wkid, expvls, expvls_len)
integer *wkid;
char *expvls;
ftnlen expvls_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char svrcod[1*3] = "c" "d" "s";
#else /* NO_PROTO */
    static char svrcod[1*3+1] = "cds";
#endif /* NO_PROTO */

    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_indx();
#endif /* NO_PROTO */

    /* Local variables */
    static integer idum1, idum2, idum3;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdus (integer *, integer *, integer *, 
	    integer *, integer *, integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdus (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, actsvr;

/*  SVROK: true iff current SVR is one of the expected values, */
/*  encoded by character: c-correct, s-simulated, d-deferred. */
/*  E.g. expvls = 'cd' means SVR must be either CORRECT or */
/*  DEFERRED. */
/* state of visual representation */
/*                correct    deferred    simulated */
    nqdus (wkid, &errind, &idum1, &idum2, &idum3, &actsvr);
    chkinq_("pqdus", &errind, 5L);
    ret_val = i_indx(expvls, svrcod + actsvr, expvls_len, 1L) > 0;
    return ret_val;
} /* svrok_ */

