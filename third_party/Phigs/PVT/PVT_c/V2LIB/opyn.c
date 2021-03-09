/* opyn.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int opyn_(char *prompt, char *ans, ftnlen prompt_len, ftnlen 
	ans_len)
#else /* NO_PROTO */
/* Subroutine */ int opyn_(prompt, ans, prompt_len, ans_len)
char *prompt, *ans;
ftnlen prompt_len;
ftnlen ans_len;
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_800[] = "(a)";

    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    integer s_rsfe(), do_fio(), e_rsfe();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);


#endif /* not NO_PROTO */
    /* Local variables */
    static char buf[132];
#ifndef NO_PROTO
    extern /* Subroutine */ int opmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opmsg_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 5, 0, fmt_800, 0 };


/* opyn gets a yes or no reply from operator - encoded as y or n. */
/* L800: */
L100:
/* Writing concatenation */
    i__1[0] = prompt_len, a__1[0] = prompt;
    i__1[1] = 9, a__1[1] = " (y or n)";
    s_cat(buf, a__1, i__1, &c__2, 132L);
    opmsg_(buf, 132L);
    s_rsfe(&io___2);
    do_fio(&c__1, ans, 1L);
    e_rsfe();
    if (*ans == 'y' || *ans == 'n') {
	return 0;
    }
    opmsg_("Response must be y or n.", 24L);
    goto L100;
} /* opyn_ */

