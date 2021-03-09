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
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/ws.h>
#include <phigs/private/wsxP.h>
#include <phigs/private/wsglP.h>

/*******************************************************************************
 * init_output_ws_dt
 *
 * DESCR:	Helper initialization function for output ws dt
 * RETURNS:	N/A
 */

static void init_output_ws_dt(
   Wst_output_wsdt *wsdt,
   Pint ws_type
   )
{
   Pgcolr fg;

   wsdt->ws_class             = PCLASS_RASTER;
   wsdt->deferral_mode        = PDEFER_ASAP;
   wsdt->modification_mode    = PMODE_UQUM;

   switch (ws_type) {
      case PWST_OUTPUT_TRUE:
      case PWST_OUTIN_TRUE:
         wsdt->default_colour_model = PMODEL_RGB;
         wsdt->has_double_buffer    = FALSE;
         break;

      case PWST_OUTPUT_TRUE_DB:
      case PWST_OUTIN_TRUE_DB:
         wsdt->default_colour_model = PMODEL_RGB;
         wsdt->has_double_buffer    = TRUE;
         break;

      default:
         wsdt->default_colour_model = PINDIRECT;
         wsdt->has_double_buffer    = FALSE;
         break;
   }

   /* Set foreground colour */
   fg.type = PMODEL_RGB;
   fg.val.general.x = 1.0;
   fg.val.general.y = 1.0;
   fg.val.general.z = 1.0;

   /* Setup default attribute bundles */
   wsdt->num_predefined_polyline_indices = WST_MIN_PREDEF_LINE_REPS;
   wsdt->default_polyline_bundle_table[0].type = PLINE_SOLID;
   wsdt->default_polyline_bundle_table[0].width = 1.0;
   memcpy(&wsdt->default_polyline_bundle_table[0].colr,  &fg, sizeof(Pgcolr));

   wsdt->num_predefined_polymarker_indices = WST_MIN_PREDEF_MARKER_REPS;
   wsdt->default_polymarker_bundle_table[0].type = PLINE_SOLID;
   wsdt->default_polymarker_bundle_table[0].size = 1.0;
   memcpy(&wsdt->default_polymarker_bundle_table[0].colr, &fg, sizeof(Pgcolr));

   wsdt->num_predefined_text_indices = WST_MIN_PREDEF_TEXT_REPS;
   wsdt->default_text_bundle_table[0].font = 1;
   wsdt->default_text_bundle_table[0].prec = PREC_STRING;
   wsdt->default_text_bundle_table[0].char_expan = 1.0;
   wsdt->default_text_bundle_table[0].char_space = 0.0;
   memcpy(&wsdt->default_text_bundle_table[0].colr, &fg, sizeof(Pgcolr));

   wsdt->num_predefined_edge_indices = WST_MIN_PREDEF_EDGE_REPS;
   wsdt->default_edge_bundle_table[0].flag = PEDGE_OFF;
   wsdt->default_edge_bundle_table[0].type = PLINE_SOLID;
   wsdt->default_edge_bundle_table[0].width = 1.0;
   memcpy(&wsdt->default_edge_bundle_table[0].colr, &fg, sizeof(Pgcolr));

   wsdt->num_predefined_interior_indices = WST_MIN_PREDEF_INTERIOR_REPS;
   wsdt->default_interior_bundle_table[0].style = PSTYLE_SOLID;
   wsdt->default_interior_bundle_table[0].style_ind = 1;
   memcpy(&wsdt->default_interior_bundle_table[0].colr,
          &fg,
          sizeof(Pgcolr));
   wsdt->default_interior_bundle_table[0].refl_eqn = PREFL_AMB_DIFF;
   wsdt->default_interior_bundle_table[0].shad_meth = PSD_COLOUR;
   wsdt->default_interior_bundle_table[0].refl_props.ambient_coef = 1.0;
   wsdt->default_interior_bundle_table[0].refl_props.diffuse_coef = 1.0;
   wsdt->default_interior_bundle_table[0].refl_props.specular_coef = 1.0;
   memcpy(&wsdt->default_interior_bundle_table[0].refl_props.specular_colr,
          &fg,
          sizeof(Pgcolr));
   wsdt->default_interior_bundle_table[0].back_style = PSTYLE_SOLID;
   wsdt->default_interior_bundle_table[0].back_style_ind = 1;
   memcpy(&wsdt->default_interior_bundle_table[0].back_colr,
          &fg,
          sizeof(Pgcolr));
   wsdt->default_interior_bundle_table[0].back_refl_eqn = PREFL_AMBIENT;
   wsdt->default_interior_bundle_table[0].back_shad_meth = PSD_NONE;
   wsdt->default_interior_bundle_table[0].back_refl_props.ambient_coef = 0.2;
   wsdt->default_interior_bundle_table[0].back_refl_props.diffuse_coef = 0.0;
   wsdt->default_interior_bundle_table[0].back_refl_props.specular_coef = 0.0;
   memcpy(&wsdt->default_interior_bundle_table[0].back_refl_props.specular_colr,
          &fg,
          sizeof(Pgcolr));
}

/*******************************************************************************
 * init_views
 *
 * DESCR:	Helper function to initialize default views
 * RETURNS:	N/A
 */

static void init_views(
    Wst_phigs_dt *ws_dt
    )
{
    int	i;
    Pview_rep3 *view;

    view = ws_dt->default_views;

    ws_dt->num_predefined_views = WST_MIN_PREDEF_VIEW_REPS;

    phg_mat_identity( view[0].ori_matrix );
    phg_mat_identity( view[0].map_matrix );
    view[0].clip_limit.x_min = 0.0;
    view[0].clip_limit.x_max = 1.0;
    view[0].clip_limit.y_min = 0.0;
    view[0].clip_limit.y_max = 1.0;
    view[0].clip_limit.z_min = 0.0;
    view[0].clip_limit.z_max = 1.0;
    view[0].xy_clip = view[0].back_clip = view[0].front_clip = PIND_CLIP;
    for ( i = 1; i < WST_MIN_PREDEF_VIEW_REPS; i++ ) {
        memcpy(&view[i], &view[0], sizeof(Pview_rep3));
    }

    /* Predefined some interesting views. */
    /* View 1: parallel front view in lower left corner of ws window.
     * vrp = (0,0,0), vup = <0,1,0>, vpn = <0,0,1>, prp = (0.5,0.5,5.0)
     * win x limits = [0,1], win y limits = [0,1]
     * view plane = 0.0, front plane = 1.0, back plane = 0.0
     * vp x limits = [.1,.4], vp y limits = [.1,.4], vp z limits = [0,1]
     */
    view[1].map_matrix[0][0] = 0.3;
    view[1].map_matrix[0][3] = 0.1;
    view[1].map_matrix[1][1] = 0.3;
    view[1].map_matrix[1][3] = 0.1;
    view[1].clip_limit.x_min = 0.1;
    view[1].clip_limit.x_max = 0.4;
    view[1].clip_limit.y_min = 0.1;
    view[1].clip_limit.y_max = 0.4;
    view[1].clip_limit.z_min = 0.0;
    view[1].clip_limit.z_max = 1.0;

    /* View 2: top view in upper left corner of ws window.
     * vrp = (0,0,0), vup = <0,0,-1>, vpn = <0,1,0>, prp = (0.5,-0.5,5.0)
     * win x limits = [0,1], win y limits = [-1,0]
     * view plane = 0.0, front plane = 1.0, back plane = 0.0
     * vp x limits = [.1,.4], vp y limits = [.6,.9], vp z limits = [0,1]
     */
    view[2].map_matrix[0][0] = 0.3;
    view[2].map_matrix[0][3] = 0.1;
    view[2].map_matrix[1][1] = 0.3;
    view[2].map_matrix[1][3] = 0.9;
    view[2].ori_matrix[1][1] =  0.0;
    view[2].ori_matrix[1][2] = -1.0;
    view[2].ori_matrix[2][1] =  1.0;
    view[2].ori_matrix[2][2] =  0.0;
    view[2].clip_limit.x_min = 0.1;
    view[2].clip_limit.x_max = 0.4;
    view[2].clip_limit.y_min = 0.6;
    view[2].clip_limit.y_max = 0.9;
    view[2].clip_limit.z_min = 0.0;
    view[2].clip_limit.z_max = 1.0;

    /* View 3: right side view in lower right corner of ws window.
     * vrp = (0,0,0), vup = <0,1,0>, vpn = <1,0,0>, prp = (-0.5,0.5,5.0)
     * win x limits = [-1,0], win y limits = [0,1]
     * view plane = 0.0, front plane = 1.0, back plane = 0.0
     * vp x limits = [.6,.9], vp y limits = [.1,.4], vp z limits = [0,1]
     */
    view[3].map_matrix[0][0] = 0.3;
    view[3].map_matrix[0][3] = 0.9;
    view[3].map_matrix[1][1] = 0.3;
    view[3].map_matrix[1][3] = 0.1;
    view[3].ori_matrix[0][0] =  0.0;
    view[3].ori_matrix[0][2] = -1.0;
    view[3].ori_matrix[2][0] =  1.0;
    view[3].ori_matrix[2][2] =  0.0;
    view[3].clip_limit.x_min = 0.6;
    view[3].clip_limit.x_max = 0.9;
    view[3].clip_limit.y_min = 0.1;
    view[3].clip_limit.y_max = 0.4;
    view[3].clip_limit.z_min = 0.0;
    view[3].clip_limit.z_max = 1.0;

    /* View 4: off-axis view in upper right corner of ws window.
     * vrp = (0,0,0), vup = <0,1,0>, vpn = <1,1,1>, prp = (0,0,5)
     * win x limits = [-a,a], win y limits = [-a,a], a = 1/sqrt(2)
     * view plane = 0.0, front plane = sqrt(3), back plane = 0.0
     * vp x limits = [.6,.9], vp y limits = [.6,.9], vp z limits = [0,1]
     */
    view[4].map_matrix[0][0] = 0.3 / sqrt(2.0);
    view[4].map_matrix[1][1] = 0.3 / sqrt(2.0);
    view[4].map_matrix[2][2] = 1.0 / sqrt(3.0);
    view[4].map_matrix[0][3] = 0.75;
    view[4].map_matrix[1][3] = 0.75;
    view[4].ori_matrix[0][0] =
        -(view[4].ori_matrix[0][2] = -1.0/sqrt(2.0));
    view[4].ori_matrix[2][0] =
        view[4].ori_matrix[2][1] =
        view[4].ori_matrix[2][2] =  1.0/sqrt(3.0);
    view[4].ori_matrix[1][0] =
        view[4].ori_matrix[1][2] = -1.0/(sqrt(3.0) * sqrt(2.0));
    view[4].ori_matrix[1][1] = -2.0 * view[4].ori_matrix[1][0];
    view[4].clip_limit.x_min = 0.6;
    view[4].clip_limit.x_max = 0.9;
    view[4].clip_limit.y_min = 0.6;
    view[4].clip_limit.y_max = 0.9;
    view[4].clip_limit.z_min = 0.0;
    view[4].clip_limit.z_max = 1.0;

    /* View 5: off-axis perspective view in whole of ws window.
     * vrp = (0,0,0), vup = <0,1,0>, vpn = <1,1,1>, prp = (0,0,20)
     * win x limits = [-a,a], win y limits = [-a,a], a = 1/sqrt(2)
     * view plane = 10.0, front plane = sqrt(3), back plane = 0.0
     * vp x limits = [0,1], vp y limits = [0,1], vp z limits = [0,1]
     */
    memcpy(view[5].ori_matrix,
           view[4].ori_matrix,
	   sizeof(Pmatrix3));
    view[5].map_matrix[0][0] =  0.5 / sqrt(2.0);
    view[5].map_matrix[1][1] =  0.5 / sqrt(2.0);
    view[5].map_matrix[0][2] = -0.025;
    view[5].map_matrix[1][2] = -0.025;
    view[5].map_matrix[2][2] = 1.0/sqrt(3.0) - 1.0/20.0;
    view[5].map_matrix[0][3] = 0.5;
    view[5].map_matrix[1][3] = 0.5;
    view[5].map_matrix[3][2] = -1.0/20.0;
    view[5].clip_limit.x_min = 0.0;
    view[5].clip_limit.x_max = 1.0;
    view[5].clip_limit.y_min = 0.0;
    view[5].clip_limit.y_max = 1.0;
    view[5].clip_limit.z_min = 0.0;
    view[5].clip_limit.z_max = 1.0;
}

/*******************************************************************************
 * init_devices
 *
 * DESCR:	Helper function to initialize input devices
 * RETURNS:	TRUE or FALSE
 */

int init_devices(
    Wst *wst
    )
{
   Ppoint3 position = {0.0, 0.0, 0.0};
   Plimit3 e_volume = {0.0, 1.0, 0.0, 1.0, 0.0, 1.0};
   Wst_input_wsdt *idt = &wst->desc_tbl.phigs_dt.in_dt;

   wst->desc_tbl.xwin_dt.num_pick_device_types = 1;
   wst->desc_tbl.xwin_dt.pick_device_types = (Pint *) malloc(sizeof(Pint));
   if (wst->desc_tbl.xwin_dt.pick_device_types == NULL) {
      return FALSE;
   }

   /* Default locator */
   idt->num_devs.loc = 1;
   memcpy(&idt->locators[0].position, &position, sizeof(Ppoint3));
   idt->locators[0].num_pets = 1;
   idt->locators[0].pets[0] = 1;
   memcpy(&idt->locators[0].e_volume, &e_volume, sizeof(Plimit3));
   idt->locators[0].record.pets.pet_r1.unused = 0;
   idt->locators[0].type = WST_LOC_TYPE_POINTER_BUTTON_1;

   /* Default stroke */
   idt->num_devs.stroke = 1;
   memcpy(&idt->strokes[0].e_volume, &e_volume, sizeof(Plimit3));
   idt->strokes[0].max_bufsize = 200;
   idt->strokes[0].num_pets = 1;
   idt->strokes[0].pets[0] = 1;
   idt->strokes[0].record.pets.pet_r1.unused = 0;
   idt->strokes[0].record.buffer_size = 100;
   idt->strokes[0].record.init_pos = 1;
   idt->strokes[0].type = WST_LOC_TYPE_POINTER_BUTTON_1;

   /* Default pick */
   idt->num_devs.pick = 1;
   memcpy(&idt->picks[0].e_volume, &e_volume, sizeof(Plimit3));
   idt->picks[0].num_pets = 1;
   idt->picks[0].pets[0] = 1;
   idt->picks[0].record.pets.pet_r1.unused = 0;
   idt->picks[0].type = WST_LOC_TYPE_POINTER_BUTTON_1;

   /* Default valuator */
   idt->num_devs.val = 1;
   memcpy(&idt->valuators[0].e_volume, &e_volume, sizeof(Plimit3));
   idt->valuators[0].record.pets.pet_r1.unused = 0;

   /* Default choice */
   idt->num_devs.choice = 1;
   memcpy(&idt->choices[0].e_volume, &e_volume, sizeof(Plimit3));
   idt->choices[0].record.pets.pet_r1.unused = 0;

   /* Default string */
   idt->num_devs.string = 1;
   memcpy(&idt->strings[0].e_volume, &e_volume, sizeof(Plimit3));
   idt->strings[0].record.pets.pet_r1.unused = 0;

   return TRUE;
}

/*******************************************************************************
 * phg_wstx_create
 *
 * DESCR:	Create workstation type
 * RETURNS:	Pointer to workstation type or NULL
 */

Wst* phg_wstx_create(
   Err_handle erh,
   Pws_cat category,
   int double_buffer
   )
{
   Wst *wst;
   Pint ws_type;

   switch (category) {
      case PCAT_OUT:
         if (double_buffer) {
            ws_type = PWST_OUTPUT_TRUE_DB;
         }
         else {
            ws_type = PWST_OUTPUT_TRUE;
         }
         break;

      case PCAT_OUTIN:
         if (double_buffer) {
            ws_type = PWST_OUTIN_TRUE_DB;
         }
         else {
            ws_type = PWST_OUTIN_TRUE;
         }
         break;

      default:
         ws_type = PWST_OUTPUT_TRUE_DB;
         break;
   }

   wst = phg_wst_create(erh, ws_type);
   if (wst != NULL) {
      if (!phg_wstx_init(wst, category)) {
         wst = NULL;
      }
   }

   return wst;
}

/*******************************************************************************
 * phg_wstx_init
 *
 * DESCR:	Initialize workstation type
 * RETURNS:	TRUE or FALSE
 */

int phg_wstx_init(
   Wst *wst,
   Pws_cat category
   )
{
   Display *display;
   int screen_num;
   Wst_phigs_dt *dt;

   display = XOpenDisplay(NULL);
   if (display == NULL) {
      fprintf(stderr, "Error - Unable to open display\n");
      return FALSE;
   }

   screen_num = DefaultScreen(display);

   dt = &wst->desc_tbl.phigs_dt;

   dt->ws_category = category;
   dt->dev_coord_units = PDC_OTHER;

   dt->dev_coords[0] = (float) DisplayWidth(display, screen_num);
   dt->dev_coords[1] = (float) DisplayHeight(display, screen_num);
   dt->dev_coords[2] = 1.0;

   dt->dev_addrs_units[0] = DisplayWidth(display, screen_num);
   dt->dev_addrs_units[1] = DisplayHeight(display, screen_num);
   dt->dev_addrs_units[2] = 1;

   XCloseDisplay(display);

   dt->num_hlhsr_modes = 2;
   dt->hlhsr_modes = (Pint *) malloc(sizeof(Pint) * dt->num_hlhsr_modes);
   if (dt->hlhsr_modes == NULL) {
      return FALSE;
   }
   dt->hlhsr_modes[0] = PHIGS_HLHSR_MODE_NONE;
   dt->hlhsr_modes[1] = PHIGS_HLHSR_MODE_ZBUFF;

   /* Setup default views */
   init_views(dt);

   /* Initialize workstation output attributes */
   init_output_ws_dt(&dt->out_dt, wst->ws_type);

   if (category == PCAT_OUTIN) {

      /* Initialize input devices */
      if (!init_devices(wst)) {
         return FALSE;
      }
   }

#ifdef DEBUG
   printf("Added workstation type with coords: %f %f %f\n",
      wst->desc_tbl.phigs_dt.dev_coords[0],
      wst->desc_tbl.phigs_dt.dev_coords[1],
      wst->desc_tbl.phigs_dt.dev_coords[2]);
#endif

   return TRUE;
}

