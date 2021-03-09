/* dstrng.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int dstrng_(char *prompt, char *resp, ftnlen prompt_len, 
	ftnlen resp_len)
#else /* NO_PROTO */
/* Subroutine */ int dstrng_(prompt, resp, prompt_len, resp_len)
char *prompt, *resp;
ftnlen prompt_len;
ftnlen resp_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp(), i_len();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int iacans_(char *, ftnlen), iacmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int iacans_(), iacmsg_();
#endif /* NO_PROTO */
    static char linein[200];
    static integer nxtpos;

/*  DSTRNG is used to get possibly multi-line character string */
/*  response from the operator.  Operator response is terminated */
/*  by a single "." on a line.  This termination line is not */
/*  included in the response. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*  Output parameters: */
/*    RESP        : answer from operator. */
/*  display prompt */
    iacmsg_(prompt, prompt_len);
    nxtpos = 1;
    s_copy(resp, " ", resp_len, 1L);
L100:
/*  get response string */
    iacans_(linein, 200L);
    if (s_cmp(linein, ".", 200L, 1L) == 0) {
	goto L200;
    }
/*  append last line to non-blank stuff in RESP */
    s_copy(resp + (nxtpos - 1), linein, resp_len - (nxtpos - 1), 200L);
    nxtpos = itrim_(resp, resp_len) + 2;
/*  check if at or near overflow ... */
    if (nxtpos + 5 < i_len(resp, resp_len)) {
	goto L100;
    }
L200:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* dstrng_ */

