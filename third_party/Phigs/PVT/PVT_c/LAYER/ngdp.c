#include <phigs.h>
#include "f2c.h"
#include "struct.h"

/**************************************************************************
NAME
     GENERALIZED DRAWING PRIMITIVE - create 2D GDP elements  such
     as circle, ellipse, or rectangular grid

  FORTRAN Syntax
     SUBROUTINE pgdp ( N, PXA, PYA, PRIMID, LDR, DATREC )
     INTEGER     N                 number of points (>= 0)
     REAL        PXA(*), PYA(*)    coordinates of points (MC)
     INTEGER     PRIMID            GDP identifier
     INTEGER     LDR               dimension of data record array
     CHARACTER*80                  DATREC(LDR)data record
**************************************************************************/
#ifdef NO_PROTO
ngdp (n, pxa, pya, gdp_id, ldr, datrec, lendat)
   integer      *n,
            *gdp_id,
            *ldr,
             lendat;
   real     pxa[],
             pya[];
   cdatrec  *datrec;
#else
ngdp (integer *n, real pxa[], real pya[], integer *gdp_id,
      integer *ldr, cdatrec * datrec, integer lendat)
#endif
{
   int       i;
   Pgdp_data gdp_data;
   Ppoint   *line;
   Ppoint_list lines;
/*** Put points into structure  ***/

   line = (Ppoint *) calloc (*n, sizeof (Ppoint));

   for (i = 0; i < *n; i++)
   {
      line[i].x = pxa[i];
      line[i].y = pya[i];
   }

   lines.num_points = *n;
   lines.points = line;

   switch (*gdp_id)
   {

   /**********    There are no registered gdp's at this time, add the
                  structure conversions here as they are defined        *********/
   default:
   /*** Uknown, send in Pdata stucture  ****/
      gdp_data.unsupp.size = sizeof (cdatrec);
      gdp_data.unsupp.data = (void *) datrec;


   }

/**************************************************************************
  C Syntax
     void
     pgdp ( point_list, gdp_id, gdp_data )
     Ppoint_list *point_list;      array of points
     Pint        gdp_id;           gdp function identifier
     Pgdp_data   *gdp_data;        data record pointer
**************************************************************************/

   pgdp (&lines, (Pint) *gdp_id, &gdp_data);
}
