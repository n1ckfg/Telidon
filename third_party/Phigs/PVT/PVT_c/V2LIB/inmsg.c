/* inmsg.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int inmsg_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int inmsg_(msg, msg_len)
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
    static char buf[900];
#ifndef NO_PROTO
    extern /* Subroutine */ int brdmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int brdmsg_();
#endif /* NO_PROTO */

/* INMSG is used to generate informational messages. */
/* Writing concatenation */
    i__1[0] = 4, a__1[0] = "IN: ";
    i__1[1] = msg_len, a__1[1] = msg;
    s_cat(buf, a__1, i__1, &c__2, 900L);
    brdmsg_(buf, 900L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* inmsg_ */

