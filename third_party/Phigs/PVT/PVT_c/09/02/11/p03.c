/* p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__11 = 11;
static integer c__100 = 100;
static real c_b8 = (float).5;
static integer c__101 = 101;
static real c_b13 = (float).3;
static integer c__2 = 2;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c_n1 = -1;
static real c_b26 = (float).1;
static real c_b27 = (float).2;
static integer c__4 = 4;
static integer c__6 = 6;
static integer c__200 = 200;
static integer c__201 = 201;
static integer c__202 = 202;
static real c_b59 = (float).6;
static integer c__10 = 10;
static integer c__3 = 3;
static integer c__301 = 301;
static integer c__302 = 302;
static real c_b77 = (float).9;
static real c_b81 = (float)1.;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.11/03                           * */
/*  *    TEST TITLE : Error indicator = 2202                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
/* Main program */ MAIN__()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy();

    /* Local variables */
    static real ra2[2];
    static integer ees[10], eis[10];
    extern /* Subroutine */ int ntx ();
    static integer ia210[20]	/* was [2][10] */, arnm;
    extern /* Subroutine */ int rels_();
    static integer isiz, idum1;
    static real rdum1;
    extern /* Subroutine */ int riss3_(), endit_(), rqpde_(), rqedr_();
    static integer spath[2]	/* was [2][1] */;
    extern /* Subroutine */ int nqwkc (), nclst (), nopwk (), rqplr_(), 
	    nexst (), setvs_(), nopst (), rqtxx_(), nclarf (), chkinq_();
    static integer errind;
    extern /* Subroutine */ int initgl_();
    static integer specwt;
    extern /* Subroutine */ int avarnm_(), noparf (), rqcstn_(), xpopph_();

    initgl_("09.02.11/03", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "specified enumeration type is out of range", 
           200L, 42L);
    setvs_("2202", errinf_1.experr, &errinf_1.expsiz, 4L);
    s_copy(errchr_1.errsrs, "3", 40L, 1L);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &idum1, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    avarnm_(&arnm);
    noparf (&c__11, &arnm);
    nopst (&c__100);
    ntx (&c_b8, &c_b8, "TEXT100", 7L);
    nexst (&c__101);
    nclst ();
    nopst (&c__101);
    ntx (&c_b13, &c_b13, "TEXT101", 7L);
    nclst ();
    rqcstn_(&c__11, &c__100, &c__2, &c__0, &errind, &idum1, &idum1);
    rqplr_(&globnu_1.wkid, &c__1, &c__2, &errind, &idum1, &rdum1, &idum1);
    rqedr_(&globnu_1.wkid, &c__1, &c_n1, &errind, &idum1, &idum1, &rdum1, &
	    idum1);
    rqtxx_(&specwt, &c__1, &c_b8, &c_b26, &c_b27, &c__4, &c__0, &c__0, "TEXT\
 EXTENT", &errind, ra2, ra2, &rdum1, &rdum1, 11L);
    rqtxx_(&specwt, &c__1, &c_b8, &c_b26, &c_b27, &c__0, &c__4, &c__0, "TEXT\
 EXTENT", &errind, ra2, ra2, &rdum1, &rdum1, 11L);
    rqtxx_(&specwt, &c__1, &c_b8, &c_b26, &c_b27, &c__0, &c__1, &c__6, "TEXT\
 EXTENT", &errind, ra2, ra2, &rdum1, &rdum1, 11L);
    nopst (&c__200);
    ntx (&c_b8, &c_b8, "TEXT200", 7L);
    nexst (&c__201);
    nclst ();
    nopst (&c__201);
    ntx (&c_b13, &c_b13, "TEXT201", 7L);
    nexst (&c__202);
    nclst ();
    nopst (&c__202);
    ntx (&c_b59, &c_b59, "TEXT202", 7L);
    nclst ();
    rqpde_(&c__200, &c__2, &c__2, &c__10, &c__0, &errind, &idum1, &idum1, 
	    ia210);
    setvs_("1,3,8", eis, &isiz, 5L);
    setvs_("2,4", ees, &isiz, 3L);
    rels_(&c__200, &c__1, &c__2, &c__3, eis, &c__2, ees, &errind, &idum1, &
	    idum1);
    nopst (&c__301);
    nexst (&c__302);
    nclst ();
    nopst (&c__302);
    ntx (&c_b77, &c_b13, "TEXT302", 7L);
    nclst ();
    setvs_("301,1", spath, &isiz, 5L);
    riss3_(&c_b81, &c_b81, &c_b81, &c_b26, &c__1, spath, &c__2, &c__1, &c__0, 
	    &idum1, &idum1, &idum1, &idum1, &c__0, &idum1, &idum1, &idum1, &
	    idum1, &c__10, &errind, &idum1, ia210);
    nclarf (&c__11);
    endit_();
} /* MAIN__ */

