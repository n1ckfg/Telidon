/* setdlg.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

struct {
    real picl, picr, picb, pict, prtl, prtr, prtb, prtt, echl, echr, echb, 
	    echt;
} scrfmt_;

#define scrfmt_1 scrfmt_

/* Table of constant values */

static integer c__4 = 4;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b12 = 0.f;
static real c_b21 = 1.f;
static real c_b28 = .5f;
static real c_b30 = 2.f;
#else /* NO_PROTO */
static real c_b12 = (float)0.;
static real c_b21 = (float)1.;
static real c_b28 = (float).5;
static real c_b30 = (float)2.;
#endif /* NO_PROTO */
static integer c__2 = 2;
static integer c__10 = 10;

#ifndef NO_PROTO
/* Subroutine */ int setdlg_(integer *picstr, integer *dlgstr, integer *txci)
#else /* NO_PROTO */
/* Subroutine */ int setdlg_(picstr, dlgstr, txci)
integer *picstr, *dlgstr, *txci;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real rgbv[15]	/* was [3][5] */ = { 0.f,0.f,0.f,0.f,1.f,.3f,
	    1.f,1.f,.3f,.3f,1.f,1.f,1.f,1.f,1.f };
#else /* NO_PROTO */
    static real rgbv[15]	/* was [3][5] */ = { (float)0.,(float)0.,(
	    float)0.,(float)0.,(float)1.,(float).3,(float)1.,(float)1.,(float)
	    .3,(float).3,(float)1.,(float)1.,(float)1.,(float)1.,(float)1. };
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ia[2];
    static real ra[2];
    static char sa[80*2];
    static integer il, ix, ldr;
    static char msg[300];
    static integer dcun;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqcf (integer *, integer *, integer *, 
	    integer *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqcf ();
#endif /* NO_PROTO */
    static real rdum[9];
#ifndef NO_PROTO
    extern /* Subroutine */ int nscr (integer *, integer *, integer *, real *)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int nscr ();
#endif /* NO_PROTO */
    static real wnlm[4], scrx, scry;
    static integer idum1, idum2, idum3, idum4, idum5, idum6, idum8;
#ifndef NO_PROTO
    extern /* Subroutine */ int nscmd (integer *, integer *), nprec (integer *
	    , integer *, integer *, real *, integer *, integer *, char *, 
	    integer *, integer *, integer *, char *, ftnlen, ftnlen), nqwkc (
	    integer *, integer *, integer *, integer *), nqdsp (integer *, 
	    integer *, integer *, real *, real *, integer *, integer *), 
	    unmsg_(char *, ftnlen), ninst (integer *, integer *, integer *, 
	    char *, integer *, real *, real *, real *, real *, integer *, 
	    char *, ftnlen, ftnlen), nsdus (integer *, integer *, integer *), 
	    nopwk (integer *, integer *, integer *), setvs_(char *, integer *,
	     integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nscmd (), nprec (), nqwkc (), nqdsp (), 
	    unmsg_(), ninst (), nsdus (), nopwk (), setvs_();
#endif /* NO_PROTO */
    static integer wnsiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nswkw (integer *, real *, real *, real *, 
	    real *), nswkv (integer *, real *, real *, real *, real *), 
	    nevmm3 (real *, real *, integer *, real *, real *, real *, real *,
	     real *, real *, integer *, real *), nevom3 (real *, real *, real 
	    *, real *, real *, real *, real *, real *, real *, integer *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nswkw (), nswkv (), nevmm3 (), nevom3 ();
#endif /* NO_PROTO */
    static char datrec[80*10];
#ifndef NO_PROTO
    extern /* Subroutine */ int nsvwr3 (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *), chkinq_(char *, integer 
	    *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsvwr3 (), chkinq_();
#endif /* NO_PROTO */
    static integer colavl, errind, specon, admaxx, admaxy, numcol;
    static real dcmaxx, dcmaxy, vormat[16]	/* was [4][4] */, vmpmat[16]	
	    /* was [4][4] */, vwcplm[6], scrmin;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwksl (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), setrvs_(char *, real *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwksl (), setrvs_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___29 = { 0, msg, 0, "(A,I5)", 300, 1 };


/*  SETDLG performs a number of chores to initialize the workstation */
/*  for interaction with the operator.  It is normally called right */
/*  after <open phigs>.  There are three input parameters: */
/*    PICSTR : structure identifier for the picture to be shown */
/*    DLGSTR : structure identifier for the dialogue area (if used) */
/*    TXCI   : text color index for dialogue text = absolute value */
/*             of TXCI.  If TXCI negative, color table initialization */
/*             is suppressed. */
/*   Example of screen layout set by SETDLG, with dialogue area at right. 
*/
/*   Dialogue area = prompt area + echo area = rectangle at right or */
/*   bottom of screen. */

/*   screen: */
/*   ------------------------------------------- */
/*   |         unused            |             | */
/*   |---------------------------|             | */
/*   |                           |             | */
/*   |                           |   prompt    | */
/*   |                           |             | */
/*   |       picture area        |             | */
/*   |         (square)          |             | */
/*   |                           |             | */
/*   |                           |             | */
/*   |                           |-------------| */
/*   |                           |             | */
/*   |                           |    echo     | */
/*   |                           |             | */
/*   ------------------------------------------- */
/*  COMMON DIALOG variables */
/*  ----------------------- */
/*  DOUTYP* : method of sending interactive output to operator: */
/*            1-Fortran print, 2-PHIGS <message>, 3-PHIGS <text>. */
/*  DINTYP* : method of receiving interactive input from operator: */
/*            1-Fortran read, 2-PHIGS <request string>. */
/*  DSTDNR* : Logical device number for request string */
/*  DSTRID  : Identifier of structure for interactive dialogue */
/*  PSTRID  : Identifier of structure for interactive picture */
/*  DTCLIM* : Maximum number of characters per line for interactive prompt
 */
/* SCRMOD* : Screen mode for operator interaction: 0-interaction off-scree
n,*/
/*            1-dialogue at bottom, 2-dialogue at right, 3-toggle dialogue
 */
/*            and picture on full screen. */
/*  DTXCI   : Dialogue text color index */
/*  SPECWT  : Specific workstation type in which dialogue takes place */
/*  DSIZE*  : For split screen, size of dialogue area as fraction of */
/*            full screen */
/*  EFRAC*  : Fraction of dialogue area for echo, if DINTYP=2 and DOUTYP=3
 */
/*  DYXRAT  : Ratio of height to width of prompt area within dialogue area
 */
/*  SYXRAT  : Ratio of height to width of full screen */
/*  MTRPDC* : Absolute size of DC units = meters per DC unit */
/*  WCPDC   : WC units per DC unit for view #1 (picture) */
/*  QVIS    : Minimum distance assumed to be visually distinguishable, */
/*            in DC units */
/*  *initialized by INITGL */
/*  COMMON SCRFMT (screen format) variables */
/*  ----------------------- */
/*  PICL,PICR,PICB,PICT : NPC bounds of picture area */
/*  PRTL,PRTR,PRTB,PRTT : NPC bounds of prompt area */
/*  ECHL,ECHR,ECHB,ECHT : DC bounds of echo area */
/* modification mode */
/* deferral mode */
/* viewtype */
/* clipping indicator */
/*                noclip      clip */
/* device coordinate units */
/* colour model */
/* colour available */
/*                monochrome  color */
/* USERMOD  default color initialization */
/*                 black        bluish-green pale-yellow */
/*                 sky-blue     white */
/* open workstation */    

    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);

/* save parameters in DIALOG common */
    dialog_1.pstrid = *picstr;
    dialog_1.dstrid = *dlgstr;
    dialog_1.dtxci = abs(*txci);
/*  SETDLG sets up views for picture and prompt as follows: */

/*      PICTURE (view #1)      PROMPT (view #2)       FULL SCREEN (view #3
)*/
/*       x-bounds   y-bounds    x-bounds   y-bounds    x-bounds   y-bounds
 */
/*       --------   --------    --------   --------    --------   --------
 */
/*  WC   0-1        0-1         0-1        0-DYXRAT    0-1        0-SYXRAT
 */
/*  NPC  PICL-PICR  PICB-PICT   PRTL-PRTR  PRTB-PRTT   0-SCRX     0-SCRY 
*/

    nsdus (&globnu_1.wkid, &c__4, &c__0);
    nqwkc (&globnu_1.wkid, &errind, &specon, &dialog_1.specwt);
    chkinq_("pqwkc", &errind, 5L);
    nqdsp (&dialog_1.specwt, &errind, &dcun, &dcmaxx, &dcmaxy, &admaxx, &
	    admaxy);
    chkinq_("pqdsp", &errind, 5L);
    
/* make half-hearted attempt to set up colors 0,1,2,3,4 */
    if (*txci < 0) {
	goto L60;
    }
    nqcf (&dialog_1.specwt, &errind, &idum1, &colavl, &idum2, rdum);
    chkinq_("pqcf", &errind, 4L);
    if (colavl != 1) {
	goto L60;
    }
    nqwksl (&dialog_1.specwt, &errind, &idum1, &idum2, &idum3, &idum4, &idum5,
	     &idum6, &numcol, &idum8);
    chkinq_("pqwksl", &errind, 6L);

    nscmd (&globnu_1.wkid, &c__1);
/* Computing MIN */
    i__2 = 4, i__3 = numcol - 1;
    i__1 = min(i__2,i__3);
    for (ix = 0; ix <= i__1; ++ix) {
	nscr (&globnu_1.wkid, &ix, &c__3, &rgbv[ix * 3]);
/* L50: */
    }
L60:
/* set up workstation transformation to use full screen */
    dialog_1.syxrat = dcmaxy / dcmaxx;
#ifndef NO_PROTO
    if (dialog_1.syxrat > 1.f) {
#else /* NO_PROTO */
    if (dialog_1.syxrat > (float)1.) {
#endif /* NO_PROTO */
/* tall screen */
#ifndef NO_PROTO
	scry = 1.f;
#else /* NO_PROTO */
	scry = (float)1.;
#endif /* NO_PROTO */
	scrx = 1 / dialog_1.syxrat;
    } else {
/* wide screen */
	scry = dialog_1.syxrat;
#ifndef NO_PROTO
	scrx = 1.f;
#else /* NO_PROTO */
	scrx = (float)1.;
#endif /* NO_PROTO */
    }
/* NPC */
    nswkw (&globnu_1.wkid, &c_b12, &scrx, &c_b12, &scry);
/* DC */
    nswkv (&globnu_1.wkid, &c_b12, &dcmaxx, &c_b12, &dcmaxy);
/* default NPC values for picture area = largest square in screen. */
    scrmin = dmin(scrx,scry);
#ifndef NO_PROTO
    scrfmt_1.picl = 0.f;
#else /* NO_PROTO */
    scrfmt_1.picl = (float)0.;
#endif /* NO_PROTO */
    scrfmt_1.picr = scrmin;
#ifndef NO_PROTO
    scrfmt_1.picb = 0.f;
#else /* NO_PROTO */
    scrfmt_1.picb = (float)0.;
#endif /* NO_PROTO */
    scrfmt_1.pict = scrmin;
/* default NPC values for prompt area = whole screen. */
#ifndef NO_PROTO
    scrfmt_1.prtl = 0.f;
#else /* NO_PROTO */
    scrfmt_1.prtl = (float)0.;
#endif /* NO_PROTO */
    scrfmt_1.prtr = scrx;
#ifndef NO_PROTO
    scrfmt_1.prtb = 0.f;
#else /* NO_PROTO */
    scrfmt_1.prtb = (float)0.;
#endif /* NO_PROTO */
    scrfmt_1.prtt = scry;
    if (dialog_1.scrmod == 1) {
/*  dialogue at bottom */
	scrfmt_1.prtt = dialog_1.dsize * scry;
	scrfmt_1.picb = scrfmt_1.prtt;
/* Computing MIN */
	r__1 = scry - scrfmt_1.picb;
	scrfmt_1.picr = dmin(r__1,scrx);
	scrfmt_1.pict = scrfmt_1.picb + scrfmt_1.picr;
    } else if (dialog_1.scrmod == 2) {
/*  dialogue at right */
	scrfmt_1.prtl = (1 - dialog_1.dsize) * scrx;
	scrfmt_1.pict = dmin(scrfmt_1.prtl,scry);
	scrfmt_1.picr = scrfmt_1.pict;
    } else {
/*        SCRMOD .EQ. 0 or 3 - OK as is */
    }
/*  break up dialogue area into prompt/echo areas */
    scrfmt_1.echl = scrfmt_1.prtl;
    scrfmt_1.echr = scrfmt_1.prtr;
    scrfmt_1.echb = scrfmt_1.prtb;
    scrfmt_1.echt = dialog_1.efrac * (scrfmt_1.prtt - scrfmt_1.prtb) + 
	    scrfmt_1.prtb;
    scrfmt_1.prtb = scrfmt_1.echt;
/* ratio of height of prompt area to its width - allows constant */
/* width of 1.0 */
    dialog_1.dyxrat = (scrfmt_1.prtt - scrfmt_1.prtb) / (scrfmt_1.prtr - 
	    scrfmt_1.prtl);
/* set up view #1 for picture */
    nevom3 (&c_b12, &c_b12, &c_b12, &c_b12, &c_b12, &c_b21, &c_b12, &c_b21, &
	    c_b12, &errind, vormat);
    chkinq_("pevom3", &errind, 6L);
    
    setrvs_("0,1,0,1", wnlm, &wnsiz, 7L);
    vwcplm[0] = scrfmt_1.picl;
    vwcplm[1] = scrfmt_1.picr;
    vwcplm[2] = scrfmt_1.picb;
    vwcplm[3] = scrfmt_1.pict;
#ifndef NO_PROTO
    vwcplm[4] = 0.f;
    vwcplm[5] = 1.f;
#else /* NO_PROTO */
    vwcplm[4] = (float)0.;
    vwcplm[5] = (float)1.;
#endif /* NO_PROTO */
    nevmm3 (wnlm, vwcplm, &c__0, &c_b28, &c_b28, &c_b30, &c_b12, &c_b12, &
	    c_b21, &errind, vmpmat);
    chkinq_("pevmm3", &errind, 6L);
    nsvwr3 (&globnu_1.wkid, &c__1, vormat, vmpmat, vwcplm, &c__0, &c__0, &
	    c__0);
/* set up view #2 for prompt */
    wnlm[3] = dialog_1.dyxrat;
    vwcplm[0] = scrfmt_1.prtl;
    vwcplm[1] = scrfmt_1.prtr;
    vwcplm[2] = scrfmt_1.prtb;
    vwcplm[3] = scrfmt_1.prtt;
    r__1 = dialog_1.dyxrat / 2;
    nevmm3 (wnlm, vwcplm, &c__0, &c_b28, &r__1, &c_b21, &c_b12, &c_b12, &
	    c_b21, &errind, vmpmat);
    chkinq_("pevmm3", &errind, 6L);
    nsvwr3 (&globnu_1.wkid, &c__2, vormat, vmpmat, vwcplm, &c__0, &c__0, &
	    c__0);

/* set up view #3 for full screen */
    wnlm[3] = dialog_1.syxrat;
#ifndef NO_PROTO
    vwcplm[0] = 0.f;
#else /* NO_PROTO */
    vwcplm[0] = (float)0.;
#endif /* NO_PROTO */
    vwcplm[1] = scrx;
#ifndef NO_PROTO
    vwcplm[2] = 0.f;
#else /* NO_PROTO */
    vwcplm[2] = (float)0.;
#endif /* NO_PROTO */
    vwcplm[3] = scry;
    r__1 = dialog_1.syxrat / 2;
    nevmm3 (wnlm, vwcplm, &c__0, &c_b28, &r__1, &c_b21, &c_b12, &c_b12, &
	    c_b21, &errind, vmpmat);
    chkinq_("pevmm3", &errind, 6L);
    nsvwr3 (&globnu_1.wkid, &c__3, vormat, vmpmat, vwcplm, &c__0, &c__0, &
	    c__0);

/* L300: */
    if (dialog_1.dintyp == 1) {
/*  input via READ: skip initialization of string device. */
	goto L600;
    } else if (dialog_1.dintyp != 2) {
	s_wsfi(&io___29);
	do_fio(&c__1, "Invalid input type in SETDLG: ", 30L);
	do_fio(&c__1, (char *)&dialog_1.dintyp, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
/* Input to be done via request-string: convert NPC values for */
/* echo area to DC */
    scrfmt_1.echl = dcmaxx * scrfmt_1.echl / scrx;
    scrfmt_1.echr = dcmaxx * scrfmt_1.echr / scrx;
    scrfmt_1.echb = dcmaxy * scrfmt_1.echb / scry;
    scrfmt_1.echt = dcmaxy * scrfmt_1.echt / scry;
/*  pack data record with 72,1, signifying buffer size and edit position 
*/
    setvs_("72,1", ia, &il, 4L);
    nprec (&il, ia, &c__0, ra, &c__0, ia, sa, &c__10, &errind, &ldr, datrec, 
	    80L, 80L);
    chkinq_("pprec", &errind, 5L);
    
/* initialize string device */
    ninst (&globnu_1.wkid, &dialog_1.dstdnr, &c__1, " ", &c__1, &
	    scrfmt_1.echl, &scrfmt_1.echr, &scrfmt_1.echb, &scrfmt_1.echt, &
	    ldr, datrec, 1L, 80L);
    
L600:
/*  compute WC per DC within picture area */
    dialog_1.wcpdc = scrx / (dcmaxx * (scrfmt_1.picr - scrfmt_1.picl));
/*  set "quantum" of visual distinguishability to 2.0 mm, in DC units */
#ifndef NO_PROTO
    dialog_1.qvis = .002f / dialog_1.mtrpdc;
    return 0;
#else /* NO_PROTO */
    dialog_1.qvis = (float).002 / dialog_1.mtrpdc;
#endif /* NO_PROTO */
} /* setdlg_ */

