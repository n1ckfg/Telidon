/* itrim.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
integer itrim_(char *word, ftnlen word_len)
#else /* NO_PROTO */
integer itrim_(word, word_len)
char *word;
ftnlen word_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_len(char *, ftnlen), s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_len(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer lw, ihi, ilo, imid;

/* itrim returns the position of the rightmost non-blank within */
/* a string, zero if all blank. */
    lw = i_len(word, word_len);
    ilo = 0;
    ihi = lw + 1;
/* do binary search looking for trailing blank portion of word */
L100:
    if (ihi - ilo <= 1) {
	goto L666;
    }
    imid = (ihi + ilo) / 2;
    if (s_cmp(word + (imid - 1), " ", word_len - (imid - 1), 1L) == 0) {
	ihi = imid;
    } else {
	ilo = imid;
    }
    goto L100;
L666:
    ret_val = ilo;
    return ret_val;
} /* itrim_ */

