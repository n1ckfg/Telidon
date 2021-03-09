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

#ifndef _VkMenu_H
#define _VkMenu_H

#include <Vk/VkComponentList.h>
#include <Vk/VkMenuItem.h>

class VkSubMenu;

struct VkMenuDesc {
    VkMenuItemType  menuType;
    char           *name;
    XtCallbackProc  callback;
    VkMenuDesc     *submenu;
    XtPointer       clientData;
};

class VkMenu : public VkMenuItem {
public:

    ///////////////////////////////////////////////////////////////////////////
    // ~VkMenu
    //
    // DESCR:       Free resources
    // RETURNS:     N/A
    //
    virtual ~VkMenu();

    ///////////////////////////////////////////////////////////////////////////
    // build
    //
    // DESCR:       Build menu
    // RETURNS:     N/A
    //
    virtual void build(
        Widget parent
        );

    ///////////////////////////////////////////////////////////////////////////
    // add
    //
    // DESCR:       Add entry to the menu
    // RETURNS:     N/A
    //
    void add(
        VkMenuItem *item,
        int pos = -1
        );

    ///////////////////////////////////////////////////////////////////////////
    // addSubmenu
    //
    // DESCR:       Create a submenu entry on the menu
    // RETURNS:     Pointer to submenu
    //
    VkSubMenu* addSubmenu(
        const char *name,
        int pos = -1
        );

    ///////////////////////////////////////////////////////////////////////////
    // addSubmenu
    //
    // DESCR:       Add a submenu entry on the menu
    // RETURNS:     Pointer to submenu
    //
    VkSubMenu* addSubmenu(
        VkSubMenu *submenu,
        int pos = -1
        );

    ///////////////////////////////////////////////////////////////////////////
    // addSubmenu
    //
    // DESCR:       Create a submenu entry on the menu
    // RETURNS:     Pointer to submenu
    //
    VkSubMenu* addSubmenu(
        const char *name,
        VkMenuDesc *menuDesc,
        XtPointer defaultClientData = NULL,
        int pos = -1
        );

    ///////////////////////////////////////////////////////////////////////////
    // addAction
    //
    // DESCR:       Create an action entry on the menu
    // RETURNS:     Pointer to action entry
    //
    VkMenuAction* addAction(
        const char *name,
        XtCallbackProc func = NULL,
        XtPointer data = NULL,
        int pos = -1
        );

protected:

    // Various fields
    VkComponentList _contents;

    ///////////////////////////////////////////////////////////////////////////
    // VkMenu
    //
    // DESCR:       Create new menu
    // RETURNS:     N/A
    //
    VkMenu(
        const char *name
        );

private:

    ///////////////////////////////////////////////////////////////////////////
    // handleMenuDescriptor
    //
    // DESCR:       Handle menu descriptor record, used for static definition
    // RETURNS:     N/A
    //
    void handleMenuDescriptor(
        VkMenuDesc *menuDesc,
        XtPointer defaultClientData
        );
};

#endif

