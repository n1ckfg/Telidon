/* fort/02/01/02/01/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.02.01/05                        * */
/*  *    TEST TITLE : Unposting structures by deletion      * */
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
    extern /* Subroutine */ int ifpf_(logical *), ndst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), ndst ();
#endif /* NO_PROTO */
    static integer idum1;
    static real rdum1;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    npost (integer *, integer *, real *), nopst (integer *), chkinq_(
	    char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), npost (), nopst (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */
    static integer pstnum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpost (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpost ();
#endif /* NO_PROTO */

/* PHIGS parameter types */
    initgl_("02.01.02.01/05", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
#ifndef NO_PROTO
    setmsg_("4", "Deleting a closed posted structure should cause that struc"
	    "ture to become unposted from the workstation to which it is post"
	    "ed.", 1L, 125L);
#else /* NO_PROTO */
    setmsg_("4", "Deleting a closed posted structure should cause that struc\
ture to become unposted from the workstation to which it is posted.", 1L, 
	    125L);
#endif /* NO_PROTO */
    strid = 25;
#ifndef NO_PROTO
    rdum1 = .02f;
#else /* NO_PROTO */
    rdum1 = (float).02;
#endif /* NO_PROTO */
/* post structure */
    npost (&globnu_1.wkid, &strid, &rdum1);
    ndst (&strid);
/* Use inquire posted structure to determine: */
/*    pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__0, &errind, &pstnum, &idum1, &rdum1);
    chkinq_("pqpost", &errind, 6L);
    L__1 = pstnum == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4", "Deleting an open posted structure should cause that struct"
	    "ure to become unposted from the workstation to which it is poste"
	    "d.", 1L, 124L);
#else /* NO_PROTO */
    setmsg_("4", "Deleting an open posted structure should cause that struct\
ure to become unposted from the workstation to which it is posted.", 1L, 124L)
	    ;
#endif /* NO_PROTO */
    strid = 40;
#ifndef NO_PROTO
    rdum1 = .02f;
#else /* NO_PROTO */
    rdum1 = (float).02;
#endif /* NO_PROTO */
    nopst (&strid);
/* post structure */
    npost (&globnu_1.wkid, &strid, &rdum1);
    ndst (&strid);
/* Use inquire posted structure to determine: */
/*    pstnum = number of posted structures */
    nqpost (&globnu_1.wkid, &c__0, &errind, &pstnum, &idum1, &rdum1);
    chkinq_("pqpost", &errind, 6L);
    L__1 = pstnum == 0;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

