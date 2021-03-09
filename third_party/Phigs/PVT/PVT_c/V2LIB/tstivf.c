/* tstivf.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int tstivf_(integer *wkid, integer *incsiz, integer *incset, 
	integer *excsiz, integer *excset)
#else /* NO_PROTO */
/* Subroutine */ int tstivf_(wkid, incsiz, incset, excsiz, excset)
integer *wkid, *incsiz, *incset, *excsiz, *excset;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int elgprm_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), dlstpf_(char *, integer *, 
	    integer *, char *, ftnlen, ftnlen), nsivft (integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int elgprm_(), dlstpf_(), nsivft ();
#endif /* NO_PROTO */
    static integer trulis[8], trusiz;

/*  TSTIVF tests that the appropriate primitives are invisible for */
/*  a given inclusion and exclusion set used as the invisibility */
/*  filter. */
/*  Input parameters: */
/*    WKID          : workstation identifier */
/*    INCSIZ,INCSET : inclusion set */
/*    EXCSIZ,EXCSET : exclusion set */
/*  <set invisibility filter>: */
    /* Parameter adjustments */
    --excset;
    --incset;

    /* Function Body */
    nsivft (wkid, incsiz, &incset[1], excsiz, &excset[1]);
/*  Compute expected subset of invisible primitives from incl,excl */
    elgprm_(incsiz, &incset[1], excsiz, &excset[1], &trusiz, trulis);
    dlstpf_("INVISIBILITY FILTER: Which primitives are invisible (n if none)?"
	    , &trusiz, trulis, "S", 64L, 1L);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstivf_ */

