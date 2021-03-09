#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET MARKER TYPE - create structure element  to  set  current
     marker type attribute

  FORTRAN Syntax
     SUBROUTINE psmk ( MTYPE )
     INTEGER     MTYPE             marker type
**************************************************************************/
#ifdef NO_PROTO
nsmk (mtype)
   integer      *mtype;
#else
nsmk (integer *mtype)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_marker_type ( markertype )
     Pint        markertype;       marker type
**************************************************************************/

   pset_marker_type ((Pint) *mtype);
}
