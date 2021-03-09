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

#include <iostream>
#include <stdlib.h>
#include <phigs/phg.h>
#include <Vk/VkApp.h>
#include <Vk/VkWindow.h>
#include <Vk/VkSubMenu.h>
#include <Vk/VkMenuBar.h>
#include <Vk/VkSubMenu.h>
#include "Workstation.h"

void initStructs()
{
   Ppoint quad_pts[4] = {
      {0.0, 0.0},
      {0.5, 0.0},
      {0.5, 0.5},
      {0.0, 0.5}
   };
   Ppoint_list quad = {4, quad_pts};
   Pgcolr blue;

   blue.type = PMODEL_RGB;
   blue.val.general.x = 0.0;
   blue.val.general.y = 0.0;
   blue.val.general.z = 1.0;

   popen_struct(0);
   pset_int_colr(&blue);
   pfill_area(&quad);
   pclose_struct();
}

void quitCallback(Widget w, XtPointer callData, XtPointer clientData)
{
   exit(0);
}

int main(int argc, char *argv[])
{
    popen_phigs(NULL, 0);
    initStructs();

    // Create application
    VkApp *app = new VkApp("Revolver", &argc, argv);
    std::cout << "Application class name: " << app->className() << std::endl;
    std::cout << "Application instance name: " << app->name() << std::endl;
    std::cout << std::endl;

    // Create main window
    VkWindow *mainWindow = new VkWindow("Revolver");
    std::cout << "Window class name: " << mainWindow->className() << std::endl;
    std::cout << "Window instance name: " << mainWindow->name() << std::endl;
    std::cout << std::endl;

    // Create workstation
    Workstation *ws = new Workstation("ws", mainWindow->mainWindowWidget(), 0);
    std::cout << "Workstation class name: " << ws->className() << std::endl;
    std::cout << "Workstation instance name: " << ws->name() << std::endl;
    std::cout << "Workstation id: " << ws->id() << std::endl;
    std::cout << std::endl;

    VkMenuBar *bar = new VkMenuBar("menubar");
    std::cout << "Menu bar class name: " << bar->className() << std::endl;
    std::cout << "Menu bar instance name: " << bar->name() << std::endl;
    std::cout << std::endl;
    mainWindow->setMenuBar(bar);

    VkSubMenu *subFile = new VkSubMenu("file");
    std::cout << "Sub menu class name: " << subFile->className() << std::endl;
    std::cout << "Sub menu instance name: " << subFile->name() << std::endl;
    std::cout << std::endl;

    subFile->addAction("open");
    subFile->addAction("close");
    subFile->addAction("quit", quitCallback);

    bar->addSubmenu(subFile);

    VkSubMenu *subView = new VkSubMenu("view");
    VkSubMenu *subZoom = new VkSubMenu("zoom");
    subZoom->addAction("100");
    subZoom->addAction("200");
    subZoom->addAction("400");

    subView->addAction("restore");
    subView->addSubmenu(subZoom);
    bar->addSubmenu(subView);

static VkMenuDesc subMenuDesc[] = {
    {ACTION, "subaction1", NULL, NULL, NULL},
    {ACTION, "subaction2", NULL, NULL, NULL},
    {END,    NULL,         NULL, NULL, NULL}
};

static VkMenuDesc menuDesc[] = {
    {ACTION,  "action1", NULL, NULL, NULL},
    {SUBMENU, "submenu1", NULL, subMenuDesc, NULL},
    {ACTION,  "action2", NULL, NULL, NULL},
    {END,    NULL,         NULL, NULL, NULL}
};

    bar->addSubmenu("submenudesc", menuDesc);

    bar->build(mainWindow->mainWindowWidget());

    // Add workstation to main window
    mainWindow->addView(ws->baseWidget());

    // Show all windows
    app->show();

    // Run application
    app->run();

    return 0;
}

