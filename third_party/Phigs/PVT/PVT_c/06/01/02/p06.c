/* fort//06/01/02/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b5 = .7f;
static real c_b6 = .8f;
static real c_b7 = .9f;
static real c_b8 = .4f;
static real c_b9 = .5f;
static real c_b10 = .6f;
static real c_b11 = .1f;
static real c_b12 = .2f;
static real c_b13 = .3f;
static real c_b14 = 1.f;
#else /* NO_PROTO */
static real c_b5 = (float).7;
static real c_b6 = (float).8;
static real c_b7 = (float).9;
static real c_b8 = (float).4;
static real c_b9 = (float).5;
static real c_b10 = (float).6;
static real c_b11 = (float).1;
static real c_b12 = (float).2;
static real c_b13 = (float).3;
static real c_b14 = (float)1.;
#endif /* NO_PROTO */
static integer c__101 = 101;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/06                           * */
/*  *    TEST TITLE : Effect of modelling clipping in a     * */
/*  *                 single structure                      * */
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
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal), sqrt(doublereal);
#else /* NO_PROTO */
    double cos(), sin(), sqrt();
#endif /* NO_PROTO */

    /* Local variables */
    static real a1[16]	/* was [4][4] */, hs[30]	/* was [6][5] */, ang;

#ifndef NO_PROTO
    extern /* Subroutine */ int nfa3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa3 ();
#endif /* NO_PROTO */
    static real hs2d[20]	/* was [4][5] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl3 (integer *, real *, real *, real *);
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl3 ();
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static integer hsdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static real srpx, srpy, srpz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nsedm (integer *), inmsg_(char *
	    , ftnlen), nemst (integer *), nsmcv (integer *, integer *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nsedm (), inmsg_(), nemst (), 
	    nsmcv ();
#endif /* NO_PROTO */
    static integer hssiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), ebltm3_(real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *), nsmcv3 (integer *, integer *, real *), 
	    nsgmt3 (real *), nslmt3 (real *, integer *), ndelra (integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), ebltm3_(), nsmcv3 (), nsgmt3 (), 
	    nslmt3 (), ndelra ();
#endif /* NO_PROTO */
    static real linlen;
    static integer endsiz;
    static real endptx[5], endpty[5], endptz[5], angstp;
#ifndef NO_PROTO
    extern logical sphdis_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), issdis_(real *, real *, real *, real *, real *
	    , integer *, char *, ftnlen), xpopph_(integer *, integer *), 
	    setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical sphdis_();
    extern /* Subroutine */ int initgl_(), setmsg_(), issdis_(), xpopph_(), 
	    setrvs_();
#endif /* NO_PROTO */

/* clipping indicator */
/*                noclip      clip */
/* modelling clipping operator */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* edit mode */
    initgl_("06.01.02/06", 11L);
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
/*  Throughout, use incremental spatial search (ISS) to test the */
/*  effects of modelling clipping.  In general, ISS will be performed */
/*  with the search distance (sdist) set just below and above the */
/*  distance needed to reach the unclipped part of a primitive from */
/*  the search reference point (srp). */

/*  A1 = rigid transformation  = rotate: .1 .2 .3, shift: .4 .5 .6 */
/*                               fixed point: .7 .8 .9 */
    ebltm3_(&c_b5, &c_b6, &c_b7, &c_b8, &c_b9, &c_b10, &c_b11, &c_b12, &c_b13,
	     &c_b14, &c_b14, &c_b14, a1);
/*  endpt = polyline end points */
    setrvs_("1.2, 9.4", endptx, &endsiz, 8L);
    setrvs_("3.1, 7.0", endpty, &endsiz, 8L);
    setrvs_("0.2, 1.9", endptz, &endsiz, 8L);
/*  Set up structure #101: */
    nopst (&c__101);
    nsgmt3 (a1);
    npl3 (&endsiz, endptx, endpty, endptz);
    srpx = endptx[1];
    srpy = endpty[1];
#ifndef NO_PROTO
    srpz = endptz[1] + .1f;
    setmsg_("42 50", "Before any explicit clipping volume is applied, the cl"
	    "ipping volume should be all of WC space, and all parts of primit"
	    "ives should be detected.", 5L, 142L);
#else /* NO_PROTO */
    srpz = endptz[1] + (float).1;
    setmsg_("42 50", "Before any explicit clipping volume is applied, the cl\
ipping volume should be all of WC space, and all parts of primitives should \
be detected.", 5L, 142L);
#endif /* NO_PROTO */
    issdis_(&srpx, &srpy, &srpz, &c_b11, a1, &c__1, "101,2", 5L);
/*  clip off half of line near endpt(2) */
    hs[0] = (endptx[0] + endptx[1]) / 2;
    hs[1] = (endpty[0] + endpty[1]) / 2;
    hs[2] = (endptz[0] + endptz[1]) / 2;
    hs[3] = endptx[0] - endptx[1];
    hs[4] = endpty[0] - endpty[1];
    hs[5] = endptz[0] - endptz[1];
/*  insert MCV element: */
    nsedm (&c__0);
    nsep (&c__1);
    nsmcv3 (&c__2, &c__1, hs);
    srpz = endptz[1];
/*  linlen = length of line segment */
    linlen = vecl_(&hs[3], &hs[4], &hs[5]);
#ifndef NO_PROTO
    setmsg_("40 41 42 43 50 57", "When a primitive line segment intersects t"
	    "he boundary plane of a clipping volume, that part of it not in t"
	    "he half-space of the volume should be clipped.", 17L, 152L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 50 57", "When a primitive line segment intersects t\
he boundary plane of a clipping volume, that part of it not in the half-spac\
e of the volume should be clipped.", 17L, 152L);
#endif /* NO_PROTO */
    r__1 = linlen / 2;
    issdis_(&srpx, &srpy, &srpz, &r__1, a1, &c__1, "101,3", 5L);
/*  <empty structure> 101 */
    nemst (&c__101);
/*  center of rays = 2.91, 0.92, 0.18 */
#ifndef NO_PROTO
    srpx = 2.91f;
    srpy = .92f;
    srpz = .18f;
#else /* NO_PROTO */
    srpx = (float)2.91;
    srpy = (float).92;
    srpz = (float).18;
#endif /* NO_PROTO */
/*  angstp = angle step = 25 degrees */
#ifndef NO_PROTO
    angstp = .43633231249999999f;
#else /* NO_PROTO */
    angstp = (float).43633231249999999;
#endif /* NO_PROTO */
    endptx[0] = srpx;
    endpty[0] = srpy;
    endptz[0] = srpz;
    for (hsdx = 1; hsdx <= 3; ++hsdx) {
#ifndef NO_PROTO
	ang = hsdx * angstp + .17453292500000001f;
#else /* NO_PROTO */
	ang = hsdx * angstp + (float).17453292500000001;
#endif /* NO_PROTO */
/*  set up half-space vector: */
#ifndef NO_PROTO
	hs[hsdx * 6 - 3] = 0.f;
#else /* NO_PROTO */
	hs[hsdx * 6 - 3] = (float)0.;
#endif /* NO_PROTO */
	hs[hsdx * 6 - 2] = cos(ang);
	hs[hsdx * 6 - 1] = sin(ang);
/*  set up half-space point: */
	hs[hsdx * 6 - 6] = srpx + hs[hsdx * 6 - 3];
	hs[hsdx * 6 - 5] = srpx + hs[hsdx * 6 - 2];
	hs[hsdx * 6 - 4] = srpx + hs[hsdx * 6 - 1];
/*  set up primitives: */
	endptx[1] = srpx + hs[hsdx * 6 - 3] * 3;
	endpty[1] = srpy + hs[hsdx * 6 - 2] * 3;
	endptz[1] = srpz + hs[hsdx * 6 - 1] * 3;
/*  insert polyline with endpts into structure */
	npl3 (&c__2, endptx, endpty, endptz);
/*  next hsdx */
/* L100: */
    }
/*  set element pointer to 0, insert at start of structure: */
/*    1: set global transformation 3: A1 */
/*    2: set MCV: 3 points = hspt(1:3) */
/*                3 normal vector = vec(1:3) */
/*                operator = replace */
    nsep (&c__0);
    nsgmt3 (a1);
    nsmcv3 (&c__1, &c__3, hs);
#ifndef NO_PROTO
    setmsg_("40 41 42 43 57", "When several primitive line segments intersec"
	    "t several boundary planes of a single clipping volume, the porti"
	    "ons of the segments that are not in all the half-spaces of the v"
	    "olume should be clipped.", 14L, 197L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 57", "When several primitive line segments intersec\
t several boundary planes of a single clipping volume, the portions of the s\
egments that are not in all the half-spaces of the volume should be clipped.",
	     14L, 197L);
#endif /* NO_PROTO */
    r__1 = 1 / cos(angstp);
    issdis_(&srpx, &srpy, &srpz, &r__1, a1, &c__1, "101,4", 5L);
/*  delete element #2 from structure #101 and insert */
    ndelra (&c__2, &c__2);
    nsmcv3 (&c__2, &c__1, hs);
    nsmcv3 (&c__2, &c__1, &hs[6]);
    nsmcv3 (&c__2, &c__1, &hs[12]);
#ifndef NO_PROTO
    setmsg_("40 41 42 43 50 57", "When several primitive line segments inter"
	    "sect the boundary planes of several intersected clipping volumes"
	    ", the portions of the segments that are not in the half-spaces o"
	    "f all the volumes should be clipped.", 17L, 206L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 50 57", "When several primitive line segments inter\
sect the boundary planes of several intersected clipping volumes, the portio\
ns of the segments that are not in the half-spaces of all the volumes should\
 be clipped.", 17L, 206L);
#endif /* NO_PROTO */
    r__1 = 1 / cos(angstp);
    issdis_(&srpx, &srpy, &srpz, &r__1, a1, &c__1, "101,6", 5L);
/*  replace element 2-4 in structure #101: */
    ndelra (&c__2, &c__4);
    nsmcv3 (&c__1, &c__1, hs);
    nsmcv3 (&c__1, &c__1, &hs[6]);
    nsmcv3 (&c__1, &c__1, &hs[12]);
/*  Now only half-space(3) should be operative. */
#ifndef NO_PROTO
    setmsg_("40 41 42 43 57", "When the operator of a set modelling clipping"
	    " volume element is REPLACE, only its volume should be used to cl"
	    "ip primitives and previous clipping volumes should be ignored.", 
	    14L, 171L);
#else /* NO_PROTO */
    setmsg_("40 41 42 43 57", "When the operator of a set modelling clipping\
 volume element is REPLACE, only its volume should be used to clip primitive\
s and previous clipping volumes should be ignored.", 14L, 171L);
#endif /* NO_PROTO */
    issdis_(&srpx, &srpy, &srpz, &c_b14, a1, &c__1, "101,7", 5L);
    nemst (&c__101);
    nslmt3 (a1, &c__2);
/*  set up 2D points and vectors for 4 half-spaces */
    setrvs_("0,1, 3,-3, 1,0, -3,-3, 0,-1, -3,3, -1,0, 3,3", hs2d, &hssiz, 44L)
	    ;
    nsmcv (&c__1, &c__4, hs2d);
/*  set up fill area */
    setrvs_("-2, -2, 2,  2", endptx, &endsiz, 13L);
    setrvs_("-2,  2, 2, -2", endpty, &endsiz, 13L);
    setrvs_(" 3,  3, 3,  3", endptz, &endsiz, 13L);
    nfa3 (&c__4, endptx, endpty, endptz);
    srpx = endptx[1];
    srpy = endpty[1];
    srpz = endptz[1];
#ifndef NO_PROTO
    setmsg_("40 41 42 43 49 57", "When a 2D clip volume is applied to a 3D f"
	    "ill area primitive, it should behave as if the z-coordinate of i"
	    "ts point and normal vector were zero.", 17L, 143L);
    r__1 = sqrt(2.f) * 3 / 2;
#else /* NO_PROTO */
    setmsg_("40 41 42 43 49 57", "When a 2D clip volume is applied to a 3D f\
ill area primitive, it should behave as if the z-coordinate of its point and\
 normal vector were zero.", 17L, 143L);
    r__1 = sqrt((float)2.) * 3 / 2;
#endif /* NO_PROTO */
    issdis_(&srpx, &srpy, &srpz, &r__1, a1, &c__1, "101,3", 5L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

