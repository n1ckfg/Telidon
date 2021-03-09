/* fort/04/02/03/03/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 04.02.03.03/02                        * */
/*  *    TEST TITLE : Text rectangle size and concatenation * */
/*  *                 point for horizontal text orientation * */
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
    static real nomcw;
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
	    , real *, real *, real *, ftnlen), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx (), chkinq_();
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
    initgl_("04.02.03.03/02", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  open primary workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  Establish specwt = specific primary workstation type */
    nqwkc (&globnu_1.wkid, &errind, &idum1, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  Throughout, use variable names: */
/*  wktype: workstation type */
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
    txp = 0;
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
    txor = 1;
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
    setmsg_("6 13 15", "The width of a text rectangle with zero character sp"
	    "acing and a horizontal text path should expand in proportion to "
	    "the character expansion factor.", 7L, 147L);
    ifpf_(&rectok);
    setmsg_("6 10 13 17", "With zero character spacing and a horizontal text"
	    " path, the concatenation point of a text rectangle should reflec"
	    "t its expansion in proportion to the character expansion factor.",
	     10L, 177L);
#else /* NO_PROTO */
    setmsg_("6 13 15", "The width of a text rectangle with zero character sp\
acing and a horizontal text path should expand in proportion to the characte\
r expansion factor.", 7L, 147L);
    ifpf_(&rectok);
    setmsg_("6 10 13 17", "With zero character spacing and a horizontal text\
 path, the concatenation point of a text rectangle should reflect its expans\
ion in proportion to the character expansion factor.", 10L, 177L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6001:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 1;
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
    setmsg_("6 13 14 15", "The width of a text rectangle with zero character"
	    " spacing and a horizontal text path should expand in proportion "
	    "to the character expansion factor, even when it exceeds the maxi"
	    "mum for the workstation type.", 10L, 206L);
    ifpf_(&rectok);
    setmsg_("6 10 13 14 17", "With zero character spacing and a horizontal t"
	    "ext path, the concatenation point of a text rectangle should ref"
	    "lect its expansion in proportion to the character expansion fact"
	    "or, even when it exceeds the maximum for the workstation type.", 
	    13L, 236L);
#else /* NO_PROTO */
    setmsg_("6 13 14 15", "The width of a text rectangle with zero character\
 spacing and a horizontal text path should expand in proportion to the chara\
cter expansion factor, even when it exceeds the maximum for the workstation \
type.", 10L, 206L);
    ifpf_(&rectok);
    setmsg_("6 10 13 14 17", "With zero character spacing and a horizontal t\
ext path, the concatenation point of a text rectangle should reflect its exp\
ansion in proportion to the character expansion factor, even when it exceeds\
 the maximum for the workstation type.", 13L, 236L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6002:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 1;
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
    setmsg_("6 13 14 15", "The width of a text rectangle with zero character"
	    " spacing and a horizontal text path should expand in proportion "
	    "to the character expansion factor, even when it is less than the"
	    " minimum for the workstation type.", 10L, 211L);
    ifpf_(&rectok);
    setmsg_("6 10 13 14 17", "With zero character spacing and a horizontal t"
	    "ext path, the concatenation point of a text rectangle should ref"
	    "lect its expansion in proportion to the character expansion fact"
	    "or, even when it is less than the minimum for the workstation ty"
	    "pe.", 13L, 241L);
#else /* NO_PROTO */
    setmsg_("6 13 14 15", "The width of a text rectangle with zero character\
 spacing and a horizontal text path should expand in proportion to the chara\
cter expansion factor, even when it is less than the minimum for the worksta\
tion type.", 10L, 211L);
    ifpf_(&rectok);
    setmsg_("6 10 13 14 17", "With zero character spacing and a horizontal t\
ext path, the concatenation point of a text rectangle should reflect its exp\
ansion in proportion to the character expansion factor, even when it is less\
 than the minimum for the workstation type.", 13L, 241L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6003:
/*  *** *** ***   character height   *** *** *** */

/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 1;
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
    setmsg_("8 9 13 15", "The size of a text rectangle with character spacin"
	    "g = 0, character expansion factor = 1, and a horizontal text pat"
	    "h should expand in proportion to the character height.", 9L, 168L)
	    ;
    ifpf_(&rectok);
    setmsg_("8 9 10 13 17", "With character spacing = 0, character expansion"
	    " factor = 1, and a horizontal text path, the concatenation point"
	    " of a text rectangle should reflect its expansion in proportion "
	    "to the character height.", 12L, 199L);
#else /* NO_PROTO */
    setmsg_("8 9 13 15", "The size of a text rectangle with character spacin\
g = 0, character expansion factor = 1, and a horizontal text path should exp\
and in proportion to the character height.", 9L, 168L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 17", "With character spacing = 0, character expansion\
 factor = 1, and a horizontal text path, the concatenation point of a text r\
ectangle should reflect its expansion in proportion to the character height.",
	     12L, 199L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6004:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 1;
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
    setmsg_("8 9 13 14 15", "The size of a text rectangle with character spa"
	    "cing = 0, character expansion factor = 1, and a horizontal text "
	    "path should expand in proportion to the character height, even w"
	    "hen it exceeds the maximum for the workstation type.", 12L, 227L);

    ifpf_(&rectok);
    setmsg_("8 9 10 13 14 17", "With character spacing = 0, character expans"
	    "ion factor = 1, and a horizontal text path, the concatenation po"
	    "int of a text rectangle should reflect its expansion in proporti"
	    "on to the character height, even when it exceeds the maximum for"
	    " the workstation type.", 15L, 258L);
#else /* NO_PROTO */
    setmsg_("8 9 13 14 15", "The size of a text rectangle with character spa\
cing = 0, character expansion factor = 1, and a horizontal text path should \
expand in proportion to the character height, even when it exceeds the maxim\
um for the workstation type.", 12L, 227L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 14 17", "With character spacing = 0, character expans\
ion factor = 1, and a horizontal text path, the concatenation point of a tex\
t rectangle should reflect its expansion in proportion to the character heig\
ht, even when it exceeds the maximum for the workstation type.", 15L, 258L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6005:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 1;
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
    setmsg_("8 9 13 14 15", "The size of a text rectangle with character spa"
	    "cing = 0, character expansion factor = 1, and a horizontal text "
	    "path should expand in proportion to the character height, even w"
	    "hen it is less than the minimum for the workstation type.", 12L, 
	    232L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 14 17", "With character spacing = 0, character expans"
	    "ion factor = 1, and a horizontal text path, the concatenation po"
	    "int of a text rectangle should reflect its expansion in proporti"
	    "on to the character height, even when it is less than the minimu"
	    "m for the workstation type.", 15L, 263L);
#else /* NO_PROTO */
    setmsg_("8 9 13 14 15", "The size of a text rectangle with character spa\
cing = 0, character expansion factor = 1, and a horizontal text path should \
expand in proportion to the character height, even when it is less than the \
minimum for the workstation type.", 12L, 232L);
    ifpf_(&rectok);
    setmsg_("8 9 10 13 14 17", "With character spacing = 0, character expans\
ion factor = 1, and a horizontal text path, the concatenation point of a tex\
t rectangle should reflect its expansion in proportion to the character heig\
ht, even when it is less than the minimum for the workstation type.", 15L, 
	    263L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6006:
/*  *** *** ***   character spacing   *** *** *** */

/*  call CHTXRC with: nomw, nomh, pecwt, font, str unchanged */
    txor = 1;
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
    setmsg_("7 13 15", "The width of a text rectangle with character expansi"
	    "on factor = 1, character height = 1, and a horizontal text path "
	    "should increase by the character spacing times one less than the"
	    " number of characters.", 7L, 202L);
    ifpf_(&rectok);
    setmsg_("7 10 13 17 18", "With character expansion factor = 1, character"
	    " height = 1, and a horizontal text path, the concatenation point"
	    " of a text rectangle should reflect its increased size due to ch"
	    "aracter spacing.", 13L, 190L);
#else /* NO_PROTO */
    setmsg_("7 13 15", "The width of a text rectangle with character expansi\
on factor = 1, character height = 1, and a horizontal text path should incre\
ase by the character spacing times one less than the number of characters.", 
	    7L, 202L);
    ifpf_(&rectok);
    setmsg_("7 10 13 17 18", "With character expansion factor = 1, character\
 height = 1, and a horizontal text path, the concatenation point of a text r\
ectangle should reflect its increased size due to character spacing.", 13L, 
	    190L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6007:
/*  *** *** ***   combined attributes   *** *** *** */

/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 1;
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
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal"
	    " text path should reflect the combined effects of large values f"
	    "or character expansion factor, character spacing, and character "
	    "height.", 13L, 181L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With large values for character expansio"
	    "n factor, character spacing, and character height, and a horizon"
	    "tal text path, the concatenation point of a text rectangle shoul"
	    "d reflect its increased size.", 19L, 197L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal\
 text path should reflect the combined effects of large values for character\
 expansion factor, character spacing, and character height.", 13L, 181L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With large values for character expansio\
n factor, character spacing, and character height, and a horizontal text pat\
h, the concatenation point of a text rectangle should reflect its increased \
size.", 19L, 197L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6008:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 1;
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
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal"
	    " text path should reflect the combined effects of small values f"
	    "or character expansion factor, character spacing, and character "
	    "height.", 13L, 181L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With small values for character expansio"
	    "n factor, character spacing, and character height, and a horizon"
	    "tal text path, the concatenation point of a text rectangle shoul"
	    "d reflect its decreased size.", 19L, 197L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal\
 text path should reflect the combined effects of small values for character\
 expansion factor, character spacing, and character height.", 13L, 181L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With small values for character expansio\
n factor, character spacing, and character height, and a horizontal text pat\
h, the concatenation point of a text rectangle should reflect its decreased \
size.", 19L, 197L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6009:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 1;
#ifndef NO_PROTO
    chxp = -8.035f;
    chsp = -.51f;
    chh = .021f;
#else /* NO_PROTO */
    chxp = (float)-8.035;
    chsp = (float)-.51;
    chh = (float).021;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6010;
    }
#ifndef NO_PROTO
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal"
	    " text path should reflect the combined effects of negative value"
	    "s for character expansion factor and character spacing.", 13L, 
	    165L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With negative values for character expan"
	    "sion factor and character spacing, and a horizontal text path, t"
	    "he concatenation point of a text rectangle should reflect its al"
	    "tered size.", 19L, 179L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal\
 text path should reflect the combined effects of negative values for charac\
ter expansion factor and character spacing.", 13L, 165L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With negative values for character expan\
sion factor and character spacing, and a horizontal text path, the concatena\
tion point of a text rectangle should reflect its altered size.", 19L, 179L);
#endif /* NO_PROTO */
    ifpf_(&ccpok);
L6010:
/*  call CHTXRC with: nomw, nomh, specwt, font, str unchanged */
    txor = 1;
#ifndef NO_PROTO
    chxp = 28.035f;
    chsp = -2.13f;
    chh = -.021f;
#else /* NO_PROTO */
    chxp = (float)28.035;
    chsp = (float)-2.13;
    chh = (float)-.021;
#endif /* NO_PROTO */
    chtxrc_(&nomw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    didtst, &rectok, &ccpok, 19L);
    if (! didtst) {
	goto L6011;
    }
#ifndef NO_PROTO
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal"
	    " text path should reflect the combined effects of negative value"
	    "s for character spacing and character height.", 13L, 155L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With negative values for character spaci"
	    "ng and character height, and a horizontal text path, the concate"
	    "nation point of a text rectangle should reflect its altered size."
	    , 19L, 169L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal\
 text path should reflect the combined effects of negative values for charac\
ter spacing and character height.", 13L, 155L);
    ifpf_(&rectok);
    setmsg_("6 7 8 9 10 13 17 18", "With negative values for character spaci\
ng and character height, and a horizontal text path, the concatenation point\
 of a text rectangle should reflect its altered size.", 19L, 169L);
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
    txp = 0;
    txalh = 1;
    txalv = 5;
    s_copy(str, "qqqq", 20L, 4L);
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 4L);
    chkinq_("pqtxx", &errind, 5L);
    nomcw = (r__1 = txexrx[1] - txexrx[0], dabs(r__1)) / 4;
    nomh = (r__1 = txexry[1] - txexry[0], dabs(r__1));
/*  call CHMONO with: nomcw, nomh, specwt, font, str unchanged */
    txor = 1;
#ifndef NO_PROTO
    chxp = 6.35f;
    chsp = (r__1 = chxp * nomcw, dabs(r__1)) * -8.51f;
    chh = -.021f;
#else /* NO_PROTO */
    chxp = (float)6.35;
    chsp = (r__1 = chxp * nomcw, dabs(r__1)) * (float)-8.51;
    chh = (float)-.021;
#endif /* NO_PROTO */
    chmono_(&nomcw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    rok1, &ccpok1, 4L);
/*  call CHMONO with: nomcw, nomh, specwt, font, str unchanged */
    txor = 1;
#ifndef NO_PROTO
    chxp = -.065f;
    chsp = (r__1 = chxp * nomcw, dabs(r__1)) * -1.01f;
    chh = -7.21f;
#else /* NO_PROTO */
    chxp = (float)-.065;
    chsp = (r__1 = chxp * nomcw, dabs(r__1)) * (float)-1.01;
    chh = (float)-7.21;
#endif /* NO_PROTO */
    chmono_(&nomcw, &nomh, &specwt, &font, str, &txor, &chxp, &chsp, &chh, &
	    rok2, &ccpok2, 4L);
#ifndef NO_PROTO
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal"
	    " text path should reflect the effect of negative character spaci"
	    "ng of greater magnitude than the expanded width of a single char"
	    "acter.", 13L, 180L);
#else /* NO_PROTO */
    setmsg_("6 7 8 9 13 15", "The size of a text rectangle with a horizontal\
 text path should reflect the effect of negative character spacing of greate\
r magnitude than the expanded width of a single character.", 13L, 180L);
#endif /* NO_PROTO */
    L__1 = rok1 && rok2;
    ifpf_(&L__1);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

