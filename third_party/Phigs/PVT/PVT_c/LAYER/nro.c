#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     ROTATE -  calculate  2D  transformation  matrix  to  perform
     specified 2D rotation

  FORTRAN Syntax
     SUBROUTINE pro ( ROTANG, ERRIND, XFRMT )
     REAL        ROTANG            rotation angle in radians (positive
                                   if anticlockwise)
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMT(3, 3)       OUT transformation matrix
**************************************************************************/
#ifdef NO_PROTO
nro (rotang, errind, xfrmt)
   real    *rotang,
             xfrmt[3][3];
   integer      *errind;
#else
nro (real *rotang, integer *errind, real xfrmt[3][3])
#endif
{
   Pint      cerror, i, j;
   Pfloat    angle;
   Pmatrix   matrix;

   angle = *rotang;

/**************************************************************************
  C Syntax
     void
     protate ( angle, errind, m)
     Pfloat      angle;            rotation angle
     Pint        *errind;          OUT error indicator
     Pmatrix     m;                OUT transformation matrix
**************************************************************************/

   protate (angle, &cerror, matrix);
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
