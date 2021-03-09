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

#ifndef _VkMenuItem_H
#define _VkMenuItem_H

#include <Vk/VkComponent.h>

class VkMenu;
class VkSubMenu;
class VkMenuBar;

enum VkMenuItemType {
    END,                // Mark the end of a static menu structure
    ACTION,             // Ordinary menu item
    SUBMENU,            // A cascading submenu
    BAR                 // Menu bar
};

class VkMenuItem : public VkComponent {

    friend class VkMenu;
    friend class VkSubMenu;
    friend class VkMenuBar;

public:

    ///////////////////////////////////////////////////////////////////////////
    // ~VkMenuItem
    //
    // DESCR:       Free resources
    // RETURNS:     N/A
    //
    virtual ~VkMenuItem();

    ///////////////////////////////////////////////////////////////////////////
    // setLabel
    //
    // DESCR:       Set text label for menu item
    // RETURNS:     N/A
    //
    virtual void setLabel(
        const char *name
        );

    ///////////////////////////////////////////////////////////////////////////
    // getLabel
    //
    // DESCR:       Get text label from menu item
    // RETURNS:     Label string
    //
    char* getLabel();

    ///////////////////////////////////////////////////////////////////////////
    // setPosition
    //
    // DESCR:       Set menu item position
    // RETURNS:     N/A
    //
    void setPosition(
        int position
        );

    ///////////////////////////////////////////////////////////////////////////
    // activate
    //
    // DESCR:       Make menu item sensitive
    // RETURNS:     N/A
    //
    void activate();

    ///////////////////////////////////////////////////////////////////////////
    // deactivate
    //
    // DESCR:       Make menu item unsensitive
    // RETURNS:     N/A
    //
    void deactivate();

    ///////////////////////////////////////////////////////////////////////////
    // remove
    //
    // DESCR:       Remove menu item
    // RETURNS:     N/A
    //
    void remove();

    ///////////////////////////////////////////////////////////////////////////
    // show
    //
    // DESCR:       Show menu item
    // RETURNS:     N/A
    //
    void show();

    ///////////////////////////////////////////////////////////////////////////
    // hide
    //
    // DESCR:       Hide menu item
    // RETURNS:     N/A
    //
    void hide();

    ///////////////////////////////////////////////////////////////////////////
    // className
    //
    // DESCR:       Get class name
    // RETURNS:     Class name
    //
    virtual const char* className();

    ///////////////////////////////////////////////////////////////////////////
    // isContainer
    //
    // DESCR:       Get if menu item is a container item
    //              Should be overriden by subclass
    // RETURNS:     TRUE or FALSE
    //
    virtual Boolean isContainer();

    ///////////////////////////////////////////////////////////////////////////
    // menuType
    //
    // DESCR:       Get menu item type
    //              Should be implemented by subclass
    // RETURNS:     Menu item type
    //
    virtual VkMenuItemType menuType() = 0;

    ///////////////////////////////////////////////////////////////////////////
    // baseWidget
    //
    // DESCR:       Get root node for the widget hierarcy
    // RETURNS:     Root widget
    Widget baseWidget() const { return _baseWidget; }

protected:

    // Various fields
    int     _position;
    Boolean _isBuilt;
    int     _sensitive;
    VkMenu *_parentMenu;
    char   *_label;
    Boolean _isHidden;

    ///////////////////////////////////////////////////////////////////////////
    // VkMenuItem
    //
    // DESCR:       Create menu item
    // RETURNS:     N/A
    //
    VkMenuItem(
        const char *name
        );

    ///////////////////////////////////////////////////////////////////////////
    // build
    //
    // DESCR:       Build menu item
    //              Should be overriden by subclass
    // RETURNS:     N/A
    //
    virtual void build(
        Widget parent
        );
};

class VkMenuAction : public VkMenuItem {
public:

    ///////////////////////////////////////////////////////////////////////////
    // VkMenuAction
    //
    // DESCR:       Create menu action item
    // RETURNS:     N/A
    //
    VkMenuAction(
        const char *name,
        XtCallbackProc func = NULL,
        XtPointer clientData = NULL
        );

    ///////////////////////////////////////////////////////////////////////////
    // ~VkMenuAction
    //
    // DESCR:       Free resources
    // RETURNS:     N/A
    //
    virtual ~VkMenuAction();

    ///////////////////////////////////////////////////////////////////////////
    // undo
    //
    // DESCR:       Undo action
    // RETURNS:     N/A
    //
    virtual void undo();

    ///////////////////////////////////////////////////////////////////////////
    // hasUndo
    //
    // DESCR:       Get if the action can be undone
    // RETURNS:     TRUE or FALSE
    //
    Boolean hasUndo() { return ((_undoCallback != NULL) ? TRUE : FALSE); }

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
    XtCallbackProc _undoCallback;
    XtCallbackProc _func;
    void          *_data;
 
    ///////////////////////////////////////////////////////////////////////////
    // build
    //
    // DESCR:       Build menu item
    // RETURNS:     N/A
    //
    virtual void build(
        Widget parent
        );
};

#endif

