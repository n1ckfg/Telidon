/* prsrl.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;
static integer c__3 = 3;
static integer c__1 = 1;

#ifndef NO_PROTO
/* Subroutine */ int prsrl_(char *str, real *rval, integer *ierr, ftnlen 
	str_len)
#else /* NO_PROTO */
/* Subroutine */ int prsrl_(str, rval, ierr, str_len)
char *str;
real *rval;
integer *ierr;
ftnlen str_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2], a__2[3];
    integer i__1[2], i__2[3];

    /* Builtin functions */
#ifndef NO_PROTO
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(void)
	    ;
#else /* NO_PROTO */
    integer i_indx();
    /* Subroutine */ int s_cat(), s_copy();
    integer s_rsfi(), do_fio(), e_rsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static char wstr[18];
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
#endif /* NO_PROTO */
    static integer szstr, posdec, posexp;

    /* Fortran I/O blocks */
    static icilist io___5 = { 1, wstr, 1, "(F18.2)", 18, 1 };


/*  Prsrl parses a real number.  Assumes no leading spaces. */
/*  The value is returned in RVAL, and IERR gets a non-zero code */
/*  if something goes wrong. */
    szstr = itrim_(str, str_len);
#ifndef NO_PROTO
    *rval = -666.666f;
#else /* NO_PROTO */
    *rval = (float)-666.666;
#endif /* NO_PROTO */
    if (szstr > 15) {
	*ierr = -3;
	return 0;
    }
    posdec = i_indx(str, ".", str_len, 1L);
    if (posdec <= 0) {
/* No explicit decimal */
	posexp = i_indx(str, "E", str_len, 1L);
	if (posexp <= 0) {
/* No explicit exponent */
/* Writing concatenation */
	    i__1[0] = szstr, a__1[0] = str;
	    i__1[1] = 2, a__1[1] = ".0";
	    s_cat(wstr, a__1, i__1, &c__2, 18L);
	} else {
/* Writing concatenation */
	    i__2[0] = posexp - 1, a__2[0] = str;
	    i__2[1] = 2, a__2[1] = ".0";
	    i__2[2] = szstr - (posexp - 1), a__2[2] = str + (posexp - 1);
	    s_cat(wstr, a__2, i__2, &c__3, 18L);
	}
	szstr += 2;
    } else {
/* Explicit decimal */
	s_copy(wstr, str, 18L, str_len);
    }
    *ierr = s_rsfi(&io___5);
    if (*ierr != 0) {
	goto L100001;
    }
    *ierr = do_fio(&c__1, (char *)&(*rval), (ftnlen)sizeof(real));
    if (*ierr != 0) {
	goto L100001;
    }
    *ierr = e_rsfi();
L100001:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* prsrl_ */

