/* simark.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b4 = 0.f;
#else /* NO_PROTO */
static real c_b4 = (float)0.;
#endif /* NO_PROTO */
static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int simark_(integer *mkst, integer *coli, real *mkrad, real *
	cx, real *cy)
#else /* NO_PROTO */
/* Subroutine */ int simark_(mkst, coli, mkrad, cx, cy)
integer *mkst, *coli;
real *mkrad, *cx, *cy;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    double cos(), sin();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[60], ya[60], ang;
    static char msg[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer siz;
    static real ang2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static integer noseg;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), setasf_(integer *), 
	    nsplci (integer *), nslwsc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), setasf_(), nsplci (), nslwsc ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___8 = { 0, msg, 0, "(A,I5,A)", 100, 1 };


/*  SIMARK uses polyline to simulate markers of various styles. */

/*  Input parameters: */
/*    MKST   : Marker style (either plus, asterick, or circle) */
/*    COLI   : Color to be used in simulation = index #1 */
/*    MKRAD  : Marker radius in WC */
/*    CX,CY  : Marker center in WC */
/* aspect source */
/*                bundled     individual */
/* linetype */
/* marker type */
/*  use ASFs individual */
    setasf_(&c__1);
/*  use polyline to simulate polymarker */
    nsln (&c__1);
    nsplci (coli);
    nslwsc (&c_b4);
    if (*mkst == 2) {
/*  simulate plus */
	xa[0] = *cx - *mkrad;
	xa[1] = *cx + *mkrad;
	ya[0] = *cy;
	ya[1] = *cy;
	npl (&c__2, xa, ya);
	xa[0] = *cx;
	xa[1] = *cx;
	ya[0] = *cy + *mkrad;
	ya[1] = *cy - *mkrad;
	npl (&c__2, xa, ya);
    } else if (*mkst == 3) {
/* simulate asterisk */
	for (siz = 0; siz <= 2; ++siz) {
#ifndef NO_PROTO
	    ang = siz * 3.14159265f / 3;
#else /* NO_PROTO */
	    ang = siz * (float)3.14159265 / 3;
#endif /* NO_PROTO */
	    xa[0] = *cx + *mkrad * cos(ang);
	    ya[0] = *cy + *mkrad * sin(ang);
#ifndef NO_PROTO
	    ang2 = ang + 3.14159265f;
#else /* NO_PROTO */
	    ang2 = ang + (float)3.14159265;
#endif /* NO_PROTO */
	    xa[1] = *cx + *mkrad * cos(ang2);
	    ya[1] = *cy + *mkrad * sin(ang2);
	    npl (&c__2, xa, ya);
/* L100: */
	}
    } else if (*mkst == 4) {
/* mkst = 4, simulate circle */
	noseg = 40;
	i__1 = noseg + 1;
	for (siz = 1; siz <= i__1; ++siz) {
#ifndef NO_PROTO
	    ang = (siz << 1) * 3.14159265f / noseg;
#else /* NO_PROTO */
	    ang = (siz << 1) * (float)3.14159265 / noseg;
#endif /* NO_PROTO */
	    xa[siz - 1] = *cx + *mkrad * cos(ang);
	    ya[siz - 1] = *cy + *mkrad * sin(ang);
/* L200: */
	}
	i__1 = noseg + 1;
	npl (&i__1, xa, ya);
    } else {
/*  invalid marker type */
	s_wsfi(&io___8);
	do_fio(&c__1, "Invalid marker style passed to SIMARK: ", 39L);
	do_fio(&c__1, (char *)&(*mkst), (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 100L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* simark_ */

