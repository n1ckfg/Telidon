#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET WORKSTATION WINDOW 3 - specify 3D window to be displayed
     on specified workstation

  FORTRAN Syntax
     SUBROUTINE pswkw3 ( WKID, WKWN )
     INTEGER     WKID              workstation identifier
     REAL        WKWN(6)           workstation window limits (NPC)
                                   (XMIN, XMAX, YMIN, YMAX, ZMIN, ZMAX)
**************************************************************************/
#ifdef NO_PROTO
nswkw3 (wkid, wkwn)
   integer      *wkid;
   real     wkwn[];
#else
nswkw3 (integer *wkid, real wkwn[])
#endif
{
   Plimit3   window;
   window.x_min = wkwn[0];
   window.x_max = wkwn[1];
   window.y_min = wkwn[2];
   window.y_max = wkwn[3];
   window.z_min = wkwn[4];
   window.z_max = wkwn[5];

/**************************************************************************
  C Syntax
     void
     pset_ws_win3 ( ws, window )
     Pint           ws;            workstation id
     Plimit3        *window;       workstation window limits
**************************************************************************/

   pset_ws_win3 ((Pint) *wkid, &window);
}
