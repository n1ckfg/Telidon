#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE STRUCTURE STATUS - obtain status of specified struc-
     ture

  FORTRAN Syntax
     SUBROUTINE pqstst ( STRID, ERRIND, STRSTI )
     INTEGER     STRID             structure identifier
     INTEGER     ERRIND            OUT error indicator
     INTEGER     STRSTI            OUT structure status indicator
**************************************************************************/
#ifdef NO_PROTO
nqstst (strid, errind, strsti)
   integer      *strid,
            *errind,
            *strsti;
#else
nqstst (integer *strid, integer *errind, integer *strsti)
#endif
{
   Pint  cerror;
   Pstruct_status status;
/**************************************************************************
  C Syntax
     void
     pinq_struct_status ( struct_id, errind, status )
     Pint        struct_id;        structure identifier
     Pint        *errind;          OUT error indicator
     Pstruct_status                *struct;OUT existence status
**************************************************************************/

   pinq_struct_status ((Pint) *strid, &cerror, &status);
   *errind = cerror;

   *strsti = status;
   switch (status)
   {
   case PSTRUCT_STATUS_NON_EXISTENT:
      *strsti = 0;
      break;
   case PSTRUCT_STATUS_EMPTY:
      *strsti = 1;
      break;
   case PSTRUCT_STATUS_NOT_EMPTY:
      *strsti = 2;
      break;
   }

}
