#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET INTERIOR INDEX -  create  structure  element  containing
     interior representation index attribute

  FORTRAN Syntax
     SUBROUTINE psii ( II )
     INTEGER     II                interior index
**************************************************************************/
#ifdef NO_PROTO
nsii (ii)
   integer      *ii;
#else
nsii (integer *ii)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_int_ind ( index )
     Pint        index;            interior index
**************************************************************************/

   pset_int_ind ((Pint) *ii);
}
