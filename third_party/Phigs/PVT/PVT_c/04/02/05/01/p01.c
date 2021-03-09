/* fort/04/02/05/01/p01.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__2 = 2;
static integer c__50 = 50;
static integer c__1 = 1;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__3 = 3;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 04.02.05.01/01                        * */
/*  *    TEST TITLE : Simple setting and inquiring          * */
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
    /* System generated locals */
    logical L__1;

    /* Builtin functions */
#ifndef NO_PROTO
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
#else /* NO_PROTO */
    integer s_wsfi(), do_fio(), e_wsfi();
#endif /* NO_PROTO */

    /* Local variables */
    static integer i, rl;
    static char msg[200];
    static integer str;
#ifndef NO_PROTO
    extern /* Subroutine */ int fail_(void), ifpf_(logical *);
#else /* NO_PROTO */
    extern /* Subroutine */ int fail_(), ifpf_();
#endif /* NO_PROTO */
    static real rlar[50];
    static integer intg;
#ifndef NO_PROTO
    extern /* Subroutine */ int nspa (real *, real *), pass_(void), nsis (
	    integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nspa (), pass_(), nsis ();
#endif /* NO_PROTO */
    static real ratr1, ratr2;
    static integer eflag;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), nsici (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), nsici ();
#endif /* NO_PROTO */
    static integer rllen, intar[50];
    static real rincr;
#ifndef NO_PROTO
    extern /* Subroutine */ int inmsg_(char *, ftnlen), nsedt (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int inmsg_(), nsedt ();
#endif /* NO_PROTO */
    static integer strid;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsisi (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsisi ();
#endif /* NO_PROTO */
    static char strar[1*50];
#ifndef NO_PROTO
    extern /* Subroutine */ int nopst (integer *), nsedfg (integer *), 
	    nqceco (integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *, integer *, char *, 
	    ftnlen), nsedci (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nopst (), nsedfg (), nqceco (), nsedci ();
#endif /* NO_PROTO */
    static integer errind, intlen;
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer eltype;
#ifndef NO_PROTO
    extern /* Subroutine */ int setmsg_(char *, char *, ftnlen, ftnlen), 
	    nqcets (integer *, integer *, integer *, integer *, integer *), 
	    nsparf (real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int setmsg_(), nqcets (), nsparf ();
#endif /* NO_PROTO */
    static integer strlen, strarl[50], istyle;
#ifndef NO_PROTO
    extern /* Subroutine */ int nsewsc (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nsewsc ();
#endif /* NO_PROTO */
    static real rptvar[9];
#ifndef NO_PROTO
    extern /* Subroutine */ int xpopph_(integer *, integer *), nsprpv (real *,
	     real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int xpopph_(), nsprpv ();
#endif /* NO_PROTO */

    /* Fortran I/O blocks */
    static icilist io___16 = { 0, msg, 0, "(A,I2,A)", 200, 1 };
    static icilist io___23 = { 0, msg, 0, "(A,I2,A)", 200, 1 };


/* PHIGS parameter types */
/* interior style */
/* edge flag indicator */
    initgl_("04.02.05.01/01", 14L);
/* open PHIGS */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
/* structure identifier = 1 */
    strid = 1;
/* open structure */
    nopst (&strid);
/* *** *** *** *** ***    Interior style    *** *** *** *** *** */
/* set value for attribute */
    nsis (&c__2);
#ifndef NO_PROTO
    setmsg_("1 5", "<Inquire current element type and size> should return in"
	    "terior style as the type of the created element and the appropri"
	    "ate element size.", 3L, 137L);
#else /* NO_PROTO */
    setmsg_("1 5", "<Inquire current element type and size> should return in\
terior style as the type of the created element and the appropriate element \
size.", 3L, 137L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 43 is the PHIGS enumeration type for peis */
    L__1 = errind == 0 && eltype == 43 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 5 6", "<Inquire current element content> should return the st"
	    "andard representation for all valid interior style values.", 5L, 
	    112L);
#else /* NO_PROTO */
    setmsg_("2 5 6", "<Inquire current element content> should return the st\
andard representation for all valid interior style values.", 5L, 112L);
#endif /* NO_PROTO */
    for (istyle = 0; istyle <= 4; ++istyle) {
	nsis (&istyle);
	nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	if (errind == 0 && intar[0] == istyle && intg == 1 && rl == 0 && str 
		== 0) {
/*            OK so far */
	} else {
	    fail_();
	    s_wsfi(&io___16);
	    do_fio(&c__1, "Failure for interior style = ", 29L);
	    do_fio(&c__1, (char *)&istyle, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 200L);
	    goto L110;
	}
/* L100: */
    }
    pass_();
L110:
/* *** *** *** *** ***   Interior style index   *** *** *** *** *** */
/* set value for attribute */
    nsisi (&c__5);
#ifndef NO_PROTO
    setmsg_("1 18", "<Inquire current element type and size> should return i"
	    "nterior style index as the type of the created element and the a"
	    "ppropriate element size.", 4L, 143L);
#else /* NO_PROTO */
    setmsg_("1 18", "<Inquire current element type and size> should return i\
nterior style index as the type of the created element and the appropriate e\
lement size.", 4L, 143L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 44 is the PHIGS enumeration type for peisi */
    L__1 = errind == 0 && eltype == 44 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 18", "<Inquire current element content> should return the sta"
	    "ndard representation for the interior style index value.", 4L, 
	    111L);
#else /* NO_PROTO */
    setmsg_("2 18", "<Inquire current element content> should return the sta\
ndard representation for the interior style index value.", 4L, 111L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peisi */
    L__1 = errind == 0 && intar[0] == 5 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Interior colour index    *** *** *** *** *** */
/* set value for attribute */
    nsici (&c__2);
#ifndef NO_PROTO
    setmsg_("1 26", "<Inquire current element type and size> should return i"
	    "nterior colour index as the type of the created element and the "
	    "appropriate element size.", 4L, 144L);
#else /* NO_PROTO */
    setmsg_("1 26", "<Inquire current element type and size> should return i\
nterior colour index as the type of the created element and the appropriate \
element size.", 4L, 144L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 45 is the PHIGS enumeration type for peici */
    L__1 = errind == 0 && eltype == 45 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 26", "<Inquire current element content> should return the sta"
	    "ndard representation for the interior colour index value.", 4L, 
	    112L);
#else /* NO_PROTO */
    setmsg_("2 26", "<Inquire current element content> should return the sta\
ndard representation for the interior colour index value.", 4L, 112L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peici */
    L__1 = errind == 0 && intar[0] == 2 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Pattern size    *** *** *** *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    ratr1 = 4.1f;
    ratr2 = 5.1f;
#else /* NO_PROTO */
    ratr1 = (float)4.1;
    ratr2 = (float)5.1;
#endif /* NO_PROTO */
    nspa (&ratr1, &ratr2);
#ifndef NO_PROTO
    setmsg_("1 61", "<Inquire current element type and size> should return p"
	    "attern size as the type of the created element and the appropria"
	    "te element size.", 4L, 135L);
#else /* NO_PROTO */
    setmsg_("1 61", "<Inquire current element type and size> should return p\
attern size as the type of the created element and the appropriate element s\
ize.", 4L, 135L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 50 is the PHIGS enumeration type for pepa */
    L__1 = errind == 0 && eltype == 50 && intlen == 0 && rllen == 2 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 61", "<Inquire current element content> should return the sta"
	    "ndard representation for the pattern size value.", 4L, 103L);
#else /* NO_PROTO */
    setmsg_("2 61", "<Inquire current element content> should return the sta\
ndard representation for the pattern size value.", 4L, 103L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peii */
    L__1 = errind == 0 && rlar[0] == ratr1 && rlar[1] == ratr2 && intg == 0 &&
	     rl == 2 && str == 0;
    ifpf_(&L__1);
/* *** *** ***   Pattern reference point and vectors   *** *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    rincr = .5f;
#else /* NO_PROTO */
    rincr = (float).5;
#endif /* NO_PROTO */
    for (i = 1; i <= 9; ++i) {
	rptvar[i - 1] = rincr;
#ifndef NO_PROTO
	rincr += .2f;
#else /* NO_PROTO */
	rincr += (float).2;
#endif /* NO_PROTO */
/* L200: */
    }
    nsprpv (rptvar, &rptvar[1], &rptvar[2], &rptvar[3], &rptvar[5], &rptvar[7]
	    );
#ifndef NO_PROTO
    setmsg_("1 66", "<Inquire current element type and size> should return p"
	    "attern reference point and vectors as the type of the created el"
	    "ement and the appropriate element size.", 4L, 158L);
#else /* NO_PROTO */
    setmsg_("1 66", "<Inquire current element type and size> should return p\
attern reference point and vectors as the type of the created element and th\
e appropriate element size.", 4L, 158L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 51 is the PHIGS enumeration type for peprpv */
    L__1 = errind == 0 && eltype == 51 && intlen == 0 && rllen == 9 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 66", "<Inquire current element content> should return the sta"
	    "ndard representation for the pattern reference point and vectors"
	    " values.", 4L, 127L);
#else /* NO_PROTO */
    setmsg_("2 66", "<Inquire current element content> should return the sta\
ndard representation for the pattern reference point and vectors values.", 4L,
	     127L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peprpv */
    L__1 = errind == 0 && rlar[0] == rptvar[0] && rlar[1] == rptvar[1] && 
	    rlar[2] == rptvar[2] && rlar[3] == rptvar[3] && rlar[4] == rptvar[
	    5] && rlar[5] == rptvar[7] && rlar[6] == rptvar[4] && rlar[7] == 
	    rptvar[6] && rlar[8] == rptvar[8] && intg == 0 && rl == 9 && str 
	    == 0;
    ifpf_(&L__1);
/* reference point: */
/* vector 1: */
/* vector 2: */
/* array sizes: */
/* *** *** *** ***   Pattern reference point    *** *** *** *** */
/* L300: */
/* set value for attribute */
#ifndef NO_PROTO
    ratr1 = .35f;
    ratr2 = .21f;
#else /* NO_PROTO */
    ratr1 = (float).35;
    ratr2 = (float).21;
#endif /* NO_PROTO */
    nsparf (&ratr1, &ratr2);
#ifndef NO_PROTO
    setmsg_("1 67", "<Inquire current element type and size> should return p"
	    "attern reference point as the type of the created element and th"
	    "e appropriate element size.", 4L, 146L);
#else /* NO_PROTO */
    setmsg_("1 67", "<Inquire current element type and size> should return p\
attern reference point as the type of the created element and the appropriat\
e element size.", 4L, 146L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 52 is the PHIGS enumeration type for peparf */
    L__1 = errind == 0 && eltype == 52 && intlen == 0 && rllen == 2 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 67", "<Inquire current element content> should return the sta"
	    "ndard representation for the pattern reference point values.", 4L,
	     115L);
#else /* NO_PROTO */
    setmsg_("2 67", "<Inquire current element content> should return the sta\
ndard representation for the pattern reference point values.", 4L, 115L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peprpv */
    L__1 = errind == 0 && rlar[0] == ratr1 && rlar[1] == ratr2 && intg == 0 &&
	     rl == 2 && str == 0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Edge flag   *** *** *** *** *** */
/* set value for attribute */
    nsedfg (&c__1);
#ifndef NO_PROTO
    setmsg_("1 32", "<Inquire current element type and size> should return e"
	    "dge flag as the type of the created element and the appropriate "
	    "element size.", 4L, 132L);
#else /* NO_PROTO */
    setmsg_("1 32", "<Inquire current element type and size> should return e\
dge flag as the type of the created element and the appropriate element size."
	    , 4L, 132L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 46 is the PHIGS enumeration type for peedfg */
    L__1 = errind == 0 && eltype == 46 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 32 33", "<Inquire current element content> should return the "
	    "standard representation for all valid edge flag values.", 7L, 
	    107L);
#else /* NO_PROTO */
    setmsg_("2 32 33", "<Inquire current element content> should return the \
standard representation for all valid edge flag values.", 7L, 107L);
#endif /* NO_PROTO */
    for (eflag = 0; eflag <= 1; ++eflag) {
	nsedfg (&eflag);
	nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &
		str, strarl, strar, 1L);
	if (errind == 0 && intar[0] == eflag && intg == 1 && rl == 0 && str ==
		 0) {
/*            OK so far */
	} else {
	    fail_();
	    s_wsfi(&io___23);
	    do_fio(&c__1, "Failure for edge flag = ", 24L);
	    do_fio(&c__1, (char *)&eflag, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ".", 1L);
	    e_wsfi();
	    inmsg_(msg, 200L);
	    goto L1110;
	}
/* L1100: */
    }
    pass_();
L1110:
/* *** *** *** *** ***   Edgetype   *** *** *** *** *** */
/* set value for attribute */
    nsedt (&c__6);
#ifndef NO_PROTO
    setmsg_("1 40", "<Inquire current element type and size> should return e"
	    "dgetype as the type of the created element and the appropriate e"
	    "lement size.", 4L, 131L);
#else /* NO_PROTO */
    setmsg_("1 40", "<Inquire current element type and size> should return e\
dgetype as the type of the created element and the appropriate element size.",
	     4L, 131L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 47 is the PHIGS enumeration type for peedt */
    L__1 = errind == 0 && eltype == 47 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 40", "<Inquire current element content> should return the sta"
	    "ndard representation for the edgetype value.", 4L, 99L);
#else /* NO_PROTO */
    setmsg_("2 40", "<Inquire current element content> should return the sta\
ndard representation for the edgetype value.", 4L, 99L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peedt */
    L__1 = errind == 0 && intar[0] == 6 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
/* *** *** *** ***    Edgewidth scale factor    *** *** *** *** */
/* set value for attribute */
#ifndef NO_PROTO
    ratr1 = .33f;
#else /* NO_PROTO */
    ratr1 = (float).33;
#endif /* NO_PROTO */
    nsewsc (&ratr1);
#ifndef NO_PROTO
    setmsg_("1 49", "<Inquire current element type and size> should return e"
	    "dgewidth scale factor as the type of the created element and the"
	    " appropriate element size.", 4L, 145L);
#else /* NO_PROTO */
    setmsg_("1 49", "<Inquire current element type and size> should return e\
dgewidth scale factor as the type of the created element and the appropriate\
 element size.", 4L, 145L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 48 is the PHIGS enumeration type for peewsc */
    L__1 = errind == 0 && eltype == 48 && intlen == 0 && rllen == 1 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 49", "<Inquire current element content> should return the sta"
	    "ndard representation for the edgewidth scale factor value.", 4L, 
	    113L);
#else /* NO_PROTO */
    setmsg_("2 49", "<Inquire current element content> should return the sta\
ndard representation for the edgewidth scale factor value.", 4L, 113L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type peewsc */
    L__1 = errind == 0 && rlar[0] == ratr1 && intg == 0 && rl == 1 && str == 
	    0;
    ifpf_(&L__1);
/* *** *** *** *** ***    Edge colour index   *** *** *** *** *** */
/* set value for attribute */
    nsedci (&c__3);
#ifndef NO_PROTO
    setmsg_("1 55", "<Inquire current element type and size> should return e"
	    "dge colour index as the type of the created element and the appr"
	    "opriate element size.", 4L, 140L);
#else /* NO_PROTO */
    setmsg_("1 55", "<Inquire current element type and size> should return e\
dge colour index as the type of the created element and the appropriate elem\
ent size.", 4L, 140L);
#endif /* NO_PROTO */
    nqcets (&errind, &eltype, &intlen, &rllen, &strlen);
/* checking correct element type */
/* 49 is the PHIGS enumeration type for peedci */
    L__1 = errind == 0 && eltype == 49 && intlen == 1 && rllen == 0 && strlen 
	    == 0;
    ifpf_(&L__1);
#ifndef NO_PROTO
    setmsg_("2 55", "<Inquire current element content> should return the sta"
	    "ndard representation for the edge colour index value.", 4L, 108L);

#else /* NO_PROTO */
    setmsg_("2 55", "<Inquire current element content> should return the sta\
ndard representation for the edge colour index value.", 4L, 108L);
#endif /* NO_PROTO */
    nqceco (&c__50, &c__50, &c__50, &errind, &intg, intar, &rl, rlar, &str, 
	    strarl, strar, 1L);
/* checking correct output parameters for data record type pepmi */
    L__1 = errind == 0 && intar[0] == 3 && intg == 1 && rl == 0 && str == 0;
    ifpf_(&L__1);
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

