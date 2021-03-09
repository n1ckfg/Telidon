#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET CHARACTER UP VECTOR - create structure  element  to  set
     current character up vector attribute

  FORTRAN Syntax
     SUBROUTINE pschup ( CHUX, CHUY )
     REAL        CHUX, CHUY        character up vector (TLC)
**************************************************************************/
#ifdef NO_PROTO
nschup (chux, chuy)
   real    *chux,
            *chuy;
#else
nschup (real *chux, real *chuy)
#endif
{
   Pvec      up_vect;
   up_vect.delta_x = *chux;
   up_vect.delta_y = *chuy;

/**************************************************************************
  C Syntax
     void
     pset_char_up_vec ( up_vect )
     Pvec        *up_vect;         character up vector
**************************************************************************/

   pset_char_up_vec (&up_vect);
}
