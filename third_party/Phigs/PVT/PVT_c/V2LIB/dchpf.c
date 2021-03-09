/* dchpf.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int dchpf_(char *prompt, integer *maxval, integer *truans, 
	integer *perm, ftnlen prompt_len)
#else /* NO_PROTO */
/* Subroutine */ int dchpf_(prompt, maxval, truans, perm, prompt_len)
char *prompt;
integer *maxval, *truans, *perm;
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

/*  DCHPF gets an integer response from the operator, to be used as */
/*  an index into PERM, and issues pass/fail as a result.  In all */
/*  cases the operator is given a choice between 0 and MAXVAL, where */
/*  0 indicates "none of the above" and triggers an operator comment. */
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
	opfail_();
    } else {
	L__1 = perm[ans] == *truans;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dchpf_ */

