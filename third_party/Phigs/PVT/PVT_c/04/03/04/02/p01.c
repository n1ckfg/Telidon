/* fort/04/03/04/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.04.02/01                        * */
/*  *    TEST TITLE : Highlighting filter - setting and     * */
/*  *                 inquiring                             * */
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
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum4, idum5, idum6, idum7;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqphf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nclwk (integer *);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqphf (), nclwk ();
    extern logical seteq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer nanams;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, incset[100], excset[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer incsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqhlft (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), setmsg_(
	    char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqhlft (), setmsg_();
#endif /* NO_PROTO */
    static integer inqset[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int nshlft (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nshlft ();
#endif /* NO_PROTO */
    static integer excsiz, exqset[100], inqsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer exqsiz;

    initgl_("04.03.04.02/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("2 3", "Immediately after opening the workstation, the highlight"
	    "ing filter inclusion and exclusion sets should be null.", 3L, 
	    111L);
#else /* NO_PROTO */
    setmsg_("2 3", "Immediately after opening the workstation, the highlight\
ing filter inclusion and exclusion sets should be null.", 3L, 111L);
#endif /* NO_PROTO */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  <inquire highlighting filter> */
    nqhlft (&globnu_1.wkid, &c__100, &c__100, &errind, &inqsiz, inqset, &
	    exqsiz, exqset);
    L__1 = errind == 0 && inqsiz == 0 && exqsiz == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 10", "Highlighting filter should be reported as it was set "
	    "for any set of names drawn from the accessible range.", 6L, 106L);

#else /* NO_PROTO */
    setmsg_("1 2 10", "Highlighting filter should be reported as it was set \
for any set of names drawn from the accessible range.", 6L, 106L);
#endif /* NO_PROTO */
    setvs_("2,44,8,4,63", incset, &incsiz, 11L);
    setvs_("0,4,5,32,59", excset, &excsiz, 11L);
/*  <set highlighting filter>: */
    nshlft (&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/*  <inquire highlighting filter> */
    nqhlft (&globnu_1.wkid, &c__100, &c__100, &errind, &inqsiz, inqset, &
	    exqsiz, exqset);
/*  pass/fail depending on (inclusion set = orig_inclusion and */
/*                          exclusion set = orig_inclusion) */
    L__1 = errind == 0 && inqsiz == incsiz && exqsiz == excsiz && seteq_(&
	    incsiz, incset, inqset) && seteq_(&excsiz, excset, exqset);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2", "Highlighting filter should be reported as it was re-set "
	    "for any set of names drawn from the accessible range.", 3L, 109L);

#else /* NO_PROTO */
    setmsg_("1 2", "Highlighting filter should be reported as it was re-set \
for any set of names drawn from the accessible range.", 3L, 109L);
#endif /* NO_PROTO */
    setvs_("59,47", incset, &incsiz, 5L);
    setvs_("13,15,18", excset, &excsiz, 8L);
/*  <set highlighting filter> */
    nshlft (&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/*  <inquire highlighting filter> */
    nqhlft (&globnu_1.wkid, &c__100, &c__100, &errind, &inqsiz, inqset, &
	    exqsiz, exqset);
/*  pass/fail depending on (inclusion set = new_inclusion  and */
/*                          exclusion set = new_exclusion) */
    L__1 = errind == 0 && inqsiz == incsiz && exqsiz == excsiz && seteq_(&
	    incsiz, incset, inqset) && seteq_(&excsiz, excset, exqset);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 11", "Highlighting filter should be capable of containing a"
	    "t at least 64 names in its inclusion and exclusion sets.", 6L, 
	    109L);
#else /* NO_PROTO */
    setmsg_("1 2 11", "Highlighting filter should be capable of containing a\
t at least 64 names in its inclusion and exclusion sets.", 6L, 109L);
#endif /* NO_PROTO */
    for (ix = 1; ix <= 64; ++ix) {
	incset[ix - 1] = 64 - ix;
	excset[ix - 1] = 64 - ix;
/* L100: */
    }
    incsiz = 64;
    excsiz = 64;
/*  <set highlighting filter> */
    nshlft (&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/*  <inquire highlighting filter> */
    nqhlft (&globnu_1.wkid, &c__100, &c__100, &errind, &inqsiz, inqset, &
	    exqsiz, exqset);
/*  pass/fail depending on (inclusion set = new_inclusion  and */
/*                          exclusion set = new_exclusion) */
    L__1 = errind == 0 && inqsiz == incsiz && exqsiz == excsiz && seteq_(&
	    incsiz, incset, inqset) && seteq_(&excsiz, excset, exqset);
    ifpf_(&L__1);
/*  <inquire PHIGS facilities> to determine */
/*    nanams = number of available names in namesets */
    nqphf (&c__1, &errind, &idum1, &idum2, &nanams, &idum4, &idum5, &idum6, &
	    idum7);
    chkinq_("pqphf", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("1 2 12", "Highlighting filter should be capable of containing t"
	    "he minimum and maximum allowed value for a name.", 6L, 101L);
#else /* NO_PROTO */
    setmsg_("1 2 12", "Highlighting filter should be capable of containing t\
he minimum and maximum allowed value for a name.", 6L, 101L);
#endif /* NO_PROTO */
    incset[0] = 0;
    incset[1] = nanams - 1;
    excset[1] = 0;
    excset[0] = nanams - 1;
    incsiz = 2;
    excsiz = 2;
/*  <set highlighting filter> */
/*     new_inclusion set = 0,nanams-1 */
/*     new_exclusion set = 0,nanams-1 */
    nshlft (&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/*  <inquire highlighting filter> */
    nqhlft (&globnu_1.wkid, &c__100, &c__100, &errind, &inqsiz, inqset, &
	    exqsiz, exqset);
/*  pass/fail depending on (inclusion set = new_inclusion  and */
/*                          exclusion set = new_exclusion) */
    L__1 = errind == 0 && inqsiz == incsiz && exqsiz == excsiz && seteq_(&
	    incsiz, incset, inqset) && seteq_(&excsiz, excset, exqset);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 2 12 13", "Highlighting filter should contain only the valid "
	    "names as set; invalid names specified by <set highlighting filte"
	    "r> should be ignored.", 9L, 135L);
#else /* NO_PROTO */
    setmsg_("1 2 12 13", "Highlighting filter should contain only the valid \
names as set; invalid names specified by <set highlighting filter> should be\
 ignored.", 9L, 135L);
#endif /* NO_PROTO */
/*  <set highlighting filter> */
/*     inv_inclusion set = 0, nanams-1, nanams,    -10 */
/*     inv_exclusion set = 0, nanams-1, nanams+10, -10 */
    incset[0] = 0;
    incset[1] = nanams;
    incset[2] = -10;
    incset[3] = nanams - 1;
    excset[0] = -10;
    excset[1] = nanams + 10;
    excset[2] = 0;
    excset[3] = nanams - 1;
    incsiz = 4;
    excsiz = 4;
    nshlft (&globnu_1.wkid, &incsiz, incset, &excsiz, excset);
/*  <inquire highlighting filter> */
    nqhlft (&globnu_1.wkid, &c__100, &c__100, &errind, &inqsiz, inqset, &
	    exqsiz, exqset);
    incset[0] = 0;
    incset[1] = nanams - 1;
    excset[1] = 0;
    excset[0] = nanams - 1;
    incsiz = 2;
    excsiz = 2;
    L__1 = errind == 0 && inqsiz == incsiz && exqsiz == excsiz && seteq_(&
	    incsiz, incset, inqset) && seteq_(&excsiz, excset, exqset);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 3", "Immediately after re-opening the workstation, the highli"
	    "ghting filter inclusion and exclusion sets should be null.", 3L, 
	    114L);
#else /* NO_PROTO */
    setmsg_("2 3", "Immediately after re-opening the workstation, the highli\
ghting filter inclusion and exclusion sets should be null.", 3L, 114L);
#endif /* NO_PROTO */
    nclwk (&globnu_1.wkid);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  <inquire highlighting filter> */
    nqhlft (&globnu_1.wkid, &c__100, &c__100, &errind, &inqsiz, inqset, &
	    exqsiz, exqset);
/*  pass/fail depending on (inclusion = null and */
/*                          exclusion = null) */
    L__1 = errind == 0 && inqsiz == 0 && exqsiz == 0;
    ifpf_(&L__1);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

