/* dsanst.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b13 = .05f;
static real c_b14 = .35f;
#else /* NO_PROTO */
static real c_b13 = (float).05;
static real c_b14 = (float).35;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__4 = 4;

#ifndef NO_PROTO
/* Subroutine */ int dsanst_(integer *lsiz, integer *lanst)
#else /* NO_PROTO */
/* Subroutine */ int dsanst_(lsiz, lanst)
integer *lsiz, *lanst;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[10], ya[10];
    static integer ix;
    static real xo[10], yo[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static integer ldis[10], perm[10];
    static real yloc, npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int natr (real *, real *, real *, real *, char *, 
	    ftnlen), nsmk (integer *), wcnpc_(real *, real *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int natr (), nsmk (), wcnpc_();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsans (integer *), rnset_(integer *, integer *
	    , integer *), vislab_(char *, char *, real *, real *, real *, 
	    real *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsans (), rnset_(), vislab_();
#endif /* NO_PROTO */
    static real anoffx, anoffy;
    static char anstid[11];
    static real npcpwc;
    static integer numdis;
#ifndef NO_PROTO
    extern /* Subroutine */ int srtiar_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int srtiar_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___17 = { 0, anstid, 0, "(A,I5,A)", 11, 1 };


/*  DSANST accepts a list of annotation styles and displays at most 8 */
/*  of them. */
/* marker type */
    /* Parameter adjustments */
    --lanst;

    /* Function Body */
    wcnpc_(&c_b2, &c_b2, &npcx, &npcy, &npcpwc);
    numdis = min(8,*lsiz);
    rnset_(&numdis, lsiz, perm);
/*  build list of annotation styles to be displayed */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
	ldis[ix - 1] = lanst[perm[ix - 1]];
/* L100: */
    }
/*  and sort it */
    srtiar_(&numdis, ldis);
/*  display in order and label all annotation styles in ldis */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = .25f, r__2 = 1.f / (*lsiz + 1);
#else /* NO_PROTO */
    r__1 = (float).25, r__2 = (float)1. / (*lsiz + 1);
#endif /* NO_PROTO */
    yincr = dmin(r__1,r__2);
    yloc = 1 - yincr;
/*  annotation offsets in WC */
#ifndef NO_PROTO
    anoffx = .2f;
    anoffy = yincr * .3f;
#else /* NO_PROTO */
    anoffx = (float).2;
    anoffy = yincr * (float).3;
#endif /* NO_PROTO */
    i__1 = numdis;
    for (ix = 1; ix <= i__1; ++ix) {
/*  mark reference and annotation point */
#ifndef NO_PROTO
	xo[ix - 1] = .6f;
#else /* NO_PROTO */
	xo[ix - 1] = (float).6;
#endif /* NO_PROTO */
	yo[ix - 1] = yloc;
	xa[ix - 1] = xo[ix - 1] - anoffx;
	ya[ix - 1] = yo[ix - 1] - anoffy;
	s_wsfi(&io___17);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&ldis[ix - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
#ifndef NO_PROTO
	r__1 = yloc - yincr * .3f;
	r__2 = yloc + yincr * .3f;
#else /* NO_PROTO */
	r__1 = yloc - yincr * (float).3;
	r__2 = yloc + yincr * (float).3;
#endif /* NO_PROTO */
	vislab_(anstid, "R", &c_b13, &c_b14, &r__1, &r__2, 11L, 1L);
	nsans (&ldis[ix - 1]);
	r__1 = anoffx * npcpwc;
	r__2 = anoffy * npcpwc;
	natr (&xa[ix - 1], &ya[ix - 1], &r__1, &r__2, "abc", 3L);
	yloc -= yincr;
/* L220: */
    }
    nsmk (&c__3);
    npm (&numdis, xa, ya);
    nsmk (&c__4);
    npm (&numdis, xo, yo);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dsanst_ */

