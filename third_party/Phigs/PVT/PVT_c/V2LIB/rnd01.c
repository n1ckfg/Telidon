/*  This program contains the "manual" addition to the generated code for 
    the main C sublib - uses the ANSI standard C time function so as to
    provide a random seed.
*/

/* rnd01.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* MANUAL change here: */
#include <stdio.h>
#include <time.h>
/* end MANUAL change */

/* Common Block Declarations */

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw, 
	    errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[
	    20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_

struct {
    real rlseed;
} ranctl_;

#define ranctl_1 ranctl_

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 0.f;
#else /* NO_PROTO */
static real c_b2 = (float)0.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
doublereal rnd01_(void)
#else /* NO_PROTO */
doublereal rnd01_()
#endif /* NO_PROTO */
{
    /* Initialized data */

    static logical first = TRUE_;
    static doublereal factor = .53736255218;
    static doublereal addend = .63535248281;

    /* System generated locals */
    real ret_val;

    /* Local variables */
    static doublereal x;
    static integer ix;
#ifndef NO_PROTO
    extern doublereal secnds_(real *);
#else /* NO_PROTO */
    extern doublereal secnds_();
#endif /* NO_PROTO */

/*  RND01 returns a random real number, X, uniformly distributed, */
/*  such that 0 .LE. X .LT. 1. */
/*  This is a very low-grade random number generator; it should be */
/*  portable except for the call to SECNDS. */
    if (first) {
	first = FALSE_;
#ifndef NO_PROTO
	if (ranctl_1.rlseed < .1f || ranctl_1.rlseed > .9f) {
#else /* NO_PROTO */
	if (ranctl_1.rlseed < (float).1 || ranctl_1.rlseed > (float).9) {
#endif /* NO_PROTO */
/* ********************************************************* */

/* USERMOD  put in a time function to initialize X (true randomization
) */

/* ********************************************************* */

/* MANUAL change here: 
	    x = secnds_(&c_b2);
*/
	    x = time(NULL);

/* paranoid code here */
            if (x == 0)
               unmsg_ ("Random seed set by time function to zero.", 41L);
            
            if (x < 0) x = -x;
            while (x > 1000)
               x /= 10.2645;
            while (x < 0.001)
               x *= 10.2645;

/* end MANUAL change */

/* ********************************************************* */

/* USERMOD  End of customization */

/* ********************************************************* */
	} else {
/*  pseudo-random sequence - seed taken from configuration file */

	    x = ranctl_1.rlseed;
	}
    }
#ifndef NO_PROTO
    x = (x * factor + addend) * 97.8272f;
#else /* NO_PROTO */
    x = (x * factor + addend) * (float)97.8272;
#endif /* NO_PROTO */
    ix = (integer) x;
    x -= ix;
    ret_val = x;
    return ret_val;
} /* rnd01_ */

