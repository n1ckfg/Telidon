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

#ifndef _phgretdata_h
#define _phgretdata_h

typedef struct {
   Psearch_status status;
   Pint           found_el;
} Phg_ret_el_search;

typedef struct {
   Pelem_type type;
   Pint       size;
} Phg_ret_el_type_size;

typedef struct {
   Pelem_type    op;
   Phg_elmt_info *el_head;
} Phg_ret_q_content;

typedef struct {
   Pint_list counts;
   Pint      num_pairs;
   Pelem_ref *paths;
} Phg_ret_hierarchy;

typedef struct {
   int unused;
} Phg_ret_open_ws;

typedef struct {
   Pupd_st              update_state;
   Pview_rep3           *cur_rep;
   Pview_rep3           *req_rep;
} Phg_ret_view_rep;

typedef struct {
   Pdefer_mode      def_mode;
   Pmod_mode        mod_mode;
   Pdisp_surf_empty display_surf;
   Pvisual_st       state;
} Phg_ret_update_state;

typedef union {
   Pline_bundle_plus   extlnrep;
   Pmarker_bundle_plus extmkrep;
   Ptext_bundle_plus   exttxrep;
   Pint_bundle_plus    extinterrep;
   Pedge_bundle_plus   extedgerep;
   Pcolr_rep           corep;
   Pview_rep3          viewrep;
   Plight_src_bundle   lightsrcrep;
} Phg_ret_rep;

typedef struct {
   Pupd_st state;
   Pint    cur_mode;
   Pint    req_mode;
} Phg_ret_hlhsr_mode;

typedef struct {
   Pevent             id;
   Phg_inp_event_data data;
} Phg_ret_inp_event;

typedef struct {
   Pin_status istat;
   Pin_status chstat;
   Pin_status pkstat;
} Phg_ret_inp_req_stat;

typedef struct {
   int                  brk;
   Phg_ret_inp_req_stat status;
   Phg_ret_inp_event    event;
} Phg_ret_inp_request;

typedef struct {
   Pint       length;
   char       *strings;
   Pchoicest3 state;
} Phg_ret_choice_state;

typedef struct {
   Pint       length;
   Pstringst3 state;
} Phg_ret_string_state;

typedef union {
   Plocst3              loc;
   Ppickst3             pick;
   Pstrokest3           stroke;
   Pvalst3              val;
   Phg_ret_choice_state choice;
   Phg_ret_string_state string;
} Phg_ret_inp_state;

typedef struct {
   Pint_list incl;
   Pint_list excl;
} Phg_ret_filter;

typedef union {
   Pint                 idata;
   Pfloat               fdata;
   Pint_list            int_list;
   Pposted_struct_list  postlist;
   Phg_ret_open_ws      open_ws;
   Phg_ret_el_search    el_search;
   Phg_ret_el_type_size el_type_size;
   Phg_ret_q_content    el_info;
   Phg_ret_hierarchy    hierarchy;
   Phg_ret_view_rep     view_rep;
   Phg_ret_update_state update_state;
   Phg_ret_rep          rep;
   Phg_ret_hlhsr_mode   hlhsr_mode;
   Phg_ret_filter       filter;
   Phg_ret_inp_request  inp_request;
   Phg_ret_inp_state    inp_state;
   Phg_ret_inp_event    inp_event;
} Phg_ret_data;

typedef struct {
   Pint         err;
   Phg_ret_data data;
} Phg_ret;

#endif

