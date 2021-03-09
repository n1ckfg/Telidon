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
#include <phigs/private/sofas3P.h>

/*******************************************************************************
 * priv_vdata
 *
 * DESCR:	Get set of fill area set vertex data helper function
 * NOTES:	Shall be called after all vertex lists has been processed
 * RETURNS:	N/A
 */

static void priv_vdata(
   Psofas3 *sofas3
   )
{
   Pint *data = (Pint *) sofas3->vlist;

   sofas3->vdata.num_vertices = *data;
   switch (sofas3->vflag) {
      case PVERT_COORD:
         sofas3->vdata.vertex_data.points = (Ppoint3 *) &data[1];
         break;

      case PVERT_COORD_COLOUR:
         sofas3->vdata.vertex_data.ptcolrs = (Pptco3 *) &data[1];
         break;

      case PVERT_COORD_NORMAL:
         sofas3->vdata.vertex_data.ptnorms = (Pptnorm3 *) &data[1];
         break;

      case PVERT_COORD_COLOUR_NORMAL:
         sofas3->vdata.vertex_data.ptconorms = (Pptconorm3 *) &data[1];
         break;

      default:
         break;
   }
}

/*******************************************************************************
 * sofas3_head
 *
 * DESCR:	Get set of fill area set header information 3D
 * RETURNS:	N/A
 */

void sofas3_head(
   Psofas3 *sofas3,
   void *pdata
   )
{
   Pint i, j;
   Pint num_lists;
   Pint_list vlist;
   Pedge_data_list elist;
   Pedge_data_list_list *estart;
   char *tp;
   Pint *data = (Pint *) pdata;

   sofas3->fflag = data[0];
   sofas3->eflag = data[1];
   sofas3->vflag = data[2];
   sofas3->colr_type = data[3];
   sofas3->num_sets = data[4];
   tp = (char *) &data[5];

   switch (sofas3->fflag) {
      case PFACET_COLOUR:
         sofas3->fdata.colrs = (Pcoval *) tp;
         tp += sizeof(Pcoval) * sofas3->num_sets;
         break;

      case PFACET_NORMAL:
         sofas3->fdata.norms = (Pvec3 *) tp;
         tp += sizeof(Pvec3) * sofas3->num_sets;
         break;

      case PFACET_COLOUR_NORMAL:
         sofas3->fdata.conorms = (Pconorm3 *) tp;
         tp += sizeof(Pconorm3) * sofas3->num_sets;
         break;

      default:
         break;
   }

   if (sofas3->eflag == PEDGE_VISIBILITY) {
      sofas3->edata = (Pedge_data_list_list *) tp;
      estart = sofas3->edata;

      /* Move forward and setup edge lists */
      for (i = 0; i < sofas3->num_sets; i++) {
         num_lists = sofas3_num_elists(sofas3);
         for (j = 0; j < num_lists; j++) {
            sofas3_next_elist(&elist, sofas3);
         }
      }
      tp = (char *) sofas3->edata;

      /* Restore pointer to first edge list */
      sofas3->edata = estart;
   }

   sofas3->vlist = (Pint_list_list *) tp;

   /* Move forward and setup vertext lists */
   for (i = 0; i < sofas3->num_sets; i++) {
      num_lists = sofas3_num_vlists(sofas3);
      for (j = 0; j < num_lists; j++) {
         sofas3_next_vlist(&vlist, sofas3);
      }
   }

   /* Setup pointers to vertex data */
   priv_vdata(sofas3);

   /* Restore pointer to first vertex list */
   sofas3->vlist = (Pint_list_list *) tp;
}

/*******************************************************************************
 * sofas3_num_vlists
 *
 * DESCR:	Get set of fill area set number of vertex lists
 * RETURNS:	Total number of vertext lists
 */

int sofas3_num_vlists(
   Psofas3 *sofas3
   )
{
   Pint *data = (Pint *) sofas3->vlist;
   Pint num_lists = data[0];
   sofas3->vlist = (Pint_list_list *) &data[1];

   return num_lists;
}

/*******************************************************************************
 * sofas3_get_vlist
 *
 * DESCR:       Get set of fill area set vertex list
 * RETURNS:     N/A
 */

void sofas3_get_vlist(
   Pint_list *vlist,
   Psofas3 *sofas3
   )
{
   Pint *data = (Pint *) sofas3->vlist;

   vlist->num_ints = data[0];
   data = &data[1];
   vlist->ints = data;
}

/*******************************************************************************
 * sofas3_next_vlist
 *
 * DESCR:	Get set of fill area set next vertex list
 * RETURNS:	N/A
 */

void sofas3_next_vlist(
   Pint_list *vlist,
   Psofas3 *sofas3
   )
{
   Pint *data = (Pint *) sofas3->vlist;

   vlist->num_ints = data[0];
   data = &data[1];
   vlist->ints = data;
   sofas3->vlist = (Pint_list_list *) &data[vlist->num_ints];
}

/*******************************************************************************
 * sofas3_num_elists
 *
 * DESCR:	Get set of fill area set number of edge lists
 * RETURNS:	Total number of edge lists
 */

int sofas3_num_elists(
   Psofas3 *sofas3
   )
{
   Pint *data = (Pint *) sofas3->edata;
   Pint num_lists = data[0];
   sofas3->edata = (Pedge_data_list_list *) &data[1];

   return num_lists;
}

/*******************************************************************************
 * sofas3_next_elist
 *
 * DESCR:	Get set of fill area set next edge list
 * RETURNS:	N/A
 */

void sofas3_next_elist(
   Pedge_data_list *elist,
   Psofas3 *sofas3
   )
{
   Pint *data = (Pint *) sofas3->edata;
   Pedge_flag *edata;

   elist->num_edges = data[0];
   data = &data[1];
   edata = (Pedge_flag *) data;
   elist->edgedata.edges = edata;
   sofas3->edata = (Pedge_data_list_list *) &edata[elist->num_edges];
}

/*******************************************************************************
 * sofas3_normal3
 *
 * DESCR:	Get normal
 * RETURNS:	N/A
 */

void sofas3_normal3(
   Pvec3 *norm,
   Psofas3 *sofas3,
   Pint_list *vlist
   )
{
   Pint vert1, vert2, vert3;
   Pvec3 a, b, c;
   Pvec3 v1, v2;

   vert1 = vlist->ints[0];
   vert2 = vlist->ints[1];
   vert3 = vlist->ints[2];

   switch(sofas3->vflag) {
      case PVERT_COORD:
         a.delta_x = sofas3->vdata.vertex_data.points[vert1].x;
         a.delta_y = sofas3->vdata.vertex_data.points[vert1].y;
         a.delta_z = sofas3->vdata.vertex_data.points[vert1].z;
         b.delta_x = sofas3->vdata.vertex_data.points[vert2].x;
         b.delta_y = sofas3->vdata.vertex_data.points[vert2].y;
         b.delta_z = sofas3->vdata.vertex_data.points[vert2].z;
         c.delta_x = sofas3->vdata.vertex_data.points[vert3].x;
         c.delta_y = sofas3->vdata.vertex_data.points[vert3].y;
         c.delta_z = sofas3->vdata.vertex_data.points[vert3].z;
         break;

      case PVERT_COORD_COLOUR:
         a.delta_x = sofas3->vdata.vertex_data.ptcolrs[vert1].point.x;
         a.delta_y = sofas3->vdata.vertex_data.ptcolrs[vert1].point.y;
         a.delta_z = sofas3->vdata.vertex_data.ptcolrs[vert1].point.z;
         b.delta_x = sofas3->vdata.vertex_data.ptcolrs[vert2].point.x;
         b.delta_y = sofas3->vdata.vertex_data.ptcolrs[vert2].point.y;
         b.delta_z = sofas3->vdata.vertex_data.ptcolrs[vert2].point.z;
         c.delta_x = sofas3->vdata.vertex_data.ptcolrs[vert3].point.x;
         c.delta_y = sofas3->vdata.vertex_data.ptcolrs[vert3].point.y;
         c.delta_z = sofas3->vdata.vertex_data.ptcolrs[vert3].point.z;
         break;

      case PVERT_COORD_NORMAL:
         a.delta_x = sofas3->vdata.vertex_data.ptnorms[vert1].point.x;
         a.delta_y = sofas3->vdata.vertex_data.ptnorms[vert1].point.y;
         a.delta_z = sofas3->vdata.vertex_data.ptnorms[vert1].point.z;
         b.delta_x = sofas3->vdata.vertex_data.ptnorms[vert2].point.x;
         b.delta_y = sofas3->vdata.vertex_data.ptnorms[vert2].point.y;
         b.delta_z = sofas3->vdata.vertex_data.ptnorms[vert2].point.z;
         c.delta_x = sofas3->vdata.vertex_data.ptnorms[vert3].point.x;
         c.delta_y = sofas3->vdata.vertex_data.ptnorms[vert3].point.y;
         c.delta_z = sofas3->vdata.vertex_data.ptnorms[vert3].point.z;
         break;

      case PVERT_COORD_COLOUR_NORMAL:
         a.delta_x = sofas3->vdata.vertex_data.ptconorms[vert1].point.x;
         a.delta_y = sofas3->vdata.vertex_data.ptconorms[vert1].point.y;
         a.delta_z = sofas3->vdata.vertex_data.ptconorms[vert1].point.z;
         b.delta_x = sofas3->vdata.vertex_data.ptconorms[vert2].point.x;
         b.delta_y = sofas3->vdata.vertex_data.ptconorms[vert2].point.y;
         b.delta_z = sofas3->vdata.vertex_data.ptconorms[vert2].point.z;
         c.delta_x = sofas3->vdata.vertex_data.ptconorms[vert3].point.x;
         c.delta_y = sofas3->vdata.vertex_data.ptconorms[vert3].point.y;
         c.delta_z = sofas3->vdata.vertex_data.ptconorms[vert3].point.z;
         break;
   }

   phg_vector_sub(&v1, &b, &a);
   phg_vector_sub(&v2, &c, &a);
   phg_vector_cross_prod(norm, &v1, &v2);
}

/*******************************************************************************
 * sofas3_print
 *
 * DESCR:	Print set of fill area set 3D
 * RETURNS:	N/A
 */

void sofas3_print(
   Psofas3 *sofas3
   )
{
   Pint i, j, k;
   Pint num_lists;
   Pint_list vlist;
   Pedge_data_list elist;

   printf("Facet flags:\t%d\n", sofas3->fflag);
   printf("Edge flags:\t%d\n", sofas3->eflag);
   printf("Vertex flags:\t%d\n", sofas3->vflag);
   printf("Colour type:\t%d\n", sofas3->colr_type);
   printf("Num sets:\t%d\n", sofas3->num_sets);

   printf("\n");
   for (i = 0; i < sofas3->num_sets; i++) {
      printf("Set #%d\t", i);
      switch (sofas3->fflag) {
         case PFACET_COLOUR:
            printf("Colour: %g, %g, %g\n",
                   sofas3->fdata.colrs[i].direct.rgb.red,
                   sofas3->fdata.colrs[i].direct.rgb.green,
                   sofas3->fdata.colrs[i].direct.rgb.blue);
            break;

         case PFACET_NORMAL:
            printf("Normal: %g, %g, %g\n",
                   sofas3->fdata.norms[i].delta_x,
                   sofas3->fdata.norms[i].delta_y,
                   sofas3->fdata.norms[i].delta_z);
            break;

         case PFACET_COLOUR_NORMAL:
            printf("Colour: %g, %g, %g\n",
                   sofas3->fdata.conorms[i].colr.direct.rgb.red,
                   sofas3->fdata.conorms[i].colr.direct.rgb.green,
                   sofas3->fdata.conorms[i].colr.direct.rgb.blue);
            printf("Normal: %g, %g, %g\n",
                   sofas3->fdata.conorms[i].norm.delta_x,
                   sofas3->fdata.conorms[i].norm.delta_y,
                   sofas3->fdata.conorms[i].norm.delta_z);
            break;

         default:
            break;
      }
   }

   if (sofas3->eflag == PEDGE_VISIBILITY) {
      printf("\n");
      for (i = 0; i < sofas3->num_sets; i++) {
         num_lists = sofas3_num_elists(sofas3);
         printf("Set #%d, num lists: %d\n", i, num_lists);
         for (j = 0; j < num_lists; j++) {
            sofas3_next_elist(&elist, sofas3);
            printf("\tList #%d, num_edges: %d\t", j, elist.num_edges);
            for (k = 0; k < elist.num_edges; k++) {
               printf("%s ",
                      (elist.edgedata.edges[k] == PEDGE_ON) ? "ON" : "OFF");
            }
            printf("\n");
         }
      }
   }


   printf("\n");
   for (i = 0; i < sofas3->num_sets; i++) {
      num_lists = sofas3_num_vlists(sofas3);
      printf("Set #%d, num lists: %d\n", i, num_lists);
      for (j = 0; j < num_lists; j++) {
         sofas3_next_vlist(&vlist, sofas3);
         printf("\tList #%d, num_ints: %d\t", j, vlist.num_ints);
         for (k = 0; k < vlist.num_ints; k++) {
            printf("%d ", vlist.ints[k]);
         }
         printf("\n");
      }
   }

   priv_vdata(sofas3);
   printf("\nNum vertices: %d\n", sofas3->vdata.num_vertices);
   for (i = 0; i < sofas3->vdata.num_vertices; i++) {
       printf("#%d:\t%g %g %g\n", i,
              sofas3->vdata.vertex_data.points[i].x,
              sofas3->vdata.vertex_data.points[i].y,
              sofas3->vdata.vertex_data.points[i].z);
   }
}

/*******************************************************************************
 * sofas3_list
 *
 * DESCR:	List set of fill area set 3D
 * RETURNS:	N/A
 */

void sofas3_list(
   void *pdata
   )
{
   Psofas3 sofas3;

   sofas3_head(&sofas3, pdata);
   sofas3_print(&sofas3);
}

