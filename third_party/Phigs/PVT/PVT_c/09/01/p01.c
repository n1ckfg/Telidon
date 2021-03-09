/* fort/09/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.01/01                              * */
/*  *    TEST TITLE : Testing the error handling mode       * */
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
    /* System generated locals */
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), endit_();
#endif /* NO_PROTO */
    static integer hndmod, errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nqerhm (integer *, 
	    integer *), nserhm (integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nqerhm (), nserhm (), setmsg_(), 
	    xpopph_();
#endif /* NO_PROTO */

    initgl_("09.01/01", 8L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("2 3", "After opening PHIGS, <inquire error handling mode> shoul"
	    "d return ON.", 3L, 68L);
#else /* NO_PROTO */
    setmsg_("2 3", "After opening PHIGS, <inquire error handling mode> shoul\
d return ON.", 3L, 68L);
#endif /* NO_PROTO */
    nqerhm (&errind, &hndmod);
    L__1 = errind == 0 && hndmod == 1;
    ifpf_(&L__1);

#ifndef NO_PROTO
    setmsg_("1 3", "After <set error handling mode> to OFF, <inquire error h"
	    "andling mode> should return OFF.", 3L, 88L);
#else /* NO_PROTO */
    setmsg_("1 3", "After <set error handling mode> to OFF, <inquire error h\
andling mode> should return OFF.", 3L, 88L);
#endif /* NO_PROTO */
    nserhm (&c__0);
    nqerhm (&errind, &hndmod);
    L__1 = errind == 0 && hndmod == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "After <set error handling mode> to ON, <inquire error ha"
	    "ndling mode> should return ON.", 3L, 86L);
#else /* NO_PROTO */
    setmsg_("1 3", "After <set error handling mode> to ON, <inquire error ha\
ndling mode> should return ON.", 3L, 86L);
#endif /* NO_PROTO */
    nserhm (&c__1);
    nqerhm (&errind, &hndmod);
    L__1 = errind == 0 && hndmod == 1;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

