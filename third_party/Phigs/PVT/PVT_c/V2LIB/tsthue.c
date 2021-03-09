/* tsthue.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b3 = .25f;
static real c_b4 = .75f;
#else /* NO_PROTO */
static real c_b3 = (float).25;
static real c_b4 = (float).75;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__102 = 102;

#ifndef NO_PROTO
integer tsthue_(char *prmpt, logical *filmod, integer *numset, integer *
	lscoli, ftnlen prmpt_len)
#else /* NO_PROTO */
integer tsthue_(prmpt, filmod, numset, lscoli, prmpt_len)
char *prmpt;
logical *filmod;
integer *numset, *lscoli;
ftnlen prmpt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val, i__1, i__2;
    real r__1;

    /* Local variables */
    static integer ix;
    static real yval, ytop, yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), colpch_(logical *, integer 
	    *, real *, real *, real *, real *);
    extern logical iareql_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int drwrec_(real *, real *, real *, real *), 
	    dilist_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), colpch_();
    extern logical iareql_();
    extern /* Subroutine */ int drwrec_(), dilist_();
#endif /* NO_PROTO */
    static integer anslis[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsplci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsplci ();
#endif /* NO_PROTO */
    static integer anssiz;

/*  TSTHUE displays NUMSET colors, starting with #2, using LSCOLI as */
/*  color indices.  It then asks the operator to identify these and */
/*  issues 1 (pass), -1 (fail), or -2 (fail with comment), as a result. */


/*  Input parameters: */
/*    PRMPT  : prompt for the operator */
/*    FILMOD : fill mode for rectangle; true for solid fill area, */
/*             false for polylines */
/*    NUMSET : number of colored rectangles to be drawn */
/*    LSCOLI : list of identifiers from color palette */
    /* Parameter adjustments */
    --lscoli;

    /* Function Body */
#ifndef NO_PROTO
    yincr = 1.f / (*numset + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (*numset + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
#ifndef NO_PROTO
    yval = ytop - yincr * .25f;
#else /* NO_PROTO */
    yval = ytop - yincr * (float).25;
#endif /* NO_PROTO */
    i__1 = *numset;
    for (ix = 1; ix <= i__1; ++ix) {
	i__2 = ix + 1;
#ifndef NO_PROTO
	r__1 = yval + yincr * .5f;
#else /* NO_PROTO */
	r__1 = yval + yincr * (float).5;
#endif /* NO_PROTO */
	colpch_(filmod, &i__2, &c_b3, &yval, &c_b4, &r__1);
	nsplci (&c__1);
#ifndef NO_PROTO
	r__1 = yval + yincr * .5f;
#else /* NO_PROTO */
	r__1 = yval + yincr * (float).5;
#endif /* NO_PROTO */
	drwrec_(&c_b3, &c_b4, &yval, &r__1);
	yval -= yincr;
/* L120: */
    }
    dilist_(prmpt, &anssiz, anslis, prmpt_len);
    if (anssiz == 1 && anslis[0] == 0) {
	ret_val = -2;
    } else if (iareql_(&anssiz, anslis, numset, &lscoli[1])) {
	ret_val = 1;
    } else {
	ret_val = -1;
    }
    nemst (&c__102);
    return ret_val;
} /* tsthue_ */

