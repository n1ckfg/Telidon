/* fort/04/02/03/01/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__0 = 0;
#ifndef NO_PROTO
static real c_b18 = .15f;
#else /* NO_PROTO */
static real c_b18 = (float).15;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b57 = .05f;
static real c_b66 = .9f;
#else /* NO_PROTO */
static real c_b57 = (float).05;
static real c_b66 = (float).9;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.01/08                        * */
/*  *    TEST TITLE : Text alignment                        * */
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
    integer i__1;
    real r__1, r__2, r__3, r__4;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[2], ya[2];
    static integer ix;
    static real xhi, yhi;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static real xlo, ylo;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static char dig2[2];
    static real htab[3], chht, vtab[5], xmid, ymid;
    static integer perm[20], txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static real ytop;
    static integer idum1, algnh[6];
    static real xhalf, yhalf;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nschh ();
#endif /* NO_PROTO */
    static integer algnv[6];
    static real yincr, xincr, xleft;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *), nexst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst (), nexst ();
#endif /* NO_PROTO */
    static real ntxwd, ntxht;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsvwi (integer *), nstxp (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsvwi (), nstxp ();
#endif /* NO_PROTO */
    static char txstr[8];
    static integer ealgnh[6], ralgnh[6], ealgnv[6], picstr, numlin, algntp[6],
	     ralgnv[6];
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *), setasf_(
	    integer *), nstxfn (integer *), discol_(integer *, integer *, 
	    integer *), txexal_(integer *, integer *, char *, real *, real *, 
	    real *, real *, ftnlen), setval_(char *, integer *, ftnlen), 
	    nstxpr (integer *), rnperm_(integer *, integer *), nstxci (
	    integer *), nsplci (integer *), numlab_(integer *, real *, real *,
	     real *);
#else /* NO_PROTO */
    extern integer rndint_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_(), setasf_(), 
	    nstxfn (), discol_(), txexal_(), setval_(), nstxpr (), rnperm_(), 
	    nstxci (), nsplci (), numlab_();
#endif /* NO_PROTO */
    static real txposx, txposy;
#ifndef NO_PROTO
    extern /* Subroutine */ int drwrec_(real *, real *, real *, real *), 
	    nstxal (integer *, integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), dchpfv_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int drwrec_(), nstxal (), setmsg_(), dchpfv_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___37 = { 0, dig2, 0, "(I1,A)", 2, 1 };
    static icilist io___38 = { 0, dig2, 0, "(I1,A)", 2, 1 };


/* aspect source */
/*                bundled     individual */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* linetype */
    initgl_("04.02.03.01/08", 14L);
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
/*  set text font = 2, text precision = STROKE */
    nstxfn (&c__2);
    nstxpr (&c__2);
    nexst (&c__102);
    nclst ();
/*  try for 2 distinct colors */
    discol_(&c__2, &globnu_1.wkid, &idum1);
    nopst (&c__102);
/*  txstr = text string to be used for test = "Widget!?" */
    s_copy(txstr, "Widget!?", 8L, 8L);
/*  use <inquire text extent> on horizontal txstr to determine: */
/*    ntxwd  = nominal width of text extent rectangle */
/*    ntxht  = nominal height of text extent rectangle */
/*    vtab,htab = normalized heights and widths */
    txexal_(&c__2, &c__0, txstr, &ntxwd, &ntxht, htab, vtab, 8L);
/*  table of alignments and paths to be tested: */

/*       hor-align  vert-align  text path */
/*       algnh      algnv       algntp */
/*       ---------  ----------  --------- */
/*    1: left       top         left */
/*    2: center     cap         right */
/*    3: right      half        left */
/*    4: right      base        right */
/*    5: center     bottom      left */
/*    6: left       bottom      right */
    setval_("1,2,3,3,2,1", algnh, 11L);
    setval_("1,2,3,4,5,5", algnv, 11L);
    setval_("1,0,1,0,1,0", algntp, 11L);
    numlin = 6;
    rnperm_(&numlin, perm);
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
/*  scale to fit */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = .7f / ntxwd, r__2 = yincr * .8f / ntxht;
#else /* NO_PROTO */
    r__1 = (float).7 / ntxwd, r__2 = yincr * (float).8 / ntxht;
#endif /* NO_PROTO */
    chht = dmin(r__1,r__2);
    nschh (&chht);
/*  draw and label 6 identical horizontal text rectangles, */
/*    using dotted lines, distinct color, dashed baseline */
/*    stacked vertically, and labelled 1-6 */
    nstxci (&c__1);
    nsplci (&c__2);
    numlab_(&numlin, &c_b18, &ytop, &yincr);
#ifndef NO_PROTO
    xlo = .2f;
#else /* NO_PROTO */
    xlo = (float).2;
#endif /* NO_PROTO */
    xhi = xlo + chht * ntxwd;
    yhalf = chht * ntxht / 2;
    xa[0] = xlo;
    xa[1] = xhi;
    r__1 = yincr / 2;
    r__2 = -(doublereal)yincr;
    for (ymid = ytop; r__2 < 0 ? ymid >= r__1 : ymid <= r__1; ymid += r__2) {
	nsln (&c__3);
	r__3 = ymid - yhalf;
	r__4 = ymid + yhalf;
	drwrec_(&xlo, &xhi, &r__3, &r__4);
	nsln (&c__2);
	ya[0] = ymid - yhalf + chht * vtab[3];
	ya[1] = ya[0];
	npl (&c__2, xa, ya);
/* L200: */
    }
/*  draw in text */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  set desired y-location based on perm(ix); find bottom of rectangle
 */
	ylo = ytop - yhalf - yincr * (perm[ix - 1] - 1);
/*  calculate txpos = text position, so as to fit text */
/*    into expected box, using values from algnh(ix),algnv(ix) */
	txposx = xlo + chht * htab[algnh[ix - 1] - 1];
	txposy = ylo + chht * vtab[algnv[ix - 1] - 1];
/*  if ix=6 then change txpos to generate incorrect result */
	if (ix == numlin) {
#ifndef NO_PROTO
	    txposx += (rndint_(&c__0, &c__1) - .5f) * .1f;
#else /* NO_PROTO */
	    txposx += (rndint_(&c__0, &c__1) - (float).5) * (float).1;
#endif /* NO_PROTO */
	}
/*  set text alignment = algnh(ix), algnv(ix) */
	nstxal (&algnh[ix - 1], &algnv[ix - 1]);
/*  set text path = algntp(ix) */
	nstxp (&algntp[ix - 1]);
/*  draw text at txpos */
	ntx (&txposx, &txposy, txstr, 8L);
/* L300: */
    }
#ifndef NO_PROTO
    setmsg_("16 27 31 65 66 67 72 73 74 75", "Explicit text alignment attrib"
	    "utes should affect the position of a horizontal text rectangle i"
	    "n accordance with the values returned by <inquire text extent>.", 
	    29L, 157L);
    dchpfv_("EXPLICIT ALIGNMENT FOR HORIZONTAL TEXT: Which text primitive is"
	    " NOT aligned within the dotted text extent rectangle on the dash"
	    "ed baseline?", &numlin, &perm[numlin - 1], 139L);
#else /* NO_PROTO */
    setmsg_("16 27 31 65 66 67 72 73 74 75", "Explicit text alignment attrib\
utes should affect the position of a horizontal text rectangle in accordance\
 with the values returned by <inquire text extent>.", 29L, 157L);
    dchpfv_("EXPLICIT ALIGNMENT FOR HORIZONTAL TEXT: Which text primitive is\
 NOT aligned within the dotted text extent rectangle on the dashed baseline?",
	     &numlin, &perm[numlin - 1], 139L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  table of requested and expected alignments and paths to be tested: */

/*                  requested:             | expected: */
/*       text path  hor-align  vert-align  | hor-align  vert-align */
/*       algntp     ralgnh     ralgnv      | ealgnh     ealgnv */
/*       ---------  ---------  ----------  | ---------  ---------- */
/*    1: left       normal     normal      | right      base */
/*    2: right      normal     normal      | left       base */
/*    3: left       center     normal      | center     base */
/*    4: right      normal     top         | left       top */
/*    5: left       normal     normal      | right      base */
    setval_("0,0,2,0,0", ralgnh, 9L);
    setval_("0,0,0,1,0", ralgnv, 9L);
    setval_("3,1,2,1,3", ealgnh, 9L);
    setval_("4,4,4,1,4", ealgnv, 9L);
    numlin = 5;
/*  set up PERM to randomize position */
    rnperm_(&numlin, perm);
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
/*  scale to fit */
/* Computing MIN */
#ifndef NO_PROTO
    r__2 = .7f / ntxwd, r__1 = yincr * .8f / ntxht;
#else /* NO_PROTO */
    r__2 = (float).7 / ntxwd, r__1 = yincr * (float).8 / ntxht;
#endif /* NO_PROTO */
    chht = dmin(r__2,r__1);
    nschh (&chht);
/*  draw and label 5 identical horizontal text rectangles, */
/*    using dotted lines, distinct color, */
/*    stacked vertically, and labelled 1-5 */
    nstxci (&c__1);
    nsplci (&c__2);
    numlab_(&numlin, &c_b18, &ytop, &yincr);
#ifndef NO_PROTO
    xlo = .2f;
#else /* NO_PROTO */
    xlo = (float).2;
#endif /* NO_PROTO */
    xhi = xlo + chht * ntxwd;
    yhalf = chht * ntxht / 2;
    xa[0] = xlo;
    xa[1] = xhi;
    r__2 = yincr / 2;
    r__1 = -(doublereal)yincr;
    for (ymid = ytop; r__1 < 0 ? ymid >= r__2 : ymid <= r__2; ymid += r__1) {
	nsln (&c__3);
	r__3 = ymid - yhalf;
	r__4 = ymid + yhalf;
	drwrec_(&xlo, &xhi, &r__3, &r__4);
	nsln (&c__2);
	ya[0] = ymid - yhalf + chht * vtab[3];
	ya[1] = ya[0];
	npl (&c__2, xa, ya);
/* L500: */
    }
/*  draw in text */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  set desired y-location based on perm(ix); find bottom of rectangle
 */
	ylo = ytop - yhalf - yincr * (perm[ix - 1] - 1);
/*  calculate txpos = text position, so as to fit text */
/*  into expected box, using values from ealgnh(ix),ealgnv(ix) */
	txposx = xlo + chht * htab[ealgnh[ix - 1] - 1];
	txposy = ylo + chht * vtab[ealgnv[ix - 1] - 1];
/*  if ix=5 then change txpos to generate incorrect result */
	if (ix == numlin) {
#ifndef NO_PROTO
	    txposx += (rndint_(&c__0, &c__1) - .5f) * .1f;
#else /* NO_PROTO */
	    txposx += (rndint_(&c__0, &c__1) - (float).5) * (float).1;
#endif /* NO_PROTO */
	}
/*  set text alignment = ralgnh(ix), ralgnv(ix) */
	nstxal (&ralgnh[ix - 1], &ralgnv[ix - 1]);
/*  set text path = algntp(ix) */
	nstxp (&algntp[ix - 1]);
/*  draw text at txpos */
	ntx (&txposx, &txposy, txstr, 8L);
/* L600: */
    }
#ifndef NO_PROTO
    setmsg_("16 27 31 66 67 72 73 74 75 76", "Implicit text alignment attrib"
	    "utes should affect the position of a horizontal text rectangle i"
	    "n accordance with the values returned by <inquire text extent>.", 
	    29L, 157L);
    dchpfv_("IMPLICIT ALIGNMENT FOR HORIZONTAL TEXT: Which text primitive is"
	    " NOT aligned within the dotted text extent rectangle on the dash"
	    "ed baseline?", &numlin, &perm[numlin - 1], 139L);
#else /* NO_PROTO */
    setmsg_("16 27 31 66 67 72 73 74 75 76", "Implicit text alignment attrib\
utes should affect the position of a horizontal text rectangle in accordance\
 with the values returned by <inquire text extent>.", 29L, 157L);
    dchpfv_("IMPLICIT ALIGNMENT FOR HORIZONTAL TEXT: Which text primitive is\
 NOT aligned within the dotted text extent rectangle on the dashed baseline?",
	     &numlin, &perm[numlin - 1], 139L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  use <inquire text extent> on vertical txstr to determine: */
/*    ntxwd  = nominal width of text extent rectangle */
/*    ntxht  = nominal height of text extent rectangle */
/*    vtab,htab = normalized heights and widths */
    txexal_(&c__2, &c__3, txstr, &ntxwd, &ntxht, htab, vtab, 8L);
/*  table of alignments and paths to be tested: */

/*       hor-align  vert-align  text path */
/*       algnh      algnv       algntp */
/*       ---------  ----------  --------- */
/*    1: right      top         up */
/*    2: left       cap         down */
/*    3: center     half        up */
/*    4: center     base        down */
/*    5: left       bottom      up */
/*    6: right      bottom      down */
    setval_("3,1,2,2,1,3", algnh, 11L);
    setval_("1,2,3,4,5,5", algnv, 11L);
    setval_("2,3,2,3,2,3", algntp, 11L);
    numlin = 6;
    rnperm_(&numlin, perm);
#ifndef NO_PROTO
    xincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    xincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    xleft = xincr;
/*  scale to fit */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = .7f / ntxht, r__2 = xincr * .8f / ntxwd;
#else /* NO_PROTO */
    r__1 = (float).7 / ntxht, r__2 = xincr * (float).8 / ntxwd;
#endif /* NO_PROTO */
    chht = dmin(r__1,r__2);
/*  draw and label 6 identical vertical text rectangles, */
/*    using dotted lines, distinct color, */
/*    placed adjacent left-to-right and labelled 1-6 */
    nstxci (&c__1);
    nstxal (&c__2, &c__5);
    nsplci (&c__2);
#ifndef NO_PROTO
    yhi = .85f;
#else /* NO_PROTO */
    yhi = (float).85;
#endif /* NO_PROTO */
    ylo = yhi - chht * ntxht;
    xhalf = chht * ntxwd / 2;
    ya[0] = ylo;
    ya[1] = yhi;
/*  char height for label */
    nschh (&c_b57);
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
	xmid = xleft + (ix - 1) * xincr;
	nsln (&c__3);
	r__1 = xmid - xhalf;
	r__2 = xmid + xhalf;
	drwrec_(&r__1, &r__2, &ylo, &yhi);
	nsln (&c__2);
	xa[0] = xmid;
	xa[1] = xa[0];
	npl (&c__2, xa, ya);
	s_wsfi(&io___37);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	ntx (&xmid, &c_b66, dig2, 2L);
/* L700: */
    }
/*  char height for text under test */
    nschh (&chht);
/*  draw in text */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  set desired x-location based on perm(ix); find left of rectangle 
*/
	xlo = xleft - xhalf + xincr * (perm[ix - 1] - 1);
/*  calculate txpos = text position, so as to fit text */
/*    into expected box, using values from algnh(ix),algnv(ix) */
	txposx = xlo + chht * htab[algnh[ix - 1] - 1];
	txposy = ylo + chht * vtab[algnv[ix - 1] - 1];
/*  if ix=6 then change txpos to generate incorrect result */
	if (ix == numlin) {
#ifndef NO_PROTO
	    txposy += (rndint_(&c__0, &c__1) - .5f) * .1f;
#else /* NO_PROTO */
	    txposy += (rndint_(&c__0, &c__1) - (float).5) * (float).1;
#endif /* NO_PROTO */
	}
/*  set text alignment = algnh(ix), algnv(ix) */
	nstxal (&algnh[ix - 1], &algnv[ix - 1]);
/*  set text path = algntp(ix) */
	nstxp (&algntp[ix - 1]);
/*  draw text at txpos */
	ntx (&txposx, &txposy, txstr, 8L);
/* L800: */
    }
#ifndef NO_PROTO
    setmsg_("16 27 31 65 66 67 72 73 74 75", "Explicit text alignment attrib"
	    "utes should affect the position of a vertical text rectangle in "
	    "accordance with the values returned by <inquire text extent>.", 
	    29L, 155L);
    dchpfv_("EXPLICIT ALIGNMENT FOR VERTICAL TEXT: Which text primitive is N"
	    "OT aligned within the dotted text extent rectangle on the dashed"
	    " centerline?", &numlin, &perm[numlin - 1], 139L);
#else /* NO_PROTO */
    setmsg_("16 27 31 65 66 67 72 73 74 75", "Explicit text alignment attrib\
utes should affect the position of a vertical text rectangle in accordance w\
ith the values returned by <inquire text extent>.", 29L, 155L);
    dchpfv_("EXPLICIT ALIGNMENT FOR VERTICAL TEXT: Which text primitive is N\
OT aligned within the dotted text extent rectangle on the dashed centerline?",
	     &numlin, &perm[numlin - 1], 139L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  table of requested and expected alignments and paths to be tested: */

/*                  requested:             | expected: */
/*       text path  hor-align  vert-align  | hor-align  vert-align */
/*       algntp     ralgnh     ralgnv      | ealgnh     ealgnv */
/*       ---------  ---------  ----------  | ---------  ---------- */
/*    1: up         normal     normal      | center     base */
/*    2: down       normal     normal      | center     top */
/*    3: up         right      normal      | right      base */
/*    4: down       normal     half        | center     half */
/*    5: up         normal     normal      | center     base */
    setval_("0,0,3,0,0", ralgnh, 9L);
    setval_("0,0,0,3,0", ralgnv, 9L);
    setval_("2,2,3,2,2", ealgnh, 9L);
    setval_("4,1,4,3,4", ealgnv, 9L);
    numlin = 5;
    rnperm_(&numlin, perm);
#ifndef NO_PROTO
    xincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    xincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    xleft = xincr;
/*  scale to fit */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = .7f / ntxht, r__2 = xincr * .8f / ntxwd;
#else /* NO_PROTO */
    r__1 = (float).7 / ntxht, r__2 = xincr * (float).8 / ntxwd;
#endif /* NO_PROTO */
    chht = dmin(r__1,r__2);
/*  draw and label 5 identical vertical text rectangles, */
/*    using dotted lines, distinct color, */
/*    placed adjacent left-to-right and labelled 1-5 */
    nstxci (&c__1);
    nstxal (&c__2, &c__5);
    nsplci (&c__2);
#ifndef NO_PROTO
    yhi = .85f;
#else /* NO_PROTO */
    yhi = (float).85;
#endif /* NO_PROTO */
    ylo = yhi - chht * ntxht;
    xhalf = chht * ntxwd / 2;
/*  char height for label */
    nschh (&c_b57);
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
	xmid = xleft + (ix - 1) * xincr;
	nsln (&c__3);
	r__1 = xmid - xhalf;
	r__2 = xmid + xhalf;
	drwrec_(&r__1, &r__2, &ylo, &yhi);
	nsln (&c__2);
	xa[0] = xmid;
	xa[1] = xa[0];
	npl (&c__2, xa, ya);
	s_wsfi(&io___38);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	ntx (&xmid, &c_b66, dig2, 2L);
/* L900: */
    }
/*  char height for text under test */
    nschh (&chht);
/*  draw in text */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  set desired x-location based on perm(ix); find left of rectangle 
*/
	xlo = xleft - xhalf + xincr * (perm[ix - 1] - 1);
/*  calculate txpos = text position, so as to fit text */
/*    into expected box, using values from ealgnh(ix),ealgnv(ix) */
	txposx = xlo + chht * htab[ealgnh[ix - 1] - 1];
	txposy = ylo + chht * vtab[ealgnv[ix - 1] - 1];
/*  if ix=5 then change txpos to generate incorrect result */
	if (ix == numlin) {
#ifndef NO_PROTO
	    txposy += (rndint_(&c__0, &c__1) - .5f) * .1f;
#else /* NO_PROTO */
	    txposy += (rndint_(&c__0, &c__1) - (float).5) * (float).1;
#endif /* NO_PROTO */
	}
/*  set text alignment = ralgnh(ix), ralgnv(ix) */
	nstxal (&ralgnh[ix - 1], &ralgnv[ix - 1]);
/*  set text path = algntp(ix) */
	nstxp (&algntp[ix - 1]);
/*  draw text at txpos */
	ntx (&txposx, &txposy, txstr, 8L);
/* L1000: */
    }
#ifndef NO_PROTO
    setmsg_("16 27 31 66 67 72 73 74 75 76", "Implicit text alignment attrib"
	    "utes should affect the position of a vertical text rectangle in "
	    "accordance with the values returned by <inquire text extent>.", 
	    29L, 155L);
    dchpfv_("IMPLICIT ALIGNMENT FOR VERTICAL TEXT: Which text primitive is N"
	    "OT aligned within the dotted text extent rectangle on the dashed"
	    " centerline?", &numlin, &perm[numlin - 1], 139L);
#else /* NO_PROTO */
    setmsg_("16 27 31 66 67 72 73 74 75 76", "Implicit text alignment attrib\
utes should affect the position of a vertical text rectangle in accordance w\
ith the values returned by <inquire text extent>.", 29L, 155L);
    dchpfv_("IMPLICIT ALIGNMENT FOR VERTICAL TEXT: Which text primitive is N\
OT aligned within the dotted text extent rectangle on the dashed centerline?",
	     &numlin, &perm[numlin - 1], 139L);
#endif /* NO_PROTO */
    nemst (&c__102);
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

