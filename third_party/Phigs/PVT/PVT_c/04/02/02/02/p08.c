/* fort/04/02/02/02/p08.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
static integer c__5 = 5;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b8 = 1.f;
#else /* NO_PROTO */
static real c_b8 = (float)1.;
#endif /* NO_PROTO */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.02.02/08                        * */
/*  *    TEST TITLE : Polymarker color index                * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer nce, mci;
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer coli;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer idum1;
    static real rdum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci ();
#endif /* NO_PROTO */
    static integer undci;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer rpmci;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqpmr (integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nopwk (integer *, integer *, integer *), nspmr (integer *, 
	    integer *, integer *, real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nqpmr (), nopwk (), nspmr ();
#endif /* NO_PROTO */
    static logical failed;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, listel;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), errctl_(logical *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), sigtst_(integer *, 
	    logical *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), errctl_(), setmsg_(), sigtst_(), 
	    xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___11 = { 0, msg, 0, "(A,I5,A,I5,A)", 300, 1 };
    static icilist io___13 = { 0, msg, 0, "(A,I5,A)", 300, 1 };
    static icilist io___14 = { 0, msg, 0, "(A,I5,A)", 300, 1 };


/* type of returned value */
    initgl_("04.02.02.02/08", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  loop thru color table to determine mci (maximum defined color index) 
*/
/*  nce = number of color entries */
    nqeci (&globnu_1.wkid, &c__0, &errind, &nce, &idum1);
    chkinq_("pqeci", &errind, 5L);
    mci = -9999;
    i__1 = nce;
    for (listel = 1; listel <= i__1; ++listel) {
	nqeci (&globnu_1.wkid, &listel, &errind, &idum1, &coli);
	chkinq_("pqeci", &errind, 5L);
	if (mci < coli) {
	    mci = coli;
	}
/* L100: */
    }
/*  undci = = undefined color index */
    undci = mci + 1;
/* <set polymarker representation>, index #5, polymarker color index = mci
*/
    nspmr (&globnu_1.wkid, &c__5, &c__1, &c_b8, &mci);
#ifndef NO_PROTO
    setmsg_("15 48 49", "<Inquire polymarker representation> should report a"
	    " defined polymarker colour index realized as itself.", 8L, 103L);
#else /* NO_PROTO */
    setmsg_("15 48 49", "<Inquire polymarker representation> should report a\
 defined polymarker colour index realized as itself.", 8L, 103L);
#endif /* NO_PROTO */
/*  <inquire polymarker representation>, index #5 to determine */
/*  rpmci = realized polymarker color index */
    nqpmr (&globnu_1.wkid, &c__5, &c__1, &errind, &idum1, &rdum1, &rpmci);
    chkinq_("pqpmr", &errind, 5L);
    if (rpmci == mci) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___11);
	do_fio(&c__1, "Color set as ", 13L);
	do_fio(&c__1, (char *)&mci, (ftnlen)sizeof(integer));
	do_fio(&c__1, ", but realized as ", 18L);
	do_fio(&c__1, (char *)&rpmci, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 300L);
    }
/* <set polymarker representation>, index #5, polymarker color index = und
ci*/
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nspmr (&globnu_1.wkid, &c__5, &c__1, &c_b8, &undci);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
#else /* NO_PROTO */
    errctl_(&c__0);
#endif /* NO_PROTO */
    setmsg_("47", "Any non-negative color index should be accepted as valid.",
	     2L, 57L);
    sigtst_(&c__0, &failed);
    if (failed) {
	s_wsfi(&io___13);
	do_fio(&c__1, "Color set as ", 13L);
	do_fio(&c__1, (char *)&undci, (ftnlen)sizeof(integer));
	do_fio(&c__1, " signalled error.", 17L);
	e_wsfi();
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    setmsg_("15 48 50", "<Inquire polymarker representation> should report a"
	    "n undefined polymarker colour index realized as 1.", 8L, 101L);
#else /* NO_PROTO */
    setmsg_("15 48 50", "<Inquire polymarker representation> should report a\
n undefined polymarker colour index realized as 1.", 8L, 101L);
#endif /* NO_PROTO */
/*  <inquire polymarker representation>, index #5 to determine */
/*  rpmci = realized polymarker color index */
    nqpmr (&globnu_1.wkid, &c__5, &c__1, &errind, &idum1, &rdum1, &rpmci);
    chkinq_("pqpmr", &errind, 5L);
    if (rpmci == 1) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___14);
	do_fio(&c__1, "Undefined color index realized as ", 34L);
	do_fio(&c__1, (char *)&rpmci, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 300L);
    }
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

