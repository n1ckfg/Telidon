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

/*
 * Default device specific routines for input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <phigs/phg.h>
#include <phigs/ws_type.h>
#include <phigs/sin.h>
#include <phigs/private/sinP.h>
#ifdef REMOVED
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/Xaw/Viewport.h>
#include <X11/Xaw/List.h>

/*******************************************************************************
 * choice_notify
 *
 * DESCR:       Notity choice callback
 * RETURNS:     N/A
 */

static void choice_notify(
    Widget w,
    XtPointer client_data,
    XtPointer call_data
    )
{
    XawListReturnStruct		*selection = (XawListReturnStruct*)call_data;
    Sin_input_device		*device = (Sin_input_device *)client_data;
    Sin_choice_device_data	*data = &device->data.choice;

    data->cur_choice = selection->list_index + 1;
    if ( device->mode == SIN_EVENT ) {
	unsigned	status;
	status = phg_sin_ws_enque_events( 1, &device );
	if ( SIN_EVENT_NOT_ENQUED(status) )
	    XBell( XtDisplay(w), 0 );
    }
    /* The action proc takes care of REQUEST.  No additional action needed
     * for SAMPLE.
     */
}

/*******************************************************************************
 * enable_choice
 *
 * DESCR:       Enable choice device callback
 * RETURNS:     N/A
 */

static void enable_choice(
    Sin_input_device *device
    )
{
    Widget w;
    char buf[256];
    Sin_choice_device_data *data = &device->data.choice;
    Widget parent = device->ws->shell;

    /* Most options are not explicitly set so that the user can override
     * them.  Fallbacks are specified instead (elsewhere).
     */

    /* Create the containing shell. */
    sprintf( buf, "choice%d", device->num );
    device->item_handle.choice.shell =
	XtVaCreatePopupShell( buf, applicationShellWidgetClass, parent,
	    NULL );

    /* Create the containing viewport. */
    device->item_handle.choice.viewport =
	XtVaCreateManagedWidget( "viewport", viewportWidgetClass,
	    device->item_handle.choice.shell,
	    NULL );

    /* Create the list. */
    w = device->item_handle.choice.list =
	XtVaCreateManagedWidget( "list", listWidgetClass,
	    device->item_handle.choice.viewport,
	    XtNnumberStrings, (XtArgVal)data->count,
	    XtNlist, (XtArgVal)data->choices.strings,
	    NULL );
    XawListHighlight( device->item_handle.choice.list, data->cur_choice - 1 );
    XtAddCallback( device->item_handle.choice.list,
	XtNcallback, choice_notify, (XtPointer)device );

    XtPopup( device->item_handle.choice.shell, XtGrabNone );
#ifdef TODO
    if ( device->mode == SIN_REQUEST_PENDING )
	XSaveContext( XtDisplay(w), XtWindow(w), phg_sin_device_context_id,
	    (caddr_t)device );
#endif
}

/*******************************************************************************
 * disable_choice
 *
 * DESCR:       Disable choice device callback
 * RETURNS:     N/A
 */

static void disable_choice(
    Sin_input_device *device
    )
{
    XtDestroyWidget( device->item_handle.choice.shell );
}
#endif

/*******************************************************************************
 * phg_sin_dev_boot_choice
 *
 * DESCR:       Boot choice device
 * RETURNS:     N/A
 */

void phg_sin_dev_boot_choice(
    Sin_input_device *dev
    )
{
#ifdef REMOVED
    switch ( dev->data.choice.type ) {
	case WST_CHOICE_TYPE_LIST:
	    dev->dev_ops.reset = NULL;
	    dev->dev_ops.sample = NULL;
	    dev->dev_ops.resize = NULL;
	    dev->dev_ops.repaint = NULL;
	    dev->dev_ops.destroy = NULL;
	    dev->dev_ops.create = NULL;
	    dev->dev_ops.init = NULL;
	    dev->dev_ops.enable = enable_choice;
	    dev->dev_ops.disable = disable_choice;
	    break;
    }
#endif
}

