/* fort/06/02/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.02/05                           * */
/*  *    TEST TITLE : Order of view indices                 * */
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
    integer i__1;

    /* Local variables */
    static integer ndvi, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nopwk (integer *, integer *, 
	    integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nopwk (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), nqevwi (integer *, integer *, integer *, 
	    integer *, integer *), xpopph_(integer *, integer *), tstvip_(
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), nqevwi (), xpopph_(), 
	    tstvip_();
#endif /* NO_PROTO */

/* relative input priority */
    initgl_("06.02.02/05", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  <Inquire list of view indices> to determine */
/*     ndvi = number of defined indices in the view table */
    nqevwi (&globnu_1.wkid, &c__0, &errind, &ndvi, &idum1);
    chkinq_("pqevwi", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("18 20 21", "<Set view transformation input priority> should be "
	    "able to set a middle view to priority higher than the first view."
	    , 8L, 116L);
#else /* NO_PROTO */
    setmsg_("18 20 21", "<Set view transformation input priority> should be \
able to set a middle view to priority higher than the first view.", 8L, 116L);

#endif /* NO_PROTO */
    i__1 = ndvi / 2;
    tstvip_(&i__1, &c__1, &c__0, &ndvi);
#ifndef NO_PROTO
    setmsg_("18 20 21", "<Set view transformation input priority> should be "
	    "able to set a middle view to priority lower than the last view.", 
	    8L, 114L);
#else /* NO_PROTO */
    setmsg_("18 20 21", "<Set view transformation input priority> should be \
able to set a middle view to priority lower than the last view.", 8L, 114L);
#endif /* NO_PROTO */
    i__1 = ndvi / 2;
    tstvip_(&i__1, &ndvi, &c__1, &ndvi);
#ifndef NO_PROTO
    setmsg_("18 20 21", "<Set view transformation input priority> should be "
	    "able to set the first view to priority lower than a middle view.",
	     8L, 115L);
#else /* NO_PROTO */
    setmsg_("18 20 21", "<Set view transformation input priority> should be \
able to set the first view to priority lower than a middle view.", 8L, 115L);
#endif /* NO_PROTO */
    i__1 = ndvi / 2;
    tstvip_(&c__1, &i__1, &c__1, &ndvi);
#ifndef NO_PROTO
    setmsg_("18 20 21", "<Set view transformation input priority> should be "
	    "able to set the last view to priority higher than a middle view.",
	     8L, 115L);
#else /* NO_PROTO */
    setmsg_("18 20 21", "<Set view transformation input priority> should be \
able to set the last view to priority higher than a middle view.", 8L, 115L);
#endif /* NO_PROTO */
    i__1 = ndvi / 2;
    tstvip_(&ndvi, &i__1, &c__0, &ndvi);
#ifndef NO_PROTO
    setmsg_("18 22", "<Set view transformation input priority> should have n"
	    "o effect when the specified view is the same as the reference vi"
	    "ew.", 5L, 121L);
#else /* NO_PROTO */
    setmsg_("18 22", "<Set view transformation input priority> should have n\
o effect when the specified view is the same as the reference view.", 5L, 
	    121L);
#endif /* NO_PROTO */
    tstvip_(&c__2, &c__2, &c__1, &ndvi);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

