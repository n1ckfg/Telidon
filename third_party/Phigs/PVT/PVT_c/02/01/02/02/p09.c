/* fort/02/01/02/02/p09.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.01.02.02/09                        * */
/*  *    TEST TITLE : Deletion of a structure network with  * */
/*  *                 the reference flag set to keep and    * */
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

/* parameter for structure status */
/* PHIGS parameter types */
    initgl_("02.01.02.02/09", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    delcss_();
#ifndef NO_PROTO
    setmsg_("7 8", "When the reference handling flag is set to keep and the "
	    "closed specified structure is not referenced outside the structu"
	    "re network the following changes should occur to the CSS: All cl"
	    "osed network structures all of whose maximal ancestor paths cont"
	    "ain the specified structure are removed. All non-specified struc"
	    "tures one of whose maximal ancestor path does not contain the sp"
	    "ecified structure remain AS IS.", 3L, 407L);
#else /* NO_PROTO */
    setmsg_("7 8", "When the reference handling flag is set to keep and the \
closed specified structure is not referenced outside the structure network t\
he following changes should occur to the CSS: All closed network structures \
all of whose maximal ancestor paths contain the specified structure are remo\
ved. All non-specified structures one of whose maximal ancestor path does no\
t contain the specified structure remain AS IS.", 3L, 407L);
#endif /* NO_PROTO */
/* specf = open specified structure (and posted specfied structure) */
    specf = 100;
    reffg = 1;
    ndsn (&specf, &reffg);
#ifndef NO_PROTO
    L__1 = csseq_("120, 1, 106, 1, 108, 1, 111, 1, 114, 0/120, 1, 106, 1, 10"
	    "8, 1, 111, 2, 115, 0/130, 1, 106, 1, 108, 1, 111, 1, 114, 0/130,"
	    " 1, 106, 1, 108, 1, 111, 2, 115, 0/130, 2, 107, 1, 108, 1, 111, "
	    "1, 114, 0/130, 2, 107, 1, 108, 1, 111, 2, 115, 0/130, 2, 107, 2,"
	    " 108, 1, 111, 1, 114, 0/130, 2, 107, 2, 108, 1, 111, 2, 115, 0/1"
	    "30, 2, 107, 3, 113, 0/140, 1, 142, 0/", 350L);
#else /* NO_PROTO */
    L__1 = csseq_("120, 1, 106, 1, 108, 1, 111, 1, 114, 0/120, 1, 106, 1, 10\
8, 1, 111, 2, 115, 0/130, 1, 106, 1, 108, 1, 111, 1, 114, 0/130, 1, 106, 1, \
108, 1, 111, 2, 115, 0/130, 2, 107, 1, 108, 1, 111, 1, 114, 0/130, 2, 107, 1\
, 108, 1, 111, 2, 115, 0/130, 2, 107, 2, 108, 1, 111, 1, 114, 0/130, 2, 107,\
 2, 108, 1, 111, 2, 115, 0/130, 2, 107, 3, 113, 0/140, 1, 142, 0/", 350L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

