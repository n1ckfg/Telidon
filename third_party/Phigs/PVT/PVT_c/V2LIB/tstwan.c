/* tstwan.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/* Subroutine */ int tstwan_(logical *warnin, char *wanact, ftnlen wanact_len)

#else /* NO_PROTO */
/* Subroutine */ int tstwan_(warnin, wanact, wanact_len)
logical *warnin;
char *wanact;
ftnlen wanact_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;
    char ch__1[363];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp(), i_indx();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static char wbuf[300];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static char funnam[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int erfunm_(integer *, char *, ftnlen), setmsg_(
	    char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int erfunm_(), setmsg_();
#endif /* NO_PROTO */

/*  TSTWAN is used to test that functions which issue a warning */
/*  take the correct action. */
/*  Input parameters: */
/*    WARNIN : logical variable indicating whether the function took */
/*             the correct action */
/*    WANACT : description of correct action */
    s_copy(wbuf, wanact, 300L, wanact_len);
    if (s_cmp(wanact, wbuf, wanact_len, 300L) != 0) {
	unmsg_("Action description passed to TSTWAN is too long.", 48L);
    }
    if (i_indx(wbuf, "should", 300L, 6L) < 1) {
/* Writing concatenation */
#ifndef NO_PROTO
	i__1[0] = 63, a__1[0] = "Action description passed to TSTWAN does no"
		"t contain \"should\": ";
#else /* NO_PROTO */
	i__1[0] = 63, a__1[0] = "Action description passed to TSTWAN does no\
t contain \"should\": ";
#endif /* NO_PROTO */
	i__1[1] = 300, a__1[1] = wbuf;
	s_cat(ch__1, a__1, i__1, &c__2, 363L);
	unmsg_(ch__1, 363L);
    }
    erfunm_(&errinf_1.efid[errinf_1.efcnt - 1], funnam, 80L);
/* Writing concatenation */
    i__1[0] = 3, a__1[0] = "If ";
    i__1[1] = 80, a__1[1] = funnam;
    s_cat(msg, a__1, i__1, &c__2, 300L);
    i__2 = itrim_(msg, 300L) + 1;
/* Writing concatenation */
    i__1[0] = 25, a__1[0] = "issues a warning because ";
    i__1[1] = 200, a__1[1] = errchr_1.curcon;
    s_cat(msg + i__2, a__1, i__1, &c__2, 300 - i__2);
    i__2 = itrim_(msg, 300L);
/* Writing concatenation */
    i__1[0] = 2, a__1[0] = ", ";
    i__1[1] = 300, a__1[1] = wbuf;
    s_cat(msg + i__2, a__1, i__1, &c__2, 300 - i__2);
    setmsg_(errchr_1.errsrs, msg, 40L, 300L);
    ifpf_(warnin);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstwan_ */

