/* unmsg.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int unmsg_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int unmsg_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int abend_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int abend_();
#endif /* NO_PROTO */

/* UNMSG is used to generate messages for unanticipated errors */
/* which do not imply non-conformance of the implementation under test. */

/* It then forces a program abort. */
    abend_("UN", msg, 2L, msg_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* unmsg_ */

