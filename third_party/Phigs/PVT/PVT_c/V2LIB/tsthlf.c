/* tsthlf.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int tsthlf_(integer *wkid, integer *incsiz, integer *incset, 
	integer *excsiz, integer *excset)
#else /* NO_PROTO */
/* Subroutine */ int tsthlf_(wkid, incsiz, incset, excsiz, excset)
integer *wkid, *incsiz, *incset, *excsiz, *excset;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int elgprm_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), dlstpf_(char *, integer *, 
	    integer *, char *, ftnlen, ftnlen), nshlft (integer *, integer *, 
	    integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int elgprm_(), dlstpf_(), nshlft ();
#endif /* NO_PROTO */
    static integer trulis[8], trusiz;

/*  TSTHLF tests that the appropriate primitives are highlighted for */
/*  a given inclusion and exclusion set used as the highlighting */
/*  filter. */
/*  Input parameters: */
/*    WKID          : workstation identifier */
/*    INCSIZ,INCSET : inclusion set */
/*    EXCSIZ,EXCSET : exclusion set */
/*  <set highlighting filter>: */
    /* Parameter adjustments */
    --excset;
    --incset;

    /* Function Body */
    nshlft (wkid, incsiz, &incset[1], excsiz, &excset[1]);
/*  Compute expected subset of highlighted primitives from incl,excl */
    elgprm_(incsiz, &incset[1], excsiz, &excset[1], &trusiz, trulis);
#ifndef NO_PROTO
    dlstpf_("HIGHLIGHTING FILTER: For which pairs is the primitive on the le"
	    "ft highlighted (n if none)?", &trusiz, trulis, "S", 90L, 1L);
    return 0;
#else /* NO_PROTO */
    dlstpf_("HIGHLIGHTING FILTER: For which pairs is the primitive on the le\
ft highlighted (n if none)?", &trusiz, trulis, "S", 90L, 1L);
#endif /* NO_PROTO */
} /* tsthlf_ */

