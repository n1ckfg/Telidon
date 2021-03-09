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
 * priv_clear_area3_points
 *
 * DESCR:	Clear fill area with point data 3D helper function
 * RETURNS:	N/A
 */

static void priv_clear_area3_points(
   Pint num_vertices,
   Ppoint3 *points
   )
{
   Pint i;

   glBegin(GL_POLYGON);
   for (i = 0; i < num_vertices; i++) {
      glVertex3f(points[i].x,
                 points[i].y,
                 points[i].z);
   }
   glEnd();
}

/*******************************************************************************
 * priv_clear_area3_ptcolrs
 *
 * DESCR:	Clear fill area with point and colour data 3D helper function
 * RETURNS:	N/A
 */

static void priv_clear_area3_ptcolrs(
   Pint num_vertices,
   Pptco3 *ptcolrs
   )
{
   Pint i;

   glBegin(GL_POLYGON);
   for (i = 0; i < num_vertices; i++) {
      glVertex3f(ptcolrs[i].point.x,
                 ptcolrs[i].point.y,
                 ptcolrs[i].point.z);
   }
   glEnd();
}

/*******************************************************************************
 * priv_clear_area3_ptnorms
 *
 * DESCR:	Clear fill area with point and normal data 3D helper function
 * RETURNS:	N/A
 */

static void priv_clear_area3_ptnorms(
   Pint num_vertices,
   Pptnorm3 *ptnorms
   )
{
   Pint i;

   glBegin(GL_POLYGON);
   for (i = 0; i < num_vertices; i++) {
      glVertex3f(ptnorms[i].point.x,
                 ptnorms[i].point.y,
                 ptnorms[i].point.z);
   }
   glEnd();
}

/*******************************************************************************
 * priv_clear_area3_ptconorms
 *
 * DESCR:	Clear fill area with point, colour and normal data 3D
 *              helper function
 * RETURNS:	N/A
 */

static void priv_clear_area3_ptconorms(
   Pint num_vertices,
   Pptconorm3 *ptconorms
   )
{
   Pint i;

   glBegin(GL_POLYGON);
   for (i = 0; i < num_vertices; i++) {
      glVertex3f(ptconorms[i].point.x,
                 ptconorms[i].point.y,
                 ptconorms[i].point.z);
   }
   glEnd();
}

/*******************************************************************************
 * wsgl_clear_area_set3_data
 *
 * DESCR:	Clear fill area set with data 3D
 * RETURNS:	N/A
 */

void wsgl_clear_area_set3_data(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pint i;
   Pfasd3 fasd3;
   Pedge_data_list edata;
   Pfacet_vdata_list3 vdata;

   fasd3.edata = &edata;
   fasd3.vdata = &vdata;
   fasd3_head(&fasd3, pdata);

   glPolygonOffset(WS_CLEAR_AREA_OFFSET, wsgl_get_edge_width(ast));
   glEnable(GL_POLYGON_OFFSET_FILL);
   wsgl_setup_background(ws);

   switch (fasd3.vflag) {
      case PVERT_COORD:
         for (i = 0; i < fasd3.nfa; i++) {
            priv_clear_area3_points(fasd3.vdata->num_vertices,
                                    fasd3.vdata->vertex_data.points);

            /* Advance to next set of data */
            fasd3_next_vdata3(&fasd3);
            if (fasd3.eflag == PEDGE_VISIBILITY) {
               fasd3_next_edata(&fasd3);
            }
         }
         break;

      case PVERT_COORD_COLOUR:
         for (i = 0; i < fasd3.nfa; i++) {
            priv_clear_area3_ptcolrs(fasd3.vdata->num_vertices,
                                     fasd3.vdata->vertex_data.ptcolrs);

            /* Advance to next set of data */
            fasd3_next_vdata3(&fasd3);
            if (fasd3.eflag == PEDGE_VISIBILITY) {
               fasd3_next_edata(&fasd3);
            }
         }
         break;

      case PVERT_COORD_NORMAL:
         for (i = 0; i < fasd3.nfa; i++) {
            priv_clear_area3_ptnorms(fasd3.vdata->num_vertices,
                                     fasd3.vdata->vertex_data.ptnorms);

            /* Advance to next set of data */
            fasd3_next_vdata3(&fasd3);
            if (fasd3.eflag == PEDGE_VISIBILITY) {
               fasd3_next_edata(&fasd3);
            }
         }
         break;

      case PVERT_COORD_COLOUR_NORMAL:
         for (i = 0; i < fasd3.nfa; i++) {
            priv_clear_area3_ptconorms(fasd3.vdata->num_vertices,
                                       fasd3.vdata->vertex_data.ptconorms);

            /* Advance to next set of data */
            fasd3_next_vdata3(&fasd3);
            if (fasd3.eflag == PEDGE_VISIBILITY) {
               fasd3_next_edata(&fasd3);
            }
         }
         break;

      default:
         break;
   }

   glDisable(GL_POLYGON_OFFSET_FILL);
}

