/* c01004.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/* Subroutine */ int c01004_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int c01004_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int rclph_(void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    ifphcl_(integer *), enderr_(void), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rclph_();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), ifphcl_(), enderr_(), tstign_();
#endif /* NO_PROTO */

/*  C01004 tests the handling of error number 4: function requires */
/*  state (PHOP,WSCL,STCL,ARCL) when PHIGS is closed. */
    ifphcl_(useprm);
    setvs_("4", errinf_1.experr, &errinf_1.expsiz, 1L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    rclph_();
    L__1 = streq_("CCCC", 4L);
    tstign_(&L__1);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* c01004_ */

