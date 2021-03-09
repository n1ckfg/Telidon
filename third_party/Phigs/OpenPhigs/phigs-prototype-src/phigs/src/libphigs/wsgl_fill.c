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
 * priv_fill_area
 *
 * DESCR:	Draw fill area helper function
 * RETURNS:	N/A
 */

void priv_fill_area(
   Ppoint_list *point_list
   )
{
   int i;

   glBegin(GL_POLYGON);
   for (i = 0; i < point_list->num_points; i++) {
      glVertex2f(point_list->points[i].x,
                 point_list->points[i].y);
   }
   glEnd();
}

/*******************************************************************************
 * priv_normal3
 *
 * DESCR:	Calculate normal helper function
 * RETURNS:	N/A
 */

void priv_normal3(
   Pvec3 *norm,
   Ppoint_list3 *point_list
   )
{
   Pvec3 a, b, c;
   Pvec3 v1, v2;

   a.delta_x = point_list->points[0].x;
   a.delta_y = point_list->points[0].y;
   a.delta_z = point_list->points[0].z;

   b.delta_x = point_list->points[1].x;
   b.delta_y = point_list->points[1].y;
   b.delta_z = point_list->points[1].z;

   c.delta_x = point_list->points[2].x;
   c.delta_y = point_list->points[2].y;
   c.delta_z = point_list->points[2].z;

   phg_vector_sub(&v1, &b, &a);
   phg_vector_sub(&v2, &c, &a);
   phg_vector_cross_prod(norm, &v1, &v2);
}

/*******************************************************************************
 * priv_fill_area3
 *
 * DESCR:	Draw fill area 3D helper function
 * RETURNS:	N/A
 */

void priv_fill_area3(
   Ppoint_list3 *point_list
   )
{
   int i;

   glBegin(GL_POLYGON);
   for (i = 0; i < point_list->num_points; i++) {
      glVertex3f(point_list->points[i].x,
                 point_list->points[i].y,
                 point_list->points[i].z);
   }
   glEnd();
}

/*******************************************************************************
 * wsgl_fill_area
 *
 * DESCR:	Draw fill area
 * RETURNS:	N/A
 */

void wsgl_fill_area(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Ppoint_list point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint *) &data[1];

   wsgl_setup_int_attr(ws, ast);
   priv_fill_area(&point_list);
}

/*******************************************************************************
 * wsgl_fill_area3
 *
 * DESCR:	Draw fill area 3D
 * RETURNS:	N/A
 */

void wsgl_fill_area3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pvec3 norm;
   Ppoint_list3 point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint3 *) &data[1];

   glPolygonOffset(WS_FILL_AREA_OFFSET, wsgl_get_edge_width(ast));
   glEnable(GL_POLYGON_OFFSET_FILL);
   glEnable(GL_POLYGON_OFFSET_LINE);
   if (wsgl_setup_int_attr_plus(ws, ast)) {
      priv_normal3(&norm, &point_list);
      glNormal3f(norm.delta_x, norm.delta_y, norm.delta_z);
   }
   priv_fill_area3(&point_list);
   glDisable(GL_POLYGON_OFFSET_LINE);
   glDisable(GL_POLYGON_OFFSET_FILL);
}

/*******************************************************************************
 * wsgl_back_area3
 *
 * DESCR:	Draw backface area 3D
 * RETURNS:	N/A
 */

void wsgl_back_area3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pvec3 norm;
   Ppoint_list3 point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint3 *) &data[1];

   glPolygonOffset(WS_FILL_AREA_OFFSET, wsgl_get_edge_width(ast));
   glEnable(GL_POLYGON_OFFSET_FILL);
   glEnable(GL_POLYGON_OFFSET_LINE);
   if (wsgl_setup_back_int_attr_plus(ws, ast)) {
      priv_normal3(&norm, &point_list);
      glNormal3f(norm.delta_x, norm.delta_y, norm.delta_z);
   }
   priv_fill_area3(&point_list);
   glDisable(GL_POLYGON_OFFSET_LINE);
   glDisable(GL_POLYGON_OFFSET_FILL);
}

/*******************************************************************************
 * wsgl_fill_area_set
 *
 * DESCR:	Draw fill area set
 * RETURNS:	N/A
 */

void wsgl_fill_area_set(
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

   wsgl_setup_int_attr(ws, ast);

   for (i = 0; i < num_lists; i++) {
      point_list.num_points = *data;
      point_list.points = (Ppoint *) &data[1];
      priv_fill_area(&point_list);
      data = (Pint *) &point_list.points[point_list.num_points];
   }
}

/*******************************************************************************
 * wsgl_fill_area_set3
 *
 * DESCR:	Draw fill area set 3D
 * RETURNS:	N/A
 */

void wsgl_fill_area_set3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pvec3 norm;
   Pint i, num_lists;
   Ppoint_list3 point_list;
   Pint *data = (Pint *) pdata;

   num_lists = *data;
   data = &data[1];

   point_list.num_points = *data;
   point_list.points = (Ppoint3 *) &data[1];

   glPolygonOffset(WS_FILL_AREA_OFFSET, wsgl_get_edge_width(ast));
   glEnable(GL_POLYGON_OFFSET_FILL);
   glEnable(GL_POLYGON_OFFSET_LINE);
   if (wsgl_setup_int_attr_plus(ws, ast)) {
      priv_normal3(&norm, &point_list);
      glNormal3f(norm.delta_x, norm.delta_y, norm.delta_z);
   }

   for (i = 0; i < num_lists; i++) {
      point_list.num_points = *data;
      point_list.points = (Ppoint3 *) &data[1];
      priv_fill_area3(&point_list);
      data = (Pint *) &point_list.points[point_list.num_points];
   }

   glDisable(GL_POLYGON_OFFSET_LINE);
   glDisable(GL_POLYGON_OFFSET_FILL);
}

