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

#ifndef _ws_inp_h
#define _ws_inp_h

#include <phigs/sin.h>
#include <phigs/util.h>

typedef struct {
   Pint         num;
   Pop_mode     mode;
   Pecho_switch esw;
   Ploc3        loc;
   Pint         pet;
   Plimit3      e_volume;
   Ploc_data3   record;
} Ws_inp_loc;

typedef struct {
   Pint         num;
   Pop_mode     mode;
   Pecho_switch esw;
   Ppick        pick;
   Pint         pet;
   Plimit3      e_volume;
   Ppick_data3  record;
   Ppath_order  order;
   Pfloat       ap_size;
   Pint         dev_type;
   Pint         measure;
   struct {
      Nameset   incl;
      Nameset   excl;
   } filter;
   Ppick_path   scratch_path;
} Ws_inp_pick;

typedef struct {
   Pint          num;
   Pop_mode      mode;
   Pecho_switch  esw;
   Pstroke3      stroke;
   Pint          pet;
   Plimit3       e_volume;
   Pstroke_data3 record;
} Ws_inp_stroke;

typedef struct {
   Pint         num;
   Pop_mode     mode;
   Pecho_switch esw;
   Pfloat       val;
   Pint         pet;
   Plimit3      e_volume;
   Pval_data3   record;
   char         *string_buf;
} Ws_inp_val;

typedef struct {
   Pint          num;
   Pop_mode      mode;
   Pecho_switch  esw;
   Pchoice       choice;
   Pint          pet;
   Plimit3       e_volume;
   Pint          strings_length;
   Pchoice_data3 record;
} Ws_inp_choice;

typedef struct {
   Pint          num;
   Pop_mode      mode;
   Pecho_switch  esw;
   Pint          length;
   char          *string;
   Pint          pet;
   Plimit3       e_volume;
   Pstring_data3 record;
} Ws_inp_string;

typedef union {
   Ws_inp_loc    *loc;
   Ws_inp_pick   *pik;
   Ws_inp_stroke *stk;
   Ws_inp_val    *val;
   Ws_inp_choice *cho;
   Ws_inp_string *str;
} Ws_inp_device_handle;

typedef struct {
   Phg_args_idev_class  dev_class;
   Pint                 dev_num;
   Phg_ret_inp_req_stat status;
   union {
      Ploc3             loc;
      Ppick             pick;
      Pstroke3          stroke;
      Pfloat            val;
      Pchoice           choice;
      Phg_string        string;
   } evt;
} Ws_inp_req;

typedef struct _Ws_input_ws {
   Pnum_in          num_devs;
   struct {
      Ws_inp_loc    *locator;
      Ws_inp_pick   *pick;
      Ws_inp_stroke *stroke;
      Ws_inp_val    *valuator;
      Ws_inp_choice *choice;
      Ws_inp_string *string;
   } devs;
   Sin_handle       sin_handle;
   Input_q_handle   input_queue;
   Ws_inp_req       input_request;
   Phg_scratch      scratch;
} Ws_input_ws;

#define WS_INP_DEV( _wsh, _class, _num ) \
    (&(_wsh)->in_ws.devs._class[(_num)-1])

#define SET_ECHO_AREA( _ev1, _ev2 ) \
    (_ev2).x_min = (_ev1).x_min; \
    (_ev2).x_max = (_ev1).x_max; \
    (_ev2).y_min = (_ev1).y_min; \
    (_ev2).y_max = (_ev1).y_max

#define MAP_MODE( _m) \
    ((_m) == POP_EVENT ? SIN_EVENT : \
        (_m) == POP_SAMPLE ? SIN_SAMPLE : SIN_REQUEST)

#define WSINP_DC_ECHO_TO_DRWBL_ECHO2( _ws, _ev_vdc, _ea_dc) \
    {   Ppoint  p; \
        p.x = (_ev_vdc)->x_min; \
        p.y = (_ev_vdc)->y_min; \
        WS_DC_TO_DRWBL2((_ws), &p, &(_ea_dc)->ll); \
        p.x = (_ev_vdc)->x_max; \
        p.y = (_ev_vdc)->y_max; \
        WS_DC_TO_DRWBL2((_ws), &p, &(_ea_dc)->ur); \
    }

#define WSINP_INIT_COMMON_FIELDS( stp, def) \
    stp->mode = POP_REQ; \
    stp->esw = PSWITCH_ECHO; \
    stp->pet = 1; \
    stp->e_volume = def->e_volume; \
    stp->record = def->record;

#define WSINP_SET_GENERIC_ENABLE_DATA( _ws, _dev, _ed ) \
    { \
    /* Set echo area using the current vdc rect of the window.  */ \
    WSINP_DC_ECHO_TO_DRWBL_ECHO2((_ws), &(_dev)->e_volume, &(_ed)->echo_area) \
    }

#define WSINP_COPY_COMMON_STATE_FIELDS( _st, _dev ) \
  { \
    (_st)->mode = (_dev)->mode; \
    (_st)->esw = (_dev)->esw; \
    (_st)->pet = (_dev)->pet; \
    (_st)->e_volume = (_dev)->e_volume; \
    (_st)->record = (_dev)->record; \
  }

struct _Ws;

/*******************************************************************************
 * phg_ws_inp_init_device
 *
 * DESCR:       Initialize workstation input device
 * RETURNS:     N/A
 */

void phg_ws_inp_init_device(
    struct _Ws *ws,
    Phg_args_inp_init_dev *args
    );

/*******************************************************************************
 * phg_ws_inp_set_mode
 *
 * DESCR:       Set input mode
 * RETURNS:     N/A
 */

void phg_ws_inp_set_mode(
    struct _Ws *ws,
    Phg_args_set_mode_data *args
    );

/*******************************************************************************
 * phg_ws_inp_request
 *
 * DESCR:       Request input from device
 * RETURNS:     N/A
 */

void phg_ws_inp_request(
    struct _Ws *ws,
    Phg_args_idev_class idev_class,
    Pint dev_num,
    Phg_ret *ret
    );

/*******************************************************************************
 * phg_ws_inp_sample
 *
 * DESCR:       Sample device
 * RETURNS:     N/A
 */

void phg_ws_inp_sample(
    struct _Ws *ws,
    Phg_args_idev_class idev_class,
    Pint dev_num,
    Phg_ret *ret
    );

/*******************************************************************************
 * phg_ws_inp_repaint
 *
 * DESCR:       Repaint device
 * RETURNS:     N/A
 */

void phg_ws_inp_repaint(
    struct _Ws *ws,
    Pint num_rects,
    XRectangle *rects
    );

/*******************************************************************************
 * phg_ws_inp_inq_dev_state
 *
 * DESCR:       Inquire device state
 * RETURNS:     N/A
 */

void phg_ws_inp_inq_dev_state(
    struct _Ws *ws,
    Phg_args_idev_class idev_class,
    Pint num,
    Phg_ret *ret
    );

/*******************************************************************************
 * phg_ws_input_init
 *
 * DESCR:       Initialize input workstation
 * RETURNS:     TRUE or FALSE
 */

int phg_ws_input_init(
    struct _Ws *ws,
    Input_q_handle queue
    );

/*******************************************************************************
 * phg_ws_input_close
 *
 * DESCR:       Close input workstation
 * RETURNS:     TRUE or FALSE
 */

void phg_ws_input_close(
    struct _Ws *ws
    );

/*******************************************************************************
 * phg_ws_inp_resize
 *
 * DESCR:       Resize input device
 * RETURNS:     N/A
 */

void phg_ws_inp_resize(
    struct _Ws *ws,
    XRectangle *old_rect
    );

/*******************************************************************************
 * phg_wsx_create_overlay
 *
 * DESCR:       Create overlay window
 * RETURNS:     Overlay window
 */

Window phg_wsx_create_overlay(
    struct _Ws *ws
    );

/*******************************************************************************
 * phg_wsx_destroy_overlay
 *
 * DESCR:       Destroy overlay window
 * RETURNS:     N/A
 */

void phg_wsx_destroy_overlay(
    Display *display,
    Window overlay,
    Drawable parent
    );

#endif /* _ws_inp_h */

