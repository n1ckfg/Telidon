/* fort/11/02/p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw, 
	    errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[
	    20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_

struct {
    char pident[40], glberr[60], tstmsg[900], funcid[80], dumch[400];
} globch_;

#define globch_1 globch_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 11.02/02                              * */
/*  *    TEST TITLE : Prevent re-definition of function     * */
/*  *                 names                                 * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Main program */ MAIN__(void)
#else /* NO_PROTO */
/* Main program */ MAIN__()
#endif /* NO_PROTO */
{
    /* Format strings */
    static char fmt_801[] = "(a)";

    /* System generated locals */
    address a__1[2], a__2[3];
    integer i__1, i__2[2], i__3[3];
    char ch__1[1], ch__2[3066];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_open(olist *), s_wsfi(icilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfi(void), f_rew(alist *), s_rsfe(cilist *), e_rsfe(
	    void), s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char 
	    *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer f_open(), s_wsfi(), do_fio(), e_wsfi(), f_rew(), s_rsfe(), e_rsfe(
	    ), s_cmp(), i_indx();
    /* Subroutine */ int s_cat();
    integer s_wsfe(), e_wsfe(), f_clos();
#endif /* NO_PROTO */

#ifndef NO_PROTO
    integer s_wsfe(cilist *), e_wsfe(void), f_clos(cllist *);

#endif /* not NO_PROTO */
    /* Local variables */
    static integer cc, hi, lo, mid;
    static char msg[300];
    static integer uin, dpos, npos, ppos, uout;
    static char chbuf[3000], cfunc[32*323], inrec[500];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_();
#endif /* NO_PROTO */
    static integer ioerr;
#ifndef NO_PROTO
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */
    static integer nposz;
#ifndef NO_PROTO
    extern integer leadnb_(char *, ftnlen);
#else /* NO_PROTO */
    extern integer leadnb_();
#endif /* NO_PROTO */
    static integer lastch;
    static char loglin[3000], funcnm[32];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen), windup_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_(), windup_();
#endif /* NO_PROTO */
    static integer nxtpos;

    /* Fortran I/O blocks */
    static icilist io___6 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static icilist io___7 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static icilist io___8 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static icilist io___9 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static cilist io___12 = { 1, 0, 1, fmt_801, 0 };
    static icilist io___14 = { 0, msg, 0, "(A,I6,A)", 300, 1 };
    static cilist io___26 = { 0, 0, 0, fmt_801, 0 };


/* L801: */
    initgl_("11.02/02", 8L);
#ifndef NO_PROTO
    inmsg_("This program does not perform any test cases, but merely comment"
	    "s out any lines that re-define the standard long C function name"
	    "s.", 130L);
#else /* NO_PROTO */
    inmsg_("This program does not perform any test cases, but merely comment\
s out any lines that re-define the standard long C function names.", 130L);
#endif /* NO_PROTO */
/*  set up ordered table of PHIGS/C function names */
    s_copy(cfunc, "padd_names_set", 32L, 14L);
    s_copy(cfunc + 32, "panno_text_rel", 32L, 14L);
    s_copy(cfunc + 64, "panno_text_rel3", 32L, 15L);
    s_copy(cfunc + 96, "pappl_data", 32L, 10L);
    s_copy(cfunc + 128, "par_all_structs", 32L, 15L);
    s_copy(cfunc + 160, "par_struct_nets", 32L, 15L);
    s_copy(cfunc + 192, "par_structs", 32L, 11L);
    s_copy(cfunc + 224, "pawait_event", 32L, 12L);
    s_copy(cfunc + 256, "pbuild_tran_matrix", 32L, 18L);
    s_copy(cfunc + 288, "pbuild_tran_matrix3", 32L, 19L);
    s_copy(cfunc + 320, "pcell_array", 32L, 11L);
    s_copy(cfunc + 352, "pcell_array3", 32L, 12L);
    s_copy(cfunc + 384, "pchange_struct_id", 32L, 17L);
    s_copy(cfunc + 416, "pchange_struct_id_refs", 32L, 22L);
    s_copy(cfunc + 448, "pchange_struct_refs", 32L, 19L);
    s_copy(cfunc + 480, "pclose_ar_file", 32L, 14L);
    s_copy(cfunc + 512, "pclose_phigs", 32L, 12L);
    s_copy(cfunc + 544, "pclose_struct", 32L, 13L);
    s_copy(cfunc + 576, "pclose_ws", 32L, 9L);
    s_copy(cfunc + 608, "pcompose_matrix", 32L, 15L);
    s_copy(cfunc + 640, "pcompose_matrix3", 32L, 16L);
    s_copy(cfunc + 672, "pcompose_tran_matrix", 32L, 20L);
    s_copy(cfunc + 704, "pcompose_tran_matrix3", 32L, 21L);
    s_copy(cfunc + 736, "pcopy_all_elems_struct", 32L, 22L);
    s_copy(cfunc + 768, "pcreate_store", 32L, 13L);
    s_copy(cfunc + 800, "pdel_all_structs", 32L, 16L);
    s_copy(cfunc + 832, "pdel_all_structs_ar", 32L, 19L);
    s_copy(cfunc + 864, "pdel_elem", 32L, 9L);
    s_copy(cfunc + 896, "pdel_elem_range", 32L, 15L);
    s_copy(cfunc + 928, "pdel_elems_labels", 32L, 17L);
    s_copy(cfunc + 960, "pdel_store", 32L, 10L);
    s_copy(cfunc + 992, "pdel_struct", 32L, 11L);
    s_copy(cfunc + 1024, "pdel_struct_net", 32L, 15L);
    s_copy(cfunc + 1056, "pdel_struct_nets_ar", 32L, 19L);
    s_copy(cfunc + 1088, "pdel_structs_ar", 32L, 15L);
    s_copy(cfunc + 1120, "pelem_search", 32L, 12L);
    s_copy(cfunc + 1152, "pemergency_close_phigs", 32L, 22L);
    s_copy(cfunc + 1184, "pempty_struct", 32L, 13L);
    s_copy(cfunc + 1216, "perr_hand", 32L, 9L);
    s_copy(cfunc + 1248, "perr_log", 32L, 8L);
    s_copy(cfunc + 1280, "pescape", 32L, 7L);
    s_copy(cfunc + 1312, "peval_view_map_matrix", 32L, 21L);
    s_copy(cfunc + 1344, "peval_view_map_matrix3", 32L, 22L);
    s_copy(cfunc + 1376, "peval_view_ori_matrix", 32L, 21L);
    s_copy(cfunc + 1408, "peval_view_ori_matrix3", 32L, 22L);
    s_copy(cfunc + 1440, "pexec_struct", 32L, 12L);
    s_copy(cfunc + 1472, "pfill_area", 32L, 10L);
    s_copy(cfunc + 1504, "pfill_area3", 32L, 11L);
    s_copy(cfunc + 1536, "pfill_area_set", 32L, 14L);
    s_copy(cfunc + 1568, "pfill_area_set3", 32L, 15L);
    s_copy(cfunc + 1600, "pflush_events", 32L, 13L);
    s_copy(cfunc + 1632, "pgdp", 32L, 4L);
    s_copy(cfunc + 1664, "pgdp3", 32L, 5L);
    s_copy(cfunc + 1696, "pget_choice", 32L, 11L);
    s_copy(cfunc + 1728, "pget_item_type", 32L, 14L);
    s_copy(cfunc + 1760, "pget_loc", 32L, 8L);
    s_copy(cfunc + 1792, "pget_loc3", 32L, 9L);
    s_copy(cfunc + 1824, "pget_pick", 32L, 9L);
    s_copy(cfunc + 1856, "pget_string", 32L, 11L);
    s_copy(cfunc + 1888, "pget_stroke", 32L, 11L);
    s_copy(cfunc + 1920, "pget_stroke3", 32L, 12L);
    s_copy(cfunc + 1952, "pget_val", 32L, 8L);
    s_copy(cfunc + 1984, "pgse", 32L, 4L);
    s_copy(cfunc + 2016, "pincr_spa_search", 32L, 16L);
    s_copy(cfunc + 2048, "pincr_spa_search3", 32L, 17L);
    s_copy(cfunc + 2080, "pinit_choice", 32L, 12L);
    s_copy(cfunc + 2112, "pinit_choice3", 32L, 13L);
    s_copy(cfunc + 2144, "pinit_loc", 32L, 9L);
    s_copy(cfunc + 2176, "pinit_loc3", 32L, 10L);
    s_copy(cfunc + 2208, "pinit_pick", 32L, 10L);
    s_copy(cfunc + 2240, "pinit_pick3", 32L, 11L);
    s_copy(cfunc + 2272, "pinit_string", 32L, 12L);
    s_copy(cfunc + 2304, "pinit_string3", 32L, 13L);
    s_copy(cfunc + 2336, "pinit_stroke", 32L, 12L);
    s_copy(cfunc + 2368, "pinit_stroke3", 32L, 13L);
    s_copy(cfunc + 2400, "pinit_val", 32L, 9L);
    s_copy(cfunc + 2432, "pinit_val3", 32L, 10L);
    s_copy(cfunc + 2464, "pinq_all_conf_structs", 32L, 21L);
    s_copy(cfunc + 2496, "pinq_anno_facs", 32L, 14L);
    s_copy(cfunc + 2528, "pinq_ar_files", 32L, 13L);
    s_copy(cfunc + 2560, "pinq_ar_st", 32L, 10L);
    s_copy(cfunc + 2592, "pinq_choice_st", 32L, 14L);
    s_copy(cfunc + 2624, "pinq_choice_st3", 32L, 15L);
    s_copy(cfunc + 2656, "pinq_colr_facs", 32L, 14L);
    s_copy(cfunc + 2688, "pinq_colr_model", 32L, 15L);
    s_copy(cfunc + 2720, "pinq_colr_model_facs", 32L, 20L);
    s_copy(cfunc + 2752, "pinq_colr_rep", 32L, 13L);
    s_copy(cfunc + 2784, "pinq_conf_res", 32L, 13L);
    s_copy(cfunc + 2816, "pinq_conf_structs_net", 32L, 21L);
    s_copy(cfunc + 2848, "pinq_cur_elem_content", 32L, 21L);
    s_copy(cfunc + 2880, "pinq_cur_elem_type_size", 32L, 23L);
    s_copy(cfunc + 2912, "pinq_def_choice_data", 32L, 20L);
    s_copy(cfunc + 2944, "pinq_def_choice_data3", 32L, 21L);
    s_copy(cfunc + 2976, "pinq_def_disp_upd_st", 32L, 20L);
    s_copy(cfunc + 3008, "pinq_def_loc_data", 32L, 17L);
    s_copy(cfunc + 3040, "pinq_def_loc_data3", 32L, 18L);
    s_copy(cfunc + 3072, "pinq_def_pick_data", 32L, 18L);
    s_copy(cfunc + 3104, "pinq_def_pick_data3", 32L, 19L);
    s_copy(cfunc + 3136, "pinq_def_string_data", 32L, 20L);
    s_copy(cfunc + 3168, "pinq_def_string_data3", 32L, 21L);
    s_copy(cfunc + 3200, "pinq_def_stroke_data", 32L, 20L);
    s_copy(cfunc + 3232, "pinq_def_stroke_data3", 32L, 21L);
    s_copy(cfunc + 3264, "pinq_def_val_data", 32L, 17L);
    s_copy(cfunc + 3296, "pinq_def_val_data3", 32L, 18L);
    s_copy(cfunc + 3328, "pinq_disp_space_size", 32L, 20L);
    s_copy(cfunc + 3360, "pinq_disp_space_size3", 32L, 21L);
    s_copy(cfunc + 3392, "pinq_disp_upd_st", 32L, 16L);
    s_copy(cfunc + 3424, "pinq_dyns_structs", 32L, 17L);
    s_copy(cfunc + 3456, "pinq_dyns_ws_attrs", 32L, 18L);
    s_copy(cfunc + 3488, "pinq_edge_facs", 32L, 14L);
    s_copy(cfunc + 3520, "pinq_edge_rep", 32L, 13L);
    s_copy(cfunc + 3552, "pinq_edit_mode", 32L, 14L);
    s_copy(cfunc + 3584, "pinq_elem_content", 32L, 17L);
    s_copy(cfunc + 3616, "pinq_elem_ptr", 32L, 13L);
    s_copy(cfunc + 3648, "pinq_elem_type_size", 32L, 19L);
    s_copy(cfunc + 3680, "pinq_err_hand_mode", 32L, 18L);
    s_copy(cfunc + 3712, "pinq_gdp", 32L, 8L);
    s_copy(cfunc + 3744, "pinq_gdp3", 32L, 9L);
    s_copy(cfunc + 3776, "pinq_gse_facs", 32L, 13L);
    s_copy(cfunc + 3808, "pinq_highl_filter", 32L, 17L);
    s_copy(cfunc + 3840, "pinq_hlhsr_id_facs", 32L, 18L);
    s_copy(cfunc + 3872, "pinq_hlhsr_mode", 32L, 15L);
    s_copy(cfunc + 3904, "pinq_hlhsr_mode_facs", 32L, 20L);
    s_copy(cfunc + 3936, "pinq_in_overf", 32L, 13L);
    s_copy(cfunc + 3968, "pinq_int_facs", 32L, 13L);
    s_copy(cfunc + 4000, "pinq_int_rep", 32L, 12L);
    s_copy(cfunc + 4032, "pinq_invis_filter", 32L, 17L);
    s_copy(cfunc + 4064, "pinq_line_facs", 32L, 14L);
    s_copy(cfunc + 4096, "pinq_line_rep", 32L, 13L);
    s_copy(cfunc + 4128, "pinq_list_avail_gdp", 32L, 19L);
    s_copy(cfunc + 4160, "pinq_list_avail_gdp3", 32L, 20L);
    s_copy(cfunc + 4192, "pinq_list_avail_gse", 32L, 19L);
    s_copy(cfunc + 4224, "pinq_list_avail_ws_types", 32L, 24L);
    s_copy(cfunc + 4256, "pinq_list_colr_inds", 32L, 19L);
    s_copy(cfunc + 4288, "pinq_list_edge_inds", 32L, 19L);
    s_copy(cfunc + 4320, "pinq_list_int_inds", 32L, 18L);
    s_copy(cfunc + 4352, "pinq_list_line_inds", 32L, 19L);
    s_copy(cfunc + 4384, "pinq_list_marker_inds", 32L, 21L);
    s_copy(cfunc + 4416, "pinq_list_pat_inds", 32L, 18L);
    s_copy(cfunc + 4448, "pinq_list_text_inds", 32L, 19L);
    s_copy(cfunc + 4480, "pinq_list_view_inds", 32L, 19L);
    s_copy(cfunc + 4512, "pinq_loc_st", 32L, 11L);
    s_copy(cfunc + 4544, "pinq_loc_st3", 32L, 12L);
    s_copy(cfunc + 4576, "pinq_marker_facs", 32L, 16L);
    s_copy(cfunc + 4608, "pinq_marker_rep", 32L, 15L);
    s_copy(cfunc + 4640, "pinq_model_clip_facs", 32L, 20L);
    s_copy(cfunc + 4672, "pinq_more_simult_events", 32L, 23L);
    s_copy(cfunc + 4704, "pinq_num_avail_in", 32L, 17L);
    s_copy(cfunc + 4736, "pinq_num_disp_pris", 32L, 18L);
    s_copy(cfunc + 4768, "pinq_open_struct", 32L, 16L);
    s_copy(cfunc + 4800, "pinq_open_wss", 32L, 13L);
    s_copy(cfunc + 4832, "pinq_pat_facs", 32L, 13L);
    s_copy(cfunc + 4864, "pinq_pat_rep", 32L, 12L);
    s_copy(cfunc + 4896, "pinq_paths_ances", 32L, 16L);
    s_copy(cfunc + 4928, "pinq_paths_descs", 32L, 16L);
    s_copy(cfunc + 4960, "pinq_phigs_facs", 32L, 15L);
    s_copy(cfunc + 4992, "pinq_pick_st", 32L, 12L);
    s_copy(cfunc + 5024, "pinq_pick_st3", 32L, 13L);
    s_copy(cfunc + 5056, "pinq_posted_structs", 32L, 19L);
    s_copy(cfunc + 5088, "pinq_pred_colr_rep", 32L, 18L);
    s_copy(cfunc + 5120, "pinq_pred_edge_rep", 32L, 18L);
    s_copy(cfunc + 5152, "pinq_pred_int_rep", 32L, 17L);
    s_copy(cfunc + 5184, "pinq_pred_line_rep", 32L, 18L);
    s_copy(cfunc + 5216, "pinq_pred_marker_rep", 32L, 20L);
    s_copy(cfunc + 5248, "pinq_pred_pat_rep", 32L, 17L);
    s_copy(cfunc + 5280, "pinq_pred_text_rep", 32L, 18L);
    s_copy(cfunc + 5312, "pinq_pred_view_rep", 32L, 18L);
    s_copy(cfunc + 5344, "pinq_string_st", 32L, 14L);
    s_copy(cfunc + 5376, "pinq_string_st3", 32L, 15L);
    s_copy(cfunc + 5408, "pinq_stroke_st", 32L, 14L);
    s_copy(cfunc + 5440, "pinq_stroke_st3", 32L, 15L);
    s_copy(cfunc + 5472, "pinq_struct_ids", 32L, 15L);
    s_copy(cfunc + 5504, "pinq_struct_st", 32L, 14L);
    s_copy(cfunc + 5536, "pinq_struct_status", 32L, 18L);
    s_copy(cfunc + 5568, "pinq_sys_st", 32L, 11L);
    s_copy(cfunc + 5600, "pinq_text_extent", 32L, 16L);
    s_copy(cfunc + 5632, "pinq_text_facs", 32L, 14L);
    s_copy(cfunc + 5664, "pinq_text_rep", 32L, 13L);
    s_copy(cfunc + 5696, "pinq_val_st", 32L, 11L);
    s_copy(cfunc + 5728, "pinq_val_st3", 32L, 12L);
    s_copy(cfunc + 5760, "pinq_view_facs", 32L, 14L);
    s_copy(cfunc + 5792, "pinq_view_rep", 32L, 13L);
    s_copy(cfunc + 5824, "pinq_ws_cat", 32L, 11L);
    s_copy(cfunc + 5856, "pinq_ws_class", 32L, 13L);
    s_copy(cfunc + 5888, "pinq_ws_conn_type", 32L, 17L);
    s_copy(cfunc + 5920, "pinq_ws_st", 32L, 10L);
    s_copy(cfunc + 5952, "pinq_ws_st_table", 32L, 16L);
    s_copy(cfunc + 5984, "pinq_ws_tran", 32L, 12L);
    s_copy(cfunc + 6016, "pinq_ws_tran3", 32L, 13L);
    s_copy(cfunc + 6048, "pinq_wss_posted", 32L, 15L);
    s_copy(cfunc + 6080, "pinterpret_item", 32L, 15L);
    s_copy(cfunc + 6112, "plabel", 32L, 6L);
    s_copy(cfunc + 6144, "pmessage", 32L, 8L);
    s_copy(cfunc + 6176, "poffset_elem_ptr", 32L, 16L);
    s_copy(cfunc + 6208, "popen_ar_file", 32L, 13L);
    s_copy(cfunc + 6240, "popen_phigs", 32L, 11L);
    s_copy(cfunc + 6272, "popen_struct", 32L, 12L);
    s_copy(cfunc + 6304, "popen_ws", 32L, 8L);
    s_copy(cfunc + 6336, "ppolyline", 32L, 9L);
    s_copy(cfunc + 6368, "ppolyline3", 32L, 10L);
    s_copy(cfunc + 6400, "ppolymarker", 32L, 11L);
    s_copy(cfunc + 6432, "ppolymarker3", 32L, 12L);
    s_copy(cfunc + 6464, "ppost_struct", 32L, 12L);
    s_copy(cfunc + 6496, "pread_item", 32L, 10L);
    s_copy(cfunc + 6528, "predraw_all_structs", 32L, 19L);
    s_copy(cfunc + 6560, "premove_names_set", 32L, 17L);
    s_copy(cfunc + 6592, "preq_choice", 32L, 11L);
    s_copy(cfunc + 6624, "preq_loc", 32L, 8L);
    s_copy(cfunc + 6656, "preq_loc3", 32L, 9L);
    s_copy(cfunc + 6688, "preq_pick", 32L, 9L);
    s_copy(cfunc + 6720, "preq_string", 32L, 11L);
    s_copy(cfunc + 6752, "preq_stroke", 32L, 11L);
    s_copy(cfunc + 6784, "preq_stroke3", 32L, 12L);
    s_copy(cfunc + 6816, "preq_val", 32L, 8L);
    s_copy(cfunc + 6848, "prestore_model_clip_vol", 32L, 23L);
    s_copy(cfunc + 6880, "pret_all_structs", 32L, 16L);
    s_copy(cfunc + 6912, "pret_paths_ances", 32L, 16L);
    s_copy(cfunc + 6944, "pret_paths_descs", 32L, 16L);
    s_copy(cfunc + 6976, "pret_struct_ids", 32L, 15L);
    s_copy(cfunc + 7008, "pret_struct_nets", 32L, 16L);
    s_copy(cfunc + 7040, "pret_structs", 32L, 12L);
    s_copy(cfunc + 7072, "protate", 32L, 7L);
    s_copy(cfunc + 7104, "protate_x", 32L, 9L);
    s_copy(cfunc + 7136, "protate_y", 32L, 9L);
    s_copy(cfunc + 7168, "protate_z", 32L, 9L);
    s_copy(cfunc + 7200, "psample_choice", 32L, 14L);
    s_copy(cfunc + 7232, "psample_loc", 32L, 11L);
    s_copy(cfunc + 7264, "psample_loc3", 32L, 12L);
    s_copy(cfunc + 7296, "psample_pick", 32L, 12L);
    s_copy(cfunc + 7328, "psample_string", 32L, 14L);
    s_copy(cfunc + 7360, "psample_stroke", 32L, 14L);
    s_copy(cfunc + 7392, "psample_stroke3", 32L, 15L);
    s_copy(cfunc + 7424, "psample_val", 32L, 11L);
    s_copy(cfunc + 7456, "pscale", 32L, 6L);
    s_copy(cfunc + 7488, "pscale3", 32L, 7L);
    s_copy(cfunc + 7520, "pset_anno_align", 32L, 15L);
    s_copy(cfunc + 7552, "pset_anno_char_ht", 32L, 17L);
    s_copy(cfunc + 7584, "pset_anno_char_up_vec", 32L, 21L);
    s_copy(cfunc + 7616, "pset_anno_path", 32L, 14L);
    s_copy(cfunc + 7648, "pset_anno_style", 32L, 15L);
    s_copy(cfunc + 7680, "pset_char_expan", 32L, 15L);
    s_copy(cfunc + 7712, "pset_char_ht", 32L, 12L);
    s_copy(cfunc + 7744, "pset_char_space", 32L, 15L);
    s_copy(cfunc + 7776, "pset_char_up_vec", 32L, 16L);
    s_copy(cfunc + 7808, "pset_choice_mode", 32L, 16L);
    s_copy(cfunc + 7840, "pset_colr_model", 32L, 15L);
    s_copy(cfunc + 7872, "pset_colr_rep", 32L, 13L);
    s_copy(cfunc + 7904, "pset_conf_res", 32L, 13L);
    s_copy(cfunc + 7936, "pset_disp_upd_st", 32L, 16L);
    s_copy(cfunc + 7968, "pset_edge_colr_ind", 32L, 18L);
    s_copy(cfunc + 8000, "pset_edge_flag", 32L, 14L);
    s_copy(cfunc + 8032, "pset_edge_ind", 32L, 13L);
    s_copy(cfunc + 8064, "pset_edge_rep", 32L, 13L);
    s_copy(cfunc + 8096, "pset_edgetype", 32L, 13L);
    s_copy(cfunc + 8128, "pset_edgewidth", 32L, 14L);
    s_copy(cfunc + 8160, "pset_edit_mode", 32L, 14L);
    s_copy(cfunc + 8192, "pset_elem_ptr", 32L, 13L);
    s_copy(cfunc + 8224, "pset_elem_ptr_label", 32L, 19L);
    s_copy(cfunc + 8256, "pset_err_hand", 32L, 13L);
    s_copy(cfunc + 8288, "pset_err_hand_mode", 32L, 18L);
    s_copy(cfunc + 8320, "pset_global_tran", 32L, 16L);
    s_copy(cfunc + 8352, "pset_global_tran3", 32L, 17L);
    s_copy(cfunc + 8384, "pset_highl_filter", 32L, 17L);
    s_copy(cfunc + 8416, "pset_hlhsr_id", 32L, 13L);
    s_copy(cfunc + 8448, "pset_hlhsr_mode", 32L, 15L);
    s_copy(cfunc + 8480, "pset_indiv_asf", 32L, 14L);
    s_copy(cfunc + 8512, "pset_int_colr_ind", 32L, 17L);
    s_copy(cfunc + 8544, "pset_int_ind", 32L, 12L);
    s_copy(cfunc + 8576, "pset_int_rep", 32L, 12L);
    s_copy(cfunc + 8608, "pset_int_style", 32L, 14L);
    s_copy(cfunc + 8640, "pset_int_style_ind", 32L, 18L);
    s_copy(cfunc + 8672, "pset_invis_filter", 32L, 17L);
    s_copy(cfunc + 8704, "pset_line_colr_ind", 32L, 18L);
    s_copy(cfunc + 8736, "pset_line_ind", 32L, 13L);
    s_copy(cfunc + 8768, "pset_line_rep", 32L, 13L);
    s_copy(cfunc + 8800, "pset_linetype", 32L, 13L);
    s_copy(cfunc + 8832, "pset_linewidth", 32L, 14L);
    s_copy(cfunc + 8864, "pset_loc_mode", 32L, 13L);
    s_copy(cfunc + 8896, "pset_local_tran", 32L, 15L);
    s_copy(cfunc + 8928, "pset_local_tran3", 32L, 16L);
    s_copy(cfunc + 8960, "pset_marker_colr_ind", 32L, 20L);
    s_copy(cfunc + 8992, "pset_marker_ind", 32L, 15L);
    s_copy(cfunc + 9024, "pset_marker_rep", 32L, 15L);
    s_copy(cfunc + 9056, "pset_marker_size", 32L, 16L);
    s_copy(cfunc + 9088, "pset_marker_type", 32L, 16L);
    s_copy(cfunc + 9120, "pset_model_clip_ind", 32L, 19L);
    s_copy(cfunc + 9152, "pset_model_clip_vol", 32L, 19L);
    s_copy(cfunc + 9184, "pset_model_clip_vol3", 32L, 20L);
    s_copy(cfunc + 9216, "pset_pat_ref_point", 32L, 18L);
    s_copy(cfunc + 9248, "pset_pat_ref_point_vecs", 32L, 23L);
    s_copy(cfunc + 9280, "pset_pat_rep", 32L, 12L);
    s_copy(cfunc + 9312, "pset_pat_size", 32L, 13L);
    s_copy(cfunc + 9344, "pset_pick_filter", 32L, 16L);
    s_copy(cfunc + 9376, "pset_pick_id", 32L, 12L);
    s_copy(cfunc + 9408, "pset_pick_mode", 32L, 14L);
    s_copy(cfunc + 9440, "pset_string_mode", 32L, 16L);
    s_copy(cfunc + 9472, "pset_stroke_mode", 32L, 16L);
    s_copy(cfunc + 9504, "pset_text_align", 32L, 15L);
    s_copy(cfunc + 9536, "pset_text_colr_ind", 32L, 18L);
    s_copy(cfunc + 9568, "pset_text_font", 32L, 14L);
    s_copy(cfunc + 9600, "pset_text_ind", 32L, 13L);
    s_copy(cfunc + 9632, "pset_text_path", 32L, 14L);
    s_copy(cfunc + 9664, "pset_text_prec", 32L, 14L);
    s_copy(cfunc + 9696, "pset_text_rep", 32L, 13L);
    s_copy(cfunc + 9728, "pset_val_mode", 32L, 13L);
    s_copy(cfunc + 9760, "pset_view_ind", 32L, 13L);
    s_copy(cfunc + 9792, "pset_view_rep", 32L, 13L);
    s_copy(cfunc + 9824, "pset_view_rep3", 32L, 14L);
    s_copy(cfunc + 9856, "pset_view_tran_in_pri", 32L, 21L);
    s_copy(cfunc + 9888, "pset_ws_vp", 32L, 10L);
    s_copy(cfunc + 9920, "pset_ws_vp3", 32L, 11L);
    s_copy(cfunc + 9952, "pset_ws_win", 32L, 11L);
    s_copy(cfunc + 9984, "pset_ws_win3", 32L, 12L);
    s_copy(cfunc + 10016, "ptext", 32L, 5L);
    s_copy(cfunc + 10048, "ptext3", 32L, 6L);
    s_copy(cfunc + 10080, "ptran_point", 32L, 11L);
    s_copy(cfunc + 10112, "ptran_point3", 32L, 12L);
    s_copy(cfunc + 10144, "ptranslate", 32L, 10L);
    s_copy(cfunc + 10176, "ptranslate3", 32L, 11L);
    s_copy(cfunc + 10208, "punpost_all_structs", 32L, 19L);
    s_copy(cfunc + 10240, "punpost_struct", 32L, 14L);
    s_copy(cfunc + 10272, "pupd_ws", 32L, 7L);
    s_copy(cfunc + 10304, "pwrite_item", 32L, 11L);
/* Computing MAX */
    i__1 = max(20,globnu_1.indlun);
    uin = max(i__1,globnu_1.glblun) + 1;
    uout = uin + 1;
/*  open output file */
    o__1.oerr = 1;
    o__1.ounit = uout;
    o__1.ofnmlen = 7;
    o__1.ofnm = "phigs.c";
    o__1.orl = 9000;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsfi(&io___6);
	do_fio(&c__1, "Error code opening output file phigs.c = ", 41L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
    al__1.aerr = 1;
    al__1.aunit = uout;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsfi(&io___7);
	do_fio(&c__1, "Error code rewinding output file phigs.c = ", 43L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  open input file */
    o__1.oerr = 1;
    o__1.ounit = uin;
    o__1.ofnmlen = 7;
    o__1.ofnm = "phigs.h";
    o__1.orl = 2000;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    ioerr = f_open(&o__1);
    if (ioerr != 0) {
	s_wsfi(&io___8);
	do_fio(&c__1, "Error code opening input file phigs.h = ", 40L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
    al__1.aerr = 1;
    al__1.aunit = uin;
    ioerr = f_rew(&al__1);
    if (ioerr != 0) {
	s_wsfi(&io___9);
	do_fio(&c__1, "Error code rewinding input file phigs.h = ", 42L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, ".", 1L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  begin read-write loop for next logical line */
L100:
    s_copy(loglin, " ", 3000L, 1L);
    nxtpos = 1;
/*  get next record */
L110:
    io___12.ciunit = uin;
    ioerr = s_rsfe(&io___12);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = do_fio(&c__1, inrec, 500L);
    if (ioerr != 0) {
	goto L100001;
    }
    ioerr = e_rsfe();
L100001:
    if (ioerr < 0) {
	goto L666;
    }
    if (ioerr != 0) {
	s_wsfi(&io___14);
	do_fio(&c__1, "Error #", 7L);
	do_fio(&c__1, (char *)&ioerr, (ftnlen)sizeof(integer));
	do_fio(&c__1, " occurred reading phigs.h.", 26L);
	e_wsfi();
	unmsg_(msg, 300L);
    }
/*  ensure a non-blank logical line */
    if (s_cmp(inrec, " ", 500L, 1L) == 0) {
	goto L110;
    }
    s_copy(loglin + (nxtpos - 1), inrec, 3000 - (nxtpos - 1), 500L);
    nxtpos = itrim_(loglin, 3000L);
    if (loglin[nxtpos - 1] == '\\') {
	goto L110;
    }
    lastch = nxtpos;
/* USERMOD  convert HT,LF,VT,FF,CR to space */
/*  convert all white space to spaces - we'll take */
/*  these to be ASCII 9-13 ... */
    for (cc = 9; cc <= 13; ++cc) {
L315:
	ch__1[0] = cc;
	nxtpos = i_indx(loglin, ch__1, 3000L, 1L);
	if (nxtpos != 0) {
	    loglin[nxtpos - 1] = ' ';
	    goto L315;
	}
/* L310: */
    }
/*  comment out re-defines of C-functions - leave all other logical */
/*  lines alone */
/*  search for # */
    ppos = leadnb_(loglin, 3000L);
    if (loglin[ppos - 1] != '#') {
	goto L400;
    }
/*  search for define */
    i__1 = ppos;
    dpos = leadnb_(loglin + i__1, 3000 - i__1);
    if (dpos == 0) {
	goto L400;
    }
    dpos += ppos;
    if (s_cmp(loglin + (dpos - 1), "define ", 7L, 7L) != 0) {
	goto L400;
    }
/*  search for function name */
    i__1 = dpos + 5;
    npos = leadnb_(loglin + i__1, 3000 - i__1);
    if (npos == 0) {
	goto L400;
    }
    npos = npos + dpos + 5;
/*  search for end of function name */
    nposz = i_indx(loglin + (npos - 1), " ", 3000 - (npos - 1), 1L);
    if (nposz == 0) {
/* Writing concatenation */
#ifndef NO_PROTO
	i__2[0] = 66, a__1[0] = "Suspicious logical line: no blank found aft"
		"er name to be defined: ";
#else /* NO_PROTO */
	i__2[0] = 66, a__1[0] = "Suspicious logical line: no blank found aft\
er name to be defined: ";
#endif /* NO_PROTO */
	i__2[1] = 3000 - (npos - 1), a__1[1] = loglin + (npos - 1);
	s_cat(ch__2, a__1, i__2, &c__2, 3066L);
	inmsg_(ch__2, 3000 - (npos - 1) + 66);
	goto L400;
    }
    nposz = nposz + npos - 2;
    s_copy(funcnm, loglin + (npos - 1), 32L, nposz - (npos - 1));
/*  do binary search to see if found;  possible names are strictly */
/*  between LO and HI */
    lo = 0;
    hi = 324;
L300:
    mid = (lo + hi) / 2;
    if (s_cmp(funcnm, cfunc + (mid - 1 << 5), 32L, 32L) == 0) {
/* Writing concatenation */
	i__3[0] = 3, a__2[0] = "/* ";
	i__3[1] = lastch, a__2[1] = loglin;
	i__3[2] = 3, a__2[2] = " */";
	s_cat(chbuf, a__2, i__3, &c__3, 3000L);
	s_copy(loglin, chbuf, 3000L, 3000L);
	lastch += 6;
	goto L400;
    } else if (s_cmp(funcnm, cfunc + (mid - 1 << 5), 32L, 32L) < 0) {
	hi = mid;
    } else {
	lo = mid;
    }
    if (hi - lo >= 2) {
	goto L300;
    }
L400:
    io___26.ciunit = uout;
    s_wsfe(&io___26);
    do_fio(&c__1, loglin, lastch);
    e_wsfe();
    goto L100;
L666:
    cl__1.cerr = 0;
    cl__1.cunit = uout;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = uin;
    cl__1.csta = 0;
    f_clos(&cl__1);
    windup_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

