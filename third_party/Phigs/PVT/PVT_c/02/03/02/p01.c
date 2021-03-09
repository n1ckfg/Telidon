/* fort/02/03/02/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__40 = 40;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__7 = 7;
static integer c__5 = 5;
static integer c__9 = 9;
static integer c__4 = 4;
static integer c__8 = 8;
static integer c_n5 = -5;
static integer c__15 = 15;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.02/01                           * */
/*  *    TEST TITLE : Element search within a single closed * */
/*  *                 structure                             * */
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
    extern /* Subroutine */ int initgl_(char *, ftnlen), nsiasf (integer *, 
	    integer *), nspkid (integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nsiasf (), nspkid (), setmsg_();
#endif /* NO_PROTO */
    static integer stridx;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), tstels_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), nstxfn (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), tstels_(), nstxfn ();
#endif /* NO_PROTO */

/* search success */
/* search direction */
/* aspect source */
/*                bundled     individual */
/* attribute identifier */
/* element type */
/*  <polyline 3>, <polymarker 3> parameters: */
    initgl_("02.03.02/01", 11L);
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
/*  POSITION     CONTENTS */
/*  --------     -------- */
/*     1         <polyline 3>           with n, xval, yval, zval */
/*     2         <polymarker 3>         with n, xval, yval, zval */
/*    3         <text 3>               with xpos,ypos,zpos, xvec,yvec,zvec
,*/
/*                                           chrstr */
/*     4         <set text font>        with font */
/*     5         <set character height> with charht */
/*     6         <set individual asf>   with attrid, asfval */
/*     7         <execute structure>    with stridx */
/*     8         <label>                with labl1 */
/*     9         <set pick identifier>  with pkid */
/*  create structure strid: */
    nopst (&c__40);
    npl3 (&n, xval, yval, zval);
    npm3 (&n, xval, yval, zval);
    ntx3 (&xpos, &ypos, &zpos, xvec, yvec, zvec, chrstr, 70L);
    nstxfn (&font);
    nschh (&charht);
    nsiasf (&attrid, &asfval);
    nexst (&stridx);
    nlb (&labl1);
    nspkid (&pkid);
    nclst ();
#ifndef NO_PROTO
    setmsg_("1 2 3 6 8", "<Element search> should find the next matching ele"
	    "ment in the structure identified when searching FORWARD, and whe"
	    "n the start element position is at the beginning of the structur"
	    "e.", 9L, 180L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 8", "<Element search> should find the next matching ele\
ment in the structure identified when searching FORWARD, and when the start \
element position is at the beginning of the structure.", 9L, 180L);
#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = EXECUTE_STRUCTURE, LABEL */
/*  elexc = POLYLINE_3, POLYMARKER_3, TEXT_3 */
    elinc[0] = 66;
    elinc[1] = 67;
    elexc[0] = 2;
    elexc[1] = 4;
    elexc[2] = 6;
    tstels_(&c__40, &c__0, &c__1, &c__2, elinc, &c__3, elexc, &c__1, &c__7);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 8", "<Element search> should find the next matching ele"
	    "ment in the structure identified when searching BACKWARD, and wh"
	    "en the start element position is at the middle of the structure.",
	     9L, 178L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 8", "<Element search> should find the next matching ele\
ment in the structure identified when searching BACKWARD, and when the start\
 element position is at the middle of the structure.", 9L, 178L);
#endif /* NO_PROTO */
/*  selpos = 5, dir = BACKWARD */
/*  elinc = TEXT_3, POLYMARKER_3 */
/*  elexc = SET_TEXT_FONT, SET_CHARACTER_HEIGHT */
    elinc[0] = 6;
    elinc[1] = 4;
    elexc[0] = 29;
    elexc[1] = 34;
    tstels_(&c__40, &c__5, &c__0, &c__2, elinc, &c__2, elexc, &c__1, &c__3);
#ifndef NO_PROTO
    setmsg_("1 2 3 8", "<Element search> should find the next matching eleme"
	    "nt in the structure identified when searching BACKWARD, and when"
	    " the start element position is at the end of the structure.", 7L, 
	    175L);
#else /* NO_PROTO */
    setmsg_("1 2 3 8", "<Element search> should find the next matching eleme\
nt in the structure identified when searching BACKWARD, and when the start e\
lement position is at the end of the structure.", 7L, 175L);
#endif /* NO_PROTO */
/*  selpos = 9, dir = BACKWARD */
/*  elinc = SET_TEXT_FONT */
/*  elexc = SET_PICK_IDENTIFIER */
    elinc[0] = 29;
    elexc[0] = 70;
    tstels_(&c__40, &c__9, &c__0, &c__1, elinc, &c__1, elexc, &c__1, &c__4);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 8", "<Element search> should find the next matching ele"
	    "ment in the structure identified when searching forward, and whe"
	    "n the start element position is on the sought element.", 9L, 168L)
	    ;
#else /* NO_PROTO */
    setmsg_("1 2 3 4 8", "<Element search> should find the next matching ele\
ment in the structure identified when searching forward, and when the start \
element position is on the sought element.", 9L, 168L);
#endif /* NO_PROTO */
/*  selpos = 8, dir = FORWARD */
/*  elinc = LABEL, EXECUTE_STRUCTURE, SET_PICK_ID */
/*  elexc = NIL */
    elinc[0] = 67;
    elinc[1] = 66;
    elinc[2] = 70;
    elexc[0] = 1;
    tstels_(&c__40, &c__8, &c__1, &c__3, elinc, &c__1, elexc, &c__1, &c__8);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 7 8", "When using <element search>, if the start elemen"
	    "t position is less than 0, the search should begin at element 0.",
	     11L, 112L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 7 8", "When using <element search>, if the start elemen\
t position is less than 0, the search should begin at element 0.", 11L, 112L);

#endif /* NO_PROTO */
/*  selpos = -5, dir = FORWARD */
/*  elinc = POLYLINE_3, POLYMARKER_3 */
/*  elexc = NIL */
    elinc[0] = 2;
    elinc[1] = 4;
    elexc[0] = 1;
    tstels_(&c__40, &c_n5, &c__1, &c__2, elinc, &c__1, elexc, &c__1, &c__1);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 7 8", "When using <element search>, if the start elemen"
	    "t position is greater than the number of elements in the structu"
	    "re, the search should begin at the last element in the structure."
	    , 11L, 177L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 7 8", "When using <element search>, if the start elemen\
t position is greater than the number of elements in the structure, the sear\
ch should begin at the last element in the structure.", 11L, 177L);
#endif /* NO_PROTO */
/*  selpos = 15, dir = BACKWARD */
/*  elinc = SET_PICK_IDENTIFIER, LABEL */
/*  elexc = NIL */
    elinc[0] = 70;
    elinc[1] = 67;
    elexc[0] = 1;
    tstels_(&c__40, &c__15, &c__0, &c__2, elinc, &c__1, elexc, &c__1, &c__9);
#ifndef NO_PROTO
    setmsg_("1 2 3 5 7 8", "When using <element search> and searching BACKWA"
	    "RD, if the start element position is less than 0 the search shou"
	    "ld begin at element position 0.", 11L, 143L);
#else /* NO_PROTO */
    setmsg_("1 2 3 5 7 8", "When using <element search> and searching BACKWA\
RD, if the start element position is less than 0 the search should begin at \
element position 0.", 11L, 143L);
#endif /* NO_PROTO */
/*  selpos = -5, dir = BACKWARD */
/*  elinc = POLYLINE_3, NIL */
/*  elexc = TEXT_3 */
    elinc[0] = 2;
    elinc[1] = 1;
    elexc[0] = 6;
    tstels_(&c__40, &c_n5, &c__0, &c__2, elinc, &c__1, elexc, &c__1, &c__0);
#ifndef NO_PROTO
    setmsg_("1 2 3 7 9", "When using <element search> and searching FORWARD,"
	    " if the start element position is greater than the number of ele"
	    "ments in the structure the search should examine only the last e"
	    "lement.", 9L, 185L);
#else /* NO_PROTO */
    setmsg_("1 2 3 7 9", "When using <element search> and searching FORWARD,\
 if the start element position is greater than the number of elements in the\
 structure the search should examine only the last element.", 9L, 185L);
#endif /* NO_PROTO */
/*  selpos = 15, dir = FORWARD */
/*  elinc = SET_PICK_IDENTIFIER, LABEL, POLYLINE_3 */
/*  elexc = EXECUTE_STRUCTURE */
    elinc[0] = 70;
    elinc[1] = 67;
    elinc[2] = 2;
    elexc[0] = 66;
    tstels_(&c__40, &c__15, &c__1, &c__3, elinc, &c__1, elexc, &c__1, &c__9);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 8", "When using <element search>, the element type ALL "
	    "in the inclusion set should designate all possible element types."
	    , 9L, 115L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 8", "When using <element search>, the element type ALL \
in the inclusion set should designate all possible element types.", 9L, 115L);

#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = ALL */
/*  elexc = POLYLINE_3, NIL */
    elinc[0] = 0;
    elexc[0] = 2;
    elexc[1] = 1;
    tstels_(&c__40, &c__0, &c__1, &c__1, elinc, &c__2, elexc, &c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 9", "When using <element search>, the element type NIL "
	    "in the inclusion set should designate the type of the virtual el"
	    "ement in position #0.", 9L, 135L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 9", "When using <element search>, the element type NIL \
in the inclusion set should designate the type of the virtual element in pos\
ition #0.", 9L, 135L);
#endif /* NO_PROTO */
/*  selpos = 9, dir = BACKWARD */
/*  elinc = NIL */
/*  elexc = POLYLINE_3 */
    elinc[0] = 1;
    elexc[0] = 2;
    tstels_(&c__40, &c__9, &c__0, &c__1, elinc, &c__1, elexc, &c__1, &c__0);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 9", "When using <element search>, an empty inclusion se"
	    "t should designate no element type.", 9L, 85L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 9", "When using <element search>, an empty inclusion se\
t should designate no element type.", 9L, 85L);
#endif /* NO_PROTO */
/*  selpos = 9, dir = BACKWARD */
/*  elinc = empty */
/*  elexc = POLYLINE_3 */
    elexc[0] = 2;
    tstels_(&c__40, &c__9, &c__0, &c__0, elinc, &c__1, elexc, &c__0, &c__7);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 6 9", "When using <element search>, the element type AL"
	    "L in the exclusion set should designate all element types.", 11L, 
	    106L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 6 9", "When using <element search>, the element type AL\
L in the exclusion set should designate all element types.", 11L, 106L);
#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = POLYLINE_3, TEXT_3 */
/*  elexc = ALL */
    elinc[0] = 2;
    elinc[1] = 6;
    elexc[0] = 0;
    tstels_(&c__40, &c__0, &c__1, &c__2, elinc, &c__1, elexc, &c__0, &c__7);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 8", "When using <element search>, an empty exclusion se"
	    "t should designate no element type.", 9L, 85L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 8", "When using <element search>, an empty exclusion se\
t should designate no element type.", 9L, 85L);
#endif /* NO_PROTO */
/*  selpos = 9, dir = BACKWARD */
/*  elinc = ALL */
/*  elexc = empty */
    elinc[0] = 0;
    tstels_(&c__40, &c__9, &c__0, &c__1, elinc, &c__0, elexc, &c__1, &c__9);
#ifndef NO_PROTO
    setmsg_("1 2 3 9", "When using <element search>, an empty inclusion and "
	    "exclusion set should result in no elements being found.", 7L, 
	    107L);
#else /* NO_PROTO */
    setmsg_("1 2 3 9", "When using <element search>, an empty inclusion and \
exclusion set should result in no elements being found.", 7L, 107L);
#endif /* NO_PROTO */
/*  selpos = 2, dir = FORWARD */
/*  elinc = empty */
/*  elexc = empty */
    tstels_(&c__40, &c__2, &c__1, &c__0, elinc, &c__0, elexc, &c__0, &c__7);
#ifndef NO_PROTO
    setmsg_("1 2 3 9", "When using <element search>, if an element type is s"
	    "pecified in both the exclusion set and inclusion set, it should "
	    "be excluded.", 7L, 128L);
#else /* NO_PROTO */
    setmsg_("1 2 3 9", "When using <element search>, if an element type is s\
pecified in both the exclusion set and inclusion set, it should be excluded.",
	     7L, 128L);
#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = LABEL */
/*  elexc = LABEL */
    elinc[0] = 67;
    elexc[0] = 67;
    tstels_(&c__40, &c__0, &c__1, &c__1, elinc, &c__1, elexc, &c__0, &c__7);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 9", "When using <element search>, if an element type is"
	    " not specified in the exclusion set nor the inclusion set, it sh"
	    "ould be excluded.", 9L, 131L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 9", "When using <element search>, if an element type is\
 not specified in the exclusion set nor the inclusion set, it should be excl\
uded.", 9L, 131L);
#endif /* NO_PROTO */
/*  selpos = 1, dir = FORWARD */
/*  elinc = NIL */
/*  elexc = NIL */
    elinc[0] = 1;
    elexc[0] = 1;
    tstels_(&c__40, &c__1, &c__1, &c__1, elinc, &c__1, elexc, &c__0, &c__7);
#ifndef NO_PROTO
    setmsg_("1 2 3 6 8", "When using <element search>, an element should qua"
	    "lify for selection if and only if its type belongs to the inclus"
	    "ion set and does not belong to the exclusion set.", 9L, 163L);
#else /* NO_PROTO */
    setmsg_("1 2 3 6 8", "When using <element search>, an element should qua\
lify for selection if and only if its type belongs to the inclusion set and \
does not belong to the exclusion set.", 9L, 163L);
#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = POLYLINE_3, TEXT_3, LABEL, SET_PICK_IDENTIFIER */
/*  elexc = POLYLINE_3, TEXT_3, EXECUTE_STRUCTURE */
    elinc[0] = 2;
    elinc[1] = 6;
    elinc[2] = 67;
    elinc[3] = 70;
    elexc[0] = 2;
    elexc[1] = 6;
    elexc[2] = 66;
    tstels_(&c__40, &c__0, &c__1, &c__4, elinc, &c__3, elexc, &c__1, &c__8);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 6 8", "<Element search> should take the union of the el"
	    "ement type ALL and other element types in the inclusion set.", 
	    11L, 108L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 6 8", "<Element search> should take the union of the el\
ement type ALL and other element types in the inclusion set.", 11L, 108L);
#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = SET_TEXT_FONT, POLYLINE_3, ALL */
/*  elexc = NIL */
    elinc[0] = 29;
    elinc[1] = 2;
    elinc[2] = 0;
    elexc[0] = 1;
    tstels_(&c__40, &c__0, &c__1, &c__3, elinc, &c__1, elexc, &c__1, &c__1);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 6 8", "<Element search> should take the union of the el"
	    "ement type NIL and other element types in the inclusion set.", 
	    11L, 108L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 6 8", "<Element search> should take the union of the el\
ement type NIL and other element types in the inclusion set.", 11L, 108L);
#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = SET_TEXT_FONT, POLYMARKER_3, NIL */
/*  elexc = POLYMARKER_3 */
    elinc[0] = 29;
    elinc[1] = 4;
    elinc[2] = 1;
    elexc[0] = 4;
    tstels_(&c__40, &c__0, &c__1, &c__3, elinc, &c__1, elexc, &c__1, &c__0);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 6 9", "<Element search> should take the union of the el"
	    "ement type ALL and other element types in the exclusion set.", 
	    11L, 108L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 6 9", "<Element search> should take the union of the el\
ement type ALL and other element types in the exclusion set.", 11L, 108L);
#endif /* NO_PROTO */
/*  selpos = 9, dir = BACKWARD */
/*  elinc = POLYLINE_3, POLYMARKER_3, TEXT_3 */
/*  elexc = SET_TEXT_FONT, EXECUTE_STRUCTURE, ALL */
    elinc[0] = 2;
    elinc[1] = 4;
    elinc[2] = 6;
    elexc[0] = 29;
    elexc[1] = 66;
    elexc[2] = 0;
    tstels_(&c__40, &c__9, &c__0, &c__3, elinc, &c__3, elexc, &c__0, &c__7);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 6 8", "<Element search> should take the union of the el"
	    "ement type NIL and other element types in the exclusion set.", 
	    11L, 108L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 6 8", "<Element search> should take the union of the el\
ement type NIL and other element types in the exclusion set.", 11L, 108L);
#endif /* NO_PROTO */
/*  selpos = 9, dir = BACKWARD */
/*  elinc = POLYLINE_3, POLYMARKER_3, TEXT_3 */
/*  elexc = POLYLINE_3, TEXT_3, NIL */
    elinc[0] = 2;
    elinc[1] = 4;
    elinc[2] = 6;
    elexc[0] = 6;
    elexc[1] = 1;
    elexc[2] = 2;
    tstels_(&c__40, &c__9, &c__0, &c__3, elinc, &c__3, elexc, &c__1, &c__2);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 6 8", "<Element search> should take the union of the el"
	    "ement types ALL and NIL in the inclusion set.", 11L, 93L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 6 8", "<Element search> should take the union of the el\
ement types ALL and NIL in the inclusion set.", 11L, 93L);
#endif /* NO_PROTO */
/*  selpos = 0, dir = FORWARD */
/*  elinc = ALL, NIL */
/*  elexc = empty */
    elinc[0] = 0;
    elinc[1] = 1;
    tstels_(&c__40, &c__0, &c__1, &c__2, elinc, &c__0, elexc, &c__1, &c__0);
#ifndef NO_PROTO
    setmsg_("1 2 3 4 6 9", "<Element search> should take the union of the el"
	    "ement types ALL and NIL in the exclusion set.", 11L, 93L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4 6 9", "<Element search> should take the union of the el\
ement types ALL and NIL in the exclusion set.", 11L, 93L);
#endif /* NO_PROTO */
/*  selpos = 9, dir = BACKWARD */
/*  elinc = SET_PICK_IDENTIFIER, LABEL, EXECUTE_STRUCTURE */
/*  elexc = ALL, NIL */
    elinc[0] = 70;
    elinc[1] = 67;
    elinc[2] = 66;
    elexc[0] = 0;
    elexc[1] = 1;
    tstels_(&c__40, &c__9, &c__0, &c__3, elinc, &c__2, elexc, &c__0, &c__7);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

