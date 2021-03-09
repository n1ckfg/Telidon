#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     OPEN STRUCTURE -  create  new  structure  or  begin  editing
     existing structure

  FORTRAN Syntax
     SUBROUTINE popst ( STRID )
     INTEGER     STRID             structure identifier
**************************************************************************/
#ifdef NO_PROTO
nopst (strid)
   integer      *strid;
#else
nopst (integer *strid)
#endif
{

/**************************************************************************
  C Syntax
     void
     popen_struct ( struct_id )
     Pint        struct_id;        structure identifier
**************************************************************************/

   popen_struct ((Pint) *strid);
}
