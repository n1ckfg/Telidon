/* esetup.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
     static void  (*current_handler_1)
                     (Pint error_num, Pint func_num, char *error_file);
#else /* NO_PROTO */
     static void  (*current_handler_1)();
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

