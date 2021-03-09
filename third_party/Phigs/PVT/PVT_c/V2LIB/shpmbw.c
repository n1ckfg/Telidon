/* shpmbw.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__3 = 3;
static integer c__0 = 0;
static integer c__13 = 13;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__17 = 17;
#ifndef NO_PROTO
static real c_b26 = .05f;
static real c_b33 = .175f;
#else /* NO_PROTO */
static real c_b26 = (float).05;
static real c_b33 = (float).175;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int shpmbw_(char *hding, integer *wkid, real *reqmw, real *
	expmw, real *nommw, char *pfsw, ftnlen hding_len, ftnlen pfsw_len)
#else /* NO_PROTO */
/* Subroutine */ int shpmbw_(hding, wkid, reqmw, expmw, nommw, pfsw, 
	hding_len, pfsw_len)
char *hding;
integer *wkid;
real *reqmw, *expmw, *nommw;
char *pfsw;
ftnlen hding_len;
ftnlen pfsw_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    real r__1;

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
    static real xa[60], ya[60];
    static integer ix;
    static real alt[10];
    static integer ans;
    static char msg[300];
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern logical dyn_();
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static real pmx[1], pmy[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real ygap;
    static integer perm[20];
    static real xloc, yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static integer mkst;
    static real scrx, scry;
    static integer idum1, idum2, idum3;
    static real mkrad;
    static char digit[1];
    static real ybase;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh ();
#endif /* NO_PROTO */
    static real centx, centy, xincr, msize;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqdsp (integer *, integer *, integer *, real *
	    , real *, integer *, integer *), nspmi (integer *), nspmr (
	    integer *, integer *, integer *, real *, integer *), nsvwi (
	    integer *), dchoic_(char *, integer *, integer *, integer *, 
	    ftnlen), ndellb (integer *, integer *), chkinq_(char *, integer *,
	     ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqdsp (), nspmi (), nspmr (), nsvwi (), 
	    dchoic_(), ndellb (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *);
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_();
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer numalt;
#ifndef NO_PROTO
    extern /* Subroutine */ int simark_(integer *, integer *, real *, real *, 
	    real *), rnperm_(integer *, integer *), altsiz_(real *, real *, 
	    real *, integer *, integer *, real *), nstxal (integer *, integer 
	    *);
#else /* NO_PROTO */
    extern /* Subroutine */ int simark_(), rnperm_(), altsiz_(), nstxal ();
#endif /* NO_PROTO */
    static real scrsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int opcomt_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int opcomt_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___27 = { 0, digit, 0, "(I1)", 1, 1 };


/*  SHPMBW tests the rendering of a given marker size, and returns the */
/*  pass/fail result. */

/*  Input parameters: */
/*    HDING : Title for this test */
/*    WKID  : Workstation identifier */
/*    REQMW : The marker size (in DC) to be requested. */
/*    EXPMW : The expected marker size (in DC) - the one which should */
/*            be realized in order to pass. */
/*    NOMMW : The nominal marker size */
/*  Output parameters: */
/*    PFSW  : Result of the test - P for pass, F for fail, A for abort. */

/* aspect source */
/*                bundled     individual */
/* marker type */
/* text alignment horizontal */
/* text alignment vertical */
/*  can we fit 4 across in the picture area? */
#ifndef NO_PROTO
    if (*expmw * dialog_1.wcpdc < .25f) {
#else /* NO_PROTO */
    if (*expmw * dialog_1.wcpdc < (float).25) {
#endif /* NO_PROTO */
	goto L50;
    }
/*  can we fit on the screen as a whole? - if not, quit */
    nqdsp (&dialog_1.specwt, &errind, &idum1, &scrx, &scry, &idum2, &idum3);
    chkinq_("pqdsp", &errind, 5L);
    scrsiz = dmin(scrx,scry);
    if (*expmw > scrsiz) {
	*pfsw = 'A';
	return 0;
    }
/*  draw on full screen - override view #1 */
    nsvwi (&c__3);
/*  use ASFs bundled */
    setasf_(&c__0);
/*  attributes for actual marker, use index #13 */
    r__1 = *reqmw / *nommw;
    nspmr (wkid, &c__13, &c__2, &r__1, &c__1);
#ifndef NO_PROTO
    xa[0] = .5f;
#else /* NO_PROTO */
    xa[0] = (float).5;
#endif /* NO_PROTO */
    ya[0] = dialog_1.syxrat / 2;
    nspmi (&c__13);
    npm (&c__1, xa, ya);
/*  MKRAD is simulated marker radius - this works because in */
/*  view #3, in x-dimension, WC:1 = DC:SCRX */
    mkrad = *expmw / (scrx * 2);
#ifndef NO_PROTO
    centx = .5f;
#else /* NO_PROTO */
    centx = (float).5;
#endif /* NO_PROTO */
    centy = dialog_1.syxrat / 2;
/*  simulate circle to surround non-circle marker */
    simark_(&c__4, &c__1, &mkrad, &centx, &centy);
    if (dyn_("Does the marker fit exactly within the circle?", 46L)) {
	*pfsw = 'P';
    } else {
	*pfsw = 'F';
    }
    goto L666;
L50:
/*  alt = list of alternative operator choices for marker size */
/*  numalt = total number of alternative marker sizes generated */
#ifndef NO_PROTO
    r__1 = .25f / dialog_1.wcpdc;
#else /* NO_PROTO */
    r__1 = (float).25 / dialog_1.wcpdc;
#endif /* NO_PROTO */
    altsiz_(expmw, &dialog_1.qvis, &r__1, &c__4, &numalt, alt);
    rnperm_(&numalt, perm);
/*  draw actual markers and simulate markers of various sizes */
#ifndef NO_PROTO
    xincr = 1.f / numalt;
#else /* NO_PROTO */
    xincr = (float)1. / numalt;
#endif /* NO_PROTO */
    xloc = xincr / 2;
#ifndef NO_PROTO
    ybase = .375f;
#else /* NO_PROTO */
    ybase = (float).375;
#endif /* NO_PROTO */
    pmy[0] = ybase;
/* Computing MAX */
#ifndef NO_PROTO
    r__1 = *expmw * 1.5f * dialog_1.wcpdc;
    ygap = dmax(r__1,.1f);
#else /* NO_PROTO */
    r__1 = *expmw * (float)1.5 * dialog_1.wcpdc;
    ygap = dmax(r__1,(float).1);
#endif /* NO_PROTO */
    yloc = ybase + ygap;
/*  bundle for actual marker, use bundle 17 */
/*  pick a marker between 2 and 4 */
    mkst = rndint_(&c__2, &c__4);
    r__1 = *reqmw / *nommw;
    nspmr (wkid, &c__17, &mkst, &r__1, &c__1);
    nspmi (&c__17);
/*  attributes for label */
    nstxal (&c__2, &c__3);
    nschh (&c_b26);
    i__1 = numalt;
    for (ix = 1; ix <= i__1; ++ix) {
/*  reset  to bundled, since SIMARK uses individual */
	setasf_(&c__0);
/* draw actual marker */
	pmx[0] = xloc;
	npm (&c__1, pmx, pmy);
/*  simulate marker with polylines */
	msize = alt[perm[ix - 1] - 1] * dialog_1.wcpdc;
	mkrad = msize / 2;
	simark_(&mkst, &c__1, &mkrad, &xloc, &yloc);
/*  now label */
	s_wsfi(&io___27);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	e_wsfi();
	ntx (&xloc, &c_b33, digit, 1L);
	xloc += xincr;
/* L500: */
    }
/* Writing concatenation */
    i__2[0] = hding_len, a__1[0] = hding;
    i__2[1] = 42, a__1[1] = ": Which pair of markers has the same size?";
    s_cat(msg, a__1, i__2, &c__2, 300L);
    dchoic_(msg, &c__0, &numalt, &ans, 300L);
    if (ans == 0) {
	opcomt_();
	*pfsw = 'F';
    } else if (perm[ans - 1] == 1) {
	*pfsw = 'P';
    } else {
	*pfsw = 'F';
    }
L666:
/*  clear out last display from structure */
    nsep (&c__1);
    ndellb (&c__1, &c__2);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* shpmbw_ */

