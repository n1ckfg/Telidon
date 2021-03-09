/* lbedty.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b10 = .05f;
static real c_b11 = .45f;
static real c_b14 = 1.f;
#else /* NO_PROTO */
static real c_b10 = (float).05;
static real c_b11 = (float).45;
static real c_b14 = (float)1.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int lbedty_(integer *wkid, integer *numdis, integer *perm, 
	integer *ledtyp)
#else /* NO_PROTO */
/* Subroutine */ int lbedty_(wkid, numdis, perm, ledtyp)
integer *wkid, *numdis, *perm, *ledtyp;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[3], ya[3];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static real yloc, ybot;
    static integer npts[1];
    static real ytop;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedi ();
#endif /* NO_PROTO */
    static char lntid[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedr (integer *, integer *, integer *, 
	    integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedr ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int vislab_(char *, char *, real *, real *, real *
	    , real *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int vislab_();
#endif /* NO_PROTO */
    static integer thiset;

    /* Fortran I/O blocks */
    static icilist io___11 = { 0, lntid, 0, "(A, I4, A)", 20, 1 };


/*  LBEDTY is used to display a list of edgetypes, under bundled control. 
*/

/*  Input parameters: */
/*    WKID   : Workstation identifier for edge bundles */
/*    NUMDIS : Number of edgetypes to be selected and displayed */
/*    PERM   : List of positions of selected edgetypes within LEDTYP */
/*    LEDTYP : List of edgetypes from which selection is made */
/* off/on switch for edge flag and error handling mode */
/*  display in order and label bundles 1 thru numdis */
    /* Parameter adjustments */
    --ledtyp;
    --perm;

    /* Function Body */
#ifndef NO_PROTO
    xa[0] = .5f;
    xa[1] = .5f;
    xa[2] = .9f;
    yincr = .8f / *numdis;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).5;
    xa[1] = (float).5;
    xa[2] = (float).9;
    yincr = (float).8 / *numdis;
    yloc = (float).9;
#endif /* NO_PROTO */
    npts[0] = 3;
    i__1 = *numdis;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	ybot = yloc - yincr * .3f;
	ytop = yloc + yincr * .3f;
#else /* NO_PROTO */
	ybot = yloc - yincr * (float).3;
	ytop = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	ya[0] = ybot;
	ya[1] = ytop;
	ya[2] = ybot;
	thiset = ledtyp[perm[ix]];
	s_wsfi(&io___11);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&thiset, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	vislab_(lntid, "R", &c_b10, &c_b11, &ybot, &ytop, 10L, 1L);
	nsedi (&ix);
	nfas (&c__1, npts, xa, ya);
	nsedr (wkid, &ix, &c__1, &thiset, &c_b14, &c__1);
	yloc -= yincr;
/* L300: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* lbedty_ */

