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
#include <phigs/util/ftn.h>

/*******************************************************************************
 * popst
 *
 * DESCR:	Opens a structure for appending or editing.
 * RETURNS:	N/A
 */

FTN_SUBROUTINE(popst)(
   FTN_INTEGER(strid)
   )
{
   Pint struct_id = FTN_INTEGER_GET(strid);

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
 * pclst
 *
 * DESCR:	Closes a previously opened structure.
 * RETURNS:	N/A
 */

FTN_SUBROUTINE(pclst)(
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

