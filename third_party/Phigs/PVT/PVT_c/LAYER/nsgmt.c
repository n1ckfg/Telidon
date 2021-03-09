#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET GLOBAL TRANSFORMATION - create  structure  element  con-
     taining 2D global modelling transformation matrix

  FORTRAN Syntax
     SUBROUTINE psgmt ( XFRMT )
     REAL        XFRMT(3, 3)       transformation matrix
**************************************************************************/
#ifdef NO_PROTO
nsgmt (xfrmt)
   real     xfrmt[3][3];
#else
nsgmt (real xfrmt[3][3])
#endif
{
   Pint      i, j;
   Pmatrix   xform;


/***************************************************

       This transposition done because f2c emulates
       FORTRAN, and logically does not alter 2D arrays
       only physically.

 **************************************************/
   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 xform[i][j] = xfrmt[j][i];

/**************************************************************************
  C Syntax
     void
     pset_global_tran ( xform )
     Pmatrix     xform;            transformation matrix
**************************************************************************/

   pset_global_tran (xform);

}
