#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET LOCAL TRANSFORMATION 3  - create structure element  con-
     taining 3D local modelling transformation matrix

  FORTRAN Syntax
     SUBROUTINE pslmt3 ( XFRMT, CTYPE )
     REAL        XFRMT(4, 4)       transformation matrix
     INTEGER     CTYPE             composition type (PCPRE, PCPOST, PCREPL)
**************************************************************************/
#ifdef NO_PROTO
nslmt3 (xfrmt, ctype)
   real     xfrmt[4][4];
   integer      *ctype;
#else
nslmt3 (real xfrmt[4][4], integer *ctype)
#endif
{
   Pint      i, j;
   Pmatrix3  xform;
   Pcompose_type compose_type;

   compose_type = *ctype;
   switch (*ctype)
   {
   case 0:			/*** PCPRE   ***/
      compose_type = PTYPE_PRECONCAT;
      break;
   case 1:			/*** PCPOST  ***/
      compose_type = PTYPE_POSTCONCAT;
      break;
   case 2:			/*** PCREPL  ***/
      compose_type = PTYPE_REPLACE;
      break;
   }

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
     pset_local_tran3 ( xform, compose_type )
     Pmatrix3    xform;            transformation matrix
     Pcompose_type                 compose_type;composition type
**************************************************************************/

   pset_local_tran3 (xform, compose_type);

}
