#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     OFFSET ELEMENT POINTER - move element pointer in open struc-
     ture relative to its current position

  FORTRAN Syntax
     SUBROUTINE posep ( EPO )
     INTEGER     EPO               element pointer offset
**************************************************************************/
#ifdef NO_PROTO
nosep (epo)
   integer      *epo;
#else
nosep (integer *epo)
#endif
{

/**************************************************************************
  C Syntax
     void poffset_elem_ptr ( ep_offset )
     Pint        ep_offset;        element pointer offset
**************************************************************************/

   poffset_elem_ptr ((Pint) *epo);
}
