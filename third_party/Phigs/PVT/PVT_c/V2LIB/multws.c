/* multws.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__9 = 9;

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
    static icilist io___9 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static icilist io___10 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static cilist io___11 = { 1, 0, 1, 0, 0 };
    static icilist io___14 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static cilist io___15 = { 1, 0, 1, 0, 0 };
    static icilist io___24 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static cilist io___25 = { 1, 0, 1, 0, 0 };
    static icilist io___30 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static cilist io___31 = { 1, 0, 1, 0, 0 };
    static icilist io___35 = { 0, msg, 0, "(A,I3,A,I8)", 300, 1 };
    static icilist io___41 = { 0, msg, 0, "(A,I8)", 300, 1 };
    static icilist io___42 = { 0, msg, 0, "(A,I5)", 300, 1 };


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

/* USERMOD  NOTE: The following must be initialized to the absolute file */
/* USERMOD  name for the system configuration file.  This must be */
/* USERMOD  customized for each installation.  See the INITGL */
/* USERMOD  subroutine, immediately above, and also the INITPH */
/* USERMOD  program which writes the file. */

/* ********************************************************** */
    s_copy(filenm, "/home/cugini/pvt/work/v2.1/c/INITPH.DAT", 60L, 39L);
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
	s_wsfi(&io___9);
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
	s_wsfi(&io___10);
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
    io___11.ciunit = lun;
    ioerr = s_rsue(&io___11);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = do_uio(&c__1, (char *)&dumi[0], (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = do_uio(&c__1, dumc2, 20L);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = e_rsue();
L100001:
    if (ioerr != 0) {
	s_wsfi(&io___14);
/* Writing concatenation */
	i__1[0] = 30, a__1[0] = errprf;
	i__1[1] = 10, a__1[1] = "READ #1 = ";
	s_cat(ch__3, a__1, i__1, &c__2, 40L);
	do_fio(&c__1, ch__3, 40L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
    io___15.ciunit = lun;
    ioerr = s_rsue(&io___15);
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&doutyp, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dtclim, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dintyp, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dstdnr, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&dsize, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&efrac, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&scrmod, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = do_uio(&c__1, (char *)&mtrpdc, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100002;
    }
    ioerr = e_rsue();
L100002:
    if (ioerr != 0) {
	s_wsfi(&io___24);
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
    io___25.ciunit = lun;
    ioerr = s_rsue(&io___25);
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__9, (char *)&dumi[0], (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, dumc1, 60L);
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__2, (char *)&dumj[0], (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&nwksav, (ftnlen)sizeof(integer));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = do_uio(&c__1, (char *)&dumr, (ftnlen)sizeof(real));
    if (ioerr != 0) {
	goto L100003;
    }
    ioerr = e_rsue();
L100003:
    if (ioerr != 0) {
	s_wsfi(&io___30);
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
	io___31.ciunit = lun;
	ioerr = s_rsue(&io___31);
	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = do_uio(&c__1, (char *)&mwkid[i - 1], (ftnlen)sizeof(integer));

	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = do_uio(&c__1, (char *)&mconid[i - 1], (ftnlen)sizeof(integer))
		;
	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = do_uio(&c__1, (char *)&mwtype[i - 1], (ftnlen)sizeof(integer))
		;
	if (ioerr != 0) {
	    goto L100004;
	}
	ioerr = e_rsue();
L100004:
	if (ioerr != 0) {
	    s_wsfi(&io___35);
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
	s_wsfi(&io___41);
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
	s_wsfi(&io___42);
	do_fio(&c__1, "Requested workstation out of range in MULTWS:", 45L);
	do_fio(&c__1, (char *)&(*iwk), (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* multws_ */

