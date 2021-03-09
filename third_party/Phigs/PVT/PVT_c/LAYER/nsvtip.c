#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     SET VIEW TRANSFORMATION INPUT  PRIORITY  -  assign  relative
     priority  of  view  representation  to use when transforming
     input values

  FORTRAN Syntax
     SUBROUTINE psvtip ( WKID, VIEWI, RFVWIX, RELPRI )
     INTEGER     WKID              workstation identifier
     INTEGER     VIEWI             view index
     INTEGER     RFVWIX            reference view index
     INTEGER     RELPRI            relative priority (PHIGHR, PLOWER)
**************************************************************************/
#ifdef NO_PROTO
nsvtip (wkid, viewi, rfvwix, relpri)
   integer      *wkid,
            *viewi,
            *rfvwix,
            *relpri;
#else
nsvtip (integer *wkid, integer *viewi, integer *rfvwix, integer *relpri)
#endif
{
   Prel_pri  priority;

   priority = *relpri;
   switch (*relpri)
   {
   case 0:
      priority = PPRI_HIGHER;
      break;
   case 1:
      priority = PPRI_LOWER;
      break;
   }

/**************************************************************************
  C Syntax
     void
     pset_view_tran_in_pri ( ws, index, ref_index, priority )
     Pint        ws;               workstation identifier
     Pint        index;            view index
     Pint        ref_index;        reference view index
     Prel_pri    priority;         relative priority
**************************************************************************/

   pset_view_tran_in_pri ((Pint) *wkid, (Pint) *viewi, (Pint) *rfvwix, 
                           priority);
}
