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

/* PEX/PHIGS workstation utility functions for the B model (client side
 * workstations and structure storage).
 */

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/util.h>
#include <phigs/ws.h>
#include <phigs/private/wsglP.h>
#include <phigs/private/wsxP.h>
#include <phigs/css.h>
#include <phigs/alloc.h>

static void wsb_load_funcs(
    Ws *ws
    )
{
    ws->close = phg_wsb_close_ws;
    ws->redraw_all = phg_wsb_redraw_all;
    ws->conditional_redraw = phg_wsb_conditional_redraw;
    ws->repaint_all = phg_wsb_repaint_all;
    ws->make_requested_current = phg_wsb_make_requested_current;
    ws->update = phg_wsb_update;
    ws->set_disp_update_state = phg_wsb_set_disp_update_state;
    ws->set_rep = phg_wsb_set_rep;
    ws->set_filter = phg_wsb_set_filter;
    ws->set_hlhsr_mode = phg_wsb_set_hlhsr_mode;
    ws->set_ws_window = phg_wsb_set_ws_window;
    ws->set_ws_vp = phg_wsb_set_ws_vp;
    ws->add_el = phg_wsb_add_el;
    ws->copy_struct = phg_wsb_copy_struct;
    ws->close_struct = phg_wsb_close_struct;
    ws->move_ep = NULL;
    ws->delete_el = phg_wsb_delete_el;
    ws->delete_struct = phg_wsb_delete_struct;
    ws->delete_struct_net = phg_wsb_delete_struct_net;
    ws->delete_all_structs = phg_wsb_delete_all_structs;
    ws->post = phg_wsb_post;
    ws->unpost = phg_wsb_unpost;
    ws->unpost_all = phg_wsb_unpost_all;
    ws->change_posting = phg_wsb_change_posting;
    ws->inq_posted = phg_wsb_inq_posted;
    ws->inq_representation = phg_wsb_inq_rep;
    ws->inq_disp_update_state = phg_wsb_inq_disp_update_state;
    ws->inq_hlhsr_mode = phg_wsb_inq_hlhsr_mode;
    ws->set_view_input_priority = phg_wsb_set_view_input_priority;
    ws->map_initial_points = phg_wsb_map_initial_points;
    ws->resolve_locator = phg_wsb_resolve_locator;
    ws->point_in_viewport = phg_wsb_point_in_viewport;
    ws->resolve_stroke = phg_wsb_resolve_stroke;
    ws->resolve_pick = phg_wsb_resolve_pick;

    /* Not used by all workstations */
    ws->valid_pick_path = NULL;
    ws->pick_enable = NULL;
    ws->pick_disable = NULL;

    /* Initialized by input module */
    ws->init_device = NULL;
    ws->set_device_mode = NULL;
    ws->request_device = NULL;
    ws->sample_device = NULL;
    ws->input_repaint = NULL;
    ws->inq_inp_dev_state = NULL;
}

/* 
 * Tables that determine what update action is valid at a give point
 * in time.  The table has 3 axes:
 *	[Time] [Modification Mode] [Deferral Mode].
 */

static Ws_action_table default_action_table =
{
    {   /* PHG_TIME_NOW */  
	{   /* NIVE */   
	    PHG_UPDATE_ACCURATE, 		/* ASAP */
	    PHG_UPDATE_IF_IG,	 		/* BNIG */
	    PHG_UPDATE_IF_IL, 			/* BNIL */
	    PHG_UPDATE_NOTHING, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	},
	{   /* UWOR */
	    PHG_UPDATE_ACCURATE, 		/* ASAP */
	    PHG_UPDATE_IF_IG, 			/* BNIG */
	    PHG_UPDATE_IF_IL, 			/* BNIL */
	    PHG_UPDATE_UWOR, 			/* ASTI */
	    PHG_UPDATE_UWOR			/* WAIT */
	},
	{   /* UQUM */
	    PHG_UPDATE_ACCURATE, 		/* ASAP */
	    PHG_UPDATE_IF_IG, 			/* BNIG */
	    PHG_UPDATE_IF_IL, 			/* BNIL */
	    PHG_UPDATE_UQUM, 			/* ASTI */
	    PHG_UPDATE_UQUM			/* WAIT */
	}, 
    }, 

    {   /* PHG_TIME_BIG */  
	{   /* NIVE */   
	    ASSURE_CORRECT, 			/* ASAP */
	    PHG_UPDATE_ACCURATE, 		/* BNIG */
	    PHG_UPDATE_NOTHING, 		/* BNIL */
	    PHG_UPDATE_NOTHING, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	}, 
	{   /* UWOR */ 
	    ASSURE_CORRECT, 			/* ASAP */
	    PHG_UPDATE_ACCURATE, 		/* BNIG */
	    PHG_UPDATE_NOTHING, 		/* BNIL */
	    PHG_UPDATE_NOTHING, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	}, 
	{   /* UQUM */   
	    ASSURE_CORRECT, 			/* ASAP */
	    PHG_UPDATE_ACCURATE, 		/* BNIG */
	    PHG_UPDATE_NOTHING, 		/* BNIL */
	    PHG_UPDATE_NOTHING, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	}, 
    }, 	    
    {   /* PHG_TIME_BIL */  
	{   /* NIVE */   
	    ASSURE_CORRECT, 			/* ASAP */
	    PHG_UPDATE_ACCURATE, 		/* BNIG */
	    PHG_UPDATE_ACCURATE, 		/* BNIL */
	    PHG_UPDATE_NOTHING, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	}, 
	{   /* UWOR */ 
	    ASSURE_CORRECT, 			/* ASAP */
	    PHG_UPDATE_ACCURATE, 		/* BNIG */
	    PHG_UPDATE_ACCURATE, 		/* BNIL */
	    PHG_UPDATE_NOTHING, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	}, 
	{   /* UQUM */   
	    ASSURE_CORRECT, 			/* ASAP */
	    PHG_UPDATE_ACCURATE, 		/* BNIG */
	    PHG_UPDATE_ACCURATE, 		/* BNIL */
	    PHG_UPDATE_NOTHING, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	}, 
    }, 
    {   /* PHG_TIME_ATI */  
	{   /* NIVE */   
	    ASSURE_CORRECT, 			/* ASAP */
	    PHG_UPDATE_IF_INCORRECT, 		/* BNIG */
	    PHG_UPDATE_IF_INCORRECT, 		/* BNIL */
	    PHG_UPDATE_ACCURATE, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	}, 
	{   /* UWOR */ 
	    ASSURE_CORRECT, 			/* ASAP */
	    PHG_UPDATE_IF_INCORRECT, 		/* BNIG */
	    PHG_UPDATE_IF_INCORRECT, 		/* BNIL */
	    PHG_UPDATE_ACCURATE, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	},
	{   /* UQUM */   
	    ASSURE_CORRECT, 			/* ASAP */
	    PHG_UPDATE_IF_INCORRECT, 		/* BNIG */
	    PHG_UPDATE_IF_INCORRECT, 		/* BNIL */
	    PHG_UPDATE_ACCURATE, 		/* ASTI */
	    PHG_UPDATE_NOTHING			/* WAIT */
	},
    }
};

static void init_update_state(
    Ws *ws
    )
{   
    Ws_output_ws	*ows = &ws->out_ws;
    Wsb_output_ws	*owsb = &ows->model.b;

    ows->def_mode = ws->type->desc_tbl.phigs_dt.out_dt.deferral_mode;
    ows->mod_mode = ws->type->desc_tbl.phigs_dt.out_dt.modification_mode;

    owsb->update_action_table = (Ws_action_table_ptr)default_action_table;

    /* cache action for time "NOW" */
    owsb->now_action = (*owsb->update_action_table)
	[(int)PHG_TIME_NOW][(int)ows->mod_mode][(int)ows->def_mode];

    owsb->vis_rep = PVISUAL_ST_CORRECT;
    owsb->surf_state = PSURF_EMPTY;
}

static int init_output_state(
    Ws *ws
    )
{
    Wsb_output_ws *owsb = &ws->out_ws.model.b;

    /* Initialize the workstation transform. */
    owsb->req_ws_window.x_min = 0.0;
    owsb->req_ws_window.x_max = 1.0;
    owsb->req_ws_window.y_min = 0.0;
    owsb->req_ws_window.y_max = 1.0;
    owsb->req_ws_window.z_min = 0.0;
    owsb->req_ws_window.z_max = 1.0;
    owsb->ws_window = owsb->req_ws_window;
    owsb->ws_window_pending = PUPD_NOT_PEND;
    wsgl_set_window(ws, &owsb->ws_window);

    owsb->req_ws_viewport.x_min = 0.0;
    owsb->req_ws_viewport.x_max = (float) ws->ws_rect.width;
    owsb->req_ws_viewport.y_min = 0.0;
    owsb->req_ws_viewport.y_max = (float) ws->ws_rect.height;
    owsb->req_ws_viewport.z_min = 0.0;
    owsb->req_ws_viewport.z_max = 1.0;
    owsb->ws_viewport = owsb->req_ws_viewport;
    owsb->ws_viewport_pending = PUPD_NOT_PEND;
    wsgl_set_viewport(ws, &owsb->ws_viewport);

    phg_wsx_compute_ws_transform( &owsb->ws_window, &owsb->ws_viewport,
        &owsb->ws_xform );

    /* Initialize the list of posted structs. */
    owsb->posted.lowest.higher = &owsb->posted.highest;
    owsb->posted.lowest.lower = NULL;
    owsb->posted.highest.higher = NULL;
    owsb->posted.highest.lower = &owsb->posted.lowest;

    /* Initialize other miscellaneous output state. */
    owsb->cur_hlhsr_mode = PHIGS_HLHSR_MODE_NONE;
    owsb->req_hlhsr_mode = PHIGS_HLHSR_MODE_NONE;
    owsb->hlhsr_mode_pending = PUPD_NOT_PEND;

    return 1;
}

static int init_attributes(
    Ws *ws
    )
{
    int i;
    Phg_args_rep_data rep;
    Wst_output_wsdt *wsdt;

    wsdt = &ws->type->desc_tbl.phigs_dt.out_dt;

    /* Line representations */
    for (i = 0; i < wsdt->num_predefined_polyline_indices; i++) {
        rep.index = i;
        memcpy(&rep.bundl.lnrep,
               &wsdt->default_polyline_bundle_table[i],
               sizeof(Pline_bundle_plus));
        (*ws->set_rep)(ws, PHG_ARGS_EXTLNREP, &rep);
    }

    /* Marker representations */
    for (i = 0; i < wsdt->num_predefined_polymarker_indices; i++) {
        rep.index = i;
        memcpy(&rep.bundl.mkrep,
               &wsdt->default_polymarker_bundle_table[i],
               sizeof(Pmarker_bundle_plus));
        (*ws->set_rep)(ws, PHG_ARGS_EXTMKREP, &rep);
    }

    /* Text representations */
    for (i = 0; i < wsdt->num_predefined_text_indices; i++) {
        rep.index = i;
        memcpy(&rep.bundl.txrep,
               &wsdt->default_text_bundle_table[i],
               sizeof(Ptext_bundle_plus));
        (*ws->set_rep)(ws, PHG_ARGS_EXTTXREP, &rep);
    }

    /* Edge representations */
    for (i = 0; i < wsdt->num_predefined_edge_indices; i++) {
        rep.index = i;
        memcpy(&rep.bundl.edgerep,
               &wsdt->default_edge_bundle_table[i],
               sizeof(Pedge_bundle_plus));
        (*ws->set_rep)(ws, PHG_ARGS_EXTEDGEREP, &rep);
    }

    /* Interiour representations */
    for (i = 0; i < wsdt->num_predefined_interior_indices; i++) {
        rep.index = i;
        memcpy(&rep.bundl.interrep,
               &wsdt->default_interior_bundle_table[i],
               sizeof(Pint_bundle_plus));
        (*ws->set_rep)(ws, PHG_ARGS_EXTINTERREP, &rep);
    }

    return 1;
}

static void destroy_resources(
    Ws *ws
    )
{
    Ws_output_ws *ows = &ws->out_ws;

    if (ows->nset.invis_incl != NULL) {
        phg_nset_destroy(ows->nset.invis_incl);
    }
    if (ows->nset.invis_excl != NULL) {
       phg_nset_destroy(ows->nset.invis_excl);
    }
}

static int init_resources(
    Ws *ws
    )
{
    int status = TRUE;
    Ws_output_ws *ows = &ws->out_ws;

    ows->nset.invis_incl = phg_nset_create(WS_MAX_NAMES_IN_NAMESET);
    if (ows->nset.invis_incl == NULL) {
        destroy_resources(ws);
        status = FALSE;
    }

    ows->nset.invis_excl = phg_nset_create(WS_MAX_NAMES_IN_NAMESET);
    if (ows->nset.invis_excl == NULL) {
        destroy_resources(ws);
        status = FALSE;
    }

    return status;
}

static int init_viewrep(
    Ws *ws
    )
{
    int i;
    Phg_args_rep_data rep;
    Wst_phigs_dt *dt;

    dt = &ws->type->desc_tbl.phigs_dt;

    for (i = 0; i < dt->num_predefined_views; i++) {
        rep.index = i;
        memcpy(&rep.bundl.viewrep,
               &dt->default_views[i],
               sizeof(Pview_rep3));
        (*ws->set_rep)(ws, PHG_ARGS_VIEWREP, &rep);
    }

    return TRUE;
}

static void init_views(
    Ws *ws
    )
{
    Ws_output_ws  *ows = &ws->out_ws;
    Wsb_output_ws *owsb = &ows->model.b;

    owsb->views_pending = PUPD_NOT_PEND;
    list_init(&owsb->pending_views);
    list_init(&owsb->views);
}

Ws* phg_wsb_open_ws(
    Phg_args_open_ws *args,
    Phg_ret *ret
    )
{
    XWindowAttributes wattr;
    Ws *ws;
    Wst_phigs_dt *dt;
    Wst_xwin_dt *xdt;
    Pgcolr background;

    ret->err = -1;
    ws = phg_wsx_create(args);
    if (ws == NULL) {
	return ws;
    }

    wsb_load_funcs( ws );

    if (args->conn_type == PHG_ARGS_CONN_OPEN) {

        /* Store workstation type parameters */
        dt = &args->type->desc_tbl.phigs_dt;
        xdt = &args->type->desc_tbl.xwin_dt;
        xdt->tool.x            = 0;
        xdt->tool.y            = 0;
        xdt->tool.width        = (unsigned) dt->dev_coords[0] / 2;
        xdt->tool.height       = xdt->tool.width;
        xdt->tool.border_width = 1;
        strncpy(xdt->tool.label, args->window_name, PHIGS_MAX_NAME_LEN);
        strncpy(xdt->tool.icon_label, args->icon_name, PHIGS_MAX_NAME_LEN);

        ws->display = phg_wsx_open_gl_display(NULL, &ret->err);
        if (ws->display == NULL) {
            ERR_BUF(ws->erh, ret->err);
            goto abort;
        }

        if (!phg_wsx_setup_tool(ws, NULL, args->type)) {
            goto abort;
        }
    }
    else if (args->conn_type == PHG_ARGS_CONN_DRAWABLE) {

        /* Store workstation type parameters */
        dt = &args->type->desc_tbl.phigs_dt;
        xdt = &args->type->desc_tbl.xwin_dt;

        ws->display     = args->conn_info.display;
        ws->drawable_id = args->conn_info.drawable_id;
        ws->glx_context = args->conn_info.glx_context;
        phg_wsx_pixel_colour(ws,
                             args->conn_info.colormap,
                             args->conn_info.background,
                             &background);
        if (!wsgl_init(ws, &background, NUM_SELECTABLE_STRUCTS)) {
           ERR_BUF(ws->erh, ERR900);
           goto abort;
        }
    }

#if 1
    if (dt->ws_category == PCAT_OUTIN) {

        ws->input_overlay_window = phg_wsx_create_overlay(ws);
        if (ws->input_overlay_window == 0) {
            XDestroyWindow(ws->display, ws->drawable_id);
            goto abort;
        }

        if (!phg_ws_input_init(ws, args->input_q)) {
            XDestroyWindow(ws->display, ws->input_overlay_window);
            XDestroyWindow(ws->display, ws->drawable_id);
            goto abort;
        }
    }
#endif

    (void)XGetWindowAttributes( ws->display, ws->drawable_id, &wattr );
    WS_SET_WS_RECT( ws, &wattr )

    /* Setup workstation attributes */
    ws->current_colour_model =
        ws->type->desc_tbl.phigs_dt.out_dt.default_colour_model;
    ws->category = ws->type->desc_tbl.phigs_dt.ws_category;
    ws->has_double_buffer =
        ws->type->desc_tbl.phigs_dt.out_dt.has_double_buffer;
    ws->out_ws.model.b.cssh = args->cssh;

    if (!init_output_state(ws)) {
	goto abort;
    }

    init_update_state(ws);

    /* NOTE:
     * Setup colourmap if used here
     */

    if (!phg_wsb_create_LUTs(ws)) {
        goto abort;
    }

    if (!init_attributes(ws)) {
        goto abort;
    }

    if (!init_resources(ws)) {
        goto abort;
    }

    init_views(ws);

    if (!init_viewrep(ws)) {
        goto abort;
    }

    /* Fill in the return data. */
    ret->err = 0;

    return ws;

abort:
    wsb_destroy_ws(ws);
    return NULL;
}

void wsb_free_all_posted(
    Wsb_output_ws *owsb
    )
{
    Ws_post_str	*cur, *end;

    cur = owsb->posted.lowest.higher;
    end = &owsb->posted.highest;
    while ( cur != end ) {
	cur = cur->higher;
	free( (char *)cur->lower );
    }
    owsb->posted.lowest.higher = end;
    end->lower = &owsb->posted.lowest;
}

void wsb_destroy_ws(
    Ws *ws
    )
{
    if ( ws ) {
	if ( ws->display ) {
	    if ( ws->drawable_id )
		phg_wsx_release_window( ws );
                destroy_resources(ws);

            /* NOTE:
             * Free renderer resource here if needed
             * Destroy colourmap here if needed
             */

	    XFlush( ws->display );
	}
	phg_wsx_destroy( ws );
    }
}

void phg_wsb_close_ws(
    Ws *ws
    )
{
    if ( ws ) {
	wsb_free_all_posted( &ws->out_ws.model.b );
	wsb_destroy_ws( ws );
    }
}

void phg_wsb_redraw_all(
    Ws *ws,
    Pctrl_flag clear_control
    )
{
#ifdef DEBUG
    printf("wsb: Redraw.\n");
#endif

    (*ws->make_requested_current)( ws );
    (*ws->repaint_all)( ws, clear_control );
    ws->out_ws.model.b.vis_rep = PVISUAL_ST_CORRECT;
}

static Ws_view_ref* phg_wsb_find_view(
    List *list,
    Pint id
    )
{
    Ws_view_ref *vref;

    for (vref = (Ws_view_ref *) LIST_HEAD(list);
         vref != NULL;
         vref = (Ws_view_ref *) NODE_NEXT(&vref->node)) {
        if (id == vref->id) {
            break;
        }
    }

    return vref;
}

/* Make all "requested" and pending data current. */
void phg_wsb_make_requested_current(
    Ws *ws
    )
{
    Ws_view_ref *vref, *dupref;
    Wsb_output_ws *owsb = &ws->out_ws.model.b;

    /* WS transform */
    if ( owsb->ws_window_pending == PUPD_PEND
	    || owsb->ws_viewport_pending == PUPD_PEND ) {
	if ( owsb->ws_window_pending == PUPD_PEND ) {
#ifdef DEBUG
            printf("wsb: Set window\n");
#endif
	    owsb->ws_window = owsb->req_ws_window;
	    owsb->ws_window_pending = PUPD_NOT_PEND;
            wsgl_set_window(ws, &owsb->ws_window);
	}

	if ( owsb->ws_viewport_pending == PUPD_PEND ) {
#ifdef DEBUG
            printf("wsb: Set viewport\n");
#endif
	    owsb->ws_viewport = owsb->req_ws_viewport;
	    owsb->ws_viewport_pending = PUPD_NOT_PEND;
            wsgl_set_viewport(ws, &owsb->ws_viewport);
	}

#ifdef DEBUG
            printf("wsb: Compute transform\n");
#endif
        phg_wsx_compute_ws_transform( &owsb->ws_window, &owsb->ws_viewport,
            &owsb->ws_xform );

    }

    /* Pending views */
    if (owsb->views_pending == PUPD_PEND) {
#ifdef DEBUG
       printf("wsb: Views pending\n");
#endif
       vref = (Ws_view_ref *) list_get(&owsb->pending_views);
       while (vref != NULL) {
#ifdef DEBUG
           printf("wsb: Flush view with %d with priority %d\n",
                  vref->id, vref->priority);
#endif
           /* Remove duplicated views */
           dupref = phg_wsb_find_view(&owsb->views, vref->id);
           if (dupref != NULL) {
              list_remove(&owsb->views, &dupref->node);
              free(dupref);
           }

           list_enqueue(&owsb->views, &vref->node, vref->priority);
           vref = (Ws_view_ref *) list_get(&owsb->pending_views);
       }
#ifdef DEBUG
       {
          Ws_view_ref *v;
          for (v = (Ws_view_ref *) LIST_HEAD(&owsb->views);
               v != NULL;
               v = (Ws_view_ref *) NODE_NEXT(&v->node)) {
             printf("wsb: View %d with priority: %d\n", v->id, v->priority);
          }
       }
#endif
       owsb->views_pending = PUPD_NOT_PEND;
    }

    /* Other pending data */
    if ( owsb->hlhsr_mode_pending == PUPD_PEND) {
#ifdef DEBUG
         printf("wsb: Set hlhsr mode\n");
#endif
	 owsb->cur_hlhsr_mode = owsb->req_hlhsr_mode;
	 owsb->hlhsr_mode_pending = PUPD_NOT_PEND;
         wsgl_set_hlhsr_mode(ws, owsb->req_hlhsr_mode);
    }

#ifdef DEBUG
    printf("wsb: Flush\n");
#endif

    /* Make it all take effect. */
    wsgl_flush(ws);
}

void phg_wsb_repaint_all(
    Ws *ws,
    Pctrl_flag clear_control
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    /* assuming this stuff does clear */
    if (clear_control == PFLAG_ALWAYS
        || owsb->surf_state == PSURF_NOT_EMPTY) {
	/* TODO: Need a way to "clear" the window that uses the zero-th
	 * entry in the WS colour table and runs it through colour mapping.
	 */
#ifdef DEBUG
        printf("wsb: Clear\n");
#endif

	wsgl_clear(ws);
    }
    owsb->surf_state = PSURF_EMPTY;

    phg_wsb_traverse_all_postings(ws);

    /* now swap the buffers and update the drawable indices */
    wsgl_flush(ws);

#if TODO
    /* Redraw input prompts & echos of any active input devices. */
    if ( ws->input_repaint && WS_ANY_INP_DEV_ACTIVE(ws) )
	(ws->input_repaint)( ws, num_rects, exposure_rects );
#endif
}

void phg_wsb_traverse_all_postings(
    Ws *ws
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;
    Ws_post_str		*post_str, *end;

    WSB_CHECK_POSTED(&owsb->posted);
    if( WSB_SOME_POSTED(&owsb->posted) ) {
	/* Set up for complete traversal. */
	post_str = owsb->posted.lowest.higher;
	end = &(owsb->posted.highest);
        wsgl_begin_rendering(ws);
	while ( post_str != end ) {
	    phg_wsb_traverse_net( ws, post_str->structh );
	    post_str = post_str->higher;
	}
        wsgl_end_rendering(ws);
	owsb->surf_state = PSURF_NOT_EMPTY;
    }
}

void phg_wsb_traverse_net(
    Ws_handle ws,
    Struct_handle structp
    )
{
    El_handle el;

    wsgl_begin_structure(ws, structp->struct_id);
    el = structp->first_el;
    while ( 1 ) {	/* termination test is at the bottom */
	switch ( el->eltype ) {
	    case PELEM_NIL:
		break;
	    case PELEM_EXEC_STRUCT:
		phg_wsb_traverse_net( ws, (Struct_handle)el->eldata.ptr );
		break;
	    default:
                wsgl_render_element(ws, el);
		break;
	}

	if ( el == structp->last_el )
	    break;  /* out of the while over all elements in struct */
	el = el->next;
    }
    wsgl_end_structure(ws);
}

static int wsb_visible_element_type(
    El_handle el
    )
{
    int		status = 1;	/* almost all are */

    switch ( el->eltype ) {
#ifdef TODO
	case PELEM_APPL_DATA:
#endif
	case PELEM_LABEL:
	case PELEM_PICK_ID:
	    status = 0;
	    break;
        default:
            /* Default */
            break;
    }

    return status;
}

void phg_wsb_add_el(
    Ws *ws
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;
    El_handle		cur_el = CSS_CUR_ELP(owsb->cssh);

#ifdef DEBUG
    printf("wsb: Add\n");
#endif

    assert(CSS_CUR_STRUCTP(owsb->cssh)); /* A structure must be open */
    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	default:
	    if ( wsb_visible_element_type( cur_el ) )
		(*ws->redraw_all)( ws, PFLAG_COND );
	    break;

	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	case PHG_UPDATE_UQUM:
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
    }
}

int phg_wsb_asti_update(
    Ws *ws,
    Pctrl_flag clear_control
    )
{
    /* Returns non-zero if redraw occurred. */

    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

#ifdef DEBUG
    printf("wsb: Asti\n");
#endif
    switch ( (*owsb->update_action_table)
	    [(int)PHG_TIME_ATI]
	    [(int)ws->out_ws.mod_mode]
	    [(int)ws->out_ws.def_mode] ) {
	case PHG_UPDATE_IF_INCORRECT:
	case PHG_UPDATE_IF_IL:
	case PHG_UPDATE_IF_IG:
	    if ( owsb->vis_rep == PVISUAL_ST_CORRECT )
		break;
	    /* else fall through to PHG_UPDATE_ACCURATE case */
	case PHG_UPDATE_ACCURATE:
	    (*ws->redraw_all)( ws, clear_control );
	    return 1;

	case PHG_UPDATE_UQUM:
	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	    break;
        default:
            /* Default */
            break;
    }

    return 0;
}

void phg_wsb_close_struct(
    Ws *ws,
    Struct_handle structh
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

#ifdef DEBUG
    printf("wsb: Close\n");
#endif

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    /* First, do processing that is independent of screen output */
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	case PHG_UPDATE_UQUM:
	default:
	    break;
    }

    /* Updates are implementation dependent in ASTI mode.  This is one
     * of the cases where we do an ASTI update;  we're hopefully doing the
     * application a favor.
     */
    (void)phg_wsb_asti_update( ws, PFLAG_COND );
}

static void wsb_update_a_posting(
    Ws *ws,
    Ws_post_str *posting
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

#ifdef DEBUG
    printf("wsb: Posting\n");
#endif

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	    (*ws->redraw_all)( ws, PFLAG_COND );
	    break;

	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	case PHG_UPDATE_UQUM:
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
        default:
            /* Default */
            break;
    }
}

void phg_wsb_post(
    Ws *ws,
    Struct_handle structh,
    Pfloat priority,
    Pint first_posting
    )
{
    Ws_post_str 	*start;

    Wsb_output_ws	*owsb = &ws->out_ws.model.b;
    Ws_post_str 	*cur, *end;
    Ws_post_str 	*new;

    if ( !first_posting ) {
	/* Check to see if structure is already posted. */
	cur = owsb->posted.lowest.higher;
	end = &owsb->posted.highest;
	while ( cur != end && cur->structh != structh )
	    cur = cur->higher;
    }

    /* The structure is already_posted if (cur != end). */
    if ( !first_posting && cur != end ) {
	if( cur->higher != end && priority >= cur->higher->disp_pri ) {
	    start = end->lower;
	    assert(start == owsb->posted.highest.lower);
	    end = cur->higher;	/* insert betw. cur->higher & posted.highest */
	} else if ( cur->lower != &owsb->posted.lowest
		&& priority < cur->lower->disp_pri ) {
	    /* Will insert between start and cur->lower. */
	    start = cur->lower;
	    end = &owsb->posted.lowest;
	} else {
	    /* This is a reposting with the same *relative* prio. */
	    cur->disp_pri = priority;
	    return;
	}

	/* Struct is posted.  Remove it, but re-use its Ws_post_str entry */
	cur->lower->higher = cur->higher;
	cur->higher->lower = cur->lower;
	new = cur;

    } else {
	/* Struct is not currently posted, malloc an element. */
	if ( !(new = (Ws_post_str *)malloc(sizeof(Ws_post_str))) ) {
	    ERR_BUF( ws->erh, ERR900);
	    return;
	}
	start = owsb->posted.highest.lower;
	end = &owsb->posted.lowest;
    }

    /* Now figure out where to insert it, working backwards from start
     * to end
     */
    cur = start;
    while ( cur != end && cur->disp_pri > priority )
	cur = cur->lower;	/* if priorities equal, new after cur */
    /* insert new element w/prio >= than cur's, so cur->higher will be new */
    new->lower = cur;
    new->higher = cur->higher;
    cur->higher = new;
    new->higher->lower = new;
    new->structh = structh;
    new->disp_pri = priority;

    if ( structh->num_el != 0 )
	wsb_update_a_posting( ws, new );
}

/* This function only called from the css for change struct ids/refs -
 * it is used to change the structure pointers referencing a given
 * structure, because the way the change struct ids/refs functions work
 * is by changing struct_id fields rather than copying whole structures,
 * so any lists using structure pointers to reference specific structures
 * have to be changed to use the correct pointers.
 */

void phg_wsb_change_posting(
    Ws *ws,
    Struct_handle unpost,
    Struct_handle post
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;
    Ws_post_str 	*cur, *end;

    cur = owsb->posted.lowest.higher;
    end = &owsb->posted.highest;
    while ( cur != end && cur->structh != unpost )
	cur = cur->higher;

    if ( cur != end ) {
	if ( post ) {
	    /* if the structure to be "posted" is already posted, remove it */
	    phg_wsb_change_posting( ws, post, (Struct_handle)NULL );
	    /* Change posted structure from "unpost" to "post", same priority*/
	    cur->structh = post;
	} else {
	    /* Post is NULL - just remove Ws_post_str entry for unpost. */
	    cur->lower->higher = cur->higher;
	    cur->higher->lower = cur->lower;
	    free( (char *)cur );
	}
    }
}

/* Search the list of posted structures for this one.
 * If found, return pointer to next-higher-priority posted structure element.
 * (Remember that that could be the dummy element owsb->posted.highest)
 * If not, return NULL.
 */
static Ws_post_str* wsb_unpost_struct_if_found(
    Wsb_output_ws *owsb,
    Struct_handle structh
    )
{
    Ws_post_str	*cur, *end;

    cur = owsb->posted.lowest.higher;
    end = &owsb->posted.highest;
    while ( cur != end && cur->structh != structh )
	cur = cur->higher;
    if ( cur != end ) {
	/* Found it -- now delete it */
	cur->lower->higher = cur->higher;
	cur->higher->lower = cur->lower;
	end = cur->higher;	/* Save this around the free */
	free( (char *)cur );
	return end;
    } else
	return (Ws_post_str*)NULL;
}

void phg_wsb_unpost(
    Ws *ws,
    Struct_handle structh
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    if ( !wsb_unpost_struct_if_found( owsb, structh ) )
	/* Tried to unpost structure that wasn't there; but that's okay. */
	return;

    if ( structh->num_el != 0 ) {
	WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
	switch ( owsb->now_action ) {
	    case_PHG_UPDATE_ACCURATE_or_IF_Ix:
		(*ws->redraw_all)( ws, PFLAG_COND );
		break;

	    case PHG_UPDATE_UWOR:
	    case PHG_UPDATE_NOTHING:
	    case PHG_UPDATE_UQUM:
		owsb->vis_rep = PVISUAL_ST_DEFER;
		break;
            default:
                /* Default */
                break;
	}
    }
}

void phg_wsb_unpost_all(
    Ws *ws
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    wsb_free_all_posted( owsb );
    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	    (*ws->redraw_all)( ws, PFLAG_COND );
	    break;

	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	case PHG_UPDATE_UQUM:
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
        default:
            /* Default */
            break;
    }
}

void phg_wsb_delete_all_structs(
    Ws *ws
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    phg_wsb_unpost_all( ws );
}

int phg_wsb_delete_struct(
    Ws *ws,
    Struct_handle structh,
    Ws_delete_flag flag
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;
    int			call_again = 0;

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	    if ( flag == WS_PRE_CSS_DELETE ) {
		(void)wsb_unpost_struct_if_found( owsb, structh );
		call_again = 1;
	    } else
		(*ws->redraw_all)( ws, PFLAG_COND );
	    break;

	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	case PHG_UPDATE_UQUM:
	    (void)wsb_unpost_struct_if_found( owsb, structh );
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
        default:
            /* Default */
            break;
    }

    return call_again;
}

int phg_wsb_delete_struct_net(
    Ws *ws,
    Struct_handle structh,
    Pref_flag reff,
    Ws_delete_flag flag
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;
    int			call_again = 0;

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	    if ( flag == WS_PRE_CSS_DELETE ) {
		(void)wsb_unpost_struct_if_found( owsb, structh );
		call_again = 1;
	    } else
		(*ws->redraw_all)( ws, PFLAG_COND );
	    break;

	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	case PHG_UPDATE_UQUM:
	default:
	    (void)wsb_unpost_struct_if_found( owsb, structh );
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
    }
    return call_again;
}

void phg_wsb_copy_struct(
    Ws *ws,
    El_handle first_el
    )
{
    (*ws->conditional_redraw)( ws );
}

/* Delete elements elh1 through elh2, inclusive, in structure structh */
int phg_wsb_delete_el(
    Ws *ws,
    Struct_handle structh,
    El_handle elh1,
    El_handle elh2,
    Ws_delete_flag flag
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;
    int			call_again = 0;

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	default:
	    if ( flag == WS_PRE_CSS_DELETE ) {
		if ( elh1 == elh2 && !wsb_visible_element_type( elh1 ) )
		    call_again = 0; /* avoid second call. */
		else
		    call_again = 1;
	    } else		/* POST_CSS_DELETE */
		(*ws->redraw_all)(ws, PFLAG_COND);
	    break;

	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	case PHG_UPDATE_UQUM:
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
    }

    return call_again;
}

/* Called by CP after difficult operations like change struct refs/ids.
 * Redraws workstation, if that is permitted, else DEFERs.
 */
void phg_wsb_conditional_redraw(
    Ws *ws
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	    (*ws->redraw_all)( ws, PFLAG_ALWAYS );
	    break;

	case PHG_UPDATE_UQUM:
	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
        default:
            /* Default */
            break;
    }
}

/* Resolves PHG_UPDATE_IF_Ix to the ASTI now_action, if no input device active.
 *
 * Check this function before every (out_ws->now_action) use.
 * Then use case_PHG_UPDATE_ACCURATE_or_IF_Ix in switch (out_ws->now_action),
 * so that PHG_UPDATE_IF_Ix acts as PHG_UPDATE_ACCURATE (i.e., ASAP)
 * while appicable input devices are (still) active.
 */
void phg_wsb_resolve_now_action(
    Ws *ws,
    Ws_update_action *now_action_ptr
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    switch ( *now_action_ptr ) {
      case PHG_UPDATE_IF_IL:
	/* If none active, treat like ASTI until next bnig_update(ws,ws) */
	if ( !WS_ANY_INP_DEV_ACTIVE(ws) ) {
	    *now_action_ptr = (*owsb->update_action_table)
		[(int)PHG_TIME_NOW][(int)ws->out_ws.mod_mode][(int)PDEFER_ASTI];
	}
	break;

      case PHG_UPDATE_IF_IG:
	/* If none active, treat like ASTI until next bnig_update(ws,*) */
#ifdef TODO
	if ( !phg_cp_any_inp_device_active( ws->cph ) ) {
	    *now_action_ptr = (*owsb->update_action_table)
		[(int)PHG_TIME_NOW][(int)ws->out_ws.mod_mode][(int)PDEFER_ASTI];
	}
#endif
	break;

        default:
          /* Default */
        break;
    }
}

void phg_wsb_update(
    Ws *ws,
    Pregen_flag flag
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    if ( flag != PFLAG_POSTPONE && owsb->vis_rep != PVISUAL_ST_CORRECT ) 
	(*ws->redraw_all)( ws, PFLAG_COND );
    else
	(*ws->make_requested_current)( ws );
}

void phg_wsb_set_disp_update_state(
    Ws *ws,
    Pdefer_mode def_mode,
    Pmod_mode mod_mode
    )
{
    Ws_update_action	previous_now_action;

    Ws_output_ws	*out_ws = &ws->out_ws;
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    out_ws->def_mode = def_mode;
    out_ws->mod_mode = mod_mode;

    previous_now_action = owsb->now_action;
    owsb->now_action = (*owsb->update_action_table)
	[(int)PHG_TIME_NOW][(int)out_ws->mod_mode][(int)out_ws->def_mode];
    assert(owsb->now_action != PHG_UPDATE_IF_INCORRECT);

    if ( owsb->now_action != previous_now_action ) {
	WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
	switch ( owsb->now_action ) {
	    case_PHG_UPDATE_ACCURATE_or_IF_Ix:
		if( owsb->vis_rep != PVISUAL_ST_CORRECT )
		    (*ws->redraw_all)( ws, PFLAG_COND );
		break;
            default:
                /* Default */
                break;
	}
    }
}

void phg_wsb_set_hlhsr_mode(
    Ws *ws,
    Pint mode
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    owsb->req_hlhsr_mode = mode;
    owsb->hlhsr_mode_pending = PUPD_PEND;

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	    (*ws->redraw_all)( ws, PFLAG_COND );
	    break;

	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_UQUM:
	case PHG_UPDATE_NOTHING:
	default:
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
    }
}

void phg_wsb_set_ws_window(
    Ws *ws,
    Pint two_d,
    Plimit3 *limits
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    owsb->ws_window_pending = PUPD_PEND;
    if ( two_d ) {	/* leave the z values as they are */
	owsb->req_ws_window.x_min = limits->x_min;
	owsb->req_ws_window.x_max = limits->x_max;
	owsb->req_ws_window.y_min = limits->y_min;
	owsb->req_ws_window.y_max = limits->y_max;
    } else
	owsb->req_ws_window = *limits;

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	    (*ws->redraw_all)( ws, PFLAG_COND );
	    break;

	case PHG_UPDATE_UQUM:
	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	default:
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
    }
}

void phg_wsb_set_ws_vp(
    Ws *ws,
    Pint two_d,
    Plimit3 *limits
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    owsb->ws_viewport_pending = PUPD_PEND;
    if ( two_d ) {	/* leave the z values as they are */
	owsb->req_ws_viewport.x_min = limits->x_min;
	owsb->req_ws_viewport.x_max = limits->x_max;
	owsb->req_ws_viewport.y_min = limits->y_min;
	owsb->req_ws_viewport.y_max = limits->y_max;
    } else
	owsb->req_ws_viewport = *limits;

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	    (*ws->redraw_all)( ws, PFLAG_COND );
	    break;

	case PHG_UPDATE_UQUM:
	case PHG_UPDATE_UWOR:
	case PHG_UPDATE_NOTHING:
	default:
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
    }
}

static int phg_wsb_add_view(
    Ws *ws,
    Pint id,
    Pint priority,
    Pview_rep3 *vrep
    )
{
    int status;
    Ws_view_ref *vref, *dupref;
    Ws_output_ws  *ows = &ws->out_ws;
    Wsb_output_ws *owsb = &ows->model.b;

    /* Create new node */
    vref = (Ws_view_ref *) malloc(sizeof(Ws_view_ref) + sizeof(Pview_rep3));
    if (vref == NULL) {
        status = FALSE;
    }
    else {
        /* Remove duplicated views */
        dupref = phg_wsb_find_view(&owsb->pending_views, id);
        if (dupref != NULL) {
            list_remove(&owsb->pending_views, &dupref->node);
            free(dupref);
        }

        vref->id = id;
        vref->priority = priority;
        vref->npc_to_wc_state = WS_INV_NOT_CURRENT;
        vref->viewrep = (Pview_rep3 *) &vref[1];
        memcpy(vref->viewrep, vrep, sizeof(Pview_rep3));
        list_add(&owsb->pending_views, &vref->node);
        owsb->views_pending = PUPD_PEND;
        status = TRUE;
    }

    return status;
}

void phg_wsb_set_rep(
    Ws *ws,
    Phg_args_rep_type type,
    Phg_args_rep_data *rep
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;
    Pgcolr      gcolr;

    switch ( type ) {
	case PHG_ARGS_LNREP:
	case PHG_ARGS_EXTLNREP:
	case PHG_ARGS_MKREP:
	case PHG_ARGS_EXTMKREP:
	case PHG_ARGS_TXREP:
	case PHG_ARGS_EXTTXREP:
	case PHG_ARGS_INTERREP:
	case PHG_ARGS_EXTINTERREP:
        case PHG_ARGS_EFREP:
	case PHG_ARGS_EDGEREP:
	case PHG_ARGS_EXTEDGEREP:
	case PHG_ARGS_PTREP:
	case PHG_ARGS_EXTPTREP:
	case PHG_ARGS_DCUEREP:
	case PHG_ARGS_LIGHTSRCREP:
	case PHG_ARGS_COLRMAPREP:
            phg_wsb_set_LUT_entry(ws, type, rep, NULL);
	    break;

	case PHG_ARGS_COREP:
	    /* Store in current colour model. */
	    gcolr.type = ws->current_colour_model;
	    gcolr.val.general.x = rep->bundl.corep.rgb.red;
	    gcolr.val.general.y = rep->bundl.corep.rgb.green;
	    gcolr.val.general.z = rep->bundl.corep.rgb.blue;
            phg_wsb_set_LUT_entry(ws, type, rep, &gcolr);
	    break;

	case PHG_ARGS_VIEWREP:
#ifdef DEBUG
            printf("Set view: %d\n", rep->index);
#endif
            phg_wsb_set_LUT_entry(ws, type, rep, NULL);
            if (!phg_wsb_add_view(ws,
                                  rep->index,
                                  rep->index,
                                  &rep->bundl.viewrep)) {
	        ERR_BUF(ws->erh, ERR900);
            }
	    break;
    }

    WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
    switch ( owsb->now_action ) {
	case_PHG_UPDATE_ACCURATE_or_IF_Ix:
	    (*ws->redraw_all)( ws, PFLAG_COND );
	    break;

	case PHG_UPDATE_NOTHING:
	    /* Defer if rep has PENDING flag, or if screen could be affected. */
	    if ( WSB_SOME_POSTED(&owsb->posted) || (type == PHG_ARGS_VIEWREP) )
		 owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;

	default:
	case PHG_UPDATE_UQUM:
	case PHG_UPDATE_UWOR:
	    owsb->vis_rep = PVISUAL_ST_DEFER;
	    break;
    }
}

void phg_wsb_set_filter(
    Ws *ws,
    Phg_args_flt_type type,
    Pint dev_id,
    Pint_list *incl_set,
    Pint_list *excl_set
    )
{
    Wsb_output_ws *owsb = &ws->out_ws.model.b;

    phg_wsb_set_name_set( ws, type, dev_id, incl_set, excl_set );

    if ( (type == PHG_ARGS_FLT_HIGH || type == PHG_ARGS_FLT_INVIS)
	    && WSB_SOME_POSTED(&owsb->posted) ) {
	WSB_CHECK_FOR_INTERACTION_UNDERWAY(ws, &owsb->now_action);
	switch ( owsb->now_action ) {
	    case_PHG_UPDATE_ACCURATE_or_IF_Ix:
		(*ws->redraw_all)( ws, PFLAG_COND );
		break;

	    case PHG_UPDATE_UQUM:
	    case PHG_UPDATE_UWOR:
	    case PHG_UPDATE_NOTHING:
	    default:
		owsb->vis_rep = PVISUAL_ST_DEFER;
		break;
	}
    }
}

#if 0
void
phg_wsb_inq_filter( ws, type, ret )
    Ws                  *ws;
    Phg_args_flt_type   type;
    Phg_ret             *ret;
{
    phg_wsx_inq_name_set( ws, type, (Pint)0, ret );
}

#endif

void phg_wsb_inq_posted(
    Ws *ws,
    Phg_ret *ret
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    Ws_post_str	*cur, *end;
    int		cnt;
    Pposted_struct	*list;

    cur = owsb->posted.lowest.higher;
    end = &owsb->posted.highest;

    /* Count them */
    cnt = 0;
    while ( cur != end ) {
	++cnt;
	cur = cur->higher;
    }

    ret->err = 0;
    ret->data.postlist.num_postings = cnt;
    if ( cnt > 0 ) {
	if ( PHG_SCRATCH_SPACE(&ws->scratch, cnt * sizeof(Pposted_struct)) ) {
	    ret->data.postlist.postings = list =
		(Pposted_struct *)ws->scratch.buf;
	    cur = owsb->posted.lowest.higher;
	    while ( cur != end ) {
		list->id = cur->structh->struct_id;
		list++->disp_pri = cur->disp_pri;
		cur = cur->higher;
	    }

	} else {
	    ret->err = ERR900;
	    ret->data.postlist.num_postings = 0;
	}
    }
}

void phg_wsb_inq_disp_update_state(
    Ws *ws,
    Phg_ret *ret
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    ret->err = 0;
    ret->data.update_state.def_mode = ws->out_ws.def_mode;
    ret->data.update_state.mod_mode = ws->out_ws.mod_mode;
    ret->data.update_state.display_surf = owsb->surf_state;
    ret->data.update_state.state = owsb->vis_rep;
}

void phg_wsb_inq_hlhsr_mode(
    Ws *ws,
    Phg_ret *ret
    )
{
    Wsb_output_ws	*owsb = &ws->out_ws.model.b;

    ret->err = 0;
    ret->data.hlhsr_mode.state =  owsb->hlhsr_mode_pending;
    ret->data.hlhsr_mode.cur_mode = owsb->cur_hlhsr_mode;
    ret->data.hlhsr_mode.req_mode = owsb->req_hlhsr_mode;
}

void phg_wsb_inq_rep(
    Ws *ws,
    Pint index,
    Pinq_type how,
    Phg_args_rep_type rep_type,
    Phg_ret *ret
    )
{
    Pgcolr gcolr;
    Pcolr_rep *cb;
    Pview_rep3 vrep;

    ret->err = 0;
    switch ( rep_type ) {
	case PHG_ARGS_LNREP:
	case PHG_ARGS_EXTLNREP:
	case PHG_ARGS_MKREP:
	case PHG_ARGS_EXTMKREP:
	case PHG_ARGS_TXREP:
	case PHG_ARGS_EXTTXREP:
	case PHG_ARGS_INTERREP:
	case PHG_ARGS_EXTINTERREP:
	case PHG_ARGS_EDGEREP:
	case PHG_ARGS_EXTEDGEREP:
	case PHG_ARGS_PTREP:
	case PHG_ARGS_EXTPTREP:
	case PHG_ARGS_DCUEREP:
	case PHG_ARGS_LIGHTSRCREP:
	case PHG_ARGS_COLRMAPREP:
	/* View rep is done elsewhere. */
	    phg_wsb_inq_LUT_entry(ws, index, how, rep_type, ret, NULL, NULL);
	    break;

	case PHG_ARGS_COREP:
	    cb = &ret->data.rep.corep;

	    /* Need to convert to current colour model. */
            phg_wsb_inq_LUT_entry(ws, index, how, rep_type, ret, &gcolr, NULL);

            /* NOTE:
             * Convert to correct colour model here if needed
             */

	    cb->rgb.red = gcolr.val.general.x;
	    cb->rgb.green = gcolr.val.general.y;
	    cb->rgb.blue = gcolr.val.general.z;
	    break;

        case PHG_ARGS_VIEWREP:
            phg_wsb_inq_LUT_entry(ws, index, how, rep_type, ret, NULL, &vrep);
            memcpy(&ret->data.rep.viewrep, &vrep, sizeof(Pview_rep3));
            break;

	default:
            /* Default */
            break;
    }
}

/*******************************************************************************
 * phg_wsb_set_view_input_priority
 *
 * DESCR:       Set priority of view relative another view
 * RETURNS:     N/A
 */

void phg_wsb_set_view_input_priority(
   Ws *ws,
   Pint index,
   Pint ref_index,
   Prel_pri priority
   )
{
    NodePrio prio;
    Wsb_output_ws *owsb = &ws->out_ws.model.b;
    Ws_view_ref *view = phg_wsb_find_view(&owsb->views, index);
    Ws_view_ref *ref = phg_wsb_find_view(&owsb->views, ref_index);
    prio = (priority == PPRI_LOWER) ? NODE_PRIO_LOWER : NODE_PRIO_HIGHER;

    if ((ref != NULL) && (view != NULL)) {
       list_requeue(&owsb->views, &view->node, &ref->node, prio);
    }
#ifdef DEBUG
    {
        Ws_view_ref *v;
        for (v = (Ws_view_ref *) LIST_HEAD(&owsb->views);
             v != NULL;
             v = (Ws_view_ref *) NODE_NEXT(&v->node)) {
            printf("wsb: View %d with priority: %d\n", v->id, v->priority);
        }
    }
#endif
}

/*******************************************************************************
 * update_inv_view_xform
 *
 * DESCR:       Update inverse transform helper function
 * RETURNS:     N/A
 */

static void update_inv_view_xform(
    Ws_view_ref *view_ref
    )
{
    Pview_rep3 *viewrep;

    /* Calculate the inverse xform, if necessary. */
    if (view_ref->npc_to_wc_state == WS_INV_NOT_CURRENT) {
        viewrep = view_ref->viewrep;
        phg_mat_mul(view_ref->npc_to_wc,
                    viewrep->map_matrix,
                    viewrep->ori_matrix);
        phg_mat_inv(view_ref->npc_to_wc);
        view_ref->npc_to_wc_state = WS_INV_CURRENT;
    }
}

/*******************************************************************************
 * phg_wsb_map_initial_points
 *
 * DESCR:       Map initial points
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_map_initial_points(
    Ws *ws,
    Pint view_index,
    Pint *num_pts,
    Ppoint3 *wc_pts,
    XPoint *dwbl_pts
    )
{
    int i;
    Ppoint3 scratch[20];    /* enough for most cases */
    Pmatrix3 wc_to_npc;
    Ppoint3 dc_pt;
    Ws_view_ref *view_ref;
    Pview_rep3 *viewrep;
    Ppoint3 *npc_pts = NULL;
    Ws_xform *wsxf = &ws->out_ws.model.b.ws_xform;
    Wsb_output_ws *owsb = &ws->out_ws.model.b;

    /* Transform the initial points to NPC and check that they all fit
     * in the clip limits of the specified view.  Then transform and map
     * them to drawable coordinates.
     */
    if (*num_pts <= 0) {
        return FALSE;
    }
    if (*num_pts <= sizeof(scratch) / sizeof(scratch[0])) {
        npc_pts = scratch;
    }
    else if (*num_pts > sizeof(scratch) / sizeof(scratch[0])) {
        npc_pts = (Ppoint3 *) malloc((unsigned) (*num_pts * sizeof(Ppoint3 *)));
        if (npc_pts == NULL) {
            *num_pts = 0;
            ERR_BUF(ws->erh, ERR900);
            return FALSE;
        }
    }

    /* Find current view */
    view_ref = phg_wsb_find_view(&owsb->views, view_index);
    if (view_ref == NULL) {
       *num_pts = 0;
       return FALSE;
    }
    viewrep = view_ref->viewrep;

    /* Map initial point in view */
    phg_mat_mul(wc_to_npc, viewrep->map_matrix, viewrep->ori_matrix);
    if (!phg_tranpts3(wc_to_npc, *num_pts, wc_pts, npc_pts)) {
        *num_pts = 0;
        return FALSE;
    }

    for (i = 0; i < *num_pts; i++) {
        if (!WS_PT_IN_LIMIT(&viewrep->clip_limit, &npc_pts[i])) {
            *num_pts = 0;
            break;
        } else {
            WS_NPC_TO_DC(wsxf, &npc_pts[i], &dc_pt)
            WS_DC_TO_DRWBL2(ws, &dc_pt, &dwbl_pts[i]);
        }
    }

    if ((npc_pts != NULL) &&
        (npc_pts != scratch)) {
        free(npc_pts);
    }

    return (*num_pts > 0 ? TRUE : FALSE);
}

/*******************************************************************************
 * phg_wsb_resolve_locator
 *
 * DESCR:       Resolve locator device
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_resolve_locator(
    Ws *ws,
    Ws_point *dc_pt,
    int determine_z,
    Pint *view_index,
    Ppoint3 *wc_pt
    )
{
    Ppoint3 npc_pt;
    Ws_view_ref *view_ref;
    Pview_rep3 *viewrep;
    Wsb_output_ws *owsb = &ws->out_ws.model.b;
    Ws_xform *wsxf = &owsb->ws_xform;
    Plimit3 *ws_win = &owsb->ws_window;
    int in_win = FALSE;
    int in_clip = FALSE;
    int status = FALSE;

    /* Apply the inverse WS transform and see if it's in the ws window.
     * Can't just check against the viewport boundaries because the
     * window may be smaller if the aspect ratios are different.
     */
    WS_DC_TO_NPC2(wsxf, dc_pt, &npc_pt)
    if (WS_PT_IN_LIMIT2(ws_win, &npc_pt)) {
        in_win = TRUE;
    }

    if (in_win) {
        /* Find the highest priority view that contains the point. */
        for (view_ref = (Ws_view_ref *) LIST_HEAD(&owsb->views);
             view_ref != NULL;
             view_ref = (Ws_view_ref *) NODE_NEXT(&view_ref->node)) {

            viewrep = view_ref->viewrep;
            if (WS_PT_IN_LIMIT2(&viewrep->clip_limit, &npc_pt)) {
                in_clip = TRUE;
            }

            if (in_clip) {
                /* Calculate the inverse xform if necessary. */
                if (view_ref->npc_to_wc_state == WS_INV_NOT_CURRENT) {
                    update_inv_view_xform(view_ref);
                }

                /* Map point to WC if xform invertible. */
                if (view_ref->npc_to_wc_state == WS_INV_CURRENT) {
                    npc_pt.z = viewrep->clip_limit.z_min;
                    if (phg_tranpt3(&npc_pt, view_ref->npc_to_wc, wc_pt)) {
                        *view_index = view_ref->id;
                        status = TRUE;
                        break;  /* out of the for on view index */
                    }
                }
            }
        }
    }

    return status;
}

/*******************************************************************************
 * phg_wsb_point_in_viewport
 *
 * DESCR:       Test if point is within viewport
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_point_in_viewport(
    Ws *ws,
    XPoint *pt
    )
{
    int status;
    Ppoint dc_pt;

    phg_wsx_update_ws_rect(ws);
    WS_DRWBL_TO_DC2(ws, pt, &dc_pt);
    status = WS_PT_IN_LIMIT2(&ws->out_ws.model.b.ws_viewport, pt);

    return status;
}

/*******************************************************************************
 * wsb_stroke_view
 *
 * DESCR:       Resolve stroke device helper function
 * RETURNS:     TRUE or FALSE
 */

static int wsb_stroke_view(
    Ws *ws,
    Ws_point *dc_ll,
    Ws_point *dc_ur,
    Ws_view_ref **vref
    )
{
    Ppoint3 npc_ll, npc_ur;
    Ws_view_ref *view_ref;
    Pview_rep3 *viewrep;
    Wsb_output_ws *owsb = &ws->out_ws.model.b;
    Ws_xform *wsxf = &owsb->ws_xform;
    Plimit3 *ws_win = &owsb->ws_window;
    int status = FALSE;
    int in_win = FALSE;
    int in_clip = FALSE;

    WS_DC_TO_NPC2(wsxf, dc_ll, &npc_ll);
    WS_DC_TO_NPC2(wsxf, dc_ur, &npc_ur);
    if ((WS_PT_IN_LIMIT2(ws_win, &npc_ll)) &&
        (WS_PT_IN_LIMIT2(ws_win, &npc_ur))) {
        in_win = TRUE;
    }

    if (in_win) {
        /* Find the highest priority view that contains the point. */
        for (view_ref = (Ws_view_ref *) LIST_HEAD(&owsb->views);
             view_ref != NULL;
             view_ref = (Ws_view_ref *) NODE_NEXT(&view_ref->node)) {

            viewrep = view_ref->viewrep;

            if ((WS_PT_IN_LIMIT2(&viewrep->clip_limit, &npc_ll)) &&
                (WS_PT_IN_LIMIT2(&viewrep->clip_limit, &npc_ur))) {
                in_clip = TRUE;
            }

            /* Found a matching view */
            if (in_clip) {
                if (view_ref->npc_to_wc_state == WS_INV_NOT_CURRENT) {
                    update_inv_view_xform(view_ref);
                }

                if (view_ref->npc_to_wc_state == WS_INV_CURRENT) {
                    *vref = view_ref;
                    status = TRUE;
                    break;
                }
            }
        }
    }

    return status;
}

/*******************************************************************************
 * wsb_transform_stroke
 *
 * DESCR:       Transform stroke device helper function
 * RETURNS:     N/A
 */

static void wsb_transform_stroke(
    Ws *ws,
    Ws_view_ref *vref,
    int determine_z,
    Pint num_pts,
    Ws_point *dc_pts,
    Ppoint_list3 *wc_pts
    )
{
    Pint i;
    Ppoint3 *npc_pts;
    Wsb_output_ws *owsb = &ws->out_ws.model.b;
    Ws_xform *wsxf = &owsb->ws_xform;
    Pview_rep3 *viewrep;

    viewrep = vref->viewrep;

    npc_pts = (Ppoint3 *) malloc(num_pts * sizeof(Ppoint3));
    if (npc_pts == NULL) {
       wc_pts->num_points = 0;
       ERR_BUF(ws->erh, ERR900);
    }
    else {
        for (i = 0; i < num_pts; i++) {
            WS_DC_TO_NPC2(wsxf, &dc_pts[i], &npc_pts[i]);
            npc_pts[i].z = viewrep->clip_limit.z_min;
        }

        /* Transform to world coordinates */
        if (!phg_tranpts3(vref->npc_to_wc,
                         num_pts,
                         npc_pts,
                         wc_pts->points)) {
            wc_pts->num_points = 0;
        }
        free(npc_pts);
    }
}

/*******************************************************************************
 * phg_wsb_resolve_stroke
 *
 * DESCR:       Resolve stroke device
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_resolve_stroke(
    Ws *ws,
    Pint num_pts,
    Ws_point *dc_pts,
    int determine_z,
    Pint *view_index,
    Ppoint_list3 *wc_pts
    )
{
    Pint i, xmin, xmax, ymin, ymax;
    Ws_point ll, ur;
    Ws_point *dp;
    Ws_view_ref *view_ref;
    int status = FALSE;

    xmin = dc_pts->x;
    xmax = dc_pts->x;
    ymin = dc_pts->y;
    ymax = dc_pts->y;

    /* Get bounding box for all points */
    for (i = 1, dp = &dc_pts[1]; i < num_pts; i++, dp++) {
        if (dp->x < xmin) {
            xmin = dp->x;
        }
        else if (dp->x > xmax) {
            xmax = dp->x;
        }

        if (dp->y < ymin) {
            ymin = dp->y;
        }
        else if (dp->y > ymax) {
            ymax = dp->y;
        }
    }

    ll.x = xmin;
    ll.y = ymax;
    ur.x = xmax;
    ur.y = ymin;

    /* Resolve view and transform points */
    if (wsb_stroke_view(ws, &ll, &ur, &view_ref)) {
        wc_pts->num_points = num_pts;
        wsb_transform_stroke(ws,
                             view_ref,
                             determine_z,
                             num_pts,
                             dc_pts,
                             wc_pts);
        *view_index = view_ref->id;
        status = TRUE;
    }

    return status;
}

/*******************************************************************************
 * phg_wsb_resolve_pick
 *
 * DESCR:       Resolve pick device
 * RETURNS:     TRUE or FALSE
 */

int phg_wsb_resolve_pick(
    Ws *ws,
    Ws_inp_pick *dev,
    int echo,
    Ws_point *dc_pt,
    Ppick *pick
    )
{
    int status;
    Pint i;
    Ws_post_str *post_str, *end;
    Ws_hit_box box;
    Ws_pick_elmt *elmts;
    Pint err_ind, depth;
    Wsb_output_ws *owsb = &ws->out_ws.model.b;

    WSB_CHECK_POSTED(&owsb->posted);
    if (WSB_SOME_POSTED(&owsb->posted)) {
        box.x = dc_pt->x;
        box.y = dc_pt->y;
        box.distance = 3.0;

        wsgl_set_filter(ws,
                        PHG_ARGS_FLT_PICK,
                        dev->filter.incl,
                        dev->filter.excl);
        wsgl_begin_pick(ws, &box);

        post_str = owsb->posted.highest.lower;
        end = &(owsb->posted.lowest);

        while (post_str != end) {
            phg_wsb_traverse_net(ws, post_str->structh);
            post_str = post_str->lower;
        }

        wsgl_end_pick(ws, &err_ind, &depth, &elmts);
    }

    if (err_ind != 0) {
        ERR_REPORT(ws->erh, err_ind);
        status = FALSE;
    }
    else if (depth > 0) {
        pick->pick_path.depth = depth;
        pick->pick_path.path_list = (Ppick_path_elem *)
            malloc(sizeof(Ppick_path_elem) * depth);
        if (pick->pick_path.path_list == NULL) {
            pick->status = PIN_STATUS_NONE;
            ERR_REPORT(ws->erh, ERR900);
            free(elmts);
            status = FALSE;
        }
        else {
            pick->status = PIN_STATUS_OK;
            if (dev->order == PORDER_BOTTOM_FIRST) {
                for (i = 0; i < depth; i++) {
                    pick->pick_path.path_list[i].struct_id =
                        elmts[depth - i - 1].sid;
                    pick->pick_path.path_list[i].pick_id =
                        elmts[depth - i - 1].pickid;
                    pick->pick_path.path_list[i].elem_pos =
                        elmts[depth - i - 1].offset;
                }
            }
            else {
                for (i = 0; i < depth; i++) {
                    pick->pick_path.path_list[i].struct_id = elmts[i].sid;
                    pick->pick_path.path_list[i].pick_id = elmts[i].pickid;
                    pick->pick_path.path_list[i].elem_pos = elmts[i].offset;
                }
            }
            free(elmts);
            status = TRUE;
        }
    }
    else {
        pick->status = PIN_STATUS_NONE;
        pick->pick_path.depth = 0;
        status = TRUE;
    }

    return status;
}

