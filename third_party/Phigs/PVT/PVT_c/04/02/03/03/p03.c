/* fort/04/02/03/03/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.03/03                        * */
/*  *    TEST TITLE : Text rectangle size and concatenation * */
/*  *                 point for vertical text orientation   * */
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
    real r__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static real chh;
    static char msg[200], str[20];
    static integer txp;
    static logical rok1, rok2;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real chsp, nomh, chxp;
    static integer font;
    static real nomw;
    static integer txor, idum1, idum2, idum3, idum4, idum5, idum6;
    static real rdum1, rdum2, mnchh;
    static logical ccpok;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real mxchh;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer txalh;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer txalv;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    nqtxf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *, real *, real *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), nqtxf ();
#endif /* NO_PROTO */
    static logical ccpok1, ccpok2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxx (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, char *, integer *, real *
	    , real *, real *, real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx ();
#endif /* NO_PROTO */
    static real nomchh;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real mnchxp;
    static logical didtst, rectok;
    static integer specwt;
    static real mxchxp;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), prpfnt_(integer *, 
	    integer *), chtxrc_(real *, real *, integer *, integer *, char *, 
	    integer *, real *, real *, real *, logical *, logical *, logical *
	    , ftnlen), setmsg_(char *, char *, ftnlen, ftnlen), chmono_(real *
	    , real *, integer *, integer *, char *, integer *, real *, real *,
	     real *, logical *, logical *, ftnlen), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), prpfnt_(), chtxrc_(), setmsg_(), 
	    chmono_(), xpopph_();
#endif /* NO_PROTO */
    static real txexrx[2], txexry[2];

    /* Fortran I/O blocks */
    static icilist io___15 = { 0, msg, 0, "(A,I5,A)", 200, 1 };


/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    initgl_("04.02.03.03/03", 14L);
/* open PHIGS and workstation */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &idum1, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  Throughout, use variable names: */
/*  specwt: workstation type */
/*  font:   text font */
/*  chxp:   character expansion factor */
/*  chsp:   character spacing */
/*  chh:    character height */
/*  txp:    text path */
/*  txal:   text alignment */
/*  str:    character string */

/*  <inquire text facilities> to determine: */
/*     mnchxp = minimum character expansion factor */
/*     mxchxp = maximum character expansion factor */
/*     mnchh  = minimum character height */
/*     mxchh  = maximum character height */
    nqtxf (&specwt, &c__0, &errind, &idum1, &idum2, &idum3, &idum4, &mnchh, &
	    mxchh, &idum5, &mnchxp, &mxchxp, &idum6);
    chkinq_("pqtxf", &errind, 5L);
/*  <Inquire text extent> with: */
/*     txp    = DOWN */
/*     txal   = LEFT, BOTTOM */
/*     str    = "Inquire text extent" */
/*  to determine: */
/*     nomw   = nominal width  = abs (txexrx(2) - txexrx(1)) */
/*     nomh   = nominal height = abs (txexry(2) - txexry(1)) */
/*  font   = a randomly selected font; non-monospaced if possible */
    prpfnt_(&specwt, &font);
    s_wsfi(&io___15);
    do_fio(&c__1, "Font selected for test: ", 24L);
    do_fio(&c__1, (char *)&font, (ftnlen)sizeof(integer));
    do_fio(&c__1, ".", 1L);
    e_wsfi();
    inmsg_(msg, 200L);
#ifndef NO_PROTO
    chxp = 1.f;
    chsp = 0.f;
    chh = 1.f;
#else /* NO_PROTO */
    chxp = (float)1.;
    chsp = (float)0.;
    chh = (float)1.;
#endif /* NO_PROTO */
    txp = 3;
    txalh = 1;
    txalv = 5;
    s_copy(str, "Inquire text extent", 20L, 19L);
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 19L);
    chkinq_("pqtxx", &errind, 5L);
    nomw = (r__1 = txexrx[1] - txexrx[0], dabs(r__1));
    nomh = (r__1 = txexry[1] - txexry[0], dabs(r__1));
/*  *** *** ***   character expansion factor   *** *** *** */

/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = 1.7f;
    chsp = 0.f;
    chh = 1.f;
#else /* NO_PROTO */
    chxp = (float)1.7;
    chsp = (float)0.;
    chh = (float)1.;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6001;
    }
#ifndef NO_PROTO
    setmsg_("6 13 16", "The width of a text rectangle with zero character sp"
	    "acing and a vertical text path should expand in proportion to th"
	    "e character expansion factor.", 7L, 145L);
    ifpf_(&rectok);
    setmsg_("6 10 13 17", "With zero character spacing and a vertical text p"
	    "ath, the concatenation point of a text rectangle should be unaff"
	    "ected by its expansion in proportion to the character expansion "
	    "factor.", 10L, 184L);
#else /* NO_PROTO */
    setmsg_("6 13 16", "The width of a text rectangle with zero character sp\
acing and a vertical text path should expand in proportion to the character \
expansion factor.", 7L, 145L);
    ifpf_(&rectok);
    setmsg_("6 10 13 17", "With zero character spacing and a vertical text p\
ath, the concatenation point of a text rectangle should be unaffected by its\
 expansion in proportion to the character expansion factor.", 10L, 184L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6001:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    if (dabs(mxchxp) < 1e37f) {
	chxp = mxchxp * 1.9f;
#else /* NO_PROTO */
    if (dabs(mxchxp) < (float)1e37) {
	chxp = mxchxp * (float)1.9;
#endif /* NO_PROTO */
    } else {
	chxp = mxchxp;
    }
#ifndef NO_PROTO
    chsp = 0.f;
    chh = 1.f;
#else /* NO_PROTO */
    chsp = (float)0.;
    chh = (float)1.;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6002;
    }
#ifndef NO_PROTO
    setmsg_("6 13 14 16", "The width of a text rectangle with zero character"
	    " spacing and a vertical text path should expand in proportion to"
	    " the character expansion factor, even when it exceeds the maximu"
	    "m for the workstation type.", 10L, 204L);
    ifpf_(&rectok);
    setmsg_("6 10 13 14 17", "With zero character spacing and a vertical tex"
	    "t path, the concatenation point of a text rectangle should be un"
	    "affected by its expansion in proportion to the character expansi"
	    "on factor, even when it exceeds the maximum for the workstation "
	    "type.", 13L, 243L);
#else /* NO_PROTO */
    setmsg_("6 13 14 16", "The width of a text rectangle with zero character\
 spacing and a vertical text path should expand in proportion to the charact\
er expansion factor, even when it exceeds the maximum for the workstation ty\
pe.", 10L, 204L);
    ifpf_(&rectok);
    setmsg_("6 10 13 14 17", "With zero character spacing and a vertical tex\
t path, the concatenation point of a text rectangle should be unaffected by \
its expansion in proportion to the character expansion factor, even when it \
exceeds the maximum for the workstation type.", 13L, 243L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6002:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    if (dabs(mnchxp) > 1e-37f) {
	chxp = mnchxp * .6f;
#else /* NO_PROTO */
    if (dabs(mnchxp) > (float)1e-37) {
	chxp = mnchxp * (float).6;
#endif /* NO_PROTO */
    } else {
	chxp = mnchxp;
    }
#ifndef NO_PROTO
    chsp = 0.f;
    chh = 1.f;
#else /* NO_PROTO */
    chsp = (float)0.;
    chh = (float)1.;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6003;
    }
#ifndef NO_PROTO
    setmsg_("6 13 14 16", "The width of a text rectangle with zero character"
	    " spacing and a vertical text path should expand in proportion to"
	    " the character expansion factor, even when it is less than the m"
	    "inimum for the workstation type.", 10L, 209L);
    ifpf_(&rectok);
    setmsg_("6 10 13 14 17", "With zero character spacing and a vertical tex"
	    "t path, the concatenation point of a text rectangle should be un"
	    "affected by its expansion in proportion to the character expansi"
	    "on factor, even when it is less than the minimum for the worksta"
	    "tion type.", 13L, 248L);
#else /* NO_PROTO */
    setmsg_("6 13 14 16", "The width of a text rectangle with zero character\
 spacing and a vertical text path should expand in proportion to the charact\
er expansion factor, even when it is less than the minimum for the workstati\
on type.", 10L, 209L);
    ifpf_(&rectok);
    setmsg_("6 10 13 14 17", "With zero character spacing and a vertical tex\
t path, the concatenation point of a text rectangle should be unaffected by \
its expansion in proportion to the character expansion factor, even when it \
is less than the minimum for the workstation type.", 13L, 248L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6003:
/*  *** *** ***   character height   *** *** *** */

/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = 1.f;
    chsp = 0.f;
    chh = 1.9f;
#else /* NO_PROTO */
    chxp = (float)1.;
    chsp = (float)0.;
    chh = (float)1.9;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6004;
    }
#ifndef NO_PROTO
    setmsg_("8 9 13 16", "The size of a text rectangle with character spacin"
	    "g = 0, character expansion factor = 1, and a vertical text path "
	    "should expand in proportion to the character height.", 9L, 166L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 17", "With character spacing = 0, character expansion"
	    " factor = 1, and a vertical text path, the concatenation point o"
	    "f a text rectangle should reflect its expansion in proportion to"
	    " the character height.", 12L, 197L);
#else /* NO_PROTO */
    setmsg_("8 9 13 16", "The size of a text rectangle with character spacin\
g = 0, character expansion factor = 1, and a vertical text path should expan\
d in proportion to the character height.", 9L, 166L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 17", "With character spacing = 0, character expansion\
 factor = 1, and a vertical text path, the concatenation point of a text rec\
tangle should reflect its expansion in proportion to the character height.", 
	    12L, 197L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6004:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = 1.f;
    chsp = 0.f;
    if (dabs(mxchh) < 1e37f) {
	chh = mxchh * 1.9f;
#else /* NO_PROTO */
    chxp = (float)1.;
    chsp = (float)0.;
    if (dabs(mxchh) < (float)1e37) {
	chh = mxchh * (float)1.9;
#endif /* NO_PROTO */
    } else {
	chh = mxchh;
    }
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6005;
    }
#ifndef NO_PROTO
    setmsg_("8 9 13 14 16", "The size of a text rectangle with character spa"
	    "cing = 0, character expansion factor = 1, and a vertical text pa"
	    "th should expand in proportion to the character height, even whe"
	    "n it exceeds the maximum for the workstation type.", 12L, 225L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 14 17", "With character spacing = 0, character expans"
	    "ion factor = 1, and a vertical text path, the concatenation poin"
	    "t of a text rectangle should reflect its expansion in proportion"
	    " to the character height, even when it exceeds the maximum for t"
	    "he workstation type.", 15L, 256L);
#else /* NO_PROTO */
    setmsg_("8 9 13 14 16", "The size of a text rectangle with character spa\
cing = 0, character expansion factor = 1, and a vertical text path should ex\
pand in proportion to the character height, even when it exceeds the maximum\
 for the workstation type.", 12L, 225L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 14 17", "With character spacing = 0, character expans\
ion factor = 1, and a vertical text path, the concatenation point of a text \
rectangle should reflect its expansion in proportion to the character height\
, even when it exceeds the maximum for the workstation type.", 15L, 256L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6005:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = 1.f;
    chsp = 0.f;
    if (dabs(mnchh) > 1e-37f) {
	chh = mnchh * .6f;
#else /* NO_PROTO */
    chxp = (float)1.;
    chsp = (float)0.;
    if (dabs(mnchh) > (float)1e-37) {
	chh = mnchh * (float).6;
#endif /* NO_PROTO */
    } else {
	chh = mnchh;
    }
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6006;
    }
#ifndef NO_PROTO
    setmsg_("8 9 13 14 16", "The size of a text rectangle with character spa"
	    "cing = 0, character expansion factor = 1, and a vertical text pa"
	    "th should expand in proportion to the character height, even whe"
	    "n it is less than the minimum for the workstation type.", 12L, 
	    230L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 14 17", "With character spacing = 0, character expans"
	    "ion factor = 1, and a vertical text path, the concatenation poin"
	    "t of a text rectangle should reflect its expansion in proportion"
	    " to the character height, even when it is less than the minimum "
	    "for the workstation type.", 15L, 261L);
#else /* NO_PROTO */
    setmsg_("8 9 13 14 16", "The size of a text rectangle with character spa\
cing = 0, character expansion factor = 1, and a vertical text path should ex\
pand in proportion to the character height, even when it is less than the mi\
nimum for the workstation type.", 12L, 230L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 14 17", "With character spacing = 0, character expans\
ion factor = 1, and a vertical text path, the concatenation point of a text \
rectangle should reflect its expansion in proportion to the character height\
, even when it is less than the minimum for the workstation type.", 15L, 261L)
	    ;
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6006:
/*  *** *** ***   character spacing   *** *** *** */

/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = 1.f;
    chsp = .3f;
    chh = 1.f;
#else /* NO_PROTO */
    chxp = (float)1.;
    chsp = (float).3;
    chh = (float)1.;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6007;
    }
#ifndef NO_PROTO
    setmsg_("7 13 16", "The height of a text rectangle with character expans"
	    "ion factor = 1, character height = 1, and a vertical text path s"
	    "hould increase by the character spacing times one less than the "
	    "number of characters.", 7L, 201L);
    ifpf_(&rectok);
    setmsg_("7 10 13 17 18", "With character expansion factor = 1, character"
	    " height = 1, and a vertical text path, the concatenation point o"
	    "f a text rectangle should reflect its increased size due to char"
	    "acter spacing.", 13L, 188L);
#else /* NO_PROTO */
    setmsg_("7 13 16", "The height of a text rectangle with character expans\
ion factor = 1, character height = 1, and a vertical text path should increa\
se by the character spacing times one less than the number of characters.", 
	    7L, 201L);
    ifpf_(&rectok);
    setmsg_("7 10 13 17 18", "With character expansion factor = 1, character\
 height = 1, and a vertical text path, the concatenation point of a text rec\
tangle should reflect its increased size due to character spacing.", 13L, 
	    188L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6007:
/*  *** *** ***   combined attributes   *** *** *** */

/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = 35.3f;
    chsp = 6.2f;
    chh = 21.1f;
#else /* NO_PROTO */
    chxp = (float)35.3;
    chsp = (float)6.2;
    chh = (float)21.1;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6008;
    }
#ifndef NO_PROTO
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t"
	    "ext path should reflect the combined effects of large values for"
	    " character expansion factor, character spacing, and character he"
	    "ight.", 13L, 179L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With large values for character expansio"
	    "n factor, character spacing, and character height, and a vertica"
	    "l text path, the concatenation point of a text rectangle should "
	    "reflect its increased size.", 19L, 195L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t\
ext path should reflect the combined effects of large values for character e\
xpansion factor, character spacing, and character height.", 13L, 179L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With large values for character expansio\
n factor, character spacing, and character height, and a vertical text path,\
 the concatenation point of a text rectangle should reflect its increased si\
ze.", 19L, 195L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6008:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = .035f;
    chsp = .0062f;
    chh = .021f;
#else /* NO_PROTO */
    chxp = (float).035;
    chsp = (float).0062;
    chh = (float).021;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6009;
    }
#ifndef NO_PROTO
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t"
	    "ext path should reflect the combined effects of small values for"
	    " character expansion factor, character spacing, and character he"
	    "ight.", 13L, 179L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With small values for character expansio"
	    "n factor, character spacing, and character height, and a vertica"
	    "l text path, the concatenation point of a text rectangle should "
	    "reflect its decreased size.", 19L, 195L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t\
ext path should reflect the combined effects of small values for character e\
xpansion factor, character spacing, and character height.", 13L, 179L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With small values for character expansio\
n factor, character spacing, and character height, and a vertical text path,\
 the concatenation point of a text rectangle should reflect its decreased si\
ze.", 19L, 195L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6009:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = -8.035f;
    chsp = -.09f;
    chh = .021f;
#else /* NO_PROTO */
    chxp = (float)-8.035;
    chsp = (float)-.09;
    chh = (float).021;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6010;
    }
#ifndef NO_PROTO
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t"
	    "ext path should reflect the combined effects of negative values "
	    "for character expansion factor and character spacing.", 13L, 163L)
	    ;
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With negative values for character expan"
	    "sion factor and character spacing, and a vertical text path, the"
	    " concatenation point of a text rectangle should reflect its alte"
	    "red size.", 19L, 177L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t\
ext path should reflect the combined effects of negative values for characte\
r expansion factor and character spacing.", 13L, 163L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With negative values for character expan\
sion factor and character spacing, and a vertical text path, the concatenati\
on point of a text rectangle should reflect its altered size.", 19L, 177L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6010:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = .035f;
    chsp = -.03f;
    chh = -9.02f;
#else /* NO_PROTO */
    chxp = (float).035;
    chsp = (float)-.03;
    chh = (float)-9.02;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6011;
    }
#ifndef NO_PROTO
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t"
	    "ext path should reflect the combined effects of negative values "
	    "for character spacing and character height.", 13L, 153L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With negative values for character spaci"
	    "ng and character height, and a vertical text path, the concatena"
	    "tion point of a text rectangle should reflect its altered size.", 
	    19L, 167L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t\
ext path should reflect the combined effects of negative values for characte\
r spacing and character height.", 13L, 153L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With negative values for character spaci\
ng and character height, and a vertical text path, the concatenation point o\
f a text rectangle should reflect its altered size.", 19L, 167L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6011:
/*  *** *** ***   Excessive character spacing   *** *** *** */

/*  <Inquire text extent> with: */
    font = 2;
#ifndef NO_PROTO
    chxp = 1.f;
    chsp = 0.f;
    chh = 1.f;
#else /* NO_PROTO */
    chxp = (float)1.;
    chsp = (float)0.;
    chh = (float)1.;
#endif /* NO_PROTO */
    txp = 3;
    txalh = 1;
    txalv = 5;
    s_copy(str, "qqqq", 20L, 4L);
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 4L);
    chkinq_("pqtxx", &errind, 5L);
    nomchh = (r__1 = txexry[1] - txexry[0], dabs(r__1)) / 4;
    nomw = (r__1 = txexrx[1] - txexrx[0], dabs(r__1));
/*  call CHMONO with: nomchh, nomw, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = 6.35f;
    chsp = nomchh * -8.51f;
    chh = -.021f;
#else /* NO_PROTO */
    chxp = (float)6.35;
    chsp = nomchh * (float)-8.51;
    chh = (float)-.021;
#endif /* NO_PROTO */
    chmono_(&nomchh, &nomw, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    rok1, &ccpok1, 4L);
/*  call CHMONO with: nomchh, nomw, specwt, font, str unchanged */
    txor = 2;
#ifndef NO_PROTO
    chxp = -.065f;
    chsp = nomchh * -1.01f;
    chh = -7.21f;
#else /* NO_PROTO */
    chxp = (float)-.065;
    chsp = nomchh * (float)-1.01;
    chh = (float)-7.21;
#endif /* NO_PROTO */
    chmono_(&nomchh, &nomw, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    rok2, &ccpok2, 4L);
#ifndef NO_PROTO
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t"
	    "ext path should reflect the effect of negative character spacing"
	    " of greater magnitude than the height of a single character.", 
	    13L, 170L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 16", "The size of a text rectangle with a vertical t\
ext path should reflect the effect of negative character spacing of greater \
magnitude than the height of a single character.", 13L, 170L);
#endif /* NO_PROTO */
    L__1 = rok1 && rok2;
    ifpf_(&L__1);
/* L666: */
/* close PHIGS and workstation */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

