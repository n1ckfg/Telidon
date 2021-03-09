/* vecang.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
doublereal vecang_(real *vx1, real *vy1, real *vz1, real *vx2, real *vy2, 
	real *vz2)
#else /* NO_PROTO */
doublereal vecang_(vx1, vy1, vz1, vx2, vy2, vz2)
real *vx1, *vy1, *vz1, *vx2, *vy2, *vz2;
#endif /* NO_PROTO */
{
    /* System generated locals */
    real ret_val;

    /* Builtin functions */
#ifndef NO_PROTO
    double acos(doublereal);
#else /* NO_PROTO */
    double acos();
#endif /* NO_PROTO */

    /* Local variables */
    static real vl;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern doublereal vecl_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static real cosval;
#ifndef NO_PROTO
    extern doublereal dotprd_(real *, real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal dotprd_();
#endif /* NO_PROTO */

#ifndef NO_PROTO

#endif /* not NO_PROTO */
/*  This function accepts two 3D vectors and returns the */
/*  angle between them. */
    vl = vecl_(vx1, vy1, vz1) * vecl_(vx2, vy2, vz2);
#ifndef NO_PROTO
    if (vl == 0.f) {
	ret_val = 0.f;
#else /* NO_PROTO */
    if (vl == (float)0.) {
	ret_val = (float)0.;
#endif /* NO_PROTO */
    } else {
	cosval = dotprd_(vx1, vy1, vz1, vx2, vy2, vz2) / vl;
#ifndef NO_PROTO
	if (dabs(cosval) > 1.f) {
#else /* NO_PROTO */
	if (dabs(cosval) > (float)1.) {
#endif /* NO_PROTO */
	    unmsg_("Unstable parameters passed to VECANG.", 37L);
	}
	ret_val = acos(cosval);
    }
    return ret_val;
} /* vecang_ */

