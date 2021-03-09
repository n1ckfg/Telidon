/* fort/02/01/02/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__100 = 100;
static integer c__105 = 105;
static integer c__110 = 110;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.01/03                        * */
/*  *    TEST TITLE : Deletion of a non-existent structure  * */
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
    extern /* Subroutine */ int ifpf_(logical *), ndst (integer *), endit_(
	    void);
    extern logical csseq_(char *, ftnlen);
    extern /* Subroutine */ int nclst (void), nexst (integer *), nopst (
	    integer *), initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndst (), endit_();
    extern logical csseq_();
    extern /* Subroutine */ int nclst (), nexst (), nopst (), initgl_();
#endif /* NO_PROTO */
    static integer nostid;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), xpopph_();
#endif /* NO_PROTO */

/* PHIGS parameter types */
    initgl_("02.01.02.01/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* creation of structures */
    nopst (&c__100);
    nexst (&c__105);
    nexst (&c__110);
    nclst ();
#ifndef NO_PROTO
    setmsg_("3", "Deleting a non-existent structure should have no effect on"
	    " the contents of the CSS.", 1L, 83L);
#else /* NO_PROTO */
    setmsg_("3", "Deleting a non-existent structure should have no effect on\
 the contents of the CSS.", 1L, 83L);
#endif /* NO_PROTO */
    nostid = 25;
    ndst (&nostid);
    L__1 = csseq_("100,1, 105,0/ 100,2, 110,0/", 27L);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

