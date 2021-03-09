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

#ifndef _cvsP_h
#define _cvsP_h

#include <X11/Xlib.h>

#define SIN_MAX_DEV_TRIGGERS   10
#define SIN_NUM_DEV_NUMS       5
#define SIN_NUM_DEV_CLASSES    6

#define SIN_SHIFT_DOWN         (1L << 0)
#define SIN_CTRL_DOWN          (1L << 1)
#define SIN_BUTTON_DOWN        (1L << 2)
#define SIN_KEY_DOWN           (1L << 3)

typedef enum {
   SIN_EVT_NONE,
   SIN_EVT_STARTED,
   SIN_EVT_DONE,
   SIN_EVT_BREAK
} Sin_event_state;

typedef enum {
   SIN_ECHO_DYNAMIC,
   SIN_ECHO_ADD_POINT,
   SIN_ECHO_DELETE_POINT,
   SIN_ECHO_ALL_POINTS
} Sin_stroke_echo_op;

typedef enum {
   SIN_NULL_TRIGGER     = 0,
   SIN_KEY_PRESS        = 1,
   SIN_KEY_RELEASE      = 2,
   SIN_BUTTON_1_PRESS   = 3,
   SIN_BUTTON_2_PRESS   = 4,
   SIN_BUTTON_3_PRESS   = 5,
   SIN_BUTTON_4_PRESS   = 6,
   SIN_BUTTON_5_PRESS   = 7,
   SIN_BUTTON_1_RELEASE = 8,
   SIN_BUTTON_2_RELEASE = 9,
   SIN_BUTTON_3_RELEASE = 10,
   SIN_BUTTON_4_RELEASE = 11,
   SIN_BUTTON_5_RELEASE = 12,
   SIN_PTR_MOVE         = 13,
   SIN_PTR_DRAG         = 14,
   SIN_WIN_ENTER        = 15,
   SIN_WIN_EXIT         = 16,
   SIN_MAX_TRIG_CODE    = 17
} Sin_trig_code;

typedef struct {
   Sin_trig_code trigger;
   Sin_window_pt pt;
   Pint          keycode;
   unsigned int  flags;
   XEvent        *xevent;
} Sin_cvs_event;

typedef struct {
   Pint count;
   Pint max_count;
   Pint size;
   Pint pos;
   union {
      Pint          ivalue;
      Sin_window_pt pt;
      Sin_window_pt *pts;
   } data;
} Sin_measure;

typedef Sin_trig_code Sin_trig_list[SIN_MAX_DEV_TRIGGERS + 1];

struct _Sin_window_table;

typedef struct _Dev_data {
   Pint             enabled;
   Sin_event_state  evt_state;
   Sin_measure      *measure;
   Sin_input_device *sin_dev;
   GC               gc;
   void             (*activate)(
                       struct _Dev_data *dev,
                       struct _Sin_window_table *cvs_tbl
                    );
   void             (*deactivate)(
                       struct _Dev_data *dev,
                       struct _Sin_window_table *cvs_tbl
                    );

   void             (*sample)(
                       struct _Dev_data *dev
                    );
   Sin_trig_list    triggers;
} Dev_data;

typedef struct _Sin_trig_op {
   void                (*evt_func)(
                           Dev_data *dev,
                           struct _Sin_window_table *table,
                           Window window,
                           Sin_cvs_event *event
                           );
   Dev_data            *dev_data;
   struct _Sin_trig_op *next;
} Sin_trig_op;

typedef struct {
   Sin_trig_code code;
   Sin_trig_op   *ops;
} Sin_trig_data;

struct _Sin_input_ws;

typedef struct _Sin_window_table {
   struct _Sin_input_ws *ws;
   Sin_trig_data        trigs[SIN_MAX_TRIG_CODE];
   Dev_data             dev_table[SIN_NUM_DEV_CLASSES][SIN_NUM_DEV_NUMS];
} Sin_window_table;

#define SIN_DEVICE_CANVAS_TABLE( _dev ) \
    (_dev)->ws->window_table

#define DEVICE_DATA( _cvs_tbl, _class, _devno ) \
    (&(_cvs_tbl)->dev_table[SIN_CLASS_INDEX((_class))][(_devno) - 1])

#define EVENT_IS_BUTTON( _e ) \
    (  (int)(_e)->trigger >= (int)SIN_BUTTON_1_PRESS \
    && (int)(_e)->trigger <= (int)SIN_BUTTON_5_RELEASE )

#define BUTTON_IS_DOWN( _e ) \
    ((_e)->flags & SIN_BUTTON_DOWN)

#define EVENT_SHIFT_IS_DOWN( _e ) \
    ((_e)->flags & SIN_SHIFT_DOWN)

#define EVENT_CTRL_IS_DOWN( _e ) \
    ((_e)->flags & SIN_CTRL_DOWN)

#define IN_INITIAL_STROKE( _m ) \
    ((_m)->pos < (_m)->count)

#define FIRST_PT_IN_STROKE( _m ) \
    ((_m)->pos == 0)

#define LAST_PT_IN_STROKE( _m ) \
    ((_m)->pos == ((_m)->count - 1))

#define TRIGGER_DATA( _ct, _code ) \
    (&(_ct)->trigs[(int)(_code)])

#define ALL_BUTTONS \
    (Button1Mask | Button2Mask | Button3Mask | Button4Mask | Button5Mask)

/*******************************************************************************
 * phg_sin_cvs_device_enable
 *
 * DESCR:       Enable device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_enable(
    Sin_input_device *device
    );

/*******************************************************************************
 * phg_sin_cvs_device_disable
 *
 * DESCR:       Disable device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_disable(
    Sin_input_device *device
    );

/*******************************************************************************
 * phg_sin_cvs_device_initialize
 *
 * DESCR:       Initialize device
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_cvs_device_initialize(
    Sin_input_device *sin_dev,
    Sin_dev_init_data *nd
    );

/*******************************************************************************
 * phg_sin_cvs_device_sample
 *
 * DESCR:       Sample device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_sample( 
    Sin_input_device *sin_dev
    );

/*******************************************************************************
 * phg_sin_cvs_device_repaint
 *
 * DESCR:       Repaint device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_repaint(
    Sin_input_device *sin_dev,
    int num_rects,
    XRectangle *rects
    );

/*******************************************************************************
 * phg_sin_cvs_device_resize
 *
 * DESCR:       Resize device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_resize(
    Sin_input_device *sin_dev,
    XRectangle  *old_rect,
    XRectangle  *new_rect
    );

/*******************************************************************************
 * phg_sin_cvs_create_device
 *
 * DESCR:       Create device
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_cvs_create_device(
    Sin_input_device *device
    );

/*******************************************************************************
 * phg_sin_cvs_destroy_device
 *
 * DESCR:       Destroy device
 * RETURNS:     N/A
 */

void phg_sin_cvs_destroy_device(
    Sin_input_device *sin_dev
    );

/*******************************************************************************
 * phg_sin_cvs_destroy
 *
 * DESCR:       Destroy cvs
 * RETURNS:     N/A
 */

void phg_sin_cvs_destroy(
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_cvs_create
 *
 * DESCR:       Initialize cvs
 * RETURNS:     Pointer to window table or NULL
 */

Sin_window_table* phg_sin_cvs_create(
    Sin_input_ws *ws
    );

#endif /* _cvsP_h */

