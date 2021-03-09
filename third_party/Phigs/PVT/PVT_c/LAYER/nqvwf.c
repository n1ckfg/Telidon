#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE VIEW FACILITIES - obtain view facilities of a speci-
     fied workstation type

  FORTRAN Syntax
     SUBROUTINE pqvwf ( WTYPE, ERRIND, NPVWI )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NPVWI             OUT number of predefined view indices
**************************************************************************/
#ifdef NO_PROTO
nqvwf (wtype, errind, npvwi)
   integer      *wtype,
            *errind,
            *npvwi;
#else
nqvwf (integer *wtype, integer *errind, integer *npvwi)
#endif
{
   Pint cvw, cerror;
/**************************************************************************
  C Syntax
     void
     pinq_view_facs ( type, errind, num )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pint        *num;             OUT number of predefined view indices
**************************************************************************/

   pinq_view_facs ((Pint) *wtype, &cerror, &cvw);
   *errind = cerror;
   *npvwi = cvw;
}
