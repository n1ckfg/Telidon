/* txexal.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

#ifndef NO_PROTO
static real c_b2 = 1.f;
static real c_b3 = 0.f;
#else /* NO_PROTO */
static real c_b2 = (float)1.;
static real c_b3 = (float)0.;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__5 = 5;

#ifndef NO_PROTO
/* Subroutine */ int txexal_(integer *txfont, integer *txpath, char *txstr, 
	real *ntxwd, real *ntxht, real *htab, real *vtab, ftnlen txstr_len)
#else /* NO_PROTO */
/* Subroutine */ int txexal_(txfont, txpath, txstr, ntxwd, ntxht, htab, vtab, 
	txstr_len)
integer *txfont, *txpath;
char *txstr;
real *ntxwd, *ntxht, *htab, *vtab;
ftnlen txstr_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Local variables */
    static integer ix;
    static real txrx[2], txry[2], rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxx (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, char *, integer *, real *
	    , real *, real *, real *, ftnlen), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  TXEXAL returns not only the size of the nominal text extent */
/*  rectangle, but also the location within it of the various text */
/*  alignment positions. */
/*  Input parameters: */
/*    TXFONT : text font to be used for inquiry */
/*    TXPATH : text path to be used for inquiry */
/*    TXSTR  : text string to be used for inquiry */
/*  Output parameters: */
/*    NTXWD  : nominal width of text rectangle */
/*    NTXHT  : nominal height of text rectangle */
/*    HTAB   : nominal position of horizontal text alignments */
/*    VTAB   : nominal position of vertical text alignments */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    /* Parameter adjustments */
    --vtab;
    --htab;

    /* Function Body */
    nqtxx (&dialog_1.specwt, txfont, &c_b2, &c_b3, &c_b2, txpath, &c__1, &
	    c__5, txstr, &errind, txrx, txry, &rdum1, &rdum2, txstr_len);
    chkinq_("pqtxx", &errind, 5L);
    *ntxwd = (r__1 = txrx[1] - txrx[0], dabs(r__1));
    *ntxht = (r__1 = txry[1] - txry[0], dabs(r__1));
/*  save normalized heights in table: */
    for (ix = 1; ix <= 5; ++ix) {
	nqtxx (&dialog_1.specwt, txfont, &c_b2, &c_b3, &c_b2, txpath, &c__1, &
		ix, txstr, &errind, txrx, txry, &rdum1, &rdum2, txstr_len);
	chkinq_("pqtxx", &errind, 5L);
	vtab[ix] = *ntxht - txry[1];
/* L100: */
    }
/*  save normalized widths in table: */
#ifndef NO_PROTO
    htab[1] = 0.f;
#else /* NO_PROTO */
    htab[1] = (float)0.;
#endif /* NO_PROTO */
    htab[2] = *ntxwd / 2;
    htab[3] = *ntxwd;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* txexal_ */

