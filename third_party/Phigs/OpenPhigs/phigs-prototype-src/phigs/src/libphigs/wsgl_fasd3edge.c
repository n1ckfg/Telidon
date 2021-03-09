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
 * priv_edges_points
 *
 * DESCR:	Draw edges for fill area 3D with point data
 * RETURNS:	N/A
 */

static void priv_edges_points(
   Pint eflag,
   Pedge_data_list *edata,
   Pint num_vertices,
   Ppoint3 *points
   )
{
   Pint i;

   if (eflag == PEDGE_VISIBILITY) {
      glBegin(GL_LINES);
      for (i = 0; i < edata->num_edges - 1; i++) {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(points[i].x,
                       points[i].y,
                       points[i].z);
            glVertex3f(points[i + 1].x,
                       points[i + 1].y,
                       points[i + 1].z);
         }
      }
      if (edata->num_edges < num_vertices) {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(points[i].x,
                       points[i].y,
                       points[i].z);
            glVertex3f(points[i + 1].x,
                       points[i + 1].y,
                       points[i + 1].z);
         }
      }
      else {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(points[i].x,
                       points[i].y,
                       points[i].z);
            glVertex3f(points[0].x,
                       points[0].y,
                       points[0].z);
         }
      }
      glEnd();
   }
   else {
      glBegin(GL_LINE_LOOP);
      for (i = 0; i < num_vertices; i++) {
         glVertex3f(points[i].x,
                    points[i].y,
                    points[i].z);
      }
      glEnd();
   }
}

/*******************************************************************************
 * priv_edges_ptcolrs
 *
 * DESCR:	Draw edges for fill area 3D with point and colour data
 * RETURNS:	N/A
 */

static void priv_edges_ptcolrs(
   Pint eflag,
   Pedge_data_list *edata,
   Pint num_vertices,
   Pptco3 *ptcolrs
   )
{
   Pint i;

   if (eflag == PEDGE_VISIBILITY) {
      glBegin(GL_LINES);
      for (i = 0; i < edata->num_edges - 1; i++) {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(ptcolrs[i].point.x,
                       ptcolrs[i].point.y,
                       ptcolrs[i].point.z);
            glVertex3f(ptcolrs[i + 1].point.x,
                       ptcolrs[i + 1].point.y,
                       ptcolrs[i + 1].point.z);
         }
      }
      if (edata->num_edges < num_vertices) {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(ptcolrs[i].point.x,
                       ptcolrs[i].point.y,
                       ptcolrs[i].point.z);
            glVertex3f(ptcolrs[i + 1].point.x,
                       ptcolrs[i + 1].point.y,
                       ptcolrs[i + 1].point.z);
         }
      }
      else {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(ptcolrs[i].point.x,
                       ptcolrs[i].point.y,
                       ptcolrs[i].point.z);
            glVertex3f(ptcolrs[0].point.x,
                       ptcolrs[0].point.y,
                       ptcolrs[0].point.z);
         }
      }
      glEnd();
   }
   else {
      glBegin(GL_LINE_LOOP);
      for (i = 0; i < num_vertices; i++) {
         glVertex3f(ptcolrs[i].point.x,
                    ptcolrs[i].point.y,
                    ptcolrs[i].point.z);
      }
      glEnd();
   }
}

/*******************************************************************************
 * priv_edges_ptnorms
 *
 * DESCR:	Draw edges for fill area 3D with point and normal data
 * RETURNS:	N/A
 */

static void priv_edges_ptnorms(
   Pint eflag,
   Pedge_data_list *edata,
   Pint num_vertices,
   Pptnorm3 *ptnorms
   )
{
   Pint i;

   if (eflag == PEDGE_VISIBILITY) {
      glBegin(GL_LINES);
      for (i = 0; i < edata->num_edges - 1; i++) {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(ptnorms[i].point.x,
                       ptnorms[i].point.y,
                       ptnorms[i].point.z);
            glVertex3f(ptnorms[i + 1].point.x,
                       ptnorms[i + 1].point.y,
                       ptnorms[i + 1].point.z);
         }
      }
      if (edata->num_edges < num_vertices) {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(ptnorms[i].point.x,
                       ptnorms[i].point.y,
                       ptnorms[i].point.z);
            glVertex3f(ptnorms[i + 1].point.x,
                       ptnorms[i + 1].point.y,
                       ptnorms[i + 1].point.z);
         }
      }
      else {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(ptnorms[i].point.x,
                       ptnorms[i].point.y,
                       ptnorms[i].point.z);
            glVertex3f(ptnorms[0].point.x,
                       ptnorms[0].point.y,
                       ptnorms[0].point.z);
         }
      }
      glEnd();
   }
   else {
      glBegin(GL_LINE_LOOP);
      for (i = 0; i < num_vertices; i++) {
         glVertex3f(ptnorms[i].point.x,
                    ptnorms[i].point.y,
                    ptnorms[i].point.z);
      }
      glEnd();
   }
}

/*******************************************************************************
 * priv_edges_ptconorms
 *
 * DESCR:	Draw edges for fill area 3D with point, colour and normal data
 * RETURNS:	N/A
 */

static void priv_edges_ptconorms(
   Pint eflag,
   Pedge_data_list *edata,
   Pint num_vertices,
   Pptconorm3 *ptconorms
   )
{
   Pint i;

   if (eflag == PEDGE_VISIBILITY) {
      glBegin(GL_LINES);
      for (i = 0; i < edata->num_edges - 1; i++) {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(ptconorms[i].point.x,
                       ptconorms[i].point.y,
                       ptconorms[i].point.z);
            glVertex3f(ptconorms[i + 1].point.x,
                       ptconorms[i + 1].point.y,
                       ptconorms[i + 1].point.z);
         }
      }
      if (edata->num_edges < num_vertices) {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(ptconorms[i].point.x,
                       ptconorms[i].point.y,
                       ptconorms[i].point.z);
            glVertex3f(ptconorms[i + 1].point.x,
                       ptconorms[i + 1].point.y,
                       ptconorms[i + 1].point.z);
         }
      }
      else {
         if (edata->edgedata.edges[i] == PEDGE_ON) {
            glVertex3f(ptconorms[i].point.x,
                       ptconorms[i].point.y,
                       ptconorms[i].point.z);
            glVertex3f(ptconorms[0].point.x,
                       ptconorms[0].point.y,
                       ptconorms[0].point.z);
         }
      }
      glEnd();
   }
   else {
      glBegin(GL_LINE_LOOP);
      for (i = 0; i < num_vertices; i++) {
         glVertex3f(ptconorms[i].point.x,
                    ptconorms[i].point.y,
                    ptconorms[i].point.z);
      }
      glEnd();
   }
}

/*******************************************************************************
 * wsgl_edge_area_set3_data
 *
 * DESCR:	Draw fill area set edges with data 3D
 * RETURNS:	N/A
 */

void wsgl_edge_area_set3_data(
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

   wsgl_setup_edge_attr(ast);
   switch (fasd3.vflag) {
      case PVERT_COORD:
         for (i = 0; i < fasd3.nfa; i++) {
            priv_edges_points(fasd3.eflag,
                              fasd3.edata,
                              fasd3.vdata->num_vertices,
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
            priv_edges_ptcolrs(fasd3.eflag,
                               fasd3.edata,
                               fasd3.vdata->num_vertices,
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
            priv_edges_ptnorms(fasd3.eflag,
                               fasd3.edata,
                               fasd3.vdata->num_vertices,
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
            priv_edges_ptconorms(fasd3.eflag,
                                 fasd3.edata,
                                 fasd3.vdata->num_vertices,
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
}

