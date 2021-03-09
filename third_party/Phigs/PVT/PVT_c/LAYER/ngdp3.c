#include <phigs.h>
#include "f2c.h"
#include "struct.h"

/**************************************************************************
NAME
     GENERALIZED DRAWING PRIMITIVE 3 -  create  3D  GDP  elements
     such as circle 3, ellipse 3, or rectangular grid 3

  FORTRAN Syntax
     SUBROUTINE pgdp3 ( N, PXA, PYA, PZA, PRIMID, LDR, DATREC )
     INTEGER     N                 number of points (>= 0)
     REAL        PXA(*), PYA(*), PZA(*)coordinates of points (MC)
     INTEGER     PRIMID            GDP 3 identifier
     INTEGER     LDR               dimension of data record array
     CHARACTER*80                  DATREC(LDR)data record
**************************************************************************/


#ifdef NO_PROTO
ngdp3 (n, pxa, pya, pza, gdp3_id, ldr, datrec, lendat)
   integer      *n,
            *gdp3_id,
            *ldr,
             lendat;
   real     pxa[],
             pya[],
             pza[];
   cdatrec  *datrec;
#else
ngdp3 (integer *n, real pxa[], real pya[], real pza[], integer *gdp3_id,
       integer *ldr, char datrec[], integer lendat)
#endif
{
   int       i;
   Pgdp_data3 gdp_data;
   Ppoint3  *line;
   Ppoint_list3 lines;
/*** Put points into structure  ***/

   line = (Ppoint3 *) calloc (*n, sizeof (Ppoint3));

   for (i = 0; i < *n; i++)
   {
      line[i].x = pxa[i];
      line[i].y = pya[i];
      line[i].z = pza[i];
   }
   lines.num_points = *n;
   lines.points = line;

   switch (*gdp3_id)
   {

   /**********    There are no registered gdp's at this time, add the
                  structure conversions here as they are defined        *********/
   default:
   /*** Unknown, send in Pdata stucture  ****/
      gdp_data.unsupp.size = sizeof (cdatrec);
      gdp_data.unsupp.data = (void *) datrec;


   }

/**************************************************************************
  C Syntax
     void
     pgdp3 ( point_list, gdp3_id, gdp_data )
     Ppoint_list3                  *point_list;array of points
     Pint        gdp3_id;          gdp function identifier
     Pgdp_data3      *gdp_data;    gdp data record
**************************************************************************/

   pgdp3 (&lines, (Pint) *gdp3_id, &gdp_data);
}
