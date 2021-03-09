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
   Phg_args_add_el args;
   Pint i;
   unsigned facet_size, vertex_size;
   Pint *data;
   char *tp;
   Pint num_vertices;

   if (phg_entry_check(ERR5, Pfn_fill_area_set3_data)) {
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
               facet_size = sizeof(Pconorm3);
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

         args.el_type = PELEM_FILL_AREA_SET3_DATA;
         args.el_size = 5 * sizeof(Pint) + facet_size;

         if (eflag == PEDGE_VISIBILITY) {
            for (i = 0; i < nfa; i++) {
               args.el_size += sizeof(Pint);   /* Pint num_edges */
               args.el_size += edata[i].num_edges * sizeof(Pedge_flag);
            }
         }

         for (i = 0; i < nfa; i++) {
            args.el_size += sizeof(Pint);      /* Pint num_vertices */
            args.el_size += vdata[i].num_vertices * vertex_size;
         }

         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            data[0] = fflag;
            data = &data[1];
            data[0] = eflag;
            data = &data[1];
            data[0] = vflag;
            data = &data[1];
            data[0] = colr_type;
            tp = (char *) &data[1];

            switch(fflag) {
               case PFACET_COLOUR:
                  memcpy(tp, &fdata->colr, sizeof(Pcoval));
                  tp += sizeof(Pcoval);
                  break;

               case PFACET_NORMAL:
                  memcpy(tp, &fdata->norm, sizeof(Pvec3));
                  tp += sizeof(Pvec3);
                  break;

               case PFACET_COLOUR_NORMAL:
                  memcpy(tp, &fdata->conorm, sizeof(Pconorm3));
                  tp += sizeof(Pconorm3);
                  break;

               default:
                  break;
            }

            data = (Pint *) tp;
            data[0] = nfa;
            tp = (char *) &data[1];

            if (eflag == PEDGE_VISIBILITY) {
               for (i = 0; i < nfa; i++) {
                  num_vertices = edata[i].num_edges;
                  data = (Pint *) tp;
                  data[0] = num_vertices;
                  tp = (char *) &data[1];
                  memcpy(tp, edata[i].edgedata.edges,
                         sizeof(Pedge_flag) * num_vertices);
                  tp += sizeof(Pedge_flag) * num_vertices;
               }
            }

            for (i = 0; i < nfa; i++) {
               num_vertices = vdata[i].num_vertices;

               data = (Pint *) tp;
               data[0] = num_vertices;
               tp = (char *) &data[1];

               switch (vflag) {
                  case PVERT_COORD:
                     memcpy(tp, vdata[i].vertex_data.points,
                            num_vertices * sizeof(Ppoint3));
                     tp += num_vertices * sizeof(Ppoint3);
                     break;

                  case PVERT_COORD_COLOUR:
                     memcpy(tp, vdata[i].vertex_data.ptcolrs,
                            num_vertices * sizeof(Pptco3));
                     tp += num_vertices * sizeof(Pptco3);
                     break;

                  case PVERT_COORD_NORMAL:
                     memcpy(tp, vdata[i].vertex_data.ptnorms,
                            num_vertices * sizeof(Pptnorm3));
                     tp += num_vertices * sizeof(Pptnorm3);
                     break;

                  case PVERT_COORD_COLOUR_NORMAL:
                     memcpy(tp, vdata[i].vertex_data.ptconorms,
                            num_vertices * sizeof(Pptconorm3));
                     tp += num_vertices * sizeof(Pptconorm3);
                     break;

                  default:
                     break;
               }
            }

            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_of_fill_area_set3_data
 *
 * DESCR:	Creates a new element - Set of fill area set with data 3D
 * RETURNS:	N/A
 */

void pset_of_fill_area_set3_data(
   Pint fflag,
   Pint eflag,
   Pint vflag,
   Pint colr_type,
   Pint num_sets,
   Pfacet_data_arr3 *fdata,
   Pedge_data_list_list *edata,
   Pint_list_list *vlist,
   Pfacet_vdata_list3 *vdata
   )
{
   Phg_args_add_el args;
   Pint i, j;
   unsigned facet_size, vertex_size;
   Pint *data;
   char *tp;
   Pint num_lists, num_vertices;

   if (phg_entry_check(ERR5, Pfn_set_of_fill_area_set3_data)) {
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
               facet_size = sizeof(Pconorm3);
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

         args.el_type = PELEM_SET_OF_FILL_AREA_SET3_DATA;
         args.el_size = 5 * sizeof(Pint) + num_sets * facet_size;

         if (eflag == PEDGE_VISIBILITY) {
            for (i = 0; i < num_sets; i++) {
               args.el_size += sizeof(Pint);      /* Pint num_lists */
               for (j = 0; j < edata[i].num_lists; j++) {
                  args.el_size += sizeof(Pint);   /* Pint num_edges */
                  args.el_size += edata[i].edgelist[j].num_edges *
                                  sizeof(Pedge_flag);
               }
            }
         }

         for (i = 0; i < num_sets; i++) {
            args.el_size += sizeof(Pint);      /* Pint num_lists */
            for (j = 0; j < vlist[i].num_lists; j++) {
               args.el_size += sizeof(Pint);   /* Pint num_ints */
               args.el_size += vlist[i].lists[j].num_ints * sizeof(Pint);
            }
         }

         args.el_size += sizeof(Pint);         /* Pint num_vertices */
         args.el_size += vdata->num_vertices * vertex_size;

         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;

            data[0] = fflag;
            data = &data[1];
            data[0] = eflag;
            data = &data[1];
            data[0] = vflag;
            data = &data[1];
            data[0] = colr_type;
            data = &data[1];
            data[0] = num_sets;
            tp = (char *) &data[1];

            switch(fflag) {
               case PFACET_COLOUR:
                  memcpy(tp, fdata->colrs, sizeof(Pcoval) * num_sets);
                  tp += sizeof(Pcoval) * num_sets;
                  break;

               case PFACET_NORMAL:
                  memcpy(tp, fdata->norms, sizeof(Pvec3) * num_sets);
                  tp += sizeof(Pvec3) * num_sets;
                  break;

               case PFACET_COLOUR_NORMAL:
                  memcpy(tp, fdata->conorms, sizeof(Pconorm3) * num_sets);
                  tp += sizeof(Pconorm3) * num_sets;
               break;

               default:
                  break;
            }

            if (eflag == PEDGE_VISIBILITY) {
               for (i = 0; i < num_sets; i++) {
                  data = (Pint *) tp;
                  num_lists = edata[i].num_lists;
                  data[0] = num_lists;
                  tp = (char *) &data[1];
                  for (j = 0; j < num_lists; j++) {
                     num_vertices = edata[i].edgelist[j].num_edges;
                     data = (Pint *) tp;
                     data[0] = num_vertices;
                     tp = (char *) &data[1];
                     memcpy(tp, edata[i].edgelist[j].edgedata.edges,
                            sizeof(Pedge_flag) * num_vertices);
                     tp += sizeof(Pedge_flag) * num_vertices;
                  }
               }
            }

            for (i = 0; i < num_sets; i++) {
               data = (Pint *) tp;
               num_lists = vlist[i].num_lists;
               data[0] = num_lists;
               tp = (char *) &data[1];
               for (j = 0; j < num_lists; j++) {
                  num_vertices = vlist[i].lists[j].num_ints;
                  data = (Pint *) tp;
                  data[0] = num_vertices;
                  tp = (char *) &data[1];
                  memcpy(tp, vlist[i].lists[j].ints,
                         sizeof(Pint) * num_vertices);
                  tp += sizeof(Pint) * num_vertices;
               }
            }

            num_vertices = vdata->num_vertices;

            data = (Pint *) tp;
            data[0] = num_vertices;
            tp = (char *) &data[1];

            switch (vflag) {
               case PVERT_COORD:
                  memcpy(tp, vdata->vertex_data.points,
                         num_vertices * sizeof(Ppoint3));
                  break;

               case PVERT_COORD_COLOUR:
                  memcpy(tp, vdata->vertex_data.ptcolrs,
                         num_vertices * sizeof(Pptco3));
                  break;

               case PVERT_COORD_NORMAL:
                  memcpy(tp, vdata->vertex_data.ptnorms,
                         num_vertices * sizeof(Pptnorm3));
                  break;

               case PVERT_COORD_COLOUR_NORMAL:
                  memcpy(tp, vdata->vertex_data.ptconorms,
                         num_vertices * sizeof(Pptconorm3));
                  break;

               default:
                  break;
            }

            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_back_int_style
 *
 * DESCR:	Creates a new element - Backface Interiour Style
 * RETURNS:	N/A
 */

void pset_back_int_style(
   Pint_style int_style
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_back_int_style)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_BACK_INT_STYLE;
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
 * pset_back_int_style_ind
 *
 * DESCR:	Creates a new element - Backface Interiour Pattern Index
 * RETURNS:	N/A
 */

void pset_back_int_style_ind(
   Pint int_style_ind
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_back_int_style_ind)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else if (int_style_ind < 1) {
         ERR_REPORT(PHG_ERH, ERR112);
      }
      else {
         args.el_type = PELEM_BACK_INT_STYLE_IND;
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

   if (phg_entry_check(ERR5, Pfn_set_int_colr)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_INT_COLR;
         args.el_size = sizeof(Pgcolr);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, colr, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_back_int_colr
 *
 * DESCR:	Creates a new element - Backface Color Attribute
 * RETURNS:	N/A
 */

void pset_back_int_colr(
   Pgcolr *colr
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_back_int_colr)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_BACK_INT_COLR;
         args.el_size = sizeof(Pgcolr);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, colr, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
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

   if (phg_entry_check(ERR5, Pfn_set_line_colr)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_LINE_COLR;
         args.el_size = sizeof(Pgcolr);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, colr, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
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

   if (phg_entry_check(ERR5, Pfn_set_marker_colr)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_MARKER_COLR;
         args.el_size = sizeof(Pgcolr);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, colr, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
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

   if (phg_entry_check(ERR5, Pfn_set_edge_colr)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_EDGE_COLR;
         args.el_size = sizeof(Pgcolr);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, colr, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_text_colr
 *
 * DESCR:	Creates a new element - Text Color Attribute
 * RETURNS:	N/A
 */

void pset_text_colr(
   Pgcolr *colr
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_text_colr)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_TEXT_COLR;
         args.el_size = sizeof(Pgcolr);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, colr, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
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
   Pint n1, n2;
   Pint *data;

   if (phg_entry_check(ERR5, Pfn_set_light_src_state)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_LIGHT_SRC_STATE;
         args.el_size = 2 * sizeof(Pint) +
            sizeof(Pint) * activation->num_ints +
            sizeof(Pint) * deactivation->num_ints;
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            data = (Pint *) args.el_data;
            n1 = activation->num_ints;
            n2 = deactivation->num_ints;
            data[0] = n1;
            data = &data[1];
            memcpy(data, activation->ints, sizeof(Pint) * n1);
            data = &data[n1];
            data[0] = n2;
            data = &data[1];
            memcpy(data, deactivation->ints, sizeof(Pint) * n2);
            phg_add_el(PHG_CSS, &args);
         }
      }
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

   if (phg_entry_check(ERR5, Pfn_set_int_shad_meth)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_INT_SHAD_METH;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &shad_meth, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_back_int_shad_meth
 *
 * DESCR:	Creates a new element - Set backface interiour shading method
 * RETURNS:	N/A
 */

void pset_back_int_shad_meth(
   Pint shad_meth
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_back_int_shad_meth)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_BACK_INT_SHAD_METH;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &shad_meth, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
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

   if (phg_entry_check(ERR5, Pfn_set_refl_eqn)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_INT_REFL_EQN;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &refl_equ, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_back_refl_eqn
 *
 * DESCR:	Creates a new element - Set backsurface reflectance equation
 * RETURNS:	N/A
 */

void pset_back_refl_eqn(
   Pint refl_equ
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_back_refl_eqn)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_BACK_INT_REFL_EQN;
         args.el_size = sizeof(Pint);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &refl_equ, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
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

   if (phg_entry_check(ERR5, Pfn_set_refl_props)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_REFL_PROPS;
         args.el_size = sizeof(Prefl_props);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, refl_props, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_back_refl_props
 *
 * DESCR:	Creates a new element - Set backsurface reflectance properties
 * RETURNS:	N/A
 */

void pset_back_refl_props(
   Prefl_props *refl_props
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_back_refl_props)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_BACK_REFL_PROPS;
         args.el_size = sizeof(Prefl_props);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, refl_props, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_face_disting_mode
 *
 * DESCR:	Creates a new element - Set facet distinguish mode
 * RETURNS:	N/A
 */

void pset_face_disting_mode(
   Pdisting_mode disting_mode
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_face_disting_mode)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_FACE_DISTING_MODE;
         args.el_size = sizeof(Pdisting_mode);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            memcpy(args.el_data, &disting_mode, args.el_size);
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

/*******************************************************************************
 * pset_face_cull_mode
 *
 * DESCR:	Creates a new element - Set face culling mode
 * RETURNS:	N/A
 */

void pset_face_cull_mode(
   Pcull_mode cull_mode
   )
{
   Phg_args_add_el args;

   if (phg_entry_check(ERR5, Pfn_set_face_cull_mode)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.el_type = PELEM_FACE_CULL_MODE;
         args.el_size = sizeof(Pcull_mode);
         if (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, args.el_size)) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.el_data = PHG_SCRATCH.buf;
            *((Pint *) args.el_data) = (Pint) cull_mode;
            phg_add_el(PHG_CSS, &args);
         }
      }
   }
}

