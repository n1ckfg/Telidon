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
#define INT_STYLE      PSTYLE_SOLID
#define EDGE_FLAG      PEDGE_ON
#define HLHSR_FLAG     PHIGS_HLHSR_ID_ON
#define INIT_SHAPE     init_shape_pfill_area3
#define CULL_MODE      PCULL_NONE
#define DISTING_MODE   PDISTING_YES
#define BACK_INT_STYLE PSTYLE_HATCH
#define BACK_STYLE_IND 6
#define SHAD_METH      PSD_COLOUR
#define BACK_SHAD_METH PSD_NONE
#define REFL_EQN       PREFL_AMB_DIFF
#define BACK_REFL_EQN  PREFL_AMBIENT


Pint errnum;
Pmatrix3 rot3, rotx, roty;
Pint view_ind = 5;
Pfloat angle_x = 0.0;
Pfloat angle_y = 0.0;
Pgcolr edge_colr;
Pgcolr int_colr;
Pgcolr back_int_colr;
Pint lights_on[] = {1, 2};
Pint light_off[] = {0};
Pint_list lights_on_list = {2, lights_on};
Pint_list lights_off_list = {0, light_off};
Prefl_props refl_props;

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

void setup_light(Pint ws_id)
{
   Plight_src_bundle light;

   light.type = PLIGHT_AMBIENT;
   light.rec.ambient.colr.val.general.x = 0.2;
   light.rec.ambient.colr.val.general.y = 0.2;
   light.rec.ambient.colr.val.general.z = 0.2;

   pset_light_src_rep(ws_id, 1, &light);

   light.type = PLIGHT_DIRECTIONAL;
   light.rec.directional.colr.val.general.x = 1.0;
   light.rec.directional.colr.val.general.y = 1.0;
   light.rec.directional.colr.val.general.z = 1.0;
   light.rec.directional.dir.delta_x = 1/sqrt(3.0);
   light.rec.directional.dir.delta_y = 1/sqrt(3.0);
   light.rec.directional.dir.delta_z = 1/sqrt(3.0);

   pset_light_src_rep(ws_id, 2, &light);
}

void init_shape_pfill_area3(void)
{
   Ppoint3 vertex_data[4];
   Ppoint_list3 point_list;

   point_list.num_points = 4;
   point_list.points = vertex_data;

   /* Back */
   vertex_data[0].x = 0.0;
   vertex_data[0].y = HEIGHT;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = HEIGHT;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = 0.0;
   vertex_data[2].z = 0.0;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = 0.0;
   vertex_data[3].z = 0.0;

   pfill_area3(&point_list);

   /* Front */
   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = DEPTH;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = DEPTH;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = DEPTH;

   pfill_area3(&point_list);

   /* Bottom */
   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = 0.0;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = 0.0;
   vertex_data[3].z = DEPTH;

   pfill_area3(&point_list);

   /* Top */
   vertex_data[0].x = WIDTH;
   vertex_data[0].y = HEIGHT;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = 0.0;
   vertex_data[1].y = HEIGHT;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = 0.0;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = WIDTH;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = DEPTH;

   pfill_area3(&point_list);

   /* Left */
   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = 0.0;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = DEPTH;

   vertex_data[2].x = 0.0;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = 0.0;

   pfill_area3(&point_list);

   /* Right */
   vertex_data[0].x = WIDTH;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = DEPTH;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = 0.0;

   vertex_data[3].x = WIDTH;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = DEPTH;

   //pfill_area3(&point_list);
}

void init_shape_no_norm(void)
{
   Ppoint3 vertex_data[5];
   Pfacet_data3 fdata;
   Pfacet_vdata_list3 vdata;

   fdata.colr.direct.rgb.red = 0.0;
   fdata.colr.direct.rgb.green = 1.0;
   fdata.colr.direct.rgb.blue = 1.0;

   /* Back */
   vertex_data[0].x = 0.0;
   vertex_data[0].y = HEIGHT;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = HEIGHT;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = 0.0;
   vertex_data[2].z = 0.0;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = 0.0;
   vertex_data[3].z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Front */
   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = DEPTH;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = DEPTH;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = DEPTH;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Bottom */
   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = 0.0;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = 0.0;
   vertex_data[3].z = DEPTH;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Top */
   vertex_data[0].x = WIDTH;
   vertex_data[0].y = HEIGHT;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = 0.0;
   vertex_data[1].y = HEIGHT;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = 0.0;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = WIDTH;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = DEPTH;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Left */
   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = 0.0;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = DEPTH;

   vertex_data[2].x = 0.0;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Right */
   vertex_data[0].x = WIDTH;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = DEPTH;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = 0.0;

   vertex_data[3].x = WIDTH;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = DEPTH;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);
}

void init_shape_norm_per_facet(void)
{
   Ppoint3 vertex_data[5];
   Pfacet_data3 fdata;
   Pfacet_vdata_list3 vdata;

   fdata.conorm.colr.direct.rgb.red = 0.0;
   fdata.conorm.colr.direct.rgb.green = 1.0;
   fdata.conorm.colr.direct.rgb.blue = 1.0;

   /* Back */
   fdata.conorm.norm.delta_x = 0.0;
   fdata.conorm.norm.delta_y = 0.0;
   fdata.conorm.norm.delta_z = -1.0;

   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = 0.0;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Front */
   fdata.conorm.norm.delta_x = 0.0;
   fdata.conorm.norm.delta_y = 0.0;
   fdata.conorm.norm.delta_z = 1.0;

   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = DEPTH;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = DEPTH;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = DEPTH;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Bottom */
   fdata.conorm.norm.delta_x = 0.0;
   fdata.conorm.norm.delta_y = -1.0;
   fdata.conorm.norm.delta_z = 0.0;

   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = 0.0;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = 0.0;
   vertex_data[3].z = DEPTH;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Top */
   fdata.conorm.norm.delta_x = 0.0;
   fdata.conorm.norm.delta_y = 1.0;
   fdata.conorm.norm.delta_z = 0.0;

   vertex_data[0].x = 0.0;
   vertex_data[0].y = HEIGHT;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = HEIGHT;
   vertex_data[1].z = 0.0;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = DEPTH;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Left */
   fdata.conorm.norm.delta_x = -1.0;
   fdata.conorm.norm.delta_y = 0.0;
   fdata.conorm.norm.delta_z = 0.0;

   vertex_data[0].x = 0.0;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = 0.0;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = DEPTH;

   vertex_data[2].x = 0.0;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = 0.0;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Right */
   fdata.conorm.norm.delta_x = 1.0;
   fdata.conorm.norm.delta_y = 0.0;
   fdata.conorm.norm.delta_z = 0.0;

   vertex_data[0].x = WIDTH;
   vertex_data[0].y = 0.0;
   vertex_data[0].z = 0.0;

   vertex_data[1].x = WIDTH;
   vertex_data[1].y = 0.0;
   vertex_data[1].z = DEPTH;

   vertex_data[2].x = WIDTH;
   vertex_data[2].y = HEIGHT;
   vertex_data[2].z = DEPTH;

   vertex_data[3].x = WIDTH;
   vertex_data[3].y = HEIGHT;
   vertex_data[3].z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.points = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);
}

void init_shape_norm_per_vertex(void)
{
   Pptnorm3 vertex_data[5];
   Pfacet_data3 fdata;
   Pfacet_vdata_list3 vdata;

   fdata.colr.direct.rgb.red = 0.0;
   fdata.colr.direct.rgb.green = 1.0;
   fdata.colr.direct.rgb.blue = 1.0;

   /* Back */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].norm.delta_x = 0.0;
   vertex_data[0].norm.delta_y = 0.0;
   vertex_data[0].norm.delta_z = -1.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = 0.0;
   vertex_data[1].norm.delta_x = 0.0;
   vertex_data[1].norm.delta_y = 0.0;
   vertex_data[1].norm.delta_z = -1.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = 0.0;
   vertex_data[2].norm.delta_x = 0.0;
   vertex_data[2].norm.delta_y = 0.0;
   vertex_data[2].norm.delta_z = -1.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = 0.0;
   vertex_data[3].norm.delta_x = 0.0;
   vertex_data[3].norm.delta_y = 0.0;
   vertex_data[3].norm.delta_z = -1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptnorms = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD_NORMAL,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Front */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = DEPTH;
   vertex_data[0].norm.delta_x = 0.0;
   vertex_data[0].norm.delta_y = 0.0;
   vertex_data[0].norm.delta_z = 1.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = DEPTH;
   vertex_data[1].norm.delta_x = 0.0;
   vertex_data[1].norm.delta_y = 0.0;
   vertex_data[1].norm.delta_z = 1.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].norm.delta_x = 0.0;
   vertex_data[2].norm.delta_y = 0.0;
   vertex_data[2].norm.delta_z = 1.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = DEPTH;
   vertex_data[3].norm.delta_x = 0.0;
   vertex_data[3].norm.delta_y = 0.0;
   vertex_data[3].norm.delta_z = 1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptnorms = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD_NORMAL,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Bottom */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].norm.delta_x = 0.0;
   vertex_data[0].norm.delta_y = -1.0;
   vertex_data[0].norm.delta_z = 0.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = 0.0;
   vertex_data[1].norm.delta_x = 0.0;
   vertex_data[1].norm.delta_y = -1.0;
   vertex_data[1].norm.delta_z = 0.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = 0.0;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].norm.delta_x = 0.0;
   vertex_data[2].norm.delta_y = -1.0;
   vertex_data[2].norm.delta_z = 0.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = 0.0;
   vertex_data[3].point.z = DEPTH;
   vertex_data[3].norm.delta_x = 0.0;
   vertex_data[3].norm.delta_y = -1.0;
   vertex_data[3].norm.delta_z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptnorms = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD_NORMAL,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Top */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = HEIGHT;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].norm.delta_x = 0.0;
   vertex_data[0].norm.delta_y = 1.0;
   vertex_data[0].norm.delta_z = 0.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = HEIGHT;
   vertex_data[1].point.z = 0.0;
   vertex_data[1].norm.delta_x = 0.0;
   vertex_data[1].norm.delta_y = 1.0;
   vertex_data[1].norm.delta_z = 0.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].norm.delta_x = 0.0;
   vertex_data[2].norm.delta_y = 1.0;
   vertex_data[2].norm.delta_z = 0.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = DEPTH;
   vertex_data[3].norm.delta_x = 0.0;
   vertex_data[3].norm.delta_y = 1.0;
   vertex_data[3].norm.delta_z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptnorms = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD_NORMAL,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Left */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].norm.delta_x = -1.0;
   vertex_data[0].norm.delta_y = 0.0;
   vertex_data[0].norm.delta_z = 0.0;

   vertex_data[1].point.x = 0.0;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = DEPTH;
   vertex_data[1].norm.delta_x = -1.0;
   vertex_data[1].norm.delta_y = 0.0;
   vertex_data[1].norm.delta_z = 0.0;

   vertex_data[2].point.x = 0.0;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].norm.delta_x = -1.0;
   vertex_data[2].norm.delta_y = 0.0;
   vertex_data[2].norm.delta_z = 0.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = 0.0;
   vertex_data[3].norm.delta_x = -1.0;
   vertex_data[3].norm.delta_y = 0.0;
   vertex_data[3].norm.delta_z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptnorms = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD_NORMAL,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   vertex_data[0].point.x = WIDTH;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].norm.delta_x = 1.0;
   vertex_data[0].norm.delta_y = 0.0;
   vertex_data[0].norm.delta_z = 0.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = DEPTH;
   vertex_data[1].norm.delta_x = 1.0;
   vertex_data[1].norm.delta_y = 0.0;
   vertex_data[1].norm.delta_z = 0.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].norm.delta_x = 1.0;
   vertex_data[2].norm.delta_y = 0.0;
   vertex_data[2].norm.delta_z = 0.0;

   vertex_data[3].point.x = WIDTH;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = 0.0;
   vertex_data[3].norm.delta_x = 1.0;
   vertex_data[3].norm.delta_y = 0.0;
   vertex_data[3].norm.delta_z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptnorms = vertex_data;
   pfill_area_set3_data(PFACET_COLOUR,
                        PEDGE_NONE,
                        PVERT_COORD_NORMAL,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);
}

void init_shape_colour_norm_per_facet(void)
{
   Pptco3 vertex_data[5];
   Pfacet_data3 fdata;
   Pfacet_vdata_list3 vdata;

   /* Back */
   fdata.norm.delta_x = 0.0;
   fdata.norm.delta_y = 0.0;
   fdata.norm.delta_z = -1.0;

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
   pfill_area_set3_data(PFACET_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Front */
   fdata.norm.delta_x = 0.0;
   fdata.norm.delta_y = 0.0;
   fdata.norm.delta_z = 1.0;

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
   pfill_area_set3_data(PFACET_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Bottom */
   fdata.norm.delta_x = 0.0;
   fdata.norm.delta_y = -1.0;
   fdata.norm.delta_z = 0.0;

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
   pfill_area_set3_data(PFACET_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Top */
   fdata.norm.delta_x = 0.0;
   fdata.norm.delta_y = 1.0;
   fdata.norm.delta_z = 0.0;

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
   pfill_area_set3_data(PFACET_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Left */
   fdata.norm.delta_x = -1.0;
   fdata.norm.delta_y = 0.0;
   fdata.norm.delta_z = 0.0;

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
   pfill_area_set3_data(PFACET_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Right */
   fdata.norm.delta_x = 1.0;
   fdata.norm.delta_y = 0.0;
   fdata.norm.delta_z = 0.0;

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
   pfill_area_set3_data(PFACET_NORMAL,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);
}

void init_shape_colour_norm_per_vertex(void)
{
   Pptconorm3 vertex_data[5];
   Pfacet_data3 fdata;
   Pfacet_vdata_list3 vdata;

   /* Back */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = 0.0;
   vertex_data[0].colr.direct.rgb.red = 1.0;
   vertex_data[0].colr.direct.rgb.green = 0.0;
   vertex_data[0].colr.direct.rgb.blue = 0.0;
   vertex_data[0].norm.delta_x = 0.0;
   vertex_data[0].norm.delta_y = 0.0;
   vertex_data[0].norm.delta_z = -1.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = 0.0;
   vertex_data[1].colr.direct.rgb.red = 1.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 0.0;
   vertex_data[1].norm.delta_x = 0.0;
   vertex_data[1].norm.delta_y = 0.0;
   vertex_data[1].norm.delta_z = -1.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = 0.0;
   vertex_data[2].colr.direct.rgb.red = 0.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 1.0;
   vertex_data[2].norm.delta_x = 0.0;
   vertex_data[2].norm.delta_y = 0.0;
   vertex_data[2].norm.delta_z = -1.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = 0.0;
   vertex_data[3].colr.direct.rgb.red = 1.0;
   vertex_data[3].colr.direct.rgb.green = 0.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;
   vertex_data[3].norm.delta_x = 0.0;
   vertex_data[3].norm.delta_y = 0.0;
   vertex_data[3].norm.delta_z = -1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptconorms = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR_NORMAL,
                        PMODEL_RGB,
                        &fdata,
                        1,
                        NULL,
                        &vdata);

   /* Front */
   vertex_data[0].point.x = 0.0;
   vertex_data[0].point.y = 0.0;
   vertex_data[0].point.z = DEPTH;
   vertex_data[0].colr.direct.rgb.red = 1.0;
   vertex_data[0].colr.direct.rgb.green = 0.0;
   vertex_data[0].colr.direct.rgb.blue = 1.0;
   vertex_data[0].norm.delta_x = 0.0;
   vertex_data[0].norm.delta_y = 0.0;
   vertex_data[0].norm.delta_z = 1.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = DEPTH;
   vertex_data[1].colr.direct.rgb.red = 0.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 1.0;
   vertex_data[1].norm.delta_x = 0.0;
   vertex_data[1].norm.delta_y = 0.0;
   vertex_data[1].norm.delta_z = 1.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 1.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 0.0;
   vertex_data[2].norm.delta_x = 0.0;
   vertex_data[2].norm.delta_y = 0.0;
   vertex_data[2].norm.delta_z = 1.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = DEPTH;
   vertex_data[3].colr.direct.rgb.red = 0.0;
   vertex_data[3].colr.direct.rgb.green = 1.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;
   vertex_data[3].norm.delta_x = 0.0;
   vertex_data[3].norm.delta_y = 0.0;
   vertex_data[3].norm.delta_z = 1.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptconorms = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR_NORMAL,
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
   vertex_data[0].norm.delta_x = 0.0;
   vertex_data[0].norm.delta_y = -1.0;
   vertex_data[0].norm.delta_z = 0.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = 0.0;
   vertex_data[1].colr.direct.rgb.red = 1.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 0.0;
   vertex_data[1].norm.delta_x = 0.0;
   vertex_data[1].norm.delta_y = -1.0;
   vertex_data[1].norm.delta_z = 0.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = 0.0;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 0.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 1.0;
   vertex_data[2].norm.delta_x = 0.0;
   vertex_data[2].norm.delta_y = -1.0;
   vertex_data[2].norm.delta_z = 0.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = 0.0;
   vertex_data[3].point.z = DEPTH;
   vertex_data[3].colr.direct.rgb.red = 1.0;
   vertex_data[3].colr.direct.rgb.green = 0.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;
   vertex_data[3].norm.delta_x = 0.0;
   vertex_data[3].norm.delta_y = -1.0;
   vertex_data[3].norm.delta_z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptconorms = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR_NORMAL,
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
   vertex_data[0].norm.delta_x = 0.0;
   vertex_data[0].norm.delta_y = 1.0;
   vertex_data[0].norm.delta_z = 0.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = HEIGHT;
   vertex_data[1].point.z = 0.0;
   vertex_data[1].colr.direct.rgb.red = 0.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 1.0;
   vertex_data[1].norm.delta_x = 0.0;
   vertex_data[1].norm.delta_y = 1.0;
   vertex_data[1].norm.delta_z = 0.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 1.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 0.0;
   vertex_data[2].norm.delta_x = 0.0;
   vertex_data[2].norm.delta_y = 1.0;
   vertex_data[2].norm.delta_z = 0.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = DEPTH;
   vertex_data[3].colr.direct.rgb.red = 0.0;
   vertex_data[3].colr.direct.rgb.green = 1.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;
   vertex_data[3].norm.delta_x = 0.0;
   vertex_data[3].norm.delta_y = 1.0;
   vertex_data[3].norm.delta_z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptconorms = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR_NORMAL,
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
   vertex_data[0].norm.delta_x = -1.0;
   vertex_data[0].norm.delta_y = 0.0;
   vertex_data[0].norm.delta_z = 0.0;

   vertex_data[1].point.x = 0.0;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = DEPTH;
   vertex_data[1].colr.direct.rgb.red = 1.0;
   vertex_data[1].colr.direct.rgb.green = 0.0;
   vertex_data[1].colr.direct.rgb.blue = 1.0;
   vertex_data[1].norm.delta_x = -1.0;
   vertex_data[1].norm.delta_y = 0.0;
   vertex_data[1].norm.delta_z = 0.0;

   vertex_data[2].point.x = 0.0;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 0.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 1.0;
   vertex_data[2].norm.delta_x = -1.0;
   vertex_data[2].norm.delta_y = 0.0;
   vertex_data[2].norm.delta_z = 0.0;

   vertex_data[3].point.x = 0.0;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = 0.0;
   vertex_data[3].colr.direct.rgb.red = 1.0;
   vertex_data[3].colr.direct.rgb.green = 0.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;
   vertex_data[3].norm.delta_x = -1.0;
   vertex_data[3].norm.delta_y = 0.0;
   vertex_data[3].norm.delta_z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptconorms = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR_NORMAL,
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
   vertex_data[0].norm.delta_x = 1.0;
   vertex_data[0].norm.delta_y = 0.0;
   vertex_data[0].norm.delta_z = 0.0;

   vertex_data[1].point.x = WIDTH;
   vertex_data[1].point.y = 0.0;
   vertex_data[1].point.z = DEPTH;
   vertex_data[1].colr.direct.rgb.red = 0.0;
   vertex_data[1].colr.direct.rgb.green = 1.0;
   vertex_data[1].colr.direct.rgb.blue = 1.0;
   vertex_data[1].norm.delta_x = 1.0;
   vertex_data[1].norm.delta_y = 0.0;
   vertex_data[1].norm.delta_z = 0.0;

   vertex_data[2].point.x = WIDTH;
   vertex_data[2].point.y = HEIGHT;
   vertex_data[2].point.z = DEPTH;
   vertex_data[2].colr.direct.rgb.red = 1.0;
   vertex_data[2].colr.direct.rgb.green = 1.0;
   vertex_data[2].colr.direct.rgb.blue = 0.0;
   vertex_data[2].norm.delta_x = 1.0;
   vertex_data[2].norm.delta_y = 0.0;
   vertex_data[2].norm.delta_z = 0.0;

   vertex_data[3].point.x = WIDTH;
   vertex_data[3].point.y = HEIGHT;
   vertex_data[3].point.z = 0.0;
   vertex_data[3].colr.direct.rgb.red = 0.0;
   vertex_data[3].colr.direct.rgb.green = 1.0;
   vertex_data[3].colr.direct.rgb.blue = 1.0;
   vertex_data[3].norm.delta_x = 1.0;
   vertex_data[3].norm.delta_y = 0.0;
   vertex_data[3].norm.delta_z = 0.0;

   vdata.num_vertices = 4;
   vdata.vertex_data.ptconorms = vertex_data;
   pfill_area_set3_data(PFACET_NONE,
                        PEDGE_NONE,
                        PVERT_COORD_COLOUR_NORMAL,
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
   edge_colr.val.general.x = 1.0;
   edge_colr.val.general.y = 1.0;
   edge_colr.val.general.z = 1.0;

   int_colr.type = PMODEL_RGB;
   int_colr.val.general.x = 0.0;
   int_colr.val.general.y = 1.0;
   int_colr.val.general.z = 1.0;

   back_int_colr.type = PMODEL_RGB;
   back_int_colr.val.general.x = 0.0;
   back_int_colr.val.general.y = 1.0;
   back_int_colr.val.general.z = 0.0;

   refl_props.ambient_coef = 0.25;
   refl_props.diffuse_coef = 1.0;

   popen_phigs(NULL, 0);
   phg_mat_identity(rot3);

   popen_struct(STRUCT_OBJECT);
   pset_hlhsr_id(HLHSR_FLAG);
   pset_view_ind(view_ind);
   pset_edge_flag(EDGE_FLAG);
   pset_edge_colr(&edge_colr);
   pset_int_style(INT_STYLE);
   pset_face_disting_mode(DISTING_MODE);
   pset_face_cull_mode(CULL_MODE);
   pset_int_colr(&int_colr);
   pset_back_int_colr(&back_int_colr);
   pset_int_style(INT_STYLE);
   pset_back_int_style(BACK_INT_STYLE);
   pset_back_int_style_ind(BACK_STYLE_IND);
   pset_light_src_state(&lights_on_list, &lights_off_list);
   pset_int_shad_meth(PSD_COLOUR);
   pset_refl_eqn(PREFL_AMB_DIFF);
   pset_refl_props(&refl_props);
   plabel(LABEL_TRANS);
   pset_local_tran3(rot3, PTYPE_REPLACE);
   INIT_SHAPE();
   pclose_struct();

   popen_ws(0, NULL, PWST_OUTPUT_TRUE_DB);
   pset_hlhsr_mode(0, PHIGS_HLHSR_MODE_ZBUFF);
   setup_light(0);
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

