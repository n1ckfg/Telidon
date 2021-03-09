/* colpch.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__4 = 4;
static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int colpch_(logical *filmod, integer *clor, real *xlo, real *
	ylo, real *xhi, real *yhi)
#else /* NO_PROTO */
/* Subroutine */ int colpch_(filmod, clor, xlo, ylo, xhi, yhi)
logical *filmod;
integer *clor;
real *xlo, *ylo, *xhi, *yhi;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *), npl (integer 
	    *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa (), npl ();
#endif /* NO_PROTO */
    static real filx[4], fily[4], yinc, yval;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *), nsis (integer *), nsici (
	    integer *), nsplci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln (), nsis (), nsici (), nsplci ();
#endif /* NO_PROTO */

/*  COLPCH will generate a rectangular color patch with the specified */
/*  diagonal vertices.  It will use solid interior fill area or */
/*  polylines based on the specified filling mode. */
/*  Input parameters: */
/*    FILMOD          : use fill area if true, otherwise polyline */
/*    CLOR            : color index to use */
/*    XLO,YLO,XHI,YHI : extent of the rectangle */
/*  interior style hollow, solid,    pattern,  hatch,    empty */
/* linetype */
    filx[0] = *xlo;
    filx[1] = *xhi;
    filx[2] = *xhi;
    filx[3] = *xlo;
    if (*filmod) {
	fily[0] = *ylo;
	fily[1] = *ylo;
	fily[2] = *yhi;
	fily[3] = *yhi;
	nsis (&c__1);
	nsici (clor);
	nfa (&c__4, filx, fily);
    } else {
	nsln (&c__1);
	nsplci (clor);
/*  paint lines at the rate of about 400/screen */
#ifndef NO_PROTO
	yinc = .0025000000000000001f;
#else /* NO_PROTO */
	yinc = (float).0025000000000000001;
#endif /* NO_PROTO */
	r__1 = *yhi;
	r__2 = yinc;
	for (yval = *ylo; r__2 < 0 ? yval >= r__1 : yval <= r__1; yval += 
		r__2) {
	    fily[0] = yval;
	    fily[1] = yval;
	    npl (&c__2, filx, fily);
/* L100: */
	}
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* colpch_ */

