#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET PATTERN REFERENCE POINT - create  structure  element  to
     set current pattern reference point attribute

  FORTRAN Syntax
     SUBROUTINE psparf ( RFX, RFY )
     REAL        RFX, RFY          pattern reference point (MC)
**************************************************************************/
#ifdef NO_PROTO
nsparf (rfx, rfy)
   real    *rfx,
            *rfy;
#else
nsparf (real *rfx, real *rfy)
#endif
{
   Ppoint    ref_pt;
   ref_pt.x = *rfx;
   ref_pt.y = *rfy;

/**************************************************************************
  C Syntax
     void
     pset_pat_ref_point ( ref_pt )
     Ppoint      *ref_pt;          pattern reference point
**************************************************************************/

   pset_pat_ref_point (&ref_pt);
}
