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
 * pinq_ws_cat
 *
 * DESCR:       Get workstation category
 * RETURNS:     N/A
 */

void pinq_ws_cat(
   Pint ws_type,
   Pint *err_ind,
   Pws_cat *cat
   )
{
   Wst *wst;

   if (!phg_entry_check(0, Pfn_INQUIRY)) {
      *err_ind = ERR2;
   }
   else {
      wst = phg_wst_find(&PHG_WST_LIST, ws_type);
      if (wst == NULL) {
         *err_ind = ERR52;
      }
      else {
         *err_ind = 0;
         *cat = wst->desc_tbl.phigs_dt.ws_category;
      }
   }
}

/*******************************************************************************
 * pinq_disp_space_size3
 *
 * DESCR:       Get display size 3D
 * RETURNS:     N/A
 */

void pinq_disp_space_size3(
   Pint ws_type,
   Pint *err_ind,
   Pdisp_space_size3 *size
   )
{
   Wst *wst;
   Wst_phigs_dt *dt;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_INQUIRY);

   wst = phg_wst_find(&PHG_WST_LIST, ws_type);
   if (wst == NULL) {
      *err_ind = ERR52;
   }
   else {
      dt = &wst->desc_tbl.phigs_dt;
      if (dt->ws_category == PCAT_MI) {
         *err_ind = ERR57;
      }
      else {
         *err_ind = 0;
         if (wst->bound_status != WST_BOUND) {
            size->dc_units           = dt->dev_coord_units;
            size->size_raster.size_x = dt->dev_addrs_units[0];
            size->size_raster.size_y = dt->dev_addrs_units[1];
            size->size_raster.size_z = dt->dev_addrs_units[2];
            size->size_dc.size_x     = dt->dev_coords[0];
            size->size_dc.size_y     = dt->dev_coords[1];
            size->size_dc.size_z     = dt->dev_coords[2];
         }
      }
   }
}

