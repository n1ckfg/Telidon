/* strcon.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__20 = 20;

#ifndef NO_PROTO
logical strcon_(integer *strid, char *strg, ftnlen strg_len)
#else /* NO_PROTO */
logical strcon_(strid, strg, strg_len)
integer *strid;
char *strg;
ftnlen strg_len;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2;
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_cat();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

#endif /* not NO_PROTO */
    /* Local variables */
    static integer ia[20];
    static real ra[20];
    static char sa[80*20];
    static integer ep, sl[20];
    static char msg[100];
    static integer icon, size, stat, isiz, ityp, rsiz, ssiz;
#ifndef NO_PROTO
    extern /* Subroutine */ int nqeco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, integer *, integer *, char *, ftnlen), unmsg_(char *, 
	    ftnlen), nqets (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), setvs_(char *, integer *, 
	    integer *, ftnlen), chkinq_(char *, integer *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqeco (), unmsg_(), nqets (), setvs_(), 
	    chkinq_();
#endif /* NO_PROTO */
    static integer errind, lstele, eltype, typcon[300];
#ifndef NO_PROTO
    extern /* Subroutine */ int nqstst (integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nqstst ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___7 = { 0, msg, 0, "(A,I7)", 100, 1 };
    static icilist io___19 = { 0, msg, 0, "(A,I7)", 100, 1 };
    static icilist io___20 = { 0, msg, 0, "(A,I7)", 100, 1 };


/*  Strcon is used to check the contents of a single structure. */

/*  Strid is the identifier of the structure to be examined. */
/*  Strg is a string representing a list of integers, which are */
/*  interpreted as type-content pairs.  Only the first integer */
/*  in an element's content is checked, i.e. that mapped to */
/*  the first slot in the integer array by PQCECO or PQECO */

/*  If the structure contains a sequence of elements exactly matching */
/*  these type-content pairs, strcon returns TRUE, otherwise FALSE. */
/*  A blank string may be used to designate an empty structure, but */
/*  the structure must exist. */
/* structure status indicator */
/*  error code for non-existent element */
/* generate integer array from strg */
    setvs_(strg, typcon, &size, strg_len);
    if (size % 2 != 0) {
/* Writing concatenation */
#ifndef NO_PROTO
	i__1[0] = 66, a__1[0] = "Illegal string passed to strcon; must be ev"
		"en number of elements: ";
#else /* NO_PROTO */
	i__1[0] = 66, a__1[0] = "Illegal string passed to strcon; must be ev\
en number of elements: ";
#endif /* NO_PROTO */
	i__1[1] = strg_len, a__1[1] = strg;
	s_cat(msg, a__1, i__1, &c__2, 100L);
	unmsg_(msg, 100L);
    }
/* last element */
    lstele = size / 2;
/* check structure existence */
    nqstst (strid, &errind, &stat);
    chkinq_("pqstst", &errind, 6L);
    if (stat == 0) {
	s_wsfi(&io___7);
	do_fio(&c__1, "Non-existent structure passed to strcon: ", 41L);
	do_fio(&c__1, (char *)&(*strid), (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 100L);
    }
/* check that structure is not too long */
    i__2 = lstele + 1;
    nqets (strid, &i__2, &errind, &eltype, &isiz, &rsiz, &ssiz);
    if (errind != 202) {
	goto L666;
    }
    if (lstele > 0) {
/* check that structure is not too short */
	nqets (strid, &lstele, &errind, &eltype, &isiz, &rsiz, &ssiz);
	if (errind == 202) {
	    goto L666;
	}
    }
    i__2 = lstele;
    for (ep = 1; ep <= i__2; ++ep) {
	nqets (strid, &ep, &errind, &eltype, &isiz, &rsiz, &ssiz);
	if (errind == 0) {
/*  Normal return from pqets */
	    icon = ep << 1;
	    ityp = icon - 1;
	    if (eltype != typcon[ityp - 1]) {
/*  types don't match */
		goto L666;
	    }
	    nqeco (strid, &ep, &c__20, &c__20, &c__20, &errind, &isiz, ia, &
		    rsiz, ra, &ssiz, sl, sa, 80L);
	    if (errind != 0) {
/*  weird errind from pqeco */
		s_wsfi(&io___19);
		do_fio(&c__1, "Strange errind from pqeco in strcon: ", 37L);
		do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
		e_wsfi();
		unmsg_(msg, 100L);
	    }
	    if (ia[0] != typcon[icon - 1]) {
/*  contents don't match */
		goto L666;
	    }
	} else {
/*  weird errind from pqets */
	    s_wsfi(&io___20);
	    do_fio(&c__1, "Strange errind from pqets in strcon: ", 37L);
	    do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	    e_wsfi();
	    unmsg_(msg, 100L);
	}
/* L100: */
    }
    ret_val = TRUE_;
    goto L667;
L666:
    ret_val = FALSE_;
L667:
    return ret_val;
} /* strcon_ */

