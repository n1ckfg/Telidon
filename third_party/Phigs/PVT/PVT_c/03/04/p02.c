/* fort/03/04/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__112 = 112;
static integer c__104 = 104;
static integer c__110 = 110;
static integer c__105 = 105;
static integer c__102 = 102;
static integer c__108 = 108;
static integer c__113 = 113;
static integer c__103 = 103;
static integer c__109 = 109;
static integer c__114 = 114;
static integer c__101 = 101;
static integer c__119 = 119;
static integer c__106 = 106;
static integer c__107 = 107;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__115 = 115;
static integer c__116 = 116;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 03.04/02                              * */
/*  *    TEST TITLE : Examine conflicting structures        * */
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
    static integer arid;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndas ();
#endif /* NO_PROTO */
    static integer arnm, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nclst (void), nqcst (integer *, integer *, 
	    integer *, integer *, integer *), nexst (integer *), setvs_(char *
	    , integer *, integer *, ftnlen), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical seteq_();
    extern /* Subroutine */ int nclst (), nqcst (), nexst (), setvs_(), 
	    nopst ();
#endif /* NO_PROTO */
    static integer arclen, allcfs[50], alllen, arcncs[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int ndasar (integer *), nclarf (integer *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndasar (), nclarf (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, cssncs[50], csslen, explen, intind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), avarnm_(integer *), 
	    noparf (integer *, integer *), narast (integer *), setmsg_(char *,
	     char *, ftnlen, ftnlen), nqcstn (integer *, integer *, integer *,
	     integer *, integer *, integer *, integer *), xpopph_(integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), avarnm_(), noparf (), narast (), 
	    setmsg_(), nqcstn (), xpopph_();
#endif /* NO_PROTO */
    static integer expstr[50];

/* structure network source */
    initgl_("03.04/02", 8L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/*  open archive file = arid */
    arid = 30;
    avarnm_(&arnm);
    noparf (&arid, &arnm);
/*  set up structures as follows: */

/*     Archive =                         CSS = */
/*     ---------------------             ------------------ */
/*     112   102    103  109             101    102     105 */
/*           / \     |    |               |     /  \     | */
/*         104 105  108  114             119  104  106  107 */
/*           \  |    |                         |  / |    | */
/*             110  113                       110  112  113 */

    nopst (&c__112);
    nclst ();
    nopst (&c__104);
    nexst (&c__110);
    nclst ();
    nopst (&c__105);
    nexst (&c__110);
    nclst ();
    nopst (&c__102);
    nexst (&c__104);
    nexst (&c__105);
    nclst ();
    nopst (&c__108);
    nexst (&c__113);
    nclst ();
    nopst (&c__103);
    nexst (&c__108);
    nclst ();
    nopst (&c__109);
    nexst (&c__114);
    nclst ();
    narast (&arid);
    ndas ();
    nopst (&c__101);
    nexst (&c__119);
    nclst ();
    nopst (&c__104);
    nexst (&c__110);
    nclst ();
    nopst (&c__106);
    nexst (&c__110);
    nexst (&c__112);
    nclst ();
    nopst (&c__102);
    nexst (&c__104);
    nexst (&c__106);
    nclst ();
    nopst (&c__107);
    nexst (&c__113);
    nclst ();
    nopst (&c__105);
    nexst (&c__107);
    nclst ();
/*  *** ***   conflicting networks - root and descendants   *** *** */

    nqcstn (&arid, &c__102, &c__0, &c__0, &errind, &csslen, &idum1);
    chkinq_("pqcstn", &errind, 6L);
    i__1 = csslen;
    for (intind = 1; intind <= i__1; ++intind) {
	nqcstn (&arid, &c__102, &c__0, &intind, &errind, &idum1, &cssncs[
		intind - 1]);
	chkinq_("pqcstn", &errind, 6L);
/* L100: */
    }
#ifndef NO_PROTO
    setmsg_("3", "If the CSS is the structure network source and the specifi"
	    "ed structure also exists and has descendants in the archive file"
	    ", then <inquire conflicting structures in network> should return"
	    " a list of identifiers which exist in both the archive and the C"
	    "SS network whose root is the specified structure.", 1L, 299L);
#else /* NO_PROTO */
    setmsg_("3", "If the CSS is the structure network source and the specifi\
ed structure also exists and has descendants in the archive file, then <inqu\
ire conflicting structures in network> should return a list of identifiers w\
hich exist in both the archive and the CSS network whose root is the specifi\
ed structure.", 1L, 299L);
#endif /* NO_PROTO */
    setvs_("102,104,110,112", expstr, &explen, 15L);
    L__1 = seteq_(&explen, expstr, cssncs) && csslen == explen;
    ifpf_(&L__1);
    nqcstn (&arid, &c__105, &c__1, &c__0, &errind, &arclen, &idum1);
    chkinq_("pqcstn", &errind, 6L);
    i__1 = arclen;
    for (intind = 1; intind <= i__1; ++intind) {
	nqcstn (&arid, &c__105, &c__1, &intind, &errind, &idum1, &arcncs[
		intind - 1]);
	chkinq_("pqcstn", &errind, 6L);
/* L200: */
    }
#ifndef NO_PROTO
    setmsg_("4", "If the archive is the structure network source and the spe"
	    "cified structure also exists and has descendants in the CSS, the"
	    "n <inquire conflicting structures in network> should return a li"
	    "st of identifiers which exist in both the CSS and the archive ne"
	    "twork whose root is the specified structure.", 1L, 294L);
#else /* NO_PROTO */
    setmsg_("4", "If the archive is the structure network source and the spe\
cified structure also exists and has descendants in the CSS, then <inquire c\
onflicting structures in network> should return a list of identifiers which \
exist in both the CSS and the archive network whose root is the specified st\
ructure.", 1L, 294L);
#endif /* NO_PROTO */
    setvs_("105,110", expstr, &explen, 7L);
    L__1 = seteq_(&explen, expstr, arcncs) && arclen == explen;
    ifpf_(&L__1);
/*  *** ***   conflicting networks - descendants only   *** *** */
    nqcstn (&arid, &c__106, &c__0, &c__0, &errind, &csslen, &idum1);
    chkinq_("pqcstn", &errind, 6L);
    i__1 = csslen;
    for (intind = 1; intind <= i__1; ++intind) {
	nqcstn (&arid, &c__106, &c__0, &intind, &errind, &idum1, &cssncs[
		intind - 1]);
	chkinq_("pqcstn", &errind, 6L);
/* L300: */
    }
#ifndef NO_PROTO
    setmsg_("3", "If the CSS is the structure network source and the specifi"
	    "ed structure does not exist in the archive file (but some descen"
	    "dants do), then <inquire conflicting structures in network> shou"
	    "ld return a list of identifiers which exist in both the archive "
	    "and the CSS network whose root is the specified structure.", 1L, 
	    308L);
#else /* NO_PROTO */
    setmsg_("3", "If the CSS is the structure network source and the specifi\
ed structure does not exist in the archive file (but some descendants do), t\
hen <inquire conflicting structures in network> should return a list of iden\
tifiers which exist in both the archive and the CSS network whose root is th\
e specified structure.", 1L, 308L);
#endif /* NO_PROTO */
    setvs_("110,112", expstr, &explen, 7L);
    L__1 = seteq_(&explen, expstr, cssncs) && csslen == explen;
    ifpf_(&L__1);
    nqcstn (&arid, &c__108, &c__1, &c__0, &errind, &arclen, &idum1);
    chkinq_("pqcstn", &errind, 6L);
    i__1 = arclen;
    for (intind = 1; intind <= i__1; ++intind) {
	nqcstn (&arid, &c__108, &c__1, &intind, &errind, &idum1, &arcncs[
		intind - 1]);
	chkinq_("pqcstn", &errind, 6L);
/* L400: */
    }
#ifndef NO_PROTO
    setmsg_("4", "If the archive is the structure network source and the spe"
	    "cified structure does not exist in the CSS (but some descendants"
	    " do), then <inquire conflicting structures in network> should re"
	    "turn a list of identifiers which exist in both the CSS and the a"
	    "rchive network whose root is the specified structure.", 1L, 303L);

#else /* NO_PROTO */
    setmsg_("4", "If the archive is the structure network source and the spe\
cified structure does not exist in the CSS (but some descendants do), then <\
inquire conflicting structures in network> should return a list of identifie\
rs which exist in both the CSS and the archive network whose root is the spe\
cified structure.", 1L, 303L);
#endif /* NO_PROTO */
    setvs_("113", expstr, &explen, 3L);
    L__1 = seteq_(&explen, expstr, arcncs) && arclen == explen;
    ifpf_(&L__1);
/*  *** *** *** ***   non-conflicting networks   *** *** *** *** */
    nqcstn (&arid, &c__101, &c__0, &c__0, &errind, &csslen, &idum1);
    chkinq_("pqcstn", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("3", "If the CSS is the structure network source and the specifi"
	    "ed structure neither exists nor has descendants in the archive f"
	    "ile, then <inquire conflicting structures in network> should ret"
	    "urn an empty list.", 1L, 204L);
#else /* NO_PROTO */
    setmsg_("3", "If the CSS is the structure network source and the specifi\
ed structure neither exists nor has descendants in the archive file, then <i\
nquire conflicting structures in network> should return an empty list.", 1L, 
	    204L);
#endif /* NO_PROTO */
    L__1 = csslen == 0;
    ifpf_(&L__1);
    nqcstn (&arid, &c__109, &c__1, &c__0, &errind, &arclen, &idum1);
    chkinq_("pqcstn", &errind, 6L);
#ifndef NO_PROTO
    setmsg_("4", "If the archive is the structure network source and the spe"
	    "cified structure neither exists nor has descendants in the CSS, "
	    "then <inquire conflicting structures in network> should return a"
	    "n empty list.", 1L, 199L);
#else /* NO_PROTO */
    setmsg_("4", "If the archive is the structure network source and the spe\
cified structure neither exists nor has descendants in the CSS, then <inquir\
e conflicting structures in network> should return an empty list.", 1L, 199L);

#endif /* NO_PROTO */
    L__1 = arclen == 0;
    ifpf_(&L__1);
/*  *** *** *** ***   structures conflict   *** *** *** *** */
    nqcst (&arid, &c__0, &errind, &alllen, &idum1);
    chkinq_("pqcst", &errind, 5L);
    i__1 = alllen;
    for (intind = 1; intind <= i__1; ++intind) {
	nqcst (&arid, &intind, &errind, &idum1, &allcfs[intind - 1]);
	chkinq_("pqcst", &errind, 5L);
/* L700: */
    }
#ifndef NO_PROTO
    setmsg_("2", "If the same structure identifiers exist in both the CSS an"
	    "d archive file, then <inquire all conflicting structures> should"
	    " return a list of all such identifiers.", 1L, 161L);
#else /* NO_PROTO */
    setmsg_("2", "If the same structure identifiers exist in both the CSS an\
d archive file, then <inquire all conflicting structures> should return a li\
st of all such identifiers.", 1L, 161L);
#endif /* NO_PROTO */
    setvs_("102,104,105,110,112,113", expstr, &explen, 23L);
    L__1 = seteq_(&explen, expstr, allcfs) && alllen == explen;
    ifpf_(&L__1);
/*  *** *** *** ***   disjoint structures   *** *** *** *** */
/*  <delete all structures from archive> to ensure empty archive */
/*  clear CSS */
    ndasar (&arid);
    ndas ();
/*  set up archive and CSS as follows: */

/*     Archive =                        CSS = */
/*     -----------------                ------------ */
/*     101   102    103                 112   115 */
/*           / \     |                         /\ */
/*         104 105  108                     114  116 */

    nopst (&c__101);
    nclst ();
    nopst (&c__102);
    nexst (&c__104);
    nexst (&c__105);
    nclst ();
    nopst (&c__103);
    nexst (&c__108);
    nclst ();
    narast (&arid);
    ndas ();
    nopst (&c__112);
    nclst ();
    nopst (&c__115);
    nexst (&c__114);
    nexst (&c__116);
    nclst ();
    nqcst (&arid, &c__0, &errind, &alllen, &idum1);
    chkinq_("pqcst", &errind, 5L);
#ifndef NO_PROTO
    setmsg_("2", "If there are no structure identifiers that exist in both t"
	    "he CSS and archive file, then <inquire all conflicting structure"
	    "s> should return an empty list.", 1L, 153L);
#else /* NO_PROTO */
    setmsg_("2", "If there are no structure identifiers that exist in both t\
he CSS and archive file, then <inquire all conflicting structures> should re\
turn an empty list.", 1L, 153L);
#endif /* NO_PROTO */
    L__1 = alllen == 0;
    ifpf_(&L__1);
/*  close archive file */
    nclarf (&arid);
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

