/* fort/02/01/02/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

#ifndef NO_PROTO
static real c_b4 = 0.f;
#else /* NO_PROTO */
static real c_b4 = (float)0.;
#endif /* NO_PROTO */
static integer c__0 = 0;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.02/05                        * */
/*  *    TEST TITLE : Deletion of a structure network with  * */
/*  *                 the reference flag set to delete and  * */
/*  *                 references are not made to the open   * */
/*  *                 specified structure                   * */
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
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), ndsn (integer *
	    , integer *), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), ndsn (), pass_();
#endif /* NO_PROTO */
    static integer idum1;
    static real rdum1;
    static integer reffg, specf;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical csseq_(char *, ftnlen);
    extern /* Subroutine */ int nclst (void), nopwk (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical csseq_();
    extern /* Subroutine */ int nclst (), nopwk ();
#endif /* NO_PROTO */
    static integer stype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), npost (integer *, integer *
	    , real *), delcss_(void), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), npost (), delcss_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer strref;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer pstnum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst ();
#endif /* NO_PROTO */
    static integer strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpost (integer *, integer *, integer *, 
	    integer *, integer *, real *), nqstst (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpost (), nqstst ();
#endif /* NO_PROTO */

/* parameter for structure status, reference flag, structure empty */
/* PHIGS parameter types */
    initgl_("02.01.02.02/05", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    delcss_();
#ifndef NO_PROTO
    setmsg_("1 3 4", "When the reference handling flag is set to delete and "
	    "the open specified structure is not referenced outside the struc"
	    "ture network the following changes should occur to the CSS: All "
	    "closed structures contained in a structure network are removed. "
	    "The specified structure is OPEN and EMPTY.", 5L, 288L);
#else /* NO_PROTO */
    setmsg_("1 3 4", "When the reference handling flag is set to delete and \
the open specified structure is not referenced outside the structure network\
 the following changes should occur to the CSS: All closed structures contai\
ned in a structure network are removed. The specified structure is OPEN and \
EMPTY.", 5L, 288L);
#endif /* NO_PROTO */
/* specf = open specified structure (and posted specified structure) */
    specf = 120;
    reffg = 0;
    nopst (&specf);
    npost (&globnu_1.wkid, &specf, &c_b4);
    ndsn (&specf, &reffg);
#ifndef NO_PROTO
    L__1 = csseq_("100, 1, 101, 1, 103, 0/100, 1, 101, 2, 103, 0/100, 2, 102"
	    ", 1, 104, 1, 109, 0/100, 2, 102, 1, 104, 2, 109, 0/100, 2, 102, "
	    "2, 105, 1, 110, 0/120, 0/130, 1, 107, 1, 113, 0/140, 1, 142, 0/", 
	    184L);
#else /* NO_PROTO */
    L__1 = csseq_("100, 1, 101, 1, 103, 0/100, 1, 101, 2, 103, 0/100, 2, 102\
, 1, 104, 1, 109, 0/100, 2, 102, 1, 104, 2, 109, 0/100, 2, 102, 2, 105, 1, 1\
10, 0/120, 0/130, 1, 107, 1, 113, 0/140, 1, 142, 0/", 184L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1", "<Delete structure network> with the reference flag set to "
	    "delete and an open specified structure which is not referenced o"
	    "utside the structure network should cause that structure to exis"
	    "t in the CSS as an open structure.", 1L, 220L);
#else /* NO_PROTO */
    setmsg_("1", "<Delete structure network> with the reference flag set to \
delete and an open specified structure which is not referenced outside the s\
tructure network should cause that structure to exist in the CSS as an open \
structure.", 1L, 220L);
#endif /* NO_PROTO */
/* use <inquire open structure> to determine */
/* stype  = the structure status open or close */
/* strref = structure id */
    nqopst (&errind, &stype, &strref);
    chkinq_("pqopst", &errind, 6L);
    if (stype == 1 && specf == strref) {
	pass_();
	nclst ();
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("1", "<Delete structure network> with the reference flag set to "
	    "delete and an open specified structure which is not referenced o"
	    "utside the structure network should cause that structure to exis"
	    "t in the CSS as an empty structure.", 1L, 221L);
#else /* NO_PROTO */
    setmsg_("1", "<Delete structure network> with the reference flag set to \
delete and an open specified structure which is not referenced outside the s\
tructure network should cause that structure to exist in the CSS as an empty\
 structure.", 1L, 221L);
#endif /* NO_PROTO */
/* use <inquire structure status> on specified structure to determine */
/* strsti = structure status identifier */
    nqstst (&specf, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10", "<Delete structure network> should cause the open specifie"
	    "d structure not referenced outside the structure network to beco"
	    "me unposted from the workstation when the reference handling fla"
	    "g is set to delete.", 2L, 204L);
#else /* NO_PROTO */
    setmsg_("10", "<Delete structure network> should cause the open specifie\
d structure not referenced outside the structure network to become unposted \
from the workstation when the reference handling flag is set to delete.", 2L, 
	    204L);
#endif /* NO_PROTO */
/* use <inquire posted structures> to determine */
/* pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__0, &errind, &pstnum, &idum1, &rdum1);
    chkinq_("pqpost", &errind, 6L);
    L__1 = pstnum == 0;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

