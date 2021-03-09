#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SCALE - calculate 2D transformation matrix to perform speci-
     fied scaling

  FORTRAN Syntax
     SUBROUTINE psc ( FX, FY, ERRIND, XFRMT )
     REAL        FX, FY            scale factor vector
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMT(3, 3)       OUT transformation matrix
**************************************************************************/
#ifdef NO_PROTO
nsc (fx, fy, errind, xfrmt)
   real    *fx,
            *fy,
             xfrmt[3][3];
   integer      *errind;
#else
nsc (real *fx, real *fy, integer *errind, real xfrmt[3][3])
#endif
{
   Pint      cerror, i, j;
   Pvec      scale_vector;
   Pmatrix   matrix;


   scale_vector.delta_x = *fx;
   scale_vector.delta_y = *fy;

/**************************************************************************
  C Syntax
     void
     pscale ( scale_vector, errind, m )
     Pvec        *scale_vector;    scale factor vector
     Pint        *errind;          OUT error indicator
     Pmatrix     m;                OUT transformation matrix
**************************************************************************/

   pscale (&scale_vector, &cerror, matrix);
   *errind = cerror;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 3; i++)
   {
      for (j = 0; j < 3; j++)
      {
	 xfrmt[i][j] = matrix[j][i];
      }
   }
}
