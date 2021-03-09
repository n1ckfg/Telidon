/* fort/02/01/02/02/p14.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__20 = 20;
static integer c__21 = 21;
static integer c__22 = 22;
static integer c__221 = 221;
static integer c__222 = 222;
static integer c__2221 = 2221;
static integer c__30 = 30;
static integer c__31 = 31;
static integer c__32 = 32;
static integer c__40 = 40;
static integer c__41 = 41;
static integer c__42 = 42;
static integer c__43 = 43;
static integer c__44 = 44;
static integer c__50 = 50;
static integer c__100 = 100;
static integer c__51 = 51;
static integer c__511 = 511;
static integer c__512 = 512;
static integer c__5121 = 5121;
static integer c__60 = 60;
static integer c__61 = 61;
static integer c__70 = 70;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.02/14                        * */
/*  *    TEST TITLE : Effect of deleting structure networks * */
/*  *                 on element pointer                    * */
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
    extern /* Subroutine */ int ndsn (integer *, integer *), nsep (integer *),
	     endit_(void), nsedm (integer *), inmsg_(char *, ftnlen), nclst (
	    void), nexst (integer *), nopst (integer *), chkelp_(integer *), 
	    initgl_(char *, ftnlen), setmsg_(char *, char *, ftnlen, ftnlen), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndsn (), nsep (), endit_(), nsedm (), inmsg_()
	    , nclst (), nexst (), nopst (), chkelp_(), initgl_(), setmsg_(), 
	    xpopph_();
#endif /* NO_PROTO */

/* reference handling flag */
/* edit mode */
    initgl_("02.01.02.02/14", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Set up CSS as: */

/*                                 40 */
/*                                  |       50 */
/*                               D:41      /  \ */
/*                                  |     /    \ */
/*                                 42   100   D:51 */
/*                                  |  / |\    / | */
/*                                 43 /  | \4 /  | */
/*      20                          |/3  |  511  | */
/*     /  \                        44    |       | */
/*    /    \                             |       | */
/*  21    D:22   -----------------------/ \     / */
/*         /  \ 1|       2|            /   \6  / */
/*        /    \ |        |  D:60     /     \ / */
/*       /      \|      D:30    \    /\     512 */
/*     221      222       / \    \ 5/  \7    | */
/*               |       /   \    \/    \    | */
/*               |     31     32  61    70  5121 */
/*              2221 */


/*  The nodes of the graph (20 and above) represent structures, and */
/*  the labelled edges are references to invoke (lower) structures. */
/*  The labels (1- 7) represent the element position of the <execute */
/*  structure> function within structure #100.  The structures that */
/*  are specified by <delete structure network> are prefaced by "D:". */
    nopst (&c__20);
    nexst (&c__21);
    nexst (&c__22);
    nclst ();
    nopst (&c__22);
    nexst (&c__221);
    nexst (&c__222);
    nclst ();
    nopst (&c__222);
    nexst (&c__2221);
    nclst ();
    nopst (&c__30);
    nexst (&c__31);
    nexst (&c__32);
    nclst ();
    nopst (&c__40);
    nexst (&c__41);
    nclst ();
    nopst (&c__41);
    nexst (&c__42);
    nclst ();
    nopst (&c__42);
    nexst (&c__43);
    nclst ();
    nopst (&c__43);
    nexst (&c__44);
    nclst ();
    nopst (&c__50);
    nexst (&c__100);
    nexst (&c__51);
    nclst ();
    nopst (&c__51);
    nexst (&c__511);
    nexst (&c__512);
    nclst ();
    nopst (&c__512);
    nexst (&c__5121);
    nclst ();
    nopst (&c__60);
    nexst (&c__61);
    nclst ();
    nopst (&c__100);
    nexst (&c__222);
    nexst (&c__30);
    nexst (&c__44);
    nexst (&c__511);
    nexst (&c__61);
    nexst (&c__512);
    nexst (&c__70);
/*  Structure 100 is left open. */

/*  Throughout, the expected state is shown as the sequence of */
/*  references within structure #100, with the current element */
/*  marked by an asterisk.  Thus the first state is: */

/*     (222, 30*, 44, 511, 61, 512, 70) */
    nsedm (&c__1);
    inmsg_("Following test cases run in REPLACE mode.", 41L);
/*  set element pointer to 2 and delete structure network #30 */
    nsep (&c__2);
    ndsn (&c__30, &c__0);
#ifndef NO_PROTO
    setmsg_("12", "When <delete structure network> causes deletion of refere"
	    "nces at the current element, the element pointer should be chang"
	    "ed so as to point to the preceding element.", 2L, 164L);
#else /* NO_PROTO */
    setmsg_("12", "When <delete structure network> causes deletion of refere\
nces at the current element, the element pointer should be changed so as to \
point to the preceding element.", 2L, 164L);
#endif /* NO_PROTO */
    chkelp_(&c__1);
/*  (222*, 44, 511, 61, 512, 70) */
/*  delete structure network #22 */
    ndsn (&c__22, &c__0);
#ifndef NO_PROTO
    setmsg_("12", "When <delete structure network> causes deletion of refere"
	    "nces at the current element, the element pointer should be chang"
	    "ed to zero when there is no preceding element.", 2L, 167L);
#else /* NO_PROTO */
    setmsg_("12", "When <delete structure network> causes deletion of refere\
nces at the current element, the element pointer should be changed to zero w\
hen there is no preceding element.", 2L, 167L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
/*  (* 44, 511, 61, 512, 70) */
    nsedm (&c__0);
    inmsg_("Following test cases run in INSERT mode.", 40L);
/*  delete structure network #41 */
    ndsn (&c__41, &c__0);
#ifndef NO_PROTO
    setmsg_("11", "When <delete structure network> causes deletion of refere"
	    "nces following the current element, the element pointer should b"
	    "e unchanged.", 2L, 133L);
#else /* NO_PROTO */
    setmsg_("11", "When <delete structure network> causes deletion of refere\
nces following the current element, the element pointer should be unchanged.",
	     2L, 133L);
#endif /* NO_PROTO */
    chkelp_(&c__0);
/*  (* 511, 61, 512, 70) */
/*  set element pointer to 2 and delete structure network #51 */
    nsep (&c__2);
    ndsn (&c__51, &c__0);
#ifndef NO_PROTO
    setmsg_("11", "When <delete structure network> causes deletion of refere"
	    "nces surrounding the current element, the element pointer should"
	    " be changed so as to point to the same element.", 2L, 168L);
#else /* NO_PROTO */
    setmsg_("11", "When <delete structure network> causes deletion of refere\
nces surrounding the current element, the element pointer should be changed \
so as to point to the same element.", 2L, 168L);
#endif /* NO_PROTO */
    chkelp_(&c__1);
/*  (61*, 70) */
/*  set element pointer to 2 */
/*  delete structure network #60, ref-flag = KEEP */
    nsep (&c__2);
    ndsn (&c__60, &c__1);
#ifndef NO_PROTO
    setmsg_("11", "When <delete structure network> does not cause deletion o"
	    "f a reference in the open structure because the reference flag i"
	    "s KEEP, the element pointer should be unchanged.", 2L, 169L);
#else /* NO_PROTO */
    setmsg_("11", "When <delete structure network> does not cause deletion o\
f a reference in the open structure because the reference flag is KEEP, the \
element pointer should be unchanged.", 2L, 169L);
#endif /* NO_PROTO */
    chkelp_(&c__2);
/*  (61, 70*) */
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

