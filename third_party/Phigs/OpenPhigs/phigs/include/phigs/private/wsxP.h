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

#ifndef _wsxP_h
#define _wsxP_h

#include <X11/Xlib.h>
#include <GL/glx.h>

/*******************************************************************************
 * phg_wsx_create
 *
 * DESCR:       Create workstation
 * RETURNS:     Pointer to workstaion of NULL
 */

Ws* phg_wsx_create(
   Phg_args_open_ws *args
   );

/*******************************************************************************
 * phg_wsx_setup_tool
 *
 * DESCR:       Create window
 * RETURNS:     TRUE or FALSE
 */

int phg_wsx_setup_tool(
   Ws *ws,
   Phg_args_conn_info *conn_info,
   Wst *wst
   );

/*******************************************************************************
 * phg_wsx_release_window
 *
 * DESCR:       Release window
 * RETURNS:     N/A
 */

void phg_wsx_release_window(
   Ws *ws
   );

/*******************************************************************************
 * phg_wsx_destroy
 *
 * DESCR:       Destroy workstation
 * RETURNS:     N/A
 */

void phg_wsx_destroy(
   Ws *ws
   );

/*******************************************************************************
 * phg_wsx_open_gl_display
 *
 * DESCR:       Open dipslay with OpenGL extension
 * RETURNS:     N/A
 */

Display* phg_wsx_open_gl_display(
   char *name,
   Pint *err_ind
   );

/*******************************************************************************
 * phg_wsx_find_best_visual
 *
 * DESCR:       Find best matching visual
 * RETURNS:     N/A
 */

void phg_wsx_find_best_visual(
   Ws *ws,
   Wst *wst,
   XVisualInfo **visual_info,
   Colormap *cmap,
   Pint *err_ind
   );

/*******************************************************************************
 * phg_wsx_create_context
 *
 * DESCR:       Create rendering context from visual info
 * RETURNS:     N/A
 */

GLXContext phg_wsx_create_context(
   Ws *ws,
   XVisualInfo *visual_info,
   Pint *err_ind
   );

/*******************************************************************************
 * phg_wsx_pixel_colour
 *
 * DESCR:       Get colour from pixel value
 * RETURNS:     N/A
 */

void phg_wsx_pixel_colour(
   Ws *ws,
   Colormap cmap,
   unsigned long pixel,
   Pgcolr *gcolr
   );

/*******************************************************************************
 * phg_wsx_update_ws_rect
 *
 * DESCR:       Update workstation rectangle
 * RETURNS:     N/A
 */

void phg_wsx_update_ws_rect(
   Ws *ws
   );

/*******************************************************************************
 * phg_wsx_compute_ws_transform
 *
 * DESCR:       Compute workstation transform
 * RETURNS:     N/A
 */

void phg_wsx_compute_ws_transform(
   Plimit3 *ws_win,
   Plimit3 *ws_vp,
   Ws_xform *ws_xform
   );

/*******************************************************************************
 * phg_wsx_input_dispatch_next
 *
 * DESCR:       Process any event on the event queue
 * RETURNS:     TRUE or FALSE
 */

int phg_wsx_input_dispatch_next(
   Ws *ws,
   Phg_sin_evt_tbl *evt_tbl
   );

/*******************************************************************************
 * phg_wstx_create
 *
 * DESCR:       Create workstation type
 * RETURNS:     Pointer to workstation type or NULL
 */

Wst* phg_wstx_create(
   Err_handle erh,
   Pws_cat category,
   int double_buffer
   );

/*******************************************************************************
 * phg_wstx_init
 *
 * DESCR:       Initialize workstation type
 * RETURNS:     TRUE or FALSE
 */

int phg_wstx_init(
   Wst *wst,
   Pws_cat category
   );

#endif /* _wsxP_h */

