/* inoutl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__201 = 201;
static integer c__202 = 202;
static integer c__203 = 203;

#ifndef NO_PROTO
/* Subroutine */ int inoutl_(void)
#else /* NO_PROTO */
/* Subroutine */ int inoutl_()
#endif /* NO_PROTO */
{
    static real xa[20], ya[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer siz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nopst (integer *), setrvs_(char 
	    *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nopst (), setrvs_();
#endif /* NO_PROTO */

/*  Build outlines for nominal ELF in structures 201,202,203; */
/*  lower left corner of character at 0,0 and height and width of */
/*  character = 1.  Note that height of character *body* (from */
/*  topline to bottomline) is usually greater than height of */
/*  character (from capline to baseline). */
/*  capital E */
    nopst (&c__201);
#ifndef NO_PROTO
    setrvs_("-0.125, -0.125, 1.125, 1.125, 0.125, 0.125,  1.125,  1.125, 0.1"
	    "25, 0.125, 1.125, 1.125, -0.125", xa, &siz, 94L);
    setrvs_("-0.125, 1.125, 1.125, 0.875, 0.875,  0.625,  0.625, 0.375, 0.37"
	    "5, 0.125, 0.125, -0.125, -0.125", ya, &siz, 94L);
#else /* NO_PROTO */
    setrvs_("-0.125, -0.125, 1.125, 1.125, 0.125, 0.125,  1.125,  1.125, 0.1\
25, 0.125, 1.125, 1.125, -0.125", xa, &siz, 94L);
    setrvs_("-0.125, 1.125, 1.125, 0.875, 0.875,  0.625,  0.625, 0.375, 0.37\
5, 0.125, 0.125, -0.125, -0.125", ya, &siz, 94L);
#endif /* NO_PROTO */
    npl (&siz, xa, ya);
    nclst ();
/*  capital L */
    nopst (&c__202);
    setrvs_("-0.125, -0.125, 0.125, 0.125, 1.125,  1.125, -0.125", xa, &siz, 
	    51L);
    setrvs_("-0.125,  1.125, 1.125, 0.125, 0.125, -0.125, -0.125", ya, &siz, 
	    51L);
    npl (&siz, xa, ya);
    nclst ();
/*  capital F */
    nopst (&c__203);
#ifndef NO_PROTO
    setrvs_("-0.125, -0.125, 1.125, 1.125,  0.125, 0.125,  1.125,  1.125, 0."
	    "125, 0.125, -0.125", xa, &siz, 81L);
    setrvs_("-0.125, 1.125, 1.125,  0.875,  0.875, 0.625,  0.625, 0.375, 0.3"
	    "75, -0.125, -0.125", ya, &siz, 81L);
#else /* NO_PROTO */
    setrvs_("-0.125, -0.125, 1.125, 1.125,  0.125, 0.125,  1.125,  1.125, 0.\
125, 0.125, -0.125", xa, &siz, 81L);
    setrvs_("-0.125, 1.125, 1.125,  0.875,  0.875, 0.625,  0.625, 0.375, 0.3\
75, -0.125, -0.125", ya, &siz, 81L);
#endif /* NO_PROTO */
    npl (&siz, xa, ya);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* inoutl_ */

