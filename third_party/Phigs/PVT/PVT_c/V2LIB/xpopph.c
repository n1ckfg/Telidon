/* xpopph.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"
#include "phigs.h"

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
/* Subroutine */ int xpopph_(integer *errprm, integer *memprm)
#else /* NO_PROTO */
/* Subroutine */ int xpopph_(errprm, memprm)
integer *errprm, *memprm;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nopph (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopph ();
#endif /* NO_PROTO */

/* XPOPPH serves to open PHIGS on the system under test. */

/* USERMOD If needed, insert implementation-dependent code before */
/* USERMOD opening PHIGS. */

    nopph (errprm, memprm);

#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* xpopph_ */

