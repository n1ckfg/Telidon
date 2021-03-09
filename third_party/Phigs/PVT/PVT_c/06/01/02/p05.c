/* fort//06/01/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__123 = 123;
static integer c__101 = 101;
static integer c__104 = 104;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__102 = 102;
static integer c__103 = 103;
static integer c__2 = 2;
static integer c__4 = 4;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 06.01.02/05                           * */
/*  *    TEST TITLE : Effect of local and global            * */
/*  *                 transformations in a structure        * */
/*  *                 network                               * */
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
    /* Initialized data */

#ifndef NO_PROTO
    static real a1[16]	/* was [4][4] */ = { .64f,-.2158f,-.3232f,-.1398f,
	    -.3405f,.9041f,-.1562f,.2284f,-.3458f,-.1908f,.6289f,-.2234f,
	    -.2107f,.2571f,-.1183f,1.3633f };
    static real a2[16]	/* was [4][4] */ = { .7066f,.2092f,-.0416f,-.3792f,
	    -.0907f,.7405f,-.1633f,-.2249f,-.3822f,.1112f,.6808f,.0086f,
	    -.1183f,-.1777f,.0448f,.975f };
    static real a3[16]	/* was [4][4] */ = { .7061f,-.2336f,-.2953f,-.2673f,
	    -.2344f,.828f,-.2632f,-.2501f,.2709f,.0524f,.6326f,-.1435f,.3407f,
	    .3902f,.1875f,1.252f };
    static real a4[16]	/* was [4][4] */ = { .8168f,-.2033f,-.3886f,-.2358f,
	    .1839f,1.1356f,-.3802f,-.3262f,.1461f,.0644f,.7139f,.2245f,.0835f,
	    -.1778f,-.3036f,.8549f };
    static real a5[16]	/* was [4][4] */ = { .6428f,.3743f,.1195f,6e-4f,
	    -.2039f,1.3347f,-.0378f,.1513f,.348f,-.2931f,1.3423f,.2051f,
	    -.2744f,-.259f,.0819f,1.2317f };
    static real ppmx[1] = { 3.f };
    static real ppmy[1] = { 4.f };
    static real ppmz[1] = { 5.f };
#else /* NO_PROTO */
    static real a1[16]	/* was [4][4] */ = { (float).64,(float)-.2158,(float)
	    -.3232,(float)-.1398,(float)-.3405,(float).9041,(float)-.1562,(
	    float).2284,(float)-.3458,(float)-.1908,(float).6289,(float)
	    -.2234,(float)-.2107,(float).2571,(float)-.1183,(float)1.3633 };
    static real a2[16]	/* was [4][4] */ = { (float).7066,(float).2092,(float)
	    -.0416,(float)-.3792,(float)-.0907,(float).7405,(float)-.1633,(
	    float)-.2249,(float)-.3822,(float).1112,(float).6808,(float).0086,
	    (float)-.1183,(float)-.1777,(float).0448,(float).975 };
    static real a3[16]	/* was [4][4] */ = { (float).7061,(float)-.2336,(
	    float)-.2953,(float)-.2673,(float)-.2344,(float).828,(float)
	    -.2632,(float)-.2501,(float).2709,(float).0524,(float).6326,(
	    float)-.1435,(float).3407,(float).3902,(float).1875,(float)1.252 }
	    ;
    static real a4[16]	/* was [4][4] */ = { (float).8168,(float)-.2033,(
	    float)-.3886,(float)-.2358,(float).1839,(float)1.1356,(float)
	    -.3802,(float)-.3262,(float).1461,(float).0644,(float).7139,(
	    float).2245,(float).0835,(float)-.1778,(float)-.3036,(float).8549 
	    };
    static real a5[16]	/* was [4][4] */ = { (float).6428,(float).3743,(float)
	    .1195,(float)6e-4,(float)-.2039,(float)1.3347,(float)-.0378,(
	    float).1513,(float).348,(float)-.2931,(float)1.3423,(float).2051,(
	    float)-.2744,(float)-.259,(float).0819,(float)1.2317 };
    static real ppmx[1] = { (float)3. };
    static real ppmy[1] = { (float)4. };
    static real ppmz[1] = { (float)5. };
#endif /* NO_PROTO */

#ifndef NO_PROTO
    extern /* Subroutine */ int npm3 (integer *, real *, real *, real *), 
	    ecom3_(real *, real *, real *), idmat_(integer *, real *), endit_(
	    void), inmsg_(char *, ftnlen), nclst (void), nexst (integer *), 
	    nopst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int npm3 (), ecom3_(), idmat_(), endit_(), inmsg_(
	    ), nclst (), nexst (), nopst ();
#endif /* NO_PROTO */
    static real ex1com[16]	/* was [4][4] */, ex2com[16]	/* was [4][4] 
	    */;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsgmt3 (real *), nslmt3 (real *, integer *);
    extern logical sphdis_(integer *);
    extern /* Subroutine */ int initgl_(char *, ftnlen), comtok_(real *, char 
	    *, ftnlen), setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(
	    integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsgmt3 (), nslmt3 ();
    extern logical sphdis_();
    extern /* Subroutine */ int initgl_(), comtok_(), setmsg_(), xpopph_();
#endif /* NO_PROTO */

/* composition type */
/*                preconcatenate  postconcatenate  replace */
/*  Set up arbitrary matrices: */
    initgl_("06.01.02/05", 11L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    if (! sphdis_(&c__123)) {
#ifndef NO_PROTO
	inmsg_("Skipping test because implementation apparently uses non-Euc"
		"lidean metric for search distance.", 94L);
#else /* NO_PROTO */
	inmsg_("Skipping test because implementation apparently uses non-Euc\
lidean metric for search distance.", 94L);
#endif /* NO_PROTO */
	goto L666;
    }
/*  Throughout, use incremental spatial search (ISS) to test the */
/*  effects of the current global and local modelling */
/*  transformations.  The search reference point (SRP) is based on */
/*  an MC location of (3,4,5), adjusted to account for the expected */
/*  transformation. */
/*  Set up structure #101: */
    nopst (&c__101);
    nexst (&c__104);
    npm3 (&c__1, ppmx, ppmy, ppmz);
    nsgmt3 (a1);
    nslmt3 (a2, &c__0);
    nexst (&c__102);
    nslmt3 (a3, &c__1);
    npm3 (&c__1, ppmx, ppmy, ppmz);
    nsgmt3 (a4);
    nexst (&c__103);
    nclst ();
/*  Set up structure #102: */
    nopst (&c__102);
    npm3 (&c__1, ppmx, ppmy, ppmz);
    nsgmt3 (a5);
    npm3 (&c__1, ppmx, ppmy, ppmz);
    nsgmt3 (a3);
    nexst (&c__103);
    nslmt3 (a4, &c__0);
    nexst (&c__104);
    npm3 (&c__1, ppmx, ppmy, ppmz);
    nclst ();
/*  Set up structure #103: */
    nopst (&c__103);
    npm3 (&c__1, ppmx, ppmy, ppmz);
    nslmt3 (a1, &c__0);
    npm3 (&c__1, ppmx, ppmy, ppmz);
    nclst ();
/*  Set up structure #104: */
    nopst (&c__104);
    nsgmt3 (a1);
    nslmt3 (a2, &c__2);
    nclst ();
#ifndef NO_PROTO
    setmsg_("16 17 19 20", "If no transformations have been set since the on"
	    "set of traversal, the composite modelling transformation should "
	    "be restored to the identity matrix after invocation of a structu"
	    "re network.", 11L, 187L);
#else /* NO_PROTO */
    setmsg_("16 17 19 20", "If no transformations have been set since the on\
set of traversal, the composite modelling transformation should be restored \
to the identity matrix after invocation of a structure network.", 11L, 187L);
#endif /* NO_PROTO */
/*  expected composite transformation = identity matrix */
    idmat_(&c__4, ex1com);
    comtok_(ex1com, "101,2", 5L);
#ifndef NO_PROTO
    setmsg_("16 17 21 22", "At the start of a sub-traversal caused by <execu"
	    "te structure>, the new composite modelling transformation should"
	    " be unchanged from that of the invoking structure.", 11L, 162L);
#else /* NO_PROTO */
    setmsg_("16 17 21 22", "At the start of a sub-traversal caused by <execu\
te structure>, the new composite modelling transformation should be unchange\
d from that of the invoking structure.", 11L, 162L);
#endif /* NO_PROTO */
/*  expected composite transformation = A1 x A2 */
    ecom3_(a1, a2, ex1com);
    comtok_(ex1com, "101,5, 102,1", 12L);
#ifndef NO_PROTO
    setmsg_("16 17 21 22", "Replacing the global modelling transformation wi"
	    "thin a sub-traversal without altering the local modelling transf"
	    "ormation should replace the composite transformation.", 11L, 165L)
	    ;
#else /* NO_PROTO */
    setmsg_("16 17 21 22", "Replacing the global modelling transformation wi\
thin a sub-traversal without altering the local modelling transformation sho\
uld replace the composite transformation.", 11L, 165L);
#endif /* NO_PROTO */
/*  expected composite transformation = A5 */
    comtok_(a5, "101,5, 102,3", 12L);
#ifndef NO_PROTO
    setmsg_("16 17 21 22", "At the start of a sub-traversal several levels d"
	    "eep, the composite modelling transformation should be unchanged "
	    "from that of the immediately invoking structure.", 11L, 160L);
#else /* NO_PROTO */
    setmsg_("16 17 21 22", "At the start of a sub-traversal several levels d\
eep, the composite modelling transformation should be unchanged from that of\
 the immediately invoking structure.", 11L, 160L);
#endif /* NO_PROTO */
/*  expected composite transformation = A3 */
    comtok_(a3, "101,5, 102,5, 103,1", 19L);
#ifndef NO_PROTO
    setmsg_("16 17 21 22", "Replacing the local modelling transformation wit"
	    "hin a sub-traversal without altering the global modelling transf"
	    "ormation should postconcatenate the specified matrix to the old "
	    "value of the composite transformation.", 11L, 214L);
#else /* NO_PROTO */
    setmsg_("16 17 21 22", "Replacing the local modelling transformation wit\
hin a sub-traversal without altering the global modelling transformation sho\
uld postconcatenate the specified matrix to the old value of the composite t\
ransformation.", 11L, 214L);
#endif /* NO_PROTO */
/*  expected composite transformation = A3 x A1 */
    ecom3_(a3, a1, ex1com);
    comtok_(ex1com, "101,5, 102,5, 103,3", 19L);
#ifndef NO_PROTO
    setmsg_("16 17 20", "Upon returning from a sub-traversal, the global and"
	    " local modelling transformations should be restored to the value"
	    " they had just before the sub-traversal.", 8L, 155L);
#else /* NO_PROTO */
    setmsg_("16 17 20", "Upon returning from a sub-traversal, the global and\
 local modelling transformations should be restored to the value they had ju\
st before the sub-traversal.", 8L, 155L);
#endif /* NO_PROTO */
/*  expected composite transformation = A3 x A4 */
    ecom3_(a3, a4, ex1com);
    comtok_(ex1com, "101,5, 102,8", 12L);
#ifndef NO_PROTO
    setmsg_("16 17 20", "Upon returning several levels from a sub-traversal,"
	    " the global and local modelling transformations should be restor"
	    "ed to the value they had just before the sub-traversal.", 8L, 
	    170L);
#else /* NO_PROTO */
    setmsg_("16 17 20", "Upon returning several levels from a sub-traversal,\
 the global and local modelling transformations should be restored to the va\
lue they had just before the sub-traversal.", 8L, 170L);
#endif /* NO_PROTO */
/*  expected composite transformation = A1 x A3 x A2 */
    ecom3_(a3, a2, ex1com);
    ecom3_(a1, ex1com, ex2com);
    comtok_(ex2com, "101,7", 5L);
#ifndef NO_PROTO
    setmsg_("16 17 21 22", "At the start of a sub-traversal the new composit"
	    "e modelling transformation should be unchanged from that of the "
	    "invoking structure, even if the invoked structure has been execu"
	    "ted previously in the traversal.", 11L, 208L);
#else /* NO_PROTO */
    setmsg_("16 17 21 22", "At the start of a sub-traversal the new composit\
e modelling transformation should be unchanged from that of the invoking str\
ucture, even if the invoked structure has been executed previously in the tr\
aversal.", 11L, 208L);
#endif /* NO_PROTO */
/*  expected composite transformation = A4 x A3 x A2 */
    ecom3_(a4, ex1com, ex2com);
    comtok_(ex2com, "101,9, 103,1", 12L);
#ifndef NO_PROTO
    setmsg_("16 17 21 22", "Replacing the local modelling transformation wit"
	    "hin a sub-traversal without altering the global modelling transf"
	    "ormation should postconcatenate the specified matrix to the old "
	    "value of the composite transformation, even if the invoked struc"
	    "ture has been executed previously in the traversal.", 11L, 291L);
#else /* NO_PROTO */
    setmsg_("16 17 21 22", "Replacing the local modelling transformation wit\
hin a sub-traversal without altering the global modelling transformation sho\
uld postconcatenate the specified matrix to the old value of the composite t\
ransformation, even if the invoked structure has been executed previously in\
 the traversal.", 11L, 291L);
#endif /* NO_PROTO */
/*  expected composite transformation = A4 x A3 x A2 x A1 */
    ecom3_(ex2com, a1, ex1com);
    comtok_(ex1com, "101,9, 103,3", 12L);
L666:
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

