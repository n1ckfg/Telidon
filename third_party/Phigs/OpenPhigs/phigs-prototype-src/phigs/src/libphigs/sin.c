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

/*
 *	Top level routines for the SIN package.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <phigs/phg.h>
#include <phigs/ws.h>
#include <phigs/sin.h>
#include <phigs/private/sinP.h>
#include <phigs/private/cvsP.h>

/*******************************************************************************
 * phg_sin_destroy
 *
 * DESCR:       Destroy input workstation
 * RETURNS:     N/A
 */

void phg_sin_destroy(
    Sin_input_ws *iws
    )
{
    int	i;

    phg_sin_dev_stop( iws );
    phg_sin_ws_destroy_event_buf( iws );
    phg_sin_dev_destroy_devices( iws );
    phg_sin_cvs_destroy( iws );
    for ( i = 0; i < 6; i++)
	free(iws->devices[i]);
    phg_sin_ws_free_notify_list( iws );
    free(iws);
}

/*******************************************************************************
 * phg_sin_create
 *
 * DESCR:       Create input workstation
 * RETURNS:     Pointer to input workstation or NULL
 */

Sin_handle phg_sin_create(
    Sin_desc *desc,
    Err_handle erh
    )
{
    Sin_input_ws *iws;
    Pint err = ERR900;

    iws = (Sin_input_ws*) calloc(1, sizeof(Sin_input_ws));
    if (iws == NULL) {
	goto no_mem;
    }

    iws->erh = erh;
    iws->queue = desc->queue;
    iws->display = desc->display;
    iws->output_window = desc->output_window;
    iws->input_window = desc->input_window;
    iws->shell = desc->shell;
    iws->wsh = desc->wsh;
    iws->ops.send_request = desc->send_request;
    iws->ops.in_viewport = desc->in_viewport;

    iws->wsid = desc->wsh->id;
    iws->idt = desc->idt;
    iws->num_devs = desc->idt->num_devs;

    if (iws->num_devs.loc > 0) {
        iws->devices[SIN_CLASS_INDEX(SIN_LOCATOR)] = (Sin_input_device*)
            calloc((unsigned) iws->num_devs.loc, sizeof(Sin_input_device));
        if (iws->devices[SIN_CLASS_INDEX(SIN_LOCATOR)] == NULL) {
            goto no_mem;
        }
    }
    if (iws->num_devs.stroke > 0) {
        iws->devices[SIN_CLASS_INDEX(SIN_STROKE)] = (Sin_input_device*)
            calloc((unsigned) iws->num_devs.stroke, sizeof(Sin_input_device));
        if (iws->devices[SIN_CLASS_INDEX(SIN_STROKE)] == NULL) {
            goto no_mem;
        }
    }

    if (iws->num_devs.pick > 0) {
        iws->devices[SIN_CLASS_INDEX(SIN_PICK)] = (Sin_input_device*)
	    calloc((unsigned) iws->num_devs.pick, sizeof(Sin_input_device));
        if (iws->devices[SIN_CLASS_INDEX(SIN_PICK)] == NULL) {
            goto no_mem;
        }
    }

    if (iws->num_devs.val > 0) {
        iws->devices[SIN_CLASS_INDEX(SIN_VALUATOR)] = (Sin_input_device*)
            calloc((unsigned) iws->num_devs.val, sizeof(Sin_input_device));
        if (iws->devices[SIN_CLASS_INDEX(SIN_VALUATOR)] == NULL) {
            goto no_mem;
        }
    }

    if (iws->num_devs.choice > 0) {
        iws->devices[SIN_CLASS_INDEX(SIN_CHOICE)] = (Sin_input_device*)
            calloc((unsigned) iws->num_devs.choice, sizeof(Sin_input_device));
        if (iws->devices[SIN_CLASS_INDEX(SIN_CHOICE)] == NULL) {
            goto no_mem;
        }
    }

    if (iws->num_devs.string > 0) {
        iws->devices[SIN_CLASS_INDEX(SIN_STRING)] = (Sin_input_device*)
            calloc((unsigned) iws->num_devs.string, sizeof(Sin_input_device));
        if (iws->devices[SIN_CLASS_INDEX(SIN_STRING)] == NULL) {
            goto no_mem;
        }
    }

    phg_sin_dev_init_devices( iws );

    SIN_DISABLE_BREAK(iws);

    if ( !phg_sin_ws_event_buf_init( iws ) )
	goto no_mem;

    if ( !(iws->window_table = phg_sin_cvs_create( iws )) ) {
	phg_sin_ws_destroy_event_buf( iws );
	goto no_mem;
    }

    if ( !phg_sin_dev_create_devices( iws ) ) {
	phg_sin_ws_destroy_event_buf( iws );
	phg_sin_cvs_destroy( iws );
	goto no_mem;
    }

    if ( !phg_sin_dev_start( iws ) ) {
	phg_sin_ws_destroy_event_buf( iws );
	phg_sin_dev_destroy_devices( iws );
	phg_sin_cvs_destroy( iws );
	goto no_mem;
    }

    return iws;

no_mem:
    ERR_BUF(erh, err);

    if (iws->devices[SIN_CLASS_INDEX(SIN_LOCATOR)] != NULL) {
        free(iws->devices[SIN_CLASS_INDEX(SIN_LOCATOR)]);
    }

    if (iws->devices[SIN_CLASS_INDEX(SIN_STROKE)] != NULL) {
        free(iws->devices[SIN_CLASS_INDEX(SIN_STROKE)]);
    }

    if (iws->devices[SIN_CLASS_INDEX(SIN_PICK)] != NULL) {
        free(iws->devices[SIN_CLASS_INDEX(SIN_PICK)]);
    }

    if (iws->devices[SIN_CLASS_INDEX(SIN_VALUATOR)] != NULL) {
        free(iws->devices[SIN_CLASS_INDEX(SIN_VALUATOR)]);
    }

    if (iws->devices[SIN_CLASS_INDEX(SIN_CHOICE)] != NULL) {
        free(iws->devices[SIN_CLASS_INDEX(SIN_CHOICE)]);
    }

    if (iws->devices[SIN_CLASS_INDEX(SIN_STRING)] != NULL) {
        free(iws->devices[SIN_CLASS_INDEX(SIN_STRING)]);
    }

    if (iws != NULL) {
        free(iws);
    }

    return NULL;
}

/*******************************************************************************
 * phg_sin_init_device
 *
 * DESCR:       Initialize device for input workstation
 * RETURNS:     N/A
 */

void phg_sin_init_device(
    Sin_input_ws *iws,
    Sin_input_class inp_class,
    Pint dev_num,
    Sin_dev_init_data *new_data
    )
{
    Sin_input_device *dev = SIN_DEV(iws, inp_class, dev_num);

#ifdef DEBUG
    printf("sin: phg_sin_init_device\n");
    printf("\tDevice class: %d\n", inp_class);
#endif

    if ( !dev->flags.exists )
	return;

    /* Do anything that affects the whole workstation. */
	/* nothing to do right now */

    /* Do the device specific stuff. */
    if ( dev->dev_ops.init ) {
	(dev->dev_ops.init)( dev, new_data );
    }

    /* Update the Sin internal state. */
    dev->client_data = new_data->client_data;
    dev->pe_type = new_data->pe_type;
    dev->echo_area = new_data->echo_area;
    switch (dev->inp_class) {
        case SIN_LOCATOR:
	    SIN_COPY_LOC_INIT_DATA( new_data, dev)
            break;
	case SIN_STROKE: {
	    /* Allocate room for request and sample event. */
	    /* TODO: detect allocation failure and free this at ws close. */
	    Ppoint3		*wc_pts;
	    if ( dev->data.stroke.buf_size < new_data->data.stroke.buf_size) {
		if ( dev->data.stroke.wc_pts )
		    free(dev->data.stroke.wc_pts);
		wc_pts = (Ppoint3*)
		    malloc(new_data->data.stroke.buf_size * sizeof(Ppoint3));
	    } else
		wc_pts = dev->data.stroke.wc_pts;

	    if ( dev->data.stroke.init_pts )
		free(dev->data.stroke.init_pts);
	    /* TODO: Make a macro to only copy the relevant fields. */
	    dev->data = new_data->data;
	    dev->data.stroke.wc_pts = wc_pts;
	    if ( new_data->data.stroke.count > 0 )
		memcpy(wc_pts, new_data->data.stroke.wc_pts,
		    new_data->data.stroke.count * sizeof(Ppoint3) );
            } break;
	case SIN_VALUATOR:
	    SIN_COPY_VAL_INIT_DATA( new_data, dev)
            dev->data.valuator.value = dev->data.valuator.init_value;
	    break;
	case SIN_CHOICE:
	    SIN_COPY_CHOICE_INIT_DATA( new_data, dev)
            dev->data.choice.cur_choice = dev->data.choice.init_choice;
	    switch ( dev->pe_type ) {
		case 1:
		case 3:
		    dev->data.choice.count = new_data->data.choice.count;
		    dev->data.choice.choices.strings =
			new_data->data.choice.choices.strings;
		    break;
	    }
	    break;
	case SIN_STRING: {
	    /* Allocate buffer. */
	    /* TODO: detect allocation failure and free this at ws close. */
	    char	*str;

	    if ( dev->data.string.buf_size < new_data->data.string.buf_size) {
		if ( dev->data.string.string )
		    free( dev->data.string.string);
		str = malloc(new_data->data.string.buf_size);
	    } else
		str = dev->data.string.string;
	    dev->data = new_data->data;
	    dev->data.string.string = str;
	    } break;
	case SIN_PICK:
	    SIN_COPY_PICK_INIT_DATA(new_data, dev)
	    break;
    }
}

/*******************************************************************************
 * phg_sin_set_mode
 *
 * DESCR:       Set device mode for input workstation
 * RETURNS:     N/A
 */

void phg_sin_set_mode(
    Sin_input_ws *iws,
    Sin_set_mode_data *md,
    Sin_enable_data *ed
    )
{
    Sin_input_device *dev = SIN_DEV(iws, md->inp_class, md->dev_num);

    if ( !dev->flags.exists )
	return;

    /* Turn old device off if it's on. */
    if ( dev->flags.on ) {
	phg_sin_ws_disable_device( dev);
        /* Allow the cancellation of REQUEST_PENDING. */
        if ( dev->mode == SIN_REQUEST_PENDING ) {
            dev->mode = SIN_REQUEST;
            SIN_DISABLE_BREAK(dev->ws);
        }
    }

    dev->mode = md->mode;
    dev->echo_sw = md->echo;
    SIN_SET_ENABLE_DATA(dev, ed)

    /* turn device on if usable */
    if ( dev->mode == SIN_EVENT || dev->mode == SIN_SAMPLE ) {
	phg_sin_ws_reset_device( dev );
	phg_sin_ws_enable_device( dev );
    }
}

/*******************************************************************************
 * phg_sin_sample
 *
 * DESCR:       Sample device for input workstation
 * RETURNS:     N/A
 */

void phg_sin_sample(
    Sin_input_ws *iws,
    Sin_input_class inp_class,
    Pint dev_num,
    Sin_input_event *event
    )
{
    Sin_input_device *dev = SIN_DEV(iws, inp_class, dev_num);

#ifdef DEBUG
    printf("sin: phg_sin_sample\n");
#endif

    if ( !dev->flags.exists )
	return;

    if ( dev->dev_ops.sample ) {
	(dev->dev_ops.sample)( dev );
    }
    phg_sin_ws_load_event( dev, event );
}

/*******************************************************************************
 * phg_sin_request
 *
 * DESCR:       Request device for input workstation
 * RETURNS:     N/A
 */

void phg_sin_request(
    Sin_input_ws *iws,
    Sin_input_class inp_class,
    Pint dev_num,
    Sin_enable_data *ed
    )
{
    Sin_input_device *dev = SIN_DEV(iws, inp_class, dev_num);

    if ( !dev->flags.exists )
	return;

    SIN_SET_ENABLE_DATA(dev, ed)
    dev->mode = SIN_REQUEST_PENDING;
    SIN_ENABLE_BREAK(dev);
    phg_sin_ws_reset_device( dev );
    phg_sin_ws_enable_device( dev );
}

/*******************************************************************************
 * phg_sin_repaint
 *
 * DESCR:       Repaint device for input workstation
 * RETURNS:     N/A
 */

void phg_sin_repaint(
    Sin_input_ws *iws,
    Pint num_rects,
    XRectangle *rects
    )
{
    Sin_input_device *dev;
    int i;

    /* Only repaint active devices. */

    dev = iws->devices[SIN_CLASS_INDEX(SIN_LOCATOR)];
    for ( i = 0; i < iws->num_devs.loc; i++, dev++ ) {
	if ( dev->flags.on && dev->dev_ops.repaint )
		(dev->dev_ops.repaint)( dev, num_rects, rects );
    }
    dev = iws->devices[SIN_CLASS_INDEX(SIN_STROKE)];
    for ( i = 0; i < iws->num_devs.stroke; i++, dev++ ) {
	if ( dev->flags.on && dev->dev_ops.repaint )
		(dev->dev_ops.repaint)( dev, num_rects, rects );
    }
    dev = iws->devices[SIN_CLASS_INDEX(SIN_PICK)];
    for ( i = 0; i < iws->num_devs.pick; i++, dev++ ) {
	if ( dev->flags.on && dev->dev_ops.repaint )
		(dev->dev_ops.repaint)( dev, num_rects, rects );
    }
    dev = iws->devices[SIN_CLASS_INDEX(SIN_CHOICE)];
    for ( i = 0; i < iws->num_devs.choice; i++, dev++ ) {
	if ( dev->flags.on && dev->dev_ops.repaint )
		(dev->dev_ops.repaint)( dev, num_rects, rects );
    }
    dev = iws->devices[SIN_CLASS_INDEX(SIN_VALUATOR)];
    for ( i = 0; i < iws->num_devs.val; i++, dev++ ) {
	if ( dev->flags.on && dev->dev_ops.repaint )
		(dev->dev_ops.repaint)( dev, num_rects, rects );
    }
    dev = iws->devices[SIN_CLASS_INDEX(SIN_STRING)];
    for ( i = 0; i < iws->num_devs.string; i++, dev++ ) {
	if ( dev->flags.on && dev->dev_ops.repaint )
		(dev->dev_ops.repaint)( dev, num_rects, rects );
    }
}

/*******************************************************************************
 * phg_sin_resize_dev
 *
 * DESCR:       Resize device for input workstation
 * RETURNS:     N/A
 */

void phg_sin_resize_dev(
    Sin_input_ws *ws,
    Sin_input_class inp_class,
    Pint dev_num,
    Sin_enable_data *ed,
    XRectangle *old_rect,
    XRectangle *new_rect
    )
{
    Sin_input_device *dev = SIN_DEV( ws, inp_class, dev_num);

    if ( dev->flags.on ) {
	SIN_SET_ENABLE_DATA( dev, ed)
	if ( dev->dev_ops.resize )
	    (dev->dev_ops.resize)( dev, old_rect, new_rect );
    }
}

