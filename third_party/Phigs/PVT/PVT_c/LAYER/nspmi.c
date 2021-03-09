#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET POLYMARKER INDEX - create structure  element  containing
     polymarker representation index attribute

  FORTRAN Syntax
     SUBROUTINE pspmi ( PMI )
     INTEGER     PMI               polymarker index
**************************************************************************/
#ifdef NO_PROTO
nspmi (pmi)
   integer      *pmi;
#else
nspmi (integer *pmi)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_marker_ind ( index )
     Pint        index;            polymarker index
**************************************************************************/

   pset_marker_ind ((Pint) *pmi);
}
