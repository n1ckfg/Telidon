/* fort/02/01/02/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__115 = 115;
static integer c__120 = 120;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.01/02                        * */
/*  *    TEST TITLE : Structure deletion with an open       * */
/*  *                 structure                             * */
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
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), pass_(void), 
	    ndst (integer *), endit_(void);
    extern logical csseq_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), pass_(), ndst (), endit_();
    extern logical csseq_();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nexst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst ();
#endif /* NO_PROTO */
    static integer stype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer delstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    xpopph_(integer *, integer *), nqopst (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), xpopph_(), nqopst ();
#endif /* NO_PROTO */
    static integer strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/* parameter type for structure state */
/* PHIGS parameter types */
    initgl_("02.01.02.01/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* creation of structure network */
    nopst (&c__100);
    nexst (&c__105);
    nexst (&c__110);
    nclst ();
    nopst (&c__110);
    nexst (&c__115);
    nexst (&c__120);
    nclst ();
#ifndef NO_PROTO
    setmsg_("5", "Deleting an open root structure should cause the structure"
	    " to exist in the CSS as an open structure.", 1L, 100L);
#else /* NO_PROTO */
    setmsg_("5", "Deleting an open root structure should cause the structure\
 to exist in the CSS as an open structure.", 1L, 100L);
#endif /* NO_PROTO */
    delstr = 100;
    nopst (&delstr);
    ndst (&delstr);
/* use <inquire open structure> to determine */
/*    stype = structure status */
/*    strid = structure id */
    nqopst (&errind, &stype, &strid);
    chkinq_("pqopst", &errind, 6L);
    if (stype != 1 || strid != delstr) {
	fail_();
    } else {
	pass_();
	nclst ();
    }
#ifndef NO_PROTO
    setmsg_("5", "Deleting an open root structure should cause the structure"
	    " to exist in the CSS as an empty structure.", 1L, 101L);
#else /* NO_PROTO */
    setmsg_("5", "Deleting an open root structure should cause the structure\
 to exist in the CSS as an empty structure.", 1L, 101L);
#endif /* NO_PROTO */
/* strsti = structure status identifier */
    nqstst (&delstr, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2", "Deleting an open root structure should cause the deletion "
	    "of all references made to that structure contained in other stru"
	    "ctures.", 1L, 129L);
#else /* NO_PROTO */
    setmsg_("2", "Deleting an open root structure should cause the deletion \
of all references made to that structure contained in other structures.", 1L, 
	    129L);
#endif /* NO_PROTO */
    L__1 = csseq_("110,1, 115,0/ 110,2, 120,0/ 100,0/ 105,0/ ", 42L);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("5", "Deleting a non-root structure should cause the structure t"
	    "o exist in the CSS as an open structure.", 1L, 98L);
#else /* NO_PROTO */
    setmsg_("5", "Deleting a non-root structure should cause the structure t\
o exist in the CSS as an open structure.", 1L, 98L);
#endif /* NO_PROTO */
    delstr = 115;
    nopst (&delstr);
    ndst (&delstr);
/* use <inquire open structure> to determine */
/*    stype = structure status */
/*    strid = structure id */
    nqopst (&errind, &stype, &strid);
    chkinq_("pqopst", &errind, 6L);
    if (stype != 1 || strid != delstr) {
	fail_();
    } else {
	pass_();
	nclst ();
    }
#ifndef NO_PROTO
    setmsg_("5", "Deleting a non-root structure should cause the structure t"
	    "o exist in the CSS as an empty structure.", 1L, 99L);
#else /* NO_PROTO */
    setmsg_("5", "Deleting a non-root structure should cause the structure t\
o exist in the CSS as an empty structure.", 1L, 99L);
#endif /* NO_PROTO */
/* strsti = structure status identifier */
    nqstst (&delstr, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2", "Deleting a non-root structure should cause the deletion of"
	    " all references made to that structure contained in other struct"
	    "ures.", 1L, 127L);
#else /* NO_PROTO */
    setmsg_("2", "Deleting a non-root structure should cause the deletion of\
 all references made to that structure contained in other structures.", 1L, 
	    127L);
#endif /* NO_PROTO */
    L__1 = csseq_("110,1, 120,0/115,0/ 105,0/ 100,0/ ", 34L);
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

