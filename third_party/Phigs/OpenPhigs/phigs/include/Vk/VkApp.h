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

#ifndef _VkApp_H
#define _VkApp_H

#include <X11/Xlib.h>
#include <Vk/VkComponent.h>
#include <Vk/VkComponentList.h>

class VkApp;
class VkSimpleWindow;

extern VkApp *theApplication;

class VkApp : public VkComponent {

    friend class VkSimpleWindow;

public:

    ///////////////////////////////////////////////////////////////////////////
    // VkApp
    //
    // DESCR:       Normal constructor -- most apps should use this one
    // RETURNS:     N/A
    //
    VkApp(
        char *appClassName,
        int *arg_c,
        char **arg_v,
        XrmOptionDescRec *optionList = NULL,
        int sizeOfOptionList = 0
        );

    ///////////////////////////////////////////////////////////////////////////
    // ~VkApp
    //
    // DESCR:       Clear up resources
    // RETURNS:     N/A
    //
    virtual ~VkApp();

    ///////////////////////////////////////////////////////////////////////////
    // run
    //
    // DESCR:       Run application by entering event loop
    // RETURNS:     N/A
    //
    virtual void run();

    ///////////////////////////////////////////////////////////////////////////
    // iconify
    //
    // DESCR:       Iconify all the application windows
    // RETURNS:     N/A
    //
    virtual void iconify();

    ///////////////////////////////////////////////////////////////////////////
    // show
    //
    // DESCR:       Show all the application windows
    // RETURNS:     N/A
    //
    virtual void show();

    ///////////////////////////////////////////////////////////////////////////
    // hide
    //
    // DESCR:       Hide all the application windows
    // RETURNS:     N/A
    //
    virtual void hide();

    ///////////////////////////////////////////////////////////////////////////
    // display
    //
    // DESCR:       Get display connection for application
    // RETURNS:     Display connection
    //
    virtual Display* display() { return _dpy; }

    ///////////////////////////////////////////////////////////////////////////
    // className
    //
    // DESCR:       Get class name
    // RETURNS:     Class name
    //
    virtual const char* className();

protected:

    // List of application windows
    VkComponentList _winList;

private:

    ///////////////////////////////////////////////////////////////////////////
    // VkAppInitialize
    //
    // DESCR:       Constructor's real initialization function
    // RETURNS:     N/A
    //
    void VkAppInitialize(
        char *appClassName,
        int *arg_c,
        char **arg_v,
        ArgList argList,
        Cardinal argCount,
        void (*preRealizeFunction)(Widget w),
        XrmOptionDescRec *optionList,
        int sizeOfOptionList
        );

    // Various data fields needed by an application
    char          **_argv;
    int             _argc;
    Display        *_dpy;
    XtAppContext    _appContext;
    char           *_applicationClassName;

    ///////////////////////////////////////////////////////////////////////////
    // addWindow
    //
    // DESCR:       Add window to the application
    // RETURNS:     N/A
    //
    void addWindow(
        VkSimpleWindow *window
        );

    ///////////////////////////////////////////////////////////////////////////
    // removeWindow
    //
    // DESCR:       Remove window from the application
    // RETURNS:     N/A
    //
    void removeWindow(
        VkSimpleWindow *window
        );
};

#endif

