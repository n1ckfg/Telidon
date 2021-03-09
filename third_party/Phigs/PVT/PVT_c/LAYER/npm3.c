#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     POLYMARKER 3 - create structure element specifying 3D  poly-
     marker primitive

  FORTRAN Syntax
     SUBROUTINE ppm3 ( N, PXA, PYA, PZA )
     INTEGER     N                 number of points
     REAL        PXA(N), PYA(N), PZA(N)coordinates of points (MC)
**************************************************************************/
#ifdef NO_PROTO
npm3 (n, xcord, ycord, zcord)
   integer      *n;
   real     xcord[],
             ycord[],
             zcord[];
#else
npm3 (integer *n, real xcord[], real ycord[], real zcord[])
#endif
{
   int       i;

   Ppoint3  *mark;
   Ppoint_list3 marks;
   mark = (Ppoint3 *) calloc (*n, sizeof (Ppoint3));

   for (i = 0; i <= (*n - 1); i++)
   {
      mark[i].x = xcord[i];
      mark[i].y = ycord[i];
      mark[i].z = zcord[i];
   }
   marks.num_points = *n;
   marks.points = mark;

/**************************************************************************
  C Syntax
     void
     ppolymarker3 ( point_list )
     Ppoint_list3                  *point_list;list of points
**************************************************************************/

   ppolymarker3 (&marks);
   free (mark);
}
