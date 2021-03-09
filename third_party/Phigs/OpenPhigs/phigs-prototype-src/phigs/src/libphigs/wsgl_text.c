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
 * wsgl_text_string
 *
 * DESCR:	Draw text with string precision helper function
 * RETURNS:	N/A
 */

static void wsgl_text_string(
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

   wsgl_setup_text_attr(ast, &fnt, &char_expan);
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
 * wsgl_text_char
 *
 * DESCR:	Draw text with character precision helper function
 * RETURNS:	N/A
 */

static void wsgl_text_char(
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

   wsgl_setup_text_attr(ast, &fnt, &char_expan);
   char_ht = ast->char_ht;
   char_space = wsgl_get_char_space(ast);
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
 * wsgl_text_stroke
 *
 * DESCR:	Draw text with stroke precision helper function
 * RETURNS:	N/A
 */

static void wsgl_text_stroke(
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

   wsgl_setup_text_attr(ast, &fnt, &char_expan);
   char_ht = ast->char_ht;
   char_space = wsgl_get_char_space(ast);
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
 * wsgl_text
 *
 * DESCR:	Draw text
 * RETURNS:	N/A
 */

void wsgl_text(
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
   prec = wsgl_get_text_prec(ast);
   switch (prec) {
      case PREC_STRING:
         wsgl_text_string(ws, &text, ast);
         break;

      case PREC_CHAR:
         wsgl_text_char(ws, &text, ast);
         break;

      case PREC_STROKE:
         wsgl_text_stroke(ws, &text, ast);
         break;
   }
}

