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
#include <GL/gl.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/ws.h>
#include <phigs/util.h>
#include <phigs/private/wsxP.h>
#include <phigs/private/wsglP.h>

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

#ifdef DEBUG
   printf("Lighting nameset: ");
   phg_nset_print(&wsgl->cur_struct.lightstat);
   printf("Lighting is %s\n", (wsgl->cur_struct.lighting) ? "On" : "Off");
#endif
}

/*******************************************************************************
 * add_amb_light
 *
 * DESCR:	Add ambient light helper function
 * RETURNS:	N/A
 */

static void add_amb_light(
   Pcoval *result,
   Pint colr_type,
   Pint refl_eqn,
   Prefl_props *props,
   Pamb_light_src_rec *rec
   )
{
   if (refl_eqn >= PREFL_AMBIENT) {
      result->direct.rgb.red += props->ambient_coef *
                          rec->colr.val.general.x;
      result->direct.rgb.green += props->ambient_coef *
                          rec->colr.val.general.y;
      result->direct.rgb.blue += props->ambient_coef *
                          rec->colr.val.general.z;
   }
}

/*******************************************************************************
 * add_dir_light
 *
 * DESCR:	Add directional light helper function
 * RETURNS:	N/A
 */

static void add_dir_light(
   Pcoval *result,
   Pint colr_type,
   Pvec3 *normal,
   Pint refl_eqn,
   Prefl_props *props,
   Pdir_light_src_rec *rec
   )
{
   Pfloat dp = rec->dir.delta_x * normal->delta_x +
               rec->dir.delta_y * normal->delta_y +
               rec->dir.delta_z * normal->delta_z;

   if (refl_eqn >= PREFL_AMB_DIFF) {
      result->direct.rgb.red += dp * props->diffuse_coef *
                          rec->colr.val.general.x;
      result->direct.rgb.green += dp * props->diffuse_coef *
                          rec->colr.val.general.y;
      result->direct.rgb.blue += dp * props->diffuse_coef *
                          rec->colr.val.general.z;
   }
}

/*******************************************************************************
 * wsgl_light_colr
 *
 * DESCR:	Perform lighting calculations and set colour for vertex
 * RETURNS:	N/A
 */

void wsgl_light_colr(
   Ws *ws,
   Pcoval *result,
   Pint refl_eqn,
   Prefl_props *refl_props,
   Pint colr_type,
   Pcoval *colr,
   Pvec3 *normal
   )
{
   int i;
   Phg_ret ret;
   Pvec3 norm;
   Ppoint3 pt, pn;
   Wsgl *wsgl = ws->render_context;

   pt.x = normal->delta_x;
   pt.y = normal->delta_y;
   pt.z = normal->delta_z;

   phg_tranpt3(&pt, wsgl->model_tran, &pn);

   norm.delta_x = pn.x;
   norm.delta_y = pn.y;
   norm.delta_z = pn.z;

   result->direct.rgb.red = 0.0;
   result->direct.rgb.green = 0.0;
   result->direct.rgb.blue = 0.0;

   /* Process light sources */
   for (i = 0; i < WS_MAX_LIGHT_SRC; i++) {
      if (phg_nset_name_is_set(&wsgl->cur_struct.lightstat, i)) {
         (*ws->inq_representation)(ws,
                                   i,
                                   PINQ_REALIZED,
                                   PHG_ARGS_LIGHTSRCREP,
                                   &ret);
         if (ret.err == 0) {
            switch (ret.data.rep.lightsrcrep.type) {
               case PLIGHT_AMBIENT:
                  add_amb_light(result, colr_type, refl_eqn, refl_props,
                                &ret.data.rep.lightsrcrep.rec.ambient);
                  break;

               case PLIGHT_DIRECTIONAL:
                  add_dir_light(result, colr_type, &norm, refl_eqn, refl_props,
                                &ret.data.rep.lightsrcrep.rec.directional);
                  break;
            }
         }
      }
   }

   result->direct.rgb.red *= colr->direct.rgb.red;
   result->direct.rgb.green *= colr->direct.rgb.green;
   result->direct.rgb.blue *= colr->direct.rgb.blue;

   if (result->direct.rgb.red > 1.0) {
      result->direct.rgb.red = 1.0;
   }
   if (result->direct.rgb.green > 1.0) {
      result->direct.rgb.green = 1.0;
   }
   if (result->direct.rgb.blue > 1.0) {
      result->direct.rgb.blue = 1.0;
   }
}

