/* nfunm.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

#ifndef NO_PROTO
/* Subroutine */ int nfunm_(integer *funccd, char *funnam, ftnlen funnam_len)
#else /* NO_PROTO */
/* Subroutine */ int nfunm_(funccd, funnam, funnam_len)
integer *funccd;
char *funnam;
ftnlen funnam_len;
#endif /* NO_PROTO */
{
    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
#endif /* NO_PROTO */

    /* Local variables */
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_();
#endif /* NO_PROTO */

/* NFUNM accepts an integer identifying a function and returns the generic
*/
/*  name of the function.  These are the codes used by the PVT system, as 
*/
/*  documented in sys-dict.prt and used in the #F entries of DOC.PRT. */
/*  Input parameter: */
/*    FUNCCD : integer code for function */
/*  Output parameter: */
/*    FUNNAM : generic name of function */
    if (*funccd < 1 || *funccd > 324) {
	unmsg_("NFUNM called with invalid value.", 32L);
    }
    if (*funccd <= 100) {
	goto L9000;
    }
    if (*funccd <= 200) {
	goto L9100;
    }
    if (*funccd <= 300) {
	goto L9200;
    }
    goto L9300;
L9000:
#ifndef NO_PROTO
    switch (*funccd) {
#else /* NO_PROTO */
    switch ((int)*funccd) {
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
	case 100:  goto L100;
    }
L9100:
#ifndef NO_PROTO
    switch (*funccd - 100) {
#else /* NO_PROTO */
    switch ((int)(*funccd - 100)) {
#endif /* NO_PROTO */
	case 1:  goto L101;
	case 2:  goto L102;
	case 3:  goto L103;
	case 4:  goto L104;
	case 5:  goto L105;
	case 6:  goto L106;
	case 7:  goto L107;
	case 8:  goto L108;
	case 9:  goto L109;
	case 10:  goto L110;
	case 11:  goto L111;
	case 12:  goto L112;
	case 13:  goto L113;
	case 14:  goto L114;
	case 15:  goto L115;
	case 16:  goto L116;
	case 17:  goto L117;
	case 18:  goto L118;
	case 19:  goto L119;
	case 20:  goto L120;
	case 21:  goto L121;
	case 22:  goto L122;
	case 23:  goto L123;
	case 24:  goto L124;
	case 25:  goto L125;
	case 26:  goto L126;
	case 27:  goto L127;
	case 28:  goto L128;
	case 29:  goto L129;
	case 30:  goto L130;
	case 31:  goto L131;
	case 32:  goto L132;
	case 33:  goto L133;
	case 34:  goto L134;
	case 35:  goto L135;
	case 36:  goto L136;
	case 37:  goto L137;
	case 38:  goto L138;
	case 39:  goto L139;
	case 40:  goto L140;
	case 41:  goto L141;
	case 42:  goto L142;
	case 43:  goto L143;
	case 44:  goto L144;
	case 45:  goto L145;
	case 46:  goto L146;
	case 47:  goto L147;
	case 48:  goto L148;
	case 49:  goto L149;
	case 50:  goto L150;
	case 51:  goto L151;
	case 52:  goto L152;
	case 53:  goto L153;
	case 54:  goto L154;
	case 55:  goto L155;
	case 56:  goto L156;
	case 57:  goto L157;
	case 58:  goto L158;
	case 59:  goto L159;
	case 60:  goto L160;
	case 61:  goto L161;
	case 62:  goto L162;
	case 63:  goto L163;
	case 64:  goto L164;
	case 65:  goto L165;
	case 66:  goto L166;
	case 67:  goto L167;
	case 68:  goto L168;
	case 69:  goto L169;
	case 70:  goto L170;
	case 71:  goto L171;
	case 72:  goto L172;
	case 73:  goto L173;
	case 74:  goto L174;
	case 75:  goto L175;
	case 76:  goto L176;
	case 77:  goto L177;
	case 78:  goto L178;
	case 79:  goto L179;
	case 80:  goto L180;
	case 81:  goto L181;
	case 82:  goto L182;
	case 83:  goto L183;
	case 84:  goto L184;
	case 85:  goto L185;
	case 86:  goto L186;
	case 87:  goto L187;
	case 88:  goto L188;
	case 89:  goto L189;
	case 90:  goto L190;
	case 91:  goto L191;
	case 92:  goto L192;
	case 93:  goto L193;
	case 94:  goto L194;
	case 95:  goto L195;
	case 96:  goto L196;
	case 97:  goto L197;
	case 98:  goto L198;
	case 99:  goto L199;
	case 100:  goto L200;
    }
L9200:
#ifndef NO_PROTO
    switch (*funccd - 200) {
#else /* NO_PROTO */
    switch ((int)(*funccd - 200)) {
#endif /* NO_PROTO */
	case 1:  goto L201;
	case 2:  goto L202;
	case 3:  goto L203;
	case 4:  goto L204;
	case 5:  goto L205;
	case 6:  goto L206;
	case 7:  goto L207;
	case 8:  goto L208;
	case 9:  goto L209;
	case 10:  goto L210;
	case 11:  goto L211;
	case 12:  goto L212;
	case 13:  goto L213;
	case 14:  goto L214;
	case 15:  goto L215;
	case 16:  goto L216;
	case 17:  goto L217;
	case 18:  goto L218;
	case 19:  goto L219;
	case 20:  goto L220;
	case 21:  goto L221;
	case 22:  goto L222;
	case 23:  goto L223;
	case 24:  goto L224;
	case 25:  goto L225;
	case 26:  goto L226;
	case 27:  goto L227;
	case 28:  goto L228;
	case 29:  goto L229;
	case 30:  goto L230;
	case 31:  goto L231;
	case 32:  goto L232;
	case 33:  goto L233;
	case 34:  goto L234;
	case 35:  goto L235;
	case 36:  goto L236;
	case 37:  goto L237;
	case 38:  goto L238;
	case 39:  goto L239;
	case 40:  goto L240;
	case 41:  goto L241;
	case 42:  goto L242;
	case 43:  goto L243;
	case 44:  goto L244;
	case 45:  goto L245;
	case 46:  goto L246;
	case 47:  goto L247;
	case 48:  goto L248;
	case 49:  goto L249;
	case 50:  goto L250;
	case 51:  goto L251;
	case 52:  goto L252;
	case 53:  goto L253;
	case 54:  goto L254;
	case 55:  goto L255;
	case 56:  goto L256;
	case 57:  goto L257;
	case 58:  goto L258;
	case 59:  goto L259;
	case 60:  goto L260;
	case 61:  goto L261;
	case 62:  goto L262;
	case 63:  goto L263;
	case 64:  goto L264;
	case 65:  goto L265;
	case 66:  goto L266;
	case 67:  goto L267;
	case 68:  goto L268;
	case 69:  goto L269;
	case 70:  goto L270;
	case 71:  goto L271;
	case 72:  goto L272;
	case 73:  goto L273;
	case 74:  goto L274;
	case 75:  goto L275;
	case 76:  goto L276;
	case 77:  goto L277;
	case 78:  goto L278;
	case 79:  goto L279;
	case 80:  goto L280;
	case 81:  goto L281;
	case 82:  goto L282;
	case 83:  goto L283;
	case 84:  goto L284;
	case 85:  goto L285;
	case 86:  goto L286;
	case 87:  goto L287;
	case 88:  goto L288;
	case 89:  goto L289;
	case 90:  goto L290;
	case 91:  goto L291;
	case 92:  goto L292;
	case 93:  goto L293;
	case 94:  goto L294;
	case 95:  goto L295;
	case 96:  goto L296;
	case 97:  goto L297;
	case 98:  goto L298;
	case 99:  goto L299;
	case 100:  goto L300;
    }
L9300:
#ifndef NO_PROTO
    switch (*funccd - 300) {
#else /* NO_PROTO */
    switch ((int)(*funccd - 300)) {
#endif /* NO_PROTO */
	case 1:  goto L301;
	case 2:  goto L302;
	case 3:  goto L303;
	case 4:  goto L304;
	case 5:  goto L305;
	case 6:  goto L306;
	case 7:  goto L307;
	case 8:  goto L308;
	case 9:  goto L309;
	case 10:  goto L310;
	case 11:  goto L311;
	case 12:  goto L312;
	case 13:  goto L313;
	case 14:  goto L314;
	case 15:  goto L315;
	case 16:  goto L316;
	case 17:  goto L317;
	case 18:  goto L318;
	case 19:  goto L319;
	case 20:  goto L320;
	case 21:  goto L321;
	case 22:  goto L322;
	case 23:  goto L323;
	case 24:  goto L324;
    }
L1:
    s_copy(funnam, "<open phigs>", funnam_len, 12L);
    return 0;
L2:
    s_copy(funnam, "<close phigs>", funnam_len, 13L);
    return 0;
L3:
    s_copy(funnam, "<open workstation>", funnam_len, 18L);
    return 0;
L4:
    s_copy(funnam, "<close workstation>", funnam_len, 19L);
    return 0;
L5:
    s_copy(funnam, "<redraw all structures>", funnam_len, 23L);
    return 0;
L6:
    s_copy(funnam, "<update workstation>", funnam_len, 20L);
    return 0;
L7:
    s_copy(funnam, "<set display update state>", funnam_len, 26L);
    return 0;
L8:
    s_copy(funnam, "<message>", funnam_len, 9L);
    return 0;
L9:
    s_copy(funnam, "<polyline 3>", funnam_len, 12L);
    return 0;
L10:
    s_copy(funnam, "<polyline>", funnam_len, 10L);
    return 0;
L11:
    s_copy(funnam, "<polymarker 3>", funnam_len, 14L);
    return 0;
L12:
    s_copy(funnam, "<polymarker>", funnam_len, 12L);
    return 0;
L13:
    s_copy(funnam, "<text 3>", funnam_len, 8L);
    return 0;
L14:
    s_copy(funnam, "<text>", funnam_len, 6L);
    return 0;
L15:
    s_copy(funnam, "<annotation text relative 3>", funnam_len, 28L);
    return 0;
L16:
    s_copy(funnam, "<annotation text relative>", funnam_len, 26L);
    return 0;
L17:
    s_copy(funnam, "<fill area 3>", funnam_len, 13L);
    return 0;
L18:
    s_copy(funnam, "<fill area>", funnam_len, 11L);
    return 0;
L19:
    s_copy(funnam, "<fill area set 3>", funnam_len, 17L);
    return 0;
L20:
    s_copy(funnam, "<fill area set>", funnam_len, 15L);
    return 0;
L21:
    s_copy(funnam, "<cell array 3>", funnam_len, 14L);
    return 0;
L22:
    s_copy(funnam, "<cell array>", funnam_len, 12L);
    return 0;
L23:
    s_copy(funnam, "<generalized drawing primitive 3>", funnam_len, 33L);
    return 0;
L24:
    s_copy(funnam, "<generalized drawing primitive>", funnam_len, 31L);
    return 0;
L25:
    s_copy(funnam, "<set polyline index>", funnam_len, 20L);
    return 0;
L26:
    s_copy(funnam, "<set polymarker index>", funnam_len, 22L);
    return 0;
L27:
    s_copy(funnam, "<set text index>", funnam_len, 16L);
    return 0;
L28:
    s_copy(funnam, "<set interior index>", funnam_len, 20L);
    return 0;
L29:
    s_copy(funnam, "<set edge index>", funnam_len, 16L);
    return 0;
L30:
    s_copy(funnam, "<set linetype>", funnam_len, 14L);
    return 0;
L31:
    s_copy(funnam, "<set linewidth scale factor>", funnam_len, 28L);
    return 0;
L32:
    s_copy(funnam, "<set polyline colour index>", funnam_len, 27L);
    return 0;
L33:
    s_copy(funnam, "<set marker type>", funnam_len, 17L);
    return 0;
L34:
    s_copy(funnam, "<set marker size scale factor>", funnam_len, 30L);
    return 0;
L35:
    s_copy(funnam, "<set polymarker colour index>", funnam_len, 29L);
    return 0;
L36:
    s_copy(funnam, "<set text font>", funnam_len, 15L);
    return 0;
L37:
    s_copy(funnam, "<set text precision>", funnam_len, 20L);
    return 0;
L38:
    s_copy(funnam, "<set character expansion factor>", funnam_len, 32L);
    return 0;
L39:
    s_copy(funnam, "<set character spacing>", funnam_len, 23L);
    return 0;
L40:
    s_copy(funnam, "<set text colour index>", funnam_len, 23L);
    return 0;
L41:
    s_copy(funnam, "<set character height>", funnam_len, 22L);
    return 0;
L42:
    s_copy(funnam, "<set character up vector>", funnam_len, 25L);
    return 0;
L43:
    s_copy(funnam, "<set text path>", funnam_len, 15L);
    return 0;
L44:
    s_copy(funnam, "<set text alignment>", funnam_len, 20L);
    return 0;
L45:
    s_copy(funnam, "<set annotation text character height>", funnam_len, 38L);

    return 0;
L46:
    s_copy(funnam, "<set annotation text character up vector>", funnam_len, 
	    41L);
    return 0;
L47:
    s_copy(funnam, "<set annotation text path>", funnam_len, 26L);
    return 0;
L48:
    s_copy(funnam, "<set annotation text alignment>", funnam_len, 31L);
    return 0;
L49:
    s_copy(funnam, "<set annotation style>", funnam_len, 22L);
    return 0;
L50:
    s_copy(funnam, "<set interior style>", funnam_len, 20L);
    return 0;
L51:
    s_copy(funnam, "<set interior style index>", funnam_len, 26L);
    return 0;
L52:
    s_copy(funnam, "<set interior colour index>", funnam_len, 27L);
    return 0;
L53:
    s_copy(funnam, "<set edge flag>", funnam_len, 15L);
    return 0;
L54:
    s_copy(funnam, "<set edgetype>", funnam_len, 14L);
    return 0;
L55:
    s_copy(funnam, "<set edgewidth scale factor>", funnam_len, 28L);
    return 0;
L56:
    s_copy(funnam, "<set edge colour index>", funnam_len, 23L);
    return 0;
L57:
    s_copy(funnam, "<set pattern size>", funnam_len, 18L);
    return 0;
L58:
    s_copy(funnam, "<set pattern reference point and vectors>", funnam_len, 
	    41L);
    return 0;
L59:
    s_copy(funnam, "<set pattern reference point>", funnam_len, 29L);
    return 0;
L60:
    s_copy(funnam, "<add names to set>", funnam_len, 18L);
    return 0;
L61:
    s_copy(funnam, "<remove names from set>", funnam_len, 23L);
    return 0;
L62:
    s_copy(funnam, "<set individual asf>", funnam_len, 20L);
    return 0;
L63:
    s_copy(funnam, "<set polyline representation>", funnam_len, 29L);
    return 0;
L64:
    s_copy(funnam, "<set polymarker representation>", funnam_len, 31L);
    return 0;
L65:
    s_copy(funnam, "<set text representation>", funnam_len, 25L);
    return 0;
L66:
    s_copy(funnam, "<set interior representation>", funnam_len, 29L);
    return 0;
L67:
    s_copy(funnam, "<set edge representation>", funnam_len, 25L);
    return 0;
L68:
    s_copy(funnam, "<set pattern representation>", funnam_len, 28L);
    return 0;
L69:
    s_copy(funnam, "<set colour representation>", funnam_len, 27L);
    return 0;
L70:
    s_copy(funnam, "<set highlighting filter>", funnam_len, 25L);
    return 0;
L71:
    s_copy(funnam, "<set invisibility filter>", funnam_len, 25L);
    return 0;
L72:
    s_copy(funnam, "<set colour model>", funnam_len, 18L);
    return 0;
L73:
    s_copy(funnam, "<set hlhsr identifier>", funnam_len, 22L);
    return 0;
L74:
    s_copy(funnam, "<set hlhsr mode>", funnam_len, 16L);
    return 0;
L75:
    s_copy(funnam, "<set local transformation 3>", funnam_len, 28L);
    return 0;
L76:
    s_copy(funnam, "<set local transformation>", funnam_len, 26L);
    return 0;
L77:
    s_copy(funnam, "<set global transformation 3>", funnam_len, 29L);
    return 0;
L78:
    s_copy(funnam, "<set global transformation>", funnam_len, 27L);
    return 0;
L79:
    s_copy(funnam, "<set modelling clipping volume 3>", funnam_len, 33L);
    return 0;
L80:
    s_copy(funnam, "<set modelling clipping volume>", funnam_len, 31L);
    return 0;
L81:
    s_copy(funnam, "<set modelling clipping indicator>", funnam_len, 34L);
    return 0;
L82:
    s_copy(funnam, "<restore modelling clipping volume>", funnam_len, 35L);
    return 0;
L83:
    s_copy(funnam, "<set view index>", funnam_len, 16L);
    return 0;
L84:
    s_copy(funnam, "<set view representation 3>", funnam_len, 27L);
    return 0;
L85:
    s_copy(funnam, "<set view representation>", funnam_len, 25L);
    return 0;
L86:
    s_copy(funnam, "<set view transformation input priority>", funnam_len, 
	    40L);
    return 0;
L87:
    s_copy(funnam, "<set workstation window 3>", funnam_len, 26L);
    return 0;
L88:
    s_copy(funnam, "<set workstation window>", funnam_len, 24L);
    return 0;
L89:
    s_copy(funnam, "<set workstation viewport 3>", funnam_len, 28L);
    return 0;
L90:
    s_copy(funnam, "<set workstation viewport>", funnam_len, 26L);
    return 0;
L91:
    s_copy(funnam, "<translate 3>", funnam_len, 13L);
    return 0;
L92:
    s_copy(funnam, "<translate>", funnam_len, 11L);
    return 0;
L93:
    s_copy(funnam, "<scale 3>", funnam_len, 9L);
    return 0;
L94:
    s_copy(funnam, "<scale>", funnam_len, 7L);
    return 0;
L95:
    s_copy(funnam, "<rotate x>", funnam_len, 10L);
    return 0;
L96:
    s_copy(funnam, "<rotate y>", funnam_len, 10L);
    return 0;
L97:
    s_copy(funnam, "<rotate z>", funnam_len, 10L);
    return 0;
L98:
    s_copy(funnam, "<rotate>", funnam_len, 8L);
    return 0;
L99:
    s_copy(funnam, "<compose matrix 3>", funnam_len, 18L);
    return 0;
L100:
    s_copy(funnam, "<compose matrix>", funnam_len, 16L);
    return 0;
L101:
    s_copy(funnam, "<transform point 3>", funnam_len, 19L);
    return 0;
L102:
    s_copy(funnam, "<transform point>", funnam_len, 17L);
    return 0;
L103:
    s_copy(funnam, "<build transformation matrix 3>", funnam_len, 31L);
    return 0;
L104:
    s_copy(funnam, "<build transformation matrix>", funnam_len, 29L);
    return 0;
L105:
    s_copy(funnam, "<compose transformation matrix 3>", funnam_len, 33L);
    return 0;
L106:
    s_copy(funnam, "<compose transformation matrix>", funnam_len, 31L);
    return 0;
L107:
    s_copy(funnam, "<evaluate view orientation matrix 3>", funnam_len, 36L);
    return 0;
L108:
    s_copy(funnam, "<evaluate view orientation matrix>", funnam_len, 34L);
    return 0;
L109:
    s_copy(funnam, "<evaluate view mapping matrix 3>", funnam_len, 32L);
    return 0;
L110:
    s_copy(funnam, "<evaluate view mapping matrix>", funnam_len, 30L);
    return 0;
L111:
    s_copy(funnam, "<open structure>", funnam_len, 16L);
    return 0;
L112:
    s_copy(funnam, "<close structure>", funnam_len, 17L);
    return 0;
L113:
    s_copy(funnam, "<execute structure>", funnam_len, 19L);
    return 0;
L114:
    s_copy(funnam, "<label>", funnam_len, 7L);
    return 0;
L115:
    s_copy(funnam, "<application data>", funnam_len, 18L);
    return 0;
L116:
    s_copy(funnam, "<generalized structure element>", funnam_len, 31L);
    return 0;
L117:
    s_copy(funnam, "<set edit mode>", funnam_len, 15L);
    return 0;
L118:
    s_copy(funnam, "<copy all elements from structure>", funnam_len, 34L);
    return 0;
L119:
    s_copy(funnam, "<set element pointer>", funnam_len, 21L);
    return 0;
L120:
    s_copy(funnam, "<offset element pointer>", funnam_len, 24L);
    return 0;
L121:
    s_copy(funnam, "<set element pointer at label>", funnam_len, 30L);
    return 0;
L122:
    s_copy(funnam, "<delete element>", funnam_len, 16L);
    return 0;
L123:
    s_copy(funnam, "<delete element range>", funnam_len, 22L);
    return 0;
L124:
    s_copy(funnam, "<delete elements between labels>", funnam_len, 32L);
    return 0;
L125:
    s_copy(funnam, "<empty structure>", funnam_len, 17L);
    return 0;
L126:
    s_copy(funnam, "<delete structure>", funnam_len, 18L);
    return 0;
L127:
    s_copy(funnam, "<delete structure network>", funnam_len, 26L);
    return 0;
L128:
    s_copy(funnam, "<delete all structures>", funnam_len, 23L);
    return 0;
L129:
    s_copy(funnam, "<change structure identifier>", funnam_len, 29L);
    return 0;
L130:
    s_copy(funnam, "<change structure references>", funnam_len, 29L);
    return 0;
L131:
    s_copy(funnam, "<change structure identifier and references>", funnam_len,
	     44L);
    return 0;
L132:
    s_copy(funnam, "<post structure>", funnam_len, 16L);
    return 0;
L133:
    s_copy(funnam, "<unpost structure>", funnam_len, 18L);
    return 0;
L134:
    s_copy(funnam, "<unpost all structures>", funnam_len, 23L);
    return 0;
L135:
    s_copy(funnam, "<open archive file>", funnam_len, 19L);
    return 0;
L136:
    s_copy(funnam, "<close archive file>", funnam_len, 20L);
    return 0;
L137:
    s_copy(funnam, "<archive structures>", funnam_len, 20L);
    return 0;
L138:
    s_copy(funnam, "<archive structure networks>", funnam_len, 28L);
    return 0;
L139:
    s_copy(funnam, "<archive all structures>", funnam_len, 24L);
    return 0;
L140:
    s_copy(funnam, "<set conflict resolution>", funnam_len, 25L);
    return 0;
L141:
    s_copy(funnam, "<retrieve structure identifiers>", funnam_len, 32L);
    return 0;
L142:
    s_copy(funnam, "<retrieve structures>", funnam_len, 21L);
    return 0;
L143:
    s_copy(funnam, "<retrieve structure networks>", funnam_len, 29L);
    return 0;
L144:
    s_copy(funnam, "<retrieve all structures>", funnam_len, 25L);
    return 0;
L145:
    s_copy(funnam, "<retrieve paths to ancestors>", funnam_len, 29L);
    return 0;
L146:
    s_copy(funnam, "<retrieve paths to descendants>", funnam_len, 31L);
    return 0;
L147:
    s_copy(funnam, "<delete structures from archive>", funnam_len, 32L);
    return 0;
L148:
    s_copy(funnam, "<delete structure networks from archive>", funnam_len, 
	    40L);
    return 0;
L149:
    s_copy(funnam, "<delete all structures from archive>", funnam_len, 36L);
    return 0;
L150:
    s_copy(funnam, "<set pick identifier>", funnam_len, 21L);
    return 0;
L151:
    s_copy(funnam, "<set pick filter>", funnam_len, 17L);
    return 0;
L152:
    s_copy(funnam, "<initialize locator 3>", funnam_len, 22L);
    return 0;
L153:
    s_copy(funnam, "<initialize locator>", funnam_len, 20L);
    return 0;
L154:
    s_copy(funnam, "<initialize stroke 3>", funnam_len, 21L);
    return 0;
L155:
    s_copy(funnam, "<initialize stroke>", funnam_len, 19L);
    return 0;
L156:
    s_copy(funnam, "<initialize valuator 3>", funnam_len, 23L);
    return 0;
L157:
    s_copy(funnam, "<initialize valuator>", funnam_len, 21L);
    return 0;
L158:
    s_copy(funnam, "<initialize choice 3>", funnam_len, 21L);
    return 0;
L159:
    s_copy(funnam, "<initialize choice>", funnam_len, 19L);
    return 0;
L160:
    s_copy(funnam, "<initialize pick 3>", funnam_len, 19L);
    return 0;
L161:
    s_copy(funnam, "<initialize pick>", funnam_len, 17L);
    return 0;
L162:
    s_copy(funnam, "<initialize string 3>", funnam_len, 21L);
    return 0;
L163:
    s_copy(funnam, "<initialize string>", funnam_len, 19L);
    return 0;
L164:
    s_copy(funnam, "<set locator mode>", funnam_len, 18L);
    return 0;
L165:
    s_copy(funnam, "<set stroke mode>", funnam_len, 17L);
    return 0;
L166:
    s_copy(funnam, "<set valuator mode>", funnam_len, 19L);
    return 0;
L167:
    s_copy(funnam, "<set choice mode>", funnam_len, 17L);
    return 0;
L168:
    s_copy(funnam, "<set pick mode>", funnam_len, 15L);
    return 0;
L169:
    s_copy(funnam, "<set string mode>", funnam_len, 17L);
    return 0;
L170:
    s_copy(funnam, "<request locator 3>", funnam_len, 19L);
    return 0;
L171:
    s_copy(funnam, "<request locator>", funnam_len, 17L);
    return 0;
L172:
    s_copy(funnam, "<request stroke 3>", funnam_len, 18L);
    return 0;
L173:
    s_copy(funnam, "<request stroke>", funnam_len, 16L);
    return 0;
L174:
    s_copy(funnam, "<request valuator>", funnam_len, 18L);
    return 0;
L175:
    s_copy(funnam, "<request choice>", funnam_len, 16L);
    return 0;
L176:
    s_copy(funnam, "<request pick>", funnam_len, 14L);
    return 0;
L177:
    s_copy(funnam, "<request string>", funnam_len, 16L);
    return 0;
L178:
    s_copy(funnam, "<sample locator 3>", funnam_len, 18L);
    return 0;
L179:
    s_copy(funnam, "<sample locator>", funnam_len, 16L);
    return 0;
L180:
    s_copy(funnam, "<sample stroke 3>", funnam_len, 17L);
    return 0;
L181:
    s_copy(funnam, "<sample stroke>", funnam_len, 15L);
    return 0;
L182:
    s_copy(funnam, "<sample valuator>", funnam_len, 17L);
    return 0;
L183:
    s_copy(funnam, "<sample choice>", funnam_len, 15L);
    return 0;
L184:
    s_copy(funnam, "<sample pick>", funnam_len, 13L);
    return 0;
L185:
    s_copy(funnam, "<sample string>", funnam_len, 15L);
    return 0;
L186:
    s_copy(funnam, "<await event>", funnam_len, 13L);
    return 0;
L187:
    s_copy(funnam, "<flush device events>", funnam_len, 21L);
    return 0;
L188:
    s_copy(funnam, "<get locator 3>", funnam_len, 15L);
    return 0;
L189:
    s_copy(funnam, "<get locator>", funnam_len, 13L);
    return 0;
L190:
    s_copy(funnam, "<get stroke 3>", funnam_len, 14L);
    return 0;
L191:
    s_copy(funnam, "<get stroke>", funnam_len, 12L);
    return 0;
L192:
    s_copy(funnam, "<get valuator>", funnam_len, 14L);
    return 0;
L193:
    s_copy(funnam, "<get choice>", funnam_len, 12L);
    return 0;
L194:
    s_copy(funnam, "<get pick>", funnam_len, 10L);
    return 0;
L195:
    s_copy(funnam, "<get string>", funnam_len, 12L);
    return 0;
L196:
    s_copy(funnam, "<write item to metafile>", funnam_len, 24L);
    return 0;
L197:
    s_copy(funnam, "<get item type from metafile>", funnam_len, 29L);
    return 0;
L198:
    s_copy(funnam, "<read item from metafile>", funnam_len, 25L);
    return 0;
L199:
    s_copy(funnam, "<interpret item>", funnam_len, 16L);
    return 0;
L200:
    s_copy(funnam, "<inquire system state value>", funnam_len, 28L);
    return 0;
L201:
    s_copy(funnam, "<inquire workstation state value>", funnam_len, 33L);
    return 0;
L202:
    s_copy(funnam, "<inquire structure state value>", funnam_len, 31L);
    return 0;
L203:
    s_copy(funnam, "<inquire archive state value>", funnam_len, 29L);
    return 0;
L204:
    s_copy(funnam, "<inquire list of available workstation types>", 
	    funnam_len, 45L);
    return 0;
L205:
    s_copy(funnam, "<inquire phigs facilities>", funnam_len, 26L);
    return 0;
L206:
    s_copy(funnam, "<inquire generalized structure element facilities>", 
	    funnam_len, 50L);
    return 0;
L207:
    s_copy(funnam, "<inquire modelling clipping facilities>", funnam_len, 39L)
	    ;
    return 0;
L208:
    s_copy(funnam, "<inquire edit mode>", funnam_len, 19L);
    return 0;
L209:
    s_copy(funnam, "<inquire set of open workstations>", funnam_len, 34L);
    return 0;
L210:
    s_copy(funnam, "<inquire structure identifiers>", funnam_len, 31L);
    return 0;
L211:
    s_copy(funnam, "<inquire archive files>", funnam_len, 23L);
    return 0;
L212:
    s_copy(funnam, "<inquire conflict resolution>", funnam_len, 29L);
    return 0;
L213:
    s_copy(funnam, "<inquire all conflicting structures>", funnam_len, 36L);
    return 0;
L214:
    s_copy(funnam, "<inquire conflicting structures in network>", funnam_len, 
	    43L);
    return 0;
L215:
    s_copy(funnam, "<inquire more simultaneous events>", funnam_len, 34L);
    return 0;
L216:
    s_copy(funnam, "<inquire workstation connection and type>", funnam_len, 
	    41L);
    return 0;
L217:
    s_copy(funnam, "<inquire list of view indices>", funnam_len, 30L);
    return 0;
L218:
    s_copy(funnam, "<inquire view representation>", funnam_len, 29L);
    return 0;
L219:
    s_copy(funnam, "<inquire hlhsr mode>", funnam_len, 20L);
    return 0;
L220:
    s_copy(funnam, "<inquire posted structures>", funnam_len, 27L);
    return 0;
L221:
    s_copy(funnam, "<inquire display update state>", funnam_len, 30L);
    return 0;
L222:
    s_copy(funnam, "<inquire list of polyline indices>", funnam_len, 34L);
    return 0;
L223:
    s_copy(funnam, "<inquire polyline representation>", funnam_len, 33L);
    return 0;
L224:
    s_copy(funnam, "<inquire list of polymarker indices>", funnam_len, 36L);
    return 0;
L225:
    s_copy(funnam, "<inquire polymarker representation>", funnam_len, 35L);
    return 0;
L226:
    s_copy(funnam, "<inquire list of text indices>", funnam_len, 30L);
    return 0;
L227:
    s_copy(funnam, "<inquire text representation>", funnam_len, 29L);
    return 0;
L228:
    s_copy(funnam, "<inquire list of interior indices>", funnam_len, 34L);
    return 0;
L229:
    s_copy(funnam, "<inquire interior representation>", funnam_len, 33L);
    return 0;
L230:
    s_copy(funnam, "<inquire list of edge indices>", funnam_len, 30L);
    return 0;
L231:
    s_copy(funnam, "<inquire edge representation>", funnam_len, 29L);
    return 0;
L232:
    s_copy(funnam, "<inquire list of pattern indices>", funnam_len, 33L);
    return 0;
L233:
    s_copy(funnam, "<inquire pattern representation>", funnam_len, 32L);
    return 0;
L234:
    s_copy(funnam, "<inquire colour model>", funnam_len, 22L);
    return 0;
L235:
    s_copy(funnam, "<inquire list of colour indices>", funnam_len, 32L);
    return 0;
L236:
    s_copy(funnam, "<inquire colour representation>", funnam_len, 31L);
    return 0;
L237:
    s_copy(funnam, "<inquire highlighting filter>", funnam_len, 29L);
    return 0;
L238:
    s_copy(funnam, "<inquire invisibility filter>", funnam_len, 29L);
    return 0;
L239:
    s_copy(funnam, "<inquire workstation transformation 3>", funnam_len, 38L);

    return 0;
L240:
    s_copy(funnam, "<inquire workstation transformation>", funnam_len, 36L);
    return 0;
L241:
    s_copy(funnam, "<inquire locator device state 3>", funnam_len, 32L);
    return 0;
L242:
    s_copy(funnam, "<inquire locator device state>", funnam_len, 30L);
    return 0;
L243:
    s_copy(funnam, "<inquire stroke device state 3>", funnam_len, 31L);
    return 0;
L244:
    s_copy(funnam, "<inquire stroke device state>", funnam_len, 29L);
    return 0;
L245:
    s_copy(funnam, "<inquire valuator device state 3>", funnam_len, 33L);
    return 0;
L246:
    s_copy(funnam, "<inquire valuator device state>", funnam_len, 31L);
    return 0;
L247:
    s_copy(funnam, "<inquire choice device state 3>", funnam_len, 31L);
    return 0;
L248:
    s_copy(funnam, "<inquire choice device state>", funnam_len, 29L);
    return 0;
L249:
    s_copy(funnam, "<inquire pick device state 3>", funnam_len, 29L);
    return 0;
L250:
    s_copy(funnam, "<inquire pick device state>", funnam_len, 27L);
    return 0;
L251:
    s_copy(funnam, "<inquire string device state 3>", funnam_len, 31L);
    return 0;
L252:
    s_copy(funnam, "<inquire string device state>", funnam_len, 29L);
    return 0;
L253:
    s_copy(funnam, "<inquire workstation category>", funnam_len, 30L);
    return 0;
L254:
    s_copy(funnam, "<inquire display space size 3>", funnam_len, 30L);
    return 0;
L255:
    s_copy(funnam, "<inquire display space size>", funnam_len, 28L);
    return 0;
L256:
    s_copy(funnam, "<inquire hlhsr facilities>", funnam_len, 26L);
    return 0;
L257:
    s_copy(funnam, "<inquire view facilities>", funnam_len, 25L);
    return 0;
L258:
    s_copy(funnam, "<inquire predefined view representation>", funnam_len, 
	    40L);
    return 0;
L259:
    s_copy(funnam, "<inquire workstation classification>", funnam_len, 36L);
    return 0;
L260:
    s_copy(funnam, "<inquire dynamics of workstation attributes>", funnam_len,
	     44L);
    return 0;
L261:
    s_copy(funnam, "<inquire default display update state>", funnam_len, 38L);

    return 0;
L262:
    s_copy(funnam, "<inquire polyline facilities>", funnam_len, 29L);
    return 0;
L263:
    s_copy(funnam, "<inquire predefined polyline representation>", funnam_len,
	     44L);
    return 0;
L264:
    s_copy(funnam, "<inquire polymarker facilities>", funnam_len, 31L);
    return 0;
L265:
    s_copy(funnam, "<inquire predefined polymarker representation>", 
	    funnam_len, 46L);
    return 0;
L266:
    s_copy(funnam, "<inquire text facilities>", funnam_len, 25L);
    return 0;
L267:
    s_copy(funnam, "<inquire predefined text representation>", funnam_len, 
	    40L);
    return 0;
L268:
    s_copy(funnam, "<inquire annotation facilities>", funnam_len, 31L);
    return 0;
L269:
    s_copy(funnam, "<inquire text extent>", funnam_len, 21L);
    return 0;
L270:
    s_copy(funnam, "<inquire interior facilities>", funnam_len, 29L);
    return 0;
L271:
    s_copy(funnam, "<inquire predefined interior representation>", funnam_len,
	     44L);
    return 0;
L272:
    s_copy(funnam, "<inquire edge facilities>", funnam_len, 25L);
    return 0;
L273:
    s_copy(funnam, "<inquire predefined edge representation>", funnam_len, 
	    40L);
    return 0;
L274:
    s_copy(funnam, "<inquire pattern facilities>", funnam_len, 28L);
    return 0;
L275:
    s_copy(funnam, "<inquire predefined pattern representation>", funnam_len, 
	    43L);
    return 0;
L276:
    s_copy(funnam, "<inquire colour model facilities>", funnam_len, 33L);
    return 0;
L277:
    s_copy(funnam, "<inquire colour facilities>", funnam_len, 27L);
    return 0;
L278:
    s_copy(funnam, "<inquire predefined colour representation>", funnam_len, 
	    42L);
    return 0;
L279:
#ifndef NO_PROTO
    s_copy(funnam, "<inquire list of available generalized drawing primitive"
	    "s 3>", funnam_len, 60L);
#else /* NO_PROTO */
    s_copy(funnam, "<inquire list of available generalized drawing primitive\
s 3>", funnam_len, 60L);
#endif /* NO_PROTO */
    return 0;
L280:
#ifndef NO_PROTO
    s_copy(funnam, "<inquire list of available generalized drawing primitive"
	    "s>", funnam_len, 58L);
#else /* NO_PROTO */
    s_copy(funnam, "<inquire list of available generalized drawing primitive\
s>", funnam_len, 58L);
#endif /* NO_PROTO */
    return 0;
L281:
    s_copy(funnam, "<inquire generalized drawing primitive 3>", funnam_len, 
	    41L);
    return 0;
L282:
    s_copy(funnam, "<inquire generalized drawing primitive>", funnam_len, 39L)
	    ;
    return 0;
L283:
#ifndef NO_PROTO
    s_copy(funnam, "<inquire list of available generalized structure element"
	    "s>", funnam_len, 58L);
#else /* NO_PROTO */
    s_copy(funnam, "<inquire list of available generalized structure element\
s>", funnam_len, 58L);
#endif /* NO_PROTO */
    return 0;
L284:
    s_copy(funnam, "<inquire number of display priorities supported>", 
	    funnam_len, 48L);
    return 0;
L285:
    s_copy(funnam, "<inquire workstation state table lengths>", funnam_len, 
	    41L);
    return 0;
L286:
    s_copy(funnam, "<inquire dynamics of structures>", funnam_len, 32L);
    return 0;
L287:
    s_copy(funnam, "<inquire number of available logical input devices>", 
	    funnam_len, 51L);
    return 0;
L288:
    s_copy(funnam, "<inquire default locator device data 3>", funnam_len, 39L)
	    ;
    return 0;
L289:
    s_copy(funnam, "<inquire default locator device data>", funnam_len, 37L);
    return 0;
L290:
    s_copy(funnam, "<inquire default stroke device data 3>", funnam_len, 38L);

    return 0;
L291:
    s_copy(funnam, "<inquire default stroke device data>", funnam_len, 36L);
    return 0;
L292:
    s_copy(funnam, "<inquire default valuator device data 3>", funnam_len, 
	    40L);
    return 0;
L293:
    s_copy(funnam, "<inquire default valuator device data>", funnam_len, 38L);

    return 0;
L294:
    s_copy(funnam, "<inquire default choice device data 3>", funnam_len, 38L);

    return 0;
L295:
    s_copy(funnam, "<inquire default choice device data>", funnam_len, 36L);
    return 0;
L296:
    s_copy(funnam, "<inquire default pick device data 3>", funnam_len, 36L);
    return 0;
L297:
    s_copy(funnam, "<inquire default pick device data>", funnam_len, 34L);
    return 0;
L298:
    s_copy(funnam, "<inquire default string device data 3>", funnam_len, 38L);

    return 0;
L299:
    s_copy(funnam, "<inquire default string device data>", funnam_len, 36L);
    return 0;
L300:
    s_copy(funnam, "<inquire set of workstations to which posted>", 
	    funnam_len, 45L);
    return 0;
L301:
    s_copy(funnam, "<inquire open structure>", funnam_len, 24L);
    return 0;
L302:
    s_copy(funnam, "<inquire element pointer>", funnam_len, 25L);
    return 0;
L303:
    s_copy(funnam, "<inquire current element type and size>", funnam_len, 39L)
	    ;
    return 0;
L304:
    s_copy(funnam, "<inquire current element content>", funnam_len, 33L);
    return 0;
L305:
    s_copy(funnam, "<inquire element type and size>", funnam_len, 31L);
    return 0;
L306:
    s_copy(funnam, "<inquire element content>", funnam_len, 25L);
    return 0;
L307:
    s_copy(funnam, "<inquire structure status>", funnam_len, 26L);
    return 0;
L308:
    s_copy(funnam, "<inquire paths to ancestors>", funnam_len, 28L);
    return 0;
L309:
    s_copy(funnam, "<inquire paths to descendants>", funnam_len, 30L);
    return 0;
L310:
    s_copy(funnam, "<element search>", funnam_len, 16L);
    return 0;
L311:
    s_copy(funnam, "<incremental spatial search 3>", funnam_len, 30L);
    return 0;
L312:
    s_copy(funnam, "<incremental spatial search>", funnam_len, 28L);
    return 0;
L313:
    s_copy(funnam, "<inquire input queue overflow>", funnam_len, 30L);
    return 0;
L314:
    s_copy(funnam, "<inquire error handling mode>", funnam_len, 29L);
    return 0;
L315:
    s_copy(funnam, "<emergency close phigs>", funnam_len, 23L);
    return 0;
L316:
    s_copy(funnam, "<error handling>", funnam_len, 16L);
    return 0;
L317:
    s_copy(funnam, "<error logging>", funnam_len, 15L);
    return 0;
L318:
    s_copy(funnam, "<set error handling mode>", funnam_len, 25L);
    return 0;
L319:
    s_copy(funnam, "<escape>", funnam_len, 8L);
    return 0;
L320:
    s_copy(funnam, "<pack data record>", funnam_len, 18L);
    return 0;
L321:
    s_copy(funnam, "<unpack data record>", funnam_len, 20L);
    return 0;
L322:
    s_copy(funnam, "<create store>", funnam_len, 14L);
    return 0;
L323:
    s_copy(funnam, "<delete store>", funnam_len, 14L);
    return 0;
L324:
    s_copy(funnam, "<set error handler>", funnam_len, 19L);
    return 0;
} /* nfunm_ */

