/* rlzms.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
logical rlzms_(real *msset, real *msexp)
#else /* NO_PROTO */
logical rlzms_(msset, msexp)
real *msset, *msexp;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static real rms;
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nqpmr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nspmr (integer *, 
	    integer *, integer *, real *, integer *), chkinq_(char *, integer 
	    *, ftnlen);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nqpmr (), nspmr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/* RLZMS sets a requested marker size scale factor in the polymarker bundl
e*/
/* table, and checks to see that it is realized approximately equal to the
*/
/*  expected value. */
/*  Input parameters: */
/*    MSSET : Requested value for marker size scale factor */
/*    MSEXP : Expected value for realized marker size scale factor */
    nspmr (&globnu_1.wkid, &c__4, &c__1, msset, &c__1);
    nqpmr (&globnu_1.wkid, &c__4, &c__1, &errind, &idum1, &rms, &idum2);
    chkinq_("pqpmr", &errind, 5L);
    ret_val = appeq_(&rms, msexp, &c_b8, &c_b9);
    return ret_val;
} /* rlzms_ */

