/* fort/02/01/03/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.01.03.02/02                        * */
/*  *    TEST TITLE : <Change structure references> where   * */
/*  *                 changes occur to the CSS              * */
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
    extern /* Subroutine */ int ifpf_(logical *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), endit_();
#endif /* NO_PROTO */
    static integer orgid, resid;
#ifndef NO_PROTO
    extern logical csseq_(char *, ftnlen);
    extern /* Subroutine */ int initgl_(char *, ftnlen), ncstrf (integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen), stdcss_(void)
	    , xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern logical csseq_();
    extern /* Subroutine */ int initgl_(), ncstrf (), setmsg_(), stdcss_(), 
	    xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
    initgl_("02.01.03.02/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1", "<Change structure references> when the original structure "
	    "is referenced and the resulting structure is not referenced shou"
	    "ld replace all execute structure elements which reference origin"
	    "al structure identifier with elements which reference resulting "
	    "structure identifier.", 1L, 271L);
#else /* NO_PROTO */
    setmsg_("1", "<Change structure references> when the original structure \
is referenced and the resulting structure is not referenced should replace a\
ll execute structure elements which reference original structure identifier \
with elements which reference resulting structure identifier.", 1L, 271L);
#endif /* NO_PROTO */
    stdcss_();
    orgid = 108;
    resid = 140;
    ncstrf (&orgid, &resid);
#ifndef NO_PROTO
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3,"
	    " 114,0/100,2, 102,2, 105,2, 140,1, 142,0/100,2, 102,5, 106,1, 14"
	    "0,1, 142,0/108,2, 111,1, 114,0/108,2, 111,3, 115,0/120,2, 106,1,"
	    " 140,1, 142,0/130,3, 106,1, 140,1, 142,0/130,5, 107,1, 140,1, 14"
	    "2,0/130,5, 107,4, 140,1, 142,0/130,5, 107,5, 113,0/", 364L);
#else /* NO_PROTO */
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2\
, 102,2, 105,2, 140,1, 142,0/100,2, 102,5, 106,1, 140,1, 142,0/108,2, 111,1,\
 114,0/108,2, 111,3, 115,0/120,2, 106,1, 140,1, 142,0/130,3, 106,1, 140,1, 1\
42,0/130,5, 107,1, 140,1, 142,0/130,5, 107,4, 140,1, 142,0/130,5, 107,5, 113\
,0/", 364L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 4", "When the original structure and resulting structure are "
	    "referenced then <change structure references> should cause the i"
	    "nitial references made to resulting structure to remain as is.", 
	    3L, 182L);
#else /* NO_PROTO */
    setmsg_("1 4", "When the original structure and resulting structure are \
referenced then <change structure references> should cause the initial refer\
ences made to resulting structure to remain as is.", 3L, 182L);
#endif /* NO_PROTO */
    stdcss_();
    orgid = 108;
    resid = 104;
    ncstrf (&orgid, &resid);
#ifndef NO_PROTO
    L__1 = csseq_("100,1, 101,2, 103,0/108,2, 111,1, 114,0/108,2, 111,3, 115"
	    ",0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2, "
	    "102,2, 105,2, 104,2, 109,0/100,2, 102,2, 105,2, 104,5, 109,0/100"
	    ",2, 102,1, 104,2, 109,0/100,2, 102,1, 104,5, 109,0/100,2, 102,5,"
	    " 106,1, 104,2, 109,0/100,2, 102,5, 106,1, 104,5, 109,0/120,2, 10"
	    "6,1, 104,2, 109,0/120,2, 106,1, 104,5, 109,0/130,3, 106,1, 104,2"
	    ", 109,0/130,3, 106,1, 104,5, 109,0/130,5, 107,1, 104,2, 109,0/13"
	    "0,5, 107,1, 104,5, 109,0/130,5, 107,4, 104,2, 109,0/130,5, 107,4"
	    ", 104,5, 109,0/130,5, 107,5, 113,0/ 140,1, 142,0/", 554L);
#else /* NO_PROTO */
    L__1 = csseq_("100,1, 101,2, 103,0/108,2, 111,1, 114,0/108,2, 111,3, 115\
,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,3, 114,0/100,2, 102,2, 105,2\
, 104,2, 109,0/100,2, 102,2, 105,2, 104,5, 109,0/100,2, 102,1, 104,2, 109,0/\
100,2, 102,1, 104,5, 109,0/100,2, 102,5, 106,1, 104,2, 109,0/100,2, 102,5, 1\
06,1, 104,5, 109,0/120,2, 106,1, 104,2, 109,0/120,2, 106,1, 104,5, 109,0/130\
,3, 106,1, 104,2, 109,0/130,3, 106,1, 104,5, 109,0/130,5, 107,1, 104,2, 109,\
0/130,5, 107,1, 104,5, 109,0/130,5, 107,4, 104,2, 109,0/130,5, 107,4, 104,5,\
 109,0/130,5, 107,5, 113,0/ 140,1, 142,0/", 554L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

