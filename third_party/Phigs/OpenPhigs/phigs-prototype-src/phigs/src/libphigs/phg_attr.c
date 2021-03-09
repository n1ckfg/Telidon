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

#include <string.h>
#include <phigs/phg.h>
#include <phigs/css.h>
#include <phigs/private/phgP.h>
#include <phigs/private/cssP.h>
#include <phigs/ws.h>

/*******************************************************************************
 * phg_attr_group_create
 *
 * DESCR:	Create attribute group
 * RETURNS:	Pointer to attribute group or NULL
 */

Pattr_group* phg_attr_group_create(
   void
   )
{
   Pattr_group *attr_group;

   attr_group = (Pattr_group *) malloc(sizeof(Pattr_group));
   if (attr_group != NULL) {
      if (!phg_attr_group_init(attr_group)) {
         ERR_REPORT(PHG_ERH, ERR900);
         attr_group = NULL;
      }
   }

   return attr_group;
}

/*******************************************************************************
 * phg_attr_group_init
 *
 * DESCR:	Initialize attribute group
 * RETURNS:	TRUE or FALSE
 */

int phg_attr_group_init(
   Pattr_group *attr_group
   )
{
   memset(attr_group, 0, sizeof(Pattr_group));

   return TRUE;
}

/*******************************************************************************
 * phg_attr_group_destroy
 *
 * DESCR:	Destroy attribute group
 * RETURNS:	N/A
 */

void phg_attr_group_destroy(
   Pattr_group *attr_group
   )
{
   if (attr_group != NULL) {
      free(attr_group);
   }
}

/*******************************************************************************
 * phg_attr_group_set_line_bundle
 *
 * DESCR:	Set attribute group line bundle
 * RETURNS:	N/A
 */

void phg_attr_group_set_line_bundle(
   Ws *ws,
   Pattr_group *attr_group,
   Pline_bundle_plus *line_bundle
   )
{
   memcpy(&attr_group->line_bundle, line_bundle, sizeof(Pline_bundle_plus));
   if (attr_group->line_bundle.colr.type == PINDIRECT) {
      phg_get_colr_ind(ws,
                       &attr_group->line_bundle.colr,
                       attr_group->line_bundle.colr.val.ind);
   }
}

/*******************************************************************************
 * phg_attr_group_set_marker_bundle
 *
 * DESCR:	Set attribute group marker bundle
 * RETURNS:	N/A
 */

void phg_attr_group_set_marker_bundle(
   Ws *ws,
   Pattr_group *attr_group,
   Pmarker_bundle_plus *marker_bundle
   )
{
   memcpy(&attr_group->marker_bundle,
          marker_bundle,
          sizeof(Pmarker_bundle_plus));
   if (attr_group->marker_bundle.colr.type == PINDIRECT) {
      phg_get_colr_ind(ws,
                       &attr_group->marker_bundle.colr,
                       attr_group->marker_bundle.colr.val.ind);
   }
}

/*******************************************************************************
 * phg_attr_group_set_text_bundle
 *
 * DESCR:	Set attribute group text bundle
 * RETURNS:	N/A
 */

void phg_attr_group_set_text_bundle(
   Ws *ws,
   Pattr_group *attr_group,
   Ptext_bundle_plus *text_bundle
   )
{
   memcpy(&attr_group->text_bundle, text_bundle, sizeof(Ptext_bundle_plus));
   if (attr_group->text_bundle.colr.type == PINDIRECT) {
      phg_get_colr_ind(ws,
                       &attr_group->text_bundle.colr,
                       attr_group->text_bundle.colr.val.ind);
   }
}

/*******************************************************************************
 * phg_attr_group_set_edge_bundle
 *
 * DESCR:	Set attribute group edge bundle
 * RETURNS:	N/A
 */

void phg_attr_group_set_edge_bundle(
   Ws *ws,
   Pattr_group *attr_group,
   Pedge_bundle_plus *edge_bundle
   )
{
   memcpy(&attr_group->edge_bundle, edge_bundle, sizeof(Pedge_bundle_plus));
   if (attr_group->edge_bundle.colr.type == PINDIRECT) {
      phg_get_colr_ind(ws,
                       &attr_group->edge_bundle.colr,
                       attr_group->edge_bundle.colr.val.ind);
   }
}

/*******************************************************************************
 * phg_attr_group_set_int_bundle
 *
 * DESCR:	Set attribute group interior bundle
 * RETURNS:	N/A
 */

void phg_attr_group_set_int_bundle(
   Ws *ws,
   Pattr_group *attr_group,
   Pint_bundle_plus *int_bundle
   )
{
   memcpy(&attr_group->int_bundle, int_bundle, sizeof(Pint_bundle_plus));
   if (attr_group->int_bundle.colr.type == PINDIRECT) {
      phg_get_colr_ind(ws,
                       &attr_group->int_bundle.colr,
                       attr_group->int_bundle.colr.val.ind);
   }
}

