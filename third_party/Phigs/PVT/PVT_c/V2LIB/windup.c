/* windup.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__9 = 9;
static integer c__5 = 5;
static integer c__2 = 2;

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
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
    integer s_cmp(), f_clos();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_clos(cllist *);

#endif /* not NO_PROTO */
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
    static icilist io___4 = { 0, aerrct, 0, "(I3)", 3, 1 };
    static icilist io___6 = { 0, atstct, 0, "(I3)", 3, 1 };
    static icilist io___9 = { 0, aerrct, 0, "(I3)", 3, 1 };


/*  Windup handles end-of-test processing - it formulates two */
/*  messages, one with the total error count, the second to proclaim */
/*  end of execution.  If there has been an unanticipated error it */
/*  also generates a message for that.  It then closes the error */
/*  files, as needed.  It is normally the last thing called by a */
/*  test. */
    s_copy(err, " errors", 7L, 7L);
    s_copy(cword, " conditions", 11L, 11L);
    s_wsfi(&io___4);
    do_fio(&c__1, (char *)&globnu_1.ierrct, (ftnlen)sizeof(integer));
    e_wsfi();
    s_wsfi(&io___6);
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
	s_wsfi(&io___9);
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

