/* subfnt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b6 = 1.f;
static real c_b7 = 0.f;
#else /* NO_PROTO */
static real c_b6 = (float)1.;
static real c_b7 = (float)0.;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b23 = .02f;
#else /* NO_PROTO */
static real c_b23 = (float).02;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int subfnt_(integer *specwt, integer *bestfn, real *ncbhtw, 
	real *ncbwdw, real *ncbhti, real *ncbwdi)
#else /* NO_PROTO */
/* Subroutine */ int subfnt_(specwt, bestfn, ncbhtw, ncbwdw, ncbhti, ncbwdi)
integer *specwt, *bestfn;
real *ncbhtw, *ncbwdw, *ncbhti, *ncbwdi;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
    static integer ix, nfpp, perm[400];
    static real txrx[2], txry[2];
    static integer idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nqtxf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *), nqtxx (integer *, integer *
	    , real *, real *, real *, integer *, integer *, integer *, char *,
	     integer *, real *, real *, real *, real *, ftnlen);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int nqtxf (), nqtxx ();
#endif /* NO_PROTO */
    static real tcbwdi, tcbhti;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer bestsc, errind, fnscor, thisfn;
    static real tcbhtw, tcbwdw;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_();
#endif /* NO_PROTO */
    static integer thispr;

/*  SUBFNT looks for a stroke text font other than 1, preferably not */
/*  #2 and not monospaced, and returns nominal size for "W" and "i". */
/*  Input parameters: */
/*    SPECWT : workstation type */
/*  Output parameters: */
/*    BESTFN        : selected font */
/*    NCBHTW,NCBWDW : nominal height, width of "W" in selected font */
/*    NCBHTI,NCBWDI : nominal height, width of "i" in selected font */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    nqtxf (specwt, &c__0, &errind, &nfpp, &idum1, &idum2, &idum3, &rdum1, &
	    rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    bestsc = -1;
    *bestfn = 1;
/*  go thru the fonts, in random order, looking for a good one */
    rnperm_(&nfpp, perm);
    i__1 = nfpp;
    for (ix = 1; ix <= i__1; ++ix) {
	nqtxf (specwt, &perm[ix - 1], &errind, &idum1, &thisfn, &thispr, &
		idum3, &rdum1, &rdum2, &idum4, &rdum3, &rdum4, &idum5);
	chkinq_("pqtxf", &errind, 5L);
/*  must be non-1 stroke font */
	if (thisfn == 1 || thispr != 2) {
	    goto L300;
	}
/*  determine */
/*    tcbhtw = nominal character body height for W */
/*    tcbwdw = nominal character body width for W */
	nqtxx (specwt, &thisfn, &c_b6, &c_b7, &c_b6, &c__0, &c__1, &c__5, 
		"WWW", &errind, txrx, txry, &rdum1, &rdum2, 3L);
	chkinq_("pqtxx", &errind, 5L);
	tcbhtw = (r__1 = txry[1] - txry[0], dabs(r__1));
	tcbwdw = (r__1 = txrx[1] - txrx[0], dabs(r__1)) / 3;
/*  determine */
/*    tcbhti = nominal character body height for i */
/*    tcbwdi = nominal character body width for i */
	nqtxx (specwt, &thisfn, &c_b6, &c_b7, &c_b6, &c__0, &c__1, &c__5, 
		"iii", &errind, txrx, txry, &rdum1, &rdum2, 3L);
	chkinq_("pqtxx", &errind, 5L);
	tcbhti = (r__1 = txry[1] - txry[0], dabs(r__1));
	tcbwdi = (r__1 = txrx[1] - txrx[0], dabs(r__1)) / 3;
/*  "goodness" score for this font */
	if (thisfn == 2) {
	    fnscor = 0;
	} else {
	    fnscor = 1;
	}
/*  add 2 to score if not monospaced */
	if (! appeq_(&tcbwdw, &tcbwdi, &c_b7, &c_b23)) {
	    fnscor += 2;
	}
	if (fnscor > bestsc) {
/*  best font so far */
	    bestsc = fnscor;
	    *bestfn = thisfn;
	    *ncbhtw = tcbhtw;
	    *ncbwdw = tcbwdw;
	    *ncbhti = tcbhti;
	    *ncbwdi = tcbwdi;
/*  got a non-2, non-monospaced font */
	    if (fnscor >= 3) {
		goto L310;
	    }
	}
L300:
	;
    }
/*  got_font: */
L310:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* subfnt_ */

