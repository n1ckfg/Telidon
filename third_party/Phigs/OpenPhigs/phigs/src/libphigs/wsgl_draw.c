/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
*
*   This file is part of Open PHIGS
*   Copyright (C) 2011 - 2012 Surplus Users Ham Society
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
 * phg_draw_marker_dot
 *
 * DESCR:	Draw marker dots helper function
 * RETURNS:	N/A
 */

static void phg_draw_marker_dot(
   Ppoint_list *point_list,
   Pfloat scale
   )
{
   int i;

   glPointSize(scale);
   glBegin(GL_POINTS);
   for (i = 0; i < point_list->num_points; i++) {
      glVertex2f(point_list->points[i].x,
                 point_list->points[i].y);
   }
   glEnd();
}

/*******************************************************************************
 * phg_draw_marker_plus
 *
 * DESCR:	Draw marker pluses helper function
 * RETURNS:	N/A
 */

static void phg_draw_marker_plus(
   Ppoint_list *point_list,
   Pfloat scale
   )
{
   int i;
   float half_scale;

   half_scale = scale / 2.0;

   glLineWidth(1.0);
   glDisable(GL_LINE_STIPPLE);
   glBegin(GL_LINES);
   for (i = 0; i < point_list->num_points; i++) {
      glVertex2f(point_list->points[i].x - half_scale,
                 point_list->points[i].y);
      glVertex2f(point_list->points[i].x + half_scale,
                 point_list->points[i].y);
      glVertex2f(point_list->points[i].x,
                 point_list->points[i].y - half_scale);
      glVertex2f(point_list->points[i].x,
                 point_list->points[i].y + half_scale);
   }
   glEnd();
}

/*******************************************************************************
 * phg_draw_marker_asterisk
 *
 * DESCR:	Draw marker asterisks helper function
 * RETURNS:	N/A
 */

static void phg_draw_marker_asterisk(
   Ppoint_list *point_list,
   Pfloat scale
   )
{
   int i;
   float half_scale, small_scale;

   half_scale = scale / 2.0;
   small_scale = half_scale / 1.414;

   glLineWidth(1.0);
   glDisable(GL_LINE_STIPPLE);
   glBegin(GL_LINES);
   for (i = 0; i < point_list->num_points; i++) {
      glVertex2f(point_list->points[i].x - half_scale,
                 point_list->points[i].y);
      glVertex2f(point_list->points[i].x + half_scale,
                 point_list->points[i].y);
      glVertex2f(point_list->points[i].x,
                 point_list->points[i].y - half_scale);
      glVertex2f(point_list->points[i].x,
                 point_list->points[i].y + half_scale);

      glVertex2f(point_list->points[i].x - small_scale,
                 point_list->points[i].y + small_scale);
      glVertex2f(point_list->points[i].x + small_scale,
                 point_list->points[i].y - small_scale);
      glVertex2f(point_list->points[i].x - small_scale,
                 point_list->points[i].y - small_scale);
      glVertex2f(point_list->points[i].x + small_scale,
                 point_list->points[i].y + small_scale);
   }
   glEnd();
}

/*******************************************************************************
 * phg_draw_marker_cross
 *
 * DESCR:	Draw marker crosses helper function
 * RETURNS:	N/A
 */

static void phg_draw_marker_cross(
   Ppoint_list *point_list,
   Pfloat scale
   )
{
   int i;
   float half_scale;

   half_scale = scale / 2.0;

   glLineWidth(1.0);
   glDisable(GL_LINE_STIPPLE);
   glBegin(GL_LINES);
   for (i = 0; i < point_list->num_points; i++) {
      glVertex2f(point_list->points[i].x - half_scale,
                 point_list->points[i].y + half_scale);
      glVertex2f(point_list->points[i].x + half_scale,
                 point_list->points[i].y - half_scale);
      glVertex2f(point_list->points[i].x - half_scale,
                 point_list->points[i].y - half_scale);
      glVertex2f(point_list->points[i].x + half_scale,
                 point_list->points[i].y + half_scale);
   }
   glEnd();
}

/*******************************************************************************
 * phg_draw_polymarker
 *
 * DESCR:	Draw markers
 * RETURNS:	N/A
 */

void phg_draw_polymarker(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pint type;
   Pfloat size;
   Ppoint_list point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint *) &data[1];

   phg_setup_marker_attr(ast, &type, &size);
   switch (type) {
      case PMARKER_DOT:
         phg_draw_marker_dot(&point_list, size);
      break;

      case PMARKER_PLUS:
         phg_draw_marker_plus(&point_list, size);
      break;

      case PMARKER_ASTERISK:
         phg_draw_marker_asterisk(&point_list, size);
      break;

      case PMARKER_CROSS:
         phg_draw_marker_cross(&point_list, size);
      break;
   }
}

/*******************************************************************************
 * phg_draw_polymarker3
 *
 * DESCR:	Draw markers 3D
 * RETURNS:	N/A
 */

void phg_draw_polymarker3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   Pint type;
   Pfloat size;
   int i;
   Ppoint_list plist;
   Ppoint_list3 point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint3 *) &data[1];

   phg_setup_line_attr(ast);

   if (PHG_SCRATCH_SPACE(&ws->scratch,
                         point_list.num_points * sizeof(Ppoint))) {
      plist.num_points = point_list.num_points;
      plist.points = (Ppoint *) ws->scratch.buf;

      for (i = 0; i < point_list.num_points; i++) {
         plist.points[i].x = point_list.points[i].x;
         plist.points[i].y = point_list.points[i].y;
      }

      phg_setup_marker_attr(ast, &type, &size);
      switch (type) {
         case PMARKER_DOT:
            phg_draw_marker_dot(&plist, size);
         break;

         case PMARKER_PLUS:
            phg_draw_marker_plus(&plist, size);
         break;

         case PMARKER_ASTERISK:
            phg_draw_marker_asterisk(&plist, size);
         break;

         case PMARKER_CROSS:
            phg_draw_marker_cross(&plist, size);
         break;
      }
   }
   else {
      ERR_REPORT(ws->erh, ERR900);
   }
}

/*******************************************************************************
 * phg_draw_polyline
 *
 * DESCR:	Draw lines
 * RETURNS:	N/A
 */

void phg_draw_polyline(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   int i;
   Ppoint_list point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint *) &data[1];

   phg_setup_line_attr(ast);
   glBegin(GL_LINES);
   for (i = 0; i < point_list.num_points; i++) {
      glVertex2f(point_list.points[i].x,
                 point_list.points[i].y);
   }
   glEnd();
}

/*******************************************************************************
 * phg_draw_polyline3
 *
 * DESCR:	Draw lines 3D
 * RETURNS:	N/A
 */

void phg_draw_polyline3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   int i;
   Ppoint_list3 point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint3 *) &data[1];

   phg_setup_line_attr(ast);
   glBegin(GL_LINES);
   for (i = 0; i < point_list.num_points; i++) {
      glVertex3f(point_list.points[i].x,
                 point_list.points[i].y,
                 point_list.points[i].z);
   }
   glEnd();
}

/*******************************************************************************
 * phg_draw_fill_area
 *
 * DESCR:	Draw fill area
 * RETURNS:	N/A
 */

void phg_draw_fill_area(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   int i;
   Pint_style style;
   Ppoint_list point_list;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint *) &data[1];

   style = phg_get_int_style(ast);
   if (style != PSTYLE_EMPTY) {
      phg_setup_int_attr(ast);
      glBegin(GL_POLYGON);
      for (i = 0; i < point_list.num_points; i++) {
         glVertex2f(point_list.points[i].x,
                    point_list.points[i].y);
      }
      glEnd();
   }

   if (phg_get_edge_flag(ast) == PEDGE_ON) {
      phg_setup_edge_attr(ast);
      glBegin(GL_LINE_LOOP);
      for (i = 0; i < point_list.num_points; i++) {
         glVertex2f(point_list.points[i].x,
                    point_list.points[i].y);
      }
      glEnd();
   }
}

/*******************************************************************************
 * phg_draw_fill_area3
 *
 * DESCR:	Draw fill area 3D
 * RETURNS:	N/A
 */

void phg_draw_fill_area3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   )
{
   int i;
   Pint_style style;
   Pedge_flag flag;
   Ppoint_list3 point_list;
   Wsgl_handle wsgl = ws->render_context;
   Pint *data = (Pint *) pdata;

   point_list.num_points = *data;
   point_list.points = (Ppoint3 *) &data[1];

   style = phg_get_int_style(ast);
   flag = phg_get_edge_flag(ast);

   phg_set_polygon_offset(phg_get_edge_width(ast));
   glEnable(GL_POLYGON_OFFSET_FILL);
   glEnable(GL_POLYGON_OFFSET_LINE);

   if  ((style == PSTYLE_EMPTY) || (style == PSTYLE_HOLLOW)) {

      /* If hidden surface removal, clear interiour to background colour */
      if (wsgl->cur_struct.hlhsr_id == PHIGS_HLHSR_ID_ON) {
         phg_setup_background(ws);
         glBegin(GL_POLYGON);
         for (i = 0; i < point_list.num_points; i++) {
            glVertex3f(point_list.points[i].x,
                       point_list.points[i].y,
                       point_list.points[i].z);
         }
         glEnd();
      }

      if (style == PSTYLE_HOLLOW) {
         phg_setup_int_attr(ast);
         glBegin(GL_POLYGON);
         for (i = 0; i < point_list.num_points; i++) {
            glVertex3f(point_list.points[i].x,
                       point_list.points[i].y,
                       point_list.points[i].z);
         }
         glEnd();
      }
   }
   else {
      phg_setup_int_attr(ast);
      glBegin(GL_POLYGON);
      for (i = 0; i < point_list.num_points; i++) {
         glVertex3f(point_list.points[i].x,
                    point_list.points[i].y,
                    point_list.points[i].z);
      }
      glEnd();
   }

   if (flag == PEDGE_ON) {
      phg_setup_edge_attr(ast);
      glBegin(GL_LINE_LOOP);
      for (i = 0; i < point_list.num_points; i++) {
         glVertex3f(point_list.points[i].x,
                    point_list.points[i].y,
                    point_list.points[i].z);
      }
      glEnd();
   }

   glDisable(GL_POLYGON_OFFSET_LINE);
   glDisable(GL_POLYGON_OFFSET_FILL);
}

/*******************************************************************************
 * phg_draw_fill_area_set
 *
 * DESCR:	Draw fill area set
 * RETURNS:	N/A
 */

void phg_draw_fill_area_set(
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
   for (i = 0; i < num_lists; i++) {
      point_list.num_points = *data;
      point_list.points = (Ppoint *) &data[1];
      phg_draw_fill_area(ws, data, ast);
      data = (Pint *) &point_list.points[point_list.num_points];
   }
}

/*******************************************************************************
 * phg_draw_fill_area_set3
 *
 * DESCR:	Draw fill area set 3D
 * RETURNS:	N/A
 */

void phg_draw_fill_area_set3(
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
   for (i = 0; i < num_lists; i++) {
      point_list.num_points = *data;
      point_list.points = (Ppoint3 *) &data[1];
      phg_draw_fill_area3(ws, data, ast);
      data = (Pint *) &point_list.points[point_list.num_points];
   }
}

/*******************************************************************************
 * draw_text_string
 *
 * DESCR:	Draw text with string precision helper function
 * RETURNS:	N/A
 */

static void draw_text_string(
   Ws *ws,
   Ptext *text,
   Ws_attr_st *ast
   )
{
   Phg_font *fnt;
   Pfloat char_ht;
   Pfloat char_expan;
   char *str;
   size_t i, len;
   Phg_char *ch;
   Ppoint_list *spath;
   Ppoint pos;
   int j, z;

   phg_setup_text_attr(ast, &fnt, &char_expan);
   char_ht = ast->char_ht;

   pos.x = text->pos.x;
   pos.y = text->pos.y;
   str = text->char_string;

   len = strlen(str);
   for (i = 0; i < len; i++) {

       ch = &fnt->chars[(int) str[i]];
       if (ch->num_paths > 0) {

          for (j = 0, spath = ch->paths;
               j < ch->num_paths;
               j++, spath++) {

             glBegin(GL_LINE_STRIP);
             for(z = 0; z < spath->num_points; z++) {
                glVertex2f(pos.x + spath->points[z].x * char_ht * char_expan,
                           pos.y + spath->points[z].y * char_ht);
             }
             glEnd();
          }
       }

       pos.x += ch->right * char_ht * char_expan;
   }
}

/*******************************************************************************
 * draw_text_char
 *
 * DESCR:	Draw text with character precision helper function
 * RETURNS:	N/A
 */

static void draw_text_char(
   Ws *ws,
   Ptext *text,
   Ws_attr_st *ast
   )
{
   Phg_font *fnt;
   Pfloat char_ht;
   Pfloat char_expan;
   Pfloat char_space;
   Pfloat height;
   Ptext_path text_path;
   char *str;
   size_t i, len;
   Phg_char *ch;
   Ppoint_list *spath;
   Ppoint pos;
   int j, z;

   phg_setup_text_attr(ast, &fnt, &char_expan);
   char_ht = ast->char_ht;
   phg_get_char_text_attr(ast, &char_space);
   text_path = ast->text_path;
   height = fnt->top - fnt->bottom;

   pos.x = text->pos.x;
   pos.y = text->pos.y;
   str = text->char_string;

   len = strlen(str);
   for (i = 0; i < len; i++) {

       ch = &fnt->chars[(int) str[i]];
       if (ch->num_paths > 0) {

          for (j = 0, spath = ch->paths;
               j < ch->num_paths;
               j++, spath++) {

             glBegin(GL_LINE_STRIP);
             for(z = 0; z < spath->num_points; z++) {
                glVertex2f(pos.x + spath->points[z].x * char_ht * char_expan,
                           pos.y + spath->points[z].y * char_ht);
             }
             glEnd();
          }
       }

       switch (text_path) {
          case PPATH_RIGHT:
             pos.x += (ch->right + char_space) * char_ht * char_expan;
             break;

          case PPATH_LEFT:
             pos.x -= (ch->right + char_space) * char_ht * char_expan;
             break;

          case PPATH_UP:
             pos.y += (height + char_space) * char_ht;
             break;

          case PPATH_DOWN:
             pos.y -= (height + char_space) * char_ht;
             break;
       }
   }
}

/*******************************************************************************
 * draw_text_stroke
 *
 * DESCR:	Draw text with stroke precision helper function
 * RETURNS:	N/A
 */

static void draw_text_stroke(
   Ws *ws,
   Ptext *text,
   Ws_attr_st *ast
   )
{
   Phg_font *fnt;
   Pfloat char_ht;
   Pfloat char_expan;
   Pfloat char_space;
   Pfloat height;
   Ptext_path text_path;
   char *str;
   size_t i, len;
   Phg_char *ch;
   Ppoint_list *spath;
   Ppoint pt, pos;
   int j, z;
   Pvec *up;
   Pvec right;

   phg_setup_text_attr(ast, &fnt, &char_expan);
   char_ht = ast->char_ht;
   phg_get_char_text_attr(ast, &char_space);
   text_path = ast->text_path;
   height = fnt->top - fnt->bottom;
   up = &ast->char_up_vec, sizeof(Pvec);

   right.delta_x =  up->delta_y;
   right.delta_y = -up->delta_x;

   pos.x = text->pos.x;
   pos.y = text->pos.y;
   str = text->char_string;

   len = strlen(str);
   for (i = 0; i < len; i++) {

      ch = &fnt->chars[(int) str[i]];
      if (ch->num_paths > 0) {

         for (j = 0, spath = ch->paths;
              j < ch->num_paths;
              j++, spath++) {

            glBegin(GL_LINE_STRIP);
            for(z = 0; z < spath->num_points; z++) {
               pt.x = spath->points[z].x * right.delta_x +
                      spath->points[z].y * right.delta_y;
               pt.y = spath->points[z].x * up->delta_x +
                      spath->points[z].y * up->delta_y;
               glVertex2f(pos.x + pt.x * char_ht * char_expan,
                          pos.y + pt.y * char_ht);
            }
            glEnd();
         }
      }

      switch (text_path) {
         case PPATH_RIGHT:
            pos.x += (ch->right + char_space) *
                        right.delta_x * char_ht * char_expan;
            pos.y += (ch->right + char_space) *
                        up->delta_x * char_ht * char_expan;
            break;

         case PPATH_LEFT:
            pos.x -= (ch->right + char_space) *
                        right.delta_x * char_ht * char_expan;
            pos.y -= (ch->right + char_space) *
                         up->delta_x * char_ht * char_expan;
            break;

         case PPATH_UP:
            pos.x += (height + char_space) * right.delta_y * char_ht;
            pos.y += (height + char_space) * up->delta_y * char_ht;
            break;

         case PPATH_DOWN:
            pos.x -= (height + char_space) * right.delta_y * char_ht;
            pos.y -= (height + char_space) * up->delta_y * char_ht;
            break;
      }
   }
}

/*******************************************************************************
 * phg_draw_text
 *
 * DESCR:	Draw text
 * RETURNS:	N/A
 */

void phg_draw_text(
   Ws *ws,
   void *tdata,
   Ws_attr_st *ast
   )
{
   Ptext_prec prec;
   Ptext text;
   Ppoint *pos = (Ppoint *) tdata;

   memcpy(&text.pos, pos, sizeof(Ppoint));
   text.char_string = (char *) &pos[1];
   prec = phg_get_text_prec(ast);
   switch (prec) {
      case PREC_STRING:
         draw_text_string(ws, &text, ast);
         break;

      case PREC_CHAR:
         draw_text_char(ws, &text, ast);
         break;

      case PREC_STROKE:
         draw_text_stroke(ws, &text, ast);
         break;
   }
}

