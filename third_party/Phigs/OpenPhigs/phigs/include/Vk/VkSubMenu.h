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

#ifndef _VkSubMenu_H
#define _VkSubMenu_H

#include <Vk/VkMenu.h>

class VkSubMenu : public VkMenu {

    friend class VkMenuItem;

public:

    ///////////////////////////////////////////////////////////////////////////
    // VkSubMenu
    //
    // DESCR:       Create new sub menu
    // RETURNS:     N/A
    //
    VkSubMenu(
        const char *name,
        VkMenuDesc *desc = NULL,
        XtPointer defaultClientData = NULL
        );

    ///////////////////////////////////////////////////////////////////////////
    // ~VkSubMenu
    //
    // DESCR:       Free resources
    // RETURNS:     N/A
    //
    virtual ~VkSubMenu();

    ///////////////////////////////////////////////////////////////////////////
    // showTearOff
    //
    // DESCR:       Set tear off flag
    // RETURNS:     N/A
    //
    void showTearOff(
        Boolean showit
        );

    ///////////////////////////////////////////////////////////////////////////
    // pulldown
    //
    // DESCR:       Get pulldown menu widget
    // RETURNS:     Pulldown widget
    //
    Widget pulldown() { return _pulldown; }

    ///////////////////////////////////////////////////////////////////////////
    // menuType
    //
    // DESCR:       Get menu item type
    // RETURNS:     Menu item type
    //
    virtual VkMenuItemType menuType();

    ///////////////////////////////////////////////////////////////////////////
    // className
    //
    // DESCR:       Get class name
    // RETURNS:     Class name
    //
    virtual const char* className();

protected:

    // Various fields
    Widget _pulldown;
    int _showTearOff;

    ///////////////////////////////////////////////////////////////////////////
    // build
    //
    // DESCR:       Build sub menu
    // RETURNS:     N/A
    //
    virtual void build(
        Widget parent
        );

};

#endif

