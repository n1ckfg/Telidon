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
#include <phigs/private/phgP.h>

/*******************************************************************************
 * phg_int_in_list
 *
 * DESCR:       Find out if integer values is stored in list
 * RETURNS:     TRUE or FALSE
 */

int phg_int_in_list(
   Pint v,
   Pint num,
   Pint *list
   )
{
   Pint i;
   int status = FALSE;

   for (i = 0; i < num; i++) {
      if (list[i] == v) {
         status = TRUE;
         break;
      }
   }

   return status;
}

/*******************************************************************************
 * phg_echo_limits_valid
 *
 * DESCR:       Helper function to check if echo volume limits are valid
 * RETURNS:     TRUE or FALSE
 */

int phg_echo_limits_valid(
   Pint ws_id,
   Pint fn_id,
   Plimit3 *e_volume,
   Wst_phigs_dt *dt
   )
{
   Psl_ws_info *wsinfo;
   int status = FALSE;

   wsinfo = phg_psl_get_ws_info(PHG_PSL, ws_id);
   switch(fn_id) {
      case Pfn_init_loc3:
      case Pfn_init_stroke3:
      case Pfn_init_pick3:
      case Pfn_init_val3:
      case Pfn_init_choice3:
      case Pfn_init_string3:
      case Pfn_escape:
         if (!PHG_ECHO_VOLUME_VALID(e_volume)) {
            ERR_REPORT(PHG_ERH, ERR254);
         }
         else if (!PHG_ECHO_VOLUME_IN_RANGE(e_volume, dt->dev_coords)) {
            ERR_REPORT(PHG_ERH, ERR255);
         }
         else {
            status = TRUE;
         }
         break;


      case Pfn_init_loc:
      case Pfn_init_stroke:
      case Pfn_init_pick:
      case Pfn_init_val:
      case Pfn_init_choice:
      case Pfn_init_string:
         if (!PHG_ECHO_AREA_VALID(e_volume)) {
            ERR_REPORT(PHG_ERH, ERR254);
         }
         else if (!PHG_ECHO_AREA_IN_RANGE(e_volume, dt->dev_coords)) {
            ERR_REPORT(PHG_ERH, ERR255);
         }
         else {
            status = TRUE;
         }
         break;
   }

   return status;
}

