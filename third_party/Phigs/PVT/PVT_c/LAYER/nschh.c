#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET CHARACTER HEIGHT  -  create  structure  element  to  set
     current character height attribute

  FORTRAN Syntax
     SUBROUTINE pschh ( CHH )
     REAL        CHH               character height (TLC)
**************************************************************************/
#ifdef NO_PROTO
nschh (chh)
   real    *chh;
#else
nschh (real *chh)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_char_ht ( height )
     Pfloat      height;           character height
**************************************************************************/

   pset_char_ht ((Pfloat) *chh);
}
