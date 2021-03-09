/* tstign.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int tstign_(logical *ignore)
#else /* NO_PROTO */
/* Subroutine */ int tstign_(ignore)
logical *ignore;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
    extern integer itrim_();
#endif /* NO_PROTO */
    static char funnam[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int erfunm_(integer *, char *, ftnlen), setmsg_(
	    char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int erfunm_(), setmsg_();
#endif /* NO_PROTO */

/*  TSTIGN is used to test that a function signalling an error is */
/*  ignored. */
/*  Input parameters: */
/*   IGNORE : logical variable indicating whether the function was ignored
*/
    erfunm_(&errinf_1.efid[errinf_1.efcnt - 1], funnam, 80L);
/* Writing concatenation */
    i__1[0] = 3, a__1[0] = "If ";
    i__1[1] = 80, a__1[1] = funnam;
    s_cat(msg, a__1, i__1, &c__2, 300L);
    i__2 = itrim_(msg, 300L) + 1;
/* Writing concatenation */
    i__1[0] = 25, a__1[0] = "signals an error because ";
    i__1[1] = 200, a__1[1] = errchr_1.curcon;
    s_cat(msg + i__2, a__1, i__1, &c__2, 300 - i__2);
    i__2 = itrim_(msg, 300L);
    s_copy(msg + i__2, ", it should not cause any other effect.", 300 - i__2, 
	    39L);
    setmsg_(errchr_1.errsrs, msg, 40L, 300L);
    ifpf_(ignore);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstign_ */

