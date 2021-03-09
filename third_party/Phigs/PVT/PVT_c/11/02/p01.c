#include "phigs.h"
#include "f2c.h"

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 11.02/01                              * */
/*  *    TEST TITLE : Definition of macros with numeric     * */
/*  *                 values in phigs.h                     * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */

#ifdef NO_PROTO
extern /* Subroutine */ int fail_ (), pass_ (), endit_(), initgl_ ();
#else
extern /* Subroutine */ int fail_ (void), pass_ (void), endit_(void), 
                        initgl_(char*, ftnlen);
#endif
    

main ()
{

/* Local variables */
   initgl_ ("11.02/01", 8L);
   function_check ();
   error_check ();
   misc_check ();
/*  WRAP IT UP. */
    endit_();
}


function_check ()
{

/***  Section 6  Macro Definitions  ***/

   setmsg_ ("1 2", "Pfn_open_phigs should be defined as  0.", 3L, 39L);
#ifdef Pfn_open_phigs
   Pfn_open_phigs == 0 ? pass_() : fail_();
#else				/* Pfn_open_phigs */
   fail_ ();
#endif				/* Pfn_open_phigs */
   setmsg_ ("1 2", "Pfn_close_phigs should be defined as  1.", 3L, 40L);
#ifdef Pfn_close_phigs
   Pfn_close_phigs == 1 ? pass_() : fail_();
#else				/* Pfn_close_phigs */
   fail_ ();
#endif				/* Pfn_close_phigs */
   setmsg_ ("1 2", "Pfn_open_ws should be defined as  2.", 3L, 36L);
#ifdef Pfn_open_ws
   Pfn_open_ws == 2 ? pass_() : fail_();
#else				/* Pfn_open_ws */
   fail_ ();
#endif				/* Pfn_open_ws */
   setmsg_ ("1 2", "Pfn_close_ws should be defined as  3.", 3L, 37L);
#ifdef Pfn_close_ws
   Pfn_close_ws == 3 ? pass_() : fail_();
#else				/* Pfn_close_ws */
   fail_ ();
#endif				/* Pfn_close_ws */
   setmsg_ ("1 2", "Pfn_redraw_all_structs should be defined as  4.", 3L, 47L);
#ifdef Pfn_redraw_all_structs
   Pfn_redraw_all_structs == 4 ? pass_() : fail_();
#else				/* Pfn_redraw_all_structs */
   fail_ ();
#endif				/* Pfn_redraw_all_structs */
   setmsg_ ("1 2", "Pfn_upd_ws should be defined as  5.", 3L, 35L);
#ifdef Pfn_upd_ws
   Pfn_upd_ws == 5 ? pass_() : fail_();
#else				/* Pfn_upd_ws */
   fail_ ();
#endif				/* Pfn_upd_ws */
   setmsg_ ("1 2", "Pfn_set_disp_upd_st should be defined as  6.", 3L, 44L);
#ifdef Pfn_set_disp_upd_st
   Pfn_set_disp_upd_st == 6 ? pass_() : fail_();
#else				/* Pfn_set_disp_upd_st */
   fail_ ();
#endif				/* Pfn_set_disp_upd_st */
   setmsg_ ("1 2", "Pfn_message should be defined as  7.", 3L, 36L);
#ifdef Pfn_message
   Pfn_message == 7 ? pass_() : fail_();
#else				/* Pfn_message */
   fail_ ();
#endif				/* Pfn_message */
   setmsg_ ("1 2", "Pfn_polyline3 should be defined as  8.", 3L, 38L);
#ifdef Pfn_polyline3
   Pfn_polyline3 == 8 ? pass_() : fail_();
#else				/* Pfn_polyline3 */
   fail_ ();
#endif				/* Pfn_polyline3 */
   setmsg_ ("1 2", "Pfn_polyline should be defined as  9.", 3L, 37L);
#ifdef Pfn_polyline
   Pfn_polyline == 9 ? pass_() : fail_();
#else				/* Pfn_polyline */
   fail_ ();
#endif				/* Pfn_polyline */
   setmsg_ ("1 2", "Pfn_polymarker3 should be defined as  10.", 3L, 41L);
#ifdef Pfn_polymarker3
   Pfn_polymarker3 == 10 ? pass_() : fail_();
#else				/* Pfn_polymarker3 */
   fail_ ();
#endif				/* Pfn_polymarker3 */
   setmsg_ ("1 2", "Pfn_polymarker should be defined as  11.", 3L, 40L);
#ifdef Pfn_polymarker
   Pfn_polymarker == 11 ? pass_() : fail_();
#else				/* Pfn_polymarker */
   fail_ ();
#endif				/* Pfn_polymarker */
   setmsg_ ("1 2", "Pfn_text3 should be defined as  12.", 3L, 35L);
#ifdef Pfn_text3
   Pfn_text3 == 12 ? pass_() : fail_();
#else				/* Pfn_text3 */
   fail_ ();
#endif				/* Pfn_text3 */
   setmsg_ ("1 2", "Pfn_text should be defined as  13.", 3L, 34L);
#ifdef Pfn_text
   Pfn_text == 13 ? pass_() : fail_();
#else				/* Pfn_text */
   fail_ ();
#endif				/* Pfn_text */
   setmsg_ ("1 2", "Pfn_anno_text_rel3 should be defined as  14.", 3L, 44L);
#ifdef Pfn_anno_text_rel3
   Pfn_anno_text_rel3 == 14 ? pass_() : fail_();
#else				/* Pfn_anno_text_rel3 */
   fail_ ();
#endif				/* Pfn_anno_text_rel3 */
   setmsg_ ("1 2", "Pfn_anno_text_rel should be defined as  15.", 3L, 43L);
#ifdef Pfn_anno_text_rel
   Pfn_anno_text_rel == 15 ? pass_() : fail_();
#else				/* Pfn_anno_text_rel */
   fail_ ();
#endif				/* Pfn_anno_text_rel */
   setmsg_ ("1 2", "Pfn_fill_area3 should be defined as  16.", 3L, 40L);
#ifdef Pfn_fill_area3
   Pfn_fill_area3 == 16 ? pass_() : fail_();
#else				/* Pfn_fill_area3 */
   fail_ ();
#endif				/* Pfn_fill_area3 */
   setmsg_ ("1 2", "Pfn_fill_area should be defined as  17.", 3L, 39L);
#ifdef Pfn_fill_area
   Pfn_fill_area == 17 ? pass_() : fail_();
#else				/* Pfn_fill_area */
   fail_ ();
#endif				/* Pfn_fill_area */
   setmsg_ ("1 2", "Pfn_fill_area_set3 should be defined as  18.", 3L, 44L);
#ifdef Pfn_fill_area_set3
   Pfn_fill_area_set3 == 18 ? pass_() : fail_();
#else				/* Pfn_fill_area_set3 */
   fail_ ();
#endif				/* Pfn_fill_area_set3 */
   setmsg_ ("1 2", "Pfn_fill_area_set should be defined as  19.", 3L, 43L);
#ifdef Pfn_fill_area_set
   Pfn_fill_area_set == 19 ? pass_() : fail_();
#else				/* Pfn_fill_area_set */
   fail_ ();
#endif				/* Pfn_fill_area_set */
   setmsg_ ("1 2", "Pfn_cell_array3 should be defined as  20.", 3L, 41L);
#ifdef Pfn_cell_array3
   Pfn_cell_array3 == 20 ? pass_() : fail_();
#else				/* Pfn_cell_array3 */
   fail_ ();
#endif				/* Pfn_cell_array3 */
   setmsg_ ("1 2", "Pfn_cell_array should be defined as  21.", 3L, 40L);
#ifdef Pfn_cell_array
   Pfn_cell_array == 21 ? pass_() : fail_();
#else				/* Pfn_cell_array */
   fail_ ();
#endif				/* Pfn_cell_array */
   setmsg_ ("1 2", "Pfn_gdp3 should be defined as  22.", 3L, 34L);
#ifdef Pfn_gdp3
   Pfn_gdp3 == 22 ? pass_() : fail_();
#else				/* Pfn_gdp3 */
   fail_ ();
#endif				/* Pfn_gdp3 */
   setmsg_ ("1 2", "Pfn_gdp should be defined as  23.", 3L, 33L);
#ifdef Pfn_gdp
   Pfn_gdp == 23 ? pass_() : fail_();
#else				/* Pfn_gdp */
   fail_ ();
#endif				/* Pfn_gdp */
   setmsg_ ("1 2", "Pfn_set_line_ind should be defined as  24.", 3L, 42L);
#ifdef Pfn_set_line_ind
   Pfn_set_line_ind == 24 ? pass_() : fail_();
#else				/* Pfn_set_line_ind */
   fail_ ();
#endif				/* Pfn_set_line_ind */
   setmsg_ ("1 2", "Pfn_set_marker_ind should be defined as  25.", 3L, 44L);
#ifdef Pfn_set_marker_ind
   Pfn_set_marker_ind == 25 ? pass_() : fail_();
#else				/* Pfn_set_marker_ind */
   fail_ ();
#endif				/* Pfn_set_marker_ind */
   setmsg_ ("1 2", "Pfn_set_text_ind should be defined as  26.", 3L, 42L);
#ifdef Pfn_set_text_ind
   Pfn_set_text_ind == 26 ? pass_() : fail_();
#else				/* Pfn_set_text_ind */
   fail_ ();
#endif				/* Pfn_set_text_ind */
   setmsg_ ("1 2", "Pfn_set_int_ind should be defined as  27.", 3L, 41L);
#ifdef Pfn_set_int_ind
   Pfn_set_int_ind == 27 ? pass_() : fail_();
#else				/* Pfn_set_int_ind */
   fail_ ();
#endif				/* Pfn_set_int_ind */
   setmsg_ ("1 2", "Pfn_set_edge_ind should be defined as  28.", 3L, 42L);
#ifdef Pfn_set_edge_ind
   Pfn_set_edge_ind == 28 ? pass_() : fail_();
#else				/* Pfn_set_edge_ind */
   fail_ ();
#endif				/* Pfn_set_edge_ind */
   setmsg_ ("1 2", "Pfn_set_linetype should be defined as  29.", 3L, 42L);
#ifdef Pfn_set_linetype
   Pfn_set_linetype == 29 ? pass_() : fail_();
#else				/* Pfn_set_linetype */
   fail_ ();
#endif				/* Pfn_set_linetype */
   setmsg_ ("1 2", "Pfn_set_linewidth should be defined as  30.", 3L, 43L);
#ifdef Pfn_set_linewidth
   Pfn_set_linewidth == 30 ? pass_() : fail_();
#else				/* Pfn_set_linewidth */
   fail_ ();
#endif				/* Pfn_set_linewidth */
   setmsg_ ("1 2", "Pfn_set_line_colr_ind should be defined as  31.", 3L, 47L);
#ifdef Pfn_set_line_colr_ind
   Pfn_set_line_colr_ind == 31 ? pass_() : fail_();
#else				/* Pfn_set_line_colr_ind */
   fail_ ();
#endif				/* Pfn_set_line_colr_ind */
   setmsg_ ("1 2", "Pfn_set_marker_type should be defined as  32.", 3L, 45L);
#ifdef Pfn_set_marker_type
   Pfn_set_marker_type == 32 ? pass_() : fail_();
#else				/* Pfn_set_marker_type */
   fail_ ();
#endif				/* Pfn_set_marker_type */
   setmsg_ ("1 2", "Pfn_set_marker_size should be defined as  33.", 3L, 45L);
#ifdef Pfn_set_marker_size
   Pfn_set_marker_size == 33 ? pass_() : fail_();
#else				/* Pfn_set_marker_size */
   fail_ ();
#endif				/* Pfn_set_marker_size */
   setmsg_ ("1 2", "Pfn_set_marker_colr_ind should be defined as  34.", 3L, 49L);
#ifdef Pfn_set_marker_colr_ind
   Pfn_set_marker_colr_ind == 34 ? pass_() : fail_();
#else				/* Pfn_set_marker_colr_ind */
   fail_ ();
#endif				/* Pfn_set_marker_colr_ind */
   setmsg_ ("1 2", "Pfn_set_text_font should be defined as  35.", 3L, 43L);
#ifdef Pfn_set_text_font
   Pfn_set_text_font == 35 ? pass_() : fail_();
#else				/* Pfn_set_text_font */
   fail_ ();
#endif				/* Pfn_set_text_font */
   setmsg_ ("1 2", "Pfn_set_text_prec should be defined as  36.", 3L, 43L);
#ifdef Pfn_set_text_prec
   Pfn_set_text_prec == 36 ? pass_() : fail_();
#else				/* Pfn_set_text_prec */
   fail_ ();
#endif				/* Pfn_set_text_prec */
   setmsg_ ("1 2", "Pfn_set_char_expan should be defined as  37.", 3L, 44L);
#ifdef Pfn_set_char_expan
   Pfn_set_char_expan == 37 ? pass_() : fail_();
#else				/* Pfn_set_char_expan */
   fail_ ();
#endif				/* Pfn_set_char_expan */
   setmsg_ ("1 2", "Pfn_set_char_space should be defined as  38.", 3L, 44L);
#ifdef Pfn_set_char_space
   Pfn_set_char_space == 38 ? pass_() : fail_();
#else				/* Pfn_set_char_space */
   fail_ ();
#endif				/* Pfn_set_char_space */
   setmsg_ ("1 2", "Pfn_set_text_colr_ind should be defined as  39.", 3L, 47L);
#ifdef Pfn_set_text_colr_ind
   Pfn_set_text_colr_ind == 39 ? pass_() : fail_();
#else				/* Pfn_set_text_colr_ind */
   fail_ ();
#endif				/* Pfn_set_text_colr_ind */
   setmsg_ ("1 2", "Pfn_set_char_ht should be defined as  40.", 3L, 41L);
#ifdef Pfn_set_char_ht
   Pfn_set_char_ht == 40 ? pass_() : fail_();
#else				/* Pfn_set_char_ht */
   fail_ ();
#endif				/* Pfn_set_char_ht */
   setmsg_ ("1 2", "Pfn_set_char_up_vec should be defined as  41.", 3L, 45L);
#ifdef Pfn_set_char_up_vec
   Pfn_set_char_up_vec == 41 ? pass_() : fail_();
#else				/* Pfn_set_char_up_vec */
   fail_ ();
#endif				/* Pfn_set_char_up_vec */
   setmsg_ ("1 2", "Pfn_set_text_path should be defined as  42.", 3L, 43L);
#ifdef Pfn_set_text_path
   Pfn_set_text_path == 42 ? pass_() : fail_();
#else				/* Pfn_set_text_path */
   fail_ ();
#endif				/* Pfn_set_text_path */
   setmsg_ ("1 2", "Pfn_set_text_align should be defined as  43.", 3L, 44L);
#ifdef Pfn_set_text_align
   Pfn_set_text_align == 43 ? pass_() : fail_();
#else				/* Pfn_set_text_align */
   fail_ ();
#endif				/* Pfn_set_text_align */
   setmsg_ ("1 2", "Pfn_set_anno_char_ht should be defined as  44.", 3L, 46L);
#ifdef Pfn_set_anno_char_ht
   Pfn_set_anno_char_ht == 44 ? pass_() : fail_();
#else				/* Pfn_set_anno_char_ht */
   fail_ ();
#endif				/* Pfn_set_anno_char_ht */
   setmsg_ ("1 2", "Pfn_set_anno_char_up_vec should be defined as  45.", 3L, 50L);
#ifdef Pfn_set_anno_char_up_vec
   Pfn_set_anno_char_up_vec == 45 ? pass_() : fail_();
#else				/* Pfn_set_anno_char_up_vec */
   fail_ ();
#endif				/* Pfn_set_anno_char_up_vec */
   setmsg_ ("1 2", "Pfn_set_anno_path should be defined as  46.", 3L, 43L);
#ifdef Pfn_set_anno_path
   Pfn_set_anno_path == 46 ? pass_() : fail_();
#else				/* Pfn_set_anno_path */
   fail_ ();
#endif				/* Pfn_set_anno_path */
   setmsg_ ("1 2", "Pfn_set_anno_align should be defined as  47.", 3L, 44L);
#ifdef Pfn_set_anno_align
   Pfn_set_anno_align == 47 ? pass_() : fail_();
#else				/* Pfn_set_anno_align */
   fail_ ();
#endif				/* Pfn_set_anno_align */
   setmsg_ ("1 2", "Pfn_set_anno_style should be defined as  48.", 3L, 44L);
#ifdef Pfn_set_anno_style
   Pfn_set_anno_style == 48 ? pass_() : fail_();
#else				/* Pfn_set_anno_style */
   fail_ ();
#endif				/* Pfn_set_anno_style */
   setmsg_ ("1 2", "Pfn_set_int_style should be defined as  49.", 3L, 43L);
#ifdef Pfn_set_int_style
   Pfn_set_int_style == 49 ? pass_() : fail_();
#else				/* Pfn_set_int_style */
   fail_ ();
#endif				/* Pfn_set_int_style */
   setmsg_ ("1 2", "Pfn_set_int_style_ind should be defined as  50.", 3L, 47L);
#ifdef Pfn_set_int_style_ind
   Pfn_set_int_style_ind == 50 ? pass_() : fail_();
#else				/* Pfn_set_int_style_ind */
   fail_ ();
#endif				/* Pfn_set_int_style_ind */
   setmsg_ ("1 2", "Pfn_set_int_colr_ind should be defined as  51.", 3L, 46L);
#ifdef Pfn_set_int_colr_ind
   Pfn_set_int_colr_ind == 51 ? pass_() : fail_();
#else				/* Pfn_set_int_colr_ind */
   fail_ ();
#endif				/* Pfn_set_int_colr_ind */
   setmsg_ ("1 2", "Pfn_set_edge_flag should be defined as  52.", 3L, 43L);
#ifdef Pfn_set_edge_flag
   Pfn_set_edge_flag == 52 ? pass_() : fail_();
#else				/* Pfn_set_edge_flag */
   fail_ ();
#endif				/* Pfn_set_edge_flag */
   setmsg_ ("1 2", "Pfn_set_edgetype should be defined as  53.", 3L, 42L);
#ifdef Pfn_set_edgetype
   Pfn_set_edgetype == 53 ? pass_() : fail_();
#else				/* Pfn_set_edgetype */
   fail_ ();
#endif				/* Pfn_set_edgetype */
   setmsg_ ("1 2", "Pfn_set_edgewidth should be defined as  54.", 3L, 43L);
#ifdef Pfn_set_edgewidth
   Pfn_set_edgewidth == 54 ? pass_() : fail_();
#else				/* Pfn_set_edgewidth */
   fail_ ();
#endif				/* Pfn_set_edgewidth */
   setmsg_ ("1 2", "Pfn_set_edge_colr_ind should be defined as  55.", 3L, 47L);
#ifdef Pfn_set_edge_colr_ind
   Pfn_set_edge_colr_ind == 55 ? pass_() : fail_();
#else				/* Pfn_set_edge_colr_ind */
   fail_ ();
#endif				/* Pfn_set_edge_colr_ind */
   setmsg_ ("1 2", "Pfn_set_pat_size should be defined as  56.", 3L, 42L);
#ifdef Pfn_set_pat_size
   Pfn_set_pat_size == 56 ? pass_() : fail_();
#else				/* Pfn_set_pat_size */
   fail_ ();
#endif				/* Pfn_set_pat_size */
   setmsg_ ("1 2", "Pfn_set_pat_ref_point_vecs should be defined as  57.", 3L, 52L);
#ifdef Pfn_set_pat_ref_point_vecs
   Pfn_set_pat_ref_point_vecs == 57 ? pass_() : fail_();
#else				/* Pfn_set_pat_ref_point_vecs */
   fail_ ();
#endif				/* Pfn_set_pat_ref_point_vecs */
   setmsg_ ("1 2", "Pfn_set_pat_ref_point should be defined as  58.", 3L, 47L);
#ifdef Pfn_set_pat_ref_point
   Pfn_set_pat_ref_point == 58 ? pass_() : fail_();
#else				/* Pfn_set_pat_ref_point */
   fail_ ();
#endif				/* Pfn_set_pat_ref_point */
   setmsg_ ("1 2", "Pfn_add_names_set should be defined as  59.", 3L, 43L);
#ifdef Pfn_add_names_set
   Pfn_add_names_set == 59 ? pass_() : fail_();
#else				/* Pfn_add_names_set */
   fail_ ();
#endif				/* Pfn_add_names_set */
   setmsg_ ("1 2", "Pfn_remove_names_set should be defined as  60.", 3L, 46L);
#ifdef Pfn_remove_names_set
   Pfn_remove_names_set == 60 ? pass_() : fail_();
#else				/* Pfn_remove_names_set */
   fail_ ();
#endif				/* Pfn_remove_names_set */
   setmsg_ ("1 2", "Pfn_set_indiv_asf should be defined as  61.", 3L, 43L);
#ifdef Pfn_set_indiv_asf
   Pfn_set_indiv_asf == 61 ? pass_() : fail_();
#else				/* Pfn_set_indiv_asf */
   fail_ ();
#endif				/* Pfn_set_indiv_asf */
   setmsg_ ("1 2", "Pfn_set_line_rep should be defined as  62.", 3L, 42L);
#ifdef Pfn_set_line_rep
   Pfn_set_line_rep == 62 ? pass_() : fail_();
#else				/* Pfn_set_line_rep */
   fail_ ();
#endif				/* Pfn_set_line_rep */
   setmsg_ ("1 2", "Pfn_set_marker_rep should be defined as  63.", 3L, 44L);
#ifdef Pfn_set_marker_rep
   Pfn_set_marker_rep == 63 ? pass_() : fail_();
#else				/* Pfn_set_marker_rep */
   fail_ ();
#endif				/* Pfn_set_marker_rep */
   setmsg_ ("1 2", "Pfn_set_text_rep should be defined as  64.", 3L, 42L);
#ifdef Pfn_set_text_rep
   Pfn_set_text_rep == 64 ? pass_() : fail_();
#else				/* Pfn_set_text_rep */
   fail_ ();
#endif				/* Pfn_set_text_rep */
   setmsg_ ("1 2", "Pfn_set_int_rep should be defined as  65.", 3L, 41L);
#ifdef Pfn_set_int_rep
   Pfn_set_int_rep == 65 ? pass_() : fail_();
#else				/* Pfn_set_int_rep */
   fail_ ();
#endif				/* Pfn_set_int_rep */
   setmsg_ ("1 2", "Pfn_set_edge_rep should be defined as  66.", 3L, 42L);
#ifdef Pfn_set_edge_rep
   Pfn_set_edge_rep == 66 ? pass_() : fail_();
#else				/* Pfn_set_edge_rep */
   fail_ ();
#endif				/* Pfn_set_edge_rep */
   setmsg_ ("1 2", "Pfn_set_pat_rep should be defined as  67.", 3L, 41L);
#ifdef Pfn_set_pat_rep
   Pfn_set_pat_rep == 67 ? pass_() : fail_();
#else				/* Pfn_set_pat_rep */
   fail_ ();
#endif				/* Pfn_set_pat_rep */
   setmsg_ ("1 2", "Pfn_set_colr_rep should be defined as  68.", 3L, 42L);
#ifdef Pfn_set_colr_rep
   Pfn_set_colr_rep == 68 ? pass_() : fail_();
#else				/* Pfn_set_colr_rep */
   fail_ ();
#endif				/* Pfn_set_colr_rep */
   setmsg_ ("1 2", "Pfn_set_highl_filter should be defined as  69.", 3L, 46L);
#ifdef Pfn_set_highl_filter
   Pfn_set_highl_filter == 69 ? pass_() : fail_();
#else				/* Pfn_set_highl_filter */
   fail_ ();
#endif				/* Pfn_set_highl_filter */
   setmsg_ ("1 2", "Pfn_set_invis_filter should be defined as  70.", 3L, 46L);
#ifdef Pfn_set_invis_filter
   Pfn_set_invis_filter == 70 ? pass_() : fail_();
#else				/* Pfn_set_invis_filter */
   fail_ ();
#endif				/* Pfn_set_invis_filter */
   setmsg_ ("1 2", "Pfn_set_colr_model should be defined as  71.", 3L, 44L);
#ifdef Pfn_set_colr_model
   Pfn_set_colr_model == 71 ? pass_() : fail_();
#else				/* Pfn_set_colr_model */
   fail_ ();
#endif				/* Pfn_set_colr_model */
   setmsg_ ("1 2", "Pfn_set_hlhsr_id should be defined as  72.", 3L, 42L);
#ifdef Pfn_set_hlhsr_id
   Pfn_set_hlhsr_id == 72 ? pass_() : fail_();
#else				/* Pfn_set_hlhsr_id */
   fail_ ();
#endif				/* Pfn_set_hlhsr_id */
   setmsg_ ("1 2", "Pfn_set_hlhsr_mode should be defined as  73.", 3L, 44L);
#ifdef Pfn_set_hlhsr_mode
   Pfn_set_hlhsr_mode == 73 ? pass_() : fail_();
#else				/* Pfn_set_hlhsr_mode */
   fail_ ();
#endif				/* Pfn_set_hlhsr_mode */
   setmsg_ ("1 2", "Pfn_set_local_tran3 should be defined as  74.", 3L, 45L);
#ifdef Pfn_set_local_tran3
   Pfn_set_local_tran3 == 74 ? pass_() : fail_();
#else				/* Pfn_set_local_tran3 */
   fail_ ();
#endif				/* Pfn_set_local_tran3 */
   setmsg_ ("1 2", "Pfn_set_local_tran should be defined as  75.", 3L, 44L);
#ifdef Pfn_set_local_tran
   Pfn_set_local_tran == 75 ? pass_() : fail_();
#else				/* Pfn_set_local_tran */
   fail_ ();
#endif				/* Pfn_set_local_tran */
   setmsg_ ("1 2", "Pfn_set_global_tran3 should be defined as  76.", 3L, 46L);
#ifdef Pfn_set_global_tran3
   Pfn_set_global_tran3 == 76 ? pass_() : fail_();
#else				/* Pfn_set_global_tran3 */
   fail_ ();
#endif				/* Pfn_set_global_tran3 */
   setmsg_ ("1 2", "Pfn_set_global_tran should be defined as  77.", 3L, 45L);
#ifdef Pfn_set_global_tran
   Pfn_set_global_tran == 77 ? pass_() : fail_();
#else				/* Pfn_set_global_tran */
   fail_ ();
#endif				/* Pfn_set_global_tran */
   setmsg_ ("1 2", "Pfn_set_model_clip_vol3 should be defined as  78.", 3L, 49L);
#ifdef Pfn_set_model_clip_vol3
   Pfn_set_model_clip_vol3 == 78 ? pass_() : fail_();
#else				/* Pfn_set_model_clip_vol3 */
   fail_ ();
#endif				/* Pfn_set_model_clip_vol3 */
   setmsg_ ("1 2", "Pfn_set_model_clip_vol should be defined as  79.", 3L, 48L);
#ifdef Pfn_set_model_clip_vol
   Pfn_set_model_clip_vol == 79 ? pass_() : fail_();
#else				/* Pfn_set_model_clip_vol */
   fail_ ();
#endif				/* Pfn_set_model_clip_vol */
   setmsg_ ("1 2", "Pfn_set_model_clip_ind should be defined as  80.", 3L, 48L);
#ifdef Pfn_set_model_clip_ind
   Pfn_set_model_clip_ind == 80 ? pass_() : fail_();
#else				/* Pfn_set_model_clip_ind */
   fail_ ();
#endif				/* Pfn_set_model_clip_ind */
   setmsg_ ("1 2", "Pfn_restore_model_clip_vol should be defined as  81.", 3L, 52L);
#ifdef Pfn_restore_model_clip_vol
   Pfn_restore_model_clip_vol == 81 ? pass_() : fail_();
#else				/* Pfn_restore_model_clip_vol */
   fail_ ();
#endif				/* Pfn_restore_model_clip_vol */
   setmsg_ ("1 2", "Pfn_set_view_ind should be defined as  82.", 3L, 42L);
#ifdef Pfn_set_view_ind
   Pfn_set_view_ind == 82 ? pass_() : fail_();
#else				/* Pfn_set_view_ind */
   fail_ ();
#endif				/* Pfn_set_view_ind */
   setmsg_ ("1 2", "Pfn_set_view_rep3 should be defined as  83.", 3L, 43L);
#ifdef Pfn_set_view_rep3
   Pfn_set_view_rep3 == 83 ? pass_() : fail_();
#else				/* Pfn_set_view_rep3 */
   fail_ ();
#endif				/* Pfn_set_view_rep3 */
   setmsg_ ("1 2", "Pfn_set_view_rep should be defined as  84.", 3L, 42L);
#ifdef Pfn_set_view_rep
   Pfn_set_view_rep == 84 ? pass_() : fail_();
#else				/* Pfn_set_view_rep */
   fail_ ();
#endif				/* Pfn_set_view_rep */
   setmsg_ ("1 2", "Pfn_set_view_tran_in_pri should be defined as  85.", 3L, 50L);
#ifdef Pfn_set_view_tran_in_pri
   Pfn_set_view_tran_in_pri == 85 ? pass_() : fail_();
#else				/* Pfn_set_view_tran_in_pri */
   fail_ ();
#endif				/* Pfn_set_view_tran_in_pri */
   setmsg_ ("1 2", "Pfn_set_ws_win3 should be defined as  86.", 3L, 41L);
#ifdef Pfn_set_ws_win3
   Pfn_set_ws_win3 == 86 ? pass_() : fail_();
#else				/* Pfn_set_ws_win3 */
   fail_ ();
#endif				/* Pfn_set_ws_win3 */
   setmsg_ ("1 2", "Pfn_set_ws_win should be defined as  87.", 3L, 40L);
#ifdef Pfn_set_ws_win
   Pfn_set_ws_win == 87 ? pass_() : fail_();
#else				/* Pfn_set_ws_win */
   fail_ ();
#endif				/* Pfn_set_ws_win */
   setmsg_ ("1 2", "Pfn_set_ws_vp3 should be defined as  88.", 3L, 40L);
#ifdef Pfn_set_ws_vp3
   Pfn_set_ws_vp3 == 88 ? pass_() : fail_();
#else				/* Pfn_set_ws_vp3 */
   fail_ ();
#endif				/* Pfn_set_ws_vp3 */
   setmsg_ ("1 2", "Pfn_set_ws_vp should be defined as  89.", 3L, 39L);
#ifdef Pfn_set_ws_vp
   Pfn_set_ws_vp == 89 ? pass_() : fail_();
#else				/* Pfn_set_ws_vp */
   fail_ ();
#endif				/* Pfn_set_ws_vp */
   setmsg_ ("1 2", "Pfn_open_struct should be defined as  90.", 3L, 41L);
#ifdef Pfn_open_struct
   Pfn_open_struct == 90 ? pass_() : fail_();
#else				/* Pfn_open_struct */
   fail_ ();
#endif				/* Pfn_open_struct */
   setmsg_ ("1 2", "Pfn_close_struct should be defined as  91.", 3L, 42L);
#ifdef Pfn_close_struct
   Pfn_close_struct == 91 ? pass_() : fail_();
#else				/* Pfn_close_struct */
   fail_ ();
#endif				/* Pfn_close_struct */
   setmsg_ ("1 2", "Pfn_exec_struct should be defined as  92.", 3L, 41L);
#ifdef Pfn_exec_struct
   Pfn_exec_struct == 92 ? pass_() : fail_();
#else				/* Pfn_exec_struct */
   fail_ ();
#endif				/* Pfn_exec_struct */
   setmsg_ ("1 2", "Pfn_label should be defined as  93.", 3L, 35L);
#ifdef Pfn_label
   Pfn_label == 93 ? pass_() : fail_();
#else				/* Pfn_label */
   fail_ ();
#endif				/* Pfn_label */
   setmsg_ ("1 2", "Pfn_appl_data should be defined as  94.", 3L, 39L);
#ifdef Pfn_appl_data
   Pfn_appl_data == 94 ? pass_() : fail_();
#else				/* Pfn_appl_data */
   fail_ ();
#endif				/* Pfn_appl_data */
   setmsg_ ("1 2", "Pfn_gse should be defined as  95.", 3L, 33L);
#ifdef Pfn_gse
   Pfn_gse == 95 ? pass_() : fail_();
#else				/* Pfn_gse */
   fail_ ();
#endif				/* Pfn_gse */
   setmsg_ ("1 2", "Pfn_set_edit_mode should be defined as  96.", 3L, 43L);
#ifdef Pfn_set_edit_mode
   Pfn_set_edit_mode == 96 ? pass_() : fail_();
#else				/* Pfn_set_edit_mode */
   fail_ ();
#endif				/* Pfn_set_edit_mode */
   setmsg_ ("1 2", "Pfn_copy_all_elems_struct should be defined as  97.", 3L, 51L);
#ifdef Pfn_copy_all_elems_struct
   Pfn_copy_all_elems_struct == 97 ? pass_() : fail_();
#else				/* Pfn_copy_all_elems_struct */
   fail_ ();
#endif				/* Pfn_copy_all_elems_struct */
   setmsg_ ("1 2", "Pfn_set_elem_ptr should be defined as  98.", 3L, 42L);
#ifdef Pfn_set_elem_ptr
   Pfn_set_elem_ptr == 98 ? pass_() : fail_();
#else				/* Pfn_set_elem_ptr */
   fail_ ();
#endif				/* Pfn_set_elem_ptr */
   setmsg_ ("1 2", "Pfn_offset_elem_ptr should be defined as  99.", 3L, 45L);
#ifdef Pfn_offset_elem_ptr
   Pfn_offset_elem_ptr == 99 ? pass_() : fail_();
#else				/* Pfn_offset_elem_ptr */
   fail_ ();
#endif				/* Pfn_offset_elem_ptr */
   setmsg_ ("1 2", "Pfn_set_elem_ptr_label should be defined as  100.", 3L, 49L);
#ifdef Pfn_set_elem_ptr_label
   Pfn_set_elem_ptr_label == 100 ? pass_() : fail_();
#else				/* Pfn_set_elem_ptr_label */
   fail_ ();
#endif				/* Pfn_set_elem_ptr_label */
   setmsg_ ("1 2", "Pfn_del_elem should be defined as  101.", 3L, 39L);
#ifdef Pfn_del_elem
   Pfn_del_elem == 101 ? pass_() : fail_();
#else				/* Pfn_del_elem */
   fail_ ();
#endif				/* Pfn_del_elem */
   setmsg_ ("1 2", "Pfn_del_elem_range should be defined as  102.", 3L, 45L);
#ifdef Pfn_del_elem_range
   Pfn_del_elem_range == 102 ? pass_() : fail_();
#else				/* Pfn_del_elem_range */
   fail_ ();
#endif				/* Pfn_del_elem_range */
   setmsg_ ("1 2", "Pfn_del_elems_labels should be defined as  103.", 3L, 47L);
#ifdef Pfn_del_elems_labels
   Pfn_del_elems_labels == 103 ? pass_() : fail_();
#else				/* Pfn_del_elems_labels */
   fail_ ();
#endif				/* Pfn_del_elems_labels */
   setmsg_ ("1 2", "Pfn_empty_struct should be defined as  104.", 3L, 43L);
#ifdef Pfn_empty_struct
   Pfn_empty_struct == 104 ? pass_() : fail_();
#else				/* Pfn_empty_struct */
   fail_ ();
#endif				/* Pfn_empty_struct */
   setmsg_ ("1 2", "Pfn_del_struct should be defined as  105.", 3L, 41L);
#ifdef Pfn_del_struct
   Pfn_del_struct == 105 ? pass_() : fail_();
#else				/* Pfn_del_struct */
   fail_ ();
#endif				/* Pfn_del_struct */
   setmsg_ ("1 2", "Pfn_del_struct_net should be defined as  106.", 3L, 45L);
#ifdef Pfn_del_struct_net
   Pfn_del_struct_net == 106 ? pass_() : fail_();
#else				/* Pfn_del_struct_net */
   fail_ ();
#endif				/* Pfn_del_struct_net */
   setmsg_ ("1 2", "Pfn_del_all_structs should be defined as  107.", 3L, 46L);
#ifdef Pfn_del_all_structs
   Pfn_del_all_structs == 107 ? pass_() : fail_();
#else				/* Pfn_del_all_structs */
   fail_ ();
#endif				/* Pfn_del_all_structs */
   setmsg_ ("1 2", "Pfn_change_struct_id should be defined as  108.", 3L, 47L);
#ifdef Pfn_change_struct_id
   Pfn_change_struct_id == 108 ? pass_() : fail_();
#else				/* Pfn_change_struct_id */
   fail_ ();
#endif				/* Pfn_change_struct_id */
   setmsg_ ("1 2", "Pfn_change_struct_refs should be defined as  109.", 3L, 49L);
#ifdef Pfn_change_struct_refs
   Pfn_change_struct_refs == 109 ? pass_() : fail_();
#else				/* Pfn_change_struct_refs */
   fail_ ();
#endif				/* Pfn_change_struct_refs */
   setmsg_ ("1 2", "Pfn_change_struct_id_refs should be defined as  110.", 3L, 52L);
#ifdef Pfn_change_struct_id_refs
   Pfn_change_struct_id_refs == 110 ? pass_() : fail_();
#else				/* Pfn_change_struct_id_refs */
   fail_ ();
#endif				/* Pfn_change_struct_id_refs */
   setmsg_ ("1 2", "Pfn_post_struct should be defined as  111.", 3L, 42L);
#ifdef Pfn_post_struct
   Pfn_post_struct == 111 ? pass_() : fail_();
#else				/* Pfn_post_struct */
   fail_ ();
#endif				/* Pfn_post_struct */
   setmsg_ ("1 2", "Pfn_unpost_struct should be defined as  112.", 3L, 44L);
#ifdef Pfn_unpost_struct
   Pfn_unpost_struct == 112 ? pass_() : fail_();
#else				/* Pfn_unpost_struct */
   fail_ ();
#endif				/* Pfn_unpost_struct */
   setmsg_ ("1 2", "Pfn_unpost_all_structs should be defined as  113.", 3L, 49L);
#ifdef Pfn_unpost_all_structs
   Pfn_unpost_all_structs == 113 ? pass_() : fail_();
#else				/* Pfn_unpost_all_structs */
   fail_ ();
#endif				/* Pfn_unpost_all_structs */
   setmsg_ ("1 2", "Pfn_open_ar_file should be defined as  114.", 3L, 43L);
#ifdef Pfn_open_ar_file
   Pfn_open_ar_file == 114 ? pass_() : fail_();
#else				/* Pfn_open_ar_file */
   fail_ ();
#endif				/* Pfn_open_ar_file */
   setmsg_ ("1 2", "Pfn_close_ar_file should be defined as  115.", 3L, 44L);
#ifdef Pfn_close_ar_file
   Pfn_close_ar_file == 115 ? pass_() : fail_();
#else				/* Pfn_close_ar_file */
   fail_ ();
#endif				/* Pfn_close_ar_file */
   setmsg_ ("1 2", "Pfn_ar_structs should be defined as  116.", 3L, 41L);
#ifdef Pfn_ar_structs
   Pfn_ar_structs == 116 ? pass_() : fail_();
#else				/* Pfn_ar_structs */
   fail_ ();
#endif				/* Pfn_ar_structs */
   setmsg_ ("1 2", "Pfn_ar_struct_nets should be defined as  117.", 3L, 45L);
#ifdef Pfn_ar_struct_nets
   Pfn_ar_struct_nets == 117 ? pass_() : fail_();
#else				/* Pfn_ar_struct_nets */
   fail_ ();
#endif				/* Pfn_ar_struct_nets */
   setmsg_ ("1 2", "Pfn_ar_all_structs should be defined as  118.", 3L, 45L);
#ifdef Pfn_ar_all_structs
   Pfn_ar_all_structs == 118 ? pass_() : fail_();
#else				/* Pfn_ar_all_structs */
   fail_ ();
#endif				/* Pfn_ar_all_structs */
   setmsg_ ("1 2", "Pfn_set_conf_res should be defined as  119.", 3L, 43L);
#ifdef Pfn_set_conf_res
   Pfn_set_conf_res == 119 ? pass_() : fail_();
#else				/* Pfn_set_conf_res */
   fail_ ();
#endif				/* Pfn_set_conf_res */
   setmsg_ ("1 2", "Pfn_ret_struct_ids should be defined as  120.", 3L, 45L);
#ifdef Pfn_ret_struct_ids
   Pfn_ret_struct_ids == 120 ? pass_() : fail_();
#else				/* Pfn_ret_struct_ids */
   fail_ ();
#endif				/* Pfn_ret_struct_ids */
   setmsg_ ("1 2", "Pfn_ret_structs should be defined as  121.", 3L, 42L);
#ifdef Pfn_ret_structs
   Pfn_ret_structs == 121 ? pass_() : fail_();
#else				/* Pfn_ret_structs */
   fail_ ();
#endif				/* Pfn_ret_structs */
   setmsg_ ("1 2", "Pfn_ret_struct_nets should be defined as  122.", 3L, 46L);
#ifdef Pfn_ret_struct_nets
   Pfn_ret_struct_nets == 122 ? pass_() : fail_();
#else				/* Pfn_ret_struct_nets */
   fail_ ();
#endif				/* Pfn_ret_struct_nets */
   setmsg_ ("1 2", "Pfn_ret_all_structs should be defined as  123.", 3L, 46L);
#ifdef Pfn_ret_all_structs
   Pfn_ret_all_structs == 123 ? pass_() : fail_();
#else				/* Pfn_ret_all_structs */
   fail_ ();
#endif				/* Pfn_ret_all_structs */
   setmsg_ ("1 2", "Pfn_ret_paths_ances should be defined as  124.", 3L, 47L);
#ifdef Pfn_ret_paths_ances
   Pfn_ret_paths_ances == 124 ? pass_() : fail_();
#else				/* Pfn_ret_paths_ances */
   fail_ ();
#endif				/* Pfn_ret_paths_ances */
   setmsg_ ("1 2", "Pfn_ret_paths_descs should be defined as  125.", 3L, 46L);
#ifdef Pfn_ret_paths_descs
   Pfn_ret_paths_descs == 125 ? pass_() : fail_();
#else				/* Pfn_ret_paths_descs */
   fail_ ();
#endif				/* Pfn_ret_paths_descs */
   setmsg_ ("1 2", "Pfn_del_structs_ar should be defined as  126.", 3L, 45L);
#ifdef Pfn_del_structs_ar
   Pfn_del_structs_ar == 126 ? pass_() : fail_();
#else				/* Pfn_del_structs_ar */
   fail_ ();
#endif				/* Pfn_del_structs_ar */
   setmsg_ ("1 2", "Pfn_del_struct_nets_ar should be defined as  127.", 3L, 49L);
#ifdef Pfn_del_struct_nets_ar
   Pfn_del_struct_nets_ar == 127 ? pass_() : fail_();
#else				/* Pfn_del_struct_nets_ar */
   fail_ ();
#endif				/* Pfn_del_struct_nets_ar */
   setmsg_ ("1 2", "Pfn_del_all_structs_ar should be defined as  128.", 3L, 49L);
#ifdef Pfn_del_all_structs_ar
   Pfn_del_all_structs_ar == 128 ? pass_() : fail_();
#else				/* Pfn_del_all_structs_ar */
   fail_ ();
#endif				/* Pfn_del_all_structs_ar */
   setmsg_ ("1 2", "Pfn_set_pick_id should be defined as  129.", 3L, 42L);
#ifdef Pfn_set_pick_id
   Pfn_set_pick_id == 129 ? pass_() : fail_();
#else				/* Pfn_set_pick_id */
   fail_ ();
#endif				/* Pfn_set_pick_id */
   setmsg_ ("1 2", "Pfn_set_pick_filter should be defined as  130.", 3L, 46L);
#ifdef Pfn_set_pick_filter
   Pfn_set_pick_filter == 130 ? pass_() : fail_();
#else				/* Pfn_set_pick_filter */
   fail_ ();
#endif				/* Pfn_set_pick_filter */
   setmsg_ ("1 2", "Pfn_init_loc3 should be defined as  131.", 3L, 40L);
#ifdef Pfn_init_loc3
   Pfn_init_loc3 == 131 ? pass_() : fail_();
#else				/* Pfn_init_loc3 */
   fail_ ();
#endif				/* Pfn_init_loc3 */
   setmsg_ ("1 2", "Pfn_init_loc should be defined as  132.", 3L, 39L);
#ifdef Pfn_init_loc
   Pfn_init_loc == 132 ? pass_() : fail_();
#else				/* Pfn_init_loc */
   fail_ ();
#endif				/* Pfn_init_loc */
   setmsg_ ("1 2", "Pfn_init_stroke3 should be defined as  133.", 3L, 43L);
#ifdef Pfn_init_stroke3
   Pfn_init_stroke3 == 133 ? pass_() : fail_();
#else				/* Pfn_init_stroke3 */
   fail_ ();
#endif				/* Pfn_init_stroke3 */
   setmsg_ ("1 2", "Pfn_init_stroke should be defined as  134.", 3L, 42L);
#ifdef Pfn_init_stroke
   Pfn_init_stroke == 134 ? pass_() : fail_();
#else				/* Pfn_init_stroke */
   fail_ ();
#endif				/* Pfn_init_stroke */
   setmsg_ ("1 2", "Pfn_init_val3 should be defined as  135.", 3L, 40L);
#ifdef Pfn_init_val3
   Pfn_init_val3 == 135 ? pass_() : fail_();
#else				/* Pfn_init_val3 */
   fail_ ();
#endif				/* Pfn_init_val3 */
   setmsg_ ("1 2", "Pfn_init_val should be defined as  136.", 3L, 39L);
#ifdef Pfn_init_val
   Pfn_init_val == 136 ? pass_() : fail_();
#else				/* Pfn_init_val */
   fail_ ();
#endif				/* Pfn_init_val */
   setmsg_ ("1 2", "Pfn_init_choice3 should be defined as  137.", 3L, 43L);
#ifdef Pfn_init_choice3
   Pfn_init_choice3 == 137 ? pass_() : fail_();
#else				/* Pfn_init_choice3 */
   fail_ ();
#endif				/* Pfn_init_choice3 */
   setmsg_ ("1 2", "Pfn_init_choice should be defined as  138.", 3L, 42L);
#ifdef Pfn_init_choice
   Pfn_init_choice == 138 ? pass_() : fail_();
#else				/* Pfn_init_choice */
   fail_ ();
#endif				/* Pfn_init_choice */
   setmsg_ ("1 2", "Pfn_init_pick3 should be defined as  139.", 3L, 41L);
#ifdef Pfn_init_pick3
   Pfn_init_pick3 == 139 ? pass_() : fail_();
#else				/* Pfn_init_pick3 */
   fail_ ();
#endif				/* Pfn_init_pick3 */
   setmsg_ ("1 2", "Pfn_init_pick should be defined as  140.", 3L, 40L);
#ifdef Pfn_init_pick
   Pfn_init_pick == 140 ? pass_() : fail_();
#else				/* Pfn_init_pick */
   fail_ ();
#endif				/* Pfn_init_pick */
   setmsg_ ("1 2", "Pfn_init_string3 should be defined as  141.", 3L, 43L);
#ifdef Pfn_init_string3
   Pfn_init_string3 == 141 ? pass_() : fail_();
#else				/* Pfn_init_string3 */
   fail_ ();
#endif				/* Pfn_init_string3 */
   setmsg_ ("1 2", "Pfn_init_string should be defined as  142.", 3L, 42L);
#ifdef Pfn_init_string
   Pfn_init_string == 142 ? pass_() : fail_();
#else				/* Pfn_init_string */
   fail_ ();
#endif				/* Pfn_init_string */
   setmsg_ ("1 2", "Pfn_set_loc_mode should be defined as  143.", 3L, 43L);
#ifdef Pfn_set_loc_mode
   Pfn_set_loc_mode == 143 ? pass_() : fail_();
#else				/* Pfn_set_loc_mode */
   fail_ ();
#endif				/* Pfn_set_loc_mode */
   setmsg_ ("1 2", "Pfn_set_stroke_mode should be defined as  144.", 3L, 46L);
#ifdef Pfn_set_stroke_mode
   Pfn_set_stroke_mode == 144 ? pass_() : fail_();
#else				/* Pfn_set_stroke_mode */
   fail_ ();
#endif				/* Pfn_set_stroke_mode */
   setmsg_ ("1 2", "Pfn_set_val_mode should be defined as  145.", 3L, 43L);
#ifdef Pfn_set_val_mode
   Pfn_set_val_mode == 145 ? pass_() : fail_();
#else				/* Pfn_set_val_mode */
   fail_ ();
#endif				/* Pfn_set_val_mode */
   setmsg_ ("1 2", "Pfn_set_choice_mode should be defined as  146.", 3L, 46L);
#ifdef Pfn_set_choice_mode
   Pfn_set_choice_mode == 146 ? pass_() : fail_();
#else				/* Pfn_set_choice_mode */
   fail_ ();
#endif				/* Pfn_set_choice_mode */
   setmsg_ ("1 2", "Pfn_set_pick_mode should be defined as  147.", 3L, 44L);
#ifdef Pfn_set_pick_mode
   Pfn_set_pick_mode == 147 ? pass_() : fail_();
#else				/* Pfn_set_pick_mode */
   fail_ ();
#endif				/* Pfn_set_pick_mode */
   setmsg_ ("1 2", "Pfn_set_string_mode should be defined as  148.", 3L, 46L);
#ifdef Pfn_set_string_mode
   Pfn_set_string_mode == 148 ? pass_() : fail_();
#else				/* Pfn_set_string_mode */
   fail_ ();
#endif				/* Pfn_set_string_mode */
   setmsg_ ("1 2", "Pfn_req_loc3 should be defined as  149.", 3L, 39L);
#ifdef Pfn_req_loc3
   Pfn_req_loc3 == 149 ? pass_() : fail_();
#else				/* Pfn_req_loc3 */
   fail_ ();
#endif				/* Pfn_req_loc3 */
   setmsg_ ("1 2", "Pfn_req_loc should be defined as  150.", 3L, 38L);
#ifdef Pfn_req_loc
   Pfn_req_loc == 150 ? pass_() : fail_();
#else				/* Pfn_req_loc */
   fail_ ();
#endif				/* Pfn_req_loc */
   setmsg_ ("1 2", "Pfn_req_stroke3 should be defined as  151.", 3L, 42L);
#ifdef Pfn_req_stroke3
   Pfn_req_stroke3 == 151 ? pass_() : fail_();
#else				/* Pfn_req_stroke3 */
   fail_ ();
#endif				/* Pfn_req_stroke3 */
   setmsg_ ("1 2", "Pfn_req_stroke should be defined as  152.", 3L, 41L);
#ifdef Pfn_req_stroke
   Pfn_req_stroke == 152 ? pass_() : fail_();
#else				/* Pfn_req_stroke */
   fail_ ();
#endif				/* Pfn_req_stroke */
   setmsg_ ("1 2", "Pfn_req_val should be defined as  153.", 3L, 38L);
#ifdef Pfn_req_val
   Pfn_req_val == 153 ? pass_() : fail_();
#else				/* Pfn_req_val */
   fail_ ();
#endif				/* Pfn_req_val */
   setmsg_ ("1 2", "Pfn_req_choice should be defined as  154.", 3L, 41L);
#ifdef Pfn_req_choice
   Pfn_req_choice == 154 ? pass_() : fail_();
#else				/* Pfn_req_choice */
   fail_ ();
#endif				/* Pfn_req_choice */
   setmsg_ ("1 2", "Pfn_req_pick should be defined as  155.", 3L, 39L);
#ifdef Pfn_req_pick
   Pfn_req_pick == 155 ? pass_() : fail_();
#else				/* Pfn_req_pick */
   fail_ ();
#endif				/* Pfn_req_pick */
   setmsg_ ("1 2", "Pfn_req_string should be defined as  156.", 3L, 41L);
#ifdef Pfn_req_string
   Pfn_req_string == 156 ? pass_() : fail_();
#else				/* Pfn_req_string */
   fail_ ();
#endif				/* Pfn_req_string */
   setmsg_ ("1 2", "Pfn_sample_loc3 should be defined as  157.", 3L, 42L);
#ifdef Pfn_sample_loc3
   Pfn_sample_loc3 == 157 ? pass_() : fail_();
#else				/* Pfn_sample_loc3 */
   fail_ ();
#endif				/* Pfn_sample_loc3 */
   setmsg_ ("1 2", "Pfn_sample_loc should be defined as  158.", 3L, 41L);
#ifdef Pfn_sample_loc
   Pfn_sample_loc == 158 ? pass_() : fail_();
#else				/* Pfn_sample_loc */
   fail_ ();
#endif				/* Pfn_sample_loc */
   setmsg_ ("1 2", "Pfn_sample_stroke3 should be defined as  159.", 3L, 45L);
#ifdef Pfn_sample_stroke3
   Pfn_sample_stroke3 == 159 ? pass_() : fail_();
#else				/* Pfn_sample_stroke3 */
   fail_ ();
#endif				/* Pfn_sample_stroke3 */
   setmsg_ ("1 2", "Pfn_sample_stroke should be defined as  160.", 3L, 44L);
#ifdef Pfn_sample_stroke
   Pfn_sample_stroke == 160 ? pass_() : fail_();
#else				/* Pfn_sample_stroke */
   fail_ ();
#endif				/* Pfn_sample_stroke */
   setmsg_ ("1 2", "Pfn_sample_val should be defined as  161.", 3L, 41L);
#ifdef Pfn_sample_val
   Pfn_sample_val == 161 ? pass_() : fail_();
#else				/* Pfn_sample_val */
   fail_ ();
#endif				/* Pfn_sample_val */
   setmsg_ ("1 2", "Pfn_sample_choice should be defined as  162.", 3L, 44L);
#ifdef Pfn_sample_choice
   Pfn_sample_choice == 162 ? pass_() : fail_();
#else				/* Pfn_sample_choice */
   fail_ ();
#endif				/* Pfn_sample_choice */
   setmsg_ ("1 2", "Pfn_sample_pick should be defined as  163.", 3L, 42L);
#ifdef Pfn_sample_pick
   Pfn_sample_pick == 163 ? pass_() : fail_();
#else				/* Pfn_sample_pick */
   fail_ ();
#endif				/* Pfn_sample_pick */
   setmsg_ ("1 2", "Pfn_sample_string should be defined as  164.", 3L, 44L);
#ifdef Pfn_sample_string
   Pfn_sample_string == 164 ? pass_() : fail_();
#else				/* Pfn_sample_string */
   fail_ ();
#endif				/* Pfn_sample_string */
   setmsg_ ("1 2", "Pfn_await_event should be defined as  165.", 3L, 42L);
#ifdef Pfn_await_event
   Pfn_await_event == 165 ? pass_() : fail_();
#else				/* Pfn_await_event */
   fail_ ();
#endif				/* Pfn_await_event */
   setmsg_ ("1 2", "Pfn_flush_events should be defined as  166.", 3L, 43L);
#ifdef Pfn_flush_events
   Pfn_flush_events == 166 ? pass_() : fail_();
#else				/* Pfn_flush_events */
   fail_ ();
#endif				/* Pfn_flush_events */
   setmsg_ ("1 2", "Pfn_get_loc3 should be defined as  167.", 3L, 39L);
#ifdef Pfn_get_loc3
   Pfn_get_loc3 == 167 ? pass_() : fail_();
#else				/* Pfn_get_loc3 */
   fail_ ();
#endif				/* Pfn_get_loc3 */
   setmsg_ ("1 2", "Pfn_get_loc should be defined as  168.", 3L, 38L);
#ifdef Pfn_get_loc
   Pfn_get_loc == 168 ? pass_() : fail_();
#else				/* Pfn_get_loc */
   fail_ ();
#endif				/* Pfn_get_loc */
   setmsg_ ("1 2", "Pfn_get_stroke3 should be defined as  169.", 3L, 42L);
#ifdef Pfn_get_stroke3
   Pfn_get_stroke3 == 169 ? pass_() : fail_();
#else				/* Pfn_get_stroke3 */
   fail_ ();
#endif				/* Pfn_get_stroke3 */
   setmsg_ ("1 2", "Pfn_get_stroke should be defined as  170.", 3L, 41L);
#ifdef Pfn_get_stroke
   Pfn_get_stroke == 170 ? pass_() : fail_();
#else				/* Pfn_get_stroke */
   fail_ ();
#endif				/* Pfn_get_stroke */
   setmsg_ ("1 2", "Pfn_get_val should be defined as  171.", 3L, 38L);
#ifdef Pfn_get_val
   Pfn_get_val == 171 ? pass_() : fail_();
#else				/* Pfn_get_val */
   fail_ ();
#endif				/* Pfn_get_val */
   setmsg_ ("1 2", "Pfn_get_choice should be defined as  172.", 3L, 41L);
#ifdef Pfn_get_choice
   Pfn_get_choice == 172 ? pass_() : fail_();
#else				/* Pfn_get_choice */
   fail_ ();
#endif				/* Pfn_get_choice */
   setmsg_ ("1 2", "Pfn_get_pick should be defined as  173.", 3L, 39L);
#ifdef Pfn_get_pick
   Pfn_get_pick == 173 ? pass_() : fail_();
#else				/* Pfn_get_pick */
   fail_ ();
#endif				/* Pfn_get_pick */
   setmsg_ ("1 2", "Pfn_get_string should be defined as  174.", 3L, 41L);
#ifdef Pfn_get_string
   Pfn_get_string == 174 ? pass_() : fail_();
#else				/* Pfn_get_string */
   fail_ ();
#endif				/* Pfn_get_string */
   setmsg_ ("1 2", "Pfn_write_item should be defined as  175.", 3L, 41L);
#ifdef Pfn_write_item
   Pfn_write_item == 175 ? pass_() : fail_();
#else				/* Pfn_write_item */
   fail_ ();
#endif				/* Pfn_write_item */
   setmsg_ ("1 2", "Pfn_get_item_type should be defined as  176.", 3L, 44L);
#ifdef Pfn_get_item_type
   Pfn_get_item_type == 176 ? pass_() : fail_();
#else				/* Pfn_get_item_type */
   fail_ ();
#endif				/* Pfn_get_item_type */
   setmsg_ ("1 2", "Pfn_read_item should be defined as  177.", 3L, 40L);
#ifdef Pfn_read_item
   Pfn_read_item == 177 ? pass_() : fail_();
#else				/* Pfn_read_item */
   fail_ ();
#endif				/* Pfn_read_item */
   setmsg_ ("1 2", "Pfn_interpret_item should be defined as  178.", 3L, 45L);
#ifdef Pfn_interpret_item
   Pfn_interpret_item == 178 ? pass_() : fail_();
#else				/* Pfn_interpret_item */
   fail_ ();
#endif				/* Pfn_interpret_item */
   setmsg_ ("1 2", "Pfn_set_err_hand_mode should be defined as  179.", 3L, 48L);
#ifdef Pfn_set_err_hand_mode
   Pfn_set_err_hand_mode == 179 ? pass_() : fail_();
#else				/* Pfn_set_err_hand_mode */
   fail_ ();
#endif				/* Pfn_set_err_hand_mode */
   setmsg_ ("1 2", "Pfn_escape should be defined as  180.", 3L, 37L);
#ifdef Pfn_escape
   Pfn_escape == 180 ? pass_() : fail_();
#else				/* Pfn_escape */
   fail_ ();
#endif				/* Pfn_escape */
   setmsg_ ("1 2", "Pfn_set_err_hand should be defined as  181.", 3L, 43L);
#ifdef Pfn_set_err_hand
   Pfn_set_err_hand == 181 ? pass_() : fail_();
#else				/* Pfn_set_err_hand */
   fail_ ();
#endif				/* Pfn_set_err_hand */
}



error_check ()
{
/** 6.2 ERROR  codes **/

/* Implementation Dependent Errors   are < 0 */

/* State Errors */

   setmsg_ ("1 3", "PE_NO_ERROR should be defined as  0.", 3L, 36L);
#ifdef PE_NO_ERROR
/* No Error */
   PE_NO_ERROR == 0 ? pass_() : fail_();
#else				/* PE_NO_ERROR */
   fail_ ();
#endif				/* PE_NO_ERROR */
   setmsg_ ("1 3", "PE_NOT_PHCL should be defined as  1.", 3L, 36L);
#ifdef PE_NOT_PHCL
/*
 * Ignoring function, function requires state (PHCL,WSCL,STCL,ARCL   )
 */
   PE_NOT_PHCL == 1 ? pass_() : fail_();
#else				/* PE_NOT_PHCL */
   fail_ ();
#endif				/* PE_NOT_PHCL */
   setmsg_ ("1 3", "PE_NOT_PHOP should be defined as  2.", 3L, 36L);
#ifdef PE_NOT_PHOP
/*
 * Ignoring function, function requires state (PHOP,*,*,*   )
 */
   PE_NOT_PHOP == 2 ? pass_() : fail_();
#else				/* PE_NOT_PHOP */
   fail_ ();
#endif				/* PE_NOT_PHOP */
   setmsg_ ("1 3", "PE_NOT_WSOP should be defined as  3.", 3L, 36L);
#ifdef PE_NOT_WSOP
/*
 * Ignoring function, function requires state (PHOP,WSOP,*,*   )
 */
   PE_NOT_WSOP == 3 ? pass_() : fail_();
#else				/* PE_NOT_WSOP */
   fail_ ();
#endif				/* PE_NOT_WSOP */
   setmsg_ ("1 3", "PE_NOT_CL should be defined as  4.", 3L, 34L);
#ifdef PE_NOT_CL
/*
 * Ignoring function, function requires state (PHOP,WSCL,STCL,ARCL   )
 */
   PE_NOT_CL == 4 ? pass_() : fail_();
#else				/* PE_NOT_CL */
   fail_ ();
#endif				/* PE_NOT_CL */
   setmsg_ ("1 3", "PE_NOT_STOP should be defined as  5.", 3L, 36L);
#ifdef PE_NOT_STOP
/*
 * Ignoring function, function requires state (PHOP,*,STOP,*   )
 */
   PE_NOT_STOP == 5 ? pass_() : fail_();
#else				/* PE_NOT_STOP */
   fail_ ();
#endif				/* PE_NOT_STOP */
   setmsg_ ("1 3", "PE_NOT_STCL should be defined as  6.", 3L, 36L);
#ifdef PE_NOT_STCL
/*
 * Ignoring function, function requires state (PHOP,*,STCL,*   )
 */
   PE_NOT_STCL == 6 ? pass_() : fail_();
#else				/* PE_NOT_STCL */
   fail_ ();
#endif				/* PE_NOT_STCL */
   setmsg_ ("1 3", "PE_NOT_AROP should be defined as  7.", 3L, 36L);
#ifdef PE_NOT_AROP
/*
 * Ignoring function, function requires state (PHOP,*,*,AROP   )
 */
   PE_NOT_AROP == 7 ? pass_() : fail_();
#else				/* PE_NOT_AROP */
   fail_ ();
#endif				/* PE_NOT_AROP */
/* Workstation Errors */

   setmsg_ ("1 3", "PE_BAD_CONN_ID should be defined as  50.", 3L, 40L);
#ifdef PE_BAD_CONN_ID
/*
 * Ignoring function, connection identifier not recognized by the
 * implementation
 */
   PE_BAD_CONN_ID == 50 ? pass_() : fail_();
#else				/* PE_BAD_CONN_ID */
   fail_ ();
#endif				/* PE_BAD_CONN_ID */
   setmsg_ ("1 3", "PE_WS_TYPE should be defined as  51.", 3L, 36L);
#ifdef PE_WS_TYPE
/*
 * Ignoring function, this information is not yet available for this generic
 * workstation type; open a workstation of this type and use the specific
 * workstation type
 */
   PE_WS_TYPE == 51 ? pass_() : fail_();
#else				/* PE_WS_TYPE */
   fail_ ();
#endif				/* PE_WS_TYPE */
   setmsg_ ("1 3", "PE_BAD_WS_TYPE should be defined as  52.", 3L, 40L);
#ifdef PE_BAD_WS_TYPE
/*
 * Ignoring function, workstation type not recognized by the implementation
 */
   PE_BAD_WS_TYPE == 52 ? pass_() : fail_();
#else				/* PE_BAD_WS_TYPE */
   fail_ ();
#endif				/* PE_BAD_WS_TYPE */
   setmsg_ ("1 3", "PE_DUP_WS_ID should be defined as  53.", 3L, 38L);
#ifdef PE_DUP_WS_ID
/*
 * Ignoring function, workstation identifier already is in use
 */
   PE_DUP_WS_ID == 53 ? pass_() : fail_();
#else				/* PE_DUP_WS_ID */
   fail_ ();
#endif				/* PE_DUP_WS_ID */
   setmsg_ ("1 3", "PE_WS_NOT_OPEN should be defined as  54.", 3L, 40L);
#ifdef PE_WS_NOT_OPEN
/*
 * Ignoring function, the specified workstation is not open
 */
   PE_WS_NOT_OPEN == 54 ? pass_() : fail_();
#else				/* PE_WS_NOT_OPEN */
   fail_ ();
#endif				/* PE_WS_NOT_OPEN */
   setmsg_ ("1 3", "PE_NO_OPEN_WS should be defined as  55.", 3L, 39L);
#ifdef PE_NO_OPEN_WS
/*
 * Ignoring function, workstation cannot be opened for an implementation
 * dependent reason
 */
   PE_NO_OPEN_WS == 55 ? pass_() : fail_();
#else				/* PE_NO_OPEN_WS */
   fail_ ();
#endif				/* PE_NO_OPEN_WS */
   setmsg_ ("1 3", "PE_WS_NOT_MO should be defined as  56.", 3L, 38L);
#ifdef PE_WS_NOT_MO
/*
 * Ignoring function, specified workstation is not of category MO
 */
   PE_WS_NOT_MO == 56 ? pass_() : fail_();
#else				/* PE_WS_NOT_MO */
   fail_ ();
#endif				/* PE_WS_NOT_MO */
   setmsg_ ("1 3", "PE_WS_MI should be defined as  57.", 3L, 34L);
#ifdef PE_WS_MI
/*
 * Ignoring function, specified workstation is of category MI
 */
   PE_WS_MI == 57 ? pass_() : fail_();
#else				/* PE_WS_MI */
   fail_ ();
#endif				/* PE_WS_MI */
   setmsg_ ("1 3", "PE_WS_NOT_MI should be defined as  58.", 3L, 38L);
#ifdef PE_WS_NOT_MI
/*
 * Ignoring function, specified workstation is not of category MI
 */
   PE_WS_NOT_MI == 58 ? pass_() : fail_();
#else				/* PE_WS_NOT_MI */
   fail_ ();
#endif				/* PE_WS_NOT_MI */
   setmsg_ ("1 3", "PE_WS_NO_OUTPUT should be defined as  59.", 3L, 41L);
#ifdef PE_WS_NO_OUTPUT
/*
 * Ignoring function, the specified workstation does not have output
 * capability (i.e., the workstation category is neither OUTPUT, OUTIN, nor
 * MO   )
 */
   PE_WS_NO_OUTPUT == 59 ? pass_() : fail_();
#else				/* PE_WS_NO_OUTPUT */
   fail_ ();
#endif				/* PE_WS_NO_OUTPUT */
   setmsg_ ("1 3", "PE_WS_NOT_OUTIN should be defined as  60.", 3L, 41L);
#ifdef PE_WS_NOT_OUTIN
/*
 * Ignoring function, specified workstation is not of category OUTIN
 */
   PE_WS_NOT_OUTIN == 60 ? pass_() : fail_();
#else				/* PE_WS_NOT_OUTIN */
   fail_ ();
#endif				/* PE_WS_NOT_OUTIN */
   setmsg_ ("1 3", "PE_WS_NO_INPUT should be defined as  61.", 3L, 40L);
#ifdef PE_WS_NO_INPUT
/*
 * Ignoring function, specified workstation is neither of category INPUT nor
 * of category OUTIN
 */
   PE_WS_NO_INPUT == 61 ? pass_() : fail_();
#else				/* PE_WS_NO_INPUT */
   fail_ ();
#endif				/* PE_WS_NO_INPUT */
   setmsg_ ("1 3", "PE_WS_NOT_OUT should be defined as  62.", 3L, 39L);
#ifdef PE_WS_NOT_OUT
/*
 * Ignoring function, this information is not available for this MO
 * workstation type
 */
   PE_WS_NOT_OUT == 62 ? pass_() : fail_();
#else				/* PE_WS_NOT_OUT */
   fail_ ();
#endif				/* PE_WS_NOT_OUT */
   setmsg_ ("1 3", "PE_MAX_WS should be defined as  63.", 3L, 35L);
#ifdef PE_MAX_WS
/*
 * Ignoring function, opening this workstation would exceed the maximum
 * number of simultaneously open workstations
 */
   PE_MAX_WS == 63 ? pass_() : fail_();
#else				/* PE_MAX_WS */
   fail_ ();
#endif				/* PE_MAX_WS */
   setmsg_ ("1 3", "PE_NO_GDP should be defined as  64.", 3L, 35L);
#ifdef PE_NO_GDP
/*
 * Ignoring function, the specified workstation type is not able to generate
 * the specified generalized drawing primitive
 */
   PE_NO_GDP == 64 ? pass_() : fail_();
#else				/* PE_NO_GDP */
   fail_ ();
#endif				/* PE_NO_GDP */
/* Output Attribute Errors */

   setmsg_ ("1 3", "PE_BUN_IND_LT_1 should be defined as  100.", 3L, 43L);
#ifdef PE_BUN_IND_LT_1
/*
 * Ignoring function, the bundle index value is less than one
 */
   PE_BUN_IND_LT_1 == 100 ? pass_() : fail_();
#else				/* PE_BUN_IND_LT_1 */
   fail_ ();
#endif				/* PE_BUN_IND_LT_1 */
   setmsg_ ("1 3", "PE_REP_UNDEF should be defined as  101.", 3L, 39L);
#ifdef PE_REP_UNDEF
/*
 * The specified representation has not been defined
 */
   PE_REP_UNDEF == 101 ? pass_() : fail_();
#else				/* PE_REP_UNDEF */
   fail_ ();
#endif				/* PE_REP_UNDEF */
   setmsg_ ("1 3", "PE_REP_NOT_PREDEF should be defined as  102.", 3L, 44L);
#ifdef PE_REP_NOT_PREDEF
/*
 * Ignoring function, the specified representation has not be predefined on
 * this workstation
 */
   PE_REP_NOT_PREDEF == 102 ? pass_() : fail_();
#else				/* PE_REP_NOT_PREDEF */
   fail_ ();
#endif				/* PE_REP_NOT_PREDEF */
   setmsg_ ("1 3", "PE_MAX_BUN should be defined as  103.", 3L, 37L);
#ifdef PE_MAX_BUN
/*
 * Ignoring function, setting this bundle table entry would exceed the
 * maximum number of entries allowed in the workstation bundle table
 */
   PE_MAX_BUN == 103 ? pass_() : fail_();
#else				/* PE_MAX_BUN */
   fail_ ();
#endif				/* PE_MAX_BUN */
   setmsg_ ("1 3", "PE_BAD_LINETYPE should be defined as  104.", 3L, 42L);
#ifdef PE_BAD_LINETYPE
/*
 * Ignoring function, the specified linetype is not available on the
 * specified workstation
 */
   PE_BAD_LINETYPE == 104 ? pass_() : fail_();
#else				/* PE_BAD_LINETYPE */
   fail_ ();
#endif				/* PE_BAD_LINETYPE */
   setmsg_ ("1 3", "PE_BAD_MARKER_TYPE should be defined as  105.", 3L, 45L);
#ifdef PE_BAD_MARKER_TYPE
/*
 * Ignoring function, the specified marker type is not available on the
 * specified workstation
 */
   PE_BAD_MARKER_TYPE == 105 ? pass_() : fail_();
#else				/* PE_BAD_MARKER_TYPE */
   fail_ ();
#endif				/* PE_BAD_MARKER_TYPE */
   setmsg_ ("1 3", "PE_BAD_FONT should be defined as  106.", 3L, 38L);
#ifdef PE_BAD_FONT
/*
 * Ignoring function, the specified font is not available for the requested
 * text precision on the specified workstation
 */
   PE_BAD_FONT == 106 ? pass_() : fail_();
#else				/* PE_BAD_FONT */
   fail_ ();
#endif				/* PE_BAD_FONT */
   setmsg_ ("1 3", "PE_BAD_EDGETYPE should be defined as  107.", 3L, 42L);
#ifdef PE_BAD_EDGETYPE
/*
 * Ignoring function, the specified edgetype is not available on the
 * specified workstation
 */
   PE_BAD_EDGETYPE == 107 ? pass_() : fail_();
#else				/* PE_BAD_EDGETYPE */
   fail_ ();
#endif				/* PE_BAD_EDGETYPE */
   setmsg_ ("1 3", "PE_BAD_INT_STYLE should be defined as  108.", 3L, 43L);
#ifdef PE_BAD_INT_STYLE
/*
 * Ignoring function, the specified interior style is not available on the
 * workstation
 */
   PE_BAD_INT_STYLE == 108 ? pass_() : fail_();
#else				/* PE_BAD_INT_STYLE */
   fail_ ();
#endif				/* PE_BAD_INT_STYLE */
   setmsg_ ("1 3", "PE_NO_PAT should be defined as  109.", 3L, 36L);
#ifdef PE_NO_PAT
/*
 * Ignoring function, interior style PATTERN is not supported on the
 * workstation
 */
   PE_NO_PAT == 109 ? pass_() : fail_();
#else				/* PE_NO_PAT */
   fail_ ();
#endif				/* PE_NO_PAT */
   setmsg_ ("1 3", "PE_BAD_COLR_MODEL should be defined as  110.", 3L, 44L);
#ifdef PE_BAD_COLR_MODEL
/*
 * Ignoring function, the specified colour model is not available on the
 * workstation.
 */
   PE_BAD_COLR_MODEL == 110 ? pass_() : fail_();
#else				/* PE_BAD_COLR_MODEL */
   fail_ ();
#endif				/* PE_BAD_COLR_MODEL */
   setmsg_ ("1 3", "PE_BAD_HLHSR_MODE should be defined as  111.", 3L, 44L);
#ifdef PE_BAD_HLHSR_MODE
/*
 * Ignoring function, the specified HLHSR mode is not available on the
 * specified workstation
 */
   PE_BAD_HLHSR_MODE == 111 ? pass_() : fail_();
#else				/* PE_BAD_HLHSR_MODE */
   fail_ ();
#endif				/* PE_BAD_HLHSR_MODE */
   setmsg_ ("1 3", "PE_PAT_IND_LT_1 should be defined as  112.", 3L, 43L);
#ifdef PE_PAT_IND_LT_1
/*
 * Ignoring function, the pattern index value is less than one
 */
   PE_PAT_IND_LT_1 == 112 ? pass_() : fail_();
#else				/* PE_PAT_IND_LT_1 */
   fail_ ();
#endif				/* PE_PAT_IND_LT_1 */
   setmsg_ ("1 3", "PE_COLR_IND_LT_0 should be defined as  113.", 3L, 44L);
#ifdef PE_COLR_IND_LT_0
/*
 * Ignoring function, the colour index value is less than zero
 */
   PE_COLR_IND_LT_0 == 113 ? pass_() : fail_();
#else				/* PE_COLR_IND_LT_0 */
   fail_ ();
#endif				/* PE_COLR_IND_LT_0 */
   setmsg_ ("1 3", "PE_VIEW_IND_LT_0 should be defined as  114.", 3L, 44L);
#ifdef PE_VIEW_IND_LT_0
/*
 * Ignoring function, the view index value is less than zero
 */
   PE_VIEW_IND_LT_0 == 114 ? pass_() : fail_();
#else				/* PE_VIEW_IND_LT_0 */
   fail_ ();
#endif				/* PE_VIEW_IND_LT_0 */
   setmsg_ ("1 3", "PE_VIEW_IND_LT_1 should be defined as  115.", 3L, 44L);
#ifdef PE_VIEW_IND_LT_1
/*
 * Ignoring function, the view index value is less than one
 */
   PE_VIEW_IND_LT_1 == 115 ? pass_() : fail_();
#else				/* PE_VIEW_IND_LT_1 */
   fail_ ();
#endif				/* PE_VIEW_IND_LT_1 */
   setmsg_ ("1 3", "PE_BAD_PAT_DIM should be defined as  116.", 3L, 41L);
#ifdef PE_BAD_PAT_DIM
/*
 * Ignoring function, one of the dimensions of pattern colour array is less
 * than one
 */
   PE_BAD_PAT_DIM == 116 ? pass_() : fail_();
#else				/* PE_BAD_PAT_DIM */
   fail_ ();
#endif				/* PE_BAD_PAT_DIM */
   setmsg_ ("1 3", "PE_BAD_COLR_DIM should be defined as  117.", 3L, 42L);
#ifdef PE_BAD_COLR_DIM
/*
 * Ignoring function, one of the dimensions of the colour index array is less
 * than zero
 */
   PE_BAD_COLR_DIM == 117 ? pass_() : fail_();
#else				/* PE_BAD_COLR_DIM */
   fail_ ();
#endif				/* PE_BAD_COLR_DIM */
   setmsg_ ("1 3", "PE_BAD_COLR should be defined as  118.", 3L, 38L);
#ifdef PE_BAD_COLR
/*
 * Ignoring function, one of the components of the colour specification is
 * out of range. The valid range is dependent upon the current colour model
 */
   PE_BAD_COLR == 118 ? pass_() : fail_();
#else				/* PE_BAD_COLR */
   fail_ ();
#endif				/* PE_BAD_COLR */
/* Transformation and Viewing Errors  */

   setmsg_ ("1 3", "PE_MAX_VIEW should be defined as  150.", 3L, 38L);
#ifdef PE_MAX_VIEW
/*
 * Ignoring function, setting this view table entry would exceed the maximum
 * number of entries allowed in the workstation's view table
 */
   PE_MAX_VIEW == 150 ? pass_() : fail_();
#else				/* PE_MAX_VIEW */
   fail_ ();
#endif				/* PE_MAX_VIEW */
   setmsg_ ("1 3", "PE_INVALID_WINDOW should be defined as  151.", 3L, 44L);
#ifdef PE_INVALID_WINDOW
/*
 * Ignoring function, invalid window; XMIN >= XMAX, YMIN >= YMAX, or ZMIN >
 * ZMAX
 */
   PE_INVALID_WINDOW == 151 ? pass_() : fail_();
#else				/* PE_INVALID_WINDOW */
   fail_ ();
#endif				/* PE_INVALID_WINDOW */
   setmsg_ ("1 3", "PE_INVALID_VIEWPORT should be defined as  152.", 3L, 46L);
#ifdef PE_INVALID_VIEWPORT
/*
 * Ignoring function, invalid viewport; XMIN >= XMAX, YMIN >= YMAX, or ZMIN >
 * ZMAX
 */
   PE_INVALID_VIEWPORT == 152 ? pass_() : fail_();
#else				/* PE_INVALID_VIEWPORT */
   fail_ ();
#endif				/* PE_INVALID_VIEWPORT */
   setmsg_ ("1 3", "PE_INVALID_CLIP should be defined as  153.", 3L, 42L);
#ifdef PE_INVALID_CLIP
/*
 * Ignoring function, invalid view clipping limits; XMIN >= XMAX, YMIN >=
 * YMAX, or ZMIN > ZMAX
 */
   PE_INVALID_CLIP == 153 ? pass_() : fail_();
#else				/* PE_INVALID_CLIP */
   fail_ ();
#endif				/* PE_INVALID_CLIP */
   setmsg_ ("1 3", "PE_BAD_CLIP should be defined as  154.", 3L, 38L);
#ifdef PE_BAD_CLIP
/*
 * Ignoring function, the view clipping limits are not within NPC range
 */
   PE_BAD_CLIP == 154 ? pass_() : fail_();
#else				/* PE_BAD_CLIP */
   fail_ ();
#endif				/* PE_BAD_CLIP */
   setmsg_ ("1 3", "PE_BAD_PROJ_VIEWPORT should be defined as  155.", 3L, 47L);
#ifdef PE_BAD_PROJ_VIEWPORT
/*
 * Ignoring function, the projection viewport limits are not within NPC range
 */
   PE_BAD_PROJ_VIEWPORT == 155 ? pass_() : fail_();
#else				/* PE_BAD_PROJ_VIEWPORT */
   fail_ ();
#endif				/* PE_BAD_PROJ_VIEWPORT */
   setmsg_ ("1 3", "PE_BAD_WS_WINDOW should be defined as  156.", 3L, 43L);
#ifdef PE_BAD_WS_WINDOW
/*
 * Ignoring function, the workstation window limits are not within NPC range
 */
   PE_BAD_WS_WINDOW == 156 ? pass_() : fail_();
#else				/* PE_BAD_WS_WINDOW */
   fail_ ();
#endif				/* PE_BAD_WS_WINDOW */
   setmsg_ ("1 3", "PE_BAD_WS_VIEWPORT should be defined as  157.", 3L, 45L);
#ifdef PE_BAD_WS_VIEWPORT
/*
 * Ignoring function, the workstation viewport is not within display space
 */
   PE_BAD_WS_VIEWPORT == 157 ? pass_() : fail_();
#else				/* PE_BAD_WS_VIEWPORT */
   fail_ ();
#endif				/* PE_BAD_WS_VIEWPORT */
   setmsg_ ("1 3", "PE_BAD_PLANES should be defined as  158.", 3L, 40L);
#ifdef PE_BAD_PLANES
/*
 * Ignoring function, front plane and back plane distances are equal when
 * z-extent of the projection viewport is zero
 */
   PE_BAD_PLANES == 158 ? pass_() : fail_();
#else				/* PE_BAD_PLANES */
   fail_ ();
#endif				/* PE_BAD_PLANES */
   setmsg_ ("1 3", "PE_BAD_VPN should be defined as  159.", 3L, 37L);
#ifdef PE_BAD_VPN
/*
 * Ignoring function, the view plane normal vector has length zero
 */
   PE_BAD_VPN == 159 ? pass_() : fail_();
#else				/* PE_BAD_VPN */
   fail_ ();
#endif				/* PE_BAD_VPN */
   setmsg_ ("1 3", "PE_BAD_VUP should be defined as  160.", 3L, 37L);
#ifdef PE_BAD_VUP
/*
 * Ignoring function, the view up vector has length zero
 */
   PE_BAD_VUP == 160 ? pass_() : fail_();
#else				/* PE_BAD_VUP */
   fail_ ();
#endif				/* PE_BAD_VUP */
   setmsg_ ("1 3", "PE_BAD_VUP_VPN should be defined as  161.", 3L, 41L);
#ifdef PE_BAD_VUP_VPN
/*
 * Ignoring function, the view up and view plane normal vectors are parallel
 * thus the viewing coordinate system cannot be established
 */
   PE_BAD_VUP_VPN == 161 ? pass_() : fail_();
#else				/* PE_BAD_VUP_VPN */
   fail_ ();
#endif				/* PE_BAD_VUP_VPN */
   setmsg_ ("1 3", "PE_BAD_PRP should be defined as  162.", 3L, 37L);
#ifdef PE_BAD_PRP
/*
 * Ignoring function, the projection reference point is between the front and
 * back planes
 */
   PE_BAD_PRP == 162 ? pass_() : fail_();
#else				/* PE_BAD_PRP */
   fail_ ();
#endif				/* PE_BAD_PRP */
   setmsg_ ("1 3", "PE_PRP_VIEW_PLANE should be defined as  163.", 3L, 44L);
#ifdef PE_PRP_VIEW_PLANE
/*
 * Ignoring function, the projection reference point cannot be positioned on
 * the view plane
 */
   PE_PRP_VIEW_PLANE == 163 ? pass_() : fail_();
#else				/* PE_PRP_VIEW_PLANE */
   fail_ ();
#endif				/* PE_PRP_VIEW_PLANE */
   setmsg_ ("1 3", "PE_FRONT_BACK should be defined as  164.", 3L, 40L);
#ifdef PE_FRONT_BACK
/*
 * Ignoring function, the back plane is in front of the front plane
 */
   PE_FRONT_BACK == 164 ? pass_() : fail_();
#else				/* PE_FRONT_BACK */
   fail_ ();
#endif				/* PE_FRONT_BACK */
/* Structure Errors */

   setmsg_ ("1 3", "PE_IGNORE_STRUCTS should be defined as  200.", 3L, 44L);
#ifdef PE_IGNORE_STRUCTS
/*
 * Warning, ignoring structures that do not exist
 */
   PE_IGNORE_STRUCTS == 200 ? pass_() : fail_();
#else				/* PE_IGNORE_STRUCTS */
   fail_ ();
#endif				/* PE_IGNORE_STRUCTS */
   setmsg_ ("1 3", "PE_BAD_STRUCT should be defined as  201.", 3L, 40L);
#ifdef PE_BAD_STRUCT
/*
 * Ignoring function, the specified structure does not exist
 */
   PE_BAD_STRUCT == 201 ? pass_() : fail_();
#else				/* PE_BAD_STRUCT */
   fail_ ();
#endif				/* PE_BAD_STRUCT */
   setmsg_ ("1 3", "PE_BAD_ELEMENT should be defined as  202.", 3L, 41L);
#ifdef PE_BAD_ELEMENT
/*
 * Ignoring function, the specified element does not exist
 */
   PE_BAD_ELEMENT == 202 ? pass_() : fail_();
#else				/* PE_BAD_ELEMENT */
   fail_ ();
#endif				/* PE_BAD_ELEMENT */
   setmsg_ ("1 3", "PE_BAD_PATH should be defined as  203.", 3L, 38L);
#ifdef PE_BAD_PATH
/*
 * Ignoring function, specified starting path not found in CSS
 */
   PE_BAD_PATH == 203 ? pass_() : fail_();
#else				/* PE_BAD_PATH */
   fail_ ();
#endif				/* PE_BAD_PATH */
   setmsg_ ("1 3", "PE_BAD_CEILING_IND should be defined as  204.", 3L, 46L);
#ifdef PE_BAD_CEILING_IND
/*
 * Ignoring function, specified search ceiling index out of range
 */
   PE_BAD_CEILING_IND == 204 ? pass_() : fail_();
#else				/* PE_BAD_CEILING_IND */
   fail_ ();
#endif				/* PE_BAD_CEILING_IND */
   setmsg_ ("1 3", "PE_NO_LABEL should be defined as  205.", 3L, 38L);
#ifdef PE_NO_LABEL
/*
 * Ignoring function, the label does not exist in the open structure between
 * the element pointer and the end of the structure
 */
   PE_NO_LABEL == 205 ? pass_() : fail_();
#else				/* PE_NO_LABEL */
   fail_ ();
#endif				/* PE_NO_LABEL */
   setmsg_ ("1 3", "PE_NO_LABELS should be defined as  206.", 3L, 39L);
#ifdef PE_NO_LABELS
/*
 * Ignoring function, one or both of the labels does not exist in the open
 * structure between the element pointer and the end of the structure
 */
   PE_NO_LABELS == 206 ? pass_() : fail_();
#else				/* PE_NO_LABELS */
   fail_ ();
#endif				/* PE_NO_LABELS */
   setmsg_ ("1 3", "PE_BAD_PATH_DEPTH should be defined as  207.", 3L, 44L);
#ifdef PE_BAD_PATH_DEPTH
/*
 * Ignoring function, the specified path depth is less than zero (0 )
 */
   PE_BAD_PATH_DEPTH == 207 ? pass_() : fail_();
#else				/* PE_BAD_PATH_DEPTH */
   fail_ ();
#endif				/* PE_BAD_PATH_DEPTH */
   setmsg_ ("1 3", "PE_BAD_DISP_PRI should be defined as  208.", 3L, 42L);
#ifdef PE_BAD_DISP_PRI
/*
 * Ignoring function, the display priority is out of range
 */
   PE_BAD_DISP_PRI == 208 ? pass_() : fail_();
#else				/* PE_BAD_DISP_PRI */
   fail_ ();
#endif				/* PE_BAD_DISP_PRI */
/* Input Errors */

   setmsg_ ("1 3", "PE_NO_DEVICE should be defined as  250.", 3L, 39L);
#ifdef PE_NO_DEVICE
/*
 * Ignoring function, the specified device is not available on the specified
 * workstation
 */
   PE_NO_DEVICE == 250 ? pass_() : fail_();
#else				/* PE_NO_DEVICE */
   fail_ ();
#endif				/* PE_NO_DEVICE */
   setmsg_ ("1 3", "PE_NOT_REQUEST should be defined as  251.", 3L, 41L);
#ifdef PE_NOT_REQUEST
/*
 * Ignoring function, the function requires the input device to be in REQUEST
 * mode
 */
   PE_NOT_REQUEST == 251 ? pass_() : fail_();
#else				/* PE_NOT_REQUEST */
   fail_ ();
#endif				/* PE_NOT_REQUEST */
   setmsg_ ("1 3", "PE_NOT_SAMPLE should be defined as  252.", 3L, 40L);
#ifdef PE_NOT_SAMPLE
/*
 * Ignoring function, the function requires the input device to be in SAMPLE
 * Mode
 */
   PE_NOT_SAMPLE == 252 ? pass_() : fail_();
#else				/* PE_NOT_SAMPLE */
   fail_ ();
#endif				/* PE_NOT_SAMPLE */
   setmsg_ ("1 3", "PE_BAD_PET should be defined as  253.", 3L, 37L);
#ifdef PE_BAD_PET
/*
 * Warning, the specified prompt/echo type is not available on the specified
 * workstation.  Prompt/echo type one will be used in its place
 */
   PE_BAD_PET == 253 ? pass_() : fail_();
#else				/* PE_BAD_PET */
   fail_ ();
#endif				/* PE_BAD_PET */
   setmsg_ ("1 3", "PE_INVALID_ECHO should be defined as  254.", 3L, 42L);
#ifdef PE_INVALID_ECHO
/*
 * Ignoring function, invalid echo area/volume; XMIN >= XMAX, YMIN >= YMAX,
 * or ZMIN > ZMAX
 */
   PE_INVALID_ECHO == 254 ? pass_() : fail_();
#else				/* PE_INVALID_ECHO */
   fail_ ();
#endif				/* PE_INVALID_ECHO */
   setmsg_ ("1 3", "PE_BAD_ECHO should be defined as  255.", 3L, 38L);
#ifdef PE_BAD_ECHO
/*
 * Ignoring function, one of the echo area/volume boundary points is outside
 * the range of the device
 */
   PE_BAD_ECHO == 255 ? pass_() : fail_();
#else				/* PE_BAD_ECHO */
   fail_ ();
#endif				/* PE_BAD_ECHO */
   setmsg_ ("1 3", "PE_QUEUE_OFLOW should be defined as  256.", 3L, 41L);
#ifdef PE_QUEUE_OFLOW
/* Warning, the input queue has overflowed */
   PE_QUEUE_OFLOW == 256 ? pass_() : fail_();
#else				/* PE_QUEUE_OFLOW */
   fail_ ();
#endif				/* PE_QUEUE_OFLOW */
   setmsg_ ("1 3", "PE_NO_QUEUE_OFLOW should be defined as  257.", 3L, 44L);
#ifdef PE_NO_QUEUE_OFLOW
/*
 * Ignoring function, input queue has not overflowed
 */
   PE_NO_QUEUE_OFLOW == 257 ? pass_() : fail_();
#else				/* PE_NO_QUEUE_OFLOW */
   fail_ ();
#endif				/* PE_NO_QUEUE_OFLOW */
   setmsg_ ("1 3", "PE_OFLOW_NO_GO should be defined as  258.", 3L, 41L);
#ifdef PE_OFLOW_NO_GO
/*
 * Warning, input queue has overflowed, but associated workstation has been
 * closed
 */
   PE_OFLOW_NO_GO == 258 ? pass_() : fail_();
#else				/* PE_OFLOW_NO_GO */
   fail_ ();
#endif				/* PE_OFLOW_NO_GO */
   setmsg_ ("1 3", "PE_BAD_CLASS should be defined as  259.", 3L, 39L);
#ifdef PE_BAD_CLASS
/*
 * Ignoring function, the input device class of the current input report does
 * not match the class being requested
 */
   PE_BAD_CLASS == 259 ? pass_() : fail_();
#else				/* PE_BAD_CLASS */
   fail_ ();
#endif				/* PE_BAD_CLASS */
   setmsg_ ("1 3", "PE_BAD_DATA_REC should be defined as  260.", 3L, 42L);
#ifdef PE_BAD_DATA_REC
/*
 * Ignoring function, one of the fields within the input device data record
 * is in error
 */
   PE_BAD_DATA_REC == 260 ? pass_() : fail_();
#else				/* PE_BAD_DATA_REC */
   fail_ ();
#endif				/* PE_BAD_DATA_REC */
   setmsg_ ("1 3", "PE_INVALID_VALUE should be defined as  261.", 3L, 43L);
#ifdef PE_INVALID_VALUE
/*
 * Ignoring function, initial value is invalid
 */
   PE_INVALID_VALUE == 261 ? pass_() : fail_();
#else				/* PE_INVALID_VALUE */
   fail_ ();
#endif				/* PE_INVALID_VALUE */
   setmsg_ ("1 3", "PE_STROKE_BUF_SIZE should be defined as  262.", 3L, 45L);
#ifdef PE_STROKE_BUF_SIZE
/*
 * Ignoring function, number of points in the initial stroke is greater than
 * the buffer size
 */
   PE_STROKE_BUF_SIZE == 262 ? pass_() : fail_();
#else				/* PE_STROKE_BUF_SIZE */
   fail_ ();
#endif				/* PE_STROKE_BUF_SIZE */
   setmsg_ ("1 3", "PE_STRING_BUF_SIZE should be defined as  263.", 3L, 45L);
#ifdef PE_STRING_BUF_SIZE
/*
 * Ignoring function, length of the initial string is greater than the buffer
 * size
 */
   PE_STRING_BUF_SIZE == 263 ? pass_() : fail_();
#else				/* PE_STRING_BUF_SIZE */
   fail_ ();
#endif				/* PE_STRING_BUF_SIZE */
/* Metafile Errors  */

   setmsg_ ("1 3", "PE_ILLEGAL_ITEM_TYPE should be defined as  300.", 3L, 47L);
#ifdef PE_ILLEGAL_ITEM_TYPE
/*
 * Ignoring function, item type is not allowed for user items
 */
   PE_ILLEGAL_ITEM_TYPE == 300 ? pass_() : fail_();
#else				/* PE_ILLEGAL_ITEM_TYPE */
   fail_ ();
#endif				/* PE_ILLEGAL_ITEM_TYPE */
   setmsg_ ("1 3", "PE_INVALID_ITEM_LENGTH should be defined as  301.", 3L, 49L);
#ifdef PE_INVALID_ITEM_LENGTH
/* Ignoring function, item length is invalid */
   PE_INVALID_ITEM_LENGTH == 301 ? pass_() : fail_();
#else				/* PE_INVALID_ITEM_LENGTH */
   fail_ ();
#endif				/* PE_INVALID_ITEM_LENGTH */
   setmsg_ ("1 3", "PE_METAFILE_EMPTY should be defined as  302.", 3L, 44L);
#ifdef PE_METAFILE_EMPTY
/*
 * Ignoring function, no item is left in metafile input
 */
   PE_METAFILE_EMPTY == 302 ? pass_() : fail_();
#else				/* PE_METAFILE_EMPTY */
   fail_ ();
#endif				/* PE_METAFILE_EMPTY */
   setmsg_ ("1 3", "PE_INVALID_ITEM should be defined as  303.", 3L, 42L);
#ifdef PE_INVALID_ITEM
/*
 * Ignoring function, metafile item is invalid
 */
   PE_INVALID_ITEM == 303 ? pass_() : fail_();
#else				/* PE_INVALID_ITEM */
   fail_ ();
#endif				/* PE_INVALID_ITEM */
   setmsg_ ("1 3", "PE_BAD_ITEM_TYPE should be defined as  304.", 3L, 43L);
#ifdef PE_BAD_ITEM_TYPE
/* Ignoring function, item type is unknown */
   PE_BAD_ITEM_TYPE == 304 ? pass_() : fail_();
#else				/* PE_BAD_ITEM_TYPE */
   fail_ ();
#endif				/* PE_BAD_ITEM_TYPE */
   setmsg_ ("1 3", "PE_BAD_ITEM_REC should be defined as  305.", 3L, 42L);
#ifdef PE_BAD_ITEM_REC
/*
 * Ignoring function, content of item data record is invalid for the
 * specified item type
 */
   PE_BAD_ITEM_REC == 305 ? pass_() : fail_();
#else				/* PE_BAD_ITEM_REC */
   fail_ ();
#endif				/* PE_BAD_ITEM_REC */
   setmsg_ ("1 3", "PE_MAX_ITEM_LENGTH should be defined as  306.", 3L, 45L);
#ifdef PE_MAX_ITEM_LENGTH
/*
 * Ignoring function, maximum item data record length is invalid
 */
   PE_MAX_ITEM_LENGTH == 306 ? pass_() : fail_();
#else				/* PE_MAX_ITEM_LENGTH */
   fail_ ();
#endif				/* PE_MAX_ITEM_LENGTH */
   setmsg_ ("1 3", "PE_USER_ITEM should be defined as  307.", 3L, 39L);
#ifdef PE_USER_ITEM
/*
 * Ignoring function, user item cannot be interpreted
 */
   PE_USER_ITEM == 307 ? pass_() : fail_();
#else				/* PE_USER_ITEM */
   fail_ ();
#endif				/* PE_USER_ITEM */
/* Escape Errors  */

   setmsg_ ("1 3", "PE_ESCAPE_NOT_AVAIL should be defined as  350.", 3L, 46L);
#ifdef PE_ESCAPE_NOT_AVAIL
/*
 * Warning, the specified escape is not available on one or more workstations
 * in this implementation.  The escape will be processed by those
 * workstations on which it is available
 */
   PE_ESCAPE_NOT_AVAIL == 350 ? pass_() : fail_();
#else				/* PE_ESCAPE_NOT_AVAIL */
   fail_ ();
#endif				/* PE_ESCAPE_NOT_AVAIL */
   setmsg_ ("1 3", "PE_BAD_ESCAPE_DATA should be defined as  351.", 3L, 45L);
#ifdef PE_BAD_ESCAPE_DATA
/*
 * Ignoring function, one of the fields within the escape data record is in
 * error
 */
   PE_BAD_ESCAPE_DATA == 351 ? pass_() : fail_();
#else				/* PE_BAD_ESCAPE_DATA */
   fail_ ();
#endif				/* PE_BAD_ESCAPE_DATA */
/* Archival and Retrieval  Errors  */

   setmsg_ ("1 3", "PE_AR_CANT_OPEN should be defined as  400.", 3L, 42L);
#ifdef PE_AR_CANT_OPEN
/*
 * Ignoring function, the archive file cannot be opened
 */
   PE_AR_CANT_OPEN == 400 ? pass_() : fail_();
#else				/* PE_AR_CANT_OPEN */
   fail_ ();
#endif				/* PE_AR_CANT_OPEN */
   setmsg_ ("1 3", "PE_MAX_AR should be defined as  401.", 3L, 36L);
#ifdef PE_MAX_AR
/*
 * Ignoring function, opening this archive file would exceed the maximum
 * number of simultaneously open archive files
 */
   PE_MAX_AR == 401 ? pass_() : fail_();
#else				/* PE_MAX_AR */
   fail_ ();
#endif				/* PE_MAX_AR */
   setmsg_ ("1 3", "PE_DUP_AR_ID should be defined as  402.", 3L, 39L);
#ifdef PE_DUP_AR_ID
/*
 * Ignoring function, archive file identifier already in use
 */
   PE_DUP_AR_ID == 402 ? pass_() : fail_();
#else				/* PE_DUP_AR_ID */
   fail_ ();
#endif				/* PE_DUP_AR_ID */
   setmsg_ ("1 3", "PE_BAD_AR should be defined as  403.", 3L, 36L);
#ifdef PE_BAD_AR
/*
 * Ignoring function, the archive file is not a PHIGS archive file
 */
   PE_BAD_AR == 403 ? pass_() : fail_();
#else				/* PE_BAD_AR */
   fail_ ();
#endif				/* PE_BAD_AR */
   setmsg_ ("1 3", "PE_AR_NOT_OPEN should be defined as  404.", 3L, 41L);
#ifdef PE_AR_NOT_OPEN
/*
 * Ignoring function, the specified archive file is not open
 */
   PE_AR_NOT_OPEN == 404 ? pass_() : fail_();
#else				/* PE_AR_NOT_OPEN */
   fail_ ();
#endif				/* PE_AR_NOT_OPEN */
   setmsg_ ("1 3", "PE_NAME_CONFLICT should be defined as  405.", 3L, 43L);
#ifdef PE_NAME_CONFLICT
/*
 * Ignoring function, name conflict occured while conflict resolution flag
 * has value ABANDON
 */
   PE_NAME_CONFLICT == 405 ? pass_() : fail_();
#else				/* PE_NAME_CONFLICT */
   fail_ ();
#endif				/* PE_NAME_CONFLICT */
   setmsg_ ("1 3", "PE_AR_FULL should be defined as  406.", 3L, 37L);
#ifdef PE_AR_FULL
/*
 * Warning, the archive file is full.  Any structures that were archived were
 * archived in total
 */
   PE_AR_FULL == 406 ? pass_() : fail_();
#else				/* PE_AR_FULL */
   fail_ ();
#endif				/* PE_AR_FULL */
   setmsg_ ("1 3", "PE_AR_NO_STRUCT should be defined as  407.", 3L, 42L);
#ifdef PE_AR_NO_STRUCT
/*
 * Warning, some of the specified structures do not exist on the archive file
 */
   PE_AR_NO_STRUCT == 407 ? pass_() : fail_();
#else				/* PE_AR_NO_STRUCT */
   fail_ ();
#endif				/* PE_AR_NO_STRUCT */
   setmsg_ ("1 3", "PE_AR_NO_STRUCT_EMPTY should be defined as  408.", 3L, 48L);
#ifdef PE_AR_NO_STRUCT_EMPTY
/*
 * Warning, some of the specified structures do not exist on the archive
 * file.  PHIGS will create empty structures in their places
 */
   PE_AR_NO_STRUCT_EMPTY == 408 ? pass_() : fail_();
#else				/* PE_AR_NO_STRUCT_EMPTY */
   fail_ ();
#endif				/* PE_AR_NO_STRUCT_EMPTY */
/* Miscellaneous Errors */

   setmsg_ ("1 3", "PE_BAD_ERROR_FILE should be defined as  450.", 3L, 44L);
#ifdef PE_BAD_ERROR_FILE
/*
 * Ignoring function, the specified error file is invalid
 */
   PE_BAD_ERROR_FILE == 450 ? pass_() : fail_();
#else				/* PE_BAD_ERROR_FILE */
   fail_ ();
#endif				/* PE_BAD_ERROR_FILE */
/* System Errors */

   setmsg_ ("1 3", "PE_OFLOW_PHIGS should be defined as  900.", 3L, 42L);
#ifdef PE_OFLOW_PHIGS
/* Storage overflow has occurred in PHIGS */
   PE_OFLOW_PHIGS == 900 ? pass_() : fail_();
#else				/* PE_OFLOW_PHIGS */
   fail_ ();
#endif				/* PE_OFLOW_PHIGS */
   setmsg_ ("1 3", "PE_OFLOW_CSS should be defined as  901.", 3L, 39L);
#ifdef PE_OFLOW_CSS
/* Storage overflow has occurred in CSS */
   PE_OFLOW_CSS == 901 ? pass_() : fail_();
#else				/* PE_OFLOW_CSS */
   fail_ ();
#endif				/* PE_OFLOW_CSS */
   setmsg_ ("1 3", "PE_IO_ERROR_READ should be defined as  902.", 3L, 43L);
#ifdef PE_IO_ERROR_READ
/*
 * Input/Output error has occurred while reading
 */
   PE_IO_ERROR_READ == 902 ? pass_() : fail_();
#else				/* PE_IO_ERROR_READ */
   fail_ ();
#endif				/* PE_IO_ERROR_READ */
   setmsg_ ("1 3", "PE_IO_ERROR_WRITE should be defined as  903.", 3L, 44L);
#ifdef PE_IO_ERROR_WRITE
/*
 * Input/Output error has occurred while writing
 */
   PE_IO_ERROR_WRITE == 903 ? pass_() : fail_();
#else				/* PE_IO_ERROR_WRITE */
   fail_ ();
#endif				/* PE_IO_ERROR_WRITE */
   setmsg_ ("1 3", "PE_IO_ERROR_TO_WS should be defined as  904.", 3L, 44L);
#ifdef PE_IO_ERROR_TO_WS
/*
 * Input/Output error has occurred while sending data to a workstation
 */
   PE_IO_ERROR_TO_WS == 904 ? pass_() : fail_();
#else				/* PE_IO_ERROR_TO_WS */
   fail_ ();
#endif				/* PE_IO_ERROR_TO_WS */
   setmsg_ ("1 3", "PE_IO_ERROR_FROM_WS should be defined as  905.", 3L, 46L);
#ifdef PE_IO_ERROR_FROM_WS
/*
 * Input/Output error has occurred while receiving data from a workstation
 */
   PE_IO_ERROR_FROM_WS == 905 ? pass_() : fail_();
#else				/* PE_IO_ERROR_FROM_WS */
   fail_ ();
#endif				/* PE_IO_ERROR_FROM_WS */
   setmsg_ ("1 3", "PE_IO_ERROR_LIB should be defined as  906.", 3L, 42L);
#ifdef PE_IO_ERROR_LIB
/*
 * Input/Output error has occurred during program library management
 */
   PE_IO_ERROR_LIB == 906 ? pass_() : fail_();
#else				/* PE_IO_ERROR_LIB */
   fail_ ();
#endif				/* PE_IO_ERROR_LIB */
   setmsg_ ("1 3", "PE_IO_ERROR_WDT should be defined as  907.", 3L, 42L);
#ifdef PE_IO_ERROR_WDT
/*
 * Input/Output error has occurred while reading workstation description
 * table
 */
   PE_IO_ERROR_WDT == 907 ? pass_() : fail_();
#else				/* PE_IO_ERROR_WDT */
   fail_ ();
#endif				/* PE_IO_ERROR_WDT */
   setmsg_ ("1 3", "PE_ARITHMETIC_ERROR should be defined as  908.", 3L, 46L);
#ifdef PE_ARITHMETIC_ERROR
/* Arithmetic error has occurred */
   PE_ARITHMETIC_ERROR == 908 ? pass_() : fail_();
#else				/* PE_ARITHMETIC_ERROR */
   fail_ ();
#endif				/* PE_ARITHMETIC_ERROR */
/* C Binding specific errors */

   setmsg_ ("1 3", "PE_START_IND_INVAL should be defined as  2200.", 3L, 46L);
#ifdef PE_START_IND_INVAL
/* Start index out of range */
   PE_START_IND_INVAL == 2200 ? pass_() : fail_();
#else				/* PE_START_IND_INVAL */
   fail_ ();
#endif				/* PE_START_IND_INVAL */
   setmsg_ ("1 3", "PE_LIST_LENGTH_LT_ZERO should be defined as  2201.", 3L, 50);
#ifdef PE_LIST_LENGTH_LT_ZERO
/*
 * The length of the application's list is negative
 */
   PE_LIST_LENGTH_LT_ZERO == 2201 ? pass_() : fail_();
#else				/* PE_LIST_LENGTH_LT_ZERO */
   fail_ ();
#endif				/* PE_LIST_LENGTH_LT_ZERO */

   setmsg_ ("1 3", "PE_ENUM_TYPE_INVAL should be defined as  2202.", 3L, 46L);
#ifdef PE_ENUM_TYPE_INVAL
/* Enumeration type out of range */
   PE_ENUM_TYPE_INVAL == 2202 ? pass_() : fail_();
#else				/* PE_ENUM_TYPE_INVAL */
   fail_ ();
#endif				/* PE_ENUM_TYPE_INVAL */
   setmsg_ ("1 3", "PE_ALLOC_STORE should be defined as  2203.", 3L, 42L);
#ifdef PE_ALLOC_STORE
/*
 * Ignoring function, error while allocating store
 */
   PE_ALLOC_STORE == 2203 ? pass_() : fail_();
#else				/* PE_ALLOC_STORE */
   fail_ ();
#endif				/* PE_ALLOC_STORE */
   setmsg_ ("1 3", "PE_ALLOC_STORE_MEM should be defined as  2204.", 3L, 46L);
#ifdef PE_ALLOC_STORE_MEM
/*
 * Ignoring function, error while allocating memory for store
 */
   PE_ALLOC_STORE_MEM == 2204 ? pass_() : fail_();
#else				/* PE_ALLOC_STORE_MEM */
   fail_ ();
#endif				/* PE_ALLOC_STORE_MEM */
}



misc_check ()
{
/* 6.3 Miscellaneous defines */

/* 6.3.1 Line types */

   setmsg_ ("1 4", "PLINE_SOLID should be defined as  1.", 3L, 36L);
#ifdef PLINE_SOLID
   PLINE_SOLID == 1 ? pass_() : fail_();
#else				/* PLINE_SOLID */
   fail_ ();
#endif				/* PLINE_SOLID */
   setmsg_ ("1 4", "PLINE_DASH should be defined as  2.", 3L, 35L);
#ifdef PLINE_DASH
   PLINE_DASH == 2 ? pass_() : fail_();
#else				/* PLINE_DASH */
   fail_ ();
#endif				/* PLINE_DASH */
   setmsg_ ("1 4", "PLINE_DOT should be defined as  3.", 3L, 34L);
#ifdef PLINE_DOT
   PLINE_DOT == 3 ? pass_() : fail_();
#else				/* PLINE_DOT */
   fail_ ();
#endif				/* PLINE_DOT */
   setmsg_ ("1 4", "PLINE_DASH_DOT should be defined as  4.", 3L, 39L);
#ifdef PLINE_DASH_DOT
   PLINE_DASH_DOT == 4 ? pass_() : fail_();
#else				/* PLINE_DASH_DOT */
   fail_ ();
#endif				/* PLINE_DASH_DOT */
/* 6.3.2 Marker types */

   setmsg_ ("1 5", "PMARKER_DOT should be defined as  1.", 3L, 36L);
#ifdef PMARKER_DOT
   PMARKER_DOT == 1 ? pass_() : fail_();
#else				/* PMARKER_DOT */
   fail_ ();
#endif				/* PMARKER_DOT */
   setmsg_ ("1 5", "PMARKER_PLUS should be defined as  2.", 3L, 37L);
#ifdef PMARKER_PLUS
   PMARKER_PLUS == 2 ? pass_() : fail_();
#else				/* PMARKER_PLUS */
   fail_ ();
#endif				/* PMARKER_PLUS */
   setmsg_ ("1 5", "PMARKER_ASTERISK should be defined as  3.", 3L, 41L);
#ifdef PMARKER_ASTERISK
   PMARKER_ASTERISK == 3 ? pass_() : fail_();
#else				/* PMARKER_ASTERISK */
   fail_ ();
#endif				/* PMARKER_ASTERISK */
   setmsg_ ("1 5", "PMARKER_CIRCLE should be defined as  4.", 3L, 39L);
#ifdef PMARKER_CIRCLE
   PMARKER_CIRCLE == 4 ? pass_() : fail_();
#else				/* PMARKER_CIRCLE */
   fail_ ();
#endif				/* PMARKER_CIRCLE */
   setmsg_ ("1 5", "PMARKER_CROSS should be defined as  5.", 3L, 38L);
#ifdef PMARKER_CROSS
   PMARKER_CROSS == 5 ? pass_() : fail_();
#else				/* PMARKER_CROSS */
   fail_ ();
#endif				/* PMARKER_CROSS */
/* 6.3.3 Annotation styles */

   setmsg_ ("1 6", "PANNO_STYLE_UNCONNECTED should be defined as  1.", 3L, 48L);
#ifdef PANNO_STYLE_UNCONNECTED
   PANNO_STYLE_UNCONNECTED == 1 ? pass_() : fail_();
#else				/* PANNO_STYLE_UNCONNECTED */
   fail_ ();
#endif				/* PANNO_STYLE_UNCONNECTED */
   setmsg_ ("1 6", "PANNO_STYLE_LEAD_LINE should be defined as  2.", 3L, 46L);
#ifdef PANNO_STYLE_LEAD_LINE
   PANNO_STYLE_LEAD_LINE == 2 ? pass_() : fail_();
#else				/* PANNO_STYLE_LEAD_LINE */
   fail_ ();
#endif				/* PANNO_STYLE_LEAD_LINE */
/* 6.3.4 Colour models */

   setmsg_ ("1 7", "PMODEL_RGB should be defined as  1.", 3L, 35L);
#ifdef PMODEL_RGB
   PMODEL_RGB == 1 ? pass_() : fail_();
#else				/* PMODEL_RGB */
   fail_ ();
#endif				/* PMODEL_RGB */
   setmsg_ ("1 7", "PMODEL_CIELUV should be defined as  2.", 3L, 38L);
#ifdef PMODEL_CIELUV
   PMODEL_CIELUV == 2 ? pass_() : fail_();
#else				/* PMODEL_CIELUV */
   fail_ ();
#endif				/* PMODEL_CIELUV */
   setmsg_ ("1 7", "PMODEL_HSV should be defined as  3.", 3L, 35L);
#ifdef PMODEL_HSV
   PMODEL_HSV == 3 ? pass_() : fail_();
#else				/* PMODEL_HSV */
   fail_ ();
#endif				/* PMODEL_HSV */
   setmsg_ ("1 7", "PMODEL_HLS should be defined as  4.", 3L, 35L);
#ifdef PMODEL_HLS
   PMODEL_HLS == 4 ? pass_() : fail_();
#else				/* PMODEL_HLS */
   fail_ ();
#endif				/* PMODEL_HLS */
/* 6.3.5 Prompt and Echo types */

   setmsg_ ("1 8", "PLOC_DEF should be defined as  1.", 3L, 33L);
#ifdef PLOC_DEF
   PLOC_DEF == 1 ? pass_() : fail_();
#else				/* PLOC_DEF */
   fail_ ();
#endif				/* PLOC_DEF */
   setmsg_ ("1 8", "PLOC_CROSS_HAIR should be defined as  2.", 3L, 40L);
#ifdef PLOC_CROSS_HAIR
   PLOC_CROSS_HAIR == 2 ? pass_() : fail_();
#else				/* PLOC_CROSS_HAIR */
   fail_ ();
#endif				/* PLOC_CROSS_HAIR */
   setmsg_ ("1 8", "PLOC_TRACK_CROSS should be defined as  3.", 3L, 41L);
#ifdef PLOC_TRACK_CROSS
   PLOC_TRACK_CROSS == 3 ? pass_() : fail_();
#else				/* PLOC_TRACK_CROSS */
   fail_ ();
#endif				/* PLOC_TRACK_CROSS */
   setmsg_ ("1 8", "PLOC_RUB_BAND should be defined as  4.", 3L, 38L);
#ifdef PLOC_RUB_BAND
   PLOC_RUB_BAND == 4 ? pass_() : fail_();
#else				/* PLOC_RUB_BAND */
   fail_ ();
#endif				/* PLOC_RUB_BAND */
   setmsg_ ("1 8", "PLOC_RECT should be defined as  5.", 3L, 34L);
#ifdef PLOC_RECT
   PLOC_RECT == 5 ? pass_() : fail_();
#else				/* PLOC_RECT */
   fail_ ();
#endif				/* PLOC_RECT */
   setmsg_ ("1 8", "PLOC_DIGIT should be defined as  6.", 3L, 35L);
#ifdef PLOC_DIGIT
   PLOC_DIGIT == 6 ? pass_() : fail_();
#else				/* PLOC_DIGIT */
   fail_ ();
#endif				/* PLOC_DIGIT */
   setmsg_ ("1 8", "PSTROKE_DEF should be defined as  1.", 3L, 36L);
#ifdef PSTROKE_DEF
   PSTROKE_DEF == 1 ? pass_() : fail_();
#else				/* PSTROKE_DEF */
   fail_ ();
#endif				/* PSTROKE_DEF */
   setmsg_ ("1 8", "PSTROKE_DIGIT should be defined as  2.", 3L, 38L);
#ifdef PSTROKE_DIGIT
   PSTROKE_DIGIT == 2 ? pass_() : fail_();
#else				/* PSTROKE_DIGIT */
   fail_ ();
#endif				/* PSTROKE_DIGIT */
   setmsg_ ("1 8", "PSTROKE_MARKER should be defined as  3.", 3L, 39L);
#ifdef PSTROKE_MARKER
   PSTROKE_MARKER == 3 ? pass_() : fail_();
#else				/* PSTROKE_MARKER */
   fail_ ();
#endif				/* PSTROKE_MARKER */
   setmsg_ ("1 8", "PSTROKE_LINE should be defined as  4.", 3L, 37L);
#ifdef PSTROKE_LINE
   PSTROKE_LINE == 4 ? pass_() : fail_();
#else				/* PSTROKE_LINE */
   fail_ ();
#endif				/* PSTROKE_LINE */
   setmsg_ ("1 8", "PVAL_DEF should be defined as  1.", 3L, 33L);
#ifdef PVAL_DEF
   PVAL_DEF == 1 ? pass_() : fail_();
#else				/* PVAL_DEF */
   fail_ ();
#endif				/* PVAL_DEF */
   setmsg_ ("1 8", "PVAL_GRAPH should be defined as  2.", 3L, 35L);
#ifdef PVAL_GRAPH
   PVAL_GRAPH == 2 ? pass_() : fail_();
#else				/* PVAL_GRAPH */
   fail_ ();
#endif				/* PVAL_GRAPH */
   setmsg_ ("1 8", "PVAL_DIGIT should be defined as  3.", 3L, 35L);
#ifdef PVAL_DIGIT
   PVAL_DIGIT == 3 ? pass_() : fail_();
#else				/* PVAL_DIGIT */
   fail_ ();
#endif				/* PVAL_DIGIT */
   setmsg_ ("1 8", "PCHOICE_DEF should be defined as  1.", 3L, 36L);
#ifdef PCHOICE_DEF
   PCHOICE_DEF == 1 ? pass_() : fail_();
#else				/* PCHOICE_DEF */
   fail_ ();
#endif				/* PCHOICE_DEF */
   setmsg_ ("1 8", "PCHOICE_PR_ECHO should be defined as  2.", 3L, 40L);
#ifdef PCHOICE_PR_ECHO
   PCHOICE_PR_ECHO == 2 ? pass_() : fail_();
#else				/* PCHOICE_PR_ECHO */
   fail_ ();
#endif				/* PCHOICE_PR_ECHO */
   setmsg_ ("1 8", "PCHOICE_STRING_PR should be defined as  3.", 3L, 42L);
#ifdef PCHOICE_STRING_PR
   PCHOICE_STRING_PR == 3 ? pass_() : fail_();
#else				/* PCHOICE_STRING_PR */
   fail_ ();
#endif				/* PCHOICE_STRING_PR */
   setmsg_ ("1 8", "PCHOICE_STRING_IN should be defined as  4.", 3L, 42L);
#ifdef PCHOICE_STRING_IN
   PCHOICE_STRING_IN == 4 ? pass_() : fail_();
#else				/* PCHOICE_STRING_IN */
   fail_ ();
#endif				/* PCHOICE_STRING_IN */
   setmsg_ ("1 8", "PCHOICE_STRUCT should be defined as  5.", 3L, 39L);
#ifdef PCHOICE_STRUCT
   PCHOICE_STRUCT == 5 ? pass_() : fail_();
#else				/* PCHOICE_STRUCT */
   fail_ ();
#endif				/* PCHOICE_STRUCT */
   setmsg_ ("1 8", "PPICK_DEF should be defined as  1.", 3L, 34L);
#ifdef PPICK_DEF
   PPICK_DEF == 1 ? pass_() : fail_();
#else				/* PPICK_DEF */
   fail_ ();
#endif				/* PPICK_DEF */
   setmsg_ ("1 8", "PPICK_GROUP_HIGHL should be defined as  2.", 3L, 42L);
#ifdef PPICK_GROUP_HIGHL
   PPICK_GROUP_HIGHL == 2 ? pass_() : fail_();
#else				/* PPICK_GROUP_HIGHL */
   fail_ ();
#endif				/* PPICK_GROUP_HIGHL */
   setmsg_ ("1 8", "PPICK_STRUCT_NETWORK should be defined as  3.", 3L, 45L);
#ifdef PPICK_STRUCT_NETWORK
   PPICK_STRUCT_NETWORK == 3 ? pass_() : fail_();
#else				/* PPICK_STRUCT_NETWORK */
   fail_ ();
#endif				/* PPICK_STRUCT_NETWORK */
   setmsg_ ("1 8", "PSTRING_DEF should be defined as  1.", 3L, 36L);
#ifdef PSTRING_DEF
   PSTRING_DEF == 1 ? pass_() : fail_();
#else				/* PSTRING_DEF */
   fail_ ();
#endif				/* PSTRING_DEF */


/* 6.3.6 Default parameters of OPEN PHIGS */

   setmsg_ ("1 9", "PDEF_MEM_SIZE should be defined as ((size_t) (-1)).", 3L, 53L);
#ifdef PDEF_MEM_SIZE
   PDEF_MEM_SIZE == ((size_t) (-1)) ? pass_ () : fail_ ();
#else				/* PDEF_MEM_SIZE */
   fail_ ();
#endif				/* PDEF_MEM_SIZE */
   setmsg_ ("1 9", "PDEF_ERR_FILE should be defined as  ((char *) (0)).", 3L, 51L);
#ifdef PDEF_ERR_FILE
   PDEF_ERR_FILE == ((char *) (0)) ? pass_ () : fail_ ();
#else				/* PDEF_ERR_FILE */
   fail_ ();
#endif				/* PDEF_ERR_FILE */


/* 6.3.7 Element Enumeration */

   setmsg_ ("1 10", "PFIRST_PHIGS_ELEM should be defined as  PELEM_POLYLINE3.", 4L, 58L);
#ifdef PFIRST_PHIGS_ELEM
   PFIRST_PHIGS_ELEM == PELEM_POLYLINE3 ? pass_ () : fail_ ();
#else				/* PFIRST_PHIGS_ELEM */
   fail_ ();
#endif				/* PFIRST_PHIGS_ELEM */
   setmsg_ ("1 10", "PLAST_PHIGS_ELEM should be defined as  PELEM_PICK_ID.", 4L, 53L);
#ifdef PLAST_PHIGS_ELEM
   PLAST_PHIGS_ELEM == PELEM_PICK_ID ? pass_ () : fail_ ();
#else				/* PLAST_PHIGS_ELEM */
   fail_ ();
#endif				/* PLAST_PHIGS_ELEM */
}

