#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET PATTERN SIZE - create structure element to  set  current
     pattern size attribute


  FORTRAN Syntax
     SUBROUTINE pspa ( SZX, SZY )
     REAL        SZX, SZY          pattern size (MC)
**************************************************************************/
#ifdef NO_PROTO
nspa (szx, szy)
   real    *szx,
            *szy;
#else
nspa (real *szx, real *szy)
#endif
{
   Pfloat_size pat_size;
   pat_size.size_x = *szx;
   pat_size.size_y = *szy;
/**************************************************************************
  C Syntax
     void
     pset_pat_size ( pat_size)
     Pfloat_size      *pat_size;           pattern size
**************************************************************************/

   pset_pat_size (&pat_size);
}
