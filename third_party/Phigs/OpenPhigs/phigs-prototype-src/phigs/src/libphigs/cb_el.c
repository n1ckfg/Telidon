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

#include <stdlib.h>
#include <string.h>
#include <phigs/phg.h>
#include <phigs/css.h>
#include <phigs/private/phgP.h>

/*******************************************************************************
 * padd_names_set
 *
 * DESCR:	Creates a new element - name set Inclusion
 * RETURNS:	N/A
 */

void padd_names_set(
   Pint_list *names
   )
{
   Phg_args_add_el args;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_add_names_set)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_ADD_NAMES_SET;
         args.el_size = sizeof(Pint) + sizeof(Pint) * names->num_ints;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = names->num_ints;
            memcpy(&data[1], names->ints, sizeof(Pint) * names->num_ints);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * premove_names_set
 *
 * DESCR:	Creates a new element - name set Remover
 * RETURNS:	N/A
 */

void premove_names_set(
   Pint_list *names
   )
{
   Phg_args_add_el args;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_remove_names_set)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_REMOVE_NAMES_SET;
         args.el_size = sizeof(Pint) + sizeof(Pint) * names->num_ints;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = names->num_ints;
            memcpy(&data[1], names->ints, sizeof(Pint) * names->num_ints);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_indiv_asf
 *
 * DESCR:	Creates a new element - Set attribute source flag
 * RETURNS:	N/A
 */

void pset_indiv_asf(
   Paspect asf_id,
   Pasf asf_source
   )
{
   Phg_args_add_el args;
   Pasf_info *data;

   if (phg_entry_check(ERR5, Pfn_set_indiv_asf)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_INDIV_ASF;
         args.el_size = sizeof(Pasf_info);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pasf_info *) args.el_data;
            data->id = asf_id;
            data->source = asf_source; 
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_local_tran3
 *
 * DESCR:	Creates a new element - Set local model space transformation 3D
 * RETURNS:	N/A
 */

void pset_local_tran3(
   Pmatrix3 local_tran,
   Pcompose_type compose_type
   )
{
   Phg_args_add_el args;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_set_local_tran3)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_LOCAL_MODEL_TRAN3;
         args.el_size = sizeof(Pint) + 16 * sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = (Pint) compose_type;
            phg_mat_unpack((Pfloat *) &data[1], local_tran);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_global_tran3
 *
 * DESCR:	Creates a new element - Set global model space transformation 3D
 * RETURNS:	N/A
 */

void pset_global_tran3(
   Pmatrix3 global_tran
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_global_tran3)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_GLOBAL_MODEL_TRAN3;
         args.el_size = 16 * sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            phg_mat_unpack((Pfloat *) args.el_data, global_tran);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_view_ind
 *
 * DESCR:	Creates a new element - Set view index
 * RETURNS:	N/A
 */

void pset_view_ind(
   Pint view_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_view_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (view_ind < 0) {
         ERR_REPORT(PHG_ERH, ERR114);
      }
      else {
         args.el_type = PELEM_VIEW_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &view_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * ptext
 *
 * DESCR:	Creates a new element - Text
 * RETURNS:	N/A
 */

void ptext(
   Ppoint *text_pos,
   char *char_string
   )
{
   Phg_args_add_el args;
   Ppoint *data;

   if (phg_entry_check(ERR5, Pfn_text)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_TEXT;
         args.el_size = sizeof(Ppoint) + strlen(char_string) + 1;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Ppoint *) args.el_data;
            memcpy(data, text_pos, sizeof(Ppoint));
            strcpy((char *) &data[1], char_string);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * ppolyline
 *
 * DESCR:	Creates a new element - Polyline
 * RETURNS:	N/A
 */

void ppolyline(
   Ppoint_list *point_list
   )
{
   Phg_args_add_el args;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_polyline)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_POLYLINE;
         args.el_size = sizeof(Pint) + sizeof(Ppoint) * point_list->num_points;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = point_list->num_points;
            memcpy(&data[1], point_list->points,
                   sizeof(Ppoint) * point_list->num_points);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * ppolyline3
 *
 * DESCR:	Creates a new element - Polyline 3D
 * RETURNS:	N/A
 */

void ppolyline3(
   Ppoint_list3 *point_list
   )
{
   Phg_args_add_el args;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_polyline3)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_POLYLINE3;
         args.el_size = sizeof(Pint) + sizeof(Ppoint3) * point_list->num_points;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = point_list->num_points;
            memcpy(&data[1], point_list->points,
                   sizeof(Ppoint3) * point_list->num_points);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * ppolymarker
 *
 * DESCR:	Creates a new element - Polymarker
 * RETURNS:	N/A
 */

void ppolymarker(
   Ppoint_list *point_list
   )
{
   Phg_args_add_el args;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_polymarker)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_POLYMARKER;
         args.el_size = sizeof(Pint) + sizeof(Ppoint) * point_list->num_points;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = point_list->num_points;
            memcpy(&data[1], point_list->points,
                   sizeof(Ppoint) * point_list->num_points);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * ppolymarker3
 *
 * DESCR:	Creates a new element - Polymarker 3D
 * RETURNS:	N/A
 */

void ppolymarker3(
   Ppoint_list3 *point_list
   )
{
   Phg_args_add_el args;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_polymarker3)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_POLYMARKER3;
         args.el_size = sizeof(Pint) + sizeof(Ppoint3) * point_list->num_points;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = point_list->num_points;
            memcpy(&data[1], point_list->points,
                   sizeof(Ppoint3) * point_list->num_points);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pfill_area
 *
 * DESCR:	Creates a new element - Fill area
 * RETURNS:	N/A
 */

void pfill_area(
   Ppoint_list *point_list
   )
{
   Phg_args_add_el args;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_fill_area)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_FILL_AREA;
         args.el_size = sizeof(Pint) + sizeof(Ppoint) * point_list->num_points;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = point_list->num_points;
            memcpy(&data[1], point_list->points,
                   sizeof(Ppoint) * point_list->num_points);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pfill_area3
 *
 * DESCR:	Creates a new element - Fill area 3D
 * RETURNS:	N/A
 */

void pfill_area3(
   Ppoint_list3 *point_list
   )
{
   Phg_args_add_el args;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_fill_area3)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_FILL_AREA3;
         args.el_size = sizeof(Pint) + sizeof(Ppoint3) * point_list->num_points;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = point_list->num_points;
            memcpy(&data[1], point_list->points,
                   sizeof(Ppoint3) * point_list->num_points);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pfill_area_set
 *
 * DESCR:	Creates a new element - Fill area set
 * RETURNS:	N/A
 */

void pfill_area_set(
   Ppoint_list_list *point_list_list
   )
{
   Phg_args_add_el args;
   Pint i, num_points;
   Pint num_lists;
   Pint *data;
   Ppoint *pts;

   if (phg_entry_check(ERR5, Pfn_fill_area_set)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_FILL_AREA_SET;
         num_lists = point_list_list->num_point_lists;
         for (i = 0, num_points = 0; i < num_lists; i++) {
            num_points += point_list_list->point_lists[i].num_points;
         }
         args.el_size = sizeof(Pint) +
            sizeof(Pint) * num_lists + sizeof(Ppoint) * num_points;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = num_lists;
            data = &data[1];
            for (i = 0; i < num_lists; i++) {
               data[0] = point_list_list->point_lists[i].num_points;
               pts = (Ppoint *) &data[1];
               memcpy(pts, point_list_list->point_lists[i].points,
                      data[0] * sizeof(Ppoint));
               data = (Pint *) &pts[data[0]];
            }
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pfill_area_set3
 *
 * DESCR:	Creates a new element - Fill area set 3D
 * RETURNS:	N/A
 */

void pfill_area_set3(
   Ppoint_list_list3 *point_list_list
   )
{
   Phg_args_add_el args;
   Pint i, num_points;
   Pint num_lists;
   Pint *data;
   Ppoint3 *pts;

   if (phg_entry_check(ERR5, Pfn_fill_area_set3)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_FILL_AREA_SET3;
         num_lists = point_list_list->num_point_lists;
         for (i = 0, num_points = 0; i < num_lists; i++) {
            num_points += point_list_list->point_lists[i].num_points;
         }
         args.el_size = sizeof(Pint) +
            sizeof(Pint) * num_lists + sizeof(Ppoint3) * num_points;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = num_lists;
            data = &data[1];
            for (i = 0; i < num_lists; i++) {
               data[0] = point_list_list->point_lists[i].num_points;
               pts = (Ppoint3 *) &data[1];
               memcpy(pts, point_list_list->point_lists[i].points,
                      data[0] * sizeof(Ppoint3));
               data = (Pint *) &pts[data[0]];
            }
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * plabel
 *
 * DESCR:	Creates a new element - Label
 * RETURNS:	N/A
 */

void plabel(
   Pint label_id
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_label)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_LABEL;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &label_id, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_pick_id
 *
 * DESCR:	Creates a new element - Pick ID
 * RETURNS:	N/A
 */

void pset_pick_id(
   Pint pick_id
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_pick_id)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_PICK_ID;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &pick_id, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_hlhsr_id
 *
 * DESCR:	Create hidden lines, surface removal flag element
 * RETURNS:	N/A
 */

void pset_hlhsr_id(
   Pint hlhsr_id
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_hlhsr_id)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_HLHSR_ID;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &hlhsr_id, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_int_ind
 *
 * DESCR:	Creates a new element - Facet Interiour Attribute Index
 * RETURNS:	N/A
 */

void pset_int_ind(
   Pint int_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_int_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (int_ind < 1) {
         ERR_REPORT(PHG_ERH, ERR100);
      }
      else {
         args.el_type = PELEM_INT_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &int_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_int_colr_ind
 *
 * DESCR:	Creates a new element - Facet Color Attribute
 * RETURNS:	N/A
 */

void pset_int_colr_ind(
   Pint colr_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_int_colr_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (colr_ind < 0) {
         ERR_REPORT(PHG_ERH, ERR113);
      }
      else {
         args.el_type = PELEM_INT_COLR_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &colr_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_int_style
 *
 * DESCR:	Creates a new element - Face Interiour Style
 * RETURNS:	N/A
 */

void pset_int_style(
   Pint_style int_style
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_int_style)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_INT_STYLE;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            *((Pint *) args.el_data) = (Pint) int_style;
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_int_style_ind
 *
 * DESCR:	Creates a new element - Face Interiour Pattern Index
 * RETURNS:	N/A
 */

void pset_int_style_ind(
   Pint int_style_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_int_style)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (int_style_ind < 1) {
         ERR_REPORT(PHG_ERH, ERR112);
      }
      else {
         args.el_type = PELEM_INT_STYLE_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &int_style_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_line_ind
 *
 * DESCR:	Creates a new element - Line Attribute Index
 * RETURNS:	N/A
 */

void pset_line_ind(
   Pint line_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_line_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (line_ind < 1) {
         ERR_REPORT(PHG_ERH, ERR100);
      }
      else {
         args.el_type = PELEM_LINE_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &line_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_line_colr_ind
 *
 * DESCR:	Creates a new element - Line Color Attribute
 * RETURNS:	N/A
 */

void pset_line_colr_ind(
   Pint colr_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_line_colr_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (colr_ind < 0) {
         ERR_REPORT(PHG_ERH, ERR113);
      }
      else {
         args.el_type = PELEM_LINE_COLR_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &colr_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_linewidth
 *
 * DESCR:	Creates a new element - Line Width Attribute
 * RETURNS:	N/A
 */

void pset_linewidth(
   Pfloat linewidth
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_linewidth)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_LINEWIDTH;
         args.el_size = sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &linewidth, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_linetype
 *
 * DESCR:	Creates a new element - Line Type Attribute
 * RETURNS:	N/A
 */

void pset_linetype(
   Pint linetype
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_linetype)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_LINETYPE;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &linetype, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_marker_ind
 *
 * DESCR:	Creates a new element - Marker Attribute Index
 * RETURNS:	N/A
 */

void pset_marker_ind(
   Pint marker_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_marker_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (marker_ind < 1) {
         ERR_REPORT(PHG_ERH, ERR100);
      }
      else {
         args.el_type = PELEM_MARKER_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &marker_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_marker_colr_ind
 *
 * DESCR:	Creates a new element - Marker Color Attribute
 * RETURNS:	N/A
 */

void pset_marker_colr_ind(
   Pint colr_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_marker_colr_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (colr_ind < 0) {
         ERR_REPORT(PHG_ERH, ERR113);
      }
      else {
         args.el_type = PELEM_MARKER_COLR_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &colr_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_marker_size
 *
 * DESCR:	Creates a new element - Marker Size Attribute
 * RETURNS:	N/A
 */

void pset_marker_size(
   Pfloat marker_size
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_marker_size)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_MARKER_SIZE;
         args.el_size = sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &marker_size, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_marker_type
 *
 * DESCR:	Creates a new element - Marker Type Attribute
 * RETURNS:	N/A
 */

void pset_marker_type(
   Pint marker_type
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_marker_type)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_MARKER_TYPE;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &marker_type, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_edge_ind
 *
 * DESCR:	Creates a new element - Edge Attribute Index
 * RETURNS:	N/A
 */

void pset_edge_ind(
   Pint edge_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_edge_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (edge_ind < 1) {
         ERR_REPORT(PHG_ERH, ERR100);
      }
      else {
         args.el_type = PELEM_EDGE_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &edge_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_edge_colr_ind
 *
 * DESCR:	Creates a new element - Edge Color Attribute
 * RETURNS:	N/A
 */

void pset_edge_colr_ind(
   Pint colr_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_edge_colr_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (colr_ind < 0) {
         ERR_REPORT(PHG_ERH, ERR113);
      }
      else {
         args.el_type = PELEM_EDGE_COLR_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &colr_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_edgetype
 *
 * DESCR:	Creates a new element - Edge Type Attribute
 * RETURNS:	N/A
 */

void pset_edgetype(
   Pint edgetype
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_edgetype)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_EDGETYPE;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &edgetype, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_edge_flag
 *
 * DESCR:	Creates a new element - Edge Flag Attribute
 * RETURNS:	N/A
 */

void pset_edge_flag(
   Pedge_flag edge_flag
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_edge_flag)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_EDGE_FLAG;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            *((Pint *) args.el_data) = (Pint) edge_flag;
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_edgewidth
 *
 * DESCR:	Creates a new element - Edge Width Attribute
 * RETURNS:	N/A
 */

void pset_edgewidth(
   Pfloat edgewidth
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_edgewidth)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_EDGEWIDTH;
         args.el_size = sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &edgewidth, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_text_font
 *
 * DESCR:	Creates a new element - Text Font Attribute
 * RETURNS:	N/A
 */

void pset_text_font(
   Pint font
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_text_font)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_TEXT_FONT;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &font, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_text_prec
 *
 * DESCR:	Creates a new element - Text Precision Attribute
 * RETURNS:	N/A
 */

void pset_text_prec(
   Ptext_prec prec
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_text_prec)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_TEXT_PREC;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            *((Pint *) args.el_data) = (Pint) prec;
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_text_path
 *
 * DESCR:	Creates a new element - Text Path Attribute
 * RETURNS:	N/A
 */

void pset_text_path(
   Ptext_path text_path
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_text_path)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_TEXT_PATH;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            *((Pint *) args.el_data) = (Pint) text_path;
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_text_align
 *
 * DESCR:	Creates a new element - Text Alignment Attribute
 * RETURNS:	N/A
 */

void pset_text_align(
   Ptext_align *text_align
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_text_align)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_TEXT_ALIGN;
         args.el_size = sizeof(Ptext_align);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, text_align, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_char_ht
 *
 * DESCR:	Creates a new element - Character height Attribute
 * RETURNS:	N/A
 */

void pset_char_ht(
   Pfloat char_ht
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_char_ht)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_CHAR_HT;
         args.el_size = sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &char_ht, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_char_expan
 *
 * DESCR:	Creates a new element - Character expansion factor Attribute
 * RETURNS:	N/A
 */

void pset_char_expan(
   Pfloat char_expan
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_char_expan)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_CHAR_EXPAN;
         args.el_size = sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &char_expan, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_char_space
 *
 * DESCR:	Creates a new element - Character spaceing Attribute
 * RETURNS:	N/A
 */

void pset_char_space(
   Pfloat char_space
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_char_space)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_CHAR_SPACE;
         args.el_size = sizeof(Pfloat);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &char_space, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_char_up_vec
 *
 * DESCR:	Creates a new element - Character up vector Attribute
 * RETURNS:	N/A
 */

void pset_char_up_vec(
   Pvec *char_up_vec
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_char_up_vec)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_CHAR_UP_VEC;
         args.el_size = sizeof(Pvec);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, char_up_vec, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_text_ind
 *
 * DESCR:	Creates a new element - Text Attribute Index
 * RETURNS:	N/A
 */

void pset_text_ind(
   Pint text_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_text_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (text_ind < 1) {
         ERR_REPORT(PHG_ERH, ERR100);
      }
      else {
         args.el_type = PELEM_TEXT_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &text_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_text_colr_ind
 *
 * DESCR:	Creates a new element - Text Color Attribute
 * RETURNS:	N/A
 */

void pset_text_colr_ind(
   Pint colr_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_text_colr_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (colr_ind < 0) {
         ERR_REPORT(PHG_ERH, ERR113);
      }
      else {
         args.el_type = PELEM_TEXT_COLR_IND;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &colr_ind, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pexec_struct
 *
 * DESCR:	Creates a new element - Nested Structure
 * RETURNS:	N/A
 */

void pexec_struct(
   Pint struct_id
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_exec_struct)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_EXEC_STRUCT;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &struct_id, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

