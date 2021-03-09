/* fort/04/03/04/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;
static integer c__101 = 101;
static integer c__102 = 102;
static integer c__103 = 103;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.04.01/03                        * */
/*  *    TEST TITLE : Current nameset during conceptual     * */
/*  *                 traversal                             * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static real xa[2] = { 1.f,1.f };
    static real ya[2] = { 1.f,1.f };
    static real za[2] = { 1.f,1.f };
#else /* NO_PROTO */
    static real xa[2] = { (float)1.,(float)1. };
    static real ya[2] = { (float)1.,(float)1. };
    static real za[2] = { (float)1.,(float)1. };
#endif /* NO_PROTO */

#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *), 
	    nads (integer *, integer *), nres (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 (), nads (), nres ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum6;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqphf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nclst (void), nexst (integer *), setvs_(char *, 
	    integer *, integer *, ftnlen), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqphf (), nclst (), nexst (), 
	    setvs_(), nopst ();
#endif /* NO_PROTO */
    static integer nanams;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer maxnam, errind, namset[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer namsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static integer mxnofl;
#ifndef NO_PROTO
    extern /* Subroutine */ int curnms_(integer *, integer *, char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int curnms_(), xpopph_();
#endif /* NO_PROTO */

    initgl_("04.03.04.01/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Throughout, incremental spatial search (ISS) is used to probe the */
/*  behavior of the current nameset.  It always searches for a */
/*  primitive at location 1,1,1.  Its filters are set to accept only */
/*  the expected nameset. */
/*  <inquire PHIGS facilities> to determine */
/*    nanams = number of available names in namesets */
/*    mxnofl = maximum length of normal filter length */
    nqphf (&c__1, &errind, &idum1, &idum2, &nanams, &idum3, &idum4, &mxnofl, &
	    idum6);
    chkinq_("pqphf", &errind, 5L);
/*  maxnam is used by ISS to generate the correct filters */
    maxnam = min(nanams,100);
/*  Set up structure #101: */
/*  1. add names to set: 3,4,5,9 */
/*  2. execute structure 102 */
/*  3. remove names from set: 4,6 */
/*  4. execute structure 102 */
    nopst (&c__101);
    setvs_("3,5,4,9", namset, &namsiz, 7L);
    nads (&namsiz, namset);
    nexst (&c__102);
    setvs_("4,6", namset, &namsiz, 3L);
    nres (&namsiz, namset);
    nexst (&c__102);
    nclst ();
/*  Set up structure #102: */
/*  1. polymarker at 1,1,1 */
/*  2. remove names from set: 5,6,7,8 */
/*  3. add names to set: 1,2,8,9 */
/*  4. polymarker at 1,1,1 */
    nopst (&c__102);
    npm3 (&c__1, xa, ya, za);
    setvs_("8,7,6,5", namset, &namsiz, 7L);
    nres (&namsiz, namset);
    setvs_("1,2,8,9", namset, &namsiz, 7L);
    nads (&namsiz, namset);
    npm3 (&c__1, xa, ya, za);
    nclst ();
#ifndef NO_PROTO
    setmsg_("1 4 11 15", "The current name set should be initialized to the "
	    "null set at the start of traversal.", 9L, 85L);
#else /* NO_PROTO */
    setmsg_("1 4 11 15", "The current name set should be initialized to the \
null set at the start of traversal.", 9L, 85L);
#endif /* NO_PROTO */
    curnms_(&mxnofl, &maxnam, "102,0", "102,1", " ", 5L, 5L, 1L);
#ifndef NO_PROTO
    setmsg_("1 4 11 12 13 15", "The current name set should be augmented by "
	    "<add names to set> and reduced by <remove names from set> during"
	    " traversal within a structure.", 15L, 138L);
#else /* NO_PROTO */
    setmsg_("1 4 11 12 13 15", "The current name set should be augmented by \
<add names to set> and reduced by <remove names from set> during traversal w\
ithin a structure.", 15L, 138L);
#endif /* NO_PROTO */
    curnms_(&mxnofl, &maxnam, "102,0", "102,4", "1,2,8,9", 5L, 5L, 7L);
#ifndef NO_PROTO
    setmsg_("1 4 11 12 13 15", "The current name set should be inherited unc"
	    "hanged from an invoking structure during traversal.", 15L, 95L);
#else /* NO_PROTO */
    setmsg_("1 4 11 12 13 15", "The current name set should be inherited unc\
hanged from an invoking structure during traversal.", 15L, 95L);
#endif /* NO_PROTO */
    curnms_(&mxnofl, &maxnam, "101,0", "101,2, 102,1", "3,4,5,9", 5L, 12L, 7L)
	    ;
#ifndef NO_PROTO
    setmsg_("1 4 11 12 13 15", "The current name set should be inherited unc"
	    "hanged from an invoking structure during traversal and then modi"
	    "fied by <add names to set> and <remove names from set> within th"
	    "e structure.", 15L, 184L);
#else /* NO_PROTO */
    setmsg_("1 4 11 12 13 15", "The current name set should be inherited unc\
hanged from an invoking structure during traversal and then modified by <add\
 names to set> and <remove names from set> within the structure.", 15L, 184L);

#endif /* NO_PROTO */
    curnms_(&mxnofl, &maxnam, "101,0", "101,2, 102,4", "1,2,3,4,8,9", 5L, 12L,
	     11L);
#ifndef NO_PROTO
    setmsg_("1 4 11 12 13 14 15", "After sub-traversal of the network specif"
	    "ied by <execute structure>, the current name set should be resto"
	    "red to the value it had just prior to the sub-traversal.", 18L, 
	    161L);
#else /* NO_PROTO */
    setmsg_("1 4 11 12 13 14 15", "After sub-traversal of the network specif\
ied by <execute structure>, the current name set should be restored to the v\
alue it had just prior to the sub-traversal.", 18L, 161L);
#endif /* NO_PROTO */
    curnms_(&mxnofl, &maxnam, "101,0", "101,4, 102,1", "3,5,9", 5L, 12L, 5L);
#ifndef NO_PROTO
    setmsg_("1 4 11 12 13 14 15", "The current nameset should reflect all th"
	    "e effects of traversal: inheritance, restoration after sub-trave"
	    "rsal, and additions and removals within the current structure.", 
	    18L, 167L);
#else /* NO_PROTO */
    setmsg_("1 4 11 12 13 14 15", "The current nameset should reflect all th\
e effects of traversal: inheritance, restoration after sub-traversal, and ad\
ditions and removals within the current structure.", 18L, 167L);
#endif /* NO_PROTO */
    curnms_(&mxnofl, &maxnam, "101,0", "101,4, 102,4", "1,2,3,8,9", 5L, 12L, 
	    9L);
/*  Set up structure #103: */
/*  1. add names to set: 0, 1, max+1, -1 */
/*  2. polymarker at 1,1,1 */
/*  3. remove names from set: 1, max+11, -10 */
/*  4. polymarker at 1,1,1 */
    nopst (&c__103);
    setvs_("3,2,1,0", namset, &namsiz, 7L);
    namset[0] = nanams;
    namset[1] = -1;
    nads (&namsiz, namset);
    npm3 (&c__1, xa, ya, za);
    setvs_("3,2,1", namset, &namsiz, 5L);
    namset[0] = nanams + 10;
    namset[1] = -10;
    nres (&namsiz, namset);
    npm3 (&c__1, xa, ya, za);
    nclst ();
#ifndef NO_PROTO
    setmsg_("1 10 11 12 15 16", "The current name set should be augmented by"
	    " the valid names specified by <add names to set> during traversa"
	    "l within a structure, and invalid names should be ignored.", 16L, 
	    165L);
#else /* NO_PROTO */
    setmsg_("1 10 11 12 15 16", "The current name set should be augmented by\
 the valid names specified by <add names to set> during traversal within a s\
tructure, and invalid names should be ignored.", 16L, 165L);
#endif /* NO_PROTO */
    curnms_(&mxnofl, &maxnam, "103,0", "103,2", "0,1", 5L, 5L, 3L);
#ifndef NO_PROTO
    setmsg_("4 10 11 13 15 16", "The current name set should be reduced by t"
	    "he valid names specified by <remove names from set> during trave"
	    "rsal within a structure, and invalid names should be ignored.", 
	    16L, 168L);
#else /* NO_PROTO */
    setmsg_("4 10 11 13 15 16", "The current name set should be reduced by t\
he valid names specified by <remove names from set> during traversal within \
a structure, and invalid names should be ignored.", 16L, 168L);
#endif /* NO_PROTO */
    curnms_(&mxnofl, &maxnam, "103,0", "103,4", "0", 5L, 5L, 1L);
/* L666: */
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

