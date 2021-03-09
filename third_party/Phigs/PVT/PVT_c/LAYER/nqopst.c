#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE OPEN STRUCTURE - inquire the status of the currently
     opened structure

  FORTRAN Syntax
     SUBROUTINE pqopst ( ERRIND, STYPE, STRID )
     INTEGER     ERRIND            OUT error indicator
     INTEGER     STYPE             OUT open structure status (PNONST, POPNST)
     INTEGER     STRID             OUT structure identifier
**************************************************************************/
#ifdef NO_PROTO
nqopst (errind, stype, strid)
   integer   *errind,
            *stype,
            *strid;
#else
nqopst (integer *errind, integer *stype, integer *strid)
#endif
{
   Pint   cerror, cstrid;
   Popen_struct_status status;
/**************************************************************************
  C Syntax
     void
     pinq_open_struct ( errind, status, struct_id )
     Pint        *errind;          OUT error indicator
     Popen_struct_status           *status;OUT status of open structure
     Pint        *struct_id;       OUT structure identifier
**************************************************************************/

   pinq_open_struct (&cerror, &status, &cstrid);
   *errind = cerror;
   *strid  = cstrid;

   *stype = status;
   if (status == PSTRUCT_NONE) *stype = 0;
   if (status == PSTRUCT_OPEN) *stype = 1;
}
