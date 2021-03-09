#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET EDGE COLOUR INDEX -  create  structure  element  to  set
     current edge colour index attribute

  FORTRAN Syntax
     SUBROUTINE psedci ( COLI )
     INTEGER     COLI              edge colour index
**************************************************************************/
#ifdef NO_PROTO
nsedci (coli)
   integer      *coli;
#else
nsedci (integer *coli)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_edge_colr_ind ( index )
     Pint        index;            edge colour index
**************************************************************************/

   pset_edge_colr_ind ((Pint) *coli);
}
