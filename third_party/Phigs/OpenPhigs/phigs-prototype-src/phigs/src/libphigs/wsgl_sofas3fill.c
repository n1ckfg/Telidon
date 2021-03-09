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
 * priv_fill_area3_points
 *
 * DESCR:	Draw fill area with point data 3D helper function
 * RETURNS:	N/A
 */

static void priv_fill_area3_points(
   Pint_list *vlist,
   Ppoint3 *points
   )
{
   Pint i, vert;

   glBegin(GL_POLYGON);
   for (i = 0; i < vlist->num_ints; i++) {
      vert = vlist->ints[i];
      glVertex3f(points[vert].x,
                 points[vert].y,
                 points[vert].z);
   }
   glEnd();
}

/*******************************************************************************
 * priv_fill_area3_ptcolrs
 *
 * DESCR:	Draw fill area with point and colour data 3D helper function
 * RETURNS:	N/A
 */

static void priv_fill_area3_ptcolrs(
   Ws *ws,
   Pint colr_type,
   Pint_list *vlist,
   Pptco3 *ptcolrs,
   Ws_attr_st *ast
   )
{
   Pint i, vert;

   glBegin(GL_POLYGON);
   for (i = 0; i < vlist->num_ints; i++) {
      vert = vlist->ints[i];
      wsgl_setup_int_colr(ws, colr_type, &ptcolrs[vert].colr, ast);
      glVertex3f(ptcolrs[vert].point.x,
                 ptcolrs[vert].point.y,
                 ptcolrs[vert].point.z);
   }
   glEnd();
}

/*******************************************************************************
 * priv_back_area3_ptcolrs
 *
 * DESCR:	Draw back area with point and colour data 3D helper function
 * RETURNS:	N/A
 */

static void priv_back_area3_ptcolrs(
   Ws *ws,
   Pint colr_type,
   Pint_list *vlist,
   Pptco3 *ptcolrs,
   Ws_attr_st *ast
   )
{
   Pint i, vert;

   glBegin(GL_POLYGON);
   for (i = 0; i < vlist->num_ints; i++) {
      vert = vlist->ints[i];
      wsgl_setup_back_int_colr(ws, colr_type, &ptcolrs[vert].colr, ast);
      glVertex3f(ptcolrs[vert].point.x,
                 ptcolrs[vert].point.y,
                 ptcolrs[vert].point.z);
   }
   glEnd();
}

/*******************************************************************************
 * priv_fill_area3_ptnorms
 *
 * DESCR:	Draw fill area with point and normal data 3D helper function
 * RETURNS:	N/A
 */

static void priv_fill_area3_ptnorms(
   Pint_list *vlist,
   Pptnorm3 *ptnorms
   )
{
   Pint i, vert;

   glBegin(GL_POLYGON);
   for (i = 0; i < vlist->num_ints; i++) {
      vert = vlist->ints[i];
      glNormal3f(ptnorms[vert].norm.delta_x,
                 ptnorms[vert].norm.delta_y,
                 ptnorms[vert].norm.delta_z);
      glVertex3f(ptnorms[vert].point.x,
                 ptnorms[vert].point.y,
                 ptnorms[vert].point.z);
   }
   glEnd();
}

/*******************************************************************************
 * priv_fill_area3_ptconorms
 *
 * DESCR:	Draw fill area with point, colour and normal data 3D
 *		helper function
 * RETURNS:	N/A
 */

static void priv_fill_area3_ptconorms(
   Ws *ws,
   Pint colr_type,
   Pint_list *vlist,
   Pptconorm3 *ptconorms,
   Ws_attr_st *ast
   )
{
   Pint i, vert;

   glBegin(GL_POLYGON);
   for (i = 0; i < vlist->num_ints; i++) {
      vert = vlist->ints[i];
      wsgl_setup_int_colr(ws, colr_type, &ptconorms[vert].colr, ast);
      glNormal3f(ptconorms[vert].norm.delta_x,
                 ptconorms[vert].norm.delta_y,
                 ptconorms[vert].norm.delta_z);
      glVertex3f(ptconorms[vert].point.x,
                 ptconorms[vert].point.y,
                 ptconorms[vert].point.z);
   }
   glEnd();
}

/*******************************************************************************
 * priv_back_area3_ptconorms
 *
 * DESCR:	Draw back area with point, colour and normal data 3D
 *		helper function
 * RETURNS:	N/A
 */

static void priv_back_area3_ptconorms(
   Ws *ws,
   Pint colr_type,
   Pint_list *vlist,
   Pptconorm3 *ptconorms,
   Ws_attr_st *ast
   )
{
   Pint i, vert;

   glBegin(GL_POLYGON);
   for (i = 0; i < vlist->num_ints; i++) {
      vert = vlist->ints[i];
      wsgl_setup_back_int_colr(ws, colr_type, &ptconorms[vert].colr, ast);
      glNormal3f(ptconorms[vert].norm.delta_x,
                 ptconorms[vert].norm.delta_y,
                 ptconorms[vert].norm.delta_z);
      glVertex3f(ptconorms[vert].point.x,
                 ptconorms[vert].point.y,
                 ptconorms[vert].point.z);
   }
   glEnd();
}

/*******************************************************************************
 * wsgl_set_of_fill_area_set3_data_front
 *
 * DESCR:	Draw set of fill area set with data 3D front faces
 * RETURNS:	N/A
 */

void wsgl_set_of_fill_area_set3_data_front(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pint i, j;
   Psofas3 sofas3;
   Pint num_lists;
   Pint_list vlist;
   Pcoval colr;
   Pvec3 norm;

   sofas3_head(&sofas3, pdata);

   glPolygonOffset(WS_FILL_AREA_OFFSET, wsgl_get_edge_width(ast));
   glEnable(GL_POLYGON_OFFSET_FILL);
   glEnable(GL_POLYGON_OFFSET_LINE);
   wsgl_setup_int_attr_nocol(ws, ast);

   switch (sofas3.vflag) {
      case PVERT_COORD:
         if (sofas3.fflag == PFACET_COLOUR_NORMAL) {
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               wsgl_setup_int_colr(ws,
                                   sofas3.colr_type,
                                   &sofas3.fdata.conorms[i].colr,
                                   ast);
               glNormal3f(sofas3.fdata.conorms[i].norm.delta_x,
                          sofas3.fdata.conorms[i].norm.delta_y,
                          sofas3.fdata.conorms[i].norm.delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_points(&vlist,
                                         sofas3.vdata.vertex_data.points);
               }
            }
         }
         else if (sofas3.fflag == PFACET_NORMAL) {
            wsgl_colr_from_gcolr(&colr, wsgl_get_int_colr(ast));
            wsgl_setup_int_colr(ws, sofas3.colr_type, &colr, ast);
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               glNormal3f(sofas3.fdata.norms[i].delta_x,
                          sofas3.fdata.norms[i].delta_y,
                          sofas3.fdata.norms[i].delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_points(&vlist,
                                         sofas3.vdata.vertex_data.points);
               }
            }
         }
         else if (sofas3.fflag == PFACET_COLOUR) {
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               wsgl_setup_int_colr(ws,
                                   sofas3.colr_type,
                                   &sofas3.fdata.colrs[i],
                                   ast);
               sofas3_get_vlist(&vlist, &sofas3);
               sofas3_normal3(&norm, &sofas3, &vlist);
               glNormal3f(norm.delta_x, norm.delta_y, norm.delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_points(&vlist,
                                         sofas3.vdata.vertex_data.points);
               }
            }
         }
         else {
            wsgl_colr_from_gcolr(&colr, wsgl_get_int_colr(ast));
            wsgl_setup_int_colr(ws, sofas3.colr_type, &colr, ast);
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               sofas3_get_vlist(&vlist, &sofas3);
               sofas3_normal3(&norm, &sofas3, &vlist);
               glNormal3f(norm.delta_x, norm.delta_y, norm.delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_points(&vlist,
                                         sofas3.vdata.vertex_data.points);
               }
            }
         }
         break;

      case PVERT_COORD_COLOUR:
         if (sofas3.fflag == PFACET_NORMAL) {
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               glNormal3f(sofas3.fdata.norms[i].delta_x,
                          sofas3.fdata.norms[i].delta_y,
                          sofas3.fdata.norms[i].delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_ptcolrs(ws,
                                          sofas3.colr_type,
                                          &vlist,
                                          sofas3.vdata.vertex_data.ptcolrs,
                                          ast);
               }
            }
         }
         else {
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               sofas3_get_vlist(&vlist, &sofas3);
               sofas3_normal3(&norm, &sofas3, &vlist);
               glNormal3f(norm.delta_x, norm.delta_y, norm.delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_ptcolrs(ws,
                                          sofas3.colr_type,
                                          &vlist,
                                          sofas3.vdata.vertex_data.ptcolrs,
                                          ast);
               }
            }
         }
         break;

      case PVERT_COORD_NORMAL:
         if (sofas3.fflag == PFACET_COLOUR) {
            for (i = 0; i < sofas3.num_sets; i++) {
               wsgl_setup_int_colr(ws,
                                   sofas3.colr_type,
                                   &sofas3.fdata.colrs[i],
                                   ast);
               num_lists = sofas3_num_vlists(&sofas3);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_ptnorms(&vlist,
                                          sofas3.vdata.vertex_data.ptnorms);
               }
            }
         }
         else {
            wsgl_colr_from_gcolr(&colr, wsgl_get_int_colr(ast));
            wsgl_setup_int_colr(ws, sofas3.colr_type, &colr, ast);
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_ptnorms(&vlist,
                                          sofas3.vdata.vertex_data.ptnorms);
               }
            }
         }
         break;

      case PVERT_COORD_COLOUR_NORMAL:
         for (i = 0; i < sofas3.num_sets; i++) {
            num_lists = sofas3_num_vlists(&sofas3);
            for (j = 0; j < num_lists; j++) {
               sofas3_next_vlist(&vlist, &sofas3);
               priv_fill_area3_ptconorms(ws,
                                         sofas3.colr_type,
                                         &vlist,
                                         sofas3.vdata.vertex_data.ptconorms,
                                         ast);
            }
         }
         break;

      default:
         break;
   }

   glDisable(GL_POLYGON_OFFSET_LINE);
   glDisable(GL_POLYGON_OFFSET_FILL);
}

/*******************************************************************************
 * wsgl_set_of_fill_area_set3_data_back
 *
 * DESCR:	Draw set of fill area set with data 3D back faces
 * RETURNS:	N/A
 */

void wsgl_set_of_fill_area_set3_data_back(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pint i, j;
   Psofas3 sofas3;
   Pint num_lists;
   Pint_list vlist;
   Pcoval colr;
   Pvec3 norm;

   sofas3_head(&sofas3, pdata);

   glPolygonOffset(WS_FILL_AREA_OFFSET, wsgl_get_edge_width(ast));
   glEnable(GL_POLYGON_OFFSET_FILL);
   glEnable(GL_POLYGON_OFFSET_LINE);
   wsgl_setup_back_int_attr_nocol(ws, ast);

   switch (sofas3.vflag) {
      case PVERT_COORD:
         if (sofas3.fflag == PFACET_COLOUR_NORMAL) {
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               wsgl_setup_back_int_colr(ws,
                                        sofas3.colr_type,
                                        &sofas3.fdata.conorms[i].colr,
                                        ast);
               glNormal3f(sofas3.fdata.conorms[i].norm.delta_x,
                          sofas3.fdata.conorms[i].norm.delta_y,
                          sofas3.fdata.conorms[i].norm.delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_points(&vlist,
                                         sofas3.vdata.vertex_data.points);
               }
            }
         }
         else if (sofas3.fflag == PFACET_NORMAL) {
            wsgl_colr_from_gcolr(&colr, wsgl_get_back_int_colr(ast));
            wsgl_setup_back_int_colr(ws, sofas3.colr_type, &colr, ast);
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               glNormal3f(sofas3.fdata.norms[i].delta_x,
                          sofas3.fdata.norms[i].delta_y,
                          sofas3.fdata.norms[i].delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_points(&vlist,
                                         sofas3.vdata.vertex_data.points);
               }
            }
         }
         else if (sofas3.fflag == PFACET_COLOUR) {
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               wsgl_setup_back_int_colr(ws,
                                        sofas3.colr_type,
                                        &sofas3.fdata.colrs[i],
                                        ast);
               sofas3_get_vlist(&vlist, &sofas3);
               sofas3_normal3(&norm, &sofas3, &vlist);
               glNormal3f(norm.delta_x, norm.delta_y, norm.delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_points(&vlist,
                                         sofas3.vdata.vertex_data.points);
               }
            }
         }
         else {
            wsgl_colr_from_gcolr(&colr, wsgl_get_back_int_colr(ast));
            wsgl_setup_back_int_colr(ws, sofas3.colr_type, &colr, ast);
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               sofas3_get_vlist(&vlist, &sofas3);
               sofas3_normal3(&norm, &sofas3, &vlist);
               glNormal3f(norm.delta_x, norm.delta_y, norm.delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_points(&vlist,
                                         sofas3.vdata.vertex_data.points);
               }
            }
         }
         break;

      case PVERT_COORD_COLOUR:
         if (sofas3.fflag == PFACET_NORMAL) {
            for (i = 0; i < sofas3.num_sets; i++) {
               glNormal3f(sofas3.fdata.norms[i].delta_x,
                          sofas3.fdata.norms[i].delta_y,
                          sofas3.fdata.norms[i].delta_z);
               num_lists = sofas3_num_vlists(&sofas3);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_back_area3_ptcolrs(ws,
                                          sofas3.colr_type,
                                          &vlist,
                                          sofas3.vdata.vertex_data.ptcolrs,
                                          ast);
               }
            }
         }
         else {
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               sofas3_get_vlist(&vlist, &sofas3);
               sofas3_normal3(&norm, &sofas3, &vlist);
               glNormal3f(norm.delta_x, norm.delta_y, norm.delta_z);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_back_area3_ptcolrs(ws,
                                          sofas3.colr_type,
                                          &vlist,
                                          sofas3.vdata.vertex_data.ptcolrs,
                                          ast);
               }
            }
         }
         break;

      case PVERT_COORD_NORMAL:
         if (sofas3.fflag == PFACET_COLOUR) {
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               wsgl_setup_back_int_colr(ws,
                                        sofas3.colr_type,
                                        &sofas3.fdata.colrs[i],
                                        ast);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_ptnorms(&vlist,
                                          sofas3.vdata.vertex_data.ptnorms);
               }
            }
         }
         else {
            wsgl_colr_from_gcolr(&colr, wsgl_get_back_int_colr(ast));
            wsgl_setup_back_int_colr(ws, sofas3.colr_type, &colr, ast);
            for (i = 0; i < sofas3.num_sets; i++) {
               num_lists = sofas3_num_vlists(&sofas3);
               for (j = 0; j < num_lists; j++) {
                  sofas3_next_vlist(&vlist, &sofas3);
                  priv_fill_area3_ptnorms(&vlist,
                                          sofas3.vdata.vertex_data.ptnorms);
               }
            }
         }
         break;

      case PVERT_COORD_COLOUR_NORMAL:
         for (i = 0; i < sofas3.num_sets; i++) {
            num_lists = sofas3_num_vlists(&sofas3);
            for (j = 0; j < num_lists; j++) {
               sofas3_next_vlist(&vlist, &sofas3);
               priv_back_area3_ptconorms(ws,
                                         sofas3.colr_type,
                                         &vlist,
                                         sofas3.vdata.vertex_data.ptconorms,
                                         ast);
            }
         }
         break;

      default:
         break;
   }

   glDisable(GL_POLYGON_OFFSET_LINE);
   glDisable(GL_POLYGON_OFFSET_FILL);
}

