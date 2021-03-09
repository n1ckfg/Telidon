#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE NUMBER OF AVAILABLE LOGICAL INPUT DEVICES -  inquire
     the  number  of available logical input devices for a speci-
     fied workstation type

  FORTRAN Syntax
     SUBROUTINE pqli ( WTYPE, ERRIND, NLCD, NSKD, NVLD, NCHD, NPKD, NSTD )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NLCD              OUT number of locator devices
     INTEGER     NSKD              OUT number of stroke devices
     INTEGER     NVLD              OUT number of valuator devices
     INTEGER     NCHD              OUT number of choice devices
     INTEGER     NPKD              OUT number of pick devices
     INTEGER     NSTD              OUT number of string devices
**************************************************************************/
#ifdef NO_PROTO
nqli (wtype, errind, nlcd, nskd, nvld, nchd, npkd, nstd)
   integer      *wtype,
            *errind,
            *nlcd,
            *nskd,
            *nvld,
            *nchd,
            *npkd,
            *nstd;
#else
nqli (integer *wtype, integer *errind, integer *nlcd, integer *nskd, 
      integer *nvld, integer *nchd,
      integer *npkd, integer *nstd)
#endif
{
   Pint      cerror;
   Pnum_in   devices;
/**************************************************************************
  C Syntax
     void
     pinq_num_avail_in ( type, errind, numbers )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pnum_in     *numbers;         OUT number of input devices
**************************************************************************/

   pinq_num_avail_in ((Pint) *wtype, &cerror, &devices);
   *errind = cerror;

   *nlcd = devices.loc;
   *nskd = devices.stroke;
   *nvld = devices.val;
   *nchd = devices.choice;
   *npkd = devices.pick;
   *nstd = devices.string;

}
