/* enderr.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;

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
    static icilist io___4 = { 0, msg, 0, "(A,I7,A)", 200, 1 };
    static icilist io___6 = { 0, msg, 0, "(A,I7,A)", 200, 1 };
    static icilist io___7 = { 0, msg, 0, "(A,I7,A)", 200, 1 };
    static icilist io___10 = { 0, msg, 0, "(A,I7,A)", 200, 1 };
    static icilist io___11 = { 0, msg, 0, "(A,I7,A)", 200, 1 };


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
	    s_wsfi(&io___4);
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
		s_wsfi(&io___6);
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
	    s_wsfi(&io___7);
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
	    s_wsfi(&io___10);
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
	    s_wsfi(&io___11);
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

