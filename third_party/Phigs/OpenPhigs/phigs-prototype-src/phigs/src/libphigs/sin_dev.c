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
 * Default device specific routines for input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <phigs/phg.h>
#include <phigs/ws_type.h>
#include <phigs/sin.h>
#include <phigs/private/sinP.h>
#include <phigs/private/cvsP.h>
#include <phigs/private/evtP.h>

#define NUM_COMMON_EVENTS (sizeof(common_events) / sizeof(common_events[0]))

static unsigned long common_mask =
    KeyPressMask |
    KeyReleaseMask |
    ButtonPressMask |
    ButtonReleaseMask |
    EnterWindowMask |
    LeaveWindowMask |
    PointerMotionHintMask;

static int common_events[] = {
    KeyPress,
    KeyRelease,
    ButtonPress,
    ButtonRelease,
    EnterNotify,
    LeaveNotify,
    MotionNotify
};

/*******************************************************************************
 * remove_ops
 *
 * DESCR:       Remove device operators helper function
 * RETURNS:     N/A
 */

static void remove_ops(
    Sin_input_device *dev
    )
{
    /* Remove ops for this device. */
    dev->dev_ops.create = NULL;
    dev->dev_ops.reset = NULL;
    dev->dev_ops.enable = NULL;
    dev->dev_ops.disable = NULL;
    dev->dev_ops.init = NULL;
    dev->dev_ops.sample = NULL;
    dev->dev_ops.resize = NULL;
    dev->dev_ops.repaint = NULL;
    dev->dev_ops.destroy = NULL;
}

/*******************************************************************************
 * phg_sin_dev_create_devices
 *
 * DESCR:       Create devices on workspace
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_dev_create_devices(
    Sin_input_ws *ws
    )
{
    Sin_input_device *dev;
    int i;

    /* Create and link the window devices */
    for ( i = 1; i <= ws->num_devs.loc; i++ ) {
	dev = SIN_DEV(ws, SIN_LOCATOR, i);
	dev->flags.exists = 1;
	if ( dev->dev_ops.create ) {
	    if ( !(dev->dev_ops.create)( dev ) ) {
		remove_ops( dev );
		dev->flags.exists = 0;
	    }
	}
    }

    for ( i = 1; i <= ws->num_devs.pick; i++ ) {
	dev = SIN_DEV(ws, SIN_PICK, i);
	dev->flags.exists = 1;
	if ( dev->dev_ops.create ) {
	    if ( !(dev->dev_ops.create)( dev ) ) {
		remove_ops( dev );
		dev->flags.exists = 0;
	    }
	}
    }

    for ( i = 1; i <= ws->num_devs.stroke; i++ ) {
	dev = SIN_DEV(ws, SIN_STROKE, i);
	dev->flags.exists = 1;
	if ( dev->dev_ops.create ) {
	    if ( !(dev->dev_ops.create)( dev ) ) {
		remove_ops( dev );
		dev->flags.exists = 0;
	    }
	}
    }

    for ( i = 1; i <= ws->num_devs.choice; i++ ) {
	dev = SIN_DEV(ws, SIN_CHOICE, i);
	dev->flags.exists = 1;
	if ( dev->dev_ops.create ) {
	    if ( !(dev->dev_ops.create)( dev ) ) {
		remove_ops( dev );
		dev->flags.exists = 0;
	    }
	}
    }

    for ( i = 1; i <= ws->num_devs.val; i++ ) {
	dev = SIN_DEV(ws, SIN_VALUATOR, i);
	dev->flags.exists = 1;
	if ( dev->dev_ops.create ) {
	    if ( !(dev->dev_ops.create)( dev ) ) {
		remove_ops( dev );
		dev->flags.exists = 0;
	    }
	}
    }

    for ( i = 1; i <= ws->num_devs.string; i++ ) {
	dev = SIN_DEV(ws, SIN_STRING, i);
	dev->flags.exists = 1;
	if ( dev->dev_ops.create ) {
	    if ( !(dev->dev_ops.create)( dev ) ) {
		remove_ops( dev );
		dev->flags.exists = 0;
	    }
	}
    }

    return TRUE;
}

/*******************************************************************************
 * phg_sin_dev_start
 *
 * DESCR:       Start devices on workspace
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_dev_start(
    Sin_input_ws *ws
    )
{
    int	i;

#ifdef DEBUG
   printf("sin_dev: phg_sin_dev_start\n");
   printf("\tinput_window = %x\n", (unsigned) ws->input_window);
#endif

    /* Start up input processing for the input window. */
    for ( i = 0; i < NUM_COMMON_EVENTS; i++ ) {
#ifdef DEBUG
        printf("\tRegister event: %d\n", common_events[i]);
#endif
	(void)phg_sin_evt_register( PHG_EVT_TABLE, ws->display,
	    ws->input_window, common_events[i], (caddr_t)ws,
            phg_sin_ws_window_event_proc );
    }
    XSelectInput( ws->display, ws->input_window, common_mask );
    return TRUE;
}

/*******************************************************************************
 * phg_sin_dev_stop
 *
 * DESCR:       Stop devices on workspace
 * RETURNS:     N/A
 */

void phg_sin_dev_stop(
    Sin_input_ws *ws
    )
{
    int	i;

#ifdef DEBUG
   printf("sin_dev: phg_sin_dev_stop\n");
   printf("\tinput_window = %x\n", (unsigned) ws->input_window);
#endif

    for ( i = 0; i < NUM_COMMON_EVENTS; i++ ) {
	phg_sin_evt_unregister( PHG_EVT_TABLE, ws->display, ws->input_window,
	    common_events[i], (caddr_t)ws );
    }
}

/*******************************************************************************
 * phg_sin_dev_destroy_devices
 *
 * DESCR:       Destroy devices on workspace
 * RETURNS:     N/A
 */

void phg_sin_dev_destroy_devices(
    Sin_input_ws *ws
    )
{
    Sin_input_device *dev;
    int i;

    for ( i = 1; i <= ws->num_devs.loc; i++) {
	dev = SIN_DEV(ws, SIN_LOCATOR, i);
	if ( dev->dev_ops.destroy )
	    (*dev->dev_ops.destroy)( dev );
	dev->flags.exists = 0;
    }

    for ( i = 1; i <= ws->num_devs.pick; i++ ) {
	dev = SIN_DEV(ws, SIN_PICK, i);
	if ( dev->dev_ops.destroy )
	    (*dev->dev_ops.destroy)( dev );
	dev->flags.exists = 0;
    }

    for ( i = 1; i <= ws->num_devs.stroke; i++ ) {
	dev = SIN_DEV(ws, SIN_STROKE, i);
	if ( dev->dev_ops.destroy )
	    (*dev->dev_ops.destroy)( dev );
	dev->flags.exists = 0;
    }

    for ( i = 1; i <= ws->num_devs.choice; i++ ) {
	dev = SIN_DEV(ws, SIN_CHOICE, i);
	if ( dev->dev_ops.destroy )
	    (*dev->dev_ops.destroy)( dev );
	dev->flags.exists = 0;
    }

    for ( i = 1; i <= ws->num_devs.val; i++ ) {
	dev = SIN_DEV(ws, SIN_VALUATOR, i);
	if ( dev->dev_ops.destroy )
	    (*dev->dev_ops.destroy)( dev );
	dev->flags.exists = 0;
    }

    for ( i = 1; i <= ws->num_devs.string; i++ ) {
	dev = SIN_DEV(ws, SIN_STRING, i);
	if ( dev->dev_ops.destroy )
	    (*dev->dev_ops.destroy)( dev );
	dev->flags.exists = 0;
    }
}

/*******************************************************************************
 * phg_sin_dev_init_devices
 *
 * DESCR:       Initialize devices on workspace
 * RETURNS:     N/A
 */

void phg_sin_dev_init_devices(
    Sin_input_ws *ws
    )
{
    Wst_defloc *idt_loc;
    Wst_defstroke *idt_stroke;
    Wst_defpick	*idt_pick;
    Wst_defchoice *idt_choice;
    Wst_defval *idt_val;
    Wst_defstring *idt_string;

    int i;
    Sin_input_device *dev;

#ifdef DEBUG
   printf("sin_dev: phg_sin_dev_init_devices\n");
   printf("\tinput_window = %x\n", (unsigned) ws->input_window);
#endif

    /* Assign initial and default workstation data */
    ws->notify_list = NULL;

    /* Assign default device data.
     *
     * NOTE:  Only items NOT set at device initialization are set here.
     * It's assumed that sin_init_device() will be called for each device
     * prior to using it (however, the application shouldn't be the one to
     * initate this call, the startup code using the input code should do
     * it).
     */

    idt_loc = ws->idt->locators;
    dev = ws->devices[SIN_CLASS_INDEX(SIN_LOCATOR)];
    for ( i = 1; i <= ws->num_devs.loc; i++, dev++, idt_loc++ ) {
	dev->inp_class = SIN_LOCATOR;
	dev->num = i;
	dev->data.locator.type = idt_loc->type;
	SET_DEFAULT_DEV_GENERIC_DATA(ws, dev);
	switch ( dev->data.locator.type ) {
	    case WST_LOC_TYPE_POINTER_BUTTON_1:
	    case WST_LOC_TYPE_POINTER_BUTTON_2:
	    case WST_LOC_TYPE_POINTER_BUTTON_3:
		dev->item_handle.window = ws->input_window;
		dev->dev_ops.init = NULL;
		dev->dev_ops.reset = NULL;
		dev->dev_ops.resize = phg_sin_cvs_device_resize;
		dev->dev_ops.create = phg_sin_cvs_create_device;
		dev->dev_ops.enable = phg_sin_cvs_device_enable;
		dev->dev_ops.disable = phg_sin_cvs_device_disable;
		dev->dev_ops.sample = phg_sin_cvs_device_sample;
		dev->dev_ops.repaint = phg_sin_cvs_device_repaint;
		dev->dev_ops.destroy = phg_sin_cvs_destroy_device;
		break;
	}
    }

    idt_stroke = ws->idt->strokes;
    dev = ws->devices[SIN_CLASS_INDEX(SIN_STROKE)];
    for ( i = 1; i <= ws->num_devs.stroke; i++, dev++, idt_stroke++ ) {
	dev->inp_class = SIN_STROKE;
	dev->num = i;
	dev->data.stroke.type = idt_stroke->type;
	SET_DEFAULT_DEV_GENERIC_DATA(ws, dev);
	switch ( dev->data.stroke.type ) {
	    case WST_STROKE_TYPE_POINTER_BUTTON_1:
	    case WST_STROKE_TYPE_POINTER_BUTTON_2:
	    case WST_STROKE_TYPE_POINTER_BUTTON_3:
		dev->item_handle.window = ws->input_window;
		dev->dev_ops.reset = NULL;
		dev->dev_ops.resize = phg_sin_cvs_device_resize;
		dev->dev_ops.create = phg_sin_cvs_create_device;
		dev->dev_ops.init = phg_sin_cvs_device_initialize;
		dev->dev_ops.enable = phg_sin_cvs_device_enable;
		dev->dev_ops.disable = phg_sin_cvs_device_disable;
		dev->dev_ops.sample = phg_sin_cvs_device_sample;
		dev->dev_ops.repaint = phg_sin_cvs_device_repaint;
		dev->dev_ops.destroy = phg_sin_cvs_destroy_device;
		break;
	}
    }

    idt_pick = ws->idt->picks;
    dev = ws->devices[SIN_CLASS_INDEX(SIN_PICK)];
    for ( i = 1; i <= ws->num_devs.pick; i++, dev++, idt_pick++ ) {
	dev->inp_class = SIN_PICK;
	dev->num = i;
	dev->data.pick.type = idt_pick->type;
	SET_DEFAULT_DEV_GENERIC_DATA(ws, dev);
	switch ( dev->data.pick.type ) {
	    case WST_PICK_TYPE_POINTER_BUTTON_1:
	    case WST_PICK_TYPE_POINTER_BUTTON_2:
	    case WST_PICK_TYPE_POINTER_BUTTON_3:
		dev->item_handle.window = ws->input_window;
		dev->dev_ops.init = NULL;
		dev->dev_ops.reset = NULL;
		dev->dev_ops.resize = NULL;
		dev->dev_ops.create = phg_sin_cvs_create_device;
		dev->dev_ops.enable = phg_sin_cvs_device_enable;
		dev->dev_ops.disable = phg_sin_cvs_device_disable;
		dev->dev_ops.sample = phg_sin_cvs_device_sample;
		dev->dev_ops.repaint = phg_sin_cvs_device_repaint;
		dev->dev_ops.destroy = phg_sin_cvs_destroy_device;
		break;
	}
    }


    idt_val = ws->idt->valuators;
    dev = ws->devices[SIN_CLASS_INDEX(SIN_VALUATOR)];
    for ( i = 1; i <= ws->num_devs.val; i++, dev++, idt_val++ ) {
	dev->inp_class = SIN_VALUATOR;
	dev->num = i;
	dev->data.valuator.type = idt_val->type;
	SET_DEFAULT_DEV_GENERIC_DATA(ws, dev);
	phg_sin_dev_boot_valuator( dev );
    }

    idt_choice = ws->idt->choices;
    dev = ws->devices[SIN_CLASS_INDEX(SIN_CHOICE)];
    for ( i = 1; i <= ws->num_devs.choice; i++, dev++, idt_choice++ ) {
	dev->inp_class = SIN_CHOICE;
	dev->num = i;
	dev->data.choice.type = idt_choice->type;
	SET_DEFAULT_DEV_GENERIC_DATA(ws, dev);
	phg_sin_dev_boot_choice( dev );
    }

    idt_string = ws->idt->strings;
    dev = ws->devices[SIN_CLASS_INDEX(SIN_STRING)];
    for ( i = 1; i <= ws->num_devs.string; i++, dev++, idt_string++ ) {
	dev->inp_class = SIN_STRING;
	dev->num = i;
	dev->data.string.type = idt_string->type;
	SET_DEFAULT_DEV_GENERIC_DATA(ws, dev);
	phg_sin_dev_boot_string( dev );
    }
}

