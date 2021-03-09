/* fort/03/03/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__105 = 105;
static integer c__104 = 104;
static integer c__102 = 102;
static integer c__101 = 101;
static integer c__103 = 103;
static integer c__408 = 408;
static integer c__2 = 2;
static integer c__405 = 405;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.03/05                              * */
/*  *    TEST TITLE : Retrieval conflict resolution         * */
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
    extern /* Subroutine */ int endit_(void), nresn (integer *, integer *, 
	    integer *), nrast (integer *), nrest (integer *, integer *, 
	    integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nresn (), nrast (), nrest (), 
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
/*  noted by following the structure identifier with a "C" (for CSS), */
/*  "A" (for archive), or "E" (for empty). */
    initgl_("03.03/05", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  open new archive file, with arid = archive identifier */
    avarnm_(&arnm);
    arid = 5;
    noparf (&arid, &arnm);
/*  *** *** ***   retrieving with MAINTAIN   *** *** *** */
    nscnrs (&c__1, &c__0);
/*  ***  retrieve existing structures */
/*  set up structures: */
/*     archive : 102-A, 104-A, 105-A, */
/*        with 102-A invoking 104-A, and 104-A invoking 105-A */
/*     CSS:      101-C, 104-C */
    ndas ();
    setstr_(&c__105, "L1", 2L);
    setstr_(&c__104, "L1,E105", 7L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("10 12 14", "When the retrieval resolution flag is MAINTAIN, <re"
	    "trieve structure networks> should insert new structures into the"
	    " CSS, but not replace existing structures.", 8L, 157L);
#else /* NO_PROTO */
    setmsg_("10 12 14", "When the retrieval resolution flag is MAINTAIN, <re\
trieve structure networks> should insert new structures into the CSS, but no\
t replace existing structures.", 8L, 157L);
#endif /* NO_PROTO */
/*  <retrieve structure networks> 102 */
    setvs_("102", spcstr, &spcsiz, 3L);
    nresn (&arid, &spcsiz, spcstr);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-C, 105-A) */
    if (cssids_("101,102,104,105", 15L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__102, "67,1,66,104",
		 11L) && strcon_(&c__104, "67,3", 4L) && strcon_(&c__105, 
		"67,1", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
/*  set up structures: */
/*     archive : 102-A, 104-A, with 102-A invoking 104-A */
/*     CSS:      101-C, 104-C */
    ndas ();
    setstr_(&c__104, "L1", 2L);
    setstr_(&c__102, "L1,E104", 7L);
    ndasar (&arid);
    narast (&arid);
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("11 12 14", "When the retrieval resolution flag is MAINTAIN, <re"
	    "trieve all structures> should insert new structures into the CSS"
	    ", but not replace existing structures.", 8L, 153L);
#else /* NO_PROTO */
    setmsg_("11 12 14", "When the retrieval resolution flag is MAINTAIN, <re\
trieve all structures> should insert new structures into the CSS, but not re\
place existing structures.", 8L, 153L);
#endif /* NO_PROTO */
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
/*  ***  retrieve with some non-existing structures */

/*  set up CSS: 101-C, 104-C */
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("9 12 13 14", "When the retrieval resolution flag is MAINTAIN an"
	    "d some of the specified structures do not exist in the archive, "
	    "<retrieve structures> should insert existing structures into the"
	    " CSS and create empty structures for those not existing, but not"
	    " replace existing CSS structures.", 10L, 274L);
#else /* NO_PROTO */
    setmsg_("9 12 13 14", "When the retrieval resolution flag is MAINTAIN an\
d some of the specified structures do not exist in the archive, <retrieve st\
ructures> should insert existing structures into the CSS and create empty st\
ructures for those not existing, but not replace existing CSS structures.", 
	    10L, 274L);
#endif /* NO_PROTO */
/*  <retrieve structures> 101,102,103,104 */
    setvs_("101,102,103,104", spcstr, &spcsiz, 15L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nrest (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  pass/fail depending on (CSS = 101-C, 102-A, 103-E, 104-C) */
    if (cssids_("101,102,103,104", 15L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__102, "67,1,66,104",
		 11L) && strcon_(&c__103, " ", 1L) && strcon_(&c__104, "67,3",
		 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("9 13", "When the retrieval resolution flag is MAINTAIN and some"
	    " of the specified structures do not exist in the archive, <retri"
	    "eve structures> should signal error 408.", 4L, 159L);
#else /* NO_PROTO */
    setmsg_("9 13", "When the retrieval resolution flag is MAINTAIN and some\
 of the specified structures do not exist in the archive, <retrieve structur\
es> should signal error 408.", 4L, 159L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 408 signalled from <retrieve */
/*                          structures>) */
    sigtst_(&c__408, &failfl);
/*  *** *** ***   retrieving with UPDATE   *** *** *** */
    nscnrs (&c__1, &c__2);
/*  ***  retrieve existing structures */
/*  set up CSS: 101-C, 104-C */
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("10 12 16", "When the retrieval resolution flag is UPDATE, <retr"
	    "ieve structure networks> should insert new structures into the C"
	    "SS, and replace existing structures.", 8L, 151L);
#else /* NO_PROTO */
    setmsg_("10 12 16", "When the retrieval resolution flag is UPDATE, <retr\
ieve structure networks> should insert new structures into the CSS, and repl\
ace existing structures.", 8L, 151L);
#endif /* NO_PROTO */
/*  <retrieve structure networks> 102 */
    setvs_("102", spcstr, &spcsiz, 3L);
    nresn (&arid, &spcsiz, spcstr);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-A) */
    if (cssids_("101,102,104", 11L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__102, "67,1,66,104",
		 11L) && strcon_(&c__104, "67,1", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
/*  ***  retrieve with some non-existing structures */

/*  set up CSS: 101-C, 104-C */
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("10 12 16 17", "When the retrieval resolution flag is UPDATE and"
	    " some of the specified structures do not exist in the archive, <"
	    "retrieve structure networks> should insert existing structures i"
	    "nto the CSS, create empty structures for those not existing, and"
	    " replace existing CSS structures, even if the replacement did no"
	    "t exist in the archive.", 11L, 327L);
#else /* NO_PROTO */
    setmsg_("10 12 16 17", "When the retrieval resolution flag is UPDATE and\
 some of the specified structures do not exist in the archive, <retrieve str\
ucture networks> should insert existing structures into the CSS, create empt\
y structures for those not existing, and replace existing CSS structures, ev\
en if the replacement did not exist in the archive.", 11L, 327L);
#endif /* NO_PROTO */
/*  <retrieve structure networks> 101,102,104 */
    setvs_("101,102,104", spcstr, &spcsiz, 11L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nresn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  pass/fail depending on (CSS = 101-E, 102-A, 104-A) */
    if (cssids_("101,102,104", 11L)) {
	L__1 = strcon_(&c__101, " ", 1L) && strcon_(&c__102, "67,1,66,104", 
		11L) && strcon_(&c__104, "67,1", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("10 17", "When the retrieval resolution flag is UPDATE and some "
	    "of the specified structures do not exist in the archive, <retrie"
	    "ve structure networks> should signal error 408.", 5L, 165L);
#else /* NO_PROTO */
    setmsg_("10 17", "When the retrieval resolution flag is UPDATE and some \
of the specified structures do not exist in the archive, <retrieve structure\
 networks> should signal error 408.", 5L, 165L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 408 signalled from <retrieve */
/*                          structure networks>) */
    sigtst_(&c__408, &failfl);
/*  *** *** ***   retrieving with ABANDON   *** *** *** */
    nscnrs (&c__1, &c__1);
/*  ***  retrieve existing structures */
/*  set up CSS: 101-C, 104-C */
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("9 12", "When the retrieval resolution flag is ABANDON and all o"
	    "f the specified structures exist in the archive file but not in "
	    "the CSS, <retrieve structures> should insert the new structures "
	    "into the CSS.", 4L, 196L);
#else /* NO_PROTO */
    setmsg_("9 12", "When the retrieval resolution flag is ABANDON and all o\
f the specified structures exist in the archive file but not in the CSS, <re\
trieve structures> should insert the new structures into the CSS.", 4L, 196L);

#endif /* NO_PROTO */
/*  <retrieve structures> 102 */
    setvs_("102", spcstr, &spcsiz, 3L);
    nrest (&arid, &spcsiz, spcstr);
/*  pass/fail depending on (CSS = 101-C, 102-A, 104-C) */
    if (cssids_("101,102,104", 11L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__102, "67,1,66,104",
		 11L) && strcon_(&c__104, "67,3", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
/*  ***  retrieve with some non-existing structures */
/*  set up CSS: 101-C */
    ndas ();
    setstr_(&c__101, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("10 12 13", "When the retrieval resolution flag is ABANDON and s"
	    "ome of the specified structures do not exist in the archive, <re"
	    "trieve structure networks> should insert existing structures int"
	    "o the CSS and create empty structures for those not existing.", 
	    8L, 240L);
#else /* NO_PROTO */
    setmsg_("10 12 13", "When the retrieval resolution flag is ABANDON and s\
ome of the specified structures do not exist in the archive, <retrieve struc\
ture networks> should insert existing structures into the CSS and create emp\
ty structures for those not existing.", 8L, 240L);
#endif /* NO_PROTO */
/*  <retrieve structure networks> 102,103 */
    setvs_("102,103", spcstr, &spcsiz, 7L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nresn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  pass/fail depending on (CSS = 101-C, 102-A, 103-E, 104-A) */
    if (cssids_("101,102,103,104", 15L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__102, "67,1,66,104",
		 11L) && strcon_(&c__103, " ", 1L) && strcon_(&c__104, "67,1",
		 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("10 13", "When the retrieval resolution flag is ABANDON and some"
	    " of the specified structures do not exist in the archive, <retri"
	    "eve structure networks> should signal error 408.", 5L, 166L);
#else /* NO_PROTO */
    setmsg_("10 13", "When the retrieval resolution flag is ABANDON and some\
 of the specified structures do not exist in the archive, <retrieve structur\
e networks> should signal error 408.", 5L, 166L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 408 signalled from <retrieve */
/*                          structure networks>) */
    sigtst_(&c__408, &failfl);
/*  ***  retrieve with duplicate structures to trigger ABANDON */

/*  set up CSS: 101-C, 104-C */
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("11 15", "When the retrieval resolution flag is ABANDON and some"
	    " of the specified structures are already in the CSS, <retrieve a"
	    "ll structures> should leave the CSS unchanged.", 5L, 164L);
#else /* NO_PROTO */
    setmsg_("11 15", "When the retrieval resolution flag is ABANDON and some\
 of the specified structures are already in the CSS, <retrieve all structure\
s> should leave the CSS unchanged.", 5L, 164L);
#endif /* NO_PROTO */
/*  <retrieve all structures> from arid */
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nrast (&arid);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  pass/fail depending on (CSS = 101-C, 104-C) */
    if (cssids_("101,104", 7L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__104, "67,3", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("11 15", "When the retrieval resolution flag is ABANDON and some"
	    " of the specified structures are already in the CSS, <retrieve a"
	    "ll structures> should signal error 405.", 5L, 157L);
#else /* NO_PROTO */
    setmsg_("11 15", "When the retrieval resolution flag is ABANDON and some\
 of the specified structures are already in the CSS, <retrieve all structure\
s> should signal error 405.", 5L, 157L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 405 signalled from <retrieve all */
/*                          structures>) */
    sigtst_(&c__405, &failfl);
/*  ***  retrieve with duplicate structures to trigger ABANDON and */
/*  ***  non-existent structures */

/*  set up CSS: 101-C, 104-C */
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("10 15", "When the retrieval resolution flag is ABANDON and some"
	    " of the specified structures exist in the archive and also in th"
	    "e CSS, <retrieve structure networks> should leave the CSS unchan"
	    "ged.", 5L, 186L);
#else /* NO_PROTO */
    setmsg_("10 15", "When the retrieval resolution flag is ABANDON and some\
 of the specified structures exist in the archive and also in the CSS, <retr\
ieve structure networks> should leave the CSS unchanged.", 5L, 186L);
#endif /* NO_PROTO */
/*  <retrieve structure networks> 103, 102 */
    setvs_("103,102", spcstr, &spcsiz, 7L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nresn (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  pass/fail depending on (CSS = 101-C, 104-C) */
    if (cssids_("101,104", 7L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__104, "67,3", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("10 13 15", "When the retrieval resolution flag is ABANDON and s"
	    "ome of the specified structures are already in the CSS, and othe"
	    "rs do not exist in the archive file, then <retrieve structure ne"
	    "tworks> should signal error 405 or 408.", 8L, 218L);
#else /* NO_PROTO */
    setmsg_("10 13 15", "When the retrieval resolution flag is ABANDON and s\
ome of the specified structures are already in the CSS, and others do not ex\
ist in the archive file, then <retrieve structure networks> should signal er\
ror 405 or 408.", 8L, 218L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 405 or 408 signalled from <retrieve */
/*                          structure networks>) */
/* make 408 look like 405 for pass/fail purposes: */
    if (globnu_1.errsig == 408) {
	globnu_1.errsig = 405;
    }
    sigtst_(&c__405, &failfl);
/*  set up CSS: 101-C, 104-C */
    ndas ();
    setstr_(&c__101, "L3", 2L);
    setstr_(&c__104, "L3", 2L);
#ifndef NO_PROTO
    setmsg_("10 15", "When the retrieval resolution flag is ABANDON and a sp"
	    "ecified structure is already in the CSS, <retrieve structures> s"
	    "hould leave the CSS unchanged even if the structure does not exi"
	    "st in the archive.", 5L, 200L);
#else /* NO_PROTO */
    setmsg_("10 15", "When the retrieval resolution flag is ABANDON and a sp\
ecified structure is already in the CSS, <retrieve structures> should leave \
the CSS unchanged even if the structure does not exist in the archive.", 5L, 
	    200L);
#endif /* NO_PROTO */
/*  <retrieve structures> 102, 101 */
    setvs_("102,101", spcstr, &spcsiz, 7L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nrest (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  pass/fail depending on (CSS = 101-C, 104-C) */
    if (cssids_("101,104", 7L)) {
	L__1 = strcon_(&c__101, "67,3", 4L) && strcon_(&c__104, "67,3", 4L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("10 13 15", "When the retrieval resolution flag is ABANDON and a"
	    " specified non-existent structure is already in the CSS, then <r"
	    "etrieve structures> should signal error 405 or 408.", 8L, 166L);
#else /* NO_PROTO */
    setmsg_("10 13 15", "When the retrieval resolution flag is ABANDON and a\
 specified non-existent structure is already in the CSS, then <retrieve stru\
ctures> should signal error 405 or 408.", 8L, 166L);
#endif /* NO_PROTO */
/*  pass/fail depending on (Error 405 or 408 signalled from <retrieve */
/*                          structures>) */
/* make 408 look like 405 for pass/fail purposes: */
    if (globnu_1.errsig == 408) {
	globnu_1.errsig = 405;
    }
    sigtst_(&c__405, &failfl);
/* L666: */
/* close archive and PHIGS */
    nclarf (&arid);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

