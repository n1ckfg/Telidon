/* dynpf.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int dynpf_(char *prompt, char *expctd, ftnlen prompt_len, 
	ftnlen expctd_len)
#else /* NO_PROTO */
/* Subroutine */ int dynpf_(prompt, expctd, prompt_len, expctd_len)
char *prompt, *expctd;
ftnlen prompt_len;
ftnlen expctd_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    char ch__1[34];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern logical dyn_();
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static logical expy;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), opfail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), opfail_();
#endif /* NO_PROTO */

/*  DYNPF is used to ask the operator a yes/no question and issue pass */
/*  or fail as a result.  If the answer indicates failure, the operator */

/*  is given the opportunity to comment. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    EXPCTD      : expected answer (to pass) - must be y or n */
    if (*expctd == 'Y' || *expctd == 'y') {
	expy = TRUE_;
    } else if (*expctd == 'N' || *expctd == 'n') {
	expy = FALSE_;
    } else {
/* Writing concatenation */
	i__1[0] = 33, a__1[0] = "DYNPF called with invalid value: ";
	i__1[1] = 1, a__1[1] = expctd;
	s_cat(ch__1, a__1, i__1, &c__2, 34L);
	unmsg_(ch__1, 34L);
    }
    if (expy == dyn_(prompt, prompt_len)) {
	pass_();
    } else {
	opfail_();
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dynpf_ */

