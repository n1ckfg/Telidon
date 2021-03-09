/* fort/02/01/02/02/p10.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.01.02.02/10                        * */
/*  *    TEST TITLE : Deletion of a structure network with  * */
/*  *                 the reference flag set to keep and    * */
/*  *                 references are made to the open       * */
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
    initgl_("02.01.02.02/10", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    delcss_();
#ifndef NO_PROTO
    setmsg_("5 7 8", "When the reference handling flag is set to keep and th"
	    "e open specified structure is referenced outside the structure n"
	    "etwork the following changes should occur to the CSS: All closed"
	    " non-specified structures all of whose maximal ancestor paths co"
	    "ntain the specified structure are removed. The specified structu"
	    "re is OPEN and EMPTY. All non-specified structures one of whose "
	    "maximal ancestor paths does not contain the specified structure "
	    "remain AS IS.", 5L, 451L);
#else /* NO_PROTO */
    setmsg_("5 7 8", "When the reference handling flag is set to keep and th\
e open specified structure is referenced outside the structure network the f\
ollowing changes should occur to the CSS: All closed non-specified structure\
s all of whose maximal ancestor paths contain the specified structure are re\
moved. The specified structure is OPEN and EMPTY. All non-specified structur\
es one of whose maximal ancestor paths does not contain the specified struct\
ure remain AS IS.", 5L, 451L);
#endif /* NO_PROTO */
/* specf = open specified structure (and posted specified structure) */
    specf = 102;
    reffg = 1;
    nopst (&specf);
    npost (&globnu_1.wkid, &specf, &c_b4);
    ndsn (&specf, &reffg);
#ifndef NO_PROTO
    L__1 = csseq_("100, 1, 101, 1, 103, 0/100, 1, 101, 2, 103, 0/102, 0/120,"
	    " 1, 106, 1, 108, 1, 111, 1, 114, 0/120, 1, 106, 1, 108, 1, 111, "
	    "2, 115, 0/130, 1, 106, 1, 108, 1, 111, 1, 114, 0/130, 1, 106, 1,"
	    " 108, 1, 111, 2, 115, 0/130, 2, 107, 1, 108, 1, 111, 1, 114, 0/1"
	    "30, 2, 107, 1, 108, 1, 111, 2, 115, 0/130, 2, 107, 2, 108, 1, 11"
	    "1, 1, 114, 0/130, 2, 107, 2, 108, 1, 111, 2, 115, 0/130, 2, 107,"
	    " 3, 113, 0/140, 1, 142, 0/", 403L);
#else /* NO_PROTO */
    L__1 = csseq_("100, 1, 101, 1, 103, 0/100, 1, 101, 2, 103, 0/102, 0/120,\
 1, 106, 1, 108, 1, 111, 1, 114, 0/120, 1, 106, 1, 108, 1, 111, 2, 115, 0/13\
0, 1, 106, 1, 108, 1, 111, 1, 114, 0/130, 1, 106, 1, 108, 1, 111, 2, 115, 0/\
130, 2, 107, 1, 108, 1, 111, 1, 114, 0/130, 2, 107, 1, 108, 1, 111, 2, 115, \
0/130, 2, 107, 2, 108, 1, 111, 1, 114, 0/130, 2, 107, 2, 108, 1, 111, 2, 115\
, 0/130, 2, 107, 3, 113, 0/140, 1, 142, 0/", 403L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("5", "<Delete structure network> with the reference flag set to "
	    "keep and an open specified structure which is referenced outside"
	    " the structure network should cause that structure to exist in t"
	    "he CSS as an open structure.", 1L, 214L);
#else /* NO_PROTO */
    setmsg_("5", "<Delete structure network> with the reference flag set to \
keep and an open specified structure which is referenced outside the structu\
re network should cause that structure to exist in the CSS as an open struct\
ure.", 1L, 214L);
#endif /* NO_PROTO */
/* use <inquire open structure to determine */
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
    setmsg_("5", "<Delete structure network> with the reference flag set to "
	    "keep and an open specified structure which is referenced outside"
	    " the structure network should cause that structure to exist in t"
	    "he CSS as an empty structure.", 1L, 215L);
#else /* NO_PROTO */
    setmsg_("5", "<Delete structure network> with the reference flag set to \
keep and an open specified structure which is referenced outside the structu\
re network should cause that structure to exist in the CSS as an empty struc\
ture.", 1L, 215L);
#endif /* NO_PROTO */
/* use <inquire structure status> on specified structure to determine */
/* strsti = structure status identifier */
    nqstst (&specf, &errind, &strsti);
    chkinq_("pqstst", &errind, 6L);
    L__1 = strsti == 1;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("10", "<Delete structure network> should cause the open specifie"
	    "d structure referenced outside the structure network to become u"
	    "nposted from the workstation when the reference handling flag is"
	    " set to keep.", 2L, 198L);
#else /* NO_PROTO */
    setmsg_("10", "<Delete structure network> should cause the open specifie\
d structure referenced outside the structure network to become unposted from\
 the workstation when the reference handling flag is set to keep.", 2L, 198L);

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

