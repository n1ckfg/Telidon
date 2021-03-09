/* fort/09/01/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"
/*  MANUAL CHANGE HERE  */
#include <phigs.h>
/*  END MANUAL CHANGE   */

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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__3 = 3;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c__111 = 111;
static integer c__90 = 90;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__8 = 8;
static integer c__9 = 9;
static integer c__13 = 13;
static integer c__17 = 17;
static integer c__16 = 16;
static integer c__11 = 11;
static integer c__15 = 15;
static integer c__19 = 19;
static integer c__18 = 18;
static integer c__20 = 20;
static integer c__21 = 21;
static integer c__62 = 62;
static integer c__63 = 63;
static integer c__42 = 42;
static integer c__43 = 43;
static integer c__47 = 47;
static integer c__49 = 49;
static integer c__27 = 27;
static integer c__33 = 33;
static integer c__35 = 35;
static integer c__48 = 48;
static integer c__58 = 58;
static integer c__65 = 65;
static integer c__67 = 67;
static integer c__64 = 64;
static integer c__28 = 28;
static integer c__55 = 55;
static integer c__31 = 31;
static integer c__39 = 39;
static integer c__26 = 26;
static integer c__66 = 66;
static integer c__24 = 24;
static integer c__29 = 29;
static integer c__34 = 34;
static integer c__37 = 37;
static integer c__52 = 52;
static integer c__59 = 59;
static integer c__60 = 60;
static integer c__61 = 61;
static integer c__69 = 69;
static integer c__72 = 72;
static integer c__70 = 70;
static integer c__71 = 71;
static integer c__68 = 68;
static integer c__73 = 73;
static integer c__84 = 84;
static integer c__87 = 87;
static integer c__86 = 86;
static integer c__88 = 88;
static integer c__89 = 89;
static integer c__77 = 77;
static integer c__83 = 83;
static integer c__75 = 75;
static integer c__79 = 79;
static integer c__82 = 82;
static integer c__85 = 85;
static integer c__91 = 91;
static integer c__93 = 93;
static integer c__98 = 98;
static integer c__92 = 92;
static integer c__97 = 97;
static integer c__101 = 101;
static integer c__96 = 96;
static integer c__104 = 104;
static integer c__106 = 106;
static integer c__110 = 110;
static integer c__119 = 119;
static integer c__100 = 100;
static integer c__103 = 103;
static integer c__112 = 112;
static integer c__113 = 113;
static integer c__114 = 114;
static integer c__115 = 115;
static integer c__116 = 116;
static integer c__117 = 117;
static integer c__118 = 118;
static integer c__120 = 120;
static integer c__123 = 123;
static integer c__121 = 121;
static integer c__122 = 122;
static integer c__124 = 124;
static integer c__125 = 125;
static integer c__126 = 126;
static integer c__128 = 128;
static integer c__127 = 127;
static integer c__179 = 179;
static integer c__180 = 180;
static integer c_n666 = -666;
#ifndef NO_PROTO
static real c_b564 = .1f;
static real c_b565 = .55f;
#else /* NO_PROTO */
static real c_b564 = (float).1;
static real c_b565 = (float).55;
#endif /* NO_PROTO */

/*  The routines in 09.01/sublib are used to support the checking of */
/*  error signalling for the various error codes.  The calling */
/*  structure looks like this: */


/*                    Pxx.FOR */
/*                     | */
/*                     | */
/*              ---------------- */
/*              Emmeee or Cmmeee   =   E/C <module#> <error#> */
/*              ---------------- */
/*                     | */
/*      -------------------------------------- */
/*      |         |        |        |        | */
/*    esetup    enderr   tstign   streq    rfuncs */
/*                |                          | */
/*                |                          | */
/*                |                          | */
/*                |----------              echkz */
/*                |         | */
/*              tsterr      | */
/*                |         | */
/*                |-------gterrm */
/*                |         | */
/*              scherr    ermsgh */


/*  These routines communicate largely through the common areas */
/*  ERRINF and ERRCHR.  Here is the meaning of their variables: */

/*     /ERRINF/ */
/*  ERRCOM : error code returned by system to user-defined PERHND */
/*  FUNCOM : function code returned by system to user-defined PERHND */
/*  FILCOM : error file returned by system to user-defined PERHND */
/*  ERNMSW : switch set by INITPH: */
/*             1-program can explicitly open and name error file, */
/*             2-program cannot set name of error file */
/*  EXPSIZ : Number of correct values for error code */
/*  EXPERR : List of expected/correct value(s) for error code */
/*  USRERR : switch indicating type of error checking: */
/*             0 - normal mode (non-09 tests); not testing error handling */
/*             1 - user-defined error handling */
/*             2 - system-defined error handling */
/*             3 - user-defined error handling, when PHIGS is closed at */
/*                 the time the error is generated.  This is a special */
/*                 case because the value of the error file parameter */
/*                 should not be checked. */
/*             4 - system-defined error handling, when PHIGS is closed at */
/*                 the time the error is generated.  This is a special */
/*                 case because the error file, to which messages are */
/*                 normally written, is closed and therefore inaccessible. */
/*             5 - system-defined error handling, but use CURCON as total */
/*                 test message, rather than constructing additional */
/*                 parts of message automatically. */
/* ERRSAV : Array of error codes returned by system to user-defined PERHND*/
/*  FUNSAV : Array of function codes actually returned by system */
/*           to user-defined PERHND */
/*  FILSAV : Array of error file identifiers returned by system to */
/*           user-defined PERHND */
/*  EFCNT  : Number of error-signalling function invocations (each of */
/*           which may generate several errors) */
/*  EFID   : Table of expected identifiers of error-signalling functions, */
/*           indexed by EFCNT */

/*     /ERRCHR/ */
/* CURCON : description of the current condition expected to cause an error*/
/*  ERRSRS : string containing the SRs which support the current test case */
/*  ERRMRK : string set by INITPH to identify distinct system-generated */
/*           error messages in error file */
/*  ERFLNM : character string for name of error file */
/*  CONTAB : table of current condition descriptions at the time error- */
/*           generating function was invoked */
/*  Data flow within 09/01/sublib */

/*  Producers: */
/*  initph  perhnd  pvt-code  esetup  echkz   tsterr */
/*                                                     Consumers: */
/*  - - - - - - - - - - - - - - - - - - - - - - - - - */
/*  ERNMSW          USRERR                             esetup */
/*  - - - - - - - - - - - - - - - - - - - - - - - - - */
/*  ERNMSW          USRERR    ERFLNM  EFCNT */
/*                                    EFID             enderr */
/*                                    CONTAB */
/*  - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                  CURCON                             tstign */
/*                  ERRSRS */
/*  - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                  USRERR    EFCNT                    rfuncs/echkz */
/*                  CURCON */
/*  - - - - - - - - - - - - - - - - - - - - - - - - - */
/*          ERRSAV  EXPSIZ                    ERRCOM */
/*          FUNSAV  EXPERR                    FUNCOM   tsterr */
/*          FILSAV  USRERR                    FILCOM */
/*                  ERRSRS */
/*  - - - - - - - - - - - - - - - - - - - - - - - - - */
/*  ERRMRK                                             gterrm */
/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/esetup                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int esetup_(integer *useprm)
#else /* NO_PROTO */
/* Subroutine */ int esetup_(useprm)
integer *useprm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3];
    olist o__1;
    alist al__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer f_open(olist *), s_wsfi(icilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfi(void), f_rew(alist *);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    integer f_open(), s_wsfi(), do_fio(), e_wsfi(), f_rew();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char msg[300];
    static integer ioerr;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen), errctl_(logical *), 
	    xpopph_(integer *, integer *);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_(), errctl_(), xpopph_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___4 = { 0, msg, 0, "(A,I7,A)", 300, 1 };
    static icilist io___5 = { 0, msg, 0, "(A,I7,A)", 300, 1 };

/*  MANUAL CHANGE HERE  */

#ifndef NO_PROTO
     extern void  (*current_handler_1)
                     (Pint error_num, Pint func_num, char *error_file);
#else /* NO_PROTO */
     extern void  (*current_handler_1)();
#endif /* NO_PROTO */

/*  END MANUAL CHANGE   */

/*  ESETUP initializes USRERR from its parameter USEPRM.  It also */
/*  initializes ERFLNM and opens PHIGS.  ESETUP is always called by */
/*  the Emmeee routines before they start generating errors. */

/*  Input parameter: */
/*    USEPRM : switch indicating type of error checking: */
/*             1 - user-defined error handling */
/*             2 - system-defined error handling */
/*             3 - user-defined error handling, when PHIGS is closed. */
/*             4 - system-defined error handling, when PHIGS is closed. */

    if (*useprm >= 1 && *useprm <= 5) {
	errinf_1.usrerr = *useprm;
    } else {
	unmsg_("ESETUP called with invalid USEPRM.", 34L);
    }

/*  MANUAL CHANGE HERE  */

/*  Use C mechanism to make system-defined error handler (perr_hand)
    the current handler;  This overrides default set by INITGL
    which sets PVT-defined error handler (pvt_err_hand).
*/
    if (*useprm == 2 || *useprm >= 4) 
       pset_err_hand (perr_hand, &current_handler_1);

/*  END MANUAL CHANGE   */

    s_copy(errchr_1.erflnm, " ", 80L, 1L);
    if (errinf_1.usrerr == 2 || errinf_1.usrerr == 5) {
	if (errinf_1.ernmsw == 1) {
/*  set up error file */
	    ix = itrim_(globch_1.pident, 40L);
	    i__1 = ix - 2;
/* Writing concatenation */
	    i__2[0] = 1, a__1[0] = "p";
	    i__2[1] = ix - i__1, a__1[1] = globch_1.pident + i__1;
	    i__2[2] = 4, a__1[2] = ".erf";
	    s_cat(errchr_1.erflnm, a__1, i__2, &c__3, 80L);
	    o__1.oerr = 1;
	    o__1.ounit = globnu_1.errfil;
	    o__1.ofnmlen = 80;
	    o__1.ofnm = errchr_1.erflnm;
	    o__1.orl = 0;
	    o__1.osta = "UNKNOWN";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    ioerr = f_open(&o__1);
	    if (ioerr != 0) {
		s_wsfi(&io___4);
#ifndef NO_PROTO
		do_fio(&c__1, "ESETUP failed to open error file.  OPEN retur"
			"ned Fortran IO status = ", 69L);
#else /* NO_PROTO */
		do_fio(&c__1, "ESETUP failed to open error file.  OPEN retur\
ned Fortran IO status = ", 69L);
#endif /* NO_PROTO */
		do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		unmsg_(msg, 300L);
	    }
/*  rewind error file, so that its contents can be written */
	    al__1.aerr = 1;
	    al__1.aunit = globnu_1.errfil;
	    ioerr = f_rew(&al__1);
	    if (ioerr != 0) {
		s_wsfi(&io___5);
#ifndef NO_PROTO
		do_fio(&c__1, "ESETUP failed to rewind the error file.  REWI"
			"ND returned Fortran IO status = ", 77L);
#else /* NO_PROTO */
		do_fio(&c__1, "ESETUP failed to rewind the error file.  REWI\
ND returned Fortran IO status = ", 77L);
#endif /* NO_PROTO */
		do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		unmsg_(msg, 300L);
	    }
	}
    } else if (errinf_1.usrerr == 1 || errinf_1.usrerr == 3) {
#ifndef NO_PROTO
	errctl_((logical*)&c__1);
#else /* NO_PROTO */
	errctl_(&c__1);
#endif /* NO_PROTO */
    }
    errinf_1.efcnt = 0;
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* esetup_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/enderr                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int enderr_(void)
#else /* NO_PROTO */
/* Subroutine */ int enderr_()
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char erlogt[800] = "                                             "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                   ";
#else /* NO_PROTO */
    static char erlogt[800+1] = "                                           \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                         ";
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;
    alist al__1;
    inlist ioin__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer f_inqu(inlist *), s_cmp(char *, char *, ftnlen, ftnlen), s_wsfi(
	    icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void), 
	    f_open(olist *), f_rew(alist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_clos(cllist *);
#else /* NO_PROTO */
    integer f_inqu(), s_cmp(), s_wsfi(), do_fio(), e_wsfi(), f_open(), f_rew()
	    ;
    /* Subroutine */ int s_copy();
    integer f_clos();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclph (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclph ();
#endif /* NO_PROTO */
    static integer ioerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer funcix, seplun;
    static char ersnam[80];
    static logical opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int gterrm_(integer *, char *, ftnlen), errctl_(
	    logical *), tsterr_(integer *, char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int gterrm_(), errctl_(), tsterr_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___9 = { 0, msg, 0, "(A,I7,A)", 200, 1 };
    static icilist io___11 = { 0, msg, 0, "(A,I7,A)", 200, 1 };
    static icilist io___12 = { 0, msg, 0, "(A,I7,A)", 200, 1 };
    static icilist io___15 = { 0, msg, 0, "(A,I7,A)", 200, 1 };
    static icilist io___16 = { 0, msg, 0, "(A,I7,A)", 200, 1 };


/*  ENDERR closes PHIGS.  Also, when system error handling is being */
/*  tested, it determines the file name of the system error file so */
/*  that it can re-open and rewind the file for inspection.  ENDERR */
/*  is normally called by the Emmeee routines after generating errors, */
/*  but before testing them. */
/*  special strings to control processing of error file */
    if ((errinf_1.usrerr == 2 || errinf_1.usrerr == 5) && errinf_1.ernmsw == 
	    2) {
/*  try to find out system-name for error file */
	ioin__1.inerr = 1;
	ioin__1.inunit = globnu_1.errfil;
	ioin__1.infile = 0;
	ioin__1.inex = 0;
	ioin__1.inopen = 0;
	ioin__1.innum = 0;
	ioin__1.innamed = 0;
	ioin__1.innamlen = 80;
	ioin__1.inname = errchr_1.erflnm;
	ioin__1.inacc = 0;
	ioin__1.inseq = 0;
	ioin__1.indir = 0;
	ioin__1.infmt = 0;
	ioin__1.inform = 0;
	ioin__1.inunf = 0;
	ioin__1.inrecl = 0;
	ioin__1.innrec = 0;
	ioin__1.inblank = 0;
	ioerr = f_inqu(&ioin__1);
	if (ioerr != 0 || s_cmp(errchr_1.erflnm, " ", 80L, 1L) == 0) {
	    s_wsfi(&io___9);
#ifndef NO_PROTO
	    do_fio(&c__1, "ENDERR failed to determine name of system error f"
		    "ile.  Inquire returned Fortran IO status = ", 92L);
#else /* NO_PROTO */
	    do_fio(&c__1, "ENDERR failed to determine name of system error f\
ile.  Inquire returned Fortran IO status = ", 92L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    unmsg_(msg, 200L);
	}
    }
    if (errinf_1.usrerr == 1 || errinf_1.usrerr == 2 || errinf_1.usrerr == 5) 
	    {
	nclph ();
    }
    if (errinf_1.usrerr == 2 || errinf_1.usrerr == 5) {
	ioin__1.inerr = 0;
	ioin__1.inunit = globnu_1.errfil;
	ioin__1.infile = 0;
	ioin__1.inex = 0;
	ioin__1.inopen = &opstat;
	ioin__1.innum = 0;
	ioin__1.innamed = 0;
	ioin__1.inname = 0;
	ioin__1.inacc = 0;
	ioin__1.inseq = 0;
	ioin__1.indir = 0;
	ioin__1.infmt = 0;
	ioin__1.inform = 0;
	ioin__1.inunf = 0;
	ioin__1.inrecl = 0;
	ioin__1.innrec = 0;
	ioin__1.inblank = 0;
	f_inqu(&ioin__1);
/*  re-open error file if necessary (closing PHIGS should have closed 
*/
/*  error file). */
	if (! opstat) {
	    o__1.oerr = 1;
	    o__1.ounit = globnu_1.errfil;
	    o__1.ofnmlen = 80;
	    o__1.ofnm = errchr_1.erflnm;
	    o__1.orl = 0;
	    o__1.osta = "OLD";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    ioerr = f_open(&o__1);
	    if (ioerr != 0) {
		s_wsfi(&io___11);
#ifndef NO_PROTO
		do_fio(&c__1, "ENDERR failed to re-open error file after clo"
			"sing PHIGS.  OPEN returned Fortran IO status = ", 92L)
			;
#else /* NO_PROTO */
		do_fio(&c__1, "ENDERR failed to re-open error file after clo\
sing PHIGS.  OPEN returned Fortran IO status = ", 92L);
#endif /* NO_PROTO */
		do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
		do_fio(&c__1, ".", 1L);
		e_wsfi();
		unmsg_(msg, 200L);
	    }
	}
/*  rewind error file, so that its contents can be read and examined 
*/
	al__1.aerr = 1;
	al__1.aunit = globnu_1.errfil;
	ioerr = f_rew(&al__1);
	if (ioerr != 0) {
	    s_wsfi(&io___12);
#ifndef NO_PROTO
	    do_fio(&c__1, "ENDERR failed to rewind the error file.  REWIND r"
		    "eturned Fortran IO status = ", 77L);
#else /* NO_PROTO */
	    do_fio(&c__1, "ENDERR failed to rewind the error file.  REWIND r\
eturned Fortran IO status = ", 77L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    unmsg_(msg, 200L);
	}
/* USERMOD  Insert here filename for error separator file, usually in */
/* USERMOD  PVT root directory */
	s_copy(ersnam, "/home/cugini/pvt/work/v2.1/errsep.erf", 80L, 37L);
/*  get error separator message */
/* Computing MAX */
	i__1 = max(globnu_1.glblun,globnu_1.indlun);
	seplun = max(i__1,globnu_1.errfil) + 1;
	o__1.oerr = 1;
	o__1.ounit = seplun;
	o__1.ofnmlen = 80;
	o__1.ofnm = ersnam;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	ioerr = f_open(&o__1);
	if (ioerr != 0) {
	    s_wsfi(&io___15);
#ifndef NO_PROTO
	    do_fio(&c__1, "ENDERR failed to open errsep file.  OPEN returned"
		    " Fortran IO status = ", 70L);
#else /* NO_PROTO */
	    do_fio(&c__1, "ENDERR failed to open errsep file.  OPEN returned\
 Fortran IO status = ", 70L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    unmsg_(msg, 200L);
	}
	al__1.aerr = 1;
	al__1.aunit = seplun;
	ioerr = f_rew(&al__1);
	if (ioerr != 0) {
	    s_wsfi(&io___16);
#ifndef NO_PROTO
	    do_fio(&c__1, "ENDERR failed to rewind errsep file.  REWIND retu"
		    "rned Fortran IO status = ", 74L);
#else /* NO_PROTO */
	    do_fio(&c__1, "ENDERR failed to rewind errsep file.  REWIND retu\
rned Fortran IO status = ", 74L);
#endif /* NO_PROTO */
	    do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    unmsg_(msg, 200L);
	}
/*  get the first (and presumably only) message from the errsep file, 
*/
/*  to be used as pattern to recognize terminator message */
	s_copy(erlogt, "first call", 800L, 10L);
	gterrm_(&seplun, erlogt, 800L);
	cl__1.cerr = 0;
	cl__1.cunit = seplun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    } else {
/*  user-defined error handling */
#ifndef NO_PROTO
	errctl_((logical*)&c__0);
#else /* NO_PROTO */
	errctl_(&c__0);
#endif /* NO_PROTO */
    }
/*  loop thru expected functions and see whether they match actual results
 */
    i__1 = errinf_1.efcnt;
    for (funcix = 1; funcix <= i__1; ++funcix) {
	tsterr_(&errinf_1.efid[funcix - 1], errchr_1.contab + (funcix - 1) * 
		150, erlogt, 150L, 800L);
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* enderr_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/tsterr                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tsterr_(integer *expfun, char *condes, char *erlogt, 
	ftnlen condes_len, ftnlen erlogt_len)
#else /* NO_PROTO */
/* Subroutine */ int tsterr_(expfun, condes, erlogt, condes_len, erlogt_len)
integer *expfun;
char *condes, *erlogt;
ftnlen condes_len;
ftnlen erlogt_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer errct = 0;
#ifndef NO_PROTO
    static char emsg[1000] = "first call                                    "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                                "
	    "                                                          ";
#else /* NO_PROTO */
    static char emsg[1000+1] = "first call                                  \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                                                            \
                                            ";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[2], a__2[3];
    integer i__1[2], i__2, i__3, i__4[3];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat(), s_copy();
    integer s_wsfi(), do_fio(), e_wsfi(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, lnb;
    static char ans[1], msg[160];
    static integer lst;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_();
#endif /* NO_PROTO */
    static integer ierr;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static char tmsg[500];
#ifndef NO_PROTO
    extern /* Subroutine */ int opyn_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opyn_();
#endif /* NO_PROTO */
    static char acode[4];
    static logical filok;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static logical errok;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static logical funok;
#ifndef NO_PROTO
    extern /* Subroutine */ int opmsg_(char *, ftnlen), oplin_(char *, ftnlen)
	    , unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opmsg_(), oplin_(), unmsg_();
#endif /* NO_PROTO */
    static integer tstat;
#ifndef NO_PROTO
    extern integer leadnb_(char *, ftnlen), iarfnd_(integer *, integer *, 
	    integer *);
    extern /* Subroutine */ int erfucd_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern integer leadnb_(), iarfnd_();
    extern /* Subroutine */ int erfucd_();
#endif /* NO_PROTO */
    static integer generr, genfun;
    static char funnam[80], errmsg[180], funmsg[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int erfunm_(integer *, char *, ftnlen), setmsg_(
	    char *, char *, ftnlen, ftnlen), gterrm_(integer *, char *, 
	    ftnlen), prsint_(char *, integer *, integer *, ftnlen), scherr_(
	    integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int erfunm_(), setmsg_(), gterrm_(), prsint_(), 
	    scherr_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___24 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___25 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___26 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___32 = { 0, msg, 0, "(A,I6.3,A)", 160, 1 };
    static icilist io___33 = { 0, msg, 0, "(A,I4.3,A,I4.3,A)", 160, 1 };
    static icilist io___34 = { 0, msg, 0, "(A,I4.3,A,I4.3,A)", 160, 1 };
    static icilist io___43 = { 0, msg, 0, "(A,I6.3,A)", 160, 1 };
    static icilist io___44 = { 0, msg, 0, "(A,I4.3,A,I4.3,A)", 160, 1 };


/*  TSTERR sets up one test case for error handling and then issues */
/*  pass or fail for it.  It sets up the test case based on the SRs */
/*  to be tested (ERRSRS), the list of expected errors (EXPERR) and */
/*  the expected error-generating function (EXPFUN).  The test */
/*  procedure adopted depends on whether TSTERR is invoked for */
/*  user-defined error handling, or system-defined, as indicated by */
/*  USRERR. */

/*  Input parameters: */
/*    EXPFUN : code for the expected generating function. */
/*    CONDES : description of condition that should have caused error */
/*    ERLOGT : content of error message serving as terminator */
/*  special strings to control processing of error file */
/*  for user error handling, ERRCT is used to scan through array */
/*  of actual results generated by error-signalling functions */
/*  set up test message */
    erfunm_(expfun, funnam, 80L);
/* Writing concatenation */
    i__1[0] = 3, a__1[0] = "If ";
    i__1[1] = 80, a__1[1] = funnam;
    s_cat(tmsg, a__1, i__1, &c__2, 500L);
    i__2 = itrim_(tmsg, 500L) + 1;
/* Writing concatenation */
    i__1[0] = 14, a__1[0] = "is called and ";
    i__1[1] = condes_len, a__1[1] = condes;
    s_cat(tmsg + i__2, a__1, i__1, &c__2, 500 - i__2);
    i__2 = itrim_(tmsg, 500L);
    s_copy(tmsg + i__2, ", it should", 500 - i__2, 11L);
    if (errinf_1.usrerr == 1 || errinf_1.usrerr == 3) {
	if (errinf_1.expsiz < 1) {
	    unmsg_("TSTERR called with invalid EXPSIZ.", 34L);
	}
	i__2 = itrim_(tmsg, 500L) + 1;
	s_copy(tmsg + i__2, "return error code", 500 - i__2, 17L);
/*  may be several valid error code possibilities */
	i__2 = errinf_1.expsiz - 1;
	for (ix = 1; ix <= i__2; ++ix) {
	    s_wsfi(&io___24);
	    do_fio(&c__1, (char *)&errinf_1.experr[ix - 1], (ftnlen)sizeof(
		    integer));
	    e_wsfi();
	    i__3 = itrim_(tmsg, 500L) + 1;
/* Writing concatenation */
	    i__1[0] = 4, a__1[0] = acode;
	    i__1[1] = 1, a__1[1] = ",";
	    s_cat(tmsg + i__3, a__1, i__1, &c__2, 500 - i__3);
/* L20: */
	}
	if (errinf_1.expsiz >= 2) {
	    i__2 = itrim_(tmsg, 500L) - 1;
	    s_copy(tmsg + i__2, " and/or", 500 - i__2, 7L);
	}
	s_wsfi(&io___25);
	do_fio(&c__1, (char *)&errinf_1.experr[errinf_1.expsiz - 1], (ftnlen)
		sizeof(integer));
	e_wsfi();
	i__2 = itrim_(tmsg, 500L) + 1;
	s_copy(tmsg + i__2, acode, 500 - i__2, 4L);
	s_wsfi(&io___26);
	do_fio(&c__1, (char *)&(*expfun), (ftnlen)sizeof(integer));
	e_wsfi();
	if (errinf_1.usrerr == 1) {
	    i__2 = itrim_(tmsg, 500L);
/* Writing concatenation */
	    i__4[0] = 22, a__2[0] = ", function identifier ";
	    i__4[1] = 4, a__2[1] = acode;
	    i__4[2] = 39, a__2[2] = ", and the current error file identifier";

	    s_cat(tmsg + i__2, a__2, i__4, &c__3, 500 - i__2);
	} else {
	    i__2 = itrim_(tmsg, 500L) + 1;
/* Writing concatenation */
	    i__1[0] = 24, a__1[0] = "and function identifier ";
	    i__1[1] = 4, a__1[1] = acode;
	    s_cat(tmsg + i__2, a__1, i__1, &c__2, 500 - i__2);
	}
	i__2 = itrim_(tmsg, 500L) + 1;
	s_copy(tmsg + i__2, "to the user defined error handler.", 500 - i__2, 
		34L);
    } else if (errinf_1.usrerr == 2) {
	i__2 = itrim_(tmsg, 500L) + 1;
#ifndef NO_PROTO
	s_copy(tmsg + i__2, "write an accurate, self-identifying error messa"
		"ge on the error file.", 500 - i__2, 68L);
#else /* NO_PROTO */
	s_copy(tmsg + i__2, "write an accurate, self-identifying error messa\
ge on the error file.", 500 - i__2, 68L);
#endif /* NO_PROTO */
    } else if (errinf_1.usrerr == 4) {
	unmsg_("TSTERR called with USRERR=4.", 28L);
	i__2 = itrim_(tmsg, 500L) + 1;
#ifndef NO_PROTO
	s_copy(tmsg + i__2, "write an accurate, self-identifying error messa"
		"ge to the operator.", 500 - i__2, 66L);
#else /* NO_PROTO */
	s_copy(tmsg + i__2, "write an accurate, self-identifying error messa\
ge to the operator.", 500 - i__2, 66L);
#endif /* NO_PROTO */
    } else if (errinf_1.usrerr == 5) {
	s_copy(tmsg, condes, 500L, condes_len);
    } else {
	unmsg_("TSTERR detected an invalid value for USRERR.", 44L);
    }
    setmsg_(errchr_1.errsrs, tmsg, 40L, 500L);
/*  use this to make sure that error handler was called at least once: */
/*  for TSTAT, -1:fail, 0:pass, 1:no test yet */
    tstat = 1;
    if (errinf_1.usrerr == 1 || errinf_1.usrerr == 3) {
	goto L100;
    } else {
	goto L150;
    }
/*  *** *** *** ***   user-defined error handling   *** *** *** *** */
L100:
/*  loop thru and make sure all entries are valid */
/*  get next actual error result */
    ++errct;
    if (errct > 200) {
#ifndef NO_PROTO
	unmsg_("TSTERR tried to read past last entry in internal table of ge"
		"nerated errors.", 75L);
#else /* NO_PROTO */
	unmsg_("TSTERR tried to read past last entry in internal table of ge\
nerated errors.", 75L);
#endif /* NO_PROTO */
    }
    errinf_1.errcom = errinf_1.errsav[errct - 1];
    errinf_1.funcom = errinf_1.funsav[errct - 1];
    errinf_1.filcom = errinf_1.filsav[errct - 1];
/*  check if no more entries in this group */
    if (errinf_1.errcom == 2 && errinf_1.funcom == 180 && errinf_1.filcom == 
	    -666) {
	if (tstat == 0) {
	    pass_();
	} else if (tstat == 1) {
	    fail_();
#ifndef NO_PROTO
	    inmsg_("Tested function apparently did not call user defined err"
		    "or handling subroutine.", 79L);
#else /* NO_PROTO */
	    inmsg_("Tested function apparently did not call user defined err\
or handling subroutine.", 79L);
#endif /* NO_PROTO */
	}
	goto L999;
    }
/*  determine validity of actual error report */
    errok = iarfnd_(&errinf_1.errcom, &errinf_1.expsiz, errinf_1.experr) > 0;
    funok = errinf_1.funcom == *expfun;
/* no checking of error file when PHIGS is closed at time of error generat
ion*/
    filok = errinf_1.filcom == globnu_1.errfil || errinf_1.usrerr == 3;
/*  OK so far? */
    if (errok && funok && filok) {
	tstat = min(tstat,0);
	goto L100;
    }
    if (tstat >= 0) {
/*  first detected failure condition */
	fail_();
	tstat = -1;
    }
    if (! errok) {
	s_wsfi(&io___32);
	do_fio(&c__1, "Reported error number ", 22L);
	do_fio(&c__1, (char *)&errinf_1.errcom, (ftnlen)sizeof(integer));
	do_fio(&c__1, " is not one of the expected values.", 35L);
	e_wsfi();
	inmsg_(msg, 160L);
    }
    if (! funok) {
	s_wsfi(&io___33);
	do_fio(&c__1, "Reported function identifier ", 29L);
	do_fio(&c__1, (char *)&errinf_1.funcom, (ftnlen)sizeof(integer));
	do_fio(&c__1, " does not match expected function identifier ", 45L);
	do_fio(&c__1, (char *)&(*expfun), (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 160L);
    }
    if (! filok) {
	s_wsfi(&io___34);
	do_fio(&c__1, "Reported error file identifier ", 31L);
	do_fio(&c__1, (char *)&errinf_1.filcom, (ftnlen)sizeof(integer));
	do_fio(&c__1, " does not match expected error file identifier ", 47L);

	do_fio(&c__1, (char *)&globnu_1.errfil, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 160L);
    }
    goto L100;
/*  *** *** *** ***   system-defined error handling   *** *** *** *** */
L150:
/*  loop thru and make sure all error file messages are valid */
    gterrm_(&globnu_1.errfil, emsg, 1000L);
/*  check if no more entries */
    i__2 = leadnb_(emsg, 1000L) - 1;
    if (s_cmp(emsg, "end of error file", 1000L, 17L) == 0 || s_cmp(emsg + 
	    i__2, erlogt, itrim_(emsg, 1000L) - i__2, erlogt_len) == 0) {
	if (tstat == 0) {
	    pass_();
	} else if (tstat == 1) {
	    fail_();
#ifndef NO_PROTO
	    inmsg_("Tested function apparently did not call system defined e"
		    "rror handling subroutine.", 81L);
#else /* NO_PROTO */
	    inmsg_("Tested function apparently did not call system defined e\
rror handling subroutine.", 81L);
#endif /* NO_PROTO */
	}
	goto L999;
    }
    opmsg_(" ", 1L);
    opmsg_("------- Begin error message -------", 35L);
    opmsg_(emsg, 1000L);
    opmsg_("------- End error message -------", 33L);
    opmsg_(" ", 1L);
/*  determine validity of actual error report */
#ifndef NO_PROTO
    opmsg_("Based on the error message, which function caused the error?  En"
	    "ter either generic name in lower case, or numeric function code "
	    "from Fortran binding.  Enter a negative number if function canno"
	    "t be determined from the message.", 225L);
#else /* NO_PROTO */
    opmsg_("Based on the error message, which function caused the error?  En\
ter either generic name in lower case, or numeric function code from Fortran\
 binding.  Enter a negative number if function cannot be determined from the\
 message.", 225L);
#endif /* NO_PROTO */
L550:
    oplin_(funmsg, 80L);
    lnb = leadnb_(funmsg, 80L);
    lst = itrim_(funmsg, 80L);
    prsint_(funmsg + (lnb - 1), &genfun, &ierr, lst - (lnb - 1));
    if (ierr == 0) {
/*        integer response from operator - GENFUN set */
    } else {
/*  string response from operator */
	erfucd_(funmsg, &genfun, 80L);
	if (genfun < 0) {
	    opmsg_("Could not find the function you typed, try again.", 49L);
	    goto L550;
	}
    }
/*  GENFUN is now set */
    funok = genfun == *expfun;
L600:
#ifndef NO_PROTO
    opmsg_("If the error message indicates the numeric error code, enter it;"
	    " otherwise type \"n\".", 84L);
#else /* NO_PROTO */
    opmsg_("If the error message indicates the numeric error code, enter it;\
 otherwise type \"n\".", 84L);
#endif /* NO_PROTO */
    oplin_(funmsg, 80L);
    if (s_cmp(funmsg, "n", 80L, 1L) == 0) {
	goto L610;
    }
    lnb = leadnb_(funmsg, 80L);
    lst = itrim_(funmsg, 80L);
    prsint_(funmsg + (lnb - 1), &generr, &ierr, lst - (lnb - 1));
    if (ierr != 0) {
	opmsg_("Invalid reply; re-enter.", 24L);
	goto L600;
    }
/*  Explicit error code in message */
    errok = iarfnd_(&generr, &errinf_1.expsiz, errinf_1.experr) > 0;
    goto L690;
/*  No explicit error code in message */
L610:
    if (errinf_1.expsiz > 1) {
#ifndef NO_PROTO
	opmsg_("Here are the standard error messages for the valid error cod"
		"es:", 63L);
#else /* NO_PROTO */
	opmsg_("Here are the standard error messages for the valid error cod\
es:", 63L);
#endif /* NO_PROTO */
    } else {
	opmsg_("Here is the standard message wording:", 37L);
    }
    opmsg_("------- Begin standard wording -------", 38L);
    i__2 = errinf_1.expsiz;
    for (ix = 1; ix <= i__2; ++ix) {
	scherr_(&errinf_1.experr[ix - 1], errmsg, 180L);
	opmsg_(errmsg, 180L);
	if (ix < errinf_1.expsiz) {
	    opmsg_("-----------", 11L);
	} else {
	    opmsg_("------- End standard wording -------", 36L);
	}
/* L50: */
    }
#ifndef NO_PROTO
    opyn_("Does the meaning of the actual message match (one of) the standar"
	    "d message(s)?", ans, 78L, 1L);
#else /* NO_PROTO */
    opyn_("Does the meaning of the actual message match (one of) the standar\
d message(s)?", ans, 78L, 1L);
#endif /* NO_PROTO */
    errok = *ans == 'y';
L690:
/*  OK so far? */
    if (errok && funok) {
	tstat = min(tstat,0);
	goto L150;
    }
    if (tstat >= 0) {
/*  first detected failure condition */
	fail_();
	tstat = -1;
    }
    if (! errok) {
	if (s_cmp(funmsg, "n", 80L, 1L) == 0) {
#ifndef NO_PROTO
	    inmsg_("Incorrect description of error condition in error messag"
		    "e.", 58L);
#else /* NO_PROTO */
	    inmsg_("Incorrect description of error condition in error messag\
e.", 58L);
#endif /* NO_PROTO */
	} else {
	    s_wsfi(&io___43);
	    do_fio(&c__1, "Reported error number ", 22L);
	    do_fio(&c__1, (char *)&generr, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " is not one of the expected values.", 35L);
	    e_wsfi();
	    inmsg_(msg, 160L);
	}
    }
    if (! funok) {
	if (genfun < 0) {
	    inmsg_("Missing function identifier in error message.", 45L);
	} else {
	    s_wsfi(&io___44);
	    do_fio(&c__1, "Reported function identifier ", 29L);
	    do_fio(&c__1, (char *)&genfun, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " does not match expected function identifier ", 
		    45L);
	    do_fio(&c__1, (char *)&(*expfun), (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 160L);
	}
    }
    goto L150;
L999:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* tsterr_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/gterrm                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int gterrm_(integer *elun, char *emsg, ftnlen emsg_len)
#else /* NO_PROTO */
/* Subroutine */ int gterrm_(elun, emsg, emsg_len)
integer *elun;
char *emsg;
ftnlen emsg_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char erec[200] = "                                               "
	    "                                                                "
	    "                                                                "
	    "                         ";
#else /* NO_PROTO */
    static char erec[200+1] = "                                             \
                                                                            \
                                                                            \
   ";
#endif /* NO_PROTO */

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);
#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_copy();
    integer s_rsfe(), do_fio(), e_rsfe();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static char ans[1];
    static integer nmrk;
#ifndef NO_PROTO
    extern /* Subroutine */ int opyn_(char *, char *, ftnlen, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int opmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opyn_();
    extern integer itrim_();
    extern /* Subroutine */ int opmsg_();
#endif /* NO_PROTO */
    static logical first;
#ifndef NO_PROTO
    extern logical ermsgh_(char *, char *, integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern logical ermsgh_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static cilist io___48 = { 0, 0, 1, "(A)", 0 };
    static cilist io___49 = { 0, 0, 1, "(A)", 0 };


/*  GTERRM retrieves one error message from a specified error file */
/*  and returns it. */
/*  Input parameter: */
/*    ELUN : logical unit number from which to read */
/*  Output parameter: */
/*    EMSG : complete text of error message, even if spread over */
/*           several records; also used as input to tell whether */
/*           this is the first read or not. */
/*  special strings to control processing of error file */
    nmrk = itrim_(errchr_1.errmrk, 20L);
    if (s_cmp(errchr_1.errmrk, " ", 20L, 1L) != 0) {
/*  use special string to identify start of error message */
	first = s_cmp(emsg, "first call", emsg_len, 10L) == 0;
/*  start to fill EMSG from EREC */
L210:
	if (first) {
	    s_copy(emsg, " ", emsg_len, 1L);
	} else {
/*  EREC has first record of error message or EOF indicator */
	    s_copy(emsg, erec, emsg_len, 200L);
	}
	if (s_cmp(emsg, "end of error file", emsg_len, 17L) == 0) {
	    return 0;
	}
L250:
	io___48.ciunit = *elun;
	i__1 = s_rsfe(&io___48);
	if (i__1 != 0) {
	    goto L290;
	}
	i__1 = do_fio(&c__1, erec, 200L);
	if (i__1 != 0) {
	    goto L290;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L290;
	}
/*  EREC now has next record */
	if (ermsgh_(erec, errchr_1.errmrk, &nmrk, 200L, 20L)) {
/*  message header */
	    goto L295;
	} else {
/*  non-header */
	    i__1 = itrim_(emsg, emsg_len) + 1;
	    s_copy(emsg + i__1, erec, emsg_len - i__1, 200L);
	    goto L250;
	}
L290:
	s_copy(erec, "end of error file", 200L, 17L);
L295:
/*  EREC contains either EOFMRK or message header */
	if (first) {
	    first = FALSE_;
	    goto L210;
	}
    } else {
/*  operator must identify completion of error message */
	s_copy(emsg, " ", emsg_len, 1L);
L300:
	io___49.ciunit = *elun;
	i__1 = s_rsfe(&io___49);
	if (i__1 != 0) {
	    goto L310;
	}
	i__1 = do_fio(&c__1, erec, 200L);
	if (i__1 != 0) {
	    goto L310;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L310;
	}
	if (s_cmp(emsg, " ", emsg_len, 1L) == 0) {
	    s_copy(emsg, erec, emsg_len, 200L);
	} else {
	    i__1 = itrim_(emsg, emsg_len) + 1;
	    s_copy(emsg + i__1, erec, emsg_len - i__1, 200L);
	}
	if (s_cmp(emsg, " ", emsg_len, 1L) == 0) {
	    goto L300;
	}
	opmsg_("------- Begin message from error file: -------", 46L);
	opmsg_(emsg, emsg_len);
	opmsg_("------- End message from error file: -------", 44L);
	opyn_("Is the error message completely displayed? ", ans, 43L, 1L);
	if (*ans == 'n') {
	    goto L300;
	}
	goto L320;
L310:
	opmsg_("Hit EOF while trying to read error file.", 40L);
L320:
	;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* gterrm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 09.01/ermsgh                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical ermsgh_(char *erec, char *errmrk, integer *nmrk, ftnlen erec_len, 
	ftnlen errmrk_len)
#else /* NO_PROTO */
logical ermsgh_(erec, errmrk, nmrk, erec_len, errmrk_len)
char *erec, *errmrk;
integer *nmrk;
ftnlen erec_len;
ftnlen errmrk_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_indx();
#endif /* NO_PROTO */

/*  ERMSGH determines whether or not a given record from the error file is
 */
/*  the header of an error message, i.e. whether it is the first record of
 */
/*  a possibly multi-record message.  The default logic allows for */
/*  searching for the presence of a given string (ERRMRK) within the */
/*  record, but users may code any logic needed by which to distinguish */

/*  message headers. */
/* USERMOD modify if necessary. */
/*  Input parameters: */
/*    EREC   : record from error file to be examined */
/*    ERRMRK : distinctive character string identifying message header */
/*    NMRK   : number of significant characters in ERRMRK */
    ret_val = i_indx(erec, errmrk, erec_len, (*nmrk)) >= 1;
    return ret_val;
} /* ermsgh_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/scherr                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int scherr_(integer *errnum, char *errmsg, ftnlen errmsg_len)

#else /* NO_PROTO */
/* Subroutine */ int scherr_(errnum, errmsg, errmsg_len)
integer *errnum;
char *errmsg;
ftnlen errmsg_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer stdnum[111] = { 1,2,3,4,5,6,7,50,51,52,53,54,55,56,57,58,
	    59,60,61,62,63,64,100,101,102,103,104,105,106,107,108,109,110,111,
	    112,113,114,115,116,117,118,150,151,152,153,154,155,156,157,158,
	    159,160,161,162,163,164,200,201,202,203,204,205,206,207,208,250,
	    251,252,253,254,255,256,257,258,259,260,261,262,263,300,301,302,
	    303,304,305,306,307,350,351,400,401,402,403,404,405,406,407,408,
	    450,2000,2001,2002,2003,2004,2005,2006,2200,2201,2202,2203,2204 };


    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer msgdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static char stdmsg[180];

/*  SCHERR accepts a valid error code and returns the standard */
/*  corresponding error message. */

/*  Input parameter: */
/*    ERRNUM: Standard error code */
/*  Output parameter: */
/*    ERRMSG: Wording of corresponding standard error message */
/*  List of standard error codes */
    msgdx = iarfnd_(errnum, &c__111, stdnum);
    if (msgdx < 1) {
	unmsg_("SCHERR called with invalid ERRNUM.", 34L);
    }
#ifndef NO_PROTO
    switch (msgdx) {
#else /* NO_PROTO */
    switch ((int)msgdx) {
#endif /* NO_PROTO */
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L10;
	case 11:  goto L11;
	case 12:  goto L12;
	case 13:  goto L13;
	case 14:  goto L14;
	case 15:  goto L15;
	case 16:  goto L16;
	case 17:  goto L17;
	case 18:  goto L18;
	case 19:  goto L19;
	case 20:  goto L20;
	case 21:  goto L21;
	case 22:  goto L22;
	case 23:  goto L23;
	case 24:  goto L24;
	case 25:  goto L25;
	case 26:  goto L26;
	case 27:  goto L27;
	case 28:  goto L28;
	case 29:  goto L29;
	case 30:  goto L30;
	case 31:  goto L31;
	case 32:  goto L32;
	case 33:  goto L33;
	case 34:  goto L34;
	case 35:  goto L35;
	case 36:  goto L36;
	case 37:  goto L37;
	case 38:  goto L38;
	case 39:  goto L39;
	case 40:  goto L40;
	case 41:  goto L41;
	case 42:  goto L42;
	case 43:  goto L43;
	case 44:  goto L44;
	case 45:  goto L45;
	case 46:  goto L46;
	case 47:  goto L47;
	case 48:  goto L48;
	case 49:  goto L49;
	case 50:  goto L50;
	case 51:  goto L51;
	case 52:  goto L52;
	case 53:  goto L53;
	case 54:  goto L54;
	case 55:  goto L55;
	case 56:  goto L56;
	case 57:  goto L57;
	case 58:  goto L58;
	case 59:  goto L59;
	case 60:  goto L60;
	case 61:  goto L61;
	case 62:  goto L62;
	case 63:  goto L63;
	case 64:  goto L64;
	case 65:  goto L65;
	case 66:  goto L66;
	case 67:  goto L67;
	case 68:  goto L68;
	case 69:  goto L69;
	case 70:  goto L70;
	case 71:  goto L71;
	case 72:  goto L72;
	case 73:  goto L73;
	case 74:  goto L74;
	case 75:  goto L75;
	case 76:  goto L76;
	case 77:  goto L77;
	case 78:  goto L78;
	case 79:  goto L79;
	case 80:  goto L80;
	case 81:  goto L81;
	case 82:  goto L82;
	case 83:  goto L83;
	case 84:  goto L84;
	case 85:  goto L85;
	case 86:  goto L86;
	case 87:  goto L87;
	case 88:  goto L88;
	case 89:  goto L89;
	case 90:  goto L90;
	case 91:  goto L91;
	case 92:  goto L92;
	case 93:  goto L93;
	case 94:  goto L94;
	case 95:  goto L95;
	case 96:  goto L96;
	case 97:  goto L97;
	case 98:  goto L98;
	case 99:  goto L99;
	case 100:  goto L2000;
	case 101:  goto L2001;
	case 102:  goto L2002;
	case 103:  goto L2003;
	case 104:  goto L2004;
	case 105:  goto L2005;
	case 106:  goto L2006;
	case 107:  goto L2200;
	case 108:  goto L2201;
	case 109:  goto L2202;
	case 110:  goto L2203;
	case 111:  goto L2204;
    }
    unmsg_("SCHERR called with very invalid ERRNUM.", 39L);
/*  List of standard error messages */
L1:
    s_copy(stdmsg, "(PHCL,WSCL,STCL,ARCL)", 180L, 21L);
    goto L101;
L2:
    s_copy(stdmsg, "(PHOP,*,*,*)", 180L, 12L);
    goto L101;
L3:
    s_copy(stdmsg, "(PHOP,WSOP,*,*)", 180L, 15L);
    goto L101;
L4:
    s_copy(stdmsg, "(PHOP,WSCL,STCL,ARCL)", 180L, 21L);
    goto L101;
L5:
    s_copy(stdmsg, "(PHOP,*,STOP,*)", 180L, 15L);
    goto L101;
L6:
    s_copy(stdmsg, "(PHOP,*,STCL,*)", 180L, 15L);
    goto L101;
L7:
    s_copy(stdmsg, "(PHOP,*,*,AROP)", 180L, 15L);
    goto L101;
L8:
#ifndef NO_PROTO
    s_copy(stdmsg, "connection identifier not recognized by the implementati"
	    "on", 180L, 58L);
#else /* NO_PROTO */
    s_copy(stdmsg, "connection identifier not recognized by the implementati\
on", 180L, 58L);
#endif /* NO_PROTO */
    goto L101;
L9:
#ifndef NO_PROTO
    s_copy(stdmsg, "this information is not yet available for this generic w"
	    "orkstation type; open a workstation of this type and use the spe"
	    "cific workstation type", 180L, 142L);
#else /* NO_PROTO */
    s_copy(stdmsg, "this information is not yet available for this generic w\
orkstation type; open a workstation of this type and use the specific workst\
ation type", 180L, 142L);
#endif /* NO_PROTO */
    goto L101;
L10:
    s_copy(stdmsg, "workstation type not recognized by the implementation", 
	    180L, 53L);
    goto L101;
L11:
    s_copy(stdmsg, "workstation identifier already is in use", 180L, 40L);
    goto L101;
L12:
    s_copy(stdmsg, "the specified workstation is not open", 180L, 37L);
    goto L101;
L13:
#ifndef NO_PROTO
    s_copy(stdmsg, "workstation cannot be opened for an implementation depen"
	    "dent reason", 180L, 67L);
#else /* NO_PROTO */
    s_copy(stdmsg, "workstation cannot be opened for an implementation depen\
dent reason", 180L, 67L);
#endif /* NO_PROTO */
    goto L101;
L14:
    s_copy(stdmsg, "specified workstation is not of category MO", 180L, 43L);
    goto L101;
L15:
    s_copy(stdmsg, "specified workstation is of category MI", 180L, 39L);
    goto L101;
L16:
    s_copy(stdmsg, "specified workstation is not of category MI", 180L, 43L);
    goto L101;
L17:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified workstation does not have output capabilit"
	    "y (i.e., the workstation category is neither OUTPUT, OUTIN, nor "
	    "MO)", 180L, 123L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified workstation does not have output capabilit\
y (i.e., the workstation category is neither OUTPUT, OUTIN, nor MO)", 180L, 
	    123L);
#endif /* NO_PROTO */
    goto L101;
L18:
    s_copy(stdmsg, "specified workstation is not of category OUTIN", 180L, 
	    46L);
    goto L101;
L19:
#ifndef NO_PROTO
    s_copy(stdmsg, "specified workstation is neither of category INPUT nor o"
	    "f category OUTIN", 180L, 72L);
#else /* NO_PROTO */
    s_copy(stdmsg, "specified workstation is neither of category INPUT nor o\
f category OUTIN", 180L, 72L);
#endif /* NO_PROTO */
    goto L101;
L20:
#ifndef NO_PROTO
    s_copy(stdmsg, "this information is not available for this MO workstatio"
	    "n type", 180L, 62L);
#else /* NO_PROTO */
    s_copy(stdmsg, "this information is not available for this MO workstatio\
n type", 180L, 62L);
#endif /* NO_PROTO */
    goto L101;
L21:
#ifndef NO_PROTO
    s_copy(stdmsg, "opening this workstation would exceed the maximum number"
	    " of simultaneously open workstations", 180L, 92L);
#else /* NO_PROTO */
    s_copy(stdmsg, "opening this workstation would exceed the maximum number\
 of simultaneously open workstations", 180L, 92L);
#endif /* NO_PROTO */
    goto L101;
L22:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified workstation type is not able to generate t"
	    "he specified GDP", 180L, 72L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified workstation type is not able to generate t\
he specified GDP", 180L, 72L);
#endif /* NO_PROTO */
    goto L101;
L23:
    s_copy(stdmsg, "the bundle index value is less than one", 180L, 39L);
    goto L101;
L24:
    s_copy(stdmsg, "the specified representation has not been defined", 180L, 
	    49L);
    goto L101;
L25:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified representation has not been predefined on "
	    "this workstation", 180L, 72L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified representation has not been predefined on \
this workstation", 180L, 72L);
#endif /* NO_PROTO */
    goto L101;
L26:
#ifndef NO_PROTO
    s_copy(stdmsg, "setting this bundle table entry would exceed the maximum"
	    " number of entries allowed in the workstation bundle table", 180L,
	     114L);
#else /* NO_PROTO */
    s_copy(stdmsg, "setting this bundle table entry would exceed the maximum\
 number of entries allowed in the workstation bundle table", 180L, 114L);
#endif /* NO_PROTO */
    goto L101;
L27:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified linetype is not available on the specified"
	    " workstation", 180L, 68L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified linetype is not available on the specified\
 workstation", 180L, 68L);
#endif /* NO_PROTO */
    goto L101;
L28:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified marker type is not available on the specif"
	    "ied workstation", 180L, 71L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified marker type is not available on the specif\
ied workstation", 180L, 71L);
#endif /* NO_PROTO */
    goto L101;
L29:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified font is not available for the requested te"
	    "xt precision on the specified workstation", 180L, 97L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified font is not available for the requested te\
xt precision on the specified workstation", 180L, 97L);
#endif /* NO_PROTO */
    goto L101;
L30:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified edgetype is not available on the specified"
	    " workstation", 180L, 68L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified edgetype is not available on the specified\
 workstation", 180L, 68L);
#endif /* NO_PROTO */
    goto L101;
L31:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified interior style is not available on the wor"
	    "kstation", 180L, 64L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified interior style is not available on the wor\
kstation", 180L, 64L);
#endif /* NO_PROTO */
    goto L101;
L32:
#ifndef NO_PROTO
    s_copy(stdmsg, "interior style PATTERN is not suppported on the workstat"
	    "ion", 180L, 59L);
#else /* NO_PROTO */
    s_copy(stdmsg, "interior style PATTERN is not suppported on the workstat\
ion", 180L, 59L);
#endif /* NO_PROTO */
    goto L101;
L33:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified colour model is not available on the works"
	    "tation", 180L, 62L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified colour model is not available on the works\
tation", 180L, 62L);
#endif /* NO_PROTO */
    goto L101;
L34:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified HLHSR model is not available on the specif"
	    "ied workstation", 180L, 71L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified HLHSR model is not available on the specif\
ied workstation", 180L, 71L);
#endif /* NO_PROTO */
    goto L101;
L35:
    s_copy(stdmsg, "the pattern index value is less than one", 180L, 40L);
    goto L101;
L36:
    s_copy(stdmsg, "the colour index value is less than zero", 180L, 40L);
    goto L101;
L37:
    s_copy(stdmsg, "the view index value is less than zero", 180L, 38L);
    goto L101;
L38:
    s_copy(stdmsg, "the view index value is less than one", 180L, 37L);
    goto L101;
L39:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the dimensions of pattern colour index array is l"
	    "ess than one", 180L, 68L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the dimensions of pattern colour index array is l\
ess than one", 180L, 68L);
#endif /* NO_PROTO */
    goto L101;
L40:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the dimensions of the colour index array is less "
	    "than zero", 180L, 65L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the dimensions of the colour index array is less \
than zero", 180L, 65L);
#endif /* NO_PROTO */
    goto L101;
L41:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the components of the colour specification is out"
	    " of range.  The valid range is dependent upon the current colour"
	    " model", 180L, 126L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the components of the colour specification is out\
 of range.  The valid range is dependent upon the current colour model", 180L,
	     126L);
#endif /* NO_PROTO */
    goto L101;
L42:
#ifndef NO_PROTO
    s_copy(stdmsg, "setting this view table entry would exceed the maximum n"
	    "umber of entries allowed in the workstation view table", 180L, 
	    110L);
#else /* NO_PROTO */
    s_copy(stdmsg, "setting this view table entry would exceed the maximum n\
umber of entries allowed in the workstation view table", 180L, 110L);
#endif /* NO_PROTO */
    goto L101;
L43:
#ifndef NO_PROTO
    s_copy(stdmsg, "invalid window: XMIN>=XMAX, YMIN>=YMAX, ZMIN>ZMAX, UMIN>"
	    "=UMAX or VMIN>=VMAX", 180L, 75L);
#else /* NO_PROTO */
    s_copy(stdmsg, "invalid window: XMIN>=XMAX, YMIN>=YMAX, ZMIN>ZMAX, UMIN>\
=UMAX or VMIN>=VMAX", 180L, 75L);
#endif /* NO_PROTO */
    goto L101;
L44:
    s_copy(stdmsg, "invalid viewport: XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX", 
	    180L, 54L);
    goto L101;
L45:
#ifndef NO_PROTO
    s_copy(stdmsg, "invalid view clipping limits: XMIN>=XMAX, YMIN>=YMAX or "
	    "ZMIN>ZMAX", 180L, 65L);
#else /* NO_PROTO */
    s_copy(stdmsg, "invalid view clipping limits: XMIN>=XMAX, YMIN>=YMAX or \
ZMIN>ZMAX", 180L, 65L);
#endif /* NO_PROTO */
    goto L101;
L46:
    s_copy(stdmsg, "the view clipping limits are not within NPC range", 180L, 
	    49L);
    goto L101;
L47:
    s_copy(stdmsg, "the projection viewport limits are not within NPC range", 
	    180L, 55L);
    goto L101;
L48:
    s_copy(stdmsg, "the workstation window limits are not within NPC range", 
	    180L, 54L);
    goto L101;
L49:
    s_copy(stdmsg, "the workstation viewport is not within display space", 
	    180L, 52L);
    goto L101;
L50:
#ifndef NO_PROTO
    s_copy(stdmsg, "front plane and back plane distances are equal when z-ex"
	    "tent of the projection viewport is non-zero", 180L, 99L);
#else /* NO_PROTO */
    s_copy(stdmsg, "front plane and back plane distances are equal when z-ex\
tent of the projection viewport is non-zero", 180L, 99L);
#endif /* NO_PROTO */
    goto L101;
L51:
    s_copy(stdmsg, "the view plane normal vector has length zero", 180L, 44L);

    goto L101;
L52:
    s_copy(stdmsg, "the view up vector has length zero", 180L, 34L);
    goto L101;
L53:
#ifndef NO_PROTO
    s_copy(stdmsg, "the view up and view plane normal vectors are parallel t"
	    "hus the viewing coordinate system cannot be established", 180L, 
	    111L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the view up and view plane normal vectors are parallel t\
hus the viewing coordinate system cannot be established", 180L, 111L);
#endif /* NO_PROTO */
    goto L101;
L54:
#ifndef NO_PROTO
    s_copy(stdmsg, "the projection reference point is between the front and "
	    "back planes", 180L, 67L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the projection reference point is between the front and \
back planes", 180L, 67L);
#endif /* NO_PROTO */
    goto L101;
L55:
#ifndef NO_PROTO
    s_copy(stdmsg, "the projection reference point cannot be positioned on t"
	    "he view plane", 180L, 69L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the projection reference point cannot be positioned on t\
he view plane", 180L, 69L);
#endif /* NO_PROTO */
    goto L101;
L56:
    s_copy(stdmsg, "the back plane is in front of the front plane", 180L, 45L)
	    ;
    goto L101;
L57:
    s_copy(stdmsg, "Warning, ignoring structures that do not exist", 180L, 
	    46L);
    goto L101;
L58:
    s_copy(stdmsg, "the specified structure does not exist", 180L, 38L);
    goto L101;
L59:
    s_copy(stdmsg, "the specified element does not exist", 180L, 36L);
    goto L101;
L60:
    s_copy(stdmsg, "specified starting path not found in CSS", 180L, 40L);
    goto L101;
L61:
    s_copy(stdmsg, "specified search ceiling index out of range", 180L, 43L);
    goto L101;
L62:
#ifndef NO_PROTO
    s_copy(stdmsg, "the table does not exist in the open structure between t"
	    "he element pointer and the end of the structure", 180L, 103L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the table does not exist in the open structure between t\
he element pointer and the end of the structure", 180L, 103L);
#endif /* NO_PROTO */
    goto L101;
L63:
#ifndef NO_PROTO
    s_copy(stdmsg, "one or both of the labels does not exist in the open str"
	    "ucture between the element pointer and the end of structure", 
	    180L, 115L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one or both of the labels does not exist in the open str\
ucture between the element pointer and the end of structure", 180L, 115L);
#endif /* NO_PROTO */
    goto L101;
L64:
    s_copy(stdmsg, "the specified path depth is less than zero", 180L, 42L);
    goto L101;
L65:
    s_copy(stdmsg, "the display priority is out of range", 180L, 36L);
    goto L101;
L66:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified device is not available on the specified w"
	    "orkstation ", 180L, 67L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified device is not available on the specified w\
orkstation ", 180L, 67L);
#endif /* NO_PROTO */
    goto L101;
L67:
#ifndef NO_PROTO
    s_copy(stdmsg, "the function requires the input device to be in REQUEST "
	    "mode", 180L, 60L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the function requires the input device to be in REQUEST \
mode", 180L, 60L);
#endif /* NO_PROTO */
    goto L101;
L68:
#ifndef NO_PROTO
    s_copy(stdmsg, "the function requires the input device to be in SAMPLE m"
	    "ode", 180L, 59L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the function requires the input device to be in SAMPLE m\
ode", 180L, 59L);
#endif /* NO_PROTO */
    goto L101;
L69:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified prompt/echo type is not available on the s"
	    "pecified workstation", 180L, 76L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified prompt/echo type is not available on the s\
pecified workstation", 180L, 76L);
#endif /* NO_PROTO */
    goto L101;
L70:
#ifndef NO_PROTO
    s_copy(stdmsg, "invalid echo area/volume; XMIN>=XMAX,YMIN>=YMAX or ZMIN>"
	    "ZMAX", 180L, 60L);
#else /* NO_PROTO */
    s_copy(stdmsg, "invalid echo area/volume; XMIN>=XMAX,YMIN>=YMAX or ZMIN>\
ZMAX", 180L, 60L);
#endif /* NO_PROTO */
    goto L101;
L71:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the echo area/volume boundary points is outside t"
	    "he range of the device", 180L, 78L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the echo area/volume boundary points is outside t\
he range of the device", 180L, 78L);
#endif /* NO_PROTO */
    goto L101;
L72:
    s_copy(stdmsg, "Warning, the input queue has overflowed", 180L, 39L);
    goto L101;
L73:
#ifndef NO_PROTO
    s_copy(stdmsg, "input queue has not overflowed, since OPEN PHIGS or last"
	    " invocation of INQUIRE INPUT QUEUE OVERFLOW", 180L, 99L);
#else /* NO_PROTO */
    s_copy(stdmsg, "input queue has not overflowed, since OPEN PHIGS or last\
 invocation of INQUIRE INPUT QUEUE OVERFLOW", 180L, 99L);
#endif /* NO_PROTO */
    goto L101;
L74:
#ifndef NO_PROTO
    s_copy(stdmsg, "input queue has overflowed, but associated workstation h"
	    "as been closed", 180L, 70L);
#else /* NO_PROTO */
    s_copy(stdmsg, "input queue has overflowed, but associated workstation h\
as been closed", 180L, 70L);
#endif /* NO_PROTO */
    goto L101;
L75:
#ifndef NO_PROTO
    s_copy(stdmsg, "the input device class of the current input report does "
	    "not match the class being requested", 180L, 91L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the input device class of the current input report does \
not match the class being requested", 180L, 91L);
#endif /* NO_PROTO */
    goto L101;
L76:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the fields within the input device data record is"
	    " in error", 180L, 65L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the fields within the input device data record is\
 in error", 180L, 65L);
#endif /* NO_PROTO */
    goto L101;
L77:
    s_copy(stdmsg, "initial value is invalid", 180L, 24L);
    goto L101;
L78:
#ifndef NO_PROTO
    s_copy(stdmsg, "number of points in the initial stroke is greater than t"
	    "he buffer size", 180L, 70L);
#else /* NO_PROTO */
    s_copy(stdmsg, "number of points in the initial stroke is greater than t\
he buffer size", 180L, 70L);
#endif /* NO_PROTO */
    goto L101;
L79:
#ifndef NO_PROTO
    s_copy(stdmsg, "length of the initial string is greater than the buffer "
	    "size", 180L, 60L);
#else /* NO_PROTO */
    s_copy(stdmsg, "length of the initial string is greater than the buffer \
size", 180L, 60L);
#endif /* NO_PROTO */
    goto L101;
L80:
    s_copy(stdmsg, "item type is not allowed for user items", 180L, 39L);
    goto L101;
L81:
    s_copy(stdmsg, "item length is invalid ", 180L, 23L);
    goto L101;
L82:
    s_copy(stdmsg, "no item is left in metafile input", 180L, 33L);
    goto L101;
L83:
    s_copy(stdmsg, "metafile item is invalid", 180L, 24L);
    goto L101;
L84:
    s_copy(stdmsg, "item type is unknown", 180L, 20L);
    goto L101;
L85:
#ifndef NO_PROTO
    s_copy(stdmsg, "content of item data record is invalid for the specified"
	    " item type", 180L, 66L);
#else /* NO_PROTO */
    s_copy(stdmsg, "content of item data record is invalid for the specified\
 item type", 180L, 66L);
#endif /* NO_PROTO */
    goto L101;
L86:
    s_copy(stdmsg, "maximum item data record length is invalid", 180L, 42L);
    goto L101;
L87:
    s_copy(stdmsg, "user item cannot be interpreted", 180L, 31L);
    goto L101;
L88:
#ifndef NO_PROTO
    s_copy(stdmsg, "Warning, the specified escape is not available on one or"
	    " more workstations in this implementation.  The escape will be p"
	    "rocessed by those workstations on which it is available", 180L, 
	    175L);
#else /* NO_PROTO */
    s_copy(stdmsg, "Warning, the specified escape is not available on one or\
 more workstations in this implementation.  The escape will be processed by \
those workstations on which it is available", 180L, 175L);
#endif /* NO_PROTO */
    goto L101;
L89:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the fields within the escape data record is in er"
	    "ror", 180L, 59L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the fields within the escape data record is in er\
ror", 180L, 59L);
#endif /* NO_PROTO */
    goto L101;
L90:
    s_copy(stdmsg, "the archive file cannot be opened", 180L, 33L);
    goto L101;
L91:
#ifndef NO_PROTO
    s_copy(stdmsg, "opening this archive file would exceed the maximum numbe"
	    "r of simultaneously open archive files", 180L, 94L);
#else /* NO_PROTO */
    s_copy(stdmsg, "opening this archive file would exceed the maximum numbe\
r of simultaneously open archive files", 180L, 94L);
#endif /* NO_PROTO */
    goto L101;
L92:
    s_copy(stdmsg, "archive file identifier already in use", 180L, 38L);
    goto L101;
L93:
    s_copy(stdmsg, "the archive file is not a PHIGS archive file", 180L, 44L);

    goto L101;
L94:
    s_copy(stdmsg, "the specified archive file is not open", 180L, 38L);
    goto L101;
L95:
#ifndef NO_PROTO
    s_copy(stdmsg, "name conflict occurred while conflict resolution flag ha"
	    "s value ABANDON", 180L, 71L);
#else /* NO_PROTO */
    s_copy(stdmsg, "name conflict occurred while conflict resolution flag ha\
s value ABANDON", 180L, 71L);
#endif /* NO_PROTO */
    goto L101;
L96:
#ifndef NO_PROTO
    s_copy(stdmsg, "Warning, the archive file is full.  Any structures that "
	    "were archived were archived in total", 180L, 92L);
#else /* NO_PROTO */
    s_copy(stdmsg, "Warning, the archive file is full.  Any structures that \
were archived were archived in total", 180L, 92L);
#endif /* NO_PROTO */
    goto L101;
L97:
#ifndef NO_PROTO
    s_copy(stdmsg, "Warning, some of the specified structures do not exist o"
	    "n the archive file", 180L, 74L);
#else /* NO_PROTO */
    s_copy(stdmsg, "Warning, some of the specified structures do not exist o\
n the archive file", 180L, 74L);
#endif /* NO_PROTO */
    goto L101;
L98:
#ifndef NO_PROTO
    s_copy(stdmsg, "Warning, some of the specified structures do not exist o"
	    "n the archive file.  PHIGS will create empty structure in their "
	    "place", 180L, 125L);
#else /* NO_PROTO */
    s_copy(stdmsg, "Warning, some of the specified structures do not exist o\
n the archive file.  PHIGS will create empty structure in their place", 180L, 
	    125L);
#endif /* NO_PROTO */
    goto L101;
L99:
    s_copy(stdmsg, "the specified error file is invalid", 180L, 35L);
    goto L101;
L2000:
    s_copy(stdmsg, "enumeration type out of range", 180L, 29L);
    goto L101;
L2001:
    s_copy(stdmsg, "output parameter size insufficient", 180L, 34L);
    goto L101;
L2002:
    s_copy(stdmsg, "list or set element not available", 180L, 33L);
    goto L101;
L2003:
    s_copy(stdmsg, "invalid data record", 180L, 19L);
    goto L101;
L2004:
    s_copy(stdmsg, "input parameter size out of range", 180L, 33L);
    goto L101;
L2005:
    s_copy(stdmsg, "invalid list of point lists", 180L, 27L);
    goto L101;
L2006:
    s_copy(stdmsg, "invalid list of filters", 180L, 23L);
    goto L101;
L2200:
    s_copy(stdmsg, "start index is out of range", 180L, 27L);
    goto L101;
L2201:
    s_copy(stdmsg, "length of application's list is negative", 180L, 40L);
    goto L101;
L2202:
    s_copy(stdmsg, "enumeration type out of range", 180L, 29L);
    goto L101;
L2203:
    s_copy(stdmsg, "error while allocating a Store", 180L, 30L);
    goto L101;
L2204:
    s_copy(stdmsg, "error while allocating memory", 180L, 29L);
    goto L101;
L101:
    if (msgdx <= 7) {
/* Writing concatenation */
	i__1[0] = 43, a__1[0] = "Ignoring function, function requires state ";

	i__1[1] = 180, a__1[1] = stdmsg;
	s_cat(errmsg, a__1, i__1, &c__2, errmsg_len);
    } else if (s_cmp(stdmsg, "Warning", 7L, 7L) == 0) {
	s_copy(errmsg, stdmsg, errmsg_len, 180L);
    } else {
/* Writing concatenation */
	i__1[0] = 19, a__1[0] = "Ignoring function, ";
	i__1[1] = 180, a__1[1] = stdmsg;
	s_cat(errmsg, a__1, i__1, &c__2, errmsg_len);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* scherr_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/tstign                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tstign_(logical *ignore)
#else /* NO_PROTO */
/* Subroutine */ int tstign_(ignore)
logical *ignore;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
    extern integer itrim_();
#endif /* NO_PROTO */
    static char funnam[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int erfunm_(integer *, char *, ftnlen), setmsg_(
	    char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int erfunm_(), setmsg_();
#endif /* NO_PROTO */

/*  TSTIGN is used to test that a function signalling an error is */
/*  ignored. */
/*  Input parameters: */
/*   IGNORE : logical variable indicating whether the function was ignored
*/
    erfunm_(&errinf_1.efid[errinf_1.efcnt - 1], funnam, 80L);
/* Writing concatenation */
    i__1[0] = 3, a__1[0] = "If ";
    i__1[1] = 80, a__1[1] = funnam;
    s_cat(msg, a__1, i__1, &c__2, 300L);
    i__2 = itrim_(msg, 300L) + 1;
/* Writing concatenation */
    i__1[0] = 25, a__1[0] = "signals an error because ";
    i__1[1] = 200, a__1[1] = errchr_1.curcon;
    s_cat(msg + i__2, a__1, i__1, &c__2, 300 - i__2);
    i__2 = itrim_(msg, 300L);
    s_copy(msg + i__2, ", it should not cause any other effect.", 300 - i__2, 
	    39L);
    setmsg_(errchr_1.errsrs, msg, 40L, 300L);
    ifpf_(ignore);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstign_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION 09.01/streq                       * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical streq_(char *req, ftnlen req_len)
#else /* NO_PROTO */
logical streq_(req, req_len)
char *req;
ftnlen req_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer nar, ast, nwk, pst, sst, wst, idum1, idum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqarf (integer *, integer *, integer *, 
	    integer *, integer *), nqars (integer *), unmsg_(char *, ftnlen), 
	    nqsys (integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqarf (), nqars (), unmsg_(), nqsys (), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer errind, opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopwk (integer *, integer *, integer *, 
	    integer *), nqopst (integer *, integer *, integer *), nqwkst (
	    integer *), nqstrs (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopwk (), nqopst (), nqwkst (), nqstrs ();
#endif /* NO_PROTO */

/*  STREQ determines whether a required state is actually in force, */
/*  as reported by all the relevant inquire functions. */

/*  Input parameter: */
/*    REQ : 4-character code for required state, position 1-4 standing */
/*          for PHIGS, Workstation, Structure, and Archive, respectively. 
*/
/*          Each position must be 'O', 'C', or '*', standing for open, */
/*          closed, and don't care. */
/* system state value */
/* workstation state */
/* structure state value */
/* archive state */
/* open-structure status */
    ret_val = FALSE_;
    nqsys (&pst);
    nqwkst (&wst);
    nqstrs (&sst);
    nqars (&ast);
    if (*req == 'O') {
/*  PHIGS should be open */
	if (pst != 1) {
	    return ret_val;
	}
	if (req[1] == '*') {
/*           don't care about workstation status */
	} else {
	    nqopwk (&c__0, &errind, &nwk, &idum1);
	    chkinq_("pqopwk", &errind, 6L);
	    if (req[1] == 'O') {
		if (wst != 1) {
		    return ret_val;
		}
		if (nwk < 1) {
		    return ret_val;
		}
	    } else if (req[1] == 'C') {
		if (wst != 0) {
		    return ret_val;
		}
		if (nwk != 0) {
		    return ret_val;
		}
	    } else {
#ifndef NO_PROTO
		unmsg_("Second character of parameter to STREQ must be O or "
			"C or *.", 59L);
#else /* NO_PROTO */
		unmsg_("Second character of parameter to STREQ must be O or \
C or *.", 59L);
#endif /* NO_PROTO */
	    }
	}
	if (req[2] == '*') {
/*           don't care about structure status */
	} else {
	    nqopst (&errind, &opstat, &idum1);
	    chkinq_("pqopst", &errind, 6L);
	    if (req[2] == 'O') {
		if (sst != 1) {
		    return ret_val;
		}
		if (opstat != 1) {
		    return ret_val;
		}
	    } else if (req[2] == 'C') {
		if (sst != 0) {
		    return ret_val;
		}
		if (opstat != 0) {
		    return ret_val;
		}
	    } else {
#ifndef NO_PROTO
		unmsg_("Third character of parameter to STREQ must be O or C"
			" or *.", 58L);
#else /* NO_PROTO */
		unmsg_("Third character of parameter to STREQ must be O or C\
 or *.", 58L);
#endif /* NO_PROTO */
	    }
	}
	if (req[3] == '*') {
/*           don't care about archive status */
	} else {
	    nqarf (&c__0, &errind, &nar, &idum1, &idum2);
	    chkinq_("pqarf", &errind, 5L);
	    if (req[3] == 'O') {
		if (ast != 1) {
		    return ret_val;
		}
		if (nar < 1) {
		    return ret_val;
		}
	    } else if (req[3] == 'C') {
		if (ast != 0) {
		    return ret_val;
		}
		if (nar != 0) {
		    return ret_val;
		}
	    } else {
#ifndef NO_PROTO
		unmsg_("Fourth character of parameter to STREQ must be O or "
			"C or *.", 59L);
#else /* NO_PROTO */
		unmsg_("Fourth character of parameter to STREQ must be O or \
C or *.", 59L);
#endif /* NO_PROTO */
	    }
	}
    } else if (*req == 'C') {
/*  PHIGS should be closed */
	if (s_cmp(req, "CCCC", 4L, 4L) != 0) {
	    unmsg_("STREQ parameter should be CCCC.", 31L);
	}
	if (pst != 0) {
	    return ret_val;
	}
	if (wst != 0) {
	    return ret_val;
	}
	if (sst != 0) {
	    return ret_val;
	}
	if (ast != 0) {
	    return ret_val;
	}
    } else {
	unmsg_("First character of parameter to STREQ must be O or C.", 53L);
    }
    ret_val = TRUE_;
    return ret_val;
} /* streq_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/rfuncs                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int rfuncs_0_(int n__, integer *i1, integer *i2, integer *
	wkid, real *ra, real *rb, real *rc, real *r1, real *r2, char *chars, 
	real *r3, real *r4, integer *ia, integer *i3, integer *i4, integer *
	i5, integer *i6, integer *i7, integer *ib, real *xfa, real *xfb, real 
	*vclip, real *xga, real *xgb, integer *i8, ftnlen chars_len)
{
    extern /* Subroutine */ int nca (real *, real *, real *, real *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    ), nfa (integer *, real *, real *), nlb (integer *), npl (integer 
	    *, real *, real *), npm (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen), nca3 (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nfa3 (integer *, real *, real *, real *), npl3 (integer *, real *
	    , real *, real *), ndel (void), nads (integer *, integer *), 
	    natr (real *, real *, real *, real *, char *, ftnlen), nfas (
	    integer *, integer *, real *, real *), nsii (integer *), nsis (
	    integer *), nsir (integer *, integer *, integer *, integer *, 
	    integer *), nsln (integer *), nuwk (integer *, integer *), nres (
	    integer *, integer *), nrst (integer *, integer *), nscr (integer 
	    *, integer *, integer *, real *), nsep (integer *), ndsn (integer 
	    *, integer *), nfas3 (integer *, integer *, real *, real *, real *
	    ), nopph (integer *, integer *), echkz_(integer *), nclph (void), 
	    nopwk (integer *, integer *, integer *), nopst (integer *), 
	    nclwk (integer *), nsdus (integer *, integer *, integer *), 
	    nsplr (integer *, integer *, integer *, real *, integer *), 
	    nspmr (integer *, integer *, integer *, real *, integer *), 
	    nstxp (integer *), nstxal (integer *, integer *), nsatal (integer 
	    *, integer *), nsmksc (real *), nstxfn (integer *), nsans (
	    integer *), nsparf (real *, real *), nspar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nstxr (integer *, integer *, integer *, integer *, 
	    real *, real *, integer *), nsedi (integer *), nsedci (integer *),
	     nsplci (integer *), nstxci (integer *), nstxi (integer *), 
	    nsedr (integer *, integer *, integer *, integer *, real *, 
	    integer *), nspli (integer *), nspmci (integer *), nschxp (real *)
	    , nsedfg (integer *), nsiasf (integer *, integer *), nshlft (
	    integer *, integer *, integer *, integer *, integer *), nshrid (
	    integer *), nsivft (integer *, integer *, integer *, integer *, 
	    integer *), nscmd (integer *, integer *), nshrm (integer *, 
	    integer *), nsvwr (integer *, integer *, real *, real *, real *, 
	    integer *), nswkw (integer *, real *, real *, real *, real *), 
	    nswkw3 (integer *, real *), nswkv3 (integer *, real *), nswkv (
	    integer *, real *, real *, real *, real *), nsgmt (real *), 
	    nsvwr3 (integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *), nslmt (real *, integer *), nsmcv (integer *
	    , integer *, real *), nsvwi (integer *), nsvtip (integer *, 
	    integer *, integer *, integer *), nclst (void), nexst (integer *),
	     ncelst (integer *), nsedm (integer *), nemst (integer *), 
	    ncstir (integer *, integer *), nscnrs (integer *, integer *), 
	    npost (integer *, integer *, real *), nseplb (integer *), ndellb (
	    integer *, integer *), nupost (integer *, integer *), nupast (
	    integer *), noparf (integer *, integer *), nclarf (integer *), 
	    narst (integer *, integer *, integer *), narsn (integer *, 
	    integer *, integer *), narast (integer *), nrsid (integer *, 
	    integer *, integer *, integer *), nrast (integer *), nrest (
	    integer *, integer *, integer *), nresn (integer *, integer *, 
	    integer *), nrepan (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nrepde (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), ndstar (integer *, integer *, 
	    integer *), ndasar (integer *), ndsnar (integer *, integer *, 
	    integer *), nserhm (integer *);
#else /* NO_PROTO */
/* Subroutine */ int rfuncs_0_(n__, i1, i2, wkid, ra, rb, rc, r1, r2, chars, 
	r3, r4, ia, i3, i4, i5, i6, i7, ib, xfa, xfb, vclip, xga, xgb, i8, 
	chars_len)
int n__;
integer *i1, *i2, *wkid;
real *ra, *rb, *rc, *r1, *r2;
char *chars;
real *r3, *r4;
integer *ia, *i3, *i4, *i5, *i6, *i7, *ib;
real *xfa, *xfb, *vclip, *xga, *xgb;
integer *i8;
ftnlen chars_len;
{
    extern /* Subroutine */ int nca (), nfa (), nlb (), npl (), npm (), ntx ()
	    , nca3 (), nfa3 (), npl3 (), ndel (), nads (), natr (), nfas (), 
	    nsii (), nsis (), nsir (), nsln (), nuwk (), nres (), nrst (), 
	    nscr (), nsep (), ndsn (), nfas3 (), nopph (), echkz_(), nclph (),
	     nopwk (), nopst (), nclwk (), nsdus (), nsplr (), nspmr (), 
	    nstxp (), nstxal (), nsatal (), nsmksc (), nstxfn (), nsans (), 
	    nsparf (), nspar (), nstxr (), nsedi (), nsedci (), nsplci (), 
	    nstxci (), nstxi (), nsedr (), nspli (), nspmci (), nschxp (), 
	    nsedfg (), nsiasf (), nshlft (), nshrid (), nsivft (), nscmd (), 
	    nshrm (), nsvwr (), nswkw (), nswkw3 (), nswkv3 (), nswkv (), 
	    nsgmt (), nsvwr3 (), nslmt (), nsmcv (), nsvwi (), nsvtip (), 
	    nclst (), nexst (), ncelst (), nsedm (), nemst (), ncstir (), 
	    nscnrs (), npost (), nseplb (), ndellb (), nupost (), nupast (), 
	    noparf (), nclarf (), narst (), narsn (), narast (), nrsid (), 
	    nrast (), nrest (), nresn (), nrepan (), nrepde (), ndstar (), 
	    ndasar (), ndsnar (), nserhm ();
#endif /* NO_PROTO */

/*  RFUNCS is the home of the entry points for PHIGS functions which */
/*  are called in order to generate an error.  The functions are */
/*  followed a wrapper routine which records what should have */
/*  happened. */
/* PHIGS function names (for those functions which signal error) */
/* *** *** *** control *** *** *** */
    /* Parameter adjustments */
    if (ra) {
	--ra;
	}
    if (rb) {
	--rb;
	}
    if (rc) {
	--rc;
	}
    if (ia) {
	--ia;
	}
    if (ib) {
	--ib;
	}
    if (xfa) {
	xfa -= 4;
	}
    if (xfb) {
	xfb -= 4;
	}
    if (vclip) {
	--vclip;
	}
    if (xga) {
	xga -= 5;
	}
    if (xgb) {
	xgb -= 5;
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_ropph;
	case 2: goto L_rclph;
	case 3: goto L_ropwk;
	case 4: goto L_ropst;
	case 5: goto L_rclwk;
	case 6: goto L_rrst;
	case 7: goto L_ruwk;
	case 8: goto L_rsdus;
	case 9: goto L_rpl3;
	case 10: goto L_rpl;
	case 11: goto L_rtx;
	case 12: goto L_rfa;
	case 13: goto L_rfa3;
	case 14: goto L_rpm;
	case 15: goto L_ratr;
	case 16: goto L_rfas;
	case 17: goto L_rfas3;
	case 18: goto L_rca3;
	case 19: goto L_rca;
	case 20: goto L_rsplr;
	case 21: goto L_rspmr;
	case 22: goto L_rstxp;
	case 23: goto L_rstxal;
	case 24: goto L_rsatal;
	case 25: goto L_rsis;
	case 26: goto L_rsii;
	case 27: goto L_rsmksc;
	case 28: goto L_rstxfn;
	case 29: goto L_rsans;
	case 30: goto L_rsparf;
	case 31: goto L_rsir;
	case 32: goto L_rspar;
	case 33: goto L_rstxr;
	case 34: goto L_rsedi;
	case 35: goto L_rsedci;
	case 36: goto L_rsplci;
	case 37: goto L_rstxci;
	case 38: goto L_rstxi;
	case 39: goto L_rsedr;
	case 40: goto L_rspli;
	case 41: goto L_rsln;
	case 42: goto L_rspmci;
	case 43: goto L_rschxp;
	case 44: goto L_rsedfg;
	case 45: goto L_rads;
	case 46: goto L_rres;
	case 47: goto L_rsiasf;
	case 48: goto L_rshlft;
	case 49: goto L_rshrid;
	case 50: goto L_rsivft;
	case 51: goto L_rscmd;
	case 52: goto L_rscr;
	case 53: goto L_rshrm;
	case 54: goto L_rsvwr;
	case 55: goto L_rswkw;
	case 56: goto L_rswkw3;
	case 57: goto L_rswkv3;
	case 58: goto L_rswkv;
	case 59: goto L_rsgmt;
	case 60: goto L_rsvwr3;
	case 61: goto L_rslmt;
	case 62: goto L_rsmcv;
	case 63: goto L_rsvwi;
	case 64: goto L_rsvtip;
	case 65: goto L_rclst;
	case 66: goto L_rlb;
	case 67: goto L_rsep;
	case 68: goto L_rexst;
	case 69: goto L_rcelst;
	case 70: goto L_rdel;
	case 71: goto L_rsedm;
	case 72: goto L_remst;
	case 73: goto L_rdsn;
	case 74: goto L_rcstir;
	case 75: goto L_rscnrs;
	case 76: goto L_rpost;
	case 77: goto L_rseplb;
	case 78: goto L_rdellb;
	case 79: goto L_rupost;
	case 80: goto L_rupast;
	case 81: goto L_roparf;
	case 82: goto L_rclarf;
	case 83: goto L_rarst;
	case 84: goto L_rarsn;
	case 85: goto L_rarast;
	case 86: goto L_rrsid;
	case 87: goto L_rrast;
	case 88: goto L_rrest;
	case 89: goto L_rresn;
	case 90: goto L_rrepan;
	case 91: goto L_rrepde;
	case 92: goto L_rdstar;
	case 93: goto L_rdasar;
	case 94: goto L_rdsnar;
	case 95: goto L_rserhm;
	}


L_ropph:
    nopph (i1, i2);
    echkz_(&c__0);
    return 0;

L_rclph:
    nclph ();
    echkz_(&c__1);
    return 0;

L_ropwk:
    nopwk (wkid, i1, i2);
    echkz_(&c__2);
    return 0;

L_ropst:
    nopst (i1);
    echkz_(&c__90);
    return 0;

L_rclwk:
    nclwk (wkid);
    echkz_(&c__3);
    return 0;

L_rrst:
    nrst (wkid, i1);
    echkz_(&c__4);
    return 0;

L_ruwk:
    nuwk (wkid, i1);
    echkz_(&c__5);
    return 0;

L_rsdus:
    nsdus (wkid, i1, i2);
    echkz_(&c__6);
    return 0;
/* *** *** *** output primitives *** *** *** */

L_rpl3:
    npl3 (i1, &ra[1], &rb[1], &rc[1]);
    echkz_(&c__8);
    return 0;

L_rpl:
    npl (i1, &ra[1], &rb[1]);
    echkz_(&c__9);
    return 0;

L_rtx:
    ntx (r1, r2, chars, chars_len);
    echkz_(&c__13);
    return 0;

L_rfa:
    nfa (i1, &ra[1], &rb[1]);
    echkz_(&c__17);
    return 0;

L_rfa3:
    nfa3 (i1, &ra[1], &rb[1], &rc[1]);
    echkz_(&c__16);
    return 0;

L_rpm:
    npm (i1, &ra[1], &rb[1]);
    echkz_(&c__11);
    return 0;

L_ratr:
    natr (r1, r2, r3, r4, chars, chars_len);
    echkz_(&c__15);
    return 0;

L_rfas:
    nfas (i1, &ia[1], &ra[1], &rb[1]);
    echkz_(&c__19);
    return 0;

L_rfas3:
    nfas3 (i1, &ia[1], &ra[1], &rb[1], &rc[1]);
    echkz_(&c__18);
    return 0;

L_rca3:
    nca3 (&ra[1], &rb[1], &rc[1], i1, i2, i3, i4, i5, i6, &ia[1]);
    echkz_(&c__20);
    return 0;

L_rca:
    nca (r1, r2, r3, r4, i1, i2, i3, i4, i5, i6, &ia[1]);
    echkz_(&c__21);
    return 0;
/* *** *** *** attributes *** *** *** */

L_rsplr:
    nsplr (wkid, i1, i2, r1, i3);
    echkz_(&c__62);
    return 0;

L_rspmr:
    nspmr (wkid, i1, i2, r1, i3);
    echkz_(&c__63);
    return 0;

L_rstxp:
    nstxp (i1);
    echkz_(&c__42);
    return 0;

L_rstxal:
    nstxal (i1, i2);
    echkz_(&c__43);
    return 0;

L_rsatal:
    nsatal (i1, i2);
    echkz_(&c__47);
    return 0;

L_rsis:
    nsis (i1);
    echkz_(&c__49);
    return 0;

L_rsii:
    nsii (i1);
    echkz_(&c__27);
    return 0;

L_rsmksc:
    nsmksc (r1);
    echkz_(&c__33);
    return 0;

L_rstxfn:
    nstxfn (i1);
    echkz_(&c__35);
    return 0;

L_rsans:
    nsans (i1);
    echkz_(&c__48);
    return 0;

L_rsparf:
    nsparf (r1, r2);
    echkz_(&c__58);
    return 0;

L_rsir:
    nsir (wkid, i1, i2, i3, i4);
    echkz_(&c__65);
    return 0;

L_rspar:
    nspar (wkid, i1, i2, i3, i4, i5, i6, i7, &ia[1]);
    echkz_(&c__67);
    return 0;

L_rstxr:
    nstxr (wkid, i1, i2, i3, r1, r2, i4);
    echkz_(&c__64);
    return 0;

L_rsedi:
    nsedi (i1);
    echkz_(&c__28);
    return 0;

L_rsedci:
    nsedci (i1);
    echkz_(&c__55);
    return 0;

L_rsplci:
    nsplci (i1);
    echkz_(&c__31);
    return 0;

L_rstxci:
    nstxci (i1);
    echkz_(&c__39);
    return 0;

L_rstxi:
    nstxi (i1);
    echkz_(&c__26);
    return 0;

L_rsedr:
    nsedr (wkid, i1, i2, i3, r1, i4);
    echkz_(&c__66);
    return 0;

L_rspli:
    nspli (i1);
    echkz_(&c__24);
    return 0;

L_rsln:
    nsln (i1);
    echkz_(&c__29);
    return 0;

L_rspmci:
    nspmci (i1);
    echkz_(&c__34);
    return 0;

L_rschxp:
    nschxp (r1);
    echkz_(&c__37);
    return 0;

L_rsedfg:
    nsedfg (i1);
    echkz_(&c__52);
    return 0;
/* *** *** *** generic attributes *** *** *** */

L_rads:
    nads (i1, &ia[1]);
    echkz_(&c__59);
    return 0;

L_rres:
    nres (i1, &ia[1]);
    echkz_(&c__60);
    return 0;

L_rsiasf:
    nsiasf (i1, i2);
    echkz_(&c__61);
    return 0;

L_rshlft:
    nshlft (wkid, i1, &ia[1], i2, &ib[1]);
    echkz_(&c__69);
    return 0;

L_rshrid:
    nshrid (i1);
    echkz_(&c__72);
    return 0;

L_rsivft:
    nsivft (wkid, i1, &ia[1], i2, &ib[1]);
    echkz_(&c__70);
    return 0;

L_rscmd:
    nscmd (wkid, i1);
    echkz_(&c__71);
    return 0;

L_rscr:
    nscr (wkid, i1, i2, &ra[1]);
    echkz_(&c__68);
    return 0;

L_rshrm:
    nshrm (wkid, i1);
    echkz_(&c__73);
    return 0;
/* *** *** *** geometry *** *** *** */

L_rsvwr:
    nsvwr (wkid, i1, &xfa[4], &xfb[4], &vclip[1], i2);
    echkz_(&c__84);
    return 0;

L_rswkw:
    nswkw (wkid, r1, r2, r3, r4);
    echkz_(&c__87);
    return 0;

L_rswkw3:
    nswkw3 (wkid, &ra[1]);
    echkz_(&c__86);
    return 0;

L_rswkv3:
    nswkv3 (wkid, &ra[1]);
    echkz_(&c__88);
    return 0;

L_rswkv:
    nswkv (wkid, r1, r2, r3, r4);
    echkz_(&c__89);
    return 0;

L_rsgmt:
    nsgmt (&xfa[4]);
    echkz_(&c__77);
    return 0;

L_rsvwr3:
    nsvwr3 (wkid, i1, &xga[5], &xgb[5], &vclip[1], i2, i3, i4);
    echkz_(&c__83);
    return 0;

L_rslmt:
    nslmt (&xfa[4], i1);
    echkz_(&c__75);
    return 0;

L_rsmcv:
    nsmcv (i1, i2, &ra[1]);
    echkz_(&c__79);
    return 0;

L_rsvwi:
    nsvwi (i1);
    echkz_(&c__82);
    return 0;

L_rsvtip:
    nsvtip (wkid, i1, i2, i3);
    echkz_(&c__85);
    return 0;
/* *** *** *** structures *** *** *** */

L_rclst:
    nclst ();
    echkz_(&c__91);
    return 0;

L_rlb:
    nlb (i1);
    echkz_(&c__93);
    return 0;

L_rsep:
    nsep (i1);
    echkz_(&c__98);
    return 0;

L_rexst:
    nexst (i1);
    echkz_(&c__92);
    return 0;

L_rcelst:
    ncelst (i1);
    echkz_(&c__97);
    return 0;

L_rdel:
    ndel ();
    echkz_(&c__101);
    return 0;

L_rsedm:
    nsedm (i1);
    echkz_(&c__96);
    return 0;

L_remst:
    nemst (i1);
    echkz_(&c__104);
    return 0;

L_rdsn:
    ndsn (i1, i2);
    echkz_(&c__106);
    return 0;

L_rcstir:
    ncstir (i1, i2);
    echkz_(&c__110);
    return 0;

L_rscnrs:
    nscnrs (i1, i2);
    echkz_(&c__119);
    return 0;

L_rpost:
    npost (wkid, i1, r1);
    echkz_(&c__111);
    return 0;

L_rseplb:
    nseplb (i1);
    echkz_(&c__100);
    return 0;

L_rdellb:
    ndellb (i1, i2);
    echkz_(&c__103);
    return 0;

L_rupost:
    nupost (wkid, i1);
    echkz_(&c__112);
    return 0;

L_rupast:
    nupast (wkid);
    echkz_(&c__113);
    return 0;
/* *** *** *** archives *** *** *** */

L_roparf:
    noparf (i1, i2);
    echkz_(&c__114);
    return 0;

L_rclarf:
    nclarf (i1);
    echkz_(&c__115);
    return 0;

L_rarst:
    narst (i1, i2, &ia[1]);
    echkz_(&c__116);
    return 0;

L_rarsn:
    narsn (i1, i2, &ia[1]);
    echkz_(&c__117);
    return 0;

L_rarast:
    narast (i1);
    echkz_(&c__118);
    return 0;

L_rrsid:
    nrsid (i1, i2, i3, &ia[1]);
    echkz_(&c__120);
    return 0;

L_rrast:
    nrast (i1);
    echkz_(&c__123);
    return 0;

L_rrest:
    nrest (i1, i2, &ia[1]);
    echkz_(&c__121);
    return 0;

L_rresn:
    nresn (i1, i2, &ia[1]);
    echkz_(&c__122);
    return 0;

L_rrepan:
    nrepan (i1, i2, i3, i4, i5, i6, i7, i8, &ia[1]);
    echkz_(&c__124);
    return 0;

L_rrepde:
    nrepde (i1, i2, i3, i4, i5, i6, i7, i8, &ia[1]);
    echkz_(&c__125);
    return 0;

L_rdstar:
    ndstar (i1, i2, &ia[1]);
    echkz_(&c__126);
    return 0;

L_rdasar:
    ndasar (i1);
    echkz_(&c__128);
    return 0;

L_rdsnar:
    ndsnar (i1, i2, &ia[1]);
    echkz_(&c__127);
    return 0;

L_rserhm:
    nserhm (i1);
    echkz_(&c__179);
    return 0;
} /* rfuncs_ */

#ifndef NO_PROTO
/* Subroutine */ int rfuncs_(void)
#else /* NO_PROTO */
/* Subroutine */ int rfuncs_()
#endif /* NO_PROTO */
{
    return rfuncs_0_(0, (integer *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ropph_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int ropph_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(1, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *
	    )0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rclph_(void)
#else /* NO_PROTO */
/* Subroutine */ int rclph_()
#endif /* NO_PROTO */
{
    return rfuncs_0_(2, (integer *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ropwk_(integer *wkid, integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int ropwk_(wkid, i1, i2)
integer *wkid, *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(3, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ropst_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int ropst_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(4, i1, (integer *)0, (integer *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rclwk_(integer *wkid)
#else /* NO_PROTO */
/* Subroutine */ int rclwk_(wkid)
integer *wkid;
#endif /* NO_PROTO */
{
    return rfuncs_0_(5, (integer *)0, (integer *)0, wkid, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrst_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rrst_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(6, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ruwk_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int ruwk_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(7, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsdus_(integer *wkid, integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rsdus_(wkid, i1, i2)
integer *wkid, *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(8, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rpl3_(integer *i1, real *ra, real *rb, real *rc)
#else /* NO_PROTO */
/* Subroutine */ int rpl3_(i1, ra, rb, rc)
integer *i1;
real *ra, *rb, *rc;
#endif /* NO_PROTO */
{
    return rfuncs_0_(9, i1, (integer *)0, (integer *)0, ra, rb, rc, (real *)0,
	     (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rpl_(integer *i1, real *ra, real *rb)
#else /* NO_PROTO */
/* Subroutine */ int rpl_(i1, ra, rb)
integer *i1;
real *ra, *rb;
#endif /* NO_PROTO */
{
    return rfuncs_0_(10, i1, (integer *)0, (integer *)0, ra, rb, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rtx_(real *r1, real *r2, char *chars, ftnlen chars_len)
#else /* NO_PROTO */
/* Subroutine */ int rtx_(r1, r2, chars, chars_len)
real *r1, *r2;
char *chars;
ftnlen chars_len;
#endif /* NO_PROTO */
{
    return rfuncs_0_(11, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, r2, chars, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, chars_len);
    }

#ifndef NO_PROTO
/* Subroutine */ int rfa_(integer *i1, real *ra, real *rb)
#else /* NO_PROTO */
/* Subroutine */ int rfa_(i1, ra, rb)
integer *i1;
real *ra, *rb;
#endif /* NO_PROTO */
{
    return rfuncs_0_(12, i1, (integer *)0, (integer *)0, ra, rb, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rfa3_(integer *i1, real *ra, real *rb, real *rc)
#else /* NO_PROTO */
/* Subroutine */ int rfa3_(i1, ra, rb, rc)
integer *i1;
real *ra, *rb, *rc;
#endif /* NO_PROTO */
{
    return rfuncs_0_(13, i1, (integer *)0, (integer *)0, ra, rb, rc, (real *)
	    0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rpm_(integer *i1, real *ra, real *rb)
#else /* NO_PROTO */
/* Subroutine */ int rpm_(i1, ra, rb)
integer *i1;
real *ra, *rb;
#endif /* NO_PROTO */
{
    return rfuncs_0_(14, i1, (integer *)0, (integer *)0, ra, rb, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ratr_(real *r1, real *r2, real *r3, real *r4, char *
	chars, ftnlen chars_len)
#else /* NO_PROTO */
/* Subroutine */ int ratr_(r1, r2, r3, r4, chars, chars_len)
real *r1, *r2, *r3, *r4;
char *chars;
ftnlen chars_len;
#endif /* NO_PROTO */
{
    return rfuncs_0_(15, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, r2, chars, r3, r4, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, chars_len);
    }

#ifndef NO_PROTO
/* Subroutine */ int rfas_(integer *i1, integer *ia, real *ra, real *rb)
#else /* NO_PROTO */
/* Subroutine */ int rfas_(i1, ia, ra, rb)
integer *i1, *ia;
real *ra, *rb;
#endif /* NO_PROTO */
{
    return rfuncs_0_(16, i1, (integer *)0, (integer *)0, ra, rb, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rfas3_(integer *i1, integer *ia, real *ra, real *rb, 
	real *rc)
#else /* NO_PROTO */
/* Subroutine */ int rfas3_(i1, ia, ra, rb, rc)
integer *i1, *ia;
real *ra, *rb, *rc;
#endif /* NO_PROTO */
{
    return rfuncs_0_(17, i1, (integer *)0, (integer *)0, ra, rb, rc, (real *)
	    0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rca3_(real *ra, real *rb, real *rc, integer *i1, integer 
	*i2, integer *i3, integer *i4, integer *i5, integer *i6, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rca3_(ra, rb, rc, i1, i2, i3, i4, i5, i6, ia)
real *ra, *rb, *rc;
integer *i1, *i2, *i3, *i4, *i5, *i6, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(18, i1, i2, (integer *)0, ra, rb, rc, (real *)0, (real *)
	    0, (char *)0, (real *)0, (real *)0, ia, i3, i4, i5, i6, (integer *
	    )0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rca_(real *r1, real *r2, real *r3, real *r4, integer *i1,
	 integer *i2, integer *i3, integer *i4, integer *i5, integer *i6, 
	integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rca_(r1, r2, r3, r4, i1, i2, i3, i4, i5, i6, ia)
real *r1, *r2, *r3, *r4;
integer *i1, *i2, *i3, *i4, *i5, *i6, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(19, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, r1, r2, (char *)0, r3, r4, ia, i3, i4, i5, i6, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsplr_(integer *wkid, integer *i1, integer *i2, real *r1,
	 integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rsplr_(wkid, i1, i2, r1, i3)
integer *wkid, *i1, *i2;
real *r1;
integer *i3;
#endif /* NO_PROTO */
{
    return rfuncs_0_(20, i1, i2, wkid, (real *)0, (real *)0, (real *)0, r1, (
	    real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rspmr_(integer *wkid, integer *i1, integer *i2, real *r1,
	 integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rspmr_(wkid, i1, i2, r1, i3)
integer *wkid, *i1, *i2;
real *r1;
integer *i3;
#endif /* NO_PROTO */
{
    return rfuncs_0_(21, i1, i2, wkid, (real *)0, (real *)0, (real *)0, r1, (
	    real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxp_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rstxp_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(22, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxal_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rstxal_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(23, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsatal_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rsatal_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(24, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsis_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsis_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(25, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsii_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsii_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(26, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsmksc_(real *r1)
#else /* NO_PROTO */
/* Subroutine */ int rsmksc_(r1)
real *r1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(27, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, (real *)0, (char *)0, (real *)0, (real *
	    )0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxfn_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rstxfn_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(28, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsans_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsans_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(29, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsparf_(real *r1, real *r2)
#else /* NO_PROTO */
/* Subroutine */ int rsparf_(r1, r2)
real *r1, *r2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(30, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, r2, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsir_(integer *wkid, integer *i1, integer *i2, integer *
	i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rsir_(wkid, i1, i2, i3, i4)
integer *wkid, *i1, *i2, *i3, *i4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(31, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3,
	     i4, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)
	    0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rspar_(integer *wkid, integer *i1, integer *i2, integer *
	i3, integer *i4, integer *i5, integer *i6, integer *i7, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rspar_(wkid, i1, i2, i3, i4, i5, i6, i7, ia)
integer *wkid, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(32, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, i3, i4, i5, 
	    i6, i7, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxr_(integer *wkid, integer *i1, integer *i2, integer *
	i3, real *r1, real *r2, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rstxr_(wkid, i1, i2, i3, r1, r2, i4)
integer *wkid, *i1, *i2, *i3;
real *r1, *r2;
integer *i4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(33, i1, i2, wkid, (real *)0, (real *)0, (real *)0, r1, 
	    r2, (char *)0, (real *)0, (real *)0, (integer *)0, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)
	    0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedi_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsedi_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(34, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedci_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsedci_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(35, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsplci_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsplci_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(36, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxci_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rstxci_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(37, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxi_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rstxi_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(38, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedr_(integer *wkid, integer *i1, integer *i2, integer *
	i3, real *r1, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rsedr_(wkid, i1, i2, i3, r1, i4)
integer *wkid, *i1, *i2, *i3;
real *r1;
integer *i4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(39, i1, i2, wkid, (real *)0, (real *)0, (real *)0, r1, (
	    real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)
	    0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rspli_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rspli_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(40, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsln_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsln_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(41, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rspmci_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rspmci_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(42, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rschxp_(real *r1)
#else /* NO_PROTO */
/* Subroutine */ int rschxp_(r1)
real *r1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(43, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, (real *)0, (char *)0, (real *)0, (real *
	    )0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedfg_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsedfg_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(44, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rads_(integer *i1, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rads_(i1, ia)
integer *i1, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(45, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     ia, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rres_(integer *i1, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rres_(i1, ia)
integer *i1, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(46, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     ia, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsiasf_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rsiasf_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(47, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rshlft_(integer *wkid, integer *i1, integer *ia, integer 
	*i2, integer *ib)
#else /* NO_PROTO */
/* Subroutine */ int rshlft_(wkid, i1, ia, i2, ib)
integer *wkid, *i1, *ia, *i2, *ib;
#endif /* NO_PROTO */
{
    return rfuncs_0_(48, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, ib, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)
	    0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rshrid_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rshrid_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(49, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsivft_(integer *wkid, integer *i1, integer *ia, integer 
	*i2, integer *ib)
#else /* NO_PROTO */
/* Subroutine */ int rsivft_(wkid, i1, ia, i2, ib)
integer *wkid, *i1, *ia, *i2, *ib;
#endif /* NO_PROTO */
{
    return rfuncs_0_(50, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, ib, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)
	    0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rscmd_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rscmd_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(51, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rscr_(integer *wkid, integer *i1, integer *i2, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rscr_(wkid, i1, i2, ra)
integer *wkid, *i1, *i2;
real *ra;
#endif /* NO_PROTO */
{
    return rfuncs_0_(52, i1, i2, wkid, ra, (real *)0, (real *)0, (real *)0, (
	    real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rshrm_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rshrm_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(53, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsvwr_(integer *wkid, integer *i1, real *xfa, real *xfb, 
	real *vclip, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rsvwr_(wkid, i1, xfa, xfb, vclip, i2)
integer *wkid, *i1;
real *xfa, *xfb, *vclip;
integer *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(54, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, xfa, xfb, vclip, (real *)0, (real *)0, (integer *
	    )0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rswkw_(integer *wkid, real *r1, real *r2, real *r3, real 
	*r4)
#else /* NO_PROTO */
/* Subroutine */ int rswkw_(wkid, r1, r2, r3, r4)
integer *wkid;
real *r1, *r2, *r3, *r4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(55, (integer *)0, (integer *)0, wkid, (real *)0, (real *)
	    0, (real *)0, r1, r2, (char *)0, r3, r4, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rswkw3_(integer *wkid, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rswkw3_(wkid, ra)
integer *wkid;
real *ra;
#endif /* NO_PROTO */
{
    return rfuncs_0_(56, (integer *)0, (integer *)0, wkid, ra, (real *)0, (
	    real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rswkv3_(integer *wkid, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rswkv3_(wkid, ra)
integer *wkid;
real *ra;
#endif /* NO_PROTO */
{
    return rfuncs_0_(57, (integer *)0, (integer *)0, wkid, ra, (real *)0, (
	    real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rswkv_(integer *wkid, real *r1, real *r2, real *r3, real 
	*r4)
#else /* NO_PROTO */
/* Subroutine */ int rswkv_(wkid, r1, r2, r3, r4)
integer *wkid;
real *r1, *r2, *r3, *r4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(58, (integer *)0, (integer *)0, wkid, (real *)0, (real *)
	    0, (real *)0, r1, r2, (char *)0, r3, r4, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsgmt_(real *xfa)
#else /* NO_PROTO */
/* Subroutine */ int rsgmt_(xfa)
real *xfa;
#endif /* NO_PROTO */
{
    return rfuncs_0_(59, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, 
	    (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, xfa, (real *)0, (real *
	    )0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsvwr3_(integer *wkid, integer *i1, real *xga, real *xgb,
	 real *vclip, integer *i2, integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rsvwr3_(wkid, i1, xga, xgb, vclip, i2, i3, i4)
integer *wkid, *i1;
real *xga, *xgb, *vclip;
integer *i2, *i3, *i4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(60, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3,
	     i4, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    real *)0, (real *)0, vclip, xga, xgb, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rslmt_(real *xfa, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rslmt_(xfa, i1)
real *xfa;
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(61, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, xfa, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsmcv_(integer *i1, integer *i2, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rsmcv_(i1, i2, ra)
integer *i1, *i2;
real *ra;
#endif /* NO_PROTO */
{
    return rfuncs_0_(62, i1, i2, (integer *)0, ra, (real *)0, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsvwi_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsvwi_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(63, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsvtip_(integer *wkid, integer *i1, integer *i2, integer 
	*i3)
#else /* NO_PROTO */
/* Subroutine */ int rsvtip_(wkid, i1, i2, i3)
integer *wkid, *i1, *i2, *i3;
#endif /* NO_PROTO */
{
    return rfuncs_0_(64, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rclst_(void)
#else /* NO_PROTO */
/* Subroutine */ int rclst_()
#endif /* NO_PROTO */
{
    return rfuncs_0_(65, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, 
	    (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rlb_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rlb_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(66, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsep_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsep_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(67, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rexst_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rexst_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(68, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rcelst_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rcelst_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(69, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdel_(void)
#else /* NO_PROTO */
/* Subroutine */ int rdel_()
#endif /* NO_PROTO */
{
    return rfuncs_0_(70, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, 
	    (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedm_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsedm_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(71, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int remst_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int remst_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(72, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdsn_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rdsn_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(73, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rcstir_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rcstir_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(74, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rscnrs_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rscnrs_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(75, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rpost_(integer *wkid, integer *i1, real *r1)
#else /* NO_PROTO */
/* Subroutine */ int rpost_(wkid, i1, r1)
integer *wkid, *i1;
real *r1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(76, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *
	    )0, r1, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rseplb_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rseplb_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(77, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdellb_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rdellb_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(78, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rupost_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rupost_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(79, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rupast_(integer *wkid)
#else /* NO_PROTO */
/* Subroutine */ int rupast_(wkid)
integer *wkid;
#endif /* NO_PROTO */
{
    return rfuncs_0_(80, (integer *)0, (integer *)0, wkid, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int roparf_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int roparf_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(81, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rclarf_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rclarf_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(82, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rarst_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rarst_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(83, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rarsn_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rarsn_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(84, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rarast_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rarast_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(85, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrsid_(integer *i1, integer *i2, integer *i3, integer *
	ia)
#else /* NO_PROTO */
/* Subroutine */ int rrsid_(i1, i2, i3, ia)
integer *i1, *i2, *i3, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(86, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, i3, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrast_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rrast_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(87, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrest_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rrest_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(88, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rresn_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rresn_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(89, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrepan_(integer *i1, integer *i2, integer *i3, integer *
	i4, integer *i5, integer *i6, integer *i7, integer *i8, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rrepan_(i1, i2, i3, i4, i5, i6, i7, i8, ia)
integer *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(90, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, i3, 
	    i4, i5, i6, i7, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, i8, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrepde_(integer *i1, integer *i2, integer *i3, integer *
	i4, integer *i5, integer *i6, integer *i7, integer *i8, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rrepde_(i1, i2, i3, i4, i5, i6, i7, i8, ia)
integer *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(91, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, i3, 
	    i4, i5, i6, i7, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, i8, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdstar_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rdstar_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(92, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdasar_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rdasar_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(93, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdsnar_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rdsnar_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(94, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rserhm_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rserhm_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(95, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/echkz                             * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int echkz_(integer *funcid)
#else /* NO_PROTO */
/* Subroutine */ int echkz_(funcid)
integer *funcid;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen), nerhnd (integer *, 
	    integer *, integer *), nerlog (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_(), nerhnd (), nerlog ();
#endif /* NO_PROTO */

/*  ECHKZ does post-processing after an error-signalling function has */
/*  been called. */
/*  Input parameter: */
/*    FUNCID: numeric identifier of function that signalled error */
    if (errinf_1.usrerr == 1 || errinf_1.usrerr == 3) {
/*  user-defined error handling */
/*  make bogus entry in error table to mark end of function effect */
	nerhnd (&c__2, &c__180, &c_n666);
    } else {
/*  system-defined error handling */
/*  make bogus entry in error file to mark end of function effect */
	nerlog (&c__2, &c__180, &globnu_1.errfil);
    }
/*  fill table of expected error-signalling function identifiers */
    ++errinf_1.efcnt;
    errinf_1.efid[errinf_1.efcnt - 1] = *funcid;
    if (itrim_(errchr_1.curcon, 200L) > 150) {
	unmsg_("ECHKZ detected CURCON of excessive length.", 42L);
    }
    if (errinf_1.efcnt > 40) {
	unmsg_("ECHKZ detected CONTAB table overflow.", 37L);
    }
/*  fill table of condition descriptions */
    s_copy(errchr_1.contab + (errinf_1.efcnt - 1) * 150, errchr_1.curcon, 
	    150L, 200L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* echkz_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/tstwan                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int tstwan_(logical *warnin, char *wanact, ftnlen wanact_len)

#else /* NO_PROTO */
/* Subroutine */ int tstwan_(warnin, wanact, wanact_len)
logical *warnin;
char *wanact;
ftnlen wanact_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;
    char ch__1[363];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp(), i_indx();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
#endif /* NO_PROTO */
    static char wbuf[300];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static char funnam[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int erfunm_(integer *, char *, ftnlen), setmsg_(
	    char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int erfunm_(), setmsg_();
#endif /* NO_PROTO */

/*  TSTWAN is used to test that functions which issue a warning */
/*  take the correct action. */
/*  Input parameters: */
/*    WARNIN : logical variable indicating whether the function took */
/*             the correct action */
/*    WANACT : description of correct action */
    s_copy(wbuf, wanact, 300L, wanact_len);
    if (s_cmp(wanact, wbuf, wanact_len, 300L) != 0) {
	unmsg_("Action description passed to TSTWAN is too long.", 48L);
    }
    if (i_indx(wbuf, "should", 300L, 6L) < 1) {
/* Writing concatenation */
#ifndef NO_PROTO
	i__1[0] = 63, a__1[0] = "Action description passed to TSTWAN does no"
		"t contain \"should\": ";
#else /* NO_PROTO */
	i__1[0] = 63, a__1[0] = "Action description passed to TSTWAN does no\
t contain \"should\": ";
#endif /* NO_PROTO */
	i__1[1] = 300, a__1[1] = wbuf;
	s_cat(ch__1, a__1, i__1, &c__2, 363L);
	unmsg_(ch__1, 363L);
    }
    erfunm_(&errinf_1.efid[errinf_1.efcnt - 1], funnam, 80L);
/* Writing concatenation */
    i__1[0] = 3, a__1[0] = "If ";
    i__1[1] = 80, a__1[1] = funnam;
    s_cat(msg, a__1, i__1, &c__2, 300L);
    i__2 = itrim_(msg, 300L) + 1;
/* Writing concatenation */
    i__1[0] = 25, a__1[0] = "issues a warning because ";
    i__1[1] = 200, a__1[1] = errchr_1.curcon;
    s_cat(msg + i__2, a__1, i__1, &c__2, 300 - i__2);
    i__2 = itrim_(msg, 300L);
/* Writing concatenation */
    i__1[0] = 2, a__1[0] = ", ";
    i__1[1] = 300, a__1[1] = wbuf;
    s_cat(msg + i__2, a__1, i__1, &c__2, 300 - i__2);
    setmsg_(errchr_1.errsrs, msg, 40L, 300L);
    ifpf_(warnin);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstwan_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.01/crest                             * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int crest_(void)
#else /* NO_PROTO */
/* Subroutine */ int crest_()
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static real xa[2] = { 0.f,0.f };
    static real ya[2] = { .5f,.5f };
#else /* NO_PROTO */
    static real xa[2] = { (float)0.,(float)0. };
    static real ya[2] = { (float).5,(float).5 };
#endif /* NO_PROTO */

#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen), nschh (real *), nclst (void), nexst (
	    integer *), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx (), nschh (), nclst (), nexst (), 
	    nopst ();
#endif /* NO_PROTO */

/*   create a structure network */
    nopst (&c__100);
    npl (&c__2, xa, ya);
    nexst (&c__101);
    nclst ();
    nopst (&c__101);
    nschh (&c_b564);
    ntx (&c_b565, &c_b565, "TEXT", 4L);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* crest_ */

