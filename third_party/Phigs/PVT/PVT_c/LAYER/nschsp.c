#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET CHARACTER SPACING -  create  structure  element  to  set
     current character spacing attribute

  FORTRAN Syntax
     SUBROUTINE pschsp ( CHSP )
     REAL        CHSP              character spacing
**************************************************************************/
#ifdef NO_PROTO
nschsp (chsp)
   real    *chsp;
#else
nschsp (real *chsp)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_char_space ( spacing )
     Pfloat      spacing;          character spacing
**************************************************************************/

   pset_char_space ((Pfloat) *chsp);
}
