/* fort/04/02/03/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b56 = .04f;
static real c_b65 = .95f;
#else /* NO_PROTO */
static real c_b56 = (float).04;
static real c_b65 = (float).95;
#endif /* NO_PROTO */
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b73 = 1.f;
static real c_b74 = 0.f;
#else /* NO_PROTO */
static real c_b73 = (float)1.;
static real c_b74 = (float)0.;
#endif /* NO_PROTO */
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b82 = .3f;
static real c_b83 = 3.f;
#else /* NO_PROTO */
static real c_b82 = (float).3;
static real c_b83 = (float)3.;
#endif /* NO_PROTO */
static integer c__4 = 4;
static integer c__26 = 26;
#ifndef NO_PROTO
static real c_b130 = .25f;
#else /* NO_PROTO */
static real c_b130 = (float).25;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.01/03                        * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static char caps[1*26] = "A" "B" "C" "D" "E" "F" "G" "H" "I" "J" "K" 
	    "L" "M" "N" "O" "P" "Q" "R" "S" "T" "U" "V" "W" "X" "Y" "Z";
#else /* NO_PROTO */
    static char caps[1*26+1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2], i__3, i__4;
    real r__1, r__2;
    logical L__1;
    char ch__1[1111];

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

    /* Local variables */
    static real xa[5], ya[5], xb[5];
    static integer ix;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static char str[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen), fail_(
	    void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx (), fail_(), ifpf_();
#endif /* NO_PROTO */
    static real chht, ncsh, capy, chsp;
    static char vlbl[2];
    static integer nfpp, perm[20];
    static real lbox;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer txci;
    static real rbox;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsln (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsln ();
#endif /* NO_PROTO */
    static integer lunx;
    static real xpos, ypos, ytop, txrx[2], txry[2];
    static integer idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int dchpf_(char *, integer *, integer *, integer *
	    , ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dchpf_();
#endif /* NO_PROTO */
    static integer elloc, ngcol;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer capix[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh ();
#endif /* NO_PROTO */
    static real chexp;
    static integer numch, lnegx;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real chsiz;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static real xleft, xincr, yincr;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static char chstr[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), dynpf_(char *, char *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), dynpf_();
#endif /* NO_PROTO */
    static integer lstrk[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), rnset_(integer *, integer *
	    , integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), rnset_();
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
	    unrep_(integer *, integer *, integer *, char *, char *, ftnlen, 
	    ftnlen), nstxp (integer *), nqtxx (integer *, integer *, real *, 
	    real *, real *, integer *, integer *, integer *, char *, integer *
	    , real *, real *, real *, real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nqtxf (), nsvwi (), unrep_(), 
	    nstxp (), nqtxx ();
#endif /* NO_PROTO */
    static integer unr1ls[20], unr2ls[20], unr1sz;
#ifndef NO_PROTO
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static integer unr2sz;
    static real offact;
    static integer lnegfn[200], ngline;
    static char tallch[15];
    static integer errind, thisfn, thispr, lposfn[200], lpospr[200], lnegpr[
	    200], lstrkx, picstr, numcol;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer numsht, curfnt, numlin, minstr, maxstr, alfsiz, alfont[300]
	    , lunsfn[20], lunspr[20], maxfnt, parity;
    static char chfnts[1010], distrg[60], result[1], shrtch[15];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setdlg_(integer *, integer *, integer *), setasf_(
	    integer *), chkinq_(char *, integer *, ftnlen), setmsg_(char *, 
	    char *, ftnlen, ftnlen), chkfnt_(integer *, integer *, integer *, 
	    integer *, char *, logical *, char *, ftnlen, ftnlen), srtiar_(
	    integer *, integer *), nstxpr (integer *), nstxal (integer *, 
	    integer *), nschsp (real *), nstxci (integer *), nsplci (integer *
	    ), nstxfn (integer *), nschxp (real *), dchpfv_(char *, integer *,
	     integer *, ftnlen), dilist_(char *, integer *, integer *, ftnlen)
	    , numlab_(integer *, real *, real *, real *), rnperm_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setdlg_(), setasf_(), 
	    chkinq_(), setmsg_(), chkfnt_(), srtiar_(), nstxpr (), nstxal (), 
	    nschsp (), nstxci (), nsplci (), nstxfn (), nschxp (), dchpfv_(), 
	    dilist_(), numlab_(), rnperm_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___31 = { 0, chfnts, 0, "(200I5)", 1010, 1 };
    static icilist io___38 = { 0, vlbl, 0, "(I1,A)", 2, 1 };


/* aspect source */
/*                bundled     individual */
/* linetype */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    initgl_("04.02.03.01/03", 14L);
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
    setmsg_("11 13 19 21", "All positive text fonts should appear as specifi"
	    "ed in the ISO register.", 11L, 71L);
    inmsg_("SR 19 is indirectly confirmed in the following test case since t"
	    "his test must be run against all workstation types, and the ISO "
	    "register documentation must be correct for all of them.", 183L);
#else /* NO_PROTO */
    s_copy(msg, "NON-MANDATORY REGISTERED TEXT FONTS: Do all displayed, labe\
lled text fonts agree with the corresponding description in the ISO register?"
	    , 300L, 136L);
    setmsg_("11 13 19 21", "All positive text fonts should appear as specifi\
ed in the ISO register.", 11L, 71L);
    inmsg_("SR 19 is indirectly confirmed in the following test case since t\
his test must be run against all workstation types, and the ISO register doc\
umentation must be correct for all of them.", 183L);
#endif /* NO_PROTO */
/*  call routine to handle display */
#ifndef NO_PROTO
    chkfnt_(&lposx, lposfn, lpospr, &maxfnt, chstr, (logical*)&c__0, "T", 10L,
	     1L);
#else /* NO_PROTO */
    chkfnt_(&lposx, lposfn, lpospr, &maxfnt, chstr, &c__0, "T", 10L, 1L);
#endif /* NO_PROTO */
    dynpf_(msg, "y", 300L, 1L);
    nemst (&c__102);
#ifndef NO_PROTO
    setmsg_("11 13 19 21 29 30", "All positive text fonts should appear as s"
	    "pecified in the ISO register, even when less precision is reques"
	    "ted than is available for the font.", 17L, 141L);
#else /* NO_PROTO */
    setmsg_("11 13 19 21 29 30", "All positive text fonts should appear as s\
pecified in the ISO register, even when less precision is requested than is \
available for the font.", 17L, 141L);
#endif /* NO_PROTO */
/*  call routine to handle display */
#ifndef NO_PROTO
    chkfnt_(&lposx, lposfn, lpospr, &maxfnt, chstr, (logical*)&c__1, "T", 10L,
	     1L);
#else /* NO_PROTO */
    chkfnt_(&lposx, lposfn, lpospr, &maxfnt, chstr, &c__1, "T", 10L, 1L);
#endif /* NO_PROTO */
    dynpf_(msg, "y", 300L, 1L);
    nemst (&c__102);
/*  end_pos: */
L190:
    if (lnegx <= 0) {
	inmsg_("No implementor defined text fonts are supported.", 48L);
	goto L390;
    }
#ifndef NO_PROTO
    s_copy(msg, "IMPLEMENTOR DEFINED TEXT FONTS: Answer y if both are true, "
	    "otherwise n: 1) the implementor provides accurate documentation "
	    "for all these fonts, and 2) the documentation indicates that a f"
	    "ont identifier denotes the same font on all workstation types wh"
	    "ich support that identifier.", 300L, 279L);
    setmsg_("11 13 19 21", "All non-positive text fonts should be workstatio"
	    "n independent and appear as specified in the implementor's docum"
	    "entation.", 11L, 121L);
#else /* NO_PROTO */
    s_copy(msg, "IMPLEMENTOR DEFINED TEXT FONTS: Answer y if both are true, \
otherwise n: 1) the implementor provides accurate documentation for all thes\
e fonts, and 2) the documentation indicates that a font identifier denotes t\
he same font on all workstation types which support that identifier.", 300L, 
	    279L);
    setmsg_("11 13 19 21", "All non-positive text fonts should be workstatio\
n independent and appear as specified in the implementor's documentation.", 
	    11L, 121L);
#endif /* NO_PROTO */
/*  call routine to handle display */
#ifndef NO_PROTO
    chkfnt_(&lnegx, lnegfn, lnegpr, &maxfnt, chstr, (logical*)&c__0, "T", 10L,
	     1L);
#else /* NO_PROTO */
    chkfnt_(&lnegx, lnegfn, lnegpr, &maxfnt, chstr, &c__0, "T", 10L, 1L);
#endif /* NO_PROTO */
    dynpf_(msg, "y", 300L, 1L);
    nemst (&c__102);
#ifndef NO_PROTO
    setmsg_("11 13 19 21 29 30", "All non-positive text fonts should be work"
	    "station independent and appear as specified in the implementor's"
	    " documentation, even when less precision is requested than is av"
	    "ailable for the font.", 17L, 191L);
#else /* NO_PROTO */
    setmsg_("11 13 19 21 29 30", "All non-positive text fonts should be work\
station independent and appear as specified in the implementor's documentati\
on, even when less precision is requested than is available for the font.", 
	    17L, 191L);
#endif /* NO_PROTO */
/*  call routine to handle display */
#ifndef NO_PROTO
    chkfnt_(&lnegx, lnegfn, lnegpr, &maxfnt, chstr, (logical*)&c__1, "T", 10L,
	     1L);
#else /* NO_PROTO */
    chkfnt_(&lnegx, lnegfn, lnegpr, &maxfnt, chstr, &c__1, "T", 10L, 1L);
#endif /* NO_PROTO */
    dynpf_(msg, "y", 300L, 1L);
    nemst (&c__102);
/*  end_neg: */
/* L290: */
    if (lnegx <= maxfnt) {
	goto L390;
    }
#ifndef NO_PROTO
    setmsg_("21", "All reported implementor-defined text fonts available for"
	    " a given workstation type should be documented by the implemento"
	    "r.", 2L, 123L);
#else /* NO_PROTO */
    setmsg_("21", "All reported implementor-defined text fonts available for\
 a given workstation type should be documented by the implementor.", 2L, 123L)
	    ;
#endif /* NO_PROTO */
/*  list all reported implementor-defined text fonts in lnegfn */
    srtiar_(&lnegx, lnegfn);
    s_copy(chfnts, " ", 1010L, 1L);
    s_wsfi(&io___31);
    i__1 = lnegx;
    for (ix = 1; ix <= i__1; ++ix) {
	do_fio(&c__1, (char *)&lnegfn[ix - 1], (ftnlen)sizeof(integer));
    }
    e_wsfi();
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 101, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR TEXT FO"
	    "NTS: Are all these fonts documented by the implementor:";
#else /* NO_PROTO */
    i__2[0] = 101, a__1[0] = "COMPLETE DOCUMENTATION FOR IMPLEMENTOR TEXT FO\
NTS: Are all these fonts documented by the implementor:";
#endif /* NO_PROTO */
    i__2[1] = itrim_(chfnts, 1010L), a__1[1] = chfnts;
    s_cat(ch__1, a__1, i__2, &c__2, 1111L);
    dynpf_(ch__1, "y", itrim_(chfnts, 1010L) + 101, 1L);
/*  end_font_id: */
L390:
#ifndef NO_PROTO
    setmsg_("11 13 16 17 31 36 42 59", "In each text font, all character bod"
	    "ies affected by the same character height, character expansion f"
	    "actor, and character spacing should have the same height.", 23L, 
	    157L);
#else /* NO_PROTO */
    setmsg_("11 13 16 17 31 36 42 59", "In each text font, all character bod\
ies affected by the same character height, character expansion factor, and c\
haracter spacing should have the same height.", 23L, 157L);
#endif /* NO_PROTO */
    nstxpr (&c__2);
    nschh (&c_b56);
    nstxal (&c__1, &c__1);
/*  numcol = number of columns to display = 6 */
    numcol = 6;
/*  ngcol  = incorrect column = random number from 1 to numcol */
    ngcol = rndint_(&c__1, &numcol);
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
	s_wsfi(&io___38);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	ntx (&xpos, &c_b65, vlbl, 2L);
	xpos += xincr;
/* L500: */
    }
/*  set up short, tall characters */
    s_copy(shrtch, ",'_~;`.\"-=+*^@#", 15L, 15L);
    s_copy(tallch, "W|j(g!)Q[]/\\IMH", 15L, 15L);
/*  display vertical text */
    xpos = xleft;
#ifndef NO_PROTO
    chsp = .2f;
#else /* NO_PROTO */
    chsp = (float).2;
#endif /* NO_PROTO */
    nschsp (&chsp);
    nstxp (&c__3);
#ifndef NO_PROTO
    ytop = .85f;
#else /* NO_PROTO */
    ytop = (float).85;
#endif /* NO_PROTO */
/*  try to paint text and polylines different colors */
    nstxci (&c__1);
    nsplci (&c__2);
    i__1 = numcol;
    for (ix = 1; ix <= i__1; ++ix) {
/*  txfnt = random value from lstrk */
	txfnt = lstrk[rndint_(&c__1, &lstrkx) - 1];
/*  Use <inquire text extent> to determine */
/*  ncsh = (nominal vertical character body size / */
/*          requested character height)  for txfnt */
	nqtxx (&dialog_1.specwt, &txfnt, &c_b73, &c_b74, &c_b73, &c__3, &c__1,
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
	chexp = rndrl_(&c_b82, &c_b83);
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
	nstxfn (&txfnt);
	nschh (&chht);
	nschxp (&chexp);
/*  display distrg at location ix */
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
    setmsg_("1 11 14 16 17 31 58 59 75", "Character height magnitude should "
	    "specify the nominal height, in TLC, from baseline to capline, of"
	    " all capital letters within a font.", 25L, 133L);
    dilist_("CHARACTER HEIGHT FOR SIZE OF CAPITAL LETTERS: Enter list of fon"
	    "t identifiers available in stroke precision, other than 1 and 2,"
	    " which support alphabetic characters (n if none).", &alfsiz, 
	    alfont, 176L);
#else /* NO_PROTO */
    setmsg_("1 11 14 16 17 31 58 59 75", "Character height magnitude should \
specify the nominal height, in TLC, from baseline to capline, of all capital\
 letters within a font.", 25L, 133L);
    dilist_("CHARACTER HEIGHT FOR SIZE OF CAPITAL LETTERS: Enter list of fon\
t identifiers available in stroke precision, other than 1 and 2, which suppo\
rt alphabetic characters (n if none).", &alfsiz, alfont, 176L);
#endif /* NO_PROTO */
/*  add 1 and 2 */
    alfont[alfsiz] = 1;
    alfont[alfsiz + 1] = 2;
    alfsiz += 2;
/*  set number of lines, no-good line */
    numlin = 6;
    ngline = rndint_(&c__1, &numlin);
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ypos = 1 - yincr;
/*  try to paint text and polylines different colors */
    nstxci (&c__1);
    nsplci (&c__2);
    parity = -1;
#ifndef NO_PROTO
    lbox = .3f;
    rbox = .9f;
#else /* NO_PROTO */
    lbox = (float).3;
    rbox = (float).9;
#endif /* NO_PROTO */
/*  draw labels */
#ifndef NO_PROTO
    r__2 = lbox - .05f;
    r__1 = ypos + yincr * .25f;
#else /* NO_PROTO */
    r__2 = lbox - (float).05;
    r__1 = ypos + yincr * (float).25;
#endif /* NO_PROTO */
    numlab_(&numlin, &r__2, &r__1, &yincr);
    nstxpr (&c__2);
    nstxal (&c__1, &c__4);
    xa[0] = lbox;
    xa[1] = rbox;
    xb[0] = lbox;
    xb[1] = lbox;
    xb[2] = rbox;
    xb[3] = rbox;
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  str = 3 random capital letters */
	rnset_(&c__3, &c__26, capix);
	*str = caps[capix[0] - 1];
	str[1] = caps[capix[1] - 1];
	str[2] = caps[capix[2] - 1];
/*  chht = random value between .2*YINCR AND .8*YINCR */
#ifndef NO_PROTO
	r__2 = yincr * .2f;
	r__1 = yincr * .8f;
#else /* NO_PROTO */
	r__2 = yincr * (float).2;
	r__1 = yincr * (float).8;
#endif /* NO_PROTO */
	chht = rndrl_(&r__2, &r__1);
	parity = -parity;
	r__2 = parity * chht;
	nschh (&r__2);
	if (ix == ngline) {
/*  draw incorrect base, cap lines */
#ifndef NO_PROTO
	    if (chht < yincr * .5f) {
#else /* NO_PROTO */
	    if (chht < yincr * (float).5) {
#endif /* NO_PROTO */
/*  draw lines too far apart */
#ifndef NO_PROTO
		capy = ypos + chht * 1.25f;
#else /* NO_PROTO */
		capy = ypos + chht * (float)1.25;
#endif /* NO_PROTO */
	    } else {
/*  draw lines too close */
#ifndef NO_PROTO
		capy = ypos + chht * .75f;
#else /* NO_PROTO */
		capy = ypos + chht * (float).75;
#endif /* NO_PROTO */
	    }
	} else {
/*  draw correct base, cap lines */
	    capy = ypos + chht;
	}
	ya[0] = ypos;
	ya[1] = ypos;
	nsln (&c__2);
	npl (&c__2, xa, ya);
	ya[1] = capy;
	ya[2] = capy;
	ya[3] = ypos;
	nsln (&c__3);
	npl (&c__4, xb, ya);
/*  curfnt = random pick from alfont */
	curfnt = alfont[rndint_(&c__1, &alfsiz) - 1];
/*  display and label str, using chht and curfnt */
	nstxfn (&curfnt);
#ifndef NO_PROTO
	r__2 = lbox + .1f;
#else /* NO_PROTO */
	r__2 = lbox + (float).1;
#endif /* NO_PROTO */
	ntx (&r__2, &ypos, str, 3L);
	ypos -= yincr;
/*  next ix */
/* L700: */
    }
#ifndef NO_PROTO
    dchpfv_("CHARACTER HEIGHT FOR SIZE OF CAPITAL LETTERS: In which line do "
	    "the upper-case letters NOT fit exactly between the dashed baseli"
	    "ne and the dotted capline?", &numlin, &ngline, 153L);
#else /* NO_PROTO */
    dchpfv_("CHARACTER HEIGHT FOR SIZE OF CAPITAL LETTERS: In which line do \
the upper-case letters NOT fit exactly between the dashed baseline and the d\
otted capline?", &numlin, &ngline, 153L);
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
	inmsg_("Cannot test SR20, because there are no unrepresentable chara"
		"cter codes in fonts 1 or 2.", 87L);
#else /* NO_PROTO */
	inmsg_("Cannot test SR20, because there are no unrepresentable chara\
cter codes in fonts 1 or 2.", 87L);
#endif /* NO_PROTO */
	goto L890;
    }
#ifndef NO_PROTO
    setmsg_("13 14 20", "There should be a implementation dependent way to d"
	    "epict a character code for which a font has no graphic represent"
	    "ation.", 8L, 121L);
#else /* NO_PROTO */
    setmsg_("13 14 20", "There should be a implementation dependent way to d\
epict a character code for which a font has no graphic representation.", 8L, 
	    121L);
#endif /* NO_PROTO */
/*  skip font 1 if empty */
    if (unr1sz == 0) {
	goto L850;
    }
/*  check font 1 - if no good, fail and skip out */
    unrep_(&c__1, &unr1sz, unr1ls, "T", result, 1L, 1L);
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
    unrep_(&c__2, &unr2sz, unr2ls, "T", result, 1L, 1L);
    L__1 = *result == 'P';
    ifpf_(&L__1);
/*  end_unrep: */
L890:
#ifndef NO_PROTO
    setmsg_("11 13 15 22 27", "If text display is requested with an unavaila"
	    "ble font or precision, font=1 and precision=STRING should be use"
	    "d.", 14L, 111L);
#else /* NO_PROTO */
    setmsg_("11 13 15 22 27", "If text display is requested with an unavaila\
ble font or precision, font=1 and precision=STRING should be used.", 14L, 
	    111L);
#endif /* NO_PROTO */
/*  lunsfn,lunspr = lists of unsupported font, precision pairs */

/*  within lposfn, find at most 2 fonts in non-STROKE precision. */
/*  for each such add entry to lunsup: font and lowest unavailable */
/*  precision. */
    lunx = 0;
    i__1 = lposx;
    for (ix = 1; ix <= i__1; ++ix) {
/*  skip stroke precisions */
	if (lpospr[ix - 1] >= 2) {
	    goto L900;
	}
	++lunx;
	lunsfn[lunx - 1] = lposfn[ix - 1];
	lunspr[lunx - 1] = lpospr[ix - 1] + 1;
	if (lunx >= 2) {
	    goto L910;
	}
L900:
	;
    }
L910:
/*  within lnegfn, find at most 2 fonts in non-STROKE precision. */
/*  for each such add entry to lunsup: font and lowest unavailable */
/*    precision. */
    i__1 = lnegx;
    for (ix = 1; ix <= i__1; ++ix) {
/*  skip stroke precisions */
	if (lnegpr[ix - 1] >= 2) {
	    goto L920;
	}
	++lunx;
	lunsfn[lunx - 1] = lnegfn[ix - 1];
	lunspr[lunx - 1] = lnegpr[ix - 1] + 1;
	if (lunx >= 4) {
	    goto L930;
	}
L920:
	;
    }
L930:
/*  (minstr, maxstr) = (minimum, maximum) font identifier in lstrk */
    minstr = 1;
    maxstr = 1;
    i__1 = lstrkx;
    for (ix = 1; ix <= i__1; ++ix) {
/* Computing MIN */
	i__3 = minstr, i__4 = lstrk[ix - 1];
	minstr = min(i__3,i__4);
/* Computing MAX */
	i__3 = maxstr, i__4 = lstrk[ix - 1];
	maxstr = max(i__3,i__4);
/* L940: */
    }
/*  add to list of unsupported: */
/*  minstr -   1, STRING */
/*  minstr - 100, STRING */
/*  maxstr +   1, STRING */
/*  maxstr + 100, STRING */
    lunsfn[lunx] = minstr - 1;
    lunsfn[lunx + 1] = minstr - 100;
    lunsfn[lunx + 2] = maxstr + 1;
    lunsfn[lunx + 3] = maxstr + 100;
    lunspr[lunx] = 0;
    lunspr[lunx + 1] = 2;
    lunspr[lunx + 2] = 2;
    lunspr[lunx + 3] = 0;
    lunx += 4;
/*  add (1,STRING) to lunsup and */
/*  as last entry add (2,STRING) to lunsup */
    lunsfn[lunx] = 1;
    lunsfn[lunx + 1] = 2;
    lunspr[lunx] = 0;
    lunspr[lunx + 1] = 0;
    lunx += 2;
/*  numlin = size of lunsup */
    numlin = lunx;
/*  perm = array to randomize order of lunsup */
    rnperm_(&numlin, perm);
/*  label all lines from 1 to numlin */
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ypos = 1 - yincr;
/*  draw labels */
    numlab_(&numlin, &c_b130, &ypos, &yincr);
    nstxal (&c__1, &c__3);
/*  allow room within picture square = (x-space - 0.1) / #characters */
/* Computing MIN */
    r__1 = yincr / 2;
#ifndef NO_PROTO
    r__2 = dmin(r__1,.045454545454545456f);
#else /* NO_PROTO */
    r__2 = dmin(r__1,(float).045454545454545456);
#endif /* NO_PROTO */
    nschh (&r__2);
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
	nstxfn (&lunsfn[perm[ix - 1] - 1]);
	nstxpr (&lunspr[perm[ix - 1] - 1]);
	ntx (&c_b82, &ypos, "AaMnZz09@#Q", 11L);
	ypos -= yincr;
/* L970: */
    }
/*  pass/fail depending on (operator picks text written with (2,STRING)) 
*/
#ifndef NO_PROTO
    dchpf_("UNSUPPORTED TEXT FONT AND PRECISION PAIRS: Which line is differe"
	    "nt?", &numlin, &numlin, perm, 67L);
#else /* NO_PROTO */
    dchpf_("UNSUPPORTED TEXT FONT AND PRECISION PAIRS: Which line is differe\
nt?", &numlin, &numlin, perm, 67L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

