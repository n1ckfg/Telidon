/* fort//06/01/02/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b6 = 2.f;
static real c_b7 = 1.f;
#else /* NO_PROTO */
static real c_b6 = (float)2.;
static real c_b7 = (float)1.;
#endif /* NO_PROTO */
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b12 = 0.f;
static real c_b18 = 9.f;
#else /* NO_PROTO */
static real c_b12 = (float)0.;
static real c_b18 = (float)9.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__102 = 102;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/08                           * */
/*  *    TEST TITLE : Miscellaneous tests of modelling      * */
/*  *                 clipping                              * */
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
    static real r1[16]	/* was [4][4] */ = { .7061f,-.2336f,.2953f,-.2673f,
	    -.2344f,.828f,-.2632f,-.2501f,.2709f,.0524f,.6326f,.1435f,.3407f,
	    .3902f,.1875f,1.252f };
#else /* NO_PROTO */
    static real r1[16]	/* was [4][4] */ = { (float).7061,(float)-.2336,(
	    float).2953,(float)-.2673,(float)-.2344,(float).828,(float)-.2632,
	    (float)-.2501,(float).2709,(float).0524,(float).6326,(float).1435,
	    (float).3407,(float).3902,(float).1875,(float)1.252 };
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    real r__1;
    char ch__1[9];

    /* Builtin functions */
#ifndef NO_PROTO
    double cos(doublereal), sin(doublereal);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    double cos(), sin();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static real a, b, c, d, u, a1[9]	/* was [3][3] */, p1[9]	/* was [3][3] 
	    */, s2[9]	/* was [3][3] */, p9[9]	/* was [3][3] */, xa[20], hs[
	    6]	/* was [6][1] */, ya[20], px, py, pz, ux, uy, uz, ang, idm[9]	
	    /* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int esc_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esc_();
#endif /* NO_PROTO */
    static integer ipl;
#ifndef NO_PROTO
    extern /* Subroutine */ int ero_(real *, real *), etr_(real *, real *, 
	    real *), npl (integer *, real *, real *), npm (integer *, real *, 
	    real *), vec1_(real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ero_(), etr_(), npl (), npm (), vec1_();
#endif /* NO_PROTO */
    static real hs2d[4]	/* was [4][1] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 ();
#endif /* NO_PROTO */
    static integer asiz, nopl, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *), issab_(real *, 
	    real *, real *, real *, char *, integer *, integer *, char *, 
	    ftnlen, ftnlen), endit_(void), inmsg_(char *, ftnlen), nclst (
	    void), nsmcv (integer *, integer *, real *), nsgmt (real *), 
	    nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_(), issab_(), endit_(), inmsg_(), 
	    nclst (), nsmcv (), nsgmt (), nslmt ();
#endif /* NO_PROTO */
    static integer hssiz;
    static real inptx[1], inpty[1], inptz[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsmcv3 (integer *, integer 
	    *, real *), nsgmt3 (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsmcv3 (), nsgmt3 ();
#endif /* NO_PROTO */
    static real anginc;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), nqmclf (
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), nqmclf ();
#endif /* NO_PROTO */
    static integer errind, ndpmcv, navmco;
    static real radius, nsdist;
#ifndef NO_PROTO
    extern logical sphdis_(integer *);
#else /* NO_PROTO */
    extern logical sphdis_();
#endif /* NO_PROTO */
    static char expelm[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), tranhs_(real *, real 
	    *, real *, real *, real *, real *), setmsg_(char *, char *, 
	    ftnlen, ftnlen), xpopph_(integer *, integer *), setrvs_(char *, 
	    real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), tranhs_(), setmsg_(), xpopph_(), 
	    setrvs_();
#endif /* NO_PROTO */
    static real outptx[1], outpty[1], outptz[1];

    /* Fortran I/O blocks */
    static icilist io___41 = { 0, expelm, 0, "(I5)", 5, 1 };


/* modelling clipping operator */
/* clipping indicator */
/*                noclip      clip */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    initgl_("06.01.02/08", 11L);
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
/*  effects of modelling clipping. */
/*  Set up structure #101 */
    nopst (&c__101);
/*  In WC, polyline segment from (3,2) to (1,2) is clipped at 2,2 by */
/*  the MCV set up in element #2. */
/*  S2 = matrix for transformation to scale by 2 in x-direction */
    esc_(&c_b6, &c_b7, s2);
    nsgmt (s2);
/*  2D half-space */
    setrvs_("2,0, 2,1", hs2d, &hssiz, 8L);
    nsmcv (&c__1, &c__1, hs2d);
/*  P1 = matrix for transformation to shift by 1 in x-direction */
    etr_(&c_b7, &c_b12, p1);
    nsgmt (p1);
/*  polyline coordinates */
    setrvs_("2,0,2,0,2,0", xa, &asiz, 11L);
    setrvs_("1,1,2,2,3,3", ya, &asiz, 11L);
    npl (&asiz, xa, ya);
/*  R1 = matrix for random transformation */
    nsgmt3 (r1);
/*  hsmcpt = half-space point in MC  = -1,0,1 */
/*  hsmcvc = half-space vector in MC =  2,3,4 */
    setrvs_("-1,0,1,  2,3,4", hs, &hssiz, 14L);
    nsmcv3 (&c__1, &c__1, hs);
/*  P9 = matrix for transformation to shift by 9 in x-direction */
    etr_(&c_b18, &c_b12, p9);
    nsgmt (p9);
/*  a,b,c,d = coefficients for WC boundary plane when R1 is applied */
/*  to the MC half-space defined by hsmcpt and hsmcvc. */
    tranhs_(hs, r1, &a, &b, &c, &d);
/*  px,py,pz = the WC point where the line */
/*    x = a*u */
/*    y = b*u */
/*    z = 5 */
/*  intersects the a*x + b*y + c*z + d = 0 plane */
    u = (c * -5 - d) / (a * a + b * b);
    px = a * u;
    py = b * u;
#ifndef NO_PROTO
    pz = 5.f;
#else /* NO_PROTO */
    pz = (float)5.;
#endif /* NO_PROTO */
/*  nsdist = nominal search distance */
#ifndef NO_PROTO
    nsdist = .1f;
#else /* NO_PROTO */
    nsdist = (float).1;
#endif /* NO_PROTO */
/*  ux,uy,uz = unit vector parallel to a,b,c */
    vec1_(&a, &b, &c, &ux, &uy, &uz);
/*  inpt = WC point inside volume */
    inptx[0] = px + nsdist * ux;
    inpty[0] = py + nsdist * uy;
    inptz[0] = pz + nsdist * uz;
/*  outpt = WC point outside volume */
    outptx[0] = px - nsdist * ux;
    outpty[0] = py - nsdist * uy;
    outptz[0] = pz - nsdist * uz;
    npm3 (&c__1, outptx, outpty, outptz);
    npm3 (&c__1, inptx, inpty, inptz);
    nclst ();
#ifndef NO_PROTO
    setmsg_("15 17 18 40 42 43 49 57", "When traversal causes different curr"
	    "ent modelling transformations to be applied in the generation of"
	    " a polyline and a current MCV, the clipping should be performed "
	    "relative to WC space.", 23L, 185L);
#else /* NO_PROTO */
    setmsg_("15 17 18 40 42 43 49 57", "When traversal causes different curr\
ent modelling transformations to be applied in the generation of a polyline \
and a current MCV, the clipping should be performed relative to WC space.", 
	    23L, 185L);
#endif /* NO_PROTO */
/*  perform ISS with srp = (2-nsdist,2), clipping ON, starting at 101,0, 
*/
/*    and sdist just below and above nsdist */
/*  pass/fail depending on (found path = first empty and then = 101,4) */
#ifndef NO_PROTO
    r__1 = 2.f - nsdist;
#else /* NO_PROTO */
    r__1 = (float)2. - nsdist;
#endif /* NO_PROTO */
    issab_(&r__1, &c_b6, &c_b12, &nsdist, "101,0", &c__1, &c__1, "101,4", 5L, 
	    5L);
#ifndef NO_PROTO
    setmsg_("15 17 40 42 43 57", "When traversal causes a perspective curren"
	    "t modelling transformation to be applied in the generation of a "
	    "current MCV, and a different current modelling transformation to"
	    " be applied in the generation of a polymarker, the clipping shou"
	    "ld be performed relative to WC space.", 17L, 271L);
#else /* NO_PROTO */
    setmsg_("15 17 40 42 43 57", "When traversal causes a perspective curren\
t modelling transformation to be applied in the generation of a current MCV,\
 and a different current modelling transformation to be applied in the gener\
ation of a polymarker, the clipping should be performed relative to WC space."
	    , 17L, 271L);
#endif /* NO_PROTO */
/*  perform ISS with srp = outpt, clipping ON, starting at 101,0 */
/*    and sdist just below and above 2*nsdist */
/*  pass/fail depending on (found path = first empty and then = 101,9) */
    r__1 = nsdist * 2;
    issab_(outptx, outpty, outptz, &r__1, "101,0", &c__1, &c__1, "101,9", 5L, 
	    5L);
/*  To test several boundary planes, set up a sequence of polymarkers */
/*  all on the unit circle, and arrange each clipping plane so as to */
/*  eliminate just one of them, by slicing off the edge of the */
/*  circle.  There will be only one polymarker left unclipped, and */
/*  this is the one to be found. */

/*  <inquire modelling clipping facilities> returns */
/*     ndpmcv = number of distinct planes for modelling clipping volume */

    nqmclf (&c__0, &errind, &ndpmcv, &navmco, &idum1);
    chkinq_("pqmclf", &errind, 6L);
/*  number of planes to be tested */
    nopl = min(50,ndpmcv);
/*  angle increment */
#ifndef NO_PROTO
    anginc = 6.2831853000000004f / (nopl + 1);
#else /* NO_PROTO */
    anginc = (float)6.2831853000000004 / (nopl + 1);
#endif /* NO_PROTO */
/*  distance from origin of boundary planes */
    radius = (cos(anginc) + 1) / 2;
    setrvs_("0,0,-1,0", hs2d, &hssiz, 8L);
    hs2d[0] = radius;
/*  A1  = matrix for transformation to rotate by anginc */
    ero_(&anginc, a1);
/*  idm = identity matrix */
    idmat_(&c__3, idm);
/*  Set up structure #102 */
    nopst (&c__102);
/*  set up MCV to clip away all points except 1,0,0 */
    i__1 = nopl;
    for (ipl = 1; ipl <= i__1; ++ipl) {
	nslmt (a1, &c__0);
	nsmcv (&c__2, &c__1, hs2d);
/* L210: */
    }
    nslmt (idm, &c__2);
    i__1 = nopl + 1;
    for (ipl = 1; ipl <= i__1; ++ipl) {
	ang = anginc * ipl;
	xa[0] = cos(ang);
	ya[0] = sin(ang);
	npm (&c__1, xa, ya);
/* L220: */
    }
/*  close structure #102 */
    nclst ();
#ifndef NO_PROTO
    setmsg_("8 17 18 35 40 42 43 49 57", "During traversal, it should be pos"
	    "sible to construct the current MCV from as many half-spaces as a"
	    "re reported available by <inquire modelling clipping facilities>."
	    , 25L, 163L);
#else /* NO_PROTO */
    setmsg_("8 17 18 35 40 42 43 49 57", "During traversal, it should be pos\
sible to construct the current MCV from as many half-spaces as are reported \
available by <inquire modelling clipping facilities>.", 25L, 163L);
#endif /* NO_PROTO */
/*  expected element */
    s_wsfi(&io___41);
    i__1 = nopl * 3 + 2;
    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
    e_wsfi();
/*  perform ISS with srp = 0,0, clipping ON, starting at 102,0 */
/*    and sdist just below and above 1.0 */
/* pass/fail depending on (found path = first empty and then = 102,expelm)
*/
/* Writing concatenation */
    i__2[0] = 4, a__1[0] = "102,";
    i__2[1] = 5, a__1[1] = expelm;
    s_cat(ch__1, a__1, i__2, &c__2, 9L);
    issab_(&c_b12, &c_b12, &c_b12, &c_b7, "102,0", &c__1, &c__1, ch__1, 5L, 
	    9L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

