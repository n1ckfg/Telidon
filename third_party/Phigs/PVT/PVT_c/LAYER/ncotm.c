#include <phigs.h>
#include "f2c.h"

/***************************************************************************
NAME
     COMPOSE TRANSFORMATION MATRIX  - compose a 2D transformation
     matrix, which is the composition of a specified matrix and a
     transformation matrix defined by a fixed point,  shift  vec-
     tor, rotation angle, and scale factors

  FORTRAN Syntax
     SUBROUTINE pcotm ( XFRMTI, X0, Y0, DX, DY, PHI, FX, FY, ERRIND, XFRMTO )
     REAL        XFRMTI(3, 3)      transformation matrix
     REAL        X0, Y0            fixed point
     REAL        DX, DY            shift vector
     REAL        PHI               rotation angle (radians)
     REAL        FX, FY            scale factor vector
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMTO(3, 3)      OUT transformation matrix
***************************************************************************/
#ifdef NO_PROTO
ncotm (xfrmti, x0, y0, dx, dy, phi, fx, fy, errind, xfrmto)
   real     xfrmti[3][3],
            *x0,
            *y0,
            *dx,
            *dy,
            *phi;
   real    *fx,
            *fy,
             xfrmto[3][3];
   integer      *errind;
#else
ncotm (real xfrmti[3][3], real *x0, real *y0, real *dx, real *dy, real *phi,
       real *fx, real *fy, integer *errind, real xfrmto[3][3])
#endif
{
   Pint      cerror, i, j;
   Pmatrix   matrix;
   Ppoint    pt;
   Pvec      shift;
   Pfloat    angle;
   Pvec      scale;
   Pmatrix   result;


/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 matrix[i][j] = xfrmti[j][i];

   pt.x = *x0;
   pt.y = *y0;

   shift.delta_x = *dx;
   shift.delta_y = *dy;

   angle = *phi;

   scale.delta_x = *fx;
   scale.delta_y = *fy;

/***************************************************************************
  C Syntax
     void
     pcompose_tran_matrix ( m, pt, shift, angle, scale, errind, result )
     Pmatrix     m;                transformation matrix
     Ppoint      *pt;              fixed point
     Pvec        *shift;           shift vector
     Pfloat      angle;            rotation angle
     Pvec        *scale;           scale vector
     Pint        *errind;          OUT error indicator
     Pmatrix     result;           OUT transformation matrix
***************************************************************************/

   pcompose_tran_matrix (matrix, &pt, &shift, angle, &scale, &cerror, result);

   *errind = cerror;

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 xfrmto[i][j] = result[j][i];
}
