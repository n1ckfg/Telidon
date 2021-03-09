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

#ifndef _err_h
#define _err_h

typedef struct {
    Pint errnum;
    Pint funcnum;
} Err_msg;

typedef struct {
    char *fname;
} Err_local_data;

typedef struct {
    int  sfd;
    char *fname;
} Err_client_data;

typedef struct {
    int sfd;
} Err_remote_data;

typedef struct {
    Perr_mode mode;
    Perr_mode err_state;
    int       cur_func_num;
    int       errno;
    void      (*buf_func)();
    void      (*flush_func)();
    void      (*report_func)();
    void      (*destroy_func)();
    union {
	Err_local_data  local;
	Err_client_data	client;
	Err_remote_data remote;
    } data;
} Err_struct;

typedef Err_struct *Err_handle;

extern void (*phg_errhandle)();

#define ERR_SET_CUR_FUNC(erh, funcnum) \
    ((erh)->cur_func_num = (funcnum))

#define ERR_BUF(erh, errnum) \
    if ((erh)->mode == PERR_ON) (*(erh)->buf_func)((erh), (errnum))

#define ERR_FLUSH(erh) \
    if ((erh)->flush_func) (*(erh)->flush_func)(erh)

#define ERR_HANDLE(errnum, funcnum, erf) \
    (*phg_errhandle)((errnum), (funcnum), (erf))

#define ERR_REPORT(erh, errnum) \
    if ((erh)->mode == PERR_ON && (erh)->report_func) \
       (*(erh)->report_func)((erh), (errnum))

#define ERR_DESTROY(erh) \
    if ((erh)->destroy_func) (*(erh)->destroy_func)(erh)

/*******************************************************************************
 * phg_erh_create
 *
 * DESCR:       Create error handler
 * RETURNS:     Pointer to handler or NULL
 */

Err_handle phg_erh_create(
   char *err_file
   );

/*******************************************************************************
 * phg_erh_init
 *
 * DESCR:       Initialize error handler
 * RETURNS:     TRUE or FALSE
 */

int phg_erh_init(
   Err_handle erh,
   char *err_file
   );

/*******************************************************************************
 * phg_erh_destroy
 * 
 * DESCR:       Initialize error handler
 * RETURNS:     TRUE or FALSE
 */
 
void phg_erh_destroy(
   Err_handle erh
   );

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
   );

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
   );

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
   );

/*******************************************************************************
 * pset_err_hand
 *
 * DESCR:       Set error handler
 * RETURNS:     N/A
 */

void pset_err_hand(
   void (*new_err_hand)(),
   void (**old_err_hand)()
   );

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
   );

#endif
