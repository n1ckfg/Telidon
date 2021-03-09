#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     TRANSLATE 3 - calculate a 3D transformation matrix  to  per-
     form a specified translation

  FORTRAN Syntax
     SUBROUTINE ptr3 ( DX, DY, DZ, ERRIND, XFRMT )
     REAL        DX, DY, DZ        translation vector
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMT(4, 4)       OUT transformation matrix
**************************************************************************/
#ifdef NO_PROTO
ntr3 (dx, dy, dz, errind, xfrmt)
   real    *dx,
            *dy,
            *dz,
             xfrmt[4][4];
   integer      *errind;
#else
ntr3 (real *dx, real *dy, real *dz, integer *errind, real xfrmt[4][4])
#endif
{
   Pint      cerror, i, j;
   Pvec3     vec;
   Pmatrix3  matrix;
   vec.delta_x = *dx;
   vec.delta_y = *dy;
   vec.delta_z = *dz;

/**************************************************************************
  C Syntax
     void
     ptranslate3 ( trans_vector, errind, m)
     Pvec3          *trans_vector; translation vector
     Pint        *errind;          OUT error indicator
     Pmatrix3       m;             OUT transformation matrix
**************************************************************************/

   ptranslate3 (&vec, &cerror, matrix);
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
