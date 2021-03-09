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
*******************************************************************************

Copyright (c) 1989, 1990, 1991  X Consortium

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of the X Consortium shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from the X Consortium.

Copyright 1989, 1990, 1991 by Sun Microsystems, Inc. 

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the name of Sun Microsystems,
not be used in advertising or publicity pertaining to distribution of 
the software without specific, written prior permission.  

SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, 
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT 
SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL 
DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <phigs/phg.h>
#include <phigs/ws.h>
#include <phigs/sin.h>
#include <phigs/private/sinP.h>
#include <phigs/private/cvsP.h>

static void activate_loc(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    );

static void deactivate_loc(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    );

static void activate_stroke(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    );

static void deactivate_stroke(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    );

static void sample_loc(
    Dev_data *dev
    );

static void sample_stroke(
    Dev_data *dev
    );

static void echo_locator(
   Dev_data *dev
   )
{
    Sin_input_device	*sin_dev = dev->sin_dev;

    if ( sin_dev->echo_sw
	&& SIN_POINT_IN_ECHO_AREA(&dev->measure->data.pt, sin_dev)) {
	switch ( sin_dev->pe_type) {
	    case 1:
	    default:
		/* Nothing to do. */
		break;
	}
    }
}

static void echo_stroke_marker(
    Dev_data *dev,
    Sin_window_pt *pt
    )
{
    static XPoint   cross[] =  {{ 0, 0}, /* first point, the rest are relative*/
				{-1, 0}, {-1, 0}, {-1, 0}, {-1, 0},
				{ 5, 0}, { 1, 0}, { 1, 0}, { 1, 0},
				{-4, 1}, { 0, 1}, { 0, 1}, { 0, 1},
				{ 0,-5}, { 0,-1}, { 0,-1}, { 0,-1}};

    switch ( dev->sin_dev->pe_type ) {
	case 1:
	default:
	    cross[0].x = pt->x; cross[0].y = pt->y;
	    XDrawPoints( dev->sin_dev->ws->display,
		dev->sin_dev->ws->output_window, dev->gc,
		cross, sizeof(cross)/sizeof(cross[0]), CoordModePrevious );
	    break;
    }
}

static void echo_stroke(
   Dev_data *dev,
   Sin_stroke_echo_op echo_op
   )
{
    Sin_window_pt *pt;
    int	i;

    if ( !dev->sin_dev->echo_sw )
	return;

    switch ( dev->sin_dev->pe_type ) {
	case 1:
	default:
	    if ( echo_op == SIN_ECHO_ADD_POINT || 
		 echo_op == SIN_ECHO_DELETE_POINT) {
		pt = &dev->measure->data.pts[dev->measure->pos];
		if ( SIN_POINT_IN_ECHO_AREA(pt, dev->sin_dev) ) {
		    echo_stroke_marker( dev, pt );
		    XFlush( dev->sin_dev->ws->display );
		}
	    } else if ( echo_op == SIN_ECHO_ALL_POINTS ) {
		for ( i = 0, pt = dev->measure->data.pts;
			i < dev->measure->count; i++, pt++ ) {
		    if ( SIN_POINT_IN_ECHO_AREA(pt, dev->sin_dev) )
			echo_stroke_marker( dev, pt );
		}
		if ( dev->measure->count > 0 )
		    XFlush( dev->sin_dev->ws->display );
	    }
	    break;
    }
}

static void reset_device(
    Dev_data *dev
    )
{
    dev->evt_state = SIN_EVT_NONE;
    dev->measure->count = 0;

    switch (dev->sin_dev->inp_class) {
	case SIN_LOCATOR:
	    dev->measure->data.pt = dev->sin_dev->data.locator.init_pos;
	    break;
	case SIN_PICK:
	    dev->measure->data.pt = dev->sin_dev->data.pick.init_pos;
	    break;

	case SIN_STROKE:
	    dev->measure->count = dev->sin_dev->data.stroke.init_count;
	    dev->measure->pos = dev->sin_dev->data.stroke.edit_pos;
            if ( dev->measure->count > 0) {
		memcpy(dev->measure->data.pts,
		       dev->sin_dev->data.stroke.init_pts,
		       dev->measure->count * sizeof(Sin_window_pt) );
	    }
	    break;

        default:
            break;
    }
}

static void attach_to_trigger(
    Sin_trig_data *trig,
    Dev_data *dev,
    void (*func)(
        Dev_data*,
        Sin_window_table*,
        Window,
        Sin_cvs_event*)
    )
{
    Sin_trig_op	*op;

    /* Add device data and event function to front of trigger's list. */
    op = (Sin_trig_op*) malloc(sizeof(Sin_trig_op));
    if (op != NULL) {
        op->dev_data = dev;
        op->evt_func = func;
        op->next = trig->ops;
        trig->ops = op;
        dev->enabled = 1;
    }
}

static void attach_to_triggers(
    Dev_data *dev,
    Sin_window_table *cvs_tbl,
    void (*func)(
        Dev_data*,
        Sin_window_table*,
        Window,
        Sin_cvs_event*)
    )
{
    Sin_trig_data *trig;
    Sin_trig_code *code;

    for ( code = dev->triggers; *code != SIN_NULL_TRIGGER; ++code) {
	if ( (trig = TRIGGER_DATA( cvs_tbl, *code )) ) {
	    attach_to_trigger( trig, dev, func );
	}
    }
}

static void detach_from_trigger(
    Sin_trig_data *trig,
    Dev_data *dev
    )
{
    Sin_trig_op	**op = &trig->ops;
    Sin_trig_op	*old_op;

    while ( *op ) {
	if ( (*op)->dev_data == dev ) {
	    old_op = *op;
	    *op = (*op)->next;
	    free(old_op);
	    break;
	}
	op = &(*op)->next;
    }
}

static void detach_from_triggers(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    )
{
    Sin_trig_data *trig;
    Sin_trig_code *code;

    for ( code = dev->triggers; *code != SIN_NULL_TRIGGER; ++code ) {
	if ( (trig = TRIGGER_DATA( cvs_tbl, *code )) ) {
	    detach_from_trigger( trig, dev );
	}
    }
    dev->enabled = 0;
}

static void locator_event_func(
    Dev_data *dev,
    Sin_window_table *cvs_tbl,
    Window window,
    Sin_cvs_event *event
    )
{
    Sin_input_device *sin_dev = dev->sin_dev;
    int	event_occurred = FALSE;
    Sin_window_pt cpt;

    if ( dev->evt_state == SIN_EVT_STARTED )
	echo_locator( dev);	/* remove last echo */
    else
	dev->evt_state = SIN_EVT_STARTED;

    cpt.x = event->pt.x; cpt.y = event->pt.y;

    /* Set the device to its initial value if the cursor leaves device space.
     */
    if (event->trigger == SIN_WIN_EXIT || !SIN_POINT_IN_WS(&cpt,sin_dev->ws)) {
	reset_device( dev);

    } else {
	dev->measure->data.pt = cpt;
	echo_locator( dev );
	switch ( sin_dev->data.locator.type ) {
	    case WST_LOC_TYPE_POINTER_BUTTON_1:
	    case WST_LOC_TYPE_POINTER_BUTTON_2:
	    case WST_LOC_TYPE_POINTER_BUTTON_3:
		if ( EVENT_IS_BUTTON(event) && BUTTON_IS_DOWN(event) ) {
		    event_occurred = TRUE;
		    SIN_WS_SET_ACKNOWLEDGE(cvs_tbl->ws);
		}
		break;
	}
    }

    if ( event_occurred && SIN_EVENT_IS_WANTED( dev) ) {
	sin_dev->data.locator.cur_pos = dev->measure->data.pt;
	switch ( sin_dev->mode) {
	    case SIN_REQUEST_PENDING:
		if ( (*sin_dev->data.locator.resolve)( sin_dev, 0, NULL ) )
		    phg_sin_ws_send_request( sin_dev );
		break;
	    case SIN_EVENT:
		if ( (*sin_dev->data.locator.resolve)( sin_dev, 0, NULL ) ) {
		    phg_sin_ws_buffer_event( cvs_tbl->ws, sin_dev );
		}
		break;
            default:
                break;
	}
    }
}

static void pick_event_func(
    Dev_data *dev,
    Sin_window_table *cvs_tbl,
    Window window,
    Sin_cvs_event *event
    )
{
    Sin_input_device *sin_dev = dev->sin_dev;
    Sin_window_pt cpt;
    int	event_occurred = FALSE;
    int	echo;

    cpt.x = event->pt.x; cpt.y = event->pt.y;

    /* Set the device to its initial value if the cursor leaves device space. */
    if (event->trigger == SIN_WIN_EXIT || !SIN_POINT_IN_WS(&cpt,sin_dev->ws) )
	reset_device( dev);
    else {
     	dev->measure->data.pt = cpt;
	switch (sin_dev->data.pick.type) {
	    case WST_PICK_TYPE_POINTER_BUTTON_1:
	    case WST_PICK_TYPE_POINTER_BUTTON_2:
	    case WST_PICK_TYPE_POINTER_BUTTON_3:
		if ( event->flags & SIN_BUTTON_DOWN )
		    event_occurred = TRUE;
		break;
	}
    }

    if ( event_occurred ) {
	sin_dev->data.pick.cur_pos = cpt;
	echo = sin_dev->echo_sw && SIN_POINT_IN_ECHO_AREA( &cpt, sin_dev);
	switch ( sin_dev->mode ) {
	case SIN_REQUEST_PENDING:
	    if ((*sin_dev->data.pick.resolve)( sin_dev, echo, NULL ) )
		phg_sin_ws_send_request( sin_dev);
	    break;
	case SIN_EVENT:
	    if ((*sin_dev->data.pick.resolve)( sin_dev, echo, NULL ) ) {
		SIN_WS_SET_ACKNOWLEDGE(cvs_tbl->ws);
		phg_sin_ws_buffer_event( cvs_tbl->ws, sin_dev);
	    }
	    break;
	case SIN_SAMPLE:
    	    (void)(*sin_dev->data.pick.resolve)( sin_dev, echo, NULL );
	    break; 
        default:
           break;
    	}
    }
}

static void process_stroke_event(
    Dev_data *dev,
    Sin_window_table *cvs_tbl,
    Sin_cvs_event *event,
    Sin_input_device *sin_dev,
    Sin_window_pt *pt
    )
{

    if ( EVENT_SHIFT_IS_DOWN(event) && SIN_EVENT_IS_WANTED(dev)) {
	/* This point terminates the stroke but is not added to buffer. */
	if ( sin_dev->mode == SIN_REQUEST_PENDING ) {
	    (*sin_dev->data.stroke.resolve)( sin_dev,
		dev->measure->count, dev->measure->data.pts);
	    phg_sin_ws_send_request( sin_dev);

	} else if ( sin_dev->mode == SIN_EVENT ) {
	    (*sin_dev->data.stroke.resolve)( sin_dev,
		dev->measure->count, dev->measure->data.pts);
	    SIN_WS_SET_ACKNOWLEDGE(cvs_tbl->ws);
	    phg_sin_ws_buffer_event( cvs_tbl->ws, sin_dev);
	    deactivate_stroke( dev, cvs_tbl);
	    activate_stroke( dev, cvs_tbl);
	}

    } else if ( EVENT_SHIFT_IS_DOWN(event) && sin_dev->mode == SIN_SAMPLE ) {
	/* Flush buffer and start again . */
	deactivate_stroke( dev, cvs_tbl);
	activate_stroke( dev, cvs_tbl);
    

    } else if ( EVENT_CTRL_IS_DOWN(event) ) {
	/* Remove point from buffer (if after the edit position. */
	if ( dev->measure->count > 0 && dev->measure->pos > 0
	    && dev->measure->pos-1 >= sin_dev->data.stroke.edit_pos ) {
	    --dev->measure->pos;
	    --dev->measure->count;
	    echo_stroke( dev, SIN_ECHO_DELETE_POINT);
	}

    } else {
	/* Add point to buffer if not already full. */
	if ( dev->measure->count >= dev->measure->max_count)
	    XBell( sin_dev->ws->display, 100 );
	else if ( dev->measure->count <= sin_dev->data.stroke.init_count
	    && dev->measure->pos < dev->measure->count ) {
	    echo_stroke( dev, SIN_ECHO_DELETE_POINT);
	    dev->measure->data.pts[dev->measure->pos] = *pt;
	    echo_stroke( dev, SIN_ECHO_ADD_POINT);
	    ++dev->measure->pos;
	} else {
	    dev->measure->data.pts[dev->measure->pos] = *pt;
	    echo_stroke( dev, SIN_ECHO_ADD_POINT);
	    ++dev->measure->pos;
	    ++dev->measure->count;
	}
    }
}

static void stroke_event_func(
    Dev_data *dev,
    Sin_window_table *cvs_tbl,
    Window window,
    Sin_cvs_event *event
    )
{
    Sin_input_device *sin_dev = dev->sin_dev;
    int	event_occurred = FALSE;
    Sin_window_pt cpt;

    if ( dev->evt_state == SIN_EVT_STARTED)
	echo_stroke( dev, SIN_ECHO_DYNAMIC);	/* remove last dynamic echo */
    else
	dev->evt_state = SIN_EVT_STARTED;

    cpt.x = event->pt.x; cpt.y = event->pt.y;

    if (event->trigger != SIN_WIN_EXIT && SIN_POINT_IN_WS(&cpt,sin_dev->ws))
	echo_stroke( dev, SIN_ECHO_DYNAMIC);

    if ( event->flags & SIN_BUTTON_DOWN ) {
	if ( EVENT_SHIFT_IS_DOWN(event) || EVENT_CTRL_IS_DOWN(event) )
	    event_occurred = TRUE;
	else if ( (*sin_dev->ws->ops.in_viewport)(
                      (Ws_handle) sin_dev->client_data, &cpt))
	    event_occurred = TRUE;
    }

    if ( event_occurred )
	process_stroke_event( dev, cvs_tbl, event, sin_dev, &cpt );
}

static void activate_loc(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    )
{
#ifdef DEBUG
    printf("sin_cvs: activate_loc\n");
#endif

    reset_device( dev );
    attach_to_triggers( dev, cvs_tbl, locator_event_func );
}

static void deactivate_loc(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    )
{
    detach_from_triggers( dev, cvs_tbl );
    reset_device( dev );
}

static void activate_stroke(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    )
{
#ifdef DEBUG
    printf("sin_cvs: activate_stroke");
#endif

    reset_device( dev );
    attach_to_triggers( dev, cvs_tbl, stroke_event_func );
    echo_stroke( dev, SIN_ECHO_ALL_POINTS );
}

static void deactivate_stroke(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    )
{
    detach_from_triggers( dev, cvs_tbl );
    echo_stroke( dev, SIN_ECHO_ALL_POINTS );
    reset_device( dev );
}

static void activate_pick(
    Dev_data *dev,
    Sin_window_table *cvs_tbl
    )
{
#ifdef DEBUG
    printf("sin_cvs: activate_pick");
#endif

    reset_device( dev );
    attach_to_triggers( dev, cvs_tbl, pick_event_func );
}

static void sample_loc(
    Dev_data *dev
    )
{
    /* Don't resolve until the measure is changed. */
    if ( dev->evt_state == SIN_EVT_STARTED ) {
	dev->sin_dev->data.locator.cur_pos = dev->measure->data.pt;
	(void)(*dev->sin_dev->data.locator.resolve)( dev->sin_dev, 0, NULL );
    }
}

static void sample_stroke(
    Dev_data *dev
    )
{
    /* Don't resolve until the measure is changed. */
    if ( dev->evt_state == SIN_EVT_STARTED ) {
	(void)(*dev->sin_dev->data.stroke.resolve)( dev->sin_dev,
	    dev->measure->count, dev->measure->data.pts);
    }
}

/*******************************************************************************
 * phg_sin_cvs_device_enable
 *
 * DESCR:       Enable device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_enable(
    Sin_input_device *device
    )
{
    Sin_window_table *cvs_tbl;
    Dev_data *dev;

    cvs_tbl = SIN_DEVICE_CANVAS_TABLE(device);
    dev = DEVICE_DATA(cvs_tbl, device->inp_class, device->num);
    if ( dev->enabled) {
	(*dev->deactivate)( dev, cvs_tbl );
    }

    switch ( device->mode) {
	case SIN_REQUEST_PENDING:
	case SIN_SAMPLE:
	case SIN_EVENT:
	    (*dev->activate)( dev, cvs_tbl );
	    break;
        default:
            break;
    }
}

/*******************************************************************************
 * phg_sin_cvs_device_disable
 *
 * DESCR:       Disable device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_disable(
    Sin_input_device *device
    )
{
    Sin_window_table *cvs_tbl;
    Dev_data *dev;

    cvs_tbl = SIN_DEVICE_CANVAS_TABLE( device);
    dev = DEVICE_DATA(cvs_tbl, device->inp_class, device->num);
    if ( dev->enabled ) {
	(*dev->deactivate)( dev, cvs_tbl);
    }
}

/*******************************************************************************
 * phg_sin_cvs_device_initialize
 *
 * DESCR:       Initialize device
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_cvs_device_initialize(
    Sin_input_device *sin_dev,
    Sin_dev_init_data *nd
    )
{
    Sin_window_table *cvs_tbl;
    Dev_data *dev;
    Sin_measure	*m;
    int	size_needed, status = TRUE;

    cvs_tbl = SIN_DEVICE_CANVAS_TABLE(sin_dev);
    dev = DEVICE_DATA( cvs_tbl, sin_dev->inp_class, sin_dev->num);
    switch (sin_dev->inp_class) {
	case SIN_STROKE:
	    dev->measure->max_count = nd->data.stroke.buf_size;
	    size_needed = dev->measure->max_count * sizeof(Sin_window_pt);
	    m = dev->measure;
	    if ( m->size < size_needed ) {
		if ( m->data.pts ) {
		    free(m->data.pts);
		    m->size = 0;
		}
		if ( (m->data.pts = (Sin_window_pt*) malloc(size_needed)) )
		    m->size = size_needed;
		else
		    status = 0;
	    }
	    break;
        default:
	    break;
    }
    return status;
}

/*******************************************************************************
 * phg_sin_cvs_device_sample
 *
 * DESCR:       Sample device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_sample(
    Sin_input_device *sin_dev
    )
{
    Sin_window_table *cvs_tbl;
    Dev_data *dev;

    cvs_tbl = SIN_DEVICE_CANVAS_TABLE(sin_dev);
    dev = DEVICE_DATA(cvs_tbl, sin_dev->inp_class, sin_dev->num);
    if ( dev->sample) {
	(*dev->sample)(dev);
    }
}

/*******************************************************************************
 * phg_sin_cvs_device_repaint
 *
 * DESCR:       Repaint device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_repaint(
    Sin_input_device *sin_dev,
    int	num_rects,
    XRectangle *rects
    )
{
    Sin_window_table *cvs_tbl;
    Dev_data *dev;

    cvs_tbl = SIN_DEVICE_CANVAS_TABLE(sin_dev);
    dev = DEVICE_DATA(cvs_tbl, sin_dev->inp_class, sin_dev->num);
    switch (sin_dev->inp_class) {
	case SIN_LOCATOR:
	    if ( dev->evt_state == SIN_EVT_STARTED)
		echo_locator( dev );
	    break;
	case SIN_STROKE:
	    if ( num_rects >= 0 )
		XSetClipRectangles( sin_dev->ws->display, dev->gc, 0, 0,
		    rects, num_rects, Unsorted );
	    echo_stroke(dev, SIN_ECHO_ALL_POINTS);
	    XSetClipMask( sin_dev->ws->display, dev->gc, None );
	    break;
        default:
	    break;
    }
}

/*******************************************************************************
 * phg_sin_cvs_device_resize
 *
 * DESCR:       Resize device
 * RETURNS:     N/A
 */

void phg_sin_cvs_device_resize(
    Sin_input_device *sin_dev,
    XRectangle	*old_rect,
    XRectangle	*new_rect
    )
{
    Sin_window_table *cvs_tbl;
    Dev_data *dev;
    int	delta;

    cvs_tbl = SIN_DEVICE_CANVAS_TABLE( sin_dev);
    dev = DEVICE_DATA(cvs_tbl, sin_dev->inp_class, sin_dev->num);
    if ( sin_dev->inp_class == SIN_LOCATOR || sin_dev->inp_class == SIN_STROKE )
	delta = new_rect->height - old_rect->height;

    switch (sin_dev->inp_class) {
	case SIN_LOCATOR:
	    dev->measure->data.pt.y += delta;
	    break;
	case SIN_STROKE: {
	    Sin_window_pt *pt = dev->measure->data.pts;
	    int	i;
	    for ( i = 0; i < dev->measure->count; i++, pt++ )
		pt->y += delta;
	    } break;
        default:
            break;
    }
}

/*******************************************************************************
 * create_locator_dev
 *
 * DESCR:       Create locator device helper function
 * RETURNS:     TRUE or FALSE
 */

static int create_locator_dev(
    Sin_input_device *sin_dev,
    Dev_data *dev
    )
{
    int	status = TRUE;

    dev->activate = activate_loc;
    dev->deactivate = deactivate_loc;
    dev->sample = sample_loc;
    switch ( sin_dev->data.locator.type ) {
	case WST_LOC_TYPE_POINTER_BUTTON_1:
	    dev->triggers[0] = SIN_BUTTON_1_PRESS;
	    dev->triggers[1] = SIN_PTR_MOVE;
	    dev->triggers[2] = SIN_PTR_DRAG;
	    dev->triggers[3] = SIN_WIN_ENTER;
	    dev->triggers[4] = SIN_WIN_EXIT;
	    dev->triggers[5] = SIN_NULL_TRIGGER;	/* terminator */
	    break;
	case WST_LOC_TYPE_POINTER_BUTTON_2:
	    dev->triggers[0] = SIN_BUTTON_2_PRESS;
	    dev->triggers[1] = SIN_PTR_MOVE;
	    dev->triggers[2] = SIN_PTR_DRAG;
	    dev->triggers[3] = SIN_WIN_ENTER;
	    dev->triggers[4] = SIN_WIN_EXIT;
	    dev->triggers[5] = SIN_NULL_TRIGGER;	/* terminator */
	    break;
	case WST_LOC_TYPE_POINTER_BUTTON_3:
	    dev->triggers[0] = SIN_BUTTON_3_PRESS;
	    dev->triggers[1] = SIN_PTR_MOVE;
	    dev->triggers[2] = SIN_PTR_DRAG;
	    dev->triggers[3] = SIN_WIN_ENTER;
	    dev->triggers[4] = SIN_WIN_EXIT;
	    dev->triggers[5] = SIN_NULL_TRIGGER;	/* terminator */
	    break;
    }
    return status;
}

/*******************************************************************************
 * create_pick_dev
 *
 * DESCR:       Create pick device helper function
 * RETURNS:     TRUE or FALSE
 */

static int create_pick_dev(
    Sin_input_device *sin_dev,
    Dev_data *dev
    )
{
    int	status = TRUE;

    dev->activate = activate_pick;
    dev->deactivate = detach_from_triggers;
    switch ( sin_dev->data.pick.type ) {
	case WST_PICK_TYPE_POINTER_BUTTON_1:
	    dev->triggers[0] = SIN_BUTTON_1_PRESS;
	    dev->triggers[1] = SIN_PTR_MOVE;
	    dev->triggers[2] = SIN_WIN_ENTER;
	    dev->triggers[3] = SIN_WIN_EXIT;
	    dev->triggers[4] = SIN_NULL_TRIGGER;	/* terminator */
	    break;
	case WST_PICK_TYPE_POINTER_BUTTON_2:
	    dev->triggers[0] = SIN_BUTTON_2_PRESS;
	    dev->triggers[1] = SIN_PTR_MOVE;
	    dev->triggers[2] = SIN_WIN_ENTER;
	    dev->triggers[3] = SIN_WIN_EXIT;
	    dev->triggers[4] = SIN_NULL_TRIGGER;	/* terminator */
	    break;
	case WST_PICK_TYPE_POINTER_BUTTON_3:
	    dev->triggers[0] = SIN_BUTTON_3_PRESS;
	    dev->triggers[1] = SIN_PTR_MOVE;
	    dev->triggers[2] = SIN_WIN_ENTER;
	    dev->triggers[3] = SIN_WIN_EXIT;
	    dev->triggers[4] = SIN_NULL_TRIGGER;	/* terminator */
	    break;
    }
    return status;
}

/*******************************************************************************
 * create_stroke_dev
 *
 * DESCR:       Create stroke device helper function
 * RETURNS:     TRUE or FALSE
 */

static int create_stroke_dev(
    Sin_input_device *sin_dev,
    Dev_data *dev
    )
{
    int	status = TRUE;

    dev->activate = activate_stroke;
    dev->deactivate = deactivate_stroke;
    dev->sample = sample_stroke;
    dev->measure->data.pts = NULL;
    if (   sin_dev->data.stroke.type == WST_STROKE_TYPE_POINTER_BUTTON_1
	    || sin_dev->data.stroke.type == WST_STROKE_TYPE_POINTER_BUTTON_2
	    || sin_dev->data.stroke.type == WST_STROKE_TYPE_POINTER_BUTTON_3 ) {
	dev->gc = XCreateGC( sin_dev->ws->display,
	    sin_dev->ws->output_window, 0, NULL );
	/* TODO: A pixel value of 1 is used, but we need to see how this
	 * fits with the colour mapping colour table.
	 */
	XSetForeground( sin_dev->ws->display, dev->gc, 1 );
	XSetFunction( sin_dev->ws->display, dev->gc, GXxor );
    }
    switch ( sin_dev->data.stroke.type ) {
	case WST_STROKE_TYPE_POINTER_BUTTON_1:
	    dev->triggers[0] = SIN_BUTTON_1_PRESS;
	    dev->triggers[1] = SIN_NULL_TRIGGER;	/* terminator */
	    break;
	case WST_STROKE_TYPE_POINTER_BUTTON_2:
	    dev->triggers[0] = SIN_BUTTON_2_PRESS;
	    dev->triggers[1] = SIN_NULL_TRIGGER;	/* terminator */
	    break;
	case WST_STROKE_TYPE_POINTER_BUTTON_3:
	    dev->triggers[0] = SIN_BUTTON_3_PRESS;
	    dev->triggers[1] = SIN_NULL_TRIGGER;	/* terminator */
	    break;
    }
    return status;
}

/*******************************************************************************
 * phg_sin_cvs_create_device
 *
 * DESCR:       Create device
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_cvs_create_device(
    Sin_input_device *device
    )
{
    int	status = FALSE;
    Dev_data *dev;
    Sin_window_table *cvs_tbl;

    cvs_tbl = SIN_DEVICE_CANVAS_TABLE(device);
    dev = DEVICE_DATA(cvs_tbl, device->inp_class, device->num);
    dev->measure = (Sin_measure*) calloc( 1, sizeof(Sin_measure));
    if ( dev->measure != NULL) {
	dev->evt_state = SIN_EVT_NONE;
	dev->sin_dev = device;
	switch (device->inp_class) {
	    case SIN_LOCATOR:
		status = create_locator_dev( device, dev );
		break;
	    case SIN_PICK:
		status = create_pick_dev( device, dev );
		break;
	    case SIN_STROKE:
		status = create_stroke_dev( device, dev );
		break;
            default:
		break;
	}
    }
    
    return status;
}

/*******************************************************************************
 * phg_sin_cvs_destroy_device
 *
 * DESCR:       Destroy device
 * RETURNS:     N/A
 */

void phg_sin_cvs_destroy_device(
    Sin_input_device *sin_dev
    )
{
    Sin_window_table *cvs_tbl;
    Dev_data *dev;

    cvs_tbl = SIN_DEVICE_CANVAS_TABLE(sin_dev);
    dev = DEVICE_DATA(cvs_tbl, sin_dev->inp_class, sin_dev->num);
    if ( dev->enabled )
	(*dev->deactivate)( dev, cvs_tbl );
    if ( dev->measure ) {
	if ( dev->measure->size )
	    free(dev->measure->data.pts);
	free(dev->measure);
    }
}

/*******************************************************************************
 * map_event
 *
 * DESCR:       Map event helper function
 * RETURNS:     One or zero on unknown event
 */

static int map_event(
    XEvent *xevent,
    Sin_cvs_event *event
    )
{
    int	status = 1;

    event->flags = 0;
    event->xevent = xevent;
    switch ( xevent->type ) {
	case KeyPress:
	    event->trigger = SIN_KEY_PRESS;
	    event->pt.x = xevent->xkey.x;
	    event->pt.y = xevent->xkey.y;
	    event->flags |= SIN_KEY_DOWN;
	    if ( xevent->xkey.state & ShiftMask )
		event->flags |= SIN_SHIFT_DOWN;
	    if ( xevent->xkey.state & ControlMask )
		event->flags |= SIN_CTRL_DOWN;
	    break;
	case KeyRelease:
	    event->trigger = SIN_KEY_RELEASE;
	    event->pt.x = xevent->xkey.x;
	    event->pt.y = xevent->xkey.y;
	    if ( xevent->xkey.state & ShiftMask )
		event->flags |= SIN_SHIFT_DOWN;
	    if ( xevent->xkey.state & ControlMask )
		event->flags |= SIN_CTRL_DOWN;
	    break;
	case ButtonPress:
	    event->pt.x = xevent->xbutton.x;
	    event->pt.y = xevent->xbutton.y;
	    event->flags |= SIN_BUTTON_DOWN;
	    if ( xevent->xbutton.state & ShiftMask )
		event->flags |= SIN_SHIFT_DOWN;
	    if ( xevent->xbutton.state & ControlMask )
		event->flags |= SIN_CTRL_DOWN;
	    switch ( xevent->xbutton.button ) {
		case Button1: event->trigger = SIN_BUTTON_1_PRESS; break;
		case Button2: event->trigger = SIN_BUTTON_2_PRESS; break;
		case Button3: event->trigger = SIN_BUTTON_3_PRESS; break;
		case Button4: event->trigger = SIN_BUTTON_4_PRESS; break;
		case Button5: event->trigger = SIN_BUTTON_5_PRESS; break;
	    }
	    break;
	case ButtonRelease:
	    event->pt.x = xevent->xbutton.x;
	    event->pt.y = xevent->xbutton.y;
	    if ( xevent->xbutton.state & ShiftMask )
		event->flags |= SIN_SHIFT_DOWN;
	    if ( xevent->xbutton.state & ControlMask )
		event->flags |= SIN_CTRL_DOWN;
	    switch ( xevent->xbutton.button ) {
		case Button1: event->trigger = SIN_BUTTON_1_RELEASE; break;
		case Button2: event->trigger = SIN_BUTTON_2_RELEASE; break;
		case Button3: event->trigger = SIN_BUTTON_3_RELEASE; break;
		case Button4: event->trigger = SIN_BUTTON_4_RELEASE; break;
		case Button5: event->trigger = SIN_BUTTON_5_RELEASE; break;
	    }
	    break;
	case MotionNotify:
	    event->pt.x = xevent->xmotion.x;
	    event->pt.y = xevent->xmotion.y;
	    if ( xevent->xmotion.state & ShiftMask )
		event->flags |= SIN_SHIFT_DOWN;
	    if ( xevent->xmotion.state & ControlMask )
		event->flags |= SIN_CTRL_DOWN;
	    if ( xevent->xmotion.state & ALL_BUTTONS ) {
		event->trigger = SIN_PTR_DRAG;
		event->flags |= SIN_BUTTON_DOWN;
	    } else
		event->trigger = SIN_PTR_MOVE;
	    break;
	case EnterNotify:
	case LeaveNotify:
	    event->trigger = xevent->type == EnterNotify ?
		SIN_WIN_ENTER : SIN_WIN_EXIT;
	    event->pt.x = xevent->xcrossing.x;
	    event->pt.y = xevent->xcrossing.y;
	    if ( xevent->xcrossing.state & ShiftMask )
		event->flags |= SIN_SHIFT_DOWN;
	    if ( xevent->xcrossing.state & ControlMask )
		event->flags |= SIN_CTRL_DOWN;
	    if ( xevent->xcrossing.state & ALL_BUTTONS )
		event->flags |= SIN_BUTTON_DOWN;
	    break;
	default:
	    status = 0;
	    break;
    }
    return status;
}

/*******************************************************************************
 * process_event
 *
 * DESCR:       Process event handler function
 * RETURNS:     N/A
 */

static void process_event(
    Sin_input_ws *ws,
    caddr_t handle,
    Window window,
    XEvent *xevent
    )
{
    Sin_trig_data *trig;
    Sin_cvs_event event;
    Sin_window_table *cvs_tbl = (Sin_window_table *) handle;

    Sin_trig_op	*op, *next;

    /* Call all the event procs associated with this event. */
    if ( !map_event( xevent, &event ) )
	return;
    if ( (trig = TRIGGER_DATA(cvs_tbl, event.trigger)) ) {
	op = trig->ops;
	while ( op ) {
	    next = op->next; /* remember next node in case list changes */
	    (*op->evt_func)( op->dev_data, cvs_tbl, window, &event );
	    op = next;
	}
	phg_sin_ws_flush_event_buffer( ws );
    }
}

/*******************************************************************************
 * phg_sin_cvs_destroy
 *
 * DESCR:       Destroy cvs
 * RETURNS:     N/A
 */

void phg_sin_cvs_destroy(
    Sin_input_ws *ws
    )
{
    /* Deactivate and free the window table. */
    phg_sin_ws_remove_event_func( ws, ws->input_window,
	(caddr_t)ws->window_table, process_event );
    if ( ws->window_table )
	free(ws->window_table );
}

/*******************************************************************************
 * phg_sin_cvs_create
 *
 * DESCR:       Initialize cvs
 * RETURNS:     Pointer to window table or NULL
 */

Sin_window_table* phg_sin_cvs_create(
    Sin_input_ws *ws
    )
{
    Sin_window_table *cvs_tbl;
    int	i;

    cvs_tbl = (Sin_window_table *) calloc(1, sizeof(Sin_window_table));
    if (cvs_tbl == NULL) {
	goto no_mem;
    }

    cvs_tbl->ws = ws;
    if ( !phg_sin_ws_set_event_func( ws, ws->input_window, (caddr_t)cvs_tbl,
	    process_event ))
	goto no_mem;
    /* Initialize the trigger table. */
    for ( i = 0; i < (int)SIN_MAX_TRIG_CODE; i++ )
	cvs_tbl->trigs[i].code = (Sin_trig_code)i;

    return cvs_tbl;

no_mem:
    free(cvs_tbl);
    return NULL;
}

