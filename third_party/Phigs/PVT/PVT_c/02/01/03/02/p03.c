/* fort/02/01/03/02/p03.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.01.03.02/03                        * */
/*  *    TEST TITLE : The effects of <change structure      * */
/*  *                 references> on posted structures      * */
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
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static integer numb;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer orgid, resid, strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopwk (integer *, integer *, integer *), 
	    npost (integer *, integer *, real *), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopwk (), npost (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), ncstrf (integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), ncstrf ();
#endif /* NO_PROTO */
    static real orgpri;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */
    static real respri;
#ifndef NO_PROTO
    extern /* Subroutine */ int stdcss_(void), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int stdcss_(), xpopph_();
#endif /* NO_PROTO */
    static real priort;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpost (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpost ();
#endif /* NO_PROTO */

/*  Declare program-specific variables */
    initgl_("02.01.03.02/03", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
#ifndef NO_PROTO
    setmsg_("5", "When the original and resulting structures are posted then"
	    " <change structure references> should cause the original structu"
	    "re to become unposted and the resulting structure to remain post"
	    "ed with unchanged priority.", 1L, 213L);
#else /* NO_PROTO */
    setmsg_("5", "When the original and resulting structures are posted then\
 <change structure references> should cause the original structure to become\
 unposted and the resulting structure to remain posted with unchanged priori\
ty.", 1L, 213L);
#endif /* NO_PROTO */
    stdcss_();
    orgid = 108;
#ifndef NO_PROTO
    orgpri = .42f;
#else /* NO_PROTO */
    orgpri = (float).42;
#endif /* NO_PROTO */
    resid = 104;
#ifndef NO_PROTO
    respri = .37f;
#else /* NO_PROTO */
    respri = (float).37;
#endif /* NO_PROTO */
    npost (&globnu_1.wkid, &orgid, &orgpri);
    npost (&globnu_1.wkid, &resid, &respri);
    ncstrf (&orgid, &resid);
/*  Use <inquire posted structures> to determine */
/*  numb   = number of posted structures */
/*  strid  = posted structure identifier */
/*  priort = posted structure priority */
    nqpost (&globnu_1.wkid, &c__0, &errind, &numb, &strid, &priort);
    chkinq_("pqpost", &errind, 6L);
    if (numb == 1) {
	nqpost (&globnu_1.wkid, &c__1, &errind, &numb, &strid, &priort);
	chkinq_("pqpost", &errind, 6L);
	L__1 = strid == resid && priort == respri;
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("5", "When the original structure is not posted and the resultin"
	    "g structure is posted then <change structure references> should "
	    "cause the original structure to remain unposted and the resultin"
	    "g structure to remain posted with unchanged priority.", 1L, 239L);

#else /* NO_PROTO */
    setmsg_("5", "When the original structure is not posted and the resultin\
g structure is posted then <change structure references> should cause the or\
iginal structure to remain unposted and the resulting structure to remain po\
sted with unchanged priority.", 1L, 239L);
#endif /* NO_PROTO */
    stdcss_();
    orgid = 108;
#ifndef NO_PROTO
    orgpri = .42f;
#else /* NO_PROTO */
    orgpri = (float).42;
#endif /* NO_PROTO */
    resid = 104;
#ifndef NO_PROTO
    respri = .37f;
#else /* NO_PROTO */
    respri = (float).37;
#endif /* NO_PROTO */
    npost (&globnu_1.wkid, &resid, &respri);
    ncstrf (&orgid, &resid);
/*  Use <inquire posted structures> to determine */
/*  numb   = number of posted structures */
/*  strid  = posted structure identifier */
/*  priort = posted structure priority */
    nqpost (&globnu_1.wkid, &c__0, &errind, &numb, &strid, &priort);
    chkinq_("pqpost", &errind, 6L);
    if (numb == 1) {
	nqpost (&globnu_1.wkid, &c__1, &errind, &numb, &strid, &priort);
	chkinq_("pqpost", &errind, 6L);
	L__1 = strid == resid && priort == respri;
	ifpf_(&L__1);
    } else {
	fail_();
    }
#ifndef NO_PROTO
    setmsg_("6", "When the original structure is posted and the resulting st"
	    "ructure is not posted then <change structure references> should "
	    "cause the original structure to become unposted and the resultin"
	    "g structure to become posted with the priority of the original s"
	    "tructure.", 1L, 259L);
#else /* NO_PROTO */
    setmsg_("6", "When the original structure is posted and the resulting st\
ructure is not posted then <change structure references> should cause the or\
iginal structure to become unposted and the resulting structure to become po\
sted with the priority of the original structure.", 1L, 259L);
#endif /* NO_PROTO */
    stdcss_();
    orgid = 108;
#ifndef NO_PROTO
    orgpri = .42f;
#else /* NO_PROTO */
    orgpri = (float).42;
#endif /* NO_PROTO */
    resid = 104;
#ifndef NO_PROTO
    respri = .37f;
#else /* NO_PROTO */
    respri = (float).37;
#endif /* NO_PROTO */
    npost (&globnu_1.wkid, &orgid, &orgpri);
    ncstrf (&orgid, &resid);
/*  Use <inquire posted structures> to determine */
/*  numb   = number of posted structures */
/*  strid  = posted structure identifier */
/*  priort = posted structure priority */
    nqpost (&globnu_1.wkid, &c__0, &errind, &numb, &strid, &priort);
    chkinq_("pqpost", &errind, 6L);
    if (numb == 1) {
	nqpost (&globnu_1.wkid, &c__1, &errind, &numb, &strid, &priort);
	chkinq_("pqpost", &errind, 6L);
	L__1 = strid == resid && priort == orgpri;
	ifpf_(&L__1);
    } else {
	fail_();
    }
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

