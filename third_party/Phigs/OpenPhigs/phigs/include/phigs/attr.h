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

#ifndef _attr_h
#define _attr_h

#include <phigs/phigs.h>

typedef struct {
   Pline_bundle_plus   line_bundle;
   Pmarker_bundle_plus marker_bundle;
   Ptext_bundle_plus   text_bundle;
   Pedge_bundle_plus   edge_bundle;
   Pint_bundle_plus    int_bundle;
} Pattr_group;

struct _Ws;

/*******************************************************************************
 * phg_attr_group_create
 *
 * DESCR:       Create attribute group
 * RETURNS:     Pointer to attribute group or NULL
 */

Pattr_group* phg_attr_group_create(
   void
   );

/*******************************************************************************
 * phg_attr_group_init
 *
 * DESCR:       Initialize attribute group
 * RETURNS:     TRUE or FALSE
 */

int phg_attr_group_init(
   Pattr_group *attr_group
   );

/*******************************************************************************
 * phg_attr_group_destroy
 *
 * DESCR:       Destroy attribute group
 * RETURNS:     N/A
 */

void phg_attr_group_destroy(
   Pattr_group *attr_group
   );

/*******************************************************************************
 * phg_attr_group_set_line_bundle
 *
 * DESCR:       Set attribute group line bundle
 * RETURNS:     N/A
 */

void phg_attr_group_set_line_bundle(
   struct _Ws *ws,
   Pattr_group *attr_group,
   Pline_bundle_plus *line_bundle
   );

/*******************************************************************************
 * phg_attr_group_set_marker_bundle
 *
 * DESCR:       Set attribute group marker bundle
 * RETURNS:     N/A
 */

void phg_attr_group_set_marker_bundle(
   struct _Ws *ws,
   Pattr_group *attr_group,
   Pmarker_bundle_plus *marker_bundle
   );

/*******************************************************************************
 * phg_attr_group_set_text_bundle
 *
 * DESCR:       Set attribute group text bundle
 * RETURNS:     N/A
 */

void phg_attr_group_set_text_bundle(
   struct _Ws *ws,
   Pattr_group *attr_group,
   Ptext_bundle_plus *text_bundle
   );

/*******************************************************************************
 * phg_attr_group_set_edge_bundle
 *
 * DESCR:       Set attribute group edge bundle
 * RETURNS:     N/A
 */

void phg_attr_group_set_edge_bundle(
   struct _Ws *ws,
   Pattr_group *attr_group,
   Pedge_bundle_plus *edge_bundle
   );

/*******************************************************************************
 * phg_attr_group_set_int_bundle
 *
 * DESCR:       Set attribute group interior bundle
 * RETURNS:     N/A
 */

void phg_attr_group_set_int_bundle(
   struct _Ws *ws,
   Pattr_group *attr_group,
   Pint_bundle_plus *int_bundle
   );

#endif /* _attr_h */

