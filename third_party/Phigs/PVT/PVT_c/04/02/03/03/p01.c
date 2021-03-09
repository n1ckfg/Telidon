/* fort/04/02/03/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b33 = 1.f;
static real c_b34 = 0.f;
#else /* NO_PROTO */
static real c_b33 = (float)1.;
static real c_b34 = (float)0.;
#endif /* NO_PROTO */
static integer c__3 = 3;
static integer c__1 = 1;
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.03/01                        * */
/*  *    TEST TITLE : Text font in <inquire text extent>    * */
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
    integer i__1, i__2;
    real r__1, r__2, r__3;
    logical L__1;
    char ch__1[1];

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
    static integer cc;
    static real hw, vw, chh;
    static char msg[300], str[20];
    static integer txp;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static real schh, bwid;
    static integer prec;
    static real chsp, chxp, pwid, schw;
    static integer font;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static real wwid;
    static integer wkno, fntx;
    static char cdum1[1];
    static integer spec2, idum1, wkid2, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, rdum3, rdum4;
    static integer maxcc;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical appeq_();
#endif /* NO_PROTO */
    static integer igenx;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer ifont, txalh;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *), nqewk (integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk (), nqwkc (), nqewk ();
#endif /* NO_PROTO */
    static integer txalv;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk ();
#endif /* NO_PROTO */
    static integer wknum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *, real *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxf ();
#endif /* NO_PROTO */
    static integer conid2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxx (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, char *, integer *, real *
	    , real *, real *, real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx ();
#endif /* NO_PROTO */
    static integer wtype2;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real abstol, reltol;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt, numfnt, gentyp;
    static char result[1];
    static integer lavtyp;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), multws_(
	    integer *, char *, integer *, integer *, integer *, integer *, 
	    char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), multws_();
#endif /* NO_PROTO */
    static real txexrx[2], txexry[2];

    /* Fortran I/O blocks */
    static icilist io___39 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___40 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___48 = { 0, msg, 0, "(A,I6)", 300, 1 };
    static icilist io___52 = { 0, msg, 0, "(A,I6)", 300, 1 };


/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    initgl_("04.02.03.03/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  Establish specwt = specific primary workstation type */
    nqwkc (&globnu_1.wkid, &errind, &idum1, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  Throughout, use variable names: */
/*  font:  text font */
/*  chxp:  character expansion factor */
/*  chsp:  character spacing */
/*  chh:   character height */
/*  txp:   text path */
/*  txal:  text alignment */
/*  str:   character string */
/*  For approximate equality: */
/*  abstol = absolute tolerance = .02 */
/*  reltol = relative tolerance = .02 */
#ifndef NO_PROTO
    abstol = .02f;
    reltol = .02f;
#else /* NO_PROTO */
    abstol = (float).02;
    reltol = (float).02;
#endif /* NO_PROTO */
    font = 1;
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
    s_copy(str, "Text extent", 20L, 11L);
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 11L);
    chkinq_("pqtxx", &errind, 5L);
/*  schw = standard character width */
#ifndef NO_PROTO
    schw = (r__1 = txexrx[1] - txexrx[0], dabs(r__1)) / 11.f;
#else /* NO_PROTO */
    schw = (r__1 = txexrx[1] - txexrx[0], dabs(r__1)) / (float)11.;
#endif /* NO_PROTO */
/*  schh = standard character height */
    schh = (r__1 = txexry[1] - txexry[0], dabs(r__1));
#ifndef NO_PROTO
    setmsg_("1 3 4 10 15", "For a horizontal text path, the width of a chara"
	    "cter string in font 1 should be proportional to the number of ch"
	    "aracters it contains.", 11L, 133L);
#else /* NO_PROTO */
    setmsg_("1 3 4 10 15", "For a horizontal text path, the width of a chara\
cter string in font 1 should be proportional to the number of characters it \
contains.", 11L, 133L);
#endif /* NO_PROTO */
/*  <Inquire text extent> as before, but with: */
/*     str   = "WWWW" */
    s_copy(str, "WWWW", 20L, 4L);
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 4L);
    chkinq_("pqtxx", &errind, 5L);
    wwid = txexrx[1];
/*  <Inquire text extent> as before, but with: */
/*     str   = "...", txp = LEFT */
    txp = 1;
    s_copy(str, "...", 20L, 3L);
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 3L);
    chkinq_("pqtxx", &errind, 5L);
    pwid = txexrx[1];
/*  <Inquire text extent> as before, but with: */
/*     str   = "  " */
    s_copy(str, "  ", 20L, 2L);
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 2L);
    chkinq_("pqtxx", &errind, 5L);
    bwid = txexrx[1];
    r__1 = schw * 4;
    r__2 = schw * 3;
    r__3 = schw * 2;
    L__1 = appeq_(&wwid, &r__1, &abstol, &reltol) && appeq_(&pwid, &r__2, &
	    abstol, &reltol) && appeq_(&bwid, &r__3, &abstol, &reltol);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 3 4 10 16", "For a vertical text path, the width of a charact"
	    "er string in font 1 should always be the width of a single chara"
	    "cter.", 11L, 117L);
#else /* NO_PROTO */
    setmsg_("1 3 4 10 16", "For a vertical text path, the width of a charact\
er string in font 1 should always be the width of a single character.", 11L, 
	    117L);
#endif /* NO_PROTO */
    s_copy(str, "WWW", 20L, 3L);
    txp = 3;
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 3L);
    chkinq_("pqtxx", &errind, 5L);
    wwid = txexrx[1];
    s_copy(str, "....", 20L, 4L);
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 4L);
    chkinq_("pqtxx", &errind, 5L);
    pwid = txexrx[1];
    txp = 2;
    s_copy(str, "     ", 20L, 5L);
    nqtxx (&specwt, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
	    errind, txexrx, txexry, &rdum1, &rdum2, 5L);
    chkinq_("pqtxx", &errind, 5L);
    bwid = txexrx[1];
    L__1 = appeq_(&wwid, &schw, &abstol, &reltol) && appeq_(&pwid, &schw, &
	    abstol, &reltol) && appeq_(&bwid, &schw, &abstol, &reltol);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 13", "All fonts reportedly available in stroke precision shou"
	    "ld be valid for use with <inquire text extent>.", 4L, 102L);
    chxp = 1.f;
    chsp = 0.f;
    chh = 1.f;
#else /* NO_PROTO */
    setmsg_("1 13", "All fonts reportedly available in stroke precision shou\
ld be valid for use with <inquire text extent>.", 4L, 102L);
    chxp = (float)1.;
    chsp = (float)0.;
    chh = (float)1.;
#endif /* NO_PROTO */
    txp = 0;
    txalh = 1;
    txalv = 5;
    s_copy(str, "Text extent", 20L, 11L);
/*  Use <inquire text facilities> using specwt to determine */
/*     lstfnt = list of fonts available in STROKE precision */
    nqtxf (&specwt, &c__0, &errind, &numfnt, &idum1, &idum2, &idum3, &rdum1, &
	    rdum2, &idum4, &rdum3, &rdum4, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    i__1 = numfnt;
    for (ifont = 1; ifont <= i__1; ++ifont) {
	nqtxf (&specwt, &ifont, &errind, &idum1, &fntx, &prec, &idum3, &rdum1,
		 &rdum2, &idum4, &rdum3, &rdum4, &idum5);
	chkinq_("pqtxf", &errind, 5L);
	if (prec != 2) {
	    goto L100;
	}
	nqtxx (&specwt, &fntx, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, 
		&errind, txexrx, txexry, &rdum1, &rdum2, 11L);
	if (errind != 0) {
	    fail_();
	    goto L500;
	}
L100:
	;
    }
    pass_();
/* end valid fonts: */
L500:
#ifndef NO_PROTO
    setmsg_("1 2 3 9 10 15 16", "For any font, the nominal width of any rect"
	    "angle whose text path is vertical should equal the nominal width"
	    " of the widest character in the font.", 16L, 144L);
#else /* NO_PROTO */
    setmsg_("1 2 3 9 10 15 16", "For any font, the nominal width of any rect\
angle whose text path is vertical should equal the nominal width of the wide\
st character in the font.", 16L, 144L);
#endif /* NO_PROTO */
/*  maximum valid character code */
    maxcc = 255;
/*  for each stroke fntx in lstfnt */
    i__1 = numfnt;
    for (ifont = 1; ifont <= i__1; ++ifont) {
	nqtxf (&specwt, &ifont, &errind, &idum1, &fntx, &prec, &idum3, &rdum1,
		 &rdum2, &idum4, &rdum3, &rdum4, &idum5);
	chkinq_("pqtxf", &errind, 5L);
	if (prec != 2) {
	    goto L510;
	}
/*  determine vw = width of vertical rectangle */
	nqtxx (&specwt, &fntx, &c_b33, &c_b34, &c_b33, &c__3, &c__1, &c__5, 
		".", &errind, txexrx, txexry, &rdum1, &rdum2, 1L);
	if (errind != 0) {
	    goto L510;
	}
	vw = txexrx[1];
/*  all characters so far are narrower */
	*result = 'L';
/*  character code from 0 to maxcc */
	i__2 = maxcc;
	for (cc = 0; cc <= i__2; ++cc) {
/*  determine hw = width of horizontal rectangle */
	    ch__1[0] = cc;
	    nqtxx (&specwt, &fntx, &c_b33, &c_b34, &c_b33, &c__0, &c__1, &
		    c__5, ch__1, &errind, txexrx, txexry, &rdum1, &rdum2, 1L);

	    if (errind != 0) {
		goto L520;
	    }
	    hw = txexrx[1];
	    if (appeq_(&hw, &vw, &c_b34, &reltol)) {
/*  some character of equal width exists */
		*result = 'E';
	    } else if (hw > vw) {
		fail_();
		s_wsfi(&io___39);
#ifndef NO_PROTO
		do_fio(&c__1, "Horizontal character is too wide: failed on f"
			"ont = ", 51L);
#else /* NO_PROTO */
		do_fio(&c__1, "Horizontal character is too wide: failed on f\
ont = ", 51L);
#endif /* NO_PROTO */
		do_fio(&c__1, (char *)&fntx, (ftnlen)sizeof(integer));
		do_fio(&c__1, "; character code = ", 19L);
		do_fio(&c__1, (char *)&cc, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		inmsg_(msg, 300L);
		goto L550;
	    }
/*  next_char: */
L520:
	    ;
	}
	if (*result == 'L') {
	    fail_();
	    s_wsfi(&io___40);
#ifndef NO_PROTO
	    do_fio(&c__1, "All horizontal characters are too narrow: failed "
		    "on font = ", 59L);
#else /* NO_PROTO */
	    do_fio(&c__1, "All horizontal characters are too narrow: failed \
on font = ", 59L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&fntx, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L550;
	}
/*  next_font: */
L510:
	;
    }
    pass_();
/*  end_other_fonts: */
L550:
#ifndef NO_PROTO
    setmsg_("1 2 4 5 15 16", "Font 1 should generate character bodies of the"
	    " same height and width for all workstation types.", 13L, 95L);
#else /* NO_PROTO */
    setmsg_("1 2 4 5 15 16", "Font 1 should generate character bodies of the\
 same height and width for all workstation types.", 13L, 95L);
#endif /* NO_PROTO */
/* close primary workstation (because may not be able to open */
/*    several simultaneously) */
    nclwk (&globnu_1.wkid);
/*  test other specific types: */
/*  for each accessible secondary output workstation = wkid2 */
    multws_(&c__0, "od", &wkno, &idum1, &idum2, &idum3, cdum1, 2L, 1L);
    font = 1;
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
    s_copy(str, ".......", 20L, 7L);
    i__1 = wkno;
    for (wknum = 1; wknum <= i__1; ++wknum) {
	multws_(&wknum, "od", &idum1, &wkid2, &conid2, &wtype2, cdum1, 2L, 1L)
		;
	nopwk (&wkid2, &conid2, &wtype2);
	nqwkc (&wkid2, &errind, &idum1, &spec2);
	chkinq_("pqwkc", &errind, 5L);
	nqtxx (&spec2, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, &
		errind, txexrx, txexry, &rdum1, &rdum2, 7L);
	nclwk (&wkid2);
	r__1 = schw * 7;
	if (errind != 0 || ! appeq_(&txexrx[1], &r__1, &abstol, &reltol) || ! 
		appeq_(&txexry[1], &schh, &abstol, &reltol)) {
	    fail_();
	    s_wsfi(&io___48);
	    do_fio(&c__1, "Failure on specific workstation type #", 38L);
	    do_fio(&c__1, (char *)&spec2, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
/*  next wkid2 */
/* L600: */
    }
/*  test generic types: */
/*  <inquire list of available workstation types> */
/*     to determine lavtyp = list of generic workstation types */
    nqewk (&c__0, &errind, &lavtyp, &idum1);
    chkinq_("pqewk", &errind, 5L);
    s_copy(str, "WWWWW", 20L, 5L);
    txp = 2;
/*  for each gentyp in lavtyp: */
    i__1 = lavtyp;
    for (igenx = 1; igenx <= i__1; ++igenx) {
	nqewk (&igenx, &errind, &idum1, &gentyp);
	chkinq_("pqewk", &errind, 5L);
	nqtxx (&gentyp, &font, &chxp, &chsp, &chh, &txp, &txalh, &txalv, str, 
		&errind, txexrx, txexry, &rdum1, &rdum2, 5L);
	if (errind == 51) {
	    goto L200;
	}
	r__1 = schh * 5;
	if (errind != 0 || ! appeq_(&txexrx[1], &schw, &abstol, &reltol) || ! 
		appeq_(&txexry[1], &r__1, &abstol, &reltol)) {
	    fail_();
	    s_wsfi(&io___52);
	    do_fio(&c__1, "Failure on generic workstation type #", 37L);
	    do_fio(&c__1, (char *)&gentyp, (ftnlen)sizeof(integer));
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L666;
	}
L200:
	;
    }
    pass_();
/*  end_other_types: */
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

