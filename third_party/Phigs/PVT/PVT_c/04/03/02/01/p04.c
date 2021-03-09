/* fort/04/03/02/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__801 = 801;
static integer c__1 = 1;
static integer c__106 = 106;
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__2 = 2;
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b30 = 0.f;
static real c_b43 = .3f;
static real c_b44 = .7f;
#else /* NO_PROTO */
static real c_b30 = (float)0.;
static real c_b43 = (float).3;
static real c_b44 = (float).7;
#endif /* NO_PROTO */
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.01/04                        * */
/*  *    TEST TITLE : Simultaneous use of all color table   * */
/*  *                 entries                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[5];
    integer i__1, i__2[5];
    real r__1, r__2, r__3, r__4;
    char ch__1[115];

    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    double sqrt();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real xa[10], ya[10], xf[9]	/* was [3][3] */;
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *), win6_(
	    integer *, integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm (), win6_();
#endif /* NO_PROTO */
    static integer perm[6];
    static real xloc;
    static integer txci, ngsq;
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *), nscr (integer *, 
	    integer *, integer *, real *), nsmk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcr (), nscr (), nsmk ();
#endif /* NO_PROTO */
    static real xsiz, ysiz, side1, side2;
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum2, rdum3;
    static integer maxci;
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_(), endit_();
#endif /* NO_PROTO */
    static real sqinc;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern /* Subroutine */ int nqpmf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nclst (void), nemst (integer *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern /* Subroutine */ int nqpmf (), nclst (), nemst ();
#endif /* NO_PROTO */
    static real nomms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    nopst (integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), nopst (), nsvwi ();
#endif /* NO_PROTO */
    static real bckcol[3];
    static char sidlbl[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpfv_(char *, integer *, integer *, ftnlen),
	     chkinq_(char *, integer *, ftnlen), setdlg_(integer *, integer *,
	     integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpfv_(), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, numret, sqside;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer colsiz, nxtcol, window;
    static real mrksiz, forcol[3], xwinlo[6], ywinlo[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    nsmksc (real *), rnperm_(integer *, integer *), nspmci (integer *)
	    , sqgrmk_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nqwksl (), 
	    setmsg_(), nsmksc (), rnperm_(), nspmci (), sqgrmk_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___39 = { 0, sidlbl, 0, "(I3)", 3, 1 };


/* aspect source */
/*                bundled     individual */
/* marker type */
/*  type of returned value */
/*  composition type */
/*  colour model */
/*  Declare program-specific variables */
    initgl_("04.03.02.01/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nexst (&c__106);
    nexst (&c__102);
    nclst ();
/*  divide screen up into six labelled square areas */
    win6_(&c__106, &c__1, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__102);
/*  inquire color representation #0 as realized to determine */
/*    bckcol = background color */
    nqcr (&globnu_1.wkid, &c__0, &c__3, &c__1, &errind, &numret, bckcol);
    chkinq_("pqcr", &errind, 4L);
/*  inquire color representation #1 as realized to determine */
/*    forcol = foreground color */
    nqcr (&globnu_1.wkid, &c__1, &c__3, &c__1, &errind, &numret, forcol);
    chkinq_("pqcr", &errind, 4L);
/*  inquire workstation state table lengths to determine */
/*    colsiz = number of settable entries in color table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &colsiz, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  maxci = maximum color index = colsiz-1 */
    maxci = colsiz - 1;

#ifndef NO_PROTO
    setmsg_("1 2 7", "All the entries within the reported size of the color "
	    "table should be usable and effective.", 5L, 91L);
#else /* NO_PROTO */
    setmsg_("1 2 7", "All the entries within the reported size of the color \
table should be usable and effective.", 5L, 91L);
#endif /* NO_PROTO */
/*  set all even entries = background color */
/*           odd entries = foreground color: */
    i__1 = maxci;
    for (ix = 2; ix <= i__1; ix += 2) {
	nscr (&globnu_1.wkid, &ix, &c__3, bckcol);
/* L100: */
    }
    i__1 = maxci;
    for (ix = 3; ix <= i__1; ix += 2) {
	nscr (&globnu_1.wkid, &ix, &c__3, forcol);
/* L110: */
    }
/*  sqside = integer number of polymarkers per side of square array */
/*  (this ensures all color slots will be used) */
/*  side1 = 0.1, side2 = 0.9 */
/*  sqinc = increment for square = (side2-side1) / (sqside-1) */
/*  mrksiz = polymarker size = min(0.05, 0.2 * sqinc) */
#ifndef NO_PROTO
    sqside = sqrt(colsiz / 4.f + 1) + 1;
    side1 = .1f;
    side2 = .9f;
#else /* NO_PROTO */
    sqside = sqrt(colsiz / (float)4. + 1) + 1;
    side1 = (float).1;
    side2 = (float).9;
#endif /* NO_PROTO */
    sqinc = (side2 - side1) / (sqside - 1);
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = .05f, r__2 = sqinc * .1f;
#else /* NO_PROTO */
    r__1 = (float).05, r__2 = sqinc * (float).1;
#endif /* NO_PROTO */
    mrksiz = dmin(r__1,r__2);
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum2, &rdum3, &idum4);
    chkinq_("pqpmf", &errind, 5L);
/*  set polymarker size = mrksiz (in WC) */
    r__1 = mrksiz / (nomms * dialog_1.wcpdc);
    nsmksc (&r__1);
/*  set polymarker style = plus (+) */
    nsmk (&c__2);
/*  perm = randomize order from 1 to 6 */
    rnperm_(&c__6, perm);
/*  nxtcol = next color index to use = 0 */
    nxtcol = 0;
    for (ix = 1; ix <= 6; ++ix) {
	window = perm[ix - 1];
	ebltm_(&c_b30, &c_b30, &xwinlo[ix - 1], &ywinlo[ix - 1], &c_b30, &
		xsiz, &xsiz, xf);
	nslmt (xf, &c__2);
	if (window == 1) {
/*  simulate incorrect display. */
	    ngsq = ix;
	    nspmci (&c__1);
#ifndef NO_PROTO
	    r__1 = side2 + sqinc * .5f;
#else /* NO_PROTO */
	    r__1 = side2 + sqinc * (float).5;
#endif /* NO_PROTO */
	    sqgrmk_(&side1, &r__1, &sqinc);
/*  put a polymarker at a non-aligned position: */
	    i__1 = sqside - 2;
#ifndef NO_PROTO
	    xa[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + .5f);
#else /* NO_PROTO */
	    xa[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + (float).5);
#endif /* NO_PROTO */
	    i__1 = sqside - 2;
#ifndef NO_PROTO
	    ya[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + .5f);
#else /* NO_PROTO */
	    ya[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + (float).5);
#endif /* NO_PROTO */
	    npm (&c__1, xa, ya);
	} else if (window == 2) {
/*  simulate correct display: */
	    nspmci (&c__1);
#ifndef NO_PROTO
	    r__1 = side2 + sqinc * .5f;
#else /* NO_PROTO */
	    r__1 = side2 + sqinc * (float).5;
#endif /* NO_PROTO */
	    sqgrmk_(&side1, &r__1, &sqinc);
	} else {
/*  for other windows, draw actual grid */
#ifndef NO_PROTO
	    r__1 = side2 + sqinc * .5f;
#else /* NO_PROTO */
	    r__1 = side2 + sqinc * (float).5;
#endif /* NO_PROTO */
	    r__2 = sqinc;
	    for (xloc = side1; r__2 < 0 ? xloc >= r__1 : xloc <= r__1; xloc +=
		     r__2) {
#ifndef NO_PROTO
		r__3 = side2 + sqinc * .5f;
#else /* NO_PROTO */
		r__3 = side2 + sqinc * (float).5;
#endif /* NO_PROTO */
		r__4 = sqinc;
		for (yloc = side1; r__4 < 0 ? yloc >= r__3 : yloc <= r__3; 
			yloc += r__4) {
/*  visible aligned marker: */
		    if (nxtcol < maxci) {
			++nxtcol;
		    } else {
			nxtcol = 1;
		    }
/*  set polymarker color = nxtcol */
		    nspmci (&nxtcol);
		    xa[0] = xloc;
		    ya[0] = yloc;
		    npm (&c__1, xa, ya);
/*  invisible mis-aligned marker: */
		    if (nxtcol < maxci) {
			++nxtcol;
		    } else {
			nxtcol = 0;
		    }
/*  set polymarker color = nxtcol */
		    nspmci (&nxtcol);
/*  put a polymarker at a non-aligned position: the RNDRL 
makes it */
/*  unlikely that a bad (visible) polymarker will be overw
ritten */
/*  by a good (invisible) one. */
		    i__1 = sqside - 2;
		    xa[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + rndrl_(&
			    c_b43, &c_b44));
		    i__1 = sqside - 2;
		    ya[0] = side1 + sqinc * (rndint_(&c__0, &i__1) + rndrl_(&
			    c_b43, &c_b44));
		    npm (&c__1, xa, ya);
/* L240: */
		}
/* L245: */
	    }
	}
/* L200: */
    }
    s_wsfi(&io___39);
    do_fio(&c__1, (char *)&sqside, (ftnlen)sizeof(integer));
    e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 58, a__1[0] = "USE OF ENTIRE COLOUR TABLE: Which area does NOT"
	    " contain a ";
#else /* NO_PROTO */
    i__2[0] = 58, a__1[0] = "USE OF ENTIRE COLOUR TABLE: Which area does NOT\
 contain a ";
#endif /* NO_PROTO */
    i__2[1] = 3, a__1[1] = sidlbl;
    i__2[2] = 4, a__1[2] = " by ";
    i__2[3] = 3, a__1[3] = sidlbl;
    i__2[4] = 47, a__1[4] = " square grid of polymarkers of a single colour?";

    s_cat(ch__1, a__1, i__2, &c__5, 115L);
    dchpfv_(ch__1, &c__6, &ngsq, 115L);
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

