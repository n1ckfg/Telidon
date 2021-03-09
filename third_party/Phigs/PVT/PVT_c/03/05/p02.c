/* fort/03/05/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
/*  *    TEST NUMBER: 03.05/02                              * */
/*  *    TEST TITLE : Delete structure networks from        * */
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
    static integer dellen, actlen, alllen;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), setdif_(integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclarf (), setdif_();
#endif /* NO_PROTO */
    static integer anslen, spclen, newlen, delstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), avarnm_();
#endif /* NO_PROTO */
    static integer allstr[100], actstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int stdcss_(void), noparf (integer *, integer *), 
	    narast (integer *), ndsnar (integer *, integer *, integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), errctl_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int stdcss_(), noparf (), narast (), ndsnar (), 
	    setmsg_(), errctl_();
#endif /* NO_PROTO */
    static integer ansstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int sigtst_(integer *, logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int sigtst_();
#endif /* NO_PROTO */
    static integer spcstr[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static integer newstr[100];

/*  Declare program-specific variables */
    initgl_("03.05/02", 8L);
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
/*  allstr = all strucutures = 100,101,102,103,104,105,106,107,108,109, */

/*                             110,111,113,114,115,120,130,140,142 */
#ifndef NO_PROTO
    setvs_("100,101,102,103,104,105,106,107,108,109,110,111,113,114,115,120,"
	    "130,140,142", allstr, &alllen, 75L);
#else /* NO_PROTO */
    setvs_("100,101,102,103,104,105,106,107,108,109,110,111,113,114,115,120,\
130,140,142", allstr, &alllen, 75L);
#endif /* NO_PROTO */
/*  spcstr = specified network structures = 107,114,105 */
    setvs_("107,114,105", spcstr, &spclen, 11L);
/*   delstr = deleted network structures = 105,110,114,108,111,115,107,113
 */
    setvs_("105,110,114,108,111,115,107,113", delstr, &dellen, 31L);
/*  <delete structure networks from archive> arid, spcstr */
    ndsnar (&arid, &spclen, spcstr);
/*  <retrieve structure identifiers> with arid */
/*     to determine actstr = actual list of archived structures */
    nrsid (&arid, &c__100, &actlen, actstr);
#ifndef NO_PROTO
    setmsg_("2 4", "Only the structures explicitly listed as parameters of <"
	    "delete structure networks from archive> and their descendants sh"
	    "ould be deleted from the specified open archive file.", 3L, 173L);

#else /* NO_PROTO */
    setmsg_("2 4", "Only the structures explicitly listed as parameters of <\
delete structure networks from archive> and their descendants should be dele\
ted from the specified open archive file.", 3L, 173L);
#endif /* NO_PROTO */
/*  pass/fail depending on (actstr = (allstr - delstr)) */
    setdif_(&alllen, allstr, &dellen, delstr, &anslen, ansstr);
    L__1 = actlen == anslen && seteq_(&actlen, actstr, ansstr);
    ifpf_(&L__1);
/*  delete with a structure network not in archive */
/*  spcstr = 155 */
    setvs_("155", spcstr, &spclen, 3L);
/*  <delete structure networks from archive> arid, spcstr */
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    ndsnar (&arid, &spclen, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  <retrieve structure identifiers> with arid */
/*     to determine newstr = new list of archived structures */
    nrsid (&arid, &c__100, &newlen, newstr);
#ifndef NO_PROTO
    setmsg_("2 5", "If the specified structure does not exist in the archive"
	    " file, then <delete structure networks from archive> should resu"
	    "lt in no action with regards to that structure network.", 3L, 
	    175L);
#else /* NO_PROTO */
    setmsg_("2 5", "If the specified structure does not exist in the archive\
 file, then <delete structure networks from archive> should result in no act\
ion with regards to that structure network.", 3L, 175L);
#endif /* NO_PROTO */
/*  pass/fail depending on (newstr = actstr) */
    L__1 = newlen == actlen && seteq_(&newlen, newstr, actstr);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 5", "If the specified structure does not exist in the archive"
	    " file, then <delete structure networks from archive> should sign"
	    "al error 407.", 3L, 133L);
#else /* NO_PROTO */
    setmsg_("2 5", "If the specified structure does not exist in the archive\
 file, then <delete structure networks from archive> should signal error 407."
	    , 3L, 133L);
#endif /* NO_PROTO */
/*  pass/fail depending on (error = 407) */
    sigtst_(&c__407, &failfl);
/*  delete with structure networks both in and not-in archive */
/*  spcstr = 104, 177, 140 */
    setvs_("104,177,140", spcstr, &spclen, 11L);
/*  delstr = 104, 109, 140, 142 */
    setvs_("104,109,140,142", delstr, &dellen, 15L);
/*  <delete structure networks from archive> arid, spcstr */
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    ndsnar (&arid, &spclen, spcstr);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  <retrieve structure identifiers> with arid */
/*     to determine actstr = new list of archived structures */
    nrsid (&arid, &c__100, &actlen, actstr);
#ifndef NO_PROTO
    setmsg_("2 4 5", "If the list of specified structures to be deleted from"
	    " the archive file contains structure networks that exist and do "
	    "not exist in the archive file, then those structure networks tha"
	    "t exist should be deleted from the archive and no action is take"
	    "n for those structures that do not exist in the archive file.", 
	    5L, 307L);
#else /* NO_PROTO */
    setmsg_("2 4 5", "If the list of specified structures to be deleted from\
 the archive file contains structure networks that exist and do not exist in\
 the archive file, then those structure networks that exist should be delete\
d from the archive and no action is taken for those structures that do not e\
xist in the archive file.", 5L, 307L);
#endif /* NO_PROTO */
/*  pass/fail depending on (actstr = (newstr - delstr)) */
    setdif_(&newlen, newstr, &dellen, delstr, &anslen, ansstr);
    L__1 = actlen == anslen && seteq_(&actlen, actstr, ansstr);
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 5", "If the list of specified structure networks to be delete"
	    "d from the archive file contains structures that do not exist in"
	    " the archive file, then error 407 should be signalled.", 3L, 174L)
	    ;
#else /* NO_PROTO */
    setmsg_("2 5", "If the list of specified structure networks to be delete\
d from the archive file contains structures that do not exist in the archive\
 file, then error 407 should be signalled.", 3L, 174L);
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

