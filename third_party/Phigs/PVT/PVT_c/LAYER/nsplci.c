#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET POLYLINE COLOUR INDEX - create structure element to  set
     current polyline colour index attribute

  FORTRAN Syntax
     SUBROUTINE psplci ( COLI )
     INTEGER     COLI              polyline colour index
**************************************************************************/
#ifdef NO_PROTO
nsplci (coli)
   integer      *coli;
#else
nsplci (integer *coli)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_line_colr_ind ( colour )
     Pint        colour;           polyline colour index
**************************************************************************/

   pset_line_colr_ind ((Pint) *coli);
}
