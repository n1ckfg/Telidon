/* fort/03/05/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__100 = 100;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.05/04                              * */
/*  *    TEST TITLE : Deleting from archive when multiple   * */
/*  *                 archive files are open                * */
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
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer arid1, arid2, arnm1, arnm2, idum1, idum2, idum3, idum4, 
	    idum5, idum6;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen), nqphf (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nrsid (integer *, integer *, integer *, 
	    integer *), setvs_(char *, integer *, integer *, ftnlen), nclarf (
	    integer *), ndasar (integer *), chkinq_(char *, integer *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_(), nqphf ();
    extern logical seteq_();
    extern /* Subroutine */ int nrsid (), setvs_(), nclarf (), ndasar (), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer errind, spclen, explen, newlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *), 
	    noparf (integer *, integer *), stdcss_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), avarnm_(), noparf (), stdcss_();
#endif /* NO_PROTO */
    static integer mxarno;
#ifndef NO_PROTO
    extern /* Subroutine */ int narast (integer *), ndstar (integer *, 
	    integer *, integer *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    ndsnar (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int narast (), ndstar (), setmsg_(), ndsnar ();
#endif /* NO_PROTO */
    static integer spcstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer newstr[100], expstr[100];

    initgl_("03.05/04", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  <inquire phigs facilities> to determine */
/*     mxarno = maximum number of simultaneously open archive files */
    nqphf (&c__0, &errind, &idum1, &mxarno, &idum2, &idum3, &idum4, &idum5, &
	    idum6);
    chkinq_("pqphf", &errind, 5L);
    if (mxarno <= 1) {
	inmsg_("Skipping test: cannot open multiple archive files.", 50L);
	goto L666;
    }
/*  set up standard networks in CSS */
    stdcss_();
/*  open new archive file, with arid1 = archive identifier */
    arid1 = 4;
    avarnm_(&arnm1);
    noparf (&arid1, &arnm1);
/*  open 2nd archive file, with arid2 */
    arid2 = 5;
    avarnm_(&arnm2);
    noparf (&arid2, &arnm2);
/*  <archive all structures> into arid1 and arid2 */
    narast (&arid1);
    narast (&arid2);
/*  expstr = expected structures = 100,101,102,103,104,105,106,107,108,110
 */
/*                                 111,113,114,115,120,130,140,142,109 */
#ifndef NO_PROTO
    setvs_("100,101,102,103,104,105,106,107,108,110,111,113,114,115,120,130,"
	    "140,142,109", expstr, &explen, 75L);
#else /* NO_PROTO */
    setvs_("100,101,102,103,104,105,106,107,108,110,111,113,114,115,120,130,\
140,142,109", expstr, &explen, 75L);
#endif /* NO_PROTO */
/*  spcstr = specified structures = 114,102,100,140,107 */
    setvs_("114,102,100,140,107", spcstr, &spclen, 19L);
/*  <delete structures from archive> with arid1, spcstr */
    ndstar (&arid1, &spclen, spcstr);
/*  <retrieve structure indentiers> with arid2 */
/*     to determine newstr = new list of archived structures */
    nrsid (&arid2, &c__100, &newlen, newstr);
#ifndef NO_PROTO
    setmsg_("1 4", "If more than one archive file is open, <delete structure"
	    "s from archive> should not affect any open archive file other th"
	    "an the file specified.", 3L, 142L);
#else /* NO_PROTO */
    setmsg_("1 4", "If more than one archive file is open, <delete structure\
s from archive> should not affect any open archive file other than the file \
specified.", 3L, 142L);
#endif /* NO_PROTO */
/*  pass/fail depending on (newstr = expstr) */
    L__1 = newlen == explen && seteq_(&newlen, newstr, expstr);
    ifpf_(&L__1);
/*  <delete all structures from archive> arid1 */
    ndasar (&arid1);
/*  <retrieve structure identifiers> with arid2 to determine newstr */
    nrsid (&arid2, &c__100, &newlen, newstr);
#ifndef NO_PROTO
    setmsg_("3 4", "If more than one archive file is open, <delete all struc"
	    "tures from archive> should not affect any open archive file othe"
	    "r than the file specified.", 3L, 146L);
#else /* NO_PROTO */
    setmsg_("3 4", "If more than one archive file is open, <delete all struc\
tures from archive> should not affect any open archive file other than the f\
ile specified.", 3L, 146L);
#endif /* NO_PROTO */
/*  pass/fail depending on (newstr = expstr) */
    L__1 = newlen == explen && seteq_(&newlen, newstr, expstr);
    ifpf_(&L__1);
/*  <archive all structures> into arid1 */
    narast (&arid1);
/*  spcstr = specified structures = 107, 114, 105 */
    setvs_("107,114,105", spcstr, &spclen, 11L);
/*  <delete structure networks from archive> with arid1, spcstr */
    ndsnar (&arid1, &spclen, spcstr);
/*  <retrieve structure identifiers> with arid2 to determine newstr */
    nrsid (&arid2, &c__100, &newlen, newstr);
#ifndef NO_PROTO
    setmsg_("2 4", "If more than one archive file is open, <delete structure"
	    " networks from archive> should not affect any open archive file "
	    "other than the file specified.", 3L, 150L);
#else /* NO_PROTO */
    setmsg_("2 4", "If more than one archive file is open, <delete structure\
 networks from archive> should not affect any open archive file other than t\
he file specified.", 3L, 150L);
#endif /* NO_PROTO */
/*  pass/fail depending on (newstr = expstr) */
    L__1 = newlen == explen && seteq_(&newlen, newstr, expstr);
    ifpf_(&L__1);
/*  <close archive file> with arid1 and arid2 */
    nclarf (&arid1);
    nclarf (&arid2);
/*  done: */
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

