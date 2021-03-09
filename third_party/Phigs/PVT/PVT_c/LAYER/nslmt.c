#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET LOCAL TRANSFORMATION  - create  structure  element  con-
     taining 2D Local Modelling Transformation matrix

  FORTRAN Syntax
     SUBROUTINE pslmt ( XFRMT, CTYPE )
     REAL        XFRMT(3, 3)       transformation matrix
     INTEGER     CTYPE             composition type (PCPRE, PCPOST, PCREPL)
**************************************************************************/
#ifdef NO_PROTO
nslmt (xfrmt, ctype)
   real     xfrmt[3][3];
   integer      *ctype;
#else
nslmt (real xfrmt[3][3], integer *ctype)
#endif
{
   Pint      i, j;
   Pmatrix   xform;
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

   for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
	 xform[i][j] = xfrmt[j][i];

/**************************************************************************
  C Syntax
     void
     pset_local_tran ( xform, compose_type )
     Pmatrix     xform;            transformation matrix
     Pcompose_type                 compose_type;composition type
**************************************************************************/

   pset_local_tran (xform, compose_type);

}
