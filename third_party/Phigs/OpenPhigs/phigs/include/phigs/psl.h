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

#ifndef _psl_h
#define _psl_h

#define MAX_NO_OPEN_WS                         10

typedef struct {
   Pint       used;                            /* Mark if workstation is used */
   Pint       wsid;                            /* Workstation id */
   char       *connid;                         /* Connection identity */
   Wst        *wstype;                         /* Workstation type */
} Psl_ws_info;

typedef struct {
   Pevent             id;
   Phg_inp_event_data data;
} Psl_inp_event;

typedef struct {
   Psys_st       phg_sys_state;                /* System state */
   Pws_st        phg_ws_state;                 /* Workstation state */
   Pstruct_st    phg_struct_state;             /* Structure state */
   Psl_ws_info   open_ws[MAX_NO_OPEN_WS];      /* Info list for workstations */
   Psl_inp_event cur_event;                    /* Event gotten by pwait_event */
   Pedit_mode    edit_mode;                    /* Structure edit mode */
   Pint          open_struct;                  /* Open structure */
} Phg_state_list;

typedef Phg_state_list *Psl_handle;

#define PSL_SYS_STATE(_psl) \
   ((_psl)->phg_sys_state)

#define PSL_WS_STATE(_psl) \
   ((_psl)->phg_ws_state)

#define PSL_STRUCT_STATE(_psl) \
   ((_psl)->phg_struct_state)

#define PSL_SET_CUR_EVENT_ID(_psl, _id) \
   ((_psl)->cur_event.id = (_id))

#define PSL_SET_CUR_EVENT_DATA(_psl, _data) \
   ((_psl)->cur_event.data = (_data))

#define PSL_CUR_EVENT_CLASS(_psl) \
   ((_psl)->cur_event.id.in_class)

#define PSL_CUR_EVENT_DATA(_psl, _class) \
   ((_psl)->cur_event.data._class)

#define PSL_CLEAR_CUR_EVENT( _psl) \
    {   switch ((_psl)->cur_event.id.in_class) { \
          case PIN_STROKE: \
            if ( (_psl)->cur_event.data.stk.num_points > 0) \
                free(((_psl)->cur_event.data.stk.points)); \
            break; \
          case PIN_PICK: \
            if ( (_psl)->cur_event.data.pik.status == PIN_STATUS_OK \
                && (_psl)->cur_event.data.pik.pick_path.depth > 0) \
                free(((_psl)->cur_event.data.pik.pick_path.path_list)); \
            break; \
          case PIN_STRING: \
            if ( (_psl)->cur_event.data.str.length > 0) \
                free(((_psl)->cur_event.data.str.string)); \
            break; \
          default: \
            break; \
        } \
        (_psl)->cur_event.id.in_class = PIN_NONE; \
    }

#define PSL_OPEN_STRUCT(_psl) \
   ((_psl)->open_struct)

#define PSL_EDIT_MODE(_psl) \
   ((_psl)->edit_mode)

/*******************************************************************************
 * phg_psl_create
 *
 * DESCR:       Create PHIGS state list
 * RETURNS:     Pointer to state list or NULL
 */

Psl_handle phg_psl_create(
   void
   );

/*******************************************************************************
 * phg_psl_init
 *
 * DESCR:       Initialize PHIGS state list
 * RETURNS:     TRUE or FALSE
 */

int phg_psl_init(
   Psl_handle psl
   );

/*******************************************************************************
 * phg_psl_destroy
 *
 * DESCR:       Destroy PHIGS state list
 * RETURNS:     N/A
 */

void phg_psl_destroy(
   Psl_handle psl
   );

/*******************************************************************************
 * phg_psl_inq_ws_open
 *
 * DESCR:       Inquire open workstation
 * RETURNS:     TRUE or FALSE
 */

int phg_psl_inq_ws_open(
   Psl_handle psl,
   Pint wsid
   );

/*******************************************************************************
 * phg_psl_inq_wsids
 *
 * DESCR:       Inquire workstation ids
 * RETURNS:     Number of open workstations
 */

int phg_psl_inq_wsids(
   Psl_handle psl,
   Pint *wsids
   );

/*******************************************************************************
 * phg_psl_get_ws_info
 * 
 * DESCR:       Get open workstation information
 * RETURNS:     Pointer to information structure
 */

Psl_ws_info* phg_psl_get_ws_info(
   Psl_handle psl,
   Pint wsid
   );

/*******************************************************************************
 * phg_psl_ws_free_slot 
 *
 * DESCR:       Find if there is a free slot for a workstation
 * RETURNS:     TRUE or there is a slot free otherwise FALSE
 */

int phg_psl_ws_free_slot(
   Psl_handle psl
   );

/*******************************************************************************
 * phg_psl_add_ws
 *
 * DESCR:       Add workstation to list
 * RETURNS:     TRUE if wsid could be added, else FALSE
 */

int phg_psl_add_ws(
   Psl_handle psl,
   Pint wsid,
   char *connid,
   Wst *type
   );

/*******************************************************************************
 * phg_psl_rem_ws
 *
 * DESCR:       Remove workstation from list
 * RETURNS:     N/A
 */

void phg_psl_rem_ws(
   Psl_handle psl,
   Pint wsid
   );

#endif /* _psl_h */

