/* fort/04/02/05/04/p06.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__100 = 100;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.04/06                        * */
/*  *    TEST TITLE : Pattern color index array             * */
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

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer dx, dy, nce, mci, isc;
    static char msg[300];
    static integer isr, rdx, rdy;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static integer coli, idum1, colia[10000]	/* was [100][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeci (integer *, integer *, integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeci ();
#endif /* NO_PROTO */
    static integer undci;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
    extern logical arreq_(integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *);
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nqpar (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nqwkc (integer *, integer *, integer *, 
	    integer *), nspar (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nopwk (
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
    extern logical arreq_();
    extern /* Subroutine */ int inmsg_(), nqpar (), nqwkc (), nspar (), 
	    nopwk ();
#endif /* NO_PROTO */
    static logical failed;
    static integer rcolia[10000]	/* was [100][100] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon, listel;
#ifndef NO_PROTO
    extern logical patavl_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern logical patavl_();
    extern /* Subroutine */ int initgl_(), setmsg_();
#endif /* NO_PROTO */
    static integer specwt;
#ifndef NO_PROTO
    extern /* Subroutine */ int errctl_(logical *), sigtst_(integer *, 
	    logical *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int errctl_(), sigtst_(), xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___20 = { 0, msg, 0, "(A,I5,A)", 300, 1 };


/* type of returned value */
/* interior style */
/* set up pattern color index array */
    initgl_("04.02.05.04/06", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* open workstation */
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &specon, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    if (! patavl_(&specwt)) {
#ifndef NO_PROTO
	inmsg_("Skipping all tests because pattern interior style is not sup"
		"ported on this workstation.", 87L);
#else /* NO_PROTO */
	inmsg_("Skipping all tests because pattern interior style is not sup\
ported on this workstation.", 87L);
#endif /* NO_PROTO */
	goto L666;
    }
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
/*  <set pattern representation>, index #5, starting at isc=6, isr=4 */
/*  pattern color index array = mci mci */
/*                              mci mci */
    isc = 6;
    isr = 4;
    dx = 2;
    dy = 2;
    colia[305] = mci;
    colia[306] = mci;
    colia[405] = mci;
    colia[406] = mci;
    nspar (&globnu_1.wkid, &c__5, &c__100, &c__100, &isc, &isr, &dx, &dy, 
	    colia);
#ifndef NO_PROTO
    setmsg_("6 20", "<Inquire pattern representation> should report a define"
	    "d pattern color index in the pattern color index array realized "
	    "as itself.", 4L, 129L);
#else /* NO_PROTO */
    setmsg_("6 20", "<Inquire pattern representation> should report a define\
d pattern color index in the pattern color index array realized as itself.", 
	    4L, 129L);
#endif /* NO_PROTO */
/*  <inquire pattern representation>, index #5 to determine */
/*  rcolia = realized pattern color index array */
    nqpar (&globnu_1.wkid, &c__5, &c__1, &c__100, &c__100, &errind, &rdx, &
	    rdy, rcolia);
    chkinq_("pqpar", &errind, 5L);
/* check all entries in rcolia */
    L__1 = dx == rdx && dy == rdy && arreq_(&c__100, &c__100, &isc, &isr, &dx,
	     &dy, colia, rcolia);
    ifpf_(&L__1);
/*  <set pattern representation>, index #5, isc=1, isr=1 */
/*  pattern color index array = undci undci */
/*                              undci undci */
    isc = 1;
    isr = 1;
    colia[0] = undci;
    colia[1] = undci;
    colia[100] = undci;
    colia[1] = undci;
#ifndef NO_PROTO
    errctl_((logical*)&c__1);
#else /* NO_PROTO */
    errctl_(&c__1);
#endif /* NO_PROTO */
    nspar (&globnu_1.wkid, &c__5, &c__100, &c__100, &isc, &isr, &dx, &dy, 
	    colia);
#ifndef NO_PROTO
    errctl_((logical*)&c__0);
    setmsg_("19", "Any non-negative color index specified in the pattern col"
	    "or index array should be accepted as valid.", 2L, 100L);
#else /* NO_PROTO */
    errctl_(&c__0);
    setmsg_("19", "Any non-negative color index specified in the pattern col\
or index array should be accepted as valid.", 2L, 100L);
#endif /* NO_PROTO */
    sigtst_(&c__0, &failed);
    if (failed) {
	s_wsfi(&io___20);
	do_fio(&c__1, "Color set as ", 13L);
	do_fio(&c__1, (char *)&undci, (ftnlen)sizeof(integer));
	do_fio(&c__1, " signalled error.", 17L);
	e_wsfi();
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    setmsg_("6 21", "<Inquire pattern representation> should report an undef"
	    "ined color index in the pattern color index array realized as 1.",
	     4L, 119L);
#else /* NO_PROTO */
    setmsg_("6 21", "<Inquire pattern representation> should report an undef\
ined color index in the pattern color index array realized as 1.", 4L, 119L);
#endif /* NO_PROTO */
/*  <inquire pattern representation>, index #5 to determine */
/*  rcolia = realized pattern color index array */
    nqpar (&globnu_1.wkid, &c__5, &c__1, &c__100, &c__100, &errind, &rdx, &
	    rdy, rcolia);
    chkinq_("pqpar", &errind, 5L);
/* check all entries in rcolia */
    L__1 = rdx == dx && rdy == dy && rcolia[0] == 1 && rcolia[100] == 1 && 
	    rcolia[1] == 1 && rcolia[101] == 1;
    ifpf_(&L__1);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

