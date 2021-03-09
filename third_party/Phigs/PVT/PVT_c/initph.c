/* fort///initph.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__100 = 100;
static integer c__2 = 2;
static integer c__4 = 4;
static integer c__180 = 180;
static integer c__801 = 801;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 00/initph                             * */
/*  *    TEST TITLE : PVT System Initialization             * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
/*  FILE: INITPH.FOR */
/*  This program is run once, before all the other tests in the system. */
/*  Its only purpose is to initialize a system-configuration file which */
/*  will be used by all subsequent tests to control their operation. */
/*  Dictionary of variables used globally throughout PVT. */

/*  Variable   Type*   Description */
/*  --------   ----    ----------- */
/*  conid      S  I    Connection identifier, for <open workstation> */
/*  ctlhnd     D  I    Tell PERHND whether to abort (0) or return (1) */
/*  dumch      S  C    Dummy character variables for future use */
/*  dumint     S  I    Dummy integer variables for future use */
/*  dumrl      S  R    Dummy real variables for future use */
/*  errind     D  I    Error indicator, returned from inquire functions */
/*  errfil     S  I    PHIGS error file, for <open phigs> */
/*  errsig     D  I    Signalled error code returned by PERHND */
/*  errsw      S  I    Indicates whether to send messages to operator */
/*  funcid     D  C    Function signalling the error, returned by PERHND */
/*  glberr     S  C    Absolute name of global message file */
/*  glblun     S  I    Logical unit number of global message file */
/*  ierrct     D  I    Count of errors detected by test */
/*  iflerr     S  I    Controls writing of messages to message files */
/*  indlun     S  I    Logical unit number of individual message file */
/*  maxlin     S  I    Maximum characters per line in messages */
/*  memun      S  I    Number of memory units, for <open phigs> */
/*  passsw     S  I    Controls writing/suppression of pass-messages */
/*  pident     D  C    Unique program identifier - hierarchical number */
/*  testct     D  I    Count of conditions tested so far within program */
/*  tstmsg     D  C    Text for next condition to be reported. */
/*  unerr      D  I    Count of unanticipated errors detected by test */
/*  wkid       S  I    Workstation id, for <open workstation> */
/*  wtype      S  I    Workstation type, for <open workstation> */
/*  rlseed     S  R    Seed for random number generator */

/*  * S: Static value read from configuration file */
/*    D: Dynamic variable, altered during test execution */

/*    I: Integer */
/*    C: Character */
/*    R: Real */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char sucmsg[48*3] = "Never generate success messages.            "
	    "    " "Always generate success messages.               " "Operat"
	    "or option to generate success messages.   ";
    static char dotmsg[15*3] = "Fortran print  " "PHIGS message  " "PHIGS te"
	    "xt     ";
    static char dinmsg[21*2] = "Fortran read         " "PHIGS request string "
	    ;
    static char dlgloc[7*2] = "bottom." "right. ";
    static char notstr[5] = " not ";
#else /* NO_PROTO */
    static char sucmsg[48*3+1] = "Never generate success messages.          \
      Always generate success messages.               Operator option to gen\
erate success messages.   ";
    static char dotmsg[15*3+1] = "Fortran print  PHIGS message  PHIGS text  \
   ";
    static char dinmsg[21*2+1] = "Fortran read         PHIGS request string ";

    static char dlgloc[7*2+1] = "bottom.right. ";
    static char notstr[5+1] = " not ";
#endif /* NO_PROTO */

    /* Format strings */
    static char fmt_800[] = "(a)";
#ifndef NO_PROTO
    static char fmt_801[] = "(\002 GLOBAL MESSAGE FILE\002,/,\002 .\002,/"
	    ",\002 .\002,/,\002 .\002)";
#else /* NO_PROTO */
    static char fmt_801[] = "(\002 GLOBAL MESSAGE FILE\002,/,\002 .\002,/\
,\002 .\002,/,\002 .\002)";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2], a__2[3];
    integer i__1, i__2[2], i__3[3];
    char ch__1[57], ch__2[56], ch__3[51], ch__4[52], ch__5[61], ch__6[73], 
	    ch__7[50];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_rsle(cilist *), e_rsle(void);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     f_open(olist *), s_wsfe(cilist *), e_wsfe(void), f_clos(cllist *)
	    , f_rew(alist *);
    double sqrt(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsle(), do_lio(), e_wsle(), s_rsle(), e_rsle();
    /* Subroutine */ int s_cat();
    integer s_rsfe(), do_fio(), e_rsfe(), f_open(), s_wsfe(), e_wsfe(), 
	    f_clos(), f_rew();
    double sqrt();
    /* Subroutine */ int s_stop();
    integer s_wsue(), do_uio(), e_wsue(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[5], ya[5];
    static integer ans, iwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer lun, psz, txci, lprt;
    static char rseed[30];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclph (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclph ();
#endif /* NO_PROTO */
    static integer mwkid[100], ioerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk ();
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer maxop, nxtch;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), prsrl_(char *, real *, integer *
	    , ftnlen), nopst (integer *), nsvwi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), prsrl_(), nopst (), nsvwi ();
#endif /* NO_PROTO */
    static integer mconid[100];
    static real rlseed;
#ifndef NO_PROTO
    extern /* Subroutine */ int setdlg_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setdlg_();
#endif /* NO_PROTO */
    static char errmrk[20], prtfil[60], suffix[35];
    static integer nwksav;
    static char sysfil[60];
    static integer ernmsw;
    static char msgdst[40], errprf[30], errsep[60];
    static integer mwtype[100], picstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nerlog (
	    integer *, integer *, integer *), setrvs_(char *, real *, integer 
	    *, ftnlen), drlval_(char *, real *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nerlog (), setrvs_(), drlval_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static cilist io___8 = { 0, 6, 0, 0, 0 };
    static cilist io___9 = { 0, 6, 0, 0, 0 };
    static cilist io___10 = { 0, 6, 0, 0, 0 };
    static cilist io___11 = { 0, 6, 0, 0, 0 };
    static cilist io___12 = { 0, 6, 0, 0, 0 };
    static cilist io___13 = { 0, 6, 0, 0, 0 };
    static cilist io___14 = { 0, 6, 0, 0, 0 };
    static cilist io___15 = { 0, 6, 0, 0, 0 };
    static cilist io___16 = { 0, 6, 0, 0, 0 };
    static cilist io___17 = { 0, 5, 0, 0, 0 };
    static cilist io___18 = { 0, 6, 0, 0, 0 };
    static cilist io___19 = { 0, 6, 0, 0, 0 };
    static cilist io___20 = { 0, 5, 0, 0, 0 };
    static cilist io___21 = { 0, 6, 0, 0, 0 };
    static cilist io___22 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 6, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, 0, 0 };
    static cilist io___25 = { 0, 6, 0, 0, 0 };
    static cilist io___26 = { 0, 5, 0, 0, 0 };
    static cilist io___28 = { 0, 6, 0, 0, 0 };
    static cilist io___29 = { 0, 6, 0, 0, 0 };
    static cilist io___30 = { 0, 6, 0, 0, 0 };
    static cilist io___33 = { 0, 6, 0, 0, 0 };
    static cilist io___34 = { 0, 6, 0, 0, 0 };
    static cilist io___35 = { 0, 6, 0, 0, 0 };
    static cilist io___36 = { 0, 6, 0, 0, 0 };
    static cilist io___38 = { 0, 6, 0, 0, 0 };
    static cilist io___39 = { 0, 6, 0, 0, 0 };
    static cilist io___40 = { 0, 5, 0, 0, 0 };
    static cilist io___42 = { 0, 6, 0, 0, 0 };
    static cilist io___43 = { 0, 5, 0, 0, 0 };
    static cilist io___45 = { 0, 6, 0, 0, 0 };
    static cilist io___46 = { 0, 5, 0, 0, 0 };
    static cilist io___48 = { 0, 6, 0, 0, 0 };
    static cilist io___49 = { 0, 6, 0, 0, 0 };
    static cilist io___50 = { 0, 6, 0, 0, 0 };
    static cilist io___51 = { 0, 6, 0, 0, 0 };
    static cilist io___52 = { 0, 5, 0, 0, 0 };
    static cilist io___53 = { 0, 6, 0, 0, 0 };
    static cilist io___54 = { 0, 6, 0, 0, 0 };
    static cilist io___55 = { 0, 6, 0, 0, 0 };
    static cilist io___56 = { 0, 6, 0, 0, 0 };
    static cilist io___57 = { 0, 5, 0, 0, 0 };
    static cilist io___58 = { 0, 6, 0, 0, 0 };
    static cilist io___59 = { 0, 6, 0, 0, 0 };
    static cilist io___60 = { 0, 6, 0, 0, 0 };
    static cilist io___61 = { 0, 6, 0, 0, 0 };
    static cilist io___62 = { 0, 6, 0, 0, 0 };
    static cilist io___63 = { 0, 6, 0, 0, 0 };
    static cilist io___64 = { 0, 5, 0, 0, 0 };
    static cilist io___65 = { 0, 6, 0, 0, 0 };
    static cilist io___66 = { 0, 6, 0, 0, 0 };
    static cilist io___67 = { 0, 6, 0, 0, 0 };
    static cilist io___68 = { 0, 5, 0, fmt_800, 0 };
    static cilist io___69 = { 0, 6, 0, 0, 0 };
    static cilist io___70 = { 0, 5, 0, 0, 0 };
    static cilist io___72 = { 0, 6, 0, 0, 0 };
    static cilist io___73 = { 0, 0, 0, fmt_801, 0 };
    static cilist io___74 = { 0, 6, 0, 0, 0 };
    static cilist io___75 = { 0, 5, 0, 0, 0 };
    static cilist io___76 = { 0, 6, 0, 0, 0 };
    static cilist io___77 = { 0, 5, 0, 0, 0 };
    static cilist io___78 = { 0, 6, 0, 0, 0 };
    static cilist io___79 = { 0, 6, 0, 0, 0 };
    static cilist io___80 = { 0, 6, 0, 0, 0 };
    static cilist io___81 = { 0, 6, 0, 0, 0 };
    static cilist io___82 = { 0, 5, 0, 0, 0 };
    static cilist io___84 = { 0, 6, 0, 0, 0 };
    static cilist io___85 = { 0, 6, 0, 0, 0 };
    static cilist io___86 = { 0, 6, 0, 0, 0 };
    static cilist io___87 = { 0, 6, 0, 0, 0 };
    static cilist io___88 = { 0, 5, 0, fmt_800, 0 };
    static cilist io___91 = { 0, 6, 0, 0, 0 };
    static cilist io___92 = { 0, 6, 0, 0, 0 };
    static cilist io___93 = { 0, 6, 0, 0, 0 };
    static cilist io___94 = { 0, 6, 0, 0, 0 };
    static cilist io___95 = { 0, 6, 0, 0, 0 };
    static cilist io___96 = { 0, 6, 0, 0, 0 };
    static cilist io___97 = { 0, 6, 0, 0, 0 };
    static cilist io___98 = { 0, 6, 0, 0, 0 };
    static cilist io___99 = { 0, 6, 0, 0, 0 };
    static cilist io___100 = { 0, 5, 0, fmt_800, 0 };
    static cilist io___103 = { 0, 6, 0, 0, 0 };
    static cilist io___104 = { 0, 6, 0, 0, 0 };
    static cilist io___105 = { 0, 6, 0, 0, 0 };
    static cilist io___106 = { 0, 5, 0, 0, 0 };
    static cilist io___108 = { 0, 6, 0, 0, 0 };
    static cilist io___109 = { 0, 6, 0, 0, 0 };
    static cilist io___110 = { 0, 5, 0, 0, 0 };
    static cilist io___111 = { 0, 6, 0, 0, 0 };
    static cilist io___112 = { 0, 5, 0, 0, 0 };
    static cilist io___113 = { 0, 6, 0, 0, 0 };
    static cilist io___114 = { 0, 6, 0, 0, 0 };
    static cilist io___115 = { 0, 5, 0, 0, 0 };
    static cilist io___116 = { 0, 6, 0, 0, 0 };
    static cilist io___117 = { 0, 5, 0, 0, 0 };
    static cilist io___118 = { 0, 6, 0, 0, 0 };
    static cilist io___119 = { 0, 6, 0, 0, 0 };
    static cilist io___120 = { 0, 5, 0, 0, 0 };
    static cilist io___121 = { 0, 6, 0, 0, 0 };
    static cilist io___122 = { 0, 5, 0, 0, 0 };
    static cilist io___123 = { 0, 6, 0, 0, 0 };
    static cilist io___124 = { 0, 5, 0, 0, 0 };
    static cilist io___125 = { 0, 6, 0, 0, 0 };
    static cilist io___126 = { 0, 6, 0, 0, 0 };
    static cilist io___127 = { 0, 6, 0, 0, 0 };
    static cilist io___128 = { 0, 5, 0, 0, 0 };
    static cilist io___129 = { 0, 6, 0, 0, 0 };
    static cilist io___130 = { 0, 5, 0, 0, 0 };
    static cilist io___138 = { 0, 6, 0, 0, 0 };
    static cilist io___139 = { 0, 6, 0, 0, 0 };
    static cilist io___140 = { 1, 0, 0, 0, 0 };
    static cilist io___141 = { 0, 6, 0, 0, 0 };
    static cilist io___142 = { 1, 0, 0, 0, 0 };
    static cilist io___143 = { 0, 6, 0, 0, 0 };
    static cilist io___144 = { 1, 0, 0, 0, 0 };
    static cilist io___145 = { 0, 6, 0, 0, 0 };
    static cilist io___146 = { 1, 0, 0, 0, 0 };
    static cilist io___147 = { 0, 6, 0, 0, 0 };
    static cilist io___148 = { 0, 6, 0, 0, 0 };
    static cilist io___149 = { 0, 6, 0, 0, 0 };
    static cilist io___151 = { 0, 6, 0, 0, 0 };
    static cilist io___152 = { 1, 0, 0, 0, 0 };
    static cilist io___153 = { 1, 0, 0, 0, 0 };
    static cilist io___154 = { 1, 0, 0, 0, 0 };
    static cilist io___155 = { 1, 0, 0, 0, 0 };
    static cilist io___156 = { 1, 0, 0, 0, 0 };
    static cilist io___157 = { 1, 0, 0, 0, 0 };
    static cilist io___158 = { 1, 0, 0, 0, 0 };
    static cilist io___159 = { 1, 0, 0, 0, 0 };
    static cilist io___160 = { 1, 0, 0, 0, 0 };
    static cilist io___161 = { 1, 0, 0, 0, 0 };
    static cilist io___162 = { 1, 0, 0, 0, 0 };
    static cilist io___163 = { 1, 0, 0, 0, 0 };
    static cilist io___164 = { 1, 0, 0, 0, 0 };
    static cilist io___165 = { 1, 0, 0, 0, 0 };
    static cilist io___166 = { 1, 0, 0, 0, 0 };
    static cilist io___167 = { 1, 0, 0, 0, 0 };
    static cilist io___168 = { 1, 0, 0, 0, 0 };
    static cilist io___169 = { 1, 0, 0, 0, 0 };
    static cilist io___170 = { 1, 0, 0, 0, 0 };
    static cilist io___173 = { 1, 0, 0, 0, 0 };
    static cilist io___174 = { 1, 0, 0, 0, 0 };
    static cilist io___175 = { 1, 0, 0, 0, 0 };
    static cilist io___176 = { 1, 0, 0, 0, 0 };
    static cilist io___177 = { 1, 0, 0, 0, 0 };
    static cilist io___178 = { 1, 0, 0, 0, 0 };
    static cilist io___179 = { 1, 0, 0, 0, 0 };
    static cilist io___180 = { 0, 6, 0, 0, 0 };
    static cilist io___181 = { 0, 6, 0, 0, 0 };
    static cilist io___182 = { 0, 6, 0, 0, 0 };


/* definitions for /DIALOG/ variables in SETDLG subroutine */
/* these are the only two variables from the error handling common areas 
*/
/* that need to be set by INITPH: */
/* limit for number of multiple workstations to be tested. */
/* ********************************************************* */

/* USERMOD  NOTE: The following must be initialized to absolute file */
/* USERMOD  name of the system configuration file.  This must be */
/* USERMOD  customized for each installation.  See also the INITGL */
/* USERMOD  and MULTWS subroutines in the subroutine library, which */
/* USERMOD  read the file. */

/* ********************************************************* */
/* real system configuration file */
    s_copy(sysfil, "INITPH.DAT", 60L, 10L);
/* human-readable version */
    s_copy(prtfil, "INITPH.PRT", 60L, 10L);
/* L800: */
    s_wsle(&io___8);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "This program creates a system configuration file w"
	    "hich is", 57L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "This program creates a system configuration file w\
hich is", 57L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___9);
    do_lio(&c__9, &c__1, "used by all subsequent PHIGS validation programs.", 
	    49L);
    e_wsle();
    s_wsle(&io___10);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "Please answer all questions carefully.  All respon"
	    "ses should", 60L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "Please answer all questions carefully.  All respon\
ses should", 60L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___11);
    do_lio(&c__9, &c__1, "be in the format of an integer, except as noted.", 
	    48L);
    e_wsle();
    s_wsle(&io___12);
    do_lio(&c__9, &c__1, " ", 1L);
    e_wsle();
    s_wsle(&io___13);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "*** *** *** *** *** *** *** *** *** *** *** *** **"
	    "* *** *** ", 60L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "*** *** *** *** *** *** *** *** *** *** *** *** **\
* *** *** ", 60L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___14);
    do_lio(&c__9, &c__1, " ", 1L);
    e_wsle();
    s_wsle(&io___15);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "PHIGS-error-file number to be passed to <open phig"
	    "s>", 52L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "PHIGS-error-file number to be passed to <open phig\
s>", 52L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___16);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "(must be a readable file, do not route to printer)"
	    " ?", 52L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "(must be a readable file, do not route to printer)\
 ?", 52L);
#endif /* NO_PROTO */
    e_wsle();
    s_rsle(&io___17);
    do_lio(&c__3, &c__1, (char *)&globnu_1.errfil, (ftnlen)sizeof(integer));
    e_rsle();
    s_wsle(&io___18);
    do_lio(&c__9, &c__1, "Memory units to be passed to <open phigs>", 41L);
    e_wsle();
    s_wsle(&io___19);
    do_lio(&c__9, &c__1, "(-1 to use implementation-defined value)?", 41L);
    e_wsle();
    s_rsle(&io___20);
    do_lio(&c__3, &c__1, (char *)&globnu_1.memun, (ftnlen)sizeof(integer));
    e_rsle();
L15:
    s_wsle(&io___21);
    do_lio(&c__9, &c__1, "Enter the number of accessible workstations for", 
	    47L);
    e_wsle();
    s_wsle(&io___22);
    do_lio(&c__9, &c__1, "this implementation.  (To be accessible, it is", 
	    46L);
    e_wsle();
    s_wsle(&io___23);
    do_lio(&c__9, &c__1, "required only that a successful open may be", 43L);
    e_wsle();
    s_wsle(&io___24);
    do_lio(&c__9, &c__1, "performed on the workstation, NOT that all the", 
	    46L);
    e_wsle();
    s_wsle(&io___25);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "accessible workstations may be opened simultaneous"
	    "ly.)", 54L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "accessible workstations may be opened simultaneous\
ly.)", 54L);
#endif /* NO_PROTO */
    e_wsle();
    s_rsle(&io___26);
    do_lio(&c__3, &c__1, (char *)&maxop, (ftnlen)sizeof(integer));
    e_rsle();
    if (maxop < 1) {
	s_wsle(&io___28);
	do_lio(&c__9, &c__1, "Must allow at least 1 open workstation.", 39L);
	e_wsle();
	goto L15;
    }
    if (maxop > 100) {
	s_wsle(&io___29);
	do_lio(&c__9, &c__1, "Will store information about 1st ", 33L);
	do_lio(&c__3, &c__1, (char *)&c__100, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, " workstations.", 14L);
	e_wsle();
	s_wsle(&io___30);
	do_lio(&c__9, &c__1, " ", 1L);
	e_wsle();
	nwksav = 100;
    } else {
	nwksav = maxop;
    }
    s_copy(suffix, " to be passed to open_workstation?", 35L, 34L);
    s_wsle(&io___33);
    do_lio(&c__9, &c__1, "Workstation #1 is the default workstation for all", 
	    49L);
    e_wsle();
    s_wsle(&io___34);
    do_lio(&c__9, &c__1, "the PHIGS tests which use a single non-metafile", 
	    47L);
    e_wsle();
    s_wsle(&io___35);
    do_lio(&c__9, &c__1, "workstation.  Other workstations (2 - n) are used", 
	    49L);
    e_wsle();
    s_wsle(&io___36);
    do_lio(&c__9, &c__1, "for multiple-workstation tests.", 31L);
    e_wsle();
    i__1 = nwksav;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	s_wsle(&io___38);
	do_lio(&c__9, &c__1, "----- For workstation #", 23L);
	do_lio(&c__3, &c__1, (char *)&iwk, (ftnlen)sizeof(integer));
	do_lio(&c__9, &c__1, ":", 1L);
	e_wsle();
	s_wsle(&io___39);
/* Writing concatenation */
	i__2[0] = 22, a__1[0] = "Workstation identifier";
	i__2[1] = 35, a__1[1] = suffix;
	s_cat(ch__1, a__1, i__2, &c__2, 57L);
	do_lio(&c__9, &c__1, ch__1, 57L);
	e_wsle();
	s_rsle(&io___40);
	do_lio(&c__3, &c__1, (char *)&mwkid[iwk - 1], (ftnlen)sizeof(integer))
		;
	e_rsle();
	s_wsle(&io___42);
/* Writing concatenation */
	i__2[0] = 21, a__1[0] = "Connection identifier";
	i__2[1] = 35, a__1[1] = suffix;
	s_cat(ch__2, a__1, i__2, &c__2, 56L);
	do_lio(&c__9, &c__1, ch__2, 56L);
	e_wsle();
	s_rsle(&io___43);
	do_lio(&c__3, &c__1, (char *)&mconid[iwk - 1], (ftnlen)sizeof(integer)
		);
	e_rsle();
	s_wsle(&io___45);
/* Writing concatenation */
	i__2[0] = 16, a__1[0] = "Workstation type";
	i__2[1] = 35, a__1[1] = suffix;
	s_cat(ch__3, a__1, i__2, &c__2, 51L);
	do_lio(&c__9, &c__1, ch__3, 51L);
	e_wsle();
	s_rsle(&io___46);
	do_lio(&c__3, &c__1, (char *)&mwtype[iwk - 1], (ftnlen)sizeof(integer)
		);
	e_rsle();
/* L20: */
    }
    globnu_1.wkid = mwkid[0];
    globnu_1.conid = mconid[0];
    globnu_1.wtype = mwtype[0];
L100:
    s_wsle(&io___48);
    do_lio(&c__9, &c__1, "Indicate whether run-time messages are to be ", 45L)
	    ;
    do_lio(&c__9, &c__1, "generated for successful handling of conditions.", 
	    48L);
    e_wsle();
    s_wsle(&io___49);
/* Writing concatenation */
    i__2[0] = 4, a__1[0] = "0 - ";
    i__2[1] = 48, a__1[1] = sucmsg;
    s_cat(ch__4, a__1, i__2, &c__2, 52L);
    do_lio(&c__9, &c__1, ch__4, 52L);
    e_wsle();
    s_wsle(&io___50);
/* Writing concatenation */
    i__2[0] = 4, a__1[0] = "1 - ";
    i__2[1] = 48, a__1[1] = sucmsg + 48;
    s_cat(ch__4, a__1, i__2, &c__2, 52L);
    do_lio(&c__9, &c__1, ch__4, 52L);
    e_wsle();
    s_wsle(&io___51);
/* Writing concatenation */
    i__2[0] = 4, a__1[0] = "2 - ";
    i__2[1] = 48, a__1[1] = sucmsg + 96;
    s_cat(ch__4, a__1, i__2, &c__2, 52L);
    do_lio(&c__9, &c__1, ch__4, 52L);
    e_wsle();
    s_rsle(&io___52);
    do_lio(&c__3, &c__1, (char *)&globnu_1.passsw, (ftnlen)sizeof(integer));
    e_rsle();
    if (globnu_1.passsw < 0 || globnu_1.passsw > 2) {
	s_wsle(&io___53);
	do_lio(&c__9, &c__1, "Invalid response - re-enter.", 28L);
	e_wsle();
	goto L100;
    }
L200:
    s_wsle(&io___54);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "Indicate whether run-time messages are to be sent "
	    "to ", 53L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "Indicate whether run-time messages are to be sent \
to ", 53L);
#endif /* NO_PROTO */
    do_lio(&c__9, &c__1, "the operator.", 13L);
    e_wsle();
    s_wsle(&io___55);
    do_lio(&c__9, &c__1, "0 - Do not send messages to operator.", 37L);
    e_wsle();
    s_wsle(&io___56);
    do_lio(&c__9, &c__1, "1 - Send messages to operator.", 30L);
    e_wsle();
    s_rsle(&io___57);
    do_lio(&c__3, &c__1, (char *)&globnu_1.errsw, (ftnlen)sizeof(integer));
    e_rsle();
    if (globnu_1.errsw < 0 || globnu_1.errsw > 1) {
	s_wsle(&io___58);
	do_lio(&c__9, &c__1, "Invalid response - re-enter.", 28L);
	e_wsle();
	goto L200;
    }
L300:
    s_wsle(&io___59);
    do_lio(&c__9, &c__1, "Indicate which files are destinations for ", 42L);
    do_lio(&c__9, &c__1, "run-time messages.", 18L);
    e_wsle();
    s_wsle(&io___60);
    do_lio(&c__9, &c__1, "0 - Do not send messages to any file.", 37L);
    e_wsle();
    s_wsle(&io___61);
    do_lio(&c__9, &c__1, "1 - Append messages to end of global file.", 42L);
    e_wsle();
    s_wsle(&io___62);
    do_lio(&c__9, &c__1, "2 - Send messages to program-specific file.", 43L);
    e_wsle();
    s_wsle(&io___63);
    do_lio(&c__9, &c__1, "3 - Both 1 and 2.", 17L);
    e_wsle();
    s_rsle(&io___64);
    do_lio(&c__3, &c__1, (char *)&globnu_1.iflerr, (ftnlen)sizeof(integer));
    e_rsle();
    if (globnu_1.iflerr < 0 || globnu_1.iflerr > 3) {
	s_wsle(&io___65);
	do_lio(&c__9, &c__1, "Invalid response - re-enter.", 28L);
	e_wsle();
	goto L300;
    }
/* default units */
    globnu_1.glblun = 21;
    globnu_1.indlun = 22;
    if (globnu_1.iflerr == 1 || globnu_1.iflerr == 3) {
/* set up global message file */
/* name of global message file */
	s_wsle(&io___66);
	do_lio(&c__9, &c__1, "Absolute file name for the global message file",
		 46L);
	e_wsle();
	s_wsle(&io___67);
	do_lio(&c__9, &c__1, "(Character input, not integer)?", 31L);
	e_wsle();
	s_rsfe(&io___68);
	do_fio(&c__1, globch_1.glberr, 60L);
	e_rsfe();
	s_wsle(&io___69);
	do_lio(&c__9, &c__1, "Logical unit number to be used for ", 35L);
	do_lio(&c__9, &c__1, "global message file?", 20L);
	e_wsle();
	s_rsle(&io___70);
	do_lio(&c__3, &c__1, (char *)&globnu_1.glblun, (ftnlen)sizeof(integer)
		);
	e_rsle();
/* create global message file */
	o__1.oerr = 1;
	o__1.ounit = globnu_1.glblun;
	o__1.ofnmlen = 60;
	o__1.ofnm = globch_1.glberr;
	o__1.orl = 0;
	o__1.osta = "NEW";
	o__1.oacc = 0;
	o__1.ofm = "FORMATTED";
	o__1.oblnk = 0;
	ioerr = f_open(&o__1);
	if (ioerr != 0) {
	    s_wsle(&io___72);
#ifndef NO_PROTO
	    do_lio(&c__9, &c__1, "Abort.  Error code for OPEN of global mess"
		    "age ", 46L);
#else /* NO_PROTO */
	    do_lio(&c__9, &c__1, "Abort.  Error code for OPEN of global mess\
age ", 46L);
#endif /* NO_PROTO */
	    do_lio(&c__9, &c__1, "file = ", 7L);
	    do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    e_wsle();
	    goto L666;
	}
	io___73.ciunit = globnu_1.glblun;
	s_wsfe(&io___73);
	e_wsfe();
	cl__1.cerr = 0;
	cl__1.cunit = globnu_1.glblun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (globnu_1.iflerr == 2 || globnu_1.iflerr == 3) {
/* set up individual message file */
	s_wsle(&io___74);
	do_lio(&c__9, &c__1, "Logical unit number to be used for ", 35L);
	do_lio(&c__9, &c__1, "individual message file?", 24L);
	e_wsle();
	s_rsle(&io___75);
	do_lio(&c__3, &c__1, (char *)&globnu_1.indlun, (ftnlen)sizeof(integer)
		);
	e_rsle();
    }
L400:
    s_wsle(&io___76);
    do_lio(&c__9, &c__1, "Maximum characters per line in messages (40-300)?", 
	    49L);
    e_wsle();
    s_rsle(&io___77);
    do_lio(&c__3, &c__1, (char *)&globnu_1.maxlin, (ftnlen)sizeof(integer));
    e_rsle();
    if (globnu_1.maxlin < 40 || globnu_1.maxlin > 300) {
	s_wsle(&io___78);
	do_lio(&c__9, &c__1, "Response out of range - re-enter.", 33L);
	e_wsle();
	goto L400;
    }
/* set up for error handling */
L404:
    s_wsle(&io___79);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "Indicate whether the implementation allows the err"
	    "or ", 53L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "Indicate whether the implementation allows the err\
or ", 53L);
#endif /* NO_PROTO */
    do_lio(&c__9, &c__1, "file to be ", 11L);
    e_wsle();
    s_wsle(&io___80);
    do_lio(&c__9, &c__1, "explicitly opened and named by the application ", 
	    47L);
    do_lio(&c__9, &c__1, "program prior to ", 17L);
    e_wsle();
    s_wsle(&io___81);
    do_lio(&c__9, &c__1, "execution of <open phigs>: 1-yes, 2-no.", 39L);
    e_wsle();
    s_rsle(&io___82);
    do_lio(&c__3, &c__1, (char *)&ernmsw, (ftnlen)sizeof(integer));
    e_rsle();
    if (ernmsw < 1 || ernmsw > 2) {
	s_wsle(&io___84);
	do_lio(&c__9, &c__1, "Invalid response - re-enter.", 28L);
	e_wsle();
	goto L404;
    }
    s_wsle(&io___85);
    do_lio(&c__9, &c__1, "If the error messages written by the system error ",
	     50L);
    do_lio(&c__9, &c__1, "handler all ", 12L);
    e_wsle();
    s_wsle(&io___86);
    do_lio(&c__9, &c__1, "contain a special string by which they can be ", 
	    46L);
    do_lio(&c__9, &c__1, "individuated ", 13L);
    e_wsle();
    s_wsle(&io___87);
    do_lio(&c__9, &c__1, "(such as \"%PHIGS-ERROR:\"), enter that string.  ", 
	    47L);
    do_lio(&c__9, &c__1, "If not, enter blanks.", 21L);
    e_wsle();
    s_rsfe(&io___88);
    do_fio(&c__1, errmrk, 20L);
    e_rsfe();
/* write out error message to serve as separator of function invocations 
*/
    if (ernmsw == 1) {
	s_copy(errsep, "errsep.erf", 60L, 10L);
	o__1.oerr = 1;
	o__1.ounit = globnu_1.errfil;
	o__1.ofnmlen = 60;
	o__1.ofnm = errsep;
	o__1.orl = 0;
	o__1.osta = "UNKNOWN";
	o__1.oacc = 0;
	o__1.ofm = "FORMATTED";
	o__1.oblnk = 0;
	ioerr = f_open(&o__1);
	if (ioerr != 0) {
	    s_wsle(&io___91);
	    do_lio(&c__9, &c__1, "Abort.  Error code for ", 23L);
	    do_lio(&c__9, &c__1, errsep, 60L);
	    do_lio(&c__9, &c__1, " OPEN = ", 8L);
	    do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    e_wsle();
	    goto L666;
	}
	al__1.aerr = 0;
	al__1.aunit = globnu_1.errfil;
	f_rew(&al__1);
    } else {
	s_wsle(&io___92);
	do_lio(&c__9, &c__1, "********************************************", 
		44L);
	e_wsle();
	s_wsle(&io___93);
#ifndef NO_PROTO
	do_lio(&c__9, &c__1, "Cannot explicitly name file holding error sepa"
		"rator; ensure that un-named", 73L);
#else /* NO_PROTO */
	do_lio(&c__9, &c__1, "Cannot explicitly name file holding error sepa\
rator; ensure that un-named", 73L);
#endif /* NO_PROTO */
	e_wsle();
	s_wsle(&io___94);
	do_lio(&c__9, &c__1, "error file is re-named to \"errsep.erf\".", 39L)
		;
	e_wsle();
	s_wsle(&io___95);
	do_lio(&c__9, &c__1, "********************************************", 
		44L);
	e_wsle();
    }
/* set up parameters for interactive tests: */
L410:
/* set up bogus values */
    dialog_1.doutyp = -1;
    dialog_1.dtclim = -1;
#ifndef NO_PROTO
    dialog_1.dsize = -1.f;
    dialog_1.efrac = -1.f;
#else /* NO_PROTO */
    dialog_1.dsize = (float)-1.;
    dialog_1.efrac = (float)-1.;
#endif /* NO_PROTO */
    dialog_1.dintyp = -1;
    dialog_1.dstdnr = -1;
#ifndef NO_PROTO
    dialog_1.mtrpdc = -1.f;
#else /* NO_PROTO */
    dialog_1.mtrpdc = (float)-1.;
#endif /* NO_PROTO */
L415:
    s_wsle(&io___96);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "If the random number function is to generate a pse"
	    "udo-random", 60L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "If the random number function is to generate a pse\
udo-random", 60L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___97);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "sequence (allowing exactly repeatable test results"
	    "), enter", 58L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "sequence (allowing exactly repeatable test results\
), enter", 58L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___98);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "a real value between 0.1 and 0.9 as a seed; any ot"
	    "her value", 59L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "a real value between 0.1 and 0.9 as a seed; any ot\
her value", 59L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___99);
    do_lio(&c__9, &c__1, "will generate an unpredictable sequence.", 40L);
    e_wsle();
    s_rsfe(&io___100);
    do_fio(&c__1, rseed, 30L);
    e_rsfe();
    prsrl_(rseed, &rlseed, &ioerr, 30L);
    if (ioerr != 0) {
	s_wsle(&io___103);
	do_lio(&c__9, &c__1, "Incorrect format for real number; re-enter.", 
		43L);
	e_wsle();
	goto L415;
    }
    s_wsle(&io___104);
    do_lio(&c__9, &c__1, "Is the primary workstation to be tested ", 40L);
    do_lio(&c__9, &c__1, "interactively as category", 25L);
    e_wsle();
    s_wsle(&io___105);
    do_lio(&c__9, &c__1, "OUTPUT or OUTIN (1-yes, 2-no)?", 30L);
    e_wsle();
    s_rsle(&io___106);
    do_lio(&c__3, &c__1, (char *)&ans, (ftnlen)sizeof(integer));
    e_rsle();
    if (ans == 1) {
/* OK - fall thru to set-up routine */
    } else if (ans == 2) {
	goto L450;
    } else {
/* invalid response */
	goto L410;
    }
L420:
    s_wsle(&io___108);
    do_lio(&c__9, &c__1, "Method for prompting operator: 1-Fortran print, ", 
	    48L);
    e_wsle();
    s_wsle(&io___109);
    do_lio(&c__9, &c__1, "2-PHIGS <message>, 3-PHIGS <text>?", 34L);
    e_wsle();
    s_rsle(&io___110);
    do_lio(&c__3, &c__1, (char *)&dialog_1.doutyp, (ftnlen)sizeof(integer));
    e_rsle();
    if (dialog_1.doutyp == 1 || dialog_1.doutyp == 2) {
	s_wsle(&io___111);
	do_lio(&c__9, &c__1, "Maximum number of characters per line in ", 41L)
		;
	do_lio(&c__9, &c__1, "interactive prompts?", 20L);
	e_wsle();
	s_rsle(&io___112);
	do_lio(&c__3, &c__1, (char *)&dialog_1.dtclim, (ftnlen)sizeof(integer)
		);
	e_rsle();
    } else if (dialog_1.doutyp == 3) {
/*        OK - DTCLIM to be set automatically when prompt is generated
 */
    } else {
	goto L420;
    }
/* set up input */
L430:
    s_wsle(&io___113);
    do_lio(&c__9, &c__1, "Method for operator responses: 1-Fortran read, ", 
	    47L);
    e_wsle();
    s_wsle(&io___114);
    do_lio(&c__9, &c__1, "2-PHIGS <request string>?", 25L);
    e_wsle();
    s_rsle(&io___115);
    do_lio(&c__3, &c__1, (char *)&dialog_1.dintyp, (ftnlen)sizeof(integer));
    e_rsle();
    if (dialog_1.dintyp == 1) {
	dialog_1.dstdnr = 1;
    } else if (dialog_1.dintyp == 2) {
	s_wsle(&io___116);
	do_lio(&c__9, &c__1, "Device number for <request string>?", 35L);
	e_wsle();
	s_rsle(&io___117);
	do_lio(&c__3, &c__1, (char *)&dialog_1.dstdnr, (ftnlen)sizeof(integer)
		);
	e_rsle();
    } else {
	goto L430;
    }
L435:
    if (dialog_1.dintyp == 2 || dialog_1.doutyp == 3) {
	s_wsle(&io___118);
	do_lio(&c__9, &c__1, "Dialogue area: 1-dialogue at bottom, ", 37L);
	do_lio(&c__9, &c__1, "2-dialogue at right, ", 21L);
	e_wsle();
	s_wsle(&io___119);
	do_lio(&c__9, &c__1, "3-toggle picture and dialogue?", 30L);
	e_wsle();
	s_rsle(&io___120);
	do_lio(&c__3, &c__1, (char *)&dialog_1.scrmod, (ftnlen)sizeof(integer)
		);
	e_rsle();
	if (dialog_1.scrmod == 1 || dialog_1.scrmod == 2) {
	    s_wsle(&io___121);
#ifndef NO_PROTO
	    do_lio(&c__9, &c__1, "Dialogue area as percentage of screen (1-9"
		    "9)?", 45L);
#else /* NO_PROTO */
	    do_lio(&c__9, &c__1, "Dialogue area as percentage of screen (1-9\
9)?", 45L);
#endif /* NO_PROTO */
	    e_wsle();
	    s_rsle(&io___122);
	    do_lio(&c__4, &c__1, (char *)&dialog_1.dsize, (ftnlen)sizeof(real)
		    );
	    e_rsle();
#ifndef NO_PROTO
	    if (dialog_1.dsize < 1.f || dialog_1.dsize > 99.f) {
#else /* NO_PROTO */
	    if (dialog_1.dsize < (float)1. || dialog_1.dsize > (float)99.) {
#endif /* NO_PROTO */
		goto L435;
	    }
	    dialog_1.dsize /= 100;
	} else if (dialog_1.scrmod == 3) {
#ifndef NO_PROTO
	    dialog_1.dsize = 1.f;
#else /* NO_PROTO */
	    dialog_1.dsize = (float)1.;
#endif /* NO_PROTO */
	} else {
	    goto L435;
	}
/*  set EFRAC */
	if (dialog_1.dintyp == 2 && dialog_1.doutyp == 3) {
	    s_wsle(&io___123);
#ifndef NO_PROTO
	    do_lio(&c__9, &c__1, "Echo area as percentage of dialogue area ("
		    "1-99)?", 48L);
#else /* NO_PROTO */
	    do_lio(&c__9, &c__1, "Echo area as percentage of dialogue area (\
1-99)?", 48L);
#endif /* NO_PROTO */
	    e_wsle();
	    s_rsle(&io___124);
	    do_lio(&c__4, &c__1, (char *)&dialog_1.efrac, (ftnlen)sizeof(real)
		    );
	    e_rsle();
#ifndef NO_PROTO
	    if (dialog_1.efrac < 1.f || dialog_1.efrac > 99.f) {
#else /* NO_PROTO */
	    if (dialog_1.efrac < (float)1. || dialog_1.efrac > (float)99.) {
#endif /* NO_PROTO */
		goto L435;
	    }
	    dialog_1.efrac /= 100;
	} else if (dialog_1.dintyp == 2) {
/*  <request string> only */
#ifndef NO_PROTO
	    dialog_1.efrac = .99f;
#else /* NO_PROTO */
	    dialog_1.efrac = (float).99;
#endif /* NO_PROTO */
	} else {
/*  <text> only */
#ifndef NO_PROTO
	    dialog_1.efrac = .01f;
#else /* NO_PROTO */
	    dialog_1.efrac = (float).01;
#endif /* NO_PROTO */
	}
    } else {
/*  no dialogue area */
	dialog_1.scrmod = 0;
#ifndef NO_PROTO
	dialog_1.dsize = 0.f;
	dialog_1.efrac = 0.f;
#else /* NO_PROTO */
	dialog_1.dsize = (float)0.;
	dialog_1.efrac = (float)0.;
#endif /* NO_PROTO */
    }
L440:
    s_wsle(&io___125);
    do_lio(&c__9, &c__1, "For meters per DC unit on the primary workstation: "
	    , 51L);
    e_wsle();
    s_wsle(&io___126);
    do_lio(&c__9, &c__1, "1-enter number directly, 2-use PHIGS to measure ", 
	    48L);
    e_wsle();
    s_wsle(&io___127);
    do_lio(&c__9, &c__1, "right now on the primary workstation?", 37L);
    e_wsle();
    s_rsle(&io___128);
    do_lio(&c__3, &c__1, (char *)&ans, (ftnlen)sizeof(integer));
    e_rsle();
    if (ans < 1 || ans > 2) {
	goto L440;
    }
/* Create an error file with a single error message; this otherwise unused
*/
/*  message will be used as a separator when later tests analyze the */
/*  contents of error files generated by the system.  Therefore, this */
/*  single-message error file must be readable by those tests, under the 
*/
/*  name "errsep.erf". */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nerlog (&c__2, &c__180, &globnu_1.errfil);
    if (ans == 1) {
	s_wsle(&io___129);
	do_lio(&c__9, &c__1, "For primary workstation, how many meters per ", 
		45L);
	do_lio(&c__9, &c__1, "DC unit?", 8L);
	e_wsle();
	s_rsle(&io___130);
	do_lio(&c__4, &c__1, (char *)&dialog_1.mtrpdc, (ftnlen)sizeof(real));
	e_rsle();
    } else {
/* set-up of workstation and dialogue area */
	picstr = 101;
	txci = 1;
	setdlg_(&picstr, &c__801, &txci);
	nopst (&picstr);
	nsvwi (&c__1);
	setrvs_("0.1,0.9", xa, &psz, 7L);
	setrvs_("0.1,0.9", ya, &psz, 7L);
	npl (&psz, xa, ya);
	setrvs_("0.88,0.92", xa, &psz, 9L);
	setrvs_("0.92,0.88", ya, &psz, 9L);
	npl (&psz, xa, ya);
	setrvs_("0.08,0.12", xa, &psz, 9L);
	setrvs_("0.12,0.08", ya, &psz, 9L);
	npl (&psz, xa, ya);
#ifndef NO_PROTO
	drlval_("Please enter length of the diagonal line segment, expressed"
		" in centimeters (e.g. \"25.4\" if exactly 10 inches).", &
		dialog_1.mtrpdc, 110L);
	dialog_1.mtrpdc = dialog_1.mtrpdc / (sqrt(2.f) * 80.f) * 
#else /* NO_PROTO */
	drlval_("Please enter length of the diagonal line segment, expressed\
 in centimeters (e.g. \"25.4\" if exactly 10 inches).", &dialog_1.mtrpdc, 
		110L);
	dialog_1.mtrpdc = dialog_1.mtrpdc / (sqrt((float)2.) * (float)80.) * 
#endif /* NO_PROTO */
		dialog_1.wcpdc;
	nclst ();
	nclwk (&globnu_1.wkid);
    }
    nclph ();
/* interactive parameters set by now */
L450:
/* Guessing at a good logical unit number to open SYSFIL (config file) */
    lun = max(globnu_1.glblun,globnu_1.indlun) + 1;
    s_copy(errprf, "INITPH abort.  Error code for ", 30L, 30L);
    o__1.oerr = 1;
    o__1.ounit = lun;
    o__1.ofnmlen = 60;
    o__1.ofnm = sysfil;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsle(&io___138);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "OPEN of configuration file = ", 29L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    al__1.aerr = 1;
    al__1.aunit = lun;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsle(&io___139);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "REWIND of configuration file = ", 31L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
/* write info to system configuration file */
    io___140.ciunit = lun;
    ioerr = s_wsue(&io___140);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = do_uio(&c__1, (char *)&ernmsw, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = do_uio(&c__1, errmrk, 20L);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = e_wsue();
L100001:
    if (ioerr != 0) {
	s_wsle(&io___141);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "WRITE1 of configuration file = ", 31L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    io___142.ciunit = lun;
    ioerr = s_wsue(&io___142);
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dialog_1.doutyp, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dialog_1.dtclim, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dialog_1.dintyp, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dialog_1.dstdnr, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dialog_1.dsize, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dialog_1.efrac, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dialog_1.scrmod, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dialog_1.mtrpdc, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = e_wsue();
L100002:
    if (ioerr != 0) {
	s_wsle(&io___143);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "WRITE2 of configuration file = ", 31L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    io___144.ciunit = lun;
    ioerr = s_wsue(&io___144);
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.errfil, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.iflerr, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.passsw, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.errsw, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.maxlin, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.conid, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.memun, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.wkid, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.wtype, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, globch_1.glberr, 60L);
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.glblun, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&globnu_1.indlun, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&nwksav, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&rlseed, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = e_wsue();
L100003:
    if (ioerr != 0) {
	s_wsle(&io___145);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "WRITE3 of configuration file = ", 31L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    i__1 = nwksav;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	io___146.ciunit = lun;
	ioerr = s_wsue(&io___146);
	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = do_uio(&c__1, (char *)&mwkid[iwk - 1], (ftnlen)sizeof(integer)
		);
	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = do_uio(&c__1, (char *)&mconid[iwk - 1], (ftnlen)sizeof(
		integer));
	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = do_uio(&c__1, (char *)&mwtype[iwk - 1], (ftnlen)sizeof(
		integer));
	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = e_wsue();
L100004:
	if (ioerr != 0) {
	    s_wsle(&io___147);
	    do_lio(&c__9, &c__1, errprf, 30L);
	    do_lio(&c__9, &c__1, "WRITE of workstation #", 22L);
	    do_lio(&c__3, &c__1, (char *)&iwk, (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, "to configuration file = ", 24L);
	    do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    e_wsle();
	    s_stop("", 0L);
	}
/* L500: */
    }
    cl__1.cerr = 1;
    cl__1.cunit = lun;
    cl__1.csta = 0;
    ioerr = f_clos(&cl__1);
    if (ioerr != 0) {
	s_wsle(&io___148);
	do_lio(&c__9, &c__1, "Abort.  Error code for ", 23L);
	do_lio(&c__9, &c__1, sysfil, 60L);
	do_lio(&c__9, &c__1, " CLOSE = ", 9L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	goto L666;
    }
    s_wsle(&io___149);
    do_lio(&c__9, &c__1, "Wrote configuration information to: ", 36L);
    do_lio(&c__9, &c__1, sysfil, 60L);
    e_wsle();
/* now write printable version for user-inspection */
    lprt = max(globnu_1.glblun,globnu_1.indlun) + 2;
    o__1.oerr = 1;
    o__1.ounit = lprt;
    o__1.ofnmlen = 60;
    o__1.ofnm = prtfil;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsle(&io___151);
	do_lio(&c__9, &c__1, "Abort.  Error code for ", 23L);
	do_lio(&c__9, &c__1, prtfil, 60L);
	do_lio(&c__9, &c__1, " OPEN = ", 8L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	goto L666;
    }
    al__1.aerr = 0;
    al__1.aunit = lprt;
    f_rew(&al__1);
/* parms for open-phigs */
    io___152.ciunit = lprt;
    ioerr = s_wsle(&io___152);
    if (ioerr != 0) {
	goto L100005;
    }
    ioerr = do_lio(&c__9, &c__1, "Parameters to be passed to OPEN PHIGS:", 
	    38L);
    if (ioerr != 0) {
	goto L100005;
    }
    ioerr = e_wsle();
L100005:
    if (ioerr != 0) {
	goto L660;
    }
    io___153.ciunit = lprt;
    ioerr = s_wsle(&io___153);
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_lio(&c__9, &c__1, "   Error-file number = ", 23L);
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_lio(&c__3, &c__1, (char *)&globnu_1.errfil, (ftnlen)sizeof(
	    integer));
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = e_wsle();
L100006:
    if (ioerr != 0) {
	goto L660;
    }
    io___154.ciunit = lprt;
    ioerr = s_wsle(&io___154);
    if (ioerr != 0) {
	goto L100007;
    }
    ioerr = do_lio(&c__9, &c__1, "   Memory units = ", 18L);
    if (ioerr != 0) {
	goto L100007;
    }
    ioerr = do_lio(&c__3, &c__1, (char *)&globnu_1.memun, (ftnlen)sizeof(
	    integer));
    if (ioerr != 0) {
	goto L100007;
    }
    ioerr = e_wsle();
L100007:
    if (ioerr != 0) {
	goto L660;
    }
/* parms for open-workstation */
    io___155.ciunit = lprt;
    ioerr = s_wsle(&io___155);
    if (ioerr != 0) {
	goto L100008;
    }
#ifndef NO_PROTO
    ioerr = do_lio(&c__9, &c__1, "Recorded number of accessible workstations"
	    " = ", 45L);
#else /* NO_PROTO */
    ioerr = do_lio(&c__9, &c__1, "Recorded number of accessible workstations\
 = ", 45L);
#endif /* NO_PROTO */
    if (ioerr != 0) {
	goto L100008;
    }
    ioerr = do_lio(&c__3, &c__1, (char *)&nwksav, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100008;
    }
    ioerr = e_wsle();
L100008:
    i__1 = nwksav;
    for (iwk = 1; iwk <= i__1; ++iwk) {
	io___156.ciunit = lprt;
	ioerr = s_wsle(&io___156);
	if (ioerr != 0) {
	    goto L100009;
	}
#ifndef NO_PROTO
	ioerr = do_lio(&c__9, &c__1, "Parameters to be passed to OPEN WORKST"
		"ATION for wkst #", 54L);
#else /* NO_PROTO */
	ioerr = do_lio(&c__9, &c__1, "Parameters to be passed to OPEN WORKST\
ATION for wkst #", 54L);
#endif /* NO_PROTO */
	if (ioerr != 0) {
	    goto L100009;
	}
	ioerr = do_lio(&c__3, &c__1, (char *)&iwk, (ftnlen)sizeof(integer));
	if (ioerr != 0) {
	    goto L100009;
	}
	ioerr = do_lio(&c__9, &c__1, ":", 1L);
	if (ioerr != 0) {
	    goto L100009;
	}
	ioerr = e_wsle();
L100009:
	if (ioerr != 0) {
	    goto L660;
	}
	io___157.ciunit = lprt;
	ioerr = s_wsle(&io___157);
	if (ioerr != 0) {
	    goto L100010;
	}
	ioerr = do_lio(&c__9, &c__1, "   Workstation identifier = ", 28L);
	if (ioerr != 0) {
	    goto L100010;
	}
	ioerr = do_lio(&c__3, &c__1, (char *)&mwkid[iwk - 1], (ftnlen)sizeof(
		integer));
	if (ioerr != 0) {
	    goto L100010;
	}
	ioerr = e_wsle();
L100010:
	if (ioerr != 0) {
	    goto L660;
	}
	io___158.ciunit = lprt;
	ioerr = s_wsle(&io___158);
	if (ioerr != 0) {
	    goto L100011;
	}
	ioerr = do_lio(&c__9, &c__1, "   Connection identifier = ", 27L);
	if (ioerr != 0) {
	    goto L100011;
	}
	ioerr = do_lio(&c__3, &c__1, (char *)&mconid[iwk - 1], (ftnlen)sizeof(
		integer));
	if (ioerr != 0) {
	    goto L100011;
	}
	ioerr = e_wsle();
L100011:
	if (ioerr != 0) {
	    goto L660;
	}
	io___159.ciunit = lprt;
	ioerr = s_wsle(&io___159);
	if (ioerr != 0) {
	    goto L100012;
	}
	ioerr = do_lio(&c__9, &c__1, "   Workstation type = ", 22L);
	if (ioerr != 0) {
	    goto L100012;
	}
	ioerr = do_lio(&c__3, &c__1, (char *)&mwtype[iwk - 1], (ftnlen)sizeof(
		integer));
	if (ioerr != 0) {
	    goto L100012;
	}
	ioerr = e_wsle();
L100012:
	if (ioerr != 0) {
	    goto L660;
	}
/* L310: */
    }
    io___160.ciunit = lprt;
    ioerr = s_wsle(&io___160);
    if (ioerr != 0) {
	goto L100013;
    }
    ioerr = do_lio(&c__9, &c__1, "Random generator seed = ", 24L);
    if (ioerr != 0) {
	goto L100013;
    }
    ioerr = do_lio(&c__9, &c__1, rseed, 30L);
    if (ioerr != 0) {
	goto L100013;
    }
    ioerr = e_wsle();
L100013:
    if (ioerr != 0) {
	goto L660;
    }
    if (dialog_1.doutyp == -1) {
	goto L330;
    }
    io___161.ciunit = lprt;
    ioerr = s_wsle(&io___161);
    if (ioerr != 0) {
	goto L100014;
    }
    ioerr = do_lio(&c__9, &c__1, "Interactive output to ", 22L);
    if (ioerr != 0) {
	goto L100014;
    }
    ioerr = do_lio(&c__9, &c__1, "operator via ", 13L);
    if (ioerr != 0) {
	goto L100014;
    }
    ioerr = do_lio(&c__9, &c__1, dotmsg + (dialog_1.doutyp - 1) * 15, 15L);
    if (ioerr != 0) {
	goto L100014;
    }
    ioerr = e_wsle();
L100014:
    if (ioerr != 0) {
	goto L660;
    }
    if (dialog_1.doutyp == 1 || dialog_1.doutyp == 2) {
	io___162.ciunit = lprt;
	ioerr = s_wsle(&io___162);
	if (ioerr != 0) {
	    goto L100015;
	}
	ioerr = do_lio(&c__9, &c__1, "Maximum characters ", 19L);
	if (ioerr != 0) {
	    goto L100015;
	}
	ioerr = do_lio(&c__9, &c__1, "per line in interactive messages = ", 
		35L);
	if (ioerr != 0) {
	    goto L100015;
	}
	ioerr = do_lio(&c__3, &c__1, (char *)&dialog_1.dtclim, (ftnlen)sizeof(
		integer));
	if (ioerr != 0) {
	    goto L100015;
	}
	ioerr = e_wsle();
L100015:
	if (ioerr != 0) {
	    goto L660;
	}
    }
    io___163.ciunit = lprt;
    ioerr = s_wsle(&io___163);
    if (ioerr != 0) {
	goto L100016;
    }
    ioerr = do_lio(&c__9, &c__1, "Interactive input from ", 23L);
    if (ioerr != 0) {
	goto L100016;
    }
    ioerr = do_lio(&c__9, &c__1, "operator via ", 13L);
    if (ioerr != 0) {
	goto L100016;
    }
    ioerr = do_lio(&c__9, &c__1, dinmsg + (dialog_1.dintyp - 1) * 21, 21L);
    if (ioerr != 0) {
	goto L100016;
    }
    ioerr = e_wsle();
L100016:
    if (ioerr != 0) {
	goto L660;
    }
    if (dialog_1.dintyp == 2) {
	io___164.ciunit = lprt;
	ioerr = s_wsle(&io___164);
	if (ioerr != 0) {
	    goto L100017;
	}
	ioerr = do_lio(&c__9, &c__1, "Standard string ", 16L);
	if (ioerr != 0) {
	    goto L100017;
	}
	ioerr = do_lio(&c__9, &c__1, "device #", 8L);
	if (ioerr != 0) {
	    goto L100017;
	}
	ioerr = do_lio(&c__3, &c__1, (char *)&dialog_1.dstdnr, (ftnlen)sizeof(
		integer));
	if (ioerr != 0) {
	    goto L100017;
	}
	ioerr = e_wsle();
L100017:
	if (ioerr != 0) {
	    goto L660;
	}
    }
    if (dialog_1.scrmod == 0) {
/*        do nothing */
    } else if (dialog_1.scrmod == 3) {
	io___165.ciunit = lprt;
	ioerr = s_wsle(&io___165);
	if (ioerr != 0) {
	    goto L100018;
	}
	ioerr = do_lio(&c__9, &c__1, "Dialogue via toggled screen.", 28L);
	if (ioerr != 0) {
	    goto L100018;
	}
	ioerr = e_wsle();
L100018:
	if (ioerr != 0) {
	    goto L660;
	}
    } else {
/*  dialog on split screen */
	io___166.ciunit = lprt;
	ioerr = s_wsle(&io___166);
	if (ioerr != 0) {
	    goto L100019;
	}
	ioerr = do_lio(&c__9, &c__1, "Split screen, dialogue at ", 26L);
	if (ioerr != 0) {
	    goto L100019;
	}
	ioerr = do_lio(&c__9, &c__1, dlgloc + (dialog_1.scrmod - 1) * 7, 7L);
	if (ioerr != 0) {
	    goto L100019;
	}
	ioerr = e_wsle();
L100019:
	if (ioerr != 0) {
	    goto L660;
	}
	io___167.ciunit = lprt;
	ioerr = s_wsle(&io___167);
	if (ioerr != 0) {
	    goto L100020;
	}
	ioerr = do_lio(&c__9, &c__1, "Dialog area as ", 15L);
	if (ioerr != 0) {
	    goto L100020;
	}
	ioerr = do_lio(&c__9, &c__1, "fraction of screen = ", 21L);
	if (ioerr != 0) {
	    goto L100020;
	}
	ioerr = do_lio(&c__4, &c__1, (char *)&dialog_1.dsize, (ftnlen)sizeof(
		real));
	if (ioerr != 0) {
	    goto L100020;
	}
	ioerr = e_wsle();
L100020:
	if (ioerr != 0) {
	    goto L660;
	}
	io___168.ciunit = lprt;
	ioerr = s_wsle(&io___168);
	if (ioerr != 0) {
	    goto L100021;
	}
	ioerr = do_lio(&c__9, &c__1, "Echo area as ", 13L);
	if (ioerr != 0) {
	    goto L100021;
	}
	ioerr = do_lio(&c__9, &c__1, "fraction of dialogue area = ", 28L);
	if (ioerr != 0) {
	    goto L100021;
	}
	ioerr = do_lio(&c__4, &c__1, (char *)&dialog_1.efrac, (ftnlen)sizeof(
		real));
	if (ioerr != 0) {
	    goto L100021;
	}
	ioerr = e_wsle();
L100021:
	if (ioerr != 0) {
	    goto L660;
	}
    }
    io___169.ciunit = lprt;
    ioerr = s_wsle(&io___169);
    if (ioerr != 0) {
	goto L100022;
    }
    ioerr = do_lio(&c__9, &c__1, "Meters per DC unit = ", 21L);
    if (ioerr != 0) {
	goto L100022;
    }
    ioerr = do_lio(&c__4, &c__1, (char *)&dialog_1.mtrpdc, (ftnlen)sizeof(
	    real));
    if (ioerr != 0) {
	goto L100022;
    }
    ioerr = e_wsle();
L100022:
    if (ioerr != 0) {
	goto L660;
    }
L330:
    io___170.ciunit = lprt;
    ioerr = s_wsle(&io___170);
    if (ioerr != 0) {
	goto L100023;
    }
    ioerr = do_lio(&c__9, &c__1, sucmsg + globnu_1.passsw * 48, 48L);
    if (ioerr != 0) {
	goto L100023;
    }
    ioerr = e_wsle();
L100023:
    if (ioerr != 0) {
	goto L660;
    }
    if (globnu_1.errsw == 0) {
	s_copy(msgdst, " ", 40L, 1L);
	nxtch = 1;
    } else {
	s_copy(msgdst, "operator", 40L, 8L);
	nxtch = 9;
    }
    if (globnu_1.iflerr == 1 || globnu_1.iflerr == 3) {
	s_copy(msgdst + (nxtch - 1), ", global-file", 40 - (nxtch - 1), 13L);
	nxtch += 13;
    }
    if (globnu_1.iflerr == 2 || globnu_1.iflerr == 3) {
	s_copy(msgdst + (nxtch - 1), ", individual-file", 40 - (nxtch - 1), 
		17L);
	nxtch += 17;
    }
    if (s_cmp(msgdst, " ", 40L, 1L) == 0) {
	s_copy(msgdst, "None.", 40L, 5L);
    }
    io___173.ciunit = lprt;
    ioerr = s_wsle(&io___173);
    if (ioerr != 0) {
	goto L100024;
    }
/* Writing concatenation */
    i__2[0] = 21, a__1[0] = "Message destination: ";
    i__2[1] = 40, a__1[1] = msgdst;
    s_cat(ch__5, a__1, i__2, &c__2, 61L);
    ioerr = do_lio(&c__9, &c__1, ch__5, 61L);
    if (ioerr != 0) {
	goto L100024;
    }
    ioerr = e_wsle();
L100024:
    if (ioerr != 0) {
	goto L660;
    }
    if (globnu_1.iflerr == 1 || globnu_1.iflerr == 3) {
	io___174.ciunit = lprt;
	ioerr = s_wsle(&io___174);
	if (ioerr != 0) {
	    goto L100025;
	}
	ioerr = do_lio(&c__9, &c__1, "Global file unit number = ", 26L);
	if (ioerr != 0) {
	    goto L100025;
	}
	ioerr = do_lio(&c__3, &c__1, (char *)&globnu_1.glblun, (ftnlen)sizeof(
		integer));
	if (ioerr != 0) {
	    goto L100025;
	}
/* Writing concatenation */
	i__2[0] = 13, a__1[0] = ", filename = ";
	i__2[1] = 60, a__1[1] = globch_1.glberr;
	s_cat(ch__6, a__1, i__2, &c__2, 73L);
	ioerr = do_lio(&c__9, &c__1, ch__6, 73L);
	if (ioerr != 0) {
	    goto L100025;
	}
	ioerr = e_wsle();
L100025:
	if (ioerr != 0) {
	    goto L660;
	}
    }
    if (globnu_1.iflerr == 2 || globnu_1.iflerr == 3) {
	io___175.ciunit = lprt;
	ioerr = s_wsle(&io___175);
	if (ioerr != 0) {
	    goto L100026;
	}
	ioerr = do_lio(&c__9, &c__1, "Individual file unit number = ", 30L);
	if (ioerr != 0) {
	    goto L100026;
	}
	ioerr = do_lio(&c__3, &c__1, (char *)&globnu_1.indlun, (ftnlen)sizeof(
		integer));
	if (ioerr != 0) {
	    goto L100026;
	}
	ioerr = e_wsle();
L100026:
	if (ioerr != 0) {
	    goto L660;
	}
    }
    io___176.ciunit = lprt;
    ioerr = s_wsle(&io___176);
    if (ioerr != 0) {
	goto L100027;
    }
    ioerr = do_lio(&c__9, &c__1, "Maximum characters per line in messages = ",
	     42L);
    if (ioerr != 0) {
	goto L100027;
    }
    ioerr = do_lio(&c__3, &c__1, (char *)&globnu_1.maxlin, (ftnlen)sizeof(
	    integer));
    if (ioerr != 0) {
	goto L100027;
    }
    ioerr = e_wsle();
L100027:
    if (ioerr != 0) {
	goto L660;
    }
    io___177.ciunit = lprt;
    ioerr = s_wsle(&io___177);
    if (ioerr != 0) {
	goto L100028;
    }
/* Writing concatenation */
    i__3[0] = 14, a__2[0] = "Error file may";
    i__3[1] = (ernmsw << 2) - 3, a__2[1] = notstr;
    i__3[2] = 31, a__2[2] = "be explicitly opened and named.";
    s_cat(ch__7, a__2, i__3, &c__3, 50L);
    ioerr = do_lio(&c__9, &c__1, ch__7, (ernmsw << 2) + 42);
    if (ioerr != 0) {
	goto L100028;
    }
    ioerr = e_wsle();
L100028:
    if (ioerr != 0) {
	goto L660;
    }
    if (s_cmp(errmrk, " ", 20L, 1L) == 0) {
	io___178.ciunit = lprt;
	ioerr = s_wsle(&io___178);
	if (ioerr != 0) {
	    goto L100029;
	}
#ifndef NO_PROTO
	ioerr = do_lio(&c__9, &c__1, "Error messages do not contain an ident"
		"ifying string.", 52L);
#else /* NO_PROTO */
	ioerr = do_lio(&c__9, &c__1, "Error messages do not contain an ident\
ifying string.", 52L);
#endif /* NO_PROTO */
	if (ioerr != 0) {
	    goto L100029;
	}
	ioerr = e_wsle();
L100029:
	;
    } else {
	io___179.ciunit = lprt;
	ioerr = s_wsle(&io___179);
	if (ioerr != 0) {
	    goto L100030;
	}
/* Writing concatenation */
	i__3[0] = 40, a__2[0] = "Identifying string for error messages: \"";
	i__3[1] = itrim_(errmrk, 20L), a__2[1] = errmrk;
	i__3[2] = 1, a__2[2] = "\"";
	s_cat(ch__5, a__2, i__3, &c__3, 61L);
	ioerr = do_lio(&c__9, &c__1, ch__5, itrim_(errmrk, 20L) + 41);
	if (ioerr != 0) {
	    goto L100030;
	}
	ioerr = e_wsle();
L100030:
	;
    }
    if (ioerr != 0) {
	goto L660;
    }
    cl__1.cerr = 1;
    cl__1.cunit = lprt;
    cl__1.csta = 0;
    ioerr = f_clos(&cl__1);
    if (ioerr != 0) {
	s_wsle(&io___180);
	do_lio(&c__9, &c__1, "Abort.  Error code for ", 23L);
	do_lio(&c__9, &c__1, prtfil, 60L);
	do_lio(&c__9, &c__1, " CLOSE = ", 9L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	goto L666;
    }
    s_wsle(&io___181);
    do_lio(&c__9, &c__1, "Wrote printable configuration information to: ", 
	    46L);
    do_lio(&c__9, &c__1, prtfil, 60L);
    e_wsle();
    goto L666;
L660:
    s_wsle(&io___182);
    do_lio(&c__9, &c__1, "Abort.  Error code for ", 23L);
    do_lio(&c__9, &c__1, prtfil, 60L);
    do_lio(&c__9, &c__1, " WRITE = ", 9L);
    do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
    e_wsle();
L666:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* MAIN__ */

#ifndef NO_PROTO
/* Main program alias */ int initph_ () { MAIN__ (); return 0; }
#else /* NO_PROTO */
/* Main program alias */ int initph_ () { MAIN__ (); }
#endif /* NO_PROTO */
