#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     REQUEST VALUATOR - request operator interaction with  speci-
     fied valuator device

  FORTRAN Syntax
     SUBROUTINE prqvl ( WKID, VLDNR, STAT, VAL )
     INTEGER     WKID              workstation identifier
     INTEGER     VLDNR             valuator device number
     INTEGER     STAT              OUT status (PNONE, POK)
     REAL        VAL               OUT value
**************************************************************************/
#ifdef NO_PROTO
nrqvl (wkid, vldnr, stat, val)
   integer      *wkid,
            *vldnr,
            *stat;
   real    *val;
#else
nrqvl (integer *wkid, integer *vldnr, integer *stat, real *val)
#endif
{
   Pfloat  cval;
   Pin_status in_status;
/**************************************************************************
  C Syntax
     void
     preq_val ( ws, dev, in_status, value )
     Pint        ws;               workstation identifier
     Pint        dev;              valuator device number
     Pin_status  *in_status;       OUT input status
     Pfloat      *value;           OUT value
**************************************************************************/

   preq_val ((Pint) *wkid, (Pint) *vldnr, &in_status, &cval);
   *val = cval;

   *stat = in_status;
   switch (in_status)
   {
   case PIN_STATUS_NONE:
      *stat = 0;
      break;
   case PIN_STATUS_OK:
      *stat = 1;
      break;
   case PIN_STATUS_NO_IN:
      *stat = 2;
      break;
   }
}
