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
#include <phigs/phg.h>
#include <phigs/private/wsxP.h>

#define STRUCT_OBJECT  0
#define STRUCT_SCENE   1
#define STRUCT_MAIN    2
#define STRUCT_BORDER  3

#define NAME_VIEW_1    1
#define NAME_VIEW_2    2
#define NAME_VIEW_3    3
#define NAME_VIEW_4    4

#define WS_1           0

#define WIDTH          0.5
#define HEIGHT         0.5
#define SPACE          0.6
#define DEPTH         -0.2
#define LOW            0.2

#define FILL_STYLE     PSTYLE_SOLID
#define FILL_STYLE_IND 4
#define EDGE_WIDTH     2.0

#define WIN_X0         0.0
#define WIN_X1         1.0
#define WIN_Y0         0.0
#define WIN_Y1         1.0

Ppoint3 pts_quad[] = {
   {0.0, 0.0, 0.0},
   {WIDTH, 0.0, 0.0},
   {WIDTH, HEIGHT, 0.0},
   {0.0, HEIGHT, 0.0}
};

Ppoint_list3 plist_quad = {
   4, pts_quad
};

Ppoint pts_vline[] = {
   {0.0, 0.4},
   {1.0, 0.4}
};

Ppoint_list plist_vline ={
   2, pts_vline
};

Ppoint pts_hline[] = {
   {0.4, 0.0},
   {0.4, 1.0}
};

Ppoint_list plist_hline ={
   2, pts_hline
};

Pint errnum;
Pvec3 tvec3;
Pmatrix3 scale3;
Pmatrix3 tran3;
Pmatrix3 rot3;
Pcolr_rep col_rep;
Pgcolr dark, medium, light, white, red;
Plimit win = {WIN_X0, WIN_X1, WIN_Y0, WIN_Y1};
Ppoint3 stroke_points[100];
Ppoint_list3 stroke = {0, stroke_points};
Ppick_path_elem path_list[10];
Ppick_path pick = {0, path_list};
Pint view_list_1[] = {NAME_VIEW_1};
Pint view_list_2[] = {NAME_VIEW_2};
Pint view_list_3[] = {NAME_VIEW_3};
Pint view_list_4[] = {NAME_VIEW_4};
Pint_list names_view_1 = {1, view_list_1};
Pint_list names_view_2 = {1, view_list_2};
Pint_list names_view_3 = {1, view_list_3};
Pint_list names_view_4 = {1, view_list_4};
Pint view_list[] = {NAME_VIEW_1, NAME_VIEW_2, NAME_VIEW_3, NAME_VIEW_4};
Pint_list pick_incl = {4, view_list};
Pint_list pick_excl = {1, view_list_1};
Pint_list empty_set = {0, NULL};

void init_scene(void)
{
   dark.type = PMODEL_RGB;
   dark.val.general.x = 0.0;
   dark.val.general.y = 0.25;
   dark.val.general.z = 0.25;

   medium.type = PMODEL_RGB;
   medium.val.general.x = 0.0;
   medium.val.general.y = 0.5;
   medium.val.general.z = 0.5;

   light.type = PMODEL_RGB;
   light.val.general.x = 0.0;
   light.val.general.y = 0.5;
   light.val.general.z = 0.5;

   white.type = PMODEL_RGB;
   white.val.general.x = 1.0;
   white.val.general.y = 1.0;
   white.val.general.z = 1.0;

   red.type = PMODEL_RGB;
   red.val.general.x = 1.0;
   red.val.general.y = 0.0;
   red.val.general.z = 0.0;

   popen_struct(STRUCT_OBJECT);
   pfill_area3(&plist_quad);
   ppolymarker3(&plist_quad);
   pclose_struct();

   tvec3.delta_x = 1.0;
   tvec3.delta_y = 1.0;
   tvec3.delta_z = 1.0;
   pscale3(&tvec3, &errnum, scale3);

   tvec3.delta_x = 0.0;
   tvec3.delta_y = 0.0;
   tvec3.delta_z = DEPTH;
   ptranslate3(&tvec3, &errnum, tran3);
   protate_x(-3.14 / 4.0, &errnum, rot3);

   popen_struct(STRUCT_SCENE);
   pset_edge_flag(PEDGE_ON);
   pset_edge_colr(&white);
   pset_edgewidth(EDGE_WIDTH);
   pset_edgetype(PLINE_SOLID);
   pset_int_colr(&dark);
   pset_int_style(FILL_STYLE);
   pset_int_style_ind(FILL_STYLE_IND);
   pset_marker_type(PMARKER_CROSS);
   pset_marker_size(0.1);
   pset_marker_colr(&red);
   pset_local_tran3(tran3, PTYPE_REPLACE);
   pset_pick_id(1);
   pexec_struct(STRUCT_OBJECT);
   tvec3.delta_z += SPACE;
   ptranslate3(&tvec3, &errnum, tran3);
   pset_local_tran3(rot3, PTYPE_REPLACE);
   pset_local_tran3(tran3, PTYPE_POSTCONCAT);
   pset_int_colr(&medium);
   pset_pick_id(2);
   pexec_struct(STRUCT_OBJECT);
   tvec3.delta_z += SPACE;
   ptranslate3(&tvec3, &errnum, tran3);
   pset_local_tran3(rot3, PTYPE_REPLACE);
   pset_local_tran3(rot3, PTYPE_POSTCONCAT);
   plabel(10);
   pset_local_tran3(tran3, PTYPE_POSTCONCAT);
   pset_int_colr(&light);
   plabel(20);
   pset_pick_id(3);
   pexec_struct(STRUCT_OBJECT);
   plabel(30);
   pclose_struct();

   popen_struct(STRUCT_MAIN);
   pset_global_tran3(scale3);
   pset_hlhsr_id(PHIGS_HLHSR_ID_ON);
   padd_names_set(&names_view_1);
   pset_view_ind(1);
   pexec_struct(STRUCT_SCENE);
   premove_names_set(&names_view_1);
   padd_names_set(&names_view_2);
   pset_view_ind(2);
   pexec_struct(STRUCT_SCENE);
   premove_names_set(&names_view_2);
   padd_names_set(&names_view_3);
   pset_view_ind(3);
   pexec_struct(STRUCT_SCENE);
   premove_names_set(&names_view_3);
   padd_names_set(&names_view_3);
   pset_view_ind(4);
   pexec_struct(STRUCT_SCENE);
   premove_names_set(&names_view_4);
   pclose_struct();

   popen_struct(STRUCT_BORDER);
   pexec_struct(STRUCT_MAIN);
   pset_line_colr(&white);
   ppolyline(&plist_vline);
   ppolyline(&plist_hline);
   pclose_struct();
}

void print_event(XEvent *event)
{
    printf("%-2d: ", event->type);
    phg_sin_evt_print(event);
    printf("\tWindow = %x\n", (unsigned) event->xany.window);
}

void init_locator(Pint ws_id, Pint dev_id, Pop_mode mode, Pecho_switch echo)
{
   Plimit3 echo_volume = {0.0, 500.0, 0.0, 500.0, 0.0, 1.0};
   Ppoint3 init_pos = {0.0, 0.0, 0.0};
   Ploc_data3 rec;
   rec.pets.pet_r1.unused = 0;

   pinit_loc3(ws_id, dev_id, 0, &init_pos, 1, &echo_volume, &rec);
   pset_loc_mode(ws_id, dev_id, mode, echo);
}

void init_stroke(Pint ws_id, Pint dev_id, Pop_mode mode, Pecho_switch echo)
{
   Plimit3 echo_volume = {0.0, 500.0, 0.0, 500.0, 0.0, 1.0};
   Ppoint3 pt[1] = {{0.0, 0.0, 0.0}};
   Ppoint_list3 init_stk = {1, pt};
   Pstroke_data3 rec;
   rec.buffer_size = 100;
   rec.init_pos = 1;
   rec.pets.pet_r1.unused = 0;

   pinit_stroke3(ws_id, dev_id, 0, &init_stk, 1, &echo_volume, &rec);
   pset_stroke_mode(ws_id, dev_id, mode, echo);
}

void init_pick(Pint ws_id, Pint dev_id, Pop_mode mode, Pecho_switch echo)
{
   Pfilter pick_filter;
   Plimit3 echo_volume = {0.0, 500.0, 0.0, 500.0, 0.0, 1.0};
   Ppick_path_elem plist[1] = {{0, 0, 0}};
   Ppick_path pik = {1, plist};
   Ppick_data3 rec;
   rec.pets.pet_r1.unused = 0;
   pick_filter.incl_set = pick_incl;
   pick_filter.excl_set = pick_excl;

   pinit_pick3(ws_id, dev_id, PIN_STATUS_OK, &pik, 1, &echo_volume,
               &rec, PORDER_TOP_FIRST);
   pset_pick_filter(ws_id, dev_id, &pick_filter);
   pset_pick_mode(ws_id, dev_id, mode, echo);
}

void sample_locator(Pint ws_id, Pint dev_num)
{
   Pint view_ind;
   Ppoint3 loc_pos;

   psample_loc3(ws_id, dev_num, &view_ind, &loc_pos);
   printf("Sample locator #%-2d:\t[%f, %f, %f]\n",
          view_ind,
          loc_pos.x,
          loc_pos.y,
          loc_pos.z);
}

void sample_stroke(Pint ws_id, Pint dev_num)
{
   int i;
   Pint view_ind;

   psample_stroke3(ws_id, dev_num, &view_ind, &stroke);
   printf("Sample stroke #%-2d:\n", view_ind);
   for (i = 0; i < stroke.num_points; i++) {
      printf("\t[%f, %f, %f]\n",
             stroke.points[i].x,
             stroke.points[i].y,
             stroke.points[i].z);
   }
}

void sample_pick(Pint ws_id, Pint dev_num)
{
   int i;
   Pin_status status;

   psample_pick(ws_id, dev_num, 10, &status, &pick);
   if (status == PIN_STATUS_OK) {
      printf("Sample pick #%-d:\n", pick.depth);
      for (i = 0; i < pick.depth; i++) {
         printf("\tStruct: %d\tOffset: %d\tPick ID: %d\n",
                pick.path_list[i].struct_id,
                pick.path_list[i].elem_pos,
                pick.path_list[i].pick_id);
      }
   }
}

int locator_event(void)
{
   int ret;
   Pin_class class;
   Pint ws_id, in_num, view_ind;
   Ppoint3 loc_pos;

   pawait_event(0.1, &ws_id, &class, &in_num);
   if (class != PIN_NONE) {
      pget_loc3(&view_ind, &loc_pos);
      printf("#%-2d Locator event #%-2d:\t[%f, %f, %f]\n",
             ws_id,
             view_ind,
             loc_pos.x,
             loc_pos.y,
             loc_pos.z);
      ret = TRUE;
   }
   else {
      ret = FALSE;
   }

   return ret;
}

int stroke_event(void)
{
   int i, ret;
   Pin_class class;
   Pint ws_id, in_num, view_ind;

   pawait_event(0.1, &ws_id, &class, &in_num);
   if (class != PIN_NONE) {
      pget_stroke3(&view_ind, &stroke);
      printf("#%-2d Stroke event #%-2d:\n", ws_id, view_ind);
      for (i = 0; i < stroke.num_points; i++) {
         printf("\t[%f, %f, %f]\n",
                stroke.points[i].x,
                stroke.points[i].y,
                stroke.points[i].z);
      }
      ret = TRUE;
   }
   else {
      ret = FALSE;
   }

   return ret;
}

int pick_event(void)
{
   int i, ret;
   Pin_class class;
   Pint ws_id, in_num;
   Pin_status status;
   Ppick_path_elem path_list[10];
   Ppick_path pick = {0, path_list};

   pawait_event(0.1, &ws_id, &class, &in_num);
   if (class != PIN_NONE) {
      pget_pick(10, &status, &pick);
      if (status == PIN_STATUS_OK) {
         printf("#%-2d Pick event #%-2d:\n", ws_id, pick.depth);
         for (i = 0; i < pick.depth; i++) {
            printf("\tStruct: %d\tOffset: %d\tPick ID: %d\n",
                   pick.path_list[i].struct_id,
                   pick.path_list[i].elem_pos,
                   pick.path_list[i].pick_id);
         }
         ret = TRUE;
      }
      else {
         ret = FALSE;
      }
   }
   else {
      ret = FALSE;
   }

   return ret;
}

int locator_request(Pint ws_id, Pint dev_num)
{
   Ppoint3 pos;
   Pint view_ind;
   Pin_status in_status;
   int status;

   preq_loc3(ws_id, dev_num, &in_status, &view_ind, &pos);
   if (in_status == PIN_STATUS_OK) {
      printf("Locator request #%-2d:\t[%f, %f, %f]\n",
             view_ind,
             pos.x,
             pos.y,
             pos.z);
      status = TRUE;
   }
   else {
      status = FALSE;
   }

   return status;
}

int stroke_request(Pint ws_id, Pint dev_num)
{
   Pint i;
   Pint view_ind;
   Pin_status in_status;
   int status;

   preq_stroke3(ws_id, dev_num, &in_status, &view_ind, &stroke);
   if (in_status == PIN_STATUS_OK) {
      printf("Stroke request #%-2d:\n", view_ind);
      for (i = 0; i < stroke.num_points; i++) {
         printf("\t[%f, %f, %f]\n",
                stroke.points[i].x,
                stroke.points[i].y,
                stroke.points[i].z);
      }
      status = TRUE;
   }
   else {
      status = FALSE;
   }

   return status;
}
void print_size(Pint ws_type)
{
   Pint err_ind;
   Pdisp_space_size3 size;

   pinq_disp_space_size3(ws_type, &err_ind, &size);
   if (err_ind == 0) {
      printf("Display device size:\t%f x %f x %f\n",
             size.size_dc.size_x,
             size.size_dc.size_y,
             size.size_dc.size_z);
      printf("Display raster size:\t%d x %d x %d\n",
             size.size_raster.size_x,
             size.size_raster.size_y,
             size.size_raster.size_z);
   }
   else {
      ERR_REPORT(PHG_ERH, err_ind);
   }
}

int main(void)
{
   Pfilter invis_filter;
   Ws *wsh1;
   XEvent event;
   int redraw1 = 0;

   invis_filter.incl_set = pick_excl;
   invis_filter.excl_set = pick_incl;
   popen_phigs(NULL, 0);
   init_scene();
   print_size(PWST_OUTIN_TRUE_DB);

   popen_ws(WS_1, NULL, PWST_OUTIN_TRUE_DB);

   pset_ws_win(WS_1, &win);
   pset_invis_filter(WS_1, &invis_filter);
   pset_hlhsr_mode(WS_1, PHIGS_HLHSR_MODE_ZBUFF);
   pset_view_tran_in_pri(WS_1, 0, 4, PPRI_LOWER);
   ppost_struct(WS_1, STRUCT_BORDER, 0);
   wsh1 = PHG_WSID(WS_1);

   if (wsh1 != NULL) {

      XSelectInput(wsh1->display, wsh1->drawable_id, ExposureMask);

      init_pick(WS_1, 1, POP_EVENT, PSWITCH_NO_ECHO);

      while (1) {
         if (XCheckWindowEvent(wsh1->display,
                               wsh1->drawable_id,
                               (unsigned long) 0xffffffffUL,
                               &event) == True) {
#if 0
            print_event(&event);
#endif
            if (event.type == Expose) {
               while (XCheckTypedEvent(wsh1->display, Expose, &event));
               redraw1 = 1;
            }
         }
         pick_event();

         if (redraw1) {
            predraw_all_structs(WS_1, PFLAG_ALWAYS);
            redraw1 = 0;
         }
      }
   }

   pclose_ws(WS_1);
   pclose_phigs();

   return 1;
}

