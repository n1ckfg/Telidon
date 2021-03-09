#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE DISPLAY SPACE SIZE 3- obtain display space  size  of
     workstation type

  FORTRAN Syntax
     SUBROUTINE pqdsp3 ( WTYPE, ERRIND, DCUNIT, DX, DY, DZ, RX, RY, RZ )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     DCUNIT            OUT device coordinate units (PMETRE, POTHU)
     REAL        DX, DY, DZ        OUT maximum display surface size (DC)
     INTEGER     RX, RY, RZ        OUT maximum display surface size (raster units)
**************************************************************************/
#ifdef NO_PROTO
nqdsp3 (wtype, errind, dcunit, dx, dy, dz, rx, ry, rz)
   integer      *wtype,
            *errind,
            *dcunit,
            *rx,
            *ry,
            *rz;
   real    *dx,
            *dy,
            *dz;
#else
nqdsp3 (integer *wtype, integer *errind, integer *dcunit, real *dx, real *dy, real *dz,
	integer *rx, integer *ry, integer *rz)
#endif
{
   Pdisp_space_size3 size;
   Pint cerror;
/**************************************************************************
  C Syntax
     void
     pinq_disp_space_size3 ( type, errind, size )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pdisp_space_size3             *size;OUT display size
**************************************************************************/

   pinq_disp_space_size3 ((Pint) *wtype, &cerror, &size);
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
   *dz = size.size_dc.size_z;

   *rx = size.size_raster.size_x;
   *ry = size.size_raster.size_y;
   *rz = size.size_raster.size_z;
}
