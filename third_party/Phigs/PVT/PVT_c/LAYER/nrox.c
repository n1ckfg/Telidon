#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     ROTATE X - calculate 3D  transformation  matrix  to  perform
     specified rotation about x axis

  FORTRAN Syntax
     SUBROUTINE prox ( ROTANG, ERRIND, XFRMT )
     REAL        ROTANG            rotation angle in radians (positive
                                   if anticlockwise)
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMT(4, 4)       OUT transformation matrix
**************************************************************************/
#ifdef NO_PROTO
nrox (rotang, errind, xfrmt)
   real    *rotang,
             xfrmt[4][4];
   integer      *errind;
#else
nrox (real *rotang, integer *errind, real xfrmt[4][4])
#endif
{
   Pint      cerror, i, j;
   Pfloat    angle;
   Pmatrix3  matrix;

   angle = *rotang;

/**************************************************************************
  C Syntax
     void
     protate_x ( angle, errind, m)
     Pfloat      angle;            rotation angle
     Pint        *errind;          OUT error indicator
     Pmatrix3    m;                OUT transformation matrix
**************************************************************************/

   protate_x (angle, &cerror, matrix);
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
