/* ifphcl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

#ifndef NO_PROTO
/* Subroutine */ int ifphcl_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int ifphcl_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int nclph (void), esetup_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclph (), esetup_();
#endif /* NO_PROTO */

/*  IFPHCL initializes things for the special case where error */
/*  handling is to be tested in the state where PHIGS is closed. */
/*  This requires special handling, since ordinarily the error */
/*  file will not be available for writing. */
/*  Input parameters: */
/*    USEPRM : Handling mode: 1 for user, 2 for system */
    s_copy(errchr_1.curcon, "PHIGS is closed", 200L, 15L);
/*  add 2 to "normal" USRERR value to signify PHCL */
    i__1 = *useprm + 2;
    esetup_(&i__1);
    nclph ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ifphcl_ */

