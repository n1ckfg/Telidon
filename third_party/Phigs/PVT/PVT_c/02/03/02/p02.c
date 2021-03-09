/* fort/02/03/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__10 = 10;
static integer c__30 = 30;
static integer c__20 = 20;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__7 = 7;
static integer c__93 = 93;
static integer c__4 = 4;
static integer c__8 = 8;
static integer c__9 = 9;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.02/02                           * */
/*  *    TEST TITLE : Element search with varying types of  * */
/*  *                 structures                            * */
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
    static real xval[4] = { 1e-4f,99.99f,-1.3e20f,1.3e13f };
    static real yval[4] = { -99.99f,0.f,.0015f,5.f };
    static real zval[4] = { 5e9f,1.2f,-5.f,0.f };
#else /* NO_PROTO */
    static real xval[4] = { (float)1e-4,(float)99.99,(float)-1.3e20,(float)
	    1.3e13 };
    static real yval[4] = { (float)-99.99,(float)0.,(float).0015,(float)5. };
    static real zval[4] = { (float)5e9,(float)1.2,(float)-5.,(float)0. };
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer n;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), npl3 (integer *, real *, 
	    real *, real *), npm3 (integer *, real *, real *, real *), ntx3 (
	    real *, real *, real *, real *, real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), npl3 (), npm3 (), ntx3 ();
#endif /* NO_PROTO */
    static integer pkid;
    static real xvec[2];
    static integer font;
    static real yvec[2], zvec[2], xpos, ypos;
    static integer labl1;
    static real zpos;
    static integer elinc[68], elexc[68];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nschh (real *), nclst (void), 
	    nexst (integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nschh (), nclst (), nexst (), 
	    nopst ();
#endif /* NO_PROTO */
    static real charht;
    static integer asfval, attrid;
    static char chrstr[70];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nspkid (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nspkid ();
#endif /* NO_PROTO */
    static integer stridx;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nsiasf (
	    integer *, integer *), nstxfn (integer *), setmsg_(char *, char *,
	     ftnlen, ftnlen), tstels_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nsiasf (), nstxfn (), setmsg_(), 
	    tstels_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/* search success */
/* search direction */
/* aspect source */
/*                bundled     individual */
/* attribute identifier */
/* element type */
/*  <polyline 3>, <polymarker 3> parameters: */
    initgl_("02.03.02/02", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  <polyline 3>, <polymarker 3> parameters: */
    n = 4;
/*  <text 3> parameters: */
#ifndef NO_PROTO
    xpos = 1e-4f;
    ypos = -99.99f;
    zpos = 5e9f;
    xvec[0] = 1.f;
    xvec[1] = .3f;
    yvec[0] = 2.5f;
    yvec[1] = -1.6e13f;
    zvec[0] = .003f;
    zvec[1] = 999.f;
#else /* NO_PROTO */
    xpos = (float)1e-4;
    ypos = (float)-99.99;
    zpos = (float)5e9;
    xvec[0] = (float)1.;
    xvec[1] = (float).3;
    yvec[0] = (float)2.5;
    yvec[1] = (float)-1.6e13;
    zvec[0] = (float).003;
    zvec[1] = (float)999.;
#endif /* NO_PROTO */
    s_copy(chrstr, "This is a TEXT_3 character string for <element search>.", 
	    70L, 55L);
/*  <set text font> parameters: */
    font = -2;
/*  <set character height> parameters: */
#ifndef NO_PROTO
    charht = .5f;
#else /* NO_PROTO */
    charht = (float).5;
#endif /* NO_PROTO */
/*  <set individual asf> parameters: */
    attrid = 0;
    asfval = 0;
/*  <execute structure> parameters: */
    stridx = 30;
/*  <label> parameters: */
    labl1 = 1;
/*  <set pick identifier> parameters: */
    pkid = 5;
/*  create empty structure stride: */
    nopst (&c__10);
    nclst ();
/*  create closed structure stridc: */
    nopst (&c__30);
    nspkid (&pkid);
    nlb (&labl1);
    nexst (&stridx);
    nsiasf (&attrid, &asfval);
    nschh (&charht);
    nstxfn (&font);
    ntx3 (&xpos, &ypos, &zpos, xvec, yvec, zvec, chrstr, 70L);
    npm3 (&n, xval, yval, zval);
    npl3 (&n, xval, yval, zval);
    nclst ();
/*  create open structure strido: */
    nopst (&c__20);
    npl3 (&n, xval, yval, zval);
    npm3 (&n, xval, yval, zval);
    ntx3 (&xpos, &ypos, &zpos, xvec, yvec, zvec, chrstr, 70L);
    nstxfn (&font);
    nschh (&charht);
    nsiasf (&attrid, &asfval);
    nexst (&stridx);
    nlb (&labl1);
    nspkid (&pkid);
/*  strido left open */
/*  closed structure: */
/*  POSITION     CONTENTS */
/*  --------     -------- */
/*     1         <set pick identifier>  with pkid */
/*     2         <label>                with labl1 */
/*     3         <execute structure>    with stridx */
/*     4         <set individual asf>   with attrid, asfval */
/*     5         <set character height> with charht */
/*     6         <set text font>        with font */
/*    7         <text 3>               with xpos, ypos, zpox, xvec, yvec, 
zvec,*/
/*                                           chrstr */
/*     8         <polymarker 3>         with n, xval, yval, zval */
/*     9         <polyline 3>           with n, xval, yval, zval */
/*  open structure: */
/*  POSITION     CONTENTS */
/*  --------     -------- */
/*     1         <polyline 3>           with n, xval, yval, zval */
/*     2         <polymarker 3>         with n, xval, yval, zval */
/*    3         <text 3>               with xpos, ypos, zpos, xvec, yvec, 
zvec,*/
/*                                           chrstr */
/*     4         <set text font>        with font */
/*     5         <set character height> with charht */
/*     6         <set individual asf>   with attrid, asfval */
/*     7         <execute structure>    with stridx */
/*     8         <label>                with labl1 */
/*     9         <set pick identifier>  with pkid */
#ifndef NO_PROTO
    setmsg_("1 2 6 9", "When using <element search> with an empty structure "
	    "and searching for non-NIL elements, the search should be unsucce"
	    "ssful and the status indicator should return the value FAILURE.", 
	    7L, 179L);
#else /* NO_PROTO */
    setmsg_("1 2 6 9", "When using <element search> with an empty structure \
and searching for non-NIL elements, the search should be unsuccessful and th\
e status indicator should return the value FAILURE.", 7L, 179L);
#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = POLYLINE_3, SET_CHARACTER_HEIGHT, LABEL */
/*  elexc = POLYMARKER_3 */
    elinc[0] = 2;
    elinc[1] = 34;
    elinc[2] = 67;
    elexc[0] = 4;
    tstels_(&c__10, &c__0, &c__1, &c__3, elinc, &c__1, elexc, &c__0, &c__7);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 5 7 8", "When using <element search> with an empty stru"
	    "cture and searching for a NIL element, the search should find th"
	    "e element at position #0.", 13L, 135L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 5 7 8", "When using <element search> with an empty stru\
cture and searching for a NIL element, the search should find the element at\
 position #0.", 13L, 135L);
#endif /* NO_PROTO */
/*  selpos = 93, dir = BACKWARD */
/*  elinc = ALL */
/*  elexc = POLYMARKER_3 */
    elinc[0] = 0;
    elexc[0] = 4;
    tstels_(&c__10, &c__93, &c__0, &c__1, elinc, &c__1, elexc, &c__1, &c__0);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 8", "When using <element search> with an open structure"
	    ", an element should qualify for selection if and only if its typ"
	    "e belongs to the inclusion set and does not belong to the exclus"
	    "ion set.", 9L, 186L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 8", "When using <element search> with an open structure\
, an element should qualify for selection if and only if its type belongs to\
 the inclusion set and does not belong to the exclusion set.", 9L, 186L);
#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = POLYMARKER_3, SET_TEXT_FONT, LABEL, SET_PICK_IDENTIFIER */
/*  elexc = POLYMARKER_3, SET_TEXT_FONT, EXECUTE_STRUCTURE */
    elinc[0] = 4;
    elinc[1] = 29;
    elinc[2] = 67;
    elinc[3] = 70;
    elexc[0] = 4;
    elexc[1] = 66;
    elexc[2] = 29;
    tstels_(&c__20, &c__0, &c__1, &c__4, elinc, &c__3, elexc, &c__1, &c__8);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 8", "When using <element search> with a closed structur"
	    "e, an element should qualify for selection if and only if its ty"
	    "pe belongs to the inclusion set and does not belong to the exclu"
	    "sion set.", 9L, 187L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 8", "When using <element search> with a closed structur\
e, an element should qualify for selection if and only if its type belongs t\
o the inclusion set and does not belong to the exclusion set.", 9L, 187L);
#endif /* NO_PROTO */
/*  selpos = 9 */
/*  dir = BACKWARD */
/*  elinc = POLYLINE_3, TEXT_3, POLYMARKER_3 */
/*  elexc = POLYLINE_3, POLYMARKER_3 */
    elinc[0] = 4;
    elinc[1] = 6;
    elinc[2] = 2;
    elexc[0] = 2;
    elexc[1] = 4;
    tstels_(&c__30, &c__9, &c__0, &c__3, elinc, &c__2, elexc, &c__1, &c__7);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

