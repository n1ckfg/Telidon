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

#ifndef _phgargs_h
#define _phgargs_h

#include <phigs/util.h>
#include <phigs/ws_type.h>
#include <X11/Xlib.h>
#include <GL/glx.h>

typedef enum {
    PHG_ARGS_LNREP,
    PHG_ARGS_EXTLNREP,
    PHG_ARGS_MKREP,
    PHG_ARGS_EXTMKREP,
    PHG_ARGS_TXREP,
    PHG_ARGS_EXTTXREP,
    PHG_ARGS_EFREP,
    PHG_ARGS_INTERREP,
    PHG_ARGS_EXTINTERREP,
    PHG_ARGS_EDGEREP,
    PHG_ARGS_EXTEDGEREP,
    PHG_ARGS_PTREP,
    PHG_ARGS_EXTPTREP,
    PHG_ARGS_COREP,
    PHG_ARGS_VIEWREP,
    PHG_ARGS_DCUEREP,
    PHG_ARGS_LIGHTSRCREP,
    PHG_ARGS_COLRMAPREP
} Phg_args_rep_type;

typedef enum {
    PHG_ARGS_SETEP_ABS,
    PHG_ARGS_SETEP_REL,
    PHG_ARGS_SETEP_LABEL,
    PHG_ARGS_SETEP_PICK_ID
} Phg_args_set_ep_op;

typedef enum {
    PHG_ARGS_DEL_CURRENT,
    PHG_ARGS_DEL_RANGE,
    PHG_ARGS_DEL_LABEL,
    PHG_ARGS_EMPTY_STRUCT
} Phg_args_del_el_op;

typedef enum {
   PHG_ARGS_INP_LOC,
   PHG_ARGS_INP_LOC3,
   PHG_ARGS_INP_PIK,
   PHG_ARGS_INP_PIK3,
   PHG_ARGS_INP_STK,
   PHG_ARGS_INP_STK3,
   PHG_ARGS_INP_VAL,
   PHG_ARGS_INP_VAL3,
   PHG_ARGS_INP_CHC,
   PHG_ARGS_INP_CHC3,
   PHG_ARGS_INP_STR,
   PHG_ARGS_INP_STR3
} Phg_args_idev_class;

typedef enum {
   PHG_ARGS_FLT_HIGH,
   PHG_ARGS_FLT_INVIS,
   PHG_ARGS_FLT_DRAWABLE,
   PHG_ARGS_FLT_PICK
} Phg_args_flt_type;

typedef enum {
   PHG_ARGS_CONN_OPEN,
   PHG_ARGS_CONN_DRAWABLE
} Phg_args_conn_type;

typedef enum {
   PHG_ARGS_AR_STRUCTS,
   PHG_ARGS_AR_NETWORKS,
   PHG_ARGS_AR_ALL
} Phg_args_ar_op;

typedef struct {
   Pint           arid;
   Phg_args_ar_op op;
   Pint_list      data;
   Pconf_res      resflag;
} Phg_args_ar_info;

typedef enum {
   PHG_ARGS_HIER_ANCESTORS,
   PHG_ARGS_HIER_DESCENDANTS
} Phg_args_hierarchy_dir;

typedef enum {
   PHG_ARGS_CONF_ALL,
   PHG_ARGS_CONF_NET
} Phg_args_conf_op;

typedef struct {
   Pint       el_size;
   Pelem_type el_type;
   void *     el_data;
} Phg_args_add_el;

typedef struct {
   Pint orig_id;
   Pint new_id;
   int  posted;
} Phg_args_change_struct;

typedef struct _Phg_args_conn_info {
   unsigned long background;
   Colormap      colormap;
   GLXContext    glx_context;
   Drawable      drawable_id;
   Display       *display;
   char          *display_name;
   Pint          display_name_length;
} Phg_args_conn_info;

typedef struct _Phg_args_open_ws {
   Pint               wsid;
   Phg_args_conn_type conn_type;
   Phg_args_conn_info conn_info;
   Wst                *type;
   Err_handle         erh;
   Css_handle         cssh;
   size_t             memory;
   Input_q_handle     input_q;
   char               *window_name;
   char               *icon_name;
} Phg_args_open_ws;

typedef struct {
   Pint              index;
   union {
      Pline_bundle        lnrep;
      Pline_bundle_plus   extlnrep;
      Pmarker_bundle      mkrep;
      Pmarker_bundle_plus extmkrep;
      Ptext_bundle        txrep;
      Ptext_bundle_plus   exttxrep;
      Pint_bundle         interrep;
      Pint_bundle_plus    extinterrep;
      Pedge_bundle        edgerep;
      Pedge_bundle_plus   extedgerep;
      Pcolr_rep           corep;
      Pview_rep3          viewrep;
      Plight_src_bundle   lightsrcrep;
   } bundl;
} Phg_args_rep_data;

typedef struct {
   Phg_args_set_ep_op op;
   Pint               data;
} Phg_args_set_el_ptr;

typedef union {
    struct {
        Pint    ep1;
        Pint    ep2;
    } ep_values;
    struct {
        Pint    label1;
        Pint    label2;
    } label_range;
    Pint        struct_id;
} Phg_args_del_el_data;

typedef struct {
   Phg_args_del_el_op   op;
   Phg_args_del_el_data data;
} Phg_args_del_el;

typedef union {
   struct {
      Ploc3         init;
      Ploc_data3    rec;
   } loc;

   struct {
      Ppick         init;
      Ppick_data    rec;
      Ppath_order   porder;
   } pik;

   struct {
      Pstroke3      init;
      Pstroke_data3 rec;
   } stk;

   struct {
      Pfloat        init;
      Pint          counts[4];
      Pval_data     rec;
   } val;

   struct {
      Pin_status    status;
      Pint          init;
      Pint          string_list_size;
      Pchoice_data  rec;
   } cho;

   struct {
      Phg_string    init;
      Pstring_data  rec;
   } str;
} Phg_args_init_data;

typedef struct {
   Pint                wsid;
   Phg_args_idev_class idev_class;
   Pint                dev;
   Pint                pet;
   Plimit3             echo_volume;
   Phg_args_init_data  data;
} Phg_args_inp_init_dev;

typedef struct {
   Phg_args_idev_class idev_class;
   Pint                dev;
   Pop_mode            mode;
   Pecho_switch        echo;
} Phg_args_set_mode_data;

typedef struct {
   char *fname;
   Pint name_length;
   Pint arid;
} Phg_args_ar_open;

typedef struct {
   Phg_args_hierarchy_dir dir;
   Pint                   struct_id;
   Ppath_order            order;
   Pint                   depth;
} Phg_args_q_hierarchy;

typedef struct {
   Pint                 arid;
   Phg_args_q_hierarchy hier;
} Phg_args_q_ar_hierarchy;

typedef struct {
   Phg_args_conf_op   op;
   Pint               arid;
   Pint               struct_id;
   Pstruct_net_source src;
} Phg_args_q_conflicting;

#endif

