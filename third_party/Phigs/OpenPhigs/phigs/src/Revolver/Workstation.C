///////////////////////////////////////////////////////////////////////////////
//  DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
//
//  This file is part of Open PHIGS
//  Copyright (C) 2011 - 2012 Surplus Users Ham Society
//
//  Open PHIGS is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 2.1 of the License, or
//  (at your option) any later version.
//
//  Open PHIGS is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with Open PHIGS. If not, see <http://www.gnu.org/licenses/>.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <Xm/Xm.h>
#include <X11/Xmu/StdCmap.h>
#include <GL/glx.h>
#include <X11/GLw/GLwMDrawA.h>
#include <phigs/phg.h>
#include "Workstation.h"

///////////////////////////////////////////////////////////////////////////////
// VkWorkstation
//
// DESCR:       Initialize workstaion
// RETURNS:     N/A
//
Workstation::Workstation(
    const char *name,
    Widget parent,
    int id
    ) :
    VkComponent(name),
    _id(id)
{

    static int reqVisual[] = {
        GLX_DOUBLEBUFFER,
        GLX_RGBA,
        GLX_RED_SIZE, 1,
        GLX_GREEN_SIZE, 1,
        GLX_BLUE_SIZE, 1,
        None
        };

    XVisualInfo *visinfo;

    // Store display for parent widget
    _dpy = XtDisplay(parent);

    // Find appropriate visual
    visinfo = glXChooseVisual(_dpy, DefaultScreen(_dpy), reqVisual);
    if (visinfo == NULL) {
        std::cerr << "No appropriate visual found" << std::endl;
        exit(1);
    }

    // Get sharable colourmap
    _cmap = getSharableCmap(visinfo);

    // Open workstation window
    // TODO: Read width and height from resources
    _baseWidget = XtVaCreateWidget(_name,
                                   glwMDrawingAreaWidgetClass,
                                   parent,
                                   GLwNvisualInfo, visinfo,
                                   XtNcolormap, _cmap,
                                   XmNwidth, 600,
                                   XmNheight, 600,
                                   NULL);

    // Install destroy widget handler
    installDestroyHandler();

     // Add callbacks
     XtAddCallback(_baseWidget,
                   GLwNginitCallback,
                   &Workstation::initCallback,
                   (XtPointer) this);

     XtAddCallback(_baseWidget,
                   GLwNexposeCallback,
                   &Workstation::exposeCallback,
                   (XtPointer) this);

}
 
///////////////////////////////////////////////////////////////////////////////
// className
//
// DESCR:       Get name of object class
// RETURNS:     Class name
//
const char* Workstation::className()
{
    return "Workstation";
}

///////////////////////////////////////////////////////////////////////////////
// init
//
// DESCR:       Initialize workstation window
// RETURNS:     N/A
//
void Workstation::init()
{
    Phg_args_conn_info conn_info;
    XVisualInfo *visinfo;

    XtVaGetValues(_baseWidget, GLwNvisualInfo, &visinfo, NULL);

    conn_info.display     = _dpy;
    conn_info.drawable_id = XtWindow(_baseWidget);
    conn_info.glx_context = glXCreateContext(_dpy, visinfo, 0, False);
    conn_info.colormap    = _cmap;
    conn_info.background  = WhitePixel(conn_info.display, 0);
    popen_ws(0, &conn_info, PWST_OUTPUT_TRUE_DB);

    ppost_struct(_id, 0, 0);
}

///////////////////////////////////////////////////////////////////////////////
// expose
//
// DESCR:       Redraw workstation window
// RETURNS:     N/A
//
void Workstation::expose()
{
    predraw_all_structs(_id, PFLAG_ALWAYS);
}

///////////////////////////////////////////////////////////////////////////////
// getSharableCmap
//
// DESCR:       Get a colourmap that is sharable between windows
// RETURNS:     Colour map
//
Colormap Workstation::getSharableCmap(
    XVisualInfo *vi
    )
{
    Status status;
    XStandardColormap *standardCmaps;
    Colormap cmap;
    int i, numCmaps;

    status = XmuLookupStandardColormap(_dpy,
                                       vi->screen,
                                       vi->visualid,
                                       vi->depth,
                                       XA_RGB_DEFAULT_MAP,
                                       False,
                                       True);
    if (status == 1) {
        status = XGetRGBColormaps(_dpy,
                                  RootWindow(_dpy, vi->screen),
                                  &standardCmaps,
                                  &numCmaps,
                                  XA_RGB_DEFAULT_MAP);
        if (status == 1) {
            for (i = 0; i < numCmaps; i++) {
                if (standardCmaps[i].visualid == vi->visualid) {
                    cmap = standardCmaps[i].colormap;
                    XFree(standardCmaps);
                    return cmap;
                }
            }
        }
    }

    cmap = XCreateColormap(_dpy,
                           RootWindow(_dpy, vi->screen),
                           vi->visual,
                           AllocNone);
    return cmap;
}

///////////////////////////////////////////////////////////////////////////////
// initCallback
//
// DESCR:       Callback called by toolkit when initialized
// RETURNS:     N/A
//
void Workstation::initCallback(
    Widget w,
    XtPointer clientData,
    XtPointer callData
    )
{
    Workstation *obj = (Workstation *) clientData;
    obj->init();
}

///////////////////////////////////////////////////////////////////////////////
// exposeCallback
//
// DESCR:       Callback called by toolkit when exposed
// RETURNS:     N/A
//
void Workstation::exposeCallback(
    Widget w,
    XtPointer clientData,
    XtPointer callData
    )
{
    Workstation *obj = (Workstation *) clientData;
    obj->expose();
}


#ifdef TEST
#include <phigs/phg.h>

void initStructs()
{
   Ppoint quad_pts[4] = {
      {0.0, 0.0},
      {0.5, 0.0},
      {0.5, 0.5},
      {0.0, 0.5}
   };
   Ppoint_list quad = {4, quad_pts};
   Pgcolr blue;

   blue.type = PMODEL_RGB;
   blue.val.general.x = 0.0;
   blue.val.general.y = 0.0;
   blue.val.general.z = 1.0;

   popen_struct(0);
   pset_int_colr(&blue);
   pfill_area(&quad);
   pclose_struct();
}

int main(int argc, char *argv[])
{
    Widget toplevel;
    XtAppContext app;

    popen_phigs(NULL, 0);
    initStructs();

    toplevel = XtVaAppInitialize(
        &app,                  /* Application context */
        "Revolver",            /* Application name */
        NULL, 0,               /* Command line options list */
        &argc, argv,           /* Command line args */
        NULL,                  /* Fallback resources */
        NULL);

    Workstation *ws = new Workstation("ws", toplevel);

    std::cout << "Class name: " << ws->className() << std::endl;
    std::cout << "Object name: " << ws->name() << std::endl;

    ws->show();

    XtRealizeWidget(toplevel);
    XtAppMainLoop(app);

    return 0;
}
#endif

