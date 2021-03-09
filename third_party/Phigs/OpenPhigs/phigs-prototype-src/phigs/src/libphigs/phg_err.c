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
#include <string.h>
#include <phigs/phigs.h>
#include <phigs/phg.h>
#include <phigs/err.h>
#include <phigs/private/errP.h>

void (*phg_errhandle)() = perr_hand;

#define MSG_BUF_SIZE 255

/*******************************************************************************
 * err_buf_local
 *
 * DESCR:       Local error buffer function
 * RETURNS:     N/A
 */

static void err_buf_local(
   Err_handle erh,
   Pint errnum
   )
{
   ERR_HANDLE(errnum, erh->cur_func_num, erh->data.local.fname);
}

/*******************************************************************************
 * err_flush_local
 *
 * DESCR:       Local error flush function
 * RETURNS:     N/A
 */

static void err_flush_local(
   Err_handle erh
   )
{
   fflush(stderr);
}

/*******************************************************************************
 * err_destroy_local
 *
 * DESCR:       Local error destroy function
 * RETURNS:     N/A
 */

static void err_destroy_local(
   Err_handle erh
   )
{
   if (erh->data.local.fname) {
      free(erh->data.local.fname);
   }
}

/*******************************************************************************
 * phg_erh_create
 *
 * DESCR:       Create error handler
 * RETURNS:     Pointer to handler or NULL
 */

Err_handle phg_erh_create(
   char *err_file
   )
{
   Err_handle erh;

   erh = (Err_handle) malloc(sizeof(Err_struct));
   if (erh == NULL)
      return NULL;

   if (!phg_erh_init(erh, err_file)) {
      ERR_HANDLE(ERR900, Pfn_open_phigs, err_file);
      free(erh);
      return NULL;
   }

   return erh;
}

/*******************************************************************************
 * phg_erh_init
 *
 * DESCR:       Initialize error handler
 * RETURNS:     TRUE or FALSE
 */

int phg_erh_init(
   Err_handle erh,
   char *err_file
   )
{
   int status;

   erh->mode          = PERR_ON;
   erh->err_state     = PERR_ON;
   erh->cur_func_num  = Pfn_open_phigs;
   erh->buf_func      = err_buf_local;
   erh->flush_func    = err_flush_local;
   erh->report_func   = err_buf_local;
   erh->destroy_func  = err_destroy_local;

   if (!phg_err_store_name(erh, err_file, &erh->data.local.fname)) {
      status = FALSE;
   }
   else {
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * phg_erh_destroy
 *
 * DESCR:       Initialize error handler
 * RETURNS:     TRUE or FALSE
 */

void phg_erh_destroy(
   Err_handle erh
   )
{
   ERR_DESTROY(erh);

   if (erh != NULL)
      free(erh);
}

/*******************************************************************************
 * phg_err_store_name
 *
 * DESCR:       Store error filename, err_file == NULL means stderr
 * RETURNS:     TRUE or FALSE
 */

int phg_err_store_name(
   Err_handle erh,
   char *err_file,
   char **ptr
   )
{
   int status = FALSE;

   if (err_file != NULL) {
      *ptr = (char *) malloc(strlen(err_file) + 1);
      if (*ptr != NULL) {
         strcpy(*ptr, err_file);
         status = TRUE;
      }
      else {
         status = FALSE;
      }
   }
   else {
      *ptr = NULL;
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * phg_format_err_msg
 *
 * DESCR:       Create error message and place it in buffer
 * RETURNS:     N/A
 */

void phg_format_err_msg(
   Pint binding,
   Pint errnum,
   Pint funcnum,
   char *buf
   )
{
   char *errmsg, *funcname;
   char noerrmsg[] = "Unknown Error";
   char nofuncname[] = "Unknown Function";

   errmsg = phg_get_errmsg(errnum);
   if (errmsg == NULL) {
      errmsg = noerrmsg;
   }

   funcname = phg_get_funcname(funcnum);
   if (funcname == NULL) {
      funcname = nofuncname;
   }

   sprintf(buf, "%s: %s\n", funcname, errmsg);
}

/*******************************************************************************
 * perr_log
 *
 * DESCR:       Log error
 * RETURNS:     N/A
 */

void perr_log(
   Pint errnum,
   Pint funcnum,
   char *fname
   )
{
   FILE *erf;
   char msg_buf[MSG_BUF_SIZE];

   phg_format_err_msg(0, errnum, funcnum, msg_buf);
   if (fname != NULL) {
      erf = fopen(fname, "a");
      if (erf != NULL) {
         fprintf(erf, "%s", msg_buf);
         fclose(erf);
      }
      else {
         fprintf(stderr, "%s", msg_buf);
      }
   }
   else {
      fprintf(stderr, "%s", msg_buf);
   }
}

/*******************************************************************************
 * pset_err_hand
 *
 * DESCR:       Set error handler
 * RETURNS:     N/A
 */

void pset_err_hand(
   void (*new_err_hand)(),
   void (**old_err_hand)()
   )
{
   *old_err_hand = phg_errhandle;
   phg_errhandle = new_err_hand;
}

/*******************************************************************************
 * perr_hand
 *
 * DESCR:       Handle error
 * RETURNS:     N/A
 */

void perr_hand(
   Pint errnum,
   Pint funcnum,
   char *fname
   )
{
   perr_log(errnum, funcnum, fname);
}

