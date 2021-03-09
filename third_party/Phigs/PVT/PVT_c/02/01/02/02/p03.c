/* fort/02/01/02/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.02/03                        * */
/*  *    TEST TITLE : Deletion of a structure network with  * */
/*  *                 the reference flag set to delete and  * */
/*  *                 references are not made to the closed * */
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
    extern /* Subroutine */ int ifpf_(logical *), ndsn (integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndsn ();
#endif /* NO_PROTO */
    static integer reffg, specf;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical csseq_(char *, ftnlen);
    extern /* Subroutine */ int delcss_(void), initgl_(char *, ftnlen), 
	    setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical csseq_();
    extern /* Subroutine */ int delcss_(), initgl_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */

/* PHIGS parameter type for reference handling flag */
/* PHIGS parameter types */
    initgl_("02.01.02.02/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    delcss_();
#ifndef NO_PROTO
    setmsg_("3 4", "When the reference handling flag is set to delete and th"
	    "e closed specified structure is not referenced outside the struc"
	    "ture network the following changes should occur to the CSS: All "
	    "closed structures contained in a structure network are removed.", 
	    3L, 247L);
#else /* NO_PROTO */
    setmsg_("3 4", "When the reference handling flag is set to delete and th\
e closed specified structure is not referenced outside the structure network\
 the following changes should occur to the CSS: All closed structures contai\
ned in a structure network are removed.", 3L, 247L);
#endif /* NO_PROTO */
/* specf = closed specified structure */
    specf = 120;
    reffg = 0;
    ndsn (&specf, &reffg);
#ifndef NO_PROTO
    L__1 = csseq_("100, 1, 101, 1, 103, 0/100, 1, 101, 2, 103, 0/100, 2, 102"
	    ", 1, 104, 1, 109, 0/100, 2, 102, 1, 104, 2, 109, 0/100, 2, 102, "
	    "2, 105, 1, 110, 0/130, 1, 107, 1, 113, 0/140, 1, 142, 0/", 177L);
#else /* NO_PROTO */
    L__1 = csseq_("100, 1, 101, 1, 103, 0/100, 1, 101, 2, 103, 0/100, 2, 102\
, 1, 104, 1, 109, 0/100, 2, 102, 1, 104, 2, 109, 0/100, 2, 102, 2, 105, 1, 1\
10, 0/130, 1, 107, 1, 113, 0/140, 1, 142, 0/", 177L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

