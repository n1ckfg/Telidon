#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     DELETE STRUCTURE - remove specified structure

  FORTRAN Syntax
     SUBROUTINE pdst ( STRID )
     INTEGER     STRID             structure identifier
**************************************************************************/
#ifdef NO_PROTO
ndst (strid)
   integer      *strid;
#else
ndst (integer *strid)
#endif
{

/**************************************************************************
  C Syntax
     void
     pdel_struct ( struct_id )
     Pint        struct_id;        structure identifier
**************************************************************************/

   pdel_struct ((Pint) *strid);
}
