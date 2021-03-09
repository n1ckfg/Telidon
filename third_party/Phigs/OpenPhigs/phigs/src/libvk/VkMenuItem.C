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

#include <Vk/VkMenuItem.h>

///////////////////////////////////////////////////////////////////////////////
// ~VkMenuItem
//
// DESCR:       Free resources
// RETURNS:     N/A
//
VkMenuItem::~VkMenuItem()
{
    if (_label != NULL) {
        XtFree(_label);
    }
}

///////////////////////////////////////////////////////////////////////////////
// setLabel
//
// DESCR:       Set text label for menu item
// RETURNS:     N/A
//
void VkMenuItem::setLabel(
    const char *name
    )
{
}

///////////////////////////////////////////////////////////////////////////////
// getLabel
//
// DESCR:       Get text label from menu item
// RETURNS:     Label string
//
char* VkMenuItem::getLabel()
{
    return NULL;
}

///////////////////////////////////////////////////////////////////////////////
// setPosition
//
// DESCR:       Set menu item position
// RETURNS:     N/A
//
void VkMenuItem::setPosition(
    int position
    )
{
    _position = position;
}

///////////////////////////////////////////////////////////////////////////////
// activate
//
// DESCR:       Make menu item sensitive
// RETURNS:     N/A
//
void VkMenuItem::activate()
{
    _sensitive = True;
    if (_isBuilt) {
        XtSetSensitive(_baseWidget, True);
    }
}

///////////////////////////////////////////////////////////////////////////////
// deactivate
//
// DESCR:       Make menu item unsensitive
// RETURNS:     N/A
//
void VkMenuItem::deactivate()
{
    _sensitive = False;
    if (_isBuilt) {
        XtSetSensitive(_baseWidget, False);
    }
}

///////////////////////////////////////////////////////////////////////////////
// remove
//
// DESCR:       Remove menu item
// RETURNS:     N/A
//
void VkMenuItem::remove()
{
}

///////////////////////////////////////////////////////////////////////////////
// show
//
// DESCR:       Show menu item
// RETURNS:     N/A
//
void VkMenuItem::show()
{
}

///////////////////////////////////////////////////////////////////////////////
// hide
//
// DESCR:       Hide menu item
// RETURNS:     N/A
//
void VkMenuItem::hide()
{
}

///////////////////////////////////////////////////////////////////////////////
// className
//
// DESCR:       Get class name
// RETURNS:     Class name
//
const char* VkMenuItem::className()
{
    return "VkMenuItem";
}

///////////////////////////////////////////////////////////////////////////
// isContainer
//
// DESCR:       Get if menu item is a container item
//              Should be overriden by subclass
// RETURNS:     TRUE or FALSE
//
Boolean VkMenuItem::isContainer()
{
    return FALSE;
}

///////////////////////////////////////////////////////////////////////////////
// VkMenuItem
//
// DESCR:       Create menu item 
// RETURNS:     N/A
//
VkMenuItem::VkMenuItem(
    const char *name
    ) :
    VkComponent(name)
{
    _position = -1;
    _isBuilt = FALSE;
    _isHidden = FALSE;
    _sensitive = True;
    _parentMenu = NULL;
    _label = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// build
//
// DESCR:       Build menu item
//              Should be overriden by subclass
// RETURNS:     N/A
//
void VkMenuItem::build(
    Widget parent
    )
{
    _isBuilt = TRUE;
}

