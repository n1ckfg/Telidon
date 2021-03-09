/* p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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
static integer c__207 = 207;
static integer c__209 = 209;
static integer c__100 = 100;
static real c_b16 = (float).5;
static integer c__101 = 101;
static real c_b21 = (float).3;
static integer c__210 = 210;
static integer c__11 = 11;
static integer c__213 = 213;
static integer c__217 = 217;
static integer c__220 = 220;
static integer c__222 = 222;
static integer c__226 = 226;
static integer c__230 = 230;
static integer c__235 = 235;
static integer c__256 = 256;
static integer c__262 = 262;
static integer c__268 = 268;
static integer c__270 = 270;
static integer c__276 = 276;
static integer c__280 = 280;
static integer c__300 = 300;
static integer c__301 = 301;
static integer c__302 = 302;
static real c_b76 = (float).9;
static real c_b80 = (float)1.;
static real c_b82 = (float).15;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__10 = 10;
static integer c__312 = 312;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 09.02.11/01                           * */
/*  *    TEST TITLE : Error indicator = 2200                * */
/*  *                                                       * */
/*  *    PHIGS Validation Tests, produced by NIST           * */
/*  *                                                       * */
/*  ********************************************************* */
/* Main program */ MAIN__()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy();

    /* Local variables */
    extern /* Subroutine */ int ntx ();
    static integer ia210[20]	/* was [2][10] */, arnm, isiz;
    extern /* Subroutine */ int nqif (), niss ();
    static integer idum1, specwt;
    static real rdum1;
    static float px[1], py[1];
    static integer errind, number, stindx, spath[2]	/* was [2][1] */;
    extern /* Subroutine */ int initgl_(), xpopph_(), setvs_(), nopwk (), 
	    nqewk (), chkinq_(), ichkz_(), nqphf (), nqmclf (), nopst (), 
	    nexst (), nclst (), avarnm_(), narast (), nqcst (), nclarf (), 
	    nqevwi (), npost (), nqpost (), nqepli (), nqetxi (), nqeedi (), 
	    nqeci (), nqhrif (), nqplf (), nqanf (), nqcmdf (), nqegdp (), 
	    nqwkpo (), endit_();
    Pint_list ids;
    Pline_facs linefacs;
    Pint_facs intfacs;
    Pposted_struct_list  postlist;
    Ppoint ref;
    Pelem_ref_list sp, fp;
    Pclip_ind clip;
    Pint ceil;
    Pfilter_list norm, inv;

    px[0] = (float)1.;
    py[0] = (float)1.;

    initgl_("09.02.11/01", 11L);
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    s_copy(errchr_1.curcon, "start index is out of range", 200L, 27L);
    setvs_("2200", errinf_1.experr, &errinf_1.expsiz, 4L);
    s_copy(errchr_1.errsrs, "1", 40L, 1L);

    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
    nqwkc (&globnu_1.wkid, &errind, &idum1, &specwt);
    chkinq_("pqwkc", &errind, 5L);
    
    ids.ints = (Pint *) calloc(1, sizeof(Pint));

    nqewk (&c__0, &errind, &number, &idum1);
    chkinq_("pqewk", &errind, 5L);
    if (number != 0) {
	stindx = number ;
/*         CALL RQEWK (NUMEWK, ERRIND, IDUM1, IDUM1) */
        pinq_list_avail_ws_types(c__1,stindx,&errind,&ids,&idum1);
	ichkz_(&errind, &c__204);
    }

    nqphf (&c__0, &errind, &idum1, &idum1, &idum1, &number, &idum1, &idum1, 
	   &idum1);
    chkinq_("pqphf", &errind, 5L);
    if (number != 0) {
	stindx = -1;
/*        CALL RQPHF */
        pinq_phigs_facs(c__1,stindx,&errind,&idum1,&idum1,&idum1,&ids,&idum1,
                       &idum1,&idum1);
	ichkz_(&errind, &c__205);
    }

    nqmclf (&c__0, &errind, &idum1, &number, &idum1);
    chkinq_("pqmclf", &errind, 6L);
    if (number != 0) {
	stindx = number ;
/*        CALL RQMCLF */
        pinq_model_clip_facs(c__1,stindx,&errind,&idum1,&ids,&idum1);
	ichkz_(&errind, &c__207);
    }

    stindx = -1;
/*     CALL RQOPWK */
    pinq_open_wss(c__1,stindx,&errind,&ids,&idum1);
    ichkz_(&errind, &c__209);

    nopst (&c__100);
    ntx (&c_b16, &c_b16, "TEXT", 4L);
    nexst (&c__101);
    nclst ();
    nopst (&c__101);
    ntx (&c_b21, &c_b21, "TEXT3", 5L);
    nclst ();
    stindx = 3;
/*     CALL RQSID */
    pinq_struct_ids(c__1,stindx,&errind,&ids,&idum1);
    ichkz_(&errind, &c__210);
    
    avarnm_(&arnm);
    noparf (&c__11, &arnm);
    narast (&c__11);
    stindx = 2;
/*     CALL RQCST */
    pinq_all_conf_structs(c__11,c__1,stindx,&errind,&ids,&idum1);
    ichkz_(&errind, &c__213);
    
    nclarf (&c__11);

    nqevwi (&globnu_1.wkid, &c__0, &errind, &number, &idum1);
    chkinq_("pqevwi", &errind, 6L);
    if (number != 0) {
	stindx = number ;
/*        CALL RQEVWI */
        pinq_list_view_inds(globnu_1.wkid,c__1,stindx,&errind,&ids,&idum1);
	ichkz_(&errind, &c__217);
    }

    npost (&globnu_1.wkid, &c__100, &c_b16);
    stindx = 1;
/*     CALL RQPOST */
    postlist.postings = (Pposted_struct *) calloc(1,sizeof(Pposted_struct));
    pinq_posted_structs(globnu_1.wkid,c__1,stindx,&errind,&postlist,&idum1);
    ichkz_(&errind, &c__220);
    free (postlist.postings);

    nqepli (&globnu_1.wkid, &c__0, &errind, &number, &idum1);
    chkinq_("pqepli", &errind, 6L);
    if (number != 0) {
	stindx = number ;
/*        CALL RQEPLI */
        pinq_list_line_inds(globnu_1.wkid,c__1,stindx,&errind,&ids,&idum1);
	ichkz_(&errind, &c__222);
    }

    nqetxi (&globnu_1.wkid, &c__0, &errind, &number, &idum1);
    chkinq_("pqetxi", &errind, 6L);
    if (number != 0) {
	stindx = number ;
/*        CALL RQETXI */
        pinq_list_text_inds(globnu_1.wkid,c__1,stindx,&errind,&ids,&idum1);
	ichkz_(&errind, &c__226);
    }

    nqeedi (&globnu_1.wkid, &c__0, &errind, &number, &idum1);
    chkinq_("pqeedi", &errind, 6L);
    if (number != 0) {
	stindx = -2;
/*        CALL RQEEDI */
        pinq_list_edge_inds(globnu_1.wkid,c__1,stindx,&errind,&ids,&idum1);
	ichkz_(&errind, &c__230);
    }

    nqeci (&globnu_1.wkid, &c__0, &errind, &number, &idum1);
    if (number != 0) {
	stindx = number ;
/*        CALL RQECI */
        pinq_list_colr_inds(globnu_1.wkid,c__1,stindx,&errind,&ids,&idum1);
	ichkz_(&errind, &c__235);
   }

    nqhrif (&specwt, &c__0, &errind, &number, &idum1);
    chkinq_("pqhrif", &errind, 6L);
    if (number != 0) {
	stindx = number ;   
/*        CALL RQHRIF */
        pinq_hlhsr_id_facs(specwt,c__1,stindx,&errind,&ids,&idum1);
	ichkz_(&errind, &c__256); 
    }     

    nqplf (&specwt, &c__0, &errind, &number, &idum1, &idum1, &rdum1, 
           &rdum1, &rdum1, &idum1);
    chkinq_("pqplf", &errind, 5L);
    if (number != 0) {
	stindx = -1;
/*        CALL RQPLF */
        linefacs.types.ints = (Pint *) calloc(number,sizeof(Pint));
        pinq_line_facs(specwt,c__1,stindx,&errind,&linefacs,&idum1);
	ichkz_(&errind, &c__262);
        free (linefacs.types.ints);
    }

    nqanf (&specwt, &c__0, &errind, &number, &idum1, &idum1, &rdum1, 
	    &rdum1);
    chkinq_("pqanf", &errind, 5L);
    if (number != 0) {
	stindx = number ;
/*        CALL RQANF */
        pinq_anno_facs(specwt,c__1,stindx,&errind,&ids,&idum1,&idum1,
                       &rdum1,&rdum1);
	ichkz_(&errind, &c__268);
    }

    nqif (&specwt, &c__0, &c__0, &errind, &idum1, &idum1, &number, 
	   &idum1, &idum1);
    chkinq_("pqif", &errind, 4L);
    if (number != 0) {
	stindx = -1;     
/*        CALL RQIF */
        intfacs.hatch_styles.ints = (Pint *) calloc(number,sizeof(Pint));
        pinq_int_facs(specwt,c__1,stindx,&errind,&intfacs,&idum1);
	ichkz_(&errind, &c__270);
        free (intfacs.hatch_styles.ints);
    }   

    nqcmdf (&specwt, &c__0, &errind, &number, &idum1, &idum1);
    chkinq_("pqcmdf", &errind, 6L);
    if (number != 0) {
	stindx = number ;
/*        CALL RQCMDF */
        pinq_colr_model_facs(specwt,c__1,stindx,&errind,&ids,&idum1,
                             &idum1);
	ichkz_(&errind, &c__276);
    }

    nqegdp (&specwt, &c__0, &errind, &number, &idum1);
    chkinq_("pqegdp", &errind, 6L);
    if (number != 0) {
        stindx = number;
/*        CALL RQEGDP */
        pinq_list_avail_gdp(specwt,c__1,stindx,&errind,&ids,&idum1);
	ichkz_(&errind, &c__280);
    }   

    nqwkpo (&c__100, &c__0, &errind, &number, &idum1);
    chkinq_("pqwkpo", &errind, 6L);
    if (number != 0) {
	stindx = number ;
/*        CALL RQWKPO */
        pinq_wss_posted(c__100,c__1,stindx,&errind,&ids,&idum1);
	ichkz_(&errind, &c__300);
    }

    nopst (&c__301);
    ntx (&c_b80, &c_b80, "TEXT301", 7L);
    nexst (&c__302);
    nclst ();
    nopst (&c__302);
    npm (&c__1, px, py);
    nclst ();

    stindx = 2;
    ref.x = c_b76;
    ref.y = c_b76;
    sp.num_elem_refs = c__1;
    sp.elem_refs = (Pelem_ref *) calloc (1,sizeof(Pelem_ref));
    sp.elem_refs[0].struct_id = c__301;
    sp.elem_refs[0].elem_pos = c__1;
    clip = c__0;
    ceil = c__1;
    norm.num_filters = c__0;
    inv.num_filters = c__0;
    fp.elem_refs = (Pelem_ref *) calloc (2, sizeof(Pelem_ref));
    pincr_spa_search(&ref,c_b82,&sp,clip,ceil,&norm,&inv,c__1,
                         stindx,&errind,&fp,&idum1);
/*        CALL RISS */
    ichkz_(&errind, &c__312);
    free (fp.elem_refs);

    free (ids.ints);

    endit_();

} /* MAIN__ */

