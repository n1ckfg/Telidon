#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET WORKSTATION WINDOW - specify 2D window to  be  displayed
     on specified workstation

  FORTRAN Syntax
     SUBROUTINE pswkw ( WKID, XMIN, XMAX, YMIN, YMAX )
     INTEGER     WKID                workstation identifier
     REAL        XMIN, XMAX, YMIN, YMAXworkstation window limits (NPC)
**************************************************************************/
#ifdef NO_PROTO
nswkw (wkid, xmin, xmax, ymin, ymax)
   integer      *wkid;
   real    *xmin,
            *xmax,
            *ymin,
            *ymax;
#else
nswkw (integer *wkid, real *xmin, real *xmax, real *ymin, real *ymax)
#endif
{
   Plimit    window;
   window.x_min = *xmin;
   window.x_max = *xmax;
   window.y_min = *ymin;
   window.y_max = *ymax;

/**************************************************************************
  C Syntax
     void
     pset_ws_win ( ws, window )
     Pint           ws;              workstation id
     Plimit         *window;         workstation window limits
**************************************************************************/

   pset_ws_win ((Pint) *wkid, &window);
}
