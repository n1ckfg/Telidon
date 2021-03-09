#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     FILL AREA SET - create structure element specifying 2D  fill
     area set primitive

  FORTRAN Syntax
     SUBROUTINE pfas ( NPL, IXA, PXA, PYA )
     INTEGER     NPL               number of point lists
     INTEGER     IXA(NPL)          array of end indices for the point lists
     REAL        PXA(*), PYA(*)    coordinates of points (MC)
**************************************************************************/
#ifdef NO_PROTO
nfas (npl, ixa, pxa, pya)
   integer      *npl,
             ixa[];
   real     pxa[],
             pya[];
#else
nfas (integer *npl, integer ixa[], real pxa[], real pya[])
#endif
{
   int       i = 0,
             nump = 0;
   int       prev_endpoint = 0,
             end_point = 0;

   Ppoint_list_list fas_points_list;
   Ppoint_list *fas_points;
   Ppoint   *point;


/** Allocate room to hold the npl (number) of sets **/

   fas_points = (Ppoint_list *) calloc (*npl, sizeof (Ppoint_list));


   for (i = 0; i < *npl; i++)
   {

      end_point = ixa[i];
   /** Allocate room to hold the points **/

      point = (Ppoint *) calloc (end_point - prev_endpoint, sizeof (Ppoint));
      fas_points[i].num_points = end_point - prev_endpoint;

      for (nump = 0; nump < end_point - prev_endpoint; nump++)
      {
	 point[nump].x = pxa[nump + prev_endpoint];
	 point[nump].y = pya[nump + prev_endpoint];
      }
      fas_points[i].points = point;
      prev_endpoint = ixa[i];
      end_point = ixa[i + 1];

   }

   fas_points_list.num_point_lists = *npl;
   fas_points_list.point_lists = fas_points;

/**************************************************************************
  C Syntax
     void
     pfill_area_set(point_list_list)
     Ppoint_list_list              *point_list_list;list of point lists
**************************************************************************/

   pfill_area_set (&fas_points_list);

   for (i = 0; i < *npl; i++)
      free (fas_points_list.point_lists[i].points);

   free (fas_points_list.point_lists);
}
