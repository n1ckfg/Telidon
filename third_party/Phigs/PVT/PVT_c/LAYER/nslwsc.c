#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET LINEWIDTH SCALE FACTOR - create structure element to set
     current linewidth scale factor attribute

  FORTRAN Syntax
     SUBROUTINE pslwsc ( LWIDTH )
     REAL        LWIDTH            linewidth scale factor
**************************************************************************/
#ifdef NO_PROTO
nslwsc (lwidth)
   real    *lwidth;
#else
nslwsc (real *lwidth)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_linewidth ( width )
     Pfloat      width;            linewidth scale factor
**************************************************************************/

   pset_linewidth ((Pfloat) *lwidth);
}
