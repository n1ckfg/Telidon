/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
*
*   This file is part of Open PHIGS
*   Copyright (C) 2014 Surplus Users Ham Society
*
*   Open PHIGS is free software: you can redistribute it and/or modify
*   it under the terms of the GNU Lesser General Public License as published by
*   the Free Software Foundation, either version 2.1 of the License, or
*   (at your option) any later version.
*
*   Open PHIGS is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public License
*   along with Open PHIGS. If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/gl.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/ws.h>
#include <phigs/private/wsglP.h>
#include <phigs/private/fasd3P.h>

/*******************************************************************************
 * fasd3_head
 *
 * DESCR:	Get facet head information
 * RETURNS:	N/A
 */

void fasd3_head(
   Pfasd3 *fasd3,
   void *pdata
   )
{
   Pint i, num_edges;
   char *tp;
   Pint *data = (Pint *) pdata;

   fasd3->fflag = data[0];
   fasd3->eflag = data[1];
   fasd3->vflag = data[2];
   fasd3->colr_type = data[3];
   tp = (char *) &data[4];

   switch (fasd3->fflag) {
      case PFACET_COLOUR:
         memcpy(&fasd3->fdata.colr, tp, sizeof(Pcoval));
         tp += sizeof(Pcoval);
         break;

      case PFACET_NORMAL:
         memcpy(&fasd3->fdata.norm, tp, sizeof(Pvec3));
         tp += sizeof(Pvec3);
         break;

      case PFACET_COLOUR_NORMAL:
         memcpy(&fasd3->fdata.conorm, tp, sizeof(Pconorm3));
         tp += sizeof(Pconorm3);
         break;

      default:
         break;
   }

   data = (Pint *) tp;
   fasd3->nfa = data[0];
   tp = (char *) &data[1];

   if (fasd3->eflag == PEDGE_VISIBILITY) {
      data = (Pint *) tp;
      fasd3->edata->num_edges = data[0];
      fasd3->edata->edgedata.edges = (Pedge_flag *) &data[1];

      for (i = 0; i < fasd3->nfa; i++) {
         data = (Pint *) tp;
         num_edges = data[0];
         tp += sizeof(Pedge_flag) * num_edges + sizeof(Pint);
      }
   }

   data = (Pint *) tp;
   fasd3->vdata->num_vertices = data[0];
   switch (fasd3->vflag) {
      case PVERT_COORD:
         fasd3->vdata->vertex_data.points = (Ppoint3 *) &data[1];
         break;

      case PVERT_COORD_COLOUR:
         fasd3->vdata->vertex_data.ptcolrs = (Pptco3 *) &data[1];
         break;

      case PVERT_COORD_NORMAL:
         fasd3->vdata->vertex_data.ptnorms = (Pptnorm3 *) &data[1];
         break;

      case PVERT_COORD_COLOUR_NORMAL:
         fasd3->vdata->vertex_data.ptconorms = (Pptconorm3 *) &data[1];
         break;

      default:
         break;
   }
}

/*******************************************************************************
 * fasd3_next_edata
 *
 * DESCR:	Get facet edge data
 * NOTE:        Remember to set up Pfasd3->edata to point to a valid
 *              Pedge_data_list structure
 * RETURNS:	N/A
 */

void fasd3_next_edata(
   Pfasd3 *fasd3
   )
{
   Pint *data;
   char *tp;
   Pint num_edges;

   num_edges = fasd3->edata->num_edges;
   tp = (char *) fasd3->edata->edgedata.edges;
   tp += sizeof(Pedge_flag) * num_edges;
   data = (Pint *) tp;
   fasd3->edata->num_edges = data[0];
   fasd3->edata->edgedata.edges = (Pedge_flag *) &data[1];
}

/*******************************************************************************
 * fasd3_next_vdata3
 *
 * DESCR:	Get facet vertex data
 * NOTE:        Remember to set up Pfasd3->vdata to point to a valid
 *              Pfacet_vdata_list3 structure
 * RETURNS:	N/A
 */

void fasd3_next_vdata3(
   Pfasd3 *fasd3
   )
{
   Pint *data;
   char *tp;
   Pint num_vertices = fasd3->vdata->num_vertices;

   switch (fasd3->vflag) {
      case PVERT_COORD:
         tp = (char *) fasd3->vdata->vertex_data.points;
         tp += sizeof(Ppoint3) * num_vertices;
         data = (Pint *) tp;
         fasd3->vdata->num_vertices = data[0];
         fasd3->vdata->vertex_data.points = (Ppoint3 *) &data[1];
         break;

      case PVERT_COORD_COLOUR:
         tp = (char *) fasd3->vdata->vertex_data.ptcolrs;
         tp += sizeof(Pptco3) * num_vertices;
         data = (Pint *) tp;
         fasd3->vdata->num_vertices = data[0];
         fasd3->vdata->vertex_data.ptcolrs = (Pptco3 *) &data[1];
         break;

      case PVERT_COORD_NORMAL:
         tp = (char *) fasd3->vdata->vertex_data.ptnorms;
         tp += sizeof(Pptnorm3);
         data = (Pint *) tp;
         fasd3->vdata->num_vertices = data[0];
         fasd3->vdata->vertex_data.ptnorms = (Pptnorm3 *) &data[1];
         break;

      case PVERT_COORD_COLOUR_NORMAL:
         tp = (char *) fasd3->vdata->vertex_data.ptconorms;
         tp += sizeof(Pptconorm3) * num_vertices;
         data = (Pint *) tp;
         fasd3->vdata->num_vertices = data[0];
         fasd3->vdata->vertex_data.ptconorms = (Pptconorm3 *) &data[1];
         break;

      default:
         break;
   }
}

/*******************************************************************************
 * fasd3_normal3
 *
 * DESCR:       Get normal
 * RETURNS:     N/A
 */

void fasd3_normal3(
   Pvec3 *norm,
   Pfasd3 *fasd3
   )
{
   Pvec3 a, b, c;
   Pvec3 v1, v2;

   switch(fasd3->vflag) {
      case PVERT_COORD:
         a.delta_x = fasd3->vdata->vertex_data.points[0].x;
         a.delta_y = fasd3->vdata->vertex_data.points[0].y;
         a.delta_z = fasd3->vdata->vertex_data.points[0].z;
         b.delta_x = fasd3->vdata->vertex_data.points[1].x;
         b.delta_y = fasd3->vdata->vertex_data.points[1].y;
         b.delta_z = fasd3->vdata->vertex_data.points[1].z;
         c.delta_x = fasd3->vdata->vertex_data.points[2].x;
         c.delta_y = fasd3->vdata->vertex_data.points[2].y;
         c.delta_z = fasd3->vdata->vertex_data.points[2].z;
         break;

      case PVERT_COORD_COLOUR:
         a.delta_x = fasd3->vdata->vertex_data.ptcolrs[0].point.x;
         a.delta_y = fasd3->vdata->vertex_data.ptcolrs[0].point.y;
         a.delta_z = fasd3->vdata->vertex_data.ptcolrs[0].point.z;
         b.delta_x = fasd3->vdata->vertex_data.ptcolrs[1].point.x;
         b.delta_y = fasd3->vdata->vertex_data.ptcolrs[1].point.y;
         b.delta_z = fasd3->vdata->vertex_data.ptcolrs[1].point.z;
         c.delta_x = fasd3->vdata->vertex_data.ptcolrs[2].point.x;
         c.delta_y = fasd3->vdata->vertex_data.ptcolrs[2].point.y;
         c.delta_z = fasd3->vdata->vertex_data.ptcolrs[2].point.z;
         break;

      case PVERT_COORD_NORMAL:
         a.delta_x = fasd3->vdata->vertex_data.ptnorms[0].point.x;
         a.delta_y = fasd3->vdata->vertex_data.ptnorms[0].point.y;
         a.delta_z = fasd3->vdata->vertex_data.ptnorms[0].point.z;
         b.delta_x = fasd3->vdata->vertex_data.ptnorms[1].point.x;
         b.delta_y = fasd3->vdata->vertex_data.ptnorms[1].point.y;
         b.delta_z = fasd3->vdata->vertex_data.ptnorms[1].point.z;
         c.delta_x = fasd3->vdata->vertex_data.ptnorms[2].point.x;
         c.delta_y = fasd3->vdata->vertex_data.ptnorms[2].point.y;
         c.delta_z = fasd3->vdata->vertex_data.ptnorms[2].point.z;
         break;

      case PVERT_COORD_COLOUR_NORMAL:
         a.delta_x = fasd3->vdata->vertex_data.ptconorms[0].point.x;
         a.delta_y = fasd3->vdata->vertex_data.ptconorms[0].point.y;
         a.delta_z = fasd3->vdata->vertex_data.ptconorms[0].point.z;
         b.delta_x = fasd3->vdata->vertex_data.ptconorms[1].point.x;
         b.delta_y = fasd3->vdata->vertex_data.ptconorms[1].point.y;
         b.delta_z = fasd3->vdata->vertex_data.ptconorms[1].point.z;
         c.delta_x = fasd3->vdata->vertex_data.ptconorms[2].point.x;
         c.delta_y = fasd3->vdata->vertex_data.ptconorms[2].point.y;
         c.delta_z = fasd3->vdata->vertex_data.ptconorms[2].point.z;
         break;
   }

   phg_vector_sub(&v1, &b, &a);
   phg_vector_sub(&v2, &c, &a);
   phg_vector_cross_prod(norm, &v1, &v2);
}
