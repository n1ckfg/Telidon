/* fort/04/02/03/03/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.03.03/chtxrc                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int chtxrc_(real *nomw, real *nomh, integer *wktype, integer 
	*font, char *str, integer *txor, real *chxp, real *chsp, real *chh, 
	logical *didtst, logical *rectok, logical *ccpok, ftnlen str_len)
#else /* NO_PROTO */
/* Subroutine */ int chtxrc_(nomw, nomh, wktype, font, str, txor, chxp, chsp, 
	chh, didtst, rectok, ccpok, str_len)
real *nomw, *nomh;
integer *wktype, *font;
char *str;
integer *txor;
real *chxp, *chsp, *chh;
logical *didtst, *rectok, *ccpok;
ftnlen str_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer i_len(char *, ftnlen);
#else /* NO_PROTO */
    integer i_len();
#endif /* NO_PROTO */

    /* Local variables */
    static real achh;
    static integer nchar;
    static real achxp, exccx, exccy;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real minsp;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static real extxhi, extyhi;
#ifndef NO_PROTO
    extern /* Subroutine */ int txcomp_(integer *, integer *, integer *, real 
	    *, real *, real *, char *, real *, real *, real *, real *, 
	    logical *, logical *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int txcomp_();
#endif /* NO_PROTO */

/*  CHTXRC computes expected results for various parameter values */
/*  which affect the size of the text extent rectangle and the */
/*  concatenation point.  Computation is based on deviation from */
/*  nominal width and length of entire string.  Therefore, CHTXRC may */
/*  be used for non-monospaced fonts. */
/* Input parameters: */
/*   nomw    : nominal width of string */
/*   nomh    : nominal height of string */
/*   wktype  : workstation type */
/*   font    : text font */
/*   str     : character string */
/*   txor    : text path orientation */
/*   chxp    : character expansion factor */
/*   chsp    : character spacing */
/*   chh     : character height */

/* Output parameters: */
/*   didtst  : was able to perform test */
/*   rectok  : text rectangle OK */
/*   ccpok   : concatenation point OK */
    achh = dabs(*chh);
    achxp = dabs(*chxp);
#ifndef NO_PROTO
    if (achh < 1e-37f || achh > 1e37f || achxp < 1e-37f || achxp > 1e37f) {
	inmsg_("Magnitude of character height or expansion factor too high o"
		"r low to allow computation of expected value; skipping test "
		"case.", 125L);
#else /* NO_PROTO */
    if (achh < (float)1e-37 || achh > (float)1e37 || achxp < (float)1e-37 || 
	    achxp > (float)1e37) {
	inmsg_("Magnitude of character height or expansion factor too high o\
r low to allow computation of expected value; skipping test case.", 125L);
#endif /* NO_PROTO */
	*didtst = FALSE_;
	return 0;
    } else {
	*didtst = TRUE_;
    }
    if (*txor == 1) {
#ifndef NO_PROTO
	minsp = achxp * -.1f;
#else /* NO_PROTO */
	minsp = achxp * (float)-.1;
#endif /* NO_PROTO */
    } else if (*txor == 2) {
#ifndef NO_PROTO
	minsp = -.1f;
#else /* NO_PROTO */
	minsp = (float)-.1;
#endif /* NO_PROTO */
    } else {
	unmsg_("Invalid text orientation passed to CHXTRC.", 42L);
    }
    if (*chsp < minsp) {
#ifndef NO_PROTO
	unmsg_("Cannot compute expected values because negative character sp"
		"acing may overwhelm character width.", 96L);
#else /* NO_PROTO */
	unmsg_("Cannot compute expected values because negative character sp\
acing may overwhelm character width.", 96L);
#endif /* NO_PROTO */
    }
/*  nchar = number of characters in str */
    nchar = i_len(str, str_len);
/* calculate expected values for rectangle and concatenation point */
    if (*txor == 1) {
	extxhi = achh * (*nomw * achxp + *chsp * (nchar - 1));
	extyhi = achh * *nomh;
	exccx = extxhi + achh * *chsp;
#ifndef NO_PROTO
	exccy = 0.f;
#else /* NO_PROTO */
	exccy = (float)0.;
#endif /* NO_PROTO */
    } else if (*txor == 2) {
	extyhi = achh * (*nomh + *chsp * (nchar - 1));
	extxhi = achh * *nomw * achxp;
#ifndef NO_PROTO
	exccx = 0.f;
#else /* NO_PROTO */
	exccx = (float)0.;
#endif /* NO_PROTO */
	exccy = extyhi + achh * *chsp;
    }
    txcomp_(wktype, txor, font, chxp, chsp, chh, str, &extxhi, &extyhi, &
	    exccx, &exccy, rectok, ccpok, str_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chtxrc_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.03.03/chmono                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int chmono_(real *nomcsz, real *nomsth, integer *wktype, 
	integer *font, char *str, integer *txor, real *chxp, real *chsp, real 
	*chh, logical *rectok, logical *ccpok, ftnlen str_len)
#else /* NO_PROTO */
/* Subroutine */ int chmono_(nomcsz, nomsth, wktype, font, str, txor, chxp, 
	chsp, chh, rectok, ccpok, str_len)
real *nomcsz, *nomsth;
integer *wktype, *font;
char *str;
integer *txor;
real *chxp, *chsp, *chh;
logical *rectok, *ccpok;
ftnlen str_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer i_len(char *, ftnlen);
#else /* NO_PROTO */
    integer i_len();
#endif /* NO_PROTO */

    /* Local variables */
    static real achh, xpcw;
    static integer nchar;
    static real achxp, exccx, exccy;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static real chrinc, extxhi, extyhi;
#ifndef NO_PROTO
    extern /* Subroutine */ int txcomp_(integer *, integer *, integer *, real 
	    *, real *, real *, char *, real *, real *, real *, real *, 
	    logical *, logical *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int txcomp_();
#endif /* NO_PROTO */

/*  CHMONO computes expected results for various parameter values */
/*  which affect the size of the text extent rectangle and the */
/*  concatenation point.  Computation is based on deviation from */
/*  nominal character size in text path dimension and thickness of */
/*  entire string in other dimension.  Therefore, CHMONO is valid */
/*  only when every character in the string has the same size. */
/* Input parameters: */
/*   nomcsz  : nominal character size, in dimension of */
/*             text orientation */
/*   nomsth  : nominal thickness of string, in dimension */
/*             perpendicular to text orientation */
/*   wktype  : workstation type */
/*   font    : text font */
/*   str     : character string */
/*   txor    : text path orientation */
/*   chxp    : character expansion factor */
/*   chsp    : character spacing */
/*   chh     : character height */

/* Output parameters: */
/*   rectok  : text rectangle OK */
/*   ccpok   : concatenation point OK */
    achh = dabs(*chh);
    achxp = dabs(*chxp);
/*     nchar = number of characters in str */
    nchar = i_len(str, str_len);
/* calculate expected values for rectangle and concatenation point */
    if (*txor == 1) {
	xpcw = achxp * *nomcsz;
/*  chrinc = character increment */
	chrinc = xpcw + *chsp;
	extxhi = achh * (xpcw + (nchar - 1) * dabs(chrinc));
	extyhi = achh * *nomsth;
#ifndef NO_PROTO
	if (chrinc <= 0.f) {
#else /* NO_PROTO */
	if (chrinc <= (float)0.) {
#endif /* NO_PROTO */
	    exccx = achh * chrinc;
	} else {
	    exccx = achh * chrinc * nchar;
	}
#ifndef NO_PROTO
	exccy = 0.f;
#else /* NO_PROTO */
	exccy = (float)0.;
#endif /* NO_PROTO */
    } else if (*txor == 2) {
/*  chrinc = character increment */
	chrinc = *nomcsz + *chsp;
	extxhi = achh * *nomsth * achxp;
	extyhi = achh * (*nomcsz + (nchar - 1) * dabs(chrinc));
#ifndef NO_PROTO
	exccx = 0.f;
	if (chrinc <= 0.f) {
#else /* NO_PROTO */
	exccx = (float)0.;
	if (chrinc <= (float)0.) {
#endif /* NO_PROTO */
	    exccy = achh * chrinc;
	} else {
	    exccy = achh * chrinc * nchar;
	}
    } else {
	unmsg_("Invalid text orientation passed to CHMONO.", 42L);
    }
    txcomp_(wktype, txor, font, chxp, chsp, chh, str, &extxhi, &extyhi, &
	    exccx, &exccy, rectok, ccpok, str_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chmono_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 04.02.03.03/txcomp                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

