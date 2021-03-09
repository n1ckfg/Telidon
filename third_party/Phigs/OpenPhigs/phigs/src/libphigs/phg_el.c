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

#include <stdlib.h>
#include <string.h>
#include <phigs/phg.h>
#include <phigs/css.h>
#include <phigs/private/phgP.h>

/*******************************************************************************
 * phg_add_el
 *
 * DESCR:	Add an element and update workstations posted to
 * RETURNS:	N/A
 */

static void phg_add_el(
   Css_handle cssh,
   Phg_args_add_el *args
   )
{
   Css_ws_list ws_list;

   ws_list = CSS_GET_WS_ON(CSS_CUR_STRUCTP(cssh));

   if (phg_css_add_elem(cssh, args)) {
      if (ws_list != NULL) {
         for (; ws_list->wsh; ws_list++)
            (*ws_list->wsh->add_el)(ws_list->wsh);
      }
   }
}

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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_add_names_set);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_ADD_NAMES_SET;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) + sizeof(Pint) * names->num_ints;
      ARGS_ELMT_DATA(&args).int_list.num_ints = names->num_ints;
      ARGS_ELMT_DATA(&args).int_list.ints = names->ints;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_remove_names_set);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_REMOVE_NAMES_SET;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) + sizeof(Pint) * names->num_ints;
      ARGS_ELMT_DATA(&args).int_list.num_ints = names->num_ints;
      ARGS_ELMT_DATA(&args).int_list.ints = names->ints;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_indiv_asf);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_INDIV_ASF;
      ARGS_ELMT_SIZE(&args) = sizeof(Pasf_info);
      ARGS_ELMT_DATA(&args).asf_info.id = asf_id;
      ARGS_ELMT_DATA(&args).asf_info.source = asf_source;
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_local_tran
 *
 * DESCR:	Creates a new element - Set local model space transformation
 * RETURNS:	N/A
 */

void pset_local_tran(
   Pmatrix local_tran,
   Pcompose_type compose_type
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_local_tran);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_LOCAL_MODEL_TRAN;
      ARGS_ELMT_SIZE(&args) = sizeof(Pcompose_type) + sizeof(Pmatrix);
      ARGS_ELMT_DATA(&args).local_tran.compose_type = compose_type;
      phg_mat_copy_3x3(ARGS_ELMT_DATA(&args).local_tran.matrix, local_tran);
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_local_tran3);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_LOCAL_MODEL_TRAN3;
      ARGS_ELMT_SIZE(&args) = sizeof(Plocal_tran3);
      ARGS_ELMT_DATA(&args).local_tran3.compose_type = compose_type;
      phg_mat_copy(ARGS_ELMT_DATA(&args).local_tran3.matrix, local_tran);
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_global_tran
 *
 * DESCR:	Creates a new element - Set global model space transformation
 * RETURNS:	N/A
 */

void pset_global_tran(
   Pmatrix global_tran
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_global_tran);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_GLOBAL_MODEL_TRAN;
      ARGS_ELMT_SIZE(&args) = sizeof(Pmatrix);
      phg_mat_copy_3x3(ARGS_ELMT_DATA(&args).global_tran, global_tran);
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_global_tran3);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_GLOBAL_MODEL_TRAN3;
      ARGS_ELMT_SIZE(&args) = sizeof(Pmatrix3);
      phg_mat_copy(ARGS_ELMT_DATA(&args).global_tran3, global_tran);
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_view_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (view_ind < 0) {
      ERR_REPORT(PHG_ERH, ERR114);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_VIEW_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = view_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_text);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_TEXT;
      ARGS_ELMT_SIZE(&args) = sizeof(Ppoint) + strlen(char_string) + 1;
      memcpy(&ARGS_ELMT_DATA(&args).text.pos, text_pos, sizeof(Ppoint));
      ARGS_ELMT_DATA(&args).text.char_string = char_string;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_polyline);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_POLYLINE;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) +
          sizeof(Ppoint) * point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list.num_points = point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list.points = point_list->points;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_polyline3);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_POLYLINE3;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) +
          sizeof(Ppoint3) * point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list3.num_points =
         point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list3.points = point_list->points;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_polymarker);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_POLYMARKER;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) +
          sizeof(Ppoint) * point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list.num_points = point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list.points = point_list->points;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_polymarker3);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_POLYMARKER3;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) +
          sizeof(Ppoint3) * point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list3.num_points =
         point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list3.points = point_list->points;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_fill_area);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_FILL_AREA;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) +
          sizeof(Ppoint) * point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list.num_points = point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list.points = point_list->points;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_fill_area3);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_FILL_AREA3;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) +
          sizeof(Ppoint3) * point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list3.num_points =
         point_list->num_points;
      ARGS_ELMT_DATA(&args).point_list3.points = point_list->points;
      phg_add_el(PHG_CSS, &args);
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
   Pint i, num_points;
   unsigned size;
   Pint num_lists;
   Ppoint_list *point_lists;
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_fill_area_set);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_FILL_AREA_SET;
      num_lists = point_list_list->num_point_lists;
      size = sizeof(Ppoint_list) * num_lists;
      for (i = 0, num_points = 0; i < num_lists; i++) {
         num_points += point_list_list->point_lists[i].num_points;
      }
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) * num_lists +
         sizeof(Ppoint) * num_points;

      if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, size)) {
         ERR_REPORT(PHG_ERH, ERR900);
      }
      else {
         point_lists = (Ppoint_list *) PHG_SCRATCH.buf;
         memcpy(point_lists, point_list_list->point_lists, size);
         ARGS_ELMT_DATA(&args).point_list_list.num_point_lists = num_lists;
         ARGS_ELMT_DATA(&args).point_list_list.point_lists = point_lists;
         phg_add_el(PHG_CSS, &args);
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
   Pint i, num_points;
   unsigned size;
   Pint num_lists;
   Ppoint_list3 *point_lists;
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_fill_area_set3);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_FILL_AREA_SET3;
      num_lists = point_list_list->num_point_lists;
      size = sizeof(Ppoint_list3) * num_lists;
      for (i = 0, num_points = 0; i < num_lists; i++) {
         num_points += point_list_list->point_lists[i].num_points;
      }
      ARGS_ELMT_SIZE(&args) = sizeof(Pint) * num_lists +
         sizeof(Ppoint3) * num_points;

      if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, size)) {
         ERR_REPORT(PHG_ERH, ERR900);
      }
      else {
         point_lists = (Ppoint_list3 *) PHG_SCRATCH.buf;
         memcpy(point_lists, point_list_list->point_lists, size);
         ARGS_ELMT_DATA(&args).point_list_list3.num_point_lists = num_lists;
         ARGS_ELMT_DATA(&args).point_list_list3.point_lists = point_lists;
         phg_add_el(PHG_CSS, &args);
      }
   }
}

/*******************************************************************************
 * pfill_area_set3_data
 *
 * DESCR:	Creates a new element - Fill area set with data 3D
 * RETURNS:	N/A
 */

void pfill_area_set3_data(
   Pint fflag,
   Pint eflag,
   Pint vflag,
   Pint colr_type,
   Pfacet_data3 *fdata,
   Pint nfa,
   Pedge_data_list *edata,
   Pfacet_vdata_list3 *vdata
   )
{
   Pint i;
   unsigned facet_size, vertex_size;
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_fill_area_set3_data);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      switch (fflag) {
         case PFACET_COLOUR:
            facet_size = sizeof(Pcoval);
            break;

         case PFACET_NORMAL:
            facet_size = sizeof(Pvec3);
            break;

         case PFACET_COLOUR_NORMAL:
            facet_size = sizeof(Pptconorm3);
            break;

         default:
            facet_size = 0;
            break;
      }

      switch (vflag) {
         case PVERT_COORD:
            vertex_size = sizeof(Ppoint3);
            break;

         case PVERT_COORD_COLOUR:
            vertex_size = sizeof(Pptco3);
            break;

         case PVERT_COORD_NORMAL:
            vertex_size = sizeof(Pptnorm3);
            break;

         case PVERT_COORD_COLOUR_NORMAL:
            vertex_size = sizeof(Pptconorm3);
            break;

         default: 
            vertex_size = 0;
            break;
      }

      ARGS_ELMT_TYPE(&args) = PELEM_FILL_AREA3_DATA;
      ARGS_ELMT_SIZE(&args) = 5 * sizeof(Pint) + facet_size;

      if (eflag == PEDGE_VISIBILITY) {
         for (i = 0; i < nfa; i++) {
            ARGS_ELMT_SIZE(&args) += sizeof(Pint);   /* Pint num_edges */
            ARGS_ELMT_SIZE(&args) += edata[i].num_edges * sizeof(Pedge_flag);
         }
      }

      for (i = 0; i < nfa; i++) {
         ARGS_ELMT_SIZE(&args) += sizeof(Pint);   /* Pint num_vertices */
         ARGS_ELMT_SIZE(&args) += vdata[i].num_vertices * vertex_size;
      }

      ARGS_ELMT_DATA(&args).fasd3.fflag = fflag;
      ARGS_ELMT_DATA(&args).fasd3.eflag = eflag;
      ARGS_ELMT_DATA(&args).fasd3.vflag = vflag;
      ARGS_ELMT_DATA(&args).fasd3.colr_type = colr_type;
      memcpy(&ARGS_ELMT_DATA(&args).fasd3.fdata, fdata, sizeof(Pfacet_data3));
      ARGS_ELMT_DATA(&args).fasd3.nfa = nfa;
      ARGS_ELMT_DATA(&args).fasd3.edata = edata;
      ARGS_ELMT_DATA(&args).fasd3.vdata = vdata;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_label);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_LABEL;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = label_id;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_pick_id);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_PICK_ID;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = pick_id;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_hlhsr_id);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_HLHSR_ID;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = hlhsr_id;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_int_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (int_ind < 1) {
      ERR_REPORT(PHG_ERH, ERR100);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_INT_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = int_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_int_colr_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (colr_ind < 0) {
      ERR_REPORT(PHG_ERH, ERR113);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_INT_COLR_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = colr_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_int_style);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_INT_STYLE;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint_style);
      ARGS_ELMT_DATA(&args).int_style = int_style;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_int_style);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (int_style_ind < 1) {
      ERR_REPORT(PHG_ERH, ERR112);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_INT_STYLE_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = int_style_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_line_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (line_ind < 1) {
      ERR_REPORT(PHG_ERH, ERR100);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_LINE_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = line_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_line_colr_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (colr_ind < 0) {
      ERR_REPORT(PHG_ERH, ERR113);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_LINE_COLR_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = colr_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_linewidth);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_LINEWIDTH;
      ARGS_ELMT_SIZE(&args) = sizeof(Pfloat);
      ARGS_ELMT_DATA(&args).float_data = linewidth;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_linetype);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_LINETYPE;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = linetype;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_marker_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (marker_ind < 1) {
      ERR_REPORT(PHG_ERH, ERR100);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_MARKER_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = marker_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_marker_colr_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (colr_ind < 0) {
      ERR_REPORT(PHG_ERH, ERR113);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_MARKER_COLR_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = colr_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_marker_size);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_MARKER_SIZE;
      ARGS_ELMT_SIZE(&args) = sizeof(Pfloat);
      ARGS_ELMT_DATA(&args).float_data = marker_size;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_marker_type);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_MARKER_TYPE;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = marker_type;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_edge_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (edge_ind < 1) {
      ERR_REPORT(PHG_ERH, ERR100);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_EDGE_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = edge_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_edge_colr_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (colr_ind < 0) {
      ERR_REPORT(PHG_ERH, ERR113);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_EDGE_COLR_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = colr_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_edgetype);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_EDGETYPE;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = edgetype;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_edge_flag);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_EDGE_FLAG;
      ARGS_ELMT_SIZE(&args) = sizeof(Pedge_flag);
      ARGS_ELMT_DATA(&args).edge_flag = edge_flag;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_edgewidth);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_EDGEWIDTH;
      ARGS_ELMT_SIZE(&args) = sizeof(Pfloat);
      ARGS_ELMT_DATA(&args).float_data = edgewidth;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_text_font);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_TEXT_FONT;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = font;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_text_prec);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_TEXT_PREC;
      ARGS_ELMT_SIZE(&args) = sizeof(Ptext_prec);
      ARGS_ELMT_DATA(&args).text_prec = prec;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_text_path);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_TEXT_PATH;
      ARGS_ELMT_SIZE(&args) = sizeof(Ptext_path);
      ARGS_ELMT_DATA(&args).text_path = text_path;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_text_align);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_TEXT_ALIGN;
      ARGS_ELMT_SIZE(&args) = sizeof(Ptext_align);
      memcpy(&ARGS_ELMT_DATA(&args).text_path, text_align, sizeof(Ptext_align));
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_char_ht);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_CHAR_HT;
      ARGS_ELMT_SIZE(&args) = sizeof(Pfloat);
      ARGS_ELMT_DATA(&args).float_data = char_ht;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_char_expan);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_CHAR_EXPAN;
      ARGS_ELMT_SIZE(&args) = sizeof(Pfloat);
      ARGS_ELMT_DATA(&args).float_data = char_expan;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_char_space);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_CHAR_SPACE;
      ARGS_ELMT_SIZE(&args) = sizeof(Pfloat);
      ARGS_ELMT_DATA(&args).float_data = char_space;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_char_up_vec);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_CHAR_UP_VEC;
      ARGS_ELMT_SIZE(&args) = sizeof(Pvec);
      memcpy(&ARGS_ELMT_DATA(&args).vec, char_up_vec, sizeof(Pvec));
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_text_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (text_ind < 1) {
      ERR_REPORT(PHG_ERH, ERR100);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_TEXT_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = text_ind;
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_text_colr_ind);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else if (colr_ind < 0) {
      ERR_REPORT(PHG_ERH, ERR113);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_TEXT_COLR_IND;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = colr_ind;
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_int_colr
 *
 * DESCR:	Creates a new element - Facet Color Attribute
 * RETURNS:	N/A
 */

void pset_int_colr(
   Pgcolr *colr
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_int_colr);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_INT_COLR;
      ARGS_ELMT_SIZE(&args) = sizeof(Pgcolr);
      memcpy(&ARGS_ELMT_DATA(&args).colr, colr, sizeof(Pgcolr));
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_line_colr
 *
 * DESCR:	Creates a new element - Line Color Attribute
 * RETURNS:	N/A
 */

void pset_line_colr(
   Pgcolr *colr
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_line_colr);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_LINE_COLR;
      ARGS_ELMT_SIZE(&args) = sizeof(Pgcolr);
      memcpy(&ARGS_ELMT_DATA(&args).colr, colr, sizeof(Pgcolr));
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_marker_colr
 *
 * DESCR:	Creates a new element - Marker Color Attribute
 * RETURNS:	N/A
 */

void pset_marker_colr(
   Pgcolr *colr
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_marker_colr);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_MARKER_COLR;
      ARGS_ELMT_SIZE(&args) = sizeof(Pgcolr);
      memcpy(&ARGS_ELMT_DATA(&args).colr, colr, sizeof(Pgcolr));
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_edge_colr
 *
 * DESCR:	Creates a new element - Edge Color Attribute
 * RETURNS:	N/A
 */

void pset_edge_colr(
   Pgcolr *colr
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_edge_colr);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_EDGE_COLR;
      ARGS_ELMT_SIZE(&args) = sizeof(Pgcolr);
      memcpy(&ARGS_ELMT_DATA(&args).colr, colr, sizeof(Pgcolr));
      phg_add_el(PHG_CSS, &args);
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

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_exec_struct);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_EXEC_STRUCT;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = struct_id;
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_light_src_state
 *
 * DESCR:	Creates a new element - Set light source state
 * RETURNS:	N/A
 */

void pset_light_src_state(
   Pint_list *activation,
   Pint_list *deactivation
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_light_src_state);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_LIGHT_SRC_STATE;
      ARGS_ELMT_SIZE(&args) = 2 * sizeof(Pint) +
          sizeof(Pint) * activation->num_ints +
          sizeof(Pint) * deactivation->num_ints;
      memcpy(&ARGS_ELMT_DATA(&args).lss.activation,
             activation,
             sizeof(Plss));
      memcpy(&ARGS_ELMT_DATA(&args).lss.deactivation,
             deactivation,
             sizeof(Plss));
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_int_shad_meth
 *
 * DESCR:	Creates a new element - Set interiour shading method
 * RETURNS:	N/A
 */

void pset_int_shad_meth(
   Pint shad_meth
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_int_shad_meth);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_INT_SHAD_METH;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = shad_meth;
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_refl_eqn
 *
 * DESCR:	Creates a new element - Set surface reflectance equation
 * RETURNS:	N/A
 */

void pset_refl_eqn(
   Pint refl_equ
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_refl_eqn);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_INT_REFL_EQN;
      ARGS_ELMT_SIZE(&args) = sizeof(Pint);
      ARGS_ELMT_DATA(&args).int_data = refl_equ;
      phg_add_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pset_refl_props
 *
 * DESCR:	Creates a new element - Set surface reflectance properties
 * RETURNS:	N/A
 */

void pset_refl_props(
   Prefl_props *refl_props
   )
{
   Phg_args_add_el args;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_set_refl_props);

   if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      ERR_REPORT(PHG_ERH, ERR5);
   }
   else {
      ARGS_ELMT_TYPE(&args) = PELEM_REFL_PROPS;
      ARGS_ELMT_SIZE(&args) = sizeof(Prefl_props);
      memcpy(&ARGS_ELMT_DATA(&args).props, refl_props, sizeof(Prefl_props));
      phg_add_el(PHG_CSS, &args);
   }
}

