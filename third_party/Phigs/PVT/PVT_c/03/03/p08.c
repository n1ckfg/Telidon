/* fort/03/03/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__50 = 50;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.03/08                              * */
/*  *    TEST TITLE : Archiving and retrieving with         * */
/*  *                 multiple files                        * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndas ();
#endif /* NO_PROTO */
    static integer arnm, arid1, arid2;
    static logical ar1ok, ar2ok;
    static integer idum1, idum2, idum3, idum4, idum5, idum6;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqphf (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nrsid (integer *, integer *, integer *, 
	    integer *), narst (integer *, integer *, integer *), nrast (
	    integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqphf ();
    extern logical seteq_();
    extern /* Subroutine */ int nrsid (), narst (), nrast (), setvs_();
#endif /* NO_PROTO */
    static char chspc1[30], chspc2[30];
    static integer actst1[50], actst2[50], actsz1, actsz2, spcst1[50], spcst2[
	    50], spcsz1, spcsz2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), ndasar (integer *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclarf (), ndasar (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern logical cssids_(char *, ftnlen);
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *), 
	    noparf (integer *, integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), stdcss_(void);
#else /* NO_PROTO */
    extern logical cssids_();
    extern /* Subroutine */ int initgl_(), avarnm_(), noparf (), setmsg_(), 
	    stdcss_();
#endif /* NO_PROTO */
    static integer mxarno;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    initgl_("03.03/08", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  <inquire phigs facilities> to determine */
/*     mxarno = maximum number of simultaneously open archive files */
    nqphf (&c__0, &errind, &idum1, &mxarno, &idum2, &idum3, &idum4, &idum5, &
	    idum6);
    chkinq_("pqphf", &errind, 5L);
    if (mxarno <= 1) {
	inmsg_("Skippping tests: cannot open multiple archive files.", 52L);
	goto L666;
    }
/*  set up standard networks in CSS */
    stdcss_();
/*  open 2 archive files */
    avarnm_(&arnm);
    arid1 = 11;
    noparf (&arid1, &arnm);
    avarnm_(&arnm);
    arid2 = 12;
    noparf (&arid2, &arnm);
    s_copy(chspc1, "111,114,115", 30L, 11L);
    s_copy(chspc2, "109,113", 30L, 7L);
    setvs_(chspc1, spcst1, &spcsz1, 30L);
    setvs_(chspc2, spcst2, &spcsz2, 30L);
/*  <archive structures> spcst1 into arid1 and spcst2 into arid2 */
    ndasar (&arid1);
    ndasar (&arid2);
    narst (&arid1, &spcsz1, spcst1);
    narst (&arid2, &spcsz2, spcst2);
/*  <retrieve structure identifiers> with arid1 and arid2 */
    nrsid (&arid1, &c__50, &actsz1, actst1);
    nrsid (&arid2, &c__50, &actsz2, actst2);
#ifndef NO_PROTO
    setmsg_("1 4", "If more than one archive file is open, <archive structur"
	    "es> should affect only the open archive file specified in its pa"
	    "rameter list.", 3L, 133L);
#else /* NO_PROTO */
    setmsg_("1 4", "If more than one archive file is open, <archive structur\
es> should affect only the open archive file specified in its parameter list."
	    , 3L, 133L);
#endif /* NO_PROTO */
/*  pass/fail depending on (actst1 = spcst1 and actst2 = spcst2) */
    L__1 = actsz1 == spcsz1 && actsz2 == spcsz2 && seteq_(&actsz1, actst1, 
	    spcst1) && seteq_(&actsz2, actst2, spcst2);
    ifpf_(&L__1);
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid1 */
    nrast (&arid1);
    ar1ok = cssids_(chspc1, 30L);
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid2 */
    nrast (&arid2);
    ar2ok = cssids_(chspc2, 30L);
#ifndef NO_PROTO
    setmsg_("11 12", "If more than one archive file is open, <retrieve all s"
	    "tructures> should affect only the open archive file specified in"
	    " its parameter list.", 5L, 138L);
#else /* NO_PROTO */
    setmsg_("11 12", "If more than one archive file is open, <retrieve all s\
tructures> should affect only the open archive file specified in its paramet\
er list.", 5L, 138L);
#endif /* NO_PROTO */
    L__1 = ar1ok && ar2ok;
    ifpf_(&L__1);
/*  <close archive file> with arid1 and arid2 */
    nclarf (&arid1);
    nclarf (&arid2);
/*  done: */
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

