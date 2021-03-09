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
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/css.h>

#define ANGLE_DELTA   0.1
#define WIDTH         1.0
#define HEIGHT        1.0
#define DEPTH         1.0
#define STRUCT_OBJECT   0
#define LABEL_TRANS    10

#define FILL_STYLE PSTYLE_SOLID
#define FILL_STYLE_IND 4
#define EDGE_WIDTH 1.0

Ppoint3 pts_cube[] = {
   /* Front */
   {0.0, 0.0, 0.0},
   {WIDTH, 0.0, 0.0},
   {WIDTH, HEIGHT, 0.0},
   {0.0, HEIGHT, 0.0},

   /* Back */
   {0.0, 0.0, DEPTH},
   {WIDTH, 0.0, DEPTH},
   {WIDTH, HEIGHT, DEPTH},
   {0.0, HEIGHT, DEPTH},

   /* Bottom */
   {0.0, 0.0, 0.0},
   {WIDTH, 0.0, 0.0},
   {WIDTH, 0.0, DEPTH},
   {0.0, 0.0, DEPTH},

   /* Top */
   {0.0, HEIGHT, 0.0},
   {WIDTH, HEIGHT, 0.0},
   {WIDTH, HEIGHT, DEPTH},
   {0.0, HEIGHT, DEPTH},

   /* Left */
   {0.0, 0.0, 0.0},
   {0.0, 0.0, DEPTH},
   {0.0, HEIGHT, DEPTH},
   {0.0, HEIGHT, 0.0},

   /* Right */
   {WIDTH, 0.0, 0.0},
   {WIDTH, 0.0, DEPTH},
   {WIDTH, HEIGHT, DEPTH},
   {WIDTH, HEIGHT, 0.0}
};

Ppoint_list3 plist_cube[] = {
   {4, &pts_cube[0]},
   {4, &pts_cube[4]},
   {4, &pts_cube[8]},
   {4, &pts_cube[12]},
   {4, &pts_cube[16]},
   {4, &pts_cube[20]}
};

Ppoint_list_list3 shape = {
   6, plist_cube
};

Pint errnum;
Pmatrix3 rot3, rotx, roty;
Pint view_ind = 5;
Pfloat angle_x = 0.0;
Pfloat angle_y = 0.0;
Pgcolr blue;

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

int main(int argc, char *argv[])
{
   XEvent event;
   KeySym ks;

   if (argc > 1) {
      view_ind = atoi(argv[1]);
      printf("Use view: %d\n", view_ind);
   }

   blue.type = PMODEL_RGB;
   blue.val.general.x = 0.0;
   blue.val.general.y = 0.0;
   blue.val.general.z = 1.0;

   popen_phigs(NULL, 0);
   phg_mat_identity(rot3);

   popen_struct(STRUCT_OBJECT);
   pset_hlhsr_id(PHIGS_HLHSR_ID_ON);
   pset_view_ind(view_ind);
   pset_edge_flag(PEDGE_ON);
   pset_edgewidth(EDGE_WIDTH);
   pset_int_colr(&blue);
   pset_int_style(FILL_STYLE);
   pset_int_style_ind(FILL_STYLE_IND);
   plabel(LABEL_TRANS);
   pset_local_tran3(rot3, PTYPE_REPLACE);
   pfill_area_set3(&shape);
   pclose_struct();

   //struct_content(STRUCT_OBJECT, 7);

   popen_ws(0, NULL, PWST_OUTPUT_TRUE_DB);
   pset_hlhsr_mode(0, PHIGS_HLHSR_MODE_ZBUFF);
   pset_disp_upd_st(0, PDEFER_BNIL, PMODE_UQUM);
   ppost_struct(0, STRUCT_OBJECT, 0);
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
            if (ks == XK_Up) {
               angle_x -= ANGLE_DELTA;
            }
            else if (ks == XK_Down) {
               angle_x += ANGLE_DELTA;
            }
            else if (ks == XK_Left) {
               angle_y -= ANGLE_DELTA;
            }
            else if (ks == XK_Right) {
               angle_y += ANGLE_DELTA;
            }
            protate_x(angle_x * 3.14 / 2.0, &errnum, rotx);
            protate_y(angle_y * 3.14 / 2.0, &errnum, roty);
            pcompose_matrix3(rotx, roty, &errnum, rot3);
            popen_struct(STRUCT_OBJECT);
            pset_elem_ptr(0);
            pset_elem_ptr_label(LABEL_TRANS);
            pset_edit_mode(PEDIT_REPLACE);
            poffset_elem_ptr(1);
            pset_local_tran3(rot3, PTYPE_REPLACE);
            pclose_struct();
            pupd_ws(0, PFLAG_PERFORM);
            break;

         default:
            break;
      }
   }

   pclose_ws(0);
   pclose_phigs();

   return 0;
}

