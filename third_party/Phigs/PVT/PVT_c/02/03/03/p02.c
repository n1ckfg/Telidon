/* fort/02/03/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static real c_b16 = 22.1f;
static real c_b17 = 2.1f;
static real c_b18 = 666.6f;
static real c_b19 = .24f;
#else /* NO_PROTO */
static real c_b16 = (float)22.1;
static real c_b17 = (float)2.1;
static real c_b18 = (float)666.6;
static real c_b19 = (float).24;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b24 = 12.2f;
static real c_b25 = 2.2f;
static real c_b27 = .25f;
static real c_b39 = 2.f;
static real c_b42 = .21f;
static real c_b47 = 3.f;
static real c_b49 = 3.2f;
static real c_b50 = .11f;
static real c_b62 = 1.f;
static real c_b65 = .1f;
static real c_b73 = -22.22f;
static real c_b80 = 4.f;
static real c_b109 = 0.f;
static real c_b124 = .95f;
#else /* NO_PROTO */
static real c_b24 = (float)12.2;
static real c_b25 = (float)2.2;
static real c_b27 = (float).25;
static real c_b39 = (float)2.;
static real c_b42 = (float).21;
static real c_b47 = (float)3.;
static real c_b49 = (float)3.2;
static real c_b50 = (float).11;
static real c_b62 = (float)1.;
static real c_b65 = (float).1;
static real c_b73 = (float)-22.22;
static real c_b80 = (float)4.;
static real c_b109 = (float)0.;
static real c_b124 = (float).95;
#endif /* NO_PROTO */
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b130 = 5.f;
static real c_b140 = -1.f;
static real c_b142 = -3.f;
static real c_b150 = 2.5f;
static real c_b198 = 1.6f;
static real c_b199 = .5f;
#else /* NO_PROTO */
static real c_b130 = (float)5.;
static real c_b140 = (float)-1.;
static real c_b142 = (float)-3.;
static real c_b150 = (float)2.5;
static real c_b198 = (float)1.6;
static real c_b199 = (float).5;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.03/02                           * */
/*  *    TEST TITLE : Basic spatial search for 3-D          * */
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

    /* System generated locals */
    integer i__1;
    real r__1;

    /* Local variables */
    static real a, b, c, d, xa[100], ya[100], za[100];
    static integer ix;
    static real xn, yn, zn;
    static integer nsz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nca3 (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nfa3 (integer *, real *, real *, real *), vec1_(real *, real *, 
	    real *, real *, real *, real *), npl3 (integer *, real *, real *, 
	    real *), npm3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nca3 (), nfa3 (), vec1_(), npl3 (), npm3 ();
#endif /* NO_PROTO */
    static real tp1x, tp1y, tp1z, tp2x, tp2y, tp2z;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx3 (real *, real *, real *, real *, real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx3 ();
#endif /* NO_PROTO */
    static real tdvi[2], tdvj[2], tdvk[2];
#ifndef NO_PROTO
    extern doublereal zval_(real *, real *);
#else /* NO_PROTO */
    extern doublereal zval_();
#endif /* NO_PROTO */
    static integer npts;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfas3 (integer *, integer *, real *, real *, 
	    real *), natr3 (real *, real *, real *, real *, real *, real *, 
	    char *, ftnlen), endit_(void), nschh (real *), inmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfas3 (), natr3 (), endit_(), nschh (), 
	    inmsg_();
#endif /* NO_PROTO */
    static real tlcxi, tlcxj, tlcxk, tlcyi, tlcyj, tlcyk, tlczi, tlczj, tlczk;

#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), isspf_(integer *, real *, 
	    real *, real *, real *, char *, ftnlen), setvs_(char *, integer *,
	     integer *, ftnlen), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), isspf_(), setvs_(), nopst ();
#endif /* NO_PROTO */
    static real dist2d, tlczi1, tlczj1, tlczk1, srp2dx, srp2dy, srp3dx, 
	    srp3dy, srp3dz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsatch (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsatch ();
#endif /* NO_PROTO */
    static integer endpts[5];
#ifndef NO_PROTO
    extern logical sphdis_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), pervec_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *), nsatal (integer *, integer *), 
	    ptplds_(real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *), crossp_(real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *), nstxal (integer *
	    , integer *), xpopph_(integer *, integer *), setrvs_(char *, real 
	    *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical sphdis_();
    extern /* Subroutine */ int initgl_(), setmsg_(), pervec_(), nsatal (), 
	    ptplds_(), crossp_(), nstxal (), xpopph_(), setrvs_();
#endif /* NO_PROTO */

/* text alignment horizontal */
/* text alignment vertical */
/*  Declare program-specific variables */
/*  Use plane: 3x + 4y - z - 7 = 0, so */
/*    z = f(x,y) = 3x + 4y - 7 */
    initgl_("02.03.03/02", 11L);
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
/*  *** *** *** ***   polymarker 3   *** *** *** *** */

/*  Build structure 101: */
/*    1.  polymarker 3: (11,1,1), (12,2,2), (22,2,0.2), (13,2,3) */
/*    2.  polymarker 3: (21,1,6), (12.3,2.3,2.3), (22,2,-0.1), (23,2,5) */

    nemst (&c__101);
    setrvs_("11, 12, 22,  13", xa, &nsz, 15L);
    setrvs_(" 1,  2,  2,   2", ya, &nsz, 15L);
    setrvs_(" 1,  2,  0.2, 3", za, &nsz, 15L);
    npm3 (&nsz, xa, ya, za);
    setrvs_("21, 12.3, 22,   23", xa, &nsz, 18L);
    setrvs_(" 1,  2.3,  2,    2", ya, &nsz, 18L);
    setrvs_(" 6,  2.3, -0.1,  5", za, &nsz, 18L);
    npm3 (&nsz, xa, ya, za);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 11", "The points of a qualifying three-dimensi"
	    "onal polymarker should be found by a two-dimensional spatial sea"
	    "rch.", 19L, 108L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 11", "The points of a qualifying three-dimensi\
onal polymarker should be found by a two-dimensional spatial search.", 19L, 
	    108L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b16, &c_b17, &c_b18, &c_b19, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 11", "The points of a qualifying three-dimension"
	    "al polymarker should be found by a three-dimensional spatial sea"
	    "rch.", 17L, 110L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 11", "The points of a qualifying three-dimension\
al polymarker should be found by a three-dimensional spatial search.", 17L, 
	    110L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b24, &c_b25, &c_b25, &c_b27, "101,2", 5L);
/*  *** *** *** ***   polyline 3   *** *** *** *** */

/*  Build structure 101: */
/*    1.  polyline 3: (2.0,2.2,0.2), (3,3,3) */
/*    2.  polyline 3: (1,1,-0.1), (3,3,-0.3), (3,3,3.1) */
    nemst (&c__101);
    setrvs_("2.0, 3", xa, &nsz, 6L);
    setrvs_("2.2, 3", ya, &nsz, 6L);
    setrvs_("0.2, 3", za, &nsz, 6L);
    npl3 (&nsz, xa, ya, za);
    setrvs_(" 1,    3,   3", xa, &nsz, 13L);
    setrvs_(" 1,    3,   3 ", ya, &nsz, 14L);
    setrvs_("-0.1, -0.3, 3.1", za, &nsz, 15L);
    npl3 (&nsz, xa, ya, za);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 12", "The line segments of a qualifying three-"
	    "dimensional polyline should be found by a two-dimensional spatia"
	    "l search.", 19L, 113L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 12", "The line segments of a qualifying three-\
dimensional polyline should be found by a two-dimensional spatial search.", 
	    19L, 113L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b39, &c_b39, &c_b18, &c_b42, "101,2", 5L);

#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 12", "The line segments of a qualifying three-di"
	    "mensional polyline should be found by a three-dimensional spatia"
	    "l search.", 17L, 115L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 12", "The line segments of a qualifying three-di\
mensional polyline should be found by a three-dimensional spatial search.", 
	    17L, 115L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b47, &c_b47, &c_b49, &c_b50, "101,2", 5L);
/*  *** *** *** ***   fill area 3   *** *** *** *** */

/*  Use plane: 3x + 4y - z - 7 = 0, so */
/*    z = f(x,y) = 3x + 4y - 7 */

/*  Build structure 101: */
/*    1.  fill area 3: (1.1,0,z), (1.1,2,z), (2,2,z), (2,0,z) */
/*    2.  fill area 3: (0,  0,z), (0,  2,z), (2,2,z), (2,0,z) */
    nemst (&c__101);
    setrvs_("1.1, 1.1, 2, 2", xa, &nsz, 14L);
    setrvs_("0,   2,   2, 0", ya, &nsz, 14L);
    i__1 = nsz;
    for (ix = 1; ix <= i__1; ++ix) {
	za[ix - 1] = zval_(&xa[ix - 1], &ya[ix - 1]);
/* L110: */
    }
    nfa3 (&nsz, xa, ya, za);
    setrvs_("0, 0, 2, 2", xa, &nsz, 10L);
    setrvs_("0, 2, 2, 0", ya, &nsz, 10L);
    i__1 = nsz;
    for (ix = 1; ix <= i__1; ++ix) {
	za[ix - 1] = zval_(&xa[ix - 1], &ya[ix - 1]);
/* L120: */
    }
    nfa3 (&nsz, xa, ya, za);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 13", "The interior of a qualifying three-dimen"
	    "sional fill area should be found by a two-dimensional spatial se"
	    "arch.", 19L, 109L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 13", "The interior of a qualifying three-dimen\
sional fill area should be found by a two-dimensional spatial search.", 19L, 
	    109L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b62, &c_b62, &c_b18, &c_b65, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 13", "The interior of a qualifying three-dimen"
	    "sional fill area should be found by a two-dimensional spatial se"
	    "arch, even when the search distance is negative.", 19L, 152L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 13", "The interior of a qualifying three-dimen\
sional fill area should be found by a two-dimensional spatial search, even w\
hen the search distance is negative.", 19L, 152L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b62, &c_b62, &c_b18, &c_b73, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 13", "The interior of a qualifying three-dimensi"
	    "onal fill area should be found by a three-dimensional spatial se"
	    "arch.", 17L, 111L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 13", "The interior of a qualifying three-dimensi\
onal fill area should be found by a three-dimensional spatial search.", 17L, 
	    111L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b62, &c_b39, &c_b80, &c_b65, "101,2", 5L);
/*  *** *** *** ***   fill area set 3   *** *** *** *** */

/*  Use plane: 3x + 4y - z - 7 = 0, so */
/*    z = f(x,y) = 3x + 4y - 7 */

/*  Build structure 101: */
/*    1.  fill area set 3: (1,0,z), (0,1,z), (1,2,z) / */
/*                         (3,2,z), (4,1,z), (3,0,z) */
/*    2.  fill area set 3: (11,2,z), (13,2,z), (13,0,z), (11,0,z)  / */
/*                         ( 1,2,z), ( 3,2,z), ( 3,0,z), ( 1,0,z) */
    nemst (&c__101);
    setrvs_("1, 0, 1, 3, 4, 3", xa, &nsz, 16L);
    setrvs_("0, 1, 2, 2, 1, 0", ya, &nsz, 16L);
    i__1 = nsz;
    for (ix = 1; ix <= i__1; ++ix) {
	za[ix - 1] = zval_(&xa[ix - 1], &ya[ix - 1]);
/* L130: */
    }
    setvs_("3,6", endpts, &npts, 3L);
    nfas3 (&npts, endpts, xa, ya, za);
    setrvs_("11, 13, 13, 11, 1, 3, 3, 1", xa, &nsz, 26L);
    setrvs_(" 2,  2,  0,  0, 2, 2, 0, 0", ya, &nsz, 26L);
    i__1 = nsz;
    for (ix = 1; ix <= i__1; ++ix) {
	za[ix - 1] = zval_(&xa[ix - 1], &ya[ix - 1]);
/* L140: */
    }
    setvs_("4,8", endpts, &npts, 3L);
    nfas3 (&npts, endpts, xa, ya, za);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 14", "The interiors of a qualifying three-dime"
	    "nsional fill area set should be found by a two-dimensional spati"
	    "al search.", 19L, 114L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 14", "The interiors of a qualifying three-dime\
nsional fill area set should be found by a two-dimensional spatial search.", 
	    19L, 114L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b39, &c_b27, &c_b18, &c_b65, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 14", "The interiors of a qualifying three-dimens"
	    "ional fill area set should be found by a three-dimensional spati"
	    "al search.", 17L, 116L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 14", "The interiors of a qualifying three-dimens\
ional fill area set should be found by a three-dimensional spatial search.", 
	    17L, 116L);
#endif /* NO_PROTO */
    r__1 = zval_(&c_b39, &c_b62);
    isspf_(&c__3, &c_b39, &c_b62, &r__1, &c_b65, "101,2", 5L);
/*  *** *** *** ***   text 3   *** *** *** *** */

/*  tdv1 =  first text direction vector = 1, 0.1, 0.2 */
#ifndef NO_PROTO
    tdvi[0] = 1.f;
    tdvj[0] = .1f;
    tdvk[0] = .2f;
#else /* NO_PROTO */
    tdvi[0] = (float)1.;
    tdvj[0] = (float).1;
    tdvk[0] = (float).2;
#endif /* NO_PROTO */
/*  tdv2 = second text direction vector = 0.1, 1, 0.2 */
#ifndef NO_PROTO
    tdvi[1] = .1f;
    tdvj[1] = 1.f;
    tdvk[1] = .2f;
#else /* NO_PROTO */
    tdvi[1] = (float).1;
    tdvj[1] = (float)1.;
    tdvk[1] = (float).2;
#endif /* NO_PROTO */
/*  tlcx = text local cooordinate-x = tdv1 */
    tlcxi = tdvi[0];
    tlcxj = tdvj[0];
    tlcxk = tdvk[0];
/*  tlcy = text local cooordinate-y = vector in tdv-plane, */
/*  perpendicular to tlcx, and such that tlcy . tdv2 > 0 */
    pervec_(&tlcxi, &tlcxj, &tlcxk, &tdvi[1], &tdvj[1], &tdvk[1], &tlcyi, &
	    tlcyj, &tlcyk);
/*  tlcz = perpendicular to text plane = tlcx X tlcy */
    crossp_(&tlcxi, &tlcxj, &tlcxk, &tlcyi, &tlcyj, &tlcyk, &tlczi, &tlczj, &
	    tlczk);
/*  tlcz1 = tlcz, normalized to unit length */
    vec1_(&tlczi, &tlczj, &tlczk, &tlczi1, &tlczj1, &tlczk1);
/*  tp2  = text position 2 = 3,4,0.1 */
#ifndef NO_PROTO
    tp2x = 3.f;
    tp2y = 4.f;
    tp2z = .1f;
#else /* NO_PROTO */
    tp2x = (float)3.;
    tp2y = (float)4.;
    tp2z = (float).1;
#endif /* NO_PROTO */
/*  tp1  = text position 1 = tp2 + tlcz1 (1.0 away from tp2) */
    tp1x = tp2x + tlczi1;
    tp1y = tp2y + tlczj1;
    tp1z = tp2z + tlczk1;
/*  a,b,c,d = coefficients of text plane containing tp2: ax+by+cz+d=0 */
    a = tlczi;
    b = tlczj;
    c = tlczk;
    d = -(doublereal)(a * tp2x + b * tp2y + c * tp2z);
/*  srp2d   = 2D search reference point = (tp2x - 0.3, tp2y - 0.3) */
#ifndef NO_PROTO
    srp2dx = tp2x - .3f;
    srp2dy = tp2y - .3f;
#else /* NO_PROTO */
    srp2dx = tp2x - (float).3;
    srp2dy = tp2y - (float).3;
#endif /* NO_PROTO */
/*  dist2d  = distance of srp2d from tp2 plane; since this plane is */
/*  close to z=0 plane, the 2D search reference point will be closer */
/*  to it than to the text plane of tp1, which is about z=1. */
    ptplds_(&srp2dx, &srp2dy, &c_b109, &a, &b, &c, &d, &xn, &yn, &zn, &dist2d)
	    ;
/*  Build structure 101: */
/*    1.  set character height = 1.0 */
/*    2.  set text alignment   = (CENTRE, HALF) */
/*    3.  text 3: "Viva PHIGS!" at tp1 with tdv1,tdv2 */
/*    4.  text 3: "Viva PHIGS!" at tp2 with tdv1,tdv2 */
    nemst (&c__101);
    nschh (&c_b62);
    nstxal (&c__2, &c__3);
    ntx3 (&tp1x, &tp1y, &tp1z, tdvi, tdvj, tdvk, "Viva PHIGS!", 11L);
    ntx3 (&tp2x, &tp2y, &tp2z, tdvi, tdvj, tdvk, "Viva PHIGS!", 11L);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 15", "The text extent rectangle of a qualifyin"
	    "g three-dimensional text primitive should be found by a two-dime"
	    "nsional spatial search.", 19L, 127L);
    r__1 = dist2d * 1.1f;
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 15", "The text extent rectangle of a qualifyin\
g three-dimensional text primitive should be found by a two-dimensional spat\
ial search.", 19L, 127L);
    r__1 = dist2d * (float)1.1;
#endif /* NO_PROTO */
    isspf_(&c__2, &srp2dx, &srp2dy, &c_b18, &r__1, "101,4", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 15", "The text extent rectangle of a qualifying "
	    "three-dimensional text primitive should be found by a three-dime"
	    "nsional spatial search.", 17L, 129L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 15", "The text extent rectangle of a qualifying \
three-dimensional text primitive should be found by a three-dimensional spat\
ial search.", 17L, 129L);
#endif /* NO_PROTO */
/*  srp3d   = 3D search reference point = (tp2x + 0.3, tp2y + 0.3, z) */
/*            where z puts srp3d in a,b,c,d plane */
#ifndef NO_PROTO
    srp3dx = tp2x + .3f;
    srp3dy = tp2y + .3f;
#else /* NO_PROTO */
    srp3dx = tp2x + (float).3;
    srp3dy = tp2y + (float).3;
#endif /* NO_PROTO */
    srp3dz = -(doublereal)(a * srp3dx + b * srp3dy + d) / c;
/*  dist3d  = 0.95 (because text planes are 1.0 apart - see tp1 above) */
    isspf_(&c__3, &srp3dx, &srp3dy, &srp3dz, &c_b124, "101,4", 5L);
/*  *** *** *** ***   annotation text 3   *** *** *** *** */

/*  Build structure 101: */
/*    1.  set annotation text character height = 1.0 */
/*    2.  set annotation text alignment        = (RIGHT, TOP) */
/*    3.  annotation text relative 3: "Viva PHIGS!" at 5,0,0 */
/*           with offset = 3,-2,1 */
/*    4.  annotation text relative 3: "Viva PHIGS!" at 5,5,1 */
/*           with offset = -1,2,-3 */
    nemst (&c__101);
    nsatch (&c_b62);
    nsatal (&c__3, &c__1);
    natr3 (&c_b130, &c_b109, &c_b109, &c_b109, &c_b130, &c_b62, "Viva PHIGS!",
	     11L);
    natr3 (&c_b130, &c_b130, &c_b62, &c_b140, &c_b39, &c_b142, "Viva PHIGS!", 
	    11L);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 16", "The annotation reference point of a qual"
	    "ifying three-dimensional annotation text should be found by a tw"
	    "o-dimensional spatial search.", 19L, 133L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 16", "The annotation reference point of a qual\
ifying three-dimensional annotation text should be found by a two-dimensiona\
l spatial search.", 19L, 133L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b130, &c_b47, &c_b18, &c_b150, "101,4", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 16", "The annotation reference point of a qualif"
	    "ying three-dimensional annotation text should be found by a thre"
	    "e-dimensional spatial search.", 17L, 135L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 16", "The annotation reference point of a qualif\
ying three-dimensional annotation text should be found by a three-dimensiona\
l spatial search.", 17L, 135L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b130, &c_b47, &c_b62, &c_b17, "101,4", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 16", "The annotation reference point of a qualif"
	    "ying three-dimensional annotation text should be found by a thre"
	    "e-dimensional spatial search, even when the search distance is z"
	    "ero.", 17L, 174L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 16", "The annotation reference point of a qualif\
ying three-dimensional annotation text should be found by a three-dimensiona\
l spatial search, even when the search distance is zero.", 17L, 174L);
#endif /* NO_PROTO */
    isspf_(&c__3, &c_b130, &c_b130, &c_b62, &c_b109, "101,4", 5L);
/*  *** *** *** ***   cell array 3   *** *** *** *** */
/*  Use plane: 3x + 4y - z - 7 = 0, so */
/*    z = f(x,y) = 3x + 4y - 7 */

/*  colia = color index array =  1 0 1 */
/*                               0 1 1 */
/*  Build structure 101: */
/*    1.  cell array 3: colia with corners */
/*                      P=(1.1,1.1,z), Q=(0.6,2.0,z), R=(2.0,0.6,z) */
/*    2.  cell array 3: colia with corners */
/*                      P=(1.2,1.3,z), Q=(1.5,0.5,z), R=(0.5,1.5,z) */
    nemst (&c__101);
    setrvs_("1.1, 0.6, 2.0", xa, &nsz, 13L);
    setrvs_("1.1, 2.0, 0.6", ya, &nsz, 13L);
    i__1 = nsz;
    for (ix = 1; ix <= i__1; ++ix) {
	za[ix - 1] = zval_(&xa[ix - 1], &ya[ix - 1]);
/* L150: */
    }
    nca3 (xa, ya, za, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, colia);
    setrvs_("1.2, 1.5, 0.5", xa, &nsz, 13L);
    setrvs_("1.3, 0.5, 1.5", ya, &nsz, 13L);
    i__1 = nsz;
    for (ix = 1; ix <= i__1; ++ix) {
	za[ix - 1] = zval_(&xa[ix - 1], &ya[ix - 1]);
/* L160: */
    }
    nca3 (xa, ya, za, &c__3, &c__2, &c__1, &c__1, &c__3, &c__2, colia);
#ifndef NO_PROTO
    setmsg_("1 2 4 5 6 7 9 10 17", "The parallelogram of a qualifying three-"
	    "dimensional cell array should be found by a two-dimensional spat"
	    "ial search.", 19L, 115L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 6 7 9 10 17", "The parallelogram of a qualifying three-\
dimensional cell array should be found by a two-dimensional spatial search.", 
	    19L, 115L);
#endif /* NO_PROTO */
    isspf_(&c__2, &c_b62, &c_b62, &c_b18, &c_b65, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("2 4 5 6 7 9 10 17", "The parallelogram of a qualifying three-di"
	    "mensional cell array should be found by a three-dimensional spat"
	    "ial search.", 17L, 117L);
#else /* NO_PROTO */
    setmsg_("2 4 5 6 7 9 10 17", "The parallelogram of a qualifying three-di\
mensional cell array should be found by a three-dimensional spatial search.", 
	    17L, 117L);
#endif /* NO_PROTO */
    r__1 = zval_(&c_b198, &c_b199);
    isspf_(&c__3, &c_b198, &c_b199, &r__1, &c_b50, "101,2", 5L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

