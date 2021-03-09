#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     REQUEST STROKE - request operator interaction with specified
     stroke device

  FORTRAN Syntax
     SUBROUTINE prqsk ( WKID, SKDNR, N, STAT, VIEWI, NP, PXA, PYA )
     INTEGER     WKID              workstation identifier
     INTEGER     SKDNR             stroke device number
     INTEGER     N                 maximum number of points
     INTEGER     STAT              OUT status (PNONE, POK)
     INTEGER     VIEWI             OUT view index
     INTEGER     NP                OUT number of points
     REAL        PXA(N), PYA(N)    OUT points in stroke (WC)
**************************************************************************/
#ifdef NO_PROTO
nrqsk (wkid, skdnr, n, stat, view_ind, np, pxa, pya)
   integer      *wkid,
            *skdnr,
            *n,
            *stat,
            *view_ind,
            *np;
   real     pxa[],
             pya[];
#else
nrqsk (integer *wkid, integer *skdnr, integer *n, integer *stat, integer *view_ind, integer *np,
       real pxa[], real pya[])
#endif
{
   Pint      cview, i;
   Pin_status in_status;
   Ppoint_list stroke;
   stroke.points = (Ppoint *) calloc (*n, sizeof (Ppoint));

/**************************************************************************
  C Syntax
     void
     preq_stroke ( ws, dev, in_status, view_ind, stroke )
     Pint        ws;               workstation identifier
     Pint        dev;              stroke device number
     Pin_status  *in_status;       OUT input status
     Pint        *view_ind;        OUT view index
     Ppoint_list *stroke;          OUT stroke
**************************************************************************/

   preq_stroke ((Pint) *wkid, (Pint) *skdnr, &in_status, &cview, &stroke);
   *view_ind = cview;

   *stat = in_status;
   switch (in_status)
   {
   case PIN_STATUS_NONE:
      *stat = 0;
      break;
   case PIN_STATUS_OK:
      *stat = 1;
      break;
   case PIN_STATUS_NO_IN:
      *stat = 2;
      break;
   }

   *np = stroke.num_points;

   for (i = 0; i < *n; i++)
   {
      pxa[i] = stroke.points[i].x;
      pya[i] = stroke.points[i].y;
   }

   free (stroke.points);
}
