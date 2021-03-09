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

#ifndef _css_h
#define _css_h

#include <sys/types.h>
#include <phigs/phg.h>
#include <phigs/private/cssP.h>

#define NUM_EL_TYPES           PELEM_NUM_EL_TYPES

/* structure element data */
typedef union {
    Pint idata;
    void *ptr;
} Css_eldata;

typedef struct _set_element {
    caddr_t             key;
    caddr_t             data;
    struct _set_element *next;
} Css_set_element;

typedef struct {
    int	            data_type;
    int	            num_elements;
    Css_set_element *elements;
    Css_set_element *last_element;
} Css_set;

typedef Css_set	*Css_set_ptr;

#define SET_DATA_SET		0x0
#define SET_DATA_SET_OF_SETS	0x1

/* structure */
typedef struct _Css_structel {
    Pelem_type	         eltype;
    Css_eldata	         eldata;
    struct _Css_structel *prev;
    struct _Css_structel *next;
} Css_structel;

typedef struct _Css_ws_on {
    Ws_handle wsh;
    Pint      count;
} Css_ws_on;

typedef struct _Css_ws_on *Css_ws_list;

/* structure state list */
typedef struct _Css_ssl {
    Pint        struct_id;
    Css_ws_list ws_posted_to;
    Css_ws_list ws_appear_on;
    Css_set_ptr refer_to_me;
    Css_set_ptr i_refer_to;
    Pint        num_el;
    El_handle   first_el;
    El_handle   last_el;
} Css_ssl;

typedef int (*Css_func)();

typedef struct _hash_block {
    Pint               struct_id;
    Struct_handle      struct_ptr;
    struct _hash_block *next;
} Css_hash_block;

typedef struct {
    Css_hash_block **table;
    int            size;
    int            nstructs;
} Css_struct_tab;

typedef enum {
    SSH_CSS,
    SSH_AR
} Css_ssh_type;

typedef struct _Css_struct {
    Css_func       el_funcs[NUM_EL_TYPES];
    Css_struct_tab *stab;
    Struct_handle  open_struct;
    El_handle      el_ptr;
    Pint           el_index;
    Pedit_mode     edit_mode;
    Err_handle     erh;
    caddr_t        mem;
    int            mem_size;
    Css_ws_list    ws_list;
    Css_ssh_type   ssh_type;
} Css_struct;

#define CSS_CUR_STRUCT_ID(cssh) \
   ((cssh)->open_struct->struct_id)

#define CSS_CUR_STRUCTP(cssh) \
   ((cssh)->open_struct)

#define CSS_CUR_ELP(cssh) \
   ((cssh)->el_ptr)

#define CSS_INQ_EL_INDEX(cssh) \
   ((cssh)->el_index)

#define CSS_EDIT_MODE(cssh) \
   ((cssh)->edit_mode)

#define CSS_SET_EDIT_MODE(cssh, mode) \
   ((cssh)->edit_mode = (mode))

#define CSS_STRUCT_EXISTS(cssh, structid) \
    phg_css_stab_search((cssh)->stab, (structid))

#define CSS_GET_WS_ON(structp) \
   ((structp) ? (structp)->ws_appear_on : NULL)

#define CSS_STRUCT_HAS_DESCENDANTS(structp) \
    ((structp)->i_refer_to->num_elements)

#define CSS_STRUCT_IS_OPEN(cssh, structp) \
   ((cssh)->open_struct==(structp))

/* counts backwards to get the sequential element index for the given elptr */
#define CSS_GET_EL_INDEX(elptr, elindex)	\
  { El_handle _elptr = elptr;			\
						\
    (elindex) = 0;				\
    while (_elptr->prev) {			\
	(elindex)++;				\
	_elptr = _elptr->prev;			\
    }						\
  }

#define CSS_GET_EL_PTR(structp, elindex, elptr)		\
  { int _elindex = elindex;				\
							\
    if (_elindex<=0 || _elindex>(structp)->num_el)	\
	(elptr) = NULL;					\
    else {						\
	(elptr) = (structp)->first_el;			\
	while (_elindex--)				\
	    (elptr) = (elptr)->next;			\
    }							\
  }

/* css_ini */
Css_handle phg_css_init(Err_handle erh, Css_ssh_type ssh_type);
void phg_css_destroy(Css_handle cssh);

/* css_stb */
Css_struct_tab* phg_css_stab_init(int table_size);
Struct_handle phg_css_stab_search(Css_struct_tab *stab, Pint struct_id);
int phg_css_stab_insert(Css_struct_tab *stab, int struct_id,
                        Struct_handle struct_ptr);
int phg_css_stab_delete(Css_struct_tab *stab, int struct_id);
void phg_css_stab_free(Css_struct_tab *stab);

/* css_set */
Css_set* phg_css_set_create(int data_type);
int phg_css_set_add(Css_set *s, caddr_t key, caddr_t data);
int phg_css_set_remove(Css_set *s, caddr_t key);
int phg_css_set_element_of(Css_set *s, caddr_t key, caddr_t *data);
void phg_css_set_empty(Css_set *s);
void phg_css_set_free(Css_set *s);
void phg_css_set_recursive_free(Css_set *s);

/* css_str */
Struct_handle phg_css_open_struct(Css_handle cssh, Pint structid);
Struct_handle phg_css_close_struct(Css_handle cssh);
int phg_css_copy_struct(Css_handle cssh, Struct_handle structp);
void phg_css_delete_struct(Css_handle cssh, Struct_handle delstruct);
void phg_css_delete_net(Css_handle cssh,
                        Struct_handle structp,
                        Pref_flag refflag);
void css_print_structlist(char *header, Css_set_ptr structlist);
void phg_css_delete_all_structs(Css_handle cssh);
Css_ws_list phg_css_change_struct_id(Css_handle cssh,
                                     Phg_args_change_struct *ids,
                                     Struct_handle orig,
                                     Struct_handle newst,
                                     int orig_posted_somewhere);
Css_ws_list phg_css_change_struct_refs(Css_handle cssh,
                                       Phg_args_change_struct *ids,
                                       Struct_handle orig,
                                       Struct_handle newst);
Css_ws_list phg_css_change_struct_idrefs(Css_handle cssh,
                                         Phg_args_change_struct *ids,
                                         Struct_handle orig,
                                         Struct_handle newst);
Struct_handle phg_css_create_struct(Pint id);

/* css_el */
int phg_css_add_elem(Css_handle cssh, Phg_args_add_el *args);
El_handle phg_css_set_ep(Css_handle cssh, Phg_args_set_ep_op opcode, Pint data);
void phg_css_el_delete_list(Css_handle cssh,
                            Phg_args_del_el_op opcode,
                            Phg_args_del_el_data *data,
                            El_handle *ep1, El_handle *ep2);
void phg_css_delete_el(Css_handle cssh,
                       Phg_args_del_el_op opcode,
                       Phg_args_del_el_data *data,
                       El_handle ep1,
                       El_handle ep2);
int phg_css_struct_ref(Css_handle cssh,
                       El_handle elptr,
                       caddr_t argdata,
                       Css_el_op opcode);
int phg_css_no_data(Css_handle cssh,
                    El_handle elptr,
                    caddr_t *argdata,
                    Css_el_op opcode);
void phg_css_el_search(Css_handle cssh,
                       Pint struct_id,
                       Pint start_el,
                       Psearch_dir dir,
                       Pelem_type_list *incl,
                       Pelem_type_list *excl,
                       Phg_ret *ret);

/* css_pr */
void phg_css_print_struct(Struct_handle structp, int arflag);
void phg_css_print_eldata(El_handle elptr, int arflag);
void css_print_eltype(Pelem_type eltype);

/* css_inq */
void phg_css_inq_el_content(Css_handle cssh,
                            Pint structid,
                            Pint elnum,
                            Phg_ret *ret);
void phg_css_inq_el_type_size(Css_handle cssh,
                              Pint structid,
                              Pint elnum,
                              Phg_ret *ret);
void phg_css_inq_struct_status(Css_handle cssh,
                               Pint structid,
                               Phg_ret *ret);
void phg_css_inq_struct_ids(Css_handle cssh, Phg_ret *ret);
int phg_css_get_conf(Pint_list *csslist,
                     Pint_list *arlist,
                     Pint_list *conflist);
void phg_css_inq_hierarchy(Css_handle ssh,
                           Phg_args_hierarchy_dir dir,
                           Pint structid,
                           Ppath_order order,
                           Pint depth,
                           Phg_ret *ret);
void phg_css_inq_ws_posted(Css_handle cssh,
                           Pint structid,
                           Phg_ret *ret);

/* css_ws */
Struct_handle phg_css_post(Css_handle cssh,
                           Pint structid,
                           Ws_handle wsh,
                           int *was_posted);
Struct_handle phg_css_unpost(Css_handle cssh,
                             Pint structid,
                             Ws_handle wsh);
void phg_css_unpost_all(Css_handle cssh, Ws_handle wsh);
int phg_css_add_to_ws_appear(Css_handle cssh,
                             Struct_handle execp,
                             Css_ws_list addlist,
                             int nexec);
void phg_css_rm_from_ws_appear(Css_handle cssh,
                               Struct_handle execp,
                               Css_ws_list rmlist,
                               int nexec);
int phg_css_join_ws_list(Css_handle cssh,
                         Struct_handle s1,
                         Struct_handle s2,
                         Css_ws_list *newlist,
                         Css_ws_list_op op);
int phg_css_copy_ws_lists(Css_handle cssh,
                          Struct_handle from,
                          Struct_handle to,
                          Css_ws_list_op op);
int phg_css_ws_posted(Struct_handle structp, Ws_handle wsh);
int phg_css_ws_appearances(Struct_handle structp, Ws_handle wsh);

#endif

