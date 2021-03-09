/* fort/06/01/02/p09.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__801 = 801;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__106 = 106;
static integer c__102 = 102;
static integer c__3 = 3;
static integer c__6 = 6;
static integer c__2 = 2;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/09                           * */
/*  *    TEST TITLE : Visual effect of modelling            * */
/*  *                 transformation                        * */
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
    static real mscf;
    static integer txci, idum1, idum2, idum3, idum4;
    static real rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_();
#endif /* NO_PROTO */
    static integer ngbox;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqplf (integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    ), nqpmf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *), nclst (void), 
	    nemst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqplf (), nqpmf (), nclst (), nemst ();
#endif /* NO_PROTO */
    static real nomms;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nsvwi (
	    integer *), dchpfv_(char *, integer *, integer *, ftnlen), 
	    chkinq_(char *, integer *, ftnlen), setdlg_(integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nsvwi (), dchpfv_(), 
	    chkinq_(), setdlg_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern integer modtrn_(integer *);
#else /* NO_PROTO */
    extern integer modtrn_();
#endif /* NO_PROTO */
    static integer picstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), setasf_(integer *), 
	    nsmksc (real *), nslwsc (real *), xpopph_(integer *, integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), setasf_(), nsmksc (), nslwsc (), 
	    xpopph_(), setmsg_();
#endif /* NO_PROTO */


/*  Aspect source */
/*                BUNDLED     INDIVIDUAL */
    initgl_("06.01.02/09", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);

/*  Set-up of workstation and dialogue area */
    picstr = 101;
    txci = 1;
    setdlg_(&picstr, &c__801, &txci);
    nopst (&picstr);
/*  By convention, view #1 is for picture */
    nsvwi (&c__1);
/*  Use individual attributes */
    setasf_(&c__1);
/*  Adjust polymarker size */
    nqpmf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqpmf", &errind, 5L);
#ifndef NO_PROTO
    mscf = .02f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    mscf = (float).02 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nsmksc (&mscf);
/*  Adjust polyline width */
    nqplf (&dialog_1.specwt, &c__0, &errind, &idum1, &idum2, &idum3, &nomms, &
	    rdum1, &rdum2, &idum4);
    chkinq_("pqplf", &errind, 5L);
#ifndef NO_PROTO
    mscf = .01f / (nomms * dialog_1.wcpdc);
#else /* NO_PROTO */
    mscf = (float).01 / (nomms * dialog_1.wcpdc);
#endif /* NO_PROTO */
    nslwsc (&mscf);
    nexst (&c__106);
    nexst (&c__102);
    nclst ();
/*  *** *** *** *** ***   3D Transformations    *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("1 8 9 15 16 17", "The modelling coordinates of a 3D polyline sh"
	    "ould be transformed into world coordinates by 3D local and globa"
	    "l modelling transformation.", 14L, 136L);
#else /* NO_PROTO */
    setmsg_("1 8 9 15 16 17", "The modelling coordinates of a 3D polyline sh\
ould be transformed into world coordinates by 3D local and global modelling \
transformation.", 14L, 136L);
#endif /* NO_PROTO */
    ngbox = modtrn_(&c__3);
#ifndef NO_PROTO
    dchpfv_("3D MODELLING TRANSFORMATION: Which box contains something other"
	    " than a single line segment with circled endpoints? ", &c__6, &
	    ngbox, 115L);
#else /* NO_PROTO */
    dchpfv_("3D MODELLING TRANSFORMATION: Which box contains something other\
 than a single line segment with circled endpoints? ", &c__6, &ngbox, 115L);
#endif /* NO_PROTO */
    nemst (&c__102);
    nemst (&c__106);
/*  *** *** *** *** ***   2D Transformations    *** *** *** *** *** */
#ifndef NO_PROTO
    setmsg_("4 8 12 15 16 17 18", "The modelling coordinates of a 3D polylin"
	    "e should be transformed into world coordinates by 2D local and g"
	    "lobal modelling transformation.", 18L, 136L);
#else /* NO_PROTO */
    setmsg_("4 8 12 15 16 17 18", "The modelling coordinates of a 3D polylin\
e should be transformed into world coordinates by 2D local and global modell\
ing transformation.", 18L, 136L);
#endif /* NO_PROTO */
    ngbox = modtrn_(&c__2);
#ifndef NO_PROTO
    dchpfv_("2D MODELLING TRANSFORMATION: Which box contains something other"
	    " than a single line segment with circled endpoints? ", &c__6, &
	    ngbox, 115L);
#else /* NO_PROTO */
    dchpfv_("2D MODELLING TRANSFORMATION: Which box contains something other\
 than a single line segment with circled endpoints? ", &c__6, &ngbox, 115L);
#endif /* NO_PROTO */
/*  Wrap it up. */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

