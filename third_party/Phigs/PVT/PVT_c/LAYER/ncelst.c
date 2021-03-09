#include <phigs.h>
#include "f2c.h"

/************************************************************************
NAME
     COPY ALL ELEMENTS FROM STRUCTURE - copy elements  of  speci-
     fied structure into open structure

  FORTRAN Syntax
     SUBROUTINE pcelst ( STRID )
     INTEGER     STRID             source structure identifier
************************************************************************/


#ifdef NO_PROTO
ncelst (strid)
   integer      *strid;
#else
ncelst (integer *strid)
#endif
{

/************************************************************************
  C Syntax
     void
     pcopy_all_elems_struct ( struct_id )
     Pint        struct_id;        structure identifier
************************************************************************/

   pcopy_all_elems_struct ((Pint) *strid);
}
