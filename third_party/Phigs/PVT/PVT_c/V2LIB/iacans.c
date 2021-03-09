/* iacans.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__1 = 1;
static integer c__4 = 4;

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
    static cilist io___1 = { 0, 5, 0, "(A)", 0 };
    static icilist io___5 = { 0, msg, 0, "(A,I5)", 100, 1 };
    static icilist io___6 = { 0, msg, 0, "(A,I5)", 100, 1 };


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
	s_rsfe(&io___1);
	do_fio(&c__1, resp, resp_len);
	e_rsfe();
    } else if (dialog_1.dintyp == 2) {
	nrqst (&globnu_1.wkid, &dialog_1.dstdnr, &rqstat, &lostr, resp, 
		resp_len);
	if (rqstat != 1) {
	    s_wsfi(&io___5);
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
	s_wsfi(&io___6);
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

