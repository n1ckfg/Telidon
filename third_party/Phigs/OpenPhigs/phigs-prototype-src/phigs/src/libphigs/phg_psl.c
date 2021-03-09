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
#include <phigs/phigs.h>
#include <phigs/phg.h>

/*******************************************************************************
 * phg_psl_create
 *
 * DESCR:       Create PHIGS state list
 * RETURNS:     Pointer to state list or NULL
 */

Psl_handle phg_psl_create(
   void
   )
{
   Psl_handle psl;

   psl = (Psl_handle) malloc(sizeof(Phg_state_list));
   if (psl == NULL)
      return NULL;

   if (!phg_psl_init(psl)) {
      free(psl);
      return NULL;
   }

   return psl;
}

/*******************************************************************************
 * phg_psl_init
 *
 * DESCR:       Initialize PHIGS state list
 * RETURNS:     TRUE or FALSE
 */

int phg_psl_init(
   Psl_handle psl
   )
{
   int i;

   psl->phg_sys_state    = PSYS_ST_PHCL;
   psl->phg_ws_state     = PWS_ST_WSCL;
   psl->phg_struct_state = PSTRUCT_ST_STCL;
   psl->phg_ar_state     = PST_ARCL;
   psl->ar_res           = PRES_MAINTAIN;
   psl->retr_res         = PRES_MAINTAIN;

   for (i = 0; i < MAX_NO_OPEN_WS; i++)
      psl->open_ws[i].used = FALSE;

   for (i = 0; i < MAX_NO_OPEN_ARFILES; i++)
      psl->ar_files[i].used = FALSE;

   psl->edit_mode = PEDIT_INSERT;

   return TRUE;
}

/*******************************************************************************
 * phg_psl_destroy
 *
 * DESCR:       Destroy PHIGS state list
 * RETURNS:     N/A
 */

void phg_psl_destroy(
   Psl_handle psl
   )
{
   if (psl != NULL)
      free(psl);
}

/*******************************************************************************
 * phg_psl_inq_ws_open
 *
 * DESCR:       Inquire open workstation
 * RETURNS:     TRUE or FALSE
 */

int phg_psl_inq_ws_open(
   Psl_handle psl,
   Pint wsid
   )
{
   int i;
   int status = FALSE;

   for (i = 0; i < MAX_NO_OPEN_WS; i++) {
      if ((psl->open_ws[i].used) &&
          (psl->open_ws[i].wsid == wsid)) {
         status = TRUE;
      }
   }

   return status;
}

/*******************************************************************************
 * phg_psl_inq_wsids
 *
 * DESCR:       Inquire workstation ids
 * RETURNS:     Number of open workstations
 */

int phg_psl_inq_wsids(
   Psl_handle psl,
   Pint *wsids
   )
{
   int i;
   int cnt = 0;

   for (i = 0; i < MAX_NO_OPEN_WS; i++) {
      if (psl->open_ws[i].used) {
         *wsids++ = psl->open_ws[i].wsid;
         ++cnt;
      }
   }

   return cnt;
}

/*******************************************************************************
 * phg_psl_get_ws_info
 *
 * DESCR:       Get open workstation information
 * RETURNS:     Pointer to information structure
 */

Psl_ws_info* phg_psl_get_ws_info(
   Psl_handle psl,
   Pint wsid
   )
{
   int  i;
   Psl_ws_info *ws = NULL;

   for (i = 0; i < MAX_NO_OPEN_WS; i++) {
      if ((psl->open_ws[i].used) &&
          (psl->open_ws[i].wsid == wsid)) {
         ws = &psl->open_ws[i];
         break;
      }
   }

   return ws;
}

/*******************************************************************************
 * phg_psl_ws_free_slot
 *
 * DESCR:       Find if there is a free slot for a workstation
 * RETURNS:     TRUE or there is a slot free otherwise FALSE
 */

int phg_psl_ws_free_slot(
   Psl_handle psl
   )
{
   int i;
   int status = FALSE;

   for (i = 0; i < MAX_NO_OPEN_WS; i++) {
      if (!psl->open_ws[i].used) {
         status = TRUE;
         break;
      }
   }

   return status;
}

/*******************************************************************************
 * phg_psl_add_ws
 *
 * DESCR:	Add workstation to list
 * RETURNS:	TRUE if wsid could be added, else FALSE
 */

int phg_psl_add_ws(
   Psl_handle psl,
   Pint wsid,
   char *connid,
   Wst *type
   )
{
   int i;
   int status = FALSE;

   for (i = 0; i < MAX_NO_OPEN_WS; i++) {
      if (!psl->open_ws[i].used) {
         psl->open_ws[i].used = TRUE;
         psl->open_ws[i].wsid = wsid;
         psl->open_ws[i].connid = connid;
         psl->open_ws[i].wstype = type;
         status = TRUE;
         break;
      }
   }

   /* Update state list to reflect that at least one workstation is open */
   if (status)
      PSL_WS_STATE(psl) = PWS_ST_WSOP;

   return status;
}

/*******************************************************************************
 * phg_psl_rem_ws
 *
 * DESCR:	Remove workstation from list
 * RETURNS:	N/A
 */

void phg_psl_rem_ws(
   Psl_handle psl,
   Pint wsid
   )
{
   int i, cnt;

   for (i = 0, cnt = 0; i < MAX_NO_OPEN_WS; i++) {
      if (psl->open_ws[i].used) {
         if (psl->open_ws[i].wsid == wsid)
            psl->open_ws[i].used = FALSE;
         else
            ++cnt;
      }
   }

   /* Check if the last workstation was closed */
   if (!cnt)
      PSL_WS_STATE(psl) = PWS_ST_WSCL;
}

/*******************************************************************************
 * phg_psl_inq_ar_open
 *
 * DESCR:	Check if archive is already open
 * RETURNS:	Non-zero on open, otherwise zero
 */

int phg_psl_inq_ar_open(
   Psl_handle psl,
   Pint       arid
   )
{
   int i;
   int status = 0;

   if (psl != NULL) {
      for (i = 0; i < MAX_NO_OPEN_ARFILES; i++) {
         if ((psl->ar_files[i].used) &&
             (psl->ar_files[i].arid == arid)) {
            status = 1;
            break;
         }
      }
   }

   return status;
}

/*******************************************************************************
 * phg_psl_get_ar_info
 *
 * DESCR:	Get information about archive
 * RETURNS:	Pointer to archive info structure or NULL
 */

Psl_ar_info* phg_psl_get_ar_info(
   Psl_handle psl,
   Pint arid
   )
{
   int i;
   Psl_ar_info *ar = NULL;

   if (psl != NULL) {
      for (i = 0; i < MAX_NO_OPEN_ARFILES; i++) {
         if ((psl->ar_files[i].used) &&
             (psl->ar_files[i].arid == arid)) {
            ar = &psl->ar_files[i];
            break;
         }
      }
   }

   return ar;
}

/*******************************************************************************
 * phg_psl_ar_free_slot
 *
 * DESCR:	Check if there is a free slot for archive
 * RETURNS:	Non-zero success, otherwise zero
 */

int phg_psl_ar_free_slot(
   Psl_handle psl
   )
{
   int i;
   int status = 0;

   if (psl != NULL) {
      for (i = 0; i < MAX_NO_OPEN_ARFILES; i++) {
         if (!psl->ar_files[i].used) {
            status = 1;
            break;
         }
      }
   }

   return status;
}

/*******************************************************************************
 * phg_psl_add_ar
 *
 * DESCR:	Add achive to list
 * RETURNS:	Non-zero success, otherwise zero
 */

int phg_psl_add_ar(
   Psl_handle psl,
   Pint arid,
   char *fname
   )
{
   int i;
   int status = 0;

   for (i = 0; i < MAX_NO_OPEN_ARFILES; i++) {
      if (!psl->ar_files[i].used) {
         psl->ar_files[i].used = TRUE;
         psl->ar_files[i].arid = arid;
         psl->ar_files[i].fname = fname;
         status = 1;
         break;
      }
   }

   return status;
}

/*******************************************************************************
 * phg_psl_rem_ar
 *
 * DESCR:	Remove archive from list
 * RETURNS:	N/A
 */

void phg_psl_rem_ar(
   Psl_handle psl,
   Pint arid
   )
{
   int i;
   int count = 0;

   for (i = 0; i < MAX_NO_OPEN_ARFILES; i++) {
      if (psl->ar_files[i].used) {
         if (psl->ar_files[i].arid == arid) {
            psl->ar_files[i].used = FALSE;
            free(psl->ar_files[i].fname);
         }
         else {
            ++count;
         }
      }
   }

   if (count == 0) {
      PSL_AR_STATE(psl) = PST_ARCL;
   }
}

