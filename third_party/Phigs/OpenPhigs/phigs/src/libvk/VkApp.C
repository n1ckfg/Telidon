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

#include <Vk/VkApp.h>
#include <Vk/VkSimpleWindow.h>

VkApp *theApplication = NULL;

///////////////////////////////////////////////////////////////////////////////
// VkApp
//
// DESCR:       Normal constructor -- most apps should use this one
// RETURNS:     N/A
//
VkApp::VkApp(
    char *appClassName,
    int *arg_c,
    char **arg_v,
    XrmOptionDescRec *optionList,
    int sizeOfOptionList
    ) :
    VkComponent(arg_v[0])
{
    VkAppInitialize(appClassName,
                    arg_c, arg_v,
                    NULL, 0,
                    NULL,
                    optionList, sizeOfOptionList);
}

///////////////////////////////////////////////////////////////////////////////
// ~VkApp
//
// DESCR:       Clear up resources
// RETURNS:     N/A
//
VkApp::~VkApp()
{
    XtFree(_applicationClassName);
}

///////////////////////////////////////////////////////////////////////////////
// run
//
// DESCR:       Run application by entering event loop
// RETURNS:     N/A
//
void VkApp::run()
{
    // Enter toolkit main loop
    XtAppMainLoop(_appContext);
}

///////////////////////////////////////////////////////////////////////////////
// iconify
//
// DESCR:       Iconify all the application windows
// RETURNS:     N/A
//
void VkApp::iconify()
{
    VkSimpleWindow *window;

    // Iconify all windows
    for (int i = 0; i < _winList.size(); i++) {
        window = (VkSimpleWindow *) _winList[i];
        window->iconify();
    }
}

///////////////////////////////////////////////////////////////////////////////
// show
//
// DESCR:       Show all the application windows
// RETURNS:     N/A
//
void VkApp::show()
{
    // Manage all windows
    for (int i = 0; i < _winList.size(); i++) {
        _winList[i]->show();
    }
}

///////////////////////////////////////////////////////////////////////////////
// hide
//
// DESCR:       Hide all the application windows
// RETURNS:     N/A
//
void VkApp::hide()
{
    // Unmanage all windows
    for (int i = 0; i < _winList.size(); i++) {
        _winList[i]->hide();
    }
}

///////////////////////////////////////////////////////////////////////////////
// className
//
// DESCR:       Get class name
// RETURNS:     Class name
//
const char* VkApp::className()
{
    return "VkApp";
}

///////////////////////////////////////////////////////////////////////////////
// VkAppInitialize
//
// DESCR:       Constructor's real initialization function
// RETURNS:     N/A
//
void VkApp::VkAppInitialize(
    char *appClassName,
    int *arg_c,
    char **arg_v,
    ArgList argList,
    Cardinal argCount,
    void (*preRealizeFunction)(Widget w),
    XrmOptionDescRec *optionList,
    int sizeOfOptionList
    )
{
    // Setup the global VkApp pointer
    theApplication = this;

    // Store application class name
    _applicationClassName = XtNewString(appClassName);

    // Initialize toolkit
    _baseWidget = XtAppInitialize(&_appContext,
                                  _applicationClassName,
                                  optionList, (Cardinal) sizeOfOptionList,
                                  arg_c, arg_v,
                                  NULL, /* Fallback resources */
                                  argList, argCount);

    // Store arglist and number of arguments
    _argv = arg_v;
    _argc = *arg_c;

    // Store display connection
    _dpy = XtDisplay(_baseWidget);

    // The app class is less likely to need to handle
    // special destroy cases, but install handler for safety
    installDestroyHandler();

    // Center the shell, and make sure it is not visible
    XtVaSetValues(_baseWidget,
                  XmNmappedWhenManaged, FALSE,
                  XmNx, DisplayWidth(_dpy, 0) / 2,
                  XmNx, DisplayHeight(_dpy, 0) / 2,
                  XmNwidth, 1,
                  XmNheight, 1,
                  NULL);

    // Realize toplevel widget
    XtRealizeWidget(_baseWidget);
}

///////////////////////////////////////////////////////////////////////////////
// addWindow
//
// DESCR:       Add window to the application
// RETURNS:     N/A
//
void VkApp::addWindow(
    VkSimpleWindow *window
    )
{
    _winList.add((VkComponent *) window);
}

///////////////////////////////////////////////////////////////////////////////
// removeWindow
//
// DESCR:       Remove window from the application
// RETURNS:     N/A
//
void VkApp::removeWindow(
    VkSimpleWindow *window
    )
{
    _winList.remove((VkComponent *) window);
}

