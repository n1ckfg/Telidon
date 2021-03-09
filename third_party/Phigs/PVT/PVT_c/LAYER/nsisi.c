#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET INTERIOR STYLE INDEX - create structure element  to  set
     current interior style index attribute

  FORTRAN Syntax
     SUBROUTINE psisi ( ISTYLI )
     INTEGER     ISTYLI            interior style index
**************************************************************************/
#ifdef NO_PROTO
nsisi (istyli)
   integer      *istyli;
#else
nsisi (integer *istyli)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_int_style_ind ( index )
     Pint        index;            interior style index
**************************************************************************/

   pset_int_style_ind ((Pint) *istyli);
}
