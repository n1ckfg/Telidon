#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     POLYMARKER - create structure element  specifying  2D  poly-
     marker primitive

  FORTRAN Syntax
     SUBROUTINE ppm ( N, PXA, PYA )
     INTEGER     N                 number of points
     REAL        PXA(N), PYA(N)    coordinates of points (MC)
**************************************************************************/
#ifdef NO_PROTO
npm (n, xcord, ycord)
   integer      *n;
   real     xcord[],
             ycord[];
#else
npm (integer *n, real xcord[], real ycord[])
#endif
{
   int       i;

   Ppoint   *mark;
   Ppoint_list marks;
   mark = (Ppoint *) calloc (*n, sizeof (Ppoint));

   for (i = 0; i <= (*n - 1); i++)
   {
      mark[i].x = xcord[i];
      mark[i].y = ycord[i];
   }
   marks.num_points = *n;
   marks.points = mark;

/**************************************************************************
  C Syntax
     void
     ppolymarker ( point_list )
     Ppoint_list *point_list;      list of points
**************************************************************************/

   ppolymarker (&marks);
   free (mark);
}
