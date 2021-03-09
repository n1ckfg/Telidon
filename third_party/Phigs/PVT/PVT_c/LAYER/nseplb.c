#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET ELEMENT POINTER AT LABEL  set element  pointer  to  next
     occurrence of specified label

  FORTRAN Syntax
     SUBROUTINE pseplb ( LABEL )
     INTEGER     LABEL             label identifier
**************************************************************************/
#ifdef NO_PROTO
nseplb (label)
   integer      *label;
#else
nseplb (integer *label)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_elem_ptr_label ( label_id )
     Pint        label_id;         label identifier
**************************************************************************/

   pset_elem_ptr_label ((Pint) *label);
}
