/* setpcl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int setpcl_(char *pcctab, ftnlen pcctab_len)
#else /* NO_PROTO */
/* Subroutine */ int setpcl_(pcctab, pcctab_len)
char *pcctab;
ftnlen pcctab_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

/*  SETPCL: loads the pcctab table with the names of the picture */
/*  change categories. */
    /* Parameter adjustments */
    pcctab -= 34;

    /* Function Body */
    s_copy(pcctab + 34, "polyline bundle representation", 34L, 30L);
    s_copy(pcctab + 68, "polymarker bundle representation", 34L, 32L);
    s_copy(pcctab + 102, "text bundle representation", 34L, 26L);
    s_copy(pcctab + 136, "interior bundle representation", 34L, 30L);
    s_copy(pcctab + 170, "edge bundle representation", 34L, 26L);
    s_copy(pcctab + 204, "pattern representation", 34L, 22L);
    s_copy(pcctab + 238, "colour representation", 34L, 21L);
    s_copy(pcctab + 272, "view representation", 34L, 19L);
    s_copy(pcctab + 306, "workstation transformation", 34L, 26L);
    s_copy(pcctab + 340, "highlighting filter", 34L, 19L);
    s_copy(pcctab + 374, "invisibility filter", 34L, 19L);
    s_copy(pcctab + 408, "HLHSR mode", 34L, 10L);
    s_copy(pcctab + 442, "structure content", 34L, 17L);
    s_copy(pcctab + 476, "post structure", 34L, 14L);
    s_copy(pcctab + 510, "unpost structure", 34L, 16L);
    s_copy(pcctab + 544, "delete structure", 34L, 16L);
    s_copy(pcctab + 578, "reference modification", 34L, 22L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setpcl_ */

