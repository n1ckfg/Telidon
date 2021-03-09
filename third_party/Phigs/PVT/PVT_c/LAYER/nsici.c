#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET INTERIOR COLOUR INDEX - create structure element to  set
     current interior colour index attribute

  FORTRAN Syntax
     SUBROUTINE psici ( COLI )
     INTEGER     COLI              interior colour index
**************************************************************************/
#ifdef NO_PROTO
nsici (coli)
   integer      *coli;
#else
nsici (integer *coli)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_int_colr_ind ( index )
     Pint        index;            interior colour index
**************************************************************************/

   pset_int_colr_ind ((Pint) *coli);
}
