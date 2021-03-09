#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE NUMBER OF DISPLAY  PRIORITIES  SUPPORTED  -  inquire
     number of display priorities supported by a workstation type

  FORTRAN Syntax
     SUBROUTINE pqdp ( WTYPE, ERRIND, NSPSUP )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NSPSUP            OUT number of display priorities supported
**************************************************************************/
#ifdef NO_PROTO
nqdp (wtype, errind, nspsup)
   integer      *wtype,
            *errind,
            *nspsup;
#else
nqdp (integer *wtype, integer *errind, integer *nspsup)
#endif
{

   Pint np, cerror;

/**************************************************************************
  C Syntax
     void
     pinq_num_disp_pris ( wst, errind, num_pri )
     Pint        wst;              workstation type
     Pint        *errind;          OUT error indicator
     Pint        *num_pri;         OUT number of display priorities
**************************************************************************/

   pinq_num_disp_pris ((Pint) *wtype, &cerror, &np);
   *errind = cerror;
   *nspsup = np;
}
