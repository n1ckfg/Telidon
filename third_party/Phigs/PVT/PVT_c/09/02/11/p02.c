/* p02.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"
#include "phigs.h"

/* Common Block Declarations */

struct {
    integer ctlhnd, errsig, errfil, ierrct, unerr, testct, iflerr, passsw, 
	    errsw, maxlin, conid, memun, wkid, wtype, glblun, indlun, dumint[
	    20];
    real dumrl[20];
} globnu_;

#define globnu_1 globnu_

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

static integer c__0 = 0;
static integer c__204 = 204;
static integer c__205 = 205;
static integer c__206 = 206;
static integer c__209 = 209;
static integer c__100 = 100;
static real c_b18 = (float).5;
static integer c__101 = 101;
static real c_b23 = (float).7;
static integer c__210 = 210;
static integer c__11 = 11;
static integer c__214 = 214;
static integer c__224 = 224;
static integer c__228 = 228;
static integer c__232 = 232;
static integer c__235 = 235;
static integer c__262 = 262;
static integer c__266 = 266;
static integer c__272 = 272;
static integer c__279 = 279;
static integer c__283 = 283;
static integer c__301 = 301;
static real c_b59 = (float).4;
static integer c__302 = 302;
static integer c__1 = 1;
static integer c__312 = 312;
static real c_b78 = (float).9;
static real c_b80 = (float)1.;
static real c_b82 = (float).15;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.11/02                           * */
/*  *    TEST TITLE : Error indicator = 2201                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
/* Main program */ MAIN__()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy();

    /* Local variables */
    static real px[1], py[1];
    extern /* Subroutine */ int npm (), ntx ();
    static integer arnm, idum1, specwt;
    static real rdum1;
    static integer errind, number, applen;
    extern /* Subroutine */ int initgl_(), xpopph_ (), setvs_(), nopwk (), 
	    nqewk (), chkinq_(), ichkz_(), nqphf (), nqgsef (), nqopwk (), 
	    nopst (), nexst (), nclst (), avarnm_(), noparf (), narast (), 
	    nclarf (), nqepmi (), nqeii (), nqepai (), nqeci (), nqplf (), 
	    nqtxf (), nqedf (), nqegd3 (), nqegse (), endit_();
    Pint_list  ids;
    Pgse_id_dep_list  gse;
    Pline_facs  linefacs;
    Ptext_facs  textfacs;
    Pedge_facs  edgefacs;
    Ppoint  ref;
    Pelem_ref_list  sp, fp;
    Pclip_ind clip;
    Pint  ceil;
    Pfilter_list norm, inv;

    px[0] = c_b80;
    py[0] = c_b80;

    initgl_("09.02.11/02", 11L);
    xpopph_ (&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "length of application's list is negative", 200L, 
	    40L);
    s_copy(errchr_1.errsrs, "2", 40L, 1L);
    setvs_("2201", errinf_1.experr, &errinf_1.expsiz, 4L);

    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &idum1, &specwt);
    chkinq_("pqwkc", &errind, 5L);

    ids.ints = (Pint *) calloc(1, sizeof(Pint));

    nqewk (&c__0, &errind, &number, &idum1);
    chkinq_("pqewk", &errind, 5L);
    if (number != 0) {
	applen = -1;
/*        CALL PQEWK */
        pinq_list_avail_ws_types(applen,c__0,&errind,&ids,&idum1);
	ichkz_(&errind, &c__204);
    }

    nqphf (&c__0, &errind, &idum1, &idum1, &idum1, &number, &idum1, &idum1, &
	    idum1);
    chkinq_("pqphf", &errind, 5L);
    if (number != 0) {
	applen = -2;
/*        CALL PQPHF */
        pinq_phigs_facs(applen, c__0, &errind, &idum1, &idum1, &idum1, &ids, &idum1,
                        &idum1, &idum1);
	ichkz_(&errind, &c__205);
    }

    nqgsef (&c__0, &errind, &number, &idum1, &idum1);
    chkinq_("pqgsef", &errind, 6L);
    if (number != 0) {
/*        CALL PQGSEF */
        gse.id_facs = (Pgse_id_dep *) calloc (1, sizeof(Pgse_id_dep));
        pinq_gse_facs(applen,c__0,&errind,&gse,&idum1);
	ichkz_(&errind, &c__206);
        free (gse.id_facs);
    }

    nqopwk (&c__0, &errind, &number, &idum1);
    chkinq_("pqopwk", &errind, 6L);
    if (number != 0) {
	applen = -3;
/*        CALL PQOPWK */
        pinq_open_wss(applen,c__0,&errind,&ids,&idum1);
	ichkz_(&errind, &c__209);
    }

    nopst (&c__100);
    ntx (&c_b18, &c_b18, "TEXT100", 7L);
    nexst (&c__101);
    nclst ();
    nopst (&c__101);
    ntx (&c_b23, &c_b23, "TEXT101", 7L);
    nclst ();

    applen = -10;
/*     CALL PQSID */
    pinq_struct_ids(applen,c__0,&errind,&ids,&idum1);
    ichkz_(&errind, &c__210);

    avarnm_(&arnm);
    noparf (&c__11, &arnm);
    narast (&c__11);

    applen = -1;
/*     CALL PQCSTN */
    pinq_conf_structs_net (c__11,c__100,PNET_CSS,applen,c__0,
                           &errind,&ids,&idum1);
    ichkz_(&errind, &c__214);

    nclarf (&c__11);

    nqepmi (&globnu_1.wkid, &c__0, &errind, &number, &idum1);
    chkinq_("pqepmi", &errind, 6L);
    if (number != 0) {
	applen = -1;
/*        CALL PQEPMI */
        pinq_list_marker_inds(globnu_1.wkid,applen,c__0,&errind,&ids,&idum1);
	ichkz_(&errind, &c__224);
    }

    nqeii (&globnu_1.wkid, &c__0, &errind, &number, &idum1);
    chkinq_("pqeii", &errind, 5L);
    if (number != 0) {
	applen = -1;
/*        CALL PQEII */
        pinq_list_int_inds(globnu_1.wkid,applen,c__0,&errind,&ids,&idum1);
	ichkz_(&errind, &c__228);
    }

    nqepai (&globnu_1.wkid, &c__0, &errind, &number, &idum1);
    chkinq_("pqepai", &errind, 6L);
    if (number != 0) {
	applen = -1;
/*        CALL APPLEN */
        pinq_list_pat_inds(globnu_1.wkid,applen,c__0,&errind,&ids,&idum1);
	ichkz_(&errind, &c__232);
    }

    nqeci (&globnu_1.wkid, &c__0, &errind, &number, &idum1);
    chkinq_("pqeci", &errind, 5L);
    if (number != 0) {
	applen = -1;
/*        CALL PQECI */
        pinq_list_colr_inds(globnu_1.wkid,applen,c__0,&errind,&ids,&idum1);
	ichkz_(&errind, &c__235);
    }

    nqplf (&specwt, &c__0, &errind, &number, &idum1, &idum1, &rdum1, &
	    rdum1, &rdum1, &idum1);
    chkinq_("pqplf", &errind, 5L);
    if (number != 0) {
	applen = -6;
/*        CALL PQPLF */
        linefacs.types.ints = (Pint *) calloc(1,sizeof(Pint));
        pinq_line_facs(specwt,applen,c__0,&errind,&linefacs,&idum1);
	ichkz_(&errind, &c__262);
        free (linefacs.types.ints);
    }

    nqtxf (&specwt, &c__0, &errind, &number, &idum1, &idum1, &idum1, &
	    rdum1, &rdum1, &idum1, &rdum1, &rdum1, &idum1);
    chkinq_("pqtxf", &errind, 5L);
    if (number != 0) {
	applen = -1;
/*        CALL PQTXF */
        textfacs.font_precs = (Ptext_font_prec *) calloc(1,sizeof(
                               Ptext_font_prec));
        pinq_text_facs(specwt,applen,c__0,&errind,&textfacs,&idum1);
	ichkz_(&errind, &c__266);
        free (textfacs.font_precs);
    }

    nqedf (&specwt, &c__0, &errind, &number, &idum1, &idum1, &rdum1, &
	    rdum1, &rdum1, &idum1);
    chkinq_("pqedf", &errind, 5L);
    if (number != 0) {
	applen = -2;
/*        CALL PQEDF */
        edgefacs.types.ints = (Pint *) calloc (1, sizeof(Pint));
        pinq_edge_facs(specwt,applen,c__0,&errind,&edgefacs,&idum1);
	ichkz_(&errind, &c__272);
        free (edgefacs.types.ints);
    }

    nqegd3 (&specwt, &c__0, &errind, &number, &idum1);
    chkinq_("pqegd3", &errind, 6L);
    if (number != 0) {
	applen = -1;   
/*        CALL PQEGD3 */
        pinq_list_avail_gdp3(specwt,applen,c__0,&errind,&ids,&idum1);
	ichkz_(&errind, &c__279);
    } 

    nqegse (&specwt, &c__0, &errind, &number, &idum1);
    chkinq_("pqegse", &errind, 6L);
    if (number != 0) {
	applen = -1;   
/*        CALL PQEGSE */
        pinq_list_avail_gse(specwt,applen,c__0,&errind,&ids,&idum1);
	ichkz_(&errind, &c__283);
    }   

    nopst (&c__301);
    ntx (&c_b59, &c_b59, "TEXT301", 7L);
    nexst (&c__302);
    nclst ();
    nopst (&c__302);
    npm (&c__1, px, py);
    nclst ();
             
    applen = -1;
/*     CALL PISS */
    ref.x = c_b78;
    ref.y = c_b78;
    sp.num_elem_refs = c__1;
    sp.elem_refs = (Pelem_ref *) calloc(1, sizeof(Pelem_ref));
    sp.elem_refs[0].struct_id = c__301;
    sp.elem_refs[0].elem_pos = c__1;
    clip = c__0;
    ceil = c__1;
    norm.num_filters = c__0;
    inv.num_filters = c__0;
    fp.elem_refs = (Pelem_ref *) calloc(1, sizeof(Pelem_ref));
    pincr_spa_search(&ref,c_b82,&sp,clip,ceil,&norm,&inv,applen,c__0,&errind,
                     &fp,&idum1);
    ichkz_(&errind, &c__312);
    free (fp.elem_refs);

    free (ids.ints);

    endit_();

} /* MAIN__ */

