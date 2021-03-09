/* fort/05/02/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__4 = 4;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__7 = 7;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.02/08                              * */
/*  *    TEST TITLE : Categories of picture change          * */
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

    static integer pcsev[17] = { 666,666,666,666,666,666,666,666,666,666,666,
	    666,666,666,666,666,666 };

    /* System generated locals */
    address a__1[7];
    integer i__1[7];
    logical L__1;
    char ch__1[179];

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

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static integer ng, pcc, iwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer istr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nrst (integer *, integer *), endit_(void);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int nqwkc (integer *, integer *, integer *, 
	    integer *), nsdus (integer *, integer *, integer *), nopwk (
	    integer *, integer *, integer *);
    extern logical svrok_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nrst (), endit_();
    extern integer itrim_();
    extern /* Subroutine */ int nqwkc (), nsdus (), nopwk ();
    extern logical svrok_();
#endif /* NO_PROTO */
    static char pcctab[34*17];
    static integer actpcc;
#ifndef NO_PROTO
    extern /* Subroutine */ int picchg_(integer *, char *, char *, integer *, 
	    integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int picchg_();
#endif /* NO_PROTO */
    static char pccchr[2];
    static logical valcat;
    static char pccmsg[34];
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon, actsev;
    static char sevlbl[3*3];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer specwt, repsev;
    static char sevmsg[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int setpcl_(char *, ftnlen), nqdswa (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), setmsg_(char *, char *, ftnlen, ftnlen), picenv_(
	    integer *), nqdstr (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setpcl_(), nqdswa (), setmsg_(), picenv_(), 
	    nqdstr (), xpopph_();
#endif /* NO_PROTO */
    static char svrmsg[40];
#ifndef NO_PROTO
    extern /* Subroutine */ int exsvrs_(integer *, integer *, integer *, 
	    integer *, char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int exsvrs_();
#endif /* NO_PROTO */
    static char svrlst[3];

    /* Fortran I/O blocks */
    static icilist io___14 = { 0, pccchr, 0, "(I2)", 2, 1 };


/* clear control flag */
/* deferral mode */
/* display surface empty */
/* dynamic modification */
/* modification mode */
/* state of visual representation */
/* parameters for <inquire workstation connection and type> */
    initgl_("05.02/08", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  picture change categories are numbered from 1 to 17: */
/*    workstation changes :  1 to 12 */
/*    structure changes   : 13 to 17 */
    setpcl_(pcctab, 34L);
/*  <set display update state> WAIT, UQUM */
    nsdus (&globnu_1.wkid, &c__4, &c__2);
/*  valcat = true = valid category */
    valcat = TRUE_;
/*  <inquire dynamics of workstation attr> to determine */
/*   pcsev(1 to 12) = picture change severity */
    nqdswa (&specwt, &errind, pcsev, &pcsev[1], &pcsev[2], &pcsev[3], &pcsev[
	    4], &pcsev[5], &pcsev[6], &pcsev[7], &pcsev[8], &pcsev[9], &pcsev[
	    10], &pcsev[11]);
/*  ng = an invalid code for picture change */
    ng = -1;
    for (iwk = 1; iwk <= 12; ++iwk) {
	if (pcsev[iwk - 1] < 0 || pcsev[iwk - 1] > 2 || errind != 0) {
	    valcat = FALSE_;
	    pcsev[iwk - 1] = ng;
	}
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("6", "<Inquire dynamics of workstation attributes> should report"
	    " the modification severity for the 12 kinds of workstation chang"
	    "es as IMM,IRG,CBS.", 1L, 140L);
#else /* NO_PROTO */
    setmsg_("6", "<Inquire dynamics of workstation attributes> should report\
 the modification severity for the 12 kinds of workstation changes as IMM,IR\
G,CBS.", 1L, 140L);
#endif /* NO_PROTO */
    ifpf_(&valcat);
    valcat = TRUE_;
/*  <inquire dynamics of struc> to determine */
/*     pcsev(13 to 17) = picture change severity */
    nqdstr (&specwt, &errind, &pcsev[12], &pcsev[13], &pcsev[14], &pcsev[15], 
	    &pcsev[16]);
    for (istr = 13; istr <= 17; ++istr) {
	if (pcsev[istr - 1] < 0 || pcsev[istr - 1] > 2 || errind != 0) {
	    valcat = FALSE_;
	    pcsev[iwk - 1] = ng;
	}
/* L200: */
    }
#ifndef NO_PROTO
    setmsg_("7", "<Inquire dynamics of structures> should report the modific"
	    "ation severity for the 5 kinds of structure changes as IMM,IRG,C"
	    "BS.", 1L, 125L);
#else /* NO_PROTO */
    setmsg_("7", "<Inquire dynamics of structures> should report the modific\
ation severity for the 5 kinds of structure changes as IMM,IRG,CBS.", 1L, 
	    125L);
#endif /* NO_PROTO */
    ifpf_(&valcat);
/*  severity label: */
    s_copy(sevlbl, "IRG", 3L, 3L);
    s_copy(sevlbl + 6, "CBS", 3L, 3L);
    s_copy(sevlbl + 3, "IMM", 3L, 3L);
/*  invoke PICENV to set up standard picture environment */
    picenv_(&globnu_1.wkid);
/*  pcc = 1 to 17 = picture change category */
    for (pcc = 1; pcc <= 17; ++pcc) {
	repsev = pcsev[pcc - 1];
	if (repsev == ng) {
	    goto L310;
	}
/* <redraw all structures> to make svr CORRECT */
	nrst (&globnu_1.wkid, &c__1);
/* invoke PICCHG to generate an example of pcc */
	s_wsfi(&io___14);
	do_fio(&c__1, (char *)&pcc, (ftnlen)sizeof(integer));
	e_wsfi();
	picchg_(&globnu_1.wkid, "0,1,2", pccchr, &actsev, &actpcc, 5L, 2L);
	if (actpcc == 0) {
	    goto L310;
	}
/*        calculate expected SVRs and label, */
/*           based on sevrty, defmod, modmd, and oldsvr */
	exsvrs_(&repsev, &c__4, &c__2, &c__0, svrlst, svrmsg, 3L, 40L);
	s_copy(pccmsg, pcctab + (pcc - 1) * 34, 34L, 34L);
	s_copy(sevmsg, sevlbl + repsev * 3, 3L, 3L);
/* Writing concatenation */
	i__1[0] = 24, a__1[0] = "Picture change category ";
	i__1[1] = itrim_(pccmsg, 34L), a__1[1] = pccmsg;
	i__1[2] = 31, a__1[2] = " reported as having severity = ";
	i__1[3] = 3, a__1[3] = sevmsg;
#ifndef NO_PROTO
	i__1[4] = 46, a__1[4] = " should set state of visual representation "
		"to ";
#else /* NO_PROTO */
	i__1[4] = 46, a__1[4] = " should set state of visual representation \
to ";
#endif /* NO_PROTO */
	i__1[5] = itrim_(svrmsg, 40L), a__1[5] = svrmsg;
	i__1[6] = 1, a__1[6] = ".";
	s_cat(ch__1, a__1, i__1, &c__7, 179L);
	setmsg_("6 7 13 14 15 16 19 20 21 24 26 28", ch__1, 33L, itrim_(
		pccmsg, 34L) + 104 + itrim_(svrmsg, 40L) + 1);
	L__1 = svrok_(&globnu_1.wkid, svrlst, 3L);
	ifpf_(&L__1);
L310:
/* L350: */
	;
    }
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

