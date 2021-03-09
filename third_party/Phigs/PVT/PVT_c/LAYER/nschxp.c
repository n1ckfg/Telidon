#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET CHARACTER EXPANSION FACTOR - create structure element to
     set current character expansion factor attribute

  FORTRAN Syntax
     SUBROUTINE pschxp ( CHXP )
     REAL        CHXP              character expansion factor
**************************************************************************/
#ifdef NO_PROTO
nschxp (chxp)
   real    *chxp;
#else
nschxp (real *chxp)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_char_expan ( exp_factor )
     Pfloat      exp_factor;       character expansion factor
**************************************************************************/

   pset_char_expan ((Pfloat) *chxp);
}
