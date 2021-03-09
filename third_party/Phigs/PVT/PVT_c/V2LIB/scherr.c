/* scherr.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__111 = 111;
static integer c__2 = 2;

#ifndef NO_PROTO
/* Subroutine */ int scherr_(integer *errnum, char *errmsg, ftnlen errmsg_len)

#else /* NO_PROTO */
/* Subroutine */ int scherr_(errnum, errmsg, errmsg_len)
integer *errnum;
char *errmsg;
ftnlen errmsg_len;
#endif /* NO_PROTO */
{
    /* Initialized data */

    static integer stdnum[111] = { 1,2,3,4,5,6,7,50,51,52,53,54,55,56,57,58,
	    59,60,61,62,63,64,100,101,102,103,104,105,106,107,108,109,110,111,
	    112,113,114,115,116,117,118,150,151,152,153,154,155,156,157,158,
	    159,160,161,162,163,164,200,201,202,203,204,205,206,207,208,250,
	    251,252,253,254,255,256,257,258,259,260,261,262,263,300,301,302,
	    303,304,305,306,307,350,351,400,401,402,403,404,405,406,407,408,
	    450,2000,2001,2002,2003,2004,2005,2006,2200,2201,2202,2203,2204 };


    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy(), s_cat();
    integer s_cmp();
#endif /* NO_PROTO */

    /* Local variables */
    static integer msgdx;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static char stdmsg[180];

/*  SCHERR accepts a valid error code and returns the standard */
/*  corresponding error message. */

/*  Input parameter: */
/*    ERRNUM: Standard error code */
/*  Output parameter: */
/*    ERRMSG: Wording of corresponding standard error message */
/*  List of standard error codes */
    msgdx = iarfnd_(errnum, &c__111, stdnum);
    if (msgdx < 1) {
	unmsg_("SCHERR called with invalid ERRNUM.", 34L);
    }
#ifndef NO_PROTO
    switch (msgdx) {
#else /* NO_PROTO */
    switch ((int)msgdx) {
#endif /* NO_PROTO */
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L10;
	case 11:  goto L11;
	case 12:  goto L12;
	case 13:  goto L13;
	case 14:  goto L14;
	case 15:  goto L15;
	case 16:  goto L16;
	case 17:  goto L17;
	case 18:  goto L18;
	case 19:  goto L19;
	case 20:  goto L20;
	case 21:  goto L21;
	case 22:  goto L22;
	case 23:  goto L23;
	case 24:  goto L24;
	case 25:  goto L25;
	case 26:  goto L26;
	case 27:  goto L27;
	case 28:  goto L28;
	case 29:  goto L29;
	case 30:  goto L30;
	case 31:  goto L31;
	case 32:  goto L32;
	case 33:  goto L33;
	case 34:  goto L34;
	case 35:  goto L35;
	case 36:  goto L36;
	case 37:  goto L37;
	case 38:  goto L38;
	case 39:  goto L39;
	case 40:  goto L40;
	case 41:  goto L41;
	case 42:  goto L42;
	case 43:  goto L43;
	case 44:  goto L44;
	case 45:  goto L45;
	case 46:  goto L46;
	case 47:  goto L47;
	case 48:  goto L48;
	case 49:  goto L49;
	case 50:  goto L50;
	case 51:  goto L51;
	case 52:  goto L52;
	case 53:  goto L53;
	case 54:  goto L54;
	case 55:  goto L55;
	case 56:  goto L56;
	case 57:  goto L57;
	case 58:  goto L58;
	case 59:  goto L59;
	case 60:  goto L60;
	case 61:  goto L61;
	case 62:  goto L62;
	case 63:  goto L63;
	case 64:  goto L64;
	case 65:  goto L65;
	case 66:  goto L66;
	case 67:  goto L67;
	case 68:  goto L68;
	case 69:  goto L69;
	case 70:  goto L70;
	case 71:  goto L71;
	case 72:  goto L72;
	case 73:  goto L73;
	case 74:  goto L74;
	case 75:  goto L75;
	case 76:  goto L76;
	case 77:  goto L77;
	case 78:  goto L78;
	case 79:  goto L79;
	case 80:  goto L80;
	case 81:  goto L81;
	case 82:  goto L82;
	case 83:  goto L83;
	case 84:  goto L84;
	case 85:  goto L85;
	case 86:  goto L86;
	case 87:  goto L87;
	case 88:  goto L88;
	case 89:  goto L89;
	case 90:  goto L90;
	case 91:  goto L91;
	case 92:  goto L92;
	case 93:  goto L93;
	case 94:  goto L94;
	case 95:  goto L95;
	case 96:  goto L96;
	case 97:  goto L97;
	case 98:  goto L98;
	case 99:  goto L99;
	case 100:  goto L2000;
	case 101:  goto L2001;
	case 102:  goto L2002;
	case 103:  goto L2003;
	case 104:  goto L2004;
	case 105:  goto L2005;
	case 106:  goto L2006;
	case 107:  goto L2200;
	case 108:  goto L2201;
	case 109:  goto L2202;
	case 110:  goto L2203;
	case 111:  goto L2204;
    }
    unmsg_("SCHERR called with very invalid ERRNUM.", 39L);
/*  List of standard error messages */
L1:
    s_copy(stdmsg, "(PHCL,WSCL,STCL,ARCL)", 180L, 21L);
    goto L101;
L2:
    s_copy(stdmsg, "(PHOP,*,*,*)", 180L, 12L);
    goto L101;
L3:
    s_copy(stdmsg, "(PHOP,WSOP,*,*)", 180L, 15L);
    goto L101;
L4:
    s_copy(stdmsg, "(PHOP,WSCL,STCL,ARCL)", 180L, 21L);
    goto L101;
L5:
    s_copy(stdmsg, "(PHOP,*,STOP,*)", 180L, 15L);
    goto L101;
L6:
    s_copy(stdmsg, "(PHOP,*,STCL,*)", 180L, 15L);
    goto L101;
L7:
    s_copy(stdmsg, "(PHOP,*,*,AROP)", 180L, 15L);
    goto L101;
L8:
#ifndef NO_PROTO
    s_copy(stdmsg, "connection identifier not recognized by the implementati"
	    "on", 180L, 58L);
#else /* NO_PROTO */
    s_copy(stdmsg, "connection identifier not recognized by the implementati\
on", 180L, 58L);
#endif /* NO_PROTO */
    goto L101;
L9:
#ifndef NO_PROTO
    s_copy(stdmsg, "this information is not yet available for this generic w"
	    "orkstation type; open a workstation of this type and use the spe"
	    "cific workstation type", 180L, 142L);
#else /* NO_PROTO */
    s_copy(stdmsg, "this information is not yet available for this generic w\
orkstation type; open a workstation of this type and use the specific workst\
ation type", 180L, 142L);
#endif /* NO_PROTO */
    goto L101;
L10:
    s_copy(stdmsg, "workstation type not recognized by the implementation", 
	    180L, 53L);
    goto L101;
L11:
    s_copy(stdmsg, "workstation identifier already is in use", 180L, 40L);
    goto L101;
L12:
    s_copy(stdmsg, "the specified workstation is not open", 180L, 37L);
    goto L101;
L13:
#ifndef NO_PROTO
    s_copy(stdmsg, "workstation cannot be opened for an implementation depen"
	    "dent reason", 180L, 67L);
#else /* NO_PROTO */
    s_copy(stdmsg, "workstation cannot be opened for an implementation depen\
dent reason", 180L, 67L);
#endif /* NO_PROTO */
    goto L101;
L14:
    s_copy(stdmsg, "specified workstation is not of category MO", 180L, 43L);
    goto L101;
L15:
    s_copy(stdmsg, "specified workstation is of category MI", 180L, 39L);
    goto L101;
L16:
    s_copy(stdmsg, "specified workstation is not of category MI", 180L, 43L);
    goto L101;
L17:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified workstation does not have output capabilit"
	    "y (i.e., the workstation category is neither OUTPUT, OUTIN, nor "
	    "MO)", 180L, 123L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified workstation does not have output capabilit\
y (i.e., the workstation category is neither OUTPUT, OUTIN, nor MO)", 180L, 
	    123L);
#endif /* NO_PROTO */
    goto L101;
L18:
    s_copy(stdmsg, "specified workstation is not of category OUTIN", 180L, 
	    46L);
    goto L101;
L19:
#ifndef NO_PROTO
    s_copy(stdmsg, "specified workstation is neither of category INPUT nor o"
	    "f category OUTIN", 180L, 72L);
#else /* NO_PROTO */
    s_copy(stdmsg, "specified workstation is neither of category INPUT nor o\
f category OUTIN", 180L, 72L);
#endif /* NO_PROTO */
    goto L101;
L20:
#ifndef NO_PROTO
    s_copy(stdmsg, "this information is not available for this MO workstatio"
	    "n type", 180L, 62L);
#else /* NO_PROTO */
    s_copy(stdmsg, "this information is not available for this MO workstatio\
n type", 180L, 62L);
#endif /* NO_PROTO */
    goto L101;
L21:
#ifndef NO_PROTO
    s_copy(stdmsg, "opening this workstation would exceed the maximum number"
	    " of simultaneously open workstations", 180L, 92L);
#else /* NO_PROTO */
    s_copy(stdmsg, "opening this workstation would exceed the maximum number\
 of simultaneously open workstations", 180L, 92L);
#endif /* NO_PROTO */
    goto L101;
L22:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified workstation type is not able to generate t"
	    "he specified GDP", 180L, 72L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified workstation type is not able to generate t\
he specified GDP", 180L, 72L);
#endif /* NO_PROTO */
    goto L101;
L23:
    s_copy(stdmsg, "the bundle index value is less than one", 180L, 39L);
    goto L101;
L24:
    s_copy(stdmsg, "the specified representation has not been defined", 180L, 
	    49L);
    goto L101;
L25:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified representation has not been predefined on "
	    "this workstation", 180L, 72L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified representation has not been predefined on \
this workstation", 180L, 72L);
#endif /* NO_PROTO */
    goto L101;
L26:
#ifndef NO_PROTO
    s_copy(stdmsg, "setting this bundle table entry would exceed the maximum"
	    " number of entries allowed in the workstation bundle table", 180L,
	     114L);
#else /* NO_PROTO */
    s_copy(stdmsg, "setting this bundle table entry would exceed the maximum\
 number of entries allowed in the workstation bundle table", 180L, 114L);
#endif /* NO_PROTO */
    goto L101;
L27:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified linetype is not available on the specified"
	    " workstation", 180L, 68L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified linetype is not available on the specified\
 workstation", 180L, 68L);
#endif /* NO_PROTO */
    goto L101;
L28:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified marker type is not available on the specif"
	    "ied workstation", 180L, 71L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified marker type is not available on the specif\
ied workstation", 180L, 71L);
#endif /* NO_PROTO */
    goto L101;
L29:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified font is not available for the requested te"
	    "xt precision on the specified workstation", 180L, 97L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified font is not available for the requested te\
xt precision on the specified workstation", 180L, 97L);
#endif /* NO_PROTO */
    goto L101;
L30:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified edgetype is not available on the specified"
	    " workstation", 180L, 68L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified edgetype is not available on the specified\
 workstation", 180L, 68L);
#endif /* NO_PROTO */
    goto L101;
L31:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified interior style is not available on the wor"
	    "kstation", 180L, 64L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified interior style is not available on the wor\
kstation", 180L, 64L);
#endif /* NO_PROTO */
    goto L101;
L32:
#ifndef NO_PROTO
    s_copy(stdmsg, "interior style PATTERN is not suppported on the workstat"
	    "ion", 180L, 59L);
#else /* NO_PROTO */
    s_copy(stdmsg, "interior style PATTERN is not suppported on the workstat\
ion", 180L, 59L);
#endif /* NO_PROTO */
    goto L101;
L33:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified colour model is not available on the works"
	    "tation", 180L, 62L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified colour model is not available on the works\
tation", 180L, 62L);
#endif /* NO_PROTO */
    goto L101;
L34:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified HLHSR model is not available on the specif"
	    "ied workstation", 180L, 71L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified HLHSR model is not available on the specif\
ied workstation", 180L, 71L);
#endif /* NO_PROTO */
    goto L101;
L35:
    s_copy(stdmsg, "the pattern index value is less than one", 180L, 40L);
    goto L101;
L36:
    s_copy(stdmsg, "the colour index value is less than zero", 180L, 40L);
    goto L101;
L37:
    s_copy(stdmsg, "the view index value is less than zero", 180L, 38L);
    goto L101;
L38:
    s_copy(stdmsg, "the view index value is less than one", 180L, 37L);
    goto L101;
L39:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the dimensions of pattern colour index array is l"
	    "ess than one", 180L, 68L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the dimensions of pattern colour index array is l\
ess than one", 180L, 68L);
#endif /* NO_PROTO */
    goto L101;
L40:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the dimensions of the colour index array is less "
	    "than zero", 180L, 65L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the dimensions of the colour index array is less \
than zero", 180L, 65L);
#endif /* NO_PROTO */
    goto L101;
L41:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the components of the colour specification is out"
	    " of range.  The valid range is dependent upon the current colour"
	    " model", 180L, 126L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the components of the colour specification is out\
 of range.  The valid range is dependent upon the current colour model", 180L,
	     126L);
#endif /* NO_PROTO */
    goto L101;
L42:
#ifndef NO_PROTO
    s_copy(stdmsg, "setting this view table entry would exceed the maximum n"
	    "umber of entries allowed in the workstation view table", 180L, 
	    110L);
#else /* NO_PROTO */
    s_copy(stdmsg, "setting this view table entry would exceed the maximum n\
umber of entries allowed in the workstation view table", 180L, 110L);
#endif /* NO_PROTO */
    goto L101;
L43:
#ifndef NO_PROTO
    s_copy(stdmsg, "invalid window: XMIN>=XMAX, YMIN>=YMAX, ZMIN>ZMAX, UMIN>"
	    "=UMAX or VMIN>=VMAX", 180L, 75L);
#else /* NO_PROTO */
    s_copy(stdmsg, "invalid window: XMIN>=XMAX, YMIN>=YMAX, ZMIN>ZMAX, UMIN>\
=UMAX or VMIN>=VMAX", 180L, 75L);
#endif /* NO_PROTO */
    goto L101;
L44:
    s_copy(stdmsg, "invalid viewport: XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX", 
	    180L, 54L);
    goto L101;
L45:
#ifndef NO_PROTO
    s_copy(stdmsg, "invalid view clipping limits: XMIN>=XMAX, YMIN>=YMAX or "
	    "ZMIN>ZMAX", 180L, 65L);
#else /* NO_PROTO */
    s_copy(stdmsg, "invalid view clipping limits: XMIN>=XMAX, YMIN>=YMAX or \
ZMIN>ZMAX", 180L, 65L);
#endif /* NO_PROTO */
    goto L101;
L46:
    s_copy(stdmsg, "the view clipping limits are not within NPC range", 180L, 
	    49L);
    goto L101;
L47:
    s_copy(stdmsg, "the projection viewport limits are not within NPC range", 
	    180L, 55L);
    goto L101;
L48:
    s_copy(stdmsg, "the workstation window limits are not within NPC range", 
	    180L, 54L);
    goto L101;
L49:
    s_copy(stdmsg, "the workstation viewport is not within display space", 
	    180L, 52L);
    goto L101;
L50:
#ifndef NO_PROTO
    s_copy(stdmsg, "front plane and back plane distances are equal when z-ex"
	    "tent of the projection viewport is non-zero", 180L, 99L);
#else /* NO_PROTO */
    s_copy(stdmsg, "front plane and back plane distances are equal when z-ex\
tent of the projection viewport is non-zero", 180L, 99L);
#endif /* NO_PROTO */
    goto L101;
L51:
    s_copy(stdmsg, "the view plane normal vector has length zero", 180L, 44L);

    goto L101;
L52:
    s_copy(stdmsg, "the view up vector has length zero", 180L, 34L);
    goto L101;
L53:
#ifndef NO_PROTO
    s_copy(stdmsg, "the view up and view plane normal vectors are parallel t"
	    "hus the viewing coordinate system cannot be established", 180L, 
	    111L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the view up and view plane normal vectors are parallel t\
hus the viewing coordinate system cannot be established", 180L, 111L);
#endif /* NO_PROTO */
    goto L101;
L54:
#ifndef NO_PROTO
    s_copy(stdmsg, "the projection reference point is between the front and "
	    "back planes", 180L, 67L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the projection reference point is between the front and \
back planes", 180L, 67L);
#endif /* NO_PROTO */
    goto L101;
L55:
#ifndef NO_PROTO
    s_copy(stdmsg, "the projection reference point cannot be positioned on t"
	    "he view plane", 180L, 69L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the projection reference point cannot be positioned on t\
he view plane", 180L, 69L);
#endif /* NO_PROTO */
    goto L101;
L56:
    s_copy(stdmsg, "the back plane is in front of the front plane", 180L, 45L)
	    ;
    goto L101;
L57:
    s_copy(stdmsg, "Warning, ignoring structures that do not exist", 180L, 
	    46L);
    goto L101;
L58:
    s_copy(stdmsg, "the specified structure does not exist", 180L, 38L);
    goto L101;
L59:
    s_copy(stdmsg, "the specified element does not exist", 180L, 36L);
    goto L101;
L60:
    s_copy(stdmsg, "specified starting path not found in CSS", 180L, 40L);
    goto L101;
L61:
    s_copy(stdmsg, "specified search ceiling index out of range", 180L, 43L);
    goto L101;
L62:
#ifndef NO_PROTO
    s_copy(stdmsg, "the table does not exist in the open structure between t"
	    "he element pointer and the end of the structure", 180L, 103L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the table does not exist in the open structure between t\
he element pointer and the end of the structure", 180L, 103L);
#endif /* NO_PROTO */
    goto L101;
L63:
#ifndef NO_PROTO
    s_copy(stdmsg, "one or both of the labels does not exist in the open str"
	    "ucture between the element pointer and the end of structure", 
	    180L, 115L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one or both of the labels does not exist in the open str\
ucture between the element pointer and the end of structure", 180L, 115L);
#endif /* NO_PROTO */
    goto L101;
L64:
    s_copy(stdmsg, "the specified path depth is less than zero", 180L, 42L);
    goto L101;
L65:
    s_copy(stdmsg, "the display priority is out of range", 180L, 36L);
    goto L101;
L66:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified device is not available on the specified w"
	    "orkstation ", 180L, 67L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified device is not available on the specified w\
orkstation ", 180L, 67L);
#endif /* NO_PROTO */
    goto L101;
L67:
#ifndef NO_PROTO
    s_copy(stdmsg, "the function requires the input device to be in REQUEST "
	    "mode", 180L, 60L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the function requires the input device to be in REQUEST \
mode", 180L, 60L);
#endif /* NO_PROTO */
    goto L101;
L68:
#ifndef NO_PROTO
    s_copy(stdmsg, "the function requires the input device to be in SAMPLE m"
	    "ode", 180L, 59L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the function requires the input device to be in SAMPLE m\
ode", 180L, 59L);
#endif /* NO_PROTO */
    goto L101;
L69:
#ifndef NO_PROTO
    s_copy(stdmsg, "the specified prompt/echo type is not available on the s"
	    "pecified workstation", 180L, 76L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the specified prompt/echo type is not available on the s\
pecified workstation", 180L, 76L);
#endif /* NO_PROTO */
    goto L101;
L70:
#ifndef NO_PROTO
    s_copy(stdmsg, "invalid echo area/volume; XMIN>=XMAX,YMIN>=YMAX or ZMIN>"
	    "ZMAX", 180L, 60L);
#else /* NO_PROTO */
    s_copy(stdmsg, "invalid echo area/volume; XMIN>=XMAX,YMIN>=YMAX or ZMIN>\
ZMAX", 180L, 60L);
#endif /* NO_PROTO */
    goto L101;
L71:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the echo area/volume boundary points is outside t"
	    "he range of the device", 180L, 78L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the echo area/volume boundary points is outside t\
he range of the device", 180L, 78L);
#endif /* NO_PROTO */
    goto L101;
L72:
    s_copy(stdmsg, "Warning, the input queue has overflowed", 180L, 39L);
    goto L101;
L73:
#ifndef NO_PROTO
    s_copy(stdmsg, "input queue has not overflowed, since OPEN PHIGS or last"
	    " invocation of INQUIRE INPUT QUEUE OVERFLOW", 180L, 99L);
#else /* NO_PROTO */
    s_copy(stdmsg, "input queue has not overflowed, since OPEN PHIGS or last\
 invocation of INQUIRE INPUT QUEUE OVERFLOW", 180L, 99L);
#endif /* NO_PROTO */
    goto L101;
L74:
#ifndef NO_PROTO
    s_copy(stdmsg, "input queue has overflowed, but associated workstation h"
	    "as been closed", 180L, 70L);
#else /* NO_PROTO */
    s_copy(stdmsg, "input queue has overflowed, but associated workstation h\
as been closed", 180L, 70L);
#endif /* NO_PROTO */
    goto L101;
L75:
#ifndef NO_PROTO
    s_copy(stdmsg, "the input device class of the current input report does "
	    "not match the class being requested", 180L, 91L);
#else /* NO_PROTO */
    s_copy(stdmsg, "the input device class of the current input report does \
not match the class being requested", 180L, 91L);
#endif /* NO_PROTO */
    goto L101;
L76:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the fields within the input device data record is"
	    " in error", 180L, 65L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the fields within the input device data record is\
 in error", 180L, 65L);
#endif /* NO_PROTO */
    goto L101;
L77:
    s_copy(stdmsg, "initial value is invalid", 180L, 24L);
    goto L101;
L78:
#ifndef NO_PROTO
    s_copy(stdmsg, "number of points in the initial stroke is greater than t"
	    "he buffer size", 180L, 70L);
#else /* NO_PROTO */
    s_copy(stdmsg, "number of points in the initial stroke is greater than t\
he buffer size", 180L, 70L);
#endif /* NO_PROTO */
    goto L101;
L79:
#ifndef NO_PROTO
    s_copy(stdmsg, "length of the initial string is greater than the buffer "
	    "size", 180L, 60L);
#else /* NO_PROTO */
    s_copy(stdmsg, "length of the initial string is greater than the buffer \
size", 180L, 60L);
#endif /* NO_PROTO */
    goto L101;
L80:
    s_copy(stdmsg, "item type is not allowed for user items", 180L, 39L);
    goto L101;
L81:
    s_copy(stdmsg, "item length is invalid ", 180L, 23L);
    goto L101;
L82:
    s_copy(stdmsg, "no item is left in metafile input", 180L, 33L);
    goto L101;
L83:
    s_copy(stdmsg, "metafile item is invalid", 180L, 24L);
    goto L101;
L84:
    s_copy(stdmsg, "item type is unknown", 180L, 20L);
    goto L101;
L85:
#ifndef NO_PROTO
    s_copy(stdmsg, "content of item data record is invalid for the specified"
	    " item type", 180L, 66L);
#else /* NO_PROTO */
    s_copy(stdmsg, "content of item data record is invalid for the specified\
 item type", 180L, 66L);
#endif /* NO_PROTO */
    goto L101;
L86:
    s_copy(stdmsg, "maximum item data record length is invalid", 180L, 42L);
    goto L101;
L87:
    s_copy(stdmsg, "user item cannot be interpreted", 180L, 31L);
    goto L101;
L88:
#ifndef NO_PROTO
    s_copy(stdmsg, "Warning, the specified escape is not available on one or"
	    " more workstations in this implementation.  The escape will be p"
	    "rocessed by those workstations on which it is available", 180L, 
	    175L);
#else /* NO_PROTO */
    s_copy(stdmsg, "Warning, the specified escape is not available on one or\
 more workstations in this implementation.  The escape will be processed by \
those workstations on which it is available", 180L, 175L);
#endif /* NO_PROTO */
    goto L101;
L89:
#ifndef NO_PROTO
    s_copy(stdmsg, "one of the fields within the escape data record is in er"
	    "ror", 180L, 59L);
#else /* NO_PROTO */
    s_copy(stdmsg, "one of the fields within the escape data record is in er\
ror", 180L, 59L);
#endif /* NO_PROTO */
    goto L101;
L90:
    s_copy(stdmsg, "the archive file cannot be opened", 180L, 33L);
    goto L101;
L91:
#ifndef NO_PROTO
    s_copy(stdmsg, "opening this archive file would exceed the maximum numbe"
	    "r of simultaneously open archive files", 180L, 94L);
#else /* NO_PROTO */
    s_copy(stdmsg, "opening this archive file would exceed the maximum numbe\
r of simultaneously open archive files", 180L, 94L);
#endif /* NO_PROTO */
    goto L101;
L92:
    s_copy(stdmsg, "archive file identifier already in use", 180L, 38L);
    goto L101;
L93:
    s_copy(stdmsg, "the archive file is not a PHIGS archive file", 180L, 44L);

    goto L101;
L94:
    s_copy(stdmsg, "the specified archive file is not open", 180L, 38L);
    goto L101;
L95:
#ifndef NO_PROTO
    s_copy(stdmsg, "name conflict occurred while conflict resolution flag ha"
	    "s value ABANDON", 180L, 71L);
#else /* NO_PROTO */
    s_copy(stdmsg, "name conflict occurred while conflict resolution flag ha\
s value ABANDON", 180L, 71L);
#endif /* NO_PROTO */
    goto L101;
L96:
#ifndef NO_PROTO
    s_copy(stdmsg, "Warning, the archive file is full.  Any structures that "
	    "were archived were archived in total", 180L, 92L);
#else /* NO_PROTO */
    s_copy(stdmsg, "Warning, the archive file is full.  Any structures that \
were archived were archived in total", 180L, 92L);
#endif /* NO_PROTO */
    goto L101;
L97:
#ifndef NO_PROTO
    s_copy(stdmsg, "Warning, some of the specified structures do not exist o"
	    "n the archive file", 180L, 74L);
#else /* NO_PROTO */
    s_copy(stdmsg, "Warning, some of the specified structures do not exist o\
n the archive file", 180L, 74L);
#endif /* NO_PROTO */
    goto L101;
L98:
#ifndef NO_PROTO
    s_copy(stdmsg, "Warning, some of the specified structures do not exist o"
	    "n the archive file.  PHIGS will create empty structure in their "
	    "place", 180L, 125L);
#else /* NO_PROTO */
    s_copy(stdmsg, "Warning, some of the specified structures do not exist o\
n the archive file.  PHIGS will create empty structure in their place", 180L, 
	    125L);
#endif /* NO_PROTO */
    goto L101;
L99:
    s_copy(stdmsg, "the specified error file is invalid", 180L, 35L);
    goto L101;
L2000:
    s_copy(stdmsg, "enumeration type out of range", 180L, 29L);
    goto L101;
L2001:
    s_copy(stdmsg, "output parameter size insufficient", 180L, 34L);
    goto L101;
L2002:
    s_copy(stdmsg, "list or set element not available", 180L, 33L);
    goto L101;
L2003:
    s_copy(stdmsg, "invalid data record", 180L, 19L);
    goto L101;
L2004:
    s_copy(stdmsg, "input parameter size out of range", 180L, 33L);
    goto L101;
L2005:
    s_copy(stdmsg, "invalid list of point lists", 180L, 27L);
    goto L101;
L2006:
    s_copy(stdmsg, "invalid list of filters", 180L, 23L);
    goto L101;
L2200:
    s_copy(stdmsg, "start index is out of range", 180L, 27L);
    goto L101;
L2201:
    s_copy(stdmsg, "length of application's list is negative", 180L, 40L);
    goto L101;
L2202:
    s_copy(stdmsg, "enumeration type out of range", 180L, 29L);
    goto L101;
L2203:
    s_copy(stdmsg, "error while allocating a Store", 180L, 30L);
    goto L101;
L2204:
    s_copy(stdmsg, "error while allocating memory", 180L, 29L);
    goto L101;
L101:
    if (msgdx <= 7) {
/* Writing concatenation */
	i__1[0] = 43, a__1[0] = "Ignoring function, function requires state ";

	i__1[1] = 180, a__1[1] = stdmsg;
	s_cat(errmsg, a__1, i__1, &c__2, errmsg_len);
    } else if (s_cmp(stdmsg, "Warning", 7L, 7L) == 0) {
	s_copy(errmsg, stdmsg, errmsg_len, 180L);
    } else {
/* Writing concatenation */
	i__1[0] = 19, a__1[0] = "Ignoring function, ";
	i__1[1] = 180, a__1[1] = stdmsg;
	s_cat(errmsg, a__1, i__1, &c__2, errmsg_len);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* scherr_ */

