/* fort/03/03/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;
static integer c__104 = 104;
static integer c__102 = 102;
static integer c__101 = 101;
static integer c__200 = 200;
static integer c__2 = 2;
static integer c__405 = 405;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.03/03                              * */
/*  *    TEST TITLE : Archival conflict resolution          * */
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
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndas ();
#endif /* NO_PROTO */
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), narsn (integer *, integer *, 
	    integer *), nrast (integer *), narst (integer *, integer *, 
	    integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), narsn (), nrast (), narst (), 
	    setvs_();
#endif /* NO_PROTO */
    static logical failfl;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), ndasar (integer *);
    extern logical cssids_(char *, ftnlen);
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *), 
	    noparf (integer *, integer *), narast (integer *), setmsg_(char *,
	     char *, ftnlen, ftnlen), errctl_(logical *);
    extern logical strcon_(integer *, char *, ftnlen);
    extern /* Subroutine */ int nscnrs (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclarf (), ndasar ();
    extern logical cssids_();
    extern /* Subroutine */ int initgl_(), avarnm_(), noparf (), narast (), 
	    setmsg_(), errctl_();
    extern logical strcon_();
    extern /* Subroutine */ int nscnrs ();
#endif /* NO_PROTO */
    static integer spcsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int sigtst_(integer *, logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int sigtst_();
#endif /* NO_PROTO */
    static integer spcstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setstr_(
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setstr_();
#endif /* NO_PROTO */

/* conflict resolution */
/*                maintain    abandon     update */
/*  When structures with the same identifiers are set up for testing, */
/*  the contents of those in the CSS differ from those in the */
/*  archive, so that the two versions are distinguishable. This is */
/*  noted by following the structure identifier with a "C" (for CSS) */
/*  or "A" (for archive). */
    initgl_("03.03/03", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  open new archive file, with arid = archive identifier */
    avarnm_(&arnm);
    arid = 3;
    noparf (&arid, &arnm);
/*  *** *** ***   archiving with MAINTAIN   *** *** *** */
    nscnrs (&c__0, &c__1);
/*  ***  archive existing structures */

/*  set up structures: */
/*     CSS     : 101-C, 104-C */
/*     archive : 102-A, 104-A */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
/*  <archive all structures> to arid */
    narast (&arid);
#ifndef NO_PROTO
    setmsg_("3 4 7", "When the archival resolution flag is MAINTAIN, <archiv"
	    "e all structures> should insert new structures into the archive "
	    "file, but not replace existing structures.", 5L, 160L);
#else /* NO_PROTO */
    setmsg_("3 4 7", "When the archival resolution flag is MAINTAIN, <archiv\
e all structures> should insert new structures into the archive file, but no\
t replace existing structures.", 5L, 160L);
#endif /* NO_PROTO */
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid */
    nrast (&arid);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-A) */
    if (cssids_("101,102,104", 11L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__102, "67,1,66,104",
		 11L) && strcon_(&c__104, "67,1", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
/*  set up structures: */
/*     CSS     : 101-C, 104-C, with 101-C invoking 104-C */
/*     archive : 102-A, 104-A */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "E104,L3", 7L);
    setstr_(&c__104, "L3", 2L);
/*  <archive structure networks> 101 */
    setvs_("101", spcstr, &spcsiz, 3L);
    narsn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("2 4 7", "When the archival resolution flag is MAINTAIN, <archiv"
	    "e structure networks> should insert new structures into the arch"
	    "ive file, but not replace existing structures.", 5L, 164L);
#else /* NO_PROTO */
    setmsg_("2 4 7", "When the archival resolution flag is MAINTAIN, <archiv\
e structure networks> should insert new structures into the archive file, bu\
t not replace existing structures.", 5L, 164L);
#endif /* NO_PROTO */
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid */
    nrast (&arid);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-A) */
    if (cssids_("101,102,104", 11L)) {
#ifndef NO_PROTO
	L__1 = strcon_(&c__101, "66,104,67,3", 11L) && strcon_(&c__102, "67,"
		"1,66,104", 11L) && strcon_(&c__104, "67,1", 4L);
#else /* NO_PROTO */
	L__1 = strcon_(&c__101, "66,104,67,3", 11L) && strcon_(&c__102, "67,\
1,66,104", 11L) && strcon_(&c__104, "67,1", 4L);
#endif /* NO_PROTO */
	ifpf_(&L__1);
    } else {
	fail_();
    }
/*  ***  archive with some non-existent structures */

/*  set up structures: */
/*     CSS     : 101-C, 104-C */
/*     archive : 102-A, 104-A */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
/*  <archive structures> 101,102,103,104 */
    setvs_("101,102,103,104", spcstr, &spcsiz, 15L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    narst (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
    setmsg_("1 4 5 7", "When the archival resolution flag is MAINTAIN and so"
	    "me of the specified structures do not exist in the CSS, <archive"
	    " structures> should take no action for the non-existent structur"
	    "es, add new structures to the archive file, but not replace exis"
	    "ting archive structures.", 7L, 268L);
#else /* NO_PROTO */
    errctl_(&c__0);
    setmsg_("1 4 5 7", "When the archival resolution flag is MAINTAIN and so\
me of the specified structures do not exist in the CSS, <archive structures>\
 should take no action for the non-existent structures, add new structures t\
o the archive file, but not replace existing archive structures.", 7L, 268L);
#endif /* NO_PROTO */
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid */
    nrast (&arid);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-A) */
    if (cssids_("101,102,104", 11L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__102, "67,1,66,104",
		 11L) && strcon_(&c__104, "67,1", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("1 5", "When the archival resolution flag is MAINTAIN and some o"
	    "f the specified structures do not exist in the CSS, <archive str"
	    "uctures> should signal error 200.", 3L, 153L);
#else /* NO_PROTO */
    setmsg_("1 5", "When the archival resolution flag is MAINTAIN and some o\
f the specified structures do not exist in the CSS, <archive structures> sho\
uld signal error 200.", 3L, 153L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 200 signalled from <archive */
/*                          structures>) */
    sigtst_(&c__200, &failfl);
/*  *** *** ***   archiving with UPDATE   *** *** *** */
    nscnrs (&c__2, &c__1);
/*  ***  archive existing structures */

/*  set up structures: */
/*     CSS     : 101-C, 104-C, with 101-C invoking 104-C */
/*     archive : 102-A, 104-A */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__104, "L3", 2L);
    setstr_(&c__101, "E104,L3", 7L);
/*  <archive structure networks> 101 */
    setvs_("101", spcstr, &spcsiz, 3L);
    narsn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("2 4 6", "When the archival resolution flag is UPDATE and all of"
	    " the specified structures exist, <archive structure networks> sh"
	    "ould insert new structures into the archive file, and replace ex"
	    "isting structures.", 5L, 200L);
#else /* NO_PROTO */
    setmsg_("2 4 6", "When the archival resolution flag is UPDATE and all of\
 the specified structures exist, <archive structure networks> should insert \
new structures into the archive file, and replace existing structures.", 5L, 
	    200L);
#endif /* NO_PROTO */
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid */
    nrast (&arid);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-C) */
    if (cssids_("101,102,104", 11L)) {
#ifndef NO_PROTO
	L__1 = strcon_(&c__101, "66,104,67,3", 11L) && strcon_(&c__102, "67,"
		"1,66,104", 11L) && strcon_(&c__104, "67,3", 4L);
#else /* NO_PROTO */
	L__1 = strcon_(&c__101, "66,104,67,3", 11L) && strcon_(&c__102, "67,\
1,66,104", 11L) && strcon_(&c__104, "67,3", 4L);
#endif /* NO_PROTO */
	ifpf_(&L__1);
    } else {
	fail_();
    }
/*  ***  archive with some non-existent structures */

/*  set up structures: */
/*     CSS     : 101-C, 104-C */
/*     archive : 102-A, 104-A */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
/*  <archive structure networks> 101,102,103,104 */
    setvs_("101,102,103,104", spcstr, &spcsiz, 15L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    narsn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
    setmsg_("2 4 5 6", "When the archival resolution flag is UPDATE and some"
	    " of the specified structures do not exist in the CSS, <archive s"
	    "tructure networks> should take no action for the non-existent st"
	    "ructures, add new structures to the archive file, and replace ex"
	    "isting archive structures.", 7L, 270L);
#else /* NO_PROTO */
    errctl_(&c__0);
    setmsg_("2 4 5 6", "When the archival resolution flag is UPDATE and some\
 of the specified structures do not exist in the CSS, <archive structure net\
works> should take no action for the non-existent structures, add new struct\
ures to the archive file, and replace existing archive structures.", 7L, 270L)
	    ;
#endif /* NO_PROTO */
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid */
    nrast (&arid);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-C) */
    if (cssids_("101,102,104", 11L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__102, "67,1,66,104",
		 11L) && strcon_(&c__104, "67,3", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("2 5", "When the archival resolution flag is UPDATE and some of "
	    "the specified structures do not exist in the CSS, <archive struc"
	    "ture networks> should signal error 200.", 3L, 159L);
#else /* NO_PROTO */
    setmsg_("2 5", "When the archival resolution flag is UPDATE and some of \
the specified structures do not exist in the CSS, <archive structure network\
s> should signal error 200.", 3L, 159L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 200 signalled from <archive */
/*                          structure networks>) */
    sigtst_(&c__200, &failfl);
/*  *** *** ***   archiving with ABANDON   *** *** *** */
    nscnrs (&c__1, &c__1);
/*  ***  archive existing structures */

/*  set up structures: */
/*     CSS     : 101-C, 104-C, with 101-C invoking 104-C */
/*     archive : 102-A, 104-A */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "E104,L3", 7L);
    setstr_(&c__104, "L3", 2L);
/*  <archive structures> 101 */
    setvs_("101", spcstr, &spcsiz, 3L);
    narst (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("1 4", "When the archival resolution flag is ABANDON and all of "
	    "the specified structures exist in the CSS but not in the archive"
	    " file, <archive structures> should insert the new structures int"
	    "o the archive file.", 3L, 203L);
#else /* NO_PROTO */
    setmsg_("1 4", "When the archival resolution flag is ABANDON and all of \
the specified structures exist in the CSS but not in the archive file, <arch\
ive structures> should insert the new structures into the archive file.", 3L, 
	    203L);
#endif /* NO_PROTO */
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid */
    nrast (&arid);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-A) */
    if (cssids_("101,102,104", 11L)) {
#ifndef NO_PROTO
	L__1 = strcon_(&c__101, "66,104,67,3", 11L) && strcon_(&c__102, "67,"
		"1,66,104", 11L) && strcon_(&c__104, "67,1", 4L);
#else /* NO_PROTO */
	L__1 = strcon_(&c__101, "66,104,67,3", 11L) && strcon_(&c__102, "67,\
1,66,104", 11L) && strcon_(&c__104, "67,1", 4L);
#endif /* NO_PROTO */
	ifpf_(&L__1);
    } else {
	fail_();
    }
/*  ***  archive with some non-existent structures */

/*  set up structures: */
/*     CSS     : 101-C, 104-C */
/*     archive : 102-A, 104-A */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
/*  <archive structure networks> 101,102,103 */
    setvs_("101,102,103", spcstr, &spcsiz, 11L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    narsn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
    setmsg_("2 4 5", "When the archival resolution flag is ABANDON and some "
	    "of the specified structures do not exist in the CSS, <archive st"
	    "ructure networks> should take no action for the non-existent str"
	    "uctures and add new structures to the archive file.", 5L, 233L);
#else /* NO_PROTO */
    errctl_(&c__0);
    setmsg_("2 4 5", "When the archival resolution flag is ABANDON and some \
of the specified structures do not exist in the CSS, <archive structure netw\
orks> should take no action for the non-existent structures and add new stru\
ctures to the archive file.", 5L, 233L);
#endif /* NO_PROTO */
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid */
    nrast (&arid);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-A) */
    if (cssids_("101,102,104", 11L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__102, "67,1,66,104",
		 11L) && strcon_(&c__104, "67,1", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("2 5", "When the archival resolution flag is ABANDON and some of"
	    " the specified structures do not exist in the CSS, <archive stru"
	    "cture networks> should signal error 200.", 3L, 160L);
#else /* NO_PROTO */
    setmsg_("2 5", "When the archival resolution flag is ABANDON and some of\
 the specified structures do not exist in the CSS, <archive structure networ\
ks> should signal error 200.", 3L, 160L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 200 signalled from <archive */
/*                          structure networks>) */
    sigtst_(&c__200, &failfl);
/*  ***  archive with duplicate structures to trigger ABANDON */

/*  set up structures: */
/*     CSS     : 101-C, 104-C */
/*     archive : 102-A, 104-A */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1", 2L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
/*  <archive all structures> */
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    narast (&arid);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
    setmsg_("3 8", "When the archival resolution flag is ABANDON and some of"
	    " the specified structures are already in the archive file, <arch"
	    "ive all structures> should leave the archive file unchanged.", 3L,
	     180L);
#else /* NO_PROTO */
    errctl_(&c__0);
    setmsg_("3 8", "When the archival resolution flag is ABANDON and some of\
 the specified structures are already in the archive file, <archive all stru\
ctures> should leave the archive file unchanged.", 3L, 180L);
#endif /* NO_PROTO */
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid */
    nrast (&arid);
/*  pass/fail depending on (CSS = 102-A, 104-A) */
    if (cssids_("102,104", 7L)) {
	L__1 = strcon_(&c__102, "67,1", 4L) && strcon_(&c__104, "67,1", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("3 8", "When the archival resolution flag is ABANDON and some of"
	    " the specified structures are already in the archive file, <arch"
	    "ive all structures> should signal error 405.", 3L, 164L);
#else /* NO_PROTO */
    setmsg_("3 8", "When the archival resolution flag is ABANDON and some of\
 the specified structures are already in the archive file, <archive all stru\
ctures> should signal error 405.", 3L, 164L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 405 signalled from <archive all */
/*                          structures>) */
    sigtst_(&c__405, &failfl);
/*  ***  archive with duplicate structures to trigger ABANDON and */
/*  ***  non-existent structures */

/*  set up structures: */
/*     CSS     : 101-C, 104-C, with 101-C invoking 104-C */
/*     archive : 102-A, 104-A */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "E104,L3", 7L);
    setstr_(&c__104, "L3", 2L);
/*  <archive structure networks> 101,103,102 */
    setvs_("101,103,102", spcstr, &spcsiz, 11L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    narsn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
    setmsg_("2 8", "When the archival resolution flag is ABANDON and some of"
	    " the specified structures do not exist in the CSS and some are a"
	    "lready in the archive file, <archive structure networks> should "
	    "leave the archive file unchanged.", 3L, 217L);
#else /* NO_PROTO */
    errctl_(&c__0);
    setmsg_("2 8", "When the archival resolution flag is ABANDON and some of\
 the specified structures do not exist in the CSS and some are already in th\
e archive file, <archive structure networks> should leave the archive file u\
nchanged.", 3L, 217L);
#endif /* NO_PROTO */
/*  clear CSS */
    ndas ();
/*  <retrieve all structures> from arid */
    nrast (&arid);
/*  pass/fail depending on (CSS = 102-A, 104-A) */
    if (cssids_("102,104", 7L)) {
	L__1 = strcon_(&c__102, "67,1,66,104", 11L) && strcon_(&c__104, "67,1"
		, 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("2 5 8", "When the archival resolution flag is ABANDON and some "
	    "of the specified structures are already in the archive file and "
	    "others do not exist in the CSS, then <archive structure networks"
	    "> should signal error 200 or 405.", 5L, 215L);
#else /* NO_PROTO */
    setmsg_("2 5 8", "When the archival resolution flag is ABANDON and some \
of the specified structures are already in the archive file and others do no\
t exist in the CSS, then <archive structure networks> should signal error 20\
0 or 405.", 5L, 215L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 200 or 405 signalled from <archive */
/*                          all structures>) */
/* make 200 look like 405 for pass/fail purposes: */
    if (globnu_1.errsig == 200) {
	globnu_1.errsig = 405;
    }
    sigtst_(&c__405, &failfl);
/*  <close archive file> with arid */
    nclarf (&arid);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

