/* fort/03/04/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__109 = 109;
static integer c__0 = 0;
static integer c__107 = 107;
static integer c__1 = 1;
static integer c__106 = 106;
static integer c__108 = 108;
static integer c__3 = 3;
static integer c__104 = 104;
static integer c__5 = 5;
static integer c__105 = 105;
static integer c__101 = 101;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.04/03                              * */
/*  *    TEST TITLE : Retrieving ancestor paths             * */
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
    extern /* Subroutine */ int pass_(void), endit_(void), nclarf (integer *),
	     ndasar (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_(), endit_(), nclarf (), ndasar ();
#endif /* NO_PROTO */
    static integer retcod;
#ifndef NO_PROTO
    extern /* Subroutine */ int arcpth_(integer *, char *, integer *, integer 
	    *, integer *, integer *, char *, ftnlen, ftnlen), initgl_(char *, 
	    ftnlen), avarnm_(integer *), noparf (integer *, integer *), 
	    narast (integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    csspth_(void), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int arcpth_(), initgl_(), avarnm_(), noparf (), 
	    narast (), setmsg_(), csspth_(), xpopph_();
#endif /* NO_PROTO */

/* truncation method */
    initgl_("03.04/03", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  open new archive file, with arid = archive identifier */
    arid = 30;
    avarnm_(&arnm);
    noparf (&arid, &arnm);
/*  Set up archive as follows: */

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
/*  *** *** *** *** ***   No truncation   *** *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("5 7 8 10", "<Retrieve paths to ancestors> should retrieve all m"
	    "aximal ancestor paths when path depth is zero.", 8L, 97L);
#else /* NO_PROTO */
    setmsg_("5 7 8 10", "<Retrieve paths to ancestors> should retrieve all m\
aximal ancestor paths when path depth is zero.", 8L, 97L);
#endif /* NO_PROTO */
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 109 */
/*       path order   = TOPFIRST */
/*       path depth   = zero */
#ifndef NO_PROTO
    arcpth_(&arid, "A", &c__109, &c__0, &c__0, &retcod, "101,1, 102,1, 109,0"
	    "        /101,1, 102,2, 104,1, 109,0 /101,2, 103,1, 104,1, 109,0 "
	    "/101,2, 103,2, 105,1, 109,0 /101,2, 103,3, 105,1, 109,0 /", 1L, 
	    140L);
#else /* NO_PROTO */
    arcpth_(&arid, "A", &c__109, &c__0, &c__0, &retcod, "101,1, 102,1, 109,0\
        /101,1, 102,2, 104,1, 109,0 /101,2, 103,1, 104,1, 109,0 /101,2, 103,\
2, 105,1, 109,0 /101,2, 103,3, 105,1, 109,0 /", 1L, 140L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 107 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = zero */
#ifndef NO_PROTO
    arcpth_(&arid, "A", &c__107, &c__1, &c__0, &retcod, "101,3, 107,0 /106,1"
	    ", 107,0 /", 1L, 28L);
#else /* NO_PROTO */
    arcpth_(&arid, "A", &c__107, &c__1, &c__0, &retcod, "101,3, 107,0 /106,1\
, 107,0 /", 1L, 28L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 106 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = zero */
    arcpth_(&arid, "A", &c__106, &c__1, &c__0, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 108 */
/*       path order   = TOPFIRST */
/*       path depth   = zero */
    arcpth_(&arid, "A", &c__108, &c__0, &c__0, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
    pass_();
/*  *** *** *** ***   Truncating via TOPFIRST   *** *** *** *** */
L2000:
#ifndef NO_PROTO
    setmsg_("5 7 8 10 12 16", "<Retrieve paths to ancestors> should retrieve"
	    " all qualifying ancestor paths (or portions thereof), with no re"
	    "petition, when path depth is positive and path order is TOPFIRST."
	    , 14L, 174L);
#else /* NO_PROTO */
    setmsg_("5 7 8 10 12 16", "<Retrieve paths to ancestors> should retrieve\
 all qualifying ancestor paths (or portions thereof), with no repetition, wh\
en path depth is positive and path order is TOPFIRST.", 14L, 174L);
#endif /* NO_PROTO */
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 109 */
/*       path order   = TOPFIRST */
/*       path depth   = 3 */
#ifndef NO_PROTO
    arcpth_(&arid, "A", &c__109, &c__0, &c__3, &retcod, "101,1, 102,1, 109,0"
	    " /101,1, 102,2, 104,1 /101,2, 103,1, 104,1 /101,2, 103,2, 105,1 "
	    "/101,2, 103,3, 105,1 /", 1L, 105L);
#else /* NO_PROTO */
    arcpth_(&arid, "A", &c__109, &c__0, &c__3, &retcod, "101,1, 102,1, 109,0\
 /101,1, 102,2, 104,1 /101,2, 103,1, 104,1 /101,2, 103,2, 105,1 /101,2, 103,\
3, 105,1 /", 1L, 105L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 104 */
/*       path order   = TOPFIRST */
/*       path depth   = 5 */
/*    saap = set of all ancestor paths. */
#ifndef NO_PROTO
    arcpth_(&arid, "A", &c__104, &c__0, &c__5, &retcod, "101,1, 102,2, 104,0"
	    " /101,2, 103,1, 104,0 /", 1L, 42L);
#else /* NO_PROTO */
    arcpth_(&arid, "A", &c__104, &c__0, &c__5, &retcod, "101,1, 102,2, 104,0\
 /101,2, 103,1, 104,0 /", 1L, 42L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 105 */
/*       path order   = TOPFIRST */
/*       path depth   = 1 */
    arcpth_(&arid, "A", &c__105, &c__0, &c__1, &retcod, "101,2 /", 1L, 7L);
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 101 */
/*       path order   = TOPFIRST */
/*       path depth   = 5 */
    arcpth_(&arid, "A", &c__101, &c__0, &c__5, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
    pass_();
/*  *** *** *** ***   Truncating via BOTTOMFIRST   *** *** *** *** */
L3000:
#ifndef NO_PROTO
    setmsg_("5 7 8 10 13 16", "<Retrieve paths to ancestors> should retrieve"
	    " all qualifying ancestor paths (or portions thereof), with no re"
	    "petition, when path depth is positive and path order is BOTTOMFI"
	    "RST.", 14L, 177L);
#else /* NO_PROTO */
    setmsg_("5 7 8 10 13 16", "<Retrieve paths to ancestors> should retrieve\
 all qualifying ancestor paths (or portions thereof), with no repetition, wh\
en path depth is positive and path order is BOTTOMFIRST.", 14L, 177L);
#endif /* NO_PROTO */
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 109 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 3 */
/*    saap = set of all ancestor paths. */
#ifndef NO_PROTO
    arcpth_(&arid, "A", &c__109, &c__1, &c__3, &retcod, "101,1, 102,1, 109,0"
	    " /102,2, 104,1, 109,0 /103,1, 104,1, 109,0 /103,2, 105,1, 109,0 "
	    "/103,3, 105,1, 109,0 /", 1L, 105L);
#else /* NO_PROTO */
    arcpth_(&arid, "A", &c__109, &c__1, &c__3, &retcod, "101,1, 102,1, 109,0\
 /102,2, 104,1, 109,0 /103,1, 104,1, 109,0 /103,2, 105,1, 109,0 /103,3, 105,\
1, 109,0 /", 1L, 105L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L666;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 109 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 2 */
#ifndef NO_PROTO
    arcpth_(&arid, "A", &c__109, &c__1, &c__2, &retcod, "102,1, 109,0 /104,1"
	    ", 109,0 /105,1, 109,0 /", 1L, 42L);
#else /* NO_PROTO */
    arcpth_(&arid, "A", &c__109, &c__1, &c__2, &retcod, "102,1, 109,0 /104,1\
, 109,0 /105,1, 109,0 /", 1L, 42L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L666;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 107 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 5 */
#ifndef NO_PROTO
    arcpth_(&arid, "A", &c__107, &c__1, &c__5, &retcod, "101,3, 107,0 / 106,"
	    "1, 107,0 / ", 1L, 30L);
#else /* NO_PROTO */
    arcpth_(&arid, "A", &c__107, &c__1, &c__5, &retcod, "101,3, 107,0 / 106,\
1, 107,0 / ", 1L, 30L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L666;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 107 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 1 */
    arcpth_(&arid, "A", &c__107, &c__1, &c__1, &retcod, "107,0 /", 1L, 7L);
    if (retcod != 0) {
	fail_();
	goto L666;
    }
/*  Use <retrieve paths to ancestors> with */
/*       structure id = 106 */
/*       path order   = BOTTOMFIRST */
/*       path depth   = 1 */
    arcpth_(&arid, "A", &c__106, &c__1, &c__1, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L666;
    }
    pass_();
L666:
/*  close archive file */
    nclarf (&arid);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

