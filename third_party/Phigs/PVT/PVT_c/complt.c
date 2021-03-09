/* fort//complt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 00/complt                             * */
/*  *    TEST TITLE : Completion check                      * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
/*  FILE: COMPLT.FOR */
/*  This program checks the global message file for the presence of */
/*  an "End execution" message from every appropriate program in the */
/*  PHIGS validation suite. */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_800[] = "(a)";

    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer f_open(olist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_rew(alist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void), s_rsle(cilist *), e_rsle(void), i_indx(
	    char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    integer f_open(), s_wsle(), do_lio(), e_wsle();
    /* Subroutine */ int s_stop();
    integer f_rew(), s_rsfe(), do_fio(), e_rsfe(), s_rsle(), e_rsle(), i_indx(
	    );
    /* Subroutine */ int s_copy();
    integer s_cmp();
    /* Subroutine */ int s_cat();
    integer f_clos();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer f_clos(cllist *);

#endif /* not NO_PROTO */
    /* Local variables */
    static integer enx;
    static char mkey[17];
    static integer ptot;
    static char oicat[2];
    static integer glbun, wkcat, ioerr;
    static char pgmno[17*400];
    static integer pgmun;
    static char glfnam[60], pgmrec[100];
    static integer firstb, langsw;
    static logical gotpgm[400];

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 6, 0, 0, 0 };
    static cilist io___4 = { 0, 6, 0, 0, 0 };
    static cilist io___5 = { 0, 6, 0, 0, 0 };
    static cilist io___6 = { 0, 6, 0, 0, 0 };
    static cilist io___7 = { 0, 5, 0, fmt_800, 0 };
    static cilist io___10 = { 0, 6, 0, 0, 0 };
    static cilist io___11 = { 0, 6, 0, 0, 0 };
    static cilist io___12 = { 0, 6, 0, 0, 0 };
    static cilist io___13 = { 0, 5, 0, 0, 0 };
    static cilist io___15 = { 0, 6, 0, 0, 0 };
    static cilist io___16 = { 0, 6, 0, 0, 0 };
    static cilist io___17 = { 0, 5, 0, 0, 0 };
    static cilist io___20 = { 0, 0, 1, fmt_800, 0 };
    static cilist io___23 = { 0, 6, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, 0, 0 };
    static cilist io___28 = { 0, 0, 1, fmt_800, 0 };
    static cilist io___31 = { 0, 6, 0, 0, 0 };
    static cilist io___32 = { 0, 6, 0, 0, 0 };
    static cilist io___33 = { 0, 6, 0, 0, 0 };


/* L800: */
    pgmun = 22;
    o__1.oerr = 1;
    o__1.ounit = pgmun;
    o__1.ofnmlen = 12;
    o__1.ofnm = "pgm-char.prt";
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsle(&io___3);
#ifndef NO_PROTO
	do_lio(&c__9, &c__1, "OPEN failed for program title file, error code"
		" = ", 49L);
#else /* NO_PROTO */
	do_lio(&c__9, &c__1, "OPEN failed for program title file, error code\
 = ", 49L);
#endif /* NO_PROTO */
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    al__1.aerr = 1;
    al__1.aunit = pgmun;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsle(&io___4);
#ifndef NO_PROTO
	do_lio(&c__9, &c__1, "REWIND failed for program title file, error co"
		"de = ", 51L);
#else /* NO_PROTO */
	do_lio(&c__9, &c__1, "REWIND failed for program title file, error co\
de = ", 51L);
#endif /* NO_PROTO */
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    s_wsle(&io___5);
    do_lio(&c__9, &c__1, "Enter the name of the global message file ", 42L);
    e_wsle();
    s_wsle(&io___6);
    do_lio(&c__9, &c__1, "to be checked for completeness.", 31L);
    e_wsle();
    s_rsfe(&io___7);
    do_fio(&c__1, glfnam, 60L);
    e_rsfe();
    glbun = 21;
    o__1.oerr = 1;
    o__1.ounit = glbun;
    o__1.ofnmlen = 60;
    o__1.ofnm = glfnam;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsle(&io___10);
#ifndef NO_PROTO
	do_lio(&c__9, &c__1, "OPEN failed for global message file, error cod"
		"e = ", 50L);
#else /* NO_PROTO */
	do_lio(&c__9, &c__1, "OPEN failed for global message file, error cod\
e = ", 50L);
#endif /* NO_PROTO */
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
    al__1.aerr = 1;
    al__1.aunit = glbun;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsle(&io___11);
#ifndef NO_PROTO
	do_lio(&c__9, &c__1, "REWIND failed for global message file, error c"
		"ode = ", 52L);
#else /* NO_PROTO */
	do_lio(&c__9, &c__1, "REWIND failed for global message file, error c\
ode = ", 52L);
#endif /* NO_PROTO */
	do_lio(&c__3, &c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", 0L);
    }
L110:
    s_wsle(&io___12);
    do_lio(&c__9, &c__1, "Language binding? 1:Fortran, 2:C", 32L);
    e_wsle();
    s_rsle(&io___13);
    do_lio(&c__3, &c__1, (char *)&langsw, (ftnlen)sizeof(integer));
    e_rsle();
    if (langsw < 1 || langsw > 2) {
	goto L110;
    }
L120:
    s_wsle(&io___15);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "Subset of PVT, based on primary workstation catego"
	    "ry?", 53L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "Subset of PVT, based on primary workstation catego\
ry?", 53L);
#endif /* NO_PROTO */
    e_wsle();
    s_wsle(&io___16);
#ifndef NO_PROTO
    do_lio(&c__9, &c__1, "1:All tests, 2:OUTIN only, 3:OUTPUT only, 4:INPUT "
	    "only", 54L);
#else /* NO_PROTO */
    do_lio(&c__9, &c__1, "1:All tests, 2:OUTIN only, 3:OUTPUT only, 4:INPUT \
only", 54L);
#endif /* NO_PROTO */
    e_wsle();
    s_rsle(&io___17);
    do_lio(&c__3, &c__1, (char *)&wkcat, (ftnlen)sizeof(integer));
    e_rsle();
    if (wkcat < 1 || wkcat > 4) {
	goto L120;
    }
/*  loop to fill PGMNO table from program title file */
    ptot = 0;
L200:
    io___20.ciunit = pgmun;
    i__1 = s_rsfe(&io___20);
    if (i__1 != 0) {
	goto L266;
    }
    i__1 = do_fio(&c__1, pgmrec, 100L);
    if (i__1 != 0) {
	goto L266;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L266;
    }
    if (i_indx(pgmrec, "/", 100L, 1L) != 13) {
	goto L200;
    }
    if (*pgmrec != '0' && *pgmrec != '1') {
	goto L200;
    }
/*  filter out unneeded workstation categories */
    s_copy(oicat, pgmrec + 19, 2L, 2L);
    if (wkcat == 2 && s_cmp(oicat, "nn", 2L, 2L) == 0) {
	goto L200;
    }
    if (wkcat == 3 && s_cmp(oicat, "yn", 2L, 2L) != 0) {
	goto L200;
    }
    if (wkcat == 4 && s_cmp(oicat, "ny", 2L, 2L) != 0) {
	goto L200;
    }
/*  filter out language-specific programs, assuming only Fortran or C */
/*  tests exist, e.g. not Ada - no 11.03 */
    if (langsw == 1) {
/*  This is Fortran - get rid of C modules */
	if (s_cmp(pgmrec, "11.02", 5L, 5L) == 0) {
	    goto L200;
	}
	if (s_cmp(pgmrec, "09.01.11", 8L, 8L) == 0) {
	    goto L200;
	}
	if (s_cmp(pgmrec, "09.02.11", 8L, 8L) == 0) {
	    goto L200;
	}
    }
    if (langsw == 2) {
/*  This is C - get rid of Fortran modules */
	if (s_cmp(pgmrec, "11.01", 5L, 5L) == 0) {
	    goto L200;
	}
	if (s_cmp(pgmrec, "09.01.10", 8L, 8L) == 0) {
	    goto L200;
	}
	if (s_cmp(pgmrec, "09.02.10", 8L, 8L) == 0) {
	    goto L200;
	}
    }
    ++ptot;
    if (ptot > 400) {
	s_wsle(&io___23);
	do_lio(&c__9, &c__1, "Number of programs exceeds internal table size;"
		, 47L);
	e_wsle();
	s_wsle(&io___24);
	do_lio(&c__9, &c__1, "increase PGMLIM.", 16L);
	e_wsle();
	s_stop("", 0L);
    }
/*  add entry to table of required programs */
    firstb = i_indx(pgmrec, " ", 100L, 1L) - 1;
/* Writing concatenation */
    i__2[0] = firstb, a__1[0] = pgmrec;
    i__2[1] = 1, a__1[1] = "/";
    i__2[2] = 2, a__1[2] = pgmrec + 15;
    s_cat(pgmno + (ptot - 1) * 17, a__1, i__2, &c__3, 17L);
    gotpgm[ptot - 1] = FALSE_;
    goto L200;
/*  end loop: table of required programs now complete */
L266:
    cl__1.cerr = 0;
    cl__1.cunit = pgmun;
    cl__1.csta = 0;
    f_clos(&cl__1);
/*  loop to check message file against PGMNO table */
L300:
    io___28.ciunit = glbun;
    i__1 = s_rsfe(&io___28);
    if (i__1 != 0) {
	goto L366;
    }
    i__1 = do_fio(&c__1, pgmrec, 100L);
    if (i__1 != 0) {
	goto L366;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L366;
    }
    enx = i_indx(pgmrec, "End execution of PVT #", 100L, 22L);
    if (enx <= 0) {
	goto L300;
    }
    i__1 = enx + 21;
    s_copy(mkey, pgmrec + i__1, 17L, 100 - i__1);
    i__1 = ptot;
    for (enx = 1; enx <= i__1; ++enx) {
	if (s_cmp(pgmno + (enx - 1) * 17, mkey, 17L, 17L) == 0) {
/*  found pgm# */
	    gotpgm[enx - 1] = TRUE_;
	    goto L300;
	}
/* L310: */
    }
/*  not found - strange ... */
    s_wsle(&io___31);
    do_lio(&c__9, &c__1, "No reference record in the program title file was ",
	     50L);
    e_wsle();
    s_wsle(&io___32);
    do_lio(&c__9, &c__1, "found for message from program #", 32L);
    do_lio(&c__9, &c__1, mkey, 17L);
    e_wsle();
    goto L300;
L366:
    i__1 = ptot;
    for (enx = 1; enx <= i__1; ++enx) {
	if (! gotpgm[enx - 1]) {
	    s_wsle(&io___33);
	    do_lio(&c__9, &c__1, "No \"End execution\" found for program #", 
		    38L);
	    do_lio(&c__9, &c__1, pgmno + (enx - 1) * 17, 17L);
	    e_wsle();
	}
/* L400: */
    }
    cl__1.cerr = 0;
    cl__1.cunit = glbun;
    cl__1.csta = 0;
    f_clos(&cl__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

#ifndef NO_PROTO
/* Main program alias */ int complt_ () { MAIN__ (); return 0; }
#else /* NO_PROTO */
/* Main program alias */ int complt_ () { MAIN__ (); }
#endif /* NO_PROTO */
