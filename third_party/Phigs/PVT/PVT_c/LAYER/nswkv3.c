#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET WORKSTATION VIEWPORT 3 -  set  3D  viewport  limits  for
     specified workstation

  FORTRAN Syntax
     SUBROUTINE pswkv3 ( WKID, WKVP )
     INTEGER     WKID              workstation identifier
     REAL        WKVP(6)           workstation viewport limits (DC)
                                   (XMIN, XMAX, YMIN, YMAX, ZMIN, ZMAX)
**************************************************************************/
#ifdef NO_PROTO
nswkv3 (wkid, wkvp)
   integer      *wkid;
   real     wkvp[];
#else
nswkv3 (integer *wkid, real wkvp[])
#endif
{
   Plimit3   viewport;
   viewport.x_min = wkvp[0];
   viewport.x_max = wkvp[1];
   viewport.y_min = wkvp[2];
   viewport.y_max = wkvp[3];
   viewport.z_min = wkvp[4];
   viewport.z_max = wkvp[5];

/**************************************************************************
  C Syntax
     void
     pset_ws_vp3 ( ws, viewport )
     Pint           ws;            workstation id
     Plimit3        *viewport;     workstation viewport limits
**************************************************************************/

   pset_ws_vp3 ((Pint) *wkid, &viewport);
}
