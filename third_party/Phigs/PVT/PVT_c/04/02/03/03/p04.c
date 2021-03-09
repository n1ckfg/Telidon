/* fort/04/02/03/03/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__0 = 0;
static integer c__7 = 7;
static integer c__4 = 4;
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.03/04                        * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static char vnmtab[7*6] = "NORMAL " "TOP    " "CAP    " "HALF   " "BASE "
	    "  " "BOTTOM ";
    static char hnmtab[7*4] = "NORMAL " "LEFT   " "CENTRE " "RIGHT  ";
    static char txptab[7*4] = "RIGHT  " "LEFT   " "UP     " "DOWN   ";
#else /* NO_PROTO */
    static char vnmtab[7*6+1] = "NORMAL TOP    CAP    HALF   BASE   BOTTOM ";
    static char hnmtab[7*4+1] = "NORMAL LEFT   CENTRE RIGHT  ";
    static char txptab[7*4+1] = "RIGHT  LEFT   UP     DOWN   ";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[7], a__2[4], a__3[5];
    integer i__1[7], i__2[4], i__3[5];
    real r__1, r__2;
    logical L__1;
    char ch__1[460], ch__2[496], ch__3[521], ch__4[471], ch__5[506];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static real chh, cpx, cpy;
    static char str[20];
    static integer txp;
    static char hbuf[7];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static real chsp, nomh, chxp, vloc[3];
    static char vbuf[7];
    static integer font;
    static real nomw;
    static integer idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical appeq_();
#endif /* NO_PROTO */
    static integer txalh, htxal;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static real frhix, frhiy;
    static char txbuf[7];
    static real frlox, frloy;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkc ();
#endif /* NO_PROTO */
    static integer txalv, vtxal;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    unmsg_(char *, ftnlen), nqtxx (integer *, integer *, real *, real 
	    *, real *, integer *, integer *, integer *, char *, integer *, 
	    real *, real *, real *, real *, ftnlen), chkinq_(char *, integer *
	    , ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), unmsg_(), nqtxx (), chkinq_();
#endif /* NO_PROTO */
    static integer ahtxal;
    static real rechix;
    static integer errind, nhoral, nveral, avtxal;
    static real horlim[6]	/* was [3][2] */;
    static integer specwt;
    static real verlim[10]	/* was [5][2] */, vertab[6], abstol, reltol, 
	    nomcpx, nomcpy, reclox, recloy, rechiy;
    static integer wktype;
    static real expcpx, expcpy;
    static char conmsg[400], vermsg[400];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), xpopph_(integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), xpopph_(), setmsg_();
#endif /* NO_PROTO */
    static real txexrx[2], txexry[2];

/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    initgl_("04.02.03.03/04", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  Establish specwt = specific primary workstation type */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &idum1, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  set up for basic vertical tests */
#ifndef NO_PROTO
    chxp = 1.3f;
    chsp = .4f;
    chh = 3.4f;
#else /* NO_PROTO */
    chxp = (float)1.3;
    chsp = (float).4;
    chh = (float)3.4;
#endif /* NO_PROTO */
    for (txalv = 2; txalv <= 4; ++txalv) {
	nqtxx (&specwt, &c__2, &chxp, &chsp, &chh, &c__0, &c__2, &txalv, 
		"NIST", &errind, txexrx, txexry, &cpx, &cpy, 4L);
	chkinq_("pqtxx", &errind, 5L);
	vloc[txalv - 2] = txexry[0];
/* L50: */
    }
/*  For approximate equality: */
#ifndef NO_PROTO
    abstol = chh * .02f;
    reltol = .02f;
    setmsg_("8 11", "Character height should set the distance between the CA"
	    "P and BASE lines of a capital letter.", 4L, 92L);
#else /* NO_PROTO */
    abstol = chh * (float).02;
    reltol = (float).02;
    setmsg_("8 11", "Character height should set the distance between the CA\
P and BASE lines of a capital letter.", 4L, 92L);
#endif /* NO_PROTO */
    r__1 = vloc[2] - vloc[0];
    L__1 = appeq_(&r__1, &chh, &abstol, &reltol);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("11", "Text alignment for HALF should be approximately halfway b"
	    "etween CAP and BASE.", 2L, 77L);
    L__1 = vloc[2] * .7f + vloc[0] * .3f > vloc[1] && vloc[2] * .3f + vloc[0] 
	    * .7f < vloc[1];
#else /* NO_PROTO */
    setmsg_("11", "Text alignment for HALF should be approximately halfway b\
etween CAP and BASE.", 2L, 77L);
    L__1 = vloc[2] * (float).7 + vloc[0] * (float).3 > vloc[1] && vloc[2] * (
	    float).3 + vloc[0] * (float).7 < vloc[1];
#endif /* NO_PROTO */
    ifpf_(&L__1);
/*  default character height */
#ifndef NO_PROTO
    chh = 4.4f;
#else /* NO_PROTO */
    chh = (float)4.4;
#endif /* NO_PROTO */
/*  For approximate equality: */
#ifndef NO_PROTO
    abstol = chh * .02f;
    reltol = .02f;
#else /* NO_PROTO */
    abstol = chh * (float).02;
    reltol = (float).02;
#endif /* NO_PROTO */
/*  Set horizontal and vertical limits for reasonable fraction of */
/*  text rectangle indicated by text alignment: */
#ifndef NO_PROTO
    horlim[0] = -.01f;
    horlim[3] = .01f;
    horlim[1] = .49f;
    horlim[4] = .51f;
    horlim[2] = .99f;
    horlim[5] = 1.01f;
    verlim[0] = .99f;
    verlim[5] = 1.01f;
    verlim[1] = .6f;
    verlim[6] = 1.01f;
    verlim[2] = .2f;
    verlim[7] = .8f;
    verlim[3] = .01f;
    verlim[8] = .4f;
    verlim[4] = -.01f;
    verlim[9] = .01f;
#else /* NO_PROTO */
    horlim[0] = (float)-.01;
    horlim[3] = (float).01;
    horlim[1] = (float).49;
    horlim[4] = (float).51;
    horlim[2] = (float).99;
    horlim[5] = (float)1.01;
    verlim[0] = (float).99;
    verlim[5] = (float)1.01;
    verlim[1] = (float).6;
    verlim[6] = (float)1.01;
    verlim[2] = (float).2;
    verlim[7] = (float).8;
    verlim[3] = (float).01;
    verlim[8] = (float).4;
    verlim[4] = (float)-.01;
    verlim[9] = (float).01;
#endif /* NO_PROTO */
    for (txp = 0; txp <= 3; ++txp) {
/*     <inquire text extent> with: */
	wktype = specwt;
/*  font = 2 (ASCII font) */
	font = 2;
#ifndef NO_PROTO
	chxp = -.33f;
	chsp = -.1f;
#else /* NO_PROTO */
	chxp = (float)-.33;
	chsp = (float)-.1;
#endif /* NO_PROTO */
	txalh = 1;
	txalv = 5;
	s_copy(str, "W.j ", 20L, 4L);
/* get nominal concatenation point offset */
	nqtxx (&wktype, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, 
		&errind, txexrx, txexry, &nomcpx, &nomcpy, 4L);
	chkinq_("pqtxx", &errind, 5L);
/* get nominal width and height */
	nomw = (r__1 = txexrx[1] - txexrx[0], dabs(r__1));
	nomh = (r__1 = txexry[1] - txexry[0], dabs(r__1));
/*     calculate NORMAL alignment, based on this txp: */
	if (txp == 0) {
	    nhoral = 1;
	    nveral = 4;
	} else if (txp == 1) {
	    nhoral = 3;
	    nveral = 4;
	} else if (txp == 2) {
	    nhoral = 2;
	    nveral = 4;
	} else if (txp == 3) {
	    nhoral = 2;
	    nveral = 1;
	} else {
	    unmsg_("Illegal text path.", 18L);
	}
	for (htxal = 0; htxal <= 3; ++htxal) {
/*        calculate actual horizontal alignment: */
	    if (htxal == 0) {
		ahtxal = nhoral;
	    } else {
		ahtxal = htxal;
	    }
	    for (vtxal = 0; vtxal <= 5; ++vtxal) {
/*           calculate actual vertical alignment: */
		if (vtxal == 0) {
		    avtxal = nveral;
		} else {
		    avtxal = vtxal;
		}
		s_copy(txbuf, txptab + txp * 7, 7L, 7L);
		s_copy(hbuf, hnmtab + htxal * 7, 7L, 7L);
		s_copy(vbuf, vnmtab + vtxal * 7, 7L, 7L);
/* Writing concatenation */
		i__1[0] = 18, a__1[0] = "When text path is ";
		i__1[1] = itrim_(txbuf, 7L), a__1[1] = txbuf;
		i__1[2] = 24, a__1[2] = " and text alignment is (";
		i__1[3] = itrim_(hbuf, 7L), a__1[3] = hbuf;
		i__1[4] = 1, a__1[4] = ",";
		i__1[5] = itrim_(vbuf, 7L), a__1[5] = vbuf;
		i__1[6] = 2, a__1[6] = ") ";
		s_cat(conmsg, a__1, i__1, &c__7, 400L);
/*           <inquire text extent> with wktype, font, chxp, ch
sp, */
/*                 chh, txp, str unchanged, but */
		txalh = htxal;
		txalv = vtxal;
		nqtxx (&wktype, &font, &chxp, &chsp, &chh, &txp, &txalh, &
			txalv, str, &errind, txexrx, txexry, &cpx, &cpy, 4L);
		chkinq_("pqtxx", &errind, 5L);
		reclox = txexrx[0];
		rechix = txexrx[1];
		recloy = txexry[0];
		rechiy = txexry[1];
/* Writing concatenation */
		i__2[0] = itrim_(conmsg, 400L), a__2[0] = conmsg;
		i__2[1] = 10, a__2[1] = " the size ";
		i__2[2] = 36, a__2[2] = "of the text extent rectangle should "
			;
		i__2[3] = 14, a__2[3] = "be unaffected.";
		s_cat(ch__1, a__2, i__2, &c__4, 460L);
		setmsg_("2 10 11 12 13 15 16", ch__1, 19L, itrim_(conmsg, 
			400L) + 60);
		r__1 = rechix - reclox;
		r__2 = rechiy - recloy;
		L__1 = appeq_(&r__1, &nomw, &abstol, &reltol) && appeq_(&r__2,
			 &nomh, &abstol, &reltol);
		ifpf_(&L__1);
/* Writing concatenation */
		i__3[0] = itrim_(conmsg, 400L), a__3[0] = conmsg;
		i__3[1] = 5, a__3[1] = " the ";
#ifndef NO_PROTO
		i__3[2] = 38, a__3[2] = "location of the text extent rectang"
			"le ";
		i__3[3] = 38, a__3[3] = "should be shifted as indicated by t"
			"he ";
#else /* NO_PROTO */
		i__3[2] = 38, a__3[2] = "location of the text extent rectang\
le ";
		i__3[3] = 38, a__3[3] = "should be shifted as indicated by t\
he ";
#endif /* NO_PROTO */
		i__3[4] = 15, a__3[4] = "text alignment.";
		s_cat(ch__2, a__3, i__3, &c__5, 496L);
		setmsg_("2 10 11 12 13 15 16", ch__2, 19L, itrim_(conmsg, 
			400L) + 96);
/*           calculate low, high fraction of rectangle: */
		frlox = -(doublereal)reclox / nomw;
		frhix = 1 - rechix / nomw;
		frloy = -(doublereal)recloy / nomh;
		frhiy = 1 - rechiy / nomh;

/*           pass/fail depending on */
		L__1 = horlim[ahtxal - 1] <= frlox && horlim[ahtxal + 2] >= 
			frlox && horlim[ahtxal - 1] <= frhix && horlim[ahtxal 
			+ 2] >= frhix && verlim[avtxal - 1] <= frloy && 
			verlim[avtxal + 4] >= frloy && verlim[avtxal - 1] <= 
			frhiy && verlim[avtxal + 4] >= frhiy;
		ifpf_(&L__1);

		if (txp == 1 || txp == 0) {
		    expcpx = nomcpx + reclox;
#ifndef NO_PROTO
		    expcpy = 0.f;
#else /* NO_PROTO */
		    expcpy = (float)0.;
#endif /* NO_PROTO */
		} else {
#ifndef NO_PROTO
		    expcpx = 0.f;
#else /* NO_PROTO */
		    expcpx = (float)0.;
#endif /* NO_PROTO */
		    expcpy = nomcpy + recloy;
		}
/* Writing concatenation */
		i__3[0] = itrim_(conmsg, 400L), a__3[0] = conmsg;
		i__3[1] = 5, a__3[1] = " the ";
#ifndef NO_PROTO
		i__3[2] = 38, a__3[2] = "concatenation point should be shift"
			"ed ";
		i__3[3] = 37, a__3[3] = "along the text path dimension by th"
			"e ";
		i__3[4] = 41, a__3[4] = "same amount as the text extent rect"
			"angle.";
#else /* NO_PROTO */
		i__3[2] = 38, a__3[2] = "concatenation point should be shift\
ed ";
		i__3[3] = 37, a__3[3] = "along the text path dimension by th\
e ";
		i__3[4] = 41, a__3[4] = "same amount as the text extent rect\
angle.";
#endif /* NO_PROTO */
		s_cat(ch__3, a__3, i__3, &c__5, 521L);
		setmsg_("10 11 12 13 17 18", ch__3, 17L, itrim_(conmsg, 400L) 
			+ 121);
/*           pass/fail depending on */
		L__1 = appeq_(&cpx, &expcpx, &abstol, &reltol) && appeq_(&cpy,
			 &expcpy, &abstol, &reltol);
		ifpf_(&L__1);
/*           save vertical displacements: */
		vertab[vtxal] = recloy;
/*           next vtxal */
/* L300: */
	    }
/* Writing concatenation */
	    i__3[0] = 18, a__3[0] = "When text path is ";
	    i__3[1] = itrim_(txbuf, 7L), a__3[1] = txbuf;
	    i__3[2] = 34, a__3[2] = " and horizontal text alignment is ";
	    i__3[3] = itrim_(hbuf, 7L), a__3[3] = hbuf;
	    i__3[4] = 1, a__3[4] = ",";
	    s_cat(vermsg, a__3, i__3, &c__5, 400L);
	    s_copy(vbuf, vnmtab + nveral * 7, 7L, 7L);
/* Writing concatenation */
	    i__3[0] = itrim_(vermsg, 400L), a__3[0] = vermsg;
	    i__3[1] = 39, a__3[1] = " then NORMAL vertical alignment should ";

	    i__3[2] = 24, a__3[2] = "have the same effect as ";
	    i__3[3] = itrim_(vbuf, 7L), a__3[3] = vbuf;
	    i__3[4] = 1, a__3[4] = ".";
	    s_cat(ch__4, a__3, i__3, &c__5, 471L);
	    setmsg_("10 11 12 13 16", ch__4, 14L, itrim_(vermsg, 400L) + 63 + 
		    itrim_(vbuf, 7L) + 1);
	    L__1 = appeq_(vertab, &vertab[nveral], &abstol, &reltol);
	    ifpf_(&L__1);
/* Writing concatenation */
	    i__2[0] = itrim_(vermsg, 400L), a__2[0] = vermsg;
	    i__2[1] = 36, a__2[1] = " then vertical alignments TOP, CAP, ";
	    i__2[2] = 36, a__2[2] = "HALF, BASE, and BOTTOM should cause ";
	    i__2[3] = 34, a__2[3] = "increasing vertical displacements.";
	    s_cat(ch__5, a__2, i__2, &c__4, 506L);
	    setmsg_("10 11 13 16", ch__5, 11L, itrim_(vermsg, 400L) + 106);
	    L__1 = vertab[1] <= vertab[2] && vertab[2] < vertab[3] && vertab[
		    3] < vertab[4] && vertab[4] < vertab[5];
	    ifpf_(&L__1);
/*        next htxal */
/* L200: */
	}
/*     next txp */
/* L100: */
    }
/* L666: */
/* close PHIGS and workstation */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

