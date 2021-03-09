/* dline.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int dline_(char *prompt, char *resp, ftnlen prompt_len, 
	ftnlen resp_len)
#else /* NO_PROTO */
/* Subroutine */ int dline_(prompt, resp, prompt_len, resp_len)
char *prompt, *resp;
ftnlen prompt_len;
ftnlen resp_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int iacans_(char *, ftnlen), iacmsg_(char *, 
	    ftnlen), opcomt_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int iacans_(), iacmsg_(), opcomt_();
#endif /* NO_PROTO */

/*  DLINE issues a prompt to the operator and gets a single line */
/*  character string response.  If the operator responds with */
/*  the escape character "@", DLINE allows entry of a non-committal */
/*  operator comment (neither pass nor fail), to be sent out as */
/*  an OP message, and then re-issues the original prompt. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*  Output parameters: */
/*    RESP        : answer from operator. */
L100:
    iacmsg_(prompt, prompt_len);
    iacans_(resp, resp_len);
/*  allow operator-requested comment. */
    if (s_cmp(resp, "@", resp_len, 1L) == 0) {
	opcomt_();
	goto L100;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dline_ */

