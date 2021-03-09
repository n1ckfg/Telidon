#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET POLYLINE INDEX -  create  structure  element  containing
     polyline index attribute

  FORTRAN Syntax
     SUBROUTINE pspli ( PLI )
     INTEGER     PLI               polyline index
**************************************************************************/
#ifdef NO_PROTO
nspli (pli)
   integer      *pli;
#else
nspli (integer *pli)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_line_ind ( index )
     Pint        index;            polyline index
**************************************************************************/

   pset_line_ind ((Pint) *pli);
}
