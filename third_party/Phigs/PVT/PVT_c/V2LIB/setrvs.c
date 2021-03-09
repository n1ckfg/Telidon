/* setrvs.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int setrvs_(char *st, real *arr, integer *nsz, ftnlen st_len)

#else /* NO_PROTO */
/* Subroutine */ int setrvs_(st, arr, nsz, st_len)
char *st;
real *arr;
integer *nsz;
ftnlen st_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_indx();
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer nc, lst, ierr;
    static real rval;
    static char stwk[700];
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), prsrl_(char *, real *,
	     integer *, ftnlen), deblnk_(char *, char *, integer *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), prsrl_(), deblnk_();
#endif /* NO_PROTO */
    static char tmpmsg[730];

/*  setrvs initializes the real array ARR, based on the */
/*  value-representations in ST and also returns the number */
/*  of values in NSZ. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    *nsz = 0;
/* blank means zero entries */
    if (s_cmp(st, " ", st_len, 1L) == 0) {
	return 0;
    }
/* get rid of leading, internal blanks */
    deblnk_(st, stwk, &lst, st_len, 700L);
/* L300: */
/* add trailing comma */
    ++lst;
    stwk[lst - 1] = ',';
/* now sitting at alleged number */
L400:
/* find next comma */
    nc = i_indx(stwk, ",", 700L, 1L);
    if (nc <= 1) {
	unmsg_("Adjacent commas passed to SETRVS.", 33L);
    }
/* parse up to comma */
    prsrl_(stwk, &rval, &ierr, nc - 1);
    if (ierr != 0) {
/* Writing concatenation */
	i__1[0] = 31, a__1[0] = "Invalid string sent to SETRVS: ";
	i__1[1] = st_len, a__1[1] = st;
	s_cat(tmpmsg, a__1, i__1, &c__2, 730L);
	unmsg_(tmpmsg, 730L);
    }
    ++(*nsz);
    arr[*nsz] = rval;
/* delete thru comma */
    i__2 = nc;
    s_copy(stwk, stwk + i__2, 700L, 700 - i__2);
    if (s_cmp(stwk, " ", 700L, 1L) != 0) {
	goto L400;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setrvs_ */

