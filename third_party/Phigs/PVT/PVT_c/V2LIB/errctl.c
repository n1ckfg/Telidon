/* errctl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw, 
	    errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[
	    20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_

struct {
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

#ifndef NO_PROTO
/* Subroutine */ int errctl_(logical *locctl)
#else /* NO_PROTO */
/* Subroutine */ int errctl_(locctl)
logical *locctl;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

/*  Errctl is called by test programs to control whether or not perhnd */
/*  should handle signalled errors and abort (locctl = .false.) or rather 
*/
/*  should simply return error information (locctl = .true.) in the */
/*  COMMON variables errsig and funcid. */
/* Should there be local control over signalled errors? */
    if (*locctl) {
	globnu_1.ctlhnd = 1;
	globnu_1.errsig = 0;
	s_copy(globch_1.funcid, " ", 80L, 1L);
    } else {
	globnu_1.ctlhnd = 0;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* errctl_ */

