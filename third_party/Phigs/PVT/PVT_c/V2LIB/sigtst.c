/* sigtst.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/* Subroutine */ int sigtst_(integer *expsig, logical *failed)
#else /* NO_PROTO */
/* Subroutine */ int sigtst_(expsig, failed)
integer *expsig;
logical *failed;
#endif /* NO_PROTO */
{
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), pass_(void), inmsg_(char *, 
	    ftnlen), sigmsg_(integer *, char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_(), inmsg_(), sigmsg_();
#endif /* NO_PROTO */

/*  Sigtst is used to compare an signalled error code with an expected */
/*  value.  If not equal, failure and informative messages are generated, 
*/
/*  including the error code and function name.  If equal, pass is */
/*  invoked. */
/*  Input parameter: */
/*    EXPSIG : expected value of error code (usually 0) */
/*  Output parameter */
/*    FAILED : true if expected not equal to actual, else false */
    if (*expsig == globnu_1.errsig) {
	*failed = FALSE_;
	pass_();
    } else {
	*failed = TRUE_;
	fail_();
	sigmsg_(&globnu_1.errsig, globch_1.funcid, msg, 80L, 300L);
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* sigtst_ */

