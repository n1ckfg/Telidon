#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SCALE 3 - calculate  3D  transformation  matrix  to  perform
     specified scaling

  FORTRAN Syntax
     SUBROUTINE psc3 ( FX, FY, FZ, ERRIND, XFRMT )
     REAL        FX, FY, FZ        scale factor vector
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMT(4, 4)       OUT transformation matrix
**************************************************************************/
#ifdef NO_PROTO
nsc3 (fx, fy, fz, errind, xfrmt)
   real    *fx,
            *fy,
            *fz,
             xfrmt[4][4];
   integer      *errind;
#else
nsc3 (real *fx, real *fy, real *fz, integer *errind, real xfrmt[4][4])
#endif
{
   Pint      cerror, i, j;
   Pvec3     scale_vector;
   Pmatrix3  matrix;


   scale_vector.delta_x = *fx;
   scale_vector.delta_y = *fy;
   scale_vector.delta_z = *fz;

/**************************************************************************
  C Syntax
     void
     pscale3 ( scale_vector, errind, m)
     Pvec3       *scale_vector;    scale factor vector
     Pint        *errind;          OUT error indicator
     Pmatrix3    m;                OUT transformation matrix
**************************************************************************/

   pscale3 (&scale_vector, &cerror, matrix);
   *errind = cerror;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
   {
      for (j = 0; j < 4; j++)
      {
	 xfrmt[i][j] = matrix[j][i];
      }
   }
}
