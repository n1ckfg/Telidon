/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
*
*   This file is part of Open PHIGS
*   Copyright (C) 2011 - 2012 Surplus Users Ham Society
*
*   Open PHIGS is free software: you can redistribute it and/or modify
*   it under the terms of the GNU Lesser General Public License as published by
*   the Free Software Foundation, either version 2.1 of the License, or
*   (at your option) any later version.
*
*   Open PHIGS is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public License
*   along with Open PHIGS. If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <phigs/phg.h>
#include <phigs/private/evtP.h>

static char *eventNames[] = {
   "Illegal Event",
   "Illegal Event",
   "KeyPress",
   "KeyRelease",
   "ButtonPress",
   "ButtonRelease",
   "MotionNotify",
   "EnterNotify",
   "LeaveNotify",
   "FocusIn",
   "FocusOut",
   "KeymapNotify",
   "Expose",
   "GraphicsExpose",
   "NoExpose",
   "VisibilityNotify",
   "CreateNotify",
   "DestroyNotify",
   "UnmapNotify",
   "MapNotify",
   "MapRequest",
   "ReparentNotify",
   "ConfigureNotify",
   "ConfigureRequest",
   "GravityNotify",
   "ResizeRequest",
   "CirculateNotify",
   "CirculateRequest",
   "PropertyNotify",
   "SelectionClear",
   "SelectionRequest",
   "SelectionNotify",
   "ColormapNotify",
   "ClientMessage",
   "MappingNotify",
   "unknown event type"
};

/*******************************************************************************
 * phg_sin_evt_tbl_create
 *
 * DESCR:       Create event table
 * RETURNS:     Pointer to event table or NULL
 */

Phg_sin_evt_tbl* phg_sin_evt_tbl_create(
   int num_events
   )
{
   Phg_sin_evt_tbl *ev_tbl;

   ev_tbl = (Phg_sin_evt_tbl *) malloc(sizeof(Phg_sin_evt_tbl) +
                                       sizeof(Phg_sin_evt_entry) * num_events);
   if (ev_tbl != NULL) {
      ev_tbl->num_events = num_events;
      ev_tbl->events = (List *) &ev_tbl[1];
      if (!phg_sin_evt_tbl_init(ev_tbl)) {
         free(ev_tbl);
         ev_tbl = NULL;
      }
   }

   return ev_tbl;
}

/*******************************************************************************
 * phg_sin_evt_tbl_init
 *
 * DESCR:       Inititalize event table
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_evt_tbl_init(
   Phg_sin_evt_tbl *ev_tbl
   )
{
   int i;

   for (i = 0; i < ev_tbl->num_events; i++) {
      list_init(&ev_tbl->events[i]);
   }

   return TRUE;
}

/*******************************************************************************
 * phg_sin_evt_tbl_destroy
 *
 * DESCR:       Destroy event table
 * RETURNS:     N/A
 */

void phg_sin_evt_tbl_destroy(
   Phg_sin_evt_tbl *ev_tbl
   )
{
   free(ev_tbl);
}

/*******************************************************************************
 * phg_sin_evt_register
 *
 * DESCR:       Register an event in event table
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_evt_register(
   Phg_sin_evt_tbl *ev_tbl,
   Display *display,
   Window window,
   int event_type,
   caddr_t cdata,
   void (*callback)(Display*, Window, caddr_t, XEvent*)
   )
{
   int status;
   Phg_sin_evt_entry *ev;

#ifdef DEBUG
   printf("sin_evt: phg_sin_evt_register\n");
   printf("\t%-14s", eventNames[event_type]);
   printf("\tWindow = %x, ", (unsigned) window);
   printf("\tClient_data = %x\n", (unsigned) cdata);
#endif
   /* First check if entry exists */
   for (ev = (Phg_sin_evt_entry *) LIST_HEAD(&ev_tbl->events[event_type]);
        ev != NULL;
        ev = (Phg_sin_evt_entry *) NODE_NEXT(&ev->node)) {
      if ((ev->display == display) &&
          (ev->window == window) &&
          (ev->cdata == cdata)) {
         ev->callback = callback;
         break;
      }
   }

   /* Was not found */
   if (ev == NULL) {
      ev = (Phg_sin_evt_entry *) malloc(sizeof(Phg_sin_evt_entry));
      if (ev == NULL) {
         status = FALSE;
      }
      else {
         ev->display = display;
         ev->window = window;
         ev->cdata = cdata;
         ev->callback = callback;
         list_add(&ev_tbl->events[event_type], &ev->node);
      }
   }
   else {
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * phg_sin_evt_unregister
 *
 * DESCR:       Unregister event in event table
 * RETURNS:     N/A
 */

void phg_sin_evt_unregister(
   Phg_sin_evt_tbl *ev_tbl,
   Display *display,
   Window window,
   int event_type,
   caddr_t cdata
   )
{
   Phg_sin_evt_entry *ev;

   /* First check if entry exists */
   for (ev = (Phg_sin_evt_entry *) LIST_HEAD(&ev_tbl->events[event_type]);
        ev != NULL;
        ev = (Phg_sin_evt_entry *) NODE_NEXT(&ev->node)) {
      if ((ev->display == display) &&
          (ev->window == window) &&
          (ev->cdata == cdata)) {
         list_remove(&ev_tbl->events[event_type], &ev->node);
         free(ev);
         break;
      }
   }
}

/*******************************************************************************
 * phg_sin_evt_unregister_display
 *
 * DESCR:       Unregister all events for display in event table
 * RETURNS:     N/A
 */

void phg_sin_evt_unregister_display(
   Phg_sin_evt_tbl *ev_tbl,
   Display *display
   )
{
   int i;
   Phg_sin_evt_entry *ev;

   for (i = 0; i < ev_tbl->num_events; i++) {
      for (ev = (Phg_sin_evt_entry *) LIST_HEAD(&ev_tbl->events[i]);
           ev != NULL;
           ev = (Phg_sin_evt_entry *) NODE_NEXT(&ev->node)) {
         if (ev->display == display) {
            list_remove(&ev_tbl->events[i], &ev->node);
            free(ev);
         }
      }
   }
}

/*******************************************************************************
 * phg_sin_evt_unregister_window
 *
 * DESCR:       Unregister all events for window in event table
 * RETURNS:     N/A
 */

void phg_sin_evt_unregister_window(
   Phg_sin_evt_tbl *ev_tbl,
   Display *display,
   Window window
   )
{
   int i;
   Phg_sin_evt_entry *ev;

   for (i = 0; i < ev_tbl->num_events; i++) {
      for (ev = (Phg_sin_evt_entry *) LIST_HEAD(&ev_tbl->events[i]);
           ev != NULL;
           ev = (Phg_sin_evt_entry *) NODE_NEXT(&ev->node)) {
         if ((ev->display == display) &&
             (ev->window == window)) {
            list_remove(&ev_tbl->events[i], &ev->node);
            free(ev);
         }
      }
   }
}

/*******************************************************************************
 * phg_sin_evt_dispatch
 *
 * DESCR:       Dipatch events using event table
 * RETURNS:     N/A
 */

void phg_sin_evt_dispatch(
   Phg_sin_evt_tbl *ev_tbl,
   Display *display,
   XEvent *event
   )
{
   Phg_sin_evt_entry *ev;

   /* First check if entry exists */
   for (ev = (Phg_sin_evt_entry *) LIST_HEAD(&ev_tbl->events[event->type]);
        ev != NULL;
        ev = (Phg_sin_evt_entry *) NODE_NEXT(&ev->node)) {
      if ((ev->display == display) &&
          (ev->window == event->xany.window)) {
#ifdef DEBUG
         printf("%x\t", (unsigned) ev->cdata);
         phg_sin_evt_print(event);
         printf("\n");
#endif
         (*ev->callback)(display,
                         event->xany.window,
                         ev->cdata,
                         event);
      }
   }
}

/*******************************************************************************
 * phg_sin_evt_name
 *
 * DESCR:       Get event type name
 * RETURNS:     Pointer to string
 */

char* phg_sin_evt_name(
   XEvent *event
   )
{
   return eventNames[event->type];
}

/*******************************************************************************
 * phg_sin_evt_print
 *
 * DESCR:       Print event type name
 * RETURNS:     N/A
 */

void phg_sin_evt_print(
   XEvent *event
   )
{
   printf("%-14s", eventNames[event->type]);
}

