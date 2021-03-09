/* tstcor.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b24 = 1e-7f;
static real c_b25 = 1e-4f;
#else /* NO_PROTO */
static real c_b24 = (float)1e-7;
static real c_b25 = (float)1e-4;
#endif /* NO_PROTO */
static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int tstcor_(real *vwind, real *prvwpt, integer *projty, real 
	*prp, real *vpd, real *bpd, real *fpd, real *trnf, real *vwcent)
#else /* NO_PROTO */
/* Subroutine */ int tstcor_(vwind, prvwpt, projty, prp, vpd, bpd, fpd, trnf, 
	vwcent)
real *vwind, *prvwpt;
integer *projty;
real *prp, *vpd, *bpd, *fpd, *trnf, *vwcent;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];
    char ch__1[14];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
    /* Local variables */
    static real bas[12]	/* was [4][3] */, dlt[12]	/* was [4][3] */;
    static char msg[300], xyz[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), fail_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), fail_();
#endif /* NO_PROTO */
    static integer icor;
    static real nval;
#ifndef NO_PROTO
    extern /* Subroutine */ int pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int pass_();
#endif /* NO_PROTO */
    static integer ixyz;
#ifndef NO_PROTO
    extern logical appeq_(real *, real *, real *, real *);
#else /* NO_PROTO */
    extern logical appeq_();
#endif /* NO_PROTO */
    static real actpr[3];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static real actvv[24]	/* was [8][3] */, uparm;
    static integer iproj, icorx, icory, icorz;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static real exppr[24]	/* was [8][3] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nevmm3 (real *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *, integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nevmm3 ();
#endif /* NO_PROTO */
    static integer errind;

    /* Fortran I/O blocks */
    static icilist io___8 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static icilist io___17 = { 0, msg, 0, "(A,I5)", 300, 1 };
    static icilist io___19 = { 0, msg, 0, "(A,I5,A)", 300, 1 };


/*  TSTCOR tests the pevmm3 function by applying the transform */
/*  returned by it to the eight corners of the view volume and */
/*  checking that they are reasonably close to the corners of the */
/*  projection viewport. */

/*  ------- INPUT PARAMETERS */
/*  vwind (4)  : view window limits */
/*  prvwpt (6) : projection viewport limits */
/*  projty     : projection type */
/*  prp (3)    : projection reference point */
/*  vpd        : view plane distance (n-coordinate value) */
/*  bpd        : back plane distance (n-coordinate value) */
/*  fpd        : front plane distance (n-coordinate value) */

/*  ------- OUTPUT PARAMETERS: */
/*  trnf (4,4) : transformation returned by pevmm3 */
/*  vwcent (3) : view window center */
/* viewtype */
    /* Parameter adjustments */
    --vwcent;
    trnf -= 5;
    --prp;
    --prvwpt;
    --vwind;

    /* Function Body */
    s_copy(xyz, "XYZ", 3L, 3L);
/* get view window center */
    vwcent[1] = (vwind[1] + vwind[2]) / 2;
    vwcent[2] = (vwind[3] + vwind[4]) / 2;
    vwcent[3] = *vpd;
/* determine BASE and DELTA for 4 corner projectors - each line in */
/* parametric form: */
/*   x = BASx + uparm*DLTx */
/*   y = BASy + uparm*DLTy */
/*   z = BASz + uparm*DLTz */
/*  Order of projectors is: */
/*     1: left,  bottom */
/*     2: left,  top */
/*     3: right, bottom */
/*     4: right, top */
    if (*projty == 0) {
/* deltas for all 4 projectors are the same - parallel projectors */
	for (iproj = 1; iproj <= 4; ++iproj) {
	    for (ixyz = 1; ixyz <= 3; ++ixyz) {
		dlt[iproj + (ixyz << 2) - 5] = vwcent[ixyz] - prp[ixyz];
/* L120: */
	    }
/* L110: */
	}
    } else if (*projty == 1) {
/* delta based on PRP and *corners* of view window */
	for (icorx = 1; icorx <= 2; ++icorx) {
	    for (icory = 3; icory <= 4; ++icory) {
/* which projector? */
		iproj = (icorx << 1) + icory - 4;
		dlt[iproj - 1] = vwind[icorx] - prp[1];
		dlt[iproj + 3] = vwind[icory] - prp[2];
		dlt[iproj + 7] = *vpd - prp[3];
/* L215: */
	    }
/* L210: */
	}
    } else {
	s_wsfi(&io___8);
	do_fio(&c__1, "Illegal projection type passed to TSTCOR:", 41L);
	do_fio(&c__1, (char *)&(*projty), (ftnlen)sizeof(integer));
	e_wsfi();
	unmsg_(msg, 300L);
    }
/* use 4 corners of view window as bases - these are valid */
/* for either parallel or perspective */
    for (icorx = 1; icorx <= 2; ++icorx) {
	for (icory = 3; icory <= 4; ++icory) {
/* which projector? */
	    iproj = (icorx << 1) + icory - 4;
	    bas[iproj - 1] = vwind[icorx];
	    bas[iproj + 3] = vwind[icory];
	    bas[iproj + 7] = *vpd;
/* L315: */
	}
/* L310: */
    }
/* calculate all 8 view volume corners */
/*labeling of corners: (left, bottom, back = 1, left, bottom, front = 2...
*/
/*    right, top, front = 8) */
    for (icor = 1; icor <= 8; ++icor) {
/* which projector */
	iproj = (icor + 1) / 2;
	if (icor % 2 == 1) {
	    nval = *bpd;
	} else {
	    nval = *fpd;
	}
/* calculate value of UPARM for parametric lines */
	uparm = (nval - bas[iproj + 7]) / dlt[iproj + 7];
/* get coordinates for the corner */
	for (ixyz = 1; ixyz <= 3; ++ixyz) {
	    actvv[icor + (ixyz << 3) - 9] = bas[iproj + (ixyz << 2) - 5] + 
		    uparm * dlt[iproj + (ixyz << 2) - 5];
/* L360: */
	}
/* L350: */
    }
/* expected values for projection: */
    for (icorx = 1; icorx <= 2; ++icorx) {
	for (icory = 3; icory <= 4; ++icory) {
	    for (icorz = 5; icorz <= 6; ++icorz) {
/* which corner */
		icor = (icorx << 2) + (icory << 1) + icorz - 14;
		exppr[icor - 1] = prvwpt[icorx];
		exppr[icor + 7] = prvwpt[icory];
		exppr[icor + 15] = prvwpt[icorz];
/* L430: */
	    }
/* L420: */
	}
/* L410: */
    }
    nevmm3 (&vwind[1], &prvwpt[1], projty, &prp[1], &prp[2], &prp[3], vpd, 
	    bpd, fpd, &errind, &trnf[5]);
    if (errind != 0) {
	fail_();
	s_wsfi(&io___17);
	do_fio(&c__1, "Non-zero error code in TSTCOR from PEVMM3:", 42L);
	do_fio(&c__1, (char *)&errind, (ftnlen)sizeof(integer));
	e_wsfi();
	inmsg_(msg, 300L);
	return 0;
    }
/* transform view volume corners to projection corners */
    for (icor = 1; icor <= 8; ++icor) {
	etp3_(&actvv[icor - 1], &actvv[icor + 7], &actvv[icor + 15], &trnf[5],
		 actpr, &actpr[1], &actpr[2]);
	for (ixyz = 1; ixyz <= 3; ++ixyz) {
	    if (! appeq_(&actpr[ixyz - 1], &exppr[icor + (ixyz << 3) - 9], &
		    c_b24, &c_b25)) {
		fail_();
		s_wsfi(&io___19);
		do_fio(&c__1, "Failed on corner #", 18L);
		do_fio(&c__1, (char *)&icor, (ftnlen)sizeof(integer));
/* Writing concatenation */
		i__1[0] = 13, a__1[0] = ", coordinate ";
		i__1[1] = 1, a__1[1] = xyz + (ixyz - 1);
		s_cat(ch__1, a__1, i__1, &c__2, 14L);
		do_fio(&c__1, ch__1, 14L);
		e_wsfi();
		inmsg_(msg, 300L);
		return 0;
	    }
/* L520: */
	}
/* L510: */
    }
    pass_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* tstcor_ */

