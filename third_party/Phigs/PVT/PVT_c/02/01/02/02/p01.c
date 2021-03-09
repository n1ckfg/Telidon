/* fort/02/01/02/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__103 = 103;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__106 = 106;
static integer c__102 = 102;
static integer c__109 = 109;
static integer c__107 = 107;
static integer c__108 = 108;
static integer c__110 = 110;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.02/01                        * */
/*  *    TEST TITLE : Deletion of a structure network using * */
/*  *                 a non-existent structure identifier   * */
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
    extern /* Subroutine */ int ifpf_(logical *), ndsn (integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndsn ();
#endif /* NO_PROTO */
    static integer reffg;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical csseq_(char *, ftnlen);
    extern /* Subroutine */ int nclst (void), nexst (integer *), nopst (
	    integer *), initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical csseq_();
    extern /* Subroutine */ int nclst (), nexst (), nopst (), initgl_();
#endif /* NO_PROTO */
    static integer nostid;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), xpopph_();
#endif /* NO_PROTO */

/* PHIGS parameter type for reference handling flag */
/* PHIGS paramter types */
    initgl_("02.01.02.02/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* creation of a structure network */
    nopst (&c__100);
    nexst (&c__103);
    nexst (&c__104);
    nclst ();
    nopst (&c__103);
    nexst (&c__105);
    nexst (&c__105);
    nclst ();
    nopst (&c__104);
    nexst (&c__106);
    nclst ();
    nopst (&c__102);
    nexst (&c__106);
    nexst (&c__109);
    nclst ();
    nopst (&c__106);
    nexst (&c__107);
    nexst (&c__108);
    nclst ();
    nopst (&c__109);
    nexst (&c__108);
    nexst (&c__110);
    nclst ();
#ifndef NO_PROTO
    setmsg_("9", "<Delete structure network> with a non-existent structure i"
	    "dentifier and the reference handling flag set to delete should h"
	    "ave no effect on the contents of the CSS.", 1L, 163L);
#else /* NO_PROTO */
    setmsg_("9", "<Delete structure network> with a non-existent structure i\
dentifier and the reference handling flag set to delete should have no effec\
t on the contents of the CSS.", 1L, 163L);
#endif /* NO_PROTO */
/* nostid = non-existent structure identifier */
    nostid = 25;
    reffg = 0;
    ndsn (&nostid, &reffg);
#ifndef NO_PROTO
    L__1 = csseq_("100, 1, 103, 1, 105, 0/100, 1, 103, 2, 105, 0/100, 2, 104"
	    ", 1, 106, 1, 107, 0/100, 2, 104, 1, 106, 2, 108, 0/102, 1, 106, "
	    "1, 107, 0/102, 1, 106, 2, 108, 0/102, 2, 109, 1, 108, 0/102, 2, "
	    "109, 2, 110, 0/", 200L);
#else /* NO_PROTO */
    L__1 = csseq_("100, 1, 103, 1, 105, 0/100, 1, 103, 2, 105, 0/100, 2, 104\
, 1, 106, 1, 107, 0/100, 2, 104, 1, 106, 2, 108, 0/102, 1, 106, 1, 107, 0/10\
2, 1, 106, 2, 108, 0/102, 2, 109, 1, 108, 0/102, 2, 109, 2, 110, 0/", 200L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("9", "<Delete structure network> with a non-existent structure i"
	    "dentifier and the reference handling flag set to keep should hav"
	    "e no effect on the contents of the CSS.", 1L, 161L);
#else /* NO_PROTO */
    setmsg_("9", "<Delete structure network> with a non-existent structure i\
dentifier and the reference handling flag set to keep should have no effect \
on the contents of the CSS.", 1L, 161L);
#endif /* NO_PROTO */
    nostid = 40;
    reffg = 1;
    ndsn (&nostid, &reffg);
#ifndef NO_PROTO
    L__1 = csseq_("100, 1, 103, 1, 105, 0/100, 1, 103, 2, 105, 0/100, 2, 104"
	    ", 1, 106, 1, 107, 0/100, 2, 104, 1, 106, 2, 108, 0/102, 1, 106, "
	    "1, 107, 0/102, 1, 106, 2, 108, 0/102, 2, 109, 1, 108, 0/102, 2, "
	    "109, 2, 110, 0/", 200L);
#else /* NO_PROTO */
    L__1 = csseq_("100, 1, 103, 1, 105, 0/100, 1, 103, 2, 105, 0/100, 2, 104\
, 1, 106, 1, 107, 0/100, 2, 104, 1, 106, 2, 108, 0/102, 1, 106, 1, 107, 0/10\
2, 1, 106, 2, 108, 0/102, 2, 109, 1, 108, 0/102, 2, 109, 2, 110, 0/", 200L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

