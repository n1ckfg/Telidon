/* fort/09/01/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.01/06                              * */
/*  *    TEST TITLE : Emergency close phigs                 * */
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
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer arval, wkval;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqars (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqars ();
#endif /* NO_PROTO */
    static integer stval;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nopst (integer *), nqsys (integer *), neclph (void), initgl_(char 
	    *, ftnlen), avarnm_(integer *), noparf (integer *, integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nopst (), nqsys (), neclph (), 
	    initgl_(), avarnm_(), noparf (), setmsg_(), xpopph_();
#endif /* NO_PROTO */
    static integer sysval;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkst (integer *), nqstrs (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkst (), nqstrs ();
#endif /* NO_PROTO */

/* archive state */
/*                closed   open */
/* structure state value */
/* system state value */
/* workstation state */
    initgl_("09.01/06", 8L);
#ifndef NO_PROTO
    setmsg_("11", "If <emergency close phigs> is called, open structure shou"
	    "ld be closed, open archive files should be closed, all open work"
	    "stations should be updated and closed, and PHIGS should be close"
	    "d.", 2L, 187L);
#else /* NO_PROTO */
    setmsg_("11", "If <emergency close phigs> is called, open structure shou\
ld be closed, open archive files should be closed, all open workstations sho\
uld be updated and closed, and PHIGS should be closed.", 2L, 187L);
#endif /* NO_PROTO */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nopst (&c__100);
    arid = 11;
    avarnm_(&arnm);
    noparf (&arid, &arnm);
    neclph ();
    nqsys (&sysval);
    nqwkst (&wkval);
    nqstrs (&stval);
    nqars (&arval);
    L__1 = sysval == 0 && wkval == 0 && stval == 0 && arval == 0;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

