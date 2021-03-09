#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     TRANSLATE - calculate a 2D transformation matrix to  perform
     a specified translation

  FORTRAN Syntax
     SUBROUTINE ptr ( DX, DY, ERRIND, XFRMT )
     REAL        DX, DY            translation vector
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMT(3, 3)       OUT transformation matrix
**************************************************************************/
#ifdef NO_PROTO
ntr (dx, dy, errind, xfrmt)
   real    *dx,
            *dy,
             xfrmt[3][3];
   integer      *errind;
#else
ntr (real *dx, real *dy, integer *errind, real xfrmt[3][3])
#endif
{
   Pint      cerror, i,j;
   Pvec      vec;
   Pmatrix   matrix;
   vec.delta_x = *dx;
   vec.delta_y = *dy;

/**************************************************************************
  C Syntax
     void
     ptranslate ( trans_vector, errind, m)
     Pvec           *trans_vector; translation vector
     Pint        *errind;          OUT error indicator
     Pmatrix        m;             OUT transformation matrix
**************************************************************************/

   ptranslate (&vec, &cerror, matrix);
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
