/* sphdis.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b3 = 0.f;
static real c_b5 = 1.f;
#else /* NO_PROTO */
static real c_b3 = (float)0.;
static real c_b5 = (float)1.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__10 = 10;

#ifndef NO_PROTO
logical sphdis_(integer *strid)
#else /* NO_PROTO */
logical sphdis_(strid)
integer *strid;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static real xa[1], ya[1];
    static char msg[200];
#ifndef NO_PROTO
    extern /* Subroutine */ int npl (integer *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npl ();
#endif /* NO_PROTO */
    static integer idum[1];
#ifndef NO_PROTO
    extern /* Subroutine */ int niss (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int niss ();
#endif /* NO_PROTO */
    static integer fpath[20]	/* was [2][10] */, spath[2]	/* was [2][1] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nclst (void), nemst (integer *), unmsg_(char *
	    , ftnlen), nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nclst (), nemst (), unmsg_(), nopst ();
#endif /* NO_PROTO */
    static integer errind, fpthsz;

    /* Fortran I/O blocks */
    static icilist io___9 = { 0, msg, 0, "(A,I6)", 200, 1 };


/*  SPHDIS determines whether this implementation uses "spherical" or */
/* "cubic" distance metric for purposes of ISS.  Based on fact that betwee
n*/
/*  (0,0) and (.85,.85), the "spherical" distance = 1.202 but the "cubic" 
*/
/*  distance = 0.85. */
/*  Input parameter: */
/*    STRID: available structure ID */
/* clipping indicator */
/*                noclip      clip */
    nopst (strid);
    nemst (strid);
#ifndef NO_PROTO
    xa[0] = .85f;
    ya[0] = .85f;
#else /* NO_PROTO */
    xa[0] = (float).85;
    ya[0] = (float).85;
#endif /* NO_PROTO */
    npl (&c__1, xa, ya);
    nclst ();
    spath[0] = *strid;
    spath[1] = 0;
/* search distance of 1.0 should find marker for cubic, but not for spheri
cal*/
    niss (&c_b3, &c_b3, &c_b5, &c__1, spath, &c__0, &c__1, &c__0, idum, idum, 
	    idum, idum, &c__0, idum, idum, idum, idum, &c__10, &errind, &
	    fpthsz, fpath);
    nemst (strid);
    if (errind != 0) {
	s_wsfi(&io___9);
	do_fio(&c__1, "ISS in SPHDIS returned error indicator = ", 41L);
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 200L);
    }
    ret_val = fpthsz == 0;
    return ret_val;
} /* sphdis_ */

