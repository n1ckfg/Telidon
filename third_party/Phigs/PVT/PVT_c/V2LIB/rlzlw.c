/* rlzlw.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b8 = 0.f;
static real c_b9 = .02f;
#else /* NO_PROTO */
static real c_b8 = (float)0.;
static real c_b9 = (float).02;
#endif /* NO_PROTO */

#ifndef NO_PROTO
logical rlzlw_(real *lwset, real *lwexp)
#else /* NO_PROTO */
logical rlzlw_(lwset, lwexp)
real *lwset, *lwexp;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static real rlw;
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nsplr (integer *, integer *, integer *, real *
	    , integer *), nqplr (integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *), chkinq_(char *, integer *, ftnlen);

#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nsplr (), nqplr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  RLZLW sets a requested linewidth scale factor in the polyline bundle 
*/
/* table, and checks to see that it is realized approximately equal to the
*/
/*  expected value. */
/*  Input parameters: */
/*    LWSET : Requested value for linewidth scale factor */
/*    LWEXP : Expected value for realized linewidth scale factor */
    nsplr (&globnu_1.wkid, &c__4, &c__1, lwset, &c__1);
    nqplr (&globnu_1.wkid, &c__4, &c__1, &errind, &idum1, &rlw, &idum2);
    chkinq_("pqplr", &errind, 5L);
    ret_val = appeq_(&rlw, lwexp, &c_b8, &c_b9);
    return ret_val;
} /* rlzlw_ */

