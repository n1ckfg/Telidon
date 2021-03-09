/* fort/09/02/sublib.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer errcom, funcom, filcom, ernmsw, expsiz, experr[10], usrerr, 
	    errsav[200], funsav[200], filsav[200], efcnt, efid[100];
} errinf_;

#define errinf_1 errinf_

struct {
    char curcon[200], errsrs[40], errmrk[20], erflnm[80], contab[6000];
} errchr_;

#define errchr_1 errchr_

/* Table of constant values */

static integer c__91 = 91;
static integer c__92 = 92;
static integer c__93 = 93;
static integer c__94 = 94;
static integer c__95 = 95;
static integer c__97 = 97;
static integer c__98 = 98;
static integer c__99 = 99;
static integer c__100 = 100;
static integer c__101 = 101;
static integer c__102 = 102;
static integer c__103 = 103;
static integer c__104 = 104;
static integer c__105 = 105;
static integer c__106 = 106;
static integer c__107 = 107;
static integer c__108 = 108;
static integer c__109 = 109;
static integer c__110 = 110;
static integer c__204 = 204;
static integer c__205 = 205;
static integer c__206 = 206;
static integer c__207 = 207;
static integer c__208 = 208;
static integer c__209 = 209;
static integer c__210 = 210;
static integer c__211 = 211;
static integer c__212 = 212;
static integer c__213 = 213;
static integer c__214 = 214;
static integer c__215 = 215;
static integer c__216 = 216;
static integer c__217 = 217;
static integer c__218 = 218;
static integer c__219 = 219;
static integer c__220 = 220;
static integer c__221 = 221;
static integer c__222 = 222;
static integer c__223 = 223;
static integer c__224 = 224;
static integer c__225 = 225;
static integer c__226 = 226;
static integer c__227 = 227;
static integer c__228 = 228;
static integer c__229 = 229;
static integer c__230 = 230;
static integer c__231 = 231;
static integer c__232 = 232;
static integer c__233 = 233;
static integer c__234 = 234;
static integer c__235 = 235;
static integer c__236 = 236;
static integer c__237 = 237;
static integer c__238 = 238;
static integer c__239 = 239;
static integer c__240 = 240;
static integer c__253 = 253;
static integer c__254 = 254;
static integer c__255 = 255;
static integer c__256 = 256;
static integer c__257 = 257;
static integer c__258 = 258;
static integer c__259 = 259;
static integer c__260 = 260;
static integer c__261 = 261;
static integer c__262 = 262;
static integer c__263 = 263;
static integer c__264 = 264;
static integer c__265 = 265;
static integer c__266 = 266;
static integer c__267 = 267;
static integer c__268 = 268;
static integer c__269 = 269;
static integer c__270 = 270;
static integer c__271 = 271;
static integer c__272 = 272;
static integer c__273 = 273;
static integer c__274 = 274;
static integer c__275 = 275;
static integer c__276 = 276;
static integer c__277 = 277;
static integer c__278 = 278;
static integer c__279 = 279;
static integer c__280 = 280;
static integer c__281 = 281;
static integer c__282 = 282;
static integer c__283 = 283;
static integer c__284 = 284;
static integer c__285 = 285;
static integer c__286 = 286;
static integer c__300 = 300;
static integer c__301 = 301;
static integer c__302 = 302;
static integer c__303 = 303;
static integer c__304 = 304;
static integer c__305 = 305;
static integer c__306 = 306;
static integer c__307 = 307;
static integer c__308 = 308;
static integer c__309 = 309;
static integer c__310 = 310;
static integer c__311 = 311;
static integer c__312 = 312;
static integer c__313 = 313;
static integer c__314 = 314;
static integer c__320 = 320;
static integer c__321 = 321;
static integer c__2 = 2;
static integer c__1 = 1;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.02/ifuncs                            * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ifuncs_0_(int n__, real *r1, real *r2, real *r3, integer 
	*errind, real *xga, real *xfa, real *xgb, real *xgc, real *xfb, real *
	xfc, real *r4, real *r5, real *r6, real *r7, real *r8, real *r9, real 
	*r10, real *r11, real *r12, real *ra, real *rb, integer *i1, integer *
	i2, integer *i3, integer *i4, integer *i5, integer *i6, integer *i7, 
	integer *i8, integer *wkid, real *vclip, integer *ia, integer *ib, 
	real *rc, real *rd, integer *i9, integer *i10, integer *i11, integer *
	i12, integer *i13, char *chars, char *charsa, integer *ia2, integer *
	ic, integer *id, integer *ie, integer *if__, integer *ig, integer *ih,
	 integer *ib2, char *charsb, ftnlen chars_len, ftnlen charsa_len, 
	ftnlen charsb_len)
{
    extern /* Subroutine */ int nsc (real *, real *, integer *, real *), nro (
	    real *, integer *, real *), ntp (real *, real *, real *, integer *
	    , real *, real *), ntr (real *, real *, integer *, real *), nsc3 (
	    real *, real *, real *, integer *, real *), ntp3 (real *, real *, 
	    real *, real *, integer *, real *, real *, real *), ntr3 (real *, 
	    real *, real *, integer *, real *), nrox (real *, integer *, real 
	    *), nroy (real *, integer *, real *), nroz (real *, integer *, 
	    real *), ncom (real *, real *, integer *, real *), nqir (integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    ), nqcr (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *), nqif (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqcf (integer *, integer *, integer *, integer *, integer *, 
	    real *), nqdp (integer *, integer *, integer *), nqep (integer *, 
	    integer *), nels (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     ncom3 (real *, real *, integer *, real *), niss (real *, real *, 
	    real *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), niss3 (real *, real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), ichkz_(
	    integer *, integer *), nbltm3 (real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    integer *, real *), nbltm (real *, real *, real *, real *, real *,
	     real *, real *, integer *, real *), ncotm3 (real *, real *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, integer *, real *), ncotm (real *, real *, real *
	    , real *, real *, real *, real *, real *, integer *, real *), 
	    nevom3 (real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, integer *, real *), nevom (real *, real *, real *,
	     real *, integer *, real *), nevmm3 (real *, real *, integer *, 
	    real *, real *, real *, real *, real *, real *, integer *, real *)
	    , nevmm (real *, real *, integer *, real *), nqewk (integer *, 
	    integer *, integer *, integer *), nqphf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nqgsef (integer *, integer *, integer *, integer *, 
	    integer *), nqmclf (integer *, integer *, integer *, integer *, 
	    integer *), nqedm (integer *, integer *), nqopwk (integer *, 
	    integer *, integer *, integer *), nqsid (integer *, integer *, 
	    integer *, integer *), nqarf (integer *, integer *, integer *, 
	    integer *, integer *), nqcnrs (integer *, integer *, integer *), 
	    nqcst (integer *, integer *, integer *, integer *, integer *), 
	    nqcstn (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nqsim (integer *, integer *), nqwkc (
	    integer *, integer *, integer *, integer *), nqevwi (integer *, 
	    integer *, integer *, integer *, integer *), nqvwr (integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , integer *, integer *, integer *), nqhrm (integer *, integer *, 
	    integer *, integer *, integer *), nqpost (integer *, integer *, 
	    integer *, integer *, integer *, real *), nqdus (integer *, 
	    integer *, integer *, integer *, integer *, integer *), nqepli (
	    integer *, integer *, integer *, integer *, integer *), nqplr (
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *), nqepmi (integer *, integer *, integer *, integer *, 
	    integer *), nqpmr (integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *), nqetxi (integer *, integer *, 
	    integer *, integer *, integer *), nqtxr (integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *), nqeii (integer *, integer *, integer *, integer *, 
	    integer *), nqeedi (integer *, integer *, integer *, integer *, 
	    integer *), nqedr (integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *), nqepai (integer *, 
	    integer *, integer *, integer *, integer *), nqpar (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nqcmd (integer *, integer *, integer *), 
	    nqeci (integer *, integer *, integer *, integer *, integer *), 
	    nqhlft (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), nqivft (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqwkt3 (integer *, integer *, integer *, real *, real *, real *, 
	    real *), nqwkt (integer *, integer *, integer *, real *, real *, 
	    real *, real *), nqwkca (integer *, integer *, integer *), 
	    nqdsp3 (integer *, integer *, integer *, real *, real *, real *, 
	    integer *, integer *, integer *), nqdsp (integer *, integer *, 
	    integer *, real *, real *, integer *, integer *), nqhrif (integer 
	    *, integer *, integer *, integer *, integer *), nqhrmf (integer *,
	     integer *, integer *, integer *, integer *), nqvwf (integer *, 
	    integer *, integer *), nqpvwr (integer *, integer *, integer *, 
	    real *, real *, real *, integer *, integer *, integer *), nqwkcl (
	    integer *, integer *, integer *), nqdswa (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqddus (integer *, integer *, integer *, integer *), nqplf (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    real *, real *, real *, integer *), nqpplr (integer *, integer *, 
	    integer *, integer *, real *, integer *), nqpmf (integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, integer *), nqppmr (integer *, integer *, integer 
	    *, integer *, real *, integer *), nqtxf (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, integer *, real *, real *, integer *), nqptxr (integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    integer *), nqanf (integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, real *), nqtxx (integer *, integer *
	    , real *, real *, real *, integer *, integer *, integer *, char *,
	     integer *, real *, real *, real *, real *, ftnlen), nqpir (
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqedf (integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *), nqpedr (integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *), 
	    nqpaf (integer *, integer *, integer *), nqppar (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nqcmdf (integer *, integer *, integer *, integer *, 
	    integer *, integer *), nqpcr (integer *, integer *, integer *, 
	    integer *, integer *, real *), nqegd3 (integer *, integer *, 
	    integer *, integer *, integer *), nqegdp (integer *, integer *, 
	    integer *, integer *, integer *), nqgdp3 (integer *, integer *, 
	    integer *, integer *, integer *), nqgdp (integer *, integer *, 
	    integer *, integer *, integer *), nqegse (integer *, integer *, 
	    integer *, integer *, integer *), nqwksl (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), nqdstr (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), nqwkpo (integer *, 
	    integer *, integer *, integer *, integer *), nqopst (integer *, 
	    integer *, integer *), nqcets (integer *, integer *, integer *, 
	    integer *, integer *), nqceco (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, integer *, 
	    integer *, char *, ftnlen), nqets (integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *), nqeco (integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *, integer *, char *, 
	    ftnlen), nqstst (integer *, integer *, integer *), nqpan (integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *), nqpde (integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nqiqov (integer *, integer *, integer *, integer *), nqerhm (
	    integer *, integer *), nprec (integer *, integer *, integer *, 
	    real *, integer *, integer *, char *, integer *, integer *, 
	    integer *, char *, ftnlen, ftnlen), nurec (integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, integer *, integer *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
/* Subroutine */ int ifuncs_0_(n__, r1, r2, r3, errind, xga, xfa, xgb, xgc, 
	xfb, xfc, r4, r5, r6, r7, r8, r9, r10, r11, r12, ra, rb, i1, i2, i3, 
	i4, i5, i6, i7, i8, wkid, vclip, ia, ib, rc, rd, i9, i10, i11, i12, 
	i13, chars, charsa, ia2, ic, id, ie, if__, ig, ih, ib2, charsb, 
	chars_len, charsa_len, charsb_len)
int n__;
real *r1, *r2, *r3;
integer *errind;
real *xga, *xfa, *xgb, *xgc, *xfb, *xfc, *r4, *r5, *r6, *r7, *r8, *r9, *r10, *
	r11, *r12, *ra, *rb;
integer *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *wkid;
real *vclip;
integer *ia, *ib;
real *rc, *rd;
integer *i9, *i10, *i11, *i12, *i13;
char *chars, *charsa;
integer *ia2, *ic, *id, *ie, *if__, *ig, *ih, *ib2;
char *charsb;
ftnlen chars_len;
ftnlen charsa_len;
ftnlen charsb_len;
{
    extern /* Subroutine */ int nsc (), nro (), ntp (), ntr (), nsc3 (), 
	    ntp3 (), ntr3 (), nrox (), nroy (), nroz (), ncom (), nqir (), 
	    nqcr (), nqif (), nqcf (), nqdp (), nqep (), nels (), ncom3 (), 
	    niss (), niss3 (), ichkz_(), nbltm3 (), nbltm (), ncotm3 (), 
	    ncotm (), nevom3 (), nevom (), nevmm3 (), nevmm (), nqewk (), 
	    nqphf (), nqgsef (), nqmclf (), nqedm (), nqopwk (), nqsid (), 
	    nqarf (), nqcnrs (), nqcst (), nqcstn (), nqsim (), nqwkc (), 
	    nqevwi (), nqvwr (), nqhrm (), nqpost (), nqdus (), nqepli (), 
	    nqplr (), nqepmi (), nqpmr (), nqetxi (), nqtxr (), nqeii (), 
	    nqeedi (), nqedr (), nqepai (), nqpar (), nqcmd (), nqeci (), 
	    nqhlft (), nqivft (), nqwkt3 (), nqwkt (), nqwkca (), nqdsp3 (), 
	    nqdsp (), nqhrif (), nqhrmf (), nqvwf (), nqpvwr (), nqwkcl (), 
	    nqdswa (), nqddus (), nqplf (), nqpplr (), nqpmf (), nqppmr (), 
	    nqtxf (), nqptxr (), nqanf (), nqtxx (), nqpir (), nqedf (), 
	    nqpedr (), nqpaf (), nqppar (), nqcmdf (), nqpcr (), nqegd3 (), 
	    nqegdp (), nqgdp3 (), nqgdp (), nqegse (), nqwksl (), nqdstr (), 
	    nqwkpo (), nqopst (), nqcets (), nqceco (), nqets (), nqeco (), 
	    nqstst (), nqpan (), nqpde (), nqiqov (), nqerhm (), nprec (), 
	    nurec ();
#endif /* NO_PROTO */

/*  IFUNCS is the home of the entry points for PHIGS functions which */
/*  are called in order to generate a non-zero error indicator. */
/*  The functions are followed a a call to ICHKZ which tests what */
/*  the actual error code is among the expected error codes. */
/*  PHIGS function names (for those functions which return non-zero */
/*  error indicator) */
/* *** *** *** Transformation/Utility functions to support medelling */
    /* Parameter adjustments */
    if (xga) {
	xga -= 5;
	}
    if (xfa) {
	xfa -= 4;
	}
    if (xgb) {
	xgb -= 5;
	}
    if (xgc) {
	xgc -= 5;
	}
    if (xfb) {
	xfb -= 4;
	}
    if (xfc) {
	xfc -= 4;
	}
    if (ra) {
	--ra;
	}
    if (rb) {
	--rb;
	}
    if (vclip) {
	--vclip;
	}
    if (ia) {
	--ia;
	}
    if (ib) {
	--ib;
	}
    if (rc) {
	--rc;
	}
    if (rd) {
	--rd;
	}
    if (charsa) {
	charsa -= charsa_len;
	}
    if (ia2) {
	ia2 -= 3;
	}
    if (ic) {
	--ic;
	}
    if (id) {
	--id;
	}
    if (ie) {
	--ie;
	}
    if (if__) {
	--if__;
	}
    if (ig) {
	--ig;
	}
    if (ih) {
	--ih;
	}
    if (ib2) {
	ib2 -= 3;
	}
    if (charsb) {
	charsb -= charsb_len;
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_rtr3;
	case 2: goto L_rtr;
	case 3: goto L_rsc3;
	case 4: goto L_rsc;
	case 5: goto L_rrox;
	case 6: goto L_rroy;
	case 7: goto L_rroz;
	case 8: goto L_rro;
	case 9: goto L_rcom3;
	case 10: goto L_rcom;
	case 11: goto L_rtp3;
	case 12: goto L_rtp;
	case 13: goto L_rbltm3;
	case 14: goto L_rbltm;
	case 15: goto L_rcotm3;
	case 16: goto L_rcotm;
	case 17: goto L_revom3;
	case 18: goto L_revom;
	case 19: goto L_revmm3;
	case 20: goto L_revmm;
	case 21: goto L_rqewk;
	case 22: goto L_rqphf;
	case 23: goto L_rqgsef;
	case 24: goto L_rqmclf;
	case 25: goto L_rqedm;
	case 26: goto L_rqopwk;
	case 27: goto L_rqsid;
	case 28: goto L_rqarf;
	case 29: goto L_rqcnrs;
	case 30: goto L_rqcst;
	case 31: goto L_rqcstn;
	case 32: goto L_rqsim;
	case 33: goto L_rqwkc;
	case 34: goto L_rqevwi;
	case 35: goto L_rqvwr;
	case 36: goto L_rqhrm;
	case 37: goto L_rqpost;
	case 38: goto L_rqdus;
	case 39: goto L_rqepli;
	case 40: goto L_rqplr;
	case 41: goto L_rqepmi;
	case 42: goto L_rqpmr;
	case 43: goto L_rqetxi;
	case 44: goto L_rqtxr;
	case 45: goto L_rqeii;
	case 46: goto L_rqir;
	case 47: goto L_rqeedi;
	case 48: goto L_rqedr;
	case 49: goto L_rqepai;
	case 50: goto L_rqpar;
	case 51: goto L_rqcmd;
	case 52: goto L_rqeci;
	case 53: goto L_rqcr;
	case 54: goto L_rqhlft;
	case 55: goto L_rqivft;
	case 56: goto L_rqwkt3;
	case 57: goto L_rqwkt;
	case 58: goto L_rqwkca;
	case 59: goto L_rqdsp3;
	case 60: goto L_rqdsp;
	case 61: goto L_rqhrif;
	case 62: goto L_rqhrmf;
	case 63: goto L_rqvwf;
	case 64: goto L_rqpvwr;
	case 65: goto L_rqwkcl;
	case 66: goto L_rqdswa;
	case 67: goto L_rqddus;
	case 68: goto L_rqplf;
	case 69: goto L_rqpplr;
	case 70: goto L_rqpmf;
	case 71: goto L_rqppmr;
	case 72: goto L_rqtxf;
	case 73: goto L_rqptxr;
	case 74: goto L_rqanf;
	case 75: goto L_rqtxx;
	case 76: goto L_rqif;
	case 77: goto L_rqpir;
	case 78: goto L_rqedf;
	case 79: goto L_rqpedr;
	case 80: goto L_rqpaf;
	case 81: goto L_rqppar;
	case 82: goto L_rqcmdf;
	case 83: goto L_rqcf;
	case 84: goto L_rqpcr;
	case 85: goto L_rqegd3;
	case 86: goto L_rqegdp;
	case 87: goto L_rqgdp3;
	case 88: goto L_rqgdp;
	case 89: goto L_rqegse;
	case 90: goto L_rqdp;
	case 91: goto L_rqwksl;
	case 92: goto L_rqdstr;
	case 93: goto L_rqwkpo;
	case 94: goto L_rqopst;
	case 95: goto L_rqep;
	case 96: goto L_rqcets;
	case 97: goto L_rqceco;
	case 98: goto L_rqets;
	case 99: goto L_rqeco;
	case 100: goto L_rqstst;
	case 101: goto L_rqpan;
	case 102: goto L_rqpde;
	case 103: goto L_rels;
	case 104: goto L_riss3;
	case 105: goto L_riss;
	case 106: goto L_rqiqov;
	case 107: goto L_rqerhm;
	case 108: goto L_rprec;
	case 109: goto L_rurec;
	}


L_rtr3:
    ntr3 (r1, r2, r3, errind, &xga[5]);
    ichkz_(errind, &c__91);
    return 0;

L_rtr:
    ntr (r1, r2, errind, &xfa[4]);
    ichkz_(errind, &c__92);
    return 0;

L_rsc3:
    nsc3 (r1, r2, r3, errind, &xga[5]);
    ichkz_(errind, &c__93);
    return 0;

L_rsc:
    nsc (r1, r2, errind, &xfa[4]);
    ichkz_(errind, &c__94);
    return 0;

L_rrox:
    nrox (r1, errind, &xga[5]);
    ichkz_(errind, &c__95);
    return 0;

L_rroy:
    nroy (r1, errind, &xga[5]);
    ichkz_(errind, &c__95);
    return 0;

L_rroz:
    nroz (r1, errind, &xga[5]);
    ichkz_(errind, &c__97);
    return 0;

L_rro:
    nro (r1, errind, &xfa[4]);
    ichkz_(errind, &c__98);
    return 0;

L_rcom3:
    ncom3 (&xga[5], &xgb[5], errind, &xgc[5]);
    ichkz_(errind, &c__99);
    return 0;

L_rcom:
    ncom (&xfa[4], &xfb[4], errind, &xfc[4]);
    ichkz_(errind, &c__100);
    return 0;

L_rtp3:
    ntp3 (r1, r2, r3, &xga[5], errind, r4, r5, r6);
    ichkz_(errind, &c__101);
    return 0;

L_rtp:
    ntp (r1, r2, &xfa[4], errind, r3, r4);
    ichkz_(errind, &c__102);
    return 0;

L_rbltm3:
    nbltm3 (r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, errind, &xga[5]
	    );
    ichkz_(errind, &c__103);
    return 0;

L_rbltm:
    nbltm (r1, r2, r3, r4, r5, r6, r7, errind, &xfa[4]);
    ichkz_(errind, &c__104);
    return 0;

L_rcotm3:
    ncotm3 (&xga[5], r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, 
	    errind, &xgb[5]);
    ichkz_(errind, &c__105);
    return 0;

L_rcotm:
    ncotm (&xfa[4], r1, r2, r3, r4, r5, r6, r7, errind, &xfb[4]);
    ichkz_(errind, &c__106);
    return 0;
/* *** *** *** Transformation/Utility functions to support viewing */

L_revom3:
    nevom3 (r1, r2, r3, r4, r5, r6, r7, r8, r9, errind, &xga[5]);
    ichkz_(errind, &c__107);
    return 0;

L_revom:
    nevom (r1, r2, r3, r4, errind, &xfa[4]);
    ichkz_(errind, &c__108);
    return 0;

L_revmm3:
    nevmm3 (&ra[1], &rb[1], i1, r1, r2, r3, r4, r5, r6, errind, &xga[5]);
    ichkz_(errind, &c__109);
    return 0;

L_revmm:
    nevmm (&ra[1], &rb[1], errind, &xfa[4]);
    ichkz_(errind, &c__110);
    return 0;
/* *** *** *** Inquiry/PHIGS Description Table */

L_rqewk:
    nqewk (i1, errind, i2, i3);
    ichkz_(errind, &c__204);
    return 0;

L_rqphf:
    nqphf (i1, errind, i2, i3, i4, i5, i6, i7, i8);
    ichkz_(errind, &c__205);
    return 0;

L_rqgsef:
    nqgsef (i1, errind, i2, i3, i4);
    ichkz_(errind, &c__206);
    return 0;

L_rqmclf:
    nqmclf (i1, errind, i2, i3, i4);
    ichkz_(errind, &c__207);
    return 0;
/* *** *** *** Inquiry/PHIGS State List */

L_rqedm:
    nqedm (errind, i1);
    ichkz_(errind, &c__208);
    return 0;

L_rqopwk:
    nqopwk (i1, errind, i2, i3);
    ichkz_(errind, &c__209);
    return 0;

L_rqsid:
    nqsid (i2, errind, i2, i3);
    ichkz_(errind, &c__210);
    return 0;

L_rqarf:
    nqarf (i1, errind, i2, i3, i4);
    ichkz_(errind, &c__211);
    return 0;

L_rqcnrs:
    nqcnrs (errind, i1, i2);
    ichkz_(errind, &c__212);
    return 0;

L_rqcst:
    nqcst (i1, i2, errind, i3, i4);
    ichkz_(errind, &c__213);
    return 0;

L_rqcstn:
    nqcstn (i1, i2, i3, i4, errind, i5, i6);
    ichkz_(errind, &c__214);
    return 0;

L_rqsim:
    nqsim (errind, i1);
    ichkz_(errind, &c__215);
    return 0;
/* *** *** *** Inquiry/workstation state list */

L_rqwkc:
    nqwkc (wkid, errind, i2, i3);
    ichkz_(errind, &c__216);
    return 0;

L_rqevwi:
    nqevwi (wkid, i1, errind, i2, i3);
    ichkz_(errind, &c__217);
    return 0;

L_rqvwr:
    nqvwr (wkid, i1, i2, errind, i3, &xga[5], &xgb[5], &vclip[1], i4, i5, i6);

    ichkz_(errind, &c__218);
    return 0;

L_rqhrm:
    nqhrm (wkid, errind, i1, i2, i3);
    ichkz_(errind, &c__219);
    return 0;

L_rqpost:
    nqpost (wkid, i1, errind, i2, i3, r1);
    ichkz_(errind, &c__220);
    return 0;

L_rqdus:
    nqdus (wkid, errind, i1, i2, i3, i4);
    ichkz_(errind, &c__221);
    return 0;

L_rqepli:
    nqepli (wkid, i1, errind, i2, i3);
    ichkz_(errind, &c__222);
    return 0;

L_rqplr:
    nqplr (wkid, i1, i2, errind, i3, r1, i4);
    ichkz_(errind, &c__223);
    return 0;

L_rqepmi:
    nqepmi (wkid, i1, errind, i2, i3);
    ichkz_(errind, &c__224);
    return 0;

L_rqpmr:
    nqpmr (wkid, i1, i2, errind, i3, r1, i4);
    ichkz_(errind, &c__225);
    return 0;

L_rqetxi:
    nqetxi (wkid, i1, errind, i2, i3);
    ichkz_(errind, &c__226);
    return 0;

L_rqtxr:
    nqtxr (wkid, i1, i2, errind, i3, i4, r1, r2, i5);
    ichkz_(errind, &c__227);
    return 0;

L_rqeii:
    nqeii (wkid, i1, errind, i2, i3);
    ichkz_(errind, &c__228);
    return 0;

L_rqir:
    nqir (wkid, i1, i2, errind, i3, i4, i5);
    ichkz_(errind, &c__229);
    return 0;

L_rqeedi:
    nqeedi (wkid, i1, errind, i2, i3);
    ichkz_(errind, &c__230);
    return 0;

L_rqedr:
    nqedr (wkid, i1, i2, errind, i3, i4, r1, i5);
    ichkz_(errind, &c__231);
    return 0;

L_rqepai:
    nqepai (wkid, i1, errind, i2, i3);
    ichkz_(errind, &c__232);
    return 0;

L_rqpar:
    nqpar (wkid, i1, i2, i3, i4, errind, i5, i6, &ia[1]);
    ichkz_(errind, &c__233);
    return 0;

L_rqcmd:
    nqcmd (wkid, errind, i1);
    ichkz_(errind, &c__234);
    return 0;

L_rqeci:
    nqeci (wkid, i1, errind, i2, i3);
    ichkz_(errind, &c__235);
    return 0;

L_rqcr:
    nqcr (wkid, i1, i2, i3, errind, i4, &ra[1]);
    ichkz_(errind, &c__236);
    return 0;

L_rqhlft:
    nqhlft (wkid, i1, i2, errind, i3, &ia[1], i4, &ib[1]);
    ichkz_(errind, &c__237);
    return 0;

L_rqivft:
    nqivft (wkid, i1, i2, errind, i3, &ia[1], i4, &ib[1]);
    ichkz_(errind, &c__238);
    return 0;

L_rqwkt3:
    nqwkt3 (wkid, errind, i1, &ra[1], &rb[1], &rc[1], &rd[1]);
    ichkz_(errind, &c__239);
    return 0;

L_rqwkt:
    nqwkt (wkid, errind, i1, &ra[1], &rb[1], &rc[1], &rd[1]);
    ichkz_(errind, &c__240);
    return 0;
/* *** *** *** Inquiry/WSL/Input Devices */
/* *** *** *** Inquiry/Workstation Description Table */

L_rqwkca:
    nqwkca (i1, errind, i2);
    ichkz_(errind, &c__253);
    return 0;

L_rqdsp3:
    nqdsp3 (i1, errind, i2, r1, r2, r3, i3, i4, i5);
    ichkz_(errind, &c__254);
    return 0;

L_rqdsp:
    nqdsp (i1, errind, i2, r1, r2, i4, i5);
    ichkz_(errind, &c__255);
    return 0;

L_rqhrif:
    nqhrif (i1, i2, errind, i3, i4);
    ichkz_(errind, &c__256);
    return 0;

L_rqhrmf:
    nqhrmf (i1, i2, errind, i3, i4);
    ichkz_(errind, &c__256);
    return 0;

L_rqvwf:
    nqvwf (i1, errind, i2);
    ichkz_(errind, &c__257);
    return 0;

L_rqpvwr:
    nqpvwr (i1, i2, errind, &xga[5], &xgb[5], &vclip[1], i3, i4, i5);
    ichkz_(errind, &c__258);
    return 0;

L_rqwkcl:
    nqwkcl (i1, errind, i2);
    ichkz_(errind, &c__259);
    return 0;

L_rqdswa:
    nqdswa (i1, errind, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13);
    ichkz_(errind, &c__260);
    return 0;

L_rqddus:
    nqddus (i1, errind, i2, i3);
    ichkz_(errind, &c__261);
    return 0;
/* *** *** *** Inquiry/WDT/Output Primitives and Attributes */

L_rqplf:
    nqplf (i1, i2, errind, i3, i4, i5, r1, r2, r3, i6);
    ichkz_(errind, &c__262);
    return 0;

L_rqpplr:
    nqpplr (i1, i2, errind, i3, r1, i4);
    ichkz_(errind, &c__263);
    return 0;

L_rqpmf:
    nqpmf (i1, i2, errind, i3, i4, i5, r1, r2, r3, i6);
    ichkz_(errind, &c__264);
    return 0;

L_rqppmr:
    nqppmr (i2, i3, errind, i3, r1, i4);
    ichkz_(errind, &c__265);
    return 0;

L_rqtxf:
    nqtxf (i1, i2, errind, i3, i4, i5, i6, r1, r2, i7, r3, r4, i8);
    ichkz_(errind, &c__266);
    return 0;

L_rqptxr:
    nqptxr (i1, i2, errind, i3, i4, r1, r2, i5);
    ichkz_(errind, &c__267);
    return 0;

L_rqanf:
    nqanf (i1, i2, errind, i3, i4, i5, r1, r2);
    ichkz_(errind, &c__268);
    return 0;

L_rqtxx:
    nqtxx (i1, i2, r1, r2, r3, i3, i4, i5, chars, errind, &ra[1], &rb[1], r4, 
	    r5, chars_len);
    ichkz_(errind, &c__269);
    return 0;

L_rqif:
    nqif (i1, i2, i3, errind, i4, i5, i6, i7, i8);
    ichkz_(errind, &c__270);
    return 0;

L_rqpir:
    nqpir (i1, i2, errind, i3, i4, i5);
    ichkz_(errind, &c__271);
    return 0;

L_rqedf:
    nqedf (i1, i2, errind, i3, i4, i5, r1, r2, r3, i6);
    ichkz_(errind, &c__272);
    return 0;

L_rqpedr:
    nqpedr (i1, i2, errind, i3, i4, r1, i5);
    ichkz_(errind, &c__273);
    return 0;

L_rqpaf:
    nqpaf (i1, errind, i2);
    ichkz_(errind, &c__274);
    return 0;

L_rqppar:
    nqppar (i1, i2, i3, i4, errind, i5, i6, &ia[1]);
    ichkz_(errind, &c__275);
    return 0;

L_rqcmdf:
    nqcmdf (i1, i2, errind, i3, i4, i5);
    ichkz_(errind, &c__276);
    return 0;

L_rqcf:
    nqcf (i1, errind, i2, i3, i4, &ra[1]);
    ichkz_(errind, &c__277);
    return 0;

L_rqpcr:
    nqpcr (i1, i2, i3, errind, i4, &ra[1]);
    ichkz_(errind, &c__278);
    return 0;

L_rqegd3:
    nqegd3 (i1, i2, errind, i3, i4);
    ichkz_(errind, &c__279);
    return 0;

L_rqegdp:
    nqegdp (i1, i2, errind, i3, i4);
    ichkz_(errind, &c__280);
    return 0;

L_rqgdp3:
    nqgdp3 (i1, i2, errind, i3, &ia[1]);
    ichkz_(errind, &c__281);
    return 0;

L_rqgdp:
    nqgdp (i1, i2, errind, i3, &ia[1]);
    ichkz_(errind, &c__282);
    return 0;

L_rqegse:
    nqegse (i1, i2, errind, i3, i4);
    ichkz_(errind, &c__283);
    return 0;
/* *** *** *** Inquiry/WDL/Rendering Features */

L_rqdp:
    nqdp (i1, errind, i2);
    ichkz_(errind, &c__284);
    return 0;

L_rqwksl:
    nqwksl (i1, errind, i2, i3, i4, i5, i6, i7, i8, i9);
    ichkz_(errind, &c__285);
    return 0;

L_rqdstr:
    nqdstr (i1, errind, i2, i3, i4, i5, i6);
    ichkz_(errind, &c__286);
    return 0;
/* *** *** *** Inquiry/Structure State List */

L_rqwkpo:
    nqwkpo (i1, i2, errind, i3, i4);
    ichkz_(errind, &c__300);
    return 0;
/* *** *** *** Inquiry/Structure Content */

L_rqopst:
    nqopst (errind, i1, i2);
    ichkz_(errind, &c__301);
    return 0;

L_rqep:
    nqep (errind, i1);
    ichkz_(errind, &c__302);
    return 0;

L_rqcets:
    nqcets (errind, i1, i2, i3, i4);
    ichkz_(errind, &c__303);
    return 0;

L_rqceco:
    nqceco (i1, i2, i3, errind, i4, &ia[1], i5, &ra[1], i6, &ib[1], charsa + 
	    charsa_len, charsa_len);
    ichkz_(errind, &c__304);
    return 0;

L_rqets:
    nqets (i1, i2, errind, i3, i4, i5, i6);
    ichkz_(errind, &c__305);
    return 0;

L_rqeco:
    nqeco (i1, i2, i3, i4, i5, errind, i6, &ia[1], i7, &ra[1], i8, &ib[1], 
	    charsa + charsa_len, charsa_len);
    ichkz_(errind, &c__306);
    return 0;

L_rqstst:
    nqstst (i1, errind, i2);
    ichkz_(errind, &c__307);
    return 0;

L_rqpan:
    nqpan (i1, i2, i3, i4, i5, errind, i6, i7, &ia2[3]);
    ichkz_(errind, &c__308);
    return 0;

L_rqpde:
    nqpde (i1, i2, i3, i4, i5, errind, i6, i7, &ia2[3]);
    ichkz_(errind, &c__309);
    return 0;

L_rels:
    nels (i1, i2, i3, i4, &ia[1], i5, &ib[1], errind, i6, i7);
    ichkz_(errind, &c__310);
    return 0;

L_riss3:
    niss3 (r1, r2, r3, r4, i1, &ia2[3], i2, i3, i4, &ia[1], &ib[1], &ic[1], &
	    id[1], i5, &ie[1], &if__[1], &ig[1], &ih[1], i6, errind, i7, &ib2[
	    3]);
    ichkz_(errind, &c__311);
    return 0;

L_riss:
    niss (r1, r2, r3, i1, &ia2[3], i2, i3, i4, &ia[1], &ib[1], &ic[1], &id[1],
	     i5, &ie[1], &if__[1], &ig[1], &ih[1], i6, errind, i7, &ib2[3]);
    ichkz_(errind, &c__312);
    return 0;
/* *** *** *** Inquiry/Error State List */

L_rqiqov:
    nqiqov (errind, wkid, i1, i2);
    ichkz_(errind, &c__313);
    return 0;

L_rqerhm:
    nqerhm (errind, i1);
    ichkz_(errind, &c__314);
    return 0;
/* *** *** *** Utility functions */

L_rprec:
    nprec (i1, &ia[1], i2, &ra[1], i3, &ib[1], charsa + charsa_len, i4, 
	    errind, i5, charsb + charsb_len, charsa_len, charsb_len);
    ichkz_(errind, &c__320);
    return 0;

L_rurec:
    nurec (i1, charsa + charsa_len, i2, i3, i4, errind, i5, &ia[1], i6, &ra[1]
	    , i7, &ib[1], charsb + charsb_len, charsa_len, charsb_len);
    ichkz_(errind, &c__321);
    return 0;
} /* ifuncs_ */

#ifndef NO_PROTO
/* Subroutine */ int ifuncs_(void)
#else /* NO_PROTO */
/* Subroutine */ int ifuncs_()
#endif /* NO_PROTO */
{
    return ifuncs_0_(0, (real *)0, (real *)0, (real *)0, (integer *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (real *)0, (integer *
	    )0, (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)
	    0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rtr3_(real *r1, real *r2, real *r3, integer *errind, 
	real *xga)
#else /* NO_PROTO */
/* Subroutine */ int rtr3_(r1, r2, r3, errind, xga)
real *r1, *r2, *r3;
integer *errind;
real *xga;
#endif /* NO_PROTO */
{
    return ifuncs_0_(1, r1, r2, r3, errind, xga, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rtr_(real *r1, real *r2, integer *errind, real *xfa)
#else /* NO_PROTO */
/* Subroutine */ int rtr_(r1, r2, errind, xfa)
real *r1, *r2;
integer *errind;
real *xfa;
#endif /* NO_PROTO */
{
    return ifuncs_0_(2, r1, r2, (real *)0, errind, (real *)0, xfa, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsc3_(real *r1, real *r2, real *r3, integer *errind, 
	real *xga)
#else /* NO_PROTO */
/* Subroutine */ int rsc3_(r1, r2, r3, errind, xga)
real *r1, *r2, *r3;
integer *errind;
real *xga;
#endif /* NO_PROTO */
{
    return ifuncs_0_(3, r1, r2, r3, errind, xga, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsc_(real *r1, real *r2, integer *errind, real *xfa)
#else /* NO_PROTO */
/* Subroutine */ int rsc_(r1, r2, errind, xfa)
real *r1, *r2;
integer *errind;
real *xfa;
#endif /* NO_PROTO */
{
    return ifuncs_0_(4, r1, r2, (real *)0, errind, (real *)0, xfa, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrox_(real *r1, integer *errind, real *xga)
#else /* NO_PROTO */
/* Subroutine */ int rrox_(r1, errind, xga)
real *r1;
integer *errind;
real *xga;
#endif /* NO_PROTO */
{
    return ifuncs_0_(5, r1, (real *)0, (real *)0, errind, xga, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, 
	    (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rroy_(real *r1, integer *errind, real *xga)
#else /* NO_PROTO */
/* Subroutine */ int rroy_(r1, errind, xga)
real *r1;
integer *errind;
real *xga;
#endif /* NO_PROTO */
{
    return ifuncs_0_(6, r1, (real *)0, (real *)0, errind, xga, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, 
	    (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rroz_(real *r1, integer *errind, real *xga)
#else /* NO_PROTO */
/* Subroutine */ int rroz_(r1, errind, xga)
real *r1;
integer *errind;
real *xga;
#endif /* NO_PROTO */
{
    return ifuncs_0_(7, r1, (real *)0, (real *)0, errind, xga, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, 
	    (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rro_(real *r1, integer *errind, real *xfa)
#else /* NO_PROTO */
/* Subroutine */ int rro_(r1, errind, xfa)
real *r1;
integer *errind;
real *xfa;
#endif /* NO_PROTO */
{
    return ifuncs_0_(8, r1, (real *)0, (real *)0, errind, (real *)0, xfa, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, 
	    (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rcom3_(real *xga, real *xgb, integer *errind, real *xgc)
#else /* NO_PROTO */
/* Subroutine */ int rcom3_(xga, xgb, errind, xgc)
real *xga, *xgb;
integer *errind;
real *xgc;
#endif /* NO_PROTO */
{
    return ifuncs_0_(9, (real *)0, (real *)0, (real *)0, errind, xga, (real *)
	    0, xgb, xgc, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)
	    0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rcom_(real *xfa, real *xfb, integer *errind, real *xfc)
#else /* NO_PROTO */
/* Subroutine */ int rcom_(xfa, xfb, errind, xfc)
real *xfa, *xfb;
integer *errind;
real *xfc;
#endif /* NO_PROTO */
{
    return ifuncs_0_(10, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    xfa, (real *)0, (real *)0, xfb, xfc, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *)0, 
	    (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rtp3_(real *r1, real *r2, real *r3, real *xga, integer *
	errind, real *r4, real *r5, real *r6)
#else /* NO_PROTO */
/* Subroutine */ int rtp3_(r1, r2, r3, xga, errind, r4, r5, r6)
real *r1, *r2, *r3, *xga;
integer *errind;
real *r4, *r5, *r6;
#endif /* NO_PROTO */
{
    return ifuncs_0_(11, r1, r2, r3, errind, xga, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (real *)0, r4, r5, r6, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *
	    )0, (integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *
	    )0, (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rtp_(real *r1, real *r2, real *xfa, integer *errind, 
	real *r3, real *r4)
#else /* NO_PROTO */
/* Subroutine */ int rtp_(r1, r2, xfa, errind, r3, r4)
real *r1, *r2, *xfa;
integer *errind;
real *r3, *r4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(12, r1, r2, r3, errind, (real *)0, xfa, (real *)0, (real 
	    *)0, (real *)0, (real *)0, r4, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rbltm3_(real *r1, real *r2, real *r3, real *r4, real *r5,
	 real *r6, real *r7, real *r8, real *r9, real *r10, real *r11, real *
	r12, integer *errind, real *xga)
#else /* NO_PROTO */
/* Subroutine */ int rbltm3_(r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, 
	r12, errind, xga)
real *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9, *r10, *r11, *r12;
integer *errind;
real *xga;
#endif /* NO_PROTO */
{
    return ifuncs_0_(13, r1, r2, r3, errind, xga, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (real *)0, r4, r5, r6, r7, r8, r9, r10, r11, r12, 
	    (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rbltm_(real *r1, real *r2, real *r3, real *r4, real *r5, 
	real *r6, real *r7, integer *errind, real *xfa)
#else /* NO_PROTO */
/* Subroutine */ int rbltm_(r1, r2, r3, r4, r5, r6, r7, errind, xfa)
real *r1, *r2, *r3, *r4, *r5, *r6, *r7;
integer *errind;
real *xfa;
#endif /* NO_PROTO */
{
    return ifuncs_0_(14, r1, r2, r3, errind, (real *)0, xfa, (real *)0, (real 
	    *)0, (real *)0, (real *)0, r4, r5, r6, r7, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rcotm3_(real *xga, real *r1, real *r2, real *r3, real *
	r4, real *r5, real *r6, real *r7, real *r8, real *r9, real *r10, real 
	*r11, real *r12, integer *errind, real *xgb)
#else /* NO_PROTO */
/* Subroutine */ int rcotm3_(xga, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, 
	r11, r12, errind, xgb)
real *xga, *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9, *r10, *r11, *r12;
integer *errind;
real *xgb;
#endif /* NO_PROTO */
{
    return ifuncs_0_(15, r1, r2, r3, errind, xga, (real *)0, xgb, (real *)0, (
	    real *)0, (real *)0, r4, r5, r6, r7, r8, r9, r10, r11, r12, (real 
	    *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rcotm_(real *xfa, real *r1, real *r2, real *r3, real *r4,
	 real *r5, real *r6, real *r7, integer *errind, real *xfb)
#else /* NO_PROTO */
/* Subroutine */ int rcotm_(xfa, r1, r2, r3, r4, r5, r6, r7, errind, xfb)
real *xfa, *r1, *r2, *r3, *r4, *r5, *r6, *r7;
integer *errind;
real *xfb;
#endif /* NO_PROTO */
{
    return ifuncs_0_(16, r1, r2, r3, errind, (real *)0, xfa, (real *)0, (real 
	    *)0, xfb, (real *)0, r4, r5, r6, r7, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (real *)0, (integer *
	    )0, (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)
	    0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int revom3_(real *r1, real *r2, real *r3, real *r4, real *r5,
	 real *r6, real *r7, real *r8, real *r9, integer *errind, real *xga)
#else /* NO_PROTO */
/* Subroutine */ int revom3_(r1, r2, r3, r4, r5, r6, r7, r8, r9, errind, xga)
real *r1, *r2, *r3, *r4, *r5, *r6, *r7, *r8, *r9;
integer *errind;
real *xga;
#endif /* NO_PROTO */
{
    return ifuncs_0_(17, r1, r2, r3, errind, xga, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (real *)0, r4, r5, r6, r7, r8, r9, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (integer *)0, 
	    (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int revom_(real *r1, real *r2, real *r3, real *r4, integer *
	errind, real *xfa)
#else /* NO_PROTO */
/* Subroutine */ int revom_(r1, r2, r3, r4, errind, xfa)
real *r1, *r2, *r3, *r4;
integer *errind;
real *xfa;
#endif /* NO_PROTO */
{
    return ifuncs_0_(18, r1, r2, r3, errind, (real *)0, xfa, (real *)0, (real 
	    *)0, (real *)0, (real *)0, r4, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int revmm3_(real *ra, real *rb, integer *i1, real *r1, real *
	r2, real *r3, real *r4, real *r5, real *r6, integer *errind, real *
	xga)
#else /* NO_PROTO */
/* Subroutine */ int revmm3_(ra, rb, i1, r1, r2, r3, r4, r5, r6, errind, xga)
real *ra, *rb;
integer *i1;
real *r1, *r2, *r3, *r4, *r5, *r6;
integer *errind;
real *xga;
#endif /* NO_PROTO */
{
    return ifuncs_0_(19, r1, r2, r3, errind, xga, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (real *)0, r4, r5, r6, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, ra, rb, i1, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (integer *)0, 
	    (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int revmm_(real *ra, real *rb, integer *errind, real *xfa)
#else /* NO_PROTO */
/* Subroutine */ int revmm_(ra, rb, errind, xfa)
real *ra, *rb;
integer *errind;
real *xfa;
#endif /* NO_PROTO */
{
    return ifuncs_0_(20, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    xfa, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, ra, rb, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)
	    0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqewk_(integer *i1, integer *errind, integer *i2, 
	integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqewk_(i1, errind, i2, i3)
integer *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(21, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqphf_(integer *i1, integer *errind, integer *i2, 
	integer *i3, integer *i4, integer *i5, integer *i6, integer *i7, 
	integer *i8)
#else /* NO_PROTO */
/* Subroutine */ int rqphf_(i1, errind, i2, i3, i4, i5, i6, i7, i8)
integer *i1, *errind, *i2, *i3, *i4, *i5, *i6, *i7, *i8;
#endif /* NO_PROTO */
{
    return ifuncs_0_(22, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6,
	     i7, i8, (integer *)0, (real *)0, (integer *)0, (integer *)0, (
	    real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqgsef_(integer *i1, integer *errind, integer *i2, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqgsef_(i1, errind, i2, i3, i4)
integer *i1, *errind, *i2, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(23, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqmclf_(integer *i1, integer *errind, integer *i2, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqmclf_(i1, errind, i2, i3, i4)
integer *i1, *errind, *i2, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(24, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqedm_(integer *errind, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rqedm_(errind, i1)
integer *errind, *i1;
#endif /* NO_PROTO */
{
    return ifuncs_0_(25, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, 
	    (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqopwk_(integer *i1, integer *errind, integer *i2, 
	integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqopwk_(i1, errind, i2, i3)
integer *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(26, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqsid_(integer *i1, integer *errind, integer *i2, 
	integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqsid_(i1, errind, i2, i3)
integer *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(27, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqarf_(integer *i1, integer *errind, integer *i2, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqarf_(i1, errind, i2, i3, i4)
integer *i1, *errind, *i2, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(28, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqcnrs_(integer *errind, integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rqcnrs_(errind, i1, i2)
integer *errind, *i1, *i2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(29, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqcst_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqcst_(i1, i2, errind, i3, i4)
integer *i1, *i2, *errind, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(30, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqcstn_(integer *i1, integer *i2, integer *i3, integer *
	i4, integer *errind, integer *i5, integer *i6)
#else /* NO_PROTO */
/* Subroutine */ int rqcstn_(i1, i2, i3, i4, errind, i5, i6)
integer *i1, *i2, *i3, *i4, *errind, *i5, *i6;
#endif /* NO_PROTO */
{
    return ifuncs_0_(31, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6,
	     (integer *)0, (integer *)0, (integer *)0, (real *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqsim_(integer *errind, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rqsim_(errind, i1)
integer *errind, *i1;
#endif /* NO_PROTO */
{
    return ifuncs_0_(32, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, 
	    (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqwkc_(integer *wkid, integer *errind, integer *i2, 
	integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqwkc_(wkid, errind, i2, i3)
integer *wkid, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(33, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (integer *)0, i2, i3, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, wkid, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *
	    )0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqevwi_(integer *wkid, integer *i1, integer *errind, 
	integer *i2, integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqevwi_(wkid, i1, errind, i2, i3)
integer *wkid, *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(34, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqvwr_(integer *wkid, integer *i1, integer *i2, integer *
	errind, integer *i3, real *xga, real *xgb, real *vclip, integer *i4, 
	integer *i5, integer *i6)
#else /* NO_PROTO */
/* Subroutine */ int rqvwr_(wkid, i1, i2, errind, i3, xga, xgb, vclip, i4, i5,
	 i6)
integer *wkid, *i1, *i2, *errind, *i3;
real *xga, *xgb, *vclip;
integer *i4, *i5, *i6;
#endif /* NO_PROTO */
{
    return ifuncs_0_(35, (real *)0, (real *)0, (real *)0, errind, xga, (real *
	    )0, xgb, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6, (integer *
	    )0, (integer *)0, wkid, vclip, (integer *)0, (integer *)0, (real *
	    )0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqhrm_(integer *wkid, integer *errind, integer *i1, 
	integer *i2, integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqhrm_(wkid, errind, i1, i2, i3)
integer *wkid, *errind, *i1, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(36, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpost_(integer *wkid, integer *i1, integer *errind, 
	integer *i2, integer *i3, real *r1)
#else /* NO_PROTO */
/* Subroutine */ int rqpost_(wkid, i1, errind, i2, i3, r1)
integer *wkid, *i1, *errind, *i2, *i3;
real *r1;
#endif /* NO_PROTO */
{
    return ifuncs_0_(37, r1, (real *)0, (real *)0, errind, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqdus_(integer *wkid, integer *errind, integer *i1, 
	integer *i2, integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqdus_(wkid, errind, i1, i2, i3, i4)
integer *wkid, *errind, *i1, *i2, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(38, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqepli_(integer *wkid, integer *i1, integer *errind, 
	integer *i2, integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqepli_(wkid, i1, errind, i2, i3)
integer *wkid, *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(39, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqplr_(integer *wkid, integer *i1, integer *i2, integer *
	errind, integer *i3, real *r1, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqplr_(wkid, i1, i2, errind, i3, r1, i4)
integer *wkid, *i1, *i2, *errind, *i3;
real *r1;
integer *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(40, r1, (real *)0, (real *)0, errind, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, wkid, (real *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqepmi_(integer *wkid, integer *i1, integer *errind, 
	integer *i2, integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqepmi_(wkid, i1, errind, i2, i3)
integer *wkid, *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(41, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpmr_(integer *wkid, integer *i1, integer *i2, integer *
	errind, integer *i3, real *r1, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqpmr_(wkid, i1, i2, errind, i3, r1, i4)
integer *wkid, *i1, *i2, *errind, *i3;
real *r1;
integer *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(42, r1, (real *)0, (real *)0, errind, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, wkid, (real *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqetxi_(integer *wkid, integer *i1, integer *errind, 
	integer *i2, integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqetxi_(wkid, i1, errind, i2, i3)
integer *wkid, *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(43, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqtxr_(integer *wkid, integer *i1, integer *i2, integer *
	errind, integer *i3, integer *i4, real *r1, real *r2, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqtxr_(wkid, i1, i2, errind, i3, i4, r1, r2, i5)
integer *wkid, *i1, *i2, *errind, *i3, *i4;
real *r1, *r2;
integer *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(44, r1, r2, (real *)0, errind, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, (integer *)0, 
	    (integer *)0, (integer *)0, wkid, (real *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqeii_(integer *wkid, integer *i1, integer *errind, 
	integer *i2, integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqeii_(wkid, i1, errind, i2, i3)
integer *wkid, *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(45, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqir_(integer *wkid, integer *i1, integer *i2, integer *
	errind, integer *i3, integer *i4, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqir_(wkid, i1, i2, errind, i3, i4, i5)
integer *wkid, *i1, *i2, *errind, *i3, *i4, *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(46, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, (
	    integer *)0, (integer *)0, (integer *)0, wkid, (real *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqeedi_(integer *wkid, integer *i1, integer *errind, 
	integer *i2, integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqeedi_(wkid, i1, errind, i2, i3)
integer *wkid, *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(47, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqedr_(integer *wkid, integer *i1, integer *i2, integer *
	errind, integer *i3, integer *i4, real *r1, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqedr_(wkid, i1, i2, errind, i3, i4, r1, i5)
integer *wkid, *i1, *i2, *errind, *i3, *i4;
real *r1;
integer *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(48, r1, (real *)0, (real *)0, errind, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, (integer *
	    )0, (integer *)0, (integer *)0, wkid, (real *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqepai_(integer *wkid, integer *i1, integer *errind, 
	integer *i2, integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqepai_(wkid, i1, errind, i2, i3)
integer *wkid, *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(49, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpar_(integer *wkid, integer *i1, integer *i2, integer *
	i3, integer *i4, integer *errind, integer *i5, integer *i6, integer *
	ia)
#else /* NO_PROTO */
/* Subroutine */ int rqpar_(wkid, i1, i2, i3, i4, errind, i5, i6, ia)
integer *wkid, *i1, *i2, *i3, *i4, *errind, *i5, *i6, *ia;
#endif /* NO_PROTO */
{
    return ifuncs_0_(50, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6,
	     (integer *)0, (integer *)0, wkid, (real *)0, ia, (integer *)0, (
	    real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqcmd_(integer *wkid, integer *errind, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rqcmd_(wkid, errind, i1)
integer *wkid, *errind, *i1;
#endif /* NO_PROTO */
{
    return ifuncs_0_(51, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, wkid, (real *)0, (integer *)0, (integer *)0, (
	    real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqeci_(integer *wkid, integer *i1, integer *errind, 
	integer *i2, integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqeci_(wkid, i1, errind, i2, i3)
integer *wkid, *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(52, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqcr_(integer *wkid, integer *i1, integer *i2, integer *
	i3, integer *errind, integer *i4, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rqcr_(wkid, i1, i2, i3, errind, i4, ra)
integer *wkid, *i1, *i2, *i3, *errind, *i4;
real *ra;
#endif /* NO_PROTO */
{
    return ifuncs_0_(53, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, ra, (real *)0, i1, i2, i3, i4, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, wkid, (real *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqhlft_(integer *wkid, integer *i1, integer *i2, integer 
	*errind, integer *i3, integer *ia, integer *i4, integer *ib)
#else /* NO_PROTO */
/* Subroutine */ int rqhlft_(wkid, i1, i2, errind, i3, ia, i4, ib)
integer *wkid, *i1, *i2, *errind, *i3, *ia, *i4, *ib;
#endif /* NO_PROTO */
{
    return ifuncs_0_(54, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, ia, ib, (real *)0, (real *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)
	    0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqivft_(integer *wkid, integer *i1, integer *i2, integer 
	*errind, integer *i3, integer *ia, integer *i4, integer *ib)
#else /* NO_PROTO */
/* Subroutine */ int rqivft_(wkid, i1, i2, errind, i3, ia, i4, ib)
integer *wkid, *i1, *i2, *errind, *i3, *ia, *i4, *ib;
#endif /* NO_PROTO */
{
    return ifuncs_0_(55, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, wkid, (
	    real *)0, ia, ib, (real *)0, (real *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)
	    0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqwkt3_(integer *wkid, integer *errind, integer *i1, 
	real *ra, real *rb, real *rc, real *rd)
#else /* NO_PROTO */
/* Subroutine */ int rqwkt3_(wkid, errind, i1, ra, rb, rc, rd)
integer *wkid, *errind, *i1;
real *ra, *rb, *rc, *rd;
#endif /* NO_PROTO */
{
    return ifuncs_0_(56, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, ra, rb, i1, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, wkid, (real *)0, (integer *)0, (integer *)0, rc, rd, (integer *
	    )0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char 
	    *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqwkt_(integer *wkid, integer *errind, integer *i1, real 
	*ra, real *rb, real *rc, real *rd)
#else /* NO_PROTO */
/* Subroutine */ int rqwkt_(wkid, errind, i1, ra, rb, rc, rd)
integer *wkid, *errind, *i1;
real *ra, *rb, *rc, *rd;
#endif /* NO_PROTO */
{
    return ifuncs_0_(57, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, ra, rb, i1, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, wkid, (real *)0, (integer *)0, (integer *)0, rc, rd, (integer *
	    )0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char 
	    *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqwkca_(integer *i1, integer *errind, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rqwkca_(i1, errind, i2)
integer *i1, *errind, *i2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(58, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqdsp3_(integer *i1, integer *errind, integer *i2, real *
	r1, real *r2, real *r3, integer *i3, integer *i4, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqdsp3_(i1, errind, i2, r1, r2, r3, i3, i4, i5)
integer *i1, *errind, *i2;
real *r1, *r2, *r3;
integer *i3, *i4, *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(59, r1, r2, r3, errind, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, i1, i2, i3, i4, i5, (integer *)0, (integer *
	    )0, (integer *)0, (integer *)0, (real *)0, (integer *)0, (integer 
	    *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, 
	    (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqdsp_(integer *i1, integer *errind, integer *i2, real *
	r1, real *r2, integer *i4, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqdsp_(i1, errind, i2, r1, r2, i4, i5)
integer *i1, *errind, *i2;
real *r1, *r2;
integer *i4, *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(60, r1, r2, (real *)0, errind, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, i4, i5, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqhrif_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqhrif_(i1, i2, errind, i3, i4)
integer *i1, *i2, *errind, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(61, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqhrmf_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqhrmf_(i1, i2, errind, i3, i4)
integer *i1, *i2, *errind, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(62, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqvwf_(integer *i1, integer *errind, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rqvwf_(i1, errind, i2)
integer *i1, *errind, *i2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(63, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpvwr_(integer *i1, integer *i2, integer *errind, real *
	xga, real *xgb, real *vclip, integer *i3, integer *i4, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqpvwr_(i1, i2, errind, xga, xgb, vclip, i3, i4, i5)
integer *i1, *i2, *errind;
real *xga, *xgb, *vclip;
integer *i3, *i4, *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(64, (real *)0, (real *)0, (real *)0, errind, xga, (real *
	    )0, xgb, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, vclip, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqwkcl_(integer *i1, integer *errind, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rqwkcl_(i1, errind, i2)
integer *i1, *errind, *i2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(65, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqdswa_(integer *i1, integer *errind, integer *i2, 
	integer *i3, integer *i4, integer *i5, integer *i6, integer *i7, 
	integer *i8, integer *i9, integer *i10, integer *i11, integer *i12, 
	integer *i13)
#else /* NO_PROTO */
/* Subroutine */ int rqdswa_(i1, errind, i2, i3, i4, i5, i6, i7, i8, i9, i10, 
	i11, i12, i13)
integer *i1, *errind, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9, *i10, *i11, *
	i12, *i13;
#endif /* NO_PROTO */
{
    return ifuncs_0_(66, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6,
	     i7, i8, (integer *)0, (real *)0, (integer *)0, (integer *)0, (
	    real *)0, (real *)0, i9, i10, i11, i12, i13, (char *)0, (char *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)
	    0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqddus_(integer *i1, integer *errind, integer *i2, 
	integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rqddus_(i1, errind, i2, i3)
integer *i1, *errind, *i2, *i3;
#endif /* NO_PROTO */
{
    return ifuncs_0_(67, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqplf_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, integer *i5, real *r1, real *r2, real *r3, 
	integer *i6)
#else /* NO_PROTO */
/* Subroutine */ int rqplf_(i1, i2, errind, i3, i4, i5, r1, r2, r3, i6)
integer *i1, *i2, *errind, *i3, *i4, *i5;
real *r1, *r2, *r3;
integer *i6;
#endif /* NO_PROTO */
{
    return ifuncs_0_(68, r1, r2, r3, errind, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, i1, i2, i3, i4, i5, i6, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *)0, 
	    (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpplr_(integer *i1, integer *i2, integer *errind, 
	integer *i3, real *r1, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqpplr_(i1, i2, errind, i3, r1, i4)
integer *i1, *i2, *errind, *i3;
real *r1;
integer *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(69, r1, (real *)0, (real *)0, errind, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0,
	     (integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpmf_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, integer *i5, real *r1, real *r2, real *r3, 
	integer *i6)
#else /* NO_PROTO */
/* Subroutine */ int rqpmf_(i1, i2, errind, i3, i4, i5, r1, r2, r3, i6)
integer *i1, *i2, *errind, *i3, *i4, *i5;
real *r1, *r2, *r3;
integer *i6;
#endif /* NO_PROTO */
{
    return ifuncs_0_(70, r1, r2, r3, errind, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, i1, i2, i3, i4, i5, i6, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *)0, 
	    (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqppmr_(integer *i1, integer *i2, integer *errind, 
	integer *i3, real *r1, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqppmr_(i1, i2, errind, i3, r1, i4)
integer *i1, *i2, *errind, *i3;
real *r1;
integer *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(71, r1, (real *)0, (real *)0, errind, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0,
	     (integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqtxf_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, integer *i5, integer *i6, real *r1, real *
	r2, integer *i7, real *r3, real *r4, integer *i8)
#else /* NO_PROTO */
/* Subroutine */ int rqtxf_(i1, i2, errind, i3, i4, i5, i6, r1, r2, i7, r3, 
	r4, i8)
integer *i1, *i2, *errind, *i3, *i4, *i5, *i6;
real *r1, *r2;
integer *i7;
real *r3, *r4;
integer *i8;
#endif /* NO_PROTO */
{
    return ifuncs_0_(72, r1, r2, r3, errind, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, r4, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, i1, i2, i3, i4, i5, i6, i7, i8, (integer *)0, (
	    real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqptxr_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, real *r1, real *r2, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqptxr_(i1, i2, errind, i3, i4, r1, r2, i5)
integer *i1, *i2, *errind, *i3, *i4;
real *r1, *r2;
integer *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(73, r1, r2, (real *)0, errind, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (real *)0, (integer *)0,
	     (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqanf_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, integer *i5, real *r1, real *r2)
#else /* NO_PROTO */
/* Subroutine */ int rqanf_(i1, i2, errind, i3, i4, i5, r1, r2)
integer *i1, *i2, *errind, *i3, *i4, *i5;
real *r1, *r2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(74, r1, r2, (real *)0, errind, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (real *)0, (integer *)0,
	     (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqtxx_(integer *i1, integer *i2, real *r1, real *r2, 
	real *r3, integer *i3, integer *i4, integer *i5, char *chars, integer 
	*errind, real *ra, real *rb, real *r4, real *r5, ftnlen chars_len)
#else /* NO_PROTO */
/* Subroutine */ int rqtxx_(i1, i2, r1, r2, r3, i3, i4, i5, chars, errind, ra,
	 rb, r4, r5, chars_len)
integer *i1, *i2;
real *r1, *r2, *r3;
integer *i3, *i4, *i5;
char *chars;
integer *errind;
real *ra, *rb, *r4, *r5;
ftnlen chars_len;
#endif /* NO_PROTO */
{
    return ifuncs_0_(75, r1, r2, r3, errind, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, r4, r5, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, ra, rb, i1, 
	    i2, i3, i4, i5, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, chars, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, chars_len, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqif_(integer *i1, integer *i2, integer *i3, integer *
	errind, integer *i4, integer *i5, integer *i6, integer *i7, integer *
	i8)
#else /* NO_PROTO */
/* Subroutine */ int rqif_(i1, i2, i3, errind, i4, i5, i6, i7, i8)
integer *i1, *i2, *i3, *errind, *i4, *i5, *i6, *i7, *i8;
#endif /* NO_PROTO */
{
    return ifuncs_0_(76, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6,
	     i7, i8, (integer *)0, (real *)0, (integer *)0, (integer *)0, (
	    real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpir_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqpir_(i1, i2, errind, i3, i4, i5)
integer *i1, *i2, *errind, *i3, *i4, *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(77, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqedf_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, integer *i5, real *r1, real *r2, real *r3, 
	integer *i6)
#else /* NO_PROTO */
/* Subroutine */ int rqedf_(i1, i2, errind, i3, i4, i5, r1, r2, r3, i6)
integer *i1, *i2, *errind, *i3, *i4, *i5;
real *r1, *r2, *r3;
integer *i6;
#endif /* NO_PROTO */
{
    return ifuncs_0_(78, r1, r2, r3, errind, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, i1, i2, i3, i4, i5, i6, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *)0, 
	    (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpedr_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, real *r1, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqpedr_(i1, i2, errind, i3, i4, r1, i5)
integer *i1, *i2, *errind, *i3, *i4;
real *r1;
integer *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(79, r1, (real *)0, (real *)0, errind, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, (integer *
	    )0, (integer *)0, (integer *)0, (integer *)0, (real *)0, (integer 
	    *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)
	    0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpaf_(integer *i1, integer *errind, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rqpaf_(i1, errind, i2)
integer *i1, *errind, *i2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(80, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqppar_(integer *i1, integer *i2, integer *i3, integer *
	i4, integer *errind, integer *i5, integer *i6, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rqppar_(i1, i2, i3, i4, errind, i5, i6, ia)
integer *i1, *i2, *i3, *i4, *errind, *i5, *i6, *ia;
#endif /* NO_PROTO */
{
    return ifuncs_0_(81, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6,
	     (integer *)0, (integer *)0, (integer *)0, (real *)0, ia, (
	    integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqcmdf_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, integer *i5)
#else /* NO_PROTO */
/* Subroutine */ int rqcmdf_(i1, i2, errind, i3, i4, i5)
integer *i1, *i2, *errind, *i3, *i4, *i5;
#endif /* NO_PROTO */
{
    return ifuncs_0_(82, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqcf_(integer *i1, integer *errind, integer *i2, integer 
	*i3, integer *i4, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rqcf_(i1, errind, i2, i3, i4, ra)
integer *i1, *errind, *i2, *i3, *i4;
real *ra;
#endif /* NO_PROTO */
{
    return ifuncs_0_(83, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, ra, (real *)0, i1, i2, i3, i4, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0,
	     (integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpcr_(integer *i1, integer *i2, integer *i3, integer *
	errind, integer *i4, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rqpcr_(i1, i2, i3, errind, i4, ra)
integer *i1, *i2, *i3, *errind, *i4;
real *ra;
#endif /* NO_PROTO */
{
    return ifuncs_0_(84, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, ra, (real *)0, i1, i2, i3, i4, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0,
	     (integer *)0, (integer *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)0, 
	    (char *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *)
	    0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqegd3_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqegd3_(i1, i2, errind, i3, i4)
integer *i1, *i2, *errind, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(85, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqegdp_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqegdp_(i1, i2, errind, i3, i4)
integer *i1, *i2, *errind, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(86, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqgdp3_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rqgdp3_(i1, i2, errind, i3, ia)
integer *i1, *i2, *errind, *i3, *ia;
#endif /* NO_PROTO */
{
    return ifuncs_0_(87, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, ia, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqgdp_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rqgdp_(i1, i2, errind, i3, ia)
integer *i1, *i2, *errind, *i3, *ia;
#endif /* NO_PROTO */
{
    return ifuncs_0_(88, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, ia, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqegse_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqegse_(i1, i2, errind, i3, i4)
integer *i1, *i2, *errind, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(89, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqdp_(integer *i1, integer *errind, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rqdp_(i1, errind, i2)
integer *i1, *errind, *i2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(90, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqwksl_(integer *i1, integer *errind, integer *i2, 
	integer *i3, integer *i4, integer *i5, integer *i6, integer *i7, 
	integer *i8, integer *i9)
#else /* NO_PROTO */
/* Subroutine */ int rqwksl_(i1, errind, i2, i3, i4, i5, i6, i7, i8, i9)
integer *i1, *errind, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *i9;
#endif /* NO_PROTO */
{
    return ifuncs_0_(91, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6,
	     i7, i8, (integer *)0, (real *)0, (integer *)0, (integer *)0, (
	    real *)0, (real *)0, i9, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqdstr_(integer *i1, integer *errind, integer *i2, 
	integer *i3, integer *i4, integer *i5, integer *i6)
#else /* NO_PROTO */
/* Subroutine */ int rqdstr_(i1, errind, i2, i3, i4, i5, i6)
integer *i1, *errind, *i2, *i3, *i4, *i5, *i6;
#endif /* NO_PROTO */
{
    return ifuncs_0_(92, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6,
	     (integer *)0, (integer *)0, (integer *)0, (real *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqwkpo_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqwkpo_(i1, i2, errind, i3, i4)
integer *i1, *i2, *errind, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(93, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqopst_(integer *errind, integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rqopst_(errind, i1, i2)
integer *errind, *i1, *i2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(94, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)0,
	     (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqep_(integer *errind, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rqep_(errind, i1)
integer *errind, *i1;
#endif /* NO_PROTO */
{
    return ifuncs_0_(95, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, 
	    (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqcets_(integer *errind, integer *i1, integer *i2, 
	integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rqcets_(errind, i1, i2, i3, i4)
integer *errind, *i1, *i2, *i3, *i4;
#endif /* NO_PROTO */
{
    return ifuncs_0_(96, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (char *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqceco_(integer *i1, integer *i2, integer *i3, integer *
	errind, integer *i4, integer *ia, integer *i5, real *ra, integer *i6, 
	integer *ib, char *charsa, ftnlen charsa_len)
#else /* NO_PROTO */
/* Subroutine */ int rqceco_(i1, i2, i3, errind, i4, ia, i5, ra, i6, ib, 
	charsa, charsa_len)
integer *i1, *i2, *i3, *errind, *i4, *ia, *i5;
real *ra;
integer *i6, *ib;
char *charsa;
ftnlen charsa_len;
#endif /* NO_PROTO */
{
    return ifuncs_0_(97, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, ra, (real *)0, i1, i2, i3, i4, i5, i6, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, ia, ib, (real 
	    *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, charsa, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, charsa_len, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqets_(integer *i1, integer *i2, integer *errind, 
	integer *i3, integer *i4, integer *i5, integer *i6)
#else /* NO_PROTO */
/* Subroutine */ int rqets_(i1, i2, errind, i3, i4, i5, i6)
integer *i1, *i2, *errind, *i3, *i4, *i5, *i6;
#endif /* NO_PROTO */
{
    return ifuncs_0_(98, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, i6,
	     (integer *)0, (integer *)0, (integer *)0, (real *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0,
	     (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqeco_(integer *i1, integer *i2, integer *i3, integer *
	i4, integer *i5, integer *errind, integer *i6, integer *ia, integer *
	i7, real *ra, integer *i8, integer *ib, char *charsa, ftnlen 
	charsa_len)
#else /* NO_PROTO */
/* Subroutine */ int rqeco_(i1, i2, i3, i4, i5, errind, i6, ia, i7, ra, i8, 
	ib, charsa, charsa_len)
integer *i1, *i2, *i3, *i4, *i5, *errind, *i6, *ia, *i7;
real *ra;
integer *i8, *ib;
char *charsa;
ftnlen charsa_len;
#endif /* NO_PROTO */
{
    return ifuncs_0_(99, (real *)0, (real *)0, (real *)0, errind, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, ra, (real *)0, i1, i2, i3, i4, i5, i6, i7, 
	    i8, (integer *)0, (real *)0, ia, ib, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, charsa, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (char *)0, (ftnint)0, charsa_len, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqstst_(integer *i1, integer *errind, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rqstst_(i1, errind, i2)
integer *i1, *errind, *i2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(100, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (integer *)0, (real *)0, (integer *)0, (integer *)0, (real *)
	    0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (
	    ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpan_(integer *i1, integer *i2, integer *i3, integer *
	i4, integer *i5, integer *errind, integer *i6, integer *i7, integer *
	ia2)
#else /* NO_PROTO */
/* Subroutine */ int rqpan_(i1, i2, i3, i4, i5, errind, i6, i7, ia2)
integer *i1, *i2, *i3, *i4, *i5, *errind, *i6, *i7, *ia2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(101, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, 
	    i6, i7, (integer *)0, (integer *)0, (real *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, 
	    ia2, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (
	    ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqpde_(integer *i1, integer *i2, integer *i3, integer *
	i4, integer *i5, integer *errind, integer *i6, integer *i7, integer *
	ia2)
#else /* NO_PROTO */
/* Subroutine */ int rqpde_(i1, i2, i3, i4, i5, errind, i6, i7, ia2)
integer *i1, *i2, *i3, *i4, *i5, *errind, *i6, *i7, *ia2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(102, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, 
	    i6, i7, (integer *)0, (integer *)0, (real *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (char *)0, 
	    ia2, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (
	    ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rels_(integer *i1, integer *i2, integer *i3, integer *i4,
	 integer *ia, integer *i5, integer *ib, integer *errind, integer *i6, 
	integer *i7)
#else /* NO_PROTO */
/* Subroutine */ int rels_(i1, i2, i3, i4, ia, i5, ib, errind, i6, i7)
integer *i1, *i2, *i3, *i4, *ia, *i5, *ib, *errind, *i6, *i7;
#endif /* NO_PROTO */
{
    return ifuncs_0_(103, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, i1, i2, i3, i4, i5, 
	    i6, i7, (integer *)0, (integer *)0, (real *)0, ia, ib, (real *)0, 
	    (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int riss3_(real *r1, real *r2, real *r3, real *r4, integer *
	i1, integer *ia2, integer *i2, integer *i3, integer *i4, integer *ia, 
	integer *ib, integer *ic, integer *id, integer *i5, integer *ie, 
	integer *if__, integer *ig, integer *ih, integer *i6, integer *errind,
	 integer *i7, integer *ib2)
#else /* NO_PROTO */
/* Subroutine */ int riss3_(r1, r2, r3, r4, i1, ia2, i2, i3, i4, ia, ib, ic, 
	id, i5, ie, if__, ig, ih, i6, errind, i7, ib2)
real *r1, *r2, *r3, *r4;
integer *i1, *ia2, *i2, *i3, *i4, *ia, *ib, *ic, *id, *i5, *ie, *if__, *ig, *
	ih, *i6, *errind, *i7, *ib2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(104, r1, r2, r3, errind, (real *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, r4, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, i1, i2, i3, i4, i5, i6, i7, (integer *)0, (
	    integer *)0, (real *)0, ia, ib, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *
	    )0, (char *)0, ia2, ic, id, ie, if__, ig, ih, ib2, (char *)0, (
	    ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int riss_(real *r1, real *r2, real *r3, integer *i1, integer 
	*ia2, integer *i2, integer *i3, integer *i4, integer *ia, integer *ib,
	 integer *ic, integer *id, integer *i5, integer *ie, integer *if__, 
	integer *ig, integer *ih, integer *i6, integer *errind, integer *i7, 
	integer *ib2)
#else /* NO_PROTO */
/* Subroutine */ int riss_(r1, r2, r3, i1, ia2, i2, i3, i4, ia, ib, ic, id, 
	i5, ie, if__, ig, ih, i6, errind, i7, ib2)
real *r1, *r2, *r3;
integer *i1, *ia2, *i2, *i3, *i4, *ia, *ib, *ic, *id, *i5, *ie, *if__, *ig, *
	ih, *i6, *errind, *i7, *ib2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(105, r1, r2, r3, errind, (real *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, i1, i2, i3, i4, i5, i6, i7, (integer *)0, (
	    integer *)0, (real *)0, ia, ib, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (char *
	    )0, (char *)0, ia2, ic, id, ie, if__, ig, ih, ib2, (char *)0, (
	    ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqiqov_(integer *errind, integer *wkid, integer *i1, 
	integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rqiqov_(errind, wkid, i1, i2)
integer *errind, *wkid, *i1, *i2;
#endif /* NO_PROTO */
{
    return ifuncs_0_(106, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, i1, i2, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, wkid, (real *)0, (integer *)0, (integer *)0, (real *)0, (real 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (char *)0, (char *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rqerhm_(integer *errind, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rqerhm_(errind, i1)
integer *errind, *i1;
#endif /* NO_PROTO */
{
    return ifuncs_0_(107, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, i1, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (char *)0, (char *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (char *)0, (ftnint)0, (ftnint)0, 
	    (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rprec_(integer *i1, integer *ia, integer *i2, real *ra, 
	integer *i3, integer *ib, char *charsa, integer *i4, integer *errind, 
	integer *i5, char *charsb, ftnlen charsa_len, ftnlen charsb_len)
#else /* NO_PROTO */
/* Subroutine */ int rprec_(i1, ia, i2, ra, i3, ib, charsa, i4, errind, i5, 
	charsb, charsa_len, charsb_len)
integer *i1, *ia, *i2;
real *ra;
integer *i3, *ib;
char *charsa;
integer *i4, *errind, *i5;
char *charsb;
ftnlen charsa_len;
ftnlen charsb_len;
#endif /* NO_PROTO */
{
    return ifuncs_0_(108, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, ra, (real *)0, i1, i2, i3, i4, i5, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0, ia, ib, 
	    (real *)0, (real *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (char *)0, charsa, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, charsb, (ftnint)0, charsa_len, 
	    charsb_len);
    }

#ifndef NO_PROTO
/* Subroutine */ int rurec_(integer *i1, char *charsa, integer *i2, integer *
	i3, integer *i4, integer *errind, integer *i5, integer *ia, integer *
	i6, real *ra, integer *i7, integer *ib, char *charsb, ftnlen 
	charsa_len, ftnlen charsb_len)
#else /* NO_PROTO */
/* Subroutine */ int rurec_(i1, charsa, i2, i3, i4, errind, i5, ia, i6, ra, 
	i7, ib, charsb, charsa_len, charsb_len)
integer *i1;
char *charsa;
integer *i2, *i3, *i4, *errind, *i5, *ia, *i6;
real *ra;
integer *i7, *ib;
char *charsb;
ftnlen charsa_len;
ftnlen charsb_len;
#endif /* NO_PROTO */
{
    return ifuncs_0_(109, (real *)0, (real *)0, (real *)0, errind, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, ra, (real *)0, i1, i2, i3, i4, i5, i6, i7, (
	    integer *)0, (integer *)0, (real *)0, ia, ib, (real *)0, (real *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (char *)0, charsa, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, charsb, (ftnint)0, charsa_len, charsb_len);
    }

/*  ********************************************************* */
/*  *                                                       * */
/*  *    SUBROUTINE 09.02/ichkz                             * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
#ifndef NO_PROTO
/* Subroutine */ int ichkz_(integer *cerind, integer *funcid)
#else /* NO_PROTO */
/* Subroutine */ int ichkz_(cerind, funcid)
integer *cerind, *funcid;
#endif /* NO_PROTO */
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2], i__2, i__3;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    /* Subroutine */ int s_cat(), s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer ix;
    static char msg[160];
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), pass_(void);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), pass_();
#endif /* NO_PROTO */
    static char tmsg[500], acode[4];
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nfunm_(integer *, 
	    char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int unmsg_(char *, ftnlen);
    extern integer iarfnd_(integer *, integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nfunm_();
    extern integer itrim_();
    extern /* Subroutine */ int unmsg_();
    extern integer iarfnd_();
#endif /* NO_PROTO */
    static char funnam[80];
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___5 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___6 = { 0, acode, 0, "(I4.3)", 4, 1 };
    static icilist io___8 = { 0, msg, 0, "(A,I6.3,A)", 160, 1 };


/*  ICHKZ does post-processing after an error-indicator function has */
/*  been called. */
/*  Input parameters: */
/*    CERIND: actual error indicator returned by function */
/*    FUNCID: numeric identifier of function that returned error indicator
 */
    if (errinf_1.expsiz < 1) {
	unmsg_("ICHKZ is called with invalid EXPSIZ.", 36L);
    }
/*  set up test message */
    nfunm_(funcid, funnam, 80L);
/* Writing concatenation */
    i__1[0] = 3, a__1[0] = "If ";
    i__1[1] = 80, a__1[1] = funnam;
    s_cat(tmsg, a__1, i__1, &c__2, 500L);
    i__2 = itrim_(tmsg, 500L) + 1;
/* Writing concatenation */
    i__1[0] = 14, a__1[0] = "is called and ";
    i__1[1] = 200, a__1[1] = errchr_1.curcon;
    s_cat(tmsg + i__2, a__1, i__1, &c__2, 500 - i__2);
    i__2 = itrim_(tmsg, 500L);
    s_copy(tmsg + i__2, ", it should return error indicator = ", 500 - i__2, 
	    37L);
/*  may be several valid error code possibilities */
    i__2 = errinf_1.expsiz - 1;
    for (ix = 1; ix <= i__2; ++ix) {
	s_wsfi(&io___5);
	do_fio(&c__1, (char *)&errinf_1.experr[ix - 1], (ftnlen)sizeof(
		integer));
	e_wsfi();
	i__3 = itrim_(tmsg, 500L) + 1;
/* Writing concatenation */
	i__1[0] = 4, a__1[0] = acode;
	i__1[1] = 1, a__1[1] = ",";
	s_cat(tmsg + i__3, a__1, i__1, &c__2, 500 - i__3);
/* L50: */
    }
    if (errinf_1.expsiz >= 2) {
	i__2 = itrim_(tmsg, 500L) - 1;
	s_copy(tmsg + i__2, " or ", 500 - i__2, 4L);
    }
    s_wsfi(&io___6);
    do_fio(&c__1, (char *)&errinf_1.experr[errinf_1.expsiz - 1], (ftnlen)
	    sizeof(integer));
    e_wsfi();
    i__2 = itrim_(tmsg, 500L) + 1;
/* Writing concatenation */
    i__1[0] = 4, a__1[0] = acode;
    i__1[1] = 1, a__1[1] = ".";
    s_cat(tmsg + i__2, a__1, i__1, &c__2, 500 - i__2);
    setmsg_(errchr_1.errsrs, tmsg, 40L, 500L);
    if (iarfnd_(cerind, &errinf_1.expsiz, errinf_1.experr) > 0) {
	pass_();
    } else {
	fail_();
	s_wsfi(&io___8);
	do_fio(&c__1, "Reported error indicator ", 25L);
	do_fio(&c__1, (char *)&(*cerind), (ftnlen)sizeof(integer));
	do_fio(&c__1, " is not one of the expected values.", 35L);
	e_wsfi();
	inmsg_(msg, 160L);
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* ichkz_ */

