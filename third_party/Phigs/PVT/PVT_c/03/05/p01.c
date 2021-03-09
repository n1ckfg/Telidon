/* fort/03/05/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__100 = 100;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__407 = 407;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.05/01                              * */
/*  *    TEST TITLE : Delete specified structures from      * */
/*  *                 archive                               * */
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
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer arnm;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nrsid (integer *, integer *, integer *, 
	    integer *), setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical seteq_();
    extern /* Subroutine */ int nrsid (), setvs_();
#endif /* NO_PROTO */
    static logical failfl;
    static integer actlen, alllen;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), setdif_(integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclarf (), setdif_();
#endif /* NO_PROTO */
    static integer anslen, spclen, temlen, newlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), avarnm_();
#endif /* NO_PROTO */
    static integer allstr[100], actstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int stdcss_(void), noparf (integer *, integer *), 
	    narast (integer *), ndstar (integer *, integer *, integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), errctl_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int stdcss_(), noparf (), narast (), ndstar (), 
	    setmsg_(), errctl_();
#endif /* NO_PROTO */
    static integer ansstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int sigtst_(integer *, logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int sigtst_();
#endif /* NO_PROTO */
    static integer spcstr[100], temstr[100], newstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
    initgl_("03.05/01", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  set up standard networks in CSS */
    stdcss_();
/*  open new archive file, with arid = archive identifier */
    arid = 2;
    avarnm_(&arnm);
    noparf (&arid, &arnm);
/*  <archive all structures>, into arid */
    narast (&arid);
/*  all structures */
#ifndef NO_PROTO
    setvs_("100,101,102,103,104,105,106,107,108,109,110,111,113,114,115,120,"
	    "130,140,142", allstr, &alllen, 75L);
#else /* NO_PROTO */
    setvs_("100,101,102,103,104,105,106,107,108,109,110,111,113,114,115,120,\
130,140,142", allstr, &alllen, 75L);
#endif /* NO_PROTO */
/*  spcstr = specified structures = 103,105,113 */
    setvs_("103,105,113", spcstr, &spclen, 11L);
/*  <delete structures from archive> arid, spcstr */
    ndstar (&arid, &spclen, spcstr);
/*  <retrieve structure identifiers> with arid */
/*     to determine actstr = actual list of archived structures */
    nrsid (&arid, &c__100, &actlen, actstr);
#ifndef NO_PROTO
    setmsg_("1 4", "Only the structures explicitly listed as parameters of <"
	    "delete structures from archive> should be deleted from the speci"
	    "fied open archive file.", 3L, 143L);
#else /* NO_PROTO */
    setmsg_("1 4", "Only the structures explicitly listed as parameters of <\
delete structures from archive> should be deleted from the specified open ar\
chive file.", 3L, 143L);
#endif /* NO_PROTO */
/*  pass/fail depending on (actstr = (allstr - spcstr)) */
    setdif_(&alllen, allstr, &spclen, spcstr, &anslen, ansstr);
    L__1 = actlen == anslen && seteq_(&actlen, actstr, ansstr);
    ifpf_(&L__1);
/*  delete structure identifier not in archive */
    setvs_("155", spcstr, &spclen, 3L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    ndstar (&arid, &spclen, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  <retrieve structure identifiers> with arid */
/*     to determine newstr = new list of archived structures */
    nrsid (&arid, &c__100, &newlen, newstr);
#ifndef NO_PROTO
    setmsg_("1 5", "If the specified structure does not exist in the archive"
	    " file, then <delete structures from archive> should result in no"
	    " action for that structure.", 3L, 147L);
#else /* NO_PROTO */
    setmsg_("1 5", "If the specified structure does not exist in the archive\
 file, then <delete structures from archive> should result in no action for \
that structure.", 3L, 147L);
#endif /* NO_PROTO */
/*  pass/fail depending on (newstr = actstr) */
    L__1 = actlen == newlen && seteq_(&newlen, newstr, actstr);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 5", "If the specified structure does not exist in the archive"
	    " file, then <delete structures from archive> should signal error"
	    " 407.", 3L, 125L);
#else /* NO_PROTO */
    setmsg_("1 5", "If the specified structure does not exist in the archive\
 file, then <delete structures from archive> should signal error 407.", 3L, 
	    125L);
#endif /* NO_PROTO */
/*  pass/fail depending on (error = 407) */
    sigtst_(&c__407, &failfl);
/*  delete with structure identifiers both in and not-in archive */
/*  spcstr = 102, 177, 142 */
    setvs_("102,177,142", spcstr, &spclen, 11L);
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    ndstar (&arid, &spclen, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  <retrieve structure identifiers> with arid */
/*     to determine actstr = new list of archived structures */
    nrsid (&arid, &c__100, &actlen, actstr);
#ifndef NO_PROTO
    setmsg_("1 4 5", "If the list of specified structures to be deleted from"
	    " the archive file contains structures that exist and do not exis"
	    "t in the archive file, then those structures that exist should b"
	    "e deleted from the archive and no action is taken for those stru"
	    "ctures that do not exist in the archive file.", 5L, 291L);
#else /* NO_PROTO */
    setmsg_("1 4 5", "If the list of specified structures to be deleted from\
 the archive file contains structures that exist and do not exist in the arc\
hive file, then those structures that exist should be deleted from the archi\
ve and no action is taken for those structures that do not exist in the arch\
ive file.", 5L, 291L);
#endif /* NO_PROTO */
/*  pass/fail depending on (actstr = (newstr - structures 102 and 142)) */

    setvs_("102,142", temstr, &temlen, 7L);
    setdif_(&newlen, newstr, &temlen, temstr, &anslen, ansstr);
    L__1 = actlen == anslen && seteq_(&actlen, actstr, ansstr);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("1 5", "If the list of specified structures to be deleted from t"
	    "he archive file contains structures that do not exist in the arc"
	    "hive file, then error 407 should be signalled.", 3L, 166L);
#else /* NO_PROTO */
    setmsg_("1 5", "If the list of specified structures to be deleted from t\
he archive file contains structures that do not exist in the archive file, t\
hen error 407 should be signalled.", 3L, 166L);
#endif /* NO_PROTO */
/*  pass/fail depending on (error = 407) */
    sigtst_(&c__407, &failfl);
/*  <close archive file> with arid */
    nclarf (&arid);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

