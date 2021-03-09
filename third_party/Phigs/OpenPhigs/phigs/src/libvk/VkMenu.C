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

#include <assert.h>
#include <Vk/VkMenu.h>
#include <Vk/VkSubMenu.h>

///////////////////////////////////////////////////////////////////////////////
// ~VkMenu
//
// DESCR:       Free resources
// RETURNS:     N/A
//
VkMenu::~VkMenu()
{
    for (int i = 0; i < _contents.size(); i++) {
        delete _contents[i];
    }
}

///////////////////////////////////////////////////////////////////////////////
// build
//
// DESCR:       Build menu
// RETURNS:     N/A
//
void VkMenu::build(
    Widget parent
    )
{
    VkMenuItem::build(parent);
}

///////////////////////////////////////////////////////////////////////////////
// add
//
// DESCR:       Add entry to the menu
// RETURNS:     N/A
//
void VkMenu::add(
    VkMenuItem *item,
    int pos
    )
{
    if (pos == -1) {
        // Place the item at the end of the array
        _contents.add(item);
    }
    // TODO: Other position

    item->_position = pos;
    item->_parentMenu = this;

    if (_isBuilt) {

        switch(menuType()) {
            case SUBMENU:
                item->build(((VkSubMenu *) this)->pulldown());
                break;

            default:
                item->build(baseWidget());
                break;
        }

    }
}

///////////////////////////////////////////////////////////////////////////////
// addAction
//
// DESCR:       Create an action entry on the menu
// RETURNS:     Pointer to action entry
//
VkMenuAction* VkMenu::addAction(
    const char *name,
    XtCallbackProc func,
    XtPointer data,
    int pos
    )
{
    VkMenuAction *action = new VkMenuAction(name, func, data);
    add(action, pos);

    return action;
}

///////////////////////////////////////////////////////////////////////////////
// addSubmenu
//
// DESCR:       Create a submenu entry on the menu
// RETURNS:     Pointer to submenu
//
VkSubMenu* VkMenu::addSubmenu(
    const char *name,
    int pos
    )
{
    VkSubMenu *submenu = new VkSubMenu(name);
    add(submenu, pos);

    return submenu;
}

///////////////////////////////////////////////////////////////////////////////
// addSubmenu
//
// DESCR:       Add a submenu entry on the menu
// RETURNS:     Pointer to submenu
//
VkSubMenu* VkMenu::addSubmenu(
    VkSubMenu *submenu,
    int pos
    )
{
    add(submenu, pos);

    return submenu;
}

///////////////////////////////////////////////////////////////////////////////
// addSubmenu
//
// DESCR:       Create a submenu entry on the menu
// RETURNS:     Pointer to submenu
//
VkSubMenu* VkMenu::addSubmenu(
    const char *name,
    VkMenuDesc *menuDesc,
    XtPointer defaultClientData,
    int pos
    )
{
    VkSubMenu *submenu = new VkSubMenu(name);
    add(submenu, pos);
    submenu->handleMenuDescriptor(menuDesc, defaultClientData);

    return submenu;
}

///////////////////////////////////////////////////////////////////////////////
// VkMenu
//
// DESCR:       Create new menu
// RETURNS:     N/A
//
VkMenu::VkMenu(
    const char *name
    ) :
    VkMenuItem(name)
{
}

///////////////////////////////////////////////////////////////////////////////
// handleMenuDescriptor
//
// DESCR:       Handle menu descriptor record, used for static definition 
// RETURNS:     N/A
//
void VkMenu::handleMenuDescriptor(
    VkMenuDesc *menuDesc,
    XtPointer defaultClientData
    )
{
    VkMenuDesc *curr;

    assert(menuDesc != NULL);

    for (curr = menuDesc; curr->menuType != END; curr++) {

        switch(curr->menuType) {
            case ACTION:
                addAction(curr->name,
                          curr->callback,
                          curr->clientData == NULL ?
                              curr->clientData : defaultClientData);
                break;

            case SUBMENU:
                addSubmenu(curr->name,
                           curr->submenu,
                          curr->clientData == NULL ?
                              curr->clientData : defaultClientData);
                break;

            default:
                break;
        }

    }
}

