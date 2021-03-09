/* pf.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

/* Table of constant values */

static integer c__1 = 1;
static integer c__5 = 5;

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
    static icilist io___2 = { 0, acond, 0, "(I3)", 3, 1 };


/*  pf handles the processing of the pass/fail condition. */
    if (! (*result == 'p' || *result == 'f')) {
	unmsg_("Input parameter to pf neither p nor f.", 38L);
    }
    if (s_cmp(globch_1.tstmsg, " ", 900L, 1L) == 0) {
	unmsg_("Blank tstmsg detected by pf.  Program logic error.", 50L);
    }
    ++globnu_1.testct;
    s_wsfi(&io___2);
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

