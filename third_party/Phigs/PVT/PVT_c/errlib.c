/*  This program contains the "manual" addition to the generated code for 
    the C errlib - papers over the problem that Fortran/PERHND
    and C/perr_hand are called with different parameter types.
*/

/* fort//errlib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE ER/perhnd                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ 

/* MANUAL CHANGE HERE: 
   int nerhnd (integer *errnr, integer *funccd, integer *erflid)
*/
/* Subroutine */ 
   void pvt_err_hand (Pint errnr_act, Pint funccd_act, char *fn)

#else /* NO_PROTO */
/* Subroutine */ 

/* MANUAL CHANGE HERE: 
   int  nerhnd (errnr, funccd, erflid)
   integer *errnr, *funccd, *erflid;
*/
   void   pvt_err_hand (errnr_act, funccd_act, fn)
   Pint   errnr_act, funccd_act;
   char   *fn;

#endif /* NO_PROTO */
{
    /* MANUAL CHANGE HERE: */
    integer *erflid, *errnr, *funccd;

    /* Initialized data */

    static integer errct = 0;

    /* System generated locals */
    address a__1[3];
    integer i__1[3];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[300], errch[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int ncmsg_(char *, ftnlen), unmsg_(char *, ftnlen)
	    , erfunm_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ncmsg_(), unmsg_(), erfunm_();
#endif /* NO_PROTO */
    static char errfun[45];
#ifndef NO_PROTO
    extern /* Subroutine */ int sigmsg_(integer *, char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int sigmsg_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___4 = { 0, errch, 0, "(I6)", 6, 1 };


/*  Perhnd is the standard routine name for error handling in */
/*  PHIGS/Fortran.  Generally, no errors should be signalled during */
/*  execution of the tests.  Perhnd does one of two things: */

/*  1. Expected errors: If a test program specifies that a signalled error
 */
/*  is possibly expected, and wants to test the error code explicitly, it 
*/
/*  does so by using errctl to set the value of ctlhnd (a COMMON variable)
 */
/*  to 1.  Perhnd will then simply set errsig to the error code signalled,
 */
/*  funcid to the name of the signalling function and return.  No message 
*/
/*  is written by perhnd; the test program assumes all responsibility for 
*/
/*  handling the error.  Normally the test program should use errctl to */

/*  re-set ctlhnd to 0 immediately after calling the potentially */
/*  error-signalling function. */

/*  2. Unexpected errors: By default, errors are unexpected, and their */
/*  occurrence causes perhnd to write a message and abort the program, */
/*  using NCMSG.  This happens if ctlhnd has a value of 0, as initialized.
 */

/*  Note that inquires never signal an error, but merely return a non-zero
 */
/*  error indicator, normally checked by CHKINQ. */
/*  PERHND is stored in a separate library (ERRLIB) to allow the */
/*  system linker more easily to insert it into the executable, or to */
/*  exclude it so as to allow the default error handler of the same */
/*  name to take effect.  The subroutine INITGL in the global */
/*  subroutine library contains dummy calls to PERHND and to all */
/*  subroutines immediately invoked by PERHND so as to allow optional */
/*  linking of ERRLIB following SUBLIB. */

    /* MANUAL CHANGE HERE: */
    if (strcmp (fn, "-666") )
       *erflid = globnu_1.errfil;
    else
       *erflid = -666;

    errnr  = &errnr_act;
    funccd = &funccd_act;

    /* END MANUAL CHANGE */

/* put name of function into errfun */
    if (*funccd >= 0 && *funccd <= 182) {
	erfunm_(funccd, errfun, 45L);
    } else {
	s_wsfi(&io___4);
	do_fio(&c__1, (char *)&(*funccd), (ftnlen)sizeof(integer));
	e_wsfi();
/* Writing concatenation */
	i__1[0] = 27, a__1[0] = "<Function of unknown code: ";
	i__1[1] = 6, a__1[1] = errch;
	i__1[2] = 1, a__1[2] = ">";
	s_cat(errfun, a__1, i__1, &c__3, 45L);
    }
    if (globnu_1.ctlhnd == 1) {
/* let test program handle error */
	globnu_1.errsig = *errnr;
	s_copy(globch_1.funcid, errfun, 80L, 45L);
	errinf_1.errcom = *errnr;
	errinf_1.funcom = *funccd;
	errinf_1.filcom = *erflid;
	if (errinf_1.usrerr == 1 || errinf_1.usrerr == 3) {
	    ++errct;
	    if (errct > 200) {
#ifndef NO_PROTO
		unmsg_("PERHND tried to write past last entry in internal ta"
			"ble of generated errors.", 76L);
#else /* NO_PROTO */
		unmsg_("PERHND tried to write past last entry in internal ta\
ble of generated errors.", 76L);
#endif /* NO_PROTO */
	    }
	    errinf_1.errsav[errct - 1] = errinf_1.errcom;
	    errinf_1.funsav[errct - 1] = errinf_1.funcom;
	    errinf_1.filsav[errct - 1] = errinf_1.filcom;
	} else if (errinf_1.usrerr == 0) {
/*           normal - not testing error handling - do nothing */
	} else {
	    unmsg_("User-defined PERHND called with invalid value for USRERR."
		    , 57L);
	}
	return 0;
    }
    sigmsg_(errnr, errfun, msg, 45L, 300L);
    if (*errnr >= 0) {
	ncmsg_(msg, 300L);
    } else {
/* implementation-dependent errors - could be warning - at any rate */

/* not necessarily non-conforming. */
	unmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /*  pvt_err_hand  */
