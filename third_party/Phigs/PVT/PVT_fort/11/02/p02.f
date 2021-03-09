C  *********************************************************
C  *                                                       *
C  *    TEST NUMBER: 11.02/02                              *
C  *    TEST TITLE : Prevent re-definition of function     *
C  *                 names                                 *
C  *                                                       *
C  *    PHIGS Validation Tests, produced by NIST           *
C  *                                                       *
C  *********************************************************

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20)
      REAL    DUMRL(20)

      COMMON /GLOBCH/ PIDENT,    GLBERR,    TSTMSG,     FUNCID,
     1                DUMCH
      CHARACTER       PIDENT*40, GLBERR*60, TSTMSG*900, FUNCID*80,
     1                DUMCH(20)*20

      INTEGER    UIN,UOUT, IOERR, NXTPOS, ITRIM, CC, LEADNB, LASTCH
      INTEGER    PPOS,DPOS,NPOS, NPOSZ, NUMCF, LO,HI, MID
      PARAMETER (NUMCF = 323)

      CHARACTER  MSG*300, INREC*500, LOGLIN*3000, FUNCNM*32
      CHARACTER  CFUNC(NUMCF)*32, CHBUF*3000

801   FORMAT (A)

      CALL INITGL ('11.02/02')

      CALL INMSG ('This program does not perform any test cases, '    //
     1            'but merely comments out any lines that re-define ' //
     2            'the standard long C function names.')

C  set up ordered table of PHIGS/C function names

      CFUNC(001) = 'padd_names_set'
      CFUNC(002) = 'panno_text_rel'
      CFUNC(003) = 'panno_text_rel3'
      CFUNC(004) = 'pappl_data'
      CFUNC(005) = 'par_all_structs'
      CFUNC(006) = 'par_struct_nets'
      CFUNC(007) = 'par_structs'
      CFUNC(008) = 'pawait_event'
      CFUNC(009) = 'pbuild_tran_matrix'
      CFUNC(010) = 'pbuild_tran_matrix3'
      CFUNC(011) = 'pcell_array'
      CFUNC(012) = 'pcell_array3'
      CFUNC(013) = 'pchange_struct_id'
      CFUNC(014) = 'pchange_struct_id_refs'
      CFUNC(015) = 'pchange_struct_refs'
      CFUNC(016) = 'pclose_ar_file'
      CFUNC(017) = 'pclose_phigs'
      CFUNC(018) = 'pclose_struct'
      CFUNC(019) = 'pclose_ws'
      CFUNC(020) = 'pcompose_matrix'
      CFUNC(021) = 'pcompose_matrix3'
      CFUNC(022) = 'pcompose_tran_matrix'
      CFUNC(023) = 'pcompose_tran_matrix3'
      CFUNC(024) = 'pcopy_all_elems_struct'
      CFUNC(025) = 'pcreate_store'
      CFUNC(026) = 'pdel_all_structs'
      CFUNC(027) = 'pdel_all_structs_ar'
      CFUNC(028) = 'pdel_elem'
      CFUNC(029) = 'pdel_elem_range'
      CFUNC(030) = 'pdel_elems_labels'
      CFUNC(031) = 'pdel_store'
      CFUNC(032) = 'pdel_struct'
      CFUNC(033) = 'pdel_struct_net'
      CFUNC(034) = 'pdel_struct_nets_ar'
      CFUNC(035) = 'pdel_structs_ar'
      CFUNC(036) = 'pelem_search'
      CFUNC(037) = 'pemergency_close_phigs'
      CFUNC(038) = 'pempty_struct'
      CFUNC(039) = 'perr_hand'
      CFUNC(040) = 'perr_log'
      CFUNC(041) = 'pescape'
      CFUNC(042) = 'peval_view_map_matrix'
      CFUNC(043) = 'peval_view_map_matrix3'
      CFUNC(044) = 'peval_view_ori_matrix'
      CFUNC(045) = 'peval_view_ori_matrix3'
      CFUNC(046) = 'pexec_struct'
      CFUNC(047) = 'pfill_area'
      CFUNC(048) = 'pfill_area3'
      CFUNC(049) = 'pfill_area_set'
      CFUNC(050) = 'pfill_area_set3'
      CFUNC(051) = 'pflush_events'
      CFUNC(052) = 'pgdp'
      CFUNC(053) = 'pgdp3'
      CFUNC(054) = 'pget_choice'
      CFUNC(055) = 'pget_item_type'
      CFUNC(056) = 'pget_loc'
      CFUNC(057) = 'pget_loc3'
      CFUNC(058) = 'pget_pick'
      CFUNC(059) = 'pget_string'
      CFUNC(060) = 'pget_stroke'
      CFUNC(061) = 'pget_stroke3'
      CFUNC(062) = 'pget_val'
      CFUNC(063) = 'pgse'
      CFUNC(064) = 'pincr_spa_search'
      CFUNC(065) = 'pincr_spa_search3'
      CFUNC(066) = 'pinit_choice'
      CFUNC(067) = 'pinit_choice3'
      CFUNC(068) = 'pinit_loc'
      CFUNC(069) = 'pinit_loc3'
      CFUNC(070) = 'pinit_pick'
      CFUNC(071) = 'pinit_pick3'
      CFUNC(072) = 'pinit_string'
      CFUNC(073) = 'pinit_string3'
      CFUNC(074) = 'pinit_stroke'
      CFUNC(075) = 'pinit_stroke3'
      CFUNC(076) = 'pinit_val'
      CFUNC(077) = 'pinit_val3'
      CFUNC(078) = 'pinq_all_conf_structs'
      CFUNC(079) = 'pinq_anno_facs'
      CFUNC(080) = 'pinq_ar_files'
      CFUNC(081) = 'pinq_ar_st'
      CFUNC(082) = 'pinq_choice_st'
      CFUNC(083) = 'pinq_choice_st3'
      CFUNC(084) = 'pinq_colr_facs'
      CFUNC(085) = 'pinq_colr_model'
      CFUNC(086) = 'pinq_colr_model_facs'
      CFUNC(087) = 'pinq_colr_rep'
      CFUNC(088) = 'pinq_conf_res'
      CFUNC(089) = 'pinq_conf_structs_net'
      CFUNC(090) = 'pinq_cur_elem_content'
      CFUNC(091) = 'pinq_cur_elem_type_size'
      CFUNC(092) = 'pinq_def_choice_data'
      CFUNC(093) = 'pinq_def_choice_data3'
      CFUNC(094) = 'pinq_def_disp_upd_st'
      CFUNC(095) = 'pinq_def_loc_data'
      CFUNC(096) = 'pinq_def_loc_data3'
      CFUNC(097) = 'pinq_def_pick_data'
      CFUNC(098) = 'pinq_def_pick_data3'
      CFUNC(099) = 'pinq_def_string_data'
      CFUNC(100) = 'pinq_def_string_data3'
      CFUNC(101) = 'pinq_def_stroke_data'
      CFUNC(102) = 'pinq_def_stroke_data3'
      CFUNC(103) = 'pinq_def_val_data'
      CFUNC(104) = 'pinq_def_val_data3'
      CFUNC(105) = 'pinq_disp_space_size'
      CFUNC(106) = 'pinq_disp_space_size3'
      CFUNC(107) = 'pinq_disp_upd_st'
      CFUNC(108) = 'pinq_dyns_structs'
      CFUNC(109) = 'pinq_dyns_ws_attrs'
      CFUNC(110) = 'pinq_edge_facs'
      CFUNC(111) = 'pinq_edge_rep'
      CFUNC(112) = 'pinq_edit_mode'
      CFUNC(113) = 'pinq_elem_content'
      CFUNC(114) = 'pinq_elem_ptr'
      CFUNC(115) = 'pinq_elem_type_size'
      CFUNC(116) = 'pinq_err_hand_mode'
      CFUNC(117) = 'pinq_gdp'
      CFUNC(118) = 'pinq_gdp3'
      CFUNC(119) = 'pinq_gse_facs'
      CFUNC(120) = 'pinq_highl_filter'
      CFUNC(121) = 'pinq_hlhsr_id_facs'
      CFUNC(122) = 'pinq_hlhsr_mode'
      CFUNC(123) = 'pinq_hlhsr_mode_facs'
      CFUNC(124) = 'pinq_in_overf'
      CFUNC(125) = 'pinq_int_facs'
      CFUNC(126) = 'pinq_int_rep'
      CFUNC(127) = 'pinq_invis_filter'
      CFUNC(128) = 'pinq_line_facs'
      CFUNC(129) = 'pinq_line_rep'
      CFUNC(130) = 'pinq_list_avail_gdp'
      CFUNC(131) = 'pinq_list_avail_gdp3'
      CFUNC(132) = 'pinq_list_avail_gse'
      CFUNC(133) = 'pinq_list_avail_ws_types'
      CFUNC(134) = 'pinq_list_colr_inds'
      CFUNC(135) = 'pinq_list_edge_inds'
      CFUNC(136) = 'pinq_list_int_inds'
      CFUNC(137) = 'pinq_list_line_inds'
      CFUNC(138) = 'pinq_list_marker_inds'
      CFUNC(139) = 'pinq_list_pat_inds'
      CFUNC(140) = 'pinq_list_text_inds'
      CFUNC(141) = 'pinq_list_view_inds'
      CFUNC(142) = 'pinq_loc_st'
      CFUNC(143) = 'pinq_loc_st3'
      CFUNC(144) = 'pinq_marker_facs'
      CFUNC(145) = 'pinq_marker_rep'
      CFUNC(146) = 'pinq_model_clip_facs'
      CFUNC(147) = 'pinq_more_simult_events'
      CFUNC(148) = 'pinq_num_avail_in'
      CFUNC(149) = 'pinq_num_disp_pris'
      CFUNC(150) = 'pinq_open_struct'
      CFUNC(151) = 'pinq_open_wss'
      CFUNC(152) = 'pinq_pat_facs'
      CFUNC(153) = 'pinq_pat_rep'
      CFUNC(154) = 'pinq_paths_ances'
      CFUNC(155) = 'pinq_paths_descs'
      CFUNC(156) = 'pinq_phigs_facs'
      CFUNC(157) = 'pinq_pick_st'
      CFUNC(158) = 'pinq_pick_st3'
      CFUNC(159) = 'pinq_posted_structs'
      CFUNC(160) = 'pinq_pred_colr_rep'
      CFUNC(161) = 'pinq_pred_edge_rep'
      CFUNC(162) = 'pinq_pred_int_rep'
      CFUNC(163) = 'pinq_pred_line_rep'
      CFUNC(164) = 'pinq_pred_marker_rep'
      CFUNC(165) = 'pinq_pred_pat_rep'
      CFUNC(166) = 'pinq_pred_text_rep'
      CFUNC(167) = 'pinq_pred_view_rep'
      CFUNC(168) = 'pinq_string_st'
      CFUNC(169) = 'pinq_string_st3'
      CFUNC(170) = 'pinq_stroke_st'
      CFUNC(171) = 'pinq_stroke_st3'
      CFUNC(172) = 'pinq_struct_ids'
      CFUNC(173) = 'pinq_struct_st'
      CFUNC(174) = 'pinq_struct_status'
      CFUNC(175) = 'pinq_sys_st'
      CFUNC(176) = 'pinq_text_extent'
      CFUNC(177) = 'pinq_text_facs'
      CFUNC(178) = 'pinq_text_rep'
      CFUNC(179) = 'pinq_val_st'
      CFUNC(180) = 'pinq_val_st3'
      CFUNC(181) = 'pinq_view_facs'
      CFUNC(182) = 'pinq_view_rep'
      CFUNC(183) = 'pinq_ws_cat'
      CFUNC(184) = 'pinq_ws_class'
      CFUNC(185) = 'pinq_ws_conn_type'
      CFUNC(186) = 'pinq_ws_st'
      CFUNC(187) = 'pinq_ws_st_table'
      CFUNC(188) = 'pinq_ws_tran'
      CFUNC(189) = 'pinq_ws_tran3'
      CFUNC(190) = 'pinq_wss_posted'
      CFUNC(191) = 'pinterpret_item'
      CFUNC(192) = 'plabel'
      CFUNC(193) = 'pmessage'
      CFUNC(194) = 'poffset_elem_ptr'
      CFUNC(195) = 'popen_ar_file'
      CFUNC(196) = 'popen_phigs'
      CFUNC(197) = 'popen_struct'
      CFUNC(198) = 'popen_ws'
      CFUNC(199) = 'ppolyline'
      CFUNC(200) = 'ppolyline3'
      CFUNC(201) = 'ppolymarker'
      CFUNC(202) = 'ppolymarker3'
      CFUNC(203) = 'ppost_struct'
      CFUNC(204) = 'pread_item'
      CFUNC(205) = 'predraw_all_structs'
      CFUNC(206) = 'premove_names_set'
      CFUNC(207) = 'preq_choice'
      CFUNC(208) = 'preq_loc'
      CFUNC(209) = 'preq_loc3'
      CFUNC(210) = 'preq_pick'
      CFUNC(211) = 'preq_string'
      CFUNC(212) = 'preq_stroke'
      CFUNC(213) = 'preq_stroke3'
      CFUNC(214) = 'preq_val'
      CFUNC(215) = 'prestore_model_clip_vol'
      CFUNC(216) = 'pret_all_structs'
      CFUNC(217) = 'pret_paths_ances'
      CFUNC(218) = 'pret_paths_descs'
      CFUNC(219) = 'pret_struct_ids'
      CFUNC(220) = 'pret_struct_nets'
      CFUNC(221) = 'pret_structs'
      CFUNC(222) = 'protate'
      CFUNC(223) = 'protate_x'
      CFUNC(224) = 'protate_y'
      CFUNC(225) = 'protate_z'
      CFUNC(226) = 'psample_choice'
      CFUNC(227) = 'psample_loc'
      CFUNC(228) = 'psample_loc3'
      CFUNC(229) = 'psample_pick'
      CFUNC(230) = 'psample_string'
      CFUNC(231) = 'psample_stroke'
      CFUNC(232) = 'psample_stroke3'
      CFUNC(233) = 'psample_val'
      CFUNC(234) = 'pscale'
      CFUNC(235) = 'pscale3'
      CFUNC(236) = 'pset_anno_align'
      CFUNC(237) = 'pset_anno_char_ht'
      CFUNC(238) = 'pset_anno_char_up_vec'
      CFUNC(239) = 'pset_anno_path'
      CFUNC(240) = 'pset_anno_style'
      CFUNC(241) = 'pset_char_expan'
      CFUNC(242) = 'pset_char_ht'
      CFUNC(243) = 'pset_char_space'
      CFUNC(244) = 'pset_char_up_vec'
      CFUNC(245) = 'pset_choice_mode'
      CFUNC(246) = 'pset_colr_model'
      CFUNC(247) = 'pset_colr_rep'
      CFUNC(248) = 'pset_conf_res'
      CFUNC(249) = 'pset_disp_upd_st'
      CFUNC(250) = 'pset_edge_colr_ind'
      CFUNC(251) = 'pset_edge_flag'
      CFUNC(252) = 'pset_edge_ind'
      CFUNC(253) = 'pset_edge_rep'
      CFUNC(254) = 'pset_edgetype'
      CFUNC(255) = 'pset_edgewidth'
      CFUNC(256) = 'pset_edit_mode'
      CFUNC(257) = 'pset_elem_ptr'
      CFUNC(258) = 'pset_elem_ptr_label'
      CFUNC(259) = 'pset_err_hand'
      CFUNC(260) = 'pset_err_hand_mode'
      CFUNC(261) = 'pset_global_tran'
      CFUNC(262) = 'pset_global_tran3'
      CFUNC(263) = 'pset_highl_filter'
      CFUNC(264) = 'pset_hlhsr_id'
      CFUNC(265) = 'pset_hlhsr_mode'
      CFUNC(266) = 'pset_indiv_asf'
      CFUNC(267) = 'pset_int_colr_ind'
      CFUNC(268) = 'pset_int_ind'
      CFUNC(269) = 'pset_int_rep'
      CFUNC(270) = 'pset_int_style'
      CFUNC(271) = 'pset_int_style_ind'
      CFUNC(272) = 'pset_invis_filter'
      CFUNC(273) = 'pset_line_colr_ind'
      CFUNC(274) = 'pset_line_ind'
      CFUNC(275) = 'pset_line_rep'
      CFUNC(276) = 'pset_linetype'
      CFUNC(277) = 'pset_linewidth'
      CFUNC(278) = 'pset_loc_mode'
      CFUNC(279) = 'pset_local_tran'
      CFUNC(280) = 'pset_local_tran3'
      CFUNC(281) = 'pset_marker_colr_ind'
      CFUNC(282) = 'pset_marker_ind'
      CFUNC(283) = 'pset_marker_rep'
      CFUNC(284) = 'pset_marker_size'
      CFUNC(285) = 'pset_marker_type'
      CFUNC(286) = 'pset_model_clip_ind'
      CFUNC(287) = 'pset_model_clip_vol'
      CFUNC(288) = 'pset_model_clip_vol3'
      CFUNC(289) = 'pset_pat_ref_point'
      CFUNC(290) = 'pset_pat_ref_point_vecs'
      CFUNC(291) = 'pset_pat_rep'
      CFUNC(292) = 'pset_pat_size'
      CFUNC(293) = 'pset_pick_filter'
      CFUNC(294) = 'pset_pick_id'
      CFUNC(295) = 'pset_pick_mode'
      CFUNC(296) = 'pset_string_mode'
      CFUNC(297) = 'pset_stroke_mode'
      CFUNC(298) = 'pset_text_align'
      CFUNC(299) = 'pset_text_colr_ind'
      CFUNC(300) = 'pset_text_font'
      CFUNC(301) = 'pset_text_ind'
      CFUNC(302) = 'pset_text_path'
      CFUNC(303) = 'pset_text_prec'
      CFUNC(304) = 'pset_text_rep'
      CFUNC(305) = 'pset_val_mode'
      CFUNC(306) = 'pset_view_ind'
      CFUNC(307) = 'pset_view_rep'
      CFUNC(308) = 'pset_view_rep3'
      CFUNC(309) = 'pset_view_tran_in_pri'
      CFUNC(310) = 'pset_ws_vp'
      CFUNC(311) = 'pset_ws_vp3'
      CFUNC(312) = 'pset_ws_win'
      CFUNC(313) = 'pset_ws_win3'
      CFUNC(314) = 'ptext'
      CFUNC(315) = 'ptext3'
      CFUNC(316) = 'ptran_point'
      CFUNC(317) = 'ptran_point3'
      CFUNC(318) = 'ptranslate'
      CFUNC(319) = 'ptranslate3'
      CFUNC(320) = 'punpost_all_structs'
      CFUNC(321) = 'punpost_struct'
      CFUNC(322) = 'pupd_ws'
      CFUNC(323) = 'pwrite_item'

      UIN  = MAX(20, INDLUN, GLBLUN) + 1
      UOUT = UIN+1

C  open output file
      OPEN (UNIT=UOUT, IOSTAT=IOERR, FILE='phigs.c', RECL=9000,
     1      STATUS='UNKNOWN', FORM='FORMATTED')
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code opening output file ' //
     1          'phigs.c = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF
      REWIND (UNIT=UOUT, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code rewinding output file ' //
     1          'phigs.c = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF

C  open input file
      OPEN (UNIT=UIN, IOSTAT=IOERR, FILE='phigs.h', RECL=2000,
     1      STATUS='OLD', FORM='FORMATTED')
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code opening input file ' //
     1          'phigs.h = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF
      REWIND (UNIT=UIN, IOSTAT=IOERR)
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error code rewinding input file ' //
     1          'phigs.h = ', IOERR, '.'
         CALL UNMSG (MSG)
      ENDIF

C  begin read-write loop for next logical line
100   CONTINUE
      LOGLIN = ' '
      NXTPOS = 1

C  get next record
110   CONTINUE
      READ (UNIT=UIN, FMT=801, END=666, IOSTAT=IOERR) INREC
      IF (IOERR .NE. 0) THEN
         WRITE (MSG, '(A,I6,A)') 'Error #', IOERR,
     1                           ' occurred reading phigs.h.'
         CALL UNMSG (MSG)
      ENDIF
C  ensure a non-blank logical line
      IF (INREC .EQ. ' ') GOTO 110
      LOGLIN (NXTPOS:) = INREC
      NXTPOS = ITRIM(LOGLIN)
      IF (LOGLIN(NXTPOS:NXTPOS) .EQ. '\') GOTO 110
      LASTCH = NXTPOS

CUSERMOD  convert HT,LF,VT,FF,CR to space
C  convert all white space to spaces - we'll take
C  these to be ASCII 9-13 ...
      DO 310 CC = 9,13
315      CONTINUE
         NXTPOS = INDEX(LOGLIN, CHAR(CC))
         IF (NXTPOS .NE. 0) THEN
            LOGLIN(NXTPOS:NXTPOS) = ' '
            GOTO 315
         ENDIF
310   CONTINUE

C  comment out re-defines of C-functions - leave all other logical
C  lines alone

C  search for #
      PPOS = LEADNB(LOGLIN)
      IF (LOGLIN(PPOS:PPOS) .NE. '#') GOTO 400
C  search for define
      DPOS = LEADNB(LOGLIN(PPOS+1:))
      IF (DPOS.EQ.0) GOTO 400
      DPOS = DPOS + PPOS
      IF (LOGLIN(DPOS:DPOS+6) .NE. 'define ') GOTO 400
C  search for function name
      NPOS = LEADNB(LOGLIN(DPOS+6:))
      IF (NPOS.EQ.0) GOTO 400
      NPOS = NPOS + DPOS + 5
C  search for end of function name
      NPOSZ = INDEX(LOGLIN(NPOS:), ' ')
      IF (NPOSZ.EQ.0) THEN
         CALL INMSG ('Suspicious logical line: no blank found after ' //
     1               'name to be defined: ' // LOGLIN(NPOS:))
         GOTO 400
      ENDIF
      NPOSZ = NPOSZ + NPOS - 2
      FUNCNM = LOGLIN(NPOS:NPOSZ)

C  do binary search to see if found;  possible names are strictly
C  between LO and HI
      LO = 0
      HI = NUMCF+1

300   CONTINUE
      MID = (LO+HI)/2
      IF (FUNCNM .EQ. CFUNC(MID)) THEN
         CHBUF = '/* ' // LOGLIN(:LASTCH) // ' */'
         LOGLIN = CHBUF
         LASTCH = LASTCH + 6
         GOTO 400
      ELSEIF (FUNCNM .LT. CFUNC(MID)) THEN
         HI = MID
      ELSE
         LO = MID
      ENDIF
      IF (HI-LO .GE. 2)  GOTO 300

400   CONTINUE
      WRITE (UNIT=UOUT, FMT=801) LOGLIN(1:LASTCH)

      GOTO 100

666   CONTINUE
      CLOSE (UNIT=UOUT)
      CLOSE (UNIT=UIN)

      CALL WINDUP
      END
