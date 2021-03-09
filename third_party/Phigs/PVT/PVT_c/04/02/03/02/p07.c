/* fort/04/02/03/02/p07.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
#ifndef NO_PROTO
static real c_b32 = 0.f;
#else /* NO_PROTO */
static real c_b32 = (float)0.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b56 = .005f;
#else /* NO_PROTO */
static real c_b56 = (float).005;
#endif /* NO_PROTO */
static integer c__6 = 6;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.03.02/07                        * */
/*  *    TEST TITLE : Character expansion factor support    * */
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
    real r__1, r__2;
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    double log(doublereal), exp(doublereal);
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    double log(), exp();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[300];
    static integer rpr, txi;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer prec;
    static real expi;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static real rexp;
    static integer idum1, idum2, idum3, idum4, idum5;
    static real rdum1, rdum2, hilog;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical appeq_();
#endif /* NO_PROTO */
    static real chexp;
    static integer naexp;
    static real lolog;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqwkc (integer *, 
	    integer *, integer *, integer *), nopwk (integer *, integer *, 
	    integer *), nqtxf (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *, real *
	    , real *, integer *), nqtxr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, integer *), 
	    nstxr (integer *, integer *, integer *, integer *, real *, real *,
	     integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqwkc (), nopwk (), nqtxf (), 
	    nqtxr (), nstxr (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon;
    static real lchexp[3], logval;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static real minexp, maxexp;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    errctl_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), errctl_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___15 = { 0, msg, 0, "(A,A,I6,A,A, 2(E13.4,A))", 300, 1 }
	    ;
    static icilist io___19 = { 0, msg, 0, "(A,E13.4,A,I6,A)", 300, 1 };
    static icilist io___21 = { 0, msg, 0, "(A, E13.4, A, E13.4, A)", 300, 1 };



/* parameters for <inquire workstation connection and type> */
    initgl_("04.02.03.02/07", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
/*  <inquire text facilities> to determine: */
/*     naexp  = number of available character expansion factors */
/*     minexp = minimum character expansion factor */
/*     maxexp = maximum character expansion factor */
    nqtxf (&specwt, &c__1, &errind, &idum1, &idum2, &idum3, &idum4, &rdum1, &
	    rdum2, &naexp, &minexp, &maxexp, &idum5);
    chkinq_("pqtxf", &errind, 5L);
    s_wsfi(&io___15);
    do_fio(&c__1, "Implementation reports number of available character ", 
	    53L);
    do_fio(&c__1, "expansion factors = ", 20L);
    do_fio(&c__1, (char *)&naexp, (ftnlen)sizeof(integer));
    do_fio(&c__1, ";  minimum, maximum ", 20L);
    do_fio(&c__1, "expansion factors = ", 20L);
    do_fio(&c__1, (char *)&minexp, (ftnlen)sizeof(real));
    do_fio(&c__1, ",", 1L);
    do_fio(&c__1, (char *)&maxexp, (ftnlen)sizeof(real));
    do_fio(&c__1, ".", 1L);
    e_wsfi();
    inmsg_(msg, 300L);
#ifndef NO_PROTO
    setmsg_("51", "Maximum character expansion factor should not be less tha"
	    "n the minimum character expansion factor.", 2L, 98L);
#else /* NO_PROTO */
    setmsg_("51", "Maximum character expansion factor should not be less tha\
n the minimum character expansion factor.", 2L, 98L);
#endif /* NO_PROTO */
    L__1 = maxexp >= minexp;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("51 52", "The minimum and maximum character expansion factors sh"
	    "ould be positive.", 5L, 71L);
    L__1 = minexp > 0.f && maxexp > 0.f;
#else /* NO_PROTO */
    setmsg_("51 52", "The minimum and maximum character expansion factors sh\
ould be positive.", 5L, 71L);
    L__1 = minexp > (float)0. && maxexp > (float)0.;
#endif /* NO_PROTO */
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("51 53 55", "The reported number of available character expansio"
	    "n factors should be at least 0.", 8L, 82L);
#else /* NO_PROTO */
    setmsg_("51 53 55", "The reported number of available character expansio\
n factors should be at least 0.", 8L, 82L);
#endif /* NO_PROTO */
    L__1 = naexp >= 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("51 56", "All character expansion factors should be accepted as "
	    "valid.", 5L, 60L);
    if (dabs(minexp) > 1e-37f) {
	lchexp[0] = minexp * .6f;
#else /* NO_PROTO */
    setmsg_("51 56", "All character expansion factors should be accepted as \
valid.", 5L, 60L);
    if (dabs(minexp) > (float)1e-37) {
	lchexp[0] = minexp * (float).6;
#endif /* NO_PROTO */
    } else {
	lchexp[0] = minexp;
    }
#ifndef NO_PROTO
    if (dabs(maxexp) < 1e37f) {
	lchexp[1] = maxexp * 1.6f;
#else /* NO_PROTO */
    if (dabs(maxexp) < (float)1e37) {
	lchexp[1] = maxexp * (float)1.6;
#endif /* NO_PROTO */
    } else {
	lchexp[1] = maxexp;
    }
#ifndef NO_PROTO
    lchexp[2] = -10.f;
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    lchexp[2] = (float)-10.;
    errctl_(&c__1);
#endif /* NO_PROTO */
    prec = 0;
    for (txi = 1; txi <= 3; ++txi) {
	if (txi == 3) {
	    prec = 1;
	}
	nstxr (&globnu_1.wkid, &txi, &c__1, &prec, &lchexp[txi - 1], &c_b32, &
		c__1);
	if (globnu_1.errsig != 0) {
	    fail_();
	    s_wsfi(&io___19);
	    do_fio(&c__1, "Character expansion factor of ", 30L);
	    do_fio(&c__1, (char *)&lchexp[txi - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, " rejected with error code = ", 28L);
	    do_fio(&c__1, (char *)&globnu_1.errsig, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L199;
	}
/* L100: */
    }
    pass_();
L199:
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
/*  inquire as realized (Stroke precision) */
/*  rexp = realized character expansion factor */
#ifndef NO_PROTO
    setmsg_("15 59", "For STROKE precision, any character expansion factor s"
	    "hould be realized as the absolute value of itself.", 5L, 104L);
#else /* NO_PROTO */
    setmsg_("15 59", "For STROKE precision, any character expansion factor s\
hould be realized as the absolute value of itself.", 5L, 104L);
#endif /* NO_PROTO */
    for (txi = 1; txi <= 3; ++txi) {
	nstxr (&globnu_1.wkid, &c__2, &c__1, &c__2, &lchexp[txi - 1], &c_b32, 
		&c__1);
	nqtxr (&globnu_1.wkid, &c__2, &c__1, &errind, &idum1, &idum2, &rexp, &
		rdum1, &idum3);
	chkinq_("pqtxr", &errind, 5L);
	r__2 = (r__1 = lchexp[txi - 1], dabs(r__1));
	if (! appeq_(&rexp, &r__2, &c_b56, &c_b56)) {
	    fail_();
	    s_wsfi(&io___21);
	    do_fio(&c__1, "Character expansion factor set as ", 34L);
	    do_fio(&c__1, (char *)&lchexp[txi - 1], (ftnlen)sizeof(real));
	    do_fio(&c__1, " but realized as ", 17L);
	    do_fio(&c__1, (char *)&rexp, (ftnlen)sizeof(real));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 300L);
	    goto L250;
	}
/* L200: */
    }
    pass_();
L250:
/*  rpr = realized precision */
#ifndef NO_PROTO
    if (dabs(minexp) > 1e-37f) {
	chexp = minexp * .6f;
#else /* NO_PROTO */
    if (dabs(minexp) > (float)1e-37) {
	chexp = minexp * (float).6;
#endif /* NO_PROTO */
    } else {
	chexp = minexp;
    }
    nstxr (&globnu_1.wkid, &c__1, &c__1, &c__0, &chexp, &c_b32, &c__1);
    nqtxr (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, &rpr, &rexp, &rdum1,
	     &idum2);
    chkinq_("pqtxr", &errind, 5L);
/*  check that we have STRING precision */
    if (rpr == 0) {
#ifndef NO_PROTO
	setmsg_("15 54 59", "For font 1 and STRING precision realized direct"
		"ly, the absolute value of all character expansion factors le"
		"ss than the minimum character expansion factor should be rea"
		"lized as the minimum character expansion factor.", 8L, 215L);
#else /* NO_PROTO */
	setmsg_("15 54 59", "For font 1 and STRING precision realized direct\
ly, the absolute value of all character expansion factors less than the mini\
mum character expansion factor should be realized as the minimum character e\
xpansion factor.", 8L, 215L);
#endif /* NO_PROTO */
	L__1 = rexp == minexp;
	ifpf_(&L__1);
    }
    nstxr (&globnu_1.wkid, &c__2, &c__1, &c__1, &chexp, &c_b32, &c__1);
    nqtxr (&globnu_1.wkid, &c__2, &c__1, &errind, &idum1, &rpr, &rexp, &rdum1,
	     &idum2);
    chkinq_("pqtxr", &errind, 5L);
/*  check that we have CHAR precision */
    if (rpr == 1) {
#ifndef NO_PROTO
	setmsg_("15 54 59", "For font 1 and CHAR precision realized directly"
		", the absolute value of all character expansion factors less"
		" than the minimum character expansion factor should be reali"
		"zed as the minimum character expansion factor.", 8L, 213L);
#else /* NO_PROTO */
	setmsg_("15 54 59", "For font 1 and CHAR precision realized directly\
, the absolute value of all character expansion factors less than the minimu\
m character expansion factor should be realized as the minimum character exp\
ansion factor.", 8L, 213L);
#endif /* NO_PROTO */
	L__1 = rexp == minexp;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    if (dabs(maxexp) < 1e37f) {
	chexp = maxexp * 1.6f;
#else /* NO_PROTO */
    if (dabs(maxexp) < (float)1e37) {
	chexp = maxexp * (float)1.6;
#endif /* NO_PROTO */
    } else {
	chexp = maxexp;
    }
    nstxr (&globnu_1.wkid, &c__1, &c__1, &c__0, &chexp, &c_b32, &c__1);
    nqtxr (&globnu_1.wkid, &c__1, &c__1, &errind, &idum1, &rpr, &rexp, &rdum1,
	     &idum2);
    chkinq_("pqtxr", &errind, 5L);
/*  check that we have STRING precision */
    if (rpr == 0) {
#ifndef NO_PROTO
	setmsg_("15 54 59", "For font 1 and STRING precision realized direct"
		"ly, the absolute value of all character expansion factors gr"
		"eater than the maximum character expansion factor should be "
		"realized as the maximum character expansion factor.", 8L, 
		218L);
#else /* NO_PROTO */
	setmsg_("15 54 59", "For font 1 and STRING precision realized direct\
ly, the absolute value of all character expansion factors greater than the m\
aximum character expansion factor should be realized as the maximum characte\
r expansion factor.", 8L, 218L);
#endif /* NO_PROTO */
	L__1 = rexp == maxexp;
	ifpf_(&L__1);
    }
    nstxr (&globnu_1.wkid, &c__2, &c__1, &c__1, &chexp, &c_b32, &c__1);
    nqtxr (&globnu_1.wkid, &c__2, &c__1, &errind, &idum1, &rpr, &rexp, &rdum1,
	     &idum2);
    chkinq_("pqtxr", &errind, 5L);
/*  check that we have CHAR precision */
    if (rpr == 1) {
#ifndef NO_PROTO
	setmsg_("15 54 59", "For font 1 and CHAR precision realized directly"
		", the absolute value of all character expansion factors grea"
		"ter than the maximum character expansion factor should be re"
		"alized as the maximum character expansion factor.", 8L, 216L);

#else /* NO_PROTO */
	setmsg_("15 54 59", "For font 1 and CHAR precision realized directly\
, the absolute value of all character expansion factors greater than the max\
imum character expansion factor should be realized as the maximum character \
expansion factor.", 8L, 216L);
#endif /* NO_PROTO */
	L__1 = rexp == maxexp;
	ifpf_(&L__1);
    }
/*  check that there is a continuous range */
    if (naexp != 0) {
	goto L666;
    }
#ifndef NO_PROTO
    setmsg_("15 55", "For continuous character expansion factors, a characte"
	    "r expansion factor within the min-max range should be realized a"
	    "s itself.", 5L, 127L);
#else /* NO_PROTO */
    setmsg_("15 55", "For continuous character expansion factors, a characte\
r expansion factor within the min-max range should be realized as itself.", 
	    5L, 127L);
#endif /* NO_PROTO */
    lolog = log(minexp);
    hilog = log(maxexp);
    r__1 = hilog;
#ifndef NO_PROTO
    r__2 = (hilog - lolog) / 6.00001f;
#else /* NO_PROTO */
    r__2 = (hilog - lolog) / (float)6.00001;
#endif /* NO_PROTO */
    for (logval = lolog; r__2 < 0 ? logval >= r__1 : logval <= r__1; logval +=
	     r__2) {
	expi = exp(logval);
	nstxr (&globnu_1.wkid, &c__6, &c__1, &c__0, &expi, &c_b32, &c__1);
	nqtxr (&globnu_1.wkid, &c__6, &c__1, &errind, &idum1, &idum2, &rexp, &
		rdum1, &idum3);
	chkinq_("pqtxr", &errind, 5L);
	if (! appeq_(&rexp, &expi, &c_b32, &c_b56)) {
	    fail_();
	    goto L666;
	}
/* L400: */
    }
    pass_();
L666:
/* wrap it up */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

