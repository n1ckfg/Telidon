#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     TRANSFORM POINT 3 - apply a 3D transformation  matrix  to  a
     specified 3D point

  FORTRAN Syntax
     SUBROUTINE ptp3 ( XI, YI, ZI, XFRMT, ERRIND, XO, YO, ZO )
     REAL        XI, YI, ZI        point
     REAL        XFRMT(4, 4)       transformation matrix
     INTEGER     ERRIND            OUT error indicator
     REAL        XO, YO, ZO        OUT transformed point
**************************************************************************/
#ifdef NO_PROTO
ntp3 (xi, yi, zi, xfrmt, errind, xo, yo, zo)
   real    *xi,
            *yi,
            *zi,
             xfrmt[4][4],
            *xo,
            *yo,
            *zo;
   integer      *errind;
#else
ntp3 (real *xi, real *yi, real *zi, real xfrmt[4][4], integer *errind,
      real *xo, real *yo, real *zo)
#endif
{
   Pint      cerror, i, j;
   Ppoint3   pt;
   Pmatrix3  matrix;
   Ppoint3   result;
   pt.x = *xi;
   pt.y = *yi;
   pt.z = *zi;

/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
   {
      for (j = 0; j < 4; j++)
      {
	 matrix[i][j] = xfrmt[j][i];
      }
   }

/**************************************************************************
  C Syntax
     void
     ptran_point3 ( p, m, errind, r)
     Ppoint3        *p;            point
     Pmatrix3       m;             transformation matrix
     Pint        *errind;          OUT error indicator
     Ppoint3        *r;            OUT transformed point
**************************************************************************/

   ptran_point3 (&pt, matrix, &cerror, &result);
   *errind = cerror;

   *xo = result.x;
   *yo = result.y;
   *zo = result.z;
}
