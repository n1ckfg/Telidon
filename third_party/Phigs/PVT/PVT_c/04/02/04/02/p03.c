/* fort/04/02/04/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b5 = 0.f;
#else /* NO_PROTO */
static real c_b5 = (float)0.;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b59 = 1.f;
static real c_b60 = .1f;
#else /* NO_PROTO */
static real c_b59 = (float)1.;
static real c_b60 = (float).1;
#endif /* NO_PROTO */
static integer c__33 = 33;
#ifndef NO_PROTO
static real c_b66 = .4f;
static real c_b68 = .5f;
#else /* NO_PROTO */
static real c_b66 = (float).4;
static real c_b68 = (float).5;
#endif /* NO_PROTO */
static integer c__6 = 6;
static integer c__26 = 26;
static integer c__5 = 5;
static integer c__4 = 4;
static integer c__21 = 21;
static integer c__22 = 22;
static integer c_n1 = -1;
#ifndef NO_PROTO
static real c_b142 = .25f;
static real c_b144 = .3f;
static real c_b177 = 3.f;
#else /* NO_PROTO */
static real c_b142 = (float).25;
static real c_b144 = (float).3;
static real c_b177 = (float)3.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.04.02/03                        * */
/*  *    TEST TITLE : Appearance of text fonts 1 and 2      * */
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
    static char ascch[1*33] = " " "!" "\"" "#" "$" "%" "&" "'" "(" ")" "*" 
	    "+" "," "-" "." "/" ":" ";" "<" "=" ">" "?" "@" "[" "\\" "]" 
	    "^" "_" "`" "{" "|" "}" "~";
#else /* NO_PROTO */
    static char ascch[1*33+1] = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2];
    real r__1, r__2;
    char ch__1[27], ch__2[11];

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
    static real xa[5], ya[5];
    static integer ix, iy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer icx;
    static char msg[300];
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
    extern /* Subroutine */ int npl (integer *, real *, real *), fail_(void);
#else /* NO_PROTO */
    extern logical dyn_();
    extern /* Subroutine */ int npl (), fail_();
#endif /* NO_PROTO */
    static real chht;
    static integer prec;
    static real chsp, ncwh;
    static integer perm[50], font, txci;
    static real npcx, npcy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *), natr (real *, real *, real *
	    , real *, char *, ftnlen), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep (), natr (), pass_();
#endif /* NO_PROTO */
    static real xpos, ypos, txrx[2], txry[2], rdum1, rdum2;
    static char narch[40], widch[40];
    static real xbase;
    static char ascnm[30*33], digit[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer fonta, fontb;
    static real chexp;
    static integer numch;
#ifndef NO_PROTO
    extern logical fpavl_(integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical fpavl_();
#endif /* NO_PROTO */
    static integer txdif;
    static real chsiz;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern doublereal rndrl_();
    extern integer itrim_();
#endif /* NO_PROTO */
    static real yincr;
    static char lower[26];
#ifndef NO_PROTO
    extern /* Subroutine */ int wcnpc_(real *, real *, real *, real *, real *)
	    , inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int wcnpc_(), inmsg_();
#endif /* NO_PROTO */
    static char upper[26];
#ifndef NO_PROTO
    extern /* Subroutine */ int nosep (integer *), nspli (integer *), nsplr (
	    integer *, integer *, integer *, real *, integer *), nopst (
	    integer *), nstxi (integer *), nsvwi (integer *), nstxr (integer *
	    , integer *, integer *, integer *, real *, real *, integer *), 
	    nqtxx (integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *, char *, integer *, real *, real *, real *, 
	    real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nosep (), nspli (), nsplr (), nopst (), 
	    nstxi (), nsvwi (), nstxr (), nqtxx ();
#endif /* NO_PROTO */
    static real offact;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndellb (integer *, integer *);
    extern logical dchflv_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndellb ();
    extern logical dchflv_();
#endif /* NO_PROTO */
    static integer grpbas, ngline;
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer picstr, srtans[20], anssiz, anslis[20], numlft, numlin, 
	    numnar;
    static real npcpwc;
    static char prompt[500], nonmem[6], distrg[40];
    static logical distng;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), nsatal (integer *, integer *), nsatch (real *), nseplb (
	    integer *), rnperm_(integer *, integer *), numlab_(integer *, 
	    real *, real *, real *), srtiar_(integer *, integer *), dilist_(
	    char *, integer *, integer *, ftnlen), opfail_(void), tstasc_(
	    char *, char *, char *, ftnlen, ftnlen, ftnlen), chkinq_(char *, 
	    integer *, ftnlen), dchpfv_(char *, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), setmsg_(), 
	    nsatal (), nsatch (), nseplb (), rnperm_(), numlab_(), srtiar_(), 
	    dilist_(), opfail_(), tstasc_(), chkinq_(), dchpfv_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___12 = { 0, msg, 0, "(A,2I3)", 300, 1 };


/* aspect source */
/*                bundled     individual */
/* text precision */
/* text path */
/* text alignment horizontal */
/* text alignment vertical */
/*  set up array for ASCII characters: */
    initgl_("04.02.04.02/03", 14L);
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
/*  get ratio of NPC to WC */
    wcnpc_(&c_b5, &c_b5, &npcx, &npcy, &npcpwc);
/*  set up array for ASCII names: */
    s_copy(ascnm, "space", 30L, 5L);
    s_copy(ascnm + 30, "exclamation point", 30L, 17L);
    s_copy(ascnm + 60, "double quotation marks", 30L, 22L);
    s_copy(ascnm + 90, "number sign", 30L, 11L);
    s_copy(ascnm + 120, "dollar sign", 30L, 11L);
    s_copy(ascnm + 150, "percent sign", 30L, 12L);
    s_copy(ascnm + 180, "ampersand", 30L, 9L);
    s_copy(ascnm + 210, "apostrophe", 30L, 10L);
    s_copy(ascnm + 240, "opening parenthesis", 30L, 19L);
    s_copy(ascnm + 270, "closing parenthesis", 30L, 19L);
    s_copy(ascnm + 300, "asterisk", 30L, 8L);
    s_copy(ascnm + 330, "plus", 30L, 4L);
    s_copy(ascnm + 360, "comma", 30L, 5L);
    s_copy(ascnm + 390, "hyphen", 30L, 6L);
    s_copy(ascnm + 420, "period", 30L, 6L);
    s_copy(ascnm + 450, "slant", 30L, 5L);
    s_copy(ascnm + 480, "colon", 30L, 5L);
    s_copy(ascnm + 510, "semicolon", 30L, 9L);
    s_copy(ascnm + 540, "less than", 30L, 9L);
    s_copy(ascnm + 570, "equals", 30L, 6L);
    s_copy(ascnm + 600, "greater than", 30L, 12L);
    s_copy(ascnm + 630, "question mark", 30L, 13L);
    s_copy(ascnm + 660, "commercial at", 30L, 13L);
    s_copy(ascnm + 690, "opening bracket", 30L, 15L);
    s_copy(ascnm + 720, "reverse slant", 30L, 13L);
    s_copy(ascnm + 750, "closing bracket", 30L, 15L);
    s_copy(ascnm + 780, "circumflex", 30L, 10L);
    s_copy(ascnm + 810, "underline", 30L, 9L);
    s_copy(ascnm + 840, "opening single quotation mark", 30L, 29L);
    s_copy(ascnm + 870, "opening brace", 30L, 13L);
    s_copy(ascnm + 900, "vertical line", 30L, 13L);
    s_copy(ascnm + 930, "closing brace", 30L, 13L);
    s_copy(ascnm + 960, "tilde", 30L, 5L);
#ifndef NO_PROTO
    setmsg_("1 3 4 10 11 12 13 14", "Fonts 1 and 2 should both contain all t"
	    "he ASCII special characters, in any precision.", 20L, 85L);
    yincr = .14285714285714285f;
#else /* NO_PROTO */
    setmsg_("1 3 4 10 11 12 13 14", "Fonts 1 and 2 should both contain all t\
he ASCII special characters, in any precision.", 20L, 85L);
    yincr = (float).14285714285714285;
#endif /* NO_PROTO */
    nsatal (&c__1, &c__3);
#ifndef NO_PROTO
    r__1 = yincr * .5f * npcpwc;
#else /* NO_PROTO */
    r__1 = yincr * (float).5 * npcpwc;
#endif /* NO_PROTO */
    nsatch (&r__1);
/*  label 1 just before font-precision setting */
    nlb (&c__1);
/*  label 2,3 just before,after character display */
    nlb (&c__2);
    nlb (&c__3);
    nsep (&c__1);
    nseplb (&c__1);
/*  loop thru fonts and precisions */
    for (font = 1; font <= 2; ++font) {
	for (prec = 0; prec <= 2; ++prec) {
/*        skip unavailable font-precision pairs */
	    if (! fpavl_(&globnu_1.wkid, &c__2, &font, &prec)) {
		s_wsfi(&io___12);
		do_fio(&c__1, "Unavailable (font,precision) pair: ", 35L);
		do_fio(&c__1, (char *)&font, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&prec, (ftnlen)sizeof(integer));
		e_wsfi();
		inmsg_(msg, 300L);
		goto L190;
	    }
	    nstxr (&globnu_1.wkid, &c__3, &font, &prec, &c_b59, &c_b60, &c__1)
		    ;
	    nstxi (&c__3);
	    nseplb (&c__2);
/*  perm = array to randomize order of the 33 characters */
	    rnperm_(&c__33, perm);
/*  loop thru GRPSIZ characters at a time; display next GRPSIZ */
/*  randomly ordered characters. */
	    for (grpbas = 0; grpbas <= 32; grpbas += 6) {
		ypos = 1 - yincr;
/* Computing MIN */
		i__1 = 6, i__2 = 33 - grpbas;
		numlft = min(i__1,i__2);
		numlab_(&numlft, &c_b66, &ypos, &yincr);
		i__1 = numlft;
		for (icx = 1; icx <= i__1; ++icx) {
		    iy = icx + grpbas;
		    natr (&c_b68, &ypos, &c_b5, &c_b5, ascch + (perm[iy - 1] 
			    - 1), 1L);
		    srtans[icx - 1] = perm[iy - 1];
		    ypos -= yincr;
/* L230: */
		}
/*  sort answers */
		srtiar_(&numlft, srtans);
/*  form prompt and get response */
/* Writing concatenation */
#ifndef NO_PROTO
		i__3[0] = 73, a__1[0] = "ASCII SPECIAL CHARACTERS: Identify,"
			" in order, the following characters: <";
#else /* NO_PROTO */
		i__3[0] = 73, a__1[0] = "ASCII SPECIAL CHARACTERS: Identify,\
 in order, the following characters: <";
#endif /* NO_PROTO */
		i__3[1] = 30, a__1[1] = ascnm + (srtans[0] - 1) * 30;
		s_cat(prompt, a__1, i__3, &c__2, 500L);
		i__1 = numlft;
		for (icx = 2; icx <= i__1; ++icx) {
		    i__2 = itrim_(prompt, 500L);
/* Writing concatenation */
		    i__3[0] = 4, a__1[0] = ">, <";
		    i__3[1] = 30, a__1[1] = ascnm + (srtans[icx - 1] - 1) * 
			    30;
		    s_cat(prompt + i__2, a__1, i__3, &c__2, 500 - i__2);
/* L240: */
		}
		i__1 = itrim_(prompt, 500L);
		s_copy(prompt + i__1, ">.", 500 - i__1, 2L);
L245:
		dilist_(prompt, &anssiz, anslis, 500L);
/*  check response */
		if (anssiz == 1 && anslis[0] == 0) {
		    opfail_();
		    goto L290;
		}
		if (anssiz != numlft) {
		    goto L255;
		}
		i__1 = numlft;
		for (icx = 1; icx <= i__1; ++icx) {
		    if (perm[anslis[icx - 1] + grpbas - 1] != srtans[icx - 1])
			     {
			goto L255;
		    }
/* L250: */
		}
/*           OK so far */
/*  clear display */
		nsep (&c__1);
		ndellb (&c__2, &c__3);
		goto L220;
/*  apparent failure */
L255:
		if (dyn_("Incorrect response; do you wish to re-try?", 42L)) {

		    goto L245;
		} else {
		    fail_();
		    goto L290;
		}
L220:
		;
	    }
/*  clear font and precision */
	    nsep (&c__1);
	    ndellb (&c__1, &c__2);
/*  end_fp_spec: */
L190:
/* L210: */
	    ;
	}
/* L200: */
    }
    pass_();
/*  end_ascii_special: */
L290:
/*  clear out everything */
    nsep (&c__1);
    ndellb (&c__1, &c__3);
#ifndef NO_PROTO
    setmsg_("1 3 4 10 11 12 13 14", "Fonts 1 and 2 should both contain all t"
	    "he ASCII uppercase letters, in any precision.", 20L, 84L);
#else /* NO_PROTO */
    setmsg_("1 3 4 10 11 12 13 14", "Fonts 1 and 2 should both contain all t\
he ASCII uppercase letters, in any precision.", 20L, 84L);
#endif /* NO_PROTO */
    s_copy(upper, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26L, 26L);
    s_copy(nonmem, "bdfhkt", 6L, 6L);
    ix = rndint_(&c__1, &c__6);
/* Writing concatenation */
    i__3[0] = 1, a__1[0] = nonmem + (ix - 1);
    i__3[1] = 26, a__1[1] = upper;
    s_cat(ch__1, a__1, i__3, &c__2, 27L);
#ifndef NO_PROTO
    tstasc_("ASCII UPPERCASE LETTERS: Which character is NOT an uppercase le"
	    "tter?", ch__1, "B", 68L, 27L, 1L);
    setmsg_("1 3 4 10 11 12 13 14", "Fonts 1 and 2 should both contain all t"
	    "he ASCII lowercase letters, in any precision.", 20L, 84L);
#else /* NO_PROTO */
    tstasc_("ASCII UPPERCASE LETTERS: Which character is NOT an uppercase le\
tter?", ch__1, "B", 68L, 27L, 1L);
    setmsg_("1 3 4 10 11 12 13 14", "Fonts 1 and 2 should both contain all t\
he ASCII lowercase letters, in any precision.", 20L, 84L);
#endif /* NO_PROTO */
    s_copy(lower, "abcdefghijklmnopqrstuvwxyz", 26L, 26L);
L395:
    ix = rndint_(&c__1, &c__26);
    if (ix == 9) {
	goto L395;
    }
/* Writing concatenation */
    i__3[0] = 1, a__1[0] = upper + (ix - 1);
    i__3[1] = 26, a__1[1] = lower;
    s_cat(ch__1, a__1, i__3, &c__2, 27L);
#ifndef NO_PROTO
    tstasc_("ASCII LOWERCASE LETTERS: Which character is NOT a lowercase let"
	    "ter?", ch__1, "B", 67L, 27L, 1L);
    setmsg_("1 3 4 10 11 12 13 14", "Fonts 1 and 2 should both contain all t"
	    "he ASCII digit characters, in any precision.", 20L, 83L);
#else /* NO_PROTO */
    tstasc_("ASCII LOWERCASE LETTERS: Which character is NOT a lowercase let\
ter?", ch__1, "B", 67L, 27L, 1L);
    setmsg_("1 3 4 10 11 12 13 14", "Fonts 1 and 2 should both contain all t\
he ASCII digit characters, in any precision.", 20L, 83L);
#endif /* NO_PROTO */
    s_copy(digit, "0123456789", 10L, 10L);
    s_copy(nonmem, "CEISZ", 6L, 5L);
    ix = rndint_(&c__1, &c__5);
/* Writing concatenation */
    i__3[0] = 1, a__1[0] = nonmem + (ix - 1);
    i__3[1] = 10, a__1[1] = digit;
    s_cat(ch__2, a__1, i__3, &c__2, 11L);
    tstasc_("ASCII DIGITS: Which character is NOT a digit?", ch__2, "B", 45L, 
	    11L, 1L);
/*  clear out everything */
    nsep (&c__1);
    ndellb (&c__1, &c__3);
#ifndef NO_PROTO
    setmsg_("1 3 4 10 11 12 13 15", "Text fonts 1 and 2 should be visually d"
	    "istinguishable in any precision.", 20L, 71L);
#else /* NO_PROTO */
    setmsg_("1 3 4 10 11 12 13 15", "Text fonts 1 and 2 should be visually d\
istinguishable in any precision.", 20L, 71L);
#endif /* NO_PROTO */
    fonta = rndint_(&c__3, &c__4);
    fontb = 7 - fonta;
#ifndef NO_PROTO
    yincr = .15f;
#else /* NO_PROTO */
    yincr = (float).15;
#endif /* NO_PROTO */
    nsatal (&c__1, &c__3);
#ifndef NO_PROTO
    r__1 = yincr * .5f * npcpwc;
#else /* NO_PROTO */
    r__1 = yincr * (float).5 * npcpwc;
#endif /* NO_PROTO */
    nsatch (&r__1);
    nlb (&c__21);
    nlb (&c__22);
    nosep (&c_n1);
    numlin = 5;
    for (prec = 0; prec <= 2; ++prec) {
	txdif = rndint_(&c__1, &numlin);
/*  switch fonts */
	fonta = 7 - fonta;
	fontb = 7 - fontb;
	nstxr (&globnu_1.wkid, &c__3, &c__1, &prec, &c_b59, &c_b60, &c__1);
	nstxr (&globnu_1.wkid, &c__4, &c__2, &prec, &c_b59, &c_b60, &c__1);
	ypos = 1 - yincr;
	numlab_(&numlin, &c_b142, &ypos, &yincr);
	i__1 = numlin;
	for (ix = 1; ix <= i__1; ++ix) {
	    if (ix == txdif) {
		nstxi (&fontb);
	    } else {
		nstxi (&fonta);
	    }
	    natr (&c_b144, &ypos, &c_b5, &c_b5, "Test", 4L);
	    ypos -= yincr;
/* L620: */
	}
#ifndef NO_PROTO
	distng = dchflv_("DISTINGUISHABILITY OF FONTS 1 AND 2: Which line ha"
		"s a different font?", &numlin, &txdif, 69L);
#else /* NO_PROTO */
	distng = dchflv_("DISTINGUISHABILITY OF FONTS 1 AND 2: Which line ha\
s a different font?", &numlin, &txdif, 69L);
#endif /* NO_PROTO */
/*  clear out display for this precision */
	nsep (&c__1);
	ndellb (&c__21, &c__22);
	if (distng) {
	    goto L690;
	}
/*  next precision */
/* L610: */
    }
    pass_();
/*  end_distin: */
L690:
#ifndef NO_PROTO
    setmsg_("1 3 4 11 12 16 17 18 23 24 25 27 28", "In text font 1, all char"
	    "acter bodies affected by the same annotation text character heig"
	    "ht, character expansion factor, and character spacing should hav"
	    "e the same width.", 35L, 169L);
#else /* NO_PROTO */
    setmsg_("1 3 4 11 12 16 17 18 23 24 25 27 28", "In text font 1, all char\
acter bodies affected by the same annotation text character height, characte\
r expansion factor, and character spacing should have the same width.", 35L, 
	    169L);
#endif /* NO_PROTO */
/*  Use <inquire text extent> to determine */
/*    ncwh = nominal character width/height ratio for font 1 */
    nqtxx (&dialog_1.specwt, &c__1, &c_b59, &c_b5, &c_b59, &c__0, &c__1, &
	    c__5, "Testing 123", &errind, txrx, txry, &rdum1, &rdum2, 11L);
    chkinq_("pqtxx", &errind, 5L);
    ncwh = (r__1 = txrx[1] - txrx[0], dabs(r__1)) / 11;
/*  number of lines to be displayed */
    numlin = 6;
/*  ngline = incorrect line = random number from 1 to numlin */
    ngline = rndint_(&c__1, &numlin);
/*  text font,precision = 1,STROKE, character spacing = 0, */
/*  annotation text alignment = LEFT,BASE */
    nsatal (&c__1, &c__3);
/*  try to paint text and polylines different colors */
    nspli (&c__1);
    nsplr (&globnu_1.wkid, &c__1, &c__1, &c_b59, &c__2);
/*  narrow characters */
    s_copy(narch, ".,;:`1lij|\"[]{}", 40L, 15L);
/*  wide characters */
    s_copy(widch, "WHAZMOQRFEGBXNS", 40L, 15L);
#ifndef NO_PROTO
    xbase = .3f;
#else /* NO_PROTO */
    xbase = (float).3;
#endif /* NO_PROTO */
/*  display labels for all numlin lines to be shown */
#ifndef NO_PROTO
    yincr = 1.f / (numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (numlin + 1);
#endif /* NO_PROTO */
    ypos = 1 - yincr;
#ifndef NO_PROTO
    r__1 = xbase - .05f;
#else /* NO_PROTO */
    r__1 = xbase - (float).05;
#endif /* NO_PROTO */
    numlab_(&numlin, &r__1, &ypos, &yincr);
/*  set up room for separators */
#ifndef NO_PROTO
    chsp = .2f;
#else /* NO_PROTO */
    chsp = (float).2;
#endif /* NO_PROTO */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
L722:
#ifndef NO_PROTO
	r__1 = .2f / numlin;
	r__2 = .6f / numlin;
#else /* NO_PROTO */
	r__1 = (float).2 / numlin;
	r__2 = (float).6 / numlin;
#endif /* NO_PROTO */
	chht = rndrl_(&r__1, &r__2);
	chexp = rndrl_(&c_b144, &c_b177);
/*  horizontal distance per character */
	chsiz = chht * (ncwh * chexp + chsp);
/*  number of characters this string */
#ifndef NO_PROTO
	numch = .6f / chsiz;
#else /* NO_PROTO */
	numch = (float).6 / chsiz;
#endif /* NO_PROTO */
	if (numch < 4 || numch > 25) {
	    goto L722;
	}
/*  number of narrow characters */
	numnar = numch / 2;
/* Writing concatenation */
	i__3[0] = numnar, a__1[0] = narch;
	i__3[1] = numch - numnar, a__1[1] = widch;
	s_cat(distrg, a__1, i__3, &c__2, 40L);
	r__1 = chht * npcpwc;
	nsatch (&r__1);
	nstxi (&ix);
	nstxr (&globnu_1.wkid, &ix, &c__1, &c__2, &chexp, &chsp, &c__1);
	natr (&xbase, &ypos, &c_b5, &c_b5, distrg, numch);
/*  draw vertical lines between characters */
	ya[0] = ypos - chht / 2;
	ya[1] = ypos + chht / 2;
/* if this is "incorrect" line, fiddle with separators by plus or minu
s 20%*/
	if (ix == ngline) {
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
/*  start in middle of character space between 1st and 2nd characters 
*/
#ifndef NO_PROTO
	r__1 = xbase + (numch - .5f) * chsiz;
#else /* NO_PROTO */
	r__1 = xbase + (numch - (float).5) * chsiz;
#endif /* NO_PROTO */
	r__2 = chsiz * offact;
	for (xpos = xbase + chsiz - chsp * chht / 2; r__2 < 0 ? xpos >= r__1 :
		 xpos <= r__1; xpos += r__2) {
	    xa[0] = xpos;
	    xa[1] = xpos;
	    npl (&c__2, xa, ya);
/* L730: */
	}
	ypos -= yincr;
/* L720: */
    }
#ifndef NO_PROTO
    dchpfv_("FONT 1 MONOSPACED: In which line are the characters NOT located"
	    " between the separators?", &numlin, &ngline, 87L);
#else /* NO_PROTO */
    dchpfv_("FONT 1 MONOSPACED: In which line are the characters NOT located\
 between the separators?", &numlin, &ngline, 87L);
#endif /* NO_PROTO */
/* L666: */
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

