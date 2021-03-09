/* initgl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* MANUAL CHANGE HERE: */
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

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c_n1 = -1;

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
#else /* NO_PROTO */
    integer s_wsle(), do_lio(), e_wsle();
    /* Subroutine */ int s_stop(), s_copy();
    integer f_open(), f_rew(), s_rsue(), do_uio(), e_rsue(), f_clos(), s_rsfe(
	    ), do_fio(), e_rsfe(), f_back();
    /* Subroutine */ int s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen);

#endif /* not NO_PROTO */
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
   extern void pvt_err_hand        (Pint errnr_act, Pint funccd_act, char *fn);
   void (*current_handler_1)(Pint errnr_act, Pint funccd_act, char *fn);
#else /* NO_PROTO */
   extern void pvt_err_hand ();
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

/* USERMOD  NOTE: The following must be initialized to the absolute file */
/* USERMOD  name for the system configuration file.  This must be */
/* USERMOD  customized for each installation.  See the MULTWS */
/* USERMOD  subroutine, immediately below, and also the INITPH */
/* USERMOD  program which writes the file. */

/* ********************************************************** */
    s_copy(filenm, "/home/cugini/pvt/work/v2.1/c/INITPH.DAT", 60L, 39L);
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

/* USERMOD  

To make append work more efficiently, if desired, change the following
to system-specific magic code which will open the global message file
and position it after the last record, to allow new records to be
added.  The routine above seems to be the only Fortran-standard way to
do it.

*/

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

