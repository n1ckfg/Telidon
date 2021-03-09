#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     FILL AREA SET 3 - create  structure  element  specifying  3D
     fill area set primitive

  FORTRAN Syntax
     SUBROUTINE pfas3 ( NPL, IXA, PXA, PYA, PZA )
     INTEGER     NPL               number of point lists
     INTEGER     IXA(NPL)          array of end indices for the point lists
     REAL        PXA(*), PYA(*), PZA(*)coordinates of points (MC)
**************************************************************************/
#ifdef NO_PROTO
nfas3 (npl, ixa, pxa, pya, pza)
   integer      *npl,
             ixa[];
   real     pxa[],
             pya[],
             pza[];
#else
nfas3 (integer *npl, integer ixa[], real pxa[], real pya[], real pza[])
#endif
{
   int       i = 0,
             nump = 0;
   int       prev_endpoint = 0,
             end_point = 0;

   Ppoint_list_list3 fas3_points_list;
   Ppoint_list3 *fas3_points;
   Ppoint3  *point;


/** Allocate room to hold the npl (number) of sets **/

   fas3_points = (Ppoint_list3 *) calloc (*npl, sizeof (Ppoint_list3));


   for (i = 0; i < *npl; i++)
   {

      end_point = ixa[i];
   /** Allocate room to hold the points **/

      point = (Ppoint3 *) calloc (end_point - prev_endpoint, sizeof (Ppoint3));
      fas3_points[i].num_points = end_point - prev_endpoint;

      for (nump = 0; nump < end_point - prev_endpoint; nump++)
      {
	 point[nump].x = pxa[nump + prev_endpoint];
	 point[nump].y = pya[nump + prev_endpoint];
	 point[nump].z = pza[nump + prev_endpoint];
      }
      fas3_points[i].points = point;
      prev_endpoint = ixa[i];
   }

   fas3_points_list.num_point_lists = *npl;
   fas3_points_list.point_lists = fas3_points;

/**************************************************************************
  C Syntax
     void
     pfill_area_set3(point_list_list)
     Ppoint_list_list3             *point_list_list;list of point lists
**************************************************************************/

   pfill_area_set3 (&fas3_points_list);

   for (i = 0; i < *npl; i++)
      free (fas3_points_list.point_lists[i].points);

   free (fas3_points_list.point_lists);
}
