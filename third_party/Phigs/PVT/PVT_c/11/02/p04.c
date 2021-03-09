/* fort/11/02/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 11.02/04                              * */
/*  *    TEST TITLE : Check prototypes and typedefs in      * */
/*  *                 phigs.h                               * */
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
    /* Format strings */
    static char fmt_801[] = "(a)";

    /* System generated locals */
    address a__1[3], a__2[2];
    integer i__1, i__2[3], i__3[2];
    logical L__1;
    char ch__1[6059], ch__2[6037];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer f_open(olist *), s_wsfi(icilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfi(void), f_rew(alist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfe(cilist *), e_rsfe(void), s_cmp(char *, char *, ftnlen, 
	    ftnlen), i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer f_open(), s_wsfi(), do_fio(), e_wsfi(), f_rew();
    /* Subroutine */ int s_copy();
    integer s_rsfe(), e_rsfe(), s_cmp(), i_indx();
    /* Subroutine */ int s_cat();
    integer i_len(), f_clos();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer i_len(char *, ftnlen), f_clos(cllist *);

#endif /* not NO_PROTO */
    /* Local variables */
    static char msg[300];
    static integer key1;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer uref;
    static char srid[4];
    static integer ufut;
    static char chbuf[6000];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer ioerr;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer arbloc;
    static char refrec[6000];
    static integer reflen, cmplen, futloc;
    static char futarb[6000], futrec[6000];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), windup_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), windup_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___5 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static icilist io___6 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static icilist io___7 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static icilist io___8 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static cilist io___11 = { 1, 0, 1, fmt_801, 0 };
    static cilist io___15 = { 1, 0, 1, fmt_801, 0 };


/* L801: */
    initgl_("11.02/04", 8L);
/* Computing MAX */
    i__1 = max(20,globnu_1.indlun);
    ufut = max(i__1,globnu_1.glblun) + 1;
    uref = ufut + 1;
/*  open input file under test (FUT) */
    o__1.oerr = 1;
    o__1.ounit = ufut;
    o__1.ofnmlen = 10;
    o__1.ofnm = "phigs.hpns";
    o__1.orl = 4000;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsfi(&io___5);
	do_fio(&c__1, "Error code opening input file phigs.hpns = ", 43L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
    al__1.aerr = 1;
    al__1.aunit = ufut;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsfi(&io___6);
	do_fio(&c__1, "Error code rewinding input file phigs.hpns = ", 45L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  open input reference file (REF) */
    o__1.oerr = 1;
    o__1.ounit = uref;
    o__1.ofnmlen = 14;
    o__1.ofnm = "std_phigs.hpns";
    o__1.orl = 4000;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsfi(&io___7);
	do_fio(&c__1, "Error code opening input file std_phigs.hpns = ", 47L);

	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
    al__1.aerr = 1;
    al__1.aunit = uref;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsfi(&io___8);
	do_fio(&c__1, "Error code rewinding input file std_phigs.hpns = ", 
		49L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
    s_copy(futrec, " ", 6000L, 1L);
    s_copy(refrec, " ", 6000L, 1L);
/*  get next REF record */
L100:
    io___11.ciunit = uref;
    ioerr = s_rsfe(&io___11);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = do_fio(&c__1, refrec, 6000L);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = e_rsfe();
L100001:
    if (ioerr < 0) {
	goto L666;
    }
/*  set length and location to be compared within REFREC */
    if (s_cmp(refrec, "extern void ", 12L, 12L) == 0) {
	cmplen = i_indx(refrec, "(", 6000L, 1L) - 1;
	key1 = 13;
	s_copy(srid, "1 12", 4L, 4L);
    } else {
	cmplen = i_indx(refrec, " typedef", 6000L, 8L) - 1;
	key1 = 1;
	s_copy(srid, "1 11", 4L, 4L);
    }
    if (cmplen < 0) {
	unmsg_("Invalid record in std_phigs.hpns.", 33L);
    }
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 58, a__1[0] = "The phigs.h file should contain a correct decla"
	    "ration for ";
#else /* NO_PROTO */
    i__2[0] = 58, a__1[0] = "The phigs.h file should contain a correct decla\
ration for ";
#endif /* NO_PROTO */
    i__2[1] = cmplen - (key1 - 1), a__1[1] = refrec + (key1 - 1);
    i__2[2] = 1, a__1[2] = ".";
    s_cat(ch__1, a__1, i__2, &c__3, 6059L);
    setmsg_(srid, ch__1, 4L, cmplen - (key1 - 1) + 59);
/*  Look for matching FUT record */
L120:
    if (s_cmp(futrec, refrec, cmplen, cmplen) < 0) {
	io___15.ciunit = ufut;
	ioerr = s_rsfe(&io___15);
	if (ioerr != 0) {
	    goto L100002;
	}
	ioerr = do_fio(&c__1, futrec, 6000L);
	if (ioerr != 0) {
	    goto L100002;
	}
	ioerr = e_rsfe();
L100002:
	if (ioerr < 0) {
	    goto L660;
	}
	goto L120;
    } else if (s_cmp(futrec, refrec, cmplen, cmplen) > 0) {
/*  no equivalent name in FUT */
	fail_();
/* Writing concatenation */
	i__2[0] = 19, a__1[0] = "No declaration for ";
	i__2[1] = cmplen - (key1 - 1), a__1[1] = refrec + (key1 - 1);
	i__2[2] = 18, a__1[2] = " found in phigs.h.";
	s_cat(ch__2, a__1, i__2, &c__3, 6037L);
	inmsg_(ch__2, cmplen - (key1 - 1) + 37);
	goto L100;
    }
/*  got a name match between FUT and REF */
/* L200: */
    reflen = itrim_(refrec, 6000L);
/*  If the statement has "typedef enum", insert the explicit marker */
/*  "{IMPL-DEP}" to allow extra enumeration values. */
    if (i_indx(refrec, " typedef enum{", 6000L, 14L) > 0) {
	i__1 = reflen - 1 - cmplen - 1;
/* Writing concatenation */
	i__2[0] = reflen - 2 - cmplen, a__1[0] = refrec;
	i__2[1] = 10, a__1[1] = "{IMPL-DEP}";
	i__2[2] = reflen - i__1, a__1[2] = refrec + i__1;
	s_cat(chbuf, a__1, i__2, &c__3, 6000L);
	s_copy(refrec, chbuf, 6000L, 6000L);
	reflen += i_len("{IMPL-DEP}", 10L);
    }
/*  put ARB at end for uniform treatment */
/* Writing concatenation */
    i__3[0] = reflen, a__2[0] = refrec;
    i__3[1] = 10, a__2[1] = "{IMPL-DEP}";
    s_cat(chbuf, a__2, i__3, &c__2, 6000L);
    s_copy(refrec, chbuf, 6000L, 6000L);
    arbloc = i_indx(refrec, "{IMPL-DEP}", 6000L, 10L);
    if (s_cmp(futrec, refrec, arbloc - 1, arbloc - 1) != 0) {
	fail_();
	goto L100;
    }
    futloc = arbloc;
/*  Start loop to compare chunks of REFREC between occurrences of ARB */
/*  with chunks of FUTARB */
    s_copy(futarb, futrec, 6000L, 6000L);
L150:
/*  discard chunks already matched */
    s_copy(chbuf, futarb + (futloc - 1), 6000L, 6000 - (futloc - 1));
    s_copy(futarb, chbuf, 6000L, 6000L);
    i__1 = arbloc + i_len("{IMPL-DEP}", 10L) - 1;
    s_copy(chbuf, refrec + i__1, 6000L, 6000 - i__1);
    s_copy(refrec, chbuf, 6000L, 6000L);
/*  check if done */
    if (s_cmp(refrec, " ", 6000L, 1L) == 0) {
	L__1 = s_cmp(futarb, " ", 6000L, 1L) == 0;
	ifpf_(&L__1);
	goto L100;
    }
/*  search for next REF chunk to be matched in FUTARB */
    arbloc = i_indx(refrec, "{IMPL-DEP}", 6000L, 10L);
    futloc = i_indx(futarb, refrec, 6000L, arbloc - 1);
    if (futloc <= 0) {
	fail_();
	goto L100;
    }
    futloc = futloc + arbloc - 1;
    goto L150;
L660:
    fail_();
    inmsg_("No more declarations to be checked; hit end of phigs.hpns.", 58L);

L666:
    cl__1.cerr = 0;
    cl__1.cunit = ufut;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = uref;
    cl__1.csta = 0;
    f_clos(&cl__1);
    windup_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

