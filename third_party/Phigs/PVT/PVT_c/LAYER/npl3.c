#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     POLYLINE 3 - create structure element specifying 3D polyline

  FORTRAN Syntax
     SUBROUTINE ppl3 ( N, PXA, PYA, PZA )
     INTEGER     N                 number of points
     REAL        PXA(N), PYA(N), PZA(N)coordinates of points (MC)
**************************************************************************/
#ifdef NO_PROTO
npl3 (n, xcord, ycord, zcord)
   integer      *n;
   real     xcord[],
             ycord[],
             zcord[];
#else
npl3 (integer *n, real xcord[], real ycord[], real zcord[])
#endif
{
   int       i;

   Ppoint3  *line;
   Ppoint_list3 lines;
   line = (Ppoint3 *) calloc (*n, sizeof (Ppoint3));

   for (i = 0; i <= (*n - 1); i++)
   {
      line[i].x = xcord[i];
      line[i].y = ycord[i];
      line[i].z = zcord[i];
   }
   lines.num_points = *n;
   lines.points = line;

/**************************************************************************
  C Syntax
     void
     ppolyline3 ( point_list )
     Ppoint_list3                  *point_list;list of points
**************************************************************************/

   ppolyline3 (&lines);
   free (line);
}
