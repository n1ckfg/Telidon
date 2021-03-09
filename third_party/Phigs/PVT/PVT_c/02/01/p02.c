/* fort/02/01/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__105 = 105;
static integer c__101 = 101;
static integer c__5 = 5;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01/02                              * */
/*  *    TEST TITLE : Inquiring about ancestor paths        * */
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
    extern /* Subroutine */ int fail_(void), pass_(void), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_(), endit_();
#endif /* NO_PROTO */
    static integer retcod;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), csspth_(void), pthseq_(char *, integer *, 
	    integer *, integer *, integer *, char *, ftnlen, ftnlen), xpopph_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), csspth_(), pthseq_(), 
	    xpopph_();
#endif /* NO_PROTO */

/* truncation method */
    initgl_("02.01/02", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Use <open structure> and <execute structure> to set up */
/*  the CSS as follows: */

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
/*  common setup routine here */
    csspth_();
/*  *** *** *** *** ***   No truncation   *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 3 5 6 7", "<Inquire paths to ancestors> should retrieve all m"
	    "aximal ancestor paths when path depth is zero.", 9L, 96L);
#else /* NO_PROTO */
    setmsg_("1 3 5 6 7", "<Inquire paths to ancestors> should retrieve all m\
aximal ancestor paths when path depth is zero.", 9L, 96L);
#endif /* NO_PROTO */
/* compare set of all reported ancestor paths to expected value. */
#ifndef NO_PROTO
    pthseq_("A", &c__109, &c__0, &c__0, &retcod, "101,1, 102,1, 109,0       "
	    " /101,1, 102,2, 104,1, 109,0 /101,2, 103,1, 104,1, 109,0 /101,2,"
	    " 103,2, 105,1, 109,0 /101,2, 103,3, 105,1, 109,0 /", 1L, 140L);
#else /* NO_PROTO */
    pthseq_("A", &c__109, &c__0, &c__0, &retcod, "101,1, 102,1, 109,0       \
 /101,1, 102,2, 104,1, 109,0 /101,2, 103,1, 104,1, 109,0 /101,2, 103,2, 105,\
1, 109,0 /101,2, 103,3, 105,1, 109,0 /", 1L, 140L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
#ifndef NO_PROTO
    pthseq_("A", &c__107, &c__1, &c__0, &retcod, "101,3, 107,0 /106,1, 107,0"
	    " /", 1L, 28L);
#else /* NO_PROTO */
    pthseq_("A", &c__107, &c__1, &c__0, &retcod, "101,3, 107,0 /106,1, 107,0\
 /", 1L, 28L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
    pthseq_("A", &c__106, &c__1, &c__0, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
    pthseq_("A", &c__108, &c__0, &c__0, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
    pass_();
/*  *** *** *** *** ***   Truncating via TOPFIRST   *** *** *** *** *** */

L2000:
#ifndef NO_PROTO
    setmsg_("1 3 5 6 9 13", "<Inquire paths to ancestors> should retrieve al"
	    "l qualifying ancestor paths (or portions thereof), with no repet"
	    "ition, when path depth is positive and path order is TOPFIRST.", 
	    12L, 173L);
    pthseq_("A", &c__109, &c__0, &c__3, &retcod, "101,1, 102,1, 109,0 /101,1"
	    ", 102,2, 104,1 /101,2, 103,1, 104,1 /101,2, 103,2, 105,1 /101,2,"
	    " 103,3, 105,1 /", 1L, 105L);
#else /* NO_PROTO */
    setmsg_("1 3 5 6 9 13", "<Inquire paths to ancestors> should retrieve al\
l qualifying ancestor paths (or portions thereof), with no repetition, when \
path depth is positive and path order is TOPFIRST.", 12L, 173L);
    pthseq_("A", &c__109, &c__0, &c__3, &retcod, "101,1, 102,1, 109,0 /101,1\
, 102,2, 104,1 /101,2, 103,1, 104,1 /101,2, 103,2, 105,1 /101,2, 103,3, 105,\
1 /", 1L, 105L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
    pthseq_("A", &c__105, &c__0, &c__1, &retcod, "101,2 /", 1L, 7L);
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
    pthseq_("A", &c__101, &c__0, &c__5, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
    pass_();
/*  *** *** *** *** ***   Truncating via BOTTOMFIRST   *** *** *** *** ***
 */
L3000:
#ifndef NO_PROTO
    setmsg_("1 3 5 6 10 13", "<Inquire paths to ancestors> should retrieve a"
	    "ll qualifying ancestor paths (or portions thereof), with no repe"
	    "tition, when path depth is positive and path order is BOTTOMFIRS"
	    "T.", 13L, 176L);
    pthseq_("A", &c__109, &c__1, &c__3, &retcod, "101,1, 102,1, 109,0 /102,2"
	    ", 104,1, 109,0 /103,1, 104,1, 109,0 /103,2, 105,1, 109,0 /103,3,"
	    " 105,1, 109,0 /", 1L, 105L);
#else /* NO_PROTO */
    setmsg_("1 3 5 6 10 13", "<Inquire paths to ancestors> should retrieve a\
ll qualifying ancestor paths (or portions thereof), with no repetition, when\
 path depth is positive and path order is BOTTOMFIRST.", 13L, 176L);
    pthseq_("A", &c__109, &c__1, &c__3, &retcod, "101,1, 102,1, 109,0 /102,2\
, 104,1, 109,0 /103,1, 104,1, 109,0 /103,2, 105,1, 109,0 /103,3, 105,1, 109,\
0 /", 1L, 105L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L666;
    }
#ifndef NO_PROTO
    pthseq_("A", &c__109, &c__1, &c__2, &retcod, "102,1, 109,0 /104,1, 109,0"
	    " /105,1, 109,0 /", 1L, 42L);
#else /* NO_PROTO */
    pthseq_("A", &c__109, &c__1, &c__2, &retcod, "102,1, 109,0 /104,1, 109,0\
 /105,1, 109,0 /", 1L, 42L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L666;
    }
#ifndef NO_PROTO
    pthseq_("A", &c__107, &c__1, &c__5, &retcod, "101,3, 107,0 / 106,1, 107,"
	    "0 / ", 1L, 30L);
#else /* NO_PROTO */
    pthseq_("A", &c__107, &c__1, &c__5, &retcod, "101,3, 107,0 / 106,1, 107,\
0 / ", 1L, 30L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L666;
    }
    pthseq_("A", &c__107, &c__1, &c__1, &retcod, "107,0 /", 1L, 7L);
    if (retcod != 0) {
	fail_();
	goto L666;
    }
    pthseq_("A", &c__106, &c__1, &c__1, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L666;
    }
    pass_();
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

