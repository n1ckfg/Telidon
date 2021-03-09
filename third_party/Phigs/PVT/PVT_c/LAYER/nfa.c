#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     FILL AREA - create structure element specifying 2D fill area
     primitive

  FORTRAN Syntax
     SUBROUTINE pfa ( N, PXA, PYA )
     INTEGER     N                 number of points
     REAL        PXA(N), PYA(N)    coordinates of points (MC)
**************************************************************************/
#ifdef NO_PROTO
nfa (n, pxa, pya)
   integer      *n;
   real     pxa[],
             pya[];
#else
nfa (integer *n, real pxa[], real pya[])
#endif
{
   int       i;

   Ppoint   *point;
   Ppoint_list point_list;
   point = (Ppoint *) calloc (*n, sizeof (Ppoint));

   for (i = 0; i <= (*n - 1); i++)
   {
      point[i].x = pxa[i];
      point[i].y = pya[i];
   }

   point_list.num_points = *n;
   point_list.points = point;

/**************************************************************************
  C Syntax
     void
     pfill_area ( point_list )
     Ppoint_list *point_list;      array of points
**************************************************************************/

   pfill_area (&point_list);
   free (point);
}
