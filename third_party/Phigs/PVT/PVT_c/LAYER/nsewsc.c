#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET EDGEWIDTH SCALE FACTOR - create structure element to set
     current edgewidth scale factor attribute

  FORTRAN Syntax
     SUBROUTINE psewsc ( EWIDTH )
     REAL        EWIDTH            edgewidth scale factor
**************************************************************************/
#ifdef NO_PROTO
nsewsc (ewidth)
   real    *ewidth;
#else
nsewsc (real *ewidth)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_edgewidth ( scale )
     Pfloat      scale;            edgewidth scale factor
**************************************************************************/

   pset_edgewidth ((Pfloat) *ewidth);
}
