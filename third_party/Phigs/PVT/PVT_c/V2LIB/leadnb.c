/* leadnb.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
integer leadnb_(char *txt, ftnlen txt_len)
#else /* NO_PROTO */
integer leadnb_(txt, txt_len)
char *txt;
ftnlen txt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_len();
#endif /* NO_PROTO */

    /* Local variables */
    static integer hi, lo, mid;

/*  LEADNB returns the character position of the first (leftmost) */
/*  non-blank character within TXT.  If there is none, 0 is returned. */
    if (s_cmp(txt, " ", txt_len, 1L) == 0) {
	ret_val = 0;
	return ret_val;
    }
/*  LO always points to a location *before* the first non-blank, */
/*  HI to a location *at or after* the first non-blank. */
    lo = 0;
    hi = i_len(txt, txt_len);
L100:
    if (hi - lo <= 1) {
	goto L666;
    }
    mid = (hi + lo) / 2;
    if (s_cmp(txt, " ", mid, 1L) == 0) {
	lo = mid;
    } else {
	hi = mid;
    }
    goto L100;
L666:
    ret_val = hi;
    return ret_val;
} /* leadnb_ */

