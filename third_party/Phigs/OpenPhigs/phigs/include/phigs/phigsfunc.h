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

#ifndef _phigsfunc_h
#define _phigsfunc_h

#define		Pfn_open_phigs			(0)
#define		Pfn_close_phigs			(1)
#define		Pfn_open_ws			(2)
#define		Pfn_close_ws			(3)
#define		Pfn_redraw_all_structs		(4)
#define		Pfn_upd_ws			(5)
#define		Pfn_set_disp_upd_st		(6)
#define		Pfn_message			(7)
#define		Pfn_polyline3			(8)
#define		Pfn_polyline			(9)
#define		Pfn_polymarker3			(10)
#define		Pfn_polymarker			(11)
#define		Pfn_text3			(12)
#define		Pfn_text			(13)
#define		Pfn_anno_text_rel3		(14)
#define		Pfn_anno_text_rel		(15)
#define		Pfn_fill_area3			(16)
#define		Pfn_fill_area			(17)
#define		Pfn_fill_area_set3		(18)
#define		Pfn_fill_area_set		(19)
#define		Pfn_cell_array3			(20)
#define		Pfn_cell_array			(21)
#define		Pfn_gdp3			(22)
#define		Pfn_gdp				(23)
#define		Pfn_set_line_ind		(24)
#define		Pfn_set_marker_ind		(25)
#define		Pfn_set_text_ind		(26)
#define		Pfn_set_int_ind			(27)
#define		Pfn_set_edge_ind		(28)
#define		Pfn_set_linetype		(29)
#define		Pfn_set_linewidth		(30)
#define		Pfn_set_line_colr_ind		(31)
#define		Pfn_set_marker_type		(32)
#define		Pfn_set_marker_size		(33)
#define		Pfn_set_marker_colr_ind		(34)
#define		Pfn_set_text_font		(35)
#define		Pfn_set_text_prec		(36)
#define		Pfn_set_char_expan		(37)
#define		Pfn_set_char_space		(38)
#define		Pfn_set_text_colr_ind		(39)
#define		Pfn_set_char_ht			(40)
#define		Pfn_set_char_up_vec		(41)
#define		Pfn_set_text_path		(42)
#define		Pfn_set_text_align		(43)
#define		Pfn_set_anno_char_ht		(44)
#define		Pfn_set_anno_char_up_vec	(45)
#define		Pfn_set_anno_path		(46)
#define		Pfn_set_anno_align		(47)
#define		Pfn_set_anno_style		(48)
#define		Pfn_set_int_style		(49)
#define		Pfn_set_int_style_ind		(50)
#define		Pfn_set_int_colr_ind		(51)
#define		Pfn_set_edge_flag		(52)
#define		Pfn_set_edgetype		(53)
#define		Pfn_set_edgewidth		(54)
#define		Pfn_set_edge_colr_ind		(55)
#define		Pfn_set_pat_size		(56)
#define		Pfn_set_pat_ref_point_vecs	(57)
#define		Pfn_set_pat_ref_point		(58)
#define		Pfn_add_names_set		(59)
#define		Pfn_remove_names_set		(60)
#define		Pfn_set_indiv_asf		(61)
#define		Pfn_set_line_rep		(62)
#define		Pfn_set_marker_rep		(63)
#define		Pfn_set_text_rep		(64)
#define		Pfn_set_int_rep			(65)
#define		Pfn_set_edge_rep		(66)
#define		Pfn_set_pat_rep			(67)
#define		Pfn_set_colr_rep		(68)
#define		Pfn_set_highl_filter		(69)
#define		Pfn_set_invis_filter		(70)
#define		Pfn_set_colr_model		(71)
#define		Pfn_set_hlhsr_id		(72)
#define		Pfn_set_hlhsr_mode		(73)
#define		Pfn_set_local_tran3		(74)
#define		Pfn_set_local_tran		(75)
#define		Pfn_set_global_tran3		(76)
#define		Pfn_set_global_tran		(77)
#define		Pfn_set_model_clip_vol3		(78)
#define		Pfn_set_model_clip_vol		(79)
#define		Pfn_set_model_clip_ind		(80)
#define		Pfn_restore_model_clip_vol	(81)
#define		Pfn_set_view_ind		(82)
#define		Pfn_set_view_rep3		(83)
#define		Pfn_set_view_rep		(84)
#define		Pfn_set_view_tran_in_pri	(85)
#define		Pfn_set_ws_win3			(86)
#define		Pfn_set_ws_win			(87)
#define		Pfn_set_ws_vp3			(88)
#define		Pfn_set_ws_vp			(89)
#define		Pfn_open_struct			(90)
#define		Pfn_close_struct		(91)
#define		Pfn_exec_struct			(92)
#define		Pfn_label			(93)
#define		Pfn_appl_data			(94)
#define		Pfn_gse				(95)
#define		Pfn_set_edit_mode		(96)
#define		Pfn_copy_all_elems_struct	(97)
#define		Pfn_set_elem_ptr		(98)
#define		Pfn_offset_elem_ptr		(99)
#define		Pfn_set_elem_ptr_label		(100)
#define		Pfn_del_elem			(101)
#define		Pfn_del_elem_range		(102)
#define		Pfn_del_elems_labels		(103)
#define		Pfn_empty_struct		(104)
#define		Pfn_del_struct			(105)
#define		Pfn_del_struct_net		(106)
#define		Pfn_del_all_struct		(107)
#define		Pfn_change_struct_id		(108)
#define		Pfn_change_struct_refs		(109)
#define		Pfn_change_struct_id_refs	(110)
#define		Pfn_post_struct			(111)
#define		Pfn_unpost_struct		(112)
#define		Pfn_unpost_all_structs		(113)
#define		Pfn_open_ar_file		(114)
#define		Pfn_close_ar_file		(115)
#define		Pfn_ar_structs			(116)
#define		Pfn_ar_struct_nets		(117)
#define		Pfn_ar_all_structs		(118)
#define		Pfn_set_conf_res		(119)
#define		Pfn_ret_struct_ids		(120)
#define		Pfn_ret_structs			(121)
#define		Pfn_ret_struct_nets		(122)
#define		Pfn_ret_all_structs		(123)
#define		Pfn_ret_paths_ancest		(124)
#define		Pfn_ret_paths_descs		(125)
#define		Pfn_del_structs_ar		(126)
#define		Pfn_del_struct_nets_ar		(127)
#define		Pfn_del_all_structs_ar		(128)
#define		Pfn_set_pick_id			(129)
#define		Pfn_set_pick_filter		(130)
#define		Pfn_init_loc3			(131)
#define		Pfn_init_loc			(132)
#define		Pfn_init_stroke3		(133)
#define		Pfn_init_stroke			(134)
#define		Pfn_init_val3			(135)
#define		Pfn_init_val			(136)
#define		Pfn_init_choice3		(137)
#define		Pfn_init_choice			(138)
#define		Pfn_init_pick3			(139)
#define		Pfn_init_pick			(140)
#define		Pfn_init_string3		(141)
#define		Pfn_init_string			(142)
#define		Pfn_set_loc_mode		(143)
#define		Pfn_set_stroke_mode		(144)
#define		Pfn_set_val_mode		(145)
#define		Pfn_set_choice_mode		(146)
#define		Pfn_set_pick_mode		(147)
#define		Pfn_set_string_mode		(148)
#define		Pfn_req_loc3			(149)
#define		Pfn_req_loc			(150)
#define		Pfn_req_stroke3			(151)
#define		Pfn_req_stroke			(152)
#define		Pfn_req_val			(153)
#define		Pfn_req_choice			(154)
#define		Pfn_req_pick			(155)
#define		Pfn_req_string			(156)
#define		Pfn_sample_loc3			(157)
#define		Pfn_sample_loc			(158)
#define		Pfn_sample_stroke3		(159)
#define		Pfn_sample_stroke		(160)
#define		Pfn_sample_val			(161)
#define		Pfn_sample_choice		(162)
#define		Pfn_sample_pick			(163)
#define		Pfn_sample_string		(164)
#define		Pfn_await_event			(165)
#define		Pfn_flush_events		(166)
#define		Pfn_get_loc3			(167)
#define		Pfn_get_loc			(168)
#define		Pfn_get_stroke3			(169)
#define		Pfn_get_stroke			(170)
#define		Pfn_get_val			(171)
#define		Pfn_get_choice			(172)
#define		Pfn_get_pick			(173)
#define		Pfn_get_string			(174)
#define		Pfn_write_item			(175)
#define		Pfn_get_item_type		(176)
#define		Pfn_read_item			(177)
#define		Pfn_interpret_item		(178)
#define		Pfn_set_err_hand_mode		(179)
#define		Pfn_escape			(180)

#define         Pfn_set_line_colr               (310)
#define         Pfn_set_marker_colr             (312)
#define         Pfn_set_text_colr               (313)
#define         Pfn_set_int_colr                (316)
#define         Pfn_set_edge_colr               (327)
#define         Pfn_fill_area_set3_data         (328)
#define         Pfn_set_light_src_rep           (329)
#define         Pfn_set_light_src_state         (330)
#define         Pfn_set_int_shad_meth           (331)
#define         Pfn_set_refl_eqn                (332)
#define         Pfn_set_refl_props              (333)

#define         Pfn_INQUIRY                     (1000)

/*******************************************************************************
 * popen_phigs
 *
 * DESCR:       Open phigs
 * RETURNS:     N/A
 */

void popen_phigs(
   char *error_file,
   size_t memory
   );

/*******************************************************************************
 * popen_ws
 *
 * DESCR:       Open workstation
 * RETURNS:     N/A
 */

void popen_ws(
   Pint ws_id,
   Phg_args_conn_info *conn_id,
   Pint ws_type
   );

/*******************************************************************************
 * pset_ws_vp
 *
 * DESCR:       Set workstation viewport
 * RETURNS:     N/A
 */

void pset_ws_vp(
   Pint ws_id,
   Plimit *viewport
   );

/*******************************************************************************
 * pset_ws_vp3
 *
 * DESCR:       Set workstation viewport
 * RETURNS:     N/A
 */

void pset_ws_vp3(
   Pint ws_id,
   Plimit3 *viewport
   );

/*******************************************************************************
 * pset_ws_win
 *
 * DESCR:       Set workstation window
 * RETURNS:     N/A
 */

void pset_ws_win(
   Pint ws_id,
   Plimit *window
   );

/*******************************************************************************
 * pset_ws_win3
 *
 * DESCR:       Set workstation window
 * RETURNS:     N/A
 */

void pset_ws_win3(
   Pint ws_id,
   Plimit3 *window
   );

/*******************************************************************************
 * pset_invis_filter
 *
 * DESCR:       Set workstation invisibility filter
 * RETURNS:     N/A
 */

void pset_invis_filter(
   Pint ws_id,
   Pfilter *filter
   );

/*******************************************************************************
 * pset_hlhsr_mode
 *
 * DESCR:       Set workstation hlhsr mode
 * RETURNS:     N/A
 */

void pset_hlhsr_mode(
   Pint ws_id,
   Pint hlhsr_mode
   );

/*******************************************************************************
 * pset_line_rep
 *
 * DESCR:       Set workstation line represenation
 * RETURNS:     N/A
 */

void pset_line_rep(
   Pint ws_id,
   Pint line_ind,
   Pline_bundle *line_bundle
   );

/*******************************************************************************
 * pset_marker_rep
 *
 * DESCR:       Set workstation marker represenation
 * RETURNS:     N/A
 */

void pset_marker_rep(
   Pint ws_id,
   Pint marker_ind,
   Pmarker_bundle *marker_bundle
   );

/*******************************************************************************
 * pset_text_rep
 *
 * DESCR:       Set workstation text represenation
 * RETURNS:     N/A
 */

void pset_text_rep(
   Pint ws_id,
   Pint text_ind,
   Ptext_bundle *text_bundle
   );

/*******************************************************************************
 * pset_edge_rep
 *
 * DESCR:       Set workstation edge represenation
 * RETURNS:     N/A
 */

void pset_edge_rep(
   Pint ws_id,
   Pint edge_ind,
   Pedge_bundle *edge_bundle
   );

/*******************************************************************************
 * pset_int_rep
 *
 * DESCR:       Set workstation interior represenation
 * RETURNS:     N/A
 */

void pset_int_rep(
   Pint ws_id,
   Pint int_ind,
   Pint_bundle *int_bundle
   );

/*******************************************************************************
 * ppost_struct
 *
 * DESCR:       Post structure to workstation
 * RETURNS:     N/A
 */

void ppost_struct(
   Pint ws_id,
   Pint struct_id,
   Pfloat priority
   );

/*******************************************************************************
 * punpost_struct
 *
 * DESCR:       Remove posted structure from workstation
 * RETURNS:     N/A
 */

void punpost_struct(
   Pint ws_id,
   Pint struct_id
   );

/*******************************************************************************
 * punpost_all_structs
 *
 * DESCR:       Remove all posted structures from workstation
 * RETURNS:     N/A
 */

void punpost_all_structs(
   Pint ws_id
   );

/*******************************************************************************
 * predraw_all_structs
 *
 * DESCR:       Redraw all structures on workstation
 * RETURNS:     N/A
 */

void predraw_all_structs(
   Pint ws_id,
   Pctrl_flag ctrl_flag
   );

/*******************************************************************************
 * pupd_ws
 *
 * DESCR:       Set workstation update state
 * RETURNS:     N/A
 */

void pupd_ws(
   Pint ws_id,
   Pregen_flag regen_flag
   );

/*******************************************************************************
 * pset_disp_upd_st
 *
 * DESCR:       Set workstation update state
 * RETURNS:     N/A
 */

void pset_disp_upd_st(
   Pint ws_id,
   Pdefer_mode def_mode,
   Pmod_mode mod_mode
   );

/*******************************************************************************
 * pset_view_tran_in_pri
 *
 * DESCR:       Set view input priority
 * RETURNS:     N/A
 */

void pset_view_tran_in_pri(
   Pint ws_id,
   Pint view_ind,
   Pint ref_view_ind,
   Prel_pri rel_pri
   );

/*******************************************************************************
 * pset_light_src_rep
 *
 * DESCR:       Set light source for workstation
 * RETURNS:     N/A
 */

void pset_light_src_rep(
   Pint ws_id,
   Pint light_src_ind,
   Plight_src_bundle *light_src_rep
   );

/*******************************************************************************
 * pset_colr_rep
 *
 * DESCR:       Set workstation colour representation
 * RETURNS:     N/A
 */

void pset_colr_rep(
   Pint ws_id,
   Pint ind,
   Pcolr_rep *rep
   );

/*******************************************************************************
 * popen_struct
 *
 * DESCR:       Opens a structure for appending or editing.
 * RETURNS:     N/A
 */

void popen_struct(
   Pint struct_id
   );

/*******************************************************************************
 * pclose_struct
 *
 * DESCR:       Closes a previously opened structure.
 * RETURNS:     N/A
 */

void pclose_struct(
   void
   );

/*******************************************************************************
 * pset_edit_mode
 *
 * DESCR:       Set structure edit mode
 * RETURNS:     N/A
 */

void pset_edit_mode(
   Pedit_mode mode
   );

/*******************************************************************************
 * pset_elem_ptr
 *
 * DESCR:       Make the requested index the "currently active element".
 *              NOTE: 0 means set element to even before the very first
 *              element; 1 means set elptr to very first element.
 * RETURNS:     N/A
 */

void pset_elem_ptr(
   Pint elem_ptr_value
   );

/*******************************************************************************
 * poffset_elem_ptr
 *
 * DESCR:       Offsets the element pointer forward by the given number of
 *              elements.
 *              Internal call to pset_elem_ptr does the verification work
 *              on the index.
 * RETURNS:     N/A
 */

void poffset_elem_ptr(
   Pint elem_ptr_offset
   );

/*******************************************************************************
 * pset_elem_ptr_label
 *
 * DESCR:       Searches forward in the structure list for the specified
 *              label, and makes that the current element.  Search begins
 *              with the element after (to the right) of the current one.
 *              Question: should I include the current element in the search?
 *              Or does the search begin with the first element after the
 *              current one?
 *              This version gives fatal error if label not found.
 * RETURNS:     N/A
 */

void pset_elem_ptr_label(
   Pint label_id
   );

/*******************************************************************************
 * pdel_elem
 *
 * DESCR:       Deletes the current element.  The element pointer is left
 *              pointing to the element just before (to the left) the one to
 *              be killed, if any.
 * RETURNS:     N/A
 */

void pdel_elem(
   void
   );

/*******************************************************************************
 * pdel_elem_range
 *
 * DESCR:       Deletes all elements within and on the bounds of the given
 *              range.  The element pointer is left pointing to the element
 *              just prior to the first element deleted.
 * RETURNS:     N/A
 */

void pdel_elem_range(
   Pint elem_ptr1_value,
   Pint elem_ptr2_value
   );

/*******************************************************************************
 * pdel_elems_labels
 *
 * DESCR:       Deletes all elements in the structure that lie between the
 *              given labels, but not the labels themselves.  The element
 *              pointer is left pointing to the first label.
 * RETURNS:     N/A
 */

void pdel_elems_labels(
   Pint label1_id,
   Pint label2_id
   );

/*******************************************************************************
 * pcopy_all_elems_struct
 *
 * DESCR:       Copies the elements of another structure into the open
 *              structure after the current element, which is updated to
 *              point to the last element inserted.  A structure can be
 *              copied into itself.
 * RETURNS:     N/A
 */

void pcopy_all_elems_struct(
   Pint struct_id
   );

/*******************************************************************************
 * pinq_elem_ptr
 *
 * DESCR:       Returns the index of the current element.
 * RETURNS:     N/A
 */

void pinq_elem_ptr(
   Pint *err_ind,
   Pint *elem_ptr_value
   );

/*******************************************************************************
 * pinq_open_struct
 *
 * DESCR:       Check if a structure is open for appending or editing.
 * RETURNS:     N/A
 */

void pinq_open_struct(
   Pint *err_ind,
   Popen_struct_status *status,
   Pint *struct_id
   );

/*******************************************************************************
 * padd_names_set
 *
 * DESCR:       Creates a new element - name set Inclusion
 * RETURNS:     N/A
 */

void padd_names_set(
   Pint_list *names
   );

/*******************************************************************************
 * premove_names_set
 *
 * DESCR:       Creates a new element - name set Remover
 * RETURNS:     N/A
 */

void premove_names_set(
   Pint_list *names
   );

/*******************************************************************************
 * pset_indiv_asf
 *
 * DESCR:       Creates a new element - Set attribute source flag
 * RETURNS:     N/A
 */

void pset_indiv_asf(
   Paspect asf_id,
   Pasf asf_source
   );

/*******************************************************************************
 * pset_local_tran
 *
 * DESCR:       Creates a new element - Set local model space transformation
 * RETURNS:     N/A
 */

void pset_local_tran(
   Pmatrix local_tran,
   Pcompose_type compose_type
   );

/*******************************************************************************
 * pset_local_tran3
 *
 * DESCR:       Creates a new element - Set local model space transformation 3D
 * RETURNS:     N/A
 */

void pset_local_tran3(
   Pmatrix3 local_tran,
   Pcompose_type compose_type
   );

/*******************************************************************************
 * pset_global_tran
 *
 * DESCR:       Creates a new element - Set global model space transformation
 * RETURNS:     N/A
 */

void pset_global_tran(
   Pmatrix global_tran
   );

/*******************************************************************************
 * pset_global_tran3
 *
 * DESCR:       Creates a new element - Set global model space transformation 3D
 * RETURNS:     N/A
 */

void pset_global_tran3(
   Pmatrix3 global_tran
   );

/*******************************************************************************
 * pset_view_ind
 *
 * DESCR:       Creates a new element - Set view index
 * RETURNS:     N/A
 */

void pset_view_ind(
   Pint view_ind
   );

/*******************************************************************************
 * ptext
 *
 * DESCR:       Creates a new element - Text
 * RETURNS:     N/A
 */

void ptext(
   Ppoint *text_pos,
   char *char_string
   );

/*******************************************************************************
 * ppolyline
 *
 * DESCR:       Creates a new element - Polyline
 * RETURNS:     N/A
 */

void ppolyline(
   Ppoint_list *point_list
   );

/*******************************************************************************
 * ppolyline3
 *
 * DESCR:       Creates a new element - Polyline 3D
 * RETURNS:     N/A
 */

void ppolyline3(
   Ppoint_list3 *point_list
   );

/*******************************************************************************
 * ppolymarker
 *
 * DESCR:       Creates a new element - Polymarker
 * RETURNS:     N/A
 */

void ppolymarker(
   Ppoint_list *point_list
   );

/*******************************************************************************
 * ppolymarker3
 *
 * DESCR:       Creates a new element - Polymarker 3D
 * RETURNS:     N/A
 */

void ppolymarker3(
   Ppoint_list3 *point_list
   );

/*******************************************************************************
 * pfill_area
 *
 * DESCR:       Creates a new element - Fill area
 * RETURNS:     N/A
 */

void pfill_area(
   Ppoint_list *point_list
   );

/*******************************************************************************
 * pfill_area3
 *
 * DESCR:       Creates a new element - Fill area 3D
 * RETURNS:     N/A
 */

void pfill_area3(
   Ppoint_list3 *point_list
   );

/*******************************************************************************
 * pfill_area_set
 *
 * DESCR:       Creates a new element - Fill area set
 * RETURNS:     N/A
 */

void pfill_area_set(
   Ppoint_list_list *point_list_list
   );

/*******************************************************************************
 * pfill_area_set3
 *
 * DESCR:       Creates a new element - Fill area set 3D
 * RETURNS:     N/A
 */

void pfill_area_set3(
   Ppoint_list_list3 *point_list_list
   );

/*******************************************************************************
 * pfill_area_set3_data
 *
 * DESCR:       Creates a new element - Fill area set with data 3D
 * RETURNS:     N/A
 */

void pfill_area_set3_data(
   Pint fflag,
   Pint eflag,
   Pint vflag,
   Pint colr_type,
   Pfacet_data3 *fdata,
   Pint nfa,
   Pedge_data_list *edata,
   Pfacet_vdata_list3 *vdata
   );

/*******************************************************************************
 * plabel
 *
 * DESCR:       Creates a new element - Label
 * RETURNS:     N/A
 */

void plabel(
   Pint label_id
   );

/*******************************************************************************
 * pset_pick_id
 *
 * DESCR:       Creates a new element - Pick ID
 * RETURNS:     N/A
 */

void pset_pick_id(
   Pint pick_id
   );

/*******************************************************************************
 * pset_hlhsr_id
 *
 * DESCR:       Create hidden lines, surface removal flag element
 * RETURNS:     N/A
 */

void pset_hlhsr_id(
   Pint hlhsr_id
   );

/*******************************************************************************
 * pset_int_ind
 *
 * DESCR:       Creates a new element - Facet Interiour Attribute Index
 * RETURNS:     N/A
 */

void pset_int_ind(
   Pint int_ind
   );

/*******************************************************************************
 * pset_int_colr_ind
 *
 * DESCR:       Creates a new element - Facet Color Attribute
 * RETURNS:     N/A
 */

void pset_int_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pset_int_style
 *
 * DESCR:       Creates a new element - Face Interiour Style
 * RETURNS:     N/A
 */

void pset_int_style(
   Pint_style int_style
   );

/*******************************************************************************
 * pset_int_style_ind
 *
 * DESCR:       Creates a new element - Face Interiour Pattern Index
 * RETURNS:     N/A
 */

void pset_int_style_ind(
   Pint int_style_ind
   );

/*******************************************************************************
 * pset_line_ind
 *
 * DESCR:       Creates a new element - Line Attribute Index
 * RETURNS:     N/A
 */

void pset_line_ind(
   Pint line_ind
   );

/*******************************************************************************
 * pset_line_colr_ind
 *
 * DESCR:       Creates a new element - Line Color Attribute
 * RETURNS:     N/A
 */

void pset_line_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pset_linewidth
 *
 * DESCR:       Creates a new element - Line Width Attribute
 * RETURNS:     N/A
 */

void pset_linewidth(
   Pfloat linewidth
   );

/*******************************************************************************
 * pset_linetype
 *
 * DESCR:       Creates a new element - Line Type Attribute
 * RETURNS:     N/A
 */

void pset_linetype(
   Pint linetype
   );

/*******************************************************************************
 * pset_marker_ind
 *
 * DESCR:       Creates a new element - Marker Attribute Index
 * RETURNS:     N/A
 */

void pset_marker_ind(
   Pint marker_ind
   );

/*******************************************************************************
 * pset_marker_colr_ind
 *
 * DESCR:       Creates a new element - Marker Color Attribute
 * RETURNS:     N/A
 */

void pset_marker_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pset_marker_size
 *
 * DESCR:       Creates a new element - Marker Size Attribute
 * RETURNS:     N/A
 */

void pset_marker_size(
   Pfloat marker_size
   );

/*******************************************************************************
 * pset_marker_type
 *
 * DESCR:       Creates a new element - Marker Type Attribute
 * RETURNS:     N/A
 */

void pset_marker_type(
   Pint marker_type
   );

/*******************************************************************************
 * pset_edge_ind
 *
 * DESCR:       Creates a new element - Edge Attribute Index
 * RETURNS:     N/A
 */

void pset_edge_ind(
   Pint edge_ind
   );

/*******************************************************************************
 * pset_edge_colr_ind
 *
 * DESCR:       Creates a new element - Edge Color Attribute
 * RETURNS:     N/A
 */

void pset_edge_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pset_edgetype
 *
 * DESCR:       Creates a new element - Edge Type Attribute
 * RETURNS:     N/A
 */

void pset_edgetype(
   Pint edgetype
   );

/*******************************************************************************
 * pset_edge_flag
 *
 * DESCR:       Creates a new element - Edge Flag Attribute
 * RETURNS:     N/A
 */

void pset_edge_flag(
   Pedge_flag edge_flag
   );

/*******************************************************************************
 * pset_edgewidth
 *
 * DESCR:       Creates a new element - Edge Width Attribute
 * RETURNS:     N/A
 */

void pset_edgewidth(
   Pfloat edgewidth
   );

/*******************************************************************************
 * pset_text_font
 *
 * DESCR:       Creates a new element - Text Font Attribute
 * RETURNS:     N/A
 */

void pset_text_font(
   Pint font
   );

/*******************************************************************************
 * pset_text_prec
 *
 * DESCR:       Creates a new element - Text Precision Attribute
 * RETURNS:     N/A
 */

void pset_text_prec(
   Ptext_prec prec
   );

/*******************************************************************************
 * pset_text_path
 *
 * DESCR:       Creates a new element - Text Path Attribute
 * RETURNS:     N/A
 */

void pset_text_path(
   Ptext_path text_path
   );

/*******************************************************************************
 * pset_text_align
 *
 * DESCR:       Creates a new element - Text Alignment Attribute
 * RETURNS:     N/A
 */

void pset_text_align(
   Ptext_align *text_align
   );

/*******************************************************************************
 * pset_char_ht
 *
 * DESCR:       Creates a new element - Character height Attribute
 * RETURNS:     N/A
 */

void pset_char_ht(
   Pfloat char_ht
   );

/*******************************************************************************
 * pset_char_expan
 *
 * DESCR:       Creates a new element - Character expansion factor Attribute
 * RETURNS:     N/A
 */

void pset_char_expan(
   Pfloat char_expan
   );

/*******************************************************************************
 * pset_char_space
 *
 * DESCR:       Creates a new element - Character spaceing Attribute
 * RETURNS:     N/A
 */

void pset_char_space(
   Pfloat char_space
   );

/*******************************************************************************
 * pset_char_up_vec
 *
 * DESCR:       Creates a new element - Character up vector Attribute
 * RETURNS:     N/A
 */

void pset_char_up_vec(
   Pvec *char_up_vec
   );

/*******************************************************************************
 * pset_text_ind
 *
 * DESCR:       Creates a new element - Text Attribute Index
 * RETURNS:     N/A
 */

void pset_text_ind(
   Pint text_ind
   );

/*******************************************************************************
 * pset_text_colr_ind
 *
 * DESCR:       Creates a new element - Text Color Attribute
 * RETURNS:     N/A
 */

void pset_text_colr_ind(
   Pint colr_ind
   );

/*******************************************************************************
 * pset_int_colr
 *
 * DESCR:       Creates a new element - Facet Color Attribute
 * RETURNS:     N/A
 */

void pset_int_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pset_line_colr
 *
 * DESCR:       Creates a new element - Line Color Attribute
 * RETURNS:     N/A
 */

void pset_line_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pset_marker_colr
 *
 * DESCR:       Creates a new element - Marker Color Attribute
 * RETURNS:     N/A
 */

void pset_marker_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pset_edge_colr
 *
 * DESCR:       Creates a new element - Edge Color Attribute
 * RETURNS:     N/A
 */

void pset_edge_colr(
   Pgcolr *colr
   );

/*******************************************************************************
 * pexec_struct
 *
 * DESCR:       Creates a new element - Nested Structure
 * RETURNS:     N/A
 */

void pexec_struct(
   Pint struct_id
   );

/*******************************************************************************
 * pset_light_src_state
 *
 * DESCR:       Creates a new element - Set light source state
 * RETURNS:     N/A
 */

void pset_light_src_state(
   Pint_list *activation,
   Pint_list *deactivation
   );

/*******************************************************************************
 * pset_int_shad_meth
 *
 * DESCR:       Creates a new element - Set interiour shading method
 * RETURNS:     N/A
 */

void pset_int_shad_meth(
   Pint shad_meth
   );

/*******************************************************************************
 * pset_refl_eqn
 *
 * DESCR:       Creates a new element - Set surface reflectance equation
 * RETURNS:     N/A
 */

void pset_refl_eqn(
   Pint refl_equ
   );

/*******************************************************************************
 * pset_refl_props
 *
 * DESCR:       Creates a new element - Set surface reflectance properties
 * RETURNS:     N/A
 */

void pset_refl_props(
   Prefl_props *refl_props
   );

/*******************************************************************************
 * ptranslate3
 *
 * DESCR:       Generate 3D translation matrix
 * RETURNS:     N/A
 */

void ptranslate3(
    Pvec3 *trans_vector,       /* translation vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * ptranslate
 *
 * DESCR:       Generate translation matrix
 * RETURNS:     N/A
 */

void ptranslate(
    Pvec *trans_vector,        /* translation vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT transformation matrix */
    );

/*******************************************************************************
 * pscale3
 *  
 * DESCR:       Generate 3D scaling matrix
 * RETURNS:     N/A
 */
    
void pscale3(
    Pvec3 *scale_vector,       /* scale factor vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * pscale
 *
 * DESCR:       Generate scaling matrix
 * RETURNS:     N/A
 */

void pscale(
    Pvec *scale_vector,        /* scale factor vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT transformation matrix */
    );

/*******************************************************************************
 * protate_x 
 *
 * DESCR:       Generate matrix for rotation around x-axis
 * RETURNS:     N/A
 */

void protate_x(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * protate_y
 *
 * DESCR:       Generate matrix for rotation around y-axis
 * RETURNS:     N/A
 */

void protate_y(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * protate_z
 *
 * DESCR:       Generate matrix for rotation around z-axis
 * RETURNS:     N/A
 */

void protate_z(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT transformation matrix */
    );

/*******************************************************************************
 * protate
 *  
 * DESCR:       Generate rotation matrix
 * RETURNS:     N/A
 */

void protate(
    Pfloat angle,              /* rotation angle */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT transformation matrix */
    );

/*******************************************************************************
 * pcompose_matrix3
 *
 * DESCR:       Generate combined 3D transformation matrix
 * RETURNS:     N/A
 */

void pcompose_matrix3(
    Pmatrix3 a,                /* matrix a */
    Pmatrix3 b,                /* matrix b */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT result matrix */
    );

/*******************************************************************************
 * pcompose_matrix
 *
 * DESCR:       Generate combined transformation matrix
 * RETURNS:     N/A
 */

void pcompose_matrix(
    Pmatrix a,                 /* matrix a */
    Pmatrix b,                 /* matrix b */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT result matrix */
    );

/*******************************************************************************
 * ptran_point3
 *
 * DESCR:       Translate 3D point using transformation matrix
 * RETURNS:     N/A
 */

void ptran_point3(
    Ppoint3 *p,                /* point */
    Pmatrix3 m,                /* transformation matrix */
    Pint *error_ind,           /* OUT error indicator */
    Ppoint3 *r                 /* OUT transformed point */
    );

/*******************************************************************************
 * ptran_point
 *
 * DESCR:       Translate point using transformation matrix
 * RETURNS:     N/A
 */

void ptran_point(
    Ppoint *p,                 /* point */
    Pmatrix m,                 /* transformation matrix */
    Pint *error_ind,           /* OUT error indicator */
    Ppoint *r                  /* OUT transformed point */
    );

/*******************************************************************************
 * pbuild_tran_matrix3
 *
 * DESCR:       Generate 3D transformation matrix
 * RETURNS:     N/A
 */

void pbuild_tran_matrix3(
    Ppoint3 *pt,               /* fixed point */
    Pvec3 *shift,              /* shift vector */
    Pfloat x_angle,            /* rotation angle X */
    Pfloat y_angle,            /* rotation angle Y */
    Pfloat z_angle,            /* rotation angle Z */
    Pvec3 *scale,              /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 matrix            /* OUT transformation matrix */
    );

/*******************************************************************************
 * void build_tran_matrix
 *
 * DESCR:       Generate transformation matrix
 * RETURNS:     N/A
 */

void pbuild_tran_matrix(
    Ppoint *pt,                /* fixed point */
    Pvec *shift,               /* shift vector */
    Pfloat angle,              /* rotation angle */
    Pvec *scale,               /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix matrix             /* OUT transformation matrix */
    );

/*******************************************************************************
 * pcompose_tran_matrix3
 *
 * DESCR:       Combine 3D transformation with other transformation matrix
 * RETURNS:     N/A
 */

void pcompose_tran_matrix3(
    Pmatrix3 m,                /* transformation matrix */
    Ppoint3 *pt,               /* fixed point */
    Pvec3 *shift,              /* shift vector */
    Pfloat x_ang,              /* rotation angle X */
    Pfloat y_ang,              /* rotation angle Y */
    Pfloat z_ang,              /* rotation angle Z */
    Pvec3 *scale,              /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 result            /* OUT transformation matrix */
    );

/*******************************************************************************
 * pcompose_tran_matrix
 *  
 * DESCR:       Combine transformation with other transformation matrix
 * RETURNS:     N/A            
 */ 

void pcompose_tran_matrix(
    Pmatrix m,                 /* transformation matrix */
    Ppoint *pt,                /* fixed point */
    Pvec *shift,               /* shift vector */
    Pfloat angle,              /* rotation angle */
    Pvec *scale,               /* scale vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix result             /* OUT transformation matrix */
    );

/*******************************************************************************
 * peval_view_ori_matrix3
 *
 * DESCR:       Generate 3D view orientation matrix
 * RETURNS:     N/A
 */

void peval_view_ori_matrix3(
    Ppoint3 *vrp,              /* view reference point */
    Pvec3 *vpn,                /* view plane normal */
    Pvec3 *vup,                /* view up vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT view orientation matrix */
    );

/*******************************************************************************
 * peval_view_ori_matrix
 *
 * DESCR:       Generate view orientation matrix
 * RETURNS:     N/A
 */

void peval_view_ori_matrix(
    Ppoint *vrp,               /* view reference point */
    Pvec *vup,                 /* view up vector */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT view orientation matrix */
    );

/*******************************************************************************
 * peval_view_map_matrix3
 *
 * DESCR:       Generate 3D view mapping matrix
 * RETURNS:     N/A
 */

void peval_view_map_matrix3(
    Pview_map3 *map,           /* view mapping */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix3 m                 /* OUT view mapping matrix */
    );

/*******************************************************************************
 * peval_view_map_matrix
 *
 * DESCR:       Generate view mapping matrix
 * RETURNS:     N/A
 */

void peval_view_map_matrix(
    Pview_map *map,            /* view mapping */
    Pint *error_ind,           /* OUT error indicator */
    Pmatrix m                  /* OUT view mapping matrix */
    );

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
   );

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
   );

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
   );

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
   );

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
   );

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
   );

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
   );

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
   );

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
   );

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
   );

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
   );

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
   );

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
   );

/*******************************************************************************
 * pget_loc
 *
 * DESCR:       Get locator event from event queue
 * RETURNS:     N/A
 */

void pget_loc(
   Pint *view_ind,
   Ppoint *loc_pos
   );

/*******************************************************************************
 * pget_loc3
 *
 * DESCR:       Get locator event from event queue 3D
 * RETURNS:     N/A
 */

void pget_loc3(
   Pint *view_ind,
   Ppoint3 *loc_pos
   );

/*******************************************************************************
 * pget_stroke
 *
 * DESCR:       Get stroke event from event queue
 * RETURNS:     N/A
 */

void pget_stroke(
   Pint *view_ind,
   Ppoint_list *stroke
   );

/*******************************************************************************
 * pget_stroke3
 *
 * DESCR:       Get stroke event from event queue 3D
 * RETURNS:     N/A
 */

void pget_stroke3(
   Pint *view_ind,
   Ppoint_list3 *stroke
   );

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
   );

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
   );

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
   );

/*******************************************************************************
 * pinq_disp_space_size3
 *
 * DESCR:       Get display size 3D
 * RETURNS:     N/A
 */

void pinq_disp_space_size3(
   Pint ws_type,
   Pint *err_ind,
   Pdisp_space_size3 *size
   );

#endif /* _phigsfunc_h */

