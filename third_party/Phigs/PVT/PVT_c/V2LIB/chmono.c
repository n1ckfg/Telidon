/* chmono.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

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

