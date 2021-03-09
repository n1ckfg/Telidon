/* win6.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b2 = 0.f;
#else /* NO_PROTO */
static real c_b2 = (float)0.;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b5 = 1.f;
#else /* NO_PROTO */
static real c_b5 = (float)1.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int win6_(integer *strid, integer *coli, real *xsiz, real *
	ysiz, real *xwinlo, real *ywinlo)
#else /* NO_PROTO */
/* Subroutine */ int win6_(strid, coli, xsiz, ysiz, xwinlo, ywinlo)
integer *strid, *coli;
real *xsiz, *ysiz, *xwinlo, *ywinlo;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[2], ya[2];
    static integer ix, iy;
    static char dig[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx ();
#endif /* NO_PROTO */
    static real xloc, yloc, txht;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh ();
#endif /* NO_PROTO */
    static integer winid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nopst (integer *), nsplci (
	    integer *), nschup (real *, real *), nschxp (real *), nstxci (
	    integer *), nslwsc (real *), nstxal (integer *, integer *), 
	    nstxfn (integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nopst (), nsplci (), nschup (), 
	    nschxp (), nstxci (), nslwsc (), nstxal (), nstxfn (), nstxpr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___10 = { 0, dig, 0, "(I1)", 1, 1 };


/*  WIN6 sets up a structure which generates 6 labelled */
/*  windows on the screen. */
/*  Input parameters: */
/*    STRID         : Identifier of structure to contain windows */
/*    COLI          : Color index to be used */
/*  Output parameters: */
/*    XSIZ,YSIZ     : Size of windows */
/*    XWINLO,YWINLO : Location of lower left corner of windows */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    /* Parameter adjustments */
    --ywinlo;
    --xwinlo;

    /* Function Body */
#ifndef NO_PROTO
    *xsiz = .3333f;
    *ysiz = .3333f;
    txht = .1666f;
#else /* NO_PROTO */
    *xsiz = (float).3333;
    *ysiz = (float).3333;
    txht = (float).1666;
#endif /* NO_PROTO */
    nopst (strid);
    nslwsc (&c_b2);
    nsplci (coli);
    nstxci (coli);
    nstxfn (&c__1);
    nstxpr (&c__2);
    nschxp (&c_b5);
#ifndef NO_PROTO
    r__1 = txht * .3f;
#else /* NO_PROTO */
    r__1 = txht * (float).3;
#endif /* NO_PROTO */
    nschh (&r__1);
    nschup (&c_b2, &c_b5);
    nstxal (&c__2, &c__1);
    winid = 1;
    for (iy = 1; iy >= 0; --iy) {
#ifndef NO_PROTO
	xa[0] = 0.f;
	xa[1] = 1.f;
#else /* NO_PROTO */
	xa[0] = (float)0.;
	xa[1] = (float)1.;
#endif /* NO_PROTO */
	yloc = txht + iy * (*ysiz + txht);
	ya[0] = yloc;
	ya[1] = yloc;
	npl (&c__2, xa, ya);
	ya[0] = yloc + *ysiz;
	ya[1] = ya[0];
	npl (&c__2, xa, ya);
	for (ix = 0; ix <= 3; ++ix) {
	    xloc = ix * *xsiz;
	    ya[0] = yloc;
	    ya[1] = yloc + *ysiz;
	    xa[0] = xloc;
	    xa[1] = xloc;
	    npl (&c__2, xa, ya);
	    if (ix == 3) {
		goto L200;
	    }
	    xwinlo[winid] = xloc;
	    ywinlo[winid] = yloc;
	    s_wsfi(&io___10);
	    do_fio(&c__1, (char *)&winid, (ftnlen)sizeof(integer));
	    e_wsfi();
	    r__1 = xloc + *xsiz / 2;
#ifndef NO_PROTO
	    r__2 = yloc - txht * .1f;
#else /* NO_PROTO */
	    r__2 = yloc - txht * (float).1;
#endif /* NO_PROTO */
	    ntx (&r__1, &r__2, dig, 1L);
	    ++winid;
L200:
	    ;
	}
/* L100: */
    }
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* win6_ */

