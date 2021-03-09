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

#ifndef _wsglP_h
#define _wsglP_h

#include <stdint.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/ws.h>
#include <phigs/util.h>
#include <GL/gl.h>

#define WS_CLEAR_AREA_OFFSET   2.0
#define WS_FILL_AREA_OFFSET    1.0

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
   Pattr_group   bundl_group;
   Pattr_group   indiv_group;
   Pfloat        char_ht;
   Ptext_path    text_path;
   Ptext_align   text_align;
   Pvec          char_up_vec;
   Pdisting_mode disting_mode;
   Pcull_mode    cull_mode;
   Nset          asf_nameset;
   uint32_t      ast_buf[1];
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
   Pint       lighting;
   Nset       lightstat;
   uint32_t   lightstat_buf[1];
} Ws_struct;

typedef struct {
   int     used;
   Nameset incl;
   Nameset excl;
} Ws_filter;

typedef struct {
   Pint_style int_style;
   Pint       int_style_ind;
   Pint       int_shad_meth;
} Ws_dev_st;

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
   Ws_dev_st       dev_st;
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
 * wsgl_set_asf
 *
 * DESCR:       Setup asf
 * RETURNS:     N/A
 */

void wsgl_set_asf(
   Ws_attr_st *ast,
   void *asf_info
   );

/*******************************************************************************
 * wsgl_set_colr
 *
 * DESCR:       Set colour value
 * RETURNS:     N/A
 */

void wsgl_set_colr(
   Pint colr_type,
   Pcoval *colr
   );

/*******************************************************************************
 * wsgl_set_gcolr
 *
 * DESCR:       Set colour
 * RETURNS:     N/A
 */

void wsgl_set_gcolr(
   Pgcolr *gcolr
   );

/*******************************************************************************
 * wsgl_colr_from_gcolr
 *
 * DESCR:       Get colour value from Pgcolr
 * RETURNS:     N/A
 */

void wsgl_colr_from_gcolr(
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
 * wsgl_update_projection
 *
 * DESCR:       Update projection matrix
 * RETURNS:     N/A
 */

void wsgl_update_projection(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_update_modelview
 *
 * DESCR:       Update modelview matrix
 * RETURNS:     N/A
 */

void wsgl_update_modelview(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_set_view_ind
 *
 * DESCR:       Setup view
 * RETURNS:     N/A
 */

void wsgl_set_view_ind(
   Ws *ws,
   Pint ind
   );

/*******************************************************************************
 * wsgl_update_hlhsr_id
 *
 * DESCR:       Update depth buffer checking flag
 * RETURNS:     N/A
 */

void wsgl_update_hlhsr_id(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_set_line_ind
 *
 * DESCR:       Setup line index
 * RETURNS:     N/A
 */

void wsgl_set_line_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * wsgl_setup_line_attr
 *
 * DESCR:       Setup line attributes
 * RETURNS:     N/A
 */

void wsgl_setup_line_attr(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_set_int_ind
 *
 * DESCR:       Setup interior index
 * RETURNS:     N/A
 */

void wsgl_set_int_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * wsgl_get_int_colr
 *
 * DESCR:       Get interior colur
 * RETURNS:     Pointer to interiour colour
 */

Pgcolr* wsgl_get_int_colr(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_get_int_style
 *
 * DESCR:       Get interior style
 * RETURNS:     Interiour style
 */

Pint_style wsgl_get_int_style(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_int_style
 *
 * DESCR:       Setup interior style
 * RETURNS:     N/A
 */

void wsgl_setup_int_style(
   Pint_style style
   );

/*******************************************************************************
 * wsgl_setup_int_attr_nocol
 *
 * DESCR:       Setup interior attributes without color 
 * RETURNS:     N/A
 */

void wsgl_setup_int_attr_nocol(
   Ws *ws,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_int_attr
 *
 * DESCR:       Setup interior attributes 
 * RETURNS:     N/A
 */

void wsgl_setup_int_attr(
   Ws *ws,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_get_back_int_colr
 * 
 * DESCR:       Get backface interior colur
 * RETURNS:     Pointer to interiour colour
 */
 
Pgcolr* wsgl_get_back_int_colr(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_back_int_attr_nocol
 *
 * DESCR:       Setup backface interior attributes without color
 * RETURNS:     N/A
 */

void wsgl_setup_back_int_attr_nocol(
   Ws *ws,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_int_refl_props
 *
 * DESCR:       Setup surface reflection and colour properties
 * RETURNS:     N/A
 */

void wsgl_setup_int_refl_props(
   Pint colr_type,
   Pcoval *colr,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_int_colr
 *
 * DESCR:       Setup surface colour
 * RETURNS:     Lighting state
 */

int wsgl_setup_int_colr(
   Ws *ws,
   Pint colr_type,
   Pcoval *colr,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_int_attr_plus
 *
 * DESCR:       Setup interiour attributes for PHIGS Plus
 * RETURNS:     Lighting state
 */

int wsgl_setup_int_attr_plus(
   Ws *ws,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_back_int_refl_props
 *
 * DESCR:       Setup backface surface reflection and colour properties
 * RETURNS:     N/A
 */

void wsgl_setup_back_int_refl_props(
   Pint colr_type,
   Pcoval *colr,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_back_int_colr
 *
 * DESCR:       Setup back-surface colour
 * RETURNS:     Lighting state
 */

int wsgl_setup_back_int_colr(
   Ws *ws,
   Pint colr_type,
   Pcoval *colr,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_back_int_attr_plus
 *
 * DESCR:       Setup backface interiour attributes for PHIGS Plus
 * RETURNS:     Lighting state
 */

int wsgl_setup_back_int_attr_plus(
   Ws *ws,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_set_edge_ind
 *
 * DESCR:       Setup edge index
 * RETURNS:     N/A
 */

void wsgl_set_edge_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * wsgl_get_edge_flag
 *
 * DESCR:       Get edge flag
 * RETURNS:     Edge flag
 */

Pedge_flag wsgl_get_edge_flag(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_get_edge_width
 *
 * DESCR:       Get edge width
 * RETURNS:     Edge width
 */

Pfloat wsgl_get_edge_width(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_edge_attr
 *
 * DESCR:       Setup edge attributes 
 * RETURNS:     N/A
 */

void wsgl_setup_edge_attr(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_set_marker_ind
 *
 * DESCR:       Setup marker index
 * RETURNS:     N/A
 */

void wsgl_set_marker_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * wsgl_setup_marker_attr
 *
 * DESCR:       Setup marker attributes 
 * RETURNS:     N/A
 */

void wsgl_setup_marker_attr(
   Ws_attr_st *ast,
   Pint *type,
   Pfloat *size
   );

/*******************************************************************************
 * wsgl_setup_background
 *
 * DESCR:       Setup background colour 
 * RETURNS:     N/A
 */

void wsgl_setup_background(
   Ws *ws
   );

/*******************************************************************************
 * wsgl_set_text_ind
 *
 * DESCR:       Setup text index
 * RETURNS:     N/A
 */

void wsgl_set_text_ind(
   Ws *ws,
   Pattr_group *attr_group,
   Pint ind
   );

/*******************************************************************************
 * wsgl_get_text_prec
 *
 * DESCR:       Get text precision
 * RETURNS:     Text precision
 */

Ptext_prec wsgl_get_text_prec(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_setup_text_attr
 *
 * DESCR:       Setup text attributes
 * RETURNS:     N/A
 */

void wsgl_setup_text_attr(
   Ws_attr_st *ast,
   Phg_font **fnt,
   Pfloat *char_expan
   );

/*******************************************************************************
 * wsgl_get_char_space
 *
 * DESCR:       Get char spacing
 * RETURNS:     Character spacing
 */

Pfloat wsgl_get_char_space(
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_add_names_set
 *
 * DESCR:       Add names to nameset
 * RETURNS:     N/A
 */

void wsgl_add_names_set(
   Ws *ws,
   void *names
   );

/*******************************************************************************
 * wsgl_remove_names_set
 *
 * DESCR:       Remove names from nameset
 * RETURNS:     N/A
 */

void wsgl_remove_names_set(
   Ws *ws,
   void *names
   );

/*******************************************************************************
 * wsgl_polymarker
 *
 * DESCR:       Draw markers
 * RETURNS:     N/A
 */

void wsgl_polymarker(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_polymarker3
 *
 * DESCR:       Draw markers 3D
 * RETURNS:     N/A
 */

void wsgl_polymarker3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_polyline
 *
 * DESCR:       Draw lines
 * RETURNS:     N/A
 */

void wsgl_polyline(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_polyline3
 *
 * DESCR:       Draw lines 3D
 * RETURNS:     N/A
 */

void wsgl_polyline3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_clear_area3
 *
 * DESCR:       Clear area 3D
 * RETURNS:     N/A
 */

void wsgl_clear_area3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_clear_area_set3
 *
 * DESCR:       Clear area set 3D
 * RETURNS:     N/A
 */

void wsgl_clear_area_set3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_fill_area
 *
 * DESCR:       Draw fill area
 * RETURNS:     N/A
 */

void wsgl_fill_area(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_fill_area3
 *
 * DESCR:       Draw fill area 3D
 * RETURNS:     N/A
 */

void wsgl_fill_area3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_back_area3
 *
 * DESCR:       Draw backface area 3D
 * RETURNS:     N/A
 */

void wsgl_back_area3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_fill_area_set
 *
 * DESCR:       Draw fill area set
 * RETURNS:     N/A
 */

void wsgl_fill_area_set(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_fill_area_set3
 *
 * DESCR:       Draw fill area set 3D
 * RETURNS:     N/A
 */

void wsgl_fill_area_set3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_edge_area
 *
 * DESCR:       Draw fill area edge
 * RETURNS:     N/A
 */

void wsgl_edge_area(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_edge_area3
 *
 * DESCR:       Draw fill area edge 3D
 * RETURNS:     N/A
 */

void wsgl_edge_area3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_edge_area_set
 *
 * DESCR:       Draw fill area set edge
 * RETURNS:     N/A
 */

void wsgl_edge_area_set(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_text
 *
 * DESCR:       Draw text
 * RETURNS:     N/A
 */

void wsgl_text(
   Ws *ws,
   void *tdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_edge_area_set3
 *
 * DESCR:       Draw fill area set edge 3D
 * RETURNS:     N/A
 */

void wsgl_edge_area_set3(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_clear_area_set3_data
 *
 * DESCR:       Clear fill area set with data 3D
 * RETURNS:     N/A
 */

void wsgl_clear_area_set3_data(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_fill_area_set3_data_front
 *
 * DESCR:       Draw fill area set with data 3D front faces
 * RETURNS:     N/A
 */

void wsgl_fill_area_set3_data_front(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_fill_area_set3_data_back
 *
 * DESCR:       Draw fill area set with data 3D back faces
 * RETURNS:     N/A
 */

void wsgl_fill_area_set3_data_back(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_edge_area_set3_data
 *
 * DESCR:       Draw fill area set edges with data 3D
 * RETURNS:     N/A
 */

void wsgl_edge_area_set3_data(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_set_of_clear_area_set3_data
 *
 * DESCR:       Clear set of fill area set with data 3D
 * RETURNS:     N/A
 */

void wsgl_set_of_clear_area_set3_data(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_set_of_fill_area_set3_data_front
 *
 * DESCR:       Draw set of fill area set with data 3D front faces
 * RETURNS:     N/A
 */

void wsgl_set_of_fill_area_set3_data_front(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_set_of_fill_area_set3_data_back
 *
 * DESCR:       Draw set of fill area set with data 3D back faces
 * RETURNS:     N/A
 */

void wsgl_set_of_fill_area_set3_data_back(
   Ws *ws,
   void *pdata,
   Ws_attr_st *ast
   );

/*******************************************************************************
 * wsgl_set_of_edge_area_set3_data
 *
 * DESCR:       Draw set of fill area set edges with data 3D
 * RETURNS:     N/A
 */

void wsgl_set_of_edge_area_set3_data(
   Ws *ws,
   void *pdata,
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
 * wsgl_update_light_src_state
 *
 * DESCR:       Update light source state for workstation
 * RETURNS:     N/A
 */

void wsgl_update_light_src_state(
   Ws *ws
   );

extern Phg_font *fnt_fonts[];
extern unsigned char *wsgl_hatch_tbl[];

#endif /* _wsglP_h */

