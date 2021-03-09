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
#include <phigs/private/sinqP.h>
#include <phigs/private/wsxP.h>

/*******************************************************************************
 * input_ws_open
 *
 * DESCR:       Open input workstation desciption helper function
 * RETURNS:     Pointer to input description or NULL
 */

static Wst_input_wsdt* input_ws_open(
   Pint ws_id,
   Pint fn_id,
   Wst_phigs_dt **dtp,
   Pint *err_ind
   )
{
   Psl_ws_info *wsinfo;
   Wst_phigs_dt *dt;
   Wst_input_wsdt *idt = NULL;

   if (err_ind == NULL) {
      ERR_SET_CUR_FUNC(PHG_ERH, fn_id);
   }

   if (PSL_WS_STATE(PHG_PSL) != PWS_ST_WSOP) {
       if (err_ind == NULL) {
          ERR_REPORT(PHG_ERH, ERR3);
       }
       else {
          *err_ind = ERR3;
       }
   }
   else {
      wsinfo = phg_psl_get_ws_info(PHG_PSL, ws_id);
      if (wsinfo == NULL) {
         if (err_ind == NULL) {
            ERR_REPORT(PHG_ERH, ERR54);
         }
         else {
            *err_ind = ERR54;
         }
      }
      else {
         dt = &wsinfo->wstype->desc_tbl.phigs_dt;
         if (!((dt->ws_category == PCAT_OUTIN) ||
               (dt->ws_category == PCAT_IN))) {
            if (err_ind == NULL) {
               ERR_REPORT(PHG_ERH, ERR61);
            }
            else {
               *err_ind = ERR61;
            }
         }
         else {
            idt = &wsinfo->wstype->desc_tbl.phigs_dt.in_dt;
            if (dtp != NULL) {
               *dtp = dt;
            }
         }
      }
   }

   return idt;
}

/*******************************************************************************
 * check_loc_data_record
 *
 * DESCR:       Check locator data record helper function
 * RETURNS:     TRUE or FALSE
 */

static int check_loc_data_record(
   Pint pet,
   Ploc_data3 *loc_data,
   Wst_phigs_dt *dt,
   Wst_defloc *ddt
   )
{
   int status;

   switch (pet) {
      case 1:
      case 2:
      case 3:
         /* No data */
         status = TRUE;
         break;

      default:
         status = FALSE;
         break;
   }

   return status;
}

/*******************************************************************************
 * pinit_loc3
 *
 * DESCR:       Initialize locator device 3D
 * RETURNS:     N/A
 */

void pinit_loc3(
   Pint ws_id,
   Pint loc_num,
   Pint init_view_ind,
   Ppoint3 *init_loc_pos,
   Pint pet,
   Plimit3 *echo_vol,
   Ploc_data3 *loc_data
   )
{
   Wst_input_wsdt *idt;
   Wst_phigs_dt *dt;
   Wst_defloc *ddt;
   Phg_args_inp_init_dev args;
   Ws_handle wsh;

   idt = input_ws_open(ws_id, Pfn_init_loc3, &dt, NULL);
   if (idt != NULL) {
      if ((loc_num > 0) &&  (loc_num <= idt->num_devs.loc)) {
         if (phg_echo_limits_valid(ws_id, Pfn_init_loc3, echo_vol, dt)) {
            /* TODO: Also check against maximum view index */
            if (init_view_ind >= 0) {
               ddt = &idt->locators[loc_num - 1];
               if (!phg_int_in_list(pet, ddt->num_pets, ddt->pets)) {
                  /* Report error and use default data */
                  ERR_REPORT(PHG_ERH, ERR253);
                  loc_data = &ddt->record;
                  pet = 1;
               }
               if (check_loc_data_record(pet, loc_data, dt, ddt)) {
                  args.wsid                   = ws_id;
                  args.idev_class             = PHG_ARGS_INP_LOC3;
                  args.dev                    = loc_num;
                  args.pet                    = pet;
                  args.data.loc.init.view_ind = init_view_ind;
                  memcpy(&args.data.loc.init.position,
                         init_loc_pos,
                         sizeof(Ppoint3));
                  memcpy(&args.echo_volume,
                         echo_vol,
                         sizeof(Plimit3));
                  memcpy(&args.data.loc.rec,
                         loc_data,
                         sizeof(Ploc_data3));
                  wsh = PHG_WSID(ws_id);
                  (*wsh->init_device)(wsh, &args);
               }
               else {
                  ERR_REPORT(PHG_ERH, ERR260);
               }
            }
            else {
               ERR_REPORT(PHG_ERH, ERR114);
            }
         }
         /* Error reported by phg_echo_limits_valid */
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * check_stroke_data_record
 *
 * DESCR:       Check stroke data record helper function
 * RETURNS:     TRUE or FALSE
 */

static int check_stroke_data_record(
   Pint pet,
   Pstroke_data3 *stroke_data,
   Wst_phigs_dt *dt,
   Wst_defstroke *ddt
   )
{
   int status;

   if ((stroke_data->buffer_size < 1) ||
       (stroke_data->buffer_size > ddt->max_bufsize)) {
      status = FALSE;
   }
   else if ((stroke_data->init_pos < 1) ||
            (stroke_data->init_pos > ddt->max_bufsize)) {
      status = FALSE;
   }
   else {
      status = TRUE;
   }

   return status;
}

/*******************************************************************************
 * pinit_stroke3
 *
 * DESCR:       Initialize stroke device 3D
 * RETURNS:     N/A
 */

void pinit_stroke3(
   Pint ws_id,
   Pint stroke_num,
   Pint init_view_ind,
   Ppoint_list3 *init_stroke,
   Pint pet,
   Plimit3 *echo_vol,
   Pstroke_data3 *stroke_data
   )
{
   Wst_input_wsdt *idt;
   Wst_phigs_dt *dt;
   Wst_defstroke *ddt;
   Phg_args_inp_init_dev args;
   Ws_handle wsh;

   idt = input_ws_open(ws_id, Pfn_init_stroke3, &dt, NULL);
   if (idt != NULL) {
      if ((stroke_num > 0) &&  (stroke_num <= idt->num_devs.stroke)) {
         if (phg_echo_limits_valid(ws_id, Pfn_init_stroke3, echo_vol, dt)) {
            /* TODO: Also check against maximum view index */
            if (init_view_ind >= 0) {
               ddt = &idt->strokes[stroke_num - 1];
               if (!phg_int_in_list(pet, ddt->num_pets, ddt->pets)) {
                  /* Report error and use default data */
                  ERR_REPORT(PHG_ERH, ERR253);
                  stroke_data = &ddt->record;
                  pet = 1;
               }
               if (check_stroke_data_record(pet, stroke_data, dt, ddt)) {
                  if (init_stroke->num_points < stroke_data->buffer_size) {
                     args.wsid                     = ws_id;
                     args.idev_class               = PHG_ARGS_INP_STK3;
                     args.dev                      = stroke_num;
                     args.pet                      = pet;
                     args.data.stk.init.view_ind   = init_view_ind;
                     args.data.stk.init.num_points = init_stroke->num_points;
                     args.data.stk.init.points     = init_stroke->points;
                     memcpy(&args.echo_volume,
                            echo_vol,
                            sizeof(Plimit3));
                     memcpy(&args.data.stk.rec,
                            stroke_data,
                            sizeof(Pstroke_data3));
                     wsh = PHG_WSID(ws_id);
                     (*wsh->init_device)(wsh, &args);
                  }
                  else {
                     ERR_REPORT(PHG_ERH, ERR262);
                  }
               }
               else {
                  ERR_REPORT(PHG_ERH, ERR260);
               }
            }
            else {
               ERR_REPORT(PHG_ERH, ERR114);
            }
         }
         /* Error reported by phg_echo_limits_valid */
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * check_pick_data_record
 *
 * DESCR:       Check pick data record helper function
 * RETURNS:     TRUE or FALSE
 */

static int check_pick_data_record(
   Pint pet,
   Ppick_data3 *stroke_data,
   Wst_phigs_dt *dt,
   Wst_defpick *ddt
   )
{
   int status;

   switch (pet) {
      case 1:
      case 2:
      case 3:
         /* No data */
         status = TRUE;
         break;

      default:
         status = FALSE;
         break;
   }

   return status;
}

/*******************************************************************************
 * pinit_pick3
 *
 * DESCR:       Initialize pick device 3D
 * RETURNS:     N/A
 */

void pinit_pick3(
   Pint ws_id,
   Pint pick_num,
   Pin_status init_status,
   Ppick_path *init_pick,
   Pint pet,
   Plimit3 *echo_vol,
   Ppick_data3 *pick_data,
   Ppath_order order
   )
{
   Wst_input_wsdt *idt;
   Wst_phigs_dt *dt;
   Wst_defpick *ddt;
   Phg_args_inp_init_dev args;
   Ws_handle wsh;

   /* TODO: Change to only accept outin workstations */
   idt = input_ws_open(ws_id, Pfn_init_pick3, &dt, NULL);
   if (idt != NULL) {
      if ((pick_num > 0) &&  (pick_num <= idt->num_devs.pick)) {
         if (phg_echo_limits_valid(ws_id, Pfn_init_pick3, echo_vol, dt)) {
            ddt = &idt->picks[pick_num - 1];
            if (!phg_int_in_list(pet, ddt->num_pets, ddt->pets)) {
               /* Report error and use default data */
               ERR_REPORT(PHG_ERH, ERR253);
               pick_data = &ddt->record;
               pet = 1;
            }
            if (check_pick_data_record(pet, pick_data, dt, ddt)) {
               args.wsid                   = ws_id;
               args.idev_class             = PHG_ARGS_INP_PIK3;
               args.dev                    = pick_num;
               args.pet                    = pet;
               args.data.pik.init.status   = init_status;
               if (init_status == PIN_STATUS_OK) {
                  memcpy(&args.data.pik.init.pick_path,
                         init_pick,
                         sizeof(Ppick_path));
               }
               else {
                  args.data.pik.init.pick_path.depth = 0;
               }
               memcpy(&args.echo_volume,
                      echo_vol,
                      sizeof(Plimit3));
               memcpy(&args.data.pik.rec,
                      pick_data,
                      sizeof(Ppick_data3));
               args.data.pik.porder = order;
               wsh = PHG_WSID(ws_id);
               (*wsh->init_device)(wsh, &args);
               }
            else {
               ERR_REPORT(PHG_ERH, ERR260);
            }
         }
         /* Error reported by phg_echo_limits_valid */
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * pset_pick_filter
 *
 * DESCR:       Set pick device filter
 * RETURNS:     N/A
 */

void pset_pick_filter(
   Pint ws_id,
   Pint pick_num,
   Pfilter *filter
   )
{
   Wst_input_wsdt *idt;
   Ws_handle wsh;

   /* TODO: Change to only accept outin workstations */
   idt = input_ws_open(ws_id, Pfn_set_pick_filter, NULL, NULL);
   if (idt != NULL) {
      if ((pick_num > 0) &&  (pick_num <= idt->num_devs.pick)) {
         wsh = PHG_WSID(ws_id);
         (*wsh->set_filter)(wsh,
                            PHG_ARGS_FLT_PICK,
                            pick_num,
                            &filter->incl_set,
                            &filter->excl_set
                            );
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * set_mode
 *
 * DESCR:       Set mode helper function
 * RETURNS:     N/A
 */

static void set_mode(
   Pint ws_id,
   Phg_args_idev_class dev_class,
   Pint dev_num,
   Pop_mode op_mode,
   Pecho_switch echo_switch
   )
{
   Phg_args_set_mode_data args;

   /* The calling function shall always check the requested workstation first */
   Ws_handle wsh = PHG_WSID(ws_id);

   args.idev_class = dev_class;
   args.dev = dev_num;
   args.mode = op_mode;
   args.echo = echo_switch;

   (*wsh->set_device_mode)(wsh, &args);
}

/*******************************************************************************
 * pset_loc_mode
 *
 * DESCR:       Set locator input device mode
 * RETURNS:     N/A
 */

void pset_loc_mode(
   Pint ws_id,
   Pint loc_num,
   Pop_mode op_mode,
   Pecho_switch echo_switch
   )
{
   Wst_input_wsdt *idt;

   idt = input_ws_open(ws_id, Pfn_set_loc_mode, NULL, NULL);
   if (idt != NULL) {
      if ((loc_num > 0) &&  (loc_num <= idt->num_devs.loc)) {
         set_mode(ws_id, PHG_ARGS_INP_LOC, loc_num, op_mode, echo_switch);
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * pset_stroke_mode
 *
 * DESCR:       Set stroke input device mode
 * RETURNS:     N/A
 */

void pset_stroke_mode(
   Pint ws_id,
   Pint stroke_num,
   Pop_mode op_mode,
   Pecho_switch echo_switch
   )
{
   Wst_input_wsdt *idt;

   idt = input_ws_open(ws_id, Pfn_set_stroke_mode, NULL, NULL);
   if (idt != NULL) {
      if ((stroke_num > 0) &&  (stroke_num <= idt->num_devs.stroke)) {
         set_mode(ws_id, PHG_ARGS_INP_STK, stroke_num, op_mode, echo_switch);
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * pset_pick_mode
 *
 * DESCR:       Set pick input device mode
 * RETURNS:     N/A
 */

void pset_pick_mode(
   Pint ws_id,
   Pint pick_num,
   Pop_mode op_mode,
   Pecho_switch echo_switch
   )
{
   Wst_input_wsdt *idt;

   idt = input_ws_open(ws_id, Pfn_set_stroke_mode, NULL, NULL);
   if (idt != NULL) {
      if ((pick_num > 0) &&  (pick_num <= idt->num_devs.pick)) {
         set_mode(ws_id, PHG_ARGS_INP_PIK, pick_num, op_mode, echo_switch);
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * sample_device
 *
 * DESCR:       Sample device helper function
 * RETURNS:     N/A
 */

static void sample_device(
   Pint ws_id,
   Pint dev_num,
   Phg_args_idev_class dev_class,
   Phg_ret *ret
   )
{
   Ws_handle wsh;

   /* The calling function shall always check the requested workstation first */
   wsh = PHG_WSID(ws_id);

   /* Process all events for workstation */
   while (phg_wsx_input_dispatch_next(wsh, PHG_EVT_TABLE));

   (*wsh->sample_device)(wsh, dev_class, dev_num, ret);
}

/*******************************************************************************
 * psample_loc
 *
 * DESCR:       Sample locator device
 * RETURNS:     N/A
 */

void psample_loc(
   Pint ws_id,
   Pint loc_num,
   Pint *view_ind,
   Ppoint *loc_pos
   )
{
   Phg_ret ret;
   Wst_input_wsdt *idt;

   idt = input_ws_open(ws_id, Pfn_sample_loc, NULL, NULL);
   if (idt != NULL) {
      if ((loc_num > 0) &&  (loc_num <= idt->num_devs.loc)) {
         sample_device(ws_id, loc_num, PHG_ARGS_INP_LOC, &ret);
         if (ret.err == 0) {
            *view_ind = ret.data.inp_event.data.loc.view_ind;
            loc_pos->x = ret.data.inp_event.data.loc.position.x;
            loc_pos->y = ret.data.inp_event.data.loc.position.y;
         }
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * psample_loc3
 *
 * DESCR:       Sample locator device 3D
 * RETURNS:     N/A
 */

void psample_loc3(
   Pint ws_id,
   Pint loc_num,
   Pint *view_ind,
   Ppoint3 *loc_pos
   )
{
   Phg_ret ret;
   Wst_input_wsdt *idt;

   idt = input_ws_open(ws_id, Pfn_sample_loc3, NULL, NULL);
   if (idt != NULL) {
      if ((loc_num > 0) &&  (loc_num <= idt->num_devs.loc)) {
         sample_device(ws_id, loc_num, PHG_ARGS_INP_LOC3, &ret);
         if (ret.err == 0) {
            *view_ind = ret.data.inp_event.data.loc.view_ind;
            memcpy(loc_pos,
                   &ret.data.inp_event.data.loc.position,
                   sizeof(Ppoint3));
         }
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * psample_stroke
 *
 * DESCR:       Sample stroke device
 * RETURNS:     N/A
 */

void psample_stroke(
   Pint ws_id,
   Pint stroke_num,
   Pint *view_ind,
   Ppoint_list *stroke
   )
{
   int i;
   Phg_ret ret;
   Wst_input_wsdt *idt;
   Pstroke3 *stk;

   idt = input_ws_open(ws_id, Pfn_sample_stroke, NULL, NULL);
   if (idt != NULL) {
      if ((stroke_num > 0) &&  (stroke_num <= idt->num_devs.stroke)) {
         sample_device(ws_id, stroke_num, PHG_ARGS_INP_STK, &ret);
         if (ret.err == 0) {
            stk = &ret.data.inp_event.data.stk;
            *view_ind = stk->view_ind;
            stroke->num_points = stk->num_points;
            if (stk->num_points > 0) {
               for (i = 0; i < stk->num_points; i++) {
                  stroke->points[i].x = stk->points[i].x;
                  stroke->points[i].y = stk->points[i].y;
               }
            }
            else {
               stroke->num_points = 0;
            }
         }
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * psample_stroke3
 *
 * DESCR:       Sample stroke device 3D
 * RETURNS:     N/A
 */

void psample_stroke3(
   Pint ws_id,
   Pint stroke_num,
   Pint *view_ind,
   Ppoint_list3 *stroke
   )
{
   Phg_ret ret;
   Wst_input_wsdt *idt;
   Pstroke3 *stk;

   idt = input_ws_open(ws_id, Pfn_sample_stroke3, NULL, NULL);
   if (idt != NULL) {
      if ((stroke_num > 0) &&  (stroke_num <= idt->num_devs.stroke)) {
         sample_device(ws_id, stroke_num, PHG_ARGS_INP_STK3, &ret);
         if (ret.err == 0) {
            stk = &ret.data.inp_event.data.stk;
            *view_ind = stk->view_ind;
            stroke->num_points = stk->num_points;
            if (stk->num_points > 0) {
               memcpy(&stroke->points,
                      &stk->points,
                      stk->num_points * sizeof(Ppoint3));
            }
            else {
               stroke->num_points = 0;
            }
         }
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * psample_pick
 *
 * DESCR:       Sample pick device
 * RETURNS:     N/A
 */

void psample_pick(
   Pint ws_id,
   Pint pick_num,
   Pint depth,
   Pin_status *pick_in_status,
   Ppick_path *pick
   )
{
   Phg_ret ret;
   Wst_input_wsdt *idt;
   Ppick *pik;
   Pint depth_limit;

   idt = input_ws_open(ws_id, Pfn_sample_pick, NULL, NULL);
   if (idt != NULL) {
      if ((pick_num > 0) &&  (pick_num <= idt->num_devs.pick)) {
         sample_device(ws_id, pick_num, PHG_ARGS_INP_PIK, &ret);
         if (ret.err == 0) {
            pik = &ret.data.inp_event.data.pik;
            *pick_in_status = pik->status;
            if (pik->status == PIN_STATUS_OK) {
               pick->depth = pik->pick_path.depth;
               depth_limit = PHG_MIN(depth, pik->pick_path.depth);
               if (depth_limit > 0) {
                  memcpy(pick->path_list,
                         pik->pick_path.path_list,
                         depth_limit * sizeof(Ppick_path_elem));
               }
            }
         }
         else {
            *pick_in_status = PIN_STATUS_NONE;
         }
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * inp_dispatch_next
 *
 * DESCR:       Dispatch next event for all open input workstations
 * RETURNS:     TRUE or FALSE
 */

int inp_dispatch_next(
   Pint fn_id
   )
{
   Pint i, err_ind;
   Wst_input_wsdt *idt;
   Wst_phigs_dt *dt;
   Ws_handle wsh;
   int status = FALSE;

   for (i = 0; i < MAX_NO_OPEN_WS; i++) {
      idt = input_ws_open(i, fn_id, &dt, &err_ind);
      if (idt != NULL) {
         if ((dt->ws_category == PCAT_IN) ||
             (dt->ws_category == PCAT_OUTIN)) {
            wsh = PHG_WSID(i);
            status = phg_wsx_input_dispatch_next(wsh, PHG_EVT_TABLE);
         }
      }
   }

   return status;
}

/*******************************************************************************
 * inp_event_poll
 *
 * DESCR:       Poll input events helper function
 * RETURNS:     N/A
 */

static void inp_event_poll(
   Phg_ret *ret
   )
{
   unsigned size;
   Ppick *pick;
   Sin_input_event *event;
   Pevent *ev_id = &ret->data.inp_event.id;
   Phg_inp_event_data *ed = &ret->data.inp_event.data;

   ret->err = 0;
   event = phg_sin_q_next_event(PHG_INPUT_Q);
   if (event != NULL) {
      if (SIN_Q_OVERFLOWED(PHG_INPUT_Q)) {
         ERR_BUF(PHG_ERH, ERR256);
      }
      ev_id->ws = event->wsid;
      ev_id->dev = event->dev_num;
      ev_id->in_class = event->dev_class;
      SIN_Q_SET_CUR_SIMUL_ID(PHG_INPUT_Q, event);

      switch (ev_id->in_class) {
         case PIN_LOC:
            ed->loc = event->data.locator.evt;
            break;

         case PIN_STROKE:
            size = event->data.stroke.evt.num_points * sizeof(Ppoint3);
            if ((size > 0) && (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, size))) {
               ERR_BUF(PHG_ERH, ERR900);
               ret->err = ERR900;
               free(ed->stk.points);
            }
            else {
               ed->stk = event->data.stroke.evt;
               if (size > 0) {
                  memcpy(PHG_SCRATCH.buf, ed->stk.points, size);
                  free(ed->stk.points);
                  ed->stk.points = (Ppoint3 *) PHG_SCRATCH.buf;
               }
            }
            break;

         case PIN_PICK:
            pick = &event->data.pick.evt;
            ed->pik = *pick;
            if (pick->status == PIN_STATUS_OK) {
               size = pick->pick_path.depth * sizeof(Ppick_path_elem);
               if ((size > 0) && (!PHG_SCRATCH_SPACE(&PHG_SCRATCH, size))) {
                  ERR_BUF(PHG_ERH, ERR900);
                  ret->err = ERR900;
                  free(pick->pick_path.path_list);
               }
               else if (size > 0) {
                  memcpy(PHG_SCRATCH.buf, pick->pick_path.path_list, size);
                  free(pick->pick_path.path_list);
                  ed->pik.pick_path.path_list = (Ppick_path_elem *)
                     PHG_SCRATCH.buf;
               }
            }
            break;

         /* TODO: Check what is needed to copy for other device types */

         default:
            break;
      }

      phg_sin_q_deque_event(PHG_INPUT_Q);
   }
   else {
      ev_id->in_class = PIN_NONE;
      if (SIN_Q_OVERFLOWED(PHG_INPUT_Q)) {
         SIN_Q_CLEAR_OVERFLOW(PHG_INPUT_Q);
      }
   }
}

/*******************************************************************************
 * pawait_event
 *
 * DESCR:       Wait for event to occur
 * RETURNS:     N/A
 */

void pawait_event(
   Pfloat timeout,
   Pint *ws_id,
   Pin_class *dev_class,
   Pint *in_num
   )
{
   Phg_ret ret;
   unsigned size;
   Ppoint3 *pts;
   Ppick_path_elem *path;
   time_t time, time1, time2;
   time_t limit = (time_t) (timeout * 1000.0);
   Phg_ret_inp_event *revt = &ret.data.inp_event;

   ERR_SET_CUR_FUNC(PHG_ERH, Pfn_await_event);

   if (PSL_WS_STATE(PHG_PSL) != PWS_ST_WSOP) {
      ERR_REPORT(PHG_ERH, ERR3);
   }
   else {
      /* Process events one at time for each workstation
       * until one is available, or if the timeout expires
       */
      time = 0;
      do {
         phg_mtime(&time1);
         if (inp_dispatch_next(Pfn_await_event) == FALSE) {
            /* If there where no events sleep a while */
            phg_msleep(1);
         }
         inp_event_poll(&ret);
         phg_mtime(&time2);
         time += (time2 - time1);
         if (time >= limit) {
            break;
         }
      } while (revt->id.in_class == PIN_NONE);

      if (ret.err == 0) {
         *ws_id = revt->id.ws;
         *dev_class = revt->id.in_class;
         *in_num = revt->id.dev;

         switch (revt->id.in_class) {
            case PIN_STROKE:
               size = revt->data.stk.num_points * sizeof(Ppoint3);
               if (size > 0) {
                  pts = (Ppoint3 *) malloc(size);
                  if (pts == NULL) {
                     ERR_REPORT(PHG_ERH, ERR900);
                     revt->data.stk.num_points = 0;
                  }
                  else {
                     memcpy(pts, revt->data.stk.points, size);
                     revt->data.stk.points = pts;
                  }
               }
               break;

               case PIN_PICK:
                  if (revt->data.pik.status == PIN_STATUS_OK) {
                     size = revt->data.pik.pick_path.depth *
                            sizeof(Ppick_path_elem);
                     if (size > 0) {
                        path = (Ppick_path_elem *) malloc(size);
                        if (path == NULL) {
                           ERR_REPORT(PHG_ERH, ERR900);
                           revt->data.pik.status = PIN_STATUS_NONE;
                        }
                        else {
                           memcpy(path,
                                  revt->data.pik.pick_path.path_list,
                                  size);
                           revt->data.pik.pick_path.path_list = path;
                        }
                     }
                  }
                  break;

               /* TODO: Investigate things to copy for other device types */

               default:
                  break;
         }

         PSL_CLEAR_CUR_EVENT(PHG_PSL);
         PSL_SET_CUR_EVENT_ID(PHG_PSL, revt->id);
         if (revt->id.in_class != PIN_NONE) {
            PSL_SET_CUR_EVENT_DATA(PHG_PSL, revt->data);
         }
      }
      else {
         ERR_FLUSH(PHG_ERH);
      }
   }
}

/*******************************************************************************
 * check_event_class
 *
 * DESCR:       Helper function to check input class of event on queue
 * RETURNS:     TRUE or FALSE
 */

static int check_event_class(
   Pin_class dev_class,
   Pint fn_id
   )
{
   int status = TRUE;

   ERR_SET_CUR_FUNC(PHG_ERH, fn_id);

   if (PSL_WS_STATE(PHG_PSL) != PWS_ST_WSOP) {
      ERR_REPORT(PHG_ERH, ERR3);
      status = FALSE;
   }
   else if (PSL_CUR_EVENT_CLASS(PHG_PSL) != dev_class) {
      ERR_REPORT(PHG_ERH, ERR259);
      status = FALSE;
   }

   return status;
}

/*******************************************************************************
 * pget_loc
 *
 * DESCR:       Get locator event from event queue
 * RETURNS:     N/A
 */

void pget_loc(
   Pint *view_ind,
   Ppoint *loc_pos
   )
{
   if (check_event_class(PIN_LOC, Pfn_get_loc)) {
      *view_ind = PSL_CUR_EVENT_DATA(PHG_PSL, loc).view_ind;
      loc_pos->x = PSL_CUR_EVENT_DATA(PHG_PSL, loc).position.x;
      loc_pos->y = PSL_CUR_EVENT_DATA(PHG_PSL, loc).position.y;
   }
}

/*******************************************************************************
 * pget_loc3
 *
 * DESCR:       Get locator event from event queue 3D
 * RETURNS:     N/A
 */

void pget_loc3(
   Pint *view_ind,
   Ppoint3 *loc_pos
   )
{
   if (check_event_class(PIN_LOC, Pfn_get_loc3)) {
      *view_ind = PSL_CUR_EVENT_DATA(PHG_PSL, loc).view_ind;
      loc_pos->x = PSL_CUR_EVENT_DATA(PHG_PSL, loc).position.x;
      loc_pos->y = PSL_CUR_EVENT_DATA(PHG_PSL, loc).position.y;
      loc_pos->z = PSL_CUR_EVENT_DATA(PHG_PSL, loc).position.z;
   }
}

/*******************************************************************************
 * pget_stroke
 *
 * DESCR:       Get stroke event from event queue
 * RETURNS:     N/A
 */

void pget_stroke(
   Pint *view_ind,
   Ppoint_list *stroke
   )
{
   int i;
   Pstroke3 *stk;

   if (check_event_class(PIN_STROKE, Pfn_get_stroke)) {
      stk = &PSL_CUR_EVENT_DATA(PHG_PSL, stk);
      *view_ind = stk->view_ind;
      stroke->num_points = stk->num_points;
      for (i = 0; i < stk->num_points; i++) {
         stroke->points[i].x = stk->points[i].x;
         stroke->points[i].y = stk->points[i].y;
      }
   }
}

/*******************************************************************************
 * pget_stroke3
 *
 * DESCR:       Get stroke event from event queue 3D
 * RETURNS:     N/A
 */

void pget_stroke3(
   Pint *view_ind,
   Ppoint_list3 *stroke
   )
{
   Pstroke3 *stk;

   if (check_event_class(PIN_STROKE, Pfn_get_stroke3)) {
      stk = &PSL_CUR_EVENT_DATA(PHG_PSL, stk);
      *view_ind = stk->view_ind;
      stroke->num_points = stk->num_points;
      if (stk->num_points > 0) {
         memcpy(stroke->points, stk->points, stk->num_points * sizeof(Ppoint3));
      }
   }
}

/*******************************************************************************
 * pget_pick
 *
 * DESCR:       Get pick event from event queue
 * RETURNS:     N/A
 */

void pget_pick(
   Pint depth,
   Pin_status *in_status,
   Ppick_path *pick
   )
{
   Ppick *pik;
   Pint depth_limit;

   if (check_event_class(PIN_PICK, Pfn_get_pick)) {
      pik = &PSL_CUR_EVENT_DATA(PHG_PSL, pik);
      *in_status = pik->status;
      if (pik->status == PIN_STATUS_OK) {
         pick->depth = pik->pick_path.depth;
         depth_limit = PHG_MIN(depth, pik->pick_path.depth);
         if (depth_limit > 0) {
            memcpy(pick->path_list,
                   pik->pick_path.path_list,
                   depth_limit * sizeof(Ppick_path_elem));
         }
      }
   }
}

/*******************************************************************************
 * request_device
 *
 * DESCR:       Request device helper function
 * RETURNS:     N/A
 */

static void request_device(
   Pint ws_id,
   Pint dev_num,
   Phg_args_idev_class dev_class,
   Phg_ret *ret
   )
{
   Pin_status in_status;

   /* The calling function shall always check the requested workstation first */
   Ws_handle wsh = PHG_WSID(ws_id);
   Ws_inp_req *inp = &wsh->in_ws.input_request;
   Phg_ret_inp_request *req = &ret->data.inp_request;

   (*wsh->request_device)(wsh, dev_class, dev_num, ret);

   do {
      while (phg_wsx_input_dispatch_next(wsh, PHG_EVT_TABLE));

      switch (dev_class) {
         case PHG_ARGS_INP_LOC:
         case PHG_ARGS_INP_LOC3:
         case PHG_ARGS_INP_STK:
         case PHG_ARGS_INP_STK3:
         case PHG_ARGS_INP_VAL:
         case PHG_ARGS_INP_VAL3:
         case PHG_ARGS_INP_STR:
         case PHG_ARGS_INP_STR3:
            in_status = inp->status.istat;
            break;

         case PHG_ARGS_INP_PIK:
         case PHG_ARGS_INP_PIK3:
            in_status = inp->status.pkstat;
            break;

         case PHG_ARGS_INP_CHC:
         case PHG_ARGS_INP_CHC3:
            in_status = inp->status.chstat;
            break;
      }

      phg_msleep(1);

   } while ((in_status == PIN_STATUS_NONE) &&
            (inp->dev_class != dev_class) &&
            (inp->dev_num != dev_num));

   /* Copy to return argument */
   req->status.istat = in_status;
   if (in_status != PIN_STATUS_NO_IN) {
      switch (dev_class) {
         case PHG_ARGS_INP_LOC:
         case PHG_ARGS_INP_LOC3:
            memcpy(&req->event.data.loc,
                   &wsh->in_ws.input_request.evt.loc,
                   sizeof(Ploc3));
            break;

         case PHG_ARGS_INP_STK:
         case PHG_ARGS_INP_STK3:
            memcpy(&req->event.data.stk,
                   &wsh->in_ws.input_request.evt.stroke,
                   sizeof(Pstroke3));
            break;

         case PHG_ARGS_INP_PIK:
         case PHG_ARGS_INP_PIK3:
            memcpy(&req->event.data.pik,
                   &wsh->in_ws.input_request.evt.pick,
                   sizeof(Ppick));
            break;

         case PHG_ARGS_INP_VAL:
         case PHG_ARGS_INP_VAL3:
            memcpy(&req->event.data.val,
                   &wsh->in_ws.input_request.evt.val,
                   sizeof(Pfloat));
            break;

         case PHG_ARGS_INP_CHC:
         case PHG_ARGS_INP_CHC3:
            memcpy(&req->event.data.chc,
                   &wsh->in_ws.input_request.evt.choice,
                   sizeof(Pchoice));
            break;

         case PHG_ARGS_INP_STR:
         case PHG_ARGS_INP_STR3:
            memcpy(&req->event.data.str,
                   &wsh->in_ws.input_request.evt.string,
                   sizeof(Phg_string));
            break;
      }
   }

   memset(inp, 0, sizeof(Ws_inp_req));
   ret->err = 0;
}

/*******************************************************************************
 * preq_loc3
 *
 * DESCR:       Request input from locator device 3D
 * RETURNS:     N/A
 */

void preq_loc3(
   Pint ws_id,
   Pint loc_num,
   Pin_status *in_status,
   Pint *view_ind,
   Ppoint3 *loc_pos
   )
{
   Wst_input_wsdt *idt;
   Phg_ret ret;
   Phg_ret_inp_request *req = &ret.data.inp_request;

   idt = input_ws_open(ws_id, Pfn_req_loc3, NULL, NULL);
   if (idt != NULL) {
      if ((loc_num > 0) && (loc_num <= idt->num_devs.loc)) {
         request_device(ws_id, loc_num, PHG_ARGS_INP_LOC3, &ret);
         if (ret.err == 0) {
            *in_status = req->status.istat;
            if (req->status.istat != PIN_STATUS_NO_IN) {
               *view_ind = req->event.data.loc.view_ind;
               memcpy(loc_pos,
                      &req->event.data.loc.position,
                      sizeof(Ppoint3));
            }
         }
         else {
            *in_status = PIN_STATUS_NO_IN;
         }
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}

/*******************************************************************************
 * preq_stroke3
 *
 * DESCR:       Request input from stroke device 3D
 * RETURNS:     N/A
 */

void preq_stroke3(
   Pint ws_id,
   Pint stroke_num,
   Pin_status *in_status,
   Pint *view_ind,
   Ppoint_list3 *stroke
   )
{
   Wst_input_wsdt *idt;
   Phg_ret ret;
   Phg_ret_inp_request *req = &ret.data.inp_request;

   idt = input_ws_open(ws_id, Pfn_req_stroke3, NULL, NULL);
   if (idt != NULL) {
      if ((stroke_num > 0) && (stroke_num <= idt->num_devs.stroke)) {
         request_device(ws_id, stroke_num, PHG_ARGS_INP_STK3, &ret);
         if (ret.err == 0) {
            *in_status = req->status.istat;
            if (req->status.istat != PIN_STATUS_NO_IN) {
               *view_ind = req->event.data.stk.view_ind;
               stroke->num_points = req->event.data.stk.num_points;
               memcpy(stroke->points,
                      req->event.data.stk.points,
                      stroke->num_points * sizeof(Ppoint3));
            }
         }
         else {
            *in_status = PIN_STATUS_NO_IN;
         }
      }
      else {
         ERR_REPORT(PHG_ERH, ERR250);
      }
   }
}
