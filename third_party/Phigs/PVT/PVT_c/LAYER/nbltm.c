#include <phigs.h>
#include "f2c.h"

/***********************************************************************
NAME
     BUILD TRANSFORMATION MATRIX  - generate a 2D  transformation
     matrix to perform a transformation specified by a shift vec-
     tor, rotation angle, and scale factors relative to a  speci-
     fied fixed point

  FORTRAN Syntax
     SUBROUTINE pbltm ( X0, Y0, DX, DY, PHI, FX, FY, ERRIND, XFRMT )
     REAL        X0, Y0            fixed point
     REAL        DX, DY            shift vector
     REAL        PHI               rotation angle (radians)
     REAL        FX, FY            scale factor vector
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMT(3, 3)       OUT transformation matrix
***********************************************************************/
#ifdef NO_PROTO
nbltm (x0, y0, dx, dy, phi, fx, fy, errind, xfrmt)
   real    *x0,
            *y0,
            *dx,
            *dy,
            *phi,
            *fx,
            *fy,
             xfrmt[3][3];
   integer      *errind;
#else
nbltm (real *x0, real *y0, real *dx, real *dy, real *phi, real *fx,
       real *fy, integer *errind, real xfrmt[3][3])
#endif
{
   Pint      i, j, cerror;
   Ppoint    pt;
   Pvec      shift;
   Pfloat    angle;
   Pvec      scale;
   Pmatrix   matrix;
   pt.x = *x0;
   pt.y = *y0;

   angle = *phi;

   shift.delta_x = *dx;
   shift.delta_y = *dy;

   scale.delta_x = *fx;
   scale.delta_y = *fy;

/***********************************************************************
  C Syntax
     void
     pbuild_tran_matrix ( pt, shift, angle, scale, errind, matrix )
     Ppoint      *pt;              fixed point
     Pvec        *shift;           shift vector
     Pfloat      angle;            rotation angle
     Pvec        *scale;           scale vector
     Pint        *errind;          OUT error indicator
     Pmatrix     matrix;           OUT transformation matrix
***********************************************************************/

   pbuild_tran_matrix (&pt, &shift, angle, &scale, &cerror, matrix);
   *errind = cerror;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 xfrmt[i][j] = matrix[j][i];
}
