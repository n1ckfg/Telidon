/* fort/04/01/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b10 = .1f;
#else /* NO_PROTO */
static real c_b10 = (float).1;
#endif /* NO_PROTO */
static integer c__102 = 102;
static integer c__5 = 5;
static integer c__26 = 26;
#ifndef NO_PROTO
static real c_b31 = .06f;
static real c_b32 = .2f;
static real c_b34 = .5f;
#else /* NO_PROTO */
static real c_b31 = (float).06;
static real c_b32 = (float).2;
static real c_b34 = (float).5;
#endif /* NO_PROTO */
static integer c__106 = 106;
static integer c__103 = 103;
static integer c__6 = 6;
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b49 = 45.f;
static real c_b50 = -45.f;
static real c_b53 = 0.f;
static real c_b54 = 360.f;
static real c_b61 = 1.f;
#else /* NO_PROTO */
static real c_b49 = (float)45.;
static real c_b50 = (float)-45.;
static real c_b53 = (float)0.;
static real c_b54 = (float)360.;
static real c_b61 = (float)1.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.01.03/02                           * */
/*  *    TEST TITLE : Appearance of text primitives         * */
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
    static real tdv1[15]	/* was [3][5] */ = { 0.f,0.f,0.f,0.f,0.f,0.f,
	    3.f,4.f,5.f,1.f,-2.f,3.f,8.f,1.f,0.f };
    static real tdv2[15]	/* was [3][5] */ = { 2.f,3.f,4.f,0.f,0.f,0.f,
	    0.f,0.f,0.f,3.f,-6.f,9.f,-1.f,8.f,0.f };
#else /* NO_PROTO */
    static real tdv1[15]	/* was [3][5] */ = { (float)0.,(float)0.,(
	    float)0.,(float)0.,(float)0.,(float)0.,(float)3.,(float)4.,(float)
	    5.,(float)1.,(float)-2.,(float)3.,(float)8.,(float)1.,(float)0. };
#endif /* NO_PROTO */

#ifdef NO_PROTO
    static real tdv2[15]	/* was [3][5] */ = { (float)2.,(float)3.,(
	    float)4.,(float)0.,(float)0.,(float)0.,(float)0.,(float)0.,(float)
	    0.,(float)3.,(float)-6.,(float)9.,(float)-1.,(float)8.,(float)0. }
	    ;

#endif /* NO_PROTO */
    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static real xf[16]	/* was [4][4] */;
    static integer ix, n2d;
    static real idm[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen), etp3_(
	    real *, real *, real *, real *, real *, real *, real *), win6_(
	    integer *, integer *, real *, real *, real *, real *), ntx3 (real 
	    *, real *, real *, real *, real *, real *, char *, ftnlen), fail_(
	    void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx (), etp3_(), win6_(), ntx3 (), fail_(), 
	    ifpf_();
#endif /* NO_PROTO */
    static real xmid, ymid;
    static integer perm[10];
    static real zmid, xloc, yloc;
    static integer txci, ngsq, nhoz;
    static real tdvx[2], tdvy[2], tdvz[2], rotx, xsiz, ysiz, roty, rotz;
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen), 
	    idmat_(integer *, real *), endit_(void), nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_(), idmat_(), endit_(), nschh ();
#endif /* NO_PROTO */
    static real xcord, ycord, zcord, yincr;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static char chstr[5], lower[26];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
#endif /* NO_PROTO */
    static char upper[26];
#ifndef NO_PROTO
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *), 
	    nemst (integer *), nexst (integer *), nopst (integer *), nsvwi (
	    integer *), nstxp (integer *), ebltm3_(real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnset_(), nemst (), nexst (), nopst (), 
	    nsvwi (), nstxp (), ebltm3_();
#endif /* NO_PROTO */
    static char chrabc[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nslmt3 (real *, integer *), numlab_(integer *,
	     real *, real *, real *), dchpfv_(char *, integer *, integer *, 
	    ftnlen), setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nslmt3 (), numlab_(), dchpfv_(), setdlg_();
#endif /* NO_PROTO */
    static integer picstr;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer primid, nothoz, numlin;
    static real xwinlo[6], ywinlo[6];
    static char repstr[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nstxfn (integer *), nstxpr (
	    integer *), nstxal (integer *, integer *), setmsg_(char *, char *,
	     ftnlen, ftnlen), rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nstxfn (), 
	    nstxpr (), nstxal (), setmsg_(), rnperm_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
    initgl_("04.01.03/02", 11L);
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
/*  set default text attributes: */
/*  font = 1, precision = STROKE, text alignment = CENTRE,HALF */
    nstxfn (&c__1);
    nstxpr (&c__2);
    nstxal (&c__2, &c__3);
    nstxp (&c__0);
    nschh (&c_b10);
/*  set up 102 as sub-structure */
    nexst (&c__102);
    nclst ();
/*  *** *** *** ***   character content   *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("9", "A displayed text primitive should contain the specified ch"
	    "aracter string.", 1L, 73L);
#else /* NO_PROTO */
    setmsg_("9", "A displayed text primitive should contain the specified ch\
aracter string.", 1L, 73L);
#endif /* NO_PROTO */
    nopst (&c__102);
    nstxfn (&c__2);
    s_copy(upper, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26L, 26L);
/*  chstr = string of 5 randomly chosen upper-case letters */
    rnset_(&c__5, &c__26, perm);
    for (ix = 1; ix <= 5; ++ix) {
	i__1 = perm[ix - 1] - 1;
	s_copy(chstr + (ix - 1), upper + i__1, 1L, perm[ix - 1] - i__1);
/* L100: */
    }
/*  display <text 3> consisting of chstr: */
/*    position = 0.5,0.5,0.5 */
/*    TDV = (1,0,0), (0,1,0) */
#ifndef NO_PROTO
    xcord = .5f;
    ycord = .5f;
    zcord = .5f;
    tdvx[0] = 1.f;
    tdvy[0] = 0.f;
    tdvz[0] = 0.f;
    tdvx[1] = 0.f;
    tdvy[1] = 1.f;
    tdvz[1] = 0.f;
#else /* NO_PROTO */
    xcord = (float).5;
    ycord = (float).5;
    zcord = (float).5;
    tdvx[0] = (float)1.;
    tdvy[0] = (float)0.;
    tdvz[0] = (float)0.;
    tdvx[1] = (float)0.;
    tdvy[1] = (float)1.;
    tdvz[1] = (float)0.;
#endif /* NO_PROTO */
    ntx3 (&xcord, &ycord, &zcord, tdvx, tdvy, tdvz, chstr, 5L);
    dline_("CHARACTER CONTENT: Enter the displayed character string.", repstr,
	     56L, 10L);
    nemst (&c__102);
    if (s_cmp(repstr, chstr, 10L, 5L) != 0) {
	fail_();
	goto L199;
    }
    nstxfn (&c__1);
/*  chstr = string of 5 randomly chosen lower-case letters */
    s_copy(lower, "abcdefghijklmnopqrstuvwxyz", 26L, 26L);
    rnset_(&c__5, &c__26, perm);
    for (ix = 1; ix <= 5; ++ix) {
	i__1 = perm[ix - 1] - 1;
	s_copy(chstr + (ix - 1), lower + i__1, 1L, perm[ix - 1] - i__1);
/* L110: */
    }
/*  display <text> consisting of chstr: */
/*     at (0.5, 0.5) */
#ifndef NO_PROTO
    xcord = .5f;
    ycord = .5f;
#else /* NO_PROTO */
    xcord = (float).5;
    ycord = (float).5;
#endif /* NO_PROTO */
    ntx (&xcord, &ycord, chstr, 5L);
    dline_("CHARACTER CONTENT: Enter the displayed character string.", repstr,
	     56L, 10L);
    nemst (&c__102);
    L__1 = s_cmp(repstr, chstr, 10L, 5L) == 0;
    ifpf_(&L__1);
/*  end_char: */
L199:
/*  *** *** *** ***   degenerate vectors   *** *** *** *** */
    numlin = 6;
    nhoz = 5;
    n2d = 6;
    s_copy(chrabc, "ABC", 3L, 3L);
/*  create random array */
    rnperm_(&numlin, perm);
/*  In random order, display on 6 lines: */
/*                 1st vector   2nd vector */
/*  3D text "ABC"  (0,0,0)      (2,3,4) */
/*  3D text "ABC"  (0,0,0)      (0,0,0) */
/*  3D text "ABC"  (3,4,5)      (0,0,0) */
/*  3D text "ABC"  (1,-2,3)     (3,-6,9) (parallel vectors) */
/*  3D text "ABC"  (8,1,0)      (-1,8,0) (not horizontal) */
/*  2D text "ABC"   n.a.         n.a. */
#ifndef NO_PROTO
    xloc = .4f;
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    xloc = (float).4;
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    yloc = 1 - yincr;
    nschh (&c_b31);
    numlab_(&numlin, &c_b32, &yloc, &yincr);
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
	primid = perm[ix - 1];
	if (primid == nhoz) {
	    nothoz = ix;
	}
	if (primid == n2d) {
	    ntx (&xloc, &yloc, chrabc, 3L);
	} else {
	    tdvx[0] = tdv1[primid * 3 - 3];
	    tdvy[0] = tdv1[primid * 3 - 2];
	    tdvz[0] = tdv1[primid * 3 - 1];
	    tdvx[1] = tdv2[primid * 3 - 3];
	    tdvy[1] = tdv2[primid * 3 - 2];
	    tdvz[1] = tdv2[primid * 3 - 1];
	    ntx3 (&xloc, &yloc, &c_b34, tdvx, tdvy, tdvz, chrabc, 3L);
	}
	yloc -= yincr;
/* L230: */
    }
#ifndef NO_PROTO
    setmsg_("9 10 11", "The values (1,0,0) and (0,1,0) should be used as tex"
	    "t direction vectors for all 2D text primitives and also when the"
	    " explicit vectors of a 3D text primitive fail to define a plane.",
	     7L, 180L);
#else /* NO_PROTO */
    setmsg_("9 10 11", "The values (1,0,0) and (0,1,0) should be used as tex\
t direction vectors for all 2D text primitives and also when the explicit ve\
ctors of a 3D text primitive fail to define a plane.", 7L, 180L);
#endif /* NO_PROTO */
    dchpfv_("DEGENERATE TEXT DIRECTION VECTORS: Which text line is different?"
	    , &numlin, &nothoz, 64L);
    nemst (&c__102);
/*  *** *** *** ***   effect of text direction vectors   *** *** *** *** 
*/
    nexst (&c__106);
    nexst (&c__103);
    nclst ();
/*  Divide screen up into 6 square labelled areas */
    win6_(&c__106, &c__2, &xsiz, &ysiz, xwinlo, ywinlo);
    nopst (&c__103);
    ngsq = rndint_(&c__1, &c__6);
    s_copy(chrabc, "ABC", 3L, 3L);
#ifndef NO_PROTO
    zmid = .5f;
#else /* NO_PROTO */
    zmid = (float).5;
#endif /* NO_PROTO */
/*  idm = identity matrix */
    idmat_(&c__4, idm);
    for (ix = 1; ix <= 6; ++ix) {
/*   xmid,ymid = center of box #ix */
	xmid = xwinlo[ix - 1] + xsiz / 2;
	ymid = ywinlo[ix - 1] + ysiz / 2;
/*  rotx = random from -45.0 to 45.0 degrees */
/*  roty = random from -45.0 to 45.0 degrees */
/*  rotz = random from 0 to 360 degrees */
#ifndef NO_PROTO
	rotx = rndrl_(&c_b49, &c_b50) * 3.14159265f / 180.f;
	roty = rndrl_(&c_b49, &c_b50) * 3.14159265f / 180.f;
	rotz = rndrl_(&c_b53, &c_b54) * 3.14159265f / 180.f;
#else /* NO_PROTO */
	rotx = rndrl_(&c_b49, &c_b50) * (float)3.14159265 / (float)180.;
	roty = rndrl_(&c_b49, &c_b50) * (float)3.14159265 / (float)180.;
	rotz = rndrl_(&c_b53, &c_b54) * (float)3.14159265 / (float)180.;
#endif /* NO_PROTO */
/*   build transformation matrix xf for rotation - rotx, roty, rotz */

/*     centered at 0,0,0 */
	ebltm3_(&c_b53, &c_b53, &c_b53, &c_b53, &c_b53, &c_b53, &rotx, &roty, 
		&rotz, &c_b61, &c_b61, &c_b61, xf);
/*     calculate equivalent TDVs: */
/*     tdv1x,tdv1y,tdv1z = (1,0,0) transformed by xf */
/*     tdv2x,tdv2y,tdv2z = (0,1,0) transformed by xf */
	etp3_(&c_b61, &c_b53, &c_b53, xf, tdvx, tdvy, tdvz);
	etp3_(&c_b53, &c_b61, &c_b53, xf, &tdvx[1], &tdvy[1], &tdvz[1]);
/*     apply identity matrix as modelling transformation */
	nslmt3 (idm, &c__2);
/*     draw <text 3> chstr: */
/*        position: xmid,ymid,zmid */
/*        TDV: tdv1,tdv2 */
	ntx3 (&xmid, &ymid, &zmid, tdvx, tdvy, tdvz, chrabc, 3L);
/*     if (ix = ngsq) rotz = rotz + 15 degrees */
	if (ix == ngsq) {
#ifndef NO_PROTO
	    rotz += .26179938750000004f;
#else /* NO_PROTO */
	    rotz += (float).26179938750000004;
#endif /* NO_PROTO */
	}
/*   build transformation matrix  xf for rotx,roty,rotz, */
/*          centered at xmid,ymid,0 */
/*          then shift by 0.5 in z-direction */
	ebltm3_(&xmid, &ymid, &c_b53, &c_b53, &c_b53, &c_b34, &rotx, &roty, &
		rotz, &c_b61, &c_b61, &c_b61, xf);
/*   apply xf as modelling transformation */
	nslmt3 (xf, &c__2);
/*   set up TDVs */
#ifndef NO_PROTO
	tdvx[0] = 1.f;
	tdvy[0] = 0.f;
	tdvz[0] = 0.f;
	tdvx[1] = 0.f;
	tdvy[1] = 1.f;
	tdvz[1] = 0.f;
#else /* NO_PROTO */
	tdvx[0] = (float)1.;
	tdvy[0] = (float)0.;
	tdvz[0] = (float)0.;
	tdvx[1] = (float)0.;
	tdvy[1] = (float)1.;
	tdvz[1] = (float)0.;
#endif /* NO_PROTO */
/*  draw text:   if (ix <= 3) then draw <text 3> chstr: */
/*     position: xmid, ymid, 0; TDV: (1, 0, 0), (0, 1, 0) */
/*     else draw <text> chstr: position: xmid, ymid */
	if (ix <= 3) {
	    ntx3 (&xmid, &ymid, &c_b53, tdvx, tdvy, tdvz, chrabc, 3L);
	} else {
	    ntx (&xmid, &ymid, chrabc, 3L);
	}
/* L310: */
    }
#ifndef NO_PROTO
    setmsg_("9 10", "A displayed text primitive should be rotated around the"
	    " text position as specified by the first and second text directi"
	    "on vectors.", 4L, 130L);
#else /* NO_PROTO */
    setmsg_("9 10", "A displayed text primitive should be rotated around the\
 text position as specified by the first and second text direction vectors.", 
	    4L, 130L);
#endif /* NO_PROTO */
    dchpfv_("TEXT DIRECTION VECTORS: Which box contains overlapping text?", &
	    c__6, &ngsq, 60L);
    nemst (&c__103);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

