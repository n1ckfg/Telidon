/* fort/04/02/05/03/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw, 
	    errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[
	    20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__4 = 4;
static integer c__0 = 0;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b9 = 0.f;
static real c_b10 = .02f;
static real c_b28 = .2f;
#else /* NO_PROTO */
static real c_b9 = (float)0.;
static real c_b10 = (float).02;
static real c_b28 = (float).2;
#endif /* NO_PROTO */
static integer c__5 = 5;
static integer c__2 = 2;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b50 = .05f;
#else /* NO_PROTO */
static real c_b50 = (float).05;
#endif /* NO_PROTO */
static integer c__11 = 11;
static integer c__13 = 13;
#ifndef NO_PROTO
static real c_b80 = .45f;
static real c_b83 = 1.f;
#else /* NO_PROTO */
static real c_b80 = (float).45;
static real c_b83 = (float)1.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 04.02.05.03/rlzew                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical rlzew_(real *ewset, real *ewexp)
#else /* NO_PROTO */
logical rlzew_(ewset, ewexp)
real *ewset, *ewexp;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static real rew;
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nqedr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, integer *), nsedr (
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nqedr (), nsedr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  RLZEW sets a requested edgewidth scale factor in the edge bundle */
/* table, and checks to see that it is realized approximately equal to the
*/
/*  expected value. */
/*  Input parameters: */
/*    EWSET : Requested value for edgewidth scale factor */
/*    EWEXP : Expected value for realized edgewidth scale factor */
/* off/on switch for edge flag and error handling mode */
    nsedr (&globnu_1.wkid, &c__4, &c__0, &c__1, ewset, &c__1);
    nqedr (&globnu_1.wkid, &c__4, &c__1, &errind, &idum1, &idum2, &rew, &
	    idum2);
    chkinq_("pqedr", &errind, 5L);
    ret_val = appeq_(&rew, ewexp, &c_b9, &c_b10);
    return ret_val;
} /* rlzew_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.05.03/disedb                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int disedb_(integer *samp, integer *start, integer *univ, 
	integer *subset)
#else /* NO_PROTO */
/* Subroutine */ int disedb_(samp, start, univ, subset)
integer *samp, *start, *univ, *subset;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i, j, k, jj, ot, jef, kef, jet, ket;
    static real jew, kew;
    static integer jeci, keci;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind, maxloc, atrcnt, maxatr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpedr (integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *);
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpedr ();
    extern integer rndint_();
#endif /* NO_PROTO */
    static logical atrnew[4];
    static integer optatr;

/*  DISEDB selects SAMP predefined bundles at random from the */
/*  edge bundle table which are distinct in all their attributes. */
/*  If there are not SAMP completely distinct bundles, DISEDB tries */
/*  to maximize the number of different attributes. */

/*  Input parameters: */
/*    SAMP        : number of predefined bundles to be picked */
/*    START       : starting index */
/*    UNIV        : last element in universe to pick from */
/*  Output parameters: */
/*    SUBSET      : array containing the selected distinct bundles */
/* off/on switch for edge flag and error handling mode */
/*  total number of attributes */
    /* Parameter adjustments */
    --subset;

    /* Function Body */
    if (*univ + 1 - *start < *samp) {
#ifndef NO_PROTO
	unmsg_("Abort in DISEDB because size of universe is less than reques"
		"ted sample.", 71L);
#else /* NO_PROTO */
	unmsg_("Abort in DISEDB because size of universe is less than reques\
ted sample.", 71L);
#endif /* NO_PROTO */
    }
/*  OPTATR is the best possible number of attributes that can be distinct 
*/
    optatr = 4;
/*  this loop picks out samp elements */
    i__1 = *samp;
    for (i = 1; i <= i__1; ++i) {
/*  number of new attribute values so far */
	maxatr = -1;
/*  look at entire universe each time, starting at random location */
	j = rndint_(start, univ);
	i__2 = *univ;
	for (jj = *start; jj <= i__2; ++jj) {
	    if (j >= *univ) {
/*  cycle around to beginning */
		j = *start;
	    } else {
		++j;
	    }
	    for (ot = 1; ot <= 4; ++ot) {
		atrnew[ot - 1] = TRUE_;
/* L50: */
	    }
/*  get attributes of next candidate */
	    nqpedr (&dialog_1.specwt, &j, &errind, &jef, &jet, &jew, &jeci);
	    chkinq_("pqpedr", &errind, 6L);
/*  check against all those picked so far; */
	    i__3 = i - 1;
	    for (k = 1; k <= i__3; ++k) {
/*  if already picked, get another j */
		if (j == subset[k]) {
		    goto L400;
		}
		nqpedr (&dialog_1.specwt, &subset[k], &errind, &kef, &ket, &
			kew, &keci);
		chkinq_("pqpedr", &errind, 6L);
/*  check all attributes */
		if (jef == kef) {
		    if (jef == 0) {
/*  edge flag off implies all other attributes indisti
nguishable */
			atrcnt = 0;
			goto L80;
		    } else {
			atrnew[0] = FALSE_;
		    }
		}
		if (jet == ket) {
		    atrnew[1] = FALSE_;
		}
		if (jew == kew) {
		    atrnew[2] = FALSE_;
		}
		if (jeci == keci) {
		    atrnew[3] = FALSE_;
		}
/* L300: */
	    }
/*  count # of trues = # of distinct attributes */
	    atrcnt = 0;
	    for (ot = 1; ot <= 4; ++ot) {
		if (atrnew[ot - 1]) {
		    ++atrcnt;
		}
/* L75: */
	    }
L80:
/*  take the best so far */
	    if (atrcnt > maxatr) {
		maxatr = atrcnt;
		maxloc = j;
	    }
/*  cannot get better than OPTATR */
	    if (maxatr >= optatr) {
		goto L410;
	    }
L400:
	    ;
	}
/*  put best one on the list */
L410:
	subset[i] = maxloc;
/*  remember greatest number of distinct attributes */
	optatr = maxatr;
/* L500: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* disedb_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.05.03/drwedb                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int drwedb_(integer *numbun, integer *bundis, integer *
	bundif, integer *numet)
#else /* NO_PROTO */
/* Subroutine */ int drwedb_(numbun, bundis, bundif, numet)
integer *numbun, *bundis, *bundif, *numet;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[4], ya[4];
    static integer ix, pdef, pdci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static integer pdet;
    static real pdew, yloc;
    static integer npts[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedt (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedt ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int drbued_(integer *, integer *), nsedfg (
	    integer *), nsedci (integer *), chkinq_(char *, integer *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int drbued_(), nsedfg (), nsedci (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nqpedr (integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nsewsc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nqpedr (), nsewsc ();
#endif /* NO_PROTO */

/*  DRWEDB draws a set of actual edges using the specified bundle */
/*  values, and a set of expected edges, using the attribute */
/*  values returned by <inquire predefined edge representation>. */
/*  It draws the expected edge incorrectly at the specified */
/*  position. */

/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of edge bundle indices to be displayed */
/*    BUNDIF : position of edge to be drawn incorrectly */
/*    NUMET  : number of edge types */
/* aspect source */
/* off/on switch for edge flag and error handling mode */
/*  draw triangles to display edge */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    npts[0] = 3;
/*  draw and label actual */
    drbued_(numbun, &bundis[1]);
/*  now draw expected results - with individual attributes from WDT */
/*  use individual attributes */
    setasf_(&c__1);
#ifndef NO_PROTO
    xa[0] = .6f;
    xa[1] = .6f;
    xa[2] = .9f;
    yloc = .9f;
    yincr = .8f / *numbun;
#else /* NO_PROTO */
    xa[0] = (float).6;
    xa[1] = (float).6;
    xa[2] = (float).9;
    yloc = (float).9;
    yincr = (float).8 / *numbun;
#endif /* NO_PROTO */
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nqpedr (&dialog_1.specwt, &bundis[ix], &errind, &pdef, &pdet, &pdew, &
		pdci);
	chkinq_("pqpedr", &errind, 6L);
	if (ix == *bundif) {
	    if (*numet == 1) {
/*  switch edge flag */
		if (pdef == 1) {
		    pdef = 0;
		} else {
		    pdef = 1;
		}
	    }
	    pdet = pdet % 4 + 1;
#ifndef NO_PROTO
	    pdew *= 1.3f;
#else /* NO_PROTO */
	    pdew *= (float)1.3;
#endif /* NO_PROTO */
	    pdci = pdci % 5 + 1;
	}
	nsedfg (&pdef);
	nsedt (&pdet);
	nsewsc (&pdew);
	nsedci (&pdci);
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .25f;
	ya[1] = yloc + yincr * .25f;
	ya[2] = yloc - yincr * .25f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).25;
	ya[1] = yloc + yincr * (float).25;
	ya[2] = yloc - yincr * (float).25;
#endif /* NO_PROTO */
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwedb_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.05.03/drbued                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int drbued_(integer *numbun, integer *bundis)
#else /* NO_PROTO */
/* Subroutine */ int drbued_(numbun, bundis)
integer *numbun, *bundis;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[4], ya[4];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas (integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas ();
#endif /* NO_PROTO */
    static real yloc;
    static integer npts[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsedi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsedi ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int numlab_(integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int numlab_();
#endif /* NO_PROTO */

/*  DRBUED draws a set of edges using the specified edge bundle */
/*  values. */
/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of edge bundle indices to be displayed */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    npts[0] = 3;
#ifndef NO_PROTO
    xa[0] = .25f;
    xa[1] = .25f;
    xa[2] = .55f;
    yincr = .8f / *numbun;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).25;
    xa[1] = (float).25;
    xa[2] = (float).55;
    yincr = (float).8 / *numbun;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(numbun, &c_b28, &yloc, &yincr);
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	ya[0] = yloc - yincr * .25f;
	ya[1] = yloc + yincr * .25f;
	ya[2] = yloc - yincr * .25f;
#else /* NO_PROTO */
	ya[0] = yloc - yincr * (float).25;
	ya[1] = yloc + yincr * (float).25;
	ya[2] = yloc - yincr * (float).25;
#endif /* NO_PROTO */
	nsedi (&bundis[ix]);
	nfas (&c__1, npts, xa, ya);
	yloc -= yincr;
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drbued_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.05.03/shedbw                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
    static icilist io___57 = { 0, digit, 0, "(I1)", 1, 1 };


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
    nslwsc (&c_b9);
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
    nschh (&c_b50);
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
	s_wsfi(&io___57);
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.05.03/lbedty                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
    static icilist io___70 = { 0, lntid, 0, "(A, I4, A)", 20, 1 };


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
	s_wsfi(&io___70);
	do_fio(&c__1, "Type#", 5L);
	do_fio(&c__1, (char *)&thiset, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	vislab_(lntid, "R", &c_b50, &c_b80, &ybot, &ytop, 10L, 1L);
	nsedi (&ix);
	nfas (&c__1, npts, xa, ya);
	nsedr (wkid, &ix, &c__1, &thiset, &c_b83, &c__1);
	yloc -= yincr;
/* L300: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* lbedty_ */

