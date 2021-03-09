/* ichkz.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int ichkz_(integer *cerind, integer *funcid)
#else /* NO_PROTO */
/* Subroutine */ int ichkz_(cerind, funcid)
integer *cerind, *funcid;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2, i__3;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    /* Subroutine */ int s_cat(), s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char msg[160];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_();
#endif /* NO_PROTO */
    static char tmsg[500], acode[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nfunm_(integer *, 
	    char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nfunm_();
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static char funnam[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___5 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___6 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___8 = { 0, msg, 0, "(A,I6.3,A)", 160, 1 };


/*  ICHKZ does post-processing after an error-indicator function has */
/*  been called. */
/*  Input parameters: */
/*    CERIND: actual error indicator returned by function */
/*    FUNCID: numeric identifier of function that returned error indicator
 */
    if (errinf_1.expsiz < 1) {
	unmsg_("ICHKZ is called with invalid EXPSIZ.", 36L);
    }
/*  set up test message */
    nfunm_(funcid, funnam, 80L);
/* Writing concatenation */
    i__1[0] = 3, a__1[0] = "If ";
    i__1[1] = 80, a__1[1] = funnam;
    s_cat(tmsg, a__1, i__1, &c__2, 500L);
    i__2 = itrim_(tmsg, 500L) + 1;
/* Writing concatenation */
    i__1[0] = 14, a__1[0] = "is called and ";
    i__1[1] = 200, a__1[1] = errchr_1.curcon;
    s_cat(tmsg + i__2, a__1, i__1, &c__2, 500 - i__2);
    i__2 = itrim_(tmsg, 500L);
    s_copy(tmsg + i__2, ", it should return error indicator = ", 500 - i__2, 
	    37L);
/*  may be several valid error code possibilities */
    i__2 = errinf_1.expsiz - 1;
    for (ix = 1; ix <= i__2; ++ix) {
	s_wsfi(&io___5);
	do_fio(&c__1, (char *)&errinf_1.experr[ix - 1], (ftnlen)sizeof(
		integer));
	e_wsfi();
	i__3 = itrim_(tmsg, 500L) + 1;
/* Writing concatenation */
	i__1[0] = 4, a__1[0] = acode;
	i__1[1] = 1, a__1[1] = ",";
	s_cat(tmsg + i__3, a__1, i__1, &c__2, 500 - i__3);
/* L50: */
    }
    if (errinf_1.expsiz >= 2) {
	i__2 = itrim_(tmsg, 500L) - 1;
	s_copy(tmsg + i__2, " or ", 500 - i__2, 4L);
    }
    s_wsfi(&io___6);
    do_fio(&c__1, (char *)&errinf_1.experr[errinf_1.expsiz - 1], (ftnlen)
	    sizeof(integer));
    e_wsfi();
    i__2 = itrim_(tmsg, 500L) + 1;
/* Writing concatenation */
    i__1[0] = 4, a__1[0] = acode;
    i__1[1] = 1, a__1[1] = ".";
    s_cat(tmsg + i__2, a__1, i__1, &c__2, 500 - i__2);
    setmsg_(errchr_1.errsrs, tmsg, 40L, 500L);
    if (iarfnd_(cerind, &errinf_1.expsiz, errinf_1.experr) > 0) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___8);
	do_fio(&c__1, "Reported error indicator ", 25L);
	do_fio(&c__1, (char *)&(*cerind), (ftnlen)sizeof(integer));
	do_fio(&c__1, " is not one of the expected values.", 35L);
	e_wsfi();
	inmsg_(msg, 160L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ichkz_ */

