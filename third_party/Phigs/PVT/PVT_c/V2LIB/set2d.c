/* set2d.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int set2d_(char *vals, integer *maxcol, integer *nocols, 
	integer *collen, integer *arr, ftnlen vals_len)
#else /* NO_PROTO */
/* Subroutine */ int set2d_(vals, maxcol, nocols, collen, arr, vals_len)
char *vals;
integer *maxcol, *nocols, *collen, *arr;
ftnlen vals_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer arr_dim1, arr_offset, i__1[2], i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_len(char *, ftnlen), s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer i_len(), s_cmp();
    /* Subroutine */ int s_cat();
    integer i_indx();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);

#endif /* not NO_PROTO */
    /* Local variables */
    static char wk[2000];
    static integer last;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer slpos;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */

/*  Set2d is used to initialize a ragged 2D array of integers, based */
/*  on an input string. */

/*  --- Input Parameter: */
/*  vals      : Input string, with integer values.  Values separated by */

/*              commas, array columns terminated by slashes. */
/*  maxcol    : Maximum column size = size of first dimension of 2D array.
 */
/*  --- Output parameters: */
/*  nocols    : Number of columns initialized */
/*  collen    : 1D array of lengths of each column */
/*  arr       : 2D array of integers */
/*  Syntax of vals: */
/*  vals         = column* */
/*  column       = col-values "/" */
/*  col-values   = " " | integer-list */
/*  integer-list = integer | integer "," integer-list */
    /* Parameter adjustments */
    arr_dim1 = *maxcol;
    arr_offset = arr_dim1 + 1;
    arr -= arr_offset;
    --collen;

    /* Function Body */
    if (i_len(vals, vals_len) > 1998) {
	unmsg_("String passed to SET2D exceeds length of work area.", 51L);
    }
/* no columns so far */
    *nocols = 0;
/* blank means no columns at all */
    if (s_cmp(vals, " ", vals_len, 1L) == 0) {
	return 0;
    }
/* check for terminating slash */
    last = itrim_(vals, vals_len);
    if (vals[last - 1] != '/') {
	unmsg_("String sent to set2d does not terminate with slash.", 51L);
    }
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = " ";
    i__1[1] = vals_len, a__1[1] = vals;
    s_cat(wk, a__1, i__1, &c__2, 2000L);
/* begin a new column */
L100:
    slpos = i_indx(wk, "/", 2000L, 1L);
/* put next column and its length in arrays */
    ++(*nocols);
    setvs_(wk, &arr[*nocols * arr_dim1 + 1], &collen[*nocols], slpos - 1);
    if (collen[*nocols] > *maxcol) {
/* Writing concatenation */
#ifndef NO_PROTO
	i__1[0] = 47, a__1[0] = "Column passed to set2d exceeds maximum leng"
		"th: ";
#else /* NO_PROTO */
	i__1[0] = 47, a__1[0] = "Column passed to set2d exceeds maximum leng\
th: ";
#endif /* NO_PROTO */
	i__1[1] = slpos - 1, a__1[1] = wk;
	s_cat(wk, a__1, i__1, &c__2, 2000L);
	unmsg_(wk, 2000L);
    }
/* delete encoded column - set up for next; ensure one blank */
    i__2 = slpos;
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = " ";
    i__1[1] = 2000 - i__2, a__1[1] = wk + i__2;
    s_cat(wk, a__1, i__1, &c__2, 2000L);
/* any more columns ? */
    if (s_cmp(wk, " ", 2000L, 1L) != 0) {
	goto L100;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* set2d_ */

