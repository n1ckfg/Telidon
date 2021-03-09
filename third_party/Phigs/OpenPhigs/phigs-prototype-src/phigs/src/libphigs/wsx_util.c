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
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xmu/StdCmap.h>
#include <phigs/phg.h>
#include <phigs/private/phgP.h>
#include <phigs/ws.h>
#include <phigs/private/wsglP.h>

/*******************************************************************************
 * get_sharable_colormap
 *
 * DESCR:	Get sharable colormap
 * RETURNS:	Colormap
 */

static Colormap get_sharable_colormap(
   XVisualInfo *vi,
   Display *dpy
   )
{
  Status status;
  XStandardColormap *standardCmaps;
  Colormap cmap;
  int i, numCmaps;

  /* If no standard colormap but TrueColor make an unshared one */
  status = XmuLookupStandardColormap(dpy, vi->screen, vi->visualid,
                vi->depth, XA_RGB_DEFAULT_MAP, False, True);
  if (status == 1) {
    status = XGetRGBColormaps(dpy, RootWindow(dpy, vi->screen),
                &standardCmaps, &numCmaps, XA_RGB_DEFAULT_MAP);

    if (status == 1)
      for (i = 0; i < numCmaps; i++)
        if (standardCmaps[i].visualid == vi->visualid) {
          cmap = standardCmaps[i].colormap;
          XFree(standardCmaps);
          return cmap;
        }
  }

  cmap = XCreateColormap(dpy, RootWindow(dpy, vi->screen),
                vi->visual, AllocNone);
  return cmap;
}

/*******************************************************************************
 * phg_wsx_open_gl_display
 *
 * DESCR:	Open dipslay with OpenGL extension
 * RETURNS:	N/A
 */

Display* phg_wsx_open_gl_display(
   char *name,
   Pint *err_ind
   )
{
   Display *display;
   char *display_name;

   display_name = XDisplayName(name);
   display = XOpenDisplay(display_name);
   if (display != NULL) {
      if (!glXQueryExtension(display, NULL, NULL)) {
         XCloseDisplay(display);
         display = NULL;
         *err_ind = ERRN201;
      }
   }
   else {
      *err_ind = ERRN200;
   }

   return display;
}

/*******************************************************************************
 * phg_wsx_find_best_visual
 *
 * DESCR:	Find best matching visual
 * RETURNS:	N/A
 */

void phg_wsx_find_best_visual(
   Ws *ws,
   Wst *wst,
   XVisualInfo **visual_info,
   Colormap *cmap,
   Pint *err_ind
   )
{
   int args[20];
   int argc = 0;
   Display *dpy = ws->display;
   int status = FALSE;

   /* Select workstation type */
   switch (wst->ws_type) {
      case PWST_OUTPUT_TRUE:
      case PWST_OUTIN_TRUE:
          args[argc++] = GLX_RGBA;
          args[argc++] = GLX_RED_SIZE;
             args[argc++] = 1;
          args[argc++] = GLX_GREEN_SIZE;
             args[argc++] = 1;
          args[argc++] = GLX_BLUE_SIZE;
             args[argc++] = 1;
          args[argc++] = GLX_DEPTH_SIZE;
             args[argc++] = 16;
          args[argc] = None;
          status = TRUE;
          break;

       case PWST_OUTPUT_TRUE_DB:
       case PWST_OUTIN_TRUE_DB:
          args[argc++] = GLX_DOUBLEBUFFER;
          args[argc++] = GLX_RGBA;
          args[argc++] = GLX_RED_SIZE;
             args[argc++] = 1;
          args[argc++] = GLX_GREEN_SIZE;
             args[argc++] = 1;
          args[argc++] = GLX_BLUE_SIZE;
             args[argc++] = 1;
          args[argc++] = GLX_DEPTH_SIZE;
             args[argc++] = 16;
          args[argc] = None;
          status = TRUE;
          break;

      default:
         *err_ind = ERR52;
         status = FALSE;
         break;
   }

   if (status == TRUE) {
      *visual_info = glXChooseVisual(dpy, DefaultScreen(dpy), args);
      if (*visual_info == NULL) {
         *err_ind = ERRN205;
      }
      else {
         /* NOTE: Only call this for true colour */
         *cmap = get_sharable_colormap(*visual_info, dpy);
         *err_ind = 0;
      }
   }
}

/*******************************************************************************
 * phg_wsx_create_context
 *
 * DESCR:	Create rendering context from visual info
 * RETURNS:	N/A
 */

GLXContext phg_wsx_create_context(
   Ws *ws,
   XVisualInfo *visual_info,
   Pint *err_ind
   )
{
   Display *dpy = ws->display;
   GLXContext context;

   context = glXCreateContext(dpy, visual_info, NULL, True);
   if (context == NULL) {
      *err_ind = ERRN206;
   }
   else {
      *err_ind = 0;
   }

   return context;
}

/*******************************************************************************
 * phg_wsx_pixel_colour
 *
 * DESCR:	Get colour from pixel value
 * RETURNS:	N/A
 */

void phg_wsx_pixel_colour(
   Ws *ws,
   Colormap cmap,
   unsigned long pixel,
   Pgcolr *gcolr
   )
{
   XColor color;

   color.pixel = pixel;
   XQueryColor(ws->display, cmap, &color);

   gcolr->type = PMODEL_RGB;
   gcolr->val.general.x = (float) color.red / 65535.0;
   gcolr->val.general.y = (float) color.green / 65535.0;
   gcolr->val.general.z = (float) color.blue / 65535.0;
}

/*******************************************************************************
 * phg_wsx_update_ws_rect
 *
 * DESCR:	Update workstation rectangle
 * RETURNS:	N/A
 */

void phg_wsx_update_ws_rect(
   Ws *ws
   )
{
   XWindowAttributes wattr;

   XGetWindowAttributes(ws->display, ws->drawable_id, &wattr);
   WS_SET_WS_RECT(ws, &wattr)
}

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
   )
{
   Pfloat sx, sy, sz, sxy;

   sx = (ws_vp->x_max - ws_vp->x_min) / (ws_win->x_max - ws_win->x_min);
   sy = (ws_vp->y_max - ws_vp->y_min) / (ws_win->y_max - ws_win->y_min);
   sz = (ws_vp->z_max - ws_vp->z_min) / (ws_win->z_max - ws_win->z_min);

   sxy = (sx < sy) ? sx : sy;

   ws_xform->scale.x = ws_xform->scale.y = sxy;
   ws_xform->scale.z = sz;

   ws_xform->offset.x = ws_vp->x_min - (ws_win->x_min * sxy);
   ws_xform->offset.y = ws_vp->y_min - (ws_win->y_min * sxy);
   ws_xform->offset.z = ws_vp->z_min - (ws_win->z_min * sz);
}

