#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET INTERIOR STYLE - create structure element to set current
     interior style attribute

  FORTRAN Syntax
     SUBROUTINE psis ( INTS )
     INTEGER     INTS              interior style
**************************************************************************/
#ifdef NO_PROTO
nsis (ints)
   integer      *ints;
#else
nsis (integer *ints)
#endif
{
   Pint_style style;

   style = *ints;
   switch (*ints)
   {
   case 0:
      style = PSTYLE_HOLLOW;
      break;
   case 1:
      style = PSTYLE_SOLID;
      break;
   case 2:
      style = PSTYLE_PAT;
      break;
   case 3:
      style = PSTYLE_HATCH;
      break;
   case 4:
      style = PSTYLE_EMPTY;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_int_style ( style )
     Pint_style  style;            interior style
**************************************************************************/

   pset_int_style (style);
}
