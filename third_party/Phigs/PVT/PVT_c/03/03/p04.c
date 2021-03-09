/* fort/03/03/p04.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.03/04                              * */
/*  *    TEST TITLE : Selection of structures for           * */
/*  *                 retrieving                            * */
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
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndas ();
#endif /* NO_PROTO */
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nresn (integer *, integer *, 
	    integer *), nrast (integer *), nrest (integer *, integer *, 
	    integer *), setvs_(char *, integer *, integer *, ftnlen), nclarf (
	    integer *), ndasar (integer *), initgl_(char *, ftnlen);
    extern logical cssids_(char *, ftnlen);
    extern /* Subroutine */ int avarnm_(integer *), noparf (integer *, 
	    integer *), narast (integer *), setmsg_(char *, char *, ftnlen, 
	    ftnlen), stdcss_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nresn (), nrast (), nrest (), 
	    setvs_(), nclarf (), ndasar (), initgl_();
    extern logical cssids_();
    extern /* Subroutine */ int avarnm_(), noparf (), narast (), setmsg_(), 
	    stdcss_();
#endif /* NO_PROTO */
    static integer spcsiz, spcstr[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    initgl_("03.03/04", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  open new archive file, with arid = archive identifier */
    avarnm_(&arnm);
    arid = 4;
    noparf (&arid, &arnm);
/*  <delete all structures from archive> to ensure empty file */
    ndasar (&arid);
/*  set up standard networks in archive = arid */
    stdcss_();
    narast (&arid);
/*  <delete all structures> to ensure empty CSS */
    ndas ();
/*  spcstr = specified structures = 114,111,115,109,140,142 */
    setvs_("114,111,115,109,140,142", spcstr, &spcsiz, 23L);
/*  <retrieve structures> with arid, spcstr */
    nrest (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("9 12", "When no references to non-existent structures are creat"
	    "ed, then exactly those structures explicitly listed in the input"
	    " parameter of <retrieve structures> should be reported as existi"
	    "ng in a previously empty CSS.", 4L, 212L);
#else /* NO_PROTO */
    setmsg_("9 12", "When no references to non-existent structures are creat\
ed, then exactly those structures explicitly listed in the input parameter o\
f <retrieve structures> should be reported as existing in a previously empty\
 CSS.", 4L, 212L);
#endif /* NO_PROTO */
    L__1 = cssids_("114,111,115,109,140,142", 23L);
    ifpf_(&L__1);
/*  <delete all structures> to ensure empty CSS */
    ndas ();
/*  spcstr = specified structures = 107,114,105 */
    setvs_("107,114,105", spcstr, &spcsiz, 11L);
/*  <retrieve structure networks> with arid, spcstr */
    nresn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("10 12", "The structures explicitly listed in the input paramete"
	    "r of <retrieve structure networks> and all their descendants in "
	    "the archive file should be reported as existing in a previously "
	    "empty CSS.", 5L, 192L);
#else /* NO_PROTO */
    setmsg_("10 12", "The structures explicitly listed in the input paramete\
r of <retrieve structure networks> and all their descendants in the archive \
file should be reported as existing in a previously empty CSS.", 5L, 192L);
#endif /* NO_PROTO */
    L__1 = cssids_("105,110,114,108,111,115,107,113", 31L);
    ifpf_(&L__1);
/*  <delete all structures> to ensure empty CSS */
    ndas ();
/*  <retrieve all structures> with arid */
    nrast (&arid);
#ifndef NO_PROTO
    setmsg_("11 12", "<Retrieve all structures> should cause all structures "
	    "currently in the archive file to be reported as existing in a pr"
	    "eviously empty CSS.", 5L, 137L);
    L__1 = cssids_("100,101,102,103,104,105,106,107,108,109,110,111,113,114,"
	    "115,120,130,140,142", 75L);
#else /* NO_PROTO */
    setmsg_("11 12", "<Retrieve all structures> should cause all structures \
currently in the archive file to be reported as existing in a previously emp\
ty CSS.", 5L, 137L);
    L__1 = cssids_("100,101,102,103,104,105,106,107,108,109,110,111,113,114,\
115,120,130,140,142", 75L);
#endif /* NO_PROTO */
    ifpf_(&L__1);
/*  <close archive file> with arid */
    nclarf (&arid);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

