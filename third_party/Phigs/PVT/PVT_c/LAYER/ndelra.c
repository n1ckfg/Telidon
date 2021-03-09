#include <phigs.h>
#include "f2c.h"

/*************************************************************************
NAME
     DELETE ELEMENT RANGE - delete  a  block  of  elements  in  a
     structure

  FORTRAN Syntax
     SUBROUTINE pdelra ( EP1, EP2 )
     INTEGER     EP1, EP2          element pointer range
*************************************************************************/
#ifdef NO_PROTO
ndelra (ep1, ep2)
   integer      *ep1,
            *ep2;
#else
ndelra (integer *ep1, integer *ep2)
#endif
{

/*************************************************************************
  C Syntax
     void
     pdel_elem_range ( ep1_value, ep2_value )
     Pint        ep1_value;        element pointer 1 value
     Pint        ep2_value;        element pointer 2 value
*************************************************************************/

   pdel_elem_range ((Pint) *ep1, (Pint) *ep2);
}
