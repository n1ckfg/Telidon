#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     ROTATE Y - calculate 3D  transformation  matrix  to  perform
     specified rotation about y axis

  FORTRAN Syntax
     SUBROUTINE proy ( ROTANG, ERRIND, XFRMT )
     REAL        ROTANG            rotation angle in radians (positive
                                   if anticlockwise)
     INTEGER     ERRIND            OUT error indicator
     REAL        XFRMT(4, 4)       OUT transformation matrix
**************************************************************************/
#ifdef NO_PROTO
nroy (rotang, errind, xfrmt)
   real    *rotang,
             xfrmt[4][4];
   integer      *errind;
#else
nroy (real *rotang, integer *errind, real xfrmt[4][4])
#endif
{
   Pint      cerror, i, j;
   Pfloat    angle;
   Pmatrix3  matrix;

   angle = *rotang;

/**************************************************************************
  C Syntax
     void
     protate_y ( angle, errind, m)
     Pfloat      angle;            rotation angle
     Pint        *errind;          OUT error indicator
     Pmatrix3    m;                OUT transformation matrix
**************************************************************************/

   protate_y (angle, &cerror, matrix);
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
