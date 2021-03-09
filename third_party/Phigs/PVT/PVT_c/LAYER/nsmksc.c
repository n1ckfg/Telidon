#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET MARKER SIZE SCALE FACTOR - create structure  element  to
     set current marker size scale factor attribute

  FORTRAN Syntax
     SUBROUTINE psmksc ( MSZSF )
     REAL        MSZSF             marker size scale factor
**************************************************************************/
#ifdef NO_PROTO
nsmksc (mszsf)
   real    *mszsf;
#else
nsmksc (real *mszsf)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_marker_size ( size )
     Pfloat      size;             marker size scale factor
**************************************************************************/

   pset_marker_size ((Pfloat) *mszsf);
}
