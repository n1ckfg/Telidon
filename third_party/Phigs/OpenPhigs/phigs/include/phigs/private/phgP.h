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

#ifndef _phgP_h
#define _phgP_h

#include <stdio.h>
#include <stdlib.h>
#include <phigs/ws.h>
#include <phigs/phg.h>
#include <phigs/private/cssP.h>

#define ARGS_ELMT_SIZE(ARG) \
   ((Phg_args_add_el *) (ARG))->el_size

#define ARGS_ELMT_SIZE_FULL(ARG) \
   (((Phg_args_add_el *) (ARG))->el_size + sizeof(Phg_elmt_info))

#define ARGS_ELMT_TYPE(ARG) \
   ((Phg_args_add_el *) (ARG))->el_type

#define ARGS_ELMT_DATA(ARG) \
   ((Phg_args_add_el *) (ARG))->el_data

#define ARGS_COPY_DATA(ELMT) \
   (Phg_elmt_info *) (((Css_eldata *) (ELMT))->ptr)

#define ARGS_COPY_DATA_LEN(ELMT) \
   (((Phg_elmt_info *) (((Css_eldata *) (ELMT))->ptr))->length + \
      sizeof(Phg_elmt_info))

#define ARGS_INQ_HEAD(ARG) \
   (((Phg_ret_q_content *) argdata)->el_head)

#define ARGS_INQ_SIZE(ARG) \
   *((Pint *) argdata)

#define ELMT_HEAD(ELMT) \
   ((ELMT)->eldata.ptr)

#define ELMT_INFO(ELMT) \
   ((Phg_elmt_info *) (ELMT)->eldata.ptr)

#define ELMT_INFO_LEN(ELMT) \
   (((Phg_elmt_info *) (ELMT)->eldata.ptr)->length)

#define ELMT_CONTENT(ELMT) \
   (((Phg_elmt_info *) (ELMT)->eldata.ptr) + 1)

#define PHG_LOCAL_TRAN3(ELMT) \
   ((Plocal_tran3 *) ELMT_CONTENT(ELMT))

#define PHG_INT(ELMT) \
   *((Pint *) ELMT_CONTENT(ELMT))

#define PHG_FLOAT(ELMT) \
   *((Pfloat *) ELMT_CONTENT(ELMT))

#define PHG_IN_RANGE( low, high, val) \
   ((val) >= (low) && (val) <= (high))

#define PHG_ECHO_AREA_VALID( _ev ) \
   (   (_ev)->x_min < (_ev)->x_max \
    && (_ev)->y_min < (_ev)->y_max \
   )

#define PHG_ECHO_VOLUME_VALID( _ev ) \
   (   (_ev)->x_min < (_ev)->x_max \
    && (_ev)->y_min < (_ev)->y_max \
    && (_ev)->z_min <= (_ev)->z_max \
   )

#define PHG_ECHO_AREA_IN_RANGE( _ea, _dc ) \
   (   PHG_IN_RANGE( 0.0, (_dc)[0], (_ea)->x_min) \
    && PHG_IN_RANGE( 0.0, (_dc)[0], (_ea)->x_max) \
    && PHG_IN_RANGE( 0.0, (_dc)[1], (_ea)->y_min) \
    && PHG_IN_RANGE( 0.0, (_dc)[1], (_ea)->y_max) \
   )

#define PHG_ECHO_VOLUME_IN_RANGE( _ea, _dc ) \
   (   PHG_IN_RANGE( 0.0, (_dc)[0], (_ea)->x_min) \
    && PHG_IN_RANGE( 0.0, (_dc)[0], (_ea)->x_max) \
    && PHG_IN_RANGE( 0.0, (_dc)[1], (_ea)->y_min) \
    && PHG_IN_RANGE( 0.0, (_dc)[1], (_ea)->y_max) \
    && PHG_IN_RANGE( 0.0, (_dc)[2], (_ea)->z_min) \
    && PHG_IN_RANGE( 0.0, (_dc)[2], (_ea)->z_max) \
   )

/*******************************************************************************
 * phg_get_colr_ind
 *
 * DESCR:       Get colour from index
 * RETURNS:     N/A
 */

void phg_get_colr_ind(
   Ws *ws,
   Pgcolr *gcolr,
   Pint ind
   );

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
   );

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
   );

extern Phg_font phg_mroman;
extern Phg_font phg_roman;

#endif

