/* fort/03/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__3 = 3;
static integer c__2 = 2;
static integer c__30 = 30;
static integer c__4 = 4;
static integer c__7 = 7;
static integer c__1 = 1;
static integer c__20 = 20;
static integer c__5 = 5;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.03/01                              * */
/*  *    TEST TITLE : Preservation of structure contents    * */
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
    static real xvals[4] = { 2.2f,3.3e22f,4.4e-33f,-5.5f };
    static real yvals[4] = { -1.2e-22f,-2.3e33f,-3.4f,0.f };
#else /* NO_PROTO */
    static real xvals[4] = { (float)2.2,(float)3.3e22,(float)4.4e-33,(float)
	    -5.5 };
    static real yvals[4] = { (float)-1.2e-22,(float)-2.3e33,(float)-3.4,(
	    float)0. };
#endif /* NO_PROTO */
    static integer nmvals[7] = { 2,3,5,8,13,63,0 };
    static integer eltab[4] = { 5,7,53,17 };
    static integer exisz[4] = { 1,0,7,2 };
    static integer exrsz[4] = { 8,2,0,6 };
    static integer exssz[4] = { 0,1,0,2 };

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    char ch__1[310];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi(), s_cmp();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static integer ix;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm (), ntx ();
#endif /* NO_PROTO */
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nads (integer *, integer *),
	     ngdp (integer *, real *, real *, integer *, integer *, char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nads (), ngdp ();
#endif /* NO_PROTO */
    static integer arnm, slen[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int ndst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndst ();
#endif /* NO_PROTO */
    static real xpos, ypos;
    static integer gdpid;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int nqeco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *, integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical appeq_();
    extern /* Subroutine */ int nqeco ();
#endif /* NO_PROTO */
    static logical conok;
#ifndef NO_PROTO
    extern logical rareq_(integer *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical rareq_();
#endif /* NO_PROTO */
    static integer acisz, icont[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nprec (integer *, integer *, integer *, real *
	    , integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, ftnlen, ftnlen);
    extern logical seteq_(integer *, integer *, integer *);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nprec ();
    extern logical seteq_();
    extern integer itrim_();
#endif /* NO_PROTO */
    static real rcont[20];
    static integer acrsz, acssz;
    static char scont[80*20], svals[80*2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), narst (integer *, integer *, 
	    integer *), nrest (integer *, integer *, integer *), nqets (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), inmsg_(char *, ftnlen), unmsg_(char *, ftnlen), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), narst (), nrest (), nqets (), 
	    inmsg_(), unmsg_(), nopst ();
#endif /* NO_PROTO */
    static char datrec[80*30];
    static integer ldract;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndasar (integer *), nclarf (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndasar (), nclarf ();
#endif /* NO_PROTO */
    static integer elemno;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real abstol;
    static integer drlens[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), avarnm_();
#endif /* NO_PROTO */
    static real reltol;
    static integer eltype;
#ifndef NO_PROTO
    extern /* Subroutine */ int noparf (integer *, integer *), setmsg_(char *,
	     char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int noparf (), setmsg_();
#endif /* NO_PROTO */
    static integer struid[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer numrls;

    /* Fortran I/O blocks */
    static icilist io___29 = { 0, msg, 0, "(A,I2,A)", 300, 1 };
    static icilist io___30 = { 0, msg, 0, "(A,I3,A,I2,A)", 300, 1 };
    static icilist io___31 = { 0, msg, 0, "(A,I2,A)", 300, 1 };
    static icilist io___36 = { 0, msg, 0, "(A,I2,A)", 300, 1 };


/* element type */
/*  set up parameters for name-set: */
/*  expected sizes */
/*  actual sizes */
/* expected element sizes: */
    initgl_("03.03/01", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  tolerance for floating-point equality */
#ifndef NO_PROTO
    reltol = 1e-5f;
    abstol = 0.f;
#else /* NO_PROTO */
    reltol = (float)1e-5;
    abstol = (float)0.;
#endif /* NO_PROTO */
/*  set up parameters for text: */
#ifndef NO_PROTO
    xpos = 9.8f;
    ypos = 7.6f;
#else /* NO_PROTO */
    xpos = (float)9.8;
    ypos = (float)7.6;
#endif /* NO_PROTO */
/*  set up additional parameters for GDP: */
    numrls = 3;
    gdpid = 33;
    s_copy(svals, "  string#1", 80L, 10L);
    s_copy(svals + 80, "and #2", 80L, 6L);
    drlens[0] = itrim_(svals, 80L);
    drlens[1] = itrim_(svals + 80, 80L);
    nprec (&c__3, nmvals, &c__2, yvals, &c__2, drlens, svals, &c__30, &errind,
	     &ldract, datrec, 80L, 80L);
    chkinq_("pprec", &errind, 5L);
    exssz[3] = ldract;
    struid[0] = 101;
/* set up structure */
    nopst (struid);
    npm (&c__4, xvals, yvals);
    ntx (&xpos, &ypos, "Text string.", 12L);
    nads (&c__7, nmvals);
    ngdp (&numrls, xvals, yvals, &gdpid, &ldract, datrec, 80L);
    nclst ();
    arid = 10;
    avarnm_(&arnm);
/* archive and retrieve it */
    noparf (&arid, &arnm);
    ndasar (&arid);
    narst (&arid, &c__1, struid);
    ndst (struid);
    nrest (&arid, &c__1, struid);
    nclarf (&arid);
#ifndef NO_PROTO
    setmsg_("1 4 9 12", "When a structure is archived and retrieved, all the"
	    " structure elements and all the parameter values therein should "
	    "be accurately restored.", 8L, 138L);
#else /* NO_PROTO */
    setmsg_("1 4 9 12", "When a structure is archived and retrieved, all the\
 structure elements and all the parameter values therein should be accuratel\
y restored.", 8L, 138L);
#endif /* NO_PROTO */
    conok = TRUE_;
    for (elemno = 1; elemno <= 4; ++elemno) {
	s_copy(msg, "OK", 300L, 2L);
/*        <inquire element type and size> with struid,elemno */
/*           to determine eltype, elsize */
	nqets (struid, &elemno, &errind, &eltype, &acisz, &acrsz, &acssz);
	if (errind == 201 || errind == 202) {
	    conok = FALSE_;
	    s_wsfi(&io___29);
	    do_fio(&c__1, "Element number ", 15L);
	    do_fio(&c__1, (char *)&elemno, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " reported as non-existent.", 26L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L300;
	}
	chkinq_("pqets", &errind, 5L);
	if (eltype != eltab[elemno - 1]) {
	    s_wsfi(&io___30);
	    do_fio(&c__1, "element type ", 13L);
	    do_fio(&c__1, (char *)&eltype, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " in position #", 14L);
	    do_fio(&c__1, (char *)&elemno, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    goto L150;
	}
	if (acisz == exisz[elemno - 1] && acrsz == exrsz[elemno - 1] && acssz 
		== exssz[elemno - 1]) {
/*           OK so far */
	} else {
	    s_wsfi(&io___31);
	    do_fio(&c__1, "element size from PQETS in position #", 37L);
	    do_fio(&c__1, (char *)&elemno, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    goto L150;
	}
	s_copy(scont, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 80L, 33L);
	s_copy(scont + 80, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 80L, 33L);
	nqeco (struid, &elemno, &c__20, &c__20, &c__20, &errind, &acisz, 
		icont, &acrsz, rcont, &acssz, slen, scont, 80L);
	chkinq_("pqeco", &errind, 5L);
	if (acisz == exisz[elemno - 1] && acrsz == exrsz[elemno - 1] && acssz 
		== exssz[elemno - 1]) {
/*           OK so far */
	} else {
	    s_wsfi(&io___36);
	    do_fio(&c__1, "element size from PQECO in position #", 37L);
	    do_fio(&c__1, (char *)&elemno, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    goto L190;
	}
#ifndef NO_PROTO
	switch (elemno) {
#else /* NO_PROTO */
	switch ((int)elemno) {
#endif /* NO_PROTO */
	    case 1:  goto L110;
	    case 2:  goto L120;
	    case 3:  goto L130;
	    case 4:  goto L140;
	}
	unmsg_("Element number out of expected range.", 37L);
/*  polymarker */
L110:
	if (icont[0] == 4 && rareq_(&c__4, rcont, xvals, &abstol, &reltol) && 
		rareq_(&c__4, &rcont[4], yvals, &abstol, &reltol)) {
/*           OK */
	} else {
	    s_copy(msg, "contents for polymarker.", 300L, 24L);
	}
	goto L190;
/*  text */
L120:
	if (appeq_(rcont, &xpos, &abstol, &reltol) && appeq_(&rcont[1], &ypos,
#ifndef NO_PROTO
		 &abstol, &reltol) && slen[0] == 12 && s_cmp(scont, "Text st"
		"ring.", 80L, 12L) == 0) {
#else /* NO_PROTO */
		 &abstol, &reltol) && slen[0] == 12 && s_cmp(scont, "Text st\
ring.", 80L, 12L) == 0) {
#endif /* NO_PROTO */
/*           OK */
	} else {
	    s_copy(msg, "contents for text.", 300L, 18L);
	}
	goto L190;
/*  add names to set */
L130:
	if (seteq_(&c__7, icont, nmvals)) {
/*           OK */
	} else {
	    s_copy(msg, "contents for add names to set.", 300L, 30L);
	}
	goto L190;
/*  generalized drawing primitive */
L140:
	if (icont[0] == numrls && icont[1] == gdpid && rareq_(&c__3, rcont, 
		xvals, &abstol, &reltol) && rareq_(&c__3, &rcont[3], yvals, &
		abstol, &reltol)) {
/*           OK so far */
	} else {
	    s_copy(msg, "numeric contents for generalized drawing primitive.",
		     300L, 51L);
	    goto L190;
	}
/*  check size and contents of data records in GDP */
	i__1 = acssz;
	for (ix = 1; ix <= i__1; ++ix) {
	    if (slen[ix - 1] != 80 || s_cmp(scont + (ix - 1) * 80, datrec + (
		    ix - 1) * 80, 80L, 80L) != 0) {
#ifndef NO_PROTO
		s_copy(msg, "data record contents for generalized drawing pr"
			"imitive.", 300L, 55L);
#else /* NO_PROTO */
		s_copy(msg, "data record contents for generalized drawing pr\
imitive.", 300L, 55L);
#endif /* NO_PROTO */
		goto L190;
	    }
/* L145: */
	}
	goto L190;
L190:
/*  skip_contents: */
L150:
	if (s_cmp(msg, "OK", 300L, 2L) == 0) {
/*           do nothing */
	} else {
	    conok = FALSE_;
/* Writing concatenation */
	    i__2[0] = 10, a__1[0] = "Incorrect ";
	    i__2[1] = 300, a__1[1] = msg;
	    s_cat(ch__1, a__1, i__2, &c__2, 310L);
	    inmsg_(ch__1, 310L);
	}
/* L100: */
    }
    nqets (struid, &c__5, &errind, &eltype, &acisz, &acrsz, &acssz);
    if (errind == 202) {
/*        OK - non-existent as expected */
    } else {
	conok = FALSE_;
	inmsg_("Extra element found at end of retrieved structure.", 50L);
    }
/*  end_tests: */
L300:
    ifpf_(&conok);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

