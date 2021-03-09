/* fort/04/02/03/01/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b14 = 1.f;
static real c_b15 = 0.f;
#else /* NO_PROTO */
static real c_b14 = (float)1.;
static real c_b15 = (float)0.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b25 = .1f;
static real c_b30 = .5f;
static real c_b31 = .9f;
#else /* NO_PROTO */
static real c_b25 = (float).1;
static real c_b30 = (float).5;
static real c_b31 = (float).9;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b39 = 22.2f;
static real c_b40 = 2.f;
static real c_b41 = 3.f;
static real c_b45 = .15f;
#else /* NO_PROTO */
static real c_b39 = (float)22.2;
static real c_b40 = (float)2.;
static real c_b41 = (float)3.;
static real c_b45 = (float).15;
#endif /* NO_PROTO */
static integer c__4 = 4;
#ifndef NO_PROTO
static real c_b53 = .04f;
static real c_b55 = .2f;
static real c_b56 = .8f;
static real c_b84 = .85f;
#else /* NO_PROTO */
static real c_b53 = (float).04;
static real c_b55 = (float).2;
static real c_b56 = (float).8;
static real c_b84 = (float).85;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.01/06                        * */
/*  *    TEST TITLE : Text path and character height,       * */
/*  *                 expansion factor, spacing, and up     * */
/*  *                 vector                                * */
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
    real r__1, r__2, r__3, r__4, r__5;

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
    static real b2, bb, xa[5], ya[5];
    static integer ix, icx;
    static char msg[200];
    static real xhi, yhi;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static real xlo;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static char dig2[2];
    static real chht;
    static integer ipar;
    static real chsp, chxp;
    static integer txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static real xpos, ypos, ytop, txrx[2], txry[2], rdum1, rdum2, ncbwd, 
	    ncbht;
    static integer ngcol;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nschh (real *), inmsg_(char *, 
	    ftnlen);
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nschh (), inmsg_();
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static real yincr, boxht, boxwd, xincr, xcent;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *), nsatp (
	    integer *), nexst (integer *), nopst (integer *), nsvwi (integer *
	    ), nstxp (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst (), nsatp (), nexst (), 
	    nopst (), nsvwi (), nstxp ();
#endif /* NO_PROTO */
    static char txstr[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxx (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, char *, integer *, real *
	    , real *, real *, real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx ();
#endif /* NO_PROTO */
    static real ncbwdi, ncbhti;
    static integer ngline, bestfn, errind, numlin, numcol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer picstr;
    static real ncbhtw, ncbwdw, boxinc, boxhtw, boxwdw, boxhti, boxwdi;
#ifndef NO_PROTO
    extern doublereal basbot_(integer *, integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *), setasf_(
	    integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern doublereal basbot_();
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_(), setasf_(), 
	    nstxpr ();
#endif /* NO_PROTO */
    static char ptxstr[6];
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    txpcup_(char *, ftnlen), chkinq_(char *, integer *, ftnlen), 
	    nstxfn (integer *), numlab_(integer *, real *, real *, real *), 
	    nstxal (integer *, integer *), nschsp (real *), nschxp (real *), 
	    nsplci (integer *), drwrec_(real *, real *, real *, real *), 
	    hlfbox_(real *, real *, real *, real *, char *, ftnlen), nsatch (
	    real *), nsatcu (real *, real *), nsatal (integer *, integer *), 
	    dchpfv_(char *, integer *, integer *, ftnlen), varfnt_(integer *, 
	    real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), txpcup_(), chkinq_(), nstxfn (), 
	    numlab_(), nstxal (), nschsp (), nschxp (), nsplci (), drwrec_(), 
	    hlfbox_(), nsatch (), nsatcu (), nsatal (), dchpfv_(), varfnt_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___35 = { 0, dig2, 0, "(I1,A)", 2, 1 };
    static icilist io___43 = { 0, msg, 0, "(A,I6,A)", 200, 1 };
    static icilist io___51 = { 0, msg, 0, "(A,I6,A)", 200, 1 };
    static icilist io___52 = { 0, dig2, 0, "(I1,A)", 2, 1 };


/* aspect source */
/*                bundled     individual */
/* linetype */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    initgl_("04.02.03.01/06", 14L);
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
/*  always use STROKE */
    nstxpr (&c__2);
/*  set up 102 as sub-structure */
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
#ifndef NO_PROTO
    setmsg_("11 14 31 64 65 66 67 79 80 81", "Text path should specify the d"
	    "irection in which successive characters are generated and charac"
	    "ter up vector should rotate the resulting primitive.", 29L, 146L);

#else /* NO_PROTO */
    setmsg_("11 14 31 64 65 66 67 79 80 81", "Text path should specify the d\
irection in which successive characters are generated and character up vecto\
r should rotate the resulting primitive.", 29L, 146L);
#endif /* NO_PROTO */
    txpcup_("T", 1L);
    nemst (&c__102);
/*  use <inquire text extent> to determine, for font #1: */
/*    ncbht = nominal character body height */
/*    ncbwd = nominal character body width */
    s_copy(txstr, "WWiig!", 6L, 6L);
    nqtxx (&dialog_1.specwt, &c__1, &c_b14, &c_b15, &c_b14, &c__0, &c__1, &
	    c__5, txstr, &errind, txrx, txry, &rdum1, &rdum2, 6L);
    chkinq_("pqtxx", &errind, 5L);
    ncbht = (r__1 = txry[1] - txry[0], dabs(r__1));
    ncbwd = (r__1 = txrx[1] - txrx[0], dabs(r__1)) / 6;
/*  set text path = RIGHT, font = 1 */
    nstxp (&c__0);
    nstxfn (&c__1);
    bb = basbot_(&dialog_1.specwt, &c__1);
/*  numlin = number of lines = 6 */
    numlin = 6;
/*  ngline = random number from 1 to numlin */
    ngline = rndint_(&c__1, &numlin);
/*  display and box each line, doing NGLINE incorrectly */
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
    ytop = 1 - yincr * 1.5f;
    r__1 = ytop + yincr * .4f;
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
    ytop = 1 - yincr * (float)1.5;
    r__1 = ytop + yincr * (float).4;
#endif /* NO_PROTO */
    numlab_(&numlin, &c_b25, &r__1, &yincr);
    nstxal (&c__1, &c__5);
    ypos = ytop;
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  ensure various character spacings */
#ifndef NO_PROTO
	chsp = ix * .3f - .7f;
#else /* NO_PROTO */
	chsp = ix * (float).3 - (float).7;
#endif /* NO_PROTO */
/*  randomly select a character height and expansion factor */
/*  to fit on one line */
L110:
	chht = rndrl_(&c_b30, &c_b31) * yincr / ncbht;
/*  as character spacings get larger, range of expansion factors */
/*  shifts to lower values */
#ifndef NO_PROTO
	r__1 = 1.5f - ix * .2f;
	r__2 = 2.2f - ix * .2f;
#else /* NO_PROTO */
	r__1 = (float)1.5 - ix * (float).2;
	r__2 = (float)2.2 - ix * (float).2;
#endif /* NO_PROTO */
	chxp = rndrl_(&r__1, &r__2);
/*  calculate expected character boxes */
	boxht = chht * ncbht;
	boxwd = chht * ncbwd * dabs(chxp);
	boxinc = boxwd + chht * chsp;
/*  check line fit */
#ifndef NO_PROTO
	if (boxinc * 6 > .8f) {
#else /* NO_PROTO */
	if (boxinc * 6 > (float).8) {
#endif /* NO_PROTO */
	    goto L110;
	}
/*  only the magnitude of character expansion should affect text */
	if (ix % 2 == 1) {
	    chxp = -(doublereal)chxp;
	}
	nschh (&chht);
	nschsp (&chsp);
	nschxp (&chxp);
/*  if (ix = ngline) distort character boxes */
	if (ix == ngline) {
#ifndef NO_PROTO
	    boxinc *= .8f;
#else /* NO_PROTO */
	    boxinc *= (float).8;
#endif /* NO_PROTO */
	}
/*  draw in character boxes, using dotted line style, color #2 */
	nsln (&c__3);
	nsplci (&c__2);
	ipar = 1;
	b2 = boxht / 2;
#ifndef NO_PROTO
	r__1 = boxinc * 5.5f + .15f;
#else /* NO_PROTO */
	r__1 = boxinc * (float)5.5 + (float).15;
#endif /* NO_PROTO */
	r__2 = boxinc;
#ifndef NO_PROTO
	for (xlo = .15f; r__2 < 0 ? xlo >= r__1 : xlo <= r__1; xlo += r__2) {
	    if (chsp >= 0.f) {
#else /* NO_PROTO */
	for (xlo = (float).15; r__2 < 0 ? xlo >= r__1 : xlo <= r__1; xlo += 
		r__2) {
	    if (chsp >= (float)0.) {
#endif /* NO_PROTO */
		r__3 = xlo + boxwd;
		r__4 = ypos + boxht;
		drwrec_(&xlo, &r__3, &ypos, &r__4);
	    } else {
		ipar = -ipar;
		r__3 = ypos + b2;
		r__4 = ipar * b2;
		hlfbox_(&xlo, &r__3, &boxwd, &r__4, "Y", 1L);
	    }
/* L120: */
	}
/*  draw in base line, using dashed line style, color #3 */
	nsln (&c__2);
	nsplci (&c__3);
#ifndef NO_PROTO
	xa[0] = .15f;
	xa[1] = boxinc * 5 + .15f + boxwd;
#else /* NO_PROTO */
	xa[0] = (float).15;
	xa[1] = boxinc * 5 + (float).15 + boxwd;
#endif /* NO_PROTO */
	ya[0] = ypos + chht * bb;
	ya[1] = ya[0];
	npl (&c__2, xa, ya);
/*  try to confuse the issue */
	nsatch (&c_b39);
	nsatcu (&c_b40, &c_b41);
	nsatp (&c__1);
	nsatal (&c__1, &c__5);
/*  display text on line ix */
	ntx (&c_b45, &ypos, txstr, 6L);
/*  next ix */
	ypos -= yincr;
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("11 18 27 31 35 36 37 41 42 43 58 59 60 61 66 67 69", "The size "
	    "and shape of a text string displayed with STROKE precision in a "
	    "monospaced font on a horizontal text path should conform exactly"
	    " to the character height, expansion factor, and spacing in effec"
	    "t.", 50L, 203L);
    dchpfv_("CHARACTER HEIGHT, EXPANSION, AND SPACING IN HORIZONTAL TEXT: In"
	    " which line are the characters of the text string NOT aligned wi"
	    "thin dotted character boxes and on the dashed baseline?", &numlin,
	     &ngline, 182L);
#else /* NO_PROTO */
    setmsg_("11 18 27 31 35 36 37 41 42 43 58 59 60 61 66 67 69", "The size \
and shape of a text string displayed with STROKE precision in a monospaced f\
ont on a horizontal text path should conform exactly to the character height\
, expansion factor, and spacing in effect.", 50L, 203L);
    dchpfv_("CHARACTER HEIGHT, EXPANSION, AND SPACING IN HORIZONTAL TEXT: In\
 which line are the characters of the text string NOT aligned within dotted \
character boxes and on the dashed baseline?", &numlin, &ngline, 182L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
/*  numcol = number of columns = 6 */
    numcol = 6;
/*  ngcol  = random number from 1 to numcol */
    ngcol = rndint_(&c__1, &numcol);
/*  display and box each column, doing NGCOL incorrectly */
#ifndef NO_PROTO
    xincr = 1.f / (numcol + 1);
#else /* NO_PROTO */
    xincr = (float)1. / (numcol + 1);
#endif /* NO_PROTO */
    xcent = xincr;
/*  draw labels across top of columns */
    nstxal (&c__2, &c__4);
    nschh (&c_b53);
    nstxfn (&c__1);
    nschsp (&c_b55);
    nschxp (&c_b56);
    xpos = xcent;
    i__1 = numcol;
    for (ix = 1; ix <= i__1; ++ix) {
	s_wsfi(&io___35);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	ntx (&xpos, &c_b31, dig2, 2L);
	xpos += xincr;
/* L190: */
    }
/*  set text path = DOWN, font = 1 */
    nstxp (&c__3);
    nstxal (&c__2, &c__1);
    xpos = xcent;
    i__1 = numcol;
    for (ix = 1; ix <= i__1; ++ix) {
/*  ensure various character spacings */
#ifndef NO_PROTO
	chsp = ix * .3f - .7f;
#else /* NO_PROTO */
	chsp = ix * (float).3 - (float).7;
#endif /* NO_PROTO */
/*  randomly select a character height, expansion factor, and */
/*  spacing, to fit in one column */
L210:
/*  as character spacings get larger, range of character heights */
/*  shifts to lower values */
/* Computing MAX */
#ifndef NO_PROTO
	r__1 = .3f, r__3 = 1.f - ix * .2f;
#else /* NO_PROTO */
	r__1 = (float).3, r__3 = (float)1. - ix * (float).2;
#endif /* NO_PROTO */
	r__2 = dmax(r__1,r__3);
	chht = rndrl_(&r__2, &c_b14) / (ncbht * 6);
	chxp = rndrl_(&c_b30, &c_b41);
/*  calculate expected character boxes */
	boxwd = ncbwd * chht * chxp;
	boxht = chht * ncbht;
	boxinc = chht * (ncbht + chsp);
/*  check column fit */
#ifndef NO_PROTO
	if (boxwd > xincr * .9f) {
#else /* NO_PROTO */
	if (boxwd > xincr * (float).9) {
#endif /* NO_PROTO */
	    goto L210;
	}
#ifndef NO_PROTO
	if (boxinc * 6 > .8f) {
#else /* NO_PROTO */
	if (boxinc * 6 > (float).8) {
#endif /* NO_PROTO */
	    goto L210;
	}
/*  only the magnitude of character expansion should affect text */
	if (ix % 2 == 1) {
	    chxp = -(doublereal)chxp;
	}
	nschh (&chht);
	nschsp (&chsp);
	nschxp (&chxp);
/*  if (ix = ngcol) distort character boxes */
	if (ix == ngcol) {
#ifndef NO_PROTO
	    boxinc *= .8f;
#else /* NO_PROTO */
	    boxinc *= (float).8;
#endif /* NO_PROTO */
	}
/*  draw in character boxes, using dotted line style, color #2 */
	nsln (&c__3);
	nsplci (&c__2);
	ipar = 1;
	b2 = boxwd / 2;
#ifndef NO_PROTO
	r__2 = .85f - boxinc * 5.5f;
#else /* NO_PROTO */
	r__2 = (float).85 - boxinc * (float)5.5;
#endif /* NO_PROTO */
	r__1 = -(doublereal)boxinc;
#ifndef NO_PROTO
	for (yhi = .85f; r__1 < 0 ? yhi >= r__2 : yhi <= r__2; yhi += r__1) {
	    if (chsp >= 0.f) {
#else /* NO_PROTO */
	for (yhi = (float).85; r__1 < 0 ? yhi >= r__2 : yhi <= r__2; yhi += 
		r__1) {
	    if (chsp >= (float)0.) {
#endif /* NO_PROTO */
		r__3 = xpos - b2;
		r__4 = xpos + b2;
		r__5 = yhi - boxht;
		drwrec_(&r__3, &r__4, &r__5, &yhi);
	    } else {
		ipar = -ipar;
		r__3 = ipar * b2;
		r__4 = -(doublereal)boxht;
		hlfbox_(&xpos, &yhi, &r__3, &r__4, "X", 1L);
	    }
/* L220: */
	}
/*  draw in center line, using dashed line style, color #3 */
	nsln (&c__2);
	nsplci (&c__3);
	xa[0] = xpos;
	xa[1] = xpos;
#ifndef NO_PROTO
	ya[0] = .85f;
	ya[1] = .85f - boxinc * 5 - boxht;
#else /* NO_PROTO */
	ya[0] = (float).85;
	ya[1] = (float).85 - boxinc * 5 - boxht;
#endif /* NO_PROTO */
	npl (&c__2, xa, ya);
/*  try to confuse the issue */
	nsatch (&c_b39);
	nsatcu (&c_b40, &c_b41);
	nsatp (&c__1);
	nsatal (&c__1, &c__5);
/*  display text in column ix */
	ntx (&xpos, &c_b84, txstr, 6L);
/*  next ix */
	xpos += xincr;
/* L200: */
    }
#ifndef NO_PROTO
    setmsg_("11 18 27 31 35 36 37 41 42 43 58 59 60 61 66 67 68", "The size "
	    "and shape of a text string displayed with STROKE precision in a "
	    "monospaced font on a vertical text path should conform exactly t"
	    "o the character height, expansion factor, and spacing in effect.",
	     50L, 201L);
    dchpfv_("CHARACTER HEIGHT, EXPANSION, AND SPACING IN VERTICAL TEXT: In w"
	    "hich column are the characters of the text string NOT aligned wi"
	    "thin dotted character boxes and on the dashed centerline?", &
	    numcol, &ngcol, 184L);
#else /* NO_PROTO */
    setmsg_("11 18 27 31 35 36 37 41 42 43 58 59 60 61 66 67 68", "The size \
and shape of a text string displayed with STROKE precision in a monospaced f\
ont on a vertical text path should conform exactly to the character height, \
expansion factor, and spacing in effect.", 50L, 201L);
    dchpfv_("CHARACTER HEIGHT, EXPANSION, AND SPACING IN VERTICAL TEXT: In w\
hich column are the characters of the text string NOT aligned within dotted \
character boxes and on the dashed centerline?", &numcol, &ngcol, 184L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
/*  bestfn = a stroke text font other than 1, preferably not #2 and */
/*     not monospaced */
    varfnt_(&bestfn, &ncbhtw, &ncbwdw, &ncbhti, &ncbwdi);
    if (bestfn == 1) {
	inmsg_("Skipping tests for fonts other than #1; none available.", 55L)
		;
	goto L666;
    } else {
	s_wsfi(&io___43);
	do_fio(&c__1, "Using #", 7L);
	do_fio(&c__1, (char *)&bestfn, (ftnlen)sizeof(integer));
	do_fio(&c__1, " as alternative font for horizontal text path.", 46L);
	e_wsfi();
	inmsg_(msg, 200L);
    }
/*  set text path = LEFT */
    nstxp (&c__1);
    nstxfn (&bestfn);
    bb = basbot_(&dialog_1.specwt, &bestfn);
/*  numlin = number of lines = 6 */
    numlin = 6;
/*  ngline = random number from 1 to numlin */
    ngline = rndint_(&c__1, &numlin);
/*  display and box each line, doing NGLINE incorrectly */
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
    ytop = 1 - yincr * 1.5f;
    r__1 = ytop + yincr * .4f;
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
    ytop = 1 - yincr * (float)1.5;
    r__1 = ytop + yincr * (float).4;
#endif /* NO_PROTO */
    numlab_(&numlin, &c_b25, &r__1, &yincr);
    nstxal (&c__1, &c__5);
    ypos = ytop;
    s_copy(ptxstr, "WWiiiW", 6L, 6L);
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  ensure various character spacings */
#ifndef NO_PROTO
	chsp = ix * .3f - .7f;
#else /* NO_PROTO */
	chsp = ix * (float).3 - (float).7;
#endif /* NO_PROTO */
/*  randomly select a character height, expansion factor, and */
/*  spacing, to fit on one line */
L410:
	chht = rndrl_(&c_b30, &c_b31) * yincr / ncbhtw;
/*  as character spacings get larger, range of expansion factors */
/*  shifts to lower values */
#ifndef NO_PROTO
	r__1 = 1.5f - ix * .2f;
	r__2 = 2.2f - ix * .2f;
#else /* NO_PROTO */
	r__1 = (float)1.5 - ix * (float).2;
	r__2 = (float)2.2 - ix * (float).2;
#endif /* NO_PROTO */
	chxp = rndrl_(&r__1, &r__2);
/*  calculate expected character boxes */
	boxhtw = chht * ncbhtw;
	boxwdw = chht * ncbwdw * dabs(chxp);
	boxhti = chht * ncbhti;
	boxwdi = chht * ncbwdi * dabs(chxp);
/*  check line fit */
#ifndef NO_PROTO
	if ((boxwdw + boxwdi) * 3 + chht * 5 * chsp > .8f) {
#else /* NO_PROTO */
	if ((boxwdw + boxwdi) * 3 + chht * 5 * chsp > (float).8) {
#endif /* NO_PROTO */
	    goto L410;
	}
/*  only the magnitude of character expansion should affect text */
	if (ix % 2 == 1) {
	    chxp = -(doublereal)chxp;
	}
	nschh (&chht);
	nschsp (&chsp);
	nschxp (&chxp);
/*  if (ix = ngline) distort character boxes */
	if (ix == ngline) {
#ifndef NO_PROTO
	    boxwdw *= .7f;
#else /* NO_PROTO */
	    boxwdw *= (float).7;
#endif /* NO_PROTO */
	}
/*  draw in character boxes, using dotted line style, color #2 */
	nsln (&c__3);
	nsplci (&c__2);
#ifndef NO_PROTO
	xlo = .15f;
#else /* NO_PROTO */
	xlo = (float).15;
#endif /* NO_PROTO */
	ipar = 1;
/*  backwards, because path is to the left */
	for (icx = 6; icx >= 1; --icx) {
	    if (ptxstr[icx - 1] == 'W') {
		boxwd = boxwdw;
		boxht = boxhtw;
	    } else {
		boxwd = boxwdi;
		boxht = boxhti;
	    }
	    xhi = xlo + boxwd;
#ifndef NO_PROTO
	    if (chsp >= 0.f) {
#else /* NO_PROTO */
	    if (chsp >= (float)0.) {
#endif /* NO_PROTO */
		r__1 = ypos + boxht;
		drwrec_(&xlo, &xhi, &ypos, &r__1);
	    } else {
		b2 = boxht / 2;
		ipar = -ipar;
		r__1 = ypos + b2;
		r__2 = ipar * b2;
		hlfbox_(&xlo, &r__1, &boxwd, &r__2, "Y", 1L);
	    }
	    xlo = xlo + boxwd + chht * chsp;
/* L420: */
	}
/*  draw in base line, using dashed line style, color #3 */
	nsln (&c__2);
	nsplci (&c__3);
#ifndef NO_PROTO
	xa[0] = .15f;
#else /* NO_PROTO */
	xa[0] = (float).15;
#endif /* NO_PROTO */
	xa[1] = xhi;
	ya[0] = ypos + chht * bb;
	ya[1] = ya[0];
	npl (&c__2, xa, ya);
/*  try to confuse the issue */
	nsatch (&c_b39);
	nsatcu (&c_b40, &c_b41);
	nsatp (&c__1);
	nsatal (&c__1, &c__5);
/*  display text on line ix */
	ntx (&c_b45, &ypos, ptxstr, 6L);
/*  next ix */
	ypos -= yincr;
/* L400: */
    }
#ifndef NO_PROTO
    setmsg_("11 27 31 35 36 37 41 42 43 58 59 60 61 66 67 69", "The size and"
	    " shape of a text string displayed with STROKE precision in any f"
	    "ont on a horizontal text path should conform exactly to the char"
	    "acter height, expansion factor, and spacing in effect.", 47L, 
	    194L);
    dchpfv_("CHARACTER HEIGHT, EXPANSION, AND SPACING IN HORIZONTAL TEXT: In"
	    " which line are the characters of the text string NOT aligned wi"
	    "thin dotted character boxes and on the dashed baseline?", &numlin,
	     &ngline, 182L);
#else /* NO_PROTO */
    setmsg_("11 27 31 35 36 37 41 42 43 58 59 60 61 66 67 69", "The size and\
 shape of a text string displayed with STROKE precision in any font on a hor\
izontal text path should conform exactly to the character height, expansion \
factor, and spacing in effect.", 47L, 194L);
    dchpfv_("CHARACTER HEIGHT, EXPANSION, AND SPACING IN HORIZONTAL TEXT: In\
 which line are the characters of the text string NOT aligned within dotted \
character boxes and on the dashed baseline?", &numlin, &ngline, 182L);
#endif /* NO_PROTO */
    nemst (&c__102);
/*  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */
/*  bestfn = a stroke text font other than 1, preferably not #2 and */
/*     not monospaced */
    varfnt_(&bestfn, &ncbhtw, &ncbwdw, &ncbhti, &ncbwdi);
    s_wsfi(&io___51);
    do_fio(&c__1, "Using #", 7L);
    do_fio(&c__1, (char *)&bestfn, (ftnlen)sizeof(integer));
    do_fio(&c__1, " as alternative font for vertical text path.", 44L);
    e_wsfi();
    inmsg_(msg, 200L);
/*  numcol = number of columns = 6 */
    numcol = 6;
/*  ngcol  = random number from 1 to numcol */
    ngcol = rndint_(&c__1, &numcol);
/*  display and box each column, doing NGCOL incorrectly */
#ifndef NO_PROTO
    xincr = 1.f / (numcol + 1);
#else /* NO_PROTO */
    xincr = (float)1. / (numcol + 1);
#endif /* NO_PROTO */
    xcent = xincr;
/*  draw labels across top of columns */
    nstxal (&c__2, &c__4);
    nschh (&c_b53);
    nstxfn (&c__1);
    nschsp (&c_b55);
    nschxp (&c_b56);
    xpos = xcent;
    i__1 = numcol;
    for (ix = 1; ix <= i__1; ++ix) {
	s_wsfi(&io___52);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	ntx (&xpos, &c_b31, dig2, 2L);
	xpos += xincr;
/* L490: */
    }
/*  set text path = UP */
    nstxp (&c__2);
    nstxfn (&bestfn);
    nstxal (&c__2, &c__1);
    xpos = xcent;
    i__1 = numcol;
    for (ix = 1; ix <= i__1; ++ix) {
/*  ensure various character spacings */
#ifndef NO_PROTO
	chsp = ix * .3f - .7f;
#else /* NO_PROTO */
	chsp = ix * (float).3 - (float).7;
#endif /* NO_PROTO */
/*  randomly select a character height, expansion factor, and */
/*  spacing, to fit in one column */
L510:
/*  as character spacings get larger, range of character heights */
/*  shifts to lower values */
/* Computing MAX */
#ifndef NO_PROTO
	r__2 = .3f, r__3 = 1.f - ix * .2f;
#else /* NO_PROTO */
	r__2 = (float).3, r__3 = (float)1. - ix * (float).2;
#endif /* NO_PROTO */
	r__1 = dmax(r__2,r__3);
	chht = rndrl_(&r__1, &c_b14) / (ncbhtw * 6);
	chxp = rndrl_(&c_b30, &c_b41);
/*  calculate expected character boxes */
	boxhtw = chht * ncbhtw;
	boxwdw = chht * ncbwdw * dabs(chxp);
	boxhti = chht * ncbhti;
	boxwdi = chht * ncbwdi * dabs(chxp);
/*  check column fit */
#ifndef NO_PROTO
	if (boxwdw > xincr * .9f || boxwdi > xincr * .9f) {
#else /* NO_PROTO */
	if (boxwdw > xincr * (float).9 || boxwdi > xincr * (float).9) {
#endif /* NO_PROTO */
	    goto L510;
	}
#ifndef NO_PROTO
	if ((boxhtw + boxhti) * 3 + chht * 5 * chsp > .8f) {
#else /* NO_PROTO */
	if ((boxhtw + boxhti) * 3 + chht * 5 * chsp > (float).8) {
#endif /* NO_PROTO */
	    goto L510;
	}
/*  only the magnitude of character expansion should affect text */
	if (ix % 2 == 1) {
	    chxp = -(doublereal)chxp;
	}
	nschh (&chht);
	nschsp (&chsp);
	nschxp (&chxp);
/*  if (ix = ngcol) distort character boxes */
	if (ix == ngcol) {
#ifndef NO_PROTO
	    boxhtw *= .7f;
#else /* NO_PROTO */
	    boxhtw *= (float).7;
#endif /* NO_PROTO */
	}
/*  draw in character boxes, using dotted line style, color #2 */
	nsln (&c__3);
	nsplci (&c__2);
#ifndef NO_PROTO
	yhi = .85f;
#else /* NO_PROTO */
	yhi = (float).85;
#endif /* NO_PROTO */
	ipar = 1;
/*  backwards, because path is to the left */
	for (icx = 6; icx >= 1; --icx) {
	    if (ptxstr[icx - 1] == 'W') {
		boxwd = boxwdw;
		boxht = boxhtw;
	    } else {
		boxwd = boxwdi;
		boxht = boxhti;
	    }
	    b2 = boxwd / 2;
#ifndef NO_PROTO
	    if (chsp >= 0.f) {
#else /* NO_PROTO */
	    if (chsp >= (float)0.) {
#endif /* NO_PROTO */
		r__1 = xpos - b2;
		r__2 = xpos + b2;
		r__3 = yhi - boxht;
		drwrec_(&r__1, &r__2, &r__3, &yhi);
	    } else {
		ipar = -ipar;
		r__1 = ipar * b2;
		r__2 = -(doublereal)boxht;
		hlfbox_(&xpos, &yhi, &r__1, &r__2, "X", 1L);
	    }
	    yhi = yhi - boxht - chht * chsp;
/* L520: */
	}
/*  draw in center line, using dashed line style, color #3 */
	nsln (&c__2);
	nsplci (&c__3);
	xa[0] = xpos;
	xa[1] = xpos;
#ifndef NO_PROTO
	ya[0] = .85f;
#else /* NO_PROTO */
	ya[0] = (float).85;
#endif /* NO_PROTO */
	ya[1] = yhi + chht * chsp;
	npl (&c__2, xa, ya);
/*  try to confuse the issue */
	nsatch (&c_b39);
	nsatcu (&c_b40, &c_b41);
	nsatp (&c__1);
	nsatal (&c__1, &c__5);
/*  display text in column ix */
	ntx (&xpos, &c_b84, ptxstr, 6L);
/*  next ix */
	xpos += xincr;
/* L500: */
    }
#ifndef NO_PROTO
    setmsg_("11 27 31 35 36 37 41 42 43 58 59 60 61 66 67 68", "The size and"
	    " shape of a text string displayed with STROKE precision in any f"
	    "ont on a vertical text path should conform exactly to the charac"
	    "ter height, expansion factor, and spacing in effect.", 47L, 192L);

    dchpfv_("CHARACTER HEIGHT, EXPANSION, AND SPACING IN VERTICAL TEXT: In w"
	    "hich column are the characters of the text string NOT aligned wi"
	    "thin dotted character boxes and on the dashed centerline?", &
	    numcol, &ngcol, 184L);
#else /* NO_PROTO */
    setmsg_("11 27 31 35 36 37 41 42 43 58 59 60 61 66 67 68", "The size and\
 shape of a text string displayed with STROKE precision in any font on a ver\
tical text path should conform exactly to the character height, expansion fa\
ctor, and spacing in effect.", 47L, 192L);
    dchpfv_("CHARACTER HEIGHT, EXPANSION, AND SPACING IN VERTICAL TEXT: In w\
hich column are the characters of the text string NOT aligned within dotted \
character boxes and on the dashed centerline?", &numcol, &ngcol, 184L);
#endif /* NO_PROTO */
    nemst (&c__102);
L666:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

