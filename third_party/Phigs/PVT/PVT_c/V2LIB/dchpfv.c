/* dchpfv.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int dchpfv_(char *prompt, integer *maxval, integer *truans, 
	ftnlen prompt_len)
#else /* NO_PROTO */
/* Subroutine */ int dchpfv_(prompt, maxval, truans, prompt_len)
char *prompt;
integer *maxval, *truans;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Local variables */
    static integer ans;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), dchoic_(char *, integer *, 
	    integer *, integer *, ftnlen), opfail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), dchoic_(), opfail_();
#endif /* NO_PROTO */

/*  DCHPFV operates just like DCHPF, except that the response is */
/*  tested directly against TRUANS. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    MAXVAL      : highest valid response. */
/*    TRUANS      : expected value from operator. */
    dchoic_(prompt, &c__0, maxval, &ans, prompt_len);
    if (ans == 0) {
	opfail_();
    } else {
	L__1 = ans == *truans;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dchpfv_ */

