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

#ifndef _VkComponent_H
#define _VkComponent_H

#include <Xm/Xm.h>

class VkComponent {
public:

    ///////////////////////////////////////////////////////////////////////////
    // ~VkComponent
    //
    // DESCR:       Destroy baseWidget and free resources
    // RETURNS:     N/A
    //
    virtual ~VkComponent();

    ///////////////////////////////////////////////////////////////////////////
    // show
    //
    // DESCR:       Display all widgets by managing to baseWidget
    //              Assumes that all child widgets have been managed
    //              by the subclass constructor
    // RETURNS:     N/A
    //
    virtual void show();

    ///////////////////////////////////////////////////////////////////////////
    // hide
    //
    // DESCR:       Hide all widgets by unmanaging to baseWidget
    // RETURNS:     N/A
    //
    virtual void hide();

    ///////////////////////////////////////////////////////////////////////////
    // manage
    //
    // DESCR:       Alias for show
    // RETURNS:     N/A
    void manage() { show(); }

    ///////////////////////////////////////////////////////////////////////////
    // unmanage
    //
    // DESCR:       Alias for hide
    // RETURNS:     N/A
    void unmanage() { hide(); }

    ///////////////////////////////////////////////////////////////////////////
    // name
    //
    // DESCR:       Get the name that was used when calling the constructor
    // RETURNS:     Instance name
    const char* name() const { return _name; }

    ///////////////////////////////////////////////////////////////////////////
    // className
    //
    // DESCR:       Get class name for the object
    //              This member function should be overriden by subclass
    // RETURNS:     Class name
    //
    virtual const char* className();

    ///////////////////////////////////////////////////////////////////////////
    // baseWidget
    //
    // DESCR:       Get root node for the widget hierarcy
    // RETURNS:     Root widget
    Widget baseWidget() const { return _baseWidget; }

protected:

    ///////////////////////////////////////////////////////////////////////////
    // installDestroyHandler
    //
    // DESCR:       Install the destroy handler callback
    //              Should be called after baseWidget widget has been created
    // RETURNS:     N/A
    //
    void installDestroyHandler();

    ///////////////////////////////////////////////////////////////////////////
    // widgetDestroyed
    //
    // DESCR:       Callback by installed callback when widget is destroyed
    //              Should be overriden by the subclass if needed
    // RETURNS:     N/A
    //
    virtual void widgetDestroyed();

    ///////////////////////////////////////////////////////////////////////////
    // setDefaultResources
    //
    // DESCR:       Set default resources that can be overriden
    // RETURNS:     N/A
    //
    void setDefaultResources(
        const Widget w,
        const String *resourceSpec
        );

    ///////////////////////////////////////////////////////////////////////////
    // getResources
    //
    // DESCR:       Retrive object specific resources relative to
    //              to the parent of the base widget
    // RETURNS:     N/A
    //
    void getResources(
        const XtResourceList resources,
        const int numResources
        );

    // Name of the instance
    char *_name;

    // Root widget
    Widget _baseWidget;

    ///////////////////////////////////////////////////////////////////////////
    // VkComponent
    //
    // DESCR:       Initialize baseWidget to NULL and set instance name
    //              Should be called by subclass constructor
    // RETURNS:     N/A
    //
    VkComponent(
        const char *name
        );

    ///////////////////////////////////////////////////////////////////////////
    // VkComponent
    //
    // DESCR:       Default constructor
    //              Should not be called directly but may be used from subclass
    // RETURNS:     N/A
    //
    VkComponent();

private:

    ///////////////////////////////////////////////////////////////////////////
    // widgetDestroyedCallback
    //
    // DESCR:       Callback called by toolkit when widget is destroyed
    // RETURNS:     N/A
    //
    static void widgetDestroyedCallback(
        Widget w,
        XtPointer clientData,
        XtPointer callData
        );
};

#endif

