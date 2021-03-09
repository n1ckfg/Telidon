/* fort/11/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 11.02/03                              * */
/*  *    TEST TITLE : Normalize prototypes and typedefs     * */
/*  *                 in phigs.h                            * */
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
    static char chtok[1*9] = "[" "]" "{" "}" "(" ")" ";" "," "*";
#else /* NO_PROTO */
    static char chtok[1*9+1] = "[]{}();,*";
#endif /* NO_PROTO */

    /* Format strings */
    static char fmt_801[] = "(a)";

    /* System generated locals */
    address a__1[2], a__2[3];
    integer i__1, i__2[2], i__3, i__4[3];
    char ch__1[340], ch__2[352], ch__3[1], ch__4[349];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer f_open(olist *), s_wsfi(icilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfi(void), f_rew(alist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen), s_cmp(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer f_open(), s_wsfi(), do_fio(), e_wsfi(), f_rew();
    /* Subroutine */ int s_copy();
    integer i_indx(), s_cmp();
    /* Subroutine */ int s_cat();
    integer s_rsfe(), e_rsfe(), s_wsfe(), e_wsfe(), f_clos();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_rsfe(cilist *), e_rsfe(void), s_wsfe(cilist *), e_wsfe(void), 
	    f_clos(cllist *);

#endif /* not NO_PROTO */
    /* Local variables */
    static integer c1, c2, c3, cc, ix, iy, nnb;
    static char msg[300];
    static integer uin, uout;
    static char endch[1], chbuf[10000], inrec[500], inbuf[10000];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer ioerr;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
    extern integer leadnb_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
    extern integer leadnb_();
#endif /* NO_PROTO */
    static integer blevel, buflen;
    static char thisch[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static char rstrec[500];
#ifndef NO_PROTO
    extern /* Subroutine */ int windup_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int windup_();
#endif /* NO_PROTO */
    static integer nxtpos;

    /* Fortran I/O blocks */
    static icilist io___6 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static icilist io___7 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static icilist io___8 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static icilist io___9 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static cilist io___20 = { 1, 0, 1, fmt_801, 0 };
    static icilist io___21 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static cilist io___28 = { 0, 0, 0, fmt_801, 0 };


/*  NG must be greater than the length of INBUF to signify not-found */
/* L801: */
    initgl_("11.02/03", 8L);
#ifndef NO_PROTO
    inmsg_("This program does not perform any test cases, but merely normali"
	    "zes the contents of phigs.hp as phigs.hpn for later comparison.", 
	    127L);
#else /* NO_PROTO */
    inmsg_("This program does not perform any test cases, but merely normali\
zes the contents of phigs.hp as phigs.hpn for later comparison.", 127L);
#endif /* NO_PROTO */
/* Computing MAX */
    i__1 = max(20,globnu_1.indlun);
    uin = max(i__1,globnu_1.glblun) + 1;
    uout = uin + 1;
/*  open output file */
    o__1.oerr = 1;
    o__1.ounit = uout;
    o__1.ofnmlen = 9;
    o__1.ofnm = "phigs.hpn";
    o__1.orl = 9000;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsfi(&io___6);
	do_fio(&c__1, "Error code opening output file phigs.hpn = ", 43L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
    al__1.aerr = 1;
    al__1.aunit = uout;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsfi(&io___7);
	do_fio(&c__1, "Error code rewinding output file phigs.hpn = ", 45L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  open input file */
    o__1.oerr = 1;
    o__1.ounit = uin;
    o__1.ofnmlen = 8;
    o__1.ofnm = "phigs.hp";
    o__1.orl = 2000;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsfi(&io___8);
	do_fio(&c__1, "Error code opening input file phigs.hp = ", 41L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
#ifndef NO_PROTO
	do_fio(&c__1, ".  Create phigs.hp as pre-processed version of phigs."
		"h and re-execute.", 70L);
#else /* NO_PROTO */
	do_fio(&c__1, ".  Create phigs.hp as pre-processed version of phigs.\
h and re-execute.", 70L);
#endif /* NO_PROTO */
	e_wsfi();
	unmsg_(msg, 300L);
    }
    al__1.aerr = 1;
    al__1.aunit = uin;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsfi(&io___9);
	do_fio(&c__1, "Error code rewinding input file phigs.hp = ", 43L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  record as read in from input file */
    s_copy(inrec, " ", 500L, 1L);
/*  the part of inbuf beyond the first statement */
    s_copy(rstrec, " ", 500L, 1L);
/*  try to get next statement in inbuf */
L100:
    s_copy(inbuf, rstrec, 10000L, 500L);
/*  search inbuf for zero-level semi-colon */
    blevel = 0;
    nxtpos = 1;
L110:
    c1 = i_indx(inbuf + (nxtpos - 1), "{", 10000 - (nxtpos - 1), 1L);
    if (c1 == 0) {
	c1 = 99999;
    }
    c2 = i_indx(inbuf + (nxtpos - 1), "}", 10000 - (nxtpos - 1), 1L);
    if (c2 == 0) {
	c2 = 99999;
    }
    if (blevel == 0) {
	c3 = i_indx(inbuf + (nxtpos - 1), ";", 10000 - (nxtpos - 1), 1L);
	if (c3 == 0) {
	    c3 = 99999;
	}
    } else {
	c3 = 99999;
    }
/* Computing MIN */
    i__1 = min(c1,c2);
    cc = min(i__1,c3);
    if (cc >= 99999) {
	goto L200;
    }
/*  get absolute position of next interesting character */
    cc = cc + nxtpos - 1;
/*  where to start next search */
    nxtpos = cc + 1;
    s_copy(thisch, inbuf + (cc - 1), 2L, 1L);
    if (s_cmp(thisch, "{", 2L, 1L) == 0) {
	++blevel;
	goto L110;
    } else if (s_cmp(thisch, "}", 2L, 1L) == 0) {
	--blevel;
	goto L110;
    } else if (s_cmp(thisch, ";", 2L, 1L) == 0) {
	goto L300;
    } else {
/* Writing concatenation */
	i__2[0] = 40, a__1[0] = "Logic error searching for delimiter in: ";
	i__2[1] = 300, a__1[1] = inbuf;
	s_cat(ch__1, a__1, i__2, &c__2, 340L);
	unmsg_(ch__1, 340L);
    }
/*  not found - need more records in inbuf */
L200:
    io___20.ciunit = uin;
    ioerr = s_rsfe(&io___20);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = do_fio(&c__1, inrec, 500L);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = e_rsfe();
L100001:
    if (ioerr < 0) {
	goto L601;
    }
    if (ioerr == 0) {
/*  skip any records left with leading "#" or blanks */
	if (*inrec == '#' || s_cmp(inrec, " ", 500L, 1L) == 0) {
	    goto L200;
	}
/*  append INREC to INBUF */
	nxtpos = itrim_(inbuf, 10000L);
	if (inbuf[nxtpos - 1] != '\\') {
/*  not C-continuation */
	    nxtpos += 2;
	}
	s_copy(inbuf + (nxtpos - 1), inrec, 10000 - (nxtpos - 1), 500L);
	goto L110;
    } else {
	s_wsfi(&io___21);
	do_fio(&c__1, "Error #", 7L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, " occurred reading phigs.hp.", 27L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
L601:
    if (s_cmp(inbuf, " ", 10000L, 1L) != 0) {
/* Writing concatenation */
#ifndef NO_PROTO
	i__2[0] = 52, a__1[0] = "Hit end-of-file in phigs.hp with partial st"
		"atement: ";
#else /* NO_PROTO */
	i__2[0] = 52, a__1[0] = "Hit end-of-file in phigs.hp with partial st\
atement: ";
#endif /* NO_PROTO */
	i__2[1] = 300, a__1[1] = inbuf;
	s_cat(ch__2, a__1, i__2, &c__2, 352L);
	unmsg_(ch__2, 352L);
    }
    goto L666;
/*  found zero-level semi-colon */
L300:
/*  put rest of record in rstrec */
    i__1 = cc;
    s_copy(rstrec, inbuf + i__1, 500L, 10000 - i__1);
    i__1 = cc;
    s_copy(inbuf + i__1, " ", 10000 - i__1, 1L);
/*  INBUF now has full statement */
/* USERMOD  convert HT,LF,VT,FF,CR to space */
/*  convert all white space to spaces - we'll take */
/*  these to be ASCII 9-13 ... */
    for (cc = 9; cc <= 13; ++cc) {
L315:
	ch__3[0] = cc;
	nxtpos = i_indx(inbuf, ch__3, 10000L, 1L);
	if (nxtpos != 0) {
	    inbuf[nxtpos - 1] = ' ';
	    goto L315;
	}
/* L310: */
    }
/*  keep this statement? */
    cc = leadnb_(inbuf, 10000L);
    if (s_cmp(inbuf + (cc - 1), "typedef ", 8L, 8L) == 0 || s_cmp(inbuf + (cc 
	    - 1), "extern ", 7L, 7L) == 0) {
/*        keep it */
    } else {
/*        toss it */
	goto L100;
    }
/*  delete all extra spaces */
    nxtpos = 1;
L320:
/*  next non-blank */
    nnb = leadnb_(inbuf + (nxtpos - 1), 10000 - (nxtpos - 1));
    if (nnb <= 0) {
	goto L350;
    }
/*  compress only if extra spaces found */
    if (nnb > 1) {
	i__1 = nxtpos + nnb - 2;
	s_copy(chbuf, inbuf + i__1, 10000L, 10000 - i__1);
	s_copy(inbuf + (nxtpos - 1), chbuf, 10000 - (nxtpos - 1), 10000L);
    }
/*  where is next blank? */
    cc = i_indx(inbuf + (nxtpos - 1), " ", 10000 - (nxtpos - 1), 1L);
/*  position one beyond next blank - next receiving position */
    nxtpos += cc;
    goto L320;
L350:
/*  delete spaces adjacent to character-tokens: []{}();,* */
    buflen = itrim_(inbuf, 10000L);
    for (ix = 1; ix <= 9; ++ix) {
	for (iy = 0; iy <= 1; ++iy) {
	    if (iy == 0) {
/* Writing concatenation */
		i__2[0] = 1, a__1[0] = " ";
		i__2[1] = 1, a__1[1] = chtok + (ix - 1);
		s_cat(thisch, a__1, i__2, &c__2, 2L);
	    } else {
/* Writing concatenation */
		i__2[0] = 1, a__1[0] = chtok + (ix - 1);
		i__2[1] = 1, a__1[1] = " ";
		s_cat(thisch, a__1, i__2, &c__2, 2L);
	    }
L355:
	    cc = i_indx(inbuf, thisch, 10000L, 2L);
	    if (cc <= 0 || cc >= buflen) {
		goto L345;
	    }
	    i__1 = cc + iy - 1;
	    i__3 = cc + iy;
	    s_copy(inbuf + i__1, inbuf + i__3, 10000 - i__1, 10000 - i__3);
	    --buflen;
	    goto L355;
L345:
	    ;
	}
/* L340: */
    }
/*  INBUF now normalized */
    buflen = itrim_(inbuf, 10000L);
/*  if typedef, swing type name up to front */
    if (s_cmp(inbuf, "typedef", 7L, 7L) != 0) {
	goto L400;
    }
/*  search backwards for "}", "*" or " " */
    for (ix = buflen; ix >= 1; --ix) {
	*endch = inbuf[ix - 1];
	if (*endch == '}' || *endch == '*' || *endch == ' ') {
	    goto L380;
	}
/* L370: */
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 49, a__1[0] = "Could not find last \"}\", \"*\", or \" \" in t"
	    "ypedef: ";
#else /* NO_PROTO */
    i__2[0] = 49, a__1[0] = "Could not find last \"}\", \"*\", or \" \" in t\
ypedef: ";
#endif /* NO_PROTO */
    i__2[1] = 300, a__1[1] = inbuf;
    s_cat(ch__4, a__1, i__2, &c__2, 349L);
    unmsg_(ch__4, 349L);
L380:
    i__1 = ix;
/* Writing concatenation */
    i__4[0] = buflen - 1 - i__1, a__2[0] = inbuf + i__1;
    i__4[1] = 1, a__2[1] = " ";
    i__4[2] = buflen, a__2[2] = inbuf;
    s_cat(chbuf, a__2, i__4, &c__3, 10000L);
    buflen = buflen + buflen - ix;
    s_copy(inbuf, chbuf, 10000L, 10000L);
L400:
    io___28.ciunit = uout;
    s_wsfe(&io___28);
    do_fio(&c__1, inbuf, buflen);
    e_wsfe();
    goto L100;
L666:
    cl__1.cerr = 0;
    cl__1.cunit = uout;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = uin;
    cl__1.csta = 0;
    f_clos(&cl__1);
    windup_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

