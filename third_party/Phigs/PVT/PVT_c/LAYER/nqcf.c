#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE COLOUR FACILITIES - obtain workstation type's colour
     facilities

  FORTRAN Syntax
     SUBROUTINE pqcf ( WTYPE, ERRIND, NCOLI, COLA, NPCI, CC )
     INTEGER     WTYPE             workstation type
     INTEGER     ERRIND            OUT error indicator
     INTEGER     NCOLI             OUT number of colours
     INTEGER     COLA              OUT colour available (PMONOC, PCOLOR)
     INTEGER     NPCI              OUT number of predefined colour indices
     REAL        CC(9)             OUT primary colour chromaticity coefficients
                                         and luminance value
**************************************************************************/
#ifdef NO_PROTO
nqcf (wtype, errind, ncoli, cola, npci, cc)
   integer      *wtype,
            *errind,
            *ncoli,
            *cola,
            *npci;
   real     cc[];
#else
nqcf (integer *wtype, integer *errind, integer *ncoli, integer *cola, integer *npci, real cc[])
#endif
{
   Pcolr_facs facilities;
   Pint cerror;

/**************************************************************************
  C Syntax
     void
     pinq_colr_facs ( type, errind, facilities )
     Pint        type;             workstation type
     Pint        *errind;          OUT error indicator
     Pcolr_facs  *facilities;      OUT colour facilities
**************************************************************************/

   pinq_colr_facs ((Pint) *wtype, &cerror, &facilities);
   *errind = cerror;

   *ncoli = facilities.num_colrs;

   *cola = facilities.colr_avail;
   if (facilities.colr_avail == PAVAIL_COLR)    *cola = 1;
   if (facilities.colr_avail == PAVAIL_MONOCHR) *cola = 0;

   *npci = facilities.num_pred_inds;

/***   Red ***/
   cc[0] = facilities.prim_colrs[0].cieluv_x;
   cc[1] = facilities.prim_colrs[0].cieluv_y;
   cc[2] = facilities.prim_colrs[0].cieluv_y_lum;

/***   Green ***/
   cc[3] = facilities.prim_colrs[1].cieluv_x;
   cc[4] = facilities.prim_colrs[1].cieluv_y;
   cc[5] = facilities.prim_colrs[1].cieluv_y_lum;
/***   Blue ***/
   cc[6] = facilities.prim_colrs[2].cieluv_x;
   cc[7] = facilities.prim_colrs[2].cieluv_y;
   cc[8] = facilities.prim_colrs[2].cieluv_y_lum;

}
