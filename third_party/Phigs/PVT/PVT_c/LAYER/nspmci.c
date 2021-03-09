#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET POLYMARKER COLOUR INDEX - create  structure  element  to
     set current polymarker colour index attribute

  FORTRAN Syntax
     SUBROUTINE pspmci ( COLI )
     INTEGER     COLI              polymarker colour index
**************************************************************************/
#ifdef NO_PROTO
nspmci (coli)
   integer      *coli;
#else
nspmci (integer *coli)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_marker_colr_ind ( colour )
     Pint        colour;           polymarker colour index
**************************************************************************/

   pset_marker_colr_ind ((Pint) *coli);
}
