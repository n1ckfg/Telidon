/* setstr.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;

#ifndef NO_PROTO
/* Subroutine */ int setstr_(integer *strid, char *strg, ftnlen strg_len)
#else /* NO_PROTO */
/* Subroutine */ int setstr_(strid, strg, strg_len)
integer *strid;
char *strg;
ftnlen strg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[3];
    integer i__1[3], i__2;
    char ch__1[33];

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen), s_wsfi(icilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfi(void);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    integer s_cmp(), i_indx(), s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat(), s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int nlb (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nlb ();
#endif /* NO_PROTO */
    static integer ival, ierr, wlen;
    static char wstr[700];
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *), unmsg_(char *
	    , ftnlen), nexst (integer *), nopst (integer *), deblnk_(char *, 
	    char *, integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst (), unmsg_(), nexst (), 
	    nopst (), deblnk_();
#endif /* NO_PROTO */
    static integer ncomma;
#ifndef NO_PROTO
    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int chkinq_();
#endif /* NO_PROTO */
    static integer errind, opstid, opstat;
#ifndef NO_PROTO
    extern /* Subroutine */ int prsint_(char *, integer *, integer *, ftnlen),
	     nqopst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int prsint_(), nqopst ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___9 = { 0, wstr, 0, "(A,I4,A)", 700, 1 };


/*  Setstr is used to set the contents of a single structure. */

/*  Strid is the identifier of the structure to be set. */
/*  Strg is a string representing a list of letter-integer pairs, */
/*  separated by commas, which are interpreted as type-content pairs. */
/*  A blank string may be used to designate an empty structure.  The */
/*  only two valid letters are L (for LABEL) and E (for EXECUTE */
/*  STRUCTURE). E.g. the string "L11,E101,L901" indicates that the */
/*  structure is to contain 3 elements: LABEL 11, EXECUTE STRUCTURE */
/*  101 and LABEL 901.  Blanks are ignored. */
/*  The specified structure is left closed.  If another structure is */
/*  originally open, it is closed. */
/*  open-structure status */
/* de-blank string */
    deblnk_(strg, wstr, &wlen, strg_len, 700L);
    ++wlen;
    wstr[wlen - 1] = ',';
/*  check open structure */
    nqopst (&errind, &opstat, &opstid);
    chkinq_("pqopst", &errind, 6L);
    if (opstat == 1) {
	nclst ();
    }
/*  set up empty structure */
    nemst (strid);
    nopst (strid);
L100:
    if (s_cmp(wstr, " ", 700L, 1L) == 0) {
	goto L600;
    }
    ncomma = i_indx(wstr, ",", 700L, 1L);
    prsint_(wstr + 1, &ival, &ierr, ncomma - 2);
    if (ierr != 0) {
	s_wsfi(&io___9);
	do_fio(&c__1, "SETSTR got error code ", 22L);
	do_fio(&c__1, (char *)&ierr, (ftnlen)sizeof(integer));
	do_fio(&c__1, " from PRSINT.", 13L);
	e_wsfi();
	unmsg_(wstr, 700L);
    }
    if (*wstr == 'L') {
	nlb (&ival);
    } else if (*wstr == 'E') {
	nexst (&ival);
    } else {
/* Writing concatenation */
	i__1[0] = 14, a__1[0] = "Illegal code: ";
	i__1[1] = 1, a__1[1] = wstr;
	i__1[2] = 18, a__1[2] = " passed to SETSTR.";
	s_cat(ch__1, a__1, i__1, &c__3, 33L);
	unmsg_(ch__1, 33L);
    }
    i__2 = ncomma;
    s_copy(wstr, wstr + i__2, 700L, 700 - i__2);
    goto L100;
L600:
    nclst ();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* setstr_ */

