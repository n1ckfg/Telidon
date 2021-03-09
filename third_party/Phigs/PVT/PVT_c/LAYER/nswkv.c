#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET WORKSTATION VIEWPORT   -  set  2D  viewport  limits  for
     specified workstation

  FORTRAN Syntax
     SUBROUTINE pswkv ( WKID, XMIN, XMAX, YMIN, YMAX )
     INTEGER     WKID                workstation identifier
     REAL        XMIN, XMAX, YMIN, YMAXworkstation viewport limits (DC)
**************************************************************************/
#ifdef NO_PROTO
nswkv (wkid, xmin, xmax, ymin, ymax)
   integer      *wkid;
   real    *xmin,
            *xmax,
            *ymin,
            *ymax;
#else
nswkv (integer *wkid, real *xmin, real *xmax, real *ymin, real *ymax)
#endif
{
   Plimit    viewport;
   viewport.x_min = *xmin;
   viewport.x_max = *xmax;
   viewport.y_min = *ymin;
   viewport.y_max = *ymax;

/**************************************************************************
  C Syntax
     void
     pset_ws_vp ( ws, viewport )
     Pint           ws;              workstation id
     Plimit         *viewport;       workstation viewport limits
**************************************************************************/

   pset_ws_vp ((Pint) *wkid, &viewport);
}
