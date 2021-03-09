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

#ifndef _ws_h
#define _ws_h

#include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <GL/glx.h>
#include <phigs/util.h>
#include <phigs/ws_inp.h>

#define NUM_DEFERRAL            5
#define NUM_MODIFICATION        3
#define NUM_SELECTABLE_STRUCTS  256
#define WS_MAX_NAMES_IN_NAMESET 1024
#define WS_MAX_LIGHT_SRC        8

typedef enum {
   PHG_TIME_NOW,
   PHG_TIME_BIG,
   PHG_TIME_BIL,
   PHG_TIME_ATI,
   PHG_TIME_NUM
} Ws_update_time;

typedef enum {
   PHG_UPDATE_ACCURATE,
   PHG_UPDATE_UWOR,
   PHG_UPDATE_UQUM,
   PHG_UPDATE_NOTHING,
   PHG_UPDATE_IF_IG,
   PHG_UPDATE_IF_IL,
   PHG_UPDATE_IF_INCORRECT,
   ASSURE_CORRECT,
   PHG_UPDATE_NUM
} Ws_update_action;

typedef enum {
   WS_PRE_CSS_DELETE,
   WS_POST_CSS_DELETE
} Ws_delete_flag;

typedef enum {
   WS_INV_NOT_CURRENT,
   WS_INV_CURRENT,
   WS_INT_NOT_INVERTIBLE
} Ws_inverse_state;


typedef struct {
   Pint x, y;
} Ws_point;

typedef struct {
   Node             node;
   Pint             id;
   Pint             priority;
   Pview_rep3       *viewrep;
   Ws_inverse_state npc_to_wc_state;
   Pmatrix3         npc_to_wc;
} Ws_view_ref;

typedef struct _Ws_post_str {
   Pfloat              disp_pri;
   Struct_handle       structh;
   struct _Ws_post_str *lower;
   struct _Ws_post_str *higher;
} Ws_post_str;

typedef struct {
   Ws_post_str lowest;
   Ws_post_str highest;
} Ws_posted_structs;

typedef Ws_update_action
   Ws_action_table[PHG_TIME_NUM][NUM_MODIFICATION][NUM_DEFERRAL];

typedef Ws_action_table *Ws_action_table_ptr;

typedef struct {
   Ppoint3 scale;
   Ppoint3 offset;
} Ws_xform;

typedef struct {
   int unused;
} Wsa_output_ws;

typedef struct {
   Css_handle          cssh;

   Pvisual_st          vis_rep;
   Pdisp_surf_empty    surf_state;

   /* Window */
   Plimit3             ws_window;
   Plimit3             ws_viewport;
   Pupd_st             ws_window_pending;
   Pupd_st             ws_viewport_pending;
   Plimit3             req_ws_window;
   Plimit3             req_ws_viewport;
   Ws_xform            ws_xform;

   /* Views */
   Pupd_st             views_pending;
   List                pending_views;
   List                views;

   /* Structures */
   Ws_posted_structs   posted;

   Ws_update_action    now_action;
   Ws_action_table_ptr update_action_table;

   /* Render modes */
   Pupd_st             hlhsr_mode_pending;
   Pint                req_hlhsr_mode;
   Pint                cur_hlhsr_mode;
} Wsb_output_ws;

typedef struct {
   Pdefer_mode      def_mode;
   Pmod_mode        mod_mode;

   struct {
      Hash_table    marker;
      Hash_table    line;
      Hash_table    text;
      Hash_table    interior;
      Hash_table    edge;
      Hash_table    colour;
      Hash_table    view;
      Hash_table    light_source;
   } htab;

   struct {
      Nameset       invis_incl;
      Nameset       invis_excl;
   } nset;

   union {
      Wsa_output_ws a;
      Wsb_output_ws b;
   } model;
} Ws_output_ws;

struct _Wsgl;
typedef struct _Wsgl *Wsgl_handle;

typedef struct _Ws {
   Pint         id;
   Wst          *type;
   Pws_cat      category;
   Ws_output_ws out_ws;
   Ws_input_ws  in_ws;
   Pint         current_colour_model;
   Pint         num_active_input_devs;

   Err_handle   erh;
   Phg_scratch  scratch;

   /* Window system variables */
   Display      *display;
   Drawable     drawable_id;
   GLXContext   glx_context;
   Window       input_overlay_window;
   Wsgl_handle  render_context;
   int          has_double_buffer;
   XRectangle   ws_rect;
   Widget       shell;

   void         (*close)(
                   struct _Ws *ws
                   );
   void         (*redraw_all)(
                   struct _Ws *ws,
                   Pctrl_flag clear_control
                   );
   void         (*conditional_redraw)(
                   struct _Ws *ws
                   );
   void         (*repaint_all)(
                   struct _Ws *ws,
                   Pctrl_flag clear_control
                   );
   void         (*make_requested_current)(
                   struct _Ws *ws
                   );
   void         (*update)(
                   struct _Ws *ws,
                   Pregen_flag flag
                   );
   void         (*set_disp_update_state)(
                   struct _Ws *ws,
                   Pdefer_mode def_mode,
                   Pmod_mode mod_mode
                   );
   void         (*set_hlhsr_mode)(
                   struct _Ws *ws,
                   Pint mode
                   );
   void         (*set_rep)(
                   struct _Ws *ws,
                   Phg_args_rep_type type,
                   Phg_args_rep_data *rep);
   void         (*set_filter)(
                   struct _Ws *ws,
                   Phg_args_flt_type type,
                   Pint dev_id,
                   Pint_list *incl_set,
                   Pint_list *excl_set
                   );
   void         (*set_ws_window)(
                   struct _Ws *ws,
                   Pint two_d,
                   Plimit3 *limits
                   );
   void         (*set_ws_vp)(
                   struct _Ws *ws,
                   Pint two_d,
                   Plimit3 *limits
                   );
   void         (*add_el)(
                   struct _Ws *ws
                   );
   void         (*copy_struct)(
                   struct _Ws *ws,
                   El_handle first_el
                   );
   void         (*close_struct)(
                   struct _Ws *ws,
                   Struct_handle structh
                   );
   void         (*move_ep)(
                   struct _Ws *ws,
                   El_handle ep
                );
   int          (*delete_el)(
                   struct _Ws *ws,
                   Struct_handle structh,
                   El_handle elh1,
                   El_handle elh2,
                   Ws_delete_flag flag
                   );
   int          (*delete_struct)(
                   struct _Ws *ws,
                   Struct_handle structh,
                   Ws_delete_flag flag
                   );
   int          (*delete_struct_net)(
                   struct _Ws *ws,
                   Struct_handle structh,
                   Pref_flag reff,
                   Ws_delete_flag flag
                   );
   void         (*delete_all_structs) (
                   struct _Ws *ws
                   );
   void         (*post)(
                   struct _Ws *ws,
                   Struct_handle structh,
                   Pfloat priority,
                   int first_posting
                   );
   void         (*unpost)(
                    struct _Ws *ws,
                    Struct_handle structh
                    );
   void         (*unpost_all)(
                    struct _Ws *ws
                    );
   void         (*change_posting)(
                   struct _Ws *ws,
                   Struct_handle unpost,
                   Struct_handle post
                   );
   void         (*inq_posted)(
                   struct _Ws *ws,
                   Phg_ret *ret
                   );
   void         (*inq_disp_update_state)(
                   struct _Ws *ws,
                   Phg_ret *ret
                   );
   void         (*inq_hlhsr_mode)(
                   struct _Ws *ws,
                   Phg_ret *ret
                   );
   void         (*inq_representation)(
                   struct _Ws *ws,
                   Pint index,
                   Pinq_type how,
                   Phg_args_rep_type rep_type,
                   Phg_ret *ret
                   );
   void         (*set_view_input_priority)(
                   struct _Ws *ws,
                   Pint index,
                   Pint ref_index,
                   Prel_pri priority
                   );
   int          (*map_initial_points)(
                   struct _Ws *ws,
                   Pint view_index,
                   Pint *num_pts,
                   Ppoint3 *wc_pts,
                   XPoint *dwbl_pts
                   );
   int          (*resolve_locator)(
                   struct _Ws *ws,
                   Ws_point *dc_pt,
                   int determine_z,
                   Pint *view_index,
                   Ppoint3 *wc_pt
                   );
   int          (*point_in_viewport)(
                   struct _Ws *ws,
                   XPoint *pt
                   );
   int         (*resolve_stroke)(
                   struct _Ws *ws,
                   Pint num_pts,
                   Ws_point *dc_pts,
                   int determine_z,
                   Pint *view_index,
                   Ppoint_list3 *wc_pts
                   );
   int          (*resolve_pick)(
                   struct _Ws *ws,
                   Ws_inp_pick *dev,
                   int echo,
                   Ws_point *dc_pt,
                   Ppick *pick
                   );

   /* Not used by all workstations */
   int          (*valid_pick_path)(
                   struct _Ws *ws,
                   Ppick *pick
                   );
   int          (*pick_enable)(
                   struct _Ws *ws,
                   Ws_inp_pick *dev
                   );
   void         (*pick_disable)(
                   struct _Ws *ws,
                   Ws_inp_pick *dev
                   );

   /* Initialized by input module */
   void         (*init_device)(
                   struct _Ws *ws,
                   Phg_args_inp_init_dev *args
                   );
   void         (*set_device_mode)(
                   struct _Ws *ws,
                   Phg_args_set_mode_data *args
                   );
   void         (*request_device)(
                   struct _Ws *ws,
                   Phg_args_idev_class idev_class,
                   Pint dev_num,
                   Phg_ret *ret
                   );
   void         (*sample_device)(
                   struct _Ws *ws,
                   Phg_args_idev_class idev_class,
                   Pint dev_num,
                   Phg_ret *ret
                   );
   void         (*input_repaint)(
                   struct _Ws *ws,
                   Pint num_rects,
                   XRectangle *rects
                   );
   void         (*inq_inp_dev_state)(
                   struct _Ws *ws,
                   Phg_args_idev_class idev_class,
                   Pint num,
                   Phg_ret *ret
                   );
} Ws;

#define WSB_NONE_POSTED(posted_ptr) \
   ((posted_ptr)->lowest.higher == &(posted_ptr)->highest)

#define WSB_SOME_POSTED(posted_ptr) \
   ((posted_ptr)->lowest.higher != &(posted_ptr)->highest)

#define WSB_CHECK_POSTED(posted_ptr) \
        assert(((posted_ptr)->lowest.higher == &(posted_ptr)->highest) \
                == ((posted_ptr)->highest.lower == &(posted_ptr)->lowest))

#define case_PHG_UPDATE_ACCURATE_or_IF_Ix	\
   case PHG_UPDATE_ACCURATE:			\
   case PHG_UPDATE_IF_IG:			\
   case PHG_UPDATE_IF_IL

#define WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, now_action_ptr)	\
{								\
   if ( *(now_action_ptr) == PHG_UPDATE_IF_IG ||		\
        *(now_action_ptr) == PHG_UPDATE_IF_IL)			\
      phg_wsb_resolve_now_action(ws, now_action_ptr);		\
}

#define WS_SET_WS_RECT(_wsh, _wattr)		\
{						\
   (_wsh)->ws_rect.x = (_wattr)->x;		\
   (_wsh)->ws_rect.y = (_wattr)->y;		\
   (_wsh)->ws_rect.width = (_wattr)->width;	\
   (_wsh)->ws_rect.height = (_wattr)->height;	\
}

#define WS_ANY_INP_DEV_ACTIVE(_wsh) \
   ((_wsh)->num_active_input_devs > 0)

#define WS_DRWBL_TO_DC2( _wsh, _dwp, _dcp ) \
    ((_dcp)->x = (_dwp)->x, \
     (_dcp)->y = (_wsh)->ws_rect.height - (_dwp)->y)

#define WS_NPC_TO_DC(_wsxf, _npc, _dc) \
    (_dc)->x = (_npc)->x * (_wsxf)->scale.x + (_wsxf)->offset.x; \
    (_dc)->y = (_npc)->y * (_wsxf)->scale.y + (_wsxf)->offset.y; \
    (_dc)->z = (_npc)->z * (_wsxf)->scale.z + (_wsxf)->offset.z;

#define WS_DC_TO_DRWBL2( _wsh, _dcp, _dwp ) \
    ((_dwp)->x = (_dcp)->x, \
     (_dwp)->y = (_wsh)->ws_rect.height - (_dcp)->y)

#define WS_DC_TO_NPC2(_wsxf, _dc, _npc) \
    (_npc)->x = ( (_dc)->x - (_wsxf)->offset.x) / (_wsxf)->scale.x; \
    (_npc)->y = ( (_dc)->y - (_wsxf)->offset.y) / (_wsxf)->scale.y;

#define WS_DC_TO_NPC(_wsxf, _dc, _npc) \
    (_npc)->x = ( (_dc)->x - (_wsxf)->offset.x) / (_wsxf)->scale.x; \
    (_npc)->y = ( (_dc)->y - (_wsxf)->offset.y) / (_wsxf)->scale.y; \
    (_npc)->z = ( (_dc)->z - (_wsxf)->offset.z) / (_wsxf)->scale.z;

#define WS_PT_IN_LIMIT2( lim, pt) \
    (  (pt)->x >= (lim)->x_min && (pt)->x <= (lim)->x_max \
    && (pt)->y >= (lim)->y_min && (pt)->y <= (lim)->y_max)

#define WS_PT_IN_LIMIT( lim, pt) \
    (  (pt)->x >= (lim)->x_min && (pt)->x <= (lim)->x_max \
    && (pt)->y >= (lim)->y_min && (pt)->y <= (lim)->y_max \
    && (pt)->z >= (lim)->z_min && (pt)->z <= (lim)->z_max)

Ws* phg_wsb_open_ws(
    Phg_args_open_ws *args,
    Phg_ret *ret
    );

void wsb_free_all_posted(
    Wsb_output_ws *owsb
    );

void wsb_destroy_ws(
    Ws *ws
    );

void phg_wsb_close_ws(
    Ws *ws
    );

void phg_wsb_redraw_all(
    Ws *ws,
    Pctrl_flag clear_control
    );

void phg_wsb_make_requested_current(
    Ws *ws
    );

void phg_wsb_repaint_all(
    Ws *ws,
    Pctrl_flag clear_control
    );

void phg_wsb_traverse_all_postings(
    Ws *ws
    );

void phg_wsb_traverse_net(
    Ws_handle ws,
    Struct_handle structp
    );

void phg_wsb_add_el(
    Ws *ws
    );

int phg_wsb_asti_update(
    Ws *ws,
    Pctrl_flag clear_control
    );

void phg_wsb_close_struct(
    Ws *ws,
    Struct_handle structh
    );

void phg_wsb_post(
    Ws *ws,
    Struct_handle structh,
    Pfloat priority,
    Pint first_posting
    );

void phg_wsb_change_posting(
    Ws *ws,
    Struct_handle unpost,
    Struct_handle post
    );

void phg_wsb_unpost(
    Ws *ws,
    Struct_handle structh
    );

void phg_wsb_unpost_all(
    Ws *ws
    );

void phg_wsb_delete_all_structs(
    Ws *ws
    );

int phg_wsb_delete_struct(
    Ws *ws,
    Struct_handle structh,
    Ws_delete_flag flag
    );

int phg_wsb_delete_struct_net(
    Ws *ws,
    Struct_handle structh,
    Pref_flag reff,
    Ws_delete_flag flag
    );

void phg_wsb_copy_struct(
    Ws *ws,
    El_handle first_el
    );

int phg_wsb_delete_el(
    Ws *ws,
    Struct_handle structh,
    El_handle elh1,
    El_handle elh2,
    Ws_delete_flag flag
    );

void phg_wsb_conditional_redraw(
    Ws *ws
    );

void phg_wsb_resolve_now_action(
    Ws *ws,
    Ws_update_action *now_action_ptr
    );

void phg_wsb_update(
    Ws *ws,
    Pregen_flag flag
    );

void phg_wsb_set_disp_update_state(
    Ws *ws,
    Pdefer_mode def_mode,
    Pmod_mode mod_mode
    );

void phg_wsb_set_hlhsr_mode(
    Ws *ws,
    Pint mode
    );

void phg_wsb_set_ws_window(
    Ws *ws,
    Pint two_d,
    Plimit3 *limits
    );

void phg_wsb_set_ws_vp(
    Ws *ws,
    Pint two_d,
    Plimit3 *limits
    );

void phg_wsb_set_rep(
    Ws *ws,
    Phg_args_rep_type type,
    Phg_args_rep_data *rep
    );

void phg_wsb_set_filter(
    Ws *ws,
    Phg_args_flt_type type,
    Pint dev_id,
    Pint_list *incl_set,
    Pint_list *excl_set
    );

void phg_wsb_inq_posted(
    Ws *ws,
    Phg_ret *ret
    );

void phg_wsb_inq_ws_xform(
    Ws *ws,
    Phg_ret *ret
    );

void phg_wsb_inq_disp_update_state(
    Ws *ws,
    Phg_ret *ret
    );

void phg_wsb_inq_hlhsr_mode(
    Ws *ws,
    Phg_ret *ret
    );

void phg_wsb_inq_rep(
    Ws *ws,
    Pint index,
    Pinq_type how,
    Phg_args_rep_type rep_type,
    Phg_ret *ret
    );

/*******************************************************************************
 * phg_wsb_set_view_input_priority
 *
 * DESCR:       Set priority of view relative another view
 * RETURNS:     N/A
 */

void phg_wsb_set_view_input_priority(
   Ws *ws,
   Pint index,
   Pint ref_index,
   Prel_pri priority
   );

/*******************************************************************************
 * phg_wsb_map_initial_points
 *
 * DESCR:       Map initial points
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_map_initial_points(
    Ws *ws,
    Pint view_index,
    Pint *num_pts,
    Ppoint3 *wc_pts,
    XPoint *dwbl_pts
    );

/*******************************************************************************
 * phg_wsb_resolve_locator
 *
 * DESCR:       Resolve locator device
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_resolve_locator(
    Ws *ws,
    Ws_point *dc_pt,
    int determine_z,
    Pint *view_index,
    Ppoint3 *wc_pt
    );

/*******************************************************************************
 * phg_wsb_point_in_viewport
 *
 * DESCR:       Test if point is within viewport
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_point_in_viewport(
    Ws *ws,
    XPoint *pt
    );

/*******************************************************************************
 * phg_wsb_resolve_stroke
 *
 * DESCR:       Resolve stroke device
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_resolve_stroke(
    Ws *ws,
    Pint num_pts,
    Ws_point *dc_pts,
    int determine_z,
    Pint *view_index,
    Ppoint_list3 *wc_pts
    );

/*******************************************************************************
 * phg_wsb_resolve_pick
 *
 * DESCR:       Resolve pick device
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_resolve_pick(
    Ws *ws,
    Ws_inp_pick *dev,
    int echo,
    Ws_point *dc_pt,
    Ppick *pick
    );

/*******************************************************************************
 * phg_wsb_create_LUTs
 *  
 * DESCR:       Create workstation lookup tables
 * RETURNS:     Non-zero on success
 */

int phg_wsb_create_LUTs(
    Ws *ws
    );

/*******************************************************************************
 * phg_wsb_destroy_LUTs
 *
 * DESCR:       Destroy workstation lookup tables
 * RETURNS:     N/A
 */

void phg_wsb_destroy_LUTs(
    Ws *ws
    );

/*******************************************************************************
 * phg_wsb_set_LUT_entry
 *
 * DESCR:       Set workstation table entry
 * RETURNS:     N/A
 */

void phg_wsb_set_LUT_entry(
    Ws *ws,
    Phg_args_rep_type type,
    Phg_args_rep_data *rep,
    Pgcolr *gcolr
    );

/*******************************************************************************
 * phg_wsb_inq_LUT_entry
 *
 * DESCR:       Get workstation table entry
 * RETURNS:     N/A
 */

void phg_wsb_inq_LUT_entry(
    Ws *ws,
    Pint index,
    Pinq_type type,
    Phg_args_rep_type rep_type,
    Phg_ret *ret,
    Pgcolr *gcolr,
    Pview_rep3 *vrep
    );

/*******************************************************************************
 * phg_wsb_set_name_set
 *
 * DESCR:       Set filter name set
 * RETURNS:     N/A
 */

void phg_wsb_set_name_set(
   Ws *ws,
   Phg_args_flt_type type,
   Pint dev_id,
   Pint_list *incl_set,
   Pint_list *excl_set
   );

#endif

