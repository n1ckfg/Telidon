/* fort/05/03/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__0 = 0;
static integer c__4 = 4;
static integer c__99 = 99;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.03/01                              * */
/*  *    TEST TITLE : Effects of posting on the structure   * */
/*  *                 state list and workstation state list * */
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
    integer i__1;
    logical L__1;

    /* Local variables */
    static real dp, np;
    static integer iwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer istr, lsiz, stst;
    static logical upsw;
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum7;
    static real rdum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static char owcat[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqphf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nclwk (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqphf (), nclwk ();
#endif /* NO_PROTO */
    static integer strid[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *), nopwk (
	    integer *, integer *, integer *), nexst (integer *), nopst (
	    integer *), npost (integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst (), nopwk (), nexst (), 
	    nopst (), npost ();
#endif /* NO_PROTO */
    static integer acwkid[3], oconid[3], accout;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
    static real thisdp;
    static logical lwpcod, lpscod;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), chkpst_(integer *, 
	    integer *, integer *, integer *, integer *, logical *, logical *),
	     setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), chkpst_(), setmsg_();
#endif /* NO_PROTO */
    static integer thistr, simopw, stinwk[12]	/* was [4][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setpst_(
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setpst_();
#endif /* NO_PROTO */
    static integer numwks;
#ifndef NO_PROTO
    extern /* Subroutine */ int nupast (integer *), nqpost (integer *, 
	    integer *, integer *, integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nupast (), nqpost ();
#endif /* NO_PROTO */
    static integer owtype[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int nupost (integer *, integer *), multws_(
	    integer *, char *, integer *, integer *, integer *, integer *, 
	    char *, ftnlen, ftnlen), nqstst (integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nupost (), multws_(), nqstst ();
#endif /* NO_PROTO */
    static integer stvswk[12]	/* was [4][3] */;

/* structure status indicator */
    initgl_("05.03/01", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  *** *** *** *** ***   Initialization   *** *** *** *** *** */

/*  workstation setup: */
/*  Use <inquire phigs facilities> to determine: */
/*     simopw = maximum number of simultaneously open workstations */
/*  accout = number of accessible workstations with output capabilities */

/*  acwkid = array containing the specified workstation identifiers */
/*  numwks = min (3, accout, simopw) = number of workstations open */
    nqphf (&c__1, &errind, &simopw, &idum2, &idum3, &idum4, &idum5, &idum6, &
	    idum7);
    chkinq_("pqphf", &errind, 5L);
    multws_(&c__0, "od", &accout, acwkid, oconid, owtype, owcat, 2L, 1L);
/* Computing MIN */
    i__1 = min(3,accout);
    numwks = min(i__1,simopw);
/*  table setup: */
/*  stvswk = all -1's, indicating unposted = 4 rows x 3 column array */
/*           indicating what structures (rows) are expected to be */
/*           posted to what workstations (columns). */
/*  stinwk = 4 rows x 3 column array indicating what structures */
/*           (rows) are initially posted to what workstations */
/*           (columns). */
    for (istr = 1; istr <= 4; ++istr) {
	i__1 = numwks;
	for (iwk = 1; iwk <= i__1; ++iwk) {
	    stinwk[istr + (iwk << 2) - 5] = -1;
	    stvswk[istr + (iwk << 2) - 5] = -1;
/* L310: */
	}
/* L300: */
    }
/*  open workstations: */
    i__1 = numwks;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	multws_(&iwk, "od", &accout, &acwkid[iwk - 1], &oconid[iwk - 1], &
		owtype[iwk - 1], owcat, 2L, 1L);
	nopwk (&acwkid[iwk - 1], &oconid[iwk - 1], &owtype[iwk - 1]);
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("11 14", "Immediately after opening a workstation, its list of p"
	    "osted structures should be empty.", 5L, 87L);
#else /* NO_PROTO */
    setmsg_("11 14", "Immediately after opening a workstation, its list of p\
osted structures should be empty.", 5L, 87L);
#endif /* NO_PROTO */
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
    ifpf_(&lpscod);
/*  structure setup: */
/*  numstr = 4 = number of structures */
/*  strid  = array containing the specified structure identifiers */
/*  create structures: */
    for (istr = 1; istr <= 4; ++istr) {
	strid[istr - 1] = istr + 100;
/* L200: */
    }
    nopst (strid);
    nexst (&strid[1]);
    nemst (&strid[2]);
    nclst ();
    nopst (&strid[3]);
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
#ifndef NO_PROTO
    setmsg_("10 13", "Immediately after a structure is created, its list of "
	    "workstations to which posted should be empty.", 5L, 99L);
#else /* NO_PROTO */
    setmsg_("10 13", "Immediately after a structure is created, its list of \
workstations to which posted should be empty.", 5L, 99L);
#endif /* NO_PROTO */
    ifpf_(&lwpcod);
#ifndef NO_PROTO
    setmsg_("10 14", "Immediately after a structure is created, no list of p"
	    "osted structures should contain it.", 5L, 89L);
#else /* NO_PROTO */
    setmsg_("10 14", "Immediately after a structure is created, no list of p\
osted structures should contain it.", 5L, 89L);
#endif /* NO_PROTO */
    ifpf_(&lpscod);
/*  *** *** *** *** ***   Posting   *** *** *** *** *** */

/*  Loop posts structures as follows: */
/*     structure    workstations to which posted */
/*     ---------    ---------------------------- */
/*         1        all */
/*         2        first and last */
/*         3        all but the last */
/*         4        all but the first */
    i__1 = numwks;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	for (istr = 1; istr <= 4; ++istr) {
	    if (istr == 1 || istr == 2 && (iwk == 1 || iwk == 4) || istr == 3 
		    && iwk != 4 || istr == 4 && iwk != 1) {
		stinwk[istr + (iwk << 2) - 5] = 1;
		stvswk[istr + (iwk << 2) - 5] = 1;
	    }
/* L410: */
	}
/* L400: */
    }
/*  post structures to workstations, according to stinwk */
    setpst_(&c__4, strid, &numwks, acwkid, stinwk);
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
#ifndef NO_PROTO
    setmsg_("1 13", "<Post structure> should add the workstation identifier "
	    "to the list of workstations to which posted of the specified str"
	    "ucture.", 4L, 126L);
#else /* NO_PROTO */
    setmsg_("1 13", "<Post structure> should add the workstation identifier \
to the list of workstations to which posted of the specified structure.", 4L, 
	    126L);
#endif /* NO_PROTO */
    ifpf_(&lwpcod);
#ifndef NO_PROTO
    setmsg_("2 14", "<Post structure> should add the structure identifier to"
	    " the list of posted structures of the specified workstation.", 4L,
	     115L);
#else /* NO_PROTO */
    setmsg_("2 14", "<Post structure> should add the structure identifier to\
 the list of posted structures of the specified workstation.", 4L, 115L);
#endif /* NO_PROTO */
    ifpf_(&lpscod);
/*  Re-post 2nd structure to 1st workstation, with different priority = dp
 */
#ifndef NO_PROTO
    dp = 0.f;
#else /* NO_PROTO */
    dp = (float)0.;
#endif /* NO_PROTO */
    npost (acwkid, &strid[1], &dp);
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
#ifndef NO_PROTO
    setmsg_("4 13", "<Post structure> should leave unchanged the list of wor"
	    "kstations to which posted of the specified structure when that s"
	    "tructure has already been posted to the specified workstation.", 
	    4L, 181L);
#else /* NO_PROTO */
    setmsg_("4 13", "<Post structure> should leave unchanged the list of wor\
kstations to which posted of the specified structure when that structure has\
 already been posted to the specified workstation.", 4L, 181L);
#endif /* NO_PROTO */
    ifpf_(&lwpcod);
#ifndef NO_PROTO
    setmsg_("4 14", "<Post structure> should leave unchanged the list of pos"
	    "ted structures of the specified workstation when the specified s"
	    "tructure has already been posted to that workstation.", 4L, 172L);

#else /* NO_PROTO */
    setmsg_("4 14", "<Post structure> should leave unchanged the list of pos\
ted structures of the specified workstation when the specified structure has\
 already been posted to that workstation.", 4L, 172L);
#endif /* NO_PROTO */
    ifpf_(&lpscod);
#ifndef NO_PROTO
    setmsg_("4 14", "<Post structure> should change the relevant display pri"
	    "ority in the list of posted structures when the specified struct"
	    "ure has already been posted to the specified workstation.", 4L, 
	    176L);
#else /* NO_PROTO */
    setmsg_("4 14", "<Post structure> should change the relevant display pri\
ority in the list of posted structures when the specified structure has alre\
ady been posted to the specified workstation.", 4L, 176L);
#endif /* NO_PROTO */
/*  <inquire list of posted structures> for 2nd structure, 1st workstation
 */
/*  to determine new priority = np */
    nqpost (acwkid, &c__0, &errind, &lsiz, &idum1, &rdum1);
    chkinq_("pqpost", &errind, 6L);
#ifndef NO_PROTO
    np = dp + 100.f;
#else /* NO_PROTO */
    np = dp + (float)100.;
#endif /* NO_PROTO */
/*  find STRID(2) in list of posted structures */
    i__1 = lsiz;
    for (istr = 1; istr <= i__1; ++istr) {
	nqpost (acwkid, &istr, &errind, &idum1, &thistr, &thisdp);
	chkinq_("pqpost", &errind, 6L);
	if (thistr == strid[1]) {
	    np = thisdp;
	    goto L460;
	}
/* L450: */
    }
L460:
    L__1 = np == dp;
    ifpf_(&L__1);
/*  *** *** *** ***   Unposting a non-existent structure   *** *** *** ***
 */
    nupost (acwkid, &c__99);
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
#ifndef NO_PROTO
    setmsg_("7 13", "Unposting a non-existent structure should have no effec"
	    "t on any list of workstations to which posted.", 4L, 101L);
#else /* NO_PROTO */
    setmsg_("7 13", "Unposting a non-existent structure should have no effec\
t on any list of workstations to which posted.", 4L, 101L);
#endif /* NO_PROTO */
    ifpf_(&lwpcod);
#ifndef NO_PROTO
    setmsg_("7 14", "Unposting a non-existent structure should have no effec"
	    "t on any list of posted structures.", 4L, 90L);
#else /* NO_PROTO */
    setmsg_("7 14", "Unposting a non-existent structure should have no effec\
t on any list of posted structures.", 4L, 90L);
#endif /* NO_PROTO */
    ifpf_(&lpscod);
#ifndef NO_PROTO
    setmsg_("7", "Unposting a non-existent structure should not create the s"
	    "pecified structure.", 1L, 77L);
#else /* NO_PROTO */
    setmsg_("7", "Unposting a non-existent structure should not create the s\
pecified structure.", 1L, 77L);
#endif /* NO_PROTO */
    nqstst (&c__99, &errind, &stst);
    chkinq_("pqstst", &errind, 6L);
    L__1 = stst == 0;
    ifpf_(&L__1);
/*** *** *** ***   Unposting an unposted existent structure   *** *** *** 
****/
/*  make sure structure #99 exists */
    nemst (&c__99);
    nupost (acwkid, &c__99);
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
#ifndef NO_PROTO
    setmsg_("7 13", "Unposting an unposted structure should have no effect o"
	    "n any list of workstations to which posted.", 4L, 98L);
#else /* NO_PROTO */
    setmsg_("7 13", "Unposting an unposted structure should have no effect o\
n any list of workstations to which posted.", 4L, 98L);
#endif /* NO_PROTO */
    ifpf_(&lwpcod);
#ifndef NO_PROTO
    setmsg_("7 14", "Unposting an unposted structure should have no effect o"
	    "n any list of posted structures.", 4L, 87L);
#else /* NO_PROTO */
    setmsg_("7 14", "Unposting an unposted structure should have no effect o\
n any list of posted structures.", 4L, 87L);
#endif /* NO_PROTO */
    ifpf_(&lpscod);
/*  *** *** ***   Unposting individual structures  *** *** *** */
/*  unpost every other posting: */
    upsw = FALSE_;
    for (istr = 1; istr <= 4; ++istr) {
	i__1 = numwks;
	for (iwk = 1; iwk <= i__1; ++iwk) {
	    if (stvswk[istr + (iwk << 2) - 5] == 1) {
		upsw = ! upsw;
		if (upsw) {
		    nupost (&acwkid[iwk - 1], &strid[istr - 1]);
		    stvswk[istr + (iwk << 2) - 5] = -1;
		}
	    }
/* L510: */
	}
/* L500: */
    }
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
#ifndef NO_PROTO
    setmsg_("5 13", "<Unpost structure> should remove the workstation identi"
	    "fier from the list of workstations to which posted of the specif"
	    "ied structure.", 4L, 133L);
#else /* NO_PROTO */
    setmsg_("5 13", "<Unpost structure> should remove the workstation identi\
fier from the list of workstations to which posted of the specified structur\
e.", 4L, 133L);
#endif /* NO_PROTO */
    ifpf_(&lwpcod);
#ifndef NO_PROTO
    setmsg_("6 14", "<Unpost structure> should remove the structure identifi"
	    "er from the list of posted structures of the specified workstati"
	    "on.", 4L, 122L);
#else /* NO_PROTO */
    setmsg_("6 14", "<Unpost structure> should remove the structure identifi\
er from the list of posted structures of the specified workstation.", 4L, 
	    122L);
#endif /* NO_PROTO */
    ifpf_(&lpscod);
/*  *** *** ***   Unposting all structures  *** *** *** */
/*  post structures to workstations, according to stinwk */
    setpst_(&c__4, strid, &numwks, acwkid, stinwk);
    for (istr = 1; istr <= 4; ++istr) {
	i__1 = numwks;
	for (iwk = 1; iwk <= i__1; ++iwk) {
	    stvswk[istr + (iwk << 2) - 5] = stinwk[istr + (iwk << 2) - 5];
/* L610: */
	}
/* L600: */
    }
/*  <unpost all structures> acwkid(1) and note in stvswk */
    nupast (acwkid);
    for (istr = 1; istr <= 4; ++istr) {
	stvswk[istr - 1] = -1;
/* L650: */
    }
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
#ifndef NO_PROTO
    setmsg_("8 13", "<Unpost all structures> should remove the workstation i"
	    "dentifier from the list of workstations to which posted in all t"
	    "he structure state lists.", 4L, 144L);
#else /* NO_PROTO */
    setmsg_("8 13", "<Unpost all structures> should remove the workstation i\
dentifier from the list of workstations to which posted in all the structure\
 state lists.", 4L, 144L);
#endif /* NO_PROTO */
    ifpf_(&lwpcod);
#ifndef NO_PROTO
    setmsg_("9 14", "<Unpost all structures> should remove all structure ide"
	    "ntifiers from the list of posted structures of the specified wor"
	    "kstation.", 4L, 128L);
#else /* NO_PROTO */
    setmsg_("9 14", "<Unpost all structures> should remove all structure ide\
ntifiers from the list of posted structures of the specified workstation.", 
	    4L, 128L);
#endif /* NO_PROTO */
    ifpf_(&lpscod);
/*  *** *** *** *** ***   Close workstation   *** *** *** *** *** */
/*  post structures to workstations, according to stinwk */
    setpst_(&c__4, strid, &numwks, acwkid, stinwk);
    for (istr = 1; istr <= 4; ++istr) {
	i__1 = numwks;
	for (iwk = 1; iwk <= i__1; ++iwk) {
	    stvswk[istr + (iwk << 2) - 5] = stinwk[istr + (iwk << 2) - 5];
/* L710: */
	}
/* L700: */
    }
/*  <close workstation> acwkid(1) and note in stvswk */
    nclwk (acwkid);
    for (istr = 1; istr <= 4; ++istr) {
	stvswk[istr - 1] = -1;
/* L750: */
    }
#ifndef NO_PROTO
    setmsg_("12 13", "<Close workstation> should remove the workstation iden"
	    "tifier from the list of workstations to which posted in all the "
	    "structure state lists.", 5L, 140L);
#else /* NO_PROTO */
    setmsg_("12 13", "<Close workstation> should remove the workstation iden\
tifier from the list of workstations to which posted in all the structure st\
ate lists.", 5L, 140L);
#endif /* NO_PROTO */
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
    ifpf_(&lwpcod);
/*  *** *** *** *** ***   Re-opening  workstation   *** *** *** *** *** */

    nopwk (acwkid, oconid, owtype);
    chkpst_(&c__4, strid, &numwks, acwkid, stvswk, &lwpcod, &lpscod);
#ifndef NO_PROTO
    setmsg_("11 14", "Immediately after re-opening a workstation, its list o"
	    "f posted structures should be empty.", 5L, 90L);
#else /* NO_PROTO */
    setmsg_("11 14", "Immediately after re-opening a workstation, its list o\
f posted structures should be empty.", 5L, 90L);
#endif /* NO_PROTO */
    ifpf_(&lpscod);
#ifndef NO_PROTO
    setmsg_("11 13", "Immediately after re-opening a workstation, no list of"
	    " workstations to which posted should contain it.", 5L, 102L);
#else /* NO_PROTO */
    setmsg_("11 13", "Immediately after re-opening a workstation, no list of\
 workstations to which posted should contain it.", 5L, 102L);
#endif /* NO_PROTO */
    ifpf_(&lwpcod);
/*  <close structure> */
    nclst ();
/*  close all workstations */
    i__1 = numwks;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	nclwk (&acwkid[iwk - 1]);
/* L800: */
    }
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

