#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET EDGETYPE - create structure element to set current edge-
     type attribute

  FORTRAN Syntax
     SUBROUTINE psedt ( EDTYPE )
     INTEGER     EDTYPE            edgetype
**************************************************************************/
#ifdef NO_PROTO
nsedt (edtype)
   integer      *edtype;
#else
nsedt (integer *edtype)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_edgetype ( edgetype )
     Pint        edgetype;         edgetype
**************************************************************************/

   pset_edgetype ((Pint) *edtype);
}
