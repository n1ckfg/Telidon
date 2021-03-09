/* elstr.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__50 = 50;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int elstr_(integer *strid, char *strg, ftnlen strg_len)
#else /* NO_PROTO */
/* Subroutine */ int elstr_(strid, strg, strg_len)
integer *strid;
char *strg;
ftnlen strg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    icilist ici__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer rl, str;
    static real rlar[50];
    static integer intg, strl[50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *, integer *, char *, ftnlen), ncmsg_(char *, 
	    ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeco (), ncmsg_();
#endif /* NO_PROTO */
    static integer rllen, intar[50], elpos, stlen;
    static char strar[80*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqets (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), chkinq_(char *, 
	    integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqets (), chkinq_();
#endif /* NO_PROTO */
    static integer errind, intlen, nxchar, eltype, iexist;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

/*     Input Parameter: */
/*     INTEGER strid              structure identifier */
/*     Output Parameter: */
/*     CHARACTER strg             string identifying element types */
/*                                and contents for strid */
/*  Elstr returns the character string STRG which contains integer-like */

/*  substrings separated by commas. The substrings of STRG represent an */

/*  ordered listing of label identifiers and execute structure identifiers
 */
/*  used to indicate the structure element positions of a particular */
/*  structure in the network. */
/*  e.g. The structure 110 creates STRG = "66, 111, 66, 120, 67, 901" */
/*             <open structure> 110 */
/*             <execute structure> 111 */
/*             <execute structure> 120 */
/*             <label> 901 */
/*             <close structure> */
/* PHIGS enumeration parameter for PEEXST and PELB */
/* structure status indicator   non-existent, empty,      non-empty */
/* array length parameter values */
/* initialize values */
    s_copy(strg, " ", strg_len, 1L);
    nxchar = 1;
    elpos = 1;
/* check the status of the structure */
    nqstst (strid, &errind, &iexist);
    chkinq_("pqstst", &errind, 6L);
    if (iexist == 0 || iexist == 1) {
	return 0;
    }
/* create the string STRG for the network structure STRID */
L900:
    nqets (strid, &elpos, &errind, &eltype, &intlen, &rllen, &stlen);
    if (errind != 0) {
	goto L950;
    }
    nqeco (strid, &elpos, &c__50, &c__50, &c__50, &errind, &intg, intar, &rl, 
	    rlar, &str, strl, strar, 80L);
    chkinq_("pqeco", &errind, 5L);
    if (eltype == 66 || eltype == 67) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 3;
	ici__1.iciunit = strg + (nxchar - 1);
	ici__1.icifmt = "(I2, A)";
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&eltype, (ftnlen)sizeof(integer));
	do_fio(&c__1, ",", 1L);
	e_wsfi();
	nxchar += 3;
    } else {
	ncmsg_("Problem with the element type in subroutine elstr.", 50L);
    }
    ici__1.icierr = 0;
    ici__1.icirnum = 1;
    ici__1.icirlen = 4;
    ici__1.iciunit = strg + (nxchar - 1);
    ici__1.icifmt = "(I3, A)";
    s_wsfi(&ici__1);
    do_fio(&c__1, (char *)&intar[0], (ftnlen)sizeof(integer));
    do_fio(&c__1, ",", 1L);
    e_wsfi();
    nxchar += 4;
    ++elpos;
    goto L900;
L950:
    i__1 = nxchar - 2;
    s_copy(strg + i__1, " ", strg_len - i__1, 1L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* elstr_ */

