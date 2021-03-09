/* xfinh.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int xfinh_(integer *perm)
#else /* NO_PROTO */
/* Subroutine */ int xfinh_(perm)
integer *perm;
#endif /* NO_PROTO */
{
    static real u, z;
#ifndef NO_PROTO
    extern /* Subroutine */ int nbltm (real *, real *, real *, real *, real *,
	     real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nbltm ();
#endif /* NO_PROTO */
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static real scaley;
    static integer errind;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real shifty;

/*  More special-purpose code here for testing inheritance. */
/*  Since structure 104 is re-invoked, it generates polyline #5,6 on */
/*  first invocation, and 11,12 on 2nd.  But 11,12 would simply */
/*  overlay 5,6, so we must also pass down a transformation which */
/*  maps locations 5,6 to locations 11,12, respectively. */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    /* Parameter adjustments */
    --perm;

    /* Function Body */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    fxpty = ylocel_(&perm[5]);
    shifty = ylocel_(&perm[11]) - ylocel_(&perm[5]);
    scaley = (ylocel_(&perm[12]) - ylocel_(&perm[11])) / (ylocel_(&perm[6]) - 
	    ylocel_(&perm[5]));
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &scaley, &errind, xform);
    chkinq_("pbltm", &errind, 5L);
    nslmt (xform, &c__2);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* xfinh_ */

