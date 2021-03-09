#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE ERROR HANDLING MODE - obtain current error  handling
     mode

  FORTRAN Syntax
     SUBROUTINE pqerhm ( ERRIND, ERHM )
     INTEGER     ERRIND            OUT error indicator
     INTEGER     ERHM              OUT error handling mode (POFF, PON)
**************************************************************************/
#ifdef NO_PROTO
nqerhm (errind, erhm)
   integer      *errind,
            *erhm;
#else
nqerhm (integer *errind, integer *erhm)
#endif
{
   Perr_mode mode;
   Pint cerror;
/**************************************************************************
  C Syntax
     void
     pinq_err_hand_mode ( errind, mode )
     Pint        *errind;          OUT error indicator
     Perr_mode   *mode;            OUT error mode
**************************************************************************/

   pinq_err_hand_mode (&cerror, &mode);
   *errind = cerror;

   *erhm = mode;
   if (mode == PERR_OFF) *erhm = 0;
   if (mode == PERR_ON)  *erhm = 1;
}
