#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE DISPLAY SPACE SIZE- obtain  display  space  size  of
     workstation type

  FORTRAN Syntax
     SUBROUTINE pqdsp ( WTYPE, ERRIND, DCUNIT, DX, DY, RX, RY )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     DCUNIT            OUT device coordinate units (PMETRE, POTHU)
     REAL        DX, DY            OUT max display surface size (DC)
     INTEGER     RX, RY            OUT max display surface size (raster units)
**************************************************************************/
#ifdef NO_PROTO
nqdsp (wtype, errind, dcunit, dx, dy, rx, ry)
   integer      *wtype,
            *errind,
            *dcunit,
            *rx,
            *ry;
   real    *dx,
            *dy;
#else
nqdsp (integer *wtype, integer *errind, integer *dcunit, real *dx, real *dy,
       integer *rx, integer *ry)
#endif
{
   Pdisp_space_size size;
   Pint cerror;
/**************************************************************************
  C Syntax
     void
     pinq_disp_space_size ( type, errind, size )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pdisp_space_size              *size;OUT display size
**************************************************************************/

   pinq_disp_space_size ((Pint) *wtype, &cerror, &size);
   *errind = cerror;

   *dcunit = size.dc_units;
   switch (size.dc_units)
   {
   case PDC_METRES:
      *dcunit = 0;
      break;
   case PDC_OTHER:
      *dcunit = 1;
      break;
   }

   *dx = size.size_dc.size_x;
   *dy = size.size_dc.size_y;

   *rx = size.size_raster.size_x;
   *ry = size.size_raster.size_y;
}
