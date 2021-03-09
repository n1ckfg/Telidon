/* dlstpf.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int dlstpf_(char *prompt, integer *expsiz, integer *explst, 
	char *slsw, ftnlen prompt_len, ftnlen slsw_len)
#else /* NO_PROTO */
/* Subroutine */ int dlstpf_(prompt, expsiz, explst, slsw, prompt_len, 
	slsw_len)
char *prompt;
integer *expsiz, *explst;
char *slsw;
ftnlen prompt_len;
ftnlen slsw_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];
    logical L__1;
    char ch__1[28];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int unmsg_(char *, ftnlen), opfail_(void);
    extern logical iareql_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int dilist_(char *, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
    extern logical seteq_();
    extern /* Subroutine */ int unmsg_(), opfail_();
    extern logical iareql_();
    extern /* Subroutine */ int dilist_();
#endif /* NO_PROTO */
    static integer anslst[100], anssiz;

/*  DLSTPF gets an integer list response from the operator, and */
/*  issues pass/fail as a result of comparing the operator response */
/*  to the expected list. A list with one element = 0 indicates "fail */
/*  - cannot answer" and triggers an operator comment. */
/*  Input parameters: */
/*    PROMPT : prompt to be sent to operator. */
/*    EXPSIZ : expected size of list */
/*    EXPLST : expected contents of list */
/*    SLSW   : S/L switch to indicate comparison by set-equality */
/*             (unordered) of list-equality (ordered) */
    /* Parameter adjustments */
    --explst;

    /* Function Body */
    dilist_(prompt, &anssiz, anslst, prompt_len);
    if (anssiz == 1 && anslst[0] == 0) {
	opfail_();
    } else {
	if (*slsw == 'L') {
	    L__1 = iareql_(&anssiz, anslst, expsiz, &explst[1]);
	    ifpf_(&L__1);
	} else if (*slsw == 'S') {
	    L__1 = anssiz == *expsiz && seteq_(&anssiz, anslst, &explst[1]);
	    ifpf_(&L__1);
	} else {
/* Writing concatenation */
	    i__1[0] = 26, a__1[0] = "DLSTPF called with SLSW = ";
	    i__1[1] = 1, a__1[1] = slsw;
	    i__1[2] = 1, a__1[2] = ".";
	    s_cat(ch__1, a__1, i__1, &c__3, 28L);
	    unmsg_(ch__1, 28L);
	}
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dlstpf_ */

