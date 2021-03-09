/* fort/03/03/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__101 = 101;
static integer c__104 = 104;
static integer c__50 = 50;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.03/07                              * */
/*  *    TEST TITLE : Partial networks in archive           * */
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
    extern /* Subroutine */ int endit_(void);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nrsid (integer *, integer *, integer *, 
	    integer *), narst (integer *, integer *, integer *), nrest (
	    integer *, integer *, integer *), setvs_(char *, integer *, 
	    integer *, ftnlen), nclarf (integer *), ndasar (integer *);
    extern logical cssids_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical seteq_();
    extern /* Subroutine */ int nrsid (), narst (), nrest (), setvs_(), 
	    nclarf (), ndasar ();
    extern logical cssids_();
#endif /* NO_PROTO */
    static integer actsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), avarnm_();
#endif /* NO_PROTO */
    static integer actstr[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int noparf (integer *, integer *), setmsg_(char *,
	     char *, ftnlen, ftnlen), narast (integer *);
    extern logical strcon_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int noparf (), setmsg_(), narast ();
    extern logical strcon_();
#endif /* NO_PROTO */
    static integer spcsiz, spcstr[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), setstr_(
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), setstr_();
#endif /* NO_PROTO */

    initgl_("03.03/07", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  open new archive file, with arid = archive identifier */
    avarnm_(&arnm);
    arid = 7;
    noparf (&arid, &arnm);
/*  *** *** ***   partial archive networks   *** *** *** */

/*  set up structures: */
/*     CSS     : 101-C, 104-C, with 101-C invoking 104-C */
    ndas ();
    setstr_(&c__101, "L931,E104", 9L);
    setstr_(&c__104, "L931,L932", 9L);
/*  <archive structures> 101 */
    setvs_("101", spcstr, &spcsiz, 3L);
    narst (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("1 4", "When <archive structures> specifies a referring structur"
	    "e, but not the structure to which it refers, only the specified "
	    "structure should be archived.", 3L, 149L);
#else /* NO_PROTO */
    setmsg_("1 4", "When <archive structures> specifies a referring structur\
e, but not the structure to which it refers, only the specified structure sh\
ould be archived.", 3L, 149L);
#endif /* NO_PROTO */
/*  <retrieve structure identifiers> to determine: */
/*     actstr = actual list of structures */
/*  pass/fail depending on (actstr = [101]) */
    nrsid (&arid, &c__50, &actsiz, actstr);
    L__1 = actsiz == spcsiz && seteq_(&actsiz, actstr, spcstr);
    ifpf_(&L__1);
/*  *** *** ***   completing CSS networks   *** *** *** */

/*  clear CSS */
    ndas ();
/*  <retrieve structures> 101 */
    nrest (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("9 12 19", "If <retrieve structures> specifies a referring struc"
	    "ture but not the structure to which it refers, and no structure "
	    "with the referred identifier exists in the CSS, then an empty st"
	    "ructure should be created in the CSS with the corresponding iden"
	    "tifier when the referring structure is retrieved.", 7L, 293L);
#else /* NO_PROTO */
    setmsg_("9 12 19", "If <retrieve structures> specifies a referring struc\
ture but not the structure to which it refers, and no structure with the ref\
erred identifier exists in the CSS, then an empty structure should be create\
d in the CSS with the corresponding identifier when the referring structure \
is retrieved.", 7L, 293L);
#endif /* NO_PROTO */
/*  pass/fail depending on (CSS = 101-C, 104-E) */
    if (cssids_("101,104", 7L)) {
	L__1 = strcon_(&c__101, "67,931,66,104", 13L) && strcon_(&c__104, 
		" ", 1L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
/*  set up structures: */
/*     archive : 101-C, 104-C, with 101-C invoking 104-C */
    ndas ();
    setstr_(&c__101, "E104,L3", 7L);
    setstr_(&c__104, "L3", 2L);
    ndasar (&arid);
    narast (&arid);
/*  clear CSS */
    ndas ();
/*  <retrieve structures> 101 */
    nrest (&arid, &spcsiz, spcstr);
#ifndef NO_PROTO
    setmsg_("9 12 19", "If <retrieve structures> specifies a referring struc"
	    "ture but not the structure to which it refers, and no structure "
	    "with the referred identifier exists in the CSS, then an empty st"
	    "ructure should be created in the CSS with the corresponding iden"
	    "tifier when the referring structure is retrieved, even if the re"
	    "ferred structure exists in the archive.", 7L, 347L);
#else /* NO_PROTO */
    setmsg_("9 12 19", "If <retrieve structures> specifies a referring struc\
ture but not the structure to which it refers, and no structure with the ref\
erred identifier exists in the CSS, then an empty structure should be create\
d in the CSS with the corresponding identifier when the referring structure \
is retrieved, even if the referred structure exists in the archive.", 7L, 
	    347L);
#endif /* NO_PROTO */
/*  pass/fail depending on (CSS = 101-C, 104-E) */
    if (cssids_("101,104", 7L)) {
	L__1 = strcon_(&c__101, "66,104,67,3", 11L) && strcon_(&c__104, " ", 
		1L);
	ifpf_(&L__1);
    } else {
	fail_();
    }
/*  <close archive file> with arid */
    nclarf (&arid);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

