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

#include <Xm/RowColumn.h>
#include <Vk/VkMenuBar.h>

///////////////////////////////////////////////////////////////////////////////
// VkMenuBar
//
// DESCR:       Create new menu bar
// RETURNS:     N/A
//
VkMenuBar::VkMenuBar(
    const char *name,
    Boolean showHelpPane
    ) :
    VkMenu(name)
{
}

///////////////////////////////////////////////////////////////////////////////
// ~VkMenuBar
//
// DESCR:       Free resources
// RETURNS:     N/A
//
VkMenuBar::~VkMenuBar()
{
}

///////////////////////////////////////////////////////////////////////////////
// build
//
// DESCR:       Build menu bar
// RETURNS:     N/A
//
void VkMenuBar::build(
    Widget parent
    )
{
    _baseWidget = XmCreateMenuBar(parent, _name, NULL, 0);

    installDestroyHandler();

    XtManageChild(_baseWidget);

    for (int i = 0; i < _contents.size(); i++) {
        ((VkMenuItem *) _contents[i])->build(_baseWidget);
    }

    // TODO: Set help pane

    XtSetSensitive(_baseWidget, _sensitive);

    _isBuilt = TRUE;
}

///////////////////////////////////////////////////////////////////////////////
// menuType
//
// DESCR:       Get menu item type
// RETURNS:     Menu item type
//
VkMenuItemType VkMenuBar::menuType()
{
    return BAR;
}

///////////////////////////////////////////////////////////////////////////////
// className
//
// DESCR:       Get class name
// RETURNS:     Class name
//
const char* VkMenuBar::className()
{
    return "VkMenuBar";
}

