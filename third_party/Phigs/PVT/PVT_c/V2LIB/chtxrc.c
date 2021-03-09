/* chtxrc.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

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

