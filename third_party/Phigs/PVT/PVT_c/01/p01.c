/* fort/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 01/01                                 * */
/*  *    TEST TITLE : Testing the system state value        * */
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
    extern /* Subroutine */ int ifpf_(logical *), nclph (void), nqsys (
	    integer *), initgl_(char *, ftnlen), setmsg_(char *, char *, 
	    ftnlen, ftnlen), windup_(void), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nclph (), nqsys (), initgl_(), 
	    setmsg_(), windup_(), xpopph_();
#endif /* NO_PROTO */
    static integer systra;

/* system state value */
    initgl_("01/01", 5L);
/*  Use <inquire system state value> to determine: */
/*      systra = system state value */
#ifndef NO_PROTO
    setmsg_("3", "<Inquire system state value> should return closed as the s"
	    "ystem state value before PHIGS is opened.", 1L, 99L);
#else /* NO_PROTO */
    setmsg_("3", "<Inquire system state value> should return closed as the s\
ystem state value before PHIGS is opened.", 1L, 99L);
#endif /* NO_PROTO */
    systra = -6;
    nqsys (&systra);
    L__1 = systra == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "After opening PHIGS <inquire system state value> should "
	    "return the system state value as open.", 3L, 94L);
#else /* NO_PROTO */
    setmsg_("1 3", "After opening PHIGS <inquire system state value> should \
return the system state value as open.", 3L, 94L);
#endif /* NO_PROTO */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nqsys (&systra);
    L__1 = systra == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 3", "After closing PHIGS <inquire system state value> should "
	    "return the system state value as closed.", 3L, 96L);
#else /* NO_PROTO */
    setmsg_("2 3", "After closing PHIGS <inquire system state value> should \
return the system state value as closed.", 3L, 96L);
#endif /* NO_PROTO */
    nclph ();
    nqsys (&systra);
    L__1 = systra == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3", "After reopening PHIGS <inquire system state value> shoul"
	    "d return the system state value as open.", 3L, 96L);
#else /* NO_PROTO */
    setmsg_("1 3", "After reopening PHIGS <inquire system state value> shoul\
d return the system state value as open.", 3L, 96L);
#endif /* NO_PROTO */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nqsys (&systra);
    L__1 = systra == 1;
    ifpf_(&L__1);
/* L666: */
/* close PHIGS */
    nclph ();
    windup_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

