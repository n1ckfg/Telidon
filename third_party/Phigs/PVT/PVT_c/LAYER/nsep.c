#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET ELEMENT POINTER  -  set  element  pointer  to  specified
     pointer value

  FORTRAN Syntax
     SUBROUTINE psep ( EP )
     INTEGER     EP                element position
**************************************************************************/
#ifdef NO_PROTO
nsep (ep)
   integer      *ep;
#else
nsep (integer *ep)
#endif
{

/**************************************************************************
  C Syntax
     void
     pset_elem_ptr ( ep_value )
     Pint        ep_value;         element pointer value
**************************************************************************/

   pset_elem_ptr ((Pint) *ep);
}
