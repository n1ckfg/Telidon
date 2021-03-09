/* fort/06/02/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.02.01/01                           * */
/*  *    TEST TITLE : Behavior of orientation utilities     * */
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
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static real vpnx, vpny, vpnz, vupx, vupy, vupz, vwrx, vwry, vwrz;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static real act3x3[9]	/* was [3][3] */, act4x4[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int eevom_(real *, real *, real *, real *, real *)
	    , inmsg_(char *, ftnlen), nevom (real *, real *, real *, real *, 
	    integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int eevom_(), inmsg_(), nevom ();
#endif /* NO_PROTO */
    static real exp3x3[9]	/* was [3][3] */, exp4x4[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int eevom3_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *), nevom3 (real *, real *,
	     real *, real *, real *, real *, real *, real *, real *, integer *
	    , real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int eevom3_(), nevom3 ();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setmsg_(char *, char 
	    *, ftnlen, ftnlen);
    extern logical trnseq_(integer *, real *, real *);
    extern /* Subroutine */ int xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setmsg_();
    extern logical trnseq_();
    extern /* Subroutine */ int xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___14 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static icilist io___17 = { 0, msg, 0, "(A,I5)", 300, 1 };


/*  Declare program-specific variables */
    initgl_("06.02.01/01", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    setmsg_("1 2 3 4", "<Evaluate view orientation matrix 3> should return a"
	    " correct representation for the transformation to change 3D WC c"
	    "oordinates to 3D VRC coordinates.", 7L, 149L);
#else /* NO_PROTO */
    setmsg_("1 2 3 4", "<Evaluate view orientation matrix 3> should return a\
 correct representation for the transformation to change 3D WC coordinates t\
o 3D VRC coordinates.", 7L, 149L);
#endif /* NO_PROTO */
/*  Set 3D orientation parameters (all WC x-y-z): */
/*    VRP (view reference point) :  -3.24, 37.727,  11.2 */
/*    VPN (view plane normal)    :  62.21, 45.67,  -25.98 */
/*    VUP (view up vector)       : -23.32,  6.868,  -2.22 */
#ifndef NO_PROTO
    vwrx = -3.24f;
    vwry = 37.727f;
    vwrz = 11.2f;
    vpnx = 62.21f;
    vpny = 45.67f;
    vpnz = -25.98f;
    vupx = -23.32f;
    vupy = 6.868f;
    vupz = -2.22f;
#else /* NO_PROTO */
    vwrx = (float)-3.24;
    vwry = (float)37.727;
    vwrz = (float)11.2;
    vpnx = (float)62.21;
    vpny = (float)45.67;
    vpnz = (float)-25.98;
    vupx = (float)-23.32;
    vupy = (float)6.868;
    vupz = (float)-2.22;
#endif /* NO_PROTO */
/*  <Evaluate view orientation matrix 3> returns act4x4 = actual array */
    nevom3 (&vwrx, &vwry, &vwrz, &vpnx, &vpny, &vpnz, &vupx, &vupy, &vupz, &
	    errind, act4x4);
    if (errind == 0) {
/*  Compute exp4x4 = expected array */
	eevom3_(&vwrx, &vwry, &vwrz, &vpnx, &vpny, &vpnz, &vupx, &vupy, &vupz,
		 exp4x4);
	L__1 = trnseq_(&c__4, act4x4, exp4x4);
	ifpf_(&L__1);
    } else {
	fail_();
	s_wsfi(&io___14);
	do_fio(&c__1, "PEVOM3 failed with error code = ", 32L);
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    setmsg_("1 2 5 6", "<Evaluate view orientation matrix> should return a c"
	    "orrect representation for the transformation to change 2D WC coo"
	    "rdinates to 2D VRC coordinates.", 7L, 147L);
#else /* NO_PROTO */
    setmsg_("1 2 5 6", "<Evaluate view orientation matrix> should return a c\
orrect representation for the transformation to change 2D WC coordinates to \
2D VRC coordinates.", 7L, 147L);
#endif /* NO_PROTO */
/*  Set 2D orientation parameters (all WC x-y): */
/*    VRP (view reference point) :  -3.24, 37.727 */
/*    VUP (view up vector)       : -23.32,  0.041 */
#ifndef NO_PROTO
    vwrx = -3.24f;
    vwry = 37.727f;
    vupx = -23.32f;
    vupy = .041f;
#else /* NO_PROTO */
    vwrx = (float)-3.24;
    vwry = (float)37.727;
    vupx = (float)-23.32;
    vupy = (float).041;
#endif /* NO_PROTO */
/*  <Evaluate view orientation matrix> returns act3x3 = actual array */
    nevom (&vwrx, &vwry, &vupx, &vupy, &errind, act3x3);
    if (errind == 0) {
/*  Compute exp3x3 = expected array */
	eevom_(&vwrx, &vwry, &vupx, &vupy, exp3x3);
	L__1 = trnseq_(&c__3, act3x3, exp3x3);
	ifpf_(&L__1);
    } else {
	fail_();
	s_wsfi(&io___17);
	do_fio(&c__1, "PEVOM failed with error code = ", 31L);
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 300L);
    }
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

