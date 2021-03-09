/* fort/04/02/03/02/p13.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
static integer c__102 = 102;
#ifndef NO_PROTO
static real c_b45 = .04f;
#else /* NO_PROTO */
static real c_b45 = (float).04;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b51 = 1.f;
static real c_b52 = 0.f;
static real c_b59 = .95f;
#else /* NO_PROTO */
static real c_b51 = (float)1.;
static real c_b52 = (float)0.;
static real c_b59 = (float).95;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b77 = .3f;
static real c_b78 = 3.f;
#else /* NO_PROTO */
static real c_b77 = (float).3;
static real c_b78 = (float)3.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.02/13                        * */
/*  *    TEST TITLE : Appearance of all text fonts          * */
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
    address a__1[2];
    integer i__1, i__2[2];
    real r__1, r__2;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real xa[5], ya[5];
    static integer ix;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen), fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx (), fail_(), ifpf_();
#endif /* NO_PROTO */
    static real chht, ncsh, chsp;
    static char vlbl[2];
    static integer nfpp;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer txci;
    static real xpos, ypos, ytop, txrx[2], txry[2];
    static integer idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
    static integer elloc, ngcol;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nschh ();
#endif /* NO_PROTO */
    static real chexp;
    static integer numch, lnegx;
    static real chsiz, xleft, xincr;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static char chstr[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), inmsg_(char *, ftnlen), dynpf_(
	    char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), inmsg_(), dynpf_();
#endif /* NO_PROTO */
    static integer lstrk[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), unrep_(integer *, integer *
	    , integer *, char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), unrep_();
#endif /* NO_PROTO */
    static integer txfnt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst ();
#endif /* NO_PROTO */
    static integer lposx;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nqtxf (integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, integer *, real *, real *, integer *), nsvwi (integer *), 
	    nstxi (integer *), nstxp (integer *), nstxr (integer *, integer *,
	     integer *, integer *, real *, real *, integer *), nqtxx (integer 
	    *, integer *, real *, real *, real *, integer *, integer *, 
	    integer *, char *, integer *, real *, real *, real *, real *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nqtxf (), nsvwi (), nstxi (), 
	    nstxp (), nstxr (), nqtxx ();
#endif /* NO_PROTO */
    static integer unr1ls[20], unr2ls[20], unr1sz;
#ifndef NO_PROTO
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static integer unr2sz;
    static real offact;
    static integer lnegfn[200];
    static char tallch[15];
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer errind, thisfn, thispr, lposfn[200], lpospr[200], lnegpr[
	    200], lstrkx, picstr, numcol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer numsht, maxfnt;
    static char distrg[60], result[1], shrtch[15];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), chkinq_(char *, integer *, ftnlen)
	    , setmsg_(char *, char *, ftnlen, ftnlen), chkfnt_(integer *, 
	    integer *, integer *, integer *, char *, logical *, char *, 
	    ftnlen, ftnlen), nstxal (integer *, integer *), nsiasf (integer *,
	     integer *), nsplci (integer *), dchpfv_(char *, integer *, 
	    integer *, ftnlen), dilist_(char *, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), chkinq_(), 
	    setmsg_(), chkfnt_(), nstxal (), nsiasf (), nsplci (), dchpfv_(), 
	    dilist_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___35 = { 0, vlbl, 0, "(I1,A)", 2, 1 };


/* aspect identifier */
/* aspect source */
/*                bundled     individual */
/* linetype */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    initgl_("04.02.03.02/13", 14L);
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
    setasf_(&c__0);
/*  use structure 102 to hold changeable stuff */
    nexst (&c__102);
    nclst ();
    nopst (&c__102);
/*  use <inquire text facilities> to determine */
/*    lposfn = list of positive fonts and highest available precision */
/*             for each, other than fonts 1 and 2 */
/*    lnegfn = list of non-positive fonts and highest available precision 
*/
/*             for each */
/*    lstrk  = list of fonts available in STROKE precision */
    nqtxf (&dialog_1.specwt, &c__0, &errind, &nfpp, &idum1, &idum2, &idum3, &
	    rdum1, &rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    lposx = 0;
    lnegx = 0;
    lstrkx = 0;
    i__1 = nfpp;
    for (ix = 1; ix <= i__1; ++ix) {
	nqtxf (&dialog_1.specwt, &ix, &errind, &idum1, &thisfn, &thispr, &
		idum3, &rdum1, &rdum2, &idum4, &rdum3, &rdum4, &idum5);
	chkinq_("pqtxf", &errind, 5L);
/*  build list of stroke fonts */
	if (thispr == 2) {
	    ++lstrkx;
	    lstrk[lstrkx - 1] = thisfn;
	}
	if (thisfn > 2) {
	    elloc = iarfnd_(&thisfn, &lposx, lposfn);
	    if (elloc == 0) {
		++lposx;
		lposfn[lposx - 1] = thisfn;
		lpospr[lposx - 1] = thispr;
	    } else {
		if (thispr > lpospr[elloc - 1]) {
		    lpospr[elloc - 1] = thispr;
		}
	    }
	} else if (thisfn < 1) {
	    elloc = iarfnd_(&thisfn, &lnegx, lnegfn);
	    if (elloc == 0) {
		++lnegx;
		lnegfn[lnegx - 1] = thisfn;
		lnegpr[lnegx - 1] = thispr;
	    } else {
		if (thispr > lnegpr[elloc - 1]) {
		    lnegpr[elloc - 1] = thispr;
		}
	    }
	}
/* L100: */
    }
    maxfnt = 8;
    s_copy(chstr, "AaZz09$;^}", 10L, 10L);
    if (lposx <= 0) {
	inmsg_("No non-mandatory registered text fonts are supported.", 53L);
	goto L190;
    }
#ifndef NO_PROTO
    s_copy(msg, "NON-MANDATORY REGISTERED TEXT FONTS: Do all displayed, labe"
	    "lled text fonts agree with the corresponding description in the "
	    "ISO register?", 300L, 136L);
    setmsg_("3 5 6 38 39 40", "All positive text fonts should appear as spec"
	    "ified in the ISO register.", 14L, 71L);
#else /* NO_PROTO */
    s_copy(msg, "NON-MANDATORY REGISTERED TEXT FONTS: Do all displayed, labe\
lled text fonts agree with the corresponding description in the ISO register?"
	    , 300L, 136L);
    setmsg_("3 5 6 38 39 40", "All positive text fonts should appear as spec\
ified in the ISO register.", 14L, 71L);
#endif /* NO_PROTO */
/*  call routine to handle display */
#ifndef NO_PROTO
    chkfnt_(&lposx, lposfn, lpospr, &maxfnt, chstr, (logical*)&c__0, "U", 10L,
	     1L);
#else /* NO_PROTO */
    chkfnt_(&lposx, lposfn, lpospr, &maxfnt, chstr, &c__0, "U", 10L, 1L);
#endif /* NO_PROTO */
    dynpf_(msg, "Y", 300L, 1L);
    nemst (&c__102);
#ifndef NO_PROTO
    setmsg_("3 5 6 38 39 40 48 49", "All positive text fonts should appear a"
	    "s specified in the ISO register, even when less precision is req"
	    "uested than is available for the font.", 20L, 141L);
#else /* NO_PROTO */
    setmsg_("3 5 6 38 39 40 48 49", "All positive text fonts should appear a\
s specified in the ISO register, even when less precision is requested than \
is available for the font.", 20L, 141L);
#endif /* NO_PROTO */
/*  call routine to handle display */
#ifndef NO_PROTO
    chkfnt_(&lposx, lposfn, lpospr, &maxfnt, chstr, (logical*)&c__1, "U", 10L,
	     1L);
#else /* NO_PROTO */
    chkfnt_(&lposx, lposfn, lpospr, &maxfnt, chstr, &c__1, "U", 10L, 1L);
#endif /* NO_PROTO */
    dynpf_(msg, "Y", 300L, 1L);
    nemst (&c__102);
/*  end_pos: */
L190:
    if (lnegx <= 0) {
	inmsg_("No implementor defined text fonts are supported.", 48L);
	goto L390;
    }
#ifndef NO_PROTO
    s_copy(msg, "IMPLEMENTOR DEFINED TEXT FONTS: Do all displayed, labelled "
	    "text fonts agree with the corresponding description in the imple"
	    "mentor documentation? ", 300L, 145L);
    setmsg_("3 5 6 38 39 40", "All non-positive text fonts should appear as "
	    "specified in the implementor's documentation.", 14L, 90L);
#else /* NO_PROTO */
    s_copy(msg, "IMPLEMENTOR DEFINED TEXT FONTS: Do all displayed, labelled \
text fonts agree with the corresponding description in the implementor docum\
entation? ", 300L, 145L);
    setmsg_("3 5 6 38 39 40", "All non-positive text fonts should appear as \
specified in the implementor's documentation.", 14L, 90L);
#endif /* NO_PROTO */
/*  call routine to handle display */
#ifndef NO_PROTO
    chkfnt_(&lnegx, lnegfn, lnegpr, &maxfnt, chstr, (logical*)&c__0, "U", 10L,
	     1L);
#else /* NO_PROTO */
    chkfnt_(&lnegx, lnegfn, lnegpr, &maxfnt, chstr, &c__0, "U", 10L, 1L);
#endif /* NO_PROTO */
    dynpf_(msg, "Y", 300L, 1L);
    nemst (&c__102);
#ifndef NO_PROTO
    setmsg_("3 5 6 38 39 40 48 49", "All non-positive text fonts should appe"
	    "ar as specified in the implementor's documentation, even when le"
	    "ss precision is requested than is available for the font.", 20L, 
	    160L);
#else /* NO_PROTO */
    setmsg_("3 5 6 38 39 40 48 49", "All non-positive text fonts should appe\
ar as specified in the implementor's documentation, even when less precision\
 is requested than is available for the font.", 20L, 160L);
#endif /* NO_PROTO */
/*  call routine to handle display */
#ifndef NO_PROTO
    chkfnt_(&lnegx, lnegfn, lnegpr, &maxfnt, chstr, (logical*)&c__1, "U", 10L,
	     1L);
#else /* NO_PROTO */
    chkfnt_(&lnegx, lnegfn, lnegpr, &maxfnt, chstr, &c__1, "U", 10L, 1L);
#endif /* NO_PROTO */
    dynpf_(msg, "Y", 300L, 1L);
    nemst (&c__102);
/*  end_font_id: */
L390:
#ifndef NO_PROTO
    setmsg_("3 5 6 38 39 43 44 50 57 58 61 62", "In each text font, all char"
	    "acter bodies affected by the same character height, character ex"
	    "pansion factor, and character spacing should have the same heigh"
	    "t.", 32L, 157L);
#else /* NO_PROTO */
    setmsg_("3 5 6 38 39 43 44 50 57 58 61 62", "In each text font, all char\
acter bodies affected by the same character height, character expansion fact\
or, and character spacing should have the same height.", 32L, 157L);
#endif /* NO_PROTO */
/*  numcol = number of columns to display = 6 */
    numcol = 6;
/*  ngcol  = incorrect column = random number from 1 to numcol */
    ngcol = rndint_(&c__1, &numcol);
/*  set up for labels */
    nschh (&c_b45);
    nstxal (&c__1, &c__1);
    nstxp (&c__0);
    i__1 = numcol + 1;
    nstxi (&i__1);
    i__1 = numcol + 1;
    nstxr (&globnu_1.wkid, &i__1, &c__1, &c__2, &c_b51, &c_b52, &c__1);
/*  display labels for all numcol columns to be shown */
#ifndef NO_PROTO
    xleft = .05f;
#else /* NO_PROTO */
    xleft = (float).05;
#endif /* NO_PROTO */
    xpos = xleft;
#ifndef NO_PROTO
    xincr = .9f / numcol;
#else /* NO_PROTO */
    xincr = (float).9 / numcol;
#endif /* NO_PROTO */
    i__1 = numcol;
    for (ix = 1; ix <= i__1; ++ix) {
	s_wsfi(&io___35);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	ntx (&xpos, &c_b59, vlbl, 2L);
	xpos += xincr;
/* L500: */
    }
/*  set up short, tall characters */
    s_copy(shrtch, ",'_~;`.\"-=+*^@#", 15L, 15L);
    s_copy(tallch, "W|j(g!)Q[]/\\IMH", 15L, 15L);
/*  display vertical text */
    xpos = xleft;
#ifndef NO_PROTO
    chsp = .4f;
#else /* NO_PROTO */
    chsp = (float).4;
#endif /* NO_PROTO */
    nstxp (&c__3);
#ifndef NO_PROTO
    ytop = .85f;
#else /* NO_PROTO */
    ytop = (float).85;
#endif /* NO_PROTO */
/*  try to paint text and polylines different colors */
    nsiasf (&c__2, &c__1);
    nsplci (&c__2);
    i__1 = numcol;
    for (ix = 1; ix <= i__1; ++ix) {
/*  txfnt = random value from lstrk */
	txfnt = lstrk[rndint_(&c__1, &lstrkx) - 1];
/*  Use <inquire text extent> to determine */
/*  ncsh = (nominal vertical character body size / */
/*          requested character height)  for txfnt */
	nqtxx (&dialog_1.specwt, &txfnt, &c_b51, &c_b52, &c_b51, &c__3, &c__1,
		 &c__5, "Testing 123", &errind, txrx, txry, &rdum1, &rdum2, 
		11L);
	chkinq_("pqtxx", &errind, 5L);
	ncsh = (r__1 = txry[1] - txry[0], dabs(r__1)) / 11;
L610:
#ifndef NO_PROTO
	r__1 = .2f / numcol;
	r__2 = .6f / numcol;
#else /* NO_PROTO */
	r__1 = (float).2 / numcol;
	r__2 = (float).6 / numcol;
#endif /* NO_PROTO */
	chht = rndrl_(&r__1, &r__2);
	chexp = rndrl_(&c_b77, &c_b78);
/*  don't exceed column width */
#ifndef NO_PROTO
	if (chht * chexp >= xincr * .8f) {
#else /* NO_PROTO */
	if (chht * chexp >= xincr * (float).8) {
#endif /* NO_PROTO */
	    goto L610;
	}
/*  chsiz  = vertical distance per character */
	chsiz = chht * (ncsh + chsp);
/*  numch  = number of characters this string */
#ifndef NO_PROTO
	numch = (integer) ((ytop - .05f) / chsiz);
#else /* NO_PROTO */
	numch = (integer) ((ytop - (float).05) / chsiz);
#endif /* NO_PROTO */
/*  make sure numch between 4 and 25, else pick new values */
	if (numch < 4 || numch > 25) {
	    goto L610;
	}
/*  numsht = number of short characters = numch/2 */
	numsht = numch / 2;
/* Writing concatenation */
	i__2[0] = numsht, a__1[0] = shrtch;
	i__2[1] = numch - numsht, a__1[1] = tallch;
	s_cat(distrg, a__1, i__2, &c__2, 60L);
	nschh (&chht);
/*  display distrg at location ix */
	nstxi (&ix);
	nstxr (&globnu_1.wkid, &ix, &txfnt, &c__2, &chexp, &chsp, &c__1);
	ntx (&xpos, &ytop, distrg, numch);
/*  set offset factor to distort separators if this column no good */
	if (ix == ngcol) {
#ifndef NO_PROTO
	    offact = rndint_(&c__2, &c__3) * .4f;
#else /* NO_PROTO */
	    offact = rndint_(&c__2, &c__3) * (float).4;
#endif /* NO_PROTO */
	} else {
#ifndef NO_PROTO
	    offact = 1.f;
#else /* NO_PROTO */
	    offact = (float)1.;
#endif /* NO_PROTO */
	}
/*  draw horizontal lines between characters, assuming that chht, */
/*     chsp, and chexp are in effect, distorted by offact */
	xa[0] = xpos;
	xa[1] = xpos + chht * chexp;
/*  start in middle of character space between 1st and 2nd characters 
*/
#ifndef NO_PROTO
	r__1 = ytop - (numch - .5f) * chsiz;
#else /* NO_PROTO */
	r__1 = ytop - (numch - (float).5) * chsiz;
#endif /* NO_PROTO */
	r__2 = -(doublereal)chsiz * offact;
	for (ypos = ytop - chsiz + chsp * chht / 2; r__2 < 0 ? ypos >= r__1 : 
		ypos <= r__1; ypos += r__2) {
	    ya[0] = ypos;
	    ya[1] = ypos;
	    npl (&c__2, xa, ya);
/* L650: */
	}
	xpos += xincr;
/*  next ix */
/* L600: */
    }
#ifndef NO_PROTO
    dchpfv_("UNIFORM HEIGHT FOR CHARACTER BODIES: In which column are the ch"
	    "aracters NOT aligned between the separators?", &numcol, &ngcol, 
	    107L);
#else /* NO_PROTO */
    dchpfv_("UNIFORM HEIGHT FOR CHARACTER BODIES: In which column are the ch\
aracters NOT aligned between the separators?", &numcol, &ngcol, 107L);
#endif /* NO_PROTO */
    nemst (&c__102);
#ifndef NO_PROTO
    dilist_("IDENTIFY UNREPRESENTED CHARACTER CODES: Enter list of 6 or fewe"
	    "r character codes for which font 1 has no representation (n if n"
	    "one).", &unr1sz, unr1ls, 132L);
    dilist_("IDENTIFY UNREPRESENTED CHARACTER CODES: Enter list of 6 or fewe"
	    "r character codes for which font 2 has no representation (n if n"
	    "one).", &unr2sz, unr2ls, 132L);
#else /* NO_PROTO */
    dilist_("IDENTIFY UNREPRESENTED CHARACTER CODES: Enter list of 6 or fewe\
r character codes for which font 1 has no representation (n if none).", &
	    unr1sz, unr1ls, 132L);
    dilist_("IDENTIFY UNREPRESENTED CHARACTER CODES: Enter list of 6 or fewe\
r character codes for which font 2 has no representation (n if none).", &
	    unr2sz, unr2ls, 132L);
#endif /* NO_PROTO */
    if (unr1sz == 0 && unr2sz == 0) {
#ifndef NO_PROTO
	inmsg_("Cannot test SR46, because there are no unrepresentable chara"
		"cter codes in fonts 1 or 2.", 87L);
#else /* NO_PROTO */
	inmsg_("Cannot test SR46, because there are no unrepresentable chara\
cter codes in fonts 1 or 2.", 87L);
#endif /* NO_PROTO */
	goto L890;
    }
#ifndef NO_PROTO
    setmsg_("3 5 6 38 39 41 46", "There should be an implementation dependen"
	    "t way to depict a character code for which a font has no graphic"
	    " representation.", 17L, 122L);
#else /* NO_PROTO */
    setmsg_("3 5 6 38 39 41 46", "There should be an implementation dependen\
t way to depict a character code for which a font has no graphic representat\
ion.", 17L, 122L);
#endif /* NO_PROTO */
/*  skip font 1 if empty */
    if (unr1sz == 0) {
	goto L850;
    }
/*  check font 1 - if no good, fail and skip out */
    unrep_(&c__1, &unr1sz, unr1ls, "U", result, 1L, 1L);
    if (*result == 'F') {
	fail_();
	goto L890;
    }
    if (unr2sz == 0) {
	pass_();
	goto L890;
    }
/*  do_f2: */
L850:
    unrep_(&c__2, &unr2sz, unr2ls, "U", result, 1L, 1L);
    L__1 = *result == 'P';
    ifpf_(&L__1);
/*  end_unrep: */
L890:
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

