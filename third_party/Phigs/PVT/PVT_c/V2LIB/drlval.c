/* drlval.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int drlval_(char *prompt, real *ans, ftnlen prompt_len)
#else /* NO_PROTO */
/* Subroutine */ int drlval_(prompt, ans, prompt_len)
char *prompt;
real *ans;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[100];
    static integer ierr;
    static char resp[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen), 
	    prsrl_(char *, real *, integer *, ftnlen), opmsgw_(char *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_(), prsrl_(), opmsgw_();
#endif /* NO_PROTO */

/*  DRLVAL is used to get a real-number response from the operator. */

/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*  Output parameters: */
/*    ANS         : valid answer from operator. */
L110:
/*  display prompt and get response string */
    dline_(prompt, resp, prompt_len, 100L);
    if (s_cmp(resp, " ", 100L, 1L) == 0) {
	s_copy(msg, "Response must be non-blank.", 100L, 27L);
    } else {
	prsrl_(resp, ans, &ierr, 100L);
	if (ierr == 0) {
	    s_copy(msg, "OK", 100L, 2L);
	} else {
	    s_copy(msg, "Response not a real number.", 100L, 27L);
	}
    }
    if (s_cmp(msg, "OK", 100L, 2L) == 0) {
/*        OK - do nothing */
    } else {
/*  show error message in dialogue area and pause */
	opmsgw_(msg, 100L);
	goto L110;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drlval_ */

