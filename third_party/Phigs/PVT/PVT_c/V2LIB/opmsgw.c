/* opmsgw.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int opmsgw_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int opmsgw_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static char pmsg[999], resp[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_();
    extern integer itrim_();
#endif /* NO_PROTO */

/*  OPMSGW sends a character string (MSG) to the operator in */
/*  accordance with DOUTYP.  It then waits for a response, to ensure */
/*  that the message has been read. */
/* Writing concatenation */
    i__1[0] = itrim_(msg, msg_len), a__1[0] = msg;
    i__1[1] = 29, a__1[1] = "  Enter anything to continue.";
    s_cat(pmsg, a__1, i__1, &c__2, 999L);
    dline_(pmsg, resp, 999L, 80L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opmsgw_ */

