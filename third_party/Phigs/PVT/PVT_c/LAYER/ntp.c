#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     TRANSFORM POINT  - apply a 2D  transformation  matrix  to  a
     specified 2D point

  FORTRAN Syntax
     SUBROUTINE ptp ( XI, YI, XFRMT, ERRIND, XO, YO )
     REAL        XI, YI            point
     REAL        XFRMT(3, 3)       transformation matrix
     INTEGER     ERRIND            OUT error indicator
     REAL        XO, YO            OUT transformed point
**************************************************************************/
#ifdef NO_PROTO
ntp (xi, yi, xfrmt, errind, xo, yo)
   real    *xi,
            *yi,
             xfrmt[3][3],
            *xo,
            *yo;
   integer      *errind;
#else
ntp (real *xi, real *yi, real xfrmt[3][3], integer *errind, 
     real *xo, real *yo)
#endif
{
   Pint      cerror, i, j;
   Ppoint    pt;
   Pmatrix   matrix;
   Ppoint    result;
   pt.x = *xi;
   pt.y = *yi;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 3; i++)
   {
      for (j = 0; j < 3; j++)
      {
	 matrix[i][j] = xfrmt[j][i];
      }
   }

/**************************************************************************
  C Syntax
     void
     ptran_point ( p, m, errind, r)
     Ppoint         *p;            point
     Pmatrix        m;             transformation matrix
     Pint        *errind;          OUT error indicator
     Ppoint         *r;            OUT transformed point
**************************************************************************/

   ptran_point (&pt, matrix, &cerror, &result);
   *errind = cerror;

   *xo = result.x;
   *yo = result.y;
}
