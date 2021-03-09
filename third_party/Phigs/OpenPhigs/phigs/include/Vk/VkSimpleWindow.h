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

#ifndef _VkSimpleWindow_H
#define _VkSimpleWindow_H

#include <Vk/VkComponent.h>

class VkApp;

class VkSimpleWindow : public VkComponent {

    friend class VkApp;

public:

    ///////////////////////////////////////////////////////////////////////////
    // VkSimpleWindow
    //
    // DESCR:       Create simple window
    // RETURNS:     N/A
    //
    VkSimpleWindow(
        const char *name,
        ArgList argList = NULL,
        Cardinal argCount = 0
        );

    ///////////////////////////////////////////////////////////////////////////
    // ~VkSimpleWindow
    //
    // DESCR:       Clear up resources
    // RETURNS:     N/A
    //
    virtual ~VkSimpleWindow();

    ///////////////////////////////////////////////////////////////////////////
    // addView
    //
    // DESCR:       Add view area widget to window
    // RETURNS:     N/A
    //
    void addView(
        Widget w
        );

    ///////////////////////////////////////////////////////////////////////////
    // iconify
    //
    // DESCR:       Iconify window
    // RETURNS:     N/A
    //
    virtual void iconify();

    ///////////////////////////////////////////////////////////////////////////
    // show
    //
    // DESCR:       Show window
    // RETURNS:     N/A
    //
    virtual void show();

    ///////////////////////////////////////////////////////////////////////////
    // hide
    //
    // DESCR:       Hide window
    // RETURNS:     N/A
    //
    virtual void hide();

    ///////////////////////////////////////////////////////////////////////////
    // className
    //
    // DESCR:       Get class name
    // RETURNS:     Class name
    //
    virtual const char* className();

    ///////////////////////////////////////////////////////////////////////////
    // mainWindowWidget
    //
    // DESCR:       Get main window widget
    // RETURNS:     Main window widget
    //
    virtual Widget mainWindowWidget();

protected:

    // Widget for main window container
    Widget _mainWindowWidget;

private:

    ///////////////////////////////////////////////////////////////////////////
    // VkSimpleWindowInitialize
    //
    // DESCR:       The window's real initialization code
    // RETURNS:     N/A
    //
    void VkSimpleWindowInitialize(
        const char *name,
        ArgList argList,
        Cardinal argCount
    );

    Widget _viewWidget;
};

#endif

