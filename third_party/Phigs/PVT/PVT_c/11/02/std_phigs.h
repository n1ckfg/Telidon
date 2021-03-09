/*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

This file contains declarations for all and only standard PHIGS/C
typedefs and functions, formatted for human reading.  It should
match the standard word-for-word, except for comments.

 *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

                   begin standard typedefs

 *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***/

typedef {IMPL-DEP} Pfloat;

typedef {IMPL-DEP} Pint;

typedef Pfloat Pmatrix3[4][4];

typedef Pfloat Pmatrix[3][3];

typedef void *Pstore;

typedef enum {
    PWS_INDEP,
    PWS_DEP
} Pws_dep_ind;

typedef enum {
    PSYS_ST_PHCL,
    PSYS_ST_PHOP
} Psys_st;

typedef enum {
    PWS_ST_WSCL,
    PWS_ST_WSOP
} Pws_st;

typedef enum {
    PSTRUCT_ST_STCL,
    PSTRUCT_ST_STOP
} Pstruct_st;

typedef enum {
    PSTRUCT_STATUS_NON_EXISTENT,
    PSTRUCT_STATUS_EMPTY,
    PSTRUCT_STATUS_NOT_EMPTY
} Pstruct_status;

typedef enum {
    PST_ARCL,
    PST_AROP
} Par_st;

typedef enum {
    PCLASS_VEC,
    PCLASS_RASTER,
    PCLASS_OTHER
} Pws_class;

typedef enum {
    PCAT_OUT,
    PCAT_IN,
    PCAT_OUTIN,
    PCAT_MO,
    PCAT_MI
} Pws_cat;

typedef enum {
    PFLAG_COND,
    PFLAG_ALWAYS
} Pctrl_flag;

typedef enum {
    PFLAG_POSTPONE,
    PFLAG_PERFORM
} Pregen_flag;

typedef enum {
    PDEFER_ASAP,
    PDEFER_BNIG,
    PDEFER_BNIL,
    PDEFER_ASTI,
    PDEFER_WAIT
} Pdefer_mode;

typedef enum {
    PMODE_NIVE,
    PMODE_UWOR,
    PMODE_UQUM
} Pmod_mode;

typedef enum {
    PSIMULT_NO_MORE,
    PSIMULT_MORE
} Pmore_simult_events;

typedef enum {
    PNET_CSS,
    PNET_AR
} Pstruct_net_source;

typedef enum {
    PSURF_NOT_EMPTY,
    PSURF_EMPTY
} Pdisp_surf_empty;

typedef enum {
    PVISUAL_ST_CORRECT,
    PVISUAL_ST_DEFER,
    PVISUAL_ST_SIMULATED
} Pvisual_st;

typedef enum {
    PPREC_STRING,
    PPREC_CHAR,
    PPREC_STROKE
} Ptext_prec;

typedef enum {
    PPATH_RIGHT,
    PPATH_LEFT,
    PPATH_UP,
    PPATH_DOWN
} Ptext_path;

typedef enum {
    PHOR_NORM,
    PHOR_LEFT,
    PHOR_CTR,
    PHOR_RIGHT
} Phor_text_align;

typedef enum {
    PVERT_NORM,
    PVERT_TOP,
    PVERT_CAP,
    PVERT_HALF,
    PVERT_BASE,
    PVERT_BOTTOM
} Pvert_text_align;

typedef enum {
    PSTYLE_HOLLOW,
    PSTYLE_SOLID,
    PSTYLE_PAT,
    PSTYLE_HATCH,
    PSTYLE_EMPTY
} Pint_style;

typedef enum {
    PEDGE_OFF,
    PEDGE_ON
} Pedge_flag;

typedef enum {
    PASPECT_LINETYPE,
    PASPECT_LINEWIDTH,
    PASPECT_LINE_COLR_IND,
    PASPECT_MARKER_TYPE,
    PASPECT_MARKER_SIZE,
    PASPECT_MARKER_COLR_IND,
    PASPECT_TEXT_FONT,
    PASPECT_TEXT_PREC,
    PASPECT_CHAR_EXPAN,
    PASPECT_CHAR_SPACE,
    PASPECT_TEXT_COLR_IND,
    PASPECT_INT_STYLE,
    PASPECT_INT_STYLE_IND,
    PASPECT_INT_COLR_IND,
    PASPECT_EDGE_FLAG,
    PASPECT_EDGETYPE,
    PASPECT_EDGEWIDTH,
    PASPECT_EDGE_COLR_IND
} Paspect;

typedef enum {
    PASF_BUNDLED,
    PASF_INDIV
} Pasf;

typedef enum {
    PAVAIL_MONOCHR,
    PAVAIL_COLR
} Pcolr_avail;

typedef enum {
    PTYPE_PRECONCAT,
    PTYPE_POSTCONCAT,
    PTYPE_REPLACE
} Pcompose_type;

typedef enum {
    PTYPE_PARAL,
    PTYPE_PERSPECT
} Pproj_type;

typedef enum {
    PIND_NO_CLIP,
    PIND_CLIP
} Pclip_ind;

typedef enum {
    PPRI_HIGHER,
    PPRI_LOWER
} Prel_pri;

typedef enum {
    PRES_MAINTAIN,
    PRES_ABANDON,
    PRES_UPD
} Pconf_res;

typedef enum {
    PFLAG_LINE,
    PFLAG_FILL,
    PFLAG_FILL_SET
} Pline_fill_ctrl_flag;

typedef enum {
    PORDER_TOP_FIRST,
    PORDER_BOTTOM_FIRST
} Ppath_order;

typedef enum {
    POP_REQ,
    POP_SAMPLE,
    POP_EVENT
} Pop_mode;

typedef enum {
    PSWITCH_NO_ECHO,
    PSWITCH_ECHO
} Pecho_switch;

typedef enum {
    PIN_STATUS_NONE,
    PIN_STATUS_OK,
    PIN_STATUS_NO_IN
} Pin_status;

typedef enum {
    PSTRUCT_NONE,
    PSTRUCT_OPEN
} Popen_struct_status;

typedef enum {
    PIN_NONE,
    PIN_LOC,
    PIN_STROKE,
    PIN_VAL,
    PIN_CHOICE,
    PIN_PICK,
    PIN_STRING
} Pin_class;

typedef enum {
    PPR_OFF,
    PPR_ON
} Ppr_switch;

typedef enum {
    PINQ_SET,
    PINQ_REALIZED
} Pinq_type;

typedef enum {
    PUPD_NOT_PEND,
    PUPD_PEND
} Pupd_st;

typedef enum {
    PDC_METRES,
    PDC_OTHER
} Pdc_units;

typedef enum {
    PDYN_IRG,
    PDYN_IMM,
    PDYN_CBS
} Pdyn_mod;

typedef enum {
    PATTR_LINE,
    PATTR_MARKER,
    PATTR_TEXT,
    PATTR_INT,
    PATTR_EDGE
} Pattrs;

typedef enum {
    PELEM_ALL,
    PELEM_NIL,
    PELEM_POLYLINE3,
    PELEM_POLYLINE,
    PELEM_POLYMARKER3,
    PELEM_POLYMARKER,
    PELEM_TEXT3,
    PELEM_TEXT,
    PELEM_ANNO_TEXT_REL3,
    PELEM_ANNO_TEXT_REL,
    PELEM_FILL_AREA3,
    PELEM_FILL_AREA,
    PELEM_FILL_AREA_SET3,
    PELEM_FILL_AREA_SET,
    PELEM_CELL_ARRAY3,
    PELEM_CELL_ARRAY,
    PELEM_GDP3,
    PELEM_GDP,
    PELEM_LINE_IND,
    PELEM_MARKER_IND,
    PELEM_TEXT_IND,
    PELEM_INT_IND,
    PELEM_EDGE_IND,
    PELEM_LINETYPE,
    PELEM_LINEWIDTH,
    PELEM_LINE_COLR_IND,
    PELEM_MARKER_TYPE,
    PELEM_MARKER_SIZE,
    PELEM_MARKER_COLR_IND,
    PELEM_TEXT_FONT,
    PELEM_TEXT_PREC,
    PELEM_CHAR_EXPAN,
    PELEM_CHAR_SPACE,
    PELEM_TEXT_COLR_IND,
    PELEM_CHAR_HT,
    PELEM_CHAR_UP_VEC,
    PELEM_TEXT_PATH,
    PELEM_TEXT_ALIGN,
    PELEM_ANNO_CHAR_HT,
    PELEM_ANNO_CHAR_UP_VEC,
    PELEM_ANNO_PATH,
    PELEM_ANNO_ALIGN,
    PELEM_ANNO_STYLE,
    PELEM_INT_STYLE,
    PELEM_INT_STYLE_IND,
    PELEM_INT_COLR_IND,
    PELEM_EDGE_FLAG,
    PELEM_EDGETYPE,
    PELEM_EDGEWIDTH,
    PELEM_EDGE_COLR_IND,
    PELEM_PAT_SIZE,
    PELEM_PAT_REF_POINT_VECS,
    PELEM_PAT_REF_POINT,
    PELEM_ADD_NAMES_SET,
    PELEM_REMOVE_NAMES_SET,
    PELEM_INDIV_ASF,
    PELEM_HLHSR_ID,
    PELEM_LOCAL_MODEL_TRAN3,
    PELEM_LOCAL_MODEL_TRAN,
    PELEM_GLOBAL_MODEL_TRAN3,
    PELEM_GLOBAL_MODEL_TRAN,
    PELEM_MODEL_CLIP_VOL3,
    PELEM_MODEL_CLIP_VOL,
    PELEM_MODEL_CLIP_IND,
    PELEM_RESTORE_MODEL_CLIP_VOL,
    PELEM_VIEW_IND,
    PELEM_EXEC_STRUCT,
    PELEM_LABEL,
    PELEM_APPL_DATA,
    PELEM_GSE,
    PELEM_PICK_ID
} Pelem_type;

typedef enum {
    PEDIT_INSERT,
    PEDIT_REPLACE
} Pedit_mode;

typedef enum {
    PFLAG_DEL,
    PFLAG_KEEP
} Pref_flag;

typedef enum {
    PERR_OFF,
    PERR_ON
} Perr_mode;

typedef enum {
    PDIR_BACKWARD,
    PDIR_FORWARD
} Psearch_dir;

typedef enum {
    PSEARCH_STATUS_FAILURE,
    PSEARCH_STATUS_SUCCESS
} Psearch_status;

typedef struct {
    size_t	size;	   /* sizeof data */
    void	*data;	   /* pointer to data */
} Pdata;

typedef struct {
     Pfloat     cieluv_x;      /* x coefficient */
     Pfloat     cieluv_y;      /* y coefficient */
     Pfloat     cieluv_y_lum;  /* y luminance */
} Pcieluv;

typedef struct {
     Pfloat     hue;        /* hue */
     Pfloat     lightness;  /* lightness; */
     Pfloat     satur;      /* saturation */
} Phls;

typedef struct {
     Pfloat     hue;    /* hue */
     Pfloat     satur;  /* saturation */
     Pfloat     value;  /* value */
} Phsv;

typedef struct {
    Pfloat	red;	/* red, hue, etc */
    Pfloat	green;	/* green, saturation, lightness, etc */
    Pfloat	blue;	/* blue, value, saturation, etc */
} Prgb;

typedef union {
     Prgb	rgb;
     Pcieluv	cieluv;
     Phls	hls;
     Phsv	hsv;
     Pdata	unsupp;
     {IMPL-DEP}
} Pcolr_rep;

typedef struct {
    Pint        num_ints; /* number of Pints in list */
    Pint        *ints;    /* list of integers        */
} Pint_list;

typedef struct {
    Pint	id;	/* GSE identifier */
    Pws_dep_ind	ind;	/* WS independent/dependent ind */
} Pgse_id_dep;

typedef struct {
    Pint	num_id_facs;	/* number of identifiers/dependency element */
    Pgse_id_dep	*id_facs;	/* list */
} Pgse_id_dep_list;

typedef struct {
    Pint        id;	/* archive file identifier */
    char       *name;	/* archive file name       */
} Par_file;

typedef struct {
    Pint	num_ar_files;	/* number of archive files */
    Par_file	*ar_files;	/* list of archive files */
} Par_file_list;

typedef struct {
    Pint	struct_id;	/* structure identifier */
    Pint	elem_pos;	/* element number */
} Pelem_ref;

typedef struct {
    Pint	num_elem_refs;	/* number of execute refs */
    Pelem_ref	*elem_refs;	/* list of execute refs */
} Pelem_ref_list;

typedef struct {
    Pint	        num_elem_ref_lists;  /* number of execute refs lists */
    Pelem_ref_list	*elem_ref_lists;     /* list of execute ref lists */
} Pelem_ref_list_list;

typedef struct {
    Pint	id;		/* structure id */
    Pfloat	disp_pri;	/* structure disp_pri */
} Pposted_struct;

typedef struct {
    Pint	    num_postings;	/* number of structure postings */
    Pposted_struct  *postings;  	/* list of postings */
} Pposted_struct_list;

typedef struct {
    Pfloat	x;	/* x coordinate */
    Pfloat	y;	/* y coordinate */
} Ppoint;

typedef struct {
    Pfloat	x;	/* x coordinate */
    Pfloat	y;	/* y coordinate */
    Pfloat	z;	/* z coordinate */
} Ppoint3;

typedef struct {
    Pfloat	delta_x;	/* x magnitude */
    Pfloat	delta_y;	/* y magnitude */
} Pvec;

typedef struct {
    Pfloat	delta_x;	/* x magnitude */
    Pfloat	delta_y;	/* y magnitude */
    Pfloat	delta_z;	/* z magnitude */
} Pvec3;

typedef struct {
    Pint	size_x;
    Pint	size_y;
} Pint_size;

typedef struct {
    Pint	size_x;
    Pint	size_y;
    Pint	size_z;
} Pint_size3;

typedef struct {
    Pfloat	size_x;
    Pfloat	size_y;
} Pfloat_size;

typedef struct {
    Pfloat	size_x;
    Pfloat	size_y;
    Pfloat	size_z;
} Pfloat_size3;

typedef struct {
    Ppoint	point;	/* point */
    Pvec	norm;	/* normal */
} Phalf_space;

typedef struct {
    Ppoint3	point;	/* point */
    Pvec3	norm;	/* normal */
} Phalf_space3;

typedef struct {
    Ppoint	p;	/* lower left */
    Ppoint	q;	/* upper right */
} Prect;

typedef struct {
    Ppoint3	p;	/* point p */
    Ppoint3	q;	/* point q */
    Ppoint3	r;	/* point r */
} Pparal;

typedef struct {
    Pfloat	x_min;	/* x min */
    Pfloat	x_max;	/* x max */
    Pfloat	y_min;	/* y min */
    Pfloat	y_max;	/* y max */
    Pfloat	z_min;	/* z min */
    Pfloat	z_max;	/* z max */
} Plimit3;

typedef struct {
    Pfloat	x_min;	/* x min */
    Pfloat	x_max;	/* x max */
    Pfloat	y_min;	/* y min */
    Pfloat	y_max;	/* y max */
} Plimit;

typedef struct {
    Pint	num_points;	/* number of Ppoints in the list */
    Ppoint	*points;	/* list of points */
} Ppoint_list;

typedef struct {
    Pint	num_points;	/* number of Ppoint3s in the list */
    Ppoint3	*points;	/* list of points */
} Ppoint_list3;

typedef struct {			/* list of 2d point lists */
    Pint	num_point_lists;	/* number of point lists  */
    Ppoint_list	*point_lists;		/* list of point lists	  */
} Ppoint_list_list;

typedef struct {			/* list of 3d point lists */
    Pint	 num_point_lists;	/* number of point lists  */
    Ppoint_list3 *point_lists;		/* list of point lists	  */
} Ppoint_list_list3;

typedef struct {
    Pint	num_half_spaces;   /* number of half spaces */
    Phalf_space	*half_spaces;      /* list of half-spaces */
} Phalf_space_list;

typedef struct {
    Pint           num_half_spaces;	/* number of half-spaces */
    Phalf_space3   *half_spaces;   	/* list of half-spaces */
} Phalf_space_list3;

typedef struct {
    Pint_list	incl_set;	/* inclusion set */
    Pint_list	excl_set;	/* exclusion set */
} Pfilter;

typedef struct {
    Pint	num_filters;	/* number of filters */
    Pfilter	*filters;	/* list of filters */
} Pfilter_list;

typedef struct {
    Phor_text_align	hor;	/* horizontal component */
    Pvert_text_align	vert;	/* vertical component */
} Ptext_align;

typedef struct {
    Pint	type;		/* line type */
    Pfloat	width;		/* linewidth scale factor */
    Pint	colr_ind;	/* colour index */
} Pline_bundle;

typedef struct {
    Pint	type;		/* marker type */
    Pfloat	size;		/* marker size scale factor */
    Pint	colr_ind;	/* colour index */
} Pmarker_bundle;

typedef struct {
    Pint	font;		/* text font */
    Ptext_prec	prec;		/* text precision */
    Pfloat	char_expan;	/* character char_expansion factor */
    Pfloat	char_space;	/* character spacing */
    Pint	colr_ind;	/* text colour index */
} Ptext_bundle;

typedef struct {
    Pint_style	style;		/* interior style */
    Pint	style_ind;	/* interior style index */
    Pint	colr_ind;	/* interior colour index */
} Pint_bundle;

typedef struct {
    Pedge_flag	flag;		/* edge flag */
    Pint	type;		/* edgetype */
    Pfloat	width;		/* edgewidth scale factor */
    Pint	colr_ind;	/* edge colour index */
} Pedge_bundle;

typedef struct {
    Pint_size	dims;		/* pattern's dimensions */
    Pint	*colr_array;	/* colour index array */
} Ppat_rep;

typedef struct {
    Pmatrix3	ori_matrix;	/* orientation matrix */
    Pmatrix3	map_matrix;	/* mapping matrix */
    Plimit3	clip_limit;	/* clipping limits */
    Pclip_ind	xy_clip;	/* X-Y clipping indicator */
    Pclip_ind	back_clip;	/* back clipping indicator */
    Pclip_ind	front_clip;	/* front clipping indicator */
} Pview_rep3;

typedef struct {
    Pmatrix	ori_matrix;	/* orientation matrix */
    Pmatrix	map_matrix;	/* mapping matrix */
    Plimit	clip_limit;	/* clipping limits */
    Pclip_ind	xy_clip;	/* X-Y clipping ind */
} Pview_rep;

typedef struct {
    Plimit	win;		/* window limits */
    Plimit3	proj_vp;	/* viewport limits */
    Pproj_type	proj_type;	/* projection type */
    Ppoint3	proj_ref_point;	/* projection reference point */
    Pfloat	view_plane;	/* view plane distance */
    Pfloat	back_plane;	/* back plane distance */
    Pfloat	front_plane;	/* front plane distance */
} Pview_map3;

typedef struct {
    Plimit	win;		/* window limits */
    Plimit	proj_vp;	/* viewport limits */
} Pview_map;

typedef struct {
    Pasf        	type_asf;	/* line type asf */
    Pasf        	width_asf;	/* line width asf */
    Pasf        	colr_ind_asf;	/* line colour index asf */
    Pint        	ind;		/* line index */
    Pline_bundle	bundle;		/* line bundle */
} Pline_attrs;

typedef struct {
    Pasf	style_asf;	/* interior asf */
    Pasf	style_ind_asf;	/* interior style asf */
    Pasf	colr_ind_asf;	/* interior colour index asf */
    Pint	ind;		/* interior index */
    Pint_bundle	bundle;		/* interior bundle */
} Pint_attrs;

typedef struct {
    Pasf	        flag_asf;	/* edge flag asf */
    Pasf	        type_asf;	/* edge type asf */
    Pasf	        width_asf;	/* edge width asf */
    Pasf	        colr_ind_asf;	/* edge colour index asf */
    Pint	        ind;		/* edge index */
    Pedge_bundle	bundle;		/* edge bundle */
} Pedge_attrs;

typedef struct {
    Pasf	        type_asf;	/* marker type asf */
    Pasf	        size_asf;	/* marker style asf */
    Pasf	        colr_ind_asf;	/* marker colour index asf */
    Pint	        ind;		/* marker index */
    Pmarker_bundle	bundle;		/* marker bundle */
} Pmarker_attrs;

typedef struct {
    Pint	struct_id;	/* structure identifier */
    Pint	pick_id;	/* hierarchical pick identifier */
    Pint	elem_pos;	/* element sequence number */
} Ppick_path_elem;

typedef struct {
    Pint		depth;		/* pick path_list depth */
    Ppick_path_elem	*path_list;	/* pick path */
} Ppick_path;

typedef struct {
    Pdc_units	dc_units;	/* device coordinate units */
    Pfloat_size	size_dc;	/* device size in coordinate units */
    Pint_size	size_raster;	/* device size in raster units */
} Pdisp_space_size;

typedef struct {
    Pdc_units		dc_units;	/* device coordinate units */
    Pfloat_size3	size_dc;	/* device volume in coordinate units */
    Pint_size3		size_raster;	/* device volume in raster units */
} Pdisp_space_size3;

typedef struct {
    Pdyn_mod	line_bundle;	/* polyline representation */
    Pdyn_mod	marker_bundle;	/* polymarker representation */
    Pdyn_mod	text_bundle;	/* text representation */
    Pdyn_mod	int_bundle;	/* interior representation */
    Pdyn_mod	edge_bundle;	/* edge representation */
    Pdyn_mod	pat_rep;	/* pattern representation */
    Pdyn_mod	colr_rep;	/* colour representation */
    Pdyn_mod	view_rep;	/* view representation */
    Pdyn_mod	ws_tran;	/* workstation transform */
    Pdyn_mod	highl_filter;	/* highlight filter */
    Pdyn_mod	invis_filter;	/* invisibility filter */
    Pdyn_mod	hlhsr_mode;	/* HLHSR mode */
} Pdyns_ws_attrs;

typedef struct {
    Pint_list	types;		/* list of line types */
    Pint	num_widths;	/* number of available line widths */
    Pfloat	nom_width;	/* nominal line width */
    Pfloat	min_width;	/* min line width */
    Pfloat	max_width;	/* max line width */
    Pint	num_pred_inds;	/* number of predefined bundles */
} Pline_facs;

typedef struct {
    Pint_list	types;	/* list of marker types */
    Pint	num_sizes;	/* number of available marker sizes */
    Pfloat	nom_size;	/* nominal marker size */
    Pfloat	min_size;	/* min marker size */
    Pfloat	max_size;	/* max marker size */
    Pint	num_pred_inds;	/* number of predefined bundles */
} Pmarker_facs;

typedef struct {
    Pint	font;	/* text font */
    Ptext_prec	prec;	/* text precision */
} Ptext_font_prec;

typedef struct {
    Pint	num_font_precs;	/* number of fonts and precisions */
    Ptext_font_prec	*font_precs;	/* list of fonts and precisions */
    Pint	num_char_hts;	/* number of character heights */
    Pfloat	min_char_ht;	/* minimum height */
    Pfloat	max_char_ht;	/* maximum height */
    Pint	num_char_expans;	/* number of character expansion factors */
    Pfloat	min_char_expan;	/* minimum expansion factor */
    Pfloat	max_char_expan;	/* maximum expansion factor */
    Pint	num_pred_inds;	/* number of predefined bundles */
} Ptext_facs;

typedef struct {
    Pint	num_int_styles;	/* number of interior styles */
    Pint_style	int_styles[5];	/* list of available interior styles */
    Pint_list	hatch_styles;	/* list of available hatch styles */
    Pint	num_pred_inds;	/* number of predefined bundles */
} Pint_facs;


typedef struct {
    Pint_list	types;	/* list of edge types */
    Pint	num_widths;	/* number of available edge widths */
    Pfloat	nom_width;	/* nominal edge width */
    Pfloat	min_width;	/* min edge width */
    Pfloat	max_width;	/* max edge width */
    Pint	num_pred_inds;	/* number of predefined bundles */
} Pedge_facs;

typedef struct {
    Pint	num_colrs;	/* number of colours */
    Pcolr_avail	colr_avail;	/* colour availability */
    Pint	num_pred_inds;	/* number of predefined bundles */
    Pcieluv	prim_colrs[3];	/* primary colours */
} Pcolr_facs;

typedef struct {
    Pint	line_bundles;	    /* polyline tables */
    Pint	mark_bundles;	    /* polymarker tables */
    Pint	text_bundles;	    /* text tables */
    Pint	int_bundles;        /* interior tables */
    Pint	edge_bundles;	    /* edge tables */
    Pint	pat_reps;	    /* pattern tables */
    Pint	colr_reps;	    /* colour tables */
    Pint	view_reps;	    /* view tables */
} Pws_st_tables;

typedef struct {
    Pdyn_mod	content;	/* structure content */
    Pdyn_mod	post;		/* post structure  */
    Pdyn_mod	unpost;		/* unpost structure  */
    Pdyn_mod	del;		/* del structure  */
    Pdyn_mod	ref;		/* structure references  */
} Pdyns_structs;

typedef struct {
    Pint	loc;	/* locators */
    Pint	stroke;	/* strokes */
    Pint	val;	/* valuators */
    Pint	choice;	/* choices */
    Pint	pick;	/* picks */
    Pint	string;	/* strings */
} Pnum_in;

typedef struct {
    Pint	num_elem_types;	/* number of elements */
    Pelem_type	*elem_types;	/* list of elements */
} Pelem_type_list;

typedef union {
    {IMPL-DEP}
    Pdata  unsupp;           /* unsupported Metafile item data */
} Pitem_data;

typedef struct {
    union Ploc_pets {
        {IMPL-DEP}
	struct Ploc_pet_r1 {
	   {IMPL-DEP}
	} pet_r1;
	struct Ploc_pet_r2 {
	   {IMPL-DEP}
	} pet_r2;
	struct Ploc_pet_r3 {
	   {IMPL-DEP}
	} pet_r3;
	struct Ploc_pet_r4 {
	   Pline_attrs	line_attrs;	/* polyline attributes */
           {IMPL-DEP}
	} pet_r4;
	struct Ploc_pet_r5 {
	   Pline_fill_ctrl_flag	line_fill_ctrl_flag;
	   union Ploc_attrs {
 		 Pline_attrs	line_attrs;	/* polyline attributes */
		 Pint_attrs	int_attrs;	/* interior attributes */
		 struct Ploc_fill_set {
			Pint_attrs	int_attrs; /* interior attributes */
			Pedge_attrs	edge_attrs; /* edge attributes */
		 } fill_set;
	   } attrs;
           {IMPL-DEP}
	} pet_r5;
	struct Ploc_pet_r6 {
	   {IMPL-DEP}
	} pet_r6;
        {IMPL-DEP}
    } pets;
} Ploc_data;

typedef struct {
	Pint	in_buf_size;	/* input buffer size */
	Pint	init_pos;	/* initial editing position		*/
	Pfloat	x_interval;	/* x interval				*/
	Pfloat	y_interval;	/* y interval				*/
	Pfloat	time_interval;	/* time interval			*/
	union Pstroke_pets {
           {IMPL-DEP}
	   struct Pstroke_pet_r1 {
              {IMPL-DEP}
           } pet_r1;
	   struct Pstroke_pet_r2 {
              {IMPL-DEP}
           } pet_r2;
	   struct Pstroke_pet_r3 {
	      Pmarker_attrs	marker_attrs;	/* marker attributes */
              {IMPL-DEP}
	   } pet_r3;
	   struct Pstroke_pet_r4 {
	      Pline_attrs	line_attrs;	/* line attributes */
              {IMPL-DEP}
	   } pet_r4;
           {IMPL-DEP}
	} pets;
} Pstroke_data;

typedef struct {
	Pfloat  low_value;            /* low range limit */
	Pfloat  high_value;           /* high range limit */
	union Pval_pets {
           {IMPL-DEP}
	   struct Pval_pet_r1 {
	      {IMPL-DEP}
	   } pet_r1;
           {IMPL-DEP}
	} pets;
} Pval_data;

typedef struct {
    union Pchoice_pets {
        {IMPL-DEP}
	struct Pchoice_pet_r1 {
	   {IMPL-DEP}
	} pet_r1;
	struct Pchoice_pet_r2 {
	   Pint		num_prompts;	/* number of alternatives	*/
	   Ppr_switch	*prompts;	/* array of prompts		*/
           {IMPL-DEP}
	} pet_r2;
	struct Pchoice_pet_r3 {
	   Pint		num_strings;	/* number of choice strings	*/
	   char		**strings;	/* array of choice strings	*/
           {IMPL-DEP}
	} pet_r3;
	struct Pchoice_pet_r4 {
	   Pint		num_strings;	/* number of choice strings     */
	   char		**strings;	/* array of choice strings	*/
           {IMPL-DEP}
	} pet_r4;
	struct Pchoice_pet_r5 {
	   Pint		struct_id;	/* struct identifier		*/
	   Pint		num_pick_ids;	/* number of pick ids		*/
	   Pint		*pick_ids;	/* array of pick identifiers	*/
           {IMPL-DEP}
	} pet_r5;
        {IMPL-DEP}
    } pets;
} Pchoice_data;

typedef struct {
    union Ppick_pets {
        {IMPL-DEP}
	struct Ppick_pet_r1 {
	    {IMPL-DEP}
	} pet_r1;
        {IMPL-DEP}
    } pets;
} Ppick_data;

typedef struct {
	Pint	in_buf_size;		/* input buffer size		*/
	Pint	init_pos;		/* initial editing position	*/
	union Pstring_pets {
           {IMPL-DEP}
           struct Pstring_pet_r1 {
              {IMPL-DEP}
           } pet_r1;
           {IMPL-DEP}
        } pets;
} Pstring_data;

typedef struct {
    union Ploc3_pets {
        {IMPL-DEP}
	struct Ploc3_pet_r1 {
	   {IMPL-DEP}
	} pet_r1;
	struct Ploc3_pet_r2 {
	   {IMPL-DEP}
	} pet_r2;
	struct Ploc3_pet_r3 {
	   {IMPL-DEP}
	} pet_r3;
	struct Ploc3_pet_r4 {
	   Pline_attrs	line_attrs;
           {IMPL-DEP}
	} pet_r4;
	struct Ploc3_pet_r5 {
	   Pline_fill_ctrl_flag	line_fill_ctrl_flag;
	   union Ploc3_attrs {
		 Pline_attrs	line_attrs;
		 Pint_attrs	int_attrs; 
		 struct Ploc3_fill_set {
			Pint_attrs	int_attrs; 
			Pedge_attrs	edge_attrs;
		 } fill_set;
	   } attrs;
           {IMPL-DEP}
	} pet_r5;
	struct Ploc3_pet_r6 {
	   {IMPL-DEP}
	} pet_r6;
        {IMPL-DEP}
    } pets;
} Ploc_data3;

typedef struct {
	Pint	in_buf_size;	/* input buffer size 		*/
	Pint	init_pos;	/* initial editing position	*/
	Pfloat	x_interval;	/* x interval			*/
	Pfloat	y_interval;	/* y interval			*/
	Pfloat	z_interval;	/* z interval			*/
	Pfloat	time_interval;	/* time interval		*/
	union Pstroke3_pets {
           {IMPL-DEP}
	   struct Pstroke3_pet_r1 {
              {IMPL-DEP}
           } pet_r1;
	   struct Pstroke3_pet_r2 {
              {IMPL-DEP}
           } pet_r2;
	   struct Pstroke3_pet_r3 {
	      Pmarker_attrs	marker_attrs;	/* marker attributes */
              {IMPL-DEP}
	   } pet_r3;
	   struct Pstroke3_pet_r4 {
	      Pline_attrs	line_attrs;	/* line attributes */
              {IMPL-DEP}
	   } pet_r4;
           {IMPL-DEP}
	} pets;
} Pstroke_data3;

typedef struct {
	Pfloat  low_value;            /* low range limit */
	Pfloat  high_value;           /* high range limit */
	union Pval3_pets {
            {IMPL-DEP}
	    struct Pval3_pet_r1 {
		{IMPL-DEP}
	    } pet_r1;
            {IMPL-DEP}
	} pets;
} Pval_data3;

typedef struct {
    union Pchoice3_pets {
        {IMPL-DEP}
	struct Pchoice3_pet_r1 {
	   {IMPL-DEP}
	} pet_r1;
	struct Pchoice3_pet_r2 {
	   Pint		num_prompts;	/* number of alternatives	*/
	   Ppr_switch	*prompts;	/* array of prompts		*/
           {IMPL-DEP}
	} pet_r2;
	struct Pchoice3_pet_r3 {
	   Pint		num_strings;	/* number of choice strings	*/
	   char		**strings;	/* array of choice strings	*/
           {IMPL-DEP}
	} pet_r3;
	struct Pchoice3_pet_r4 {
	   Pint		num_strings;	/* number of alternatives	*/
	   char		**strings;	/* array of strings		*/
           {IMPL-DEP}
	} pet_r4;
	struct Pchoice3_pet_r5 {
	   Pint		struct_id;	/* struct identifier		*/
	   Pint		num_pick_ids;	/* number of alternatives	*/
	   Pint		*pick_ids;	/* array of pick identifiers	*/
           {IMPL-DEP}
	} pet_r5;
        {IMPL-DEP}
    } pets;
} Pchoice_data3;

typedef struct {
    union Ppick3_pets {
        {IMPL-DEP}
	struct Ppick3_pet_r1 {
	    {IMPL-DEP}
	} pet_r1;
        {IMPL-DEP}
    } pets;
} Ppick_data3;

typedef struct {
	Pint	in_buf_size;		/* input buffer size		*/
	Pint	init_pos;		/* initial editing position	*/
	union Pstring3_pets {
           {IMPL-DEP}
           struct Pstring3_pet_r1 {
              {IMPL-DEP}
           } pet_r1;
           {IMPL-DEP}
        } pets;
} Pstring_data3;

/*  *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***

    These are the typedefs for GDP, GSE, and ESCAPE as they appear in
    the PHIGS/C standard. These statements are not suitable for
    comparison with the file under test (phigs.h), however, since
    they imply that certain optional components of the unions are
    mandatory (e.g. gdp_r1).  There is no requirement to support
    gdp_r1;  rather this serves to illustrate the standard format for
    whatever gdp's are supported, and likewise for gse and escape.

typedef union {
        {IMPL-DEP}
	struct Pgdp_r1 {
            {IMPL-DEP}
	} gdp_r1;
	Pdata	unsupp;
        {IMPL-DEP}
} Pgdp_data;

typedef union {
        {IMPL-DEP}
	struct Pgdp3_r1 {
            {IMPL-DEP}
	} gdp3_r1;
	Pdata	unsupp;
        {IMPL-DEP}
} Pgdp_data3;

typedef union {
        {IMPL-DEP}
	struct Pgse_r1 {
            {IMPL-DEP}
	} gse_r1;
	Pdata	unsupp;
        {IMPL-DEP}
} Pgse_data;

typedef union {
        {IMPL-DEP}
	struct Pescape_out_r1 {
            {IMPL-DEP}
	} escape_out_r1;
        {IMPL-DEP}
} Pescape_out_data;

typedef union {
        {IMPL-DEP}
	struct Pescape_in_r1 {
            {IMPL-DEP}
	} escape_in_r1;
        {IMPL-DEP}
} Pescape_in_data;

The following typedefs are used for comparison purposes with the
file under test, since they represent the minimum allowable
content of each statement.

*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */

typedef union {
        {IMPL-DEP}
	Pdata	unsupp;		/* unsupported GDP data record	*/
        {IMPL-DEP}
} Pgdp_data;

typedef union {
        {IMPL-DEP}
	Pdata	unsupp;		/* unsupported GDP data record	*/
        {IMPL-DEP}
} Pgdp_data3;

typedef union {
        {IMPL-DEP}
	Pdata	unsupp;		/* unsupported GSE data record	*/
        {IMPL-DEP}
} Pgse_data;

typedef union {
        {IMPL-DEP}
} Pescape_out_data;

typedef union {
        {IMPL-DEP}
} Pescape_in_data;

/* *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** */

typedef union {
    Pint		int_data;		/* integer valued data */
    Pfloat		float_data;		/* float valued data */
    Ppoint_list3	point_list3;		/* list of 3d points */
    Ppoint_list		point_list;		/* list of 2d points */
    Ppoint_list_list3	point_list_list3;	/* list of 3d point lists */
    Ppoint_list_list	point_list_list;	/* list of 2d point lists */
    struct Pelem_text3 {
        Ppoint3		pos;		/* text point */
        Pvec3   	dir[2];		/* direction vectors */
        char		*char_string;	/* text string */
    } text3;
    struct Pelem_text {
        Ppoint		pos;		/* text point */
        char		*char_string;	/* text string */
    } text;
    struct Pelem_anno_text_rel3 {
        Ppoint3		ref_point;	/* reference point */
        Pvec3		offset;		/* anno offset */
        char		*char_string;	/* text string */
    } anno_text_rel3;
    struct Pelem_anno_text_rel {
        Ppoint		ref_point;	/* reference point */
        Pvec		offset;		/* anno offset */
        char		*char_string;	/* text string */
    } anno_text_rel;
    struct Pelem_cell_array3 {
        Pparal		paral;  	/* parallelogram */
        Ppat_rep	colr_array;   	/* colour array */
    } cell_array3;
    struct Pelem_cell_array {
        Prect		rect;		/* rectangle */
        Ppat_rep	colr_array;  	/* colour array */
    } cell_array;
    struct Pelem_gdp3 {
        Pint		id;		/* GDP3 id */
        Ppoint_list3	point_list;	/* points */
        Pgdp_data3	data;		/* data record */
    } gdp3;
    struct Pelem_gdp {
        Pint		id;		/* GDP id */
        Ppoint_list	point_list;	/* points */
        Pgdp_data	data;		/* data record */
    } gdp;
    Ptext_prec		text_prec;	/* text precision */
    Pvec		char_up_vec;	/* char up vector */
    Ptext_path		text_path;	/* text path */
    Ptext_align		text_align;	/* text alignment */
    Pint_style		int_style;	/* interior style */
    Pedge_flag		edge_flag;	/* edge flag */
    Ppoint		pat_ref_point;	/* pat ref point */
    Pfloat_size		pat_size;	/* pattern size */
    struct Pelem_pat_ref_point_vecs {
        Ppoint3		ref_point;	/* pat ref point */
        Pvec3   	ref_vec[2];	/* vectors */
    } pat_ref_point_vecs;
    Pint_list		names;  	/* name sets */
    struct Pelem_asf {
        Paspect		id;		/* attribute id */
        Pasf		source;		/* asf */
    } asf;
    struct Pelem_local_tran3 {
        Pcompose_type	compose_type;	/* composition type */
        Pmatrix3	matrix;		/* transformation matrix */
    } local_tran3;
    struct Pelem_local_tran {
        Pcompose_type	compose_type;	/* composition type */
        Pmatrix		matrix;		/* transformation matrix */
    } local_tran;
    Pmatrix3		global_tran3;	/* global transform3 */
    Pmatrix		global_tran;	/* global transform */
    struct Pelem_model_clip3 {
        Pint		  op;		/* operator */
        Phalf_space_list3 half_spaces;	/* half-space list */
    } model_clip3;
    struct Pelem_model_clip {
        Pint		 op;		/* operator */
        Phalf_space_list half_spaces;	/* half-space list */
    } model_clip;
    Pclip_ind		clip_ind;	/* clipping indicator */
    Pdata		appl_data;	/* application data */
    struct Pelem_gse {
        Pint		id;		/* GSE id */
        Pgse_data	data;		/* GSE data record */
    } gse;
    {IMPL-DEP}
} Pelem_data;


/*** *** *** *** *** *** *** *** *** *** *** *** *** *** ***/
/***              end standard typedefs                  ***/
/*** *** *** *** *** *** *** *** *** *** *** *** *** *** ***/
/***             begin standard functions                ***/
/*** *** *** *** *** *** *** *** *** *** *** *** *** *** ***/

extern void popen_phigs(
    const char    *err_file,
    size_t        mem_units
);

extern void pclose_phigs(
    void
);

extern void popen_ws(
    Pint          ws_id,
    const void    *conn_id,
    Pint          ws_type
);
extern void pclose_ws(
    Pint    ws_id
);
extern void predraw_all_structs(
    Pint         ws_id,
    Pctrl_flag   ctrl_flag
);
extern void pupd_ws(
    Pint         ws_id,
    Pregen_flag  regen_flag
);
extern void pset_disp_upd_st(
    Pint         ws_id,
    Pdefer_mode  def_mode,
    Pmod_mode    mod_mode
);
extern void pmessage(
    Pint               ws_id,
    const char         *message
);
extern void ppolyline3(
    const Ppoint_list3 *point_list
);
extern void ppolyline(
    const Ppoint_list  *point_list
);
extern void ppolymarker3(
    const Ppoint_list3 *point_list
);
extern void ppolymarker(
    const Ppoint_list  *point_list
);
extern void ptext3(
    const Ppoint3      *text_pos,
    const Pvec3        text_dir[2],
    const char         *char_string
);
extern void ptext(
    const Ppoint       *text_pos,
    const char         *char_string
);
extern void panno_text_rel3(
    const Ppoint3      *ref_point,
    const Pvec3        *offset,
    const char         *char_string
);
extern void panno_text_rel(
    const Ppoint       *ref_point,
    const Pvec         *offset,
    const char         *char_string
);
extern void pfill_area3(
    const Ppoint_list3 *point_list
);
extern void pfill_area(
    const Ppoint_list  *point_list
);
extern void pfill_area_set3(
    const Ppoint_list_list3  *point_list_list
);
extern void pfill_area_set(
    const Ppoint_list_list   *point_list_list
);
extern void pcell_array3(
    const Pparal       *paral,
    const Ppat_rep     *colr_array
);

extern void pcell_array(
    const Prect        *rect,
    const Ppat_rep     *colr_array
);
extern void pgdp3(
    const Ppoint_list3 *point_list,
    Pint               gdp3_id,
    const Pgdp_data3   *gdp_data
);

extern void pgdp(
    const Ppoint_list  *point_list,
    Pint               gdp_id,
    const Pgdp_data    *gdp_data
);
extern void pset_line_ind(
    Pint         line_ind
);
extern void pset_marker_ind(
    Pint         marker_ind
);
extern void pset_text_ind(
    Pint         text_ind
);
extern void pset_int_ind(
    Pint         int_ind
);
extern void pset_edge_ind(
    Pint         edge_ind
);
extern void pset_linetype(
    Pint         linetype
);
extern void pset_linewidth(
    Pfloat       linewidth
);
extern void pset_line_colr_ind(
    Pint         line_colr_ind
);
extern void pset_marker_type(
    Pint         marker_type
);
extern void pset_marker_size(
    Pfloat       marker_size
);
extern void pset_marker_colr_ind(
    Pint         marker_colr_ind
);
extern void pset_text_font(
    Pint         font
);
extern void pset_text_prec(
    Ptext_prec   prec
);
extern void pset_char_expan(
    Pfloat       char_expan
);
extern void pset_char_space(
    Pfloat       char_space
);
extern void pset_text_colr_ind(
    Pint         text_colr_ind
);
extern void pset_char_ht(
    Pfloat       char_ht
);
extern void pset_char_up_vec(
    const Pvec   *char_up_vec
);
extern void pset_text_path(
    Ptext_path   text_path
);
extern void pset_text_align(
    const Ptext_align  *text_align
);
extern void pset_anno_char_ht(
    Pfloat       char_ht
);
extern void pset_anno_char_up_vec(
    const Pvec   *char_up_vec
);
extern void pset_anno_path(
    Ptext_path   text_path
);
extern void pset_anno_align(
    const Ptext_align  *text_align
);
extern void pset_anno_style(
    Pint         anno_style
);
extern void pset_int_style(
    Pint_style   int_style
);
extern void pset_int_style_ind(
    Pint         int_style_ind
);
extern void pset_int_colr_ind(
    Pint         int_colr_ind
);
extern void pset_edge_flag(
    Pedge_flag   edge_flag
);
extern void pset_edgetype(
    Pint         edgetype
);
extern void pset_edgewidth(
    Pfloat       edgewidth
);
extern void pset_edge_colr_ind(
    Pint         edge_colr_ind
);
extern void pset_pat_size(
    const Pfloat_size  *pat_size
);
extern void pset_pat_ref_point_vecs(
    const Ppoint3      *pat_ref_point,
    const Pvec3        pat_ref_vec[2]
);

extern void pset_pat_ref_point(
    const Ppoint       *pat_ref_point
);
extern void padd_names_set(
    const Pint_list    *names
);
extern void premove_names_set(
    const Pint_list    *names
);

extern void pset_indiv_asf(
    Paspect      asf_id,
    Pasf         asf_source
);

extern void pset_line_rep(
    Pint                 ws_id,
    Pint                 line_ind,
    const Pline_bundle   *line_bundle
);

extern void pset_marker_rep(
    Pint                 ws_id,
    Pint                 marker_ind,
    const Pmarker_bundle *marker_bundle
);

extern void pset_text_rep(
    Pint                 ws_id,
    Pint                 text_ind,
    const Ptext_bundle   *text_bundle
);

extern void pset_int_rep(
    Pint                 ws_id,
    Pint                 int_ind,
    const Pint_bundle    *int_bundle
);

extern void pset_edge_rep(
    Pint                 ws_id,
    Pint                 edge_ind,
    const Pedge_bundle   *edge_bundle
);

extern void pset_pat_rep(
    Pint                 ws_id,
    Pint                 pat_ind,
    const Ppat_rep       *pat_bundle
);
extern void pset_colr_rep(
    Pint                 ws_id,
    Pint                 colr_ind,
    const Pcolr_rep      *colr_rep
);

extern void pset_highl_filter(
    Pint            ws_id,
    const Pfilter   *filter
);

extern void pset_invis_filter(
    Pint            ws_id,
    const Pfilter   *filter
);

extern void pset_colr_model(
    Pint            ws_id,
    Pint            colr_model
);

extern void pset_hlhsr_id(
    Pint         hlhsr_id
);

extern void pset_hlhsr_mode(
    Pint         ws_id,
    Pint         hlhsr_mode
);

extern void pset_local_tran3(
    Pmatrix3        local_tran,
    Pcompose_type   compose_type
);

extern void pset_local_tran(
    Pmatrix         local_tran,
    Pcompose_type   compose_type
);

extern void pset_global_tran3(
    Pmatrix3        global_tran
);

extern void pset_global_tran(
    Pmatrix         global_tran
);

extern void pset_model_clip_vol3(
    Pint                     op,
    const Phalf_space_list3  *half_spaces
);

extern void pset_model_clip_vol(
    Pint                     op,
    const Phalf_space_list   *half_spaces
);

extern void pset_model_clip_ind(
    Pclip_ind          clip_ind
);

extern void prestore_model_clip_vol(
    void
);

extern void pset_view_ind(
    Pint         view_ind
);

extern void pset_view_rep3(
    Pint               ws_id,
    Pint               view_ind,
    const Pview_rep3   *view_rep
);

extern void pset_view_rep(
    Pint               ws_id,
    Pint               view_ind,
    const Pview_rep    *view_rep
);

extern void pset_view_tran_in_pri(
    Pint            ws_id,
    Pint            view_ind,
    Pint            ref_view_ind,
    Prel_pri        rel_pri
);
extern void pset_ws_win3(
    Pint            ws_id,
    const Plimit3   *ws_win_limits
);

extern void pset_ws_win(
    Pint            ws_id,
    const Plimit    *ws_win_limits
);

extern void pset_ws_vp3(
    Pint            ws_id,
    const Plimit3   *ws_vp_limits
);

extern void pset_ws_vp(
    Pint            ws_id,
    const Plimit    *ws_vp_limits
);

extern void ptranslate3(
    const Pvec3     *trans_vec,
    Pint            *err_ind,
    Pmatrix3        result_tran
);

extern void ptranslate(
    const Pvec      *trans_vec,
    Pint            *err_ind,
    Pmatrix         result_tran
);

extern void pscale3(
    const Pvec3     *scale_vec,
    Pint            *err_ind,
    Pmatrix3        result_tran
);

extern void pscale(
    const Pvec      *scale_vec,
    Pint            *err_ind,
    Pmatrix         result_tran
);

extern void protate_x(
    Pfloat          angle,
    Pint            *err_ind,
    Pmatrix3        result_tran
);

extern void protate_y(
    Pfloat          angle,
    Pint            *err_ind,
    Pmatrix3        result_tran
);

extern void protate_z(
    Pfloat          angle,
    Pint            *err_ind,
    Pmatrix3        result_tran
);

extern void protate(
    Pfloat          angle,
    Pint            *err_ind,
    Pmatrix         result_tran
);

extern void pcompose_matrix3(
    Pmatrix3        tran_a,
    Pmatrix3        tran_b,
    Pint            *err_ind,
    Pmatrix3        result_tran
);

extern void pcompose_matrix(
    Pmatrix         tran_a,
    Pmatrix         tran_b,
    Pint            *err_ind,
    Pmatrix         result_tran
);

extern void ptran_point3(
    const Ppoint3   *point,
    Pmatrix3        tran,
    Pint            *err_ind,
    Ppoint3         *result
);

extern void ptran_point(
    const Ppoint    *point,
    Pmatrix         tran,
    Pint            *err_ind,
    Ppoint          *result
);

extern void pbuild_tran_matrix3(
    const Ppoint3   *point,
    const Pvec3     *shift_vec,
    Pfloat          x_angle,
    Pfloat          y_angle,
    Pfloat          z_angle,
    const Pvec3     *scale_vec,
    Pint            *err_ind,
    Pmatrix3        result_tran
);

extern void pbuild_tran_matrix(
    const Ppoint    *point,
    const Pvec      *shift_vec,
    Pfloat          angle,
    const Pvec      *scale_vec,
    Pint            *err_ind,
    Pmatrix         result_tran
);

extern void pcompose_tran_matrix3(
    Pmatrix3        tran,
    const Ppoint3   *point,
    const Pvec3     *shift_vec,
    Pfloat          x_angle,
    Pfloat          y_angle,
    Pfloat          z_angle,
    const Pvec3     *scale_vec,
    Pint            *err_ind,
    Pmatrix3        result_tran
);

extern void pcompose_tran_matrix(
    Pmatrix         tran,
    const Ppoint    *point,
    const Pvec      *shift_vec,
    Pfloat          angle,
    const Pvec      *scale_vec,
    Pint            *err_ind,
    Pmatrix         result_tran
);

extern void peval_view_ori_matrix3(
    const Ppoint3   *view_ref_point,
    const Pvec3     *view_norm_vec,
    const Pvec3     *view_up_vec,
    Pint            *err_ind,
    Pmatrix3        result_tran
);

extern void peval_view_ori_matrix(
    const Ppoint    *view_ref_point,
    const Pvec      *view_up_vec,
    Pint            *err_ind,
    Pmatrix         result_tran
);

extern void peval_view_map_matrix3(
    const Pview_map3  *mapping,
    Pint              *err_ind,
    Pmatrix3          result_tran
);

extern void peval_view_map_matrix(
    const Pview_map *mapping,
    Pint            *err_ind,
    Pmatrix         result_tran
);

extern void popen_struct(
    Pint            struct_id
);

extern void pclose_struct(
    void
);

extern void pexec_struct(
    Pint            struct_id
);

extern void plabel(
    Pint            label_id
);

extern void pappl_data(
    const Pdata     *data
);

extern void pgse(
    Pint            id,
    const Pgse_data *gse_data
);

extern void pset_edit_mode(
    Pedit_mode      edit_mode
);

extern void pcopy_all_elems_struct(
    Pint            struct_id
);

extern void pset_elem_ptr(
    Pint            elem_ptr_value
);

extern void poffset_elem_ptr(
    Pint            elem_ptr_offset
);

extern void pset_elem_ptr_label(
    Pint            label_id
);

extern void pdel_elem(
    void
);

extern void pdel_elem_range(
    Pint            elem_ptr1_value,
    Pint            elem_ptr2_value
);

extern void pdel_elems_labels(
    Pint            label1_id,
    Pint            label2_id
);

extern void pempty_struct(
    Pint            struct_id
);

extern void pdel_struct(
    Pint            struct_id
);

extern void pdel_struct_net(
    Pint            struct_id,
    Pref_flag       ref_flag
);

extern void pdel_all_structs(
    void
);

extern void pchange_struct_id(
    Pint            orig_struct_id,
    Pint            result_struct_id
);

extern void pchange_struct_refs(
    Pint            orig_struct_id,
    Pint            result_struct_id
);

extern void pchange_struct_id_refs(
    Pint            orig_struct_id,
    Pint            result_struct_id
);

extern void ppost_struct(
    Pint            ws_id,
    Pint            struct_id,
    Pfloat          pri
);

extern void punpost_struct(
    Pint            ws_id,
    Pint            struct_id
);

extern void punpost_all_structs(
    Pint            ws_id
);

extern void popen_ar_file(
    Pint            archive_id,
    const char      *archive_file
);

extern void pclose_ar_file(
    Pint            archive_id
);

extern void par_structs(
    Pint            archive_id,
    const Pint_list *struct_ids
);

extern void par_struct_nets(
    Pint            archive_id,
    const Pint_list *struct_ids
);

extern void par_all_structs(
    Pint            archive_id
);

extern void pset_conf_res(
    Pconf_res       archival_res,
    Pconf_res       retrieval_res
);

extern void pret_struct_ids(
    Pint            archive_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint_list       *ids,
    Pint            *num_elems_impl_list
);

extern void pret_structs(
    Pint            archive_id,
    const Pint_list *struct_ids
);

extern void pret_struct_nets(
    Pint            archive_id,
    const Pint_list *struct_ids
);

extern void pret_all_structs(
    Pint            archive_id
);

extern void pret_paths_ances(
    Pint                 ar_id,
    Pint                 struct_id,
    Ppath_order          order,
    Pint                 depth,
    Pstore               store,
    Pelem_ref_list_list  **paths
);

extern void pret_paths_descs(
    Pint                 ar_id,
    Pint                 struct_id,
    Ppath_order          order,
    Pint                 depth,
    Pstore               store,
    Pelem_ref_list_list  **paths
);

extern void pdel_structs_ar(
    Pint            archive_id,
    const Pint_list *struct_ids
);

extern void pdel_struct_nets_ar(
    Pint            archive_id,
    const Pint_list *struct_ids
);

extern void pdel_all_structs_ar(
    Pint            archive_id
);

extern void pset_pick_id(
    Pint            pick_id
);

extern void pset_pick_filter(
    Pint            ws_id,
    Pint            pick_num,
    const Pfilter   *filter
);
extern void pinit_loc3(
    Pint              ws_id,
    Pint              loc_num,
    Pint              init_view_ind,
    const Ppoint3     *init_loc_pos,
    Pint              pet,
    const Plimit3     *echo_vol,
    const Ploc_data3  *loc_data
);

extern void pinit_loc(
    Pint              ws_id,
    Pint              loc_num,
    Pint              init_view_ind,
    const Ppoint      *init_loc_pos,
    Pint              pet,
    const Plimit      *echo_area,
    const Ploc_data   *loc_data
);

extern void pinit_stroke3(
    Pint                ws_id,
    Pint                stroke_num,
    Pint                init_view_ind,
    const Ppoint_list3  *init_stroke,
    Pint                pet,
    const Plimit3       *echo_vol,
    const Pstroke_data3 *stroke_data
);
extern void pinit_stroke(
    Pint                ws_id,
    Pint                stroke_num,
    Pint                init_view_ind,
    const Ppoint_list   *init_stroke,
    Pint                pet,
    const Plimit        *echo_area,
    const Pstroke_data  *stroke_data
);
extern void pinit_val3(
    Pint                ws_id,
    Pint                val_num,
    Pfloat              init_value,
    Pint                pet,
    const Plimit3       *echo_vol,
    const Pval_data3    *val_data
);
extern void pinit_val(
    Pint                ws_id,
    Pint                val_num,
    Pfloat              init_value,
    Pint                pet,
    const Plimit        *echo_area,
    const Pval_data     *val_data
);
extern void pinit_choice3(
    Pint                ws_id,
    Pint                choice_num,
    Pin_status          init_status,
    Pint                init_choice,
    Pint                pet,
    const Plimit3       *echo_vol,
    const Pchoice_data3 *choice_data
);
extern void  pinit_choice(
    Pint                ws_id,
    Pint                choice_num,
    Pin_status          init_status,
    Pint                init_choice,
    Pint                pet,
    const Plimit        *echo_area,
    const Pchoice_data  *choice_data
);

extern void pinit_pick3(
    Pint                ws_id,
    Pint                pick_num,
    Pin_status          init_status,
    const Ppick_path    *init_pick,
    Pint                pet,
    const Plimit3       *echo_vol,
    const Ppick_data3   *pick_data,
    Ppath_order         order
);
extern void pinit_pick(
    Pint                ws_id,
    Pint                pick_num,
    Pin_status          init_status,
    const Ppick_path    *init_pick,
    Pint                pet,
    const Plimit        *echo_area,
    const Ppick_data    *pick_data,
    Ppath_order         order
);
extern void pinit_string3(
    Pint                ws_id,
    Pint                string_num,
    const char          *init_string,
    Pint                pet,
    const Plimit3       *echo_vol,
    const Pstring_data3 *string_data
);
extern void pinit_string(
    Pint                ws_id,
    Pint                string_num,
    const char          *init_string,
    Pint                pet,
    const Plimit        *echo_area,
    const Pstring_data  *string_data
);

extern void pset_loc_mode(
    Pint            ws_id,
    Pint            loc_num,
    Pop_mode        op_mode,
    Pecho_switch    echo_switch
);
extern void pset_stroke_mode(
    Pint            ws_id,
    Pint            stroke_num,
    Pop_mode        op_mode,
    Pecho_switch    echo_switch
);
extern void pset_val_mode(
    Pint            ws_id,
    Pint            val_num,
    Pop_mode        op_mode,
    Pecho_switch    echo_switch
);
extern void pset_choice_mode(
    Pint            ws_id,
    Pint            choice_num,
    Pop_mode        op_mode,
    Pecho_switch    echo_switch
);
extern void pset_pick_mode(
    Pint            ws_id,
    Pint            pick_num,
    Pop_mode        op_mode,
    Pecho_switch    echo_switch
);
extern void pset_string_mode(
    Pint            ws_id,
    Pint            string_num,
    Pop_mode        op_mode,
    Pecho_switch    echo_switch
);

extern void preq_loc3(
    Pint            ws_id,
    Pint            loc_num,
    Pin_status      *in_status,
    Pint            *view_ind,
    Ppoint3         *loc_pos
);
extern void preq_loc(
    Pint            ws_id,
    Pint            loc_num,
    Pin_status      *in_status,
    Pint            *view_ind,
    Ppoint          *loc_pos
);
extern void preq_stroke3(
    Pint            ws_id,
    Pint            stroke_num,
    Pin_status      *in_status,
    Pint            *view_ind,
    Ppoint_list3    *stroke
);
extern void preq_stroke(
    Pint            ws_id,
    Pint            stroke_num,
    Pin_status      *in_status,
    Pint            *view_ind,
    Ppoint_list     *stroke
);
extern void preq_val(
    Pint            ws_id,
    Pint            val_num,
    Pin_status      *in_status,
    Pfloat          *value
);
extern void preq_choice(
    Pint            ws_id,
    Pint            choice_num,
    Pin_status      *in_status,
    Pint            *choice
);                      
extern void preq_pick(
    Pint            ws_id,
    Pint            pick_num,
    Pint            depth,
    Pin_status      *in_status,
    Ppick_path      *pick
);
extern void preq_string(
    Pint            ws_id,
    Pint            string_num,
    Pin_status      *in_status,
    char            *string
);

extern void psample_loc3(
    Pint            ws_id,
    Pint            loc_num,
    Pint            *view_ind,
    Ppoint3         *loc_pos
);

extern void psample_loc(
    Pint            ws_id,
    Pint            loc_num,
    Pint            *view_ind,
    Ppoint          *loc_pos
);                   

extern void psample_stroke3(
    Pint            ws_id,
    Pint            stroke_num,
    Pint            *view_ind,
    Ppoint_list3    *stroke
);

extern void psample_stroke(
    Pint            ws_id,
    Pint            stroke_num,
    Pint            *view_ind,
    Ppoint_list     *stroke
);

extern void psample_val( 
    Pint            ws_id,
    Pint            val_num,
    Pfloat          *value
);

extern void psample_choice(
    Pint            ws_id,
    Pint            choice_num,
    Pin_status      *choice_in_status,
    Pint            *choice
);                      
                       
extern void psample_pick(
    Pint            ws_id,
    Pint            pick_num,
    Pint            depth,
    Pin_status      *pick_in_status,
    Ppick_path      *pick
);

extern void psample_string(
    Pint            ws_id,
    Pint            string_num,
    char            *string
);

extern void pawait_event(
    Pfloat          timeout,
    Pint            *ws_id,
    Pin_class       *dev_class,
    Pint            *in_num
);

extern void pflush_events(
    Pint            ws_id,
    Pin_class       dev_class,
    Pint            in_num
);

extern void pget_loc3(
    Pint            *view_ind,
    Ppoint3         *loc_pos
);

extern void pget_loc(
    Pint            *view_ind,
    Ppoint          *loc_pos
);

extern void pget_stroke3(
    Pint            *view_ind,
    Ppoint_list3    *stroke
);

extern void pget_stroke(
    Pint            *view_ind,
    Ppoint_list     *stroke
);

extern void pget_val(
    Pfloat          *value
);

extern void pget_choice(
    Pin_status      *in_status,
    Pint            *choice
);

extern void pget_pick(
    Pint            depth,
    Pin_status      *in_status,
    Ppick_path      *pick
);

extern void pget_string(
    char            *string
);

extern void pwrite_item(
    Pint              ws_id,
    Pint              item_type,
    Pint              item_data_length,
    const Pitem_data  *item_data
);

extern void pget_item_type(
    Pint            ws_id,
    Pint            *item_type,
    Pint            *item_data_length
);

extern void pread_item(
    Pint            ws_id,
    Pint            max_item_data_length,
    Pitem_data      *item_data
);

extern void pinterpret_item(
    Pint              type,
    Pint              item_data_length,
    const Pitem_data  *item_data
);

extern void pinq_sys_st(
    Psys_st         *sys_st
);

extern void pinq_ws_st(
    Pws_st          *ws_st
);

extern void pinq_struct_st(
    Pstruct_st      *struct_st
);

extern void pinq_ar_st(
    Par_st          *ar_st
);

extern void pinq_list_avail_ws_types(
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *types,
    Pint            *num_elems_impl_list
);

extern void pinq_phigs_facs(
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint            *max_open_ws,
    Pint            *max_open_ar,
    Pint            *num_avail_names,
    Pint_list       *char_sets,
    Pint            *num_elems_impl_list,
    Pint            *iss_norm_max,
    Pint            *iss_inv_max
);

extern void pinq_gse_facs(
    Pint               num_elems_appl_list,
    Pint               start_ind,
    Pint               *err_ind,
    Pgse_id_dep_list   *gse,
    Pint               *num_elems_impl_list
);

extern void pinq_model_clip_facs(
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint            *num_planes,
    Pint_list       *ops,
    Pint            *num_elems_impl_list
);

extern void pinq_edit_mode(
    Pint            *err_ind,
    Pedit_mode      *edit_mode
);

extern void pinq_open_wss(
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *open_ws_ids,
    Pint            *num_elems_impl_list
);

extern void pinq_struct_ids(
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *struct_ids,
    Pint            *num_elems_impl_list
);

extern void pinq_ar_files(
    Pstore          store,
    Pint            *err_ind,
    Par_file_list   **ar_files
);

extern void pinq_conf_res(
    Pint            *err_ind,
    Pconf_res       *archive_res,
    Pconf_res       *retrieve_res
);

extern void pinq_all_conf_structs(
    Pint            ar_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *ids,
    Pint            *num_elems_impl_list
);

extern void pinq_conf_structs_net(
    Pint                 ar_id,
    Pint                 struct_id,
    Pstruct_net_source   source,
    Pint                 num_elems_appl_list,
    Pint                 start_ind,
    Pint                 *err_ind,
    Pint_list            *ids,
    Pint                 *num_elems_impl_list
);

extern void pinq_more_simult_events(
    Pint                 *err_ind,
    Pmore_simult_events  *simult_events
);

extern void pinq_ws_conn_type(
    Pint            ws_id,
    Pstore          store,
    Pint            *err_ind,
    void            **conn_id,
    Pint            *ws_type
);

extern void pinq_list_view_inds(
    Pint            ws_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *view_inds,
    Pint            *num_elems_impl_list
);

extern void pinq_view_rep(
    Pint            ws_id,
    Pint            view_ind,
    Pint            *err_ind,
    Pupd_st         *upd_st,
    Pview_rep3      *cur_view,
    Pview_rep3      *req_view
);

extern void pinq_hlhsr_mode(
    Pint            ws_id,
    Pint            *err_ind,
    Pupd_st         *upd_st,
    Pint            *cur_mode,
    Pint            *req_mode
);

extern void pinq_posted_structs(
    Pint                 ws_id,
    Pint                 num_elems_appl_list,
    Pint                 start_ind,
    Pint                 *err_ind,
    Pposted_struct_list  *struct_ids,
    Pint                 *num_elems_impl_list
);

extern void pinq_disp_upd_st(
    Pint                 ws_id,
    Pint                 *err_ind,
    Pdefer_mode          *def_mode,
    Pmod_mode            *mod_mode,
    Pdisp_surf_empty     *disp_surf_empty,
    Pvisual_st           *vis_st
);

extern void pinq_list_line_inds(
    Pint            ws_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *def_line_ind,
    Pint            *num_elems_impl_list
);

extern void pinq_line_rep(
    Pint            ws_id,
    Pint            index,
    Pinq_type       type,
    Pint            *err_ind,
    Pline_bundle    *line_rep
);

extern void pinq_list_marker_inds(
    Pint            ws_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *def_marker_ind,
    Pint            *num_elems_impl_list
);

extern void pinq_marker_rep(
    Pint            ws_id,
    Pint            index,
    Pinq_type       type,
    Pint            *err_ind,
    Pmarker_bundle  *marker_rep
);

extern void pinq_list_text_inds(
    Pint            ws_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *def_text_ind,
    Pint            *num_elems_impl_list
);

extern void pinq_text_rep(
    Pint            ws_id,
    Pint            index,
    Pinq_type       type,
    Pint            *err_ind,
    Ptext_bundle    *text_rep
);

extern void pinq_list_int_inds(
    Pint            ws_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *def_int_ind,
    Pint            *num_elems_impl_list
);

extern void pinq_int_rep(
    Pint            ws_id,
    Pint            index,
    Pinq_type       type,
    Pint            *err_ind,
    Pint_bundle     *int_rep
);

extern void pinq_list_edge_inds(
    Pint            ws_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *def_edge_ind,
    Pint            *num_elems_impl_list
);

extern void pinq_edge_rep(
    Pint            ws_id,
    Pint            index,
    Pinq_type       type,
    Pint            *err_ind,
    Pedge_bundle    *edge_rep
);

extern void pinq_list_pat_inds(
    Pint            ws_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *def_pat_ind,
    Pint            *num_elems_impl_list
);

extern void pinq_pat_rep(
    Pint            ws_id,
    Pint            index,
    Pinq_type       type,
    Pstore          store,
    Pint            *err_ind,
    Ppat_rep        **pat_rep
);

extern void pinq_colr_model(
    Pint            ws_id,
    Pint            *err_ind,
    Pint            *model
);

extern void pinq_list_colr_inds(
    Pint            ws_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *colr_ind,
    Pint            *num_elems_impl_list
);

extern void pinq_colr_rep(
    Pint            ws_id,
    Pint            colr_ind,
    Pinq_type       type,
    Pint            *err_ind,
    Pcolr_rep       *colr_rep
);

extern void pinq_highl_filter(
    Pint            ws_id,
    Pstore          store,
    Pint            *err_ind,
    Pfilter         **highl_filter
);

extern void pinq_invis_filter(
    Pint            ws_id,
    Pstore          store,
    Pint            *err_ind,
    Pfilter         **invis_filter
);

extern void pinq_ws_tran3(
    Pint            ws_id,
    Pint            *err_ind,
    Pupd_st         *upd_st,
    Plimit3         *req_win_lim,
    Plimit3         *cur_win_lim,
    Plimit3         *req_vp_lim,
    Plimit3         *cur_vp_lim
);

extern void pinq_ws_tran(
    Pint            ws_id,
    Pint            *err_ind,
    Pupd_st         *upd_st,
    Plimit          *req_win_lim,
    Plimit          *cur_win_lim,
    Plimit          *req_vp_lim,
    Plimit          *cur_vp_lim
);

extern void pinq_loc_st3(
    Pint            ws_id,
    Pint            loc_num,
    Pinq_type       type,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pint            *init_view_ind,
    Ppoint3         *init_loc_pos,
    Pint            *prompt_echo,
    Plimit3         *echo_vol,
    Ploc_data3      **loc_data
);

extern void pinq_loc_st(
    Pint            ws_id,
    Pint            loc_num,
    Pinq_type       type,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pint            *init_view_ind,
    Ppoint          *init_loc_pos,
    Pint            *prompt_echo,
    Plimit          *echo_area,
    Ploc_data       **loc_data
);

extern void pinq_stroke_st3(
    Pint            ws_id,
    Pint            stroke_num,
    Pinq_type       type,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pint            *init_view_ind,
    Ppoint_list3    **init_stroke,
    Pint            *prompt_echo,
    Plimit3         *echo_vol,
    Pstroke_data3   **stroke_data
);

extern void pinq_stroke_st(
    Pint            ws_id,
    Pint            stroke_num,
    Pinq_type       type,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pint            *init_view_ind,
    Ppoint_list     **init_stroke,
    Pint            *prompt_echo,
    Plimit          *echo_area,
    Pstroke_data    **stroke_data
);

extern void pinq_val_st3(
    Pint            ws_id,
    Pint            val_num,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pfloat          *init_value,
    Pint            *prompt_echo,
    Plimit3         *echo_vol,
    Pval_data3      **val_data
);

extern void pinq_val_st(
    Pint            ws_id,
    Pint            val_num,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pfloat          *init_value,
    Pint            *prompt_echo,
    Plimit          *echo_area,
    Pval_data       **val_data
);

extern void pinq_choice_st3(
    Pint            ws_id,
    Pint            choice_num,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pin_status      *init_status,
    Pint            *init_choice,
    Pint            *prompt_echo,
    Plimit3         *echo_vol,
    Pchoice_data3   **choice_data
);

extern void pinq_choice_st(
    Pint            ws_id,
    Pint            choice_num,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pin_status      *init_status,
    Pint            *init_choice,
    Pint            *prompt_echo,
    Plimit          *echo_area,
    Pchoice_data    **choice_data
);

extern void pinq_pick_st3(
    Pint            ws_id,
    Pint            pick_num,
    Pinq_type       type,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pfilter         **pick_filter,
    Pin_status      *init_status,
    Ppick_path      **init_pick,
    Pint            *prompt_echo,
    Plimit3         *echo_vol,
    Ppick_data3     **pick_data,
    Ppath_order     *order
);

extern void pinq_pick_st(
    Pint            ws_id,
    Pint            pick_num,
    Pinq_type       type,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    Pfilter         **pick_filter,
    Pin_status      *init_status,
    Ppick_path      **init_pick,
    Pint            *prompt_echo,
    Plimit          *echo_area,
    Ppick_data      **pick_data,
    Ppath_order     *order
);

extern void pinq_string_st3(
    Pint            ws_id,
    Pint            string_num,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    char            **init_string,
    Pint            *prompt_echo,
    Plimit3         *echo_vol,
    Pstring_data3   **string_data
);

extern void pinq_string_st(
    Pint            ws_id,
    Pint            string_num,
    Pstore          store,
    Pint            *err_ind,
    Pop_mode        *op_mode,
    Pecho_switch    *echo_switch,
    char            **init_string,
    Pint            *prompt_echo,
    Plimit          *echo_area,
    Pstring_data    **string_data
);

extern void pinq_ws_cat(
    Pint            ws_type,
    Pint            *err_ind,
    Pws_cat         *cat
);

extern void pinq_disp_space_size3(
    Pint                ws_type,
    Pint                *err_ind,
    Pdisp_space_size3   *size
);

extern void pinq_disp_space_size(
    Pint                ws_type,
    Pint                *err_ind,
    Pdisp_space_size    *size
);

extern void pinq_hlhsr_id_facs(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *hlhsr_ids,
    Pint            *num_elems_impl_list
);

extern void pinq_hlhsr_mode_facs(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *hlhsr_modes,
    Pint            *num_elems_impl_list
);

extern void pinq_view_facs(
    Pint            ws_type,
    Pint            *err_ind,
    Pint            *num_view_ind
);

extern void pinq_pred_view_rep(
    Pint            ws_type,
    Pint            index,
    Pint            *err_ind,
    Pview_rep3      *view
);

extern void pinq_ws_class(
    Pint            ws_type,
    Pint            *err_ind,
    Pws_class       *ws_class
);

extern void pinq_dyns_ws_attrs(
    Pint            ws_type,
    Pint            *err_ind,
    Pdyns_ws_attrs  *attr
);

extern void pinq_def_disp_upd_st(
    Pint            ws_type,
    Pint            *err_ind,
    Pdefer_mode     *def_mode,
    Pmod_mode       *mod_mode
);

extern void pinq_line_facs(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pline_facs      *fac,
    Pint            *num_elems_impl_list
);

extern void pinq_pred_line_rep(
    Pint            ws_type,
    Pint            index,
    Pint            *err_ind,
    Pline_bundle    *bundle
);

extern void pinq_marker_facs(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pmarker_facs    *fac,
    Pint            *num_elems_impl_list
);

extern void pinq_pred_marker_rep(
    Pint            ws_type,
    Pint            index,
    Pint            *err_ind,
    Pmarker_bundle  *bundle
);

extern void pinq_text_facs(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Ptext_facs      *fac,
    Pint            *num_elems_impl_list
);

extern void pinq_pred_text_rep(
    Pint            ws_type,
    Pint            index,
    Pint            *err_ind,
    Ptext_bundle    *bundle
);

extern void pinq_anno_facs(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *styles,
    Pint            *num_elems_impl_list,
    Pint            *num_anno_char_hts,
    Pfloat          *min_anno_char_ht,
    Pfloat          *max_anno_char_ht
);

extern void pinq_text_extent(
    Pint                ws_type,
    Pint                text_font,
    Pfloat              char_expan,
    Pfloat              char_space,
    Pfloat              char_ht,
    Ptext_path          text_path,
    Phor_text_align     hor_text_align,
    Pvert_text_align    ver_text_align,
    const char          *char_string,
    Pint                *err_ind,
    Prect               *rect,
    Ppoint              *offset
);

extern void pinq_int_facs(
    Pint            ws_type,
    Pint            hatch_num_elems_appl_length,
    Pint            hatch_start_ind,
    Pint            *err_ind,
    Pint_facs       *int_facs,
    Pint            *hatch_num_elems_impl_list
);

extern void pinq_pred_int_rep(
    Pint            ws_type,
    Pint            index,
    Pint            *err_ind,
    Pint_bundle     *bundle
);

extern void pinq_edge_facs(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pedge_facs      *fac,
    Pint            *num_elems_impl_list
);

extern void pinq_pred_edge_rep(
    Pint            ws_type,
    Pint            index,
    Pint            *err_ind,
    Pedge_bundle    *bundle
);

extern void pinq_pat_facs(
    Pint            ws_type,
    Pint            *err_ind,
    Pint            *num_pred
);

extern void pinq_pred_pat_rep(
    Pint            ws_type,
    Pint            index,
    Pstore          store,
    Pint            *err_ind,
    Ppat_rep        **pat_rep
);

extern void pinq_colr_model_facs(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *models,
    Pint            *num_elems_impl_list,
    Pint            *def
);

extern void pinq_colr_facs(
    Pint            ws_type,
    Pint            *err_ind,
    Pcolr_facs      *fac
);

extern void pinq_pred_colr_rep(
    Pint            ws_type,
    Pint            colr_ind,
    Pint            *err_ind,
    Pcolr_rep       *colr_rep
);

extern void pinq_list_avail_gdp3(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *gdps,
    Pint            *num_elems_impl_list
);

extern void pinq_list_avail_gdp(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *gdps,
    Pint            *num_elems_impl_list
);

extern void pinq_gdp3(
    Pint            ws_type,
    Pint            gdp,
    Pint            *err_ind,
    Pint            *num_attr,
    Pattrs          attr[{IMPL-DEP}]
);

extern void pinq_gdp(
    Pint            ws_type,
    Pint            gdp,
    Pint            *err_ind,
    Pint            *num_attr,
    Pattrs          attr[{IMPL-DEP}]
);

extern void pinq_list_avail_gse(
    Pint            ws_type,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *gses,
    Pint            *num_elems_impl_list
);

extern void pinq_num_disp_pris(
    Pint            ws_type,
    Pint            *err_ind,
    Pint            *num_pri
);

extern void pinq_ws_st_table(
    Pint            ws_type,
    Pint            *err_ind,
    Pws_st_tables   *lengths
);

extern void pinq_dyns_structs(
    Pint            ws_type,
    Pint            *err_ind,
    Pdyns_structs   *dyns
);

extern void pinq_num_avail_in(
    Pint            ws_type,
    Pint            *err_ind,
    Pnum_in         *num_in
);

extern void pinq_def_loc_data3(
    Pint            ws_type,
    Pint            loc_num,
    Pstore          store,
    Pint            *err_ind,
    Ppoint3         *loc_pos,
    Pint_list       **pet_list,
    Plimit3         *echo_vol,
    Ploc_data3      **loc_data
);

extern void pinq_def_loc_data(
    Pint            ws_type,
    Pint            loc_num,
    Pstore          store,
    Pint            *err_ind,
    Ppoint          *loc_pos,
    Pint_list       **pet_list,
    Plimit          *echo_area,
    Ploc_data       **loc_data
);

extern void pinq_def_stroke_data3(
    Pint            ws_type,
    Pint            stroke_num,
    Pstore          store,
    Pint            *err_ind,
    Pint            *max_buf_size,
    Pint_list       **pet_list,
    Plimit3         *echo_vol,
    Pstroke_data3   **stroke_data
);

extern void pinq_def_stroke_data(
    Pint            ws_type,
    Pint            stroke_num,
    Pstore          store,
    Pint            *err_ind,
    Pint            *max_buf_size,
    Pint_list       **pet_list,
    Plimit          *echo_area,
    Pstroke_data    **stroke_data
);

extern void pinq_def_val_data3(
    Pint            ws_type,
    Pint            val_num,
    Pstore          store,
    Pint            *err_ind,
    Pfloat          *def_value,
    Pint_list       **pet_list,
    Plimit3         *echo_vol,
    Pval_data3      **val_data
);

extern void pinq_def_val_data(
    Pint            ws_type,
    Pint            val_num,
    Pstore          store,
    Pint            *err_ind,
    Pfloat          *def_value,
    Pint_list       **pet_list,
    Plimit          *echo_area,
    Pval_data       **val_data
);

extern void pinq_def_choice_data3(
    Pint            ws_type,
    Pint            choice_num,
    Pstore          store,
    Pint            *err_ind,
    Pint            *max_choices,
    Pint_list       **pet_list,
    Plimit3         *echo_vol,
    Pchoice_data3   **choice_data
);

extern void pinq_def_choice_data(
    Pint            ws_type,
    Pint            choice_num,
    Pstore          store,
    Pint            *err_ind,
    Pint            *max_choices,
    Pint_list       **pet_list,
    Plimit          *echo_area,
    Pchoice_data    **choice_data
);

extern void pinq_def_pick_data3(
    Pint            ws_type,
    Pint            pick_num,
    Pstore          store,
    Pint            *err_ind,
    Pint_list       **pet_list,
    Plimit3         *echo_vol,
    Ppick_data3     **pick_data
);

extern void pinq_def_pick_data(
    Pint            ws_type,
    Pint            pick_num,
    Pstore          store,
    Pint            *err_ind,
    Pint_list       **pet_list,
    Plimit          *echo_area,
    Ppick_data      **pick_data
);

extern void pinq_def_string_data3(
    Pint            ws_type,
    Pint            string_num,
    Pstore          store,
    Pint            *err_ind,
    Pint            *max_buf_size,
    Pint_list       **pet_list,
    Plimit3         *echo_vol,
    Pstring_data3   **string_data
);

extern void pinq_def_string_data(
    Pint            ws_type,
    Pint            string_num,
    Pstore          store,
    Pint            *err_ind,
    Pint            *max_buf_size,
    Pint_list       **pet_list,
    Plimit          *echo_area,
    Pstring_data    **string_data
);

extern void pinq_wss_posted(
    Pint            struct_id,
    Pint            num_elems_appl_list,
    Pint            start_ind,
    Pint            *err_ind,
    Pint_list       *ws,
    Pint            *num_elems_impl_list
);

extern void pinq_open_struct(
    Pint                 *err_ind,
    Popen_struct_status  *status,
    Pint                 *struct_id
);

extern void pinq_elem_ptr(
    Pint            *err_ind,
    Pint            *elem_ptr_value
);

extern void pinq_cur_elem_type_size(
    Pint            *err_ind,
    Pelem_type      *elem_type,
    size_t          *elem_size
);

extern void pinq_cur_elem_content(
    Pstore          store,
    Pint            *err_ind,
    Pelem_data      **elem_data
);

extern void pinq_elem_type_size(
    Pint            struct_id,
    Pint            elem_num,
    Pint            *err_ind,
    Pelem_type      *elem_type,
    size_t          *elem_size
);

extern void pinq_elem_content(
    Pint            struct_id,
    Pint            elem_num,
    Pstore          store,
    Pint            *err_ind,
    Pelem_data      **elem_data
);

extern void pinq_struct_status(
    Pint            struct_id,
    Pint            *err_ind,
    Pstruct_status  *status
);

extern void pinq_paths_ances(
    Pint                 struct_id,
    Ppath_order          order,
    Pint                 depth,
    Pstore               store,
    Pint                 *err_ind,
    Pelem_ref_list_list  **paths
);

extern void pinq_paths_descs(
    Pint                 struct_id,
    Ppath_order          order,
    Pint                 depth,
    Pstore               store,
    Pint                 *err_ind,
    Pelem_ref_list_list  **paths
);

extern void pelem_search(
    Pint                   struct_id,
    Pint                   start_elem,
    Psearch_dir            dir,
    const Pelem_type_list  *incl,
    const Pelem_type_list  *excl,
    Pint                   *err_ind,
    Psearch_status         *status,
    Pint                   *found_elem_ptr
);

extern void pincr_spa_search3(
    const Ppoint3          *ref_pt,
    Pfloat                 dist,
    const Pelem_ref_list   *sp,
    Pclip_ind              clip_ind,
    Pint                   ceiling,
    const Pfilter_list     *norm,
    const Pfilter_list     *inv,
    Pint                   num_elems_appl_list,
    Pint                   start_ind,
    Pint                   *err_ind,
    Pelem_ref_list         *fp,
    Pint                   *num_elems_impl_list
);

extern void pincr_spa_search(
    const Ppoint           *ref_pt,
    Pfloat                 dist,
    const Pelem_ref_list   *sp,
    Pclip_ind              clip_ind,
    Pint                   ceiling,
    const Pfilter_list     *norm,
    const Pfilter_list     *inv,
    Pint                   num_elems_appl_list,
    Pint                   start_ind,
    Pint                   *err_ind,
    Pelem_ref_list         *fp,
    Pint                   *num_elems_impl_list
);

extern void pinq_in_overf(
    Pint            *err_ind,
    Pint            *ws_id,
    Pin_class       *in_class,
    Pint            *in_num
);

extern void pinq_err_hand_mode(
    Pint            *err_ind,
    Perr_mode       *err_mode
);

extern void pemergency_close_phigs(
    void
);

extern void perr_hand(
    Pint            error_num,
    Pint            func_num,
    const char      *error_file
);

extern void perr_log(
    Pint            error_num,
    Pint            func_num,
    const char      *error_file
);

extern void pset_err_hand_mode(
    Perr_mode       error_mode
);

extern void pescape(
    Pint                   func_id,
    const Pescape_in_data  *in_data,
    Pstore                 store,
    Pescape_out_data       **out_data
);

extern void pset_err_hand(
    void            (*new_err_hand)(),
    void            (**old_err_hand)()
);

extern void pcreate_store(
    Pint            *err_ind,
    Pstore          *store
);

extern void pdel_store(
    Pint            *err_ind,
    Pstore          *store
);

/*** *** *** *** *** *** *** *** *** *** *** *** *** *** ***/

/***               end standard functions                ***/

/*** *** *** *** *** *** *** *** *** *** *** *** *** *** ***/
