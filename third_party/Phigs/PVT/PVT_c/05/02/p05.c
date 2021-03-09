/* fort/05/02/p05.f -- translated by f2c (version of 22 July 1992  22:54:52).
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

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__8 = 8;
static integer c__12 = 12;
static integer c__13 = 13;

/*  ********************************************************* */
/*  *                                                       * */
/*  *    TEST NUMBER: 05.02/05                              * */
/*  *    TEST TITLE : Deferral mode WAIT and ASTI           * */
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
    static char deftab[4*5] = "ASAP" "BNIG" "BNIL" "ASTI" "WAIT";
    static char modtab[4*3] = "NIVE" "UWOR" "UQUM";
    static char sevtab[3*3] = "IRG" "IMM" "CBS";
    static char oldtab[10*3] = "CORRECT   " "DEFERRED  " "SIMULATED ";
    static char svrcod[1*3] = "c" "d" "s";
#else /* NO_PROTO */
    static char deftab[4*5+1] = "ASAPBNIGBNILASTIWAIT";
    static char modtab[4*3+1] = "NIVEUWORUQUM";
    static char sevtab[3*3+1] = "IRGIMMCBS";
    static char oldtab[10*3+1] = "CORRECT   DEFERRED  SIMULATED ";
    static char svrcod[1*3+1] = "cds";
#endif /* NO_PROTO */

    /* System generated locals */
    address a__1[3], a__2[8], a__3[12], a__4[13];
    integer i__1[3], i__2[8], i__3[12], i__4[13];
    logical L__1;
    char ch__1[91], ch__2[170], ch__3[189], ch__4[171], ch__5[210];

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer s_wsfi(), do_fio(), e_wsfi();
    /* Subroutine */ int s_cat();
#endif /* NO_PROTO */

    /* Local variables */
    static integer pcc;
#ifndef NO_PROTO
    extern /* Subroutine */ int ifpf_(logical *), nrst (integer *, integer *);

#else /* NO_PROTO */
    extern /* Subroutine */ int ifpf_(), nrst ();
#endif /* NO_PROTO */
    static integer modmd;
#ifndef NO_PROTO
    extern /* Subroutine */ int endit_(void), inmsg_(char *, ftnlen);
    extern integer itrim_(char *, ftnlen);
    extern /* Subroutine */ int nsdus (integer *, integer *, integer *), 
	    nopwk (integer *, integer *, integer *);
    extern logical svrok_(integer *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int endit_(), inmsg_();
    extern integer itrim_();
    extern /* Subroutine */ int nsdus (), nopwk ();
    extern logical svrok_();
#endif /* NO_PROTO */
    static char deflbl[4], pcctab[34*17];
    static integer actpcc, defmod;
    static char pcclbl[34], pcchar[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int picchg_(integer *, char *, char *, integer *, 
	    integer *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int picchg_();
#endif /* NO_PROTO */
    static char modlbl[4], oldlbl[10];
    static integer actsev;
    static char sevlbl[3], sevchr[2], svrlbl[20], explbl[40];
#ifndef NO_PROTO
    extern /* Subroutine */ int initgl_(char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int initgl_();
#endif /* NO_PROTO */
    static integer oldsvr;
#ifndef NO_PROTO
    extern /* Subroutine */ int setpcl_(char *, ftnlen), picenv_(integer *), 
	    setmsg_(char *, char *, ftnlen, ftnlen), xpopph_(integer *, 
	    integer *), setsvr_(integer *, integer *), exsvrs_(integer *, 
	    integer *, integer *, integer *, char *, char *, ftnlen, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int setpcl_(), picenv_(), setmsg_(), xpopph_(), 
	    setsvr_(), exsvrs_();
#endif /* NO_PROTO */
    static integer sevrty;
    static char svrlst[3];

    /* Fortran I/O blocks */
    static icilist io___13 = { 0, pcchar, 0, "(I2)", 2, 1 };
    static icilist io___24 = { 0, sevchr, 0, "(I2)", 2, 1 };


/* deferral mode */
/* modification mode */
/* dynamic modification */
/* state of visual representation */
/*                correct    deferred    simulated */
/* clear control flag */
/*                conditionally  always */
/*  Declare program-specific variables */
    initgl_("05.02/05", 8L);
/* open PHIGS and workstation */
    xpopph_(&globnu_1.errfil, &globnu_1.memun);
    nopwk (&globnu_1.wkid, &globnu_1.conid, &globnu_1.wtype);
/*  picture change categories are numbered from 1 to 17: */
/*    workstation changes :  1 to 12 */
/*    structure changes   : 13 to 17 */
/*  set pcctab to names of picture change categories */
    setpcl_(pcctab, 34L);
/*  invoke PICENV to set up standard picture environment */
    picenv_(&globnu_1.wkid);
    for (defmod = 4; defmod >= 3; --defmod) {
/*        set deflbl = string for defmod */
	s_copy(deflbl, deftab + (defmod << 2), 4L, 4L);
	if (defmod == 3) {
	    s_copy(svrlbl, "DEFERRED or CORRECT", 20L, 19L);
	    s_copy(svrlst, "cd", 3L, 2L);
	} else {
	    s_copy(svrlbl, "DEFERRED", 20L, 8L);
	    s_copy(svrlst, "d", 3L, 1L);
	}
/*        <set display update state> defmod, NIVE */
	nsdus (&globnu_1.wkid, &defmod, &c__0);
/*        for pcc = 1 to 17 = picture change category */
	for (pcc = 1; pcc <= 17; ++pcc) {
/*           <redraw all structures>/COND to make state of visual 
*/
/*           representation = CORRECT */
	    nrst (&globnu_1.wkid, &c__0);
/*           attempt visual change of type pcc */
	    s_wsfi(&io___13);
	    do_fio(&c__1, (char *)&pcc, (ftnlen)sizeof(integer));
	    e_wsfi();
	    picchg_(&globnu_1.wkid, "0,1,2", pcchar, &actsev, &actpcc, 5L, 2L)
		    ;
	    s_copy(pcclbl, pcctab + (pcc - 1) * 34, 34L, 34L);
	    if (actpcc == 0) {
/* Writing concatenation */
#ifndef NO_PROTO
		i__1[0] = 56, a__1[0] = "Picture change failed, NIVE test sk"
			"ipped for category = ";
#else /* NO_PROTO */
		i__1[0] = 56, a__1[0] = "Picture change failed, NIVE test sk\
ipped for category = ";
#endif /* NO_PROTO */
		i__1[1] = itrim_(pcclbl, 34L), a__1[1] = pcclbl;
		i__1[2] = 1, a__1[2] = ".";
		s_cat(ch__1, a__1, i__1, &c__3, 91L);
		inmsg_(ch__1, itrim_(pcclbl, 34L) + 57);
		goto L110;
	    }
/* Writing concatenation */
	    i__2[0] = 29, a__2[0] = "A picture change of category ";
	    i__2[1] = itrim_(pcclbl, 34L), a__2[1] = pcclbl;
	    i__2[2] = 23, a__2[2] = " performed under mode [";
	    i__2[3] = 4, a__2[3] = deflbl;
#ifndef NO_PROTO
	    i__2[4] = 41, a__2[4] = ", NIVE] should leave the state of visua"
		    "l ";
#else /* NO_PROTO */
	    i__2[4] = 41, a__2[4] = ", NIVE] should leave the state of visua\
l ";
#endif /* NO_PROTO */
	    i__2[5] = 18, a__2[5] = "representation as ";
	    i__2[6] = itrim_(svrlbl, 20L), a__2[6] = svrlbl;
	    i__2[7] = 1, a__2[7] = ".";
	    s_cat(ch__2, a__2, i__2, &c__8, 170L);
	    setmsg_("3 4 13 14 15 23 29", ch__2, 18L, itrim_(pcclbl, 34L) + 
		    115 + itrim_(svrlbl, 20L) + 1);
/*           pass/fail depending on ( svr = DEFERRED or */
/*                                   (svr = CORRECT  and defmod = 
ASTI) ) */
	    L__1 = svrok_(&globnu_1.wkid, svrlst, 3L);
	    ifpf_(&L__1);
/*        next pcc */
L110:
	    ;
	}
	for (modmd = 1; modmd <= 2; ++modmd) {
	    s_copy(modlbl, modtab + (modmd << 2), 4L, 4L);
	    for (sevrty = 0; sevrty <= 2; ++sevrty) {
		s_copy(sevlbl, sevtab + sevrty * 3, 3L, 3L);
		for (oldsvr = 0; oldsvr <= 2; ++oldsvr) {
		    s_copy(oldlbl, oldtab + oldsvr * 10, 10L, 10L);
/*           attempt to set SVR to oldsvr */
		    setsvr_(&globnu_1.wkid, &oldsvr);
/*           <set display update state> defmod, modmd */
		    nsdus (&globnu_1.wkid, &defmod, &modmd);
/*           if (current_SVR not= oldsvr) goto skip_svr */

		    if (! svrok_(&globnu_1.wkid, svrcod + oldsvr, 1L)) {
/* Writing concatenation */
#ifndef NO_PROTO
			i__3[0] = 48, a__3[0] = "Cannot set old state of vis"
				"ual representation = ";
#else /* NO_PROTO */
			i__3[0] = 48, a__3[0] = "Cannot set old state of vis\
ual representation = ";
#endif /* NO_PROTO */
			i__3[1] = itrim_(oldlbl, 10L), a__3[1] = oldlbl;
#ifndef NO_PROTO
			i__3[2] = 34, a__3[2] = "; skipping test for update "
				"mode = ";
#else /* NO_PROTO */
			i__3[2] = 34, a__3[2] = "; skipping test for update \
mode = ";
#endif /* NO_PROTO */
			i__3[3] = 1, a__3[3] = "[";
			i__3[4] = 4, a__3[4] = deflbl;
			i__3[5] = 2, a__3[5] = ", ";
			i__3[6] = 4, a__3[6] = modlbl;
#ifndef NO_PROTO
			i__3[7] = 29, a__3[7] = "], picture change severity "
				"= ";
#else /* NO_PROTO */
			i__3[7] = 29, a__3[7] = "], picture change severity \
= ";
#endif /* NO_PROTO */
			i__3[8] = 3, a__3[8] = sevlbl;
#ifndef NO_PROTO
			i__3[9] = 43, a__3[9] = ", and old state of visual r"
				"epresentation = ";
#else /* NO_PROTO */
			i__3[9] = 43, a__3[9] = ", and old state of visual r\
epresentation = ";
#endif /* NO_PROTO */
			i__3[10] = itrim_(oldlbl, 10L), a__3[10] = oldlbl;
			i__3[11] = 1, a__3[11] = ".";
			s_cat(ch__3, a__3, i__3, &c__12, 189L);
			inmsg_(ch__3, itrim_(oldlbl, 10L) + 168 + itrim_(
				oldlbl, 10L) + 1);
			goto L150;
		    }
/*           attempt to perform sevrty-type operation: */
		    s_wsfi(&io___24);
		    do_fio(&c__1, (char *)&sevrty, (ftnlen)sizeof(integer));
		    e_wsfi();
#ifndef NO_PROTO
		    picchg_(&globnu_1.wkid, sevchr, "1,2,3,4,5,6,7,8,9,10,11"
			    ",12,13,14,15,16,17", &actsev, &actpcc, 2L, 41L);
#else /* NO_PROTO */
		    picchg_(&globnu_1.wkid, sevchr, "1,2,3,4,5,6,7,8,9,10,11\
,12,13,14,15,16,17", &actsev, &actpcc, 2L, 41L);
#endif /* NO_PROTO */
		    if (actsev != sevrty) {
/* Writing concatenation */
#ifndef NO_PROTO
			i__3[0] = 37, a__3[0] = "Picture change failed for s"
				"everity = ";
#else /* NO_PROTO */
			i__3[0] = 37, a__3[0] = "Picture change failed for s\
everity = ";
#endif /* NO_PROTO */
			i__3[1] = 3, a__3[1] = sevlbl;
#ifndef NO_PROTO
			i__3[2] = 34, a__3[2] = "; skipping test for update "
				"mode = ";
#else /* NO_PROTO */
			i__3[2] = 34, a__3[2] = "; skipping test for update \
mode = ";
#endif /* NO_PROTO */
			i__3[3] = 1, a__3[3] = "[";
			i__3[4] = 4, a__3[4] = deflbl;
			i__3[5] = 2, a__3[5] = ", ";
			i__3[6] = 4, a__3[6] = modlbl;
#ifndef NO_PROTO
			i__3[7] = 29, a__3[7] = "], picture change severity "
				"= ";
#else /* NO_PROTO */
			i__3[7] = 29, a__3[7] = "], picture change severity \
= ";
#endif /* NO_PROTO */
			i__3[8] = 3, a__3[8] = sevlbl;
#ifndef NO_PROTO
			i__3[9] = 43, a__3[9] = ", and old state of visual r"
				"epresentation = ";
#else /* NO_PROTO */
			i__3[9] = 43, a__3[9] = ", and old state of visual r\
epresentation = ";
#endif /* NO_PROTO */
			i__3[10] = itrim_(oldlbl, 10L), a__3[10] = oldlbl;
			i__3[11] = 1, a__3[11] = ".";
			s_cat(ch__4, a__3, i__3, &c__12, 171L);
			inmsg_(ch__4, itrim_(oldlbl, 10L) + 161);
			goto L150;
		    }
/*           calculate expected SVRs and label, */
/*              based on sevrty, defmod, modmd, and oldsvr
 */
		    exsvrs_(&sevrty, &defmod, &modmd, &oldsvr, svrlst, explbl,
			     3L, 40L);
/*           set up label for expected value(s) */
/* Writing concatenation */
		    i__4[0] = 18, a__4[0] = "If update mode = [";
		    i__4[1] = 4, a__4[1] = deflbl;
		    i__4[2] = 2, a__4[2] = ", ";
		    i__4[3] = 4, a__4[3] = modlbl;
		    i__4[4] = 29, a__4[4] = "], picture change severity = ";
		    i__4[5] = 3, a__4[5] = sevlbl;
		    i__4[6] = 26, a__4[6] = ", and old state of visual ";
		    i__4[7] = 17, a__4[7] = "representation = ";
		    i__4[8] = itrim_(oldlbl, 10L), a__4[8] = oldlbl;
		    i__4[9] = 15, a__4[9] = ", then current ";
#ifndef NO_PROTO
		    i__4[10] = 41, a__4[10] = "state of visual representatio"
			    "n should be ";
#else /* NO_PROTO */
		    i__4[10] = 41, a__4[10] = "state of visual representatio\
n should be ";
#endif /* NO_PROTO */
		    i__4[11] = itrim_(explbl, 40L), a__4[11] = explbl;
		    i__4[12] = 1, a__4[12] = ".";
		    s_cat(ch__5, a__4, i__4, &c__13, 210L);
		    setmsg_("3 4 13 14 15 19 20 21 24 25 26 27 28 29", ch__5, 
			    39L, itrim_(oldlbl, 10L) + 159 + itrim_(explbl, 
			    40L) + 1);
		    L__1 = svrok_(&globnu_1.wkid, svrlst, 3L);
		    ifpf_(&L__1);
/*  skip_svr: */
/*     next oldsvr */
L150:
		    ;
		}
/*     next sevrty */
/* L140: */
	    }
/*     next modmd */
/* L130: */
	}
/*  next defmod */
/* L100: */
    }
/* L666: */
    endit_();
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* MAIN__ */

