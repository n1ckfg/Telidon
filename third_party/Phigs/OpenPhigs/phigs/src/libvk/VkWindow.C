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

#include <Vk/VkWindow.h>

///////////////////////////////////////////////////////////////////////////////
// VkWindow
//
// DESCR:       Create window
// RETURNS:     N/A
//
VkWindow::VkWindow(
    const char *name,
    ArgList argList,
    Cardinal argCount
    ) :
    VkSimpleWindow(name, argList, argCount)
{
    _menu = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// ~VkWindow
//
// DESCR:       Clear up resources
// RETURNS:     N/A
//
VkWindow::~VkWindow()
{
    delete _menu;
}

///////////////////////////////////////////////////////////////////////////////
// show
//
// DESCR:       Show window
// RETURNS:     N/A
//
void VkWindow::show()
{
    VkSimpleWindow::show();
}

///////////////////////////////////////////////////////////////////////////////
// setMenuBar
//
// DESCR:       Set menu bar for window
// RETURNS:     N/A
//
void VkWindow::setMenuBar(
    VkMenuBar *menuObj
    )
{
    _menu = menuObj;
}

///////////////////////////////////////////////////////////////////////////////
// className
//
// DESCR:       Get class name
// RETURNS:     Class name
//
const char* VkWindow::className()
{
    return "VkWindow";
}

