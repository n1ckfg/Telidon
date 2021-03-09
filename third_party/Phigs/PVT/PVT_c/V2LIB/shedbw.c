/* shedbw.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b7 = 0.f;
#else /* NO_PROTO */
static real c_b7 = (float)0.;
#endif /* NO_PROTO */
static integer c__5 = 5;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b20 = .05f;
#else /* NO_PROTO */
static real c_b20 = (float).05;
#endif /* NO_PROTO */
static integer c__11 = 11;
static integer c__13 = 13;

#ifndef NO_PROTO
/* Subroutine */ int shedbw_(char *hding, integer *wkid, real *reqew, real *
	expew, real *nomew, real *minlw, char *pfsw, ftnlen hding_len, ftnlen 
	pfsw_len)
#else /* NO_PROTO */
/* Subroutine */ int shedbw_(hding, wkid, reqew, expew, nomew, minlw, pfsw, 
	hding_len, pfsw_len)
char *hding;
integer *wkid;
real *reqew, *expew, *nomew, *minlw;
char *pfsw;
ftnlen hding_len;
ftnlen pfsw_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real xa[5], ya[5], za[5];
    static integer ix;
    static real alt[10];
    static integer ans;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx ();
#endif /* NO_PROTO */
    static real xgap;
    static integer perm[20];
    static real xloc, xlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), nsln (integer *), nsis (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nsln (), nsis ();
#endif /* NO_PROTO */
    static integer npts[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 ();
#endif /* NO_PROTO */
    static char digit[1];
    static real ybase;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedi (integer *), nschh (real *), nsici (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedi (), nschh (), nsici ();
#endif /* NO_PROTO */
    static real fsize, xmarg, xincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedr (integer *, integer *, integer *, 
	    integer *, real *, integer *), dchoic_(char *, integer *, integer 
	    *, integer *, ftnlen), ndellb (integer *, integer *), opcofl_(
	    void), setasf_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedr (), dchoic_(), ndellb (), opcofl_(), 
	    setasf_();
#endif /* NO_PROTO */
    static integer numalt;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *), nsplci (
	    integer *), altsiz_(real *, real *, real *, integer *, integer *, 
	    real *), nslwsc (real *), nsiasf (integer *, integer *), nstxal (
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_(), nsplci (), altsiz_(), nslwsc (), 
	    nsiasf (), nstxal ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___17 = { 0, digit, 0, "(I1)", 1, 1 };


/*  SHEDBW tests the rendering of a given edgewidth, and returns the */
/*  pass/fail result, or an abort signal if the requested edge is */
/*  too wide to be tested. */
/*  Input parameters: */
/*    HDING : Title for this test */
/*    WKID  : Workstation identification */
/*    REQEW : The edgewidth (in DC) to be requested. */
/*    EXPEW : The expected edgewidth (in DC) - the one which should */
/*            be realized in order to pass. */
/*    NOMEW : The nominal edgewidth */
/*    MINLW : The minimum linewidth (used for simulation) */
/*  Output parameters: */
/*    PFSW  : Result of the test - P:pass, F:fail, A:abort. */
/* aspect source */
/* edge-, line-type */
/* edge flag indicator */
/* interior style */
/* aspect identifier */
/* text alignment horizontal */
/* text alignment vertical */
#ifndef NO_PROTO
    ybase = .2f;
#else /* NO_PROTO */
    ybase = (float).2;
#endif /* NO_PROTO */
/*  can we fit in top of picture area? - if not, quit */
    if (*expew * dialog_1.wcpdc > 1 - ybase) {
	*pfsw = 'A';
	return 0;
    }
/*  get list of alternate sizes */
#ifndef NO_PROTO
    r__1 = (1.f - ybase) / dialog_1.wcpdc;
#else /* NO_PROTO */
    r__1 = ((float)1. - ybase) / dialog_1.wcpdc;
#endif /* NO_PROTO */
    altsiz_(expew, &dialog_1.qvis, &r__1, &c__4, &numalt, alt);
    rnperm_(&numalt, perm);
/*  draw actual and simulated edges of various widths */
/*  first simulated - use individual attributes */
    setasf_(&c__1);
    nsln (&c__1);
    nsplci (&c__1);
    nslwsc (&c_b7);
#ifndef NO_PROTO
    xincr = 1.f / numalt;
    xloc = 0.f;
#else /* NO_PROTO */
    xincr = (float)1. / numalt;
    xloc = (float)0.;
#endif /* NO_PROTO */
    xgap = xincr / 25;
    xmarg = xgap * 3;
    xlen = (xincr - xgap - xmarg * 2) / 2;
    ya[1] = ybase + *minlw * dialog_1.wcpdc / 2;
    ya[2] = ya[1];
    i__1 = numalt;
    for (ix = 1; ix <= i__1; ++ix) {
/*  size of linewidth to be simulated - allow for thickness */
/*  of simulating edge by subtracting minimum edgewidth. */
	fsize = (alt[perm[ix - 1] - 1] - *minlw) * dialog_1.wcpdc;
	ya[0] = ya[1] + fsize;
	ya[3] = ya[0];
	ya[4] = ya[0];
	xa[0] = xloc + xmarg;
	xa[1] = xa[0];
	xa[4] = xa[0];
	xa[2] = xa[0] + xlen;
	xa[3] = xa[2];
	npl (&c__5, xa, ya);
	xloc += xincr;
/* L500: */
    }
/*  now actual - use bundle attributes */
/*  use bundle index #5 */
    setasf_(&c__0);
    r__1 = *reqew / *nomew;
    nsedr (wkid, &c__5, &c__1, &c__1, &r__1, &c__1);
    nsedi (&c__5);
/*   set up text for individual attributes */
    for (ix = 6; ix <= 10; ++ix) {
	nsiasf (&ix, &c__1);
/* L110: */
    }
    nstxal (&c__2, &c__3);
    nschh (&c_b20);
    nsiasf (&c__11, &c__1);
    nsiasf (&c__13, &c__1);
    nsis (&c__4);
    nsici (&c__1);
#ifndef NO_PROTO
    xloc = 0.f;
    za[0] = .5f;
    za[1] = .9f;
#else /* NO_PROTO */
    xloc = (float)0.;
    za[0] = (float).5;
    za[1] = (float).9;
#endif /* NO_PROTO */
    za[2] = za[1];
    za[3] = za[0];
    ya[0] = ybase + *expew * dialog_1.wcpdc / 2;
    ya[1] = ya[0];
    ya[2] = ya[0];
    ya[3] = ya[0];
    npts[0] = 4;
    i__1 = numalt;
    for (ix = 1; ix <= i__1; ++ix) {
/*  offset 2nd and 4th point slightly so that Z-oriented edges (1-2 an
d */
/*  3-4) project to a short horizontal line, rather than to a point. 
*/
	xa[0] = xloc + xmarg + xgap + xlen;
	xa[1] = xa[0] + xlen / 100;
	xa[2] = xa[0] + xlen;
	xa[3] = xa[2] - xlen / 100;
	nfas3 (&c__1, npts, xa, ya, za);
	s_wsfi(&io___17);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	e_wsfi();
	r__1 = xloc + xincr / 2;
#ifndef NO_PROTO
	r__2 = ybase - .05f;
#else /* NO_PROTO */
	r__2 = ybase - (float).05;
#endif /* NO_PROTO */
	ntx (&r__1, &r__2, digit, 1L);
	xloc += xincr;
/* L600: */
    }
/* Writing concatenation */
    i__2[0] = hding_len, a__1[0] = hding;
    i__2[1] = 45, a__1[1] = ": Which pair has the same vertical thickness?";
    s_cat(msg, a__1, i__2, &c__2, 300L);
    dchoic_(msg, &c__0, &numalt, &ans, 300L);
    if (ans == 0) {
	opcofl_();
	*pfsw = 'F';
    } else if (perm[ans - 1] == 1) {
	*pfsw = 'P';
    } else {
	*pfsw = 'F';
    }
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* shedbw_ */

