#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET EDGE INDEX - create structure  element  containing  edge
     representation index attribute

  FORTRAN Syntax
     SUBROUTINE psedi ( EDI )
     INTEGER     EDI               edge representation index
**************************************************************************/
#ifdef NO_PROTO
nsedi (edi)
   integer      *edi;
#else
nsedi (integer *edi)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_edge_ind ( index )
     Pint        index;            edge index
**************************************************************************/

   pset_edge_ind ((Pint) *edi);
}
