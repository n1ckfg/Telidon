#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     EXECUTE STRUCTURE  -  create  structure  element  to  invoke
     another structure

  FORTRAN Syntax
     SUBROUTINE pexst ( STRID )
     INTEGER     STRID             structure identifier
**************************************************************************/
#ifdef NO_PROTO
nexst (strid)
   integer      *strid;
#else
nexst (integer *strid)
#endif
{

/**************************************************************************
  C Syntax
     void
     pexec_struct ( struct_id )
     Pint        struct_id;        structure identifier
**************************************************************************/

   pexec_struct ((Pint) *strid);
}
