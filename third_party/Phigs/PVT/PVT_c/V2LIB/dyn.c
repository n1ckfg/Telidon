/* dyn.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
logical dyn_(char *prompt, ftnlen prompt_len)
#else /* NO_PROTO */
logical dyn_(prompt, prompt_len)
char *prompt;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);

#endif /* not NO_PROTO */
    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_();
    extern integer itrim_();
#endif /* NO_PROTO */
    static char linein[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int opmsgw_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opmsgw_();
#endif /* NO_PROTO */
    static char msgtxt[3000];

/*  DYN is used to ask the operator a yes/no question and return */
/*  a logical value as a result: .true. for yes, .false. for no. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*  display prompt */
/* Writing concatenation */
    i__1[0] = itrim_(prompt, prompt_len), a__1[0] = prompt;
    i__1[1] = 9, a__1[1] = " (y or n)";
    s_cat(msgtxt, a__1, i__1, &c__2, 3000L);
L100:
    dline_(msgtxt, linein, 3000L, 100L);
    if (s_cmp(linein, "Y", 100L, 1L) == 0 || s_cmp(linein, "y", 100L, 1L) == 
	    0) {
	ret_val = TRUE_;
    } else if (s_cmp(linein, "N", 100L, 1L) == 0 || s_cmp(linein, "n", 100L, 
	    1L) == 0) {
	ret_val = FALSE_;
    } else {
/*  show error message in dialogue area and pause */
	opmsgw_("Response must be y or n.", 24L);
	goto L100;
    }
    return ret_val;
} /* dyn_ */

