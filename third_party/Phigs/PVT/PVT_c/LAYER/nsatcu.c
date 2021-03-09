#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET ANNOTATION TEXT CHARACTER UP VECTOR -  create  structure
     element  to  set current annotation text character up vector
     attribute

  FORTRAN Syntax
     SUBROUTINE psatcu ( ATCHUX, ATCHUY )
     REAL        ATCHUX, ATCHUY    annotation text character up vector (TLC)
**************************************************************************/
#ifdef NO_PROTO
nsatcu (atchux, atchuy)
   real    *atchux,
            *atchuy;
#else
nsatcu (real *atchux, real *atchuy)
#endif
{
   Pvec      up_vect;
   up_vect.delta_x = *atchux;
   up_vect.delta_y = *atchuy;

/**************************************************************************
  C Syntax
     void
     pset_anno_char_up_vec ( up_vect )
     Pvec           *up_vect;      character up vector
**************************************************************************/

   pset_anno_char_up_vec (&up_vect);
}
