/* nmscol.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    integer black, green, yellow, white, blue;
} colors_;

#define colors_1 colors_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int nmscol_(integer *wkid)
#else /* NO_PROTO */
/* Subroutine */ int nmscol_(wkid)
integer *wkid;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real blck[3] = { 0.f,0.f,0.f };
    static real grn[3] = { 0.f,1.f,0.f };
    static real yellw[3] = { 1.f,1.f,0.f };
    static real wht[3] = { 1.f,1.f,1.f };
    static real blu[3] = { 0.f,0.f,1.f };
#else /* NO_PROTO */
    static real blck[3] = { (float)0.,(float)0.,(float)0. };
    static real grn[3] = { (float)0.,(float)1.,(float)0. };
    static real yellw[3] = { (float)1.,(float)1.,(float)0. };
    static real wht[3] = { (float)1.,(float)1.,(float)1. };
    static real blu[3] = { (float)0.,(float)0.,(float)1. };
#endif /* NO_PROTO */

#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd (), chkinq_();
#endif /* NO_PROTO */
    static integer maxcol, errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwksl (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwksl ();
#endif /* NO_PROTO */

/*  Subroutine NMSCOL sets the workstation color indices for the */
/*  specified colors.  If the station does not support color, all */
/*  indices are set to 1 (the foreground color). */

/*  Input parameter: */
/*    WKID:  workstation identifier */
/* colour model */
/* Colors */
/*  maxcol = maximum size of color table */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &maxcol, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  If workstation allows, set up its color table with entries: */
/*  color index   RGB        color */
/*  -----------   ---        ----- */
/*     0          0,0,0      black */
/*     1          0,1,0      green */
/*     2          1,1,0      yellow */
/*     3          1,1,1      white */
/*     4          0,0,1      blue */

    if (maxcol > 4) {
/*  set color model = rgb */
	nscmd (wkid, &c__1);
/*  Set representation for workstation */
	colors_1.black = 0;
	colors_1.green = 1;
	colors_1.yellow = 2;
	colors_1.white = 3;
	colors_1.blue = 4;
	nscr (wkid, &colors_1.black, &c__3, blck);
	nscr (wkid, &colors_1.green, &c__3, grn);
	nscr (wkid, &colors_1.yellow, &c__3, yellw);
	nscr (wkid, &colors_1.white, &c__3, wht);
	nscr (wkid, &colors_1.blue, &c__3, blu);
    } else {
/*  MONO set for only 2 colors */
	colors_1.black = 0;
	colors_1.green = 1;
	colors_1.yellow = 1;
	colors_1.white = 1;
	colors_1.blue = 1;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* nmscol_ */

