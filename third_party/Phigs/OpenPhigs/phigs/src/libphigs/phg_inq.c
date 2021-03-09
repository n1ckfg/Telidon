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
#include <phigs/css.h>
#include <phigs/private/phgP.h>

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
   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

   if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
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
   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

   if (PSL_SYS_STATE(PHG_PSL) != PSYS_ST_PHOP) {
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

