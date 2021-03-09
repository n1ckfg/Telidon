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

#ifndef _wsglP_h
#define _wsglP_h

#include <stdint.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/ws.h>
#include <phigs/util.h>
#include <GL/gl.h>

typedef struct {
   Pint x, y;
   Pfloat distance;
} Ws_hit_box;

typedef struct {
   Pint sid;
   Pint pickid;
   Pint offset;
} Ws_pick_elmt;

typedef enum {
   WS_RENDER_MODE_DRAW,
   WS_RENDER_MODE_SELECT
} Ws_render_mode;

typedef struct {
   Pattr_group  bundl_group;
   Pattr_group  indiv_group;
   Pfloat       char_ht;
   Ptext_path   text_path;
   Ptext_align  text_align;
   Pvec         char_up_vec;
   Nset         asf_nameset;
   uint32_t     ast_buf[1];
} Ws_attr_st;

typedef struct {
   Pint       id;
   Pint       offset;
   Pint       hlhsr_id;
   Ws_attr_st ast;
   Nset       cur_nameset;
   uint32_t   nameset_buf[WS_MAX_NAMES_IN_NAMESET / 32];
   Pview_rep3 view_rep;
   Pmatrix3   local_tran;
   Pmatrix3   global_tran;
   Pint       pick_id;
   Nset       lightstat;
   uint32_t   lightstat_buf[1];
} Ws_struct;

typedef struct {
   int     used;
   Nameset incl;
   Nameset excl;
} Ws_filter;

typedef struct _Wsgl {
   Plimit3         cur_win;
   int             win_changed;
   Plimit3         cur_vp;
   int             vp_changed;
   int             hlhsr_changed;
   Pint            hlhsr_mode;
   Pgcolr          background;
   Ws_render_mode  render_mode;
   Stack           struct_stack;
   Ws_struct       cur_struct;
   Pmatrix3        composite_tran;
   Pmatrix3        model_tran;
   Pmatrix3        pick_tran;
   Ws_filter       invis_filter;
   Ws_filter       pick_filter;
   Pint            select_size;
   GLuint          *select_buf;
} Wsgl;

/*******************************************************************************
 * wsgl_init
 *
 * DESCR:       Initialize renderer
 * RETURNS:     Non zero or zero on error
 */

int wsgl_init(
   Ws *ws,
   Pgcolr *background,
   Pint select_size
   );

/*******************************************************************************
 * wsgl_close
 *
 * DESCR:       Close 
 * RETURNS:     N/A
 */

void wsgl_close(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_set_window
 *
 * DESCR:       Set render window coordinates
 * RETURNS:     N/A
 */

void wsgl_set_window(
   Ws *ws,
   Plimit3 *win
   );

/*******************************************************************************
 * wsgl_set_viewport
 *
 * DESCR:       Set render window viewport
 * RETURNS:     N/A
 */

void wsgl_set_viewport(
   Ws *ws,
   Plimit3 *vp
   );

/*******************************************************************************
 * wsgl_set_hlhsr_mode
 *
 * DESCR:       Set render depth mode
 * RETURNS:     N/A
 */

void wsgl_set_hlhsr_mode(
   Ws *ws,
   Pint hlhsr_mode
   );

/*******************************************************************************
 * phg_set_asf
 *
 * DESCR:       Setup asf
 * RETURNS:     N/A
 */

void phg_set_asf(
   Ws_attr_st *ast,
   void *asf_info
   );

/*******************************************************************************
 * phg_set_colr
 *
 * DESCR:       Set colour value
 * RETURNS:     N/A
 */

void phg_set_colr(
   Pint colr_type,
   Pcoval *colr
   );

/*******************************************************************************
 * phg_set_gcolr
 *
 * DESCR:       Set colour
 * RETURNS:     N/A
 */

void phg_set_gcolr(
   Pgcolr *gcolr
   );

/*******************************************************************************
 * phg_colr_from_gcolr
 *
 * DESCR:       Get colour value from Pgcolr
 * RETURNS:     N/A
 */

void phg_colr_from_gcolr(
   Pcoval *pcoval,
   Pgcolr *gcolr
   );

/*******************************************************************************
 * wsgl_clear
 *
 * DESCR:       Clear render window
 * RETURNS:     N/A
 */

void wsgl_clear(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_flush
 *
 * DESCR:       Flush settings to render window
 * RETURNS:     N/A
 */

void wsgl_flush(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_begin_rendering
 *
 * DESCR:       Start a rendiering session for workstation
 * RETURNS:     N/A
 */

void wsgl_begin_rendering(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_end_rendering
 *
 * DESCR:       End a rendiering session
 * RETURNS:     N/A
 */

void wsgl_end_rendering(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_begin_structure
 *
 * DESCR:       Mark the beginning of a new structure element
 * RETURNS:     N/A
 */

void wsgl_begin_structure(
   Ws *ws,
   Pint struct_id
   );

/*******************************************************************************
 * wsgl_end_structure
 *
 * DESCR:       Mark the ending of a structure element
 * RETURNS:     N/A
 */

void wsgl_end_structure(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_render_element
 *
 * DESCR:       Render element to current workstation rendering window
 * RETURNS:     N/A
 */

void wsgl_render_element(
   Ws *ws,
   El_handle el
   );

/*******************************************************************************
 * wsgl_set_filter
 *
 * DESCR:       Set filter
 * RETURNS:     N/A
 */

void wsgl_set_filter(
   Ws *ws,
   Phg_args_flt_type type,
   Nameset incl,
   Nameset excl
   );

/*******************************************************************************
 * wsgl_begin_pick
 *
 * DESCR:       Begin pick process
 * RETURNS:     N/A
 */

void wsgl_begin_pick(
   Ws *ws,
   Ws_hit_box *box
   );

/*******************************************************************************
 * wsgl_end_pick
 *
 * DESCR:       End pick process
 * RETURNS:     N/A
 */

void wsgl_end_pick(
   Ws *ws,
   Pint *err_ind,
   Pint *depth,
   Ws_pick_elmt **elmts
   );

/*******************************************************************************
 * phg_update_projection
 *
 * DESCR:       Update projection matrix
 * RETURNS:     N/A
 */

void phg_update_projection(
   Ws *ws
   );

/*******************************************************************************
 * phg_update_modelview
 *
 * DESCR:       Update modelview matrix
 * RETURNS:     N/A
 */

void phg_update_modelview(
   Ws *ws
   );

/*******************************************************************************
 * phg_set_view_ind
 *
 * DESCR:       Setup view
 * RETURNS:     N/A
 */

void phg_set_view_ind(
   Ws *ws,
   Pint ind
   );

/*******************************************************************************
 * phg_update_hlhsr_id
 *
 * DESCR:       Update depth buffer checking flag
 * RETURNS:     N/A
 */

void phg_update_hlhsr_id(
   Ws *ws
   );

/*******************************************************************************
 * phg_set_line_ind
 *
 * DESCR:       Setup line index
 * RETURNS:     N/A
 */

void phg_set_line_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * phg_setup_line_attr
 *
 * DESCR:       Setup line attributes
 * RETURNS:     N/A
 */

void phg_setup_line_attr(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_set_int_ind
 *
 * DESCR:       Setup interior index
 * RETURNS:     N/A
 */

void phg_set_int_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * phg_get_int_style
 *
 * DESCR:       Get interior style
 * RETURNS:     Interiour style
 */

Pint_style phg_get_int_style(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_setup_int_nocol
 *
 * DESCR:       Setup interior attributes without color 
 * RETURNS:     N/A
 */

void phg_setup_int_attr_nocol(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_setup_int_attr
 *
 * DESCR:       Setup interior attributes 
 * RETURNS:     N/A
 */

void phg_setup_int_attr(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_set_polygon_offset
 *
 * DESCR:       Setup polygon offset helper function
 * RETURNS:     N/A
 */

void phg_set_polygon_offset(
   float w
   );

/*******************************************************************************
 * phg_get_facet_colr
 *
 * DESCR:       Get facet colour
 * RETURNS:     N/A
 */

void phg_get_facet_colr(
   Pcoval *colr,
   Pint fflag,
   Pfacet_data3 *fdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_get_int_refl_eqn
 *
 * DESCR:       Get interiour reflection equation
 * RETURNS:     N/A
 */

Pint phg_get_int_refl_eqn(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_get_refl_props
 *
 * DESCR:       Get surface reflectance properties
 * RETURNS:     Pointer to surface reflectance properties
 */

Prefl_props* phg_get_refl_props(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_set_edge_ind
 *
 * DESCR:       Setup edge index
 * RETURNS:     N/A
 */

void phg_set_edge_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * phg_get_edge_flag
 *
 * DESCR:       Get edge flag
 * RETURNS:     Edge flag
 */

Pedge_flag phg_get_edge_flag(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_get_edge_width
 *
 * DESCR:       Get edge width
 * RETURNS:     Edge width
 */

Pfloat phg_get_edge_width(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_setup_edge_attr
 *
 * DESCR:       Setup edge attributes 
 * RETURNS:     N/A
 */

void phg_setup_edge_attr(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_set_marker_ind
 *
 * DESCR:       Setup marker index
 * RETURNS:     N/A
 */

void phg_set_marker_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * phg_setup_marker_attr
 *
 * DESCR:       Setup marker attributes 
 * RETURNS:     N/A
 */

void phg_setup_marker_attr(
   Ws_attr_st *ast,
   Pint *type,
   Pfloat *size
   );

/*******************************************************************************
 * phg_setup_background
 *
 * DESCR:       Setup background colour 
 * RETURNS:     N/A
 */

void phg_setup_background(
   Ws *ws
   );

/*******************************************************************************
 * phg_set_text_ind
 *
 * DESCR:       Setup text index
 * RETURNS:     N/A
 */

void phg_set_text_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * phg_get_text_prec
 *
 * DESCR:       Get text precision
 * RETURNS:     Text precision
 */

Ptext_prec phg_get_text_prec(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_setup_text_attr
 *
 * DESCR:       Setup text attributes
 * RETURNS:     N/A
 */

void phg_setup_text_attr(
   Ws_attr_st *ast,
   Phg_font **fnt,
   Pfloat *char_expan
   );

/*******************************************************************************
 * phg_get_char_text_attr
 *
 * DESCR:       Get text attributes
 * RETURNS:     N/A
 */

void phg_get_char_text_attr(
   Ws_attr_st *ast,
   Pfloat *char_space
   );

/*******************************************************************************
 * phg_add_names_set
 *
 * DESCR:       Add names to nameset
 * RETURNS:     N/A
 */

void phg_add_names_set(
   Ws *ws,
   void *names
   );

/*******************************************************************************
 * phg_remove_names_set
 *
 * DESCR:       Remove names from nameset
 * RETURNS:     N/A
 */

void phg_remove_names_set(
   Ws *ws,
   void *names
   );

/*******************************************************************************
 * phg_draw_polymarker
 *
 * DESCR:       Draw markers
 * RETURNS:     N/A
 */

void phg_draw_polymarker(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_draw_polymarker3
 *
 * DESCR:       Draw markers 3D
 * RETURNS:     N/A
 */

void phg_draw_polymarker3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_draw_polyline
 *
 * DESCR:       Draw lines
 * RETURNS:     N/A
 */

void phg_draw_polyline(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_draw_polyline3
 *
 * DESCR:       Draw lines 3D
 * RETURNS:     N/A
 */

void phg_draw_polyline3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_draw_fill_area
 *
 * DESCR:       Draw fill area
 * RETURNS:     N/A
 */

void phg_draw_fill_area(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_draw_fill_area3
 *
 * DESCR:       Draw fill area 3D
 * RETURNS:     N/A
 */

void phg_draw_fill_area3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_draw_fill_area_set
 *
 * DESCR:       Draw fill area set
 * RETURNS:     N/A
 */

void phg_draw_fill_area_set(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_draw_fill_area_set3
 *
 * DESCR:       Draw fill area set 3D
 * RETURNS:     N/A
 */

void phg_draw_fill_area_set3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_draw_fill_area3_data
 *
 * DESCR:       Draw fill area width data 3D
 * RETURNS:     N/A
 */

void phg_draw_fill_area3_data(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * phg_draw_text
 *
 * DESCR:       Draw text
 * RETURNS:     N/A
 */

void phg_draw_text(
   Ws *ws,
   void *tdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_set_light_src_state
 *
 * DESCR:       Set light source state for workstation
 * RETURNS:     N/A
 */

void wsgl_set_light_src_state(
   Ws *ws,
   void *pdata
   );

/*******************************************************************************
 * wsgl_light_colr
 *
 * DESCR:       Perform lighting calculations and set colour for vertex
 * RETURNS:     N/A
 */

void wsgl_light_colr(
   Ws *ws,
   Pcoval *result,
   Pint refl_eqn,
   Prefl_props *refl_props,
   Pint colr_type,
   Pcoval *coval,
   Pvec3 *normal
   );

extern unsigned char *wsgl_hatch_tbl[];

#endif /* _wsglP_h */

