/* fort/04/03/02/02/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__6 = 6;
static integer c__801 = 801;
static integer c__1 = 1;
static integer c__102 = 102;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__9 = 9;
static integer c__4 = 4;
static integer c__2 = 2;
static integer c__10 = 10;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.03.02.02/07                        * */
/*  *    TEST TITLE : Hue recognition for colour models     * */
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

    static logical cmodel[4] = { FALSE_,FALSE_,FALSE_,FALSE_ };
    static integer hueent[6] = { 2,3,5,6,7,9 };
#ifndef NO_PROTO
    static char colist[7*9] = "black  " "blue   " "cyan   " "gray   " "green"
	    "  " "magenta" "red    " "white  " "yellow ";
    static real rgbcc[27]	/* was [3][9] */ = { 0.f,0.f,0.f,0.f,0.f,1.f,
	    0.f,1.f,1.f,.5f,.5f,.5f,0.f,1.f,0.f,1.f,0.f,1.f,1.f,0.f,0.f,1.f,
	    1.f,1.f,1.f,1.f,0.f };
    static real hsvcc[27]	/* was [3][9] */ = { -1.f,-1.f,0.f,.6667f,1.f,
	    1.f,.5f,1.f,1.f,-1.f,0.f,.5f,.3333f,1.f,1.f,.8333f,1.f,1.f,0.f,
	    1.f,1.f,-1.f,0.f,1.f,.1667f,1.f,1.f };
    static real hlscc[27]	/* was [3][9] */ = { -1.f,0.f,-1.f,.6667f,.5f,
	    1.f,.5f,.5f,1.f,-1.f,.5f,0.f,.3333f,.5f,1.f,.8333f,.5f,1.f,0.f,
	    .5f,1.f,-1.f,1.f,-1.f,.1667f,.5f,1.f };
    static real ciebas[30]	/* was [3][10] */ = { -1.f,-1.f,0.f,.11689f,
	    .20283f,1.f,.19366f,.46435f,.5f,.00733f,.5425f,1.f,.31886f,
	    .54308f,1.f,.34634f,.48f,1.f,.32592f,.12348f,1.f,.59985f,.47955f,
	    1.f,.19366f,.46435f,1.f,.24702f,.55471f,1.f };
    static real ciegr1[18]	/* was [3][6] */ = { .20462f,.06966f,1.f,
	    .05689f,.33083f,1.f,.08567f,.57794f,1.f,.21172f,.55987f,1.f,
	    .27978f,.54823f,1.f,.53137f,.39053f,1.f };
    static real ciegr2[18]	/* was [3][6] */ = { .02205f,.44449f,1.f,
	    .17644f,.56634f,1.f,.397f,.52885f,1.f,.4388f,.27271f,1.f,.31241f,
	    .5087f,1.f,.29942f,.42f,1.f };
#else /* NO_PROTO */
    static char colist[7*9+1] = "black  blue   cyan   gray   green  magentar\
ed    white  yellow ";
    static real rgbcc[27]	/* was [3][9] */ = { (float)0.,(float)0.,(
	    float)0.,(float)0.,(float)0.,(float)1.,(float)0.,(float)1.,(float)
	    1.,(float).5,(float).5,(float).5,(float)0.,(float)1.,(float)0.,(
	    float)1.,(float)0.,(float)1.,(float)1.,(float)0.,(float)0.,(float)
	    1.,(float)1.,(float)1.,(float)1.,(float)1.,(float)0. };
    static real hsvcc[27]	/* was [3][9] */ = { (float)-1.,(float)-1.,(
	    float)0.,(float).6667,(float)1.,(float)1.,(float).5,(float)1.,(
	    float)1.,(float)-1.,(float)0.,(float).5,(float).3333,(float)1.,(
	    float)1.,(float).8333,(float)1.,(float)1.,(float)0.,(float)1.,(
	    float)1.,(float)-1.,(float)0.,(float)1.,(float).1667,(float)1.,(
	    float)1. };
    static real hlscc[27]	/* was [3][9] */ = { (float)-1.,(float)0.,(
	    float)-1.,(float).6667,(float).5,(float)1.,(float).5,(float).5,(
	    float)1.,(float)-1.,(float).5,(float)0.,(float).3333,(float).5,(
	    float)1.,(float).8333,(float).5,(float)1.,(float)0.,(float).5,(
	    float)1.,(float)-1.,(float)1.,(float)-1.,(float).1667,(float).5,(
	    float)1. };
    static real ciebas[30]	/* was [3][10] */ = { (float)-1.,(float)-1.,(
	    float)0.,(float).11689,(float).20283,(float)1.,(float).19366,(
	    float).46435,(float).5,(float).00733,(float).5425,(float)1.,(
	    float).31886,(float).54308,(float)1.,(float).34634,(float).48,(
	    float)1.,(float).32592,(float).12348,(float)1.,(float).59985,(
	    float).47955,(float)1.,(float).19366,(float).46435,(float)1.,(
	    float).24702,(float).55471,(float)1. };
    static real ciegr1[18]	/* was [3][6] */ = { (float).20462,(float)
	    .06966,(float)1.,(float).05689,(float).33083,(float)1.,(float)
	    .08567,(float).57794,(float)1.,(float).21172,(float).55987,(float)
	    1.,(float).27978,(float).54823,(float)1.,(float).53137,(float)
	    .39053,(float)1. };
    static real ciegr2[18]	/* was [3][6] */ = { (float).02205,(float)
	    .44449,(float)1.,(float).17644,(float).56634,(float)1.,(float)
	    .397,(float).52885,(float)1.,(float).4388,(float).27271,(float)1.,
	    (float).31241,(float).5087,(float)1.,(float).29942,(float).42,(
	    float)1. };
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3];
    logical L__1;
    char ch__1[251], ch__2[285], ch__3[261], ch__4[278], ch__5[276];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i;
    static real cc[9];
    static integer ix, iy, iz, cola, cmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer npci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf ();
#endif /* NO_PROTO */
    static integer nmod, txci;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7, maxfg, 
	    mcoli;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nscmd (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nscmd ();
#endif /* NO_PROTO */
    static integer huedx;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nclst (void), nexst (
	    integer *), nopst (integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nclst (), nexst (), nopst (), 
	    nsvwi ();
#endif /* NO_PROTO */
    static char ciepr1[87], ciepr2[103], ciepr3[101], prmpt1[77];
    static real shadcc[12]	/* was [3][4] */;
    static logical filmod;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcmdf (integer *, integer *, integer *, 
	    integer *, integer *, integer *), chkinq_(char *, integer *, 
	    ftnlen), setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcmdf (), chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind, lscoli[20], sizpal, picstr, numset, result;
#ifndef NO_PROTO
    extern integer tsthue_(char *, logical *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern integer tsthue_();
#endif /* NO_PROTO */
    static logical didtst;
    static char prmbas[139];
#ifndef NO_PROTO
    extern logical intsty_(integer *, integer *);
#else /* NO_PROTO */
    extern logical intsty_();
#endif /* NO_PROTO */
    static char prmint[236];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setasf_(integer *), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), setrvs_(char *, real *, integer *, ftnlen),
	     sethue_(integer *, integer *, integer *, integer *, real *, 
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    opcofl_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setasf_(), nqwksl (), 
	    setrvs_(), sethue_(), setmsg_(), opcofl_();
#endif /* NO_PROTO */

/* aspect source */
/*                bundled     individual */
/* colour available */
/* interior style */
/* colour model */
/*  identify hue entries */
/*  Alphabetical order of hues (except CIE): */
/*  CIE coordinates for basic hues and neutrals: */
/*                    black,   blue,             gray */
/*           green,            orange,           pink */
/*           purple,           red,              white */
/*           yellow, */
/*  CIE coordinates for group 1 of mixed hues */
/*                 purplish-blue,    greenish-blue,    yellowish-green, */

/*                 greenish-yellow,  orange-yellow,    purplish-red */
/*  CIE coordinates for group 2 of mixed hues */
/*                 bluish-green,     yellow-green,     reddish-orange, */
/*                 reddish-purple,   yellowish-pink,   purplish-pink, */
    initgl_("04.03.02.02/07", 14L);
/* open PHIGS */
    xpopph_(&c__6, &globnu_1.memun);
/* set-up of workstation and dialogue area */
    picstr = 101;
    txci = 11;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  by convention, view #1 is for picture */
    nsvwi (&c__1);
/*  use individual attributes */
    setasf_(&c__1);
    nexst (&c__102);
    nclst ();
/*  Check to see that color is available */
/*    SIZPAL = number of colours available (size of palette) */
/*    COLA = COLOR/MONOCHROME */
    nqcf (&dialog_1.specwt, &errind, &sizpal, &cola, &npci, cc);
    chkinq_("pqcf", &errind, 4L);
    if (cola != 1) {
	inmsg_("Multi-hue color not available; skipping all hue tests.", 54L);

	goto L666;
    }
    if (sizpal > 0 && sizpal < 27) {
#ifndef NO_PROTO
	inmsg_("Number of available colors too low for reliable testing; ski"
		"pping all hue tests.", 80L);
#else /* NO_PROTO */
	inmsg_("Number of available colors too low for reliable testing; ski\
pping all hue tests.", 80L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  Determine the maximum number of color indices (MCOLI) available. */
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &mcoli, &idum7);
    chkinq_("pqwksl", &errind, 6L);
/*  Maximum available # foreground colors, besides #1 */
    maxfg = mcoli - 2;
    if (maxfg < 4) {
#ifndef NO_PROTO
	inmsg_("Number of available color entries too low for reliable testi"
		"ng; skipping all hue tests.", 87L);
#else /* NO_PROTO */
	inmsg_("Number of available color entries too low for reliable testi\
ng; skipping all hue tests.", 87L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  Determine how to fill in rectangles, use solid style */
/*  if it is available, otherwise use dense polyline cross-hatch */
    filmod = intsty_(&dialog_1.specwt, &c__1);
/*  Determine list of color models to test. */
    nqcmdf (&dialog_1.specwt, &c__0, &errind, &nmod, &idum1, &idum2);
    chkinq_("pqcmdf", &errind, 6L);
    i__1 = nmod;
    for (i = 1; i <= i__1; ++i) {
	nqcmdf (&dialog_1.specwt, &i, &errind, &idum1, &cmod, &idum2);
	chkinq_("pqcmdf", &errind, 6L);
	if (1 <= cmod && cmod <= 4) {
	    cmodel[cmod - 1] = TRUE_;
	}
/* L110: */
    }
/*  prompt for color selection for every color model other than CIE */
#ifndef NO_PROTO
    s_copy(prmpt1, "1-black, 2-blue, 3-cyan, 4-gray, 5-green, 6-magenta, 7-r"
	    "ed, 8-white, 9-yellow", 77L, 77L);
#else /* NO_PROTO */
    s_copy(prmpt1, "1-black, 2-blue, 3-cyan, 4-gray, 5-green, 6-magenta, 7-r\
ed, 8-white, 9-yellow", 77L, 77L);
#endif /* NO_PROTO */
/*  prompt for basic colors */
#ifndef NO_PROTO
    s_copy(prmbas, "Enter a list of color identifiers which corresponds to t"
	    "he order (from top to bottom) of displayed rectangles.  The colo"
	    "r identifiers are: ", 139L, 139L);
#else /* NO_PROTO */
    s_copy(prmbas, "Enter a list of color identifiers which corresponds to t\
he order (from top to bottom) of displayed rectangles.  The color identifier\
s are: ", 139L, 139L);
#endif /* NO_PROTO */
/*  prompt for intermediate colors */
#ifndef NO_PROTO
    s_copy(prmint, "Enter a list of shading identifiers which corresponds to"
	    " the order (from top to bottom) of displayed rectangles.  The id"
	    "entifiers are: 1-normal, 2-light (closer to white), 3-muted (clo"
	    "ser to gray), and 4-dark (closer to black) shade of ", 236L, 236L)
	    ;
#else /* NO_PROTO */
    s_copy(prmint, "Enter a list of shading identifiers which corresponds to\
 the order (from top to bottom) of displayed rectangles.  The identifiers ar\
e: 1-normal, 2-light (closer to white), 3-muted (closer to gray), and 4-dark\
 (closer to black) shade of ", 236L, 236L);
#endif /* NO_PROTO */
/*  keep background as dark gray, #1 foreground as white */
    nscmd (&globnu_1.wkid, &c__1);
    setrvs_(".25,.25,.25", cc, &ix, 11L);
    nscr (&globnu_1.wkid, &c__0, &c__3, cc);
    setrvs_("1,1,1", cc, &ix, 5L);
    nscr (&globnu_1.wkid, &c__1, &c__3, cc);
    nopst (&c__102);
/*  **** **** **** ****   RGB Color Model   **** **** **** **** */
/*  Make sure RGB model is available */
    if (! cmodel[0]) {
	inmsg_("RGB color model not available; skipping RGB tests.", 50L);
	goto L199;
    }
    sethue_(&globnu_1.wkid, &c__1, &maxfg, &c__9, rgbcc, &numset, lscoli);
    if (numset < 4) {
#ifndef NO_PROTO
	inmsg_("Realized basic colors not accurate enough for testing RGB co"
		"lor model.", 70L);
#else /* NO_PROTO */
	inmsg_("Realized basic colors not accurate enough for testing RGB co\
lor model.", 70L);
#endif /* NO_PROTO */
	goto L199;
    }
#ifndef NO_PROTO
    setmsg_("1 5 16 17 21 22 32 33", "The basic hues and neutral colors shou"
	    "ld appear as described within the RGB color model.", 21L, 88L);
#else /* NO_PROTO */
    setmsg_("1 5 16 17 21 22 32 33", "The basic hues and neutral colors shou\
ld appear as described within the RGB color model.", 21L, 88L);
#endif /* NO_PROTO */
/* Writing concatenation */
    i__2[0] = 35, a__1[0] = "APPEARANCE OF BASIC COLORS IN RGB: ";
    i__2[1] = 139, a__1[1] = prmbas;
    i__2[2] = 77, a__1[2] = prmpt1;
    s_cat(ch__1, a__1, i__2, &c__3, 251L);
    result = tsthue_(ch__1, &filmod, &numset, lscoli, 251L);
    if (result == -2) {
	opcofl_();
    }
    L__1 = result == 1;
    ifpf_(&L__1);
    if (sizpal > 0 && sizpal < 64) {
#ifndef NO_PROTO
	inmsg_("Number of available colors too low for reliable testing of i"
		"ntermediate RGB hues.", 81L);
#else /* NO_PROTO */
	inmsg_("Number of available colors too low for reliable testing of i\
ntermediate RGB hues.", 81L);
#endif /* NO_PROTO */
	goto L199;
    }
    didtst = FALSE_;
    for (ix = 1; ix <= 6; ++ix) {
/*  set up next hue */
	huedx = hueent[ix - 1];
/*  primary,light,gray,dark */
	for (iy = 1; iy <= 3; ++iy) {
/*  primary */
	    shadcc[iy - 1] = rgbcc[iy + huedx * 3 - 4];
/*  light */
#ifndef NO_PROTO
	    shadcc[iy + 2] = rgbcc[iy + huedx * 3 - 4] * .3f + 
		    .69999999999999996f;
#else /* NO_PROTO */
	    shadcc[iy + 2] = rgbcc[iy + huedx * 3 - 4] * (float).3 + (float)
		    .69999999999999996;
#endif /* NO_PROTO */
/*  grayish */
#ifndef NO_PROTO
	    shadcc[iy + 5] = rgbcc[iy + huedx * 3 - 4] * .3f + 
		    .34999999999999998f;
#else /* NO_PROTO */
	    shadcc[iy + 5] = rgbcc[iy + huedx * 3 - 4] * (float).3 + (float)
		    .34999999999999998;
#endif /* NO_PROTO */
/*  dark */
#ifndef NO_PROTO
	    shadcc[iy + 8] = rgbcc[iy + huedx * 3 - 4] * .4f + 0.f;
#else /* NO_PROTO */
	    shadcc[iy + 8] = rgbcc[iy + huedx * 3 - 4] * (float).4 + (float)
		    0.;
#endif /* NO_PROTO */
/* L133: */
	}
	sethue_(&globnu_1.wkid, &c__1, &maxfg, &c__4, shadcc, &numset, lscoli)
		;
/*  skip hue, if not all shown */
	if (numset < 4) {
	    goto L130;
	}
	didtst = TRUE_;
/* Writing concatenation */
	i__2[0] = 42, a__1[0] = "APPEARANCE OF INTERMEDIATE COLORS IN RGB: ";
	i__2[1] = 236, a__1[1] = prmint;
	i__2[2] = 7, a__1[2] = colist + (huedx - 1) * 7;
	s_cat(ch__2, a__1, i__2, &c__3, 285L);
	result = tsthue_(ch__2, &filmod, &numset, lscoli, 285L);
	if (result < 0) {
	    goto L140;
	}
L130:
	;
    }
L140:
    if (didtst) {
#ifndef NO_PROTO
	setmsg_("1 5 16 17 21 22 32 33", "The intermediate hues should appea"
		"r as described within the RGB color model.", 21L, 76L);
#else /* NO_PROTO */
	setmsg_("1 5 16 17 21 22 32 33", "The intermediate hues should appea\
r as described within the RGB color model.", 21L, 76L);
#endif /* NO_PROTO */
	if (result == -2) {
	    opcofl_();
	}
	L__1 = result > 0;
	ifpf_(&L__1);
    } else {
#ifndef NO_PROTO
	inmsg_("Realized intermediate colors not accurate enough for testing"
		" RGB color model.", 77L);
#else /* NO_PROTO */
	inmsg_("Realized intermediate colors not accurate enough for testing\
 RGB color model.", 77L);
#endif /* NO_PROTO */
    }
/*  end RGB */
L199:
/*  **** **** **** ****   HSV Color Model   **** **** **** **** */
/*  Make sure HSV model is available */
    if (! cmodel[2]) {
	inmsg_("HSV color model not available; skipping HSV tests.", 50L);
	goto L299;
    }
    sethue_(&globnu_1.wkid, &c__3, &maxfg, &c__9, hsvcc, &numset, lscoli);
    if (numset < 4) {
#ifndef NO_PROTO
	inmsg_("Realized basic colors not accurate enough for testing HSV co"
		"lor model.", 70L);
#else /* NO_PROTO */
	inmsg_("Realized basic colors not accurate enough for testing HSV co\
lor model.", 70L);
#endif /* NO_PROTO */
	goto L299;
    }
#ifndef NO_PROTO
    setmsg_("1 5 16 17 21 24 32 33", "The basic hues and neutral colors shou"
	    "ld appear as described within the HSV color model.", 21L, 88L);
#else /* NO_PROTO */
    setmsg_("1 5 16 17 21 24 32 33", "The basic hues and neutral colors shou\
ld appear as described within the HSV color model.", 21L, 88L);
#endif /* NO_PROTO */
/* Writing concatenation */
    i__2[0] = 35, a__1[0] = "APPEARANCE OF BASIC COLORS IN HSV: ";
    i__2[1] = 139, a__1[1] = prmbas;
    i__2[2] = 77, a__1[2] = prmpt1;
    s_cat(ch__1, a__1, i__2, &c__3, 251L);
    result = tsthue_(ch__1, &filmod, &numset, lscoli, 251L);
    if (result == -2) {
	opcofl_();
    }
    L__1 = result == 1;
    ifpf_(&L__1);
    if (sizpal > 0 && sizpal < 64) {
#ifndef NO_PROTO
	inmsg_("Number of available colors too low for reliable testing of i"
		"ntermediate HSV hues.", 81L);
#else /* NO_PROTO */
	inmsg_("Number of available colors too low for reliable testing of i\
ntermediate HSV hues.", 81L);
#endif /* NO_PROTO */
	goto L299;
    }
    didtst = FALSE_;
    for (ix = 1; ix <= 6; ++ix) {
/*  set up next hue */
	huedx = hueent[ix - 1];
/*  shadcc(component-index, shade) */
/*  shade: 1-normal, 2-light, 3-grayish, and 4-dark */
	for (iy = 1; iy <= 3; ++iy) {
	    for (iz = 1; iz <= 4; ++iz) {
		shadcc[iy + iz * 3 - 4] = hsvcc[iy + huedx * 3 - 4];
/* L235: */
	    }
/* L233: */
	}
/*  light - set saturation to 0.5 */
#ifndef NO_PROTO
	shadcc[4] = .5f;
#else /* NO_PROTO */
	shadcc[4] = (float).5;
#endif /* NO_PROTO */
/*  grayish - set saturation to 0.5 and value to 0.7 */
#ifndef NO_PROTO
	shadcc[7] = .5f;
	shadcc[8] = .7f;
#else /* NO_PROTO */
	shadcc[7] = (float).5;
	shadcc[8] = (float).7;
#endif /* NO_PROTO */
/*  dark - set value to 0.3 */
#ifndef NO_PROTO
	shadcc[11] = .3f;
#else /* NO_PROTO */
	shadcc[11] = (float).3;
#endif /* NO_PROTO */
	sethue_(&globnu_1.wkid, &c__3, &maxfg, &c__4, shadcc, &numset, lscoli)
		;
/*  skip hue, if not all shown */
	if (numset < 4) {
	    goto L230;
	}
	didtst = TRUE_;
/* Writing concatenation */
	i__2[0] = 42, a__1[0] = "APPEARANCE OF INTERMEDIATE COLORS IN HSV: ";
	i__2[1] = 236, a__1[1] = prmint;
	i__2[2] = 7, a__1[2] = colist + (huedx - 1) * 7;
	s_cat(ch__2, a__1, i__2, &c__3, 285L);
	result = tsthue_(ch__2, &filmod, &numset, lscoli, 285L);
	if (result < 0) {
	    goto L240;
	}
L230:
	;
    }
L240:
    if (didtst) {
#ifndef NO_PROTO
	setmsg_("1 5 16 17 21 24 32 33", "The intermediate hues should appea"
		"r as described within the HSV color model.", 21L, 76L);
#else /* NO_PROTO */
	setmsg_("1 5 16 17 21 24 32 33", "The intermediate hues should appea\
r as described within the HSV color model.", 21L, 76L);
#endif /* NO_PROTO */
	if (result == -2) {
	    opcofl_();
	}
	L__1 = result > 0;
	ifpf_(&L__1);
    } else {
#ifndef NO_PROTO
	inmsg_("Realized intermediate colors not accurate enough for testing"
		" HSV color model.", 77L);
#else /* NO_PROTO */
	inmsg_("Realized intermediate colors not accurate enough for testing\
 HSV color model.", 77L);
#endif /* NO_PROTO */
    }
/*  end HSV */
L299:
/*  **** **** **** ****   HLS Color Model   **** **** **** **** */
/*  Make sure HLS model is available */
    if (! cmodel[3]) {
	inmsg_("HLS color model not available; skipping HLS tests.", 50L);
	goto L399;
    }
    sethue_(&globnu_1.wkid, &c__4, &maxfg, &c__9, hlscc, &numset, lscoli);
    if (numset < 4) {
#ifndef NO_PROTO
	inmsg_("Realized basic colors not accurate enough for testing HLS co"
		"lor model.", 70L);
#else /* NO_PROTO */
	inmsg_("Realized basic colors not accurate enough for testing HLS co\
lor model.", 70L);
#endif /* NO_PROTO */
	goto L399;
    }
#ifndef NO_PROTO
    setmsg_("1 5 16 17 21 25 32 33", "The basic hues and neutral colors shou"
	    "ld appear as described within the HLS color model.", 21L, 88L);
#else /* NO_PROTO */
    setmsg_("1 5 16 17 21 25 32 33", "The basic hues and neutral colors shou\
ld appear as described within the HLS color model.", 21L, 88L);
#endif /* NO_PROTO */
/* Writing concatenation */
    i__2[0] = 35, a__1[0] = "APPEARANCE OF BASIC COLORS IN HLS: ";
    i__2[1] = 139, a__1[1] = prmbas;
    i__2[2] = 77, a__1[2] = prmpt1;
    s_cat(ch__1, a__1, i__2, &c__3, 251L);
    result = tsthue_(ch__1, &filmod, &numset, lscoli, 251L);
    if (result == -2) {
	opcofl_();
    }
    L__1 = result == 1;
    ifpf_(&L__1);
    if (sizpal > 0 && sizpal < 64) {
#ifndef NO_PROTO
	inmsg_("Number of available colors too low for reliable testing of i"
		"ntermediate HLS hues.", 81L);
#else /* NO_PROTO */
	inmsg_("Number of available colors too low for reliable testing of i\
ntermediate HLS hues.", 81L);
#endif /* NO_PROTO */
	goto L399;
    }
    didtst = FALSE_;
    for (ix = 1; ix <= 6; ++ix) {
/*  set up next hue */
	huedx = hueent[ix - 1];
/*  shadcc(component-index, shade) */
/*  shade: 1-normal, 2-light, 3-grayish, and 4-dark */
	for (iy = 1; iy <= 3; ++iy) {
	    for (iz = 1; iz <= 4; ++iz) {
		shadcc[iy + iz * 3 - 4] = hlscc[iy + huedx * 3 - 4];
/* L335: */
	    }
/* L333: */
	}
/*  light - set lightness to 0.8 */
#ifndef NO_PROTO
	shadcc[4] = .8f;
#else /* NO_PROTO */
	shadcc[4] = (float).8;
#endif /* NO_PROTO */
/*  grayish - set saturation to 0.5 */
#ifndef NO_PROTO
	shadcc[8] = .5f;
#else /* NO_PROTO */
	shadcc[8] = (float).5;
#endif /* NO_PROTO */
/*  dark - set lightness to 0.3 */
#ifndef NO_PROTO
	shadcc[10] = .3f;
#else /* NO_PROTO */
	shadcc[10] = (float).3;
#endif /* NO_PROTO */
	sethue_(&globnu_1.wkid, &c__4, &maxfg, &c__4, shadcc, &numset, lscoli)
		;
/*  skip hue, if not all shown */
	if (numset < 4) {
	    goto L330;
	}
	didtst = TRUE_;
/* Writing concatenation */
	i__2[0] = 42, a__1[0] = "APPEARANCE OF INTERMEDIATE COLORS IN HLS: ";
	i__2[1] = 236, a__1[1] = prmint;
	i__2[2] = 7, a__1[2] = colist + (huedx - 1) * 7;
	s_cat(ch__2, a__1, i__2, &c__3, 285L);
	result = tsthue_(ch__2, &filmod, &numset, lscoli, 285L);
	if (result < 0) {
/*  have hit failure */
	    goto L340;
	}
L330:
	;
    }
L340:
    if (didtst) {
#ifndef NO_PROTO
	setmsg_("1 5 16 17 21 25 32 33", "The intermediate hues should appea"
		"r as described within the HLS color model.", 21L, 76L);
#else /* NO_PROTO */
	setmsg_("1 5 16 17 21 25 32 33", "The intermediate hues should appea\
r as described within the HLS color model.", 21L, 76L);
#endif /* NO_PROTO */
	if (result == -2) {
	    opcofl_();
	}
	L__1 = result > 0;
	ifpf_(&L__1);
    } else {
#ifndef NO_PROTO
	inmsg_("Realized intermediate colors not accurate enough for testing"
		" HLS color model.", 77L);
#else /* NO_PROTO */
	inmsg_("Realized intermediate colors not accurate enough for testing\
 HLS color model.", 77L);
#endif /* NO_PROTO */
    }
/*  end HLS */
L399:
/*  **** **** **** ****   CIE Color Model   **** **** **** **** */
/*  Make sure CIE model is available */
    if (! cmodel[1]) {
	inmsg_("CIE color model not available; skipping CIE tests.", 50L);
	goto L499;
    }
/*  CIE prompt for basic hues and neutrals: */
#ifndef NO_PROTO
    s_copy(ciepr1, "1-black, 2-blue, 3-gray, 4-green, 5-orange, 6-pink, 7-pu"
	    "rple, 8-red, 9-white, 10-yellow", 87L, 87L);
#else /* NO_PROTO */
    s_copy(ciepr1, "1-black, 2-blue, 3-gray, 4-green, 5-orange, 6-pink, 7-pu\
rple, 8-red, 9-white, 10-yellow", 87L, 87L);
#endif /* NO_PROTO */
    sethue_(&globnu_1.wkid, &c__2, &maxfg, &c__10, ciebas, &numset, lscoli);
    if (numset < 4) {
#ifndef NO_PROTO
	inmsg_("Realized basic colors not accurate enough for testing CIE co"
		"lor model.", 70L);
#else /* NO_PROTO */
	inmsg_("Realized basic colors not accurate enough for testing CIE co\
lor model.", 70L);
#endif /* NO_PROTO */
	goto L499;
    }
#ifndef NO_PROTO
    setmsg_("1 5 16 17 21 23 32 33", "The basic hues and neutral colors shou"
	    "ld appear as described within the CIE color model.", 21L, 88L);
#else /* NO_PROTO */
    setmsg_("1 5 16 17 21 23 32 33", "The basic hues and neutral colors shou\
ld appear as described within the CIE color model.", 21L, 88L);
#endif /* NO_PROTO */
/* Writing concatenation */
    i__2[0] = 35, a__1[0] = "APPEARANCE OF BASIC COLORS IN CIE: ";
    i__2[1] = 139, a__1[1] = prmbas;
    i__2[2] = 87, a__1[2] = ciepr1;
    s_cat(ch__3, a__1, i__2, &c__3, 261L);
    result = tsthue_(ch__3, &filmod, &numset, lscoli, 261L);
    if (result == -2) {
	opcofl_();
    }
    L__1 = result == 1;
    ifpf_(&L__1);
    if (sizpal > 0 && sizpal < 64) {
#ifndef NO_PROTO
	inmsg_("Number of available colors too low for reliable testing of i"
		"ntermediate CIE hues.", 81L);
#else /* NO_PROTO */
	inmsg_("Number of available colors too low for reliable testing of i\
ntermediate CIE hues.", 81L);
#endif /* NO_PROTO */
	goto L499;
    }
/*  CIE prompt for group 1 of mixed hues */
#ifndef NO_PROTO
    s_copy(ciepr2, "1-purplish blue, 2-greenish blue, 3-yellowish green, 4-g"
	    "reenish yellow, 5-orange yellow, 6-purplish red", 103L, 103L);
#else /* NO_PROTO */
    s_copy(ciepr2, "1-purplish blue, 2-greenish blue, 3-yellowish green, 4-g\
reenish yellow, 5-orange yellow, 6-purplish red", 103L, 103L);
#endif /* NO_PROTO */
/*  CIE prompt for group 2 of mixed hues */
#ifndef NO_PROTO
    s_copy(ciepr3, "1-bluish green, 2-yellow green, 3-reddish orange, 4-redd"
	    "ish purple, 5-yellowish pink, 6-purplish pink", 101L, 101L);
#else /* NO_PROTO */
    s_copy(ciepr3, "1-bluish green, 2-yellow green, 3-reddish orange, 4-redd\
ish purple, 5-yellowish pink, 6-purplish pink", 101L, 101L);
#endif /* NO_PROTO */
    didtst = FALSE_;
    sethue_(&globnu_1.wkid, &c__2, &maxfg, &c__6, ciegr1, &numset, lscoli);
/*  maybe skip group 1 */
    if (numset < 4) {
	goto L450;
    }
    didtst = TRUE_;
/* Writing concatenation */
    i__2[0] = 36, a__1[0] = "APPEARANCE OF COMPOUND HUES IN CIE: ";
    i__2[1] = 139, a__1[1] = prmbas;
    i__2[2] = 103, a__1[2] = ciepr2;
    s_cat(ch__4, a__1, i__2, &c__3, 278L);
    result = tsthue_(ch__4, &filmod, &numset, lscoli, 278L);
    if (result < 0) {
	goto L480;
    }
L450:
    sethue_(&globnu_1.wkid, &c__2, &maxfg, &c__6, ciegr2, &numset, lscoli);
/*  maybe skip group 2 */
    if (numset < 4) {
	goto L480;
    }
    didtst = TRUE_;
/* Writing concatenation */
    i__2[0] = 36, a__1[0] = "APPEARANCE OF COMPOUND HUES IN CIE: ";
    i__2[1] = 139, a__1[1] = prmbas;
    i__2[2] = 101, a__1[2] = ciepr3;
    s_cat(ch__5, a__1, i__2, &c__3, 276L);
    result = tsthue_(ch__5, &filmod, &numset, lscoli, 276L);
L480:
    if (didtst) {
#ifndef NO_PROTO
	setmsg_("1 5 16 17 21 23 32 33", "The compound hues should appear as"
		" described within the CIE color model.", 21L, 72L);
#else /* NO_PROTO */
	setmsg_("1 5 16 17 21 23 32 33", "The compound hues should appear as\
 described within the CIE color model.", 21L, 72L);
#endif /* NO_PROTO */
	if (result == -2) {
	    opcofl_();
	}
	L__1 = result > 0;
	ifpf_(&L__1);
    } else {
#ifndef NO_PROTO
	inmsg_("Realized compound hues not accurate enough for testing CIE c"
		"olor model.", 71L);
#else /* NO_PROTO */
	inmsg_("Realized compound hues not accurate enough for testing CIE c\
olor model.", 71L);
#endif /* NO_PROTO */
    }
/*  end CIE */
L499:
L666:
/*  wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

