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
#include <GL/gl.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/ws.h>
#include <phigs/util.h>
#include <phigs/private/wsxP.h>
#include <phigs/private/wsglP.h>

/*******************************************************************************
 * get_light_id
 *
 * DESCR:	Get light id helper function
 * RETURNS:	Light source idientifier
 */

static GLuint get_light_id(
   Pint ind
   )
{
   GLuint id;

   switch (ind) {
      case 1:  id = GL_LIGHT1; break;
      case 2:  id = GL_LIGHT2; break;
      case 3:  id = GL_LIGHT3; break;
      case 4:  id = GL_LIGHT4; break;
      case 5:  id = GL_LIGHT5; break;
      case 6:  id = GL_LIGHT6; break;
      case 7:  id = GL_LIGHT7; break;
      default: id = GL_LIGHT0; break;
   }

   return id;
}

/*******************************************************************************
 * setup_ambient_light
 *
 * DESCR:	Setup ambient light source helper function
 * RETURNS:	N/A
 */

static void setup_ambient_light(
   Pint ind,
   Pamb_light_src_rec *rec
   )
{
   GLfloat amb[4];
   GLuint id;

   amb[0] = rec->colr.val.general.x;
   amb[1] = rec->colr.val.general.y;
   amb[2] = rec->colr.val.general.z;
   amb[3] = 1.0;

#ifdef DEBUG
   printf("Ambient light: %f %f %f\n", amb[0], amb[1], amb[2]);
#endif

   id = get_light_id(ind);
   glLightfv(id, GL_AMBIENT, amb);
   glEnable(id);
}

/*******************************************************************************
 * setup_directional_light
 *
 * DESCR:	Setup directional light source helper function
 * RETURNS:	N/A
 */

static void setup_directional_light(
   Pint ind,
   Pdir_light_src_rec *rec
   )
{
   GLfloat dif[4];
   GLfloat pos[4];
   GLuint id;

   dif[0] = rec->colr.val.general.x;
   dif[1] = rec->colr.val.general.y;
   dif[2] = rec->colr.val.general.z;
   dif[3] = 1.0;

   pos[0] = rec->dir.delta_x;
   pos[1] = rec->dir.delta_y;
   pos[2] = rec->dir.delta_z;
   pos[3] = 0.0;

#ifdef DEBUG
   printf("Directional light: %f %f %f @(%f, %f %f)\n",
          dif[0], dif[1], dif[2],
          pos[0], pos[1], pos[2]);
#endif

   id = get_light_id(ind);
   glLightfv(id, GL_DIFFUSE, dif);
   glLightfv(id, GL_POSITION, pos);
   glEnable(id);
}

/*******************************************************************************
 * wsgl_update_light_src_state
 *
 * DESCR:	Update light source state for workstation
 * RETURNS:	N/A
 */

void wsgl_update_light_src_state(
   Ws *ws
   )
{
   Pint i;
   Phg_ret ret;
   Wsgl *wsgl = ws->render_context;

   glPushMatrix();
   glLoadIdentity();

   /* Activate light sources */
   for (i = 0; i < WS_MAX_LIGHT_SRC; i++) {
      if (phg_nset_name_is_set(&wsgl->cur_struct.lightstat, i)) {
#ifdef DEBUG
         printf("Setup light source: %d\n", i);
#endif
         (*ws->inq_representation)(ws,
                                   i,
                                   PINQ_REALIZED,
                                   PHG_ARGS_LIGHTSRCREP,
                                   &ret);
         if (ret.err == 0) {
            switch (ret.data.rep.lightsrcrep.type) {
               case PLIGHT_AMBIENT:
                  setup_ambient_light(i, &ret.data.rep.lightsrcrep.rec.ambient);
                  break;

               case PLIGHT_DIRECTIONAL:
                  setup_directional_light(i, &ret.data.rep.lightsrcrep.rec.directional);
                  break;

               default:
                  break;
            }
         }
      }
      else {
         glDisable(get_light_id(i));
      }
   }

   glPopMatrix();
}

/*******************************************************************************
 * wsgl_set_light_src_state
 *
 * DESCR:	Set light source state for workstation
 * RETURNS:	N/A
 */

void wsgl_set_light_src_state(
   Ws *ws,
   void *pdata
   )
{
   Pint i, num_ints;
   Pint *data;
   data = (Pint *) pdata;
   Wsgl *wsgl = ws->render_context;

   num_ints = *data;
   data++;
   for (i = 0; i < num_ints; i++) {
      phg_nset_name_set(&wsgl->cur_struct.lightstat, *data);
      data++;
   }

   num_ints = *data;
   data++;
   for (i = 0; i < num_ints; i++) {
      phg_nset_name_clear(&wsgl->cur_struct.lightstat, *data);
      data++;
   }

   if (phg_nset_names_is_empty_all(&wsgl->cur_struct.lightstat)) {
      wsgl->cur_struct.lighting = FALSE;
   }
   else {
      wsgl->cur_struct.lighting = TRUE;
   }

#ifdef DEBUG
   printf("Lighting nameset: ");
   phg_nset_print(&wsgl->cur_struct.lightstat);
   printf("Lighting is %s\n", (wsgl->cur_struct.lighting) ? "On" : "Off");
#endif

   wsgl_update_light_src_state(ws);
}

