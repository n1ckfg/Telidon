#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET GLOBAL TRANSFORMATION 3 - create structure element  con-
     taining 3D global modelling transformation matrix

  FORTRAN Syntax
     SUBROUTINE psgmt3 ( XFRMT )
     REAL        XFRMT(4, 4)       transformation matrix
**************************************************************************/
#ifdef NO_PROTO
nsgmt3 (xfrmt)
   real     xfrmt[4][4];
#else
nsgmt3 (real xfrmt[4][4])
#endif
{
   Pint      i, j;
   Pmatrix3  xform;
/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/

   for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
	 xform[i][j] = xfrmt[j][i];

/**************************************************************************
  C Syntax
     void
     pset_global_tran3 ( xform )
     Pmatrix3    xform;            transformation matrix
**************************************************************************/

   pset_global_tran3 (xform);

}
