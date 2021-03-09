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
#include <Xm/MainW.h>
#include <Vk/VkApp.h>
#include <Vk/VkSimpleWindow.h>

///////////////////////////////////////////////////////////////////////////////
// VkSimpleWindow
//
// DESCR:       Create simple window
// RETURNS:     N/A
//
VkSimpleWindow::VkSimpleWindow(
    const char *name,
    ArgList argList,
    Cardinal argCount
    ) :
    VkComponent(name)
{
    _viewWidget = NULL;

    // The application must exists first
    assert(theApplication != NULL);

    // Initialize window
    VkSimpleWindowInitialize(name, argList, argCount);

    // Add this window to the application
    theApplication->addWindow(this);
}

///////////////////////////////////////////////////////////////////////////////
// ~VkSimpleWindow
//
// DESCR:       Clear up resources
// RETURNS:     N/A
//
VkSimpleWindow::~VkSimpleWindow()
{
    theApplication->removeWindow(this);
}

///////////////////////////////////////////////////////////////////////////////
// addView
//
// DESCR:       Add view area widget to window
// RETURNS:     N/A
//
void VkSimpleWindow::addView(
    Widget w
    )
{
    _viewWidget = w;

    // Set as main window
    XtVaSetValues(_mainWindowWidget,
                  XmNworkWindow, _viewWidget,
                  NULL);

    // Manage the view if not done before
    if (!XtIsManaged(_viewWidget)) {
        XtManageChild(_viewWidget);
    }
}

///////////////////////////////////////////////////////////////////////////////
// iconify
//
// DESCR:       Iconify window
// RETURNS:     N/A
//
void VkSimpleWindow::iconify()
{
    assert(_baseWidget != NULL);

    // Set widget to have an initial iconic state
    // in case it has not been realized already
    XtVaSetValues(_baseWidget,
                  XmNiconic, TRUE,
                  NULL);

    // If the widget alredy has been realized, iconify it
    if (XtIsRealized(_baseWidget)) {
        XIconifyWindow(theApplication->display(), XtWindow(_baseWidget), 0);
    }
}

///////////////////////////////////////////////////////////////////////////////
// show
//
// DESCR:       Show window
// RETURNS:     N/A
//
void VkSimpleWindow::show()
{
    assert(_baseWidget != NULL);
    XtPopup(_baseWidget, XtGrabNone);

    // Map the window, in case if it is iconified
    if (XtIsRealized(_baseWidget)) {
        XMapRaised(theApplication->display(), XtWindow(_baseWidget));
    }
}

///////////////////////////////////////////////////////////////////////////////
// hide
//
// DESCR:       Hide window
// RETURNS:     N/A
//
void VkSimpleWindow::hide()
{
    assert(_baseWidget != NULL);
    XtPopdown(_baseWidget);
}

///////////////////////////////////////////////////////////////////////////////
// className
//
// DESCR:       Get class name
// RETURNS:     Class name
//
const char* VkSimpleWindow::className()
{
    return "VkSimpleWindow";
}

///////////////////////////////////////////////////////////////////////////////
// mainWindowWidget
//
// DESCR:       Get main window widget
// RETURNS:     Main window widget
//
Widget VkSimpleWindow::mainWindowWidget()
{
    return _mainWindowWidget;
}

///////////////////////////////////////////////////////////////////////////////
// VkSimpleWindowInitialize
//
// DESCR:       The window's real initialization code
// RETURNS:     N/A
//
void VkSimpleWindow::VkSimpleWindowInitialize(
    const char *name,
    ArgList argList,
    Cardinal argCount
    )

{
    // Create a popup shell for window
    _baseWidget = XtCreatePopupShell(name,
                                     applicationShellWidgetClass,
                                     theApplication->baseWidget(),
                                     argList, argCount);

    installDestroyHandler();

    // Create a main window container
    _mainWindowWidget = XtCreateManagedWidget("mainWindow",
                                              xmMainWindowWidgetClass,
                                              _baseWidget,
                                              argList, argCount);
}

