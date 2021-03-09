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
#include <sys/types.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/css.h>

#define WIDTH   0.8
#define HEIGHT  0.8
#define SPACE   0.9
#define DEPTH  -0.2
#define LOW     0.2

#define FILL_STYLE PSTYLE_SOLID
#define FILL_STYLE_IND 4
#define EDGE_WIDTH 2.0

#define VP_X0    0.0
#define VP_X1  500.0
#define VP_Y0    0.0
#define VP_Y1  500.0
#define WIN_X0   0.0
#define WIN_X1   1.0
#define WIN_Y0   0.0
#define WIN_Y1   1.0

Ppoint3 pts_quad[] = {
   {0.0, 0.0, 0.0},
   {WIDTH, 0.0, 0.0},
   {WIDTH, HEIGHT, 0.0},
   {0.0, HEIGHT, 0.0}
};

Ppoint_list3 plist_quad = {
   4, pts_quad
};

Pint errnum;
Pvec3 tvec3;
Pmatrix3 tran3;
Pmatrix3 rot3;
int view_index = 5;
Pcolr_rep col_rep;
Pgcolr green, yellow;

void struct_content(Pint struct_id, Pint elmt_num)
{
   Pint i, num_longs;
   Phg_ret ret;
   caddr_t data;

   ret.err = 0;
   phg_css_inq_el_type_size(PHG_CSS, struct_id, elmt_num, &ret);
   if (!ret.err) {
      num_longs = ret.data.el_type_size.size / 4;
      css_print_eltype(ret.data.el_type_size.type);
      printf("\t\t\tSIZE: %d\n", ret.data.el_type_size.size);
   }
   else {
      num_longs = 0;
      printf("Error %d\n", ret.err);
   }

   ret.err = 0;
   phg_css_inq_el_content(PHG_CSS, struct_id, elmt_num, &ret);
   if (!ret.err) {
      data = (caddr_t) ret.data.el_info.el_head + 4;
      printf("-------------------------------------------------------------\n");
      for (i = 0; i < num_longs; i++) {
         printf("%08x:\tINTEGER: %d\n"
                "\t\t\t\t\tFLOAT: %f\n",
                i, *((int *) data), *((float *) data));
         data += 4;
      }
   }
   else {
      printf("Error: %d\n", ret.err);
   }
   printf("\n");
}

void struct_stat(void)
{
   Pint index, err;
   Popen_struct_status status;

   pinq_open_struct(&err, &status, &index);
   if (!err && status == PSTRUCT_OPEN)
      printf("Open structure id: %d\n", index);
   else
      printf("No structure open\n");

   pinq_elem_ptr(&err, &index);
   if (!err)
      printf("Label found at: %d\n", index);
   else
      printf("Label not found\n");

#if 0
   printf("\n");
   struct_content(0, 1);
   struct_content(1, 1);
   struct_content(1, 5);
   struct_content(1, 13);
#endif
}

int main(int argc, char *argv[])
{
   XEvent event;
   KeySym ks;
   Plimit3 vp, win;

   if (argc > 1) {
      view_index = atoi(argv[1]);
      printf("Use view: %d\n", view_index);
   }

   green.type = PMODEL_RGB;
   green.val.general.x = 0.0;
   green.val.general.y = 1.0;
   green.val.general.z = 0.0;

   yellow.type = PMODEL_RGB;
   yellow.val.general.x = 1.0;
   yellow.val.general.y = 1.0;
   yellow.val.general.z = 0.0;

   popen_phigs(NULL, 0);

   popen_struct(0);
   pfill_area3(&plist_quad);
   ppolymarker3(&plist_quad);
   pclose_struct();

   tvec3.delta_x = 0.0;
   tvec3.delta_y = 0.0;
   tvec3.delta_z = DEPTH;
   ptranslate3(&tvec3, &errnum, tran3);
   protate_x(-3.14 / 4.0, &errnum, rot3);

   popen_struct(1);
   pset_view_ind(view_index);
   pset_hlhsr_id(PHIGS_HLHSR_ID_ON);
   pset_edge_flag(PEDGE_ON);
   pset_edge_colr_ind(3);
   pset_edgewidth(EDGE_WIDTH);
   pset_edgetype(PLINE_SOLID);
   pset_int_colr_ind(0);
   pset_int_style(FILL_STYLE);
   pset_int_style_ind(FILL_STYLE_IND);
   pset_marker_type(PMARKER_CROSS);
   pset_marker_size(0.1);
   pset_marker_colr_ind(4);
   pset_local_tran3(tran3, PTYPE_REPLACE);
   pexec_struct(0);
   tvec3.delta_z += SPACE;
   ptranslate3(&tvec3, &errnum, tran3);
   pset_local_tran3(rot3, PTYPE_REPLACE);
   pset_local_tran3(tran3, PTYPE_POSTCONCAT);
   pset_int_colr_ind(1);
   pexec_struct(0);
   tvec3.delta_z += SPACE;
   ptranslate3(&tvec3, &errnum, tran3);
   pset_local_tran3(rot3, PTYPE_REPLACE);
   pset_local_tran3(rot3, PTYPE_POSTCONCAT);
   plabel(10);
   pset_local_tran3(tran3, PTYPE_POSTCONCAT);
   pset_int_colr_ind(2);
   plabel(20);
   pexec_struct(0);
   plabel(30);
   pclose_struct();

   popen_ws(0, NULL, PWST_OUTPUT_TRUE_DB);
   vp.x_min = VP_X0;
   vp.x_max = VP_X1;
   vp.y_min = VP_Y0;
   vp.y_max = VP_Y1;
   vp.z_min = 0.0;
   vp.z_max = 1.0;
   win.x_min = WIN_X0;
   win.x_max = WIN_X1;
   win.y_min = WIN_Y0;
   win.y_max = WIN_Y1;
   win.z_min = 0.0;
   win.z_max = 1.0;
   pset_ws_vp3(0, &vp);
   pset_ws_win3(0, &win);
   pset_hlhsr_mode(0, PHIGS_HLHSR_MODE_ZBUFF);

   col_rep.rgb.red = 0.0;
   col_rep.rgb.green = 0.25;
   col_rep.rgb.blue = 0.25;
   pset_colr_rep(0, 0, &col_rep);

   col_rep.rgb.red = 0.0;
   col_rep.rgb.green = 0.5;
   col_rep.rgb.blue = 0.5;
   pset_colr_rep(0, 1, &col_rep);

   col_rep.rgb.red = 0.0;
   col_rep.rgb.green = 1.0;
   col_rep.rgb.blue = 1.0;
   pset_colr_rep(0, 2, &col_rep);

   col_rep.rgb.red = 1.0;
   col_rep.rgb.green = 1.0;
   col_rep.rgb.blue = 1.0;
   pset_colr_rep(0, 3, &col_rep);

   col_rep.rgb.red = 1.0;
   col_rep.rgb.green = 0.0;
   col_rep.rgb.blue = 0.0;
   pset_colr_rep(0, 4, &col_rep);
   pset_disp_upd_st(0, PDEFER_BNIL, PMODE_UQUM);

   ppost_struct(0, 1, 0);
   pupd_ws(0, PFLAG_PERFORM);

   XSelectInput(PHG_WSID(0)->display,
                PHG_WSID(0)->drawable_id,
                ExposureMask | KeyPressMask);
   while (1) {
      XNextEvent(PHG_WSID(0)->display, &event);
      switch(event.type) {

         case Expose:
            while (XCheckTypedEvent(PHG_WSID(0)->display, Expose, &event));
            predraw_all_structs(0, PFLAG_ALWAYS);
            break;

         case KeyPress:
            ks = XLookupKeysym((XKeyEvent *) &event, 0);
            if (ks == XK_Down) {
               punpost_struct(0, 1);
               pupd_ws(0, PFLAG_PERFORM);
            }
            else if (ks == XK_Up) {
               ppost_struct(0, 1, 0);
               pupd_ws(0, PFLAG_PERFORM);
            }
            else if (ks == XK_Left) {
               punpost_all_structs(0);
               pupd_ws(0, PFLAG_PERFORM);
            }
            else {
               popen_struct(1);
               tvec3.delta_y = -LOW;
               ptranslate3(&tvec3, &errnum, tran3);
               pset_elem_ptr(0);
               pset_elem_ptr_label(10);
               struct_stat();
               pset_edit_mode(PEDIT_REPLACE);
               poffset_elem_ptr(1);
               pset_local_tran3(tran3, PTYPE_POSTCONCAT);
               poffset_elem_ptr(1);
               pset_int_colr_ind(4);
#if 0
               pset_elem_ptr(0);
               //pdel_elem_range(19, 20);
               pdel_elems_labels(10, 20);
               pset_edit_mode(PEDIT_INSERT);
#endif
               pset_elem_ptr(0);
               pset_elem_ptr_label(30);
               pset_edit_mode(PEDIT_INSERT);
               tvec3.delta_x = -SPACE;
               tvec3.delta_y = 0.0;
               tvec3.delta_z = DEPTH;
               ptranslate3(&tvec3, &errnum, tran3);
               pset_local_tran3(tran3, PTYPE_REPLACE);
               //pset_hlhsr_id(PHIGS_HLHSR_ID_OFF);
               pset_int_style(FILL_STYLE);
               pset_int_colr(&green);
               pset_edge_colr(&yellow);
               pcopy_all_elems_struct(0);
               pclose_struct();
            }
            break;

         default:
            break;
      }
   }

   pclose_ws(0);
   pclose_phigs();

   return 0;
}

