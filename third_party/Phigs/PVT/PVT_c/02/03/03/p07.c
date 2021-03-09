/* fort/02/03/03/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.03/07                           * */
/*  *    TEST TITLE : ISS and filters                       * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static char digch[1*9] = "1" "2" "3" "4" "5" "6" "7" "8" "9";
#else /* NO_PROTO */
    static char digch[1*9+1] = "123456789";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[3], a__2[2];
    integer i__1, i__2[3], i__3[2];
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer n;
    static real xp[5], yp[5], zp[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 ();
#endif /* NO_PROTO */
    static char ifil[900];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nads (integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nads ();
#endif /* NO_PROTO */
    static char nfil[900];
    static integer iptr, nptr, idum1, idum2, idum3, idum4, idum5;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer inval;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqphf (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqphf ();
#endif /* NO_PROTO */
    static integer mxifl, mxnfl;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nexst (integer *), setvs_(char *
	    , integer *, integer *, ftnlen), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst (), setvs_(), nopst ();
#endif /* NO_PROTO */
    static integer namlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, namset[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), issflt_(char *, char *, char *, char *, 
	    ftnlen, ftnlen, ftnlen, ftnlen), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), issflt_(), xpopph_();
#endif /* NO_PROTO */
    static integer mxitst, mxntst;

    initgl_("02.03.03/07", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Structure #101: */
/*  1. add names to set: 3,4,5 */
/*  2. execute structure 102 */
    nopst (&c__101);
    setvs_("3,4,5", namset, &namlen, 5L);
    nads (&namlen, namset);
    nexst (&c__102);
    nclst ();
/*  Structure #102: */
/*  1. polymarker at 1,2,3 */
#ifndef NO_PROTO
    xp[0] = 1.f;
    yp[0] = 2.f;
    zp[0] = 3.f;
#else /* NO_PROTO */
    xp[0] = (float)1.;
    yp[0] = (float)2.;
    zp[0] = (float)3.;
#endif /* NO_PROTO */
    nopst (&c__102);
    npm3 (&c__1, xp, yp, zp);
    nclst ();
/*  Throughout, keep fixed for ISS: */
/*  SRP = 1,2,3 */
/*  search distance = 0.1 */
/*  search ceiling = 1 */
/*  clipping flag = OFF */

/*  *** *** *** ***   One normal and inverted filter   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if"
	    " its non-null nameset is accepted by a single non-null normal fi"
	    "lter and rejected by a single non-null inverted filter.", 19L, 
	    159L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if\
 its non-null nameset is accepted by a single non-null normal filter and rej\
ected by a single non-null inverted filter.", 19L, 159L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   incl: 5,6,7; excl: 8,9 */
/*    inverted filter = incl: 1,2;   excl: 8,9 */

/*  pass/fail depending on (found path = 101,2, 102,1) */
    issflt_("101,1", "5,6,7 / 8,9 /", "1,2 / 8,9 /", "101,2, 102,1", 5L, 13L, 
	    11L, 12L);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun"
	    "d if its non-null nameset is rejected by a single non-null norma"
	    "l filter and also by a single non-null inverted filter.", 19L, 
	    159L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun\
d if its non-null nameset is rejected by a single non-null normal filter and\
 also by a single non-null inverted filter.", 19L, 159L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   incl: 5,6,7; excl: 3,8,9 */
/*    inverted filter = incl: 1,2;   excl: 8,9 */

/*  pass/fail depending on (found path = empty) */
    issflt_("101,1", "5,6,7 / 3,8,9 /", "1,2 / 8,9 /", " ", 5L, 15L, 11L, 1L);

#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun"
	    "d if its non-null nameset is accepted by a single non-null norma"
	    "l filter but also by a single non-null inverted filter.", 19L, 
	    159L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun\
d if its non-null nameset is accepted by a single non-null normal filter but\
 also by a single non-null inverted filter.", 19L, 159L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   incl: 4,6,7; excl: 9,1 */
/*    inverted filter = incl: 3;     excl: 8,9 */

/*  pass/fail depending on (found path = empty) */
    issflt_("101,1", "4,6,7 / 9,1 /", "3 / 8,9 /", " ", 5L, 13L, 9L, 1L);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun"
	    "d if its non-null nameset is rejected by a single non-null norma"
	    "l filter and accepted by a single non-null inverted filter.", 19L,
	     163L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun\
d if its non-null nameset is rejected by a single non-null normal filter and\
 accepted by a single non-null inverted filter.", 19L, 163L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   incl: 6,7;  excl: 9,1,3 */
/*    inverted filter = incl: 11,3; excl: 8,9 */

/*  pass/fail depending on (found path = empty) */
    issflt_("101,1", "6,7 / 9,1,3 /", "11,3 / 8,9 /", " ", 5L, 13L, 12L, 1L);
/* *** *** ***   One normal or inverted filter, but not both   *** *** **
**/
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if"
	    " its non-null nameset is accepted by a single non-null normal fi"
	    "lter and there are no inverted filters.", 19L, 143L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if\
 its non-null nameset is accepted by a single non-null normal filter and the\
re are no inverted filters.", 19L, 143L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   incl: 5,6,7; excl: 8,9 */
/*    inverted filter = none */

/*  pass/fail depending on (found path = 101,2, 102,1) */
    issflt_("101,1", "5,6,7 / 8,9 /", " ", "101,2, 102,1", 5L, 13L, 1L, 12L);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun"
	    "d if its non-null nameset is rejected by a single non-null norma"
	    "l filter and there are no inverted filters.", 19L, 147L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun\
d if its non-null nameset is rejected by a single non-null normal filter and\
 there are no inverted filters.", 19L, 147L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   incl: 2,6,7; excl: 8,9 */
/*    inverted filter = none */

/*  pass/fail depending on (found path = empty) */
    issflt_("101,1", "2,6,7 / 8,9 /", " ", " ", 5L, 13L, 1L, 1L);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun"
	    "d if its non-null nameset is accepted by a single non-null inver"
	    "ted filter and there are no normal filters.", 19L, 147L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun\
d if its non-null nameset is accepted by a single non-null inverted filter a\
nd there are no normal filters.", 19L, 147L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   none */
/*    inverted filter = incl: 2,6,4,7; excl: 8,9 */

/*  pass/fail depending on (found path = empty) */
    issflt_("101,1", " ", "2,6,4,7 / 8,9 /", " ", 5L, 1L, 15L, 1L);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if"
	    " its non-null nameset is rejected by a single non-null inverted "
	    "filter and there are no normal filters.", 19L, 143L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if\
 its non-null nameset is rejected by a single non-null inverted filter and t\
here are no normal filters.", 19L, 143L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   none */
/*    inverted filter = incl: empty; excl: 8,9 */

/*  pass/fail depending on (found path = 101,2, 102,1) */
    issflt_("101,1", " ", "  / 8,9 /", "101,2, 102,1", 5L, 1L, 9L, 12L);
/*  *** *** ***   No filters   *** *** *** */
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if"
	    " its nameset is non-null and there is no normal or inverted filt"
	    "er.", 19L, 107L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if\
 its nameset is non-null and there is no normal or inverted filter.", 19L, 
	    107L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   none */
/*    inverted filter = none */

/*  pass/fail depending on (found path = 101,2, 102,1) */
    issflt_("101,1", " ", " ", "101,2, 102,1", 5L, 1L, 1L, 12L);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if"
	    " its nameset is null and there is no normal or inverted filter.", 
	    19L, 103L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if\
 its nameset is null and there is no normal or inverted filter.", 19L, 103L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   102,0 */
/*    normal filter =   none */
/*    inverted filter = none */

/*  pass/fail depending on (found path = 102,1) */
    issflt_("102,0", " ", " ", "102,1", 5L, 1L, 1L, 5L);
/*  *** *** *** ***   Null nameset   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun"
	    "d if its nameset is null and there is at least one normal filter."
	    , 19L, 105L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun\
d if its nameset is null and there is at least one normal filter.", 19L, 105L)
	    ;
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   102,0 */
/*    normal filter =   incl: empty; excl: 1,2 */
/*    inverted filter = incl: 11,3;  excl: 8,9,4 */

/*  pass/fail depending on (found path = empty) */
    issflt_("102,0", "  / 1,2 /", "11,3 / 8,9,4 /", " ", 5L, 9L, 14L, 1L);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if"
	    " its nameset is null and there is no normal filter.", 19L, 91L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if\
 its nameset is null and there is no normal filter.", 19L, 91L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =   102,0 */
/*    normal filter =   none */
/*    inverted filter = incl: empty; excl: 8,9 */

/*  pass/fail depending on (found path = 102,1) */
    issflt_("102,0", " ", "  / 8,9 /", "102,1", 5L, 1L, 9L, 5L);
/*  *** *** *** ***   Maximum number of filters   *** *** *** *** */

/*  <inquire phigs facilities> to determine: */
/*    mxnfl = maximum length of normal filter list */
/*    mxifl = maximum length of inverted filter list */
    nqphf (&c__1, &errind, &idum1, &idum2, &idum3, &idum4, &idum5, &mxnfl, &
	    mxifl);
    chkinq_("pqphf", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("21", "<Inquire phigs facilities> should report the maximum leng"
	    "ths of both the normal and inverted filter lists to be at least "
	    "1.", 2L, 123L);
#else /* NO_PROTO */
    setmsg_("21", "<Inquire phigs facilities> should report the maximum leng\
ths of both the normal and inverted filter lists to be at least 1.", 2L, 123L)
	    ;
#endif /* NO_PROTO */
    L__1 = mxnfl > 0 && mxifl > 0;
    ifpf_(&L__1);
    if (mxnfl < 2 || mxifl < 2) {
	inmsg_("Skipping tests of multiple filters.", 35L);
	goto L666;
    }
    mxntst = min(mxnfl,50);
    mxitst = min(mxifl,50);
#ifndef NO_PROTO
    setmsg_("21 22", "ISS should be able to specify as many filters in a lis"
	    "t as the maximum reported by <inquire phigs facilities>.", 5L, 
	    110L);
#else /* NO_PROTO */
    setmsg_("21 22", "ISS should be able to specify as many filters in a lis\
t as the maximum reported by <inquire phigs facilities>.", 5L, 110L);
#endif /* NO_PROTO */
    nptr = 1;
    inval = 3;
    i__1 = mxntst;
    for (n = 1; n <= i__1; ++n) {
	if (inval > 4) {
	    inval = 3;
	} else {
	    ++inval;
	}
/*  set up nth normal filter inclusion set as 1,inval */
/* Writing concatenation */
	i__2[0] = 2, a__1[0] = "1,";
	i__2[1] = 1, a__1[1] = digch + (inval - 1);
	i__2[2] = 1, a__1[2] = "/";
	s_cat(nfil + (nptr - 1), a__1, i__2, &c__3, 900 - (nptr - 1));
	nptr += 4;
/*  set up nth normal filter exclusion set as 8,9 */
	s_copy(nfil + (nptr - 1), "8,9/", 900 - (nptr - 1), 4L);
	nptr += 4;
/* L100: */
    }
    iptr = 1;
    inval = 5;
    i__1 = mxitst;
    for (n = 1; n <= i__1; ++n) {
	if (inval > 4) {
	    inval = 2;
	} else {
	    ++inval;
	}
/*  set up nth inverted filter inclusion set as 1,inval */
/* Writing concatenation */
	i__2[0] = 2, a__1[0] = "1,";
	i__2[1] = 1, a__1[1] = digch + (inval - 1);
	i__2[2] = 1, a__1[2] = "/";
	s_cat(ifil + (iptr - 1), a__1, i__2, &c__3, 900 - (iptr - 1));
	iptr += 4;
/*  set up nth inverted filter exclusion set as inval,8 */
/* Writing concatenation */
	i__3[0] = 1, a__2[0] = digch + (inval - 1);
	i__3[1] = 3, a__2[1] = ",8/";
	s_cat(ifil + (iptr - 1), a__2, i__3, &c__2, 900 - (iptr - 1));
	iptr += 4;
/* L200: */
    }
/*  ISS with */
/*    starting path =   101,1 */
/*    normal filter =   as set up */
/*    inverted filter = as set up */

/*  pass/fail depending on */
/*     (no error from ISS and found path = 101,2, 102,1) */
    issflt_("101,1", nfil, ifil, "101,2, 102,1", 5L, nptr, iptr, 12L);
/*  *** *** *** ***   Multiple filters   *** *** *** *** */

#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if"
	    " its nameset is accepted all the normal filters and rejected by "
	    "all the inverted filters.", 19L, 129L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should be found if\
 its nameset is accepted all the normal filters and rejected by all the inve\
rted filters.", 19L, 129L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =    101,1 */
/*    normal filters =   incl: 5,3,6,7; excl: 8,9 */
/*                       incl: 3;       excl: empty */
/*    inverted filters = incl: 1,2;     excl: 8,9 */
/*                       incl: 3,1,2;   excl: 4,8,9 */

/*  pass/fail depending on (found path = 101,2, 102,1) */
    issflt_("101,1", "5,3,6,7 / 8,9 / 3 /   /", "1,2 / 8,9 / 3,1,2 / 4,8,9 / "
	    , "101,2, 102,1", 5L, 23L, 28L, 12L);
#ifndef NO_PROTO
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun"
	    "d if its nameset is rejected by at least one normal filter.", 19L,
	     99L);
#else /* NO_PROTO */
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun\
d if its nameset is rejected by at least one normal filter.", 19L, 99L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =    101,1 */
/*    normal filters =   incl: 5,3,6,7; excl: 8,9 */
/*                       incl: 3;       excl: 3 */
/*    inverted filters = incl: 1,2;     excl: 8,9 */
/*                       incl: 3,1,2;   excl: 4,8,9 */

/*  pass/fail depending on (found path = empty) */
#ifndef NO_PROTO
    issflt_("101,1", "5,3,6,7 / 8,9 / 3 / 3 / ", "1,2 / 8,9 / 3,1,2 / 4,8,9 "
	    "/ ", " ", 5L, 24L, 28L, 1L);
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun"
	    "d if its nameset is accepted by at least one inverted filter.", 
	    19L, 101L);
#else /* NO_PROTO */
    issflt_("101,1", "5,3,6,7 / 8,9 / 3 / 3 / ", "1,2 / 8,9 / 3,1,2 / 4,8,9 \
/ ", " ", 5L, 24L, 28L, 1L);
    setmsg_("3 4 5 6 10 18 19 20", "An eligible primitive should not be foun\
d if its nameset is accepted by at least one inverted filter.", 19L, 101L);
#endif /* NO_PROTO */
/*  ISS with */
/*    starting path =    101,1 */
/*    normal filters =   incl: 5,3,6,7; excl: 8,9 */
/*                       incl: 3;       excl: 2,1 */
/*    inverted filters = incl: 4,1,2;   excl: 8,9 */
/*                       incl: 3,1,2;   excl: 4,8,9 */

/*  pass/fail depending on (found path = empty) */
#ifndef NO_PROTO
    issflt_("101,1", "5,3,6,7 / 8,9 / 3 / 2,1 / ", "4,1,2 / 8,9 / 3,1,2 / 4,"
	    "8,9 / ", " ", 5L, 26L, 30L, 1L);
#else /* NO_PROTO */
    issflt_("101,1", "5,3,6,7 / 8,9 / 3 / 2,1 / ", "4,1,2 / 8,9 / 3,1,2 / 4,\
8,9 / ", " ", 5L, 26L, 30L, 1L);
#endif /* NO_PROTO */
/*  end_mult_filter: */
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

