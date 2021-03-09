#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     COMPOSE TRANSFORMATION MATRIX 3 - compose a  3D  transforma-
     tion  matrix, which is the composition of a specified matrix
     and a transformation matrix defined by a fixed point,  shift
     vector, rotation angle, and scale factors

  FORTRAN Syntax
     SUBROUTINE pcotm3 ( XFRMTI, X0, Y0, Z0, DX, DY, DZ, PHIX, PHIY, PHIZ, FX, FY,
         FZ, ERRIND, XFRMTO )
     REAL        XFRMTI(4, 4)      transformation matrix
     REAL        X0, Y0, Z0        fixed point
     REAL        DX, DY, DZ        shift vector
     REAL        PHIX, PHIY, PHIZ  rotation angles (radians)
     REAL        FX, FY, FZ        scale factor vector
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMTO(4, 4)      OUT transformation matrix
**************************************************************************/
#ifdef NO_PROTO
ncotm3 (xfrmti, x0, y0, z0, dx, dy, dz, phix, phiy, phiz, fx, fy, fz, errind, xfrmto)
   real     xfrmti[4][4],
            *x0,
            *y0,
            *z0,
            *dx,
            *dy,
            *dz,
            *phix,
            *phiy,
            *phiz;
   real    *fx,
            *fy,
            *fz,
             xfrmto[4][4];
   integer      *errind;
#else
ncotm3 (real xfrmti[4][4], real *x0, real *y0, real *z0, real *dx, real *dy,
     real *dz, real *phix, real *phiy, real *phiz, real *fx, real *fy,
	real *fz, integer *errind, real xfrmto[4][4])
#endif
{
   Pint      cerror, i, j;
   Pmatrix3  matrix;
   Ppoint3   pt;
   Pvec3     shift;
   Pfloat    x_angle;
   Pfloat    y_angle;
   Pfloat    z_angle;
   Pvec3     scale;
   Pmatrix3  result;


/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	 matrix[i][j] = xfrmti[j][i];

   pt.x = *x0;
   pt.y = *y0;
   pt.z = *z0;

   shift.delta_x = *dx;
   shift.delta_y = *dy;
   shift.delta_z = *dz;

   x_angle = *phix;
   y_angle = *phiy;
   z_angle = *phiz;

   scale.delta_x = *fx;
   scale.delta_y = *fy;
   scale.delta_z = *fz;

/**************************************************************************
  C Syntax
     void
     pcompose_tran_matrix3 ( m, pt, shift, x_ang, y_ang, z_ang, scale,
         errind, result )
     Pmatrix3    m;                transformation matrix
     Ppoint3     *pt;              fixed point
     Pvec3       *shift;           shift vector
     Pfloat      x_ang;            rotation angle X
     Pfloat      y_ang;            rotation angle Y
     Pfloat      z_ang;            rotation angle Z
     Pvec3       *scale;           scale vector
     Pint        *errind;          OUT error indicator
     Pmatrix3    result;           OUT transformation matrix
**************************************************************************/

   pcompose_tran_matrix3 (matrix, &pt, &shift, x_angle, y_angle, z_angle,
      &scale, &cerror, result);

   *errind = cerror;

   for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	 xfrmto[i][j] = result[j][i];
}
