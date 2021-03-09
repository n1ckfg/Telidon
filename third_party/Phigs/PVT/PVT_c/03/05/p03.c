/* fort/03/05/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 03.05/03                              * */
/*  *    TEST TITLE : Delete all structures from archive    * */
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
    extern /* Subroutine */ int endit_(void), nrsid (integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nrsid ();
#endif /* NO_PROTO */
    static integer actlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), ndasar (integer *), 
	    initgl_(char *, ftnlen), avarnm_(integer *), noparf (integer *, 
	    integer *), narast (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclarf (), ndasar (), initgl_(), avarnm_(), 
	    noparf (), narast ();
#endif /* NO_PROTO */
    static integer actstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    stdcss_(void), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), stdcss_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("03.05/03", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  set up standard networks in CSS */
    stdcss_();
/*  open new archive file, with arid = archive identifier */
    arid = 3;
    avarnm_(&arnm);
    noparf (&arid, &arnm);
/*  <archive all structures>, into arid */
    narast (&arid);
/*  <delete all structures from archive> arid */
    ndasar (&arid);
#ifndef NO_PROTO
    setmsg_("3 4", "After <delete all structures from archive>, the specifie"
	    "d archive file should be empty.", 3L, 87L);
#else /* NO_PROTO */
    setmsg_("3 4", "After <delete all structures from archive>, the specifie\
d archive file should be empty.", 3L, 87L);
#endif /* NO_PROTO */
/*  <retrieve structure identifiers> with arid */
/*     to determine actstr = actual list of archived structures */
    nrsid (&arid, &c__100, &actlen, actstr);
/*  pass/fail depending on (actstr = empty) */
    L__1 = actlen == 0;
    ifpf_(&L__1);
/*     <close archive file> with arid */
    nclarf (&arid);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

