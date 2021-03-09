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

#include <Xm/PushBG.h>
#include <Vk/VkMenuItem.h>

///////////////////////////////////////////////////////////////////////////////
// VkMenuAction
//
// DESCR:       Create menu action item
// RETURNS:     N/A
//
VkMenuAction::VkMenuAction(
    const char *name,
    XtCallbackProc func,
    XtPointer clientData
    ) :
    VkMenuItem(name)
{
    _func = func;
    _data = clientData;
}

///////////////////////////////////////////////////////////////////////////////
// ~VkMenuAction
//
// DESCR:       Free resources
// RETURNS:     N/A
//
VkMenuAction::~VkMenuAction()
{
    if (_isBuilt) {
        XtRemoveAllCallbacks(_baseWidget, XmNactivateCallback);
    }
}

///////////////////////////////////////////////////////////////////////////////
// undo
//
// DESCR:       Undo action
// RETURNS:     N/A
//
void VkMenuAction::undo()
{
    if (_undoCallback != NULL) {
        (*_undoCallback)(_baseWidget, _data, 0);
    }
}

///////////////////////////////////////////////////////////////////////////////
// menuType
//
// DESCR:       Get menu item type
// RETURNS:     Menu item type
//
VkMenuItemType VkMenuAction::menuType()
{
    return ACTION;
}

///////////////////////////////////////////////////////////////////////////////
// className
//
// DESCR:       Get class name
// RETURNS:     Class name
//
const char* VkMenuAction::className()
{
    return "VkMenuAction";
}

///////////////////////////////////////////////////////////////////////////////
// build
//
// DESCR:       Build menu item
// RETURNS:     N/A
//
void VkMenuAction::build(
    Widget parent
    )
{
    Arg args[2];
    Cardinal n = 0;

    XtSetArg(args[n], XmNpositionIndex,
             _position == -1 ? XmLAST_POSITION : _position); n++;

    // Create push button widget
    _baseWidget = XmCreatePushButtonGadget(parent,
                                           _name,
                                           args, n);

    installDestroyHandler();

    if (_func != NULL) {
        XtAddCallback(_baseWidget,
                      XmNactivateCallback,
                      _func,
                      (XtPointer) this);
    }

    XtManageChild(_baseWidget);

    // Set sensitivity
    XtSetSensitive(_baseWidget, _sensitive);

    VkMenuItem::build(parent);
}

