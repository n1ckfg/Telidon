/* denhat.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b5 = .15f;
#else /* NO_PROTO */
static real c_b5 = (float).15;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int denhat_(integer *strid, integer *maxh, integer *specwt, 
	integer *ihat)
#else /* NO_PROTO */
/* Subroutine */ int denhat_(strid, maxh, specwt, ihat)
integer *strid, *maxh, *specwt, *ihat;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static real xa[4], ya[4];
    static integer hs[100], ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */
    static integer ans;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer perm[100];
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsis ();
#endif /* NO_PROTO */
    static real ytop;
    static integer idum1, idum2, idum3, idum4;
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nsisi (integer *), nemst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nsisi (), nemst ();
#endif /* NO_PROTO */
    static integer numhs;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *), 
	    nopst (integer *), dchoic_(char *, integer *, integer *, integer *
	    , ftnlen), chkinq_(char *, integer *, ftnlen), numlab_(integer *, 
	    real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnset_(), nopst (), dchoic_(), chkinq_(), 
	    numlab_();
#endif /* NO_PROTO */
    static integer errind, numlin;

/*  DENHAT displays a random selection of hatch styles and asks the */
/*  operator to select a dense one. */
/*  Input parameters: */
/*    STRID  : identifier for available closed posted structure */
/*    MAXH   : maximum number of styles to display */
/*    SPECWT : specific workstation type */
/*  Output parameters: */
/*    IHAT   : selected hatch style */
/* interior style */
    nopst (strid);
    nqif (specwt, &c__0, &c__0, &errind, &idum1, &idum2, &numhs, &idum3, &
	    idum4);
    chkinq_("pqif", &errind, 4L);
/* Computing MIN */
    i__1 = *maxh, i__2 = abs(numhs);
    numlin = min(i__1,i__2);
    i__1 = abs(numhs);
    rnset_(&numlin, &i__1, perm);
#ifndef NO_PROTO
    yincr = 1 / (numlin + 1.f);
#else /* NO_PROTO */
    yincr = 1 / (numlin + (float)1.);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
    numlab_(&numlin, &c_b5, &ytop, &yincr);
    nsis (&c__3);
#ifndef NO_PROTO
    xa[0] = .2f;
    xa[1] = .9f;
    xa[2] = .9f;
    xa[3] = .2f;
#else /* NO_PROTO */
    xa[0] = (float).2;
    xa[1] = (float).9;
    xa[2] = (float).9;
    xa[3] = (float).2;
#endif /* NO_PROTO */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	ya[0] = yloc + yincr * .4f;
	ya[1] = yloc + yincr * .4f;
	ya[2] = yloc - yincr * .4f;
	ya[3] = yloc - yincr * .4f;
#else /* NO_PROTO */
	ya[0] = yloc + yincr * (float).4;
	ya[1] = yloc + yincr * (float).4;
	ya[2] = yloc - yincr * (float).4;
	ya[3] = yloc - yincr * (float).4;
#endif /* NO_PROTO */
	nqif (specwt, &c__0, &perm[ix - 1], &errind, &idum1, &idum2, &idum3, &
		hs[ix - 1], &idum4);
	chkinq_("pqif", &errind, 4L);
	nsisi (&hs[ix - 1]);
	nfa (&c__4, xa, ya);
	yloc -= yincr;
/* L60: */
    }
    dchoic_("Pick a dense hatch style, preferably diagonal.", &c__1, &numlin, 
	    &ans, 46L);
    nemst (strid);
    nclst ();
    *ihat = hs[ans - 1];
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* denhat_ */

