#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE PATTERN  FACILITIES  -  inquire  pattern  facilities
     available on a workstation type

  FORTRAN Syntax
     SUBROUTINE pqpaf ( WTYPE, ERRIND, NPPAI )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NPPAI             OUT number of predefined pattern indices
**************************************************************************/
#ifdef NO_PROTO
nqpaf (wtype, errind, nppai)
   integer      *wtype,
            *errind,
            *nppai;
#else
nqpaf (integer *wtype, integer *errind, integer *nppai)
#endif
{
   Pint  npre, cerror;

/**************************************************************************
  C Syntax
     void
     pinq_pat_facs (type, errind, predefined )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pint        *predefined;      OUT number of predefined pattern indices
**************************************************************************/

   pinq_pat_facs ((Pint) *wtype, &cerror, &npre);
   *errind = cerror;
   *nppai = npre;
}
