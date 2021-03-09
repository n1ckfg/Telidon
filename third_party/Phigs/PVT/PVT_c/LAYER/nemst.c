#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     EMPTY STRUCTURE - remove all elements from structure

  FORTRAN Syntax
     SUBROUTINE pemst ( STRID )
     INTEGER     STRID             structure identifier
**************************************************************************/
#ifdef NO_PROTO
nemst (strid)
   integer      *strid;
#else
nemst (integer *strid)
#endif
{

/**************************************************************************
  C Syntax
     void
     pempty_struct ( struct_id )
     Pint        struct_id;        structure id
**************************************************************************/

   pempty_struct ((Pint) *strid);
}
