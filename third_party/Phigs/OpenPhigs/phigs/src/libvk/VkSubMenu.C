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
#include <Xm/CascadeBG.h>
#include <Vk/VkSubMenu.h>

///////////////////////////////////////////////////////////////////////////////
// VkSubMenu
//
// DESCR:       Create new sub menu
// RETURNS:     N/A
//
VkSubMenu::VkSubMenu(
    const char *name,
    VkMenuDesc *desc,
    XtPointer defaultClientData
    ) :
    VkMenu(name)
{
    _showTearOff = FALSE;
}

///////////////////////////////////////////////////////////////////////////////
// ~VkSubMenu
//
// DESCR:       Free resources
// RETURNS:     N/A
//
VkSubMenu::~VkSubMenu()
{
}

///////////////////////////////////////////////////////////////////////////////
// showTearOff
//
// DESCR:       Set tear off flag
// RETURNS:     N/A
//
void VkSubMenu::showTearOff(
    Boolean showit
    )
{
    if (_isBuilt) {
        XtVaSetValues(_pulldown,
                      XmNtearOffModel,
                      showit ? XmTEAR_OFF_ENABLED : XmTEAR_OFF_DISABLED,
                      NULL);
    }
    _showTearOff = showit;
}

///////////////////////////////////////////////////////////////////////////////
// menuType
//
// DESCR:       Get menu item type
// RETURNS:     Menu item type
//
VkMenuItemType VkSubMenu::menuType()
{
    return SUBMENU;
}

///////////////////////////////////////////////////////////////////////////////
// className
//
// DESCR:       Get class name
// RETURNS:     Class name
//
const char* VkSubMenu::className()
{
    return "VkSubMenu";
}

///////////////////////////////////////////////////////////////////////////////
// build
//
// DESCR:       Build sub menu
// RETURNS:     N/A
//
void VkSubMenu::build(
    Widget parent
    )
{
    Arg args[4];
    Cardinal n = 0;

    XtSetArg(args[n], XmNtearOffModel,
             _showTearOff ? XmTEAR_OFF_ENABLED : XmTEAR_OFF_DISABLED); n++;
    XtSetArg(args[n], XmNpositionIndex,
             _position == -1 ? XmLAST_POSITION : _position); n++;

    // Create pulldown pane
    _pulldown = XmCreatePulldownMenu(parent,
                                     _name,
                                     args, n);

    n = 0;
    XtSetArg(args[n], XmNsubMenuId, _pulldown); n++;

    // Create cascade button gadget
    _baseWidget = XmCreateCascadeButtonGadget(parent,
                                              _name,
                                              args, n);

    installDestroyHandler();

    XtManageChild(_baseWidget);

    for (int i = 0; i < _contents.size(); i++) {
        ((VkMenuItem *) _contents[i])->build(_pulldown);
    }

    XtSetSensitive(_baseWidget, _sensitive);

   _isBuilt = TRUE;
}

