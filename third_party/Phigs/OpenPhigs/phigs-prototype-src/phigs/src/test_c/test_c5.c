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

#define INT_STYLE     PSTYLE_SOLID
#define EDGE_FLAG     PEDGE_ON

#define ANGLE_DELTA   0.1
#define WIDTH         1.0
#define HEIGHT        1.0
#define DEPTH         1.0
#define STRUCT_OBJECT   0
#define LABEL_TRANS    10

Pint errnum;
Pmatrix3 rot3, rotx, roty;
Pint view_ind = 5;
Pfloat angle_x = 0.0;
Pfloat angle_y = 0.0;
Pgcolr edge_colr;

void init_shape(void)
{
   Pptco3 vertex_data[5];
   Pfacet_data3 fdata;
   Pfacet_vdata_list3 vdata;

   /* Front */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].colr.direct.rgb.red = 1.0;
   vertex_data[0].colr.direct.rgb.green = 0.0;
   vertex_data[0].colr.direct.rgb.blue = 0.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = 0.0;
   vertex_data[1].colr.direct.rgb.red = 1.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 0.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = 0.0;
   vertex_data[2].colr.direct.rgb.red = 0.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 1.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = 0.0;
   vertex_data[3].colr.direct.rgb.red = 1.0;
   vertex_data[3].colr.direct.rgb.green = 0.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptcolrs = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Back */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = DEPTH;
   vertex_data[0].colr.direct.rgb.red = 1.0;
   vertex_data[0].colr.direct.rgb.green = 0.0;
   vertex_data[0].colr.direct.rgb.blue = 1.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = DEPTH;
   vertex_data[1].colr.direct.rgb.red = 0.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 1.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 1.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 0.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = DEPTH;
   vertex_data[3].colr.direct.rgb.red = 0.0;
   vertex_data[3].colr.direct.rgb.green = 1.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptcolrs = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Bottom */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].colr.direct.rgb.red = 1.0;
   vertex_data[0].colr.direct.rgb.green = 0.0;
   vertex_data[0].colr.direct.rgb.blue = 0.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = 0.0;
   vertex_data[1].colr.direct.rgb.red = 1.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 0.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = 0.0;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 0.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 1.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = 0.0;
   vertex_data[3].point.z = DEPTH;
   vertex_data[3].colr.direct.rgb.red = 1.0;
   vertex_data[3].colr.direct.rgb.green = 0.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptcolrs = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Top */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = HEIGHT;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].colr.direct.rgb.red = 1.0;
   vertex_data[0].colr.direct.rgb.green = 0.0;
   vertex_data[0].colr.direct.rgb.blue = 1.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = HEIGHT;
   vertex_data[1].point.z = 0.0;
   vertex_data[1].colr.direct.rgb.red = 0.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 1.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 1.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 0.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = DEPTH;
   vertex_data[3].colr.direct.rgb.red = 0.0;
   vertex_data[3].colr.direct.rgb.green = 1.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptcolrs = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Left */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].colr.direct.rgb.red = 1.0;
   vertex_data[0].colr.direct.rgb.green = 0.0;
   vertex_data[0].colr.direct.rgb.blue = 0.0;

   vertex_data[1].point.x = 0.0;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = DEPTH;
   vertex_data[1].colr.direct.rgb.red = 1.0;
   vertex_data[1].colr.direct.rgb.green = 0.0;
   vertex_data[1].colr.direct.rgb.blue = 1.0;

   vertex_data[2].point.x = 0.0;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 0.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 1.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = 0.0;
   vertex_data[3].colr.direct.rgb.red = 1.0;
   vertex_data[3].colr.direct.rgb.green = 0.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptcolrs = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Right */
   vertex_data[0].point.x = WIDTH;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].colr.direct.rgb.red = 1.0;
   vertex_data[0].colr.direct.rgb.green = 1.0;
   vertex_data[0].colr.direct.rgb.blue = 0.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = DEPTH;
   vertex_data[1].colr.direct.rgb.red = 0.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 1.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 1.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 0.0;

   vertex_data[3].point.x = WIDTH;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = 0.0;
   vertex_data[3].colr.direct.rgb.red = 0.0;
   vertex_data[3].colr.direct.rgb.green = 1.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptcolrs = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);
}

int main(int argc, char *argv[])
{
   XEvent event;
   KeySym ks;

   if (argc > 1) {
      view_ind = atoi(argv[1]);
      printf("Use view: %d\n", view_ind);
   }

   edge_colr.type = PMODEL_RGB;
   edge_colr.val.general.x = 0.0;
   edge_colr.val.general.y = 0.0;
   edge_colr.val.general.z = 1.0;

   popen_phigs(NULL, 0);
   phg_mat_identity(rot3);

   popen_struct(STRUCT_OBJECT);
   pset_hlhsr_id(PHIGS_HLHSR_ID_ON);
   pset_view_ind(view_ind);
   pset_edge_flag(EDGE_FLAG);
   pset_edge_colr(&edge_colr);
   pset_int_style(INT_STYLE);
   pset_int_shad_meth(PSD_COLOUR);
   pset_face_disting_mode(PDISTING_NO);
   plabel(LABEL_TRANS);
   pset_local_tran3(rot3, PTYPE_REPLACE);
   init_shape();
   pclose_struct();

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

