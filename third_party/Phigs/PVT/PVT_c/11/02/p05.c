/* fort/11/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"
#include "phigs.h"

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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 11.02/05                              * */
/*  *    TEST TITLE : Create store and delete store         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */ 
{
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), initgl_(char *, ftnlen), 
	    setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), initgl_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */
    Pstore  pstore = NULL;
    Pint    err_ind;

/*  Declare program-specific variables */
    initgl_("11.02/05", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  DESIGN: */

    setmsg_("13", "<Create store> should return a non-null pointer.", 2L, 48L)
	    ;
/*  <create store> to set ptr */
/*  pass/fail depending on (error indicator = 0 and ptr not= null) */

    pcreate_store( &err_ind, &pstore );
    if (err_ind == 0 && pstore != NULL)
       pass_();
    else
       fail_();

    setmsg_("14", "<Delete store> should return a null pointer.", 2L, 44L);

/*  <delete store> to set ptr */
/*  pass/fail depending on (error indicator = 0 and ptr = null) */

    pdel_store( &err_ind, &pstore );
    if (err_ind == 0 && pstore == NULL)
       pass_();
    else
       fail_();

/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

