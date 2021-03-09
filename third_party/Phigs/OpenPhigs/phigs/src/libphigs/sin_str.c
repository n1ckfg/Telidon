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
#include <X11/Xaw/AsciiText.h>


/*******************************************************************************
 * reset_string_measure
 *
 * DESCR:       Reset string measure helper function
 * RETURNS:     N/A
 */

static void reset_string_measure(
    Sin_input_device *device
    )
{
    XawTextPosition pos;
    Widget src;
    XawTextBlock block;

    src = XawTextGetSource( device->item_handle.string.textw );
    /* Find end of text and remember it. */
    pos = XawTextSourceScan( src, 0, XawstAll, XawsdRight, 1, TRUE );
    device->data.string.last_pos = pos;
    if ( device->data.string.init_string ) {
	/* Insert the initial string. */
	block.firstPos = 0;
	block.length = strlen( device->data.string.init_string );
	block.ptr = device->data.string.init_string;
	block.format = FMT8BIT;
	XawTextReplace( device->item_handle.string.textw, pos, pos, &block );
    }
    XawTextSetInsertionPoint( device->item_handle.string.textw,
	pos + device->data.string.edit_pos );
}

/*******************************************************************************
 * update_string
 *
 * DESCR:       Update string helper function
 * RETURNS:     N/A
 */

static void update_string(
    Sin_input_device *device
    )
{
    Sin_string_device_data *data = &device->data.string;
    String string;
    Arg args[1];
    Widget src;
    XawTextPosition pos;

    data->string[0] = '\0';
    src = XawTextGetSource( device->item_handle.string.textw );
    pos = XawTextSourceScan( src, 0, XawstAll, XawsdRight, 1, TRUE );
    /* Buffer is "empty" if text has been deleted up to or before the
     * last start position.
     */
    if ( pos >= data->last_pos ) {
	XtSetArg( args[0], XtNstring, (XtArgVal)&string );
	XtGetValues( device->item_handle.string.textw, args, 1 );
	strncat( data->string, &string[data->last_pos], data->buf_size );
    }
}

#ifdef TODO
/*******************************************************************************
 * phg_sin_xt_string_event
 *
 * DESCR:       String event function
 * RETURNS:     N/A
 */

XtActionProc phg_sin_xt_string_event(
    Widget w,
    XEvent *event,
    String *params,
    Cardinal *num_params
    )
{
    Sin_input_device *device;

    XFindContext( XtDisplay(w), XtWindow(w), phg_sin_device_context_id,
	(caddr_t*)&device );
    update_string( device );
    if ( device->mode == SIN_EVENT ) {
	unsigned	status;
	status = phg_sin_ws_enque_events( 1, &device );
	if ( SIN_EVENT_NOT_ENQUED(status) )
	    XBell( XtDisplay(w), 0 );
	else
	    reset_string_measure( device );
    }
}
#endif

static XtTranslations		compiled_translations;
static String translations = "\
          <Key>Return:	newline() StringEvent() RequestSatisfied() \n\
	  ";

/*******************************************************************************
 * create_string
 *
 * DESCR:       Create string callback
 * RETURNS:     N/A
 */

static void create_string(
    Sin_input_device *device
    )
{
    char buf[20];
    Sin_string_handle *widgets = &device->item_handle.string;
    Widget parent = device->ws->shell;

    /* Most options are not explicitly set so that the user can override
     * them.  Fallbacks are specified instead (elsewhere).
     */

    /* Create the containing shell. */
    sprintf( buf, "string%d", device->num );
    widgets->shell =
	XtVaCreatePopupShell( buf, applicationShellWidgetClass, parent, NULL );

    /* Create the containing viewport. */
    widgets->pane = XtVaCreateManagedWidget( "viewport", viewportWidgetClass,
	    device->item_handle.string.shell,
	    NULL );

    /* Create the device. */
    widgets->textw = XtVaCreateManagedWidget( "text", asciiTextWidgetClass,
	widgets->pane,
	NULL );

    if ( !compiled_translations ) {
	compiled_translations = XtParseTranslationTable( translations );
    }
    XtOverrideTranslations( widgets->textw, compiled_translations );
}

/*******************************************************************************
 * enable_string
 *
 * DESCR:       Enable string callback
 * RETURNS:     N/A
 */

static void enable_string(
    Sin_input_device *device
    )
{
    /* Only create it if it's going to be used. */
    if ( !device->item_handle.string.shell )
	create_string( device );

    reset_string_measure( device );
    XtPopup( device->item_handle.string.shell, XtGrabNone );
#ifdef TODO
    if ( !device->flags.been_up_yet ) {
	XSaveContext( XtDisplay(device->item_handle.string.textw),
	    XtWindow(device->item_handle.string.textw),
	    phg_sin_device_context_id, (caddr_t)device );
	device->flags.been_up_yet = 1;

    }
#endif
}

/*******************************************************************************
 * sample_string
 *
 * DESCR:       Sample string callback
 * RETURNS:     N/A
 */

static void sample_string(
    Sin_input_device *device
    )
{
    if ( !device->item_handle.string.shell )
	create_string( device );
    update_string( device );
}

/*******************************************************************************
 * disable_string
 *
 * DESCR:       Disable string callback
 * RETURNS:     N/A
 */

static void disable_string(
    Sin_input_device *device
    )
{
    if ( device->item_handle.string.shell )
	XtPopdown( device->item_handle.string.shell );
}

/*******************************************************************************
 * destroy_string
 *
 * DESCR:       Destroy string callback
 * RETURNS:     N/A
 */

static void destroy_string(
    Sin_input_device *device
    )
{
    if ( device->item_handle.string.shell )
	XtDestroyWidget( device->item_handle.string.shell );
}
#endif

/*******************************************************************************
 * phg_sin_dev_boot_string
 *
 * DESCR:       Boot string device
 * RETURNS:     N/A
 */

void phg_sin_dev_boot_string(
    Sin_input_device *dev
    )
{
#ifdef REMOVED
    switch ( dev->data.string.type ) {
	case WST_STRING_TYPE_WINDOW:
	    dev->item_handle.string.shell = (Widget)NULL;
	    dev->item_handle.string.pane = (Widget)NULL;
	    dev->item_handle.string.textw = (Widget)NULL;
	    dev->dev_ops.reset = NULL;
	    dev->dev_ops.sample = sample_string;
	    dev->dev_ops.resize = NULL;
	    dev->dev_ops.repaint = NULL;
	    dev->dev_ops.destroy = destroy_string;
	    dev->dev_ops.create = NULL;
	    dev->dev_ops.init = NULL;
	    dev->dev_ops.enable = enable_string;
	    dev->dev_ops.disable = disable_string;
	    break;
    }
#endif
}

