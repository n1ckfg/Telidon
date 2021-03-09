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

#ifndef _sinP_h
#define _sinP_h

#define SIN_EVENT_NOT_ENQUED_FLAG       0x1
#define SIN_EVENT_ENQUED_FLAG           0x2
#define SIN_EVENT_NOTIFIED_FLAG         0x4

#define SIN_EVENT_NOT_ENQUED( _s )      ((_s) & SIN_EVENT_NOT_ENQUED_FLAG)
#define SIN_EVENT_ENQUED( _s )          ((_s) & SIN_EVENT_ENQUED_FLAG)
#define SIN_EVENT_NOTIFIED( _s )        ((_s) & SIN_EVENT_NOTIFIED_FLAG)

#define SIN_COPY_LOC_INIT_DATA( _o, _n ) \
    { \
    (_n)->data.locator.cur_pos          = (_o)->data.locator.cur_pos; \
    (_n)->data.locator.init_pos         = (_o)->data.locator.init_pos; \
    (_n)->data.locator.wc_pt            = (_o)->data.locator.wc_pt; \
    (_n)->data.locator.view             = (_o)->data.locator.view; \
    (_n)->data.locator.resolve          = (_o)->data.locator.resolve; \
    (_n)->data.locator.ln_bundl         = (_o)->data.locator.ln_bundl; \
    }

#define SIN_COPY_PICK_INIT_DATA( _o, _n ) \
    { \
    (_n)->data.pick.init_pos            = (_o)->data.pick.init_pos; \
    (_n)->data.pick.cur_pos             = (_o)->data.pick.cur_pos; \
    (_n)->data.pick.init_pick           = (_o)->data.pick.init_pick; \
    (_n)->data.pick.cur_pick            = (_o)->data.pick.cur_pick; \
    (_n)->data.pick.client_data         = (_o)->data.pick.client_data; \
    (_n)->data.pick.resolve             = (_o)->data.pick.resolve; \
    }

#define SIN_COPY_CHOICE_INIT_DATA( _o, _n ) \
    { \
    (_n)->data.choice.init_choice       = (_o)->data.choice.init_choice; \
    (_n)->data.choice.cur_choice        = (_o)->data.choice.cur_choice; \
    }

#define SIN_COPY_VAL_INIT_DATA( _o, _n ) \
    { \
    (_n)->data.valuator.init_value      = (_o)->data.valuator.init_value; \
    (_n)->data.valuator.low             = (_o)->data.valuator.low; \
    (_n)->data.valuator.high            = (_o)->data.valuator.high; \
    (_n)->data.valuator.label           = (_o)->data.valuator.label; \
    (_n)->data.valuator.format          = (_o)->data.valuator.format; \
    (_n)->data.valuator.low_label       = (_o)->data.valuator.low_label; \
    (_n)->data.valuator.high_label      = (_o)->data.valuator.high_label; \
    }

#define SET_DEFAULT_DEV_GENERIC_DATA( _ws, _dev ) \
    (_dev)->ws = (_ws); \
    (_dev)->wsid = (_ws)->wsid; \
    (_dev)->mode = SIN_REQUEST; \
    (_dev)->flags.on = 0; \
    (_dev)->echo_sw = TRUE;

#define SIN_EVENT_IS_WANTED( _dev ) \
    ( (_dev)->sin_dev->mode == SIN_REQUEST_PENDING  || \
      (_dev)->sin_dev->mode == SIN_EVENT )

#define SIN_X_RECT_TO_SIN_RECT( _sw_r, _sin_r) \
    (_sin_r)->ll.x = (_sw_r)->x; \
    (_sin_r)->ll.y = (_sw_r)->y + (_sw_r)->height; \
    (_sin_r)->ur.x = (_sw_r)->x + (_sw_r)->width; \
    (_sin_r)->ur.y = (_sw_r)->y;

#define SIN_POINT_IN_RECT( _p, _r) \
    /* window coords, y increases top to bottom */ \
    (   (_p)->x >= (_r)->ll.x && (_p)->x <= (_r)->ur.x \
     && (_p)->y <= (_r)->ll.y && (_p)->y >= (_r)->ur.y)

#define SIN_POINT_IN_ECHO_AREA( _p, _dev) \
    (SIN_POINT_IN_RECT( (_p), &(_dev)->echo_area))

#define SIN_POINT_IN_WS( _p, _ws) \
    (1) /* not needed yet */

#define SIN_SET_ENABLE_DATA( _dev, _ed) \
    (_dev)->echo_area = (_ed)->echo_area;    \
    switch ((_dev)->inp_class) { \
        case SIN_LOCATOR: \
            (_dev)->data.locator.init_pos = (_ed)->data.locator.init_pos;\
            break; \
        case SIN_STROKE: \
            (_dev)->data.stroke.count = (_ed)->data.stroke.cnt; \
            memcpy((_dev)->data.stroke.init_pts, \
                   (char *)(_ed)->data.stroke.init_pts, \
                   (_dev)->data.stroke.count * sizeof(Sin_window_pt)); \
            break; \
        default: \
            break; \
    }

#define SIN_VALUATOR_SCALE( data) \
    (((data).valuator.high - (data).valuator.low) / (data).valuator.length)

#define SIN_BREAK_DEVICE( ws) \
    ((ws)->break_device)

#define SIN_ENABLE_BREAK( device) \
    SIN_BREAK_DEVICE((device)->ws) = device; \

#define SIN_DISABLE_BREAK( ws) \
    SIN_BREAK_DEVICE((ws)) = NULL; \

/* Control-d (^d) is the break "key." */
#define BREAK_EVENT( _e ) \
    ((_e)->type == KeyPress && ((_e)->xkey.state & ControlMask) \
        && (XLookupKeysym(&(_e)->xkey, 0) == XK_d))

#define SIN_SAME_CLIENT( _ca, _cb ) \
    ((_ca)->window == (_cb)->window && (_ca)->handle == (_cb)->handle)

#define SIN_DATA_MATCHES( _nd, _w, _h, _f ) \
    ((_nd)->window == (_w) && (_nd)->handle == (_h) && (_nd)->notify == (_f))

/*******************************************************************************
 * phg_sin_ws_window_event_proc
 *
 * DESCR:       Set window event procedure
 * RETURNS:     N/A
 */

void phg_sin_ws_window_event_proc(
    Display *display,
    Window window,
    caddr_t handle,
    XEvent *event
    );

/*******************************************************************************
 * phg_sin_ws_set_event_func
 *
 * DESCR:       Add client to list helper function
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_ws_set_event_func(
    Sin_input_ws *ws,
    Window window,
    caddr_t handle,
    void (*func)(
        struct _Sin_input_ws *ws,
        caddr_t handle,
        Window window,
        XEvent *event
        )
    );

/*******************************************************************************
 * phg_sin_ws_remove_event_func
 *
 * DESCR:       Remove workstation event function
 * RETURNS:     N/A
 */

void phg_sin_ws_remove_event_func(
    Sin_input_ws *ws,
    Window window,
    caddr_t handle,
    void (*func)(
        struct _Sin_input_ws *ws,
        caddr_t handle,
        Window window,
        XEvent *event
        )
    );

/*******************************************************************************
 * phg_sin_ws_free_notify_list
 *
 * DESCR:       Free workstation event notify list
 * RETURNS:     N/A
 */

void phg_sin_ws_free_notify_list(
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_ws_load_event
 *
 * DESCR:       Copy an event from a device to an event strucure.
 * RETURNS:     N/A
 */

void phg_sin_ws_load_event(
    Sin_input_device *dev,
    Sin_input_event *event
    );

/*******************************************************************************
 * phg_sin_ws_enque_events
 *
 * DESC:        Add simultaneous events to the event queue.
 *              Returns SIN_EVENT_ENQUED if all events can be enqued else
 *              SIN_EVENT_NOT_ENQUED.  No events were enqued if
 *              SIN_EVENT_NOT_ENQUED is returned.
 *              All the events are treated as simultaneous.
 *
 *              Call the event notify proc (if any) anytime an attempt is made 
 *              to place events on the queue -- even if the queue has overfloed.
 * RETURNS:     N/A
 */

int phg_sin_ws_enque_events(
    int count,
    Sin_input_device **devs
    );

/*******************************************************************************
 * phg_sin_ws_enable_device
 *
 * DESCR:       Enable device for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_enable_device(
    Sin_input_device *device
    );

/*******************************************************************************
 * phg_sin_ws_disable_device
 *
 * DESCR:       Disable device for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_disable_device(
    Sin_input_device *device
    );

/*******************************************************************************
 * phg_sin_ws_reset_device
 *
 * DESCR:       Reset device for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_reset_device(
    Sin_input_device *device
    );

/*******************************************************************************
 * phg_sin_ws_send_request
 *
 * DESCR:       Send request for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_send_request(
    Sin_input_device *dev
    );

/*******************************************************************************
 * phg_sin_ws_break
 *
 * DESCR:       Break for workstation
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_ws_break( 
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_ws_destroy_event_buf
 *
 * DESCR:       Destroy event buffer for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_destroy_event_buf(
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_ws_event_buf_init
 *
 * DESCR:       Initialize event buffer for workstation
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_ws_event_buf_init(
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_ws_buffer_event
 *
 * DESCR:       Buffer event for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_buffer_event(
    Sin_input_ws *ws,
    Sin_input_device *dev
    );

/*******************************************************************************
 * phg_sin_ws_flush_event_buffer
 *
 * DESCR:       Flush event buffer for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_flush_event_buffer(
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_dev_boot_valuator(
 *
 * DESCR:       Boot valuator device
 * RETURNS:     N/A
 */     
            
void phg_sin_dev_boot_valuator( 
    Sin_input_device *dev
    );

/*******************************************************************************
 * phg_sin_dev_boot_choice
 *
 * DESCR:       Boot choice device 
 * RETURNS:     N/A
 */         

void phg_sin_dev_boot_choice( 
    Sin_input_device *dev
    );

/*******************************************************************************
 * phg_sin_dev_boot_string
 *
 * DESCR:       Boot string device
 * RETURNS:     N/A
 */

void phg_sin_dev_boot_string( 
    Sin_input_device *dev
    );

/*******************************************************************************
 * phg_sin_dev_create_devices
 *
 * DESCR:       Create devices on workspace
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_dev_create_devices(
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_dev_start
 *
 * DESCR:       Start devices on workspace
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_dev_start(
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_dev_stop
 *
 * DESCR:       Stop devices on workspace
 * RETURNS:     N/A
 */

void phg_sin_dev_stop(
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_dev_destroy_devices
 *
 * DESCR:       Destroy devices on workspace
 * RETURNS:     N/A
 */

void phg_sin_dev_destroy_devices(
    Sin_input_ws *ws
    );

/*******************************************************************************
 * phg_sin_dev_init_devices
 *  
 * DESCR:       Initialize devices on workspace
 * RETURNS:     N/A
 */ 

void phg_sin_dev_init_devices(
    Sin_input_ws *ws
    );

#endif /* _sinP_h */

