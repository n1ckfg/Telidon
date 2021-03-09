/* fort/02/01/03/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 02.01.03.02/01                        * */
/*  *    TEST TITLE : <Change structure references> where   * */
/*  *                 no changes occur to the CSS           * */
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
    initgl_("02.01.03.02/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("2", "<Change structure references> when the original structure "
	    "is non-existent and the resulting structure exists and is not re"
	    "ferenced should have no effect on the contents of the CSS.", 1L, 
	    180L);
#else /* NO_PROTO */
    setmsg_("2", "<Change structure references> when the original structure \
is non-existent and the resulting structure exists and is not referenced sho\
uld have no effect on the contents of the CSS.", 1L, 180L);
#endif /* NO_PROTO */
    stdcss_();
    orgid = 300;
    resid = 120;
    ncstrf (&orgid, &resid);
#ifndef NO_PROTO
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,2,"
	    " 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0/10"
	    "0,2, 102,2, 105,3, 114,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "   ", 700L);
#else /* NO_PROTO */
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,2, 108,2, 111,\
1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0/100,2, 102,2, 105,3, 114,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                   ", 700L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2", "<Change structure references> when the original structure "
	    "exists and is not referenced and the resulting structure exists "
	    "and is referenced should have no effect on the contents of the C"
	    "SS.", 1L, 189L);
#else /* NO_PROTO */
    setmsg_("2", "<Change structure references> when the original structure \
exists and is not referenced and the resulting structure exists and is refer\
enced should have no effect on the contents of the CSS.", 1L, 189L);
#endif /* NO_PROTO */
    stdcss_();
    orgid = 130;
    resid = 103;
    ncstrf (&orgid, &resid);
#ifndef NO_PROTO
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,2,"
	    " 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0/10"
	    "0,2, 102,2, 105,3, 114,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "   ", 700L);
#else /* NO_PROTO */
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,2, 108,2, 111,\
1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0/100,2, 102,2, 105,3, 114,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                   ", 700L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2", "<Change structure references> when the original structure "
	    "and resulting structure are non-existent should have no effect o"
	    "n the contents of the CSS.", 1L, 148L);
#else /* NO_PROTO */
    setmsg_("2", "<Change structure references> when the original structure \
and resulting structure are non-existent should have no effect on the conten\
ts of the CSS.", 1L, 148L);
#endif /* NO_PROTO */
    stdcss_();
    orgid = 300;
    resid = 320;
    ncstrf (&orgid, &resid);
#ifndef NO_PROTO
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,2,"
	    " 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0/10"
	    "0,2, 102,2, 105,3, 114,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "   ", 700L);
#else /* NO_PROTO */
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,2, 108,2, 111,\
1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0/100,2, 102,2, 105,3, 114,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                   ", 700L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("3", "<Change structure references> when the original structure "
	    "identifier and resulting identifier are the same and the common "
	    "structure exists and is referenced should have no effect on the "
	    "contents of the CSS.", 1L, 206L);
#else /* NO_PROTO */
    setmsg_("3", "<Change structure references> when the original structure \
identifier and resulting identifier are the same and the common structure ex\
ists and is referenced should have no effect on the contents of the CSS.", 1L,
	     206L);
#endif /* NO_PROTO */
    stdcss_();
    orgid = 107;
    resid = 107;
    ncstrf (&orgid, &resid);
#ifndef NO_PROTO
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102"
	    ",1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,2,"
	    " 108,2, 111,1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0/10"
	    "0,2, 102,2, 105,3, 114,0/100,2, 102,5, 106,1, 108,2, 111,1, 114,"
	    "0/100,2, 102,5, 106,1, 108,2, 111,3, 115,0/120,2, 106,1, 108,2, "
	    "111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/130,3, 106,1, 108"
	    ",2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 107,1,"
	    " 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 10"
	    "7,4, 108,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5"
	    ", 107,5, 113,0/140,1, 142,0/                                    "
	    "                                                                "
	    "   ", 700L);
#else /* NO_PROTO */
    L__1 = csseq_("100,1, 101,2, 103,0/100,2, 102,1, 104,2, 109,0/100,2, 102\
,1, 104,5, 109,0/100,2, 102,2, 105,1, 110,0/100,2, 102,2, 105,2, 108,2, 111,\
1, 114,0/100,2, 102,2, 105,2, 108,2, 111,3, 115,0/100,2, 102,2, 105,3, 114,0\
/100,2, 102,5, 106,1, 108,2, 111,1, 114,0/100,2, 102,5, 106,1, 108,2, 111,3,\
 115,0/120,2, 106,1, 108,2, 111,1, 114,0/120,2, 106,1, 108,2, 111,3, 115,0/1\
30,3, 106,1, 108,2, 111,1, 114,0/130,3, 106,1, 108,2, 111,3, 115,0/130,5, 10\
7,1, 108,2, 111,1, 114,0/130,5, 107,1, 108,2, 111,3, 115,0/130,5, 107,4, 108\
,2, 111,1, 114,0/130,5, 107,4, 108,2, 111,3, 115,0/130,5, 107,5, 113,0/140,1\
, 142,0/                                                                    \
                                   ", 700L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

