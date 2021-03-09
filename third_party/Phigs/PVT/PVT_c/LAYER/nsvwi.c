#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET VIEW INDEX - create structure  element  containing  view
     index attribute

  FORTRAN Syntax
     SUBROUTINE psvwi ( VIEWI )
     INTEGER     VIEWI             view index
**************************************************************************/
#ifdef NO_PROTO
nsvwi (index)
   integer      *index;
#else
nsvwi (integer *index)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_view_ind ( index )
     Pint        index;            view index
**************************************************************************/

   pset_view_ind ((Pint) *index);
}
