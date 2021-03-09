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
#include <phigs/ar.h>
#include <phigs/private/phgP.h>
 
/*******************************************************************************
 * valid_ar_fname
 *
 * DESCR:       Check archive filename helper function
 * RETURNS:     Non-zero on success, otherwise zero
 */

static int valid_ar_fname(
   char *fname
   )
{
   int status = 0;

   if (fname != NULL && strlen(fname) <= PHG_MAX_NAMELEN) {
      status = 1;
   }

   return status;
}

/*******************************************************************************
 * popen_ar_file
 *
 * DESCR:       Open archive file
 * RETURNS:     N/A
 */

void popen_ar_file(
   Pint archive_id,
   char *archive_file
   )
{
   Phg_args_ar_open args;
   Phg_ret ret;
   char *fname;

   if (phg_entry_check(ERR2, Pfn_open_ar_file)) {
      if (phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR402);
      }
      else if (!valid_ar_fname(archive_file)) {
         ERR_REPORT(PHG_ERH, ERR400);
      }
      else if (!phg_psl_ar_free_slot(PHG_PSL)) {
         ERR_REPORT(PHG_ERH, ERR401);
      }
      else {
         fname = (char *) malloc(strlen(archive_file) + 1);
         if (fname == NULL) {
            ERR_REPORT(PHG_ERH, ERR900);
         }
         else {
            args.arid = archive_id;
            args.fname = archive_file;
            args.name_length = strlen(archive_file) + 1;
            phg_ar_open(&args, &ret);
            if (ret.err) {
               free(fname);
            }
            else {
               strcpy(fname, archive_file);
               phg_psl_add_ar(PHG_PSL, archive_id, fname);
               PSL_AR_STATE(PHG_PSL) = PST_AROP;
            }

            ERR_FLUSH(PHG_ERH);
         }
      }
   }
}

/*******************************************************************************
 * pclose_ar_file
 *
 * DESCR:       Close archive file
 * RETURNS:     N/A
 */

void pclose_ar_file(
   Pint archive_id
   )
{
   if (phg_entry_check(ERR7, Pfn_close_ar_file)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         phg_ar_close(archive_id);
         phg_psl_rem_ar(PHG_PSL, archive_id);
      }
   }
}

/*******************************************************************************
 * pset_conf_res
 *
 * DESCR:       Set structure conflict resolution for archive
 * RETURNS:     N/A
 */

void pset_conf_res(
   Pconf_res archive_res,
   Pconf_res retrieval_res
   )
{
   if (phg_entry_check(ERR2, Pfn_set_conf_res)) {
      PSL_ARCHIVE_CONFLICT(PHG_PSL) = archive_res;
      PSL_RETRIEVE_CONFLICT(PHG_PSL) = retrieval_res;
   }
}

/*******************************************************************************
 * par_structs
 *
 * DESCR:       Store structures in archive
 * RETURNS:     N/A
 */

void par_structs(
   Pint archive_id,
   Pint_list *struct_ids
   )
{
   Phg_args_ar_info args;

   if (phg_entry_check(ERR7, Pfn_ar_structs)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         args.arid = archive_id;
         memcpy(&args.data, struct_ids, sizeof(Pint_list));
         args.op = PHG_ARGS_AR_STRUCTS;
         args.resflag = PSL_ARCHIVE_CONFLICT(PHG_PSL);
         phg_ar_archive(&args);
      }
   }
}

/*******************************************************************************
 * par_struct_nets
 *
 * DESCR:       Store structure networks in archive
 * RETURNS:     N/A
 */

void par_struct_nets(
   Pint archive_id,
   Pint_list *struct_ids
   )
{
   Phg_args_ar_info args;

   if (phg_entry_check(ERR7, Pfn_ar_struct_nets)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         args.arid = archive_id;
         memcpy(&args.data, struct_ids, sizeof(Pint_list));
         args.op = PHG_ARGS_AR_NETWORKS;
         args.resflag = PSL_ARCHIVE_CONFLICT(PHG_PSL);
         phg_ar_archive(&args);
      }
   }
}

/*******************************************************************************
 * par_all_structs
 *
 * DESCR:       Store all structures in archive
 * RETURNS:     N/A
 */

void par_all_structs(
   Pint archive_id
   )
{
   Phg_args_ar_info args;

   if (phg_entry_check(ERR7, Pfn_ar_all_structs)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         args.arid = archive_id;
         args.op = PHG_ARGS_AR_ALL;
         args.resflag = PSL_ARCHIVE_CONFLICT(PHG_PSL);
         phg_ar_archive(&args);
      }
   }
}

/*******************************************************************************
 * pret_struct_ids
 *
 * DESCR:       Retreive all structures identifiers for archive
 * RETURNS:     N/A
 */

void pret_struct_ids(
   Pint archive_id,
   Pint num_elems_appl_list,
   Pint start_ind,
   Pint_list *ids,
   Pint *num_elems_impl_list
   )
{
   Phg_ret ret;

   if (phg_entry_check(ERR7, Pfn_ret_struct_ids)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         ret.err = 0;
         ids->num_ints = 0;
         *num_elems_impl_list = 0;
         phg_ar_get_names(archive_id, &ret);
         if (ret.err == 0) {
            ids->num_ints = 0;
            *num_elems_impl_list = ret.data.int_list.num_ints;
            if (ret.data.int_list.num_ints > 0) {
               if (start_ind < 0 ||
                   start_ind >= ret.data.int_list.num_ints) {
                  ERR_REPORT(PHG_ERH, ERR2201);
               }
               else if (num_elems_appl_list > 0) {
                  ids->num_ints = PHG_MIN(num_elems_appl_list,
                                          ret.data.int_list.num_ints -
                                             start_ind);
                  memcpy(ids->ints, &ret.data.int_list.ints[start_ind],
                         ids->num_ints * sizeof(Pint));
               }
               else if (num_elems_appl_list < 0) {
                  ERR_REPORT(PHG_ERH, ERRN153);
               }
            }
         }
         ERR_FLUSH(PHG_ERH);
      }
   }
}

/*******************************************************************************
 * pret_structs
 *
 * DESCR:       Retreive structures from archive
 * RETURNS:     N/A
 */

void pret_structs(
   Pint archive_id,
   Pint_list *struct_ids
   )
{
   Phg_args_ar_info args;

   if (phg_entry_check(ERR7, Pfn_ret_structs)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         args.arid = archive_id;
         memcpy(&args.data, struct_ids, sizeof(Pint_list));
         args.op = PHG_ARGS_AR_STRUCTS;
         args.resflag = PSL_RETRIEVE_CONFLICT(PHG_PSL);
         phg_ar_retrieve(&args);
      }
   }
}

/*******************************************************************************
 * pret_struct_nets
 *
 * DESCR:       Retreive structure networks from archive
 * RETURNS:     N/A
 */

void pret_struct_nets(
   Pint archive_id,
   Pint_list *struct_ids
   )
{
   Phg_args_ar_info args;

   if (phg_entry_check(ERR7, Pfn_ret_struct_nets)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         args.arid = archive_id;
         memcpy(&args.data, struct_ids, sizeof(Pint_list));
         args.op = PHG_ARGS_AR_NETWORKS;
         args.resflag = PSL_RETRIEVE_CONFLICT(PHG_PSL);
         phg_ar_retrieve(&args);
      }
   }
}

/*******************************************************************************
 * pret_all_structs
 *
 * DESCR:       Retreive all structures from archive
 * RETURNS:     N/A
 */

void pret_all_structs(
   Pint archive_id
   )
{
   Phg_args_ar_info args;

   if (phg_entry_check(ERR7, Pfn_ret_all_structs)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         args.arid = archive_id;
         args.op = PHG_ARGS_AR_ALL;
         args.resflag = PSL_RETRIEVE_CONFLICT(PHG_PSL);
         phg_ar_retrieve(&args);
      }
   }
}

/*******************************************************************************
 * pdel_structs_ar
 *
 * DESCR:       Delete structures from archive
 * RETURNS:     N/A
 */

void pdel_structs_ar(
   Pint archive_id,
   Pint_list *struct_ids
   )
{
   Phg_args_ar_info args;

   if (phg_entry_check(ERR7, Pfn_del_structs_ar)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         args.arid = archive_id;
         memcpy(&args.data, struct_ids, sizeof(Pint_list));
         args.op = PHG_ARGS_AR_STRUCTS;
         phg_ar_delete(&args);
      }
   }
}

/*******************************************************************************
 * pdel_struct_nets_ar
 *
 * DESCR:       Delete structure networks from archive
 * RETURNS:     N/A
 */

void pdel_struct_nets_ar(
   Pint archive_id,
   Pint_list *struct_ids
   )
{
   Phg_args_ar_info args;

   if (phg_entry_check(ERR7, Pfn_del_struct_nets_ar)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         args.arid = archive_id;
         memcpy(&args.data, struct_ids, sizeof(Pint_list));
         args.op = PHG_ARGS_AR_NETWORKS;
         phg_ar_delete(&args);
      }
   }
}

/*******************************************************************************
 * pdel_all_structs_ar
 *
 * DESCR:       Delete all structures from archive
 * RETURNS:     N/A
 */

void pdel_all_structs_ar(
   Pint archive_id
   )
{
   Phg_args_ar_info args;

   if (phg_entry_check(ERR7, Pfn_del_all_structs_ar)) {
      if (PSL_AR_STATE(PHG_PSL) != PST_AROP) {
         ERR_REPORT(PHG_ERH, ERR7);
      }
      else if (!phg_psl_inq_ar_open(PHG_PSL, archive_id)) {
         ERR_REPORT(PHG_ERH, ERR404);
      }
      else {
         args.arid = archive_id;
         args.op = PHG_ARGS_AR_ALL;
         phg_ar_delete(&args);
      }
   }
}

/*******************************************************************************
 * pinq_ar_st
 *
 * DESCR:       Get archive state
 * RETURNS:     N/A
 */

void pinq_ar_st(
   Par_st *ar_st
   )
{
   if (phg_entry_check(0, Pfn_INQUIRY)) {
      *ar_st = PSL_AR_STATE(PHG_PSL);
   }
   else {
      *ar_st = PST_ARCL;
   }
}

/*******************************************************************************
 * pinq_conf_res
 *
 * DESCR:       Get archive conflict resolution
 * RETURNS:     N/A
 */

void pinq_conf_res(
   Pint *err_ind,
   Pconf_res *archive_res,
   Pconf_res *retrieval_res
   )
{
   if (phg_entry_check(0, Pfn_INQUIRY)) {
      *err_ind = 0;
      *archive_res = PSL_ARCHIVE_CONFLICT(PHG_PSL);
      *retrieval_res = PSL_RETRIEVE_CONFLICT(PHG_PSL);
   }
   else {
      *err_ind = ERR2;
   }
}

