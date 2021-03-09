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
#include <phigs/sin.h>
#include <phigs/private/sinP.h>
#include <X11/keysym.h>

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
    )
{
    Sin_input_ws *ws = (Sin_input_ws *) handle;
    Sin_notify_data *nd, *next;

#ifdef DEBUG
    printf("sin_ws: phg_sin_ws_window_event_proc\n");
#endif

    if ( BREAK_EVENT(event) && phg_sin_ws_break( ws ) )
	return;	/* received and acted on a BREAK. */
    else if ( event->type == EnterNotify )
	XSetInputFocus( display, window, RevertToParent, CurrentTime );
    else if ( event->type == LeaveNotify )
	XSetInputFocus(display, PointerRoot, RevertToPointerRoot, CurrentTime);

    /* It's possible for the notify list to change while inside the
     * client's notify proc, either because the application closes the
     * workstation or the client code unregisters its notify function.
     * If the workstation closes, the ws's notify list will be set to NULL;
     * thus we check it before each trip through the loop.
     */
    for ( nd = ws->notify_list; nd && ws->notify_list; nd = next ) {
#ifdef DEBUG
        printf("\tNotify %x\n", (unsigned) nd);
#endif
	next = nd->next; /* remember next node in case list changes */
	if ( nd->window == window && nd->notify ) {
#ifdef DEBUG
            printf("\tCall notify func\n");
#endif
	    (*nd->notify)( ws, nd->handle, window, event);
        }
    }
}

/*******************************************************************************
 * add_client_to_list
 *
 * DESCR:       Add client to list helper function
 * RETURNS:     N/A
 */

static void add_client_to_list(
    Sin_notify_data **listp,
    Sin_notify_data *client
    )
{
    Sin_notify_data *dead_node;

    /* If client exists, replace it.  If not, add new client to end of
     * list.
     */
    for (  ; *listp; listp = &(*listp)->next ) {
	if ( SIN_SAME_CLIENT(*listp, client) ) {
	    client->next = (*listp)->next;
	    dead_node = *listp;
	    *listp = client;
	    free((char*)dead_node);
	    break;
	}
    }
    if ( ! *listp )	/* at end of list */
	*listp = client;
}

/*******************************************************************************
 * phg_sin_ws_set_event_func
 *
 * DESCR:       Set workstation event function
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
    )
{
    Sin_notify_data *nd;
    int	status = FALSE;

#ifdef DEBUG
    printf("sin_ws: phg_sin_ws_set_event_func\n");
#endif

    nd = (Sin_notify_data*)calloc((unsigned)1, sizeof(Sin_notify_data));
    if ( nd ) {
	status = TRUE;
	nd->window = window;
	nd->handle = handle;
	nd->notify = func;
	nd->next = NULL;
        /* WARNING:
         * Is this really correct
         */
	add_client_to_list(&ws->notify_list, nd);
    }
    return status;
}

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
    )
{
    Sin_notify_data **ndp;
    Sin_notify_data *dead_node;

    for ( ndp = &ws->notify_list; *ndp; ndp = &(*ndp)->next ) {
	if ( SIN_DATA_MATCHES( *ndp, window, handle, func) ) {
	    dead_node = *ndp;
	    *ndp = (*ndp)->next;
	    free(dead_node);
	    break;
	}
    }
}

/*******************************************************************************
 * phg_sin_ws_free_notify_list
 *
 * DESCR:       Free workstation event notify list
 * RETURNS:     N/A
 */

void phg_sin_ws_free_notify_list(
    Sin_input_ws *ws
    )
{
    Sin_notify_data *nd, *next;

    for ( nd = ws->notify_list; nd; nd = next ) {
	next = nd->next;
	free(nd);
    }
}

/*******************************************************************************
 * phg_sin_ws_load_event
 *
 * DESCR:       Copy an event from a device to an event strucure.
 * RETURNS:     N/A
 */

void phg_sin_ws_load_event(
    Sin_input_device *dev,
    Sin_input_event *event
    )
{
#ifdef DEBUG
    printf("sin_ws: phg_sin_ws_load_event\n");
#endif

    event->wsid = dev->wsid;
    event->dev_num = dev->num;
    switch(dev->inp_class) {
        case SIN_LOCATOR:
	    event->dev_class = PIN_LOC;
	    event->data.locator.evt.position = dev->data.locator.wc_pt;
	    event->data.locator.evt.view_ind = dev->data.locator.view;
            break;
        case SIN_PICK:
	    event->dev_class = PIN_PICK;
	    event->data.pick.evt = dev->data.pick.cur_pick;
            break;
        case SIN_STROKE:
	    event->dev_class = PIN_STROKE;
	    event->data.stroke.evt.view_ind = dev->data.stroke.view;
	    event->data.stroke.evt.num_points = dev->data.stroke.count;
	    /* REQUEST and SAMPLE mode just use the device's buffer.
	     * EVENT mode needs to get space and copy the points.  The
	     * space is freed when the event is removed from the queue.
	     */
	    if ( dev->mode != SIN_EVENT )
		event->data.stroke.evt.points = dev->data.stroke.wc_pts;
	    else if ( dev->data.stroke.count > 0 ) {
		/* TODO: Issue error if this fails. */
		event->data.stroke.evt.points = (Ppoint3*)
		    malloc(dev->data.stroke.count * sizeof(Ppoint3));
		if ( event->data.stroke.evt.points != NULL) {
		    memcpy(event->data.stroke.evt.points,
		           dev->data.stroke.wc_pts,
			   dev->data.stroke.count * sizeof(Ppoint3));
		} else {
		    event->data.stroke.evt.num_points = 0;
		}
	    }
            break;
        case SIN_VALUATOR:
	    event->dev_class = PIN_VAL;
            event->data.valuator.value = dev->data.valuator.value;
            break;
        case SIN_CHOICE:
	    event->dev_class = PIN_CHOICE;
	    event->data.choice.evt.choice = dev->data.choice.cur_choice;
	    if ( dev->data.choice.cur_choice )
		event->data.choice.evt.status = PIN_STATUS_OK;
	    else
		event->data.choice.evt.status = PIN_STATUS_NONE;
            break;
        case SIN_STRING:
	    event->dev_class = PIN_STRING;
	    event->data.string.evt.length = strlen(dev->data.string.string);
	    event->data.string.evt.string = dev->data.string.string;
	    if ( event->data.string.evt.length > 0 ) {
		++event->data.string.evt.length; /* one for the terminator */
		if ( dev->mode == SIN_EVENT ) {
		    /* Allocate space and copy the event to it.  The space
		     * is freed when the event is removed from the queue.
		     */
		    /* TODO: Issue error when this fails. */
		    event->data.string.evt.string =
			malloc((unsigned)event->data.string.evt.length);
		    if ( !event->data.string.evt.string )
			event->data.string.evt.length = 0;
		    else
			strcpy( event->data.string.evt.string,
			    dev->data.string.string);
		}
	    }
            break;
    }
}

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
    int	count,
    Sin_input_device **devs
    )
{
    Sin_input_event *event;
    Sin_event_queue *queue;
    int	status = SIN_EVENT_NOT_ENQUED_FLAG, simul_id;

#ifdef DEBUG
    printf("sin_ws: phg_sin_ws_enque_events\n");
#endif

    queue = (*devs)->ws->queue;
    if ( SIN_Q_ENOUGH_ROOM( queue, count) && !SIN_Q_OVERFLOWED( queue) ) {
	if ( count > 1) {
	    simul_id = SIN_Q_NEW_SIMUL_ID(queue);
	} else {
	    simul_id = 0;
	}
	while ( count--) {
	    event = phg_sin_q_enque_free_event(queue);
	    if ( event != NULL ) {
		phg_sin_ws_load_event( *devs, event);
		event->simul_id = simul_id;
	    }
	    ++devs;
	}
	status = SIN_EVENT_ENQUED_FLAG;

    } else if ( !SIN_Q_OVERFLOWED( queue) ) {
	SIN_Q_SET_OVERFLOW( queue, devs[SIN_Q_NUM_FREE_EVENTS(queue)]);
    }

    if ( queue->event_notify_proc ) {
	(*queue->event_notify_proc)();
	status |= SIN_EVENT_NOTIFIED_FLAG;
    }

    return status;
}

/*******************************************************************************
 * phg_sin_ws_enable_device
 *
 * DESCR:       Enable device for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_enable_device(
    Sin_input_device *device
    )
{
    device->flags.on = 1;
    if ( device->dev_ops.enable) {
	(device->dev_ops.enable)( device );
    }
}

/*******************************************************************************
 * phg_sin_ws_disable_device
 *
 * DESCR:       Disable device for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_disable_device(
    Sin_input_device *device
    )
{
    device->flags.on = 0;
    if ( device->dev_ops.disable ) {
	(device->dev_ops.disable)( device );
    }
}

/*******************************************************************************
 * phg_sin_ws_reset_device
 *
 * DESCR:       Reset device for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_reset_device(
    Sin_input_device *device
    )
{
    switch(device->inp_class) {
        case SIN_LOCATOR:
            device->data.locator.cur_pos = device->data.locator.init_pos;
            break;
	case SIN_PICK:
            device->data.pick.cur_pos = device->data.pick.init_pos;
            device->data.pick.cur_pick = device->data.pick.init_pick;
            break;
        case SIN_STROKE:
            break;
        case SIN_CHOICE:
            device->data.choice.cur_choice = device->data.choice.init_choice;
            break;
        case SIN_STRING:
	    if (device->data.string.init_string)
		strcpy( device->data.string.string,
		    device->data.string.init_string);
	    else
		*device->data.string.string = '\0';
            break;
        case SIN_VALUATOR:
            device->data.valuator.value = device->data.valuator.init_value;
            break;
    }

    if ( device->dev_ops.reset) {
	(device->dev_ops.reset)( device);
    }
}

/*******************************************************************************
 * phg_sin_ws_send_request
 *
 * DESCR:       Send request for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_send_request(
    Sin_input_device *dev
    )
{
    Sin_input_ws *ws = dev->ws;
    Sin_input_event scratch_event;

    if ( dev->mode == SIN_REQUEST_PENDING) {
	dev->mode = SIN_REQUEST;
	SIN_DISABLE_BREAK( ws);
	phg_sin_ws_disable_device( dev);
	phg_sin_ws_load_event( dev, &scratch_event);
	(*ws->ops.send_request)( ws->wsh, &scratch_event, 0);
    }
}

/*******************************************************************************
 * phg_sin_ws_break
 *
 * DESCR:       Break for workstation
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_ws_break(
    Sin_input_ws *ws
    )
{
    /* Return true if the break was used. */
    Sin_input_device *dev;
    Sin_input_event scratch_event;
    int	status = FALSE;

    if ( ws && (dev = SIN_BREAK_DEVICE(ws)) ){
	status = TRUE;
	/* Check the mode just to be safe. */
        if ( dev->mode == SIN_REQUEST_PENDING) {
            dev->mode = SIN_REQUEST;
	    phg_sin_ws_disable_device( dev);
        }
        SIN_DISABLE_BREAK( ws);
	scratch_event.dev_class = SIN_TO_PHIGS_CLASS(dev->inp_class);
	scratch_event.wsid = dev->wsid;
	scratch_event.dev_num = dev->num;
	(*ws->ops.send_request)( ws->wsh, &scratch_event, 1);
    } 

    return status;
}

/*******************************************************************************
 * phg_sin_ws_destroy_event_buf
 *
 * DESCR:       Destroy event buffer for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_destroy_event_buf(
    Sin_input_ws *ws
    )
{
    free(ws->event_buffer.devs);
    ws->event_buffer.devs = NULL;
    ws->event_buffer.size = 0;
    SIN_WS_RESET_EVENT_BUFFER( &ws->event_buffer );
}

/*******************************************************************************
 * phg_sin_ws_event_buf_init
 *
 * DESCR:       Initialize event buffer for workstation
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_ws_event_buf_init(
    Sin_input_ws *ws
    )
{
    int	status = FALSE;

    ws->event_buffer.size = 10;	/* room for this many events initially */
    ws->event_buffer.devs = (Sin_input_device**) calloc( (unsigned)1,
	    (unsigned)ws->event_buffer.size * sizeof(Sin_input_device*));
    if (ws->event_buffer.devs != NULL) {
	status = TRUE;
    }
    else {
	ws->event_buffer.size = 0;
    }

    SIN_WS_RESET_EVENT_BUFFER( &ws->event_buffer );
    return status;
}

/*******************************************************************************
 * phg_sin_ws_buffer_event
 *
 * DESCR:       Buffer event for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_buffer_event(
    Sin_input_ws *ws,
    Sin_input_device *dev
    )
{
    Sin_buf_data *ev_buf = &ws->event_buffer;

    if ( ev_buf->count >= ev_buf->size) {
	ev_buf->devs = (Sin_input_device**)realloc( (char *)ev_buf->devs,
	    (unsigned)((ev_buf->size *= 2)*sizeof(Sin_input_device*)));
    }

    if ( ev_buf->devs ) {
	ev_buf->devs[ev_buf->count++] = dev;
	/* Devices can only be buffered once per flush. */
	dev->flags.buffered = 1;
    }
}

/*******************************************************************************
 * phg_sin_ws_flush_event_buffer
 *
 * DESCR:       Flush event buffer for workstation
 * RETURNS:     N/A
 */

void phg_sin_ws_flush_event_buffer(
    Sin_input_ws *ws
    )
{
    Sin_buf_data *ev_buf = &ws->event_buffer;
    Sin_input_device **devs;
    int	i;
    int	status;

#ifdef DEBUG
    printf("sin_ws: phg_sin_ws_flush_event_buffer\n");
#endif

    /* Put all the events on the queue. */
    if ( ev_buf->count > 0) {
	status = phg_sin_ws_enque_events( ev_buf->count, ev_buf->devs);
	if ( SIN_EVENT_NOT_ENQUED(status) )  {
	    XBell( ws->display, 100 );
	    /* TODO: Free up any allocated data when event won't fit. */

	/* "Acknowledge a successful enque, but don't acknowledge if
	 * there's application notification going on. (This assumes that
	 * the applicaton is doing the acknowledgment.)
	 */
	} else if ( ev_buf->flags & SIN_EVT_ACKNOWLEDGE
	    && !SIN_EVENT_NOTIFIED(status) ) {
	    /* TODO: Acknowledge successful enqueing of event. */
	    ;
	}
    }

    /* Reset the flags. */
    for ( i = 0, devs = ev_buf->devs; i < ev_buf->count; i++, devs++ )
	(*devs)->flags.buffered = 0;
    SIN_WS_RESET_EVENT_BUFFER(ev_buf);
}

#ifdef TODO
XtActionProc phg_sin_xt_request_satisfied(
    Widget  w
    )
{
    Sin_input_device    *device;

    if ( XFindContext( XtDisplay(w), XtWindow(w),
	    phg_sin_device_context_id, (caddr_t*)&device ) == 0 )
	phg_sin_ws_send_request( device );
}
#endif

