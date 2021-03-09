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

#include <stdio.h>
#include <stdlib.h>
#include <phigs/phg.h>
#include <phigs/css.h>
#include <phigs/private/phgP.h>

/*******************************************************************************
 * popen_struct
 *
 * DESCR:	Opens a structure for appending or editing.
 * RETURNS:	N/A
 */

void popen_struct(
   Pint struct_id
   )
{
   if (phg_entry_check(ERR6, Pfn_open_struct)) {
      if (PSL_STRUCT_STATE(PHG_PSL) == PSTRUCT_ST_STCL) {
         if (phg_css_open_struct(PHG_CSS, struct_id) != NULL) {
            PSL_STRUCT_STATE(PHG_PSL) = PSTRUCT_ST_STOP;
            PSL_OPEN_STRUCT(PHG_PSL) = struct_id;
         }
         ERR_FLUSH(PHG_ERH);
      }
      else {
         ERR_REPORT(PHG_ERH, ERR6);
      }
   }
}

/*******************************************************************************
 * pclose_struct
 *
 * DESCR:	Closes a previously opened structure.
 * RETURNS:	N/A
 */

void pclose_struct(
   void
   )
{
   if (phg_entry_check(ERR5, Pfn_close_struct)) {
      if (PSL_STRUCT_STATE(PHG_PSL) == PSTRUCT_ST_STOP) {
         phg_close_struct(PHG_CSS);
         PSL_STRUCT_STATE(PHG_PSL) = PSTRUCT_ST_STCL;
      }
      else {
         ERR_REPORT(PHG_ERH, ERR5);
      }
   }
}

/*******************************************************************************
 * pset_edit_mode
 *
 * DESCR:	Set structure edit mode
 * RETURNS:	N/A
 */

void pset_edit_mode(
   Pedit_mode mode
   )
{
   if (phg_entry_check(ERR2, Pfn_set_edit_mode)) {
      CSS_EDIT_MODE(PHG_CSS) = mode;
      PSL_EDIT_MODE(PHG_PSL) = mode;
   }
}

/*******************************************************************************
 * pset_elem_ptr
 *
 * DESCR:	Make the requested index the "currently active element".
 * 		NOTE: 0 means set element to even before the very first
 * 		element; 1 means set elptr to very first element.
 * RETURNS:	N/A
 */

void pset_elem_ptr(
   Pint elem_ptr_value
   )
{
   Phg_args_set_el_ptr args;

   if (phg_entry_check(ERR5, Pfn_set_elem_ptr)) {
      if (PSL_STRUCT_STATE(PHG_PSL) == PSTRUCT_ST_STOP) {
         args.op = PHG_ARGS_SETEP_ABS;
         args.data = elem_ptr_value;
         phg_set_el_ptr(PHG_CSS, &args);
      }
      else {
         ERR_REPORT(PHG_ERH, ERR5);
      }
   }
}

/*******************************************************************************
 * poffset_elem_ptr
 *
 * DESCR:	Offsets the element pointer forward by the given number of
 * 		elements.
 * 		Internal call to pset_elem_ptr does the verification work
 * 		on the index.
 * RETURNS:	N/A
 */

void poffset_elem_ptr(
   Pint elem_ptr_offset
   )
{
   Phg_args_set_el_ptr args;

   if (phg_entry_check(ERR5, Pfn_offset_elem_ptr)) {
      if (PSL_STRUCT_STATE(PHG_PSL) == PSTRUCT_ST_STOP) {
         args.op = PHG_ARGS_SETEP_REL;
         args.data = elem_ptr_offset;
         phg_set_el_ptr(PHG_CSS, &args);
      }
      else {
         ERR_REPORT(PHG_ERH, ERR5);
      }
   }
}

/*******************************************************************************
 * pset_elem_ptr_label
 *
 * DESCR:	Searches forward in the structure list for the specified
 * 		label, and makes that the current element.  Search begins
 * 		with the element after (to the right) of the current one.
 * 		Question: should I include the current element in the search?
 * 		Or does the search begin with the first element after the
 * 		current one? 
 * 		This version gives fatal error if label not found.
 * RETURNS:	N/A
 */

void pset_elem_ptr_label(
   Pint label_id
   )
{
   Phg_args_set_el_ptr args;

   if (phg_entry_check(ERR5, Pfn_set_elem_ptr_label)) {
      if (PSL_STRUCT_STATE(PHG_PSL) == PSTRUCT_ST_STOP) {
         args.op = PHG_ARGS_SETEP_LABEL;
         args.data = label_id;
         phg_set_el_ptr(PHG_CSS, &args);
      }
      else {
         ERR_REPORT(PHG_ERH, ERR5);
      }
   }
}

/*******************************************************************************
 * pdel_elem
 *
 * DESCR:	Deletes the current element.  The element pointer is left
 * 		pointing to the element just before (to the left) the one to
 * 		be killed, if any.
 * RETURNS:	N/A
 */

void pdel_elem(
   void
   )
{
   Phg_args_del_el args;

   if (phg_entry_check(ERR5, Pfn_del_elem)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.op = PHG_ARGS_DEL_CURRENT;
         phg_del_el(PHG_CSS, &args);
      }
   }
}

/*******************************************************************************
 * pdel_elem_range
 *
 * DESCR:	Deletes all elements within and on the bounds of the given
 * 		range.  The element pointer is left pointing to the element
 *		just prior to the first element deleted.
 * RETURNS:	N/A
 */

void pdel_elem_range(
   Pint elem_ptr1_value,
   Pint elem_ptr2_value
   )
{
   Phg_args_del_el args;

   if (phg_entry_check(ERR5, Pfn_del_elem_range)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.op = PHG_ARGS_DEL_RANGE;
         args.data.ep_values.ep1 = PHG_MAX(0, elem_ptr1_value);
         args.data.ep_values.ep2 = elem_ptr2_value;
         phg_del_el(PHG_CSS, &args);
      }
   }
}

/*******************************************************************************
 * pdel_elems_labels
 *
 * DESCR:	Deletes all elements in the structure that lie between the
 * 		given labels, but not the labels themselves.  The element
 * 		pointer is left pointing to the first label.
 * RETURNS:	N/A
 */

void pdel_elems_labels(
   Pint label1_id,
   Pint label2_id
   )
{
   Phg_args_del_el args;

   if (phg_entry_check(ERR5, Pfn_del_elems_labels)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         args.op = PHG_ARGS_DEL_LABEL;
         args.data.label_range.label1 = label1_id;
         args.data.label_range.label2 = label2_id;
         phg_del_el(PHG_CSS, &args);
      }
   }
}

/*******************************************************************************
 * pempty_struct
 *
 * DESCR:	Clear structure
 * RETURNS:	N/A
 */

void pempty_struct(
   Pint struct_id
   )
{
   Phg_args_del_el args;

   if (phg_entry_check(ERR2, Pfn_empty_struct)) {
      args.op = PHG_ARGS_EMPTY_STRUCT;
      args.data.struct_id = struct_id;
      phg_del_el(PHG_CSS, &args);
   }
}

/*******************************************************************************
 * pcopy_all_elems_struct
 *
 * DESCR:	Copies the elements of another structure into the open
 * 		structure after the current element, which is updated to
 * 		point to the last element inserted.  A structure can be
 * 		copied into itself.
 * RETURNS:	N/A
 */

void pcopy_all_elems_struct(
   Pint struct_id
   )
{
   if (phg_entry_check(ERR5, Pfn_copy_all_elems_struct)) {
      if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
         ERR_REPORT(PHG_ERH, ERR5);
      }
      else {
         phg_copy_all_els(PHG_CSS, struct_id);
      }
   }
}

/*******************************************************************************
 * pinq_elem_ptr
 *
 * DESCR:	Returns the index of the current element.
 * RETURNS:	N/A
 */

void pinq_elem_ptr(
   Pint *err_ind,
   Pint *elem_ptr_value
   )
{
   if (!phg_entry_check(0, Pfn_INQUIRY)) {
      *err_ind = ERR5;
   }
   else if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      *err_ind = ERR5;
   }
   else {
      *err_ind = 0;
      *elem_ptr_value = CSS_INQ_EL_INDEX(PHG_CSS);
   }
}

/*******************************************************************************
 * pinq_open_struct
 *
 * DESCR:	Check if a structure is open for appending or editing.
 * RETURNS:	N/A
 */

void pinq_open_struct(
   Pint *err_ind,
   Popen_struct_status *status,
   Pint *struct_id
   )
{
   if (!phg_entry_check(0, Pfn_INQUIRY)) {
      *err_ind = ERR2;
   }
   else if (PSL_STRUCT_STATE(PHG_PSL) != PSTRUCT_ST_STOP) {
      *status = PSTRUCT_NONE;
      *err_ind = 0;
   }
   else {
      *err_ind = 0;
      *status = PSTRUCT_OPEN;
      *struct_id = CSS_CUR_STRUCT_ID(PHG_CSS);
   }
}

