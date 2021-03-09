#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET ERROR HANDLING MODE - set current error handling mode

  FORTRAN Syntax
     SUBROUTINE pserhm ( ERHM )
     INTEGER     ERHM              error handling mode (POFF, PON)
**************************************************************************/
#ifdef NO_PROTO
nserhm (erhm)
   integer      *erhm;
#else
nserhm (integer *erhm)
#endif
{
   Perr_mode mode;

   mode = *erhm;
   switch (*erhm)
   {
   case 0:
      mode = PERR_OFF;
      break;
   case 1:
      mode = PERR_ON;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_err_hand_mode ( mode )
     Perr_mode   mode;             error handling mode
**************************************************************************/

   pset_err_hand_mode (mode);
}
