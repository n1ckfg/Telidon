/* e04153.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

#ifndef NO_PROTO
static real c_b5 = .5f;
static real c_b6 = .6f;
static real c_b7 = .7f;
static real c_b8 = .8f;
static real c_b9 = .9f;
static real c_b10 = .1f;
#else /* NO_PROTO */
static real c_b5 = (float).5;
static real c_b6 = (float).6;
static real c_b7 = (float).7;
static real c_b8 = (float).8;
static real c_b9 = (float).9;
static real c_b10 = (float).1;
#endif /* NO_PROTO */
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b16 = .2f;
static real c_b17 = .3f;
static real c_b18 = .4f;
#else /* NO_PROTO */
static real c_b16 = (float).2;
static real c_b17 = (float).3;
static real c_b18 = (float).4;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__16 = 16;
#ifndef NO_PROTO
static real c_b53 = .01f;
#else /* NO_PROTO */
static real c_b53 = (float).01;
#endif /* NO_PROTO */
static integer c__6 = 6;
#ifndef NO_PROTO
static real c_b83 = 0.f;
#else /* NO_PROTO */
static real c_b83 = (float)0.;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e04153_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e04153_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int etr_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr_();
#endif /* NO_PROTO */
    static integer pcl1, pcl2, pcl3;
#ifndef NO_PROTO
    extern /* Subroutine */ int etr3_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etr3_();
#endif /* NO_PROTO */
    static integer isiz;
    static real vwcp[6];
    static integer idum1;
    static real vwcp0[6], vwcp1[6], vwcp4[4];
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical rareq_();
#endif /* NO_PROTO */
    static real mapmt[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk ();
#endif /* NO_PROTO */
    static real vwcp40[6];
#ifndef NO_PROTO
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_();
#endif /* NO_PROTO */
    static real rotmt[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqvwr (integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , integer *), nsvwr (integer *, integer *, real *, real *, real *,
	     integer *), rsvwr_(integer *, integer *, real *, real *, real *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqvwr (), nsvwr (), rsvwr_();
#endif /* NO_PROTO */
    static real mapmt3[16]	/* was [4][4] */, rotmt3[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwr3 (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *), rsvwr3_(integer *, 
	    integer *, real *, real *, real *, integer *, integer *, integer *
	    ), chkinq_(char *, integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwr3 (), rsvwr3_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
    static real qmapmt[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */
    static real qrotmt[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setrvs_();
#endif /* NO_PROTO */

/*    E04153 tests the handling of error 153. */
/*  clipping indicator */

#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified view clipping limits are invalid:"
	    " XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX", 200L, 84L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified view clipping limits are invalid:\
 XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX", 200L, 84L);
#endif /* NO_PROTO */
    setvs_("153", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  try 3D cases first */
    etr3_(&c_b5, &c_b6, &c_b7, rotmt3);
    etr3_(&c_b8, &c_b9, &c_b10, mapmt3);
    setrvs_(".1,.9,.1,.9,.1,.9", vwcp0, &isiz, 17L);
    nsvwr3 (&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp0, &c__1, &c__1, &c__1)
	    ;
    etr3_(&c_b16, &c_b17, &c_b18, rotmt3);
    etr3_(&c_b17, &c_b18, &c_b5, mapmt3);
    setrvs_(".6,.3,0.,1.,0.,1.", vwcp, &isiz, 17L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__0, &c__0, &c__0);

    setrvs_("0.,1.,.6,.6,0.,1.", vwcp, &isiz, 17L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__0, &c__0, &c__0);

    setrvs_("0.,1.,0.,1.,.6,.3", vwcp, &isiz, 17L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__0, &c__0, &c__0);

    setrvs_("0.,1.,.6,.3,0.,0.", vwcp, &isiz, 17L);
    rsvwr3_(&globnu_1.wkid, &c__1, rotmt3, mapmt3, vwcp, &c__0, &c__0, &c__0);

    etr3_(&c_b5, &c_b6, &c_b7, rotmt3);
    etr3_(&c_b8, &c_b9, &c_b10, mapmt3);
    nqvwr (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, qrotmt, qmapmt, 
	    vwcp1, &pcl1, &pcl2, &pcl3);
    chkinq_("pqvwr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__16, qrotmt, rotmt3, &c_b53, &
	    c_b53) && rareq_(&c__16, qmapmt, mapmt3, &c_b53, &c_b53) && 
	    rareq_(&c__6, vwcp1, vwcp0, &c_b53, &c_b53) && pcl1 == 1 && pcl2 
	    == 1 && pcl3 == 1;
    tstign_(&L__1);
/*  now test 2D cases */
    etr_(&c_b10, &c_b16, rotmt);
    etr_(&c_b17, &c_b18, mapmt);
    setrvs_(".1,.9,.1,.9,.0,1.0", vwcp40, &isiz, 18L);
    nsvwr (&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp40, &c__1);
    etr_(&c_b5, &c_b6, rotmt);
    etr_(&c_b7, &c_b8, mapmt);
    setrvs_(".6,.3,0.,1.", vwcp4, &isiz, 11L);
    rsvwr_(&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp4, &c__0);
    setrvs_("0.,1.,.6,.3", vwcp4, &isiz, 11L);
    rsvwr_(&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp4, &c__0);
    setrvs_(".44,.44, .5,.6", vwcp4, &isiz, 14L);
    rsvwr_(&globnu_1.wkid, &c__1, rotmt, mapmt, vwcp4, &c__0);
    etr3_(&c_b10, &c_b16, &c_b83, rotmt3);
    etr3_(&c_b17, &c_b18, &c_b83, mapmt3);
    nqvwr (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, qrotmt, qmapmt, 
	    vwcp1, &pcl1, &pcl2, &pcl3);
    chkinq_("pqvwr", &errind, 5L);
    L__1 = streq_("OO**", 4L) && rareq_(&c__16, qrotmt, rotmt3, &c_b53, &
	    c_b53) && rareq_(&c__16, qmapmt, mapmt3, &c_b53, &c_b53) && 
	    rareq_(&c__6, vwcp1, vwcp40, &c_b53, &c_b53) && pcl1 == 1 && pcl2 
	    == 1 && pcl3 == 1;
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e04153_ */

