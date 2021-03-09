/* e05200.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__2 = 2;
static integer c__0 = 0;
static integer c__10 = 10;
static integer c__100 = 100;
#ifndef NO_PROTO
static real c_b12 = .5f;
#else /* NO_PROTO */
static real c_b12 = (float).5;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int e05200_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05200_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer arf;
    static char msg[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen), ndas (
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx (), ndas ();
#endif /* NO_PROTO */
    static integer arnm, isiz, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqsid (integer *, integer *, integer *, 
	    integer *);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nrsid (integer *, integer *, integer *, 
	    integer *), nclst (void), rarsn_(integer *, integer *, integer *),
	     crest_(void), rarst_(integer *, integer *, integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqsid ();
    extern logical seteq_();
    extern /* Subroutine */ int nrsid (), nclst (), rarsn_(), crest_(), 
	    rarst_();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nopst ();
#endif /* NO_PROTO */
    static integer lstst[100], outst[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), ndasar (integer *), 
	    chkinq_(char *, integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclarf (), ndasar (), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind, numarc;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_();
#endif /* NO_PROTO */
    static integer numcss;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), noparf (integer *, 
	    integer *), tstwan_(logical *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), noparf (), tstwan_();
#endif /* NO_PROTO */

/*   E05200 tests the handling of error 200. */
    s_copy(errchr_1.curcon, "some of specified structures do not exist in CSS"
	    , 200L, 48L);
    s_copy(msg, "it should ignore the non-existent structures.", 100L, 45L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);
    setvs_("200", errinf_1.experr, &errinf_1.expsiz, 3L);
    esetup_(useprm);
    arf = 11;
/*  set up empty archive file */
    avarnm_(&arnm);
    noparf (&arf, &arnm);
    ndasar (&arf);
    lstst[0] = 100;
    lstst[1] = 101;
/*  test <archive structures> */
/*  archive two non-existent structures */
    rarst_(&arf, &c__2, lstst);
/*  check state of archive file and CSS */
    nqsid (&c__0, &errind, &numcss, &idum1);
    chkinq_("pqsid", &errind, 5L);
    nrsid (&arf, &c__10, &numarc, outst);
    L__1 = streq_("O*CO", 4L) && numcss == 0 && numarc == 0;
    tstwan_(&L__1, msg, 100L);
/*  create structure #100 */
    nopst (&c__100);
    ntx (&c_b12, &c_b12, "TEXT", 4L);
    nclst ();
/*  archive one existing and one non-existing structure */
    rarst_(&arf, &c__2, lstst);
/*  check state of archive */
    nrsid (&arf, &c__10, &numarc, outst);
    L__1 = streq_("O*CO", 4L) && numarc == 1 && outst[0] == 100;
    tstwan_(&L__1, msg, 100L);
/*  clear archive and CSS */
    ndas ();
    ndasar (&arf);
/*  test <archive structure networks> */
/*  archive two non-existent structures */
    rarsn_(&arf, &c__2, lstst);
/*  check state of archive file and CSS */
    nqsid (&c__0, &errind, &numcss, &idum1);
    chkinq_("pqsid", &errind, 5L);
    nrsid (&arf, &c__10, &numarc, outst);
    L__1 = streq_("O*CO", 4L) && numcss == 0 && numarc == 0;
    tstwan_(&L__1, msg, 100L);
/*  create structure network #100 - 101 */
    crest_();
/*  archive one existing and one non-existing structure network */
    setvs_("102,100", lstst, &isiz, 7L);
    rarsn_(&arf, &c__2, lstst);
    nrsid (&arf, &c__10, &numarc, outst);
/*  check state of archive */
    setvs_("100,101", lstst, &isiz, 7L);
    L__1 = streq_("O*CO", 4L) && numarc == 2 && seteq_(&c__2, outst, lstst);
    tstwan_(&L__1, msg, 100L);
    nclarf (&arf);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05200_ */

