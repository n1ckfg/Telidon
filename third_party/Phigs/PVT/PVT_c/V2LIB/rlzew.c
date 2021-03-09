/* rlzew.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw, 
	    errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[
	    20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_

/* Table of constant values */

static integer c__4 = 4;
static integer c__0 = 0;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b9 = 0.f;
static real c_b10 = .02f;
#else /* NO_PROTO */
static real c_b9 = (float)0.;
static real c_b10 = (float).02;
#endif /* NO_PROTO */

#ifndef NO_PROTO
logical rlzew_(real *ewset, real *ewexp)
#else /* NO_PROTO */
logical rlzew_(ewset, ewexp)
real *ewset, *ewexp;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static real rew;
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nqedr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *), nsedr (
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nqedr (), nsedr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  RLZEW sets a requested edgewidth scale factor in the edge bundle */
/* table, and checks to see that it is realized approximately equal to the
*/
/*  expected value. */
/*  Input parameters: */
/*    EWSET : Requested value for edgewidth scale factor */
/*    EWEXP : Expected value for realized edgewidth scale factor */
/* off/on switch for edge flag and error handling mode */
    nsedr (&globnu_1.wkid, &c__4, &c__0, &c__1, ewset, &c__1);
    nqedr (&globnu_1.wkid, &c__4, &c__1, &errind, &idum1, &idum2, &rew, &
	    idum2);
    chkinq_("pqedr", &errind, 5L);
    ret_val = appeq_(&rew, ewexp, &c_b9, &c_b10);
    return ret_val;
} /* rlzew_ */

