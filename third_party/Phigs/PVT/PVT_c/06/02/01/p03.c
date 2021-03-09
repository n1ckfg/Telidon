/* fort/06/02/01/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.01/03                           * */
/*  *    TEST TITLE : Behavior of 2D mapping                * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *), endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_(), endit_();
#endif /* NO_PROTO */
    static real act3x3[9]	/* was [3][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int eevmm_(real *, real *, real *), inmsg_(char *,
	     ftnlen), nevmm (real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int eevmm_(), inmsg_(), nevmm ();
#endif /* NO_PROTO */
    static real exp3x3[9]	/* was [3][3] */;
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static real pjvplm[4];
#ifndef NO_PROTO
    extern logical trnseq_(integer *, real *, real *);
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern logical trnseq_();
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */
    static real vwwnlm[4];

    /* Fortran I/O blocks */
    static icilist io___6 = { 0, msg, 0, "(A,I5)", 300, 1 };


/*  Declare program-specific variables */
    initgl_("06.02.01/03", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 2 11 12 13", "<Evaluate view mapping matrix> should return a "
	    "correct representation for the transformation from the view wind"
	    "ow to the 2D projection viewport.", 12L, 144L);
#else /* NO_PROTO */
    setmsg_("1 2 11 12 13", "<Evaluate view mapping matrix> should return a \
correct representation for the transformation from the view window to the 2D\
 projection viewport.", 12L, 144L);
#endif /* NO_PROTO */
/*  Set 2D mapping parameters: */
#ifndef NO_PROTO
    vwwnlm[0] = -23.32f;
    vwwnlm[1] = 35600.f;
    vwwnlm[2] = 2.29f;
    vwwnlm[3] = 2.295f;
    pjvplm[0] = .298f;
    pjvplm[1] = .736f;
    pjvplm[2] = .22f;
    pjvplm[3] = .89f;
#else /* NO_PROTO */
    vwwnlm[0] = (float)-23.32;
    vwwnlm[1] = (float)35600.;
    vwwnlm[2] = (float)2.29;
    vwwnlm[3] = (float)2.295;
    pjvplm[0] = (float).298;
    pjvplm[1] = (float).736;
    pjvplm[2] = (float).22;
    pjvplm[3] = (float).89;
#endif /* NO_PROTO */
/*  <Evaluate view mapping matrix> returns act3x3 = actual array */
    nevmm (vwwnlm, pjvplm, &errind, act3x3);
    if (errind != 0) {
	fail_();
	s_wsfi(&io___6);
	do_fio(&c__1, "Non-zero error code from PEVMM:", 31L);
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 300L);
	goto L666;
    }
/*  Compute exp3x3 = expected array */
    eevmm_(vwwnlm, pjvplm, exp3x3);
/* pass/fail depending on (act3x3 represents same transformation as exp3x3
)*/
    L__1 = trnseq_(&c__3, act3x3, exp3x3);
    ifpf_(&L__1);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

