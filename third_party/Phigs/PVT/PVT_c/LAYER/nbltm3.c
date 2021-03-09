#include <phigs.h>
#include "f2c.h"

/******************************************************************************
NAME
     BUILD TRANSFORMATION MATRIX 3 - generate a 3D transformation
     matrix to perform a transformation specified by a shift vec-
     tor, rotation angles, and scale factors relative to a speci-
     fied fixed point

  FORTRAN Syntax
     SUBROUTINE pbltm3 ( X0, Y0, Z0, DX, DY, DZ, PHIX, PHIY, PHIZ, FX, FY, FZ,
         ERRIND, XFRMT )
     REAL        X0, Y0, Z0        fixed point
     REAL        DX, DY, DZ        shift vector
     REAL        PHIX, PHIY, PHIZ  rotation angles (radians)
     REAL        FX, FY, FZ        scale factor vector
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMT(4, 4)       OUT transformation matrix
******************************************************************************/
#ifdef NO_PROTO
nbltm3 (x0, y0, z0, dx, dy, dz, phix, phiy, phiz, fx, fy, fz, errind, xfrmt)
   real    *x0,
            *y0,
            *z0,
            *dx,
            *dy,
            *dz,
            *phix,
            *phiy,
            *phiz,
            *fx,
            *fy,
            *fz,
             xfrmt[4][4];
   integer      *errind;
#else
nbltm3 (real *x0, real *y0, real *z0, real *dx, real *dy, real *dz,
     real *phix, real *phiy, real *phiz, real *fx, real *fy, real *fz,
	integer *errind, real xfrmt[4][4])
#endif
{
   Pint      i, j, cerror;
   Ppoint3   pt;
   Pvec3     shift;
   Pfloat    anglex;
   Pfloat    angley;
   Pfloat    anglez;
   Pvec3     scale;
   Pmatrix3  matrix;
   pt.x = *x0;
   pt.y = *y0;
   pt.z = *z0;

   anglex = *phix;
   angley = *phiy;
   anglez = *phiz;

   shift.delta_x = *dx;
   shift.delta_y = *dy;
   shift.delta_z = *dz;

   scale.delta_x = *fx;
   scale.delta_y = *fy;
   scale.delta_z = *fz;

/******************************************************************************
  C Syntax
     void
     pbuild_tran_matrix3 ( pt, shift, x_angle, y_angle, z_angle, scale,
        errind, matrix )
     Ppoint3     *pt;              fixed point
     Pvec3       *shift;           shift vector
     Pfloat      x_angle;          rotation angle X
     Pfloat      y_angle;          rotation angle Y
     Pfloat      z_angle;          rotation angle Z
     Pvec3       *scale;           scale vector
     Pint        *errind;          OUT error indicator
     Pmatrix3    matrix;           OUT transformation matrix
******************************************************************************/

   pbuild_tran_matrix3 (&pt, &shift, anglex, angley, anglez, &scale,
     &cerror, matrix);

   *errind = cerror;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	 xfrmt[i][j] = matrix[j][i];
}
