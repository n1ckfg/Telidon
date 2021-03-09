#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET COLOUR REPRESENTATION  -  define  colour  representation
     entry in workstation's colour table

  FORTRAN Syntax
     SUBROUTINE pscr ( WKID, CI, NCCS, CSPEC )
     INTEGER     WKID              workstation identifier
     INTEGER     CI                colour index
     INTEGER     NCCS              number of components of colour specification
     REAL        CSPEC             colour specification
**************************************************************************/
#ifdef NO_PROTO
nscr (wkid, coli, ccsbsz, cspec)
   integer      *wkid,
            *coli,
            *ccsbsz;
   real     cspec[];
#else
nscr (integer *wkid, integer *coli, integer *ccsbsz, real cspec[])
#endif
{
   Pcolr_rep col_rep;

   /*  All of the "required" color models (RGB/CIE) have 3 reals to
       represent them, so ignore nccs, we know it must
       be 3, and use the rgb structure, since they
       are all the same  */

   col_rep.rgb.red   = cspec[0];
   col_rep.rgb.green = cspec[1];
   col_rep.rgb.blue  = cspec[2];

/**************************************************************************
  C Syntax
     void
     pset_colr_rep ( ws, index, rep )
     Pint        ws;               workstation identifier
     Pint        index;            colour bundle index
     Pcolr_rep   *rep;             colour representation pointer
**************************************************************************/

   pset_colr_rep ((Pint) *wkid, (Pint) *coli, &col_rep);
}
