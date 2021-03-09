/* fort/03/03/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__104 = 104;
static integer c__102 = 102;
static integer c__101 = 101;
static integer c__3 = 3;
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.03/06                              * */
/*  *    TEST TITLE : Retrieving open structure             * */
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
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndas ();
#endif /* NO_PROTO */
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nresn (integer *, integer *, 
	    integer *), nrast (integer *), nrest (integer *, integer *, 
	    integer *), setvs_(char *, integer *, integer *, ftnlen), nopst (
	    integer *), nclarf (integer *), ndasar (integer *), initgl_(char *
	    , ftnlen), avarnm_(integer *), noparf (integer *, integer *), 
	    narast (integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    errctl_(logical *), retopn_(integer *, integer *, char *, ftnlen),
	     nscnrs (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nresn (), nrast (), nrest (), 
	    setvs_(), nopst (), nclarf (), ndasar (), initgl_(), avarnm_(), 
	    noparf (), narast (), setmsg_(), errctl_(), retopn_(), nscnrs ();
#endif /* NO_PROTO */
    static integer spcsiz, spcstr[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setstr_(
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setstr_();
#endif /* NO_PROTO */

/* conflict resolution */
/*                maintain    abandon     update */
    initgl_("03.03/06", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  open new archive file, with arid = archive identifier */
    avarnm_(&arnm);
    arid = 6;
    noparf (&arid, &arnm);
/*  set retrieval conflict resolution flag = UPDATE */
    nscnrs (&c__1, &c__2);
/*  set up structures: */
/*     archive : 102-A, 104-A (3 elements), with 102-A invoking 104-A */
/*     CSS     : 101-C, 104-C (4 elements) */
    ndas ();
    setstr_(&c__104, "L911,L912,L913", 14L);
    setstr_(&c__102, "E104", 4L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "L931", 4L);
    setstr_(&c__104, "L931,L932,L933,L934", 19L);
/*  <open structure> 104 */
    nopst (&c__104);
/*  <retrieve all structures> */
    nrast (&arid);
#ifndef NO_PROTO
    setmsg_("11 16 18", "When <retrieve all structures> causes a structure i"
	    "n the archive to replace the open CSS structure, the structure s"
	    "hould remain open, with the element pointer indicating the last "
	    "element.", 8L, 187L);
#else /* NO_PROTO */
    setmsg_("11 16 18", "When <retrieve all structures> causes a structure i\
n the archive to replace the open CSS structure, the structure should remain\
 open, with the element pointer indicating the last element.", 8L, 187L);
#endif /* NO_PROTO */
/*  pass/fail depending on (104-A is open structure and */
/*                          element pointer = 3) */
    retopn_(&c__104, &c__3, "67,911,67,912,67,913", 20L);
/*  set up structures: */
/*     CSS     : 101-C, 104-C (4 elements) */
    ndas ();
    setstr_(&c__101, "L931", 4L);
    setstr_(&c__104, "L931,L932,L933,L934", 19L);
/*  <open structure> 101 */
    nopst (&c__101);
/*  <retrieve structures> 102, 101 */
    setvs_("102,101", spcstr, &spcsiz, 7L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nrest (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
    setmsg_("9 17 18", "When <retrieve structures> specifies a non-existent "
	    "archive structure to replace the open CSS structure, the structu"
	    "re should become empty but remain open, with the element pointer"
	    " indicating zero.", 7L, 197L);
#else /* NO_PROTO */
    errctl_(&c__0);
    setmsg_("9 17 18", "When <retrieve structures> specifies a non-existent \
archive structure to replace the open CSS structure, the structure should be\
come empty but remain open, with the element pointer indicating zero.", 7L, 
	    197L);
#endif /* NO_PROTO */
/*  pass/fail depending on (101-E is open structure and */
/*                          element pointer = 0) */
    retopn_(&c__101, &c__0, " ", 1L);
/*  set up structures: */
/*     CSS     : 101-C, 104-C (2 elements) */
    ndas ();
    setstr_(&c__101, "L931", 4L);
    setstr_(&c__104, "L931,L932", 9L);
/*  <open structure> 104 */
    nopst (&c__104);
/*  <retrieve structure networks> 102 */
    setvs_("102", spcstr, &spcsiz, 3L);
    nresn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("10 16 18", "When <retrieve structure networks> causes an implic"
	    "itly specified structure in the archive to replace the open CSS "
	    "structure, the structure should remain open, with the element po"
	    "inter indicating the last element.", 8L, 213L);
#else /* NO_PROTO */
    setmsg_("10 16 18", "When <retrieve structure networks> causes an implic\
itly specified structure in the archive to replace the open CSS structure, t\
he structure should remain open, with the element pointer indicating the las\
t element.", 8L, 213L);
#endif /* NO_PROTO */
/*  pass/fail depending on (104-A is open structure and */
/*                          element pointer = 3) */
    retopn_(&c__104, &c__3, "67,911,67,912,67,913", 20L);
/* L666: */
/* close archive and PHIGS */
    nclarf (&arid);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

