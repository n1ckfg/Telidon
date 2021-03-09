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

#include <stdlib.h>
#include <string.h>
#include <phigs/phg.h>
#include <phigs/css.h>
#include <phigs/private/phgP.h>
#include <phigs/private/hdlP.h>

/*******************************************************************************
 * hdl_create
 *
 * DESCR:	Create new element handle
 * RETURNS:	Pointer to element head or NULL
 */

Phg_elmt_info* hdl_create(
   void **data,
   caddr_t argdata
   )
{
   Phg_elmt_info *head;

   head = (Phg_elmt_info *) malloc(ARGS_ELMT_SIZE_FULL(argdata));
   if (head != NULL) {
      head->elementType = ARGS_ELMT_TYPE(argdata);
      head->length = ARGS_ELMT_SIZE_FULL(argdata);
      *data = &head[1];
   }

   return head;
}

/*******************************************************************************
 * hdl_resize
 *
 * DESCR:	Change size element handle
 * RETURNS:	Pointer to element head or NULL
 */

Phg_elmt_info* hdl_resize(
   void *buf,
   void **data,
   caddr_t argdata
   )
{
   Phg_elmt_info *head;

   head = (Phg_elmt_info *) realloc(buf, ARGS_ELMT_SIZE_FULL(argdata));
   if (head != NULL) {
      head->elementType = ARGS_ELMT_TYPE(argdata);
      head->length = ARGS_ELMT_SIZE_FULL(argdata);
      *data = &head[1];
   }

   return head;
}

/*******************************************************************************
 * hdl_dup
 *
 * DESCR:	Duplicate element handle
 * RETURNS:	Pointer to element head or NULL
 */

Phg_elmt_info* hdl_dup(
   caddr_t argdata
   )
{
   Phg_elmt_info *head;

   head = (Phg_elmt_info *) malloc(ARGS_COPY_DATA_LEN(argdata));
   if (head != NULL) {
      memcpy(head,
             ARGS_COPY_DATA(argdata),
             ARGS_COPY_DATA_LEN(argdata));
   }

   return head;
}

/*******************************************************************************
 * hdl_generic_elmt
 *
 * DESCR:	Handle generic element
 * RETURNS:	TRUE on success, otherwise FALSE
 */

int hdl_generic_elmt(
   Css_handle cssh,
   El_handle elmt,
   caddr_t argdata,
   Css_el_op op
   )
{
   void *data;

   switch (op) {
      case CSS_EL_CREATE:
         ELMT_HEAD(elmt) = hdl_create((void *) &data, argdata);
         if (ELMT_HEAD(elmt) == NULL) {
            return (FALSE);
         }
         memcpy(data,
                ((Phg_args_add_el *) argdata)->el_data,
                ((Phg_args_add_el *) argdata)->el_size);
         break;

      case CSS_EL_REPLACE:
         ELMT_HEAD(elmt) = hdl_resize(ELMT_HEAD(elmt),
                                      (void *) &data, argdata);
         if (ELMT_HEAD(elmt) == NULL) {
            return (FALSE);
         }
         memcpy(data,
                ((Phg_args_add_el *) argdata)->el_data,
                ((Phg_args_add_el *) argdata)->el_size);
         break;

      case CSS_EL_COPY:
         ELMT_HEAD(elmt) = hdl_dup(argdata);
         if (ELMT_HEAD(elmt) == NULL) {
            return (FALSE);
         }
         break;

      case CSS_EL_INQ_CONTENT:
         ARGS_INQ_HEAD(argdata) = ELMT_HEAD(elmt);
         break;

      case CSS_EL_INQ_TYPE_SIZE:
         ARGS_INQ_SIZE(argdata) = ELMT_INFO_LEN(elmt);
         break;

      case CSS_EL_FREE:
         free(ELMT_HEAD(elmt));
         break;

      default:
         /* Default */
         return (FALSE);
         break;
   }

   return (TRUE);
}

