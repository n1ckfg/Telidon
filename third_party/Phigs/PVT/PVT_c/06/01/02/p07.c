/* fort//06/01/02/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
static integer c__102 = 102;
static integer c__109 = 109;
static integer c__2 = 2;
static integer c__103 = 103;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/07                           * */
/*  *    TEST TITLE : Saving and restoring the modelling    * */
/*  *                 clipping volume                       * */
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
    static real hs[18]	/* was [6][3] */ = { 0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,
	    0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f,0.f };
#else /* NO_PROTO */
    static real hs[18]	/* was [6][3] */ = { (float)0.,(float)0.,(float)0.,(
	    float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)
	    0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(
	    float)0.,(float)0. };
#endif /* NO_PROTO */

    static real xa[8], ya[8], za[8];
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *), 
	    endit_(void), nclst (void), nrmcv (void), nexst (integer *), 
	    nopst (integer *), nsmcv3 (integer *, integer *, real *), ndelra (
	    integer *, integer *), chkmcv_(char *, char *, ftnlen, ftnlen), 
	    initgl_(char *, ftnlen), setmsg_(char *, char *, ftnlen, ftnlen), 
	    xpopph_(integer *, integer *), setrvs_(char *, real *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 (), endit_(), nclst (), nrmcv (), nexst (
	    ), nopst (), nsmcv3 (), ndelra (), chkmcv_(), initgl_(), setmsg_()
	    , xpopph_(), setrvs_();
#endif /* NO_PROTO */

/* modelling clipping operator */
    initgl_("06.01.02/07", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Throughout, use incremental spatial search (ISS) to test the */
/*  effects of modelling clipping.  In general, ISS checks which */
/*  subset of primitives have been clipped so as to determine the */
/*  current modelling clipping volume.  The search reference point */
/*  and distance are constant and are set so as to reach all the */
/*  primitives. */
/*  hs(1) = half-space #1 = all points for which x > 0 */
/*  hs(2) = half-space #2 = all points for which y > 0 */
/*  hs(3) = half-space #3 = all points for which z > 0 */
#ifndef NO_PROTO
    hs[3] = .1f;
    hs[10] = .1f;
    hs[17] = .1f;
#else /* NO_PROTO */
    hs[3] = (float).1;
    hs[10] = (float).1;
    hs[17] = (float).1;
#endif /* NO_PROTO */
/*  Set up structure #101: */
    nopst (&c__101);
    nsmcv3 (&c__1, &c__1, hs);
    nexst (&c__102);
    nexst (&c__109);
    nsmcv3 (&c__2, &c__1, &hs[6]);
    nexst (&c__102);
    nexst (&c__109);
    nsmcv3 (&c__1, &c__1, &hs[6]);
    nexst (&c__103);
    nexst (&c__109);
    nclst ();
/*  Set up structure #102: */
    nopst (&c__102);
    nsmcv3 (&c__2, &c__1, &hs[12]);
    nexst (&c__103);
    nexst (&c__109);
    nclst ();
/*  Set up structure #103: */
    nopst (&c__103);
    nsmcv3 (&c__1, &c__1, &hs[12]);
    nexst (&c__109);
    nclst ();
/*  Set up structure #109: */
    setrvs_("-1,-1,-1,-1, 1, 1, 1, 1", xa, &ix, 23L);
    setrvs_("-1,-1, 1, 1,-1,-1, 1, 1", ya, &ix, 23L);
    setrvs_("-1, 1,-1, 1,-1, 1,-1, 1", za, &ix, 23L);
    nopst (&c__109);
    for (ix = 1; ix <= 8; ++ix) {
	npm3 (&c__1, &xa[ix - 1], &ya[ix - 1], &za[ix - 1]);
/* L100: */
    }
    nclst ();
#ifndef NO_PROTO
    setmsg_("40 43 57", "When an executed structure sets the MCV with REPLAC"
	    "E, it should override the inherited current MCV.", 8L, 99L);
    chkmcv_("101,0", "101,2, 102,2, 103,2, 109,2 /101,2, 102,2, 103,2, 109,4"
	    " /101,2, 102,2, 103,2, 109,6 /101,2, 102,2, 103,2, 109,8 /", 5L, 
	    112L);
#else /* NO_PROTO */
    setmsg_("40 43 57", "When an executed structure sets the MCV with REPLAC\
E, it should override the inherited current MCV.", 8L, 99L);
    chkmcv_("101,0", "101,2, 102,2, 103,2, 109,2 /101,2, 102,2, 103,2, 109,4\
 /101,2, 102,2, 103,2, 109,6 /101,2, 102,2, 103,2, 109,8 /", 5L, 112L);
#endif /* NO_PROTO */
/*  based on expected MCV = HS(3) */
#ifndef NO_PROTO
    setmsg_("40 43 51 57", "A calling structure should have its current MCV "
	    "restored after traversal returns from the executed structure.", 
	    11L, 109L);
    chkmcv_("101,2, 102,2, 103,2", "101,2, 102,3, 109,6 /101,2, 102,3, 109,8"
	    " /", 19L, 42L);
#else /* NO_PROTO */
    setmsg_("40 43 51 57", "A calling structure should have its current MCV \
restored after traversal returns from the executed structure.", 11L, 109L);
    chkmcv_("101,2, 102,2, 103,2", "101,2, 102,3, 109,6 /101,2, 102,3, 109,8\
 /", 19L, 42L);
#endif /* NO_PROTO */
/*  based on expected MCV = HS(1),HS(3) */
#ifndef NO_PROTO
    setmsg_("40 43 51 57", "A calling structure should have its current MCV "
	    "restored after traversal returns from two levels of execution.", 
	    11L, 110L);
    chkmcv_("101,2, 102,3", "101,3, 109,5 /101,3, 109,6 /101,3, 109,7 /101,3"
	    ", 109,8 /", 12L, 56L);
#else /* NO_PROTO */
    setmsg_("40 43 51 57", "A calling structure should have its current MCV \
restored after traversal returns from two levels of execution.", 11L, 110L);
    chkmcv_("101,2, 102,3", "101,3, 109,5 /101,3, 109,6 /101,3, 109,7 /101,3\
, 109,8 /", 12L, 56L);
#endif /* NO_PROTO */
/*  based on expected MCV = HS(1) */
#ifndef NO_PROTO
    setmsg_("40 43 57", "When an executed structure sets the MCV with REPLAC"
	    "E, it should override the inherited current MCV, even when calle"
	    "d twice.", 8L, 123L);
    chkmcv_("101,3", "101,5, 102,2, 103,2, 109,2 /101,5, 102,2, 103,2, 109,4"
	    " /101,5, 102,2, 103,2, 109,6 /101,5, 102,2, 103,2, 109,8 /", 5L, 
	    112L);
#else /* NO_PROTO */
    setmsg_("40 43 57", "When an executed structure sets the MCV with REPLAC\
E, it should override the inherited current MCV, even when called twice.", 8L,
	     123L);
    chkmcv_("101,3", "101,5, 102,2, 103,2, 109,2 /101,5, 102,2, 103,2, 109,4\
 /101,5, 102,2, 103,2, 109,6 /101,5, 102,2, 103,2, 109,8 /", 5L, 112L);
#endif /* NO_PROTO */
/*  based on expected MCV = HS(3) */
#ifndef NO_PROTO
    setmsg_("40 43 51 57", "A calling structure should have its current MCV "
	    "restored after executing the same structure twice.", 11L, 98L);
#else /* NO_PROTO */
    setmsg_("40 43 51 57", "A calling structure should have its current MCV \
restored after executing the same structure twice.", 11L, 98L);
#endif /* NO_PROTO */
    chkmcv_("101,5, 102,2, 103,2", "101,5, 102,3, 109,8 /", 19L, 21L);
/*  based on expected MCV = HS(1),HS(2),HS(3) */
#ifndef NO_PROTO
    setmsg_("40 43 51 57", "A calling structure should have its current MCV "
	    "restored after traversal repeatedly returns from two levels of e"
	    "xecution.", 11L, 121L);
#else /* NO_PROTO */
    setmsg_("40 43 51 57", "A calling structure should have its current MCV \
restored after traversal repeatedly returns from two levels of execution.", 
	    11L, 121L);
#endif /* NO_PROTO */
    chkmcv_("101,5, 102,3", "101,6, 109,7 /101,6, 109,8 /", 12L, 28L);
/*  based on expected MCV = HS(1),HS(2) */
#ifndef NO_PROTO
    setmsg_("40 43 57", "When an executed structure sets the MCV with REPLAC"
	    "E, it should override the inherited current MCV, even when calle"
	    "d by a different structure.", 8L, 142L);
    chkmcv_("101,6", "101,8, 103,2, 109,2 /101,8, 103,2, 109,4 /101,8, 103,2"
	    ", 109,6 /101,8, 103,2, 109,8 /", 5L, 84L);
#else /* NO_PROTO */
    setmsg_("40 43 57", "When an executed structure sets the MCV with REPLAC\
E, it should override the inherited current MCV, even when called by a diffe\
rent structure.", 8L, 142L);
    chkmcv_("101,6", "101,8, 103,2, 109,2 /101,8, 103,2, 109,4 /101,8, 103,2\
, 109,6 /101,8, 103,2, 109,8 /", 5L, 84L);
#endif /* NO_PROTO */
/*  based on expected MCV = HS(3) */
#ifndef NO_PROTO
    setmsg_("40 43 51 57", "A calling structure should have its current MCV "
	    "restored after traversal returns from different structures.", 11L,
	     107L);
    chkmcv_("101,8, 103,2", "101,9, 109,3 /101,9, 109,4 /101,9, 109,7 /101,9"
	    ", 109,8 /", 12L, 56L);
#else /* NO_PROTO */
    setmsg_("40 43 51 57", "A calling structure should have its current MCV \
restored after traversal returns from different structures.", 11L, 107L);
    chkmcv_("101,8, 103,2", "101,9, 109,3 /101,9, 109,4 /101,9, 109,7 /101,9\
, 109,8 /", 12L, 56L);
#endif /* NO_PROTO */
/*  based on expected MCV = HS(2) */
/*  *** *** *** ***   <restore MCV>   *** *** *** *** */
/*  Add to structure #103: */
/*  3: restore MCV */
/*  4: execute structure 109 */
    nopst (&c__103);
    nrmcv ();
    nexst (&c__109);
#ifndef NO_PROTO
    setmsg_("40 43 56 57", "<Restore MCV> should cause the current MCV to be"
	    " reset to the original value it had upon entry to the structure,"
	    " even though the value was replaced within the structure.", 11L, 
	    169L);
#else /* NO_PROTO */
    setmsg_("40 43 56 57", "<Restore MCV> should cause the current MCV to be\
 reset to the original value it had upon entry to the structure, even though\
 the value was replaced within the structure.", 11L, 169L);
#endif /* NO_PROTO */
    chkmcv_("101,5,102,2,103,2", "101,5, 102,2, 103,4, 109,8 /", 17L, 28L);
/*  based on expected MCV = HS(1),HS(2),HS(3) */
/*  change structure #103: */
/*  1: set MCV = hs2 with intersect */
    ndelra (&c__1, &c__1);
    nsmcv3 (&c__2, &c__1, &hs[6]);
    nclst ();
#ifndef NO_PROTO
    setmsg_("40 43 56 57", "<Restore MCV> should cause the current MCV to be"
	    " reset to the original value it had upon entry to the structure,"
	    " even though the value was altered by intersection within the st"
	    "ructure.", 11L, 184L);
    chkmcv_("101,2,102,2,103,2", "101,2, 102,2, 103,4, 109,6 /101,2, 102,2, "
	    "103,4, 109,8 /", 17L, 56L);
#else /* NO_PROTO */
    setmsg_("40 43 56 57", "<Restore MCV> should cause the current MCV to be\
 reset to the original value it had upon entry to the structure, even though\
 the value was altered by intersection within the structure.", 11L, 184L);
    chkmcv_("101,2,102,2,103,2", "101,2, 102,2, 103,4, 109,6 /101,2, 102,2, \
103,4, 109,8 /", 17L, 56L);
#endif /* NO_PROTO */
/*  based on expected MCV = HS(1),HS(3) */
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

