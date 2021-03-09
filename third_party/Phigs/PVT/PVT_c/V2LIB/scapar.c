/* scapar.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int scapar_(integer *dtclim, real *chwrat, real *dyxrat, 
	integer *numlin, integer *linpos, real *chht, real *loghw)
#else /* NO_PROTO */
/* Subroutine */ int scapar_(dtclim, chwrat, dyxrat, numlin, linpos, chht, 
	loghw)
integer *dtclim;
real *chwrat, *dyxrat;
integer *numlin, *linpos;
real *chht, *loghw;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
    static real loght, logwid;

/*  SCAPAR calculates the needed scaling factor and logical */
/*  height/width ratio of a paragraph, given a line break-up. */
/*  Input parameters: */
/*    DTCLIM : maximum number of characters per line */
/*    CHWRAT : desired height/width ratio of each character */
/*    DYXRAT : height/width ratio of paragraph area */
/*    NUMLIN : number of logical lines in paragraph */
/*    LINPOS : array of starting positions of lines within MSGTXT */
/*  Output parameters: */
/*    CHHT   : resulting character height */
/*    LOGHW  : logical height/width ratio of resulting paragraph */
    /* Parameter adjustments */
    --linpos;

    /* Function Body */
    if (*numlin > 1) {
	logwid = (real) (*dtclim);
    } else {
	logwid = (real) (linpos[2] - 1);
    }
    loght = *numlin * *chwrat;
    *loghw = loght / logwid;
/*  1/LOGWID takes effect for a "full" multi-line paragraph. */
/* DYXRAT/LOGHT takes effect for a partially-filled single-line paragraph.
*/
/* Computing MIN */
    r__1 = 1 / logwid, r__2 = *dyxrat / loght;
    *chht = dmin(r__1,r__2);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* scapar_ */

