#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     FILL AREA 3 - create structure element  specifying  3D  fill
     area primitive

  FORTRAN Syntax
     SUBROUTINE pfa3 ( N, PXA, PYA, PZA )
     INTEGER     N                 number of points
     REAL        PXA(N), PYA(N), PZA(N)coordinates of points (MC)
**************************************************************************/
#ifdef NO_PROTO
nfa3 (n, pxa, pya, pza)
   integer      *n;
   real     pxa[],
             pya[],
             pza[];
#else
nfa3 (integer *n, real pxa[], real pya[], real pza[])
#endif
{
   int       i;

   Ppoint3  *point;
   Ppoint_list3 point_list;
   point = (Ppoint3 *) calloc (*n, sizeof (Ppoint3));

   for (i = 0; i <= (*n - 1); i++)
   {
      point[i].x = pxa[i];
      point[i].y = pya[i];
      point[i].z = pza[i];
   }

   point_list.num_points = *n;
   point_list.points = point;

/**************************************************************************
  C Syntax
     void
     pfill_area3 ( point_list )
     Ppoint_list3                  *point_list;array of points
**************************************************************************/

   pfill_area3 (&point_list);
   free (point);
}
