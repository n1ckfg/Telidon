/* fort/04/02/01/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b8 = 0.f;
static real c_b9 = .02f;
#else /* NO_PROTO */
static real c_b8 = (float)0.;
static real c_b9 = (float).02;
#endif /* NO_PROTO */
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b22 = .2f;
#else /* NO_PROTO */
static real c_b22 = (float).2;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__5 = 5;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b47 = .05f;
#else /* NO_PROTO */
static real c_b47 = (float).05;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 04.02.01.02/rlzlw                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical rlzlw_(real *lwset, real *lwexp)
#else /* NO_PROTO */
logical rlzlw_(lwset, lwexp)
real *lwset, *lwexp;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static real rlw;
    static integer idum1, idum2;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nsplr (integer *, integer *, integer *, real *
	    , integer *), nqplr (integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *), chkinq_(char *, integer *, ftnlen);

#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nsplr (), nqplr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  RLZLW sets a requested linewidth scale factor in the polyline bundle 
*/
/* table, and checks to see that it is realized approximately equal to the
*/
/*  expected value. */
/*  Input parameters: */
/*    LWSET : Requested value for linewidth scale factor */
/*    LWEXP : Expected value for realized linewidth scale factor */
    nsplr (&globnu_1.wkid, &c__4, &c__1, lwset, &c__1);
    nqplr (&globnu_1.wkid, &c__4, &c__1, &errind, &idum1, &rlw, &idum2);
    chkinq_("pqplr", &errind, 5L);
    ret_val = appeq_(&rlw, lwexp, &c_b8, &c_b9);
    return ret_val;
} /* rlzlw_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.01.02/displb                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int displb_(integer *samp, integer *start, integer *univ, 
	integer *subset)
#else /* NO_PROTO */
/* Subroutine */ int displb_(samp, start, univ, subset)
integer *samp, *start, *univ, *subset;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i, j, k, jj, ot, jci, kci, jlt, klt;
    static real jlw, klw;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind, maxloc, atrcnt, maxatr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static logical atrnew[3];
    static integer optatr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpplr (integer *, integer *, integer *, 
	    integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpplr ();
#endif /* NO_PROTO */

/*  DISPLB selects SAMP predefined bundles at random from the */
/*  polyline bundle table which are distinct in all their attributes. */
/*  If there are not SAMP completely distinct bundles, DISPLB tries */
/*  to maximize the number of different attributes. */

/*  Input parameters: */
/*    SAMP        : number of predefined bundles to be picked */
/*    START       : starting index */
/*    UNIV        : last element in universe to pick from */
/*  Output parameters: */
/*    SUBSET      : array containing the selected distinct bundles */
/*  total number of attributes */
    /* Parameter adjustments */
    --subset;

    /* Function Body */
    if (*univ + 1 - *start < *samp) {
#ifndef NO_PROTO
	unmsg_("Abort in DISPLB because size of universe is less than reques"
		"ted sample.", 71L);
#else /* NO_PROTO */
	unmsg_("Abort in DISPLB because size of universe is less than reques\
ted sample.", 71L);
#endif /* NO_PROTO */
    }
/*  OPTATR is the best possible number of attributes that can be distinct 
*/
    optatr = 3;
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
	    for (ot = 1; ot <= 3; ++ot) {
		atrnew[ot - 1] = TRUE_;
/* L50: */
	    }
/*  get attributes of next candidate */
	    nqpplr (&dialog_1.specwt, &j, &errind, &jlt, &jlw, &jci);
	    chkinq_("pqpplr", &errind, 6L);
/*  check against all those picked so far; */
	    i__3 = i - 1;
	    for (k = 1; k <= i__3; ++k) {
/*  if already picked, get another j */
		if (j == subset[k]) {
		    goto L400;
		}
		nqpplr (&dialog_1.specwt, &subset[k], &errind, &klt, &klw, &
			kci);
		chkinq_("pqpplr", &errind, 6L);
/*  check all attributes */
		if (jlt == klt) {
		    atrnew[0] = FALSE_;
		}
		if (jlw == klw) {
		    atrnew[1] = FALSE_;
		}
		if (jci == kci) {
		    atrnew[2] = FALSE_;
		}
/* L300: */
	    }
/*  count # of trues */
	    atrcnt = 0;
	    for (ot = 1; ot <= 3; ++ot) {
		if (atrnew[ot - 1]) {
		    ++atrcnt;
		}
/* L75: */
	    }
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
} /* displb_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.01.02/drwplb                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int drwplb_(integer *numbun, integer *bundis, integer *
	bundif)
#else /* NO_PROTO */
/* Subroutine */ int drwplb_(numbun, bundis, bundif)
integer *numbun, *bundis, *bundif;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static real xa[2], ya[2];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer pdci, pdlt;
    static real yloc, pdlw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspli (integer *), chkinq_(char *, integer *, 
	    ftnlen), numlab_(integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspli (), chkinq_(), numlab_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nsplci (integer *), 
	    nslwsc (real *), nqpplr (integer *, integer *, integer *, integer 
	    *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nsplci (), nslwsc (), nqpplr ();
#endif /* NO_PROTO */

/*  DRWPLB draws a set of actual polylines using the specified bundle */
/*  values, and a set of expected polylines, using the attribute */
/*  values returned by <inquire predefined polyline representation>. */
/*  It draws the expected polyline incorrectly at the specified */
/*  position. */

/*  Input parameters: */
/*    NUMBUN : number of entries in BUNDIS */
/*    BUNDIS : list of polyline bundle indices to be displayed */
/*    BUNDIF : position of polyline to be drawn incorrectly */
/* aspect source */
/*                bundled     individual */
/*  draw and label actual; use individual attributes */
    /* Parameter adjustments */
    --bundis;

    /* Function Body */
    setasf_(&c__0);
#ifndef NO_PROTO
    xa[0] = .25f;
    xa[1] = .55f;
    yincr = .8f / *numbun;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).25;
    xa[1] = (float).55;
    yincr = (float).8 / *numbun;
    yloc = (float).9;
#endif /* NO_PROTO */
    numlab_(numbun, &c_b22, &yloc, &yincr);
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	ya[0] = yloc;
	ya[1] = yloc;
	nspli (&bundis[ix]);
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L100: */
    }
/*  now draw expected results - with individual attributes from WDT */
/*  use individual attributes */
    setasf_(&c__1);
#ifndef NO_PROTO
    xa[0] = .6f;
    xa[1] = .9f;
    yloc = .9f;
#else /* NO_PROTO */
    xa[0] = (float).6;
    xa[1] = (float).9;
    yloc = (float).9;
#endif /* NO_PROTO */
    i__1 = *numbun;
    for (ix = 1; ix <= i__1; ++ix) {
	nqpplr (&dialog_1.specwt, &bundis[ix], &errind, &pdlt, &pdlw, &pdci);
	chkinq_("pqpplr", &errind, 6L);
	if (ix == *bundif) {
	    pdlt = pdlt % 4 + 1;
#ifndef NO_PROTO
	    pdlw *= 1.5f;
#else /* NO_PROTO */
	    pdlw *= (float)1.5;
#endif /* NO_PROTO */
	    pdci = pdci % 5 + 1;
	}
	nsln (&pdlt);
	nslwsc (&pdlw);
	nsplci (&pdci);
	ya[0] = yloc;
	ya[1] = yloc;
	npl (&c__2, xa, ya);
	yloc -= yincr;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwplb_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.01.02/shplbw                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int shplbw_(char *hding, integer *wkid, real *reqlw, real *
	explw, real *nomlw, real *minlw, char *pfsw, ftnlen hding_len, ftnlen 
	pfsw_len)
#else /* NO_PROTO */
/* Subroutine */ int shplbw_(hding, wkid, reqlw, explw, nomlw, minlw, pfsw, 
	hding_len, pfsw_len)
char *hding;
integer *wkid;
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
    extern /* Subroutine */ int nspli (integer *), nsplr (integer *, integer *
	    , integer *, real *, integer *), dchoic_(char *, integer *, 
	    integer *, integer *, ftnlen), ndellb (integer *, integer *), 
	    opcofl_(void), setasf_(integer *), nsplci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspli (), nsplr (), dchoic_(), ndellb (), 
	    opcofl_(), setasf_(), nsplci ();
#endif /* NO_PROTO */
    static integer numalt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsiasf (integer *, integer *), rnperm_(
	    integer *, integer *), altsiz_(real *, real *, real *, integer *, 
	    integer *, real *), nslwsc (real *), nstxal (integer *, integer *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nsiasf (), rnperm_(), altsiz_(), nslwsc (), 
	    nstxal ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___45 = { 0, digit, 0, "(I1)", 1, 1 };


/*  SHPLBW tests the rendering of a given linewidth, and returns the */
/*  pass/fail result. */

/*  Input parameters: */
/*    HDING : Title for this test */
/*    WKID  : Workstation identifier */
/*    REQLW : The linewidth (in DC) to be requested. */
/*    EXPLW : The expected linewidth (in DC) - the one which should */
/*            be realized in order to pass. */
/*    NOMLW : The nominal linewidth */
/*    MINLW : The minimum linewidth */
/*  Output parameters: */
/*    PFSW  : Result of the test - P for pass, F for fail, A for abort. */

/* aspect source */
/*                bundled     individual */
/* aspect identifier */
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
/*  first simulated -use individual attributes */
    setasf_(&c__1);
    nsln (&c__1);
    nsplci (&c__1);
    nslwsc (&c_b8);
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
/*  now actual - use bundle attributes */
/*  use bundle index #5 */
    setasf_(&c__0);
    r__1 = *reqlw / *nomlw;
    nsplr (wkid, &c__5, &c__1, &r__1, &c__1);
    nspli (&c__5);
/*  set up text for individual attributes */
    for (ix = 6; ix <= 10; ++ix) {
	nsiasf (&ix, &c__1);
/* L110: */
    }
    nstxal (&c__2, &c__3);
    nschh (&c_b47);
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
	s_wsfi(&io___45);
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
} /* shplbw_ */

