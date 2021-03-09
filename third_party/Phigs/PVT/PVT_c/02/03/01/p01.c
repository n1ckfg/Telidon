/* fort/02/03/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

#ifndef NO_PROTO
static real c_b2 = .24f;
static real c_b3 = .35f;
#else /* NO_PROTO */
static real c_b2 = (float).24;
static real c_b3 = (float).35;
#endif /* NO_PROTO */
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b7 = .05f;
static real c_b8 = .16f;
static real c_b9 = .2f;
#else /* NO_PROTO */
static real c_b7 = (float).05;
static real c_b8 = (float).16;
static real c_b9 = (float).2;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__50 = 50;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 02.03.01/01                           * */
/*  *    TEST TITLE : Inquire element type and size, and    * */
/*  *                 content when a structure is closed    * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static real xpts[5] = { .02f,.05f,.08f,.11f,.14f };
    static real ypts[5] = { .17f,.2f,.23f,.26f,.29f };
#else /* NO_PROTO */
    static real xpts[5] = { (float).02,(float).05,(float).08,(float).11,(
	    float).14 };
    static real ypts[5] = { (float).17,(float).2,(float).23,(float).26,(float)
	    .29 };
#endif /* NO_PROTO */

    /* System generated locals */
    logical L__1;

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen), fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx (), fail_(), ifpf_();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer rcnt;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer rlsz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nqeco (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *, integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nqeco ();
#endif /* NO_PROTO */
    static integer intar[50], strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst ();
#endif /* NO_PROTO */
    static char strar[30*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqets (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqets ();
#endif /* NO_PROTO */
    static integer lnstr[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static integer intsz, strsz, errind, eltype;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), nschup (real *, real 
	    *), nschsp (real *), setmsg_(char *, char *, ftnlen, ftnlen), 
	    nstxal (integer *, integer *), xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), nschup (), nschsp (), setmsg_(), 
	    nstxal (), xpopph_();
#endif /* NO_PROTO */

/* text alignment horizontal */
/* text alignment vertical */
/* element type */
    initgl_("02.03.01/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    strid = 100;
    nopst (&strid);
    nschup (&c_b2, &c_b3);
    nstxal (&c__1, &c__3);
    npl (&c__5, xpts, ypts);
    nschsp (&c_b7);
    ntx (&c_b8, &c_b9, "PHIGS Validation Tests", 22L);
    nclst ();
#ifndef NO_PROTO
    setmsg_("5", "<Inquire element type and size> should return NIL as the e"
	    "lement type and 0 as the length of all array entry sizes when th"
	    "e specified element position of the closed structure is 0.", 1L, 
	    180L);
#else /* NO_PROTO */
    setmsg_("5", "<Inquire element type and size> should return NIL as the e\
lement type and 0 as the length of all array entry sizes when the specified \
element position of the closed structure is 0.", 1L, 180L);
#endif /* NO_PROTO */
    intsz = -6;
    rlsz = -6;
    strsz = -6;
    nqets (&strid, &c__0, &errind, &eltype, &intsz, &rlsz, &strsz);
    L__1 = errind == 0 && eltype == 1 && intsz == 0 && rlsz == 0 && strsz == 
	    0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6", "<Inquire element content> should return 0 as the length of"
	    " all arrays associated with the data record when the specified e"
	    "lement position of the closed structure is 0.", 1L, 167L);
#else /* NO_PROTO */
    setmsg_("6", "<Inquire element content> should return 0 as the length of\
 all arrays associated with the data record when the specified element posit\
ion of the closed structure is 0.", 1L, 167L);
#endif /* NO_PROTO */
    intsz = -6;
    rlsz = -6;
    strsz = -6;
    nqeco (&strid, &c__0, &c__50, &c__50, &c__50, &errind, &intsz, intar, &
	    rlsz, rlar, &strsz, lnstr, strar, 30L);
    L__1 = errind == 0 && intsz == 0 && rlsz == 0 && strsz == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("4", "<Inquire element type and size> should return polyline as "
	    "the element type and an integer array entry size of 1, real arra"
	    "y entry size of 10, and a string array entry size of 0 for the s"
	    "pecified element of the closed structure.", 1L, 227L);
#else /* NO_PROTO */
    setmsg_("4", "<Inquire element type and size> should return polyline as \
the element type and an integer array entry size of 1, real array entry size\
 of 10, and a string array entry size of 0 for the specified element of the \
closed structure.", 1L, 227L);
#endif /* NO_PROTO */
    strsz = -6;
    nqets (&strid, &c__3, &errind, &eltype, &intsz, &rlsz, &strsz);
    L__1 = errind == 0 && eltype == 3 && intsz == 1 && rlsz == 10 && strsz == 
	    0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("6", "<Inquire element content> should return the appropriate in"
	    "formation contained in the data record associated with polyline,"
	    " the specified element of the closed structure.", 1L, 169L);
#else /* NO_PROTO */
    setmsg_("6", "<Inquire element content> should return the appropriate in\
formation contained in the data record associated with polyline, the specifi\
ed element of the closed structure.", 1L, 169L);
#endif /* NO_PROTO */
    strsz = -6;
    nqeco (&strid, &c__3, &c__50, &c__50, &c__50, &errind, &intsz, intar, &
	    rlsz, rlar, &strsz, lnstr, strar, 30L);
    if (errind == 0 && intsz == 1 && intar[0] == 5 && rlsz == 10 && strsz == 
	    0) {
/* OK so far - test array contents */
	for (rcnt = 1; rcnt <= 10; ++rcnt) {
	    if (rcnt <= 5) {
		if (rlar[rcnt - 1] != xpts[rcnt - 1]) {
		    goto L110;
		}
	    } else {
		if (rlar[rcnt - 1] != ypts[rcnt - 6]) {
		    goto L110;
		}
	    }
/* L100: */
	}
	pass_();
	goto L666;
    }
L110:
    fail_();
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

