/******************************************************************************
*   DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER
*
*   This file is part of Open PHIGS
*   Copyright (C) 2014 Surplus Users Ham Society
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

#ifndef _evtP_h
#define _evtP_h

#include <sys/types.h>
#include <X11/Xlib.h>
#include <phigs/phg.h>
#include <phigs/util.h>

typedef struct {
   Node    node;
   Display *display;
   Window  window;
   caddr_t cdata;
   void    (*callback)(
              Display *display,
              Window window,
              caddr_t caddr,
              XEvent *event
              );
} Phg_sin_evt_entry;

typedef struct {
   Pint num_events;
   List *events;
} Phg_sin_evt_tbl;

/*******************************************************************************
 * phg_sin_evt_tbl_create
 * 
 * DESCR:       Create event table
 * RETURNS:     Pointer to event table or NULL
 */

Phg_sin_evt_tbl* phg_sin_evt_tbl_create(
   int num_events
   );

/*******************************************************************************
 * phg_sin_evt_tbl_init
 *
 * DESCR:       Inititalize event table
 * RETURNS:     TRUE or FALSE
 */

int phg_sin_evt_tbl_init(
   Phg_sin_evt_tbl *ev_tbl
   );

/*******************************************************************************
 * phg_sin_evt_tbl_destroy
 *
 * DESCR:       Destroy event table
 * RETURNS:     N/A
 */

void phg_sin_evt_tbl_destroy(
   Phg_sin_evt_tbl *ev_tbl
   );

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
   );

/*******************************************************************************
 * phg_sin_evt_unregister
 * 
 * DESCR:       Unregister an event in event table
 * RETURNS:     N/A
 */

void phg_sin_evt_unregister(
   Phg_sin_evt_tbl *ev_tbl,
   Display *display,
   Window window,
   int event_type,
   caddr_t cdata
   );

/*******************************************************************************
 * phg_sin_evt_unregister_display
 *
 * DESCR:       Unregister all events for display in event table
 * RETURNS:     N/A
 */

void phg_sin_evt_unregister_display(
   Phg_sin_evt_tbl *ev_tbl,
   Display *display
   );

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
   );

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
   );

/*******************************************************************************
 * phg_sin_evt_name
 *
 * DESCR:       Get event type name
 * RETURNS:     Pointer to string
 */

char* phg_sin_evt_name(
   XEvent *event
   );

/*******************************************************************************
 * phg_sin_evt_print
 *
 * DESCR:       Print event type name
 * RETURNS:     N/A
 */

void phg_sin_evt_print(
   XEvent *event
   );

#endif /* _evtP_h */

