/* fort/02/01/02/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.01.02.01/01                        * */
/*  *    TEST TITLE : Simple structure deletion             * */
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
    static integer delstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("02.01.02.01/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* creation of structures */
    nopst (&c__100);
    nexst (&c__105);
    nexst (&c__110);
    nclst ();
#ifndef NO_PROTO
    setmsg_("1 2", "Deleting a structure should remove the specified structu"
	    "re from the CSS and all references made to that structure contai"
	    "ned in other structures.", 3L, 144L);
#else /* NO_PROTO */
    setmsg_("1 2", "Deleting a structure should remove the specified structu\
re from the CSS and all references made to that structure contained in other\
 structures.", 3L, 144L);
#endif /* NO_PROTO */
    delstr = 105;
    ndst (&delstr);
    L__1 = csseq_("100,1, 110,0/", 13L);
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

