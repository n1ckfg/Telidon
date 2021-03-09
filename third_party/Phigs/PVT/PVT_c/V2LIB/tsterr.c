/* tsterr.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__3 = 3;

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
    static icilist io___7 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___8 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___9 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___15 = { 0, msg, 0, "(A,I6.3,A)", 160, 1 };
    static icilist io___16 = { 0, msg, 0, "(A,I4.3,A,I4.3,A)", 160, 1 };
    static icilist io___17 = { 0, msg, 0, "(A,I4.3,A,I4.3,A)", 160, 1 };
    static icilist io___26 = { 0, msg, 0, "(A,I6.3,A)", 160, 1 };
    static icilist io___27 = { 0, msg, 0, "(A,I4.3,A,I4.3,A)", 160, 1 };


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
	    s_wsfi(&io___7);
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
	s_wsfi(&io___8);
	do_fio(&c__1, (char *)&errinf_1.experr[errinf_1.expsiz - 1], (ftnlen)
		sizeof(integer));
	e_wsfi();
	i__2 = itrim_(tmsg, 500L) + 1;
	s_copy(tmsg + i__2, acode, 500 - i__2, 4L);
	s_wsfi(&io___9);
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
	s_wsfi(&io___15);
	do_fio(&c__1, "Reported error number ", 22L);
	do_fio(&c__1, (char *)&errinf_1.errcom, (ftnlen)sizeof(integer));
	do_fio(&c__1, " is not one of the expected values.", 35L);
	e_wsfi();
	inmsg_(msg, 160L);
    }
    if (! funok) {
	s_wsfi(&io___16);
	do_fio(&c__1, "Reported function identifier ", 29L);
	do_fio(&c__1, (char *)&errinf_1.funcom, (ftnlen)sizeof(integer));
	do_fio(&c__1, " does not match expected function identifier ", 45L);
	do_fio(&c__1, (char *)&(*expfun), (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	inmsg_(msg, 160L);
    }
    if (! filok) {
	s_wsfi(&io___17);
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
	    s_wsfi(&io___26);
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
	    s_wsfi(&io___27);
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

