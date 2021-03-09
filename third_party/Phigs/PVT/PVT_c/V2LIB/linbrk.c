/* linbrk.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int linbrk_(char *msgtxt, integer *dtclim, integer *err, 
	integer *numlin, integer *linpos, ftnlen msgtxt_len)
#else /* NO_PROTO */
/* Subroutine */ int linbrk_(msgtxt, dtclim, err, numlin, linpos, msgtxt_len)
char *msgtxt;
integer *dtclim, *err, *numlin, *linpos;
ftnlen msgtxt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer stlin;
#ifndef NO_PROTO
    extern integer leadnb_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer leadnb_();
#endif /* NO_PROTO */
    static integer lenmsg, nxtpos;

/*  LINBRK calculates starting positions within a character string so */
/*  as to break it up into lines of at most DTCLIM characters. LINBRK */
/*  tries to break lines only on blanks, and it constructs the */
/*  longest line possible within the DTCLIM limit.  It returns the */
/*  number of lines in NUMLIN, and the starting positions within */
/*  LINPOS.  An "extra" position is calculated after the last line, */
/*  pointing just beyond the last non-blank, so that the location of */
/*  the end of the last line is available.  If a single word */
/*  (contiguous non-blanks) is longer than DTCLIM, it is broken up */
/*  after DTCLIM characters, and ERR is set to 1. */
/*  Input parameters: */
/*    MSGTXT : character string to be broken up */
/*    DTCLIM : maximum number of characters in each chunk */
/*  Output parameters: */
/*    ERR    : error code: 0 if OK, 1 if line overflow */
/*    NUMLIN : number of logical lines found in MSGTXT */
/*    LINPOS : array of starting positions of lines within MSGTXT */
    /* Parameter adjustments */
    --linpos;

    /* Function Body */
    *err = 0;
    *numlin = 0;
    if (s_cmp(msgtxt, " ", msgtxt_len, 1L) == 0) {
	return 0;
    }
    lenmsg = itrim_(msgtxt, msgtxt_len);
    nxtpos = 1;
L100:
/*  seek next non-blank */
    stlin = leadnb_(msgtxt + (nxtpos - 1), msgtxt_len - (nxtpos - 1));
/*  get absolute position of line-starting non-blank */
    stlin = stlin + nxtpos - 1;
/*  record starting position */
    ++(*numlin);
    linpos[*numlin] = stlin;
/*  any non-blanks beyond this line? */
    if (lenmsg - stlin < *dtclim) {
	linpos[*numlin + 1] = lenmsg + 1;
	return 0;
    }
    i__1 = stlin;
    for (nxtpos = stlin + *dtclim; nxtpos >= i__1; --nxtpos) {
	if (msgtxt[nxtpos - 1] == ' ') {
	    goto L100;
	}
/* L200: */
    }
/*  no space within line */
    *err = 1;
    nxtpos = stlin + *dtclim;
    goto L100;
} /* linbrk_ */

