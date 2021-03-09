/* fort/04/03/04/01/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__801 = 801;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b10 = .025f;
static real c_b11 = 0.f;
#else /* NO_PROTO */
static real c_b10 = (float).025;
static real c_b11 = (float)0.;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__14 = 14;
static integer c__102 = 102;
static integer c__2 = 2;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__103 = 103;
#ifndef NO_PROTO
static real c_b60 = .25f;
static real c_b62 = .066666666666666666f;
#else /* NO_PROTO */
static real c_b60 = (float).25;
static real c_b62 = (float).066666666666666666;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.04.01/04                        * */
/*  *    TEST TITLE : Network inheritance and               * */
/*  *                 initialization                        * */
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

    static integer colid[9]	/* was [3][3] */ = { 0,1,0,1,0,1,0,0,1 };

    /* System generated locals */
    real r__1;

    /* Local variables */
    static real u, z;
#ifndef NO_PROTO
    extern /* Subroutine */ int nca (real *, real *, real *, real *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    );
#else /* NO_PROTO */
    extern /* Subroutine */ int nca ();
#endif /* NO_PROTO */
    static integer hes[3], his[3];
    static real xca1, xca2, yca1, yca2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nads (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nads ();
#endif /* NO_PROTO */
    static integer hesn;
    static real xact;
    static integer hisn, perm[14], txci, ives[3];
    static real npcx;
    static integer ivis[3];
    static real npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nres (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nres ();
#endif /* NO_PROTO */
    static real xppl[2], xexp, xppm[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */
    static integer names[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nschh (real *), nscmd (integer *
	    , integer *), wcnpc_(real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nschh (), nscmd (), wcnpc_();
#endif /* NO_PROTO */
    static real xfill[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nbltm (real *, real *, real *, real *, real *,
	     real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nbltm ();
#endif /* NO_PROTO */
    static integer ivesn;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
#endif /* NO_PROTO */
    static integer ivisn;
    static real xform[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt (real *, integer *), nexst (integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), nopst (integer *), 
	    nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt (), nexst (), setvs_(), nopst (), 
	    nsvwi ();
#endif /* NO_PROTO */
    static real fxpty;
#ifndef NO_PROTO
    extern /* Subroutine */ int rn1shf_(integer *, integer *), chkinq_(char *,
	     integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int rn1shf_(), chkinq_();
#endif /* NO_PROTO */
    static real scaley;
#ifndef NO_PROTO
    extern /* Subroutine */ int numlab_(integer *, real *, real *, real *), 
	    setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int numlab_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, picstr, namsiz;
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */
    static real npcpwc, shifty, xfills[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nshlft (integer *, integer *, 
	    integer *, integer *, integer *), nsivft (integer *, integer *, 
	    integer *, integer *, integer *), nsatch (real *), nstxal (
	    integer *, integer *), nsatal (integer *, integer *), locppl_(
	    integer *, real *), locppm_(integer *, real *), locint_(integer *,
	     real *), loctxt_(integer *, real *), locatx_(integer *, real *), 
	    loctri_(integer *, real *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), dchpfv_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nshlft (), 
	    nsivft (), nsatch (), nstxal (), nsatal (), locppl_(), locppm_(), 
	    locint_(), loctxt_(), locatx_(), loctri_(), setmsg_(), dchpfv_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/*  composition type */
/*                preconcatenate  postconcatenate  replace */
/* colour model */
/* text alignment horizontal */
/* text alignment vertical */
    initgl_("04.03.04.01/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nscmd (&globnu_1.wkid, &c__1);

/*  Five distinct values for nameset are set up and propagated */
/*  throughout the network.  The first value is the system default */
/*  from the PDT. Note that structure #104 is executed by both #103 */
/*  and #101. Actual results are displayed on the left, expected */
/*  results on the right, with the 14th deliberately made incorrect. */

/*  default = null */
/*    |                  102 */
/*    |                 /  prim 2 */
/*    |               /    nmset = {3,4,5}  {3,4,5} */
/*    V         null/      exec 103---------------103 */
/*  101           /        prim 8                   prim 3 */
/*    prim 1    /                                   nmset = {1,6} */
/*    exec 102/                                     prim 4 */
/*    prim 9                                        exec 104\ */
/*    nmset = {2,3}                                 prim 7    \ {1,6} */
/*    prim 10                                                   \ */
/*    transform             {2,3}                                 \ */
/*    exec 104-----------------------------------------------------104 */
/*   un-transform                                                   prim 5
/11*/
/*   prim 13                                                        nmset 
= {5,6}/{2,3,5}*/
/*   prim 14                                                        prim 6
/12*/
/*    exec 105---------->105 */
/*                         expected values */

/*  nameset    attribute */
/*  -------    --------- */
/*  null       normal */
/*  {2,3}      invisible */
/*  {3,4,5}    highlighted */
/*  {1,6}      invisible */
/*  {5,6}      normal */
/*  {2,3,5}    highlighted */
/*  {7}        normal */

/*  set highlighting filter: */
/*     inclusion set = {2,3,5} */
/*     exclusion set = {6} */
    setvs_("2, 3, 5", his, &hisn, 7L);
    setvs_("6", hes, &hesn, 1L);
    nshlft (&globnu_1.wkid, &hisn, his, &hesn, hes);

/*  set invisibility filter: */
/*     inclusion set = {3,6} */
/*     exclusion set = {5} */
    setvs_("3, 6", ivis, &ivisn, 4L);
    setvs_("5", ives, &ivesn, 1L);
    nsivft (&globnu_1.wkid, &ivisn, ivis, &ivesn, ives);
    nschh (&c_b10);
    wcnpc_(&c_b11, &c_b11, &npcx, &npcy, &npcpwc);
#ifndef NO_PROTO
    r__1 = npcpwc * .025f;
#else /* NO_PROTO */
    r__1 = npcpwc * (float).025;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nstxal (&c__1, &c__3);
    nsatal (&c__1, &c__3);

/*  randomize location of primitives */
    rn1shf_(&c__14, perm);
#ifndef NO_PROTO
    xact = .4f;
    xppm[0] = xact + .05f;
#else /* NO_PROTO */
    xact = (float).4;
    xppm[0] = xact + (float).05;
#endif /* NO_PROTO */
    xppl[0] = xact;
#ifndef NO_PROTO
    xppl[1] = xppl[0] + .1f;
#else /* NO_PROTO */
    xppl[1] = xppl[0] + (float).1;
#endif /* NO_PROTO */
    xfill[0] = xact;
    xfill[1] = xfill[0];
#ifndef NO_PROTO
    xfill[2] = xfill[1] + .1f;
#else /* NO_PROTO */
    xfill[2] = xfill[1] + (float).1;
#endif /* NO_PROTO */
    xfill[3] = xfill[2];
#ifndef NO_PROTO
    xfills[0] = xact + .05f;
#else /* NO_PROTO */
    xfills[0] = xact + (float).05;
#endif /* NO_PROTO */
    xfills[1] = xact;
#ifndef NO_PROTO
    xfills[2] = xact + .1f;
#else /* NO_PROTO */
    xfills[2] = xact + (float).1;
#endif /* NO_PROTO */
    xca1 = xact;
#ifndef NO_PROTO
    xca2 = xact + .15f;
#else /* NO_PROTO */
    xca2 = xact + (float).15;
#endif /* NO_PROTO */

/*  polyline 1 (order within traversal) */
    locppl_(perm, xppl);
/*  execute 102 */
    nexst (&c__102);
/*  polymarker 9 */
    locppm_(&perm[8], xppm);
/*  add names to set: 2,3 */
    setvs_("2, 3", names, &namsiz, 4L);
    nads (&namsiz, names);
/*  fill area 10 */
    locint_(&perm[9], xfill);
/*  set local transformation to make primitives 11,12 distinguishable */
/*    from 5,6 */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    fxpty = ylocel_(&perm[4]);
    shifty = ylocel_(&perm[10]) - ylocel_(&perm[4]);
    scaley = (ylocel_(&perm[11]) - ylocel_(&perm[10])) / (ylocel_(&perm[5]) - 
	    ylocel_(&perm[4]));
    nbltm (&z, &fxpty, &z, &shifty, &z, &u, &scaley, &errind, xform);
    chkinq_("pbltm", &errind, 5L);
    nslmt (xform, &c__2);
/*  execute 104 */
    nexst (&c__104);
/*  re-set local transformation to identity */
    idmat_(&c__3, xform);
    nslmt (xform, &c__2);
/*  text 13 */
    loctxt_(&perm[12], &xact);
/*  text 14 */
    loctxt_(&perm[13], &xact);
    setvs_("2, 3", names, &namsiz, 4L);
    nres (&namsiz, names);
/*  execute 105 */
    nexst (&c__105);
    nclst ();

/*  structure #102 */
    nopst (&c__102);
/*  cell array 2 */
#ifndef NO_PROTO
    yca1 = ylocel_(&perm[1]) - .02f;
    yca2 = yca1 + .035f;
#else /* NO_PROTO */
    yca1 = ylocel_(&perm[1]) - (float).02;
    yca2 = yca1 + (float).035;
#endif /* NO_PROTO */
    nca (&xca1, &yca1, &xca2, &yca2, &c__3, &c__3, &c__1, &c__1, &c__3, &c__3,
	     colid);
/*  add names to set: 3,4,5 */
    setvs_("3, 4, 5", names, &namsiz, 7L);
    nads (&namsiz, names);
/*  execute 103 */
    nexst (&c__103);
/*  annotation text 8 */
    locatx_(&perm[7], &xact);
    nclst ();

/*  structure #103 */
    nopst (&c__103);
/*  polyline 3 */
    locppl_(&perm[2], xppl);
/*  add names to set: 1,6; remove names from set: 3,4,5 */
    setvs_("1, 6", names, &namsiz, 4L);
    nads (&namsiz, names);
    setvs_("3, 4, 5", names, &namsiz, 7L);
    nres (&namsiz, names);
/*  polymarker 4 */
    locppm_(&perm[3], xppm);
/*  execute 104 */
    nexst (&c__104);
/*  polyline 7 */
    locppl_(&perm[6], xppl);
    nclst ();

/*  structure #104 */
    nopst (&c__104);
/*  fill area set 5 / 11 */
    locint_(&perm[4], xfill);
/*  remove names from set: 1; add names to set: 5 */
    setvs_("1", names, &namsiz, 1L);
    nres (&namsiz, names);
    setvs_("5", names, &namsiz, 1L);
    nads (&namsiz, names);
/*  fill area  6 / 12 */
    loctri_(&perm[5], xfills);
    nclst ();

/*  Expected attributes (except #14, whose actual nameset should be {2,3} 
*/

/*  structure #105 */
    nopst (&c__105);
/*  sequence #   primitive         nameset        attribute */
/*  ----------   ---------         -------        ---------- */
/*     01        polyline          null           normal */
/*     02        cell array        null           normal */
/*     03        polyline          {3,4,5}        highlighted */
/*     04        polymarker        {1,6}          invisible */
/*     05        fill area set     {1,6}          invisible */
/*     06        fill area         {5,6}          normal */
/*     07        polyline          {1,6}          invisible */
/*     08        annotation text   {3,4,5}        highlighted */
/*     09        polymarker        null           normal */
/*     10        fill area         {2,3}          invisible */
/*     11        fill area set     {2,3}          invisible */
/*     12        fill area         {2,3,5}        highlighted */
/*     13        text              {2,3}          invisible */
/*     14        text              {7}            normal */

#ifndef NO_PROTO
    xexp = .7f;
    xppm[0] = xexp + .05f;
#else /* NO_PROTO */
    xexp = (float).7;
    xppm[0] = xexp + (float).05;
#endif /* NO_PROTO */
    xppl[0] = xexp;
#ifndef NO_PROTO
    xppl[1] = xppl[0] + .1f;
#else /* NO_PROTO */
    xppl[1] = xppl[0] + (float).1;
#endif /* NO_PROTO */
    xfill[0] = xexp;
    xfill[1] = xfill[0];
#ifndef NO_PROTO
    xfill[2] = xfill[1] + .1f;
#else /* NO_PROTO */
    xfill[2] = xfill[1] + (float).1;
#endif /* NO_PROTO */
    xfill[3] = xfill[2];
#ifndef NO_PROTO
    xfills[0] = xexp + .05f;
#else /* NO_PROTO */
    xfills[0] = xexp + (float).05;
#endif /* NO_PROTO */
    xfills[1] = xexp;
#ifndef NO_PROTO
    xfills[2] = xexp + .1f;
#else /* NO_PROTO */
    xfills[2] = xexp + (float).1;
#endif /* NO_PROTO */
    xca1 = xexp;
#ifndef NO_PROTO
    xca2 = xexp + .15f;
#else /* NO_PROTO */
    xca2 = xexp + (float).15;
#endif /* NO_PROTO */
    locppl_(perm, xppl);
#ifndef NO_PROTO
    yca1 = ylocel_(&perm[1]) - .02f;
    yca2 = yca1 + .035f;
#else /* NO_PROTO */
    yca1 = ylocel_(&perm[1]) - (float).02;
    yca2 = yca1 + (float).035;
#endif /* NO_PROTO */
    nca (&xca1, &yca1, &xca2, &yca2, &c__3, &c__3, &c__1, &c__1, &c__3, &c__3,
	     colid);
    setvs_("3, 4, 5", names, &namsiz, 7L);
    nads (&namsiz, names);
    locppl_(&perm[2], xppl);
    nres (&namsiz, names);
    setvs_("1, 6", names, &namsiz, 4L);
    nads (&namsiz, names);
    locppm_(&perm[3], xppm);
    locint_(&perm[4], xfill);
    nres (&namsiz, names);
    setvs_("5, 6", names, &namsiz, 4L);
    nads (&namsiz, names);
    loctri_(&perm[5], xfills);
    nres (&namsiz, names);
    setvs_("1, 6", names, &namsiz, 4L);
    nads (&namsiz, names);
    locppl_(&perm[6], xppl);
    nres (&namsiz, names);
    setvs_("3, 4, 5", names, &namsiz, 7L);
    nads (&namsiz, names);
    locatx_(&perm[7], &xexp);
    nres (&namsiz, names);
    locppm_(&perm[8], xppm);
    setvs_("2, 3", names, &namsiz, 4L);
    nads (&namsiz, names);
    locint_(&perm[9], xfill);
    locint_(&perm[10], xfill);
    nres (&namsiz, names);
    setvs_("2, 3, 5", names, &namsiz, 7L);
    nads (&namsiz, names);
    loctri_(&perm[11], xfills);
    nres (&namsiz, names);
    setvs_("2, 3", names, &namsiz, 4L);
    nads (&namsiz, names);
    loctxt_(&perm[12], &xexp);
    nres (&namsiz, names);
    setvs_("7", names, &namsiz, 1L);
    nads (&namsiz, names);
    loctxt_(&perm[13], &xexp);
    r__1 = ylocel_(&c__1);
    numlab_(&c__14, &c_b60, &r__1, &c_b62);
    nclst ();
#ifndef NO_PROTO
    setmsg_("1 4 11 12 13 14 15", "The nameset attribute for the all primiti"
	    "ves should be saved and restored by <execute structure> during t"
	    "raversal.", 18L, 114L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR NAMESET: Which pair of primit"
	    "ives does NOT match?", &c__14, &perm[13], 83L);
#else /* NO_PROTO */
    setmsg_("1 4 11 12 13 14 15", "The nameset attribute for the all primiti\
ves should be saved and restored by <execute structure> during traversal.", 
	    18L, 114L);
    dchpfv_("STRUCTURE NETWORK INHERITANCE FOR NAMESET: Which pair of primit\
ives does NOT match?", &c__14, &perm[13], 83L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

