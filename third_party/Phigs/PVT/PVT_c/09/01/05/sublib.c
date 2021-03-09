/* fort//09/01/05/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__102 = 102;
static integer c__1 = 1;
static integer c_n1 = -1;
static integer c__4 = 4;
static integer c__103 = 103;
static integer c__101 = 101;
#ifndef NO_PROTO
static real c_b115 = -.1f;
static real c_b117 = 1.1f;
static real c_b121 = .001f;
#else /* NO_PROTO */
static real c_b115 = (float)-.1;
static real c_b117 = (float)1.1;
static real c_b121 = (float).001;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.05/e05200                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.05/e05201                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e05201_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05201_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ol, ix, arf, nst;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndas ();
#endif /* NO_PROTO */
    static integer path[20]	/* was [2][10] */, arnm, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int crest_(void);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int nqsid (integer *, integer *, integer *, 
	    integer *);
    extern logical streq_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int crest_();
    extern logical seteq_();
    extern /* Subroutine */ int nqsid ();
    extern logical streq_();
#endif /* NO_PROTO */
    static integer expst[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */
    static integer lstst[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclarf (integer *), ndasar (integer *), 
	    chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclarf (), ndasar (), chkinq_();
#endif /* NO_PROTO */
    static integer pathod, pathdp;
#ifndef NO_PROTO
    extern /* Subroutine */ int rrepde_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rrepde_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), esetup_(integer *), 
	    noparf (integer *, integer *), narast (integer *), rrepan_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), setval_(char *, integer *, 
	    ftnlen), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), esetup_(), noparf (), narast (), 
	    rrepan_(), setval_(), tstign_();
#endif /* NO_PROTO */

/*  E05201 tests the handling of error 201. */
/*   path order */
    s_copy(errchr_1.curcon, "the specified structure does not exist", 200L, 
	    38L);
    setvs_("201", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    esetup_(useprm);
    arf = 11;
/*  set up empty archive file */
    avarnm_(&arnm);
    noparf (&arf, &arnm);
    ndasar (&arf);
/*  create structure network #100 - 101 */
    crest_();
/*  archive all structures */
    narast (&arf);
    pathod = 0;
    pathdp = 0;
/*  retrieve ancestors of non-existent structure */
    rrepan_(&arf, &c__102, &pathod, &pathdp, &c__10, &c__0, &ol, &idum1, path)
	    ;
/*  check that state of CSS is unchanged */
    setval_("101,100", expst, 7L);
    nqsid (&c__0, &errind, &nst, &idum1);
    chkinq_("pqsid", &errind, 5L);
    i__1 = nst;
    for (ix = 1; ix <= i__1; ++ix) {
	nqsid (&ix, &errind, &idum1, &lstst[ix - 1]);
	chkinq_("pqsid", &errind, 5L);
/* L110: */
    }
    L__1 = streq_("O**O", 4L) && nst == 2 && seteq_(&c__2, lstst, expst);
    tstign_(&L__1);
/*  clear archive and CSS */
    ndas ();
    ndasar (&arf);
/*  create structure network #100 - 101 */
    crest_();
/*  archive all structures */
    narast (&arf);
    pathod = 1;
    pathdp = 0;
/*  retrieve descendants of non-existent structure */
    rrepde_(&arf, &c__102, &pathod, &pathdp, &c__10, &c__0, &ol, &idum1, path)
	    ;
/*  check that state of CSS is unchanged */
    setval_("101,100", expst, 7L);
    nqsid (&c__0, &errind, &nst, &idum1);
    chkinq_("pqsid", &errind, 5L);
    i__1 = nst;
    for (ix = 1; ix <= i__1; ++ix) {
	nqsid (&ix, &errind, &idum1, &lstst[ix - 1]);
	chkinq_("pqsid", &errind, 5L);
/* L120: */
    }
    L__1 = streq_("O**O", 4L) && nst == 2 && seteq_(&c__2, lstst, expst);
    tstign_(&L__1);
/*  clear archive and CSS */
    ndas ();
    ndasar (&arf);
    nclarf (&arf);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05201_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.05/e05205                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e05205_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05205_(useprm)
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
    static real xa[2], ya[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), npl (integer *, real *, real 
	    *), nqep (integer *, integer *), nclst (void), nosep (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), npl (), nqep (), nclst (), nosep ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nopst ();
#endif /* NO_PROTO */
    static integer elpnt1, elpnt2;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), enderr_(
	    void);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int rseplb_(integer *), esetup_(integer *), 
	    tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rseplb_(), esetup_(), tstign_();
#endif /* NO_PROTO */

/*  E05205 tests the handling of error 205. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "the specified label does not exist in the open "
	    "structure between the element pointer and the end of the structu"
	    "re", 200L, 113L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "the specified label does not exist in the open \
structure between the element pointer and the end of the structure", 200L, 
	    113L);
#endif /* NO_PROTO */
    setvs_("205", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    esetup_(useprm);
    nopst (&c__100);
#ifndef NO_PROTO
    xa[0] = 0.f;
    xa[1] = .5f;
    ya[0] = 0.f;
    ya[1] = .5f;
#else /* NO_PROTO */
    xa[0] = (float)0.;
    xa[1] = (float).5;
    ya[0] = (float)0.;
    ya[1] = (float).5;
#endif /* NO_PROTO */
    npl (&c__2, xa, ya);
    nqep (&errind, &elpnt1);
    chkinq_("pqep", &errind, 4L);
    rseplb_(&c__1);
    nqep (&errind, &elpnt2);
    chkinq_("pqep", &errind, 4L);
    L__1 = streq_("O*O*", 4L) && elpnt1 == elpnt2;
    tstign_(&L__1);
    nlb (&c__1);
    npl (&c__2, xa, ya);
    nlb (&c__2);
    nosep (&c_n1);
    rseplb_(&c__1);
    nclst ();
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05205_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.05/e05206                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e05206_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05206_(useprm)
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
    static real xa[2], ya[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), npl (integer *, real *, real 
	    *), npm (integer *, real *, real *), nqep (integer *, integer *), 
	    nsep (integer *), nclst (void), nosep (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), npl (), npm (), nqep (), nsep (), 
	    nclst (), nosep ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nopst ();
#endif /* NO_PROTO */
    static integer elpnt1, elpnt2;
#ifndef NO_PROTO
    extern /* Subroutine */ int rdellb_(integer *, integer *), chkinq_(char *,
	     integer *, ftnlen), enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rdellb_(), chkinq_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_();
#endif /* NO_PROTO */

/*  E05206 tests the handling of error 206. */
#ifndef NO_PROTO
    s_copy(errchr_1.curcon, "one or both of the labels does not exist in the"
	    " open structure between the element pointer and the end of the s"
	    "tructure", 200L, 119L);
#else /* NO_PROTO */
    s_copy(errchr_1.curcon, "one or both of the labels does not exist in the\
 open structure between the element pointer and the end of the structure", 
	    200L, 119L);
#endif /* NO_PROTO */
    setvs_("206", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "4", 40L, 1L);
    esetup_(useprm);
#ifndef NO_PROTO
    xa[0] = 0.f;
    ya[0] = .5f;
    xa[1] = 1.f;
    ya[1] = 1.f;
#else /* NO_PROTO */
    xa[0] = (float)0.;
    ya[0] = (float).5;
    xa[1] = (float)1.;
    ya[1] = (float)1.;
#endif /* NO_PROTO */
    nopst (&c__100);
    nqep (&errind, &elpnt1);
    chkinq_("pqep", &errind, 4L);
    rdellb_(&c__1, &c__2);
    nqep (&errind, &elpnt2);
    chkinq_("pqep", &errind, 4L);
    L__1 = streq_("O*O*", 4L) && elpnt1 == elpnt2;
    tstign_(&L__1);
    npl (&c__2, xa, ya);
    nlb (&c__1);
    npm (&c__2, xa, ya);
    nlb (&c__2);
    nosep (&c_n1);
    nqep (&errind, &elpnt1);
    chkinq_("pqep", &errind, 4L);
    rdellb_(&c__1, &c__2);
    nqep (&errind, &elpnt2);
    chkinq_("pqep", &errind, 4L);
    L__1 = streq_("O*O*", 4L) && elpnt1 == elpnt2;
    tstign_(&L__1);
    nsep (&c__0);
    rdellb_(&c__2, &c__4);
    nclst ();
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05206_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.05/e05207                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e05207_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05207_(useprm)
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
    static integer ol, arf, nst;
#ifndef NO_PROTO
    extern /* Subroutine */ int ndas (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ndas ();
#endif /* NO_PROTO */
    static integer path[20]	/* was [2][10] */, arnm, idum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int crest_(void), nqsid (integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int crest_(), nqsid ();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen), 
	    nopst (integer *), nclarf (integer *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
    extern logical streq_();
    extern /* Subroutine */ int setvs_(), nopst (), nclarf (), chkinq_();
#endif /* NO_PROTO */
    static integer pathod, pathdp;
#ifndef NO_PROTO
    extern /* Subroutine */ int rrepde_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     enderr_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int rrepde_(), enderr_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int avarnm_(integer *), esetup_(integer *), 
	    noparf (integer *, integer *), narast (integer *), rrepan_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), tstign_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int avarnm_(), esetup_(), noparf (), narast (), 
	    rrepan_(), tstign_();
#endif /* NO_PROTO */

/*   E05207 tests the handling of error 207. */
/*   path order */
    s_copy(errchr_1.curcon, "the specified path depth is less than zero", 
	    200L, 42L);
    setvs_("207", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "5", 40L, 1L);
    esetup_(useprm);
    arf = 11;
    avarnm_(&arnm);
    noparf (&arf, &arnm);
    crest_();
    narast (&arf);
    ndas ();
    nopst (&c__103);
    pathod = 1;
    pathdp = -1;
    rrepan_(&arf, &c__100, &pathod, &pathdp, &c__10, &c__0, &ol, &idum1, path)
	    ;
/*  check that state of CSS is unchanged */
    nqsid (&c__1, &errind, &nst, &strid);
    chkinq_("pqsid", &errind, 5L);
    L__1 = streq_("O**O", 4L) && nst == 1 && strid == 103;
    tstign_(&L__1);
    pathod = 0;
    pathdp = -100;
    rrepde_(&arf, &c__101, &pathod, &pathdp, &c__10, &c__0, &ol, &idum1, path)
	    ;
/*  check that state of CSS is unchanged */
    nqsid (&c__1, &errind, &nst, &strid);
    chkinq_("pqsid", &errind, 5L);
    L__1 = streq_("O**O", 4L) && nst == 1 && strid == 103;
    tstign_(&L__1);
    nclarf (&arf);
    nclst ();
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05207_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01.05/e05208                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int e05208_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int e05208_(useprm)
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
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
    extern /* Subroutine */ int crest_(void), nclwk (integer *);
    extern logical streq_(char *, ftnlen);
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    setvs_(char *, integer *, integer *, ftnlen), npost (integer *, 
	    integer *, real *), rpost_(integer *, integer *, real *), enderr_(
	    void);
#else /* NO_PROTO */
    extern logical appeq_();
    extern /* Subroutine */ int crest_(), nclwk ();
    extern logical streq_();
    extern /* Subroutine */ int nopwk (), setvs_(), npost (), rpost_(), 
	    enderr_();
#endif /* NO_PROTO */
    static integer errind, number;
    static real orgpri;
#ifndef NO_PROTO
    extern /* Subroutine */ int esetup_(integer *), tstign_(logical *), 
	    nqpost (integer *, integer *, integer *, integer *, integer *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int esetup_(), tstign_(), nqpost ();
#endif /* NO_PROTO */
    static integer postst;

/*   E05208 tests the handling of error 208. */
    s_copy(errchr_1.curcon, "the specified display priority is out of range", 
	    200L, 46L);
    setvs_("208", errinf_1.experr, &errinf_1.expsiz, 3L);
    s_copy(errchr_1.errsrs, "6", 40L, 1L);
    esetup_(useprm);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    crest_();
    npost (&globnu_1.wkid, &c__100, &c_b12);
    rpost_(&globnu_1.wkid, &c__101, &c_b115);
    rpost_(&globnu_1.wkid, &c__101, &c_b117);
    nqpost (&globnu_1.wkid, &c__1, &errind, &number, &postst, &orgpri);
    L__1 = streq_("OO**", 4L) && errind == 0 && number == 1 && postst == 100 
	    && appeq_(&orgpri, &c_b12, &c_b121, &c_b121);
    tstign_(&L__1);
    nclwk (&globnu_1.wkid);
    enderr_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* e05208_ */

