/* dchfl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

#ifndef NO_PROTO
logical dchfl_(char *prompt, integer *maxval, integer *truans, integer *perm, 
	ftnlen prompt_len)
#else /* NO_PROTO */
logical dchfl_(prompt, maxval, truans, perm, prompt_len)
char *prompt;
integer *maxval, *truans, *perm;
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

/*  DCHFL gets an integer response from the operator, to be used as */
/*  an index into PERM, and, if the result is incorrect, issues fail */
/*  and returns TRUE.  If correct, it returns FALSE, but does not */
/*  issue pass. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    MAXVAL      : highest valid response. */
/*    TRUANS      : expected value from operator. */
/*    PERM        : permutation of 1-MAXVAL, used to randomize prompt. */
    /* Parameter adjustments */
    --perm;

    /* Function Body */
    dchoic_(prompt, &c__0, maxval, &ans, prompt_len);
    if (ans == 0) {
	ret_val = TRUE_;
	opfail_();
    } else {
	if (perm[ans] == *truans) {
	    ret_val = FALSE_;
	} else {
	    ret_val = TRUE_;
	    fail_();
	}
    }
    return ret_val;
} /* dchfl_ */

