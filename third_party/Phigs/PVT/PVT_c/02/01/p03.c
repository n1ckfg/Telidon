/* fort/02/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.01/03                              * */
/*  *    TEST TITLE : Inquiring about descendant paths      * */
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
    initgl_("02.01/03", 8L);
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
    setmsg_("1 4 5 6 8", "<Inquire paths to descendants> should retrieve all"
	    " maximal descendant paths when path depth is zero.", 9L, 100L);
    pthseq_("D", &c__101, &c__0, &c__0, &retcod, "101,1, 102,1, 109,0 /101,1"
	    ", 102,2, 104,1, 109,0 /101,2, 103,1, 104,1, 109,0 /101,2, 103,2,"
	    " 105,1, 109,0 /101,2, 103,3, 105,1, 109,0 /101,3, 107,0 /", 1L, 
	    147L);
#else /* NO_PROTO */
    setmsg_("1 4 5 6 8", "<Inquire paths to descendants> should retrieve all\
 maximal descendant paths when path depth is zero.", 9L, 100L);
    pthseq_("D", &c__101, &c__0, &c__0, &retcod, "101,1, 102,1, 109,0 /101,1\
, 102,2, 104,1, 109,0 /101,2, 103,1, 104,1, 109,0 /101,2, 103,2, 105,1, 109,\
0 /101,2, 103,3, 105,1, 109,0 /101,3, 107,0 /", 1L, 147L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
#ifndef NO_PROTO
    pthseq_("D", &c__103, &c__1, &c__0, &retcod, "103,1, 104,1, 109,0 /103,2"
	    ", 105,1, 109,0 /103,3, 105,1, 109,0 /", 1L, 63L);
#else /* NO_PROTO */
    pthseq_("D", &c__103, &c__1, &c__0, &retcod, "103,1, 104,1, 109,0 /103,2\
, 105,1, 109,0 /103,3, 105,1, 109,0 /", 1L, 63L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
    pthseq_("D", &c__109, &c__1, &c__0, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
    pthseq_("D", &c__108, &c__0, &c__0, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L2000;
    }
    pass_();
/*  *** *** *** *** ***   Truncating via TOPFIRST   *** *** *** *** *** */

L2000:
#ifndef NO_PROTO
    setmsg_("1 4 5 6 11 14", "<Inquire paths to descendants> should retrieve"
	    " all qualifying descendant paths (or portions thereof), with no "
	    "repetition, when path depth is positive and path order is TOPFIR"
	    "ST.", 13L, 177L);
    pthseq_("D", &c__101, &c__0, &c__2, &retcod, "101,1, 102,1 /101,1, 102,2"
	    " /101,2, 103,1 /101,2, 103,2 /101,2, 103,3 /101,3, 107,0 /", 1L, 
	    84L);
#else /* NO_PROTO */
    setmsg_("1 4 5 6 11 14", "<Inquire paths to descendants> should retrieve\
 all qualifying descendant paths (or portions thereof), with no repetition, \
when path depth is positive and path order is TOPFIRST.", 13L, 177L);
    pthseq_("D", &c__101, &c__0, &c__2, &retcod, "101,1, 102,1 /101,1, 102,2\
 /101,2, 103,1 /101,2, 103,2 /101,2, 103,3 /101,3, 107,0 /", 1L, 84L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
    pthseq_("D", &c__101, &c__0, &c__1, &retcod, "101,1 /101,2 /101,3 /", 1L, 
	    21L);
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
    pthseq_("D", &c__104, &c__0, &c__5, &retcod, "104,1, 109,0 /", 1L, 14L);
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
    pthseq_("D", &c__109, &c__0, &c__5, &retcod, " ", 1L, 1L);
    if (retcod != 0) {
	fail_();
	goto L3000;
    }
    pass_();
/*  *** *** *** *** ***   Truncating via BOTTOMFIRST   *** *** *** *** ***
 */
L3000:
#ifndef NO_PROTO
    setmsg_("1 4 5 6 12 14", "<Inquire paths to descendants> should retrieve"
	    " all qualifying descendant paths (or portions thereof), with no "
	    "repetition, when path depth is positive and path order is BOTTOM"
	    "FIRST.", 13L, 180L);
    pthseq_("D", &c__101, &c__1, &c__2, &retcod, "102,1, 109,0 /104,1, 109,0"
	    " /105,1, 109,0 /101,3, 107,0 /", 1L, 56L);
#else /* NO_PROTO */
    setmsg_("1 4 5 6 12 14", "<Inquire paths to descendants> should retrieve\
 all qualifying descendant paths (or portions thereof), with no repetition, \
when path depth is positive and path order is BOTTOMFIRST.", 13L, 180L);
    pthseq_("D", &c__101, &c__1, &c__2, &retcod, "102,1, 109,0 /104,1, 109,0\
 /105,1, 109,0 /101,3, 107,0 /", 1L, 56L);
#endif /* NO_PROTO */
    if (retcod != 0) {
	fail_();
	goto L666;
    }
    pthseq_("D", &c__102, &c__1, &c__1, &retcod, "109,0 /", 1L, 7L);
    if (retcod != 0) {
	fail_();
	goto L666;
    }
    pthseq_("D", &c__108, &c__1, &c__1, &retcod, " ", 1L, 1L);
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

