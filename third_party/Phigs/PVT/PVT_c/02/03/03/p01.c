/* fort/02/03/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__123 = 123;
static integer c__101 = 101;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b14 = 22.1f;
static real c_b15 = 2.1f;
static real c_b16 = 666.6f;
static real c_b17 = .2f;
static real c_b22 = 22.f;
static real c_b23 = 2.f;
static real c_b25 = 0.f;
#else /* NO_PROTO */
static real c_b14 = (float)22.1;
static real c_b15 = (float)2.1;
static real c_b16 = (float)666.6;
static real c_b17 = (float).2;
static real c_b22 = (float)22.;
static real c_b23 = (float)2.;
static real c_b25 = (float)0.;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b32 = -.1f;
static real c_b43 = 21.5f;
static real c_b44 = 1.5f;
static real c_b46 = .1f;
static real c_b54 = .11f;
static real c_b59 = 23.f;
static real c_b62 = -33.3f;
static real c_b72 = 21.7f;
static real c_b73 = 1.3f;
static real c_b96 = 1.f;
static real c_b118 = 3.5f;
#else /* NO_PROTO */
static real c_b32 = (float)-.1;
static real c_b43 = (float)21.5;
static real c_b44 = (float)1.5;
static real c_b46 = (float).1;
static real c_b54 = (float).11;
static real c_b59 = (float)23.;
static real c_b62 = (float)-33.3;
static real c_b72 = (float)21.7;
static real c_b73 = (float)1.3;
static real c_b96 = (float)1.;
static real c_b118 = (float)3.5;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b127 = 5.f;
static real c_b136 = 4.9f;
static real c_b137 = 5.5f;
static real c_b139 = .3f;
static real c_b167 = 3.f;
static real c_b169 = 2.5f;
#else /* NO_PROTO */
static real c_b127 = (float)5.;
static real c_b136 = (float)4.9;
static real c_b137 = (float)5.5;
static real c_b139 = (float).3;
static real c_b167 = (float)3.;
static real c_b169 = (float)2.5;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.03/01                           * */
/*  *    TEST TITLE : Basic spatial search for 2-D          * */
/*  *                 primitives                            * */
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

    static integer colia[6]	/* was [3][2] */ = { 1,0,1,0,1,1 };

    static real xa[100], ya[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int nca (real *, real *, real *, real *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    ), nfa (integer *, real *, real *), npl (integer *, real *, real *
	    ), npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nca (), nfa (), npl (), npm ();
#endif /* NO_PROTO */
    static integer nsz;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen), nfas (
	    integer *, integer *, real *, real *), natr (real *, real *, real 
	    *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx (), nfas (), natr ();
#endif /* NO_PROTO */
    static integer npts, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nschh (real *), inmsg_(char *, 
	    ftnlen), isspf_(integer *, real *, real *, real *, real *, char *,
	     ftnlen), nemst (integer *), setvs_(char *, integer *, integer *, 
	    ftnlen), nopst (integer *), nsatch (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nschh (), inmsg_(), isspf_(), 
	    nemst (), setvs_(), nopst (), nsatch ();
#endif /* NO_PROTO */
    static integer endpts[20];
#ifndef NO_PROTO
    extern logical sphdis_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), nsatal (integer *, integer *), nstxal (
	    integer *, integer *), xpopph_(integer *, integer *), setrvs_(
	    char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical sphdis_();
    extern /* Subroutine */ int initgl_(), setmsg_(), nsatal (), nstxal (), 
	    xpopph_(), setrvs_();
#endif /* NO_PROTO */

/* text alignment horizontal */
/* text alignment vertical */
    initgl_("02.03.03/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    if (! sphdis_(&c__123)) {
#ifndef NO_PROTO
	inmsg_("Skipping test because implementation apparently uses non-Euc"
		"lidean metric for search distance.", 94L);
#else /* NO_PROTO */
	inmsg_("Skipping test because implementation apparently uses non-Euc\
lidean metric for search distance.", 94L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  All ISS's from start of root (101,0), no modelling clipping, */
/*  null filter lists, search ceiling = 1. */
    nopst (&c__101);

/*  *** *** *** ***   polymarker   *** *** *** *** */

/*  Build structure 101: */
/*    1.  polymarker: (11,1), (12,2), (13,2), (22.3, 2.3) */
/*    2.  polymarker: (21,1), (22,2), (23,2) */
    nemst (&c__101);
    setrvs_("11, 12, 13,  22.3", xa, &nsz, 17L);
    setrvs_(" 1,  2,  2,   2.3", ya, &nsz, 17L);
    npm (&nsz, xa, ya);
    setrvs_("21, 22, 23", xa, &nsz, 10L);
    setrvs_(" 1,  2,  2", ya, &nsz, 10L);
    npm (&nsz, xa, ya);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 11", "The points of a qualifying two-dimension"
	    "al polymarker should be found by a two-dimensional spatial searc"
	    "h.", 19L, 106L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 11", "The points of a qualifying two-dimension\
al polymarker should be found by a two-dimensional spatial search.", 19L, 
	    106L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b14, &c_b15, &c_b16, &c_b17, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 11", "The points of a qualifying two-dimension"
	    "al polymarker should be found by a two-dimensional spatial searc"
	    "h, even when the search distance is zero.", 19L, 145L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 11", "The points of a qualifying two-dimension\
al polymarker should be found by a two-dimensional spatial search, even when\
 the search distance is zero.", 19L, 145L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b22, &c_b23, &c_b16, &c_b25, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 11", "The points of a qualifying two-dimensional"
	    " polymarker should be found by a three-dimensional spatial searc"
	    "h.", 17L, 108L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 11", "The points of a qualifying two-dimensional\
 polymarker should be found by a three-dimensional spatial search.", 17L, 
	    108L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b14, &c_b15, &c_b32, &c_b17, "101,2", 5L);
/*  *** *** *** ***   polyline   *** *** *** *** */

/*  Build structure 101: */
/*    1.  polyline: (11,1), (12,2), (13,2), (21.5, 1.7) */
/*    2.  polyline: (21,1), (22,2), (23,2) */
    nemst (&c__101);
    setrvs_("11, 12, 13, 21.5", xa, &nsz, 16L);
    setrvs_(" 1,  2,  2,  1.7", ya, &nsz, 16L);
    npl (&nsz, xa, ya);
    setrvs_("21, 22, 23", xa, &nsz, 10L);
    setrvs_(" 1,  2,  2 ", ya, &nsz, 11L);
    npl (&nsz, xa, ya);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 12", "The line segments of a qualifying two-di"
	    "mensional polyline should be found by a two-dimensional spatial "
	    "search.", 19L, 111L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 12", "The line segments of a qualifying two-di\
mensional polyline should be found by a two-dimensional spatial search.", 19L,
	     111L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b43, &c_b44, &c_b16, &c_b46, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 12", "The line segments of a qualifying two-dime"
	    "nsional polyline should be found by a three-dimensional spatial "
	    "search.", 17L, 113L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 12", "The line segments of a qualifying two-dime\
nsional polyline should be found by a three-dimensional spatial search.", 17L,
	     113L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b43, &c_b44, &c_b46, &c_b54, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 12", "The line segments of a qualifying two-dime"
	    "nsional polyline should be found by a three-dimensional spatial "
	    "search, even when the search distance is negative.", 17L, 156L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 12", "The line segments of a qualifying two-dime\
nsional polyline should be found by a three-dimensional spatial search, even\
 when the search distance is negative.", 17L, 156L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b59, &c_b23, &c_b25, &c_b62, "101,2", 5L);
/*  *** *** *** ***   fill area   *** *** *** *** */

/*  Build structure 101: */
/*    1.  fill area: (20.5, 1), (21.5, 2), (21.5, 1) */
/*    2.  fill area: (21,   1), (22,   2), (22,   1) */

    nemst (&c__101);
    setrvs_("20.5, 21.5, 21.5", xa, &nsz, 16L);
    setrvs_(" 1,    2,    1", ya, &nsz, 14L);
    nfa (&nsz, xa, ya);
    setrvs_("21, 22, 22", xa, &nsz, 10L);
    setrvs_(" 1,  2,  1 ", ya, &nsz, 11L);
    nfa (&nsz, xa, ya);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 13", "The interior of a qualifying two-dimensi"
	    "onal fill area should be found by a two-dimensional spatial sear"
	    "ch.", 19L, 107L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 13", "The interior of a qualifying two-dimensi\
onal fill area should be found by a two-dimensional spatial search.", 19L, 
	    107L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b72, &c_b73, &c_b16, &c_b46, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 13", "The interior of a qualifying two-dimension"
	    "al fill area should be found by a three-dimensional spatial sear"
	    "ch.", 17L, 109L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 13", "The interior of a qualifying two-dimension\
al fill area should be found by a three-dimensional spatial search.", 17L, 
	    109L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b72, &c_b73, &c_b46, &c_b54, "101,2", 5L);
/*  *** *** *** ***   fill area set   *** *** *** *** */

/*  Build structure 101: */
/*    1.  fill area set: (1,0), (0,1), (1,2)  / (3,2), (4,1), (3,0) */
/*    2.  fill area set: (11,2), (13,2), (13,0), (11,0)  / */
/*                       ( 1,2), ( 3,2), ( 3,0), ( 1,0) */
    nemst (&c__101);
    setrvs_("1, 0, 1, 3, 4, 3", xa, &idum1, 16L);
    setrvs_("0, 1, 2, 2, 1, 0", ya, &idum1, 16L);
    setvs_("3, 6", endpts, &npts, 4L);
    nfas (&npts, endpts, xa, ya);
    setrvs_("11, 13, 13, 11, 1, 3, 3, 1", xa, &idum1, 26L);
    setrvs_(" 2,  2,  0,  0, 2, 2, 0, 0", ya, &idum1, 26L);
    setvs_("4, 8", endpts, &npts, 4L);
    nfas (&npts, endpts, xa, ya);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 14", "The interiors of a qualifying two-dimens"
	    "ional fill area set should be found by a two-dimensional spatial"
	    " search.", 19L, 112L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 14", "The interiors of a qualifying two-dimens\
ional fill area set should be found by a two-dimensional spatial search.", 
	    19L, 112L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b23, &c_b96, &c_b16, &c_b46, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 14", "The interiors of a qualifying two-dimensio"
	    "nal fill area set should be found by a three-dimensional spatial"
	    " search.", 17L, 114L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 14", "The interiors of a qualifying two-dimensio\
nal fill area set should be found by a three-dimensional spatial search.", 
	    17L, 114L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b23, &c_b96, &c_b46, &c_b54, "101,2", 5L);
/*  Build structure 101: */
/*    1.  fill area set: (1,4), (4,1), (4,4) / (3,6), (6,3), (3,3) */
/*    2.  fill area set: (3.4,3.4), (3.4,3.6), (3.6,3.6), (3.6,3.4) */
    nemst (&c__101);
    setrvs_("1, 4, 4, 3, 6, 3", xa, &idum1, 16L);
    setrvs_("4, 1, 4, 6, 3, 3", ya, &idum1, 16L);
    setvs_("3, 6", endpts, &npts, 4L);
    nfas (&npts, endpts, xa, ya);
    setrvs_("3.4, 3.4, 3.6, 3.6", xa, &idum1, 18L);
    setrvs_("3.4, 3.6, 3.6, 3.4", ya, &idum1, 18L);
    setvs_("4", endpts, &npts, 1L);
    nfas (&npts, endpts, xa, ya);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 14", "The interior of a qualifying two-dimensi"
	    "onal fill area set should be found by a two-dimensional spatial "
	    "search, but sub-areas overlapping an even number of times should"
	    " not be found.", 19L, 182L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 14", "The interior of a qualifying two-dimensi\
onal fill area set should be found by a two-dimensional spatial search, but \
sub-areas overlapping an even number of times should not be found.", 19L, 
	    182L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b118, &c_b118, &c_b16, &c_b46, "101,2", 5L);
/*  *** *** *** ***   text   *** *** *** *** */

/*  Build structure 101: */
/*    1.  set character height = 1.0 */
/*    2.  set text alignment   = (LEFT, BOTTOM) */
/*    3.  text: "Viva PHIGS!" at 5,0 */
/*    4.  text: "Viva PHIGS!" at 5,5 */
    nemst (&c__101);
    nschh (&c_b96);
    nstxal (&c__1, &c__5);
    ntx (&c_b127, &c_b25, "Viva PHIGS!", 11L);
    ntx (&c_b127, &c_b127, "Viva PHIGS!", 11L);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 15", "The text extent rectangle of a qualifyin"
	    "g two-dimensional text primitive should be found by a two-dimens"
	    "ional spatial search.", 19L, 125L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 15", "The text extent rectangle of a qualifyin\
g two-dimensional text primitive should be found by a two-dimensional spatia\
l search.", 19L, 125L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b136, &c_b137, &c_b16, &c_b139, "101,4", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 15", "The text extent rectangle of a qualifying "
	    "two-dimensional text primitive should be found by a three-dimens"
	    "ional spatial search.", 17L, 127L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 15", "The text extent rectangle of a qualifying \
two-dimensional text primitive should be found by a three-dimensional spatia\
l search.", 17L, 127L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b136, &c_b137, &c_b32, &c_b139, "101,4", 5L);
/*  *** *** *** ***   annotation text   *** *** *** *** */

/*  Build structure 101: */
/*    1.  set annotation text character height = 1.0 */
/*    2.  set annotation text alignment        = (LEFT, BOTTOM) */
/*    3.  annotation text relative: "Viva PHIGS!" at 5,0 with offset = 0,0
 */
/*    4.  annotation text relative: "Viva PHIGS!" at 5,5 with offset = 0,0
 */
    nemst (&c__101);
    nsatch (&c_b96);
    nsatal (&c__1, &c__5);
    natr (&c_b127, &c_b25, &c_b25, &c_b25, "Viva PHIGS!", 11L);
    natr (&c_b127, &c_b127, &c_b25, &c_b25, "Viva PHIGS!", 11L);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 16", "The annotation reference point of a qual"
	    "ifying two-dimensional annotation text should be found by a two-"
	    "dimensional spatial search.", 19L, 131L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 16", "The annotation reference point of a qual\
ifying two-dimensional annotation text should be found by a two-dimensional \
spatial search.", 19L, 131L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b127, &c_b167, &c_b16, &c_b169, "101,4", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 16", "The annotation reference point of a qualif"
	    "ying two-dimensional annotation text should be found by a three-"
	    "dimensional spatial search.", 17L, 133L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 16", "The annotation reference point of a qualif\
ying two-dimensional annotation text should be found by a three-dimensional \
spatial search.", 17L, 133L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b127, &c_b167, &c_b96, &c_b169, "101,4", 5L);
/*  *** *** *** ***   cell array   *** *** *** *** */

/*  colia = color index array =  1 0 1 */
/*                               0 1 1 */
/*  Build structure 101: */
/*    1.  cell array: colia between corners (0,0) and (2,2) */
/*    2.  cell array: colia between corners (1,1) and (3,3) */
    nemst (&c__101);
    nca (&c_b25, &c_b25, &c_b23, &c_b23, &c__3, &c__2, &c__1, &c__1, &c__3, &
	    c__2, colia);
    nca (&c_b96, &c_b96, &c_b167, &c_b167, &c__3, &c__2, &c__1, &c__1, &c__3, 
	    &c__2, colia);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 17", "The parallelogram of a qualifying two-di"
	    "mensional cell array should be found by a two-dimensional spatia"
	    "l search.", 19L, 113L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 17", "The parallelogram of a qualifying two-di\
mensional cell array should be found by a two-dimensional spatial search.", 
	    19L, 113L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b23, &c_b169, &c_b16, &c_b46, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 17", "The parallelogram of a qualifying two-dime"
	    "nsional cell array should be found by a three-dimensional spatia"
	    "l search.", 17L, 115L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 17", "The parallelogram of a qualifying two-dime\
nsional cell array should be found by a three-dimensional spatial search.", 
	    17L, 115L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b23, &c_b169, &c_b46, &c_b54, "101,2", 5L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

