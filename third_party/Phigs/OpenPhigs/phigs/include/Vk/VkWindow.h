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

#ifndef _VkWindow_H
#define _VkWindow_H

#include <Vk/VkSimpleWindow.h>
#include <Vk/VkMenuBar.h>

class VkWindow : public VkSimpleWindow {
public:

    ///////////////////////////////////////////////////////////////////////////
    // VkWindow
    //
    // DESCR:       Create window
    // RETURNS:     N/A
    //
    VkWindow(
        const char *name,
        ArgList argList = NULL,
        Cardinal argCount = 0
        );

    ///////////////////////////////////////////////////////////////////////////
    // ~VkWindow
    //
    // DESCR:       Clear up resources
    // RETURNS:     N/A
    //
    virtual ~VkWindow();

    ///////////////////////////////////////////////////////////////////////////
    // show
    //
    // DESCR:       Show window
    // RETURNS:     N/A
    //
    virtual void show();

    ///////////////////////////////////////////////////////////////////////////
    // setMenuBar
    //
    // DESCR:       Set menu bar for window
    // RETURNS:     N/A
    //
    void setMenuBar(
        VkMenuBar *menuObj
        );

    ///////////////////////////////////////////////////////////////////////////
    // className
    //
    // DESCR:       Get class name
    // RETURNS:     Class name
    //
    virtual const char* className();

private:

    VkMenuBar *_menu;
};

#endif

