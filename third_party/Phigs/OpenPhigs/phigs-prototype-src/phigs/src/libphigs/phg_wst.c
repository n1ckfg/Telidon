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
#include <phigs/private/wsxP.h>

/*******************************************************************************
 * phg_wst_create
 *
 * DESCR:       Create workstation type structure
 * RETURNS:     Pointer to workstation type or NULL
 */

Wst* phg_wst_create(
   Err_handle erh,
   Pint ws_type
   )
{
   Wst *wst;

   wst = (Wst *) malloc(sizeof(Wst));
   if (wst == NULL) {
      ERR_REPORT(erh, ERR900);
   }
   else if (!phg_wst_init(wst, erh, ws_type)) {
      ERR_REPORT(erh, ERR900);
   }

   return wst;
}

/*******************************************************************************
 * phg_wst_init
 *
 * DESCR:       Initialize workstation type structure
 * RETURNS:     TRUE or FALSE
 */

int phg_wst_init(
   Wst *wst,
   Err_handle erh,
   Pint ws_type
   )
{
   wst->wsid = -1;
   wst->bound_status = WST_UNBOUND;
   wst->erh = erh;
   wst->ws_type = ws_type;

   return TRUE;
}

/*******************************************************************************
 * phg_wst_find
 *
 * DESCR:       Find workstation type
 * RETURNS:     Pointer to workstation type or NULL
 */

Wst* phg_wst_find(
   List *list,
   Pint ws_type
   )
{
   Wst *wst;

   for (wst = (Wst *) LIST_HEAD(list);
        wst != NULL;
        wst = (Wst *) NODE_NEXT(&wst->node)) {
      if (wst->ws_type == ws_type) {
         break;
      }
   }

   return wst;
}

/*******************************************************************************
 * phg_wst_destroy
 *
 * DESCR:       Destroy workstation type structure
 * RETURNS:     N/A
 */

void phg_wst_destroy(
   Wst *wst
   )
{
   if (wst != NULL) {
      free(wst);
   }
}

/*******************************************************************************
 * phg_wst_check_set_rep
 *
 * DESCR:       Check workstation attribute to set
 * RETURNS:     Pointer to Wst_phigs_dt structure or NULL
 */

Wst_phigs_dt* phg_wst_check_set_rep(
   Pint fn_id,
   Pint ws_id,
   Pint ind,
   Pint colr_ind
   )
{
   Psl_ws_info *wsinfo;
   Wst_phigs_dt *dt = NULL;

   ERR_SET_CUR_FUNC(PHG_ERH, fn_id);

   if (PSL_WS_STATE(PHG_PSL) != PWS_ST_WSOP) {
      ERR_REPORT(PHG_ERH, ERR3);
   }
   else if (ind < 1) {
      ERR_REPORT(PHG_ERH, ERR100);
   }
   else if (colr_ind < 0) {
      ERR_REPORT(PHG_ERH, ERR113);
   }
   else {
      wsinfo = phg_psl_get_ws_info(PHG_PSL, ws_id);
      if (wsinfo == NULL) {
         ERR_REPORT(PHG_ERH, ERR54);
      }
      else {
         dt = &wsinfo->wstype->desc_tbl.phigs_dt;
         if (!(dt->ws_category == PCAT_OUTIN ||
               dt->ws_category == PCAT_OUT ||
               dt->ws_category == PCAT_MO)) {
            ERR_REPORT(PHG_ERH, ERR59);
            dt = NULL;
         }
      }
   }

   return dt;
}

/*******************************************************************************
 * phg_wst_add_ws_type
 *
 * DESCR:       Add workstation type
 * RETURNS:     TRUE or FALSE
 */

int phg_wst_add_ws_type(
   Pws_cat category,
   int double_buffer
   )
{
   int status;
   Wst *wst;

   wst = phg_wstx_create(PHG_ERH, category, double_buffer);
   if (wst == NULL) {
      status = FALSE;
   }
   else {
      list_add(&PHG_WST_LIST, &wst->node);
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * phg_wst_remove_ws_types
 *
 * DESCR:       Remove workstation types
 * RETURNS:     N/A
 */

void phg_wst_remove_ws_types(
   void
   )
{
   Wst *wst;

   wst = (Wst *) list_get(&PHG_WST_LIST);
   while (wst != NULL) {
      phg_wst_destroy(wst);
      wst = (Wst *) list_get(&PHG_WST_LIST);
   }
}

