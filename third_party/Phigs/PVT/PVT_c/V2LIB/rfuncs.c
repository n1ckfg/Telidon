/* rfuncs.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__90 = 90;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__8 = 8;
static integer c__9 = 9;
static integer c__13 = 13;
static integer c__17 = 17;
static integer c__16 = 16;
static integer c__11 = 11;
static integer c__15 = 15;
static integer c__19 = 19;
static integer c__18 = 18;
static integer c__20 = 20;
static integer c__21 = 21;
static integer c__62 = 62;
static integer c__63 = 63;
static integer c__42 = 42;
static integer c__43 = 43;
static integer c__47 = 47;
static integer c__49 = 49;
static integer c__27 = 27;
static integer c__33 = 33;
static integer c__35 = 35;
static integer c__48 = 48;
static integer c__58 = 58;
static integer c__65 = 65;
static integer c__67 = 67;
static integer c__64 = 64;
static integer c__28 = 28;
static integer c__55 = 55;
static integer c__31 = 31;
static integer c__39 = 39;
static integer c__26 = 26;
static integer c__66 = 66;
static integer c__24 = 24;
static integer c__29 = 29;
static integer c__34 = 34;
static integer c__37 = 37;
static integer c__52 = 52;
static integer c__59 = 59;
static integer c__60 = 60;
static integer c__61 = 61;
static integer c__69 = 69;
static integer c__72 = 72;
static integer c__70 = 70;
static integer c__71 = 71;
static integer c__68 = 68;
static integer c__73 = 73;
static integer c__84 = 84;
static integer c__87 = 87;
static integer c__86 = 86;
static integer c__88 = 88;
static integer c__89 = 89;
static integer c__77 = 77;
static integer c__83 = 83;
static integer c__75 = 75;
static integer c__79 = 79;
static integer c__82 = 82;
static integer c__85 = 85;
static integer c__91 = 91;
static integer c__93 = 93;
static integer c__98 = 98;
static integer c__92 = 92;
static integer c__97 = 97;
static integer c__101 = 101;
static integer c__96 = 96;
static integer c__104 = 104;
static integer c__106 = 106;
static integer c__110 = 110;
static integer c__119 = 119;
static integer c__111 = 111;
static integer c__100 = 100;
static integer c__103 = 103;
static integer c__112 = 112;
static integer c__113 = 113;
static integer c__114 = 114;
static integer c__115 = 115;
static integer c__116 = 116;
static integer c__117 = 117;
static integer c__118 = 118;
static integer c__120 = 120;
static integer c__123 = 123;
static integer c__121 = 121;
static integer c__122 = 122;
static integer c__124 = 124;
static integer c__125 = 125;
static integer c__126 = 126;
static integer c__128 = 128;
static integer c__127 = 127;
static integer c__179 = 179;

#ifndef NO_PROTO
/* Subroutine */ int rfuncs_0_(int n__, integer *i1, integer *i2, integer *
	wkid, real *ra, real *rb, real *rc, real *r1, real *r2, char *chars, 
	real *r3, real *r4, integer *ia, integer *i3, integer *i4, integer *
	i5, integer *i6, integer *i7, integer *ib, real *xfa, real *xfb, real 
	*vclip, real *xga, real *xgb, integer *i8, ftnlen chars_len)
{
    extern /* Subroutine */ int nca (real *, real *, real *, real *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    ), nfa (integer *, real *, real *), nlb (integer *), npl (integer 
	    *, real *, real *), npm (integer *, real *, real *), ntx (real *, 
	    real *, char *, ftnlen), nca3 (real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     nfa3 (integer *, real *, real *, real *), npl3 (integer *, real *
	    , real *, real *), ndel (void), nads (integer *, integer *), 
	    natr (real *, real *, real *, real *, char *, ftnlen), nfas (
	    integer *, integer *, real *, real *), nsii (integer *), nsis (
	    integer *), nsir (integer *, integer *, integer *, integer *, 
	    integer *), nsln (integer *), nuwk (integer *, integer *), nres (
	    integer *, integer *), nrst (integer *, integer *), nscr (integer 
	    *, integer *, integer *, real *), nsep (integer *), ndsn (integer 
	    *, integer *), nfas3 (integer *, integer *, real *, real *, real *
	    ), nopph (integer *, integer *), echkz_(integer *), nclph (void), 
	    nopwk (integer *, integer *, integer *), nopst (integer *), 
	    nclwk (integer *), nsdus (integer *, integer *, integer *), 
	    nsplr (integer *, integer *, integer *, real *, integer *), 
	    nspmr (integer *, integer *, integer *, real *, integer *), 
	    nstxp (integer *), nstxal (integer *, integer *), nsatal (integer 
	    *, integer *), nsmksc (real *), nstxfn (integer *), nsans (
	    integer *), nsparf (real *, real *), nspar (integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), nstxr (integer *, integer *, integer *, integer *, 
	    real *, real *, integer *), nsedi (integer *), nsedci (integer *),
	     nsplci (integer *), nstxci (integer *), nstxi (integer *), 
	    nsedr (integer *, integer *, integer *, integer *, real *, 
	    integer *), nspli (integer *), nspmci (integer *), nschxp (real *)
	    , nsedfg (integer *), nsiasf (integer *, integer *), nshlft (
	    integer *, integer *, integer *, integer *, integer *), nshrid (
	    integer *), nsivft (integer *, integer *, integer *, integer *, 
	    integer *), nscmd (integer *, integer *), nshrm (integer *, 
	    integer *), nsvwr (integer *, integer *, real *, real *, real *, 
	    integer *), nswkw (integer *, real *, real *, real *, real *), 
	    nswkw3 (integer *, real *), nswkv3 (integer *, real *), nswkv (
	    integer *, real *, real *, real *, real *), nsgmt (real *), 
	    nsvwr3 (integer *, integer *, real *, real *, real *, integer *, 
	    integer *, integer *), nslmt (real *, integer *), nsmcv (integer *
	    , integer *, real *), nsvwi (integer *), nsvtip (integer *, 
	    integer *, integer *, integer *), nclst (void), nexst (integer *),
	     ncelst (integer *), nsedm (integer *), nemst (integer *), 
	    ncstir (integer *, integer *), nscnrs (integer *, integer *), 
	    npost (integer *, integer *, real *), nseplb (integer *), ndellb (
	    integer *, integer *), nupost (integer *, integer *), nupast (
	    integer *), noparf (integer *, integer *), nclarf (integer *), 
	    narst (integer *, integer *, integer *), narsn (integer *, 
	    integer *, integer *), narast (integer *), nrsid (integer *, 
	    integer *, integer *, integer *), nrast (integer *), nrest (
	    integer *, integer *, integer *), nresn (integer *, integer *, 
	    integer *), nrepan (integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), nrepde (
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), ndstar (integer *, integer *, 
	    integer *), ndasar (integer *), ndsnar (integer *, integer *, 
	    integer *), nserhm (integer *);
#else /* NO_PROTO */
/* Subroutine */ int rfuncs_0_(n__, i1, i2, wkid, ra, rb, rc, r1, r2, chars, 
	r3, r4, ia, i3, i4, i5, i6, i7, ib, xfa, xfb, vclip, xga, xgb, i8, 
	chars_len)
int n__;
integer *i1, *i2, *wkid;
real *ra, *rb, *rc, *r1, *r2;
char *chars;
real *r3, *r4;
integer *ia, *i3, *i4, *i5, *i6, *i7, *ib;
real *xfa, *xfb, *vclip, *xga, *xgb;
integer *i8;
ftnlen chars_len;
{
    extern /* Subroutine */ int nca (), nfa (), nlb (), npl (), npm (), ntx ()
	    , nca3 (), nfa3 (), npl3 (), ndel (), nads (), natr (), nfas (), 
	    nsii (), nsis (), nsir (), nsln (), nuwk (), nres (), nrst (), 
	    nscr (), nsep (), ndsn (), nfas3 (), nopph (), echkz_(), nclph (),
	     nopwk (), nopst (), nclwk (), nsdus (), nsplr (), nspmr (), 
	    nstxp (), nstxal (), nsatal (), nsmksc (), nstxfn (), nsans (), 
	    nsparf (), nspar (), nstxr (), nsedi (), nsedci (), nsplci (), 
	    nstxci (), nstxi (), nsedr (), nspli (), nspmci (), nschxp (), 
	    nsedfg (), nsiasf (), nshlft (), nshrid (), nsivft (), nscmd (), 
	    nshrm (), nsvwr (), nswkw (), nswkw3 (), nswkv3 (), nswkv (), 
	    nsgmt (), nsvwr3 (), nslmt (), nsmcv (), nsvwi (), nsvtip (), 
	    nclst (), nexst (), ncelst (), nsedm (), nemst (), ncstir (), 
	    nscnrs (), npost (), nseplb (), ndellb (), nupost (), nupast (), 
	    noparf (), nclarf (), narst (), narsn (), narast (), nrsid (), 
	    nrast (), nrest (), nresn (), nrepan (), nrepde (), ndstar (), 
	    ndasar (), ndsnar (), nserhm ();
#endif /* NO_PROTO */

/*  RFUNCS is the home of the entry points for PHIGS functions which */
/*  are called in order to generate an error.  The functions are */
/*  followed a wrapper routine which records what should have */
/*  happened. */
/* PHIGS function names (for those functions which signal error) */
/* *** *** *** control *** *** *** */
    /* Parameter adjustments */
    if (ra) {
	--ra;
	}
    if (rb) {
	--rb;
	}
    if (rc) {
	--rc;
	}
    if (ia) {
	--ia;
	}
    if (ib) {
	--ib;
	}
    if (xfa) {
	xfa -= 4;
	}
    if (xfb) {
	xfb -= 4;
	}
    if (vclip) {
	--vclip;
	}
    if (xga) {
	xga -= 5;
	}
    if (xgb) {
	xgb -= 5;
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_ropph;
	case 2: goto L_rclph;
	case 3: goto L_ropwk;
	case 4: goto L_ropst;
	case 5: goto L_rclwk;
	case 6: goto L_rrst;
	case 7: goto L_ruwk;
	case 8: goto L_rsdus;
	case 9: goto L_rpl3;
	case 10: goto L_rpl;
	case 11: goto L_rtx;
	case 12: goto L_rfa;
	case 13: goto L_rfa3;
	case 14: goto L_rpm;
	case 15: goto L_ratr;
	case 16: goto L_rfas;
	case 17: goto L_rfas3;
	case 18: goto L_rca3;
	case 19: goto L_rca;
	case 20: goto L_rsplr;
	case 21: goto L_rspmr;
	case 22: goto L_rstxp;
	case 23: goto L_rstxal;
	case 24: goto L_rsatal;
	case 25: goto L_rsis;
	case 26: goto L_rsii;
	case 27: goto L_rsmksc;
	case 28: goto L_rstxfn;
	case 29: goto L_rsans;
	case 30: goto L_rsparf;
	case 31: goto L_rsir;
	case 32: goto L_rspar;
	case 33: goto L_rstxr;
	case 34: goto L_rsedi;
	case 35: goto L_rsedci;
	case 36: goto L_rsplci;
	case 37: goto L_rstxci;
	case 38: goto L_rstxi;
	case 39: goto L_rsedr;
	case 40: goto L_rspli;
	case 41: goto L_rsln;
	case 42: goto L_rspmci;
	case 43: goto L_rschxp;
	case 44: goto L_rsedfg;
	case 45: goto L_rads;
	case 46: goto L_rres;
	case 47: goto L_rsiasf;
	case 48: goto L_rshlft;
	case 49: goto L_rshrid;
	case 50: goto L_rsivft;
	case 51: goto L_rscmd;
	case 52: goto L_rscr;
	case 53: goto L_rshrm;
	case 54: goto L_rsvwr;
	case 55: goto L_rswkw;
	case 56: goto L_rswkw3;
	case 57: goto L_rswkv3;
	case 58: goto L_rswkv;
	case 59: goto L_rsgmt;
	case 60: goto L_rsvwr3;
	case 61: goto L_rslmt;
	case 62: goto L_rsmcv;
	case 63: goto L_rsvwi;
	case 64: goto L_rsvtip;
	case 65: goto L_rclst;
	case 66: goto L_rlb;
	case 67: goto L_rsep;
	case 68: goto L_rexst;
	case 69: goto L_rcelst;
	case 70: goto L_rdel;
	case 71: goto L_rsedm;
	case 72: goto L_remst;
	case 73: goto L_rdsn;
	case 74: goto L_rcstir;
	case 75: goto L_rscnrs;
	case 76: goto L_rpost;
	case 77: goto L_rseplb;
	case 78: goto L_rdellb;
	case 79: goto L_rupost;
	case 80: goto L_rupast;
	case 81: goto L_roparf;
	case 82: goto L_rclarf;
	case 83: goto L_rarst;
	case 84: goto L_rarsn;
	case 85: goto L_rarast;
	case 86: goto L_rrsid;
	case 87: goto L_rrast;
	case 88: goto L_rrest;
	case 89: goto L_rresn;
	case 90: goto L_rrepan;
	case 91: goto L_rrepde;
	case 92: goto L_rdstar;
	case 93: goto L_rdasar;
	case 94: goto L_rdsnar;
	case 95: goto L_rserhm;
	}


L_ropph:
    nopph (i1, i2);
    echkz_(&c__0);
    return 0;

L_rclph:
    nclph ();
    echkz_(&c__1);
    return 0;

L_ropwk:
    nopwk (wkid, i1, i2);
    echkz_(&c__2);
    return 0;

L_ropst:
    nopst (i1);
    echkz_(&c__90);
    return 0;

L_rclwk:
    nclwk (wkid);
    echkz_(&c__3);
    return 0;

L_rrst:
    nrst (wkid, i1);
    echkz_(&c__4);
    return 0;

L_ruwk:
    nuwk (wkid, i1);
    echkz_(&c__5);
    return 0;

L_rsdus:
    nsdus (wkid, i1, i2);
    echkz_(&c__6);
    return 0;
/* *** *** *** output primitives *** *** *** */

L_rpl3:
    npl3 (i1, &ra[1], &rb[1], &rc[1]);
    echkz_(&c__8);
    return 0;

L_rpl:
    npl (i1, &ra[1], &rb[1]);
    echkz_(&c__9);
    return 0;

L_rtx:
    ntx (r1, r2, chars, chars_len);
    echkz_(&c__13);
    return 0;

L_rfa:
    nfa (i1, &ra[1], &rb[1]);
    echkz_(&c__17);
    return 0;

L_rfa3:
    nfa3 (i1, &ra[1], &rb[1], &rc[1]);
    echkz_(&c__16);
    return 0;

L_rpm:
    npm (i1, &ra[1], &rb[1]);
    echkz_(&c__11);
    return 0;

L_ratr:
    natr (r1, r2, r3, r4, chars, chars_len);
    echkz_(&c__15);
    return 0;

L_rfas:
    nfas (i1, &ia[1], &ra[1], &rb[1]);
    echkz_(&c__19);
    return 0;

L_rfas3:
    nfas3 (i1, &ia[1], &ra[1], &rb[1], &rc[1]);
    echkz_(&c__18);
    return 0;

L_rca3:
    nca3 (&ra[1], &rb[1], &rc[1], i1, i2, i3, i4, i5, i6, &ia[1]);
    echkz_(&c__20);
    return 0;

L_rca:
    nca (r1, r2, r3, r4, i1, i2, i3, i4, i5, i6, &ia[1]);
    echkz_(&c__21);
    return 0;
/* *** *** *** attributes *** *** *** */

L_rsplr:
    nsplr (wkid, i1, i2, r1, i3);
    echkz_(&c__62);
    return 0;

L_rspmr:
    nspmr (wkid, i1, i2, r1, i3);
    echkz_(&c__63);
    return 0;

L_rstxp:
    nstxp (i1);
    echkz_(&c__42);
    return 0;

L_rstxal:
    nstxal (i1, i2);
    echkz_(&c__43);
    return 0;

L_rsatal:
    nsatal (i1, i2);
    echkz_(&c__47);
    return 0;

L_rsis:
    nsis (i1);
    echkz_(&c__49);
    return 0;

L_rsii:
    nsii (i1);
    echkz_(&c__27);
    return 0;

L_rsmksc:
    nsmksc (r1);
    echkz_(&c__33);
    return 0;

L_rstxfn:
    nstxfn (i1);
    echkz_(&c__35);
    return 0;

L_rsans:
    nsans (i1);
    echkz_(&c__48);
    return 0;

L_rsparf:
    nsparf (r1, r2);
    echkz_(&c__58);
    return 0;

L_rsir:
    nsir (wkid, i1, i2, i3, i4);
    echkz_(&c__65);
    return 0;

L_rspar:
    nspar (wkid, i1, i2, i3, i4, i5, i6, i7, &ia[1]);
    echkz_(&c__67);
    return 0;

L_rstxr:
    nstxr (wkid, i1, i2, i3, r1, r2, i4);
    echkz_(&c__64);
    return 0;

L_rsedi:
    nsedi (i1);
    echkz_(&c__28);
    return 0;

L_rsedci:
    nsedci (i1);
    echkz_(&c__55);
    return 0;

L_rsplci:
    nsplci (i1);
    echkz_(&c__31);
    return 0;

L_rstxci:
    nstxci (i1);
    echkz_(&c__39);
    return 0;

L_rstxi:
    nstxi (i1);
    echkz_(&c__26);
    return 0;

L_rsedr:
    nsedr (wkid, i1, i2, i3, r1, i4);
    echkz_(&c__66);
    return 0;

L_rspli:
    nspli (i1);
    echkz_(&c__24);
    return 0;

L_rsln:
    nsln (i1);
    echkz_(&c__29);
    return 0;

L_rspmci:
    nspmci (i1);
    echkz_(&c__34);
    return 0;

L_rschxp:
    nschxp (r1);
    echkz_(&c__37);
    return 0;

L_rsedfg:
    nsedfg (i1);
    echkz_(&c__52);
    return 0;
/* *** *** *** generic attributes *** *** *** */

L_rads:
    nads (i1, &ia[1]);
    echkz_(&c__59);
    return 0;

L_rres:
    nres (i1, &ia[1]);
    echkz_(&c__60);
    return 0;

L_rsiasf:
    nsiasf (i1, i2);
    echkz_(&c__61);
    return 0;

L_rshlft:
    nshlft (wkid, i1, &ia[1], i2, &ib[1]);
    echkz_(&c__69);
    return 0;

L_rshrid:
    nshrid (i1);
    echkz_(&c__72);
    return 0;

L_rsivft:
    nsivft (wkid, i1, &ia[1], i2, &ib[1]);
    echkz_(&c__70);
    return 0;

L_rscmd:
    nscmd (wkid, i1);
    echkz_(&c__71);
    return 0;

L_rscr:
    nscr (wkid, i1, i2, &ra[1]);
    echkz_(&c__68);
    return 0;

L_rshrm:
    nshrm (wkid, i1);
    echkz_(&c__73);
    return 0;
/* *** *** *** geometry *** *** *** */

L_rsvwr:
    nsvwr (wkid, i1, &xfa[4], &xfb[4], &vclip[1], i2);
    echkz_(&c__84);
    return 0;

L_rswkw:
    nswkw (wkid, r1, r2, r3, r4);
    echkz_(&c__87);
    return 0;

L_rswkw3:
    nswkw3 (wkid, &ra[1]);
    echkz_(&c__86);
    return 0;

L_rswkv3:
    nswkv3 (wkid, &ra[1]);
    echkz_(&c__88);
    return 0;

L_rswkv:
    nswkv (wkid, r1, r2, r3, r4);
    echkz_(&c__89);
    return 0;

L_rsgmt:
    nsgmt (&xfa[4]);
    echkz_(&c__77);
    return 0;

L_rsvwr3:
    nsvwr3 (wkid, i1, &xga[5], &xgb[5], &vclip[1], i2, i3, i4);
    echkz_(&c__83);
    return 0;

L_rslmt:
    nslmt (&xfa[4], i1);
    echkz_(&c__75);
    return 0;

L_rsmcv:
    nsmcv (i1, i2, &ra[1]);
    echkz_(&c__79);
    return 0;

L_rsvwi:
    nsvwi (i1);
    echkz_(&c__82);
    return 0;

L_rsvtip:
    nsvtip (wkid, i1, i2, i3);
    echkz_(&c__85);
    return 0;
/* *** *** *** structures *** *** *** */

L_rclst:
    nclst ();
    echkz_(&c__91);
    return 0;

L_rlb:
    nlb (i1);
    echkz_(&c__93);
    return 0;

L_rsep:
    nsep (i1);
    echkz_(&c__98);
    return 0;

L_rexst:
    nexst (i1);
    echkz_(&c__92);
    return 0;

L_rcelst:
    ncelst (i1);
    echkz_(&c__97);
    return 0;

L_rdel:
    ndel ();
    echkz_(&c__101);
    return 0;

L_rsedm:
    nsedm (i1);
    echkz_(&c__96);
    return 0;

L_remst:
    nemst (i1);
    echkz_(&c__104);
    return 0;

L_rdsn:
    ndsn (i1, i2);
    echkz_(&c__106);
    return 0;

L_rcstir:
    ncstir (i1, i2);
    echkz_(&c__110);
    return 0;

L_rscnrs:
    nscnrs (i1, i2);
    echkz_(&c__119);
    return 0;

L_rpost:
    npost (wkid, i1, r1);
    echkz_(&c__111);
    return 0;

L_rseplb:
    nseplb (i1);
    echkz_(&c__100);
    return 0;

L_rdellb:
    ndellb (i1, i2);
    echkz_(&c__103);
    return 0;

L_rupost:
    nupost (wkid, i1);
    echkz_(&c__112);
    return 0;

L_rupast:
    nupast (wkid);
    echkz_(&c__113);
    return 0;
/* *** *** *** archives *** *** *** */

L_roparf:
    noparf (i1, i2);
    echkz_(&c__114);
    return 0;

L_rclarf:
    nclarf (i1);
    echkz_(&c__115);
    return 0;

L_rarst:
    narst (i1, i2, &ia[1]);
    echkz_(&c__116);
    return 0;

L_rarsn:
    narsn (i1, i2, &ia[1]);
    echkz_(&c__117);
    return 0;

L_rarast:
    narast (i1);
    echkz_(&c__118);
    return 0;

L_rrsid:
    nrsid (i1, i2, i3, &ia[1]);
    echkz_(&c__120);
    return 0;

L_rrast:
    nrast (i1);
    echkz_(&c__123);
    return 0;

L_rrest:
    nrest (i1, i2, &ia[1]);
    echkz_(&c__121);
    return 0;

L_rresn:
    nresn (i1, i2, &ia[1]);
    echkz_(&c__122);
    return 0;

L_rrepan:
    nrepan (i1, i2, i3, i4, i5, i6, i7, i8, &ia[1]);
    echkz_(&c__124);
    return 0;

L_rrepde:
    nrepde (i1, i2, i3, i4, i5, i6, i7, i8, &ia[1]);
    echkz_(&c__125);
    return 0;

L_rdstar:
    ndstar (i1, i2, &ia[1]);
    echkz_(&c__126);
    return 0;

L_rdasar:
    ndasar (i1);
    echkz_(&c__128);
    return 0;

L_rdsnar:
    ndsnar (i1, i2, &ia[1]);
    echkz_(&c__127);
    return 0;

L_rserhm:
    nserhm (i1);
    echkz_(&c__179);
    return 0;
} /* rfuncs_ */

#ifndef NO_PROTO
/* Subroutine */ int rfuncs_(void)
#else /* NO_PROTO */
/* Subroutine */ int rfuncs_()
#endif /* NO_PROTO */
{
    return rfuncs_0_(0, (integer *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ropph_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int ropph_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(1, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *
	    )0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rclph_(void)
#else /* NO_PROTO */
/* Subroutine */ int rclph_()
#endif /* NO_PROTO */
{
    return rfuncs_0_(2, (integer *)0, (integer *)0, (integer *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (
	    real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ropwk_(integer *wkid, integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int ropwk_(wkid, i1, i2)
integer *wkid, *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(3, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ropst_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int ropst_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(4, i1, (integer *)0, (integer *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rclwk_(integer *wkid)
#else /* NO_PROTO */
/* Subroutine */ int rclwk_(wkid)
integer *wkid;
#endif /* NO_PROTO */
{
    return rfuncs_0_(5, (integer *)0, (integer *)0, wkid, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrst_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rrst_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(6, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ruwk_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int ruwk_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(7, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsdus_(integer *wkid, integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rsdus_(wkid, i1, i2)
integer *wkid, *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(8, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real *
	    )0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rpl3_(integer *i1, real *ra, real *rb, real *rc)
#else /* NO_PROTO */
/* Subroutine */ int rpl3_(i1, ra, rb, rc)
integer *i1;
real *ra, *rb, *rc;
#endif /* NO_PROTO */
{
    return rfuncs_0_(9, i1, (integer *)0, (integer *)0, ra, rb, rc, (real *)0,
	     (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rpl_(integer *i1, real *ra, real *rb)
#else /* NO_PROTO */
/* Subroutine */ int rpl_(i1, ra, rb)
integer *i1;
real *ra, *rb;
#endif /* NO_PROTO */
{
    return rfuncs_0_(10, i1, (integer *)0, (integer *)0, ra, rb, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rtx_(real *r1, real *r2, char *chars, ftnlen chars_len)
#else /* NO_PROTO */
/* Subroutine */ int rtx_(r1, r2, chars, chars_len)
real *r1, *r2;
char *chars;
ftnlen chars_len;
#endif /* NO_PROTO */
{
    return rfuncs_0_(11, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, r2, chars, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, chars_len);
    }

#ifndef NO_PROTO
/* Subroutine */ int rfa_(integer *i1, real *ra, real *rb)
#else /* NO_PROTO */
/* Subroutine */ int rfa_(i1, ra, rb)
integer *i1;
real *ra, *rb;
#endif /* NO_PROTO */
{
    return rfuncs_0_(12, i1, (integer *)0, (integer *)0, ra, rb, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rfa3_(integer *i1, real *ra, real *rb, real *rc)
#else /* NO_PROTO */
/* Subroutine */ int rfa3_(i1, ra, rb, rc)
integer *i1;
real *ra, *rb, *rc;
#endif /* NO_PROTO */
{
    return rfuncs_0_(13, i1, (integer *)0, (integer *)0, ra, rb, rc, (real *)
	    0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rpm_(integer *i1, real *ra, real *rb)
#else /* NO_PROTO */
/* Subroutine */ int rpm_(i1, ra, rb)
integer *i1;
real *ra, *rb;
#endif /* NO_PROTO */
{
    return rfuncs_0_(14, i1, (integer *)0, (integer *)0, ra, rb, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int ratr_(real *r1, real *r2, real *r3, real *r4, char *
	chars, ftnlen chars_len)
#else /* NO_PROTO */
/* Subroutine */ int ratr_(r1, r2, r3, r4, chars, chars_len)
real *r1, *r2, *r3, *r4;
char *chars;
ftnlen chars_len;
#endif /* NO_PROTO */
{
    return rfuncs_0_(15, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, r2, chars, r3, r4, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, chars_len);
    }

#ifndef NO_PROTO
/* Subroutine */ int rfas_(integer *i1, integer *ia, real *ra, real *rb)
#else /* NO_PROTO */
/* Subroutine */ int rfas_(i1, ia, ra, rb)
integer *i1, *ia;
real *ra, *rb;
#endif /* NO_PROTO */
{
    return rfuncs_0_(16, i1, (integer *)0, (integer *)0, ra, rb, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rfas3_(integer *i1, integer *ia, real *ra, real *rb, 
	real *rc)
#else /* NO_PROTO */
/* Subroutine */ int rfas3_(i1, ia, ra, rb, rc)
integer *i1, *ia;
real *ra, *rb, *rc;
#endif /* NO_PROTO */
{
    return rfuncs_0_(17, i1, (integer *)0, (integer *)0, ra, rb, rc, (real *)
	    0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rca3_(real *ra, real *rb, real *rc, integer *i1, integer 
	*i2, integer *i3, integer *i4, integer *i5, integer *i6, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rca3_(ra, rb, rc, i1, i2, i3, i4, i5, i6, ia)
real *ra, *rb, *rc;
integer *i1, *i2, *i3, *i4, *i5, *i6, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(18, i1, i2, (integer *)0, ra, rb, rc, (real *)0, (real *)
	    0, (char *)0, (real *)0, (real *)0, ia, i3, i4, i5, i6, (integer *
	    )0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rca_(real *r1, real *r2, real *r3, real *r4, integer *i1,
	 integer *i2, integer *i3, integer *i4, integer *i5, integer *i6, 
	integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rca_(r1, r2, r3, r4, i1, i2, i3, i4, i5, i6, ia)
real *r1, *r2, *r3, *r4;
integer *i1, *i2, *i3, *i4, *i5, *i6, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(19, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, r1, r2, (char *)0, r3, r4, ia, i3, i4, i5, i6, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsplr_(integer *wkid, integer *i1, integer *i2, real *r1,
	 integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rsplr_(wkid, i1, i2, r1, i3)
integer *wkid, *i1, *i2;
real *r1;
integer *i3;
#endif /* NO_PROTO */
{
    return rfuncs_0_(20, i1, i2, wkid, (real *)0, (real *)0, (real *)0, r1, (
	    real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rspmr_(integer *wkid, integer *i1, integer *i2, real *r1,
	 integer *i3)
#else /* NO_PROTO */
/* Subroutine */ int rspmr_(wkid, i1, i2, r1, i3)
integer *wkid, *i1, *i2;
real *r1;
integer *i3;
#endif /* NO_PROTO */
{
    return rfuncs_0_(21, i1, i2, wkid, (real *)0, (real *)0, (real *)0, r1, (
	    real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxp_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rstxp_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(22, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxal_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rstxal_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(23, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsatal_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rsatal_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(24, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsis_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsis_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(25, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsii_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsii_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(26, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsmksc_(real *r1)
#else /* NO_PROTO */
/* Subroutine */ int rsmksc_(r1)
real *r1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(27, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, (real *)0, (char *)0, (real *)0, (real *
	    )0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxfn_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rstxfn_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(28, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsans_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsans_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(29, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsparf_(real *r1, real *r2)
#else /* NO_PROTO */
/* Subroutine */ int rsparf_(r1, r2)
real *r1, *r2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(30, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, r2, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsir_(integer *wkid, integer *i1, integer *i2, integer *
	i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rsir_(wkid, i1, i2, i3, i4)
integer *wkid, *i1, *i2, *i3, *i4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(31, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3,
	     i4, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)
	    0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rspar_(integer *wkid, integer *i1, integer *i2, integer *
	i3, integer *i4, integer *i5, integer *i6, integer *i7, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rspar_(wkid, i1, i2, i3, i4, i5, i6, i7, ia)
integer *wkid, *i1, *i2, *i3, *i4, *i5, *i6, *i7, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(32, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, i3, i4, i5, 
	    i6, i7, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxr_(integer *wkid, integer *i1, integer *i2, integer *
	i3, real *r1, real *r2, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rstxr_(wkid, i1, i2, i3, r1, r2, i4)
integer *wkid, *i1, *i2, *i3;
real *r1, *r2;
integer *i4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(33, i1, i2, wkid, (real *)0, (real *)0, (real *)0, r1, 
	    r2, (char *)0, (real *)0, (real *)0, (integer *)0, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)
	    0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedi_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsedi_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(34, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedci_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsedci_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(35, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsplci_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsplci_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(36, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxci_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rstxci_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(37, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rstxi_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rstxi_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(38, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedr_(integer *wkid, integer *i1, integer *i2, integer *
	i3, real *r1, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rsedr_(wkid, i1, i2, i3, r1, i4)
integer *wkid, *i1, *i2, *i3;
real *r1;
integer *i4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(39, i1, i2, wkid, (real *)0, (real *)0, (real *)0, r1, (
	    real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3, i4, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)
	    0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rspli_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rspli_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(40, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsln_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsln_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(41, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rspmci_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rspmci_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(42, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rschxp_(real *r1)
#else /* NO_PROTO */
/* Subroutine */ int rschxp_(r1)
real *r1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(43, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, r1, (real *)0, (char *)0, (real *)0, (real *
	    )0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedfg_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsedfg_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(44, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rads_(integer *i1, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rads_(i1, ia)
integer *i1, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(45, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     ia, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rres_(integer *i1, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rres_(i1, ia)
integer *i1, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(46, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     ia, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsiasf_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rsiasf_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(47, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rshlft_(integer *wkid, integer *i1, integer *ia, integer 
	*i2, integer *ib)
#else /* NO_PROTO */
/* Subroutine */ int rshlft_(wkid, i1, ia, i2, ib)
integer *wkid, *i1, *ia, *i2, *ib;
#endif /* NO_PROTO */
{
    return rfuncs_0_(48, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, ib, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)
	    0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rshrid_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rshrid_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(49, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsivft_(integer *wkid, integer *i1, integer *ia, integer 
	*i2, integer *ib)
#else /* NO_PROTO */
/* Subroutine */ int rsivft_(wkid, i1, ia, i2, ib)
integer *wkid, *i1, *ia, *i2, *ib;
#endif /* NO_PROTO */
{
    return rfuncs_0_(50, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, ib, (
	    real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (integer *)
	    0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rscmd_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rscmd_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(51, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rscr_(integer *wkid, integer *i1, integer *i2, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rscr_(wkid, i1, i2, ra)
integer *wkid, *i1, *i2;
real *ra;
#endif /* NO_PROTO */
{
    return rfuncs_0_(52, i1, i2, wkid, ra, (real *)0, (real *)0, (real *)0, (
	    real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rshrm_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rshrm_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(53, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsvwr_(integer *wkid, integer *i1, real *xfa, real *xfb, 
	real *vclip, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rsvwr_(wkid, i1, xfa, xfb, vclip, i2)
integer *wkid, *i1;
real *xfa, *xfb, *vclip;
integer *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(54, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, xfa, xfb, vclip, (real *)0, (real *)0, (integer *
	    )0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rswkw_(integer *wkid, real *r1, real *r2, real *r3, real 
	*r4)
#else /* NO_PROTO */
/* Subroutine */ int rswkw_(wkid, r1, r2, r3, r4)
integer *wkid;
real *r1, *r2, *r3, *r4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(55, (integer *)0, (integer *)0, wkid, (real *)0, (real *)
	    0, (real *)0, r1, r2, (char *)0, r3, r4, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rswkw3_(integer *wkid, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rswkw3_(wkid, ra)
integer *wkid;
real *ra;
#endif /* NO_PROTO */
{
    return rfuncs_0_(56, (integer *)0, (integer *)0, wkid, ra, (real *)0, (
	    real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rswkv3_(integer *wkid, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rswkv3_(wkid, ra)
integer *wkid;
real *ra;
#endif /* NO_PROTO */
{
    return rfuncs_0_(57, (integer *)0, (integer *)0, wkid, ra, (real *)0, (
	    real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rswkv_(integer *wkid, real *r1, real *r2, real *r3, real 
	*r4)
#else /* NO_PROTO */
/* Subroutine */ int rswkv_(wkid, r1, r2, r3, r4)
integer *wkid;
real *r1, *r2, *r3, *r4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(58, (integer *)0, (integer *)0, wkid, (real *)0, (real *)
	    0, (real *)0, r1, r2, (char *)0, r3, r4, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)
	    0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsgmt_(real *xfa)
#else /* NO_PROTO */
/* Subroutine */ int rsgmt_(xfa)
real *xfa;
#endif /* NO_PROTO */
{
    return rfuncs_0_(59, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, 
	    (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, xfa, (real *)0, (real *
	    )0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsvwr3_(integer *wkid, integer *i1, real *xga, real *xgb,
	 real *vclip, integer *i2, integer *i3, integer *i4)
#else /* NO_PROTO */
/* Subroutine */ int rsvwr3_(wkid, i1, xga, xgb, vclip, i2, i3, i4)
integer *wkid, *i1;
real *xga, *xgb, *vclip;
integer *i2, *i3, *i4;
#endif /* NO_PROTO */
{
    return rfuncs_0_(60, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3,
	     i4, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    real *)0, (real *)0, vclip, xga, xgb, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rslmt_(real *xfa, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rslmt_(xfa, i1)
real *xfa;
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(61, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, xfa, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsmcv_(integer *i1, integer *i2, real *ra)
#else /* NO_PROTO */
/* Subroutine */ int rsmcv_(i1, i2, ra)
integer *i1, *i2;
real *ra;
#endif /* NO_PROTO */
{
    return rfuncs_0_(62, i1, i2, (integer *)0, ra, (real *)0, (real *)0, (
	    real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsvwi_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsvwi_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(63, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsvtip_(integer *wkid, integer *i1, integer *i2, integer 
	*i3)
#else /* NO_PROTO */
/* Subroutine */ int rsvtip_(wkid, i1, i2, i3)
integer *wkid, *i1, *i2, *i3;
#endif /* NO_PROTO */
{
    return rfuncs_0_(64, i1, i2, wkid, (real *)0, (real *)0, (real *)0, (real 
	    *)0, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, i3,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rclst_(void)
#else /* NO_PROTO */
/* Subroutine */ int rclst_()
#endif /* NO_PROTO */
{
    return rfuncs_0_(65, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, 
	    (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rlb_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rlb_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(66, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsep_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsep_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(67, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rexst_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rexst_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(68, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rcelst_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rcelst_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(69, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdel_(void)
#else /* NO_PROTO */
/* Subroutine */ int rdel_()
#endif /* NO_PROTO */
{
    return rfuncs_0_(70, (integer *)0, (integer *)0, (integer *)0, (real *)0, 
	    (real *)0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, 
	    (real *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)0,
	     (integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rsedm_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rsedm_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(71, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int remst_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int remst_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(72, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdsn_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rdsn_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(73, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rcstir_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rcstir_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(74, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rscnrs_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rscnrs_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(75, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rpost_(integer *wkid, integer *i1, real *r1)
#else /* NO_PROTO */
/* Subroutine */ int rpost_(wkid, i1, r1)
integer *wkid, *i1;
real *r1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(76, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *
	    )0, r1, (real *)0, (char *)0, (real *)0, (real *)0, (integer *)0, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rseplb_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rseplb_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(77, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdellb_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int rdellb_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(78, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rupost_(integer *wkid, integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rupost_(wkid, i1)
integer *wkid, *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(79, i1, (integer *)0, wkid, (real *)0, (real *)0, (real *
	    )0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rupast_(integer *wkid)
#else /* NO_PROTO */
/* Subroutine */ int rupast_(wkid)
integer *wkid;
#endif /* NO_PROTO */
{
    return rfuncs_0_(80, (integer *)0, (integer *)0, wkid, (real *)0, (real *)
	    0, (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)
	    0, (integer *)0, (integer *)0, (integer *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int roparf_(integer *i1, integer *i2)
#else /* NO_PROTO */
/* Subroutine */ int roparf_(i1, i2)
integer *i1, *i2;
#endif /* NO_PROTO */
{
    return rfuncs_0_(81, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rclarf_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rclarf_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(82, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rarst_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rarst_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(83, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rarsn_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rarsn_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(84, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rarast_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rarast_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(85, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrsid_(integer *i1, integer *i2, integer *i3, integer *
	ia)
#else /* NO_PROTO */
/* Subroutine */ int rrsid_(i1, i2, i3, ia)
integer *i1, *i2, *i3, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(86, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, i3, 
	    (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *
	    )0, (real *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrast_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rrast_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(87, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrest_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rrest_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(88, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rresn_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rresn_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(89, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrepan_(integer *i1, integer *i2, integer *i3, integer *
	i4, integer *i5, integer *i6, integer *i7, integer *i8, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rrepan_(i1, i2, i3, i4, i5, i6, i7, i8, ia)
integer *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(90, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, i3, 
	    i4, i5, i6, i7, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, i8, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rrepde_(integer *i1, integer *i2, integer *i3, integer *
	i4, integer *i5, integer *i6, integer *i7, integer *i8, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rrepde_(i1, i2, i3, i4, i5, i6, i7, i8, ia)
integer *i1, *i2, *i3, *i4, *i5, *i6, *i7, *i8, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(91, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, i3, 
	    i4, i5, i6, i7, (integer *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (real *)0, i8, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdstar_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rdstar_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(92, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdasar_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rdasar_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(93, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rdsnar_(integer *i1, integer *i2, integer *ia)
#else /* NO_PROTO */
/* Subroutine */ int rdsnar_(i1, i2, ia)
integer *i1, *i2, *ia;
#endif /* NO_PROTO */
{
    return rfuncs_0_(94, i1, i2, (integer *)0, (real *)0, (real *)0, (real *)
	    0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0, ia, (
	    integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer *)
	    0, (integer *)0, (real *)0, (real *)0, (real *)0, (real *)0, (
	    real *)0, (integer *)0, (ftnint)0);
    }

#ifndef NO_PROTO
/* Subroutine */ int rserhm_(integer *i1)
#else /* NO_PROTO */
/* Subroutine */ int rserhm_(i1)
integer *i1;
#endif /* NO_PROTO */
{
    return rfuncs_0_(95, i1, (integer *)0, (integer *)0, (real *)0, (real *)0,
	     (real *)0, (real *)0, (real *)0, (char *)0, (real *)0, (real *)0,
	     (integer *)0, (integer *)0, (integer *)0, (integer *)0, (integer 
	    *)0, (integer *)0, (integer *)0, (real *)0, (real *)0, (real *)0, 
	    (real *)0, (real *)0, (integer *)0, (ftnint)0);
    }

