/* fort///sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* MANUAL CHANGE HERE: */
#include <phigs.h>
#include <stdio.h>
#include <time.h>
/* END MANUAL CHANGE */

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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

struct {
    char ophead[300];
} opcomm_;

#define opcomm_1 opcomm_

struct {
    real rlseed;
} ranctl_;

#define ranctl_1 ranctl_

struct {
    real picl, picr, picb, pict, prtl, prtr, prtb, prtt, echl, echr, echb, 
	    echt;
} scrfmt_;

#define scrfmt_1 scrfmt_

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__2 = 2;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__7 = 7;
static integer c__100 = 100;
static integer c__101 = 101;
static integer c__102 = 102;
static integer c__902 = 902;
static integer c__103 = 103;
static integer c__960 = 960;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__900 = 900;
static integer c__901 = 901;
static integer c__106 = 106;
static integer c__120 = 120;
static integer c__907 = 907;
static integer c__130 = 130;
static integer c__910 = 910;
static integer c__912 = 912;
static integer c__914 = 914;
static integer c__107 = 107;
static integer c__140 = 140;
static integer c__142 = 142;
static integer c__920 = 920;
static integer c__109 = 109;
static integer c__925 = 925;
static integer c__926 = 926;
static integer c__110 = 110;
static integer c__108 = 108;
static integer c__114 = 114;
static integer c__950 = 950;
static integer c__930 = 930;
static integer c__935 = 935;
static integer c__113 = 113;
static integer c__961 = 961;
static integer c__111 = 111;
static integer c__940 = 940;
static integer c__115 = 115;
static integer c__942 = 942;
static integer c__916 = 916;
static integer c__947 = 947;
static integer c__955 = 955;
static integer c__50 = 50;
static integer c__20 = 20;
#ifndef NO_PROTO
static real c_b1307 = 0.f;
static real c_b1309 = 1.f;
#else /* NO_PROTO */
static real c_b1307 = (float)0.;
static real c_b1309 = (float)1.;
#endif /* NO_PROTO */
static integer c__10 = 10;
#ifndef NO_PROTO
static real c_b1364 = .5f;
static real c_b1366 = 2.f;
static real c_b1464 = .15f;
static real c_b1637 = .03f;
#else /* NO_PROTO */
static real c_b1364 = (float).5;
static real c_b1366 = (float)2.;
static real c_b1464 = (float).15;
static real c_b1637 = (float).03;
#endif /* NO_PROTO */

/*  FILE: sublib.f */
/*  This library of subroutines is meant to be used by the individual */
/*  programs of the PHIGS Validation Tests (PVT). */
/*   Routines, in order: */

/*      SUBROUTINE initgl        : initialize globally */
/*   * SUBROUTINE xpopph        : Open PHIGS, allow implementor-dependent code
*/
/*    * SUBROUTINE multws        : access multiple workstation */
/*      SUBROUTINE setmsg        : set up pass/fail message */
/*      SUBROUTINE ifpf          : if _ then pass else fail */
/*      SUBROUTINE pass          : test case passed */
/*      SUBROUTINE fail          : test case failed */
/*      SUBROUTINE pf            : pass/fail common subroutine */
/*      SUBROUTINE chkinq        : check previous inquire */
/*      SUBROUTINE windup        : wind up this test */
/*      SUBROUTINE set2d         : set values in ragged 2d array */
/*      LOGICAL FUNCTION setis   : set is these values */
/*      LOGICAL FUNCTION seteq   : these sets are equal */
/*      SUBROUTINE setval        : set array to these values */
/*     SUBROUTINE setvs         : set array to integer values and get size*/
/*      SUBROUTINE iniari        : like setvs, but report error */
/*      SUBROUTINE setrvs        : set array to real values and get size */
/*      LOGICAL FUNCTION iareq   : equality for two integer arrays */
/*     LOGICAL FUNCTION iareql  : equality for two integer lengths and arrays
*/
/*     LOGICAL FUNCTION rareq   : approximate equality for two real arrays*/
/*     LOGICAL FUNCTION appeq   : approximate equality for two real numbers*/
/*     INTEGER FUNCTION iarfnd  : find location of key value in integer array
*/
/*      SUBROUTINE cpyiar        : copy integer array */
/*      SUBROUTINE srtiar        : sort integer array */
/*      SUBROUTINE srtrar        : sort real array */
/*      SUBROUTINE prsint        : parse integer */
/*      SUBROUTINE prsuin        : parse unsigned integer */
/*      SUBROUTINE prsrl         : parse real */
/*      SUBROUTINE ncmsg         : unanticipated non-conformance message */
/*      SUBROUTINE unmsg         : unanticipated condition message */
/*      SUBROUTINE inmsg         : informational message */
/*    * SUBROUTINE abend         : abnormal ending */
/*      SUBROUTINE brdmsg        : broadcast message */
/*      SUBROUTINE opmsg         : send operator message, sans workstation */
/*      SUBROUTINE opyn          : get operator yes/no response */
/*      SUBROUTINE opint         : get operator integer response */
/*      SUBROUTINE oplin         : get operator one-line response */
/*      SUBROUTINE deblnk        : compress out blanks from string */
/*      INTEGER FUNCTION leadnb  : find leading non-blank in string */
/*      INTEGER FUNCTION itrim   : locate last non-blank */
/*      SUBROUTINE errctl        : Error-handling control */
/*      SUBROUTINE sigtst        : Test signalled error */
/*      SUBROUTINE sigmsg        : Signalled error message */
/*      SUBROUTINE erfucd        : get function code from name */
/*      SUBROUTINE erfunm        : get function name from code */
/*    * SUBROUTINE stdcss        : sets up standard CSS */
/*    * SUBROUTINE csspth        : sets up standard CSS for path testing */
/*    * LOGICAL FUNCTION csseq   : Is CSS .eq. to set of ER paths? */
/*   * LOGICAL FUNCTION strcon  : Is a structure .eq. to type-content sequence
?*/
/*    * SUBROUTINE setstr        : set up a structure in the CSS */
/*   * SUBROUTINE newstr        : find identifier for a non-existent structure
*/
/*    * SUBROUTINE gtroot        : Get CSS roots */
/*    * LOGICAL FUNCTION sphdis  : Does ISS use Euclidean metric? */
/*    * SUBROUTINE chkelp        : Check element pointer value */
/*    * SUBROUTINE avarnm        : get valid archive name */
/*  ----- Routines for interactive tests ----- */
/*   * SUBROUTINE setdlg        : set up dialogue area for interactive test*/
/*    * SUBROUTINE endit         : close everything and end program */
/*    * SUBROUTINE win6          : draws 6 labelled windows on the screen */
/*    * SUBROUTINE wcnpc         : converts from WC to NPC */
/*    * SUBROUTINE locppm        : draws polymarker at indexed y-location */
/*    * SUBROUTINE drwrec        : draw rectangle */
/*   * SUBROUTINE txexal        : return size, alignments of text rectangle*/
/*    * LOGICAL FUNCTION intsty  : availability of interior styles */
/*    * SUBROUTINE denhat        : pick dense hatch style */
/*    * SUBROUTINE numlab        : draw numeric labels in a column */
/*    * SUBROUTINE vislab        : draw a text label in a box */
/*      SUBROUTINE dynpf         : pass/fail based on yes/no response */
/*      LOGICAL FUNCTION dyn     : get yes/no from operator */
/*      SUBROUTINE dchpf         : pass/fail based on location response */
/*      SUBROUTINE dchpfv        : pass/fail based on integer response */
/*      LOGICAL FUNCTION dchfl   : fail based on location response */
/*      LOGICAL FUNCTION dchflv  : fail based on integer response */
/*      SUBROUTINE dchoic        : get integer choice from operator */
/*     SUBROUTINE dlstpf        : pass/fail based on integer list response*/
/*      SUBROUTINE dilist        : get integer list from operator */
/*      SUBROUTINE drlval        : get real number from operator */
/*      SUBROUTINE dline         : get one-line string from operator */
/*      SUBROUTINE opfail        : get failure comment and do fail */
/*      SUBROUTINE opcofl        : get failure comment from operator */
/*      SUBROUTINE opcomt        : get neutral comment from operator */
/*      SUBROUTINE opco          : get operator comment */
/*      SUBROUTINE dstrng        : get multi-line string from operator */
/*      SUBROUTINE opmsgw        : put message to operator, and wait */
/*    * SUBROUTINE iacmsg        : put message to operator, no waiting */
/*    * SUBROUTINE iacans        : get single line response from operator */
/*    * SUBROUTINE setasf        : set all ASF's individual or bundled */
/*    * SUBROUTINE pstctl        : control posting of dialogue and picture */
/*     SUBROUTINE fitpar        : get line size to fit paragraph in rectangle
*/
/*      SUBROUTINE linbrk        : calculate line breaks for paragraph */
/*     SUBROUTINE scapar        : calculate scaling factor to fit paragraph*/
/*     REAL FUNCTION ylocel     : calculate y position for inheritance tests*/

/*     SUBROUTINE rn1shf        : random permutation for inheritance tests*/
/*      SUBROUTINE rnperm        : random permutation of first n integers */
/*     SUBROUTINE rnset         : random set n integers, chosen from 1-max*/
/*      SUBROUTINE rnbset        : random set n integers, chosen from m-n */
/*      INTEGER FUNCTION rndint  : random integer between two values */
/*      REAL FUNCTION rndrl      : random real between two values */
/*      REAL FUNCTION rnd01      : random real between 0 and 1 */
/* interacts with PHIGS; not pure Fortran. */
/*  Invocation structure: */
/*                rareq                              chkelp */
/*                  |                                  | */
/*                  |                   ------------------------------ */
/*                appeq                 |                   |        | */
/*                  |                 chkinq               pass    fail */
/*                  |                   |                   |        | */
/*                unmsg                 V                   V        V */
/*                  | */
/*                  V */
/* errctl                                                          sigtst */
/*                                                                   | */
/*                                                                   | */
/*                                         perhnd*   ---------------+-------*/

/*                     csseq                 |  \    |     |        |      |*/

/*           setval    / | \------------     |   \   |     |        |      |*/

/*             |      /  |  \          |     |    sigmsg   |  ifpf  |      |*/

/*      setis  |  set2d  |   gtroot    |     |             |  /  \  |      |*/

/*      /   \  |  /   \  |  /      \   |     |    multws   | /    \ |      |*/

/*  seteq    \ | /     \ | /         chkinq  |    setmsg  pass    fail   inmsg
   initgl*/
/*            \|/       \|/            |     |      |         \  /         |  
   / |*/
/*             |         |             |------------|          pf*         |  
  /  |*/
/*             | strcon  |             |            |           |          |  
 /   |*/
/*             | /    |  |             |            ------------|          |  
/    |*/
/* setstr    setvs    |  |             |                 |      |          | /
     |*/
/*   |   \ /   | \    |  |            ncmsg            unmsg    |          |/ 
   opyn*/
/*   |    X    |  \   |  |             |                 |      |          /  
    /*/
/*   |   / \   |   \  |  |             -------------------      |         /   
   /*/
/* deblnk   prsint  \ |  |                |                     |        /    
  /*/
/*             |     unmsg-->           abend*                  |       /     
 /*/
/*             |                          |  \                  |      /      
/*/
/*          prsuin                        |   \                 |     /      
/*/
/*                                     windup  \                |    /      /
*/
/*                                        |     \               |   /      /*/

/*          setrvs                        --------------------------      /*/
/*             |                                    |                    /*/
/*              |                                  brdmsg*               / */
/*           prsrl                                   |                  / */
/*                                                   ------------------- */
/*                                                          | */
/*                                                        opmsg* */
/*  * not designed to be callable directly by test programs */
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

/*  * S: Static value read from configuration file */
/*    D: Dynamic variable, altered during test execution */

/*    I: Integer */
/*    C: Character */
/*    R: Real */
/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/initgl                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int initgl_(char *ident, ftnlen ident_len)
#else /* NO_PROTO */
/* Subroutine */ int initgl_(ident, ident_len)
char *ident;
ftnlen ident_len;
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_800[] = "(a)";

    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3];
    char ch__1[89];
    olist o__1;
    cllist cl__1;
    alist al__1, al__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer f_open(olist *), f_rew(alist *), s_rsue(cilist *), do_uio(integer 
	    *, char *, ftnlen), e_rsue(void), f_clos(cllist *), s_rsfe(cilist 
	    *), do_fio(integer *, char *, ftnlen), e_rsfe(void), f_back(alist 
	    *);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_wsle(), do_lio(), e_wsle();
    /* Subroutine */ int s_stop(), s_copy();
    integer f_open(), f_rew(), s_rsue(), do_uio(), e_rsue(), f_clos(), s_rsfe(
	    ), do_fio(), e_rsfe(), f_back();
    /* Subroutine */ int s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer it, ix;
    static char ans[1];
    static integer lun;
#ifndef NO_PROTO
    extern /* Subroutine */ int opyn_(char *, char *, ftnlen, ftnlen), ncmsg_(
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opyn_(), ncmsg_();
#endif /* NO_PROTO */
    static integer ioerr;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static char idchar[1], filenm[60], dumrec[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int brdmsg_(char *, ftnlen), nerhnd (integer *, 
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int brdmsg_(), nerhnd ();
#endif /* NO_PROTO */
    static integer nwksav;
    static char inderr[30], errprf[30];
#ifndef NO_PROTO
    extern /* Subroutine */ int sigmsg_(integer *, char *, char *, ftnlen, 
	    ftnlen), erfunm_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int sigmsg_(), erfunm_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, 0, 0 };
    static cilist io___9 = { 0, 6, 0, 0, 0 };
    static cilist io___10 = { 0, 6, 0, 0, 0 };
    static cilist io___11 = { 1, 0, 1, 0, 0 };
    static cilist io___12 = { 0, 6, 0, 0, 0 };
    static cilist io___13 = { 1, 0, 1, 0, 0 };
    static cilist io___14 = { 0, 6, 0, 0, 0 };
    static cilist io___15 = { 1, 0, 1, 0, 0 };
    static cilist io___17 = { 0, 6, 0, 0, 0 };
    static cilist io___18 = { 0, 6, 0, 0, 0 };
    static cilist io___20 = { 0, 6, 0, 0, 0 };
    static cilist io___21 = { 1, 0, 1, fmt_800, 0 };
    static cilist io___23 = { 0, 6, 0, 0, 0 };
    static cilist io___25 = { 0, 6, 0, 0, 0 };

/*  MANUAL CHANGE HERE  */

#ifndef NO_PROTO
   extern void pvt_err_hand  (Pint errnr_act, Pint funccd_act, char *fn);
   void (*current_handler_1) (Pint errnr_act, Pint funccd_act, char *fn);
#else /* NO_PROTO */
   extern void pvt_err_hand  ();
   void (*current_handler_1) ();
#endif /* NO_PROTO */

/*  END MANUAL CHANGE   */

/*  Initgl accepts the identifying hierarchical number of the test */
/*  program and initializes the GLOBAL COMMON variables, mostly from */
/*  values read from the INITPH.DAT file.  It then opens message */
/*  files as indicated by control variables.  This routine is */
/*  normally the first thing called by a test program. */
/* check validity of IDENT */
    it = itrim_(ident, ident_len);
    if (it < 5) {
	goto L60;
    }
    i__1 = it;
    for (ix = 1; ix <= i__1; ++ix) {
	*idchar = ident[ix - 1];
	if (ix == it - 2) {
	    if (*idchar != '/') {
		goto L60;
	    }
	} else if (ix % 3 == 0) {
	    if (*idchar != '.') {
		goto L60;
	    }
	} else {
	    if (*idchar < '0' || *idchar > '9') {
		goto L60;
	    }
	}
/* L50: */
    }
    goto L70;
L60:
    s_wsle(&io___4);
    do_lio(&c__9, &c__1, "Format of program-identifier is invalid: ", 41L);
    do_lio(&c__9, &c__1, ident, ident_len);
    e_wsle();
    s_stop("", 0L);
L70:
/* *** *** *** ***  Initialize common for operator comment */
    s_copy(opcomm_1.ophead, "NO TEST CASES YET:", 300L, 18L);
/* *** *** *** ***  Initialize global common */
/* initialize global common from input parameter */
    s_copy(globch_1.pident, ident, 40L, ident_len);
    s_copy(globch_1.tstmsg, " ", 900L, 1L);
/* set error and test counts to 0 */
    globnu_1.unerr = 0;
    globnu_1.ierrct = 0;
    globnu_1.testct = 0;
/* set handler-control to default (perhnd reports and aborts). */
    globnu_1.ctlhnd = 0;
/* initialize global common from system configuration file */
/* filename and logical unit number for system configuration file. */
/* ********************************************************** */

/* USERMOD  NOTE: The following must be initialized to the absolute file 
*/
/* USERMOD  name for the system configuration file.  This must be */
/* USERMOD  customized for each installation.  See the MULTWS */
/* USERMOD  subroutine, immediately below, and also the INITPH */
/* USERMOD  program which writes the file. */

/* ********************************************************** */
    s_copy(filenm, "/home/cugini/pvt/work/v2.1/INITPH.DAT", 60L, 37L);
/* ********************************************************* */

/* USERMOD  End of customization */

/* ********************************************************* */
/*  Use random unit number - no other files open yet, so should be OK. */
    lun = 21;
    s_copy(errprf, "INITGL abort.  Error code for ", 30L, 30L);
    o__1.oerr = 1;
    o__1.ounit = lun;
    o__1.ofnmlen = 60;
    o__1.ofnm = filenm;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsle(&io___9);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "OPEN of configuration file = ", 29L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
/*  position at beginning of file */
    al__1.aerr = 1;
    al__1.aunit = lun;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsle(&io___10);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "REWIND of configuration file = ", 31L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    io___11.ciunit = lun;
    ioerr = s_rsue(&io___11);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = do_uio(&c__1, (char *)&errinf_1.ernmsw, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = do_uio(&c__1, errchr_1.errmrk, 20L);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = e_rsue();
L100001:
    if (ioerr != 0) {
	s_wsle(&io___12);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "READ1 of configuration file = ", 30L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    io___13.ciunit = lun;
    ioerr = s_rsue(&io___13);
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
    ioerr = e_rsue();
L100002:
    if (ioerr != 0) {
	s_wsle(&io___14);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "READ2 of configuration file = ", 30L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    io___15.ciunit = lun;
    ioerr = s_rsue(&io___15);
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
    ioerr = do_uio(&c__1, (char *)&ranctl_1.rlseed, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = e_rsue();
L100003:
    if (ioerr != 0) {
	s_wsle(&io___17);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "READ3 of configuration file = ", 30L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    cl__1.cerr = 1;
    cl__1.cunit = lun;
    cl__1.csta = 0;
    ioerr = f_clos(&cl__1);
    if (ioerr != 0) {
	s_wsle(&io___18);
	do_lio(&c__9, &c__1, errprf, 30L);
	do_lio(&c__9, &c__1, "CLOSE of configuration file = ", 30L);
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
/* *** *** ***  Initialize error-handling common area   *** *** *** */
/*  set these to invalid values to make sure error handling routines */
/*  initialize them: */
    errinf_1.errcom = -1;
    errinf_1.funcom = -1;
    errinf_1.filcom = -1;
    errinf_1.expsiz = -1;
    for (it = 1; it <= 10; ++it) {
	errinf_1.experr[it - 1] = -1;
/* L80: */
    }
    for (it = 1; it <= 200; ++it) {
	errinf_1.errsav[it - 1] = -1;
	errinf_1.funsav[it - 1] = -1;
	errinf_1.filsav[it - 1] = -1;
/* L90: */
    }
    s_copy(errchr_1.errsrs, "Un-initialized", 40L, 14L);
    s_copy(errchr_1.erflnm, "Un-initialized", 80L, 14L);
    s_copy(errchr_1.curcon, "Un-initialized", 200L, 14L);
    s_copy(errchr_1.contab, "Un-initialized", 150L, 14L);
/*  normal mode: NOT testing error handling. */
    errinf_1.usrerr = 0;

/*  MANUAL CHANGE HERE  */

/*  Use C mechanism to make PVT-defined error handler (pvt_err_hand)
    the usual handler for PVT code;  this may be reversed by ESETUP
    to the system-defined error handler (perr_hand).
*/
    pset_err_hand (pvt_err_hand, &current_handler_1);

/*  END MANUAL CHANGE   */

/* *** *** *** ***  Initialize global common from operator, if necessary 
*/
    if (globnu_1.passsw == 2) {
	opyn_("Generate run-time messages for successful conditions?", ans, 
		53L, 1L);
	if (*ans == 'y') {
	    globnu_1.passsw = 1;
	} else {
	    globnu_1.passsw = 0;
	}
    }
/* *** *** *** ***  Open message files, as needed. */
    if (globnu_1.iflerr == 1 || globnu_1.iflerr == 3) {
/* open global file for append */
	o__1.oerr = 1;
	o__1.ounit = globnu_1.glblun;
	o__1.ofnmlen = 60;
	o__1.ofnm = globch_1.glberr;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = "FORMATTED";
	o__1.oblnk = 0;
	ioerr = f_open(&o__1);
	if (ioerr != 0) {
	    s_wsle(&io___20);
	    do_lio(&c__9, &c__1, errprf, 30L);
	    do_lio(&c__9, &c__1, "OPEN of global file = ", 22L);
	    do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    e_wsle();
	    s_stop("", 0L);
	}
/* L800: */
/* ********************************************************* */

/* USERMOD  To make append work more efficiently, if desired, change 
*/
/* USERMOD  the following to system-specific magic code which will */
/* USERMOD  open the global message file and position it after the */
/* USERMOD  last record, to allow new records to be added.  The */
/* USERMOD  routine above seems to be the only Fortran-standard way */

/* USERMOD  to do it. */

/* ********************************************************* */
/* position at end-of-file */
L100:
	io___21.ciunit = globnu_1.glblun;
	ioerr = s_rsfe(&io___21);
	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = do_fio(&c__1, dumrec, 300L);
	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = e_rsfe();
L100004:
	if (ioerr < 0) {
	    goto L200;
	}
	if (ioerr != 0) {
	    s_wsle(&io___23);
	    do_lio(&c__9, &c__1, errprf, 30L);
	    do_lio(&c__9, &c__1, "READ of global file = ", 22L);
	    do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    e_wsle();
	    s_stop("", 0L);
	}
	goto L100;
L200:
	al__2.aerr = 0;
	al__2.aunit = globnu_1.glblun;
	f_back(&al__2);
/* ********************************************************* */

/* USERMOD  End of customization */

/* ********************************************************* */
    }
    it = itrim_(globch_1.pident, 40L);
    if (globnu_1.iflerr == 2 || globnu_1.iflerr == 3) {
/* create individual message file */
/* generate file name */
	i__1 = it - 2;
/* Writing concatenation */
	i__2[0] = 1, a__1[0] = "p";
	i__2[1] = it - i__1, a__1[1] = globch_1.pident + i__1;
	i__2[2] = 4, a__1[2] = ".msg";
	s_cat(inderr, a__1, i__2, &c__3, 30L);
	o__1.oerr = 1;
	o__1.ounit = globnu_1.indlun;
	o__1.ofnmlen = 30;
	o__1.ofnm = inderr;
	o__1.orl = 0;
	o__1.osta = "UNKNOWN";
	o__1.oacc = 0;
	o__1.ofm = "FORMATTED";
	o__1.oblnk = 0;
	ioerr = f_open(&o__1);
	al__1.aerr = 0;
	al__1.aunit = globnu_1.indlun;
	f_rew(&al__1);
	if (ioerr != 0) {
	    s_wsle(&io___25);
	    do_lio(&c__9, &c__1, errprf, 30L);
	    do_lio(&c__9, &c__1, "OPEN of individual file = ", 26L);
	    do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    e_wsle();
	    s_stop("", 0L);
	}
    }
/* Broadcast beginning-of-program message */
/* Writing concatenation */
    i__2[0] = 36, a__1[0] = "SY: ------- Begin execution of PVT #";
    i__2[1] = it, a__1[1] = globch_1.pident;
    i__2[2] = 13, a__1[2] = ", version 2.2";
    s_cat(ch__1, a__1, i__2, &c__3, 89L);
    brdmsg_(ch__1, it + 49);
/*  Following statement is never executed, but may help cause PERHND */
/*  to be linked into executable module, as well as routines called */
/*  directly by PVT version of PERHND. */
    if (s_cmp(globch_1.pident, "A bogus string value", 40L, 20L) == 0) {
	unmsg_("This should never happen.", 25L);
	ncmsg_("This should never happen.", 25L);
	sigmsg_(&c__0, "bogus function name", dumrec, 19L, 300L);
	erfunm_(&c_n1, globch_1.funcid, 80L);
	nerhnd (&c__0, &c__0, &c__0);
    }
/* L666: */
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* initgl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/xpopph                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int xpopph_(integer *errprm, integer *memprm)
#else /* NO_PROTO */
/* Subroutine */ int xpopph_(errprm, memprm)
integer *errprm, *memprm;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nopph (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopph ();
#endif /* NO_PROTO */

/* XPOPPH serves to open PHIGS on the system under test. */
/* USERMOD If needed, insert implementation-dependent code before */
/* USERMOD opening PHIGS. */
    nopph (errprm, memprm);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* xpopph_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/multws                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int multws_(integer *iwk, char *categ, integer *onwk, 
	integer *owkid, integer *oconid, integer *owtype, char *owcat, ftnlen 
	categ_len, ftnlen owcat_len)
#else /* NO_PROTO */
/* Subroutine */ int multws_(iwk, categ, onwk, owkid, oconid, owtype, owcat, 
	categ_len, owcat_len)
integer *iwk;
char *categ;
integer *onwk, *owkid, *oconid, *owtype;
char *owcat;
ftnlen categ_len;
ftnlen owcat_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static logical rdfile = FALSE_;

    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2, i__3;
    char ch__1[37], ch__2[39], ch__3[40], ch__4[36], ch__5[38];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer f_open(olist *), s_wsfi(icilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfi(void), f_rew(alist *), s_rsue(cilist *), do_uio(
	    integer *, char *, ftnlen), e_rsue(void), f_clos(cllist *), s_cmp(
	    char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_indx(), i_len();
    /* Subroutine */ int s_cat(), s_copy();
    integer f_open(), s_wsfi(), do_fio(), e_wsfi(), f_rew(), s_rsue(), do_uio(
	    ), e_rsue(), f_clos(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i;
    static char msg[300];
    static integer lun;
    static char mcat[1*100];
    static integer dumi[9], dumj[2];
    static real dumr;
    static char dumc1[60], dumc2[20];
    static real efrac;
    static integer wkcat, mwkid[100];
    static real dsize;
    static integer ioerr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclwk (integer *), nqwkc (integer *, integer *
	    , integer *, integer *), unmsg_(char *, ftnlen), nopwk (integer *,
	     integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclwk (), nqwkc (), unmsg_(), nopwk ();
#endif /* NO_PROTO */
    static char catcod[6];
    static integer mconid[100];
    static char filenm[60];
    static integer dtclim;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, specon, scrmod, dstdnr;
    static real mtrpdc;
    static char errprf[30];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqwkca (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqwkca ();
#endif /* NO_PROTO */
    static integer specwt, dintyp, nwksav, doutyp, mwtype[100];

    /* Fortran I/O blocks */
    static icilist io___34 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static icilist io___35 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static cilist io___36 = { 1, 0, 1, 0, 0 };
    static icilist io___39 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static cilist io___40 = { 1, 0, 1, 0, 0 };
    static icilist io___49 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static cilist io___50 = { 1, 0, 1, 0, 0 };
    static icilist io___55 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static cilist io___56 = { 1, 0, 1, 0, 0 };
    static icilist io___60 = { 0, msg, 0, "(A,I3,A,I8)", 300, 1 };
    static icilist io___66 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static icilist io___67 = { 0, msg, 0, "(A,I5)", 300, 1 };


/*  Multws returns information about access to multiple workstations: */

/*  ------- Input parameters: */
/*  IWK     : requested element of list of available workstations */
/*            within requested categories (must be between 0 and ONWK). */

/*  CATEG   : Requested categories of workstation, according to the */
/*            following code: */
/*                o : OUTPUT */
/*                i : INPUT */
/*                d : OUTIN */
/*                m : MO (metafile output) */
/*                n : MI (metafile input) */
/*                a : all accessible workstations, regardless of category 
*/
/*            Eg, to request all metafile workstations, specify 'mn'; */
/*            to request all OUTPUT and OUTIN workstations, specify 'od'. 
*/

/*  ------- Output parameters: */
/*  ONWK    : number of accessible workstations within the */
/*            requested categories. */
/*  OWKID   : workstation identifier for IWKth workstation */
/*  OCONID  : connection identifier for IWKth workstation */
/*  OWTYPE  : workstation type for IWKth workstation */
/*  OWCAT   : workstation category for IWKth workstation */
/*            (one character; see category codes under CATEG above). */

/*  This information is taken from the configuration file, which is */
/*  read only on the first invocation.  The three parameters for */
/*  opening the workstation when IWK=1 are identical to those of the */
/*  default workstation in COMMON: wkid, conid, wtype. */
/*dummy variables to read into - mostly skip 1st two records of config fil
e*/
/* workstation category */
/* check validity of CATEG */
    if (i_indx(categ, "a", categ_len, 1L) > 0 && i_len(categ, categ_len) > 1) 
	    {
/* Writing concatenation */
#ifndef NO_PROTO
	i__1[0] = 53, a__1[0] = "Invalid category (\"a\" is not alone) passe"
		"d to MULTWS:";
#else /* NO_PROTO */
	i__1[0] = 53, a__1[0] = "Invalid category (\"a\" is not alone) passe\
d to MULTWS:";
#endif /* NO_PROTO */
	i__1[1] = categ_len, a__1[1] = categ;
	s_cat(msg, a__1, i__1, &c__2, 300L);
	unmsg_(msg, 300L);
    }
    s_copy(catcod, "oidmna", 6L, 6L);
    i__2 = i_len(categ, categ_len);
    for (i = 1; i <= i__2; ++i) {
	if (i_indx(catcod, categ + (i - 1), 6L, 1L) <= 0) {
/* Writing concatenation */
	    i__1[0] = 34, a__1[0] = "Invalid category passed to MULTWS:";
	    i__1[1] = categ_len, a__1[1] = categ;
	    s_cat(msg, a__1, i__1, &c__2, 300L);
	    unmsg_(msg, 300L);
	}
/* L20: */
    }
/* read file first time only */
    if (rdfile) {
	goto L100;
    }
/* ********************************************************** */

/* USERMOD  NOTE: The following must be initialized to the absolute file 
*/
/* USERMOD  name for the system configuration file.  This must be */
/* USERMOD  customized for each installation.  See the INITGL */
/* USERMOD  subroutine, immediately above, and also the INITPH */
/* USERMOD  program which writes the file. */

/* ********************************************************** */
    s_copy(filenm, "/home/cugini/pvt/work/v2.1/INITPH.DAT", 60L, 37L);
/* ********************************************************* */

/* USERMOD  End of customization */

/* ********************************************************* */
/* find unused unit number: */
    if ((i__2 = globnu_1.indlun - globnu_1.glblun, abs(i__2)) >= 2) {
	lun = (globnu_1.indlun + globnu_1.glblun) / 2;
    } else {
	lun = globnu_1.glblun + 2;
    }
/* prefix for error messages */
    s_copy(errprf, "MULTWS abort.  Error code for ", 30L, 30L);
    o__1.oerr = 1;
    o__1.ounit = lun;
    o__1.ofnmlen = 60;
    o__1.ofnm = filenm;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsfi(&io___34);
/* Writing concatenation */
	i__1[0] = 30, a__1[0] = errprf;
	i__1[1] = 7, a__1[1] = "OPEN = ";
	s_cat(ch__1, a__1, i__1, &c__2, 37L);
	do_fio(&c__1, ch__1, 37L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  position at beginning of file */
    al__1.aerr = 1;
    al__1.aunit = lun;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsfi(&io___35);
/* Writing concatenation */
	i__1[0] = 30, a__1[0] = errprf;
	i__1[1] = 9, a__1[1] = "REWIND = ";
	s_cat(ch__2, a__1, i__1, &c__2, 39L);
	do_fio(&c__1, ch__2, 39L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  skip past first two records */
    io___36.ciunit = lun;
    ioerr = s_rsue(&io___36);
    if (ioerr != 0) {
	goto L100005;
    }
    ioerr = do_uio(&c__1, (char *)&dumi[0], (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100005;
    }
    ioerr = do_uio(&c__1, dumc2, 20L);
    if (ioerr != 0) {
	goto L100005;
    }
    ioerr = e_rsue();
L100005:
    if (ioerr != 0) {
	s_wsfi(&io___39);
/* Writing concatenation */
	i__1[0] = 30, a__1[0] = errprf;
	i__1[1] = 10, a__1[1] = "READ #1 = ";
	s_cat(ch__3, a__1, i__1, &c__2, 40L);
	do_fio(&c__1, ch__3, 40L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
    io___40.ciunit = lun;
    ioerr = s_rsue(&io___40);
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_uio(&c__1, (char *)&doutyp, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_uio(&c__1, (char *)&dtclim, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_uio(&c__1, (char *)&dintyp, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_uio(&c__1, (char *)&dstdnr, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_uio(&c__1, (char *)&dsize, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_uio(&c__1, (char *)&efrac, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_uio(&c__1, (char *)&scrmod, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = do_uio(&c__1, (char *)&mtrpdc, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100006;
    }
    ioerr = e_rsue();
L100006:
    if (ioerr != 0) {
	s_wsfi(&io___49);
/* Writing concatenation */
	i__1[0] = 30, a__1[0] = errprf;
	i__1[1] = 10, a__1[1] = "READ #2 = ";
	s_cat(ch__3, a__1, i__1, &c__2, 40L);
	do_fio(&c__1, ch__3, 40L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
/* get NWKSAV - number of accessible workstations */
    io___50.ciunit = lun;
    ioerr = s_rsue(&io___50);
    if (ioerr != 0) {
	goto L100007;
    }
    ioerr = do_uio(&c__9, (char *)&dumi[0], (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100007;
    }
    ioerr = do_uio(&c__1, dumc1, 60L);
    if (ioerr != 0) {
	goto L100007;
    }
    ioerr = do_uio(&c__2, (char *)&dumj[0], (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100007;
    }
    ioerr = do_uio(&c__1, (char *)&nwksav, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100007;
    }
    ioerr = do_uio(&c__1, (char *)&dumr, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100007;
    }
    ioerr = e_rsue();
L100007:
    if (ioerr != 0) {
	s_wsfi(&io___55);
/* Writing concatenation */
	i__1[0] = 30, a__1[0] = errprf;
	i__1[1] = 10, a__1[1] = "READ #3 = ";
	s_cat(ch__3, a__1, i__1, &c__2, 40L);
	do_fio(&c__1, ch__3, 40L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
/* go thru accessible workstations and initialize arrays */
    i__2 = nwksav;
    for (i = 1; i <= i__2; ++i) {
	io___56.ciunit = lun;
	ioerr = s_rsue(&io___56);
	if (ioerr != 0) {
	    goto L100008;
	}
	ioerr = do_uio(&c__1, (char *)&mwkid[i - 1], (ftnlen)sizeof(integer));

	if (ioerr != 0) {
	    goto L100008;
	}
	ioerr = do_uio(&c__1, (char *)&mconid[i - 1], (ftnlen)sizeof(integer))
		;
	if (ioerr != 0) {
	    goto L100008;
	}
	ioerr = do_uio(&c__1, (char *)&mwtype[i - 1], (ftnlen)sizeof(integer))
		;
	if (ioerr != 0) {
	    goto L100008;
	}
	ioerr = e_rsue();
L100008:
	if (ioerr != 0) {
	    s_wsfi(&io___60);
/* Writing concatenation */
	    i__1[0] = 30, a__1[0] = errprf;
	    i__1[1] = 6, a__1[1] = "wkst #";
	    s_cat(ch__4, a__1, i__1, &c__2, 36L);
	    do_fio(&c__1, ch__4, 36L);
	    do_fio(&c__1, (char *)&i, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " READ = ", 8L);
	    do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	    e_wsfi();
	    unmsg_(msg, 300L);
	}
/* determine category of workstation */
	nqwkca (&mwtype[i - 1], &errind, &wkcat);
	if (errind == 51) {
/* generic no good - try to open wkstat and get category for speci
fic type */
	    nopwk (&mwkid[i - 1], &mconid[i - 1], &mwtype[i - 1]);
	    nqwkc (&mwkid[i - 1], &errind, &specon, &specwt);
	    chkinq_("pqwkc", &errind, 5L);
	    nqwkca (&specwt, &errind, &wkcat);
	    chkinq_("pqwkca", &errind, 6L);
	    nclwk (&mwkid[i - 1]);
	} else {
	    chkinq_("pqwkca", &errind, 6L);
	}
/* encode category */
	if (wkcat >= 0 && wkcat <= 4) {
	    i__3 = wkcat;
	    s_copy(mcat + (i - 1), catcod + i__3, 1L, wkcat + 1 - i__3);
	} else {
/* got invalid category */
	    mcat[i - 1] = 'x';
	}
/* L50: */
    }
    cl__1.cerr = 1;
    cl__1.cunit = lun;
    cl__1.csta = 0;
    ioerr = f_clos(&cl__1);
    if (ioerr != 0) {
	s_wsfi(&io___66);
/* Writing concatenation */
	i__1[0] = 30, a__1[0] = errprf;
	i__1[1] = 8, a__1[1] = "CLOSE = ";
	s_cat(ch__5, a__1, i__1, &c__2, 38L);
	do_fio(&c__1, ch__5, 38L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
/* prevent re-reading of file */
    rdfile = TRUE_;
L100:
/* fill output parameters from array */
/* here are defaults: */
    *owkid = -1;
    *oconid = -1;
    *owtype = -1;
    *owcat = '?';
    *onwk = 0;
    i__2 = nwksav;
    for (i = 1; i <= i__2; ++i) {
/* skip if this wkst not in requested category-set */
	if (s_cmp(categ, "a", categ_len, 1L) != 0 && i_indx(categ, mcat + (i 
		- 1), categ_len, 1L) <= 0) {
	    goto L200;
	}
	++(*onwk);
	if (*onwk == *iwk) {
/* requested entry: */
	    *owkid = mwkid[i - 1];
	    *oconid = mconid[i - 1];
	    *owtype = mwtype[i - 1];
	    *owcat = mcat[i - 1];
	}
L200:
	;
    }
    if (*iwk < 0 || *iwk > *onwk) {
	s_wsfi(&io___67);
	do_fio(&c__1, "Requested workstation out of range in MULTWS:", 45L);
	do_fio(&c__1, (char *)&(*iwk), (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* multws_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/setmsg                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setmsg_(char *srlist, char *msg, ftnlen srlist_len, 
	ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int setmsg_(srlist, msg, srlist_len, msg_len)
char *srlist, *msg;
ftnlen srlist_len;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2], a__2[4];
    integer i__1[2], i__2, i__3, i__4[4];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_cat();
    integer i_indx();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static char ch[1];
    static integer it, loc, lim, idig;
    static char term[1];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static char fixsr[80];

/*  Setmsg parses the srlist (a list of semantic requirements), accepts an
 */
/*  associated message describing the condition about to be tested, and */

/*  sets the COMMON variable tstmsg to a resulting value, to be issued by 
*/
/*  either pass or fail, whichever is next executed. */
/*  Both pass and fail blank out tstmsg as a sign that they have processed
 */
/*  it, and so setmsg requires that it be blank upon entry. */
    if (s_cmp(globch_1.tstmsg, " ", 900L, 1L) != 0) {
	unmsg_("Non-blank tstmsg detected by setmsg.  Program logic error.", 
		58L);
    }
/* srlist must be a list of 1 or 2-digit numbers separated by spaces. */
/* This routine edits out extra spaces and leading zeros. */
/* term is an "unusual" character, used to terminate string */
    *term = '\17';
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = " ";
    i__1[1] = srlist_len, a__1[1] = srlist;
    s_cat(fixsr, a__1, i__1, &c__2, 80L);
    it = itrim_(fixsr, 80L) + 1;
    fixsr[it - 1] = *term;
/* edit out extra spaces - we assume fixsr is longer than srlist and has 
*/
/* some trailing spaces. */
L100:
    loc = i_indx(fixsr, "  ", 80L, 2L);
    lim = i_indx(fixsr, term, 80L, 1L);
    if (loc > 0 && loc < lim) {
	i__2 = loc;
	s_copy(fixsr + (loc - 1), fixsr + i__2, 80 - (loc - 1), 80 - i__2);
	goto L100;
    }
/* edit out leading zeros */
L200:
    loc = i_indx(fixsr, " 0", 80L, 2L);
    if (loc > 0) {
	i__2 = loc;
	i__3 = loc + 1;
	s_copy(fixsr + i__2, fixsr + i__3, 80 - i__2, 80 - i__3);
	goto L200;
    }
/* should be only digits and spaces */
    loc = 0;
    idig = 0;
L300:
    ++loc;
    *ch = fixsr[loc - 1];
    if (*ch == *term) {
	goto L400;
    }
    if (*ch == ' ') {
	goto L300;
    }
    if (*ch >= '0' && *ch <= '9') {
	idig = 1;
	goto L300;
    }
/* Illegal character in parameter - bomb this test */
    unmsg_("Illegal character in setmsg srlist-parameter.", 45L);
L400:
    if (idig == 0) {
	unmsg_("No digits found in setmsg srlist-parameter.", 43L);
    }
/* OK, fixsr looks valid... */
    lim = i_indx(fixsr, term, 80L, 1L) - 1;
/* set up pass/fail message */
/* Writing concatenation */
    i__4[0] = 3, a__2[0] = "#SR";
    i__4[1] = lim, a__2[1] = fixsr;
    i__4[2] = 2, a__2[2] = ", ";
    i__4[3] = msg_len, a__2[3] = msg;
    s_cat(globch_1.tstmsg, a__2, i__4, &c__4, 900L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setmsg_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/ifpf                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ifpf_(logical *cond)
#else /* NO_PROTO */
/* Subroutine */ int ifpf_(cond)
logical *cond;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_();
#endif /* NO_PROTO */

/*  Ifpf simply provides a short form for the typical coding: if */
/*  (condition) then pass else fail. */
    if (*cond) {
	pass_();
    } else {
	fail_();
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ifpf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/pass                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int pass_(void)
#else /* NO_PROTO */
/* Subroutine */ int pass_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pf_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pf_();
#endif /* NO_PROTO */

/*  pass handles the processing of a pass-condition. */
    pf_("p", 1L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pass_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/fail                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int fail_(void)
#else /* NO_PROTO */
/* Subroutine */ int fail_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int pf_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int pf_();
#endif /* NO_PROTO */

/*  pass handles the processing of a fail-condition. */
    ++globnu_1.ierrct;
    pf_("f", 1L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* fail_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/pf                                   * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int pf_(char *result, ftnlen result_len)
#else /* NO_PROTO */
/* Subroutine */ int pf_(result, result_len)
char *result;
ftnlen result_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[5];
    integer i__1[5];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfi(icilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfi(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static char buf[999], acond[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static char condvb[10];
#ifndef NO_PROTO
    extern /* Subroutine */ int brdmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int brdmsg_();
#endif /* NO_PROTO */
    static char msgtyp[4];

    /* Fortran I/O blocks */
    static icilist io___76 = { 0, acond, 0, "(I3)", 3, 1 };


/*  pf handles the processing of the pass/fail condition. */
    if (! (*result == 'p' || *result == 'f')) {
	unmsg_("Input parameter to pf neither p nor f.", 38L);
    }
    if (s_cmp(globch_1.tstmsg, " ", 900L, 1L) == 0) {
	unmsg_("Blank tstmsg detected by pf.  Program logic error.", 50L);
    }
    ++globnu_1.testct;
    s_wsfi(&io___76);
    do_fio(&c__1, (char *)&globnu_1.testct, (ftnlen)sizeof(integer));
    e_wsfi();
    if (*result == 'p') {
	s_copy(msgtyp, "OK: ", 4L, 4L);
	s_copy(condvb, " passed:  ", 10L, 10L);
    } else {
	s_copy(msgtyp, "FA: ", 4L, 4L);
	s_copy(condvb, " failed:  ", 10L, 10L);
    }
/* Writing concatenation */
    i__1[0] = 4, a__1[0] = msgtyp;
    i__1[1] = 11, a__1[1] = "Condition #";
    i__1[2] = 3, a__1[2] = acond;
    i__1[3] = 10, a__1[3] = condvb;
    i__1[4] = 900, a__1[4] = globch_1.tstmsg;
    s_cat(buf, a__1, i__1, &c__5, 999L);
/* blank out tstmsg to signify use by pass/fail. */
    s_copy(globch_1.tstmsg, " ", 900L, 1L);
/* optional suppression of pass-messages done here. */
    if (*result == 'f' || globnu_1.passsw == 1) {
	brdmsg_(buf, 999L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/chkinq                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int chkinq_(char *routnm, integer *ierrcd, ftnlen routnm_len)

#else /* NO_PROTO */
/* Subroutine */ int chkinq_(routnm, ierrcd, routnm_len)
char *routnm;
integer *ierrcd;
ftnlen routnm_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[7];
    integer i__1[7];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static char buf[200], aerr[9];
#ifndef NO_PROTO
    extern /* Subroutine */ int ncmsg_(char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ncmsg_();
    extern integer itrim_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___81 = { 0, aerr, 0, "(I9)", 9, 1 };


/*  Chkinq is used to check that inquire-functions have returned a value 
*/
/*  of zero as the error code.  It is normally called after invoking an */

/*  inquire which is being used incidentally, i.e., one which is NOT the 
*/
/*  object of interest of the test, but rather one whose returned values 
*/
/*  are needed to test OTHER functions.  Nonetheless, the failure of such 
*/
/*  an inquire is a failure of the implementation, since these inquires */

/*  are called only in circumstances when they should work. */
    if (*ierrcd == 0) {
	return 0;
    }
    s_wsfi(&io___81);
    do_fio(&c__1, (char *)&(*ierrcd), (ftnlen)sizeof(integer));
    e_wsfi();
/* Writing concatenation */
    i__1[0] = 20, a__1[0] = "Unexpected error in ";
    i__1[1] = itrim_(globch_1.pident, 40L), a__1[1] = globch_1.pident;
    i__1[2] = 14, a__1[2] = ", Function = \"";
    i__1[3] = routnm_len, a__1[3] = routnm;
    i__1[4] = 16, a__1[4] = "\", Error code = ";
    i__1[5] = 9, a__1[5] = aerr;
    i__1[6] = 1, a__1[6] = ".";
    s_cat(buf, a__1, i__1, &c__7, 200L);
    ncmsg_(buf, 200L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chkinq_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/windup                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int windup_(void)
#else /* NO_PROTO */
/* Subroutine */ int windup_()
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[9], a__2[5], a__3[2];
    integer i__1[9], i__2[5], i__3[2];
    char ch__1[106], ch__2[41], ch__3[74];
    cllist cl__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer s_cmp(char *, char *, ftnlen, ftnlen), f_clos(cllist *);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
    integer s_cmp(), f_clos();
#endif /* NO_PROTO */

    /* Local variables */
    static char err[7];
    static integer isz, icsz;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static char cword[11];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int brdmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int brdmsg_();
#endif /* NO_PROTO */
    static char aerrct[3], atstct[3];

    /* Fortran I/O blocks */
    static icilist io___86 = { 0, aerrct, 0, "(I3)", 3, 1 };
    static icilist io___88 = { 0, atstct, 0, "(I3)", 3, 1 };
    static icilist io___91 = { 0, aerrct, 0, "(I3)", 3, 1 };


/*  Windup handles end-of-test processing - it formulates two */
/*  messages, one with the total error count, the second to proclaim */
/*  end of execution.  If there has been an unanticipated error it */
/*  also generates a message for that.  It then closes the error */
/*  files, as needed.  It is normally the last thing called by a */
/*  test. */
    s_copy(err, " errors", 7L, 7L);
    s_copy(cword, " conditions", 11L, 11L);
    s_wsfi(&io___86);
    do_fio(&c__1, (char *)&globnu_1.ierrct, (ftnlen)sizeof(integer));
    e_wsfi();
    s_wsfi(&io___88);
    do_fio(&c__1, (char *)&globnu_1.testct, (ftnlen)sizeof(integer));
    e_wsfi();
    if (globnu_1.ierrct == 1) {
	isz = 6;
    } else {
	isz = 7;
    }
    if (globnu_1.testct == 1) {
	icsz = 10;
    } else {
	icsz = 11;
    }
/* Writing concatenation */
    i__1[0] = 20, a__1[0] = "SY: SUMMARY of PVT #";
    i__1[1] = itrim_(globch_1.pident, 40L), a__1[1] = globch_1.pident;
    i__1[2] = 3, a__1[2] = " : ";
    i__1[3] = 3, a__1[3] = aerrct;
    i__1[4] = isz, a__1[4] = err;
    i__1[5] = 18, a__1[5] = " detected, out of ";
    i__1[6] = 3, a__1[6] = atstct;
    i__1[7] = icsz, a__1[7] = cword;
    i__1[8] = 1, a__1[8] = ".";
    s_cat(ch__1, a__1, i__1, &c__9, 106L);
    brdmsg_(ch__1, itrim_(globch_1.pident, 40L) + 26 + isz + 21 + icsz + 1);
    if (globnu_1.unerr != 0) {
	s_wsfi(&io___91);
	do_fio(&c__1, (char *)&globnu_1.unerr, (ftnlen)sizeof(integer));
	e_wsfi();
	if (globnu_1.unerr == 1) {
	    isz = 6;
	} else {
	    isz = 7;
	}
/* Writing concatenation */
	i__2[0] = 16, a__2[0] = "SY: Encountered ";
	i__2[1] = 3, a__2[1] = aerrct;
	i__2[2] = 14, a__2[2] = " unanticipated";
	i__2[3] = isz, a__2[3] = err;
	i__2[4] = 1, a__2[4] = ".";
	s_cat(ch__2, a__2, i__2, &c__5, 41L);
	brdmsg_(ch__2, isz + 34);
    }
/*  Both pass and fail blank out tstmsg as a sign that they have processed
 */
/*  it, and so windup requires that it be blank upon entry. */
    if (s_cmp(globch_1.tstmsg, " ", 900L, 1L) != 0) {
	inmsg_("Non-blank tstmsg detected by WINDUP.  Program logic error.", 
		58L);
    }
/* Writing concatenation */
    i__3[0] = 34, a__3[0] = "SY: ------- End execution of PVT #";
    i__3[1] = 40, a__3[1] = globch_1.pident;
    s_cat(ch__3, a__3, i__3, &c__2, 74L);
    brdmsg_(ch__3, 74L);
    brdmsg_(".", 1L);
    brdmsg_(".", 1L);
    brdmsg_(".", 1L);
/* close error files */
    if (globnu_1.iflerr == 1 || globnu_1.iflerr == 3) {
/* close global file */
	cl__1.cerr = 0;
	cl__1.cunit = globnu_1.glblun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (globnu_1.iflerr == 2 || globnu_1.iflerr == 3) {
/* close individual error file */
	cl__1.cerr = 0;
	cl__1.cunit = globnu_1.indlun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* windup_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/set2d                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int set2d_(char *vals, integer *maxcol, integer *nocols, 
	integer *collen, integer *arr, ftnlen vals_len)
#else /* NO_PROTO */
/* Subroutine */ int set2d_(vals, maxcol, nocols, collen, arr, vals_len)
char *vals;
integer *maxcol, *nocols, *collen, *arr;
ftnlen vals_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer arr_dim1, arr_offset, i__1[2], i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_len(char *, ftnlen), s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer i_indx(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_len(), s_cmp();
    /* Subroutine */ int s_cat();
    integer i_indx();
#endif /* NO_PROTO */

    /* Local variables */
    static char wk[2000];
    static integer last;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer slpos;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */

/*  Set2d is used to initialize a ragged 2D array of integers, based */
/*  on an input string. */

/*  --- Input Parameter: */
/*  vals      : Input string, with integer values.  Values separated by */

/*              commas, array columns terminated by slashes. */
/*  maxcol    : Maximum column size = size of first dimension of 2D array.
 */
/*  --- Output parameters: */
/*  nocols    : Number of columns initialized */
/*  collen    : 1D array of lengths of each column */
/*  arr       : 2D array of integers */
/*  Syntax of vals: */
/*  vals         = column* */
/*  column       = col-values "/" */
/*  col-values   = " " | integer-list */
/*  integer-list = integer | integer "," integer-list */
    /* Parameter adjustments */
    arr_dim1 = *maxcol;
    arr_offset = arr_dim1 + 1;
    arr -= arr_offset;
    --collen;

    /* Function Body */
    if (i_len(vals, vals_len) > 1998) {
	unmsg_("String passed to SET2D exceeds length of work area.", 51L);
    }
/* no columns so far */
    *nocols = 0;
/* blank means no columns at all */
    if (s_cmp(vals, " ", vals_len, 1L) == 0) {
	return 0;
    }
/* check for terminating slash */
    last = itrim_(vals, vals_len);
    if (vals[last - 1] != '/') {
	unmsg_("String sent to set2d does not terminate with slash.", 51L);
    }
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = " ";
    i__1[1] = vals_len, a__1[1] = vals;
    s_cat(wk, a__1, i__1, &c__2, 2000L);
/* begin a new column */
L100:
    slpos = i_indx(wk, "/", 2000L, 1L);
/* put next column and its length in arrays */
    ++(*nocols);
    setvs_(wk, &arr[*nocols * arr_dim1 + 1], &collen[*nocols], slpos - 1);
    if (collen[*nocols] > *maxcol) {
/* Writing concatenation */
#ifndef NO_PROTO
	i__1[0] = 47, a__1[0] = "Column passed to set2d exceeds maximum leng"
		"th: ";
#else /* NO_PROTO */
	i__1[0] = 47, a__1[0] = "Column passed to set2d exceeds maximum leng\
th: ";
#endif /* NO_PROTO */
	i__1[1] = slpos - 1, a__1[1] = wk;
	s_cat(wk, a__1, i__1, &c__2, 2000L);
	unmsg_(wk, 2000L);
    }
/* delete encoded column - set up for next; ensure one blank */
    i__2 = slpos;
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = " ";
    i__1[1] = 2000 - i__2, a__1[1] = wk + i__2;
    s_cat(wk, a__1, i__1, &c__2, 2000L);
/* any more columns ? */
    if (s_cmp(wk, " ", 2000L, 1L) != 0) {
	goto L100;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* set2d_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/setis                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical setis_(integer *arr, char *st, ftnlen st_len)
#else /* NO_PROTO */
logical setis_(arr, st, st_len)
integer *arr;
char *st;
ftnlen st_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer wk[500], nsz;
#ifndef NO_PROTO
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int unmsg_(char *, ftnlen), setvs_(char *, 
	    integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern logical seteq_();
    extern /* Subroutine */ int unmsg_(), setvs_();
#endif /* NO_PROTO */

/*  setis compares the contents of the integer array ARR with the set */
/*  of integers encoded in the character string ST and returns .true. */
/*  iff the leading elements of ARR contain exactly those values *in */
/*  any order*.  ST contains integer-like strings separated by */
/*  commas, e.g. "3, +4, -5". */
/*  store ST values in WK array; NSZ is number of values */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    setvs_(st, wk, &nsz, st_len);
    if (nsz > 500) {
#ifndef NO_PROTO
	unmsg_("Number of values in string passed to SETIS exceeds size of w"
		"ork area.", 69L);
#else /* NO_PROTO */
	unmsg_("Number of values in string passed to SETIS exceeds size of w\
ork area.", 69L);
#endif /* NO_PROTO */
    }
/*  compare the two arrays */
    ret_val = seteq_(&nsz, &arr[1], wk);
    return ret_val;
} /* setis_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/seteq                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical seteq_(integer *n, integer *a, integer *b)
#else /* NO_PROTO */
logical seteq_(n, a, b)
integer *n, *a, *b;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;
    logical ret_val;

    /* Local variables */
    static integer i, j, wk[5000];
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer wkleft;

/*  seteq compares the contents of the first N elements of two */
/*  arrays, A and B.  If they contain the same elements *in any */
/*  order*, seteq returns .true., else .false. */
    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
    if (*n > 5000) {
	unmsg_("Size of array passed to SETEQ exceeds size of work area.", 
		56L);
    }
/* save contents of B in WK, so as not to clobber B */
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
	wk[i - 1] = b[i];
/* L50: */
    }
    wkleft = *n;
/* check all elements of A */
    i__1 = *n;
    for (i = 1; i <= i__1; ++i) {
/* against remaining elements of WK */
	i__2 = wkleft;
	for (j = 1; j <= i__2; ++j) {
	    if (a[i] == wk[j - 1]) {
		wk[j - 1] = wk[wkleft - 1];
		--wkleft;
		goto L100;
	    }
/* L200: */
	}
	ret_val = FALSE_;
	return ret_val;
L100:
	;
    }
    ret_val = TRUE_;
    return ret_val;
} /* seteq_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/setval                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setval_(char *st, integer *arr, ftnlen st_len)
#else /* NO_PROTO */
/* Subroutine */ int setval_(st, arr, st_len)
char *st;
integer *arr;
ftnlen st_len;
#endif /* NO_PROTO */
{
    static integer nsz;
#ifndef NO_PROTO
    extern /* Subroutine */ int setvs_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setvs_();
#endif /* NO_PROTO */

/*  setval initializes the integer array ARR, based on the */
/*  value-representations in ST. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    setvs_(st, &arr[1], &nsz, st_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setval_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/setvs                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setvs_(char *st, integer *arr, integer *nsz, ftnlen 
	st_len)
#else /* NO_PROTO */
/* Subroutine */ int setvs_(st, arr, nsz, st_len)
char *st;
integer *arr, *nsz;
ftnlen st_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ierr;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), iniari_(char *, 
	    integer *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), iniari_();
#endif /* NO_PROTO */
    static char tmpmsg[300];

/*  SETVS initializes the integer array ARR, based on the */
/*  value-representations in ST and also returns the number */
/*  of values in NSZ.  SETVS is meant to be called to parse */
/*  strings generated directly by other PVT code, and thus */
/*  aborts on invalid strings.  To handle strings from operator, */
/*  use INIARI directly. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    iniari_(st, &arr[1], nsz, &ierr, st_len);
    if (ierr != 0) {
/* Writing concatenation */
	i__1[0] = 30, a__1[0] = "Invalid string sent to SETVS: ";
	i__1[1] = st_len, a__1[1] = st;
	s_cat(tmpmsg, a__1, i__1, &c__2, 300L);
	unmsg_(tmpmsg, 300L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setvs_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/iniari                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int iniari_(char *st, integer *arr, integer *nsz, integer *
	ierr, ftnlen st_len)
#else /* NO_PROTO */
/* Subroutine */ int iniari_(st, arr, nsz, ierr, st_len)
char *st;
integer *arr, *nsz, *ierr;
ftnlen st_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_indx();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer nc, lst, ival;
    static char stwk[700];
#ifndef NO_PROTO
    extern /* Subroutine */ int deblnk_(char *, char *, integer *, ftnlen, 
	    ftnlen), prsint_(char *, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int deblnk_(), prsint_();
#endif /* NO_PROTO */

/*  INIARI initializes the integer array ARR, based on the */
/*  value-representations in ST and also returns the number */
/*  of values in NSZ.  INIARI does not abort when faced with */
/*  an invalid string, just returns a non-zero error code in IERR. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    *nsz = 0;
    *ierr = 0;
/* blank means zero entries */
    if (s_cmp(st, " ", st_len, 1L) == 0) {
	return 0;
    }
/* get rid of leading, internal blanks */
    deblnk_(st, stwk, &lst, st_len, 700L);
/* L300: */
/* add trailing comma */
    ++lst;
    stwk[lst - 1] = ',';
/* now sitting at alleged number */
L400:
/* find next comma */
    nc = i_indx(stwk, ",", 700L, 1L);
    if (nc <= 1) {
	*ierr = 1;
	return 0;
    }
/* parse up to comma */
    prsint_(stwk, &ival, ierr, nc - 1);
    if (*ierr != 0) {
	*ierr += 100;
	return 0;
    }
/* add new entry to array */
    ++(*nsz);
    arr[*nsz] = ival;
/* delete thru comma */
    i__1 = nc;
    s_copy(stwk, stwk + i__1, 700L, 700 - i__1);
    if (s_cmp(stwk, " ", 700L, 1L) != 0) {
	goto L400;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* iniari_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/setrvs                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setrvs_(char *st, real *arr, integer *nsz, ftnlen st_len)

#else /* NO_PROTO */
/* Subroutine */ int setrvs_(st, arr, nsz, st_len)
char *st;
real *arr;
integer *nsz;
ftnlen st_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_indx();
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static integer nc, lst, ierr;
    static real rval;
    static char stwk[700];
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), prsrl_(char *, real *,
	     integer *, ftnlen), deblnk_(char *, char *, integer *, ftnlen, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), prsrl_(), deblnk_();
#endif /* NO_PROTO */
    static char tmpmsg[730];

/*  setrvs initializes the real array ARR, based on the */
/*  value-representations in ST and also returns the number */
/*  of values in NSZ. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    *nsz = 0;
/* blank means zero entries */
    if (s_cmp(st, " ", st_len, 1L) == 0) {
	return 0;
    }
/* get rid of leading, internal blanks */
    deblnk_(st, stwk, &lst, st_len, 700L);
/* L300: */
/* add trailing comma */
    ++lst;
    stwk[lst - 1] = ',';
/* now sitting at alleged number */
L400:
/* find next comma */
    nc = i_indx(stwk, ",", 700L, 1L);
    if (nc <= 1) {
	unmsg_("Adjacent commas passed to SETRVS.", 33L);
    }
/* parse up to comma */
    prsrl_(stwk, &rval, &ierr, nc - 1);
    if (ierr != 0) {
/* Writing concatenation */
	i__1[0] = 31, a__1[0] = "Invalid string sent to SETRVS: ";
	i__1[1] = st_len, a__1[1] = st;
	s_cat(tmpmsg, a__1, i__1, &c__2, 730L);
	unmsg_(tmpmsg, 730L);
    }
    ++(*nsz);
    arr[*nsz] = rval;
/* delete thru comma */
    i__2 = nc;
    s_copy(stwk, stwk + i__2, 700L, 700 - i__2);
    if (s_cmp(stwk, " ", 700L, 1L) != 0) {
	goto L400;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setrvs_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/iareq                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical iareq_(integer *size, integer *act, integer *exp__)
#else /* NO_PROTO */
logical iareq_(size, act, exp__)
integer *size, *act, *exp__;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix;

/*  General purpose routine for equality of two integer arrays. */
/*  ------- Input parameters: */
/*  size    : Number of elements to be compared */
/*  act     : actual values */
/*  exp     : expected values */
/*  This will handle multi-dimensional arrays according to the usual */
/*  Fortran rules for overlaying arrays. */
    /* Parameter adjustments */
    --exp__;
    --act;

    /* Function Body */
    i__1 = *size;
    for (ix = 1; ix <= i__1; ++ix) {
	if (act[ix] != exp__[ix]) {
	    ret_val = FALSE_;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* iareq_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/iareql                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical iareql_(integer *sizea, integer *arra, integer *sizeb, integer *arrb)
#else /* NO_PROTO */
logical iareql_(sizea, arra, sizeb, arrb)
integer *sizea, *arra, *sizeb, *arrb;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
#ifndef NO_PROTO
    extern logical iareq_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern logical iareq_();
#endif /* NO_PROTO */

/*  General purpose routine for equality of two variable-length */
/*  integer lists. */
/*  ------- Input parameters: */
/*  sizea   : size of first list */
/*  arra    : contents of first list */
/*  sizeb   : size of second list */
/*  arrb    : contents of second list */
/*  This will handle multi-dimensional arrays according to the usual */
/*  Fortran rules for overlaying arrays. */
    /* Parameter adjustments */
    --arrb;
    --arra;

    /* Function Body */
    if (*sizea == *sizeb) {
	ret_val = iareq_(sizea, &arra[1], &arrb[1]);
    } else {
	ret_val = FALSE_;
    }
    return ret_val;
} /* iareql_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/rareq                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical rareq_(integer *size, real *act, real *exp__, real *abserr, real *
	relerr)
#else /* NO_PROTO */
logical rareq_(size, act, exp__, abserr, relerr)
integer *size;
real *act, *exp__, *abserr, *relerr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */

/*  General purpose routine for approximate equality of two real arrays. 
*/
/*  ------- Input parameters: */
/*  size    : Number of elements to be compared */
/*  act     : actual values */
/*  exp     : expected values */
/*  abserr  : absolute tolerance */
/*  relerr  : relative tolerance */
/*  This will handle multi-dimensional arrays according to the usual */
/*  Fortran rules for overlaying arrays. */
    /* Parameter adjustments */
    --exp__;
    --act;

    /* Function Body */
    i__1 = *size;
    for (ix = 1; ix <= i__1; ++ix) {
	if (appeq_(&act[ix], &exp__[ix], abserr, relerr)) {
/* OK so far */
	} else {
	    ret_val = FALSE_;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* rareq_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/appeq                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical appeq_(real *act, real *exp__, real *abserr, real *relerr)
#else /* NO_PROTO */
logical appeq_(act, exp__, abserr, relerr)
real *act, *exp__, *abserr, *relerr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;
    logical ret_val;

    /* Local variables */
    static real abdif;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/*  General purpose routine for approximate equality of two real-numbers. 
*/
/*  The 1st parameter is the actual value, the 2nd, the expected value. */

/*  Tests as true iff: */
/*     1. absolute error of act wrt exp .le. abserr, OR */
/*     2. relative error of act wrt exp .le. relerr */
#ifndef NO_PROTO
    if (*abserr < 0.f || *relerr < 0.f) {
#else /* NO_PROTO */
    if (*abserr < (float)0. || *relerr < (float)0.) {
#endif /* NO_PROTO */
	unmsg_("Negative tolerance passed to APPEQ.", 35L);
    }
    abdif = (r__1 = *act - *exp__, dabs(r__1));
/* note that this expression is "safe" even if act or exp is zero. */
    ret_val = abdif <= *abserr || abdif <= (r__1 = *relerr * *exp__, dabs(
	    r__1));
    return ret_val;
} /* appeq_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION GL/iarfnd                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
integer iarfnd_(integer *key, integer *arsiz, integer *iarr)
#else /* NO_PROTO */
integer iarfnd_(key, arsiz, iarr)
integer *key, *arsiz, *iarr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val, i__1;

    /* Local variables */
    static integer ix;

/*  IARFND searches the first ARSIZ entries within IARR, and returns */
/*  the first location equal to KEY. If not found, 0 is returned. */
    /* Parameter adjustments */
    --iarr;

    /* Function Body */
    i__1 = *arsiz;
    for (ix = 1; ix <= i__1; ++ix) {
	if (iarr[ix] == *key) {
	    ret_val = ix;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = 0;
    return ret_val;
} /* iarfnd_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/cpyiar                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int cpyiar_(integer *size, real *from, real *to)
#else /* NO_PROTO */
/* Subroutine */ int cpyiar_(size, from, to)
integer *size;
real *from, *to;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i;

/*  CPYIAR copies the contents of an array of a given size to */
/*  another array. */
/*  Input parameters: */
/*    SIZE : number of elements to copy */
/*    TO   : source array */
/*  Output parameter: */
/*    FROM : destination array */
    /* Parameter adjustments */
    --to;
    --from;

    /* Function Body */
    i__1 = *size;
    for (i = 1; i <= i__1; ++i) {
	to[i] = from[i];
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* cpyiar_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/srtiar                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int srtiar_(integer *siz, integer *arr)
#else /* NO_PROTO */
/* Subroutine */ int srtiar_(siz, arr)
integer *siz, *arr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i, j, tmp;

/*  SRTIAR sorts an integer array in place, into ascending order. */

/*  Input parameter: */
/*    SIZ : number of elements in array to be sorted. */
/*  Input/output parameter: */
/*    ARR : the array of integers to be sorted. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    i__1 = *siz - 1;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *siz;
	for (j = i + 1; j <= i__2; ++j) {
	    if (arr[i] > arr[j]) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	    }
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* srtiar_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/srtrar                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int srtrar_(integer *siz, real *arr)
#else /* NO_PROTO */
/* Subroutine */ int srtrar_(siz, arr)
integer *siz;
real *arr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i, j;
    static real tmp;

/*  SRTRAR sorts a real array in place, into ascending order. */

/*  Input parameter: */
/*    SIZ : number of elements in array to be sorted. */
/*  Input/output parameter: */
/*    ARR : the array of integers to be sorted. */
    /* Parameter adjustments */
    --arr;

    /* Function Body */
    i__1 = *siz - 1;
    for (i = 1; i <= i__1; ++i) {
	i__2 = *siz;
	for (j = i + 1; j <= i__2; ++j) {
	    if (arr[i] > arr[j]) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	    }
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* srtrar_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/prsint                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int prsint_(char *str, integer *ival, integer *ierr, ftnlen 
	str_len)
#else /* NO_PROTO */
/* Subroutine */ int prsint_(str, ival, ierr, str_len)
char *str;
integer *ival, *ierr;
ftnlen str_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen);
#else /* NO_PROTO */
    integer i_indx(), i_len();
#endif /* NO_PROTO */

    /* Local variables */
    static integer lst, isign;
#ifndef NO_PROTO
    extern /* Subroutine */ int prsuin_(char *, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    extern /* Subroutine */ int prsuin_();
#endif /* NO_PROTO */

/*  Prsint parses a possibly signed integer.  Assumes no leading spaces. 
*/
/*  The value is returned in IVAL, and IERR gets a non-zero code if */
/*  something goes wrong. */
    isign = i_indx("+-", str, 2L, 1L);
    lst = i_len(str, str_len);
    if (isign == 0) {
/* unsigned */
	prsuin_(str, ival, ierr, str_len);
    } else {
/* signed */
	if (lst <= 1) {
/* no digits */
	    *ierr = 50;
	} else {
	    prsuin_(str + 1, ival, ierr, str_len - 1);
	    if (isign == 2) {
		*ival = -(*ival);
	    }
	}
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* prsint_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/prsuin                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int prsuin_(char *str, integer *ival, integer *ierr, ftnlen 
	str_len)
#else /* NO_PROTO */
/* Subroutine */ int prsuin_(str, ival, ierr, str_len)
char *str;
integer *ival, *ierr;
ftnlen str_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_indx();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i, lst, idig, itot;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */

/*  Prsuin parses an unsigned integer.  Assumes no leading spaces. */
/*  The value is returned in IVAL, and IERR gets a non-zero code if */
/*  something goes wrong. */
    lst = itrim_(str, str_len);
    if (lst <= 0) {
	*ierr = 2;
	return 0;
    }
    itot = 0;
    i__1 = lst;
    for (i = 1; i <= i__1; ++i) {
	idig = i_indx("0123456789", str + (i - 1), 10L, 1L) - 1;
	if (idig >= 0 && idig <= 9) {
	    itot = itot * 10 + idig;
	} else {
	    *ierr = 1;
	    return 0;
	}
/* L100: */
    }
    *ierr = 0;
    *ival = itot;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* prsuin_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/prsrl                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int prsrl_(char *str, real *rval, integer *ierr, ftnlen 
	str_len)
#else /* NO_PROTO */
/* Subroutine */ int prsrl_(str, rval, ierr, str_len)
char *str;
real *rval;
integer *ierr;
ftnlen str_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2], a__2[3];
    integer i__1[2], i__2[3];

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(void)
	    ;
#else /* NO_PROTO */
    integer i_indx();
    /* Subroutine */ int s_cat(), s_copy();
    integer s_rsfi(), do_fio(), e_rsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static char wstr[18];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer szstr, posdec, posexp;

    /* Fortran I/O blocks */
    static icilist io___135 = { 1, wstr, 1, "(F18.2)", 18, 1 };


/*  Prsrl parses a real number.  Assumes no leading spaces. */
/*  The value is returned in RVAL, and IERR gets a non-zero code */
/*  if something goes wrong. */
    szstr = itrim_(str, str_len);
#ifndef NO_PROTO
    *rval = -666.666f;
#else /* NO_PROTO */
    *rval = (float)-666.666;
#endif /* NO_PROTO */
    if (szstr > 15) {
	*ierr = -3;
	return 0;
    }
    posdec = i_indx(str, ".", str_len, 1L);
    if (posdec <= 0) {
/* No explicit decimal */
	posexp = i_indx(str, "E", str_len, 1L);
	if (posexp <= 0) {
/* No explicit exponent */
/* Writing concatenation */
	    i__1[0] = szstr, a__1[0] = str;
	    i__1[1] = 2, a__1[1] = ".0";
	    s_cat(wstr, a__1, i__1, &c__2, 18L);
	} else {
/* Writing concatenation */
	    i__2[0] = posexp - 1, a__2[0] = str;
	    i__2[1] = 2, a__2[1] = ".0";
	    i__2[2] = szstr - (posexp - 1), a__2[2] = str + (posexp - 1);
	    s_cat(wstr, a__2, i__2, &c__3, 18L);
	}
	szstr += 2;
    } else {
/* Explicit decimal */
	s_copy(wstr, str, 18L, str_len);
    }
    *ierr = s_rsfi(&io___135);
    if (*ierr != 0) {
	goto L100009;
    }
    *ierr = do_fio(&c__1, (char *)&(*rval), (ftnlen)sizeof(real));
    if (*ierr != 0) {
	goto L100009;
    }
    *ierr = e_rsfi();
L100009:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* prsrl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/ncmsg                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ncmsg_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int ncmsg_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int abend_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int abend_();
#endif /* NO_PROTO */

/* NCMSG is used to generate messages for unanticipated errors */
/* which imply non-conformance of the implementation under test. */
/* It then forces a program abort. */
    abend_("NC", msg, 2L, msg_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ncmsg_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/unmsg                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int unmsg_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int unmsg_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int abend_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int abend_();
#endif /* NO_PROTO */

/* UNMSG is used to generate messages for unanticipated errors */
/* which do not imply non-conformance of the implementation under test. */

/* It then forces a program abort. */
    abend_("UN", msg, 2L, msg_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* unmsg_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/inmsg                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int inmsg_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int inmsg_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static char buf[900];
#ifndef NO_PROTO
    extern /* Subroutine */ int brdmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int brdmsg_();
#endif /* NO_PROTO */

/* INMSG is used to generate informational messages. */
/* Writing concatenation */
    i__1[0] = 4, a__1[0] = "IN: ";
    i__1[1] = msg_len, a__1[1] = msg;
    s_cat(buf, a__1, i__1, &c__2, 900L);
    brdmsg_(buf, 900L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* inmsg_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/abend                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int abend_(char *svrty, char *msg, ftnlen svrty_len, ftnlen 
	msg_len)
#else /* NO_PROTO */
/* Subroutine */ int abend_(svrty, msg, svrty_len, msg_len)
char *svrty, *msg;
ftnlen svrty_len;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3], a__2[2];
    integer i__1[3], i__2[2];
    char ch__1[46];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    integer s_cmp();
    /* Subroutine */ int s_copy(), s_stop();
#endif /* NO_PROTO */

    /* Local variables */
    static char buf[900];
#ifndef NO_PROTO
    extern /* Subroutine */ int neclph (void), brdmsg_(char *, ftnlen), 
	    windup_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int neclph (), brdmsg_(), windup_();
#endif /* NO_PROTO */

/* Abend handles program-aborting messages. */
    ++globnu_1.unerr;
/* Writing concatenation */
    i__1[0] = 2, a__1[0] = svrty;
    i__1[1] = 18, a__1[1] = ": Program ABORT.  ";
    i__1[2] = msg_len, a__1[2] = msg;
    s_cat(buf, a__1, i__1, &c__3, 900L);
    brdmsg_(buf, 900L);
    if (s_cmp(svrty, "UN", 2L, 2L) != 0 && s_cmp(svrty, "NC", 2L, 2L) != 0) {
	++globnu_1.unerr;
/* Writing concatenation */
	i__2[0] = 44, a__2[0] = "UN: unknown severity code passed to abend = "
		;
	i__2[1] = 2, a__2[1] = svrty;
	s_cat(ch__1, a__2, i__2, &c__2, 46L);
	brdmsg_(ch__1, 46L);
    }
/* wrap it up - emergency close */
    neclph ();
/* blank out tstmsg to prevent spurious informational message from windup 
*/
    s_copy(globch_1.tstmsg, " ", 900L, 1L);
/* kill program */
    windup_();
    s_stop("", 0L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* abend_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/brdmsg                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int brdmsg_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int brdmsg_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_800[] = "(a)";

    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat(), s_copy();
    integer s_wsfe(), do_fio(), e_wsfe(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ib;
    static char buf[999];
    static integer isp;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int opmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int opmsg_();
#endif /* NO_PROTO */
    static char msglin[300];
    static integer lstlin;

    /* Fortran I/O blocks */
    static cilist io___143 = { 0, 0, 0, fmt_800, 0 };
    static cilist io___144 = { 0, 0, 0, fmt_800, 0 };


/* Brdmsg broadcasts a message to various destinations.  It uses */
/* variables in common to control how it issues the message passed to it. 
*/
/* leading space is as Fortran carriage control character. */
/* Writing concatenation */
    i__1[0] = 1, a__1[0] = " ";
    i__1[1] = msg_len, a__1[1] = msg;
    s_cat(buf, a__1, i__1, &c__2, 999L);
/*  This loop breaks up msg into chunks of size .le. maxlin.  It also */
/* puts 5 spaces to the start of each non-first line, so that message-type
*/
/*  will stand out. */
L100:
    for (ib = globnu_1.maxlin + 1; ib >= 1; --ib) {
	if (buf[ib - 1] == ' ') {
	    isp = ib;
	    goto L210;
	}
/* L200: */
    }
    isp = globnu_1.maxlin;
L210:
/* isp now points to a line-breaking space. */
    s_copy(msglin, buf, 300L, isp - 1);
    lstlin = itrim_(msglin, 300L);
/* ensure *at least* 5 spaces in start of buf. */
    i__2 = isp;
/* Writing concatenation */
    i__1[0] = 5, a__1[0] = "     ";
    i__1[1] = 999 - i__2, a__1[1] = buf + i__2;
    s_cat(buf, a__1, i__1, &c__2, 999L);
/* Message to operator */
    if (globnu_1.errsw == 1) {
	opmsg_(msglin, lstlin);
    }
/* L800: */
/* Message to files */
    if (globnu_1.iflerr == 1 || globnu_1.iflerr == 3) {
/* append to global file */
	io___143.ciunit = globnu_1.glblun;
	s_wsfe(&io___143);
	do_fio(&c__1, msglin, lstlin);
	e_wsfe();
    }
    if (globnu_1.iflerr == 2 || globnu_1.iflerr == 3) {
/* add to individual file */
	io___144.ciunit = globnu_1.indlun;
	s_wsfe(&io___144);
	do_fio(&c__1, msglin, lstlin);
	e_wsfe();
    }
/* any more non-blanks to send out?  If not, quit. */
    if (s_cmp(buf, " ", 999L, 1L) == 0) {
	goto L666;
    }
/* ensure *exactly* 5 leading blanks */
L300:
    if (buf[5] != ' ') {
	goto L100;
    }
    s_copy(buf, buf + 1, 999L, 998L);
    goto L300;
L666:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* brdmsg_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/opmsg                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int opmsg_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int opmsg_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(void);
#else /* NO_PROTO */
    integer s_cmp(), s_wsle(), do_lio(), e_wsle();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, iy, nxt, mlen, lastb;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static cilist io___145 = { 0, 6, 0, 0, 0 };
    static cilist io___148 = { 0, 6, 0, 0, 0 };
    static cilist io___152 = { 0, 6, 0, 0, 0 };


/*  OPMSG writes out a message to the operator.  No assumptions are */
/*  made that a workstation is open. */
    if (s_cmp(msg, " ", msg_len, 1L) == 0) {
	s_wsle(&io___145);
	do_lio(&c__9, &c__1, " ", 1L);
	e_wsle();
	return 0;
    }
/*  set IX,LASTB to start, end of substring to be printed */
    ix = 1;
    mlen = itrim_(msg, msg_len);
L100:
    if (mlen - ix < globnu_1.maxlin) {
	s_wsle(&io___148);
	do_lio(&c__9, &c__1, msg + (ix - 1), mlen - (ix - 1));
	e_wsle();
	return 0;
    }
    i__1 = ix;
    for (iy = ix + globnu_1.maxlin; iy >= i__1; --iy) {
	if (msg[iy - 1] == ' ') {
	    lastb = iy;
	    nxt = lastb + 1;
	    goto L210;
	}
/* L200: */
    }
    lastb = ix + globnu_1.maxlin;
    nxt = lastb;
L210:
    s_wsle(&io___152);
    do_lio(&c__9, &c__1, msg + (ix - 1), lastb - 1 - (ix - 1));
    e_wsle();
    ix = nxt;
    goto L100;
} /* opmsg_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/opyn                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int opyn_(char *prompt, char *ans, ftnlen prompt_len, ftnlen 
	ans_len)
#else /* NO_PROTO */
/* Subroutine */ int opyn_(prompt, ans, prompt_len, ans_len)
char *prompt, *ans;
ftnlen prompt_len;
ftnlen ans_len;
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_800[] = "(a)";

    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);

#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    integer s_rsfe(), do_fio(), e_rsfe();
#endif /* NO_PROTO */

    /* Local variables */
    static char buf[132];
#ifndef NO_PROTO
    extern /* Subroutine */ int opmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opmsg_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static cilist io___154 = { 0, 5, 0, fmt_800, 0 };


/* opyn gets a yes or no reply from operator - encoded as y or n. */
/* L800: */
L100:
/* Writing concatenation */
    i__1[0] = prompt_len, a__1[0] = prompt;
    i__1[1] = 9, a__1[1] = " (y or n)";
    s_cat(buf, a__1, i__1, &c__2, 132L);
    opmsg_(buf, 132L);
    s_rsfe(&io___154);
    do_fio(&c__1, ans, 1L);
    e_rsfe();
    if (*ans == 'y' || *ans == 'n') {
	return 0;
    }
    opmsg_("Response must be y or n.", 24L);
    goto L100;
} /* opyn_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/opint                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int opint_(integer *ians)
#else /* NO_PROTO */
/* Subroutine */ int opint_(ians)
integer *ians;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static char cans[40];
    static integer ierr;
#ifndef NO_PROTO
    extern /* Subroutine */ int oplin_(char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int opmsg_(char *, ftnlen);
    extern integer leadnb_(char *, ftnlen);
    extern /* Subroutine */ int prsint_(char *, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    extern /* Subroutine */ int oplin_();
    extern integer itrim_();
    extern /* Subroutine */ int opmsg_();
    extern integer leadnb_();
    extern /* Subroutine */ int prsint_();
#endif /* NO_PROTO */

/*  OPINT gets an integer response from the operator. */
L10:
    oplin_(cans, 40L);
    if (s_cmp(cans, " ", 40L, 1L) == 0) {
	opmsg_("Response must be a non-blank valid integer.  Re-enter.", 54L);

	goto L10;
    }
    i__1 = leadnb_(cans, 40L) - 1;
    prsint_(cans + i__1, ians, &ierr, itrim_(cans, 40L) - i__1);
    if (ierr != 0) {
	opmsg_("Response must be a non-blank valid integer.  Re-enter.", 54L);

	goto L10;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opint_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/oplin                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int oplin_(char *ans, ftnlen ans_len)
#else /* NO_PROTO */
/* Subroutine */ int oplin_(ans, ans_len)
char *ans;
ftnlen ans_len;
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_800[] = "(a)";

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);

#else /* NO_PROTO */
    integer s_rsfe(), do_fio(), e_rsfe();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static cilist io___157 = { 0, 5, 0, fmt_800, 0 };


/*  OPLIN gets a single-line response from the operator. */
    s_rsfe(&io___157);
    do_fio(&c__1, ans, ans_len);
    e_rsfe();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* oplin_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/deblnk                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int deblnk_(char *strin, char *strout, integer *newsiz, 
	ftnlen strin_len, ftnlen strout_len)
#else /* NO_PROTO */
/* Subroutine */ int deblnk_(strin, strout, newsiz, strin_len, strout_len)
char *strin, *strout;
integer *newsiz;
ftnlen strin_len;
ftnlen strout_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_len(char *, ftnlen), i_indx(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer i_len(), i_indx();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, recv, nbloc, nblen;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */

/*  deblnk accepts a string (strin) and generates from it another */
/*  string (strout) with all leading and internal blanks deleted. It */
/*  also returns the new size of the compressed string as newsiz, */
/*  which points to the last non-blank (0 if all blank). */
    s_copy(strout, " ", strout_len, 1L);
    nbloc = 0;
    nblen = 1;
    recv = 1;
L100:
/* get next sending non-blank */
    i__1 = i_len(strin, strin_len);
    for (ix = nbloc + nblen; ix <= i__1; ++ix) {
	if (strin[ix - 1] != ' ') {
	    nbloc = ix;
	    goto L210;
	}
/* L200: */
    }
/* no more non-blanks */
    goto L300;
/* send next non-blank field */
L210:
    s_copy(strout + (recv - 1), strin + (nbloc - 1), strout_len - (recv - 1), 
	    strin_len - (nbloc - 1));
/* more blanks to compress out? */
    nblen = i_indx(strin + (nbloc - 1), " ", strin_len - (nbloc - 1), 1L) - 1;

    if (nblen == -1) {
/*        all done */
    } else {
/* set recv */
	recv += nblen;
	goto L100;
    }
L300:
    *newsiz = itrim_(strout, strout_len);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* deblnk_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION GL/leadnb                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
integer leadnb_(char *txt, ftnlen txt_len)
#else /* NO_PROTO */
integer leadnb_(txt, txt_len)
char *txt;
ftnlen txt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_len();
#endif /* NO_PROTO */

    /* Local variables */
    static integer hi, lo, mid;

/*  LEADNB returns the character position of the first (leftmost) */
/*  non-blank character within TXT.  If there is none, 0 is returned. */
    if (s_cmp(txt, " ", txt_len, 1L) == 0) {
	ret_val = 0;
	return ret_val;
    }
/*  LO always points to a location *before* the first non-blank, */
/*  HI to a location *at or after* the first non-blank. */
    lo = 0;
    hi = i_len(txt, txt_len);
L100:
    if (hi - lo <= 1) {
	goto L666;
    }
    mid = (hi + lo) / 2;
    if (s_cmp(txt, " ", mid, 1L) == 0) {
	lo = mid;
    } else {
	hi = mid;
    }
    goto L100;
L666:
    ret_val = hi;
    return ret_val;
} /* leadnb_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION GL/itrim                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
integer itrim_(char *word, ftnlen word_len)
#else /* NO_PROTO */
integer itrim_(word, word_len)
char *word;
ftnlen word_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_len(char *, ftnlen), s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer i_len(), s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer lw, ihi, ilo, imid;

/* itrim returns the position of the rightmost non-blank within */
/* a string, zero if all blank. */
    lw = i_len(word, word_len);
    ilo = 0;
    ihi = lw + 1;
/* do binary search looking for trailing blank portion of word */
L100:
    if (ihi - ilo <= 1) {
	goto L666;
    }
    imid = (ihi + ilo) / 2;
    if (s_cmp(word + (imid - 1), " ", word_len - (imid - 1), 1L) == 0) {
	ihi = imid;
    } else {
	ilo = imid;
    }
    goto L100;
L666:
    ret_val = ilo;
    return ret_val;
} /* itrim_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/errctl                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int errctl_(logical *locctl)
#else /* NO_PROTO */
/* Subroutine */ int errctl_(locctl)
logical *locctl;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

/*  Errctl is called by test programs to control whether or not perhnd */
/*  should handle signalled errors and abort (locctl = .false.) or rather 
*/
/*  should simply return error information (locctl = .true.) in the */
/*  COMMON variables errsig and funcid. */
/* Should there be local control over signalled errors? */
    if (*locctl) {
	globnu_1.ctlhnd = 1;
	globnu_1.errsig = 0;
	s_copy(globch_1.funcid, " ", 80L, 1L);
    } else {
	globnu_1.ctlhnd = 0;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* errctl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/sigtst                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int sigtst_(integer *expsig, logical *failed)
#else /* NO_PROTO */
/* Subroutine */ int sigtst_(expsig, failed)
integer *expsig;
logical *failed;
#endif /* NO_PROTO */
{
    static char msg[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), pass_(void), inmsg_(char *, 
	    ftnlen), sigmsg_(integer *, char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_(), inmsg_(), sigmsg_();
#endif /* NO_PROTO */

/*  Sigtst is used to compare an signalled error code with an expected */
/*  value.  If not equal, failure and informative messages are generated, 
*/
/*  including the error code and function name.  If equal, pass is */
/*  invoked. */
/*  Input parameter: */
/*    EXPSIG : expected value of error code (usually 0) */
/*  Output parameter */
/*    FAILED : true if expected not equal to actual, else false */
    if (*expsig == globnu_1.errsig) {
	*failed = FALSE_;
	pass_();
    } else {
	*failed = TRUE_;
	fail_();
	sigmsg_(&globnu_1.errsig, globch_1.funcid, msg, 80L, 300L);
	inmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* sigtst_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/sigmsg                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int sigmsg_(integer *perrsg, char *funcnm, char *msg, ftnlen 
	funcnm_len, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int sigmsg_(perrsg, funcnm, msg, funcnm_len, msg_len)
integer *perrsg;
char *funcnm, *msg;
ftnlen funcnm_len;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3], a__2[5];
    integer i__1[3], i__2[5];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi(), s_cmp();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static char errch[6];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___171 = { 0, errch, 0, "(I6)", 6, 1 };


/*  SIGMSG formulates a message indicating that the function named by */
/*  funcnm signalled the error code perrsg. */
/*  Input parameters: */
/*    PERRSG : Error code to be incorporated in MSG */
/*    FUNCNM : Name of erroneous function to be incorporated in MSG */
/*  Output parameters: */
/*    MSG    : Resulting descriptive message */
    s_wsfi(&io___171);
    do_fio(&c__1, (char *)&(*perrsg), (ftnlen)sizeof(integer));
    e_wsfi();
    if (s_cmp(funcnm, " ", funcnm_len, 1L) == 0) {
/* Writing concatenation */
	i__1[0] = 41, a__1[0] = "No error signalled; current error code = ";
	i__1[1] = 6, a__1[1] = errch;
	i__1[2] = 1, a__1[2] = ".";
	s_cat(msg, a__1, i__1, &c__3, msg_len);
    } else {
/* Writing concatenation */
	i__2[0] = 9, a__2[0] = "Function ";
	i__2[1] = itrim_(funcnm, funcnm_len), a__2[1] = funcnm;
	i__2[2] = 22, a__2[2] = " signalled error code ";
	i__2[3] = 6, a__2[3] = errch;
	i__2[4] = 1, a__2[4] = ".";
	s_cat(msg, a__2, i__2, &c__5, msg_len);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* sigmsg_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/erfucd                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int erfucd_(char *funnam, integer *funccd, ftnlen funnam_len)

#else /* NO_PROTO */
/* Subroutine */ int erfucd_(funnam, funccd, funnam_len)
char *funnam;
integer *funccd;
ftnlen funnam_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_indx();
    /* Subroutine */ int s_copy(), s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, iy;
    static char wnam[100];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen), leadnb_(char *, ftnlen);
    extern /* Subroutine */ int erfunm_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_(), leadnb_();
    extern /* Subroutine */ int erfunm_();
#endif /* NO_PROTO */
    static char trunam[100];

/*  ERFUCD accepts a character string identifying a generic function */
/*  and returns the standard function code. */

/*  Input parameter: */
/*    FUNNAM : generic name of function */
/*  Output parameter: */
/*    FUNCCD : integer code for offending function */
    *funccd = -1;
    if (s_cmp(funnam, " ", funnam_len, 1L) == 0) {
	return 0;
    }
/*  check whether already enclosed in angle brackets */
    ix = i_indx(funnam, "<", funnam_len, 1L);
    if (ix > 0) {
	s_copy(wnam, funnam + (ix - 1), 100L, funnam_len - (ix - 1));
    } else {
	ix = leadnb_(funnam, funnam_len);
	iy = itrim_(funnam, funnam_len);
/* Writing concatenation */
	i__1[0] = 1, a__1[0] = "<";
	i__1[1] = iy - (ix - 1), a__1[1] = funnam + (ix - 1);
	i__1[2] = 1, a__1[2] = ">";
	s_cat(wnam, a__1, i__1, &c__3, 100L);
    }
/*  WNAM now has canonical function name */
    for (iy = 0; iy <= 182; ++iy) {
	erfunm_(&iy, trunam, 100L);
	if (s_cmp(wnam, trunam, 100L, 100L) == 0) {
	    *funccd = iy;
	    return 0;
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* erfucd_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/erfunm                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int erfunm_(integer *funccd, char *funnam, ftnlen funnam_len)

#else /* NO_PROTO */
/* Subroutine */ int erfunm_(funccd, funnam, funnam_len)
integer *funccd;
char *funnam;
ftnlen funnam_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

#ifndef NO_PROTO
    static char funtab[45*183] = "<open phigs>                              "
	    "   " "<close phigs>                                " "<open work"
	    "station>                           " "<close workstation>       "
	    "                   " "<redraw all structures>                   "
	    "   " "<update workstation>                         " "<set displ"
	    "ay update state>                   " "<message>                 "
	    "                   " "<polyline 3>                              "
	    "   " "<polyline>                                   " "<polymarke"
	    "r 3>                               " "<polymarker>              "
	    "                   " "<text 3>                                  "
	    "   " "<text>                                       " "<annotatio"
	    "n text relative 3>                 " "<annotation text relative>"
	    "                   " "<fill area 3>                             "
	    "   " "<fill area>                                  " "<fill area"
	    " set 3>                            " "<fill area set>           "
	    "                   " "<cell array 3>                            "
	    "   " "<cell array>                                 " "<generaliz"
	    "ed drawing primitive 3>            " "<generalized drawing primi"
	    "tive>              " "<set polyline index>                      "
	    "   " "<set polymarker index>                       " "<set text "
	    "index>                             " "<set interior index>      "
	    "                   " "<set edge index>                          "
	    "   " "<set linetype>                               " "<set linew"
	    "idth scale factor>                 " "<set polyline colour index"
	    ">                  " "<set marker type>                         "
	    "   " "<set marker size scale factor>               " "<set polym"
	    "arker colour index>                " "<set text font>           "
	    "                   " "<set text precision>                      "
	    "   " "<set character expansion factor>             " "<set chara"
	    "cter spacing>                      " "<set text colour index>   "
	    "                   " "<set character height>                    "
	    "   " "<set character up vector>                    " "<set text "
	    "path>                              " "<set text alignment>      "
	    "                   " "<set annotation text character height>    "
	    "   " "<set annotation text character up vector>    " "<set annot"
	    "ation text path>                   " "<set annotation text align"
	    "ment>              " "<set annotation style>                    "
	    "   " "<set interior style>                         " "<set inter"
	    "ior style index>                   " "<set interior colour index"
	    ">                  " "<set edge flag>                           "
	    "   " "<set edgetype>                               " "<set edgew"
	    "idth scale factor>                 " "<set edge colour index>   "
	    "                   " "<set pattern size>                        "
	    "   " "<set pattern reference point and vectors>    " "<set patte"
	    "rn reference point>                " "<add names to set>        "
	    "                   " "<remove names from set>                   "
	    "   " "<set individual asf>                         " "<set polyl"
	    "ine representation>                " "<set polymarker representa"
	    "tion>              " "<set text representation>                 "
	    "   " "<set interior representation>                " "<set edge "
	    "representation>                    " "<set pattern representatio"
	    "n>                 " "<set colour representation>               "
	    "   " "<set highlighting filter>                    " "<set invis"
	    "ibility filter>                    " "<set colour model>        "
	    "                   " "<set hlhsr identifier>                    "
	    "   " "<set hlhsr mode>                             " "<set local"
	    " transformation 3>                 " "<set local transformation>"
	    "                   " "<set global transformation 3>             "
	    "   " "<set global transformation>                  " "<set model"
	    "ling clipping volume 3>            " "<set modelling clipping vo"
	    "lume>              " "<set modelling clipping indicator>        "
	    "   " "<restore modelling clipping volume>          " "<set view "
	    "index>                             " "<set view representation 3"
	    ">                  " "<set view representation>                 "
	    "   " "<set view transformation input priority>     " "<set works"
	    "tation window 3>                   " "<set workstation window>  "
	    "                   " "<set workstation viewport 3>              "
	    "   " "<set workstation viewport>                   " "<open stru"
	    "cture>                             " "<close structure>         "
	    "                   " "<execute structure>                       "
	    "   " "<label>                                      " "<applicati"
	    "on data>                           " "<generalized structure ele"
	    "ment>              " "<set edit mode>                           "
	    "   " "<copy all elements from structure>           " "<set eleme"
	    "nt pointer>                        " "<offset element pointer>  "
	    "                   " "<set element pointer at label>            "
	    "   " "<delete element>                             " "<delete el"
	    "ement range>                       " "<delete elements between l"
	    "abels>             " "<empty structure>                         "
	    "   " "<delete structure>                           " "<delete st"
	    "ructure network>                   " "<delete all structures>   "
	    "                   " "<change structure identifier>             "
	    "   " "<change structure references>                " "<change st"
	    "ructure identifier and references> " "<post structure>          "
	    "                   " "<unpost structure>                        "
	    "   " "<unpost all structures>                      " "<open arch"
	    "ive file>                          " "<close archive file>      "
	    "                   " "<archive structures>                      "
	    "   " "<archive structure networks>                 " "<archive a"
	    "ll structures>                     " "<set conflict resolution> "
	    "                   " "<retrieve structure identifiers>          "
	    "   " "<retrieve structures>                        " "<retrieve "
	    "structure networks>                " "<retrieve all structures> "
	    "                   " "<retrieve paths to ancestors>             "
	    "   " "<retrieve paths to descendants>              " "<delete st"
	    "ructures from archive>             " "<delete structure networks"
	    " from archive>     " "<delete all structures from archive>      "
	    "   " "<set pick identifier>                        " "<set pick "
	    "filter>                            " "<initialize locator 3>    "
	    "                   " "<initialize locator>                      "
	    "   " "<initialize stroke 3>                        " "<initializ"
	    "e stroke>                          " "<initialize valuator 3>   "
	    "                   " "<initialize valuator>                     "
	    "   " "<initialize choice 3>                        " "<initializ"
	    "e choice>                          " "<initialize pick 3>       "
	    "                   " "<initialize pick>                         "
	    "   " "<initialize string 3>                        " "<initializ"
	    "e string>                          " "<set locator mode>        "
	    "                   " "<set stroke mode>                         "
	    "   " "<set valuator mode>                          " "<set choic"
	    "e mode>                            " "<set pick mode>           "
	    "                   " "<set string mode>                         "
	    "   " "<request locator 3>                          " "<request l"
	    "ocator>                            " "<request stroke 3>        "
	    "                   " "<request stroke>                          "
	    "   " "<request valuator>                           " "<request c"
	    "hoice>                             " "<request pick>            "
	    "                   " "<request string>                          "
	    "   " "<sample locator 3>                           " "<sample lo"
	    "cator>                             " "<sample stroke 3>         "
	    "                   " "<sample stroke>                           "
	    "   " "<sample valuator>                            " "<sample ch"
	    "oice>                              " "<sample pick>             "
	    "                   " "<sample string>                           "
	    "   " "<await event>                                " "<flush dev"
	    "ice events>                        " "<get locator 3>           "
	    "                   " "<get locator>                             "
	    "   " "<get stroke 3>                               " "<get strok"
	    "e>                                 " "<get valuator>            "
	    "                   " "<get choice>                              "
	    "   " "<get pick>                                   " "<get strin"
	    "g>                                 " "<write item to metafile>  "
	    "                   " "<get item type from metafile>             "
	    "   " "<read item from metafile>                    " "<interpret"
	    " item>                             " "<set error handling mode> "
	    "                   " "<escape>                                  "
	    "   " "<pack data record>                           " "<unpack da"
	    "ta record>                         ";
#else /* NO_PROTO */
    static char funtab[45*183+1] = "<open phigs>                            \
     <close phigs>                                <open workstation>        \
                   <close workstation>                          <redraw all \
structures>                      <update workstation>                       \
  <set display update state>                   <message>                    \
                <polyline 3>                                 <polyline>     \
                              <polymarker 3>                               <\
polymarker>                                 <text 3>                        \
             <text>                                       <annotation text r\
elative 3>                 <annotation text relative>                   <fil\
l area 3>                                <fill area>                        \
          <fill area set 3>                            <fill area set>      \
                        <cell array 3>                               <cell a\
rray>                                 <generalized drawing primitive 3>     \
       <generalized drawing primitive>              <set polyline index>    \
                     <set polymarker index>                       <set text \
index>                             <set interior index>                     \
    <set edge index>                             <set linetype>             \
                  <set linewidth scale factor>                 <set polyline\
 colour index>                  <set marker type>                           \
 <set marker size scale factor>               <set polymarker colour index> \
               <set text font>                              <set text precis\
ion>                         <set character expansion factor>             <s\
et character spacing>                      <set text colour index>          \
            <set character height>                       <set character up v\
ector>                    <set text path>                              <set \
text alignment>                         <set annotation text character heigh\
t>       <set annotation text character up vector>    <set annotation text p\
ath>                   <set annotation text alignment>              <set ann\
otation style>                       <set interior style>                   \
      <set interior style index>                   <set interior colour inde\
x>                  <set edge flag>                              <set edgety\
pe>                               <set edgewidth scale factor>              \
   <set edge colour index>                      <set pattern size>          \
                 <set pattern reference point and vectors>    <set pattern r\
eference point>                <add names to set>                           \
<remove names from set>                      <set individual asf>           \
              <set polyline representation>                <set polymarker r\
epresentation>              <set text representation>                    <se\
t interior representation>                <set edge representation>         \
           <set pattern representation>                 <set colour represen\
tation>                  <set highlighting filter>                    <set i\
nvisibility filter>                    <set colour model>                   \
        <set hlhsr identifier>                       <set hlhsr mode>       \
                      <set local transformation 3>                 <set loca\
l transformation>                   <set global transformation 3>           \
     <set global transformation>                  <set modelling clipping vo\
lume 3>            <set modelling clipping volume>              <set modelli\
ng clipping indicator>           <restore modelling clipping volume>        \
  <set view index>                             <set view representation 3>  \
                <set view representation>                    <set view trans\
formation input priority>     <set workstation window 3>                   <\
set workstation window>                     <set workstation viewport 3>    \
             <set workstation viewport>                   <open structure>  \
                           <close structure>                            <exe\
cute structure>                          <label>                            \
          <application data>                           <generalized structur\
e element>              <set edit mode>                              <copy a\
ll elements from structure>           <set element pointer>                 \
       <offset element pointer>                     <set element pointer at \
label>               <delete element>                             <delete el\
ement range>                       <delete elements between labels>         \
    <empty structure>                            <delete structure>         \
                  <delete structure network>                   <delete all s\
tructures>                      <change structure identifier>               \
 <change structure references>                <change structure identifier a\
nd references> <post structure>                             <unpost structur\
e>                           <unpost all structures>                      <o\
pen archive file>                          <close archive file>             \
            <archive structures>                         <archive structure \
networks>                 <archive all structures>                     <set \
conflict resolution>                    <retrieve structure identifiers>    \
         <retrieve structures>                        <retrieve structure ne\
tworks>                <retrieve all structures>                    <retriev\
e paths to ancestors>                <retrieve paths to descendants>        \
      <delete structures from archive>             <delete structure network\
s from archive>     <delete all structures from archive>         <set pick i\
dentifier>                        <set pick filter>                         \
   <initialize locator 3>                       <initialize locator>        \
                 <initialize stroke 3>                        <initialize st\
roke>                          <initialize valuator 3>                      \
<initialize valuator>                        <initialize choice 3>          \
              <initialize choice>                          <initialize pick \
3>                          <initialize pick>                            <in\
itialize string 3>                        <initialize string>               \
           <set locator mode>                           <set stroke mode>   \
                         <set valuator mode>                          <set c\
hoice mode>                            <set pick mode>                      \
        <set string mode>                            <request locator 3>    \
                      <request locator>                            <request \
stroke 3>                           <request stroke>                        \
     <request valuator>                           <request choice>          \
                   <request pick>                               <request str\
ing>                             <sample locator 3>                         \
  <sample locator>                             <sample stroke 3>            \
                <sample stroke>                              <sample valuato\
r>                            <sample choice>                              <\
sample pick>                                <sample string>                 \
             <await event>                                <flush device even\
ts>                        <get locator 3>                              <get\
 locator>                                <get stroke 3>                     \
          <get stroke>                                 <get valuator>       \
                        <get choice>                                 <get pi\
ck>                                   <get string>                          \
       <write item to metafile>                     <get item type from meta\
file>                <read item from metafile>                    <interpret\
 item>                             <set error handling mode>                \
    <escape>                                     <pack data record>         \
                  <unpack data record>                         ";
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/* ERFUNM accepts an integer identifying a function and returns the generi
c*/
/* name of the function.  These are the "official" function codes from the
*/
/*  standard Fortran binding.  Only functions that generate errors are */
/*  encoded. */

/*  Input parameter: */
/*    FUNCCD : integer code for offending function */
/*  Output parameter: */
/*    FUNNAM : generic name of function */
    if (*funccd >= 0 && *funccd <= 182) {
	s_copy(funnam, funtab + *funccd * 45, funnam_len, 45L);
    } else {
	unmsg_("ERFUNM called with invalid value.", 33L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* erfunm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/nfunm                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int nfunm_(integer *funccd, char *funnam, ftnlen funnam_len)
#else /* NO_PROTO */
/* Subroutine */ int nfunm_(funccd, funnam, funnam_len)
integer *funccd;
char *funnam;
ftnlen funnam_len;
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
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/* NFUNM accepts an integer identifying a function and returns the generic
*/
/*  name of the function.  These are the codes used by the PVT system, as 
*/
/*  documented in sys-dict.prt and used in the #F entries of DOC.PRT. */
/*  Input parameter: */
/*    FUNCCD : integer code for function */
/*  Output parameter: */
/*    FUNNAM : generic name of function */
    if (*funccd < 1 || *funccd > 324) {
	unmsg_("NFUNM called with invalid value.", 32L);
    }
    if (*funccd <= 100) {
	goto L9000;
    }
    if (*funccd <= 200) {
	goto L9100;
    }
    if (*funccd <= 300) {
	goto L9200;
    }
    goto L9300;
L9000:
#ifndef NO_PROTO
    switch (*funccd) {
#else /* NO_PROTO */
    switch ((int)*funccd) {
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
	case 100:  goto L100;
    }
L9100:
#ifndef NO_PROTO
    switch (*funccd - 100) {
#else /* NO_PROTO */
    switch ((int)(*funccd - 100)) {
#endif /* NO_PROTO */
	case 1:  goto L101;
	case 2:  goto L102;
	case 3:  goto L103;
	case 4:  goto L104;
	case 5:  goto L105;
	case 6:  goto L106;
	case 7:  goto L107;
	case 8:  goto L108;
	case 9:  goto L109;
	case 10:  goto L110;
	case 11:  goto L111;
	case 12:  goto L112;
	case 13:  goto L113;
	case 14:  goto L114;
	case 15:  goto L115;
	case 16:  goto L116;
	case 17:  goto L117;
	case 18:  goto L118;
	case 19:  goto L119;
	case 20:  goto L120;
	case 21:  goto L121;
	case 22:  goto L122;
	case 23:  goto L123;
	case 24:  goto L124;
	case 25:  goto L125;
	case 26:  goto L126;
	case 27:  goto L127;
	case 28:  goto L128;
	case 29:  goto L129;
	case 30:  goto L130;
	case 31:  goto L131;
	case 32:  goto L132;
	case 33:  goto L133;
	case 34:  goto L134;
	case 35:  goto L135;
	case 36:  goto L136;
	case 37:  goto L137;
	case 38:  goto L138;
	case 39:  goto L139;
	case 40:  goto L140;
	case 41:  goto L141;
	case 42:  goto L142;
	case 43:  goto L143;
	case 44:  goto L144;
	case 45:  goto L145;
	case 46:  goto L146;
	case 47:  goto L147;
	case 48:  goto L148;
	case 49:  goto L149;
	case 50:  goto L150;
	case 51:  goto L151;
	case 52:  goto L152;
	case 53:  goto L153;
	case 54:  goto L154;
	case 55:  goto L155;
	case 56:  goto L156;
	case 57:  goto L157;
	case 58:  goto L158;
	case 59:  goto L159;
	case 60:  goto L160;
	case 61:  goto L161;
	case 62:  goto L162;
	case 63:  goto L163;
	case 64:  goto L164;
	case 65:  goto L165;
	case 66:  goto L166;
	case 67:  goto L167;
	case 68:  goto L168;
	case 69:  goto L169;
	case 70:  goto L170;
	case 71:  goto L171;
	case 72:  goto L172;
	case 73:  goto L173;
	case 74:  goto L174;
	case 75:  goto L175;
	case 76:  goto L176;
	case 77:  goto L177;
	case 78:  goto L178;
	case 79:  goto L179;
	case 80:  goto L180;
	case 81:  goto L181;
	case 82:  goto L182;
	case 83:  goto L183;
	case 84:  goto L184;
	case 85:  goto L185;
	case 86:  goto L186;
	case 87:  goto L187;
	case 88:  goto L188;
	case 89:  goto L189;
	case 90:  goto L190;
	case 91:  goto L191;
	case 92:  goto L192;
	case 93:  goto L193;
	case 94:  goto L194;
	case 95:  goto L195;
	case 96:  goto L196;
	case 97:  goto L197;
	case 98:  goto L198;
	case 99:  goto L199;
	case 100:  goto L200;
    }
L9200:
#ifndef NO_PROTO
    switch (*funccd - 200) {
#else /* NO_PROTO */
    switch ((int)(*funccd - 200)) {
#endif /* NO_PROTO */
	case 1:  goto L201;
	case 2:  goto L202;
	case 3:  goto L203;
	case 4:  goto L204;
	case 5:  goto L205;
	case 6:  goto L206;
	case 7:  goto L207;
	case 8:  goto L208;
	case 9:  goto L209;
	case 10:  goto L210;
	case 11:  goto L211;
	case 12:  goto L212;
	case 13:  goto L213;
	case 14:  goto L214;
	case 15:  goto L215;
	case 16:  goto L216;
	case 17:  goto L217;
	case 18:  goto L218;
	case 19:  goto L219;
	case 20:  goto L220;
	case 21:  goto L221;
	case 22:  goto L222;
	case 23:  goto L223;
	case 24:  goto L224;
	case 25:  goto L225;
	case 26:  goto L226;
	case 27:  goto L227;
	case 28:  goto L228;
	case 29:  goto L229;
	case 30:  goto L230;
	case 31:  goto L231;
	case 32:  goto L232;
	case 33:  goto L233;
	case 34:  goto L234;
	case 35:  goto L235;
	case 36:  goto L236;
	case 37:  goto L237;
	case 38:  goto L238;
	case 39:  goto L239;
	case 40:  goto L240;
	case 41:  goto L241;
	case 42:  goto L242;
	case 43:  goto L243;
	case 44:  goto L244;
	case 45:  goto L245;
	case 46:  goto L246;
	case 47:  goto L247;
	case 48:  goto L248;
	case 49:  goto L249;
	case 50:  goto L250;
	case 51:  goto L251;
	case 52:  goto L252;
	case 53:  goto L253;
	case 54:  goto L254;
	case 55:  goto L255;
	case 56:  goto L256;
	case 57:  goto L257;
	case 58:  goto L258;
	case 59:  goto L259;
	case 60:  goto L260;
	case 61:  goto L261;
	case 62:  goto L262;
	case 63:  goto L263;
	case 64:  goto L264;
	case 65:  goto L265;
	case 66:  goto L266;
	case 67:  goto L267;
	case 68:  goto L268;
	case 69:  goto L269;
	case 70:  goto L270;
	case 71:  goto L271;
	case 72:  goto L272;
	case 73:  goto L273;
	case 74:  goto L274;
	case 75:  goto L275;
	case 76:  goto L276;
	case 77:  goto L277;
	case 78:  goto L278;
	case 79:  goto L279;
	case 80:  goto L280;
	case 81:  goto L281;
	case 82:  goto L282;
	case 83:  goto L283;
	case 84:  goto L284;
	case 85:  goto L285;
	case 86:  goto L286;
	case 87:  goto L287;
	case 88:  goto L288;
	case 89:  goto L289;
	case 90:  goto L290;
	case 91:  goto L291;
	case 92:  goto L292;
	case 93:  goto L293;
	case 94:  goto L294;
	case 95:  goto L295;
	case 96:  goto L296;
	case 97:  goto L297;
	case 98:  goto L298;
	case 99:  goto L299;
	case 100:  goto L300;
    }
L9300:
#ifndef NO_PROTO
    switch (*funccd - 300) {
#else /* NO_PROTO */
    switch ((int)(*funccd - 300)) {
#endif /* NO_PROTO */
	case 1:  goto L301;
	case 2:  goto L302;
	case 3:  goto L303;
	case 4:  goto L304;
	case 5:  goto L305;
	case 6:  goto L306;
	case 7:  goto L307;
	case 8:  goto L308;
	case 9:  goto L309;
	case 10:  goto L310;
	case 11:  goto L311;
	case 12:  goto L312;
	case 13:  goto L313;
	case 14:  goto L314;
	case 15:  goto L315;
	case 16:  goto L316;
	case 17:  goto L317;
	case 18:  goto L318;
	case 19:  goto L319;
	case 20:  goto L320;
	case 21:  goto L321;
	case 22:  goto L322;
	case 23:  goto L323;
	case 24:  goto L324;
    }
L1:
    s_copy(funnam, "<open phigs>", funnam_len, 12L);
    return 0;
L2:
    s_copy(funnam, "<close phigs>", funnam_len, 13L);
    return 0;
L3:
    s_copy(funnam, "<open workstation>", funnam_len, 18L);
    return 0;
L4:
    s_copy(funnam, "<close workstation>", funnam_len, 19L);
    return 0;
L5:
    s_copy(funnam, "<redraw all structures>", funnam_len, 23L);
    return 0;
L6:
    s_copy(funnam, "<update workstation>", funnam_len, 20L);
    return 0;
L7:
    s_copy(funnam, "<set display update state>", funnam_len, 26L);
    return 0;
L8:
    s_copy(funnam, "<message>", funnam_len, 9L);
    return 0;
L9:
    s_copy(funnam, "<polyline 3>", funnam_len, 12L);
    return 0;
L10:
    s_copy(funnam, "<polyline>", funnam_len, 10L);
    return 0;
L11:
    s_copy(funnam, "<polymarker 3>", funnam_len, 14L);
    return 0;
L12:
    s_copy(funnam, "<polymarker>", funnam_len, 12L);
    return 0;
L13:
    s_copy(funnam, "<text 3>", funnam_len, 8L);
    return 0;
L14:
    s_copy(funnam, "<text>", funnam_len, 6L);
    return 0;
L15:
    s_copy(funnam, "<annotation text relative 3>", funnam_len, 28L);
    return 0;
L16:
    s_copy(funnam, "<annotation text relative>", funnam_len, 26L);
    return 0;
L17:
    s_copy(funnam, "<fill area 3>", funnam_len, 13L);
    return 0;
L18:
    s_copy(funnam, "<fill area>", funnam_len, 11L);
    return 0;
L19:
    s_copy(funnam, "<fill area set 3>", funnam_len, 17L);
    return 0;
L20:
    s_copy(funnam, "<fill area set>", funnam_len, 15L);
    return 0;
L21:
    s_copy(funnam, "<cell array 3>", funnam_len, 14L);
    return 0;
L22:
    s_copy(funnam, "<cell array>", funnam_len, 12L);
    return 0;
L23:
    s_copy(funnam, "<generalized drawing primitive 3>", funnam_len, 33L);
    return 0;
L24:
    s_copy(funnam, "<generalized drawing primitive>", funnam_len, 31L);
    return 0;
L25:
    s_copy(funnam, "<set polyline index>", funnam_len, 20L);
    return 0;
L26:
    s_copy(funnam, "<set polymarker index>", funnam_len, 22L);
    return 0;
L27:
    s_copy(funnam, "<set text index>", funnam_len, 16L);
    return 0;
L28:
    s_copy(funnam, "<set interior index>", funnam_len, 20L);
    return 0;
L29:
    s_copy(funnam, "<set edge index>", funnam_len, 16L);
    return 0;
L30:
    s_copy(funnam, "<set linetype>", funnam_len, 14L);
    return 0;
L31:
    s_copy(funnam, "<set linewidth scale factor>", funnam_len, 28L);
    return 0;
L32:
    s_copy(funnam, "<set polyline colour index>", funnam_len, 27L);
    return 0;
L33:
    s_copy(funnam, "<set marker type>", funnam_len, 17L);
    return 0;
L34:
    s_copy(funnam, "<set marker size scale factor>", funnam_len, 30L);
    return 0;
L35:
    s_copy(funnam, "<set polymarker colour index>", funnam_len, 29L);
    return 0;
L36:
    s_copy(funnam, "<set text font>", funnam_len, 15L);
    return 0;
L37:
    s_copy(funnam, "<set text precision>", funnam_len, 20L);
    return 0;
L38:
    s_copy(funnam, "<set character expansion factor>", funnam_len, 32L);
    return 0;
L39:
    s_copy(funnam, "<set character spacing>", funnam_len, 23L);
    return 0;
L40:
    s_copy(funnam, "<set text colour index>", funnam_len, 23L);
    return 0;
L41:
    s_copy(funnam, "<set character height>", funnam_len, 22L);
    return 0;
L42:
    s_copy(funnam, "<set character up vector>", funnam_len, 25L);
    return 0;
L43:
    s_copy(funnam, "<set text path>", funnam_len, 15L);
    return 0;
L44:
    s_copy(funnam, "<set text alignment>", funnam_len, 20L);
    return 0;
L45:
    s_copy(funnam, "<set annotation text character height>", funnam_len, 38L);

    return 0;
L46:
    s_copy(funnam, "<set annotation text character up vector>", funnam_len, 
	    41L);
    return 0;
L47:
    s_copy(funnam, "<set annotation text path>", funnam_len, 26L);
    return 0;
L48:
    s_copy(funnam, "<set annotation text alignment>", funnam_len, 31L);
    return 0;
L49:
    s_copy(funnam, "<set annotation style>", funnam_len, 22L);
    return 0;
L50:
    s_copy(funnam, "<set interior style>", funnam_len, 20L);
    return 0;
L51:
    s_copy(funnam, "<set interior style index>", funnam_len, 26L);
    return 0;
L52:
    s_copy(funnam, "<set interior colour index>", funnam_len, 27L);
    return 0;
L53:
    s_copy(funnam, "<set edge flag>", funnam_len, 15L);
    return 0;
L54:
    s_copy(funnam, "<set edgetype>", funnam_len, 14L);
    return 0;
L55:
    s_copy(funnam, "<set edgewidth scale factor>", funnam_len, 28L);
    return 0;
L56:
    s_copy(funnam, "<set edge colour index>", funnam_len, 23L);
    return 0;
L57:
    s_copy(funnam, "<set pattern size>", funnam_len, 18L);
    return 0;
L58:
    s_copy(funnam, "<set pattern reference point and vectors>", funnam_len, 
	    41L);
    return 0;
L59:
    s_copy(funnam, "<set pattern reference point>", funnam_len, 29L);
    return 0;
L60:
    s_copy(funnam, "<add names to set>", funnam_len, 18L);
    return 0;
L61:
    s_copy(funnam, "<remove names from set>", funnam_len, 23L);
    return 0;
L62:
    s_copy(funnam, "<set individual asf>", funnam_len, 20L);
    return 0;
L63:
    s_copy(funnam, "<set polyline representation>", funnam_len, 29L);
    return 0;
L64:
    s_copy(funnam, "<set polymarker representation>", funnam_len, 31L);
    return 0;
L65:
    s_copy(funnam, "<set text representation>", funnam_len, 25L);
    return 0;
L66:
    s_copy(funnam, "<set interior representation>", funnam_len, 29L);
    return 0;
L67:
    s_copy(funnam, "<set edge representation>", funnam_len, 25L);
    return 0;
L68:
    s_copy(funnam, "<set pattern representation>", funnam_len, 28L);
    return 0;
L69:
    s_copy(funnam, "<set colour representation>", funnam_len, 27L);
    return 0;
L70:
    s_copy(funnam, "<set highlighting filter>", funnam_len, 25L);
    return 0;
L71:
    s_copy(funnam, "<set invisibility filter>", funnam_len, 25L);
    return 0;
L72:
    s_copy(funnam, "<set colour model>", funnam_len, 18L);
    return 0;
L73:
    s_copy(funnam, "<set hlhsr identifier>", funnam_len, 22L);
    return 0;
L74:
    s_copy(funnam, "<set hlhsr mode>", funnam_len, 16L);
    return 0;
L75:
    s_copy(funnam, "<set local transformation 3>", funnam_len, 28L);
    return 0;
L76:
    s_copy(funnam, "<set local transformation>", funnam_len, 26L);
    return 0;
L77:
    s_copy(funnam, "<set global transformation 3>", funnam_len, 29L);
    return 0;
L78:
    s_copy(funnam, "<set global transformation>", funnam_len, 27L);
    return 0;
L79:
    s_copy(funnam, "<set modelling clipping volume 3>", funnam_len, 33L);
    return 0;
L80:
    s_copy(funnam, "<set modelling clipping volume>", funnam_len, 31L);
    return 0;
L81:
    s_copy(funnam, "<set modelling clipping indicator>", funnam_len, 34L);
    return 0;
L82:
    s_copy(funnam, "<restore modelling clipping volume>", funnam_len, 35L);
    return 0;
L83:
    s_copy(funnam, "<set view index>", funnam_len, 16L);
    return 0;
L84:
    s_copy(funnam, "<set view representation 3>", funnam_len, 27L);
    return 0;
L85:
    s_copy(funnam, "<set view representation>", funnam_len, 25L);
    return 0;
L86:
    s_copy(funnam, "<set view transformation input priority>", funnam_len, 
	    40L);
    return 0;
L87:
    s_copy(funnam, "<set workstation window 3>", funnam_len, 26L);
    return 0;
L88:
    s_copy(funnam, "<set workstation window>", funnam_len, 24L);
    return 0;
L89:
    s_copy(funnam, "<set workstation viewport 3>", funnam_len, 28L);
    return 0;
L90:
    s_copy(funnam, "<set workstation viewport>", funnam_len, 26L);
    return 0;
L91:
    s_copy(funnam, "<translate 3>", funnam_len, 13L);
    return 0;
L92:
    s_copy(funnam, "<translate>", funnam_len, 11L);
    return 0;
L93:
    s_copy(funnam, "<scale 3>", funnam_len, 9L);
    return 0;
L94:
    s_copy(funnam, "<scale>", funnam_len, 7L);
    return 0;
L95:
    s_copy(funnam, "<rotate x>", funnam_len, 10L);
    return 0;
L96:
    s_copy(funnam, "<rotate y>", funnam_len, 10L);
    return 0;
L97:
    s_copy(funnam, "<rotate z>", funnam_len, 10L);
    return 0;
L98:
    s_copy(funnam, "<rotate>", funnam_len, 8L);
    return 0;
L99:
    s_copy(funnam, "<compose matrix 3>", funnam_len, 18L);
    return 0;
L100:
    s_copy(funnam, "<compose matrix>", funnam_len, 16L);
    return 0;
L101:
    s_copy(funnam, "<transform point 3>", funnam_len, 19L);
    return 0;
L102:
    s_copy(funnam, "<transform point>", funnam_len, 17L);
    return 0;
L103:
    s_copy(funnam, "<build transformation matrix 3>", funnam_len, 31L);
    return 0;
L104:
    s_copy(funnam, "<build transformation matrix>", funnam_len, 29L);
    return 0;
L105:
    s_copy(funnam, "<compose transformation matrix 3>", funnam_len, 33L);
    return 0;
L106:
    s_copy(funnam, "<compose transformation matrix>", funnam_len, 31L);
    return 0;
L107:
    s_copy(funnam, "<evaluate view orientation matrix 3>", funnam_len, 36L);
    return 0;
L108:
    s_copy(funnam, "<evaluate view orientation matrix>", funnam_len, 34L);
    return 0;
L109:
    s_copy(funnam, "<evaluate view mapping matrix 3>", funnam_len, 32L);
    return 0;
L110:
    s_copy(funnam, "<evaluate view mapping matrix>", funnam_len, 30L);
    return 0;
L111:
    s_copy(funnam, "<open structure>", funnam_len, 16L);
    return 0;
L112:
    s_copy(funnam, "<close structure>", funnam_len, 17L);
    return 0;
L113:
    s_copy(funnam, "<execute structure>", funnam_len, 19L);
    return 0;
L114:
    s_copy(funnam, "<label>", funnam_len, 7L);
    return 0;
L115:
    s_copy(funnam, "<application data>", funnam_len, 18L);
    return 0;
L116:
    s_copy(funnam, "<generalized structure element>", funnam_len, 31L);
    return 0;
L117:
    s_copy(funnam, "<set edit mode>", funnam_len, 15L);
    return 0;
L118:
    s_copy(funnam, "<copy all elements from structure>", funnam_len, 34L);
    return 0;
L119:
    s_copy(funnam, "<set element pointer>", funnam_len, 21L);
    return 0;
L120:
    s_copy(funnam, "<offset element pointer>", funnam_len, 24L);
    return 0;
L121:
    s_copy(funnam, "<set element pointer at label>", funnam_len, 30L);
    return 0;
L122:
    s_copy(funnam, "<delete element>", funnam_len, 16L);
    return 0;
L123:
    s_copy(funnam, "<delete element range>", funnam_len, 22L);
    return 0;
L124:
    s_copy(funnam, "<delete elements between labels>", funnam_len, 32L);
    return 0;
L125:
    s_copy(funnam, "<empty structure>", funnam_len, 17L);
    return 0;
L126:
    s_copy(funnam, "<delete structure>", funnam_len, 18L);
    return 0;
L127:
    s_copy(funnam, "<delete structure network>", funnam_len, 26L);
    return 0;
L128:
    s_copy(funnam, "<delete all structures>", funnam_len, 23L);
    return 0;
L129:
    s_copy(funnam, "<change structure identifier>", funnam_len, 29L);
    return 0;
L130:
    s_copy(funnam, "<change structure references>", funnam_len, 29L);
    return 0;
L131:
    s_copy(funnam, "<change structure identifier and references>", funnam_len,
	     44L);
    return 0;
L132:
    s_copy(funnam, "<post structure>", funnam_len, 16L);
    return 0;
L133:
    s_copy(funnam, "<unpost structure>", funnam_len, 18L);
    return 0;
L134:
    s_copy(funnam, "<unpost all structures>", funnam_len, 23L);
    return 0;
L135:
    s_copy(funnam, "<open archive file>", funnam_len, 19L);
    return 0;
L136:
    s_copy(funnam, "<close archive file>", funnam_len, 20L);
    return 0;
L137:
    s_copy(funnam, "<archive structures>", funnam_len, 20L);
    return 0;
L138:
    s_copy(funnam, "<archive structure networks>", funnam_len, 28L);
    return 0;
L139:
    s_copy(funnam, "<archive all structures>", funnam_len, 24L);
    return 0;
L140:
    s_copy(funnam, "<set conflict resolution>", funnam_len, 25L);
    return 0;
L141:
    s_copy(funnam, "<retrieve structure identifiers>", funnam_len, 32L);
    return 0;
L142:
    s_copy(funnam, "<retrieve structures>", funnam_len, 21L);
    return 0;
L143:
    s_copy(funnam, "<retrieve structure networks>", funnam_len, 29L);
    return 0;
L144:
    s_copy(funnam, "<retrieve all structures>", funnam_len, 25L);
    return 0;
L145:
    s_copy(funnam, "<retrieve paths to ancestors>", funnam_len, 29L);
    return 0;
L146:
    s_copy(funnam, "<retrieve paths to descendants>", funnam_len, 31L);
    return 0;
L147:
    s_copy(funnam, "<delete structures from archive>", funnam_len, 32L);
    return 0;
L148:
    s_copy(funnam, "<delete structure networks from archive>", funnam_len, 
	    40L);
    return 0;
L149:
    s_copy(funnam, "<delete all structures from archive>", funnam_len, 36L);
    return 0;
L150:
    s_copy(funnam, "<set pick identifier>", funnam_len, 21L);
    return 0;
L151:
    s_copy(funnam, "<set pick filter>", funnam_len, 17L);
    return 0;
L152:
    s_copy(funnam, "<initialize locator 3>", funnam_len, 22L);
    return 0;
L153:
    s_copy(funnam, "<initialize locator>", funnam_len, 20L);
    return 0;
L154:
    s_copy(funnam, "<initialize stroke 3>", funnam_len, 21L);
    return 0;
L155:
    s_copy(funnam, "<initialize stroke>", funnam_len, 19L);
    return 0;
L156:
    s_copy(funnam, "<initialize valuator 3>", funnam_len, 23L);
    return 0;
L157:
    s_copy(funnam, "<initialize valuator>", funnam_len, 21L);
    return 0;
L158:
    s_copy(funnam, "<initialize choice 3>", funnam_len, 21L);
    return 0;
L159:
    s_copy(funnam, "<initialize choice>", funnam_len, 19L);
    return 0;
L160:
    s_copy(funnam, "<initialize pick 3>", funnam_len, 19L);
    return 0;
L161:
    s_copy(funnam, "<initialize pick>", funnam_len, 17L);
    return 0;
L162:
    s_copy(funnam, "<initialize string 3>", funnam_len, 21L);
    return 0;
L163:
    s_copy(funnam, "<initialize string>", funnam_len, 19L);
    return 0;
L164:
    s_copy(funnam, "<set locator mode>", funnam_len, 18L);
    return 0;
L165:
    s_copy(funnam, "<set stroke mode>", funnam_len, 17L);
    return 0;
L166:
    s_copy(funnam, "<set valuator mode>", funnam_len, 19L);
    return 0;
L167:
    s_copy(funnam, "<set choice mode>", funnam_len, 17L);
    return 0;
L168:
    s_copy(funnam, "<set pick mode>", funnam_len, 15L);
    return 0;
L169:
    s_copy(funnam, "<set string mode>", funnam_len, 17L);
    return 0;
L170:
    s_copy(funnam, "<request locator 3>", funnam_len, 19L);
    return 0;
L171:
    s_copy(funnam, "<request locator>", funnam_len, 17L);
    return 0;
L172:
    s_copy(funnam, "<request stroke 3>", funnam_len, 18L);
    return 0;
L173:
    s_copy(funnam, "<request stroke>", funnam_len, 16L);
    return 0;
L174:
    s_copy(funnam, "<request valuator>", funnam_len, 18L);
    return 0;
L175:
    s_copy(funnam, "<request choice>", funnam_len, 16L);
    return 0;
L176:
    s_copy(funnam, "<request pick>", funnam_len, 14L);
    return 0;
L177:
    s_copy(funnam, "<request string>", funnam_len, 16L);
    return 0;
L178:
    s_copy(funnam, "<sample locator 3>", funnam_len, 18L);
    return 0;
L179:
    s_copy(funnam, "<sample locator>", funnam_len, 16L);
    return 0;
L180:
    s_copy(funnam, "<sample stroke 3>", funnam_len, 17L);
    return 0;
L181:
    s_copy(funnam, "<sample stroke>", funnam_len, 15L);
    return 0;
L182:
    s_copy(funnam, "<sample valuator>", funnam_len, 17L);
    return 0;
L183:
    s_copy(funnam, "<sample choice>", funnam_len, 15L);
    return 0;
L184:
    s_copy(funnam, "<sample pick>", funnam_len, 13L);
    return 0;
L185:
    s_copy(funnam, "<sample string>", funnam_len, 15L);
    return 0;
L186:
    s_copy(funnam, "<await event>", funnam_len, 13L);
    return 0;
L187:
    s_copy(funnam, "<flush device events>", funnam_len, 21L);
    return 0;
L188:
    s_copy(funnam, "<get locator 3>", funnam_len, 15L);
    return 0;
L189:
    s_copy(funnam, "<get locator>", funnam_len, 13L);
    return 0;
L190:
    s_copy(funnam, "<get stroke 3>", funnam_len, 14L);
    return 0;
L191:
    s_copy(funnam, "<get stroke>", funnam_len, 12L);
    return 0;
L192:
    s_copy(funnam, "<get valuator>", funnam_len, 14L);
    return 0;
L193:
    s_copy(funnam, "<get choice>", funnam_len, 12L);
    return 0;
L194:
    s_copy(funnam, "<get pick>", funnam_len, 10L);
    return 0;
L195:
    s_copy(funnam, "<get string>", funnam_len, 12L);
    return 0;
L196:
    s_copy(funnam, "<write item to metafile>", funnam_len, 24L);
    return 0;
L197:
    s_copy(funnam, "<get item type from metafile>", funnam_len, 29L);
    return 0;
L198:
    s_copy(funnam, "<read item from metafile>", funnam_len, 25L);
    return 0;
L199:
    s_copy(funnam, "<interpret item>", funnam_len, 16L);
    return 0;
L200:
    s_copy(funnam, "<inquire system state value>", funnam_len, 28L);
    return 0;
L201:
    s_copy(funnam, "<inquire workstation state value>", funnam_len, 33L);
    return 0;
L202:
    s_copy(funnam, "<inquire structure state value>", funnam_len, 31L);
    return 0;
L203:
    s_copy(funnam, "<inquire archive state value>", funnam_len, 29L);
    return 0;
L204:
    s_copy(funnam, "<inquire list of available workstation types>", 
	    funnam_len, 45L);
    return 0;
L205:
    s_copy(funnam, "<inquire phigs facilities>", funnam_len, 26L);
    return 0;
L206:
    s_copy(funnam, "<inquire generalized structure element facilities>", 
	    funnam_len, 50L);
    return 0;
L207:
    s_copy(funnam, "<inquire modelling clipping facilities>", funnam_len, 39L)
	    ;
    return 0;
L208:
    s_copy(funnam, "<inquire edit mode>", funnam_len, 19L);
    return 0;
L209:
    s_copy(funnam, "<inquire set of open workstations>", funnam_len, 34L);
    return 0;
L210:
    s_copy(funnam, "<inquire structure identifiers>", funnam_len, 31L);
    return 0;
L211:
    s_copy(funnam, "<inquire archive files>", funnam_len, 23L);
    return 0;
L212:
    s_copy(funnam, "<inquire conflict resolution>", funnam_len, 29L);
    return 0;
L213:
    s_copy(funnam, "<inquire all conflicting structures>", funnam_len, 36L);
    return 0;
L214:
    s_copy(funnam, "<inquire conflicting structures in network>", funnam_len, 
	    43L);
    return 0;
L215:
    s_copy(funnam, "<inquire more simultaneous events>", funnam_len, 34L);
    return 0;
L216:
    s_copy(funnam, "<inquire workstation connection and type>", funnam_len, 
	    41L);
    return 0;
L217:
    s_copy(funnam, "<inquire list of view indices>", funnam_len, 30L);
    return 0;
L218:
    s_copy(funnam, "<inquire view representation>", funnam_len, 29L);
    return 0;
L219:
    s_copy(funnam, "<inquire hlhsr mode>", funnam_len, 20L);
    return 0;
L220:
    s_copy(funnam, "<inquire posted structures>", funnam_len, 27L);
    return 0;
L221:
    s_copy(funnam, "<inquire display update state>", funnam_len, 30L);
    return 0;
L222:
    s_copy(funnam, "<inquire list of polyline indices>", funnam_len, 34L);
    return 0;
L223:
    s_copy(funnam, "<inquire polyline representation>", funnam_len, 33L);
    return 0;
L224:
    s_copy(funnam, "<inquire list of polymarker indices>", funnam_len, 36L);
    return 0;
L225:
    s_copy(funnam, "<inquire polymarker representation>", funnam_len, 35L);
    return 0;
L226:
    s_copy(funnam, "<inquire list of text indices>", funnam_len, 30L);
    return 0;
L227:
    s_copy(funnam, "<inquire text representation>", funnam_len, 29L);
    return 0;
L228:
    s_copy(funnam, "<inquire list of interior indices>", funnam_len, 34L);
    return 0;
L229:
    s_copy(funnam, "<inquire interior representation>", funnam_len, 33L);
    return 0;
L230:
    s_copy(funnam, "<inquire list of edge indices>", funnam_len, 30L);
    return 0;
L231:
    s_copy(funnam, "<inquire edge representation>", funnam_len, 29L);
    return 0;
L232:
    s_copy(funnam, "<inquire list of pattern indices>", funnam_len, 33L);
    return 0;
L233:
    s_copy(funnam, "<inquire pattern representation>", funnam_len, 32L);
    return 0;
L234:
    s_copy(funnam, "<inquire colour model>", funnam_len, 22L);
    return 0;
L235:
    s_copy(funnam, "<inquire list of colour indices>", funnam_len, 32L);
    return 0;
L236:
    s_copy(funnam, "<inquire colour representation>", funnam_len, 31L);
    return 0;
L237:
    s_copy(funnam, "<inquire highlighting filter>", funnam_len, 29L);
    return 0;
L238:
    s_copy(funnam, "<inquire invisibility filter>", funnam_len, 29L);
    return 0;
L239:
    s_copy(funnam, "<inquire workstation transformation 3>", funnam_len, 38L);

    return 0;
L240:
    s_copy(funnam, "<inquire workstation transformation>", funnam_len, 36L);
    return 0;
L241:
    s_copy(funnam, "<inquire locator device state 3>", funnam_len, 32L);
    return 0;
L242:
    s_copy(funnam, "<inquire locator device state>", funnam_len, 30L);
    return 0;
L243:
    s_copy(funnam, "<inquire stroke device state 3>", funnam_len, 31L);
    return 0;
L244:
    s_copy(funnam, "<inquire stroke device state>", funnam_len, 29L);
    return 0;
L245:
    s_copy(funnam, "<inquire valuator device state 3>", funnam_len, 33L);
    return 0;
L246:
    s_copy(funnam, "<inquire valuator device state>", funnam_len, 31L);
    return 0;
L247:
    s_copy(funnam, "<inquire choice device state 3>", funnam_len, 31L);
    return 0;
L248:
    s_copy(funnam, "<inquire choice device state>", funnam_len, 29L);
    return 0;
L249:
    s_copy(funnam, "<inquire pick device state 3>", funnam_len, 29L);
    return 0;
L250:
    s_copy(funnam, "<inquire pick device state>", funnam_len, 27L);
    return 0;
L251:
    s_copy(funnam, "<inquire string device state 3>", funnam_len, 31L);
    return 0;
L252:
    s_copy(funnam, "<inquire string device state>", funnam_len, 29L);
    return 0;
L253:
    s_copy(funnam, "<inquire workstation category>", funnam_len, 30L);
    return 0;
L254:
    s_copy(funnam, "<inquire display space size 3>", funnam_len, 30L);
    return 0;
L255:
    s_copy(funnam, "<inquire display space size>", funnam_len, 28L);
    return 0;
L256:
    s_copy(funnam, "<inquire hlhsr facilities>", funnam_len, 26L);
    return 0;
L257:
    s_copy(funnam, "<inquire view facilities>", funnam_len, 25L);
    return 0;
L258:
    s_copy(funnam, "<inquire predefined view representation>", funnam_len, 
	    40L);
    return 0;
L259:
    s_copy(funnam, "<inquire workstation classification>", funnam_len, 36L);
    return 0;
L260:
    s_copy(funnam, "<inquire dynamics of workstation attributes>", funnam_len,
	     44L);
    return 0;
L261:
    s_copy(funnam, "<inquire default display update state>", funnam_len, 38L);

    return 0;
L262:
    s_copy(funnam, "<inquire polyline facilities>", funnam_len, 29L);
    return 0;
L263:
    s_copy(funnam, "<inquire predefined polyline representation>", funnam_len,
	     44L);
    return 0;
L264:
    s_copy(funnam, "<inquire polymarker facilities>", funnam_len, 31L);
    return 0;
L265:
    s_copy(funnam, "<inquire predefined polymarker representation>", 
	    funnam_len, 46L);
    return 0;
L266:
    s_copy(funnam, "<inquire text facilities>", funnam_len, 25L);
    return 0;
L267:
    s_copy(funnam, "<inquire predefined text representation>", funnam_len, 
	    40L);
    return 0;
L268:
    s_copy(funnam, "<inquire annotation facilities>", funnam_len, 31L);
    return 0;
L269:
    s_copy(funnam, "<inquire text extent>", funnam_len, 21L);
    return 0;
L270:
    s_copy(funnam, "<inquire interior facilities>", funnam_len, 29L);
    return 0;
L271:
    s_copy(funnam, "<inquire predefined interior representation>", funnam_len,
	     44L);
    return 0;
L272:
    s_copy(funnam, "<inquire edge facilities>", funnam_len, 25L);
    return 0;
L273:
    s_copy(funnam, "<inquire predefined edge representation>", funnam_len, 
	    40L);
    return 0;
L274:
    s_copy(funnam, "<inquire pattern facilities>", funnam_len, 28L);
    return 0;
L275:
    s_copy(funnam, "<inquire predefined pattern representation>", funnam_len, 
	    43L);
    return 0;
L276:
    s_copy(funnam, "<inquire colour model facilities>", funnam_len, 33L);
    return 0;
L277:
    s_copy(funnam, "<inquire colour facilities>", funnam_len, 27L);
    return 0;
L278:
    s_copy(funnam, "<inquire predefined colour representation>", funnam_len, 
	    42L);
    return 0;
L279:
#ifndef NO_PROTO
    s_copy(funnam, "<inquire list of available generalized drawing primitive"
	    "s 3>", funnam_len, 60L);
#else /* NO_PROTO */
    s_copy(funnam, "<inquire list of available generalized drawing primitive\
s 3>", funnam_len, 60L);
#endif /* NO_PROTO */
    return 0;
L280:
#ifndef NO_PROTO
    s_copy(funnam, "<inquire list of available generalized drawing primitive"
	    "s>", funnam_len, 58L);
#else /* NO_PROTO */
    s_copy(funnam, "<inquire list of available generalized drawing primitive\
s>", funnam_len, 58L);
#endif /* NO_PROTO */
    return 0;
L281:
    s_copy(funnam, "<inquire generalized drawing primitive 3>", funnam_len, 
	    41L);
    return 0;
L282:
    s_copy(funnam, "<inquire generalized drawing primitive>", funnam_len, 39L)
	    ;
    return 0;
L283:
#ifndef NO_PROTO
    s_copy(funnam, "<inquire list of available generalized structure element"
	    "s>", funnam_len, 58L);
#else /* NO_PROTO */
    s_copy(funnam, "<inquire list of available generalized structure element\
s>", funnam_len, 58L);
#endif /* NO_PROTO */
    return 0;
L284:
    s_copy(funnam, "<inquire number of display priorities supported>", 
	    funnam_len, 48L);
    return 0;
L285:
    s_copy(funnam, "<inquire workstation state table lengths>", funnam_len, 
	    41L);
    return 0;
L286:
    s_copy(funnam, "<inquire dynamics of structures>", funnam_len, 32L);
    return 0;
L287:
    s_copy(funnam, "<inquire number of available logical input devices>", 
	    funnam_len, 51L);
    return 0;
L288:
    s_copy(funnam, "<inquire default locator device data 3>", funnam_len, 39L)
	    ;
    return 0;
L289:
    s_copy(funnam, "<inquire default locator device data>", funnam_len, 37L);
    return 0;
L290:
    s_copy(funnam, "<inquire default stroke device data 3>", funnam_len, 38L);

    return 0;
L291:
    s_copy(funnam, "<inquire default stroke device data>", funnam_len, 36L);
    return 0;
L292:
    s_copy(funnam, "<inquire default valuator device data 3>", funnam_len, 
	    40L);
    return 0;
L293:
    s_copy(funnam, "<inquire default valuator device data>", funnam_len, 38L);

    return 0;
L294:
    s_copy(funnam, "<inquire default choice device data 3>", funnam_len, 38L);

    return 0;
L295:
    s_copy(funnam, "<inquire default choice device data>", funnam_len, 36L);
    return 0;
L296:
    s_copy(funnam, "<inquire default pick device data 3>", funnam_len, 36L);
    return 0;
L297:
    s_copy(funnam, "<inquire default pick device data>", funnam_len, 34L);
    return 0;
L298:
    s_copy(funnam, "<inquire default string device data 3>", funnam_len, 38L);

    return 0;
L299:
    s_copy(funnam, "<inquire default string device data>", funnam_len, 36L);
    return 0;
L300:
    s_copy(funnam, "<inquire set of workstations to which posted>", 
	    funnam_len, 45L);
    return 0;
L301:
    s_copy(funnam, "<inquire open structure>", funnam_len, 24L);
    return 0;
L302:
    s_copy(funnam, "<inquire element pointer>", funnam_len, 25L);
    return 0;
L303:
    s_copy(funnam, "<inquire current element type and size>", funnam_len, 39L)
	    ;
    return 0;
L304:
    s_copy(funnam, "<inquire current element content>", funnam_len, 33L);
    return 0;
L305:
    s_copy(funnam, "<inquire element type and size>", funnam_len, 31L);
    return 0;
L306:
    s_copy(funnam, "<inquire element content>", funnam_len, 25L);
    return 0;
L307:
    s_copy(funnam, "<inquire structure status>", funnam_len, 26L);
    return 0;
L308:
    s_copy(funnam, "<inquire paths to ancestors>", funnam_len, 28L);
    return 0;
L309:
    s_copy(funnam, "<inquire paths to descendants>", funnam_len, 30L);
    return 0;
L310:
    s_copy(funnam, "<element search>", funnam_len, 16L);
    return 0;
L311:
    s_copy(funnam, "<incremental spatial search 3>", funnam_len, 30L);
    return 0;
L312:
    s_copy(funnam, "<incremental spatial search>", funnam_len, 28L);
    return 0;
L313:
    s_copy(funnam, "<inquire input queue overflow>", funnam_len, 30L);
    return 0;
L314:
    s_copy(funnam, "<inquire error handling mode>", funnam_len, 29L);
    return 0;
L315:
    s_copy(funnam, "<emergency close phigs>", funnam_len, 23L);
    return 0;
L316:
    s_copy(funnam, "<error handling>", funnam_len, 16L);
    return 0;
L317:
    s_copy(funnam, "<error logging>", funnam_len, 15L);
    return 0;
L318:
    s_copy(funnam, "<set error handling mode>", funnam_len, 25L);
    return 0;
L319:
    s_copy(funnam, "<escape>", funnam_len, 8L);
    return 0;
L320:
    s_copy(funnam, "<pack data record>", funnam_len, 18L);
    return 0;
L321:
    s_copy(funnam, "<unpack data record>", funnam_len, 20L);
    return 0;
L322:
    s_copy(funnam, "<create store>", funnam_len, 14L);
    return 0;
L323:
    s_copy(funnam, "<delete store>", funnam_len, 14L);
    return 0;
L324:
    s_copy(funnam, "<set error handler>", funnam_len, 19L);
    return 0;
} /* nfunm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/stdcss                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int stdcss_(void)
#else /* NO_PROTO */
/* Subroutine */ int stdcss_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *), ndas (void), nqedm (integer *
	    , integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb (), ndas (), nqedm ();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), unmsg_(char *, ftnlen), nexst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), unmsg_(), nexst ();
#endif /* NO_PROTO */
    static integer stype;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst ();
#endif /* NO_PROTO */
    static integer edmode;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst ();
#endif /* NO_PROTO */

/*  Stdcss sets up a "standard" CSS network for several of the PVT */
/*  tests.  <Open structure> and <execute structure> set up the CSS */
/*  network as follows: */
/*                  100 */
/*                 /  \ */
/*                /    \ */
/*              1/      \2 */
/*              /        \ */
/*             /          \ */
/*         101              102     120   130             140 */
/*          |              / | \     |    /|               | */
/*          |2            /  |  \    |   / |              1| */
/*          |           1/  2|  5\  2|  /3 |5              | */
/*          |           /    |    \  | /   |               | */
/*         103         /     |     \ |/    |              142 */
/*                  104     105     106   107 */
/*                  | |       |     |    / /\ */
/*                 2| |5     /|\    |   / /  \ */
/*                  | |    1/ | \2 1| 1/ /4   \5 */
/*                  109    /  |  \  | / /      \ */
/*                        /   |   \ |/ /       113 */
/*                      110   |    108 */
/*                            |     | */
/*                            |3    |2 */
/*                            |     | */
/*                            |     | */
/*                            |    111 */
/*                            |   / | */
/*                            |  /  | */
/*                            |1/  3| */
/*                            |/    | */
/*                           114   115 */
/*  The nodes of the graph between (100 and 200) represent structures, */
/*  and the labelled edges are references to invoke (lower) */
/*  structures.  The labels (1-5) represent the element position of */
/*  the <execute structure> function within the calling structure. */
/*  <Execute structure> and <label> are the structure elements of the */
/*  individual structures contained in the network.  The values */
/*  between 100 and 199, inclusive, represent structures associated */
/*  with <execute structure> and the values between 900 and 999 */
/*  represent label identifiers for <label>. */
/* open-structure status    none,        open */
/* edit mode */
    nqedm (&errind, &edmode);
    if (errind == 0 && edmode == 0) {
/*        lovely */
    } else {
	unmsg_("STDCSS invoked with edit-mode not = INSERT", 42L);
    }
/* close any structure left opened */
    nqopst (&errind, &stype, &strid);
    chkinq_("pqopst", &errind, 6L);
    if (stype == 1) {
	nclst ();
    }
/* delete old CSS */
    ndas ();
    nopst (&c__100);
    nexst (&c__101);
    nexst (&c__102);
    nclst ();
    nopst (&c__101);
    nlb (&c__902);
    nexst (&c__103);
    nlb (&c__960);
    nclst ();
    nopst (&c__102);
    nexst (&c__104);
    nexst (&c__105);
    nlb (&c__900);
    nlb (&c__901);
    nexst (&c__106);
    nclst ();
    nopst (&c__120);
    nlb (&c__907);
    nexst (&c__106);
    nclst ();
    nopst (&c__130);
    nlb (&c__910);
    nlb (&c__912);
    nexst (&c__106);
    nlb (&c__914);
    nexst (&c__107);
    nclst ();
    nopst (&c__140);
    nexst (&c__142);
    nclst ();
    nopst (&c__104);
    nlb (&c__920);
    nexst (&c__109);
    nlb (&c__925);
    nlb (&c__926);
    nexst (&c__109);
    nclst ();
    nopst (&c__105);
    nexst (&c__110);
    nexst (&c__108);
    nexst (&c__114);
    nlb (&c__950);
    nclst ();
    nopst (&c__106);
    nexst (&c__108);
    nclst ();
    nopst (&c__107);
    nexst (&c__108);
    nlb (&c__930);
    nlb (&c__935);
    nexst (&c__108);
    nexst (&c__113);
    nclst ();
    nopst (&c__108);
    nlb (&c__961);
    nexst (&c__111);
    nclst ();
    nopst (&c__111);
    nexst (&c__114);
    nlb (&c__940);
    nexst (&c__115);
    nlb (&c__942);
    nlb (&c__916);
    nlb (&c__947);
    nlb (&c__955);
    nlb (&c__947);
    nlb (&c__955);
    nlb (&c__940);
    nlb (&c__947);
    nclst ();
    nopst (&c__113);
    nlb (&c__901);
    nclst ();
    nopst (&c__114);
    nlb (&c__901);
    nclst ();
    nopst (&c__115);
    nlb (&c__901);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* stdcss_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/csspth                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int csspth_(void)
#else /* NO_PROTO */
/* Subroutine */ int csspth_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nexst (integer *), nopst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nexst (), nopst ();
#endif /* NO_PROTO */

/*  Csspth sets up the "standard" CSS network for testing */
/*  ancestor and descendant paths. */
/*  Use <open structure> and <execute structure> to set up */
/*  the CSS as follows: */

/*                   101        106       108 */
/*                  / | \       / */
/*                 /  |  \    1/ */
/*               1/  2|  3\   / */
/*               /    |    \ / */
/*              /     |    107 */
/*             /      | */
/*          102      103 */
/*          | \      / \\ */
/*          |  \   1/   \\ */
/*         1|  2\  /    2\\3 */
/*          |    \/       \\ */
/*          |    104      105 */
/*          |     |      / */
/*          |    1|    1/ */
/*           \    |    / */
/*            \   |   / */
/*             \  |  / */
/*              \ | / */
/*               109 */
    nopst (&c__101);
    nexst (&c__102);
    nexst (&c__103);
    nexst (&c__107);
    nclst ();
    nopst (&c__102);
    nexst (&c__109);
    nexst (&c__104);
    nclst ();
    nopst (&c__103);
    nexst (&c__104);
    nexst (&c__105);
    nexst (&c__105);
    nclst ();
    nopst (&c__104);
    nexst (&c__109);
    nclst ();
    nopst (&c__105);
    nexst (&c__109);
    nclst ();
    nopst (&c__106);
    nexst (&c__107);
    nclst ();
    nopst (&c__108);
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* csspth_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/csseq                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical csseq_(char *cssshd, ftnlen cssshd_len)
#else /* NO_PROTO */
logical csseq_(cssshd, cssshd_len)
char *cssshd;
ftnlen cssshd_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    logical ret_val;

    /* Local variables */
    static integer ir, iel, ish, iel1, iel2, idum, root[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int set2d_(char *, integer *, integer *, integer *
	    , integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int set2d_();
#endif /* NO_PROTO */
    static integer ipath;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpde (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqpde ();
#endif /* NO_PROTO */
    static integer strid, ixpth, nroot;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer ndpath;
    static logical single;
    static integer erpath[100]	/* was [2][50] */, errind, pathln[50], pathsh[
	    2500]	/* was [50][50] */, apthsz, numpth;
#ifndef NO_PROTO
    extern /* Subroutine */ int gtroot_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int gtroot_();
#endif /* NO_PROTO */

/*  CSSEQ accepts a character string parameter (cssshd = "CSS */
/*  should") which describes a CSS network and compares it to the CSS */
/*  state as reported by PHIGS inquire functions.  Csseq returns */
/*  .true. if they are equal, else .false.  The syntax of the input */
/*  string is: */
/*  cssshd             = path-list | blank */
/*  path-list          = path slash | path slash path-list */
/*  path               = path-element | path-element comma path */
/*  path-element       = structure-id comma element-reference */
/*  comma              = "," */
/*  slash              = "/" */
/*  blank              = " " */
/*  structure-id       = unsigned-integer */
/*  element-reference  = unsigned-integer */
/*  Spaces may appear anywhere. */
/*  Eg:  2,0/ */
/*       2,3,4,0/ */
/*       2, 3, 4, 0 / 2, 3, 5, 0 / 2, 3, 6, 0  / */
/*       20,0/30,0/40,0/ */
/*       20,0/30,1,50,0/40,0/ */
/*  If the CSS contains two networks: */

/*            10              110 */
/*           /  \              | */
/*         20   30            120 */
/*        /  \ / */
/*       40   50 */

/*  it could be represented by: */
/*     "10,1,20,1,40,0/  10,1,20,2,50,0/  10,2,30,1,50,0/  110,3,120,0/" 
*/
/*  A blank cssshd indicates an empty CSS */
/* truncation method */
/* interpret cssshd string into ragged 2D array of integers. */
    set2d_(cssshd, &c__50, &numpth, pathln, pathsh, cssshd_len);
/* now get all roots */
    gtroot_(&nroot, root);
/* Get all descendant paths of each root */
    i__1 = nroot;
    for (ir = 1; ir <= i__1; ++ir) {
/* structure ID of next root */
	strid = root[ir - 1];
/* ndpath = how many descendant paths ? */
	nqpde (&strid, &c__0, &c__0, &c__50, &c__0, &errind, &ndpath, &idum, 
		erpath);
	chkinq_("pqpde", &errind, 5L);
/* for singleton root, gotta force path of length 1 */
	single = ndpath == 0;
	if (single) {
	    ndpath = 1;
	}
/* retrieve each descendant path */
	i__2 = ndpath;
	for (ixpth = 1; ixpth <= i__2; ++ixpth) {
	    if (single) {
		apthsz = 1;
		erpath[0] = strid;
		erpath[1] = 0;
	    } else {
		nqpde (&strid, &c__0, &c__0, &c__50, &ixpth, &errind, &idum, &
			apthsz, erpath);
		chkinq_("pqpde", &errind, 5L);
	    }
/* look for a matching should-path */
	    i__3 = numpth;
	    for (ish = 1; ish <= i__3; ++ish) {
/* - start by seeking matching length */
		if (apthsz << 1 != pathln[ish - 1]) {
		    goto L500;
		}
/* lengths match - try contents */
		i__4 = apthsz;
		for (iel = 1; iel <= i__4; ++iel) {
		    iel2 = iel << 1;
		    iel1 = iel2 - 1;
		    if (pathsh[iel1 + ish * 50 - 51] != erpath[(iel << 1) - 2]
			    ) {
			goto L500;
		    }
		    if (pathsh[iel2 + ish * 50 - 51] != erpath[(iel << 1) - 1]
			    ) {
			goto L500;
		    }
/* L600: */
		}
/* OK they matched - delete out that should-path to prevent re
-use */
		pathln[ish - 1] = -1;
		goto L400;
L500:
		;
	    }
/* No should-path match found for path reported by PHIGS - fail */

	    ret_val = FALSE_;
	    return ret_val;
/* next descendant path from current root */
L400:
	    ;
	}
/* next root structure */
/* L300: */
    }
/* match has been found for every path returned by pqpde. */
/* Now, simply check that all expected paths have been "used" by CSS */
    i__1 = numpth;
    for (ipath = 1; ipath <= i__1; ++ipath) {
	if (pathln[ipath - 1] != -1) {
	    ret_val = FALSE_;
	    return ret_val;
	}
/* L700: */
    }
    ret_val = TRUE_;
    return ret_val;
} /* csseq_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/strcon                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical strcon_(integer *strid, char *strg, ftnlen strg_len)
#else /* NO_PROTO */
logical strcon_(strid, strg, strg_len)
integer *strid;
char *strg;
ftnlen strg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ia[20];
    static real ra[20];
    static char sa[80*20];
    static integer ep, sl[20];
    static char msg[100];
    static integer icon, size, stat, isiz, ityp, rsiz, ssiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *, integer *, char *, ftnlen), unmsg_(char *, 
	    ftnlen), nqets (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), setvs_(char *, integer *, 
	    integer *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeco (), unmsg_(), nqets (), setvs_(), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer errind, lstele, eltype, typcon[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___206 = { 0, msg, 0, "(A,I7)", 100, 1 };
    static icilist io___218 = { 0, msg, 0, "(A,I7)", 100, 1 };
    static icilist io___219 = { 0, msg, 0, "(A,I7)", 100, 1 };


/*  Strcon is used to check the contents of a single structure. */

/*  Strid is the identifier of the structure to be examined. */
/*  Strg is a string representing a list of integers, which are */
/*  interpreted as type-content pairs.  Only the first integer */
/*  in an element's content is checked, i.e. that mapped to */
/*  the first slot in the integer array by PQCECO or PQECO */

/*  If the structure contains a sequence of elements exactly matching */
/*  these type-content pairs, strcon returns TRUE, otherwise FALSE. */
/*  A blank string may be used to designate an empty structure, but */
/*  the structure must exist. */
/* structure status indicator */
/*  error code for non-existent element */
/* generate integer array from strg */
    setvs_(strg, typcon, &size, strg_len);
    if (size % 2 != 0) {
/* Writing concatenation */
#ifndef NO_PROTO
	i__1[0] = 66, a__1[0] = "Illegal string passed to strcon; must be ev"
		"en number of elements: ";
#else /* NO_PROTO */
	i__1[0] = 66, a__1[0] = "Illegal string passed to strcon; must be ev\
en number of elements: ";
#endif /* NO_PROTO */
	i__1[1] = strg_len, a__1[1] = strg;
	s_cat(msg, a__1, i__1, &c__2, 100L);
	unmsg_(msg, 100L);
    }
/* last element */
    lstele = size / 2;
/* check structure existence */
    nqstst (strid, &errind, &stat);
    chkinq_("pqstst", &errind, 6L);
    if (stat == 0) {
	s_wsfi(&io___206);
	do_fio(&c__1, "Non-existent structure passed to strcon: ", 41L);
	do_fio(&c__1, (char *)&(*strid), (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 100L);
    }
/* check that structure is not too long */
    i__2 = lstele + 1;
    nqets (strid, &i__2, &errind, &eltype, &isiz, &rsiz, &ssiz);
    if (errind != 202) {
	goto L666;
    }
    if (lstele > 0) {
/* check that structure is not too short */
	nqets (strid, &lstele, &errind, &eltype, &isiz, &rsiz, &ssiz);
	if (errind == 202) {
	    goto L666;
	}
    }
    i__2 = lstele;
    for (ep = 1; ep <= i__2; ++ep) {
	nqets (strid, &ep, &errind, &eltype, &isiz, &rsiz, &ssiz);
	if (errind == 0) {
/*  Normal return from pqets */
	    icon = ep << 1;
	    ityp = icon - 1;
	    if (eltype != typcon[ityp - 1]) {
/*  types don't match */
		goto L666;
	    }
	    nqeco (strid, &ep, &c__20, &c__20, &c__20, &errind, &isiz, ia, &
		    rsiz, ra, &ssiz, sl, sa, 80L);
	    if (errind != 0) {
/*  weird errind from pqeco */
		s_wsfi(&io___218);
		do_fio(&c__1, "Strange errind from pqeco in strcon: ", 37L);
		do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
		e_wsfi();
		unmsg_(msg, 100L);
	    }
	    if (ia[0] != typcon[icon - 1]) {
/*  contents don't match */
		goto L666;
	    }
	} else {
/*  weird errind from pqets */
	    s_wsfi(&io___219);
	    do_fio(&c__1, "Strange errind from pqets in strcon: ", 37L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    e_wsfi();
	    unmsg_(msg, 100L);
	}
/* L100: */
    }
    ret_val = TRUE_;
    goto L667;
L666:
    ret_val = FALSE_;
L667:
    return ret_val;
} /* strcon_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/setstr                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setstr_(integer *strid, char *strg, ftnlen strg_len)
#else /* NO_PROTO */
/* Subroutine */ int setstr_(strid, strg, strg_len)
integer *strid;
char *strg;
ftnlen strg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3], i__2;
    char ch__1[33];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen), s_wsfi(icilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfi(void);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_indx(), s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer ival, ierr, wlen;
    static char wstr[700];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *), unmsg_(char *
	    , ftnlen), nexst (integer *), nopst (integer *), deblnk_(char *, 
	    char *, integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst (), unmsg_(), nexst (), 
	    nopst (), deblnk_();
#endif /* NO_PROTO */
    static integer ncomma;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, opstid, opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int prsint_(char *, integer *, integer *, ftnlen),
	     nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int prsint_(), nqopst ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___228 = { 0, wstr, 0, "(A,I4,A)", 700, 1 };


/*  Setstr is used to set the contents of a single structure. */

/*  Strid is the identifier of the structure to be set. */
/*  Strg is a string representing a list of letter-integer pairs, */
/*  separated by commas, which are interpreted as type-content pairs. */
/*  A blank string may be used to designate an empty structure.  The */
/*  only two valid letters are L (for LABEL) and E (for EXECUTE */
/*  STRUCTURE). E.g. the string "L11,E101,L901" indicates that the */
/*  structure is to contain 3 elements: LABEL 11, EXECUTE STRUCTURE */
/*  101 and LABEL 901.  Blanks are ignored. */
/*  The specified structure is left closed.  If another structure is */
/*  originally open, it is closed. */
/*  open-structure status */
/* de-blank string */
    deblnk_(strg, wstr, &wlen, strg_len, 700L);
    ++wlen;
    wstr[wlen - 1] = ',';
/*  check open structure */
    nqopst (&errind, &opstat, &opstid);
    chkinq_("pqopst", &errind, 6L);
    if (opstat == 1) {
	nclst ();
    }
/*  set up empty structure */
    nemst (strid);
    nopst (strid);
L100:
    if (s_cmp(wstr, " ", 700L, 1L) == 0) {
	goto L600;
    }
    ncomma = i_indx(wstr, ",", 700L, 1L);
    prsint_(wstr + 1, &ival, &ierr, ncomma - 2);
    if (ierr != 0) {
	s_wsfi(&io___228);
	do_fio(&c__1, "SETSTR got error code ", 22L);
	do_fio(&c__1, (char *)&ierr, (ftnlen)sizeof(integer));
	do_fio(&c__1, " from PRSINT.", 13L);
	e_wsfi();
	unmsg_(wstr, 700L);
    }
    if (*wstr == 'L') {
	nlb (&ival);
    } else if (*wstr == 'E') {
	nexst (&ival);
    } else {
/* Writing concatenation */
	i__1[0] = 14, a__1[0] = "Illegal code: ";
	i__1[1] = 1, a__1[1] = wstr;
	i__1[2] = 18, a__1[2] = " passed to SETSTR.";
	s_cat(ch__1, a__1, i__1, &c__3, 33L);
	unmsg_(ch__1, 33L);
    }
    i__2 = ncomma;
    s_copy(wstr, wstr + i__2, 700L, 700 - i__2);
    goto L100;
L600:
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setstr_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/newstr                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int newstr_(integer *start, integer *newid)
#else /* NO_PROTO */
/* Subroutine */ int newstr_(start, newid)
integer *start, *newid;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), chkinq_();
#endif /* NO_PROTO */
    static integer errind, strsti;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/*  NEWSTR searches for a non-existent structure identifier, starting */
/*  with START, and returns it, if found, in NEWID. */
/* structure status indicator */
    i__1 = *start + 100;
    for (ix = *start; ix <= i__1; ++ix) {
	nqstst (&ix, &errind, &strsti);
	chkinq_("pqstst", &errind, 6L);
	if (strsti == 0) {
	    *newid = ix;
	    return 0;
	}
/* L100: */
    }
    unmsg_("NEWSTR cannot find a new structure identifier.", 46L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* newstr_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/gtroot                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int gtroot_(integer *iroot, integer *root)
#else /* NO_PROTO */
/* Subroutine */ int gtroot_(iroot, root)
integer *iroot, *root;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer idum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqpan (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqsid (integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqpan (), nqsid ();
#endif /* NO_PROTO */
    static integer idstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer ixstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, erpath[100]	/* was [2][50] */, nanpth, totstr;

/*  gtroot gets all identifiers for root structures in the CSS and */
/*  returns them in the array root.  Iroot contains the number */
/*  of roots found. */
/* truncation method */
/* totstr = how many structures? */
    /* Parameter adjustments */
    --root;

    /* Function Body */
    nqsid (&c__0, &errind, &totstr, &idum);
    chkinq_("pqsid", &errind, 5L);
/* number of roots so far */
    *iroot = 0;
/* go thru all the structures, looking for roots */
    i__1 = totstr;
    for (ixstr = 1; ixstr <= i__1; ++ixstr) {
/* idstr = next structure ID to check for rootedness */
	nqsid (&ixstr, &errind, &idum, &idstr);
	chkinq_("pqsid", &errind, 5L);
/* is idstr a root?  Ie, how many ancestor paths (nanpth) are there? 
*/
	nqpan (&idstr, &c__1, &c__1, &c__50, &c__0, &errind, &nanpth, &idum, 
		erpath);
	chkinq_("pqpan", &errind, 5L);
/* if there are ancestor paths, then this is NOT a root. */
	if (nanpth > 0) {
	    goto L200;
	}
/* check overflow */
	if (*iroot >= 50) {
	    unmsg_("Number of roots found by GTROOT exceeds maximum.", 48L);
	} else {
	    ++(*iroot);
	    root[*iroot] = idstr;
	}
L200:
	;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* gtroot_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/sphdis                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical sphdis_(integer *strid)
#else /* NO_PROTO */
logical sphdis_(strid)
integer *strid;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[1], ya[1];
    static char msg[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer idum[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int niss (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int niss ();
#endif /* NO_PROTO */
    static integer fpath[20]	/* was [2][10] */, spath[2]	/* was [2][1] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *), unmsg_(char *
	    , ftnlen), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst (), unmsg_(), nopst ();
#endif /* NO_PROTO */
    static integer errind, fpthsz;

    /* Fortran I/O blocks */
    static icilist io___247 = { 0, msg, 0, "(A,I6)", 200, 1 };


/*  SPHDIS determines whether this implementation uses "spherical" or */
/* "cubic" distance metric for purposes of ISS.  Based on fact that betwee
n*/
/*  (0,0) and (.85,.85), the "spherical" distance = 1.202 but the "cubic" 
*/
/*  distance = 0.85. */
/*  Input parameter: */
/*    STRID: available structure ID */
/* clipping indicator */
/*                noclip      clip */
    nopst (strid);
    nemst (strid);
#ifndef NO_PROTO
    xa[0] = .85f;
    ya[0] = .85f;
#else /* NO_PROTO */
    xa[0] = (float).85;
    ya[0] = (float).85;
#endif /* NO_PROTO */
    npl (&c__1, xa, ya);
    nclst ();
    spath[0] = *strid;
    spath[1] = 0;
/* search distance of 1.0 should find marker for cubic, but not for spheri
cal*/
    niss (&c_b1307, &c_b1307, &c_b1309, &c__1, spath, &c__0, &c__1, &c__0, 
	    idum, idum, idum, idum, &c__0, idum, idum, idum, idum, &c__10, &
	    errind, &fpthsz, fpath);
    nemst (strid);
    if (errind != 0) {
	s_wsfi(&io___247);
	do_fio(&c__1, "ISS in SPHDIS returned error indicator = ", 41L);
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 200L);
    }
    ret_val = fpthsz == 0;
    return ret_val;
} /* sphdis_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/chkelp                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int chkelp_(integer *elpos)
#else /* NO_PROTO */
/* Subroutine */ int chkelp_(elpos)
integer *elpos;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), nqep (integer *, integer *), 
	    pass_(void), nsep (integer *), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), nqep (), pass_(), nsep (), chkinq_();
#endif /* NO_PROTO */

    static integer errind, actpos;

/*  Chkelp checks whether or not the current actual element position */
/*  equals the expected position, as indicated by the parameter, */
/*  and issues pass or fail as appropriate.  In the case of */
/*  failure, it attempts to re-set the pointer to the correct value. */
    nqep (&errind, &actpos);
    chkinq_("pqep", &errind, 4L);
    if (*elpos == actpos) {
	pass_();
    } else {
	fail_();
	nsep (elpos);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* chkelp_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/avarnm                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int avarnm_(integer *arnm)
#else /* NO_PROTO */
/* Subroutine */ int avarnm_(arnm)
integer *arnm;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer numold = 0;

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    char ch__1[67], ch__2[61];
    olist o__1;
    inlist ioin__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , f_inqu(inlist *);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer f_open(olist *);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi(), f_inqu();
    /* Subroutine */ int s_cat();
    integer f_open();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix, namct;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static char arnmch[12];
    static logical exfile;
    static integer oldnms[1000];

    /* Fortran I/O blocks */
    static icilist io___255 = { 0, arnmch+3, 0, "(I5.5)", 5, 1 };


/*  This routine returns an integer to be used as the name of an */
/*  archive file in an <open archive file> statement.  This file */
/*  is empty upon open, i.e. contains no structures. */
/*  Avoid individual, global logical unit numbers, any previously */
/*  used logical units, and special Fortran units 5,6,7 */
/* Computing MAX */
    i__1 = max(globnu_1.indlun,globnu_1.glblun);
    *arnm = max(i__1,10) + 1;
    i__1 = numold;
    for (ix = 1; ix <= i__1; ++ix) {
	if (oldnms[ix - 1] >= *arnm) {
	    ++(*arnm);
	}
/* L100: */
    }
    ++numold;
    oldnms[numold - 1] = *arnm;
/*  Seek new file name and ensure that a named file is opened with */
/*  the logical unit number = ARNM */
    s_copy(arnmch, "PVT00000.ARC", 12L, 12L);
    for (namct = 1; namct <= 100; ++namct) {
	s_wsfi(&io___255);
	do_fio(&c__1, (char *)&namct, (ftnlen)sizeof(integer));
	e_wsfi();
	ioin__1.inerr = 1;
	ioin__1.infilen = 12;
	ioin__1.infile = arnmch;
	ioin__1.inex = &exfile;
	ioin__1.inopen = 0;
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
	i__1 = f_inqu(&ioin__1);
	if (i__1 != 0) {
	    goto L606;
	}
	if (! exfile) {
	    goto L300;
	}
/* L200: */
    }
    unmsg_("AVARNM unable to find name of non-existent file.", 48L);
L600:
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 55, a__1[0] = "Error encountered in AVARNM when opening archiv"
	    "e file: ";
#else /* NO_PROTO */
    i__2[0] = 55, a__1[0] = "Error encountered in AVARNM when opening archiv\
e file: ";
#endif /* NO_PROTO */
    i__2[1] = 12, a__1[1] = arnmch;
    s_cat(ch__1, a__1, i__2, &c__2, 67L);
    unmsg_(ch__1, 67L);
L606:
/* Writing concatenation */
#ifndef NO_PROTO
    i__2[0] = 49, a__1[0] = "Error encountered in AVARNM when inquiring file"
	    ": ";
#else /* NO_PROTO */
    i__2[0] = 49, a__1[0] = "Error encountered in AVARNM when inquiring file\
: ";
#endif /* NO_PROTO */
    i__2[1] = 12, a__1[1] = arnmch;
    s_cat(ch__2, a__1, i__2, &c__2, 61L);
    unmsg_(ch__2, 61L);
L300:
    o__1.oerr = 1;
    o__1.ounit = *arnm;
    o__1.ofnmlen = 12;
    o__1.ofnm = arnmch;
    o__1.orl = 0;
    o__1.osta = "unknown";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L600;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* avarnm_ */

/*  This section of SUBLIB provides features for interactive tests, */
/*  especially the handling of the dialogue area. */
/*  Calling structure among major subroutines: */
/*                 DCHPF,DCHPFV,DCHFL,DCHFLV */
/*                 ------------------------- */
/*                           | */
/*             --------------| */
/*             |             | */
/*             |  DYNPF      | */
/*             |  / |        | */
/*             | /  |        |               DLSTPF */
/*             |/   |        |                 | */
/*             |   DYN     DCHOIC   DRLVAL   DILIST   OPMSGW */
/*             |    |        |        |        |        | */
/*             |    ------------------------------------- */
/*             |                 | */
/*           OPFAIL            DLINE */
/*              \              /  | */
/*               \            /   | */
/*             OPCOFL     OPCOMT  | */
/*                  \      /      | */
/*                   \    /       | */
/*                    \  /        | */
/*                    OPCO        | */
/*                      |         | */
/*                   DSTRNG       | */
/*                       \        | */
/*                        \       | */
/*                      -------------- */
/*                      |            | */
/*                   IACMSG        IACANS */
/*                   / |  \ */
/*                  /  |   \ */
/*             FITPAR  |   SETASF */
/*               |  \  | */
/*               |   \ | */
/*               |   LINBRK */
/*               |   / */
/*               |  / */
/*             SCAPAR */
/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/setdlg                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
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
    static icilist io___285 = { 0, msg, 0, "(A,I5)", 300, 1 };


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
    nswkw (&globnu_1.wkid, &c_b1307, &scrx, &c_b1307, &scry);
/* DC */
    nswkv (&globnu_1.wkid, &c_b1307, &dcmaxx, &c_b1307, &dcmaxy);
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
    nevom3 (&c_b1307, &c_b1307, &c_b1307, &c_b1307, &c_b1307, &c_b1309, &
	    c_b1307, &c_b1309, &c_b1307, &errind, vormat);
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
    nevmm3 (wnlm, vwcplm, &c__0, &c_b1364, &c_b1364, &c_b1366, &c_b1307, &
	    c_b1307, &c_b1309, &errind, vmpmat);
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
    nevmm3 (wnlm, vwcplm, &c__0, &c_b1364, &r__1, &c_b1309, &c_b1307, &
	    c_b1307, &c_b1309, &errind, vmpmat);
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
    nevmm3 (wnlm, vwcplm, &c__0, &c_b1364, &r__1, &c_b1309, &c_b1307, &
	    c_b1307, &c_b1309, &errind, vmpmat);
    chkinq_("pevmm3", &errind, 6L);
    nsvwr3 (&globnu_1.wkid, &c__3, vormat, vmpmat, vwcplm, &c__0, &c__0, &
	    c__0);
/* L300: */
    if (dialog_1.dintyp == 1) {
/*  input via READ: skip initialization of string device. */
	goto L600;
    } else if (dialog_1.dintyp != 2) {
	s_wsfi(&io___285);
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

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/endit                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int endit_(void)
#else /* NO_PROTO */
/* Subroutine */ int endit_()
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix, wkid, idum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclph (void), nclwk (integer *), nclst (void);

#else /* NO_PROTO */
    extern /* Subroutine */ int nclph (), nclwk (), nclst ();
#endif /* NO_PROTO */
    static integer numwk;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqsys (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqsys ();
#endif /* NO_PROTO */
    static integer sysst;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind;
#ifndef NO_PROTO
    extern /* Subroutine */ int windup_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int windup_();
#endif /* NO_PROTO */
    static integer opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nupast (integer *), nqopwk (integer *, 
	    integer *, integer *, integer *), nqopst (integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nupast (), nqopwk (), nqopst ();
#endif /* NO_PROTO */

/*  ENDIT performs all normal close-out chores for a PVT test: */
/*  it clears and closes all open workstations, closes the open */
/*  structure if there is one, closes PHIGS and issues WINDUP. */
/* system state value */
/* open-structure status */
/*  check if PHIGS open */
    nqsys (&sysst);
    if (sysst == 0) {
	goto L666;
    }
/*  close all open workstations */
    nqopwk (&c__0, &errind, &numwk, &idum);
    chkinq_("pqopwk", &errind, 6L);
    i__1 = numwk;
    for (ix = 1; ix <= i__1; ++ix) {
/*  always delete 1st element of remaining list - list changes each */

/*  time thru loop because of call to PCLWK */
	nqopwk (&c__1, &errind, &idum, &wkid);
	chkinq_("pqopwk", &errind, 6L);
	nupast (&wkid);
	nclwk (&wkid);
/* L100: */
    }
/*  close open structure */
    nqopst (&errind, &opstat, &idum);
    chkinq_("pqopst", &errind, 6L);
    if (opstat == 1) {
	nclst ();
    }
    nclph ();
L666:
    windup_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* endit_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/win6                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int win6_(integer *strid, integer *coli, real *xsiz, real *
	ysiz, real *xwinlo, real *ywinlo)
#else /* NO_PROTO */
/* Subroutine */ int win6_(strid, coli, xsiz, ysiz, xwinlo, ywinlo)
integer *strid, *coli;
real *xsiz, *ysiz, *xwinlo, *ywinlo;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[2], ya[2];
    static integer ix, iy;
    static char dig[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx ();
#endif /* NO_PROTO */
    static real xloc, yloc, txht;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh ();
#endif /* NO_PROTO */
    static integer winid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nopst (integer *), nsplci (
	    integer *), nschup (real *, real *), nschxp (real *), nstxci (
	    integer *), nslwsc (real *), nstxal (integer *, integer *), 
	    nstxfn (integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nopst (), nsplci (), nschup (), 
	    nschxp (), nstxci (), nslwsc (), nstxal (), nstxfn (), nstxpr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___308 = { 0, dig, 0, "(I1)", 1, 1 };


/*  WIN6 sets up a structure which generates 6 labelled */
/*  windows on the screen. */
/*  Input parameters: */
/*    STRID         : Identifier of structure to contain windows */
/*    COLI          : Color index to be used */
/*  Output parameters: */
/*    XSIZ,YSIZ     : Size of windows */
/*    XWINLO,YWINLO : Location of lower left corner of windows */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
    /* Parameter adjustments */
    --ywinlo;
    --xwinlo;

    /* Function Body */
#ifndef NO_PROTO
    *xsiz = .3333f;
    *ysiz = .3333f;
    txht = .1666f;
#else /* NO_PROTO */
    *xsiz = (float).3333;
    *ysiz = (float).3333;
    txht = (float).1666;
#endif /* NO_PROTO */
    nopst (strid);
    nslwsc (&c_b1307);
    nsplci (coli);
    nstxci (coli);
    nstxfn (&c__1);
    nstxpr (&c__2);
    nschxp (&c_b1309);
#ifndef NO_PROTO
    r__1 = txht * .3f;
#else /* NO_PROTO */
    r__1 = txht * (float).3;
#endif /* NO_PROTO */
    nschh (&r__1);
    nschup (&c_b1307, &c_b1309);
    nstxal (&c__2, &c__1);
    winid = 1;
    for (iy = 1; iy >= 0; --iy) {
#ifndef NO_PROTO
	xa[0] = 0.f;
	xa[1] = 1.f;
#else /* NO_PROTO */
	xa[0] = (float)0.;
	xa[1] = (float)1.;
#endif /* NO_PROTO */
	yloc = txht + iy * (*ysiz + txht);
	ya[0] = yloc;
	ya[1] = yloc;
	npl (&c__2, xa, ya);
	ya[0] = yloc + *ysiz;
	ya[1] = ya[0];
	npl (&c__2, xa, ya);
	for (ix = 0; ix <= 3; ++ix) {
	    xloc = ix * *xsiz;
	    ya[0] = yloc;
	    ya[1] = yloc + *ysiz;
	    xa[0] = xloc;
	    xa[1] = xloc;
	    npl (&c__2, xa, ya);
	    if (ix == 3) {
		goto L200;
	    }
	    xwinlo[winid] = xloc;
	    ywinlo[winid] = yloc;
	    s_wsfi(&io___308);
	    do_fio(&c__1, (char *)&winid, (ftnlen)sizeof(integer));
	    e_wsfi();
	    r__1 = xloc + *xsiz / 2;
#ifndef NO_PROTO
	    r__2 = yloc - txht * .1f;
#else /* NO_PROTO */
	    r__2 = yloc - txht * (float).1;
#endif /* NO_PROTO */
	    ntx (&r__1, &r__2, dig, 1L);
	    ++winid;
L200:
	    ;
	}
/* L100: */
    }
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* win6_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/wcnpc                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int wcnpc_(real *wcx, real *wcy, real *npcx, real *npcy, 
	real *npcpwc)
#else /* NO_PROTO */
/* Subroutine */ int wcnpc_(wcx, wcy, npcx, npcy, npcpwc)
real *wcx, *wcy, *npcx, *npcy, *npcpwc;
#endif /* NO_PROTO */
{
/*  WCNPC converts a 2D point in WC to the equivalent point in NPC */
/*  within view#1 for the picture area, which maps 0:1,0:1 (WC) to */
/*  PICL:PICR, PICB:PICT (NPC).  It also returns the NPC/WC ratio. */
    *npcx = *wcx * (scrfmt_1.picr - scrfmt_1.picl) + scrfmt_1.picl;
    *npcy = *wcy * (scrfmt_1.pict - scrfmt_1.picb) + scrfmt_1.picb;
    *npcpwc = scrfmt_1.pict - scrfmt_1.picb;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* wcnpc_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/locppm                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int locppm_(integer *yloc, real *xval)
#else /* NO_PROTO */
/* Subroutine */ int locppm_(yloc, xval)
integer *yloc;
real *xval;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int npm (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm ();
#endif /* NO_PROTO */
    static real yval[1];
#ifndef NO_PROTO
    extern doublereal ylocel_(integer *);
#else /* NO_PROTO */
    extern doublereal ylocel_();
#endif /* NO_PROTO */

/*  LOCPPM draws a polymarker at the real y-location corresponding to */
/*  the integer index given in YLOC. */
    /* Parameter adjustments */
    --xval;

    /* Function Body */
    yval[0] = ylocel_(yloc);
    npm (&c__1, &xval[1], yval);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* locppm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/drwrec                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int drwrec_(real *xl, real *xh, real *yl, real *yh)
#else /* NO_PROTO */
/* Subroutine */ int drwrec_(xl, xh, yl, yh)
real *xl, *xh, *yl, *yh;
#endif /* NO_PROTO */
{
    static real xa[5], ya[5];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */

/*  DRWREC draws a rectangle as specified by x-low,x-high,y-low,y-high */
    xa[0] = *xl;
    xa[1] = *xl;
    xa[2] = *xh;
    xa[3] = *xh;
    xa[4] = *xl;
    ya[0] = *yl;
    ya[1] = *yh;
    ya[2] = *yh;
    ya[3] = *yl;
    ya[4] = *yl;
    npl (&c__5, xa, ya);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drwrec_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/txexal                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int txexal_(integer *txfont, integer *txpath, char *txstr, 
	real *ntxwd, real *ntxht, real *htab, real *vtab, ftnlen txstr_len)
#else /* NO_PROTO */
/* Subroutine */ int txexal_(txfont, txpath, txstr, ntxwd, ntxht, htab, vtab, 
	txstr_len)
integer *txfont, *txpath;
char *txstr;
real *ntxwd, *ntxht, *htab, *vtab;
ftnlen txstr_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1;

    /* Local variables */
    static integer ix;
    static real txrx[2], txry[2], rdum1, rdum2;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqtxx (integer *, integer *, real *, real *, 
	    real *, integer *, integer *, integer *, char *, integer *, real *
	    , real *, real *, real *, ftnlen), chkinq_(char *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqtxx (), chkinq_();
#endif /* NO_PROTO */
    static integer errind;

/*  TXEXAL returns not only the size of the nominal text extent */
/*  rectangle, but also the location within it of the various text */
/*  alignment positions. */
/*  Input parameters: */
/*    TXFONT : text font to be used for inquiry */
/*    TXPATH : text path to be used for inquiry */
/*    TXSTR  : text string to be used for inquiry */
/*  Output parameters: */
/*    NTXWD  : nominal width of text rectangle */
/*    NTXHT  : nominal height of text rectangle */
/*    HTAB   : nominal position of horizontal text alignments */
/*    VTAB   : nominal position of vertical text alignments */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    /* Parameter adjustments */
    --vtab;
    --htab;

    /* Function Body */
    nqtxx (&dialog_1.specwt, txfont, &c_b1309, &c_b1307, &c_b1309, txpath, &
	    c__1, &c__5, txstr, &errind, txrx, txry, &rdum1, &rdum2, 
	    txstr_len);
    chkinq_("pqtxx", &errind, 5L);
    *ntxwd = (r__1 = txrx[1] - txrx[0], dabs(r__1));
    *ntxht = (r__1 = txry[1] - txry[0], dabs(r__1));
/*  save normalized heights in table: */
    for (ix = 1; ix <= 5; ++ix) {
	nqtxx (&dialog_1.specwt, txfont, &c_b1309, &c_b1307, &c_b1309, txpath,
		 &c__1, &ix, txstr, &errind, txrx, txry, &rdum1, &rdum2, 
		txstr_len);
	chkinq_("pqtxx", &errind, 5L);
	vtab[ix] = *ntxht - txry[1];
/* L100: */
    }
/*  save normalized widths in table: */
#ifndef NO_PROTO
    htab[1] = 0.f;
#else /* NO_PROTO */
    htab[1] = (float)0.;
#endif /* NO_PROTO */
    htab[2] = *ntxwd / 2;
    htab[3] = *ntxwd;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* txexal_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/intsty                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical intsty_(integer *specwt, integer *rqstyl)
#else /* NO_PROTO */
logical intsty_(specwt, rqstyl)
integer *specwt, *rqstyl;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    logical ret_val;

    /* Local variables */
    static integer ix, nis;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer idum1, idum2, idum3, idum4;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, thisis;

/*  INTSTY indicates whether or not a requested interior style is */
/*  available for a workstation type. */

/*  Input parameters: */
/*    SPECWT : workstation type */
/*    RQSTYL : the interior style in question */
    nqif (specwt, &c__0, &c__0, &errind, &nis, &idum1, &idum2, &idum3, &idum4)
	    ;
    chkinq_("pqif", &errind, 4L);
    i__1 = nis;
    for (ix = 1; ix <= i__1; ++ix) {
	nqif (specwt, &ix, &c__0, &errind, &idum1, &thisis, &idum2, &idum3, &
		idum4);
	chkinq_("pqif", &errind, 4L);
	if (thisis == *rqstyl) {
	    ret_val = TRUE_;
	    return ret_val;
	}
/* L100: */
    }
    ret_val = FALSE_;
    return ret_val;
} /* intsty_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/denhat                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int denhat_(integer *strid, integer *maxh, integer *specwt, 
	integer *ihat)
#else /* NO_PROTO */
/* Subroutine */ int denhat_(strid, maxh, specwt, ihat)
integer *strid, *maxh, *specwt, *ihat;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static real xa[4], ya[4];
    static integer hs[100], ix;
#ifndef NO_PROTO
    extern /* Subroutine */ int nfa (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nfa ();
#endif /* NO_PROTO */
    static integer ans;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqif ();
#endif /* NO_PROTO */
    static integer perm[100];
    static real yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsis (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsis ();
#endif /* NO_PROTO */
    static real ytop;
    static integer idum1, idum2, idum3, idum4;
    static real yincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nsisi (integer *), nemst (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nsisi (), nemst ();
#endif /* NO_PROTO */
    static integer numhs;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnset_(integer *, integer *, integer *), 
	    nopst (integer *), dchoic_(char *, integer *, integer *, integer *
	    , ftnlen), chkinq_(char *, integer *, ftnlen), numlab_(integer *, 
	    real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnset_(), nopst (), dchoic_(), chkinq_(), 
	    numlab_();
#endif /* NO_PROTO */
    static integer errind, numlin;

/*  DENHAT displays a random selection of hatch styles and asks the */
/*  operator to select a dense one. */
/*  Input parameters: */
/*    STRID  : identifier for available closed posted structure */
/*    MAXH   : maximum number of styles to display */
/*    SPECWT : specific workstation type */
/*  Output parameters: */
/*    IHAT   : selected hatch style */
/* interior style */
    nopst (strid);
    nqif (specwt, &c__0, &c__0, &errind, &idum1, &idum2, &numhs, &idum3, &
	    idum4);
    chkinq_("pqif", &errind, 4L);
/* Computing MIN */
    i__1 = *maxh, i__2 = abs(numhs);
    numlin = min(i__1,i__2);
    i__1 = abs(numhs);
    rnset_(&numlin, &i__1, perm);
#ifndef NO_PROTO
    yincr = 1 / (numlin + 1.f);
#else /* NO_PROTO */
    yincr = 1 / (numlin + (float)1.);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    yloc = ytop;
    numlab_(&numlin, &c_b1464, &ytop, &yincr);
    nsis (&c__3);
#ifndef NO_PROTO
    xa[0] = .2f;
    xa[1] = .9f;
    xa[2] = .9f;
    xa[3] = .2f;
#else /* NO_PROTO */
    xa[0] = (float).2;
    xa[1] = (float).9;
    xa[2] = (float).9;
    xa[3] = (float).2;
#endif /* NO_PROTO */
    i__1 = numlin;
    for (ix = 1; ix <= i__1; ++ix) {
#ifndef NO_PROTO
	ya[0] = yloc + yincr * .4f;
	ya[1] = yloc + yincr * .4f;
	ya[2] = yloc - yincr * .4f;
	ya[3] = yloc - yincr * .4f;
#else /* NO_PROTO */
	ya[0] = yloc + yincr * (float).4;
	ya[1] = yloc + yincr * (float).4;
	ya[2] = yloc - yincr * (float).4;
	ya[3] = yloc - yincr * (float).4;
#endif /* NO_PROTO */
	nqif (specwt, &c__0, &perm[ix - 1], &errind, &idum1, &idum2, &idum3, &
		hs[ix - 1], &idum4);
	chkinq_("pqif", &errind, 4L);
	nsisi (&hs[ix - 1]);
	nfa (&c__4, xa, ya);
	yloc -= yincr;
/* L60: */
    }
    dchoic_("Pick a dense hatch style, preferably diagonal.", &c__1, &numlin, 
	    &ans, 46L);
    nemst (strid);
    nclst ();
    *ihat = hs[ans - 1];
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* denhat_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/numlab                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int numlab_(integer *hinum, real *rtmarg, real *ytop, real *
	yincr)
#else /* NO_PROTO */
/* Subroutine */ int numlab_(hinum, rtmarg, ytop, yincr)
integer *hinum;
real *rtmarg, *ytop, *yincr;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real u, z;
    static char d2[3];
    static integer ix;
    static real ccx, ccy, txh;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real txv, txx[2], txy[2], chht;
    static integer opid;
    static real chsp, chxp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqep (integer *, integer *), nsep (integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqep (), nsep ();
#endif /* NO_PROTO */
    static real ypos;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), nqedm (integer *, integer *), 
	    nsedm (integer *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), nqedm (), nsedm (), nclst ();
#endif /* NO_PROTO */
    static integer elptr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), unmsg_();
#endif /* NO_PROTO */
    static integer txfnt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nstxp (
	    integer *), nqtxx (integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *, char *, integer *, real *, real *
	    , real *, real *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nstxp (), nqtxx (), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer editmo, errind, labstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nschsp (real *), nschup (
	    real *, real *), nschxp (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nschsp (), nschup (), nschxp ();
#endif /* NO_PROTO */
    static integer opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxal (integer *, integer *), newstr_(
	    integer *, integer *), nqopst (integer *, integer *, integer *), 
	    nstxfn (integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxal (), newstr_(), nqopst (), nstxfn (), 
	    nstxpr ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___363 = { 0, d2, 0, "(I2,A)", 3, 1 };


/*  NUMLAB draws a sequence of numeric labels down a vertical column. */
/*  Labels are drawn in stroke precision.  A non-existent structure */
/*  is used as a substructure if there is a currently open structure, */
/*  otherwise it is used as the main structure.  If used as a */
/*  substructure, an <execute structure> element is inserted in the */
/*  main structure.  Most text attributes are set explicitly, but */
/*  text colour index is inherited. */
/*  Input parameters: */
/*    HINUM  : highest number; labels 1-HINUM are drawn. */
/*    RTMARG : right-hand margin for labels */
/*    YTOP   : vertically centered location of top label (#1) */
/*    YINCR  : vertical increment for labels */
/* open-structure status */
/* edit mode */
/* aspect source */
/*                bundled     individual */
/* text precision */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    if (*hinum < 1 || *hinum > 99) {
	unmsg_("Invalid value for HINUM in NUMLAB.", 34L);
    }
/*  save edit state, open-structure state */
    nqedm (&errind, &editmo);
    chkinq_("pqedm", &errind, 5L);
    nqopst (&errind, &opstat, &opid);
    chkinq_("pqopst", &errind, 6L);
/*  If a structure is open, save element-pointer and close structure */
    if (opstat == 1) {
	nqep (&errind, &elptr);
	chkinq_("pqep", &errind, 4L);
	nclst ();
    }
/*  get a new structure identifier */
    newstr_(&c__950, &labstr);
    nsedm (&c__0);
    nopst (&labstr);
    nemst (&labstr);
/*  set all aspects to individual */
    setasf_(&c__1);
/* USERMOD  text attributes for labels */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    txfnt = 1;
#ifndef NO_PROTO
    chsp = 0.f;
    chxp = .8f;
#else /* NO_PROTO */
    chsp = (float)0.;
    chxp = (float).8;
#endif /* NO_PROTO */
    nstxfn (&txfnt);
    nstxpr (&c__2);
    nschxp (&chxp);
    nschsp (&chsp);
    nschup (&z, &u);
    nstxp (&c__0);
    nstxal (&c__3, &c__3);
/*  adjust character height according to text-extent */
    nqtxx (&dialog_1.specwt, &txfnt, &chxp, &chsp, &c_b1309, &c__0, &c__1, &
	    c__5, "88:", &errind, txx, txy, &ccx, &ccy, 3L);
    chkinq_("pqtxx", &errind, 5L);
    txh = (r__1 = txx[0] - txx[1], dabs(r__1));
    txv = (r__1 = txy[0] - txy[1], dabs(r__1));
/*  scale down vertically or horizontally, to lower size */
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = *rtmarg * .9f / txh, r__2 = *yincr * .65f / txv;
#else /* NO_PROTO */
    r__1 = *rtmarg * (float).9 / txh, r__2 = *yincr * (float).65 / txv;
#endif /* NO_PROTO */
    chht = dmin(r__1,r__2);
    nschh (&chht);
    ypos = *ytop;
    i__1 = *hinum;
    for (ix = 1; ix <= i__1; ++ix) {
	s_wsfi(&io___363);
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
	do_fio(&c__1, ":", 1L);
	e_wsfi();
	ntx (rtmarg, &ypos, d2, 3L);
	ypos -= *yincr;
/* L100: */
    }
    nclst ();
/*  restore edit state, open-structure state */
    nsedm (&editmo);
    if (opstat == 1) {
	nopst (&opid);
	nsep (&elptr);
	nexst (&labstr);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* numlab_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/vislab                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int vislab_(char *txt, char *align, real *xlo, real *xhi, 
	real *ylo, real *yhi, ftnlen txt_len, ftnlen align_len)
#else /* NO_PROTO */
/* Subroutine */ int vislab_(txt, align, xlo, xhi, ylo, yhi, txt_len, 
	align_len)
char *txt, *align;
real *xlo, *xhi, *ylo, *yhi;
ftnlen txt_len;
ftnlen align_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer alh[5] = { 1,3,2,2,2 };
    static integer alv[5] = { 3,3,1,5,3 };

    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    real r__1, r__2;
    char ch__1[35];

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    integer i_indx();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static real u, z, ccx, ccy, txh;
#ifndef NO_PROTO
    extern /* Subroutine */ int ntx (real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int ntx ();
#endif /* NO_PROTO */
    static real txv, txx[2], txy[2], chht;
    static integer opid;
    static real chsp, chxp, xloc, yloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqep (integer *, integer *), nsep (integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int nqep (), nsep ();
#endif /* NO_PROTO */
    static integer aldex;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), nqedm (integer *, integer *), 
	    nsedm (integer *), nclst (void);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), nqedm (), nsedm (), nclst ();
#endif /* NO_PROTO */
    static integer elptr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nemst (integer *), unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nemst (), unmsg_();
#endif /* NO_PROTO */
    static integer txfnt;
#ifndef NO_PROTO
    extern /* Subroutine */ int nexst (integer *), nopst (integer *), nstxp (
	    integer *), nqtxx (integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *, char *, integer *, real *, real *
	    , real *, real *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nexst (), nopst (), nstxp (), nqtxx (), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer editmo, errind, labstr;
#ifndef NO_PROTO
    extern /* Subroutine */ int setasf_(integer *), nschsp (real *), nschup (
	    real *, real *), nschxp (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setasf_(), nschsp (), nschup (), nschxp ();
#endif /* NO_PROTO */
    static integer opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxal (integer *, integer *), newstr_(
	    integer *, integer *), nqopst (integer *, integer *, integer *), 
	    nstxfn (integer *), nstxpr (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxal (), newstr_(), nqopst (), nstxfn (), 
	    nstxpr ();
#endif /* NO_PROTO */

/*  VISLAB draws a text label within a specified box.  Labels are */
/*  drawn in stroke precision.  The text label is scaled uniformly */
/*  (aspect ratio preserved) so that it just fits in the box, and */
/*  then aligned as requested.  Thus, there may be empty space left */
/*  within the box. A new structure is used as a substructure if */
/*  there is a currently open structure, otherwise it is used as the */
/*  main structure.  If used as a substructure, an <execute */
/*  structure> element is inserted in the main structure. Most text */
/*  attributes are set explicitly, but text colour index is */
/*  inherited. */
/*  Input parameters: */
/*    TXT     : Contents of text label to be written */
/*    ALIGN   : alignment code: L,R,T,B,C for left,right,top,bottom,center
 */
/*    XLO,XHI : horizontal location for label */
/*    YLO,YHI : vertical location for label */
/* open-structure status */
/* edit mode */
/* aspect source */
/*                bundled     individual */
/* text precision */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
    aldex = i_indx("LRTBC", align, 5L, 1L);
    if (aldex <= 0) {
/* Writing concatenation */
	i__1[0] = 34, a__1[0] = "Invalid alignment code in VISLAB: ";
	i__1[1] = 1, a__1[1] = align;
	s_cat(ch__1, a__1, i__1, &c__2, 35L);
	unmsg_(ch__1, 35L);
    }
/*  save edit state, open-structure state */
    nqedm (&errind, &editmo);
    chkinq_("pqedm", &errind, 5L);
    nqopst (&errind, &opstat, &opid);
    chkinq_("pqopst", &errind, 6L);
/*  If a structure is open, save element-pointer and close structure */
    if (opstat == 1) {
	nqep (&errind, &elptr);
	chkinq_("pqep", &errind, 4L);
	nclst ();
    }
/*  set up new structure for labels */
    newstr_(&c__950, &labstr);
    nsedm (&c__0);
    nopst (&labstr);
    nemst (&labstr);
/*  set all aspects to individual */
    setasf_(&c__1);
/* USERMOD  text attributes for labels */
#ifndef NO_PROTO
    z = 0.f;
    u = 1.f;
#else /* NO_PROTO */
    z = (float)0.;
    u = (float)1.;
#endif /* NO_PROTO */
    txfnt = 1;
#ifndef NO_PROTO
    chht = 1.f;
    chsp = .1f;
    chxp = .8f;
#else /* NO_PROTO */
    chht = (float)1.;
    chsp = (float).1;
    chxp = (float).8;
#endif /* NO_PROTO */
    nstxfn (&txfnt);
    nstxpr (&c__2);
    nschxp (&chxp);
    nschsp (&chsp);
    nschup (&z, &u);
    nstxp (&c__0);
    nstxal (&alh[aldex - 1], &alv[aldex - 1]);
/*  adjust character height according to text-extent */
    nqtxx (&dialog_1.specwt, &txfnt, &chxp, &chsp, &chht, &c__0, &c__1, &c__5,
	     txt, &errind, txx, txy, &ccx, &ccy, txt_len);
    chkinq_("pqtxx", &errind, 5L);
    txh = (r__1 = txx[0] - txx[1], dabs(r__1));
    txv = (r__1 = txy[0] - txy[1], dabs(r__1));
/*  scale vertically and horizontally by same amount to fit within box. */

/* Computing MIN */
    r__1 = (*xhi - *xlo) / txh, r__2 = (*yhi - *ylo) / txv;
    chht = dmin(r__1,r__2);
    nschh (&chht);
/*  get correct alignment point - assume centered and then move */
    xloc = (*xlo + *xhi) / 2;
    yloc = (*ylo + *yhi) / 2;
    if (aldex == 1) {
	xloc = *xlo;
    }
    if (aldex == 2) {
	xloc = *xhi;
    }
    if (aldex == 3) {
	yloc = *yhi;
    }
    if (aldex == 4) {
	yloc = *ylo;
    }
    ntx (&xloc, &yloc, txt, txt_len);
    nclst ();
/*  restore edit state, open-structure state */
    nsedm (&editmo);
    if (opstat == 1) {
	nopst (&opid);
	nsep (&elptr);
	nexst (&labstr);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* vislab_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/dynpf                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int dynpf_(char *prompt, char *expctd, ftnlen prompt_len, 
	ftnlen expctd_len)
#else /* NO_PROTO */
/* Subroutine */ int dynpf_(prompt, expctd, prompt_len, expctd_len)
char *prompt, *expctd;
ftnlen prompt_len;
ftnlen expctd_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    char ch__1[34];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern logical dyn_(char *, ftnlen);
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern logical dyn_();
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static logical expy;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), opfail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), opfail_();
#endif /* NO_PROTO */

/*  DYNPF is used to ask the operator a yes/no question and issue pass */
/*  or fail as a result.  If the answer indicates failure, the operator */

/*  is given the opportunity to comment. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    EXPCTD      : expected answer (to pass) - must be y or n */
    if (*expctd == 'Y' || *expctd == 'y') {
	expy = TRUE_;
    } else if (*expctd == 'N' || *expctd == 'n') {
	expy = FALSE_;
    } else {
/* Writing concatenation */
	i__1[0] = 33, a__1[0] = "DYNPF called with invalid value: ";
	i__1[1] = 1, a__1[1] = expctd;
	s_cat(ch__1, a__1, i__1, &c__2, 34L);
	unmsg_(ch__1, 34L);
    }
    if (expy == dyn_(prompt, prompt_len)) {
	pass_();
    } else {
	opfail_();
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dynpf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/dyn                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical dyn_(char *prompt, ftnlen prompt_len)
#else /* NO_PROTO */
logical dyn_(prompt, prompt_len)
char *prompt;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_();
    extern integer itrim_();
#endif /* NO_PROTO */
    static char linein[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int opmsgw_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opmsgw_();
#endif /* NO_PROTO */
    static char msgtxt[3000];

/*  DYN is used to ask the operator a yes/no question and return */
/*  a logical value as a result: .true. for yes, .false. for no. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*  display prompt */
/* Writing concatenation */
    i__1[0] = itrim_(prompt, prompt_len), a__1[0] = prompt;
    i__1[1] = 9, a__1[1] = " (y or n)";
    s_cat(msgtxt, a__1, i__1, &c__2, 3000L);
L100:
    dline_(msgtxt, linein, 3000L, 100L);
    if (s_cmp(linein, "Y", 100L, 1L) == 0 || s_cmp(linein, "y", 100L, 1L) == 
	    0) {
	ret_val = TRUE_;
    } else if (s_cmp(linein, "N", 100L, 1L) == 0 || s_cmp(linein, "n", 100L, 
	    1L) == 0) {
	ret_val = FALSE_;
    } else {
/*  show error message in dialogue area and pause */
	opmsgw_("Response must be y or n.", 24L);
	goto L100;
    }
    return ret_val;
} /* dyn_ */

/*  There are four closely related functions all of which use */
/*  DCHOIC.  DCHPF and DCHFL both treat the response as a location */
/*  in PERM.  The value at that location is tested against TRUANS. */
/*  DCHPFV and DCHFLV both treat the response as an integer value to */
/*  be tested directly against TRUANS.  DCHPF and DCHPFV both issue */
/*  either pass or fail as a result.  DCHFL and DCHFLV both issue */
/*  fail, but not pass, and, being functions rather than subroutines, */
/*  their returned value may be used for further control. */

/*             |  location   value */
/*  -----------+------------------- */
/*  pass/fail  |  DCHPF      DCHPFV */
/*  fail only  |  DCHFL      DCHFLV */
/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/dchpf                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int dchpf_(char *prompt, integer *maxval, integer *truans, 
	integer *perm, ftnlen prompt_len)
#else /* NO_PROTO */
/* Subroutine */ int dchpf_(prompt, maxval, truans, perm, prompt_len)
char *prompt;
integer *maxval, *truans, *perm;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Local variables */
    static integer ans;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), dchoic_(char *, integer *, 
	    integer *, integer *, ftnlen), opfail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), dchoic_(), opfail_();
#endif /* NO_PROTO */

/*  DCHPF gets an integer response from the operator, to be used as */
/*  an index into PERM, and issues pass/fail as a result.  In all */
/*  cases the operator is given a choice between 0 and MAXVAL, where */
/*  0 indicates "none of the above" and triggers an operator comment. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    MAXVAL      : highest valid response. */
/*    TRUANS      : expected value from operator. */
/*    PERM        : permutation of 1-MAXVAL, used to randomize prompt. */
    /* Parameter adjustments */
    --perm;

    /* Function Body */
    dchoic_(prompt, &c__0, maxval, &ans, prompt_len);
    if (ans == 0) {
	opfail_();
    } else {
	L__1 = perm[ans] == *truans;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dchpf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/dchpfv                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int dchpfv_(char *prompt, integer *maxval, integer *truans, 
	ftnlen prompt_len)
#else /* NO_PROTO */
/* Subroutine */ int dchpfv_(prompt, maxval, truans, prompt_len)
char *prompt;
integer *maxval, *truans;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Local variables */
    static integer ans;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), dchoic_(char *, integer *, 
	    integer *, integer *, ftnlen), opfail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), dchoic_(), opfail_();
#endif /* NO_PROTO */

/*  DCHPFV operates just like DCHPF, except that the response is */
/*  tested directly against TRUANS. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    MAXVAL      : highest valid response. */
/*    TRUANS      : expected value from operator. */
    dchoic_(prompt, &c__0, maxval, &ans, prompt_len);
    if (ans == 0) {
	opfail_();
    } else {
	L__1 = ans == *truans;
	ifpf_(&L__1);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dchpfv_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/dchfl                          * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical dchfl_(char *prompt, integer *maxval, integer *truans, integer *perm, 
	ftnlen prompt_len)
#else /* NO_PROTO */
logical dchfl_(prompt, maxval, truans, perm, prompt_len)
char *prompt;
integer *maxval, *truans, *perm;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer ans;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), dchoic_(char *, integer *, 
	    integer *, integer *, ftnlen), opfail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), dchoic_(), opfail_();
#endif /* NO_PROTO */

/*  DCHFL gets an integer response from the operator, to be used as */
/*  an index into PERM, and, if the result is incorrect, issues fail */
/*  and returns TRUE.  If correct, it returns FALSE, but does not */
/*  issue pass. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    MAXVAL      : highest valid response. */
/*    TRUANS      : expected value from operator. */
/*    PERM        : permutation of 1-MAXVAL, used to randomize prompt. */
    /* Parameter adjustments */
    --perm;

    /* Function Body */
    dchoic_(prompt, &c__0, maxval, &ans, prompt_len);
    if (ans == 0) {
	ret_val = TRUE_;
	opfail_();
    } else {
	if (perm[ans] == *truans) {
	    ret_val = FALSE_;
	} else {
	    ret_val = TRUE_;
	    fail_();
	}
    }
    return ret_val;
} /* dchfl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    LOGICAL FUNCTION GL/dchflv                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
logical dchflv_(char *prompt, integer *maxval, integer *truans, ftnlen 
	prompt_len)
#else /* NO_PROTO */
logical dchflv_(prompt, maxval, truans, prompt_len)
char *prompt;
integer *maxval, *truans;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer ans;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), dchoic_(char *, integer *, 
	    integer *, integer *, ftnlen), opfail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), dchoic_(), opfail_();
#endif /* NO_PROTO */

/*  DCHFLV operates just like DCHFL, except that the response is */
/*  tested directly against TRUANS. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    MAXVAL      : highest valid response. */
/*    TRUANS      : expected value from operator. */
    dchoic_(prompt, &c__0, maxval, &ans, prompt_len);
    ret_val = ans != *truans;
    if (ans == 0) {
	opfail_();
    } else if (ret_val) {
	fail_();
    }
    return ret_val;
} /* dchflv_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/dchoic                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int dchoic_(char *prompt, integer *lolim, integer *hilim, 
	integer *ans, ftnlen prompt_len)
#else /* NO_PROTO */
/* Subroutine */ int dchoic_(prompt, lolim, hilim, ans, prompt_len)
char *prompt;
integer *lolim, *hilim, *ans;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[100];
    static integer ierr;
    static char resp[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen), 
	    opmsgw_(char *, ftnlen), prsint_(char *, integer *, integer *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_(), opmsgw_(), prsint_();
#endif /* NO_PROTO */

/*  DCHOIC is used to get an integer response from the operator. */

/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*    LOLIM,HILIM : low, high limit (inclusive) for answer. */
/*  Output parameters: */
/*    ANS         : valid answer from operator. */
L110:
/*  display prompt and get response string */
    dline_(prompt, resp, prompt_len, 100L);
    if (s_cmp(resp, " ", 100L, 1L) == 0) {
	s_copy(msg, "Response must be non-blank.", 100L, 27L);
    } else {
	prsint_(resp, ans, &ierr, 100L);
	if (ierr == 0) {
	    if (*ans >= *lolim && *ans <= *hilim) {
		s_copy(msg, "OK", 100L, 2L);
	    } else {
		s_copy(msg, "Response out of range.", 100L, 22L);
	    }
	} else {
	    s_copy(msg, "Response not an integer.", 100L, 24L);
	}
    }
    if (s_cmp(msg, "OK", 100L, 2L) == 0) {
/*        OK - do nothing */
    } else {
/*  show error message in dialogue area and pause */
	opmsgw_(msg, 100L);
	goto L110;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dchoic_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/dlstpf                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int dlstpf_(char *prompt, integer *expsiz, integer *explst, 
	char *slsw, ftnlen prompt_len, ftnlen slsw_len)
#else /* NO_PROTO */
/* Subroutine */ int dlstpf_(prompt, expsiz, explst, slsw, prompt_len, 
	slsw_len)
char *prompt;
integer *expsiz, *explst;
char *slsw;
ftnlen prompt_len;
ftnlen slsw_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3];
    logical L__1;
    char ch__1[28];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *);
    extern logical seteq_(integer *, integer *, integer *);
    extern /* Subroutine */ int unmsg_(char *, ftnlen), opfail_(void);
    extern logical iareql_(integer *, integer *, integer *, integer *);
    extern /* Subroutine */ int dilist_(char *, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_();
    extern logical seteq_();
    extern /* Subroutine */ int unmsg_(), opfail_();
    extern logical iareql_();
    extern /* Subroutine */ int dilist_();
#endif /* NO_PROTO */
    static integer anslst[100], anssiz;

/*  DLSTPF gets an integer list response from the operator, and */
/*  issues pass/fail as a result of comparing the operator response */
/*  to the expected list. A list with one element = 0 indicates "fail */
/*  - cannot answer" and triggers an operator comment. */
/*  Input parameters: */
/*    PROMPT : prompt to be sent to operator. */
/*    EXPSIZ : expected size of list */
/*    EXPLST : expected contents of list */
/*    SLSW   : S/L switch to indicate comparison by set-equality */
/*             (unordered) of list-equality (ordered) */
    /* Parameter adjustments */
    --explst;

    /* Function Body */
    dilist_(prompt, &anssiz, anslst, prompt_len);
    if (anssiz == 1 && anslst[0] == 0) {
	opfail_();
    } else {
	if (*slsw == 'L') {
	    L__1 = iareql_(&anssiz, anslst, expsiz, &explst[1]);
	    ifpf_(&L__1);
	} else if (*slsw == 'S') {
	    L__1 = anssiz == *expsiz && seteq_(&anssiz, anslst, &explst[1]);
	    ifpf_(&L__1);
	} else {
/* Writing concatenation */
	    i__1[0] = 26, a__1[0] = "DLSTPF called with SLSW = ";
	    i__1[1] = 1, a__1[1] = slsw;
	    i__1[2] = 1, a__1[2] = ".";
	    s_cat(ch__1, a__1, i__1, &c__3, 28L);
	    unmsg_(ch__1, 28L);
	}
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dlstpf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/dilist                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int dilist_(char *prompt, integer *anssiz, integer *anslst, 
	ftnlen prompt_len)
#else /* NO_PROTO */
/* Subroutine */ int dilist_(prompt, anssiz, anslst, prompt_len)
char *prompt;
integer *anssiz, *anslst;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[100];
    static integer ierr;
    static char resp[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen), 
	    iniari_(char *, integer *, integer *, integer *, ftnlen), opmsgw_(
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_(), iniari_(), opmsgw_();
#endif /* NO_PROTO */

/*  DILIST is used to get an integer-list response from the operator. */

/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*  Output parameters: */
/*    ANSSIZ      : size of list from operator. */
/*    ANSLST      : contents of list from operator */
    /* Parameter adjustments */
    --anslst;

    /* Function Body */
L110:
/*  display prompt and get response string */
    dline_(prompt, resp, prompt_len, 100L);
    if (s_cmp(resp, " ", 100L, 1L) == 0) {
	s_copy(msg, "Response must be non-blank.", 100L, 27L);
    } else if (s_cmp(resp, "N", 100L, 1L) == 0 || s_cmp(resp, "n", 100L, 1L) 
	    == 0) {
/*  null list */
	*anssiz = 0;
	s_copy(msg, "OK", 100L, 2L);
    } else {
	iniari_(resp, &anslst[1], anssiz, &ierr, 100L);
	if (ierr == 0) {
	    s_copy(msg, "OK", 100L, 2L);
	} else {
	    s_copy(msg, "Invalid list.", 100L, 13L);
	}
    }
    if (s_cmp(msg, "OK", 100L, 2L) == 0) {
/*        OK - do nothing */
    } else {
/*  show error message in dialogue area and pause */
	opmsgw_(msg, 100L);
	goto L110;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dilist_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/drlval                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int drlval_(char *prompt, real *ans, ftnlen prompt_len)
#else /* NO_PROTO */
/* Subroutine */ int drlval_(prompt, ans, prompt_len)
char *prompt;
real *ans;
ftnlen prompt_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[100];
    static integer ierr;
    static char resp[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen), 
	    prsrl_(char *, real *, integer *, ftnlen), opmsgw_(char *, ftnlen)
	    ;
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_(), prsrl_(), opmsgw_();
#endif /* NO_PROTO */

/*  DRLVAL is used to get a real-number response from the operator. */

/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*  Output parameters: */
/*    ANS         : valid answer from operator. */
L110:
/*  display prompt and get response string */
    dline_(prompt, resp, prompt_len, 100L);
    if (s_cmp(resp, " ", 100L, 1L) == 0) {
	s_copy(msg, "Response must be non-blank.", 100L, 27L);
    } else {
	prsrl_(resp, ans, &ierr, 100L);
	if (ierr == 0) {
	    s_copy(msg, "OK", 100L, 2L);
	} else {
	    s_copy(msg, "Response not a real number.", 100L, 27L);
	}
    }
    if (s_cmp(msg, "OK", 100L, 2L) == 0) {
/*        OK - do nothing */
    } else {
/*  show error message in dialogue area and pause */
	opmsgw_(msg, 100L);
	goto L110;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* drlval_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/dline                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int dline_(char *prompt, char *resp, ftnlen prompt_len, 
	ftnlen resp_len)
#else /* NO_PROTO */
/* Subroutine */ int dline_(prompt, resp, prompt_len, resp_len)
char *prompt, *resp;
ftnlen prompt_len;
ftnlen resp_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int iacans_(char *, ftnlen), iacmsg_(char *, 
	    ftnlen), opcomt_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int iacans_(), iacmsg_(), opcomt_();
#endif /* NO_PROTO */

/*  DLINE issues a prompt to the operator and gets a single line */
/*  character string response.  If the operator responds with */
/*  the escape character "@", DLINE allows entry of a non-committal */
/*  operator comment (neither pass nor fail), to be sent out as */
/*  an OP message, and then re-issues the original prompt. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*  Output parameters: */
/*    RESP        : answer from operator. */
L100:
    iacmsg_(prompt, prompt_len);
    iacans_(resp, resp_len);
/*  allow operator-requested comment. */
    if (s_cmp(resp, "@", resp_len, 1L) == 0) {
	opcomt_();
	goto L100;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* dline_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/opfail                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int opfail_(void)
#else /* NO_PROTO */
/* Subroutine */ int opfail_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), opcofl_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), opcofl_();
#endif /* NO_PROTO */

/*  OPFAIL allows the operator to enter a character string as a */
/*  comment, by using OPCO, and then issues a failure. */
    opcofl_();
    fail_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opfail_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/opcofl                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int opcofl_(void)
#else /* NO_PROTO */
/* Subroutine */ int opcofl_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int opco_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opco_();
#endif /* NO_PROTO */

/*  OPCOFL allows the operator to enter a character string as a */
/*  comment, by using OPCO.  The comment is made in anticipation */
/*  of failure of the current test case. */
    opco_("on failure", 10L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opcofl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/opcomt                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int opcomt_(void)
#else /* NO_PROTO */
/* Subroutine */ int opcomt_()
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int opco_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int opco_();
#endif /* NO_PROTO */

/*  OPCOMT allows the operator to enter a character string as a */
/*  comment, by using OPCO.  No presumption is made about passing */
/*  or failing. */
    opco_(" ", 1L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opcomt_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/opco                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int opco_(char *topic, ftnlen topic_len)
#else /* NO_PROTO */
/* Subroutine */ int opco_(topic, topic_len)
char *topic;
ftnlen topic_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2], a__2[4], a__3[3];
    integer i__1[2], i__2[4], i__3[3];
    char ch__1[1204];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    integer s_cmp();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static char resp[900];
    static integer oplen;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int brdmsg_(char *, ftnlen), dstrng_(char *, char 
	    *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int brdmsg_(), dstrng_();
#endif /* NO_PROTO */
    static char prompt[300];

/*  OPCO allows the operator to enter a character string as a */
/*  comment, which is then generated as an OP-type message. */
/*  If there is a current topical heading, it is prefixed to */
/*  the string. */
    oplen = itrim_(opcomm_1.ophead, 300L) + 1;
    if (s_cmp(topic, " ", topic_len, 1L) == 0) {
/* Writing concatenation */
	i__1[0] = oplen, a__1[0] = opcomm_1.ophead;
	i__1[1] = 17, a__1[1] = "Operator comment?";
	s_cat(prompt, a__1, i__1, &c__2, 300L);
    } else {
/* Writing concatenation */
	i__2[0] = oplen, a__2[0] = opcomm_1.ophead;
	i__2[1] = 17, a__2[1] = "Operator comment ";
	i__2[2] = topic_len, a__2[2] = topic;
	i__2[3] = 1, a__2[3] = "?";
	s_cat(prompt, a__2, i__2, &c__4, 300L);
    }
    dstrng_(prompt, resp, 300L, 900L);
    if (s_cmp(resp, " ", 900L, 1L) != 0) {
/* Writing concatenation */
	i__3[0] = 4, a__3[0] = "OP: ";
	i__3[1] = oplen, a__3[1] = opcomm_1.ophead;
	i__3[2] = 900, a__3[2] = resp;
	s_cat(ch__1, a__3, i__3, &c__3, 1204L);
	brdmsg_(ch__1, oplen + 904);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opco_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/dstrng                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int dstrng_(char *prompt, char *resp, ftnlen prompt_len, 
	ftnlen resp_len)
#else /* NO_PROTO */
/* Subroutine */ int dstrng_(prompt, resp, prompt_len, resp_len)
char *prompt, *resp;
ftnlen prompt_len;
ftnlen resp_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp(), i_len();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int iacans_(char *, ftnlen), iacmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int iacans_(), iacmsg_();
#endif /* NO_PROTO */
    static char linein[200];
    static integer nxtpos;

/*  DSTRNG is used to get possibly multi-line character string */
/*  response from the operator.  Operator response is terminated */
/*  by a single "." on a line.  This termination line is not */
/*  included in the response. */
/*  Input parameters: */
/*    PROMPT      : prompt to be sent to operator. */
/*  Output parameters: */
/*    RESP        : answer from operator. */
/*  display prompt */
    iacmsg_(prompt, prompt_len);
    nxtpos = 1;
    s_copy(resp, " ", resp_len, 1L);
L100:
/*  get response string */
    iacans_(linein, 200L);
    if (s_cmp(linein, ".", 200L, 1L) == 0) {
	goto L200;
    }
/*  append last line to non-blank stuff in RESP */
    s_copy(resp + (nxtpos - 1), linein, resp_len - (nxtpos - 1), 200L);
    nxtpos = itrim_(resp, resp_len) + 2;
/*  check if at or near overflow ... */
    if (nxtpos + 5 < i_len(resp, resp_len)) {
	goto L100;
    }
L200:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* dstrng_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/opmsgw                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int opmsgw_(char *msg, ftnlen msg_len)
#else /* NO_PROTO */
/* Subroutine */ int opmsgw_(msg, msg_len)
char *msg;
ftnlen msg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static char pmsg[999], resp[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int dline_(char *, char *, ftnlen, ftnlen);
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int dline_();
    extern integer itrim_();
#endif /* NO_PROTO */

/*  OPMSGW sends a character string (MSG) to the operator in */
/*  accordance with DOUTYP.  It then waits for a response, to ensure */
/*  that the message has been read. */
/* Writing concatenation */
    i__1[0] = itrim_(msg, msg_len), a__1[0] = msg;
    i__1[1] = 29, a__1[1] = "  Enter anything to continue.";
    s_cat(pmsg, a__1, i__1, &c__2, 999L);
    dline_(pmsg, resp, 999L, 80L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* opmsgw_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/iacmsg                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int iacmsg_(char *msgtxt, ftnlen msgtxt_len)
#else /* NO_PROTO */
/* Subroutine */ int iacmsg_(msgtxt, msgtxt_len)
char *msgtxt;
ftnlen msgtxt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1, r__2;

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen), i_len(char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
#else /* NO_PROTO */
    integer i_indx(), i_len();
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi(), s_wsle(), do_lio(), e_wsle();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ma, mb;
    static real xa[10], ya[10];
    static integer ix;
    static real tm3[9]	/* was [3][3] */, scf;
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static char msg[300];
    static integer err;
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl (), ntx ();
#endif /* NO_PROTO */
    static integer opid;
    static real chsp;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqep (integer *, integer *),  nmsg (integer *, 
	    char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqep (),  nmsg ();
#endif /* NO_PROTO */
    static real rdum;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsep (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsep ();
#endif /* NO_PROTO */
    static real copx, copy, xmax;
    static integer outl;
    static real extx[2], exty[2], ypos;
    static integer iline;
#ifndef NO_PROTO
    extern /* Subroutine */ int nschh (real *), nqedm (integer *, integer *), 
	    nsedm (integer *), nbltm (real *, real *, real *, real *, real *, 
	    real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschh (), nqedm (), nsedm (), nbltm ();
#endif /* NO_PROTO */
    static real loghw;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer elptr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), unmsg_(char *, ftnlen), nemst (
	    integer *), nslmt (real *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), unmsg_(), nemst (), nslmt ();
#endif /* NO_PROTO */
    static integer txfnt;
    static real xsize, ysize;
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsvwi (integer *), nstxp (
	    integer *), nqtxx (integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *, char *, integer *, real *, real *
	    , real *, real *, ftnlen), scapar_(integer *, real *, real *, 
	    integer *, integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsvwi (), nstxp (), nqtxx (), 
	    scapar_();
#endif /* NO_PROTO */
    static integer colloc;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer editmo;
#ifndef NO_PROTO
    extern /* Subroutine */ int linbrk_(char *, integer *, integer *, integer 
	    *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int linbrk_();
#endif /* NO_PROTO */
    static integer errind, opstat, numlin, linpos[90];
    static real chwrat;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqopst (integer *, integer *, integer *), 
	    setasf_(integer *), nsplci (integer *), setrvs_(char *, real *, 
	    integer *, ftnlen), nstxfn (integer *), nstxpr (integer *), 
	    nschxp (real *), nschsp (real *), nstxci (integer *), nschup (
	    real *, real *), nstxal (integer *, integer *), fitpar_(char *, 
	    real *, real *, integer *, ftnlen), pstctl_(integer *), nseplb (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqopst (), setasf_(), nsplci (), setrvs_(), 
	    nstxfn (), nstxpr (), nschxp (), nschsp (), nstxci (), nschup (), 
	    nstxal (), fitpar_(), pstctl_(), nseplb ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___415 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static cilist io___435 = { 0, 6, 0, 0, 0 };


/*  IACMSG sends a character string (MSGTXT) to the operator in */
/*  accordance with DOUTYP.  For DOUTYP 3 IACMSG formats MSGTXT */
/*  into structure #DSTRID. For DOUTYP 1 OR 2 IACMSG simply breaks up */
/*  MSGTXT into the specified line-length and sends out each line */
/*  via PRINT or MESSAGE, respectively. */
/*  If the MSGTXT looks like a topical heading for a test case (caps */
/*  followed by ":"), then the heading is saved in a common area */
/*  shared with OPCO, so the operator's comments are tagged. */
/* aspect source */
/*                bundled     individual */
/* open-structure status */
/* edit mode */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/* text precision */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/*  put MSGTXT in OPHEAD if it's a topical header for a test case. */
/*  look for colon location */
    colloc = i_indx(msgtxt, ":", msgtxt_len, 1L);
    if (colloc <= 0) {
	goto L100;
    }
/* Computing MIN */
    i__2 = 10, i__3 = i_len(msgtxt, msgtxt_len);
    i__1 = min(i__2,i__3);
    for (ix = 1; ix <= i__1; ++ix) {
/*  treat as non-header if first 10 chars not all caps or digits or sp
aces */
	if (i_indx("ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789", msgtxt + (ix - 1),
		 37L, 1L) <= 0) {
	    goto L100;
	}
/* L50: */
    }
    s_copy(opcomm_1.ophead, msgtxt, 300L, colloc);
L100:
    if (dialog_1.doutyp == 1 || dialog_1.doutyp == 2) {
/*  if direct output, skip initialization of structure (DSTRID) */
/*  for dialogue. */
	goto L110;
    } else if (dialog_1.doutyp == 3) {
/*        OK - do nothing */
    } else {
	s_wsfi(&io___415);
	do_fio(&c__1, "Invalid output type in IACMSG: ", 31L);
	do_fio(&c__1, (char *)&dialog_1.dintyp, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  save edit state, open-structure state */
    nqedm (&errind, &editmo);
    chkinq_("pqedm", &errind, 5L);
    nqopst (&errind, &opstat, &opid);
    chkinq_("pqopst", &errind, 6L);
/*  If a structure is open, save element-pointer and close structure */
    if (opstat == 1) {
	if (opid == dialog_1.dstrid) {
	    unmsg_("IACMSG found dialogue structure open.", 37L);
	}
	nqep (&errind, &elptr);
	chkinq_("pqep", &errind, 4L);
	nclst ();
    }
    nsedm (&c__0);
    nopst (&dialog_1.dstrid);
    nemst (&dialog_1.dstrid);
    nsvwi (&c__2);
/*  set all aspects to individual */
    setasf_(&c__1);
/*  outline dialogue area */
    nsplci (&dialog_1.dtxci);
    setrvs_("0,0,1,1,0", xa, &outl, 9L);
    setrvs_("0,0,0,0,0", ya, &outl, 9L);
    ya[1] = dialog_1.dyxrat;
    ya[2] = dialog_1.dyxrat;
    npl (&c__5, xa, ya);
/*  mark start of text elements in structure */
    nlb (&c__101);
/* USERMOD  text attributes for dialogue */
    txfnt = 1;
#ifndef NO_PROTO
    chsp = .1f;
#else /* NO_PROTO */
    chsp = (float).1;
#endif /* NO_PROTO */
    nstxfn (&txfnt);
    nstxpr (&c__2);
    nschxp (&c_b1309);
    nschsp (&chsp);
    nstxci (&dialog_1.dtxci);
    nschh (&c_b1309);
    nschup (&c_b1307, &c_b1309);
    nstxp (&c__0);
    nstxal (&c__1, &c__1);
/* USERMOD  Control character height/width ratio for dialogue here: if */
/* USERMOD  characters too skinny, decrease, if too fat, increase. */
#ifndef NO_PROTO
    chwrat = 2.5f;
#else /* NO_PROTO */
    chwrat = (float)2.5;
#endif /* NO_PROTO */
/*  calculate line-size, for a paragraph based on desired */
/*  character body height/width ratio */
    fitpar_(msgtxt, &chwrat, &dialog_1.dyxrat, &dialog_1.dtclim, msgtxt_len);
#ifndef NO_PROTO
    ypos = 0.f;
    xmax = 0.f;
#else /* NO_PROTO */
    ypos = (float)0.;
    xmax = (float)0.;
#endif /* NO_PROTO */
L110:
/*  break up MSGTXT into DTCLIM-size chunks - get array of */
/*  line starting positions */
    linbrk_(msgtxt, &dialog_1.dtclim, &err, &numlin, linpos, msgtxt_len);
    if (numlin >= 90) {
	unmsg_("Too many lines computed by IACMSG.", 34L);
    }
/*  send each line to screen or print or message, as specified */
    i__1 = numlin;
    for (iline = 1; iline <= i__1; ++iline) {
/*  MA and MB point to substring within MSGTXT to be output */
	ma = linpos[iline - 1];
	mb = itrim_(msgtxt, linpos[iline] - 1);
	if (dialog_1.doutyp == 1) {
	    s_wsle(&io___435);
	    do_lio(&c__9, &c__1, msgtxt + (ma - 1), mb - (ma - 1));
	    e_wsle();
	} else if (dialog_1.doutyp == 2) {
	     nmsg (&globnu_1.wkid, msgtxt + (ma - 1), mb - (ma - 1));
	} else {
/*  write MSGTXT into prompt area - WC = x:0-1, y:0-DYXRAT */
	    ntx (&c_b1307, &ypos, msgtxt + (ma - 1), mb - (ma - 1));
/*  keep track of widest line and vertical position */
	    nqtxx (&dialog_1.specwt, &txfnt, &c_b1309, &chsp, &c_b1309, &c__0,
		     &c__1, &c__1, msgtxt + (ma - 1), &errind, extx, exty, &
		    copx, &copy, mb - (ma - 1));
	    chkinq_("pqtxx", &errind, 5L);
	    xsize = (r__1 = extx[0] - extx[1], dabs(r__1));
	    ysize = (r__1 = exty[0] - exty[1], dabs(r__1));
	    xmax = dmax(xmax,xsize);
/* USERMOD  Control separation of dialogue lines here - if too cro
wded, */
/* USERMOD  increase coefficient of YSIZE, if too sparse, decrease
. */
#ifndef NO_PROTO
	    ypos -= ysize * 1.02f;
#else /* NO_PROTO */
	    ypos -= ysize * (float)1.02;
#endif /* NO_PROTO */
	}
/* L200: */
    }
    if (dialog_1.scrmod == 3) {
/*  make sure dialogue is posted */
	pstctl_(&c__2);
    } else if (dialog_1.scrmod == 0) {
/*  post picture only */
	pstctl_(&c__1);
    } else {
/*  split screen - post dialogue and picture */
	pstctl_(&c__3);
    }
/*  if direct output, we're done */
    if (dialog_1.doutyp != 3) {
	return 0;
    }
/*  Text written into rectangle with x-bounds = 0:xmax, */
/*  y-bounds = ypos:0. Must transform to fit into 0:1, 0:dyxrat */
/*  rectangle, with scaling adjusted for CHWRAT = character */
/*  height/width ratio. */
    scapar_(&dialog_1.dtclim, &chwrat, &dialog_1.dyxrat, &numlin, linpos, &
	    rdum, &loghw);
/* Computing MIN */
#ifndef NO_PROTO
    r__1 = 1.f, r__2 = dialog_1.dyxrat / loghw;
    scf = dmin(r__1,r__2) * .94f;
#else /* NO_PROTO */
    r__1 = (float)1., r__2 = dialog_1.dyxrat / loghw;
    scf = dmin(r__1,r__2) * (float).94;
#endif /* NO_PROTO */
    r__1 = scf / xmax;
    r__2 = -(doublereal)scf * loghw / ypos;
    nbltm (&c_b1307, &c_b1307, &c_b1637, &dialog_1.dyxrat, &c_b1307, &r__1, &
	    r__2, &errind, tm3);
    chkinq_("pbltm", &errind, 5L);
/*  insert transformation just before text elements */
    nsep (&c__1);
    nseplb (&c__101);
    nslmt (tm3, &c__2);
    nclst ();
/*  restore edit state, open-structure state */
    nsedm (&editmo);
    if (opstat == 1) {
	nopst (&opid);
	nsep (&elptr);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* iacmsg_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/iacans                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int iacans_(char *resp, ftnlen resp_len)
#else /* NO_PROTO */
/* Subroutine */ int iacans_(resp, resp_len)
char *resp;
ftnlen resp_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_wsfi(icilist *), e_wsfi(void), i_len(char *, ftnlen), s_cmp(
	    char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfi(), e_wsfi(), i_len(), s_cmp()
	    ;
#endif /* NO_PROTO */

    /* Local variables */
    static char msg[100];
#ifndef NO_PROTO
    extern /* Subroutine */ int nuwk (integer *, integer *), unmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nuwk (), unmsg_();
#endif /* NO_PROTO */
    static integer lostr;
#ifndef NO_PROTO
    extern /* Subroutine */ int nrqst (integer *, integer *, integer *, 
	    integer *, char *, ftnlen);
    extern integer leadnb_(char *, ftnlen);
    extern /* Subroutine */ int pstctl_(integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nrqst ();
    extern integer leadnb_();
    extern /* Subroutine */ int pstctl_();
#endif /* NO_PROTO */
    static integer rqstat;

    /* Fortran I/O blocks */
    static cilist io___446 = { 0, 5, 0, "(A)", 0 };
    static icilist io___450 = { 0, msg, 0, "(A,I5)", 100, 1 };
    static icilist io___451 = { 0, msg, 0, "(A,I5)", 100, 1 };


/*  IACANS gets a single-line character string response (RESP) from */
/*  the operator in accordance with DINTYP.  For DINTYP 1, IACANS */
/*  simply issues a Fortran read statement. For DINTYP 2, IACANS */
/*  invokes the PHIGS <request string> function.  If the response */
/*  is non-blank, leading blanks are deleted. */
/* regeneration flag */
/* input device status */
L100:
/*  force screen update */
    nuwk (&globnu_1.wkid, &c__1);
    s_copy(resp, " ", resp_len, 1L);
/*  get response */
    if (dialog_1.dintyp == 1) {
	s_rsfe(&io___446);
	do_fio(&c__1, resp, resp_len);
	e_rsfe();
    } else if (dialog_1.dintyp == 2) {
	nrqst (&globnu_1.wkid, &dialog_1.dstdnr, &rqstat, &lostr, resp, 
		resp_len);
	if (rqstat != 1) {
	    s_wsfi(&io___450);
	    do_fio(&c__1, "Non-OK status from <request string>: ", 37L);
	    do_fio(&c__1, (char *)&rqstat, (ftnlen)sizeof(integer));
	    e_wsfi();
	    unmsg_(msg, 100L);
	}
/*  ensure trailing blanks */
	if (lostr < i_len(resp, resp_len)) {
	    i__1 = lostr;
	    s_copy(resp + i__1, " ", resp_len - i__1, 1L);
	}
    } else {
	s_wsfi(&io___451);
	do_fio(&c__1, "Invalid input type in IACANS: ", 30L);
	do_fio(&c__1, (char *)&dialog_1.dintyp, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 100L);
    }
/*  delete leading blanks */
    if (s_cmp(resp, " ", resp_len, 1L) != 0) {
	i__1 = leadnb_(resp, resp_len) - 1;
	s_copy(resp, resp + i__1, resp_len, resp_len - i__1);
    }
/*  check for toggling */
    if (dialog_1.scrmod == 3 && (s_cmp(resp, "T", resp_len, 1L) == 0 || s_cmp(
	    resp, "t", resp_len, 1L) == 0)) {
	pstctl_(&c__4);
	goto L100;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* iacans_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/setasf                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int setasf_(integer *flag__)
#else /* NO_PROTO */
/* Subroutine */ int setasf_(flag__)
integer *flag__;
#endif /* NO_PROTO */
{
    static integer aspect;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsiasf (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsiasf ();
#endif /* NO_PROTO */

/*  SETASF sets all ASF flags to the same value, either individual or */
/*  bundled. */
/* aspect identifier */
    for (aspect = 0; aspect <= 17; ++aspect) {
	nsiasf (&aspect, flag__);
/* L50: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setasf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/pstctl                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int pstctl_(integer *ctl)
#else /* NO_PROTO */
/* Subroutine */ int pstctl_(ctl)
integer *ctl;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer postat = 0;
#ifndef NO_PROTO
    static char act[4*4*5] = "n   " "Up  " "Ud  " "UpUd" "Pp  " "n   " "UdPp" 
	    "Ud  " "Pd  " "UpPd" "n   " "Up  " "PpPd" "Pd  " "Pp  " "n   " 
	    "Pd  " "UpPd" "UdPp" "Up  ";
#else /* NO_PROTO */
    static char act[4*4*5+1] = "n   Up  Ud  UpUdPp  n   UdPpUd  Pd  UpPdn   \
Up  PpPdPd  Pp  n   Pd  UpPdUdPpUp  ";
#endif /* NO_PROTO */

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_cmp(), i_indx();
#endif /* NO_PROTO */

    /* Local variables */
    static char doact[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int npost (integer *, integer *, real *), nupost (
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npost (), nupost ();
#endif /* NO_PROTO */

/*  PSTCTL controls the posting of structures. */
/*  CTL function */
/*  --- -------- */
/*   0  unpost both picture and dialogue structure */
/*   1  post picture only */
/*   2  post dialogue only */
/*   3  post both */
/*   4  switch picture/dialogue posting; dialogue if neither or both */
/*  POSTAT keeps track of current posting status: */
/*  POSTAT  status */
/*  ------  ------ */
/*     0    neither posted */
/*     1    picture posted */
/*     2    dialogue posted */
/*     3    both posted */
/*  action table: what to do based on POSTAT and CTL */
/*                POSTAT: 0         1        2        3 */
    s_copy(doact, act + (postat + (*ctl << 2) << 2), 4L, 4L);
    if (s_cmp(doact, "n", 4L, 1L) == 0) {
	return 0;
    }
    if (i_indx(doact, "Up", 4L, 2L) > 0) {
	nupost (&globnu_1.wkid, &dialog_1.pstrid);
    }
    if (i_indx(doact, "Ud", 4L, 2L) > 0) {
	nupost (&globnu_1.wkid, &dialog_1.dstrid);
    }
    if (i_indx(doact, "Pp", 4L, 2L) > 0) {
	npost (&globnu_1.wkid, &dialog_1.pstrid, &c_b1307);
    }
    if (i_indx(doact, "Pd", 4L, 2L) > 0) {
	npost (&globnu_1.wkid, &dialog_1.dstrid, &c_b1309);
    }
    if (*ctl == 4) {
	if (postat == 2) {
	    postat = 1;
	} else {
	    postat = 2;
	}
    } else {
	postat = *ctl;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* pstctl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/fitpar                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int fitpar_(char *msgtxt, real *chwrat, real *phwrat, 
	integer *linsiz, ftnlen msgtxt_len)
#else /* NO_PROTO */
/* Subroutine */ int fitpar_(msgtxt, chwrat, phwrat, linsiz, msgtxt_len)
char *msgtxt;
real *chwrat, *phwrat;
integer *linsiz;
ftnlen msgtxt_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    double sqrt(doublereal);
#else /* NO_PROTO */
    double sqrt();
#endif /* NO_PROTO */

    /* Local variables */
    static integer err;
    static real chht1, chht2, loghw;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int scapar_(integer *, real *, real *, integer *, 
	    integer *, real *, real *), linbrk_(char *, integer *, integer *, 
	    integer *, integer *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int scapar_(), linbrk_();
#endif /* NO_PROTO */
    static integer lenmsg, minlin, numlin, linpos[300], sizsav;

/*  FITPAR calculates a reasonably good line size (number of characters) 
*/
/*  for fitting MSGTXT into a rectangular area. */
/*  Input parameters: */
/*    MSGTXT : Text to be fit */
/*    CHWRAT : Desired height/width ratio of each character */
/*    PHWRAT : Height/width ratio of area to hold paragraph */
/*  Output parameters: */
/*    LINSIZ : Number of characters per line */
/*  let: */
/*    #chars = #lines * chars-per-line */
/*    char-height = phwrat/#lines */
/*    char-width  = 1/chars-per-line */
/*    char-height/char-width = CHWRAT */
/*  then */
/*    chars-per-line = sqrt(CHWRAT*#chars / phwrat) */
    lenmsg = itrim_(msgtxt, msgtxt_len);
/*  3 is fudge factor, because there won't be perfect packing. */
    *linsiz = sqrt(*chwrat * lenmsg / *phwrat) + 3;
/*  15 is minimum tolerable line-length */
    minlin = 15;
    *linsiz = max(minlin,*linsiz);
/*  Generate line-breaks for LINSIZ: */
    linbrk_(msgtxt, linsiz, &err, &numlin, linpos, msgtxt_len);
/*  get resulting character height */
    scapar_(linsiz, chwrat, phwrat, &numlin, linpos, &chht1, &loghw);
/*  alter LINSIZ for attempted better fit */
    sizsav = *linsiz;
    if (loghw > *phwrat && numlin == 2) {
/*  2-line message is too tall ... force to 1 line */
	*linsiz = lenmsg;
    } else {
/*  try to converge on proper height/width ratio for paragraph */
	*linsiz = *linsiz * loghw / *phwrat;
    }
    *linsiz = max(minlin,*linsiz);
/*  Generate line-breaks for 2nd LINSIZ: */
    linbrk_(msgtxt, linsiz, &err, &numlin, linpos, msgtxt_len);
/*  get 2nd resulting character height */
    scapar_(linsiz, chwrat, phwrat, &numlin, linpos, &chht2, &loghw);
/*  If 2nd attempt generated smaller characters, re-set to 1st, */
/*  otherwise leave LINSIZ as is. */
    if (chht1 > chht2) {
	*linsiz = sizsav;
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* fitpar_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/linbrk                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int linbrk_(char *msgtxt, integer *dtclim, integer *err, 
	integer *numlin, integer *linpos, ftnlen msgtxt_len)
#else /* NO_PROTO */
/* Subroutine */ int linbrk_(msgtxt, dtclim, err, numlin, linpos, msgtxt_len)
char *msgtxt;
integer *dtclim, *err, *numlin, *linpos;
ftnlen msgtxt_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer stlin;
#ifndef NO_PROTO
    extern integer leadnb_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer leadnb_();
#endif /* NO_PROTO */
    static integer lenmsg, nxtpos;

/*  LINBRK calculates starting positions within a character string so */
/*  as to break it up into lines of at most DTCLIM characters. LINBRK */
/*  tries to break lines only on blanks, and it constructs the */
/*  longest line possible within the DTCLIM limit.  It returns the */
/*  number of lines in NUMLIN, and the starting positions within */
/*  LINPOS.  An "extra" position is calculated after the last line, */
/*  pointing just beyond the last non-blank, so that the location of */
/*  the end of the last line is available.  If a single word */
/*  (contiguous non-blanks) is longer than DTCLIM, it is broken up */
/*  after DTCLIM characters, and ERR is set to 1. */
/*  Input parameters: */
/*    MSGTXT : character string to be broken up */
/*    DTCLIM : maximum number of characters in each chunk */
/*  Output parameters: */
/*    ERR    : error code: 0 if OK, 1 if line overflow */
/*    NUMLIN : number of logical lines found in MSGTXT */
/*    LINPOS : array of starting positions of lines within MSGTXT */
    /* Parameter adjustments */
    --linpos;

    /* Function Body */
    *err = 0;
    *numlin = 0;
    if (s_cmp(msgtxt, " ", msgtxt_len, 1L) == 0) {
	return 0;
    }
    lenmsg = itrim_(msgtxt, msgtxt_len);
    nxtpos = 1;
L100:
/*  seek next non-blank */
    stlin = leadnb_(msgtxt + (nxtpos - 1), msgtxt_len - (nxtpos - 1));
/*  get absolute position of line-starting non-blank */
    stlin = stlin + nxtpos - 1;
/*  record starting position */
    ++(*numlin);
    linpos[*numlin] = stlin;
/*  any non-blanks beyond this line? */
    if (lenmsg - stlin < *dtclim) {
	linpos[*numlin + 1] = lenmsg + 1;
	return 0;
    }
    i__1 = stlin;
    for (nxtpos = stlin + *dtclim; nxtpos >= i__1; --nxtpos) {
	if (msgtxt[nxtpos - 1] == ' ') {
	    goto L100;
	}
/* L200: */
    }
/*  no space within line */
    *err = 1;
    nxtpos = stlin + *dtclim;
    goto L100;
} /* linbrk_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/scapar                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int scapar_(integer *dtclim, real *chwrat, real *dyxrat, 
	integer *numlin, integer *linpos, real *chht, real *loghw)
#else /* NO_PROTO */
/* Subroutine */ int scapar_(dtclim, chwrat, dyxrat, numlin, linpos, chht, 
	loghw)
integer *dtclim;
real *chwrat, *dyxrat;
integer *numlin, *linpos;
real *chht, *loghw;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real r__1, r__2;

    /* Local variables */
    static real loght, logwid;

/*  SCAPAR calculates the needed scaling factor and logical */
/*  height/width ratio of a paragraph, given a line break-up. */
/*  Input parameters: */
/*    DTCLIM : maximum number of characters per line */
/*    CHWRAT : desired height/width ratio of each character */
/*    DYXRAT : height/width ratio of paragraph area */
/*    NUMLIN : number of logical lines in paragraph */
/*    LINPOS : array of starting positions of lines within MSGTXT */
/*  Output parameters: */
/*    CHHT   : resulting character height */
/*    LOGHW  : logical height/width ratio of resulting paragraph */
    /* Parameter adjustments */
    --linpos;

    /* Function Body */
    if (*numlin > 1) {
	logwid = (real) (*dtclim);
    } else {
	logwid = (real) (linpos[2] - 1);
    }
    loght = *numlin * *chwrat;
    *loghw = loght / logwid;
/*  1/LOGWID takes effect for a "full" multi-line paragraph. */
/* DYXRAT/LOGHT takes effect for a partially-filled single-line paragraph.
*/
/* Computing MIN */
    r__1 = 1 / logwid, r__2 = *dyxrat / loght;
    *chht = dmin(r__1,r__2);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* scapar_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION GL/ylocel                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal ylocel_(integer *yth)
#else /* NO_PROTO */
doublereal ylocel_(yth)
integer *yth;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

/*  YLOCEL returns the appropriate y-coordinate in WC for element */
/*  number YTH, when comparing pairs of elements for traversal */
/*  saving and restoring. */
#ifndef NO_PROTO
    ret_val = (15 - *yth) / 15.f;
#else /* NO_PROTO */
    ret_val = (15 - *yth) / (float)15.;
#endif /* NO_PROTO */
    return ret_val;
} /* ylocel_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/rn1shf                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int rn1shf_(integer *siz, integer *perm)
#else /* NO_PROTO */
/* Subroutine */ int rn1shf_(siz, perm)
integer *siz, *perm;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer swvals[4] = { 5,6,11,12 };

    static integer ix, iy, hdx, ldx, tmp, swloc;
#ifndef NO_PROTO
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static integer needvl;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnperm_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnperm_();
#endif /* NO_PROTO */

/*  Incredibly special-purpose subroutine which returns a permutation in 
*/
/*  PERM with the constraint that: */

/*     PERM(12) - PERM(11) = PERM(06) - PERM(05) */

/*  so as to force uniform scaling.  This is needed in inheritance tests 
*/
/*  when displaying primitives with an intrinsic size, such as fill area 
*/
/*  or text, as opposed to a single segment of a polyline or a single */
/*  polymarker. */
    /* Parameter adjustments */
    --perm;

    /* Function Body */
    rnperm_(siz, &perm[1]);
/*  put locations of 5,6,11,12 in ascending order */
    for (ix = 1; ix <= 3; ++ix) {
	for (iy = ix + 1; iy <= 4; ++iy) {
	    ldx = swvals[ix - 1];
	    hdx = swvals[iy - 1];
	    if (perm[ldx] > perm[hdx]) {
		tmp = perm[ldx];
		perm[ldx] = perm[hdx];
		perm[hdx] = tmp;
	    }
/* L300: */
	}
/* L200: */
    }
/*  switch values for shortest interval */
    if (perm[6] - perm[5] < perm[12] - perm[11]) {
/*  switch contents of PERM(11) with needed value */
	needvl = perm[12] + perm[5] - perm[6];
	swloc = 11;
    } else {
/*  switch contents of PERM(5) with needed value */
	needvl = perm[11] + perm[6] - perm[12];
	swloc = 5;
    }
    perm[iarfnd_(&needvl, siz, &perm[1])] = perm[swloc];
    perm[swloc] = needvl;
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* rn1shf_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/rnperm                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int rnperm_(integer *size, integer *perm)
#else /* NO_PROTO */
/* Subroutine */ int rnperm_(size, perm)
integer *size, *perm;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ix, swap;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static integer ranpos;

/*  RNPERM returns a random permutation of integers 1-SIZE in PERM. */
/*  For example, if SIZE is specified as 4, PERM might = [2,3,1,4]. */
    /* Parameter adjustments */
    --perm;

    /* Function Body */
    i__1 = *size;
    for (ix = 1; ix <= i__1; ++ix) {
	perm[ix] = ix;
/* L100: */
    }
    for (ix = *size; ix >= 2; --ix) {
	ranpos = rndint_(&c__1, &ix);
	swap = perm[ix];
	perm[ix] = perm[ranpos];
	perm[ranpos] = swap;
/* L200: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* rnperm_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/rnset                                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int rnset_(integer *size, integer *maxmem, integer *set)
#else /* NO_PROTO */
/* Subroutine */ int rnset_(size, maxmem, set)
integer *size, *maxmem, *set;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int rnbset_(integer *, integer *, integer *, 
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnbset_();
#endif /* NO_PROTO */

/* RNSET returns a random set of SIZE distinct integers, chosen from */
/* the universe of 1-MAXMEM, returned in SET.  For example, if SIZE is */
/* specified as 4, and MAXMEM as 7, SET might = [2,5,7,4]. */
    /* Parameter adjustments */
    --set;

    /* Function Body */
    rnbset_(size, &c__1, maxmem, &set[1]);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* rnset_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE GL/rnbset                               * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int rnbset_(integer *size, integer *lo, integer *hi, integer 
	*set)
#else /* NO_PROTO */
/* Subroutine */ int rnbset_(size, lo, hi, set)
integer *size, *lo, *hi, *set;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ix, iy;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
    extern integer rndint_();
#endif /* NO_PROTO */

/*  RNBSET returns a random set of SIZE distinct integers, chosen from */
/*  the universe of LO-HI (inclusive), returned in SET.  For example, */
/*  if SIZE is specified as 4, LO=3 and HI=10, SET might = [9,5,7,4]. */
    /* Parameter adjustments */
    --set;

    /* Function Body */
    if (*size > *hi - *lo + 1) {
	unmsg_("In RNBSET, size of set exceeds universe.", 40L);
    }
    i__1 = *size;
    for (ix = 1; ix <= i__1; ++ix) {
L110:
	set[ix] = rndint_(lo, hi);
	i__2 = ix - 1;
	for (iy = 1; iy <= i__2; ++iy) {
	    if (set[ix] == set[iy]) {
		goto L110;
	    }
/* L200: */
	}
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* rnbset_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    INTEGER FUNCTION GL/rndint                         * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
integer rndint_(integer *lo, integer *hi)
#else /* NO_PROTO */
integer rndint_(lo, hi)
integer *lo, *hi;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#ifndef NO_PROTO
    extern doublereal rnd01_(void);
#else /* NO_PROTO */
    extern doublereal rnd01_();
#endif /* NO_PROTO */

/*  RNDINT returns a random integer value between LO and HI, */
/*  inclusive. */
    ret_val = (integer) (rnd01_() * (*hi + 1 - *lo) + *lo);
    return ret_val;
} /* rndint_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION GL/rndrl                             * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
doublereal rndrl_(real *lo, real *hi)
#else /* NO_PROTO */
doublereal rndrl_(lo, hi)
real *lo, *hi;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
#ifndef NO_PROTO
    extern doublereal rnd01_(void);
#else /* NO_PROTO */
    extern doublereal rnd01_();
#endif /* NO_PROTO */

/*  RNDRL returns a random real number, X, uniformly distributed, */
/*  such that LO .LE. X .LT. HI. */
    ret_val = rnd01_() * (*hi - *lo) + *lo;
    return ret_val;
} /* rndrl_ */

/*  ********************************************************* */
/*  *                                                       * */
/*  *    REAL FUNCTION GL/rnd01                             * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */

/* MANUAL change here: */

#include <stdio.h>
#include <time.h>

/* end MANUAL change */


#ifndef NO_PROTO
doublereal rnd01_(void)
#else /* NO_PROTO */
doublereal rnd01_()
#endif /* NO_PROTO */
{
    /* Initialized data */

    static logical first = TRUE_;
    static doublereal factor = .53736255218;
    static doublereal addend = .63535248281;

    /* System generated locals */
    real ret_val;

    /* Local variables */
    static doublereal x;
    static integer ix;
#ifndef NO_PROTO
    extern doublereal secnds_(real *);
#else /* NO_PROTO */
    extern doublereal secnds_();
#endif /* NO_PROTO */

/*  RND01 returns a random real number, X, uniformly distributed, */
/*  such that 0 .LE. X .LT. 1. */
/*  This is a very low-grade random number generator; it should be */
/*  portable except for the call to SECNDS. */
    if (first) {
	first = FALSE_;
#ifndef NO_PROTO
	if (ranctl_1.rlseed < .1f || ranctl_1.rlseed > .9f) {
#else /* NO_PROTO */
	if (ranctl_1.rlseed < (float).1 || ranctl_1.rlseed > (float).9) {
#endif /* NO_PROTO */
/* ********************************************************* */

/* USERMOD  put in a time function to initialize X (true randomiza
tion) */

/* ********************************************************* */

/* MANUAL change here: 
	    x = secnds_(&c_b1307);
*/
	    x = time(NULL);

/* paranoid code here */
            if (x == 0)
               unmsg_ ("Random seed set by time function to zero.", 41L);
            
            if (x < 0) x = -x;
            while (x > 1000)
               x /= 10.2645;
            while (x < 0.001)
               x *= 10.2645;

/* end MANUAL change */

/* ********************************************************* */

/* USERMOD  End of customization */

/* ********************************************************* */
	} else {
/*  pseudo-random sequence - seed taken from configuration file */

	    x = ranctl_1.rlseed;
	}
    }
#ifndef NO_PROTO
    x = (x * factor + addend) * 97.8272f;
#else /* NO_PROTO */
    x = (x * factor + addend) * (float)97.8272;
#endif /* NO_PROTO */
    ix = (integer) x;
    x -= ix;
    ret_val = x;
    return ret_val;
} /* rnd01_ */

