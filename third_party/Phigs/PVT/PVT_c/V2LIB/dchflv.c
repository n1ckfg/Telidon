/* dchflv.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

#ifndef NO_PROTO
logical dchflv_(char *prompt, integer *maxval, integer *truans, ftnlen 
	prompt_len)
#else /* NO_PROTO */
logical dchflv_(prompt, maxval, truans, prompt_len)
char *prompt;
integer *maxval, *truans;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer ans;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), dchoic_(char *, integer *, 
	    integer *, integer *, ftnlen), opfail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), dchoic_(), opfail_();
#endif /* NO_PROTO */

/*  DCHFLV operates just like DCHFL, except that the response is */
/*  tested directly against TRUANS. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    MAXVAL      : highest valid response. */
/*    TRUANS      : expected value from operator. */
    dchoic_(prompt, &c__0, maxval, &ans, prompt_len);
    ret_val = ans != *truans;
    if (ans == 0) {
	opfail_();
    } else if (ret_val) {
	fail_();
    }
    return ret_val;
} /* dchflv_ */

