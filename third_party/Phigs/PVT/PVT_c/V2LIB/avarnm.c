/* avarnm.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__2 = 2;

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
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi(), f_inqu();
    /* Subroutine */ int s_cat();
    integer f_open();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer f_open(olist *);

#endif /* not NO_PROTO */
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
    static icilist io___6 = { 0, arnmch+3, 0, "(I5.5)", 5, 1 };


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
	s_wsfi(&io___6);
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

