#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     POLYLINE - create structure element specifying 2D polyline

  FORTRAN Syntax
     SUBROUTINE ppl ( N, PXA, PYA )
     INTEGER     N                 number of points
     REAL        PXA(N), PYA(N)    coordinates of points (MC)
**************************************************************************/
#ifdef NO_PROTO
npl (n, xcord, ycord)
   integer      *n;
   real     xcord[],
             ycord[];
#else
npl (integer *n, real xcord[], real ycord[])
#endif
{
   int       i;

   Ppoint   *line;
   Ppoint_list lines;
   line = (Ppoint *) calloc (*n, sizeof (Ppoint));

   for (i = 0; i <= (*n - 1); i++)
   {
      line[i].x = xcord[i];
      line[i].y = ycord[i];
   }
   lines.num_points = *n;
   lines.points = line;

/**************************************************************************
  C Syntax
     void
     ppolyline ( point_list )
     Ppoint_list *point_list;      list of points
**************************************************************************/

   ppolyline (&lines);
   free (line);
}
