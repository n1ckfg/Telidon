/* ermsgh.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
logical ermsgh_(char *erec, char *errmrk, integer *nmrk, ftnlen erec_len, 
	ftnlen errmrk_len)
#else /* NO_PROTO */
logical ermsgh_(erec, errmrk, nmrk, erec_len, errmrk_len)
char *erec, *errmrk;
integer *nmrk;
ftnlen erec_len;
ftnlen errmrk_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_indx();
#endif /* NO_PROTO */

/*  ERMSGH determines whether or not a given record from the error file is
 */
/*  the header of an error message, i.e. whether it is the first record of
 */
/*  a possibly multi-record message.  The default logic allows for */
/*  searching for the presence of a given string (ERRMRK) within the */
/*  record, but users may code any logic needed by which to distinguish */

/*  message headers. */
/* USERMOD modify if necessary. */
/*  Input parameters: */
/*    EREC   : record from error file to be examined */
/*    ERRMRK : distinctive character string identifying message header */
/*    NMRK   : number of significant characters in ERRMRK */
    ret_val = i_indx(erec, errmrk, erec_len, (*nmrk)) >= 1;
    return ret_val;
} /* ermsgh_ */

