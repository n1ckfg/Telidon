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

#include <stdio.h>
#include <assert.h>
#include <Vk/VkComponent.h>

///////////////////////////////////////////////////////////////////////////////
// ~VkComponent
//
// DESCR:       Destroy baseWidget and free resources
// RETURNS:     N/A
//
VkComponent::~VkComponent()
{
    if (_baseWidget != NULL) {
        XtDestroyWidget(_baseWidget);
    }

    XtFree(_name);
}

///////////////////////////////////////////////////////////////////////////////
// show
//
// DESCR:       Display all widgets by managing to baseWidget
//              Assumes that all child widgets have been managed
//              by the subclass constructor
// RETURNS:     N/A
//
void VkComponent::show()
{
    assert(_baseWidget != NULL);
    XtManageChild(_baseWidget);
}

///////////////////////////////////////////////////////////////////////////////
// hide
//
// DESCR:       Hide all widgets by unmanaging to baseWidget
// RETURNS:     N/A
//
void VkComponent::hide()
{
    assert(_baseWidget != NULL);
    XtUnmanageChild(_baseWidget);
}

///////////////////////////////////////////////////////////////////////////////
// className
//
// DESCR:       Get class name for the object
//              This member function should be overriden by subclass
// RETURNS:     Class name
//
const char* VkComponent::className()
{
    return "VkComponent";
}

///////////////////////////////////////////////////////////////////////////////
// installDestroyHandler
//
// DESCR:       Install the destroy handler callback
//              Should be called after baseWidget widget has been created
// RETURNS:     N/A
//
void VkComponent::installDestroyHandler()
{
    assert(_baseWidget != NULL);
    XtAddCallback(_baseWidget,
                  XmNdestroyCallback,
                  VkComponent::widgetDestroyedCallback,
                  (XtPointer) this);
}

///////////////////////////////////////////////////////////////////////////////
// widgetDestroyed
//
// DESCR:       Callback by installed callback when widget is destroyed
//              Should be overriden by the subclass if needed
// RETURNS:     N/A
//
void VkComponent::widgetDestroyed()
{
    _baseWidget = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// setDefaultResources
//
// DESCR:       Set default resources that can be overriden
// RETURNS:     N/A
//
void VkComponent::setDefaultResources(
    const Widget w,
    const String *resourceSpec
    )
{
    static char buf[1000];
    int i;
    Display *dpy = XtDisplay(_baseWidget);
    XrmDatabase rdb = NULL;

    // Create empty resource database
    rdb = XrmGetStringDatabase("");

    // Add component resources, prepending the name of the component
    i = 0;
    while (resourceSpec[i] != NULL) {
        sprintf(buf, "*%s%s", _name, resourceSpec[i++]);
        XrmPutLineResource(&rdb, buf);
    }

    // Merge resources into resource database with lowest precedence
    if (rdb != NULL) {
        XrmDatabase db = XtDatabase(dpy);
        XrmCombineDatabase(rdb, &db, FALSE);
    }
}

///////////////////////////////////////////////////////////////////////////////
// getResources
//
// DESCR:       Retrive object specific resources relative to
//              to the parent of the base widget
// RETURNS:     N/A
//
void VkComponent::getResources(
    const XtResourceList resources,
    const int numResources
    )
{
    assert(_baseWidget != NULL);
    assert(resources != NULL);

    // Retreive the requested resources relative to the parent
    // of the object base widget
    XtGetSubresources(XtParent(_baseWidget), (XtPointer) this,
                      _name, className(),
                      resources, numResources,
                      NULL, 0);
}

///////////////////////////////////////////////////////////////////////////////
// VkComponent
//
// DESCR:       Initialize baseWidget to NULL and set instance name
//              Should be called by subclass constructor
// RETURNS:     N/A
//
VkComponent::VkComponent(
    const char *name
    )
{
    _baseWidget = NULL;
    assert(name != NULL);
    _name = XtNewString(name);
}

///////////////////////////////////////////////////////////////////////////////
// VkComponent
//
// DESCR:       Default constructor
//              Should not be called directly but may be used from subclass
// RETURNS:     N/A
//
VkComponent::VkComponent()
{
    _baseWidget = NULL;
    _name = XtNewString("");
}

///////////////////////////////////////////////////////////////////////////////
// widgetDestroyedCallback
//
// DESCR:       Callback called by toolkit when widget is destroyed
// RETURNS:     N/A
//
void VkComponent::widgetDestroyedCallback(
    Widget w,
    XtPointer clientData,
    XtPointer callData
    )
{
    VkComponent *obj = (VkComponent *) clientData;
    obj->widgetDestroyed();
}

