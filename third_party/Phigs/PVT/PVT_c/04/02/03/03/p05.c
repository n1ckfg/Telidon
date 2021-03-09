/* fort/04/02/03/03/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b11 = 1.f;
static real c_b12 = 0.f;
#else /* NO_PROTO */
static real c_b11 = (float)1.;
static real c_b12 = (float)0.;
#endif /* NO_PROTO */
static integer c__5 = 5;
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b37 = -2.f;
static real c_b38 = 2.f;
#else /* NO_PROTO */
static real c_b37 = (float)-2.;
static real c_b38 = (float)2.;
#endif /* NO_PROTO */
static doublereal c_b39 = 10.;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b114 = -3.f;
static real c_b115 = 3.f;
#else /* NO_PROTO */
static real c_b114 = (float)-3.;
static real c_b115 = (float)3.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.03/05                        * */
/*  *    TEST TITLE : Text extent results derived from      * */
/*  *                 nominal character sizes               * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static char tchars[1*3] = "W" "." " ";
#else /* NO_PROTO */
    static char tchars[1*3+1] = "W. ";
#endif /* NO_PROTO */
    static integer tcix[9] = { 1,1,3,3,3,2,2,2,2 };
#ifndef NO_PROTO
    static real htab[3] = { 0.f,.5f,1.f };
    static char hnam[6*3] = "LEFT  " "CENTRE" "RIGHT ";
    static char vnam[6*5] = "TOP   " "CAP   " "HALF  " "BASE  " "BOTTOM";
    static char nmtxp[5*4] = "RIGHT" "LEFT " "UP   " "DOWN ";
#else /* NO_PROTO */
    static real htab[3] = { (float)0.,(float).5,(float)1. };
    static char hnam[6*3+1] = "LEFT  CENTRERIGHT ";
    static char vnam[6*5+1] = "TOP   CAP   HALF  BASE  BOTTOM";
    static char nmtxp[5*4+1] = "RIGHTLEFT UP   DOWN ";
#endif /* NO_PROTO */

    /* System generated locals */
    real r__1, r__2;
    doublereal d__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    double pow_dd(doublereal *, doublereal *);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    double pow_dd();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char msg[300];
    static real ncw[6]	/* was [3][2] */, xhi, yhi, xlo, ylo;
    static integer txp;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static real chht, acpx, acpy, chsp;
    static integer pdir;
    static real vtab[5], ccpx, chxp, xoff, yoff, ccpy;
    static integer font;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static real minx, maxx, curx, xsiz, ysiz, chht2, a2cpx, a2cpy;
    static integer idum1;
    static real chxp2, minch;
    static logical ccpok;
    static real maxch;
    static logical negok;
    static real nomch;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical appeq_();
#endif /* NO_PROTO */
    static logical locok;
    static real mincw;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real maxcw;
    static integer txalh;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static logical nomok;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer txalv;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static char testr[9];
    static real nomrx, ncwsz[3], nomvw;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxx (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, char *, integer *, real *
	    , real *, real *, real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx ();
#endif /* NO_PROTO */
    static real t2exrx[2], t2exry[2], chrinc;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static real thiscw, abstol, reltol;
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), prpfnt_(integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), prpfnt_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */
    static real txexrx[2], txexry[2];

    /* Fortran I/O blocks */
    static icilist io___12 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___60 = { 0, msg, 0, "(A,3F11.4,7A)", 300, 1 };
    static icilist io___61 = { 0, msg, 0, "(A,3F11.4,7A)", 300, 1 };
    static icilist io___62 = { 0, msg, 0, "(A,3F11.4,7A)", 300, 1 };
    static icilist io___66 = { 0, msg, 0, "(A,3F11.4,7A)", 300, 1 };
    static icilist io___67 = { 0, msg, 0, "(A,3F11.4,7A)", 300, 1 };
    static icilist io___68 = { 0, msg, 0, "(A,3F11.4,7A)", 300, 1 };


/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/*  number of characters in string */
    initgl_("04.02.03.03/05", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Establish specwt = specific primary workstation type */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &idum1, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  font = a randomly selected font; non-monospaced if possible */
    prpfnt_(&specwt, &font);
    s_wsfi(&io___12);
    do_fio(&c__1, "Font selected for test: ", 24L);
    do_fio(&c__1, (char *)&font, (ftnlen)sizeof(integer));
    do_fio(&c__1, ".", 1L);
    e_wsfi();
    inmsg_(msg, 300L);
/*     mincw,maxcw = minimum,maximum value for ncw for vertical paths */
#ifndef NO_PROTO
    mincw = 1e35f;
    maxcw = -1e35f;
#else /* NO_PROTO */
    mincw = (float)1e35;
    maxcw = (float)-1e35;
#endif /* NO_PROTO */
/*     minch,maxch = minimum,maximum value for nch for all paths */
#ifndef NO_PROTO
    minch = 1e35f;
    maxch = -1e35f;
#else /* NO_PROTO */
    minch = (float)1e35;
    maxch = (float)-1e35;
#endif /* NO_PROTO */
/*  for text path = RIGHT,LEFT,UP,DOWN */
    for (txp = 0; txp <= 3; ++txp) {
/*  <inquire text extent> to determine: */
/*     ncw,nch = nominal character body width,height for "W", ".", " "
 */
	for (ix = 1; ix <= 3; ++ix) {
	    nqtxx (&specwt, &font, &c_b11, &c_b12, &c_b11, &txp, &c__1, &c__5,
		     tchars + (ix - 1), &errind, txexrx, txexry, &acpx, &acpy,
		     1L);
	    chkinq_("pqtxx", &errind, 5L);
	    thiscw = (r__1 = txexrx[1] - txexrx[0], dabs(r__1));
	    if (txp == 1 || txp == 0) {
/*  character widths for horizontal path */
		ncw[ix + txp * 3 - 1] = thiscw;
	    } else {
/*  vertical path */
		mincw = dmin(mincw,thiscw);
		maxcw = dmax(maxcw,thiscw);
	    }
	    minch = dmin(minch,txexry[1]);
	    maxch = dmax(maxch,txexry[1]);
/* L110: */
	}
/*  next text path */
/* L100: */
    }
/*  tests for nominal size all OK */
    nomok = TRUE_;
#ifndef NO_PROTO
    setmsg_("1 2 3 15 16", "The nominal height of all character bodies for a"
	    " given font should be equal, regardless of text path.", 11L, 101L)
	    ;
#else /* NO_PROTO */
    setmsg_("1 2 3 15 16", "The nominal height of all character bodies for a\
 given font should be equal, regardless of text path.", 11L, 101L);
#endif /* NO_PROTO */
/*  tolerances for comparison, based on char-ht = 1 */
#ifndef NO_PROTO
    abstol = .02f;
    reltol = .02f;
#else /* NO_PROTO */
    abstol = (float).02;
    reltol = (float).02;
#endif /* NO_PROTO */
/*  pass/fail depending on (minch approx= maxch) */
    if (appeq_(&minch, &maxch, &abstol, &reltol)) {
	pass_();
	nomch = (minch + maxch) / 2;
    } else {
	fail_();
	nomok = FALSE_;
    }
#ifndef NO_PROTO
    setmsg_("1 2 3 16", "The nominal rectangle width of all vertical text pa"
	    "ths for a given font should be equal.", 8L, 88L);
#else /* NO_PROTO */
    setmsg_("1 2 3 16", "The nominal rectangle width of all vertical text pa\
ths for a given font should be equal.", 8L, 88L);
#endif /* NO_PROTO */
/*  pass/fail depending on (mincw approx= maxcw) */
    if (appeq_(&mincw, &maxcw, &abstol, &reltol)) {
	pass_();
	nomvw = (mincw + maxcw) / 2;
    } else {
	fail_();
	nomok = FALSE_;
    }
#ifndef NO_PROTO
    setmsg_("1 2 3 15", "The nominal rectangle width for a given font and te"
	    "xt string should be equal for all horizontal text paths.", 8L, 
	    107L);
#else /* NO_PROTO */
    setmsg_("1 2 3 15", "The nominal rectangle width for a given font and te\
xt string should be equal for all horizontal text paths.", 8L, 107L);
#endif /* NO_PROTO */
    if (appeq_(&ncw[3], ncw, &abstol, &reltol) && appeq_(&ncw[4], &ncw[1], &
	    abstol, &reltol) && appeq_(&ncw[5], &ncw[2], &abstol, &reltol)) {
	pass_();
/*  nominal widths for "W", ".", " " */
	ncwsz[0] = (ncw[0] + ncw[3]) / 2;
	ncwsz[1] = (ncw[1] + ncw[4]) / 2;
	ncwsz[2] = (ncw[2] + ncw[5]) / 2;
    } else {
	fail_();
	nomok = FALSE_;
    }
    if (! nomok) {
#ifndef NO_PROTO
	inmsg_("No more test cases can be executed because nominal sizes can"
		"not be determined.", 78L);
#else /* NO_PROTO */
	inmsg_("No more test cases can be executed because nominal sizes can\
not be determined.", 78L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  get nominal displacements for vertical text alignments: */
/*    vtab(TOP,CAP,HALF,BASE,BOTTOM) = vertical offsets from TOP */
    for (txalv = 1; txalv <= 5; ++txalv) {
	nqtxx (&specwt, &font, &c_b11, &c_b12, &c_b11, &c__0, &c__1, &txalv, 
		"W", &errind, txexrx, txexry, &acpx, &acpy, 1L);
	chkinq_("pqtxx", &errind, 5L);
	vtab[txalv - 1] = txexry[1];
/* L200: */
    }
/*  test text string, based on TCIX - picks out characters */
/*  also compute nomimal width for horizontal */
#ifndef NO_PROTO
    nomrx = 0.f;
#else /* NO_PROTO */
    nomrx = (float)0.;
#endif /* NO_PROTO */
    for (ix = 1; ix <= 9; ++ix) {
	testr[ix - 1] = tchars[tcix[ix - 1] - 1];
	nomrx += ncwsz[tcix[ix - 1] - 1];
/* L250: */
    }
/*  *** *** *** ***   horizontal text paths   *** *** *** *** */
    locok = TRUE_;
    ccpok = TRUE_;
    negok = TRUE_;
/*  nomrx = nominal horizontal rectangle size, */
/*  based on nomvw,nomch, ncwsz */
/*  for horizontal text paths */
    for (txp = 0; txp <= 1; ++txp) {
/*  direction for path */
	if (txp == 0) {
	    pdir = 1;
	} else {
	    pdir = -1;
	}
/*  for all text alignments (txal) */
	for (txalh = 1; txalh <= 3; ++txalh) {
	    for (txalv = 1; txalv <= 5; ++txalv) {
/*  chht,chxp,chsp = some random values for character height, 
*/
/*    expansion factor, and spacing */
		d__1 = (doublereal) rndrl_(&c_b37, &c_b38);
		chht = pow_dd(&c_b39, &d__1);
		d__1 = (doublereal) rndrl_(&c_b37, &c_b38);
		chxp = pow_dd(&c_b39, &d__1);
		r__1 = chxp * -3;
		r__2 = chxp * 3;
		chsp = rndrl_(&r__1, &r__2);
/*  calculate expected value for: */
/*     xlo,xhi,ylo,yhi = position of text extent rectangle */
/*     ccpx,ccpy       = concatenation point */
/*  build logical string - this is necessary because character
 */
/*  spacing may go backwards for skinny characters, and forwar
d */
/*  for thick characters */
#ifndef NO_PROTO
		minx = 1e35f;
		maxx = -1e35f;
#else /* NO_PROTO */
		minx = (float)1e35;
		maxx = (float)-1e35;
#endif /* NO_PROTO */
/*  current position of 0 */
#ifndef NO_PROTO
		curx = 0.f;
#else /* NO_PROTO */
		curx = (float)0.;
#endif /* NO_PROTO */
		for (ix = 1; ix <= 9; ++ix) {
/*  first edge of current character */
		    minx = dmin(minx,curx);
		    maxx = dmax(maxx,curx);
		    curx += pdir * chxp * ncwsz[tcix[ix - 1] - 1];
/*  second edge of current character */
		    minx = dmin(minx,curx);
		    maxx = dmax(maxx,curx);
		    curx += pdir * chsp;
/* L450: */
		}
		ccpx = curx;
/*  shift based on horizontal alignment */
		xsiz = maxx - minx;
		xoff = -(doublereal)htab[txalh - 1] * xsiz - minx;
		xlo = minx + xoff;
		xhi = maxx + xoff;
		ccpx += xoff;
/*  vertical based only on alignment */
		yhi = vtab[txalv - 1];
		ylo = yhi - nomch;
#ifndef NO_PROTO
		ccpy = 0.f;
#else /* NO_PROTO */
		ccpy = (float)0.;
#endif /* NO_PROTO */
/*  scale everything by character height */
		xlo *= chht;
		xhi *= chht;
		ccpx *= chht;
		yhi *= chht;
		ylo *= chht;
		ccpy *= chht;
/*  determine actual rectangle: */
		nqtxx (&specwt, &font, &chxp, &chsp, &chht, &txp, &txalh, &
			txalv, testr, &errind, txexrx, txexry, &acpx, &acpy, 
			9L);
		chkinq_("pqtxx", &errind, 5L);
/*  set up for negative values */
		ix = rndint_(&c__1, &c__3);
		if (ix == 1) {
		    chht2 = -(doublereal)chht;
		    chxp2 = -(doublereal)chxp;
		} else if (ix == 2) {
		    chht2 = chht;
		    chxp2 = -(doublereal)chxp;
		} else {
		    chht2 = -(doublereal)chht;
		    chxp2 = chxp;
		}
/*  determine 2nd actual rectangle, with negative values: */
		nqtxx (&specwt, &font, &chxp2, &chsp, &chht2, &txp, &txalh, &
			txalv, testr, &errind, t2exrx, t2exry, &a2cpx, &a2cpy,
			 9L);
		chkinq_("pqtxx", &errind, 5L);
		if (txexrx[0] == t2exrx[0] && txexrx[1] == t2exrx[1] && 
			txexry[0] == t2exry[0] && txexry[1] == t2exry[1] && 
			acpx == a2cpx && acpy == a2cpy) {
/*           OK, then ... */
		} else {
		    s_wsfi(&io___60);
#ifndef NO_PROTO
		    do_fio(&c__1, "Inconsistent locations with negative char"
			    "acter height or expansion, for character height,"
			    " expansion, and spacing = ", 115L);
#else /* NO_PROTO */
		    do_fio(&c__1, "Inconsistent locations with negative char\
acter height or expansion, for character height, expansion, and spacing = ", 
			    115L);
#endif /* NO_PROTO */
		    do_fio(&c__1, (char *)&chht2, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chxp2, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chsp, (ftnlen)sizeof(real));
		    do_fio(&c__1, " with text path = ", 18L);
		    do_fio(&c__1, nmtxp + txp * 5, 5L);
		    do_fio(&c__1, " and alignment = [", 18L);
		    do_fio(&c__1, hnam + (txalh - 1) * 6, 6L);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, vnam + (txalv - 1) * 6, 6L);
		    do_fio(&c__1, "].", 2L);
		    e_wsfi();
		    inmsg_(msg, 300L);
		    negok = FALSE_;
		}
/*  tolerances for comparison, based on char-ht */
#ifndef NO_PROTO
		abstol = dabs(chht) * .02f;
		reltol = .02f;
#else /* NO_PROTO */
		abstol = dabs(chht) * (float).02;
		reltol = (float).02;
#endif /* NO_PROTO */
		if (appeq_(txexrx, &xlo, &abstol, &reltol) && appeq_(&txexrx[
			1], &xhi, &abstol, &reltol) && appeq_(txexry, &ylo, &
			abstol, &reltol) && appeq_(&txexry[1], &yhi, &abstol, 
			&reltol)) {
/*           OK, then ... */
		} else {
		    s_wsfi(&io___61);
#ifndef NO_PROTO
		    do_fio(&c__1, "Incorrect rectangle location for characte"
			    "r height, expansion, and spacing = ", 76L);
#else /* NO_PROTO */
		    do_fio(&c__1, "Incorrect rectangle location for characte\
r height, expansion, and spacing = ", 76L);
#endif /* NO_PROTO */
		    do_fio(&c__1, (char *)&chht, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chxp, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chsp, (ftnlen)sizeof(real));
		    do_fio(&c__1, " with text path = ", 18L);
		    do_fio(&c__1, nmtxp + txp * 5, 5L);
		    do_fio(&c__1, " and alignment = [", 18L);
		    do_fio(&c__1, hnam + (txalh - 1) * 6, 6L);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, vnam + (txalv - 1) * 6, 6L);
		    do_fio(&c__1, "].", 2L);
		    e_wsfi();
		    inmsg_(msg, 300L);
		    locok = FALSE_;
		}
		if (appeq_(&acpx, &ccpx, &abstol, &reltol) && appeq_(&acpy, &
			ccpy, &abstol, &reltol)) {
/*           OK, then ... */
		} else {
		    s_wsfi(&io___62);
#ifndef NO_PROTO
		    do_fio(&c__1, "Incorrect concatenation point location fo"
			    "r character height, expansion, and spacing = ", 
			    86L);
#else /* NO_PROTO */
		    do_fio(&c__1, "Incorrect concatenation point location fo\
r character height, expansion, and spacing = ", 86L);
#endif /* NO_PROTO */
		    do_fio(&c__1, (char *)&chht, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chxp, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chsp, (ftnlen)sizeof(real));
		    do_fio(&c__1, " with text path = ", 18L);
		    do_fio(&c__1, nmtxp + txp * 5, 5L);
		    do_fio(&c__1, " and alignment = [", 18L);
		    do_fio(&c__1, hnam + (txalh - 1) * 6, 6L);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, vnam + (txalv - 1) * 6, 6L);
		    do_fio(&c__1, "].", 2L);
		    e_wsfi();
		    inmsg_(msg, 300L);
		    ccpok = FALSE_;
		}
/*  next alignment */
/* L410: */
	    }
/* L400: */
	}
/*  next text path */
/* L300: */
    }
#ifndef NO_PROTO
    setmsg_("6 8 10 15 17 18", "Negating the character height or expansion f"
	    "actor should not change the location of a horizontal text extent"
	    " rectangle nor its associated concatenation point.", 15L, 158L);
#else /* NO_PROTO */
    setmsg_("6 8 10 15 17 18", "Negating the character height or expansion f\
actor should not change the location of a horizontal text extent rectangle n\
or its associated concatenation point.", 15L, 158L);
#endif /* NO_PROTO */
    ifpf_(&negok);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 7 8 9 10 11 13 14 15", "For any valid parameter values,"
	    " the location of a horizontal text extent rectangle should be as"
	    " derived from nominal character body sizes and from nominal text"
	    " alignments.", 28L, 171L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 7 8 9 10 11 13 14 15", "For any valid parameter values,\
 the location of a horizontal text extent rectangle should be as derived fro\
m nominal character body sizes and from nominal text alignments.", 28L, 171L);

#endif /* NO_PROTO */
    ifpf_(&locok);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 7 8 9 10 11 13 14 17 18", "For any valid parameter valu"
	    "es, the location of the concatenation point following a horizont"
	    "al text extent rectangle should be as derived from nominal chara"
	    "cter body sizes and from nominal text alignments.", 31L, 205L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 7 8 9 10 11 13 14 17 18", "For any valid parameter valu\
es, the location of the concatenation point following a horizontal text exte\
nt rectangle should be as derived from nominal character body sizes and from\
 nominal text alignments.", 31L, 205L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
/*  *** *** *** ***   vertical text paths   *** *** *** *** */
    locok = TRUE_;
    ccpok = TRUE_;
    negok = TRUE_;
/*  for vertical text paths */
    for (txp = 2; txp <= 3; ++txp) {
/*  for all text alignments (txal) */
	for (txalh = 1; txalh <= 3; ++txalh) {
	    for (txalv = 1; txalv <= 5; ++txalv) {
/*  chht,chxp,chsp = some random values for character height, 
*/
/*    expansion factor, and spacing */
		d__1 = (doublereal) rndrl_(&c_b37, &c_b38);
		chht = pow_dd(&c_b39, &d__1);
		d__1 = (doublereal) rndrl_(&c_b37, &c_b38);
		chxp = pow_dd(&c_b39, &d__1);
		chsp = rndrl_(&c_b114, &c_b115);
/*  calculate expected value for: */
/*     xlo,xhi,ylo,yhi = position of text extent rectangle */
/*     ccpx,ccpy       = concatenation point */
/*  character increment */
		chrinc = nomch + chsp;
		ysiz = nomch + dabs(chrinc) * 8;
#ifndef NO_PROTO
		ccpx = 0.f;
#else /* NO_PROTO */
		ccpx = (float)0.;
#endif /* NO_PROTO */
		xlo = -(doublereal)htab[txalh - 1] * nomvw * chxp;
		xhi = xlo + nomvw * chxp;
/*  compute Y-values for TOP alignment */
#ifndef NO_PROTO
		yhi = 0.f;
#else /* NO_PROTO */
		yhi = (float)0.;
#endif /* NO_PROTO */
		ylo = -(doublereal)ysiz;
		if (txp == 2) {
#ifndef NO_PROTO
		    if (chrinc < 0.f) {
#else /* NO_PROTO */
		    if (chrinc < (float)0.) {
#endif /* NO_PROTO */
			ccpy = chrinc * 9 - vtab[3];
		    } else {
			ccpy = chsp + vtab[4] - vtab[3];
		    }
		} else {
#ifndef NO_PROTO
		    if (chrinc < 0.f) {
#else /* NO_PROTO */
		    if (chrinc < (float)0.) {
#endif /* NO_PROTO */
			ccpy = -(doublereal)chrinc;
		    } else {
			ccpy = chrinc * -9;
		    }
		}
/*  offset for alignment */
		if (txalv == 5) {
		    yoff = ysiz;
		} else if (txalv == 4) {
		    yoff = ysiz + vtab[3] - vtab[4];
		} else if (txalv == 3) {
#ifndef NO_PROTO
		    yoff = vtab[2] + dabs(chrinc) * 4.f;
#else /* NO_PROTO */
		    yoff = vtab[2] + dabs(chrinc) * (float)4.;
#endif /* NO_PROTO */
		} else if (txalv == 2) {
		    yoff = vtab[1];
		} else {
/*  alignment = TOP */
#ifndef NO_PROTO
		    yoff = 0.f;
#else /* NO_PROTO */
		    yoff = (float)0.;
#endif /* NO_PROTO */
		}
/*  offset y-values and then scale everything by character hei
ght */
		xlo *= chht;
		xhi *= chht;
		ccpx *= chht;
		yhi = (yhi + yoff) * chht;
		ylo = (ylo + yoff) * chht;
		ccpy = (ccpy + yoff) * chht;
/*  determine actual rectangle: */
		nqtxx (&specwt, &font, &chxp, &chsp, &chht, &txp, &txalh, &
			txalv, testr, &errind, txexrx, txexry, &acpx, &acpy, 
			9L);
		chkinq_("pqtxx", &errind, 5L);
/*  set up for negative values */
		ix = rndint_(&c__1, &c__3);
		if (ix == 1) {
		    chht2 = -(doublereal)chht;
		    chxp2 = -(doublereal)chxp;
		} else if (ix == 2) {
		    chht2 = chht;
		    chxp2 = -(doublereal)chxp;
		} else {
		    chht2 = -(doublereal)chht;
		    chxp2 = chxp;
		}
/*  determine 2nd actual rectangle, with negative values: */
		nqtxx (&specwt, &font, &chxp2, &chsp, &chht2, &txp, &txalh, &
			txalv, testr, &errind, t2exrx, t2exry, &a2cpx, &a2cpy,
			 9L);
		chkinq_("pqtxx", &errind, 5L);
		if (txexrx[0] == t2exrx[0] && txexrx[1] == t2exrx[1] && 
			txexry[0] == t2exry[0] && txexry[1] == t2exry[1] && 
			acpx == a2cpx && acpy == a2cpy) {
/*           OK, then ... */
		} else {
		    s_wsfi(&io___66);
#ifndef NO_PROTO
		    do_fio(&c__1, "Inconsistent locations with negative char"
			    "acter height or expansion, for character height,"
			    " expansion, and spacing = ", 115L);
#else /* NO_PROTO */
		    do_fio(&c__1, "Inconsistent locations with negative char\
acter height or expansion, for character height, expansion, and spacing = ", 
			    115L);
#endif /* NO_PROTO */
		    do_fio(&c__1, (char *)&chht2, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chxp2, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chsp, (ftnlen)sizeof(real));
		    do_fio(&c__1, " with text path = ", 18L);
		    do_fio(&c__1, nmtxp + txp * 5, 5L);
		    do_fio(&c__1, " and alignment = [", 18L);
		    do_fio(&c__1, hnam + (txalh - 1) * 6, 6L);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, vnam + (txalv - 1) * 6, 6L);
		    do_fio(&c__1, "].", 2L);
		    e_wsfi();
		    inmsg_(msg, 300L);
		    negok = FALSE_;
		}
/*  tolerances for comparison, based on char-ht */
#ifndef NO_PROTO
		abstol = dabs(chht) * .02f;
		reltol = .02f;
#else /* NO_PROTO */
		abstol = dabs(chht) * (float).02;
		reltol = (float).02;
#endif /* NO_PROTO */
		if (appeq_(txexrx, &xlo, &abstol, &reltol) && appeq_(&txexrx[
			1], &xhi, &abstol, &reltol) && appeq_(txexry, &ylo, &
			abstol, &reltol) && appeq_(&txexry[1], &yhi, &abstol, 
			&reltol)) {
/*           OK, then ... */
		} else {
		    s_wsfi(&io___67);
#ifndef NO_PROTO
		    do_fio(&c__1, "Incorrect rectangle location for characte"
			    "r height, expansion, and spacing = ", 76L);
#else /* NO_PROTO */
		    do_fio(&c__1, "Incorrect rectangle location for characte\
r height, expansion, and spacing = ", 76L);
#endif /* NO_PROTO */
		    do_fio(&c__1, (char *)&chht, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chxp, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chsp, (ftnlen)sizeof(real));
		    do_fio(&c__1, " with text path = ", 18L);
		    do_fio(&c__1, nmtxp + txp * 5, 5L);
		    do_fio(&c__1, " and alignment = [", 18L);
		    do_fio(&c__1, hnam + (txalh - 1) * 6, 6L);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, vnam + (txalv - 1) * 6, 6L);
		    do_fio(&c__1, "].", 2L);
		    e_wsfi();
		    inmsg_(msg, 300L);
		    locok = FALSE_;
		}
		if (appeq_(&acpx, &ccpx, &abstol, &reltol) && appeq_(&acpy, &
			ccpy, &abstol, &reltol)) {
/*           OK, then ... */
		} else {
		    s_wsfi(&io___68);
#ifndef NO_PROTO
		    do_fio(&c__1, "Incorrect concatenation point location fo"
			    "r character height, expansion, and spacing = ", 
			    86L);
#else /* NO_PROTO */
		    do_fio(&c__1, "Incorrect concatenation point location fo\
r character height, expansion, and spacing = ", 86L);
#endif /* NO_PROTO */
		    do_fio(&c__1, (char *)&chht, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chxp, (ftnlen)sizeof(real));
		    do_fio(&c__1, (char *)&chsp, (ftnlen)sizeof(real));
		    do_fio(&c__1, " with text path = ", 18L);
		    do_fio(&c__1, nmtxp + txp * 5, 5L);
		    do_fio(&c__1, " and alignment = [", 18L);
		    do_fio(&c__1, hnam + (txalh - 1) * 6, 6L);
		    do_fio(&c__1, ",", 1L);
		    do_fio(&c__1, vnam + (txalv - 1) * 6, 6L);
		    do_fio(&c__1, "].", 2L);
		    e_wsfi();
		    inmsg_(msg, 300L);
		    ccpok = FALSE_;
		}
/*  next alignment */
/* L610: */
	    }
/* L600: */
	}
/*  next text path */
/* L500: */
    }
#ifndef NO_PROTO
    setmsg_("6 8 10 16 17 18", "Negating the character height or expansion f"
	    "actor should not change the location of a vertical text extent r"
	    "ectangle nor its associated concatenation point.", 15L, 156L);
#else /* NO_PROTO */
    setmsg_("6 8 10 16 17 18", "Negating the character height or expansion f\
actor should not change the location of a vertical text extent rectangle nor\
 its associated concatenation point.", 15L, 156L);
#endif /* NO_PROTO */
    ifpf_(&negok);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 7 8 9 10 11 13 14 16", "For any valid parameter values,"
	    " the location of a vertical text extent rectangle should be as d"
	    "erived from nominal character body sizes and from nominal text a"
	    "lignments.", 28L, 169L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 7 8 9 10 11 13 14 16", "For any valid parameter values,\
 the location of a vertical text extent rectangle should be as derived from \
nominal character body sizes and from nominal text alignments.", 28L, 169L);
#endif /* NO_PROTO */
    ifpf_(&locok);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 7 8 9 10 11 13 14 17 18", "For any valid parameter valu"
	    "es, the location of the concatenation point following a vertical"
	    " text extent rectangle should be as derived from nominal charact"
	    "er body sizes and from nominal text alignments.", 31L, 203L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 7 8 9 10 11 13 14 17 18", "For any valid parameter valu\
es, the location of the concatenation point following a vertical text extent\
 rectangle should be as derived from nominal character body sizes and from n\
ominal text alignments.", 31L, 203L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
/*  endprog: */
L666:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

