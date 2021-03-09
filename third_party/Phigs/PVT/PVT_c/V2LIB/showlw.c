/* showlw.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b6 = 0.f;
#else /* NO_PROTO */
static real c_b6 = (float)0.;
#endif /* NO_PROTO */
static integer c__5 = 5;
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b11 = .05f;
#else /* NO_PROTO */
static real c_b11 = (float).05;
#endif /* NO_PROTO */
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int showlw_(char *hding, integer *lnst, integer *plcol, real 
	*reqlw, real *explw, real *nomlw, real *minlw, char *pfsw, ftnlen 
	hding_len, ftnlen pfsw_len)
#else /* NO_PROTO */
/* Subroutine */ int showlw_(hding, lnst, plcol, reqlw, explw, nomlw, minlw, 
	pfsw, hding_len, pfsw_len)
char *hding;
integer *lnst, *plcol;
real *reqlw, *explw, *nomlw, *minlw;
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
    static real xa[5], ya[5];
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
    extern /* Subroutine */ int nsep (integer *), nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), nsln ();
#endif /* NO_PROTO */
    static char digit[1];
    static real ybase;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh ();
#endif /* NO_PROTO */
    static real xmarg, fsize, xincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchoic_(char *, integer *, integer *, integer 
	    *, ftnlen), ndellb (integer *, integer *), opcofl_(void), nsplci (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchoic_(), ndellb (), opcofl_(), nsplci ();
#endif /* NO_PROTO */
    static integer numalt;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *), altsiz_(real *,
	     real *, real *, integer *, integer *, real *), nslwsc (real *), 
	    nstxal (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_(), altsiz_(), nslwsc (), nstxal ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___15 = { 0, digit, 0, "(I1)", 1, 1 };


/*  SHOWLW tests the rendering of a given linewidth, and returns the */
/*  pass/fail result.  The actual line is drawn using the indicated */
/*  linetype and color. */

/*  Input parameters: */
/*    HDING : Title for this test */
/*    LNST  : Linestyle to be used for actual line */
/*    PLCOL : Polyline color index to be used for actual line */
/*    REQLW : The linewidth (in DC) to be requested. */
/*    EXPLW : The expected linewidth (in DC) - the one which should */
/*            be realized in order to pass. */
/*    NOMLW : The nominal linewidth */
/*    MINLW : The minimum linewidth */
/*  Output parameters: */
/*    PFSW  : Result of the test - P for pass, F for fail, A for abort. */

/* linetype */
/* text alignment horizontal */
/* text alignment vertical */
#ifndef NO_PROTO
    ybase = .2f;
#else /* NO_PROTO */
    ybase = (float).2;
#endif /* NO_PROTO */
/*  can we fit in top of picture area? - if not, quit */
    if (*explw * dialog_1.wcpdc > 1 - ybase) {
	*pfsw = 'A';
	return 0;
    }
/*  get list of alternate sizes */
#ifndef NO_PROTO
    r__1 = (1.f - ybase) / dialog_1.wcpdc;
#else /* NO_PROTO */
    r__1 = ((float)1. - ybase) / dialog_1.wcpdc;
#endif /* NO_PROTO */
    altsiz_(explw, &dialog_1.qvis, &r__1, &c__4, &numalt, alt);
    rnperm_(&numalt, perm);
/*  draw actual and simulated lines of various widths */
/*  first simulated */
    nsln (&c__1);
    nsplci (&c__1);
    nslwsc (&c_b6);
#ifndef NO_PROTO
    xincr = 1.f / numalt;
    xloc = 0.f;
#else /* NO_PROTO */
    xincr = (float)1. / numalt;
    xloc = (float)0.;
#endif /* NO_PROTO */
    xmarg = xincr * 3 / 25;
    xgap = xincr / 25;
    xlen = (xincr - xgap - xmarg * 2) / 2;
    ya[1] = ybase + *minlw * dialog_1.wcpdc / 2;
    ya[2] = ya[1];
    i__1 = numalt;
    for (ix = 1; ix <= i__1; ++ix) {
/*  size of linewidth to be simulated - allow for thickness */
/*  of simulating polylines by subtracting minimum linewidth. */
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
/*  now actual */
    r__1 = *reqlw / *nomlw;
    nslwsc (&r__1);
    nsln (lnst);
    nsplci (plcol);
    nstxal (&c__2, &c__3);
    nschh (&c_b11);
#ifndef NO_PROTO
    xloc = 0.f;
#else /* NO_PROTO */
    xloc = (float)0.;
#endif /* NO_PROTO */
    ya[0] = ybase + *explw * dialog_1.wcpdc / 2;
    ya[1] = ya[0];
    i__1 = numalt;
    for (ix = 1; ix <= i__1; ++ix) {
	xa[0] = xloc + xmarg + xlen + xgap;
	xa[1] = xa[0] + xlen;
	npl (&c__2, xa, ya);
	s_wsfi(&io___15);
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
} /* showlw_ */

