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

/*******************************************************************************
 * priv_edge_area
 *
 * DESCR:	Draw fill area edge helper function
 * RETURNS:	N/A
 */

void priv_edge_area(
   Ppoint_list *point_list
   )
{
   int i;

   glBegin(GL_LINE_LOOP);
   for (i = 0; i < point_list->num_points; i++) {
      glVertex2f(point_list->points[i].x,
                 point_list->points[i].y);
   }
   glEnd();
}

/*******************************************************************************
 * priv_edge_area3
 *
 * DESCR:	Draw fill area edge 3D helper function
 * RETURNS:	N/A
 */

void priv_edge_area3(
   Ppoint_list3 *point_list
   )
{
   int i;

   glBegin(GL_LINE_LOOP);
   for (i = 0; i < point_list->num_points; i++) {
      glVertex3f(point_list->points[i].x,
                 point_list->points[i].y,
                 point_list->points[i].z);
   }
   glEnd();
}

/*******************************************************************************
 * wsgl_edge_area
 *
 * DESCR:	Draw fill area edge
 * RETURNS:	N/A
 */

void wsgl_edge_area(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Ppoint_list point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint *) &data[1];

   wsgl_setup_edge_attr(ast);
   priv_edge_area(&point_list);
}

/*******************************************************************************
 * wsgl_edge_area3
 *
 * DESCR:	Draw fill area edge 3D
 * RETURNS:	N/A
 */

void wsgl_edge_area3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Ppoint_list3 point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint3 *) &data[1];

   wsgl_setup_edge_attr(ast);
   priv_edge_area3(&point_list);
}

/*******************************************************************************
 * wsgl_edge_area_set
 *
 * DESCR:	Draw fill area set edge
 * RETURNS:	N/A
 */

void wsgl_edge_area_set(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pint i, num_lists;
   Ppoint_list point_list;
   Pint *data = (Pint *) pdata;

   num_lists = *data;
   data = &data[1];

   wsgl_setup_edge_attr(ast);

   for (i = 0; i < num_lists; i++) {
      point_list.num_points = *data;
      point_list.points = (Ppoint *) &data[1];
      priv_edge_area(&point_list);
      data = (Pint *) &point_list.points[point_list.num_points];
   }
}

/*******************************************************************************
 * wsgl_edge_area_set3
 *
 * DESCR:	Draw fill area set edge 3D
 * RETURNS:	N/A
 */

void wsgl_edge_area_set3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pint i, num_lists;
   Ppoint_list3 point_list;
   Pint *data = (Pint *) pdata;

   num_lists = *data;
   data = &data[1];

   wsgl_setup_edge_attr(ast);

   for (i = 0; i < num_lists; i++) {
      point_list.num_points = *data;
      point_list.points = (Ppoint3 *) &data[1];
      priv_edge_area3(&point_list);
      data = (Pint *) &point_list.points[point_list.num_points];
   }
}

