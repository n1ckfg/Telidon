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
#include <phigs/phigs.h>
#include <phigs/phg.h>
#include "glm.h"

#define ANGLE_DELTA   0.1
#define STRUCT_OBJECT   0
#define STRUCT_SCENE    1
#define LABEL_TRANS    10
#define INT_STYLE      PSTYLE_SOLID
#define EDGE_FLAG      PEDGE_OFF
#define HLHSR_FLAG     PHIGS_HLHSR_ID_ON
#define INIT_SHAPE     init_shape_single
#define CULL_MODE      PCULL_BACKFACE
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
Pgcolr int_colr;
Pgcolr back_int_colr;
Pgcolr edge_colr;
Pint lights_on[] = {1, 2};
Pint light_off[] = {0};
Pint_list lights_on_list = {2, lights_on};
Pint_list lights_off_list = {0, light_off};
Prefl_props refl_props;
Prefl_props back_refl_props;
GLMmodel *model = NULL;
char object_name[80];
Ppoint text_pos = {0.01, 0.01};

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

Pint_list* set_triangle(GLuint *v)
{
   Pint_list *vlist;

   vlist = (Pint_list *) malloc(sizeof(Pint_list) * 3 * sizeof(Pint));
   vlist->num_ints = 3;
   vlist->ints = (Pint *) & vlist[1];

   vlist->ints[0] = (Pint) v[0];
   vlist->ints[1] = (Pint) v[1];
   vlist->ints[2] = (Pint) v[2];

   return vlist;
}

void init_shape_norm_per_facet(void)
{
   Pint i, ref;
   Ppoint3 *vertex_data;
   Pvec3 *norms;
   Pint_list_list *vlist;
   Pfacet_data_arr3 fdata;
   Pfacet_vdata_list3 vdata;

   vertex_data = (Ppoint3 *) malloc(sizeof(Ppoint3) * model->numvertices);
   if (vertex_data == NULL) {
      fprintf(stderr, "Fatal Error - Unable to allocate memory for vertices\n");
      exit(1);
   }

   norms = (Pvec3 *) malloc(sizeof(Pvec3) * model->numtriangles);
   if (norms == NULL) {
      fprintf(stderr, "Fatal Error - Unable to allocate memory for normals\n");
      exit(1);
   }

   vlist = (Pint_list_list *) malloc(sizeof(Pint_list_list) * model->numtriangles);
   if (vlist == NULL) {
      fprintf(stderr, "Fatal Error - Unable to allocate memory for vertex lists\n");
      exit(1);
   }

   for (i = 0; i < model->numtriangles; i++) {
      vertex_data[i].x = model->vertices[i * 3    ];
      vertex_data[i].y = model->vertices[i * 3 + 1];
      vertex_data[i].z = model->vertices[i * 3 + 2];
   }

   for (i = 0; i < model->numtriangles; i++) {
      ref = model->triangles[i].findex;
      if (ref < model->numfacetnorms) {
         norms[i].delta_x = model->facetnorms[ref * 3];
         norms[i].delta_y = model->facetnorms[ref * 3 + 1];
         norms[i].delta_z = model->facetnorms[ref * 3 + 2];
      }
      else {
         norms[i].delta_x = 0.0;
         norms[i].delta_y = 0.0;
         norms[i].delta_z = 0.0;
      }
      vlist[i].num_lists = 1;
      vlist[i].lists = set_triangle(model->triangles[i].vindices);
   }

   fdata.norms = norms;

   vdata.num_vertices = model->numvertices;
   vdata.vertex_data.points = vertex_data;

   pset_of_fill_area_set3_data(PFACET_NORMAL,
                               PEDGE_NONE,
                               PVERT_COORD,
                               PMODEL_RGB,
                               model->numtriangles,
                               &fdata,
                               NULL,
                               vlist,
                               &vdata);

   for (i = 0; i < model->numtriangles; i++) {
      free(vlist[i].lists);
   }
   //free(vlist);
   //free(norms);
   //free(vertex_data);
}

void init_shape_norm_per_vertex(void)
{
   Pint i;
   Pptnorm3 *vertex_data;
   Pint_list_list *vlist;
   Pfacet_vdata_list3 vdata;

   vertex_data = (Pptnorm3 *) malloc(sizeof(Pptnorm3) * model->numvertices);
   if (vertex_data == NULL) {
      fprintf(stderr, "Fatal Error - Unable to allocate memory for vertices\n");
      exit(1);
   }

   vlist = (Pint_list_list *) malloc(sizeof(Pint_list_list) * model->numtriangles);
   if (vlist == NULL) {
      fprintf(stderr, "Fatal Error - Unable to allocate memory for vertex lists\n");
      exit(1);
   }

   for (i = 0; i < model->numtriangles; i++) {
      vertex_data[i].point.x      = model->vertices[i * 3    ];
      vertex_data[i].point.y      = model->vertices[i * 3 + 1];
      vertex_data[i].point.z      = model->vertices[i * 3 + 2];
      vertex_data[i].norm.delta_x = model->normals [i * 3    ];
      vertex_data[i].norm.delta_y = model->normals [i * 3 + 1];
      vertex_data[i].norm.delta_z = model->normals [i * 3 + 2];
   }

   for (i = 0; i < model->numtriangles; i++) {
      vlist[i].num_lists = 1;
      vlist[i].lists = set_triangle(model->triangles[i].vindices);
   }

   vdata.num_vertices = model->numvertices;
   vdata.vertex_data.ptnorms = vertex_data;

   pset_of_fill_area_set3_data(PFACET_NONE,
                               PEDGE_NONE,
                               PVERT_COORD_NORMAL,
                               PMODEL_RGB,
                               model->numtriangles,
                               NULL,
                               NULL,
                               vlist,
                               &vdata);

   for (i = 0; i < model->numtriangles; i++) {
      free(vlist[i].lists);
   }
   //free(vlist);
   //free(vertex_data);
}

#define T(x) (model->triangles[(x)])
void init_shape_single(void)
{
   Pint i, j, vert, norm;
   Pptnorm3 vertex_data[3];
   Pfacet_data3 fdata;
   Pfacet_vdata_list3 vdata;
   GLMgroup *group;
   GLMtriangle *triangle;
   GLMmaterial *material;

   for (group = model->groups; group != NULL; group = group->next) {

      if (model->materials != NULL) {
         material = &model->materials[group->material];
         fdata.colr.direct.rgb.red   = material->diffuse[0];
         fdata.colr.direct.rgb.green = material->diffuse[1];
         fdata.colr.direct.rgb.blue  = material->diffuse[2];
      }
      else {
         fdata.colr.direct.rgb.red   = 0.0;
         fdata.colr.direct.rgb.green = 0.75;
         fdata.colr.direct.rgb.blue  = 0.75;
      }

      for (i = 0; i < group->numtriangles; i++) {
         triangle = &T(group->triangles[i]);

         for (j = 0; j < 3; j++) {
            vert = triangle->vindices[j];
            vertex_data[j].point.x      = model->vertices[vert * 3    ];
            vertex_data[j].point.y      = model->vertices[vert * 3 + 1];
            vertex_data[j].point.z      = model->vertices[vert * 3 + 2];

            norm = triangle->nindices[j];
            vertex_data[j].norm.delta_x = model->normals[norm * 3    ];
            vertex_data[j].norm.delta_y = model->normals[norm * 3 + 1];
            vertex_data[j].norm.delta_z = model->normals[norm * 3 + 2];
         }

         vdata.num_vertices = 3;
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
   }
}

int main(int argc, char *argv[])
{
   XEvent event;
   KeySym ks;

   if (argc < 2) {
      fprintf(stderr, "usage is: %s <obj-file> [view-index]\n", argv[0]);
      return 1;
   }

   if (argc > 2) {
      view_ind = atoi(argv[2]);
      printf("Use view: %d\n", view_ind);
   }

   model = glmReadOBJ(argv[1]);
   if (model == NULL) {
      fprintf(stderr, "Fatal Error - Unable to read model: %s\n", argv[1]);
      return 1;
   }
   strncpy(object_name, argv[1], 80);

   glmUnitize(model);
   glmFacetNormals(model);
   glmVertexNormals(model, 90.0);

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

   back_refl_props.ambient_coef = 0.2;
   back_refl_props.diffuse_coef = 0.0;

   popen_phigs(NULL, 0);
   phg_mat_identity(rot3);

   popen_struct(STRUCT_OBJECT);
   plabel(LABEL_TRANS);
   pset_local_tran3(rot3, PTYPE_REPLACE);
   INIT_SHAPE();
   pclose_struct();

   popen_struct(STRUCT_SCENE);
   pset_hlhsr_id(HLHSR_FLAG);
   pset_view_ind(view_ind);
   pset_edge_flag(EDGE_FLAG);
   pset_edge_colr(&edge_colr);
   pset_face_disting_mode(DISTING_MODE);
   pset_face_cull_mode(CULL_MODE);
   pset_int_colr(&int_colr);
   pset_back_int_colr(&back_int_colr);
   pset_int_style(INT_STYLE);
   pset_back_int_style(BACK_INT_STYLE);
   pset_back_int_style_ind(BACK_STYLE_IND);
   pset_light_src_state(&lights_on_list, &lights_off_list);
   pset_int_shad_meth(SHAD_METH);
   pset_back_int_shad_meth(BACK_SHAD_METH);
   pset_refl_eqn(REFL_EQN);
   pset_back_refl_eqn(BACK_REFL_EQN);
   pset_refl_props(&refl_props);
   pset_back_refl_props(&back_refl_props);
   pexec_struct(STRUCT_OBJECT);
   pset_view_ind(0);
   pset_char_ht(0.02);
   ptext(&text_pos, object_name);
   pclose_struct();

   popen_ws(0, NULL, PWST_OUTPUT_TRUE_DB);
   pset_hlhsr_mode(0, PHIGS_HLHSR_MODE_ZBUFF);
   setup_light(0);
   pset_disp_upd_st(0, PDEFER_BNIL, PMODE_UQUM);
   ppost_struct(0, STRUCT_SCENE, 0);
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
            else if (ks == XK_Escape) {
               goto exit;
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

exit:
   pclose_ws (0);
   pclose_phigs();

   return 0;
}

