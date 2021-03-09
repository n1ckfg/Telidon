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
#include <phigs/private/wsxP.h>
#include <phigs/phg_dt.h>
#include <phigs/private/evtP.h>
#include <phigs/util.h>
#include <phigs/ws_inp.h>

/*******************************************************************************
 * resolve_locator
 *
 * DESCR:       Locator resolve callback
 * RETURNS:     TRUE or FALSE
 */

static int resolve_locator(
    Sin_input_device *dev,
    Pint int_data,
    Sin_window_pt *pt
    )
{
    Ws *ws = (Ws *)dev->client_data;
    int	status = 0;
    Ws_point dc_pt;
    Ppoint3 wc_pt;
    Pint view;

    /* Don't change the current measure if the point can't be resolved.  In
     * sample mode the old value will be reported.  In request and event
     * mode no event will be generated (nothing happens).
     */
    WS_DRWBL_TO_DC2(ws, &dev->data.locator.cur_pos, &dc_pt);
    if ( (*ws->resolve_locator)( ws, &dc_pt, 1, &view, &wc_pt ) ) {
	dev->data.locator.wc_pt.x = wc_pt.x;
	dev->data.locator.wc_pt.y = wc_pt.y;
	dev->data.locator.wc_pt.z = wc_pt.z;
	dev->data.locator.view = view;
	status = 1;
    }
    return status;
}

/*******************************************************************************
 * resolve_stroke
 *
 * DESCR:       Stroke resolve callback
 * RETURNS:     TRUE or FALSE
 */

static int resolve_stroke(
    Sin_input_device *dev,
    Pint count,
    XPoint *raw_pts
    )
{
    int	status = FALSE;
    Ws_point *dc_pts;
    Pint view;
    Ppoint_list3 wc_pts;
    Ws *ws = (Ws *)dev->client_data;

    int	i;

    /* Don't change the current measure if the points can't be resolved.
     * In sample mode the old value will be reported.  In request and event
     * mode no event will be generated (nothing happens).
     */
    if ( count <= 0 ) {
	dev->data.stroke.view = 0;
	dev->data.stroke.count = 0;
	return TRUE;
    }

    if ( !PHG_SCRATCH_SPACE( &ws->scratch, count * sizeof(Ws_point) ) ) {
	ERR_BUF( ws->erh, ERR900 );
	return FALSE;
    }

    dc_pts = (Ws_point *)ws->scratch.buf;
    for ( i = 0; i < count; i++ ) {
	WS_DRWBL_TO_DC2(ws, &raw_pts[i], &dc_pts[i]);
    }

    wc_pts.num_points = 0;
    wc_pts.points = dev->data.stroke.wc_pts;
    if ( (*ws->resolve_stroke)( ws, count, dc_pts, 1, &view, &wc_pts ) ) {
	dev->data.stroke.view = view;
	dev->data.stroke.count = wc_pts.num_points;
	status = 1;
    }

    return status;
}

/*******************************************************************************
 * resolve_pick
 *
 * DESCR:       Pick resolve callback
 * RETURNS:     TRUE or FALSE
 */

static int resolve_pick(
    Sin_input_device *dev,
    Pint echo,
    Sin_window_pt *pt
    )
{
    int	status = FALSE;
    Ws_point dc_pt;
    Ppick pick;
    Ppick_path_elem *path;
    Ws *ws = (Ws *)dev->client_data;
    Ws_inp_pick	*dev_state = WS_INP_DEV(ws, pick, dev->num);
    Ppick *cur_pick = &dev->data.pick.cur_pick;

    WS_DRWBL_TO_DC2(ws, &dev->data.pick.cur_pos, &dc_pt);

    if ( !(*ws->resolve_pick)( ws, dev_state, echo, &dc_pt, &pick ) )
	return 0;

    if ( pick.status == PIN_STATUS_OK && pick.pick_path.depth > 0 ) {
	/* Get space for the converted path. */
	if ( dev_state->mode == POP_REQ || dev_state->mode == POP_SAMPLE ) {
	    /* Use the scratch path.  Enlarge it if it's too small. */
	    if ( dev_state->scratch_path.depth >= pick.pick_path.depth )
		path = dev_state->scratch_path.path_list;
	    else {
		path = (Ppick_path_elem *)
		    malloc(pick.pick_path.depth * sizeof(Ppick_path_elem));
		if ( path ) {
		    if ( dev_state->scratch_path.depth > 0 )
			free(dev_state->scratch_path.path_list);
		    dev_state->scratch_path.path_list = path;
		}
	    }
	} else {
	    /* EVENT mode:  allocate unique space so the event can
	     * just be placed directly on the input queue.  It'll
	     * be freed by the input code.
	     */
	    path = (Ppick_path_elem*) malloc( (unsigned)
		(pick.pick_path.depth * sizeof(Ppick_path_elem)) );
	}

	if ( !path ) {
	    ERR_BUF( ws->erh, ERR900);
	} else {
	    memcpy(path, pick.pick_path.path_list,
		pick.pick_path.depth * sizeof(Ppick_path_elem) );
	    cur_pick->status = pick.status;
	    cur_pick->pick_path.path_list = path;
	    cur_pick->pick_path.depth = pick.pick_path.depth;
	    status = 1;
	}

    } else {	/* No pick */
	cur_pick->status = PIN_STATUS_NONE;
	cur_pick->pick_path.depth = 0;
	status = 1;
    }

    return status;
}

/*******************************************************************************
 * init_sin_locator
 *
 * DESCR:       Initialize locator device helper
 * RETURNS:     N/A
 */

static void init_sin_locator(
    Ws *ws,
    Ws_input_ws	*iws,
    Ws_inp_loc *dev,
    XPoint *init_dwbl_pt
    )
{
    Sin_dev_init_data new_data;
    Sin_dev_init_data *nd = &new_data;

    nd->data.locator.init_pos.x = init_dwbl_pt->x;
    nd->data.locator.init_pos.y = init_dwbl_pt->y;
    nd->data.locator.cur_pos = nd->data.locator.init_pos;
    WSINP_DC_ECHO_TO_DRWBL_ECHO2( ws, &dev->e_volume, &nd->echo_area )
    nd->client_data = (caddr_t)ws;
    nd->data.locator.wc_pt.x = dev->loc.position.x;
    nd->data.locator.wc_pt.y = dev->loc.position.y;
    nd->data.locator.wc_pt.z = dev->loc.position.z;
    nd->data.locator.view = dev->loc.view_ind;
    nd->data.locator.resolve = resolve_locator;
    switch ( nd->pe_type = dev->pet ) {
	/* Assignment of PET-specific data goes here. */
	case 1:
	default:
	    break;
    }
    phg_sin_init_device( iws->sin_handle, SIN_LOCATOR, dev->num, nd );
}

/*******************************************************************************
 * init_locator
 *
 * DESCR:       Initialize locator callback
 * RETURNS:     N/A
 */

static void init_locator(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_loc *dev,
    Phg_args_inp_init_dev *args,
    int two_d
    )
{
    XPoint init_dwbl_pt;
    Pint num_pts = 1;

    Ploc3 *init = &args->data.loc.init;

    if ( two_d )
	init->position.z = dev->loc.position.z;
    if ( !(*ws->map_initial_points)( ws, init->view_ind, &num_pts,
	&init->position, &init_dwbl_pt ) || num_pts != 1 ) {
	ERR_BUF( ws->erh, ERR261 );
    } else {	/* All the data's okay. */
	dev->pet = args->pet;
	/* The binding checks the data record for this device class. */
	dev->record = args->data.loc.rec;
	if ( two_d ) {
	    SET_ECHO_AREA(args->echo_volume, dev->e_volume);
	    dev->loc.view_ind = init->view_ind;
	    dev->loc.position.x = init->position.x;
	    dev->loc.position.y = init->position.y;
	} else {
	    dev->e_volume = args->echo_volume;
	    dev->loc = *init;
	}
	init_sin_locator( ws, iws, dev, &init_dwbl_pt );
    }
}

/*******************************************************************************
 * init_sin_stroke
 *
 * DESCR:       Initialize stroke helper function
 * RETURNS:     N/A
 */

static void init_sin_stroke(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_stroke *dev,
    XPoint *init_dwbl_pts
    )
{
    Sin_dev_init_data new_data;
    Sin_dev_init_data *nd = &new_data;

    nd->data.stroke.view = dev->stroke.view_ind;
    nd->data.stroke.init_count = dev->stroke.num_points;
    nd->data.stroke.count = dev->stroke.num_points;
    nd->data.stroke.wc_pts = dev->stroke.points; 
    nd->data.stroke.init_pts = init_dwbl_pts; 
    WSINP_DC_ECHO_TO_DRWBL_ECHO2( ws, &dev->e_volume, &nd->echo_area )
    nd->client_data = (caddr_t)ws;
    nd->data.stroke.resolve = resolve_stroke;
    nd->data.stroke.edit_pos
	= dev->record.init_pos - 1; /* 0 origin internally */
    nd->data.stroke.buf_size = dev->record.buffer_size;
    switch ( nd->pe_type = dev->pet ) {
	/* Assignment of PET-specific data goes here. */
	case 1:
	default:
	    /* No PET data. */
	    break;
    }
    phg_sin_init_device( iws->sin_handle, SIN_STROKE, dev->num, nd );
}

/*******************************************************************************
 * init_stroke
 *
 * DESCR:       Initialize stroke callback
 * RETURNS:     N/A
 */

static void init_stroke(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_stroke *dev,
    Phg_args_inp_init_dev *args,
    int two_d
    )
{
    XPoint *init_dwbl_pts;
    Ppoint3 *init_wc_pts = NULL;

    Pstroke3 *init = &args->data.stk.init;

    /* Take care of any initial points. */
    if ( init->num_points > 0 ) {
	Pint		num_pts;
	unsigned	size;

	/* Get space for the WC and drawable versions of the points. */
	size = init->num_points * (sizeof(Ppoint3) + sizeof(XPoint));
	if ( !(init_wc_pts = (Ppoint3 *)malloc( size )) ) {
	    ERR_BUF( ws->erh, ERR900 );
	    return;
	}
	init_dwbl_pts = (XPoint *)(init_wc_pts + init->num_points);
	memcpy(init_wc_pts,
               init->points,
               init->num_points * sizeof(Ppoint3) );

	if ( two_d ) {
	    /* Fill in the Z value. */
	    int i;

	    for ( i = 0; i < init->num_points; i++ )
		init_wc_pts[i].z = 0.0;
	}

	/* Check and map the initial points. */
	num_pts = init->num_points;
	if ( !(*ws->map_initial_points)( ws, init->view_ind, &num_pts,
		init_wc_pts, init_dwbl_pts ) || num_pts != init->num_points ) {
	    ERR_BUF( ws->erh, ERR261 );
	    return;
	}
    }

    /* All the data's okay. */
    dev->pet = args->pet;
    /* The binding checks the data record for this device class. */
    dev->record = args->data.stk.rec;
    /* Free the old points, if any. */
    if ( dev->stroke.points )
	free(dev->stroke.points);
    dev->stroke.view_ind = init->view_ind;
    dev->stroke.num_points = init->num_points;
    dev->stroke.points = init_wc_pts;
    if ( two_d ) {
	SET_ECHO_AREA(args->echo_volume, dev->e_volume);
    } else {
	dev->e_volume = args->echo_volume;
    }
    init_sin_stroke( ws, iws, dev, init_dwbl_pts );
}

/* These are the hardcoded choice strings for pet 1 and are always passed to
   the sin package for choice devices using pet 1.  It's up to the sin
   package if they are used or not (some devices don't use strings, in
   which case sin defines the policy).  These are not part of the device
   state, the pet 1 datarecord has no data, they are part of the policy for
   choice devices.
 */
static char *pet1_strings[] = {
    "1", "2", "3", "4", "5",
    "6", "7", "8", "9", "10"
};

/*******************************************************************************
 * init_sin_choice
 *
 * DESCR:       Initialize choice device helper
 * RETURNS:     N/A
 */

static void init_sin_choice(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_choice *dev
    )
{
    Sin_dev_init_data new_data;
    Sin_dev_init_data *nd = &new_data;

    WSINP_DC_ECHO_TO_DRWBL_ECHO2( ws, &dev->e_volume, &nd->echo_area )
    nd->client_data = (caddr_t)ws;
    if ( dev->choice.status == PIN_STATUS_OK )
	nd->data.choice.init_choice = dev->choice.choice;
    else
	nd->data.choice.init_choice = 1;
    switch ( nd->pe_type = dev->pet ) {
	case 1:
	default:
	    /* No user-specified data in data record, for portability. */
	    nd->data.choice.count = sizeof(pet1_strings)/sizeof(char*);
	    nd->data.choice.choices.strings = pet1_strings;
	    break;
	case 3:
	    nd->data.choice.count = dev->record.pets.pet_r3.num_strings;
	    nd->data.choice.choices.strings = dev->record.pets.pet_r3.strings;
	    break;
    }
    phg_sin_init_device( iws->sin_handle, SIN_CHOICE, dev->num, nd );
}

/*******************************************************************************
 * setup_choice_init
 *
 * DESCR:       Initialize setup choice helper function
 * RETURNS:     Error code or zero
 */

static int setup_choice_init(
    Ws_inp_choice *dev,
    Phg_args_inp_init_dev *args,
    int two_d
    )
{
    int	i, cnt;
    int	errnum = 0;	/* success is the default */

    dev->pet = args->pet;
    dev->choice.status = args->data.cho.status;
    dev->choice.choice = args->data.cho.init;
    if ( two_d ) {
	SET_ECHO_AREA( args->echo_volume, dev->e_volume);
    } else {
	dev->e_volume = args->echo_volume;
    }

    /* Take care of pets that need more data moving/mapping. */
    switch ( dev->pet ) {
	case 3: {
	    char **strs, *new_strs;

	    /* Get space for the new list of strings and copy them.*/
	    cnt = dev->record.pets.pet_r3.num_strings
		= args->data.cho.rec.pets.pet_r3.num_strings;
	    if ( cnt > 0 ) {
		/* Get pointer array space. */
		strs = (char**) malloc( cnt * sizeof(char*));
		if (strs == NULL) {
		    errnum = ERR900;
		/* Get space for ALL the strings. */
		} else if ( !( strs[0]
			= (char*) malloc(args->data.cho.string_list_size)) ) {
		    errnum = ERR900;
		    free(strs);
		} else {
		    dev->strings_length = args->data.cho.string_list_size; 
		    new_strs =
			(char*)args->data.cho.rec.pets.pet_r3.strings;
		    memcpy(strs[0], new_strs, args->data.cho.string_list_size);
		    /* Resolve the pointers into the "strings" array. */
		    for ( i = 1; i < cnt; i++ )
			strs[i] = strs[i-1] + strlen(strs[i-1]) + 1;
		    dev->record.pets.pet_r3.strings = strs;
		}
	    }
	}
	break;
    }

    return errnum;
}

/*******************************************************************************
 * free_choice
 *
 * DESCR:       Free choice helper function
 * RETURNS:     N/A
 */

static void free_choice(
    Ws_inp_choice *dev
    )
{
    switch ( dev->pet ) {
	case 3:
	    if ( dev->record.pets.pet_r3.num_strings > 0 ) {
		free(dev->record.pets.pet_r3.strings[0]);
		free(dev->record.pets.pet_r3.strings);
	    }
	    break;
    }
}

/*******************************************************************************
 * init_choice
 *
 * DESCR:       Initialize choice callback
 * RETURNS:     N/A
 */

static void init_choice(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_choice *dev,
    Phg_args_inp_init_dev *args,
    int two_d
    )
{
    Ws_inp_choice new_dev;
    int errnum;

    /* Initialize and operate on a temporary copy of the state. */
    new_dev = *dev;
    errnum = setup_choice_init( &new_dev, args, two_d );
    if ( errnum ) {
	ERR_BUF( ws->erh, errnum);
    } else {
	init_sin_choice( ws, iws, &new_dev );
	/* Clean up the old state if needed. */
	free_choice( dev );
	/* Swap the old with the new if it all worked.  */
	*dev = new_dev;
    }
}

/*******************************************************************************
 * init_sin_valuator
 *
 * DESCR:       Initialize valuator device helper
 * RETURNS:     N/A
 */

static void init_sin_valuator(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_val *dev
    )
{
    Sin_dev_init_data new_data;
    Sin_dev_init_data *nd = &new_data;

    WSINP_DC_ECHO_TO_DRWBL_ECHO2( ws, &dev->e_volume, &nd->echo_area )
    nd->client_data = (caddr_t)ws;
    nd->data.valuator.init_value = dev->val;
    nd->data.valuator.low = dev->record.low;
    nd->data.valuator.high = dev->record.high;
    switch ( nd->pe_type = dev->pet) {
	case 1:
	default:
	    /* No user specifed data in data record, for portability. */
	    nd->data.valuator.label = WST_DEFAULT_VALUATOR_LABEL;
	    nd->data.valuator.format = WST_DEFAULT_VALUATOR_FORMAT;
	    nd->data.valuator.low_label = WST_DEFAULT_VALUATOR_LOW_LABEL;
	    nd->data.valuator.high_label = WST_DEFAULT_VALUATOR_HIGH_LABEL;
	    break;
	case -1:
	    nd->data.valuator.label = dev->record.pets.pet_u1.label;
	    nd->data.valuator.format = dev->record.pets.pet_u1.format;
	    nd->data.valuator.low_label = dev->record.pets.pet_u1.low_label;
	    nd->data.valuator.high_label = dev->record.pets.pet_u1.high_label;
	    break;
    }
    phg_sin_init_device( iws->sin_handle, SIN_VALUATOR, dev->num, nd);
}

/*******************************************************************************
 * setup_val_init
 *
 * DESCR:       Initialize valuator helper function
 * RETURNS:     Error code or zero
 */

static int setup_val_init(
    Ws_inp_val *dev,
    Phg_args_inp_init_dev *args,
    int two_d
    )
{
    int size;
    int errnum = 0;            /* success is the default */
    char *strings;

    /* Update workstation state. */
    dev->pet = args->pet;
    dev->val = args->data.val.init;
    dev->record.low = args->data.val.rec.low;
    dev->record.high = args->data.val.rec.high;
    if ( two_d ) {
	SET_ECHO_AREA( args->echo_volume, dev->e_volume);
    } else {
	dev->e_volume = args->echo_volume;
    }

    /* Take care of pets that need more data moving/mapping. */
    switch ( args->pet ) {
	case -1:
	    size = args->data.val.counts[0] + args->data.val.counts[1] +
		args->data.val.counts[2] + args->data.val.counts[3];
	    strings = (char *) malloc( size );
	    if (strings == NULL) {
		errnum = ERR900;
	    } else {
		dev->string_buf = strings;
		if ( args->data.val.counts[0] > 0 ) {
		    dev->record.pets.pet_u1.label = strings;
		    strings += args->data.val.counts[0];
		    strcpy( dev->record.pets.pet_u1.label,
			args->data.val.rec.pets.pet_u1.label );
		}
		if ( args->data.val.counts[1] > 0 ) {
		    dev->record.pets.pet_u1.format = strings;
		    strings += args->data.val.counts[1];
		    strcpy( dev->record.pets.pet_u1.format,
			args->data.val.rec.pets.pet_u1.format );
		}
		if ( args->data.val.counts[2] > 0 ) {
		    dev->record.pets.pet_u1.low_label = strings;
		    strings += args->data.val.counts[2];
		    strcpy( dev->record.pets.pet_u1.low_label,
			args->data.val.rec.pets.pet_u1.low_label );
		}
		if ( args->data.val.counts[3] > 0 ) {
		    dev->record.pets.pet_u1.high_label = strings;
		    strings += args->data.val.counts[3];
		    strcpy( dev->record.pets.pet_u1.high_label,
			args->data.val.rec.pets.pet_u1.high_label );
		}
	    }
	    break;
    }

    return errnum;
}

/*******************************************************************************
 * free_valuator
 *
 * DESCR:       Free valuator device helper
 * RETURNS:     N/A
 */

static void free_valuator(
    Ws_inp_val *dev
    )
{
    switch ( dev->pet ) {
	case -1:
	    if ( dev->string_buf )
		free(dev->string_buf);
	    break;
    }
}

/*******************************************************************************
 * init_valuator
 *
 * DESCR:       Initialize valuator device callback
 * RETURNS:     N/A
 */

static void init_valuator(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_val *dev,
    Phg_args_inp_init_dev *args,
    int two_d
    )
{
    int errnum;
    Ws_inp_val new_dev;

    /* Initialize and operate on a temporary copy of the state. */
    new_dev = *dev;
    errnum = setup_val_init( &new_dev, args, two_d );
    if ( errnum ) {
	ERR_BUF( ws->erh, errnum);
    } else {
	init_sin_valuator( ws, iws, &new_dev );
	/* Clean up the old state if needed. */
	free_valuator( dev );
	/* Swap the old with the new if it all worked. */
	*dev = new_dev;
    }
}

/*******************************************************************************
 * init_sin_pick
 *
 * DESCR:       Initialize pick device helper function
 * RETURNS:     N/A
 */

static void init_sin_pick(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_pick *dev
    )
{
    Sin_dev_init_data new_data;
    Sin_dev_init_data *nd = &new_data;

    WSINP_DC_ECHO_TO_DRWBL_ECHO2( ws, &dev->e_volume, &nd->echo_area )
    nd->client_data = (caddr_t)ws;
    nd->data.pick.init_pick = dev->pick;
    nd->data.pick.resolve = resolve_pick;
    nd->data.pick.init_pos.x = -1;
    nd->data.pick.init_pos.y = -1;
    phg_sin_init_device( iws->sin_handle, SIN_PICK, dev->num, nd );
}

/*******************************************************************************
 * init_pick
 *
 * DESCR:       Initialize pick device callback
 * RETURNS:     N/A
 */

static void init_pick(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_pick *dev,
    Phg_args_inp_init_dev *args,
    int two_d
    )
{
    Ppick *init = &args->data.pik.init;
    Ppick_path_elem *init_path;
    unsigned size;

    /* Have the initial path checked if the ws wants it to be. */
    if ( ws->valid_pick_path && !(*ws->valid_pick_path)( ws, init ) ) {
	ERR_BUF( ws->erh, ERR261 );
	return;
    }

    /* Copy initial pick to state list. */
    if ( init->status == PIN_STATUS_OK && init->pick_path.depth > 0 ) {
	size = init->pick_path.depth * sizeof(Ppick_path_elem);
	if ( !(init_path = (Ppick_path_elem *)malloc( size )) ) {
	    ERR_BUF(ws->erh, ERR900);
	    return;
	} else
            memcpy(init_path,
	           init->pick_path.path_list,
		   (int) size);
    } else
	init_path = NULL;

    /* Free the old path in the state list.  Do this after we are sure
     * the new data is okay so that we can truly "ignore" the function
     * when there is an error.
     */
    if ( dev->pick.status == PIN_STATUS_OK && dev->pick.pick_path.depth > 0 )
	free(dev->pick.pick_path.path_list);

    dev->pet = args->pet;
    dev->record = args->data.pik.rec;
    dev->pick = *init;
    dev->pick.pick_path.path_list = init_path;
    dev->order = args->data.pik.porder;

    if ( two_d ) {
	SET_ECHO_AREA(args->echo_volume, dev->e_volume);
    } else
	dev->e_volume = args->echo_volume;
    init_sin_pick( ws, iws, dev );
}

/*******************************************************************************
 * init_sin_string
 *
 * DESCR:       Initialize string device helper function
 * RETURNS:     N/A
 */

static void init_sin_string(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_string *dev
    )
{
    Sin_dev_init_data new_data;
    Sin_dev_init_data *nd = &new_data;

    WSINP_DC_ECHO_TO_DRWBL_ECHO2( ws, &dev->e_volume, &nd->echo_area )
    nd->client_data = (caddr_t)ws;
    nd->data.string.init_string = dev->string;
    nd->data.string.buf_size = dev->record.buffer_size;
    nd->data.string.edit_pos = dev->record.init_pos;
    phg_sin_init_device( iws->sin_handle, SIN_STRING, dev->num, nd);
}

/*******************************************************************************
 * init_string
 *
 * DESCR:       Initialize string device callback
 * RETURNS:     N/A
 */

static void init_string(
    Ws *ws,
    Ws_input_ws *iws,
    Ws_inp_string *dev,
    Phg_args_inp_init_dev *args,
    int two_d
    )
{
    Phg_string *init = &args->data.str.init;
    char *init_str;

    /* Copy initial string to state list. */
    /* TODO: detect allocation failure and free this at ws close. */
    if ( init->length > 0 ) {
	init_str = (char *) malloc( init->length );
        if (init_str != NULL) {
	   strcpy( init_str, init->string );
        }
    } else
	init_str = NULL;

    dev->pet = args->pet;
    dev->record = args->data.str.rec;
    if ( dev->length > 0 ) {
	free(dev->string);
	dev->string = NULL;
    }
    dev->length = init->length;
    dev->string = init_str;

    if ( two_d ) {
	SET_ECHO_AREA( args->echo_volume, dev->e_volume);
    } else
	dev->e_volume = args->echo_volume;
    init_sin_string( ws, iws, dev);
}

/*******************************************************************************
 * phg_ws_inp_init_device
 *
 * DESCR:       Initialize workstation input device
 * RETURNS:     N/A
 */

void phg_ws_inp_init_device(
    Ws *ws,
    Phg_args_inp_init_dev *args
    )
{
    Ws_input_ws *iws = (Ws_input_ws*)&ws->in_ws;
    Ws_inp_device_handle dev;
    Pop_mode mode;
    int two_d;

#ifdef DEBUG
    printf("ws_inp: phg_ws_inp_init_device\n");
#endif

    phg_wsx_update_ws_rect( ws );
    switch (args->idev_class) {
        case PHG_ARGS_INP_LOC3:
        case PHG_ARGS_INP_LOC:
            dev.loc = &iws->devs.locator[args->dev-1];
            mode = dev.loc->mode;
            if (mode == POP_REQ) {
                two_d = args->idev_class == PHG_ARGS_INP_LOC ? 1 : 0;
                init_locator( ws, iws, dev.loc, args, two_d );
            }
            else {
                ERR_BUF( ws->erh, ERR251 );
            }
            break;
        case PHG_ARGS_INP_STK3:
        case PHG_ARGS_INP_STK:
            dev.stk = &iws->devs.stroke[args->dev-1];
            mode = dev.stk->mode;
            if (mode == POP_REQ) {
                two_d = args->idev_class == PHG_ARGS_INP_STK ? 1 : 0;
                init_stroke( ws, iws, dev.stk, args, two_d );
            }
            else {
                ERR_BUF( ws->erh, ERR251 );
            }
	    break;
        case PHG_ARGS_INP_CHC3:
        case PHG_ARGS_INP_CHC:
            dev.cho = &iws->devs.choice[args->dev-1];
            mode = dev.cho->mode;
            if (mode == POP_REQ) {
                two_d = args->idev_class == PHG_ARGS_INP_CHC ? 1 : 0;
                init_choice( ws, iws, dev.cho, args, two_d );
            }
            else {
                ERR_BUF( ws->erh, ERR251 );
            }
            break;
        case PHG_ARGS_INP_VAL3:
        case PHG_ARGS_INP_VAL:
            dev.val = &iws->devs.valuator[args->dev-1];
            mode = dev.val->mode;
            if (mode == POP_REQ) {
                two_d = args->idev_class == PHG_ARGS_INP_VAL ? 1 : 0;
                init_valuator( ws, iws, dev.val, args, two_d );
            }
            else {
                ERR_BUF( ws->erh, ERR251 );
            }
            break;
        case PHG_ARGS_INP_PIK3:
        case PHG_ARGS_INP_PIK:
            dev.pik = &iws->devs.pick[args->dev-1];
            mode = dev.pik->mode;
            if (mode == POP_REQ) {
                two_d = args->idev_class == PHG_ARGS_INP_PIK ? 1 : 0;
                init_pick( ws, iws, dev.pik, args, two_d );
            }
            else {
                ERR_BUF( ws->erh, ERR251 );
            }
            break;
        case PHG_ARGS_INP_STR3:
        case PHG_ARGS_INP_STR:
            dev.str = &iws->devs.string[args->dev-1];
            mode = dev.str->mode;
            if (mode == POP_REQ) {
                two_d = args->idev_class == PHG_ARGS_INP_STR ? 1 : 0;
                init_string( ws, iws, dev.str, args, two_d );
            }
            else {
                ERR_BUF( ws->erh, ERR251 );
            }
            break;
    }

    XFlush( ws->display );
}

/*******************************************************************************
 * init_all_devices
 *
 * DESCR:       Initialize all workstation input device helper function
 * RETURNS:     N/A
 */

static void init_all_devices(
    Ws *ws,
    Ws_input_ws *iws,
    Wst_input_wsdt *idt
    )
{
    Pint num_pts;
    Ws_inp_loc *loc_dev;
    XPoint init_dwbl_pt;
    int i;

#ifdef DEBUG
    printf("ws_inp: init_all_devices\n");
#endif

    for ( i = 0; i < iws->num_devs.loc; i++ ) {
	loc_dev = &iws->devs.locator[i];

	num_pts = 1;
	(void)(*ws->map_initial_points)( ws, loc_dev->loc.view_ind,
	    &num_pts, &loc_dev->loc.position, &init_dwbl_pt );
	init_sin_locator( ws, iws, loc_dev, &init_dwbl_pt );
    }

    for ( i = 0; i < iws->num_devs.stroke; i++ ) {
	init_sin_stroke( ws, iws, &iws->devs.stroke[i], (XPoint *)NULL );
    }

    for ( i = 0; i < iws->num_devs.pick; i++ ) {
	init_sin_pick( ws, iws, &iws->devs.pick[i] );
    }

    for ( i = 0; i < iws->num_devs.choice; i++ ) {
	init_sin_choice( ws, iws, &iws->devs.choice[i] );
    }

    for ( i = 0; i < iws->num_devs.val; i++ ) {
	init_sin_valuator( ws, iws, &iws->devs.valuator[i] );
    }

    for ( i = 0; i < iws->num_devs.string; i++ ) {
	init_sin_string( ws, iws, &iws->devs.string[i] );
    }
}

/*******************************************************************************
 * init_input_state
 *
 * DESCR:       Initialize input state helper function
 * RETURNS:     TRUE or FALSE
 */

static int init_input_state(
    Ws *ws,
    Wst_input_wsdt *idt
    )
{
    int i;
    Ws_input_ws *iws = &ws->in_ws;
    iws->num_devs = idt->num_devs;

#ifdef DEBUG
    printf("ws_inp: init_input_state\n");
#endif

    iws->devs.locator = (Ws_inp_loc*)
	calloc( (unsigned)iws->num_devs.loc, sizeof(Ws_inp_loc));
    if (iws->devs.locator == NULL) {
	goto no_mem;
    }

    iws->devs.stroke = (Ws_inp_stroke*)
	calloc( (unsigned)iws->num_devs.stroke, sizeof(Ws_inp_stroke));
    if (iws->devs.stroke == NULL) {
	goto no_mem;
    }

    iws->devs.pick = (Ws_inp_pick*)
	calloc( (unsigned)iws->num_devs.pick, sizeof(Ws_inp_pick));
    if (iws->devs.pick == NULL) {
	goto no_mem;
    }

    iws->devs.valuator = (Ws_inp_val*)
	calloc( (unsigned)iws->num_devs.val, sizeof(Ws_inp_val));
    if (iws->devs.valuator == NULL) {
	goto no_mem;
    }

    iws->devs.choice = (Ws_inp_choice*)
	calloc( (unsigned)iws->num_devs.choice, sizeof(Ws_inp_choice));
    if (iws->devs.choice == NULL) {
	goto no_mem;
    }

    iws->devs.string = (Ws_inp_string*)
	calloc( (unsigned)iws->num_devs.string, sizeof(Ws_inp_string));
    if (iws->devs.string == NULL) {
	goto no_mem;
    }

    {
	Ws_inp_loc	*loc = iws->devs.locator;
	Wst_defloc	*def_loc = idt->locators;

	for ( i = 0; i < iws->num_devs.loc; i++, loc++, def_loc++) {
	    WSINP_INIT_COMMON_FIELDS( loc, def_loc)
	    loc->num = i + 1;
	    loc->loc.view_ind = 0;
	    loc->loc.position = def_loc->position;
	}
    }

    {
	Ws_inp_stroke	*stk = iws->devs.stroke;
	Wst_defstroke	*def_stk = idt->strokes;

	for ( i = 0; i < iws->num_devs.stroke; i++, stk++, def_stk++) {
	    	WSINP_INIT_COMMON_FIELDS( stk, def_stk)
	    stk->num = i + 1;
	    stk->stroke.view_ind = 0;
	    /* The initial stroke buffer is only as big as it needs to be,
	     * which is zero when the device is initialized.
	     */
	    stk->stroke.num_points = 0;
	    stk->stroke.points = NULL;
	}
    }

    {
	Ws_inp_pick	*pick = iws->devs.pick;
	Wst_defpick	*def_pick = idt->picks;
	Pint		*dev_types;
	Pint		num_dev_types;

	if ( ws->type->desc_tbl.xwin_dt.num_pick_device_types <= 0 ) {
	    iws->num_devs.pick = 0;
	    idt->num_devs.pick = 0;
	}

	dev_types = ws->type->desc_tbl.xwin_dt.pick_device_types;
	num_dev_types = ws->type->desc_tbl.xwin_dt.num_pick_device_types;
	for ( i = 0; i < iws->num_devs.pick; i++, pick++, def_pick++) {
	    WSINP_INIT_COMMON_FIELDS( pick, def_pick)
	    pick->num = i + 1;
	    pick->order = def_pick->order;
	    pick->pick.status = PIN_STATUS_NONE;
	    pick->pick.pick_path.depth = 0;
	    pick->pick.pick_path.path_list = NULL;
	    pick->ap_size = 5.0;	/* DC units */
	    pick->dev_type = i >= num_dev_types ? dev_types[0] : dev_types[i];
            pick->filter.incl = phg_nset_create(WS_MAX_NAMES_IN_NAMESET);
            if (pick->filter.incl == NULL) {
                goto no_mem;
            }
            pick->filter.excl = phg_nset_create(WS_MAX_NAMES_IN_NAMESET);
            if (pick->filter.excl == NULL) {
                goto no_mem;
            }
	}
    }

    {
	Ws_inp_val	*val = iws->devs.valuator;
	Wst_defval	*def_val = idt->valuators;

	for ( i = 0; i < iws->num_devs.val; i++, val++, def_val++) {
	    WSINP_INIT_COMMON_FIELDS( val, def_val)
	    val->num = i + 1;
	    val->val= def_val->value;
	}
    }

    {
	Ws_inp_choice	*cho = iws->devs.choice;
	Wst_defchoice	*def_cho = idt->choices;

	for ( i = 0; i < iws->num_devs.choice; i++, cho++, def_cho++) {
	    WSINP_INIT_COMMON_FIELDS( cho, def_cho)
	    cho->num = i + 1;
	    cho->choice.status = PIN_STATUS_NONE;
	}
    }

    {
	Ws_inp_string	*str = iws->devs.string;
	Wst_defstring	*def_str = idt->strings;

	for ( i = 0; i < iws->num_devs.string; i++, str++, def_str++) {
	    WSINP_INIT_COMMON_FIELDS( str, def_str)
	    str->num = i + 1;
	    /* The initial string buffer is only as big as it needs to be,
	     * minimum size of 1, and changes when the device is initialized.
	     */
	    str->length = 1;
	    str->string = (char*) malloc(str->length*sizeof(char));
            if (str->string == NULL) {
		goto no_mem;
            }
	    *str->string = '\0';
	}
    }

    return TRUE;

no_mem:	/* ran out of memory somewhere! */
    ERR_BUF( ws->erh, ERR900);
    if (iws->devs.locator != NULL) {
        free(iws->devs.locator);
    }
    if (iws->devs.stroke != NULL) {
        free(iws->devs.stroke);
    }
    Ws_inp_pick *pick = iws->devs.pick;
    if (pick != NULL) {
        for (i = 0; i < iws->num_devs.pick; i++, pick++) {
            if (pick->filter.incl != NULL) {
                phg_nset_destroy(pick->filter.incl);
            }
            if (pick->filter.excl != NULL) {
                phg_nset_destroy(pick->filter.excl);
            }
        }
    }
    if (iws->devs.pick != NULL) {
        free(iws->devs.pick);
    }
    if (iws->devs.valuator != NULL) {
        free(iws->devs.valuator);
    }
    if (iws->devs.choice != NULL) {
        free(iws->devs.choice);
    }
    if (iws->devs.string != NULL) {
        free(iws->devs.string);
    }

    return FALSE;
}

/*******************************************************************************
 * send_request
 *
 * DESCR:       Send reuqest callback function
 * RETURNS:     N/A
 */

static void send_request(
    Ws *ws,
    Sin_input_event *event,
    int brk
    )
{
    Ws_input_ws *iws = &ws->in_ws;

    --ws->num_active_input_devs;
    iws->input_request.dev_class = event->dev_class;
    iws->input_request.dev_num = event->dev_num;
    if (brk) {
	switch (event->dev_class) {
	    case PIN_LOC:
	    case PIN_STROKE:
	    case PIN_VAL:
	    case PIN_STRING:
		iws->input_request.status.istat = PIN_STATUS_NO_IN;
		break;
	    case PIN_PICK:
		iws->input_request.status.pkstat = PIN_STATUS_NO_IN;
		break;
	    case PIN_CHOICE:
		iws->input_request.status.chstat = PIN_STATUS_NO_IN;
		break;
            default:
                break;
	}

    }
    else {
	switch (event->dev_class) {
	    case PIN_LOC:
		iws->input_request.status.istat = PIN_STATUS_OK;
                memcpy(&iws->input_request.evt.loc,
		       &event->data.locator.evt,
                       sizeof(Ploc3));
		break;
	    case PIN_STROKE:
		iws->input_request.status.istat = PIN_STATUS_OK;
                memcpy(&iws->input_request.evt.stroke,
		       &event->data.stroke.evt,
                       sizeof(Pstroke3));
		break;
	    case PIN_PICK:
                if (event->data.pick.evt.status == PIN_STATUS_OK) {
                    iws->input_request.status.pkstat = PIN_STATUS_OK;
                }
                else {
                    iws->input_request.status.pkstat = PIN_STATUS_NONE;
                }
                memcpy(&iws->input_request.evt.pick,
		       &event->data.pick.evt,
                       sizeof(Ppick));
		break;
	    case PIN_VAL:
		iws->input_request.status.istat = PIN_STATUS_OK;
                memcpy(&iws->input_request.evt.val,
		       &event->data.valuator.value,
                       sizeof(Pfloat));
		break;
	    case PIN_CHOICE:
                if (event->data.choice.evt.status == PIN_STATUS_OK) {
                    iws->input_request.status.chstat = PIN_STATUS_OK;
                }
                else {
                    iws->input_request.status.chstat = PIN_STATUS_NONE;
                }
                memcpy(&iws->input_request.evt.choice,
		       &event->data.choice.evt,
                       sizeof(Pchoice));
		break;
	    case PIN_STRING:
		iws->input_request.status.istat = PIN_STATUS_OK;
                memcpy(&iws->input_request.evt.string,
		       &event->data.string.evt,
                       sizeof(Phg_string));
		break;
            default:
                break;
	}
    }

    if ((event->dev_class == PIN_PICK) &&
        (ws->pick_disable != NULL)) {
	(*ws->pick_disable)(ws, &ws->in_ws.devs.pick[event->dev_num - 1]);
    }
}

/*******************************************************************************
 * ws_inp_load_funcs
 *
 * DESCR:       Load input device operators helper function
 * RETURNS:     N/A
 */

static void ws_inp_load_funcs(
    Ws *ws
    )
{
#ifdef DEBUG
    printf("ws_inp: load_funcs\n");
#endif

    ws->init_device       = phg_ws_inp_init_device;
    ws->set_device_mode	  = phg_ws_inp_set_mode;
    ws->request_device    = phg_ws_inp_request;
    ws->sample_device	  = phg_ws_inp_sample;
    ws->input_repaint     = phg_ws_inp_repaint;
    ws->inq_inp_dev_state = phg_ws_inp_inq_dev_state;
}


/*******************************************************************************
 * phg_ws_input_init
 *
 * DESCR:       Initialize input workstation
 * RETURNS:     TRUE or FALSE
 */

int phg_ws_input_init(
    Ws *ws,
    Input_q_handle queue
    )
{
    Sin_desc sin_desc;
    int status = FALSE;
    Wst_input_wsdt *idt = &ws->type->desc_tbl.phigs_dt.in_dt;
    Sin_desc *desc = &sin_desc;
    Ws_input_ws *iws = &ws->in_ws;

#ifdef DEBUG
    printf("ws_inp: phg_ws_input_init\n");
    printf("\twindow = %x\n", (unsigned) ws->drawable_id);
    printf("\tinput_overlay_window = %x\n",
           (unsigned) ws->input_overlay_window);
#endif

    if ( init_input_state( ws, idt ) ) {
	iws->input_queue = (Input_q_handle)queue;
	desc->wsh = (Ws_handle)ws;
	desc->idt = idt;
	desc->queue = (Sin_event_queue *)queue;
	desc->display = ws->display;
	desc->output_window = ws->drawable_id;
	desc->input_window = ws->input_overlay_window;
	desc->shell = ws->shell;
	desc->send_request = send_request;
	desc->in_viewport = ws->point_in_viewport;

	ws_inp_load_funcs( ws );

	if ( !(iws->sin_handle = phg_sin_create( desc, ws->erh )) ) {
	    phg_ws_input_close( ws );
	} else {
	    init_all_devices( ws, iws, idt );
	    status = TRUE;
	}
    }

#ifdef DEBUG
    printf("ws_inp: phg_ws_input_init DONE!\n");
#endif

    return status;
}

/*******************************************************************************
 * phg_ws_input_close
 *
 * DESCR:       Close input workstation
 * RETURNS:     TRUE or FALSE
 */

void phg_ws_input_close(
    Ws *ws
    )
{
    Ws_input_ws *iws = &ws->in_ws;
    int i;

    {
	Ws_inp_stroke *stk = iws->devs.stroke;
	
	if (stk != NULL) {
	    for ( i = 0; i < iws->num_devs.stroke; i++, stk++ ) {
		if ( stk->stroke.points )
		    free(stk->stroke.points);
	    }
	}
    }

    {
	Ws_inp_pick *pick = iws->devs.pick;
 
	if (pick != NULL) {
	    for ( i = 0; i < iws->num_devs.pick; i++, pick++ ) {
                phg_nset_destroy(pick->filter.incl);
                phg_nset_destroy(pick->filter.excl);
		if ( pick->pick.status == PIN_STATUS_OK
			&& pick->pick.pick_path.depth > 0 )
		    free(pick->pick.pick_path.path_list);
	    }
	}
    }

    {
	Ws_inp_string *str = iws->devs.string;
 
	if (str != NULL) {
	    for ( i = 0; i < iws->num_devs.string; i++, str++)
		free(str->string);
	}
    }

    {
	Ws_inp_choice *cho = iws->devs.choice;
 
	if (cho != NULL) {
	    for ( i = 0; i < iws->num_devs.choice; i++, cho++ )
		free_choice( cho );
	}
    }

    {
	Ws_inp_val *val = iws->devs.valuator;
 
	if (val != NULL) {
	    for ( i = 0; i < iws->num_devs.val; i++, val++ )
		free_valuator( val );
	}
    }

    if (iws->sin_handle != NULL) {
	phg_sin_destroy(iws->sin_handle);
    }
    if (iws->num_devs.loc > 0) {
	free(iws->devs.locator);
    }
    if (iws->num_devs.stroke > 0) {
	free(iws->devs.stroke);
    }
    if (iws->num_devs.pick > 0) {
	free(iws->devs.pick);
    }
    if (iws->num_devs.val > 0) {
	free(iws->devs.valuator);
    }
    if (iws->num_devs.choice > 0) {
	free(iws->devs.choice);
    }
    if (iws->num_devs.string > 0) {
	free(iws->devs.string);
    }
    memset(iws, 0, sizeof(iws));
}

/*******************************************************************************
 * stk_enable_data
 *
 * DESCR:       Stroke enable data helper function
 * RETURNS:     TRUE or FALSE
 */

static int stk_enable_data(
    Ws *ws,
    Ws_inp_stroke *dev,
    Sin_enable_data *ed
    )
{
    Pint num_pts;
    XPoint *init_dwbl_pts;

    /* Set echo area and initial drawable points using current window size. */

    if ( dev->stroke.num_points > 0 ) {

	/* Get the space we have stashed away for drawable points. */
	init_dwbl_pts = (XPoint *)
	    (dev->stroke.points + dev->stroke.num_points);

	/* Check and map the initial points. */
	num_pts = dev->stroke.num_points;
	if ( !(*ws->map_initial_points)( ws, dev->stroke.view_ind, &num_pts,
		dev->stroke.points, init_dwbl_pts )
		|| num_pts != dev->stroke.num_points ) {
	    /* The points aren't valid with this window size. */
	    ERR_BUF( ws->erh, ERR261 );
	    return FALSE;
	}
	ed->data.stroke.cnt = num_pts;
	ed->data.stroke.init_pts = init_dwbl_pts;
    } else {
	ed->data.stroke.cnt = 0;
	ed->data.stroke.init_pts = (Sin_window_pt *)NULL;
    }

    WSINP_DC_ECHO_TO_DRWBL_ECHO2( ws, &dev->e_volume, &ed->echo_area )

    return TRUE;
}

/*******************************************************************************
 * loc_enable_data
 *
 * DESCR:       Locator enable data helper function
 * RETURNS:     N/A
 */

static void loc_enable_data(
    Ws *ws,
    Ws_inp_loc *dev,
    Sin_enable_data *ed
    )
{
    Pint num_pts = 1;
    XPoint dwbl_pt;

    /* Set echo area using the current window size. */
    if ( (*ws->map_initial_points)( ws, dev->loc.view_ind, &num_pts,
	    &dev->loc.position, &dwbl_pt ) && num_pts == 1 )
	ed->data.locator.init_pos = dwbl_pt;
    WSINP_DC_ECHO_TO_DRWBL_ECHO2( ws, &dev->e_volume, &ed->echo_area )
}

/*******************************************************************************
 * phg_ws_inp_set_mode
 *
 * DESCR:       Set input mode
 * RETURNS:     N/A
 */

void phg_ws_inp_set_mode(
    Ws *ws,
    Phg_args_set_mode_data *args
    )
{
    Ws_input_ws *iws = &ws->in_ws;
    Ws_inp_device_handle dev;
    Sin_enable_data ed;
    Sin_set_mode_data md;
    int okay = TRUE;
    Pop_mode old_mode;

#ifdef DEBUG
    printf("ws_inp: phg_ws_inp_set_mode\n");
    printf("\tClass: %d\n", args->class);
#endif

    phg_wsx_update_ws_rect( ws );
    switch (args->idev_class) {
        case PHG_ARGS_INP_LOC:
	    md.inp_class = SIN_LOCATOR;
	    dev.loc = &iws->devs.locator[args->dev-1];
	    old_mode = dev.loc->mode;
	    dev.loc->mode = args->mode;
	    dev.loc->esw = args->echo;
	    loc_enable_data( ws, dev.loc, &ed);
	    break;
        case PHG_ARGS_INP_STK:
	    md.inp_class = SIN_STROKE;
	    dev.stk = &iws->devs.stroke[args->dev-1];
	    old_mode = dev.stk->mode;
	    okay = stk_enable_data( ws, dev.stk, &ed);
	    if ( okay ) {
		dev.stk->mode = args->mode;
		dev.stk->esw = args->echo;
	    }
	    break;
        case PHG_ARGS_INP_VAL:
	    md.inp_class = SIN_VALUATOR;
	    dev.val = &iws->devs.valuator[args->dev-1];
	    old_mode = dev.val->mode;
	    dev.val->mode = args->mode;
	    dev.val->esw = args->echo;
	    WSINP_SET_GENERIC_ENABLE_DATA( ws, dev.val, &ed)
	    break;
        case PHG_ARGS_INP_CHC:
	    md.inp_class = SIN_CHOICE;
	    dev.cho = &iws->devs.choice[args->dev-1];
	    old_mode = dev.cho->mode;
	    dev.cho->mode = args->mode;
	    dev.cho->esw = args->echo;
	    WSINP_SET_GENERIC_ENABLE_DATA( ws, dev.cho, &ed)
	    break;
        case PHG_ARGS_INP_PIK:
	    md.inp_class = SIN_PICK;
	    dev.pik = &iws->devs.pick[args->dev-1];
	    old_mode = dev.pik->mode;
	    dev.pik->mode = args->mode;
	    dev.pik->esw = args->echo;
	    WSINP_SET_GENERIC_ENABLE_DATA( ws, dev.pik, &ed)
	    /* Invoke the enable or disable procs when the mode changes. */
	    if ( args->mode == POP_REQ ) {
		if ( old_mode == POP_EVENT || old_mode == POP_SAMPLE )
		    if ( ws->pick_disable )
			(*ws->pick_disable)( ws, dev.pik );
	    } else if ( ws->pick_enable )
		okay = (*ws->pick_enable)( ws, dev.pik );
	    break;
        case PHG_ARGS_INP_STR:
	    md.inp_class = SIN_STRING;
	    dev.str = &iws->devs.string[args->dev-1];
	    old_mode = dev.str->mode;
	    dev.str->mode = args->mode;
	    dev.str->esw = args->echo;
	    WSINP_SET_GENERIC_ENABLE_DATA( ws, dev.str, &ed)
	    break;
        default:
            break;
    }

    if ( okay ) {
	md.dev_num = args->dev;
	md.mode = MAP_MODE(args->mode);
	md.echo = args->echo == PSWITCH_NO_ECHO ? 0 : 1;
	phg_sin_set_mode( iws->sin_handle, &md, &ed);
	/* Update the active device count. */
	if ( old_mode == POP_REQ ) {
	    if ( args->mode != POP_REQ )
		/* Device is being turned on. */
		++ws->num_active_input_devs;
	} else if ( args->mode == POP_REQ ) {
	    /* Device is being turned off. */
	    if ( ws->num_active_input_devs > 0 )
		--ws->num_active_input_devs;
	}
    }

    XFlush( ws->display );
}

/*******************************************************************************
 * phg_ws_inp_request
 *
 * DESCR:       Request input from device
 * RETURNS:     N/A
 */

void phg_ws_inp_request(
    Ws *ws,
    Phg_args_idev_class idev_class,
    Pint dev_num,
    Phg_ret *ret
    )
{
    Ws_input_ws *iws = &ws->in_ws;
    Ws_inp_device_handle dev;
    Sin_enable_data ed;
    Sin_input_class sin_class;
    Pop_mode cur_mode;
    int okay = TRUE;

    ret->err = -1;
    phg_wsx_update_ws_rect( ws );
    switch (idev_class) {
        case PHG_ARGS_INP_LOC3:
        case PHG_ARGS_INP_LOC:
	    sin_class = SIN_LOCATOR;
	    dev.loc = &iws->devs.locator[dev_num-1];
	    if ( (cur_mode = dev.loc->mode) == POP_REQ)
		loc_enable_data( ws, dev.loc, &ed);
	    break;
        case PHG_ARGS_INP_STK3:
        case PHG_ARGS_INP_STK:
	    sin_class = SIN_STROKE;
	    dev.stk = &iws->devs.stroke[dev_num-1];
	    if ( (cur_mode = dev.stk->mode) == POP_REQ)
		okay = stk_enable_data( ws, dev.stk, &ed);
	    break;
        case PHG_ARGS_INP_PIK:
	    sin_class = SIN_PICK;
	    dev.pik = &iws->devs.pick[dev_num-1];
	    if ( (cur_mode = dev.pik->mode) == POP_REQ)
		WSINP_SET_GENERIC_ENABLE_DATA( ws, dev.pik, &ed)
	    if ( ws->pick_enable )
		okay = (*ws->pick_enable)( ws, dev.pik );
	    break;
        case PHG_ARGS_INP_VAL:
	    sin_class = SIN_VALUATOR;
	    dev.val = &iws->devs.valuator[dev_num-1];
	    cur_mode = dev.val->mode;
	    if ( (cur_mode = dev.val->mode) == POP_REQ)
		WSINP_SET_GENERIC_ENABLE_DATA( ws, dev.val, &ed)
	    break;
        case PHG_ARGS_INP_CHC:
	    sin_class = SIN_CHOICE;
	    dev.cho = &iws->devs.choice[dev_num-1];
	    cur_mode = dev.cho->mode;
	    if ( (cur_mode = dev.cho->mode) == POP_REQ)
		WSINP_SET_GENERIC_ENABLE_DATA( ws, dev.cho, &ed)
	    break;
        case PHG_ARGS_INP_STR:
	    sin_class = SIN_STRING;
	    dev.str = &iws->devs.string[dev_num-1];
	    cur_mode = dev.str->mode;
	    if ( (cur_mode = dev.str->mode) == POP_REQ)
		WSINP_SET_GENERIC_ENABLE_DATA( ws, dev.str, &ed)
	    break;
        default:
            break;
    }

    if ( cur_mode != POP_REQ ) {
	ret->err = ERR251;
	ERR_BUF( ws->erh, ERR251);

    } else if ( okay ) {
	ret->err = 0;
	++ws->num_active_input_devs;
	phg_sin_request( iws->sin_handle, sin_class, dev_num, &ed);
    }
    XFlush( ws->display );
}

/*******************************************************************************
 * sample_locator
 *
 * DESCR:       Sample locator device helper function
 * RETURNS:     N/A
 */

static void sample_locator(
    Ws_input_ws *iws,
    Ws_inp_loc *loc,
    Phg_ret_inp_event *revt
    )
{
    Sin_input_event event;

#ifdef DEBUG
    printf("ws_inp: sample_locator\n");
#endif

    phg_sin_sample( iws->sin_handle, SIN_LOCATOR, loc->num, &event);
    revt->id.in_class = PIN_LOC;
    revt->data.loc = event.data.locator.evt;
}

/*******************************************************************************
 * sample_stroke
 *
 * DESCR:       Sample stroke device helper function
 * RETURNS:     N/A
 */

static void sample_stroke(
    Ws_input_ws *iws,
    Ws_inp_stroke *stk,
    Phg_ret_inp_event *revt
    )
{
    Sin_input_event event;

    phg_sin_sample( iws->sin_handle, SIN_STROKE, stk->num, &event);
    revt->id.in_class = PIN_STROKE;
    revt->data.stk = event.data.stroke.evt;
}

/*******************************************************************************
 * sample_choice
 *
 * DESCR:       Sample choice device helper function
 * RETURNS:     N/A
 */

static void sample_choice(
    Ws_input_ws *iws,
    Ws_inp_choice *choice,
    Phg_ret_inp_event *revt
    )
{
    Sin_input_event event;

    phg_sin_sample( iws->sin_handle, SIN_CHOICE, choice->num, &event);
    revt->id.in_class = PIN_CHOICE;
    revt->data.chc = event.data.choice.evt;
}

/*******************************************************************************
 * sample_valuator
 *
 * DESCR:       Sample valuator device helper function
 * RETURNS:     N/A
 */

static void sample_valuator(
    Ws_input_ws *iws,
    Ws_inp_val *val,
    Phg_ret_inp_event *revt
    )
{
    Sin_input_event event;

    phg_sin_sample( iws->sin_handle, SIN_VALUATOR, val->num, &event);
    revt->id.in_class = PIN_VAL;
    revt->data.val = event.data.valuator.value;
}

/*******************************************************************************
 * sample_pick
 *
 * DESCR:       Sample pick device helper function
 * RETURNS:     N/A
 */

static void sample_pick(
    Ws_input_ws *iws,
    Ws_inp_pick *pick,
    Phg_ret_inp_event *revt
    )
{
    Sin_input_event event;

    phg_sin_sample( iws->sin_handle, SIN_PICK, pick->num, &event);
    revt->id.in_class = PIN_PICK;
    revt->data.pik = event.data.pick.evt;
}

/*******************************************************************************
 * sample_string
 *
 * DESCR:       Sample string device helper function
 * RETURNS:     N/A
 */

static void sample_string(
    Ws_input_ws *iws,
    Ws_inp_string *str,
    Phg_ret_inp_event *revt
    )
{
    Sin_input_event event;

    phg_sin_sample( iws->sin_handle, SIN_STRING, str->num, &event);
    revt->id.in_class = PIN_STRING;
    revt->data.str = event.data.string.evt;
}

/*******************************************************************************
 * phg_ws_inp_sample
 *
 * DESCR:       Sample device
 * RETURNS:     N/A
 */

void phg_ws_inp_sample(
    Ws *ws,
    Phg_args_idev_class idev_class,
    Pint dev_num,
    Phg_ret *ret
    )
{
    Ws_input_ws *iws = &ws->in_ws;
    Ws_inp_device_handle dev;
    Pop_mode cur_mode;

#ifdef DEBUG
    printf("ws_inp: phg_ws_inp_sample\n");
#endif

    switch (idev_class) {
        case PHG_ARGS_INP_LOC3:
        case PHG_ARGS_INP_LOC:
	    dev.loc = &iws->devs.locator[dev_num-1];
	    cur_mode = dev.loc->mode;
            if (cur_mode == POP_SAMPLE) {
               ret->err = 0;
	       sample_locator(iws, dev.loc, &ret->data.inp_event);
            }
            else {
	        ret->err = ERR252;
	        ERR_BUF(ws->erh, ERR252);
            }
	    break;
        case PHG_ARGS_INP_STK3:
        case PHG_ARGS_INP_STK:
	    dev.stk = &iws->devs.stroke[dev_num-1];
	    cur_mode = dev.stk->mode;
            if (cur_mode == POP_SAMPLE) {
	       sample_stroke(iws, dev.stk, &ret->data.inp_event);
               ret->err = 0;
            }
            else {
	        ret->err = ERR252;
	        ERR_BUF(ws->erh, ERR252);
            }
	    break;
        case PHG_ARGS_INP_VAL3:
        case PHG_ARGS_INP_VAL:
	    dev.val = &iws->devs.valuator[dev_num-1];
	    cur_mode = dev.val->mode;
            if (cur_mode == POP_SAMPLE) {
	       sample_valuator(iws, dev.val, &ret->data.inp_event);
               ret->err = 0;
            }
            else {
	        ret->err = ERR252;
	        ERR_BUF(ws->erh, ERR252);
            }
	    break;
        case PHG_ARGS_INP_CHC3:
        case PHG_ARGS_INP_CHC:
	    dev.cho = &iws->devs.choice[dev_num-1];
	    cur_mode = dev.cho->mode;
            if (cur_mode == POP_SAMPLE) {
	       sample_choice(iws, dev.cho, &ret->data.inp_event);
               ret->err = 0;
            }
            else {
	        ret->err = ERR252;
	        ERR_BUF(ws->erh, ERR252);
            }
	    break;
        case PHG_ARGS_INP_PIK3:
        case PHG_ARGS_INP_PIK:
	    dev.pik = &iws->devs.pick[dev_num-1];
	    cur_mode = dev.pik->mode;
            if (cur_mode == POP_SAMPLE) {
	       sample_pick(iws, dev.pik, &ret->data.inp_event);
               ret->err = 0;
            }
            else {
	        ret->err = ERR252;
	        ERR_BUF(ws->erh, ERR252);
            }
	    break;
        case PHG_ARGS_INP_STR3:
        case PHG_ARGS_INP_STR:
	    dev.str = &iws->devs.string[dev_num-1];
	    cur_mode = dev.str->mode;
            if (cur_mode == POP_SAMPLE) {
	       sample_string(iws, dev.str, &ret->data.inp_event);
               ret->err = 0;
            }
            else {
	        ret->err = ERR252;
	        ERR_BUF(ws->erh, ERR252);
            }
	    break;
    }
}

/*******************************************************************************
 * phg_ws_inp_repaint
 *
 * DESCR:       Repaint device
 * RETURNS:     N/A
 */

void phg_ws_inp_repaint(
    Ws *ws,
    Pint num_rects,
    XRectangle *rects
    )
{
    phg_sin_repaint( ws->in_ws.sin_handle, num_rects, rects );
}

/*******************************************************************************
 * phg_ws_inp_inq_dev_state
 *
 * DESCR:       Inquire device state
 * RETURNS:     N/A
 */

void phg_ws_inp_inq_dev_state(
    Ws *ws,
    Phg_args_idev_class idev_class,
    Pint num,
    Phg_ret *ret
    )
{
    ret->err = 0;
    switch (idev_class) {
	case PHG_ARGS_INP_LOC3:
	case PHG_ARGS_INP_LOC: {
	    Ws_inp_loc	*dev = WS_INP_DEV( ws, locator, num);
	    Plocst3	*st = &ret->data.inp_state.loc;

	    WSINP_COPY_COMMON_STATE_FIELDS( st, dev )
	    st->loc = dev->loc;
	    } break;

	case PHG_ARGS_INP_STK3:
	case PHG_ARGS_INP_STK: {
	    Ws_inp_stroke	*dev = WS_INP_DEV( ws, stroke, num);
	    Pstrokest3		*st = &ret->data.inp_state.stroke;

	    WSINP_COPY_COMMON_STATE_FIELDS( st, dev )
	    st->stroke = dev->stroke;
	    } break;

	case PHG_ARGS_INP_PIK3:
	case PHG_ARGS_INP_PIK:{
	    Ws_inp_pick		*dev = WS_INP_DEV( ws, pick, num);
	    Ppickst3		*st = &ret->data.inp_state.pick;
	    Phg_ret		ret_filt;

	    WSINP_COPY_COMMON_STATE_FIELDS( st, dev )
	    st->pick = dev->pick;
	    st->order = dev->order;
#ifdef TODO
	    phg_wsx_inq_name_set( ws, PHG_ARGS_FLT_PICK, num, &ret_filt );
#endif
	    if ( ret_filt.err )
		ret->err = ret_filt.err;
	    else {
		st->inclusion_filter = ret_filt.data.filter.incl;
		st->exclusion_filter = ret_filt.data.filter.excl;
	    }
	    } break;

	case PHG_ARGS_INP_VAL3:
	case PHG_ARGS_INP_VAL: {
	    Ws_inp_val		*dev = WS_INP_DEV( ws, valuator, num);
	    Pvalst3		*st = &ret->data.inp_state.val;

	    WSINP_COPY_COMMON_STATE_FIELDS( st, dev )
	    st->val = dev->val;
	    switch ( dev->pet ) {
		case -1:
		    if ( dev->record.pets.pet_u1.label )
			st->counts[0] =
			    1 + strlen(dev->record.pets.pet_u1.label);
		    if ( dev->record.pets.pet_u1.format )
			st->counts[1] =
			    1 + strlen(dev->record.pets.pet_u1.format);
		    if ( dev->record.pets.pet_u1.low_label )
			st->counts[2] =
			    1 + strlen(dev->record.pets.pet_u1.low_label);
		    if ( dev->record.pets.pet_u1.high_label )
			st->counts[3] =
			    1 + strlen(dev->record.pets.pet_u1.high_label);
		    break;
	    }
	} break;

	case PHG_ARGS_INP_CHC3:
	case PHG_ARGS_INP_CHC: {
	    Ws_inp_choice	*dev = WS_INP_DEV( ws, choice, num);
	    Pchoicest3		*st = &ret->data.inp_state.choice.state;

	    WSINP_COPY_COMMON_STATE_FIELDS( st, dev )
	    st->choice = dev->choice;
	    switch ( st->pet ) {
		case 3:
		    if ( st->record.pets.pet_r3.num_strings > 0 )
			ret->data.inp_state.choice.strings =
			    st->record.pets.pet_r3.strings[0];
		    ret->data.inp_state.choice.length = dev->strings_length;
		    break;
	    }
	} break;

	case PHG_ARGS_INP_STR3:
	case PHG_ARGS_INP_STR: {
	    Ws_inp_string	*dev = WS_INP_DEV( ws, string, num);
	    Pstringst3		*st = &ret->data.inp_state.string.state;

	    WSINP_COPY_COMMON_STATE_FIELDS( st, dev )
	    st->string = dev->string;
	    ret->data.inp_state.string.length = dev->length;
	    } break;
    }
}

/*******************************************************************************
 * phg_ws_inp_resize
 *
 * DESCR:       Resize input device
 * RETURNS:     N/A
 */

void phg_ws_inp_resize(
    Ws *ws,
    XRectangle *old_rect
    )
{
    Ws_input_ws *iws = &ws->in_ws;
    Sin_enable_data ed;
    int i;

    /* TODO: update a device only if it's active.  All this data gets
     * updated anyway when the device *becomes* active.
     */
    for ( i = 0; i < iws->num_devs.loc; i++) {
	Ws_inp_loc	*dev = &iws->devs.locator[i];
	loc_enable_data( ws, dev, &ed);
	phg_sin_resize_dev( iws->sin_handle, SIN_LOCATOR, dev->num,
	    &ed, old_rect, &ws->ws_rect );
    }

    for ( i = 0; i < iws->num_devs.stroke; i++) {
	Ws_inp_stroke	*dev = &iws->devs.stroke[i];
	stk_enable_data( ws, dev, &ed);
	phg_sin_resize_dev( iws->sin_handle, SIN_STROKE, dev->num,
	    &ed, old_rect, &ws->ws_rect );
    }

    for ( i = 0; i < iws->num_devs.pick; i++) {
	Ws_inp_pick	*dev = &iws->devs.pick[i];
	WSINP_SET_GENERIC_ENABLE_DATA( ws, dev, &ed)
	phg_sin_resize_dev( iws->sin_handle, SIN_PICK, dev->num,
	    &ed, old_rect, &ws->ws_rect );
    }

    for ( i = 0; i < iws->num_devs.choice; i++) {
	Ws_inp_choice	*dev = &iws->devs.choice[i];
	WSINP_SET_GENERIC_ENABLE_DATA( ws, dev, &ed)
	phg_sin_resize_dev( iws->sin_handle, SIN_CHOICE, dev->num,
	    &ed, old_rect, &ws->ws_rect );
    }

    for ( i = 0; i < iws->num_devs.val; i++) {
	Ws_inp_val	*dev = &iws->devs.valuator[i];
	WSINP_SET_GENERIC_ENABLE_DATA( ws, dev, &ed)
	phg_sin_resize_dev( iws->sin_handle, SIN_VALUATOR, dev->num,
	    &ed, old_rect, &ws->ws_rect );
    }

    for ( i = 0; i < iws->num_devs.string; i++) {
	Ws_inp_string	*dev = &iws->devs.string[i];
	WSINP_SET_GENERIC_ENABLE_DATA( ws, dev, &ed)
	phg_sin_resize_dev( iws->sin_handle, SIN_STRING, dev->num,
	    &ed, old_rect, &ws->ws_rect );
    }
}

/*******************************************************************************
 * overlay_event
 *
 * DESCR:       Check for event on overlay helper function
 * RETURNS:     N/A
 */

static void overlay_event(
    Display *display,
    Window window,
    caddr_t client_data,
    XEvent *event
    )
{
#ifdef PROPAGATE
    Window parent = (Window) client_data;

#ifdef DEBUG
   printf("ws_inp: overlay_event\n");
   printf("From window: %x to %x\n",
          (unsigned) window,
          (unsigned) parent);
#endif

#ifdef DEBUG
    fprintf(stderr, "Got OVERLAY event %s on window %x on display %#x\n", 
	phg_sin_evt_name(event), (unsigned) window, (unsigned) display);
#endif

    switch ( event->type ) {
	default:
	/* Propogate this event to the window's parent. */
	XSendEvent( display, parent, True, KeyPressMask | KeyReleaseMask
	    | ButtonPressMask | ButtonReleaseMask, event );
	break;
    }
#endif
}

/*******************************************************************************
 * overlay_parent_resize
 *
 * DESCR:       Resize overlay helper function
 * RETURNS:     N/A
 */

static void overlay_parent_resize(
    Display *display,
    Window parent,
    caddr_t client_data,
    XEvent *event
    )
{
    Window overlay = (Window) client_data;

    XResizeWindow( display, overlay,
                   (unsigned int)event->xconfigure.width,
		   (unsigned int)event->xconfigure.height );
}

/*******************************************************************************
 * phg_wsx_create_overlay
 *
 * DESCR:       Create overlay window
 * RETURNS:     Overlay window
 */

Window phg_wsx_create_overlay(
    Ws *ws
    )
{
    Window win;
    XWindowAttributes gattrs;
    XSetWindowAttributes sattrs;
    Display *display = ws->display;
    Drawable parent = ws->drawable_id;

#ifdef DEBUG
    printf("ws_inp: phg_ws_create_overlay\n");
    printf("\tParent window = %x\n", (unsigned) parent);
#endif

    XGetWindowAttributes(display, (Window)parent, &gattrs);
    sattrs.win_gravity = NorthWestGravity;
    win = XCreateWindow( display, (Window)parent, 0, 0,
	    (unsigned)gattrs.width, (unsigned)gattrs.height, (unsigned)0,
	    0, InputOnly, (Visual *)NULL, CWWinGravity, &sattrs );
    if ( win ) {
#ifndef NOT_USED
	/* Set up to propogate input events to parent. */
	(void)phg_sin_evt_register(PHG_EVT_TABLE, display, win, KeyPress,
	    (caddr_t)parent, overlay_event );
	(void)phg_sin_evt_register(PHG_EVT_TABLE, display, win, KeyRelease,
	    (caddr_t)parent, overlay_event );
	(void)phg_sin_evt_register(PHG_EVT_TABLE, display, win, ButtonPress,
	    (caddr_t)parent, overlay_event );
	(void)phg_sin_evt_register(PHG_EVT_TABLE, display, win, ButtonRelease,
	    (caddr_t)parent, overlay_event );
#endif

	/* Set up to resize overlay when parent is resized. */
	(void)phg_sin_evt_register(PHG_EVT_TABLE, display, parent,
	    ConfigureNotify, (caddr_t)win, overlay_parent_resize );

	/* Let the input device initialization select events. */
	XSelectInput( display, win, (long)0 );
	XMapWindow( display, win );
	XFlush( display );
    } else {
	ERR_BUF( ws->erh, ERRN203 );
    }
    return win;
}

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
    )
{
    phg_sin_evt_unregister_window( PHG_EVT_TABLE, display, overlay );
    phg_sin_evt_unregister( PHG_EVT_TABLE, display, parent,
        ConfigureNotify, (caddr_t)overlay );
    XDestroyWindow( display, overlay );
}

