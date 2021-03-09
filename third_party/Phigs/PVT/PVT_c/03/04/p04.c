/* fort/03/04/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__101 = 101;
static integer c__0 = 0;
static integer c__103 = 103;
static integer c__1 = 1;
static integer c__109 = 109;
static integer c__108 = 108;
static integer c__2 = 2;
static integer c__104 = 104;
static integer c__5 = 5;
static integer c__102 = 102;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.04/04                              * */
/*  *    TEST TITLE : Retrieve descendant paths             * */
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
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndas ();
#endif /* NO_PROTO */
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void), endit_(void), setvs_(char *, 
	    integer *, integer *, ftnlen), nclarf (integer *), ndasar (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), endit_(), setvs_(), nclarf (), 
	    ndasar ();
#endif /* NO_PROTO */
    static integer retcod;
#ifndef NO_PROTO
    extern /* Subroutine */ int arcpth_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int arcpth_();
#endif /* NO_PROTO */
    static integer arclst[5], arcnum;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *), 
	    noparf (integer *, integer *), narast (integer *), setmsg_(char *,
	     char *, ftnlen, ftnlen), csspth_(void), ndstar (integer *, 
	    integer *, integer *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), avarnm_(), noparf (), narast (), 
	    setmsg_(), csspth_(), ndstar (), xpopph_();
#endif /* NO_PROTO */

/* truncation method */
    initgl_("03.04/04", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  open new archive file, with arid = archive identifier */
    arid = 30;
    avarnm_(&arnm);
    noparf (&arid, &arnm);
/*  set up archive as follows: */

/*                   101        106       108 */
/*                  / | \       / */
/*                 /  |  \    1/ */
/*               1/  2|  3\   / */
/*               /    |    \ / */
/*              /     |    107 */
/*             /      | */
/*          102      103 */
/*          | \      / \\ */
/*          |  \   1/   \\ */
/*         1|  2\  /    2\\3 */
/*          |    \/       \\ */
/*          |    104      105 */
/*          |     |      / */
/*          |    1|    1/ */
/*           \    |    / */
/*            \   |   / */
/*             \  |  / */
/*              \ | / */
/*               109 */


/*  The nodes of the graph (101-109) represent structures, and the */
/*  labelled edges are references to invoked (lower) structures. */
/*  The labels (1-3) represent the element position of the <execute */
/*  structure> function within the calling structure.  Eg, an element */
/*  reference path from 101 to 109 would be: (101, 2), (103, 3), */
/*  (105, 1), (109, 0). */
    csspth_();
    ndasar (&arid);
    narast (&arid);
    ndas ();
/*  *** *** *** ***   No truncation   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("6 7 8 11", "<Retrieve paths to descendants> should retrieve all"
	    " maximal descendant paths when path depth is zero.", 8L, 101L);
#else /* NO_PROTO */
    setmsg_("6 7 8 11", "<Retrieve paths to descendants> should retrieve all\
 maximal descendant paths when path depth is zero.", 8L, 101L);
#endif /* NO_PROTO */
/*  Use <retrieve paths to descendants> with */
/*       structure id = 101 */
/*       path order   = TOPFIRST */
/*       path depth   = zero */
#ifndef NO_PROTO
    arcpth_(&arid, "D", &c__101, &c__0, &c__0, &retcod, "101,1, 102,1, 109,0"
	    " /101,1, 102,2, 104,1, 109,0 /101,2, 103,1, 104,1, 109,0 /101,2,"
	    " 103,2, 105,1, 109,0 /101,2, 103,3, 105,1, 109,0 /101,3, 107,0 /",
	     1L, 147L);
#else /* NO_PROTO */
    arcpth_(&arid, "D", &c__101, &c__0, &c__0, &retcod, "101,1, 102,1, 109,0\
 /101,1, 102,2, 104,1, 109,0 /101,2, 103,1, 104,1, 109,0 /101,2, 103,2, 105,\
1, 109,0 /101,2, 103,3, 105,1, 109,0 /101,3, 107,0 /", 1L, 147L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 103 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = zero */
#ifndef NO_PROTO
    arcpth_(&arid, "D", &c__103, &c__1, &c__0, &retcod, "103,1, 104,1, 109,0"
	    " /103,2, 105,1, 109,0 /103,3, 105,1, 109,0 /", 1L, 63L);
#else /* NO_PROTO */
    arcpth_(&arid, "D", &c__103, &c__1, &c__0, &retcod, "103,1, 104,1, 109,0\
 /103,2, 105,1, 109,0 /103,3, 105,1, 109,0 /", 1L, 63L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 109 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = zero */
    arcpth_(&arid, "D", &c__109, &c__1, &c__0, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 108 */
/*       path order   = TOPFIRST */
/*       path depth   = zero */
    arcpth_(&arid, "D", &c__108, &c__0, &c__0, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
    pass_();
/*  *** *** *** ***   Truncating via TOPFIRST   *** *** *** *** */
L2000:
#ifndef NO_PROTO
    setmsg_("6 7 8 11 14 17", "<Retrieve paths to descendants> should retrie"
	    "ve all qualifying descendant paths (or portions thereof), with n"
	    "o repetition, when path depth is positive and path order is TOPF"
	    "IRST.", 14L, 178L);
#else /* NO_PROTO */
    setmsg_("6 7 8 11 14 17", "<Retrieve paths to descendants> should retrie\
ve all qualifying descendant paths (or portions thereof), with no repetition\
, when path depth is positive and path order is TOPFIRST.", 14L, 178L);
#endif /* NO_PROTO */
/*  Use <retrieve paths to descendants> with */
/*       structure id = 101 */
/*       path order   = TOPFIRST */
/*       path depth   = 2 */
#ifndef NO_PROTO
    arcpth_(&arid, "D", &c__101, &c__0, &c__2, &retcod, "101,1, 102,1 /101,1"
	    ", 102,2 /101,2, 103,1 /101,2, 103,2 /101,2, 103,3 /101,3, 107,0 /"
	    , 1L, 84L);
#else /* NO_PROTO */
    arcpth_(&arid, "D", &c__101, &c__0, &c__2, &retcod, "101,1, 102,1 /101,1\
, 102,2 /101,2, 103,1 /101,2, 103,2 /101,2, 103,3 /101,3, 107,0 /", 1L, 84L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 101 */
/*       path order   = TOPFIRST */
/*       path depth   = 1 */
#ifndef NO_PROTO
    arcpth_(&arid, "D", &c__101, &c__0, &c__1, &retcod, "101,1 /101,2 /101,3"
	    " /", 1L, 21L);
#else /* NO_PROTO */
    arcpth_(&arid, "D", &c__101, &c__0, &c__1, &retcod, "101,1 /101,2 /101,3\
 /", 1L, 21L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 104 */
/*       path order   = TOPFIRST */
/*       path depth   = 5 */
    arcpth_(&arid, "D", &c__104, &c__0, &c__5, &retcod, "104,1, 109,0 /", 1L, 
	    14L);
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 109 */
/*       path order   = TOPFIRST */
/*       path depth   = 5 */
    arcpth_(&arid, "D", &c__109, &c__0, &c__5, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
    pass_();
/*  *** *** *** ***   Truncating via BOTTOMFIRST   *** *** *** *** */
L3000:
#ifndef NO_PROTO
    setmsg_("6 7 8 11 15 17", "<Retrieve paths to descendants> should retrie"
	    "ve all qualifying descendant paths (or portions thereof), with n"
	    "o repetition, when path depth is positive and path order is BOTT"
	    "OMFIRST.", 14L, 181L);
#else /* NO_PROTO */
    setmsg_("6 7 8 11 15 17", "<Retrieve paths to descendants> should retrie\
ve all qualifying descendant paths (or portions thereof), with no repetition\
, when path depth is positive and path order is BOTTOMFIRST.", 14L, 181L);
#endif /* NO_PROTO */
/*  Use <retrieve paths to descendants> with */
/*       structure id = 101 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 2 */
#ifndef NO_PROTO
    arcpth_(&arid, "D", &c__101, &c__1, &c__2, &retcod, "102,1, 109,0 /104,1"
	    ", 109,0 /105,1, 109,0 /101,3, 107,0 /", 1L, 56L);
#else /* NO_PROTO */
    arcpth_(&arid, "D", &c__101, &c__1, &c__2, &retcod, "102,1, 109,0 /104,1\
, 109,0 /105,1, 109,0 /101,3, 107,0 /", 1L, 56L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L4000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 103 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 5 */
#ifndef NO_PROTO
    arcpth_(&arid, "D", &c__103, &c__1, &c__5, &retcod, "103,1, 104,1, 109,0"
	    " /103,2, 105,1, 109,0 /103,3, 105,1, 109,0 /", 1L, 63L);
#else /* NO_PROTO */
    arcpth_(&arid, "D", &c__103, &c__1, &c__5, &retcod, "103,1, 104,1, 109,0\
 /103,2, 105,1, 109,0 /103,3, 105,1, 109,0 /", 1L, 63L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L4000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 102 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 1 */
    arcpth_(&arid, "D", &c__102, &c__1, &c__1, &retcod, "109,0 /", 1L, 7L);
    if (retcod != 0) {
	fail_();
	goto L4000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 108 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 1 */
    arcpth_(&arid, "D", &c__108, &c__1, &c__1, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L4000;
    }
    pass_();
/*  *** *** ***   Retrieve with missing structure   *** *** *** */
L4000:
/*  delete structure #104 from archive */
    setvs_("104", arclst, &arcnum, 3L);
    ndstar (&arid, &arcnum, arclst);
#ifndef NO_PROTO
    setmsg_("6 7 8 9", "If a referenced structure T does not exist in the ar"
	    "chive, then <retrieve paths to descendants> should behave as if "
	    "T were an existing structure containing no references.", 7L, 170L)
	    ;
#else /* NO_PROTO */
    setmsg_("6 7 8 9", "If a referenced structure T does not exist in the ar\
chive, then <retrieve paths to descendants> should behave as if T were an ex\
isting structure containing no references.", 7L, 170L);
#endif /* NO_PROTO */
/*  Use <retrieve paths to descendants> with */
/*       structure id = 103 */
/*       path order   = TOPFIRST */
/*       path depth   = 0 */
#ifndef NO_PROTO
    arcpth_(&arid, "D", &c__103, &c__0, &c__0, &retcod, "103,1, 104,0 /103,2"
	    ", 105,1, 109,0 /103,3, 105,1, 109,0 /", 1L, 56L);
#else /* NO_PROTO */
    arcpth_(&arid, "D", &c__103, &c__0, &c__0, &retcod, "103,1, 104,0 /103,2\
, 105,1, 109,0 /103,3, 105,1, 109,0 /", 1L, 56L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L5000;
    }
/*  Use <retrieve paths to descendants> with */
/*       structure id = 102 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 1 */
    arcpth_(&arid, "D", &c__102, &c__1, &c__1, &retcod, "104,0 /109,0 /", 1L, 
	    14L);
    if (retcod != 0) {
	fail_();
	goto L5000;
    }
    pass_();
L5000:
    nclarf (&arid);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

