/* doimod.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;

#ifndef NO_PROTO
/* Subroutine */ int doimod_(integer *wkid, integer *inclas, integer *inmode)
#else /* NO_PROTO */
/* Subroutine */ int doimod_(wkid, inclas, inmode)
integer *wkid, *inclas, *inmode;
#endif /* NO_PROTO */
{
#ifndef NO_PROTO
    extern /* Subroutine */ int nschm (integer *, integer *, integer *, 
	    integer *), nslcm (integer *, integer *, integer *, integer *), 
	    unmsg_(char *, ftnlen), nspkm (integer *, integer *, integer *, 
	    integer *), nsskm (integer *, integer *, integer *, integer *), 
	    nsvlm (integer *, integer *, integer *, integer *), nsstm (
	    integer *, integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nschm (), nslcm (), unmsg_(), nspkm (), 
	    nsskm (), nsvlm (), nsstm ();
#endif /* NO_PROTO */

/*  DOIMOD: on the workstation (wkid), sets device #1 of the */
/*  specified input class (inclas) to the requested mode (inmode). */
/* operating mode */
/*                request  sample    event */
/* echo switch */
#ifndef NO_PROTO
    switch (*inclas) {
#else /* NO_PROTO */
    switch ((int)*inclas) {
#endif /* NO_PROTO */
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
    }
    unmsg_("Invalid input class passed to DOIMOD.", 37L);
L10:
/*     set locator mode */
    nslcm (wkid, &c__1, inmode, &c__0);
    goto L100;
L20:
/*     set stroke mode */
    nsskm (wkid, &c__1, inmode, &c__0);
    goto L100;
L30:
/*     set valuator mode */
    nsvlm (wkid, &c__1, inmode, &c__0);
    goto L100;
L40:
/*     set choice mode */
    nschm (wkid, &c__1, inmode, &c__0);
    goto L100;
L50:
/*     set pick mode */
    nspkm (wkid, &c__1, inmode, &c__0);
    goto L100;
L60:
/*     set string mode */
    nsstm (wkid, &c__1, inmode, &c__0);
    goto L100;
L100:
#ifndef NO_PROTO
    return 0;
#else /* NO_PROTO */
    ;
#endif /* NO_PROTO */
} /* doimod_ */

