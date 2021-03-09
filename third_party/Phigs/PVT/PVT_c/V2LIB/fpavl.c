/* fpavl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b8 = 1.f;
static real c_b9 = 0.f;
#else /* NO_PROTO */
static real c_b8 = (float)1.;
static real c_b9 = (float)0.;
#endif /* NO_PROTO */
static integer c__1 = 1;

#ifndef NO_PROTO
logical fpavl_(integer *wkid, integer *txi, integer *font, integer *prec)
#else /* NO_PROTO */
logical fpavl_(wkid, txi, font, prec)
integer *wkid, *txi, *font, *prec;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix, nfpp, idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
    static integer conid, qprec;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer qfont;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxf ();
#endif /* NO_PROTO */
    static integer wtype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    nstxr (integer *, integer *, integer *, integer *, real *, real *,
	     integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxr (), nstxr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  Tests whether a given font and precision will be realized exactly */
/*  as such on the workstation type.  If a requested font is realized */
/*  in a higher precision, it is not considered to be directly */
/*  available. */
/*  Input parameters: */
/*    WKID : Workstation identifier */
/*    TXI  : Identifier for a text bundle which may be altered */
/*    FONT : font whose availability is at issue */
/*    PREC : precision whose availability is at issue */
/* type of returned value */
    nqwkc (wkid, &errind, &conid, &wtype);
    chkinq_("pqwkc", &errind, 5L);
/*  check if font,prec claimed in available list */
    nqtxf (&wtype, &c__0, &errind, &nfpp, &idum1, &idum2, &idum3, &rdum1, &
	    rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    i__1 = nfpp;
    for (ix = 1; ix <= i__1; ++ix) {
	nqtxf (&wtype, &ix, &errind, &idum1, &qfont, &qprec, &idum3, &rdum1, &
		rdum2, &idum4, &rdum3, &rdum4, &idum5);
	chkinq_("pqtxf", &errind, 5L);
	if (qfont == *font && qprec >= *prec) {
	    goto L110;
	}
/* L100: */
    }
/*  font not claimed in list - give up */
    ret_val = FALSE_;
    return ret_val;
/*  check if realized exactly as requested */
L110:
    nstxr (wkid, txi, font, prec, &c_b8, &c_b9, &c__1);
    nqtxr (wkid, txi, &c__1, &errind, &qfont, &qprec, &rdum1, &rdum2, &idum1);

    chkinq_("pqtxr", &errind, 5L);
    ret_val = qfont == *font && qprec == *prec;
    return ret_val;
} /* fpavl_ */

