/* oplin.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int oplin_(char *ans, ftnlen ans_len)
#else /* NO_PROTO */
/* Subroutine */ int oplin_(ans, ans_len)
char *ans;
ftnlen ans_len;
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_800[] = "(a)";

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);
#else /* NO_PROTO */
    integer s_rsfe(), do_fio(), e_rsfe();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 5, 0, fmt_800, 0 };


/*  OPLIN gets a single-line response from the operator. */
    s_rsfe(&io___1);
    do_fio(&c__1, ans, ans_len);
    e_rsfe();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* oplin_ */

