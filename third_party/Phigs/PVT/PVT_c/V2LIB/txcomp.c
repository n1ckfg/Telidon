/* txcomp.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int txcomp_(integer *wktype, integer *txor, integer *font, 
	real *chxp, real *chsp, real *chh, char *str, real *extxhi, real *
	extyhi, real *exccx, real *exccy, logical *rectok, logical *ccpok, 
	ftnlen str_len)
#else /* NO_PROTO */
/* Subroutine */ int txcomp_(wktype, txor, font, chxp, chsp, chh, str, extxhi,
	 extyhi, exccx, exccy, rectok, ccpok, str_len)
integer *wktype, *txor, *font;
real *chxp, *chsp, *chh;
char *str;
real *extxhi, *extyhi, *exccx, *exccy;
logical *rectok, *ccpok;
ftnlen str_len;
#endif /* NO_PROTO */
{
    static integer txp;
    static real achh, accx, accy, actx[2], acty[2];
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static integer txalh;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer txalv;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxx (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, char *, integer *, real *
	    , real *, real *, real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx ();
#endif /* NO_PROTO */
    static real adjccy;
#ifndef NO_PROTO
    extern doublereal basbot_(integer *, integer *);
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern doublereal basbot_();
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real abstol, reltol, extxlo, extylo;

/*  TXCOMP compares actual and expected values for results of */
/*  <inquire text extent> and reports results in two logical */
/*  variables. TXCOMP tests both text paths for the given */
/*  orientation, i.e. LEFT and RIGHT for horizontal, UP and */
/*  DOWN for vertical. */
/* Input parameters: */
/*   wktype  : workstation type */
/*   txor    : text path orientation */
/*   font    : text font */
/*   chxp    : character expansion factor */
/*   chsp    : character spacing */
/*   chh     : character height */
/*   str     : character string */
/*   extxhi  : expected value for x size of text rectangle */
/*   extyhi  : expected value for y size of text rectangle */
/*   exccx   : expected value for x concatenation point */
/*   exccy   : expected value for y concatenation point */
/* Output parameters: */
/*   rectok  : text rectangle OK */
/*   ccpok   : concatenation point OK */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    achh = dabs(*chh);
/* abstol = absolute tolerance */
/* reltol = relative tolerance */
#ifndef NO_PROTO
    abstol = achh * .02f;
    reltol = .02f;
#else /* NO_PROTO */
    abstol = achh * (float).02;
    reltol = (float).02;
#endif /* NO_PROTO */
/*  Since txal = LEFT,BOTTOM, expected lower bounds are always zero: */
/*  extxlo = 0, extylo = 0 */
    txalh = 1;
    txalv = 5;
#ifndef NO_PROTO
    extxlo = 0.f;
    extylo = 0.f;
#else /* NO_PROTO */
    extxlo = (float)0.;
    extylo = (float)0.;
#endif /* NO_PROTO */
    if (*txor == 1) {
	txp = 0;
	adjccy = *exccy;
    } else if (*txor == 2) {
	txp = 2;
/*  this is to compensate for the additional space between the */
/*  bottom and baseline. */
	adjccy = *exccy + achh * basbot_(wktype, font);
    } else {
	unmsg_("Invalid text orientation passed to TXCOMP.", 42L);
    }
/* <Inquire text extent> with: */
/*       wktype, font, chxp, chsp, chh, txp, txal, str */
/*    to determine actual results: */
/*       actxlo,actxhi, actylo,actyhi, accx,accy */
    nqtxx (wktype, font, chxp, chsp, chh, &txp, &txalh, &txalv, str, &errind, 
	    actx, acty, &accx, &accy, str_len);
    chkinq_("pqtxx", &errind, 5L);
    *rectok = appeq_(actx, &extxlo, &abstol, &reltol) && appeq_(&actx[1], 
	    extxhi, &abstol, &reltol) && appeq_(acty, &extylo, &abstol, &
	    reltol) && appeq_(&acty[1], extyhi, &abstol, &reltol);
    *ccpok = appeq_(&accx, exccx, &abstol, &reltol) && appeq_(&accy, &adjccy, 
	    &abstol, &reltol);
/* Switch text path direction: */
    if (*txor == 1) {
	txp = 1;
	*exccx = *extxhi - *exccx;
    } else {
	txp = 3;
	*exccy = *extyhi - *exccy;
    }
    nqtxx (wktype, font, chxp, chsp, chh, &txp, &txalh, &txalv, str, &errind, 
	    actx, acty, &accx, &accy, str_len);
    chkinq_("pqtxx", &errind, 5L);
    *rectok = appeq_(actx, &extxlo, &abstol, &reltol) && appeq_(&actx[1], 
	    extxhi, &abstol, &reltol) && appeq_(acty, &extylo, &abstol, &
	    reltol) && appeq_(&acty[1], extyhi, &abstol, &reltol) && *rectok;
    *ccpok = appeq_(&accx, exccx, &abstol, &reltol) && appeq_(&accy, exccy, &
	    abstol, &reltol) && *ccpok;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* txcomp_ */

