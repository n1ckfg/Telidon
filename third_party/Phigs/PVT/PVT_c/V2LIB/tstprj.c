/* tstprj.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

#ifndef NO_PROTO
static real c_b5 = 1e-7f;
static real c_b6 = 1e-4f;
#else /* NO_PROTO */
static real c_b5 = (float)1e-7;
static real c_b6 = (float)1e-4;
#endif /* NO_PROTO */

#ifndef NO_PROTO
/* Subroutine */ int tstprj_(real *prp, real *trnf, real *vwcent)
#else /* NO_PROTO */
/* Subroutine */ int tstprj_(prp, trnf, vwcent)
real *prp, *trnf, *vwcent;
#endif /* NO_PROTO */
{
    /* System generated locals */
    logical L__1;

    /* Local variables */
    static real dlt[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), ifpf_();
#endif /* NO_PROTO */
    static integer ixyz, which;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real uparm, npcpt[6]	/* was [2][3] */, vrcpt[3];

/*  TSTPRJ tests that two arbitrary points on a projector are both */
/*  mapped to the same x-y values in NPC space. */
/*  ------- INPUT PARAMETERS */
/*  prp (3)    : projection reference point */
/*  trnf (4,4) : transformation returned by pevmm3 */
/*  vwcent (3) : view window center */
/*   compute VRC projector passing thru view window center */
    /* Parameter adjustments */
    --vwcent;
    trnf -= 5;
    --prp;

    /* Function Body */
    for (ixyz = 1; ixyz <= 3; ++ixyz) {
	dlt[ixyz - 1] = vwcent[ixyz] - prp[ixyz];
/* L110: */
    }
/*   pick two points on projector */
    for (which = 1; which <= 2; ++which) {
/*   compute point based on uparm - 3.3 units on each side of PRP */
#ifndef NO_PROTO
	uparm = ((which << 1) - 3) * 3.3f;
#else /* NO_PROTO */
	uparm = ((which << 1) - 3) * (float)3.3;
#endif /* NO_PROTO */
	for (ixyz = 1; ixyz <= 3; ++ixyz) {
	    vrcpt[ixyz - 1] = prp[ixyz] + uparm * dlt[ixyz - 1];
/* L220: */
	}
/*   apply trnf to VRC point to determine transformed NPC point */
	etp3_(vrcpt, &vrcpt[1], &vrcpt[2], &trnf[5], &npcpt[which - 1], &
		npcpt[which + 1], &npcpt[which + 3]);
/* L210: */
    }
/*   pass/fail projector test depending on */
/*     (cent1x approx= cent2x and cent1y approx= cent2y) */
    L__1 = appeq_(npcpt, &npcpt[1], &c_b5, &c_b6) && appeq_(&npcpt[2], &npcpt[
	    3], &c_b5, &c_b6);
    ifpf_(&L__1);
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstprj_ */

